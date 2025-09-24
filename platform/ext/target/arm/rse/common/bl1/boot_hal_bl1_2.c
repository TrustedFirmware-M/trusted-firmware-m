/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <string.h>
#include "boot_hal.h"
#include "region.h"
#include "device_definition.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "host_base_address.h"
#include "region_defs.h"
#include "platform_base_address.h"
#include "uart_stdout.h"
#include "tfm_plat_otp.h"
#include "kmu_drv.h"
#include "platform_regs.h"
#include "tfm_log.h"
#ifdef CRYPTO_HW_ACCELERATOR
#include "fih.h"
#include "cc3xx_drv.h"
#endif /* CRYPTO_HW_ACCELERATOR */
#include "cmsis_compiler.h"
#ifdef RSE_USE_HOST_FLASH
#include "fip_parser.h"
#include "host_flash_atu.h"
#include "plat_def_fip_uuid.h"
#endif
#include "tfm_plat_nv_counters.h"
#include "tfm_plat_provisioning.h"
#include "rse_kmu_keys.h"
#include "mpu_armv8m_drv.h"
#include "tfm_hal_device_header.h"
#include "dpa_hardened_word_copy.h"
#include "rse_clocks.h"
#include "rse_sam_config.h"
#if RSE_AMOUNT > 1
#include "rse_handshake.h"
#include "rse_otp_dev.h"
#include "rse_otp_layout.h"
#endif
#include "bl1_2_debug.h"

/* FixMe: Move CASSERT() into a generic support header */
/* Two-level macro so __LINE__ expands before token-pasting */
#define __CONCAT_(a, b) a##b
#define _CONCAT(a, b)  __CONCAT(a, b)

/* Fails to compile when (expr) is false (i.e., "assert") */
#define CASSERT(expr) \
    typedef char _CONCAT(static_assertion_, __LINE__)[(expr) ? 1 : -1]

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
#define LOGGING_ENABLED
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

#if !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART))
#include "atu_config.h"
#endif

/* Needed to store the offset of primary and secondary slot of the BL2 firmware */
static uint32_t image_offsets[2];

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

/* List the MPU regions to be configured */
enum {
#if !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART))
    ATU_WINDOW_REGION_CFG_NR = 0, /*!< Required for ATU config, not always present */
#endif
    ROM_REGION_CFG_NR             /*!< Always configured last as it's required to disable ROM exec */
};

#ifdef RSE_USE_ROM_LIB_FROM_SRAM
/* Instruction Patch Table */
static const struct {
    uint32_t addr;
    uint16_t instruction;
} instr_patches[] = {
    /* Add patches to a specific instruction in the ROM
     * here in the form:
     * { addr (in ROM) of instruction, replacement instruction code}
     */
};

/* GOT Patch Table */
static const struct {
    uint32_t got_addr;
    uint32_t replacement;
} got_patches[] = {
    /* Add patches to the GOT here in the form:
     * {Address of GOT (must be within GOT),
     *        replacement address (points to code in BL1_2)}
     */
};

extern uint32_t __got_start__;
extern uint32_t __got_end__;
extern uint32_t __bl1_1_text_size;
#endif /* RSE_USE_ROM_LIB_FROM_SRAM */

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base);

#ifdef RSE_USE_HOST_FLASH
uint32_t bl1_image_get_flash_offset(uint32_t image_id)
{
    switch (image_id) {
    case 0:
        return HOST_FLASH0_IMAGE0_BASE_S - FLASH_BASE_ADDRESS + image_offsets[0];
    case 1:
        return HOST_FLASH0_IMAGE1_BASE_S - FLASH_BASE_ADDRESS + image_offsets[1];
    default:
        FIH_PANIC;
    }
}
#endif

#if !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART))
static int32_t init_mpu_region_for_atu(void)
{
    static struct mpu_armv8m_dev_t dev_mpu_s = { MPU_BASE };
    int32_t rc;

    /* Set entire RSE ATU window to device memory to prevent caching */
    const struct mpu_armv8m_region_cfg_t atu_window_region_config = {
        .region_nr = ATU_WINDOW_REGION_CFG_NR,
        .region_base = HOST_ACCESS_BASE_NS,
        .region_limit = HOST_ACCESS_LIMIT_S,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DEVICE_IDX,
        .attr_exec = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh = MPU_ARMV8M_SH_NONE,
#ifdef TFM_PXN_ENABLE
        .attr_pxn = MPU_ARMV8M_PRIV_EXEC_NEVER,
#endif
    };

    rc = mpu_armv8m_region_enable(&dev_mpu_s, &atu_window_region_config);
    if (rc != 0) {
        return rc;
    }

    return mpu_armv8m_enable(&dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE, HARDFAULT_NMI_ENABLE);
}

#endif /* !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART)) */

#ifdef RSE_SUPPORT_ROM_LIB_RELOCATION
static void setup_got_register(void)
{
    __asm volatile(
        "mov r9, %0 \n"
        "mov r2, %1 \n"
        "lsl r9, #16 \n"
        "orr r9, r9, r2 \n"
        : : "I" (BL1_1_DATA_START >> 16), "I" (BL1_1_DATA_START & 0xFFFF) : "r2"
    );
}
#endif /* RSE_SUPPORT_ROM_LIB_RELOCATION */

#ifdef RSE_USE_ROM_LIB_FROM_SRAM
static void copy_rom_library_into_sram(void)
{
    uint32_t got_entry;
    const size_t code_size = (size_t)&__bl1_1_text_size;

    if (code_size > (VM0_SIZE)) {
        FIH_PANIC;
    }

    /* Copy the ROM into VM0 */
    memcpy((uint8_t *)VM0_BASE_S, (uint8_t *)ROM_BASE_S, code_size);

    /* Patch the GOT so that any address which pointed into ROM
     * now points into VM0.
     */
    for (uint32_t *addr = &__got_start__; addr < &__got_end__; addr++) {
        got_entry = *addr;

        if (got_entry >= ROM_BASE_S && got_entry < ROM_BASE_S + ROM_SIZE) {
            got_entry -= ROM_BASE_S;
            got_entry += VM0_BASE_S;
        }

        *addr = got_entry;
    }
}

static void do_rom_patching(void)
{
    int idx;

    /* Patch addresses in GOT with the address of the patched functions */
    for (idx = 0; idx < ARRAY_SIZE(got_patches); idx++) {
        *(volatile uint32_t *)(got_patches[idx].got_addr) = got_patches[idx].replacement;
    }

    /* Instruction based patching --> patch faulty instructions directly instead
     * of replacing whole function with a patched function
     */
    for (idx = 0; idx < ARRAY_SIZE(instr_patches); idx++) {
        /* The addr in the instr patch table will contain the ROM address
         * of the faulty patch. Convert that address to the SRAM version as
         * bl1_1_shared_lib is now shifted to SRAM where it will be patched
         */
        *(volatile uint16_t *)(instr_patches[idx].addr - ROM_BASE_S + VM0_BASE_S) =
            instr_patches[idx].instruction;
    }
}
#endif /* RSE_USE_ROM_LIB_FROM_SRAM */

/* bootloader platform-specific hw initialization */
int32_t boot_platform_init(void)
{
    int32_t result;
    enum tfm_plat_err_t plat_err;

#ifdef RSE_SUPPORT_ROM_LIB_RELOCATION
    setup_got_register();
#endif /* RSE_SUPPORT_ROM_LIB_RELOCATION */
#ifdef RSE_USE_ROM_LIB_FROM_SRAM
    copy_rom_library_into_sram();
    /* Patch faulty instruction and functions */
    do_rom_patching();
#endif /* RSE_USE_ROM_LIB_FROM_SRAM */

    /* Initialize stack limit register */
    uint32_t msp_stack_bottom =
            (uint32_t)&REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base);

    __set_MSPLIM(msp_stack_bottom);

    /* Early clock config to speed up boot */
    result = rse_clock_config();
    if (result != 0) {
        return result;
    }
    SystemCoreClockUpdate();

    plat_err = tfm_plat_init_nv_counter();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

#if !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART))
    /**
     * If logging is disabled, or the RSE is not using a UART
     * from the system memory map, then BL1_1 will not have initialised
     * the MPU for the ATU window. We therefore need to initialise the
     * MPU here and configure the whole ATU window to be device
     * memory to avoid CPU caching
     */
    result = init_mpu_region_for_atu();
    if (result != 0) {
        return result;
    }

    /* Initialize ATU driver */
    plat_err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static, atu_stat_count);
    if (plat_err != ATU_ERR_NONE) {
        return plat_err;
    }

#endif /* !(defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART)) */

#ifdef LOGGING_ENABLED
    stdio_init();
#endif /* LOGGING_ENABLED */

    result = FLASH_DEV_NAME.Initialize(NULL);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

#ifdef RSE_USE_HOST_FLASH
    result = host_flash_atu_setup_image_input_slots(UUID_RSE_FIRMWARE_BL2, image_offsets);
    if (result != 0) {
        int32_t recovery_result = boot_initiate_recovery_mode(0);
        if (recovery_result != TFM_PLAT_ERR_BL1_2_PROVISIONING_NOT_REQUIRED) {
            return recovery_result;
        }
        return result;
    }
#endif

    return 0;
}

int32_t boot_platform_post_init(void)
{
    int32_t rc;
    enum tfm_plat_err_t plat_err;

    uint32_t vhuk_seed[8 * RSE_AMOUNT];
    size_t vhuk_seed_len;
    bool provisioning_required;

    /* Perform provisioning if necessary, this function only returns true if we want to perform provisioning
     * irrespective of whether the flash is attached or not */
    plat_err = tfm_plat_provisioning_is_required(&provisioning_required);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (provisioning_required) {
        plat_err = tfm_plat_provisioning_perform();
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    rc = b1_2_platform_debug_init();
    if (rc != 0) {
        return rc;
    }

    plat_err = rse_derive_vhuk_seed(vhuk_seed, sizeof(vhuk_seed), &vhuk_seed_len);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

#if RSE_AMOUNT > 1
    /* Check the RSE config virtual key agreement policy */
    if (rse_otp_policy_check(P_RSE_OTP_CM->config_flags, CM_POLICIES_VHUK_AGREEMENT_REQUIRED)) {
        rc = rse_handshake(vhuk_seed);
        if (rc != 0) {
            return rc;
        }
    }
#endif /* RSE_AMOUNT > 1 */

    plat_err = rse_setup_vhuk((uint8_t *)vhuk_seed, vhuk_seed_len);
    if (plat_err) {
        return plat_err;
    }

    plat_err = rse_setup_iak_seed();
    if (plat_err) {
        return plat_err;
    }

#ifdef RSE_BOOT_KEYS_CCA
    plat_err = rse_setup_dak_seed();
    if (plat_err) {
        return plat_err;
    }
#endif
#ifdef RSE_BOOT_KEYS_DPE
    plat_err = rse_setup_rot_cdi();
    if (plat_err) {
        return plat_err;
    }
#endif

    plat_err = rse_setup_runtime_secure_image_encryption_key();
    if (plat_err) {
        return plat_err;
    }

#ifdef TFM_LOAD_NS_IMAGE
    plat_err = rse_setup_runtime_non_secure_image_encryption_key();
    if (plat_err) {
        return plat_err;
    }
#endif /* TFM_LOAD_NS_IMAGE */

    return 0;
}

/* Directly program the MPU registers without calling the driver
 * as that won't be runnable from ROM once we disable the ROM
 * execution
 */
static void disable_rom_execution(void)
{
    const struct mpu_armv8m_region_cfg_t rom_region_cfg = {
        .region_nr = ROM_REGION_CFG_NR,
        .region_base = ROM_BASE_S,
        .region_limit = ROM_BASE_S + ROM_SIZE - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_CODE_IDX,
        .attr_exec = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access = MPU_ARMV8M_AP_RO_PRIV_ONLY,
        .attr_sh = MPU_ARMV8M_SH_NONE,
#ifdef TFM_PXN_ENABLE
        .attr_pxn = MPU_ARMV8M_PRIV_EXEC_NEVER,
#endif
    };

    /* Validate both base and limit are aligned to 32-byte boundaries,
     * i.e. base[4:0] = 0b00000 and limit[4:1] = 0b11111
     */
    CASSERT((rom_region_cfg.region_base  & ~MPU_RBAR_BASE_Msk)  == 0);
    CASSERT((rom_region_cfg.region_limit & ~MPU_RLAR_LIMIT_Msk) == 0x1F);

    /* Region enable */
    MPU->CTRL = 0x0UL;

    MPU->RNR = rom_region_cfg.region_nr & MPU_RNR_REGION_Msk;
    MPU->RBAR = (rom_region_cfg.region_base & MPU_RBAR_BASE_Msk) |
        ((rom_region_cfg.attr_sh << MPU_RBAR_SH_Pos) & MPU_RBAR_SH_Msk) |
        ((rom_region_cfg.attr_access << MPU_RBAR_AP_Pos) & MPU_RBAR_AP_Msk) |
        ((rom_region_cfg.attr_exec << MPU_RBAR_XN_Pos) & MPU_RBAR_XN_Msk);
    MPU->RLAR = (rom_region_cfg.region_limit & MPU_RLAR_LIMIT_Msk) |
        ((rom_region_cfg.region_attridx << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) |
#ifdef TFM_PXN_ENABLE
        ((rom_region_cfg.attr_pxn << MPU_RLAR_PXN_Pos) & MPU_RLAR_PXN_Msk) |
#endif
        MPU_RLAR_EN_Msk;

    /* Enable with PRIVILEGED_DEFAULT_ENABLE, HARDFAULT_NMI_ENABLE*/

    MPU->MAIR0 = (MPU_ARMV8M_MAIR_ATTR_DEVICE_VAL << MPU_MAIR0_Attr0_Pos) |
                 (MPU_ARMV8M_MAIR_ATTR_CODE_VAL << MPU_MAIR0_Attr1_Pos) |
                 (MPU_ARMV8M_MAIR_ATTR_DATA_VAL << MPU_MAIR0_Attr2_Pos);
    MPU->MAIR1 = 0x0;
    MPU->CTRL = MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_ENABLE_Msk;

    __DSB();
    __ISB();
}

void boot_platform_start_next_image(struct boot_arm_vector_table *vt)
{
    /* Clang at O0, stores variables on the stack with SP relative addressing.
     * When manually set the SP then the place of reset vector is lost.
     * Static variables are stored in 'data' or 'bss' section, change of SP has
     * no effect on them.
     */
    static struct boot_arm_vector_table *vt_cpy;
    int32_t result;

#ifdef CRYPTO_HW_ACCELERATOR
    result = cc3xx_lowlevel_uninit();
    if (result) {
        while (1);
    }
#endif /* CRYPTO_HW_ACCELERATOR */

    rse_sam_finish();

    result = FLASH_DEV_NAME.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while (1){}
    }

#ifdef LOGGING_ENABLED
    stdio_uninit();
#endif /* LOGGING_ENABLED */

    fih_delay();

    disable_rom_execution();

    vt_cpy = vt;
#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
 || defined(__ARM_ARCH_8_1M_MAIN__)
    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSPLIM(0);
#endif /* defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
       || defined(__ARM_ARCH_8_1M_MAIN__) */

    __set_MSP(vt_cpy->msp);
    __DSB();
    __ISB();

    boot_jump_to_next_image(vt_cpy->reset);
}

int boot_platform_pre_load(uint32_t image_id)
{
    fih_delay();

    return 0;
}

int boot_platform_post_load(uint32_t image_id)
{
    int rc;

    rc = kmu_invalidate_hardware_keys(&KMU_DEV_S);
    if (rc != 0) {
        return rc;
    }

    return 0;
}

int boot_initiate_recovery_mode(uint32_t image_id)
{
    /* Unconditionally perform provisioning. This function
     * will check if provisioning is actually allowed/required */
    return tfm_plat_provisioning_perform();
}

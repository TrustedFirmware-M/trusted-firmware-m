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

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
#define LOGGING_ENABLED
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

static struct mpu_armv8m_dev_t dev_mpu_s = { MPU_BASE };

/* Needed to store the offset of primary and secondary slot of the BL2 firmware */
static uint32_t image_offsets[2];

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

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
    int32_t rc;

    /* Set entire RSE ATU window to device memory to prevent caching */
    struct mpu_armv8m_region_cfg_t atu_window_region_config = {
        0,
        HOST_ACCESS_BASE_NS,
        HOST_ACCESS_LIMIT_S,
        MPU_ARMV8M_MAIR_ATTR_DEVICE_IDX,
        MPU_ARMV8M_XN_EXEC_NEVER,
        MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        MPU_ARMV8M_SH_NONE,
#ifdef TFM_PXN_ENABLE
        MPU_ARMV8M_PRIV_EXEC_NEVER,
#endif
    };

    rc = mpu_armv8m_region_enable(&dev_mpu_s, &atu_window_region_config);
    if (rc != 0) {
        return rc;
    }

    return mpu_armv8m_enable(&dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE, HARDFAULT_NMI_ENABLE);
}

#if defined(RSE_USE_HOST_UART)
static enum tfm_plat_err_t init_atu_region_for_uart(void)
{
    enum atu_error_t atu_err;

    /* Initialize UART region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    get_supported_region_count(&ATU_DEV_S) - 1,
                                    HOST_UART0_BASE_NS, HOST_UART_BASE,
                                    HOST_UART_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return (enum tfm_plat_err_t)atu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* defined(RSE_USE_HOST_UART) */
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

    if (code_size > VM1_SIZE) {
        FIH_PANIC;
    }

    /* Copy the ROM into VM1 */
    memcpy((uint8_t *)VM1_BASE_S, (uint8_t *)ROM_BASE_S, code_size);

    /* Patch the GOT so that any address which pointed into ROM
     * now points into VM1.
     */
    for (uint32_t *addr = &__got_start__; addr < &__got_end__; addr++) {
        got_entry = *addr;

        if (got_entry >= ROM_BASE_S && got_entry < ROM_BASE_S + ROM_SIZE) {
            got_entry -= ROM_BASE_S;
            got_entry += VM1_BASE_S;
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
        *(volatile uint16_t *)(instr_patches[idx].addr - ROM_BASE_S + VM1_BASE_S) =
            instr_patches[idx].instruction;
    }
}
#endif /* RSE_USE_ROM_LIB_FROM_SRAM */

static enum tfm_plat_err_t image_load_validate_failure(void)
{
    enum tfm_plat_err_t err;
    bool provisioning_required;

    err = tfm_plat_provisioning_is_required(&provisioning_required);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (!provisioning_required) {
        return TFM_PLAT_ERR_BL1_2_PROVISIONING_NOT_REQUIRED;
    }

    return tfm_plat_provisioning_perform();
}

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

#if defined(RSE_USE_HOST_UART)
    /**
     * Add the ATU region for the UART even though logging is disabled
     * in BL1_2 as later components might enable logging and try and use
     * it
     */
    plat_err = init_atu_region_for_uart();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#endif /* defined(RSE_USE_HOST_UART) */
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


static int invalidate_hardware_keys(void)
{
    enum kmu_error_t kmu_err;
    uint32_t slot;

    for (slot = 0; slot < KMU_USER_SLOT_MIN; slot++) {
        kmu_err = kmu_set_slot_invalid(&KMU_DEV_S, slot);
        if (kmu_err != KMU_ERROR_NONE) {
            return kmu_err;
        }
    }

    return 0;
}

static int disable_rom_execution(void)
{
    struct mpu_armv8m_region_cfg_t rom_region_config = {
        1,
        ROM_BASE_S,
        ROM_BASE_S + ROM_SIZE - 1,
        MPU_ARMV8M_MAIR_ATTR_CODE_IDX,
        MPU_ARMV8M_XN_EXEC_NEVER,
        MPU_ARMV8M_AP_RO_PRIV_ONLY,
        MPU_ARMV8M_SH_NONE,
#ifdef TFM_PXN_ENABLE
        MPU_ARMV8M_PRIV_EXEC_NEVER,
#endif
    };

    return mpu_armv8m_region_enable(&dev_mpu_s, &rom_region_config);
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

#ifdef RSE_USE_HOST_FLASH
    result = host_flash_atu_uninit_regions();
    if (result) {
        while(1){}
    }
#endif

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

    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);

    result = disable_rom_execution();
    if (result != 0) {
        while (1);
    }

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
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);

    return 0;
}

int boot_platform_post_load(uint32_t image_id)
{
    int rc;

    rc = invalidate_hardware_keys();
    if (rc != 0) {
        return rc;
    }

    return 0;
}

int boot_initiate_recovery_mode(uint32_t image_id)
{
    return image_load_validate_failure();
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "bl1_random.h"
#include "boot_hal.h"
#include "region.h"
#include "device_definition.h"
#include "tfm_plat_shared_measurement_data.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "host_base_address.h"
#include "region_defs.h"
#include "platform_base_address.h"
#include "uart_stdout.h"
#include "tfm_plat_otp.h"
#include "kmu_drv.h"
#include "rse_kmu_keys.h"
#include "device_definition.h"
#include "platform_regs.h"
#ifdef CRYPTO_HW_ACCELERATOR
#include "fih.h"
#include "cc3xx_drv.h"
#endif /* CRYPTO_HW_ACCELERATOR */
#include "cmsis_compiler.h"
#include "rse_boot_self_tests.h"
#ifdef RSE_ENABLE_BRINGUP_HELPERS
#include "rse_bringup_helpers.h"
#endif /* RSE_ENABLE_BRINGUP_HELPERS */
#include "rse_sam_config.h"
#include "tfm_log.h"
#include "bl1_1_debug.h"
#include "mpu_armv8m_drv.h"
#include "rse_persistent_data.h"

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
#define LOGGING_ENABLED
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

#if defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART)
#include "atu_config.h"
#endif

#define CMSDK_SECRESPCFG_BUS_ERR_MASK   (1UL)

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base);

#if defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART)
static struct mpu_armv8m_dev_t dev_mpu_s = { MPU_BASE };

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

    FIH_CALL(mpu_armv8m_region_enable, rc, &dev_mpu_s, &atu_window_region_config);
    if (rc != 0) {
        return rc;
    }

    FIH_CALL(mpu_armv8m_enable, rc, &dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE, HARDFAULT_NMI_ENABLE);
    return rc;
}
#endif /* defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART) */

static void wait_for_vm_erase_to_finish_and_enable_cache(void)
{
    /* Wait for the DMA to finish erasing VM0 and VM1 */
    uint32_t dma_channel_amount = (*((volatile uint32_t *)(DMA_350_BASE_S + 0xfb0)) >> 4 & 0xF) + 1;

    /* FIXME remove once the FVP is fixed */
    dma_channel_amount = 1;

    /* Wait for each channel to finish */
    for (int idx = 0; idx < dma_channel_amount; idx++) {
        while ((*((volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000)) & 0x1) != 0) {}
    }

    /* Now enable caching */
    SCB_EnableICache();
    SCB_EnableDCache();
}

/* bootloader platform-specific hw initialization */
int32_t boot_platform_init(void)
{
    int32_t err;
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    cc3xx_err_t cc_err;
    uint8_t prbg_seed[KMU_PRBG_SEED_LEN];
#ifdef RSE_ENABLE_BRINGUP_HELPERS
    enum lcm_error_t lcm_err;
    enum lcm_tp_mode_t tp_mode;
#endif /* RSE_ENABLE_BRINGUP_HELPERS */

    /* Initialize stack limit register */
    uint32_t msp_stack_bottom =
            (uint32_t)&REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base);

    __set_MSPLIM(msp_stack_bottom);

    /* Enable system reset for the RSE */
    struct rse_sysctrl_t *rse_sysctrl = (void *)RSE_SYSCTRL_BASE_S;
    rse_sysctrl->reset_mask |= (1U << 8U);

    /**
     * @brief: Configure the response to a security violation as a
     *         bus error instead of RAZ/WI
     *
     */
    struct rse_sacfg_t *sacfg = (struct rse_sacfg_t *)RSE_SACFG_BASE_S;
    sacfg->secrespcfg |= CMSDK_SECRESPCFG_BUS_ERR_MASK;

    plat_err = tfm_plat_otp_init();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

#ifdef RSE_ENABLE_BRINGUP_HELPERS
    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return lcm_err;
    }

    if (tp_mode == LCM_TP_MODE_VIRGIN || tp_mode == LCM_TP_MODE_TCI) {
        rse_run_bringup_helpers_if_requested();
    }
#endif /* RSE_ENABLE_BRINGUP_HELPERS */

    err = rse_sam_init(RSE_SAM_INIT_SETUP_HANDLERS_ONLY);
    if (err != 0) {
        return err;
    }

#if defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART)
    /**
     * If we are using the ATU to map the host UART into the RSE memory
     * map then we also need to configure the MPU to ensure that the
     * address space we access from the RSE is marked as device memory
     * to avoid CPU caching. In this case, we also configure the entire
     * window to be device memory so that it does not need to be reconfigured
     * by later components
     */
    err = init_mpu_region_for_atu();
    if (err != 0) {
        return err;
    }

    /* Initialize ATU driver */
    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static, atu_stat_count);
    if (err != ATU_ERR_NONE) {
            return err;
    }
#endif /* defined(LOGGING_ENABLED) && defined(RSE_USE_HOST_UART) */

#ifdef LOGGING_ENABLED
    stdio_init();
#endif /* LOGGING_ENABLED */

#ifdef CRYPTO_HW_ACCELERATOR
    cc_err = cc3xx_lowlevel_init();
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */

#ifdef RSE_ENABLE_ROM_SELF_TESTS
    const rse_boot_self_test_ret_t self_tests = rse_boot_do_boot_self_tests();
    if (!RSE_BOOT_SELF_TESTS_CHECK_OK(self_tests)) {
        return (int32_t)self_tests;
    }
#endif /* RSE_ENABLE_ROM_SELF_TESTS */

    /* Init KMU */
    err = bl1_random_generate_secure(prbg_seed, sizeof(prbg_seed));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    kmu_err = kmu_init(&KMU_DEV_S, prbg_seed);
    if (kmu_err != KMU_ERROR_NONE) {
        return kmu_err;
    }

#ifdef CRYPTO_HW_ACCELERATOR
    plat_err = rse_setup_cc3xx_pka_sram_encryption_key();
    if (plat_err) {
        return plat_err;
    }
#endif /* CRYPTO_HW_ACCELERATOR */

    err = b1_1_platform_debug_init();
    if (err != 0) {
        return err;
    }

    /* Clear boot data area */
    memset((void *)tfm_plat_get_shared_measurement_data_base(), 0,
           tfm_plat_get_shared_measurement_data_size());

    wait_for_vm_erase_to_finish_and_enable_cache();

    rse_setup_persistent_data();

    return 0;
}

int32_t boot_platform_post_init(void)
{
    return 0;
}


int boot_platform_pre_load(uint32_t image_id)
{
    fih_delay();

    (void)image_id;

    return 0;
}

void boot_platform_start_next_image(struct boot_arm_vector_table *vt)
{
    /* Clang at O0, stores variables on the stack with SP relative addressing.
     * When manually set the SP then the place of reset vector is lost.
     * Static variables are stored in 'data' or 'bss' section, change of SP has
     * no effect on them.
     */
    static struct boot_arm_vector_table *vt_cpy;

#ifdef LOGGING_ENABLED
    stdio_uninit();
#endif /* LOGGING_ENABLED */

    fih_delay();

    vt_cpy = vt;

    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSPLIM(0);

    __set_MSP(vt_cpy->msp);
    __DSB();
    __ISB();

    boot_jump_to_next_image(vt_cpy->reset);
}

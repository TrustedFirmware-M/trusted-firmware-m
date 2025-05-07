/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

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
#include <string.h>
#include "cmsis_compiler.h"
#ifdef RSE_ENABLE_BRINGUP_HELPERS
#include "rse_bringup_helpers.h"
#endif /* RSE_ENABLE_BRINGUP_HELPERS */
#include "trng.h"
#include "rse_sam_config.h"
#include "tfm_log.h"
#include "bl1_1_debug.h"

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#define CMSDK_SECRESPCFG_BUS_ERR_MASK   (1UL)

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base);

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
static enum tfm_plat_err_t init_atu_regions(void)
{
#ifdef RSE_USE_HOST_UART
    enum atu_error_t atu_err;

    /* Initialize UART region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    get_supported_region_count(&ATU_DEV_S) - 1,
                                    HOST_UART0_BASE_NS, HOST_UART_BASE,
                                    HOST_UART_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }
#endif /* RSE_USE_HOST_UART */

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

/* bootloader platform-specific hw initialization */
int32_t boot_platform_init(void)
{
    int32_t err;
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    cc3xx_err_t cc_err;
    uint8_t prbg_seed[KMU_PRBG_SEED_LEN];
    uint32_t idx;
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

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    plat_err = init_atu_regions();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    stdio_init();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

#ifdef CRYPTO_HW_ACCELERATOR
    const cc3xx_dma_remap_region_t remap_regions[] = {
        {ITCM_BASE_S, ITCM_SIZE, ITCM_CPU0_BASE_S, 0x01000000},
        {ITCM_BASE_NS, ITCM_SIZE, ITCM_CPU0_BASE_NS, 0x01000000},
        {DTCM_BASE_S, DTCM_SIZE, DTCM_CPU0_BASE_S, 0x01000000},
        {DTCM_BASE_NS, DTCM_SIZE, DTCM_CPU0_BASE_NS, 0x01000000},
    };

    const cc3xx_dma_burst_restricted_region_t burst_restricted_regions[] = {
        {KMU_BASE_S + 0x130, 0x400}, /* KMU Key Slot Registers */
    };

    for (idx = 0; idx < ARRAY_SIZE(remap_regions); idx++) {
        cc3xx_lowlevel_dma_remap_region_init(idx, &remap_regions[idx]);
    }

    for (idx = 0; idx < ARRAY_SIZE(burst_restricted_regions); idx++) {
        cc3xx_lowlevel_dma_burst_restricted_region_init(idx,
            &burst_restricted_regions[idx]);
    }

    cc_err = cc3xx_lowlevel_init();
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */

    /* Init KMU */
    err = bl1_trng_generate_random(prbg_seed, sizeof(prbg_seed));
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

    /* Load the PKA encryption key, now that it is set up */
    kmu_err = kmu_export_key(&KMU_DEV_S, RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY);
    if (kmu_err != KMU_ERROR_NONE) {
        return kmu_err;
    }

    cc3xx_lowlevel_pka_sram_encryption_enable();
#endif /* CRYPTO_HW_ACCELERATOR */

    err = b1_1_platform_debug_init();
    if (err != 0) {
        return err;
    }

    /* Clear boot data area */
    memset((void *)tfm_plat_get_shared_measurement_data_base(), 0,
           tfm_plat_get_shared_measurement_data_size());

    return 0;
}

int32_t boot_platform_post_init(void)
{
    return 0;
}


int boot_platform_pre_load(uint32_t image_id)
{
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);

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

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_uninit();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);

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

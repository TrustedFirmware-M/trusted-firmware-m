/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#define MBEDTLS_ALLOW_PRIVATE_ACCESS
#include <string.h>
#include "bl1_random.h"
#include "boot_hal.h"
#include "region.h"
#include "platform_s_device_definition.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "region_defs.h"
#include "platform_base_address.h"
#include "uart_stdout.h"
#include "tfm_plat_otp.h"
#include "arm_watchdog_drv.h"
#include "kmu_drv.h"
#include "platform_regs.h"
#include "sam_reg_map.h"
#include "tfm_log.h"
#include "fih.h"

#include "mbedtls/hmac_drbg.h"

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base);

static int32_t pre_fsbl_flow(void);
static void set_slowclk_wdt(void);
static void clear_lcm_dcu_fd(void);
static bool is_reset_por_or_cold(void);
static void request_cold_reset(void);
static void wipe_ram(void);
static int load_sam_config(void);

static mbedtls_hmac_drbg_context hmac_drbg_ctx;

static int32_t __bl1_random_generate_secure_init(void)
{
    int error;
    size_t hash_bytes_used = 0;
    uint8_t entropy_seed[64];

    const mbedtls_md_info_t *md_info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA256);

    error = tfm_plat_otp_read(PLAT_OTP_ID_ENTROPY_SEED, sizeof(entropy_seed),
                                entropy_seed);
    if (TFM_PLAT_ERR_SUCCESS != error) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    mbedtls_hmac_drbg_init(&hmac_drbg_ctx);
    error = mbedtls_hmac_drbg_seed_buf(&hmac_drbg_ctx, md_info, entropy_seed, sizeof(entropy_seed));
    if (error != 0) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

int32_t bl1_random_generate_secure(uint8_t *output, size_t out_len)
{
    int ret = 1;
    size_t md_len = mbedtls_md_get_size(hmac_drbg_ctx.md_ctx.md_info);
    size_t left = out_len;
    unsigned char *out = output;

    if (output == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (out_len > MBEDTLS_HMAC_DRBG_MAX_REQUEST) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (hmac_drbg_ctx.f_entropy != NULL && /* For no-reseeding instances */
        (hmac_drbg_ctx.prediction_resistance == MBEDTLS_HMAC_DRBG_PR_ON ||
         hmac_drbg_ctx.reseed_counter > hmac_drbg_ctx.reseed_interval)) {
        if ((ret = mbedtls_hmac_drbg_reseed(&hmac_drbg_ctx, NULL, 0)) != 0) {
            return ret;
        }
    }

    while (left != 0) {
        size_t use_len = left > md_len ? md_len : left;

        if ((ret = mbedtls_md_hmac_reset(&hmac_drbg_ctx.md_ctx)) != 0) {
            goto exit;
        }
        if ((ret = mbedtls_md_hmac_update(&hmac_drbg_ctx.md_ctx,
                                          hmac_drbg_ctx.V, md_len)) != 0) {
            goto exit;
        }
        if ((ret = mbedtls_md_hmac_finish(&hmac_drbg_ctx.md_ctx, hmac_drbg_ctx.V)) != 0) {
            goto exit;
        }

        memcpy(out, hmac_drbg_ctx.V, use_len);
        out += use_len;
        left -= use_len;
    }

    if ((ret = mbedtls_hmac_drbg_update(&hmac_drbg_ctx, NULL, 0)) != 0) {
        goto exit;
    }

    hmac_drbg_ctx.reseed_counter++;

exit:
    return ret;
}

/* bootloader platform-specific hw initialization */
int32_t boot_platform_init(void)
{
    int32_t result;
    enum tfm_plat_err_t plat_err;
    uint8_t prbg_seed[KMU_PRBG_SEED_LEN];

    result = pre_fsbl_flow();
    arm_watchdog_disable(&SLOWCLK_WATCHDOG_DEV_S);
    if(0 != result) {
        return 1;
    }

    /* Initialize stack limit register */
    uint32_t msp_stack_bottom =
            (uint32_t)&REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base);

    __set_MSPLIM(msp_stack_bottom);
#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_init();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

    /* Enable system reset */
    struct mps4_corstone3xx_sysctrl_t *sysctrl =
                            (struct mps4_corstone3xx_sysctrl_t *)MPS4_CORSTONE3XX_SYSCTRL_BASE_S;
    sysctrl->reset_mask |= SYSCTRL_RESET_MASK_CPU0RSTREQEN_MASK;

    plat_err = tfm_plat_otp_init();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return 1;
    }

    /* Init the random generator using an internal specific helper function */
    result = __bl1_random_generate_secure_init();
    if (result != TFM_PLAT_ERR_SUCCESS) {
        return result;
    }

    result = bl1_random_generate_secure(prbg_seed, sizeof(prbg_seed));
    if (result != TFM_PLAT_ERR_SUCCESS) {
        return result;
    }

    /* Init KMU */
    result = kmu_init(&KMU_DEV_S, prbg_seed);
    if (result != KMU_ERROR_NONE) {
        return result;
    }

    /* Clear boot data area */
    memset((void*)SHARED_BOOT_MEASUREMENT_BASE, 0, SHARED_BOOT_MEASUREMENT_SIZE);

    return 0;
}

int32_t boot_platform_post_init(void)
{
    return 0;
}


int boot_platform_pre_load(uint32_t image_id)
{
    fih_delay();

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

static int32_t pre_fsbl_flow(void)
{
    set_slowclk_wdt();

    if (is_reset_por_or_cold() != true) {
        return 0;
    }

    enum lcm_bool_t fatal_error;
    lcm_get_fatal_error(&LCM_DEV_S, &fatal_error);
    if (fatal_error) {
        /* Won't return from this */
        request_cold_reset();
    }

    enum lcm_lcs_t lcs;
    lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcs == LCM_LCS_INVALID) {
        return -1;
    }
    enum lcm_tp_mode_t tp_mode;
    lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (tp_mode == LCM_TP_MODE_INVALID) {
        return -1;
    }

    if ((lcs == LCM_LCS_CM) || (lcs == LCM_LCS_DM)) {
        wipe_ram();
    } else if (lcs == LCM_LCS_SE) {
        if(0 != load_sam_config()) {
            return -1;
        }
    }

    clear_lcm_dcu_fd();

    return 0;
}

static void set_slowclk_wdt(void)
{
    arm_watchdog_init(&SLOWCLK_WATCHDOG_DEV_S, 0xffff);
    arm_watchdog_unlock(&SLOWCLK_WATCHDOG_DEV_S);
    arm_watchdog_enable(&SLOWCLK_WATCHDOG_DEV_S);
}

static bool is_reset_por_or_cold(void)
{
    struct mps4_corstone3xx_sysctrl_t *sysctrl =
                            (struct mps4_corstone3xx_sysctrl_t *)MPS4_CORSTONE3XX_SYSCTRL_BASE_S;
    uint32_t reset_syndrome_reg = sysctrl->reset_syndrome;
    if ((reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_POR_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_NSWDRSTREQ_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_SWDRSTREQ_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_SLOWCLKWDRSTREQ_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_RESETREQ_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_SWRESETREQ_MASK) ||
        (reset_syndrome_reg & SYSCTRL_RESET_SYNDROME_HOSTRESETREQ_MASK)) {
            return true;
        }
    return false;
}

static void request_cold_reset(void)
{
    struct mps4_corstone3xx_sysctrl_t *sysctrl =
                        (struct mps4_corstone3xx_sysctrl_t *)MPS4_CORSTONE3XX_SYSCTRL_BASE_S;
    __DSB();
    sysctrl->swreset |= SYSCTRL_SWRESET_SWRESETREQ_MASK;
    __DSB();
    while(1) {
        __NOP();
    }
}

static void clear_lcm_dcu_fd(void)
{
    struct mps4_corstone3xx_sysctrl_t *sysctrl =
                    (struct mps4_corstone3xx_sysctrl_t *)MPS4_CORSTONE3XX_SYSCTRL_BASE_S;
    sysctrl->lcm_dcu_force_dis = 0x002AAAAA;
}

static void wipe_ram(void)
{
    memset((void *)PROVISIONING_BUNDLE_CODE_START, 0,
        PROVISIONING_BUNDLE_CODE_SIZE);
    memset((void *)PROVISIONING_BUNDLE_VALUES_START, 0,
        PROVISIONING_BUNDLE_VALUES_SIZE + PROVISIONING_BUNDLE_DATA_SIZE);
}

static int load_sam_config(void)
{
    enum tfm_plat_err_t plat_err;
    uint32_t sam_icv_block_values[OTP_SAM_CONFIGURATION_SIZE_BYTES / sizeof(uint32_t)] = {0};
    struct sam_reg_map_t * sam_reg_block = (struct sam_reg_map_t *)SAM_BASE_S;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_SAM_CONFIG, OTP_SAM_CONFIGURATION_SIZE_BYTES,
                                 (uint8_t *) sam_icv_block_values);
    if(TFM_PLAT_ERR_SUCCESS != plat_err) {
        return -1;
    }

    /* SAM registers can only be accessed with 32bit read/write instructions.
     * memcpy cannot be used here, because 32bit access is not guaranteed,
     * the access width depends on the compiler.
     */
    for(uint8_t i = 0; i < (OTP_SAM_CONFIGURATION_SIZE_BYTES / sizeof(uint32_t)); i++) {
        ((uint32_t *)&(sam_reg_block->samem[0]))[i] = sam_icv_block_values[i];
    }

    return 0;
}

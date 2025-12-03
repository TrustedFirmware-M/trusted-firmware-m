/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_boot_state.h"

#include "tfm_plat_otp.h"
#include "device_definition.h"
#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
#include "lcm_drv.h"
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
#include "fatal_error.h"
#include "psa/crypto.h"

extern uint8_t computed_bl1_2_hash[];

enum tfm_plat_err_t rse_get_boot_state(uint8_t *state, size_t state_buf_len,
                       size_t *state_size, boot_state_include_mask_t mask)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    enum plat_otp_lcs_t lcs;
    enum lcm_tp_mode_t tp_mode;
    uint32_t reprovisioning_bits;
    psa_hash_operation_t hash_op = psa_hash_operation_init();
    psa_status_t status;

    if (mask == RSE_BOOT_STATE_INCLUDE_NONE) {
        *state_size = 0;
        return TFM_PLAT_ERR_SUCCESS;
    }

    if (state_buf_len < 32) {
        FATAL_ERR(TFM_PLAT_ERR_BOOT_STATE_OUTPUT_BUFFER_TOO_SMALL);
        return TFM_PLAT_ERR_BOOT_STATE_OUTPUT_BUFFER_TOO_SMALL;
    }

    status = psa_hash_setup(&hash_op, PSA_ALG_SHA_256);
    if (status != PSA_SUCCESS) {
        return (enum tfm_plat_err_t)status;
    }

    if (mask & RSE_BOOT_STATE_INCLUDE_TP_MODE) {
        lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
        if (lcm_err != LCM_ERROR_NONE) {
            return (enum tfm_plat_err_t)lcm_err;
        }

        status = psa_hash_update(&hash_op, (uint8_t *)&tp_mode, sizeof(tp_mode));
        if (status != PSA_SUCCESS) {
            return (enum tfm_plat_err_t)status;
        }
    }

    if (mask & RSE_BOOT_STATE_INCLUDE_LCS) {
        plat_err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t *)&lcs);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        status = psa_hash_update(&hash_op, (uint8_t *)&lcs, sizeof(lcs));
        if (status != PSA_SUCCESS) {
            return (enum tfm_plat_err_t)status;
        }
    }

    if (mask & RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS) {
        plat_err = tfm_plat_otp_read(PLAT_OTP_ID_REPROVISIONING_BITS,
                               sizeof(reprovisioning_bits),
                               (uint8_t *)&reprovisioning_bits);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        status = psa_hash_update(&hash_op, (uint8_t *)&reprovisioning_bits, sizeof(reprovisioning_bits));
        if (status != PSA_SUCCESS) {
            return (enum tfm_plat_err_t)status;
        }
    }

    if (mask & RSE_BOOT_STATE_INCLUDE_BL1_2_HASH) {
        status = psa_hash_update(&hash_op, computed_bl1_2_hash, 32);
        if (status != PSA_SUCCESS) {
            return (enum tfm_plat_err_t)status;
        }
    }

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    if (mask & RSE_BOOT_STATE_INCLUDE_DCU_STATE) {
        /* Get current DCU state */
        enum lcm_error_t lcm_err;
        uint32_t dcu_state[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

        lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)dcu_state);
        if (lcm_err != LCM_ERROR_NONE) {
            return -1;
        }

        err = cc3xx_lowlevel_hash_update((uint8_t *)dcu_state, LCM_DCU_WIDTH_IN_BYTES);
        if (err != CC3XX_ERR_SUCCESS) {
            return (enum tfm_plat_err_t)err;
        }
    }
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

    status = psa_hash_finish(&hash_op, state, SHA256_OUTPUT_SIZE, state_size);
    if (status != PSA_SUCCESS) {
        return (enum tfm_plat_err_t)status;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

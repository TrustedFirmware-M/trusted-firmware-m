/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "provisioning.h"
#include "tfm_plat_otp.h"
#include "coverity_check.h"

enum tfm_plat_err_t tfm_plat_otp_init(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_read(enum tfm_otp_element_id_t id,
                                      size_t out_len, uint8_t *out)
{
    if (PLAT_OTP_ID_LCS == id) {
        /* Read security lifecycle for tfm_spm_get_lifecycle_state */
        if (out_len != sizeof(enum plat_otp_lcs_t)) {
            return TFM_PLAT_ERR_INVALID_INPUT;
        }

        TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_3, "Intentional pointer type conversion, only byte of data is used");
        enum plat_otp_lcs_t *plat_lcs = (enum plat_otp_lcs_t *)out;
        uint32_t lcs = ifx_get_security_lifecycle() & PSA_LIFECYCLE_PSA_STATE_MASK;
        switch (lcs) {
        case PSA_LIFECYCLE_ASSEMBLY_AND_TEST:
        case PSA_LIFECYCLE_NON_PSA_ROT_DEBUG:
        case PSA_LIFECYCLE_RECOVERABLE_PSA_ROT_DEBUG:
            *plat_lcs = PLAT_OTP_LCS_ASSEMBLY_AND_TEST;
            break;
        case PSA_LIFECYCLE_PSA_ROT_PROVISIONING:
            *plat_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
            break;
        case PSA_LIFECYCLE_SECURED:
            *plat_lcs = PLAT_OTP_LCS_SECURED;
            break;
        case PSA_LIFECYCLE_DECOMMISSIONED:
            *plat_lcs = PLAT_OTP_LCS_DECOMMISSIONED;
            break;
        case PSA_LIFECYCLE_UNKNOWN:
        default:
            *plat_lcs = PLAT_OTP_LCS_UNKNOWN;
            break;
        }
        return TFM_PLAT_ERR_SUCCESS;
    }

    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t tfm_plat_otp_write(enum tfm_otp_element_id_t id,
                                       size_t in_len, const uint8_t *in)
{
    (void)id;
    (void)in_len;
    (void)in;

    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t tfm_plat_otp_get_size(enum tfm_otp_element_id_t id,
                                          size_t *size)
{
    (void)id;
    (void)size;

    return TFM_PLAT_ERR_UNSUPPORTED;
}

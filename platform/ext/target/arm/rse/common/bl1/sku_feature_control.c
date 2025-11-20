/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "dcsu_drv.h"
#include "fatal_error.h"
#include "lcm_drv.h"
#include "platform_error_codes.h"
#include "rse_otp_dev.h"
#include "rse_otp_layout.h"
#include "sku_feature_control.h"

#define FEATURE_CONTROL_MAX     (16)
#define DCU_OVERRIDE_BIT_OFFSET (8)
#define DCU_OVERRIDE_BIT_WIDTH  (5)
#define DCU_LINE                (3)

enum tfm_plat_err_t rse_dcu_otp_feature_control(struct lcm_dev_t *lcm_dev, struct dcsu_dev_t *dcsu_dev)
{
    uint32_t feature_control;
    uint32_t cm_policies;
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t plat_err;
    enum dcsu_error_t dcsu_err;
    uint32_t dcu_disable_mask[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t dcu_lines[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint8_t dcu_override_field = 0;
    uint32_t dcsu_status = 0;
    uint8_t ps_fc[4];
    enum tfm_plat_err_t (*const ps_fc_ptr[RSE_PS_FC_HANDLERS_NUM])(void) = {
        product_specific_feature_control_handler_0,
        product_specific_feature_control_handler_1,
        product_specific_feature_control_handler_2
    };

    /* DCU-based feature control */
    lcm_err = lcm_otp_read(lcm_dev, OTP_OFFSET(P_RSE_OTP_DYNAMIC->feature_control),
                           sizeof(P_RSE_OTP_DYNAMIC->feature_control),
                           (uint8_t *)(&feature_control));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_read(lcm_dev, OTP_OFFSET(P_RSE_OTP_CM->cm_policies),
                           sizeof(P_RSE_OTP_CM->cm_policies), (uint8_t *)(&cm_policies));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    dcu_override_field =
        (cm_policies >> DCU_OVERRIDE_BIT_OFFSET) & ((1 << (DCU_OVERRIDE_BIT_WIDTH)) - 1);

    if (dcu_override_field > FEATURE_CONTROL_MAX) {
        FATAL_ERR(TFM_PLAT_ERR_DCU_FEATURE_CONTROL_EXCEED_LIMIT);
        return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_EXCEED_LIMIT;
    }

    if (dcu_override_field != 0) {
        /* dcu_override_field specifies the number of MSBs of feature_control to be used */
        uint32_t feature_en_mask = feature_control &
            (~0u << (sizeof(feature_en_mask) * 8 - dcu_override_field));

        if (!feature_en_mask) {
            return TFM_PLAT_ERR_SUCCESS;
        }

        lcm_err = lcm_dcu_get_disable_mask(lcm_dev, (uint8_t *)&dcu_disable_mask);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }

        if ((dcu_disable_mask[DCU_LINE] & feature_en_mask) != feature_en_mask) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_SIGNAL_DISABLED;
        }

        lcm_err = lcm_dcu_get_enabled(lcm_dev, (uint8_t *)&dcu_lines);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }

        dcu_lines[DCU_LINE] |= feature_en_mask;

        lcm_err = lcm_dcu_set_enabled(lcm_dev, (uint8_t *)&dcu_lines);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }
    }

    /*
     * Update the DCSU status info with the applied feature control.
     * The 32 bit otp value has been masked and only the top cm_policies
     * [0, 16] number of bits are kept.
     */
    dcsu_status |= feature_control;

    /* Product-specific feature control */
    lcm_err = lcm_otp_read(lcm_dev, OTP_OFFSET(P_RSE_OTP_DYNAMIC->ps_fc),
                           sizeof(ps_fc), (uint8_t *)(ps_fc));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    for (uint8_t i = 0; i < RSE_PS_FC_HANDLERS_NUM; i++) {
        /* Update the DCSU status info with the policy-specific feature control */
        dcsu_status |= (ps_fc[i] & 0x7) << (10 - (i * 3));

        if (ps_fc[i] == RSE_OTP_PS_FC_VALUE_ENABLED) {
            plat_err = ps_fc_ptr[i]();

            if (plat_err != TFM_PLAT_ERR_SUCCESS) {
                return plat_err;
            }
        }
    }

    /* Write back the updated DCSU status info */
    dcsu_err = dcsu_write_sw_status(dcsu_dev, dcsu_status, 0);
    if (dcsu_err != DCSU_ERROR_NONE) {
        return (enum tfm_plat_err_t)dcsu_err;
    }


    return TFM_PLAT_ERR_SUCCESS;
}

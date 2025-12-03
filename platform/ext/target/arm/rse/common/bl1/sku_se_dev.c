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
#include "sku_se_dev.h"
#include "fih.h"

#define DCSU_SW_DEFINED0_OTP_DCU_OFFSET     (16)
#define DCSU_SW_DEFINED0_OTP_DCU_MASK       ((1 << 16) - 1)
#define DCSU_SW_DEFINED0_SE_DEV_CTRL_OFFSET (13)
#define DCSU_SW_DEFINED0_SE_DEV_CTRL_MASK   ((1 << 3) - 1)
#define DCSU_SW_DEFINED0_PS_FC_OFFSET(_idx) (10 - (3 * (_idx)))
#define DCSU_SW_DEFINED0_PS_FC_MASK         ((1 << 3) - 1)
#define DCSU_SW_DEFINED0_STATUS_OFFSET      (0)
#define DCSU_SW_DEFINED0_STATUS_MASK        ((1 << 4) - 1)

#define FEATURE_CONTROL_MAX     (16)
#define DCU_OVERRIDE_BIT_OFFSET (8)
#define DCU_OVERRIDE_BIT_WIDTH  (5)
#define DCU_LINE                (3)

/* Platform specific SE-DEV DCU enables - default do not
 * enable anything */
#ifndef PLAT_RSE_DCU_SE_DEV_ENABLE0_VALUE
#define PLAT_RSE_DCU_SE_DEV_ENABLE0_VALUE 0x00000000
#endif
#ifndef PLAT_RSE_DCU_SE_DEV_ENABLE1_VALUE
#define PLAT_RSE_DCU_SE_DEV_ENABLE1_VALUE 0x00000000
#endif
#ifndef PLAT_RSE_DCU_SE_DEV_ENABLE2_VALUE
#define PLAT_RSE_DCU_SE_DEV_ENABLE2_VALUE 0x00000000
#endif
#ifndef PLAT_RSE_DCU_SE_DEV_ENABLE3_VALUE
#define PLAT_RSE_DCU_SE_DEV_ENABLE3_VALUE 0x00000000
#endif

#ifdef RSE_HAS_SE_DEV_SOFT_LCS
static enum tfm_plat_err_t check_apply_se_dev_dcus(uint32_t *dcsu_swdefined0)
{
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
    struct rse_otp_se_dev_control_ps_fc_t se_dev_control_ps_fc;
    uint32_t dcu_enable_reg_val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* SE-DEV field is 1 byte, but read length must be 4 byte aligned */
    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->se_dev_control_ps_fc),
                           sizeof(se_dev_control_ps_fc), (uint8_t *)&se_dev_control_ps_fc);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    *dcsu_swdefined0 |= (se_dev_control_ps_fc.se_dev_control & DCSU_SW_DEFINED0_SE_DEV_CTRL_MASK)
                        << DCSU_SW_DEFINED0_SE_DEV_CTRL_OFFSET;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (lcs != LCM_LCS_SE) {
        /* Need to be in SE to apply SE-DEV LCS */
        return TFM_PLAT_ERR_SUCCESS;
    }

    if (FIH_COND_CHECK(se_dev_control_ps_fc.se_dev_control !=
                       RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED)) {
        /* Not in SE-DEV LCS */
        return TFM_PLAT_ERR_SUCCESS;
    }

    lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)dcu_enable_reg_val);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    dcu_enable_reg_val[0] = PLAT_RSE_DCU_SE_DEV_ENABLE0_VALUE;
    dcu_enable_reg_val[1] = PLAT_RSE_DCU_SE_DEV_ENABLE1_VALUE;
    dcu_enable_reg_val[2] = PLAT_RSE_DCU_SE_DEV_ENABLE2_VALUE;
    dcu_enable_reg_val[3] = PLAT_RSE_DCU_SE_DEV_ENABLE3_VALUE;

    lcm_err = lcm_dcu_set_enabled(&LCM_DEV_S, (uint8_t *)dcu_enable_reg_val);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_HAS_SE_DEV_SOFT_LCS */

#ifdef RSE_SKU_ENABLED
static enum tfm_plat_err_t apply_otp_feature_control_ps_fc(uint32_t *dcsu_swdefined0)
{
    uint32_t feature_control;
    uint32_t cm_policies;
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t plat_err;
    uint32_t dcu_disable_mask[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t dcu_lines[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint8_t dcu_override_field = 0;
    struct rse_otp_se_dev_control_ps_fc_t se_dev_control_ps_fc;
    enum tfm_plat_err_t (*const ps_fc_ptr[RSE_PS_FC_HANDLERS_NUM])(void) = {
        product_specific_feature_control_handler_0,
        product_specific_feature_control_handler_1,
        product_specific_feature_control_handler_2
    };

    /* DCU-based feature control */
    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->feature_control),
                           sizeof(P_RSE_OTP_DYNAMIC->feature_control),
                           (uint8_t *)(&feature_control));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cm_policies),
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

        lcm_err = lcm_dcu_get_disable_mask(&LCM_DEV_S, (uint8_t *)&dcu_disable_mask);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }

        if ((dcu_disable_mask[DCU_LINE] & feature_en_mask) != feature_en_mask) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_SIGNAL_DISABLED;
        }

        lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&dcu_lines);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }

        dcu_lines[DCU_LINE] |= feature_en_mask;

        lcm_err = lcm_dcu_set_enabled(&LCM_DEV_S, (uint8_t *)&dcu_lines);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_DCU_FEATURE_CONTROL_ERROR;
        }
    }

    /*
     * Update the DCSU status info with the applied feature control.
     * The 32 bit otp value has been masked and only the top cm_policies
     * [0, 16] number of bits are kept.
     */
    *dcsu_swdefined0 |= feature_control;

    /* Product-specific feature control */
    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->se_dev_control_ps_fc),
                           sizeof(se_dev_control_ps_fc), (uint8_t *)&se_dev_control_ps_fc);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    for (uint8_t i = 0; i < RSE_PS_FC_HANDLERS_NUM; i++) {
        /* Update the DCSU status info with the policy-specific feature control */
        *dcsu_swdefined0 |= (se_dev_control_ps_fc.ps_fc[i] & DCSU_SW_DEFINED0_PS_FC_MASK)
                            << DCSU_SW_DEFINED0_PS_FC_OFFSET(i);

        if (se_dev_control_ps_fc.ps_fc[i] == RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED) {
            plat_err = ps_fc_ptr[i]();

            if (plat_err != TFM_PLAT_ERR_SUCCESS) {
                return plat_err;
            }
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_SKU_ENABLED */

enum tfm_plat_err_t rse_apply_sku_se_dev_overrides(void)
{
#if defined(RSE_SKU_ENABLED) || defined(RSE_HAS_SE_DEV_SOFT_LCS)
    enum tfm_plat_err_t plat_err;
    uint32_t dcsu_swdefined0 = 0;
    enum dcsu_error_t dcsu_err;
#endif

#ifdef RSE_SKU_ENABLED
    plat_err = apply_otp_feature_control_ps_fc(&dcsu_swdefined0);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#endif

#ifdef RSE_HAS_SE_DEV_SOFT_LCS
    plat_err = check_apply_se_dev_dcus(&dcsu_swdefined0);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#endif

#if defined(RSE_SKU_ENABLED) || defined(RSE_HAS_SE_DEV_SOFT_LCS)
    /* Write the updated DCSU status info */
    dcsu_err = dcsu_write_sw_status(&DCSU_DEV_S, dcsu_swdefined0, 0);
    if (dcsu_err != DCSU_ERROR_NONE) {
        return (enum tfm_plat_err_t)dcsu_err;
    }
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

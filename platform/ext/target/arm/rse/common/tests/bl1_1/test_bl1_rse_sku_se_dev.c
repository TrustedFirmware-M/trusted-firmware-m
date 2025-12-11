/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_test_common.h"
#include "test_bl1_rse_sku_se_dev.h"

#include "device_definition.h"
#include "rse_otp_dev.h"
#include "rse_otp_layout.h"
#include "sku_se_dev.h"
#include "lcm_drv.h"
#include "sku_test_stubs.h"

#ifdef RSE_SKU_ENABLED
#define TEST_FEATURE_CONTROL_BITS (8)
#define TEST_FEATURE_CONTROL_VALUE (0x12340000)

/*
 * CM area is protected by zero counts so these fields must be set before switching to DM lcs.
 * This test sets CM policies for test_bl1_rse_sku_feature_control testcase.
 */
void test_bl1_rse_sku_set_cm_policies(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    uint32_t policies_flags = TEST_FEATURE_CONTROL_BITS << 8;

    plat_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cm_policies),
                             sizeof(policies_flags), (uint8_t *)&policies_flags);
    TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                "Failed to write cm policies to otp");

    ret->val = TEST_PASSED;
    return;
}

void test_bl1_rse_sku_feature_control(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    uint32_t feature_control = TEST_FEATURE_CONTROL_VALUE;
    uint32_t expected_dcu_en = feature_control & (~0u << (32 - TEST_FEATURE_CONTROL_BITS));
    uint32_t dcu_lines[4];

    plat_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->feature_control),
                             sizeof(feature_control), (uint8_t *)&feature_control);
    TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                "Failed to write feature control to otp");

    plat_err = rse_apply_sku_se_dev_overrides();
    TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                "Feature control failed");

    lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&dcu_lines);
    TEST_ASSERT(lcm_err == LCM_ERROR_NONE,
                "Failed to get DCU enabled lines");

    TEST_ASSERT((dcu_lines[3] & expected_dcu_en) == expected_dcu_en,
                "DCU lines do not match expected value");

    ret->val = TEST_PASSED;
    return;
}

void test_bl1_rse_sku_ps_fc(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    struct rse_otp_se_dev_control_ps_fc_t se_dev_control_ps_fc = {
        .se_dev_control = RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
        .ps_fc = {
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED
        }
    };

    /* Store the values in such order that can follow each other */
    enum rse_otp_se_dev_control_ps_fc_valus_t ps_fc_states[] = {
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED,
        0b110, /* Invalid value */
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED_LOCKED
    };

    /* Test each PS FC channels for each possible values */
    for (uint8_t i = 0; i < sizeof(ps_fc_states); i++) {
        for (uint8_t j = 0; j < 3; j++) {
            se_dev_control_ps_fc.ps_fc[j] = ps_fc_states[i];

            plat_err = lcm_otp_write(&LCM_DEV_S,
                                     OTP_OFFSET(P_RSE_OTP_DYNAMIC->se_dev_control_ps_fc),
                                     sizeof(se_dev_control_ps_fc),
                                     (uint8_t *)&se_dev_control_ps_fc);
            TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                        "Failed to write product specific feature control to otp");

            plat_err = rse_apply_sku_se_dev_overrides();
            TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                        "Feature control failed");

            /* Test ps fc calls */
            for (uint8_t k = 0; k < 3; k++) {
                if (se_dev_control_ps_fc.ps_fc[k] == RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED) {
                    TEST_ASSERT(sku_ps_fc_called[k] == 1, "PS FC call error");
                } else {
                    TEST_ASSERT(sku_ps_fc_called[k] == 0, "PS FC call error");
                }
            }

            sku_ps_fc_called[2] = sku_ps_fc_called[1] = sku_ps_fc_called[0] = 0;
        }
    }

    ret->val = TEST_PASSED;
    return;
}

#endif /* RSE_SKU_ENABLED */

#ifdef RSE_HAS_SE_DEV_SOFT_LCS

#define DCU_PARITY_BITS 0x02AAAAAA

void test_bl1_rse_sku_se_dev(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    struct rse_otp_se_dev_control_ps_fc_t se_dev_control_ps_fc = {
        .se_dev_control = RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
        .ps_fc = {
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED_LOCKED,
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED_LOCKED,
            RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED_LOCKED
        }
    };

    /* Store the values in such order that can follow each other */
    enum rse_otp_se_dev_control_ps_fc_valus_t se_dev_states[] = {
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED,
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED,
        0b110, /* Invalid value */
        RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_DISABLED_LOCKED
    };

    uint32_t new_dcu_lines[4];
    uint32_t orig_dcu_lines[4];

    for (uint8_t i = 0; i < sizeof(se_dev_states); i++) {
        se_dev_control_ps_fc.se_dev_control = se_dev_states[i];

        lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&orig_dcu_lines);
        TEST_ASSERT(lcm_err == LCM_ERROR_NONE,
                    "Failed to get DCU enabled lines");

        plat_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->se_dev_control_ps_fc),
                                sizeof(se_dev_control_ps_fc), (uint8_t *)&se_dev_control_ps_fc);
        TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                    "Failed to write se-dev control to otp");

        plat_err = rse_apply_sku_se_dev_overrides();
        TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS,
                    "SE-DEV LCS override failed");

        lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&new_dcu_lines);
        TEST_ASSERT(lcm_err == LCM_ERROR_NONE,
                    "Failed to get DCU enabled lines");

        if (se_dev_states[i] == RSE_OTP_SE_DEV_CONTROL_PS_FC_VALUE_ENABLED) {

            TEST_ASSERT(new_dcu_lines[0] == PLAT_RSE_DCU_SE_DEV_ENABLE0_VALUE,
                        "DCU lines do not match expected value");
            TEST_ASSERT(new_dcu_lines[1] == PLAT_RSE_DCU_SE_DEV_ENABLE1_VALUE,
                        "DCU lines do not match expected value");
            TEST_ASSERT(new_dcu_lines[2] == PLAT_RSE_DCU_SE_DEV_ENABLE2_VALUE,
                        "DCU lines do not match expected value");
            TEST_ASSERT(new_dcu_lines[3] == PLAT_RSE_DCU_SE_DEV_ENABLE3_VALUE,
                        "DCU lines do not match expected value");
        } else {
            TEST_ASSERT(new_dcu_lines[0] == orig_dcu_lines[0],
                        "DCU lines has been changed unexpectedly");
            TEST_ASSERT(new_dcu_lines[1] == orig_dcu_lines[1],
                        "DCU lines has been changed unexpectedly");
            TEST_ASSERT(new_dcu_lines[2] == orig_dcu_lines[2],
                        "DCU lines has been changed unexpectedly");
            TEST_ASSERT(new_dcu_lines[3] == orig_dcu_lines[3],
                        "DCU lines has been changed unexpectedly");
        }
    }

    ret->val = TEST_PASSED;
    return;
}
#endif /* RSE_HAS_SE_DEV_SOFT_LCS */

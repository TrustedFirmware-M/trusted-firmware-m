/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "test_state_transitions.h"

#include "cc3xx_drv.h"
#include "device_definition.h"
#include "tfm_plat_otp.h"
#include "rse_otp_layout.h"
#include "tfm_hal_platform.h"

void rse_test_virgin_to_tci_or_pci(struct test_result_t *ret)
{
    enum lcm_tp_mode_t tp_mode;
    enum lcm_error_t lcm_err;

    tp_mode = RSE_TESTS_TP_MODE;

    printf_set_color(MAGENTA);
    TEST_LOG("Entering %s mode\r\n", tp_mode == LCM_TP_MODE_PCI ? "PCI" : "TCI");
    printf_set_color(DEFAULT);

    lcm_err = lcm_set_tp_mode(&LCM_DEV_S, tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        TEST_FAIL("LCM TP mode set failed");
        return;
    }

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);

    ret->val = TEST_PASSED;
    return;
}

void rse_test_cm_sp_enable(struct test_result_t *ret)
{
    enum lcm_error_t lcm_err;

    lcm_err = lcm_set_sp_enabled(&LCM_DEV_S);
    if (lcm_err != LCM_ERROR_NONE) {
        TEST_FAIL("LCM CM SP mode enable failed");
        return;
    }

    ret->val = TEST_PASSED;
    return;
}

static enum tfm_plat_err_t setup_otp_area_infos(void)
{
    enum lcm_error_t lcm_err;
    uint16_t offset = 0;

    offset += sizeof(struct rse_otp_header_area_t);
    struct rse_otp_area_info_t cm_area_info = { .offset = offset,
                                                .size = sizeof(struct rse_otp_cm_area_t) };
    lcm_err = lcm_otp_write(&LCM_DEV_S, offsetof(struct rse_otp_header_area_t, cm_area_info),
                            sizeof(cm_area_info), (uint8_t *)&cm_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    offset += sizeof(struct rse_otp_cm_area_t);
    struct rse_otp_area_info_t bl1_2_area_info = { .offset = offset,
                                                   .size = sizeof(struct rse_otp_bl1_2_area_t) };
    lcm_err = lcm_otp_write(&LCM_DEV_S, offsetof(struct rse_otp_header_area_t, bl1_2_area_info),
                            sizeof(bl1_2_area_info), (uint8_t *)&bl1_2_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    struct rse_otp_area_info_t soc_area_info = { .offset = RSE_OTP_SIZE -
                                                           sizeof(struct rse_otp_soc_area_t),
                                                 .size = sizeof(struct rse_otp_soc_area_t) };
    lcm_err = lcm_otp_write(&LCM_DEV_S, offsetof(struct rse_otp_header_area_t, soc_area_info),
                            sizeof(soc_area_info), (uint8_t *)&soc_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

#ifndef OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    offset += sizeof(struct rse_otp_bl1_2_area_t);
    struct rse_otp_area_info_t dm_area_info = { .offset = offset,
                                                .size = sizeof(struct rse_otp_dm_area_t) };
    lcm_err = lcm_otp_write(&LCM_DEV_S, offsetof(struct rse_otp_header_area_t, dm_area_info),
                            sizeof(dm_area_info), (uint8_t *)&dm_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    offset += sizeof(struct rse_otp_dm_area_t);
    struct rse_otp_area_info_t dynamic_area_info = { .offset = offset,
                                                     .size = soc_area_info.offset - offset };
    lcm_err = lcm_otp_write(&LCM_DEV_S, offsetof(struct rse_otp_header_area_t, dynamic_area_info),
                            sizeof(dynamic_area_info), (uint8_t *)&dynamic_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE */

    return TFM_PLAT_ERR_SUCCESS;
}

void rse_test_cm_to_dm(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    uint32_t new_lcs;

    /* When making the state transition from CM->DM, we
     * write the zero counts of the various areas. There
     * does not actually need to be anything in the areas
     * themselves, but we must configure the OTP header
     * so that the code can figure out where the areas
     * are */
    plat_err = setup_otp_area_infos();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        TEST_FAIL("Setup OTP area info failed");
        return;
    }

    new_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    plat_err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        TEST_FAIL("LCM CM to DM transition failed");
        return;
    }

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);

    ret->val = TEST_PASSED;
    return;
}

void rse_test_dm_sp_enable(struct test_result_t *ret)
{
    enum lcm_error_t lcm_err;

    lcm_err = lcm_set_sp_enabled(&LCM_DEV_S);
    if (lcm_err != LCM_ERROR_NONE) {
        TEST_FAIL("LCM DM SP mode enable failed");
        return;
    }

    ret->val = TEST_PASSED;
    return;
}

void rse_test_dm_to_se(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    uint32_t new_lcs;

    new_lcs = PLAT_OTP_LCS_SECURED;
    plat_err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        TEST_FAIL("LCM DM to SE transition failed");
        return;
    }

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);

    ret->val = TEST_PASSED;
    return;
}

void rse_test_se_to_rma(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    uint32_t new_lcs;

    new_lcs = PLAT_OTP_LCS_DECOMMISSIONED;
    plat_err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        TEST_FAIL("LCM SE to RMA transition failed");
        return;
    }

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);

    ret->val = TEST_PASSED;
    return;
}

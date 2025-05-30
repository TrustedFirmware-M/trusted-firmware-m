/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_otp.h"
#include "rse_provisioning_values.h"
#include "device_definition.h"
#include "rse_otp_dev.h"
#include "region_defs.h"
#include "tfm_log.h"
#include "rse_provisioning_message_handler.h"

/* Non secret provisioning values are placed directly after the
 * blob code DATA section */
extern uint32_t Image$$DATA$$Limit[];

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
static const struct rse_non_secret_dm_provisioning_values_t *values =
    (const struct rse_non_secret_dm_provisioning_values_t *)Image$$DATA$$Limit;

static const struct rse_secret_dm_provisioning_values_t *secret_values =
    (const struct rse_secret_dm_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START;;

/* This is a stub to make the linker happy */
void __Vectors(){}
#else
static const struct rse_non_secret_dm_provisioning_values_t *values =
    &((const struct rse_non_secret_combined_provisioning_values_t *)Image$$DATA$$Limit)->dm;

static const struct rse_secret_dm_provisioning_values_t *secret_values =
    &((const struct rse_secret_combined_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START)->dm;
#endif

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
__attribute__((section("DO_PROVISION"))) enum tfm_plat_err_t do_provision(void) {
#else
enum tfm_plat_err_t do_dm_provision(void) {
#endif
    enum tfm_plat_err_t err;
    uint32_t new_lcs;
    enum lcm_error_t lcm_err;

    INFO("Provisioning KP_DM\n");
    err = tfm_plat_otp_write(PLAT_OTP_ID_DM_PROVISIONING_KEY,
                             sizeof(secret_values->kp_dm),
                             secret_values->kp_dm);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }


    INFO("Provisioning KCE_DM\n");
    err = tfm_plat_otp_write(PLAT_OTP_ID_DM_CODE_ENCRYPTION_KEY,
                             sizeof(secret_values->kce_dm),
                             secret_values->kce_dm);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* The OTP system hasn't got the area_infos set up yet, so this has to
     * bypass the OTP HAL and directly use the LCM.
     */
#ifdef OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    INFO("Writing DM area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dm_area_info),
                            sizeof(values->dm_area_info),
                            (uint8_t *)&values->dm_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
    err = rse_count_zero_bits((uint32_t *)&P_RSE_OTP_HEADER->dm_area_info,
                              sizeof(P_RSE_OTP_HEADER->dm_area_info),
                              &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dm_area_info_zero_count),
                            sizeof(zero_count),
                            (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    INFO("Writing dynamic area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dynamic_area_info),
                            sizeof(values->dynamic_area_info),
                            (uint8_t *)&values->dynamic_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
    err = rse_count_zero_bits((uint32_t *)&P_RSE_OTP_HEADER->dynamic_area_info,
                              sizeof(P_RSE_OTP_HEADER->dynamic_area_info),
                              &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dynamic_area_info_zero_count),
                            sizeof(zero_count),
                            (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    dm_area_info = values->dm_area_info;
#endif /* OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE */

#ifndef RSE_NON_ENDORSED_DM_PROVISIONING
    if (sizeof(values->dm) != dm_area_info.size) {
        return TFM_PLAT_ERR_DM_PROVISIONING_INVALID_DM_AREA_SIZE;
    }

    INFO("Writing DM provisioning values\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S, dm_area_info.offset,
                            sizeof(values->dm), (uint8_t *)(&values->dm));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* RSE_NON_ENDORSED_DM_PROVISIONING */

    message_handling_status_report_continue(
        PROVISIONING_REPORT_STEP_MANDATORY_EARLY_DM_PROVISIONING);

    INFO("Transitioning to SE LCS\n");
    new_lcs = PLAT_OTP_LCS_SECURED;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS,
                             sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    message_provisioning_finished(PROVISIONING_REPORT_STEP_RUN_BLOB);

    return err;
}

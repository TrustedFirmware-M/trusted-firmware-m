/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "provisioning/rse_provisioning_message_handler.h"
#include "tfm_plat_otp.h"
#include "rse_provisioning_plain_data_handler.h"
#include "rse_provisioning_values.h"
#include "rse_rotpk_revocation.h"

static enum tfm_plat_err_t
handle_non_endorsed_dm_rotpks(const struct rse_provisioning_message_plain_t *plain_data,
                              size_t data_size)
{
    enum tfm_plat_err_t plat_err;
    uint32_t policies_flags;
    struct rse_non_endorsed_dm_provisioning_values_t *non_endorsed_values;

    if (data_size != sizeof(struct rse_non_endorsed_dm_provisioning_values_t)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_INVALID_SIZE;
    }

    non_endorsed_values = (struct rse_non_endorsed_dm_provisioning_values_t *)plain_data->data;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_CM_CONFIG_FLAGS, sizeof(policies_flags),
                                 (uint8_t *)&policies_flags);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (!rse_otp_policy_check(policies_flags, CM_POLICIES_DM_PROVISIONING_NON_ENDORSED_FLOW)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_INVALID_CM_POLICY;
    }

    plat_err = rse_update_dm_rotpks(non_endorsed_values->non_endorsed_dm_rotpk_policies,
                                    (uint8_t *)non_endorsed_values->rotpk,
                                    sizeof(non_endorsed_values->rotpk));
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    message_provisioning_finished(PROVISIONING_REPORT_STEP_UPDATE_ROTPKS);
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
default_plain_data_handler(const struct rse_provisioning_message_plain_t *plain_data,
                           size_t msg_size, const void *ctx)
{
    if (msg_size < sizeof(*plain_data)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_NO_TYPE;
    }

    switch (plain_data->plain_metadata) {
    case RSE_PROVISIONING_PLAIN_DATA_TYPE_NON_ENDORSED_DM_ROTPKS:
        return handle_non_endorsed_dm_rotpks(plain_data, msg_size - sizeof(*plain_data));
    default:
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_TYPE_INVALID;
    }
}

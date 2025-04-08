/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "lcm_drv.h"
#include "rse_provisioning_message.h"
#include "tfm_plat_provisioning.h"

#include "region_defs.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_comms.h"
#include "device_definition.h"
#include "tfm_log.h"
#include "tfm_hal_platform.h"
#include "rse_provisioning_aes_key.h"
#include "rse_provisioning_rotpk.h"

#include <string.h>

void tfm_plat_provisioning_check_for_dummy_keys(void)
{
    /* FixMe: Check for dummy key must be implemented */
}

int tfm_plat_provisioning_is_required(void)
{
    enum lcm_error_t err;
    enum lcm_lcs_t lcs;
    bool provisioning_required;

    err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (err != LCM_ERROR_NONE) {
        assert(false);
        return false;
    }

#ifndef RSE_BOOT_IN_DM_LCS
    provisioning_required = false;
#else
    provisioning_required = (lcs == LCM_LCS_DM);
#endif /* RSE_BOOT_IN_DM_LCS */

    return provisioning_required;
}

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    INFO("Beginning RSE provisioning\n");
    enum tfm_plat_err_t err;
    const struct rse_provisioning_message_t *provisioning_message =
    (const struct rse_provisioning_message_t *)PROVISIONING_MESSAGE_START;

    struct provisioning_message_handler_config config = {
        .blob_handler = &default_blob_handler,
    };

    struct default_blob_handler_ctx_t ctx = {
        .setup_aes_key = rse_provisioning_setup_aes_key,
#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
        .get_rotpk = provisioning_rotpk_get,
#endif
        .blob_is_chainloaded = false,
    };

    err = provisioning_comms_init(provisioning_message, RSE_PROVISIONING_MESSAGE_MAX_SIZE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = provisioning_comms_receive_commands_blocking();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* FixMe: Check if the current way of handling blobs can result in running
     *        a malformed blob in case a reset happens in the middle of an
     *        operation which has already written the blob header
     */
    err = handle_provisioning_message(provisioning_message,
                                      RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                      &config, (void *)&ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, RSE_PROVISIONING_MESSAGE_MAX_SIZE);
        blob_handling_status_report_error(PROVISIONING_REPORT_STEP_RUN_BLOB, err);
        return err;
    }

    tfm_hal_system_reset();

    return TFM_PLAT_ERR_SUCCESS;
}

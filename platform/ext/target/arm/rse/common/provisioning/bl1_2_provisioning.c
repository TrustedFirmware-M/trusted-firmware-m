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
#include "rse_provisioning_message_status.h"
#include "rse_provisioning_blob_handler.h"
#include "device_definition.h"
#include "tfm_log.h"
#include "tfm_hal_platform.h"
#include "rse_provisioning_aes_key.h"
#include "rse_provisioning_rotpk.h"
#include "rse_provisioning_get_message.h"
#include "rse_persistent_data.h"

#include <assert.h>
#include <string.h>

void tfm_plat_provisioning_check_for_dummy_keys(void)
{
    /* FixMe: Check for dummy key must be implemented */
}

enum tfm_plat_err_t tfm_plat_provisioning_is_required(bool *provisioning_required)
{
    enum lcm_error_t err;
    enum lcm_lcs_t lcs;

    if (provisioning_required == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    *provisioning_required = false;

#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
    *provisioning_required = *provisioning_required || (lcs == LCM_LCS_SE);
#endif

#ifdef RSE_BOOT_IN_DM_LCS
    *provisioning_required = *provisioning_required || (lcs == LCM_LCS_DM);
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t setup_aes_key(const struct rse_provisioning_message_blob_t *blob,
                                         uint32_t *key_id)
{
#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (lcs == LCM_LCS_SE) {
        /* Blob not encrypted so key not required */
        *key_id = 0;
        return TFM_PLAT_ERR_SUCCESS;
    }
#endif /* RSE_NON_ENDORSED_DM_PROVISIONING */

    return rse_provisioning_setup_aes_key(blob, key_id);
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
        .setup_aes_key = setup_aes_key,
#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
        .get_rotpk = provisioning_rotpk_get,
#endif
        .blob_is_chainloaded = false,
    };

    err = rse_provisioning_get_message(provisioning_message, RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                       PROVISIONING_STAGING_STATUS_BL1_2_MESSAGE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = handle_provisioning_message(provisioning_message,
                                      RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                      &config, (void *)&ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, RSE_PROVISIONING_MESSAGE_MAX_SIZE);
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_RUN_BLOB, err);
        return err;
    }

    tfm_hal_system_reset();

    return TFM_PLAT_ERR_SUCCESS;
}

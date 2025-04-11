/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
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
#include "rse_persistent_data.h"

#include <string.h>

static inline bool found_valid_message_type(const struct rse_provisioning_message_t *message)
{
    const enum rse_provisioning_message_type_t msg_type = message->header.type;

    return (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_BLOB) ||
           (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_CERTIFICATE) ||
           (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA);
}

static inline bool blob_is_in_sram(const struct rse_provisioning_message_t *message, size_t size)
{
    uintptr_t message_ptr = (uintptr_t)message;

    return (message_ptr <= (UINTPTR_MAX - size)) && (message_ptr >= VM0_BASE_S) &&
           ((message_ptr + size) <= (VM0_BASE_S + VM0_SIZE + VM1_SIZE));
}

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

    provisioning_required = (lcs == LCM_LCS_CM || lcs == LCM_LCS_DM);

    return provisioning_required;
}

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    INFO("Beginning RSE provisioning\n");
    enum tfm_plat_err_t err;
    struct rse_persistent_data *persistent_data;
    const struct rse_provisioning_message_t *provisioning_message =
        (const struct rse_provisioning_message_t *)PROVISIONING_MESSAGE_START;
    const struct rse_provisioning_message_t *persistent_data_message;
    size_t provisioning_message_size = RSE_PROVISIONING_MESSAGE_MAX_SIZE;
    size_t *persistent_data_message_size;
    bool found_persistent_data_message = false;
#ifdef RSE_BOOT_IN_DM_LCS
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
#endif

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

#ifdef RSE_BOOT_IN_DM_LCS
    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* RSE_BOOT_IN_DM_LCS */

    rse_get_persistent_data(&persistent_data);
    persistent_data_message =
        (const struct rse_provisioning_message_t *)persistent_data->bl1_data.provisioning_blob_buf;
    persistent_data_message_size = &persistent_data->bl1_data.provisioning_blob_buf_size;
    if ((persistent_data_message != NULL)) {
        if (!blob_is_in_sram(persistent_data_message, *persistent_data_message_size)) {
            return TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_LOCATION;
        }

        if (found_valid_message_type(persistent_data_message)) {
            found_persistent_data_message = true;
        }
    }

    /*
     * There are three options for where we can load the provisioning blob from:
     *  1. If a blob is present in the SRAM persistent data because it has been
     *     stashed there by runtime provisioning comms handling. This could be
     *     for DM LCS provisioning and therefore we check this before the LCS
     *     state
     *  2. A blob pre-loaded into the SRAM standard staging area
     *  3. A blob passed over the provisioning comms, which will be stashed
     *     in the standard staging area
     */
    if (found_persistent_data_message) {
        provisioning_message = persistent_data_message;
        provisioning_message_size = *persistent_data_message_size;
#ifdef RSE_BOOT_IN_DM_LCS
    } else if (lcs == LCM_LCS_DM) {
        return TFM_PLAT_ERR_SUCCESS;
#endif
    } else if (!found_valid_message_type(provisioning_message)) {
        err = provisioning_comms_init(provisioning_message, provisioning_message_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        err = provisioning_comms_receive_commands_blocking();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    /* FixMe: Check if the current way of handling blobs can result in running
     *        a malformed blob in case a reset happens in the middle of an
     *        operation which has already written the blob header
     */
    err = handle_provisioning_message(provisioning_message, provisioning_message_size, &config,
                                      (void *)&ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, provisioning_message_size);
        blob_handling_status_report_error(PROVISIONING_REPORT_STEP_RUN_BLOB, err);
        return err;
    }

    /*
     * If we have provisioned the persistent data message, set persistent data pointer to
     * NULL to prevent us trying to run the blob again if the blob does not change the LCS
     */
    if (found_persistent_data_message) {
        persistent_data_message = NULL;
        *persistent_data_message_size = 0;
    }

    tfm_hal_system_reset();

    return TFM_PLAT_ERR_SUCCESS;
}

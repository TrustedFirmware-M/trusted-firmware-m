/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "runtime_provisioning_hal.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_plain_data_handler.h"
#include "rse_provisioning_comms.h"
#include "rse_provisioning_rotpk.h"
#include "rse_provisioning_message.h"
#include "rse_provisioning_message_status.h"
#include "rse_persistent_data.h"
#include "tfm_hal_platform.h"
#include "region_defs.h"
#include "lcm_drv.h"
#include "device_definition.h"

/* 3KiB buffer to store provisioned blob, will be passed to
 * BL1_1 via persistent data */
static uint32_t *blob_buffer = (uint32_t *)RUNTIME_PROVISIONING_MESSAGE_START;
static size_t blob_buffer_size = RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE;

enum runtime_provisioning_error_t runtime_provisioning_hal_init(void)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
    bool valid_state = false;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

#if defined(RSE_NON_ENDORSED_DM_PROVISIONING) || defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
    valid_state = valid_state || (lcs == LCM_LCS_SE);
#endif

#ifdef RSE_BOOT_IN_DM_LCS
    valid_state = valid_state || (lcs == LCM_LCS_DM);
#endif

    if (!valid_state) {
        return RUNTIME_PROVISIONING_INVALID_STATE;
    }

    RSE_PERSISTENT_DATA->bl1_data.provisioning_blob_buf = blob_buffer;
    RSE_PERSISTENT_DATA->bl1_data.provisioning_blob_buf_size = blob_buffer_size;

    err = provisioning_comms_init((struct rse_provisioning_message_t *)blob_buffer,
                                  blob_buffer_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

    err = provisioning_comms_signal_ready_non_blocking();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

    return RUNTIME_PROVISIONING_SUCCESS;
}

#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
static enum tfm_plat_err_t handle_plain_data_message(struct rse_provisioning_message_t *message)
{
    enum tfm_plat_err_t err;
    struct default_plain_data_handler_ctx_s ctx;
    struct provisioning_message_handler_config config = {
        .plain_data_handler = default_plain_data_handler,
    };

    err = handle_provisioning_message(message, blob_buffer_size, &config, &ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_PARSE_PLAIN_DATA, err);
    }

    return err;
}
#endif

#if defined(RSE_BOOT_IN_DM_LCS) || defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
static enum tfm_plat_err_t handle_blob_message(void)
{
    /* Reset and let BL1_1 provision the blob */
    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
    __builtin_unreachable();
    return TFM_PLAT_ERR_SUCCESS;
}
#endif

static enum tfm_plat_err_t handle_full_message(void)
{
    struct rse_provisioning_message_t *message = (struct rse_provisioning_message_t *)blob_buffer;

    switch (message->header.type) {
#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
    case RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA:
        return handle_plain_data_message(message);
#endif
#if defined(RSE_BOOT_IN_DM_LCS) || defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
    case RSE_PROVISIONING_MESSAGE_TYPE_BLOB:
        return handle_blob_message();
#endif
    default:
        return TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_TYPE;
    }
}

enum runtime_provisioning_error_t runtime_provisioning_hal_process_message(void)
{
    enum tfm_plat_err_t err;
    bool received_full_message;

    err = provisioning_comms_receive_command_non_blocking(&received_full_message);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_NO_INTERRUPT;
    }

    if (received_full_message) {
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_RUNTIME_MESSAGE);
        err = handle_full_message();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return RUNTIME_PROVISIONING_GENERIC_ERROR;
        }
    }

    return RUNTIME_PROVISIONING_SUCCESS;
}

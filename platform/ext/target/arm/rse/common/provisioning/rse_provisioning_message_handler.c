/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"

#include "fatal_error.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_message.h"
#include "rse_provisioning_comms.h"
#include "rse_persistent_data.h"
#include "rse_provisioning_message_status.h"

enum tfm_plat_err_t
message_handling_status_report_continue(enum provisioning_message_report_step_t step)
{
#ifdef RSE_ENABLE_DCSU_PROVISIONING_COMMS
    struct provisioning_message_status_report_t status_report = {
        .type = PROVISIONING_STATUS_SUCCESS_CONTINUE,
        .report_step = step,
        .error_code = 0,
    };

    return provisioning_comms_send_status_blocking((uint32_t *)&status_report,
                                                   sizeof(status_report));
#else
    return TFM_PLAT_ERR_SUCCESS;
#endif /* RSE_ENABLE_DCSU_PROVISIONING_COMMS */
}

enum tfm_plat_err_t
message_handling_status_report_error(enum provisioning_message_report_step_t step, uint32_t error)
{
#ifdef RSE_ENABLE_DCSU_PROVISIONING_COMMS
    struct provisioning_message_status_report_t status_report = {
        .type = PROVISIONING_STATUS_ERROR,
        .report_step = step,
        .error_code = error,
    };

    return provisioning_comms_send_status_blocking((uint32_t *)&status_report,
                                                   sizeof(status_report));
#else
    return TFM_PLAT_ERR_SUCCESS;
#endif /* RSE_ENABLE_DCSU_PROVISIONING_COMMS */
}

enum tfm_plat_err_t message_provisioning_finished(enum provisioning_message_report_step_t step)
{
    rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);

#ifdef RSE_ENABLE_DCSU_PROVISIONING_COMMS
    struct provisioning_message_status_report_t status_report = {
        .type = PROVISIONING_STATUS_SUCCESS_COMPLETE,
        .report_step = step,
        .error_code = 0,
    };

    return provisioning_comms_send_status_blocking((uint32_t *)&status_report,
                                                   sizeof(status_report));
#else
    return TFM_PLAT_ERR_SUCCESS;
#endif /* RSE_ENABLE_DCSU_PROVISIONING_COMMS */
}

enum tfm_plat_err_t handle_provisioning_message(const struct rse_provisioning_message_t *msg,
                                                size_t msg_size,
                                                struct provisioning_message_handler_config *config,
                                                void *ctx)
{
    if (msg_size < sizeof(msg->header) ||
        msg->header.data_length > msg_size - sizeof(msg->header)) {
        return TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_SIZE;
    }

    switch (msg->header.type) {
    case RSE_PROVISIONING_MESSAGE_TYPE_BLOB:
        if (config->blob_handler == NULL) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_BLOB_HANDLER);
            return TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_BLOB_HANDLER;
        }
        return config->blob_handler(&msg->blob, msg->header.data_length, ctx);
    case RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA:
        if (config->plain_data_handler == NULL) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_PLAIN_DATA_HANDLER);
            return TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_PLAIN_DATA_HANDLER;
        }
        return config->plain_data_handler(&msg->plain, msg->header.data_length, ctx);
    case RSE_PROVISIONING_MESSAGE_TYPE_CERTIFICATE:
        if (config->cert_handler == NULL) {
            FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_CERT_HANDLER);
            return TFM_PLAT_ERR_PROVISIONING_MESSAGE_NO_CERT_HANDLER;
        }
        return config->cert_handler(&msg->cert, msg->header.data_length, ctx);
    default:
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_TYPE);
        return TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_TYPE;
    }
}

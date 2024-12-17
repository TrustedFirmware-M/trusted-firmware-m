/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_provisioning_comms.h"

#include "fatal_error.h"
#include "device_definition.h"

enum tfm_plat_err_t provisioning_comms_receive(const struct rse_provisioning_message_t *msg,
                                               size_t msg_len, size_t *msg_size)
{
    enum dcsu_error_t err;

    if (msg_len < sizeof(*msg)) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL);
        return TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL;
    }

    err = dcsu_init(&DCSU_DEV_S, (uint8_t *)msg, msg_len, NULL);
    if (err != DCSU_ERROR_NONE) {
        return (enum tfm_plat_err_t)err;
    }

    while (dcsu_wait_for_rx_command(&DCSU_DEV_S, DCSU_RX_COMMAND_COMMIT_WRITE)
           != DCSU_ERROR_NONE) {
        err = dcsu_handle_rx_command(&DCSU_DEV_S);
        if (err != DCSU_ERROR_NONE) {
            return (enum tfm_plat_err_t)err;
        }
    }

    *msg_size = DCSU_DEV_S.rx_buf_offset;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum dcsu_rx_msg_error_t plat_err_to_rx_error(uint32_t err)
{
    switch(err) {
    case TFM_PLAT_ERR_SUCCESS:
        return DCSU_RX_MSG_ERROR_SUCCESS;
    case LCM_ERROR_OTP_WRITE_INVALID_WRITE:
        return DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN;
    case LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL:
        return DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED;
    default:
        return DCSU_RX_MSG_ERROR_GENERIC_ERROR;
    }
}

enum tfm_plat_err_t provisioning_comms_return_status(enum tfm_plat_err_t status)
{
    return (enum tfm_plat_err_t)dcsu_respond_to_rx_command(&DCSU_DEV_S,
                                                           DCSU_RX_COMMAND_COMMIT_WRITE,
                                                           plat_err_to_rx_error(status));
}

enum tfm_plat_err_t provisioning_comms_send(const struct rse_provisioning_message_t *msg,
                                            size_t msg_size)
{
    return (enum tfm_plat_err_t)dcsu_send_data(&DCSU_DEV_S, (uint8_t *)msg, msg_size);
}

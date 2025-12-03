/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "rse_provisioning_comms.h"

#include "dcsu_drv.h"
#include "fatal_error.h"
#include "device_definition.h"

#include "tfm_log.h"

enum tfm_plat_err_t provisioning_comms_init(const struct rse_provisioning_message_t *msg,
                                            size_t msg_len)
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

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_signal_ready_non_blocking(void)
{
    INFO("Signal DCSU ready\n");
    dcsu_import_ready_non_blocking(&DCSU_DEV_S);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_receive_command_non_blocking(enum rx_command_type_handled *rx_command_type)
{
    enum dcsu_error_t err;
    bool tx_pending, rx_pending;
    enum dcsu_rx_command rx_command;

    *rx_command_type = RX_COMMAND_TYPE_HANDLED_NONE;

    tx_pending = dcsu_poll_for_tx_response(&DCSU_DEV_S) == DCSU_ERROR_NONE;
    if (tx_pending) {
        err = dcsu_handle_tx_response(&DCSU_DEV_S);
        if (err != DCSU_ERROR_NONE) {
            return (enum tfm_plat_err_t)err;
        }
    }

    /*
     * The host could have sent a TX response and a fresh RX message by the time
     * we get around to processing the interrupt. So we handle both in this function
     */
    rx_pending = dcsu_poll_for_any_rx_command(&DCSU_DEV_S) == DCSU_ERROR_NONE;
    if (rx_pending) {
        err = dcsu_handle_rx_command(&DCSU_DEV_S, &rx_command);
        if (err != DCSU_ERROR_NONE) {
            return (enum tfm_plat_err_t)err;
        }

        /* Command-specific steps */
        switch (rx_command) {
            case DCSU_RX_COMMAND_IMPORT_DATA_NO_CHECKSUM:
            case DCSU_RX_COMMAND_IMPORT_DATA_CHECKSUM:
                *rx_command_type = RX_COMMAND_TYPE_HANDLED_DATA;
                break;
            case DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA:
                *rx_command_type = RX_COMMAND_TYPE_HANDLED_DATA_COMPLETE;
                break;
            case DCSU_RX_COMMAND_SET_PS_FC:
            case DCSU_RX_COMMAND_SET_FEATURE_CTRL:
            case DCSU_RX_COMMAND_SET_SE_DEV:
                *rx_command_type = RX_COMMAND_TYPE_HANDLED_SINGLE_CMD_REQUIRES_RESET;
                break;
            default:
                *rx_command_type = RX_COMMAND_TYPE_HANDLED_SINGLE_CMD;
                break;
        }
    }

    return (tx_pending || rx_pending) ? TFM_PLAT_ERR_SUCCESS :
                                        (enum tfm_plat_err_t)DCSU_ERROR_POLL_NO_COMMAND_PENDING;
}

enum tfm_plat_err_t provisioning_comms_receive_commands_blocking(void)
{
    enum dcsu_error_t err;
    bool got_complete = false;
    enum dcsu_rx_command command;

    INFO("Signal DCSU ready\n");
    dcsu_import_ready(&DCSU_DEV_S);

    while (!got_complete) {
        if (dcsu_wait_for_rx_command(&DCSU_DEV_S, DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA) ==
            DCSU_ERROR_NONE) {
                got_complete = true;
        }

        err = dcsu_handle_rx_command(&DCSU_DEV_S, &command);
        if (err != DCSU_ERROR_NONE) {
            return (enum tfm_plat_err_t)err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
provisioning_comms_send_msg_blocking(const struct rse_provisioning_message_t *msg, size_t msg_size)
{
    return (enum tfm_plat_err_t)dcsu_send_data(&DCSU_DEV_S, (uint8_t *)msg, msg_size);
}

enum tfm_plat_err_t provisioning_comms_send_status_blocking(uint32_t *msg, size_t msg_size)
{
    return (enum tfm_plat_err_t)dcsu_report_status(&DCSU_DEV_S, msg, msg_size);
}

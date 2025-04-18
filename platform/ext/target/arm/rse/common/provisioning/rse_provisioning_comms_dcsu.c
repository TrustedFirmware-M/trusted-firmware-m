/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_provisioning_comms.h"

#include "dcsu_drv.h"
#include "fatal_error.h"
#include "device_definition.h"

#include "tfm_log.h"

enum tfm_plat_err_t provisioning_comms_receive(const struct rse_provisioning_message_t *msg,
                                               size_t msg_len, size_t *msg_size)
{
    enum dcsu_error_t err;
    bool got_complete = false;

    if (msg_len < sizeof(*msg)) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL);
        return TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL;
    }

    err = dcsu_init(&DCSU_DEV_S, (uint8_t *)msg, msg_len, NULL);
    if (err != DCSU_ERROR_NONE) {
        return (enum tfm_plat_err_t)err;
    }

    INFO("Signal DCSU ready\n");
    dcsu_import_ready(&DCSU_DEV_S);

    while (!got_complete) {
        if (dcsu_wait_for_rx_command(&DCSU_DEV_S, DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA) ==
            DCSU_ERROR_NONE) {
                got_complete = true;
        }

        err = dcsu_handle_rx_command(&DCSU_DEV_S);
        if (err != DCSU_ERROR_NONE) {
            return (enum tfm_plat_err_t)err;
        }
    }

    *msg_size = DCSU_DEV_S.rx_buf_offset;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_send(const struct rse_provisioning_message_t *msg,
                                            size_t msg_size)
{
    return (enum tfm_plat_err_t)dcsu_send_data(&DCSU_DEV_S, (uint8_t *)msg, msg_size);
}

enum tfm_plat_err_t provisioning_comms_send_response(uint32_t *msg,
                                                     size_t msg_size)
{
    return (enum tfm_plat_err_t)dcsu_report_status(&DCSU_DEV_S, msg, msg_size);
}

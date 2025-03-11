/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "rse_provisioning_comms.h"

#include "fatal_error.h"

enum tfm_plat_err_t provisioning_comms_receive(const struct rse_provisioning_message_t *msg,
                                               size_t msg_size, size_t *msg_len)
{
    if (msg_size < sizeof(*msg)) {
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL);
        return TFM_PLAT_ERR_PROVISIONING_COMMS_MSG_BUFFER_TOO_SMALL;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_send(const struct rse_provisioning_message_t *msg,
                                            size_t msg_size)
{
    return TFM_PLAT_ERR_SUCCESS;
}

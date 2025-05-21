/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>

#include "rse_provisioning_message.h"
#include "platform_error_codes.h"
#include "rse_provisioning_comms.h"
#include "rse_provisioning_get_message.h"
#include "rse_provisioning_message_handler.h"

enum tfm_plat_err_t
rse_provisioning_get_message(const struct rse_provisioning_message_t *message_buf,
                             size_t message_buf_size)
{
#ifdef RSE_ENABLE_DCSU_PROVISIONING_COMMS
    enum tfm_plat_err_t err;

    err = provisioning_comms_init(message_buf, message_buf_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = provisioning_comms_receive_commands_blocking();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#else
    if (!rse_provisioning_message_is_valid(message_buf)) {
        return TFM_PLAT_ERR_PROVISIONING_MESSAGE_NOT_FOUND;
    }
#endif /* RSE_ENABLE_DCSU_PROVISIONING_COMMS */

    return TFM_PLAT_ERR_SUCCESS;
}

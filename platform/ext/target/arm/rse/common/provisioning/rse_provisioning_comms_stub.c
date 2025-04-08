/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "rse_provisioning_comms.h"

#include "fatal_error.h"

enum tfm_plat_err_t provisioning_comms_init(const struct rse_provisioning_message_t *msg,
                                            size_t msg_len)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_signal_ready_non_blocking(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_receive_command_non_blocking(bool *full_message)
{
    /* Should not be called for stub implementation as no interrupt */
    *full_message = false;

    return TFM_PLAT_ERR_PROVISIONING_COMMS_UNSUPPORTED;
}

enum tfm_plat_err_t provisioning_comms_receive_commands_blocking(void)
{
    return TFM_PLAT_ERR_PROVISIONING_COMMS_UNSUPPORTED;
}

enum tfm_plat_err_t
provisioning_comms_send_msg_blocking(const struct rse_provisioning_message_t *msg, size_t msg_size)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_comms_send_status_blocking(uint32_t *msg, size_t msg_size)
{
    return TFM_PLAT_ERR_SUCCESS;
}

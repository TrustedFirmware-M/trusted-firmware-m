/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "scmi_common.h"
#include "scmi_protocol.h"
#include "scmi_system_power.h"

scmi_protocol_err_t scmi_message_sys_power_state_notify(
    struct scmi_message_t *msg)
{
    if (msg == NULL) {
        return SCMI_PROTOCOL_INVALID_ARGUMENT;
    }

    msg->header =
        scmi_message_header(SCMI_MESSAGE_ID_SYS_POWER_STATE_NOTIFY,
                            SCMI_MESSAGE_TYPE_COMMAND,
                            SCMI_PROTOCOL_ID_SYS_POWER_STATE,
                            0);

    assert(sizeof(struct scmi_sys_power_state_notify_t) <=
        sizeof(msg->payload));

    (void)memcpy(msg->payload,
        &(struct scmi_sys_power_state_notify_t) {
            .notify_enable = UINT32_C(1),
        },
        sizeof(struct scmi_sys_power_state_notify_t));

    msg->payload_len = sizeof(struct scmi_sys_power_state_notify_t);

    return SCMI_PROTOCOL_SUCCESS;
}

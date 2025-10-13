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

uint32_t scmi_message_header(
    uint8_t message_id,
    uint8_t message_type,
    uint8_t protocol_id,
    uint8_t token)
{
    return (((uint32_t)message_id << SCMI_MESSAGE_HEADER_MESSAGE_ID_POS) &
            SCMI_MESSAGE_HEADER_MESSAGE_ID_MASK) |
           (((uint32_t)message_type << SCMI_MESSAGE_HEADER_MESSAGE_TYPE_POS) &
            SCMI_MESSAGE_HEADER_MESSAGE_TYPE_MASK) |
           (((uint32_t)protocol_id << SCMI_MESSAGE_HEADER_PROTOCOL_ID_POS) &
            SCMI_MESSAGE_HEADER_PROTOCOL_ID_MASK) |
           (((uint32_t)token << SCMI_MESSAGE_HEADER_TOKEN_POS) &
            SCMI_MESSAGE_HEADER_TOKEN_MASK);
}

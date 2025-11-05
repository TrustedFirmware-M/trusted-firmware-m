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
#include "scmi_power_domain.h"

scmi_protocol_err_t scmi_message_power_domain_protocol_version(
    struct scmi_message_t *msg)
{
    if (msg == NULL) {
        return SCMI_PROTOCOL_INVALID_ARGUMENT;
    }

    msg->header =
        scmi_message_header(SCMI_MESSAGE_ID_SYS_POWER_DOMAIN_PROTOCOL_VERSION,
                            SCMI_MESSAGE_TYPE_COMMAND,
                            SCMI_PROTOCOL_ID_POWER_DOMAIN,
                            0);

    msg->payload_len = 0; /* this message has no payload*/

    return SCMI_PROTOCOL_SUCCESS;
}

scmi_protocol_err_t scmi_message_power_domain_protocol_attributes(
    struct scmi_message_t *msg)
{
    (void)msg;
    return SCMI_STATUS_NOT_SUPPORTED;
}

scmi_protocol_err_t scmi_message_power_domain_message_attributes(
    struct scmi_message_t *msg,
    uint32_t message_id)
{
    (void)msg;
    (void)message_id;

    return SCMI_STATUS_NOT_SUPPORTED;
}

scmi_protocol_err_t scmi_message_power_domain_attributes(
    struct scmi_message_t *msg,
    uint32_t domain_id)
{
    if (msg == NULL) {
        return SCMI_PROTOCOL_INVALID_ARGUMENT;
    }

    msg->header =
        scmi_message_header(SCMI_MESSAGE_ID_PD_POWER_DOMAIN_ATTRIBUTES,
                            SCMI_MESSAGE_TYPE_COMMAND,
                            SCMI_PROTOCOL_ID_POWER_DOMAIN,
                            0);

    assert(sizeof(struct scmi_pd_power_domain_attributes_t)
        <= sizeof(msg->payload));

    (void)memcpy(msg->payload,
           &(struct scmi_pd_power_domain_attributes_t) {
                .domain_id = domain_id},
           sizeof(struct scmi_pd_power_domain_attributes_t));

    msg->payload_len = sizeof(struct scmi_pd_power_domain_attributes_t);

    return SCMI_PROTOCOL_SUCCESS;
}

scmi_protocol_err_t scmi_message_power_domain_state_set(
    struct scmi_message_t *msg,
    uint32_t flags,
    uint32_t domain_id,
    uint32_t pd_state)
{
    if (msg == NULL) {
        return SCMI_PROTOCOL_INVALID_ARGUMENT;
    }

    msg->header =
        scmi_message_header(SCMI_MESSAGE_ID_PD_POWER_STATE_SET,
                            SCMI_MESSAGE_TYPE_COMMAND,
                            SCMI_PROTOCOL_ID_POWER_DOMAIN,
                            0);

    assert(sizeof(struct scmi_pd_power_state_set_t) <= sizeof(msg->payload));

    (void)memcpy(msg->payload,
           &(struct scmi_pd_power_state_set_t) {
                .flags = flags,
                .domain_id = domain_id,
                .power_state = pd_state},
           sizeof(struct scmi_pd_power_state_set_t));

    msg->payload_len = sizeof(struct scmi_pd_power_state_set_t);

    return SCMI_PROTOCOL_SUCCESS;
}

scmi_protocol_err_t scmi_message_power_domain_state_get(
    struct scmi_message_t *msg,
    uint32_t domain_id)
{
    if (msg == NULL) {
        return SCMI_PROTOCOL_INVALID_ARGUMENT;
    }

    msg->header =
        scmi_message_header(SCMI_MESSAGE_ID_PD_POWER_STATE_GET,
                            SCMI_MESSAGE_TYPE_COMMAND,
                            SCMI_PROTOCOL_ID_POWER_DOMAIN,
                            0);

    assert(sizeof(struct scmi_pd_power_state_get_t)
        <= sizeof(msg->payload));

    (void)memcpy(msg->payload,
           &(struct scmi_pd_power_state_get_t) {
                .domain_id = domain_id},
           sizeof(struct scmi_pd_power_state_get_t));

    msg->payload_len = sizeof(struct scmi_pd_power_state_get_t);

    return SCMI_PROTOCOL_SUCCESS;
}

scmi_protocol_err_t scmi_message_power_domain_state_notify(
    struct scmi_message_t *msg,
    uint32_t domain_id,
    uint32_t notify_enable)
{
    (void)msg;
    (void)domain_id;
    (void)notify_enable;

    return SCMI_PROTOCOL_NOT_SUPPORTED;
}

scmi_protocol_err_t scmi_message_power_domain_state_change_requested_notify(
    struct scmi_message_t *msg,
    uint32_t domain_id,
    uint32_t notify_enable)
{
    (void)msg;
    (void)domain_id;
    (void)notify_enable;

    return SCMI_PROTOCOL_NOT_SUPPORTED;
}

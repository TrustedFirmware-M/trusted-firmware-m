/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "sfcp.h"
#include "sfcp_encryption.h"
#include "sfcp_link_hal.h"
#include "sfcp_platform.h"
#include "sfcp_helpers.h"
#include "sfcp_encryption_hal.h"

#define SFCP_SEND_IVS_MSG_SIZE(_num_ivs)                                \
    (sizeof(struct sfcp_handshake_send_ivs_msg_payload_t) -             \
     sizeof(((struct sfcp_handshake_send_ivs_msg_payload_t *)0)->ivs) + \
     ((_num_ivs) * sizeof(((struct sfcp_handshake_send_ivs_msg_payload_t *)0)->ivs[0])))

/* Definitions for transfer to and from other nodes */
enum sfcp_handshake_msg_type_t {
    /* Session key generation */
    SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG = 0x1010,
    SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG = 0x1020,
    SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG = 0x1030,

    /* Re-keying */
    SFCP_HANDSHAKE_PAYLOAD_CLIENT_RE_KEY_REQUEST_MSG = 0x2010,
    SFCP_HANDSHAKE_PAYLOAD_SERVER_RE_KEY_SEND_IVS_MSG = 0x2030,

    /* Mutual authentication */
    SFCP_HANDSHAKE_PAYLOAD_CLIENT_AUTH_MSG = 0x3010,

    SFCP_HANDSHAKE_PAYLOAD_TYPE_PAD = UINT16_MAX
};

/* Session key generation */
__PACKED_STRUCT sfcp_handshake_msg_header_t {
    enum sfcp_handshake_msg_type_t type;
    uint8_t trusted_subnet_id;
};

__PACKED_STRUCT sfcp_handshake_request_msg_payload_t {
    struct sfcp_handshake_msg_header_t header;
    /* Pad to 4 byte alignment */
    uint8_t __reserved[1];
};

__PACKED_STRUCT sfcp_handshake_get_iv_msg_payload_t {
    struct sfcp_handshake_msg_header_t header;
    /* Pad to 4 byte alignment */
    uint8_t __reserved[1];
};

__PACKED_STRUCT sfcp_handshake_get_iv_reply_payload_t {
    uint8_t iv[32];
};

__PACKED_STRUCT sfcp_handshake_send_ivs_msg_payload_t {
    struct sfcp_handshake_msg_header_t header;
    uint8_t iv_amount;
    uint8_t ivs[SFCP_NUMBER_NODES][32];
};

__PACKED_STRUCT sfcp_handshake_auth_msg_payload_t {
    struct sfcp_handshake_msg_header_t header;
    /* Pad to 4 byte alignment */
    uint8_t __reserved[1];
};

/* Definitions for internal tracking of handshake state */
struct sfcp_handshake_data_t {
    uint8_t send_message_id[SFCP_NUMBER_NODES];
    bool received_node_replies[SFCP_NUMBER_NODES];
    __ALIGNED(4) uint8_t node_ivs[SFCP_NUMBER_NODES][32];
};

static struct sfcp_handshake_data_t handshake_data[SFCP_MAX_TRUSTED_SUBNET_ID];

static __ALIGNED(4) uint8_t sfcp_packet_buffer[SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(false, false) +
                                               sizeof(struct sfcp_handshake_send_ivs_msg_payload_t)];

static __ALIGNED(4) uint8_t sfcp_poll_buffer[SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(false, false) +
                                             sizeof(struct sfcp_handshake_send_ivs_msg_payload_t)];

static inline bool
server_waiting_on_reply_from_node(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                  sfcp_node_id_t node_id)
{
    return !handshake_data[trusted_subnet->id].received_node_replies[node_id];
}

static inline bool server_received_all_replies(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                               sfcp_node_id_t my_node_id)
{
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t trusted_subnet_node = trusted_subnet->nodes[i].id;

        if (trusted_subnet_node == my_node_id) {
            continue;
        }

        if (server_waiting_on_reply_from_node(trusted_subnet, trusted_subnet_node)) {
            return false;
        }
    }

    return true;
}

static inline bool is_message_id_valid_for_subnet(uint8_t trusted_subnet_id,
                                                  sfcp_node_id_t remote_node, uint8_t message_id)
{
    return handshake_data[trusted_subnet_id].send_message_id[remote_node] == message_id;
}

static enum sfcp_error_t construct_send_handshake_msg(sfcp_node_id_t receiver_node,
                                                      uint8_t trusted_subnet_id, uint8_t *payload,
                                                      size_t payload_size,
                                                      struct sfcp_reply_metadata_t *metadata)
{
    enum sfcp_error_t sfcp_err;
    uint8_t *handshake_payload;
    size_t handshake_payload_len;
    struct sfcp_packet_t *msg;
    size_t msg_size;

    sfcp_err = sfcp_init_msg(sfcp_packet_buffer, sizeof(sfcp_packet_buffer), receiver_node, 0, 0,
                             true, false, 0, &handshake_payload, &handshake_payload_len, &msg,
                             &msg_size, metadata);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (handshake_payload_len < payload_size) {
        return SFCP_ERROR_BUFFER_TOO_SMALL;
    }

    if (payload_size > 0) {
        memcpy(handshake_payload, payload, payload_size);
    }

    handshake_data[trusted_subnet_id].send_message_id[receiver_node] = metadata->message_id;

    return sfcp_send_msg(msg, msg_size, payload_size);
}

static enum sfcp_error_t construct_send_reply(bool encrypt,
                                              struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                              sfcp_node_id_t sender_node, uint8_t message_id,
                                              uint8_t *payload, size_t payload_size)
{
    enum sfcp_error_t sfcp_err;
    size_t handshake_payload_len;
    struct sfcp_packet_t *reply;
    uint8_t *handshake_payload;
    size_t reply_size;
    struct sfcp_msg_metadata_t metadata = { .sender = sender_node,
                                            .uses_cryptography = encrypt,
                                            .trusted_subnet_id = trusted_subnet->id,
                                            .client_id = 0,
                                            .application_id = 0,
                                            .message_id = message_id };

    sfcp_err = sfcp_init_reply(sfcp_packet_buffer, sizeof(sfcp_packet_buffer), metadata,
                               &handshake_payload, &handshake_payload_len, &reply, &reply_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (handshake_payload_len < payload_size) {
        return SFCP_ERROR_BUFFER_TOO_SMALL;
    }

    if (payload_size > 0) {
        memcpy(handshake_payload, payload, payload_size);
    }

    return sfcp_send_reply(reply, reply_size, payload_size);
}

static enum sfcp_error_t
setup_session_key_initiator_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                   sfcp_node_id_t my_node_id)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_reply_metadata_t reply_metadata;
    struct sfcp_handshake_get_iv_msg_payload_t get_iv_msg_payload;

    get_iv_msg_payload.header.type = SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG;
    get_iv_msg_payload.header.trusted_subnet_id = trusted_subnet->id;

    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t remote_node_id = trusted_subnet->nodes[i].id;

        if (remote_node_id == my_node_id) {
            continue;
        }

        handshake_data[trusted_subnet->id].received_node_replies[remote_node_id] = false;

        sfcp_err = construct_send_handshake_msg(remote_node_id, trusted_subnet->id,
                                                (uint8_t *)&get_iv_msg_payload,
                                                sizeof(get_iv_msg_payload), &reply_metadata);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG);
}

static enum sfcp_error_t
re_key_initiator_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                        sfcp_node_id_t my_node_id)
{
    enum sfcp_error_t sfcp_err;
    __ALIGNED(4) uint8_t send_ivs_buf[SFCP_SEND_IVS_MSG_SIZE(1)];
    struct sfcp_handshake_send_ivs_msg_payload_t *send_ivs_msg =
        (struct sfcp_handshake_send_ivs_msg_payload_t *)send_ivs_buf;

    /* Generate IV for server */
    sfcp_err = sfcp_encryption_hal_generate_random(
        handshake_data[trusted_subnet->id].node_ivs[my_node_id],
        sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    memcpy(send_ivs_msg->ivs[0], handshake_data[trusted_subnet->id].node_ivs[my_node_id],
           sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));

    send_ivs_msg->header.type = SFCP_HANDSHAKE_PAYLOAD_SERVER_RE_KEY_SEND_IVS_MSG;
    send_ivs_msg->header.trusted_subnet_id = trusted_subnet->id;
    send_ivs_msg->iv_amount = 1;

    /* Send a 'send IVs' message to the other nodes with only a single generated IV */
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        struct sfcp_reply_metadata_t reply_metadata;
        sfcp_node_id_t node;

        node = trusted_subnet->nodes[i].id;

        if (node == my_node_id) {
            continue;
        }

        handshake_data[trusted_subnet->id].received_node_replies[node] = false;

        sfcp_err = construct_send_handshake_msg(node, trusted_subnet->id, (uint8_t *)send_ivs_msg,
                                                sizeof(send_ivs_buf), &reply_metadata);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    return sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                         SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SEND_SEND_IVS_MSG);
}

static enum sfcp_error_t
encryption_handshake_initiator_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                      sfcp_node_id_t my_node_id, bool re_keying)
{
    if (!re_keying) {
        return setup_session_key_initiator_server(trusted_subnet, my_node_id);
    } else {
        return re_key_initiator_server(trusted_subnet, my_node_id);
    }
}

static enum sfcp_error_t
encryption_handshake_initiator_client(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                      sfcp_node_id_t server_node_id, bool re_keying)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_reply_metadata_t reply_metadata;
    struct sfcp_handshake_request_msg_payload_t request_msg_payload;
    enum sfcp_trusted_subnet_state_t new_state;

    if (!re_keying) {
        request_msg_payload.header.type = SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG;
        new_state = SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST;
    } else {
        request_msg_payload.header.type = SFCP_HANDSHAKE_PAYLOAD_CLIENT_RE_KEY_REQUEST_MSG;
        new_state = SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST;
    }

    request_msg_payload.header.trusted_subnet_id = trusted_subnet->id;

    sfcp_err = construct_send_handshake_msg(server_node_id, trusted_subnet->id,
                                            (uint8_t *)&request_msg_payload,
                                            sizeof(request_msg_payload), &reply_metadata);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return sfcp_trusted_subnet_set_state(trusted_subnet->id, new_state);
}

static enum sfcp_error_t message_poll_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                             sfcp_node_id_t my_node_id)
{
    enum sfcp_error_t sfcp_err;
    uint16_t client_id;
    uint8_t *payload;
    size_t payload_len;
    struct sfcp_msg_metadata_t metadata;

    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t remote_node_id = trusted_subnet->nodes[i].id;

        if (remote_node_id == my_node_id) {
            continue;
        }

        if (!server_waiting_on_reply_from_node(trusted_subnet, remote_node_id)) {
            continue;
        }

        sfcp_err = sfcp_receive_msg(sfcp_poll_buffer, sizeof(sfcp_poll_buffer), false,
                                    remote_node_id, 0, &client_id, &payload, &payload_len,
                                    &metadata);
        /* We should not receive an actual message back as we are only getting handshake
         * messages */
        if (sfcp_err == SFCP_ERROR_SUCCESS) {
            return SFCP_ERROR_INVALID_MSG;
        } else if (sfcp_err != SFCP_ERROR_NO_MSG_AVAILABLE) {
            return sfcp_err;
        }
    }

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t message_poll_client(sfcp_node_id_t server_node_id)
{
    enum sfcp_error_t sfcp_err;
    uint16_t client_id;
    uint8_t *payload;
    size_t payload_len;
    struct sfcp_msg_metadata_t metadata;

    sfcp_err = sfcp_receive_msg(sfcp_poll_buffer, sizeof(sfcp_poll_buffer), false, server_node_id,
                                0, &client_id, &payload, &payload_len, &metadata);
    /* We should not receive an actual message back as we are only getting handshake
     * messages */
    if (sfcp_err == SFCP_ERROR_SUCCESS) {
        return SFCP_ERROR_INVALID_MSG;
    } else if (sfcp_err != SFCP_ERROR_NO_MSG_AVAILABLE) {
        return sfcp_err;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_trusted_subnet_state_requires_handshake_encryption(uint8_t trusted_subnet_id,
                                                                          bool *requires_handshake,
                                                                          bool *requires_encryption)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet_id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    /* Key setup required but need to encrypt message after handshake performed */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED:
        *requires_handshake = true;
        *requires_encryption = true;
        return SFCP_ERROR_SUCCESS;

    /* Currently performing handshake which does not require encryption */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_SERVER_GET_REQUEST:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_REPLY:
        *requires_handshake = false;
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    /* Key setup complete and need to encrypt all messages */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID:
        *requires_handshake = false;
        *requires_encryption = true;
        return SFCP_ERROR_SUCCESS;

    /* Re-keying required */
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED:
        *requires_handshake = true;
        *requires_encryption = true;
        return SFCP_ERROR_SUCCESS;

    /* Re-keying messages all require encryption */
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_INITIATOR_STARTED:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SEND_SEND_IVS_MSG:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_SEND_IVS_MSG:
        *requires_handshake = false;
        *requires_encryption = true;
        return SFCP_ERROR_SUCCESS;

    /* Subnet does not require encryption */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED:
        *requires_handshake = false;
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    /* Mutual authentication required, message after handshake performed
     * does not need to be encrypted
     */
    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_REQUIRED:
        *requires_handshake = true;
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    /* Mutual authentication completed so do not require encryption */
    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_COMPLETED:
        *requires_handshake = false;
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }
}

enum sfcp_error_t sfcp_encryption_handshake_initiator(uint8_t trusted_subnet_id, bool block)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_hal_error_t hal_err;
    struct sfcp_trusted_subnet_config_t *trusted_subnet;
    sfcp_node_id_t my_node_id;
    sfcp_node_id_t server_node_id;
    enum sfcp_trusted_subnet_state_t state;
    enum sfcp_trusted_subnet_state_t new_state;
    bool re_keying;
    uint32_t disable_irq_cookie;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet_id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    /* Mutual auth requires the same initial setup as session key */
    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_REQUIRED:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED:
        re_keying = false;
        new_state = SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED;
        break;
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED:
        re_keying = true;
        new_state = SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_INITIATOR_STARTED;
        break;
    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }

    sfcp_err = sfcp_get_trusted_subnet_by_id(trusted_subnet_id, &trusted_subnet);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    hal_err = sfcp_hal_get_my_node_id(&my_node_id);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        return sfcp_hal_error_to_sfcp_error(hal_err);
    }

    sfcp_err = sfcp_trusted_subnet_get_server(trusted_subnet, &server_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id, new_state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (server_node_id == my_node_id) {
        sfcp_err = encryption_handshake_initiator_server(trusted_subnet, my_node_id, re_keying);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    } else {
        sfcp_err = encryption_handshake_initiator_client(trusted_subnet, server_node_id, re_keying);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    if (!block) {
        return SFCP_ERROR_SUCCESS;
    }

    /* The following is synchronous and therefore we do not want the interrupt handler
     * running when we receive a message
     */
    disable_irq_cookie = sfcp_encryption_hal_save_disable_irq();

    /* Continuously poll for messages and check if the handshake is complete.
     * The receive_msg function will check if messages have been received and then
     * respond if required
     */
    while (1) {
        sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet_id, &state);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            goto out;
        }

        if ((state == SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID) ||
            (state == SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_COMPLETED)) {
            break;
        }

        if (server_node_id == my_node_id) {
            sfcp_err = message_poll_server(trusted_subnet, my_node_id);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                goto out;
            }
        } else {
            sfcp_err = message_poll_client(server_node_id);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                goto out;
            }
        }
    }

out:
    sfcp_encryption_hal_enable_irq(disable_irq_cookie);
    return sfcp_err;
}

static enum sfcp_error_t handle_client_request(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                               bool encrypt, sfcp_node_id_t my_node_id,
                                               const uint8_t *payload, size_t payload_size,
                                               sfcp_node_id_t sender_node, uint8_t message_id,
                                               bool re_keying)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t new_state;

    if (!re_keying) {
        new_state = SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST;
    } else {
        new_state = SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST;
    }

    sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id, new_state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = construct_send_reply(encrypt, trusted_subnet, sender_node, message_id, NULL, 0);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return encryption_handshake_initiator_server(trusted_subnet, my_node_id, re_keying);
}

static enum sfcp_error_t handle_get_iv_reply(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                             sfcp_node_id_t my_node_id, const uint8_t *payload,
                                             size_t payload_size, sfcp_node_id_t sender_node,
                                             uint8_t message_id)
{
    /* Static to avoid large stack usage */
    static struct sfcp_handshake_send_ivs_msg_payload_t send_ivs_msg;
    enum sfcp_error_t sfcp_err;
    struct sfcp_handshake_get_iv_reply_payload_t *get_iv_reply;
    size_t send_payload_size;

    get_iv_reply = (struct sfcp_handshake_get_iv_reply_payload_t *)payload;
    memcpy(handshake_data[trusted_subnet->id].node_ivs[sender_node], get_iv_reply->iv,
           sizeof(get_iv_reply->iv));

    handshake_data[trusted_subnet->id].received_node_replies[sender_node] = true;
    if (!server_received_all_replies(trusted_subnet, my_node_id)) {
        /* Still waiting on replies from other nodes */
        return SFCP_ERROR_SUCCESS;
    }

    /* Generate IV for server */
    sfcp_err = sfcp_encryption_hal_generate_random(
        handshake_data[trusted_subnet->id].node_ivs[my_node_id],
        sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    /* Generate payload with all IVs. We do not currently support the Merkle approach */
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t node = trusted_subnet->nodes[i].id;

        memcpy(send_ivs_msg.ivs[i], handshake_data[trusted_subnet->id].node_ivs[node],
               sizeof(send_ivs_msg.ivs[i]));
    }

    send_ivs_msg.header.type = SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG;
    send_ivs_msg.header.trusted_subnet_id = trusted_subnet->id;
    send_ivs_msg.iv_amount = trusted_subnet->node_amount;

    send_payload_size = SFCP_SEND_IVS_MSG_SIZE(trusted_subnet->node_amount);

    /* Send generated payload to all other nodes */
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        struct sfcp_reply_metadata_t reply_metadata;
        sfcp_node_id_t node;

        node = trusted_subnet->nodes[i].id;

        if (node == my_node_id) {
            continue;
        }

        handshake_data[trusted_subnet->id].received_node_replies[node] = false;

        sfcp_err = construct_send_handshake_msg(node, trusted_subnet->id, (uint8_t *)&send_ivs_msg,
                                                send_payload_size, &reply_metadata);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG);
}

static void reset_trusted_subnet_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet)
{
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        struct sfcp_trusted_subnet_node_t *node_config = &trusted_subnet->nodes[i];

        node_config->send_seq_num = 0;
        node_config->recv_seq_num = 0;
    }
}

static enum sfcp_error_t
send_mutual_auth_payload(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                         sfcp_node_id_t remote_node)
{
    struct sfcp_handshake_auth_msg_payload_t auth_msg;
    struct sfcp_reply_metadata_t reply_metadata;

    auth_msg.header.type = SFCP_HANDSHAKE_PAYLOAD_CLIENT_AUTH_MSG;
    auth_msg.header.trusted_subnet_id = trusted_subnet->id;

    return construct_send_handshake_msg(remote_node, trusted_subnet->id, (uint8_t *)&auth_msg,
                                        sizeof(auth_msg), &reply_metadata);
}

static enum sfcp_error_t handle_send_ivs_reply(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                               sfcp_node_id_t my_node_id, const uint8_t *payload,
                                               size_t payload_size, sfcp_node_id_t sender_node,
                                               uint8_t message_id, bool re_keying)
{
    enum sfcp_error_t sfcp_err;
    __ALIGNED(4) uint8_t hash[48];
    size_t hash_size;
    uint32_t output_key;

    handshake_data[trusted_subnet->id].received_node_replies[sender_node] = true;
    if (!server_received_all_replies(trusted_subnet, my_node_id)) {
        /* Still waiting on replies from other nodes */
        return SFCP_ERROR_SUCCESS;
    }

    /* Take hash of all IVs from other nodes */
    sfcp_err = sfcp_encryption_hal_hash_init(SFCP_ENCRYPTION_HAL_HASH_ALG_SHA384);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (!re_keying) {
        /* IV for each node in the system */
        for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
            sfcp_node_id_t node = trusted_subnet->nodes[i].id;

            sfcp_err = sfcp_encryption_hal_hash_update(
                handshake_data[trusted_subnet->id].node_ivs[node],
                sizeof(handshake_data[trusted_subnet->id].node_ivs[node]));
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }
        }
    } else {
        /* Only a single IV generated by the server */
        sfcp_err = sfcp_encryption_hal_hash_update(
            handshake_data[trusted_subnet->id].node_ivs[my_node_id],
            sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    sfcp_err = sfcp_encryption_hal_hash_finish(hash, sizeof(hash), &hash_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (!re_keying) {
        sfcp_err = sfcp_encryption_hal_setup_session_key(hash, hash_size, &output_key);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    } else {
        sfcp_err = sfcp_encryption_hal_rekey_session_key(hash, hash_size, trusted_subnet->key_id,
                                                         &output_key);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        reset_trusted_subnet_seq_num(trusted_subnet);
    }

    trusted_subnet->key_id = output_key;

    sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                             SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (trusted_subnet->type == SFCP_TRUSTED_SUBNET_INITIALLY_UNTRUSTED_LINKS) {
        /* Send mutual authentication request to each node */
        for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
            sfcp_node_id_t node;

            node = trusted_subnet->nodes[i].id;

            if (node == my_node_id) {
                continue;
            }

            handshake_data[trusted_subnet->id].received_node_replies[node] = false;

            sfcp_err = send_mutual_auth_payload(trusted_subnet, node);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }
        }

        sfcp_err = sfcp_trusted_subnet_set_state(
            trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_SENT_AUTH_MSG);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t
handle_client_request_empty_response(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                     sfcp_node_id_t my_node_id, const uint8_t *payload,
                                     size_t payload_size, sfcp_node_id_t sender_node,
                                     uint8_t message_id, enum sfcp_trusted_subnet_state_t new_state)
{
    return sfcp_trusted_subnet_set_state(trusted_subnet->id, new_state);
}

static enum sfcp_error_t handle_get_iv_msg(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                           bool encrypt, sfcp_node_id_t my_node_id,
                                           const uint8_t *payload, size_t payload_size,
                                           sfcp_node_id_t sender_node, uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_handshake_get_iv_reply_payload_t get_iv_reply_payload;

    sfcp_err = sfcp_encryption_hal_generate_random(
        handshake_data[trusted_subnet->id].node_ivs[my_node_id],
        sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    memcpy(get_iv_reply_payload.iv, handshake_data[trusted_subnet->id].node_ivs[my_node_id],
           sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));

    sfcp_err = construct_send_reply(encrypt, trusted_subnet, sender_node, message_id,
                                    (uint8_t *)&get_iv_reply_payload, sizeof(get_iv_reply_payload));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY);
}

static enum sfcp_error_t handle_send_ivs_msg(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                             bool encrypt, sfcp_node_id_t my_node_id,
                                             const uint8_t *payload, size_t payload_size,
                                             sfcp_node_id_t sender_node, uint8_t message_id,
                                             bool re_keying)
{
    enum sfcp_error_t sfcp_err;
    __ALIGNED(4) uint8_t hash[48];
    size_t hash_size;
    struct sfcp_handshake_send_ivs_msg_payload_t *send_ivs_msg;
    bool valid_iv = false;
    uint32_t output_key;

    send_ivs_msg = (struct sfcp_handshake_send_ivs_msg_payload_t *)payload;

    sfcp_err = construct_send_reply(encrypt, trusted_subnet, sender_node, message_id, NULL, 0);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    /* We only need to check that the IV matches what we sent in the initial
     * session key generation flow. In the case of re-keying, we only receive a single
     * IV from the server
     */
    if (!re_keying) {
        if (send_ivs_msg->iv_amount != trusted_subnet->node_amount) {
            return SFCP_ERROR_INVALID_MSG;
        }

        for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
            sfcp_node_id_t node = trusted_subnet->nodes[i].id;

            if (node != my_node_id) {
                continue;
            }

            if (memcmp(send_ivs_msg->ivs[i],
                       handshake_data[trusted_subnet->id].node_ivs[my_node_id],
                       sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id])) != 0) {
                return SFCP_ERROR_HANDSHAKE_INVALID_RECEIVED_IV;
            } else {
                valid_iv = true;
                break;
            }
        }

        if (!valid_iv) {
            return SFCP_ERROR_INVALID_MSG;
        }
    } else {
        if (send_ivs_msg->iv_amount != 1) {
            return SFCP_ERROR_INVALID_MSG;
        }
    }

    sfcp_err = sfcp_encryption_hal_hash_init(SFCP_ENCRYPTION_HAL_HASH_ALG_SHA384);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = sfcp_encryption_hal_hash_update(
        (uint8_t *)send_ivs_msg->ivs, send_ivs_msg->iv_amount * sizeof(send_ivs_msg->ivs[0]));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = sfcp_encryption_hal_hash_finish(hash, sizeof(hash), &hash_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (!re_keying) {
        sfcp_err = sfcp_encryption_hal_setup_session_key(hash, hash_size, &output_key);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    } else {
        sfcp_err = sfcp_encryption_hal_rekey_session_key(hash, hash_size, trusted_subnet->key_id,
                                                         &output_key);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        reset_trusted_subnet_seq_num(trusted_subnet);
    }

    trusted_subnet->key_id = output_key;

    sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                             SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (trusted_subnet->type == SFCP_TRUSTED_SUBNET_INITIALLY_UNTRUSTED_LINKS) {
        sfcp_err = sfcp_trusted_subnet_set_state(
            trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_WAITING_FOR_AUTH_MSG);
    }

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t
set_mutual_auth_completed(struct sfcp_trusted_subnet_config_t *trusted_subnet)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = sfcp_encryption_hal_invalidate_session_key(trusted_subnet->key_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    sfcp_err = sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                             SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_COMPLETED);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    trusted_subnet->type = SFCP_TRUSTED_SUBNET_TRUSTED_LINKS;

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t handle_mutual_auth_msg(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                                sfcp_node_id_t remote_node, uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = construct_send_reply(true, trusted_subnet, remote_node, message_id, NULL, 0);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return set_mutual_auth_completed(trusted_subnet);
}

static enum sfcp_error_t
handle_mutual_auth_reply(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                         sfcp_node_id_t my_node_id, sfcp_node_id_t remote_node)
{
    handshake_data[trusted_subnet->id].received_node_replies[remote_node] = true;
    if (!server_received_all_replies(trusted_subnet, my_node_id)) {
        /* Still waiting on replies from other nodes */
        return SFCP_ERROR_SUCCESS;
    }

    return set_mutual_auth_completed(trusted_subnet);
}

static bool check_receive_message(const uint8_t *payload, size_t payload_size,
                                  uint8_t trusted_subnet_id, size_t expected_size,
                                  enum sfcp_handshake_msg_type_t expected_type)
{
    struct sfcp_handshake_msg_header_t *header;

    if (payload_size < expected_size) {
        return false;
    }

    header = (struct sfcp_handshake_msg_header_t *)payload;

    if ((header->type != expected_type) || (header->trusted_subnet_id != trusted_subnet_id)) {
        return false;
    }

    return true;
}

static bool check_receive_reply(uint8_t trusted_subnet_id, sfcp_node_id_t remote_node,
                                size_t payload_size, size_t expected_size, uint8_t message_id)
{
    if (payload_size != expected_size) {
        return false;
    }

    if (!is_message_id_valid_for_subnet(trusted_subnet_id, remote_node, message_id)) {
        return false;
    }

    return true;
}

static bool
check_packet_mutual_auth_encryption_valid(struct sfcp_packet_t *packet, bool packet_encrypted,
                                          struct sfcp_trusted_subnet_config_t *trusted_subnet)
{
    if (!packet_encrypted) {
        return false;
    }

    if (packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id !=
        trusted_subnet->id) {
        return false;
    }

    return true;
}

static bool
check_packet_re_key_encryption_valid(struct sfcp_packet_t *packet, bool packet_encrypted,
                                     struct sfcp_trusted_subnet_config_t *trusted_subnet)
{
    uint8_t packet_trusted_subnet;
    uint16_t packet_encryption_seq_num;

    if (!packet_encrypted) {
        return false;
    }

    packet_trusted_subnet =
        packet->cryptography_used.cryptography_metadata.config.trusted_subnet_id;
    packet_encryption_seq_num = packet->cryptography_used.cryptography_metadata.config.seq_num;

    if (packet_encryption_seq_num < SFCP_TRUSTED_SUBNET_RE_KEY_SEQ_NUM) {
        return false;
    }

    if (packet_trusted_subnet != trusted_subnet->id) {
        return false;
    }

    return true;
}

/* We handle all the messages with the IRQs locked, to prevent
 * interrupts from other nodes when performing handshake
 */
#define HANDLE_MESSAGE_IRQS_LOCKED(_func, _ret, ...)                          \
    do {                                                                      \
        uint32_t disable_irq_cookie = sfcp_encryption_hal_save_disable_irq(); \
        _ret = _func(__VA_ARGS__);                                            \
        sfcp_encryption_hal_enable_irq(disable_irq_cookie);                   \
    } while (0)

static enum sfcp_error_t msg_process_for_trusted_subnet(
    struct sfcp_packet_t *packet, size_t packet_size, sfcp_node_id_t remote_node,
    sfcp_node_id_t my_node_id, uint8_t message_id, bool packet_encrypted, const uint8_t *payload,
    size_t payload_size, struct sfcp_trusted_subnet_config_t *trusted_subnet,
    bool *valid_for_subnet)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet->id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_COMPLETED:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED:
        goto out_invalid;
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED:
    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST: {
        sfcp_node_id_t server_node;

        if (!check_packet_re_key_encryption_valid(packet, packet_encrypted, trusted_subnet)) {
            goto out_invalid;
        }

        sfcp_err = sfcp_decrypt_msg(packet, packet_size, remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        sfcp_err = sfcp_trusted_subnet_get_server(trusted_subnet, &server_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (server_node == my_node_id) {
            if (check_receive_message(payload, payload_size, trusted_subnet->id,
                                      sizeof(struct sfcp_handshake_request_msg_payload_t),
                                      SFCP_HANDSHAKE_PAYLOAD_CLIENT_RE_KEY_REQUEST_MSG)) {
                HANDLE_MESSAGE_IRQS_LOCKED(handle_client_request, sfcp_err, trusted_subnet,
                                           packet_encrypted, my_node_id, payload, payload_size,
                                           remote_node, message_id, true);
                if (sfcp_err != SFCP_ERROR_SUCCESS) {
                    return sfcp_err;
                }

                break;
            }
        } else {
            if (check_receive_reply(trusted_subnet->id, remote_node, payload_size, 0, message_id)) {
                if (state != SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST) {
                    /* Recieved an empty reply with re-key sequence number
                     * but not in the correct state
                     */
                    return SFCP_ERROR_HANDSHAKE_INVALID_RE_KEY_MSG;
                }

                HANDLE_MESSAGE_IRQS_LOCKED(
                    handle_client_request_empty_response, sfcp_err, trusted_subnet, my_node_id,
                    payload, payload_size, remote_node, message_id,
                    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST_SERVER_REPLY);
                if (sfcp_err != SFCP_ERROR_SUCCESS) {
                    return sfcp_err;
                }

                break;

            } else if (check_receive_message(payload, payload_size, trusted_subnet->id,
                                             SFCP_SEND_IVS_MSG_SIZE(1),
                                             SFCP_HANDSHAKE_PAYLOAD_SERVER_RE_KEY_SEND_IVS_MSG)) {
                HANDLE_MESSAGE_IRQS_LOCKED(handle_send_ivs_msg, sfcp_err, trusted_subnet,
                                           packet_encrypted, my_node_id, payload, payload_size,
                                           remote_node, message_id, true);
                if (sfcp_err != SFCP_ERROR_SUCCESS) {
                    return sfcp_err;
                }

                break;
            }
        }

        /* We received a message with re-key seuquence number but its
         * contents are not valid
         */
        return SFCP_ERROR_HANDSHAKE_INVALID_RE_KEY_MSG;
    }

    /* Mutual auth requires the same initial setup as session key */
    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_REQUIRED:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED: {
        sfcp_node_id_t server_node;

        sfcp_err = sfcp_trusted_subnet_get_server(trusted_subnet, &server_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (server_node == my_node_id) {
            if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                       sizeof(struct sfcp_handshake_request_msg_payload_t),
                                       SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG)) {
                goto out_invalid;
            }

            HANDLE_MESSAGE_IRQS_LOCKED(handle_client_request, sfcp_err, trusted_subnet,
                                       packet_encrypted, my_node_id, payload, payload_size,
                                       remote_node, message_id, false);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }

        } else {
            if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                       sizeof(struct sfcp_handshake_get_iv_msg_payload_t),
                                       SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG)) {
                goto out_invalid;
            }

            HANDLE_MESSAGE_IRQS_LOCKED(handle_get_iv_msg, sfcp_err, trusted_subnet,
                                       packet_encrypted, my_node_id, payload, payload_size,
                                       remote_node, message_id);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }
        }

        break;
    }

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
        if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                   sizeof(struct sfcp_handshake_get_iv_msg_payload_t),
                                   SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG)) {
            goto out_invalid;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_get_iv_msg, sfcp_err, trusted_subnet, packet_encrypted,
                                   my_node_id, payload, payload_size, remote_node, message_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
        if (!check_packet_re_key_encryption_valid(packet, packet_encrypted, trusted_subnet)) {
            goto out_invalid;
        }

        sfcp_err = sfcp_decrypt_msg(packet, packet_size, remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                   SFCP_SEND_IVS_MSG_SIZE(1),
                                   SFCP_HANDSHAKE_PAYLOAD_SERVER_RE_KEY_SEND_IVS_MSG)) {
            /* Received a message with re-key sequence number but its contents
             * are not value */
            return SFCP_ERROR_HANDSHAKE_INVALID_RE_KEY_MSG;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_send_ivs_msg, sfcp_err, trusted_subnet, packet_encrypted,
                                   my_node_id, payload, payload_size, remote_node, message_id,
                                   true);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SEND_SEND_IVS_MSG:
        if (!check_packet_re_key_encryption_valid(packet, packet_encrypted, trusted_subnet)) {
            goto out_invalid;
        }

        sfcp_err = sfcp_decrypt_reply(packet, packet_size, remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (!check_receive_reply(trusted_subnet->id, remote_node, payload_size, 0, message_id)) {
            /* Received a message with re-key sequence number but its contents
             * are not value */
            return SFCP_ERROR_HANDSHAKE_INVALID_RE_KEY_MSG;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_send_ivs_reply, sfcp_err, trusted_subnet, my_node_id,
                                   payload, payload_size, remote_node, message_id, true);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG:
        if (!check_receive_reply(trusted_subnet->id, remote_node, payload_size, 0, message_id)) {
            goto out_invalid;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_send_ivs_reply, sfcp_err, trusted_subnet, my_node_id,
                                   payload, payload_size, remote_node, message_id, false);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST:
        if (!check_receive_reply(trusted_subnet->id, remote_node, payload_size, 0, message_id)) {
            goto out_invalid;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(
            handle_client_request_empty_response, sfcp_err, trusted_subnet, my_node_id, payload,
            payload_size, remote_node, message_id,
            SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY:
        if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                   SFCP_SEND_IVS_MSG_SIZE(trusted_subnet->node_amount),
                                   SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG)) {
            goto out_invalid;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_send_ivs_msg, sfcp_err, trusted_subnet, packet_encrypted,
                                   my_node_id, payload, payload_size, remote_node, message_id,
                                   false);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG:
        if (!check_receive_reply(trusted_subnet->id, remote_node, payload_size,
                                 sizeof(struct sfcp_handshake_get_iv_reply_payload_t),
                                 message_id)) {
            goto out_invalid;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_get_iv_reply, sfcp_err, trusted_subnet, my_node_id,
                                   payload, payload_size, remote_node, message_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_WAITING_FOR_AUTH_MSG:
        if (!check_packet_mutual_auth_encryption_valid(packet, packet_encrypted, trusted_subnet)) {
            goto out_invalid;
        }

        sfcp_err = sfcp_decrypt_reply(packet, packet_size, remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (!check_receive_message(payload, payload_size, trusted_subnet->id,
                                   sizeof(struct sfcp_handshake_auth_msg_payload_t),
                                   SFCP_HANDSHAKE_PAYLOAD_CLIENT_AUTH_MSG)) {
            /* Received message for this trusted subnet but not for this state */
            return SFCP_ERROR_HANDSHAKE_INVALID_MUTUAL_AUTH_MSG;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_mutual_auth_msg, sfcp_err, trusted_subnet, remote_node,
                                   message_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_SENT_AUTH_MSG:
        if (!check_packet_mutual_auth_encryption_valid(packet, packet_encrypted, trusted_subnet)) {
            goto out_invalid;
        }

        sfcp_err = sfcp_decrypt_reply(packet, packet_size, remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (!check_receive_reply(trusted_subnet->id, remote_node, payload_size, 0, message_id)) {
            /* Received message for this trusted subnet but not for this state */
            return SFCP_ERROR_HANDSHAKE_INVALID_MUTUAL_AUTH_MSG;
        }

        HANDLE_MESSAGE_IRQS_LOCKED(handle_mutual_auth_reply, sfcp_err, trusted_subnet, my_node_id,
                                   remote_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        break;

    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }

    *valid_for_subnet = true;
    return SFCP_ERROR_SUCCESS;

out_invalid:
    *valid_for_subnet = false;
    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t msg_process(struct sfcp_packet_t *packet, size_t packet_size,
                                     sfcp_node_id_t remote_node, sfcp_node_id_t my_node_id,
                                     uint8_t message_id, bool packet_encrypted,
                                     const uint8_t *payload, size_t payload_size,
                                     bool *msg_processed)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_trusted_subnet_config_t *configs;
    size_t num_trusted_subnets;

    *msg_processed = false;

    sfcp_platform_get_trusted_subnets(&configs, &num_trusted_subnets);

    for (uint8_t i = 0; i < num_trusted_subnets; i++) {
        sfcp_err = msg_process_for_trusted_subnet(packet, packet_size, remote_node, my_node_id,
                                                  message_id, packet_encrypted, payload,
                                                  payload_size, &configs[i], msg_processed);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (*msg_processed) {
            break;
        }
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_encryption_handshake_responder(struct sfcp_packet_t *packet,
                                                      size_t packet_size,
                                                      sfcp_node_id_t remote_node,
                                                      uint8_t message_id, bool packet_encrypted,
                                                      uint8_t *payload, size_t payload_size,
                                                      bool *is_handshake_msg)
{
    enum sfcp_hal_error_t hal_err;
    enum sfcp_error_t sfcp_err;
    sfcp_node_id_t my_node_id;

    hal_err = sfcp_hal_get_my_node_id(&my_node_id);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        sfcp_err = sfcp_hal_error_to_sfcp_error(hal_err);
        return sfcp_err;
    }

    return msg_process(packet, packet_size, remote_node, my_node_id, message_id, packet_encrypted,
                       payload, payload_size, is_handshake_msg);
}

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
#include "bl1_random.h"
#include "sfcp_helpers.h"
#include "rse_kmu_keys.h"
#include "bl1_crypto.h"
#include "fih.h"

/* Definitions for transfer to and from other nodes */
enum sfcp_handshake_msg_type_t {
    /* Session key generation */
    SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG = 0x1010,
    SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG = 0x1020,
    SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG = 0x1030,
    SFCP_HANDSHAKE_PAYLOAD_TYPE_PAD = UINT16_MAX
};

__PACKED_STRUCT sfcp_handshake_request_msg_payload_t {
    enum sfcp_handshake_msg_type_t type;
    uint8_t trusted_subnet_id;
    /* Pad to 4 byte alignment */
    uint8_t __reserved[1];
};

__PACKED_STRUCT sfcp_handshake_get_iv_msg_payload_t {
    enum sfcp_handshake_msg_type_t type;
    uint8_t trusted_subnet_id;
    /* Pad to 4 byte alignment */
    uint8_t __reserved[1];
};

__PACKED_STRUCT sfcp_handshake_get_iv_reply_payload_t {
    uint8_t iv[32];
};

__PACKED_STRUCT sfcp_handshake_send_ivs_msg_payload_t {
    enum sfcp_handshake_msg_type_t type;
    uint8_t trusted_subnet_id;
    uint8_t iv_amount;
    uint8_t ivs[SFCP_NUMBER_NODES][32];
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

static inline size_t
get_send_ivs_msg_payload_size(struct sfcp_trusted_subnet_config_t *trusted_subnet)
{
    return sizeof(struct sfcp_handshake_send_ivs_msg_payload_t) -
           sizeof(((struct sfcp_handshake_send_ivs_msg_payload_t *)0)->ivs) +
           trusted_subnet->node_amount *
               sizeof(((struct sfcp_handshake_send_ivs_msg_payload_t *)0)->ivs[0]);
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

static enum sfcp_error_t construct_send_reply(sfcp_node_id_t sender_node, uint8_t message_id,
                                              uint8_t *payload, size_t payload_size)
{
    enum sfcp_error_t sfcp_err;
    size_t handshake_payload_len;
    struct sfcp_packet_t *reply;
    uint8_t *handshake_payload;
    size_t reply_size;
    struct sfcp_msg_metadata_t metadata = { .sender = sender_node,
                                            .uses_cryptography = false,
                                            .trusted_subnet_id = 0,
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
derive_session_key_initiator_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                    sfcp_node_id_t my_node_id)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_reply_metadata_t reply_metadata;
    struct sfcp_handshake_get_iv_msg_payload_t get_iv_msg_payload;

    get_iv_msg_payload.type = SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG;
    get_iv_msg_payload.trusted_subnet_id = trusted_subnet->id;

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
derive_session_key_initiator_client(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                    sfcp_node_id_t server_node_id)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_reply_metadata_t reply_metadata;
    struct sfcp_handshake_request_msg_payload_t request_msg_payload;

    request_msg_payload.type = SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG;
    request_msg_payload.trusted_subnet_id = trusted_subnet->id;

    sfcp_err = construct_send_handshake_msg(server_node_id, trusted_subnet->id,
                                            (uint8_t *)&request_msg_payload,
                                            sizeof(request_msg_payload), &reply_metadata);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST);
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

enum sfcp_error_t sfcp_trusted_subnet_state_requires_encryption(uint8_t trusted_subnet_id,
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
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    /* Key setup complete and need to encrypt all messages */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID:
        *requires_encryption = true;
        return SFCP_ERROR_SUCCESS;

    /* Subnet does not require encryption */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED:
        *requires_encryption = false;
        return SFCP_ERROR_SUCCESS;

    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }
}

enum sfcp_error_t sfcp_derive_session_key_initiator(uint8_t trusted_subnet_id, bool block)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_hal_error_t hal_err;
    struct sfcp_trusted_subnet_config_t *trusted_subnet;
    sfcp_node_id_t my_node_id;
    sfcp_node_id_t server_node_id;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet_id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID:
        return SFCP_ERROR_SUCCESS;
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED:
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

    sfcp_err = sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (server_node_id == my_node_id) {
        sfcp_err = derive_session_key_initiator_server(trusted_subnet, my_node_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    } else {
        sfcp_err = derive_session_key_initiator_client(trusted_subnet, server_node_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    if (!block) {
        return SFCP_ERROR_SUCCESS;
    }

    /* Continuously poll for messages and check if the handshake is complete.
     * The receive_msg function will check if messages have been received and then
     * respond if required
     */
    while (1) {
        sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet_id, &state);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (state == SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID) {
            break;
        }

        if (server_node_id == my_node_id) {
            sfcp_err = message_poll_server(trusted_subnet, my_node_id);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }
        } else {
            sfcp_err = message_poll_client(server_node_id);
            if (sfcp_err != SFCP_ERROR_SUCCESS) {
                return sfcp_err;
            }
        }
    }

    return SFCP_ERROR_SUCCESS;
}

static enum sfcp_error_t handle_client_request(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                               sfcp_node_id_t my_node_id, uint8_t *payload,
                                               size_t payload_size, sfcp_node_id_t sender_node,
                                               uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = construct_send_reply(sender_node, message_id, NULL, 0);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return derive_session_key_initiator_server(trusted_subnet, my_node_id);
}

static enum sfcp_error_t handle_get_iv_reply(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                             sfcp_node_id_t my_node_id, uint8_t *payload,
                                             size_t payload_size, sfcp_node_id_t sender_node,
                                             uint8_t message_id)
{
    /* Static to avoid large stack usage */
    static struct sfcp_handshake_send_ivs_msg_payload_t send_ivs_msg;
    enum sfcp_error_t sfcp_err;
    struct sfcp_handshake_get_iv_reply_payload_t *get_iv_reply;
    size_t send_payload_size;
    int32_t bl1_random_err;

    get_iv_reply = (struct sfcp_handshake_get_iv_reply_payload_t *)payload;
    memcpy(handshake_data[trusted_subnet->id].node_ivs[sender_node], get_iv_reply->iv,
           sizeof(get_iv_reply->iv));

    handshake_data[trusted_subnet->id].received_node_replies[sender_node] = true;
    if (!server_received_all_replies(trusted_subnet, my_node_id)) {
        /* Still waiting on replies from other nodes */
        return SFCP_ERROR_SUCCESS;
    }

    /* Generate IV for server */
    bl1_random_err =
        bl1_random_generate_secure(handshake_data[trusted_subnet->id].node_ivs[my_node_id],
                                   sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
    if (bl1_random_err != 0) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    /* Generate payload with all IVs. We do not currently support the Merkle approach */
    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t node = trusted_subnet->nodes[i].id;

        memcpy(send_ivs_msg.ivs[i], handshake_data[trusted_subnet->id].node_ivs[node],
               sizeof(send_ivs_msg.ivs[i]));
    }

    send_ivs_msg.type = SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG;
    send_ivs_msg.trusted_subnet_id = trusted_subnet->id;
    send_ivs_msg.iv_amount = trusted_subnet->node_amount;

    send_payload_size = get_send_ivs_msg_payload_size(trusted_subnet);

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

static enum sfcp_error_t handle_send_ivs_reply(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                               sfcp_node_id_t my_node_id, uint8_t *payload,
                                               size_t payload_size, sfcp_node_id_t sender_node,
                                               uint8_t message_id)
{
    fih_int fih_err;
    enum tfm_plat_err_t plat_err;
    __ALIGNED(4) uint8_t hash[48];
    size_t hash_size;

    handshake_data[trusted_subnet->id].received_node_replies[sender_node] = true;
    if (!server_received_all_replies(trusted_subnet, my_node_id)) {
        /* Still waiting on replies from other nodes */
        return SFCP_ERROR_SUCCESS;
    }

    /* Take hash of all IVs from other nodes */
    FIH_CALL(bl1_hash_init, fih_err, TFM_BL1_HASH_ALG_SHA384);
    if (FIH_NOT_EQ(fih_err, FIH_SUCCESS)) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t node = trusted_subnet->nodes[i].id;

        FIH_CALL(bl1_hash_update, fih_err, handshake_data[trusted_subnet->id].node_ivs[node],
                                               sizeof(handshake_data[trusted_subnet->id].node_ivs[node]));
        if (FIH_NOT_EQ(fih_err, FIH_SUCCESS)) {
            return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
        }
    }

    FIH_CALL(bl1_hash_finish, fih_err, hash, sizeof(hash), &hash_size);
    if (FIH_NOT_EQ(fih_err, FIH_SUCCESS)) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    plat_err = rse_setup_session_key(hash, hash_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return (enum sfcp_error_t)plat_err;
    }

    trusted_subnet->key_id = cc3xx_get_opaque_key(RSE_KMU_SLOT_SESSION_KEY_0);
    assert(!CC3XX_IS_OPAQUE_KEY_INVALID(trusted_subnet->key_id));

    return sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                         SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID);
}

static enum sfcp_error_t derive_session_key_responder_server(
    struct sfcp_trusted_subnet_config_t *trusted_subnet, sfcp_node_id_t my_node_id,
    uint8_t *payload, size_t payload_size, sfcp_node_id_t sender_node, uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet->id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED:
        sfcp_err = sfcp_trusted_subnet_set_state(
            trusted_subnet->id,
            SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        return handle_client_request(trusted_subnet, my_node_id, payload, payload_size, sender_node,
                                     message_id);
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG:
        return handle_get_iv_reply(trusted_subnet, my_node_id, payload, payload_size, sender_node,
                                   message_id);
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG:
        return handle_send_ivs_reply(trusted_subnet, my_node_id, payload, payload_size, sender_node,
                                     message_id);
    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }
}

static enum sfcp_error_t handle_client_request_empty_response(
    struct sfcp_trusted_subnet_config_t *trusted_subnet, sfcp_node_id_t my_node_id,
    uint8_t *payload, size_t payload_size, sfcp_node_id_t sender_node, uint8_t message_id)
{
    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id,
        SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY);
}

static enum sfcp_error_t handle_get_iv_msg(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                           sfcp_node_id_t my_node_id, uint8_t *payload,
                                           size_t payload_size, sfcp_node_id_t sender_node,
                                           uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;
    int32_t bl1_random_err;
    struct sfcp_handshake_get_iv_reply_payload_t get_iv_reply_payload;

    bl1_random_err =
        bl1_random_generate_secure(handshake_data[trusted_subnet->id].node_ivs[my_node_id],
                                   sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));
    if (bl1_random_err != 0) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    memcpy(get_iv_reply_payload.iv, handshake_data[trusted_subnet->id].node_ivs[my_node_id],
           sizeof(handshake_data[trusted_subnet->id].node_ivs[my_node_id]));

    sfcp_err = construct_send_reply(sender_node, message_id, (uint8_t *)&get_iv_reply_payload,
                                    sizeof(get_iv_reply_payload));
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    return sfcp_trusted_subnet_set_state(
        trusted_subnet->id, SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY);
}

static enum sfcp_error_t handle_send_ivs_msg(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                             sfcp_node_id_t my_node_id, uint8_t *payload,
                                             size_t payload_size, sfcp_node_id_t sender_node,
                                             uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;
    enum tfm_plat_err_t plat_err;
    fih_int fih_err;
    __ALIGNED(4) uint8_t hash[48];
    size_t hash_size;
    struct sfcp_handshake_send_ivs_msg_payload_t *send_ivs_msg;
    bool valid_iv = false;

    send_ivs_msg = (struct sfcp_handshake_send_ivs_msg_payload_t *)payload;

    sfcp_err = construct_send_reply(sender_node, message_id, NULL, 0);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    for (uint8_t i = 0; i < trusted_subnet->node_amount; i++) {
        sfcp_node_id_t node = trusted_subnet->nodes[i].id;

        if (node != my_node_id) {
            continue;
        }

        if (memcmp(send_ivs_msg->ivs[i], handshake_data[trusted_subnet->id].node_ivs[my_node_id],
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

    FIH_CALL(bl1_hash_compute, fih_err, TFM_BL1_HASH_ALG_SHA384, (uint8_t *)send_ivs_msg->ivs,
                                        send_ivs_msg->iv_amount * sizeof(send_ivs_msg->ivs[0]), hash,
                                        sizeof(hash), &hash_size);
    if (FIH_NOT_EQ(fih_err, FIH_SUCCESS)) {
        return SFCP_ERROR_INTERNAL_HANDSHAKE_FAILURE;
    }

    plat_err = rse_setup_session_key(hash, hash_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return (enum sfcp_error_t)plat_err;
    }

    trusted_subnet->key_id = cc3xx_get_opaque_key(RSE_KMU_SLOT_SESSION_KEY_0);
    assert(!CC3XX_IS_OPAQUE_KEY_INVALID(trusted_subnet->key_id));

    return sfcp_trusted_subnet_set_state(trusted_subnet->id,
                                         SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID);
}

static enum sfcp_error_t derive_session_key_responder_client(
    struct sfcp_trusted_subnet_config_t *trusted_subnet, sfcp_node_id_t my_node_id,
    uint8_t *payload, size_t payload_size, sfcp_node_id_t sender_node, uint8_t message_id)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet->id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST:
        return handle_client_request_empty_response(trusted_subnet, my_node_id, payload,
                                                    payload_size, sender_node, message_id);
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED:
        sfcp_err = sfcp_trusted_subnet_set_state(
            trusted_subnet->id,
            SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_SERVER_GET_REQUEST);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        /* Fallthrough */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
        return handle_get_iv_msg(trusted_subnet, my_node_id, payload, payload_size, sender_node,
                                 message_id);
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY:
        return handle_send_ivs_msg(trusted_subnet, my_node_id, payload, payload_size, sender_node,
                                   message_id);
    default:
        return SFCP_ERROR_INVALID_TRUSTED_SUBNET_STATE;
    }
}

static bool check_get_iv_msg(const uint8_t *payload, size_t payload_size, uint8_t trusted_subnet_id)
{
    struct sfcp_handshake_get_iv_msg_payload_t *get_iv_msg;

    if (payload_size != sizeof(*get_iv_msg)) {
        return false;
    }

    get_iv_msg = (struct sfcp_handshake_get_iv_msg_payload_t *)payload;

    if ((get_iv_msg->type != SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_GET_IV_MSG) ||
        (get_iv_msg->trusted_subnet_id != trusted_subnet_id)) {
        return false;
    }

    return true;
}

static enum sfcp_error_t
check_msg_with_trusted_subnet(sfcp_node_id_t remote_node, sfcp_node_id_t my_node_id,
                              uint8_t message_id, const uint8_t *payload, size_t payload_size,
                              struct sfcp_trusted_subnet_config_t *trusted_subnet,
                              bool *valid_for_subnet)
{
    enum sfcp_error_t sfcp_err;
    enum sfcp_trusted_subnet_state_t state;

    sfcp_err = sfcp_trusted_subnet_get_state(trusted_subnet->id, &state);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    switch (state) {
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED:
        goto out_invalid;
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED: {
        sfcp_node_id_t server_node;

        sfcp_err = sfcp_trusted_subnet_get_server(trusted_subnet, &server_node);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (server_node == my_node_id) {
            struct sfcp_handshake_request_msg_payload_t *request_msg;

            if (payload_size != sizeof(*request_msg)) {
                goto out_invalid;
            }

            request_msg = (struct sfcp_handshake_request_msg_payload_t *)payload;

            if ((request_msg->type != SFCP_HANDSHAKE_PAYLOAD_CLIENT_SESSION_KEY_REQUEST_MSG) ||
                (request_msg->trusted_subnet_id != trusted_subnet->id)) {
                goto out_invalid;
            }
        } else {
            if (!check_get_iv_msg(payload, payload_size, trusted_subnet->id)) {
                goto out_invalid;
            }
        }

        break;
    }

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY:
        if (!check_get_iv_msg(payload, payload_size, trusted_subnet->id)) {
            goto out_invalid;
        }

        break;

    /* Expect empty replies */
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG:
    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST:
        if (payload_size != 0) {
            goto out_invalid;
        }

        if (!is_message_id_valid_for_subnet(trusted_subnet->id, remote_node, message_id)) {
            goto out_invalid;
        }

        break;

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY: {
        struct sfcp_handshake_send_ivs_msg_payload_t *send_ivs_msg;

        if (payload_size != get_send_ivs_msg_payload_size(trusted_subnet)) {
            goto out_invalid;
        }

        send_ivs_msg = (struct sfcp_handshake_send_ivs_msg_payload_t *)payload;

        if ((send_ivs_msg->type != SFCP_HANDSHAKE_PAYLOAD_SERVER_SESSION_KEY_SEND_IVS_MSG) ||
            (send_ivs_msg->trusted_subnet_id != trusted_subnet->id)) {
            goto out_invalid;
        }

        break;
    }

    case SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG:
        if (payload_size != sizeof(struct sfcp_handshake_get_iv_reply_payload_t)) {
            goto out_invalid;
        }

        if (!is_message_id_valid_for_subnet(trusted_subnet->id, remote_node, message_id)) {
            goto out_invalid;
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

static enum sfcp_error_t
msg_get_trusted_subnet_id(sfcp_node_id_t remote_node, sfcp_node_id_t my_node_id, uint8_t message_id,
                          const uint8_t *payload, size_t payload_size,
                          struct sfcp_trusted_subnet_config_t **trusted_subnet)
{
    enum sfcp_error_t sfcp_err;
    struct sfcp_trusted_subnet_config_t *configs;
    size_t num_trusted_subnets;

    *trusted_subnet = NULL;

    sfcp_platform_get_trusted_subnets(&configs, &num_trusted_subnets);

    for (uint8_t i = 0; i < num_trusted_subnets; i++) {
        bool valid_for_subnet;

        sfcp_err = check_msg_with_trusted_subnet(remote_node, my_node_id, message_id, payload,
                                                 payload_size, &configs[i], &valid_for_subnet);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }

        if (!valid_for_subnet) {
            continue;
        }

        /* The message we have is valid for this subnet state */
        *trusted_subnet = &configs[i];
        return SFCP_ERROR_SUCCESS;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_derive_session_key_responder(sfcp_node_id_t remote_node, uint8_t message_id,
                                                    uint8_t *payload, size_t payload_size,
                                                    bool *is_handshake_msg)
{
    enum sfcp_hal_error_t hal_err;
    enum sfcp_error_t sfcp_err;
    struct sfcp_trusted_subnet_config_t *trusted_subnet;
    sfcp_node_id_t my_node_id;
    sfcp_node_id_t server_node_id;

    hal_err = sfcp_hal_get_my_node_id(&my_node_id);
    if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
        sfcp_err = sfcp_hal_error_to_sfcp_error(hal_err);
        return sfcp_err;
    }

    sfcp_err = msg_get_trusted_subnet_id(remote_node, my_node_id, message_id, payload, payload_size,
                                         &trusted_subnet);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (trusted_subnet == NULL) {
        /* Not a valid handshake message */
        *is_handshake_msg = false;
        return SFCP_ERROR_SUCCESS;
    }

    sfcp_err = sfcp_trusted_subnet_get_server(trusted_subnet, &server_node_id);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return sfcp_err;
    }

    if (server_node_id == my_node_id) {
        sfcp_err = derive_session_key_responder_server(trusted_subnet, my_node_id, payload,
                                                       payload_size, remote_node, message_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    } else {
        sfcp_err = derive_session_key_responder_client(trusted_subnet, my_node_id, payload,
                                                       payload_size, remote_node, message_id);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            return sfcp_err;
        }
    }

    *is_handshake_msg = true;
    return SFCP_ERROR_SUCCESS;
}

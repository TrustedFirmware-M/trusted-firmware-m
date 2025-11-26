/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis_compiler.h"
#include "psa/client.h"
#include "sfcp.h"
#include "sfcp_psa_protocol.h"
#include "critical_section.h"

/* These are specific to the server to which we are sending PSA
 * requests. We need the node ID for the remote node and the
 * application ID of the PSA service
 */
#define SFCP_PSA_SERVER_NODE_ID (0)
#define SFCP_PSA_SERVER_APPLICATION_ID (0)

/* TODO: Tune this value. Initially aim to only make use of embed message
 * protocol if it can fit in a single MHU transfer (assuming a standard
 * number of channels of 16 with 1 channel for message length and 1
 * channel for signalling). This will need to be tuned per platform
 */
#define SFCP_MHU_MAX_TRANSFER_SIZE ((16 - 2) * sizeof(uint32_t))

/* Use for both the message and reply, define to the larger of
 * the two
 *
 * TODO: This needs to be reconsidered if reentrancy is required
 */
static __ALIGNED(4) uint8_t
    psa_payload_buf[SFCP_BUFFER_MINIMUM_SIZE +
                    (sizeof(struct serialized_psa_msg_t) > sizeof(struct serialized_psa_reply_t) ?
                         sizeof(struct serialized_psa_msg_t) :
                         sizeof(struct serialized_psa_reply_t))];

static enum sfcp_protocol_version_t select_protocol_version(const psa_invec *in_vec, size_t in_len,
                                                            const psa_outvec *out_vec,
                                                            size_t out_len)
{
    size_t comms_embed_msg_min_size;
    size_t comms_embed_reply_min_size;
    size_t in_size_total = 0;
    size_t out_size_total = 0;
    size_t i;

    for (i = 0U; i < in_len; ++i) {
        in_size_total += in_vec[i].len;
    }
    for (i = 0U; i < out_len; ++i) {
        out_size_total += out_vec[i].len;
    }

    comms_embed_msg_min_size = sizeof(struct serialized_sfcp_header_t) +
                               sizeof(struct sfcp_embed_msg_t) -
                               sizeof(((struct sfcp_embed_msg_t *)0)->payload);

    comms_embed_reply_min_size = sizeof(struct serialized_sfcp_header_t) +
                                 sizeof(struct sfcp_embed_reply_t) -
                                 sizeof(((struct sfcp_embed_reply_t *)0)->payload);

    if ((comms_embed_msg_min_size + in_size_total > SFCP_MHU_MAX_TRANSFER_SIZE) ||
        (comms_embed_reply_min_size + out_size_total > SFCP_MHU_MAX_TRANSFER_SIZE)) {
        return SFCP_PROTOCOL_POINTER_ACCESS;
    } else {
        return SFCP_PROTOCOL_EMBED;
    }
}

static uint16_t select_client_id(void)
{
    /* Client ID value of 0 is reserved
     *
     * TODO: This needs to be reconsidered if reentrancy becomes a problem.
     * In this case, we need to dynamically allocate a client ID to each
     * caller
     */
    return 1;
}

psa_status_t psa_call(psa_handle_t handle, int32_t type, const psa_invec *in_vec, size_t in_len,
                      psa_outvec *out_vec, size_t out_len)
{
    psa_status_t status;
    enum sfcp_error_t sfcp_err;
    struct serialized_psa_msg_t *psa_msg;
    struct serialized_psa_reply_t *psa_reply;
    size_t psa_msg_len;
    size_t payload_len;
    struct sfcp_packet_t *msg;
    size_t msg_size;
    struct sfcp_reply_metadata_t metadata;
    psa_status_t return_val;
    const uint16_t client_id = select_client_id();

    if (type > PSA_CALL_TYPE_MAX || type < PSA_CALL_TYPE_MIN || in_len > PSA_MAX_IOVEC ||
        out_len > PSA_MAX_IOVEC) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    sfcp_err = sfcp_init_msg(psa_payload_buf, sizeof(psa_payload_buf), SFCP_PSA_SERVER_NODE_ID,
                             SFCP_PSA_SERVER_APPLICATION_ID, client_id, true, false, 0,
                             (uint8_t **)&psa_msg, &payload_len, &msg, &msg_size, &metadata);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return PSA_ERROR_COMMUNICATION_FAILURE;
    }

    if (payload_len < sizeof(struct serialized_psa_msg_t)) {
        return PSA_ERROR_INSUFFICIENT_STORAGE;
    }

    psa_msg->header.protocol_ver = select_protocol_version(in_vec, in_len, out_vec, out_len);

    status = sfcp_protocol_serialize_msg(handle, type, in_vec, in_len, out_vec, out_len, psa_msg,
                                         &psa_msg_len);
    if (status != PSA_SUCCESS) {
        return status;
    }

    sfcp_err = sfcp_send_msg(msg, msg_size, psa_msg_len);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return PSA_ERROR_COMMUNICATION_FAILURE;
    }

    do {
        sfcp_err = sfcp_receive_reply(psa_payload_buf, sizeof(psa_payload_buf), metadata,
                                      (uint8_t **)&psa_reply, &payload_len);
    } while (sfcp_err == SFCP_ERROR_NO_REPLY_AVAILABLE);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return PSA_ERROR_COMMUNICATION_FAILURE;
    }

    status = sfcp_protocol_deserialize_reply(out_vec, out_len, &return_val, psa_reply, payload_len);
    if (status != PSA_SUCCESS) {
        return status;
    }

    return return_val;
}

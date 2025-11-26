/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_psa_protocol.h"
#include "sfcp_psa_client_request.h"

#include <assert.h>
#include <string.h>

psa_status_t sfcp_protocol_serialize_msg(psa_handle_t handle, int16_t type, const psa_invec *in_vec,
                                         uint8_t in_len, const psa_outvec *out_vec, uint8_t out_len,
                                         struct serialized_psa_msg_t *msg, size_t *msg_len)
{
    psa_status_t status;

    assert(msg != NULL);
    assert(msg_len != NULL);
    assert(in_vec != NULL);

    switch (msg->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        status = sfcp_protocol_embed_serialize_msg(handle, type, in_vec, in_len, out_vec, out_len,
                                                   &msg->msg.embed, msg_len);
        if (status != PSA_SUCCESS) {
            return status;
        }
        break;
#endif
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        status = sfcp_protocol_pointer_access_serialize_msg(
            handle, type, in_vec, in_len, out_vec, out_len, &msg->msg.pointer_access, msg_len);
        if (status != PSA_SUCCESS) {
            return status;
        }
        break;
#endif
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    *msg_len += sizeof(struct serialized_sfcp_header_t);

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_deserialize_msg(struct client_request_t *req,
                                           struct serialized_psa_msg_t *msg, size_t msg_len)
{
    if (msg_len < sizeof(msg->header)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    req->protocol_ver = msg->header.protocol_ver;

    switch (msg->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        return sfcp_protocol_embed_deserialize_msg(
            req, &msg->msg.embed, msg_len - sizeof(struct serialized_sfcp_header_t));
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        return sfcp_protocol_pointer_access_deserialize_msg(
            req, &msg->msg.pointer_access, msg_len - sizeof(struct serialized_sfcp_header_t));
#endif
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }
}

psa_status_t sfcp_protocol_serialize_reply(struct client_request_t *req,
                                           struct serialized_psa_reply_t *reply, size_t *reply_size)
{
    psa_status_t status;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));

    reply->header.protocol_ver = req->protocol_ver;

    switch (reply->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        status = sfcp_protocol_embed_serialize_reply(req, &reply->reply.embed, reply_size);
        if (status != PSA_SUCCESS) {
            return status;
        }

        break;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        status = sfcp_protocol_pointer_access_serialize_reply(req, &reply->reply.pointer_access,
                                                              reply_size);
        if (status != PSA_SUCCESS) {
            return status;
        }

        break;
#endif
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    *reply_size += sizeof(struct serialized_sfcp_header_t);

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_deserialize_reply(psa_outvec *out_vec, uint8_t out_len,
                                             psa_status_t *return_val,
                                             const struct serialized_psa_reply_t *reply,
                                             size_t reply_size)
{
    assert(reply != NULL);
    assert(return_val != NULL);

    switch (reply->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        return sfcp_protocol_embed_deserialize_reply(out_vec, out_len, return_val,
                                                     &reply->reply.embed, reply_size);
#endif
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        return sfcp_protocol_pointer_access_deserialize_reply(
            out_vec, out_len, return_val, &reply->reply.pointer_access, reply_size);
#endif
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_serialize_error(struct client_request_t *req,
                                           struct serialized_sfcp_header_t *header,
                                           psa_status_t error, struct serialized_psa_reply_t *reply,
                                           size_t *reply_size)
{
    psa_status_t status;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));
    memcpy(&reply->header, header, sizeof(struct serialized_sfcp_header_t));

    switch (reply->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        status = sfcp_protocol_embed_serialize_error(req, error, &reply->reply.embed, reply_size);
        if (status != PSA_SUCCESS) {
            return status;
        }

        break;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        status = sfcp_protocol_pointer_access_serialize_error(
            req, error, &reply->reply.pointer_access, reply_size);
        if (status != PSA_SUCCESS) {
            return status;
        }

        break;
#endif
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    *reply_size += sizeof(struct serialized_sfcp_header_t);

    return PSA_SUCCESS;
}

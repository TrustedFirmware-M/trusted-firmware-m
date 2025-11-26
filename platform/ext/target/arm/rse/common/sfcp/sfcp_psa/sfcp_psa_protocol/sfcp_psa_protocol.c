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

enum tfm_plat_err_t sfcp_protocol_serialize_msg(psa_handle_t handle, int16_t type,
                                                const psa_invec *in_vec, uint8_t in_len,
                                                const psa_outvec *out_vec, uint8_t out_len,
                                                struct serialized_psa_msg_t *msg, size_t *msg_len)
{
    enum tfm_plat_err_t plat_err;

    assert(msg != NULL);
    assert(msg_len != NULL);
    assert(in_vec != NULL);

    switch (msg->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        plat_err = sfcp_protocol_embed_serialize_msg(handle, type, in_vec, in_len, out_vec, out_len,
                                                     &msg->msg.embed, msg_len);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
        break;
#endif
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        plat_err = sfcp_protocol_pointer_access_serialize_msg(
            handle, type, in_vec, in_len, out_vec, out_len, &msg->msg.pointer_access, msg_len);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
        break;
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *msg_len += sizeof(struct serialized_sfcp_header_t);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t sfcp_protocol_deserialize_msg(struct client_request_t *req,
                                                  struct serialized_psa_msg_t *msg, size_t msg_len)
{
    if (msg_len < sizeof(msg->header)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
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
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
}

enum tfm_plat_err_t sfcp_protocol_serialize_reply(struct client_request_t *req,
                                                  struct serialized_psa_reply_t *reply,
                                                  size_t *reply_size)
{
    enum tfm_plat_err_t err;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));

    reply->header.protocol_ver = req->protocol_ver;

    switch (reply->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        err = sfcp_protocol_embed_serialize_reply(req, &reply->reply.embed, reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        break;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        err = sfcp_protocol_pointer_access_serialize_reply(req, &reply->reply.pointer_access,
                                                           reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        break;
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *reply_size += sizeof(struct serialized_sfcp_header_t);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t sfcp_protocol_deserialize_reply(psa_outvec *out_vec, uint8_t out_len,
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
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t sfcp_protocol_serialize_error(struct client_request_t *req,
                                                  struct serialized_sfcp_header_t *header,
                                                  psa_status_t error,
                                                  struct serialized_psa_reply_t *reply,
                                                  size_t *reply_size)
{
    enum tfm_plat_err_t err;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));
    memcpy(&reply->header, header, sizeof(struct serialized_sfcp_header_t));

    switch (reply->header.protocol_ver) {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    case SFCP_PROTOCOL_EMBED:
        err = sfcp_protocol_embed_serialize_error(req, error, &reply->reply.embed, reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        break;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    case SFCP_PROTOCOL_POINTER_ACCESS:
        err = sfcp_protocol_pointer_access_serialize_error(req, error, &reply->reply.pointer_access,
                                                           reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        break;
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *reply_size += sizeof(struct serialized_sfcp_header_t);

    return TFM_PLAT_ERR_SUCCESS;
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_protocol.h"

#include "tfm_log.h"
#include <string.h>

enum tfm_plat_err_t rse_protocol_deserialize_msg(
        struct client_request_t *req, struct serialized_psa_msg_t *msg,
        size_t msg_len)
{
    if (msg_len < sizeof(msg->header)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    req->protocol_ver = msg->header.protocol_ver;
    req->seq_num = msg->header.seq_num;
    req->client_id = msg->header.client_id;

    switch (msg->header.protocol_ver) {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
    case RSE_COMMS_PROTOCOL_EMBED:
        VERBOSE_RAW("[COMMS] Deserializing as embed message\n");
        return rse_protocol_embed_deserialize_msg(req, &msg->msg.embed,
            msg_len - sizeof(struct serialized_rse_comms_header_t));
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
    case RSE_COMMS_PROTOCOL_POINTER_ACCESS:
        VERBOSE_RAW("[COMMS] Deserializing as pointer_access message\n");
        return rse_protocol_pointer_access_deserialize_msg(req, &msg->msg.pointer_access,
                                               msg_len - sizeof(struct serialized_rse_comms_header_t));
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
}

enum tfm_plat_err_t rse_protocol_serialize_reply(struct client_request_t *req,
        struct serialized_psa_reply_t *reply, size_t *reply_size)
{
    enum tfm_plat_err_t err;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));

    reply->header.protocol_ver = req->protocol_ver;
    reply->header.seq_num = req->seq_num;
    reply->header.client_id = req->client_id;

    switch (reply->header.protocol_ver) {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
    case RSE_COMMS_PROTOCOL_EMBED:
        err = rse_protocol_embed_serialize_reply(req, &reply->reply.embed,
                                                 reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
        break;
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
    case RSE_COMMS_PROTOCOL_POINTER_ACCESS:
        err = rse_protocol_pointer_access_serialize_reply(req,
                &reply->reply.pointer_access, reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
        break;
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *reply_size += sizeof(struct serialized_rse_comms_header_t);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_protocol_serialize_error(
        struct client_request_t *req,
        struct serialized_rse_comms_header_t *header, psa_status_t error,
        struct serialized_psa_reply_t *reply, size_t *reply_size)
{
    enum tfm_plat_err_t err;

    memset(reply, 0, sizeof(struct serialized_psa_reply_t));
    memcpy(&reply->header, header,
           sizeof(struct serialized_rse_comms_header_t));

    switch (reply->header.protocol_ver) {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
    case RSE_COMMS_PROTOCOL_EMBED:
        err = rse_protocol_embed_serialize_error(req, error,
                                                 &reply->reply.embed,
                                                 reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
        break;
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
    case RSE_COMMS_PROTOCOL_POINTER_ACCESS:
        err = rse_protocol_pointer_access_serialize_error(req, error,
                &reply->reply.pointer_access, reply_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
        break;
#endif
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *reply_size += sizeof(struct serialized_rse_comms_header_t);

    return TFM_PLAT_ERR_SUCCESS;
}

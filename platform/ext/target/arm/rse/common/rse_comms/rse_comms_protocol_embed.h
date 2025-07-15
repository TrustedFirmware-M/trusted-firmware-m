/*
 * Copyright (c) 2022, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_PROTOCOL_EMBED_H__
#define __RSE_COMMS_PROTOCOL_EMBED_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "rse_comms.h"
#include "tfm_platform_system.h"

#ifdef __cplusplus
extern "C" {
#endif

__PACKED_STRUCT rse_embed_msg_t {
    psa_handle_t handle;
    uint32_t ctrl_param; /* type, in_len, out_len */
    uint16_t io_size[PSA_MAX_IOVEC];
    uint8_t payload[RSE_COMMS_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

__PACKED_STRUCT rse_embed_reply_t {
    int32_t return_val;
    uint16_t out_size[PSA_MAX_IOVEC];
    uint8_t payload[RSE_COMMS_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

enum tfm_plat_err_t rse_protocol_embed_deserialize_msg(
        struct client_request_t *req, struct rse_embed_msg_t *msg,
        size_t msg_len);

enum tfm_plat_err_t rse_protocol_embed_serialize_reply(
        struct client_request_t *req, struct rse_embed_reply_t *reply,
        size_t *reply_size);

enum tfm_plat_err_t rse_protocol_embed_serialize_error(
        struct client_request_t *req, psa_status_t err,
        struct rse_embed_reply_t *reply, size_t *reply_size);


#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_PROTOCOL_EMBED_H__ */

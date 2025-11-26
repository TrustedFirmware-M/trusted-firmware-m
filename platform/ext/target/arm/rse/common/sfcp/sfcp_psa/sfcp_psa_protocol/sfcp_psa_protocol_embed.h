/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_PSA_PROTOCOL_EMBED_H__
#define __SFCP_PSA_PROTOCOL_EMBED_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "tfm_platform_system.h"
#include "config_tfm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Calculate the maximum size of the PSA embed payload considering the
 * maximum possible size of the message. 0x4 is the size of the
 * payload header */
#define SFCP_PSA_EMBED_PAYLOAD_MAX_SIZE \
    (SFCP_PAYLOAD_MAX_SIZE -            \
     (0x4 + sizeof(psa_handle_t) + sizeof(uint32_t) + (PSA_MAX_IOVEC * sizeof(uint16_t))))

/**
 * \brief Packed representation of an embed-mode PSA client request.
 *
 * The structure contains the PSA handle, message metadata, the per-vector
 * sizes, and the inline payload copied from the caller.
 */
__PACKED_STRUCT sfcp_embed_msg_t {
    psa_handle_t handle;
    uint32_t ctrl_param; /* type, in_len, out_len */
    uint16_t io_size[PSA_MAX_IOVEC];
    uint8_t payload[SFCP_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

/**
 * \brief Packed representation of an embed-mode PSA reply.
 *
 * Stores the PSA status, populated output sizes, and the inline payload to
 * return to the caller.
 */
__PACKED_STRUCT sfcp_embed_reply_t {
    int32_t return_val;
    uint16_t out_size[PSA_MAX_IOVEC];
    uint8_t payload[SFCP_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

struct client_request_t;

/**
 * \brief Embed-specific implementation of sfcp_protocol_serialize_msg().
 *
 * \see sfcp_protocol_serialize_msg
 */
psa_status_t sfcp_protocol_embed_serialize_msg(psa_handle_t handle, int16_t type,
                                               const psa_invec *in_vec, uint8_t in_len,
                                               const psa_outvec *out_vec, uint8_t out_len,
                                               struct sfcp_embed_msg_t *msg, size_t *msg_len);

/**
 * \brief Embed-specific implementation of sfcp_protocol_deserialize_msg().
 *
 * \see sfcp_protocol_deserialize_msg
 */
psa_status_t sfcp_protocol_embed_deserialize_msg(struct client_request_t *req,
                                                 struct sfcp_embed_msg_t *msg, size_t msg_len);

/**
 * \brief Embed-specific implementation of sfcp_protocol_serialize_reply().
 *
 * \see sfcp_protocol_serialize_reply
 */
psa_status_t sfcp_protocol_embed_serialize_reply(struct client_request_t *req,
                                                 struct sfcp_embed_reply_t *reply,
                                                 size_t *reply_size);

/**
 * \brief Embed-specific implementation of sfcp_protocol_deserialize_reply().
 *
 * \see sfcp_protocol_deserialize_reply
 */
psa_status_t sfcp_protocol_embed_deserialize_reply(psa_outvec *out_vec, uint8_t out_len,
                                                   psa_status_t *return_val,
                                                   const struct sfcp_embed_reply_t *reply,
                                                   size_t reply_size);

/**
 * \brief Embed-specific implementation of sfcp_protocol_serialize_error().
 *
 * \see sfcp_protocol_serialize_error
 */
psa_status_t sfcp_protocol_embed_serialize_error(struct client_request_t *req, psa_status_t err,
                                                 struct sfcp_embed_reply_t *reply,
                                                 size_t *reply_size);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_PSA_PROTOCOL_EMBED_H__ */

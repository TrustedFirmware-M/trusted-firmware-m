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

__PACKED_STRUCT sfcp_embed_msg_t {
    psa_handle_t handle;
    uint32_t ctrl_param; /* type, in_len, out_len */
    uint16_t io_size[PSA_MAX_IOVEC];
    uint8_t payload[SFCP_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

__PACKED_STRUCT sfcp_embed_reply_t {
    int32_t return_val;
    uint16_t out_size[PSA_MAX_IOVEC];
    uint8_t payload[SFCP_PSA_EMBED_PAYLOAD_MAX_SIZE];
};

struct client_request_t;

enum tfm_plat_err_t sfcp_protocol_embed_deserialize_msg(struct client_request_t *req,
                                                        struct sfcp_embed_msg_t *msg,
                                                        size_t msg_len);

enum tfm_plat_err_t sfcp_protocol_embed_serialize_reply(struct client_request_t *req,
                                                        struct sfcp_embed_reply_t *reply,
                                                        size_t *reply_size);

enum tfm_plat_err_t sfcp_protocol_embed_serialize_error(struct client_request_t *req,
                                                        psa_status_t err,
                                                        struct sfcp_embed_reply_t *reply,
                                                        size_t *reply_size);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_PSA_PROTOCOL_EMBED_H__ */

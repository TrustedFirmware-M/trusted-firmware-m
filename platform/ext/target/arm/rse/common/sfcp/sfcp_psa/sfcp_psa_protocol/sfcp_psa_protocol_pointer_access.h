/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_PSA_PROTOCOL_POINTER_ACCESS_H__
#define __SFCP_PSA_PROTOCOL_POINTER_ACCESS_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "tfm_platform_system.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Packed representation of a pointer-access PSA client request.
 *
 * Carries the PSA metadata alongside host memory addresses that the secure
 * side can access directly instead of copying payloads.
 */
__PACKED_STRUCT sfcp_pointer_access_msg_t {
    psa_handle_t handle;
    uint32_t ctrl_param;
    uint32_t io_sizes[PSA_MAX_IOVEC];
    uint64_t host_ptrs[PSA_MAX_IOVEC];
};

/**
 * \brief Packed representation of a pointer-access PSA reply.
 *
 * Records the returned PSA status together with the final output sizes that
 * were written back through the shared pointers.
 */
__PACKED_STRUCT sfcp_pointer_access_reply_t {
    int32_t return_val;
    uint32_t out_size[PSA_MAX_IOVEC];
};

struct client_request_t;

/**
 * \brief Pointer-access-specific implementation of sfcp_protocol_serialize_msg().
 *
 * \see sfcp_protocol_serialize_msg
 */
enum tfm_plat_err_t
sfcp_protocol_pointer_access_serialize_msg(psa_handle_t handle, int16_t type,
                                           const psa_invec *in_vec, uint8_t in_len,
                                           const psa_outvec *out_vec, uint8_t out_len,
                                           struct sfcp_pointer_access_msg_t *msg, size_t *msg_len);

/**
 * \brief Pointer-access-specific implementation of sfcp_protocol_deserialize_msg().
 *
 * \see sfcp_protocol_deserialize_msg
 */
enum tfm_plat_err_t
sfcp_protocol_pointer_access_deserialize_msg(struct client_request_t *req,
                                             struct sfcp_pointer_access_msg_t *msg, size_t msg_len);

/**
 * \brief Pointer-access-specific implementation of sfcp_protocol_serialize_reply().
 *
 * \see sfcp_protocol_serialize_reply
 */
enum tfm_plat_err_t sfcp_protocol_pointer_access_serialize_reply(
    struct client_request_t *req, struct sfcp_pointer_access_reply_t *reply, size_t *reply_size);

/**
 * \brief Pointer-access-specific implementation of sfcp_protocol_deserialize_reply().
 *
 * \see sfcp_protocol_deserialize_reply
 */
enum tfm_plat_err_t sfcp_protocol_pointer_access_deserialize_reply(
    psa_outvec *out_vec, uint8_t out_len, psa_status_t *return_val,
    const struct sfcp_pointer_access_reply_t *reply, size_t reply_size);

/**
 * \brief Pointer-access-specific implementation of sfcp_protocol_serialize_error().
 *
 * \see sfcp_protocol_serialize_error
 */
enum tfm_plat_err_t
sfcp_protocol_pointer_access_serialize_error(struct client_request_t *req, psa_status_t err,
                                             struct sfcp_pointer_access_reply_t *reply,
                                             size_t *reply_size);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_PSA_PROTOCOL_POINTER_ACCESS_H__ */

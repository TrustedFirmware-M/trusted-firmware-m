/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_PSA_PROTOCOL_H__
#define __SFCP_PSA_PROTOCOL_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "tfm_platform_system.h"

#ifdef SFCP_PROTOCOL_EMBED_ENABLED
#include "sfcp_psa_protocol_embed.h"
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */

#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
#include "sfcp_psa_protocol_pointer_access.h"
#endif /* RSE_MHU_PROTOCOL_V0_ENABLED */

#ifdef __cplusplus
extern "C" {
#endif

enum sfcp_protocol_version_t {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
    SFCP_PROTOCOL_EMBED = 0,
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
    SFCP_PROTOCOL_POINTER_ACCESS = 1,
#endif /* SFCP_PROTOCOL_POINTER_ACCESS_ENABLED */
};

/**
 * \brief Common header that prefixes every serialized SFCP message.
 *
 * The header currently identifies which protocol (embed vs. pointer access)
 * was used when composing the payload.
 */
__PACKED_STRUCT serialized_sfcp_header_t {
    uint8_t protocol_ver;
    /* Pad out to 4 bytes to ensure alignment */
    uint8_t __reserved[3];
};

/**
 * \brief Serialized PSA client call sent from NSPE to SPE over MHU.
 *
 * The union member is selected based on \ref serialized_sfcp_header_t::protocol_ver.
 */
__PACKED_STRUCT serialized_psa_msg_t {
    struct serialized_sfcp_header_t header;
    __PACKED_UNION {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
        struct sfcp_embed_msg_t embed;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
        struct sfcp_pointer_access_msg_t pointer_access;
#endif /* SFCP_PROTOCOL_POINTER_ACCESS_ENABLED */
    } msg;
};

/**
 * \brief Serialized PSA reply sent from SPE to NSPE over MHU.
 *
 * The union member is selected based on \ref serialized_sfcp_header_t::protocol_ver.
 */
__PACKED_STRUCT serialized_psa_reply_t {
    struct serialized_sfcp_header_t header;
    __PACKED_UNION {
#ifdef SFCP_PROTOCOL_EMBED_ENABLED
        struct sfcp_embed_reply_t embed;
#endif /* SFCP_PROTOCOL_EMBED_ENABLED */
#ifdef SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
        struct sfcp_pointer_access_reply_t pointer_access;
#endif /* SFCP_PROTOCOL_POINTER_ACCESS_ENABLED */
    } reply;
};

struct client_request_t;

/**
 * \brief Serialize a PSA client call into a protocol message.
 *
 * \param[in]  handle           Target PSA partition handle.
 * \param[in]  type             PSA signal type.
 * \param[in]  in_vec           List of input vectors to copy into the message.
 * \param[in]  in_len           Number of valid entries in \p in_vec.
 * \param[in]  out_vec          List of output vectors describing expected replies.
 * \param[in]  out_len          Number of valid entries in \p out_vec.
 * \param[out] msg              Buffer to populate with the serialized message.
 * \param[out] msg_len          Final serialized message size on success.
 *
 * \retval PSA_SUCCESS         Operation succeeded.
 * \retval Other return code    Operation failed with an error code.
 */
psa_status_t sfcp_protocol_serialize_msg(psa_handle_t handle, int16_t type, const psa_invec *in_vec,
                                         uint8_t in_len, const psa_outvec *out_vec, uint8_t out_len,
                                         struct serialized_psa_msg_t *msg, size_t *msg_len);

/**
 * \brief Convert a serialized message to a client_request_t.
 *
 * \param[out] req               The client_request_t to fill.
 * \param[in]  msg               The serialized message to extract data from.
 * \param[in]  msg_len           The size of the message.
 *
 * \note   The sanitization of the client request structure is the
 *         responsibility of the caller.
 *
 * \retval PSA_SUCCESS           Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
psa_status_t sfcp_protocol_deserialize_msg(struct client_request_t *req,
                                           struct serialized_psa_msg_t *msg, size_t msg_len);

/**
 * \brief Convert a a client_request_t to a serialized reply.
 *
 * \param[in]  req               The client_request_t to serialize data from.
 * \param[out] reply             The reply to fill.
 * \param[out] reply_size        The size of the reply that was filled.
 *
 * \retval PSA_SUCCESS           Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
psa_status_t sfcp_protocol_serialize_reply(struct client_request_t *req,
                                           struct serialized_psa_reply_t *reply,
                                           size_t *reply_size);

/**
 * \brief Deserialize a protocol reply into PSA client outputs.
 *
 * \param[out] out_vec          Array of output buffers to populate.
 * \param[in]  out_len          Number of valid entries in \p out_vec.
 * \param[out] return_val       PSA status returned by the service.
 * \param[in]  reply            Serialized reply received from the peer.
 * \param[in]  reply_size       Size, in bytes, of \p reply.
 *
 * \retval PSA_SUCCESS          Operation succeeded..
 * \retval Other return code    Operation failed with an error code.
 */
psa_status_t sfcp_protocol_deserialize_reply(psa_outvec *out_vec, uint8_t out_len,
                                             psa_status_t *return_val,
                                             const struct serialized_psa_reply_t *reply,
                                             size_t reply_size);

/**
 * \brief Create a serialised error reply from a header and an error code.
 *        Intended to for the RSE to notify the AP of errors during the message
 *        deserialization phase.
 *
 * \param[in]  req               The client_request_t to serialize data from. If
 *                               the error occurred in allocation this pointer
 *                               may be NULL. This may not contain message
 *                               header information if the message
 *                               deserialize failed.
 * \param[in]  header            The header of the received
 *                               serialized_psa_msg_t whose deserialization
 *                               caused the error.
 * \param[in]  error             The error code to be transmitted to the AP.
 * \param[out] reply             The reply to fill.
 * \param[out] reply_size        The size of the reply that was filled.
 *
 * \retval PSA_SUCCESS           Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
psa_status_t sfcp_protocol_serialize_error(struct client_request_t *req,
                                           struct serialized_sfcp_header_t *header,
                                           psa_status_t error, struct serialized_psa_reply_t *reply,
                                           size_t *reply_size);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_PSA_PROTOCOL_H__ */

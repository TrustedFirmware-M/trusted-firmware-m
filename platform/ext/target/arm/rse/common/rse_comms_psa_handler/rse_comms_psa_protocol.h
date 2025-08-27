/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_PSA_PROTOCOL_H__
#define __RSE_COMMS_PSA_PROTOCOL_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "tfm_platform_system.h"

#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
#include "rse_comms_psa_protocol_embed.h"
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */

#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
#include "rse_comms_psa_protocol_pointer_access.h"
#endif /* RSE_MHU_PROTOCOL_V0_ENABLED */

#ifdef __cplusplus
extern "C" {
#endif

enum rse_comms_protocol_version_t {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
    RSE_COMMS_PROTOCOL_EMBED = 0,
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
    RSE_COMMS_PROTOCOL_POINTER_ACCESS = 1,
#endif /* RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED */
};


__PACKED_STRUCT serialized_rse_comms_header_t {
    uint8_t protocol_ver;
    /* Pad out to 4 bytes to ensure alignment */
    uint8_t __reserved[3];
};

/* MHU message passed from NSPE to SPE to deliver a PSA client call */
__PACKED_STRUCT serialized_psa_msg_t {
    struct serialized_rse_comms_header_t header;
    __PACKED_UNION {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
        struct rse_embed_msg_t embed;
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
        struct rse_pointer_access_msg_t pointer_access;
#endif /* RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED */
    } msg;
};

/* MHU reply message to hold the PSA client call return result from SPE */
__PACKED_STRUCT serialized_psa_reply_t {
    struct serialized_rse_comms_header_t header;
    __PACKED_UNION {
#ifdef RSE_COMMS_PROTOCOL_EMBED_ENABLED
        struct rse_embed_reply_t embed;
#endif /* RSE_COMMS_PROTOCOL_EMBED_ENABLED */
#ifdef RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
        struct rse_pointer_access_reply_t pointer_access;
#endif /* RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED */
    } reply;
};

struct client_request_t;

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
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t rse_protocol_deserialize_msg(struct client_request_t *req,
        struct serialized_psa_msg_t *msg, size_t msg_len);

/**
 * \brief Convert a a client_request_t to a serialized reply.
 *
 * \param[in]  req               The client_request_t to serialize data from.
 * \param[out] reply             The reply to fill.
 * \param[out] reply_size        The size of the reply that was filled.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t rse_protocol_serialize_reply(struct client_request_t *req,
        struct serialized_psa_reply_t *reply, size_t *reply_size);

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
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t rse_protocol_serialize_error(
        struct client_request_t *req,
        struct serialized_rse_comms_header_t *header, psa_status_t error,
        struct serialized_psa_reply_t *reply, size_t *reply_size);


#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_PSA_PROTOCOL_H__ */

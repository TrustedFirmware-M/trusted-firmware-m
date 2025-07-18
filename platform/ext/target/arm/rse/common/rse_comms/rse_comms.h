/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_H__
#define __RSE_COMMS_H__

#include <stdint.h>
#include <stdbool.h>
#include "platform_error_codes.h"
#include "rse_comms_link_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Minimum buffer size (in bytes) required for any RSE Comms packet.
 *
 * \details
 * This constant defines the smallest valid buffer size that can be passed to
 * RSE Comms send/receive/init functions. It accounts for the packet header,
 * required metadata fields, and any alignment requirements, but does not
 * include any additional payload space.
 *
 * Buffers smaller than this size are guaranteed to be rejected with
 * ::RSE_COMMS_ERROR_BUFFER_TOO_SMALL.
 *
 * This macro is intended for compile-time allocation checks or for ensuring
 * that dynamically allocated buffers meet the protocol's minimum size
 * requirements before calling RSE Comms APIs.
 */
#define RSE_COMMS_BUFFER_MINIMUM_SIZE (40)

/**
 * \brief Library return codes for the RSE comms API.
 *
 * Notes:
 * - Polling receives SHOULD use the *_NO_MSG_AVAILABLE / *_NO_REPLY_AVAILABLE codes
 *   when nothing is ready to read (non-fatal “no data” condition).
 * - If a provided buffer is too small to hold the packet header + metadata,
 *   the call MUST return RSE_COMMS_ERROR_BUFFER_TOO_SMALL.
 */
enum rse_comms_error_t {
    RSE_COMMS_ERROR_SUCCESS = 0,
    RSE_COMMS_ERROR_INVALID_POINTER,
    RSE_COMMS_ERROR_INVALID_PACKET,
    RSE_COMMS_ERROR_MESSAGE_TOO_SMALL,
    RSE_COMMS_ERROR_BUFFER_TOO_SMALL,
    RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE,
    RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED,
    RSE_COMMS_ERROR_INVALID_NODE,
    RSE_COMMS_ERROR_NO_MSG_AVAILABLE,
    RSE_COMMS_ERROR_NO_REPLY_AVAILABLE,
    RSE_COMMS_ERROR_SEND_MSG_AGAIN,
    RSE_COMMS_ERROR_INVALID_PROTOCOL_VERSION,
    RSE_COMMS_ERROR_INVALID_APPLICATION_ID,
    RSE_COMMS_ERROR_INVALID_CLIENT_ID,
    RSE_COMMS_ERROR_INVALID_CRYPTO_MODE,
    RSE_COMMS_ERROR_INVALID_MSG_TYPE,
    RSE_COMMS_ERROR_INVALID_SEQUENCE_NUMBER,
    RSE_COMMS_ERROR_INVALID_PACKET_SIZE,
    RSE_COMMS_ERROR_PROTOCOL_ERROR,
    RSE_COMMS_ERROR_HAL_ERROR_BASE,
    RSE_COMMS_ERROR_HAL_ERROR_MAX = RSE_COMMS_ERROR_HAL_ERROR_BASE + 0x100,
    RSE_COMMS_ERROR_FORCE_UINT32T_MAX = UINT32_MAX,
};

struct rse_comms_packet_t;

/**
 * \brief Metadata captured at send time to match a future reply.
 *
 * \details
 * The sender MUST NOT reuse a sequence number until the reply for the message
 * using that sequence number has been received. If the ID extension is used, the
 * (seq_num, client_id) pair MUST remain unique among in-flight messages.
 * If a timeout-retry mechanism is used, the sender MUST increment sequence numbers
 * between messages and keep metadata for all outstanding messages to handle delayed
 * replies.
 */
struct rse_comms_reply_metadata_t {
    rse_comms_node_id_t receiver;   /**< Intended receiver node ID. */
    bool uses_cryptography;         /**< Whether crypto/auth is used for this exchange.
                                         Replies MUST mirror this bit (except error replies,
                                         which are never encrypted). */
    uint16_t client_id;             /**< Client ID (0 if ID extension not used). */
    uint16_t application_id;        /**< Application ID (0 if ID extension not used). */
    uint8_t seq_num;                /**< Sequence number for matching. */
};

/**
 * \brief Metadata captured at receive time to initialize a reply.
 *
 * \details
 * A reply MUST use the same client ID and application ID as the original message,
 * so it routes back to the correct caller/handler.
 * The reply MUST also mirror the message’s uses_cryptography bit (except
 * for protocol error replies, which cannot be encrypted).
 */
struct rse_comms_msg_metadata_t {
    rse_comms_node_id_t sender;     /**< Original sender node ID (now the reply receiver). */
    bool uses_cryptography;         /**< Whether the original message used crypto/auth. */
    uint16_t client_id;             /**< Client ID from the original message (or 0). */
    uint16_t application_id;        /**< Application ID from the original message (or 0). */
    uint8_t seq_num;                /**< Sequence number from the original message. */
};

/**
 * \brief Initializes the RSE communications layer.
 *
 * \details
 * Initializes the transport/link integration used by the comms library.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success; otherwise a translated HAL error.
 */
enum rse_comms_error_t rse_comms_init(void);

/**
 * \brief Prepare a message packet and payload buffer for sending.
 *
 * \param[in]  buf               Caller-provided buffer that will hold the entire packet
 *                               (header + optional ID/crypto metadata + payload).
 * \param[in]  buf_size          Size of \p buf.
 * \param[in]  receiver          Destination node ID.
 * \param[in]  application_id    Application ID at the receiver (0 means the receiver node itself).
 * \param[in]  client_id         Client ID on behalf of which the sender is acting (0 means the sender node).
 * \param[in]  needs_reply       If true, the packet type is MSG_NEEDS_REPLY; otherwise MSG_NO_REPLY.
 *                               For MSG_NO_REPLY, the receiver MUST NOT send any reply.
 * \param[in]  uses_cryptography Whether to use the crypto/auth extension for this message.
 *                               (Sender and receiver must be in a Trusted Subnet and agree on mode/key.)
 * \param[out] payload           Pointer within \p buf where the caller writes plaintext payload.
 * \param[out] payload_len       Capacity of the payload area (bytes). Caller MUST NOT exceed this.
 * \param[out] msg               Pointer to the prepared packet structure within \p buf.
 * \param[out] msg_size          Total packet size (header + metadata + payload capacity) to pass to send.
 * \param[out] metadata          Populated with values needed to match a future reply.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_CRYPTOGRAPHY_NOT_SUPPORTED if crypto is requested but unsupported;
 *         RSE_COMMS_ERROR_INVALID_BUFFER / RSE_COMMS_ERROR_BUFFER_TOO_SMALL on buffer issues;
 *         RSE_COMMS_ERROR_INVALID_NODE for invalid destination.
 */
enum rse_comms_error_t rse_comms_init_msg(uint8_t *buf, size_t buf_size,
                                          rse_comms_node_id_t receiver, uint16_t application_id,
                                          uint16_t client_id, bool needs_reply,
                                          bool uses_cryptography, uint8_t **payload,
                                          size_t *payload_len, struct rse_comms_packet_t **msg,
                                          size_t *msg_size,
                                          struct rse_comms_reply_metadata_t *metadata);

/**
 * \brief Transmit a prepared message packet.
 *
 * \param[in] msg           Pointer to packet prepared by rse_comms_init_msg (unaltered).
 * \param[in] msg_size      Total size of the packet buffer.
 * \param[in] payload_size  Number of bytes of the payload area actually used.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_INVALID_PACKET / RSE_COMMS_ERROR_MESSAGE_TOO_SMALL /
 *         RSE_COMMS_ERROR_PAYLOAD_TOO_LARGE if the packet is malformed or sizes mismatch;
 *         RSE_COMMS_ERROR_INVALID_NODE if routing fails;
 *         a translated HAL error on transport failure.
 *
 * \note The application supplies plaintext in the payload; the library performs any required
 *       encryption/authentication transparently before sending.
 */
enum rse_comms_error_t rse_comms_send_msg(struct rse_comms_packet_t *msg, size_t msg_size,
                                          size_t payload_size);

/**
 * \brief Prepare a reply packet and payload buffer corresponding to a received message.
 *
 * \param[in]  buf               Caller-provided buffer for the entire reply packet.
 * \param[in]  buf_size          Size of \p buf.
 * \param[in]  metadata          Metadata captured when the message was received; the reply will:
 *                               - mirror uses_cryptography (except protocol error replies,
 *                                 which cannot be encrypted), and
 *                               - use the same client_id, application_id, and seq_num.
 * \param[out] payload           Pointer within \p buf where the caller writes the plaintext reply payload.
 * \param[out] payload_len       Capacity of the reply payload area (bytes).
 * \param[out] reply             Pointer to the prepared reply packet within \p buf.
 * \param[out] reply_size        Total packet size to pass to rse_comms_send_reply.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success; *_BUFFER_TOO_SMALL if \p buf is insufficient; or a
 *         translated HAL error if local node ID cannot be obtained.
 */
enum rse_comms_error_t rse_comms_init_reply(uint8_t *buf, size_t buf_size,
                                            struct rse_comms_msg_metadata_t metadata,
                                            uint8_t **payload, size_t *payload_len,
                                            struct rse_comms_packet_t **reply, size_t *reply_size);

/**
 * \brief Transmit a prepared reply packet.
 *
 * \param[in] reply          Pointer to packet prepared by rse_comms_init_reply (unaltered).
 * \param[in] reply_size     Total size of the packet buffer.
 * \param[in] payload_size   Number of bytes of the payload area actually used.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success; the same validation/routing/transport errors as send_msg.
 *
 * \note Normal replies MUST mirror the message’s uses_cryptography bit.
 *       Protocol error replies are never encrypted.
 */
enum rse_comms_error_t rse_comms_send_reply(struct rse_comms_packet_t *reply, size_t reply_size,
                                            size_t payload_size);

/**
 * \brief Receive a message (polling mode).
 *
 * \details
 * Retrieves the next available message destined for \p sender (by route), validates it,
 * and exposes the plaintext payload pointer and capacity. If nothing is available, returns
 * RSE_COMMS_ERROR_NO_MSG_AVAILABLE (non-fatal).
 *
 * Validation rules enforced include:
 * - Packet type MUST be MSG_NEEDS_REPLY or MSG_NO_REPLY.
 * - Protocol version MUST equal 0b10.
 * - If ID extension not present, receiver MUST treat client_id/application_id as 0;
 *   otherwise, they MUST be read from their fields.
 * - Receiver MUST route handling based on application_id; if out of range, return
 *   INVALID_APPLICATION_ID (sender of MSG_NEEDS_REPLY will receive an error reply).
 * - If message crypto setting doesn’t match the expected uses_cryptography, return INVALID_CRYPTO_MODE.
 * - For MSG_NO_REPLY, the receiver MUST NOT send a reply even on failure.
 *
 * \param[in]  buf                Buffer to receive the packet.
 * \param[in]  buf_size           Size of \p buf.
 * \param[in]  sender             Expected sender node ID.
 * \param[in]  uses_cryptography  Expected crypto usage for this path (policy-driven).
 * \param[in]  application_id     Application ID this receiver instance handles (0 for node handler).
 * \param[out] client_id          Client ID extracted from the message (0 if no ID extension).
 * \param[out] payload            Pointer within \p buf to the plaintext payload.
 * \param[out] payload_len        Capacity of \p payload (bytes).
 * \param[out] metadata           Set to values needed to initialize a reply.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_NO_MSG_AVAILABLE if nothing to read;
 *         RSE_COMMS_ERROR_BUFFER_TOO_SMALL / *_INVALID_* for validation failures.
 *
 * \note Decryption/authentication MUST be performed before returning payload to the caller
 *       when crypto is used.
 */
enum rse_comms_error_t rse_comms_receive_msg(uint8_t *buf, size_t buf_size,
                                             rse_comms_node_id_t sender, bool uses_cryptography,
                                             uint16_t application_id, uint16_t *client_id,
                                             uint8_t **payload, size_t *payload_len,
                                             struct rse_comms_msg_metadata_t *metadata);

/**
 * \brief Receive a reply (polling mode).
 *
 * \details
 * Retrieves the next available reply corresponding to \p metadata (by route), validates it,
 * and exposes the plaintext payload pointer and capacity. If nothing is available, returns
 * RSE_COMMS_ERROR_NO_REPLY_AVAILABLE (non-fatal).
 *
 * Validation rules enforced include:
 * - Packet type MUST be REPLY (normal) or PROTOCOL_ERROR_REPLY (protocol error).
 *   Error replies are never encrypted.
 * - If the message used ID extension, the reply MUST carry the same client_id and application_id.
 * - uses_cryptography MUST mirror the original message for normal replies.
 *
 * \param[in]  buf               Buffer to receive the packet.
 * \param[in]  buf_size          Size of \p buf.
 * \param[in]  metadata          Reply metadata captured at send time.
 * \param[out] payload           Pointer within \p buf to the plaintext payload (if any).
 * \param[out] payload_len       Capacity of \p payload (bytes).
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_NO_REPLY_AVAILABLE if nothing to read;
 *         RSE_COMMS_ERROR_BUFFER_TOO_SMALL / *_INVALID_* for validation failures.
 *
 * \note Decryption/authentication MUST be performed before returning payload to the caller
 *       when crypto is used.
 */
enum rse_comms_error_t rse_comms_receive_reply(uint8_t *buf, size_t buf_size,
                                               struct rse_comms_reply_metadata_t metadata,
                                               uint8_t **payload, size_t *payload_len);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_H__ */

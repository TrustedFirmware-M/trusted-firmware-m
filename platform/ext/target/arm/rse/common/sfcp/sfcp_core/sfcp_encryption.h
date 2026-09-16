/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_ENCRYPTION_H__
#define __SFCP_ENCRYPTION_H__

#include <stdint.h>
#include "sfcp.h"
#include "sfcp_defs.h"
#include "sfcp_trusted_subnet.h"

/**
 * \file sfcp_encryption.h
 *
 * \brief SFCP trusted-subnet and packet-encryption interfaces.
 */

#ifdef __cplusplus
extern "C" {
#endif

/** Maximum number of trusted-subnet identifiers. */
#define SFCP_MAX_TRUSTED_SUBNET_ID (SFCP_NUMBER_NODES)

/**
 * \brief State of trusted-subnet key establishment and authentication.
 */
enum sfcp_trusted_subnet_state_t {
    SFCP_TRUSTED_SUBNET_STATE_NOT_REGISTERED = 0,

    /* SFCP session key derivation state */
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_REQUIRED,

    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_INITIATOR_STARTED,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_SERVER_GET_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_RECIEVED_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_RECEIVED_CLIENT_REQUEST_SERVER_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_MSG,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_GET_IV_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_MSG,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_SENT_SEND_IVS_REPLY,

    /* SFCP re-keying state */
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_REQUIRED,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_INITIATOR_STARTED,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SENT_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST_SERVER_REPLY,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_CLIENT_REQUEST,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_SEND_SEND_IVS_MSG,
    SFCP_TRUSTED_SUBNET_STATE_RE_KEYING_RECEIVED_SEND_IVS_MSG,

    /* Mutual authentication */
    SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_REQUIRED,
    SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_WAITING_FOR_AUTH_MSG,
    SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_SENT_AUTH_MSG,
    SFCP_TRUSTED_SUBNET_STATE_MUTUAL_AUTH_COMPLETED,

    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_VALID,
    SFCP_TRUSTED_SUBNET_STATE_SESSION_KEY_SETUP_NOT_REQUIRED
};

/**
 * \brief Retrieve a trusted-subnet configuration by identifier.
 *
 * \param[in]  trusted_subnet_id Identifier of the trusted subnet.
 * \param[out] trusted_subnet    Matching trusted-subnet configuration.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t
sfcp_get_trusted_subnet_by_id(uint8_t trusted_subnet_id,
                              struct sfcp_trusted_subnet_config_t **trusted_subnet);

/**
 * \brief Retrieve the number of configured trusted subnets.
 *
 * \param[out] num_trusted_subnets Number of configured trusted subnets.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_get_number_trusted_subnets(size_t *num_trusted_subnets);

/**
 * \brief Retrieve the server node for a trusted subnet.
 *
 * \param[in]  trusted_subnet Trusted-subnet configuration.
 * \param[out] server_node    Server node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t
sfcp_trusted_subnet_get_server(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                               sfcp_node_id_t *server_node);

/**
 * \brief Initialize the state of every configured trusted subnet.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_trusted_subnet_state_init(void);

/**
 * \brief Retrieve the current state of a trusted subnet.
 *
 * \param[in]  trusted_subnet_id Identifier of the trusted subnet.
 * \param[out] state             Current trusted-subnet state.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_trusted_subnet_get_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t *state);

/**
 * \brief Set the state of a trusted subnet.
 *
 * \param[in] trusted_subnet_id Identifier of the trusted subnet.
 * \param[in] state             New trusted-subnet state.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_trusted_subnet_set_state(uint8_t trusted_subnet_id,
                                                enum sfcp_trusted_subnet_state_t state);

/**
 * \brief Retrieve the trusted subnet containing a node.
 *
 * \param[in]  node           Node identifier to locate.
 * \param[out] trusted_subnet Trusted-subnet configuration containing \p node.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t
sfcp_get_trusted_subnet_for_node(sfcp_node_id_t node,
                                 struct sfcp_trusted_subnet_config_t **trusted_subnet);

/**
 * \brief Retrieve the next sequence number for an encrypted packet.
 *
 * This function does not consume the sequence number. Call
 * sfcp_trusted_subnet_increment_send_seq_num() after successfully sending the
 * packet.
 *
 * \param[in]  trusted_subnet Trusted-subnet configuration.
 * \param[in]  remote_node    Destination node identifier.
 * \param[out] seq_num        Sequence number to use for the packet.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t
sfcp_trusted_subnet_get_send_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                     sfcp_node_id_t remote_node, uint16_t *seq_num);

/**
 * \brief Consume the current send sequence number after a successful send.
 *
 * The trusted subnet is marked as requiring re-keying when the sequence-number
 * threshold is reached.
 *
 * \param[in] trusted_subnet_id Identifier of the trusted subnet.
 * \param[in] remote_node       Destination node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_trusted_subnet_increment_send_seq_num(uint8_t trusted_subnet_id,
                                                             sfcp_node_id_t remote_node);

/**
 * \brief Validate and record a received packet sequence number.
 *
 * \param[in] trusted_subnet Trusted-subnet configuration.
 * \param[in] remote_node    Source node identifier.
 * \param[in] seq_num        Received packet sequence number.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t
sfcp_trusted_subnet_check_recv_seq_num(struct sfcp_trusted_subnet_config_t *trusted_subnet,
                                       sfcp_node_id_t remote_node, uint16_t seq_num, bool commit);

/**
 * \brief Determine the encryption actions required by trusted-subnet state.
 *
 * \param[in]  trusted_subnet_id  Identifier of the trusted subnet.
 * \param[out] requires_handshake Whether a key handshake must be initiated.
 * \param[out] requires_encryption Whether packets must be encrypted.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_trusted_subnet_state_requires_handshake_encryption(
    uint8_t trusted_subnet_id, bool *requires_handshake, bool *requires_encryption);

/**
 * \brief Initiate key establishment or re-keying for a trusted subnet.
 *
 * \param[in] trusted_subnet_id Identifier of the trusted subnet.
 * \param[in] block             Wait for the handshake to complete when true.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_encryption_handshake_initiator(uint8_t trusted_subnet_id, bool block);

/**
 * \brief Process a received encryption-handshake packet.
 *
 * \param[in,out] packet           Received packet.
 * \param[in]     packet_size      Total size of \p packet in bytes.
 * \param[in]     remote_node      Source node identifier.
 * \param[in]     message_id       Message identifier from the packet.
 * \param[in]     packet_encrypted Whether \p packet was encrypted.
 * \param[in]     payload          Handshake payload.
 * \param[in]     payload_size     Size of \p payload in bytes.
 * \param[out]    is_handshake_msg Whether the packet is a handshake message.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_encryption_handshake_responder(struct sfcp_packet_t *packet,
                                                      size_t packet_size,
                                                      sfcp_node_id_t remote_node,
                                                      uint8_t message_id, bool packet_encrypted,
                                                      uint8_t *payload, size_t payload_size,
                                                      bool *is_handshake_msg);

/**
 * \brief Encrypt an SFCP message in place.
 *
 * \param[in,out] msg               Message to encrypt.
 * \param[in]     packet_size       Total size of \p msg in bytes.
 * \param[in]     trusted_subnet_id Identifier of the trusted subnet.
 * \param[in]     remote_node       Destination node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_encrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   uint8_t trusted_subnet_id, sfcp_node_id_t remote_node);

/**
 * \brief Authenticate and decrypt an SFCP message in place.
 *
 * \param[in,out] msg         Message to decrypt.
 * \param[in]     packet_size Total size of \p msg in bytes.
 * \param[in]     remote_node Source node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_decrypt_msg(struct sfcp_packet_t *msg, size_t packet_size,
                                   sfcp_node_id_t remote_node);

/**
 * \brief Encrypt an SFCP reply in place.
 *
 * \param[in,out] reply             Reply to encrypt.
 * \param[in]     packet_size       Total size of \p reply in bytes.
 * \param[in]     trusted_subnet_id Identifier of the trusted subnet.
 * \param[in]     remote_node       Destination node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_encrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     uint8_t trusted_subnet_id, sfcp_node_id_t remote_node);

/**
 * \brief Authenticate and decrypt an SFCP reply in place.
 *
 * \param[in,out] reply       Reply to decrypt.
 * \param[in]     packet_size Total size of \p reply in bytes.
 * \param[in]     remote_node Source node identifier.
 *
 * \return SFCP_ERROR_SUCCESS on success, or an SFCP error otherwise.
 */
enum sfcp_error_t sfcp_decrypt_reply(struct sfcp_packet_t *reply, size_t packet_size,
                                     sfcp_node_id_t remote_node);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_ENCRYPTION_H__ */

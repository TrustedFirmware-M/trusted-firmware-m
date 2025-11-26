/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_ENCRYPTION_HAL_H__
#define __SFCP_ENCRYPTION_HAL_H__

#include "sfcp.h"

/**
 * \file sfcp_encryption_hal.h
 *
 * \brief Platform hooks required by the SFCP encryption layer.
 *
 * \details
 * The SFCP encryption implementation relies on these HAL shims to integrate
 * with the platform cryptographic services and interrupt control. Each
 * function must be implemented by the platform.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Encrypt an SFCP packet using the supplied session key.
 *
 * \param[in]      key_id      Implementation-defined key identifier.
 * \param[in,out]  packet      Packet whose metadata and payload are encrypted
 *                             in-place.
 * \param[in]      packet_size Total size of \p packet in bytes.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_ENCRYPTION_FAILED or a
 *         validation error otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_encrypt_packet(uint32_t key_id, struct sfcp_packet_t *packet,
                                                     size_t packet_size);

/**
 * \brief Decrypt and authenticate an SFCP packet.
 *
 * \param[in]      key_id      Implementation-defined key identifier.
 * \param[in,out]  packet      Packet whose payload is decrypted in-place after
 *                             authenticating the metadata.
 * \param[in]      packet_size Total size of \p packet in bytes.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_DECRYPTION_FAILED or a
 *         validation error otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_decrypt_packet(uint32_t key_id, struct sfcp_packet_t *packet,
                                                     size_t packet_size);

/**
 * \brief Save the interrupt mask and disable IRQs for a critical section.
 *
 * \return Cookie to pass back to sfcp_encryption_hal_enable_irq().
 */
uint32_t sfcp_encryption_hal_save_disable_irq(void);

/**
 * \brief Restore a previously saved interrupt mask.
 *
 * \param[in] cookie Cookie returned by sfcp_encryption_hal_save_disable_irq().
 */
void sfcp_encryption_hal_enable_irq(uint32_t cookie);

/**
 * \brief Generate cryptographically strong random data.
 *
 * \param[out] output      Buffer that receives random bytes.
 * \param[in]  output_size Number of bytes requested in \p output.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_GENERATE_RANDOM_FAILURE otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_generate_random(uint8_t *output, size_t output_size);

/**
 * \brief Hash algorithms supported by the platform implementation.
 */
enum sfcp_encryption_hal_hash_alg_t {
    SFCP_ENCRYPTION_HAL_HASH_ALG_SHA256, /**< SHA-256. */
    SFCP_ENCRYPTION_HAL_HASH_ALG_SHA384, /**< SHA-384. */
};

/**
 * \brief Initialize the hash.
 *
 * \param[in] alg Algorithm selector from ::sfcp_encryption_hal_hash_alg_t.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_HASH_ALG_UNSUPPORTED if the
 *         requested algorithm is unavailable; ::SFCP_ERROR_HANDSHAKE_HASH_FAILURE on other errors.
 */
enum sfcp_error_t sfcp_encryption_hal_hash_init(enum sfcp_encryption_hal_hash_alg_t alg);

/**
 * \brief Update the current hash with additional data.
 *
 * \param[in] data      Pointer to the input buffer. May be NULL when \p data_size is zero.
 * \param[in] data_size Number of bytes to hash from \p data.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_HASH_FAILURE otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_hash_update(uint8_t *data, size_t data_size);

/**
 * \brief Finalize the hash and retrieve.
 *
 * \param[out] hash      Output buffer that receives the hash.
 * \param[in]  hash_len  Size of \p hash in bytes.
 * \param[out] hash_size Number of bytes written to \p hash.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_HASH_FAILURE otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_hash_finish(uint8_t *hash, size_t hash_len,
                                                  size_t *hash_size);

/**
 * \brief Create a new session key from the provided seed material.
 *
 * \param[in]  seed          Pointer to the seed buffer.
 * \param[in]  seed_len      Number of bytes in \p seed.
 * \param[out] output_key_id Opaque identifier for the derived key.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_SETUP_SESSION_KEY_FAILURE otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_setup_session_key(uint8_t *seed, size_t seed_len,
                                                        uint32_t *output_key_id);

/**
 * \brief Re-key the session key.
 *
 * \param[in]  seed          Pointer to the seed buffer.
 * \param[in]  seed_len      Number of bytes in \p seed.
 * \param[in]  input_key_id  Identifier for the key being re-keyed.
 * \param[out] output_key_id Identifier for the newly derived key.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_REKEY_SESSION_KEY_FAILURE otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_rekey_session_key(uint8_t *seed, size_t seed_len,
                                                        uint32_t input_key_id,
                                                        uint32_t *output_key_id);

/**
 * \brief Destroy and invalidate a session key.
 *
 * \param[in] key_id Identifier previously returned by the HAL.
 *
 * \return SFCP_ERROR_SUCCESS on success; ::SFCP_ERROR_HANDSHAKE_INVALIDATE_SESSION_KEY_FAILURE
 *         otherwise.
 */
enum sfcp_error_t sfcp_encryption_hal_invalidate_session_key(uint32_t key_id);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_ENCRYPTION_HAL_H__ */

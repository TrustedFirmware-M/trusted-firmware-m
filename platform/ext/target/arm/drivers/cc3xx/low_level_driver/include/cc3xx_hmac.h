/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_HMAC_H__
#define __CC3XX_HMAC_H__

#include <stdint.h>
#include "cc3xx_error.h"
#include "cc3xx_hash.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The size in Bytes, i.e. B, associated to the HMAC block size
 *
 */
#define CC3XX_HMAC_BLOCK_SIZE (64)

/**
 * @brief Contains the state of the HMAC operation
 *
 */
struct cc3xx_hmac_state_t {
    uint32_t key[CC3XX_HMAC_BLOCK_SIZE / sizeof(uint32_t)]; /*!< Buffer containing the key bytes */
    struct cc3xx_hash_state_t hash;     /*!< Allows to restart low-level hash */
    cc3xx_hash_alg_t alg;               /*!< Based on the hashing algorithm, sizes change */
    uint8_t tag_len;                    /*!< Expected tag len, depends on alg */
};

/**
 * @brief Sets the key for the HMAC operation on the state
 *
 * @param[out] state    A pointer to a state structure
 * @param[in]  key      Buffer containing the key
 * @param[in]  key_size Size in bytes of the buffer \p key
 * @param[in]  alg      Underlying hashing algorithm
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_hmac_set_key(
    struct cc3xx_hmac_state_t *state,
    const uint8_t *key,
    size_t key_size,
    cc3xx_hash_alg_t alg);

/**
 * @brief Set tag length for truncated HMAC algorithms. This must be called
 *        after cc3xx_hmac_set_key is called, otherwise the default hash
 *        length will be used instead
 *
 * @param[out] state   A pointer to a state structure
 * @param[in]  tag_len Desired tag length
 */
void cc3xx_lowlevel_hmac_set_tag_length(
    struct cc3xx_hmac_state_t *state,
    size_t tag_len);

/**
 * @brief Update the HMAC operation with a new chunk of data to authenticate
 *
 * @param[in,out] state       A pointer to a state structure
 * @param[in]     data        Buffer containing the data to use for the update
 * @param[in]     data_length Size in bytes of the buffer \p data
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_hmac_update(
    struct cc3xx_hmac_state_t *state,
    const uint8_t *data,
    size_t data_length);

/**
 * @brief Finalize the HMAC operation by producing the authentication tag
 *
 * @param[in,out] state    A pointer to a state structure
 * @param[out]    tag      Output buffer
 * @param[in]     tag_size Size in bytes of the buffer \p tag
 * @param[out]    tag_len  Length of the generated tag
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_hmac_finish(
    struct cc3xx_hmac_state_t *state,
    uint32_t *tag,
    size_t tag_size,
    size_t *tag_len);

/**
 * @brief Perform the computation of HMAC as an integrated operation. When
 *        this function is normally called by the PSA MAC API layer, the
 *        cc3xx_psa_api_config.h must have the configuration option named
 *        \ref CC3XX_CONFIG_ENABLE_MAC_INTEGRATED_API must be set, otherwise
 *        the MAC layer resorts to using multipart APIs to implement single part
 *
 * @param[in]  tag_len     Desired tag length (i.e. truncates the hash output to leftmost N bits)
 * @param[in]  key         Buffer containing the key material
 * @param[in]  key_size    Size in bytes of the key to be used
 * @param[in]  alg         Hash algorithm to be used in HMAC, as a \ref cc3xx_hash_alg_t type
 * @param[in]  data        Data to be authenticated
 * @param[in]  data_length Size in bytes of the data to be authenticated
 * @param[out] tag         Buffer that contains the MAC produced if the operation succeeds
 * @param[in]  tag_size    Size in byte of the \ref tag buffer
 * @param[out] tag_length  Size in bytes of the produced tag (i.e. depends on the underlying hash)
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_hmac_compute(
    size_t tag_len,
    const uint8_t *key,
    size_t key_size,
    cc3xx_hash_alg_t alg,
    const uint8_t *data,
    size_t data_length,
    uint32_t *tag,
    size_t tag_size,
    size_t *tag_length);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_HMAC_H__ */

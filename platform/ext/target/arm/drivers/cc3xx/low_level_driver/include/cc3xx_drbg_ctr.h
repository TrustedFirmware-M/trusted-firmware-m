/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_DRBG_CTR_H__
#define __CC3XX_DRBG_CTR_H__

#include "cc3xx_error.h"
#include "cc3xx_aes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief CTR mode uses AES only as underlying block cipher
 *
 */
#define CC3XX_DRBG_CTR_BLOCKLEN (AES_BLOCK_SIZE)

/**
 * @brief CTR mode uses AES-128 only as underlying block cipher
 *
 */
#define CC3XX_DRBG_CTR_KEYLEN (16)

/**
 * @brief AES-128 key length in words, as used by the CTR_DRBG module
 *
 */
#define CC3XX_DRBG_CTR_KEYLEN_WORDS ((CC3XX_DRBG_CTR_KEYLEN)/(4))

/**
 * @brief CTR mode uses AES only as underlying block cipher, and this
 *        define provides the value of the AES block length in words
 *
 */
#define CC3XX_DRBG_CTR_BLOCKLEN_WORDS ((CC3XX_DRBG_CTR_BLOCKLEN)/(4))

/**
 * @brief CTR_DRBG defines SEEDLEN as BLOCKLEN + KEYLEN
 *
 */
#define CC3XX_DRBG_CTR_SEEDLEN (CC3XX_DRBG_CTR_BLOCKLEN + CC3XX_DRBG_CTR_KEYLEN)

/**
 * @brief CTR_DRBG defines SEEDLEN as BLOCKLEN + KEYLEN (This is in words)
 *
 */
#define CC3XX_DRBG_CTR_SEEDLEN_WORDS (CC3XX_DRBG_CTR_BLOCKLEN_WORDS + CC3XX_DRBG_CTR_KEYLEN_WORDS)

/**
 * @brief Contains the state of the CTR_DRBG
 *
 */
struct cc3xx_drbg_ctr_state_t {
    uint32_t key_k[CC3XX_DRBG_CTR_KEYLEN_WORDS];
    uint32_t block_v[CC3XX_DRBG_CTR_BLOCKLEN_WORDS];
    uint32_t reseed_counter;
};

/**
 * @brief Instantiate the CTR_DRBG
 *
 * @param[out] state              A pointer to a state structure
 * @param[in] entropy             Buffer containing the entropy for the instantiation
 * @param[in] entropy_len         Size in bytes of the entropy buffer \p entropy
 * @param[in] nonce               Buffer containing the nonce
 * @param[in] nonce_len           Size in bytes of the nonce buffer \p nonce
 * @param[in] personalization     Buffer containing the personalization string
 * @param[in] personalization_len Size in bytes of the personalization buffer \p personalization
 *
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_ctr_init(
    struct cc3xx_drbg_ctr_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len);

/**
 * @brief Generates random bits from the CTR_DRBG instance
 *
 * @param[in,out] state            Pointer to an instantiated CTR_DRBG generator
 * @param[in] len_bits             Size in bits to be generated. Must be byte aligned for simplicity
 * @param[out] returned_bits       Pointer where the random bits will be written to
 * @param[in] additional_input     Pointer to the additional input to be used
 * @param[in] additional_input_len Size in bytes of the additional input to be used
 *
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_ctr_generate(
    struct cc3xx_drbg_ctr_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Reseeds the CTR_DRBG
 *
 * @param[in,out] state            A pointer to a state structure
 * @param[in] entropy              Entropy to be used for reseeding
 * @param[in] entropy_len          Size in bytes of the entropy pointed by  \p entropy
 * @param[in] additional_input     Optional pointer containing additional input for reseeding
 * @param[in] additional_input_len Size in bytes of the buffer pointed by \p additional_input
 *
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_ctr_reseed(
    struct cc3xx_drbg_ctr_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Un-initializes the state structure associated to the CTR_DRBG
 *
 * @param[out] state Pointer to the state structure
 *
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_ctr_uninit(
    struct cc3xx_drbg_ctr_state_t *state);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_DRBG_CTR_H__ */

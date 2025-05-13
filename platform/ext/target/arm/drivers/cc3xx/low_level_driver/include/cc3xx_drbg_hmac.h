/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_DRBG_HMAC_H__
#define __CC3XX_DRBG_HMAC_H__

#include <stdint.h>
#include "cc3xx_error.h"

#include "cc3xx_hmac.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The assumption is that it will be a multiple of 4. It depends on the
 *        underlying hash function being used, which for the cc3xx driver is
 *        restricted to SHA-256
 */
#define CC3XX_DRBG_HMAC_OUTLEN SHA256_OUTPUT_SIZE

/**
 * @brief Contains the state of the HMAC_DRBG
 *
 */
struct cc3xx_drbg_hmac_state_t {
    struct cc3xx_hmac_state_t h;
    uint32_t block_v[CC3XX_DRBG_HMAC_OUTLEN / sizeof(uint32_t)];
    uint32_t key_k[CC3XX_DRBG_HMAC_OUTLEN / sizeof(uint32_t)];
    uint32_t reseed_counter;
};

/**
 * @brief Instantiate the HMAC_DRBG
 *
 * @param[out] state              A pointer to a state structure
 * @param[in] entropy             Buffer containing the entropy for the instantiation
 * @param[in] entropy_len         Size in bytes of the entropy buffer \p entropy
 * @param[in] nonce               Buffer containing the nonce
 * @param[in] nonce_len           Size in bytes of the nonce buffer \p nonce
 * @param[in] personalization     Buffer containing the personalization string
 * @param[in] personalization_len Size in bytes of the personalization buffer \p personalization
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_hmac_instantiate(
    struct cc3xx_drbg_hmac_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len);

/**
 * @brief Generate random bits of data using HMAC_DRBG
 *
 * @param[in,out] state            A pointer to a state structure
 * @param[in] len_bits             Size in bits to be generated. Note that this does not need to be byte aligned.
 * @param[out] returned_bits       Buffer to hold returned bits, must be of size ceil(len_bits/8) bytes
 * @param[in] additional_input     Optional pointer containing the additional input to be added
 * @param[in] additional_input_len Size in bytes of the additional input \p additional_input
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_hmac_generate(
    struct cc3xx_drbg_hmac_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Reseeds the HMAC_DRBG
 *
 * @param[in,out] state            A pointer to a state structure
 * @param[in] entropy              Entropy to be used for reseeding
 * @param[in] entropy_len          Size in bytes of the entropy pointed by \p entropy
 * @param[in] additional_input     Optional pointer containing additional input for reseeding
 * @param[in] additional_input_len Size in bytes of the buffer pointed by \p additional_input
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_hmac_reseed(
    struct cc3xx_drbg_hmac_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Un-initializes the state structure associated to the HMAC_DRBG
 *
 * @param[out] state Pointer to the state structure
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_hmac_uninit(struct cc3xx_drbg_hmac_state_t *state);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_DRBG_HMAC_H__ */

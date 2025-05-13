/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_DRBG_H__
#define __CC3XX_DRBG_H__

/**
 * @file Contains a generic interface towards a DRBG mechanism that
 *       can be chosen at runtime during the instantiation phase of
 *       the DRBG, i.e. when calling cc3xx_drbg_init()
 */

#include <stdint.h>
#include <stddef.h>
#include "cc3xx_error.h"
#include "cc3xx_config.h"

#include "cc3xx_drbg_ctr.h"
#include "cc3xx_drbg_hash.h"
#include "cc3xx_drbg_hmac.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief This enum defines which DRBG mechanism to use. Allowed
 *        values are CC3XX_DRBG_CTR, CC3XX_DRBG_HASH, CC3XX_DRBG_HMAC
 */
typedef enum {
    CC3XX_DRBG_CTR = 0,
    CC3XX_DRBG_HMAC,
    CC3XX_DRBG_HASH,
    CC3XX_DRBG_MAX = CC3XX_DRBG_HASH + 1,
} cc3xx_drbg_id_t;

/**
 * @brief Generic context for a DRBG generator
 *
 */
struct cc3xx_drbg_state_t {
    cc3xx_drbg_id_t id;
    union {
        struct cc3xx_drbg_ctr_state_t ctr;
        struct cc3xx_drbg_hmac_state_t hmac;
        struct cc3xx_drbg_hash_state_t hash;
    };
};

/**
 * @brief Instantiate the DRBG
 *
 * @param[in] id                  The ID of the DRBG to instantiate, of type \ref cc3xx_drbg_id_t
 * @param[out] state              A pointer to a state structure
 * @param[in] entropy             Buffer containing the entropy for the instantiation
 * @param[in] entropy_len         Size in bytes of the entropy buffer \p entropy
 * @param[in] nonce               Buffer containing the nonce
 * @param[in] nonce_len           Size in bytes of the nonce buffer \p nonce
 * @param[in] personalization     Buffer containing the personalization string
 * @param[in] personalization_len Size in bytes of the personalization buffer \p personalization
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_init(
    cc3xx_drbg_id_t id,
    struct cc3xx_drbg_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len);

/**
 * @brief Generates random bits from the DRBG instance
 *
 * @param[in,out] state            Pointer to an instantiated DRBG generator
 * @param[in] len_bits             Size in bits to be generated. Must be byte aligned for simplicity
 * @param[out] returned_bits       Pointer holding the returned random bit string
 * @param[in] additional_input     Pointer to the additional input to be used
 * @param[in] additional_input_len Size in bytes of the additional input to be used
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_generate(
    struct cc3xx_drbg_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Reseeds the DRBG
 *
 * @param[in,out] state            A pointer to a state structure
 * @param[in] entropy              Entropy to be used for reseeding
 * @param[in] entropy_len          Size in bytes of the entropy pointed by \p entropy
 * @param[in] additional_input     Optional pointer containing additional input for reseeding
 * @param[in] additional_input_len Size in bytes of the buffer pointed by \p additional_input
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_reseed(
    struct cc3xx_drbg_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len);

/**
 * @brief Un-initializes the state structure associated to the underlying DRBG
 *
 * @param[out] state Pointer to the structure
 * @return cc3xx_err_t
 */
cc3xx_err_t cc3xx_lowlevel_drbg_uninit(struct cc3xx_drbg_state_t *state);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_DRBG_H__ */

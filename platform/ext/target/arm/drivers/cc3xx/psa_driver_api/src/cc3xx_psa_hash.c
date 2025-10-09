/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_psa_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "cc3xx_psa_hash.h"
#include "cc3xx_crypto_primitives_private.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_misc.h"

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "mbedtls/build_info.h"

/**
 * @brief Map a PSA hash algorithm to the corresponding CC3xx hash algorithm and digest size.
 *
 * @param[in]  alg         PSA algorithm identifier.
 * @param[out] hash_alg    Non-NULL pointer that receives the CC3xx hash
 *                         algorithm selector on success.
 * @param[out] hash_length Optional pointer that, when non-NULL, receives the
 *                         digest length in bytes for the selected algorithm.
 *                         On unsupported algorithms, @c *hash_length is set to 0.
 *
 * @retval PSA_SUCCESS             The algorithm was recognized and mapped; outputs set.
 * @retval PSA_ERROR_NOT_SUPPORTED The algorithm is disabled at build time or has no
 *                                 CC3xx mapping; @c *hash_length is set to 0 and
 *                                 @p hash_alg is left unmodified.
 */
static psa_status_t psa_to_cc3xx_hash_alg_and_size(psa_algorithm_t alg,
                                                   cc3xx_hash_alg_t *hash_alg,
                                                   size_t *hash_length)
{
    psa_status_t status = PSA_SUCCESS;
    size_t cc3xx_length;

    assert(hash_alg != NULL);

    switch (alg) {
#if defined(PSA_WANT_ALG_SHA_1)
    case PSA_ALG_SHA_1:
        *hash_alg = CC3XX_HASH_ALG_SHA1;
        cc3xx_length = SHA1_OUTPUT_SIZE;
        break;
#endif /* PSA_WANT_ALG_SHA_1 */
#if defined(PSA_WANT_ALG_SHA_224)
    case PSA_ALG_SHA_224:
        *hash_alg = CC3XX_HASH_ALG_SHA224;
        cc3xx_length = SHA224_OUTPUT_SIZE;
        break;
#endif /* PSA_WANT_ALG_SHA_224 */
#if defined(PSA_WANT_ALG_SHA_256)
    case PSA_ALG_SHA_256:
        *hash_alg = CC3XX_HASH_ALG_SHA256;
        cc3xx_length = SHA256_OUTPUT_SIZE;
        break;
#endif /* PSA_WANT_ALG_SHA_256 */
#if defined(PSA_WANT_ALG_SHA_384)
    case PSA_ALG_SHA_384:
#endif /* PSA_WANT_ALG_SHA_384 */
#if defined(PSA_WANT_ALG_SHA_512)
    case PSA_ALG_SHA_512:
#endif /* PSA_WANT_ALG_SHA_512 */
    default:
        cc3xx_length = 0;
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (hash_length != NULL) {
        *hash_length = cc3xx_length;
    }

    return status;
}

/** @defgroup psa_hash PSA driver entry points for hashing
 *
 *  Entry points for hashing operations as described by the PSA Cryptoprocessor
 *  Driver interface specification
 *
 *  @{
 */
psa_status_t cc3xx_hash_setup(cc3xx_hash_operation_t *operation,
                              psa_algorithm_t alg)
{
    cc3xx_err_t err;
    cc3xx_hash_alg_t hash_alg;
    psa_status_t status;

    CC3XX_ASSERT(operation != NULL);

    status = psa_to_cc3xx_hash_alg_and_size(alg, &hash_alg, NULL);
    if (status != PSA_SUCCESS) {
        return status;
    }

    err = cc3xx_lowlevel_hash_init(hash_alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return cc3xx_to_psa_err(err);
    }

    cc3xx_lowlevel_hash_get_state(&operation->ctx);

    cc3xx_lowlevel_hash_uninit();

    return PSA_SUCCESS;
}

psa_status_t cc3xx_hash_clone(const cc3xx_hash_operation_t *source_operation,
                              cc3xx_hash_operation_t *target_operation)
{
    CC3XX_ASSERT(source_operation != NULL);
    CC3XX_ASSERT(target_operation != NULL);

    memcpy(target_operation, source_operation, sizeof(cc3xx_hash_operation_t));

    return PSA_SUCCESS;
}

psa_status_t cc3xx_hash_update(cc3xx_hash_operation_t *operation,
                               const uint8_t *input, size_t input_length)
{
    cc3xx_err_t err;

    CC3XX_ASSERT(operation != NULL);

    if (input_length == 0) {
        /* This is a valid situation, no need to call cc3xx_hash_update.
         * cc3xx_hash_finish will produce the result.
         */
        return PSA_SUCCESS;
    }

    /* if len not zero, but pointer is NULL */
    CC3XX_ASSERT(input != NULL);

    cc3xx_lowlevel_hash_set_state(&operation->ctx);

    err = cc3xx_lowlevel_hash_update(input, input_length);

    if (err != CC3XX_ERR_SUCCESS) {
        return cc3xx_to_psa_err(err);
    }

    cc3xx_lowlevel_hash_get_state(&operation->ctx);

    cc3xx_lowlevel_hash_uninit();

    return PSA_SUCCESS;
}

psa_status_t cc3xx_hash_finish(cc3xx_hash_operation_t *operation,
                               uint8_t *hash,
                               size_t hash_size, size_t *hash_length)
{
    CC3XX_ASSERT(operation != NULL);
    CC3XX_ASSERT(hash_length != NULL);

    cc3xx_lowlevel_hash_set_state(&operation->ctx);

    switch (operation->ctx.alg) {
    case CC3XX_HASH_ALG_SHA1:
        *hash_length = SHA1_OUTPUT_SIZE;
        break;
    case CC3XX_HASH_ALG_SHA224:
        *hash_length = SHA224_OUTPUT_SIZE;
        break;
    case CC3XX_HASH_ALG_SHA256:
        *hash_length = SHA256_OUTPUT_SIZE;
        break;
    default:
        *hash_length = 0; /* This can't happen if the object has not been tampered with */
        return PSA_ERROR_CORRUPTION_DETECTED;
    }

    if (hash_size < *hash_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    cc3xx_lowlevel_hash_finish((uint32_t *)hash, hash_size);

    return PSA_SUCCESS;
}

psa_status_t cc3xx_hash_abort(cc3xx_hash_operation_t *operation)
{
    cc3xx_secure_erase_buffer((uint32_t *)operation, sizeof(cc3xx_hash_operation_t) / sizeof(uint32_t));
    return PSA_SUCCESS;
}

psa_status_t cc3xx_hash_compute(psa_algorithm_t alg, const uint8_t *input,
                                size_t input_length, uint8_t *hash,
                                size_t hash_size, size_t *hash_length)
{
    cc3xx_hash_alg_t hash_alg;
    cc3xx_err_t err;
    psa_status_t status;

    status = psa_to_cc3xx_hash_alg_and_size(alg, &hash_alg, hash_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    err = cc3xx_lowlevel_hash_init(hash_alg);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    err = cc3xx_lowlevel_hash_update(input, input_length);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_finish((uint32_t *)hash, hash_size);

out:
    if (err != CC3XX_ERR_SUCCESS) {
        *hash_length = 0;
        return cc3xx_to_psa_err(err);
    }

    return PSA_SUCCESS;
}
/** @} */ // end of psa_hash

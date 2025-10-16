/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_psa_random.c
 *
 * This file contains the implementations of the entry points associated to the
 * random generation capability as described by the PSA Cryptoprocessor Driver
 * interface specification.
 */
#ifndef CC3XX_PSA_API_CONFIG_FILE
#include "cc3xx_psa_api_config.h"
#else
#include CC3XX_PSA_API_CONFIG_FILE
#endif

#include "cc3xx_psa_random.h"
#include "cc3xx_misc.h"
#include "cc3xx_error.h"
#include "cc3xx_rng.h"

/** @defgroup psa_random PSA driver entry points for collecting random
 *                       numbers generated using an underlying DRBG
 *                       mechanism
 *
 *  Entry points random init, add_entropy and collection as described by
 *  the PSA Cryptoprocessor Driver interface specification.
 *
 *  @{
 */
psa_status_t cc3xx_init_random(cc3xx_random_context_t *context)
{
    return PSA_ERROR_NOT_SUPPORTED;
}


psa_status_t cc3xx_add_entropy(cc3xx_random_context_t *context, const uint8_t *entropy,
                               size_t entropy_size)
{
    return PSA_ERROR_NOT_SUPPORTED;
}


psa_status_t cc3xx_internal_get_random(uint8_t *output, size_t output_size, size_t *output_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
/* As of mbed TLS 3.5, there is no support in the Core for the random entry points,
 * so the integration happens through the definition of MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG
 * as the function that mbed TLS uses to retrieve random numbers from an external
 * generator. Note that we don't rely on redefining the type
 * mbedtls_psa_external_random_context_t available to the PSA Crypto core to make
 * keep integration simple, as there is no real gain in doing that.
 */
psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    cc3xx_err_t err;

    (void)context; /* The driver keeps the state internal for simplicity */

    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    err = cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_DRBG);

    *output_length = (err == CC3XX_ERR_SUCCESS) ? output_size : 0;

    return cc3xx_to_psa_err(err);
}
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
/** @} */ // end of psa_random

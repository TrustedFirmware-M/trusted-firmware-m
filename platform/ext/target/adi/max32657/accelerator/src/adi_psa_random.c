/*
 * Copyright (C) 2025 Analog Devices, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include "adi_psa_random.h"
#include "trng.h"
#include "mxc_errors.h"

psa_status_t adi_get_random(adi_random_context_t *context,
                            uint8_t *output,
                            size_t output_size,
                            size_t *output_length)
{
    ARG_UNUSED(context);

    int ret;
    ret = MXC_TRNG_Random(output, output_size);

    if (ret != E_NO_ERROR) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *output_length = output_size;
    return PSA_SUCCESS;
}

/* As of mbed TLS 3.6, there is no support in the Core for the random entry points,
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
    psa_status_t status;
    ARG_UNUSED(context);

    if (output == NULL || output_length == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = adi_get_random(NULL, output, output_size, output_length);

    return status;
}

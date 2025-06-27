/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_psa_entropy.c
 *
 * This file contains the implementation of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */
#include <string.h>

#include "cc3xx_psa_entropy.h"
#include "cc3xx_entropy.h"
#include "cc3xx_misc.h"

/** @defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator
 *
 *  @{
 */
psa_status_t cc3xx_get_entropy(uint32_t flags, size_t *estimate_bits,
                               uint8_t *output, size_t output_size)
{
    cc3xx_err_t err;
    /* Integer multiple of entropy size*/
    const size_t int_mult = (output_size / CC3XX_ENTROPY_SIZE) * CC3XX_ENTROPY_SIZE;

    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_size != 0);

    if (estimate_bits != NULL) {
        *estimate_bits = 0;
    }

    /* Get a multiple of CC3XX_ENTROPY_SIZE bytes of entropy */
    err = cc3xx_lowlevel_get_entropy((uint32_t *)output, int_mult);

    if (err != CC3XX_ERR_SUCCESS) {
        return cc3xx_to_psa_err(err);
    }

    if ((output_size % CC3XX_ENTROPY_SIZE) != 0) {
        uint32_t last[CC3XX_ENTROPY_SIZE / sizeof(uint32_t)];
        err = cc3xx_lowlevel_get_entropy(last, sizeof(last));
        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }
        memcpy(&output[int_mult], last, output_size - int_mult);
    }

    if (estimate_bits != NULL) {
        /* The TRNG returns full entropy */
        *estimate_bits = PSA_BYTES_TO_BITS(output_size);
    }

    return PSA_SUCCESS;
}
/** @} */ // end of psa_entropy

/*
 * FixMe: This function is required to integrate into Mbed TLS as the PSA
 * subsystem does not yet support entropy entry points. See the header
 * entropy_poll.h for details. This needs to be revised once Mbed TLS adds
 * support for entropy.
 */
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    (void)data;
    return cc3xx_get_entropy(0, olen, output, len);
}

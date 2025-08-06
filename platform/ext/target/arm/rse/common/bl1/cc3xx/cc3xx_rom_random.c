/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "bl1_random.h"
#include "cc3xx_rng.h"
/* For direct reading of the noise source */
#include "cc3xx_noise_source.h"

int32_t bl1_random_generate_secure(uint8_t *output, size_t output_size)
{
    return cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_DRBG);
}

int32_t bl1_random_generate_fast(uint8_t *output, size_t output_size)
{
    return cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_LFSR);
}

int32_t bl1_random_generate_noise(uint8_t *output, size_t output_size)
{
    uint32_t buf[CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t)];
    cc3xx_err_t err;

    struct cc3xx_noise_source_ctx_t ctx = CC3XX_NOISE_SOURCE_CONTEXT_INIT;
    cc3xx_lowlevel_noise_source_context_init(&ctx);

    err = cc3xx_lowlevel_noise_source_init(&ctx);
    if (err != CC3XX_ERR_SUCCESS) {
        return (int32_t)err;
    }

    for (size_t counter = 0; counter < output_size; counter++) {
        if ((counter % CC3XX_TRNG_SAMPLE_SIZE) == 0) {
            err = cc3xx_lowlevel_noise_source_get_sample(
                    &ctx, buf, sizeof(buf) / sizeof(uint32_t));
            if (err != CC3XX_ERR_SUCCESS) {
                return 1;
            }
        }
        output[counter] = ((uint8_t *)buf)[counter % CC3XX_TRNG_SAMPLE_SIZE];
    }

    cc3xx_lowlevel_noise_source_finish();

    return 0;
}

/*
 * Copyright (c) 2021-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "bl1_random.h"
#include "cc3xx_rng.h"

int32_t bl1_random_generate_secure(uint8_t *output, size_t output_size)
{
    return cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_DRBG);
}

int32_t bl1_random_generate_fast(uint8_t *output, size_t output_size)
{
    return cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_LFSR);
}

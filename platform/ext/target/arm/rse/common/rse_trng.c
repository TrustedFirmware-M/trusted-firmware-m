/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "trng.h"
#include "cc3xx_rng_external_trng.h"

#include <stdint.h>
#include <stddef.h>
#include <string.h>

static inline uint32_t otp_trng_get_random_uint32_t(void)
{
    const volatile uint32_t *rng_ptr = (uint32_t *)0x500A5270;
    return *rng_ptr;
}

cc3xx_err_t trng_init(void)
{
    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t trng_get_random(uint32_t *buf, size_t word_count)
{
    assert(buf != NULL);

    for (size_t idx = 0; idx < word_count; idx++) {
        buf[idx] = otp_trng_get_random_uint32_t();
    }

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t trng_finish(void)
{
    return CC3XX_ERR_SUCCESS;
}

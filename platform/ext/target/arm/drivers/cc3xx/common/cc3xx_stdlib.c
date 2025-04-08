/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_stdlib.h"

#include "cc3xx_rng.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <assert.h>
#include <stdbool.h>

#ifdef CC3XX_CONFIG_STDLIB_EXTERNAL_DPA_HARDENED_WORD_COPY
#include "dpa_hardened_word_copy.h"
#endif

void cc3xx_secure_erase_buffer(uint32_t *buf, size_t word_count)
{
    /* Overwrites the input buffer with random values */
    cc3xx_lowlevel_rng_get_random((uint8_t *)buf, word_count * sizeof(uint32_t),
                                  CC3XX_RNG_FAST);
}

/* The CC3XX driver uses word-aligned copies through this function when required.
 * If DPA mitigations are enabled, the copy shuffles words randomly on copy,
 * otherwise the copy happens linearly on 4-byte aligned boundaries. Note that a
 * platform might require accesses to be 4-byte aligned due to hardware constraints,
 * i.e. when using a KMU to load keys to be used with CryptoCell
 */
#ifndef CC3XX_CONFIG_STDLIB_EXTERNAL_DPA_HARDENED_WORD_COPY
void cc3xx_dpa_hardened_word_copy(volatile uint32_t *dst,
                                  volatile const uint32_t *src, size_t word_count)
{
#if defined(CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE)
    uint8_t permutation_buf[word_count]; /* This is a VLA */
    size_t idx;

    /* We don't support more than 256 word permutations per copy, i.e. 2048 bit copy */
    assert(word_count <= UINT8_MAX);

    cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, word_count,
                                              CC3XX_RNG_FAST);

    for(idx = 0; idx < word_count; idx++) {
        dst[permutation_buf[idx]] = src[permutation_buf[idx]];
    }
#else
    for(size_t idx = 0; idx < word_count; idx++) {
        dst[idx] = src[idx];
    }
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
}
#else
void cc3xx_dpa_hardened_word_copy(volatile uint32_t *dst,
                                  volatile const uint32_t *src, size_t word_count)
{
    /* This is the externally provided implementation for hardened word copy */
    dpa_hardened_word_copy(dst, src, word_count);
}
#endif /* CC3XX_CONFIG_STDLIB_EXTERNAL_DPA_HARDENED_WORD_COPY */

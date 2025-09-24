/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>

#include "dpa_hardened_word_copy.h"

#include "device_definition.h"
#include "cc3xx_rng.h"
#include "fih.h"

#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)

/*
 * These can be tweaked depending on the memory and security requirements.
 * CHUNK_WORD_SIZE = 32 and CHUNK_MAX_COUNT = 16 is enough to cover 2 KiB copy.
 */
#define CHUNK_WORD_SIZE 32
#define CHUNK_MAX_COUNT 16

void dpa_hardened_word_copy(volatile uint32_t *dst,
                             volatile const uint32_t *src, size_t word_count)
{
    static uint8_t permutation_buf[CHUNK_WORD_SIZE];
    static uint8_t chunks_permutation_buf[CHUNK_MAX_COUNT];
    size_t idx;

    assert(word_count <= CHUNK_WORD_SIZE * CHUNK_MAX_COUNT);

    if (!word_count) {
        return;
    }

    if (word_count > CHUNK_WORD_SIZE) {
        /* Split src into chunks */
        size_t chunks = ROUND_UP(word_count, CHUNK_WORD_SIZE) / CHUNK_WORD_SIZE;
        size_t unaligned_words = word_count % CHUNK_WORD_SIZE;

        /* Initializes the permutation buffer */
        for (idx = 0; idx < chunks; idx++) {
            chunks_permutation_buf[idx] = idx;
        }

        cc3xx_lowlevel_rng_get_random_permutation(chunks_permutation_buf, chunks);

        for (idx = 0; idx < chunks; idx++) {
            size_t chunk_idx = chunks_permutation_buf[idx];
            /* Handle a potential last unaligned chunk */
            size_t copy_size = ((chunk_idx == chunks - 1) && !!unaligned_words) ?
                                    unaligned_words : CHUNK_WORD_SIZE;
            size_t copy_shift = chunk_idx * CHUNK_WORD_SIZE;

            fih_delay();
            dpa_hardened_word_copy(dst + copy_shift,
                                    src + copy_shift, copy_size);
            }
    } else {
        /* Initializes the permutation buffer */
        for (idx = 0; idx < word_count; idx++) {
            permutation_buf[idx] = idx;
        }

        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, word_count);

        for(idx = 0; idx < word_count; idx++) {
            fih_delay();
            dst[permutation_buf[idx]] = src[permutation_buf[idx]];
        }
    }
}

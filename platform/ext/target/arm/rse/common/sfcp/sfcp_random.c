/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <stdbool.h>
#include "sfcp_random.h"

struct xorshift_plus_128_state_t {
    uint64_t state[2];
};

static inline void lfsr_seed(struct xorshift_plus_128_state_t *lfsr, uint8_t *seed, size_t seed_len)
{
    if (seed_len < sizeof(lfsr->state)) {
        memcpy(lfsr->state, seed, seed_len);
    } else {
        memcpy(lfsr->state, seed, sizeof(lfsr->state));
    }
}

/* See https://en.wikipedia.org/wiki/Xorshift#xorshift+ */
static uint64_t xorshift_plus_128_lfsr(struct xorshift_plus_128_state_t *lfsr, uint8_t *seed,
                                       size_t seed_len)
{
    uint64_t temp0, temp1;

    lfsr_seed(lfsr, seed, seed_len);

    temp0 = lfsr->state[0];
    temp1 = lfsr->state[1];
    lfsr->state[0] = lfsr->state[1];

    temp0 ^= temp0 << 23;
    temp0 ^= temp0 >> 18;
    temp0 ^= temp1 ^ (temp1 >> 5);

    lfsr->state[1] = temp0;

    return temp0 + temp1;
}

uint64_t sfcp_random_generate_random_lfsr(uint8_t *seed, size_t seed_len)
{
    struct xorshift_plus_128_state_t lfsr = { 0 };

    return xorshift_plus_128_lfsr(&lfsr, seed, seed_len);
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file bl2_pseudo_rng.c
 *
 * \brief Pseudo-RNG implementation for BL2 on MPS2/AN521, which has no
 *        hardware TRNG. Provides random bytes required by MbedTLS RSA
 *        blinding during private key operations (e.g. RSA-OAEP decrypt
 *        for encrypted firmware images).
 *
 * \note  NOT suitable for production use. The AN521 is a development/QEMU
 *        target with dummy provisioning; this PRNG is seeded from a fixed
 *        value and is only meant to unblock RSA operations in BL2.
 */

#include <stdint.h>
#include <string.h>
#include "psa/crypto.h"

#ifdef MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG
/* xoshiro128 state */
static uint32_t s[4];
static int prng_initialised;

static uint32_t rotl(const uint32_t x, int k)
{
    return (x << k) | (x >> (32 - k));
}

static uint32_t xoshiro128ss(void)
{
    const uint32_t result = rotl(s[1] * 5, 7) * 9;
    const uint32_t t = s[1] << 9;

    s[2] ^= s[0];
    s[3] ^= s[1];
    s[1] ^= s[2];
    s[0] ^= s[3];

    s[2] ^= t;
    s[3] = rotl(s[3], 11);

    return result;
}

static void prng_seed(void)
{
    static const uint8_t dummy_seed[16] = {
        0x12, 0x13, 0x23, 0x34, 0x0a, 0x05, 0x89, 0x78,
        0xa3, 0x66, 0x8c, 0x0d, 0x97, 0x55, 0x53, 0xca,
    };

    memcpy(s, dummy_seed, sizeof(s));

    /* Warm up the generator */
    for (int i = 0; i < 20; i++) {
        (void)xoshiro128ss();
    }

    prng_initialised = 1;
}

/*
 * Override the __weak stub in bl2/src/psa_stub_rng.c.
 * This strong definition will be preferred by the linker.
 */
psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    (void)context;
    size_t generated = 0;

    if (!prng_initialised) {
        prng_seed();
    }

    /* Generate 4 bytes at a time */
    while (generated + 4 <= output_size) {
        uint32_t r = xoshiro128ss();
        memcpy(output + generated, &r, 4);
        generated += 4;
    }

    /* Handle remaining bytes */
    if (generated < output_size) {
        uint32_t r = xoshiro128ss();
        memcpy(output + generated, &r, output_size - generated);
        generated = output_size;
    }

    if (output_length) {
        *output_length = generated;
    }

    return PSA_SUCCESS;
}
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */

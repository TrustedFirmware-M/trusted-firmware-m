/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_rng.h"

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include "cc3xx_error.h"
#include "cc3xx_dev.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_entropy.h"
#if defined(CC3XX_CONFIG_RNG_DRBG_HMAC)
#include "cc3xx_drbg_hmac.h"
#elif defined(CC3XX_CONFIG_RNG_DRBG_HASH)
#include "cc3xx_drbg_hash.h"
#elif defined(CC3XX_CONFIG_RNG_DRBG_CTR)
#include "cc3xx_drbg_ctr.h"
#endif /* CC3XX_CONFIG_RNG_DRBG_HMAC */

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "fatal_error.h"

#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)

#ifdef CC3XX_CONFIG_RNG_ENABLE
/* Define function pointers to generically access DRBG functionalities */
#if defined(CC3XX_CONFIG_RNG_DRBG_HMAC)
typedef struct cc3xx_drbg_hmac_state_t drbg_state_t;
#elif defined(CC3XX_CONFIG_RNG_DRBG_CTR)
typedef struct cc3xx_drbg_ctr_state_t drbg_state_t;
#elif defined(CC3XX_CONFIG_RNG_DRBG_HASH)
typedef struct cc3xx_drbg_hash_state_t drbg_state_t;
#endif /* CC3XX_CONFIG_RNG_DRBG_HMAC */

typedef cc3xx_err_t (*drbg_init_fn_t)(
    drbg_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len);
typedef cc3xx_err_t (*drbg_generate_fn_t)(
    drbg_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len);
typedef cc3xx_err_t (*drbg_reseed_fn_t)(
    drbg_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len);

/* Static state context of DRBG */
static struct {
    drbg_state_t state;
    bool seed_done;
    const size_t entropy_size;
    const drbg_init_fn_t init;
    const drbg_generate_fn_t generate;
    const drbg_reseed_fn_t reseed;
} g_drbg = {.seed_done =  false,
#if defined(CC3XX_CONFIG_RNG_DRBG_HMAC)
    .entropy_size = CC3XX_ENTROPY_SIZE,
    .init = cc3xx_lowlevel_drbg_hmac_instantiate,
    .generate = cc3xx_lowlevel_drbg_hmac_generate,
    .reseed = cc3xx_lowlevel_drbg_hmac_reseed};
#elif defined(CC3XX_CONFIG_RNG_DRBG_CTR)
    .entropy_size = CC3XX_DRBG_CTR_SEEDLEN,
    .init = cc3xx_lowlevel_drbg_ctr_init,
    .generate = cc3xx_lowlevel_drbg_ctr_generate,
    .reseed = cc3xx_lowlevel_drbg_ctr_reseed};
#elif defined(CC3XX_CONFIG_RNG_DRBG_HASH)
    .entropy_size = CC3XX_ENTROPY_SIZE,
    .init = cc3xx_lowlevel_drbg_hash_init,
    .generate = cc3xx_lowlevel_drbg_hash_generate,
    .reseed = cc3xx_lowlevel_drbg_hash_reseed};
#endif /* CC3XX_CONFIG_RNG_DRBG_HMAC */

typedef struct {
    union {
        uint64_t state[2];
        uint32_t entropy[CC3XX_ENTROPY_SIZE / sizeof(uint32_t)];
    };
    bool seed_done;
} xorshift_plus_128_state_t;

static xorshift_plus_128_state_t g_lfsr = {.seed_done = false};

static inline void lfsr_seed(xorshift_plus_128_state_t *lfsr)
{
    if (!lfsr->seed_done) {
        while (cc3xx_lowlevel_get_entropy(
                    lfsr->entropy, sizeof(lfsr->entropy)) != CC3XX_ERR_SUCCESS);
        lfsr->seed_done = true;
    }
}

/* See https://en.wikipedia.org/wiki/Xorshift#xorshift+ */
static uint64_t xorshift_plus_128_lfsr(xorshift_plus_128_state_t *lfsr)
{
    uint64_t temp0, temp1;

    lfsr_seed(lfsr);

    temp0 = lfsr->state[0];
    temp1 = lfsr->state[1];
    lfsr->state[0] = lfsr->state[1];

    temp0 ^= temp0 << 23;
    temp0 ^= temp0 >> 18;
    temp0 ^= temp1 ^ (temp1 >> 5);

    lfsr->state[1] = temp0;

    return temp0 + temp1;
}

static cc3xx_err_t drbg_get_random(uint8_t *buf, size_t length)
{
    cc3xx_err_t err;
    uint32_t entropy[ROUND_UP(g_drbg.entropy_size, CC3XX_ENTROPY_SIZE) / sizeof(uint32_t)];

    if (!g_drbg.seed_done) {

        /* Get entropy to initialize DRBG state */
        while (cc3xx_lowlevel_get_entropy(
                    entropy, sizeof(entropy)) != CC3XX_ERR_SUCCESS);

        /* Call the seeding API of the desired drbg */
        err = g_drbg.init(&g_drbg.state,
                    (const uint8_t *)entropy, g_drbg.entropy_size, NULL, 0, NULL, 0);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* Clear the seed from the stack */
        memset(entropy, 0, sizeof(entropy));

        g_drbg.seed_done = true;
    }

    /* Add re-seeding capabilities */
    if (g_drbg.state.reseed_counter == UINT32_MAX) {

        /* Get entropy to re-seed DRBG state */
        while (cc3xx_lowlevel_get_entropy(
                    entropy, sizeof(entropy)) != CC3XX_ERR_SUCCESS);

        err = g_drbg.reseed(&g_drbg.state,
                    (const uint8_t *)entropy, g_drbg.entropy_size, NULL, 0);

        if (err != CC3XX_ERR_SUCCESS) {
            goto cleanup;
        }

        /* Clear the seed from the stack */
        memset(entropy, 0, sizeof(entropy));
    }

    /* The DRBG requires the number of bits to generate, aligned to byte-sizes */
    err = g_drbg.generate(&g_drbg.state, length * 8, buf, NULL, 0);

cleanup:
    return err;
}

/**
 * @brief Helper function to perform a (possibly) aligned copy of a uint64_t such as the
 *        one that gets generated by the LFSR output
 *
 * @param[out] dst  Destination buffer for the aligned copy, it can be not word-aligned
 * @param[in]  src  Source buffer containing an aligned uint64_t value (must be 8-byte aligned)
 * @param[in]  len  Size in bytes to be copied from \p src into \p dst, must be between 0 and 8
 *
 */
static void lfsr_dword_memcpy(void *dst, const uint64_t *src, size_t len)
{
    /* An helper type to manipulate contents of an aligned uint64_t */
    typedef union {
        uint64_t dword;
        uint32_t word[2];
        uint8_t bytes[8];
    } data64_t;

    const data64_t *src_data = (data64_t *)src;
    const bool dst_is_word_aligned = (((uintptr_t) dst & (sizeof(uint32_t) - 1)) == 0);
    size_t offset = 0;

    assert(len <= sizeof(uint64_t));
    assert(src != NULL);
    assert(dst != NULL);

    /* If the destination buffer is not word-aligned, just fall-back to using
     * memcpy() to copy all the required bytes to be copied
     */
    if (!dst_is_word_aligned) {
        memcpy(dst, src, len);
        return;
    }

    /* For word-aligned requests, handle the copy manually. First if it can be 2 full-word copies */
    if (len == sizeof(uint64_t)) {
        ((uint32_t *)dst)[0] = src_data->word[0];
        ((uint32_t *)dst)[1] = src_data->word[1];
        return;
    }

    /* Otherwise check if we can afford at least 1 full-word copy */
    if (len >= sizeof(uint32_t)) {
        ((uint32_t *)dst)[0] = src_data->word[0];
        len -= sizeof(uint32_t);
        offset = sizeof(uint32_t);
    }

    /* Finish manually copying the remaining bytes */
    for (size_t i = 0; i < len; i++) {
        ((uint8_t *)dst)[offset + i] = src_data->bytes[offset + i];
    }

    return;
}

cc3xx_err_t cc3xx_lowlevel_rng_get_random(uint8_t *buf, size_t length,
                                          enum cc3xx_rng_quality_t quality)
{
    if (buf == NULL) {
        if (length) {
            return CC3XX_ERR_INVALID_INPUT_LENGTH;
        }
        return CC3XX_ERR_SUCCESS;
    }

    switch (quality) {
    case CC3XX_RNG_LFSR:
        while (length) {
            /* Generate 8 random bytes through the LFSR and check how many need copying */
            const uint64_t random = xorshift_plus_128_lfsr(&g_lfsr);
            const size_t len_to_copy = length > sizeof(uint64_t) ? sizeof(random) : length;
            /* Copy the bytes taking alignment contraints in consideration */
            lfsr_dword_memcpy(buf, &random, len_to_copy);
            /* Decrease the length counter until we have copied all the bytes requested */
            length -= len_to_copy;
            buf += len_to_copy;
        }
        return CC3XX_ERR_SUCCESS;

    case CC3XX_RNG_DRBG:
        return drbg_get_random(buf, length);
    default:
        return CC3XX_ERR_RNG_INVALID_RNG;
    }
}

/* As per NIST SP800-90A A.5.1 */
cc3xx_err_t cc3xx_lowlevel_rng_get_random_uint(uint32_t bound, uint32_t *uint,
                                               enum cc3xx_rng_quality_t quality)
{
    uint32_t value;
    uint32_t attempts = 0;
    cc3xx_err_t err;
    uint32_t mask;

    /* Zero is not a sane bound */
    assert(bound != 0);

    /* There are two cases that we need to handle differently, the one where we
     * have a single bit set, and the one where we have multiple. First check
     * which we have.
     */
    if ((bound & (bound - 1)) == 0) {
        /* If a single bit is set, we can get the mask by subtracting one */
        mask = bound - 1;
    } else {
        /* Else, we shift the all-one word right until it matches the offset of
         * the leading one-bit in the bound.
         */
        mask = UINT32_MAX >> __builtin_clz(bound);
    }

    do {
        err = cc3xx_lowlevel_rng_get_random((uint8_t *)&value, sizeof(value), quality);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        value &= mask;

        attempts += 1;
        if (attempts >= CC3XX_CONFIG_RNG_MAX_ATTEMPTS) {
            FATAL_ERR(CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS);
            return CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS;
        }
    } while (value >= bound);

    *uint = value;

    return CC3XX_ERR_SUCCESS;
}

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
/* https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle. This returns a
 * uniformly random permutation, verified by experiment.
 */
static void fisher_yates_shuffle(uint8_t *permutation_buf, size_t len,
                                 enum cc3xx_rng_quality_t quality)
{
    uint32_t idx;
    uint32_t swap_idx;
    uint8_t temp_elem;
    cc3xx_err_t err;

    if (len == 0) {
        return;
    }

    for (idx = 0; idx <= len - 1; idx++) {
        err = cc3xx_lowlevel_rng_get_random_uint(len - idx, &swap_idx, quality);
        if (err != CC3XX_ERR_SUCCESS) {
            continue;
        }

        swap_idx += idx;
        temp_elem = permutation_buf[idx];
        permutation_buf[idx] = permutation_buf[swap_idx];
        permutation_buf[swap_idx] = temp_elem;
    }
}
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

void cc3xx_lowlevel_rng_get_random_permutation(uint8_t *permutation_buf, size_t len)
{
    uint32_t idx;

    /* Initializes the permutation buffer */
    for (idx = 0; idx < len; idx++) {
        permutation_buf[idx] = idx;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    fisher_yates_shuffle(permutation_buf, len, CC3XX_RNG_LFSR);
#endif
}
#endif /* CC3XX_CONFIG_RNG_ENABLE */

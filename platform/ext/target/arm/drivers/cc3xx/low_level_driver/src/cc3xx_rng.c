/*
 * Copyright (c) 2021-2025, The TrustedFirmware-M Contributors. All rights reserved.
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

#ifdef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
#include "cc3xx_rng_external_trng.h"
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifdef CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT
int32_t count_zero_bits_external(uint8_t *, size_t, uint32_t *);
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT */

/* Specific defines required to enable Continuous testing as per NIST SP800-90B */
#define BYTES_TO_BITS(x) ((x)*8)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Window size (W) for the Adaptive Proportion Test in SP800-90B section 4.4.2
 *
 * @note For binary entropy sources this is fixed to 1024 bits
 *
 */
#define SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE (1024UL)

/**
 * @brief Cutoff rate (C) for the Adaptive Proportion Test in SP800-90B section 4.4.2
 *
 * @note This is computed using the formula:
 *
 *       CRITBINOM(W, power(2,(-H)), 1-a) with W = 1024, a = 2^(-40), H = 0.5 bits/sample
 *
 *       The cutoff rate is chosen such that the probability of observing B identical
 *       samples in an observation window of length W is Pr{B >= C} < a
 */
#define SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE (821UL)

/**
 * @brief Cutoff rate (C) for the Repetition Count Test in SP800-90B section 4.4.1
 *
 * @note  This is computed using the formula:
 *
 *        1 + ceil(-log(2,a) / H) with a = 2^(-40), H = 0.5 bits/sample a
 *
 *        The cutoff rate is chosen such that C is the smallest integer satisfying
 *        a >= 2^(-H * (C-1)), i.e. the probability of getting C consecutive identical
 *        samples is at most a
 */
#define SP800_90B_REPETITION_COUNT_CUTOFF_RATE (81UL)

#ifdef CC3XX_CONFIG_RNG_ENABLE
#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
/* Static context of the TRNG continuous health tests */
static struct health_tests_ctx_t {
    size_t total_bits_count;        /*!< Number of total bits observed for the Adaptive Proportion Test window */
    size_t number_of_0s;            /*!< Number of zeros observed in the Adaptive Proportion Test window */
    size_t number_of_contiguous_0s; /*!< Number of contiguous zeros observed in the Repetition Count Test */
    size_t number_of_contiguous_1s; /*!< Number of contiguous ones observed in the Repetition Count Test */
    bool   continuous;              /*!< Continous Health tests enabled, i.e. both Adaptive Proportion and Repetition Count */
    bool   startup;                 /*!< Indicates whether a full startup test is performed on next call to get_entropy */
} g_trng_tests = {0};

/* See https://en.wikipedia.org/wiki/Hamming_weight */
static size_t popcount32(uint32_t x)
{
    const uint32_t m1  = 0x55555555; /* binary: 0101 ... */
    const uint32_t m2  = 0x33333333; /* binary: 00110011 ... */
    const uint32_t m4  = 0x0f0f0f0f; /* binary:  4 zeros,  4 ones ... */
    const uint32_t h01 = 0x01010101; /* Sum of 256 to the power of 0, 1, 2, 3 ...  */
    x -= (x >> 1) & m1;              /* put count of each 2 bits into those 2 bits */
    x = (x & m2) + ((x >> 2) & m2);  /* put count of each 4 bits into those 4 bits */
    x = (x + (x >> 4)) & m4;         /* put count of each 8 bits into those 8 bits */
    return (x * h01) >> 24;          /* returns left 8 bits of x + (x<<8) + (x<<16) + ... */
}

static cc3xx_err_t count_zero_bits(uint8_t *buf, size_t buf_len, uint32_t *zero_count)
{
#ifndef CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT
    assert((((uintptr_t) buf & 0x3) == 0) && ((buf_len & 0x3) == 0));

    for (size_t i = 0; i < buf_len / sizeof(uint32_t); i++) {
        *zero_count += BYTES_TO_BITS(sizeof(uint32_t)) - popcount32(((uint32_t *)buf)[i]);
    }
    return CC3XX_ERR_SUCCESS;
#else
    return count_zero_bits_external(buf, buf_len, zero_count);
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT */
}

/* SP800-90B section 4.4.1 */
static cc3xx_err_t repetition_count_test(const uint32_t *buf, size_t buf_size, size_t *number_of_contiguous_0s, size_t *number_of_contiguous_1s)
{
    for (size_t idx = 0; idx < buf_size; idx++) {
        uint8_t byte = ((uint8_t *)buf)[idx];
        for (size_t bit = 0; bit < 8; bit++) {
            if ((byte >> bit) & 0x01) {
                (*number_of_contiguous_1s)++;
                *number_of_contiguous_0s = 0;
            } else {
                (*number_of_contiguous_0s)++;
                *number_of_contiguous_1s = 0;
            }
            if (((*number_of_contiguous_0s) == SP800_90B_REPETITION_COUNT_CUTOFF_RATE) ||
                ((*number_of_contiguous_1s) == SP800_90B_REPETITION_COUNT_CUTOFF_RATE)) {
                FATAL_ERR(CC3XX_ERR_RNG_SP800_90B_REPETITION_COUNT_TEST_FAIL);
                return CC3XX_ERR_RNG_SP800_90B_REPETITION_COUNT_TEST_FAIL;
            }
        }
    }

    return CC3XX_ERR_SUCCESS;
}

/* SP800-90B section 4.4.2 */
static cc3xx_err_t adaptive_proportion_test(const uint32_t *buf, size_t buf_size, size_t *total_bits_count, size_t *number_of_0s)
{
    while (buf_size) {

        /* Compute the words that we still have to count until the end of the window */
        const size_t words_left_to_count =
            (SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE - *total_bits_count) / BYTES_TO_BITS(sizeof(uint32_t));
        const size_t bytes_left_to_count = words_left_to_count * sizeof(uint32_t);
        const size_t counted_bytes = MIN(buf_size, bytes_left_to_count);

        count_zero_bits((uint8_t *)buf, counted_bytes, (uint32_t *)number_of_0s);

        *total_bits_count += BYTES_TO_BITS(counted_bytes);
        buf_size -= counted_bytes;

        if (*total_bits_count == SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE) {
            if ((*number_of_0s >= SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE) ||
                ((SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE - *number_of_0s) >=
                                                    SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE)) {
                FATAL_ERR(CC3XX_ERR_RNG_SP800_90B_ADAPTIVE_PROPORTION_TEST_FAIL);
                return CC3XX_ERR_RNG_SP800_90B_ADAPTIVE_PROPORTION_TEST_FAIL;
            } else {
                *number_of_0s = 0;
                *total_bits_count = 0;
            }
        }

        /* Move the buf pointer in case we still have to process bits from this entropy collection */
        buf += counted_bytes / sizeof(uint32_t);
    }

    return CC3XX_ERR_SUCCESS;
}

/* SP800-90B section 4.4 */
static cc3xx_err_t continuous_health_test(const uint32_t *buf, size_t buf_size, struct health_tests_ctx_t *ctx)
{
    cc3xx_err_t err = repetition_count_test(
        buf, buf_size, &(ctx->number_of_contiguous_0s), &(ctx->number_of_contiguous_1s));

    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    return adaptive_proportion_test(buf, buf_size, &(ctx->total_bits_count), &(ctx->number_of_0s));
}

/**
 * @brief To be performed on the first call to get_entropy(),
 *        after the cc3xx_lowlevel_trng_init() is completed
 *
 * @return cc3xx_err_t
 */
static cc3xx_err_t startup_test(size_t entropy_byte_size)
{
    assert(entropy_byte_size == sizeof(P_CC3XX->rng.ehr_data));

    cc3xx_err_t err;
    uint32_t random_bits[entropy_byte_size / sizeof(uint32_t)];

    /* Collects 528 random bytes on startup for testing */
    for (size_t i = 0; i < 22; i++) {
        err = trng_get_random(random_bits, entropy_byte_size / sizeof(uint32_t));
        if (err != CC3XX_ERR_SUCCESS) {
            break;
        }
    }

    return err;
}
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

cc3xx_err_t cc3xx_lowlevel_rng_sp800_90b_mode(bool enable)
{
#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
    if (enable) {
        g_trng_tests = (struct health_tests_ctx_t){.startup = true};
    } else {
        g_trng_tests = (struct health_tests_ctx_t){0};
    }

    cc3xx_lowlevel_trng_sp800_90b_mode(enable);

    return CC3XX_ERR_SUCCESS;
#else
    return CC3XX_ERR_NOT_IMPLEMENTED;
#endif
}

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
    const drbg_init_fn_t init;
    const drbg_generate_fn_t generate;
    const drbg_reseed_fn_t reseed;
} g_drbg = {.seed_done =  false,
#if defined(CC3XX_CONFIG_RNG_DRBG_HMAC)
    .init = cc3xx_lowlevel_drbg_hmac_instantiate,
    .generate = cc3xx_lowlevel_drbg_hmac_generate,
    .reseed = cc3xx_lowlevel_drbg_hmac_reseed};
#elif defined(CC3XX_CONFIG_RNG_DRBG_CTR)
    .init = cc3xx_lowlevel_drbg_ctr_init,
    .generate = cc3xx_lowlevel_drbg_ctr_generate,
    .reseed = cc3xx_lowlevel_drbg_ctr_reseed};
#elif defined(CC3XX_CONFIG_RNG_DRBG_HASH)
    .init = cc3xx_lowlevel_drbg_hash_init,
    .generate = cc3xx_lowlevel_drbg_hash_generate,
    .reseed = cc3xx_lowlevel_drbg_hash_reseed};
#endif /* CC3XX_CONFIG_RNG_DRBG_HMAC */

typedef struct {
    union {
        uint64_t state[2];
        uint32_t entropy[sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t)];
    };
    bool seed_done;
} xorshift_plus_128_state_t;

static xorshift_plus_128_state_t g_lfsr = {.seed_done = false};

static void seed(xorshift_plus_128_state_t *lfsr)
{
    if (!lfsr->seed_done) {
        cc3xx_err_t err;
        do {
            err = cc3xx_lowlevel_rng_get_entropy(lfsr->entropy, sizeof(lfsr->entropy));
        } while (err != CC3XX_ERR_SUCCESS);

        lfsr->seed_done = true;
    }
}

/* See https://en.wikipedia.org/wiki/Xorshift#xorshift+ */
static uint64_t xorshift_plus_128_lfsr(xorshift_plus_128_state_t *lfsr)
{
    uint64_t temp0, temp1;

    seed(lfsr);

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
    uint32_t entropy[sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t)];

    if (!g_drbg.seed_done) {

        /* Get a 24-byte seed from the TRNG */
        err = cc3xx_lowlevel_rng_get_entropy(entropy, sizeof(entropy));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* Call the seeding API of the desired drbg */
        err = g_drbg.init(&g_drbg.state,
                    (const uint8_t *)entropy, sizeof(entropy), NULL, 0, NULL, 0);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* Clear the seed from the stack */
        memset(entropy, 0, sizeof(entropy));

        g_drbg.seed_done = true;
    }

    /* Add re-seeding capabilities */
    if (g_drbg.state.reseed_counter == UINT32_MAX) {

        /* Get a 24-byte seed from the TRNG */
        err = cc3xx_lowlevel_rng_get_entropy(entropy, sizeof(entropy));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        err = g_drbg.reseed(&g_drbg.state,
                    (const uint8_t *)entropy, sizeof(entropy), NULL, 0);

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

cc3xx_err_t cc3xx_lowlevel_rng_get_entropy(uint32_t *entropy, size_t entropy_len)
{
    cc3xx_err_t err;
    size_t num_words = 0;

    assert((entropy_len % sizeof(P_CC3XX->rng.ehr_data)) == 0);

    err = cc3xx_lowlevel_trng_validate_config();
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_trng_init();

    /* This is guarded by the continuous tests define because that is the
     * only type of testing that is being implemented by the startup_test
     * function although the spec allows for startup tests to be extended
     * by vendors if required
     */
#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
    if (g_trng_tests.startup) {
        err = startup_test(sizeof(P_CC3XX->rng.ehr_data));
        if (err != CC3XX_ERR_SUCCESS) {
            goto cleanup;
        }
        g_trng_tests.startup = false;
    }
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

    for (size_t i = 0; i < entropy_len / sizeof(P_CC3XX->rng.ehr_data); i++) {

        err = cc3xx_lowlevel_trng_get_entropy(&entropy[num_words], sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t));
        if (err != CC3XX_ERR_SUCCESS) {
            goto cleanup;
        }

#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
        if (g_trng_tests.continuous) {
            err = continuous_health_test(
                        (uint8_t *)&entropy[num_words], sizeof(P_CC3XX->rng.ehr_data), &g_trng_tests);
            if (err != CC3XX_ERR_SUCCESS) {
                goto cleanup;
            }
        }
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

        num_words += sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t);
    }

cleanup:
    cc3xx_lowlevel_trng_finish();

    return err;
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
    case CC3XX_RNG_FAST:
    {
        const bool request_is_word_aligned = (((uintptr_t) buf & (sizeof(uint32_t) - 1)) == 0);

        while (length) {

            union {
                uint64_t dword;
                uint32_t word[2];
                uint8_t bytes[8];
            } random;

            random.dword = xorshift_plus_128_lfsr(&g_lfsr);

            if (!request_is_word_aligned) {
                const size_t len_to_copy = length < sizeof(random.dword) ? length : sizeof(random.dword);
                memcpy(buf, &random.dword, len_to_copy);
                length -= len_to_copy;
                buf += len_to_copy;
                continue;
            }

            /* For word-aligned requests, handle the copy manually */
            if (length >= sizeof(random.dword)) {
                ((uint32_t *)buf)[0] = random.word[0];
                ((uint32_t *)buf)[1] = random.word[1];
                length -= sizeof(random.dword);
                buf += sizeof(random.dword);
            } else {
                size_t offset = 0;
                if (length >= sizeof(random.word[0])) {
                    ((uint32_t *)buf)[0] = random.word[0];
                    length -= sizeof(random.word[0]);
                    buf += sizeof(random.word[0]);
                    offset = sizeof(random.word[0]);
                }
                for (size_t i = 0; i < length; i++) {
                    buf[i] = random.bytes[offset + i];
                }
                length = 0;
            }

        }
        return CC3XX_ERR_SUCCESS;
    }

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

void cc3xx_lowlevel_rng_get_random_permutation(uint8_t *permutation_buf, size_t len,
                                               enum cc3xx_rng_quality_t quality)
{
    uint32_t idx;

    /* Initializes the permutation buffer */
    for (idx = 0; idx < len; idx++) {
        permutation_buf[idx] = idx;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    fisher_yates_shuffle(permutation_buf, len, quality);
#else
    (void)quality;
#endif
}
#endif /* CC3XX_CONFIG_RNG_ENABLE */

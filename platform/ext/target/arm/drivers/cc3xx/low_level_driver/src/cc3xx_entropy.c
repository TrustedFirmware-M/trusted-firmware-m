/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include "cc3xx_error.h"

#ifdef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
#include "cc3xx_rng_external_trng.h"
#else
#include "cc3xx_noise_source.h"
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "fatal_error.h"

#ifdef CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT
int32_t count_zero_bits_external(uint8_t *, size_t, uint32_t *);
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_ZERO_COUNT */

/* Specific defines required to enable Continuous testing as per NIST SP800-90B */
#define BYTES_TO_BITS(x) ((x)*8)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* Check configuration parameters */
_Static_assert(CC3XX_CONFIG_ENTROPY_WINDOW_SIZE >= 1024,
               "SP800-90B mandates W >= 1024");
_Static_assert(CC3XX_CONFIG_ENTROPY_HIGH_THRESHOLD <=
                   CC3XX_CONFIG_ENTROPY_WINDOW_SIZE,
               "SP800-90B high_threshold can't be > W");
_Static_assert(CC3XX_CONFIG_ENTROPY_REPETITION_COUNT <=
                   CC3XX_CONFIG_ENTROPY_WINDOW_SIZE,
               "SP800-90B repetition_count can't be > W");

/**
 * @brief Window size (W) for the Adaptive Proportion Test in SP800-90B
 *        section 4.4.2
 *
 * @note The spec recommends to observe at least 1024 samples. For binary
 *       entropy sources this is then fixed to 1024 bits
 */
#define SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE (CC3XX_CONFIG_ENTROPY_WINDOW_SIZE)

/**
 * @brief Cutoff rate (C) for the Adaptive Proportion Test in SP800-90B
 *        section 4.4.2
 *
 * @note This is computed using the formula:
 *
 *       C = 1 + CRITBINOM(W, power(2,(-H)), 1-a)
 *       with W = 1024, a = 2^(-40), H = 0.5 bits/sample
 *
 *       The cutoff rate is chosen such that the probability of observing B
 *       identical samples in an observation window of length W is Pr{B >= C} < a
 */
#define SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE (CC3XX_CONFIG_ENTROPY_HIGH_THRESHOLD)

/**
 * @brief Cutoff rate (C) for the Repetition Count Test in SP800-90B
 *        section 4.4.1
 *
 * @note  This is computed using the formula:
 *
 *        C = 1 + ceil(-log(2,a) / H)
 *        with a = 2^(-40), H = 0.5 bits/sample a
 *
 *        The cutoff rate is chosen such that C is the smallest integer
 *        satisfying a >= 2^(-H * (C-1)), i.e. the probability of getting C
 *        consecutive identical samples is at most a
 */
#define SP800_90B_REPETITION_COUNT_CUTOFF_RATE (CC3XX_CONFIG_ENTROPY_REPETITION_COUNT)

/* Static context of the TRNG config used by the entropy module itself */
static struct cc3xx_noise_source_ctx_t g_trng_ctx = CC3XX_NOISE_SOURCE_CONTEXT_INIT;

/* Static configuration item for the entropy source continuous health tests */
static struct {
    uint32_t high_threshold;   /*!< During an observation window W, we do not want to
                                *   observe more than this number of same symbols
                                */
    uint32_t  low_threshold;   /*!< For a binary source, the low_threshold is the
                                *   complementary of the high_threshold wrt the window
                                *   length (W). We don't want to observe less than this
                                *   number of same symbols as that would imply that the
                                *   the other symbol is above the high threshold
                                */
    uint32_t repetition_count; /*!< During an observation window of length W, we
                                *   do not want to see more than repetition_count
                                *   consecutive repetitions
                                */
} g_entropy_tests_config = {
    SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE,
    (SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE -
        SP800_90B_ADAPTIVE_PROPORTION_CUTOFF_RATE),
    SP800_90B_REPETITION_COUNT_CUTOFF_RATE
};

/* Static context of the entropy source continuous health tests */
static struct health_tests_ctx_t {
    size_t total_bits_count;        /*!< Number of total bits observed for the Adaptive Proportion Test window */
    size_t number_of_0s;            /*!< Number of zeros observed in the Adaptive Proportion Test window */
    size_t number_of_contiguous_0s; /*!< Number of contiguous zeros observed in the Repetition Count Test */
    size_t number_of_contiguous_1s; /*!< Number of contiguous ones observed in the Repetition Count Test */
    bool   startup_done;            /*!< Indicates whether a full collection on startup has been done already */
} g_entropy_tests = {0};

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
static cc3xx_err_t repetition_count_test(const uint32_t *buf, size_t word_count,
                                         size_t *number_of_contiguous_0s,
                                         size_t *number_of_contiguous_1s)
{
    for (size_t idx = 0; idx < word_count; idx++) {
        const uint32_t w = buf[idx];

        for (int i = BYTES_TO_BITS(sizeof(uint32_t)) - 1; i >= 0; i--) {
            if ((w >> i) & 0x1UL) {
                (*number_of_contiguous_1s)++;
                *number_of_contiguous_0s = 0;
            } else {
                (*number_of_contiguous_0s)++;
                *number_of_contiguous_1s = 0;
            }
            if (((*number_of_contiguous_0s) == g_entropy_tests_config.repetition_count) ||
                ((*number_of_contiguous_1s) == g_entropy_tests_config.repetition_count)) {
                FATAL_ERR(CC3XX_ERR_RNG_SP800_90B_REPETITION_COUNT_TEST_FAIL);
                return CC3XX_ERR_RNG_SP800_90B_REPETITION_COUNT_TEST_FAIL;
            }
        }
    }

    return CC3XX_ERR_SUCCESS;
}

/* SP800-90B section 4.4.2 */
static cc3xx_err_t adaptive_proportion_test(const uint32_t *buf,
                                            size_t word_count,
                                            size_t *total_bits_count,
                                            size_t *number_of_0s)
{
    size_t buf_size = word_count * sizeof(uint32_t);

    while (buf_size > 0) {

        /* Compute the words that we still have to count until the end of the window */
        const size_t words_left_to_count =
            (SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE - *total_bits_count) / BYTES_TO_BITS(sizeof(uint32_t));
        const size_t bytes_left_to_count = words_left_to_count * sizeof(uint32_t);
        const size_t counted_bytes = MIN(buf_size, bytes_left_to_count);

        count_zero_bits((uint8_t *)buf, counted_bytes, (uint32_t *)number_of_0s);

        *total_bits_count += BYTES_TO_BITS(counted_bytes);
        buf_size -= counted_bytes;

        if (*total_bits_count == SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE) {
            if ((*number_of_0s >= g_entropy_tests_config.high_threshold) ||
                (*number_of_0s <= g_entropy_tests_config.low_threshold)) {
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
static cc3xx_err_t continuous_health_test(const uint32_t *buf,
                                          size_t word_count,
                                          struct health_tests_ctx_t *ctx)
{
    cc3xx_err_t err = repetition_count_test(
        buf, word_count, &(ctx->number_of_contiguous_0s), &(ctx->number_of_contiguous_1s));

    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    return adaptive_proportion_test(buf, word_count,
                                    &(ctx->total_bits_count), &(ctx->number_of_0s));
}

/**
 * @brief To be performed on the first call to get_entropy(),
 *        after the \ref cc3xx_lowlevel_noise_source_init is completed
 *
 * @return cc3xx_err_t
 */
static cc3xx_err_t startup_test(size_t entropy_byte_size)
{
    assert(entropy_byte_size == CC3XX_TRNG_SAMPLE_SIZE);

    cc3xx_err_t err;
    uint32_t random_bits[entropy_byte_size / sizeof(uint32_t)];

    /* Collects 528 sample bytes on startup for testing */
    for (size_t i = 0; i < 22; i++) {
        err = cc3xx_lowlevel_noise_source_get_sample(
            &g_trng_ctx, random_bits, entropy_byte_size / sizeof(uint32_t));
        if (err != CC3XX_ERR_SUCCESS) {
            break;
        }

        err = continuous_health_test(random_bits,
                                     entropy_byte_size / sizeof(uint32_t),
                                     &g_entropy_tests);
        if (err != CC3XX_ERR_SUCCESS) {
            break;
        }
    }

    return err;
}

/*!
 * \defgroup cc3xx_entropy Set of functions implementing the API to access a
 *                         SP800-90B compliant entropy source
 */
/*!@{*/
cc3xx_err_t cc3xx_lowlevel_get_entropy(uint32_t *entropy, size_t entropy_len)
{
    cc3xx_err_t err;
    size_t num_words = 0;
    bool retry = false;

    assert((entropy_len % CC3XX_TRNG_SAMPLE_SIZE) == 0);

    if (!CC3XX_IS_NOISE_SOURCE_CONTEXT_VALID(&g_trng_ctx)) {
        cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);
    }

    do {
        /* Initialise the Noise Source */
        err = cc3xx_lowlevel_noise_source_init(&g_trng_ctx);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        if (!g_entropy_tests.startup_done) {
            /* Perform any required configuration on the Noise Source first */
            cc3xx_lowlevel_noise_source_sp800_90b_mode(&g_trng_ctx);
            /* Perform the extensive collection on startup */
            err = startup_test(CC3XX_TRNG_SAMPLE_SIZE);
            if (err != CC3XX_ERR_SUCCESS) {
                goto cleanup;
            }
            g_entropy_tests.startup_done = true;
        }

        for (size_t i = 0; i < entropy_len / CC3XX_TRNG_SAMPLE_SIZE; i++) {
            /* Get a full reading from the noise source and put it at the right offset */
            err = cc3xx_lowlevel_noise_source_get_sample(
                    &g_trng_ctx, &entropy[num_words], CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t));
            if (err != CC3XX_ERR_SUCCESS) {
                goto cleanup;
            }

            /* The entropy source is always in SP 800-90B mode, i.e. continuosly testing itself */
            err = continuous_health_test(&entropy[num_words],
                                         CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t),
                                         &g_entropy_tests);
            if (err != CC3XX_ERR_SUCCESS) {
                goto cleanup;
            }

            num_words += CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t);
        }

cleanup:
        cc3xx_lowlevel_noise_source_finish();
        if (err != CC3XX_ERR_SUCCESS) {
            retry = cc3xx_lowlevel_noise_source_bump_parameters(&g_trng_ctx);
        }
    } while ((err != CC3XX_ERR_SUCCESS) && retry);

    return err;
}

void *cc3xx_lowlevel_entropy_get_noise_source_ctx(void)
{
    return (void *)&g_trng_ctx;
}

cc3xx_err_t
cc3xx_lowlevel_entropy_sp800_90b_set_config(uint32_t high_threshold,
                                            uint32_t repetition_count)
{
    /* Basic sanitation of the adaptive proportion test cutoff rate */
    if (high_threshold > SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE ||
        high_threshold <= (SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE/2)) {
        return CC3XX_ERR_RNG_SP800_90B_INVALID_THRESHOLD;
    }

    /* Basic sanitation of the repetition count test cutoff rate */
    if (repetition_count > SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE ||
        repetition_count <= 1) {
        return CC3XX_ERR_RNG_SP800_90B_INVALID_THRESHOLD;
    }

    g_entropy_tests_config.high_threshold = high_threshold;
    g_entropy_tests_config.low_threshold = SP800_90B_ADAPTIVE_PROPORTION_WINDOW_SIZE - high_threshold;
    g_entropy_tests_config.repetition_count = repetition_count;

    return CC3XX_ERR_SUCCESS;
}
/*!@}*/

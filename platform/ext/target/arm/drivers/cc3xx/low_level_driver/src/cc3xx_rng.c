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
 *        after the trng_init() is completed
 *
 * @return cc3xx_err_t
 */
typedef cc3xx_err_t (*trng_get_random_fn_t)(uint32_t *, size_t);
static cc3xx_err_t startup_test(trng_get_random_fn_t get_entropy_fn, size_t entropy_byte_size)
{
    assert(entropy_byte_size == sizeof(P_CC3XX->rng.ehr_data));

    cc3xx_err_t err;
    uint32_t random_bits[entropy_byte_size / sizeof(uint32_t)];

    /* Collects 528 random bytes on startup for testing */
    for (size_t i = 0; i < 22; i++) {
        err = get_entropy_fn(random_bits, entropy_byte_size / sizeof(uint32_t));
        if (err != CC3XX_ERR_SUCCESS) {
            break;
        }
    }

    return err;
}
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

static inline uint32_t round_up(uint32_t num, uint32_t boundary)
{
    return (num + boundary - 1) - ((num + boundary - 1) % boundary);
}

/* Define a function pointer to associate to generator functions for
 * enum cc3xx_rng_quality_t that supports buffering random values
 */
typedef cc3xx_err_t (*random_fn_t)(uint32_t *, size_t);

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

/* Static context of the LFSR */
static cc3xx_err_t lfsr_get_random(uint32_t* buf, size_t word_count);

static struct {
    uint32_t buf[sizeof(uint64_t) / sizeof(uint32_t)];
    size_t buf_used_idx;
    bool seed_done;
    random_fn_t fn;
} g_lfsr = {
    .buf_used_idx = sizeof(uint64_t),
    .seed_done = false,
    .fn = lfsr_get_random};

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

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
/**
 * @brief The ROSC config holds the parameters for a ring oscillator (ROSC) from
 *        which entropy is collected by consecutive sampling. It holds the ID of
 *        the ROSC from which to sample and the interval in number of cycles for
 *        consecutive samples
 */
struct rosc_config_t {
    uint32_t subsampling_rate;   /*!< Number of rng_clk cycles between consecutive
                                      ROSC samples */
    enum cc3xx_rng_rosc_id_t id; /*!< Selected ring oscillator (ROSC) */
};

/**
 * @brief Object describing a TRNG configuration. Default values are set at
 *        build time, but can be overridden by calling \a cc3xx_lowlevel_rng_set_config
 *        for the ROSC config, and \a cc3xx_lowlevel_rng_set_debug_control to set
 *        the \a TRNG_DEBUG_CONTROL
 */
static struct {
    struct rosc_config_t rosc;   /*!< The Ring OSCillator configuration    */
    uint32_t debug_control;      /*!< The TRNG_DEBUG_CONTROL configuration */
} g_trng_config = {
    .rosc.subsampling_rate = CC3XX_CONFIG_RNG_SUBSAMPLING_RATE,
    .rosc.id = CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID,
    .debug_control = 0x0UL};

static cc3xx_err_t trng_init(
    enum cc3xx_rng_rosc_id_t rosc_id,
    uint32_t rosc_subsampling_rate,
    uint32_t trng_debug_control)
{
    /* Enable clock */
    P_CC3XX->rng.rng_clk_enable = 0x1U;

    /* reset trng */
    P_CC3XX->rng.rng_sw_reset = 0x1U;

    /* Apparently there's no way to tell that the reset has finished, so just do
     * these things repeatedly until they succeed (and hence the reset has
     * finished). Works because the reset value of SAMPLE_CNT1 is 0xFFFF.
     */
    do {
        /* Enable clock */
        P_CC3XX->rng.rng_clk_enable = 0x1U;

        /* Set subsampling ratio */
        P_CC3XX->rng.sample_cnt1 = rosc_subsampling_rate;

    } while (P_CC3XX->rng.sample_cnt1 != rosc_subsampling_rate);

    /* Temporarily disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Clear the interrupts */
    P_CC3XX->rng.rng_icr = 0x3FU;

    /* Mask all interrupts except EHR_VALID */
    P_CC3XX->rng.rng_imr = 0x3EU;

    /* Select the oscillator ring (And set SOP_SEL to 0x1 as is mandatory) */
    P_CC3XX->rng.trng_config = rosc_id | (0x1U << 2);

    /* Set debug control register for desired bypasses */
    P_CC3XX->rng.trng_debug_control = trng_debug_control;

    /* Enable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x1U;

    return CC3XX_ERR_SUCCESS;
}

static cc3xx_err_t trng_finish(void)
{
    /* Disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Disable clock */
    P_CC3XX->rng.rng_clk_enable = 0x0U;

    return CC3XX_ERR_SUCCESS;
}

static inline void trng_double_subsampling_rate(void)
{
    uint64_t product = (uint64_t)g_trng_config.rosc.subsampling_rate * 2ULL;

    g_trng_config.rosc.subsampling_rate =
        (product > UINT32_MAX) ? UINT32_MAX : (uint32_t)product;
}

static void trng_bump_rosc_id_and_subsampling_rate(void)
{
    if (g_trng_config.rosc.id == CC3XX_RNG_ROSC_ID_3 &&
        g_trng_config.rosc.subsampling_rate == UINT32_MAX) {
        /* Cannot bump further */
        return;
    }

    if (g_trng_config.rosc.id < CC3XX_RNG_ROSC_ID_3) {
        /* For each subsampling rate, bump the rosc id */
        g_trng_config.rosc.id++;
    } else {
        /* Double the subsampling rate when rosc id is at its max*/
        g_trng_config.rosc.id = CC3XX_RNG_ROSC_ID_0;
        trng_double_subsampling_rate();
    }
}

static cc3xx_err_t trng_get_random(uint32_t *buf, size_t word_count)
{
    uint32_t attempt_count = 0;
    uint32_t idx;

    assert(word_count == sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t));

    /* Wait until the RNG has finished. Any status other than 0x1 indicates
     * that either the RNG hasn't finished or a statistical test has been
     * failed.
     */
    do {
        if (P_CC3XX->rng.rng_isr & 0xEU) {
            /* At least one test has failed, the buffer contents aren't random */

            /* Disable random source before resetting the bit counter */
            P_CC3XX->rng.rnd_source_enable = 0x0U;

            /* Reset EHR registers */
            P_CC3XX->rng.rst_bits_counter = 0x1U;

            /* Clear the interrupt bits */
            P_CC3XX->rng.rng_icr = 0x3FU;

            /* Bump the rosc id and subsampling rate */
            trng_bump_rosc_id_and_subsampling_rate();

            /* Restart TRNG */
            trng_init(g_trng_config.rosc.id,
                      g_trng_config.rosc.subsampling_rate,
                      g_trng_config.debug_control);

            attempt_count++;
        }
    } while ((! (P_CC3XX->rng.rng_isr & 0x1U))
             && attempt_count < CC3XX_CONFIG_RNG_MAX_ATTEMPTS);

    if (attempt_count == CC3XX_CONFIG_RNG_MAX_ATTEMPTS) {
        trng_finish();
        FATAL_ERR(CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS);
        return CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS;
    }

    /* Reset EHR register */
    P_CC3XX->rng.rst_bits_counter = 0x1U;

    /* Make sure the interrupt is cleared before the generator is
     * restarted, to avoid a race condition with the hardware
     */
    P_CC3XX->rng.rng_icr = 0xFFFFFFFF;

    /* Reading the EHR_DATA restarts the generator */
    for (idx = 0; idx < sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t); idx++) {
        buf[idx] = P_CC3XX->rng.ehr_data[idx];
    }

#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
    if (g_trng_tests.continuous) {
        return continuous_health_test(buf, sizeof(P_CC3XX->rng.ehr_data), &g_trng_tests);
    }
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

    return CC3XX_ERR_SUCCESS;
}
#endif /* !CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

/* See https://en.wikipedia.org/wiki/Xorshift#xorshift+ */
static cc3xx_err_t xorshift_plus_128_lfsr(uint64_t *res)
{
    cc3xx_err_t err;
    static union {
        uint64_t state[2];
        uint32_t entropy[sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t)];
    } lfsr = {0};
    uint64_t temp0;
    uint64_t temp1;

    if (!g_lfsr.seed_done) {
        /* This function doesn't need to be perfectly random as it is only used
         * for the permutation function, so only seed once per boot.
         */
        err = cc3xx_lowlevel_rng_get_entropy(lfsr.entropy, sizeof(lfsr.entropy));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        g_lfsr.seed_done = true;
    }

    temp0 = lfsr.state[0];
    temp1 = lfsr.state[1];
    lfsr.state[0] = lfsr.state[1];

    temp0 ^= temp0 << 23;
    temp0 ^= temp0 >> 18;
    temp0 ^= temp1 ^ (temp1 >> 5);

    lfsr.state[1] = temp0;

    *res = temp0 + temp1;

    return CC3XX_ERR_SUCCESS;
}

static cc3xx_err_t lfsr_get_random(uint32_t* buf, size_t word_count)
{
    cc3xx_err_t err;
    assert(word_count == sizeof(uint64_t) / sizeof(uint32_t));

    err = xorshift_plus_128_lfsr((uint64_t *) buf);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    return CC3XX_ERR_SUCCESS;
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

        /* Call the seeding API of the drbg_hmac */
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

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
cc3xx_err_t cc3xx_lowlevel_rng_sp800_90b_mode(bool enable)
{
#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
    if (enable) {
        g_trng_tests = (struct health_tests_ctx_t){.startup = true};
    } else {
        g_trng_tests = (struct health_tests_ctx_t){0};
    }

    g_trng_tests.continuous = enable;

    cc3xx_lowlevel_rng_set_hw_test_bypass(true, false, true);

    return CC3XX_ERR_SUCCESS;
#else
    return CC3XX_ERR_NOT_IMPLEMENTED;
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */
}

cc3xx_err_t cc3xx_lowlevel_rng_set_config(enum cc3xx_rng_rosc_id_t rosc_id,
                                          uint32_t subsampling_rate)
{
    if (!((rosc_id >= CC3XX_RNG_ROSC_ID_0) && (rosc_id <= CC3XX_RNG_ROSC_ID_3))) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    g_trng_config.rosc.id = rosc_id;
    g_trng_config.rosc.subsampling_rate = subsampling_rate;

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_rng_set_hw_test_bypass(
    bool bypass_autocorr,
    bool bypass_crngt,
    bool bypass_vnc)
{
    uint32_t hw_entropy_tests_control = 0x0UL;

    hw_entropy_tests_control |= bypass_autocorr ? (1UL << 3) : 0x0UL;
    hw_entropy_tests_control |= bypass_crngt ? (1UL << 2) : 0x0UL;
    hw_entropy_tests_control |= bypass_vnc ? (1UL << 1) : 0x0UL;

    g_trng_config.debug_control = hw_entropy_tests_control;
}
#endif /* !CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

cc3xx_err_t cc3xx_lowlevel_rng_get_entropy(uint32_t *entropy, size_t entropy_len)
{
    cc3xx_err_t err;
    size_t num_words = 0;

    assert((entropy_len % sizeof(P_CC3XX->rng.ehr_data)) == 0);

    if (!g_trng_config.rosc.subsampling_rate) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    trng_init(g_trng_config.rosc.id, g_trng_config.rosc.subsampling_rate, g_trng_config.debug_control);

    /* This is guarded by the continuous tests define because that is the
     * only type of testing that is being implemented by the startup_test
     * function although the spec allows for startup tests to be extended
     * by vendors if required
     */
#if defined(CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE)
    if (g_trng_tests.startup) {
        err = startup_test(trng_get_random, sizeof(P_CC3XX->rng.ehr_data));
        if (err != CC3XX_ERR_SUCCESS) {
            goto cleanup;
        }
        g_trng_tests.startup = false;
    }
#endif /* CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE */

    for (size_t i = 0; i < entropy_len / sizeof(P_CC3XX->rng.ehr_data); i++) {
        err = trng_get_random(&entropy[num_words], sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t));
        if (err != CC3XX_ERR_SUCCESS) {
            goto cleanup;
        }
        num_words += sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t);
    }

cleanup:
    trng_finish();

    return err;
}

cc3xx_err_t cc3xx_lowlevel_rng_get_random(uint8_t* buf, size_t length,
                                          enum cc3xx_rng_quality_t quality)
{
    uint32_t *random_buf;
    size_t *used_idx;
    size_t max_buf_size;
    /* Different values of cc3xx_rng_quality_t use a different generation function */
    random_fn_t random_fn;

    size_t copy_size;
    const bool request_is_word_aligned = (((uintptr_t) buf & 0x3) == 0) &&
                                         ((length & 0x3) == 0);
    cc3xx_err_t err;

    switch (quality) {
    case CC3XX_RNG_FAST:
        random_buf = g_lfsr.buf;
        used_idx = &g_lfsr.buf_used_idx;
        max_buf_size = sizeof(g_lfsr.buf);
        random_fn = g_lfsr.fn;
        break;
    case CC3XX_RNG_DRBG:
        /* When using a DRBG, buffering random values is not suppported, hence just return
         * the generated bits without any special handling of saved bits from previous
         * iterations
         */
        return drbg_get_random(buf, length);
    default:
        return CC3XX_ERR_RNG_INVALID_RNG;
    }

    /* If the request is word-aligned, then throw away some of entropy buf so it
     * itself is aligned and we can use an aligned copy.
     */
    if (request_is_word_aligned) {
        *used_idx = round_up(*used_idx, sizeof(uint32_t));
    }

    while(length > 0) {
        if (*used_idx == max_buf_size) {
            err = random_fn(random_buf, max_buf_size / sizeof(uint32_t));
            if (err != CC3XX_ERR_SUCCESS) {
                return err;
            }
            *used_idx = 0;
        }

        copy_size = max_buf_size - *used_idx < length ?
                    max_buf_size - *used_idx : length;

        if (request_is_word_aligned) {
            /* If we aligned things earlier, then all of these pointers and
             * sizes will stay word aligned
             */
            for (size_t idx = 0; idx < copy_size / sizeof(uint32_t); idx++) {
                ((uint32_t *)buf)[idx] = (random_buf + (*used_idx / sizeof(uint32_t)))[idx];
            }
        } else {
            memcpy(buf, ((uint8_t *)random_buf) + *used_idx, copy_size);
        }
        length -= copy_size;
        buf += copy_size;
        *used_idx += copy_size;
    }

    return CC3XX_ERR_SUCCESS;
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

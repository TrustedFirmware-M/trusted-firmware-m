/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_test_rng.h"
#include "cc3xx_noise_source.h"
#include "cc3xx_rng.h"
#include "cc3xx_dev.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif
#include "cc3xx_test_assert.h"
#include <string.h>
#include "cc3xx_test_utils.h"

#define DUMMY_PATTERN 0xA5A5A5A5

#define CYCLE_COUNTER_TEST_MAX_POOL_SIZE    (CC3XX_TRNG_WORDS_PER_SAMPLE * 8)
#define STRESS_TESTS_MAX_POOL_SIZE          (CC3XX_TRNG_WORDS_PER_SAMPLE * 5)
#define TESTS_N_INTERATIONS    10

#define RNG_SRAM_START_ADDRESS 0

#ifndef __PACKED_ENUM
#define __PACKED_ENUM enum __attribute__((packed))
#endif

__PACKED_ENUM stress_test_id {
    STRESS_TEST_AUTOCORR_ID = 0,
    STRESS_TEST_CRNGT_ID,
    STRESS_TEST_VNC_ID,
    STRESS_TEST_INVALID = 0xFF,
};

struct stress_test_cfg {
    enum stress_test_id id;
    uint32_t subsampling_rate;
    enum cc3xx_noise_source_rosc_id_t rosc_id;
    size_t pool_size;
    size_t n_iterations;
} stress_tests;

/**
 * @note: These tweaks may be platform-specific or depend on the CC version
 *
 */
const struct stress_test_cfg autocorr_test_cfg = {
    .id = STRESS_TEST_AUTOCORR_ID,
    .subsampling_rate = 33,
    .rosc_id = CC3XX_RNG_ROSC_ID_0,
    .pool_size = CC3XX_TRNG_WORDS_PER_SAMPLE * 2,
    .n_iterations = 40
};

const struct stress_test_cfg crngt_test_cfg = {
    .id = STRESS_TEST_CRNGT_ID,
    .subsampling_rate = 17,
    .rosc_id = CC3XX_RNG_ROSC_ID_0,
    .pool_size = STRESS_TESTS_MAX_POOL_SIZE,
    .n_iterations = 200
};

const struct stress_test_cfg vnc_test_cfg = {
    .id = STRESS_TEST_VNC_ID,
    .subsampling_rate = 12,
    .rosc_id = CC3XX_RNG_ROSC_ID_0,
    .pool_size = CC3XX_TRNG_WORDS_PER_SAMPLE * 2,
    .n_iterations = 50
};

static inline void rng_sram_set_addr(uint32_t addr)
{
    P_CC3XX->host_sram.sram_addr = addr;
}

static inline void wait_for_rng_sram_ready(void)
{
    while (!P_CC3XX->host_sram.sram_data_ready);
}

static inline uint32_t rng_sram_read(void)
{
    wait_for_rng_sram_ready();
    return P_CC3XX->host_sram.sram_data;
}

static inline void rng_sram_dummy_read(void)
{
    wait_for_rng_sram_ready();
    (void) P_CC3XX->host_sram.sram_data;
}

static inline void rng_sram_write(uint32_t data)
{
    wait_for_rng_sram_ready();
    P_CC3XX->host_sram.sram_data = data;
}


static void clear_rng_sram(size_t word_count)
{
    /* Clear SRAM */
    rng_sram_set_addr(RNG_SRAM_START_ADDRESS);
    for (size_t idx = 0; idx < word_count; idx++) {
        rng_sram_write(0);
    }
}

static bool is_valid_entropy(const uint32_t *entropy, size_t word_count)
{
    for (size_t idx = 0; idx < word_count; idx++) {
        if (!entropy[idx]) {
            return false;
        }
    }

    return true;
}

static size_t rng_sram_memcmp(size_t sram_offset,
                            uint32_t *src,
                            size_t word_count)
{
    rng_sram_set_addr(sram_offset);

    rng_sram_dummy_read();

    for (size_t idx = 0; idx < word_count; idx++) {
        if (rng_sram_read() != src[idx]) {
            /* Similar to memcpy, non-zero means not a match*/
            return 1;
        }
    }

    return 0;
}

/* Static context of the TRNG config used by the test code itself */
static struct cc3xx_noise_source_ctx_t g_trng_ctx = CC3XX_NOISE_SOURCE_CONTEXT_INIT;

void trng_single_shot_entropy(struct test_result_t *ret)
{
    uint32_t entropy[CC3XX_TRNG_WORDS_PER_SAMPLE];
    cc3xx_err_t err;

    cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);

#ifdef CC3XX_CONFIG_TRNG_DMA
    clear_rng_sram(CC3XX_TRNG_WORDS_PER_SAMPLE);
#endif

    memset(entropy, 0, sizeof(entropy));

    cc3xx_lowlevel_noise_source_init(&g_trng_ctx);

    err = cc3xx_lowlevel_noise_source_get_sample(&g_trng_ctx, entropy, CC3XX_TRNG_WORDS_PER_SAMPLE);
    TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to get entropy");

    cc3xx_lowlevel_noise_source_finish();

    TEST_ASSERT(is_valid_entropy(entropy, CC3XX_TRNG_WORDS_PER_SAMPLE),
                    "Invalid entropy");

#ifdef CC3XX_CONFIG_TRNG_DMA
    TEST_ASSERT(rng_sram_memcmp(RNG_SRAM_START_ADDRESS,
                                entropy,
                                CC3XX_TRNG_WORDS_PER_SAMPLE) == 0,
                    "Entropy don't match RNG SRAM");
#endif

    ret->val = TEST_PASSED;
}

void trng_multi_shot_entropy(struct test_result_t *ret)
{
    uint32_t entropy[CC3XX_TRNG_WORDS_PER_SAMPLE];
    cc3xx_err_t err;

    cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);

#ifdef CC3XX_CONFIG_TRNG_DMA
    clear_rng_sram(CC3XX_RNG_SRAM_SIZE);
#endif

    cc3xx_lowlevel_noise_source_init(&g_trng_ctx);

    for (size_t idx = 0; idx < TESTS_N_INTERATIONS; idx++) {
        memset(entropy, 0, sizeof(entropy));

        err = cc3xx_lowlevel_noise_source_get_sample(&g_trng_ctx, entropy, CC3XX_TRNG_WORDS_PER_SAMPLE);
        TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to get entropy");

        TEST_ASSERT(is_valid_entropy(entropy, CC3XX_TRNG_WORDS_PER_SAMPLE),
                        "Invalid entropy");

#ifdef CC3XX_CONFIG_TRNG_DMA
        TEST_ASSERT(rng_sram_memcmp(RNG_SRAM_START_ADDRESS,
                                    entropy,
                                    CC3XX_TRNG_WORDS_PER_SAMPLE) == 0,
                        "Entropy don't match RNG SRAM");
#endif
    }

    cc3xx_lowlevel_noise_source_finish();

    ret->val = TEST_PASSED;
}

static void trng_cycle_counter_by_pool_size(struct test_result_t *ret, size_t pool_size)
{
    uint32_t entropy[CYCLE_COUNTER_TEST_MAX_POOL_SIZE];
    uint32_t cyccnt_start;
    uint32_t cyccnt_end;
    uint32_t cyccnt_elapsed;
    uint32_t cyccnt_average = 0;
    cc3xx_err_t err;

    TEST_ASSERT(pool_size <= CYCLE_COUNTER_TEST_MAX_POOL_SIZE, "Invalid entropy array size");
    TEST_ASSERT(!(pool_size % CC3XX_TRNG_WORDS_PER_SAMPLE), "Unaligned pool size");

    enable_cycle_counter();

    for (size_t idx = 0; idx < TESTS_N_INTERATIONS; idx++) {
        memset(entropy, 0, pool_size * sizeof(uint32_t));

#ifdef CC3XX_CONFIG_TRNG_DMA
        clear_rng_sram(pool_size);
#endif
        /* To avoid cycle counter overflow */
        reset_cycle_count();

        /* Start Recording */
        cyccnt_start = get_cycle_count();

        /* Generate entropy */
        cc3xx_lowlevel_noise_source_init(&g_trng_ctx);

        /* Collect entropy */
#ifdef CC3XX_CONFIG_TRNG_DMA
        err = cc3xx_lowlevel_noise_source_get_sample(&g_trng_ctx, entropy, pool_size);
        TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to get entropy");
#else
        for (size_t j = 0; j < pool_size / CC3XX_TRNG_WORDS_PER_SAMPLE; j++) {
            size_t offset = j * CC3XX_TRNG_WORDS_PER_SAMPLE;

            err = cc3xx_lowlevel_noise_source_get_sample(&g_trng_ctx, entropy + offset,
                                                 CC3XX_TRNG_WORDS_PER_SAMPLE);
            TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to get entropy");
        }
#endif
        /* Stop Recording */
        cyccnt_end = get_cycle_count();

        /* Turn off TRNG */
        cc3xx_lowlevel_noise_source_finish();

        TEST_ASSERT(is_valid_entropy(entropy, pool_size), "Invalid entropy");

        /* Get elapsed time of generating and collecting the entropy */
        cyccnt_elapsed = cyccnt_end - cyccnt_start;

        /* Elapsed time must be > 0 */
        TEST_ASSERT(cyccnt_elapsed, "Invalid cycle counter");

        /* Accumulate average elapsed time, divide on each iter to avoid overflow */
        cyccnt_average += cyccnt_elapsed / TESTS_N_INTERATIONS;
    }

    TEST_LOG("[TRNG] pool_size: %u, average cycles: %u, time: %u (ms)\n",
                    pool_size, cyccnt_average, cycles_to_ms(cyccnt_average));

    ret->val = TEST_PASSED;
}

void trng_cycle_counter(struct test_result_t *ret)
{
    const size_t pool_sizes[] = {6, 12, 18, CYCLE_COUNTER_TEST_MAX_POOL_SIZE};

    cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);

    for (size_t idx = 0; idx < ARRAY_SIZE(pool_sizes); idx++) {
        trng_cycle_counter_by_pool_size(ret, pool_sizes[idx]);
    }
}

static void drbg_cycle_counter_by_pool_size(struct test_result_t *ret, size_t pool_size)
{
    uint32_t entropy[CYCLE_COUNTER_TEST_MAX_POOL_SIZE];
    uint32_t cyccnt_start;
    uint32_t cyccnt_end;
    uint32_t cyccnt_elapsed;
    uint32_t cyccnt_average = 0;
    cc3xx_err_t err;

    TEST_ASSERT(pool_size <= (sizeof(entropy) / sizeof(uint32_t)),
                    "Invalid entropy array size");

    enable_cycle_counter();

    for (size_t idx = 0; idx < TESTS_N_INTERATIONS; idx++) {
        memset(entropy, 0, pool_size * sizeof(uint32_t));

        /* To avoid cycle counter overflow */
        reset_cycle_count();

        /* Start Recording */
        cyccnt_start = get_cycle_count();

        /* Collect entropy */
        err = cc3xx_lowlevel_rng_get_random((uint8_t *) entropy,
                                            pool_size * sizeof(uint32_t),
                                            CC3XX_RNG_DRBG);

        /* Stop Recording */
        cyccnt_end = get_cycle_count();

        /* Validate TRNG exit error code */
        TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to get entropy");

        TEST_ASSERT(is_valid_entropy(entropy, pool_size), "Invalid entropy");

        /* Get elapsed time of generating and collecting the entropy */
        cyccnt_elapsed = cyccnt_end - cyccnt_start;

        /* Elapsed time must be > 0 */
        TEST_ASSERT(cyccnt_elapsed, "Invalid cycle counter");

        /* Accumulate average elapsed time, divide on each iter to avoid overflow */
        cyccnt_average += cyccnt_elapsed / TESTS_N_INTERATIONS;
    }

    TEST_LOG("[DRBG] pool_size: %u, average cycles: %u, time: %u (ms)\n",
                    pool_size, cyccnt_average, cycles_to_ms(cyccnt_average));

    ret->val = TEST_PASSED;
}

void drbg_cycle_counter(struct test_result_t *ret)
{
    const size_t pool_sizes[] = {6, 12, 18, CYCLE_COUNTER_TEST_MAX_POOL_SIZE};

    /* DRBG uses entropy to initialise its state */
    cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);

    for (size_t idx = 0; idx < ARRAY_SIZE(pool_sizes); idx++) {
        drbg_cycle_counter_by_pool_size(ret, pool_sizes[idx]);
    }
}

#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
/**
 * @note:   this test may hang if cc3xx_lowlevel_rng_get_entropy() fails
 *          and HALT_ON_FATAL_ERRORS is enabled. It is preferable to run
 *          these tests with TFM_HALT_ON_FATAL_ERRORS disabled.
 *
 */
static void trng_errors_stress_test(struct test_result_t *ret,
                                    const struct stress_test_cfg *test_cfg)
{
    uint32_t entropy[STRESS_TESTS_MAX_POOL_SIZE];
    struct cc3xx_noise_source_stats_t stats;
    size_t trng_get_rnd_fails = 0;
    size_t trng_test_stats;
    cc3xx_err_t err;

    err = cc3xx_lowlevel_noise_source_set_config(&g_trng_ctx,
                                                 test_cfg->rosc_id,
                                                 test_cfg->subsampling_rate);
    TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Failed to set TRNG configuration");

    cc3xx_lowlevel_noise_source_clear_stats();

    for (size_t idx = 0; idx < test_cfg->n_iterations; idx++) {
        memset(entropy, 0, sizeof(entropy));

#ifdef CC3XX_CONFIG_TRNG_DMA
        clear_rng_sram(test_cfg->pool_size);
#endif
        cc3xx_lowlevel_noise_source_init(&g_trng_ctx);

        err = cc3xx_lowlevel_noise_source_get_sample(&g_trng_ctx, entropy, test_cfg->pool_size);
        if (err != CC3XX_ERR_SUCCESS) {
            trng_get_rnd_fails++;
            continue;
        }

        cc3xx_lowlevel_noise_source_finish();

        TEST_ASSERT(is_valid_entropy(entropy, test_cfg->pool_size),
                        "Invalid entropy");
    }

    TEST_ASSERT(trng_get_rnd_fails != test_cfg->n_iterations,
                    "TRNG too fast or pool too large");

    cc3xx_lowlevel_noise_source_get_stats(&stats);

    trng_test_stats = (test_cfg->id == STRESS_TEST_AUTOCORR_ID) ? stats.autocorr_err_stats :
                      (test_cfg->id == STRESS_TEST_CRNGT_ID) ? stats.crngt_err_stats :
                      (test_cfg->id == STRESS_TEST_VNC_ID) ? stats.vnc_err_stats :
                      STRESS_TEST_INVALID;

    TEST_ASSERT(trng_test_stats != STRESS_TEST_INVALID, "Invalid test id");

    TEST_LOG("[%u] TRNG errors: %u per %u iterations\n", test_cfg->id,
                                                         trng_test_stats,
                                                         test_cfg->n_iterations);

    TEST_ASSERT(!!trng_test_stats, "No fails");

    /* Restore the default configuration */
    cc3xx_lowlevel_noise_source_context_init(&g_trng_ctx);

    ret->val = TEST_PASSED;
}

void trng_errors_stress_test_autocorr(struct test_result_t *ret)
{
    cc3xx_lowlevel_noise_source_set_hw_test_bypass(&g_trng_ctx,
                                                   CC3XX_TRNG_AUTOCORR_TEST_ACTIVE,
                                                   CC3XX_TRNG_CRNGT_TEST_BYPASS,
                                                   CC3XX_TRNG_VNC_TEST_BYPASS);

    trng_errors_stress_test(ret, &autocorr_test_cfg);
}

void trng_errors_stress_test_crngt(struct test_result_t *ret)
{
    cc3xx_lowlevel_noise_source_set_hw_test_bypass(&g_trng_ctx,
                                                   CC3XX_TRNG_AUTOCORR_TEST_BYPASS,
                                                   CC3XX_TRNG_CRNGT_TEST_ACTIVE,
                                                   CC3XX_TRNG_VNC_TEST_BYPASS);

    trng_errors_stress_test(ret, &crngt_test_cfg);
}

void trng_errors_stress_test_vnc(struct test_result_t *ret)
{
    cc3xx_lowlevel_noise_source_set_hw_test_bypass(&g_trng_ctx,
                                                   CC3XX_TRNG_AUTOCORR_TEST_BYPASS,
                                                   CC3XX_TRNG_CRNGT_TEST_BYPASS,
                                                   CC3XX_TRNG_VNC_TEST_ACTIVE);

    trng_errors_stress_test(ret, &vnc_test_cfg);
}
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */


void rng_sram_rw_test(struct test_result_t *ret)
{
    const size_t word_count = 64;

    /* Clear SRAM */
    clear_rng_sram(word_count);

    /* Write pattern to SRAM */
    rng_sram_set_addr(RNG_SRAM_START_ADDRESS);
    for (size_t idx = 0; idx < word_count; idx++) {
        rng_sram_write(DUMMY_PATTERN);
    }

    /* Last word is null */
    rng_sram_write(0);

    /* Readback pattern from SRAM */
    rng_sram_set_addr(RNG_SRAM_START_ADDRESS);

    /* First read is always dummy */
    rng_sram_dummy_read();

    for (size_t idx = 0; idx < word_count; idx++) {
        uint32_t data = rng_sram_read();

        TEST_ASSERT(data == DUMMY_PATTERN,
                    "RNG SRAM readback failed");
    }

    /* Last word should be null */
    TEST_ASSERT(rng_sram_read() == 0,
            "RNG SRAM last word should be null");

    ret->val = TEST_PASSED;
}

static struct test_t rng_tests[] = {
    {
        &trng_single_shot_entropy,
        "CC3XX_TRNG_SINGLE_SHOT_ENTROPY",
        "CC3XX TRNG Single Entropy",
    },
    {
        &trng_multi_shot_entropy,
        "CC3XX_TRNG_MULTI_SHOT_ENTROPY",
        "CC3XX TRNG Multi Shot Entropy",
    },
    {
        &trng_cycle_counter,
        "CC3XX_TRNG_CYCLE_COUNTER",
        "CC3XX TRNG Cycle counter",
    },
    {
        &drbg_cycle_counter,
        "CC3XX_DRBG_CYCLE_COUNTER",
        "CC3XX DRBG Cycle counter",
    },
#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
    {
        &trng_errors_stress_test_autocorr,
        "CC3XX_TRNG_STRESS_TEST_AUTOCORR",
        "CC3XX TRNG Stress test autocorr",
    },
    {
        &trng_errors_stress_test_crngt,
        "CC3XX_TRNG_STRESS_TEST_CRNGT",
        "CC3XX TRNG Stress test crngt",
    },
    {
        &trng_errors_stress_test_vnc,
        "CC3XX_TRNG_STRESS_TEST_VNC",
        "CC3XX TRNG Stress test vnc",
    },
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */
    {
        &rng_sram_rw_test,
        "CC3XX_RNG_SRAM_RW_TEST",
        "CC3XX RNG SRAM RW test",
    },
};

void add_cc3xx_rng_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
    cc3xx_add_tests_to_testsuite(rng_tests, ARRAY_SIZE(rng_tests), p_ts, ts_size);
}

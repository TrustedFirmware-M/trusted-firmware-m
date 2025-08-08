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

#include "cc3xx_noise_source.h"

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "fatal_error.h"

#ifdef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
#include "cc3xx_rng_external_trng.h"
#endif /* !CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG

#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)

#ifdef CC3XX_CONFIG_TRNG_DMA
#define CC3XX_TRNG_SRAM_SIZE         (2048) /* 2KiB */
#define CC3XX_TRNG_SRAM_SIZE_WORDS   (CC3XX_TRNG_SRAM_SIZE / sizeof(uint32_t))

/* Align the SRAM to sample size for simplicity */
#define CC3XX_TRNG_SRAM_MAX_SAMPLES (CC3XX_TRNG_SRAM_SIZE / CC3XX_TRNG_SAMPLE_SIZE)
#define CC3XX_TRNG_SRAM_MAX_WORDS   (CC3XX_TRNG_SRAM_MAX_SAMPLES * CC3XX_TRNG_WORDS_PER_SAMPLE)
#endif /* CC3XX_CONFIG_TRNG_DMA */

__PACKED_ENUM {
    EHR_VALID_INT = 0,
    AUTOCORR_ERR_INT,
    CRNGT_ERR_INT,
    VN_ERR_INT,
    WATCHDOG_INT,
    RNG_DMA_DONE_INT
};

#define TRNG_ROSC_ID_MASK ((1UL << 2) - 1)

#define TRNG_ERROR_MASK (1 << VN_ERR_INT | 1 << CRNGT_ERR_INT | \
                         1 << AUTOCORR_ERR_INT)

#define TRNG_ISR_MASK   (TRNG_ERROR_MASK | 1 << EHR_VALID_INT | \
                         1 << WATCHDOG_INT | 1 << RNG_DMA_DONE_INT)

#ifdef CC3XX_CONFIG_TRNG_DMA
#define TRNG_DONE_MASK                  (1U << RNG_DMA_DONE_INT)
#define CC3XX_RNG_SRAM_START_OFFSET     0
#else
#define TRNG_DONE_MASK                  (1U << EHR_VALID_INT)
#endif /* CC3XX_CONFIG_TRNG_DMA */

#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
/**
 * @brief When \a CC3XX_CONFIG_TRNG_COLLECT_STATISTICS is set,
 *        the object tracks the statistics collected at each
 *        reading of the TRNG samples
 */
static struct cc3xx_noise_source_stats_t g_trng_stats = {0};
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */

static inline bool is_trng_done(void)
{
    return !!(P_CC3XX->rng.rng_isr & TRNG_DONE_MASK);
}

static inline uint32_t trng_get_errors(void)
{
    return P_CC3XX->rng.rng_isr & TRNG_ERROR_MASK;
}

static void trng_init(
    enum cc3xx_noise_source_rosc_id_t rosc_id,
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
    P_CC3XX->rng.rng_icr = TRNG_ISR_MASK;

    /* Mask all interrupts except RNG_DMA_DONE and EHR_VALID */
    P_CC3XX->rng.rng_imr = 0x1EU;

    /* Set SOP_SEL to 0x1 (mandatory) */
    P_CC3XX->rng.trng_config = 0x1U << 2;

#ifndef CC3XX_CONFIG_TRNG_DMA
    /* Select the oscillator ring */
    P_CC3XX->rng.trng_config |= rosc_id;
#endif

    /* Set debug control register for desired bypasses */
    P_CC3XX->rng.trng_debug_control = trng_debug_control;

    /* Enable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x1U;
}

static void trng_finish(void)
{
    /* Disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Disable clock */
    P_CC3XX->rng.rng_clk_enable = 0x0U;
}

#ifdef CC3XX_CONFIG_TRNG_DMA
static void trng_init_dma(struct cc3xx_noise_source_ctx_t *ctx, size_t sample_count)
{
    /* Fill the RNG SRAM with entropy */
    P_CC3XX->rng.rng_dma_samples_num = sample_count;
    P_CC3XX->rng.rng_dma_sram_addr = 0x0U;
    P_CC3XX->rng.rng_dma_src_mask = 0x1U << ctx->rosc.id;
    P_CC3XX->rng.rng_dma_enable = 0x1U;
}

static void trng_copy_entropy(uint32_t *entropy, size_t word_count)
{
    cc3xx_lowlevel_dma_copy_data_from_rng_sram(entropy,
                                               CC3XX_RNG_SRAM_START_OFFSET,
                                               word_count * sizeof(uint32_t));
}
#else
static void trng_copy_entropy(uint32_t *entropy, size_t word_count)
{
    /* Reading the EHR_DATA restarts the generator */
    for (size_t idx = 0; idx < CC3XX_TRNG_WORDS_PER_SAMPLE; idx++) {
        entropy[idx] = P_CC3XX->rng.ehr_data[idx];
    }
}
#endif /* CC3XX_CONFIG_TRNG_DMA */

static inline uint32_t trng_double_subsampling_rate(uint32_t subsampling_rate)
{
    const uint64_t product = ((uint64_t)subsampling_rate) * 2ULL;

    return (product > UINT32_MAX) ? UINT32_MAX : (uint32_t)product;
}

static bool trng_bump_rosc_id_and_subsampling_rate(uint32_t *rosc_id, uint32_t *rosc_subsampling_rate)
{
    if ((*rosc_id == CC3XX_RNG_ROSC_ID_3) && (*rosc_subsampling_rate == UINT32_MAX)) {
        /* Cannot bump further */
        return false;
    }

    if (*rosc_id < CC3XX_RNG_ROSC_ID_3) {
        /* For each subsampling rate, bump the rosc id */
        (*rosc_id)++;
    } else {
        /* Double the subsampling rate when rosc id is at its max */
        *rosc_id = CC3XX_RNG_ROSC_ID_0;
        *rosc_subsampling_rate = trng_double_subsampling_rate(*rosc_subsampling_rate);
    }

    return true;
}

static bool trng_error_handler(struct cc3xx_noise_source_ctx_t *ctx)
{
    uint32_t trng_errors = trng_get_errors();
    uint32_t rosc_id, rosc_subsampling_rate;
#ifdef CC3XX_CONFIG_TRNG_DMA
    size_t dma_samples_num;
#endif

    if (!trng_errors) {
        /* No errors to handle */
        return false;
    }

#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
    g_trng_stats.autocorr_err_stats += (trng_errors & (1 << AUTOCORR_ERR_INT)) ? 1U : 0;
    g_trng_stats.crngt_err_stats += (trng_errors & (1 << CRNGT_ERR_INT)) ? 1U : 0;
    g_trng_stats.vnc_err_stats += (trng_errors & (1 << VN_ERR_INT)) ? 1U : 0;
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */

#ifdef CC3XX_CONFIG_TRNG_DMA
    /* Get the requested sample count before resetting the TRNG */
    dma_samples_num = P_CC3XX->rng.rng_dma_samples_num;
#endif

    /* Get the ROSC-related config parameters from the TRNG */
    rosc_id = P_CC3XX->rng.trng_config & TRNG_ROSC_ID_MASK;
    rosc_subsampling_rate = P_CC3XX->rng.sample_cnt1;

    /* Disable random source before resetting the bit counter */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Reset the bit counter */
    P_CC3XX->rng.rst_bits_counter = 0x1U;

    /* Clear the interrupt bits */
    P_CC3XX->rng.rng_icr = 0xFFFFFFFF;

    /* Bump the rosc id and subsampling rate, if there is room for it */
    if (trng_bump_rosc_id_and_subsampling_rate(&rosc_id, &rosc_subsampling_rate)) {
        /* Update the TRNG parameters */
        P_CC3XX->rng.trng_config = rosc_id | (0x1U << 2);
        P_CC3XX->rng.sample_cnt1 = rosc_subsampling_rate;
        /* Update the context as well */
        ctx->rosc.id = rosc_id;
        ctx->rosc.subsampling_rate = rosc_subsampling_rate;
    }

    /* Restart TRNG */
    trng_init(
        P_CC3XX->rng.trng_config & TRNG_ROSC_ID_MASK, /* Extract the ROSC_ID from the register */
        P_CC3XX->rng.sample_cnt1,
        P_CC3XX->rng.trng_debug_control);

#ifdef CC3XX_CONFIG_TRNG_DMA
    trng_init_dma(ctx, dma_samples_num);
#endif

    return true;
}

static cc3xx_err_t trng_wait_for_sample(struct cc3xx_noise_source_ctx_t *ctx)
{
    uint32_t attempt_count = 0;

    /* Wait until the TRNG has finished. Any status other than 0x1 indicates
     * that either the TRNG hasn't finished or a statistical test has been
     * failed.
     */
    do {
        if (trng_error_handler(ctx)) {
            attempt_count++;
        }
    } while (!is_trng_done() && attempt_count < CC3XX_CONFIG_RNG_MAX_ATTEMPTS);

    if (attempt_count == CC3XX_CONFIG_RNG_MAX_ATTEMPTS) {
        trng_finish();
        FATAL_ERR(CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS);
        return CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS;
    }

    /* Reset the bit counter */
    P_CC3XX->rng.rst_bits_counter = 0x1U;

    /* Make sure the interrupt is cleared before the generator is
     * restarted, to avoid a race condition with the hardware
     */
    P_CC3XX->rng.rng_icr = 0xFFFFFFFF;

    return CC3XX_ERR_SUCCESS;
}

static cc3xx_err_t trng_get_sample(struct cc3xx_noise_source_ctx_t *ctx, uint32_t *entropy, size_t word_count)
{
    cc3xx_err_t err;

#ifdef CC3XX_CONFIG_TRNG_DMA
    size_t dma_samples_num = ROUND_UP(word_count, CC3XX_TRNG_WORDS_PER_SAMPLE) /
                             CC3XX_TRNG_WORDS_PER_SAMPLE;

    assert(word_count <= CC3XX_TRNG_SRAM_MAX_WORDS);

    trng_init_dma(ctx, dma_samples_num);
#else
    assert(word_count == CC3XX_TRNG_WORDS_PER_SAMPLE);
#endif /* CC3XX_CONFIG_TRNG_DMA */

    err = trng_wait_for_sample(ctx);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    trng_copy_entropy(entropy, word_count);

    return CC3XX_ERR_SUCCESS;
}
#endif /* !CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

/*!
 * \defgroup cc3xx_noise_source Set of functions implementing the API to access the TRNG
 *                              based noise source, for reading random bits
 */
/*!@{*/
#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
void cc3xx_lowlevel_noise_source_context_init(struct cc3xx_noise_source_ctx_t *ctx)
{
    assert(ctx != NULL);

    *ctx = (struct cc3xx_noise_source_ctx_t){
        .is_config_valid = true,
        .rosc.id = CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID,
        .rosc.subsampling_rate = CC3XX_CONFIG_RNG_SUBSAMPLING_RATE,
        .debug_control = 0x0UL
    };
}
#else
void cc3xx_lowlevel_noise_source_context_init(struct cc3xx_noise_source_ctx_t *ctx)
{
    (void)ctx;
}
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
cc3xx_err_t cc3xx_lowlevel_noise_source_init(struct cc3xx_noise_source_ctx_t *ctx)
{
    assert(ctx != NULL);
    if (!(ctx->is_config_valid)) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }
    trng_init(ctx->rosc.id, ctx->rosc.subsampling_rate, ctx->debug_control);
    return CC3XX_ERR_SUCCESS;
}
#else
cc3xx_err_t cc3xx_lowlevel_noise_source_init(struct cc3xx_noise_source_ctx_t *ctx)
{
    (void)ctx;
    trng_init();
    return CC3XX_ERR_SUCCESS;
}
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

cc3xx_err_t cc3xx_lowlevel_noise_source_finish(void)
{
    trng_finish();

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_noise_source_get_sample(
    struct cc3xx_noise_source_ctx_t *ctx,
    uint32_t *buf,
    size_t word_count)
{
#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
    assert(ctx != NULL);
    return trng_get_sample(ctx, buf, word_count);
#else
    return trng_get_random(buf, word_count);
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */
}

cc3xx_err_t cc3xx_lowlevel_noise_source_set_config(
    struct cc3xx_noise_source_ctx_t *ctx,
    enum cc3xx_noise_source_rosc_id_t rosc_id,
    uint32_t subsampling_rate)
{
#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
    assert(ctx != NULL);

    if (!((rosc_id >= CC3XX_RNG_ROSC_ID_0) && (rosc_id <= CC3XX_RNG_ROSC_ID_3))) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    if (!subsampling_rate) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    ctx->rosc.id = rosc_id;
    ctx->rosc.subsampling_rate = subsampling_rate;

    return CC3XX_ERR_SUCCESS;
#else
    return CC3XX_ERR_NOT_IMPLEMENTED;
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */
}

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
void cc3xx_lowlevel_noise_source_sp800_90b_mode(struct cc3xx_noise_source_ctx_t *ctx)
{
    cc3xx_lowlevel_noise_source_set_hw_test_bypass(ctx,
        CC3XX_TRNG_AUTOCORR_TEST_BYPASS, CC3XX_TRNG_CRNGT_TEST_ACTIVE, CC3XX_TRNG_VNC_TEST_BYPASS);
}
#else
void cc3xx_lowlevel_noise_source_sp800_90b_mode(struct cc3xx_noise_source_ctx_t *ctx)
{
    /* The external noise source must allow SP800-90B, perform any step required to enable it */
    (void)ctx;
    return;
}
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
void cc3xx_lowlevel_noise_source_set_hw_test_bypass(
    struct cc3xx_noise_source_ctx_t *ctx,
    enum cc3xx_trng_autocorr_test_state autocorr_state,
    enum cc3xx_trng_crngt_test_state crngt_state,
    enum cc3xx_trng_vnc_test_state vnc_state)
{
    assert(ctx != NULL);

    uint32_t hw_entropy_tests_control = 0x0UL;

    hw_entropy_tests_control |=
        (autocorr_state == CC3XX_TRNG_AUTOCORR_TEST_BYPASS) ? (1UL << 3) : 0x0UL;
    hw_entropy_tests_control |=
        (crngt_state == CC3XX_TRNG_CRNGT_TEST_BYPASS) ? (1UL << 2) : 0x0UL;
    hw_entropy_tests_control |=
        (vnc_state == CC3XX_TRNG_VNC_TEST_BYPASS) ? (1UL << 1) : 0x0UL;

    ctx->debug_control = hw_entropy_tests_control;
}
#else
void cc3xx_lowlevel_noise_source_set_hw_test_bypass(struct cc3xx_noise_source_ctx_t *ctx)
{
    /* If an external noise source has the option to separately configure the HW, plug it here */
    (void)ctx;
}
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifndef CC3XX_CONFIG_RNG_EXTERNAL_TRNG
bool cc3xx_lowlevel_noise_source_bump_parameters(struct cc3xx_noise_source_ctx_t *ctx)
{
    return trng_bump_rosc_id_and_subsampling_rate((uint32_t *)&ctx->rosc.id, &ctx->rosc.subsampling_rate);
}
#else
bool cc3xx_lowlevel_noise_source_bump_parameters(struct cc3xx_noise_source_ctx_t *ctx)
{
    /* If an external noise source has the option to bump config parameters, plug it here */
    (void)ctx;
    return false;
}
#endif /* CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
void cc3xx_lowlevel_noise_source_get_stats(struct cc3xx_noise_source_stats_t *stats)
{
    *stats = g_trng_stats;
}

void cc3xx_lowlevel_noise_source_clear_stats(void)
{
    g_trng_stats = (struct cc3xx_noise_source_stats_t){0};
}
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */
/*!@}*/

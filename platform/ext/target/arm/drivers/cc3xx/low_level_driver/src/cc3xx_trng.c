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

#include "cc3xx_trng.h"

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "fatal_error.h"

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

static void trng_init(
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
}

static void trng_finish(void)
{
    /* Disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Disable clock */
    P_CC3XX->rng.rng_clk_enable = 0x0U;
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

cc3xx_err_t cc3xx_lowlevel_trng_init(void)
{
    trng_init(g_trng_config.rosc.id, g_trng_config.rosc.subsampling_rate, g_trng_config.debug_control);

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_trng_finish(void)
{
    trng_finish();

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_trng_get_sample(uint32_t *buf, size_t word_count)
{
    uint32_t attempt_count = 0;
    uint32_t idx;

    assert(word_count == sizeof(P_CC3XX->rng.ehr_data) / sizeof(uint32_t));

    /* Wait until the TRNG has finished. Any status other than 0x1 indicates
     * that either the TRNG hasn't finished or a statistical test has been
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
            cc3xx_lowlevel_trng_init();

            attempt_count++;
        }
    } while ((! (P_CC3XX->rng.rng_isr & 0x1U))
             && attempt_count < CC3XX_CONFIG_RNG_MAX_ATTEMPTS);

    if (attempt_count == CC3XX_CONFIG_RNG_MAX_ATTEMPTS) {
        cc3xx_lowlevel_trng_finish();
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

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_trng_set_config(
    enum cc3xx_rng_rosc_id_t rosc_id,
    uint32_t subsampling_rate)
{
    if (!((rosc_id >= CC3XX_RNG_ROSC_ID_0) && (rosc_id <= CC3XX_RNG_ROSC_ID_3))) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    if (!subsampling_rate) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    g_trng_config.rosc.id = rosc_id;
    g_trng_config.rosc.subsampling_rate = subsampling_rate;

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_trng_validate_config(void)
{
    if (!g_trng_config.rosc.subsampling_rate) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    if (!((g_trng_config.rosc.id >= CC3XX_RNG_ROSC_ID_0) &&
                    (g_trng_config.rosc.id <= CC3XX_RNG_ROSC_ID_3))) {
        FATAL_ERR(CC3XX_ERR_RNG_INVALID_TRNG_CONFIG);
        return CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    }

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_trng_sp800_90b_mode(bool enable)
{
    if (enable) {
        cc3xx_lowlevel_trng_set_hw_test_bypass(true, false, true);
    }
}

void cc3xx_lowlevel_trng_set_hw_test_bypass(
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

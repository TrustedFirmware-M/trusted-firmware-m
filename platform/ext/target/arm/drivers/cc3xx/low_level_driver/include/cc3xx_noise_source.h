/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_NOISE_SOURCE_H__
#define __CC3XX_NOISE_SOURCE_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include "cc3xx_dev.h"
#include "cc3xx_error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Size in bytes of the generated entropy per each generation from the TRNG
 *
 */
#define CC3XX_TRNG_SAMPLE_SIZE      (sizeof(P_CC3XX->rng.ehr_data))
#define CC3XX_TRNG_WORDS_PER_SAMPLE (CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t))

#ifndef __PACKED_ENUM
#define __PACKED_ENUM enum __attribute__((packed))
#endif

/**
 * @brief: Indicates that the autocorrelation test failed four times in a row.
 *         When AUTOCORR_ERR is set, TRNG ceases to function until next reset.
 */
__PACKED_ENUM cc3xx_trng_autocorr_test_state {
    CC3XX_TRNG_AUTOCORR_TEST_ACTIVE,
    CC3XX_TRNG_AUTOCORR_TEST_BYPASS
};

/**
 * @brief: Indicates CRNGT in the TRNG test failed. Failure occurs when two
 *         consecutive blocks of 16 collected bits are equal.
 */
__PACKED_ENUM cc3xx_trng_crngt_test_state {
    CC3XX_TRNG_CRNGT_TEST_ACTIVE,
    CC3XX_TRNG_CRNGT_TEST_BYPASS
};

/**
 * @brief: Indicates von Neumann balancer error. Error in von Neumann balancer
 *         occurs if all 32 of the consecutive collected bits are identical.
 */
__PACKED_ENUM cc3xx_trng_vnc_test_state {
    CC3XX_TRNG_VNC_TEST_ACTIVE,
    CC3XX_TRNG_VNC_TEST_BYPASS
};

/**
 * @brief The type describes the IDs of the available ring oscillators (ROSCs) from
 *        which entropy can be generated.
 */
__PACKED_ENUM cc3xx_noise_source_rosc_id_t {
    CC3XX_RNG_ROSC_ID_0 = 0,     /*!< ROSC ID 0 */
    CC3XX_RNG_ROSC_ID_1 = 1,     /*!< ROSC ID 1 */
    CC3XX_RNG_ROSC_ID_2 = 2,     /*!< ROSC ID 2 */
    CC3XX_RNG_ROSC_ID_3 = 3,     /*!< ROSC ID 3 */
};

/**
 * @brief The ROSC config holds the parameters for a ring oscillator (ROSC) from
 *        which entropy is collected by consecutive sampling. It holds the ID of
 *        the ROSC from which to sample and the interval in number of cycles for
 *        consecutive samples
 */
struct rosc_config_t {
    uint32_t subsampling_rate;  /*!< Number of rng_clk cycles between ROSC samples */
    enum cc3xx_noise_source_rosc_id_t id; /*!< Selected ring oscillator (ROSC) */
};

/**
 * @brief Context associated to a TRNG mode of operation. Default values are set at
 *        context initialisation time through \a cc3xx_lowlevel_noise_source_context_init,
 *        but can be overridden by calling \a cc3xx_lowlevel_noise_source_set_config and
 *        \a cc3xx_lowlevel_noise_source_set_hw_test_bypass
 */
struct cc3xx_noise_source_ctx_t {
    bool is_config_valid;                     /*!< Indicates whether the contents are a valid config */
    uint32_t debug_control;                   /*!< The TRNG_DEBUG_CONTROL register configuration */
    struct {
        uint32_t subsampling_rate;            /*!< Number of rng_clk cycles between ROSC samples */
        enum cc3xx_noise_source_rosc_id_t id; /*!< Selected ring oscillator (ROSC) */
    } rosc;                                   /*!< The Ring OSCillator configuration */
};

#ifdef CC3XX_CONFIG_TRNG_COLLECT_STATISTCS
/**
 * @brief Structure keeping track of the error statistics observed since last clearing
 *
 */
struct cc3xx_noise_source_stats_t {
    size_t autocorr_err_stats; /*!< AUTOCORR test failures */
    size_t crngt_err_stats;    /*!< CRNGT test failures */
    size_t vnc_err_stats;      /*!< VNC test failures */
};

/**
 * @brief                       Gets the TRNG error counters
 *
 * @param[in] stats             statistics structure to be populated with current error counters.
 *
 */
void cc3xx_lowlevel_noise_source_get_stats(struct cc3xx_noise_source_stats_t *stats);

/**
 * @brief                       Clears the TRNG error counters.
 *
 */
void cc3xx_lowlevel_noise_source_clear_stats(void);
#endif /* CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */

static inline bool is_context_valid(struct cc3xx_noise_source_ctx_t *ctx) {
    return ctx && ctx->is_config_valid;
}
/**
 * @brief Macro that checks if the \ref cc3xx_noise_source_ctx_t context has valid contents
 *
 */
#define CC3XX_IS_NOISE_SOURCE_CONTEXT_VALID(ctx) is_context_valid(ctx)

/**
 * @brief Macro to initialise a \ref cc3xx_noise_source_ctx_t with safe *invalid* values on
 *        allocation, i.e. struct cc3xx_noise_source_ctx_t foo = CC3XX_NOISE_SOURCE_CONTEXT_INIT;
 */
#define CC3XX_NOISE_SOURCE_CONTEXT_INIT ((struct cc3xx_noise_source_ctx_t){0});

/**
 * @brief                       Initialises the provided context to *default build valid* values.
 *                              It must be called before calling any other API
 *
 * @param[out] ctx              Pointer to the context of the TRNG to set in SP800-90B mode
 *
 */
void cc3xx_lowlevel_noise_source_context_init(struct cc3xx_noise_source_ctx_t *ctx);

/**
 * @brief                       SP800-90B section 4.4 recommends two continuous health tests
 *                              to be performed at startup and during normal operation of the
 *                              noise source to verify the quality ot the entropy bits produced,
 *                              namely the Repetition Count Test (4.4.1) and Adaptive Proportion
 *                              Test (4.4.2). This API enables that mode of operation
 *
 * @note                        It configures the context to disable the AUTOCORR tests and VNC
 *                              balancer tests performed by the hardware
 *
 * @param[in, out] ctx          Pointer to the context of the TRNG to set in SP800-90B mode
 * @param[in]      enable       Set to \a true to put the the context in SP800-90B compatible mode,
 *                              i.e. disables the AUTOCORR tests and VNC balancer tests performed by
 *                              the hardware
 */
void cc3xx_lowlevel_noise_source_sp800_90b_mode(struct cc3xx_noise_source_ctx_t *ctx);

/**
 * @brief                       Sets the TRNG configuration on the provided context for
 *                              the usage of the TRNG by the other APIs used by this
 *                              module. If this is not called, default parameters
 *                              defined at initialisation time will be used, i.e.
 *                              \a CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID and
 *                              \a CC3XX_CONFIG_RNG_SUBSAMPLING_RATE
 *
 * @param[out] ctx              Pointer to the context on which to set the configuration
 * @param[in]  rosc_id          ROSC ID to be used, a number between 0 and 3
 * @param[in]  subsampling_rate Specifies the number of rng_clk cycles between collection
 *                              of consecutive samples of the selected ring oscillator
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, or
 *                              CC3XX_ERR_RNG_INVALID_TRNG_CONFIG if invalid parameters
 *                              are passed
 */
cc3xx_err_t cc3xx_lowlevel_noise_source_set_config(
    struct cc3xx_noise_source_ctx_t *ctx,
    enum cc3xx_noise_source_rosc_id_t rosc_id,
    uint32_t subsampling_rate);

/**
 * @brief                       Sets the TRNG_DEBUG_CONTROL register to bypass mode for the
 *                              respective HW tests, in the global configuration (state) structure
 *
 * @param[out] ctx              Pointer to the context on which to set the hardware bypasses
 * @param[in]  autocorr_state   Set to \a CC3XX_TRNG_AUTOCORR_TEST_BYPASS to bypass the AUTOCORR test
 * @param[in]  crngt_state      Set to \a CC3XX_TRNG_CRNGT_TEST_BYPASS to bypass the CRNGT test
 * @param[in]  vnc_state        Set to \a CC3XX_TRNG_VNC_TEST_BYPASS to bypass the VNC test
 *
 */
void cc3xx_lowlevel_noise_source_set_hw_test_bypass(
    struct cc3xx_noise_source_ctx_t *ctx,
    enum cc3xx_trng_autocorr_test_state autocorr_state,
    enum cc3xx_trng_crngt_test_state crngt_state,
    enum cc3xx_trng_vnc_test_state vnc_state);

/**
 * @brief                       Initialises the TRNG before a call to \a cc3xx_lowlevel_noise_source_get_sample.
 *                              It requires a pointer to a context to be passed in
 *
 * @param[in, out] ctx          Pointer to the context to use for the initialisation
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS
 */
cc3xx_err_t cc3xx_lowlevel_noise_source_init(struct cc3xx_noise_source_ctx_t *ctx);

/**
 * @brief                       Reads the sample out of the TRNG
 *
 * @param[in, out] ctx          Pointer to the context to use for the reading
 * @param[out] buf              Output buffer, word aligned, into which the sample is read
 * @param[in]  word_count       Size in words of the \p buf output buffer, must be equal to
 *                              the number of words of P_CC3XX->rng.ehr_data, i.e. CC3XX_TRNG_SAMPLE_SIZE
 *                              when expressed in bytes
 *
 * @note                        This function might alter the global config (state) hence it requires global
 *                              variables to be available
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS in
 *                              case errors have been detected on each generation. The maximum
 *                              number of generations is controlled by CC3XX_CONFIG_RNG_MAX_ATTEMPTS
 */
cc3xx_err_t cc3xx_lowlevel_noise_source_get_sample(struct cc3xx_noise_source_ctx_t *ctx, uint32_t *buf, size_t word_count);

/**
 * @brief                       De-initialises the TRNG by disabling the random source and the clock
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS
 */
cc3xx_err_t cc3xx_lowlevel_noise_source_finish(void);

/**
 * @brief                       Bumps the configuration parameters of the noise source, if it allows that
 *
 * @param[in, out] ctx          Pointer to the context to use for possible bumping up of the parameters
 *
 * @return true                 A config parameters change has happened
 * @return false                A config parameters change has not happened or it was not possible
 */
bool cc3xx_lowlevel_noise_source_bump_parameters(struct cc3xx_noise_source_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_NOISE_SOURCE_H__ */

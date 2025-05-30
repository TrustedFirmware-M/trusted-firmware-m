/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_TRNG_H__
#define __CC3XX_TRNG_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "cc3xx_dev.h"
#include "cc3xx_error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Size in bytes of the generated entropy per each generation from the TRNG
 *
 */
#define CC3XX_TRNG_SAMPLE_SIZE (sizeof(P_CC3XX->rng.ehr_data))

#ifndef __PACKED_ENUM
#define __PACKED_ENUM enum __attribute__((packed))
#endif

/**
 * @brief The type describes the IDs of the available ring oscillators (ROSCs) from
 *        which entropy can be generated.
 *
 * @note  If an external TRNG is used then these defines do not apply
 *
 */
__PACKED_ENUM cc3xx_rng_rosc_id_t {
    CC3XX_RNG_ROSC_ID_0 = 0,     /*!< ROSC ID 0 */
    CC3XX_RNG_ROSC_ID_1 = 1,     /*!< ROSC ID 1 */
    CC3XX_RNG_ROSC_ID_2 = 2,     /*!< ROSC ID 2 */
    CC3XX_RNG_ROSC_ID_3 = 3,     /*!< ROSC ID 3 */
};

/**
 * @brief                       SP800-90B section 4.4 recommends two continuous health tests
 *                              to be performed at startup and during normal operation of the
 *                              noise source to verify the quality ot the entropy bits produced,
 *                              namely the Repetition Count Test (4.4.1) and Adaptive Proportion
 *                              Test (4.4.2)
 *
 * @param[in] enable            Set to \a true to put the TRNG in SP800-90B compatible mode, i.e.
 *                              disables the AUTOCORR tests and VNC balancer tests performed by
 *                              the hardware
 */
void cc3xx_lowlevel_trng_sp800_90b_mode(bool enable);

/**
 * @brief                       Sets the configuration (ROSC_ID, subsampling rate) for
 *                              the usage of the TRNG by the other APIs used by this
 *                              module. If this is not called, default parameters
 *                              defined at build time will be used, i.e.
 *                              (CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID,
 *                              CC3XX_CONFIG_RNG_SUBSAMPLING_RATE)
 *
 * @param[in] rosc_id           ROSC ID to be used, a number between 0 and 3
 * @param[in] subsampling_rate  Specifies the number of rng_clk cycles between collection
 *                              of consecutive samples of the selected ring oscillator
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, or
 *                              CC3XX_ERR_RNG_INVALID_TRNG_CONFIG if invalid parameters
 *                              are passed
 */
cc3xx_err_t cc3xx_lowlevel_trng_set_config(enum cc3xx_rng_rosc_id_t rosc_id, uint32_t subsampling_rate);

/**
 * @brief                       Validates the configuration of the TRNG
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, or CC3XX_ERR_RNG_INVALID_TRNG_CONFIG if
 *                              an invalid configuration is detected
 */
cc3xx_err_t cc3xx_lowlevel_trng_validate_config(void);

/**
 * @brief                       Sets the TRNG_DEBUG_CONTROL register to bypass mode for the
 *                              respective HW tests
 *
 * @param[in] bypass_autocorr   Set to \a true to bypass the AUTOCORR test
 * @param[in] bypass_crngt      Set to \a true to bypass the CRNGT test
 * @param[in] bypass_vnc        Set to \a true to bypass the Von Neumann balancer test
 *
 */
void cc3xx_lowlevel_trng_set_hw_test_bypass(bool bypass_autocorr, bool bypass_crngt, bool bypass_vnc);

/**
 * @brief                       Reads the sample out of the TRNG
 *
 * @param[out] buf              Output buffer, word aligned, into which the entropy is read
 * @param[in]  word_count       Size in words of the \p buf output buffer, must be equal to
 *                              the number of words of P_CC3XX->rng.ehr_data, i.e. CC3XX_TRNG_SAMPLE_SIZE
 *                              when expressed in bytes
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS in
 *                              case errors have been detected on each generation. The maximum
 *                              number of generations is controlled by CC3XX_CONFIG_RNG_MAX_ATTEMPTS
 */
cc3xx_err_t cc3xx_lowlevel_trng_get_sample(uint32_t *buf, size_t word_count);

/**
 * @brief                       Initialises the TRNG before a call to \a cc3xx_lowlevel_trng_get_entropy
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS
 */
cc3xx_err_t cc3xx_lowlevel_trng_init(void);

/**
 * @brief                       De-initialises the TRNG by disabling the random source and the clock
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS
 */
cc3xx_err_t cc3xx_lowlevel_trng_finish(void);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_TRNG_H__ */

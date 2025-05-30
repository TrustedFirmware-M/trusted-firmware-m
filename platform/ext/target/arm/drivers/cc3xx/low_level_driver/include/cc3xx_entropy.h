/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_ENTROPY_H
#define CC3XX_ENTROPY_H

#include "cc3xx_error.h"
#include "cc3xx_trng.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CC3XX_ENTROPY_SIZE (CC3XX_TRNG_SAMPLE_SIZE)

/**
 * @brief                       SP800-90B section 4.4 recommends two continuous health tests
 *                              to be performed at startup and during normal operation of the
 *                              noise source to verify the quality ot the entropy bits produced,
 *                              namely the Repetition Count Test (4.4.1) and Adaptive Proportion
 *                              Test (4.4.2)
 *
 * @param[in] enable            Set to \a true to put the RNG entropy source in SP800-90B compatible
 *                              mode, i.e. enable continuous health tests as recommended by SP800-90B
 *
 * @return cc3xx_err_t          CC3XX_ERR_SUCCESS on success, or
 *                              CC3XX_ERR_NOT_IMPLEMENTED in case the firmware is built
 *                              without support for the continuous health tests, i.e.
 *                              \a CC3XX_CONFIG_RNG_CONTINUOUS_HEALTH_TESTS_ENABLE is not
 *                              set in the CC3XX configuration \a cc3xx_config.h
 */
cc3xx_err_t cc3xx_lowlevel_entropy_sp800_90b_mode(bool enable);

/**
 * @brief                        Requires an amount of entropy from the TRNG
 *
 * @param[out] entropy           Buffer containing the requested entropy
 * @param[in]  entropy_len       Size in bytes of the \p entropy buffer. Must be an
 *                               integer multiple of \def CC3XX_ENTROPY_SIZE
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_entropy_get(uint32_t *entropy, size_t entropy_len);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_ENTROPY_H */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_ENTROPY_H
#define CC3XX_ENTROPY_H

#include "cc3xx_error.h"
#include "cc3xx_noise_source.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Size of the sample produced by the underlying noise source in a
 *        single reading
 */
#define CC3XX_ENTROPY_SIZE (CC3XX_TRNG_SAMPLE_SIZE)

/**
 * @brief                  Requires an amount of entropy from the SP800-90B
 *                         entropy source.
 *
 * @param[out] entropy     Buffer containing the requested entropy
 * @param[in]  entropy_len Size in bytes of the \p entropy buffer. Must be an
 *                         integer multiple of \def CC3XX_ENTROPY_SIZE
 *
 * @return                 CC3XX_ERR_SUCCESS on success, another
 *                         cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_get_entropy(uint32_t *entropy, size_t entropy_len);

/**
 * @brief Returns a generic pointer to the context of the underlying noise source
 *
 */
void *cc3xx_lowlevel_entropy_get_noise_source_ctx(void);

/**
 * @brief                      Sets the threshold values for the SP800-90B
 *                             continuous health tests
 *
 * @param[in] high_threshold   The cutoff rate for the Adaptive Proportion Test
 * @param[in] repetition_count The cutoff rate for the Repetition Count Test
 *
 * @retval                     CC3XX_ERR_SUCCESS
 *                             Configuration applied correctly
 * @retval                     CC3XX_ERR_RNG_SP800_90B_INVALID_THRESHOLD
 *                             Any provided threshold is invalid, and the
 *                             tests retain the default build time thresholds
 */
cc3xx_err_t
cc3xx_lowlevel_entropy_sp800_90b_set_config(uint32_t high_threshold,
                                            uint32_t repetition_count);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_ENTROPY_H */

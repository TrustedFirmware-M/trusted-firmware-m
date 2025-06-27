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
 * @brief                        Requires an amount of entropy from the SP800-90B
 *                               entropy source.
 *
 * @param[out] entropy           Buffer containing the requested entropy
 * @param[in]  entropy_len       Size in bytes of the \p entropy buffer. Must be an
 *                               integer multiple of \def CC3XX_ENTROPY_SIZE
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_get_entropy(uint32_t *entropy, size_t entropy_len);

/**
 * @brief Returns a generic pointer to the context of the underlying noise source
 *
 */
void *cc3xx_lowlevel_entropy_get_noise_source_ctx(void);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_ENTROPY_H */

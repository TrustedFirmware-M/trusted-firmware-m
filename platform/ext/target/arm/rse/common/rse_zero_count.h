/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_ZERO_COUNT_H__
#define __RSE_ZERO_COUNT_H__

#include <stdint.h>
#include <stddef.h>
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Performs zero bits counting over a buffer with given length,
 *        with an hardware integrity checker if available, otherwise
 *        through a software based zero count
 *
 * @param[in]  buf        Buffer over which to perform the zero count
 * @param[in]  buf_len    Size in bytes of the \p buf buffer
 * @param[out] zero_count Computed number of zero bits over \p buf
 *
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t rse_count_zero_bits(uint8_t *buf, size_t buf_len,
                                        uint32_t *zero_count);
/**
 * @brief Verifies that the zero bit count over the input buffer matches
 *        with the expected value
 *
 * @param[in] buf                 Buffer over which to check the zero count
 * @param[in] buf_len             Size in bytes of the \p buf buffer
 * @param[in] expected_zero_count Expected zero count to compare against
 *
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t rse_check_zero_bit_count(uint8_t *buf, size_t buf_len,
                                             uint32_t expected_zero_count);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_ZERO_COUNT_H__ */

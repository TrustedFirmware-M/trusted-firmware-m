/*
 * Copyright (c) 2021-2022, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>

#ifndef __BL1_RANDOM_H__
#define __BL1_RANDOM_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Generate random bytes of cryptographic quality, for example using DRBGs
 *
 * @param[out] output      Output buffer containing the random bytes
 * @param[in]  output_size Size in bytes of the \p output buffer to generate
 *
 * @return int32_t 0 on success
 */
int32_t bl1_random_generate_secure(uint8_t *output, size_t output_size);

/**
 * @brief Generate random bytes fast, for example using LFSRs (Linear Feedback
 *        Shift Registers), which are not of cryptographic quality, but are fast
 *
 * @note  Do *NOT* use this function to generate keys or other quantities where
 *        cryptographic-grade randomness is required
 *
 * @param[out] output      Output buffer containing the random bytes
 * @param[in]  output_size Size in bytes of the \p output buffer to generate
 *
 * @return int32_t 0 on success
 */
int32_t bl1_random_generate_fast(uint8_t *output, size_t output_size);

/**
 * @brief Generate random bytes by directly reading the underlying system noise source
 *        without any particular guarantee of the cryptographic quality of the returned
 *        random bytes
 *
 * @note  Do *NOT* use this function to generate keys or other quantities where
 *        cryptographic-grade randomness is required
 *
 * @note  This function guarantees that no access to a global state will be required and
 *        the global state (if present) won't be altered after the call ends, i.e. there
 *        is no side effect on a global state triggered by a call to this function
 *
 * @param[out] output      Output buffer containing the random bytes
 * @param[in]  output_size Size in bytes of the \p output buffer to generate
 *
 * @return int32_t 0 on success
 */
int32_t bl1_random_generate_noise(uint8_t *output, size_t output_size);

#ifdef __cplusplus
}
#endif

#endif /* __BL1_RANDOM_H__ */

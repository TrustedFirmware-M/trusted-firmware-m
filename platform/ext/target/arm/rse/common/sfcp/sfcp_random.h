/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_RANDOM_H__
#define __SFCP_RANDOM_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t sfcp_random_generate_random_lfsr(uint8_t *seed, size_t seed_len);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_RANDOM_H__ */

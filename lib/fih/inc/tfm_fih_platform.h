/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_FIH_PLATFORM_H__
#define __TFM_FIH_PLATFORM_H__

#include "fih.h"

/**
 * \brief Set up the RNG for FIH with random delays.
 */
fih_ret tfm_fih_random_init(void);

/**
 * \brief Get a random number from an RNG seeded with an entropy source.
 *
 * \param[out] rand            Buffer to hold the random value
 */
void tfm_fih_random_generate(uint8_t *rand);

#endif /* __TFM_FIH_PLATFORM_H__ */

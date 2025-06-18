/******************************************************************************
 *
 * Copyright (C) 2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************/

#ifndef __ADI_PSA_RANDOM_H__
#define __ADI_PSA_RANDOM_H__

/** @file adi_psa_random.h
 *
 * This file contains the declaration of the entry points associated to the
 * random generation capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "psa/crypto.h"

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  (void)arg
#endif

/* ADI uses TRNG peripheral for random number generation
*  No context is needed for this driver
*/

typedef void adi_random_context_t;

/**
 * @brief Generates random numbers with a uniform distribution
 *
 * @param[in,out] context       A void pointer that is currently not being used. This argument is
 *                              to comply with PSA random number generation entry point defintion.
 * @param[out]    output        Buffer containing the random data collected
 * @param[in]     output_size   Size in bytes of the buffer to fill
 * @param[out]    output_length Number of bytes effectively returned in \ref buffer
 * @return psa_status_t
 */

psa_status_t adi_get_random(adi_random_context_t *context,
                             uint8_t *output,
                             size_t output_size,
                             size_t *output_length);

#endif /* __ADI_PSA_RANDOM_H__ */

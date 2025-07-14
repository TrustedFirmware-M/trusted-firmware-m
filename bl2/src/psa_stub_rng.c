/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \note This source file is derivative work of psa_crypto.c from the Mbed TLS project
 */
#include <stdint.h>
#include "psa/crypto.h"

/* This function is stubbed as no source of randomness is required
 * by APIs used in the BLx stages. Nevertheless, an hardwware driver
 * for a TRNG might override this implementation with a valid one
 * hence mark it as a weak
 */
__attribute__((weak))
psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

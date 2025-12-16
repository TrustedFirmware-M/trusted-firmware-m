/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_psa_asymmetric_encryption.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric encryption capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "cc3xx_psa_asymmetric_encryption.h"

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "tf-psa-crypto/build_info.h"

/** @defgroup psa_asym_encrypt PSA driver entry points for asymmetric cipher
 *
 *  Entry points for asymmetric cipher encryption and decryption as described
 *  by the PSA Cryptoprocessor Driver interface specification
 *
 *  @{
 */
psa_status_t cc3xx_asymmetric_encrypt(const psa_key_attributes_t *attributes,
                                      const uint8_t *key_buffer,
                                      size_t key_buffer_size,
                                      psa_algorithm_t alg,
                                      const uint8_t *input,
                                      size_t input_length,
                                      const uint8_t *salt, size_t salt_length,
                                      uint8_t *output, size_t output_size,
                                      size_t *output_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t cc3xx_asymmetric_decrypt(const psa_key_attributes_t *attributes,
                                      const uint8_t *key_buffer,
                                      size_t key_buffer_size,
                                      psa_algorithm_t alg,
                                      const uint8_t *input,
                                      size_t input_length,
                                      const uint8_t *salt, size_t salt_length,
                                      uint8_t *output, size_t output_size,
                                      size_t *output_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}
/** @} */ // end of psa_asym_encrypt

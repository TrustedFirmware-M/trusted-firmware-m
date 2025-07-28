/*
 * Copyright (c) 2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_ECDSA_H__
#define __CC3XX_ECDSA_H__

#include <stdint.h>
#include <stddef.h>

#include "cc3xx_error.h"
#include "cc3xx_ec.h"
/* Deriving ECC keys is based on AES-CMAC */
#include "cc3xx_aes.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CC3XX_ECDSA_MAX_PRIVATE_KEY_SIZE      CC3XX_EC_MAX_POINT_SIZE
#define CC3XX_ECDSA_MAX_PUBLIC_COORD_KEY_SIZE CC3XX_EC_MAX_POINT_SIZE

/**
 * @brief                        Generate an ECDSA private key
 *
 * @param[in]  curve_id          The ID of the curve to use.
 * @param[out] private_key       The buffer to write the private key into.
 * @param[in]  private_key_len   The size of the private key buffer.
 * @param[out] private_key_size  The size of the private key written into the
 *                               buffer.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_genkey(cc3xx_ec_curve_id_t curve_id,
                                        uint32_t *private_key,
                                        size_t private_key_len,
                                        size_t *private_key_size);
/**
 * @brief Derives an ECC private key for the specified curve. The corresponding
 *        public key can be obtained calling \ref cc3xx_lowlevel_ecdsa_getpub on
 *        the output of this function
 *
 * @note  This function derives an ECC private key based on AES-CMAC as PRF in
 *        Counter mode as used by \ref cc3xx_lowlevel_kdf_cmac and then applies
 *        the recommendation of FIPS 186-5 A.2.1 for modular reduction
 *
 * @param[in]  curve_id        Desired EC curve for which to derive the private key
 * @param[in]  key_id          Key ID to use as a secret key to derive from
 * @param[in]  key             If \p key_id is set to CC3XX_AES_KEY_ID_USER_KEY,
 *                             this buffer contains the key material.
 * @param[in]  key_size        The size of the key being used.
 * @param[in]  label           The label to input into the derivation operation.
 * @param[in]  label_length    The length of the label.
 * @param[in]  context         The context to input into the derivation operation.
 * @param[in]  context_length  The length of the context.
 * @param[out] output_key      Derived private key material
 * @param[in]  out_size        Size in bytes of the \p output_key buffer
 * @param[out] out_length      Length of the generated key on \p output_key. Can be
 *                             NULL
 *
 * @return                     CC3XX_ERR_SUCCESS on success, another
 *                             cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_derive_key(
    cc3xx_ec_curve_id_t curve_id,
    cc3xx_aes_key_id_t key_id, const uint32_t *key,
    cc3xx_aes_keysize_t key_size,
    const uint8_t *label, size_t label_length,
    const uint8_t *context, size_t context_length,
    uint32_t *output_key, size_t out_size, size_t *out_length);

/**
 * @brief                        Calculate an ECDSA public key from a private key
 *
 * @param[in]  curve_id          The ID of the curve that the private key
 *                               belongs to.
 * @param[in]  private_key       The buffer to load the private key from.
 * @param[in]  private_key_len   The size of the private key buffer.
 * @param[out] public_key_x      The buffer to write the public key x coord into.
 * @param[in]  public_key_x_len  The size of the public key x coord buffer.
 * @param[out] public_key_x_size The size of the public key x coord written into
 *                               the buffer.
 * @param[out] public_key_y      The buffer to write the public key y coord into.
 * @param[in]  public_key_y_len  The size of the public key y coord buffer.
 * @param[out] public_key_y_size The size of the public key y coord written into
 *                               the buffer.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_getpub(cc3xx_ec_curve_id_t curve_id,
                                        const uint32_t *private_key, size_t private_key_len,
                                        uint32_t *public_key_x, size_t public_key_x_len,
                                        size_t *public_key_x_size,
                                        uint32_t *public_key_y, size_t public_key_y_len,
                                        size_t *public_key_y_size);
/**
 * @brief                        Generate an ECDSA signature
 *
 * @param[in]  curve_id          The ID of the curve that the private key
 *                               belongs to.
 * @param[in]  private_key       The buffer to load the private key from.
 * @param[in]  private_key_len   The size of the private key buffer.
 * @param[in]  hash              The buffer to read the hash from.
 * @param[in]  hash_len          The size of the hash buffer.
 * @param[out] sig_r             The buffer to read the signature r param from.
 * @param[in]  sig_r_len         The size of the signature r param buffer.
 * @param[out] sig_r_size        The size of the signature r param written into
 *                               the buffer.
 * @param[out] sig_s             The buffer to read the signature s param from.
 * @param[in]  sig_s_len         The size of the signature s param buffer.
 * @param[out] sig_s_size        The size of the signature s param written into
 *                               the buffer.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_sign(
    cc3xx_ec_curve_id_t curve_id,
    const uint32_t *private_key, size_t private_key_len,
    const uint32_t *hash, size_t hash_len,
    uint32_t *sig_r, size_t sig_r_len, size_t *sig_r_size,
    uint32_t *sig_s, size_t sig_s_len, size_t *sig_s_size);

/**
 * @brief                        Generate an ECDSA signature deterministically
 *                               following RFC 6979
 *
 * @param[in]  curve_id          The ID of the curve that the private key
 *                               belongs to.
 * @param[in]  private_key       The buffer to load the private key from.
 * @param[in]  private_key_len   The size of the private key buffer.
 * @param[in]  hash              The buffer to read the hash from.
 * @param[in]  hash_len          The size of the hash buffer.
 * @param[out] sig_r             The buffer to read the signature r param from.
 * @param[in]  sig_r_len         The size of the signature r param buffer.
 * @param[out] sig_r_size        The size of the signature r param written into
 *                               the buffer.
 * @param[out] sig_s             The buffer to read the signature s param from.
 * @param[in]  sig_s_len         The size of the signature s param buffer.
 * @param[out] sig_s_size        The size of the signature s param written into
 *                               the buffer.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_sign_deterministic(
    cc3xx_ec_curve_id_t curve_id,
    const uint32_t *private_key, size_t private_key_len,
    const uint32_t *hash, size_t hash_len,
    uint32_t *sig_r, size_t sig_r_len, size_t *sig_r_size,
    uint32_t *sig_s, size_t sig_s_len, size_t *sig_s_size);

/**
 * @brief                        Verify an ECDSA signature
 *
 * @param[in]  curve_id          The ID of the curve that the signature was
 *                               generated using.
 * @param[in]  public_key_x      The buffer to read the public key x coord from.
 * @param[in]  public_key_x_len  The size of the public key x coord buffer.
 * @param[in]  public_key_y      The buffer to read the public key y coord from.
 * @param[in]  public_key_y_len  The size of the public key y coord buffer.
 * @param[in]  hash              The buffer to read the hash from.
 * @param[in]  hash_len          The size of the hash buffer.
 * @param[in]  sig_r             The buffer to read the signature r param from.
 * @param[in]  sig_r_len         The size of the signature r param buffer.
 * @param[in]  sig_s             The buffer to read the signature s param from.
 * @param[in]  sig_s_len         The size of the signature s param buffer.
 *
 * @return                       CC3XX_ERR_SUCCESS on signature validation
 *                               success, another cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_verify(cc3xx_ec_curve_id_t curve_id,
                                        const uint32_t *public_key_x,
                                        size_t public_key_x_len,
                                        const uint32_t *public_key_y,
                                        size_t public_key_y_len,
                                        const uint32_t *hash, size_t hash_len,
                                        const uint32_t *sig_r, size_t sig_r_len,
                                        const uint32_t *sig_s, size_t sig_s_len);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_ECDSA_H__ */

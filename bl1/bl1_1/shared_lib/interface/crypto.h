/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_1_CRYPTO_H
#define BL1_1_CRYPTO_H

#include <stddef.h>
#include <stdint.h>

#define CTR_IV_LEN 16

#include "psa/crypto.h"
#include "crypto_key_defs.h"
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Algorithm for which the given key can be used
 *
 * @enum tfm_bl1_key_type_t
 */
enum tfm_bl1_key_type_t {
    TFM_BL1_KEY_TYPE_ECDSA = 0b00,
    TFM_BL1_KEY_TYPE_LMS   = 0b01,
};

/**
 * @brief Policy associated to the given key
 *
 * @enum tfm_bl1_key_policy_t
 */
enum tfm_bl1_key_policy_t {
    TFM_BL1_KEY_MIGHT_SIGN = 0b00,
    TFM_BL1_KEY_MUST_SIGN  = 0b01,
};

/**
 * @brief Describes the EC curves that can be used for
 *        signature verification in BL1
 *
 * @enum tfm_bl1_ecdsa_curve_t
 *
 */
enum tfm_bl1_ecdsa_curve_t {
    TFM_BL1_CURVE_P256,
    TFM_BL1_CURVE_P384,
};

/**
 * @brief Describes the allowed hashing algorithms in BL1
 *
 * @enum tfm_bl1_hash_alg_t
 *
 */
enum tfm_bl1_hash_alg_t {
    TFM_BL1_HASH_ALG_SHA256 = PSA_ALG_SHA_256,
    TFM_BL1_HASH_ALG_SHA384 = PSA_ALG_SHA_384,
};

/**
 * @brief Describes the allowed aes direction in BL1
 *
 * @enum tfm_bl1_aes_direction_t
 *
 */
enum tfm_bl1_aes_direction_t {
    TFM_BL1_AES_DIRECTION_ENCRYPT,
    TFM_BL1_AES_DIRECTION_DECRYPT,
};

/**
 * @brief Describes the allowed aes modes in BL1
 *
 * @enum tfm_bl1_aes_mode_t
 *
 */
enum tfm_bl1_aes_mode_t {
    TFM_BL1_AES_MODE_CTR,
    TFM_BL1_AES_MODE_CCM,
    TFM_BL1_AES_MODE_CMAC,
};

/**
 * @brief Describes the allowed aes key size in BL1
 *
 * @enum tfm_bl1_aes_key_size_t
 *
 */
enum tfm_bl1_aes_key_size_t {
    TFM_BL1_AES_KEY_SIZE_256 = 256,
};

/**
 * @brief Computes a hash of data as a single integrated operation
 *
 * @param[in]  alg         Algorithm of type \ref tfm_bl1_hash_alg_t
 * @param[in]  data        Buffer containing the input bytes
 * @param[in]  data_length Size in bytes of the input \p data buffer
 * @param[out] hash        Buffer containing the produced output
 * @param[in]  hash_length Size in bytes of the \p hash buffer
 * @param[out] hash_size   Size in bytes of the produced hash
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_hash_compute(enum tfm_bl1_hash_alg_t alg,
                         const uint8_t *data,
                         size_t data_length,
                         uint8_t *hash,
                         size_t hash_length,
                         size_t *hash_size);
/**
 * @brief Initialises a multipart hashing operation
 *
 * @param[in] alg  Algorithm of type \ref tfm_bl1_hash_alg_t
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_hash_init(enum tfm_bl1_hash_alg_t alg);

/**
 * @brief Updates an ongoing multipart hashing operation with some input data
 *
 * @param[in] data        Buffer containing the input bytes
 * @param[in] data_length Size in bytes of the input \p data buffer
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_hash_update(const uint8_t *data,
                        size_t data_length);
/**
 * @brief Finalises an ongoing multipart hashing operation
 *
 * @param[out] hash        Buffer containing the produced output
 * @param[in]  hash_length Size in bytes of the \p hash buffer
 * @param[out] hash_size   Size in bytes of the produced hash
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_hash_finish(uint8_t *hash,
                        size_t hash_length,
                        size_t *hash_size);
/**
 * @brief Performs AES-256 decryption in Counter mode
 *
 * @note  In Counter (CTR) mode encryption and decryption
 *        are implemented in the same way
 *
 * @param[in]     key_id             Key ID of type \ref tfm_bl1_key_id_t
 * @param[in]     key_material       If TFM_BL1_KEY_USER, this contains key material
 * @param[in,out] counter            Value of the counter to be used for CTR mode
 * @param[in]     ciphertext         Buffer containing the bytes to decrypt
 * @param[in]     ciphertext_length  Size in bytes of the \p ciphertext buffer
 * @param[out]    plaintext          Buffer containing the decrypted bytes
 *
 * @return int32_t 0 on success, non-zero on error
 */
fih_ret bl1_aes_256_ctr_decrypt(enum tfm_bl1_key_id_t key_id,
                                const uint8_t *key_material,
                                uint8_t *counter,
                                const uint8_t *ciphertext,
                                size_t ciphertext_length,
                                uint8_t *plaintext);
/**
 * @brief Derives a key using a cryptographic method which depends on the underlying
 *        platform capabilities
 *
 * @note  An example is the usage of AES-CMAC as PRF in a KDF in Counter mode as per
 *        NIST SP800-108r1-upd1
 *
 * @param[in]  key_id         ID of the input key from which to derive material
 * @param[in]  label          Label to associated to the derivation. NULL terminated string
 * @param[in]  label_length   Size in bytes of the string comprising of the terminator
 * @param[in]  context        Context bytes to associate to the derivation
 * @param[in]  context_length Size in bytes of the \p context parameter
 * @param[out] output_key     Derived key material
 * @param[in]  output_length  Size in bytes of the key to be derived
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_derive_key(enum tfm_bl1_key_id_t key_id, const uint8_t *label,
                       size_t label_length, const uint8_t *context,
                       size_t context_length, uint32_t *output_key,
                       size_t output_length);

/**
 * @brief Derives a key using PSA Crypto APIs, the underlying KDF algorithm depends
 *        on platform capabilities
 *
 * @note  An example is the usage of AES-CMAC as PRF in a KDF in Counter mode as per
 *        NIST SP800-108r1-upd1
 *
 * @param[in]  key_id         PSA key ID of the input key from which to derive material
 * @param[in]  label          Label to associated to the derivation. NULL terminated string
 * @param[in]  label_length   Size in bytes of the string comprising of the terminator
 * @param[in]  context        Context bytes to associate to the derivation
 * @param[in]  context_length Size in bytes of the \p context parameter
 * @param[out] output_key     Derived key material
 * @param[in]  output_length  Size in bytes of the key to be derived
 *
 * @return psa_status_t PSA_SUCCES on success, otherwise PSA error code.
 */
psa_status_t bl1_psa_derive_key(psa_key_id_t key, const uint8_t *label,
                                size_t label_length, const uint8_t *context,
                                size_t context_length, uint8_t *output_key,
                                size_t output_length);

/**
 * @brief Derives an ECC (private) key for the specified curve. The key derivation
 *        procedure must follow a recommended procedure to generate a uniform number
 *        over the interval [1, n-1] where n is the order of the specified curve
 *
 * @note  An example is the recommendation for ECC private key generation as described in
 *        FIPS 186-5 A.2.1
 *
 * @param[in]  curve          Curve for which we want to derive a private key, of type
 *                            \ref tfm_bl1_ecdsa_curve_t
 * @param[in]  key_id         ID of the input key from which to derive material
 * @param[in]  label          Label to associated to the derivation. NULL terminated string
 * @param[in]  label_length   Size in bytes of the string comprising of the terminator
 * @param[in]  context        Context bytes to associate to the derivation
 * @param[in]  context_length Size in bytes of the \p context parameter
 * @param[out] output_key     Derived key material, naturally encoded as a Big Endian number
 * @param[in]  output_size    Size in bytes of the \p output_key parameter. It must enough to
 *                            accommodate a private key for the desired \p curve, e.g. 32
 *                            bytes for P-256 or 48 bytes for P-384
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_ecc_derive_key(enum tfm_bl1_ecdsa_curve_t curve, enum tfm_bl1_key_id_t key_id,
                           const uint8_t *label, size_t label_length,
                           const uint8_t *context, size_t context_length,
                           uint32_t *output_key, size_t output_size);

/**
 * @brief Verifies that the provided signature is a valid signature of the input
 *        hash using ECDSA and the selected curve
 *
 * @param[in] curve             Desired curve over which to verify, of type \ref tfm_bl1_ecdsa_curve_t
 * @param[in] public_key_x      The buffer to read the public key x coord from.
 * @param[in] public_key_x_len  The size of the public key x coord buffer.
 * @param[in] public_key_y      The buffer to read the public key y coord from.
 * @param[in] public_key_y_len  The size of the public key y coord buffer.
 * @param[in] hash              The buffer to read the hash from.
 * @param[in] hash_len          The size of the hash buffer.
 * @param[in] sig_r             The buffer to read the signature r param from.
 * @param[in] sig_r_len         The size of the signature r param buffer.
 * @param[in] sig_s             The buffer to read the signature s param from.
 * @param[in] sig_s_len         The size of the signature s param buffer.
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_int bl1_internal_ecdsa_verify(enum tfm_bl1_ecdsa_curve_t bl1_curve,
                                const uint32_t *public_key_x,
                                size_t public_key_x_len,
                                const uint32_t *public_key_y,
                                size_t public_key_y_len,
                                const uint32_t *hash, size_t hash_len,
                                const uint32_t *sig_r, size_t sig_r_len,
                                const uint32_t *sig_s, size_t sig_s_len);

/**
 * @brief Verifies that the provided signature is a valid signature of the input
 *        hash using ECDSA and the selected curve
 *
 * @param[in] curve          Desired curve over which to verify, of type \ref tfm_bl1_ecdsa_curve_t
 * @param[in] key            Public key in raw uncompressed format, might contain the 0x04 byte at start
 * @param[in] key_size       Size in bytes of the \p key buffer
 * @param[in] hash           Hash of which to verify the signature
 * @param[in] hash_length    Size in bytes of \p hash
 * @param[in] signature      Signature to verify in raw format (r,s)
 * @param[in] signature_size Size in bytes of the \p signature to verify
 *
 * @return FIH_SUCCESS on success, non-zero on error
 */
fih_ret bl1_ecdsa_verify(enum tfm_bl1_ecdsa_curve_t curve,
                         uint8_t *key, size_t key_size,
                         const uint8_t *hash,
                         size_t hash_length,
                         const uint8_t *signature,
                         size_t signature_size);

#ifdef __cplusplus
}
#endif

#endif /* BL1_1_CRYPTO_H */

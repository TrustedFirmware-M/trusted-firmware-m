/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __CRYPTO_CHECK_CONFIG_H__
#define __CRYPTO_CHECK_CONFIG_H__

#include "config_tfm.h"

/* RNG module config can't be adjusted on PSA_WANT_* requirements. */

#if CRYPTO_KEY_MODULE_ENABLED && \
    (!defined(PSA_WANT_KEY_TYPE_DERIVE) && \
     !defined(PSA_WANT_KEY_TYPE_HMAC) && \
     !defined(PSA_WANT_KEY_TYPE_RAW_DATA) && \
     !defined(PSA_WANT_KEY_TYPE_PASSWORD) && \
     !defined(PSA_WANT_KEY_TYPE_PASSWORD_HASH) && \
     !defined(PSA_WANT_KEY_TYPE_PEPPER) && \
     !defined(PSA_WANT_KEY_TYPE_AES) && \
     !defined(PSA_WANT_KEY_TYPE_ARIA) && \
     !defined(PSA_WANT_KEY_TYPE_CAMELLIA) && \
     !defined(PSA_WANT_KEY_TYPE_SM4) && \
     !defined(PSA_WANT_KEY_TYPE_ARC4) && \
     !defined(PSA_WANT_KEY_TYPE_CHACHA20) && \
     !defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY) && \
     !defined(PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY) && \
     !defined(PSA_WANT_KEY_TYPE_DH_PUBLIC_KEY))
#error "CRYPTO_KEY_MODULE enabled, but not all prerequisites (missing key types)!"
#endif

#if CRYPTO_AEAD_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_CCM) && \
     !defined(PSA_WANT_ALG_GCM) && \
     !defined(PSA_WANT_ALG_CHACHA20_POLY1305))
#error "CRYPTO_AEAD_MODULE_ENABLED enabled, but not all prerequisites (missing AEAD algorithms)!"
#endif

#if CRYPTO_MAC_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_CMAC) && \
     !defined(PSA_WANT_ALG_HMAC) && \
     !defined(PSA_WANT_ALG_CBC_MAC))
#error "CRYPTO_MAC_MODULE_ENABLED enabled, but not all prerequisites (missing MAC algorithms)!"
#endif

#if CRYPTO_CIPHER_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_ECB_NO_PADDING) && \
     !defined(PSA_WANT_ALG_CBC_NO_PADDING) && \
     !defined(PSA_WANT_ALG_CBC_PKCS7) && \
     !defined(PSA_WANT_ALG_CCM_STAR_NO_TAG) && \
     !defined(PSA_WANT_ALG_CFB) && \
     !defined(PSA_WANT_ALG_CTR) && \
     !defined(PSA_WANT_ALG_OFB) && \
     !defined(PSA_WANT_ALG_XTS) && \
     !defined(PSA_WANT_ALG_STREAM_CIPHER))
#error "CRYPTO_CIPHER_MODULE_ENABLED enabled, but not all prerequisites (missing CIPHER algorithms)!"
#endif

#if CRYPTO_HASH_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_MD2) && \
     !defined(PSA_WANT_ALG_MD4) && \
     !defined(PSA_WANT_ALG_MD5) && \
     !defined(PSA_WANT_ALG_RIPEMD160) && \
     !defined(PSA_WANT_ALG_SHA_1) && \
     !defined(PSA_WANT_ALG_SHA_224) && \
     !defined(PSA_WANT_ALG_SHA_256) && \
     !defined(PSA_WANT_ALG_SHA_384) && \
     !defined(PSA_WANT_ALG_SHA_512) && \
     !defined(PSA_WANT_ALG_SHA_512_224) && \
     !defined(PSA_WANT_ALG_SHA_512_256) && \
     !defined(PSA_WANT_ALG_SHA3_224) && \
     !defined(PSA_WANT_ALG_SHA3_256) && \
     !defined(PSA_WANT_ALG_SHA3_384) && \
     !defined(PSA_WANT_ALG_SHA3_512) && \
     !defined(PSA_WANT_ALG_SM3) && \
     !defined(PSA_WANT_ALG_SHAKE256_512))
#error "CRYPTO_HASH_MODULE_ENABLED enabled, but not all prerequisites (missing HASH algorithms)!"
#endif

#if CRYPTO_ASYM_SIGN_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN) && \
     !defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW) && \
     !defined(PSA_WANT_ALG_RSA_PSS) && \
     !defined(PSA_WANT_ALG_RSA_PSS_ANY_SALT) && \
     !defined(PSA_WANT_ALG_ECDSA) && \
     !defined(PSA_WANT_ALG_ECDSA_ANY) && \
     !defined(PSA_WANT_ALG_DETERMINISTIC_ECDSA) && \
     !defined(PSA_WANT_ALG_PURE_EDDSA) && \
     !defined(PSA_WANT_ALG_ED25519PH) && \
     !defined(PSA_WANT_ALG_ED448PH))
#error "CRYPTO_ASYM_SIGN_MODULE_ENABLED enabled, but not all prerequisites (missing asymmetric sign algorithms)!"
#endif

#if CRYPTO_ASYM_ENCRYPT_MODULE_ENABLED && \
    (!defined(PSA_WANT_ALG_RSA_PKCS1V15_CRYPT) && \
     !defined(PSA_WANT_ALG_RSA_OAEP))
#error "CRYPTO_ASYM_ENCRYPT_MODULE_ENABLED enabled, but not all prerequisites (missing asymmetric encryption algorithms)!"
#endif

#if CRYPTO_KEY_DERIVATION_MODULE_ENABLED && \
    (/* Key agreement */ \
     !defined(PSA_WANT_ALG_ECDH) && \
     !defined(PSA_WANT_ALG_FFDH) && \
     /* Key derivation */ \
     !defined(PSA_WANT_ALG_HKDF) && \
     !defined(PSA_WANT_ALG_HKDF_EXPAND) /* Not official PSA but exists in mbedtls */ && \
     !defined(PSA_WANT_ALG_HKDF_EXTRACT) /* Not official PSA but exists in mbedtls */  && \
     !defined(PSA_WANT_ALG_PBKDF2_HMAC) && \
     !defined(PSA_WANT_ALG_PBKDF2_AES_CMAC_PRF_128) && \
     !defined(PSA_WANT_ALG_TLS12_PRF) && \
     !defined(PSA_WANT_ALG_TLS12_PSK_TO_MS) && \
     !defined(PSA_WANT_ALG_TLS12_ECJPAKE_TO_PMS) /* Not official PSA but exists in mbedtls */)
#error "CRYPTO_KEY_DERIVATION_MODULE_ENABLED enabled, but not all prerequisites (missing key derivation algorithms)!"
#endif

#endif /* __CRYPTO_CHECK_CONFIG_H__ */

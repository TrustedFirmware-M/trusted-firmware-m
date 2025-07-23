/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_H__
#define __CC3XX_H__

/** @file cc3xx.h
 *
 * This file includes each module of the cc3xx driver that complies with the
 * PSA Cryptoprocessor Driver interface specification. the list of the
 * available modules is:
 *
 *  - Symmetric ciphers:                      cc3xx_psa_cipher.h
 *  - Access to TRNG for entropy extraction:  cc3xx_psa_entropy.h
 *  - Hashing:                                cc3xx_psa_hash.h
 *  - MAC signing/verification:               cc3xx_psa_mac.h
 *  - Authenticated Encryption w Assoc. Data: cc3xx_psa_aead.h
 *  - Raw key agreement:                      cc3xx_psa_key_agreement.h
 *  - Random key generation and key handling: cc3xx_psa_key_generation.h
 *  - Asymmetric signature schemes:           cc3xx_psa_asymmetric_signature.h
 *  - Asymmetric encryption schemes:          cc3xx_psa_asymmetric_encryption.h
 *  - Random generation:                      cc3xx_psa_random.h
 *
 * @note This file must be included by psa_crypto_driver_wrappers.c. The
 * definition of the context types used in the implementation is provided
 * through @ref cc3xx_crypto_primitives_private.h which is included, when
 * @ref PSA_CRYPTO_DRIVER_CC3XX is defined, in turn by @ref psa/crypto.h, then
 * psa/crypto_struct.h and finally by psa/crypto_driver_context_primitives.h
 * and by psa/crypto_driver_context_composites.h from the mbedTLS sources.
 */

#ifdef __DOXYGEN_ONLY__
/*!
 *  Enables the cc3xx driver in the PSA Driver Core layer. When this is
 *  defined, the \ref cc3xx_crypto_primitives_private.h type definitions are
 *  also visible through including \ref psa/crypto.h
 */
#define PSA_CRYPTO_DRIVER_CC3XX

/*!
 * Enables the Random module to use the HASH_DRBG PRNG construction as
 * described in SP800-90ar1. Note that the Random module can't support
 * more than one DRBG construction at build time
 */
#define CC3XX_CONFIG_ENABLE_RANDOM_HASH_DRBG

/*!
 * Enables the Random module to use the HMAC_DRBG PRNG construction as
 * described in SP800-90ar1. Note that the Random module can't support
 * more than one DRBG construction at build time
 */
#define CC3XX_CONFIG_ENABLE_RANDOM_HMAC_DRBG

/*!
 * Enables the Random module to use the CTR_DRBG PRNG construction as
 * described in SP800-90ar1. Note that the Random module can't support
 * more than one DRBG construction at build time
 */
#define CC3XX_CONFIG_ENABLE_RANDOM_CTR_DRBG

/*!
 * Enables the MAC module to perform the single-part API using a dedicated
 * function that directly calls into the low layer API, instead of resorting
 * to implementing it through the other PSA multipart APIs
 */
#define CC3XX_CONFIG_ENABLE_MAC_INTEGRATED_API

/*!
 * When set, AES-CBC-PKCS7 can decrypt arbitrary lengths during a multipart
 * update flow. Otherwise, the caller must pass multiples of the AES block
 * size to the update function. This option increases flexibility but it comes
 * with a tradeoff on code size and a performance decrease due to the additional
 * buffering required. It is required to pass PSA ACK test 236, see:
 * https://github.com/ARM-software/psa-arch-tests/tree/main/api-tests/dev_apis/crypto/test_c036
 */
#define CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS
#endif /* __DOXYGEN_ONLY__ */

#include "cc3xx_psa_init.h"
#include "cc3xx_psa_entropy.h"
#include "cc3xx_psa_hash.h"
#include "cc3xx_psa_random.h"
#include "cc3xx_psa_mac.h"
#include "cc3xx_psa_cipher.h"
#include "cc3xx_psa_asymmetric_encryption.h"
#include "cc3xx_psa_asymmetric_signature.h"
#include "cc3xx_psa_key_agreement.h"
#include "cc3xx_psa_key_generation.h"
#include "cc3xx_psa_aead.h"

#endif /* __CC3XX_H__ */

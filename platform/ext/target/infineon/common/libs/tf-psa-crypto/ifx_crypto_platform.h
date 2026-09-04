/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \file psa/crypto_platform.h
 *
 * \brief PSA cryptography module: TF-M platform definitions
 *
 * \note This file may not be included directly. Applications must
 * include psa/crypto.h.
 *
 * This file contains platform-dependent type definitions.
 *
 * In implementations with isolation between the application and the
 * cryptography module, implementers should take care to ensure that
 * the definitions that are exposed to applications match what the
 * module implements.
 */

#ifndef PSA_CRYPTO_TARGET_PLATFORM_H
#define PSA_CRYPTO_TARGET_PLATFORM_H

/* PSA requires several types which C99 provides in stdint.h. */
#include <stdint.h>

#include "psa/crypto_platform.h"

/** The CMAC KDF algorithm
 *
 * Key derivation in Counter Mode using CMAC as pseudo random function (PRF)
 * is defined in NIST SP 800-108 section 4.1.
 *
 * This key derivation algorithm uses the following inputs
 * - #PSA_KEY_DERIVATION_INPUT_SECRET is the key derivation key. It is a key
 *   that is used as an input to a key-derivation function (along with other
 *   input data) to derive keying material.
 * - #PSA_KEY_DERIVATION_INPUT_LABEL is a string that identifies the purpose
 *   for the derived keying material, which is encoded as a bit string.
 *   The encoding method for the Label is defined in a larger context,
 *   for example, in the protocol that uses a KDF.
 *   This input is optional.
 * - #PSA_KEY_DERIVATION_INPUT_SEED is a bit string that is used to seed the
 *   PRF. This input is optional.
 */
#define PSA_ALG_KDF_IFX_SE_AES_CMAC                 ((psa_algorithm_t)0x08000600)

/** The storage area located inside IFX SE Runtime Services */
#define PSA_KEY_LOCATION_IFX_SE                     ((psa_key_location_t)0x800001)

/* The slot number used to identify built-in keys.
 * Numbers are only used internally, so any number can be used */
#define PSA_CRYPTO_IFX_SE_HUK_SLOT_NUMBER           (0u)
#define PSA_CRYPTO_IFX_SE_OEM_ROT_SLOT_NUMBER       (1u)
#define PSA_CRYPTO_IFX_SE_SERVICES_UPD_SLOT_NUMBER  (2u)
#define PSA_CRYPTO_IFX_SE_IFX_ROT_SLOT_NUMBER       (3u)
#define PSA_CRYPTO_IFX_SE_DEVICE_PRIV_SLOT_NUMBER   (4u)
#define PSA_CRYPTO_IFX_SE_ATTEST_PRIV_SLOT_NUMBER   (5u)
#define PSA_CRYPTO_IFX_SE_ATTEST_PUB_SLOT_NUMBER    (6u)

/* IDs of supported built-in keys */
#define PSA_CRYPTO_IFX_SE_HUK_KEY_ID                (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_HUK_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_OEM_ROT_KEY_ID            (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_OEM_ROT_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_SERVICES_UPD_KEY_ID       (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_SERVICES_UPD_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_IFX_ROT_KEY_ID            (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_IFX_ROT_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_DEVICE_KEY_ID             (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_DEVICE_PRIV_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_ATTEST_PRIV_KEY_ID        (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_ATTEST_PRIV_SLOT_NUMBER)
#define PSA_CRYPTO_IFX_SE_ATTEST_PUB_KEY_ID         (MBEDTLS_PSA_KEY_ID_BUILTIN_MIN + PSA_CRYPTO_IFX_SE_ATTEST_PUB_SLOT_NUMBER)

/**
 * Maximum possible number of bytes a key derivation operation can output.
 *
 * This number is derived from the maximum number of bits which can be represented within
 * \p IFX_SCA_KEY_DERIVATION_CAPACITY_LENGTH bytes.
 */
#define PSA_IFX_SE_KEY_DERIVATION_MAX_CAPACITY       ((size_t)0x0FFFFFFF)

#endif /* PSA_CRYPTO_TARGET_PLATFORM_H */

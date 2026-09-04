/***************************************************************************//**
* \file platform_alt.h
*
* \brief This file contains the definitions and functions of the
*        IFX Mbed TLS platform abstraction layer.
*
********************************************************************************
* \copyright
* (c) 2022-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG. All rights reserved.
* This software, associated documentation and materials ("Software") is
* owned by Infineon Technologies AG or one of its affiliates ("Infineon")
* and is protected by and subject to worldwide patent protection, worldwide
* copyright laws, and international treaty provisions. Therefore, you may use
* this Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software. If no license
* agreement applies, then any use, reproduction, modification, translation, or
* compilation of this Software is prohibited without the express written
* permission of Infineon.
*
* Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
* IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
* THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
* SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
* Infineon reserves the right to make changes to the Software without notice.
* You are responsible for properly designing, programming, and testing the
* functionality and safety of your intended application of the Software, as
* well as complying with any legal requirements related to its use. Infineon
* does not guarantee that the Software will be free from intrusion, data theft
* or loss, or other breaches ("Security Breaches"), and Infineon shall have
* no liability arising out of any Security Breaches. Unless otherwise
* explicitly approved by Infineon, the Software may not be used in any
* application where a failure of the Product or any consequences of the use
* thereof can reasonably be expected to result in personal injury.
*******************************************************************************/

#ifndef MBEDTLS_PLATFORM_ALT_H
#define MBEDTLS_PLATFORM_ALT_H

#include "mbedtls/private_access.h"

#include "tf-psa-crypto/build_info.h"

#include <stddef.h>
#include <stdint.h>

#include "psa/crypto_types.h"

#ifndef MBEDTLS_PSA_KEY_ID_BUILTIN_MIN
#define MBEDTLS_PSA_KEY_ID_BUILTIN_MIN          ((psa_key_id_t) 0x7fff0000)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief   The platform context structure.
 *
 * \note    This structure may be used to assist platform-specific
 *          setup or teardown operations.
 */
typedef struct mbedtls_platform_context
{
    char MBEDTLS_PRIVATE(dummy); /**< A placeholder member, as empty structs are not portable. */
}
mbedtls_platform_context;

#if defined(IFX_PSA_SE_DPA_PRESENT)

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
#define PSA_IFX_SE_KEY_DERIVATION_MAX_CAPACITY      ((size_t)0x0FFFFFFF)

/* Use uint64_t (the underlying type of psa_drv_slot_number_t) here. The
 * psa_drv_slot_number_t typedef lives in psa/crypto_extra.h, which must only be
 * pulled in via psa/crypto.h; this header is included very early by
 * mbedtls/platform.h, so including crypto_extra.h here breaks the include order. */
psa_status_t ifx_mbedtls_get_builtin_key(
    uint64_t slot_number,
    psa_key_attributes_t *attributes,
    uint8_t *key_buffer, size_t key_buffer_size, size_t *key_buffer_length );

#endif /* IFX_PSA_SE_DPA_PRESENT */

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_PLATFORM_ALT_H */

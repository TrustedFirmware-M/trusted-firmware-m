/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "tfm_log.h"

#include "config_tfm.h"
#include "psa/crypto.h"
#include "psa/error.h"
#include "crypto_library.h"

/**
 * \brief This include is required to get the underlying platform function
 *        to allow the builtin keys support in mbed TLS to map slots to key
 *        IDs.
 */
#include "tfm_plat_crypto_keys.h"

/**
 * \brief This Mbed TLS include is needed to initialise the memory allocator
 *        of the library used for internal allocations
 */
#include "mbedtls/memory_buffer_alloc.h"

/**
 * \brief This Mbed TLS include is needed to set the mbedtls_printf to the
 *        function required by the TF-M framework in order to be able to
 *        print to terminal through mbedtls_printf
 */
#include "mbedtls/platform.h"

/**
 * \brief This Mbed TLS include is needed to retrieve version information for
 *        display
 */
#include "mbedtls/version.h"

#ifndef MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER
#error "MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER must be selected in Mbed TLS config file"
#endif

/**
 * \brief Static buffer containing the string describing the mbed TLS version. mbed TLS
 *        guarantees that the string will never be greater than 18 bytes
 */
static char mbedtls_version_full[18];

/**
 * \brief Static buffer to be used by Mbed Crypto for memory allocations
 *
 */
#include "config_engine_buf.h"
static uint8_t mbedtls_mem_buf[CRYPTO_ENGINE_BUF_SIZE] = {0};

/* Make sure the library won't print anything through mbedtls_printf */
static int null_printf(const char *fmt, ...)
{
    (void)fmt;
    return 0;
}

/*!
 * \defgroup tfm_crypto_library Set of functions implementing the abstractions of the underlying cryptographic
 *                              library that implements the PSA Crypto APIs to provide the PSA Crypto core
 *                              functionality to the TF-M Crypto service. Currently it supports only an
 *                              mbed TLS based abstraction.
 */
/*!@{*/
tfm_crypto_library_key_id_t tfm_crypto_library_key_id_init(int32_t owner, psa_key_id_t key_id)
{
    return mbedtls_svc_key_id_make(owner, key_id);
}

char *tfm_crypto_library_get_info(void)
{
    memcpy(mbedtls_version_full, MBEDTLS_VERSION_STRING_FULL, sizeof(MBEDTLS_VERSION_STRING_FULL));
    return mbedtls_version_full;
}

psa_status_t tfm_crypto_core_library_init(void)
{
    /* Initialise the Mbed Crypto memory allocator to use static memory
     * allocation from the provided buffer instead of using the heap
     */
    mbedtls_memory_buffer_alloc_init(mbedtls_mem_buf,
                                     CRYPTO_ENGINE_BUF_SIZE);

    mbedtls_platform_set_printf(null_printf);

    VERBOSE("[Crypto] Internal heap size is %d bytes\n", sizeof(mbedtls_mem_buf));

    return PSA_SUCCESS;
}

void tfm_crypto_library_get_library_key_id_set_owner(int32_t owner, psa_key_attributes_t *attr)
{
    attr->MBEDTLS_PRIVATE(id).MBEDTLS_PRIVATE(owner) = owner;
}

/**
 * \brief This function is required by mbed TLS to enable support for
 *        platform builtin keys in the PSA Crypto core layer implemented
 *        by mbed TLS. This function is not standardized by the API hence
 *        this layer directly provides the symbol required by the library
 *
 * \note It maps builtin key IDs to cryptographic drivers and slots. The
 *       actual data is deferred to a platform function, as different
 *       platforms may have different key storage capabilities.
 */
psa_status_t mbedtls_psa_platform_get_builtin_key(
    mbedtls_svc_key_id_t key_id,
    psa_key_lifetime_t *lifetime,
    psa_drv_slot_number_t *slot_number)
{
    const tfm_plat_builtin_key_descriptor_t *desc_table = NULL;
    size_t number_of_keys = tfm_plat_builtin_key_get_desc_table_ptr(&desc_table);

    for (size_t idx = 0; idx < number_of_keys; idx++) {
        if (desc_table[idx].key_id == MBEDTLS_SVC_KEY_ID_GET_KEY_ID(key_id)) {
            *lifetime = desc_table[idx].lifetime;
            *slot_number = desc_table[idx].slot_number;
            return PSA_SUCCESS;
        }
    }

    return PSA_ERROR_DOES_NOT_EXIST;
}
/*!@}*/

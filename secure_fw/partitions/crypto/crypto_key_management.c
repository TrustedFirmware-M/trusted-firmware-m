/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "config_tfm.h"
#include "coverity_check.h"
#include "tfm_mbedcrypto_include.h"
#include "tfm_crypto_api.h"
#include "tfm_crypto_key.h"
#include "tfm_crypto_defs.h"

#include "crypto_library.h"

TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_11_5, "It's PSA API design to use pointer to void")
/*!
 * \addtogroup tfm_crypto_api_shim_layer
 *
 */

/*!@{*/
#if CRYPTO_KEY_MODULE_ENABLED
psa_status_t tfm_crypto_key_management_interface(psa_invec in_vec[],
                                                 psa_outvec out_vec[],
                                                 struct tfm_crypto_key_id_s *encoded_key)
{
    const struct tfm_crypto_pack_iovec *iov = in_vec[0].base;
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    /* Build a key_id in the library key format, i.e. (owner, key_id) */
    tfm_crypto_library_key_id_t library_key = tfm_crypto_library_key_id_init(
                                                  encoded_key->owner, encoded_key->key_id);
    psa_key_attributes_t srv_key_attr;

    switch (iov->function_id) {
    case TFM_CRYPTO_IMPORT_KEY_SID:
    case TFM_CRYPTO_COPY_KEY_SID:
    case TFM_CRYPTO_GENERATE_KEY_SID:
        if ((in_vec[1].base == NULL) ||
            (in_vec[1].len != (sizeof(srv_key_attr) - TFM_CRYPTO_KEY_ATTR_OFFSET_CLIENT_SERVER))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }
        memcpy(&srv_key_attr, in_vec[1].base, in_vec[1].len);
        tfm_crypto_library_get_library_key_id_set_owner(encoded_key->owner, &srv_key_attr);
        break;
    default:
        break;
    }

    switch (iov->function_id) {
    case TFM_CRYPTO_IMPORT_KEY_SID:
    {
        const uint8_t *data = in_vec[2].base;
        size_t data_length = in_vec[2].len;
        psa_key_id_t *key_id = out_vec[0].base;
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(psa_key_id_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        status = psa_import_key(&srv_key_attr,
                                data, data_length, &library_key);
        /* Update the imported key id */
        *key_id = CRYPTO_LIBRARY_GET_KEY_ID(library_key);
    }
    break;
    case TFM_CRYPTO_DESTROY_KEY_SID:
    {
        status = psa_destroy_key(library_key);
    }
    break;
    case TFM_CRYPTO_GET_KEY_ATTRIBUTES_SID:
    {
        psa_key_attributes_t *key_attributes = out_vec[0].base;

        status = psa_get_key_attributes(library_key, &srv_key_attr);

        /* Note that we just copy out_vec[0].len, because in this context
         * sizeof(psa_key_attributes_t) would return the size of the service
         * view of the attributes, while we are passing back to the caller
         * only the client view of it, i.e. without the owner field at the
         * end of the structure
         */
        if ((out_vec[0].base == NULL) || (out_vec[0].len > sizeof(psa_key_attributes_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }
        memcpy(key_attributes, &srv_key_attr, out_vec[0].len);
    }
    break;
    case TFM_CRYPTO_EXPORT_KEY_SID:
    {
        uint8_t *data = out_vec[0].base;
        size_t data_size = out_vec[0].len;

        status = psa_export_key(library_key, data, data_size,
                                &(out_vec[0].len));
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
    }
    break;
    case TFM_CRYPTO_EXPORT_PUBLIC_KEY_SID:
    {
        uint8_t *data = out_vec[0].base;
        size_t data_size = out_vec[0].len;

        status = psa_export_public_key(library_key, data, data_size,
                                       &(out_vec[0].len));
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
    }
    break;
    case TFM_CRYPTO_PURGE_KEY_SID:
    {
        status = psa_purge_key(library_key);
    }
    break;
    case TFM_CRYPTO_COPY_KEY_SID:
    {
        psa_key_id_t *target_key_id = out_vec[0].base;
        tfm_crypto_library_key_id_t target_key = tfm_crypto_library_key_id_init_default();
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(psa_key_id_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        status = psa_copy_key(library_key,
                              &srv_key_attr,
                              &target_key);
        if (status != PSA_SUCCESS) {
            return status;
        }

        *target_key_id = CRYPTO_LIBRARY_GET_KEY_ID(target_key);
    }
    break;
    case TFM_CRYPTO_GENERATE_KEY_SID:
    {
        psa_key_id_t *key_handle = out_vec[0].base;
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(psa_key_id_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        status = psa_generate_key(&srv_key_attr, &library_key);
        if (status != PSA_SUCCESS) {
            return status;
        }

        *key_handle = CRYPTO_LIBRARY_GET_KEY_ID(library_key);
    }
    break;
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}
#else /* CRYPTO_KEY_MODULE_ENABLED  */
psa_status_t tfm_crypto_key_management_interface(psa_invec in_vec[],
                                                 psa_outvec out_vec[],
                                                 struct tfm_crypto_key_id_s *encoded_key)
{
    (void)in_vec;
    (void)out_vec;
    (void)encoded_key;

    return PSA_ERROR_NOT_SUPPORTED;
}
#endif /* CRYPTO_KEY_MODULE_ENABLED  */
/*!@}*/
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_11_5)

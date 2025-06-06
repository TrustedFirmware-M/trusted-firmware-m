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

#include "tfm_mbedcrypto_include.h"

#include "tfm_crypto_api.h"
#include "tfm_crypto_key.h"
#include "tfm_crypto_defs.h"

#include "crypto_library.h"

/*!
 * \addtogroup tfm_crypto_api_shim_layer
 *
 */

/*!@{*/
#if CRYPTO_KEY_DERIVATION_MODULE_ENABLED
psa_status_t tfm_crypto_key_derivation_interface(psa_invec in_vec[],
                                                 psa_outvec out_vec[],
                                                 struct tfm_crypto_key_id_s *encoded_key)
{
    const struct tfm_crypto_pack_iovec *iov = in_vec[0].base;
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;
    psa_key_derivation_operation_t *operation = NULL;
    uint32_t *p_handle = NULL;
    enum tfm_crypto_func_sid_t sid = (enum tfm_crypto_func_sid_t)iov->function_id;

    tfm_crypto_library_key_id_t library_key = tfm_crypto_library_key_id_init(
                                                  encoded_key->owner, encoded_key->key_id);
    if (sid == TFM_CRYPTO_RAW_KEY_AGREEMENT_SID) {
        uint8_t *output = out_vec[0].base;
        size_t output_size = out_vec[0].len;
        const uint8_t *peer_key = in_vec[1].base;
        size_t peer_key_length = in_vec[1].len;

        return psa_raw_key_agreement(iov->alg, library_key,
                                     peer_key, peer_key_length,
                                     output, output_size, &out_vec[0].len);
    }

    if (sid == TFM_CRYPTO_KEY_DERIVATION_SETUP_SID) {
        p_handle = out_vec[0].base;

        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(*p_handle))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        *p_handle = iov->op_handle;
        status = tfm_crypto_operation_alloc(TFM_CRYPTO_KEY_DERIVATION_OPERATION,
                                            out_vec[0].base,
                                            (void **)&operation);
    } else {
        status = tfm_crypto_operation_lookup(
                                            TFM_CRYPTO_KEY_DERIVATION_OPERATION,
                                            iov->op_handle,
                                            (void **)&operation);
    }
    if ((status != PSA_SUCCESS) &&
        (sid != TFM_CRYPTO_KEY_DERIVATION_ABORT_SID)) {
        return status;
    }

    switch (sid) {
    case TFM_CRYPTO_KEY_DERIVATION_SETUP_SID:
    {
        status = psa_key_derivation_setup(operation, iov->alg);

        if (status != PSA_SUCCESS) {
            goto release_operation_and_return;
        }
    }
    break;
    case TFM_CRYPTO_KEY_DERIVATION_GET_CAPACITY_SID:
    {
        size_t *capacity = out_vec[0].base;

        if ((out_vec[0].base == NULL) || (out_vec[0].len != sizeof(*capacity))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        return psa_key_derivation_get_capacity(operation, capacity);
    }
    case TFM_CRYPTO_KEY_DERIVATION_SET_CAPACITY_SID:
    {
        return psa_key_derivation_set_capacity(operation, iov->capacity);
    }
    case TFM_CRYPTO_KEY_DERIVATION_INPUT_BYTES_SID:
    {
        const uint8_t *data = in_vec[1].base;
        size_t data_length = in_vec[1].len;

        return psa_key_derivation_input_bytes(operation, iov->step, data,
                                              data_length);
    }
    case TFM_CRYPTO_KEY_DERIVATION_INPUT_INTEGER_SID:
    {
        return psa_key_derivation_input_integer(operation, iov->step, iov->value);
    }
    case TFM_CRYPTO_KEY_DERIVATION_OUTPUT_BYTES_SID:
    {
        uint8_t *output = out_vec[0].base;
        size_t output_length = out_vec[0].len;

        return psa_key_derivation_output_bytes(operation,
                                               output, output_length);
    }
    case TFM_CRYPTO_KEY_DERIVATION_INPUT_KEY_SID:
    {
         return psa_key_derivation_input_key(operation,
                                             iov->step, library_key);
    }
    case TFM_CRYPTO_KEY_DERIVATION_OUTPUT_KEY_SID:
    {
        psa_key_id_t *key_handle = out_vec[0].base;
        psa_key_attributes_t srv_key_attr;
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(psa_key_id_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        if ((in_vec[1].base == NULL) ||
            (in_vec[1].len != (sizeof(srv_key_attr) - TFM_CRYPTO_KEY_ATTR_OFFSET_CLIENT_SERVER))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }
        memcpy(&srv_key_attr, in_vec[1].base, in_vec[1].len);
        tfm_crypto_library_get_library_key_id_set_owner(encoded_key->owner, &srv_key_attr);

        status = psa_key_derivation_output_key(&srv_key_attr, operation,
                                               &library_key);

        *key_handle = CRYPTO_LIBRARY_GET_KEY_ID(library_key);
    }
    break;
    case TFM_CRYPTO_KEY_DERIVATION_ABORT_SID:
    {
        p_handle = out_vec[0].base;
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(iov->op_handle))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }
        *p_handle = iov->op_handle;

        if (status != PSA_SUCCESS) {
            /*
             * If lookup() failed to find out a valid operation, it is not
             * an error for _abort(), as it is allowed to be called multiple
             * times, and it is likely the operation has just already been
             * aborted.
             */
            return PSA_SUCCESS;
        }

        status = psa_key_derivation_abort(operation);

        goto release_operation_and_return;
    }
    case TFM_CRYPTO_KEY_DERIVATION_KEY_AGREEMENT_SID:
    {
        const uint8_t *peer_key = in_vec[1].base;
        size_t peer_key_length = in_vec[1].len;

        return psa_key_derivation_key_agreement(operation, iov->step,
                                                library_key,
                                                peer_key,
                                                peer_key_length);
    }
    break;
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return status;

release_operation_and_return:
    /* Release the operation context, ignore if the operation fails. */
    (void)tfm_crypto_operation_release(p_handle);
    return status;
}
#else /* CRYPTO_KEY_DERIVATION_MODULE_ENABLED */
psa_status_t tfm_crypto_key_derivation_interface(psa_invec in_vec[],
                                                 psa_outvec out_vec[],
                                                 struct tfm_crypto_key_id_s *encoded_key)
{
    (void)in_vec;
    (void)out_vec;
    (void)encoded_key;

    return PSA_ERROR_NOT_SUPPORTED;
}
#endif /* CRYPTO_KEY_DERIVATION_MODULE_ENABLED */
/*!@}*/

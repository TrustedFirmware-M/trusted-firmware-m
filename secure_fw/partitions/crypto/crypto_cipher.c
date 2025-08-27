/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>

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
#if CRYPTO_CIPHER_MODULE_ENABLED
/**
 * \brief Check whether PSA is capable of handling the specified cipher algorithm and the given key
 * type.
 *
 * \note  As service initialization is performed during TF-M boot up, so there is no need
 *        to check whether psa_crypto_init has already been called.
 *
 * \param[in] key_type  The key type.
 * \param[in] alg       The cipher algorithm.
 *
 * \return 1 if the PSA can handle \p alg and the given \p key_type, 0 otherwise.
 */
int tfm_crypto_can_do_cipher(psa_key_type_t key_type, psa_algorithm_t alg)
{
    /* Check whether desired key type is available. */
    switch (key_type) {
#if defined(PSA_WANT_KEY_TYPE_AES)
    case PSA_KEY_TYPE_AES:
        break;
#endif
#if defined(PSA_WANT_KEY_TYPE_ARIA)
    case PSA_KEY_TYPE_ARIA:
        break;
#endif
#if defined(PSA_WANT_KEY_TYPE_CAMELLIA)
    case PSA_KEY_TYPE_CAMELLIA:
        break;
#endif
#if defined(PSA_WANT_KEY_TYPE_DES)
    case PSA_KEY_TYPE_DES:
        break;
#endif
#if defined(PSA_WANT_KEY_TYPE_CHACHA20)
    case PSA_KEY_TYPE_CHACHA20:
        break;
#endif
    default:
        return 0;
    }

    /* Check whether desired algorithm is available. */
    if (PSA_ALG_IS_AEAD(alg)) {
        alg = PSA_ALG_AEAD_WITH_SHORTENED_TAG(alg, 0);
    }

    switch (alg) {
#if defined(PSA_WANT_ALG_CTR)
    case PSA_ALG_CTR:
        break;
#endif
#if defined(PSA_WANT_ALG_CFB)
    case PSA_ALG_CFB:
        break;
#endif
#if defined(PSA_WANT_ALG_OFB)
    case PSA_ALG_OFB:
        break;
#endif
#if defined(PSA_WANT_ALG_XTS)
    case PSA_ALG_XTS:
        break;
#endif
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
    case PSA_ALG_ECB_NO_PADDING:
        break;
#endif
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
    case PSA_ALG_CBC_NO_PADDING:
        break;
#endif
#if defined(PSA_WANT_ALG_CBC_PKCS7)
    case PSA_ALG_CBC_PKCS7:
        break;
#endif
#if defined(PSA_WANT_ALG_CMAC)
    case PSA_ALG_CMAC:
        break;
#endif
#if defined(PSA_WANT_ALG_CCM_STAR_NO_TAG)
    case PSA_ALG_CCM_STAR_NO_TAG:
        break;
#endif
#if defined(PSA_WANT_ALG_CCM)
    case PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_CCM, 0):
        break;
#endif
#if defined(PSA_WANT_ALG_GCM)
    case PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_GCM, 0):
        break;
#endif
#if defined(PSA_WANT_ALG_STREAM_CIPHER)
    case PSA_ALG_STREAM_CIPHER:
        break;
#endif
#if defined(PSA_WANT_ALG_CHACHA20_POLY1305)
    case PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_CHACHA20_POLY1305, 0):
        break;
#endif
    default:
        return 0;
    }

    return 1;
}

psa_status_t tfm_crypto_cipher_interface(psa_invec in_vec[],
                                         psa_outvec out_vec[],
                                         struct tfm_crypto_key_id_s *encoded_key)
{
    const struct tfm_crypto_pack_iovec *iov = in_vec[0].base;
    psa_status_t status = PSA_ERROR_NOT_SUPPORTED;
    psa_cipher_operation_t *operation = NULL;
    uint32_t *p_handle = NULL;
    enum tfm_crypto_func_sid_t sid = (enum tfm_crypto_func_sid_t)iov->function_id;

    if (sid == TFM_CRYPTO_CAN_DO_CIPHER_SID) {
        int *p_result = out_vec[0].base;
        const psa_key_type_t *p_key_type = in_vec[1].base;

        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(int)) ||
            (in_vec[1].base == NULL) || (in_vec[1].len < sizeof(psa_key_type_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        *p_result = tfm_crypto_can_do_cipher(*p_key_type, iov->alg);
        return PSA_SUCCESS;
    }

    tfm_crypto_library_key_id_t library_key = tfm_crypto_library_key_id_init(
                                                  encoded_key->owner, encoded_key->key_id);
    if (sid == TFM_CRYPTO_CIPHER_ENCRYPT_SID) {
#if CRYPTO_SINGLE_PART_FUNCS_DISABLED
        return PSA_ERROR_NOT_SUPPORTED;
#else
        const uint8_t *input = in_vec[1].base;
        size_t input_length = in_vec[1].len;
        uint8_t *output = out_vec[0].base;
        size_t output_size = out_vec[0].len;

        status = psa_cipher_encrypt(library_key, iov->alg, input, input_length,
                                    output, output_size, &out_vec[0].len);
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
        return status;
#endif
    }

    if (sid == TFM_CRYPTO_CIPHER_DECRYPT_SID) {
#if CRYPTO_SINGLE_PART_FUNCS_DISABLED
        return PSA_ERROR_NOT_SUPPORTED;
#else
        const uint8_t *input = in_vec[1].base;
        size_t input_length = in_vec[1].len;
        uint8_t *output = out_vec[0].base;
        size_t output_size = out_vec[0].len;

        status = psa_cipher_decrypt(library_key, iov->alg, input, input_length,
                                    output, output_size, &out_vec[0].len);
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
        return status;
#endif
    }

    if ((sid == TFM_CRYPTO_CIPHER_ENCRYPT_SETUP_SID) ||
        (sid == TFM_CRYPTO_CIPHER_DECRYPT_SETUP_SID)) {
        p_handle = out_vec[0].base;
        if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(uint32_t))) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }
        *p_handle = iov->op_handle;
        status = tfm_crypto_operation_alloc(TFM_CRYPTO_CIPHER_OPERATION,
                                            out_vec[0].base,
                                            (void **)&operation);
    } else {
        status = tfm_crypto_operation_lookup(TFM_CRYPTO_CIPHER_OPERATION,
                                             iov->op_handle,
                                             (void **)&operation);
        if ((sid == TFM_CRYPTO_CIPHER_FINISH_SID) ||
            (sid == TFM_CRYPTO_CIPHER_ABORT_SID)) {
            /*
             * finish()/abort() interface put handle in out_vec[0].
             * Therefore, out_vec[0] shall be specially set to original handle
             * value. Otherwise, the garbage data in message out_vec[0] may
             * override the original handle value in client, after lookup fails.
             */
            p_handle = out_vec[0].base;
            if ((out_vec[0].base == NULL) || (out_vec[0].len < sizeof(uint32_t))) {
                return PSA_ERROR_PROGRAMMER_ERROR;
            }
            *p_handle = iov->op_handle;
        }
    }
    if (status != PSA_SUCCESS) {
        if (sid == TFM_CRYPTO_CIPHER_ABORT_SID) {
            /*
             * Mbed TLS psa_cipher_abort() will return a misleading error code
             * if it is called with invalid operation content, since it
             * doesn't validate the operation handle.
             * It is neither necessary to call tfm_crypto_operation_release()
             * with an invalid handle.
             * Therefore return PSA_SUCCESS directly as psa_cipher_abort() can
             * be called multiple times.
             */
            return PSA_SUCCESS;
        }
        return status;
    }

    switch (sid) {
    case TFM_CRYPTO_CIPHER_GENERATE_IV_SID:
    {
        unsigned char *iv = out_vec[0].base;
        size_t iv_size = out_vec[0].len;

        status = psa_cipher_generate_iv(operation, iv, iv_size, &out_vec[0].len);
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
        return status;
    }
    case TFM_CRYPTO_CIPHER_SET_IV_SID:
    {
        const unsigned char *iv = in_vec[1].base;
        size_t iv_length = in_vec[1].len;

        return psa_cipher_set_iv(operation, iv, iv_length);
    }
    case TFM_CRYPTO_CIPHER_ENCRYPT_SETUP_SID:
    {
        status = psa_cipher_encrypt_setup(operation, library_key, iov->alg);
        if (status != PSA_SUCCESS) {
            goto release_operation_and_return;
        }
    }
    break;
    case TFM_CRYPTO_CIPHER_DECRYPT_SETUP_SID:
    {
        status = psa_cipher_decrypt_setup(operation, library_key, iov->alg);
        if (status != PSA_SUCCESS) {
            goto release_operation_and_return;
        }
    }
    break;
    case TFM_CRYPTO_CIPHER_UPDATE_SID:
    {
        const uint8_t *input = in_vec[1].base;
        size_t input_length = in_vec[1].len;
        unsigned char *output = out_vec[0].base;
        size_t output_size = out_vec[0].len;

        status = psa_cipher_update(operation, input, input_length,
                                   output, output_size, &out_vec[0].len);
        if (status != PSA_SUCCESS) {
            out_vec[0].len = 0;
        }
        return status;
    }
    case TFM_CRYPTO_CIPHER_FINISH_SID:
    {
        uint8_t *output = out_vec[1].base;
        size_t output_size = out_vec[1].len;

        status = psa_cipher_finish(operation,
                                   output, output_size, &out_vec[1].len);
        if (status == PSA_SUCCESS) {
            /* In case of success automatically release the operation */
            goto release_operation_and_return;
        } else {
            out_vec[1].len = 0;
        }
    }
    break;
    case TFM_CRYPTO_CIPHER_ABORT_SID:
    {
        status = psa_cipher_abort(operation);
        goto release_operation_and_return;
    }
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return status;

release_operation_and_return:
    /* Release the operation context, ignore if the operation fails. */
    (void)tfm_crypto_operation_release(p_handle);
    return status;
}
#else /* CRYPTO_CIPHER_MODULE_ENABLED */
psa_status_t tfm_crypto_cipher_interface(psa_invec in_vec[],
                                         psa_outvec out_vec[],
                                         struct tfm_crypto_key_id_s *encoded_key)
{
    (void)in_vec;
    (void)out_vec;
    (void)encoded_key;

    return PSA_ERROR_NOT_SUPPORTED;
}
#endif /* CRYPTO_CIPHER_MODULE_ENABLED */
/*!@}*/

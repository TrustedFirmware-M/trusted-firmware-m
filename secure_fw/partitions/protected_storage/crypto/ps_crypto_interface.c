/*
 * Copyright (c) 2017-2022, Arm Limited. All rights reserved.
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ps_crypto_interface.h"

#include <stdbool.h>
#include <string.h>

#include "config_tfm.h"
#include "tfm_crypto_defs.h"
#include "psa/crypto.h"

#define PS_KEY_LEN_BYTES  16

#ifndef PS_CRYPTO_AEAD_ALG
#define PS_CRYPTO_AEAD_ALG PSA_ALG_GCM
#endif

/* The PSA key type used by this implementation */
#define PS_KEY_TYPE PSA_KEY_TYPE_AES
/* The PSA key usage required by this implementation */
#define PS_KEY_USAGE (PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT)

/* The PSA algorithm used by this implementation */
#define PS_CRYPTO_ALG \
    PSA_ALG_AEAD_WITH_SHORTENED_TAG(PS_CRYPTO_AEAD_ALG, PS_TAG_LEN_BYTES)

/* Length of the label used to derive a crypto key */
#if PS_AES_KEY_USAGE_LIMIT == 0
#define LABEL_LEN (sizeof(int32_t) + sizeof(psa_storage_uid_t))
#else
#define LABEL_LEN (sizeof(int32_t) + sizeof(psa_storage_uid_t) + sizeof(uint32_t))
#endif

/*
 * \brief Check whether the PS AEAD algorithm is a valid one
 *
 * Triggers a compilation error if the input algorithm is not a valid AEAD
 * algorithm. The compilation error should be
 * "error: 'PS_ERROR_NOT_AEAD_ALG' declared as an array with a negative size"
 */
typedef char PS_ERROR_NOT_AEAD_ALG[(PSA_ALG_IS_AEAD(PS_CRYPTO_ALG)) ? 1 : -1];

static uint8_t ps_crypto_iv_buf[PS_IV_LEN_BYTES];

static void fill_key_label(const union ps_crypto_t *crypto,
                           uint8_t *label)
{
    psa_storage_uid_t uid = crypto->ref.uid;
    int32_t client_id = crypto->ref.client_id;
#if PS_AES_KEY_USAGE_LIMIT != 0
    uint32_t gen = crypto->ref.key_gen_nr;
#endif

    memcpy(label, &client_id, sizeof(client_id));
    memcpy(label + sizeof(client_id), &uid, sizeof(uid));
#if PS_AES_KEY_USAGE_LIMIT != 0
    memcpy(label + sizeof(client_id) + sizeof(uid), &gen, sizeof(gen));
#endif
}

static psa_status_t ps_crypto_setkey(psa_key_id_t *ps_key,
                                     const uint8_t *key_label,
                                     size_t key_label_len)
{
    psa_status_t status;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_derivation_operation_t op = PSA_KEY_DERIVATION_OPERATION_INIT;

    if (key_label_len == 0 || key_label == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Set the key attributes for the storage key */
    psa_set_key_usage_flags(&attributes, PS_KEY_USAGE);
    psa_set_key_algorithm(&attributes, PS_CRYPTO_ALG);
    psa_set_key_type(&attributes, PS_KEY_TYPE);
    psa_set_key_bits(&attributes, PSA_BYTES_TO_BITS(PS_KEY_LEN_BYTES));

    status = psa_key_derivation_setup(&op, PSA_ALG_HKDF(PSA_ALG_SHA_256));
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Set up a key derivation operation with HUK  */
    status = psa_key_derivation_input_key(&op, PSA_KEY_DERIVATION_INPUT_SECRET,
                                          TFM_BUILTIN_KEY_ID_HUK);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Supply the PS key label as an input to the key derivation */
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_INFO,
                                            key_label,
                                            key_label_len);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Create the storage key from the key derivation operation */
    status = psa_key_derivation_output_key(&attributes, &op, ps_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Free resources associated with the key derivation operation */
    status = psa_key_derivation_abort(&op);
    if (status != PSA_SUCCESS) {
        goto err_release_key;
    }

    return PSA_SUCCESS;

err_release_key:
    (void)psa_destroy_key(*ps_key);

err_release_op:
    (void)psa_key_derivation_abort(&op);

    return PSA_ERROR_GENERIC_ERROR;
}

psa_status_t ps_crypto_init(void)
{
    /* For GCM and CCM it is essential that nonce doesn't get repeated. If there
     * is no rollback protection, an attacker could try to rollback the storage and
     * encrypt another plaintext block with same IV/Key pair; this breaks GCM and CCM
     * usage rules.
     */
    const psa_algorithm_t ps_crypto_aead_alg = PS_CRYPTO_AEAD_ALG;
#ifndef PS_ROLLBACK_PROTECTION
    if ((ps_crypto_aead_alg == PSA_ALG_GCM) || (ps_crypto_aead_alg == PSA_ALG_CCM)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }
#else
    (void)ps_crypto_aead_alg;
#endif
    return PSA_SUCCESS;
}

uint32_t ps_crypto_to_blocks(size_t in_len)
{
    /* add one additional block to account for the finish operation */
    return 1 + (in_len + PSA_BLOCK_CIPHER_BLOCK_LENGTH(PSA_KEY_TYPE_AES) - 1)
                / PSA_BLOCK_CIPHER_BLOCK_LENGTH(PSA_KEY_TYPE_AES);
}

void ps_crypto_set_iv(const union ps_crypto_t *crypto)
{
    (void)memcpy(ps_crypto_iv_buf, crypto->ref.iv, PS_IV_LEN_BYTES);
}

psa_status_t ps_crypto_get_iv(union ps_crypto_t *crypto)
{
    /* IV characteristic is algorithm dependent.
     * For GCM it is essential that it doesn't get repeated.
     * A simple increment will suffice.
     * FIXME:
     * Since IV is predictable in this case,
     * If there is no rollback protection, an attacker could
     * try to rollback the storage and encrypt another plaintext
     * block with same IV/Key pair; this breaks GCM usage rules.
     * One potential fix would be to generate IV through RNG
     */

    /* Logic:
     * IV is a 12 byte value. Read the old value and increment it by 1.
     * since there is no standard C support for 12 byte integer mathematics,
     * the increment need to performed manually. Increment the lower 8byte
     * as uint64_t value and then if the new value is 0, increment the upper
     * 4 bytes as uint32_t
     * Endian order doesn't really matter as objective is not to perform
     * machine accurate increment operation but to generate a non-repetitive
     * iv value.
     */

    uint64_t iv_l;
    uint32_t iv_h;

    (void)memcpy(&iv_l, ps_crypto_iv_buf, sizeof(iv_l));
    (void)memcpy(&iv_h, (ps_crypto_iv_buf+sizeof(iv_l)), sizeof(iv_h));
    iv_l++;
    /* If overflow, increment the MSBs */
    if (iv_l == 0) {
        iv_h++;

        /* If overflow, return error. Different IV should be used. */
        if (iv_h == 0) {
            /* Reset iv_l and iv_h to the value before increasement. Otherwise,
             * iv_l will start from '1' the next time this function is called.
             */
            iv_l--;
            iv_h--;
            return PSA_ERROR_GENERIC_ERROR;
        }
    }

    /* Update the local buffer */
    (void)memcpy(ps_crypto_iv_buf, &iv_l, sizeof(iv_l));
    (void)memcpy((ps_crypto_iv_buf + sizeof(iv_l)), &iv_h, sizeof(iv_h));
    /* Update the caller buffer */
    (void)memcpy(crypto->ref.iv, ps_crypto_iv_buf, PS_IV_LEN_BYTES);

    return PSA_SUCCESS;
}

psa_status_t ps_crypto_encrypt_and_tag(union ps_crypto_t *crypto,
                                       const uint8_t *add,
                                       size_t add_len,
                                       const uint8_t *in,
                                       size_t in_len,
                                       uint8_t *out,
                                       size_t out_size,
                                       size_t *out_len)
{
    psa_status_t status;
    psa_key_id_t ps_key = 0;
    uint8_t label[LABEL_LEN];

    fill_key_label(crypto, label);

    status = ps_crypto_setkey(&ps_key, label, sizeof(label));
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_aead_encrypt(ps_key, PS_CRYPTO_ALG,
                              crypto->ref.iv, PS_IV_LEN_BYTES,
                              add, add_len,
                              in, in_len,
                              out, out_size, out_len);
    if (status != PSA_SUCCESS) {
        (void)psa_destroy_key(ps_key);
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Copy the tag out of the output buffer */
    *out_len -= PS_TAG_LEN_BYTES;
    (void)memcpy(crypto->ref.tag, (out + *out_len), PS_TAG_LEN_BYTES);

    /* Destroy the transient key */
    status = psa_destroy_key(ps_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

psa_status_t ps_crypto_auth_and_decrypt(const union ps_crypto_t *crypto,
                                        const uint8_t *add,
                                        size_t add_len,
                                        uint8_t *in,
                                        size_t in_len,
                                        uint8_t *out,
                                        size_t out_size,
                                        size_t *out_len)
{
    psa_status_t status;
    psa_key_id_t ps_key = 0;
    uint8_t label[LABEL_LEN];

    fill_key_label(crypto, label);

    /* Copy the tag into the input buffer */
    (void)memcpy((in + in_len), crypto->ref.tag, PS_TAG_LEN_BYTES);
    in_len += PS_TAG_LEN_BYTES;

    status = ps_crypto_setkey(&ps_key, label, sizeof(label));
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_aead_decrypt(ps_key, PS_CRYPTO_ALG,
                              crypto->ref.iv, PS_IV_LEN_BYTES,
                              add, add_len,
                              in, in_len,
                              out, out_size, out_len);
    if (status != PSA_SUCCESS) {
        (void)psa_destroy_key(ps_key);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Destroy the transient key */
    status = psa_destroy_key(ps_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

psa_status_t ps_crypto_generate_auth_tag(union ps_crypto_t *crypto,
                                         const uint8_t *add,
                                         uint32_t add_len)
{
    psa_status_t status;
    size_t out_len;
    psa_key_id_t ps_key = 0;
    uint8_t label[LABEL_LEN];

    fill_key_label(crypto, label);

    status = ps_crypto_setkey(&ps_key, label, sizeof(label));
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_aead_encrypt(ps_key, PS_CRYPTO_ALG,
                              crypto->ref.iv, PS_IV_LEN_BYTES,
                              add, add_len,
                              0, 0,
                              crypto->ref.tag, PS_TAG_LEN_BYTES, &out_len);
    if (status != PSA_SUCCESS || out_len != PS_TAG_LEN_BYTES) {
        (void)psa_destroy_key(ps_key);
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Destroy the transient key */
    status = psa_destroy_key(ps_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

psa_status_t ps_crypto_authenticate(const union ps_crypto_t *crypto,
                                    const uint8_t *add,
                                    uint32_t add_len)
{
    psa_status_t status;
    size_t out_len;
    psa_key_id_t ps_key = 0;
    uint8_t label[LABEL_LEN];

    fill_key_label(crypto, label);

    status = ps_crypto_setkey(&ps_key, label, sizeof(label));
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_aead_decrypt(ps_key, PS_CRYPTO_ALG,
                              crypto->ref.iv, PS_IV_LEN_BYTES,
                              add, add_len,
                              crypto->ref.tag, PS_TAG_LEN_BYTES,
                              0, 0, &out_len);
    if (status != PSA_SUCCESS || out_len != 0) {
        (void)psa_destroy_key(ps_key);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Destroy the transient key */
    status = psa_destroy_key(ps_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}

#ifdef PS_SUPPORT_FORMAT_TRANSITION
psa_status_t ps_crypto_authenticate_transition(const union ps_crypto_t *crypto,
                                               const uint8_t *add,
                                               uint32_t add_len)
{
    psa_status_t status;
    size_t out_len;
    /* Fixed object table label used in older version of PS */
    uint8_t ps_table_key_label[] = "table_key_label";
    psa_key_id_t ps_key = 0;

    /* Set object table key */
    status = ps_crypto_setkey(&ps_key, ps_table_key_label, sizeof(ps_table_key_label));
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_aead_decrypt(ps_key, PS_CRYPTO_ALG,
                              crypto->ref.iv, PS_IV_LEN_BYTES,
                              add, add_len,
                              crypto->ref.tag, PS_TAG_LEN_BYTES,
                              0, 0, &out_len);
    if (status != PSA_SUCCESS || out_len != 0) {
        (void)psa_destroy_key(ps_key);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Destroy the transient key */
    status = psa_destroy_key(ps_key);
    if (status != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    return PSA_SUCCESS;
}
#endif /* PS_SUPPORT_FORMAT_TRANSITION */

/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "ifx_utils.h"
#include "tfm_crypto_defs.h"
#include "tfm_plat_ps_crypto.h"

static const uint8_t ps_key_seed[PS_KEY_LEN_BYTES] = {0};

psa_status_t tfm_platform_ps_set_key(psa_key_id_t *ps_key, const uint8_t *key_label,
                    size_t key_label_len)
{
    psa_status_t status;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_derivation_operation_t op = PSA_KEY_DERIVATION_OPERATION_INIT;
    mbedtls_svc_key_id_t new_key = MBEDTLS_SVC_KEY_ID_INIT;

    /* Check whether the PS AEAD algorithm is PSA_ALG_CCM */
    IFX_ASSERT(PS_CRYPTO_ALG == PSA_ALG_CCM);

    if ((key_label_len == 0U) || (key_label == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Set the key attributes for the storage key */
    psa_set_key_usage_flags(&attributes, PS_KEY_USAGE);
    psa_set_key_algorithm(&attributes, PSA_ALG_CCM);
    psa_set_key_type(&attributes, PS_KEY_TYPE);
    psa_set_key_bits(&attributes, PSA_BYTES_TO_BITS(PS_KEY_LEN_BYTES));
    psa_set_key_lifetime(&attributes,
        (PSA_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                PSA_KEY_LIFETIME_VOLATILE,
                PSA_KEY_LOCATION_IFX_SE)));

    status = psa_key_derivation_setup(&op, PSA_ALG_KDF_IFX_SE_AES_CMAC);
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
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_LABEL,
                                            key_label,
                                            key_label_len);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Supply the PS key seed as an input to the key derivation */
    status = psa_key_derivation_input_bytes(&op, PSA_KEY_DERIVATION_INPUT_SEED,
                                            ps_key_seed,
                                            sizeof(ps_key_seed));
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Create the storage key from the key derivation operation */
    status = psa_key_derivation_output_key(&attributes, &op, &new_key);
    if (status != PSA_SUCCESS) {
        goto err_release_op;
    }

    /* Free resources associated with the key derivation operation */
    status = psa_key_derivation_abort(&op);
    if (status != PSA_SUCCESS) {
        goto err_release_key;
    }

    *ps_key = MBEDTLS_SVC_KEY_ID_GET_KEY_ID(new_key);

    return PSA_SUCCESS;

err_release_key:
    (void)psa_destroy_key(new_key);

err_release_op:
    (void)psa_key_derivation_abort(&op);

    return PSA_ERROR_GENERIC_ERROR;
}

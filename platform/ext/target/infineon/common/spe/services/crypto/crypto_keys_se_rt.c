/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#if defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE)
#include MBEDTLS_PSA_CRYPTO_PLATFORM_FILE
#else /* defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE) */
#include "crypto_platform.h"
#endif /* defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE) */
#include "ifx_se_psacrypto.h"
#include "psa_manifest/pid.h"
#include "tfm_builtin_key_ids.h"
#include "tfm_builtin_key_loader.h"
#include "tfm_plat_crypto_keys.h"

#define NUMBER_OF_ELEMENTS_OF(x) sizeof(x)/sizeof(*x)

#ifdef IFX_PSA_CRYPTO_BUILTIN_KEYS

/**
 * @brief Table describing the builtin-in keys (platform keys) available in the platform. Note
 *        that to bind the keys to the tfm_builtin_key_loader driver, the lifetime must be
 *        explicitly set to the one associated to the driver, i.e. TFM_BUILTIN_KEY_LOADER_LIFETIME
 */
static const tfm_plat_builtin_key_descriptor_t g_builtin_keys_desc[] = {
    /* HUK */
    { .key_id = TFM_BUILTIN_KEY_ID_HUK,
      .slot_number = TFM_BUILTIN_KEY_SLOT_HUK,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* OEM ROT key */
    { .key_id = TFM_BUILTIN_KEY_ID_OEM_ROT,
      .slot_number = TFM_BUILTIN_KEY_SLOT_OEM_ROT,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* IFX_FW_INTEGRITY_KEYx, used for authenticating the SE_RT_SERVICES update image */
    { .key_id = TFM_BUILTIN_KEY_ID_SERVICES_UPD,
      .slot_number = TFM_BUILTIN_KEY_SLOT_SERVICES_UPD,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* IFX_ROT_KEY, used to verify the signature of RAM Apps */
    { .key_id = TFM_BUILTIN_KEY_ID_IFX_ROT,
      .slot_number = TFM_BUILTIN_KEY_SLOT_IFX_ROT,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* DICE_DeviceID private key */
    { .key_id = TFM_BUILTIN_KEY_ID_DEVICE,
      .slot_number = TFM_BUILTIN_KEY_SLOT_DEVICE,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* Attestation private key */
    { .key_id = TFM_BUILTIN_KEY_ID_ATTEST_PRIV,
      .slot_number = TFM_BUILTIN_KEY_SLOT_ATTEST_PRIV,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
    /* Attestation public key */
    { .key_id = TFM_BUILTIN_KEY_ID_ATTEST_PUB,
      .slot_number = TFM_BUILTIN_KEY_SLOT_ATTEST_PUB,
      .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME },
};

/*!
 * \brief This function derives a key into a provided buffer, to make sure that
 *        keys that are returned for usage to the PSA Crypto core, are differentiated
 *        based on the partition user. The derived keys are described as platform keys
 */
static psa_status_t derive_subkey_into_buffer(
        const psa_key_attributes_t *attributes,
        ifx_se_key_id_fih_t builtin_key, int32_t user,
        uint8_t *key_buffer, size_t key_buffer_size, size_t *key_buffer_length)
{
#ifdef TFM_PARTITION_TEST_PS
    /* Hack to allow the PS tests to work, since they directly call
     * ps_system_prepare from the test partition which would otherwise derive a
     * different key.
     */
    if (user == TFM_SP_PS_TEST) {
        user = TFM_SP_PS;
    }
#endif /* TFM_PARTITION_TEST_PS */

    psa_status_t status;
    ifx_se_key_id_fih_t output_key = IFX_SE_KEY_ID_FIH_INIT;
    ifx_se_key_attributes_t output_key_attr = IFX_SE_KEY_ATTRIBUTES_INIT;
    ifx_se_key_derivation_operation_t deriv_ops = ifx_se_key_derivation_operation_init();

    /* Set properties for the output key */
    ifx_se_set_key_type(&output_key_attr, psa_get_key_type(attributes));
    ifx_se_set_key_bits(&output_key_attr, psa_get_key_bits(attributes));
    ifx_se_set_key_algorithm(&output_key_attr, psa_get_key_algorithm(attributes));
    ifx_se_set_key_usage_flags(&output_key_attr, psa_get_key_usage_flags(attributes));
    ifx_se_set_key_lifetime(&output_key_attr,
        IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                IFX_SE_KEY_LIFETIME_VOLATILE,
                IFX_SE_KEY_LOCATION_SE) );

    status = ifx_se_get_psa_status(
                ifx_se_key_derivation_setup(&deriv_ops,
                    ifx_se_fih_uint_encode(PSA_ALG_KDF_IFX_SE_AES_CMAC),
                    IFX_SE_NULL_CTX));
    if (status != PSA_SUCCESS) {
        goto wrap_up;
    }

    /* No label is being used for the derivation */

    status = ifx_se_get_psa_status(
                ifx_se_key_derivation_inp_key(
                    &deriv_ops, PSA_KEY_DERIVATION_INPUT_SECRET,
                    builtin_key,
                    IFX_SE_NULL_CTX));
    if (status != PSA_SUCCESS) {
        goto wrap_up;
    }

    status = ifx_se_get_psa_status(
                ifx_se_key_derivation_inp_bytes(
                    &deriv_ops, PSA_KEY_DERIVATION_INPUT_SEED,
                    ifx_se_fih_ptr_encode(&user), ifx_se_fih_uint_encode(sizeof(user)),
                    IFX_SE_NULL_CTX));
    if (status != PSA_SUCCESS) {
        goto wrap_up;
    }

    status = ifx_se_get_psa_status(
                ifx_se_key_derivation_out_key(
                    &output_key_attr, &deriv_ops,
                    ifx_se_fih_ptr_encode(&output_key),
                    IFX_SE_NULL_CTX));
    if (status != PSA_SUCCESS) {
        goto wrap_up;
    }

    *((ifx_se_key_id_fih_t*) key_buffer) = output_key;
    *key_buffer_length = sizeof(ifx_se_key_id_fih_t);

wrap_up:
    (void)ifx_se_key_derivation_abort(&deriv_ops, IFX_SE_NULL_CTX);

    return status;
}

/** Populates key attributes and copies key material to the output buffer.
*
* \param[in]  slot_number           The slot number which corresponds to the
*                                   requested built-in key.
* \param[out] attributes            Attributes of the requested built-in key.
* \param[out] key_buffer            Output buffer where the key material of the
*                                   requested built-in key is copied.
* \param[in]  key_buffer_size       Size of the output buffer.
* \param[out] key_buffer_length     Actual length of the data copied to the
*                                   output buffer.
*
* \return     A status indicating the success/failure of the operation
*******************************************************************************/
psa_status_t ifx_mbedtls_get_builtin_key(psa_drv_slot_number_t slot_number,
                                         psa_key_attributes_t *attributes,
                                         uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         size_t *key_buffer_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    mbedtls_svc_key_id_t key_id;
    ifx_se_key_id_fih_t se_key_id;
    int32_t user;

    /* Note that the core layer might use this function just to probe, for a loaded
     * key, the attributes of the key. In this case, key_buffer and key_buffer_length
     * could be NULL hence the validation of those pointers must happen after this
     * check here. In fact, PSA_ERROR_BUFFER_TOO_SMALL is considered in the crypto
     * core as a safe failure value that lets the caller continue.
     */
    if (key_buffer_size < sizeof(ifx_se_key_id_fih_t)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if ((uint32_t)slot_number >= (uint32_t)TFM_BUILTIN_KEY_SLOT_MAX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (attributes == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((key_buffer == NULL) || (key_buffer_length == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    switch (slot_number) {
        case TFM_BUILTIN_KEY_SLOT_HUK:
            psa_set_key_type(attributes, PSA_KEY_TYPE_DERIVE);
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_DERIVE);
            psa_set_key_algorithm(attributes, PSA_ALG_KDF_IFX_SE_AES_CMAC);
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_OEM_ROT:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE |
                PSA_KEY_USAGE_EXPORT);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_SERVICES_UPD:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE |
                PSA_KEY_USAGE_EXPORT);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_IFX_ROT:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE |
                PSA_KEY_USAGE_EXPORT);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_DEVICE:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_ANY_HASH));
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_ATTEST_PRIV:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_SIGN_MESSAGE |
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_ANY_HASH));
            status = PSA_SUCCESS;
            break;
        case TFM_BUILTIN_KEY_SLOT_ATTEST_PUB:
            psa_set_key_type(
                attributes,
                PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1));
            psa_set_key_bits(attributes, 256u);
            psa_set_key_usage_flags(
                attributes,
                PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_VERIFY_MESSAGE |
                PSA_KEY_USAGE_EXPORT);
            psa_set_key_algorithm(
                attributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
            status = PSA_SUCCESS;
            break;
        default:
            status = PSA_ERROR_DOES_NOT_EXIST;
    }
    if (status != PSA_SUCCESS) {
        return status;
    }

    key_id = psa_get_key_id(attributes);

    /* If a key can be used for derivation, we derive a further subkey for each
     * users to prevent multiple users deriving the same keys as each other.
     * For keys for encryption and signing, it's assumed that if multiple
     * partitions have access to the key, there is a good reason and therefore
     * they all need access to the raw builtin key.
     */
    user = MBEDTLS_SVC_KEY_ID_GET_OWNER_ID(key_id);

    se_key_id = ifx_se_key_id_fih_make(MBEDTLS_SVC_KEY_ID_GET_OWNER_ID(key_id),
                                       MBEDTLS_SVC_KEY_ID_GET_KEY_ID(key_id));

    if (((psa_get_key_usage_flags(attributes) & PSA_KEY_USAGE_DERIVE) != 0U) &&
        (user != TFM_SP_CRYPTO)) {

        status = derive_subkey_into_buffer(attributes,
                                           se_key_id, user,
                                           key_buffer, key_buffer_size,
                                           key_buffer_length);
    } else {
        *((ifx_se_key_id_fih_t*) key_buffer) = se_key_id;
        *key_buffer_length = sizeof(ifx_se_key_id_fih_t);
    }

    return status;
}
#endif /* IFX_PSA_CRYPTO_BUILTIN_KEYS */

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    *desc_ptr = g_builtin_keys_desc;
    return NUMBER_OF_ELEMENTS_OF(g_builtin_keys_desc);
}

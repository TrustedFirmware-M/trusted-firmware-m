/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include "psa/client.h"
#include "attest.h"
#include "attest_boot_data.h"
#include "attest_key.h"
#include "attest_token.h"
#include "config_tfm.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_device_id.h"
#include "tfm_plat_boot_seed.h"
#include "tfm_attest_hal.h"
#include "tfm_attest_iat_defs.h"
#include "t_cose/t_cose_common.h"
#include "tfm_crypto_defs.h"
#include "tfm_log_unpriv.h"

#if ATTEST_TOKEN_PROFILE_ARM_CCA
#include "tfm_strnlen.h"
#endif

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(*(array)))

/*!
 * \brief Static function to map return values between \ref psa_attest_err_t
 *        and \ref psa_status_t
 *
 * \param[in]  attest_err  Attestation error code
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static inline psa_status_t
error_mapping_to_psa_status_t(enum psa_attest_err_t attest_err)
{
    switch (attest_err) {
    case PSA_ATTEST_ERR_SUCCESS:
        return PSA_SUCCESS;
        break;
    case PSA_ATTEST_ERR_INIT_FAILED:
        return PSA_ERROR_SERVICE_FAILURE;
        break;
    case PSA_ATTEST_ERR_BUFFER_OVERFLOW:
        return PSA_ERROR_BUFFER_TOO_SMALL;
        break;
    case PSA_ATTEST_ERR_CLAIM_UNAVAILABLE:
        return PSA_ERROR_GENERIC_ERROR;
        break;
    case PSA_ATTEST_ERR_INVALID_INPUT:
        return PSA_ERROR_INVALID_ARGUMENT;
        break;
    case PSA_ATTEST_ERR_GENERAL:
        return PSA_ERROR_GENERIC_ERROR;
        break;
    default:
        return PSA_ERROR_GENERIC_ERROR;
    }
}

psa_status_t attest_init(void)
{
    enum psa_attest_err_t res;

    res = attest_boot_data_init();

    return error_mapping_to_psa_status_t(res);
}

/*!
 * \brief Static function to map return values between \ref attest_token_err_t
 *        and \ref psa_attest_err_t
 *
 * \param[in]  token_err  Token encoding return value
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static inline enum psa_attest_err_t
error_mapping_to_psa_attest_err_t(enum attest_token_err_t token_err)
{
    switch (token_err) {
    case ATTEST_TOKEN_ERR_SUCCESS:
        return PSA_ATTEST_ERR_SUCCESS;
        break;
    case ATTEST_TOKEN_ERR_TOO_SMALL:
        return PSA_ATTEST_ERR_BUFFER_OVERFLOW;
        break;
    default:
        return PSA_ATTEST_ERR_GENERAL;
    }
}

/*!
 * \brief Static function to add the claims of all SW components to the
 *        attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_all_sw_components(struct attest_token_encode_ctx *token_ctx)
{
    QCBOREncodeContext *cbor_encode_ctx = NULL;
    uint32_t component_cnt;
    int32_t map_label = IAT_SW_COMPONENTS;
    enum psa_attest_err_t err;

    cbor_encode_ctx = attest_token_encode_borrow_cbor_cntxt(token_ctx);

    err = attest_encode_sw_components_array(cbor_encode_ctx,
                                            &map_label,
                                            &component_cnt);
    if (err != PSA_ATTEST_ERR_SUCCESS) {
        return err;
    }

    if (component_cnt == 0) {
#if ATTEST_TOKEN_PROFILE_PSA_IOT_1
        /* Allowed to not have SW components claim, but it must be indicated
         * that this state is intentional. In this case, include the
         * IAT_NO_SW_COMPONENTS claim with a fixed value.
         */
        attest_token_encode_add_integer(token_ctx,
                                        IAT_NO_SW_COMPONENTS,
                                        (int64_t)NO_SW_COMPONENT_FIXED_VALUE);
#else
        /* Mandatory to have SW components claim in the token */
        ERROR_UNPRIV("[Attest] Boot record is not available\n");
        return PSA_ATTEST_ERR_CLAIM_UNAVAILABLE;
#endif
    }

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add implementation id claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_implementation_id_claim(struct attest_token_encode_ctx *token_ctx)
{
    uint8_t implementation_id[IMPLEMENTATION_ID_MAX_SIZE];
    enum tfm_plat_err_t res_plat;
    uint32_t size = sizeof(implementation_id);
    struct q_useful_buf_c claim_value;

    res_plat = tfm_plat_get_implementation_id(&size, implementation_id);
    if (res_plat != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_CLAIM_UNAVAILABLE;
    }

    claim_value.ptr = implementation_id;
    claim_value.len  = size;
    attest_token_encode_add_bstr(token_ctx,
                                 IAT_IMPLEMENTATION_ID,
                                 &claim_value);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add instance id claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \note This mandatory claim represents the unique identifier of the instance.
 *       So far, only GUID type is supported.
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_instance_id_claim(struct attest_token_encode_ctx *token_ctx)
{
    struct q_useful_buf_c claim_value;
    enum psa_attest_err_t err;

    /* Leave the first byte for UEID type byte */
    err = attest_get_instance_id(&claim_value);
    if (err != PSA_ATTEST_ERR_SUCCESS) {
        return err;
    }

    attest_token_encode_add_bstr(token_ctx,
                                 IAT_INSTANCE_ID,
                                 &claim_value);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add security lifecycle claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_security_lifecycle_claim(struct attest_token_encode_ctx *token_ctx)
{
    enum tfm_security_lifecycle_t security_lifecycle;

    /* Use callback function to get it from runtime SW */
    security_lifecycle = tfm_attest_hal_get_security_lifecycle();

    attest_token_encode_add_integer(token_ctx,
                                    IAT_SECURITY_LIFECYCLE,
                                    (int64_t)security_lifecycle);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add the name of the profile definition document
 *
 * \note This function would be optional for PSA IoT 1/2 profiles but we keep it
 *       as mandatory for both CCA and PSA IoT for simplicity
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_profile_definition(struct attest_token_encode_ctx *token_ctx)
{
    struct q_useful_buf_c profile;
    uint8_t buf[PROFILE_DEFINITION_MAX_SIZE];
    uint32_t size = sizeof(buf);
    enum tfm_plat_err_t err;

    err = tfm_attest_hal_get_profile_definition(&size, buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    profile.ptr = &buf;
    profile.len = size;
    attest_token_encode_add_tstr(token_ctx,
                                 IAT_PROFILE_DEFINITION,
                                 &profile);

    return PSA_ATTEST_ERR_SUCCESS;
}

#if ATTEST_INCLUDE_OPTIONAL_CLAIMS
/*!
 * \brief Static function to add the verification service indicator claim
 *        to the attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_verification_service(struct attest_token_encode_ctx *token_ctx)
{
    struct q_useful_buf_c service;
    uint8_t buf[VERIFICATION_URL_MAX_SIZE];
    uint32_t size = sizeof(buf);
    enum tfm_plat_err_t err;

    err = tfm_attest_hal_get_verification_service(&size, buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    service.ptr = &buf;
    service.len = size;
    attest_token_encode_add_tstr(token_ctx,
                                 IAT_VERIFICATION_SERVICE,
                                 &service);

    return PSA_ATTEST_ERR_SUCCESS;
}
#endif /* ATTEST_INCLUDE_OPTIONAL_CLAIMS */

#if ATTEST_TOKEN_PROFILE_PSA_IOT_1 || ATTEST_TOKEN_PROFILE_PSA_2_0_0
/*!
 * \brief Static function to add boot seed claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_boot_seed_claim(struct attest_token_encode_ctx *token_ctx)
{
    uint8_t boot_seed[BOOT_SEED_SIZE];
    enum tfm_plat_err_t res;
    struct q_useful_buf_c claim_value = {0};

    /* Use callback function to get it from runtime SW */
    res = tfm_plat_get_boot_seed(sizeof(boot_seed), boot_seed);
    if (res != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_CLAIM_UNAVAILABLE;
    }
    claim_value.ptr = boot_seed;
    claim_value.len = BOOT_SEED_SIZE;

    attest_token_encode_add_bstr(token_ctx,
                                 IAT_BOOT_SEED,
                                 &claim_value);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add caller id claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_caller_id_claim(struct attest_token_encode_ctx *token_ctx)
{
    enum psa_attest_err_t res;
    int32_t caller_id;

    res = attest_get_caller_client_id(&caller_id);
    if (res != PSA_ATTEST_ERR_SUCCESS) {
        return res;
    }

    attest_token_encode_add_integer(token_ctx,
                                    IAT_CLIENT_ID,
                                    (int64_t)caller_id);

    return PSA_ATTEST_ERR_SUCCESS;
}

#if ATTEST_INCLUDE_OPTIONAL_CLAIMS
/*!
 * \brief Static function to add certification reference claim to attestation
 *        token.
 *
 * \param[in]  token_ctx  Token encoding context
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_cert_ref_claim(struct attest_token_encode_ctx *token_ctx)
{
    uint8_t buf[CERTIFICATION_REF_MAX_SIZE];
    enum tfm_plat_err_t res_plat;
    uint32_t size = sizeof(buf);
    struct q_useful_buf_c claim_value = {0};

    /* Use callback function to get it from runtime SW */
    res_plat = tfm_plat_get_cert_ref(&size, buf);
    if (res_plat != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_CLAIM_UNAVAILABLE;
    }
    claim_value.ptr = buf;
    claim_value.len = size;

    attest_token_encode_add_tstr(token_ctx,
                                 IAT_CERTIFICATION_REFERENCE,
                                 &claim_value);

    return PSA_ATTEST_ERR_SUCCESS;
}
#endif /* ATTEST_INCLUDE_OPTIONAL_CLAIMS */
#endif /* ATTEST_TOKEN_PROFILE_PSA_IOT_1 || ATTEST_TOKEN_PROFILE_PSA_2_0_0 */

#if ATTEST_TOKEN_PROFILE_ARM_CCA
/*!
 * \brief Static function to add the platform hash algorithm identifier
 *        claim to the attestation token. This hash algo is used for extending
 *        the boot measurements.
 *
 * \param[in]  token_ctx  Token encoding context
 * \param[in]  challenge  Pointer to buffer which stores the hash algo.
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_hash_algo_claim(struct attest_token_encode_ctx *token_ctx)
{
    struct q_useful_buf_c hash_algo;
    const char *buf = NULL;
    uint32_t size = 0;
    enum tfm_plat_err_t err;

    err = tfm_attest_hal_get_platform_hash_algo(&size, &buf);
    if (err != TFM_PLAT_ERR_SUCCESS && buf == NULL) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    if ((tfm_strnlen(buf, PLATFORM_HASH_ALGO_ID_MAX_SIZE) != size) || (size == 0)) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    hash_algo.ptr = &buf;
    hash_algo.len = size;
    attest_token_encode_add_tstr(token_ctx,
                                 IAT_PLATFORM_HASH_ALGO_ID,
                                 &hash_algo);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to add the platform hash algorithm identifier
 *        claim to the attestation token. This hash algo is used for extending
 *        the boot measurements.
 *
 * \param[in]  token_ctx  Token encoding context
 * \param[in]  challenge  Pointer to buffer which stores the hash algo.
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_platform_config_claim(struct attest_token_encode_ctx *token_ctx)
{

    uint8_t plat_config[PLATFORM_CONFIG_MAX_SIZE];
    enum tfm_plat_err_t res;
    uint32_t size = sizeof(plat_config);
    struct q_useful_buf_c claim_value;

    res = tfm_attest_hal_get_platform_config(&size, plat_config);
    if (res != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    claim_value.ptr = plat_config;
    claim_value.len = size;

    attest_token_encode_add_bstr(token_ctx,
                                 IAT_PLATFORM_CONFIG,
                                 &claim_value);

    return PSA_ATTEST_ERR_SUCCESS;
}
#endif /* ATTEST_TOKEN_PROFILE_ARM_CCA */

/*!
 * \brief Static function to add the nonce claim to attestation token.
 *
 * \param[in]  token_ctx  Token encoding context
 * \param[in]  nonce      Pointer to buffer which stores the challenge
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_add_nonce_claim(struct attest_token_encode_ctx   *token_ctx,
                       const struct q_useful_buf_c      *nonce)
{
    attest_token_encode_add_bstr(token_ctx,
                                 IAT_NONCE,
                                 nonce);

    return PSA_ATTEST_ERR_SUCCESS;
}

/*!
 * \brief Static function to verify the input challenge size
 *
 *  Only discrete sizes are accepted.
 *
 * \param[in] challenge_size  Size of challenge object in bytes.
 *
 * \retval  PSA_ATTEST_ERR_SUCCESS
 * \retval  PSA_ATTEST_ERR_INVALID_INPUT
 */
static enum psa_attest_err_t attest_verify_challenge_size(size_t challenge_size)
{
    switch (challenge_size) {
    /* Intentional fall through */
    case PSA_INITIAL_ATTEST_CHALLENGE_SIZE_32:
    case PSA_INITIAL_ATTEST_CHALLENGE_SIZE_48:
    case PSA_INITIAL_ATTEST_CHALLENGE_SIZE_64:
        return PSA_ATTEST_ERR_SUCCESS;
    }

    return PSA_ATTEST_ERR_INVALID_INPUT;
}

static enum psa_attest_err_t attest_get_t_cose_algorithm(
        int32_t *cose_algorithm_id)
{
    psa_status_t status;
    psa_key_attributes_t attr;
    psa_key_handle_t handle = TFM_BUILTIN_KEY_ID_IAK;
    psa_key_type_t key_type;

    status = psa_get_key_attributes(handle, &attr);
    if (status != PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    key_type = psa_get_key_type(&attr);
    if (status != PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    if (PSA_KEY_TYPE_IS_ECC(key_type) &&
        (PSA_KEY_TYPE_ECC_GET_FAMILY(key_type) == PSA_ECC_FAMILY_SECP_R1)) {
        switch (psa_get_key_bits(&attr)) {
        case 256:
            *cose_algorithm_id = T_COSE_ALGORITHM_ES256;
            break;
        case 384:
            *cose_algorithm_id = T_COSE_ALGORITHM_ES384;
            break;
        case 512:
            *cose_algorithm_id = T_COSE_ALGORITHM_ES512;
            break;
        default:
            return PSA_ATTEST_ERR_GENERAL;
        }
    } else if (key_type == PSA_KEY_TYPE_HMAC) {
        switch (psa_get_key_bits(&attr)) {
        case 256:
            *cose_algorithm_id = T_COSE_ALGORITHM_HMAC256;
            break;
        case 384:
            *cose_algorithm_id = T_COSE_ALGORITHM_HMAC384;
            break;
        case 512:
            *cose_algorithm_id = T_COSE_ALGORITHM_HMAC512;
            break;
        default:
            return PSA_ATTEST_ERR_GENERAL;
        }
    } else {
        VERBOSE_UNPRIV_RAW("Attestation: Unexpected key_type for TFM_BUILTIN_KEY_ID_IAK. Key storage may be corrupted!\n");
        return PSA_ATTEST_ERR_GENERAL;
    }

    return PSA_ATTEST_ERR_SUCCESS;
}

#if ATTEST_TOKEN_PROFILE_PSA_IOT_1 || ATTEST_TOKEN_PROFILE_PSA_2_0_0
    static enum psa_attest_err_t
    (*claim_query_funcs[])(struct attest_token_encode_ctx *) = {
        &attest_add_boot_seed_claim,
        &attest_add_instance_id_claim,
        &attest_add_implementation_id_claim,
        &attest_add_caller_id_claim,
        &attest_add_security_lifecycle_claim,
        &attest_add_all_sw_components,
        &attest_add_profile_definition,
#if ATTEST_INCLUDE_OPTIONAL_CLAIMS
        &attest_add_verification_service,
        &attest_add_cert_ref_claim
#endif
    };
#elif ATTEST_TOKEN_PROFILE_ARM_CCA

    static enum psa_attest_err_t
    (*claim_query_funcs[])(struct attest_token_encode_ctx *) = {
        &attest_add_instance_id_claim,
        &attest_add_implementation_id_claim,
        &attest_add_security_lifecycle_claim,
        &attest_add_all_sw_components,
        &attest_add_profile_definition,
        &attest_add_hash_algo_claim,
        &attest_add_platform_config_claim,
#if ATTEST_INCLUDE_OPTIONAL_CLAIMS
        &attest_add_verification_service,
#endif
    };
#endif

/*!
 * \brief Static function to create the initial attestation token
 *
 * \param[in]  challenge        Structure to carry the challenge value:
 *                              pointer + challeng's length
 * \param[in]  token            Structure to carry the token info, where to
 *                              create it: pointer + buffer's length
 * \param[out] completed_token  Structure to carry the info about the created
 *                              token: pointer + final token's length
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
static enum psa_attest_err_t
attest_create_token(struct q_useful_buf_c *challenge,
                    struct q_useful_buf   *token,
                    struct q_useful_buf_c *completed_token)
{
    enum psa_attest_err_t attest_err = PSA_ATTEST_ERR_SUCCESS;
    enum attest_token_err_t token_err;
    struct attest_token_encode_ctx attest_token_ctx;
    int32_t key_select = 0;
    int i;
    int32_t cose_algorithm_id;

    attest_err = attest_get_t_cose_algorithm(&cose_algorithm_id);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        return attest_err;
    }

    /* Get started creating the token. This sets up the CBOR and COSE contexts
     * which causes the COSE headers to be constructed.
     */
    token_err = attest_token_encode_start(&attest_token_ctx,
                                          key_select,        /* key_select   */
                                          cose_algorithm_id, /* alg_select   */
                                          token);

    if (token_err != ATTEST_TOKEN_ERR_SUCCESS) {
        attest_err = error_mapping_to_psa_attest_err_t(token_err);
        goto error;
    }

    attest_err = attest_add_nonce_claim(&attest_token_ctx,
                                        challenge);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        goto error;
    }

    for (i = 0; i < ARRAY_LENGTH(claim_query_funcs); ++i) {
        /* Calling the attest_add_XXX_claim functions */
        attest_err = claim_query_funcs[i](&attest_token_ctx);
        if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
            goto error;
        }
    }

    /* Finish up creating the token. This is where the actual signature
     * is generated. This finishes up the CBOR encoding too.
     */
    token_err = attest_token_encode_finish(&attest_token_ctx, completed_token);
    attest_err = error_mapping_to_psa_attest_err_t(token_err);

error:
    return attest_err;
}

psa_status_t
initial_attest_get_token(const void *challenge_buf, size_t challenge_size,
                         void *token_buf, size_t token_buf_size,
                         size_t *token_size)
{
    enum psa_attest_err_t attest_err = PSA_ATTEST_ERR_SUCCESS;
    struct q_useful_buf_c challenge;
    struct q_useful_buf token;
    struct q_useful_buf_c completed_token;

    challenge.ptr = challenge_buf;
    challenge.len = challenge_size;
    token.ptr = token_buf;
    token.len = token_buf_size;

    attest_err = attest_verify_challenge_size(challenge.len);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        goto error;
    }

    if (token.len == 0) {
        attest_err = PSA_ATTEST_ERR_INVALID_INPUT;
        goto error;
    }

    attest_err = attest_create_token(&challenge, &token, &completed_token);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        goto error;
    }

    *token_size  = completed_token.len;

error:
    return error_mapping_to_psa_status_t(attest_err);
}

psa_status_t
initial_attest_get_token_size(size_t challenge_size, size_t *token_size)
{
    enum psa_attest_err_t attest_err = PSA_ATTEST_ERR_SUCCESS;
    struct q_useful_buf_c challenge;
    struct q_useful_buf token;
    struct q_useful_buf_c completed_token;

    /* Only the size of the challenge is needed */
    challenge.ptr = NULL;
    challenge.len = challenge_size;

    /* Special value to get the size of the token, but token is not created */
    token.ptr = NULL;
    token.len = INT32_MAX;

    attest_err = attest_verify_challenge_size(challenge_size);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        goto error;
    }

    attest_err = attest_create_token(&challenge, &token, &completed_token);
    if (attest_err != PSA_ATTEST_ERR_SUCCESS) {
        goto error;
    }

    *token_size = completed_token.len;

error:
    return error_mapping_to_psa_status_t(attest_err);
}

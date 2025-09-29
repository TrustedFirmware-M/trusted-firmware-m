/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \note This source file is derivative work of psa_crypto.c from the Mbed TLS project
 */
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "fih.h"
#include "cmsis_compiler.h"

/* This module includes the driver_wrappers which assumes that private access to the
 * fields of implementation structures is enabled through the following defined macro
 */
#define MBEDTLS_ALLOW_PRIVATE_ACCESS

#include "psa/crypto.h"
#include "psa_crypto_driver_wrappers.h"
#include "psa_crypto_driver_wrappers_no_static.h"
#if defined(MCUBOOT_BUILTIN_KEY)
#include "tfm_plat_crypto_keys.h"
#endif /* MCUBOOT_BUILTIN_KEY */
#ifdef PSA_WANT_ALG_LMS
#include "mbedtls/lms.h"
#endif /* PSA_WANT_ALG_LMS */

/* For mbedtls_psa_ecdsa_verify_hash() */
#include "psa_crypto_ecp.h"

/* A few Mbed TLS definitions */
#include "mbedtls/entropy.h"
#include "mbedtls/ecp.h"
#include "mbedtls/nist_kw.h"
#if defined(CC3XX_CRYPTO_OPAQUE_KEYS)
#include "cc3xx_opaque_keys.h"
#endif

/**
 * \brief Rounds a value x up to a bound.
 */
#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)

/**
 * @brief Declare an internal PSA API function.
 *
 * This macro defines the prototype of the internal implementation of a PSA API
 * function that returns an FIH wrapped status code.
 *
 * @param fn    The base name of the PSA API function.
 * @param types The full argument list enclosed in parentheses, e.g. `(int a, int b)`.
 *
 * @note The actual function symbol will be prefixed with `__internal_`.
 *
 * Example:
 * @code
 * INTERNAL_PSA_API(foo, (int a));
 * // Expands to:
 * // static FIH_RET_TYPE(psa_status_t) __internal_foo(int a);
 * @endcode
 */
#define INTERNAL_PSA_API(fn, types) \
    static FIH_RET_TYPE(psa_status_t) __internal_##fn types

/**
 * @brief Declare an external PSA API function with FIH protection.
 *
 * This macro declares both the public-facing PSA API function and its
 * associated internal implementation. The public wrapper ensures that calls
 * to the internal implementation are protected by the FIH calling convention
 *
 * The macro performs the following steps:
 *   1. Forward-declares the internal implementation.
 *   2. Defines the public wrapper function, which calls the internal
 *      implementation using @ref FIH_CALL and decodes the return value.
 *   3. Provides the prototype for the internal implementation, which must
 *      follow immediately.
 *
 * @param fn      The base name of the PSA API function.
 * @param types   The full argument list enclosed in parentheses, e.g. `(int a, int b)`.
 * @param ...     Arguments forwarded to the internal function when invoked.
 *
 * Example:
 * @code
 * EXTERNAL_PSA_API(foo, (int a), a)
 * {
 *     // Internal implementation
 *     return FIH_SUCCESS;
 * }
 * // Expands to:
 * // static FIH_RET_TYPE(psa_status_t) __internal_foo(int a);
 * //
 * // psa_status_t foo(int a) {
 * //     FIH_RET_TYPE(psa_status_t) status;
 * //     FIH_CALL(__internal_foo, status, a);
 * //     return (psa_status_t)fih_int_decode(status);
 * // }
 * //
 * // static FIH_RET_TYPE(psa_status_t) __internal_foo(int a) {
 * //     ...
 * // }
 * @endcode
 */
#define EXTERNAL_PSA_API(fn, types, ...)                     \
    /* Forward declaration of the internal implementation */ \
    INTERNAL_PSA_API(fn, types);                             \
                                                             \
    /* Public wrapper with FIH protection */                 \
    psa_status_t fn types                                    \
    {                                                        \
        FIH_RET_TYPE(psa_status_t) status;                   \
        FIH_CALL(__internal_##fn, status, __VA_ARGS__);      \
        return (psa_status_t)(status);                       \
    }                                                        \
                                                             \
    /* Definition of the internal implementation follows */  \
    INTERNAL_PSA_API(fn, types)

/**
 * @note The assumption is that key import will happen just
 *       before the key is used during bootloading stages,
 *       hence the key management system is simplified to
 *       just hold a pointer to the key
 */

/**
 * @brief Static local buffer that holds enough data for the key material
 *        provisioned bundle to be retrieved from the platform.
 *
 * @note  The buffer is rounded to a 4-byte size to match the requirements on the
 *        alignment for the underlying OTP memory
 */
static uint32_t g_pubkey_data[ROUND_UP(PSA_EXPORT_PUBLIC_KEY_MAX_SIZE,  sizeof(uint32_t)) / sizeof(uint32_t)];
#if defined(MCUBOOT_ENC_IMAGES)
static uint8_t g_symkey_data[PSA_CIPHER_MAX_KEY_LENGTH];
#endif
/**
 * @brief A structure describing the contents of a thin key slot, which
 *        holds key material and metadata following a psa_import_key() call
 */
struct thin_key_slot_s {
    uint8_t *buf;              /*!< Pointer to the buffer holding the key material */
    size_t len;                /*!< Size in bytes of the \a buf buffer */
    psa_key_attributes_t attr; /*!< Attributes of the key */
    psa_key_id_t key_id;       /*!< Key ID assigned to the key */
    bool is_valid;             /*!< Boolean value, true if the key material is valid */
};

/**
 * @brief This static global variable holds the key slot. The thin PSA Crypto core
 *        supports only a single key to be imported at any given time. Importing a
 *        new key will just cause the existing key to be forgotten
 */
static struct thin_key_slot_s g_key_slot =  {
    .buf = NULL,
    .len = 0,
    .attr = PSA_KEY_ATTRIBUTES_INIT,
    .key_id = PSA_KEY_ID_NULL,
    .is_valid = false,
};

/**
 * @brief Context required by the RNG function, mocked because the RNG function
 *        does not provide a valid implementation unless it is overridden by a
 *        TRNG hardware driver integration
 */
static mbedtls_psa_external_random_context_t *g_ctx = NULL;

/**
 * @brief Retrieves the builtin key associated to the \a key_id
 *        from the underlying platform, binding the core key
 *        slot to the local storage which holds the key material,
 *        and filling the associated key metadata
 *
 * @param[in] key_id Key id associated to the builtin key to retrieve
 *
 * @return psa_status_t PSA_SUCCESS or PSA_ERROR_GENERIC_ERROR, PSA_ERROR_DOES_NOT_EXIST
 */
static psa_status_t get_builtin_key(psa_key_id_t key_id)
{
#if defined(MCUBOOT_BUILTIN_KEY)
    const tfm_plat_builtin_key_descriptor_t *desc_table = NULL;
    size_t number_of_keys = tfm_plat_builtin_key_get_desc_table_ptr(&desc_table);
    size_t idx;

    for (idx = 0; idx < number_of_keys; idx++) {
        if (desc_table[idx].key_id == key_id) {
            psa_key_bits_t key_bits;
            psa_algorithm_t alg;
            psa_key_type_t key_type;
            enum tfm_plat_err_t plat_err;

            /* Bind the local storage to the key slot */
            g_key_slot.buf = (uint8_t *)g_pubkey_data;

            /* Load key */
            plat_err = desc_table[idx].loader_key_func(
                desc_table[idx].loader_key_ctx, g_key_slot.buf, sizeof(g_pubkey_data), &g_key_slot.len, &key_bits, &alg, &key_type);

            if (plat_err != TFM_PLAT_ERR_SUCCESS) {
                return PSA_ERROR_GENERIC_ERROR;
            }

            /* Set metadata */
            psa_set_key_algorithm(&g_key_slot.attr, alg);
            psa_set_key_type(&g_key_slot.attr, key_type);
            psa_set_key_bits(&g_key_slot.attr, key_bits);
            break;
        }
    }

    if (idx == number_of_keys) {
        return PSA_ERROR_DOES_NOT_EXIST;
    }

    /* Set policy */
    const tfm_plat_builtin_key_policy_t *policy_table = NULL;
    (void)tfm_plat_builtin_key_get_policy_table_ptr(&policy_table);
    psa_set_key_usage_flags(&g_key_slot.attr, policy_table[idx].usage);

    return PSA_SUCCESS;
#else
    assert(0);
    return PSA_ERROR_INVALID_ARGUMENT;
#endif
}

#if defined(MCUBOOT_ENC_IMAGES)
static psa_status_t get_symmetric_builtin_key(psa_key_id_t key,
                                     psa_algorithm_t alg)
{
#if defined(CC3XX_CRYPTO_OPAQUE_KEYS)
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    status = cc3xx_opaque_keys_attr_init(&g_key_slot.attr, key, alg,
                                         (const uint8_t **) &g_key_slot.buf,
                                         &g_key_slot.len);
    if (status != PSA_SUCCESS) {
        return status;
    }
    g_key_slot.key_id = key;
    g_key_slot.is_valid = true;
    return status;
#else
    return PSA_ERROR_NOT_SUPPORTED;
#endif
}
#endif /* MCUBOOT_ENC_IMAGES */

/**
 * @brief Check if a \a key_id refers to a builtin key_id
 *
 * @note This is an arbitrary choice, i.e. setting the MSB of the key_id
 *       that might be reworked in the future. The convention needs to be
 *       enforced with the MCUboot caller application, the rationale for
 *       the current choice is to remain as simple as possible
 *
 * @param[in] key_id The key_id to be checked, i.e. a uint32_t variable
 * @return    true   True if it is associated to a builtin key_id
 * @return    false  False if it is associated to a transient key imported
 *                   in the core
 */
static bool is_key_builtin(psa_key_id_t key_id)
{
    /* If a key is imported, it sets the MSB of the psa_key_id_t */
    if (key_id & 0x80000000) {
        return false;
    }

    return true;
}

#if defined(MCUBOOT_BUILTIN_KEY)
#ifdef MCUBOOT_ROTPK_SIGN_POLICY
/**
 * @brief Retrieve the signing policy for a given key ID.
 *
 * @details This function fetches the signing policy associated with the
 *          specified key ID and populates the provided policy structure.
 *
 * @param[in]  key_id The identifier of the key whose signing policy is to
 *                     be retrieved.
 * @param[out] policy  Pointer to a structure where the signing policy
 *                     information will be stored.
 *
 * @return PSA_SUCCESS             If the policy was successfully retrieved.
 * @return PSA_ERROR_DOES_NOT_EXIST If the key ID does not exist.
 * @return PSA_ERROR_INVALID_ARGUMENT If the input arguments are invalid.
 */
static psa_status_t get_key_sign_policy(psa_key_id_t key_id,
                                        enum tfm_bl2_key_policy_t *policy)
{
    uint32_t policies;
    enum tfm_plat_err_t err;
    uint32_t policy_mask;

    err = tfm_plat_get_bl2_rotpk_policies((uint8_t *)&policies, sizeof(policies));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    /* Get the policy mask for the corresponding key id */
    policy_mask = get_policy_bit_mask(key_id);
    if (policy_mask == 0) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (policies & policy_mask) {
        *policy = TFM_BL2_KEY_MUST_SIGN;
    } else {
        *policy = TFM_BL2_KEY_MIGHT_SIGN;
    }

    return PSA_SUCCESS;
}
#else
static inline psa_status_t get_key_sign_policy(psa_key_id_t key,
                                               enum tfm_bl2_key_policy_t *policy)
{
    (void)key; /* Unused parameter */
    /* By default key policy is a MUST SIGN */
    *policy = TFM_BL2_KEY_MUST_SIGN;

    return PSA_SUCCESS;
}
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

int boot_plat_check_key_policy(bool valid_sig, psa_key_id_t key,
                               bool *key_might_sign, bool *key_must_sign,
                               uint8_t *key_must_sign_count)
{
    enum tfm_bl2_key_policy_t policy;

    if (get_key_sign_policy(key, &policy) != PSA_SUCCESS) {
        return -1;
    }

    if (policy == TFM_BL2_KEY_MIGHT_SIGN) {
        *key_might_sign |= valid_sig;
    } else {
        *key_must_sign_count += 1;
        *key_might_sign |= valid_sig;
        *key_must_sign  &= valid_sig;
    }

    return 0;
}
#endif /* MCUBOOT_BUILTIN_KEY */

/**
 * @brief Check in constant time if the \a a buffer matches the \a b
 *        buffer
 *
 * @param[in] a  Buffer of length \a la
 * @param[in] la Size in bytes of the \a a buffer
 * @param[in] b  Buffer of length \a lb
 * @param[in] lb Size in bytes of the \a b buffer
 *
 * @return psa_status_t PSA_SUCCESS or PSA_ERROR_INVALID_SIGNATURE in case
 *                      the buffer don't match, i.e. this is normally used
 *                      in the context of signature or hash verification
 */
static psa_status_t hash_check(const uint8_t *a, size_t la, const uint8_t *b,
        size_t lb)
{
    uint8_t chk = 1;

    if (la == lb) {
        chk = 0;
        for (size_t i = 0; i < la; i++) {
            chk |= (uint8_t) (a[i] ^ b[i]);
        }
    }

    return chk == 0 ? PSA_SUCCESS : PSA_ERROR_INVALID_SIGNATURE;
}

/*!
 * \defgroup thin_psa_crypto Set of functions implementing a thin PSA Crypto core
 *                           with the bare minimum set of APIs required for
 *                           bootloading use cases.
 */
/*!@{*/
psa_status_t psa_crypto_init(void)
{
    psa_status_t status = psa_driver_wrapper_init();

    /* This will have to perform RNG/DRBG init in case that will be ever required by
     * any API
     */
    return status;
}

__WEAK psa_status_t psa_hash_abort(psa_hash_operation_t *operation)
{
    /* Aborting a non-active operation is allowed */
    if (operation->id == 0) {
        return PSA_SUCCESS;
    }

    psa_status_t status = psa_driver_wrapper_hash_abort(operation);

    operation->id = 0;

    return status;
}

__WEAK psa_status_t psa_hash_setup(psa_hash_operation_t *operation,
                            psa_algorithm_t alg)
{
    psa_status_t status;

    /* A context must be freshly initialized before it can be set up. */
    assert(operation->id == 0);
    assert(PSA_ALG_IS_HASH(alg));

    /* Ensure all of the context is zeroized, since PSA_HASH_OPERATION_INIT only
     * directly zeroes the int-sized dummy member of the context union.
     */
    memset(&operation->ctx, 0, sizeof(operation->ctx));

    status = psa_driver_wrapper_hash_setup(operation, alg);

    assert(status == PSA_SUCCESS);

    return status;
}

__WEAK psa_status_t psa_hash_update(psa_hash_operation_t *operation,
                             const uint8_t *input,
                             size_t input_length)
{
    psa_status_t status;

    assert(operation->id != 0);

    /* Don't require hash implementations to behave correctly on a
     * zero-length input, which may have an invalid pointer.
     */
    if (input_length == 0) {
        return PSA_SUCCESS;
    }

    status = psa_driver_wrapper_hash_update(operation, input, input_length);

    assert(status == PSA_SUCCESS);

    return status;
}

__WEAK psa_status_t psa_hash_finish(psa_hash_operation_t *operation,
                             uint8_t *hash,
                             size_t hash_size,
                             size_t *hash_length)
{
    *hash_length = 0;
    assert(operation->id != 0);

    psa_status_t status = psa_driver_wrapper_hash_finish(
        operation, hash, hash_size, hash_length);
    psa_hash_abort(operation);

    return status;
}

__WEAK psa_status_t psa_hash_verify(psa_hash_operation_t *operation,
                             const uint8_t *hash,
                             size_t hash_length)
{
    /* Size this buffer for the worst case in terms of size */
    uint32_t hash_produced[PSA_HASH_MAX_SIZE / sizeof(uint32_t)];
    size_t hash_produced_length;
    psa_status_t status;

    status = psa_hash_finish(operation,
                             (uint8_t *)hash_produced,
                             sizeof(hash_produced),
                             &hash_produced_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    return hash_check(hash, hash_length, (uint8_t *)hash_produced, hash_produced_length);
}

/* FixMe: psa_adac_mac_verify() and psa_adac_derive_key() for BL2 based ADAC flow with CC312
 *        are not implemented yet, hence the APIs below are just stubbed to emulate
 *        the same behaviour, i.e. PSA_ERROR_NOT_SUPPORTED
 */
psa_status_t psa_mac_sign_setup(psa_mac_operation_t *operation,
                                psa_key_id_t key,
                                psa_algorithm_t alg)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_verify_setup(psa_mac_operation_t *operation,
                                  psa_key_id_t key,
                                  psa_algorithm_t alg)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_update(psa_mac_operation_t *operation,
                            const uint8_t *input,
                            size_t input_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_verify_finish(psa_mac_operation_t *operation,
                                   const uint8_t *mac,
                                   size_t mac_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_sign_finish(psa_mac_operation_t *operation,
                                 uint8_t *mac,
                                 size_t mac_size,
                                 size_t *mac_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_abort(psa_mac_operation_t *operation)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_mac_compute(psa_key_id_t key,
                             psa_algorithm_t alg,
                             const uint8_t *input,
                             size_t input_length,
                             uint8_t *mac,
                             size_t mac_size,
                             size_t *mac_length)
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    uint8_t *key_buffer;
    size_t key_buffer_size;
    psa_status_t status = PSA_ERROR_INVALID_HANDLE;

    /* Check if the key is important */
    if (g_key_slot.is_valid && (g_key_slot.key_id == key)) {
        status = psa_get_key_attributes(key, &attributes);
        if (status != PSA_SUCCESS) {
            return status;
        }

        key_buffer = g_key_slot.buf;
        key_buffer_size = g_key_slot.len;
    }
#ifdef CC3XX_CRYPTO_OPAQUE_KEYS
    else {
        status = cc3xx_opaque_keys_attr_init(&attributes, key, alg,
                                             &key_buffer, &key_buffer_size);
        if (status != PSA_SUCCESS) {
            return status;
        }
    }
#endif /* CC3XX_CRYPTO_OPAQUE_KEYS */

    /* In case neither a static slot, nor an opaque key is used */
    if (status == PSA_ERROR_INVALID_HANDLE) {
        return status;
    }

    return psa_driver_wrapper_mac_compute(
                        &attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        mac,
                        mac_size,
                        mac_length);

}

psa_status_t psa_key_derivation_setup(psa_key_derivation_operation_t *operation,
                                      psa_algorithm_t alg)
{
    if (operation == NULL) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Only SP800-108 CMAC is supported */
    if (alg != PSA_ALG_SP800_108_COUNTER_CMAC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }
#ifndef PSA_WANT_ALG_SP800_108_COUNTER_CMAC
    else {
        return PSA_ERROR_NOT_SUPPORTED;
    }
#endif /* PSA_WANT_ALG_SP800_108_COUNTER_CMAC */

    /* Ensure all of the context is zeroized */
    memset(operation, 0, sizeof(*operation));

    operation->alg = alg;

    return PSA_SUCCESS;
}

psa_status_t psa_key_derivation_set_capacity(
    psa_key_derivation_operation_t *operation,
    size_t capacity)
{
    if (operation == NULL) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Only SP800-108 CMAC is supported */
    if (operation->alg != PSA_ALG_SP800_108_COUNTER_CMAC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /*
     * Based on PSA Crypto API spec:
     *  Subsequent calls to psa_key_derivation_set_capacity() are not
     *  permitted for this algorithm.
     */
    if (!!operation->capacity) {
        return PSA_ERROR_BAD_STATE;
    }

    /* For simplicity, only support 4-byte aligned capacity */
    if ((capacity % sizeof(uint32_t)) != 0) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    operation->capacity = capacity;

#ifdef PSA_WANT_ALG_SP800_108_COUNTER_CMAC
    psa_sp800_108_cmac_key_derivation_t *ctx = &operation->ctx.sp800_108_cmac;
    ctx->L_bits = capacity * 8;
#endif /* PSA_WANT_ALG_SP800_108_COUNTER_CMAC */

    return PSA_SUCCESS;
}
EXTERNAL_PSA_API(psa_key_derivation_input_key,
    (psa_key_derivation_operation_t *operation, psa_key_derivation_step_t step, psa_key_id_t key),
    operation, step, key)
{
    if (operation == NULL) {
        return PSA_ERROR_BAD_STATE;
    }

    if (step != PSA_KEY_DERIVATION_INPUT_SECRET) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Only SP800-108 CMAC is supported */
    if (operation->alg != PSA_ALG_SP800_108_COUNTER_CMAC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

#ifdef PSA_WANT_ALG_SP800_108_COUNTER_CMAC
    psa_sp800_108_cmac_key_derivation_t *ctx = &operation->ctx.sp800_108_cmac;

    /* The key must be provided before label and context */
    if (ctx->label_provided || ctx->context_provided) {
        return PSA_ERROR_BAD_STATE;
    }

    ctx->key_provided = true;
    ctx->key = key;
#endif /* PSA_WANT_ALG_SP800_108_COUNTER_CMAC */


    return PSA_SUCCESS;
}

EXTERNAL_PSA_API(psa_key_derivation_input_bytes,
    (psa_key_derivation_operation_t *operation, psa_key_derivation_step_t step,
    const uint8_t *data, size_t data_length),
    operation, step, data, data_length)
{
    if (operation == NULL) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Only SP800-108 CMAC is supported */
    if (operation->alg != PSA_ALG_SP800_108_COUNTER_CMAC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (!data_length) {
        return PSA_SUCCESS;
    }

#ifdef PSA_WANT_ALG_SP800_108_COUNTER_CMAC
    psa_sp800_108_cmac_key_derivation_t *ctx = &operation->ctx.sp800_108_cmac;
    const size_t ctx_input_offset = (step == PSA_KEY_DERIVATION_INPUT_LABEL) ?
                                        SP800_108_INPUT_LABEL_OFFSET(ctx) :
                                        SP800_108_INPUT_CONTEXT_OFFSET(ctx);
    const size_t ctx_input_max_size = (step == PSA_KEY_DERIVATION_INPUT_LABEL) ?
                                        SP800_108_LABEL_MAX_SIZE :
                                        SP800_108_CONTEXT_MAX_SIZE;
    size_t *ctx_input_length = (step == PSA_KEY_DERIVATION_INPUT_LABEL) ?
                                        &ctx->label_length :
                                        &ctx->context_length;
    bool *ctx_input_provided = (step == PSA_KEY_DERIVATION_INPUT_LABEL) ?
                                        &ctx->label_provided :
                                        &ctx->context_provided;

    if ((step != PSA_KEY_DERIVATION_INPUT_LABEL) &&
        (step != PSA_KEY_DERIVATION_INPUT_CONTEXT)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Inputs must be passed in this order key -> label -> context */
    if ((!ctx->key_provided) ||
        ((step == PSA_KEY_DERIVATION_INPUT_CONTEXT) && !ctx->label_provided)) {
        return PSA_ERROR_BAD_STATE;
    }

    if (data_length > ctx_input_max_size) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }

    memcpy(ctx->inputs + ctx_input_offset, data, data_length);

    *ctx_input_length = data_length;
    *ctx_input_provided = true;
#endif /* PSA_WANT_ALG_SP800_108_COUNTER_CMAC */

    return PSA_SUCCESS;
}

EXTERNAL_PSA_API(psa_key_derivation_output_bytes,
    (psa_key_derivation_operation_t *operation, uint8_t *output, size_t output_length),
    operation, output, output_length)
{
    size_t *capacity = &operation->capacity;

    if (operation == NULL) {
        return PSA_ERROR_BAD_STATE;
    }

    /* Only SP800-108 CMAC is supported */
    if (operation->alg != PSA_ALG_SP800_108_COUNTER_CMAC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (output_length > *capacity) {
        *capacity = 0;
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

#ifdef PSA_WANT_ALG_SP800_108_COUNTER_CMAC
    psa_sp800_108_cmac_key_derivation_t *ctx = &operation->ctx.sp800_108_cmac;
    uint8_t *k0_input = &ctx->inputs[SP800_108_INTERATION_COUNTER_SIZE];
    const size_t k0_input_size = ctx->label_length +
                                 SP800_108_NULL_BYTE_SIZE +
                                 ctx->context_length +
                                 SP800_108_ENCODED_LENGTH_SIZE;
    uint8_t *k0 = &ctx->inputs[SP800_108_INPUT_K0_OFFSET(ctx)];
    size_t k0_length = 0;
    const uint8_t l_total_length[] = {
        (ctx->L_bits >> 24) & 0xFF,
        (ctx->L_bits >> 16) & 0xFF,
        (ctx->L_bits >> 8) & 0xFF,
         ctx->L_bits & 0xFF};
    const size_t num_blocks = ROUND_UP(output_length, PSA_AEAD_TAG_MAX_SIZE) /
                                PSA_AEAD_TAG_MAX_SIZE;
    const size_t unaligned_block_size = output_length % PSA_AEAD_TAG_MAX_SIZE;
    psa_status_t status;

    /* copy L bits */
    memcpy(&ctx->inputs[SP800_108_INPUT_ENCODED_LENGTH_OFFSET(ctx)],
           l_total_length,
           SP800_108_ENCODED_LENGTH_SIZE);

    /* Compute K0 */
    status =  psa_mac_compute(ctx->key,
                              PSA_ALG_CMAC,
                              k0_input,
                              k0_input_size,
                              k0,
                              SP800_108_K0_SIZE,
                              &k0_length);
    if (status != PSA_SUCCESS) {
        return status;
    } else if (k0_length != SP800_108_K0_SIZE) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    for (size_t idx = ctx->counter; idx < num_blocks; idx++) {
        const uint8_t *output_key_offset = ((uint8_t *) output) + (idx * PSA_AEAD_TAG_MAX_SIZE);
        const size_t tag_size = ((idx == num_blocks - 1) && (unaligned_block_size > 0)) ?
                                    unaligned_block_size : PSA_AEAD_TAG_MAX_SIZE;
        size_t tag_length = 0;
        /* [i]2 is encoded on 4 bytes, i.e. r = 32, in binary. Assumes processor is LE */
        const size_t i_idx = idx + 1;
        const uint8_t i_encoded[] = {
            (i_idx >> 24) & 0xFF,
            (i_idx >> 16) & 0xFF,
            (i_idx >> 8) & 0xFF,
            i_idx & 0xFF};

        /* copy the encoded iteration counter */
        memcpy(&ctx->inputs[SP800_108_INPUT_INTERATION_COUNTER_OFFSET(ctx)],
           i_encoded,
           SP800_108_INTERATION_COUNTER_SIZE);

        /* Compute Ki */
        status =  psa_mac_compute(ctx->key,
                                  PSA_ALG_CMAC,
                                  ctx->inputs,
                                  SP800_108_INPUT_LENGTH(ctx),
                                  output_key_offset,
                                  tag_size,
                                  &tag_length);
        if (status != PSA_SUCCESS) {
            return status;
        } else if (tag_length != tag_size) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
        }
    }

    ctx->counter = (unaligned_block_size > 0) ?
                        ctx->counter + num_blocks - 1:
                        ctx->counter + num_blocks;
#endif /* PSA_WANT_ALG_SP800_108_COUNTER_CMAC */

    operation->capacity -= output_length;

    return PSA_SUCCESS;
}

psa_status_t psa_key_derivation_abort(psa_key_derivation_operation_t *operation)
{
    assert(operation != 0);

    /* Clear operation including its context */
    memset(operation, 0, sizeof(*operation));

    return PSA_SUCCESS;
}

/**
 * The key management subsystem is simplified to support only the key encodings
 * as expected by MCUboot. MCUboot key bundles can be encoded in the
 * SubjectPublicKeyInfo format (RFC 5480):
 *
 * SubjectPublicKeyInfo  ::= SEQUENCE  {
 *     algorithm            AlgorithmIdentifier,
 *     subjectPublicKey     BIT STRING
 * }
 *
 * where, for RSA, the subjectPublicKey is either specified in RFC 3447 (PKCS#1v2.1)
 * or the newest RFC 8017 (PKCS#1v2.2) using RSAPublicKey:
 *
 * RSAPublicKey ::= SEQUENCE {
 *     modulus           INTEGER,  -- n
 *     publicExponent    INTEGER   -- e
 * }
 *
 * or for ECDSA is specified in RFC 5480 itself as ECPoint ::= OCTET STRING
 *
 * For ECDSA, MCUboot passes the uncompressed format (i.e. 0x04 X Y), i.e. the
 * key encoding is parsed by MCUboot itself before being imported. For RSA, the
 * AlgorithmIdentifier is instead specified in RFC 3279 as the value of the OID
 * rsaEncryption: 1.2.840.113549.1.1.1, but MCUboot chooses in this case to
 * pass already the RSAPublicKey structure to the APIs, hence the code below just
 * understands the length of n by inspecting the fields of the ASN.1 encoding
 *
 */
psa_status_t psa_import_key(const psa_key_attributes_t *attributes,
                            const uint8_t *data,
                            size_t data_length,
                            psa_key_id_t *key)
{
    size_t bits = 0;
#if PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY == 1
    if (PSA_KEY_TYPE_IS_RSA(psa_get_key_type(attributes))) {
        /* This is either a 2048, 3072 or 4096 bit RSA key, hence the TLV must place
        * the length at index (6,7) with a leading 0x00. The leading 0x00 is due to
        * the fact that the MSB will always be set for RSA keys where the length is
        * a multiple of 8 bits.
        */
        bits = PSA_BYTES_TO_BITS((((uint16_t)data[6]) << 8) | (uint16_t)data[7]) - 8;
    }
#elif PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY == 1
    if (PSA_KEY_TYPE_IS_ECC(psa_get_key_type(attributes))) {
        /* The public key is expected in uncompressed format, i.e. 0x04 X Y
        * for 256 or 384 bit lengths, and the driver wrappers expect to receive
        * it in that format
        */
        assert(data[0] == 0x04);
        bits = PSA_BYTES_TO_BITS((data_length - 1)/2);
   }
#endif

    if (PSA_KEY_TYPE_IS_UNSTRUCTURED(psa_get_key_type(attributes))) {
        bits = PSA_BYTES_TO_BITS(data_length);
    }

    g_key_slot.buf = (uint8_t *)data;
    g_key_slot.len = data_length;

    memcpy(&g_key_slot.attr, attributes, sizeof(psa_key_attributes_t));
    g_key_slot.attr.bits = (psa_key_bits_t)bits;

    /* This signals that a new key has been imported */
    ++g_key_slot.key_id;
    g_key_slot.key_id |= 0x80000000UL;
    *key = g_key_slot.key_id;

    g_key_slot.is_valid = true;

    return PSA_SUCCESS;
}

psa_status_t psa_export_key(psa_key_id_t key,
                            uint8_t *data_external,
                            size_t data_size,
                            size_t *data_length)
{
    psa_status_t status;
    if (is_key_builtin(key)) {
        status = get_builtin_key(key);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else {
        assert(g_key_slot.is_valid && (g_key_slot.key_id == key));
    }

    if (data_size < g_key_slot.len) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memcpy(data_external, g_key_slot.buf, g_key_slot.len);
    return PSA_SUCCESS;
}

psa_status_t psa_get_key_attributes(psa_key_id_t key,
                                    psa_key_attributes_t *attributes)
{
    assert(g_key_slot.is_valid && (g_key_slot.key_id == key));
    memcpy(attributes, &g_key_slot.attr, sizeof(psa_key_attributes_t));
    return PSA_SUCCESS;
}

psa_status_t psa_destroy_key(psa_key_id_t key)
{
    if (is_key_builtin(key)) {

        memset(g_pubkey_data, 0, sizeof(g_pubkey_data));

    } else {

        assert(g_key_slot.is_valid && (g_key_slot.key_id == key));

        /* This will keep the value of the key_id so that a new import will
         * just use the next key_id. This allows to keep track of potential
         * clients trying to reuse a deleted key ID
         */
    }

    g_key_slot.buf = NULL;
    g_key_slot.len = 0;
    g_key_slot.attr = psa_key_attributes_init();
    g_key_slot.is_valid = false;

    return PSA_SUCCESS;
}

/* Signature verification supports only RSA or ECDSA with P256 or P384 */
psa_status_t psa_verify_hash(psa_key_id_t key,
                             psa_algorithm_t alg,
                             const uint8_t *hash,
                             size_t hash_length,
                             const uint8_t *signature,
                             size_t signature_length)
{
    psa_status_t status;

    if (is_key_builtin(key)) {
        status = get_builtin_key(key);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else {
        assert(g_key_slot.is_valid && (g_key_slot.key_id == key));
    }

    assert(PSA_ALG_IS_SIGN_HASH(alg));

    return psa_driver_wrapper_verify_hash(&g_key_slot.attr,
                                          g_key_slot.buf, g_key_slot.len,
                                          alg, hash, hash_length,
                                          signature, signature_length);
}

#ifdef PSA_WANT_ALG_LMS
static psa_status_t psa_lms_verify_message(psa_key_attributes_t *attr,
                                           const uint8_t *key, size_t key_length,
                                           psa_algorithm_t alg,
                                           const uint8_t *message, size_t message_length,
                                           const uint8_t *signature, size_t signature_length)
{
    int rc;
    mbedtls_lms_public_t ctx;

    mbedtls_lms_public_init(&ctx);

    rc = mbedtls_lms_import_public_key(&ctx, key, key_length);
    if (rc) {
        goto out;
    }

    rc = mbedtls_lms_verify(&ctx, message, message_length, signature, signature_length);
    if (rc) {
        goto out;
    }

out:
    mbedtls_lms_public_free(&ctx);

    return PSA_SUCCESS;
}
#endif /* PSA_WANT_ALG_LMS */

psa_status_t psa_verify_message(psa_key_id_t key,
                                psa_algorithm_t alg,
                                const uint8_t *message,
                                size_t message_length,
                                const uint8_t *signature,
                                size_t signature_length)
{
    psa_status_t status;
    uint8_t hash[PSA_HASH_MAX_SIZE];
    size_t hash_length;
    const psa_algorithm_t hash_alg = PSA_ALG_SIGN_GET_HASH(alg);

    assert(PSA_ALG_IS_SIGN_MESSAGE(alg));

    /* LMS isn't part of PSA yet, so we need this here */
#ifdef PSA_WANT_ALG_LMS
    if (PSA_ALG_IS_LMS(alg)) {
        return psa_lms_verify_message(&g_key_slot.attr,
                                      g_key_slot.buf, g_key_slot.len,
                                      alg, message, message_length,
                                      signature, signature_length);
    }
#else
    status = psa_driver_wrapper_hash_compute(hash_alg, message, message_length, hash, sizeof(hash), &hash_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    return psa_verify_hash(key, alg, hash, hash_length, signature, signature_length);
#endif /* PSA_WANT_ALG_LMS */
}

void mbedtls_psa_crypto_free(void)
{
    psa_driver_wrapper_free();
}

psa_status_t mbedtls_to_psa_error(int ret)
{
    /* We don't require precise error translation */
    if (!ret) {
        return PSA_SUCCESS;
    } else {
        return PSA_ERROR_GENERIC_ERROR;
    }
}

__WEAK psa_status_t psa_generate_random(uint8_t *output,
                                 size_t output_size)
{
#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)

    size_t output_length = 0;
    psa_status_t status = mbedtls_psa_external_get_random(g_ctx,
                                                          output, output_size,
                                                          &output_length);
    if (status != PSA_SUCCESS) {
        return status;
    }
    /* Breaking up a request into smaller chunks is currently not supported
     * for the external RNG interface.
     */
    if (output_length != output_size) {
        return PSA_ERROR_INSUFFICIENT_ENTROPY;
    }
    return PSA_SUCCESS;

#endif
    return PSA_ERROR_NOT_SUPPORTED;
}

/* This gets linked by the driver wrapper if no driver is present */
psa_status_t psa_verify_hash_builtin(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg, const uint8_t *hash, size_t hash_length,
    const uint8_t *signature, size_t signature_length)
{
#if PSA_WANT_ALG_RSA_PSS == 1
    if (PSA_KEY_TYPE_IS_RSA(psa_get_key_type(attributes))) {
        if (PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) ||
            PSA_ALG_IS_RSA_PSS(alg)) {
#if defined(MBEDTLS_PSA_BUILTIN_ALG_RSA_PSS)
            return mbedtls_psa_rsa_verify_hash(
                attributes,
                key_buffer, key_buffer_size,
                alg, hash, hash_length,
                signature, signature_length);
#endif /* defined(MBEDTLS_PSA_BUILTIN_ALG_RSA_PSS) */
        } else {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
#elif PSA_WANT_ALG_ECDSA == 1
    if (PSA_KEY_TYPE_IS_ECC(psa_get_key_type(attributes))) {
        if (PSA_ALG_IS_ECDSA(alg)) {
#if defined(MBEDTLS_PSA_BUILTIN_ALG_ECDSA) || \
            defined(MBEDTLS_PSA_BUILTIN_ALG_DETERMINISTIC_ECDSA)
            return mbedtls_psa_ecdsa_verify_hash(
                attributes,
                key_buffer, key_buffer_size,
                alg, hash, hash_length,
                signature, signature_length);
#endif /* defined(MBEDTLS_PSA_BUILTIN_ALG_ECDSA) ||
        * defined(MBEDTLS_PSA_BUILTIN_ALG_DETERMINISTIC_ECDSA)
        */
        } else {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
#endif

    (void) key_buffer;
    (void) key_buffer_size;
    (void) hash;
    (void) hash_length;
    (void) signature;
    (void) signature_length;

    return PSA_ERROR_NOT_SUPPORTED;
}

/* We don't need the full driver wrapper, we know the key is already a public key */
psa_status_t psa_driver_wrapper_export_public_key(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    uint8_t *data, size_t data_size, size_t *data_length)
{
    assert(PSA_KEY_TYPE_IS_PUBLIC_KEY(psa_get_key_type(attributes)));

    assert(key_buffer_size <= data_size);
    memcpy(data, key_buffer, key_buffer_size);
    *data_length = key_buffer_size;

    return PSA_SUCCESS;
}
#if defined(MCUBOOT_ENC_IMAGES)
psa_status_t psa_cipher_abort(psa_cipher_operation_t *operation)
{
   if (operation->id == 0) {
        /* The object has (apparently) been initialized but it is not (yet)
         * in use. It's ok to call abort on such an object, and there's
         * nothing to do. */
        return PSA_SUCCESS;
    }

    psa_driver_wrapper_cipher_abort(operation);

    operation->id = 0;
    operation->iv_set = 0;
    operation->iv_required = 0;

    return PSA_SUCCESS;
}

static psa_status_t psa_cipher_setup(psa_cipher_operation_t *operation,
                                     psa_key_id_t key,
                                     psa_algorithm_t alg,
                                     mbedtls_operation_t cipher_operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* A context must be freshly initialized before it can be set up. */
    if (operation->id != 0) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }
    if (!PSA_ALG_IS_CIPHER(alg)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }
    if (is_key_builtin(key)) {
        status = get_symmetric_builtin_key(key, alg);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else {
        assert(g_key_slot.is_valid && (g_key_slot.key_id == key));
    }
    operation->iv_set = 0;
    if (alg == PSA_ALG_ECB_NO_PADDING) {
        operation->iv_required = 0;
    } else {
        operation->iv_required = 1;
    }
    operation->default_iv_length = PSA_CIPHER_IV_LENGTH(g_key_slot.attr.type, alg);
    /* Try doing the operation through a driver before using software fallback. */
    if (cipher_operation == MBEDTLS_ENCRYPT) {
        status = psa_driver_wrapper_cipher_encrypt_setup(operation,
                                                         &g_key_slot.attr,
                                                         g_key_slot.buf,
                                                         g_key_slot.len,
                                                         alg);
    } else {
        status = psa_driver_wrapper_cipher_decrypt_setup(operation,
                                                         &g_key_slot.attr,
                                                         g_key_slot.buf,
                                                         g_key_slot.len,
                                                         alg);
    }

exit:
    if (status != PSA_SUCCESS) {
        psa_cipher_abort(operation);
    }

    return status;
}

psa_status_t psa_cipher_update(psa_cipher_operation_t *operation,
                               const uint8_t *input_external,
                               size_t input_length,
                               uint8_t *output_external,
                               size_t output_size,
                               size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (operation->id == 0) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    if (operation->iv_required && !operation->iv_set) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    status = psa_driver_wrapper_cipher_update(operation,
                                              input_external,
                                              input_length,
                                              output_external,
                                              output_size,
                                              output_length);
exit:
    if (status != PSA_SUCCESS) {
        psa_cipher_abort(operation);
    }

    return status;
}

psa_status_t psa_cipher_encrypt_setup(psa_cipher_operation_t *operation,
                                      psa_key_id_t key,
                                      psa_algorithm_t alg)
{
    return psa_cipher_setup(operation, key, alg, MBEDTLS_ENCRYPT);
}

psa_status_t psa_cipher_decrypt_setup(psa_cipher_operation_t *operation,
                                      psa_key_id_t key,
                                      psa_algorithm_t alg)
{
    return psa_cipher_setup(operation, key, alg, MBEDTLS_DECRYPT);
}

psa_status_t psa_cipher_set_iv(psa_cipher_operation_t *operation,
                               const uint8_t *iv_external,
                               size_t iv_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (operation->id == 0) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    if (operation->iv_set || !operation->iv_required) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    if (iv_length > PSA_CIPHER_IV_MAX_SIZE) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    status = psa_driver_wrapper_cipher_set_iv(operation,
                                              iv_external,
                                              iv_length);

exit:
    if (status == PSA_SUCCESS) {
        operation->iv_set = 1;
    } else {
        psa_cipher_abort(operation);
    }

    return status;
}

psa_status_t psa_cipher_finish(psa_cipher_operation_t *operation,
                               uint8_t *output_external,
                               size_t output_size,
                               size_t *output_length)
{
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;

    if (operation->id == 0) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    if (operation->iv_required && !operation->iv_set) {
        status = PSA_ERROR_BAD_STATE;
        goto exit;
    }

    status = psa_driver_wrapper_cipher_finish(operation,
                                              output_external,
                                              output_size,
                                              output_length);

exit:
    if (status == PSA_SUCCESS) {
        status = psa_cipher_abort(operation);
    } else {
        *output_length = 0;
        (void) psa_cipher_abort(operation);
    }

    return status;
}

void psa_reset_key_attributes(psa_key_attributes_t *attributes)
{
    memset(attributes, 0, sizeof(*attributes));
}

psa_status_t psa_wrap_key(psa_key_id_t wrapping_key,
                          psa_algorithm_t alg,
                          psa_key_id_t key,
                          uint8_t *data,
                          size_t data_size,
                          size_t *data_length)
{
    return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t psa_unwrap_key(const psa_key_attributes_t *attributes,
                            psa_key_id_t wrapping_key,
                            psa_algorithm_t alg,
                            const uint8_t *data,
                            size_t data_length,
                            psa_key_id_t *key)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_length = 0;

    if (is_key_builtin(wrapping_key)) {
        status = get_symmetric_builtin_key(wrapping_key, alg);
        if (status != PSA_SUCCESS) {
            return status;
        }
    } else {
        assert(g_key_slot.is_valid && (g_key_slot.key_id == wrapping_key));
    }

    status = mbedtls_nist_kw_unwrap(
        wrapping_key, MBEDTLS_KW_MODE_KW, data, data_length,
        g_symkey_data, sizeof(g_symkey_data), &output_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = psa_import_key(attributes, g_symkey_data, output_length, key);
    return status;
}
#endif /* MCUBOOT_ENC_IMAGES */

/* Set the key for a multipart authenticated encryption operation. */
EXTERNAL_PSA_API(psa_aead_encrypt_setup,
        (psa_aead_operation_t *operation, psa_key_id_t key_id, psa_algorithm_t alg),
        operation, key_id, alg)
{
#ifdef CC3XX_CRYPTO_OPAQUE_KEYS
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    const uint8_t *key_buffer;
    size_t key_buffer_size;
    psa_status_t status;

    status = cc3xx_opaque_keys_attr_init(&attributes, key_id, alg,
                                         &key_buffer, &key_buffer_size);
    if (status != PSA_SUCCESS) {
        FIH_RET(status);
    }

    status = psa_driver_wrapper_aead_encrypt_setup(operation,
                                                   &attributes,
                                                   key_buffer,
                                                   key_buffer_size,
                                                   alg);

    FIH_RET(status);
#else
    return PSA_ERROR_NOT_SUPPORTED;
#endif /* CC3XX_CRYPTO_OPAQUE_KEYS */
}

/* Set the key for a multipart authenticated decryption operation. */
EXTERNAL_PSA_API(psa_aead_decrypt_setup,
        (psa_aead_operation_t *operation, psa_key_id_t key_id, psa_algorithm_t alg),
        operation, key_id, alg)
{
#ifdef CC3XX_CRYPTO_OPAQUE_KEYS
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    const uint8_t *key_buffer;
    size_t key_buffer_size;
    psa_status_t status;

    status = cc3xx_opaque_keys_attr_init(&attributes, key_id, alg,
                                         &key_buffer, &key_buffer_size);
    if (status != PSA_SUCCESS) {
        FIH_RET(status);
    }

    status = psa_driver_wrapper_aead_decrypt_setup(operation,
                                                   &attributes,
                                                   key_buffer,
                                                   key_buffer_size,
                                                   alg);

    FIH_RET(status);
#else
    return PSA_ERROR_NOT_SUPPORTED;
#endif /* CC3XX_CRYPTO_OPAQUE_KEYS */
}

/* Set the nonce for an authenticated encryption or decryption operation */
EXTERNAL_PSA_API(psa_aead_set_nonce,
        (psa_aead_operation_t *operation, const uint8_t *nonce, size_t nonce_length),
        operation, nonce, nonce_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);
    assert(nonce != NULL);
    assert(nonce_length != 0);

    status = psa_driver_wrapper_aead_set_nonce(operation,
                                               nonce,
                                               nonce_length);

    FIH_RET(status);
}

/* Declare the lengths of the message and additional data for AEAD */
EXTERNAL_PSA_API(psa_aead_set_lengths,
        (psa_aead_operation_t *operation, size_t ad_length, size_t plaintext_length),
        operation, ad_length, plaintext_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);

    status = psa_driver_wrapper_aead_set_lengths(operation,
                                                 ad_length,
                                                 plaintext_length);

    FIH_RET(status);
}

/* Pass additional data to an active AEAD operation */
EXTERNAL_PSA_API(psa_aead_update_ad,
        (psa_aead_operation_t *operation, const uint8_t *input, size_t input_length),
        operation, input, input_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);
    assert((!input_length) ^ (input != NULL));

    status = psa_driver_wrapper_aead_update_ad(operation,
                                               input,
                                               input_length);

    FIH_RET(status);
}

/* Encrypt or decrypt a message fragment in an active AEAD operation */
EXTERNAL_PSA_API(psa_aead_update,
        (psa_aead_operation_t *operation, const uint8_t *input, size_t input_length,
         uint8_t *output, size_t output_size, size_t *output_length),
        operation, input, input_length, output, output_size, output_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);
    assert((!input_length) ^ (input != NULL));
    assert((!output_size) ^ (output != NULL));

    status = psa_driver_wrapper_aead_update(operation,
                                            input,
                                            input_length,
                                            output,
                                            output_size,
                                            output_length);

    FIH_RET(status);
}

/* Finish encrypting a message in an AEAD operation */
EXTERNAL_PSA_API(psa_aead_finish,
        (psa_aead_operation_t *operation, uint8_t *ciphertext, size_t ciphertext_size,
         size_t *ciphertext_length, uint8_t *tag, size_t tag_size, size_t *tag_length),
        operation, ciphertext, ciphertext_size, ciphertext_length, tag, tag_size, tag_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);
    assert(ciphertext_length != NULL);
    assert((!ciphertext_size) ^ (ciphertext != NULL));
    assert(tag != NULL);
    assert(tag_length != NULL);

    status = psa_driver_wrapper_aead_finish(operation,
                                            ciphertext,
                                            ciphertext_size,
                                            ciphertext_length,
                                            tag,
                                            tag_size,
                                            tag_length);

    FIH_RET(status);
}

/* Finish authenticating and decrypting a message in an AEAD operation */
EXTERNAL_PSA_API(psa_aead_verify,
        (psa_aead_operation_t *operation, uint8_t *plaintext, size_t plaintext_size,
         size_t *plaintext_length, const uint8_t *tag, size_t tag_length),
        operation, plaintext, plaintext_size, plaintext_length, tag, tag_length)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);
    assert(plaintext_length != NULL);
    assert((!plaintext_size) ^ (plaintext != NULL));
    assert(tag != NULL);
    assert(tag_length != 0);

    status = psa_driver_wrapper_aead_verify(operation,
                                            plaintext,
                                            plaintext_size,
                                            plaintext_length,
                                            tag,
                                            tag_length);

    FIH_RET(status);
}

EXTERNAL_PSA_API(psa_aead_abort,
        (psa_aead_operation_t *operation),
        operation)
{
    psa_status_t status;

    assert(operation != 0);
    assert(operation->id != 0);

    status = psa_driver_wrapper_aead_abort(operation);

    FIH_RET(status);
}
/*!@}*/

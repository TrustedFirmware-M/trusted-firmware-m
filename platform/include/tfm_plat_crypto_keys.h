/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PLAT_CRYPTO_KEYS_H__
#define __TFM_PLAT_CRYPTO_KEYS_H__

#include <stdbool.h>
#include <stdint.h>
#include "psa/crypto.h"
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Callback function type platform key loader functions
 *
 * This function pointer type defines the prototype for a builtin key loader function so that the
 * key can be probed by the tfm_builtin_key_loader driver during the init phase. Note that the key
 * must be readable from the secure processing element to be able to use the tfm_builtin_key_loader
 *
 * \param[in]  ctx       Context for the loader function
 * \param[out] buf       Buffer to hold the retrieved key material from the platform
 * \param[in]  buf_len   Size of the buf buffer
 * \param[out] key_len   Actual length of the key material in bytes retrieved from the platform
 * \param[out] key_bits  Size in bits of the key (important for those keys that are not
 *                       byte-multiple or encoded in different format than raw bytes)
 * \param[out] algorithm \ref psa_algorithm_t value associated to the retrieved key material
 * \param[out] type      \ref psa_key_type_t value associated to the retrieved key material
 *
 * \return Returns an error value as specified by the \ref tfm_plat_err_t type.
 *
 */
typedef enum tfm_plat_err_t (*key_loader_func_ptr_t)
    (const void *ctx, uint8_t *buf, size_t buf_len, size_t *key_len, psa_key_bits_t *key_bits, psa_algorithm_t *algorithm, psa_key_type_t *type);

/**
 * \brief This type describes the information that each TF-M builtin key
 *        must key in the associated descriptor table in \ref crypto_keys.c
 */
typedef struct {
    psa_key_id_t key_id;                   /*!< Key id associated to the builtin key */
    psa_drv_slot_number_t slot_number;     /*!< Slot number for the builtin key in the platform */
    psa_key_lifetime_t lifetime;           /*!< Lifetime (persistence + location) for the builtin key */
    key_loader_func_ptr_t loader_key_func; /*!< Loader function that reads the key from the platform */
    const void *loader_key_ctx;            /*!< Context passed to the key loader function */
} tfm_plat_builtin_key_descriptor_t;

/**
 * \brief This function retrieves a pointer to the description table for builtin keys. Each platform
 *        must implement this table with the details of the builtin keys available in the platform
 *
 * \param[out] desc_ptr A pointer to the description table
 *
 * \return size_t The number of builtin keys available in the platform
 */
size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[]);

/**
 * \brief This type maps a particular user of a builtin key (i.e. an owner) to
 *        the allowed usage (i.e. a policy) as specified by the platform
 */
typedef struct {
    int32_t user;
    psa_key_usage_t usage;
} tfm_plat_builtin_key_per_user_policy_t;

/**
 * \brief This type maps a particular key_id associated to a builtin key to the
 *        allowed usage (i.e. a policy). The policy can be user specific in case
 *        the per_user_policy field is greater than 0. In that case policy_ptr needs
 *        to be used to access the policies for each user of the key_id which are of
 *        type \ref tfm_platf_builtin_key_per_user_policy_t
 */
typedef struct {
    psa_key_id_t key_id;
    size_t per_user_policy;
    union {
        psa_key_usage_t usage;
        const tfm_plat_builtin_key_per_user_policy_t *policy_ptr;
    };
} tfm_plat_builtin_key_policy_t;

/**
 * \brief This function retrieves a pointer to the policy table of the builtin keys. Each platform
 *        must implement this table with the details of the builtin keys available in the platform
 *
 * \param[out] desc_ptr A pointer to the policy table
 *
 * \return size_t The number of builtin keys available in the platform with associated policies
 */
size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *desc_ptr[]);

/**
 * @brief Policy associated to the given key
 *
 * @enum tfm_bl2_key_policy_t
 */
enum tfm_bl2_key_policy_t {
    TFM_BL2_KEY_MIGHT_SIGN = 0b00,
    TFM_BL2_KEY_MUST_SIGN  = 0b01,
};

/**
 * \brief Reads the BL2 Root-of-Trust Public Key (ROTPK) policies from OTP.
 *
 * \param[out] buf      Pointer to the buffer where the policy blob will be stored.
 * \param[in]  buf_len  Size of the \p buf buffer in bytes.
 *
 * \retval TFM_PLAT_ERR_SUCCESS       The policies were read successfully.
 * \retval tfm_plat_err_t (other)     An error code indicating why the read failed.
 */
enum tfm_plat_err_t tfm_plat_get_bl2_rotpk_policies(uint8_t *buf, size_t buf_len);

/**
 * @brief Look up the policy bit mask associated with a particular key ID.
 *
 *        This function scans the platform-specific `tfm_image_key_map` array
 *        to find which image index and key slot correspond to the given key_id.
 *        It then calculates the bit position as:
 *        bit = (image_index * MAX_KEYS_PER_IMAGE) + key_index
 *        and returns a 32-bit mask with that single bit set.
 *        If `key_id` is not found in the map, the function returns 0.
 *
 * @param[in] key_id   The PSA key identifier to look up in `tfm_image_key_map`.
 *
 * @return
 *      A `uint32_t` mask with exactly one bit set if `key_id` was found:
 *      - Bit position = (image_index * MAX_KEYS_PER_IMAGE) + key_index
 *      Returns 0 if:
 *      - `key_id` is not present in `tfm_image_key_map`, or
 *      - the computed bit index would overflow a 32-bit word (should not occur
 *       if `MCUBOOT_IMAGE_NUMBER * MAX_KEYS_PER_IMAGE <= 32`).
 */
uint32_t get_policy_bit_mask(uint32_t key_id);

/**
 * @brief Check the key policy for a given key ID based on signature validity.
 *
 * @details This function evaluates the policy associated with the specified
 *          key ID and determines whether the key might or must be used for
 *          signing operations. It also tracks the count of keys that must
 *          sign if applicable.
 *
 * @param[in]  valid_sig           Boolean indicating if the signature is valid.
 * @param[in]  key                 The identifier of the key to check the policy for.
 * @param[out] key_might_sign      Pointer to a boolean that will be set to true
 *                                 if the key might be used for signing.
 * @param[out] key_must_sign       Pointer to a boolean that will be set to true
 *                                 if the key must be used for signing.
 * @param[out] key_must_sign_count Pointer to a counter that will be incremented
 *                                 if the key must sign.
 *
 * @return 0 on success, or an error code indicating the failure reason.
 */
int boot_plat_check_key_policy(bool valid_sig, psa_key_id_t key,
                               bool *key_might_sign, bool *key_must_sign,
                               uint8_t *key_must_sign_count);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PLAT_CRYPTO_KEYS_H__ */

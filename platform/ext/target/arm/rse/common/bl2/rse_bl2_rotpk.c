/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "tfm_plat_otp.h"

#include <bootutil/sign_key.h>
#include "rse_rotpk_mapping.h"

#ifdef MCUBOOT_HW_KEY
static enum tfm_plat_err_t get_rotpk_hash(enum tfm_otp_element_id_t id,
                                          uint8_t *rotpk_hash,
                                          size_t *rotpk_hash_size)
{
    enum tfm_plat_err_t err;
    enum rse_rotpk_hash_alg alg;

    err = tfm_plat_otp_read(id, *rotpk_hash_size, rotpk_hash);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = rse_rotpk_get_hash_alg(id, &alg);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *rotpk_hash_size = RSE_ROTPK_SIZE_FROM_ALG(alg);

    return TFM_PLAT_ERR_SUCCESS;
}

unsigned int pub_key_len;
struct bootutil_key bootutil_keys[1] = {
    {
        .key = 0,
        .len = &pub_key_len,
    },
};
const int bootutil_key_cnt = 1;

static enum tfm_plat_err_t get_otp_id(uint32_t image_index,
                                      enum tfm_otp_element_id_t *otp_id)
{
    const enum tfm_otp_element_id_t cm_id = rse_cm_get_bl2_rotpk(image_index);
    const enum tfm_otp_element_id_t dm_id = rse_dm_get_bl2_rotpk(image_index);

    if ((cm_id != PLAT_OTP_ID_INVALID) && (dm_id != PLAT_OTP_ID_INVALID)) {
        /* TODO FIXME in this case we should check both keys */
        *otp_id = cm_id;
    } else if ((cm_id != PLAT_OTP_ID_INVALID) && (dm_id == PLAT_OTP_ID_INVALID)) {
        *otp_id = cm_id;
    } else if ((cm_id == PLAT_OTP_ID_INVALID) && (dm_id != PLAT_OTP_ID_INVALID)) {
        *otp_id = dm_id;
    } else {
        return TFM_PLAT_ERR_IMAGE_HAS_NO_ROTPK_MAPPED;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

int boot_retrieve_public_key_hash(uint8_t image_index,
                                  uint8_t *public_key_hash,
                                  size_t *key_hash_size)
{
    enum tfm_otp_element_id_t otp_id;
    enum tfm_plat_err_t err;

    err = get_otp_id(image_index, &otp_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return get_rotpk_hash(otp_id, public_key_hash, key_hash_size);
}

#else

/**
 * @note When using builtin keys the signature verification happens based on key IDs.
 *       During verification MCUboot feeds the image index as a key ID and it is the
 *       underlying crypto library's responsibility to do a mapping (if required)
 *       between the image indexes and the builtin key IDs. Therefore it only allows
 *       as many IDs as there are images.
 */
const int bootutil_key_cnt = MCUBOOT_IMAGE_NUMBER;

/**
 * @brief Loader function to retrieve the Root of Trust Public Key
 *        to perform signature verification of the runtime image
 *        being loaded during the BL2 stage by MCUboot, with its associated
 *        metadata in order to be processed by the thin PSA Crypto core
 *
 * @param[in]  image_idx The index of the ROTPK, i.e. corresponds to the image index
 * @param[out] buf       Buffer containing the retrieved key material
 * @param[in]  buf_len   Size in bytes of the \a buf buffer
 * @param[out] key_len   Size in bytes of the key material returned in \a buf
 * @param[out] key_bits  Size in bits of the key, not necessarily the same as \a key_len
 * @param[out] algorithm Algorithm associated with the key
 * @param[out] type      Key type
 *
 * @return enum tfm_plat_err_t TFM_PLAT_ERR_SUCCESS or an error returned by OTP read
 */
static enum tfm_plat_err_t tfm_plat_get_bl2_rotpk(void *ctx,
                                                  uint8_t *buf, size_t buf_len,
                                                  size_t *key_len,
                                                  psa_key_bits_t *key_bits,
                                                  psa_algorithm_t *algorithm,
                                                  psa_key_type_t *type)
{
    enum tfm_plat_err_t err;
    tfm_plat_builtin_key_descriptor_t *descriptor =
        (tfm_plat_builtin_key_descriptor_t *)ctx;
    uint32_t image_idx = descriptor->key_id - 1;
    enum tfm_otp_element_id_t otp_id;

    err = get_otp_id(image_idx, &otp_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_read(otp_id, buf_len, buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* We read the size of the key material in byts, but that is not strictly
     * related to the properties of the key itself, i.e. its key_bits, due to
     * encoding of the key (RSA) or alignment requirements of the stored key
     * material, which in OTP must be 4-bytes aligned
     */
    err = tfm_plat_otp_get_size(otp_id, key_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* Metadata is not provisioned, so we just determine that on the
     * assumption that it matches the build time configuration
     */
#if defined(MCUBOOT_SIGN_EC256)
    /* OTP data is an ECPoint, uncompressed */
    *key_bits = PSA_BYTES_TO_BITS((65 - 1)/2);
    *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1);
#elif defined(MCUBOOT_SIGN_EC384)
    /* OTP data is an ECPoint, uncompressed */
    *key_bits = PSA_BYTES_TO_BITS((97 - 1)/2);
    *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_384);
    *type = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1);
#else
    *key_bits = 0;
    *algorithm = PSA_ALG_NONE;
    *type = PSA_KEY_TYPE_NONE;
#endif

#if defined(MCUBOOT_SIGN_EC256) || defined(MCUBOOT_SIGN_EC384)
    /* Discard padding zero bytes at the end of what is stored on OTP */
    *key_len = PSA_BITS_TO_BYTES(*key_bits)*2 + 1; /* 0x04 for uncompressed format */
#endif /* MCUBOOT_SIGN_EC256 || MCUBOOT_SIGN_EC384 */

    return TFM_PLAT_ERR_SUCCESS;
}

size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *policy_ptr[])
{
    static tfm_plat_builtin_key_policy_t policy_table[MCUBOOT_IMAGE_NUMBER];
    static bool policy_table_is_initalized = false;

    if (!policy_table_is_initalized) {
        for (uint32_t idx = 0; idx < MCUBOOT_IMAGE_NUMBER; idx++) {
            struct tfm_plat_builtin_key_policy_t policy = {
                .key_id = idx + 1,
                .per_user_policy = 0,
                .usage = PSA_KEY_USAGE_VERIFY_HASH,
            };

            policy_table[idx] = policy;
        }
    }

    *policy_ptr = &policy_table[0];
    return MCUBOOT_IMAGE_NUMBER;
}

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    static tfm_plat_builtin_key_descriptor_t descriptor_table[MCUBOOT_IMAGE_NUMBER];
    static bool descriptor_table_is_initalized = false;

    if (!descriptor_table_is_initalized) {
        for (uint32_t idx = 0; idx < MCUBOOT_IMAGE_NUMBER; idx++) {
            struct tfm_plat_builtin_key_descriptor_t descriptor = {
                .key_id = idx + 1,
                .slot_number = 0, /* Unused */
                .lifetime = PSA_KEY_LIFETIME_PERSISTENT,
                .loader_key_func = tfm_plat_get_bl2_rotpk,
                .loader_key_ctx = &descriptor_table[idx],
            };

            descriptor_table[idx] = descriptor;
        }
    }

    *desc_ptr = &descriptor_table[0];
    return MCUBOOT_IMAGE_NUMBER;
}
#endif /* !MCUBOOT_HW_KEY */

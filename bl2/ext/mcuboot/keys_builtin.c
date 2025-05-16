/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Original code taken from mcuboot project at:
 * https://github.com/mcu-tools/mcuboot
 * Git SHA of the original version: ac55554059147fff718015be9f4bd3108123f50a
 * Modifications are Copyright (c) 2019-2025 Arm Limited.
 */

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <bootutil/sign_key.h>
#include "mcuboot_config/mcuboot_config.h"
#include "tfm_plat_rotpk.h"
#include "tfm_plat_crypto_keys.h"
#include "tfm_plat_otp.h"

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
enum tfm_plat_err_t tfm_plat_get_bl2_rotpk_policies(uint8_t *buf, size_t buf_len)
{
    return tfm_plat_otp_read(PLAT_OTP_ID_BL2_ROTPK_POLICIES, buf_len, buf);
}
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

/* Maximum number of keys per image */
#define MAX_KEYS_PER_IMAGE MCUBOOT_ROTPK_MAX_KEYS_PER_IMAGE

/**
 * @note When using builtin keys the signature verification happens based on key IDs.
 *       During verification MCUboot feeds the image index as a key ID and it is the
 *       underlying crypto library's responsibility to do a mapping (if required)
 *       between the image indexes and the builtin key IDs. Therefore it only allows
 *       as many IDs as there are images times number of keys per image.
 */
const int bootutil_key_cnt = (MCUBOOT_IMAGE_NUMBER * MAX_KEYS_PER_IMAGE);

typedef struct {
    int key_id[MAX_KEYS_PER_IMAGE];  /*!< Key id of built in keys */
}image_key_id_mapping_t;

#ifdef MCUBOOT_IMAGE_MULTI_SIG_SUPPORT
/* Platform specific image to key id (otp id offset) map */
static const image_key_id_mapping_t tfm_image_key_map[] = {
    {
        /* Image 0: Two keys provided; both keys are required (bit mask: binary 00000011) */
        .key_id = { TFM_S_KEY_ID, TFM_S_KEY_ID_2},
    },
    {
        /* Image 1: Only one key is provided and required, the second slot is unused */
        .key_id = { TFM_NS_KEY_ID, PSA_KEY_ID_NULL },
    },
#if (MCUBOOT_IMAGE_NUMBER > 2)
    {
        /* Image 2: Only one key is provided and required, the second slot is unused */
        .key_id = { TFM_S_KEY_ID_3, PSA_KEY_ID_NULL },
    },
#endif /* MCUBOOT_IMAGE_NUMBER > 2 */
#if (MCUBOOT_IMAGE_NUMBER > 3)
    {
        /* Image 3: Only one key is provided and required, the second slot is unused */
        .key_id = { TFM_S_KEY_ID_4, PSA_KEY_ID_NULL },
    },
#endif /* MCUBOOT_IMAGE_NUMBER > 3 */
};

#else
/* Platform specific image to key id (otp id offset) map */
static const image_key_id_mapping_t tfm_image_key_map[] = {
    {
        /* Image 0: Only one key is provided and required */
        .key_id = { TFM_S_KEY_ID },
    },
    {
        /* Image 1: Only one key is provided and required */
        .key_id = { TFM_NS_KEY_ID },
    },
#if (MCUBOOT_IMAGE_NUMBER > 2)
    {
        /* Image 2: Only one key is provided and required */
        .key_id = { TFM_S_KEY_ID_3 },
    },
#endif /* MCUBOOT_IMAGE_NUMBER > 2 */
#if (MCUBOOT_IMAGE_NUMBER > 3)
    {
        /* Image 3: Only one key is provided and required */
        .key_id = { TFM_S_KEY_ID_4 },
    },
#endif /* MCUBOOT_IMAGE_NUMBER > 3 */
};
#endif /* MCUBOOT_IMAGE_MULTI_SIG_SUPPORT */

/**
 * @brief Loader function to retrieve the Root of Trust Public Key
 *        to perform signature verification of the runtime image
 *        being loaded during the BL2 stage by MCUboot, with its associated
 *        metadata in order to be processed by the thin PSA Crypto core
 *
 * @param[in]  ctx       Loader function context. This contains loader function specific
 *                       information, i.e. the \ref tfm_plat_builtin_key_descriptor_t of
 *                       the keys, the descriptor table
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
static enum tfm_plat_err_t tfm_plat_get_bl2_rotpk(const void *ctx,
                                                  uint8_t *buf, size_t buf_len,
                                                  size_t *key_len,
                                                  psa_key_bits_t *key_bits,
                                                  psa_algorithm_t *algorithm,
                                                  psa_key_type_t *type)
{
    enum tfm_plat_err_t err;
    const tfm_plat_builtin_key_descriptor_t *descriptor = (const tfm_plat_builtin_key_descriptor_t *)ctx;

    assert(descriptor->key_id >= 0);

    uint32_t otp_id = PLAT_OTP_ID_BL2_ROTPK_0 + descriptor->key_id;
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
     * assumption that it matches the build time confguration
     */
#if defined(MCUBOOT_SIGN_RSA)
    /* This is either a 2048, 3072 or 4096 bit RSA key, hence the TLV must place
     * the length at index (6,7) with a leading 0x00. The leading 0x00 is due to
     * the fact that the MSB will always be set for RSA keys where the length is
     * a multiple of 8 bits. The format is RSAPublicKey ASN.1
     */
    *key_bits =
        PSA_BYTES_TO_BITS((((uint16_t)buf[6]) << 8) | (uint16_t)buf[7]) - 8;
    *algorithm = PSA_ALG_RSA_PSS(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_RSA_PUBLIC_KEY;
#elif defined(MCUBOOT_SIGN_EC256)
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

static int get_key_id(uint8_t img_idx, uint8_t key_idx)
{
    assert(img_idx < MCUBOOT_IMAGE_NUMBER);
    assert(key_idx < MAX_KEYS_PER_IMAGE);
    return tfm_image_key_map[img_idx].key_id[key_idx];
}

/* The policy table is built dynamically at runtime to allow for an arbitrary
 * number of MCUBOOT_IMAGE_NUMBER entries, without hardcoding at build time
 */
size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *policy_ptr[])
{
    static tfm_plat_builtin_key_policy_t policy_table[MCUBOOT_IMAGE_NUMBER][MAX_KEYS_PER_IMAGE];
    static bool policy_table_is_initalized = false;

    if (!policy_table_is_initalized) {
        for (uint32_t i = 0; i < MCUBOOT_IMAGE_NUMBER; i++) {
            for (uint32_t j = 0; j < MAX_KEYS_PER_IMAGE; j++) {
                tfm_plat_builtin_key_policy_t policy = {
                    .per_user_policy = 0,
                    .usage = PSA_KEY_USAGE_VERIFY_HASH,
                };

                policy.key_id = get_key_id(i,j);
                policy_table[i][j] = policy;
            }
        }
        policy_table_is_initalized = true;
    }

    *policy_ptr = &policy_table[0][0];
    return MCUBOOT_IMAGE_NUMBER * MAX_KEYS_PER_IMAGE;

}

/* The descriptor table is built dynamically at runtime to allow for an arbitrary
 * number of MCUBOOT_IMAGE_NUMBER entries, without hardcoding at build time
 */
size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    static tfm_plat_builtin_key_descriptor_t descriptor_table[MCUBOOT_IMAGE_NUMBER][MAX_KEYS_PER_IMAGE];
    static bool descriptor_table_is_initalized = false;

    if (!descriptor_table_is_initalized) {
        for (uint32_t i = 0; i < MCUBOOT_IMAGE_NUMBER; i++) {
            for (uint32_t j = 0; j < MAX_KEYS_PER_IMAGE; j++) {
                tfm_plat_builtin_key_descriptor_t descriptor = {
                    .slot_number = 0, /* Unused */
                    .lifetime = PSA_KEY_LIFETIME_PERSISTENT,
                    .loader_key_func = tfm_plat_get_bl2_rotpk,
                    .loader_key_ctx = &descriptor_table[i][j],
                };
                descriptor.key_id = get_key_id(i,j);
                descriptor_table[i][j] = descriptor;
            }
        }

        descriptor_table_is_initalized = true;
    }

    *desc_ptr = &descriptor_table[0][0];
    return MCUBOOT_IMAGE_NUMBER * MAX_KEYS_PER_IMAGE;
}

int boot_verify_key_id_for_image(uint8_t image_index, int32_t key_id)
{
    for (int i = 0; i < MAX_KEYS_PER_IMAGE; i++) {
        if (key_id == get_key_id(image_index, i)) {
            return 0;
        }
    }
    /* If the key id is not found in the image key id mapping, return -1 */
    return -1;
}


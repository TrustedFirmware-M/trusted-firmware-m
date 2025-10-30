/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "bl1_2_image_binding.h"
#include "bl1_crypto.h"
#include "fih.h"
#include "tfm_builtin_key_ids.h"
#include "util.h"
#include "psa/crypto.h"
#include "image.h"
#include "tfm_log.h"
#include "tfm_plat_otp.h"
#include "rse_kmu_slot_ids.h"
#include "cc3xx_opaque_keys.h"

static inline psa_key_id_t get_binding_key(void)
{
    return cc3xx_get_opaque_key(RSE_KMU_SLOT_SECURE_BINDING_KEY);
}

FIH_RET_TYPE(int) is_binding_tag_present(const struct bl1_2_image_t *image)
{
    static const uint8_t zero_tag[16] = {0};
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    FIH_CALL(bl_fih_memeql, fih_rc, image->header.binding_tag, zero_tag, sizeof(zero_tag));
    if (FIH_EQ(fih_rc, FIH_SUCCESS)) {
        /* Tag is all-zero, so not present */
        FIH_RET(FIH_FAILURE);
    } else {
        /* Tag is non-zero, so is present */
        FIH_RET(FIH_SUCCESS);
    }
}

#ifndef TFM_BL1_2_IMAGE_ENCRYPTION
static FIH_RET_TYPE(int) store_binding_tag(struct bl1_2_image_t *image,
                                           uint8_t tag[16],
                                           uint32_t image_id)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    /* Update the RAM copy header */
    memcpy(image->header.binding_tag, tag, sizeof(image->header.binding_tag));

    FIH_CALL(bl1_2_store_image_binding_tag, fih_rc, image_id, image, tag);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    return FIH_SUCCESS;
}

static FIH_RET_TYPE(int) compute_binding_tag(const struct bl1_2_image_t *image,
                                   uint8_t out_tag[16])
{
    uint8_t hash[32];
    size_t hash_len;
    size_t mac_len;

    psa_status_t st;
    st = psa_hash_compute((psa_algorithm_t)PSA_ALG_SHA_256,
                           (uint8_t *)&image->protected_values,
                           sizeof(image->protected_values),
                           hash, sizeof(hash), &hash_len);
    if (st != PSA_SUCCESS) {
        ERROR("Hash function failure\n");
        FIH_RET(fih_ret_encode_zero_equality(st));
    }

    psa_mac_operation_t mac_op = PSA_MAC_OPERATION_INIT;
    psa_key_id_t key_id = get_binding_key();
    if (key_id == PSA_KEY_ID_NULL) {
        ERROR("Failed to get binding key\n");
        memset(hash, 0, sizeof(hash));
        FIH_RET(FIH_FAILURE);
    }

    /* Setup CMAC (AES-CMAC) */
    st = psa_mac_sign_setup(&mac_op, key_id, PSA_ALG_CMAC);
    if (st != PSA_SUCCESS) {
        memset(hash, 0, sizeof(hash));
        FIH_RET(FIH_FAILURE);
    }

    /* Feed the hash as “authenticated data” (CMAC input) */
    st = psa_mac_update(&mac_op, (const uint8_t *)hash, sizeof(hash));
    memset(hash, 0, sizeof(hash));
    if (st != PSA_SUCCESS) {
        psa_mac_abort(&mac_op);
        FIH_RET(FIH_FAILURE);
    }

    /* Finish CMAC and get the tag (16 bytes for AES) */
    st = psa_mac_sign_finish(&mac_op,
                             (uint8_t *)out_tag,
                             16,        /* requested tag size */
                             &mac_len);
    if (st != PSA_SUCCESS || mac_len != 16) {
        FIH_RET(FIH_FAILURE);
    }

    return FIH_SUCCESS;
}

FIH_RET_TYPE(int) bl1_2_do_image_binding(struct bl1_2_image_t *image, uint32_t image_id)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    uint8_t out_tag[16];

    /* Compute image binding tag */
    FIH_CALL(compute_binding_tag, fih_rc, image, out_tag);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(FIH_FAILURE);
    }

    /* Store calculated binding tag */
    FIH_CALL(store_binding_tag, fih_rc, image, out_tag, image_id);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(FIH_FAILURE);
    }

    return FIH_SUCCESS;
}

FIH_RET_TYPE(int) bl1_2_validate_image_binding(const struct bl1_2_image_t *image)
{
    uint8_t computed[16];
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    FIH_CALL(compute_binding_tag, fih_rc, image, computed);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* Compare computed vs stored tag from image header */
    FIH_CALL(bl_fih_memeql, fih_rc, computed, image->header.binding_tag, sizeof(computed));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        memset(computed, 0, sizeof(computed));
        FIH_RET(fih_rc);
    }

    memset(computed, 0, sizeof(computed));
    FIH_RET(FIH_SUCCESS);
}

#endif /* TFM_BL1_2_IMAGE_ENCRYPTION */

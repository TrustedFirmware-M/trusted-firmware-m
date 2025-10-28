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

FIH_RET_TYPE(int) bl1_2_validate_image_binding(struct bl1_2_image_t *image)
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

#else
/* Encryption and binding; AEAD - CCM */
#define BL1_2_BIND_BLOCK_SIZE (FLASH_PAGE_SIZE)
#define CCM_NONCE_LEN 12   /* CCM L=3 → max payload len ~ 16MB */

static inline const uint8_t* pv_start(struct bl1_2_image_t *image)
{
    return (const uint8_t *)&image->protected_values;
}

static inline size_t pv_len(const struct bl1_2_image_t *image)
{
    return sizeof(image->protected_values);
}

FIH_RET_TYPE(int) bl1_2_do_image_binding(struct bl1_2_image_t *image,
                                         uint32_t image_id)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    int rc;
    uint8_t nonce[CCM_NONCE_LEN];
    uint32_t local_tag[16 / sizeof(uint32_t)];
    size_t off, block_size;
    uint8_t out_buf[BL1_2_BIND_BLOCK_SIZE];
    uint8_t sector_buf[FLASH_SECTOR_SIZE];
    size_t out_len, tag_len;
    psa_key_id_t key_id = PSA_KEY_ID_NULL;

    /* Encrypt entire protected region which include payload, counter and version */
    const uint8_t *plaintext  = pv_start(image);
    size_t pv_size = pv_len(image);

    /* Map image_id -> absolute flash offset */
    const uint32_t img_off = bl1_image_get_flash_offset(image_id);
    const uintptr_t pv_base = (uintptr_t)img_off + offsetof(struct bl1_2_image_t, protected_values);

    uint32_t q = 15 - CCM_NONCE_LEN;
    if ((pv_size >> (8u * q)) != 0) {
        ERROR("CCM payload too large for nonce_len=%u (q=%u)\n", CCM_NONCE_LEN, q);
        FIH_RET(FIH_FAILURE);
    }
    memcpy(nonce, image->header.ctr_iv, CCM_NONCE_LEN);

    key_id = get_binding_key();
    if (key_id == PSA_KEY_ID_NULL) {
        ERROR("Failed to get binding key\n");
        FIH_RET(FIH_FAILURE);
    }
    psa_aead_operation_t op = PSA_AEAD_OPERATION_INIT;
    psa_status_t st;
    st = psa_aead_encrypt_setup(&op, key_id, PSA_ALG_CCM);
    if (st != PSA_SUCCESS) {
        ERROR("BL1_2 binding: CCM setup failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_set_lengths(&op, 0, pv_size);
    if (st != PSA_SUCCESS) {
        ERROR("BL1_2 binding: CCM set_lengths failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_set_nonce(&op, nonce, CCM_NONCE_LEN);
    memset(nonce, 0, sizeof(nonce));
    if (st != PSA_SUCCESS) {
        ERROR("BL1_2 binding: CCM set_nonce failed (%d)", (int)st);
        return -1;
    }

    bl1_2_image_flash_bind_ctx_t fw;
    rc = bl1_2_image_flash_bind_begin(&fw, pv_base, pv_size, sector_buf, sizeof(sector_buf));
    if (rc) {
        ERROR("Failed to begin flash binding write\n");
        psa_aead_abort(&op);
        FIH_RET(FIH_FAILURE);
    }

    off = 0;
    while (off < pv_size) {
        block_size = BL1_2_BIND_BLOCK_SIZE;
        if (block_size > pv_size - off) {
            block_size = pv_size - off;
        }

        /* AEAD update: plaintext -> ciphertext */
        st = psa_aead_update(&op,plaintext + off, block_size, out_buf, sizeof(out_buf), &out_len);
        if (st != PSA_SUCCESS) {
            ERROR("psa_aead_update() failed for binding: %d\n", (int)st);
            goto fail;
        }

        /* PSA may output less than block_size; write the produced bytes */
        if (out_len > 0) {
            rc = bl1_2_image_flash_bind_write(&fw, out_buf, out_len);
            if (rc) {
                ERROR("Failed to write encrypted block to flash at offset 0x%08X\n", (unsigned)(pv_base + off));
                goto fail;
            }
        }
        off += block_size;
    }

    /* Finish: may output final ciphertext + tag */
    st = psa_aead_finish(&op, out_buf, sizeof(out_buf), &out_len, (uint8_t *)local_tag, sizeof(local_tag), &tag_len);
    if (st != PSA_SUCCESS) {
        ERROR("psa_aead_finish() failed: %d\n", (int)st);
        memset(local_tag, 0, sizeof(local_tag));
        goto fail;
    }

    /* Write any remaining ciphertext tail */
    if (out_len > 0) {
        rc = bl1_2_image_flash_bind_write(&fw, out_buf, out_len);
        if (rc) {
            ERROR("Failed to write final encrypted bytes to flash\n");
            memset(local_tag, 0, sizeof(local_tag));
            goto fail;
        }
    }
    memset(out_buf, 0, sizeof(out_buf));
    if (tag_len != 16) {
        ERROR("Unexpected CCM tag length %u (expected 16)\n", (unsigned)tag_len);
        memset(local_tag, 0, sizeof(local_tag));
        goto fail;
    }

    memcpy(image->header.binding_tag, local_tag, 16);

    /* Write tag to flash */
    FIH_CALL(bl1_2_store_image_binding_tag, fih_rc, image_id,
             image, (const uint8_t *)local_tag);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Failed to store binding tag to flash\n");
        FIH_RET(fih_rc);
    }
    memset(local_tag, 0, sizeof(local_tag));

    FIH_RET(FIH_SUCCESS);

fail:
    memset(out_buf, 0, sizeof(out_buf));
    psa_aead_abort(&op);
    FIH_RET(FIH_FAILURE);
}

FIH_RET_TYPE(int) bl1_2_validate_image_binding(struct bl1_2_image_t *image)
{
    uint8_t       nonce[CCM_NONCE_LEN];
    const uint8_t *ct;
    size_t        total, chunk, in_off, out_off, out_len;
    uint8_t       *dst;
    uint8_t tmp[BL1_2_BIND_BLOCK_SIZE];
    psa_status_t          st;
    psa_key_id_t          key_id = PSA_KEY_ID_NULL;
    psa_aead_operation_t  op  = PSA_AEAD_OPERATION_INIT;

    dst     = (uint8_t *)&image->protected_values;
    /* Ciphertext lives in the RAM copy of protected_values */
    ct    = (const uint8_t *)&image->protected_values;
    total = sizeof(image->protected_values);

    /* Derive AEAD key (same as bind-time) */
    key_id = get_binding_key();
    if (key_id == PSA_KEY_ID_NULL) {
        ERROR("Failed to get binding key\n");
        FIH_RET(FIH_FAILURE);
    }
    uint32_t q = 15 - CCM_NONCE_LEN;
    if ((total >> (8u * q)) != 0) {
        ERROR("CCM payload too large for nonce_len=%u (q=%u)\n", CCM_NONCE_LEN, q);
        FIH_RET(FIH_FAILURE);
    }
    memcpy(nonce, image->header.ctr_iv, CCM_NONCE_LEN);


    /* Init CCM (decrypt) */
    st = psa_aead_decrypt_setup(&op, key_id, PSA_ALG_CCM);
    if (st != PSA_SUCCESS) {
        ERROR("BL1_2 binding: CCM setup failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_set_lengths(&op, 0, total);
    if (st != PSA_SUCCESS) {
        ERROR("psa_aead_set_lengths() failed: %d\n", (int)st);
        memset(nonce, 0, sizeof(nonce));
        goto fail;
    }

    /* Set the nonce (IV) */
    st = psa_aead_set_nonce(&op, nonce, CCM_NONCE_LEN);
    memset(nonce, 0, sizeof(nonce));
    if (st != PSA_SUCCESS) {
        ERROR("psa_aead_set_nonce() failed: %d\n", (int)st);
        goto fail;
    }

    /* Stream CT -> dst (SRAM for BL2) */
    in_off  = 0;
    out_off = 0;
    while (in_off < total) {
        chunk = BL1_2_BIND_BLOCK_SIZE;
        if (chunk > (total - in_off)) {
            chunk = total - in_off;
        }

        st = psa_aead_update(&op, ct + in_off, chunk, tmp, sizeof(tmp), &out_len);
        if (st != PSA_SUCCESS) {
            ERROR("psa_aead_update() failed at offset %u: %d\n", in_off, (int)st);
            memset(dst, 0, out_off);
            goto fail;
        }
        if (out_len > 0) {
            if (out_off + out_len > total) {
                ERROR("AEAD produced more plaintext than expected\n");
                memset(dst, 0, total);
                goto fail;
            }
            memcpy(dst + out_off, tmp, out_len);
            out_off += out_len;
        }
        in_off += chunk;
    }

    /* Finalize decryption and verify tag against header.binding_tag */
    st = psa_aead_verify(&op, tmp, sizeof(tmp), &out_len, image->header.binding_tag, 16);
    if (st != PSA_SUCCESS) {
        ERROR("psa_aead_verify_finish() failed (bad tag or error): %d\n", (int)st);
        memset(dst, 0, total);
        goto fail;
    }

    if (out_len > 0) {
        if (out_off + out_len > total) {
            ERROR("AEAD finish produced more plaintext than expected\n");
            memset(dst, 0, total);
            goto fail;
        }
        memcpy(dst + out_off, tmp, out_len);
        out_off += out_len;
    }

    if (out_off != total) {
        ERROR("Plaintext length mismatch: got %u, expected %u\n", out_off, total);
        memset(dst, 0, total);
        goto fail;
    }

    FIH_RET(FIH_SUCCESS);

fail:
    psa_aead_abort(&op);
    FIH_RET(FIH_FAILURE);
}
#endif /* TFM_BL1_2_IMAGE_ENCRYPTION */

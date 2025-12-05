/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "psa/crypto.h"
#include "bootutil/image.h"
#include "bootutil/security_cnt.h"
#include "fih.h"
#include "rse_bl2_binding.h"
#include "rse_bl2_binding_util.h"
#include "flash_map/flash_map.h"
#include "tfm_log.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define RSE_AD_LABEL  "RSEBINDv1"
#define BIND_BLOCK_SIZE  1024
#define AD_BUF_SIZE 32

static struct rse_bind_ctx g_bind_ctx[MCUBOOT_IMAGE_NUMBER];

static inline void build_ad_buf(uint8_t image_id,
                                const struct image_header *hdr,
                                uint32_t sec_cnt,
                                uint8_t *out, size_t out_size,
                                size_t *out_len)
{
    /* AD = image_id || label || flags || ver || sec_cnt  */
    uint64_t version;
    const size_t image_id_len = 1;
    const size_t label_len = sizeof(RSE_AD_LABEL); /* 10 bytes */
    const size_t version_len = 8;
    const size_t flags_len = 4;
    const size_t sec_cnt_len = 4;
    const size_t total_fixed_len = label_len + version_len + flags_len + sec_cnt_len;
    int i;
    uint8_t *ad_ptr = out;

    assert(hdr != NULL);
    assert(out != NULL);
    assert(out_len != NULL);
    assert(out_size >= total_fixed_len + image_id_len);

    memcpy (ad_ptr, &image_id, image_id_len);
    ad_ptr += image_id_len;

    memcpy(ad_ptr, RSE_AD_LABEL, label_len);
    ad_ptr += label_len;

    for (i = 0; i < 4; i++) {
        *ad_ptr++ = (uint8_t)(hdr->ih_flags >> (8 * i));
    }

    version = ((uint64_t)hdr->ih_ver.iv_major) |
              ((uint64_t)hdr->ih_ver.iv_minor << 16) |
              ((uint64_t)hdr->ih_ver.iv_revision << 32) |
              ((uint64_t)hdr->ih_ver.iv_build_num << 48);
    for (i = 0; i < 8; i++) {
        *ad_ptr++ = (uint8_t)(version >> (8 * i));
    }

    for (i = 0; i < 4; i++) {
        *ad_ptr++ = (uint8_t)(sec_cnt >> (8 * i));
    }

    *out_len = (size_t)(ad_ptr - out);
}

static bool is_all_ff(const uint8_t *p, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (p[i] != 0xFF) {
            return false;
        }
    }

    return true;
}

int rse_read_binding_data(uint8_t image_id,
                          const struct flash_area *fa,
                          const struct image_header *hdr)
{
    uint8_t meta[RSE_TLV_BIND_LEN], tag[RSE_TLV_BIND_LEN];
    int rc;
    struct rse_bind_ctx *ctx = &g_bind_ctx[image_id];

    memset(ctx, 0, sizeof *ctx);

    /* Read security counter */
    rc = read_sec_cnt(fa, hdr, &ctx->sec_cnt);
    if (rc) {
        return -1;
    }

    /* Read binding tag and metadata */
    if (read_unprot_tlv16(fa, hdr, RSE_TLV_BIND_META_TYPE, meta, RSE_TLV_BIND_LEN) ||
        read_unprot_tlv16(fa, hdr, RSE_TLV_BIND_TAG_TYPE,  tag, RSE_TLV_BIND_LEN)) {
        return -1;
    }

    /* Check if binding TLVs are unset (all 0xFF) */
    if (is_all_ff(meta, RSE_TLV_BIND_LEN) || is_all_ff(tag, RSE_TLV_BIND_LEN)) {
        INFO("BL2 binding: binding metadata are not set for image %d\n", image_id);
        return 0;
    }

    /* Verify bind state */
    if ( (meta[RSE_META_BIND_STATE_OFFSET] != RSE_BIND_STATE_BOUND) ||
         (meta[RSE_META_BIND_ALG_OFFSET] != RSE_BIND_CCM_BOUND) ) {
        ERROR("BL2 binding: invalid binding state %u\n", meta[RSE_META_BIND_STATE_OFFSET]);
        return -1;
    }

    /* Save binding data to context */
    memcpy(ctx->meta, meta, RSE_TLV_BIND_LEN);
    memcpy(ctx->tag,  tag, RSE_TLV_BIND_LEN);
    memcpy(ctx->nonce, &meta[RSE_META_BIND_CCM_NONCE_OFFSET], RSE_BIND_CCM_IV_LEN);
    ctx->has_tag = true;

    return 0;
}

fih_ret rse_bind_has_tag(uint8_t image_id)
{
    if (g_bind_ctx[image_id].has_tag) {
        return FIH_SUCCESS;
    }

    return FIH_FAILURE;
}

int rse_do_binding(uint8_t img_index,
                   const struct flash_area *fa,
                   const struct image_header *hdr)
{
    int rc;
    uint8_t meta[RSE_TLV_BIND_LEN];
    uint8_t tag[RSE_BIND_CCM_TAG_LEN];
    uint8_t ad[AD_BUF_SIZE];
    uint8_t out[BIND_BLOCK_SIZE];
    psa_key_id_t binding_key_id;
    struct rse_bind_ctx *ctx = &g_bind_ctx[img_index];
    size_t out_len, chunk, ad_len, tail_len, tag_len;
    psa_status_t st;
    uint8_t tail[32];
    uint32_t write_offset = hdr->ih_hdr_size;
    psa_aead_operation_t op = PSA_AEAD_OPERATION_INIT;

    memcpy(meta, ctx->meta, RSE_TLV_BIND_LEN);

    /* Set meta to in progress */
    meta[RSE_META_BIND_STATE_OFFSET] = RSE_BIND_STATE_IN_PROG;
    meta[RSE_META_BIND_ALG_OFFSET] = RSE_BIND_CCM_BOUND;
    meta[RSE_META_BIND_CCM_IV_LEN_OFFSET] = RSE_BIND_CCM_IV_LEN;
    meta[RSE_META_BIND_CCM_TAG_LEN_OFFSET] = RSE_BIND_CCM_TAG_LEN;
    memcpy(&meta[RSE_META_BIND_CCM_NONCE_OFFSET], ctx->nonce, RSE_BIND_CCM_IV_LEN);

    rc = write_unprot_tlv(fa, hdr, IMAGE_TLV_BIND_METADATA, meta, 16);
    if (rc) {
        ERROR("BL2 binding: metadata write failed");
        return -1;
    }

    /* Resolve device binding key */
    binding_key_id = rse_get_cmac_key_for_image(img_index);
    if (binding_key_id == PSA_KEY_ID_NULL) {
        ERROR("BL2 binding: CCM key unavailable for image %d\n", img_index);
        flash_area_close(fa);
        return -1;
    }

    /* Build additional data for CCM authentication */
    build_ad_buf(img_index, hdr, ctx->sec_cnt, ad, sizeof(ad), &ad_len);

    st = psa_aead_encrypt_setup(&op, binding_key_id, PSA_ALG_CCM);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CCM setup failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_set_lengths(&op, ad_len, ctx->body_len);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CCM set_lengths failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_set_nonce(&op, ctx->nonce, RSE_BIND_CCM_IV_LEN);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CCM set_nonce failed (%d)", (int)st);
        return -1;
    }

    st = psa_aead_update_ad(&op, ad, ad_len);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CCM update_ad failed (%d)", (int)st);
        return -1;
    }

    for (size_t pos = 0; pos < ctx->body_len; ) {
        chunk = MIN(sizeof(out), ctx->body_len - pos);

        st = psa_aead_update(&op, ctx->body_base + pos, chunk, out, sizeof(out), &out_len);
        if (st != PSA_SUCCESS) {
            ERROR("BL2 binding: CCM update failed (%d)", (int)st);
            return -1;
        }

        rc = flash_area_write(fa, write_offset, out, out_len);
        if (rc) {
            ERROR("BL2 binding: CCM write failed");
            return -1;
        }
        write_offset += out_len;
        pos += chunk;
    }

    st = psa_aead_finish(&op, tail, sizeof(tail), &tail_len, tag,  sizeof(tag),  &tag_len);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CCM finish failed (%d)", (int)st);
        return -1;
    }

    /* Write any remaining ciphertext produced at finish() */
    if (tail_len) {
        rc = flash_area_write(fa, write_offset, tail, tail_len);
        if (rc) {
            ERROR("BL2 binding: CCM tail write failed");
            return -1;
        }
        write_offset += tail_len;
    }

    rc = write_unprot_tlv(fa, hdr, IMAGE_TLV_BIND_TAG, tag, RSE_BIND_CCM_TAG_LEN);
    if (rc) {
        ERROR("BL2 binding: tag write failed");
        return -1;
    }

    meta[RSE_META_BIND_STATE_OFFSET] = RSE_BIND_STATE_BOUND;
    rc = write_unprot_tlv(fa, hdr, IMAGE_TLV_BIND_METADATA, meta, 16);
    if (rc) {
        ERROR("BL2 binding: metadata write failed");
        return -1;
    }
    memcpy(ctx->meta, meta, RSE_TLV_BIND_LEN);
    memcpy(ctx->tag, tag, RSE_BIND_CCM_TAG_LEN);

    return 0;
}

void rse_bind_set_ram_window(uint8_t image_id,
                             const uint8_t *body_base, size_t body_len)
{
    struct rse_bind_ctx *ctx = &g_bind_ctx[image_id];
    ctx->body_base = body_base;
    ctx->body_len  = body_len;
}

fih_ret rse_bind_is_authenticated(uint8_t image_id)
{
    if (g_bind_ctx[image_id].is_authenticated) {
        return FIH_SUCCESS;
    }

    return FIH_FAILURE;
}

fih_ret boot_enc_decrypt_and_auth_in_sram(uint8_t image_id,
                                          const struct image_header *hdr)
{
    uint8_t ad[AD_BUF_SIZE];
    uint8_t *body = (uint8_t *)(hdr->ih_load_addr + hdr->ih_hdr_size);
    size_t ad_len, i, chunk, out_len, local_tag;
    psa_status_t st;
    psa_key_id_t key;
    struct rse_bind_ctx *ctx = &g_bind_ctx[image_id];
    const size_t body_len = hdr->ih_img_size;
    uint8_t tmp[BIND_BLOCK_SIZE];
    psa_aead_operation_t op = PSA_AEAD_OPERATION_INIT;

    ctx->is_authenticated = false;
    key = rse_get_cmac_key_for_image(image_id);
    if (key == PSA_KEY_ID_NULL) {
        ERROR("BL2 binding: CCM key unavailable for image %d\n", image_id);
        return FIH_FAILURE;
    }

    build_ad_buf(image_id, hdr, ctx->sec_cnt, ad, sizeof(ad), &ad_len);

    st = psa_aead_decrypt_setup(&op, key, PSA_ALG_CCM);
    if (st != PSA_SUCCESS) {
        goto fail;
    }
    st = psa_aead_set_lengths(&op, ad_len, body_len);
    if (st != PSA_SUCCESS) {
        goto fail;
    }
    st = psa_aead_set_nonce(&op, ctx->nonce, RSE_BIND_CCM_IV_LEN);
    if (st != PSA_SUCCESS) {
        goto fail;
    }
    st = psa_aead_update_ad(&op, ad, ad_len);
    if (st != PSA_SUCCESS) {
        goto fail;
    }

    for (i = 0; i < body_len; ) {
        chunk = MIN(sizeof(tmp), body_len - i);
        st = psa_aead_update(&op, body + i, chunk, tmp, sizeof(tmp), &out_len);
        if (st != PSA_SUCCESS) {
            ERROR("BL2 binding: CCM update failed (%d)\n", (int)st);
            goto fail;
        }
        memcpy(body + i, tmp, out_len);
        i += chunk;
    }

    st = psa_aead_verify(&op, NULL, 0, &local_tag, ctx->tag, 16);
    if (st) goto fail;

    INFO("BL2 binding: CCM decryption and authentication successful for image %d\n", image_id);
    ctx->is_authenticated = true;

    return FIH_SUCCESS;

fail:
    ERROR("BL2 binding: CCM decryption in SRAM failed (%d)\n", (int)st);
    psa_aead_abort(&op);
    return FIH_FAILURE;
}

fih_ret rse_enforce_rollback(uint8_t image_id)
{
    int rc;
    fih_int stored;
    const uint32_t img_sec_cnt = g_bind_ctx[image_id].sec_cnt;

    rc = boot_nv_security_counter_get(image_id, &stored);
    if (rc != 0) {
        ERROR("BL2 binding: security counter read failed (image %d rc=%d)", image_id, rc);
        return FIH_FAILURE;
    }

    if (img_sec_cnt < stored) {
        ERROR("BL2 binding: rollback detected (image %d image %u < nv=%u)",
                            image_id, (unsigned)img_sec_cnt, (unsigned)stored);
        return FIH_FAILURE;
    }
    return FIH_SUCCESS;
}

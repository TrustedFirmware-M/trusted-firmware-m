/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "psa/crypto.h"
#include "bootutil/image.h"
#include "bootutil/security_cnt.h"
#include "fih.h"
#include "rse_bl2_binding.h"
#include "rse_bl2_binding_util.h"
#include "flash_map/flash_map.h"
#include "tfm_log.h"

struct rse_bind_ctx g_bind_ctx[MCUBOOT_IMAGE_NUMBER];

static bool is_all_ff(const uint8_t *p, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
    if (p[i] != 0xFF) {
        return false;
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
        INFO("BL2 binding: binding TLVs are not set for image %d\n", image_id);
        return 0;
    }

    /* Verify bind state */
    if ( (meta[RSE_META_BIND_STATE_OFFSET] != RSE_BIND_STATE_BOUND) ||
         (meta[RSE_META_BIND_ALG_OFFSET] != RSE_BIND_CMAC_BOUND) ) {
        ERROR("BL2 binding: invalid binding state %u or algorithm %u\n",
              meta[RSE_META_BIND_STATE_OFFSET], meta[RSE_META_BIND_ALG_OFFSET]);
        return -1;
    }

    /* Save binding data to context */
    memcpy(ctx->meta, meta, RSE_TLV_BIND_LEN);
    memcpy(ctx->tag,  tag, RSE_TLV_BIND_LEN);
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

static int write_bind_tag(const struct flash_area *fa,
                          const struct image_header *hdr,
                          const uint8_t tag[RSE_TLV_BIND_LEN])
{
    uint32_t val_off;
    int rc;

    rc = find_unprot_tlv(fa, hdr, IMAGE_TLV_BIND_TAG, &val_off);
    if (rc) {
        return -1;
    }

    return flash_area_write(fa, val_off, tag, RSE_TLV_BIND_LEN);
}

static psa_status_t compute_cmac_tag(const struct image_header *hdr,
                                     const uint8_t *body_base,
                                     size_t body_len,
                                     uint32_t sec_cnt,
                                     psa_key_id_t key,
                                     uint8_t out_tag[RSE_TLV_BIND_LEN])
{
    uint32_t left, n;
    size_t mac_len;
    psa_status_t st;

    if (!hdr || !body_base) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (body_len < (size_t)hdr->ih_img_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_mac_operation_t op = PSA_MAC_OPERATION_INIT;
    st = psa_mac_sign_setup(&op, key, PSA_ALG_CMAC);
    if (st != PSA_SUCCESS) {
        return st;
    }

    st = psa_mac_update(&op, (const uint8_t *)&hdr->ih_hdr_size, sizeof(hdr->ih_hdr_size));
    if (st != PSA_SUCCESS) {
        goto out;
    }
    st = psa_mac_update(&op, (const uint8_t *)&hdr->ih_img_size, sizeof(hdr->ih_img_size));
    if (st != PSA_SUCCESS) {
        goto out;
    }
    st = psa_mac_update(&op, (const uint8_t *)&hdr->ih_flags,    sizeof(hdr->ih_flags));
    if (st != PSA_SUCCESS) {
        goto out;
    }
    st = psa_mac_update(&op, (const uint8_t *)&hdr->ih_load_addr,sizeof(hdr->ih_load_addr));
    if (st != PSA_SUCCESS) {
        goto out;
    }
    st = psa_mac_update(&op, (const uint8_t *)&hdr->ih_ver,      sizeof(hdr->ih_ver));
    if (st != PSA_SUCCESS) {
        goto out;
    }
    st = psa_mac_update(&op, (const uint8_t *)&sec_cnt,          sizeof(sec_cnt));
    if (st != PSA_SUCCESS) {
        goto out;
    }

   const uint8_t *body = body_base;
   left = hdr->ih_img_size;
   while (left) {
       n = left > 1024 ? 1024 : left;
       st = psa_mac_update(&op, body, n);
       if (st) {
           goto out;
       }
       body += n;
       left -= n;
   }

    st = psa_mac_sign_finish(&op, out_tag, RSE_TLV_BIND_LEN, &mac_len);
    if (st == PSA_SUCCESS && mac_len == RSE_TLV_BIND_LEN) {
        return PSA_SUCCESS;
    }
out:
    psa_mac_abort(&op);
    return PSA_ERROR_GENERIC_ERROR;
}

int rse_do_binding(uint8_t img_index,
                   const struct flash_area *fa,
                   const struct image_header *hdr)
{
    int rc;
    uint8_t tag[RSE_TLV_BIND_LEN];
    uint8_t meta[RSE_TLV_BIND_LEN];
    psa_key_id_t key;
    psa_status_t st;
    struct rse_bind_ctx *ctx = &g_bind_ctx[img_index];

    memcpy(meta, ctx->meta, RSE_TLV_BIND_LEN);

    /* Resolve device binding key */
    key = rse_get_cmac_key_for_image(img_index);
    if (key == PSA_KEY_ID_NULL) {
        ERROR("BL2 binding: CMAC key unavailable for image %d\n", img_index);
        flash_area_close(fa);
        return -1;
    }

    /* Compute CMAC tag */
    st = compute_cmac_tag(hdr, ctx->body_base, ctx->body_len, ctx->sec_cnt, key, tag);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CMAC compute failed (%d)", (int)st);
        flash_area_close(fa);
        return -1;
    }

    /* Program TAG */
    rc = write_bind_tag(fa, hdr, tag);
    if (rc) {
        ERROR("BL2 binding: tag write failed");
        flash_area_close(fa);
        return -1;
    }

    /* Update metadata state to BOUND */
    meta[RSE_META_BIND_STATE_OFFSET] = RSE_BIND_STATE_BOUND;
    meta[RSE_META_BIND_ALG_OFFSET]  = RSE_BIND_CMAC_BOUND;
    rc = write_unprot_tlv(fa, hdr, IMAGE_TLV_BIND_METADATA, meta, 16);
    if (rc) {
        ERROR("BL2 binding: metadata write failed");
        return -1;
    }
    memcpy(ctx->meta, meta, RSE_TLV_BIND_LEN);
    memcpy(ctx->tag, tag, RSE_TLV_BIND_LEN);

    flash_area_close(fa);

    return 0;
}

void rse_bind_set_ram_window(uint8_t image_id,
                             const uint8_t *body_base, size_t body_len)
{
    struct rse_bind_ctx *ctx = &g_bind_ctx[image_id];
    ctx->body_base = body_base;
    ctx->body_len  = body_len;
}

fih_ret rse_verify_binding(uint8_t img_index,
                           const struct image_header *hdr)
{
    psa_key_id_t key;
    uint8_t computed_tag[RSE_TLV_BIND_LEN];
    psa_status_t st;
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    struct rse_bind_ctx *ctx = &g_bind_ctx[img_index];

    ctx->is_authenticated = false;
    /* Resolve device binding key */
    key = rse_get_cmac_key_for_image(img_index);
    if (key == PSA_KEY_ID_NULL) {
        ERROR("BL2 binding: CMAC key unavailable for image %d\n", img_index);
        return FIH_FAILURE;
    }

    /* Compute CMAC tag */
    st = compute_cmac_tag(hdr, ctx->body_base, ctx->body_len, ctx->sec_cnt, key, computed_tag);
    if (st != PSA_SUCCESS) {
        ERROR("BL2 binding: CMAC compute failed (%d)", (int)st);
        return FIH_FAILURE;
    }

    /* Compare computed tag with stored tag */
    FIH_CALL(memcmp, fih_rc, computed_tag, ctx->tag, RSE_TLV_BIND_LEN);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 binding: tag mismatch");
        return FIH_FAILURE;
    }
    INFO("BL2 binding: tag verified for image %d\n", img_index);
    ctx->is_authenticated = true;

    return FIH_SUCCESS;
}

fih_ret rse_bind_is_authenticated(uint8_t image_id)
{
    if (g_bind_ctx[image_id].is_authenticated) {
        return FIH_SUCCESS;
    }

    return FIH_FAILURE;
}

fih_ret rse_enforce_rollback(uint8_t image_id)
{
    fih_int stored;
    uint32_t img_sec_cnt = g_bind_ctx[image_id].sec_cnt;

    int rc = boot_nv_security_counter_get(image_id, &stored);
    if (rc != 0) {
        ERROR("secctr: read failed (image %d rc=%d)", image_id, rc);
        return FIH_FAILURE;
    }

    if (img_sec_cnt < stored) {
        ERROR("secctr: rollback detected (image %d image %u < nv=%u)",
                       image_id, (unsigned)img_sec_cnt, (unsigned)stored);
        return FIH_FAILURE;
    }
    return FIH_SUCCESS;
}

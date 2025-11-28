/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "bootutil/image.h"
#include "bootutil/security_cnt.h"
#include "flash_map/flash_map.h"
#include "rse_bl2_binding_util.h"

struct __attribute__((packed)) tlv_info_le {
    uint16_t magic;
    uint16_t tlv_tot;
};

/* Compute UNPROTECTED TLV base using only the header’s protected size */
static int unprot_base(const struct flash_area *fa,
                       const struct image_header *hdr,
                       uint32_t *off_out,
                       struct tlv_info_le *info_out)
{
    uint32_t prot_off, unprot_off;
    struct tlv_info_le info;

    prot_off = hdr->ih_hdr_size + hdr->ih_img_size;
    unprot_off = prot_off + hdr->ih_protect_tlv_size;
    if (flash_area_read(fa, unprot_off, &info, sizeof(info))) {
        return -1;
    }

    if (info.magic != IMAGE_TLV_INFO_MAGIC) {
        return -1; /* 0x6907 */
    }
    *off_out  = unprot_off;
    *info_out = info;

    return 0;
}

int find_unprot_tlv(const struct flash_area *fa,
                    const struct image_header *hdr,
                    uint16_t type,
                    uint32_t *val_off_out)
{
    uint32_t base, cur, end, val;
    struct tlv_info_le info;
    struct image_tlv tlv;

    if (unprot_base(fa, hdr, &base, &info)) {
        return -1;
    }

    end = base + info.tlv_tot;
    cur = base + sizeof(info);
    while (cur + sizeof(struct image_tlv) <= end) {
        if (flash_area_read(fa, cur, &tlv, sizeof tlv)) {
            return -1;
        }
        val = cur + sizeof tlv;
        if (tlv.it_type == type) {
            *val_off_out = val;
            return 0;
        }
        cur = val + tlv.it_len;
    }
    return -1;
}

int read_unprot_tlv16(const struct flash_area *fa,
                             const struct image_header *hdr,
                             uint16_t type,
                             uint8_t *out,
                             size_t out_len)
{
    uint32_t val_off;

    if (find_unprot_tlv(fa, hdr, type, &val_off)) {
        return -1;
    }

    return flash_area_read(fa, val_off, out, out_len);
}

int read_sec_cnt(const struct flash_area *fa,
                 const struct image_header *hdr,
                 uint32_t *sec_cnt_out)
{
    struct tlv_info_le info;
    struct image_tlv tlv;
    uint32_t end, cur, val, prot_off;
    prot_off = hdr->ih_hdr_size + hdr->ih_img_size;

    if (flash_area_read(fa, prot_off, &info, sizeof info)) {
        return -1;
    }
    if (info.magic != IMAGE_TLV_PROT_INFO_MAGIC) {
        return -1;
    }
    end = prot_off + info.tlv_tot;
    cur = prot_off + sizeof info;
    while (cur + sizeof(struct image_tlv) <= end) {
        if (flash_area_read(fa, cur, &tlv, sizeof tlv)) {
            return -1;
        }

        val = cur + sizeof tlv;
        if (tlv.it_type == IMAGE_TLV_SEC_CNT && tlv.it_len == 4) {
            return flash_area_read(fa, val, sec_cnt_out, 4);
        }
        cur = val + tlv.it_len;
    }

    return -1;
}

int write_unprot_tlv(const struct flash_area *fa,
                     const struct image_header *hdr,
                     uint16_t type, const uint8_t *val,
                     size_t val_len)
{
    uint32_t val_off;

    if (find_unprot_tlv(fa, hdr, type, &val_off) == 0) {
        /* In-place update: existing TLV */
        return flash_area_write(fa, val_off, val, val_len);
    }

    /* Fallback: append a new TLV (type,len,value) at end of UNPROTECTED area */
    struct image_tlv_info info;
    uint32_t tlv_off = hdr->ih_hdr_size + hdr->ih_img_size;
    if (flash_area_read(fa, tlv_off, &info, sizeof(info))) return -3;
    if (info.it_magic != IMAGE_TLV_INFO_MAGIC) return -4;

    /* Append at end */
    uint32_t end = tlv_off + info.it_tlv_tot;
    struct image_tlv newtlv = { .it_type = type, .it_len = 16 };
    if (flash_area_write(fa, end, &newtlv, sizeof(newtlv))) return -5;
    if (flash_area_write(fa, end + sizeof(newtlv), val, val_len)) return -6;

    /* Bump total size in the TLV-info header */
    uint16_t bump = sizeof(newtlv) + val_len;
    info.it_tlv_tot += bump;
    return flash_area_write(fa, tlv_off, &info, sizeof(info));
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "image.h"

#include "Driver_Flash.h"
#include "flash_layout.h"
#include "region_defs.h"
#include "fih.h"
#ifdef TFM_BL1_2_IMAGE_BINDING
#include <string.h>
#include "tfm_log.h"
#include "util.h"
#endif /* TFM_BL1_2_IMAGE_BINDING */

#ifndef TFM_BL1_MEMORY_MAPPED_FLASH
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_BL1;
#endif /* !TFM_BL1_MEMORY_MAPPED_FLASH */

uint32_t __WEAK bl1_image_get_flash_offset(uint32_t image_id)
{
    switch (image_id) {
    case 0:
        return FLASH_AREA_0_OFFSET;
#if defined(MCUBOOT_IMAGE_NUMBER) && (MCUBOOT_IMAGE_NUMBER >= 2)
    case 1:
        return FLASH_AREA_1_OFFSET;
#endif
    default:
        FIH_PANIC;
    }
}

#ifndef TFM_BL1_MEMORY_MAPPED_FLASH
fih_ret bl1_image_copy_to_sram(uint32_t image_id, uint8_t *out)
{
    uint32_t flash_offset;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    flash_offset = bl1_image_get_flash_offset(image_id);

    fih_rc = fih_ret_encode_zero_equality(
                FIH_NOT_EQ(BL2_CODE_SIZE + BL1_2_HEADER_SIZE,
                           (FLASH_DEV_NAME_BL1.ReadData(flash_offset,
                                                        out,
                                                        BL2_CODE_SIZE + BL1_2_HEADER_SIZE))));

    FIH_RET(fih_rc);
}
#endif /* !TFM_BL1_MEMORY_MAPPED_FLASH */

#ifdef TFM_BL1_2_IMAGE_BINDING
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_BL1;

#define BL1_FLASH_MAX_SECTOR_SIZE 0x1000
static uint8_t sector_buf[BL1_FLASH_MAX_SECTOR_SIZE];

static bool is_all(const uint8_t *p, size_t n, uint8_t v)
{
    size_t i;
    for (i = 0; i < n; i++) {
        if (p[i] != v) {
            return false;
        }
    }
    return true;
}

static int program_buffer_aligned(ARM_DRIVER_FLASH *drv,
                                  uint32_t dst_addr,
                                  const uint8_t *buf,
                                  uint32_t len,
                                  uint32_t prog_unit)
{
    /* Enforce program_unit alignment for start and length */
    if ((dst_addr % prog_unit) != 0) return -1;
    if ((len % prog_unit) != 0)     return -1;

    uint32_t written = 0;
    while (written < len) {
        int32_t rc = drv->ProgramData(dst_addr + written,
                                      (void *)(buf + written),
                                      prog_unit);
        if (rc < 0 || (uint32_t)rc != prog_unit) return -1;
        written += prog_unit;
    }
    return 0;
}

fih_ret bl1_2_store_image_binding_tag(uint32_t image_id,
                                      struct bl1_2_image_t *image,
                                      const uint8_t tag[16])
{
    int rc;
    uint8_t flash_bytes[16], confirm_bytes[16];
    uint32_t sector_start, sector_end, sector_size, offset_in_sector;
    ARM_DRIVER_FLASH *flash = &FLASH_DEV_NAME_BL1;
    const ARM_FLASH_INFO *flash_info = flash->GetInfo();
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    if (!image || !tag) {
        FIH_RET(FIH_FAILURE);
    }

    if (flash_info->sector_size > BL1_FLASH_MAX_SECTOR_SIZE) {
        /* Increase BL1_FLASH_MAX_SECTOR_SIZE to platform's max sector size */
        FIH_RET(FIH_FAILURE);
    }

    /* Compute absolute flash address of the 16B binding_tag field */
    const uint32_t field_flash_off =
        bl1_image_get_flash_offset(image_id) +
        (uint32_t)offsetof(struct bl1_2_image_t, header.binding_tag);

    const uint32_t tag_len = sizeof(image->header.binding_tag);

    /* Read current on-flash bytes of the tag field */
    rc = flash->ReadData(field_flash_off, flash_bytes, tag_len);
    if (rc < 0 || (uint32_t)rc != tag_len) {
        FIH_RET(FIH_FAILURE);
    }

    /* If already the same tag, nothing to do. */
    FIH_CALL(bl_fih_memeql, fih_rc, flash_bytes, tag, tag_len);
    if (FIH_EQ(fih_rc, FIH_SUCCESS)) {
        INFO("Image binding_tag already up to date; no action taken\n");
        FIH_RET(FIH_SUCCESS);
    }

    /* Check if flash is already erased, if yes, we can directly progran */
    if (is_all(flash_bytes, tag_len, flash_info->erased_value)) {
        /* Alignment checks */
        if ((field_flash_off % flash_info->program_unit) != 0 ||
            (tag_len % flash_info->program_unit) != 0) {
            FIH_RET(FIH_FAILURE);
        }

        rc = flash->ProgramData(field_flash_off, (void *)tag, tag_len);
        if (rc < 0 || (uint32_t)rc != tag_len) {
            FIH_RET(FIH_FAILURE);
        }
        memcpy(image->header.binding_tag, tag, tag_len);
        INFO("Image binding_tag stored successfully \n");
        FIH_RET(FIH_SUCCESS);
    }

    /* Sector erase and rewrite */
    sector_size = flash_info->sector_size;
    sector_start = field_flash_off - (field_flash_off % sector_size);
    sector_end = sector_start + sector_size;
    offset_in_sector = field_flash_off - sector_start;
    /* Read entire sector into RAM buffer */
    rc = flash->ReadData(sector_start, sector_buf, sector_size);
    if (rc < 0 || (uint32_t)rc != sector_size) {
        FIH_RET(FIH_FAILURE);
    }
    /* Update binding_tag field in RAM buffer */
    memcpy(&sector_buf[offset_in_sector], tag, tag_len);

    /* Erase sector on flash */
    rc = flash->EraseSector(sector_start);
    if (rc < 0) {
        FIH_RET(FIH_FAILURE);
    }
    /* Program entire sector from RAM buffer */
    if (program_buffer_aligned(flash,
                               sector_start,
                               sector_buf,
                               sector_size,
                               flash_info->program_unit) != 0) {
        FIH_RET(FIH_FAILURE);
    }

    memcpy(image->header.binding_tag, tag, tag_len);

    /* Read from flash again to confirm */
    rc = flash->ReadData(field_flash_off, confirm_bytes, tag_len);
    if (rc < 0 || (uint32_t)rc != tag_len) {
        FIH_RET(FIH_FAILURE);
    }

    FIH_CALL(bl_fih_memeql, fih_rc, confirm_bytes, tag, tag_len);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Failed to store image binding tag \n");
        FIH_RET(FIH_FAILURE);
    }

    INFO("Image binding_tag stored successfully\n");
    return FIH_SUCCESS;
}

#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
static inline uintptr_t align_down(uintptr_t v, uintptr_t a)
{
    return v & ~(a - 1u);
}

/* Read+patch entire sector in RAM, erase original, write back from RAM. */
static int update_patch_sector_ram(ARM_DRIVER_FLASH *flash,
                                   uint32_t sector_size,
                                   uint32_t prog_unit,
                                   uintptr_t sector_base,
                                   uint32_t off_in_sector,
                                   const uint8_t *patch,
                                   size_t patch_len,
                                   uint8_t *sector_buf)
{
    size_t read;
    int rc;

    if ((sector_base % sector_size) != 0) {
        return -1;
    }
    if (off_in_sector + patch_len > sector_size) {
        return -1;
    }

    /* Read whole sector into RAM buffer (prog_unit steps) */
    read = 0;
    while (read < sector_size) {
        rc = flash->ReadData((uint32_t)(sector_base + read),
                             &sector_buf[read], prog_unit);
        if (rc != (int32_t)prog_unit) {
            return -1;
        }
        read += prog_unit;
    }

    /* Apply patch into RAM image */
    memcpy(&sector_buf[off_in_sector], patch, patch_len);

    /* Erase original sector */
    if (flash->EraseSector((uint32_t)sector_base) != ARM_DRIVER_OK) return -1;

    /* Program sector */
    if (program_buffer_aligned(flash,
                               (uint32_t)sector_base,
                               sector_buf,
                               sector_size,
                               prog_unit) != 0) {
        return -1;
    }

    return 0;
}

int bl1_2_image_flash_bind_begin(bl1_2_image_flash_bind_ctx_t *ctx,
                                 uintptr_t region_base,
                                 size_t    region_len,
                                 uint8_t  *sector_buf,
                                 size_t    sector_buf_len)
{
    ARM_DRIVER_FLASH *flash = &FLASH_DEV_NAME_BL1;
    const ARM_FLASH_INFO *flash_info = flash->GetInfo();
    if (!flash_info || flash_info->sector_size == 0 || flash_info->program_unit == 0) {
        return -1;
    }
    if (!sector_buf || sector_buf_len < flash_info->sector_size) {
        return -1;
    }

    ctx->flash       = flash;
    ctx->region_base = region_base;
    ctx->region_len  = region_len;
    ctx->cur         = region_base;
    ctx->region_end  = region_base + region_len;
    ctx->sector_size = flash_info->sector_size;
    ctx->prog_unit   = flash_info->program_unit;
    ctx->sector_buf  = sector_buf;

    return 0;
}

int bl1_2_image_flash_bind_write(bl1_2_image_flash_bind_ctx_t *ctx,
                                 const uint8_t *buf,
                                 size_t len)
{
    size_t remaining, cap_in_sec, whole, s, block, written;
    uintptr_t sec_base;
    uint32_t  off_in_sec;
    int rc;

    ARM_DRIVER_FLASH *flash = ctx->flash;
    if (ctx->cur + len > ctx->region_end) {
        return -1;
    }
    remaining = len;
    while (remaining) {
        sec_base   = align_down(ctx->cur, ctx->sector_size);
        off_in_sec = (uint32_t)(ctx->cur - sec_base);
        cap_in_sec = ctx->sector_size - off_in_sec;
        if (cap_in_sec > remaining) cap_in_sec = remaining;

        /* If not a whole sector starting at boundary → do RAM RMW for this slice */
        if (off_in_sec != 0 || cap_in_sec < ctx->sector_size) {

            rc = update_patch_sector_ram(flash, ctx->sector_size, ctx->prog_unit,
                                         sec_base, off_in_sec,
                                         buf, cap_in_sec,
                                         ctx->sector_buf);
            if (rc) {
                return -1;
            }
            ctx->cur += cap_in_sec;
            buf    += cap_in_sec;
            remaining -= cap_in_sec;
            continue;
        }

        /* Full sector(s) path */
        whole = remaining / ctx->sector_size;
        if (whole == 0) {
            /* defensive fallback */
            rc = update_patch_sector_ram(flash, ctx->sector_size, ctx->prog_unit,
                                         sec_base, 0, buf, remaining, ctx->sector_buf);
            if (rc) {
                return -1;
            }
            ctx->cur += remaining;
            buf    += remaining;
            remaining = 0;
            continue;
        }

        /* Erase each full sector and program it from buf */
        for (s = 0; s < whole; s++) {
            rc = flash->EraseSector((uint32_t)(ctx->cur + s * ctx->sector_size));
            if (rc != ARM_DRIVER_OK) {
                return -1;
            }
        }
        block = whole * ctx->sector_size;
        written = 0;
        while (written < block) {
            rc = flash->ProgramData((uint32_t)(ctx->cur + written),
                                   (void *)(buf + written),
                                   ctx->prog_unit);
            if (rc != ARM_DRIVER_OK) {
                return -1;
            }
            written += ctx->prog_unit;
        }
        ctx->cur += block;
        buf    += block;
        remaining -= block;
    }
    return 0;
}
#endif /* TFM_BL1_2_IMAGE_ENCRYPTION */
#endif /* TFM_BL1_2_IMAGE_BINDING */

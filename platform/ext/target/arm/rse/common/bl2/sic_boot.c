/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sic_boot.h"

#include "device_definition.h"
#include "bl2_image_id.h"
#include "region_defs.h"
#include "tfm_plat_otp.h"
#include "plat_def_fip_uuid.h"
#include "rse_kmu_slot_ids.h"
#if RSE_USE_HOST_FLASH
#include "host_flash_atu.h"
#endif /* RSE_USE_HOST_FLASH */

#include <string.h>

#define RSE_SIC_S_IMAGE_DECRYPT_REGION  0
#define RSE_SIC_NS_IMAGE_DECRYPT_REGION 1

#define FLASH_SIC_HTR_SIZE 0x800
#define SIC_BASE_ADDR_MASK 0xFF000000u

uint32_t s_image_offset;
uint32_t ns_image_offset;

struct rse_xip_htr_table {
    uint32_t fw_revision;
    uint32_t nonce[2];
    size_t htr_size;
    uint8_t htr[FLASH_SIC_HTR_SIZE];
};

enum sic_boot_err_t sic_boot_init(void)
{
    enum sic_error_t sic_err;

    /* The regions must be contiguous. This check is static, so will be compiled
     * out if it succeeds.
     */
    if (RSE_RUNTIME_NS_XIP_BASE_S != RSE_RUNTIME_S_XIP_BASE_S + FLASH_S_PARTITION_SIZE) {
        return SIC_BOOT_INVALID_REGION;
    }

    sic_err = sic_auth_init(&SIC_DEV_S, SIC_DIGEST_SIZE_256,
                            SIC_DIGEST_COMPARE_FIRST_QWORD,
                            RSE_RUNTIME_S_XIP_BASE_S,
                            FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_AUTH_INIT;
    }

    sic_err = sic_decrypt_init(&SIC_DEV_S, SIC_DECRYPT_KEYSIZE_256, false);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_DECR_INIT;
    }

    return SIC_BOOT_SUCCESS;
}

enum sic_boot_err_t
sic_boot_setup_auth_and_decrypt(uintptr_t sictbl,
                                uintptr_t img_addr,
                                size_t img_size,
                                uint8_t region_idx,
                                enum rse_kmu_slot_id_t key)

{
    enum sic_error_t sic_err;
    enum kmu_error_t kmu_err;
    size_t table_offset;
    uintptr_t base_addr = (img_addr & SIC_BASE_ADDR_MASK);
    struct rse_xip_htr_table *xip_table = (struct rse_xip_htr_table *)sictbl;
    size_t page_size = sic_page_size_get(&SIC_DEV_S);

    /* The first code page must be address aligned to the page size */
    if ((img_addr % page_size) != 0u) {
        return SIC_BOOT_INVALID_ALIGNMENT;
    }

    /* The image must be in SIC address space */
    if ((base_addr != SIC_HOST_BASE_NS) && (base_addr != SIC_HOST_BASE_S)) {
        return SIC_BOOT_INVALID_REGION;
    }

    if (!(img_addr + img_size > img_addr) || !(base_addr + SIC_MAPPABLE_SIZE > base_addr)) {
        return SIC_BOOT_INVALID_REGION;
    }

    /* The image must be mapped to the SIC region */
    if ((img_addr < base_addr) ||
        ((img_addr + img_size) > (base_addr + SIC_MAPPABLE_SIZE))) {
        return SIC_BOOT_INVALID_REGION; /* Image not in SIC region */
    }

    /* Calculate offset in HTR where the SICTBL is copied */
    table_offset = ((img_addr - base_addr) / page_size); /* in pages */
    table_offset *= 32u; /* digest for each page is 32bytes (256bits) */

    /* Secure I-cache HTR setup */
    sic_err = sic_auth_table_set(&SIC_DEV_S, (uint32_t *)xip_table->htr,
                                 xip_table->htr_size, table_offset);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_AUTH_SETUP;
    }

    /* Secure I-cache DR setup */
    sic_err = sic_decrypt_region_enable(&SIC_DEV_S, region_idx,
                                        img_addr, img_size,
                                        xip_table->fw_revision,
                                        xip_table->nonce, NULL);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_DECR_SETUP;
    }

    kmu_err = kmu_export_key(&KMU_DEV_S, key);
    if (kmu_err != KMU_ERROR_NONE) {
        return SIC_BOOT_ERR_DECRKEY_EX;
    }

    return SIC_BOOT_SUCCESS;
}

enum sic_boot_err_t sic_boot_enable_auth_and_decrypt(void)
{
    enum sic_error_t sic_err;

    sic_err = sic_auth_enable(&SIC_DEV_S);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_ENABLE;
    }

    sic_err = sic_enable(&SIC_DEV_S);
    if (sic_err != SIC_ERROR_NONE) {
        return SIC_BOOT_ERR_ENABLE;
    }

    return SIC_BOOT_SUCCESS;
}

#ifdef RSE_USE_HOST_FLASH
enum sic_boot_err_t sic_boot_post_load(uint32_t image_id, uint32_t image_load_offset)
{
    enum rse_kmu_slot_id_t decrypt_key_slot;
    uint32_t table;
    uint32_t decrypt_region;
    uint32_t xip_region_base_addr;
    size_t xip_region_size;
    size_t max_region_size;
    uint64_t fip_offsets[2];
    bool fip_found[2];
    uint64_t fip_offset;
    uuid_t image_uuid;
    uint32_t *image_offset;
    int rc;

    rc = host_flash_atu_get_fip_offsets(fip_found, fip_offsets);
    if (rc) {
        return SIC_BOOT_INVALID_REGION;
    }

    switch (image_id) {
    case RSE_BL2_IMAGE_NS:
        table = BL2_XIP_TABLES_START + FLASH_SIC_TABLE_SIZE + BL2_HEADER_SIZE;

        if (image_load_offset >= FLASH_AREA_11_OFFSET
            && image_load_offset < FLASH_AREA_11_OFFSET + FLASH_AREA_11_SIZE) {
            if (fip_found[0]) {
                fip_offset = fip_offsets[0];
            } else {
                return SIC_BOOT_INVALID_REGION;
            }
        } else if (image_load_offset >= FLASH_AREA_13_OFFSET
                   && image_load_offset < FLASH_AREA_13_OFFSET + FLASH_AREA_13_SIZE) {
            if (fip_found[1]) {
                fip_offset = fip_offsets[1];
            } else {
                return SIC_BOOT_INVALID_REGION;
            }
        } else {
            return SIC_BOOT_INVALID_REGION;
        }

        decrypt_key_slot = RSE_KMU_SLOT_NON_SECURE_SIC_ENCRYPTION_KEY;
        decrypt_region = RSE_SIC_NS_IMAGE_DECRYPT_REGION;
        xip_region_base_addr = RSE_RUNTIME_NS_XIP_BASE_NS;
        max_region_size = NS_CODE_SIZE;
        image_uuid = UUID_RSE_FIRMWARE_NS;
        image_offset = &ns_image_offset;

        break;
    case RSE_BL2_IMAGE_S:
        table = BL2_XIP_TABLES_START + BL2_HEADER_SIZE;

        if (image_load_offset >= FLASH_AREA_10_OFFSET
            && image_load_offset < FLASH_AREA_10_OFFSET + FLASH_AREA_10_SIZE) {
            fip_offset = fip_offsets[0];
        } else if (image_load_offset >= FLASH_AREA_12_OFFSET
            && image_load_offset < FLASH_AREA_12_OFFSET + FLASH_AREA_12_SIZE) {
            fip_offset = fip_offsets[1];
        } else {
            return SIC_BOOT_INVALID_REGION;
        }

        decrypt_key_slot = RSE_KMU_SLOT_SECURE_SIC_ENCRYPTION_KEY;
        decrypt_region = RSE_SIC_S_IMAGE_DECRYPT_REGION;
        xip_region_base_addr = RSE_RUNTIME_S_XIP_BASE_S;
        max_region_size = S_CODE_SIZE;
        image_uuid = UUID_RSE_FIRMWARE_S;
        image_offset = &s_image_offset;

        break;

    case RSE_BL2_IMAGE_AP:
    case RSE_BL2_IMAGE_SCP:
        return SIC_BOOT_SUCCESS;
    default:
        return SIC_BOOT_INVALID_REGION;
    }

    rc = host_flash_atu_setup_image_input_slots_from_fip(fip_offset,
                                                         xip_region_base_addr,
                                                         image_uuid,
                                                         image_offset,
                                                         &xip_region_size);
    if (rc) {
        return SIC_BOOT_INVALID_REGION;
    }

    /* RSE XIP images must be aligned to, at minimum, the SIC authentication
     * page size and the SIC decrypt page size. Alignments that do not match
     * the ATU page size cause problems in jumping to NS code, and seem to
     * cause startup failure in some cases, so 8KiB alignment is required.
     */
    if (*image_offset % 0x1000 != 0) {
        return SIC_BOOT_INVALID_ALIGNMENT;
    }

    if (xip_region_size > max_region_size) {
        return SIC_BOOT_INVALID_REGION;
    }


    return sic_boot_setup_auth_and_decrypt(table,
                                           xip_region_base_addr,
                                           xip_region_size,
                                           decrypt_region,
                                           decrypt_key_slot);
}

enum sic_boot_err_t sic_boot_pre_quit(struct boot_arm_vector_table **vt_cpy)
{
    enum sic_boot_err_t sic_err;

    sic_err = sic_boot_enable_auth_and_decrypt();
    if (sic_err != SIC_BOOT_SUCCESS) {
        return sic_err;
    }

    *vt_cpy = (struct boot_arm_vector_table *)(RSE_RUNTIME_S_XIP_BASE_S + s_image_offset);

    return SIC_BOOT_SUCCESS;
}

#endif /* RSE_USE_HOST_FLASH */

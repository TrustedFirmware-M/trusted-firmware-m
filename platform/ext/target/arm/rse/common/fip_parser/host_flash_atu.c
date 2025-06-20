/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "host_flash_atu.h"

#include "flash_layout.h"
#include "device_definition.h"
#include "atu_config.h"
#include "atu_rse_lib.h"
#include "fip_parser.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "tfm_plat_defs.h"
#ifdef RSE_GPT_SUPPORT
#include "plat_def_fip_uuid.h"
#include "fwu_metadata.h"
#include "platform_regs.h"
#endif /* RSE_GPT_SUPPORT */

#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
#include "staging_config.h"
#endif /* RSE_BL2_ENABLE_IMAGE_STAGING */
#include <string.h>

/* Flash device names must be specified by target */
#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
extern ARM_DRIVER_FLASH ram_driver;
#define IMAGE_INPUT_FLASH_DRIVER ram_driver
#define IMAGE_INPUT_FLASH_BASE_ADDRESS 0
#define IMAGE_INPUT_BASE_PHYSICAL STAGING_AREA_FIP_A_BASE_S_PHYSICAL
#else
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;
#define IMAGE_INPUT_FLASH_DRIVER FLASH_DEV_NAME
#define IMAGE_INPUT_FLASH_BASE_ADDRESS FLASH_BASE_ADDRESS
#define IMAGE_INPUT_BASE_PHYSICAL HOST_FLASH0_BASE
#endif /* RSE_BL2_ENABLE_IMAGE_STAGING */

static inline uint32_t round_down(uint32_t num, uint32_t boundary)
{
    return num - (num % boundary);
}

static inline uint32_t round_up(uint32_t num, uint32_t boundary)
{
    return (num + boundary - 1) - ((num + boundary - 1) % boundary);
}

enum tfm_plat_err_t setup_aligned_atu_slot(uint64_t physical_address, uint32_t size,
                                                  uint32_t boundary,
                                                  uint32_t logical_address,
                                                  uint32_t *alignment_offset,
                                                  size_t   *atu_slot_size)
{
    uint64_t aligned_physical_address;
    enum atu_error_t atu_err;

    if (alignment_offset == NULL || atu_slot_size == NULL) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_ATU_SLOT_INVALID_INPUT;
    }

    aligned_physical_address = round_down(physical_address, boundary);
    *atu_slot_size = round_up(physical_address + size, boundary)
                     - aligned_physical_address;

    *alignment_offset = physical_address - aligned_physical_address;

    /* Sanity check our parameters, as we do _not_ trust them. We can only map
     * within the host flash, the parameters must not overflow, and we cannot
     * map further than the bounds of the logical address slot.
     */
    if (aligned_physical_address < IMAGE_INPUT_BASE_PHYSICAL
        || aligned_physical_address + *atu_slot_size > IMAGE_INPUT_BASE_PHYSICAL + HOST_FLASH0_SIZE
        || aligned_physical_address + *atu_slot_size < aligned_physical_address
        || aligned_physical_address + *atu_slot_size < *atu_slot_size
        || *atu_slot_size > HOST_IMAGE_MAX_SIZE
        || *alignment_offset > boundary) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_ATU_SLOT_INVALID_INPUT;
    }

    /* If the region is used (e.g BL2 mapped the previous image earlier), clear it first */
    (void) atu_rse_free_addr(&ATU_DEV_S, logical_address);
    /* Initialize ATU header region */
    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, aligned_physical_address, logical_address,
                                           *atu_slot_size, ATU_ENCODE_ATTRIBUTES_SECURE_PAS);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

int host_flash_atu_setup_image_input_slots_from_fip(uint64_t fip_offset,
                                                    uintptr_t logical_address,
                                                    uuid_t image_uuid,
                                                    uint32_t *logical_address_offset,
                                                    size_t *slot_size)
{
    enum tfm_plat_err_t plat_err;
    enum atu_error_t atu_err;
    uint64_t region_offset;
    size_t region_size;
    uint64_t physical_address = IMAGE_INPUT_BASE_PHYSICAL + fip_offset;
    uint32_t alignment_offset;
    size_t atu_slot_size;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);

    /* There's no way to tell how big the FIP TOC will be before reading it, so
     * we just map 0x1000.
     */
    plat_err = setup_aligned_atu_slot(physical_address, 0x1000, page_size,
                                      HOST_FLASH0_TEMP_BASE_S, &alignment_offset,
                                      &atu_slot_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = fip_get_entry_by_uuid(&IMAGE_INPUT_FLASH_DRIVER,
                HOST_FLASH0_TEMP_BASE_S - IMAGE_INPUT_FLASH_BASE_ADDRESS + alignment_offset,
                atu_slot_size - alignment_offset,
                image_uuid, &region_offset, &region_size);

    /* Free the temporary region even if the entry is not found */
    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_TEMP_BASE_S);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Initialize primary input region */
    plat_err = setup_aligned_atu_slot(physical_address + region_offset, region_size,
                                      page_size, logical_address,
                                      &alignment_offset, &atu_slot_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (logical_address_offset != NULL) {
        *logical_address_offset = alignment_offset;
    }
    if (slot_size != NULL) {
        *slot_size = atu_slot_size;
    }

    return 0;
}

#ifdef RSE_GPT_SUPPORT
int host_flash_atu_get_gpt_header(gpt_header_t *header)
{
    enum tfm_plat_err_t plat_err;
    enum atu_error_t atu_err;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);
    uint64_t physical_address;
    uint32_t alignment_offset;
    size_t atu_slot_size;

    physical_address = IMAGE_INPUT_BASE_PHYSICAL + FLASH_LBA_SIZE;
    plat_err = setup_aligned_atu_slot(physical_address, FLASH_LBA_SIZE,
                                      page_size,
                                      HOST_FLASH0_TEMP_BASE_S, &alignment_offset,
                                      &atu_slot_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = gpt_get_header(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                              atu_slot_size - alignment_offset, header);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_TEMP_BASE_S);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return 0;
}

static int
    host_flash_atu_get_fip_and_metadata_offsets(bool fip_found[2],
                                                uint64_t fip_offsets[2],
                                                bool metadata_found[2],
                                                uint64_t metadata_offsets[2],
                                                bool private_metadata_found[1],
                                                uint64_t private_metadata_offsets[1])
{
    int rc;
    enum tfm_plat_err_t plat_err;
    enum atu_error_t atu_err;
    gpt_header_t header;
    gpt_entry_t entry;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);
    uint64_t physical_address;
    uint32_t alignment_offset;
    size_t atu_slot_size;

    rc = host_flash_atu_get_gpt_header(&header);
    if (rc) {
        return rc;
    }

    physical_address = IMAGE_INPUT_BASE_PHYSICAL
                       + header.list_lba * FLASH_LBA_SIZE;
    plat_err = setup_aligned_atu_slot(physical_address,
                                      header.list_entry_size * header.list_num, page_size,
                                      HOST_FLASH0_TEMP_BASE_S, &alignment_offset,
                                      &atu_slot_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = gpt_get_list_entry_by_name(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num, header.list_entry_size,
                                          PRIMARY_FIP_GPT_NAME,
                                          sizeof(PRIMARY_FIP_GPT_NAME),
                                          atu_slot_size - alignment_offset, &entry);
    if (plat_err == TFM_PLAT_ERR_SUCCESS) {
        fip_found[0] = true;
        fip_offsets[0] = entry.first_lba * FLASH_LBA_SIZE;
    } else {
        fip_found[0] = false;
    }

    plat_err = gpt_get_list_entry_by_name(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num, header.list_entry_size,
                                          SECONDARY_FIP_GPT_NAME,
                                          sizeof(SECONDARY_FIP_GPT_NAME),
                                          atu_slot_size - alignment_offset, &entry);
    if (plat_err == TFM_PLAT_ERR_SUCCESS) {
        fip_found[1] = true;
        fip_offsets[1] = entry.first_lba * FLASH_LBA_SIZE;
    } else {
        fip_found[1] = false;
    }

    plat_err = gpt_get_list_entry_by_name(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num, header.list_entry_size,
                                          FWU_METADATA_GPT_NAME,
                                          sizeof(FWU_METADATA_GPT_NAME),
                                          atu_slot_size - alignment_offset, &entry);
    if (plat_err == TFM_PLAT_ERR_SUCCESS) {
        metadata_found[0] = true;
        metadata_offsets[0] = entry.first_lba * FLASH_LBA_SIZE;
    } else {
        metadata_found[0] = false;
    }

    plat_err = gpt_get_list_entry_by_name(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num, header.list_entry_size,
                                          FWU_BK_METADATA_GPT_NAME,
                                          sizeof(FWU_BK_METADATA_GPT_NAME),
                                          atu_slot_size - alignment_offset, &entry);
    if (plat_err == TFM_PLAT_ERR_SUCCESS) {
        metadata_found[1] = true;
        metadata_offsets[1] = entry.first_lba * FLASH_LBA_SIZE;
    } else {
        metadata_found[1] = false;
    }

    plat_err = gpt_get_list_entry_by_name(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num, header.list_entry_size,
                                          FWU_PRIVATE_METADATA_1_GPT_NAME,
                                          sizeof(FWU_PRIVATE_METADATA_1_GPT_NAME),
                                          atu_slot_size - alignment_offset, &entry);
    if (plat_err == TFM_PLAT_ERR_SUCCESS) {
        private_metadata_found[0] = true;
        private_metadata_offsets[0] = entry.first_lba * FLASH_LBA_SIZE;
    } else {
        private_metadata_found[0] = false;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_TEMP_BASE_S);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return 0;
}

static bool plat_check_if_prev_boot_failed(void)
{
    return ((tfm_hal_get_reset_syndrome() & (1u << RSE_SWSYN_FAILED_BOOT_BIT_POS)) != 0);
}
#endif /* RSE_GPT_SUPPORT */


int host_flash_atu_get_fip_offsets(bool fip_found[2], uint64_t fip_offsets[2])
{
#ifdef RSE_GPT_SUPPORT
    int rc;
    bool metadata_found[2];
    uint64_t metadata_offsets[2];
    bool private_metadata_found[1];
    uint64_t private_metadata_offsets[1];
    uint8_t bootable_fip_index;
    uint64_t found_metadata_offset;
    bool increment_failed_boot = false;

    rc = host_flash_atu_get_fip_and_metadata_offsets(fip_found, fip_offsets,
                                                     metadata_found, metadata_offsets,
                                                     private_metadata_found,
                                                     private_metadata_offsets);
    if (rc) {
        return rc;
    }

    if (!private_metadata_found[0]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_PRIVATE_METADATA_FOUND;
    }

    if (!metadata_found[0] && !metadata_found[1]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_METADATA_FOUND;
    }

    found_metadata_offset = (metadata_found[0]) ?
                             metadata_offsets[0] : metadata_offsets[1];


    rc = get_active_index(found_metadata_offset,
                          &bootable_fip_index,
                          NULL);
    if (rc) {
        return rc;
    }

    if (!fip_found[bootable_fip_index]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_FIP_FOUND;
    }
    /* MCUBoot requires that we map both regions. If we can only have the offset
     * of one, then map it to both slots.
     */
    if (bootable_fip_index == 0) {
        /* Boot from fip #0, map it to other slot as well */
        fip_offsets[1] = fip_offsets[0];
    } else {
        /* Boot from fip #1, map it to other slot as well */
        fip_offsets[0] = fip_offsets[1];
    }

#else
    fip_found[0] = true;
    fip_offsets[0] = FLASH_FIP_A_OFFSET;
    fip_found[1] = true;
    fip_offsets[1] = FLASH_FIP_B_OFFSET;
#endif /* RSE_GPT_SUPPORT */

    return 0;
}

int host_flash_atu_setup_image_input_slots(uuid_t image_uuid, uint32_t offsets[2])
{
    int rc;
    bool fip_found[2];
    uint64_t fip_offsets[2];
    bool fip_mapped[2] = {false};

    rc = host_flash_atu_get_fip_offsets(fip_found, fip_offsets);
    if (rc) {
        return rc;
    }

    rc = host_flash_atu_setup_image_input_slots_from_fip(fip_offsets[0],
                                          HOST_FLASH0_IMAGE0_BASE_S, image_uuid,
                                          &offsets[0], NULL);
    if (rc == 0) {
        fip_mapped[0] = true;
    }

    rc = host_flash_atu_setup_image_input_slots_from_fip(fip_offsets[1],
                                          HOST_FLASH0_IMAGE1_BASE_S, image_uuid,
                                          &offsets[1], NULL);
    if (rc == 0) {
        fip_mapped[1] = true;
    }


    /* If one of the mappings failed (more common without GPT support since in
     * that case we're just hoping there's a FIP at the offset) then map the
     * other one into the slot. At this stage if a backup map fails then it's an
     * error since otherwise MCUBoot will attempt to access unmapped ATU space
     * and fault.
     */
    if (fip_mapped[0] && !fip_mapped[1]) {
        rc = host_flash_atu_setup_image_input_slots_from_fip(fip_offsets[0],
                                              HOST_FLASH0_IMAGE1_BASE_S,
                                              image_uuid, &offsets[1], NULL);
        if (rc) {
            return rc;
        }
    } else if (fip_mapped[1] && !fip_mapped[0]) {
        rc = host_flash_atu_setup_image_input_slots_from_fip(fip_offsets[1],
                                              HOST_FLASH0_IMAGE0_BASE_S,
                                              image_uuid, &offsets[0], NULL);
        if (rc) {
            return rc;
        }
    } else if (!fip_mapped[0] && !fip_mapped[1]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_FIP_MAPPED;
    }

    return 0;
}

int host_flash_atu_setup_image_output_slots(uint64_t image_load_phy_addr,
                                            uint32_t image_load_logical_addr,
                                            uint32_t image_max_size,
                                            uint64_t header_phy_addr)
{
    enum atu_error_t atu_err;

    if (image_max_size < HOST_IMAGE_HEADER_SIZE) {
        return -1;
    }

    /* Initialize ATU header region */
    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, header_phy_addr, image_load_logical_addr,
                                           HOST_IMAGE_HEADER_SIZE, ATU_ENCODE_ATTRIBUTES_SECURE_PAS);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    /* Initialize ATU output region */
    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, image_load_phy_addr,
                                           image_load_logical_addr + HOST_IMAGE_HEADER_SIZE,
                                           image_max_size - HOST_IMAGE_HEADER_SIZE,
                                           ATU_ENCODE_ATTRIBUTES_SECURE_PAS);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return 0;
}

#ifdef RSE_GPT_SUPPORT
int host_flash_atu_get_gpt_partition_offset_by_image_uuid(uuid_t image_uuid,
                                                          gpt_header_t header,
                                                          bool *image_found,
                                                          uint64_t *image_offset,
                                                          uint32_t *image_size)
{
    uint64_t physical_address;
    uint32_t rc;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);
    uint32_t alignment_offset;
    size_t atu_slot_size;
    gpt_entry_t entry;

    if (image_found == NULL || image_offset == NULL || image_size == NULL) {
        return -1;
    }

    physical_address = IMAGE_INPUT_BASE_PHYSICAL +
                       (header.list_lba * FLASH_LBA_SIZE);
    rc = setup_aligned_atu_slot(physical_address,
                                header.list_entry_size * header.list_num,
                                page_size,
                                HOST_FLASH0_TEMP_BASE_S,
                                &alignment_offset,
                                &atu_slot_size);
    if (rc != TFM_PLAT_ERR_SUCCESS) {
        return rc;
    }

    rc = gpt_get_list_entry_by_image_uuid(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num,
                                          header.list_entry_size,
                                          image_uuid,
                                          atu_slot_size - alignment_offset,
                                          &entry);
    if (rc == TFM_PLAT_ERR_SUCCESS) {
        *image_found = true;
        *image_offset = entry.first_lba * FLASH_LBA_SIZE;
        *image_size = (entry.last_lba - entry.first_lba + 1) * FLASH_LBA_SIZE;
    } else {
        *image_found = false;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_TEMP_BASE_S);
    if (rc != ATU_ERR_NONE) {
        return rc;
    }

    return 0;
}

int host_flash_atu_get_gpt_partition_offset_by_type_uuid(uuid_t type_uuid,
                                                         gpt_header_t header,
                                                         bool *image_found,
                                                         uint64_t *image_offset,
                                                         size_t *image_size)
{
    uint64_t physical_address;
    uint32_t rc;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);
    uint32_t alignment_offset;
    size_t atu_slot_size;
    gpt_entry_t entries[2];
    uint8_t idx;

    if (image_found == NULL || image_offset == NULL || image_size == NULL) {
        return -1;
    }

    physical_address = IMAGE_INPUT_BASE_PHYSICAL +
                       (header.list_lba * FLASH_LBA_SIZE);
    rc = setup_aligned_atu_slot(physical_address,
                                header.list_entry_size * header.list_num,
                                page_size,
                                HOST_FLASH0_TEMP_BASE_S,
                                &alignment_offset,
                                &atu_slot_size);
    if (rc != TFM_PLAT_ERR_SUCCESS) {
        return rc;
    }

    for (idx = 0; idx < 2; idx++) {
        image_found[idx] = false;
    }

    rc = gpt_get_list_entry_by_type_uuid(HOST_FLASH0_TEMP_BASE_S + alignment_offset,
                                          header.list_num,
                                          header.list_entry_size,
                                          type_uuid,
                                          atu_slot_size - alignment_offset,
                                          entries);
    if (rc == TFM_PLAT_ERR_SUCCESS) {
        for (idx = 0; idx < 2; idx++) {
            if (!memcmp(&(entries[idx].type_uuid), &(type_uuid), sizeof(type_uuid))) {
                image_found[idx] = true;
                image_offset[idx] = entries[idx].first_lba * FLASH_LBA_SIZE;
                image_size[idx] = (entries[idx].last_lba - entries[idx].first_lba + 1) * FLASH_LBA_SIZE;
            }
        }
    }

    rc = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_TEMP_BASE_S);
    if (rc != ATU_ERR_NONE) {
        return rc;
    }

    return 0;
}
#endif /* RSE_GPT_SUPPORT */

int host_flash_atu_get_image_offsets_by_type_uuid(uuid_t type_uuid, uint64_t *image_offset, uint32_t *image_size)
{
#ifdef RSE_GPT_SUPPORT
    int rc = 0;
    gpt_header_t header;
    bool metadata_found[2];
    uint64_t metadata_offsets[2];
    bool private_metadata_found[2];
    uint64_t private_metadata_offsets[2];
    uint8_t bootable_img_index;
    bool increment_failed_boot = false;
    uint64_t found_metadata_offset;
    size_t temp_size[2];
    uuid_t image_uuid;
    bool image_found = false;

    if (image_offset == NULL || image_size == NULL){
        return -1;
    }

    rc = host_flash_atu_get_gpt_header(&header);
    if (rc) {
        return rc;
    }

    rc = host_flash_atu_get_gpt_partition_offset_by_type_uuid(UUID_RSE_METADATA,
                                                              header,
                                                              metadata_found,
                                                              metadata_offsets,
                                                              temp_size);
    if (rc) {
        return rc;
    }

    rc = host_flash_atu_get_gpt_partition_offset_by_type_uuid(UUID_RSE_PRIVATE_METADATA,
                                                              header,
                                                              private_metadata_found,
                                                              private_metadata_offsets,
                                                              temp_size);
    if (rc) {
        return rc;
    }

    if (!private_metadata_found[0]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_PRIVATE_METADATA_FOUND;
    }

    if (!metadata_found[0] && !metadata_found[1]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_METADATA_FOUND;
    }

    found_metadata_offset = (metadata_found[0]) ?
                             metadata_offsets[0] : metadata_offsets[1];

    rc = get_active_index(found_metadata_offset,
                          &bootable_img_index,
                          NULL);
    if (rc) {
        return rc;
    }

    rc = get_active_image_uuid_by_type_uuid(found_metadata_offset,
                                            type_uuid,
                                            &image_uuid);
    if (rc) {
        return rc;
    }

    rc = host_flash_atu_get_gpt_partition_offset_by_image_uuid(image_uuid,
                                                               header,
                                                               &image_found,
                                                               image_offset,
                                                               image_size);
    if (rc) {
        return rc;
    }

    return 0;
#else
    return -1;
#endif /* RSE_GPT_SUPPORT */
}

int host_flash_atu_setup_image_input_slots_by_type_uuid(uuid_t type_uuid, uint32_t offsets[2])
{
    int rc;
    size_t temp_size[2];
    uint64_t gpt_offset = 0;
    uint32_t image_size = 0;
    size_t page_size = atu_rse_get_page_size(&ATU_DEV_S);
    bool image_mapped[2] = {false};

    if (offsets == NULL) {
        return -1;
    }

    rc = host_flash_atu_get_image_offsets_by_type_uuid(type_uuid, &gpt_offset, &image_size);
    if (rc != 0) {
        return -1;
    }

    rc = setup_aligned_atu_slot(gpt_offset + IMAGE_INPUT_BASE_PHYSICAL, image_size,
                                page_size, HOST_FLASH0_IMAGE0_BASE_S,
                                &offsets[0], &temp_size[0]);
    if (rc == 0) {
        image_mapped[0] = true;
    }
    rc = setup_aligned_atu_slot(gpt_offset + IMAGE_INPUT_BASE_PHYSICAL, image_size,
                                      page_size, HOST_FLASH0_IMAGE1_BASE_S,
                                      &offsets[1], &temp_size[0]);
    if (rc == 0) {
        image_mapped[1] = true;
    }

    if (!image_mapped[0] && !image_mapped[1]) {
        return TFM_PLAT_ERR_HOST_FLASH_SETUP_IMAGE_SLOT_NO_FIP_MAPPED;
    }

    return 0;
}

int host_flash_atu_free_input_image_regions(void)
{
    enum atu_error_t atu_err;

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_IMAGE0_BASE_S);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_FLASH0_IMAGE1_BASE_S);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return 0;
}

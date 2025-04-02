/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fwu_metadata.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "atu_rse_drv.h"
#include "cmsis_compiler.h"
#include "device_definition.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "fwu_config.h"
#include "gpt.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "soft_crc.h"

#define RSE_ATU_REGION_TEMP_SLOT           2
#define BANK_INVALID    0xffu  /* One or more images corrupted or partially written */
#define BANK_VALID      0xfeu  /* Valid images, but some are in unaccepted state */
#define BANK_ACCEPTED   0xfcu  /* All images valid and accepted */

#ifndef METADATA_SIZE
#define METADATA_SIZE   FLASH_LBA_SIZE
#endif

#define PRIVATE_METADATA_SIZE   FLASH_LBA_SIZE

#define METADATA_REGION_SIZE            0x2000
#define PRIVATE_METADATA_REGION_SIZE    0x2000

#define FW_STORE_DESC_SIZE              0x8
#define IMAGE_ENTRY_SIZE                0x20
#define IMAGE_PROPERTIES_SIZE           0x18
#ifndef METADATA_NR_OF_BANKS
#define METADATA_NR_OF_BANKS            2
#endif
#ifndef METADATA_NR_OF_IMAGES
#define METADATA_NR_OF_IMAGES           2
#endif
#define IMAGE_ENTRIES_SIZE              (IMAGE_ENTRY_SIZE + (METADATA_NR_OF_BANKS * IMAGE_PROPERTIES_SIZE))

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

/* DEN0118 Metadata version 2 */
struct image_properties_t {
    uuid_t img_uuid;    /* UUID of the image in bank */
    uint32_t accepted;  /* Acceptance status */
    uint32_t reserved;
} __PACKED;

struct image_entry_t {
    uuid_t img_type_uuid; /* UUID identifying the image type */
    uuid_t location_uuid; /* UUID of the storage volume where the image is located */
    struct image_properties_t img_bank_info[METADATA_NR_OF_BANKS];
} __PACKED;

struct metadata_fw_store_desc_t {
   uint8_t num_banks;             /* Number of firmware banks */
   uint8_t reserved;              /* Reserved */
   uint16_t num_images;           /* Number of entries in the img_entry array */
   uint16_t img_entry_size;       /* Size in bytes of the fwu_image_entry */
   uint16_t bank_info_entry_size; /* Size of image bank info structure in bytes */
   struct image_entry_t img_entry[METADATA_NR_OF_IMAGES]; /* Image entries */
} __PACKED;

struct metadata_header_t {
    uint32_t crc_32;        /* Metadata crc value */
    uint32_t version;       /* Metadata version, must be 2 for this type */
    uint32_t active_index;  /* Bank index from which device boots   */
    uint32_t previous_active_index; /* Previous successfully booted bank index */
    uint32_t metadata_size; /* Size in bytes of complete metadata structure */
    uint16_t descriptor_offset; /* The offset, from the start of this data structure,
                                 * where the fw_store_desc starts (if one exists).
                                 * If the fw_store_desc does not exist, then this
                                 * field must be set to 0.
                                 */
    uint16_t reserved1;
    uint8_t bank_state[4];  /* The state of each bank */
    uint32_t reserved2;
    /* OPTIONAL fw_store_desc: not used */
} __PACKED;

struct fwu_private_metadata_t {
    uint32_t failed_boot_count; /* Counter tracking number of failed boots */
    uint32_t nv_counter[FWU_BANK_COUNT]; /* Staged nv counter; before written to OTP */
} __PACKED;

/* Valid entries for data item width */
static const uint32_t data_width_byte[] = {
    sizeof(uint8_t),
    sizeof(uint16_t),
    sizeof(uint32_t),
};

static int read_entire_region_from_host_flash(uint64_t offset,
                                              uint32_t region_size,
                                              uint8_t *data_buf)
{
    int rc;
    enum atu_error_t atu_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;

    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    if ((region_size / data_width) > (UINT32_MAX - offset)) {
        return -1;
    }

    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_REGION_TEMP_SLOT,
                                    log_addr,
                                    physical_address,
                                    region_size);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Read entire metadata */
    rc = FLASH_DEV_NAME.ReadData(log_addr - FLASH_BASE_ADDRESS, (void *)data_buf,
                                 METADATA_SIZE / data_width);
    if (rc != (METADATA_SIZE / data_width)) {
        return -1;
    }

    atu_err = atu_uninitialize_region(&ATU_DEV_S,
                                      RSE_ATU_REGION_TEMP_SLOT);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

static int read_from_host_flash(uint64_t offset,
                                uint32_t block_size,
                                uint8_t *data_buf)
{
    int rc;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;

    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    /* Read entire metadata */
    rc = FLASH_DEV_NAME.ReadData(log_addr - FLASH_BASE_ADDRESS + offset, (void *)data_buf,
                                 block_size / data_width);
    if (rc != (block_size / data_width)) {
        return -1;
    }

    return 0;
}

static int read_fwu_metadadata(struct metadata_header_t *md_header,
                               uint8_t *metadata,
                               uint64_t offset)
{
    int rc;

    rc = read_entire_region_from_host_flash(offset,
                                            METADATA_REGION_SIZE,
                                            metadata);
    if (rc != 0) {
        return rc;
    }

    /* Header is at the beginning of the metadata */
    memcpy(md_header, metadata, sizeof(struct metadata_header_t));

    return 0;
}

static int read_fwu_private_metadadata(
                                struct fwu_private_metadata_t *private_metadata,
                                uint8_t *private_metadata_buf,
                                uint64_t offset)
{
    int rc;

    rc = read_entire_region_from_host_flash(offset,
                                            PRIVATE_METADATA_REGION_SIZE,
                                            private_metadata_buf);
    if (rc != 0) {
        return rc;
    }

    memcpy(private_metadata, private_metadata_buf,
           sizeof(struct fwu_private_metadata_t));

    return 0;
}

static int write_fwu_private_metadadata(
                                struct fwu_private_metadata_t *private_metadata,
                                uint64_t offset)
{

    int rc;
    enum atu_error_t atu_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;

    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    if ((offset + PRIVATE_METADATA_REGION_SIZE) > HOST_FLASH0_SIZE) {
        return -1;
    }

    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_REGION_TEMP_SLOT,
                                    log_addr,
                                    physical_address,
                                    PRIVATE_METADATA_REGION_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    rc = FLASH_DEV_NAME.EraseSector(log_addr - FLASH_BASE_ADDRESS);
    if (rc != ARM_DRIVER_OK) {
        return -1;
    }

    /* Write private metadata */
    rc = FLASH_DEV_NAME.ProgramData(log_addr - FLASH_BASE_ADDRESS,
                                    (void *)private_metadata,
                                    sizeof(*private_metadata));
    if (rc < 0 || rc != sizeof(*private_metadata)) {
        return -1;
    }

    atu_err = atu_uninitialize_region(&ATU_DEV_S,
                                      RSE_ATU_REGION_TEMP_SLOT);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

int parse_fwu_metadata(uint64_t md_offset,
                       uint64_t private_md_offset,
                       bool increment_failed_boot,
                       uint8_t *boot_index)
{
    int rc;
    struct metadata_header_t metadata_header;
    struct fwu_private_metadata_t private_md;
    static uint8_t metadata[METADATA_SIZE];
    static uint8_t private_metadata[PRIVATE_METADATA_SIZE];
    uint32_t calc_crc, active_index, previous_active_index;

    rc = read_fwu_metadadata(&metadata_header,
                             metadata,
                             md_offset);
    if (rc != 0) {
        return -1;
    }

    /* DEN0118 A3.2.4 Metadata Integrity check for version 2 */
    calc_crc = crc32((const uint32_t *)&metadata[sizeof(metadata_header.crc_32)],
                     metadata_header.metadata_size - sizeof(metadata_header.crc_32));

    if (metadata_header.crc_32 != calc_crc) {
        return -1;
    }

    active_index = metadata_header.active_index;
    if (active_index >= FWU_BANK_COUNT) {
        return -1;
    }

    previous_active_index = metadata_header.previous_active_index;
    if (previous_active_index >= FWU_BANK_COUNT) {
        return -1;
    }

    /* Read private metadata */
    rc = read_fwu_private_metadadata(&private_md,
                                     private_metadata,
                                     private_md_offset);
    if (rc != 0) {
        return -1;
    }

    if (increment_failed_boot) {
        /* Increment and update failed boot count in private metadata */
        private_md.failed_boot_count++;
        rc = write_fwu_private_metadadata(&private_md, private_md_offset);
        if (rc != 0) {
            return -1;
        }
    }

    if ((private_md.failed_boot_count < FWU_MAX_FAILED_BOOT) &&
        ((metadata_header.bank_state[active_index] == BANK_VALID) ||
         (metadata_header.bank_state[active_index] == BANK_ACCEPTED))) {
        /* Images should load from current bank */
        *boot_index = active_index;

    } else if ((active_index != previous_active_index) &&
               ((metadata_header.bank_state[previous_active_index] == BANK_VALID) ||
                (metadata_header.bank_state[previous_active_index] == BANK_ACCEPTED))) {
        /* Boot from previous active bank */
        *boot_index = previous_active_index;

    } else {
        //TODO: One or more images corrupted or partially written
        return -1;
    }

    return 0;
}

int get_active_image_uuid_by_type_uuid(uint64_t md_offset,
                                       uuid_t type_uuid,
                                       uuid_t *image_uuid) {
    static uint8_t metadata[METADATA_SIZE];
    struct metadata_header_t metadata_header;
    struct metadata_fw_store_desc_t fw_store_desc;

    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + md_offset;
    int rc = 0;
    int idx = 0;

    if (image_uuid == NULL) {
        return -1;
    }

    rc = read_fwu_metadadata(&metadata_header,
                             metadata,
                             md_offset);
    if (rc != 0) {
        return -1;
    }
    /* WORKAROUND: Init ATU region over metadata, removed from read_from_host_flash
                   until aligned access is implemented */
    rc = atu_initialize_region(&ATU_DEV_S,
                               RSE_ATU_REGION_TEMP_SLOT,
                               log_addr,
                               physical_address,
                               METADATA_REGION_SIZE);
    if (rc != 0) {
        return -1;
    }


    /* Read fw_store_desc */
    rc = read_from_host_flash(metadata_header.descriptor_offset,
                              sizeof(fw_store_desc),
                              (uint8_t *)&fw_store_desc);
    if (rc != 0) {
        return -1;
    }

    rc = -1;
    /* Parse entries */
    for (idx = 0; idx < fw_store_desc.num_images; idx++) {
        /* Check type uuid */
        if(memcmp(&type_uuid, &fw_store_desc.img_entry[idx].img_type_uuid, sizeof(uuid_t)) == 0) {
            memcpy(image_uuid,
                   &fw_store_desc.img_entry[idx].img_bank_info[metadata_header.active_index].img_uuid,
                   sizeof(uuid_t));
            rc = 0;
            break;
        }
    }

    /* WORKAROUND: Init ATU region over metadata, removed from read_from_host_flash
                   until aligned access is implemented */
    if (atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_REGION_TEMP_SLOT) !=
        ATU_ERR_NONE) {
        return -1;
    }

    return rc;
}

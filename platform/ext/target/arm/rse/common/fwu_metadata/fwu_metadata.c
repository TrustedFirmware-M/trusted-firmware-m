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
#include "atu_config.h"
#include "atu_rse_lib.h"
#include "cmsis_compiler.h"
#include "device_definition.h"
#include "Driver_Flash.h"
#include "fwu_config.h"
#include "gpt.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "soft_crc.h"

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

static int read_from_host_flash(uint64_t offset,
                                uint32_t size,
                                uint8_t *data_buf)
{
    int rc;
    enum atu_error_t atu_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;

    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    if (size > METADATA_REGION_SIZE) {
        return -1;
    }

    if ((size / data_width) > (UINT32_MAX - offset)) {
        return -1;
    }

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, physical_address,
                                           log_addr,
                                           METADATA_REGION_SIZE,
                                           0);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    rc = FLASH_DEV_NAME.ReadData(log_addr - FLASH_BASE_ADDRESS, (void *)data_buf,
                                 size / data_width);
    if (rc != (size / data_width)) {
        return -1;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

int read_fwu_metadata(uint64_t offset, struct fwu_metadata_t *metadata)
{
    if (metadata == NULL) {
        return -1;
    }

    if (read_from_host_flash(offset, sizeof(*metadata),metadata)){
        return -1;
    }

    return 0;
}

int write_fwu_metadata(uint64_t offset,
                         const struct fwu_metadata_t *metadata)
{

    int rc;
    enum atu_error_t atu_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;

    if (metadata == NULL) {
        return -1;
    }

    ARM_FLASH_INFO *DriverInfo = FLASH_DEV_NAME.GetInfo();
    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    if (DriverInfo->sector_size < (sizeof(*metadata))) {
        return -1;
    }

    if ((offset + (sizeof(*metadata))) > HOST_FLASH0_SIZE) {
        return -1;
    }

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, physical_address,
                                           log_addr,
                                           METADATA_REGION_SIZE,
                                           0);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    rc = FLASH_DEV_NAME.EraseSector(log_addr - FLASH_BASE_ADDRESS);
    if (rc != ARM_DRIVER_OK) {
        return -1;
    }

    rc = FLASH_DEV_NAME.ProgramData(log_addr - FLASH_BASE_ADDRESS,
                                    (void *)metadata,
                                    sizeof(*metadata));
    if (rc < 0 || rc != sizeof(*metadata)) {
        return -1;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

int get_active_index(uint64_t md_offset,
                     uint8_t *active_index,
                     uint8_t *previous_active_index)
{
    int rc;
    struct fwu_metadata_t metadata;
    uint32_t calc_crc;

    rc = read_fwu_metadata(md_offset, &metadata);
    if (rc != 0) {
        return -1;
    }

    /* DEN0118 A3.2.4 Metadata Integrity check for version 2 */
    calc_crc = crc32((uint8_t *)&metadata + sizeof(metadata.crc_32),
                     metadata.metadata_size - sizeof(metadata.crc_32));

    if (metadata.crc_32 != calc_crc) {
        return -1;
    }


    if ((metadata.active_index >= FWU_BANK_COUNT) ||
        (metadata.previous_active_index >= FWU_BANK_COUNT)) {
        return -1;
    }

    if (active_index != NULL) {
        *active_index = metadata.active_index;
    }
    if (previous_active_index != NULL) {
        *previous_active_index = metadata.previous_active_index;
    }

    return 0;
}

int get_active_image_uuid_by_type_uuid(uint64_t md_offset,
                                       uuid_t type_uuid,
                                       uuid_t *image_uuid) {
    struct fwu_metadata_t metadata;
    int rc = 0;
    int idx = 0;
    uint32_t calc_crc;

    if (image_uuid == NULL) {
        return -1;
    }

    rc = read_fwu_metadata(md_offset, &metadata);
    if (rc != 0) {
        return -1;
    }

    /* DEN0118 A3.2.4 Metadata Integrity check for version 2 */
    calc_crc = crc32((const uint32_t *)(&metadata + sizeof(metadata.crc_32)),
                     metadata.metadata_size - sizeof(metadata.crc_32));

    if (metadata.crc_32 != calc_crc) {
        return -1;
    }

    rc = -1;
    /* Parse entries */
    for (idx = 0; idx < metadata.fw_desc.num_images; idx++) {
        /* Check type uuid */
        if(memcmp(&type_uuid, &metadata.fw_desc.img_entry[idx].img_type_uuid,
                  sizeof(uuid_t)) == 0) {
            memcpy(image_uuid,
                   &metadata.fw_desc.img_entry[idx].img_bank_info[metadata.active_index].img_uuid,
                   sizeof(uuid_t));
            rc = 0;
            break;
        }
    }

    return rc;
}

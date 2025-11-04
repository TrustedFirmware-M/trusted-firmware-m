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

static enum tfm_plat_err_t read_from_host_flash(uint64_t offset,
                                                uint32_t size,
                                                uint8_t *data_buf)
{
    int rc;
    enum atu_error_t atu_err;
    enum tfm_plat_err_t plat_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;
    const uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };

    ARM_FLASH_CAPABILITIES DriverCapabilities =
        FLASH_DEV_NAME.GetCapabilities();
    uint8_t data_width = data_width_byte[DriverCapabilities.data_width];

    if (size > METADATA_REGION_SIZE) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_SIZE;
    }

    if ((size / data_width) > (UINT32_MAX - offset)) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_SIZE;
    }

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_LIB_S, physical_address,
                                           log_addr,
                                           METADATA_REGION_SIZE,
                                           0);
    if (atu_err != ATU_ERR_NONE) {
        return (enum tfm_plat_err_t)atu_err;
    }

    rc = FLASH_DEV_NAME.ReadData(log_addr - FLASH_BASE_ADDRESS, (void *)data_buf,
                                 size / data_width);
    if (rc != (size / data_width)) {
        plat_err = TFM_PLAT_ERR_FWU_METADATA_FLASH_READ_FAILED;
        goto out_free_atu;
    }

    plat_err = TFM_PLAT_ERR_SUCCESS;

out_free_atu:
    atu_err = atu_rse_free_addr(&ATU_LIB_S, log_addr);
    if (atu_err != ATU_ERR_NONE) {
        return (enum tfm_plat_err_t)atu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t read_fwu_metadata(uint64_t offset, struct fwu_metadata_t *metadata)
{
    if (metadata == NULL) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_INPUT;
    }

    return read_from_host_flash(offset, sizeof(*metadata), (uint8_t *)metadata);
}

enum tfm_plat_err_t write_fwu_metadata(uint64_t offset,
                                       const struct fwu_metadata_t *metadata)
{

    int rc;
    enum atu_error_t atu_err;
    uint32_t log_addr = HOST_FLASH0_TEMP_BASE_S;
    uint64_t physical_address = HOST_FLASH0_BASE + offset;
    enum tfm_plat_err_t plat_err;

    if (metadata == NULL) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_INPUT;
    }

    ARM_FLASH_INFO *DriverInfo = FLASH_DEV_NAME.GetInfo();

    if (DriverInfo->sector_size < (sizeof(*metadata))) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_SIZE;
    }

    if ((offset + (sizeof(*metadata))) > HOST_FLASH0_SIZE) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_SIZE;
    }

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_LIB_S, physical_address,
                                           log_addr,
                                           METADATA_REGION_SIZE,
                                           0);
    if (atu_err != ATU_ERR_NONE) {
        return (enum tfm_plat_err_t)atu_err;
    }

    rc = FLASH_DEV_NAME.EraseSector(log_addr - FLASH_BASE_ADDRESS);
    if (rc != ARM_DRIVER_OK) {
        plat_err = TFM_PLAT_ERR_FWU_METADATA_FLASH_ERASE_FAILED;
        goto out_free_atu;
    }

    rc = FLASH_DEV_NAME.ProgramData(log_addr - FLASH_BASE_ADDRESS,
                                    (void *)metadata,
                                    sizeof(*metadata));
    if (rc < 0 || rc != sizeof(*metadata)) {
        plat_err = TFM_PLAT_ERR_FWU_METADATA_FLASH_WRITE_FAILED;
        goto out_free_atu;
    }

    plat_err = TFM_PLAT_ERR_SUCCESS;

out_free_atu:
    atu_err = atu_rse_free_addr(&ATU_LIB_S, log_addr);
    if (atu_err != ATU_ERR_NONE) {
        return (enum tfm_plat_err_t)atu_err;
    }

    return plat_err;
}

enum tfm_plat_err_t get_active_index(uint64_t md_offset,
                                     uint8_t *active_index,
                                     uint8_t *previous_active_index)
{
    enum tfm_plat_err_t plat_err;
    struct fwu_metadata_t metadata;
    uint32_t calc_crc;

    plat_err = read_fwu_metadata(md_offset, &metadata);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* DEN0118 A3.2.4 Metadata Integrity check for version 2 */
    calc_crc = crc32((uint8_t *)&metadata + sizeof(metadata.crc_32),
                     metadata.metadata_size - sizeof(metadata.crc_32));

    if (metadata.crc_32 != calc_crc) {
        return TFM_PLAT_ERR_FWU_METADATA_CRC_MISMATCH;
    }


    if ((metadata.active_index >= FWU_BANK_COUNT) ||
        (metadata.previous_active_index >= FWU_BANK_COUNT)) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_BANK_INDEX;
    }

    if (active_index != NULL) {
        *active_index = metadata.active_index;
    }
    if (previous_active_index != NULL) {
        *previous_active_index = metadata.previous_active_index;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t get_active_image_uuid_by_type_uuid(uint64_t md_offset,
                                                       uuid_t type_uuid,
                                                       uuid_t *image_uuid) {
    struct fwu_metadata_t metadata;
    int idx = 0;
    uint32_t calc_crc;
    enum tfm_plat_err_t plat_err;

    if (image_uuid == NULL) {
        return TFM_PLAT_ERR_FWU_METADATA_INVALID_INPUT;
    }

    plat_err = read_fwu_metadata(md_offset, &metadata);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* DEN0118 A3.2.4 Metadata Integrity check for version 2 */
    calc_crc = crc32((const uint32_t *)(&metadata + sizeof(metadata.crc_32)),
                     metadata.metadata_size - sizeof(metadata.crc_32));

    if (metadata.crc_32 != calc_crc) {
        return TFM_PLAT_ERR_FWU_METADATA_CRC_MISMATCH;
    }

    /* Parse entries */
    for (idx = 0; idx < metadata.fw_desc.num_images; idx++) {
        /* Check type uuid */
        if(memcmp(&type_uuid, &metadata.fw_desc.img_entry[idx].img_type_uuid,
                  sizeof(uuid_t)) == 0) {
            memcpy(image_uuid,
                   &metadata.fw_desc.img_entry[idx].img_bank_info[metadata.active_index].img_uuid,
                   sizeof(uuid_t));
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_FWU_METADATA_IMAGE_NOT_FOUND;
}

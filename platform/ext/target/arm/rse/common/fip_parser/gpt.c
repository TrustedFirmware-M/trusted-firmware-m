/*
 * Copyright (c) 2022-2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "gpt.h"

#include "flash_layout.h"
#include "Driver_Flash.h"

#include <string.h>

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

/* GPT has UTF-16LE strings, but we don't want to support them. FIP partitions
 * are always labelled using ANSI characters, so this function compares the
 * digits of the UTF-16LE string to an ANSI string.
 */
static enum tfm_plat_err_t gpt_strncmp(uint16_t *gpt_str, size_t gpt_maxlen,
                                       uint8_t *str, size_t str_len)
{
    size_t idx;

    if (str_len > gpt_maxlen) {
        return TFM_PLAT_ERR_GPT_STRNCMP_INVALID_INPUT;
    }

    for (idx = 0; idx < str_len; idx++) {
        if (str[idx] != gpt_str[idx]) {
            return TFM_PLAT_ERR_GPT_STRNCMP_COMPARISON_FAILED;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t gpt_get_header(uint32_t table_base, size_t atu_slot_size,
                                   gpt_header_t *header)
{
    ARM_FLASH_CAPABILITIES DriverCapabilities = FLASH_DEV_NAME.GetCapabilities();
    /* Valid entries for data item width */
    uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    size_t data_width = data_width_byte[DriverCapabilities.data_width];
    int rc;

    if (atu_slot_size < sizeof(gpt_header_t)) {
        return TFM_PLAT_ERR_GPT_HEADER_INVALID_SIZE;
    }

    rc = FLASH_DEV_NAME.ReadData(table_base - FLASH_BASE_ADDRESS, header,
                                 sizeof(gpt_header_t) / data_width);
    if (rc != sizeof(gpt_header_t) / data_width) {
        return TFM_PLAT_ERR_GPT_HEADER_INVALID_READ;
    }

    if (memcmp(header->signature, "EFI PART", sizeof(header->signature))) {
        return TFM_PLAT_ERR_GPT_HEADER_INVALID_SIGNATURE;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t gpt_get_list_entry_by_name(uint32_t list_base, uint32_t list_num_entries,
                               size_t list_entry_size, const char *name,
                               size_t name_size, size_t atu_slot_size,
                               gpt_entry_t *entry)
{
    ARM_FLASH_CAPABILITIES DriverCapabilities = FLASH_DEV_NAME.GetCapabilities();
    /* Valid entries for data item width */
    uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    size_t data_width = data_width_byte[DriverCapabilities.data_width];
    int rc;
    uint64_t idx;

    /* List entry is using names larger than EFI_NAMELEN_MAX - this is either an
     * RSE GPT config error or an out-of-spec GPT partition, either way we fail
     * here.
     */
    if (list_entry_size > sizeof(gpt_entry_t)) {
        return TFM_PLAT_ERR_GPT_ENTRY_INVALID_SIZE;
    }

    /* Check for overflow */
    if (list_base + list_num_entries * list_entry_size < list_base ||
        list_num_entries * list_entry_size > atu_slot_size) {
        return TFM_PLAT_ERR_GPT_ENTRY_OVERFLOW;
    }

    for (idx = list_base;
         idx < list_base + list_num_entries * list_entry_size;
         idx += list_entry_size) {
        rc = FLASH_DEV_NAME.ReadData(idx - FLASH_BASE_ADDRESS, entry,
                                     sizeof(gpt_entry_t));
        if (rc != sizeof(gpt_entry_t) / data_width) {
            return TFM_PLAT_ERR_GPT_ENTRY_INVALID_READ;
        }

        if (gpt_strncmp(entry->name,
                        list_entry_size - offsetof(gpt_entry_t, name),
                        name, name_size) == TFM_PLAT_ERR_SUCCESS) {
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_GPT_ENTRY_NOT_FOUND;
}

enum tfm_plat_err_t gpt_get_list_entry_by_image_uuid(uint32_t list_base,
                                                     uint32_t list_num_entries,
                                                     size_t list_entry_size,
                                                     uuid_t image_uuid,
                                                     size_t atu_slot_size,
                                                     gpt_entry_t *entry)
{
    ARM_FLASH_CAPABILITIES DriverCapabilities = FLASH_DEV_NAME.GetCapabilities();
    /* Valid entries for data item width */
    uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    size_t data_width = data_width_byte[DriverCapabilities.data_width];
    int rc;
    uint64_t idx;

    /* List entry is using names larger than EFI_NAMELEN_MAX - this is either an
     * RSE GPT config error or an out-of-spec GPT partition, either way we fail
     * here.
     */
    if (list_entry_size != sizeof(gpt_entry_t)) {
        return TFM_PLAT_ERR_GPT_ENTRY_INVALID_SIZE;
    }

    /* Check for overflow */
    if (list_base + list_num_entries * list_entry_size < list_base ||
        list_num_entries * list_entry_size > atu_slot_size) {
        return TFM_PLAT_ERR_GPT_ENTRY_OVERFLOW;
    }

    for (idx = list_base;
         idx < list_base + list_num_entries * list_entry_size;
         idx += list_entry_size) {
        rc = FLASH_DEV_NAME.ReadData(idx - FLASH_BASE_ADDRESS, entry,
                                     sizeof(gpt_entry_t));
        if (rc != sizeof(gpt_entry_t) / data_width) {
            return TFM_PLAT_ERR_GPT_ENTRY_INVALID_READ;
        }

        if (memcmp(&(entry->unique_uuid), &image_uuid, sizeof(image_uuid)) == 0) {
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    return TFM_PLAT_ERR_GPT_ENTRY_NOT_FOUND;
}

enum tfm_plat_err_t gpt_get_list_entry_by_type_uuid(uint32_t list_base,
                                                    uint32_t list_num_entries,
                                                    size_t list_entry_size,
                                                    uuid_t type_uuid,
                                                    size_t atu_slot_size,
                                                    gpt_entry_t entries[2])
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_GPT_ENTRY_NOT_FOUND;
    ARM_FLASH_CAPABILITIES DriverCapabilities = FLASH_DEV_NAME.GetCapabilities();
    /* Valid entries for data item width */
    uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    size_t data_width = data_width_byte[DriverCapabilities.data_width];
    int rc;
    uint8_t entry_cnt = 0;
    uint64_t idx;

    /* List entry is using names larger than EFI_NAMELEN_MAX - this is either an
     * RSE GPT config error or an out-of-spec GPT partition, either way we fail
     * here.
     */
    if (list_entry_size != sizeof(gpt_entry_t)) {
        return TFM_PLAT_ERR_GPT_ENTRY_INVALID_SIZE;
    }

    /* Check for overflow */
    if (list_base + list_num_entries * list_entry_size < list_base ||
        list_num_entries * list_entry_size > atu_slot_size) {
        return TFM_PLAT_ERR_GPT_ENTRY_OVERFLOW;
    }

    for (idx = list_base;
         (idx < list_base + list_num_entries * list_entry_size) &&
         (entry_cnt < 2);
         idx += list_entry_size) {
        rc = FLASH_DEV_NAME.ReadData(idx - FLASH_BASE_ADDRESS, &entries[entry_cnt],
                                     sizeof(gpt_entry_t));
        if (rc != sizeof(gpt_entry_t) / data_width) {
            return TFM_PLAT_ERR_GPT_ENTRY_INVALID_READ;
        }

        if (memcmp(&entries[entry_cnt].type_uuid, &type_uuid, sizeof(type_uuid)) == 0) {
            entry_cnt++;
            err = TFM_PLAT_ERR_SUCCESS;
        }
    }

    return err;
}

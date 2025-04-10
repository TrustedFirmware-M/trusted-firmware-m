/*
 * Copyright (c) 2022-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <assert.h>

#include "fip_parser.h"
#include "tfm_plat_defs.h"
#include "flash_layout.h"
#include "Driver_Flash.h"

enum tfm_plat_err_t fip_get_entry_by_uuid(const ARM_DRIVER_FLASH *flash_dev,
                                          uint32_t fip_offset, uint32_t atu_slot_size,
                                          uuid_t uuid, uint64_t *offset, size_t *size)
{
    ARM_FLASH_CAPABILITIES DriverCapabilities = flash_dev->GetCapabilities();
    assert(DriverCapabilities.data_width <= 2);
    /* Valid entries for data item width */
    const uint32_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    const size_t data_width =
        data_width_byte[DriverCapabilities.data_width <= 2 ? DriverCapabilities.data_width : 0];
    int rc;
    uint32_t idx = 0;
    fip_toc_header_t toc_header;
    fip_toc_entry_t toc_entry;
    uuid_t null_uuid;

    /* The NULL UUID is all-zeroes */
    memset(&null_uuid, 0, sizeof(null_uuid));

    rc = flash_dev->ReadData(fip_offset, &toc_header,
                             sizeof(toc_header) / data_width);
    if (rc != sizeof(toc_header) / data_width) {
        return TFM_PLAT_ERR_FIP_TOC_HEADER_INVALID_READ;
    }

    if (toc_header.name != TOC_HEADER_NAME) {
        return TFM_PLAT_ERR_FIP_TOC_HEADER_INVALID_NAME;
    }

    idx += sizeof(toc_header);

    do {
        /* Prevent reading out of bounds */
        if (idx + sizeof(toc_entry) > atu_slot_size) {
            return TFM_PLAT_ERR_FIP_TOC_ENTRY_OVERFLOW;
        }

        rc = flash_dev->ReadData(fip_offset + idx, &toc_entry,
                                 sizeof(toc_entry) / data_width);
        if (rc != sizeof(toc_entry) / data_width) {
            return TFM_PLAT_ERR_FIP_TOC_ENTRY_INVALID_READ;
        }

        if (!memcmp(&uuid, &toc_entry.uuid, sizeof(uuid))) {
            *offset = toc_entry.offset_address;

            /* We can't deal with partitions that are greater than UINT32_MAX,
             * since they aren't wholly mappable into the RSE memory space. This
             * is in reality bounded by the ATU mappable size, but that'll be
             * checked once the ATU region is set up, this just allows us to
             * perform safe type-conversion.
             */
            if (toc_entry.size > UINT32_MAX) {
                return TFM_PLAT_ERR_FIP_TOC_ENTRY_INVALID_SIZE;
            }

            *size = (uint32_t)toc_entry.size;

            return TFM_PLAT_ERR_SUCCESS;
        }

        idx += sizeof(toc_entry);
        /* The FIP's TOC ends in an entry with a NULL UUID. This entry's size is
         * the size of the whole FIP. */
    } while (memcmp(&null_uuid, &toc_entry.uuid, sizeof(uuid_t)));

    /* UUID not found, return error. */
    return TFM_PLAT_ERR_GPT_TOC_ENTRY_NOT_FOUND;
}

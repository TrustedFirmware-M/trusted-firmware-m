/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "runtime_shared_data.h"
#include "rse_persistent_data.h"
#include "region_defs.h"
#include "soft_crc.h"

int runtime_add_data_to_shared_area(uint8_t        major_type,
                                    uint16_t       minor_type,
                                    const uint8_t *data,
                                    size_t         size)
{
    struct runtime_shared_data_tlv_entry tlv_entry = {0};
    struct tfm_runtime_data *runtime_data;
    uintptr_t tlv_end, offset, base_addr;
    size_t region_size;

    base_addr = (uintptr_t)RSE_PERSISTENT_DATA->shared_data.runtime_to_boot_data;
    region_size = sizeof(RSE_PERSISTENT_DATA->shared_data.runtime_to_boot_data);

    if (data == NULL) {
        return -1;
    }

    runtime_data = (struct tfm_runtime_data *)base_addr;
    /* Check whether the shared area needs to be initialized. */
    if ((runtime_data->header.tlv_magic != RUNTIME_SHARED_DATA_TLV_INFO_MAGIC) ||
        (runtime_data->header.tlv_tot_len > region_size)) {

        memset((void *)base_addr, 0, region_size);
        runtime_data->header.tlv_magic   = RUNTIME_SHARED_DATA_TLV_INFO_MAGIC;
        runtime_data->header.tlv_tot_len = RUNTIME_SHARED_DATA_HEADER_SIZE;
    }

    /* Get the boundaries of TLV section. */
    tlv_end = base_addr + runtime_data->header.tlv_tot_len;
    offset  = base_addr + RUNTIME_SHARED_DATA_HEADER_SIZE;

    /* Check whether TLV entry is already added. Iterates over the TLV section
     * looks for the same entry if found then returns with error.
     */
    while (offset < tlv_end) {
        /* Create local copy to avoid unaligned access */
        memcpy(&tlv_entry, (const void *)offset,
               RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE);
        if (GET_MAJOR(tlv_entry.tlv_type) == major_type &&
            GET_MINOR(tlv_entry.tlv_type) == minor_type) {
            return -1;
        }

        offset += RUNTIME_SHARED_DATA_ENTRY_SIZE(tlv_entry.tlv_len);
    }

    /* Add TLV entry. */
    tlv_entry.tlv_type = SET_TLV_TYPE(major_type, minor_type);
    tlv_entry.tlv_len  = size;
    tlv_entry.calc_crc = crc32(data, size);

    /* Check integer overflow and overflow of shared data area. */
    if (RUNTIME_SHARED_DATA_ENTRY_SIZE(size) >
        (UINT16_MAX - runtime_data->header.tlv_tot_len)) {
        return -1;
    } else if ((RUNTIME_SHARED_DATA_ENTRY_SIZE(size) + runtime_data->header.tlv_tot_len) >
                region_size) {
        return -1;
    }

    offset = tlv_end;
    memcpy((void *)offset, &tlv_entry, RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE);

    offset += RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE;

    memcpy((void *)offset, data, size);
    runtime_data->header.tlv_tot_len += RUNTIME_SHARED_DATA_ENTRY_SIZE(size);

    return 0;
}

int get_runtime_shared_data(uint8_t  major_type,
                            uint16_t minor_type,
                            uint8_t  *data,
                            size_t   data_len)
{
    uint8_t *tlv_end, *tlv_curr;
    uint32_t calc_crc;
    struct tfm_runtime_data *runtime_data;
    struct runtime_shared_data_tlv_entry tlv_entry;

    if (data == NULL) {
        return -1;
    }

    runtime_data = (struct tfm_runtime_data *)RSE_PERSISTENT_DATA->shared_data.runtime_to_boot_data;

    /* The ADAC runtime service writes the permission mask bits into the memory
     * which is shared between TF-M ADAC runtime service and BL1_1
     */
    if (runtime_data->header.tlv_magic != RUNTIME_SHARED_DATA_TLV_INFO_MAGIC) {
        return -1;
    }

    tlv_end = (uint8_t *)runtime_data + runtime_data->header.tlv_tot_len;
    tlv_curr = runtime_data->data;

    /* Iterates over the TLV section and copy TLVs with requested major
     * type to the provided buffer.
     */
    while (tlv_curr < tlv_end) {
        memcpy(&tlv_entry, tlv_curr, RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE);

        if (GET_MAJOR(tlv_entry.tlv_type) == major_type &&
            GET_MINOR(tlv_entry.tlv_type) == minor_type) {
            /* Check for output buffer length */
            if(tlv_entry.tlv_len > data_len) {
                return -1;
            }

            calc_crc = crc32(tlv_curr + RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE,
                             tlv_entry.tlv_len);

            if (calc_crc != tlv_entry.calc_crc) {
                /* Data corrupted */
                return -1;
            }

            memcpy(data,
                tlv_curr + RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE,
                tlv_entry.tlv_len);

            return 0;
        }
        tlv_curr += RUNTIME_SHARED_DATA_ENTRY_HEADER_SIZE + tlv_entry.tlv_len;
    }

    return -1;
}

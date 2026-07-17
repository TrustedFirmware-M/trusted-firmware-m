/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file
 * Implementation of write I/O functionality
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "io/gpt_io.h"
#include "io/gpt_io_read.h"
#include "io/gpt_io_write.h"
#include "psa/error.h"
#include "gpt_defs.h"
#include "tfm_log.h"
#include "efi_soft_crc.h"

/* True if write was buffered */
static bool write_buffered = false;

/* Helper function prototypes */
static psa_status_t write_headers_to_flash(struct gpt_t *primary_table);
static psa_status_t write_entry_and_header(struct gpt_t *table,
                                           const uint64_t lbas_into_array);

bool is_write_buffered(void)
{
    return write_buffered;
}

void set_write_buffered(bool buffered)
{
    write_buffered = buffered;
}

psa_status_t flush_lba_buf(struct gpt_t *primary_table)
{
    /* Prevent recursive calls, as the various writes below may attempt to
     * flush, particularly those making multiple writes
     */
    static bool in_flush = false;

    if (in_flush) {
        return PSA_SUCCESS;
    }
    in_flush = true;
    set_write_buffered(false);
    psa_status_t ret = PSA_SUCCESS;
    uint64_t cached_lba = get_cached_lba();

    /* Commit to flash what is in the buffer. Also update the backup table if
     * the cached LBA was part of the primary table (or vise-versa)
     */
    uint64_t array_size =
        partition_array_last_lba(primary_table) - primary_table->header.array_lba + 1;

    if (cached_lba == PRIMARY_GPT_LBA ||
            (get_backup_gpt_lba() != 0 && cached_lba == get_backup_gpt_lba())) {
        /* GPT header. Write both backup and primary headers */
        ret = write_headers_to_flash(primary_table);
    } else if (cached_lba >= primary_table->header.array_lba &&
            cached_lba <= partition_array_last_lba(primary_table)) {
        /* Primary array entry. Write to backup and primary array */
        ret = write_entries_to_flash(primary_table,
                cached_lba - primary_table->header.array_lba);
    } else if (get_gpt_array_lba(false) != 0 &&
            get_gpt_array_lba(false) <= cached_lba &&
            cached_lba <= get_gpt_array_lba(false) + array_size - 1) {
        /* Backup array entry. Write to backup and primary array */
        ret = write_entries_to_flash(primary_table,
                cached_lba - get_gpt_array_lba(false));
    } else {
        /* Some other LBA is cached, possibly data. Write it anyway */
        ret = write_to_flash(cached_lba, false);
    }

    in_flush = false;
    return ret;
}

psa_status_t write_to_flash(uint64_t lba, bool skip_erase)
{
    struct gpt_flash_driver_t *flash_driver = get_plat_flash_driver();
    uint8_t *lba_buf = get_lba_buf();

    if (!skip_erase) {
        if (flash_driver->erase(lba, 1) != 1) {
            ERROR("Unable to erase flash at LBA 0x%08x%08x\n",
                    (uint32_t)(lba >> 32),
                    (uint32_t)lba);
            return PSA_ERROR_STORAGE_FAILURE;
        }
    }

    if (flash_driver->write(lba, lba_buf) != TFM_GPT_BLOCK_SIZE) {
        ERROR("Unable to program flash at LBA 0x%08x%08x\n",
                (uint32_t)(lba >> 32),
                (uint32_t)lba);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    return PSA_SUCCESS;
}

psa_status_t write_entries_to_flash(struct gpt_t *primary_table, uint32_t lbas_into_array)
{
    psa_status_t ret;
    bool lba_dirty = false;

    /* First, update the entirety of the backup table, partition array then header */
    struct gpt_t backup_table;
    if (get_backup_gpt_lba() == 0) {
        WARN("Backup GPT location unknown!\n");
    } else {
        swap_headers(&(primary_table->header), &(backup_table.header));
        if (backup_table.header.array_lba == 0) {
            WARN("Cannot update backup GPT!\n");
        } else {
            /* All information needed to update the backup table known */
            ret = write_entry_and_header(&backup_table, lbas_into_array);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
            lba_dirty = true;
        }
    }

    if (lba_dirty) {
        /* Now do the primary but first re-read the LBA just written to the backup
         * partition array. The LBA buffer may refer to a different LBA from
         * updating the backup header by reading the backup partition entry array
         * for the CRC calculation
         */
        ret = read_from_flash(backup_table.header.array_lba + lbas_into_array);
        if (ret != PSA_SUCCESS) {
            WARN("Cannot update primary GPT!\n");
            return ret;
        }
    }

    /* Now do the primary */
    if (primary_table->header.array_lba == 0) {
        WARN("Cannot update primary GPT!\n");
        ret = PSA_ERROR_STORAGE_FAILURE;
    } else {
        /* All information needed to update the primary table known */
        ret = write_entry_and_header(primary_table, lbas_into_array);
    }

    return ret;
}

psa_status_t write_entry(struct gpt_t             *primary_table,
                         uint32_t                  array_index,
                         const struct gpt_entry_t *entry)
{
    uint8_t *lba_buf = get_lba_buf();

    /* Use this for a very simple, very dumb buffering heuristic. Flush every
     * time an LBA's worth of entries have been written (flush every nth
     * operation).
     */
    static uint32_t num_writes = 0;

    /* First, ensure the entry is part of the buffered block. In most cases,
     * this will be a no-op
     */
    psa_status_t ret = read_from_flash(partition_entry_lba(primary_table, array_index));

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Copy into buffer */
    uint32_t index_in_lba = array_index % gpt_entry_per_lba_count();

    memcpy(lba_buf + index_in_lba * GPT_ENTRY_SIZE, entry, GPT_ENTRY_SIZE);

    /* Write on every nth operation. */
    if (++num_writes == gpt_entry_per_lba_count()) {
        /* Write the buffer to flash */
        num_writes = 0;
        set_write_buffered(false);

        ret = write_entries_to_flash(primary_table,
                get_cached_lba() - primary_table->header.array_lba);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    } else {
        set_write_buffered(true);
    }

    return PSA_SUCCESS;
}

psa_status_t write_header_to_flash(const struct gpt_t *table)
{
    /* Ensure the in-memory LBA buffer has the header. Because the header is
     * also in memory, there is no need to read it again before writing.
     */
    uint8_t temp_buf[GPT_HEADER_SIZE];
    uint8_t *lba_buf = get_lba_buf();

    memcpy(temp_buf, lba_buf, GPT_HEADER_SIZE);
    memcpy(lba_buf, &(table->header), GPT_HEADER_SIZE);
    const psa_status_t ret = write_to_flash(table->header.current_lba, false);

    memcpy(lba_buf, temp_buf, GPT_HEADER_SIZE);

    return ret;
}

psa_status_t update_header(struct gpt_t *table, uint32_t num_partitions)
{
    table->num_used_partitions = num_partitions;
    struct gpt_header_t *header = &(table->header);

    /* Take the CRC of the partition array */
    uint32_t crc = 0;

    for (uint32_t i = 0; i < header->num_partitions; ++i) {
        uint8_t entry_buf[GPT_ENTRY_SIZE] = {0};
        struct gpt_entry_t *entry = (struct gpt_entry_t *)entry_buf;

        psa_status_t ret = read_entry_from_flash(table, i, entry);

        if (ret != PSA_SUCCESS) {
            return ret;
        }
        crc = efi_soft_crc32_update(crc, entry_buf, GPT_ENTRY_SIZE);
    }
    header->array_crc = crc;

    /* Calculate new CRC32 for header */
    header->header_crc = 0;
    header->header_crc = efi_soft_crc32_update(0, (uint8_t *)header, GPT_HEADER_SIZE);

    return PSA_SUCCESS;
}

/* Write both backup and primary headers to flash using the given table */
static psa_status_t write_headers_to_flash(struct gpt_t *primary_table)
{
    if (get_backup_gpt_lba() != 0) {
        struct gpt_t backup_gpt = *primary_table;

        /* Always write to the backup first. */
        swap_headers(&primary_table->header, &backup_gpt.header);

        const psa_status_t ret = write_header_to_flash(&backup_gpt);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    } else {
        WARN("Backup GPT LBA unknown!\n");
    }

    return write_header_to_flash(primary_table);
}

/* Writes the entry to flash and updates the corresponding header. Assume the
 * LBA buf has in it the entry to be written
 */
static psa_status_t write_entry_and_header(struct gpt_t  *table,
                                           const uint64_t lbas_into_array)
{
    psa_status_t ret = write_to_flash(table->header.array_lba + lbas_into_array, false);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write entry to partition array\n");
        return ret;
    }

    ret = update_header(table, table->num_used_partitions);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to update GPT header; table corrupted!\n");
        return ret;
    }

    ret = write_header_to_flash(table);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to update GPT header; table corrupted!\n");
    }

    return ret;
}

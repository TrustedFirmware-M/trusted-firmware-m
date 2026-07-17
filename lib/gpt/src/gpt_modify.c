/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file
 * Implementation of public APIs
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "gpt_defs.h"
#include "io/gpt_io.h"
#include "io/gpt_io_read.h"
#include "io/gpt_io_write.h"

#include "gpt.h"
#include "gpt_flash.h"
#include "tfm_log.h"
#include "efi_guid_structs.h"
#include "efi_guid.h"
#include "efi_soft_crc.h"

/* Helper function prototypes */
static psa_status_t move_lba(const uint64_t old_lba, const uint64_t new_lba, const bool skip_erase);
static psa_status_t move_partition_data(const uint64_t old_lba,
                                        const uint64_t new_lba,
                                        const uint64_t num_blocks);
static psa_status_t move_partition(const struct efi_guid_t *guid,
                                   const uint64_t           start,
                                   const uint64_t           end,
                                   const bool               no_copy);
static psa_status_t duplicate_partition(const struct efi_guid_t *old_guid,
                                        const uint64_t           start,
                                        const bool               no_copy,
                                        struct efi_guid_t       *new_guid);
static psa_status_t restore_table(struct gpt_t *restore_from, bool is_primary);
static psa_status_t sort_partition_array(struct gpt_t *primary_table);

/* PUBLIC API FUNCTIONS */

psa_status_t gpt_entry_rename(const struct efi_guid_t *guid, const char name[GPT_ENTRY_NAME_LENGTH])
{
    if (name[0] == '\0') {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* NOOP if no name change. Prevents header update. */
    if (memcmp(cached_entry.name, name, GPT_ENTRY_NAME_LENGTH) == 0) {
        return PSA_SUCCESS;
    }

    memcpy(cached_entry.name, name, GPT_ENTRY_NAME_LENGTH);
    cached_entry.name[GPT_ENTRY_NAME_LENGTH - 1] = '\0';
    cached_entry.name[GPT_ENTRY_NAME_LENGTH - 2] = '\0';
    return write_entry(primary_table, cached_index, &cached_entry);
}

psa_status_t gpt_entry_change_type(const struct efi_guid_t *guid, const struct efi_guid_t *type)
{
    struct efi_guid_t null_type = NULL_GUID;

    if (efi_guid_cmp(&null_type, type) == 0) {
        ERROR("Cannot set type to null-GUID; delete instead\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.partition_type = *type;

    return write_entry(primary_table, cached_index, &cached_entry);
}

psa_status_t gpt_attr_add(const struct efi_guid_t *guid, const uint64_t attr)
{
    /* This quick check prevents I/O from happening for a no-op */
    if (attr == 0) {
        return PSA_SUCCESS;
    }

    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr |= attr;

    return write_entry(primary_table, cached_index, &cached_entry);
}

psa_status_t gpt_attr_remove(const struct efi_guid_t *guid, const uint64_t attr)
{
    /* This quick check prevents I/O from happening for a no-op */
    if (attr == 0) {
        return PSA_SUCCESS;
    }

    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr &= ~(attr);

    return write_entry(primary_table, cached_index, &cached_entry);
}

psa_status_t gpt_attr_set(const struct efi_guid_t *guid, const uint64_t attr)
{
    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr = attr;

    return write_entry(primary_table, cached_index, &cached_entry);
}

psa_status_t gpt_entry_move(const struct efi_guid_t *guid,
                            const uint64_t           start,
                            const uint64_t           end)
{
    return move_partition(guid, start, end, false);
}

psa_status_t gpt_entry_move_no_copy(const struct efi_guid_t *guid,
                                    const uint64_t           start,
                                    const uint64_t           end)
{
    return move_partition(guid, start, end, true);
}

psa_status_t gpt_entry_duplicate(const struct efi_guid_t *old_guid,
                                 const uint64_t           start,
                                 struct efi_guid_t       *new_guid)
{
    return duplicate_partition(old_guid, start, false, new_guid);
}

psa_status_t gpt_entry_duplicate_no_copy(const struct efi_guid_t *old_guid,
                                         const uint64_t           start,
                                         struct efi_guid_t       *new_guid)
{
    return duplicate_partition(old_guid, start, true, new_guid);
}

psa_status_t gpt_entry_create(const struct efi_guid_t *type,
                              const uint64_t           start,
                              const uint64_t           size,
                              const uint64_t           attr,
                              const char               name[GPT_ENTRY_NAME_LENGTH],
                              struct efi_guid_t       *guid)
{
    struct gpt_t *primary_table;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Using inequlity here handles when reading an initial GPT has more than
     * the maximum defined number of partitions.
     */
    if (primary_table->num_used_partitions >= get_plat_max_partitions()) {
        ERROR("Maximum number of partitions reached\n");
        return PSA_ERROR_INSUFFICIENT_STORAGE;
    }
    if (size == 0) {
        ERROR("Cannot create entry of size 0\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (name[0] == '\0') {
        ERROR("Cannot create entry with no name\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    uint64_t start_lba = start;

    if (start_lba == 0) {
        /* Use the lowest free LBA possible. Each partition uses contiguous space,
         * so if there is a gap between partitions, that will be shown by the end
         * and start not being contiguous.
         */
        uint64_t prev_end = primary_table->header.first_lba;

        for (uint32_t i = 0; i < primary_table->header.num_partitions; ++i) {
            struct gpt_entry_t entry = {0};

            ret = read_entry_from_flash(primary_table, i, &entry);
            if (ret != PSA_SUCCESS) {
                return ret;
            }

            if (entry.start - 1 > prev_end) {
                start_lba = prev_end + 1;
                break;
            }
            prev_end = entry.end;
        }

        if (start_lba != prev_end + 1) {
            /* No free space */
            ERROR("No free space on device!\n");
            return PSA_ERROR_INSUFFICIENT_STORAGE;
        }
    }

    /* Must fit on flash */
    const uint64_t end_lba = start_lba + size - 1;

    if (start_lba < primary_table->header.first_lba ||
            end_lba < primary_table->header.first_lba ||
            start_lba > primary_table->header.last_lba ||
            end_lba > primary_table->header.last_lba) {
        ERROR("Requested partition would not be on disk\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Do not allow overlapping partitions */
    struct gpt_entry_t entry;

    for (uint32_t i = 0; i < primary_table->num_used_partitions; ++i) {
        ret = read_entry_from_flash(primary_table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        if ((start_lba >= entry.start && start_lba <= entry.end) ||
                (end_lba >= entry.start && end_lba <= entry.end) ||
                (start_lba <= entry.start && end_lba >= entry.end)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Generate the new random GUID */
    if (efi_guid_generate_random(guid) != PSA_SUCCESS) {
        ERROR("Unable to generate GUID\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    /* Set new entry's metadata */
    struct gpt_entry_t new_entry = {0};

    new_entry.start = start_lba;
    new_entry.end = end_lba;
    new_entry.attr = attr;
    memcpy(new_entry.name, name, GPT_ENTRY_NAME_LENGTH);
    new_entry.partition_type = *type;
    new_entry.unique_guid = *guid;

    /* Write the new entry and update the header */
    ret = write_entry(primary_table, primary_table->num_used_partitions++, &new_entry);
    if (ret != PSA_SUCCESS) {
        --primary_table->num_used_partitions;
        return ret;
    }

    /* Flush the buffered LBA if not done so. This will cause the header to be
     * updated
     */
    if (is_write_buffered()) {
        /* flush_lba_buf will update the header */
        ret = flush_lba_buf(primary_table);
    } else {
        ret = update_header(primary_table, primary_table->num_used_partitions);
    }

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    return PSA_SUCCESS;
}

psa_status_t gpt_entry_remove(const struct efi_guid_t *guid)
{
    struct gpt_t *primary_table;
    uint8_t *lba_buf = get_lba_buf();
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Shuffle the remainder of the array up. This will overwrite the
     * most previous entry.
     *
     * The first LBA to potentially modify is in memory. It doesn't need
     * to be modified if the last entry in the array was moved or if it is
     * the only LBA used by the partition array
     */
    const uint64_t array_end_lba = partition_array_last_lba(primary_table);

    if (cached_index != primary_table->num_used_partitions - 1 ||
            cached_index < gpt_entry_per_lba_count()) {
        /* Shuffle up the remainder of the LBA. If it was the last entry
         * in the LBA, there is nothing to do.
         */
        const uint32_t lba_index = cached_index % gpt_entry_per_lba_count();

        if (lba_index + 1 != gpt_entry_per_lba_count()) {
            memmove(
                    lba_buf + lba_index * GPT_ENTRY_SIZE,
                    lba_buf + (lba_index + 1) * GPT_ENTRY_SIZE,
                    (gpt_entry_per_lba_count() - lba_index - 1) * GPT_ENTRY_SIZE);
        }

        /* If this is not the last LBA, then read the next LBA into memory and
         * place it's first element in the final slot of the currently modified
         * LBA. Repeat this for each LBA read.
         *
         * Use a second buffer to read each consecutive LBA and copy that to
         * the global LBA buffer to then write afterwards.
         */
        for (uint64_t i = partition_entry_lba(primary_table, cached_index) + 1;
                i <= array_end_lba;
                ++i) {
            uint8_t array_buf[TFM_GPT_BLOCK_SIZE] = {0};
            int read_ret = get_plat_flash_driver()->read(i, array_buf);

            if (read_ret != TFM_GPT_BLOCK_SIZE) {
                ERROR("Unable to read LBA 0x%08x%08x\n",
                        (uint32_t)(i >> 32), (uint32_t)i);
                return PSA_ERROR_STORAGE_FAILURE;
            }

            memcpy(
                    lba_buf + GPT_ENTRY_SIZE * (gpt_entry_per_lba_count() - 1),
                    array_buf,
                    GPT_ENTRY_SIZE);

            /* Write to backup first, then primary partition array */
            if (get_gpt_array_lba(false) != 0) {
                ret = write_to_flash(
                        get_gpt_array_lba(false) + i - 1 - primary_table->header.array_lba,
                        false);
                if (ret != PSA_SUCCESS) {
                    return ret;
                }
            }
            ret = write_to_flash(i - 1, false);
            if (ret != PSA_SUCCESS) {
                return ret;
            }

            memmove(
                    array_buf,
                    array_buf + GPT_ENTRY_SIZE,
                    sizeof(array_buf) - GPT_ENTRY_SIZE);
            memcpy(lba_buf, array_buf, TFM_GPT_BLOCK_SIZE);
        }
    }

    /* What was the final LBA is now cached and may be empty or partially-filled */
    set_cached_lba(array_end_lba);
    set_write_buffered(false);
    uint32_t entries_in_last_lba = (--primary_table->num_used_partitions) % gpt_entry_per_lba_count();

    bool skip_erase;
    if (entries_in_last_lba == 0) {
        /* There's nothing left in this LBA, so zero it all and write it out.
         * There is also no need to do an erase just to zero afterwards.
         */
        memset(lba_buf, 0, TFM_GPT_BLOCK_SIZE);
        skip_erase = true;
    } else {
        /* Zero what is not needed anymore */
        memset(
                lba_buf + GPT_ENTRY_SIZE * entries_in_last_lba,
                0,
                (gpt_entry_per_lba_count() - entries_in_last_lba) * GPT_ENTRY_SIZE);
        skip_erase = false;
    }

    if (get_gpt_array_lba(false) != 0) {
        ret = write_to_flash(
                get_gpt_array_lba(false) + array_end_lba - primary_table->header.array_lba,
                skip_erase);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    ret = write_to_flash(array_end_lba, skip_erase);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Update the header after flash changes */
    ret = update_header(primary_table, primary_table->num_used_partitions);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    if (get_backup_gpt_lba() != 0) {
        struct gpt_t backup_table;

        swap_headers(&primary_table->header, &backup_table.header);
        ret = write_header_to_flash(&backup_table);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    return write_header_to_flash(primary_table);
}

psa_status_t gpt_restore(bool is_primary)
{
    if (!is_primary && get_backup_gpt_lba() == 0) {
        ERROR("Backup GPT location unknown!\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    /* Flush and invalidate the in-memory buffer before attempting to restore a
     * table. The in-memory header needs to be updated if the flushed LBA was
     * part of the entry array
     */
    psa_status_t ret;

    if (is_write_buffered()) {
        /* A table should be cached */
        struct gpt_t *primary_table;
        ret = read_table(&primary_table, true);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        ret = flush_lba_buf(primary_table);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        set_write_buffered(false);
    }
    set_cached_lba(0);
    invalidate_cached_gpt();

    struct gpt_t *table;

    ret = read_table(&table, !is_primary);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = restore_table(table, !is_primary);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    return PSA_SUCCESS;
}

psa_status_t gpt_defragment(void)
{
    struct gpt_t *primary_table;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* First, sort the partition array according to start LBA. This means that
     * moving partitions towards the start of the flash sequentially is safe
     * and will not result in lost data.
     */
    ret = sort_partition_array(primary_table);

    if (ret != PSA_SUCCESS) {
        ERROR("Unable to defragment flash!\n");
        return ret;
    }

    uint64_t prev_end = primary_table->header.first_lba;
    struct gpt_entry_t entry;

    for (uint32_t i = 0; i < primary_table->num_used_partitions; ++i) {
        ret = read_entry_from_flash(primary_table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        /* Move to be next to previous entry. Continue if already where it
         * needs to be.
         */
        if (prev_end == entry.start) {
            prev_end = entry.end + 1;
            continue;
        }

        const uint64_t num_blocks = entry.end - entry.start + 1;

        ret = move_partition_data(entry.start, prev_end, num_blocks);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        /* Update header information */
        entry.start = prev_end;
        entry.end = entry.start + num_blocks - 1;
        prev_end = entry.end + 1;

        /* Write the entry change */
        ret = write_entry(primary_table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    /* Write everything to flash after defragmentation if not done so already.
     * The previous loop will write the last entry to the LBA buffer, which may
     * or not may not be flushed
     */
    if (is_write_buffered()) {
        return flush_lba_buf(primary_table);
    }

    return update_header(primary_table, primary_table->num_used_partitions);
}

/* Duplicate a partition, potentially also copying its data but always updating
 * the header
 */
static psa_status_t duplicate_partition(const struct efi_guid_t *old_guid,
                                        const uint64_t           start,
                                        const bool               no_copy,
                                        struct efi_guid_t       *new_guid)
{
    struct partition_entry_t old_entry;
    psa_status_t ret = gpt_entry_read(old_guid, &old_entry);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = gpt_entry_create(&(old_entry.type_guid),
                           start,
                           old_entry.size,
                           old_entry.attr,
                           old_entry.name,
                           new_guid);
    if (ret != PSA_SUCCESS || no_copy) {
        return ret;
    }

    /* If start is 0, then gpt_entry_create will have created the new partition
     * in the lowest free space possible, wherever that is
     */
    uint64_t new_start = start;

    if (start == 0) {
        /* Get the start LBA of the new partition. */
        struct partition_entry_t new_entry;
        ret = gpt_entry_read(new_guid, &new_entry);
        if (ret != PSA_SUCCESS) {
            ERROR("Unable to copy partition data!\n");
            return ret;
        }

        new_start = new_entry.start;
    }

    return move_partition_data(old_entry.start, new_start, old_entry.size);
}

/* Move a partition, potentially also copying its data but always updating the header */
static psa_status_t move_partition(const struct efi_guid_t *guid,
                                   const uint64_t           start,
                                   const uint64_t           end,
                                   const bool               no_copy)
{
    struct gpt_t *primary_table;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    if (end < start) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Must fit on flash */
    if (start < primary_table->header.first_lba ||
            end < primary_table->header.first_lba ||
            start > primary_table->header.last_lba ||
            end > primary_table->header.last_lba) {
        ERROR("Requested move would not be on disk\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    ret = find_gpt_entry(
            primary_table,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Prevent unnecessary I/O */
    if (start == cached_entry.start && end == cached_entry.end) {
        return PSA_SUCCESS;
    }

    /* It is not possible to move a partition such that it overlaps with an
     * existing partition (other than itself). Check the currently cached LBA
     * first, then the others to avoid reading this LBA twice
     */
    struct gpt_entry_t entry;
    const uint64_t checked_lba = get_cached_lba();
    const uint64_t array_end_lba = partition_array_last_lba(primary_table);
    uint32_t num_entries_in_cached_lba;

    if (checked_lba == array_end_lba) {
        /* If this is 0, then the last LBA is full */
        uint32_t num_entries_in_last_lba =
            primary_table->num_used_partitions % gpt_entry_per_lba_count();

        if (num_entries_in_last_lba == 0) {
            num_entries_in_cached_lba = gpt_entry_per_lba_count();
        } else {
            num_entries_in_cached_lba = num_entries_in_last_lba;
        }
    } else {
        num_entries_in_cached_lba = gpt_entry_per_lba_count();
    }

    /* Cached LBA */
    for (uint32_t i = 0; i < num_entries_in_cached_lba; ++i) {
        memcpy(&entry, get_lba_buf() + (i * GPT_ENTRY_SIZE), GPT_ENTRY_SIZE);

        const struct efi_guid_t ent_guid = entry.unique_guid;

        if (efi_guid_cmp(&ent_guid, guid) == 0) {
            continue;
        }

        if ((start >= entry.start && start <= entry.end) ||
                (end >= entry.start && end <= entry.end) ||
                (start <= entry.start && end >= entry.end)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* All the rest */
    for (uint32_t i = 0; i < primary_table->num_used_partitions; ++i) {
        if (partition_entry_lba(primary_table, i) == checked_lba) {
            continue;
        }

        ret = read_entry_from_flash(primary_table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        if ((start >= entry.start && start <= entry.end) ||
                (end >= entry.start && end <= entry.end) ||
                (start <= entry.start && end >= entry.end)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    if (!no_copy) {
        ret = move_partition_data(
                cached_entry.start,
                start,
                end - start + 1);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    cached_entry.start = start;
    cached_entry.end = end;

    return write_entry(primary_table, cached_index, &cached_entry);
}

/* Move a single LBAs data to somewhere else */
static psa_status_t move_lba(const uint64_t old_lba, const uint64_t new_lba, const bool skip_erase)
{
    VERBOSE("Moving from 0x%x%x to 0x%x%x %s erase\n",
            (uint32_t)(old_lba >> 32), (uint32_t)old_lba,
            (uint32_t)(new_lba >> 32), (uint32_t)new_lba,
            skip_erase ? "without" : "with");
    const psa_status_t ret = read_from_flash(old_lba);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    return write_to_flash(new_lba, skip_erase);
}

/* Moves a partition's data to start from one logical block to another */
static psa_status_t move_partition_data(const uint64_t old_lba,
                                   const uint64_t new_lba,
                                   const uint64_t num_blocks)
{
    struct gpt_flash_driver_t *flash_driver = get_plat_flash_driver();

    VERBOSE("moving %08x%08x blocks from 0x%08x%08x to 0x%08x%08x\n",
            (uint32_t)(num_blocks >> 32), (uint32_t)num_blocks,
            (uint32_t)(old_lba >> 32), (uint32_t)old_lba,
            (uint32_t)(new_lba >> 32), (uint32_t)new_lba);

    if (old_lba == new_lba) {
        return PSA_SUCCESS;
    }

    /* If possible, erase all of the LBAs that the data is going to be read
     * to, so that, in the case an LBA is smaller than a flash sector, the
     * number of flash erase cycles is reduced. Ignore any errors when erasing,
     * as the "write" will perform erase anyway. If the areas between where the
     * partition is now and where it will be does not overlap, then erase all
     * blocks in the new area. If there is overlap, erase only those which are
     * not within the old area
     */
    if (old_lba < new_lba) {
        /* Attempt consecutive erase */
        uint64_t non_overlap_blocks =
            (old_lba + num_blocks - 1 < new_lba ? num_blocks : new_lba - old_lba);

        VERBOSE("Erasing 0x%x%x blocks from LBA 0x%x%x\n",
                (uint32_t)(non_overlap_blocks >> 32), (uint32_t)non_overlap_blocks,
                (uint32_t)(new_lba >> 32), (uint32_t)new_lba);

        const ssize_t erase_ret = flash_driver->erase(
                new_lba + (num_blocks - non_overlap_blocks),
                (size_t)non_overlap_blocks);

        if (erase_ret != (ssize_t)non_overlap_blocks) {
            WARN("Partial consecutive erase (%ld); erasing per block\n",
                 erase_ret);
            non_overlap_blocks = 0;
        }

        /* Move block by block backwards */
        for (uint64_t block = num_blocks; block > 0; --block) {
            const bool skip_erase = (block < non_overlap_blocks);
            const psa_status_t ret = move_lba(old_lba + block - 1, new_lba + block - 1, skip_erase);

            if (ret != PSA_SUCCESS) {
                return ret;
            }
        }
    } else {
        /* Attempt consecutive erase */
        uint64_t non_overlap_blocks =
            (new_lba + num_blocks - 1 < old_lba ? num_blocks : old_lba - new_lba);

        VERBOSE("Erasing 0x%x%x blocks from LBA 0x%x%x\n",
                (uint32_t)(non_overlap_blocks >> 32), (uint32_t)non_overlap_blocks,
                (uint32_t)(new_lba >> 32), (uint32_t)new_lba);

        const ssize_t erase_ret = flash_driver->erase(new_lba, (size_t)non_overlap_blocks);

        if (erase_ret != (ssize_t)non_overlap_blocks) {
            WARN("Partial consecutive erase (%ld); erasing per block\n",
                 erase_ret);
            non_overlap_blocks = 0;
        }

        /* Move block by block forwards */
        for (uint64_t block = 0; block < num_blocks; ++block) {
            const bool skip_erase = (block < non_overlap_blocks);
            const psa_status_t ret = move_lba(old_lba + block, new_lba + block, skip_erase);

            if (ret != PSA_SUCCESS) {
                return ret;
            }
        }
    }

    set_write_buffered(false);

    return PSA_SUCCESS;
}

/* Restore a table from another. The second parameter indicates whether the
 * restoring table is the primary GPT or not
 */
static psa_status_t restore_table(struct gpt_t *restore_from, bool is_primary)
{
    /* Determine if the restoring GPT is valid */
    psa_status_t ret = validate_table(restore_from, is_primary);

    if (ret != PSA_SUCCESS) {
        invalidate_cached_gpt();
        return ret;
    }

    struct gpt_t restore_to;

    swap_headers(&(restore_from->header), &(restore_to.header));

    /* Copy the partition array as well */
    ret = move_partition_data(
            restore_from->header.array_lba,
            restore_to.header.array_lba,
            (restore_from->header.num_partitions +
             gpt_entry_per_lba_count() - 1) / gpt_entry_per_lba_count());
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Write the restored header */
    ret = write_header_to_flash(&restore_to);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write %s GPT header\n", is_primary ? "backup" : "primary");
        return ret;
    }

    /* Review the number of used partitions. */
    ret = count_used_partitions(restore_from, &restore_from->num_used_partitions);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    INFO("Successfully restored %s GPT table\n", is_primary ? "backup" : "primary");

    return 0;
}

/* Comparison function to pass to qsort */
static int cmp_u64(const void *a, const void *b)
{
    const uint64_t *a_u64 = (const uint64_t *)a;
    const uint64_t *b_u64 = (const uint64_t *)b;

    return (*a_u64 > *b_u64) - (*a_u64 < *b_u64);
}

/* bsearch but returns the index rather than the item */
static int64_t bsearch_index(const uint64_t arr[], uint32_t len, uint64_t key)
{
    uint32_t l = 0;
    uint32_t r = len;

    while (l < r) {
        uint32_t m = l + (r - l) / 2;
        uint64_t item = arr[m];

        if (item < key) {
            l = m + 1;
        } else if (item > key) {
            r = m;
        } else {
            return (int64_t)m;
        }
    }

    return -1;
}

/* Sorts the partition array for the given primary GPT by the start LBA for each
 * partition. This makes defragmentation easier.
 */
static psa_status_t sort_partition_array(struct gpt_t *primary_table)
{
    if (primary_table->num_used_partitions == 0) {
        assert(primary_table->num_used_partitions > 0);
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    /* To avoid as much I/O as possible, the LBA's for each entry are sorted in
     * memory and then the entries rearranged on flash after
     */
    uint64_t lba_arr[primary_table->num_used_partitions];
    psa_status_t ret;

    for (uint32_t i = 0; i < primary_table->num_used_partitions; ++i) {
        struct gpt_entry_t entry;

        ret = read_entry_from_flash(primary_table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        lba_arr[i] = entry.start;
    }

    qsort(lba_arr, primary_table->num_used_partitions, sizeof(uint64_t), cmp_u64);

    /* Now read and place the entries in the correct spot, starting with the
     * first. Each entry is dealt with as it is encountered. When an entry is
     * found and already in the correct spot, the next smallest index not yet
     * handled becomes the next.
     */
    struct gpt_entry_t saved_entry = {0};
    struct gpt_entry_t curr_entry;
    uint8_t handled_indices[primary_table->num_used_partitions];

    memset(handled_indices, 0, primary_table->num_used_partitions);

    ret = read_entry_from_flash(primary_table, 0, &curr_entry);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    for (uint32_t i = 0; i < primary_table->num_used_partitions; ++i) {
        const int64_t new_index = bsearch_index(
                lba_arr,
                primary_table->num_used_partitions,
                curr_entry.start);
        if (new_index < 0) {
            ERROR("Encountered unknown partition entry!\n");
            return PSA_ERROR_STORAGE_FAILURE;
        }

        /* For final entry, just write it out */
        if (i == primary_table->num_used_partitions - 1) {
            ret = write_entry(primary_table, (uint32_t)new_index, &curr_entry);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
            break;
        }

        /* Replace the entry in the new_index place with the current entry */
        ret = read_entry_from_flash(primary_table, (uint32_t)new_index, &saved_entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        struct efi_guid_t saved_guid = saved_entry.unique_guid;
        struct efi_guid_t curr_guid = curr_entry.unique_guid;

        if (efi_guid_cmp(&saved_guid, &curr_guid) == 0) {
            /* This entry is already where it needs to be, so try the smallest
             * index not yet handled next
             */
            handled_indices[new_index] = 1;
            uint32_t next_entry = 0;

            while (next_entry < primary_table->num_used_partitions &&
                   handled_indices[next_entry]) {
                ++next_entry;
            }

            if (next_entry == primary_table->num_used_partitions) {
                /* Done everything */
                break;
            }

            ret = read_entry_from_flash(primary_table, next_entry, &saved_entry);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
        } else {
            ret = write_entry(primary_table, (uint32_t)new_index, &curr_entry);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
        }

        /* Ready up for the next loop */
        curr_entry = saved_entry;
        handled_indices[new_index] = 1;
    }

    return PSA_SUCCESS;
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file
 * Implentation of common definitons across GPT modules
 */


#include <string.h>
#include <stdint.h>

#include "gpt_defs.h"
#include "io/gpt_io_read.h"
#include "psa/error.h"
#include "tfm_log.h"

#include "efi_soft_crc.h"

/* The LBA for the backup table */
static uint64_t backup_gpt_lba = 0;

/* The LBA for the primary table partition array LBA */
static uint64_t primary_gpt_array_lba = 0;

/* The LBA for the backup table partition array LBA */
static uint64_t backup_gpt_array_lba = 0;

/* Maximum partitions on platform */
static uint32_t plat_max_partitions = 0;

/* Helper function prototypes */
static psa_status_t validate_backup_gpt_lba(const uint64_t backup_lba,
                                            const uint64_t primary_lba,
                                            const uint64_t partition_array_end,
                                            const struct gpt_header_t *header);
static psa_status_t validate_array_lba(const uint64_t partition_array_end,
                                       const uint64_t usable_lba_start);

uint64_t get_backup_gpt_lba(void)
{
    return backup_gpt_lba;
}

void set_backup_gpt_lba(uint64_t new_value)
{
    backup_gpt_lba = new_value;
}

uint64_t get_gpt_array_lba(bool is_primary)
{
    return is_primary ? primary_gpt_array_lba : backup_gpt_array_lba;
}

void set_gpt_array_lba(uint64_t new_value, bool is_primary)
{
    if (is_primary) {
        primary_gpt_array_lba = new_value;
    } else {
        backup_gpt_array_lba = new_value;
    }
}

uint32_t get_plat_max_partitions(void)
{
    return plat_max_partitions;
}

void set_plat_max_partitions(uint32_t new_value)
{
    plat_max_partitions = new_value;
}

uint64_t gpt_entry_per_lba_count(void)
{
    return TFM_GPT_BLOCK_SIZE / GPT_ENTRY_SIZE;
}

uint64_t partition_entry_lba(const struct gpt_t *table,
                             uint32_t            array_index)
{
    return table->header.array_lba + (array_index / gpt_entry_per_lba_count());
}

uint64_t partition_array_last_lba(const struct gpt_t *table)
{
    return (table->num_used_partitions == 0 ?
            table->header.array_lba :
            partition_entry_lba(table, table->num_used_partitions - 1));
}

/* Compare the entry with the given guid */
bool gpt_entry_cmp_guid(const struct gpt_entry_t *entry, const void *guid)
{
    const struct efi_guid_t *cmp_guid = (const struct efi_guid_t *)guid;
    const struct efi_guid_t entry_guid = entry->unique_guid;

    return efi_guid_cmp(&entry_guid, cmp_guid) == 0;
}

/* Read entry with given GUID from given table and return it if found. */
psa_status_t find_gpt_entry(const struct gpt_t        *table,
                            gpt_entry_cmp_t            compare,
                            const void                *cmp_attr,
                            const uint32_t             repeat_index,
                            struct gpt_entry_t        *entry,
                            uint32_t                  *array_index)
{
    if (table->num_used_partitions == 0) {
        return PSA_ERROR_DOES_NOT_EXIST;
    }

    uint32_t num_found = 0;
    bool io_failure = false;

    for (uint32_t i = 0; i < table->num_used_partitions; ++i) {
        const psa_status_t ret = read_entry_from_flash(table, i, entry);

        if (ret != PSA_SUCCESS) {
            /* This might not have been the partition being sought after anyway,
             * so may as well try the rest
             */
            io_failure = true;
            continue;
        }

        if (compare(entry, cmp_attr) && num_found++ == repeat_index) {
            if (array_index != NULL) {
                *array_index = i;
            }
            return PSA_SUCCESS;
        }
    }

    return io_failure ? PSA_ERROR_STORAGE_FAILURE : PSA_ERROR_DOES_NOT_EXIST;
}

psa_status_t count_used_partitions(const struct gpt_t *table,
                                          uint32_t *num_used)
{
    for (uint32_t i = 0; i < table->header.num_partitions; ++i) {
        struct gpt_entry_t entry = {0};
        const psa_status_t ret = read_entry_from_flash(table, i, &entry);

        if (ret != PSA_SUCCESS) {
            return ret;
        }

        const struct efi_guid_t null_guid = NULL_GUID;
        const struct efi_guid_t entry_guid = entry.partition_type;

        if (efi_guid_cmp(&null_guid, &entry_guid) == 0) {
            *num_used = i;
            return PSA_SUCCESS;
        }
    }

    *num_used = table->header.num_partitions;
    return PSA_SUCCESS;
}

psa_status_t validate_table(struct gpt_t *table, bool is_primary)
{
    struct gpt_header_t *header = &(table->header);

    /* Check signature */
    if (strncmp(header->signature, GPT_SIG, GPT_SIG_LEN) != 0) {
        ERROR("Invalid GPT signature\n");
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Check header CRC */
    uint32_t calc_crc = 0;
    uint32_t old_crc = header->header_crc;

    header->header_crc = 0;

    calc_crc = efi_soft_crc32_update(calc_crc, (uint8_t *)header, GPT_HEADER_SIZE);
    header->header_crc = old_crc;

    if (old_crc != calc_crc) {
        ERROR("CRC of header does not match, expected 0x%x got 0x%x\n",
             old_crc, calc_crc);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Check MyLBA field points to this table */
    const uint64_t table_lba = (is_primary ? PRIMARY_GPT_LBA : get_backup_gpt_lba());

    if (table_lba != header->current_lba) {
        ERROR("MyLBA not pointing to this GPT, expected 0x%08x%08x, got 0x%08x%08x\n",
                (uint32_t)(table_lba >> 32),
                (uint32_t)table_lba,
                (uint32_t)(header->current_lba >> 32),
                (uint32_t)(header->current_lba));
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Check the entry size. This is not a part of the spec but ensures the
     * library only supports entry sizes equal to 128. Otherwise, the backup
     * could be used to restore the primary with an entry size that is different
     * and break that assumption, or vise-versa
     */
    if (header->entry_size != GPT_ENTRY_SIZE) {
        ERROR("Unsupported entry size 0x%08x, must be 0x%08x\n",
                header->entry_size, GPT_ENTRY_SIZE);
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Check the CRC of the partition array */
    calc_crc = 0;
    for (uint32_t i = 0; i < header->num_partitions; ++i) {
        uint8_t entry_buf[GPT_ENTRY_SIZE] = {0};
        struct gpt_entry_t *entry = (struct gpt_entry_t *)entry_buf;

        psa_status_t ret = read_entry_from_flash(table, i, entry);

        if (ret != PSA_SUCCESS) {
            return ret;
        }
        calc_crc = efi_soft_crc32_update(calc_crc, (uint8_t *)entry, GPT_ENTRY_SIZE);
    }

    if (calc_crc != header->array_crc) {
        ERROR("CRC of partition array does not match, expected 0x%x got 0x%x\n",
                calc_crc, header->array_crc);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    /* Check the backup LBA is greater than all other LBAs. Check also
     * the partition array cannot be overritten by data by ensuring
     * that it is not between the first and last usable LBAs
     */
    if (is_primary) {
        psa_status_t ret = validate_backup_gpt_lba(
                header->backup_lba,
                header->current_lba,
                partition_entry_lba(table, header->num_partitions - 1),
                header);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        /* Go to the final LBA of the partition array, including unused entries */
        ret = validate_array_lba(
                partition_entry_lba(table, header->num_partitions - 1),
                header->first_lba);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    } else {
        psa_status_t ret = validate_backup_gpt_lba(
                header->current_lba,
                header->backup_lba,
                partition_entry_lba(table, header->num_partitions - 1),
                header);
        if (ret != PSA_SUCCESS) {
            return ret;
        }

        /* To flip the condition, negate the parameters passed: it becomes
         * -array_lba >= -last_lba (equivalent to) array_lba < last_lba
         * (equivalent to) last_lba >= array_lba. This is because the backup array is
         * after the last_lba
         */
        ret = validate_array_lba(~(header->array_lba), ~(header->last_lba));
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    if (is_primary) {
        /* Any time the primary table is considered valid, cache the backup
         * LBA field
         */
        set_backup_gpt_lba(header->backup_lba);
    }

    /* Cache the array LBA field */
    set_gpt_array_lba(header->array_lba, is_primary);

    return PSA_SUCCESS;
}

psa_status_t unicode_to_ascii(const char *unicode, char *ascii)
{
    /* Check whether the unicode string is valid */
    if (unicode[0] == '\0') {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    for (int i = 1; i < GPT_ENTRY_NAME_LENGTH; i += 2) {
        if (unicode[i] != '\0') {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    /* Convert the unicode string to ascii string */
    for (int i = 0; i < GPT_ENTRY_NAME_LENGTH; i += 2) {
        ascii[i >> 1] = unicode[i];
        if (unicode[i] == '\0') {
            break;
        }
    }

    return PSA_SUCCESS;
}

void print_guid(struct efi_guid_t guid)
{
    INFO("%04x%04x-%04x-%04x-%04x-%04x%04x%04x\n",
            ((uint16_t *)&guid)[0],
            ((uint16_t *)&guid)[1],
            ((uint16_t *)&guid)[2],
            ((uint16_t *)&guid)[3],
            ((uint16_t *)&guid)[4],
            ((uint16_t *)&guid)[5],
            ((uint16_t *)&guid)[6],
            ((uint16_t *)&guid)[7]);
}

void dump_table(const struct gpt_t *table, bool header_only)
{
    /* Print the header first */
    const struct gpt_header_t *header = &(table->header);

    INFO("----------\n");
    INFO("Signature: %8s\n", header->signature);
    INFO("Revision: 0x%08x\n", header->revision);
    INFO("HeaderSize: 0x%08x\n", header->size);
    INFO("HeaderCRC32: 0x%08x\n", header->header_crc);
    INFO("Reserved: 0x%08x\n", header->reserved);
    INFO("MyLBA: 0x%08x%08x\n",
            (uint32_t)(header->current_lba >> 32),
            (uint32_t)(header->current_lba));
    INFO("AlternateLBA: 0x%08x%08x\n",
            (uint32_t)(header->backup_lba >> 32),
            (uint32_t)(header->backup_lba));
    INFO("FirstUsableLBA: 0x%08x%08x\n",
            (uint32_t)(header->first_lba >> 32),
            (uint32_t)(header->first_lba));
    INFO("LastUsableLBA: 0x%08x%08x\n",
            (uint32_t)(header->last_lba >> 32),
            (uint32_t)(header->last_lba));
    INFO("DiskGUID: ");
    print_guid(header->flash_guid);
    INFO("ParitionEntryLBA: 0x%08x%08x\n",
            (uint32_t)(header->array_lba >> 32),
            (uint32_t)(header->array_lba));
    INFO("NumberOfPartitionEntries: 0x%08x\n", header->num_partitions);
    INFO("SizeOfPartitionEntry: 0x%08x\n", header->entry_size);
    INFO("PartitionEntryArrayCRC32: 0x%08x\n", header->array_crc);
    INFO("----------\n");

    if (!header_only) {
        /* Now print meta-data for each entry, including those not in use */
        for (uint32_t i = 0; i < table->num_used_partitions; ++i) {
            struct gpt_entry_t entry;
            psa_status_t ret = read_entry_from_flash(table, i, &entry);

            if (ret != PSA_SUCCESS) {
                continue;
            }

            INFO("Entry number: %u\n", i);
            INFO("\tPartitionTypeGUID: ");
            print_guid(entry.partition_type);
            INFO("\tUniquePartitionGUID: ");
            print_guid(entry.unique_guid);
            INFO("\tStartingLBA: 0x%08x%08x\n",
                    (uint32_t)(entry.start >> 32),
                    (uint32_t)(entry.start));
            INFO("\tEndingLBA: 0x%08x%08x\n",
                    (uint32_t)(entry.end >> 32),
                    (uint32_t)(entry.end));
            INFO("\tAttributes: 0x%08x%08x\n",
                    (uint32_t)(entry.attr >> 32),
                    (uint32_t)(entry.attr));
            char name[GPT_ENTRY_NAME_LENGTH >> 1];

            if (unicode_to_ascii(entry.name, name) != PSA_SUCCESS) {
                INFO("\tPartitionName: [Not valid ascii]\n");
            } else {
                INFO("\tPartitionName: %s\n", name);
            }
        }
    }
}

static psa_status_t validate_backup_gpt_lba(const uint64_t backup_lba,
                                            const uint64_t primary_lba,
                                            const uint64_t partition_array_end,
                                            const struct gpt_header_t *header)
{
    if (backup_lba <= primary_lba) {
        ERROR("Backup LBA must be final LBA on flash\n");
        ERROR("backup: 0x%08x%08x, primary: 0x%08x%08x\n",
              (uint32_t)(backup_lba >> 32),
              (uint32_t)(backup_lba),
              (uint32_t)(primary_lba >> 32),
              (uint32_t)(primary_lba));
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (backup_lba <= header->first_lba) {
        ERROR("Backup LBA must be final LBA on flash\n");
        ERROR("backup: 0x%08x%08x, first usable: 0x%08x%08x\n",
              (uint32_t)(backup_lba >> 32),
              (uint32_t)(backup_lba),
              (uint32_t)(header->first_lba >> 32),
              (uint32_t)(header->first_lba));
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (backup_lba <= header->last_lba) {
        ERROR("Backup LBA must be final LBA on flash\n");
        ERROR("backup: 0x%08x%08x, last usable: 0x%08x%08x\n",
              (uint32_t)(backup_lba >> 32),
              (uint32_t)(backup_lba),
              (uint32_t)(header->last_lba >> 32),
              (uint32_t)(header->last_lba));
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (backup_lba <= partition_array_end) {
        ERROR("Backup LBA must be final LBA on flash\n");
        ERROR("backup: 0x%08x%08x, partition array end: 0x%08x%08x\n",
              (uint32_t)(backup_lba >> 32),
              (uint32_t)(backup_lba),
              (uint32_t)(partition_array_end >> 32),
              (uint32_t)(partition_array_end));
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    return PSA_SUCCESS;
}

/* Validate partition array is outside the area of usable flash */
static psa_status_t validate_array_lba(const uint64_t partition_array_end,
                                       const uint64_t usable_lba_start)
{
    if (partition_array_end >= usable_lba_start) {
        ERROR("GPT partition array must not be in usable space\n");
        ERROR("array end: 0x%08x%08x, usable start: 0x%08x%08x\n",
              (uint32_t)(partition_array_end >> 32),
              (uint32_t)partition_array_end,
              (uint32_t)(usable_lba_start >> 32),
              (uint32_t)usable_lba_start);
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    return PSA_SUCCESS;
}

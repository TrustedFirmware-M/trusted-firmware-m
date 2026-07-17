/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "gpt.h"
#include "gpt_defs.h"
#include "io/gpt_io.h"
#include "io/gpt_io_read.h"

/* Include files needed for handling caching */
#include "io/gpt_io_write.h"

#include "efi_guid_structs.h"
#include "tfm_log.h"

/* Helper function prototypes */
static inline void parse_entry(const struct gpt_entry_t *entry,
                               struct partition_entry_t *partition_entry);
static bool gpt_entry_cmp_name(const struct gpt_entry_t *entry, const void *name);
static bool gpt_entry_cmp_type(const struct gpt_entry_t *entry, const void *type);

/* PUBLIC API FUNCTIONS */

psa_status_t gpt_entry_read(const struct efi_guid_t  *guid,
                            struct partition_entry_t *partition_entry)
{
    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(primary_table, gpt_entry_cmp_guid, guid, 0, &cached_entry, NULL);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    parse_entry(&cached_entry, partition_entry);

    return PSA_SUCCESS;
}

psa_status_t gpt_entry_read_by_name(const char                name[GPT_ENTRY_NAME_LENGTH],
                                    const uint32_t            index,
                                    struct partition_entry_t *partition_entry)
{
    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(primary_table, gpt_entry_cmp_name, name, index, &cached_entry, NULL);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    parse_entry(&cached_entry, partition_entry);

    return PSA_SUCCESS;
}

psa_status_t gpt_entry_read_by_type(const struct efi_guid_t  *type,
                                    const uint32_t            index,
                                    struct partition_entry_t *partition_entry)
{
    struct gpt_t *primary_table;
    struct gpt_entry_t cached_entry;
    psa_status_t ret = read_table(&primary_table, true);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = find_gpt_entry(primary_table, gpt_entry_cmp_type, type, index, &cached_entry, NULL);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    parse_entry(&cached_entry, partition_entry);

    return PSA_SUCCESS;
}

psa_status_t gpt_init(struct gpt_flash_driver_t *flash_driver, uint64_t max_partitions)
{
    invalidate_cached_gpt();
    set_cached_lba(0);
    set_write_buffered(false);

    if (max_partitions < GPT_MIN_PARTITIONS) {
        ERROR("Minimum number of partitions is %d\n", GPT_MIN_PARTITIONS);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* All I/O functions are required */
    if (flash_driver->read == NULL ||
            flash_driver->write == NULL ||
            flash_driver->erase == NULL) {
        ERROR("I/O functions must be defined\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Retain information needed to perform I/O. */
    struct gpt_flash_driver_t *plat_flash_driver = get_plat_flash_driver();
    if (plat_flash_driver == NULL) {
        set_plat_flash_driver(flash_driver);
        plat_flash_driver = flash_driver;
    }
    if (get_plat_max_partitions() == 0) {
        set_plat_max_partitions(max_partitions);
    }
    if (plat_flash_driver->init != NULL) {
        if (plat_flash_driver->init() != 0) {
            ERROR("Unable to initialise flash driver\n");
            return PSA_ERROR_STORAGE_FAILURE;
        }
    }

    struct mbr_t mbr;
    psa_status_t ret = mbr_load(&mbr);

    if (ret != PSA_SUCCESS) {
        goto fail_load;
    }

    /* If the first record has type 0xEE (GPT protective), then the flash uses
     * GPT. Else, treat it as legacy MBR
     */
    struct gpt_t *primary_table;

    if (mbr.partitions[0].os_type == MBR_TYPE_GPT) {
        ret = read_table(&primary_table, true);
    } else {
        ERROR("Unsupported legacy MBR in use\n");
        ret = PSA_ERROR_NOT_SUPPORTED;
    }

    if (ret != PSA_SUCCESS) {
        goto fail_load;
    }

    /* Ensure entry size is supported. */
    if (primary_table->header.entry_size != GPT_ENTRY_SIZE) {
        ERROR("Unsupported entry size 0x%08x, must be 0x%08x\n",
                primary_table->header.entry_size, GPT_ENTRY_SIZE);
        ret = PSA_ERROR_NOT_SUPPORTED;
        goto fail_load;
    }

    /* Read the backup GPT and cache necessary values */
    set_backup_gpt_lba(primary_table->header.backup_lba);
    if (get_backup_gpt_lba() != 0) {
        struct gpt_t *backup_table;

        /* Force a real read from flash */
        invalidate_cached_gpt();
        ret = read_table(&backup_table, false);
        if (ret != PSA_SUCCESS) {
            goto fail_load;
        }

        if (backup_table->header.entry_size != GPT_ENTRY_SIZE) {
            ERROR("Unsupported entry size 0x%08x, must be 0x%08x\n",
                    backup_table->header.entry_size, GPT_ENTRY_SIZE);
            ret = PSA_ERROR_NOT_SUPPORTED;
            goto fail_load;
        }

        /* Ensure the primary is the cached GPT to begin with */
        invalidate_cached_gpt();
        ret = read_table(&primary_table, true);
        if (ret != PSA_SUCCESS) {
            goto fail_load;
        }
    } else {
        WARN("Backup GPT location is unknown!\n");
    }

    /* Count the number of used entries, assuming the array is not sparse */
    ret = count_used_partitions(primary_table, &primary_table->num_used_partitions);
    if (ret != PSA_SUCCESS) {
        goto fail_load;
    }

    return PSA_SUCCESS;

fail_load:
    /* Reset so that the user can try with something else if desired */
    set_plat_flash_driver(NULL);
    set_plat_max_partitions(0);
    set_backup_gpt_lba(0);
    set_cached_lba(0);
    set_gpt_array_lba(0, true);
    set_gpt_array_lba(0, false);
    invalidate_cached_gpt();
    set_write_buffered(false);

    return ret;
}

psa_status_t gpt_uninit(void)
{
    psa_status_t ret = PSA_SUCCESS;
    struct gpt_flash_driver_t *flash_driver = get_plat_flash_driver();

    if (flash_driver) {
        /* Flush the in-memory buffer */
        if (is_write_buffered()) {
            /* A table should be cached to be in this scenario */
            struct gpt_t *primary_table;
            ret = read_table(&primary_table, true);
            if (ret != PSA_SUCCESS) {
                return ret;
            }

            ret = flush_lba_buf(primary_table);
        }

        /* Uninitialise driver if function provided */
        if (flash_driver->uninit != NULL) {
            if (flash_driver->uninit() != 0) {
                ERROR("Unable to uninitialise flash driver\n");
                ret = PSA_ERROR_STORAGE_FAILURE;
            }
        }
    }

    set_plat_flash_driver(NULL);
    set_plat_max_partitions(0);
    set_backup_gpt_lba(0);
    set_cached_lba(0);
    set_gpt_array_lba(0, true);
    set_gpt_array_lba(0, false);
    invalidate_cached_gpt();
    set_write_buffered(false);

    return ret;
}

psa_status_t gpt_validate(bool is_primary)
{
    psa_status_t ret;

    if (!is_primary && get_backup_gpt_lba() == 0) {
        ERROR("Backup GPT location unknown!\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    /* Flush and invalidate the in-memory buffer before attempting to validate
     * a table. The in-memory header needs to be updated if the flushed LBA was
     * part of the entry array
     */
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

    ret = read_table(&table, is_primary);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    ret = validate_table(table, is_primary);
    if (ret != PSA_SUCCESS) {
        invalidate_cached_gpt();
        return ret;
    }

    ret = count_used_partitions(table, &table->num_used_partitions);
    if (ret != PSA_SUCCESS) {
        invalidate_cached_gpt();
    }

    return ret;
}

/* Copies information from the entry to the user visible structure */
static inline void parse_entry(const struct gpt_entry_t *entry,
                               struct partition_entry_t *partition_entry)
{
    partition_entry->start = entry->start;
    partition_entry->size = entry->end - entry->start + 1;
    memcpy(partition_entry->name, entry->name, GPT_ENTRY_NAME_LENGTH);
    partition_entry->attr = entry->attr;
    partition_entry->partition_guid = entry->unique_guid;
    partition_entry->type_guid = entry->partition_type;
}

/* Compare the entry with the given name */
static bool gpt_entry_cmp_name(const struct gpt_entry_t *entry, const void *name)
{
    return memcmp(name, entry->name, GPT_ENTRY_NAME_LENGTH) == 0;
}

/* Compare the entry with the given type */
static bool gpt_entry_cmp_type(const struct gpt_entry_t *entry, const void *type)
{
    const struct efi_guid_t *cmp_type = (const struct efi_guid_t *)type;
    const struct efi_guid_t entry_type = entry->partition_type;

    return efi_guid_cmp(&entry_type, cmp_type) == 0;
}

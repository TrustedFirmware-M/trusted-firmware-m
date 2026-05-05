/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "cmsis_compiler.h"
#include "psa/crypto.h"
#include "gpt.h"
#include "gpt_flash.h"
#include "tfm_log.h"
#include "efi_guid_structs.h"
#include "efi_guid.h"
#include "efi_soft_crc.h"

#ifndef __maybe_unused
#define __maybe_unused __attribute__((unused))
#endif

/* This needs to be defined by the platform and is used by the GPT library as
 * the number of bytes in a Logical Block Address (LBA). It also must be at least
 * 512.
 */
#ifndef TFM_GPT_BLOCK_SIZE
#error "TFM_GPT_BLOCK_SIZE must be defined if using GPT library!"
#endif
#if TFM_GPT_BLOCK_SIZE < 512
#error "TFM_GPT_BLOCK_SIZE must be at least 512!"
#endif

/* Where Master Boot Record (MBR) is on flash */
#define MBR_LBA 0ULL

/* Number of unused bytes at the start of the MBR */
#define MBR_UNUSED_BYTES 446

/* Cylinder Head Sector (CHS) length for MBR entry */
#define MBR_CHS_ADDRESS_LEN 3

/* Number of entries in an MBR */
#define MBR_NUM_ENTRIES 4

/* MBR signature as defined by UEFI spec */
#define MBR_SIG 0xAA55

/* Type of MBR partition that indicates GPT in use */
#define MBR_TYPE_GPT 0xEE

/* Default GUID Partition Table (GPT) header size */
#define GPT_HEADER_SIZE 92

/* "EFI PART" (without null byte) */
#define GPT_SIG "EFI PART"
#define GPT_SIG_LEN 8

/* Default partition entry size */
#define GPT_ENTRY_SIZE 128

/* Minimum number of partition entries according to spec */
#define GPT_MIN_PARTITIONS 4

/* Logical Block Address (LBA) for primary GPT */
#define PRIMARY_GPT_LBA 1

/* MBR partition entry - both for protective MBR entry and
 * legacy MBR entry
 */
struct mbr_entry_t {
    /* Indicates if bootable */
    uint8_t status;
    /* For legacy MBR, not used by UEFI firmware. For protective MBR, set to
     * 0x000200
     */
    uint8_t first_sector[MBR_CHS_ADDRESS_LEN];
    /* Type of partition */
    uint8_t os_type;
    /* For legacy MBR, not used by UEFI firmware. For protective MBR, last
     * block on flash.
     */
    uint8_t last_sector[MBR_CHS_ADDRESS_LEN];
    /* For legacy MBR, starting LBA of partition. For protective MBR, set to
     * 0x00000001
     */
    uint32_t first_lba;
    /* For legacy MBR, size of partition. For protective MBR, size of flash
     * minus one
     */
    uint32_t size;
} __PACKED;

/* MBR. This structure is used both for protective MBR and legacy MBR. The boot
 * code, flash signature and unknown sections are not read because they are
 * unused and do not change.
 */
struct mbr_t {
    /* Boot code at offset 0 is unused in EFI */
    /* Unique MBR Disk signature at offset 440 is unused */
    /* The next 2 bytes are also unused */
    /* Array of four MBR partition records. For protective MBR, only the first
     * is valid
     */
    struct mbr_entry_t partitions[MBR_NUM_ENTRIES];
    /* 0xAA55 */
    uint16_t sig;
} __PACKED;

/* A GPT partition entry. */
struct gpt_entry_t {
    struct efi_guid_t partition_type;   /* Partition type, defining purpose */
    struct efi_guid_t unique_guid;      /* Unique GUID that defines each partition */
    uint64_t start;                     /* Starting LBA for partition */
    uint64_t end;                       /* Ending LBA for partition */
    uint64_t attr;                      /* Attribute bits */
    char name[GPT_ENTRY_NAME_LENGTH];   /* Human readable name for partition */
}  __PACKED;

/* The GPT header. */
struct gpt_header_t {
    char signature[GPT_SIG_LEN];    /* "EFI PART" */
    uint32_t revision;              /* Revision number */
    uint32_t size;                  /* Size of this header */
    uint32_t header_crc;            /* CRC of this header */
    uint32_t reserved;              /* Reserved */
    uint64_t current_lba;           /* LBA of this header */
    uint64_t backup_lba;            /* LBA of backup GPT header */
    uint64_t first_lba;             /* First usable LBA */
    uint64_t last_lba;              /* Last usable LBA */
    struct efi_guid_t flash_guid;   /* Disk GUID */
    uint64_t array_lba;             /* First LBA of array of partition entries */
    uint32_t num_partitions;        /* Number of partition entries in array */
    uint32_t entry_size;            /* Size of a single partition entry */
    uint32_t array_crc;             /* CRC of partitions array */
} __PACKED;

/* A GUID partition table in memory. The array is not stored in memory
 * due to its size
 */
struct gpt_t {
    struct gpt_header_t header;     /* GPT header */
    uint32_t num_used_partitions;   /* Number of in-use partitions */
};

/* A function for comparing some gpt entry's attribute with something known.
 * Used to find entries of a certain kind, such as with a particular GUID,
 * name or type.
 */
typedef bool (*gpt_entry_cmp_t)(const struct gpt_entry_t *, const void *);

/* The LBA for the backup table */
static uint64_t backup_gpt_lba = 0;

/* The LBA for the partition array for the backup table. Rather than storing
 * the entire table header in memory, just this is stored so that updates can
 * be done without reading from flash
 */
static uint64_t backup_gpt_array_lba = 0;

/* CRC for backup header. Because the LBAs differ, so too will the CRC */
static uint32_t backup_crc32 = 0;

/* The flash driver, used to perform I/O */
static struct gpt_flash_driver_t *plat_flash_driver = NULL;

/* Maximum partitions on platform */
static uint32_t plat_max_partitions = 0;

/* The primary GPT (also used if legacy MBR, but GPT header and partition
 * entries are zero'd)
 */
static struct gpt_t primary_gpt = {0};

/* Buffer to use for LBA I/O */
static uint8_t lba_buf[TFM_GPT_BLOCK_SIZE] = {0};

/* LBA that is cached in the buffer. Zero is valid only for protective MBR, all
 * other GPT operations must have LBA of one or greater
 */
static uint64_t cached_lba = 0;

/* True if write was buffered */
static bool write_buffered = false;

/* Helper function prototypes */
static __maybe_unused void print_guid(struct efi_guid_t guid);
static __maybe_unused void dump_table(const struct gpt_t *table, bool header_only);
static __maybe_unused psa_status_t unicode_to_ascii(const char *unicode, char *ascii);
static inline uint64_t partition_entry_lba(const struct gpt_t *table,
                                           uint32_t array_index);
static inline uint64_t partition_array_last_lba(const struct gpt_t *table);
static inline uint64_t gpt_entry_per_lba_count(void);
static inline void swap_headers(const struct gpt_header_t *src, struct gpt_header_t *dst);
static psa_status_t count_used_partitions(const struct gpt_t *table,
                                          uint32_t *num_used);
static inline void parse_entry(const struct gpt_entry_t *entry,
                               struct partition_entry_t *partition_entry);
static psa_status_t read_from_flash(uint64_t required_lba);
static psa_status_t read_entry_from_flash(const struct gpt_t *table,
                                          uint32_t array_index,
                                          struct gpt_entry_t *entry);
static psa_status_t read_table_from_flash(struct gpt_t *table, bool is_primary);
static psa_status_t flush_lba_buf(void);
static psa_status_t write_to_flash(uint64_t lba, bool skip_erase);
static psa_status_t write_entries_to_flash(uint32_t lbas_into_array, bool no_header_update);
static psa_status_t write_entry(uint32_t                  array_index,
                                const struct gpt_entry_t *entry,
                                bool                      no_header_update);
static psa_status_t write_header_to_flash(const struct gpt_t *table);
static psa_status_t write_headers_to_flash(void);
static psa_status_t update_header(uint32_t num_partitions);
static psa_status_t find_gpt_entry(const struct gpt_t      *table,
                                   gpt_entry_cmp_t          compare,
                                   const void              *attr,
                                   const uint32_t           repeat_index,
                                   struct gpt_entry_t      *entry,
                                   uint32_t                *array_index);
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
static psa_status_t mbr_load(struct mbr_t *mbr);
static bool gpt_entry_cmp_guid(const struct gpt_entry_t *entry, const void *guid);
static bool gpt_entry_cmp_name(const struct gpt_entry_t *entry, const void *name);
static bool gpt_entry_cmp_type(const struct gpt_entry_t *entry, const void *type);
static psa_status_t validate_backup_gpt_lba(const uint64_t backup_lba,
                                            const uint64_t primary_lba,
                                            const uint64_t partition_array_end,
                                            const struct gpt_header_t *header);
static psa_status_t validate_array_lba(const uint64_t partition_array_end,
                                       const uint64_t usable_lba_start);
static psa_status_t validate_table(struct gpt_t *table, bool is_primary);
static psa_status_t restore_table(struct gpt_t *restore_from, bool is_primary);
static psa_status_t sort_partition_array(const struct gpt_t *table);

/* PUBLIC API FUNCTIONS */

psa_status_t gpt_entry_read(const struct efi_guid_t  *guid,
                            struct partition_entry_t *partition_entry)
{
    struct gpt_entry_t cached_entry;
    const psa_status_t ret = find_gpt_entry(&primary_gpt, gpt_entry_cmp_guid, guid, 0, &cached_entry, NULL);

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
    struct gpt_entry_t cached_entry;
    const psa_status_t ret = find_gpt_entry(&primary_gpt, gpt_entry_cmp_name, name, index, &cached_entry, NULL);

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
    struct gpt_entry_t cached_entry;
    const psa_status_t ret = find_gpt_entry(&primary_gpt, gpt_entry_cmp_type, type, index, &cached_entry, NULL);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    parse_entry(&cached_entry, partition_entry);

    return PSA_SUCCESS;
}

psa_status_t gpt_entry_rename(const struct efi_guid_t *guid, const char name[GPT_ENTRY_NAME_LENGTH])
{
    if (name[0] == '\0') {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    const psa_status_t ret = find_gpt_entry(
            &primary_gpt,
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
    return write_entry(cached_index, &cached_entry, false);
}

psa_status_t gpt_entry_change_type(const struct efi_guid_t *guid, const struct efi_guid_t *type)
{
    struct efi_guid_t null_type = NULL_GUID;
    if (efi_guid_cmp(&null_type, type) == 0) {
        ERROR("Cannot set type to null-GUID; delete instead\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    const psa_status_t ret = find_gpt_entry(
            &primary_gpt,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.partition_type = *type;

    return write_entry(cached_index, &cached_entry, false);
}

psa_status_t gpt_attr_add(const struct efi_guid_t *guid, const uint64_t attr)
{
    /* This quick check prevents I/O from happening for a no-op */
    if (attr == 0) {
        return PSA_SUCCESS;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    const psa_status_t ret = find_gpt_entry(
            &primary_gpt,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr |= attr;

    return write_entry(cached_index, &cached_entry, false);
}

psa_status_t gpt_attr_remove(const struct efi_guid_t *guid, const uint64_t attr)
{
    /* This quick check prevents I/O from happening for a no-op */
    if (attr == 0) {
        return PSA_SUCCESS;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    const psa_status_t ret = find_gpt_entry(
            &primary_gpt,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr &= ~(attr);

    return write_entry(cached_index, &cached_entry, false);
}

psa_status_t gpt_attr_set(const struct efi_guid_t *guid, const uint64_t attr)
{
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    const psa_status_t ret = find_gpt_entry(
            &primary_gpt,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    cached_entry.attr = attr;

    return write_entry(cached_index, &cached_entry, false);
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
    /* Using inequlity here handles when reading an initial GPT has more than
     * the maximum defined number of partitions.
     */
    if (primary_gpt.num_used_partitions >= plat_max_partitions) {
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
    psa_status_t ret = PSA_SUCCESS;
    if (start_lba == 0) {
        /* Use the lowest free LBA possible. Each partition uses contiguous space,
         * so if there is a gap between partitions, that will be shown by the end
         * and start not being contiguous.
         */
        uint64_t prev_end = primary_gpt.header.first_lba;

        for (uint32_t i = 0; i < primary_gpt.header.num_partitions; ++i) {
            struct gpt_entry_t entry = {0};

            ret = read_entry_from_flash(&primary_gpt, i, &entry);
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

    if (start_lba < primary_gpt.header.first_lba ||
            end_lba < primary_gpt.header.first_lba ||
            start_lba > primary_gpt.header.last_lba ||
            end_lba > primary_gpt.header.last_lba) {
        ERROR("Requested partition would not be on disk\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Do not allow overlapping partitions */
    struct gpt_entry_t entry;

    for (uint32_t i = 0; i < primary_gpt.num_used_partitions; ++i) {
        ret = read_entry_from_flash(&primary_gpt, i, &entry);
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

    /* Write the new entry. Skip header update as it is explicitely called
     * below with new number of partitions
     */
    ret = write_entry(primary_gpt.num_used_partitions++, &new_entry, true);
    if (ret != PSA_SUCCESS) {
        --primary_gpt.num_used_partitions;
        return ret;
    }

    /* Flush the buffered LBA if not done so. This will cause the header to be
     * updated
     */
    if (write_buffered) {
        /* flush_lba_buf will update the header */
        ret = flush_lba_buf();
    } else {
        ret = update_header(primary_gpt.num_used_partitions);
    }

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    return PSA_SUCCESS;
}

psa_status_t gpt_entry_remove(const struct efi_guid_t *guid)
{
    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = find_gpt_entry(
            &primary_gpt,
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
    const uint64_t array_end_lba = partition_array_last_lba(&primary_gpt);

    if (cached_index != primary_gpt.num_used_partitions - 1 ||
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
        for (uint64_t i = partition_entry_lba(&primary_gpt, cached_index) + 1;
                i <= array_end_lba;
                ++i) {
            uint8_t array_buf[TFM_GPT_BLOCK_SIZE] = {0};
            int read_ret = plat_flash_driver->read(i, array_buf);

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
            if (backup_gpt_array_lba != 0) {
                ret = write_to_flash(
                        backup_gpt_array_lba + i - 1 - primary_gpt.header.array_lba,
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
    cached_lba = array_end_lba;
    write_buffered = false;
    uint32_t entries_in_last_lba = (--primary_gpt.num_used_partitions) % gpt_entry_per_lba_count();

    if (entries_in_last_lba == 0) {
        /* There's nothing left in this LBA, so zero it all and write it out.
         * There is also no need to do an erase just to zero afterwards.
         */
        memset(lba_buf, 0, TFM_GPT_BLOCK_SIZE);
    } else {
        /* Zero what is not needed anymore */
        memset(
                lba_buf + GPT_ENTRY_SIZE * entries_in_last_lba,
                0,
                (gpt_entry_per_lba_count() - entries_in_last_lba) * GPT_ENTRY_SIZE);
    }

    if (backup_gpt_array_lba != 0) {
        ret = write_to_flash(
                backup_gpt_array_lba + array_end_lba - primary_gpt.header.array_lba,
                true);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    ret = write_to_flash(array_end_lba, true);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Update the header after flash changes */
    ret = update_header(primary_gpt.num_used_partitions);

    return ret;
}

psa_status_t gpt_validate(bool is_primary)
{
    if (!is_primary && (backup_gpt_lba == 0 || backup_gpt_array_lba == 0)) {
        ERROR("Backup GPT location unknown!\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    /* Flush and invalidate the in-memory buffer before attempting to validate
     * a table. The in-memory header needs to be updated if the flushed LBA was
     * part of the entry array
     */
    psa_status_t ret;

    if (write_buffered) {
        ret = flush_lba_buf();
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        write_buffered = false;
    }
    cached_lba = 0;

    if (is_primary) {
        return validate_table(&primary_gpt, true);
    } else {
        struct gpt_t backup_gpt;

        ret = read_table_from_flash(&backup_gpt, false);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        return validate_table(&backup_gpt, false);
    }
}

psa_status_t gpt_restore(bool is_primary)
{
    if (!is_primary && (backup_gpt_lba == 0 || backup_gpt_array_lba == 0)) {
        ERROR("Backup GPT location unknown!\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    /* Flush and invalidate the in-memory buffer before attempting to restore a
     * table. The in-memory header needs to be updated if the flushed LBA was
     * part of the entry array
     */
    psa_status_t ret;

    if (write_buffered) {
        ret = flush_lba_buf();
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        write_buffered = false;
    }
    cached_lba = 0;

    if (is_primary) {
        struct gpt_t backup_gpt;

        ret = read_table_from_flash(&backup_gpt, false);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        ret = count_used_partitions(&backup_gpt, &backup_gpt.num_used_partitions);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        return restore_table(&backup_gpt, false);
    } else {
        return restore_table(&primary_gpt, true);
    }
}

psa_status_t gpt_defragment(void)
{
    /* First, sort the partition array according to start LBA. This means that
     * moving partitions towards the start of the flash sequentially is safe
     * and will not result in lost data.
     */
    psa_status_t ret = sort_partition_array(&primary_gpt);

    if (ret != PSA_SUCCESS) {
        ERROR("Unable to defragment flash!\n");
        return ret;
    }

    uint64_t prev_end = primary_gpt.header.first_lba;
    struct gpt_entry_t entry;

    for (uint32_t i = 0; i < primary_gpt.num_used_partitions; ++i) {
        ret = read_entry_from_flash(&primary_gpt, i, &entry);
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

        /* Write the entry change, skipping header update until every entry
         * written
         */
        ret = write_entry(i, &entry, true);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    }

    /* Write everything to flash after defragmentation if not done so already.
     * The previous loop will write the last entry to the LBA buffer, which may
     * or not may not be flushed
     */
    if (write_buffered) {
        return flush_lba_buf();
    }

    return update_header(primary_gpt.num_used_partitions);
}

/* Initialises GPT from first block. */
psa_status_t gpt_init(struct gpt_flash_driver_t *flash_driver, uint64_t max_partitions)
{
    cached_lba = 0;
    write_buffered = false;
    if (max_partitions < GPT_MIN_PARTITIONS) {
        ERROR("Minimum number of partitions is %d\n", GPT_MIN_PARTITIONS);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (flash_driver->read == NULL ||
            flash_driver->write == NULL ||
            flash_driver->erase == NULL) {
        ERROR("I/O functions must be defined\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Retain information needed to perform I/O. */
    if (plat_flash_driver == NULL) {
        plat_flash_driver = flash_driver;
    }
    if (plat_max_partitions == 0) {
        plat_max_partitions = max_partitions;
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
    if (mbr.partitions[0].os_type == MBR_TYPE_GPT) {
        ret = read_table_from_flash(&primary_gpt, true);
    } else {
        ERROR("Unsupported legacy MBR in use\n");
        ret = PSA_ERROR_NOT_SUPPORTED;
    }

    if (ret != PSA_SUCCESS) {
        goto fail_load;
    }

    /* Ensure entry size is supported. */
    if (primary_gpt.header.entry_size != GPT_ENTRY_SIZE) {
        ERROR("Unsupported entry size 0x%08x, must be 0x%08x\n",
                primary_gpt.header.entry_size, GPT_ENTRY_SIZE);
        ret = PSA_ERROR_NOT_SUPPORTED;
        goto fail_load;
    }

    /* Count the number of used entries, assuming the array is not sparese */
    ret = count_used_partitions(&primary_gpt, &primary_gpt.num_used_partitions);
    if (ret != PSA_SUCCESS) {
        goto fail_load;
    }

    /* Read the backup GPT and cache necessary values */
    backup_gpt_lba = primary_gpt.header.backup_lba;
    if (backup_gpt_lba != 0) {
        struct gpt_t backup_gpt;

        ret = read_table_from_flash(&backup_gpt, false);
        if (ret != PSA_SUCCESS) {
            goto fail_load;
        }
        if (backup_gpt.header.entry_size != GPT_ENTRY_SIZE) {
            ERROR("Unsupported entry size 0x%08x, must be 0x%08x\n",
                    backup_gpt.header.entry_size, GPT_ENTRY_SIZE);
            ret = PSA_ERROR_NOT_SUPPORTED;
            goto fail_load;
        }
        backup_gpt_array_lba = backup_gpt.header.array_lba;
    } else {
        WARN("Backup GPT location is unknown!\n");
    }

    return PSA_SUCCESS;

fail_load:
    /* Reset so that the user can try with something else if desired */
    plat_flash_driver = NULL;
    plat_max_partitions = 0;
    backup_gpt_lba = 0;
    backup_gpt_array_lba = 0;
    cached_lba = 0;
    write_buffered = false;

    return ret;
}

psa_status_t gpt_uninit(void)
{
    psa_status_t ret = PSA_SUCCESS;

    if (plat_flash_driver) {
        /* Flush the in-memory buffer */
        if (write_buffered) {
            ret = flush_lba_buf();
        }

        /* Uninitialise driver if function provided */
        if (plat_flash_driver->uninit != NULL) {
            if (plat_flash_driver->uninit() != 0) {
                ERROR("Unable to uninitialise flash driver\n");
                ret = PSA_ERROR_STORAGE_FAILURE;
            }
        }
    }

    plat_flash_driver = NULL;
    plat_max_partitions = 0;
    backup_gpt_lba = 0;
    backup_gpt_array_lba = 0;
    cached_lba = 0;
    write_buffered = false;

    return ret;
}

/* Returns the number of partition entries in each LBA */
static inline uint64_t gpt_entry_per_lba_count(void)
{
    return TFM_GPT_BLOCK_SIZE / GPT_ENTRY_SIZE;
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

/* Compare the entry with the given guid */
static bool gpt_entry_cmp_guid(const struct gpt_entry_t *entry, const void *guid)
{
    const struct efi_guid_t *cmp_guid = (const struct efi_guid_t *)guid;
    const struct efi_guid_t entry_guid = entry->unique_guid;

    return efi_guid_cmp(&entry_guid, cmp_guid) == 0;
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

/* Read entry with given GUID from given table and return it if found. */
static psa_status_t find_gpt_entry(const struct gpt_t        *table,
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

    return move_partition_data(old_entry.start, start, old_entry.size);
}

/* Move a partition, potentially also copying its data but always updating the header */
static psa_status_t move_partition(const struct efi_guid_t *guid,
                                   const uint64_t           start,
                                   const uint64_t           end,
                                   const bool               no_copy)
{
    if (end < start) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Must fit on flash */
    if (start < primary_gpt.header.first_lba ||
            end < primary_gpt.header.first_lba ||
            start > primary_gpt.header.last_lba ||
            end > primary_gpt.header.last_lba) {
        ERROR("Requested move would not be on disk\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct gpt_entry_t cached_entry;
    uint32_t cached_index;
    psa_status_t ret = find_gpt_entry(
            &primary_gpt,
            gpt_entry_cmp_guid,
            guid,
            0,
            &cached_entry,
            &cached_index);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    /* Prevent unecessary I/O */
    if (start == cached_entry.start && end == cached_entry.end) {
        return PSA_SUCCESS;
    }

    /* It is not possible to move a partition such that it overlaps with an
     * existing partition (other than itself). Check the currently cached LBA
     * first, then the others to avoid reading this LBA twice
     */
    struct gpt_entry_t entry;
    const uint64_t checked_lba = cached_lba;
    const uint64_t array_end_lba = partition_array_last_lba(&primary_gpt);
    uint32_t num_entries_in_cached_lba;

    if (cached_lba == array_end_lba) {
        /* If this is 0, then the last LBA is full */
        uint32_t num_entries_in_last_lba =
            primary_gpt.num_used_partitions % gpt_entry_per_lba_count();

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
        memcpy(&entry, lba_buf + (i * GPT_ENTRY_SIZE), GPT_ENTRY_SIZE);

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
    for (uint32_t i = 0; i < primary_gpt.num_used_partitions; ++i) {
        if (partition_entry_lba(&primary_gpt, i) == checked_lba) {
            continue;
        }

        ret = read_entry_from_flash(&primary_gpt, i, &entry);
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

    return write_entry(cached_index, &cached_entry, false);
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

        const ssize_t erase_ret = plat_flash_driver->erase(
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

        const ssize_t erase_ret = plat_flash_driver->erase(new_lba, (size_t)non_overlap_blocks);

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

    write_buffered = false;

    return PSA_SUCCESS;
}

/* Updates the header of the GPT based on new number of partitions */
static psa_status_t update_header(uint32_t num_partitions)
{
    primary_gpt.num_used_partitions = num_partitions;
    struct gpt_header_t *header = &(primary_gpt.header);

    /* Take the CRC of the partition array */
    uint32_t crc = 0;

    for (uint32_t i = 0; i < header->num_partitions; ++i) {
        uint8_t entry_buf[GPT_ENTRY_SIZE] = {0};
        struct gpt_entry_t *entry = (struct gpt_entry_t *)entry_buf;

        psa_status_t ret = read_entry_from_flash(&primary_gpt, i, entry);

        if (ret != PSA_SUCCESS) {
            return ret;
        }
        crc = efi_soft_crc32_update(crc, entry_buf, GPT_ENTRY_SIZE);
    }
    header->array_crc = crc;

    /* Calculate new CRC32 for primary header */
    header->header_crc = 0;
    header->header_crc = efi_soft_crc32_update(0, (uint8_t *)header, GPT_HEADER_SIZE);

    /* Calculate new CRC32 for backup header */
    struct gpt_header_t backup_header = {0};

    swap_headers(header, &backup_header);
    backup_header.header_crc = 0;
    backup_crc32 = efi_soft_crc32_update(0, (uint8_t *)&backup_header, GPT_HEADER_SIZE);

    /* Write headers */
    const psa_status_t ret = write_headers_to_flash();

    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write headers to flash\n");
        return ret;
    }

    return PSA_SUCCESS;
}

/* Load MBR from flash */
static psa_status_t mbr_load(struct mbr_t *mbr)
{
    /* Read the beginning of the first block of flash, which will contain either
     * a legacy MBR or a protective MBR (in the case of GPT). The first
     * MBR_UNUSED_BYTES are unused and so do not need to be considered.
     */
    ssize_t ret = plat_flash_driver->read(MBR_LBA, lba_buf);

    if (ret != TFM_GPT_BLOCK_SIZE) {
        ERROR("Unable to read from flash at block 0x%08x%08x\n",
                (uint32_t)(MBR_LBA >> 32),
                (uint32_t)MBR_LBA);
        return PSA_ERROR_STORAGE_FAILURE;
    }
    memcpy(mbr, lba_buf + MBR_UNUSED_BYTES, sizeof(*mbr));

    /* Check MBR boot signature */
    if (mbr->sig != MBR_SIG) {
        ERROR("MBR signature incorrect\n");
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return PSA_SUCCESS;
}

/* Reads an LBA from the flash device and caches it. If the requested LBA is
 * already cached, this is a no-op
 */
static psa_status_t read_from_flash(uint64_t required_lba)
{
    if (required_lba != cached_lba) {
        if (write_buffered && cached_lba != 0) {
            psa_status_t ret = flush_lba_buf();

            if (ret != PSA_SUCCESS) {
                return ret;
            }
        }
        write_buffered = false;

        ssize_t ret = plat_flash_driver->read(required_lba, lba_buf);

        if (ret != TFM_GPT_BLOCK_SIZE) {
            ERROR("Unable to read from flash at block 0x%08x%08x\n",
                    (uint32_t)(required_lba >> 32),
                    (uint32_t)required_lba);
            return PSA_ERROR_STORAGE_FAILURE;
        }
        cached_lba = required_lba;
    }

    return PSA_SUCCESS;
}

/* Returns the LBA that a particular partition entry is in based on its position
 * in the array
 */
static inline uint64_t partition_entry_lba(const struct gpt_t *table,
                                           uint32_t array_index)
{
    return table->header.array_lba + (array_index / gpt_entry_per_lba_count());
}

/* Returns the last LBA used by the partition entry array */
static inline uint64_t partition_array_last_lba(const struct gpt_t *table)
{
    return (table->num_used_partitions == 0 ?
            table->header.array_lba :
            partition_entry_lba(table, table->num_used_partitions - 1));
}

/* Returns the number of partition entries used in the array, assuming the
 * array is not sparse
 */
static psa_status_t count_used_partitions(const struct gpt_t *table,
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

/* Reads a GPT entry from the given table on flash */
static psa_status_t read_entry_from_flash(const struct gpt_t *table,
                                          uint32_t            array_index,
                                          struct gpt_entry_t *entry)
{
    uint64_t required_lba = partition_entry_lba(table, array_index);
    const psa_status_t ret = read_from_flash(required_lba);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    memcpy(
            entry,
            lba_buf + ((array_index % gpt_entry_per_lba_count()) * GPT_ENTRY_SIZE),
            GPT_ENTRY_SIZE);

    return PSA_SUCCESS;
}

/* Reads a GPT table from flash */
static psa_status_t read_table_from_flash(struct gpt_t *table, bool is_primary)
{
    if (!is_primary && backup_gpt_lba == 0) {
        ERROR("Backup GPT location unknown!\n");
        return PSA_ERROR_STORAGE_FAILURE;
    }

    const psa_status_t ret = read_from_flash(
            is_primary ? PRIMARY_GPT_LBA : backup_gpt_lba);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    memcpy(&(table->header), lba_buf, GPT_HEADER_SIZE);

    return PSA_SUCCESS;
}

/* Writes the in-memory LBA buffer to flash, taking care of multiple writes if
 * needed.
 */
static psa_status_t flush_lba_buf(void)
{
    /* Prevent recursive calls, as the various writes below may attempt to
     * flush, particularly those making multiple writes
     */
    static bool in_flush = false;

    if (in_flush) {
        return PSA_SUCCESS;
    }
    in_flush = true;
    write_buffered = false;
    psa_status_t ret = PSA_SUCCESS;

    /* Commit to flash what is in the buffer. Also update the backup table if
     * the cached LBA was part of the primary table (or vise-versa)
     */
    uint64_t array_size =
        partition_array_last_lba(&primary_gpt) - primary_gpt.header.array_lba + 1;

    if (cached_lba == PRIMARY_GPT_LBA || (backup_gpt_lba != 0 && cached_lba == backup_gpt_lba)) {
        /* Write both backup and primary headers */
        ret = write_headers_to_flash();
    } else if (cached_lba >= primary_gpt.header.array_lba &&
            cached_lba <= partition_array_last_lba(&primary_gpt)) {
        /* Primary array entry. Write to backup and primary array */
        ret = write_entries_to_flash(cached_lba - primary_gpt.header.array_lba, false);
    } else if (backup_gpt_array_lba != 0 &&
            backup_gpt_array_lba <= cached_lba &&
            cached_lba <= backup_gpt_array_lba + array_size - 1) {
        /* Backup array entry. Write to backup and primary array */
        ret = write_entries_to_flash(cached_lba - backup_gpt_array_lba, false);
    } else {
        /* Some other LBA is cached, possibly data. Write it anyway */
        ret = write_to_flash(cached_lba, false);
    }

    in_flush = false;
    return ret;
}

/* Write to the flash at the specified LBA */
static psa_status_t write_to_flash(uint64_t lba, bool skip_erase)
{
    if (!skip_erase) {
        if (plat_flash_driver->erase(lba, 1) != 1) {
            ERROR("Unable to erase flash at LBA 0x%08x%08x\n",
                    (uint32_t)(lba >> 32),
                    (uint32_t)lba);
            return PSA_ERROR_STORAGE_FAILURE;
        }
    }

    if (plat_flash_driver->write(lba, lba_buf) != TFM_GPT_BLOCK_SIZE) {
        ERROR("Unable to program flash at LBA 0x%08x%08x\n",
                (uint32_t)(lba >> 32),
                (uint32_t)lba);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    return PSA_SUCCESS;
}

/* Writes the in-memory buffer to both the primary and backup partition arrays.
 * This should only be used when it is certain that the cached lba is part of
 * either the primary or backup partition array
 */
static psa_status_t write_entries_to_flash(uint32_t lbas_into_array, bool no_header_update)
{
    psa_status_t ret;

    if (backup_gpt_array_lba != 0) {
        ret = write_to_flash(backup_gpt_array_lba + lbas_into_array, false);
        if (ret != PSA_SUCCESS) {
            ERROR("Unable to write entry to backup partition array\n");
            return ret;
        }
    } else {
        WARN("Backup array LBA unknown!\n");
    }

    ret = write_to_flash(primary_gpt.header.array_lba + lbas_into_array, false);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write entry to primary partition array\n");
        return ret;
    }

    /* Update the header unless the user specifies not to, This might be useful
     * if it is known that multiple entries are being written, such as on removal
     * or defragmentation operations
     */
    if (!no_header_update) {
        return update_header(primary_gpt.num_used_partitions);
    }

    return PSA_SUCCESS;
}

/* Writes a GPT entry to flash or the in-memory buffer. The buffer is flushed
 * to both the primary and backup partition entry arrays ocassionally. When the
 * buffer is flushed, the header is updated unless no_header_update is true.
 */
static psa_status_t write_entry(uint32_t                  array_index,
                                const struct gpt_entry_t *entry,
                                bool                      no_header_update)
{
    /* Use this for a very simple, very dumb buffering heuristic. Flush every
     * time an LBA's worth of entries have been written (flush every nth
     * operation).
     */
    static uint32_t num_writes = 0;

    /* First, ensure the entry is part of the buffered block. In most cases,
     * this will be a no-op
     */
    psa_status_t ret = read_from_flash(partition_entry_lba(&primary_gpt, array_index));

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
        write_buffered = false;

        ret = write_entries_to_flash(cached_lba - primary_gpt.header.array_lba, no_header_update);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
    } else {
        write_buffered = true;
    }

    return PSA_SUCCESS;
}

/* Writes GPT header to flash. Returns PSA_SUCCESS on success or a PSA error on failure */
static psa_status_t write_header_to_flash(const struct gpt_t *table)
{
    /* Ensure the in-memory LBA buffer has the header. Because the header is
     * also in memory, there is no need to read it again before writing.
     */
    uint8_t temp_buf[GPT_HEADER_SIZE];

    memcpy(temp_buf, lba_buf, GPT_HEADER_SIZE);
    memcpy(lba_buf, &(table->header), GPT_HEADER_SIZE);
    const psa_status_t ret = write_to_flash(table->header.current_lba, false);

    memcpy(lba_buf, temp_buf, GPT_HEADER_SIZE);

    return ret;
}

/* Writes GPT headers for backup and primary tables to flash. */
static psa_status_t write_headers_to_flash(void)
{
    /* Backup table first, then primary */
    struct gpt_t backup_gpt;

    swap_headers(&(primary_gpt.header), &(backup_gpt.header));
    backup_gpt.header.header_crc = backup_crc32;
    psa_status_t ret = write_header_to_flash(&backup_gpt);

    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write backup GPT header\n");
        return ret;
    }

    ret = write_header_to_flash(&primary_gpt);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write primary GPT header\n");
    }

    return ret;
}

/* Copies one header to another and swaps the fields referring to self
 * and alternate headers. This is useful for primary to backup copies
 * and vice-versa.
 */
static inline void swap_headers(const struct gpt_header_t *src, struct gpt_header_t *dst)
{
    memcpy(dst, src, GPT_HEADER_SIZE);
    dst->backup_lba = src->current_lba;
    dst->current_lba = src->backup_lba;
    dst->array_lba = (src->current_lba == PRIMARY_GPT_LBA ?
            backup_gpt_array_lba :
            primary_gpt.header.array_lba);
}

/* Validate that the backup GPT LBA is greater than all other LBAs in the header
 */
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

/* Validates a specific GPT. */
static psa_status_t validate_table(struct gpt_t *table, bool is_primary)
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
    const uint64_t table_lba = (is_primary ? PRIMARY_GPT_LBA : backup_gpt_lba);

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
        backup_gpt_lba = header->backup_lba;
    } else {
        /* Any time backup table is considered valid, cache its array LBA
         * field and crc32
         */
        backup_gpt_array_lba = header->array_lba;
        backup_crc32 = header->header_crc;
    }
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

    /* Write the header */
    ret = write_header_to_flash(&restore_to);
    if (ret != PSA_SUCCESS) {
        ERROR("Unable to write %s GPT header\n", is_primary ? "backup" : "primary");
        return ret;
    }

    /* The primary GPT is cached in memory */
    if (!is_primary) {
        memcpy(&(primary_gpt.header), &(restore_to.header), GPT_HEADER_SIZE);
        primary_gpt.num_used_partitions = restore_from->num_used_partitions;
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

/* Sorts the partition array for the given table by the start LBA for each
 * partition. This makes defragmentation easier.
 */
static psa_status_t sort_partition_array(const struct gpt_t *table)
{
    if (table->num_used_partitions == 0) {
        assert(table->num_used_partitions > 0);
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    /* To avoid as much I/O as possible, the LBA's for each entry are sorted in
     * memory and then the entries rearranged on flash after
     */
    uint64_t lba_arr[table->num_used_partitions];
    psa_status_t ret;

    for (uint32_t i = 0; i < table->num_used_partitions; ++i) {
        struct gpt_entry_t entry;
        ret = read_entry_from_flash(table, i, &entry);
        if (ret != PSA_SUCCESS) {
            return ret;
        }
        lba_arr[i] = entry.start;
    }

    qsort(lba_arr, table->num_used_partitions, sizeof(uint64_t), cmp_u64);

    /* Now read and place the entries in the correct spot, starting with the
     * first. Each entry is dealt with as it is encountered. When an entry is
     * found and already in the correct spot, the next smallest index not yet
     * handled becomes the next.
     */
    struct gpt_entry_t saved_entry = {0};
    struct gpt_entry_t curr_entry;
    uint8_t handled_indices[table->num_used_partitions];

    memset(handled_indices, 0, table->num_used_partitions);

    ret = read_entry_from_flash(table, 0, &curr_entry);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    for (uint32_t i = 0; i < table->num_used_partitions; ++i) {
        const int64_t new_index = bsearch_index(
                lba_arr,
                table->num_used_partitions,
                curr_entry.start);
        if (new_index < 0) {
            ERROR("Encountered unknown partition entry!\n");
            return PSA_ERROR_STORAGE_FAILURE;
        }

        /* For final entry, just write it out */
        if (i == table->num_used_partitions - 1) {
            ret = write_entry((uint32_t)new_index, &curr_entry, false);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
            break;
        }

        /* Replace the entry in the new_index place with the current entry */
        ret = read_entry_from_flash(table, (uint32_t)new_index, &saved_entry);
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

            while (next_entry < table->num_used_partitions &&
                   handled_indices[next_entry]) {
                ++next_entry;
            }

            if (next_entry == table->num_used_partitions) {
                /* Done everything */
                break;
            }

            ret = read_entry_from_flash(table, next_entry, &saved_entry);
            if (ret != PSA_SUCCESS) {
                return ret;
            }
        } else {
            /* Write, skipping header update until very end */
            ret = write_entry((uint32_t)new_index, &curr_entry, true);
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

/* Converts unicode string to valid ascii */
static psa_status_t unicode_to_ascii(const char *unicode, char *ascii)
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

/* Prints guid in human readable format. Useful for debugging but should never
 * be used in production, hence marked as unused
 */
static void print_guid(struct efi_guid_t guid)
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

/* Dumps header and optionally meta-data about array. Useful for debugging,
 * but should never be used in production, hence marked as unused.
 */
static void dump_table(const struct gpt_t *table, bool header_only)
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
            psa_status_t ret = read_entry_from_flash(&primary_gpt, i, &entry);

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

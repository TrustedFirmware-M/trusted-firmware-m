/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file
 * Common definitions across GPT modules
 */

#ifndef __TFM_GPT_DEFS_H__
#define __TFM_GPT_DEFS_H__

#include <stdbool.h>
#include <stdint.h>

#include "psa/error.h"
#include "gpt.h"
#include "cmsis_compiler.h"
#include "efi_guid_structs.h"

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

/** \brief Where Master Boot Record (MBR) is on flash. */
#define MBR_LBA 0ULL

/** \brief Number of unused bytes at the start of the MBR. */
#define MBR_UNUSED_BYTES 446

/** \brief Cylinder Head Sector (CHS) length for MBR entry. */
#define MBR_CHS_ADDRESS_LEN 3

/** \brief Number of entries in an MBR. */
#define MBR_NUM_ENTRIES 4

/** \brief MBR signature as defined by UEFI spec. */
#define MBR_SIG 0xAA55

/** \brief Type of MBR partition that indicates GPT in use. */
#define MBR_TYPE_GPT 0xEE

/** \brief Default GUID Partition Table (GPT) header size. */
#define GPT_HEADER_SIZE 92

/** \brief GPT signature string, "EFI PART" without the null byte. */
#define GPT_SIG "EFI PART"

/** \brief Length of \ref GPT_SIG in bytes. */
#define GPT_SIG_LEN 8

/** \brief Default partition entry size. */
#define GPT_ENTRY_SIZE 128

/** \brief Minimum number of partition entries according to spec. */
#define GPT_MIN_PARTITIONS 4

/** \brief Logical Block Address (LBA) for primary GPT. */
#define PRIMARY_GPT_LBA 1

/**
 * \brief MBR partition entry.
 *
 * Used for both protective MBR entries and legacy MBR entries.
 */
struct mbr_entry_t {
    /*! Indicates if bootable. */
    uint8_t status;
    /*!
     * For legacy MBR, not used by UEFI firmware. For protective MBR, set to
     * 0x000200.
     */
    uint8_t first_sector[MBR_CHS_ADDRESS_LEN];
    /*! Type of partition. */
    uint8_t os_type;
    /*!
     * For legacy MBR, not used by UEFI firmware. For protective MBR, last block
     * on flash.
     */
    uint8_t last_sector[MBR_CHS_ADDRESS_LEN];
    /*!
     * For legacy MBR, starting LBA of partition. For protective MBR, set to
     * 0x00000001.
     */
    uint32_t first_lba;
    /*!
     * For legacy MBR, size of partition. For protective MBR, size of flash
     * minus one.
     */
    uint32_t size;
} __PACKED;

/**
 * \brief Master Boot Record.
 *
 * This structure is used for both protective MBR and legacy MBR. The boot code,
 * unique MBR disk signature, and unused sections are not represented because
 * they are unused and do not change.
 */
struct mbr_t {
    /*!
     * Array of four MBR partition records. For protective MBR, only the first
     * is valid.
     */
    struct mbr_entry_t partitions[MBR_NUM_ENTRIES];
    /*! MBR signature 0xAA55. */
    uint16_t sig;
} __PACKED;

/** \brief GPT partition entry. */
struct gpt_entry_t {
    struct efi_guid_t partition_type;   /*!< Partition type, defining purpose. */
    struct efi_guid_t unique_guid;      /*!< Unique GUID that defines each partition. */
    uint64_t start;                     /*!< Starting LBA for partition. */
    uint64_t end;                       /*!< Ending LBA for partition. */
    uint64_t attr;                      /*!< Attribute bits. */
    char name[GPT_ENTRY_NAME_LENGTH];   /*!< Human readable name for partition. */
} __PACKED;

/** \brief GPT header. */
struct gpt_header_t {
    char signature[GPT_SIG_LEN];    /*!< "EFI PART". */
    uint32_t revision;              /*!< Revision number. */
    uint32_t size;                  /*!< Size of this header. */
    uint32_t header_crc;            /*!< CRC of this header. */
    uint32_t reserved;              /*!< Reserved. */
    uint64_t current_lba;           /*!< LBA of this header. */
    uint64_t backup_lba;            /*!< LBA of backup GPT header. */
    uint64_t first_lba;             /*!< First usable LBA. */
    uint64_t last_lba;              /*!< Last usable LBA. */
    struct efi_guid_t flash_guid;   /*!< Disk GUID. */
    uint64_t array_lba;             /*!< First LBA of array of partition entries. */
    uint32_t num_partitions;        /*!< Number of partition entries in array. */
    uint32_t entry_size;            /*!< Size of a single partition entry. */
    uint32_t array_crc;             /*!< CRC of partitions array. */
} __PACKED;

/**
 * \brief GUID partition table in memory.
 *
 * The array is not stored in memory due to its size.
 */
struct gpt_t {
    struct gpt_header_t header;     /*!< GPT header. */
    uint32_t num_used_partitions;   /*!< Number of in-use partitions. */
};

/* A function for comparing some gpt entry's attribute with something known.
 * Used to find entries of a certain kind, such as with a particular GUID,
 * name or type.
 */
typedef bool (*gpt_entry_cmp_t)(const struct gpt_entry_t *, const void *);

bool gpt_entry_cmp_guid(const struct gpt_entry_t *entry, const void *guid);
psa_status_t find_gpt_entry(const struct gpt_t        *table,
                            gpt_entry_cmp_t            compare,
                            const void                *cmp_attr,
                            const uint32_t             repeat_index,
                            struct gpt_entry_t        *entry,
                            uint32_t                  *array_index);
psa_status_t count_used_partitions(const struct gpt_t *table,
                                   uint32_t *num_used);

/**
 * \brief Gets the LBA of the backup GPT header.
 *
 * \return Backup GPT header LBA, or 0 if not set.
 */
uint64_t get_backup_gpt_lba(void);

/**
 * \brief Sets the LBA of the backup GPT header.
 *
 * \param[in] new_value New backup GPT header LBA.
 */
void set_backup_gpt_lba(uint64_t new_value);

/**
 * \brief Gets the LBA of the GPT partition entry array.
 *
 * \param[in] is_primary True if GPT is primary, false for backup.
 *
 * \return Partition entry array LBA, or 0 if not set.
 */
uint64_t get_gpt_array_lba(bool is_primary);

/**
 * \brief Sets the LBA of the GPT partition entry array for the table not in memory.
 *
 * \param[in] new_value New alternative partition entry array LBA.
 * \param[in] is_primary True if GPT is primary, false for backup.
 */
void set_gpt_array_lba(uint64_t new_value, bool is_primary);

/**
 * \brief Gets the maximum number of partitions supported by the platform.
 *
 * \return Maximum number of platform partitions.
 */
uint32_t get_plat_max_partitions(void);

/**
 * \brief Sets the maximum number of partitions supported by the platform.
 *
 * \param[in] new_value New maximum number of platform partitions.
 */
void set_plat_max_partitions(uint32_t new_value);

/**
 * \brief Gets the LBA containing a partition entry.
 *
 * \param[in] table GPT table containing the partition entry array metadata.
 * \param[in] array_index Index of the partition entry in the array.
 *
 * \return LBA containing the requested partition entry.
 */
uint64_t partition_entry_lba(const struct gpt_t *table,
                             uint32_t array_index);

/**
 * \brief Gets the last LBA used by a GPT partition entry array.
 *
 * \param[in] table GPT table containing the partition entry array metadata.
 *
 * \return Last LBA used by the partition entry array.
 */
uint64_t partition_array_last_lba(const struct gpt_t *table);

/**
 * \brief Gets the number of GPT partition entries that fit in one LBA.
 *
 * \return Number of partition entries per LBA.
 */
uint64_t gpt_entry_per_lba_count(void);

/**
 * \brief Validates the given GPT.
 *
 * \param[in] table      The table to validate.
 * \param[in] is_primary If the table is the primary GPT or backup.
 *
 * \return PSA_SUCCESS Valid GPT.
 * \return PSA_ERROR_NOT_SUPPORTED Entry size is not 128.
 * \return PSA_ERROR_STORAGE_FAILURE I/O error.
 * \return PSA_ERROR_INVALID_SIGNATURE Table is invalid in some other way.
 */
psa_status_t validate_table(struct gpt_t *table, bool is_primary);

/**
 * \brief Prints a GUID in human-readable format for debugging.
 *
 * \param[in] guid GUID to print.
 */
__maybe_unused void print_guid(struct efi_guid_t guid);

/**
 * \brief Dumps a GPT header and optionally its partition entry metadata.
 *
 * \param[in] table GPT table to dump.
 * \param[in] header_only True to dump only the header, false to include entry metadata.
 */
__maybe_unused void dump_table(const struct gpt_t *table, bool header_only);

/**
 * \brief Converts a GPT unicode string to ASCII.
 *
 * \param[in]  unicode Unicode string to convert.
 * \param[out] ascii Populated ASCII string on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_INVALID_ARGUMENT Empty or invalid unicode string.
 */
__maybe_unused psa_status_t unicode_to_ascii(const char *unicode, char *ascii);

#endif /* __TFM_GPT_DEFS_H__ */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_GPT_H__
#define __TFM_GPT_H__

#include <stdbool.h>
#include <stdint.h>

#include "psa/error.h"
#include "gpt_flash.h"
#include "efi_guid_structs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Name length of a GPT partition entry. */
#define GPT_ENTRY_NAME_LENGTH 72

/**
 * \brief Information about a GPT partition presented to callers.
 */
struct partition_entry_t {
    uint64_t start;                   /**< Start Logical Block Address (LBA) of the partition. */
    uint64_t size;                    /**< Size of the partition in number of LBAs. */
    char name[GPT_ENTRY_NAME_LENGTH]; /**< Human readable name for the partition in unicode. */
    uint64_t attr;                    /**< Attributes associated with the partition. */
    struct efi_guid_t partition_guid; /**< Unique partition GUID. */
    struct efi_guid_t type_guid;      /**< Partition type GUID. */
};

/**
 * \brief Reads the contents of a partition entry identified by a GUID.
 *
 * \param[in]  guid GUID of the partition entry to read.
 * \param[out] partition_entry Populated partition entry on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1, 2)))
psa_status_t gpt_entry_read(const struct efi_guid_t  *guid,
                            struct partition_entry_t *partition_entry);

/**
 * \brief Reads the contents of a partition entry identified by name.
 *
 * \param[in]  name Name of the partition to read in unicode.
 * \param[in]  index Index to read when multiple entries share the same name.
 * \param[out] partition_entry Populated partition entry on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided name at \p index. For example,
 *                                  \p index was 1 (second entry) but only one entry was found.
 */
__attribute__((nonnull(1, 3)))
psa_status_t gpt_entry_read_by_name(const char                name[GPT_ENTRY_NAME_LENGTH],
                                    const uint32_t            index,
                                    struct partition_entry_t *partition_entry);

/**
 * \brief Reads the contents of a partition entry identified by type.
 *
 * \param[in]  type Type of the partition to read.
 * \param[in]  index Index to read when multiple entries share the same type.
 * \param[out] partition_entry Populated partition entry on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided type at \p index. For example,
 *                                  \p index was 1 (second entry) but only one entry was found.
 */
__attribute__((nonnull(1, 3)))
psa_status_t gpt_entry_read_by_type(const struct efi_guid_t  *type,
                                    const uint32_t            index,
                                    struct partition_entry_t *partition_entry);

/**
 * \brief Renames a partition entry.
 *
 * \param[in] guid Entry to rename.
 * \param[in] name New unicode name for the entry.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 * \retval PSA_ERROR_INVALID_ARGUMENT Empty name.
 */
__attribute__((nonnull(1, 2)))
psa_status_t gpt_entry_rename(const struct efi_guid_t *guid,
                              const char name[GPT_ENTRY_NAME_LENGTH]);

/**
 * \brief Changes the type of a partition.
 *
 * \param[in] guid Entry to update.
 * \param[in] type New type GUID.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_INVALID_ARGUMENT \p type is the null GUID.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1, 2)))
psa_status_t gpt_entry_change_type(const struct efi_guid_t *guid,
                                   const struct efi_guid_t *type);

/**
 * \brief Adds attributes to a partition entry.
 *
 * \param[in] guid Entry to modify.
 * \param[in] attr Attributes to add.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_attr_add(const struct efi_guid_t *guid, const uint64_t attr);

/**
 * \brief Removes attributes from a partition entry.
 *
 * \param[in] guid Entry to modify.
 * \param[in] attr Attributes to remove.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_attr_remove(const struct efi_guid_t *guid, const uint64_t attr);

/**
 * \brief Sets attributes for a partition entry.
 *
 * \param[in] guid Entry to modify.
 * \param[in] attr Attributes to set.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_attr_set(const struct efi_guid_t *guid, const uint64_t attr);

/**
 * \brief Moves (or resizes) a partition entry, including the partition data.
 *
 * \param[in] guid Entry to move.
 * \param[in] start New start LBA.
 * \param[in] end New end LBA.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 * \retval PSA_ERROR_INVALID_ARGUMENT Move would overlap with an existing partition.
 * \retval PSA_ERROR_INVALID_ARGUMENT \p end is less than \p start.
 * \retval PSA_ERROR_INVALID_ARGUMENT Part of the partition would move off flash.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_entry_move(const struct efi_guid_t *guid,
                            const uint64_t           start,
                            const uint64_t           end);

/**
 * \brief Moves (or resizes) a partition entry, without moving the partition data.
 *
 * \param[in] guid Entry to move.
 * \param[in] start New start LBA.
 * \param[in] end New end LBA.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 * \retval PSA_ERROR_INVALID_ARGUMENT Move would overlap with an existing partition.
 * \retval PSA_ERROR_INVALID_ARGUMENT \p end is less than \p start.
 * \retval PSA_ERROR_INVALID_ARGUMENT Part of the partition would move off flash.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_entry_move_no_copy(const struct efi_guid_t *guid,
                                    const uint64_t           start,
                                    const uint64_t           end);

/**
 * \brief Duplicates an existing partition entry into new space, including the
 *        partition data.
 *
 * \param[in]  old_guid Entry to duplicate.
 * \param[in]  start    Starting LBA (0 uses the lowest free LBA possible).
 * \param[out] new_guid GUID populated on success for subsequent API calls.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 * \retval PSA_ERROR_INSUFFICIENT_STORAGE Maximum number of partitions reached.
 * \retval PSA_ERROR_INVALID_ARGUMENT New entry would overlap with an existing partition.
 * \retval PSA_ERROR_INVALID_ARGUMENT Part of the partition would be off flash.
 */
__attribute__((nonnull(1, 3)))
psa_status_t gpt_entry_duplicate(const struct efi_guid_t *old_guid,
                                 const uint64_t           start,
                                 struct efi_guid_t       *new_guid);

/**
 * \brief Duplicates an existing partition entry into new space, without copying
 *        the partition data.
 *
 * \param[in]  old_guid Entry to duplicate.
 * \param[in]  start    Starting LBA (0 uses the lowest free LBA possible).
 * \param[out] new_guid GUID populated on success for subsequent API calls.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 * \retval PSA_ERROR_INSUFFICIENT_STORAGE Maximum number of partitions reached.
 * \retval PSA_ERROR_INVALID_ARGUMENT New entry would overlap with an existing partition.
 * \retval PSA_ERROR_INVALID_ARGUMENT Part of the partition would be off flash.
 */
__attribute__((nonnull(1, 3)))
psa_status_t gpt_entry_duplicate_no_copy(const struct efi_guid_t *old_guid,
                                         const uint64_t           start,
                                         struct efi_guid_t       *new_guid);

/**
 * \brief Creates a partition entry in the table.
 *
 * \param[in]  type Partition type.
 * \param[in]  start Starting LBA (0 uses the lowest free LBA possible).
 * \param[in]  size Size of the partition in LBAs.
 * \param[in]  attr Attributes for the partition.
 * \param[in]  name Partition name in unicode.
 * \param[out] guid GUID populated on success for subsequent API calls.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_INSUFFICIENT_STORAGE Maximum number of partitions reached.
 * \retval PSA_ERROR_INVALID_ARGUMENT Partition would extend beyond the flash.
 * \retval PSA_ERROR_INVALID_ARGUMENT New entry would overlap an existing partition, the name is empty,
 *                                    or \p size is zero.
 */
__attribute__((nonnull(1, 5, 6)))
psa_status_t gpt_entry_create(const struct efi_guid_t *type,
                              const uint64_t           start,
                              const uint64_t           size,
                              const uint64_t           attr,
                              const char               name[GPT_ENTRY_NAME_LENGTH],
                              struct efi_guid_t       *guid);

/**
 * \brief Removes a partition entry from the table.
 *
 * \param[in] guid Entry to remove.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_DOES_NOT_EXIST No entry found with the provided GUID.
 */
__attribute__((nonnull(1)))
psa_status_t gpt_entry_remove(const struct efi_guid_t *guid);

/**
 * \brief Validates the GPT.
 *
 * \param[in] is_primary True to validate the primary table, false to validate the backup.
 *
 * \retval PSA_SUCCESS GPT is valid.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_NOT_SUPPORTED Entry size is not 128 bytes
 * \retval PSA_ERROR_INVALID_SIGNATURE GPT is invalid.
 */
psa_status_t gpt_validate(bool is_primary);

/**
 * \brief Restores either the primary or backup GPT from the other copy.
 *
 * \param[in] is_primary True to restore the primary table, false to restore the backup.
 *
 * \retval PSA_SUCCESS GPT restored.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_INVALID_SIGNATURE Restoring GPT invalid; cannot restore.
 */
psa_status_t gpt_restore(bool is_primary);

/**
 * \brief Defragments the GPT, ensuring free space becomes contiguous.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O failure.
 */
psa_status_t gpt_defragment(void);

/**
 * \brief Reads the GPT header from the second block (LBA 1).
 *
 * \param[in] flash_driver Driver used to perform I/O.
 * \param[in] max_partitions Maximum number of allowable partitions.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_INVALID_ARGUMENT \p max_partitions is less than four, or one of the I/O
 *                                    functions defined by \p flash_driver is NULL. The init
 *                                    and uninit functions may be NULL if not required.
 * \retval PSA_ERROR_NOT_SUPPORTED Legacy MBR is used and not GPT.
 * \retval PSA_ERROR_NOT_SUPPORTED Entry size is not 128 bytes
 */
__attribute__((nonnull(1)))
psa_status_t gpt_init(struct gpt_flash_driver_t *flash_driver,
                      uint64_t max_partitions);

/**
 * \brief Uninitialises the library.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t gpt_uninit(void);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_GPT_H__ */

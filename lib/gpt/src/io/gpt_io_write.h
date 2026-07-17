/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file
 * Write I/O functionality
 */

#include <stdbool.h>
#include <stdint.h>

#include "psa/error.h"
#include "gpt_defs.h"
#include "tfm_log.h"

/**
 * \brief Gets whether an LBA buffer write is pending.
 *
 * \return True if buffer not flushed but has data, false otherwise.
 */
bool is_write_buffered(void);

/**
 * \brief Sets whether an LBA buffer write is pending.
 *
 * \param[in] buffered True to indicate write has been buffered
 */
void set_write_buffered(bool buffered);

/**
 * \brief Updates GPT header metadata for a new number of used partitions.
 *
 * \param[in,out] table GPT table whose header is updated.
 * \param[in]     num_partitions New number of used partitions.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t update_header(struct gpt_t *table, uint32_t num_partitions);

/**
 * \brief Flushes the in-memory LBA buffer to flash.
 *
 * \param[in,out] primary_table primary GPT table whose header may be updated
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t flush_lba_buf(struct gpt_t *primary_table);

/**
 * \brief Writes the in-memory LBA buffer to a flash LBA.
 *
 * \param[in] lba LBA to write.
 * \param[in] skip_erase True to skip erasing the LBA before writing.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t write_to_flash(uint64_t lba, bool skip_erase);

/**
 * \brief Writes the in-memory LBA buffer to both GPT partition entry arrays.
 *
 * Writes the in-memory buffer to both the primary and backup partition arrays.
 * This should only be used when it is certain that the cached lba is part of
 * either the primary or backup partition array
 *
 * \param[in,out] primary_table primary GPT table whose header may be updated
 * \param[in] lbas_into_array Offset, in LBAs, into the partition entry array.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t write_entries_to_flash(struct gpt_t *primary_table, uint32_t lbas_into_array);

/**
 * \brief Writes a GPT partition entry to flash or the in-memory LBA buffer.
 *
 * Writes a GPT entry to flash or the in-memory buffer. The buffer is flushed
 * to both the primary and backup partition entry arrays ocassionally. When the
 * buffer is flushed, the header is updated.
 *
 * \param[in,out] primary_table primary GPT table whose header may be updated
 * \param[in] array_index Index of the partition entry in the array.
 * \param[in] entry Partition entry to write.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t write_entry(struct gpt_t             *primary_gpt,
                         uint32_t                  array_index,
                         const struct gpt_entry_t *entry);

/**
 * \brief Writes a GPT header to flash.
 *
 * \param[in] table GPT table containing the header to write.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t write_header_to_flash(const struct gpt_t *table);


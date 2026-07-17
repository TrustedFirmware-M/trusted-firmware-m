/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file
 * Read I/O functionality
 */

#include <stdbool.h>
#include <stdint.h>

#include "psa/error.h"
#include "gpt_defs.h"

/**
 * \brief Reads an LBA from flash into the LBA buffer.
 *
 * \param[in] required_lba LBA to read.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t read_from_flash(uint64_t required_lba);

/**
 * \brief Reads a GPT partition entry from flash.
 *
 * \param[in]  table GPT table containing the partition entry array metadata.
 * \param[in]  array_index Index of the partition entry in the array.
 * \param[out] entry Populated partition entry on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t read_entry_from_flash(const struct gpt_t *table,
                                   uint32_t            array_index,
                                   struct gpt_entry_t *entry);

/**
 * \brief Reads a GPT table header from flash or cache.
 *
 * \param[out] table Pointer to GPT table populated with the loaded header on success.
 * \param[in]  is_primary True to read the primary GPT, false to read the backup GPT.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 */
psa_status_t read_table(struct gpt_t **table, bool is_primary);

/**
 * \brief Invalidates the cached GPT table buffer.
 */
void invalidate_cached_gpt(void);

/**
 * \brief Loads the MBR from flash.
 *
 * \param[out] mbr Populated MBR on success.
 *
 * \retval PSA_SUCCESS Success.
 * \retval PSA_ERROR_STORAGE_FAILURE I/O error.
 * \retval PSA_ERROR_INVALID_ARGUMENT MBR signature is invalid.
 */
psa_status_t mbr_load(struct mbr_t *mbr);

/**
 * \brief Copies a GPT header and swaps the fields that refer to primary and
 *        backup tables.
 *
 * \param[in]  src Source GPT header.
 * \param[out] dst Destination GPT header populated with swapped table fields.
 */
void swap_headers(const struct gpt_header_t *src, struct gpt_header_t *dst);

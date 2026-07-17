/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file
 * Implementation of read I/O functionality
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "io/gpt_io.h"
#include "io/gpt_io_read.h"
#include "psa/error.h"
#include "gpt_defs.h"
#include "gpt_flash.h"
#include "tfm_log.h"

#include "io/gpt_io_write.h"

#include "efi_soft_crc.h"

/* The cached GPT header buffer */
static struct gpt_t cached_gpt = {0};

/* Whether the cached GPT is considered valid */
static bool cached_gpt_read = false;

/* Whether the cached GPT is the primary or backup GPT */
static bool cached_gpt_primary = false;

/* Helper function prototypes */
static psa_status_t read_table_from_flash(struct gpt_t *table, bool is_primary);

void invalidate_cached_gpt(void)
{
    memset(&cached_gpt, 0, sizeof(cached_gpt));
    cached_gpt_read = false;

    /* Assume primary first. It is called "primary" after all */
    cached_gpt_primary = true;
}

psa_status_t read_from_flash(uint64_t required_lba)
{
    uint64_t cached_lba = get_cached_lba();

    if (required_lba != cached_lba) {
        if (is_write_buffered() && cached_lba != 0 && cached_gpt_read) {
            psa_status_t ret;
            if (cached_gpt_primary) {
                ret = flush_lba_buf(&cached_gpt);
            } else {
                struct gpt_t primary_gpt = cached_gpt;
                swap_headers(&(cached_gpt.header), &(primary_gpt.header));
                ret = flush_lba_buf(&primary_gpt);
            }

            if (ret != PSA_SUCCESS) {
                return ret;
            }
        }
        set_write_buffered(false);

        ssize_t ret = get_plat_flash_driver()->read(required_lba, get_lba_buf());

        if (ret != TFM_GPT_BLOCK_SIZE) {
            ERROR("Unable to read from flash at block 0x%08x%08x\n",
                    (uint32_t)(required_lba >> 32),
                    (uint32_t)required_lba);
            return PSA_ERROR_STORAGE_FAILURE;
        }
        set_cached_lba(required_lba);
    }

    return PSA_SUCCESS;
}

psa_status_t read_entry_from_flash(const struct gpt_t *table,
                                   uint32_t            array_index,
                                   struct gpt_entry_t *entry)
{
    uint64_t required_lba = partition_entry_lba(table, array_index);
    const psa_status_t ret = read_from_flash(required_lba);

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    memcpy(entry,
           get_lba_buf() + ((array_index % gpt_entry_per_lba_count()) * GPT_ENTRY_SIZE),
           GPT_ENTRY_SIZE);

    return PSA_SUCCESS;
}

psa_status_t read_table(struct gpt_t **table, bool is_primary)
{
    if (table == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t ret;

    if (cached_gpt_read) {
        if (is_primary == cached_gpt_primary) {
            /* What is cached is what is wanted */
            *table = &cached_gpt;
            return PSA_SUCCESS;
        } else if (get_gpt_array_lba(is_primary) != 0) {
            /* Something is cached, but not what is wanted, so swap the headers,
             * which relies on the partition array LBA being cached
             */
            struct gpt_t alt_gpt;
            swap_headers(&(cached_gpt.header), &(alt_gpt.header));

            /* Now swap the cached values */
            set_gpt_array_lba(cached_gpt.header.array_lba, !is_primary);
            memcpy(&(cached_gpt.header), &(alt_gpt.header), GPT_HEADER_SIZE);
            cached_gpt_primary = is_primary;

            *table = &cached_gpt;
            return PSA_SUCCESS;
        }
    }

    /* The table must be read from flash */
    ret = read_table_from_flash(&cached_gpt, is_primary);
    if (ret != PSA_SUCCESS) {
        return ret;
    }

    *table = &cached_gpt;
    cached_gpt_read = true;
    cached_gpt_primary = is_primary;

    return PSA_SUCCESS;
}

psa_status_t mbr_load(struct mbr_t *mbr)
{
    /* Read the beginning of the first block of flash, which will contain either
     * a legacy MBR or a protective MBR (in the case of GPT). The first
     * MBR_UNUSED_BYTES are unused and so do not need to be considered.
    */
    uint8_t *lba_buf = get_lba_buf();
    ssize_t ret = get_plat_flash_driver()->read(MBR_LBA, lba_buf);

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
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    return PSA_SUCCESS;
}

void swap_headers(const struct gpt_header_t *src, struct gpt_header_t *dst)
{
    memcpy(dst, src, GPT_HEADER_SIZE);
    dst->backup_lba = src->current_lba;
    dst->current_lba = src->backup_lba;
    dst->array_lba = get_gpt_array_lba(src->current_lba != PRIMARY_GPT_LBA);

    /* Calculate header CRC */
    dst->header_crc = 0;
    dst->header_crc = efi_soft_crc32_update(0, (uint8_t *)dst, GPT_HEADER_SIZE);
}

/* Reads a single table from flash */
static psa_status_t read_table_from_flash(struct gpt_t *table, bool is_primary)
{
    psa_status_t ret;
    if (is_primary) {
        ret = read_from_flash(PRIMARY_GPT_LBA);
    } else {
        if (get_backup_gpt_lba() != 0) {
            ret = read_from_flash(get_backup_gpt_lba());
        } else {
            ERROR("Backup GPT header location unknown!");
            return PSA_ERROR_STORAGE_FAILURE;
        }
    }

    if (ret != PSA_SUCCESS) {
        return ret;
    }

    memcpy(&(table->header), get_lba_buf(), GPT_HEADER_SIZE);
    table->num_used_partitions = 0;
    set_gpt_array_lba(table->header.array_lba, is_primary);

    return PSA_SUCCESS;
}

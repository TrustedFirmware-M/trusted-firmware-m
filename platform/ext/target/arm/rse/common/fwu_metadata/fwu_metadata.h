/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file    fwu_metadata.h
 * \brief   PSA FWU metadata from DEN0118
 */

#ifndef __FWU_METADATA_H__
#define __FWU_METADATA_H__

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_compiler.h"
#include "uuid.h"
#include "flash_layout.h"
#include "fwu_config.h"

#define FWU_METADATA_VERSION      2
#define FWU_FW_STORE_DESC_OFFSET  0x20

#define BANK_INVALID    0xffu  /* One or more images corrupted or partially written */
#define BANK_VALID      0xfeu  /* Valid images, but some are in unaccepted state */
#define BANK_ACCEPTED   0xfcu  /* All images valid and accepted */

#define METADATA_REGION_SIZE            0x2000

#define FW_STORE_DESC_SIZE              0x8
#define IMAGE_ENTRY_SIZE                0x20
#define IMAGE_PROPERTIES_SIZE           0x18
#ifndef METADATA_NR_OF_BANKS
#define METADATA_NR_OF_BANKS            2
#endif
#ifndef METADATA_NR_OF_IMAGES
#define METADATA_NR_OF_IMAGES           2
#endif
#define IMAGE_ENTRIES_SIZE              (IMAGE_ENTRY_SIZE + (METADATA_NR_OF_BANKS * IMAGE_PROPERTIES_SIZE))

/* DEN0118 Metadata version 2 */
struct image_properties_t {
    uuid_t img_uuid;    /* UUID of the image in bank */
    uint32_t accepted;  /* Acceptance status */
    uint32_t reserved;
} __PACKED;

struct image_entry_t {
    uuid_t img_type_uuid; /* UUID identifying the image type */
    uuid_t location_uuid; /* UUID of the storage volume where the image is located */
    struct image_properties_t img_bank_info[METADATA_NR_OF_BANKS];
} __PACKED;

struct metadata_fw_store_desc_t {
   uint8_t num_banks;             /* Number of firmware banks */
   uint8_t reserved;              /* Reserved */
   uint16_t num_images;           /* Number of entries in the img_entry array */
   uint16_t img_entry_size;       /* Size in bytes of the fwu_image_entry */
   uint16_t bank_info_entry_size; /* Size of image bank info structure in bytes */
   struct image_entry_t img_entry[METADATA_NR_OF_IMAGES]; /* Image entries */
} __PACKED;

struct fwu_metadata_t {
    uint32_t crc_32;        /* Metadata crc value */
    uint32_t version;       /* Metadata version, must be 2 for this type */
    uint32_t active_index;  /* Bank index from which device boots   */
    uint32_t previous_active_index; /* Previous successfully booted bank index */
    uint32_t metadata_size; /* Size in bytes of complete metadata structure */
    uint16_t descriptor_offset; /* The offset, from the start of this data structure,
                                 * where the fw_store_desc starts (if one exists).
                                 * If the fw_store_desc does not exist, then this
                                 * field must be set to 0.
                                 */
    uint16_t reserved1;
    uint8_t bank_state[4];  /* The state of each bank */
    uint32_t reserved2;
    struct metadata_fw_store_desc_t fw_desc;
} __PACKED;

/**
 * \brief                             Read FWU metadata.
 *
 * \param[in]  offset                 The host flash offset of the metadata to
 *                                    be read.
 * \param[out] metadata               The FWU metadata read from given offset.
 * \return                            0 on success, non-zero on failure.
 */
int read_fwu_metadata(uint64_t offset, struct fwu_metadata_t *metadata);

/**
 * \brief                             Write FWU metadata.
 *
 * \param[in]  offset                 The host flash offset of the metadata to
 *                                    be written.
 * \param[in] metadata                The FWU metadata to be written to given
 *                                    offset.
 * \return                            0 on success, non-zero on failure.
 */
int write_fwu_metadata(uint64_t offset, const struct fwu_metadata_t *metadata);

/**
 * \brief                             Get active index.
 *
 * \param[in]  md_offset              The host flash offset of the metadata to
 *                                    be parsed.
 * \param[out] active_index           Current active index, if not NULL.
 * \param[out] previous_active_index  Previous active index, if not NULL.
 * \return                            0 on success, non-zero on failure.
 */
int get_active_index(uint64_t md_offset,
                     uint8_t *active_index,
                     uint8_t *previous_active_index);

/**
 * \brief                             Retrieve the UUID of the active image from
 *                                    the metadata record.
 *
 * \param[in]  md_offset              The host flash offset of the metadata to
 *                                    be parsed.
 * \param[in]  type_uuid              UUID indicating the image type to query.
 * \param[out] image_uuid             UUID of the active image corresponding to
 *                                    the given type.
 * \return                            0 on success, non-zero on failure.
 */
int get_active_image_uuid_by_type_uuid(uint64_t md_offset,
                                       uuid_t type_uuid,
                                       uuid_t *image_uuid);

#endif /* __FWU_METADATA_H__ */

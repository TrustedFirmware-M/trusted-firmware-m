/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "boot_record.h"
#include "tfm_boot_status.h"
#include "target.h"
#include "../ext/mcuboot/bootutil/include/bootutil/image.h"
#include "../ext/mcuboot/include/flash_map/flash_map.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

/*!
 * \var shared_memory_init_done
 *
 * \brief Indicates whether shared memory area was already initialized.
 *
 */
static uint32_t shared_memory_init_done;

/*!
 * \def SHARED_MEMORY_UNINITIALZED
 *
 * \brief Indicates that shared memory is uninitialized.
 */
#define SHARED_MEMORY_UNINITIALZED (0u)

/*!
 * \def SHARED_MEMORY_INITIALZED
 *
 * \brief Indicates that shared memory was already initialized.
 */
#define SHARED_MEMORY_INITIALZED   (1u)

/*!
 * \brief Add the measurement data of SW component to the shared memory area
 *
 * Measurements data are:
 *  - measurement value:  Hash of the image, read out from the image's manifest
 *                        section.
 *  - measurement type:   Short test description: SHA256, etc.
 *  - signer ID:          Hash of the image public key, read out from the
 *                        image's manifest section.
 *
 * \param[in]  sw_module  Identifier of the SW component
 * \param[in]  hdr        Pointer to the image header stored in RAM
 * \param[in]  fap        Pointer to the flash area where image is stored
 *
 * \return Returns error code as specified in \ref boot_status_err_t
 */
static enum boot_status_err_t
boot_save_sw_measurements(uint8_t sw_module,
                          const struct image_header *hdr,
                          const struct flash_area *fap)
{
    struct image_tlv_info tlv_header;
    struct image_tlv tlv_entry;
    uintptr_t tlv_end, offset;
    uint8_t buf[32];
    int32_t res;
    uint16_t ias_minor;
    enum shared_memory_err_t res2;
    char measure_type[] = "SHA256";

    /* Manifest data is concatenated to the end of the image. It is encoded in
     * TLV format.
     */
    offset = hdr->ih_img_size + hdr->ih_hdr_size;

    res = flash_area_read(fap, offset, &tlv_header, sizeof(tlv_header));
    if (res) {
        return BOOT_STATUS_ERROR;
    }
    if (tlv_header.it_magic != IMAGE_TLV_INFO_MAGIC) {
        return BOOT_STATUS_ERROR;
    }
    tlv_end = offset + tlv_header.it_tlv_tot;
    offset += sizeof(tlv_header);

    /* Iterates over the manifest data and copy the relevant attributes to the
     * shared data area:
     *  - image hash:      SW component measurement value
     *  - public key hash: Signer ID
     */
    for (; offset < tlv_end; offset += sizeof(tlv_entry) + tlv_entry.it_len) {
        res = flash_area_read(fap, offset, &tlv_entry, sizeof(tlv_entry));
        if (res) {
            return BOOT_STATUS_ERROR;
        }

        if (tlv_entry.it_type == IMAGE_TLV_SHA256) {
            /* Get the image's hash value from the manifest section */
            res = flash_area_read(fap, offset + sizeof(tlv_entry),
                                  buf, tlv_entry.it_len);
            if (res) {
                return BOOT_STATUS_ERROR;
            }

            /* Add the image's hash value to the shared data area */
            ias_minor = SET_IAS_MINOR(sw_module, SW_MEASURE_VALUE);
            res2 = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                                ias_minor,
                                                tlv_entry.it_len,
                                                buf);
            if (res2) {
                return BOOT_STATUS_ERROR;
            }

            /* Add the measurement type to the shared data area */
            ias_minor = SET_IAS_MINOR(sw_module, SW_MEASURE_TYPE);
            res2 = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                                ias_minor,
                                                sizeof(measure_type) - 1,
                                                (const uint8_t *)measure_type);
            if (res2) {
                return BOOT_STATUS_ERROR;
            }

#ifdef MCUBOOT_SIGN_RSA
        } else if (tlv_entry.it_type == IMAGE_TLV_KEYHASH) {
            /* Get the hash of the public key from the manifest section */
            res = flash_area_read(fap, offset + sizeof(tlv_entry),
                                  buf, tlv_entry.it_len);
            if (res) {
                return BOOT_STATUS_ERROR;
            }

            /* Add the hash of the public key to the shared data area */
            ias_minor = SET_IAS_MINOR(sw_module, SW_SIGNER_ID);
            res2 = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                                ias_minor,
                                                tlv_entry.it_len,
                                                buf);
            if (res2) {
                return BOOT_STATUS_ERROR;
            }
#endif
        }
    }

    return BOOT_STATUS_OK;
}

/*!
 * \brief Add the security epoch counter of SW component to the shared
 *        memory area
 *
 * \param[in]  sw_module  Identifier of the SW component
 *
 * \return Returns error code as specified in \ref boot_status_err_t
 */
static enum boot_status_err_t
boot_save_sw_epoch(uint8_t sw_module)
{
    /*FixMe: Epoch does not exist in the current MCUBoot image manifest. Use a
     *       hard coded value for now.
     */
    uint32_t epoch = 0;
    uint16_t ias_minor;
    enum shared_memory_err_t res;

    /* Add the security epoch counter of the SW components to the shared data */
    ias_minor = SET_IAS_MINOR(sw_module, SW_EPOCH);
    res = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                       ias_minor,
                                       sizeof(epoch),
                                       (const uint8_t *)&epoch);
    if (res) {
        return BOOT_STATUS_ERROR;
    }

    return BOOT_STATUS_OK;
}

/*!
 * \brief Add a type identifier(short test name) of SW component to the shared
 *        memory area
 *
 * \param[in]  sw_module  Identifier of the SW component
 *
 * \return Returns error code as specified in \ref boot_status_err_t
 */
static enum boot_status_err_t
boot_save_sw_type(uint8_t sw_module)
{
    /*FixMe: Use a hard coded value for now. Later on when multiple image will
     *       be handled by MCUBoot then this must be revisited.
     */
    uint16_t ias_minor;
    enum shared_memory_err_t res;
    char sw_type[] = "NSPE_SPE";

    /* Add the type identifier of the SW component to the shared data area */
    ias_minor = SET_IAS_MINOR(sw_module, SW_TYPE);
    res = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                       ias_minor,
                                       sizeof(sw_type) - 1,
                                       (const uint8_t *)sw_type);
    if (res) {
        return BOOT_STATUS_ERROR;
    }

    return BOOT_STATUS_OK;
}

/*!
 * \brief Add the version of SW component to the shared memory area
 *
 * \param[in]  sw_module  Identifier of the SW component
 * \param[in]  hdr        Pointer to the image header stored in RAM
 *
 * \return Returns error code as specified in \ref boot_status_err_t
 */
static enum boot_status_err_t
boot_save_sw_version(uint8_t sw_module,
                     const struct image_header *hdr)
{
    int32_t cnt;
    enum shared_memory_err_t res;
    char sw_version[14]; /* 8bit.8bit.16bit: 3 + 1 + 3 + 1 + 5 + 1 */
    uint16_t ias_minor;

    /* FixMe: snprintf can be replaced with a custom implementation */
    cnt = snprintf(sw_version, sizeof(sw_version), "%u.%u.%u",
                   hdr->ih_ver.iv_major,
                   hdr->ih_ver.iv_minor,
                   hdr->ih_ver.iv_revision);
    if (cnt < 0 || cnt >= sizeof(sw_version)) {
        return BOOT_STATUS_ERROR;
    }

    /* Add the version of the SW component to the shared data area */
    ias_minor = SET_IAS_MINOR(sw_module, SW_VERSION);
    res = boot_add_data_to_shared_area(TLV_MAJOR_IAS,
                                       ias_minor,
                                       cnt,
                                       (const uint8_t *)sw_version);
    if (res) {
        return BOOT_STATUS_ERROR;
    }

    return BOOT_STATUS_OK;
}

/* See in boot_record.h */
enum shared_memory_err_t
boot_add_data_to_shared_area(uint8_t        major_type,
                             uint16_t       minor_type,
                             size_t         size,
                             const uint8_t *data)
{
    struct shared_data_tlv_entry tlv_entry = {0};
    struct tfm_boot_data *boot_data;
    uint8_t *next_tlv;
    uintptr_t tlv_end, offset;

    boot_data = (struct tfm_boot_data *)BOOT_TFM_SHARED_DATA_BASE;

    /* Check whether first time to call this function. If does then initialise
     * shared data area.
     */
    if (shared_memory_init_done == SHARED_MEMORY_UNINITIALZED) {
        memset((void *)BOOT_TFM_SHARED_DATA_BASE, 0, BOOT_TFM_SHARED_DATA_SIZE);
        boot_data->header.tlv_magic   = SHARED_DATA_TLV_INFO_MAGIC;
        boot_data->header.tlv_tot_len = SHARED_DATA_HEADER_SIZE;
        shared_memory_init_done = SHARED_MEMORY_INITIALZED;
    }

    /* Check whether TLV entry is already added.
     * Get the boundaries of TLV section
     */
    tlv_end = BOOT_TFM_SHARED_DATA_BASE + boot_data->header.tlv_tot_len;
    offset  = BOOT_TFM_SHARED_DATA_BASE + SHARED_DATA_HEADER_SIZE;

    /* Iterates over the TLV section looks for the same entry if found then
     * returns with error: SHARED_MEMORY_OVERWRITE
     */
    for (; offset < tlv_end; offset += tlv_entry.tlv_len) {
        /* Create local copy to avoid unaligned access */
        memcpy(&tlv_entry, (const void *)offset, SHARED_DATA_ENTRY_HEADER_SIZE);
        if (GET_MAJOR(tlv_entry.tlv_type) == major_type &&
            GET_MINOR(tlv_entry.tlv_type) == minor_type) {
            return SHARED_MEMORY_OVERWRITE;
        }
    }

    /* Add TLV entry */
    tlv_entry.tlv_type = SET_TLV_TYPE(major_type, minor_type);
    tlv_entry.tlv_len  = SHARED_DATA_ENTRY_SIZE(size);

    /* Verify overflow of shared area */
    if ((boot_data->header.tlv_tot_len + tlv_entry.tlv_len) >
         BOOT_TFM_SHARED_DATA_SIZE){
        return SHARED_MEMORY_OVERFLOW;
    }

    next_tlv = (uint8_t *)boot_data + boot_data->header.tlv_tot_len;
    memcpy(next_tlv, &tlv_entry, SHARED_DATA_ENTRY_HEADER_SIZE);

    next_tlv += SHARED_DATA_ENTRY_HEADER_SIZE;
    memcpy(next_tlv, data, size);

    boot_data->header.tlv_tot_len += tlv_entry.tlv_len;

    return SHARED_MEMORY_OK;
}

/* See in boot_record.h */
enum boot_status_err_t
boot_save_boot_status(uint8_t sw_module,
                      const struct image_header *hdr,
                      const struct flash_area *fap)
{
    enum boot_status_err_t res;

    res = boot_save_sw_type(sw_module);
    if (res) {
        return res;
    }

    res = boot_save_sw_version(sw_module, hdr);
    if (res) {
        return res;
    }

    res = boot_save_sw_epoch(sw_module);
    if (res) {
        return res;
    }

    res = boot_save_sw_measurements(sw_module, hdr, fap);
    if (res) {
        return res;
    }

    return BOOT_STATUS_OK;
}

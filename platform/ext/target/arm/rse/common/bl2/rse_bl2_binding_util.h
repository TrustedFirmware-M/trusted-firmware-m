/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_BL2_BINDING_UTIL_H__
#define __RSE_BL2_BINDING_UTIL_H__

#include <stdint.h>
#include <stdbool.h>
#include "psa/crypto.h"
#include "bootutil/image.h"
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Find a TLV in UNPROTECTED block, return offset of its VALUE bytes */
/**
 * @brief Searches for an unprotected TLV (Type-Length-Value) entry of a specified type
 *        within a given flash area and image header.
 *
 * This function scans the unprotected TLV area associated with the provided flash area
 * and image header, looking for a TLV entry that matches the specified type. If found,
 * it outputs the offset to the value of the matching TLV entry.
 *
 * @param[in]  fa         Pointer to the flash area structure.
 * @param[in]  hdr        Pointer to the image header structure.
 * @param[in]  type       The TLV type to search for.
 * @param[out] val_off_out Pointer to a variable where the offset of the TLV value will be stored if found.
 *
 * @return 0 on success (TLV entry found), -1 on failure (not found or error).
 */
int find_unprot_tlv(const struct flash_area *fa,
                    const struct image_header *hdr,
                    uint16_t type,
                    uint32_t *val_off_out);

/**
 * @brief Reads a 16-byte unprotected TLV (Type-Length-Value) entry of a specified type.
 *
 * This function searches for an unprotected TLV entry of the given type within the
 * specified flash area and image header. If found, it reads the 16-byte value of the
 * TLV entry into the provided output buffer.
 *
 * @param[in]  fa    Pointer to the flash area structure.
 * @param[in]  hdr   Pointer to the image header structure.
 * @param[in]  type  The TLV type to search for.
 * @param[out] out   Buffer to store the 16-byte TLV value
 * @param[out] out_len Length of the output buffer.
 *
 * @return 0 on success (TLV entry found and read), -1 on failure.
 */
int read_unprot_tlv16(const struct flash_area *fa,
                      const struct image_header *hdr,
                      uint16_t type,
                      uint8_t *out, size_t out_len);
/**
 * @brief Reads the secure counter value from the image TLV area in flash.
 *
 * This function locates and reads the secure counter (SEC_CNT) value from the
 * protected TLV (Type-Length-Value) area of a firmware image stored in flash.
 * It verifies the TLV area magic, iterates through TLV entries, and extracts
 * the SEC_CNT value if present.
 *
 * @param[in]  fa         Pointer to the flash area descriptor.
 * @param[in]  hdr        Pointer to the image header structure.
 * @param[out] sec_cnt_out Pointer to a uint32_t where the secure counter value will be stored.
 *
 * @return 0 on success (SEC_CNT found and read), -1 on failure (e.g., read error, TLV not found).
 */
int read_sec_cnt(const struct flash_area *fa,
                 const struct image_header *hdr,
                 uint32_t *sec_cnt_out);

/**
 * \brief Write a TLV entry into the unprotected TLV area
 *
 * \param[in] fa        Pointer to the flash area
 * \param[in] hdr       Pointer to the image header
 * \param[in] type      Type of the TLV entry
 * \param[in] val       Pointer to the value to write
 * \param[in] val_len   Length of the value
 *
 * \return 0 on success, non-zero error code on failure
 */
int write_unprot_tlv(const struct flash_area *fa,
                     const struct image_header *hdr,
                     uint16_t type, const uint8_t *val,
                     size_t val_len);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_BL2_BINDING_UTIL_H__ */

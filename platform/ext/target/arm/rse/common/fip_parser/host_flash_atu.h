/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __HOST_FLASH_ATU_H__
#define __HOST_FLASH_ATU_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "uuid.h"
#include "gpt.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initializes an ATU slot to the given address range.
 *
 * \param[in] physical_address    Physical address of the ATU slot.
 * \param[in] size                Unaligned slot size.
 * \param[in] boundary            Boundary for alignment checks.
 * \param[in] logical_address     Logical address of the AATU slot.
 *
 * \param[out] alignment_offset   Address offset after alignment.
 * \param[out] atu_slot_size      Slot size after alignment.
 *
 * \return 0 on success, non-zero on failure.
 */
enum tfm_plat_err_t setup_aligned_atu_slot(uint64_t physical_address,
                                           uint32_t size,
                                           uint32_t boundary,
                                           uint32_t logical_address,
                                           uint32_t *alignment_offset,
                                           size_t   *atu_slot_size);

#ifdef RSE_GPT_SUPPORT
/**
 * \brief                  Get the GPT header by setting up an ATU slot.
 *
 * \param[out] header      The GPT header read from flash.
 *
 * \return                 0 on success, non-zero on failure.
 */
int host_flash_atu_get_gpt_header(gpt_header_t *header);

/**
 * \brief Get the partition offset of images of specific type uuid.
 *
 * \param[in] type_uuid           Type UUID of the requested images.
 * \param[in] header              GPT header to search through.
 *
 * \param[out] image_found        Flag indicating whether an image is found.
 * \param[out] image_offset       Offset of found images.
 * \param[out] image_size         Size of found images.
 *
 * \return 0 on success, non-zero on failure.
 */
int host_flash_atu_get_gpt_partition_offset_by_type_uuid(uuid_t type_uuid,
                                                         gpt_header_t header,
                                                         bool *image_found,
                                                         uint64_t *image_offset,
                                                         size_t *image_size);
/**
 * \brief Get the partition offset of images of specific image uuid.
 *
 * \param[in] type_uuid           Image UUID of the requested images.
 * \param[in] header              GPT header to search through.
 *
 * \param[out] image_found        Flag indicating whether an image is found.
 * \param[out] image_offset       Offset of found images.
 * \param[out] image_size         Size of found images.
 *
 * \return 0 on success, non-zero on failure.
 */
int host_flash_atu_get_gpt_partition_offset_by_image_uuid(uuid_t image_uuid,
                                                          gpt_header_t header,
                                                          bool *image_found,
                                                          uint64_t *image_offset,
                                                          uint32_t *image_size);
#endif /* RSE_GPT_SUPPORT */

/**
 * \brief                  Gets the offsets of the FIPs in host flash. If GPT is
 *                         supported these are parsed from the GPT partition
 *                         list, else the hardcoded values are returned.
 *
 * \param[out] fip_found   Which fips were found. If fip_found[x] is 0, then the
 *                         value of fip_offsets[x] is undefined.
 * \param[out] fip_offsets The FIP offsets.
 *
 * \return                 0 on success, non-zero on failure.
 */
int host_flash_atu_get_fip_offsets(bool fip_found[2], uint64_t fip_offsets[2]);

/**
 * \brief                             Set up the input ATU slots so that an
 *                                    image can be loaded from host flash.
 *                                    Parses a FIP via an intermediate ATU slot
 *                                    to find the image offset.
 *
 * \param[in] fip_offset              The host flash offset of the FIP that
 *                                    should be parsed to find the image offset.
 *
 * \param[in] logical_address         The address in RSE memory to which the ATU
 *                                    should map the image.
 *
 * \param[in] image_uuid              The UUID of the image that should have
 *                                    its slot set up. This is used when parsing
 *                                    the FIP for the offset.
 *
 * \param[out] logical_address_offset The offset that the image has been mapped
 *                                    at (so the base of the image is
 *                                    logical_address + logical_address_offset).
 *                                    This is required because images may not be
 *                                    aligned to the ATU page size.
 *
 * \param[out] atu_slot_size          The size of the mapped image.
 *
 * \return                            0 on success, non-zero on failure.
 */
int host_flash_atu_setup_image_input_slots_from_fip(uint64_t fip_offset,
                                                    uintptr_t logical_address,
                                                    uuid_t image_uuid,
                                                    uint32_t *logical_address_offset,
                                                    size_t *atu_slot_size);

/**
 * \brief                             Setup the input slots for a given image.
 *                                    Returns the offsets from the
 *                                    expected logical address that the image
 *                                    has been mapped to (to account for images
 *                                    not being aligned to the ATU page size).
 *
 * \param[in] image_uuid              The UUID of the image that should have
 *                                    its input slot set up.
 *
 * \param[out] offsets                The offsets that the primary and secondary
 *                                    images for that particular UUID have been
 *                                    mapped at (offset from their expected
 *                                    logical addresses).
 *
 * \return                            0 on success, non-zero on failure.
 */
int host_flash_atu_setup_image_input_slots(uuid_t image_uuid, uint32_t offsets[2]);

/**
 * \brief                             Setup the input slots for a
 *                                    given type_uuid. Returns the offsets from
 *                                    the expected logical address that the
 *                                    image has been mapped to (to account for
 *                                    images not being aligned to the ATU page
 *                                    size).
 *
 * \param[in] type_uuid               The type UUID of the image that should
 *                                    have its input slots set up.
 *
 * \param[out] offsets                The offsets that the primary and secondary
 *                                    images for that particular UUID have been
 *                                    mapped at (offset from their expected
 *                                    logical addresses).
 *
 * \return                            0 on success, non-zero on failure.
 */
int host_flash_atu_setup_image_input_slots_by_type_uuid(uuid_t type_uuid, uint32_t offsets[2]);

/**
 * \brief                                  Setup the ATU output slots for a
 *                                         given image and its bootloader header.
 *
 * \param[in]  image_load_phy_addr         Physical address where the image
 *                                         should be written. This address
 *                                         should be aligned to the ATU page
 *                                         size.
 *
 * \param[in]  image_load_logical_addr     Logical address in RSE memory used
 *                                         to access the image data. The
 *                                         header and image will both be
 *                                         mapped into this address. This
 *                                         address should be aligned to the
 *                                         ATU page size.
 *
 * \param[in]  image_max_size              Maximum size of the image to be
 *                                         written, including the bootloader
 *                                         header size.
 *
 * \param[in]  header_phy_addr             Physical address where the image
 *                                         header should be written.
 *
 * \return     0 on success, non-zero on failure.
 */
int host_flash_atu_setup_image_output_slots(uint64_t image_load_phy_addr,
                                            uint32_t image_load_logical_addr,
                                            uint32_t image_max_size,
                                            uint64_t header_phy_addr);

/**
 * \brief                             Teardown all image input slots.
 *                                    Should be called between mapping different
 *                                    images.
 *
 * \return                            0 on success, non-zero on failure.
 */
int host_flash_atu_free_input_image_regions(void);

#ifdef __cplusplus
}
#endif

#endif /* __HOST_FLASH_ATU_H__ */

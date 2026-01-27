/*
 * Copyright (c) 2022-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FIP_PARSER_H__
#define __FIP_PARSER_H__

#include "Driver_Flash.h"
#include "firmware_image_package.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief                    Parse a FIP and retrieve the offset and size of one
 *                           of the firmware images (specified by UUID).
 *
 * \param[in]  flash_dev     The flash device in which the FIP is stored.
 * \param[in]  fip_offset    The RSE address mapped to the FIP offset in
 *                           the flash.
 * \param[in]  atu_slot_size The size of the ATU region that was mapped for
 *                           access to this FIP. This is used to prevent reads
 *                           outside the mapped region.
 * \param[in]  uuid          The UUID of the firmware image to get the offset
 *                           and size of.
 *
 * \param[out] offset        The offset in the flash of the firmware image.
 * \param[out] size          The size of the firmware image.
 *
 * \return                   TFM_PLAT_ERR_SUCCESS if operation completed
 *                           successfully, another value on error.
 */
enum tfm_plat_err_t fip_get_entry_by_uuid(const ARM_DRIVER_FLASH *flash_dev,
                                          uint32_t fip_offset, uint32_t atu_slot_size,
                                          uuid_t uuid, uint64_t *offset, size_t *size);

#ifdef __cplusplus
}
#endif

#endif /* __FIP_PARSER_H__ */

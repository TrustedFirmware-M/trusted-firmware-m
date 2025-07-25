/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "image.h"

#include "Driver_Flash.h"
#include "flash_layout.h"
#include "region_defs.h"
#include "fih.h"

#ifndef TFM_BL1_MEMORY_MAPPED_FLASH
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_BL1;
#endif /* !TFM_BL1_MEMORY_MAPPED_FLASH */

uint32_t __WEAK bl1_image_get_flash_offset(uint32_t image_id)
{
    switch (image_id) {
    case 0:
        return FLASH_AREA_0_OFFSET;
#if defined(MCUBOOT_IMAGE_NUMBER) && (MCUBOOT_IMAGE_NUMBER >= 2)
    case 1:
        return FLASH_AREA_1_OFFSET;
#endif
    default:
        FIH_PANIC;
    }
}

#ifndef TFM_BL1_MEMORY_MAPPED_FLASH
fih_ret bl1_image_copy_to_sram(uint32_t image_id, uint8_t *out)
{
    uint32_t flash_offset;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    flash_offset = bl1_image_get_flash_offset(image_id);

    fih_rc = fih_ret_encode_zero_equality(
                FIH_NOT_EQ(BL2_CODE_SIZE + BL1_2_HEADER_SIZE,
                           (FLASH_DEV_NAME_BL1.ReadData(flash_offset,
                                                        out,
                                                        BL2_CODE_SIZE + BL1_2_HEADER_SIZE))));

    FIH_RET(fih_rc);
}
#endif /* !TFM_BL1_MEMORY_MAPPED_FLASH */

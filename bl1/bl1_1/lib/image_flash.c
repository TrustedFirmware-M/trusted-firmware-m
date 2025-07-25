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

extern ARM_DRIVER_FLASH FLASH_DEV_NAME_BL1;

fih_ret bl1_read_bl1_2_image(uint8_t *image)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    fih_rc = fih_ret_encode_zero_equality(
                FIH_NOT_EQ(BL1_2_CODE_SIZE,
                           (FLASH_DEV_NAME_BL1.ReadData(BL1_2_IMAGE_FLASH_OFFSET,
                                                        image,
                                                        BL1_2_CODE_SIZE))));

    FIH_RET(fih_rc);
}

/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "array.h"
#include "bl2_image_id.h"
#include "Driver_Flash.h"
#include "flash_map/flash_map.h"
#include "host_base_address.h"
#include "target.h"

/* Flash device names must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;
extern ARM_DRIVER_FLASH AP_FLASH_DEV_NAME;

/* Default Drivers list */
const ARM_DRIVER_FLASH *flash_driver[] = {
    &FLASH_DEV_NAME,
    &AP_FLASH_DEV_NAME,
};
const int flash_driver_entry_num = ARRAY_SIZE(flash_driver);

struct flash_area flash_map[] = {
    {
        .fa_id = FLASH_AREA_2_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_2_OFFSET,
        .fa_size = FLASH_AREA_2_SIZE,
    },
    {
        .fa_id = FLASH_AREA_3_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_3_OFFSET,
        .fa_size = FLASH_AREA_3_SIZE,
    },
    {
        .fa_id = FLASH_AREA_4_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_4_OFFSET,
        .fa_size = FLASH_AREA_4_SIZE,
    },
    {
        .fa_id = FLASH_AREA_5_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_5_OFFSET,
        .fa_size = FLASH_AREA_5_SIZE,
    },
    {
        .fa_id = AP_FLASH_AREA_0_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &AP_FLASH_DEV_NAME,
        .fa_off = AP_FLASH_AREA_0_OFFSET,
        .fa_size = AP_FLASH_AREA_0_SIZE,
    },
    {
        .fa_id = AP_FLASH_AREA_1_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &AP_FLASH_DEV_NAME,
        .fa_off = AP_FLASH_AREA_1_OFFSET,
        .fa_size = AP_FLASH_AREA_1_SIZE,
    },
};

const int flash_map_entry_num = ARRAY_SIZE(flash_map);

/*
 * This function is used to validate that the image will load to a region that
 * it can execute from and that the image fits inside the execution region
 * specified.
 *
 * The address that an image is loaded to is specified in the image header.
 *
 * The execution region is specific for a particular firmware to ensure that a
 * firmware image is not loaded to the execution region of a different
 * firmware by comparing the load image address in the image header and
 * exec_ram_start corresponding to the image_id.
 */
int boot_get_image_exec_ram_info(uint32_t image_id,
                                 uint32_t *exec_ram_start,
                                 uint32_t *exec_ram_size)
{
    int rc = 0;

    if (image_id == RSE_FIRMWARE_SECURE_ID) {
        *exec_ram_start = S_IMAGE_LOAD_ADDRESS;
        *exec_ram_size  = SECURE_IMAGE_MAX_SIZE;
    } else if (image_id == RSE_FIRMWARE_AP_BL2_ID) {
        *exec_ram_start = HOST_AP_BL2_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_AP_BL2_ATU_SIZE;
    } else if (image_id == RSE_FIRMWARE_SI_CL0_ID) {
        *exec_ram_start = HOST_SI_CL0_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_SI_CL0_ATU_SIZE;
    } else {
        rc = -1;
    }

    return rc;
}

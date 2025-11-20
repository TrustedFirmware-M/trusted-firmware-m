/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "flash_map/flash_map.h"

#include "Driver_Flash.h"
#include "bl2_image_id.h"
#include "host_base_address.h"
#include "target.h"

#include "tfm_utils.h"

/* Flash device names must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

/* Default Drivers list */
const ARM_DRIVER_FLASH *flash_driver[] = {
    &FLASH_DEV_NAME,
};
const int flash_driver_entry_num = ARRAY_SIZE(flash_driver);

const struct flash_area flash_map[] = {
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
        .fa_id = FLASH_AREA_6_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_6_OFFSET,
        .fa_size = FLASH_AREA_6_SIZE,
    },
    {
        .fa_id = FLASH_AREA_7_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_7_OFFSET,
        .fa_size = FLASH_AREA_7_SIZE,
    },
    {
        .fa_id = FLASH_AREA_8_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_8_OFFSET,
        .fa_size = FLASH_AREA_8_SIZE,
    },
    {
        .fa_id = FLASH_AREA_9_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_9_OFFSET,
        .fa_size = FLASH_AREA_9_SIZE,
    },
    {
        .fa_id = FLASH_AREA_10_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_10_OFFSET,
        .fa_size = FLASH_AREA_10_SIZE,
    },
    {
        .fa_id = FLASH_AREA_11_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_11_OFFSET,
        .fa_size = FLASH_AREA_11_SIZE,
    },
    {
        .fa_id = FLASH_AREA_12_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_12_OFFSET,
        .fa_size = FLASH_AREA_12_SIZE,
    },
    {
        .fa_id = FLASH_AREA_13_ID,
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = FLASH_AREA_13_OFFSET,
        .fa_size = FLASH_AREA_13_SIZE,
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
    int rc = -1;

    if (image_id == RSE_FIRMWARE_SECURE_ID) {
        *exec_ram_start = S_IMAGE_LOAD_ADDRESS;
        *exec_ram_size  = SECURE_IMAGE_MAX_SIZE;
        rc = 0;
    } else if (image_id == RSE_FIRMWARE_NON_SECURE_ID) {
        *exec_ram_start = NS_IMAGE_LOAD_ADDRESS;
        *exec_ram_size  = NON_SECURE_IMAGE_MAX_SIZE;
        rc = 0;
    } else if (image_id == RSE_FIRMWARE_SCP_ID) {
        *exec_ram_start = HOST_SCP_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_SCP_ATU_SIZE;
        rc = 0;
    } else if (image_id == RSE_FIRMWARE_MCP_ID) {
        *exec_ram_start = HOST_MCP_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_MCP_ATU_SIZE;
        rc = 0;
    } else if (image_id == RSE_FIRMWARE_LCP_ID) {
        *exec_ram_start = HOST_LCP_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_LCP_ATU_SIZE;
        rc = 0;
    }
    else if (image_id == RSE_FIRMWARE_AP_BL1_ID) {
        *exec_ram_start = HOST_AP_BL1_IMG_HDR_BASE_S;
        *exec_ram_size  = HOST_AP_BL1_ATU_SIZE;
        rc = 0;
    }

    return rc;
}

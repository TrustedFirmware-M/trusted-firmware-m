/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "partition/flash_layout.h"
#include "coverity_check.h"
#include "tfm_hal_its.h"

TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_6, "This definition overrides weak function")
enum tfm_hal_status_t tfm_hal_its_fs_info(struct tfm_hal_its_fs_info_t *fs_info)
{
    if (fs_info == NULL) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* Infineon devices expect to use relative address to flash region allocated for ITS */
    fs_info->flash_area_addr = 0;
#if ITS_RAM_FS
    fs_info->flash_area_size = ITS_RAM_FS_SIZE;
    fs_info->sectors_per_block = TFM_HAL_ITS_SECTORS_PER_BLOCK;
#else
    fs_info->flash_area_size = TFM_HAL_ITS_FLASH_AREA_SIZE;
    fs_info->sectors_per_block = TFM_HAL_ITS_SECTORS_PER_BLOCK;
#endif

    return TFM_HAL_SUCCESS;
}

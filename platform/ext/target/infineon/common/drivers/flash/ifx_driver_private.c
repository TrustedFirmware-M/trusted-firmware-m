/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_driver_private.h"

int32_t ifx_flash_driver_validate_region(ARM_FLASH_INFO *flash_info,
                                         uint32_t address, uint32_t size)
{
    uint32_t region_size = flash_info->sector_size * flash_info->sector_count;

    /* Validate size */
    if ((size > region_size) || (size == 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Validate address */
    if (address >= region_size) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Validate (address + size) */
    if (address > (region_size - size)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    return ARM_DRIVER_OK;
}

int32_t ifx_flash_driver_initialize(ARM_FLASH_INFO *flash_info,
                                    uint32_t start_address,
                                    uint32_t mem_block_size)
{
    /* Address should be aligned to memory block size */
    if ((start_address % mem_block_size) != 0U) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Uniform sector only */
    if (flash_info->sector_info != NULL) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Non-empty region */
    if (flash_info->sector_count == 0U) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Address sector size should be aligned to memory block size */
    if ((flash_info->sector_size == 0U) ||
        ((flash_info->sector_size % mem_block_size) != 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Page size should be aligned to memory block size */
    if ((flash_info->page_size == 0U) ||
        ((flash_info->page_size % mem_block_size) != 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    if (flash_info->program_unit == 0U) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    return ARM_DRIVER_OK;
}

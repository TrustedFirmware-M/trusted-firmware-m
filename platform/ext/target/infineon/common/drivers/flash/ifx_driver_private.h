/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_DRIVER_PRIVATE_H
#define IFX_DRIVER_PRIVATE_H

#include "ifx_flash_driver_api.h"

/**
 * \brief Validate that memory block is inside of flash driver instance region.
 *
 * \param[in] flash_info    Flash driver info
 * \param[in] address       Start address of memory block
 * \param[in] size          Memory block size
 *
 * \retval ARM_DRIVER_OK
 *         Memory block is inside of flash driver instance region.
 * \retval ARM_DRIVER_ERROR_PARAMETER
 *         Memory block is outside of flash driver instance region.
 *
 * \note \ref instance settings are not validated by this function!
 */
int32_t ifx_flash_driver_validate_region(ARM_FLASH_INFO *flash_info,
                                         uint32_t address, uint32_t size);

/**
 * \brief Initialize Flash driver instance.
 *
 * \param[in] flash_info        Flash driver info
 * \param[in] start_address     Flash region start address
 * \param[in] mem_block_size    Size of flash memory block
 *
 * \retval ARM_DRIVER_OK
 *         Success.
 * \retval Other ARM_DRIVER_ERROR_*
 *         Failed
 */
int32_t ifx_flash_driver_initialize(ARM_FLASH_INFO *flash_info,
                                    uint32_t start_address,
                                    uint32_t mem_block_size);

#endif /* IFX_DRIVER_PRIVATE_H */

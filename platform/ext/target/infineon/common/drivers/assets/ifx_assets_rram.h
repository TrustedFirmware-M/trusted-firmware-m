/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_ASSETS_RRAM_H
#define IFX_ASSETS_RRAM_H

#include "Driver_Common.h"

#include <stdint.h>
#include <stddef.h>

/* Size of the rram assets checksum in bytes */
#define IFX_ASSETS_RRAM_CHECKSUM_SIZE   (4)

/*******************************************************************************
 * Function Name: ifx_assets_rram_read_block
 *******************************************************************************
 *
 * Reads an array of byte data from the specified address in RRAM.
 * Tries to acquire PC Lock predefined number of times.
 *
 * \param[in]  address  Address of RRAM memory.
 * \param[out] data     Pointer to the destination where the read data is stored.
 * \param[in]  length   Number of bytes to read.
 *
 * \return    \ref ARM_DRIVER_OK for success or error code
 *
 ******************************************************************************/
int32_t ifx_assets_rram_read_block(uint32_t address, void *data, uint32_t length);

/*******************************************************************************
 * Function Name: ifx_assets_rram_read_asset
 *******************************************************************************
 *
 * Reads an asset in RRAM and verifies its checksum.
 *
 * \param[in]  address  Address of the asset in NVM.
 * \param[out] asset    Pointer to a buffer where the asset will be copied.
 * \param[in]  size     Size of the asset in bytes excluding checksum.
 *
 * \return    \ref ARM_DRIVER_OK for success or error code
 *
 ******************************************************************************/
int32_t ifx_assets_rram_read_asset(uint32_t address, void *asset, size_t size);

#endif /* IFX_ASSETS_RRAM_H */

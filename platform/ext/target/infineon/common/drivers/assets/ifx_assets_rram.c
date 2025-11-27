/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cy_pdl.h"
#include "ifx_assets_rram.h"
#include "ifx_driver_rram.h"
#include "ifx_se_crc32.h"


int32_t ifx_assets_rram_read_block(uint32_t address, void *data, uint32_t length)
{
    cy_en_rram_status_t rram_status = CY_RRAM_BAD_PARAM;
    int32_t err = ARM_DRIVER_ERROR_PARAMETER;
    int32_t retries = IFX_DRIVER_RRAM_PC_LOCK_RETRIES;

    do {
        rram_status = Cy_RRAM_TSReadByteArray(IFX_RRAMC0, address, data, length);

        if (rram_status != CY_RRAM_ACQUIRE_PC_LOCK_FAIL) {
            break;
        }
    } while (--retries > 0);

    if (rram_status == CY_RRAM_SUCCESS) {
        err = ARM_DRIVER_OK;
    } else if (rram_status == CY_RRAM_ACQUIRE_PC_LOCK_FAIL) {
        err = ARM_DRIVER_ERROR_TIMEOUT;
    } else {
        err = ARM_DRIVER_ERROR;
    }

    return err;
}

int32_t ifx_assets_rram_read_asset(uint32_t address, void *asset, size_t size)
{
    int32_t err = ARM_DRIVER_ERROR_PARAMETER;
    uint32_t checksum = 0u;

    err = ifx_assets_rram_read_block(address, asset, size);
    if (err != ARM_DRIVER_OK) {
        return err;
    }

    err = ifx_assets_rram_read_block((address + size), (uint8_t *) &checksum, sizeof(checksum));
    if (err != ARM_DRIVER_OK) {
        return err;
    }

    if (checksum != ifx_se_crc32d6a(size, asset, IFX_S_ADDRESS_ALIAS(address))) {
        return ARM_DRIVER_ERROR;
    }

    return ARM_DRIVER_OK;
}

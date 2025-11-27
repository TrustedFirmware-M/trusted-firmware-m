/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_driver_smif.h"
#include "ifx_driver_smif_private.h"
#include <string.h>
#include "cy_device.h"

static int32_t ifx_driver_smif_read_data(ifx_flash_driver_handler_t handler,
            uint32_t addr, void *data, uint32_t cnt)
{
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    int32_t result = ARM_DRIVER_ERROR;
    uint32_t size = cnt * IFX_DRIVER_SMIF_DATA_WIDTH;

    /* Validate arguments */
    result = ifx_driver_smif_validate_region(obj, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

#if IFX_DRIVER_SMIF_DATA_WIDTH == 4
    /* Copy word by word */
    uint32_t *dst = data;
    const uint32_t *src =
            (const uint32_t *)(mem->mem_config->baseAddress + obj->offset + addr);
    while (size != 0U) {
        /* Use unaligned access */
        __UNALIGNED_UINT32_WRITE(dst, *src);
        dst++;
        src++;
        size -= IFX_DRIVER_SMIF_DATA_WIDTH;
    }
#else
#error "IFX_DRIVER_SMIF_DATA_WIDTH should be equal to 4"
#endif

    return ARM_DRIVER_OK;
}

static int32_t ifx_driver_smif_program_data(ifx_flash_driver_handler_t handler,
            uint32_t addr, const void *data, uint32_t cnt)
{
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    int32_t result = ARM_DRIVER_ERROR;
    uint32_t size = cnt * IFX_DRIVER_SMIF_DATA_WIDTH;

    /* Validate arguments */
    result = ifx_driver_smif_validate_region(obj, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

#if IFX_DRIVER_SMIF_DATA_WIDTH == 4
    /* Copy word by word */
    uint32_t *dst =
            (uint32_t *)(mem->mem_config->baseAddress + obj->offset + addr);
    const uint32_t *src = data;
    while (size != 0U) {
        /* Use unaligned access */
        *dst = __UNALIGNED_UINT32_READ(src);
        dst++;
        src++;
        size -= IFX_DRIVER_SMIF_DATA_WIDTH;
    }
#else
#error "IFX_DRIVER_SMIF_DATA_WIDTH should be equal to 4"
#endif

    return ARM_DRIVER_OK;
}

const struct ifx_flash_driver_t ifx_driver_smif_xip = {
    .GetVersion = ifx_driver_smif_get_version,
    .GetCapabilities = ifx_driver_smif_get_capabilities,
    .Initialize = ifx_driver_smif_initialize,
    .Uninitialize = ifx_driver_smif_uninitialize,
    .PowerControl = ifx_driver_smif_power_control,
    .ReadData = ifx_driver_smif_read_data,
    .ProgramData = ifx_driver_smif_program_data,
    .EraseSector = ifx_driver_smif_erase_sector,
    .EraseChip = ifx_driver_smif_erase_chip,
    .GetStatus = ifx_driver_smif_get_status,
    .GetInfo = ifx_driver_smif_get_info,
};

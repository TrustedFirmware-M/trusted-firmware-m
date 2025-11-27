/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_driver_smif.h"
#include "ifx_driver_smif_private.h"

static int32_t ifx_driver_smif_read_data(ifx_flash_driver_handler_t handler,
                                         uint32_t addr, void *data, uint32_t cnt)
{
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    cy_en_smif_status_t smif_status;
    int32_t result = ARM_DRIVER_ERROR;
    uint32_t size = cnt * IFX_DRIVER_SMIF_DATA_WIDTH;

    /* Validate arguments */
    result = ifx_driver_smif_validate_region(obj, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    result = ifx_driver_smif_set_mode(obj, CY_SMIF_MEMORY);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    smif_status = Cy_SMIF_MemRead(mem->smif_base,
                                  mem->mem_config,
                                  obj->offset + addr,
                                  data,
                                  size,
                                  mem->smif_context);
    if (smif_status != CY_SMIF_SUCCESS) {
        return ARM_DRIVER_ERROR;
    }

    return ARM_DRIVER_OK;
}

static int32_t ifx_driver_smif_program_data(ifx_flash_driver_handler_t handler,
                                            uint32_t addr, const void *data, uint32_t cnt)
{
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    cy_en_smif_status_t smif_status;
    int32_t result = ARM_DRIVER_ERROR;
    uint32_t size = cnt * IFX_DRIVER_SMIF_DATA_WIDTH;

    /* Validate arguments */
    result = ifx_driver_smif_validate_region(obj, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    result = ifx_driver_smif_set_mode(obj, CY_SMIF_MEMORY);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    /* Write data to the external memory with blocking function Cy_SMIF_MemWrite.
        This function also splits the data by pages, so no need to do such splitting here. */
    smif_status = Cy_SMIF_MemWrite(mem->smif_base,
                                   mem->mem_config,
                                   obj->offset + addr,
                                   data,
                                   size,
                                   mem->smif_context);
    if (smif_status != CY_SMIF_SUCCESS) {
        return ARM_DRIVER_ERROR;
    }

    return ARM_DRIVER_OK;
}

const struct ifx_flash_driver_t ifx_driver_smif_mmio = {
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

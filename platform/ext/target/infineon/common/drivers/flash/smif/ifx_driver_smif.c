/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* IMPORTANT NOTE
 *
 * This implementation treats address parameters as offsets in Flash address
 * space rather than as absolute addresses in CPU address space.
 */

#include "ifx_driver_smif.h"
#include "ifx_driver_smif_private.h"

#include <string.h>
#include "cy_device.h"


#define IFX_DRIVER_SMIF_VERSION             ARM_DRIVER_VERSION_MAJOR_MINOR(1UL, 0U)

#ifndef IFX_SMIF_SHORT_POLLING_RETRIES
/* Number of retries to poll the memory busy status for quick operations */
#define IFX_SMIF_SHORT_POLLING_RETRIES      (100)
#endif /* IFX_SMIF_SHORT_POLLING_RETRIES */

/**
 * \brief This function checks if the status of the SMIF block is busy
 *
 * \param[in] obj               Flash driver instance data
 *
 * \retval ARM_DRIVER_OK
 *         Memory block is not busy.
 * \retval ARM_DRIVER_ERROR_BUSY
 *         Memory block is busy.
 */
int32_t ifx_driver_smif_poll_block_busy(const ifx_driver_smif_obj_t *obj)
{
    int32_t retries = IFX_SMIF_SHORT_POLLING_RETRIES;
    cy_en_smif_txfr_status_t transaction_status;
    const ifx_driver_smif_mem_t *mem = obj->memory;

    do {
        /* Check if API is not busy executing transfer operation */
        transaction_status = (cy_en_smif_txfr_status_t)Cy_SMIF_GetTransferStatus(mem->smif_base,
                                                                                 mem->smif_context);
        bool isBusy = (CY_SMIF_RX_BUSY == transaction_status);
        isBusy = (Cy_SMIF_BusyCheck(mem->smif_base)) || isBusy;
        if (!isBusy) {
            return ARM_DRIVER_OK;
        }
    } while (--retries > 0);

    return ARM_DRIVER_ERROR_BUSY;
}

int32_t ifx_driver_smif_set_mode(const ifx_driver_smif_obj_t *obj, cy_en_smif_mode_t mode)
{
    int32_t result = ARM_DRIVER_OK;
    const ifx_driver_smif_mem_t *mem = obj->memory;

    cy_en_smif_mode_t current_mode = Cy_SMIF_GetMode(mem->smif_base);
    if (current_mode == mode)
    {
        return ARM_DRIVER_OK;
    }

    Cy_SMIF_SetMode(mem->smif_base, mode);
    result = ifx_driver_smif_poll_block_busy(obj);

    return result;
}

int32_t ifx_driver_smif_validate_region(const ifx_driver_smif_obj_t *obj,
                                        uint32_t address, uint32_t size)
{
    uint32_t region_size = obj->size;

    /* Address should be aligned to program unit */
    if ((address % IFX_DRIVER_SMIF_DATA_WIDTH) != 0U)
    {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Size should be aligned to program unit */
    if ((size % IFX_DRIVER_SMIF_DATA_WIDTH) != 0U)
    {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Validate size */
    if (size > region_size) {
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

ARM_DRIVER_VERSION ifx_driver_smif_get_version(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    (void)handler;

    /* Driver Version */
    ARM_DRIVER_VERSION driver_version = {
        .api = ARM_FLASH_API_VERSION,
        .drv = IFX_DRIVER_SMIF_VERSION
    };

    return driver_version;
}

ARM_FLASH_CAPABILITIES ifx_driver_smif_get_capabilities(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    (void)handler;

    /* Driver Capabilities */
    ARM_FLASH_CAPABILITIES capabilities = {
        .event_ready    = 0,
#if IFX_DRIVER_SMIF_DATA_WIDTH == 1
        .data_width     = 0,
#elif IFX_DRIVER_SMIF_DATA_WIDTH == 2
        .data_width     = 1,
#elif IFX_DRIVER_SMIF_DATA_WIDTH == 4
        .data_width     = 2,
#else
#error wrong IFX_DRIVER_SMIF_DATA_WIDTH value
#endif
        .erase_chip     = 1,
    };

    return capabilities;
}

/**
 * \brief Initialize SMIF flash driver instance.
 *
 * \param[in] handler   Flash driver handler data
 * \param[in] cb_event  Callback event is not supported. Must be NULL.
 *
 * \retval ARM_DRIVER_OK
 *         Success.
 * \retval Other ARM_DRIVER_ERROR_*
 *         Failed
 */
int32_t ifx_driver_smif_initialize(ifx_flash_driver_handler_t handler,
                                   ifx_flash_driver_event_t cb_event)
{
    cy_stc_smif_hybrid_region_info_t *region_info = NULL;
    uint32_t region_address;
    uint32_t sector_size;
    uint32_t sector_count;
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    const cy_stc_smif_mem_device_cfg_t *device = mem->mem_config->deviceCfg;
    uint32_t mapped_size = mem->mem_config->memMappedSize;

    /* Callback is not supported */
    if (cb_event != NULL) {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    /* Validate that region is inside mapped size */
    if ((obj->offset >= mapped_size) ||
        (obj->size > mapped_size) ||
        (obj->offset > (mapped_size - obj->size))) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    cy_en_smif_status_t status = Cy_SMIF_MemLocateHybridRegion(mem->mem_config,
                                                               &region_info,
                                                               obj->offset);
    if ((status == CY_SMIF_SUCCESS) && (region_info != NULL)) {
        /* Hybrid memory */
        region_address = region_info->regionAddress;
        sector_size = region_info->eraseSize;
        sector_count = region_info->sectorsCount;
    }
    else if (status == CY_SMIF_NOT_HYBRID_MEM) {
        /* Not hybrid memory */
        region_address = 0;
        sector_size = device->eraseSize;
        sector_count = device->memSize / device->eraseSize;
    }
    else {
        /* Error */
        return ARM_DRIVER_ERROR_SPECIFIC;
    }

    /* Region address and size should be aligned to sector size */
    if ((sector_size == 0U) ||
        ((obj->size % sector_size) != 0U) ||
        (((obj->offset - region_address) % sector_size) != 0U) ||
        (((obj->offset + obj->size - region_address) / sector_size) > sector_count)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Uniform sector only */
    obj->flash_info->sector_info = NULL;
    obj->flash_info->sector_count = obj->size / sector_size;
    obj->flash_info->sector_size = sector_size;
    obj->flash_info->page_size = device->programSize;
    obj->flash_info->program_unit = IFX_DRIVER_SMIF_DATA_WIDTH;
    obj->flash_info->erased_value = 0xFF;

    return ARM_DRIVER_OK;
}

int32_t ifx_driver_smif_uninitialize(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    (void)handler;
    return ARM_DRIVER_OK;
}

int32_t ifx_driver_smif_power_control(ifx_flash_driver_handler_t handler,
                                      ARM_POWER_STATE state)
{
    /* unused parameter */
    (void)handler;
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

int32_t ifx_driver_smif_erase_sector(ifx_flash_driver_handler_t handler, uint32_t addr)
{
    cy_en_smif_status_t smif_status;
    const ifx_driver_smif_obj_t *obj = handler;
    const ifx_driver_smif_mem_t *mem = obj->memory;
    int32_t result;

    /* Validate arguments */
    result = ifx_driver_smif_validate_region(obj, addr,
                                             obj->flash_info->sector_size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    /* Address should be aligned to sector size */
    if ((obj->flash_info->sector_size == 0U) ||
        ((addr % obj->flash_info->sector_size) != 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    result = ifx_driver_smif_set_mode(obj, CY_SMIF_MEMORY);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    smif_status = Cy_SMIF_MemEraseSectorStrict(mem->smif_base,
                                         mem->mem_config,
                                         obj->offset + addr,
                                         obj->flash_info->sector_size,
                                         mem->smif_context);
    if (smif_status != CY_SMIF_SUCCESS) {
        return ARM_DRIVER_ERROR;
    }

    if (mem->mem_config_dual_quad_pair != NULL) {
        smif_status = Cy_SMIF_MemEraseSectorStrict(mem->smif_base,
                                             mem->mem_config_dual_quad_pair,
                                             obj->offset + addr,
                                             obj->flash_info->sector_size,
                                             mem->smif_context);
        if (smif_status != CY_SMIF_SUCCESS) {
            return ARM_DRIVER_ERROR;
        }
    }

    return ARM_DRIVER_OK;
}

int32_t ifx_driver_smif_erase_chip(ifx_flash_driver_handler_t handler)
{
    const ifx_driver_smif_obj_t *obj = handler;
    int32_t result;
    uint32_t address = 0;

    /* Erase driver instance region instead of Chip Erase */
    for (size_t sector_id = 0; sector_id < obj->flash_info->sector_count; sector_id++) {
        result = ifx_driver_smif_erase_sector(handler, address);
        if (result != ARM_DRIVER_OK) {
            return result;
        }

        address += obj->flash_info->sector_size;
    }

    return ARM_DRIVER_OK;
}

struct _ARM_FLASH_STATUS ifx_driver_smif_get_status(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    (void)handler;
    struct _ARM_FLASH_STATUS status = {
        .busy = 0,
        .error = 0,
        .reserved = 0,
    };

    return status;
}

ARM_FLASH_INFO * ifx_driver_smif_get_info(ifx_flash_driver_handler_t handler)
{
    const ifx_driver_smif_obj_t *obj = handler;
    return obj->flash_info;
}

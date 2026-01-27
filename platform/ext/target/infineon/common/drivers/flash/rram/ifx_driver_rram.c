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

#include "config_tfm.h"
#include "fih.h"
#include "ifx_driver_private.h"
#include "ifx_driver_rram.h"
#include "ifx_utils.h"
#include "coverity_check.h"

#include <string.h>
#include "cy_device.h"
#include "cy_rram.h"

#define IFX_DRIVER_RRAM_VERSION      ARM_DRIVER_VERSION_MAJOR_MINOR(1UL, 0U)

static int32_t ifx_rramdrv_to_regular_status(cy_en_rram_status_t status) {
    switch (status) {
        case CY_RRAM_SUCCESS:
            return ARM_DRIVER_OK;
        case CY_RRAM_ACQUIRE_PC_LOCK_FAIL:
            return ARM_DRIVER_ERROR_BUSY;
        case CY_RRAM_OPERATION_TIME_OUT_ERROR:
            return ARM_DRIVER_ERROR_TIMEOUT;
        case CY_RRAM_BAD_PARAM:
            return ARM_DRIVER_ERROR_PARAMETER;
        default:
            return ARM_DRIVER_ERROR;
    }
}

static ARM_DRIVER_VERSION ifx_driver_rram_get_version(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    IFX_UNUSED(handler);

    /* Driver Version */
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_20_7, "Checked this part with preprocessor(-E option) and identified as not an issue")
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_1, "Drivers version defines use ARM_DRIVER_VERSION_MAJOR_MINOR define, which is provided by CMSIS. We cannot change that define")
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_12_2, "Same as above, shift is done in ARM_DRIVER_VERSION_MAJOR_MINOR")
    ARM_DRIVER_VERSION driver_version = {
        .api = ARM_FLASH_API_VERSION,
        .drv = IFX_DRIVER_RRAM_VERSION
    };
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_1)
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_20_7)

    return driver_version;
}

static ARM_FLASH_CAPABILITIES ifx_driver_rram_get_capabilities(ifx_flash_driver_handler_t handler)
{
    /* unused parameter */
    IFX_UNUSED(handler);

    /* Driver Capabilities */
    ARM_FLASH_CAPABILITIES ifx_driver_rram_capabilities = {
        .event_ready = 0,
        .data_width = 2, /* 0:8-bit, 1:16-bit, 2:32-bit */
        .erase_chip = 1,
    };

    return ifx_driver_rram_capabilities;
}

static int32_t ifx_driver_rram_initialize(ifx_flash_driver_handler_t handler,
                                          ifx_flash_driver_event_t cb_event)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;

    /* Callback is not supported */
    if (cb_event != NULL) {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    return ifx_flash_driver_initialize(&obj->flash_info,
                                       obj->start_address,
                                       CY_RRAM_BLOCK_SIZE_BYTES);
}

static int32_t ifx_driver_rram_uninitialize(ifx_flash_driver_handler_t handler)
{
    return ARM_DRIVER_OK;
}

static int32_t ifx_driver_rram_power_control(ifx_flash_driver_handler_t handler,
                                             ARM_POWER_STATE state)
{
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static int32_t ifx_driver_rram_read_data(ifx_flash_driver_handler_t handler,
            uint32_t addr, void *data, uint32_t cnt)
{
    cy_en_rram_status_t rram_status;
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;
    int32_t result;
    uint32_t size = cnt * IFX_DRIVER_RRAM_PROGRAM_UNIT;

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    rram_status = Cy_RRAM_NvmReadByteArray(obj->rram_base,
                                           obj->start_address + addr, data, size);

    if (rram_status != CY_RRAM_SUCCESS) {
        return ifx_rramdrv_to_regular_status(rram_status);
    }

#ifdef TFM_FIH_PROFILE_ON
#if IFX_PSA_ROT_PRIVILEGED
    /* fih_delay uses static variables which are placed to SPM linker section,
     * so when PSA RoT is unprivileged it has no access to these variables,
     * thus it is not possible to call fih_delay or other functions that use
     * fih_delay (e.g. fih_eq, ...). */
    (void)fih_delay();
#endif /* IFX_PSA_ROT_PRIVILEGED */

    /* Perform read back to increase fault injection hardening */
    if (memcmp((uint8_t*)(obj->start_address + addr), data, size) != 0) {
        return ARM_DRIVER_ERROR_SPECIFIC;
    }
#endif /* TFM_FIH_PROFILE_ON */

    return cnt;
}

/**
 * \brief Writes an array of byte data to the specified address in RRAM.
 * Tries to acquire PC Lock predefined number of times.
 *
 * \param[in] rram_base   Pointer to the memory object base.
 * \param[in] address     Address of RRAM memory.
 * \param[in] data        Pointer to the destination where the read data is stored.
 * \param[in] size        Number of bytes to read.
 *
 * \retval ARM_DRIVER_OK
 *         Memory had been written successfully.
 * \retval ARM_DRIVER_ERROR, ARM_DRIVER_ERROR_BUSY etc.
 *         Memory couldn't be write.
 */
static int32_t ifx_driver_rram_write(RRAMC_Type *rram_base,
                                     uint32_t address,
                                     const void *data,
                                     uint32_t size)
{
    cy_en_rram_status_t rram_status = CY_RRAM_BAD_PARAM;
    int32_t retries = IFX_DRIVER_RRAM_PC_LOCK_RETRIES;

    do {
        rram_status = Cy_RRAM_NvmWriteByteArray(rram_base, address, data, size);

        if (rram_status != CY_RRAM_ACQUIRE_PC_LOCK_FAIL) {
            break;
        }
    } while (--retries > 0);

    if (rram_status != CY_RRAM_SUCCESS) {
        return ifx_rramdrv_to_regular_status(rram_status);
    }

#ifdef TFM_FIH_PROFILE_ON
#if IFX_PSA_ROT_PRIVILEGED
    /* fih_delay uses static variables which are placed to SPM linker section,
     * so when PSA RoT is unprivileged it has no access to these variables,
     * thus it is not possible to call fih_delay or other functions that use
     * fih_delay (e.g. fih_eq, ...). */
    (void)fih_delay();
#endif /* IFX_PSA_ROT_PRIVILEGED */

    /* Perform read back to increase fault injection hardening */
    if (memcmp((uint8_t*)address, data, size) != 0) {
        return ARM_DRIVER_ERROR_SPECIFIC;
    }
#endif /* TFM_FIH_PROFILE_ON */

    return ARM_DRIVER_OK;
}

static int32_t ifx_driver_rram_program_data(ifx_flash_driver_handler_t handler,
            uint32_t addr, const void *data, uint32_t cnt)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;
    int32_t result;
    uint32_t size = cnt * IFX_DRIVER_RRAM_PROGRAM_UNIT;

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    result = ifx_driver_rram_write(obj->rram_base,
                                   obj->start_address + addr, data, size);
    return (result == ARM_DRIVER_OK) ? (int32_t)cnt : result;
}

static int32_t ifx_driver_rram_erase_sector(ifx_flash_driver_handler_t handler,
            uint32_t addr)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;
    int32_t result;
    uint8_t erase_pattern[CY_RRAM_BLOCK_SIZE_BYTES];

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, obj->flash_info.sector_size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }

    /* Address should be aligned to sector size */
    if ((obj->flash_info.sector_size == 0U) ||
        ((addr % obj->flash_info.sector_size) != 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Generate erase pattern */
    (void)memset(erase_pattern, obj->flash_info.erased_value, sizeof(erase_pattern));

    uint32_t offset = 0;
    while (offset < obj->flash_info.sector_size) {
        result = ifx_driver_rram_write(obj->rram_base,
                      obj->start_address + addr + offset,
                      erase_pattern, sizeof(erase_pattern));
        if (result != ARM_DRIVER_OK) {
            break;
        }

        offset += sizeof(erase_pattern);
    }

    return result;
}

static int32_t ifx_driver_rram_erase_chip(ifx_flash_driver_handler_t handler)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;
    int32_t result;
    uint32_t address = 0;

    /* Erase driver instance region instead of Chip Erase */
    for (size_t sector_id = 0; sector_id < obj->flash_info.sector_count; sector_id++) {
        result = ifx_driver_rram_erase_sector(handler, address);
        if (result != ARM_DRIVER_OK) {
            return result;
        }

        address += obj->flash_info.sector_size;
    }

    return ARM_DRIVER_OK;
}

static struct _ARM_FLASH_STATUS ifx_driver_rram_get_status(ifx_flash_driver_handler_t handler)
{
    struct _ARM_FLASH_STATUS status = {
        .busy = 0,
        .error = 0,
        .reserved = 0,
    };

    return status;
}


static ARM_FLASH_INFO *ifx_driver_rram_get_info(ifx_flash_driver_handler_t handler)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_rram_obj_t *obj = handler;
    return &obj->flash_info;
}

TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_2_8, "Used in RRAM flash driver in the IFX_DRIVER_RRAM_CREATE_INSTANCE macro");
const struct ifx_flash_driver_t ifx_driver_rram = {
    .GetVersion = ifx_driver_rram_get_version,
    .GetCapabilities = ifx_driver_rram_get_capabilities,
    .Initialize = ifx_driver_rram_initialize,
    .Uninitialize = ifx_driver_rram_uninitialize,
    .PowerControl = ifx_driver_rram_power_control,
    .ReadData = ifx_driver_rram_read_data,
    .ProgramData = ifx_driver_rram_program_data,
    .EraseSector = ifx_driver_rram_erase_sector,
    .EraseChip = ifx_driver_rram_erase_chip,
    .GetStatus = ifx_driver_rram_get_status,
    .GetInfo = ifx_driver_rram_get_info,
};

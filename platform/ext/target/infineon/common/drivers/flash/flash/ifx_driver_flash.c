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

#include "ifx_driver_flash.h"
#include "ifx_driver_private.h"
#include "ifx_utils.h"
#include "coverity_check.h"

#include <string.h>

#define IFX_DRIVER_FLASH_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(0x1U, 0x0U)

#if IFX_DRIVER_FLASH_SINGLE_INSTANCE
#define IFX_DRIVER_FLASH_EVENT ARM_Flash_SignalEvent_t
/* In the case of a flash driver limited to single instance,
 * list of arguments of flash driver functions is not modified */
#define IFX_DRIVER_FLASH_FUNCTION_ARGUMENTS(...) __VA_ARGS__
#define IFX_DRIVER_FLASH_FUNCTION_PARAMETERS(...) __VA_ARGS__
/* Single image of Flash driver, used in each flash driver functions */
extern const ifx_driver_flash_obj_t * const ifx_flash_driver_instance;
/* IFX_DRIVER_FLASH_INSTANCE supposed to be used only in flash driver functions */
#define IFX_DRIVER_FLASH_INSTANCE (ifx_flash_driver_instance)
#define IFX_UNUSED_FLASH_DRIVER_INSTANCE
#else /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */
#define IFX_DRIVER_FLASH_EVENT ifx_flash_driver_event_t
/* In the case of a multi image flash driver,
 * flash driver instance is added to the list of arguments of flash driver functions
 * GCC/Clang compilers don't support , ##__VA_ARGS__ syntax,
 * IAR doesn't support __VA_OPT__ syntax */
#if defined(__ICCARM__)
#define IFX_DRIVER_FLASH_FUNCTION_ARGUMENTS(...) ifx_flash_driver_handler_t handler, ##__VA_ARGS__
#define IFX_DRIVER_FLASH_FUNCTION_PARAMETERS(...) handler, ##__VA_ARGS__
#else /* defined(__ICCARM__) */
#define IFX_DRIVER_FLASH_FUNCTION_ARGUMENTS(...) ifx_flash_driver_handler_t handler __VA_OPT__(,) __VA_ARGS__
#define IFX_DRIVER_FLASH_FUNCTION_PARAMETERS(...) handler __VA_OPT__(,) __VA_ARGS__
#endif /* defined(__ICCARM__) */
/* IFX_DRIVER_FLASH_INSTANCE supposed to be used only in flash driver functions */
/* Pointer to active flash driver instance */
#define IFX_DRIVER_FLASH_INSTANCE (handler)
#define IFX_UNUSED_FLASH_DRIVER_INSTANCE    IFX_UNUSED(handler)
#endif /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */

/* Defines arguments of flash driver functions */
#define IFX_FDF_ARGS(...)   IFX_DRIVER_FLASH_FUNCTION_ARGUMENTS(__VA_ARGS__)
/* Defines parameters of flash driver functions */
#define IFX_FDF_PARAMS(...) IFX_DRIVER_FLASH_FUNCTION_PARAMETERS(__VA_ARGS__)

static int32_t ifx_flashdrv_to_regular_status(cy_en_flashdrv_status_t status)
{
    int32_t status_int32 = ARM_DRIVER_ERROR;

    switch (status) {
        case CY_FLASH_DRV_SUCCESS:
            status_int32 = ARM_DRIVER_OK;
            break;
        case CY_FLASH_DRV_IPC_BUSY:
            status_int32 = ARM_DRIVER_ERROR_BUSY;
            break;
        case CY_FLASH_DRV_INVALID_INPUT_PARAMETERS:
            status_int32 = ARM_DRIVER_ERROR_PARAMETER;
            break;
        default:
            status_int32 = ARM_DRIVER_ERROR;
            break;
    }

    return status_int32;
}

static ARM_DRIVER_VERSION ifx_driver_flash_get_version(IFX_FDF_ARGS())
{
#if !IFX_DRIVER_FLASH_SINGLE_INSTANCE
    IFX_UNUSED(IFX_DRIVER_FLASH_INSTANCE);
#endif /* !IFX_DRIVER_FLASH_SINGLE_INSTANCE */
    /* Driver Version */
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_20_7, "Checked this part with preprocessor(-E option) and identified as not an issue")
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_1, "Drivers version defines use ARM_DRIVER_VERSION_MAJOR_MINOR define, which is provided by CMSIS. We cannot change that define")
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_12_2, "Same as above, shift is done in ARM_DRIVER_VERSION_MAJOR_MINOR")
    ARM_DRIVER_VERSION driver_version = {
        ARM_FLASH_API_VERSION,
        IFX_DRIVER_FLASH_VERSION
    };
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_1)
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_20_7)

    return driver_version;
}

static ARM_FLASH_CAPABILITIES ifx_driver_flash_get_capabilities(IFX_FDF_ARGS())
{
#if !IFX_DRIVER_FLASH_SINGLE_INSTANCE
    IFX_UNUSED(IFX_DRIVER_FLASH_INSTANCE);
#endif /* !IFX_DRIVER_FLASH_SINGLE_INSTANCE */
    /* Driver Capabilities */
    ARM_FLASH_CAPABILITIES ifx_driver_flash_capabilities = {
        .event_ready = 0,
        .data_width = 0, /* 0:8-bit, 1:16-bit, 2:32-bit */
        .erase_chip = 1,
    };

    return ifx_driver_flash_capabilities;
}

static inline int32_t ifx_driver_flash_initialize(IFX_FDF_ARGS(IFX_DRIVER_FLASH_EVENT cb_event))
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;

    /* Callback is not supported */
    if (cb_event != NULL) {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    return ifx_flash_driver_initialize(&obj->flash_info,
                                       obj->start_address,
                                       IFX_DRIVER_FLASH_SECTOR_SIZE);
}

static int32_t ifx_driver_flash_uninitialize(IFX_FDF_ARGS())
{
#if !IFX_DRIVER_FLASH_SINGLE_INSTANCE
    IFX_UNUSED(IFX_DRIVER_FLASH_INSTANCE);
#endif /* !IFX_DRIVER_FLASH_SINGLE_INSTANCE */
    return ARM_DRIVER_OK;
}

static int32_t ifx_driver_flash_power_control(IFX_FDF_ARGS(ARM_POWER_STATE state))
{
#if !IFX_DRIVER_FLASH_SINGLE_INSTANCE
    IFX_UNUSED(IFX_DRIVER_FLASH_INSTANCE);
#endif /* !IFX_DRIVER_FLASH_SINGLE_INSTANCE */
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static int32_t ifx_driver_flash_read_data(IFX_FDF_ARGS(uint32_t addr, void *data, uint32_t cnt))
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;
    uint32_t size = cnt * IFX_DRIVER_FLASH_PROGRAM_UNIT;
    int32_t result;

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }
    if (data == NULL) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Using memcpy for reading */
    (void)memcpy((uint8_t *)data, (uint8_t *)(obj->start_address + addr), size);
    return cnt;
}

static int32_t ifx_driver_flash_program_data(IFX_FDF_ARGS(uint32_t addr,
                                                          const void *data,
                                                          uint32_t cnt))
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;
    uint32_t size = cnt * IFX_DRIVER_FLASH_PROGRAM_UNIT;
    int32_t result;
    uint32_t interrupt_state;

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }
    /* Make sure cnt argument is aligned to program_unit size */
    if (size % obj->flash_info.program_unit) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

#if IFX_DRIVER_FLASH_PROG_BUF_ON_STACK
    uint32_t prog_buf[CY_FLASH_SIZEOF_ROW / sizeof(uint32_t)];
#else
    /* Size of prog_buf is 512B, it is too big to put on the stack, so it is marked as static */
    static uint32_t prog_buf[CY_FLASH_SIZEOF_ROW / sizeof(uint32_t)];
#endif /* IFX_DRIVER_FLASH_PROG_BUF_ON_STACK */
    const uint8_t *data_ptr = (const uint8_t *)data;
    uint32_t address = obj->start_address + addr;
    cy_en_flashdrv_status_t cy_en_status = CY_FLASH_DRV_ERR_UNC;

    while (size) {
        uint32_t offset = address % CY_FLASH_SIZEOF_ROW;
        uint32_t chunk_size;
        if ((offset + size) > CY_FLASH_SIZEOF_ROW) {
            chunk_size = CY_FLASH_SIZEOF_ROW - offset;
        } else {
            chunk_size = size;
        }
        uint32_t row_address = IFX_ROUND_DOWN_TO_MULTIPLE(address, CY_FLASH_SIZEOF_ROW);
        interrupt_state = Cy_SysLib_EnterCriticalSection();
        (void)memcpy((uint8_t *)prog_buf, (uint8_t *)row_address, CY_FLASH_SIZEOF_ROW);
        (void)memcpy((uint8_t *)prog_buf + offset, data_ptr, chunk_size);

        cy_en_status = Cy_Flash_ProgramRow(row_address, prog_buf);
        Cy_SysLib_ExitCriticalSection(interrupt_state);
        if (cy_en_status != CY_FLASH_DRV_SUCCESS) {
            break;
        }
        data_ptr += chunk_size;
        address += chunk_size;
        size -= chunk_size;
    }

    return (cy_en_status == CY_FLASH_DRV_SUCCESS) ? (int32_t)cnt : ifx_flashdrv_to_regular_status(cy_en_status);
}

static int32_t ifx_driver_flash_erase_sector(IFX_FDF_ARGS(uint32_t addr))
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;
    int32_t result;
    uint32_t interrupt_state;

    /* Validate arguments */
    result = ifx_flash_driver_validate_region(&obj->flash_info, addr, obj->flash_info.sector_size);
    if (result != ARM_DRIVER_OK) {
        return result;
    }
    /* Address should be aligned to sector size */
    if ((addr % obj->flash_info.sector_size) != 0U) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    interrupt_state = Cy_SysLib_EnterCriticalSection();
    cy_en_flashdrv_status_t cy_en_status = Cy_Flash_EraseRow(obj->start_address + addr);
    Cy_SysLib_ExitCriticalSection(interrupt_state);
    return ifx_flashdrv_to_regular_status(cy_en_status);
}

static int32_t ifx_driver_flash_erase_chip(IFX_FDF_ARGS())
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;
    uint32_t address = obj->start_address;
    uint32_t interrupt_state;

    cy_en_flashdrv_status_t status = CY_FLASH_DRV_ERR_UNC;

    if (ifx_driver_flash_get_capabilities(IFX_FDF_PARAMS()).erase_chip != 1u) {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    for (uint32_t i = 0; i < obj->flash_info.sector_count; i++) {
        interrupt_state = Cy_SysLib_EnterCriticalSection();
        status = Cy_Flash_EraseRow(address);
        Cy_SysLib_ExitCriticalSection(interrupt_state);

        if (status != CY_FLASH_DRV_SUCCESS) {
            break;
        }

        TFM_COVERITY_DEVIATE_LINE(cert_int30_c, "This can never overflow if obj correctly describes the flash device.")
        address += obj->flash_info.sector_size;
    }

    return ifx_flashdrv_to_regular_status(status);
}

static struct _ARM_FLASH_STATUS ifx_driver_flash_get_status(IFX_FDF_ARGS())
{
#if !IFX_DRIVER_FLASH_SINGLE_INSTANCE
    IFX_UNUSED(IFX_DRIVER_FLASH_INSTANCE);
#endif /* !IFX_DRIVER_FLASH_SINGLE_INSTANCE */
    struct _ARM_FLASH_STATUS status = {
        .busy = 0,
        .error = 0,
        .reserved = 0,
    };

    return status;
}

static ARM_FLASH_INFO *ifx_driver_flash_get_info(IFX_FDF_ARGS())
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's flash driver API design to use pointer to void")
    const ifx_driver_flash_obj_t *obj = IFX_DRIVER_FLASH_INSTANCE;
    return &obj->flash_info;
}

#if IFX_DRIVER_FLASH_SINGLE_INSTANCE
/* In the case of a single flash driver instance, TFM directly implements CMSIS driver */
ARM_DRIVER_FLASH ifx_cmsis_driver_flash = {
    .GetVersion = ifx_driver_flash_get_version,
    .GetCapabilities = ifx_driver_flash_get_capabilities,
    .Initialize = ifx_driver_flash_initialize,
    .Uninitialize = ifx_driver_flash_uninitialize,
    .PowerControl = ifx_driver_flash_power_control,
    .ReadData = ifx_driver_flash_read_data,
    .ProgramData = ifx_driver_flash_program_data,
    .EraseSector = ifx_driver_flash_erase_sector,
    .EraseChip = ifx_driver_flash_erase_chip,
    .GetStatus = ifx_driver_flash_get_status,
    .GetInfo = ifx_driver_flash_get_info,
};
#else /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */
/* In the case of a multi flash driver instance, TFM creates ifx_flash_driver_t,
 * which is used to create the CMSIS driver */
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_11_1, "Checked this part with preprocessor(-E option) and identified as not an issue")
const struct ifx_flash_driver_t ifx_driver_flash = {
    .GetVersion = ifx_driver_flash_get_version,
    .GetCapabilities = ifx_driver_flash_get_capabilities,
    .Initialize = ifx_driver_flash_initialize,
    .Uninitialize = ifx_driver_flash_uninitialize,
    .PowerControl = ifx_driver_flash_power_control,
    .ReadData = ifx_driver_flash_read_data,
    .ProgramData = ifx_driver_flash_program_data,
    .EraseSector = ifx_driver_flash_erase_sector,
    .EraseChip = ifx_driver_flash_erase_chip,
    .GetStatus = ifx_driver_flash_get_status,
    .GetInfo = ifx_driver_flash_get_info,
};
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_11_1)
#endif /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IFX_FLASH_DRIVER_API_H
#define IFX_FLASH_DRIVER_API_H

#include "Driver_Flash.h"

#ifdef  __cplusplus
extern "C"
{
#endif

/**
 * \brief Driver instance handler.
 *
 * This type is used to hide internal implementation of driver instance data.
 */
typedef const void *ifx_flash_driver_handler_t;

/**
 * \brief       Signal Flash event.
 * \param[in]   handler Driver instance handler
 * \param[in]   event  Event notification mask, see \ref ARM_Flash_SignalEvent_t
 */
typedef void (*ifx_flash_driver_event_t)(ifx_flash_driver_handler_t handler, uint32_t event);

/**
 * \brief Access structure of the Flash Driver
 *
 * Interface is similar to CMSIS flash driver interface (\ref ARM_DRIVER_FLASH)
 * except that there is an additional driver instance handler
 * (see \ref ifx_flash_driver_instance_t.handler) which is specific to driver
 * implementation.
 */
typedef struct ifx_flash_driver_t {
    /* Pointer to \ref ARM_Flash_GetVersion : Get driver version. */
    ARM_DRIVER_VERSION     (*GetVersion)     (ifx_flash_driver_handler_t handler);
    /* Pointer to \ref ARM_Flash_GetCapabilities : Get driver capabilities. */
    ARM_FLASH_CAPABILITIES (*GetCapabilities)(ifx_flash_driver_handler_t handler);
    /* Pointer to \ref ARM_Flash_Initialize : Initialize Flash Interface. */
    int32_t                (*Initialize)     (ifx_flash_driver_handler_t handler,
                                              ifx_flash_driver_event_t cb_event);
    /* Pointer to \ref ARM_Flash_Uninitialize : De-initialize Flash Interface. */
    int32_t                (*Uninitialize)   (ifx_flash_driver_handler_t handler);
    /* Pointer to \ref ARM_Flash_PowerControl : Control Flash Interface Power. */
    int32_t                (*PowerControl)   (ifx_flash_driver_handler_t handler,
                                              ARM_POWER_STATE state);
    /* Pointer to \ref ARM_Flash_ReadData : Read data from Flash. */
    int32_t                (*ReadData)       (ifx_flash_driver_handler_t handler,
                                              uint32_t addr, void *data, uint32_t cnt);
    /* Pointer to \ref ARM_Flash_ProgramData : Program data to Flash. */
    int32_t                (*ProgramData)    (ifx_flash_driver_handler_t handler,
                                              uint32_t addr, const void *data, uint32_t cnt);
    /* Pointer to \ref ARM_Flash_EraseSector : Erase Flash Sector. */
    int32_t                (*EraseSector)    (ifx_flash_driver_handler_t handler,
                                              uint32_t addr);
    /* Pointer to \ref ARM_Flash_EraseChip : Erase complete Flash. */
    int32_t                (*EraseChip)      (ifx_flash_driver_handler_t handler);
    /* Pointer to \ref ARM_Flash_GetStatus : Get Flash status. */
    struct _ARM_FLASH_STATUS (*GetStatus)    (ifx_flash_driver_handler_t handler);
    /* Pointer to \ref ARM_Flash_GetInfo : Get Flash information. */
    ARM_FLASH_INFO *       (*GetInfo)        (ifx_flash_driver_handler_t handler);
} const ifx_flash_driver_t;

/**
 * \brief Flash driver instance.
 *
 * You can create a separate driver instance for same flash chip. But each instance
 * can handle different areas of flash memory. This allows to provide isolation
 * of data on driver level too.
 */
typedef struct ifx_flash_driver_instance_t {
    ifx_flash_driver_handler_t handler;
    ifx_flash_driver_t *driver;
} ifx_flash_driver_instance_t;

/**
 * Create CMSIS flash driver wrapper for TF-M compatible implementation
 *
 * instance - TF-M flash driver instance (\ref ifx_flash_driver_instance_t)
 * cmsis_driver - CMSIS flash driver that is created (\ref ARM_DRIVER_FLASH)
 **/
#define IFX_CREATE_CMSIS_FLASH_DRIVER(instance, cmsis_driver) \
    /* CMSIS wrapper for TF-M flash driver instance */ \
    static ARM_DRIVER_VERSION instance##_cmsis_get_version(void) { \
        return (instance).driver->GetVersion((instance).handler); \
    } \
    static ARM_FLASH_CAPABILITIES instance##_cmsis_get_capabilities(void) { \
        return (instance).driver->GetCapabilities((instance).handler); \
    } \
    static int32_t instance##_cmsis_initialize(ARM_Flash_SignalEvent_t cb_event) { \
        return (instance).driver->Initialize((instance).handler, NULL); \
    } \
    static int32_t instance##_cmsis_uninitialize(void) { \
        return (instance).driver->Uninitialize((instance).handler); \
    } \
    static int32_t instance##_cmsis_power_control(ARM_POWER_STATE state) { \
        return (instance).driver->PowerControl((instance).handler, state); \
    } \
    static int32_t instance##_cmsis_read_data(uint32_t addr, \
                                       void *data, uint32_t cnt) { \
        return (instance).driver->ReadData((instance).handler, addr, data, cnt); \
    } \
    static int32_t instance##_cmsis_program_data(uint32_t addr, \
                                          const void *data, uint32_t cnt) { \
        return (instance).driver->ProgramData((instance).handler, addr, data, cnt); \
    } \
    static int32_t instance##_cmsis_erase_sector(uint32_t addr) { \
        return (instance).driver->EraseSector((instance).handler, addr); \
    } \
    static int32_t instance##_cmsis_erase_chip(void) { \
        return (instance).driver->EraseChip((instance).handler); \
    } \
    static ARM_FLASH_STATUS instance##_cmsis_get_status(void) { \
        return (instance).driver->GetStatus((instance).handler); \
    } \
    static ARM_FLASH_INFO* instance##_cmsis_get_info(void) { \
        return (instance).driver->GetInfo((instance).handler); \
    } \
    /* CMSIS flash driver */ \
    ARM_DRIVER_FLASH (cmsis_driver) = { \
        .GetVersion = instance##_cmsis_get_version, \
        .GetCapabilities = instance##_cmsis_get_capabilities, \
        .Initialize = instance##_cmsis_initialize, \
        .Uninitialize = instance##_cmsis_uninitialize, \
        .PowerControl = instance##_cmsis_power_control, \
        .ReadData = instance##_cmsis_read_data, \
        .ProgramData = instance##_cmsis_program_data, \
        .EraseSector = instance##_cmsis_erase_sector, \
        .EraseChip = instance##_cmsis_erase_chip, \
        .GetStatus = instance##_cmsis_get_status, \
        .GetInfo = instance##_cmsis_get_info, \
    };

#ifdef  __cplusplus
}
#endif

#endif /* IFX_FLASH_DRIVER_API_H */

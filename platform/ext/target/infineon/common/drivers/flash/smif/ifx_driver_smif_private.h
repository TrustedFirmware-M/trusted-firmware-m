/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_DRIVER_SMIF_PRIVATE_H
#define IFX_DRIVER_SMIF_PRIVATE_H

#include "ifx_driver_smif.h"

#define IFX_DRIVER_SMIF_DATA_WIDTH          4U

#ifdef __cplusplus
extern "C" {
#endif

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
                                   ifx_flash_driver_event_t cb_event);

/**
 * \brief Switch SMIF controller mode.
 *
 * \param[in] handler   Flash driver handler data
 * \param[in] mode      SMIF controller mode.
 *
 * \retval ARM_DRIVER_OK
 *         Memory block is inside of flash driver instance region.
 * \retval ARM_DRIVER_ERROR_BUSY
 *         Memory block is outside of flash driver instance region.
 */
int32_t ifx_driver_smif_set_mode(const ifx_driver_smif_obj_t *obj,
                                 cy_en_smif_mode_t mode);

/**
 * \brief Validate that memory block is inside of flash driver instance region.
 *
 * \param[in] obj       Flash driver instance data
 * \param[in] address   Start address of memory block
 * \param[in] size      Memory block size
 *
 * \retval ARM_DRIVER_OK
 *         Memory block is inside of flash driver instance region.
 * \retval ARM_DRIVER_ERROR_PARAMETER
 *         Memory block is outside of flash driver instance region.
 *
 * \note \ref instance settings are not validated by this function!
 */
int32_t ifx_driver_smif_validate_region(const ifx_driver_smif_obj_t *obj,
                                        uint32_t address, uint32_t size);

/*
 * \brief Get CMSIS driver version for SMIF driver
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval CMSIS driver version for SMIF driver
 */
ARM_DRIVER_VERSION ifx_driver_smif_get_version(ifx_flash_driver_handler_t handler);

/*
 * \brief Get CMSIS driver capabilities for SMIF driver
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval CMSIS driver capabilities for SMIF driver
 */
ARM_FLASH_CAPABILITIES ifx_driver_smif_get_capabilities(ifx_flash_driver_handler_t handler);

/*
 * \brief Handles uninitialize request for SMIF driver
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval CMSIS driver error code
 */
int32_t ifx_driver_smif_uninitialize(ifx_flash_driver_handler_t handler);

/*
 * \brief Handles power request for SMIF driver
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval ARM_DRIVER_ERROR_UNSUPPORTED
 *         Request is not supported
 */
int32_t ifx_driver_smif_power_control(ifx_flash_driver_handler_t handler,
                                      ARM_POWER_STATE state);

/*
 * \brief Get status of SMIF driver
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval CMSIS flash driver status
 */
struct _ARM_FLASH_STATUS ifx_driver_smif_get_status(ifx_flash_driver_handler_t handler);

/*
 * \brief Get CMSIS flash driver info
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval CMSIS flash driver info
 */
ARM_FLASH_INFO * ifx_driver_smif_get_info(ifx_flash_driver_handler_t handler);

/**
 * \brief Erase sector of SMIF flash driver instance.
 *
 * \param[in] handler   Flash driver handler data
 * \param[in] addr      Sector address, must be aligned to sector.
 *
 * \retval ARM_DRIVER_OK
 *         Success.
 * \retval Other ARM_DRIVER_ERROR_*
 *         Failed
 */
int32_t ifx_driver_smif_erase_sector(ifx_flash_driver_handler_t handler, uint32_t addr);

/**
 * \brief Erase memory region allocated for SMIF flash driver instance.
 *
 * \param[in] handler   Flash driver handler data
 *
 * \retval ARM_DRIVER_OK
 *         Success.
 * \retval Other ARM_DRIVER_ERROR_*
 *         Failed
 */
int32_t ifx_driver_smif_erase_chip(ifx_flash_driver_handler_t handler);

#ifdef __cplusplus
}
#endif

#endif /* IFX_DRIVER_SMIF_PRIVATE_H */

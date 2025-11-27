/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_DRIVER_FLASH_H
#define IFX_DRIVER_FLASH_H

#include "ifx_flash_driver_api.h"

#include <stdint.h>
#include "cy_flash.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IFX_DRIVER_FLASH_ERASE_VALUE        (0xFFU)
#define IFX_DRIVER_FLASH_PROGRAM_UNIT       (1U) /* 1 B */
#define IFX_DRIVER_FLASH_SECTOR_SIZE        CY_FLASH_SIZEOF_ROW  /* 512 B */

/* Type ifx_driver_flash_obj_t similar to struct arm_flash_dev_t */
/**
 * \brief Structure containing the FLASH driver instance parameters.
 *
 * FLASH driver uses \ref start_address, \ref flash_info.sector_size and
 * \ref flash_info.sector_count to define a working region that is handled by
 * active instance. Any access outside of this region is invalid and FLASH
 * driver returns \ref ARM_DRIVER_ERROR_PARAMETER in such cases.
 *
 * \ref ifx_driver_flash interface expects address to be relative to \ref start_address.
 *
 * \note This structure can be a constant.
 */
typedef struct {
    uint32_t start_address;   /**< Region start address */

    /**
     * \ref flash_info.sector_size - sector size for region. It should be multiple
     *  of FLASH row size \ref CY_FLASH_SIZEOF_ROW.
     */
    ARM_FLASH_INFO flash_info;
} ifx_driver_flash_obj_t;


#if IFX_DRIVER_FLASH_SINGLE_INSTANCE
/* Set flash driver single instance to desired one */
#define IFX_DRIVER_FLASH_DEFINE_SINGLE_INSTANCE(instance_obj) \
    const ifx_driver_flash_obj_t * const ifx_flash_driver_instance = &instance_obj;

#else /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */
/* TF-M FLASH driver operations */
extern const struct ifx_flash_driver_t ifx_driver_flash;

/* Create FLASH flash driver instance */
#define IFX_DRIVER_FLASH_CREATE_INSTANCE(instance_name, instance_obj) \
    /* Use variable to validate instance_obj type */ \
    static const ifx_flash_driver_instance_t instance_name = { \
        .handler = &(instance_obj), \
        .driver = &ifx_driver_flash, \
    };
#endif /* IFX_DRIVER_FLASH_SINGLE_INSTANCE */

#ifdef __cplusplus
}
#endif

#endif /* IFX_DRIVER_FLASH_H */

/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_DRIVER_RRAM_H
#define IFX_DRIVER_RRAM_H

#include "ifx_flash_driver_api.h"
#include "ifx_s_peripherals_def.h"

#include <stdint.h>
#include "cy_rram.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RRAM itself does not have erase value, instead it is erased by writing a
 * buffer willed with IFX_DRIVER_RRAM_ERASE_VALUE. Here IFX_DRIVER_RRAM_ERASE_VALUE
 * is set to 0x0 to align it with other SW in the system (openocd, mcuboot, etc) */
#define IFX_DRIVER_RRAM_ERASE_VALUE     (0x0UL)
#define IFX_DRIVER_RRAM_PROGRAM_UNIT    (4U)
#ifndef IFX_DRIVER_RRAM_PC_LOCK_RETRIES
/* Number of attempts to acquire PC Lock when calling RRAM driver functions */
#define IFX_DRIVER_RRAM_PC_LOCK_RETRIES (100)
#endif /* IFX_DRIVER_RRAM_PC_LOCK_RETRIES */

/**
 * \brief Structure containing the RRAM driver instance parameters.
 *
 * RRAM flash driver uses \ref start_address, \ref flash_info.sector_size and
 * \ref flash_info.sector_count to define a working region that is handled by
 * active instance. Any access outside of this region is invalid and RRAM flash
 * driver returns \ref ARM_DRIVER_ERROR_PARAMETER in such cases.
 *
 * \ref ifx_driver_rram interface expects address to be relative to \ref start_address.
 *
 * \note This structure can be a constant.
 */
typedef struct ifx_driver_rram_obj_t {
    RRAMC_Type *rram_base;    /**< The pointer to the RRAMC instance. */
    uint32_t start_address;   /**< Region start address */

    /**
     * \ref flash_info.sector_size - sector size for region. It should be multiple
     *  of RRAM block size \ref CY_RRAM_BLOCK_SIZE_BYTES.
     */
    ARM_FLASH_INFO flash_info;
} ifx_driver_rram_obj_t;

/* TF-M RRAM driver operations */
extern const struct ifx_flash_driver_t ifx_driver_rram;

/* Create RRAM flash driver instance */
#define IFX_DRIVER_RRAM_CREATE_INSTANCE(instance_name, instance_obj) \
    /* Use variable to validate instance_obj type */ \
    const ifx_flash_driver_instance_t instance_name = { \
        .handler = &(instance_obj), \
        .driver = &ifx_driver_rram, \
    };

#ifdef __cplusplus
}
#endif

#endif /* IFX_DRIVER_RRAM_H */

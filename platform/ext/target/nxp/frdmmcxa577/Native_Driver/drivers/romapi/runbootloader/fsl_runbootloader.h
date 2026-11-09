/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_RUN_BOOTLOADER_H_
#define FSL_RUN_BOOTLOADER_H_

#include "fsl_common.h"

/*!
 * @addtogroup runbootloader
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief ROMAPI_RUNBOOTLOADER driver version 2.0.0. */
#define FSL_ROMAPI_RUNBOOTLOADER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*   API prototype fields definition.
| 31 : 24 |    23 : 20           |     19 : 16           |  15 : 12             |  11 : 8          |      6 : 5                    |      4 : 3                |
|   Tag   |   Boot mode          | ISP Interface         |  Instance            | Image Index      | recovery_boot_cfg1            | recovery_boot_cfg0        |
|  0xEB   | 0: Master boot mode  | 0 - Auto detection    | 0 - FLEXSPI: PORTA   | 0 - Boot image 0 | spi nor flash baudrate select | spi nor flash chip select |
|         | 1: ISP mode          | 1 - ISP/UART          | 1 - FLEXSPI: PORTB   | 1 - Boot image 1 |                               |                           |
|         | 2: Process FW        | 2 - FlexSPI/SPI       | 2 - FLEXSPI: PORTA&B |                  |                               |                           |
|         |                      | 3 - SPI Nor           |                      |                  |                               |                           |
|         |                      | 4 - OEM SBL/CAN       |                      |                  |                               |                           |
|         |                      | 5 - ROM Ext/ Reserved |                      |                  |                               |                           |
|         |                      | 8 - Reserved / I2C    |                      |                  |                               |                           |
*/

typedef struct
{
    union
    {
        struct
        {
            uint32_t reserved : 4;
            uint32_t recovery_boot_cfg0 : 2;
            uint32_t recovery_boot_cfg1 : 2;
            uint32_t boot_image_index : 4;
            uint32_t instance : 4;
            uint32_t boot_interface : 4;
            uint32_t mode : 4;
            uint32_t tag : 8;
        } B;
        uint32_t U;
    } option;
} user_app_boot_invoke_option_t;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MCUX_ROMAPI_TFM_INTERFACE
#include "fsl_romapi_tfm_ns.h" 
#elif !defined(MCUX_ROMAPI_TFM_INTERFACE) && (defined(DOMAIN_NS) && (DOMAIN_NS == 1))
#error "You need to enable the MCUX_COMPONENT_middleware.tfm.ns.romapi for accessing the ROM APIs in NSPE!"
#else

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Run the Bootloader API  to force into the ISP mode base on the user arg
 *
 * @param arg Indicates API prototype fields definition. Refer to the above user_app_boot_invoke_option_t structure
 */
void ROMAPI_RunBootloader(void *arg);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* MCUX_ROMAPI_TFM_INTERFACE */ 

#endif /* FSL_RUN_BOOTLOADER_H_ */

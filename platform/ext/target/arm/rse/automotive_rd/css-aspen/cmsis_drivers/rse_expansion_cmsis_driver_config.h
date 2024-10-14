/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_EXPANSION_CMSIS_DRIVER_CONFIG_H__
#define __RSE_EXPANSION_CMSIS_DRIVER_CONFIG_H__

#include "device_definition.h"
#include "tfm_hal_device_header.h"
#include "RTE_Device.h"

#ifdef RSE_USE_HOST_UART
#define UART0_DEV                    UART0_PL011_DEV_NS
#endif /* RSE_USE_HOST_UART */

#define FLASH0_DEV                   SPI_STRATAFLASHJ3_DEV

#define FLASH1_DEV                   SPI_STRATAFLASHJ3_AP_DEV

#endif  /* __RSE_EXPANSION_CMSIS_DRIVER_CONFIG_H__ */

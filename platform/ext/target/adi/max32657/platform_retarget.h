/******************************************************************************
 *
 * Copyright (C) 2024 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __ADI_MAX32657_RETARGET_H__
#define __ADI_MAX32657_RETARGET_H__

#include "max32657.h"

/* ======= Defines peripherals memory map addresses ======= */
/* Define Peripherals NS address range for the platform */
#define PERIPHERALS_BASE_NS_START (0x40000000)
#define PERIPHERALS_BASE_NS_END   (0x4FFFFFFF)

/* Non-secure memory map addresses */
#define UART0_BASE_NS MXC_BASE_UART_NS
#define TRNG_BASE_NS  MXC_BASE_TRNG_NS

/* Secure memory map addresses */
#define UART0_BASE_S           MXC_BASE_UART_S
#define TRNG_BASE_S            MXC_BASE_TRNG_S
#define MPC_SRAM0_BASE_S       MXC_BASE_MPC_SRAM0_S
#define MPC_SRAM1_BASE_S       MXC_BASE_MPC_SRAM1_S
#define MPC_SRAM2_BASE_S       MXC_BASE_MPC_SRAM2_S
#define MPC_SRAM3_BASE_S       MXC_BASE_MPC_SRAM3_S
#define MPC_SRAM4_BASE_S       MXC_BASE_MPC_SRAM4_S
#define MPC_FLASH_BASE_S       MXC_BASE_MPC_FLASH_S


/* SRAM MPC ranges and limits */
/* Internal memory */
#define MPC_SRAM0_RANGE_BASE_NS       0x20000000
#define MPC_SRAM0_RANGE_LIMIT_NS      0x20007FFF
#define MPC_SRAM0_RANGE_BASE_S        0x30000000
#define MPC_SRAM0_RANGE_LIMIT_S       0x30007FFF

#define MPC_SRAM1_RANGE_BASE_NS       0x20008000
#define MPC_SRAM1_RANGE_LIMIT_NS      0x2000FFFF
#define MPC_SRAM1_RANGE_BASE_S        0x30008000
#define MPC_SRAM1_RANGE_LIMIT_S       0x3000FFFF

#define MPC_SRAM2_RANGE_BASE_NS       0x20010000
#define MPC_SRAM2_RANGE_LIMIT_NS      0x2001FFFF
#define MPC_SRAM2_RANGE_BASE_S        0x30010000
#define MPC_SRAM2_RANGE_LIMIT_S       0x3001FFFF

#define MPC_SRAM3_RANGE_BASE_NS       0x20020000
#define MPC_SRAM3_RANGE_LIMIT_NS      0x2002FFFF
#define MPC_SRAM3_RANGE_BASE_S        0x30020000
#define MPC_SRAM3_RANGE_LIMIT_S       0x3002FFFF

#define MPC_SRAM4_RANGE_BASE_NS       0x20030000
#define MPC_SRAM4_RANGE_LIMIT_NS      0x2003FFFF
#define MPC_SRAM4_RANGE_BASE_S        0x30030000
#define MPC_SRAM4_RANGE_LIMIT_S       0x3003FFFF

/* Flash memory */
#define FLASH0_BASE_S                 0x11000000
#define FLASH0_BASE_NS                MXC_PHY_FLASH_MEM_BASE
#define FLASH0_SIZE                   MXC_PHY_FLASH_MEM_SIZE  /* 1 MB */
#define FLASH0_SECTOR_SIZE            MXC_PHY_FLASH_PAGE_SIZE /* 8 kB */
#define FLASH0_PAGE_SIZE              MXC_PHY_FLASH_PAGE_SIZE /* 8 kB */
#define FLASH0_PROGRAM_UNIT           0x10                    /* Minimum write size */

/* Flash memory Info Block */
#define FLASH_INFO_BASE               MXC_INFO_MEM_BASE
#define FLASH_INFO_SIZE               MXC_INFO_MEM_SIZE /* 16 KB */
#define FLASH_INFO_SECTOR_SIZE        0x00002000        /* 8 kB */
#define FLASH_INFO_PAGE_SIZE          0x00002000        /* 8 kB */
#define FLASH_INFO_PROGRAM_UNIT       0x10              /* Minimum write size */

#endif  /* __ADI_MAX32657_RETARGET_H__ */

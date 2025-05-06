/*
 * Copyright (c) 2022-2025 Arm Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file host_base_address.h
 * \brief This file defines the host memory map addresses accessed by RSE.
 */

#ifndef __HOST_BASE_ADDRESS_H__
#define __HOST_BASE_ADDRESS_H__

/* Host addresses */
#define AP_BOOT_SRAM_BASE   0x0UL        /* AP initial boot SRAM base address */
#define AP_BOOT_SRAM_SIZE   0x80000U     /* 512KB */

#define SCP_BOOT_SRAM_BASE  0x40000000UL /* SCP initial boot SRAM base address */
#define SCP_BOOT_SRAM_SIZE  0x80000U     /* 512KB */

#define HOST_UART_BASE     0x2A400000UL /* Host UART base address */
#define HOST_UART_SIZE     0x2000U      /* 8KB */

#define HOST_FLASH0_BASE   0x08000000UL /* Host flash base address */
#define HOST_FLASH0_SIZE   0x4000000    /* 64 MiB */

#define HOST_FLASH0_PS_OFFSET 0x2000000 /* Host flash offset 32 MiB */
#define HOST_FLASH0_PS_BASE (HOST_FLASH0_BASE + HOST_FLASH0_PS_OFFSET)
#define HOST_FLASH0_PS_SIZE (0x10000)   /* 64 KB */

/* ATU regions open in BL2 */
#define HOST_BOOT_IMAGE0_LOAD_BASE_S     (HOST_ACCESS_BASE_S + 0 * HOST_IMAGE_MAX_SIZE) /* Host boot image 0 output secure address */
#define HOST_BOOT_IMAGE1_LOAD_BASE_S     (HOST_ACCESS_BASE_S + 1 * HOST_IMAGE_MAX_SIZE) /* Host boot image 1 output secure address */

#endif  /* __HOST_BASE_ADDRESS_H__ */

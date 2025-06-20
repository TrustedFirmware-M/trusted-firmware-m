/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_base_address.h
 * \brief This file defines the host memory map addresses accessed by RSE.
 */

#ifndef __HOST_BASE_ADDRESS_H__
#define __HOST_BASE_ADDRESS_H__

#include "platform_base_address.h"

#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))
#define ALIGN_DOWN(num, align)  ((num) & ~((align) - 1))

#define RSE_ATU_PAGE_SIZE (0x2000U) /* 8KB */

/* Host addresses */
#define AP_BOOT_SRAM_BASE   0x0UL        /* AP initial boot SRAM base address */
#define AP_BOOT_SRAM_SIZE   0x80000U     /* 512KB */

#define HOST_UART_BASE     0x7FF80000UL /* Host UART base address */
#define HOST_UART_SIZE     0x2000U      /* 8KB */

#define HOST_FLASH0_BASE   0x08000000UL /* Host flash base address */
#define HOST_FLASH0_SIZE   0x4000000    /* 64 MiB */

#define AP_TRUSTED_SRAM_BASE  0x4000000UL /* AP trusted SRAM base address */
#define AP_SHARED_RAM_BASE    AP_TRUSTED_SRAM_BASE

#define PLAT_SCP_AP_SDS_SIZE          0xDC0U  /* 3520 bytes */
#define PLAT_SCP_SCMI_S_PAYLOAD_SIZE  0x100U  /*  256 bytes */
#define PLAT_RSE_AP_SDS_BASE  (AP_SHARED_RAM_BASE \
                               + PLAT_SCP_AP_SDS_SIZE \
                               + PLAT_SCP_SCMI_S_PAYLOAD_SIZE)
#define PLAT_RSE_AP_SDS_ATU_MAPPING_BASE (ALIGN_DOWN(PLAT_RSE_AP_SDS_BASE, \
                                                RSE_ATU_PAGE_SIZE))
#define PLAT_RSE_AP_SDS_SIZE  (64U)
#define PLAT_RSE_AP_SDS_ATU_MAPPING_SIZE ((ALIGN_UP(PLAT_RSE_AP_SDS_BASE +    \
                                                        PLAT_RSE_AP_SDS_SIZE, \
                                                    RSE_ATU_PAGE_SIZE)) -     \
                                          PLAT_RSE_AP_SDS_ATU_MAPPING_BASE)

#define RSE_ATU_AP_BASE             (0x00000000000000UL)
#define HOST_STAGING_MEM_BASE       (RSE_ATU_AP_BASE + 0x80000000UL)

#define SCP_BOOT_SRAM_BASE  0x1000000000000 /* SCP initial boot SRAM base address */
#define SCP_BOOT_SRAM_SIZE  0x20000U        /* 128KB */

#define SCP_SHARED_MEMORY_PHYS_BASE 0x45000000U /* SCP shared memory for SCMI transport */

#define SCP_SYSTEM_CONTROL_REGS_PHYS_BASE (0x1000058020000)

#define SCP_SYSTEM_CONTROL_BLOCK_OFFSET (0x1000)

/* System control regs are 4KB */
#define SCP_SYSTEM_CONTROL_REGS_SIZE (ALIGN_UP(0x1000, RSE_ATU_PAGE_SIZE))

/* ATU regions open in BL2 */
#define HOST_BOOT_IMAGE0_LOAD_BASE_S     (HOST_ACCESS_BASE_S + 0 * HOST_IMAGE_MAX_SIZE) /* Host boot image 0 output secure address */
#define HOST_BOOT_IMAGE1_LOAD_BASE_S     (HOST_ACCESS_BASE_S + 1 * HOST_IMAGE_MAX_SIZE) /* Host boot image 1 output secure address */
#define HOST_FLASH_FIP_BASE_S            (HOST_ACCESS_BASE_S + 5 * HOST_IMAGE_MAX_SIZE) /* Host flash FIP input secure address */

#endif  /* __HOST_BASE_ADDRESS_H__ */

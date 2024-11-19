/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_ap_memory_map.h
 * \brief This file contains addresses that are defined in the Application
 *        processor (AP) memory map.
 */

#ifndef __HOST_AP_MEMORY_MAP_H__
#define __HOST_AP_MEMORY_MAP_H__

/* AP Shared (ARSM) SRAM base address */
#define HOST_AP_SHARED_SRAM_PHYS_BASE               0x000000000ULL
/* AP Shared (ARSM) SRAM end address */
#define HOST_AP_SHARED_SRAM_PHYS_LIMIT              0x0000FFFFFULL

/* AP Memory Expansion region base address */
#define HOST_AP_MEM_EXP_PHYS_BASE                   0x030000000ULL
/* AP Memory Expansion region Flash offset */
#define HOST_AP_MEM_EXP_FLASH_OFFSET                0x008000000ULL

/* Base of AP region for MHU Pointer-access protocol */
#define HOST_AP_MHU_POINTER_ACCESS_PHYS_BASE        0x0FFFFC000ULL
/* End of AP region for MHU Pointer-access protocol */
#define HOST_AP_MHU_POINTER_ACCESS_PHYS_LIMIT       0x0FFFFFFFFULL

#endif /* __HOST_AP_MEMORY_MAP_H__ */

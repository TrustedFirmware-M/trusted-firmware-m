/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_si_memory_map.h
 * \brief This file contains addresses that are defined in the Safety Island
 *        address space.
 */

#ifndef __HOST_SI_MEMORY_MAP_H__
#define __HOST_SI_MEMORY_MAP_H__

/*
 * Safety Island memory spaces
 * ---------------------------
 *
 * RSE ATU is used for accessing SI physical address which is mapped at the
 * following system physical address spaces.
 *
 *  - SI address space: 0x4_0000_0000_0000 to 0x4_00FF_FFFF_FFFF
 */

/* SI region base address */
#define HOST_SI_PHYS_BASE                          0x4000000000000ULL
/* SI region end address */
#define HOST_SI_PHYS_LIMIT                         0x400FFFFFFFFFFULL

/* SI CL0 Cluster Utility Bus base address */
#define HOST_SI_CL0_CL_UTIL_BASE                   0x4000028000000ULL
/* SI CL0 Cluster Utility Bus end address */
#define HOST_SI_CL0_CL_UTIL_LIMIT                  0x40000287FFFFFULL

/* SI CL0 SRAM base address */
#define HOST_SI_CL0_SRAM_PHYS_BASE                 0x4000120000000ULL
/* SI CL0 SRAM end address */
#define HOST_SI_CL0_SRAM_PHYS_LIMIT                0x400012FFFFFFFULL

/* SI CL1 SRAM base address */
#define HOST_SI_CL1_SRAM_PHYS_BASE                 0x4000140000000ULL
/* SI CL1 SRAM end address */
#define HOST_SI_CL1_SRAM_PHYS_LIMIT                0x400014FFFFFFFULL

/*
 * Safety Island MHU frames
 */

#define RSE_MHU_SI_CL0_SND_IDX 0
#define RSE_MHU_SI_CL0_RCV_IDX 1

#define RSE_MHU_FRAME_SIZE 0x20000UL
#define RSE_MHU_FRAME_OFFSET(n) (n * RSE_MHU_FRAME_SIZE)

#endif /* __HOST_SI_MEMORY_MAP_H__ */

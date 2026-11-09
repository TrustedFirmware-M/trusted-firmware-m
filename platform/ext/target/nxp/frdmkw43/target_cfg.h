/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
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

#ifndef __TARGET_CFG_H__
#define __TARGET_CFG_H__

#include "target_cfg_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_DRIVER_STDIO    Driver_LPUART
#define NS_DRIVER_STDIO     Driver_LPUART


  /* =======================
 * Domain assignments (recommended)
 * DID0: Secure
 * DID1: Non-secure
 * ======================= */
#define DID_SECURE       (0u)
#define DID_NONSECURE    (1u)

/* =======================
 * MBC indices (KW43 TRDC chapter: MBC flash/rom, RAM/TCM, MBC peripherals)
 * ======================= */
#define MBC_00_PERIPH    (0u)
#define MBC_RAM          (1u)
#define MBC_FMC1         (2u)
#define MBC_FLASH        (3u)
#define MBC_04_PERIPH    (4u)

///* =======================
// * Access policy indices (GLBAC slots 0..7)
// * ======================= */
#define TRDC_GLBAC_IDX_POLICY_ALL_INDEX           (0u)
#define TRDC_GLBAC_IDX_FLASH_SEC_ALL_INDEX        (4u)
#define TRDC_GLBAC_IDX_RAM_SEC_ALL_INDEX          (4u)
#define TRDC_GLBAC_IDX_POLICY_S_RO_NS_ALL_INDEX   (1u)
#define TRDC_GLBAC_IDX_POLICY_NS_ALL_INDEX        (3u)  /* Only aplicable to RAM/Peripherals*/
#define TRDC_GLBAC_IDX_POLICY_SEC_RW_INDEX        (5u)  /* Only aplicable to RAM/Peripherals*/

/* RAM TRDC configuration */
#define RAM_SLV0_BASE                    (0x20000000u)
#define RAM_SLV0_END                     (0x2000FFFFu)  /* 64 KB */
#define TRDC_MBC1_SLV0_SUBREGION_SIZE    (0x1000)       /* 4 KB */

#define RAM_SLV1_BASE                    (0x20010000u)
#define RAM_SLV1_END                     (0x2001FFFFu)  /* 64 KB */
#define TRDC_MBC1_SLV1_SUBREGION_SIZE    (0x1000)       /* 4 KB */

/* RAM2 is shared with the NBU core: only the first 0x8E00 belongs to the
 * application core (see the RAM layout in partition/flash_layout.h). The whole
 * 64 KB slave window is declared here; which blocks are actually opened to the
 * non-secure world is derived from NS_DATA_START/NS_DATA_SIZE.
 */
#define RAM_SLV2_BASE                    (0x20020000u)
#define RAM_SLV2_END                     (0x2002FFFFu)  /* 64 KB */
#define TRDC_MBC1_SLV2_SUBREGION_SIZE    (0x1000)       /* 4 KB */

/* Peripheral TRDC configuration */
#define PERIPH_BLOCK_SIZE                (0x1000u)      /* 4 KB */
#define MBC4_SLV1_PERIPH_BLOCK_SIZE      (0x8000u)      /* 32 KB */

/* Peripheral MBC0 Configs*/
#define MBC0_SLV0_BASE 0x40200000U
#define MBC0_SLV1_BASE 0x40100000U
#define MBC0_SLV2_BASE 0x40180000U
#define MBC0_SLV3_BASE 0x4000C000U

/* Peripheral MBC4 Configs*/
#define MBC4_SLV0_BASE 0x40000000U
#define MBC4_SLV1_BASE 0x40080000U

typedef struct
{
    uint32_t addr;        /* Peripheral base address (secure or non-secure) */
    uint8_t  slaveIdx;    /* MBC / interconnect slave index */
} periph_desc_t;

typedef struct
{
    const uint32_t *slaveBase;
    uint8_t         slaveCount;
} mbc_map_t;

/**
 * \brief Holds the data necessary to do isolation for a specific peripheral.
 */
struct platform_data_t
{
    uint32_t periph_start;
    uint32_t periph_limit;

    uint32_t nseEnable;
    uint32_t mbcIdx;         /*!< The index of the MBC for this configuration to take effect. */
    uint32_t slaveMemoryIdx; /*!< The index of the slave memory for this configuration to take effect. */
    uint32_t memoryBlockIdx; /*!< The index of the memory block for this configuration to take effect. */
};

void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged);

#ifdef __cplusplus
}
#endif

#endif /* __TARGET_CFG_H__ */

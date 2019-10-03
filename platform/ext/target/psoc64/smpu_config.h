/*
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
 * Copyright (c) 2019 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
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

#ifndef __SMPU_CONFIG_H__
#define __SMPU_CONFIG_H__

#include "flash_layout.h"
#include "region_defs.h"

#include "cy_prot.h"

/* This macro depends on the actual CY_PROT_REGIONSIZE_XXX values */
#define REGIONSIZE_TO_BYTES(X)      (1UL << (1 + (X)))

/* The actual SMPU configs */

/* SMPU configs can only be changed by privileged secure PC=1 bus masters */
#define COMMON_SMPU_MASTER_CONFIG {\
    .userPermission = CY_PROT_PERM_R, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = ONLY_BL2_SPM_MASK, \
}

/* SMPU0 - secondary image in Flash */
#define SMPU0_BASE       S_ROM_ALIAS(0x00040000)
#define SMPU0_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU0_SLAVE_CONFIG {\
    .address = (void *)SMPU0_BASE, \
    .regionSize = SMPU0_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RW, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU0_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU0_BASE % REGIONSIZE_TO_BYTES(SMPU0_REGIONSIZE)
#error "Flash layout has changed - SMPU0 needs updating"
#endif

/* SMPU1 - secure primary image in Flash */
//#define SMPU1_BASE       (SMPU0_BASE + REGIONSIZE_TO_BYTES(SMPU0_REGIONSIZE))
#define SMPU1_BASE       S_ROM_ALIAS(S_IMAGE_PRIMARY_PARTITION_OFFSET)
#define SMPU1_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU1_SLAVE_CONFIG {\
    .address = (void *)SMPU1_BASE, \
    .regionSize = SMPU1_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU1_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU1_BASE % REGIONSIZE_TO_BYTES(SMPU1_REGIONSIZE)
#error "Flash layout has changed - SMPU1 needs updating"
#endif

/* SMPU2 - secure storage, NV counters, and unused space in Flash */
//#define SMPU2_BASE       (SMPU1_BASE + REGIONSIZE_TO_BYTES(SMPU1_REGIONSIZE))
#define SMPU2_BASE       S_ROM_ALIAS(FLASH_AREA_SCRATCH_OFFSET)
#define SMPU2_REGIONSIZE PROT_SIZE_64KB_BIT_SHIFT
#define SMPU2_SLAVE_CONFIG {\
    .address = (void *)SMPU2_BASE, \
    .regionSize = SMPU2_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RW, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU2_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU2_BASE % REGIONSIZE_TO_BYTES(SMPU2_REGIONSIZE)
#error "Flash layout has changed - SMPU2 needs updating"
#endif

/* SMPU6 - 32KB of unprivileged secure data in SRAM */
#define SMPU6_BASE       S_DATA_START
#define SMPU6_REGIONSIZE PROT_SIZE_32KB_BIT_SHIFT
#define SMPU6_SLAVE_CONFIG {\
    .address = (void *)SMPU6_BASE, \
    .regionSize = SMPU6_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RW, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU6_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU6_BASE % REGIONSIZE_TO_BYTES(SMPU6_REGIONSIZE)
#error "Flash layout has changed - SMPU6 needs updating"
#endif

/* S_DATA_PRIV_START must not overlap with unprivileged data section */
#if S_DATA_PRIV_START < (SMPU6_BASE + REGIONSIZE_TO_BYTES(SMPU6_REGIONSIZE))
#error "S_DATA_PRIV_START overlaps with unprivileged data section"
#endif

/* SMPU7 - 96KB of privileged secure data at S_DATA_PRIV_START in SRAM */
#define SMPU7_BASE       S_DATA_START
#define SMPU7_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU7_SUBREGION_DIS    (CY_PROT_SUBREGION_DIS0 | \
                                 CY_PROT_SUBREGION_DIS4 | \
                                 CY_PROT_SUBREGION_DIS5 | \
                                 CY_PROT_SUBREGION_DIS6 | \
                                 CY_PROT_SUBREGION_DIS7)
#define SMPU7_SLAVE_CONFIG {\
    .address = (void *)SMPU7_BASE, \
    .regionSize = SMPU7_REGIONSIZE, \
    .subregions = SMPU7_SUBREGION_DIS, \
    .userPermission = CY_PROT_PERM_DISABLED, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU7_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU7_BASE % REGIONSIZE_TO_BYTES(SMPU7_REGIONSIZE)
#error "Flash layout has changed - SMPU7 needs updating"
#endif

/*
 * S_DATA_PRIV_START must equal the base address of the second sub-region of
 * SMPU7
 */
#if S_DATA_PRIV_START != (SMPU7_BASE + \
                          (REGIONSIZE_TO_BYTES(SMPU7_REGIONSIZE) / 8))
#error "Flash layout has changed - S_DATA_PRIV_START doesn't fit the second sub-region of SMPU7"
#endif

/* SMPU10 - 4KB of privileged executable data in SRAM
 * Note: Region resides in subregion 4 of SMPU 7*/
#define SMPU10_BASE S_RAM_CODE_START
#define SMPU10_REGIONSIZE PROT_SIZE_4KB_BIT_SHIFT
#define SMPU10_SLAVE_CONFIG {\
    .address = (void *)SMPU10_BASE, \
    .regionSize = SMPU10_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_DISABLED, \
    .privPermission = CY_PROT_PERM_RX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU10_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU10_BASE % REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE)
#error "Flash layout has changed - SMPU10 needs updating"
#endif

#if S_RAM_CODE_SIZE != REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE)
#error "SMPU10_REGIONSIZE is not equal S_RAM_CODE_SIZE"
#endif

/* SMPUs 6, 7, 10 should cover the whole secure data area in the RAM */
#if S_DATA_SIZE != (REGIONSIZE_TO_BYTES(SMPU6_REGIONSIZE) + \
                    3*REGIONSIZE_TO_BYTES(SMPU7_REGIONSIZE)/8 + \
                    REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE) )
#error "Flash layout has changed - SMPU6/SMPU7/SMPU10 config needs updating"
#endif

#endif /* __SMPU_CONFIG_H__ */

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

/* SMPU4 - BL2 image in Flash */
#define SMPU4_BASE       BL2_CODE_START
#define SMPU4_REGIONSIZE PROT_SIZE_128KB_BIT_SHIFT
#define SMPU4_SLAVE_CONFIG {\
    .address = (void *)SMPU4_BASE, \
    .regionSize = SMPU4_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RX, \
    .privPermission = CY_PROT_PERM_RX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU4_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU4_BASE % REGIONSIZE_TO_BYTES(SMPU4_REGIONSIZE)
#error "Flash layout has changed - SMPU4 needs updating"
#endif

/* SMPU4 should cover the whole BL2 image */
#if FLASH_AREA_BL2_SIZE != REGIONSIZE_TO_BYTES(SMPU4_REGIONSIZE)
#error "Flash layout has changed - SMPU4 config needs updating"
#endif

/* SMPU5 - secure primary image (first half) in Flash */
#define SMPU5_BASE       S_ROM_ALIAS(FLASH_AREA_0_OFFSET)
#define SMPU5_REGIONSIZE PROT_SIZE_128KB_BIT_SHIFT
#define SMPU5_SLAVE_CONFIG {\
    .address = (void *)SMPU5_BASE, \
    .regionSize = SMPU5_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU5_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU5_BASE % REGIONSIZE_TO_BYTES(SMPU5_REGIONSIZE)
#error "Flash layout has changed - SMPU5 needs updating"
#endif

/* SMPU6 - secure primary image (second half) in Flash */
#define SMPU6_BASE       (SMPU5_BASE + REGIONSIZE_TO_BYTES(SMPU5_REGIONSIZE))
#define SMPU6_REGIONSIZE PROT_SIZE_128KB_BIT_SHIFT
#define SMPU6_SLAVE_CONFIG {\
    .address = (void *)SMPU6_BASE, \
    .regionSize = SMPU6_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU6_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU6_BASE % REGIONSIZE_TO_BYTES(SMPU6_REGIONSIZE)
#error "Flash layout has changed - SMPU6 needs updating"
#endif

/* SMPUs 5 and 6 should cover the whole secure primary image */
#if SECURE_IMAGE_MAX_SIZE != (REGIONSIZE_TO_BYTES(SMPU5_REGIONSIZE) + \
                              REGIONSIZE_TO_BYTES(SMPU6_REGIONSIZE))
#error "Flash layout has changed - SMPU5/SMPU6 config needs updating"
#endif

/* SMPU7 - Most of secondary images in Flash (0x10088000..0x100c0000) */
#define SMPU7_BASE       S_ROM_ALIAS(REGIONSIZE_TO_BYTES(\
                                     PROT_SIZE_512KB_BIT_SHIFT))
#define SMPU7_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU7_SLAVE_CONFIG {\
    .address = (void *)SMPU7_BASE, \
    .regionSize = SMPU7_REGIONSIZE, \
    .subregions = CY_PROT_SUBREGION_DIS0, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU7_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU7_BASE % REGIONSIZE_TO_BYTES(SMPU7_REGIONSIZE)
#error "Flash layout has changed - SMPU7 needs updating"
#endif

/* This "0x28000" is the gap between SMPU6 and SMPU7 for the NS image.
 * SMPU7 base address is 0x10080000 (CY_FLASH_BASE + 512KB), but the
 * first subregion (32KB = 0x8000) is disabled, giving an effective
 * start address of 0x10088000.
 */
#if NON_SECURE_IMAGE_MAX_SIZE != 0x28000
#error "Flash layout has changed - SMPU7 config needs updating"
#endif

/* SMPU8 - rest of secondary images, scratch space, secure storage,
 * NV counters, and unused space in flash */
#define SMPU8_BASE       (SMPU7_BASE + REGIONSIZE_TO_BYTES(SMPU7_REGIONSIZE))
#define SMPU8_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU8_SLAVE_CONFIG {\
    .address = (void *)SMPU8_BASE, \
    .regionSize = SMPU8_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU8_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU8_BASE % REGIONSIZE_TO_BYTES(SMPU8_REGIONSIZE)
#error "Flash layout has changed - SMPU8 needs updating"
#endif

/* SMPU9 - 32KB of unprivileged secure data in SRAM */
#define SMPU9_BASE       S_DATA_START
#define SMPU9_REGIONSIZE PROT_SIZE_32KB_BIT_SHIFT
#define SMPU9_SLAVE_CONFIG {\
    .address = (void *)SMPU9_BASE, \
    .regionSize = SMPU9_REGIONSIZE, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RW, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU9_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU9_BASE % REGIONSIZE_TO_BYTES(SMPU9_REGIONSIZE)
#error "Flash layout has changed - SMPU9 needs updating"
#endif

/* SMPU10 - 128KB of privileged secure data at S_DATA_PRIV_START in SRAM */
#define SMPU10_BASE       S_DATA_START
#define SMPU10_REGIONSIZE PROT_SIZE_256KB_BIT_SHIFT
#define SMPU10_SUBREGION_DIS    (CY_PROT_SUBREGION_DIS0 | \
                                 CY_PROT_SUBREGION_DIS5 | \
                                 CY_PROT_SUBREGION_DIS6 | \
                                 CY_PROT_SUBREGION_DIS7)
#define SMPU10_SLAVE_CONFIG {\
    .address = (void *)SMPU10_BASE, \
    .regionSize = SMPU10_REGIONSIZE, \
    .subregions = SMPU10_SUBREGION_DIS, \
    .userPermission = CY_PROT_PERM_DISABLED, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU10_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SMPU requires base address aligned to size */
#if SMPU10_BASE % REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE)
#error "Flash layout has changed - SMPU10 needs updating"
#endif

/*
 * S_DATA_PRIV_START must equal the base address of the second sub-region of
 * SMPU10
 */
#if S_DATA_PRIV_START != (SMPU10_BASE + \
                          (REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE) / 8))
#error "Flash layout has changed - S_DATA_PRIV_START doesn't fit the second sub-region of SMPU10"
#endif

/* S_DATA_PRIV_START must not overlap with unprivileged data section */
#if S_DATA_PRIV_START < (SMPU9_BASE + REGIONSIZE_TO_BYTES(SMPU9_REGIONSIZE))
#error "S_DATA_PRIV_START overlaps with unprivileged data section"
#endif

/* SMPUs 9, 10 should cover the whole secure data area in the RAM */
#if S_DATA_SIZE != (REGIONSIZE_TO_BYTES(SMPU9_REGIONSIZE) + \
                    REGIONSIZE_TO_BYTES(SMPU10_REGIONSIZE) / 2)
#error "Flash layout has changed - SMPU9/SMPU10 config needs updating"
#endif

#endif /* __SMPU_CONFIG_H__ */

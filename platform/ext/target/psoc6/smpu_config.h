/*
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
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

/* The actual SMPU configs */

/* SMPU configs can only be changed by privileged secure PC=1 bus masters */
#define COMMON_SMPU_MASTER_CONFIG {\
    .userPermission = CY_PROT_PERM_R, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = ONLY_BL2_SPM_MASK, \
}

/* Flash - BL2 image */
#define SMPU4_SLAVE_CONFIG {\
    .address = (void *)BL2_CODE_START, \
    .regionSize = CY_PROT_SIZE_128KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RX, \
    .privPermission = CY_PROT_PERM_RX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU4_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

#if FLASH_AREA_BL2_SIZE != 128*1024
#error "Flash layout has changed - SMPU4 config needs updating"
#endif

/* Flash - secure primary image (first half) */
#define SMPU5_SLAVE_CONFIG {\
    .address = (void *)S_ROM_ALIAS(FLASH_AREA_IMAGE_0_OFFSET), \
    .regionSize = CY_PROT_SIZE_128KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU5_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* Flash - secure primary image (second half) */
#define SMPU6_SLAVE_CONFIG {\
    .address = (void *)(S_ROM_ALIAS(FLASH_AREA_IMAGE_0_OFFSET) + (128*1024)), \
    .regionSize = CY_PROT_SIZE_128KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU6_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

#if SECURE_IMAGE_MAX_SIZE != 2*128*1024
#error "Flash layout has changed - SMPU5/SMPU6 config needs updating"
#endif

/* Most of secondary images  - 0x10088000..0x100c0000 */
#define SMPU7_SLAVE_CONFIG {\
    .address = (void *)(CY_FLASH_BASE + 512*1024), \
    .regionSize = CY_PROT_SIZE_256KB, \
    .subregions = CY_PROT_SUBREGION_DIS0, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU7_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

#if NON_SECURE_IMAGE_MAX_SIZE != 0x28000
#error "Flash layout has changed - SMPU7 config needs updating"
#endif

/* Flash - rest of secondary images, scratch space, secure storage, NV counters, and unused space */
#define SMPU8_SLAVE_CONFIG {\
    .address = (void *)(CY_FLASH_BASE + 3*256*1024), \
    .regionSize = CY_PROT_SIZE_256KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_RWX, \
    .privPermission = CY_PROT_PERM_RWX, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU8_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SRAM - 128KB at S_DATA_START */
#define SMPU9_SLAVE_CONFIG {\
    .address = (void *)S_DATA_START, \
    .regionSize = CY_PROT_SIZE_128KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_DISABLED, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU9_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

/* SRAM - remaining 16KB */
#define SMPU10_SLAVE_CONFIG {\
    .address = (void *)(S_DATA_START + 128*1024), \
    .regionSize = CY_PROT_SIZE_16KB, \
    .subregions = ALL_ENABLED, \
    .userPermission = CY_PROT_PERM_DISABLED, \
    .privPermission = CY_PROT_PERM_RW, \
    .secure = true, \
    .pcMatch = false, \
    .pcMask = SECURE_PCS_MASK, \
}
#define SMPU10_MASTER_CONFIG COMMON_SMPU_MASTER_CONFIG

#if S_DATA_SIZE != (128+16)*1024
#error "Flash layout has changed - SMPU9/SMPU10 config needs updating"
#endif

#endif /* __SMPU_CONFIG_H__ */

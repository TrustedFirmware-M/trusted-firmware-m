/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2021-2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
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

#ifndef __REGION_DEFS_H__
#define __REGION_DEFS_H__

#include "flash_layout.h"
#include "bl1_2_config.h"

/* Align address to 0x100 bytes boundary */
#define ADDR_ALIGN               0x100
#define ALIGN_UP_100(addr)       (((addr + (ADDR_ALIGN - 1)) / ADDR_ALIGN) * ADDR_ALIGN)

/* BL1_1 */
#define BL1_1_HEAP_SIZE         (0x0001000) /* 4KiB */
#define BL1_1_MSP_STACK_SIZE    (0x0001800) /* 6KiB */

/* BL1_2 */
#define BL1_2_HEAP_SIZE         (0x0001000) /* 4KiB */
#define BL1_2_MSP_STACK_SIZE    (0x0001800) /* 6KiB */

#define BL2_HEAP_SIZE           (0x0001000)
#define BL2_MSP_STACK_SIZE      (0x0001E00)

#ifdef ENABLE_HEAP
#define S_HEAP_SIZE             (0x0000200)
#endif

#define S_MSP_STACK_SIZE        (0x0000800)

#define BOOT_TFM_SHARED_DATA_SIZE (0x400)

/* Secure regions */
#define S_CODE_START            ALIGN_UP_100(SRAM_BASE + BL2_HEADER_SIZE)
#define S_CODE_ALIGNMENT_DIFF   (S_CODE_START - (SRAM_BASE + BL2_HEADER_SIZE))
#define IMAGE_TFM_CODE_SIZE     (TFM_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE - S_CODE_ALIGNMENT_DIFF)
#define S_CODE_SIZE             (IMAGE_TFM_CODE_SIZE)
#define S_CODE_LIMIT            (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START            (SRAM_BASE + TFM_PARTITION_SIZE)
#define S_DATA_SIZE             (SRAM_SIZE - TFM_PARTITION_SIZE)
#define S_DATA_LIMIT            (S_DATA_START + S_DATA_SIZE - 1)

/* Shared memory region */
#define INTER_PROCESSOR_SE_SHARED_MEMORY_START_ADDR 0xA8000000
#define INTER_PROCESSOR_HOST_SHARED_MEMORY_START_ADDR 0x88000000
#define INTER_PROCESSOR_SHARED_MEMORY_SIZE (1024 * 1024) /* 1MB */

#define NS_DATA_START INTER_PROCESSOR_SE_SHARED_MEMORY_START_ADDR
#define NS_DATA_SIZE INTER_PROCESSOR_SHARED_MEMORY_SIZE

#define S_CODE_VECTOR_TABLE_SIZE    (0xc0)

/* Stub NS macros needed for compilation */
#define NS_DATA_LIMIT   NS_DATA_START + NS_DATA_SIZE
#define NS_CODE_START   0x0
#define NS_CODE_SIZE    0x0
#define NS_CODE_LIMIT   0x0
#define NS_PARTITION_START 0
#define NS_PARTITION_SIZE (NS_DATA_SIZE)

/* Secondary partition for new images in case of firmware upgrade */
#define SECONDARY_PARTITION_START 0
#define SECONDARY_PARTITION_SIZE (TFM_PARTITION_SIZE)

/* SE BL2 regions */
#define BL2_IMAGE_START            (SRAM_BASE + SRAM_SIZE - SE_BL2_PARTITION_SIZE)
#define BL2_CODE_START             ALIGN_UP_100(BL2_IMAGE_START + TFM_BL1_2_HEADER_MAX_SIZE)
#define BL2_CODE_ALIGNMENT_DIFF    (BL2_CODE_START - (BL2_IMAGE_START + TFM_BL1_2_HEADER_MAX_SIZE))
#define IMAGE_BL2_CODE_SIZE        (SE_BL2_PARTITION_SIZE - TFM_BL1_2_HEADER_MAX_SIZE - BL2_CODE_ALIGNMENT_DIFF)
#define BL2_CODE_SIZE              (IMAGE_BL2_CODE_SIZE)
#define BL2_CODE_LIMIT             (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_DATA_START    (S_DATA_START)
#define BL2_DATA_SIZE     (BL2_IMAGE_START - BL2_DATA_START)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)

/* SE BL1 regions */
#define BL1_1_CODE_START    (0)
#define BL1_1_CODE_SIZE     (0x0000E800)     /* 58 KiB */
#define BL1_1_CODE_LIMIT    (BL1_1_CODE_START + BL1_1_CODE_SIZE - 1)

#define PROVISIONING_DATA_START (BL1_1_CODE_START + BL1_1_CODE_SIZE)
#define PROVISIONING_DATA_SIZE  (0x00001800)     /* 6 KiB */
#define PROVISIONING_DATA_LIMIT (PROVISIONING_DATA_START + PROVISIONING_DATA_SIZE - 1)

#define BL1_1_DATA_START    (SRAM_BASE)
#define BL1_1_DATA_SIZE     (0x8000)     /* 32 KiB*/
#define BL1_1_DATA_LIMIT    (BL1_1_DATA_START + BL1_1_DATA_SIZE - 1)

#define BL1_2_CODE_START    (BL1_1_DATA_START + BL1_1_DATA_SIZE)
/* The BL1_2_CODE just fits inside this region. The BL1_2 code is provisioned into
 * the OTP so more space shouldn't be assigned to this because we can run out of OTP
 * memory if the OTP layout is changed for some reason. That could cause runtime
 * errors
 */
#define BL1_2_CODE_SIZE     (0x0000170C) /* 5.9 KB */
#define BL1_2_CODE_LIMIT    (BL1_2_CODE_START + BL1_2_CODE_SIZE - 1)

#define BL1_2_DATA_START    (BL1_2_CODE_START+BL1_2_CODE_SIZE)
#define BL1_2_DATA_SIZE     (0x8000)     /* 32 KiB*/
#define BL1_2_DATA_LIMIT    (BL1_2_DATA_START + BL1_2_DATA_SIZE - 1)

#define BOOT_TFM_SHARED_DATA_BASE (S_DATA_START)

#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#endif /* __REGION_DEFS_H__ */

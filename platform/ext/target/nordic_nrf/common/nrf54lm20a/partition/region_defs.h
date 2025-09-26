/*
 * Copyright (c) 2025 Nordic Semiconductor ASA. All rights reserved.
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

#ifdef ENABLE_HEAP
    #define S_HEAP_SIZE         (0x0002000) /* 8k */
#endif

#define S_MSP_STACK_SIZE        (0x0002000) /* 8k */
#define S_PSP_STACK_SIZE        (0x0002000) /* 8k */

#define NS_HEAP_SIZE            (0x00002000) /* 8k */
#define NS_STACK_SIZE           (0x00002000) /* 8k */

/* Size of nRF MPC regions is 4k */
#define MPC_FLASH_REGION_SIZE   (0x00001000)
#define MPC_SRAM_REGION_SIZE    (0x00001000)

#ifdef NRF_NS_SECONDARY
#error "NRF_NS_SECONDARY is not supported for this platform"
#endif /* NRF_NS_SECONDARY */

/* Alias definitions for secure and non-secure areas*/
#define S_ROM_ALIAS(x)  (S_ROM_ALIAS_BASE + (x))
#define NS_ROM_ALIAS(x) (NS_ROM_ALIAS_BASE + (x))

#define S_RAM_ALIAS(x)  (S_RAM_ALIAS_BASE + (x))
#define NS_RAM_ALIAS(x) (NS_RAM_ALIAS_BASE + (x))

/* Secure regions */
#define S_CODE_START    (S_ROM_ALIAS(SECURE_IMAGE_OFFSET))
#define S_CODE_SIZE     (FLASH_S_PARTITION_SIZE)
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START    (S_RAM_ALIAS(0x0))
#define S_DATA_SIZE     (TOTAL_RAM_SIZE / 2)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* Copied from the CONFIG_TFM_S_CODE_VECTOR_TABLE_SIZE in sdk-nrf */
#define S_CODE_VECTOR_TABLE_SIZE (0x4D0)

#if defined(NULL_POINTER_EXCEPTION_DETECTION) && S_CODE_START == 0
/* If this image is placed at the beginning of flash make sure we
 * don't put any code in the first 256 bytes of flash as that area
 * is used for null-pointer dereference detection.
 */
#define TFM_LINKER_CODE_START_RESERVED (256)
#if S_CODE_VECTOR_TABLE_SIZE < TFM_LINKER_CODE_START_RESERVED
#error "The interrupt table is too short too for null pointer detection"
#endif
#endif

/* Non-secure regions */
#define NS_CODE_START   (NS_ROM_ALIAS(SECURE_STORAGE_PARTITIONS_END))
#define NS_CODE_SIZE    (FLASH_NS_PARTITION_SIZE)
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

#define NS_DATA_START   (NS_RAM_ALIAS(S_DATA_SIZE))

#ifdef PSA_API_TEST_IPC
/* Last SRAM region must be kept secure for PSA FF tests */
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_DATA_SIZE - MPC_SRAM_REGION_SIZE)
#else
#define NS_DATA_SIZE    (TOTAL_RAM_SIZE - S_DATA_SIZE)
#endif
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for SAU and MPC configuration */
#define NS_PARTITION_START NS_CODE_START
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)

/* Non-secure storage region */
#ifdef NRF_NS_STORAGE
#define NRF_NS_STORAGE_PARTITION_START \
            (NS_ROM_ALIAS(NRF_FLASH_NS_STORAGE_AREA_OFFSET))
#define NRF_NS_STORAGE_PARTITION_SIZE (NRF_FLASH_NS_STORAGE_AREA_SIZE)
#endif /* NRF_NS_STORAGE */

/* Regions used by psa-arch-tests to keep state */
#define PSA_TEST_SCRATCH_AREA_SIZE (0x400)

/* Even though BL2 is not supported now this needs to be defined becaused it is used by scatter files */
#define BOOT_TFM_SHARED_DATA_BASE S_RAM_ALIAS_BASE
#define BOOT_TFM_SHARED_DATA_SIZE (0x0)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

#ifdef PSA_API_TEST_IPC
/* Firmware Framework test suites */
#define FF_TEST_PARTITION_SIZE 0x100
#define PSA_TEST_SCRATCH_AREA_BASE (NS_DATA_LIMIT + 1 - \
                                    PSA_TEST_SCRATCH_AREA_SIZE - \
                                    FF_TEST_PARTITION_SIZE)

/* The psa-arch-tests implementation requires that the test partitions are
 * placed in this specific order:
 * TEST_NSPE_MMIO < TEST_SERVER < TEST_DRIVER
 *
 * TEST_NSPE_MMIO region must be in the NSPE, while TEST_SERVER and TEST_DRIVER
 * must be in SPE.
 *
 * The TEST_NSPE_MMIO region is defined in the psa-arch-tests implementation,
 * and it should be placed at the end of the NSPE area, after
 * PSA_TEST_SCRATCH_AREA.
 */
#define FF_TEST_SERVER_PARTITION_MMIO_START  (NS_DATA_LIMIT + 1)
#define FF_TEST_SERVER_PARTITION_MMIO_END    (FF_TEST_SERVER_PARTITION_MMIO_START + \
                                              FF_TEST_PARTITION_SIZE - 1)
#define FF_TEST_DRIVER_PARTITION_MMIO_START  (FF_TEST_SERVER_PARTITION_MMIO_END + 1)
#define FF_TEST_DRIVER_PARTITION_MMIO_END    (FF_TEST_DRIVER_PARTITION_MMIO_START + \
                                              FF_TEST_PARTITION_SIZE - 1)
#else
/* Development APIs test suites */
#define PSA_TEST_SCRATCH_AREA_BASE (NS_DATA_LIMIT + 1 - \
                                    PSA_TEST_SCRATCH_AREA_SIZE)
#endif /* PSA_API_TEST_IPC */

#endif /* __REGION_DEFS_H__ */

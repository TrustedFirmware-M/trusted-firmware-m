/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
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
#include "platform_base_address.h"
#include "rse_memory_sizes.h"
#if defined(RSE_BL1_TEST_BINARY) && !defined(RSE_TEST_BINARY_IN_ROM)
#include "rse_test_binary_location.h"
#endif /* defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_ROM) */
#include "bl1_2_config.h"

/* RSE memory layout is as follows during BL1
 *      |----------------------------------------------------|
 * DTCM | BLOB_DATA | BOOT_SHARED | BL1_1_DATA | BL1_2_DATA  |
 *      |----------------------------------------------------|
 *
 *      |----------------------------------------------------|
 * ITCM | BLOB_CODE | BL1_2_CODE  |                          |
 *      |----------------------------------------------------|
 *
 *      |---------------------------------------------------------
 * VM0  |                                                        |
 *      |---------------------------------------------------------
 *      |---------------------------------------------------------
 * VM1  |                            | PERS_DATA | OTP_EMULATION |
 *      |---------------------------------------------------------
 *
 * If the size of VM0 and VM1 are larger than 64KiB, the size of BL1 code/data
 * and BL2 code can be increased to fill the extra space.
 *
 * RSE memory layout is as follows during BL2
 *      |----------------------------------------|
 * DTCM | BOOT_SHARED |                          |
 *      |----------------------------------------|
 *
 *      |---------------------------------------------------------
 * VM0  | BL2_CODE                                               |
 *      |---------------------------------------------------------
 *      |---------------------------------------------------------
 * VM1  |  XIP tables  | BL2_DATA  | PERS_DATA | OTP_EMULATION   |
 *      |---------------------------------------------------------
 *
 * If the size of VM0 and VM1 are larger than 64KiB, the size of BL2 code can be
 * increased to fill the extra space. Note that BL2 code is aligned to the start
 * of S_DATA, so under non-XIP mode it will not start at the beginning of VM0.
 *
 * RSE memory layout is as follows during Runtime with XIP mode enabled
 *      |----------------------------------------|
 * DTCM | BOOT_SHARED |                          |
 *      |----------------------------------------|
 *
 *      |---------------------------------------------------------
 * VM0  | S_DATA                                                 |
 *      |---------------------------------------------------------
 *      |---------------------------------------------------------
 * VM1  | S_DATA         | NS_DATA   | PERS_DATA | OTP_EMULATION |
 *      |---------------------------------------------------------
 *
 * RSE memory layout is as follows during Runtime with XIP mode disabled. Note
 * that each SRAM must be at least 512KiB in this mode (64KiB data and 384KiB
 * code, for each of secure and non-secure).
 *      |----------------------------------------|
 * DTCM | BOOT_SHARED |                          |
 *      |----------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * VM0  | S_CODE                                           | S_DATA            |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  |  NS_DATA          | NS_CODE          | PERS_DATA | OTP_EMULATION     |
 *      |----------------------------------------------------------------------|
 */

/* Heap and stack shared between BL1_1 and BL1_2 */
#define BL1_HEAP_SIZE           (0x0001000)
#define BL1_MSP_STACK_SIZE      (0x0001800)

#define BL2_HEAP_SIZE           (0x0001000)
#define BL2_MSP_STACK_SIZE      (0x0002000)

#define S_HEAP_SIZE             (0x0001000)
#define S_MSP_STACK_SIZE        (0x0000800)

#define NS_HEAP_SIZE            (0x0001000)
#define NS_STACK_SIZE           (0x0001000)

/* Store persistent data at the end of VM1 as will not be cleared on reset */
#define PERSISTENT_DATA_SIZE (0x400)
#define PERSISTENT_DATA_BASE \
    ((VM1_BASE_S + VM1_SIZE) - PERSISTENT_DATA_SIZE - RSE_OTP_EMULATION_SRAM_SIZE)
#define PERSISTENT_DATA_LIMIT ((PERSISTENT_DATA_BASE + PERSISTENT_DATA_SIZE) - 1)

/* SRAM allocated to store data when using OTP emulation mode.
 * This must match the size of the OTP
 */
#ifdef RSE_USE_OTP_EMULATION_IN_SRAM
#define RSE_OTP_EMULATION_SRAM_SIZE     (0x4000)
#define RSE_OTP_EMULATION_SRAM_START    ((VM1_BASE_S + VM1_SIZE) - RSE_OTP_EMULATION_SRAM_SIZE)

#if RSE_OTP_EMULATION_SRAM_START % RSE_OTP_EMULATION_SRAM_SIZE != 0
#error RSE OTP Emulation SRAM must have alignment of its size
#endif

#else
#define RSE_OTP_EMULATION_SRAM_SIZE     (0x0)
#endif /* RSE_USE_OTP_EMULATION_IN_SRAM */

/* This size of buffer is big enough to store an array of all the
 * boot records/measurements which is encoded in CBOR format.
 */
#define TFM_ATTEST_BOOT_RECORDS_MAX_SIZE    (0x400)

#define S_IMAGE_SECONDARY_PARTITION_OFFSET (FLASH_AREA_4_OFFSET)

/* Boot partition structure if MCUBoot is used:
 * 0x0_0000 Bootloader header
 * 0x0_0400 Image area
 * 0x5_0000 Trailer
 */
/* IMAGE_CODE_SIZE is the space available for the software binary image.
 * It is less than the FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE
 * because we reserve space for the image header and trailer introduced
 * by the bootloader.
 */
#define IMAGE_BL2_CODE_SIZE \
            (FLASH_BL2_PARTITION_SIZE - TFM_BL1_2_HEADER_MAX_SIZE)

#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

#define IMAGE_NS_CODE_SIZE \
            (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

/* Secure regions */
/* Secure Code executes from VM0, or XIP from flash via the SIC */
#ifdef RSE_XIP
#define S_CODE_START    (RSE_RUNTIME_S_XIP_BASE_S)
#define S_CODE_SIZE     (FLASH_S_PARTITION_SIZE)
#else
#define S_CODE_START    (S_IMAGE_LOAD_ADDRESS + BL2_HEADER_SIZE)
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#endif /* RSE_XIP */
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

/* Secure Data stored in VM0. Size defined in flash layout */
#ifdef RSE_XIP
#define S_DATA_START    (VM0_BASE_S)
#define S_DATA_SIZE \
    (VM0_SIZE + VM1_SIZE - NS_DATA_SIZE - PERSISTENT_DATA_SIZE - RSE_OTP_EMULATION_SRAM_SIZE)
#else
#define S_DATA_START    (VM0_BASE_S + FLASH_S_PARTITION_SIZE)
#define S_DATA_SIZE     (VM0_SIZE - FLASH_S_PARTITION_SIZE)
#endif /* RSE_XIP */
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* Non-secure regions */
/* Non-Secure Code executes from VM1, or XIP from flash via the SIC */
#ifdef RSE_XIP
#define NS_CODE_START   (RSE_RUNTIME_NS_XIP_BASE_NS)
#define NS_CODE_SIZE    (FLASH_NS_PARTITION_SIZE)
#else
#define NS_CODE_START   (NS_DATA_START + NS_DATA_SIZE + BL2_HEADER_SIZE)
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#endif /* RSE_XIP */
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

/* Non-Secure Data stored after secure data, or in VM1 if not in XIP mode. */
#ifdef RSE_XIP
#define NS_DATA_START   (VM0_BASE_NS + S_DATA_SIZE)
#else
#define NS_DATA_START   (VM1_BASE_NS)
/* In the case of non-XIP configs, the NS data section size is controlled by the
 * size of the NS image (with the NS image plus data section taking up the whole
 * of VM1) so platforms should instead alter the size of the NS image.
 */
#undef  NS_DATA_SIZE
#define NS_DATA_SIZE \
    (VM1_SIZE - FLASH_NS_PARTITION_SIZE - PERSISTENT_DATA_SIZE - RSE_OTP_EMULATION_SRAM_SIZE)
#endif
#define NS_DATA_LIMIT   (NS_DATA_START + NS_DATA_SIZE - 1)

/* NS partition information is used for MPC and SAU configuration */
#ifdef RSE_XIP
#define NS_PARTITION_START RSE_RUNTIME_NS_XIP_BASE_NS
#else
#define NS_PARTITION_START (NS_DATA_START + NS_DATA_SIZE)
#endif /* RSE_XIP */
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)

#define SECONDARY_PARTITION_START (FWU_HOST_IMAGE_BASE_S)
#define SECONDARY_PARTITION_SIZE (HOST_IMAGE_MAX_SIZE)

/* RSE test binary is XIP from ROM */
#if defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_ROM)
#define RSE_TESTS_CODE_START (ROM_BASE_S + ROM_SIZE - ROM_DMA_ICS_SIZE - RSE_TESTS_CODE_SIZE)
#define RSE_TESTS_CODE_SIZE  (0x8000) /* 32 KiB */
#define RSE_TESTS_DATA_START VM0_BASE_S
#define RSE_TESTS_DATA_SIZE  VM0_SIZE + VM1_SIZE
#else
#define RSE_TESTS_CODE_SIZE  (0x0)
#define RSE_TESTS_DATA_SIZE  (0x0)
#endif /* defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_ROM) */

/* Bootloader regions */
/* BL1_1 is XIP from ROM */
#define BL1_1_CODE_START  (ROM_BASE_S)
#define BL1_1_CODE_SIZE   (ROM_SIZE - ROM_DMA_ICS_SIZE - RSE_TESTS_CODE_SIZE)
#define BL1_1_CODE_LIMIT  (BL1_1_CODE_START + BL1_1_CODE_SIZE - 1)

#define PROVISIONING_DATA_START (BL1_1_CODE_START + BL1_1_CODE_SIZE)
#define PROVISIONING_DATA_SIZE  (0x2400) /* 9 KB */
#define PROVISIONING_DATA_LIMIT (PROVISIONING_DATA_START + PROVISIONING_DATA_SIZE - 1)

/* BL1_2 is in the ITCM */
#define BL1_2_CODE_START  (PROVISIONING_BUNDLE_CODE_START + PROVISIONING_BUNDLE_CODE_SIZE)
#define BL1_2_CODE_SIZE   (0x2000) /* 8 KiB */
#define BL1_2_CODE_LIMIT  (BL1_2_CODE_START + BL1_2_CODE_SIZE - 1)

/* BL2 is aligned to the start of the combined secure/non-secure data region */
#define BL2_IMAGE_START   (S_DATA_START)
#define BL2_CODE_START    (BL2_IMAGE_START + TFM_BL1_2_HEADER_MAX_SIZE)
#define BL2_CODE_SIZE     (IMAGE_BL2_CODE_SIZE)
#define BL2_CODE_LIMIT    (BL2_CODE_START + BL2_CODE_SIZE - 1)

/* BL1 data is in DTCM */
#define BL1_1_DATA_START  (BOOT_TFM_SHARED_DATA_BASE + BOOT_TFM_SHARED_DATA_SIZE)
#define BL1_1_DATA_SIZE   (0x4800) /* 18 KiB */
#define BL1_1_DATA_LIMIT  (BL1_1_DATA_START + BL1_1_DATA_SIZE - 1)

#define BL1_2_DATA_START  (BL1_1_DATA_START + BL1_1_DATA_SIZE)
#define BL1_2_DATA_SIZE   (0x800) /* 2 KiB */
#define BL1_2_DATA_LIMIT  (BL1_2_DATA_START + BL1_2_DATA_SIZE - 1)

/* XIP data goes after the BL2 image */
#define BL2_XIP_TABLES_START (BL2_IMAGE_START + FLASH_BL2_PARTITION_SIZE)
#define BL2_XIP_TABLES_SIZE  (FLASH_SIC_TABLE_SIZE * 2)
#define BL2_XIP_TABLES_LIMIT (BL2_XIP_TABLES_START + BL2_XIP_TABLES_SIZE - 1)

/* BL2 data is after the code. TODO FIXME this should be in DTCM once the CC3XX
 * runtime driver supports DMA remapping.
 */
#define BL2_DATA_START    (BL2_XIP_TABLES_START + BL2_XIP_TABLES_SIZE)
#define BL2_DATA_SIZE                                                                              \
    (VM0_SIZE + VM1_SIZE - BL2_XIP_TABLES_SIZE - FLASH_BL2_PARTITION_SIZE - PERSISTENT_DATA_SIZE - \
     RSE_OTP_EMULATION_SRAM_SIZE)
#define BL2_DATA_LIMIT    (BL2_DATA_START + BL2_DATA_SIZE - 1)

/* We use various calculations which give some sections space remaining
 * after removing the size of other sections. Verify that all
 * of those calculations are valid here */
#if BL1_1_CODE_SIZE < 0 || \
    BL1_1_DATA_SIZE < 0 || \
    BL1_2_CODE_SIZE < 0 || \
    BL1_2_DATA_SIZE < 0 || \
    BL2_CODE_SIZE < 0 || \
    BL2_DATA_SIZE < 0 || \
    S_CODE_SIZE < 0 || \
    S_DATA_SIZE < 0 || \
    NS_CODE_SIZE < 0 || \
    NS_DATA_SIZE < 0
#error Partition size calculations incorrect
#endif

#if ((BL2_CODE_SIZE + BL2_XIP_TABLES_SIZE + BL2_DATA_SIZE + PERSISTENT_DATA_SIZE + \
      RSE_OTP_EMULATION_SRAM_SIZE) > (VM0_SIZE + VM1_SIZE))
#error BL2 partitions do not fit in SRAM
#endif

#if defined(RSE_XIP) && ((S_DATA_SIZE + NS_DATA_SIZE + PERSISTENT_DATA_SIZE + \
                          RSE_OTP_EMULATION_SRAM_SIZE) > (VM0_SIZE + VM1_SIZE))
#error XIP enabled runtime partitions do not fit in SRAM
#elif !defined(RSE_XIP) &&                                                             \
    ((S_CODE_SIZE + S_DATA_SIZE + NS_CODE_SIZE + NS_DATA_SIZE + PERSISTENT_DATA_SIZE + \
      RSE_OTP_EMULATION_SRAM_SIZE) > (VM0_SIZE + VM1_SIZE))
#error XIP disabled runtime partitions do not fit in SRAM
#endif

/* TODO: Shared data can be placed in the SRAM. Move it there
 * so that there is more space for the provisioning blob values */
#define BOOT_TFM_SHARED_DATA_BASE (PROVISIONING_BUNDLE_VALUES_START + PROVISIONING_BUNDLE_VALUES_SIZE)
#define BOOT_TFM_SHARED_DATA_SIZE (0x600)
#define BOOT_TFM_SHARED_DATA_LIMIT (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE 0x5C0

#define RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_BASE (SHARED_BOOT_MEASUREMENT_BASE + \
                                                    SHARED_BOOT_MEASUREMENT_SIZE)
#define RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE 0x40
#if SHARED_BOOT_MEASUREMENT_SIZE + RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE > BOOT_TFM_SHARED_DATA_SIZE
#error Shared data regions size is too large to fit in BOOT_TFM_SHARED_DATA_SIZE
#endif

#define PROVISIONING_BUNDLE_CODE_START   (ITCM_BASE_S)
#define PROVISIONING_BUNDLE_CODE_SIZE    (ITCM_SIZE - BL1_2_CODE_SIZE)
#define PROVISIONING_BUNDLE_VALUES_START (DTCM_BASE_S)
#define PROVISIONING_BUNDLE_VALUES_SIZE  (DTCM_SIZE - BOOT_TFM_SHARED_DATA_SIZE - BL1_1_DATA_SIZE - BL1_2_DATA_SIZE)
#define PROVISIONING_BUNDLE_DATA_START   (VM1_BASE_S)
#define PROVISIONING_BUNDLE_DATA_SIZE    (VM1_SIZE - PERSISTENT_DATA_SIZE - RSE_OTP_EMULATION_SRAM_SIZE)

/* Blob chainloading requires us to limit the size of the blob
 * to allow for loading two blobs simultaneously. It is simpler just
 * to always limit the main blob size and it should still have
 * plenty of space */
#define MAIN_BUNDLE_CODE_SIZE (PROVISIONING_BUNDLE_CODE_SIZE / 2)

/* Fixed address to use to store the current provisioning message in memory. This
 * allows for both pre-loading of the provisioning message into the memory in the
 * case where we do not use the comms HAL, and also an unused block of memory
 * where the comms HAL can load the message to when we are */
#define PROVISIONING_MESSAGE_START (VM0_BASE_S + OTP_DMA_ICS_SIZE)
#define RSE_PROVISIONING_MESSAGE_MAX_SIZE (VM1_BASE_S - PROVISIONING_MESSAGE_START)

#define RSE_TESTS_HEAP_SIZE      0x1000
#define RSE_TESTS_MSP_STACK_SIZE 0x1800

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
#define ADAC_SERVICE_TO_BOOT_SHARED_REGION_BASE  RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_BASE
#define ADAC_SERVICE_TO_BOOT_SHARED_REGION_SIZE  RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

#endif /* __REGION_DEFS_H__ */

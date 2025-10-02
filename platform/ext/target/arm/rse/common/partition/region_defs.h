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
#if defined(RSE_BL1_TEST_BINARY) && !defined(RSE_TEST_BINARY_IN_SRAM)
#include "rse_test_binary_location.h"
#endif /* defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM) */
#include "bl1_2_config.h"

/* RSE memory layout diagram
 *
 * This corresponds to the default memory sizing in rse_memory_sizes_common. It
 * can be overridden by subplatforms.
 *
 * ? indicates an optional memory block
 * > indicates that if the size of the memory increases, or optional memory
 *   blocks are disabled, that partition will automatically increase in size.
 *
 *
 * RSE memory layout is as follows during BL1_1
 *      |----------------------------------------------------------------------|
 * DTCM | 4 Blob Secrets | 28 BL1_1_DATA                                       |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * ITCM | 32 Blob code                                                         |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * VM0  | 64 BL1_2                                                             |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  | 20 Blob data | >26 Blob      | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 * If the BL1 test binary is used, it is preloaded into the space where BL1_2 is
 * will be loaded. The data is places in VM1 where the blob would be loaded.
 *      |----------------------------------------------------------------------|
 * VM0  | 1 reserved | 63 Test Code                                            |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  | >46 Test Data                | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 * RSE memory layout is as follows during BL1_2
 *      |----------------------------------------------------------------------|
 * DTCM | 4 Blob Secrets | 28 BL1_2_DATA                                       |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * ITCM | 32 Blob code                                                         |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * VM0  | 64 BL1_2                                                             |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  | 20 Blob data | >26 Blob      | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 *  If the blob handler does not run, VM1 is used to load BL2 code
 *
 *      |----------------------------------------------------------------------|
 * VM1  | >46 BL2 code                 | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 * RSE memory layout is as follows during BL2
 *      |----------------------------------------------------------------------|
 * DTCM |                                                                      |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * ITCM |                                                                      |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * VM0  | ?16 XIP tables | >48 BL2 Data                                        |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  | 46 BL2 code                  | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 * RSE memory layout is as follows during Runtime
 *      |----------------------------------------------------------------------|
 * DTCM | 32 Crypto partition data                                             |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * ITCM | 32 SPM code                                                          |
 *      |----------------------------------------------------------------------|
 *
 *      |----------------------------------------------------------------------|
 * VM0  | >64 S data + ?NS data + ?NS code + ?S code                           |
 *      |----------------------------------------------------------------------|
 *      |----------------------------------------------------------------------|
 * VM1  | >46 (continued)    | 14 Blob | 2 Persistent data | ?16 OTP emulation |
 *      |----------------------------------------------------------------------|
 *
 *  The exact split of the combined S data + NS data + NS code + S code section
 *  is determined by the integration. If NS is disabled then the NS sections can
 *  be size 0. If RSE_XIP is enabled both code sections will be size 0 (as they
 *  will be streamed via the SIC). All unused space will be used by S data.
 */

#define S_ADDRESS_TO_NS(addr) ((addr) - 0x10000000)
#define NS_ADDRESS_TO_S(addr) ((addr) + 0x10000000)

//==============================================================================

#define IMAGE_BL1_1_CODE_SIZE (ROM_BL1_1_CODE_SIZE)

#define IMAGE_BL1_2_CODE_SIZE (OTP_BL1_2_CODE_SIZE)

#define IMAGE_BL2_CODE_SIZE \
            (FLASH_BL2_PARTITION_SIZE - TFM_BL1_2_HEADER_MAX_SIZE)

#define IMAGE_S_CODE_SIZE \
            (FLASH_S_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)

#ifdef TFM_LOAD_NS_IMAGE
#define IMAGE_NS_CODE_SIZE \
            (FLASH_NS_PARTITION_SIZE - BL2_HEADER_SIZE - BL2_TRAILER_SIZE)
#else
#undef FLASH_NS_PARTITION_SIZE
#define FLASH_NS_PARTITION_SIZE 0
#define IMAGE_NS_CODE_SIZE 0
#endif /* TFM_LOAD_NS_IMAGE */

#ifdef RSE_XIP
#ifdef TFM_LOAD_NS_IMAGE
#define RSE_SIC_TABLE_AMOUNT 2
#else
#define RSE_SIC_TABLE_AMOUNT 1
#endif /* TFM_LOAD_NS_IMAGE */
#else
#define RSE_SIC_TABLE_AMOUNT 0
#endif /* RSE_XIP */

//==============================================================================

#define RSE_OTP_EMULATION_SRAM_START (VM1_BASE_S + VM1_SIZE - RSE_OTP_EMULATION_SRAM_SIZE)
#define RSE_OTP_EMULATION_SRAM_LIMIT (RSE_OTP_EMULATION_SRAM_START + RSE_OTP_EMULATION_SRAM_SIZE - 1)

#define PERSISTENT_DATA_BASE (RSE_OTP_EMULATION_SRAM_START - PERSISTENT_DATA_SIZE)
#define PERSISTENT_DATA_LIMIT (PERSISTENT_DATA_BASE + PERSISTENT_DATA_SIZE - 1)

#define PROVISIONING_MESSAGE_START \
     ((VM1_SIZE - VM_COLD_RESET_RETAINED_SIZE - PROVISIONING_BUNDLE_DATA_SIZE) < 0 ? \
      VM1_BASE_S + PROVISIONING_BUNDLE_DATA_SIZE : \
      VM1_BASE_S + VM1_SIZE - VM_COLD_RESET_RETAINED_SIZE)
#define RSE_PROVISIONING_MESSAGE_MAX_SIZE  (VM1_BASE_S + VM1_SIZE - \
                                            PROVISIONING_MESSAGE_START \
                                            - RSE_OTP_EMULATION_SRAM_SIZE \
                                            - PERSISTENT_DATA_SIZE)

#define RUNTIME_PROVISIONING_MESSAGE_START (VM1_BASE_S + VM1_SIZE - \
                                            RSE_OTP_EMULATION_SRAM_SIZE - \
                                            PERSISTENT_DATA_SIZE - \
                                            RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE)

/* FIXME use entire ITCM once code-sharing is removed */
#define PROVISIONING_BUNDLE_CODE_START   (ITCM_BASE_S)
#define PROVISIONING_BUNDLE_CODE_SIZE    (ITCM_SIZE / 2)

#define PROVISIONING_BUNDLE_VALUES_START (DTCM_BASE_S)

#define PROVISIONING_BUNDLE_DATA_START   (VM1_BASE_S)

#define BL1_1_CODE_START  (ROM_BASE_S)
#define BL1_1_CODE_SIZE   (IMAGE_BL1_1_CODE_SIZE)
#define BL1_1_CODE_LIMIT  (BL1_1_CODE_START + BL1_1_CODE_SIZE - 1)

#define BL1_1_DATA_START  (DTCM_BASE_S + PROVISIONING_BUNDLE_VALUES_SIZE)
#define BL1_1_DATA_SIZE   (0x4800) /* 18 KiB FIXME increase once code-sharing is removed */
#define BL1_1_DATA_LIMIT  (BL1_1_DATA_START + BL1_1_DATA_SIZE - 1)

/* FIXME once code-sharing is removed, BL1_2 should be run from VM0 */
/* #define BL1_2_CODE_START  (VM0_BASE_S) */
#define BL1_2_CODE_START  (PROVISIONING_BUNDLE_CODE_START + PROVISIONING_BUNDLE_CODE_SIZE)
#define BL1_2_CODE_SIZE   (IMAGE_BL1_2_CODE_SIZE)
#define BL1_2_CODE_LIMIT  (BL1_2_CODE_START + BL1_2_CODE_SIZE - 1)

#define BL1_2_DATA_START  (BL1_1_DATA_START + BL1_1_DATA_SIZE)
#define BL1_2_DATA_SIZE   (0x800) /* 2 KiB FIXME overlap once code-sharing is removed */
#define BL1_2_DATA_LIMIT  (BL1_2_DATA_START + BL1_2_DATA_SIZE - 1)

#define BL2_IMAGE_START (VM1_BASE_S)
#define BL2_CODE_START  (BL2_IMAGE_START + TFM_BL1_2_HEADER_MAX_SIZE)
#define BL2_CODE_SIZE   (IMAGE_BL2_CODE_SIZE)
#define BL2_CODE_LIMIT  (BL2_CODE_START + BL2_CODE_SIZE - 1)

#define BL2_XIP_TABLES_START (VM0_BASE_S)
#define BL2_XIP_TABLES_SIZE  (FLASH_SIC_TABLE_SIZE * RSE_SIC_TABLE_AMOUNT)
#define BL2_XIP_TABLES_LIMIT (BL2_XIP_TABLES_START + BL2_XIP_TABLES_SIZE - 1)

#define BL2_DATA_START  (VM0_BASE_S + BL2_XIP_TABLES_SIZE)
#define BL2_DATA_SIZE   (VM0_SIZE - BL2_XIP_TABLES_SIZE)
#define BL2_DATA_LIMIT  (BL2_DATA_START + BL2_DATA_SIZE - 1)

#ifdef RSE_XIP
#define S_CODE_START    (RSE_RUNTIME_S_XIP_BASE_S)
#define S_CODE_SIZE     (FLASH_S_PARTITION_SIZE)
#else
#define S_CODE_START    (S_IMAGE_LOAD_ADDRESS + BL2_HEADER_SIZE)
#define S_CODE_SIZE     (IMAGE_S_CODE_SIZE)
#endif /* RSE_XIP */
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START    VM0_BASE_S
#ifdef RSE_XIP
#define S_DATA_SIZE     (VM0_SIZE + VM1_SIZE - NS_DATA_SIZE - RSE_OTP_EMULATION_SRAM_SIZE - \
                        PERSISTENT_DATA_SIZE - RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE)
#else
#define S_DATA_SIZE     (VM0_SIZE + VM1_SIZE - FLASH_S_PARTITION_SIZE - \
                        FLASH_NS_PARTITION_SIZE - NS_DATA_SIZE - \
                        RSE_OTP_EMULATION_SRAM_SIZE - PERSISTENT_DATA_SIZE - \
                        RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE)
#endif
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

#define S_RUNTIME_DTCM_START (DTCM_BASE_S)
#define S_RUNTIME_DTCM_SIZE  (DTCM_SIZE)
#define S_RUNTIME_ITCM_START (ITCM_BASE_S)
#define S_RUNTIME_ITCM_SIZE  (ITCM_SIZE)

#ifdef RSE_XIP
#define NS_CODE_START   (RSE_RUNTIME_NS_XIP_BASE_NS)
#define NS_CODE_SIZE    (FLASH_NS_PARTITION_SIZE)
#else
#define NS_CODE_START   (S_ADDRESS_TO_NS(NS_IMAGE_LOAD_ADDRESS + BL2_HEADER_SIZE))
#define NS_CODE_SIZE    (IMAGE_NS_CODE_SIZE)
#endif /* RSE_XIP */
#define NS_CODE_LIMIT   (NS_CODE_START + NS_CODE_SIZE - 1)

#define NS_DATA_START    (S_ADDRESS_TO_NS(S_DATA_START + S_DATA_SIZE))
#define NS_DATA_LIMIT    (NS_DATA_START + NS_DATA_SIZE - 1)

#define NS_PARTITION_START S_ADDRESS_TO_NS(NS_IMAGE_LOAD_ADDRESS)
#define NS_PARTITION_SIZE (FLASH_NS_PARTITION_SIZE)

/* RSE ROM test binary is preloaded to VM0 */
#if defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM)
#define RSE_TESTS_CODE_START (VM0_BASE_S + OTP_DMA_ICS_SIZE)
#define RSE_TESTS_CODE_SIZE  (VM1_BASE_S - RSE_TESTS_CODE_START)
#define RSE_TESTS_DATA_START (VM1_BASE_S)
#define RSE_TESTS_DATA_SIZE  (VM1_SIZE - RSE_OTP_EMULATION_SRAM_SIZE - PERSISTENT_DATA_SIZE)
#endif /* defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM) */

#define SECONDARY_PARTITION_START (FWU_HOST_IMAGE_BASE_S)
#define SECONDARY_PARTITION_SIZE (HOST_IMAGE_MAX_SIZE)

/* Blob chainloading requires us to limit the size of the blob
 * to allow for loading two blobs simultaneously. It is simpler just
 * to always limit the main blob size and it should still have
 * plenty of space */
#define MAIN_BUNDLE_CODE_SIZE (PROVISIONING_BUNDLE_CODE_SIZE / 2)

//==============================================================================

#define _VM_RESET_RETAINED_USED RSE_OTP_EMULATION_SRAM_SIZE + \
                                PERSISTENT_DATA_SIZE + \
                                RSE_PROVISIONING_MESSAGE_MAX_SIZE

#if _VM_RESET_RETAINED_USED > VM_COLD_RESET_RETAINED_SIZE
#error "RSE_OTP_EMULATION_SRAM_SIZE + PERSISTENT_DATA_SIZE + RSE_PROVISIONING_MESSAGE_MAX_SIZE > VM_COLD_RESET_RETAINED_SIZE"
#endif

#if FLASH_BL2_PARTITION_SIZE + RSE_OTP_EMULATION_SRAM_SIZE + PERSISTENT_DATA_SIZE > VM1_SIZE
#error "FLASH_BL2_PARTITION_SIZE + RSE_OTP_EMULATION_SRAM_SIZE + PERSISTENT_DATA_SIZE + RSE_PROVISIONING_MESSAGE_MAX_SIZE > VM1_SIZE"
#endif

#if PROVISIONING_BUNDLE_DATA_SIZE + _COLD_RESET_RETAINED_USED > VM1_SIZE
#error "PROVISIONING_BUNDLE_DATA_SIZE + RSE_OTP_EMULATION_SRAM_SIZE + PERSISTENT_DATA_SIZE + RSE_PROVISIONING_MESSAGE_MAX_SIZE > VM1_SIZE"
#endif

#if S_IMAGE_LOAD_ADDRESS < BL2_IMAGE_START + IMAGE_BL2_CODE_SIZE && \
    FLASH_S_PARTITION_SIZE + FLASH_SIC_TABLE_SIZE > BL2_IMAGE_START
#error "S_IMAGE_LOAD_ADDRESS < BL2_IMAGE_START + BL2_CODE_SIZE. Decrease NS_DATA_SIZE, FLASH_NS_PARTITION_SIZE or FLASH_S_PARTITION_SIZE"
#endif

#if NS_ADDRESS_TO_S(NS_IMAGE_LOAD_ADDRESS) < BL2_IMAGE_START + IMAGE_BL2_CODE_SIZE && \
    FLASH_S_PARTITION_SIZE + FLASH_NS_PARTITION_SIZE + FLASH_SIC_TABLE_SIZE > BL2_IMAGE_START
#error "NS_IMAGE_LOAD_ADDRESS < BL2_IMAGE_START + BL2_CODE_SIZE. Decrease FLASH_NS_PARTITION_SIZE or FLASH_S_PARTITION_SIZE"
#endif

#if S_DATA_SIZE <= 0
#error "S_DATA_SIZE <= 0. Decrease NS_DATA_SIZE, FLASH_NS_PARTITION_SIZE or FLASH_S_PARTITION_SIZE"
#endif

#if RSE_PROVISIONING_MESSAGE_MAX_SIZE < 0
#error "RSE_PROVISIONING_MESSAGE_MAX_SIZE < 0. Decrease PROVISIONING_BUNDLE_DATA_SIZE"
#endif

#if RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE > RSE_PROVISIONING_MESSAGE_MAX_SIZE
#error "RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE < RSE_PROVISIONING_MESSAGE_MAX_SIZE. Decrease RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE"
#endif

#endif /* __REGION_DEFS_H__ */

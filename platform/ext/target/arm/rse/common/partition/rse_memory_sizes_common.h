/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_MEMORY_SIZES_COMMON_H__
#define __RSE_MEMORY_SIZES_COMMON_H__

#ifndef VM0_SIZE
#ifdef RSE_XIP
#define VM0_SIZE                         0x00010000 /* 64 KiB */
#else
#define VM0_SIZE                         0x00080000 /* 512 KiB */
#endif /* RSE_XIP */
#endif /* !VM0_SIZE */

#ifndef VM1_SIZE
#define VM1_SIZE VM0_SIZE
#endif

/* The uppermost RETAINED_RAM_SIZE bytes of VM1 are retained after cold reset */
#ifndef RETAINED_RAM_SIZE
#ifdef RSE_XIP
#if defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM)
#define RETAINED_RAM_SIZE                0x00008000 /* 32 KiB */
#else
#define RETAINED_RAM_SIZE                0x0000B000 /* 44 KiB */
#endif
#else /* RSE_XIP */
#define RETAINED_RAM_SIZE                0x00020000 /* 128 KiB */
#endif /* RSE_XIP */
#endif /*RETAINED_RAM_SIZE */

#ifndef NS_DATA_SIZE
#ifdef TFM_LOAD_NS_IMAGE
#define NS_DATA_SIZE (0x5000)
#else
#define NS_DATA_SIZE (0)
#endif /* TFM_LOAD_NS_IMAGE */
#endif /* !NS_DATA_SIZE */

#ifndef OTP_DMA_ICS_SIZE
#define OTP_DMA_ICS_SIZE   0x400 /* 1 KiB*/
#endif

#ifndef ROM_DMA_ICS_SIZE
#define ROM_DMA_ICS_SIZE   0x1000 /* 4 KiB */
#endif

/* Memory allocated to storing persistent data */
#ifndef PERSISTENT_DATA_SIZE
#define PERSISTENT_DATA_SIZE (0x800)
#endif


#ifndef SHARED_BOOT_MEASUREMENT_SIZE
#define SHARED_BOOT_MEASUREMENT_SIZE (0x5C0)
#endif

#ifndef RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE
#define RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE (0x40)
#endif

/* SRAM allocated to store data when using OTP emulation mode.
 * This must match the size of the OTP.
 */
#ifdef RSE_USE_OTP_EMULATION_IN_SRAM
#define RSE_OTP_EMULATION_SRAM_SIZE     (0x4000)
#else
#define RSE_OTP_EMULATION_SRAM_SIZE     (0x0)
#endif /* RSE_USE_OTP_EMULATION_IN_SRAM */

/* This size of buffer is big enough to store an array of all the
 * boot records/measurements which is encoded in CBOR format.
 */
#ifndef TFM_ATTEST_BOOT_RECORDS_MAX_SIZE
#define TFM_ATTEST_BOOT_RECORDS_MAX_SIZE    (0x400)
#endif

#ifndef ROM_BL1_1_CODE_SIZE
#define ROM_BL1_1_CODE_SIZE (ROM_SIZE - ROM_DMA_ICS_SIZE)
#endif

#ifndef OTP_BL1_2_CODE_SIZE
#define OTP_BL1_2_CODE_SIZE (0x2000)
#endif

//==============================================================================

/* Heap and stack shared between BL1_1 and BL1_2 */
#ifndef BL1_HEAP_SIZE
#define BL1_HEAP_SIZE           (0x0001000)
#endif
#ifndef BL1_MSP_STACK_SIZE
#define BL1_MSP_STACK_SIZE      (0x0001800)
#endif

#ifndef BL2_HEAP_SIZE
#define BL2_HEAP_SIZE           (0x0001000)
#endif
#ifndef BL2_MSP_HEAP_SIZE
#define BL2_MSP_STACK_SIZE      (0x0002000)
#endif

#ifndef S_HEAP_SIZE
#define S_HEAP_SIZE             (0x0001000)
#endif
#ifndef S_MSP_STACK_SIZE
#define S_MSP_STACK_SIZE        (0x0000800)
#endif

#ifdef TFM_LOAD_NS_IMAGE
#ifndef NS_HEAP_SIZE
#define NS_HEAP_SIZE            (0x0000600)
#endif
#ifndef NS_STACK_SIZE
#define NS_STACK_SIZE           (0x0001000)
#endif
#endif /* TFM_LOAD_NS_IMAGE */

#ifndef RSE_TESTS_HEAP_SIZE
#define RSE_TESTS_HEAP_SIZE      0x1000
#endif

#ifndef RSE_TESTS_MSP_STACK_SIZE
#define RSE_TESTS_MSP_STACK_SIZE 0x1800
#endif

//==============================================================================

/* The maximum size of provisioning message which can input in the runtime */
#ifndef RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE
#define RUNTIME_PROVISIONING_MESSAGE_MAX_SIZE  (0x3800) /* 14KiB */
#endif

#ifndef PROVISIONING_BUNDLE_VALUES_SIZE
#define PROVISIONING_BUNDLE_VALUES_SIZE  (0x1000) /* 4KiB */
#endif

#ifndef PROVISIONING_BUNDLE_DATA_SIZE
#define PROVISIONING_BUNDLE_DATA_SIZE    (0x5000) /* 20KiB */
#endif

#endif /* __RSE_MEMORY_SIZES_COMMON_H__ */

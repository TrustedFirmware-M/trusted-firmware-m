/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef REGION_DEFS_H
#define REGION_DEFS_H

#include "flash_layout.h"

#ifdef IFX_S_LINKER_ALIGNMENTS_HEADER
/* Include file with custom alignments for secure linker sections */
#include IFX_S_LINKER_ALIGNMENTS_HEADER
#endif /* IFX_S_LINKER_ALIGNMENTS_HEADER */

/* Size of secure vector table in bytes */
/* Ideally S_CODE_VECTOR_TABLE_SIZE should reuse VECTORTABLE_SIZE definition
 * from BSP, but file that defines VECTORTABLE_SIZE has syntax which is not
 * compatible with linker (enums, UL postfixes, etc), thus, for simplicity,
 * S_CODE_VECTOR_TABLE_SIZE is defined as a value */
#define S_CODE_VECTOR_TABLE_SIZE            (0x354)

/* Define missing linker alignment constants */
#ifndef TFM_LINKER_NS_AGENT_TZ_CODE_ALIGNMENT
#define TFM_LINKER_NS_AGENT_TZ_CODE_ALIGNMENT   32
#endif

#define S_MSP_STACK_SIZE            (0x0002000)
#ifdef ENABLE_HEAP
    #define S_HEAP_SIZE             (0x0000100)
#endif
#define IFX_CM33_NS_MSP_STACK_SIZE  (0x0001000)
#define IFX_CM55_NS_MSP_STACK_SIZE  (0x0001000)

#if DOMAIN_NS
#if (IFX_CORE == IFX_CM33)
    /* CM33 user app */
    #define NS_MSP_STACK_SIZE       IFX_CM33_NS_MSP_STACK_SIZE
#elif (IFX_CORE == IFX_CM55)
    /* CM55 user app */
    #define NS_MSP_STACK_SIZE       IFX_CM55_NS_MSP_STACK_SIZE
#else
    #error Unsupported IFX_CORE
#endif /* (IFX_CORE == IFX_CM33) */
#endif /* DOMAIN_NS */

/* Secure regions */
#define S_CODE_START    (IFX_TFM_IMAGE_EXECUTE_ADDR + IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE))
#define S_CODE_SIZE     (IFX_TFM_IMAGE_EXECUTE_SIZE - IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE) - \
                                                      IFX_UNSIGNED_TO_VALUE(BL2_TRAILER_SIZE))
#define S_CODE_LIMIT    (S_CODE_START + S_CODE_SIZE - 1)

#define S_DATA_START    (IFX_TFM_DATA_ADDR)
#define S_DATA_SIZE     (IFX_TFM_DATA_SIZE)
#define S_DATA_LIMIT    (S_DATA_START + S_DATA_SIZE - 1)

/* Non-secure regions */
#if IFX_CM33_NS_PRESENT
/* CM33 user image */
    #define IFX_CM33_NS_CODE_START      (IFX_CM33_NS_IMAGE_EXECUTE_ADDR \
                                         + IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE))
    #define IFX_CM33_NS_CODE_SIZE       (IFX_CM33_NS_IMAGE_EXECUTE_SIZE \
                                         - IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE) \
                                         - IFX_UNSIGNED_TO_VALUE(BL2_TRAILER_SIZE))
    #define IFX_CM33_NS_CODE_LIMIT      (IFX_CM33_NS_CODE_START + IFX_CM33_NS_CODE_SIZE - 1)

    #define IFX_CM33_NS_DATA_LIMIT      (IFX_CM33_NS_DATA_ADDR + IFX_CM33_NS_DATA_SIZE - 1)
#endif

#if IFX_CM55_NS_PRESENT
/* CM55 user image */
    #define IFX_CM55_NS_CODE_START      (IFX_CM55_NS_IMAGE_EXECUTE_ADDR \
                                         + IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE))
    #define IFX_CM55_NS_CODE_SIZE       (IFX_CM55_NS_IMAGE_EXECUTE_SIZE \
                                         - IFX_UNSIGNED_TO_VALUE(BL2_HEADER_SIZE) \
                                         - IFX_UNSIGNED_TO_VALUE(BL2_TRAILER_SIZE))
    #define IFX_CM55_NS_CODE_LIMIT      (IFX_CM55_NS_CODE_START + IFX_CM55_NS_CODE_SIZE - 1)

    #define IFX_CM55_NS_DATA_LIMIT      (IFX_CM55_NS_DATA_ADDR + IFX_CM55_NS_DATA_SIZE - 1)
#endif

#if DOMAIN_NS
#if (IFX_CORE == IFX_CM33)
    /* CM33 user app */
    #define NS_CODE_START   IFX_CM33_NS_CODE_START
    #define NS_CODE_SIZE    IFX_CM33_NS_CODE_SIZE
    #define NS_CODE_LIMIT   IFX_CM33_NS_CODE_LIMIT

    #define NS_DATA_START   IFX_CM33_NS_DATA_ADDR
    #define NS_DATA_SIZE    IFX_CM33_NS_DATA_SIZE
    #define NS_DATA_LIMIT   IFX_CM33_NS_DATA_LIMIT

    #define IFX_NS_SHARED_MEMORY_OFFSET     IFX_CM33_NS_SHARED_MEMORY_OFFSET
    #define IFX_NS_SHARED_MEMORY_ADDR       IFX_CM33_NS_SHARED_MEMORY_ADDR
    #define IFX_NS_SHARED_MEMORY_SIZE       IFX_CM33_NS_SHARED_MEMORY_SIZE
    #define IFX_NS_SHARED_MEMORY_LOCATION   IFX_CM33_NS_SHARED_MEMORY_LOCATION
#elif (IFX_CORE == IFX_CM55)
    /* CM55 user app */
    #define NS_CODE_START   IFX_CM55_NS_CODE_START
    #define NS_CODE_SIZE    IFX_CM55_NS_CODE_SIZE
    #define NS_CODE_LIMIT   IFX_CM55_NS_CODE_LIMIT

    #define NS_DATA_START   IFX_CM55_NS_DATA_ADDR
    #define NS_DATA_SIZE    IFX_CM55_NS_DATA_SIZE
    #define NS_DATA_LIMIT   IFX_CM55_NS_DATA_LIMIT

    #define IFX_NS_SHARED_MEMORY_OFFSET     IFX_CM55_NS_SHARED_MEMORY_OFFSET
    #define IFX_NS_SHARED_MEMORY_ADDR       IFX_CM55_NS_SHARED_MEMORY_ADDR
    #define IFX_NS_SHARED_MEMORY_SIZE       IFX_CM55_NS_SHARED_MEMORY_SIZE
    #define IFX_NS_SHARED_MEMORY_LOCATION   IFX_CM55_NS_SHARED_MEMORY_LOCATION
#else
    #error Unsupported IFX_CORE
#endif /* (IFX_CORE == IFX_CM33) */
#endif /* DOMAIN_NS */

/* Address used to boot off core NSPE from */
#define IFX_OFF_CORE_NSPE_BOOT_ADDR IFX_CM55_NS_CODE_START

/* Shared data area between bootloader and runtime firmware. */
#define BOOT_TFM_SHARED_DATA_BASE   IFX_TFM_BOOT_SHARED_DATA_ADDR
#define BOOT_TFM_SHARED_DATA_SIZE   IFX_TFM_BOOT_SHARED_DATA_SIZE
#define BOOT_TFM_SHARED_DATA_LIMIT  (BOOT_TFM_SHARED_DATA_BASE + \
                                    BOOT_TFM_SHARED_DATA_SIZE - 1)
#define SHARED_BOOT_MEASUREMENT_BASE BOOT_TFM_SHARED_DATA_BASE
#define SHARED_BOOT_MEASUREMENT_SIZE BOOT_TFM_SHARED_DATA_SIZE
#define SHARED_BOOT_MEASUREMENT_LIMIT BOOT_TFM_SHARED_DATA_LIMIT

/* Compile time check to verify that shared data region is not overlapping with
 * non-secure data areas.
 */
#ifdef IFX_ARM_CLANG_LINKER_SCRIPT
/* ARMClang linker has different syntax for bitwise operations (`or` instead
 * of `|`, `and` instead of `&`), so some macros are expended differently when
 * this file is included into ARMClang linker script which results in
 * preprocessor syntax error. Thus some checks are skipped for ARMClang linker
 * script. These checks are performed when this file is included into .c files,
 * so performing them additionally in linker script is redundant.
 */
#else /* IFX_ARM_CLANG_LINKER_SCRIPT */
#if IFX_CM33_NS_PRESENT
#if (((BOOT_TFM_SHARED_DATA_BASE  >= IFX_CM33_NS_DATA_ADDR) && \
      (BOOT_TFM_SHARED_DATA_BASE  <= IFX_CM33_NS_DATA_LIMIT)) || \
     ((BOOT_TFM_SHARED_DATA_LIMIT >= IFX_CM33_NS_DATA_ADDR) && \
      (BOOT_TFM_SHARED_DATA_LIMIT <= IFX_CM33_NS_DATA_LIMIT)))
#error "Shared data area and CM33 non-secure data area is overlapping"
#endif
#endif

#if IFX_CM55_NS_PRESENT
#if (((BOOT_TFM_SHARED_DATA_BASE  >= IFX_CM55_NS_DATA_ADDR) && \
      (BOOT_TFM_SHARED_DATA_BASE  <= IFX_CM55_NS_DATA_LIMIT)) || \
     ((BOOT_TFM_SHARED_DATA_LIMIT >= IFX_CM55_NS_DATA_ADDR) && \
      (BOOT_TFM_SHARED_DATA_LIMIT <= IFX_CM55_NS_DATA_LIMIT)))
#error "Shared data area and CM55 non-secure data area is overlapping"
#endif
#endif
#endif /* IFX_ARM_CLANG_LINKER_SCRIPT */

#endif /* REGION_DEFS_H */

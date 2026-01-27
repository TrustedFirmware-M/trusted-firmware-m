/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_STARTUP_H
#define IFX_STARTUP_H

#include "coverity_check.h"

#ifndef IS_POWER_OF_TWO
#define IS_POWER_OF_TWO(x) ((x) && !((x) & ((x) - 1)))
#endif

#ifndef VECTORTABLE_SIZE
    #error VECTORTABLE_SIZE must be defined
#endif /* VECTORTABLE_SIZE */

#ifndef VECTORTABLE_ALIGN
    #error VECTORTABLE_ALIGN must be defined
#endif /* VECTORTABLE_ALIGN */

/* Validate that vector table alignment is correct according to requirements
 * from "ARMv8-M Architecture Reference Manual" section "B4.29 Vector tables" */
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_12_1, "VECTORTABLE_ALIGN is defined externally, cannot change it")
#if (((VECTORTABLE_ALIGN / (VECTORTABLE_SIZE * 4)) < 1) || \
    (VECTORTABLE_ALIGN < 128) || (!(IS_POWER_OF_TWO(VECTORTABLE_ALIGN))))
    #error "VECTORTABLE_ALIGN is incorrect"
#endif
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_12_1)

typedef void(*VECTOR_TABLE_Type)(void);

/*********************** Compiler specific definitions ***********************/

#define IFX_VECTOR_TABLE_ATTRIBUTE __attribute__((aligned(VECTORTABLE_ALIGN))) __VECTOR_TABLE_ATTRIBUTE
extern const VECTOR_TABLE_Type __vector_table[VECTORTABLE_SIZE];

#ifdef RAM_VECTORS_SUPPORT
#ifndef __RAM_VECTOR_TABLE_ATTRIBUTE
#if defined(__ARMCC_VERSION)
    #define __RAM_VECTOR_TABLE_ATTRIBUTE __attribute__( ( section(".bss.noinit.RESET_RAM")))
#elif defined(__GNUC__)
    #define __RAM_VECTOR_TABLE_ATTRIBUTE __attribute__( ( section(".ram_vectors")))
#elif defined(__ICCARM__)
    #define __RAM_VECTOR_TABLE_ATTRIBUTE __attribute__( ( section(".ramvec")))
#else
    #error "Unsupported toolchain"
#endif /* (__ARMCC_VERSION) */
#endif /* __RAM_VECTOR_TABLE_ATTRIBUTE */

#define __IFX_RAM_VECTOR_TABLE_ATTRIBUTE __RAM_VECTOR_TABLE_ATTRIBUTE __attribute__((aligned(VECTORTABLE_ALIGN)))
extern VECTOR_TABLE_Type __vector_table_rw[VECTORTABLE_SIZE];
#endif /* RAM_VECTORS_SUPPORT */

/****************************** Default handler ******************************/
#ifndef DEFAULT_IRQ_HANDLER
#define DEFAULT_IRQ_HANDLER(handler_name) \
    __NO_RETURN void handler_name(void) __attribute__ ((weak, alias("Default_Handler")));
#endif /* DEFAULT_IRQ_HANDLER */

#endif /* IFX_STARTUP_H */

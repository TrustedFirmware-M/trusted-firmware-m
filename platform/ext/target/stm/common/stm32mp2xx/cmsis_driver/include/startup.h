/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __STARTUP_H
#define __STARTUP_H

extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

typedef void(*VECTOR_TABLE_Type)(void);
extern const VECTOR_TABLE_Type __VECTOR_TABLE[];

__NO_RETURN void __PROGRAM_START(void);

#define DEFAULT_EXCEPTION_HANDLER(handler_name) \
__NO_RETURN void __attribute__((weak, alias("default_exception_handler"))) handler_name(void);

#define DEFAULT_IRQ_HANDLER(handler_name) \
void __attribute__((weak, alias("default_irq_handler"))) handler_name(void);

__NO_RETURN void Reset_Handler(void);

#endif /* __STARTUP_H */

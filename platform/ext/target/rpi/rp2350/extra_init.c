/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "pico/runtime.h"
#include "pico/runtime_init.h"
#include "hardware/structs/scb.h"
#ifdef PSA_API_TEST_CRYPTO
#include "hardware/ticks.h"
#include "hardware/clocks.h"
#endif

#include "stdint.h"

/* Do not use __cmsis_start */
#define __PROGRAM_START
#include "tfm_hal_device_header.h"

void copy_zero_tables(void) {
    typedef struct {
        uint32_t const* src;
        uint32_t* dest;
        uint32_t  wlen;
    } __copy_table_t;

    typedef struct {
        uint32_t* dest;
        uint32_t  wlen;
    } __zero_table_t;

    extern const __copy_table_t __copy_table_start__;
    extern const __copy_table_t __copy_table_end__;
    extern const __zero_table_t __zero_table_start__;
    extern const __zero_table_t __zero_table_end__;

    for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
        for(uint32_t i=0u; i<pTable->wlen; ++i) {
            pTable->dest[i] = pTable->src[i];
        }
    }

    for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
        for(uint32_t i=0u; i<pTable->wlen; ++i) {
            pTable->dest[i] = 0u;
        }
    }
}

void hard_assertion_failure(void) {
    assert(0);
}

static void runtime_run_initializers_from(uintptr_t *from) {

    /* Start and end points of the constructor list, defined by the linker script. */
    extern uintptr_t __preinit_array_end;

    /* Call each function in the list, based on the mask
       We have to take the address of the symbols, as __preinit_array_start *is*
       the first function value, not the address of it. */
    for (uintptr_t *p = from; p < &__preinit_array_end; p++) {
        uintptr_t val = *p;
        ((void (*)(void))val)();
    }
}

void runtime_run_initializers(void) {
    extern uintptr_t __preinit_array_start;
    runtime_run_initializers_from(&__preinit_array_start);
}

/* We keep the per-core initializers in the standard __preinit_array so a standard C library
   initialization will fo the core 0 initialization, however we also want to be able to find
   them after the fact so that we can run them on core 1. Per core initializers have sections
   __preinit_array.ZZZZZ.nnnnn i.e. the ZZZZZ sorts below all the standard __preinit_array.nnnnn
   values, and then we sort within the ZZZZZ.

   We create a dummy initializer in __preinit_array.YYYYY (between the standard initializers
   and the per core initializers), so we find the first per core initializer. Whilst we could
   have done this via an entry in the linker script, we want to preserve backwards compatibility
   with RP2040 custom linker scripts. */
static void first_per_core_initializer(void) {}
PICO_RUNTIME_INIT_FUNC(first_per_core_initializer, "YYYYY");

void runtime_run_per_core_initializers(void) {
    runtime_run_initializers_from(&__pre_init_first_per_core_initializer);
}

extern uint32_t __vectors_start__;
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
extern uint64_t __STACK_SEAL;

void runtime_init(void) {
    scb_hw->vtor = (uintptr_t) &__vectors_start__;
    copy_zero_tables();

    __disable_irq();
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));

    runtime_run_initializers();

#ifdef PSA_API_TEST_CRYPTO
    /* RSA Key generation test takes very long. Use 4 times slower WD
       reference tick when it is enabled. */
    tick_start(TICK_WATCHDOG, 4 * clock_get_hz(clk_ref) / MHZ);
#endif

    SystemInit();
}

/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "hardware/clocks.h"

#ifdef TFM_MULTI_CORE_TOPOLOGY
#include "hardware/structs/sio.h"
#include "hardware/structs/scb.h"
#include "tfm_multi_core_api.h"
#endif

#include <stdint.h>

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

void __weak hard_assertion_failure(void) {
    panic("Hard assert");
}

extern void runtime_init_install_ram_vector_table(void);
extern uint32_t ram_vector_table[PICO_RAM_VECTOR_TABLE_SIZE];

void runtime_init(void) {
#ifdef TFM_MULTI_CORE_TOPOLOGY
    if(sio_hw->cpuid == 0) {
        scb_hw->vtor = (uintptr_t) ram_vector_table;
        return;
    }
#endif
    copy_zero_tables();
    runtime_init_install_ram_vector_table();

    /* These are already configured by the Secure side, just fill the array */
    clock_set_reported_hz(clk_ref, XOSC_KHZ * KHZ);
    clock_set_reported_hz(clk_sys, SYS_CLK_KHZ * KHZ);
    clock_set_reported_hz(clk_peri, SYS_CLK_KHZ * KHZ);
    clock_set_reported_hz(clk_hstx, SYS_CLK_KHZ * KHZ);
    clock_set_reported_hz(clk_usb, USB_CLK_KHZ * KHZ);
    clock_set_reported_hz(clk_adc, USB_CLK_KHZ * KHZ);

    SystemInit();
}

#ifdef TFM_MULTI_CORE_TOPOLOGY
int32_t tfm_ns_wait_for_s_cpu_ready(void)
{
    return tfm_platform_ns_wait_for_s_cpu_ready();
}
#endif

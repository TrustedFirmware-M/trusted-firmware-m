/*
 * Copyright (c) 2018-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2020, Nordic Semiconductor ASA. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "tfm_hal_device_header.h"
#include "spu.h"
#include "utilities.h"
#include "nrf_exception_info.h"
#include "flash_layout.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

/* Value indicating Secure Invasive Debug is enabled*/
#define DAUTHSTATUS_SID_ENABLED          (0x3UL << DIB_DAUTHSTATUS_SID_Pos)

/*
 * Check if an address is within valid code/data memory ranges for this device.
 * Uses FLASH_BASE_ADDRESS, TOTAL_ROM_SIZE, SRAM_BASE_ADDRESS, and TOTAL_RAM_SIZE
 * from flash_layout.h which are device-specific.
 *
 * Returns true if the address is in Flash or SRAM, false otherwise.
 * During stack unwinding, valid addresses should be in these regions.
 * Garbage addresses from uninitialized stack will be outside these regions.
 */
static inline bool is_valid_memory_address(uint32_t addr)
{
    if (addr >= FLASH_BASE_ADDRESS &&
        addr < (FLASH_BASE_ADDRESS + TOTAL_ROM_SIZE)) {
        return true;
    }

    if (addr >= SRAM_BASE_ADDRESS &&
        addr < (SRAM_BASE_ADDRESS + TOTAL_RAM_SIZE)) {
        return true;
    }

    return false;
}


void SPU_Handler(void)
{
#ifdef TFM_EXCEPTION_INFO_DUMP
    nrf_exception_info_store_context();
#endif
    /* Clear SPU interrupt flag and pending SPU IRQ */
    spu_clear_events();

    NVIC_ClearPendingIRQ((SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) - NVIC_USER_IRQ_OFFSET);

    tfm_core_panic();
}

__attribute__((naked)) void SPU_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}

#ifdef NRF_SPU00
__attribute__((naked)) void SPU00_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}
#endif

#ifdef NRF_SPU10
__attribute__((naked)) void SPU10_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}
#endif

#ifdef NRF_SPU20
__attribute__((naked)) void SPU20_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}
#endif

#ifdef NRF_SPU30
__attribute__((naked)) void SPU30_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}
#endif

#ifdef NRF_MPC00
__attribute__((naked)) void MPC_Handler(void)
{
    EXCEPTION_INFO();

#ifdef TFM_EXCEPTION_INFO_DUMP
    nrf_exception_info_store_context();
#endif

    /* Clear MPC interrupt flag and pending MPC IRQ */
    mpc_clear_events();

    NVIC_ClearPendingIRQ(MPC00_IRQn);

    tfm_core_panic();

    __ASM volatile(
    "B         .                       \n"
    );
}

void MPC00_IRQHandler(void)
{
    /*
     * When a debugger with secure debug enabled is attached and performs stack
     * unwinding (e.g., backtrace), it may read garbage addresses from the stack.
     * These reads trigger MPC MEMACCERR events, disrupting debugging.
     *
     * We ignore read-only MPC faults only when ALL conditions are met:
     *   1. A debugger is attached (CoreDebug->DHCSR.C_DEBUGEN)
     *   2. Secure invasive debug is enabled (DAUTHSTATUS.SID == 0x3)
     *   3. The access is read-only (not write or execute)
     *   4. The faulting address is outside valid memory ranges (garbage address)
     *
     * If the address is within valid memory, we do NOT ignore the fault as it
     * could indicate a real security issue. When secure debug is disabled, all
     * MPC faults are enforced. Write and execute faults are never ignored.
     */
    if (nrf_mpc_event_check(NRF_MPC00, NRF_MPC_EVENT_MEMACCERR)) {
        uint32_t fault_addr = NRF_MPC00->MEMACCERR.ADDRESS;
        uint32_t fault_info = NRF_MPC00->MEMACCERR.INFO;

        bool is_read = fault_info & MPC_MEMACCERR_INFO_READ_Msk;
        bool is_write = fault_info & MPC_MEMACCERR_INFO_WRITE_Msk;
        bool is_execute = fault_info & MPC_MEMACCERR_INFO_EXECUTE_Msk;

        bool debugger_attached = (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) != 0;

        /* Check if Secure Invasive Debug is enabled (CMSIS DIB->DAUTHSTATUS) */
        bool secure_debug_enabled = (DIB->DAUTHSTATUS & DIB_DAUTHSTATUS_SID_Msk) == DAUTHSTATUS_SID_ENABLED;

        bool is_garbage_address = !is_valid_memory_address(fault_addr);

        if (debugger_attached && secure_debug_enabled &&
            is_read && !is_write && !is_execute && is_garbage_address) {
            mpc_clear_events();
            NVIC_ClearPendingIRQ(MPC00_IRQn);
            return;
        }
    }

    MPC_Handler();
}
#endif

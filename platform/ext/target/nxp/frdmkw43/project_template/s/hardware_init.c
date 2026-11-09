/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*${header:start}*/
#include "pin_mux.h"
#include "board.h"

/*${header:end}*/

/*${function:start}*/


void BOARD_InitHardware(void)
{
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
}

void SystemInitHook (void) 
{
    /* Void implementation of the weak function. */
    extern void *__VECTOR_TABLE[];
    SCB->VTOR = (uint32_t) & (__VECTOR_TABLE[0]);
}

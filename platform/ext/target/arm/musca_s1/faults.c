/*
 * Copyright (c) 2018-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "common_target_cfg.h"
#include "Driver_MPC.h"
#include "utilities.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

/* Import MPC driver */
extern ARM_DRIVER_MPC Driver_CODE_SRAM_MPC;

void C_MPC_Handler(void)
{
    /* Clear MPC interrupt flag and pending MPC IRQ */
    Driver_CODE_SRAM_MPC.ClearInterrupt();
    NVIC_ClearPendingIRQ(S_MPC_COMBINED_IRQn);

    /* Print fault message and block execution */
    ERROR_MSG("Platform Exception: MPC fault!!!");

    tfm_core_panic();
}

__attribute__((naked)) void MPC_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        C_MPC_Handler           \n"
        "B         .                       \n"
    );
}

void C_PPC_Handler(void)
{
    /*
     * Due to an issue on the FVP, the PPC fault doesn't trigger a
     * PPC IRQ which is handled by the PPC_handler.
     * In the FVP execution, this code is not execute.
     */

    /* Clear PPC interrupt flag and pending PPC IRQ */
    ppc_clear_irq();
    NVIC_ClearPendingIRQ(S_PPC_COMBINED_IRQn);

    /* Print fault message*/
    ERROR_MSG("Platform Exception: PPC fault!!!");

    tfm_core_panic();
}

__attribute__((naked)) void PPC_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        C_PPC_Handler           \n"
        "B         .                       \n"
    );
}

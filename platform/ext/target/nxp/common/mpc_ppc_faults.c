/*
 * Copyright (c) 2018-2024, Arm Limited. All rights reserved.
 * Copyright 2019-2020, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "utilities.h"
#include "target_cfg.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

void C_SEC_VIO_IRQHandler(void)
{
#if defined(SEC_VIO_IRQn)
    /* Clear pending IRQ */
    NVIC_ClearPendingIRQ(SEC_VIO_IRQn);
#endif

    /* Print fault message and block execution */
    ERROR_MSG("Platform Exception: MPC/PPC fault!!!");

    tfm_core_panic();
}

__attribute__((naked)) void SEC_VIO_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        C_SEC_VIO_IRQHandler    \n"
        "B         .                       \n"
    );
}

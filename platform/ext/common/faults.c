/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "tfm_hal_device_header.h"
#include "utilities.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

void C_HardFault_Handler(void)
{
    /* A HardFault may indicate corruption of secure state, so it is essential
     * that Non-secure code does not regain control after one is raised.
     * Returning from this exception could allow a pending NS exception to be
     * taken, so the current solution is not to return.
     */
    tfm_core_panic();
}

EXCEPTION_INFO_IAR_REQUIRED
__attribute__((naked)) void HardFault_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "bl        C_HardFault_Handler     \n"
        "b         .                       \n"
    );
}

void C_MemManage_Handler(void)
{
    /* A MemManage fault may indicate corruption of secure state, so it is
     * essential that Non-secure code does not regain control after one is
     * raised. Returning from this exception could allow a pending NS exception
     * to be taken, so the current solution is to panic.
     */
    tfm_core_panic();
}

EXCEPTION_INFO_IAR_REQUIRED
__attribute__((naked)) void MemManage_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "bl        C_MemManage_Handler     \n"
        "b         .                       \n"
    );
}

void C_BusFault_Handler(void)
{
    /* A BusFault may indicate corruption of secure state, so it is essential
     * that Non-secure code does not regain control after one is raised.
     * Returning from this exception could allow a pending NS exception to be
     * taken, so the current solution is to panic.
     */
    tfm_core_panic();
}

EXCEPTION_INFO_IAR_REQUIRED
__attribute__((naked)) void BusFault_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "bl        C_BusFault_Handler      \n"
        "b         .                       \n"
    );
}

void C_SecureFault_Handler(void)
{
    /* A SecureFault may indicate corruption of secure state, so it is essential
     * that Non-secure code does not regain control after one is raised.
     * Returning from this exception could allow a pending NS exception to be
     * taken, so the current solution is to panic.
     */
    tfm_core_panic();
}

EXCEPTION_INFO_IAR_REQUIRED
__attribute__((naked)) void SecureFault_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "bl        C_SecureFault_Handler   \n"
        "b         .                       \n"
    );
}

void C_UsageFault_Handler(void)
{
    tfm_core_panic();
}

EXCEPTION_INFO_IAR_REQUIRED
__attribute__((naked)) void UsageFault_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "bl        C_UsageFault_Handler   \n"
        "b         .                      \n"
    );
}

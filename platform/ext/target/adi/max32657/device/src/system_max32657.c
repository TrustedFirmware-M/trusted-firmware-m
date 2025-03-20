/******************************************************************************
 *
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mxc_sys.h"
#include "mxc_errors.h"
#include "max32657.h"
#include "system_max32657.h"
#include "gcr_regs.h"
#include "mpc.h"
#include "icc.h"


uint32_t SystemCoreClock = IPO_FREQ; // Part defaults to IPO on startup

/*
    The libc implementation from GCC 11+ depends on _getpid and _kill in some places.
    There is no concept of processes/PIDs in the baremetal PeriphDrivers, therefore
    we implement stub functions that return an error code to resolve linker warnings.
*/
__weak int _getpid(void)
{
    return E_NOT_SUPPORTED;
}

__weak int _kill(void)
{
    return E_NOT_SUPPORTED;
}

__weak int PeripheralInit(void)
{
    return E_NO_ERROR;
}

__weak void SystemCoreClockUpdate(void)
{
    uint32_t base_freq, div, clk_src;

    // Get the clock source and frequency
    clk_src = (MXC_GCR->clkctrl & MXC_F_GCR_CLKCTRL_SYSCLK_SEL);
    switch (clk_src) {
    case MXC_S_GCR_CLKCTRL_SYSCLK_SEL_IPO:
        base_freq = IPO_FREQ;
        break;
    case MXC_S_GCR_CLKCTRL_SYSCLK_SEL_ERFO:
        base_freq = ERFO_FREQ;
        break;
    case MXC_S_GCR_CLKCTRL_SYSCLK_SEL_INRO:
        base_freq = INRO_FREQ;
        break;
    case MXC_S_GCR_CLKCTRL_SYSCLK_SEL_IBRO:
        base_freq = IBRO_FREQ;
        break;
    case MXC_S_GCR_CLKCTRL_SYSCLK_SEL_ERTCO:
        base_freq = ERTCO_FREQ;
        break;
    default:
        // Codes 001 and 111 are reserved.
        // This code should never execute, however, initialize to safe value.
        base_freq = HIRC_FREQ;
        break;
    }

    // Get the clock divider
    div = (MXC_GCR->clkctrl & MXC_F_GCR_CLKCTRL_SYSCLK_DIV) >> MXC_F_GCR_CLKCTRL_SYSCLK_DIV_POS;

    SystemCoreClock = base_freq >> div;
}

/**
 * This function is called just before control is transferred to main().
 *
 * You may over-ride this function in your program by defining a custom
 *  SystemInit(), but care should be taken to reproduce the initialization
 *  steps or a non-functional system may result.
 */
void SystemInit(void)
{
#if defined(__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
    extern void *__VECTOR_TABLE[];
    SCB->VTOR = (uint32_t) &(__VECTOR_TABLE[0]);
#endif /* __VTOR_PRESENT check */

#if (__FPU_PRESENT == 1U)
    /* Enable FPU - coprocessor slots 10 & 11 full access */
    SCB->CPACR |= SCB_CPACR_CP10_Msk | SCB_CPACR_CP11_Msk;
#endif /* __FPU_PRESENT check */

    /**
     *  Enable Unaligned Access Trapping to throw an exception when there is an
     *  unaligned memory access while unaligned access support is disabled.
     *
     *  Note: ARMv8-M without the Main Extension disables unaligned access by default.
     */
#if defined(UNALIGNED_SUPPORT_DISABLE) || defined(__ARM_FEATURE_UNALIGNED)
    SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

    __DSB();
    __ISB();

    /* Enable interrupts */
    __enable_irq();

#if CONFIG_TRUSTED_EXECUTION_SECURE
     MXC_ICC_Enable();
#endif

    /* Change system clock source to the main high-speed clock */
    MXC_SYS_Clock_Select(MXC_SYS_CLOCK_IPO);
    MXC_SYS_SetClockDiv(MXC_SYS_CLOCK_DIV_1);
    SystemCoreClockUpdate();

#if CONFIG_TRUSTED_EXECUTION_SECURE
    /* Init peripherals */
    PeripheralInit();
#endif

    /*
     * FPCA bit of CONTROL register can be enabled while
     * performing floating point operation in Secure domain.
     * It will trigger fault if it is not  cleared before
     * switching to Non-secure domain.
     * Hence, clearing FPCA bit during initialization firmware
     */
    __set_CONTROL(__get_CONTROL() & ~0x4);
}

/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdint.h>

#include "tfm_hal_device_header.h"
#include "common_target_cfg.h"
#include "tfm_hal_platform.h"
#include "tfm_plat_defs.h"
#include "uart_stdout.h"

extern const struct memory_region_limits memory_regions;

enum tfm_hal_status_t tfm_hal_platform_init(void)
{
    enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;

    plat_err = enable_fault_handlers();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = system_reset_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = init_debug();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    __enable_irq();
    stdio_init();

    plat_err = nvic_interrupt_target_state_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = nvic_interrupt_enable();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

#if (RTE_USART0)
    #include "cmsis_driver_config.h"
    enum musca_b1_scc_error_t scc_err = SCC_ERR_NONE;

    /* Set pin for UART functionality */
    scc_err = musca_b1_scc_set_alt_func(&MUSCA_B1_SCC_DEV, GPIO_ALTFUNC_1, 1<<AHB_GPIO0_0);
    if (scc_err != SCC_ERR_NONE) {
        return TFM_HAL_ERROR_GENERIC;
    }

    scc_err = musca_b1_scc_set_alt_func(&MUSCA_B1_SCC_DEV, GPIO_ALTFUNC_1, 1<<AHB_GPIO0_1);
    if (scc_err != SCC_ERR_NONE) {
        return TFM_HAL_ERROR_GENERIC;
    }
#endif

    return TFM_HAL_SUCCESS;
}

__NO_RETURN void tfm_hal_system_reset(uint32_t sw_reset_syn_value)
{
    assert(sw_reset_syn_value == TFM_PLAT_SWSYN_DEFAULT);
    __disable_irq();
    mpc_revert_non_secure_to_secure_cfg();

    NVIC->ICPR[0] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[1] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[2] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[3] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[4] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[5] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[6] = UINT32_MAX;         /* Clear all pending interrupts */
    NVIC->ICPR[7] = UINT32_MAX;         /* Clear all pending interrupts */

    NVIC_SystemReset();
}

__NO_RETURN void tfm_hal_system_halt(void)
{
    /*
     * Disable IRQs to stop all threads, not just the thread that
     * halted the system.
     */
    __disable_irq();

    /*
     * Enter sleep to reduce power consumption and do it in a loop in
     * case a signal wakes up the CPU.
     */
    while (1) {
        __WFE();
    }
}

uint32_t tfm_hal_get_ns_VTOR(void)
{
    return memory_regions.non_secure_code_start;
}

uint32_t tfm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)memory_regions.non_secure_code_start);
}

uint32_t tfm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(memory_regions.non_secure_code_start + 4));
}

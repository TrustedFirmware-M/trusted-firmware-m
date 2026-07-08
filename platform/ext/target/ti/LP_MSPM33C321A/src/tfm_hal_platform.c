/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Platform-specific HAL functions for LP_MSPM33C321A.
 *
 * NOTE: memory_regions, tfm_hal_get_ns_VTOR/MSP/entry_point are provided
 * by platform/ext/common/tfm_hal_platform_v8m.c — do NOT redefine here.
 */

#include "tfm_hal_device_header.h"
#include "common_target_cfg.h"
#include "tfm_hal_platform.h"
#include "tfm_plat_defs.h"
#include "tfm_platform_system.h"
#include "uart_stdout.h"
#include "fih.h"

extern void BOARD_InitHardware(void);

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_platform_init(void)
{
    enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;

    BOARD_InitHardware();
    stdio_init();

    plat_err = enable_fault_handlers();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = system_reset_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = init_debug();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    __enable_irq();

    plat_err = nvic_interrupt_target_state_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = nvic_interrupt_enable();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

enum tfm_plat_err_t enable_fault_handlers(void)
{
    /* Set SecureFault priority to the highest (0) */
    NVIC_SetPriority(SecureFault_IRQn, 0);

    /* Enable Bus, Mem, Usage, and Secure faults */
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
                  | SCB_SHCSR_BUSFAULTENA_Msk
                  | SCB_SHCSR_MEMFAULTENA_Msk
                  | SCB_SHCSR_SECUREFAULTENA_Msk;

    return TFM_PLAT_ERR_SUCCESS;
}

#define SCB_AIRCR_WRITE_MASK  ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

enum tfm_plat_err_t system_reset_cfg(void)
{
    uint32_t reg_value = SCB->AIRCR;

    /* SCB_AIRCR_VECTKEY must be set to 0x5FA to write this register */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_debug(void)
{
    /* Debug access is provisioned via SYSCTL; nothing to do at runtime. */
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
    uint32_t i;

    for (i = 0; i < (sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0])); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFFUL;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t nvic_interrupt_enable(void)
{
    /* GSC raises no interrupt on security violations, so there is no
     * violation IRQ line to enable here. */
    return TFM_PLAT_ERR_SUCCESS;
}

/* System initialization function */
void SystemInit(void)
{
}

void tfm_platform_hal_system_reset(void)
{
    NVIC_SystemReset();
}

enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec)
{
    (void)request;
    (void)in_vec;
    (void)out_vec;
    return TFM_PLATFORM_ERR_NOT_SUPPORTED;
}

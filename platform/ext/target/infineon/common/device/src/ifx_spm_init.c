/*
 * Copyright (c) 2023-2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cybsp.h"
#include "cycfg.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"
#include "ifx_spm_init.h"
#include "tfm_peripherals_def.h"
#include "utilities.h"

void ifx_init_spm_peripherals(void)
{
    cy_rslt_t bsp_res = cybsp_init();

    if (bsp_res != CY_RSLT_SUCCESS) {
        tfm_core_panic();
    }

#if IFX_UART_ENABLED
    /*
     * The SCB for UART initialization status is ignored, because configuration
     * is constant and verified for correctness.
     */
    (void)Cy_SCB_UART_Init(IFX_TFM_SPM_UART, &IFX_TFM_SPM_UART_config, NULL);
    Cy_SCB_UART_Enable(IFX_TFM_SPM_UART);
#endif /* IFX_UART_ENABLED */

#if defined(CY_CFG_PWR_PD1_DOMAIN) && (CY_CFG_PWR_PD1_DOMAIN == 1U)
    Cy_SysEnableSOCMEM(true);
#endif /* defined(CY_CFG_PWR_PD1_DOMAIN) && (CY_CFG_PWR_PD1_DOMAIN == 1U) */
}

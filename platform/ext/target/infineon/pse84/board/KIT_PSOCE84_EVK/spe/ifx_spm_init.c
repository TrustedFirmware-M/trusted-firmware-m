/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "region_defs.h"
#include "ifx_spm_init.h"
#include "tfm_peripherals_def.h"
#include "utilities.h"

#include "cybsp.h"
#include "cycfg.h"
#include "cy_device.h"
#include "cy_gpio.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"

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

    /* PD1 is enabled by BSP when CY_CFG_PWR_PD1_DOMAIN is set. Additionally
     * enable SOCMEM so that NSPE can use SOCMEM. This is needed so that TFM
     * can launch CM55 core which may use SOCMEM. */
#if (CY_CFG_PWR_PD1_DOMAIN)
        Cy_SysEnableSOCMEM(true);
#endif /* (CY_CFG_PWR_PD1_DOMAIN) */
}

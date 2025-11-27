/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifdef IFX_MTB_SRF
#include <cybsp.h>
#endif /* IFX_MTB_SRF */

#include "Driver_Common.h"
#include "region_defs.h"
#include "tfm_hal_multi_core.h"
#include "uart_stdout.h"

/* Overrides default implementation of tfm_ns_platform_init */
int32_t tfm_ns_platform_init(void)
{
    /* Call to cybsp_init in NSPE is:
     *    1. Only possible if SRF framework is present (otherwise cybsp_init
     *       fails when trying to access protected resources)
     *    2. Needed when SRF is enable as NSPE SRF init is done in cybsp_init
     */
#ifdef IFX_MTB_SRF
    cy_rslt_t bsp_res = cybsp_init();

    if (bsp_res != CY_RSLT_SUCCESS) {
        return ARM_DRIVER_ERROR;
    }
#endif /* IFX_MTB_SRF */

    stdio_init();

#if defined(IFX_MTB_MAILBOX) && IFX_NS_INTERFACE_TZ
    tfm_hal_boot_ns_cpu(IFX_OFF_CORE_NSPE_BOOT_ADDR);
#endif /* defined(IFX_MTB_MAILBOX) && IFX_NS_INTERFACE_TZ */

    return ARM_DRIVER_OK;
}

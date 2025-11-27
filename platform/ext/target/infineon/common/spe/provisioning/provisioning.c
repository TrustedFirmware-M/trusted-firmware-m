/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "ifx_s_peripherals_def.h"
#include "mxs22.h"
#include "provisioning.h"
#include "cy_device.h"
#include "cy_syslib.h"

#if !defined(CY_IP_MXS22SRSS) && !defined(CY_IP_MXS40SSRSS)
#error Unsupported SRSS IP block
#endif /* !defined(CY_IP_MXS22SRSS) && !defined(CY_IP_MXS40SSRSS) */

uint32_t ifx_get_security_lifecycle(void)
{
    cy_en_syslib_lcs_mode_t lcs = Cy_SysLib_GetDeviceLCS(IFX_LCS_BASE);

    switch (lcs) {
        case CY_SYSLIB_LCS_VIRGIN:
        case CY_SYSLIB_LCS_SORT:
        case CY_SYSLIB_LCS_PROVISIONED:
        case CY_SYSLIB_LCS_NORMAL:
        case CY_SYSLIB_LCS_NORMAL_NO_SECURE:
            return PSA_LIFECYCLE_ASSEMBLY_AND_TEST;
        case CY_SYSLIB_LCS_NORMAL_PROVISIONED:
            return PSA_LIFECYCLE_PSA_ROT_PROVISIONING;
        case CY_SYSLIB_LCS_SECURE: {
            ifx_dap_state_t dap_state = ifx_get_dap_state();

            /* LCS SECURE depends on DAP state as specified by PSA spec */
            switch (dap_state)
            {
                case IFX_DAP_DISABLED:
                        return PSA_LIFECYCLE_SECURED;
                    break;
                case IFX_DAP_ENABLED_NS_ONLY:
                        return PSA_LIFECYCLE_NON_PSA_ROT_DEBUG;
                    break;
                case IFX_DAP_ENABLED_S_NS:
                        return PSA_LIFECYCLE_RECOVERABLE_PSA_ROT_DEBUG;
                    break;
                default:
                        return PSA_LIFECYCLE_RECOVERABLE_PSA_ROT_DEBUG;
                    break;
            }
        }
        case CY_SYSLIB_LCS_RMA:
            return PSA_LIFECYCLE_DECOMMISSIONED;
        default :
            return PSA_LIFECYCLE_UNKNOWN;
    }
}

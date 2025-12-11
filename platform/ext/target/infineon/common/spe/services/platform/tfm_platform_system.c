/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis.h"
#include "cy_pdl.h"
#include "ifx_platform_api.h"
#include "ifx_platform_private.h"
#include "platform_svc_api.h"
#include "tfm_platform_system.h"

void tfm_platform_hal_system_reset(void)
{
    /* Platform partition may be unprivileged, which means that it does not
     * have access to reset control register, thus SVC call is used. */
    ifx_call_platform_system_reset();
}

enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec)
{
    enum tfm_platform_err_t status = TFM_PLATFORM_ERR_NOT_SUPPORTED;
    if ((request >= IFX_PLATFORM_IOCTL_LOG_MSG_MIN) &&
        (request <= IFX_PLATFORM_IOCTL_LOG_MSG_MAX)) {
        /* Core id is encoded in the IOCTL id */
        uint32_t core_id = request - IFX_PLATFORM_IOCTL_LOG_MSG_MIN;
        const char *str = (const char *)in_vec[0].base;
        status = (enum tfm_platform_err_t)ifx_call_platform_uart_log(
                str, in_vec[0].len, core_id);
    }
#if IFX_CUSTOM_PLATFORM_HAL_IOCTL == 1
    else if ((request >= IFX_PLATFORM_IOCTL_APP_MIN) &&
             (request <= IFX_PLATFORM_IOCTL_APP_MIN)) {
        /* Handle application platform-specific IOCTL */
        status = ifx_platform_hal_ioctl(request, in_vec, out_vec);
    }
#endif /* IFX_CUSTOM_PLATFORM_HAL_IOCTL == 1 */
    else {
        status = TFM_PLATFORM_ERR_NOT_SUPPORTED;
    }

    return status;
}

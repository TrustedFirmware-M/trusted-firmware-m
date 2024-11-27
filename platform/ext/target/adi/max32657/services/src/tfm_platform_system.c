/*
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_platform_system.h"
#include "tfm_hal_device_header.h"
#include "tfm_ioctl_core_api.h"

void tfm_platform_hal_system_reset(void)
{
    /* Reset the system */
    NVIC_SystemReset();
}

enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec)
{
    switch (request) {
    case TFM_PLATFORM_ADI_IOCTL_READ_OTP_SERVICE:
        return tfm_platform_adi_hal_otp_service(in_vec, out_vec);
    /* Not a supported IOCTL service.*/
    default:
        return TFM_PLATFORM_ERR_NOT_SUPPORTED;
    }
}

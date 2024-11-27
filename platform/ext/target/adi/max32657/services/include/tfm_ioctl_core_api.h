/******************************************************************************
 *
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************/

#ifndef TFM_IOCTL_CORE_API_H__
#define TFM_IOCTL_CORE_API_H__

#include <tfm_platform_api.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @brief Supported request types.
 */
enum tfm_platform_ioctl_core_reqest_types_t {
    TFM_PLATFORM_ADI_IOCTL_READ_OTP_SERVICE = 0,
};

enum tfm_platform_err_t
tfm_platform_adi_hal_otp_service(const psa_invec *in_vec,
                             const psa_outvec *out_vec);

#ifdef __cplusplus
}
#endif

#endif /* TFM_IOCTL_CORE_API_H__ */

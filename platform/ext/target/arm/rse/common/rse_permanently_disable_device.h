/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PERMANENTLY_DISABLE_DEVICE_H__
#define __RSE_PERMANENTLY_DISABLE_DEVICE_H__

#include <stdint.h>
#include <stddef.h>
#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

enum rse_permanently_disable_device_error_code {
    RSE_PERMANENT_ERROR_OTP_MODIFIED_BEFORE_CM_PROVISIONING = 0x1,
    RSE_PERMANENT_ERROR_LFT_COUNTER_LIMIT_EXCEEDED = 0x2,
    RSE_PERMANENT_ERROR_SECURITY_COUNTER_EXCEEDED = 0x3,
    RSE_PERMANENT_ERROR_ROTPK_REVOCATIONS_EXCEEDED = 0x4,
    RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE = 0x5,
    RSE_PERMANENT_ERROR_BL1_2_INTEGRITY_CHECK_FAILURE = 0x6,
};

enum tfm_plat_err_t rse_permanently_disable_device(
                    enum rse_permanently_disable_device_error_code fatal_error);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PERMANENTLY_DISABLE_DEVICE_H__ */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_permanently_disable_device.h"

#include "tfm_plat_otp.h"

#include <assert.h>

/* FixMe: This function might fail to write the device status. Callers
 *        currently ignore this option and assume the disabling always
 *        worked
 */
enum tfm_plat_err_t rse_permanently_disable_device(
                    enum rse_permanently_disable_device_error_code fatal_error)
{
    uint32_t device_status;
    enum tfm_plat_err_t err;

    assert(fatal_error != 0);

    err = tfm_plat_otp_read(PLAT_OTP_ID_DEVICE_STATUS, sizeof(device_status),
                            (uint8_t *)&device_status);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    device_status |= (fatal_error & 0x7FFF) << 17;

    return tfm_plat_otp_write(PLAT_OTP_ID_DEVICE_STATUS, sizeof(device_status),
                              (uint8_t *)&device_status);
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_permanently_disable_device.h"

#include "tfm_plat_otp.h"

#include <assert.h>

/* If the function fails to permanently disable the device it will just spin and
 * avoid returning so that callers do not have to handle the exceptional behaviour
 */
enum tfm_plat_err_t rse_permanently_disable_device(
                    enum rse_permanently_disable_device_error_code fatal_error)
{
    uint32_t device_status, read_back_status;
    enum tfm_plat_err_t err;

    assert(fatal_error != 0);

    do {
        err = tfm_plat_otp_read(PLAT_OTP_ID_DEVICE_STATUS, sizeof(device_status),
                            (uint8_t *)&device_status);
    } while (err != TFM_PLAT_ERR_SUCCESS);

    /* device_status[31:17] contains the error */
    device_status |= (fatal_error & 0x7FFF) << 17;

    do {
        err = tfm_plat_otp_write(PLAT_OTP_ID_DEVICE_STATUS, sizeof(device_status), (uint8_t *)&device_status);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            continue;
        }
        err = tfm_plat_otp_read(PLAT_OTP_ID_DEVICE_STATUS, sizeof(read_back_status), (uint8_t *)&read_back_status);
    } while ((err != TFM_PLAT_ERR_SUCCESS) || (read_back_status != device_status));

    return err;
}

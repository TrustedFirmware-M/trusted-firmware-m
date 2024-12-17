/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */


#include "dcsu_hal.h"

#include "device_definition.h"
#include "rse_soc_uid.h"
#include "rse_otp_dev.h"

static enum dcsu_rx_msg_error_t rse_dcsu_hal_error_mapping(uint32_t err)
{
    switch (err) {
    case TFM_PLAT_ERR_SOC_UID_NOT_GENERATED:
        return DCSU_RX_MSG_ERROR_SOC_UID_NOT_GENERATED;
    case LCM_ERROR_OTP_WRITE_INVALID_WRITE:
        return DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN;
    case LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL:
        return DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED;
    case LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT:
        return DCSU_RX_MSG_ERROR_OFFSET_INVALID;
    default:
        return DCSU_RX_MSG_ERROR_GENERIC_ERROR;
    }
}

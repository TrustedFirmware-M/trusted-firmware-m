/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */


#include "dcsu_hal.h"

#include "device_definition.h"
#include "rse_soc_uid.h"
#include "rse_otp_dev.h"

static enum dcsu_rx_msg_response_t rse_dcsu_hal_resp_mapping(uint32_t err)
{
    switch (err) {
    case TFM_PLAT_ERR_SUCCESS:
        return DCSU_RX_MSG_RESP_SUCCESS;
    case TFM_PLAT_ERR_SOC_UID_NOT_GENERATED:
        return DCSU_RX_MSG_RESP_GENERATE_SOC_UNIQUE_ID_NI;
    case LCM_ERROR_OTP_WRITE_INVALID_WRITE:
        return DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN;
    case LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL:
        return DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
    case LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT:
        return DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
    default:
        return DCSU_ERROR_RX_MSG_GENERIC_ERROR;
    }
}

uint32_t dcsu_hal_checksum_data(uint32_t *data, uint32_t word_count)
{
    uint32_t sum = 0;
    uint32_t idx;

    uint32_t word;
    uint8_t *bytes = (uint8_t *)&word;

    for (idx = 0; idx < word_count; idx++) {
        word = data[idx];
        sum += bytes[0] + bytes[1] + bytes[2] + bytes[3];
    }

    sum = sum % ((1 << 14) - 1);

    return sum;
}

enum dcsu_error_t dcsu_hal_complete_import_data(enum dcsu_rx_msg_response_t *response)
{
    /* Use no response to delay response to after import verification */
    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_hal_cancel_import_data(enum dcsu_rx_msg_response_t *response)
{
    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return 0;
}

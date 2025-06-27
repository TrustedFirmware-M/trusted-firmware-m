/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */


#include "dcsu_hal.h"

#include "device_definition.h"
#include "rse_soc_uid.h"
#include "rse_otp_dev.h"
#include "rse_zero_count.h"
#include "rse_persistent_data.h"

static inline bool is_otp_clean(uint32_t start_offset, uint32_t size)
{
    for (uint32_t idx = 0; idx < size / sizeof(uint32_t); idx += 1) {
        if (0 != ((uint32_t *)(OTP_BASE_S + start_offset))[idx]) {
            return false;
        }
    }
    return true;
}

static inline enum dcsu_rx_msg_response_t rse_dcsu_hal_resp_mapping(uint32_t err)
{
    switch (err) {
    case TFM_PLAT_ERR_SUCCESS:
        return DCSU_RX_MSG_RESP_SUCCESS;
    case TFM_PLAT_ERR_SOC_UID_NOT_GENERATED:
        return DCSU_RX_MSG_RESP_GENERATE_SOC_UNIQUE_ID_NI;
    case TFM_PLAT_ERR_SOC_UID_ALREADY_GENERATED:
    case LCM_ERROR_OTP_WRITE_INVALID_WRITE:
        return DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN;
    case LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL:
        return DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
    case LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT:
        return DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
    default:
        return DCSU_RX_MSG_RESP_GENERIC_ERROR;
    }
}

enum dcsu_error_t dcsu_hal_get_field_offset(enum dcsu_otp_field_t field, uint32_t *offset)
{
    if (offset == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    switch (field) {
#ifdef RSE_OTP_HAS_SOC_AREA
    case DCSU_OTP_FIELD_SOC_ID_BASE:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area);
        break;
    case DCSU_OTP_FIELD_FAMILY_ID:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.family_id);
        break;
    case DCSU_OTP_FIELD_IEEE_ECID:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.ieee_ecid);
        break;
    case DCSU_OTP_FIELD_SOC_ID_ZC:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.zero_count_id);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_BASE:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_cfg_area);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_DATA_ZC:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_DATA:
        *offset = OTP_OFFSET(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_size);
        break;
#endif /* RSE_OTP_HAS_SOC_AREA */
    case DCSU_OTP_FIELD_CM_COD:
        *offset = OTP_OFFSET(P_RSE_OTP_CM->cod);
        break;
#ifdef RSE_OTP_HAS_ENDORSEMENT_CERTIFICATE
    case DCSU_OTP_FIELD_EC_PARAMS:
        *offset = OTP_OFFSET(P_RSE_OTP_DYNAMIC->iak_endorsement_certificate_signature);
        break;
#endif /* RSE_OTP_HAS_ENDORSEMENT_CERTIFICATE */
    default:
        *offset = 0;
        return DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD;
    }
    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_hal_get_field_size(enum dcsu_otp_field_t field, uint32_t *size)
{
    if (size == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    switch (field) {
#ifdef RSE_OTP_HAS_SOC_AREA
    case DCSU_OTP_FIELD_SOC_ID_BASE:
        *size = sizeof(P_RSE_OTP_SOC->soc_id_area);
        break;
    case DCSU_OTP_FIELD_FAMILY_ID:
        *size = sizeof(P_RSE_OTP_SOC->soc_id_area.family_id);
        break;
    case DCSU_OTP_FIELD_IEEE_ECID:
        *size = sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid);
        break;
    case DCSU_OTP_FIELD_SOC_ID_ZC:
        *size = sizeof(P_RSE_OTP_SOC->soc_id_area.zero_count_id);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_BASE:
        *size = sizeof(P_RSE_OTP_SOC->soc_cfg_area);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_DATA_ZC:
        *size = sizeof(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc);
        break;
    case DCSU_OTP_FIELD_SOC_CFG_DATA:
        *size = sizeof(P_RSE_OTP_SOC->soc_cfg_area) -
                sizeof(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc);
        break;
#endif /* RSE_OTP_HAS_SOC_AREA */
    case DCSU_OTP_FIELD_CM_COD:
        *size = sizeof(P_RSE_OTP_CM->cod);
        break;
#ifdef RSE_OTP_HAS_ENDORSEMENT_CERTIFICATE
    case DCSU_OTP_FIELD_EC_PARAMS:
        *size = sizeof(P_RSE_OTP_DYNAMIC->iak_endorsement_certificate_signature) +
                sizeof(P_RSE_OTP_DYNAMIC->iak_endorsement_certificate_parameters);
        break;
#endif /* RSE_OTP_HAS_ENDORSEMENT_CERTIFICATE */
    default:
        *size = 0;
        return DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD;
    }
    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_hal_generate_soc_unique_id(enum dcsu_rx_msg_response_t *response)
{
    if (response == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

#ifdef RSE_OTP_HAS_SOC_AREA
    enum tfm_plat_err_t err = rse_generate_soc_uid();
    *response = rse_dcsu_hal_resp_mapping(err);
    return DCSU_ERROR_NONE;
#else
    *response = DCSU_RX_MSG_RESP_INVALID_COMMAND;
    return DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD;
#endif /* RSE_OTP_HAS_SOC_AREA */
}

enum dcsu_error_t dcsu_hal_write_otp(enum dcsu_otp_field_t otp_field,
                                     uint32_t otp_field_write_offset, uint32_t *data,
                                     size_t data_size, enum dcsu_rx_msg_response_t *response)
{
    if ((data == NULL) || (response == NULL)) {
        return DCSU_ERROR_INVALID_POINTER;
    }

#ifdef RSE_OTP_HAS_SOC_AREA
    enum lcm_error_t lcm_err;
    enum dcsu_error_t msg_err;
    uint32_t field_offset;
    uint32_t field_max_size;

    /* DCSU can't write to OTP until SoC Unique ID generated */
    if (!rse_soc_uid_is_generated()) {
        *response = DCSU_RX_MSG_RESP_GENERATE_SOC_UNIQUE_ID_NI;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(otp_field, &field_max_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    if (otp_field_write_offset - field_offset >= field_max_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
        return DCSU_ERROR_NONE;
    }
    if (otp_field_write_offset - field_offset > field_max_size - data_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST;
        return DCSU_ERROR_NONE;
    }

    if (!is_otp_clean(otp_field_write_offset, data_size)) {
        *response = DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN;
        return DCSU_ERROR_NONE;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, otp_field_write_offset, data_size, (uint8_t *)data);
    if (lcm_err != LCM_ERROR_NONE) {
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_RX_MSG_OTP_WRITE_FAILED;
    }

    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
#else
    *response = DCSU_RX_MSG_RESP_INVALID_COMMAND;
    return DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD;
#endif /* RSE_OTP_HAS_SOC_AREA */
}

enum dcsu_error_t dcsu_hal_read_otp(enum dcsu_otp_field_t otp_field, uint32_t otp_field_read_offset,
                                    uint32_t *data, size_t data_size,
                                    enum dcsu_rx_msg_response_t *response)
{
    enum lcm_error_t lcm_err;
    enum dcsu_error_t msg_err;
    uint32_t field_offset;
    uint32_t field_max_size;

    if ((data == NULL) || (response == NULL)) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(otp_field, &field_max_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    if (otp_field_read_offset - field_offset >= field_max_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
        return DCSU_ERROR_NONE;
    }
    if (otp_field_read_offset - field_offset > field_max_size - data_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST;
        return DCSU_ERROR_NONE;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, otp_field_read_offset, data_size, (uint8_t *)data);
    if (lcm_err != LCM_ERROR_NONE) {
        /* Most responses don't make sense this is closest interpret as OTP access failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_RX_MSG_OTP_WRITE_FAILED;
    }

    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_hal_write_zero_count(enum dcsu_otp_field_t otp_field,
                                            uint32_t otp_field_zero_count_field_offset,
                                            uint32_t otp_field_zero_count_start_offset,
                                            size_t data_size, enum dcsu_rx_msg_response_t *response)
{
    if (response == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

#ifdef RSE_OTP_HAS_SOC_AREA
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t plat_err;
    enum dcsu_error_t msg_err;
    uint32_t zero_count;
    uint32_t zc_field_size = sizeof(zero_count);
    uint32_t field_offset;
    uint32_t field_max_size;

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(otp_field, &field_max_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    if (otp_field_zero_count_start_offset - field_offset >= field_max_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
        return DCSU_ERROR_NONE;
    }
    if (otp_field_zero_count_start_offset - field_offset > field_max_size - data_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST;
        return DCSU_ERROR_NONE;
    }
    if (otp_field_zero_count_field_offset - field_offset >= field_max_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
        return DCSU_ERROR_NONE;
    }
    if (otp_field_zero_count_field_offset - field_offset > field_max_size - zc_field_size) {
        *response = DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST;
        return DCSU_ERROR_NONE;
    }

    if (is_otp_clean(otp_field_zero_count_start_offset, data_size)) {
        *response = DCSU_RX_MSG_RESP_RANGE_NOT_INITIALIZED;
        return DCSU_ERROR_NONE;
    }

    if (!is_otp_clean(otp_field_zero_count_field_offset, zc_field_size)) {
        *response = DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN;
        return DCSU_ERROR_NONE;
    }

    plat_err = rse_count_zero_bits((uint8_t *)(OTP_BASE_S + otp_field_zero_count_start_offset),
                                   data_size, &zero_count);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        /* Closest response that isn't already used */
        *response = DCSU_RX_MSG_RESP_VERIFY_BLOB_FAILED;
        return DCSU_ERROR_NONE;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, otp_field_zero_count_field_offset, zc_field_size,
                            (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        /* Closest response that isn't already used */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_RX_MSG_OTP_WRITE_FAILED;
    }

    plat_err = rse_check_zero_bit_count(
        (uint8_t *)(OTP_BASE_S + otp_field_zero_count_start_offset), data_size,
        *((uint32_t *)(OTP_BASE_S + otp_field_zero_count_field_offset)));
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        /* Closest response that isn't already used */
        *response = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_RX_MSG_OTP_WRITE_FAILED;
    }

    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
#else
    *response = DCSU_RX_MSG_RESP_INVALID_COMMAND;
    return DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD;
#endif /* RSE_OTP_HAS_SOC_AREA */
}

uint32_t dcsu_hal_checksum_data(uint32_t *data, uint32_t word_count)
{
    uint32_t sum = 0;
    uint32_t idx;

    uint32_t word;
    uint8_t *bytes = (uint8_t *)&word;

    if (data == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    for (idx = 0; idx < word_count; idx++) {
        word = data[idx];
        sum += bytes[0] + bytes[1] + bytes[2] + bytes[3];
    }

    sum = sum % ((1 << 14) - 1);

    return sum;
}

enum dcsu_error_t dcsu_hal_complete_import_data(enum dcsu_rx_msg_response_t *response)
{
    if (response == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    /* Use no response to delay response to after import verification */
    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_hal_cancel_import_data(enum dcsu_rx_msg_response_t *response)
{
    if (response == NULL) {
        return DCSU_ERROR_INVALID_POINTER;
    }

    *response = DCSU_RX_MSG_RESP_SUCCESS;
    return 0;
}

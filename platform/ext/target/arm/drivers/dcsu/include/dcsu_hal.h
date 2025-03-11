/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __DCSU_HAL_H__
#define __DCSU_HAL_H__

#include "dcsu_drv.h"

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief OTP field enumeration types
 * These are used when writing to/reading from OTP areas
 */
enum dcsu_otp_field_t {
    DCSU_OTP_FIELD_SOC_ID_BASE,
    DCSU_OTP_FIELD_FAMILY_ID,
    DCSU_OTP_FIELD_IEEE_ECID,
    DCSU_OTP_FIELD_SOC_ID_ZC,
    DCSU_OTP_FIELD_SOC_CFG_BASE,
    DCSU_OTP_FIELD_SOC_CFG_DATA_ZC,
    DCSU_OTP_FIELD_SOC_CFG_DATA,
    DCSU_OTP_FIELD_CM_COD,
    DCSU_OTP_FIELD_EC_PARAMS,
};

/**
 * \brief This function calculates the checksum of data
 *
 * \param data                  Data to write
 * \param word_count            Number of 32 bit words in the data
 *
 * \retval calculated checksum
 */
uint32_t dcsu_hal_checksum_data(uint32_t *data, uint32_t word_count);

/**
 * \brief This function flags that an import should be completed
 *
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 */
enum dcsu_error_t dcsu_hal_complete_import_data(enum dcsu_rx_msg_response_t *response);

/**
 * \brief This function cancels an import without performing it
 *
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 */
enum dcsu_error_t dcsu_hal_cancel_import_data(enum dcsu_rx_msg_response_t *response);

/**
 * \brief This function gets the offset of the specified OTP field.
 *
 * \param field         the OTP field to get the offset of
 * \param[out] offset   the offset of the field relative to start of OTP
 *
 * \retval DCSU_ERROR_NONE                          The operation has succeeded.
 * \retval DCSU_TX_MSG_ERROR_GENERIC_FAILURE        Unrecoverable command failure.
 */
enum dcsu_error_t dcsu_hal_get_field_offset(enum dcsu_otp_field_t field, uint32_t *offset);

/**
 * \brief This function gets the size of the specified OTP field.
 *
 * \param field         the OTP field to get the offset of
 * \param[out] size     the size of the field
 *
 * \retval DCSU_ERROR_NONE                          The operation has succeeded.
 * \retval DCSU_TX_MSG_ERROR_GENERIC_FAILURE        Unrecoverable command failure.
 */
enum dcsu_error_t dcsu_hal_get_field_size(enum dcsu_otp_field_t field, uint32_t *size);

/**
 * \brief This function generates and stores the SoC unique ID in OTP
 *
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *                          DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN    OTP was already written
 *                          DCSU_RX_MSG_RESP_OTP_WRITE_FAILED       OTP write failed
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 * \retval DCSU_TX_MSG_ERROR_GENERIC_FAILURE        Unrecoverable command failure.
 */
enum dcsu_error_t dcsu_hal_generate_soc_unique_id(enum dcsu_rx_msg_response_t *response);

/**
 * \brief This function writes a value to an OTP field at a specified offset
 *
 * \param otp_area              OTP area to write to
 * \param otp_area_write_offset Offset from OTP area to write to
 * \param data                  Data to write
 * \param data_size             Size of data to write
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *                          DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN    OTP was already written
 *                          DCSU_RX_MSG_RESP_OTP_WRITE_FAILED       OTP write failed
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM offset was outside field
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST size put write end outside field
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 */
enum dcsu_error_t dcsu_hal_write_otp(enum dcsu_otp_field_t otp_area, uint32_t otp_area_write_offset,
                                     uint32_t *data, size_t data_size,
                                     enum dcsu_rx_msg_response_t *response);

/**
 * \brief This function reads the value of an OTP field at a specified offset
 *
 * \param otp_field             OTP area to read from
 * \param otp_field_read_offset Offset from OTP area to read from
 * \param[out] data             Data read from OTP
 * \param data_size             Size of data to write
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *                          DCSU_RX_MSG_RESP_OTP_WRITE_FAILED       OTP read failed
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM offset was outside field
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST size put read end outside field
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 */
enum dcsu_error_t dcsu_hal_read_otp(enum dcsu_otp_field_t otp_field, uint32_t otp_field_read_offset,
                                    uint32_t *data, size_t data_size,
                                    enum dcsu_rx_msg_response_t *response);

/**
 * \brief This function writes the zero of a specified section of an OTP field
 * to a specified offset
 *
 * \param otp_area              OTP area to read/write
 * \param otp_area_zero_count_field_offset Offset from OTP area to write zero count
 * \param otp_area_zero_count_start_offset Start offset of data to zero count
 * \param data_size             Size of data to zero count
 * \param[out] response     The response to send via the DCSU command status
 *                          DCSU_RX_MSG_RESP_NO_RESP                No response yet (must be sent later)
 *                          DCSU_RX_MSG_RESP_SUCCESS                Operation succeeded
 *                          DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN    Zero count area already written
 *                          DCSU_RX_MSG_RESP_OTP_WRITE_FAILED       OTP access failed
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM offset was outside field
 *                          DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST size put read end outside field
 *                          DCSU_RX_MSG_RESP_RANGE_NOT_INITIALIZED  area to zero count all zero
 *                          DCSU_RX_MSG_RESP_VERIFY_BLOB_FAILED     zero count failed
 *
 * \retval DCSU_ERROR_NONE                The operation has succeeded.
 */
enum dcsu_error_t dcsu_hal_write_zero_count(enum dcsu_otp_field_t otp_area,
                                            uint32_t otp_area_zero_count_field_offset,
                                            uint32_t otp_area_zero_count_start_offset,
                                            size_t data_size,
                                            enum dcsu_rx_msg_response_t *response);

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_HAL_H__ */

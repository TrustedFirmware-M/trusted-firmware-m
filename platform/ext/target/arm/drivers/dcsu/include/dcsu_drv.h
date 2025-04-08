/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __DCSU_DRV_H__
#define __DCSU_DRV_H__

#include <stdint.h>
#include <stddef.h>

#if TFM_UNIQUE_ERROR_CODES == 1
#include "error_codes_mapping.h"
#else
#define DCSU_ERROR_BASE 0x1u
#endif /* TFM_UNIQUE_ERROR_CODES */

#ifdef __cplusplus
extern "C" {
#endif

enum dcsu_rx_command {
    DCSU_RX_COMMAND_NOP=0x0,
    DCSU_RX_COMMAND_IMPORT_DATA_NO_CHECKSUM = 0xA,
    DCSU_RX_COMMAND_IMPORT_DATA_CHECKSUM = 0xB,
    DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA = 0xC,
    DCSU_RX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM = 0xD,
    _DCSU_RX_COMMAND_PAD = UINT32_MAX,
};

enum dcsu_tx_command {
    DCSU_TX_COMMAND_NOP,
    DCSU_TX_COMMAND_READY_FOR_IMPORT = 0x1,
    DCSU_TX_COMMAND_REPORT_STATUS = 0x2,
    DCSU_TX_COMMAND_EXPORT_DATA_WITH_CHECKSUM = 0x3,
    DCSU_TX_COMMAND_EXPORT_DATA_NO_CHECKSUM = 0x4,
    DCSU_TX_COMMAND_COMPLETE_EXPORT_DATA = 0x5,

    _DCSU_TX_COMMAND_PAD = UINT32_MAX,
};

/**
 * \brief Arm DCSU received message response codes
 * These will be sent as a response to an RX DCSU command
 */
enum dcsu_rx_msg_response_t {
    DCSU_RX_MSG_RESP_NO_RESP = 0x0,
    DCSU_RX_MSG_RESP_SUCCESS = 0x1,
    DCSU_RX_MSG_RESP_OTP_ALREADY_WRITTEN = 0x2,
    DCSU_RX_MSG_RESP_OTP_WRITE_FAILED = 0x3,
    DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM = 0x4,
    DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST = 0x5,
    DCSU_RX_MSG_RESP_BAD_INTEGRITY_VALUE = 0x6,
    DCSU_RX_MSG_RESP_SOC_FAM_ID_NOT_INIT = 0x7,
    DCSU_RX_MSG_RESP_SOC_IEEE_ECID_NOT_INIT = 0x8,
    DCSU_RX_MSG_RESP_GENERATE_SOC_UNIQUE_ID_NI = 0x9,
    DCSU_RX_MSG_RESP_VERIFY_BLOB_FAILED = 0xA,
    DCSU_RX_MSG_RESP_UNEXPECTED_NUMBER_OF_WORDS = 0xB,
    DCSU_RX_MSG_RESP_UNEXPECTED_IMPORT = 0xC,
    DCSU_RX_MSG_RESP_RANGE_NOT_INITIALIZED = 0xD,

    DCSU_RX_MSG_RESP_INVALID_COMMAND = 0xFF,

    _DCSU_RX_MSG_RESP_MAX = 0x100,
    _DCSU_RX_MSG_RESP_PAD = UINT32_MAX,
};

/**
 * \brief Arm DCSU transmitted message response codes
 */
enum dcsu_tx_msg_response_t {
    DCSU_TX_MSG_RESP_NO_RESP = 0x0,
    DCSU_TX_MSG_RESP_SUCCESS = 0x1,
    DCSU_TX_MSG_RESP_TOO_LARGE_OFFSET_PARAM = 0x4,
    DCSU_TX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST = 0x5,
    DCSU_TX_MSG_RESP_BAD_INTEGRITY_VALUE = 0x6,
    DCSU_TX_MSG_RESP_UNEXPECTED_IN_CURRENT_CONTEXT = 0x7,
    _DCSU_TX_MSG_RESP_MAX = 0x100,
    _DCSU_TX_MSG_RESP_PAD = UINT32_MAX,
};

/**
 * \brief Arm DCSU error enumeration types
 */
enum dcsu_error_t {
    DCSU_ERROR_NONE = 0x0u,
    DCSU_ERROR_WAIT_UNEXPECTED_COMMAND = DCSU_ERROR_BASE,

    DCSU_ERROR_POLL_NO_COMMAND_PENDING,
    DCSU_ERROR_POLL_UNEXPECTED_COMMAND,

    DCSU_ERROR_SW_STATUS_INVALID_IDX,

    DCSU_ERROR_RX_MSG_GENERIC_ERROR,
    DCSU_ERROR_RX_MSG_INVALID_OTP_FIELD,
    DCSU_ERROR_RX_MSG_OTP_WRITE_FAILED,

    DCSU_ERROR_TX_MSG_GENERIC_FAILURE,
    DCSU_ERROR_TX_MSG_PAYLOAD_TOO_LARGE,
    DCSU_ERROR_TX_MSG_RESP_BASE,
    DCSU_ERROR_TX_MSG_RESP_MAX = DCSU_ERROR_TX_MSG_RESP_BASE + _DCSU_TX_MSG_RESP_MAX,

    _DCSU_ERROR_PAD = UINT32_MAX,
};

/**
 * \brief COMMIT_WRITE command handler
 */
typedef enum dcsu_error_t (*dcsu_commit_write_handler_t)(uint8_t *rx_buf, size_t rx_buf_len);

/**
 * \brief Arm DCSU device configuration structure
 */
struct dcsu_dev_cfg_t {
    const uintptr_t base; /*!< DCSU base address */
};

/**
 * \brief Arm DCSU device structure
 */
struct dcsu_dev_t {
    const struct dcsu_dev_cfg_t *const cfg; /* DCSU configuration */

    uint8_t *rx_buf;
    size_t rx_buf_len;
    size_t rx_buf_offset;
    dcsu_commit_write_handler_t handler;
    uint8_t import_checksum_failed;
};

/**
 * \brief This function initializes the DCSU
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[out] rx_buf     A buffer in which to store received DCSU data when
 *                        operating in asynchronous handler mode.
 * \param[in]  rx_buf_len The size of the asynchronous received data buffer.
 * \param[in]  handler    A handler function which is called when
 *                        DCSU_RX_COMMAND_COMMIT_WRITE is received in
 *                        asynchronous handler mode.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_init(struct dcsu_dev_t *dev, uint8_t *rx_buf, size_t rx_buf_len,
                            dcsu_commit_write_handler_t handler);

/**
 * \brief This function does not return until a DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 */
void dcsu_wait_for_any_rx_command(struct dcsu_dev_t *dev);

/**
 * \brief This function does not return until a specific DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  command    The command to check for.
 *
 * \return  DCSU_ERROR_NONE if the command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_wait_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command);

/**
 * \brief This function checks if a DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if a command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_poll_for_any_rx_command(struct dcsu_dev_t *dev);

/**
 * \brief This function checks if a specific DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  command    The command to check for.
 *
 * \return  DCSU_ERROR_NONE if the command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_poll_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command);

/**
 * \brief This function checks if a response has been received from a
 *        previous TX message
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_poll_for_tx_response(struct dcsu_dev_t *dev);

/**
 * \brief This function handles any pending DCSU commands. This is intended to
 *        be called by an interrupt handler.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_handle_rx_command(struct dcsu_dev_t *dev);

/**
 * \brief This function handles any pending DCSU reponse from a previous TX message.
          This is intended to be called by an interrupt handler.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_handle_tx_response(struct dcsu_dev_t *dev);

/**
 * \brief This function sends a response to a specific pending DCSU command.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  command    The command to respond to. If this command is not
 *                        pending an error will be returned.
 * \param[in]  response   The response code to be sent to the host via the DCSU.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_respond_to_rx_command(struct dcsu_dev_t *dev,
                                             enum dcsu_rx_command command,
                                             enum dcsu_rx_msg_response_t response);

/**
 * \brief This function sends the Import Ready command to signal to external
 * tooling that RSE is ready to receive commands.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_import_ready(struct dcsu_dev_t *dev);

/**
 * \brief This function sends the Import Ready command to signal to external
 * tooling that RSE is ready to receive commands. It does not block to
 * wait for acknowledgement
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_import_ready_non_blocking(struct dcsu_dev_t *dev);

/**
 * \brief This function sends the report status command with a status update.
 * Used by message handling to report what has been done so far.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  status     The status data to report
 * \param[in]  size       size of status
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_report_status(struct dcsu_dev_t *dev, uint32_t *status, uint32_t size);

/**
 * \brief This function sends data via the DCSU synchronously.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in] data       The data buffer to be sent.
 * \param[in]  data_size  The amount of data to be sent.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_send_data(struct dcsu_dev_t *dev, const uint8_t *data, size_t data_size);

/**
 * \brief This function sets the software-defined status registers.
 *
 * \param[in]  dev            The DCSU device structure.
 * \param[in]  status         The value to write to the status register.
 * \param[in]  status_reg_idx The index of the status register to write.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_write_sw_status(struct dcsu_dev_t *dev, uint32_t status,
                                       uint32_t status_reg_idx);

/**
 * \brief This function uninitializes the DCSU
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_ERROR_NONE if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_finish(struct dcsu_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_DRV_H__ */

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
    DCSU_RX_COMMAND_NOP,
    DCSU_RX_COMMAND_GENERATE_SOC_UNIQUE_ID,
    DCSU_RX_COMMAND_WRITE_SOC_AREA,
    DCSU_RX_COMMAND_COMPUTE_INTEGRITY_CHECK_SOC_AREA,
    DCSU_RX_COMMAND_WRITE_DATA,
    DCSU_RX_COMMAND_COMMIT_WRITE,

    _DCSU_RX_COMMAND_PAD = UINT32_MAX,
};

enum dcsu_tx_command {
    DCSU_TX_COMMAND_NOP,
    DCSU_TX_COMMAND_EXPORT_DATA,

    _DCSU_TX_COMMAND_PAD = UINT32_MAX,
};

/**
 * \brief Arm DCSU received message error codes
 */
enum dcsu_rx_msg_error_t {
    DCSU_RX_MSG_ERROR_SUCCESS = 0x1,
    DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN = 0x2,
    DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED = 0x3,
    DCSU_RX_MSG_ERROR_SOC_UID_NOT_GENERATED = 0x4,
    DCSU_RX_MSG_ERROR_INVALID_NUM_WORDS = 0x5,
    DCSU_RX_MSG_ERROR_OFFSET_TOO_LARGE = 0x6,
    DCSU_RX_MSG_ERROR_OFFSET_INVALID = 0x7,
    DCSU_RX_MSG_ERROR_SIZE_TOO_LARGE = 0x8,

    DCSU_RX_MSG_ERROR_BUFFER_NOT_SET_UP = 0xF0,
    DCSU_RX_MSG_ERROR_COMMIT_HANDLER_NOT_SET_UP = 0xF1,
    DCSU_RX_MSG_ERROR_UNEXPECTED_COMMAND = 0xF2,
    DCSU_RX_MSG_ERROR_INVALID_COMMAND = 0xFF,

    _DCSU_RX_MSG_ERROR_MAX = 0x100,
    _DCSU_RX_MSG_ERROR_PAD = UINT32_MAX,
};

/**
 * \brief Arm DCSU transmitted message error codes
 */
enum dcsu_tx_msg_error_t {
    DCSU_TX_MSG_ERROR_SUCCESS = 0x1,
    DCSU_TX_MSG_ERROR_GENERIC_FAILURE = 0x2,

    _DCSU_TX_MSG_ERROR_MAX = 0x100,
    _DCSU_TX_MSG_ERROR_PAD = UINT32_MAX,
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

    DCSU_ERROR_RX_MSG_BASE,
    DCSU_ERROR_RX_MSG_MAX = DCSU_ERROR_RX_MSG_BASE + _DCSU_RX_MSG_ERROR_MAX,

    DCSU_ERROR_TX_MSG_BASE,
    DCSU_ERROR_TX_MSG_MAX = DCSU_ERROR_TX_MSG_BASE + _DCSU_TX_MSG_ERROR_MAX,

    _DCSU_ERROR_PAD = UINT32_MAX,
};

/**
 * \brief COMMIT_WRITE command handler
 */
typedef enum dcsu_rx_msg_error_t (*dcsu_commit_write_handler_t)(uint8_t *rx_buf, size_t rx_buf_len);

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
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
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
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_wait_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command);

/**
 * \brief This function checks if a DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if a command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_poll_for_any_rx_command(struct dcsu_dev_t *dev);

/**
 * \brief This function checks if a specific DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  command    The command to check for.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the command is pending, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_poll_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command);

/**
 * \brief This function handles any pending DCSU commands. This is intended to
 *        be called by an interrupt handler.
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_handle_rx_command(struct dcsu_dev_t *dev);

/**
 * \brief This function sends a response to a specific pending DCSU command.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in]  command    The command to respond to. If this command is not
 *                        pending an error will be returned.
 * \param[in]  response   The response code to be sent to the host via the DCSU.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_respond_to_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command,
                                             enum dcsu_rx_msg_error_t response);

/**
 * \brief This function receives data from the DCSU synchronously. It will not
 *        return until a DCSU command has been received.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[out] data       The data buffer to receive data into.
 * \param[in]  data_len   The size of the data buffer.
 * \param[out] data_size  The amount of data received.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_receive_data(struct dcsu_dev_t *dev, uint8_t *data, size_t data_len,
                                    size_t *data_size);

/**
 * \brief This function sends data via the DCSU synchronously.
 *
 * \param[in]  dev        The DCSU device structure.
 * \param[in] data       The data buffer to be sent.
 * \param[in]  data_size  The amount of data to be sent.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
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
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_write_sw_status(struct dcsu_dev_t *dev, uint32_t status,
                                       uint32_t status_reg_idx);

/**
 * \brief This function uninitializes the DCSU
 *
 * \param[in]  dev        The DCSU device structure.
 *
 * \return  DCSU_RX_MSG_ERROR_SUCCESS if the operation has succeeded, else an
 *          error code as specified in \ref dcsu_error_t.
 */
enum dcsu_error_t dcsu_finish(struct dcsu_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_DRV_H__ */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MHU_H__
#define __MHU_H__

#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#if TFM_UNIQUE_ERROR_CODES == 1
#include "error_codes_mapping.h"
#else
#define MHU_ERROR_BASE 0x1u
#endif /* TFM_UNIQUE_ERROR_CODES */

/**
 * Generic MHU error enumeration types.
 */
enum mhu_error_t {
    MHU_ERR_NONE =  0,
    MHU_ERR_INVALID_VERSION = MHU_ERROR_BASE,
    MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG,
    MHU_ERR_WAIT_SIGNAL_CLEAR_INVALID_ARG,
    MHU_ERR_CLEAR_WAIT_SIGNAL_INVALID_ARG,
    MHU_ERR_VALIDATE_BUFFER_PARAMS_INVALID_ARG,
    MHU_ERR_INIT_SENDER_INVALID_ARG,
    MHU_ERR_INIT_SENDER_UNSUPPORTED,
    MHU_ERR_INIT_RECEIVER_INVALID_ARG,
    MHU_ERR_INIT_RECEIVER_UNSUPPORTED,
    MHU_ERR_SEND_DATA_INVALID_ARG,
    MHU_ERR_RECEIVE_DATA_INVALID_ARG,
    MHU_ERR_RECEIVE_DATA_BUFFER_TOO_SMALL,
    MHU_ERR_FORCE_UINT_SIZE = UINT_MAX,
};

/**
 * \brief Initializes sender MHU.
 *
 * \param[in] mhu_sender_dev        Pointer to the sender MHU.
 *
 * \return Returns mhu_error_t error code.
 *
 * \note This function must be called before mhu_send_data().
 */
enum mhu_error_t mhu_init_sender(void *mhu_sender_dev);

/**
 * \brief Initializes receiver MHU.
 *
 * \param[in] mhu_receiver_dev      Pointer to the receiver MHU.
 *
 * \return Returns mhu_error_t error code.
 *
 * \note This function must be called before mhu_receive_data().
 */
enum mhu_error_t mhu_init_receiver(void *mhu_receiver_dev);

/**
 * \brief Sends data over MHU.
 *
 * \param[in] mhu_sender_dev  Pointer to the sender MHU.
 * \param[in] send_buffer     Pointer to buffer containing the data to be
 *                            transmitted.
 * \param[in] size            Size of the data to be transmitted in bytes.
 *
 * \return Returns mhu_error_t error code.
 *
 * \note For MHUv2, the send_buffer must be 4-byte aligned and its length must
 *       be at least (4 - (size % 4)) bytes bigger than the data size to
 *       prevent buffer over-reading.
 */
enum mhu_error_t mhu_send_data(void *mhu_sender_dev,
                               const uint8_t *send_buffer,
                               size_t size);

/**
 * \brief Wait for data from MHU.
 *
 * \param[in]     mhu_receiver_dev  Pointer to the receiver MHU.
 *
 * \return Returns mhu_error_t error code.
 *
 * \note This function must be called before mhu_receive_data() if the MHU
 *       receiver interrupt is not used.
 */
enum mhu_error_t mhu_wait_data(void *mhu_receiver_dev);

/**
 * \brief Receives data from MHU.
 *
 * \param[in]     mhu_receiver_dev  Pointer to the receiver MHU.
 * \param[out]    receive_buffer    Pointer the buffer where to store the
 *                                  received data.
 * \param[in,out] size              As input the size of the receive_buffer,
 *                                  as output the number of bytes received.
 *                                  As a limitation, the size of the buffer
 *                                  must be a multiple of 4 for MHUv2.
 *
 * \return Returns mhu_error_t error code.
 *
 * \note For MHUv2, the receive_buffer must be 4-byte aligned and its length
 *       must be a multiple of 4.
 */
enum mhu_error_t mhu_receive_data(void *mhu_receiver_dev,
                                  uint8_t *receive_buffer,
                                  size_t *size);

/**
 * \brief Signals an interrupt over the last available channel and wait for the
 *        values to be cleared by the receiver.
 *
 * \param[in]     mhu_sender_dev   Pointer to the sender MHU.
 * \param[in]     value            Value that will be used while signaling.
 *
 * \return Returns mhu_error_t error code.
 */
enum mhu_error_t signal_and_wait_for_clear(void *mhu_sender_dev,
                                           uint32_t value);

/**
 * \brief Wait for signal on the last available channel in a loop and
 *        acknowledge the transfer by clearing the status on that channel.
 *
 * \param[in]     mhu_receiver_dev Pointer to the receiver MHU.
 * \param[in]     value            Value that will be used while waiting.
 *
 * \return Returns mhu_error_t error code.
 */
enum mhu_error_t wait_for_signal_and_clear(void *mhu_receiver_dev,
                                           uint32_t value);
#ifdef __cplusplus
}
#endif

#endif /* __MHU_H__ */

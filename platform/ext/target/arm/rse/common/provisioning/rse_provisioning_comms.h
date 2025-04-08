/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_COMMS_H__
#define __RSE_PROVISIONING_COMMS_H__

#include "platform_error_codes.h"
#include "rse_provisioning_message.h"
#include "tfm_plat_defs.h"

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize provisioning communications.
 *
 * This function sets up the provisioning_comms HAL
 *
 * @param msg Pointer to a location where received provisioning message will
 *            be stored
 * @param msg_len Size of the msg buffer
 *
 * @return Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t provisioning_comms_init(const struct rse_provisioning_message_t *msg,
                                            size_t msg_len);

/**
  * @brief Signal that the provisioning interface is ready (non-blocking).
  *
  * This function notifies the other side that the device is ready to proceed
  * with the provisioning process. It does not block for acknowledgement.
  *
  * @return Returns a tfm_plat_err_t indicating success or failure.
  */
enum tfm_plat_err_t provisioning_comms_signal_ready_non_blocking(void);

/**
  * @brief Receive a provisioning command (non-blocking).
  *
  * This function attempts to receive a command message as part of the provisioning
  * process. The function is expected to be called when an interrupt has
  * been received and will process it.
  *
  * @param full_message Whether or not the provisioning comms HAL has received
  *                     a full message which is ready to be processed
  *
  * @return Returns a tfm_plat_err_t indicating success or failure.
  */
enum tfm_plat_err_t provisioning_comms_receive_command_non_blocking(bool *full_message);

/**
  * @brief Receive multiple provisioning commands (blocking).
  *
  * This function blocks until a complete message is received. It writes the received
  * data into the buffer passed in provisioning_comms_init.
  *
  * @return Returns a tfm_plat_err_t indicating success or failure.
  */
enum tfm_plat_err_t provisioning_comms_receive_commands_blocking(void);

/**
  * @brief Send a data message and wait for a response.
  *
  * This function sends a message and blocks until a response is received.
  *
  * @param msg Pointer to the message to send.
  * @param msg_size Size of the message to send.
  *
  * @return Returns a tfm_plat_err_t indicating success or failure.
  */
enum tfm_plat_err_t
provisioning_comms_send_msg_blocking(const struct rse_provisioning_message_t *msg, size_t msg_size);

/**
  * @brief Send a report and wait for a response.
  *
  * Sends a report message (as a raw data buffer) and blocks until a response is received.
  *
  * @param msg Pointer to the report data to send.
  * @param msg_size Size of the report data in bytes.
  *
  * @return Returns a tfm_plat_err_t indicating success or failure.
  */
enum tfm_plat_err_t provisioning_comms_send_status_blocking(uint32_t *msg, size_t msg_size);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_COMMS_H__ */

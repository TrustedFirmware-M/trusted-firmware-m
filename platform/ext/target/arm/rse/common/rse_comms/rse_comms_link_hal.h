/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_LINK_HAL_H__
#define __RSE_COMMS_LINK_HAL_H__

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "platform_error_codes.h"
#include "rse_comms_link_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

enum rse_comms_hal_error_t {
    RSE_COMMS_HAL_ERROR_SUCCESS = 0,
    RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE,
    RSE_COMMS_HAL_ERROR_CANNOT_GET_ID,
    RSE_COMMS_HAL_ERROR_CANNOT_GET_ROUTING_TABLES,
    RSE_COMMS_HAL_ERROR_DEVICE_SEND_FAIL,
    RSE_COMMS_HAL_ERROR_DEVICE_IS_AVAILABLE_FAIL,
    RSE_COMMS_HAL_ERROR_DEVICE_GET_MSG_LEN_FAIL,
    RSE_COMMS_HAL_ERROR_DEVICE_RECEIVE_FAIL,
    RSE_COMMS_HAL_ERROR_DEVICE_INIT_FAIL,
    RSE_COMMS_HAL_ERROR_FORCE_UINT32 = UINT32_MAX,
};

/**
 * \brief Retrieves the route (link ID) to the specified node.
 *
 * This function determines the appropriate communication link (route)
 * to send a message to the node.
 *
 * \param node_id The identifier of the target node.
 * \return The link ID corresponding to the link to send the message on.
 */
rse_comms_link_id_t rse_comms_hal_get_route(rse_comms_node_id_t node_id);

/**
 * \brief Retrieves the current node's identifier.
 *
 * This function obtains the node ID for the current device.
 *
 * \param[out] node_id Pointer to a variable where the node ID will be stored.
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on success, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_get_my_node_id(rse_comms_node_id_t *node_id);

/**
 * \brief Sends a message over the specified communication link.
 *
 * This function sends a message to a remote node using the provided link ID.
 *
 * \param link_id      The link identifier to use for transmission.
 * \param message      Pointer to the message data to send.
 * \param message_size The size of the message in bytes.
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on success, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_send_message(rse_comms_link_id_t link_id,
                                                      const uint8_t *message, size_t message_size);

/**
 * \brief Waits for a message on the specified communication link.
 *
 * This function blocks until a message is received on the specified link.
 *
 * \note This is a blocking call. Consider updating to a non-blocking variant if needed.
 *
 * \param link_id The link identifier to wait on.
 * \param is_available Whether or not the message is available
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on success, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_is_message_available(rse_comms_link_id_t link_id,
                                                              bool *is_available);

/**
 * \brief Retrieves the size of the next message to be received on the specified communication
 *        link.
 *
 * This function queries the communication link identified by @p link_id to determine the size
 * of the next available message. The size is returned via the @p message_size pointer.
 *
 * \param[in]  link_id       The link identifier to query.
 * \param[out] message_size  Pointer to a variable where the size of
                             the message (in bytes) will be stored.
 *
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on success, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_get_receive_message_size(rse_comms_link_id_t link_id,
                                                                  size_t *message_size);

/**
 * \brief Receives a message from the specified communication link.
 *
 * This function receives a message from the given link and stores it in the provided buffer.
 *
 * \param link_id      The link identifier to receive the message from.
 * \param message      Pointer to the buffer where the received message will be stored.
 * \param message_size The size of the message to receive in bytes.
 *                     The buffer must be at least this size.
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on success, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_receive_message(rse_comms_link_id_t link_id,
                                                         uint8_t *message, size_t message_size);

/**
 * \brief Initializes the communication HAL layer.
 *
 * This function initializes internal data structures and hardware resources required
 * for communication.
 *
 * \return RSE_COMMS_HAL_ERROR_SUCCESS on successful initialization, or an appropriate error code.
 */
enum rse_comms_hal_error_t rse_comms_hal_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_LINK_HAL_H__ */

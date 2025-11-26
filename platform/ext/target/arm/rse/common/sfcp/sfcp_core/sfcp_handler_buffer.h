/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_HANDLER_BUFFER_H__
#define __SFCP_HANDLER_BUFFER_H__

#include "sfcp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Reserve a handler buffer capable of holding an incoming packet.
 *
 * \details
 * Allocates internal storage for a message of up to \p message_size bytes,
 * returning a handle that can later be used to access or release the buffer.
 * This is typically invoked by the interrupt handler before handing control
 * over to a protocol-specific handler.
 *
 * \param[out] buffer_handle  On success, updated with the allocated buffer handle.
 * \param[in]  message_size   Size in bytes required to store the incoming packet.
 *
 * \return SFCP_ERROR_SUCCESS on success;
 *         SFCP_ERROR_ALLOCATE_BUFFER_TOO_LARGE if the request exceeds limits;
 *         SFCP_ERROR_ALLOCATE_BUFFER_FAILED on allocation failure.
 */
enum sfcp_error_t sfcp_allocate_handler_buffer(sfcp_buffer_handle_t *buffer_handle,
                                               size_t message_size);

/**
 * \brief Obtain a pointer/size to a buffered packet (handler mode).
 *
 * \details
 * Provides a read-only view of a packet that was previously delivered
 * to a handler via its \ref sfcp_buffer_handle_t. This function
 * is typically called inside a handler or by a deferred consumer to
 * examine the full packet in-place before deciding how to process it.
 *
 * \param[in]  buffer_handle  Handle previously provided to a message or reply handler.
 * \param[out] buf            On success, set to point to the internal packet buffer.
 * \param[out] buf_size       On success, set to the size in bytes of \p buf.
 *
 * \return SFCP_ERROR_SUCCESS on success;
 *         SFCP_ERROR_INVALID_BUFFER_HANDLE if \p buffer_handle is not valid;
 *         other error codes as appropriate.
 */
enum sfcp_error_t sfcp_get_handler_buffer(sfcp_buffer_handle_t buffer_handle, uint8_t **buf,
                                          size_t *buf_size);

/**
 * \brief Retire (pop) a buffered packet after handling (handler mode).
 *
 * \details
 * Removes the entry associated with \p buffer_handle from the internal
 * SFCP buffer once the packet has been successfully processed.
 *
 * \param[in] buffer_handle  Handle previously provided to a message or reply handler.
 *
 * \return SFCP_ERROR_SUCCESS on success;
 *         SFCP_ERROR_INVALID_BUFFER_HANDLE if \p buffer_handle is not valid;
 *
 * \note After a successful pop, the handle must not be reused.
 */
enum sfcp_error_t sfcp_pop_handler_buffer(sfcp_buffer_handle_t buffer_handle);

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_HANDLER_BUFFER_H__ */

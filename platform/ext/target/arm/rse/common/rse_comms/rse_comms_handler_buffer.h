/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_HANDLER_BUFFER_H__
#define __RSE_COMMS_HANDLER_BUFFER_H__

#include "rse_comms.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Obtain a pointer/size to a buffered packet (handler mode).
 *
 * \details
 * Provides a read-only view of a packet that was previously delivered
 * to a handler via its \ref rse_comms_buffer_handle_t. This function
 * is typically called inside a handler or by a deferred consumer to
 * examine the full packet in-place before deciding how to process it.
 *
 * \param[in]  buffer_handle  Handle previously provided to a message or reply handler.
 * \param[out] buf            On success, set to point to the internal packet buffer.
 * \param[out] buf_size       On success, set to the size in bytes of \p buf.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_INVALID_BUFFER_HANDLE if \p buffer_handle is not valid;
 *         other error codes as appropriate.
 */
enum rse_comms_error_t rse_comms_get_handler_buffer(rse_comms_buffer_handle_t buffer_handle,
                                                    uint8_t **buf, size_t *buf_size);

/**
 * \brief Retire (pop) a buffered packet after handling (handler mode).
 *
 * \details
 * Removes the entry associated with \p buffer_handle from the internal
 * comms buffer once the packet has been successfully processed.
 *
 * \param[in] buffer_handle  Handle previously provided to a message or reply handler.
 *
 * \return RSE_COMMS_ERROR_SUCCESS on success;
 *         RSE_COMMS_ERROR_INVALID_BUFFER_HANDLE if \p buffer_handle is not valid;
 *
 * \note After a successful pop, the handle must not be reused.
 */
enum rse_comms_error_t rse_comms_pop_handler_buffer(rse_comms_buffer_handle_t buffer_handle);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_HANDLER_BUFFER_H__ */

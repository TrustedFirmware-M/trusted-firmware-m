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

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_HAL_H__ */

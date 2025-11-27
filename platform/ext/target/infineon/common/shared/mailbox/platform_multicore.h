/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2024-2025-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _PLATFORM_MULTICORE_
#define _PLATFORM_MULTICORE_

#include <stdint.h>
#include "cy_device.h"

#define IFX_PSA_CLIENT_CALL_REQ_MAGIC        (0xA5CF50C6U)
#define IFX_PSA_CLIENT_CALL_REPLY_MAGIC      (0xC605FC5AU)

#define IFX_NS_MAILBOX_INIT_ENABLE           (0xAEU)
#define IFX_S_MAILBOX_READY                  (0xC3U)

#define IFX_PLATFORM_MAILBOX_SUCCESS         (0x0)
#define IFX_PLATFORM_MAILBOX_INVAL_PARAMS    (INT32_MIN + 1)
#define IFX_PLATFORM_MAILBOX_TX_ERROR        (INT32_MIN + 2)
#define IFX_PLATFORM_MAILBOX_RX_ERROR        (INT32_MIN + 3)
#define IFX_PLATFORM_MAILBOX_INIT_ERROR      (INT32_MIN + 4)

#define IFX_IPC_SYNC_MAGIC                   0x7DADE011U

/**
 * \brief Fetch a pointer from mailbox message
 *
 * \param[out] msg_ptr     The address to write the pointer value to.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int32_t ifx_mailbox_fetch_msg_ptr(void **msg_ptr);

/**
 * \brief Fetch a data value from mailbox message
 *
 * \param[out] data_ptr    The address to write the pointer value to.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int32_t ifx_mailbox_fetch_msg_data(uint32_t *data_ptr);

/**
 * \brief Send a pointer via mailbox message
 *
 * \param[in] msg_ptr      The pointer value to be sent.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int32_t ifx_mailbox_send_msg_ptr(const void *msg_ptr);

/**
 * \brief Send a data value via mailbox message
 *
 * \param[in] data         The data value to be sent
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int32_t ifx_mailbox_send_msg_data(uint32_t data);

/**
 * \brief Wait for a mailbox notify event.
 */
void ifx_mailbox_wait_for_notify(void);

#endif

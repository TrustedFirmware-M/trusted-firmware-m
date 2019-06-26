/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _TFM_PLATFORM_MAILBOX_
#define _TFM_PLATFORM_MAILBOX_

#include <stdint.h>

#define IPC_PSA_CLIENT_CALL_CHAN         (7)
#define IPC_PSA_CLIENT_CALL_INTR_STRUCT  (4)
#define IPC_PSA_CLIENT_CALL_INTR_MASK    (1 << IPC_PSA_CLIENT_CALL_CHAN)
#define IPC_PSA_CLIENT_CALL_NOTIFY_MASK  (1 << IPC_PSA_CLIENT_CALL_INTR_STRUCT)

#define IPC_PSA_CLIENT_REPLY_CHAN        (8)
#define IPC_PSA_CLIENT_REPLY_INTR_STRUCT (5)
#define IPC_PSA_CLIENT_REPLY_INTR_MASK   (1 << IPC_PSA_CLIENT_REPLY_CHAN)
#define IPC_PSA_CLIENT_REPLY_NOTIFY_MASK (1 << IPC_PSA_CLIENT_REPLY_INTR_STRUCT)

#define IPC_RX_RELEASE_MASK              (0)

#define CY_IPC_NOTIFY_SHIFT              (16)

#define PSA_CLIENT_CALL_REQ_MAGIC        (0xA5CF50C6)

#define NS_MAILBOX_INIT_ENABLE           (0xAE)
#define S_MAILBOX_READY                  (0xC3)

#define PLATFORM_MAILBOX_SUCCESS         (0x0)
#define PLATFORM_MAILBOX_INVAL_PARAMS    (INT32_MIN + 1)
#define PLATFORM_MAILBOX_TX_ERROR        (INT32_MIN + 2)
#define PLATFORM_MAILBOX_RX_ERROR        (INT32_MIN + 3)
#define PLATFORM_MAILBOX_INIT_ERROR      (INT32_MIN + 4)

/* Inter-Processor Communication (IPC) data channel for the Semaphores */
#define PLATFORM_MAILBOX_IPC_CHAN_SEMA   CY_IPC_CHAN_SEMA
#define MAILBOX_SEMAPHORE_NUM            (0)


/**
 * \brief Fetch a pointer from mailbox message
 *
 * \param[out] msg_ptr     The address to write the pointer value to.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_mailbox_fetch_msg_ptr(void **msg_ptr);

/**
 * \brief Fetch a data value from mailbox message
 *
 * \param[out] data_ptr    The address to write the pointer value to.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_mailbox_fetch_msg_data(uint32_t *data_ptr);

/**
 * \brief Send a pointer via mailbox message
 *
 * \param[in] msg_ptr      The pointer value to be sent.
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_mailbox_send_msg_ptr(const void *msg_ptr);

/**
 * \brief Send a data value via mailbox message
 *
 * \param[in] data         The data value to be sent
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_mailbox_send_msg_data(uint32_t data);

/**
 * \brief Wait for a mailbox notify event.
 */
void platform_mailbox_wait_for_notify(void);

/**
 * \brief IPC initialization
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_ns_ipc_init(void);

/**
 * \brief Synchronisation with secure CPU, platform-specific implementation.
 *        Flags that the non-secure side has completed its initialization.
 *        Waits, if necessary, for the secure CPU to flag that it has completed
 *        its initialization.
 *
 *
 * \retval 0               The operation succeeds.
 * \retval else            The operation fails.
 */
int platform_ns_wait_for_s_cpu_ready(void);

#endif

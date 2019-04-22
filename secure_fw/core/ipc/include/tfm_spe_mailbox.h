/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_SPE_MAILBOX_H
#define TFM_SPE_MAILBOX_H

#include "tfm_mailbox.h"

/* A single slot structure in SPE mailbox queue */
struct secure_mailbox_slot_t {
    struct mailbox_msg_t msg;

    uint8_t              ns_slot_idx;
    mailbox_msg_handle_t msg_handle;
};

struct secure_mailbox_queue_t {
    mailbox_queue_status_t       empty_slots;      /* bitmask of empty slots */

    struct secure_mailbox_slot_t queue[NUM_MAILBOX_QUEUE_SLOT];
    struct ns_mailbox_queue_t    *ns_queue;
};

/**
 * \brief Handle mailbox message(s) from NSPE.
 *
 * \retval MAILBOX_SUCCESS      Successfully get PSA client call return result.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_handle_msg(void);

/**
 * \brief Return PSA client call return result to NSPE.
 *
 * \param[in] handle            The handle to the mailbox message
 * \param[in] reply             PSA client call return result to be written
 *                              to NSPE.
 *
 * \retval MAILBOX_SUCCESS      Operation succeeded.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_reply_msg(mailbox_msg_handle_t handle, int32_t reply);

/**
 * \brief Notify NSPE that a PSA client call return result is replied
 *
 * \retval MAILBOX_SUCCESS      The notification is uccessfully sent out.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_notify_peer(void);

/**
 * \brief SPE mailbox initialization
 *
 * \retval MAILBOX_SUCCESS      Operation succeeded.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_init(void);

/**
 * \brief Platform specific initialization of SPE mailbox.
 *
 * \param[in] s_queue           The base address of SPE mailbox queue.
 *
 * \retval MAILBOX_SUCCESS      Operation succeeded.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_hal_init(struct secure_mailbox_queue_t *s_queue);

/**
 * \brief Enter critical section of NSPE mailbox
 */
void tfm_mailbox_enter_critical(void);

/**
 * \brief Exit critical section of NSPE mailbox
 */
void tfm_mailbox_exit_critical(void);

#endif
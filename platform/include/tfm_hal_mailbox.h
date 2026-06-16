/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_HAL_MAILBOX_H__
#define __TFM_HAL_MAILBOX_H__

#include "tfm_mailbox.h"

/* A handle to a mailbox message in use */
typedef int32_t    mailbox_msg_handle_t;

#define MAILBOX_MSG_NULL_HANDLE             ((mailbox_msg_handle_t)0)

/* A single slot structure in SPE mailbox queue */
struct secure_mailbox_slot_t {
    struct mailbox_msg_t msg;

    uint8_t              ns_slot_idx;
    mailbox_msg_handle_t msg_handle;
};

struct secure_mailbox_queue_t {
    mailbox_queue_status_t       empty_slots;      /* bitmask of empty slots */

    struct secure_mailbox_slot_t queue[NUM_MAILBOX_QUEUE_SLOT];
    /* Shared data with fixed size */
    struct mailbox_status_t       *ns_status;
    /* Number of slots allocated by NS. */
    uint32_t                     ns_slot_count;
    /* Pointer to struct mailbox_slot_t[slot_count] allocated by NS */
    struct mailbox_slot_t        *ns_slots;
};

/**
 * \brief Platform specific initialization of SPE mailbox.
 *
 * \param[in] s_queue           The base address of SPE mailbox queue.
 *
 * \note The callee is expected to do the following:
 *       - allocate a temporary struct mailbox_init_t
 *       - perform the platform-specific call into non-secure to fetch the
 *         pointer above
 *       - fill status, slot_count and slots pointers in the given SPE mailbox
 *         queue.
 *       Once returned, SPE checks the filled addresses and the slot counts.
 *
 * \retval MAILBOX_SUCCESS      Operation succeeded.
 * \retval Other return code    Operation failed with an error code (< 0).
 */
int32_t tfm_mailbox_hal_init(struct secure_mailbox_queue_t *s_queue);

/**
 * \brief Notify NSPE that a PSA client call return result is replied.
 *        Implemented by platform specific inter-processor communication driver.
 *
 * \retval MAILBOX_SUCCESS      The notification is successfully sent out.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t tfm_mailbox_hal_notify_peer(void);

/**
 * \brief Enter critical section of NSPE mailbox
 *
 * \return Platform specific critical section state. Use it to exit from critical section
 * by passing result to \ref tfm_mailbox_hal_exit_critical.
 */
uint32_t tfm_mailbox_hal_enter_critical(void);

/**
 * \brief Exit critical section of NSPE mailbox
 *
 * \param[in] state             Critical section state returned by
 *                              \ref tfm_mailbox_hal_enter_critical.
 */
void tfm_mailbox_hal_exit_critical(uint32_t state);

#endif /* __TFM_HAL_MAILBOX_H__ */

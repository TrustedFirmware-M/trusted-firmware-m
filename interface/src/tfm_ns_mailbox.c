/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "tfm_ns_mailbox.h"

/* The pointer to NSPE mailbox queue */
static struct ns_mailbox_queue_t *mailbox_queue_ptr = NULL;

static inline void clear_queue_slot_empty(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        mailbox_queue_ptr->empty_slots &= ~(1 << idx);
    }
}

static inline void set_queue_slot_empty(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        mailbox_queue_ptr->empty_slots |= (1 << idx);
    }
}

static inline void set_queue_slot_pend(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        mailbox_queue_ptr->pend_slots |= (1 << idx);
    }
}

static inline int32_t get_mailbox_msg_handle(uint8_t idx,
                                             mailbox_msg_handle_t *handle)
{
    if ((idx >= NUM_MAILBOX_QUEUE_SLOT) || !handle) {
        return MAILBOX_MSG_NULL_HANDLE;
    }

    *handle = (mailbox_msg_handle_t)(idx + 1);

    return MAILBOX_SUCCESS;
}

static inline int32_t get_mailbox_msg_idx(mailbox_msg_handle_t handle,
                                          uint8_t *idx)
{
    if ((handle == MAILBOX_MSG_NULL_HANDLE) || !idx) {
        return MAILBOX_INVAL_PARAMS;
    }

    *idx = (uint8_t)(handle - 1);

    return MAILBOX_SUCCESS;
}

static inline void clear_queue_slot_replied(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        mailbox_queue_ptr->replied_slots &= ~(1 << idx);
    }
}

static uint8_t acquire_empty_slot(const struct ns_mailbox_queue_t *queue)
{
    uint8_t idx;
    mailbox_queue_status_t status;

    mailbox_enter_critical();
    status = queue->empty_slots;

    if (!status) {
        /* No empty slot */
        mailbox_exit_critical();
        return NUM_MAILBOX_QUEUE_SLOT;
    }

    for (idx = 0; idx < NUM_MAILBOX_QUEUE_SLOT; idx++) {
        if (status & (1 << idx)) {
            break;
        }
    }

    clear_queue_slot_empty(idx);

    mailbox_exit_critical();

    return idx;
}

mailbox_msg_handle_t mailbox_tx_client_call_req(uint32_t call_type,
                                    const struct client_call_params_t *params,
                                    int32_t client_id)
{
    uint8_t idx;
    struct mailbox_msg_t *msg_ptr;
    mailbox_msg_handle_t handle;

    if (!mailbox_queue_ptr) {
        return MAILBOX_MSG_NULL_HANDLE;
    }

    if (!params) {
        return MAILBOX_MSG_NULL_HANDLE;
    }

    idx = acquire_empty_slot(mailbox_queue_ptr);
    if (idx >= NUM_MAILBOX_QUEUE_SLOT) {
        return MAILBOX_QUEUE_FULL;
    }

    /* Fill the mailbox message */
    msg_ptr = &mailbox_queue_ptr->queue[idx].msg;

    msg_ptr->call_type = call_type;
    memcpy(&msg_ptr->params, params, sizeof(msg_ptr->params));
    msg_ptr->client_id = client_id;

    get_mailbox_msg_handle(idx, &handle);

    mailbox_enter_critical();
    set_queue_slot_pend(idx);
    mailbox_exit_critical();

    mailbox_notify_peer();

    return handle;
}

int32_t mailbox_rx_client_call_reply(mailbox_msg_handle_t handle,
                                     int32_t *reply)
{
    uint8_t idx;
    int32_t ret;

    if (!mailbox_queue_ptr) {
        return MAILBOX_INVAL_PARAMS;
    }

    if ((handle == MAILBOX_MSG_NULL_HANDLE) || (!reply)) {
        return MAILBOX_INVAL_PARAMS;
    }

    ret = get_mailbox_msg_idx(handle, &idx);
    if (ret != MAILBOX_SUCCESS) {
        return ret;
    }

    *reply = mailbox_queue_ptr->queue[idx].reply.return_val;

    mailbox_enter_critical();
    set_queue_slot_empty(idx);
    clear_queue_slot_replied(idx);
    mailbox_exit_critical();

    return MAILBOX_SUCCESS;
}

bool mailbox_is_msg_replied(mailbox_msg_handle_t handle)
{
    uint8_t idx;
    int32_t ret;
    mailbox_queue_status_t status;

    if (!mailbox_queue_ptr) {
        return false;
    }

    if (handle == MAILBOX_MSG_NULL_HANDLE) {
        return false;
    }

    ret = get_mailbox_msg_idx(handle, &idx);
    if (ret != MAILBOX_SUCCESS) {
        return false;
    }

    mailbox_enter_critical();
    status = mailbox_queue_ptr->replied_slots;
    mailbox_exit_critical();

    if (status & (1 << idx)) {
        return true;
    }

    return false;
}

int32_t mailbox_init(struct ns_mailbox_queue_t *queue)
{
    int32_t ret;

    if (!queue) {
        return MAILBOX_INVAL_PARAMS;
    }

    /*
     * FIXME
     * Further verification of mailbox queue address may be required according
     * to non-secure memory assignment.
     */

    memset(queue, 0, sizeof(*queue));

    /* Initialize empty bitmask */
    queue->empty_slots = (mailbox_queue_status_t)((1 << NUM_MAILBOX_QUEUE_SLOT)
                                                  - 1);

    mailbox_queue_ptr = queue;

    /* Platform specific initialization. */
    ret = mailbox_hal_init(queue);

    return ret;
}

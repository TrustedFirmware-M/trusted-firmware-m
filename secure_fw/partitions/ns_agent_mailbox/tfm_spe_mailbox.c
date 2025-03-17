/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2021-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#include "cmsis_compiler.h"

#include "async.h"
#include "config_impl.h"
#include "internal_status_code.h"
#include "psa/error.h"
#include "utilities.h"
#include "tfm_arch.h"
#include "thread.h"
#include "tfm_psa_call_pack.h"
#include "tfm_spe_mailbox.h"
#include "tfm_rpc.h"
#include "tfm_hal_multi_core.h"
#include "tfm_multi_core.h"
#include "ffm/mailbox_agent_api.h"


/* If there's no dcache at all, the SCB cache functions won't exist */
/* If the mailbox is uncached on the S side, no need to flush and invalidate */
#if !defined(__DCACHE_PRESENT) || (__DCACHE_PRESENT == 0U) || (MAILBOX_IS_UNCACHED_S == 1)
#define MAILBOX_CLEAN_CACHE(addr, size) __DSB()
#define MAILBOX_INVALIDATE_CACHE(addr, size) do {} while (0)
#else
#define MAILBOX_CLEAN_CACHE(addr, size) SCB_CleanDCache_by_Addr((addr), (size))
#define MAILBOX_INVALIDATE_CACHE(addr, size) SCB_InvalidateDCache_by_Addr((addr), (size))
#endif

static struct secure_mailbox_queue_t spe_mailbox_queue;

/*
 * Local copies of invecs and outvecs associated with each mailbox message
 * while it is being processed.
 */
struct vectors {
    psa_invec in_vec[PSA_MAX_IOVEC];
    psa_outvec out_vec[PSA_MAX_IOVEC];
    psa_outvec *original_out_vec;
    size_t out_len;
    bool in_use;
};
static struct vectors vectors[NUM_MAILBOX_QUEUE_SLOT] = {0};


__STATIC_INLINE void set_spe_queue_empty_status(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        spe_mailbox_queue.empty_slots |= (1 << idx);
    }
}

__STATIC_INLINE void clear_spe_queue_empty_status(uint8_t idx)
{
    if (idx < NUM_MAILBOX_QUEUE_SLOT) {
        spe_mailbox_queue.empty_slots &= ~(1 << idx);
    }
}

__STATIC_INLINE bool get_spe_queue_empty_status(uint8_t idx)
{
    if ((idx < NUM_MAILBOX_QUEUE_SLOT) &&
        (spe_mailbox_queue.empty_slots & (1 << idx))) {
        return true;
    }

    return false;
}

__STATIC_INLINE mailbox_queue_status_t get_nspe_queue_pend_status(
                                    const struct mailbox_status_t *ns_status)
{
    MAILBOX_INVALIDATE_CACHE(ns_status, sizeof(*ns_status));
    return ns_status->pend_slots;
}

__STATIC_INLINE void set_nspe_queue_replied_status(
                                            struct mailbox_status_t *ns_status,
                                            mailbox_queue_status_t mask)
{
    MAILBOX_INVALIDATE_CACHE(ns_status, sizeof(*ns_status));
    ns_status->replied_slots |= mask;
    MAILBOX_CLEAN_CACHE(ns_status, sizeof(*ns_status));
}

__STATIC_INLINE void clear_nspe_queue_pend_status(
                                            struct mailbox_status_t *ns_status,
                                            mailbox_queue_status_t mask)
{
    MAILBOX_INVALIDATE_CACHE(ns_status, sizeof(*ns_status));
    ns_status->pend_slots &= ~mask;
    MAILBOX_CLEAN_CACHE(ns_status, sizeof(*ns_status));
}

__STATIC_INLINE int32_t get_spe_mailbox_msg_handle(uint8_t idx,
                                                   mailbox_msg_handle_t *handle)
{
    if ((idx >= NUM_MAILBOX_QUEUE_SLOT) || !handle) {
        return MAILBOX_INVAL_PARAMS;
    }

    *handle = (mailbox_msg_handle_t)(idx + 1);

    return MAILBOX_SUCCESS;
}

__STATIC_INLINE int32_t get_spe_mailbox_msg_idx(mailbox_msg_handle_t handle,
                                                uint8_t *idx)
{
    if ((handle == MAILBOX_MSG_NULL_HANDLE) || !idx) {
        return MAILBOX_INVAL_PARAMS;
    }

    *idx = (uint8_t)(handle - 1);

    return MAILBOX_SUCCESS;
}

static void mailbox_clean_queue_slot(uint8_t idx)
{
    if (idx >= NUM_MAILBOX_QUEUE_SLOT) {
        return;
    }

    spm_memset(&spe_mailbox_queue.queue[idx], 0,
                         sizeof(spe_mailbox_queue.queue[idx]));
    set_spe_queue_empty_status(idx);
}

__STATIC_INLINE struct mailbox_reply_t *get_nspe_reply_addr(uint8_t idx)
{
    uint8_t ns_slot_idx;

    if (idx >= NUM_MAILBOX_QUEUE_SLOT) {
        psa_panic();
    }

    ns_slot_idx = spe_mailbox_queue.queue[idx].ns_slot_idx;
    if ((ns_slot_idx >= NUM_MAILBOX_QUEUE_SLOT) || (ns_slot_idx >= spe_mailbox_queue.ns_slot_count)) {
        psa_panic();
    }

    return &spe_mailbox_queue.ns_slots[ns_slot_idx].reply;
}

static void mailbox_direct_reply(uint8_t idx, uint32_t result)
{
    struct mailbox_reply_t *reply_ptr;
    uint32_t ret_result = result;

    /* Copy outvec lengths back if necessary */
    if ((vectors[idx].in_use) && (result == PSA_SUCCESS)) {
        for (int i = 0; i < vectors[idx].out_len; i++) {
            vectors[idx].original_out_vec[i].len = vectors[idx].out_vec[i].len;
        }
    }

    vectors[idx].in_use = false;

    /* Get reply address */
    reply_ptr = get_nspe_reply_addr(idx);
    spm_memcpy(&reply_ptr->return_val, &ret_result,
               sizeof(reply_ptr->return_val));
    MAILBOX_CLEAN_CACHE(reply_ptr, sizeof(*reply_ptr));

    mailbox_clean_queue_slot(idx);

    /*
     * Skip NSPE queue status update after single reply.
     * Update NSPE queue status after all the mailbox messages are completed
     */
}

__STATIC_INLINE int32_t check_mailbox_msg(const struct mailbox_msg_t *msg)
{
    /*
     * TODO
     * Comprehensive check of mailbox msessage content can be implemented here.
     */
    (void)msg;
    return MAILBOX_SUCCESS;
}

static int local_copy_vects(const struct psa_client_params_t *params,
                            uint32_t idx,
                            uint32_t *control)
{
    size_t in_len, out_len;

    in_len = params->psa_call_params.in_len;
    out_len = params->psa_call_params.out_len;

    if (((params->psa_call_params.out_vec == NULL) && (out_len != 0)) ||
        ((params->psa_call_params.in_vec == NULL) && (in_len != 0))) {
        return MAILBOX_INVAL_PARAMS;
    }

    if ((in_len > PSA_MAX_IOVEC) ||
        (out_len > PSA_MAX_IOVEC) ||
        ((in_len + out_len) > PSA_MAX_IOVEC)) {
        return MAILBOX_INVAL_PARAMS;
    }

    for (unsigned int i = 0; i < PSA_MAX_IOVEC; i++) {
        if (i < in_len) {
            vectors[idx].in_vec[i] = params->psa_call_params.in_vec[i];
        } else {
            vectors[idx].in_vec[i].base = 0;
            vectors[idx].in_vec[i].len = 0;
        }
    }

    for (unsigned int i = 0; i < PSA_MAX_IOVEC; i++) {
        if (i < out_len) {
            vectors[idx].out_vec[i] = params->psa_call_params.out_vec[i];
        } else {
            vectors[idx].out_vec[i].base = 0;
            vectors[idx].out_vec[i].len = 0;
        }
    }

    *control = PARAM_SET_NS_INVEC(*control);
    *control = PARAM_SET_NS_OUTVEC(*control);

    vectors[idx].out_len = out_len;
    vectors[idx].original_out_vec = params->psa_call_params.out_vec;

    vectors[idx].in_use = true;
    return MAILBOX_SUCCESS;
}

/* Passes the request from the mailbox message into SPM.
 * idx indicates the slot used to use for any immediate reply.
 * If it queues the reply immediately, updates reply_slots accordingly.
 */
static int32_t tfm_mailbox_dispatch(const struct mailbox_msg_t *msg_ptr,
                                    uint8_t idx,
                                    mailbox_queue_status_t *reply_slots)
{
    const struct psa_client_params_t *params = &msg_ptr->params;
    struct client_params_t client_params = {0};
    uint32_t control = PARAM_PACK(params->psa_call_params.type,
                                  params->psa_call_params.in_len,
                                  params->psa_call_params.out_len);
    int32_t client_id;
    psa_status_t psa_ret = PSA_ERROR_GENERIC_ERROR;
    mailbox_msg_handle_t *mb_msg_handle =
        &spe_mailbox_queue.queue[idx].msg_handle;
    int ret;

#if CONFIG_TFM_SPM_BACKEND_IPC == 1
    /* Assume asynchronous. Set to synchronous when an error happens. */
    bool sync = false;
#else
    /* Assume synchronous. */
    bool sync = true;
#endif

    assert(params != NULL);

    switch (msg_ptr->call_type) {
    case MAILBOX_PSA_FRAMEWORK_VERSION:
        psa_ret = tfm_rpc_psa_framework_version();
        sync = true;
        break;

    case MAILBOX_PSA_VERSION:
        psa_ret = tfm_rpc_psa_version(params->psa_version_params.sid);
        sync = true;
        break;

    case MAILBOX_PSA_CALL:
        ret = local_copy_vects(params, idx, &control);
        if (ret != MAILBOX_SUCCESS) {
            sync = true;
            psa_ret = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }

        if (tfm_multi_core_hal_client_id_translate(CLIENT_ID_OWNER_MAGIC,
                                                   msg_ptr->client_id,
                                                   &client_id) != SPM_SUCCESS) {
            sync = true;
            psa_ret = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }
        client_params.ns_client_id_stateless = client_id;
        client_params.p_invecs = vectors[idx].in_vec;
        client_params.p_outvecs = vectors[idx].out_vec;
        psa_ret = tfm_rpc_psa_call(params->psa_call_params.handle,
                                   control, &client_params, mb_msg_handle);
        if (psa_ret != PSA_SUCCESS) {
            sync = true;
        }
        break;

/* Following cases are only needed by connection-based services */
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
    case MAILBOX_PSA_CONNECT:
        if (tfm_multi_core_hal_client_id_translate(CLIENT_ID_OWNER_MAGIC,
                                                   msg_ptr->client_id,
                                                   &client_id) != SPM_SUCCESS) {
            sync = true;
            psa_ret = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }
        psa_ret = tfm_rpc_psa_connect(params->psa_connect_params.sid,
                                      params->psa_connect_params.version,
                                      client_id,
                                      mb_msg_handle);
        if (psa_ret != PSA_SUCCESS) {
            sync = true;
        }
        break;

    case MAILBOX_PSA_CLOSE:
        if (tfm_multi_core_hal_client_id_translate(CLIENT_ID_OWNER_MAGIC,
                                                   msg_ptr->client_id,
                                                   &client_id) != SPM_SUCCESS) {
            sync = true;
            psa_ret = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }
        psa_ret = tfm_rpc_psa_close(params->psa_close_params.handle, client_id);
        if (psa_ret != PSA_SUCCESS) {
            sync = true;
        }
        break;
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */

    default:
        return MAILBOX_INVAL_PARAMS;
    }

    /* Any synchronous result should be returned immediately */
    if (sync) {
        *reply_slots |= (1 << idx);
        mailbox_direct_reply(idx, (uint32_t)psa_ret);
    }

    return MAILBOX_SUCCESS;
}

int32_t tfm_mailbox_handle_msg(void)
{
    uint8_t idx;
    mailbox_queue_status_t mask_bits, pend_slots, reply_slots = 0;
    struct mailbox_status_t *ns_status = spe_mailbox_queue.ns_status;
    struct mailbox_msg_t *msg_ptr;
    uint32_t critical_section;
    int32_t status;
    int32_t msg_dispatched = 0;

    assert(ns_status != NULL);

    critical_section = tfm_mailbox_hal_enter_critical();

    pend_slots = get_nspe_queue_pend_status(ns_status);

    tfm_mailbox_hal_exit_critical(critical_section);

    /* Check if NSPE mailbox did assert a PSA client call request */
    if (!pend_slots) {
        return MAILBOX_NO_PEND_EVENT;
    }

    for (idx = 0; idx < spe_mailbox_queue.ns_slot_count; idx++) {
        mask_bits = (1 << idx);
        /* Check if current NSPE mailbox queue slot is pending for handling */
        if (!(pend_slots & mask_bits)) {
            continue;
        }

        /*
         * TODO
         * The operations are simplified here. Use the SPE mailbox queue
         * slot with the same idx as that of the NSPE mailbox queue slot.
         * A more general implementation should dynamically search and
         * select an empty SPE mailbox queue slot.
         */
        clear_spe_queue_empty_status(idx);
        spe_mailbox_queue.queue[idx].ns_slot_idx = idx;

        msg_ptr = &spe_mailbox_queue.queue[idx].msg;
        MAILBOX_INVALIDATE_CACHE(&spe_mailbox_queue.ns_slots[idx].msg, sizeof(*msg_ptr));
        spm_memcpy(msg_ptr, &spe_mailbox_queue.ns_slots[idx].msg, sizeof(*msg_ptr));

        if (check_mailbox_msg(msg_ptr) != MAILBOX_SUCCESS) {
            mailbox_clean_queue_slot(idx);
            continue;
        }

        get_spe_mailbox_msg_handle(idx,
                                   &spe_mailbox_queue.queue[idx].msg_handle);

        status = tfm_mailbox_dispatch(msg_ptr, idx, &reply_slots);
        if (status == MAILBOX_SUCCESS) {
            msg_dispatched++;
        } else {
            mailbox_clean_queue_slot(idx);
            continue;
        }
    }

    critical_section = tfm_mailbox_hal_enter_critical();

    /* Clean the NSPE mailbox pending status. */
    clear_nspe_queue_pend_status(ns_status, pend_slots);

    /* Set the NSPE mailbox replied status */
    set_nspe_queue_replied_status(ns_status, reply_slots);

    tfm_mailbox_hal_exit_critical(critical_section);

    if (reply_slots) {
        tfm_mailbox_hal_notify_peer();
    }

    return (int32_t)msg_dispatched;
}

int32_t tfm_mailbox_reply_msg(mailbox_msg_handle_t handle, int32_t reply)
{
    uint8_t idx;
    int32_t ret;
    uint32_t critical_section;
    struct mailbox_status_t *ns_status = spe_mailbox_queue.ns_status;

    assert(ns_status != NULL);

    /*
     * If handle == MAILBOX_MSG_NULL_HANDLE, reply to the mailbox message
     * in the first slot.
     * When multiple ongoing PSA client calls from NSPE are supported,
     * additional check might be necessary to avoid spoofing the first slot.
     */
    if (handle == MAILBOX_MSG_NULL_HANDLE) {
        idx = 0;
    } else {
        ret = get_spe_mailbox_msg_idx(handle, &idx);
        if (ret != MAILBOX_SUCCESS) {
            return ret;
        }
    }

    if (get_spe_queue_empty_status(idx)) {
        return MAILBOX_NO_PEND_EVENT;
    }

    mailbox_direct_reply(idx, (uint32_t)reply);

    critical_section = tfm_mailbox_hal_enter_critical();

    /* Set the NSPE mailbox replied status */
    set_nspe_queue_replied_status(ns_status, (1 << idx));

    tfm_mailbox_hal_exit_critical(critical_section);

    tfm_mailbox_hal_notify_peer();

    return MAILBOX_SUCCESS;
}

/* RPC handle_req() callback */
static void mailbox_handle_req(void)
{
    (void)tfm_mailbox_handle_msg();
}

/* RPC reply() callback */
static void mailbox_reply(const void *owner, int32_t ret)
{
    mailbox_msg_handle_t handle = MAILBOX_MSG_NULL_HANDLE;

    /* If the owner is specified */
    if (owner) {
        handle = *((mailbox_msg_handle_t *)owner);
    }

    (void)tfm_mailbox_reply_msg(handle, ret);
}

/* Process new mailbox message callback */
static int32_t mailbox_process_new_msg(uint32_t *nr_msg)
{
    int32_t status;

    status = tfm_mailbox_handle_msg();
    if (status < 0) {
        return status;
    } else {
        *nr_msg = (uint32_t)status;
        return MAILBOX_SUCCESS;
    }
}

/* Mailbox specific operations callback for TF-M RPC */
static const struct tfm_rpc_ops_t mailbox_rpc_ops = {
    .handle_req = mailbox_handle_req,
    .reply      = mailbox_reply,
    .process_new_msg = mailbox_process_new_msg,
};

static int32_t tfm_mailbox_init(void)
{
    int32_t ret;

    spm_memset(&spe_mailbox_queue, 0, sizeof(spe_mailbox_queue));

    spe_mailbox_queue.empty_slots =
            (mailbox_queue_status_t)((1UL << (NUM_MAILBOX_QUEUE_SLOT - 1)) - 1);
    spe_mailbox_queue.empty_slots +=
            (mailbox_queue_status_t)(1UL << (NUM_MAILBOX_QUEUE_SLOT - 1));

    /* Register RPC callbacks */
    ret = tfm_rpc_register_ops(&mailbox_rpc_ops);
    if (ret != TFM_RPC_SUCCESS) {
        return MAILBOX_CALLBACK_REG_ERROR;
    }

    /*
     * Platform specific initialization.
     * Initialize Inter-Processor Communication and achieve the base address of
     * NSPE mailbox queue
     */
    ret = tfm_mailbox_hal_init(&spe_mailbox_queue);
    if (ret != MAILBOX_SUCCESS) {
        tfm_rpc_unregister_ops();

        return ret;
    }

    return MAILBOX_SUCCESS;
}

int32_t tfm_inter_core_comm_init(void)
{
    return tfm_mailbox_init();
}

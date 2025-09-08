/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2021-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <assert.h>
#include "aapcs_local.h"
#include "async.h"
#include "config_spm.h"
#include "critical_section.h"
#include "compiler_ext_defs.h"
#include "config_spm.h"
#include "ffm/psa_api.h"
#include "fih.h"
#include "runtime_defs.h"
#include "stack_watermark.h"
#include "spm.h"
#include "tfm_hal_isolation.h"
#include "tfm_hal_platform.h"
#include "tfm_nspm.h"
#include "tfm_rpc.h"
#include "ffm/backend.h"
#include "utilities.h"
#include "memory_symbols.h"
#include "load/partition_defs.h"
#include "load/service_defs.h"
#include "load/spm_load_api.h"
#include "psa/error.h"
#include "internal_status_code.h"
#include "sprt_partition_metadata_indicator.h"

#if TFM_PARTITION_NS_AGENT_MAILBOX == 1
#include "psa_manifest/ns_agent_mailbox.h"
#endif

/* Declare the global component list */
struct partition_head_t partition_listhead;

#ifdef CONFIG_TFM_USE_TRUSTZONE
/* Instance for SPM_THREAD_CONTEXT */
struct context_ctrl_t *p_spm_thread_context;
#else
/* If ns_agent_tz isn't used, we need to provide a stack for SPM to use */
static uint8_t spm_thread_stack[CONFIG_TFM_SPM_THREAD_STACK_SIZE] __aligned(8);
ARCH_CLAIM_CTXCTRL_INSTANCE(spm_thread_context,
                            spm_thread_stack,
                            sizeof(spm_thread_stack));

struct context_ctrl_t *p_spm_thread_context = &spm_thread_context;
#endif

#if (CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1) && defined(CONFIG_TFM_USE_TRUSTZONE)
static bool basepri_set_by_ipc_schedule;
#endif

/*
 * Query the state of current thread.
 */
static uint32_t query_state(const struct thread_t *p_thrd, uint32_t *p_retval)
{
    struct critical_section_t cs_signal = CRITICAL_SECTION_STATIC_INIT;
    struct partition_t *p_pt = NULL;
    uint32_t state = p_thrd->state;
    psa_signal_t retval_signals = 0;

    /* Get current partition of thread. */
    p_pt = TO_CONTAINER(p_thrd->p_context_ctrl,
                        struct partition_t, ctx_ctrl);

    CRITICAL_SECTION_ENTER(cs_signal);

    retval_signals = p_pt->signals_waiting & p_pt->signals_asserted;

    if (retval_signals) {
        /*
         * Signal "ASYNC_MSG_REPLY" can only be waited in one of cases below:
         *
         *   - A FF-M Secure Partition is calling the Client API and
         *     expecting a replied "handle/status" from RoT Services.
         *     FF-M Secure Partitions cannot use 'psa_wait' to wait
         *     on this signal because the signal is not set in FF-M
         *     Secure Partitions' "signals_allowed".
         *
         *   - A Mailbox NS Agent is calling "psa_wait" with a pattern
         *     containing "ASYNC_MSG_REPLY". The signal is set in
         *     Mailbox NS Agents' "signals_allowed".
         *
         * Here uses "signals_allowed" to check if the calling target is a
         * FF-M Secure Partition or a Mailbox NS Agent.
         */
        if ((retval_signals ==  ASYNC_MSG_REPLY) &&
            ((p_pt->signals_allowed & ASYNC_MSG_REPLY) != ASYNC_MSG_REPLY)) {
            p_pt->signals_asserted &= ~ASYNC_MSG_REPLY;

#ifndef NDEBUG
            assert(p_pt->p_replied->status < TFM_HANDLE_STATUS_MAX);
#endif

            /*
             * For FF-M Secure Partition, the reply is synchronous and only one
             * replied handle node should be mounted. Take the reply value from
             * the node and delete it then.
             */
            *p_retval = (uint32_t)p_pt->p_replied->replied_value;
            if (p_pt->p_replied->status == TFM_HANDLE_STATUS_TO_FREE) {
                spm_free_connection(p_pt->p_replied);
            }
            p_pt->p_replied = NULL;
        } else {
            *p_retval = retval_signals;
        }

        /* Clear 'signals_waiting' to indicate the component is not waiting. */
        p_pt->signals_waiting = 0;
        state = THRD_STATE_RET_VAL_AVAIL;
    } else if (p_pt->signals_waiting != 0) {
        /*
         * If the thread is waiting some signals but none of them is asserted,
         * block the thread.
         */
        state = THRD_STATE_BLOCK;
    }

    CRITICAL_SECTION_LEAVE(cs_signal);
    return state;
}

extern struct psa_api_tbl_t psa_api_thread_fn_call;
extern struct psa_api_tbl_t psa_api_svc;

static void prv_process_metadata(struct partition_t *p_pt)
{
    const struct partition_load_info_t *p_pt_ldi;
    const struct service_load_info_t *p_srv_ldi;
    struct context_ctrl_t *ctx_ctrl;
    struct runtime_metadata_t *p_rt_meta;
    service_fn_t *p_sfn_table;
    uint32_t allocate_size;
#if TFM_ISOLATION_LEVEL != 1
    FIH_RET_TYPE(bool) fih_rc;
#endif

    p_pt_ldi = p_pt->p_ldinf;
    p_srv_ldi = LOAD_INFO_SERVICE(p_pt_ldi);
    ctx_ctrl = &p_pt->ctx_ctrl;

    /* common runtime metadata */
    allocate_size = sizeof(*p_rt_meta);

    if (!IS_IPC_MODEL(p_pt_ldi)) {
        /* SFN specific metadata - SFN function table */
        allocate_size += sizeof(service_fn_t) * p_pt_ldi->nservices;
    }

    ARCH_CTXCTRL_ALLOCATE_STACK(ctx_ctrl, allocate_size);
    p_rt_meta = (struct runtime_metadata_t *)
                                    ARCH_CTXCTRL_ALLOCATED_PTR(ctx_ctrl);

#if TFM_ISOLATION_LEVEL == 1
    p_rt_meta->psa_fns = &psa_api_thread_fn_call;
#else
    FIH_CALL(tfm_hal_boundary_need_switch, fih_rc, get_spm_boundary(), p_pt->boundary);
    if (FIH_NOT_EQ(fih_rc, false)) {
        p_rt_meta->psa_fns = &psa_api_svc;
    } else {
        p_rt_meta->psa_fns = &psa_api_thread_fn_call;
    }
#endif

    p_rt_meta->entry = p_pt_ldi->entry;
    p_rt_meta->n_sfn = 0;
    p_sfn_table = p_rt_meta->sfn_table;

    if (!IS_IPC_MODEL(p_pt_ldi)) {
        /* SFN table. The signal bit of the service is the same index of SFN. */
        for (int i = 0; i < p_pt_ldi->nservices; i++) {
            p_sfn_table[i] = (service_fn_t)p_srv_ldi[i].sfn;
        }

        p_rt_meta->n_sfn = p_pt_ldi->nservices;
    }

    p_pt->p_metadata = p_rt_meta;
}

/*
 * Send message and wake up the SP who is waiting on message queue, block the
 * current thread and trigger scheduler.
 */
psa_status_t backend_messaging(struct connection_t *p_connection)
{
    struct partition_t *p_owner = NULL;
    psa_signal_t signal = 0;
    psa_status_t ret = PSA_SUCCESS;

    if (!p_connection || !p_connection->service ||
        !p_connection->service->p_ldinf         ||
        !p_connection->service->partition) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    p_owner = p_connection->service->partition;
    signal = p_connection->service->p_ldinf->signal;

    UNI_LIST_INSERT_AFTER(p_owner, p_connection, p_reqs);

    /* Messages put. Update signals */
    ret = backend_assert_signal(p_owner, signal);

    /*
     * If it is a request from NS Mailbox Agent, it is NOT necessary to block
     * the current thread.
     */
    if (IS_NS_AGENT_MAILBOX(p_connection->p_client->p_ldinf)) {
        ret = PSA_SUCCESS;
    } else {
        signal = backend_wait_signals(p_connection->p_client, ASYNC_MSG_REPLY);
        if (signal == (psa_signal_t)0) {
            ret = STATUS_NEED_SCHEDULE;
        }
    }

    return ret;
}

psa_status_t backend_replying(struct connection_t *handle, int32_t status)
{
    struct partition_t *client = handle->p_client;

    /* Prepare the replied handle. */
    handle->replied_value = (uintptr_t)status;

    /* Mount the replied handle. There are two mode for replying.
     *
     *  - For synchronous reply, only one node is mounted.
     *  - For asynchronous reply, the first moundted is at the tail of the list
     *    and will be first replied.
     *    - Currently, this is used for mailbox multi-core technology.
     */
    UNI_LIST_INSERT_AFTER(client, handle, p_replied);

    return backend_assert_signal(handle->p_client, ASYNC_MSG_REPLY);
}

extern void common_sfn_thread(void *param);

static thrd_fn_t partition_init(struct partition_t *p_pt,
                                uint32_t service_setting, uint32_t *param)
{
    thrd_fn_t thrd_entry;

    (void)param;
    assert(p_pt);

#if CONFIG_TFM_DOORBELL_API == 1
    p_pt->signals_allowed |= PSA_DOORBELL;
#endif /* CONFIG_TFM_DOORBELL_API == 1 */

    p_pt->signals_allowed |= service_setting;

    /* Allow 'ASYNC_MSG_REPLY' for Mailbox NS Agent. */
    if (IS_NS_AGENT_MAILBOX(p_pt->p_ldinf)) {
        p_pt->signals_allowed |= ASYNC_MSG_REPLY;
    }

    UNI_LIST_INIT_NODE(p_pt, p_reqs);
    UNI_LIST_INIT_NODE(p_pt, p_replied);

    if (IS_IPC_MODEL(p_pt->p_ldinf)) {
        /* IPC Partition */
        thrd_entry = POSITION_TO_ENTRY(p_pt->p_ldinf->entry, thrd_fn_t);
    } else {
        /* SFN Partition */
        thrd_entry = (thrd_fn_t)common_sfn_thread;
    }
    return thrd_entry;
}

#ifdef CONFIG_TFM_USE_TRUSTZONE
static thrd_fn_t ns_agent_tz_init(struct partition_t *p_pt,
                                  uint32_t service_setting, uint32_t *param)
{
    thrd_fn_t thrd_entry;

    (void)service_setting;
    assert(p_pt);
    assert(param);

    tz_ns_agent_register_client_id_range(p_pt->p_ldinf->client_id_base,
                                         p_pt->p_ldinf->client_id_limit);

    /* Get the context from ns_agent_tz */
    SPM_THREAD_CONTEXT = &p_pt->ctx_ctrl;

    thrd_entry = POSITION_TO_ENTRY(p_pt->p_ldinf->entry, thrd_fn_t);

    /* NS agent TZ expects NSPE entry point as the parameter */
    *param = tfm_hal_get_ns_entry_point();
    return thrd_entry;
}
#else
static thrd_fn_t ns_agent_tz_init(struct partition_t *p_pt,
                                  uint32_t service_setting, uint32_t *param)
{
    (void)p_pt;
    (void)service_setting;
    (void)param;

    return POSITION_TO_ENTRY(NULL, thrd_fn_t);
}
#endif

typedef thrd_fn_t (*comp_init_fn_t)(struct partition_t *, uint32_t, uint32_t *);
static const comp_init_fn_t comp_init_fns[] = {
    partition_init,
    ns_agent_tz_init,
};

/* Parameters are treated as assuredly */
void backend_init_comp_assuredly(struct partition_t *p_pt, uint32_t service_setting)
{
    const struct partition_load_info_t *p_pldi = p_pt->p_ldinf;
    thrd_fn_t thrd_entry;
    uint32_t param;
    int32_t index = PARTITION_TYPE_TO_INDEX(p_pldi->flags);

    ARCH_CTXCTRL_INIT(&p_pt->ctx_ctrl,
                      LOAD_ALLOCED_STACK_ADDR(p_pldi),
                      p_pldi->stack_size);

    watermark_stack(p_pt);

    /*
     * Use Secure Partition loading order as the initial priority of scheduling
     * in IPC backend.
     */
    THRD_INIT(&p_pt->thrd, &p_pt->ctx_ctrl, p_pldi->load_order);

    thrd_entry = (comp_init_fns[index])(p_pt, service_setting, &param);

    prv_process_metadata(p_pt);

    thrd_start(&p_pt->thrd, thrd_entry, THRD_GENERAL_EXIT, (void *)param);
}

uint32_t backend_system_run(void)
{
    uint32_t control;
    const struct partition_t *p_cur_pt;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    assert(SPM_THREAD_CONTEXT);

#ifndef CONFIG_TFM_USE_TRUSTZONE
    /*
     * TZ NS Agent is mandatory when Trustzone is enabled. SPM borrows its
     * stack to improve the stack usage efficiency.
     * Hence SPM needs to have a dedicated stack when Trustzone is not enabled,
     * and this stack needs to be sealed before upcoming usage.
     */
    watermark_spm_stack();
    ARCH_CTXCTRL_ALLOCATE_STACK(SPM_THREAD_CONTEXT, sizeof(uint64_t));
    arch_seal_thread_stack(ARCH_CTXCTRL_ALLOCATED_PTR(SPM_THREAD_CONTEXT));
#endif

    /* Init thread callback function. */
    thrd_set_query_callback(query_state);

    control = thrd_start_scheduler(&CURRENT_THREAD);

    p_cur_pt = TO_CONTAINER(CURRENT_THREAD->p_context_ctrl,
                            struct partition_t, ctx_ctrl);

    FIH_CALL(tfm_hal_activate_boundary, fih_rc, p_cur_pt->p_ldinf, p_cur_pt->boundary);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        tfm_core_panic();
    }

    return control;
}

psa_signal_t backend_wait_signals(struct partition_t *p_pt, psa_signal_t signals)
{
    struct critical_section_t cs_signal = CRITICAL_SECTION_STATIC_INIT;
    psa_signal_t ret;

    if (!p_pt) {
        tfm_core_panic();
    }

    CRITICAL_SECTION_ENTER(cs_signal);

    ret = p_pt->signals_asserted & signals;
    if (ret == (psa_signal_t)0) {
        p_pt->signals_waiting = signals;
    }

    CRITICAL_SECTION_LEAVE(cs_signal);

    return ret;
}

#if (CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE == TFM_HYBRID_PLAT_SCHED_NSPE)
static void backend_assert_hybridplat_signal(
    struct partition_t *p_pt, psa_signal_t signal)
{
    const struct irq_load_info_t *irq_info;
    uint32_t irq_info_idx;
    uint32_t nirqs;

    if (IS_NS_AGENT_MAILBOX(p_pt->p_ldinf)) {
        nirqs = p_pt->p_ldinf->nirqs;
        irq_info = LOAD_INFO_IRQ(p_pt->p_ldinf);
        for (irq_info_idx = 0; irq_info_idx < nirqs; irq_info_idx++) {
            if (irq_info == NULL) {
                tfm_core_panic();
            }
            if (irq_info[irq_info_idx].signal == signal) {
                break;
            }
        }

        if (irq_info_idx < nirqs) {
            /*
             * The incoming signal is found in the irq_load_info_t,
             * do not assert the signal now.
             * NSPE will drive the processing for this request via the mailbox
             * dedicated auxiliary service.
             */
            return;
        }
    }

    p_pt->signals_asserted |= signal;
}
#endif

psa_status_t backend_assert_signal(struct partition_t *p_pt, psa_signal_t signal)
{
    struct critical_section_t cs_signal = CRITICAL_SECTION_STATIC_INIT;
    psa_status_t ret = PSA_SUCCESS;

    if (!p_pt) {
        tfm_core_panic();
    }

    CRITICAL_SECTION_ENTER(cs_signal);

#if (CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE == TFM_HYBRID_PLAT_SCHED_NSPE)
    backend_assert_hybridplat_signal(p_pt, signal);
#else
    p_pt->signals_asserted |= signal;
#endif

    if (p_pt->signals_asserted & p_pt->signals_waiting) {
        ret = STATUS_NEED_SCHEDULE;
    }
    CRITICAL_SECTION_LEAVE(cs_signal);

    return ret;
}

uint64_t backend_abi_entering_spm(void)
{
    struct partition_t *caller = GET_CURRENT_COMPONENT();
    uint32_t sp = 0;
    uint32_t sp_limit = 0;
    AAPCS_DUAL_U32_T spm_stack_info;

#if TFM_ISOLATION_LEVEL == 1
    /* PSA APIs must be called from Thread mode */
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        tfm_core_panic();
    }
#endif

    /*
     * Check if caller stack is within SPM stack. If not, then stack needs to
     * switch. Otherwise, return zeros.
     */
    if ((caller->ctx_ctrl.sp <= SPM_THREAD_CONTEXT->sp_limit) ||
        (caller->ctx_ctrl.sp >  SPM_THREAD_CONTEXT->sp_base)) {
        sp       = SPM_THREAD_CONTEXT->sp;
        sp_limit = SPM_THREAD_CONTEXT->sp_limit;
    }

    AAPCS_DUAL_U32_SET(spm_stack_info, sp, sp_limit);

    arch_acquire_sched_lock();

    return AAPCS_DUAL_U32_AS_U64(spm_stack_info);
}

uint32_t backend_abi_leaving_spm(uint32_t result)
{
    uint32_t sched_attempted;

    spm_handle_programmer_errors(result);

    /* Release scheduler lock and check the record of schedule attempt. */
    sched_attempted = arch_release_sched_lock();

    /* Interrupt is masked, PendSV will not happen immediately. */
    if (((psa_status_t)result == STATUS_NEED_SCHEDULE) ||
        (sched_attempted == SCHEDULER_ATTEMPTED)) {
        arch_attempt_schedule();
    }

    return result;
}

uint64_t ipc_schedule(uint32_t exc_return)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    FIH_RET_TYPE(bool) fih_bool;
    AAPCS_DUAL_U32_T ctx_ctrls;
    const struct partition_t *p_part_curr;
    struct partition_t *p_part_next;
    struct context_ctrl_t *p_curr_ctx;
    struct thread_t *pth_next;
    struct critical_section_t cs = CRITICAL_SECTION_STATIC_INIT;

    /* Protect concurrent access to current thread/component and thread status */
    CRITICAL_SECTION_ENTER(cs);

#if (CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1) && defined(CONFIG_TFM_USE_TRUSTZONE)
    if (__get_BASEPRI() == 0) {
        /*
         * If BASEPRI is not set, that means an interrupt was taken when
         * Non-Secure code was executing, and a scheduling is necessary because
         * a secure partition become runnable.
         */
        assert(!basepri_set_by_ipc_schedule);
        basepri_set_by_ipc_schedule = true;
        __set_BASEPRI(SECURE_THREAD_EXECUTION_PRIORITY);
    }
#endif

    p_curr_ctx = CURRENT_THREAD->p_context_ctrl;

    /*
     * Update SP for current thread, in case tfm_arch_set_context_ret_code have to update R0
     * in the current thread's saved context.
     */
    p_curr_ctx->sp = __get_PSP() -
        (is_default_stacking_rules_apply(exc_return) ?
            sizeof(struct tfm_additional_context_t) : 0) -
            TFM_FPU_CONTEXT_SIZE;

    pth_next = thrd_next();

    AAPCS_DUAL_U32_SET(ctx_ctrls, (uint32_t)p_curr_ctx, (uint32_t)p_curr_ctx);

    p_part_curr = GET_CURRENT_COMPONENT();
    p_part_next = GET_THRD_OWNER(pth_next);

    if ((pth_next != NULL) && (p_part_curr != p_part_next)) {
        /* Check if there is enough room on stack to save more context */
        if ((p_curr_ctx->sp_limit + TFM_FPU_CONTEXT_SIZE +
                sizeof(struct tfm_additional_context_t)) > __get_PSP()) {
            tfm_core_panic();
        }

        /*
         * If required, let the platform update boundary based on its
         * implementation. Change privilege, MPU or other configurations.
         */
        FIH_CALL(tfm_hal_boundary_need_switch, fih_bool,
                 p_part_curr->boundary, p_part_next->boundary);
        if (FIH_NOT_EQ(fih_bool, false)) {
            FIH_CALL(tfm_hal_activate_boundary, fih_rc,
                     p_part_next->p_ldinf, p_part_next->boundary);
            if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
                tfm_core_panic();
            }
        }
        ARCH_FLUSH_FP_CONTEXT();

#if (CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1) && defined(CONFIG_TFM_USE_TRUSTZONE)
        if (IS_NS_AGENT_TZ(p_part_next->p_ldinf)) {
            /*
             * The Non-Secure Agent for TrustZone is going to be scheduled.
             * A secure partition was scheduled previously, so BASEPRI must be
             * set to non-zero. However BASEPRI only needs to be reset to 0 if
             * Non-Secure code execution was interrupted (and not got to secure
             * execution through a veneer call. Veneers set and unset BASEPRI on
             * enter and exit). In this case basepri_set_by_ipc_schedule is set,
             * so it can be used in the condition.
             */
            assert(__get_BASEPRI() == SECURE_THREAD_EXECUTION_PRIORITY);
            if (basepri_set_by_ipc_schedule) {
                basepri_set_by_ipc_schedule = false;
                __set_BASEPRI(0);
            }
        }
#endif

        AAPCS_DUAL_U32_SET_A1(ctx_ctrls, (uint32_t)pth_next->p_context_ctrl);

        CURRENT_THREAD = pth_next;
    }

    /* Update meta indicator */
    if (p_part_next->p_metadata == NULL) {
        tfm_core_panic();
    }
    p_partition_metadata = (uintptr_t)(p_part_next->p_metadata);

    /*
     * ctx_ctrl is set from struct thread_t's p_context_ctrl, and p_part_curr
     * and p_part_next are calculated from the thread pointer.
     * struct partition_t's ctx_ctrl is pointed to by struct thread_t's p_context_ctrl,
     * but the optimiser doesn't know that when building this code.
     * Use that information to check that the context, thread, and partition
     * are all consistent
     */
    if (ctx_ctrls.u32_regs.r0 != (uint32_t)&p_part_curr->ctx_ctrl) {
        tfm_core_panic();
    }

    if (ctx_ctrls.u32_regs.r1 != (uint32_t)&p_part_next->ctx_ctrl) {
        tfm_core_panic();
    }

    if (&p_part_next->thrd != CURRENT_THREAD) {
        tfm_core_panic();
    }

    /* also double-check the metadata */
    if ((uintptr_t)GET_CTX_OWNER(ctx_ctrls.u32_regs.r1)->p_metadata != p_partition_metadata) {
        tfm_core_panic();
    }

    CRITICAL_SECTION_LEAVE(cs);

    return AAPCS_DUAL_U32_AS_U64(ctx_ctrls);
}

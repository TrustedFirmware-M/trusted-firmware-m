/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "interrupt.h"

#include "bitops.h"
#include "current.h"
#include "fih.h"
#include "svc_num.h"
#include "tfm_arch.h"
#include "tfm_hal_interrupt.h"
#include "tfm_hal_isolation.h"
#include "tfm_svcalls.h"
#include "thread.h"
#include "utilities.h"
#include "load/spm_load_api.h"
#include "ffm/backend.h"
#include "internal_status_code.h"

#if TFM_ISOLATION_LEVEL != 1
extern void tfm_flih_func_return(psa_flih_result_t result);

__attribute__((naked))
static psa_flih_result_t tfm_flih_deprivileged_handling(struct partition_t *p_pt,
                                                        uintptr_t fn_flih,
                                                        void *curr_component)
{
    __ASM volatile("SVC "M2S(TFM_SVC_PREPARE_DEPRIV_FLIH)"           \n"
                   "BX LR                                            \n"
                   );
}

uint32_t tfm_flih_prepare_depriv_flih(struct partition_t *p_owner_sp,
                                      uintptr_t flih_func)
{
    const struct partition_t *p_curr_sp;
    uintptr_t sp_base, sp_limit, curr_stack, ctx_stack;
    struct context_ctrl_t flih_ctx_ctrl;
    fih_int fih_rc = FIH_FAILURE;
    FIH_RET_TYPE(bool) fih_bool;

    /* Come too early before runtime setup, should not happen. */
    if (!CURRENT_THREAD) {
        tfm_core_panic();
    }

    p_curr_sp = GET_CURRENT_COMPONENT();
    sp_base  = LOAD_ALLOCED_STACK_ADDR(p_owner_sp->p_ldinf)
                                              + p_owner_sp->p_ldinf->stack_size;
    sp_limit = LOAD_ALLOCED_STACK_ADDR(p_owner_sp->p_ldinf);

    curr_stack = (uintptr_t)__get_PSP();
    if (curr_stack < sp_base && curr_stack > sp_limit) {
        /* The IRQ Partition's stack is being used */
        ctx_stack = curr_stack;
    } else {
        ctx_stack = p_owner_sp->thrd.p_context_ctrl->sp;
    }

    FIH_CALL(tfm_hal_boundary_need_switch, fih_bool,
             p_curr_sp->boundary, p_owner_sp->boundary);
    if (fih_not_eq(fih_bool, fih_int_encode(false))) {
        /*
         * FPU lazy stacking context preservation uses privilege and relative priorities
         * recorded during original stacking. Thus it's important to flush FP context
         * before boundary is changed for a new partition.
         */
        ARCH_FLUSH_FP_CONTEXT();

        FIH_CALL(tfm_hal_activate_boundary, fih_rc,
                 p_owner_sp->p_ldinf, p_owner_sp->boundary);
        if (fih_not_eq(fih_rc, fih_int_encode(TFM_HAL_SUCCESS))) {
            tfm_core_panic();
        }
    }

    /*
     * The CURRENT_COMPONENT has been stored on MSP by the SVC call, safe to
     * update it.
     */
    SET_CURRENT_COMPONENT(p_owner_sp);

    flih_ctx_ctrl.sp_limit = sp_limit;
    flih_ctx_ctrl.sp       = ctx_stack;

    tfm_arch_init_context(&flih_ctx_ctrl,
                          flih_func, NULL,
                          (uintptr_t)tfm_flih_func_return);

    (void)tfm_arch_refresh_hardware_context(&flih_ctx_ctrl);

    return flih_ctx_ctrl.exc_ret;
}

/* Go back to ISR from FLIH functions */
uint32_t tfm_flih_return_to_isr(psa_flih_result_t result,
                                struct context_flih_ret_t *p_ctx_flih_ret)
{
    const struct partition_t *p_owner_sp;
    struct partition_t *p_prev_sp;
    FIH_RET_TYPE(bool) fih_bool;
    fih_int fih_rc = FIH_FAILURE;

    p_prev_sp = (struct partition_t *)(p_ctx_flih_ret->state_ctx.r2);
    p_owner_sp = GET_CURRENT_COMPONENT();

    FIH_CALL(tfm_hal_boundary_need_switch, fih_bool,
             p_owner_sp->boundary, p_prev_sp->boundary);
    if (fih_not_eq(fih_bool, fih_int_encode(false))) {
        /*
         * FPU lazy stacking context preservation uses privilege and relative priorities
         * recorded during original stacking. Thus it's important to flush FP context
         * before boundary is changed for a new partition.
         */
        ARCH_FLUSH_FP_CONTEXT();

        FIH_CALL(tfm_hal_activate_boundary, fih_rc,
                 p_prev_sp->p_ldinf, p_prev_sp->boundary);
        if (fih_not_eq(fih_rc, fih_int_encode(TFM_HAL_SUCCESS))) {
            tfm_core_panic();
        }
    }

    /*
     * If the interrupted Thread mode context was running SPM code, then
     * Privileged thread mode needs to be restored.
     */
    if (tfm_svc_thread_mode_spm_active()) {
        __set_CONTROL_nPRIV(0);
    }

    /* Restore current component */
    SET_CURRENT_COMPONENT(p_prev_sp);

    arch_update_process_sp(p_ctx_flih_ret->psp, p_ctx_flih_ret->psplim);

    /* Set FLIH result to the ISR */
    p_ctx_flih_ret->state_ctx.r0 = (uint32_t)result;

    return p_ctx_flih_ret->exc_return;
}
#endif

const struct irq_load_info_t *get_irq_info_for_signal(
                                    const struct partition_load_info_t *p_ldinf,
                                    psa_signal_t signal)
{
    size_t i;
    const struct irq_load_info_t *irq_info;

    if (!IS_ONLY_ONE_BIT_IN_UINT32(signal)) {
        return NULL;
    }

    irq_info = LOAD_INFO_IRQ(p_ldinf);
    for (i = 0; i < p_ldinf->nirqs; i++) {
        if (irq_info[i].signal == signal) {
            return &irq_info[i];
        }
    }

    return NULL;
}

void spm_handle_interrupt(struct partition_t *p_pt,
                          const struct irq_load_info_t *p_ildi)
{
    psa_flih_result_t flih_result;
    psa_status_t ret;
    FIH_RET_TYPE(bool) fih_bool;

    if (!p_pt || !p_ildi) {
        tfm_core_panic();
    }

    if (p_ildi->pid != p_pt->p_ldinf->pid) {
        tfm_core_panic();
    }

    if (p_ildi->flih_func == NULL) {
        /* SLIH Model Handling */
        tfm_hal_irq_disable(p_ildi->source);
        flih_result = PSA_FLIH_SIGNAL;
    } else {
        /* FLIH Model Handling */
#if TFM_ISOLATION_LEVEL == 1
        flih_result = p_ildi->flih_func();
        (void)fih_bool;
#else
        FIH_CALL(tfm_hal_boundary_need_switch, fih_bool,
                 get_spm_boundary(), p_pt->boundary);
        if (fih_eq(fih_bool, fih_int_encode(false))) {
            flih_result = p_ildi->flih_func();
        } else {
            flih_result = tfm_flih_deprivileged_handling(
                                                p_pt,
                                                (uintptr_t)p_ildi->flih_func,
                                                GET_CURRENT_COMPONENT());
        }
#endif
    }

    if (flih_result == PSA_FLIH_SIGNAL) {
        ret = backend_assert_signal(p_pt, p_ildi->signal);
        /* In SFN backend, there is only one thread, no thread switch. */
#if CONFIG_TFM_SPM_BACKEND_SFN != 1
        if (ret == STATUS_NEED_SCHEDULE) {
            arch_attempt_schedule();
        }
#else
        (void)ret;
#endif
    }
}

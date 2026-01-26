/*
 * Copyright (c) 2018-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "security_defs.h"
#include "tfm_arch.h"
#include "tfm_core_trustzone.h"
#include "utilities.h"
#include "config_impl.h"
#include "coverity_check.h"

#include "compiler_ext_defs.h" /* Keep last. */

#if defined(__ICCARM__) && (CONFIG_TFM_FLOAT_ABI >= 1)
#pragma required = tfm_arch_clear_fp_data
#endif

__naked void tfm_arch_free_msp_and_exc_ret(uint32_t msp_base,
                                           uint32_t exc_return)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "mov     r4, r0                         \n"
        "mov     r5, r1                         \n"
#if (CONFIG_TFM_FLOAT_ABI > 0)
        "bl      tfm_arch_clear_fp_data         \n"
#endif
        "mov     sp, r4                         \n"
        "bx      r5                             \n"
    );
}
#if CONFIG_TFM_SPM_BACKEND_IPC == 1

extern uint32_t scheduler_lock;

void tfm_arch_set_context_ret_code(const struct context_ctrl_t *p_ctx_ctrl, uint32_t ret_code)
{
    /* Write the return value to the state context on stack. */
    ((struct full_context_t *)p_ctx_ctrl->sp)->stat_ctx.r0 = ret_code;
}

__naked void arch_acquire_sched_lock(void)
{
    __asm volatile(
        SYNTAX_UNIFIED
        "   ldr    r0, =scheduler_lock                 \n"
        "   movs   r1, #"M2S(SCHEDULER_LOCKED)"        \n"
        "   str    r1, [r0, #0]                        \n"
        "   dsb    #0xf                                \n"
        "   bx     lr                                  \n"
    );
}

__naked uint32_t arch_release_sched_lock(void)
{
    __asm volatile(
        SYNTAX_UNIFIED
        "ldr    r1, =scheduler_lock                    \n"
        "ldr    r0, [r1, #0]                           \n"
        "movs   r2, #"M2S(SCHEDULER_UNLOCKED)"         \n"/* Unlock scheduler */
        "str    r2, [r1, #0]                           \n"
        "dsb    #0xf                                   \n"
        "bx     lr                                     \n"
    );
}

/*
 * Try to trigger scheduler by setting PendSV if the scheduler is not locked.
 * Otherwise, record the attempt. The scheduler is locked when SPM is performing
 * context-related operations that can't be disturbed. The lock is managed by
 * lock/unlock interfaces with a public variable.
 *
 * When this function is returning to the caller, a scheduling event might have
 * performed and 'R0' may contain significant return values for the caller.
 * Keep a 'uint32_t' always in case the caller is expecting a return value.
 *
 * Caution: This is an API for core usage, do not call it out of SPM.
 */
__naked uint32_t arch_attempt_schedule(void)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "ldr     r0, =scheduler_lock                   \n"
        "ldr     r2, [r0, #0]                          \n"
        "cmp     r2, #"M2S(SCHEDULER_UNLOCKED)"        \n"
        /* Skip PendSV if scheduler is locked and mark scheduling attempted. */
        "bne     mark_schedule_attempted_and_exit      \n"
        "ldr     r0, ="M2S(SCB_ICSR_ADDR)"             \n"
        "ldr     r1, ="M2S(SCB_ICSR_PENDSVSET_BIT)"    \n"
        "str     r1, [r0, #0]                          \n"
        "dsb     #0xf                                  \n"
        "isb                                           \n"
        "bx      lr                                    \n"
    "mark_schedule_attempted_and_exit:                 \n"
        "movs    r2, #"M2S(SCHEDULER_ATTEMPTED)"       \n"
        "str     r2, [r0, #0]                          \n"
        "dsb     #0xf                                  \n"
        "bx      lr                                    \n"
    );
}
#endif

#if CONFIG_TFM_SPM_BACKEND_SFN == 1
__naked void arch_clean_stack_and_launch(void *param, uintptr_t spm_init_func,
                                         uintptr_t ns_agent_entry, uint32_t msp_base)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "msr  msp, r3                       \n" /* Reset MSP */
        "mov  lr, r2                        \n" /*
                                                 * Set lr - the return address of the first
                                                 * init function (r1) - to the second init
                                                 * function (r2) so that they will be executed
                                                 * in turn. The return value of first init
                                                 * function is passed to second init function
                                                 * through "r0".
                                                 */
        "movs r2, #"M2S(CONTROL_SPSEL_Msk)" \n"
        "mrs  r3, control                   \n"
        "orrs r3, r3, r2                    \n" /*
                                                 * CONTROL.SPSEL, bit [1], stack-pointer
                                                 * select.
                                                 * 0: Use SP_main as the current stack.
                                                 * 1: In Thread mode use PSP as the
                                                 * current stack
                                                 */
        "msr  control, r3                   \n" /* Use PSP as the current stack */
        "isb                                \n"
        "bx   r1                            \n" /* Execute first init function */
    );
}
#endif

void tfm_arch_init_context(struct context_ctrl_t *p_ctx_ctrl,
                           uintptr_t pfn, void *param, uintptr_t pfnlr)
{
    uintptr_t sp = p_ctx_ctrl->sp;
    uintptr_t sp_limit = p_ctx_ctrl->sp_limit;
    struct full_context_t *p_tctx =
            (struct full_context_t *)arch_seal_thread_stack(sp);

    /* Check if enough space on stack */
    if (((uintptr_t)p_tctx - sizeof(struct full_context_t)) < sp_limit) {
        tfm_core_panic();
    }

    /* Reserve a full context (state context + additional context) on the stack. */

    /*
     * Although a full context is reserved from the stack, the additional context within it is not
     * needed to be popped out when doing exception return. They are reserved for the scheduler
     * usage which requires full contexts.
     * So the DCRS bit of EXC_RETURN payload is set to "1" in later code, which means default rule
     * (no additional context) is followed.
     * The tfm_arch_refresh_hardware_context() must set the PSP to the state context within the
     * full context pointer rather than the full context pointer itself.
     */
    p_tctx--;

    spm_memset(p_tctx, 0, sizeof(*p_tctx));

    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_6, "Intentional pointer cast")
    ARCH_CTXCTRL_EXCRET_PATTERN(&p_tctx->stat_ctx, param, 0, 0, 0, pfn, pfnlr);

    p_ctx_ctrl->exc_ret  = EXC_RETURN_THREAD_PSP;
    p_ctx_ctrl->sp       = (uintptr_t)p_tctx;
}

uint32_t tfm_arch_refresh_hardware_context(const struct context_ctrl_t *p_ctx_ctrl)
{
    struct tfm_state_context_t *sc;

    sc = &(((struct full_context_t *)(p_ctx_ctrl->sp))->stat_ctx);

    arch_update_process_sp((uint32_t)sc, p_ctx_ctrl->sp_limit);

    return p_ctx_ctrl->exc_ret;
}

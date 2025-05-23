/*
 * Copyright (c) 2018-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <inttypes.h>
#include "compiler_ext_defs.h"
#include "config_spm.h"
#include "security_defs.h"
#include "spm.h"
#include "svc_num.h"
#include "tfm_hal_device_header.h"
#include "tfm_arch.h"
#include "tfm_svcalls.h"
#include "utilities.h"

#if !defined(__ARM_ARCH_8M_BASE__)
#error "Unsupported ARM Architecture."
#endif

/* Delcaraction flag to control the scheduling logic in PendSV. */
uint32_t scheduler_lock = SCHEDULER_UNLOCKED;

/* IAR Specific */
#if defined(__ICCARM__)

#pragma required = scheduler_lock
#pragma required = spm_svc_handler

#if CONFIG_TFM_SPM_BACKEND_IPC == 1

#pragma required = ipc_schedule
#pragma required = backend_abi_entering_spm
#pragma required = backend_abi_leaving_spm

#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1 */

#endif

#if CONFIG_TFM_SPM_BACKEND_IPC == 1

__naked
void tfm_arch_thread_fn_call(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    __asm volatile(
        SYNTAX_UNIFIED
        "   push   {r5-r7, lr}              \n"
        "   mov    r5, r12                  \n"
        "   push   {r0-r5}                  \n"
        "   cpsid  i                        \n"
        "   isb                             \n"
        "   bl     backend_abi_entering_spm \n" /* r0: new SP, r1: new PSPLIM */
        "   mrs    r6, psplim               \n"
        "   mov    r7, sp                   \n"
        "   cmp    r0, #0                   \n" /* Check whether the caller is
                                                 * NS agent(new SP == 0) or
                                                 * secure partition(new SP != 0)
                                                 */
        "   beq    v8b_branch_to_target     \n"
        "   movs   r2, #0                   \n"
        "   msr    psplim, r2               \n" /* Clear PSPLIM before setting
                                                 * PSP to a new value. This can
                                                 * avoid potential stack
                                                 * overflow.
                                                 */
        "   mov    sp, r0                   \n" /* Switch to the SPM stack if
                                                 * caller is NOT NS agent.
                                                 */
        "   msr    psplim, r1               \n"
        "v8b_branch_to_target:              \n"
        "   cpsie  i                        \n"
        "   isb                             \n"
        "   ldmia  r7!, {r0-r5}             \n" /* Load PSA interface input args
                                                 * and target function
                                                 */
        "   blx    r5                       \n"
        "   cpsid  i                        \n"
        "   isb                             \n"
        "   bl     backend_abi_leaving_spm  \n"
        "   movs   r2, #0                   \n" /* Back to caller new stack */
        "   msr    psplim, r2               \n"
        "   mov    sp, r7                   \n"
        "   msr    psplim, r6               \n"
        "   cpsie  i                        \n"
        "   isb                             \n"
        "   pop    {r5-r7, pc}              \n"
    );
}

#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1 */

#if CONFIG_TFM_SPM_BACKEND_IPC == 1
__attribute__((naked)) void PendSV_Handler(void)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "   movs    r0, #"M2S(EXC_RETURN_S)"            \n"
        "   mov     r1, lr                              \n"
#if CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED == 0
        "   tst     r0, r1                              \n" /* NS interrupted */
        "   beq     v8b_pendsv_exit                     \n" /* No schedule */
#endif
        "   push    {r0, lr}                            \n" /* Save R0, LR */
        "   mov     r0, lr                              \n" /* Pass the EXC_RETURN value as
                                                             * parameter
                                                             */
        "   bl      ipc_schedule                        \n"
        "   pop     {r2, r3}                            \n"
        "   mov     lr, r3                              \n"
        "   cmp     r0, r1                              \n" /* curr, next ctx */
        "   beq     v8b_pendsv_exit                     \n" /* No schedule */
        "   cpsid   i                                   \n"
        "   isb                                         \n"
        "   mrs     r2, psp                             \n"
        "   mov     r3, lr                              \n"
        "   push    {r0, r1}                            \n"
        "   movs    r1, #"M2S(EXC_RETURN_DCRS)"         \n" /* Check DCRS */
        "   ands    r1, r3                              \n"
        "   beq     v8b_pendsv_callee_saved             \n" /* Skip saving callee */
        "   subs    r2, #32                             \n" /* For r4-r7 */
        "   stm     r2!, {r4-r7}                        \n" /* Save r4-r7 */
        "   mov     r4, r8                              \n"
        "   mov     r5, r9                              \n"
        "   mov     r6, r10                             \n"
        "   mov     r7, r11                             \n"
        "   stm     r2!, {r4-r7}                        \n" /* Save r8-r11 */
        "   subs    r2, #40                             \n" /* Set SP to top
                                                             * With two more dummy data for
                                                             * reserved additional state context,
                                                             * integrity signature offset
                                                             */
        "v8b_pendsv_callee_saved:                       \n"
        "   pop     {r0, r1}                            \n"
        "   stm     r0!, {r2, r3}                       \n" /* Save curr ctx */
        "   ldm     r1!, {r2, r3}                       \n" /* Load next ctx */
        "   mov     lr, r3                              \n"
        "   push    {r0, r1}                            \n"
        "   movs    r1, #"M2S(EXC_RETURN_DCRS)"         \n" /* Check DCRS */
        "   ands    r1, r3                              \n"
        "   beq     v8b_pendsv_callee_loaded            \n" /* Skip loading callee */
        "   adds    r2, #24                             \n" /* Pop dummy data for
                                                             * reserved additional state context,
                                                             * integrity signature offset,
                                                             * r8-r11
                                                             */
        "   ldm     r2!, {r4-r7}                        \n"
        "   mov     r8, r4                              \n"
        "   mov     r9, r5                              \n"
        "   mov     r10, r6                             \n"
        "   mov     r11, r7                             \n"
        "   subs    r2, #32                             \n" /* Pop r4-r7 */
        "   ldm     r2!, {r4-r7}                        \n"
        "   adds    r2, #16                             \n" /* Pop r4-r11 end */
        "v8b_pendsv_callee_loaded:                      \n"
        "   pop     {r0, r1}                            \n"
        "   ldr     r3, [r1]                            \n"
        "   msr     psp, r2                             \n"
        "   msr     psplim, r3                          \n"
        "   cpsie   i                                   \n"
        "   isb                                         \n"
        "v8b_pendsv_exit:                               \n"
        "   bx      lr                                  \n"
    );
}
#endif

__attribute__((naked)) void SVC_Handler(void)
{
    __ASM volatile(
    SYNTAX_UNIFIED
    "MRS     r0, MSP                        \n"
    "MOV     r1, lr                         \n"
    "MRS     r2, PSP                        \n"
    "MRS     r3, PSPLIM                     \n"
    "PUSH    {r2, r3}                       \n" /* PSP PSPLIM */
    "PUSH    {r1, r2}                       \n" /* Orig_exc_return, dummy */
    "BL      spm_svc_handler                \n"
    "MOV     lr, r0                         \n"
    "LDR     r1, [sp]                       \n" /* Get orig_exc_return value */
    "MOVS    r2, #8                         \n"
    "ANDS    r0, r2                         \n" /* Mode bit */
    "ANDS    r1, r2                         \n"
    "SUBS    r0, r1                         \n" /* Compare EXC_RETURN values */
    "BGT     to_flih_func                   \n"
    "BLT     from_flih_func                 \n"
    "ADD     sp, #16                        \n" /*
                                                 * "Unstack" unused orig_exc_return, dummy,
                                                 * PSP, PSPLIM pushed by current handler
                                                 */
    "BX      lr                             \n"
    "to_flih_func:                          \n"
    "LDR     r0, ="M2S(EXC_RETURN_DCRS)"    \n" /* Check DCRS */
    "MOV     r1, lr                         \n"
    "ANDS    r0, r1                         \n"
    "BEQ     v8b_svc_callee_saved           \n" /* Skip saving callee */
    "PUSH    {r4-r7}                        \n" /* Save callee */
    "MOV     r4, r8                         \n"
    "MOV     r5, r9                         \n"
    "MOV     r6, r10                        \n"
    "MOV     r7, r11                        \n"
    "PUSH    {r4-r7}                        \n"
    "SUB     sp, #8                         \n" /* Dummy data to align SP offset for
                                                 * reserved additional state context,
                                                 * integrity signature
                                                 */
    "v8b_svc_callee_saved:                  \n"
    "LDR     r4, ="M2S(STACK_SEAL_PATTERN)" \n" /* clear r4-r11 */
    "MOV     r5, r4                         \n"
    "MOV     r6, r4                         \n"
    "MOV     r7, r4                         \n"
    "MOV     r8, r4                         \n"
    "MOV     r9, r4                         \n"
    "MOV     r10, r4                        \n"
    "MOV     r11, r4                        \n"
    "PUSH    {r4, r5}                       \n" /* Seal stack before EXC_RET */
    "BX      lr                             \n"
    "from_flih_func:                        \n"
    "ADD     sp, #16                        \n" /*
                                                 * "Unstack" unused orig_exc_return, dummy,
                                                 * PSP, PSPLIM pushed by current handler
                                                 */
    "POP     {r4, r5}                       \n" /* Seal stack */
    "LDR     r0, ="M2S(EXC_RETURN_DCRS)"    \n" /* Check DCRS */
    "MOV     r1, lr                         \n"
    "ANDS    r0, r1                         \n"
    "BEQ     v8b_svc_callee_loaded          \n" /* Skip loading callee */
    "ADD     sp, #8                         \n" /* Dummy data to align SP offset for
                                                 * reserved additional state context,
                                                 * integrity signature
                                                 */
    "POP     {r4-r7}                        \n"
    "MOV     r8, r4                         \n"
    "MOV     r9, r5                         \n"
    "MOV     r10, r6                        \n"
    "MOV     r11, r7                        \n"
    "POP     {r4-r7}                        \n"
    "v8b_svc_callee_loaded:                 \n"
    "ADD     sp, #16                        \n" /*
                                                 * "Unstack" unused orig_exc_return, dummy,
                                                 * PSP, PSPLIM pushed by the previous
                                                 * TFM_SVC_PREPARE_DEPRIV_FLIH request
                                                 */
    "BX      lr                             \n"
    );
}

void tfm_arch_set_secure_exception_priorities(void)
{
    uint32_t VECTKEY;
    SCB_Type *scb = SCB;
    uint32_t AIRCR;

    /* Set PRIS flag in AIRCR */
    AIRCR = scb->AIRCR;
    VECTKEY = (~AIRCR & SCB_AIRCR_VECTKEYSTAT_Msk);
    scb->AIRCR = SCB_AIRCR_PRIS_Msk |
                 VECTKEY |
                 (AIRCR & ~SCB_AIRCR_VECTKEY_Msk);

    NVIC_SetPriority(SVCall_IRQn, SVCall_IRQnLVL);
    /*
     * Set secure PendSV priority to the lowest in SECURE state.
     */
    NVIC_SetPriority(PendSV_IRQn, PENDSV_PRIO_FOR_SCHED);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(int32_t) tfm_arch_verify_secure_exception_priorities(void)
{
    SCB_Type *scb = SCB;

    if ((scb->AIRCR & SCB_AIRCR_PRIS_Msk) !=  SCB_AIRCR_PRIS_Msk) {
        FIH_RET(FIH_FAILURE);
    }
    (void)fih_delay();
    if ((scb->AIRCR & SCB_AIRCR_PRIS_Msk) !=  SCB_AIRCR_PRIS_Msk) {
        FIH_RET(FIH_FAILURE);
    }
    if (fih_not_eq(fih_int_encode(NVIC_GetPriority(SVCall_IRQn)),
                  fih_int_encode(SVCall_IRQnLVL))) {
        FIH_RET(FIH_FAILURE);
    }
    if (fih_not_eq(fih_int_encode(NVIC_GetPriority(PendSV_IRQn)),
                  fih_int_encode(PENDSV_PRIO_FOR_SCHED))) {
        FIH_RET(FIH_FAILURE);
    }
    FIH_RET(FIH_SUCCESS);
}
#endif

void tfm_arch_config_extensions(void)
{
    /* There are no coprocessors in Armv8-M Baseline implementations */
    return;
}

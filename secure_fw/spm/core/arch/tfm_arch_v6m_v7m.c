/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <inttypes.h>
#include "compiler_ext_defs.h"
#include "security_defs.h"
#include "utilities.h"
#include "spm.h"
#include "tfm_arch.h"
#include "tfm_hal_device_header.h"
#include "tfm_svcalls.h"
#include "svc_num.h"

#if !defined(__ARM_ARCH_6M__) && !defined(__ARM_ARCH_7M__) && \
    !defined(__ARM_ARCH_7EM__)
#error "Unsupported ARM Architecture."
#endif

uint32_t psp_limit;

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

#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1*/

#endif

#if CONFIG_TFM_SPM_BACKEND_IPC == 1

__naked
void tfm_arch_thread_fn_call(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    __asm volatile(
        SYNTAX_UNIFIED
        "   push   {r4-r6, lr}              \n"
        "   mov    r4, r12                  \n"
        "   push   {r0-r5}                  \n"
        "   cpsid  i                        \n"
        "   isb                             \n"
        "   bl     backend_abi_entering_spm \n" /* r0: new SP */
        "   cmp    r0, #0                   \n" /* Check whether the caller is
                                                 * NS agent(new SP == 0) or
                                                 * secure partition(new SP != 0)
                                                 */
        "   beq    v6v7_branch_to_target    \n"
        "   mov    r6, sp                   \n"
        "   mov    sp, r0                   \n" /* Switch to the SPM stack if
                                                 * caller is NOT an NS agent.
                                                 */
        "v6v7_branch_to_target:             \n"
        "   cpsie  i                        \n"
        "   isb                             \n"
        "   ldmia  r6!, {r0-r5}             \n" /* Load PSA interface input args
                                                 * and target function
                                                 */
        "   blx    r4                       \n"
        "   cpsid  i                        \n"
        "   isb                             \n"
        "   bl     backend_abi_leaving_spm  \n"
        "   mov    sp, r6                   \n" /* switch stack */
        "   cpsie  i                        \n"
        "   isb                             \n"
        "   pop    {r4-r6, pc}              \n"
    );
}

#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1*/

#if CONFIG_TFM_SPM_BACKEND_IPC == 1
__attribute__((naked)) void PendSV_Handler(void)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "   push    {r0, lr}                \n"
        "   mov     r0, lr                  \n" /* pass the EXC_RETURN value as parameter */
        "   bl      ipc_schedule            \n"
        "   pop     {r2, r3}                \n"
        "   mov     lr, r3                  \n"
        "   cmp     r0, r1                  \n" /* ctx of curr and next thrd */
        "   beq     v6v7_pendsv_exit        \n" /* No schedule if curr = next */
        "   cpsid   i                       \n"
        "   isb                             \n"
        "   mrs     r2, psp                 \n"
        "   subs    r2, #32                 \n" /* Make room for r4-r11 */
        "   stm     r2!, {r4-r7}            \n" /* Save callee registers */
        "   mov     r4, r8                  \n"
        "   mov     r5, r9                  \n"
        "   mov     r6, r10                 \n"
        "   mov     r7, r11                 \n"
        "   stm     r2!, {r4-r7}            \n"
        "   subs    r2, #40                 \n" /* Rewind r2(SP) to context top
                                                 * With two more dummy data for
                                                 * reserved additional state context,
                                                 * integrity signature offset
                                                 */
        "   mov     r3, lr                  \n"
        "   stm     r0!, {r2, r3}           \n" /* Save struct context_ctrl_t */
        "   ldm     r1!, {r2, r3}           \n" /* Load ctx of next thread */
        "   mov     lr, r3                  \n"
        "   adds    r2, #24                 \n" /* Pop dummy data for
                                                 * reserved additional state context,
                                                 * integrity signature offset,
                                                 * r4-r11
                                                 */
        "   ldm     r2!, {r4-r7}            \n"
        "   mov     r8, r4                  \n"
        "   mov     r9, r5                  \n"
        "   mov     r10, r6                 \n"
        "   mov     r11, r7                 \n"
        "   subs    r2, #32                 \n"
        "   ldm     r2!, {r4-r7}            \n"
        "   adds    r2, #16                 \n" /* End of popping r4-r11 */
        "   msr     psp, r2                 \n"
        "   cpsie   i                       \n"
        "   isb                             \n"
        "v6v7_pendsv_exit:                  \n"
        "   bx      lr                      \n"
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
    "PUSH    {r2, r3}                       \n" /* PSP dummy */
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
    "PUSH    {r4-r7}                        \n"
    "MOV     r4, r8                         \n"
    "MOV     r5, r9                         \n"
    "MOV     r6, r10                        \n"
    "MOV     r7, r11                        \n"
    "PUSH    {r4-r7}                        \n"
    "SUB     sp, sp, #8                     \n" /* Dumy data to align SP offset for
                                                 * reserved additional state context,
                                                 * integrity signature
                                                 */
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
    "ADD     sp, sp, #8                     \n" /* Dummy data to align SP offset for
                                                 * reserved additional state context,
                                                 * integrity signature
                                                 */
    "POP     {r4-r7}                        \n"
    "MOV     r8, r4                         \n"
    "MOV     r9, r5                         \n"
    "MOV     r10, r6                        \n"
    "MOV     r11, r7                        \n"
    "POP     {r4-r7}                        \n"
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
    /* Set fault priority to the highest */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    NVIC_SetPriority(MemoryManagement_IRQn, MemoryManagement_IRQnLVL);
    NVIC_SetPriority(BusFault_IRQn, BusFault_IRQnLVL);
#endif

    NVIC_SetPriority(SVCall_IRQn, SVCall_IRQnLVL);
    NVIC_SetPriority(PendSV_IRQn, PENDSV_PRIO_FOR_SCHED);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(int32_t) tfm_arch_verify_secure_exception_priorities(void)
{
    /* Set fault priority to the highest */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    if (FIH_NOT_EQ(NVIC_GetPriority(MemoryManagement_IRQn),
                  MemoryManagement_IRQnLVL)) {
        FIH_RET(FIH_FAILURE);
    }
    if (FIH_NOT_EQ(NVIC_GetPriority(BusFault_IRQn),
                  BusFault_IRQnLVL)) {
        FIH_RET(FIH_FAILURE);
    }
#endif

    if (FIH_NOT_EQ(NVIC_GetPriority(SVCall_IRQn),
                  SVCall_IRQnLVL)) {
        FIH_RET(FIH_FAILURE);
    }
    if (FIH_NOT_EQ(NVIC_GetPriority(PendSV_IRQn),
                  PENDSV_PRIO_FOR_SCHED)) {
        FIH_RET(FIH_FAILURE);
    }
    FIH_RET(FIH_SUCCESS);
}
#endif

void tfm_arch_config_extensions(void)
{
    /* There are no coprocessors in Armv6-M implementations */
#ifndef __ARM_ARCH_6M__
#if defined(CONFIG_TFM_ENABLE_CP10CP11)
    /* Enable privileged and unprivileged access to the floating-point
     * coprocessor.
     */
    SCB->CPACR |= (3U << 10U*2U)     /* enable CP10 full access */
                  | (3U << 11U*2U);  /* enable CP11 full access */
#elif defined(CONFIG_TFM_DISABLE_CP10CP11)
    /* Disable privileged and unprivileged access to the floating-point
     * coprocessor.
     */
    SCB->CPACR &= ~((3U << 10U*2U)   /* disable CP10 full access */
                  | (3U << 11U*2U)); /* disable CP11 full access */
#endif /* defined(CONFIG_TFM_ENABLE_CP10CP11) */
#endif

    __DSB();
    __ISB();
}

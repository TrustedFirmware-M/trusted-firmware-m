/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "compiler_ext_defs.h"
#include "cy_ms_ctl.h"
#include "utilities.h"
#include "fih.h"
#include "memory_symbols.h"
#include "protection_pc.h"
#include "protection_regions_cfg.h"
#ifdef IFX_BSP_CONFIG_HEADER_FILE
#include IFX_BSP_CONFIG_HEADER_FILE
#endif /* IFX_BSP_CONFIG_HEADER_FILE */
#ifdef IFX_STARTUP_HEADER_FILE
#include IFX_STARTUP_HEADER_FILE
#endif /* IFX_STARTUP_HEADER_FILE */
#include "coverity_check.h"
#include "tfm_platform_arch_hooks.h"

#ifdef RAM_VECTORS_SUPPORT
/* \brief Address of vector table which holds pointers to exception/IRQ handlers */
#define IFX_VTOR_ADDRESS    __vector_table_rw
#else
/* \brief Address of vector table which holds pointers to exception/IRQ handlers */
#define IFX_VTOR_ADDRESS    __vector_table
#endif

#if (IFX_CORE == IFX_CM33)
/*
 * \brief Bit mask that show how to handle return of NMI
 *
 * 1 - \ref ifx_pc2_exception_handler returns from exception with restoring
 *     Saved Protection Context
 * 0 - Exception handles return and Protection Context switching itself.
 *     Some exceptions like fault handlers calls \ref tfm_core_panic() without return.
 */
#define IFX_RETURN_ON_EXCEPTION_BIT_MASK    \
        ((1 <<  2) |        /*   -14 NMI Handler */ \
         (0 <<  3) |        /*   -13 Hard Fault Handler */ \
         (0 <<  4) |        /*   -12 MPU Fault Handler */ \
         (0 <<  5) |        /*   -11 Bus Fault Handler */ \
         (0 <<  6) |        /*   -10 Usage Fault Handler */ \
         (0 <<  7) |        /*    -9 Secure Fault Handler */ \
         (0 <<  8) |        /*    -8 Reserved */ \
         (0 <<  9) |        /*    -7 Reserved */ \
         (0 << 10) |        /*    -6 Reserved */ \
         (0 << 11) |        /*    -5 SVCall Handler */ \
         (1 << 12) |        /*    -4 Debug Monitor Handler */ \
         (0 << 13) |        /*    -3 Reserved */ \
         (0 << 14) |        /*    -2 PendSV Handler */ \
         (1 << 15))       /*    -1 SysTick Handler */
#endif

void ifx_pc2_exception_handler(void);

TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_9_3, "All array members are initialized via designators")
const VECTOR_TABLE_Type ifx_pc2_vector_table[VECTORTABLE_SIZE] __attribute__((aligned(VECTORTABLE_ALIGN))) = {
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_1, "Linker variable must be cast to VECTOR_TABLE_Type")
    [0] = (VECTOR_TABLE_Type)(&__INITIAL_SP),         /*       Initial Stack Pointer */ \
    /* All entries points to common handler which performs switching to PC2 and calling handler
     * from original vector table */
    [1 ... VECTORTABLE_SIZE-1] =    ifx_pc2_exception_handler,
};

/*!
 * \brief Active protection context.
 *
 * PC_SAVED is not used because it's inconsistent if there are multiple pending IRQs.
 * This variable is atomically updated with PC. So, this allows to properly restore
 * protection context after handling exception.
 *
 * Note: Allocate variable in scope of SPM data to avoid access by unprivileged code.
 */
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_2_8, "Used with assembler for restoring PC after handling exception");
fih_int ifx_arch_active_protection_context = FIH_INT_INIT(IFX_PC_TFM_SPM_ID);

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_pc_init(void)
{
    (void)fih_delay();

    /* Validate that VTOR is pointing to valid vector table */
    if (SCB->VTOR != (uint32_t)&IFX_VTOR_ADDRESS) {
        FIH_RET(TFM_HAL_ERROR_BAD_STATE);
    }

    (void)fih_delay();

    /* Capture all secure exceptions */
    SCB->VTOR = (uint32_t)ifx_pc2_vector_table;

    __ISB();
    __DSB();

#if IFX_PC_TFM_SPM_ID == 2
    /* ifx_pc2_exception_handler is hardware switch to PC2.
     * PC2_HANDLER is set as VALID by BootROM.  */
    MXCM33->CM33_PC2_HANDLER = (uint32_t)ifx_pc2_exception_handler;
    if (MXCM33->CM33_PC2_HANDLER != (uint32_t)ifx_pc2_exception_handler) {
        FIH_RET(TFM_HAL_ERROR_BAD_STATE);
    }
#else
#error "IFX_PC_TFM_SPM_ID value is unsupported"
#endif

    __ISB();
    __DSB();

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_pc_verify_static_boundaries(void)
{
    (void)fih_delay();
    /* Validate that VTOR is pointing to valid vector table */
    if (SCB->VTOR != (uint32_t)ifx_pc2_vector_table) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

#if IFX_PC_TFM_SPM_ID == 2
    (void)fih_delay();
    /* ifx_pc2_exception_handler is hardware switch to PC2 */
    if (MXCM33->CM33_PC2_HANDLER != (uint32_t)ifx_pc2_exception_handler) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
#else
#error "IFX_PC_TFM_SPM_ID value is unsupported"
#endif

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

/*!
 * \brief Perform protection context switching
 *
 * \note It's unsafe to switch PC to other than PC2 (used by SPM) in low priority
 * exception, because it's possible that there will be pending IRQ and MCU will
 * try to use MSP stack pushing exception stack within PC not equal to PC2.
 *
 * \note IRQ must be disabled if this function is called from exception/IRQ with privilege below 0.
 */
/* gcc documents that the use of attribute "naked" is only supported for basic asm statements.
 * "While using extended asm or a mixture of basic asm and C code may appear to work, they
 * cannot be depended upon to work reliably and are not supported". All the alternative approaches
 * also seem to be problematic from a maintenance point-of-view, though, and there are currently
 * similar uses in platform-independent code.
 */
#ifdef FIH_ENABLE_DOUBLE_VARS
__attribute__((naked)) void ifx_arch_switch_protection_context(uint32_t pc, uint32_t pc_mask)
#else
__attribute__((naked)) void ifx_arch_switch_protection_context(uint32_t pc)
#endif
{
    __ASM volatile(
#ifdef FIH_ENABLE_DOUBLE_VARS
        /* Validate protection context */
        "ldr    r3, =" M2S(_FIH_MASK_VALUE) "             \n"
        "eor    r3, r0                                    \n"
        "eors   r3, r1                                    \n"
        "bne.w  tfm_core_panic                            \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        /* Save active protection context atomically */
        "ldr    r2,=ifx_arch_active_protection_context    \n"
#ifdef FIH_ENABLE_DOUBLE_VARS
        "stm    r2, {r0, r1}                              \n"
#else
        "str    r0, [r2]                                  \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        /* Invalidate I-Cache if there is switch to other PC than PC2 */
        "cmp    r0, #"M2S(IFX_PC_TFM_SPM_ID)"             \n"
        "beq    ifx_arch_switch_protection_context_skip_cache_invalidation\n"
        "dsb                                              \n"
        "isb                                              \n"
        "mov    r2, %[ICACHE0_CMD_ADDR] & 0xFFFF          \n"
        "movt   r2, %[ICACHE0_CMD_ADDR] >> 16             \n"
        "mov    r3, #1                                    \n"
        "str    r3, [r2]                                  \n"
"ifx_arch_switch_protection_context_wait_for_cache_invalidation:\n"
        "ldr    r3, [r2]                                  \n"
        "tst    r3, #1                                    \n"
        "bne    ifx_arch_switch_protection_context_wait_for_cache_invalidation\n"
"ifx_arch_switch_protection_context_skip_cache_invalidation:\n"
        "dsb                                              \n"
        "isb                                              \n"

        /* Switch Protection Context */
        /* Set PC_SAVED to NS Agent TZ PC */
        "movt   r0, #"M2S(IFX_PC_TZ_NSPE_ID)"             \n"

        /* MS_PC0->PC = (pc << 16) | pc */
        "mov    r2, %[PC_ADDR] & 0xFFFF                   \n"
        "movt   r2, %[PC_ADDR] >> 16                      \n"
        "str    r0, [r2]                                  \n"

        /* read back PC_READ_MIR */
        "mov    r2, %[PC_READ_MIR_ADDR] & 0xFFFF          \n"
        "movt   r2, %[PC_READ_MIR_ADDR] >> 16             \n"
        "ldr    r3, [r2]                                  \n"
        "cmp    r0, r3                                    \n"
        "bne.w  tfm_core_panic                            \n"

#ifdef FIH_ENABLE_DOUBLE_VARS
        /* read back PC_READ_MIR second time for FIH */
        "mov    r2, %[PC_READ_MIR_ADDR] & 0xFFFF          \n"
        "movt   r2, %[PC_READ_MIR_ADDR] >> 16             \n"
        "ldr    r3, [r2]                                  \n"
        "cmp    r0, r3                                    \n"
        "bne.w  tfm_core_panic                            \n"

        /* validate vs pc_mask */
        "ldr    r2, =" M2S(_FIH_MASK_VALUE ^ (IFX_PC_TZ_NSPE_ID << 16)) " \n"
        "eor    r2, r1                                    \n"   /* r2 = (input)pc_mask ^ _FIH_MASK_VALUE ^ (PC_TZ << 16) = { PC_TZ (input)pc } */
        "eors   r2, r3                                    \n"   /* r2 = { PC_TZ (input)pc } ^ (mir){ pc_saved pc } == 0 */
        "bne.w  tfm_core_panic                            \n"
#endif

        "dmb                                              \n"
        "dsb                                              \n"
        "isb                                              \n"
        "cpsie  i                                         \n"
        "bx     lr                                        \n"
        :
        : [ICACHE0_CMD_ADDR] "n" (&ICACHE0->CMD),
          [PC_ADDR] "n" (&MS_PC0->PC),
          [PC_READ_MIR_ADDR] "n" (IFX_NS_ADDRESS_ALIAS((uintptr_t)(&MS_PC0->PC_READ_MIR)))
    );
}

/*!
 * \brief Perform protection context switching from low priority IRQ
 *
 * This function will complete switching to PC2 (SPM) in scope of current exception.
 * For all other protection context it will schedule switching after exit from active IRQ
 * in thread mode by \ref ifx_arch_switch_protection_context_thread.
 *
 * \note IRQ must be disabled when this function is called.
 */
#ifdef FIH_ENABLE_DOUBLE_VARS
__attribute__((naked)) void ifx_arch_switch_protection_context_from_irq(uint32_t pc,
                                                                        uint32_t pc_mask)
#else
__attribute__((naked)) void ifx_arch_switch_protection_context_from_irq(uint32_t pc)
#endif
{
    __ASM volatile(
#ifdef FIH_ENABLE_DOUBLE_VARS
        /* fih_validate( r0, r1 ) */
        "ldr    r3, =" M2S(_FIH_MASK_VALUE) "             \n"
        "eor    r3, r0                                    \n"
        "eors   r3, r1                                    \n"
        "bne    ifx_arch_switch_protection_context_from_irq_panic \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        /* Switch Protection Context only if it's PC2 */
        "cmp    r0, #"M2S(IFX_PC_TFM_SPM_ID)"             \n"
        "beq    ifx_arch_switch_protection_context        \n"

        /* It's not safe to switch PC to other than PC2. Because, pending IRQ
         * can cause nested exception while PC is not equal PC2 and MSP stack
         * is not accessible, so attempt to stack exception frame stack into MSP
         * will fail and generate HardFault.
         *
         * Switching PC must be done in most privileged code to avoid nested
         * exceptions. It's implemented through returning to thread mode.
         */

        /* Validate stack, it must be aligned by 8 bytes */
        "mov    r3, sp                                    \n"
        "tst    r3, #7                                    \n"
        "bne    ifx_arch_switch_protection_context_from_irq_panic\n"

        /* Stack seal pattern */
        "ldr    r2, ="M2S(STACK_SEAL_PATTERN)"            \n"
        "push   {r2}                                      \n"
        "push   {r2}                                      \n"

        /* MSP stack is used to exit to thread mode to keep original stack untouched. */
        /* XPSR - 0x01000000 (T32 state bit. Determines the current instruction set state). */
        "mov    r2, #0x01000000                           \n"
        "push   {r2}                                      \n"
        /* Return address - ifx_arch_switch_protection_context_thread  */
        "ldr    r2, =ifx_arch_switch_protection_context_thread \n"
        "push   {r2}                                      \n"
        /* Save lr - EXC_RETURN to original code */
        "push   {r12, lr}                                 \n"

        /* r2 = CONTROL to restore CONTROL.nPRIV during switch of PC */
        "mrs    r2, control                               \n"
        /* new PC, FIH new PC/R1, CONTROL, SP */
        "push   {r0-r3}                                  \n"

        /* CONTROL.nPRIV = 0 to exit to Thread privileged mode and have access to MSP stack */
        "bic    r2, #1                                    \n"
        "msr    control, r3                               \n"

        /* Exit to thread mode calling ifx_arch_switch_protection_context_thread */
        "mov    lr, #0xFFFFFFF9                           \n"
        "bx     lr                                        \n"

"ifx_arch_switch_protection_context_from_irq_panic:       \n"
        "b.w    tfm_core_panic                            \n"
    );
}

__attribute__((naked)) void ifx_arch_switch_protection_context_thread(uint32_t pc)
{
    __ASM volatile(
        /* Undefined instruction is handled by UsageFault, but it's masked, so
         * it will call HardFault, which after testing conditions should switch Protection Context
         * See \ref PLATFORM_HARD_FAULT_HANDLER_HOOK. */
        "udf    #0                                        \n"
    );
}

#if defined(__ICCARM__)
#pragma required = tfm_core_panic
#endif

/* Sometimes Clang optimizes __ASM volatile code. To avoid this and ensure
 * assembly code is kept as it appropriate pragma is added */
#if defined(__ARMCC_VERSION)
#pragma clang optimize off
#endif
/*!
 * \brief Default secure interrupt handler which is a hardware entry point to
 * Protection Context 2.
 *
 * SCB ICSR VECTACTIVE is used to detect active interrupt number and select a appropriate
 * handler from VTOR table located at \ref IFX_VTOR_ADDRESS.
 */
/* gcc documents that the use of attribute "naked" is only supported for basic asm statements.
 * "While using extended asm or a mixture of basic asm and C code may appear to work, they
 * cannot be depended upon to work reliably and are not supported". All the alternative approaches
 * also seem to be problematic from a maintenance point-of-view, though, and there are currently
 * similar uses in platform-independent code.
 */
__attribute__((naked)) void ifx_pc2_exception_handler(void)
{
    /* Save Active PC must be the first code in exception handler */
    __ASM volatile(
        SYNTAX_UNIFIED
        /* Read-Write Active PC atomically */
        "   cpsid  i                                    \n"

        /* Load active PC */
        "   ldr     r2,=ifx_arch_active_protection_context \n"
        "   ldr     r0, [r2]                            \n"
#ifdef FIH_ENABLE_DOUBLE_VARS
        "   ldr     r1, [r2, #4]                        \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        /* Update active PC to allow nested exception/IRQ with higher priority
         * to restore a proper protection context */
        "   ldr     r3, =" M2S(IFX_PC_TFM_SPM_ID) "     \n"
        "   str     r3, [r2]                            \n"
#ifdef FIH_ENABLE_DOUBLE_VARS
        "   ldr     r3, =(" M2S(IFX_PC_TFM_SPM_ID ^ _FIH_MASK_VALUE) ")\n"
        "   str     r3, [r2, #4]                        \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        /* Load Active PC, PC_SAVED*/
        "   mov     r2, %[PC_ADDR] & 0xFFFF             \n"
        "   movt    r2, %[PC_ADDR] >> 16                \n"
        "   ldr     r3, [r2]                            \n"

       /* Validate Active PC vs PC_SAVED from register */
        "   lsr     r3, r3, #16                         \n"
        "   cmp     r0, #2                              \n"
        "   ite     eq                                  \n"
        /* PC_SAVED must be equal to IFX_PC_TZ_NSPE_ID if switch from PC2 */
        "   cmpeq   r3, #"M2S(IFX_PC_TZ_NSPE_ID)"       \n"
        /* ... otherwise PC_SAVED must be equal to Active PC */
        "   cmpne   r3, r0                              \n"
        "   bne     ifx_pc2_exception_handler_inv_vact  \n"

        /* Update PC_SAVED to TZ Agent NS.
         * PC is set to PC_SAVED on non-secure exception. */
        "   ldr     r3, ="M2S(IFX_PC_TFM_SPM_ID | (IFX_PC_TZ_NSPE_ID << 16))" \n"
        "   str     r3, [r2]                            \n"

#ifdef FIH_ENABLE_DOUBLE_VARS
        /* Save Active PC with FIH to stack */
        "   push    {r0, r1}                            \n"

        /* fih_validate( r0, r1 ) */
        "   ldr     r3, =" M2S(_FIH_MASK_VALUE) "       \n"
        "   eor     r3, r0                              \n"
        "   eors    r3, r1                              \n"
        "   bne     ifx_pc2_exception_handler_inv_vact  \n"

#else /* FIH_ENABLE_DOUBLE_VARS */
        /* Save Active PC, PC_SAVED without FIH to stack */
        "   push    {r0, r3}                            \n"
#endif /* FIH_ENABLE_DOUBLE_VARS */

        "   cpsie   i                                   \n"

        /* Extract exception number */
        "   mrs     r2, IPSR                            \n"

        /* Validate that exception number is in bound of VTOR table */
#if VECTORTABLE_SIZE <= 256
        "   cmp     r2, %[VT_SIZE]                      \n"
#else
        "   mov     r3, %[VT_SIZE]                      \n"
        "   cmp     r2, r3                              \n"
#endif
        "   bhi     ifx_pc2_exception_handler_inv_vact  \n"

        /* Call handler with return if it's IRQ */
        "   lsl     r1, r2, #2                          \n"
        "   ldr     r0, =" M2S(IFX_VTOR_ADDRESS) "      \n"
        "   ldr     r0, [r0, r1]                        \n"
        "   cmp     r2, %[VEC_FIXED_EXP_NR]             \n"
        "   bhi     ifx_pc2_exception_handler_with_return \n"

        /* Handle fixed exception (SVC, PendSV, ...).
         * \ref IFX_RETURN_ON_EXCEPTION_BIT_MASK is used to determine type of
         * exception handler by using bit value at `exception id` position:
         * 1 - Saved Protection Context is pushed to stack and restored on
         *     return from handler function. Typical use case SysTick.
         * 0 - Protection Context switching and return from exception is done by
         *     handler function. Typical use case SVC/PendSV exceptions that performs
         *     partition switching or fault handlers that restart/halt system. */
        "ifx_pc2_exception_handler_exp:                 \n"
        "   ldr     r1, =" M2S(IFX_RETURN_ON_EXCEPTION_BIT_MASK) " \n"
        "   lsr     r1, r2                              \n"
        "   ands    r1, #1                              \n"
        "   bne     ifx_pc2_exception_handler_with_return \n"

        /* It's expected that exception handles exit properly */
        "   bx      r0                                  \n"

        /* Handle IRQ */
        "ifx_pc2_exception_handler_with_return:         \n"
        "   push    {lr}                                \n"
        "   blx     r0                                  \n"
        "   pop     {lr}                                \n"
        /* Exit from interrupt with restoring to Saved Protection Context */
        IFX_PLATFORM_EXIT_FROM_INTERRUPT_WITH_PC_RESTORE_HOOK

        "ifx_pc2_exception_handler_inv_vact:            \n"
        "   bl     tfm_core_panic                       \n"
    : :
      [PC_ADDR] "i" (&MS_PC0->PC),
      [VT_SIZE] "I" (VECTORTABLE_SIZE-1U),
      [VEC_FIXED_EXP_NR] "I" (VECTOR_FIXED_EXP_NR)
      : "r0", "r1", "r2", "r3"  /* clobber */
    );
}

#if defined(__ARMCC_VERSION)
#pragma clang optimize on
#endif

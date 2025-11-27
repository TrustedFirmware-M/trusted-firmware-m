/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PLATFORM_ARCH_HOOKS_H
#define TFM_PLATFORM_ARCH_HOOKS_H

#include "ifx_fih.h"
#include "ifx_regions.h"
#include "tfm_arch.h"
#include "protection_pc.h"
#include "protection_regions_cfg.h"

ifx_aapcs_fih_int ifx_arch_get_context_protection_context(const struct context_ctrl_t *prev_ctx,
                                                          const struct context_ctrl_t *cur_ctx,
                                                          uint32_t exc_return);

ifx_aapcs_fih_int ifx_arch_get_current_component_protection_context(uint32_t exc_return);

#ifdef FIH_ENABLE_DOUBLE_VARS
void ifx_arch_switch_protection_context(uint32_t pc, uint32_t pc_mask);
void ifx_arch_switch_protection_context_from_irq(uint32_t pc, uint32_t pc_mask);
#else
void ifx_arch_switch_protection_context(uint32_t pc);
void ifx_arch_switch_protection_context_from_irq(uint32_t pc);
#endif /* FIH_ENABLE_DOUBLE_VARS */

/*
 * \brief Inline assembler hook that implements exit from interrupt with switching
 * to Saved Protection Context.
 */
#define IFX_PLATFORM_EXIT_FROM_INTERRUPT_WITH_PC_RESTORE_HOOK \
        "cpsid  i                                  \n" \
        /* Pop Protection Context from stack */ \
        "pop    {r0, r1}                           \n" \
        /* Switch Protection Context */ \
        "b.w    ifx_arch_switch_protection_context_from_irq \n"

/*
 * \brief Inline assembler hook that returns MSP that points to stack saved by SVC.
 */
#define PLATFORM_SVC_HANDLER_GET_MSP_HOOK(reg) \
        /* 8 bytes used to store Saved PC */ \
        "mrs "  reg ", msp                     \n" \
        "add "  reg ", #8                      \n"

/*
 * \brief Inline assembler hook that implements Protection Context switching on exit from SVC.
 */
#define PLATFORM_SVC_HANDLER_EXIT_HOOK \
        "cpsid  i                                  \n" \
        /* Pop Protection Context from stack */ \
        "pop    {r0, r1}                           \n" \
        /* Switch Protection Context */ \
        "b.w    ifx_arch_switch_protection_context \n"

/*!
 * \brief Hook to update isolation before switching to SPM thread function
 *
 * \param msp       Address of MSP stack frame after adjusting it by
 *                  \ref PLATFORM_SVC_HANDLER_GET_MSP_HOOK
 * \param ctx       Address of SPM PSP stack used to handle SVC request in thread mode
 */
#ifdef FIH_ENABLE_DOUBLE_VARS
#define PLATFORM_INIT_SPM_FUNC_CONTEXT_HOOK(msp, ctx) \
        { \
            /* Switch to protection context used by SPM. */ \
            /* Update saved PC stored by \ref ifx_pc2_exception_handler */ \
            ((uint32_t *)msp)[-1] = IFX_PC_TFM_SPM_ID ^ _FIH_MASK_VALUE; \
            ((uint32_t *)msp)[-2] = IFX_PC_TFM_SPM_ID; \
        }
#else /* FIH_ENABLE_DOUBLE_VARS */
#define PLATFORM_INIT_SPM_FUNC_CONTEXT_HOOK(msp, ctx) \
        { \
            /* Switch to protection context used by SPM. */ \
            /* Update saved PC stored by \ref ifx_pc2_exception_handler */ \
            ((uint32_t *)msp)[-1] = IFX_PC_TFM_SPM_ID; \
            ((uint32_t *)msp)[-2] = IFX_PC_TFM_SPM_ID; \
        }
#endif /* FIH_ENABLE_DOUBLE_VARS */

/*!
 * \brief Hook to update isolation to handle exit from SPM thread function
 */
#ifdef FIH_ENABLE_DOUBLE_VARS
#define PLATFORM_THREAD_MODE_SPM_RETURN_HOOK(exc_return, msp) \
        { \
            AAPCS_DUAL_U32_T component_pc; \
            component_pc.u64_val = ifx_arch_get_current_component_protection_context(exc_return); \
            ((uint32_t *)msp)[-1] = component_pc.u32_regs.r1; \
            ((uint32_t *)msp)[-2] = component_pc.u32_regs.r0; \
        }
#else /* FIH_ENABLE_DOUBLE_VARS */
#define PLATFORM_THREAD_MODE_SPM_RETURN_HOOK(exc_return, msp) \
        { \
            uint32_t component_pc = ifx_arch_get_current_component_protection_context(exc_return); \
            uint32_t return_pc = component_pc; \
            ((uint32_t *)msp)[-1] = return_pc; \
            ((uint32_t *)msp)[-2] = return_pc; \
        }
#endif /* FIH_ENABLE_DOUBLE_VARS */

/* Declaration of required symbols for IAR inline assembler */
#define PLATFORM_SVC_HANDLER_HOOK_IAR_REQUIRED \
_Pragma("required = ifx_arch_get_current_component_protection_context") \
_Pragma("required = ifx_arch_switch_protection_context")

/*
 * \brief Inline assembler hook that remove Saved PC at the begin of exit from
 * IRQ`s FLIH handler.
 *
 * Saved PC should be removed, because:
 * 1. \ref TFM_SVC_FLIH_FUNC_RETURN is using context_flih_ret_t structure which overlaps with
 *    Saved PC for current SVC call.
 * 2. Saved PC is not important, because GET_CURRENT_COMPONENT() should be used to get information
 *    about partition that is switched to by \ref TFM_SVC_PREPARE_DEPRIV_FLIH request.
 */
#define PLATFORM_SVC_HANDLER_TO_FLIH_FUNC_ENTER_HOOK \
        /* "Unstack" orig_exc_return, dummy, PSP, PSPLIM pushed by current handler */ \
        "pop     {r0-r3}                                          \n" \
        /* Remove Saved PC from stack */ \
        "add     sp, #8                                           \n" \
        /* "Stack" orig_exc_return, dummy, PSP, PSPLIM pushed by current handler */ \
        "push     {r0-r3}                                         \n"

/*
 * \brief Inline assembler hook that implements Protection Context switching on exit from SVC
 * to enter IRQ`s FLIH handler.
 */
#define PLATFORM_SVC_HANDLER_TO_FLIH_FUNC_EXIT_HOOK \
        "cpsid  i                                                 \n" \
        "push   {lr}                                              \n" \
        "mov    r0, lr                                            \n" \
        "bl     ifx_arch_get_current_component_protection_context \n" \
        "pop    {lr}                                              \n" \
        "b.w    ifx_arch_switch_protection_context                \n"

/*
 * \brief Inline assembler hook that pop Saved PC at the begin of exit from
 * IRQ`s FLIH handler.
 *
 * Saved PC is not important, because \ref TFM_SVC_FLIH_FUNC_RETURN should switch to SPM
 * Protected Context.
 */
#define PLATFORM_SVC_HANDLER_FROM_FLIH_FUNC_ENTER_HOOK \
        /* Remove Saved PC for \ref TFM_SVC_FLIH_FUNC_RETURN SVC call from stack */ \
        "pop     {r0, r1}                                         \n"

/*
 * \brief Inline assembler hook that implements Protection Context switching on exit from
 * IRQ`s FLIH handler.
 */
#define PLATFORM_SVC_HANDLER_FROM_FLIH_FUNC_EXIT_HOOK \
        /* There is no need to switch PC, because \ref TFM_SVC_FLIH_FUNC_RETURN should
         * return to \ref spm_handle_interrupt which is running within privileged
         * PC2/SPM context */ \
        "bx      lr                                               \n"

/* Declaration of required symbols for IAR inline assembler */
#define PLATFORM_PENDSV_HANDLER_HOOK_IAR_REQUIRED \
_Pragma("required = ifx_arch_get_context_protection_context") \
_Pragma("required = ifx_arch_switch_protection_context_from_irq")

/*
 * \brief Inline assembler hook that implements Protection Context switching on exit from PendSV
 *
 * \param r0        Pointer to \ref context_ctrl_t of the current partition
 */
#define PLATFORM_PENDSV_HANDLER_EXIT_HOOK \
        "cpsid  i                                         \n" \
        /* Pop Saved Protection Context */ \
        "pop    {r2, r3}                                  \n" \
        "push   {lr}                                      \n" \
        "mov    r2, lr                                    \n" \
        "bl     ifx_arch_get_context_protection_context   \n" \
        "pop    {lr}                                      \n" \
        "b.w    ifx_arch_switch_protection_context_from_irq \n"

#if IFX_ISOLATION_PC_SWITCHING
/*
 * \brief secure interrupt handler \ref ifx_pc2_exception_handler stores
 * Saved Protection Context into exception stack. This macro removes it from the
 * stack to clean up entry for \ref EXCEPTION_INFO.
 */
#define PLATFORM_EXCEPTION_INFO_ENTER_HOOK() \
        __ASM volatile(                                     \
            "pop     {r0, r1}\n" \
        )
#endif /* IFX_ISOLATION_PC_SWITCHING */

#ifdef FIH_ENABLE_DOUBLE_VARS
/* Validate new PC with FIH */
#define PLATFORM_HARD_FAULT_HANDLER_HOOK_VALIDATE_PC() \
        /* Load FIH new PC */ \
        "ldr    r1, [sp, #0x0C]                             \n" \
        /* fih_validate( r0, r1 ) */ \
        "ldr    r3, =" M2S(_FIH_MASK_VALUE) "               \n" \
        "eor    r3, r0                                      \n" \
        "eors   r3, r1                                      \n" \
        "bne    _platform_hard_fault_handler_continue       \n"
#else /* FIH_ENABLE_DOUBLE_VARS */
/* Skip validation without FIH */
#define PLATFORM_HARD_FAULT_HANDLER_HOOK_VALIDATE_PC()
#endif /* FIH_ENABLE_DOUBLE_VARS */


/* Declaration of required symbols for IAR inline assembler */
#define PLATFORM_HARD_FAULT_HANDLER_HOOK_IAR_REQUIRED \
_Pragma("required = ifx_arch_switch_protection_context")

/*
 * \brief HardFault handler is used to perform Protection Context switching
 *
 * Validate that it has been called by \ref ifx_arch_switch_protection_context_thread
 * with arguments prepared by \ref ifx_arch_switch_protection_context.
 * \ref ifx_arch_switch_protection_context is called with New PC (from stack) if validation
 * is passed to switch Protection Context and exit to the original code.
 *
 * It's expected that call stack has following format (\ref ifx_arch_switch_protection_context):
 * 8 - bytes saved PC, 0x20 - stack frame, 8 - stack seal
 * Saved PC by common exception handler:
 *      + 0x00 - Active PC
 *      + 0x04 - Saved PC
 * Exception stack frame:
 *      + 0x08 - New PC
 *      + 0x0C - FIH new PC/R1
 *      + 0x10 - CONTROL
 *      + 0x14 - SP + 0x30 pointing to the end of used stack
 *      + 0x18 - R12
 *      + 0x1C - LR
 *      + 0x20 - PC - must be ifx_arch_switch_protection_context_thread
 *      + 0x24 - XPSR
 * Stack seal:
 *      + 0x28 - FEF5EDA5
 *      + 0x2C - FEF5EDA5
 */
#define PLATFORM_HARD_FAULT_HANDLER_HOOK() \
        __ASM volatile(                                     \
            /* Validate exception return code */ \
            "mov    r3, #0xFFFFFFF9                         \n" \
            "cmp    lr, r3                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Validate HardFault Status Register (HFSR) */ \
            "ldr    r3, =0xE000ED2C                         \n" \
            "ldr    r3, [r3]                                \n" \
            "cmp    r3, #0x40000000                         \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Validate UsageFault Status Register (UFSR) == 1 (UNDEFINSTR) */ \
            "ldr    r3, =0xE000ED2A                         \n" \
            "ldrb   r3, [r3]                                \n" \
            "cmp    r3, #1                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Validate stack (see \ref ifx_arch_switch_protection_context) */ \
            "ldr    r3, =" M2S(REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base)) " \n" \
            "cmp    sp, r3                                  \n" \
            "blt    _platform_hard_fault_handler_continue   \n" \
            "ldr    r3, =" M2S(REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Limit)) " + (-8 -0x20 - 8)\n" \
            "cmp    sp, r3                                  \n" \
            "bgt    _platform_hard_fault_handler_continue   \n" \
            /* SP + 0x30 (frame size) == Saved SP[0x14] */ \
            "ldr    r2, [sp, #0x14]                         \n" \
            "sub    r2, #0x30                               \n" \
            "cmp    r2, r3                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Test stack seal */ \
            "ldr    r3, ="M2S(STACK_SEAL_PATTERN)"          \n" \
            "ldr    r2, [sp, #0x28]                         \n" \
            "cmp    r2, r3                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            "ldr    r2, [sp, #0x2C]                         \n" \
            "cmp    r2, r3                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Test return address, ignore lower bit */ \
            "ldr    r3, =ifx_arch_switch_protection_context_thread \n" \
            "ldr    r2, [sp, #0x20]                         \n" \
            "eor    r3, r2                                  \n" \
            "bics   r3, #1                                  \n" \
            "bne    _platform_hard_fault_handler_continue   \n" \
            /* Test new PC, it's expected that it will be great than PC for SPM */ \
            "ldr    r0, [sp, #0x08]                         \n" \
            "cmp    r0, #"M2S(IFX_PC_TFM_SPM_ID)"           \n" \
            "ble    _platform_hard_fault_handler_continue   \n" \
            /* Validate new PC with FIH */ \
            /* This macro load FIH mask for FIH double vars into R1 */ \
            PLATFORM_HARD_FAULT_HANDLER_HOOK_VALIDATE_PC() \
            /* Load saved CONTROL and restore CONTROL.nPRIV */ \
            "ldr    r2, [sp, #0x10]                         \n" \
            "mrs    r3, control                             \n" \
            "and    r2, #1                                  \n" \
            "bic    r3, #1                                  \n" \
            "orr    r3, r2                                  \n" \
            "msr    control, r3                             \n" \
            /* Load LR */ \
            "ldr    lr, [sp, #0x1C]                         \n" \
            /* Drop frame */ \
            "add    r3, sp, #0x30                           \n" \
            "mov    sp, r3                                  \n" \
            /* Call switch PC function for SVC that will do the switching */ \
            "b.w    ifx_arch_switch_protection_context      \n" \
"_platform_hard_fault_handler_continue:                     \n" \
            /* Continue default HardFault handler */ \
        )

#endif /* TFM_PLATFORM_ARCH_HOOKS_H */

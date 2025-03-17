/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_ARCH_V6M_V7M_H__
#define __TFM_ARCH_V6M_V7M_H__

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "cmsis_compiler.h"
#include "utilities.h"

#if !TFM_MULTI_CORE_TOPOLOGY
#error "Armv6-M/Armv7-M can only support multi-core TF-M now."
#endif

extern uint32_t psp_limit;

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define EXC_RETURN_FTYPE                        (1 << 4)
#endif

/* Exception return behavior */

/* stack pointer used to restore context: 0=MSP 1=PSP. */
#define EXC_RETURN_SPSEL                        (1UL << 2)
/* processor mode for return: 0=Handler mode 1=Thread mod. */
#define EXC_RETURN_MODE                         (1UL << 3)

/* Exception numbers */
#define EXC_NUM_THREAD_MODE                     (0)
#define EXC_NUM_SVCALL                          (11)
#define EXC_NUM_PENDSV                          (14)

#define SCB_ICSR_ADDR                           (0xE000ED04)
#define SCB_ICSR_PENDSVSET_BIT                  (0x10000000)

/**
 * \brief Check whether Secure or Non-secure stack is used to restore stack
 *        frame on exception return.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval true             Always return to Secure stack on secure core in
 *                          multi-core topology.
 */
__STATIC_INLINE bool is_return_secure_stack(uint32_t lr)
{
    (void)lr;

    return true;
}

/**
 * \brief Check whether the default stacking rules apply, or whether the
 *        Additional state context, also known as callee registers,
 *        are already on the stack.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval true             Always use default stacking rules on
 *                          v6m/v7m architectures.
 */
__STATIC_INLINE bool is_default_stacking_rules_apply(uint32_t lr)
{
    (void)lr;

    return true;
}

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/**
 * \brief Check whether the stack frame for this exception has space allocated
 *        for Floating Point(FP) state information.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval true             The stack allocates space for FP information
 * \retval false            The stack doesn't allocate space for FP information
 */
__STATIC_INLINE bool is_stack_alloc_fp_space(uint32_t lr)
{
    return (lr & EXC_RETURN_FTYPE) ? false : true;
}
#elif defined(__ARM_ARCH_6M__)
/**
 * \brief Check whether the stack frame for this exception has space allocated
 *        for Floating Point(FP) state information.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval false            The stack doesn't allocate space for FP information
 */
__STATIC_INLINE bool is_stack_alloc_fp_space(uint32_t lr)
{
    (void)lr;

    return false;
}
#endif

/**
 * \brief Get PSP Limit.
 *
 * \retval psp limit        Limit of PSP stack.
 */
__STATIC_INLINE uint32_t tfm_arch_get_psplim(void)
{
    return psp_limit;
}

/**
 * \brief Set PSP limit value.
 *
 * \param[in] psplim        PSP limit value to be written.
 */
__STATIC_INLINE void tfm_arch_set_psplim(uint32_t psplim)
{
    psp_limit = psplim;
}

/**
 * \brief Set MSP limit value.
 *
 * \param[in] msplim        MSP limit value to be written.
 */
__STATIC_INLINE void tfm_arch_set_msplim(uint32_t msplim)
{
    /*
     * Defined as an empty function now.
     * The MSP limit value can be used in more strict memory check.
     */
    (void)msplim;
}

/**
 * \brief Seal the thread stack.
 *
 * \param[in] stk        Thread stack address.
 *
 * \retval stack         Updated thread stack address.
 */
__STATIC_INLINE uintptr_t arch_seal_thread_stack(uintptr_t stk)
{
    assert((stk & 0x7) == 0);
    return stk;
}

/**
 * \brief Check MSP sealing.
 */
__STATIC_INLINE void tfm_arch_check_msp_sealing(void)
{
}

/*
 * Update thread stack to architecture registers.
 * The stack 'bottom' is higher address in this architecture,
 * and 'toplimit' is the limit of top which is lower address.
 */
__STATIC_INLINE void arch_update_process_sp(uint32_t bottom,
                                            uint32_t toplimit)
{
    __set_PSP(bottom);
    psp_limit = toplimit;
    __ISB();
}

/**
 * \brief Empty implementation for branch protection.
 *        PACBTI applies for v8.1M Main Extension onwards.
 */
__STATIC_INLINE void tfm_arch_config_branch_protection(void)
{
}

#endif /* __TFM_ARCH_V6M_V7M_H__ */

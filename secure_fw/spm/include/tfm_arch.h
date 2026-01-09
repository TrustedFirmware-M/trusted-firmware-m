/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_ARCH_H__
#define __TFM_ARCH_H__

/* This header file collects the architecture related operations. */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>
#include "fih.h"
#include "tfm_hal_device_header.h"
#include "cmsis_compiler.h"

#if defined(__ARM_ARCH_8_1M_MAIN__) || \
    defined(__ARM_ARCH_8M_MAIN__)  || defined(__ARM_ARCH_8M_BASE__)
#include "tfm_arch_v8m.h"
#elif defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_7M__) || \
      defined(__ARM_ARCH_7EM__)
#include "tfm_arch_v6m_v7m.h"
#else
#error "Unsupported ARM Architecture."
#endif

#define SCHEDULER_ATTEMPTED 2 /* Schedule attempt when scheduler is locked. */
#define SCHEDULER_LOCKED    1
#define SCHEDULER_UNLOCKED  0

#define XPSR_T32            0x01000000

/* Define IRQ level */
#if defined(__ARM_ARCH_8_1M_MAIN__) || defined(__ARM_ARCH_8M_MAIN__)
#define SecureFault_IRQnLVL      (0)
#define MemoryManagement_IRQnLVL (0)
#define BusFault_IRQnLVL         (0)
#define SVCall_IRQnLVL           (0)
#elif defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define MemoryManagement_IRQnLVL (0)
#define BusFault_IRQnLVL         (0)
#define SVCall_IRQnLVL           (0)
#elif defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_8M_BASE__)
#define SVCall_IRQnLVL           (0)
#else
#error "Unsupported ARM Architecture."
#endif


/* The lowest secure interrupt priority */
#ifdef CONFIG_TFM_USE_TRUSTZONE
/* IMPORTANT NOTE:
 *
 * Although the priority of the secure PendSV must be the lowest possible
 * among other interrupts in the Secure state, it must be ensured that
 * PendSV is not preempted nor masked by Non-Secure interrupts to ensure
 * the integrity of the Secure operation.
 * When AIRCR.PRIS is set, the Non-Secure execution can act on
 * FAULTMASK_NS, PRIMASK_NS or BASEPRI_NS register to boost its priority
 * number up to the value 0x80.
 * For this reason, set the priority of the PendSV interrupt to the next
 * priority level configurable on the platform, just below 0x80.
 */
#define PENDSV_PRIO_FOR_SCHED ((1 << (__NVIC_PRIO_BITS - 1)) - 1)

#if CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1
#if (!defined(__ARM_ARCH_8_1M_MAIN__)) && (!defined(__ARM_ARCH_8M_MAIN__))
#error CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT is not supported in Baseline implementations
#endif /* (!defined(__ARM_ARCH_8_1M_MAIN__)) && (!defined(__ARM_ARCH_8M_MAIN__)) */
/* IMPORTANT NOTE:
 *
 * When AIRCR.PRIS is set, the Non-Secure execution can act on
 * FAULTMASK_NS, PRIMASK_NS or BASEPRI_NS register to boost its priority
 * number up to the value 0x80. To mask NS interrupts in secure thread
 * execution, set the priority of Secure thread mode execution to this value.
 */
#define SECURE_THREAD_EXECUTION_PRIORITY 0x80
#endif /* CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT == 1 */
#else /* CONFIG_TFM_USE_TRUSTZONE */
/* If TZ is not in use, we have the full priority range available */
#define PENDSV_PRIO_FOR_SCHED ((1 << __NVIC_PRIO_BITS) - 1)
#endif /* CONFIG_TFM_USE_TRUSTZONE */

/* State context defined by architecture */
struct tfm_state_context_t {
    uint32_t    r0;
    uint32_t    r1;
    uint32_t    r2;
    uint32_t    r3;
    uint32_t    r12;
    uint32_t    lr;
    uint32_t    ra;
    uint32_t    xpsr;
};

/* Context addition to state context */
struct tfm_additional_context_t {
    uint32_t    integ_sign;    /* Integrity signature */
    uint32_t    reserved;      /* Reserved */
    uint32_t    callee[8];     /* R4-R11. NOT ORDERED!! */
};

#if (CONFIG_TFM_FLOAT_ABI >= 1)
#if defined(__ARM_ARCH_8_1M_MAIN__) || defined(__ARM_ARCH_8M_MAIN__)
struct tfm_fpu_context_t {
    uint32_t    s16_s31[16];   /* S16-S31 */
};
#define TFM_FPU_CONTEXT             struct tfm_fpu_context_t
#endif /* defined(__ARM_ARCH_8_1M_MAIN__) || defined(__ARM_ARCH_8M_MAIN__) */
#endif /* CONFIG_TFM_FLOAT_ABI */

#ifdef TFM_FPU_CONTEXT
#define TFM_FPU_CONTEXT_SIZE        sizeof(TFM_FPU_CONTEXT)
#else
#define TFM_FPU_CONTEXT_SIZE        0
#endif

/* Full thread context */
struct full_context_t {
    struct tfm_additional_context_t addi_ctx;
#ifdef TFM_FPU_CONTEXT
    TFM_FPU_CONTEXT                 fpu_ctx;
#endif
    struct tfm_state_context_t      stat_ctx;
};

/* Context control.
 * CAUTION: Assembly references this structure. DO CHECK the below functions
 * before changing the structure:
       'PendSV_Handler'
 */
struct context_ctrl_t {
    uint32_t                sp;           /* Stack pointer (higher address).
                                           * THIS MUST BE THE FIRST MEMBER OF
                                           * THE STRUCT.
                                           */
    uint32_t                exc_ret;      /* EXC_RETURN pattern.
                                           * THIS MUST BE THE SECOND MEMBER OF
                                           * THE STRUCT.
                                           */
    uint32_t                sp_limit;     /* Stack limit (lower address)     */
    uint32_t                sp_base;      /* Stack usage start (higher addr) */
};

/*
 * The context on MSP when de-privileged FLIH Function calls SVC to return.
 * It is the same when de-privileged FLIH Function is ready to run.
 */
struct context_flih_ret_t {
    uint64_t stack_seal;                  /* Two words stack seal                              */
    struct tfm_additional_context_t addi_ctx;
#ifdef TFM_FPU_CONTEXT
    TFM_FPU_CONTEXT fpu_ctx;
#endif
    uint32_t exc_return;                  /* exception return value on SVC_PREPARE_DEPRIV_FLIH */
    uint32_t dummy;                       /* dummy value for 8 bytes aligned                   */
    uint32_t psp;                         /* PSP when interrupt exception occurs               */
    uint32_t psplim;                      /* PSPLIM when interrupt exception occurs when       */
    struct tfm_state_context_t state_ctx; /* ctx on SVC_PREPARE_DEPRIV_FLIH                    */
};

/* Assign stack and stack limit to the context control instance. */
#define ARCH_CTXCTRL_INIT(x, buf, sz) do {                                   \
            (x)->sp             = ((uint32_t)(buf) + (uint32_t)(sz)) & ~0x7; \
            (x)->sp_limit       = ((uint32_t)(buf) + 7) & ~0x7;              \
            (x)->sp_base        = (x)->sp;                                   \
            (x)->exc_ret        = 0;                                         \
        } while (0)

/* Allocate 'size' bytes in stack. */
#define ARCH_CTXCTRL_ALLOCATE_STACK(x, size) do { \
            assert(size <= ((x)->sp - (x)->sp_limit)); \
            ((x)->sp -= ((size) + 7) & ~0x7); \
        } while (0)

/* The last allocated pointer. */
#define ARCH_CTXCTRL_ALLOCATED_PTR(x)         ((x)->sp)

/* Prepare an exception return pattern on the stack. */
#define ARCH_CTXCTRL_EXCRET_PATTERN(x, param0, param1, param2, param3, pfn, pfnlr) do { \
            (x)->r0 = (uint32_t)(param0);                                 \
            (x)->r1 = (uint32_t)(param1);                                 \
            (x)->r2 = (uint32_t)(param2);                                 \
            (x)->r3 = (uint32_t)(param3);                                 \
            (x)->ra = (uint32_t)(pfn);                                    \
            (x)->lr = (uint32_t)(pfnlr);                                  \
            (x)->xpsr = XPSR_T32;                                         \
        } while (0)

/* Set state context parameter r0. */
#define ARCH_STATE_CTX_SET_R0(x, r0_val)                                  \
            ((x)->r0             = (uint32_t)(r0_val))

/*
 * Claim a statically initialized context control instance.
 * Make the start stack pointer at 'stack_buf[stack_size]' because
 * the hardware acts in a 'Decrease-then-store' behaviour.
 */
#define ARCH_CLAIM_CTXCTRL_INSTANCE(name, stack_buf, stack_size)          \
            struct context_ctrl_t name = {                                \
                .sp        = (uint32_t)&stack_buf[stack_size],            \
                .sp_base   = (uint32_t)&stack_buf[stack_size],            \
                .sp_limit  = (uint32_t)stack_buf,                         \
                .exc_ret   = 0,                                           \
            }

__STATIC_INLINE uint32_t __save_disable_irq(void)
{
    uint32_t result;

    __ASM volatile ("mrs %0, primask \n cpsid i" : "=r" (result) :: "memory");
    return result;
}

__STATIC_INLINE void __restore_irq(uint32_t status)
{
    __ASM volatile ("msr primask, %0" :: "r" (status) : "memory");
}

__attribute__ ((always_inline))
__STATIC_INLINE uint32_t __get_active_exc_num(void)
{
    IPSR_Type IPSR;

    /* if non-zero, exception is active. NOT banked S/NS */
    IPSR.w = __get_IPSR();
    return IPSR.b.ISR;
}

__attribute__ ((always_inline))
__STATIC_INLINE void __set_CONTROL_nPRIV(uint32_t nPRIV)
{
    CONTROL_Type ctrl;

    ctrl.w = __get_CONTROL();
    ctrl.b.nPRIV = nPRIV;
    __set_CONTROL(ctrl.w);
    __ISB();
}

/**
 * \brief Whether in privileged level
 *
 * \retval true             If current execution runs in privileged level.
 * \retval false            If current execution runs in unprivileged level.
 */
__STATIC_INLINE bool tfm_arch_is_priv(void)
{
    CONTROL_Type ctrl;

    /* If in Handler mode */
    if (__get_IPSR()) {
        return true;
    }

    /* If in privileged Thread mode */
    ctrl.w = __get_CONTROL();
    if (!ctrl.b.nPRIV) {
        return true;
    }

    return false;
}

#if (CONFIG_TFM_FLOAT_ABI >= 1) && CONFIG_TFM_LAZY_STACKING
#define ARCH_FLUSH_FP_CONTEXT()  __asm volatile("vmov.f32  s0, s0 \n":::"memory")
#else
#define ARCH_FLUSH_FP_CONTEXT()
#endif

/* Set secure exceptions priority. */
void tfm_arch_set_secure_exception_priorities(void);

#ifdef TFM_FIH_PROFILE_ON
/* Check secure exception priority */
FIH_RET_TYPE(int32_t) tfm_arch_verify_secure_exception_priorities(void);
#endif

/* Configure various extensions. */
void tfm_arch_config_extensions(void);

#if (CONFIG_TFM_FLOAT_ABI > 0)
/* Clear float point data. */
void tfm_arch_clear_fp_data(void);
#endif

/*
 * This function is called after SPM has initialized.
 * It frees the stack used by SPM initialization and do Exception Return.
 * It does not return.
 */
void tfm_arch_free_msp_and_exc_ret(uint32_t msp_base, uint32_t exc_return);

/*
 * This function sets return value on APIs that cause scheduling, for example
 * psa_wait(), by manipulating the control context - this is usaully setting the
 * R0 register of the thread context.
 */
void tfm_arch_set_context_ret_code(const struct context_ctrl_t *p_ctx_ctrl, uint32_t ret_code);

/* Init a thread context on thread stack and update the control context. */
void tfm_arch_init_context(struct context_ctrl_t *p_ctx_ctrl,
                           uintptr_t pfn, void *param, uintptr_t pfnlr);

/*
 * Refresh the HW (sp, splimit) according to the given control context and
 * returns the EXC_RETURN payload (caller might need it for following codes).
 *
 * The p_ctx_ctrl must have been initialized by 'tfm_arch_init_context'.
 */
uint32_t tfm_arch_refresh_hardware_context(const struct context_ctrl_t *p_ctx_ctrl);

/*
 * Lock the scheduler. Any scheduling attempt during locked period will not
 * take place and is recorded.
 */
void arch_acquire_sched_lock(void);

/*
 * Release the scheduler lock and return if there are scheduling attempts during
 * locked period. The recorded attempts are cleared after this function so do
 * not call it a second time after unlock to query attempt status.
 *
 * return value:
 *   SCHEDULER_ATTEMPTED: unlocked successfully but there are recorded attempts
 *                        or function get called without locked.
 *   other values:        unlocked successfully without attempts detected.
 */
uint32_t arch_release_sched_lock(void);

/*
 * Try to schedule if scheduler is not locked, otherwise record the schedule
 * attempt and return without scheduling.
 */
uint32_t arch_attempt_schedule(void);

/*
 * Thread Function Call at Thread mode. It is called in the IPC backend and
 * isolation level 1. The function switches to the SPM stack to execute the
 * target PSA API to avoid using up the Secure Partitions' stacks. The NS agent
 * shares the stack with the SPM so it doesn't need to switch.
 *
 * The stack check process destroys the caller registers so the input args and
 * the target PSA API address are stored in the caller stack at the beginning.
 * They are loaded again before the PSA API is called. This function is
 * non-preemptive except for the target PSA API execution.
 *
 * NOTE: This function cannot be called by any C functions as it uses a
 * customized parameter passing method and puts the target function address in
 * r12. These input parameters a0~a3 come from standard PSA interface input.
 * The return value is stored in r0 for the PSA API to return.
 */
void tfm_arch_thread_fn_call(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3);

/*
 * Reset MSP to msp_base.
 * Use PSP as the current stack in Thread mode.
 * Execute two init functions in turn.
 */
void arch_clean_stack_and_launch(void *param, uintptr_t spm_init_func,
                                 uintptr_t ns_agent_entry, uint32_t msp_base);

#endif

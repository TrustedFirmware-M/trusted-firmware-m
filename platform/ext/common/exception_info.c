/*
 * Copyright (c) 2021, Nordic Semiconductor ASA. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include "tfm_arch.h"
#include "tfm_log.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

static struct exception_info_t exception_info;

/**
 * \brief Check whether the exception was triggered in thread or handler mode.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval true             The exception will return to thread mode.
 */
__STATIC_INLINE bool is_return_thread_mode(uint32_t lr)
{
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    return !((lr == EXC_RETURN_HANDLER) || (lr == EXC_RETURN_HANDLER_FPU));
#elif defined(__ARM_ARCH_8M_BASE__) || defined(__ARM_ARCH_8M_MAIN__) \
        || defined(__ARM_ARCH_8_1M_MAIN__)
    return (lr & EXC_RETURN_MODE);
#else
    return !(lr == EXC_RETURN_HANDLER);
#endif
}

/**
 * \brief Check whether the PSP or MSP is used to restore stack frame on
 *        exception return.
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 *
 * \retval true             The exception frame is on the PSP
 */
__STATIC_INLINE bool is_return_psp(uint32_t lr)
{
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    return ((lr == EXC_RETURN_THREAD_PSP) || (lr == EXC_RETURN_THREAD_PSP_FPU));
#elif defined(__ARM_ARCH_8M_BASE__) || defined(__ARM_ARCH_8M_MAIN__) \
        || defined(__ARM_ARCH_8_1M_MAIN__)
    if (is_return_secure_stack(lr)) {
        /* PSP is used only if SPSEL is set, and we came from thread mode. */
        return ((lr & EXC_RETURN_SPSEL) && is_return_thread_mode(lr));
    } else {
        /* PSP is used only if CONTROL_NS.SPSEL is set, and we came from thread mode. */
        bool sp_sel = _FLD2VAL(CONTROL_SPSEL, __TZ_get_CONTROL_NS()) != 0;
        return (sp_sel && is_return_thread_mode(lr));
    }
#else
    return (lr == EXC_RETURN_THREAD_PSP);
#endif
}

/**
 * \brief Get a pointer to the current exception frame
 *
 * \param[in] lr            LR register containing the EXC_RETURN value.
 * \param[in] msp           The MSP at the start of the exception handler.
 * \param[in] psp           The PSP at the start of the exception handler.
 *
 * \return  A pointer to the current exception frame.
 */
__STATIC_INLINE
uint32_t *get_exception_frame(uint32_t lr, uint32_t msp, uint32_t psp)
{
#if defined(__ARM_ARCH_8M_BASE__) || defined(__ARM_ARCH_8M_MAIN__) \
        || defined(__ARM_ARCH_8_1M_MAIN__)
    bool is_psp = is_return_psp(lr);

    return (uint32_t *)(is_return_secure_stack(lr)
                        ? (is_psp ? psp : msp)
                        : (is_psp ? __TZ_get_PSP_NS() : __TZ_get_MSP_NS()));
#else
    return (uint32_t *)(is_return_psp(lr) ? psp : msp);
#endif
}

static void dump_exception_info(bool stack_error,
                                const struct exception_info_t *ctx)
{
    VERBOSE_RAW("Here is some context for the exception:\n");
    VERBOSE_RAW("    EXC_RETURN (LR): 0x%08x\n", ctx->EXC_RETURN);
    VERBOSE_RAW("    Exception came from");
#ifdef TRUSTZONE_PRESENT
    if (is_return_secure_stack(ctx->EXC_RETURN)) {
        VERBOSE_RAW(" secure FW in");
    } else {
        VERBOSE_RAW(" non-secure FW in");
    }
#endif

    if (is_return_thread_mode(ctx->EXC_RETURN)) {
        VERBOSE_RAW(" thread mode.\n");
    } else {
        VERBOSE_RAW(" handler mode.\n");
    }
    VERBOSE_RAW("    xPSR:    0x%08x\n", ctx->xPSR);
    VERBOSE_RAW("    MSP:     0x%08x\n", ctx->MSP);
    VERBOSE_RAW("    PSP:     0x%08x\n", ctx->PSP);
#ifdef TRUSTZONE_PRESENT
    VERBOSE_RAW("    MSP_NS:  0x%08x\n", __TZ_get_MSP_NS());
    VERBOSE_RAW("    PSP_NS:  0x%08x\n", __TZ_get_PSP_NS());
#endif

    VERBOSE_RAW("    Exception frame at:   0x%08x\n", (uint32_t)ctx->EXC_FRAME);
    if (stack_error) {
        VERBOSE_RAW(
            "       (Note that the exception frame may be corrupted for this type of error.)\r\n");
    }
    VERBOSE_RAW("        R0:   0x%08x\n", ctx->EXC_FRAME_COPY[0]);
    VERBOSE_RAW("        R1:   0x%08x\n", ctx->EXC_FRAME_COPY[1]);
    VERBOSE_RAW("        R2:   0x%08x\n", ctx->EXC_FRAME_COPY[2]);
    VERBOSE_RAW("        R3:   0x%08x\n", ctx->EXC_FRAME_COPY[3]);
    VERBOSE_RAW("        R12:  0x%08x\n", ctx->EXC_FRAME_COPY[4]);
    VERBOSE_RAW("        LR:   0x%08x\n", ctx->EXC_FRAME_COPY[5]);
    VERBOSE_RAW("        PC:   0x%08x\n", ctx->EXC_FRAME_COPY[6]);
    VERBOSE_RAW("        xPSR: 0x%08x\n", ctx->EXC_FRAME_COPY[7]);

    VERBOSE_RAW("    Callee saved register state:\n");
    VERBOSE_RAW("        R4:   0x%08x\n", ctx->CALLEE_SAVED_COPY[0]);
    VERBOSE_RAW("        R5:   0x%08x\n", ctx->CALLEE_SAVED_COPY[1]);
    VERBOSE_RAW("        R6:   0x%08x\n", ctx->CALLEE_SAVED_COPY[2]);
    VERBOSE_RAW("        R7:   0x%08x\n", ctx->CALLEE_SAVED_COPY[3]);
    VERBOSE_RAW("        R8:   0x%08x\n", ctx->CALLEE_SAVED_COPY[4]);
    VERBOSE_RAW("        R9:   0x%08x\n", ctx->CALLEE_SAVED_COPY[5]);
    VERBOSE_RAW("        R10:  0x%08x\n", ctx->CALLEE_SAVED_COPY[6]);
    VERBOSE_RAW("        R11:  0x%08x\n", ctx->CALLEE_SAVED_COPY[7]);

#ifdef FAULT_STATUS_PRESENT
    VERBOSE_RAW("    CFSR:  0x%08x\n", ctx->CFSR);
    VERBOSE_RAW("    BFSR:  0x%02x",
                    (ctx->CFSR & SCB_CFSR_BUSFAULTSR_Msk) >> SCB_CFSR_BUSFAULTSR_Pos);
    if (ctx->BFARVALID) {
        VERBOSE_RAW("    BFAR: 0x%08x\n", ctx->BFAR);
    } else {
        VERBOSE_RAW("    BFAR:  Not Valid\n");
    }
    VERBOSE_RAW("    MMFSR: 0x%02x",
                    (ctx->CFSR & SCB_CFSR_MEMFAULTSR_Msk) >> SCB_CFSR_MEMFAULTSR_Pos);
    if (ctx->MMARVALID) {
        VERBOSE_RAW("    MMFAR: 0x%08x\n", ctx->MMFAR);
    } else {
        VERBOSE_RAW("    MMFAR: Not Valid\n");
    }
    VERBOSE_RAW("    UFSR:  0x%08x\n",
                    (ctx->CFSR & SCB_CFSR_USGFAULTSR_Msk) >> SCB_CFSR_USGFAULTSR_Pos);
    VERBOSE_RAW("    HFSR:  0x%08x\n", ctx->HFSR);
#ifdef TRUSTZONE_PRESENT
    VERBOSE_RAW("    SFSR:  0x%08x\n", ctx->SFSR);
    if (ctx->SFARVALID) {
        VERBOSE_RAW("    SFAR: 0x%08x\n", ctx->SFAR);
    } else {
        VERBOSE_RAW("    SFAR: Not Valid\n");
    }
#endif

#endif
}

static void dump_error(const struct exception_info_t *ctx)
{
    bool stack_error = false;

    ERROR_RAW("FATAL ERROR: ");
    switch (ctx->VECTACTIVE) {
    case EXCEPTION_TYPE_HARDFAULT:
        ERROR_RAW("HardFault\n");
        break;
#ifdef FAULT_STATUS_PRESENT
    case EXCEPTION_TYPE_MEMMANAGEFAULT:
        ERROR_RAW("MemManage fault\n");
        stack_error = true;
        break;
    case EXCEPTION_TYPE_BUSFAULT:
        ERROR_RAW("BusFault\n");
        stack_error = true;
        break;
    case EXCEPTION_TYPE_USAGEFAULT:
        ERROR_RAW("UsageFault\n");
        stack_error = true;
        break;
#ifdef TRUSTZONE_PRESENT
    case EXCEPTION_TYPE_SECUREFAULT:
        ERROR_RAW("SecureFault\n");
        break;
#endif
#endif
    /* Platform specific external interrupt secure handler. */
    default:
        if (ctx->VECTACTIVE < 16) {
            ERROR_RAW("Reserved Exception 0x%08x\n", ctx->VECTACTIVE);
        } else {
            ERROR_RAW("Platform external interrupt (IRQn): 0x%08x\n", ctx->VECTACTIVE - 16);
        }
        /* Depends on the platform, assume it may cause stack error */
        stack_error = true;
        break;
    }

    dump_exception_info(stack_error, ctx);
}

void tfm_exception_info_get_context(struct exception_info_t *ctx)
{
    memcpy(ctx, &exception_info, sizeof(exception_info));
}

void store_and_dump_context(uint32_t MSP_in, uint32_t PSP_in, uint32_t LR_in,
                            uint32_t *callee_saved)
{
    struct exception_info_t *ctx = &exception_info;

    ctx->VECTACTIVE = SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk;
    ctx->xPSR = __get_xPSR();
    ctx->EXC_RETURN = LR_in;
    ctx->MSP = MSP_in;
    ctx->PSP = PSP_in;
    ctx->EXC_FRAME = get_exception_frame(ctx->EXC_RETURN, ctx->MSP, ctx->PSP);
    memcpy(ctx->EXC_FRAME_COPY, ctx->EXC_FRAME, sizeof(ctx->EXC_FRAME_COPY));

    if (callee_saved) {
        memcpy(ctx->CALLEE_SAVED_COPY, callee_saved, sizeof(ctx->CALLEE_SAVED_COPY));
    }

#ifdef FAULT_STATUS_PRESENT
    ctx->CFSR = SCB->CFSR;
    ctx->HFSR = SCB->HFSR;
    ctx->BFAR = SCB->BFAR;
    ctx->BFARVALID = ctx->CFSR & SCB_CFSR_BFARVALID_Msk;
    ctx->MMFAR = SCB->MMFAR;
    ctx->MMARVALID = ctx->CFSR & SCB_CFSR_MMARVALID_Msk;
    SCB->CFSR = ctx->CFSR; /* Clear bits. CFSR is write-one-to-clear. */
    SCB->HFSR = ctx->HFSR; /* Clear bits. HFSR is write-one-to-clear. */
#ifdef TRUSTZONE_PRESENT
    ctx->SFSR = SAU->SFSR;
    ctx->SFAR = SAU->SFAR;
    ctx->SFARVALID = ctx->SFSR & SAU_SFSR_SFARVALID_Msk;
    SAU->SFSR = ctx->SFSR; /* Clear bits. SFSR is write-one-to-clear. */
#endif
#endif

    dump_error(ctx);
}

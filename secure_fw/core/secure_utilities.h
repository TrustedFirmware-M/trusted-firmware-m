/*
 * Copyright (c) 2017-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SECURE_UTILITIES_H__
#define __SECURE_UTILITIES_H__

#include <stdio.h>
#include "cmsis_compiler.h"
#include "tfm_svc.h"

#define EXC_NUM_THREAD_MODE     (0)
#define EXC_NUM_SVCALL          (11)
#define EXC_NUM_PENDSV          (14)
#define EXC_NUM_SYSTICK         (15)

struct tfm_exc_stack_t {
    uint32_t R0;
    uint32_t R1;
    uint32_t R2;
    uint32_t R3;
    uint32_t R12;
    uint32_t LR;
    uint32_t RetAddr;
    uint32_t XPSR;
};

#ifdef TFM_CORE_DEBUG
#define LOG_MSG_HDLR(MSG) printf("[Sec Handler] %s\r\n", MSG)
#else
/* FixMe: redirect to secure log area */
#define LOG_MSG_HDLR(MSG) printf("[Sec Handler] %s\r\n", MSG)
#endif

#define LOG_MSG_THR(MSG) \
            __ASM volatile("MOV r0, %0\n" \
                           "SVC %1\n" \
                           : : "r" (MSG), "I" (TFM_SVC_PRINT))

#define LOG_MSG(MSG) \
            do { \
                if (__get_active_exc_num()) { \
                    LOG_MSG_HDLR(MSG); \
                } else { \
                    LOG_MSG_THR(MSG); \
                } \
            } while (0)

#ifdef TFM_CORE_DEBUG
#define ERROR_MSG(MSG) printf("[Sec Error] %s\r\n", MSG)
#else
/* FixMe: redirect to secure log area */
#define ERROR_MSG(MSG) printf("[Sec Error] %s\r\n", MSG)
#endif

#endif /* __SECURE_UTILITIES_H__ */

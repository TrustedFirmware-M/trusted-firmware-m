/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <stdint.h>

#include "security_defs.h"
#include "tfm_arch.h"
#include "tfm_hal_platform.h"

#include "compiler_ext_defs.h" /* Keep last. */

__naked void ns_agent_tz_main(uint32_t c_entry)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        "   ldr      r2, [sp]                       \n"
        "   ldr      r3, ="M2S(STACK_SEAL_PATTERN)" \n" /* SEAL double-check */
        "   cmp      r2, r3                         \n"
        "   bne      ns_agent_nspe_jump_panic       \n"
#if (CONFIG_TFM_FLOAT_ABI > 0)
/* IAR throws an error if the S0-S31 syntax is used.
 * Splitting the command into two parts solved the issue.
 */
#if defined(__ICCARM__)
        "   vscclrm  {S0-S30, VPR}                  \n"
        "   vscclrm  {S31, VPR}                     \n"
#else
        "   vscclrm  {S0-S31, VPR}                  \n"
#endif
        "   mov      r1, #0                         \n"
        "   vmsr     fpscr_nzcvqc, r1               \n"
        "   mrs      r1, control                    \n"
        "   bic      r1, r1, #4                     \n"
        "   msr      control, r1                    \n"
        "   isb                                     \n"
#endif
        "   clrm     {r1-r12, r14, apsr}            \n"
        "   bic      r0, r0, #1                     \n"
        "   bxns     r0                             \n"
        "ns_agent_nspe_jump_panic:                  \n"
        "   b        .                              \n"
    );
}

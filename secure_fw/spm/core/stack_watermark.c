/*
 * Copyright (c) 2022-2024, Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "ffm/backend.h"
#include "stack_watermark.h"
#include "lists.h"
#include "load/spm_load_api.h"
#include "spm.h"
#include "tfm_log.h"

/* Always output, regardless of log level.
 * If you don't want output, don't build this code
 */
#define SPMLOG(x) tfm_hal_output_spm_log((x), sizeof(x))
#define SPMLOG_VAL(x, y) spm_log_msgval((x), sizeof(x), y)

#define STACK_WATERMARK_VAL 0xdeadbeef

void watermark_spm_stack(void)
{
    uint32_t addr = SPM_THREAD_CONTEXT->sp_limit;

    while (addr < SPM_THREAD_CONTEXT->sp_base) {
        *(uint32_t *)addr = STACK_WATERMARK_VAL;
        addr += sizeof(uint32_t);
    }
}

void watermark_stack(const struct partition_t *p_pt)
{
    const struct partition_load_info_t *p_pldi = p_pt->p_ldinf;

    for (int i = 0; i < p_pldi->stack_size / sizeof(uint32_t); i++) {
        *((uint32_t *)LOAD_ALLOCED_STACK_ADDR(p_pldi) + i) = STACK_WATERMARK_VAL;
    }
}

#ifndef CONFIG_TFM_USE_TRUSTZONE
/* Returns the number of bytes of stack that have been used by SPM */
static uint32_t used_spm_stack(void)
{
    const uint32_t *p;

    for (p = (uint32_t *)(SPM_THREAD_CONTEXT->sp_limit);
         p < (uint32_t *)(SPM_THREAD_CONTEXT->sp_base);
         p++) {
        if (*p != STACK_WATERMARK_VAL) {
            break;
        }
    }

    return SPM_THREAD_CONTEXT->sp_base - (uint32_t)p;
}
#endif

/* Returns the number of bytes of stack that have been used by the specified partition */
static uint32_t used_stack(const struct partition_t *p_pt)
{
    const struct partition_load_info_t *p_pldi = p_pt->p_ldinf;
    uint32_t unused_words = 0;

    for (const uint32_t *p = (uint32_t *)LOAD_ALLOCED_STACK_ADDR(p_pldi);
         p < (uint32_t *)(LOAD_ALLOCED_STACK_ADDR(p_pldi) + p_pldi->stack_size);
         p++) {
        if (*p != STACK_WATERMARK_VAL) {
            break;
        }
        unused_words++;
    }

    return p_pldi->stack_size - (unused_words * sizeof(uint32_t));
}

void dump_used_stacks(void)
{
    const struct partition_t *p_pt;

    SPMLOG("Used stack sizes report\r\n");
#ifndef CONFIG_TFM_USE_TRUSTZONE
    /* SPM has a dedicated stack in this case */
    SPMLOG("  SPM\r\n");
    SPMLOG_VAL("    Stack bytes: ", CONFIG_TFM_SPM_THREAD_STACK_SIZE);
    SPMLOG_VAL("    Stack bytes used: ", used_spm_stack());
#endif
    UNI_LIST_FOREACH(p_pt, PARTITION_LIST_ADDR, next) {
        SPMLOG_VAL("  Partition id: ", p_pt->p_ldinf->pid);
        SPMLOG_VAL("    Stack bytes: ", p_pt->p_ldinf->stack_size);
        SPMLOG_VAL("    Stack bytes used: ", used_stack(p_pt));
    }
}

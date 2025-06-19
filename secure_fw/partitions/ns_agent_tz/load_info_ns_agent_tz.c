/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2021-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/***** WARNING: This file SHOULD BE CHANGED according to storage template *****/

#include <stdint.h>
#include <stddef.h>
#include "compiler_ext_defs.h"
#include "config_impl.h"
#include "spm.h"
#include "load/partition_defs.h"
#include "load/service_defs.h"
#include "load/asset_defs.h"
#include "load/ns_client_id_tz.h"
/* Note that region_defs.h must be included before tfm_s_linker_alignments.h
 * to let platform overwrite default alignment values.
 */
#include "region_defs.h"
#include "tfm_s_linker_alignments.h"

#define TFM_SP_NS_AGENT_NDEPS                                   (0)
#define TFM_SP_NS_AGENT_NSERVS                                  (0)
#if TFM_ISOLATION_LEVEL == 3
#define TFM_SP_NS_AGENT_NASSETS                                 (1)
#endif

/* Entrypoint function declaration */
extern void ns_agent_tz_main(uint32_t c_entry);

/* Stack */
uint8_t ns_agent_tz_stack[TFM_NS_AGENT_TZ_STACK_SIZE_ALIGNED] __aligned(TFM_LINKER_NS_AGENT_TZ_STACK_ALIGNMENT);

struct partition_tfm_sp_ns_agent_tz_load_info_t {
    /* common length load data */
    struct partition_load_info_t    load_info;
    /* per-partition variable length load data */
    uintptr_t                       stack_addr;
    uintptr_t                       heap_addr;
#if TFM_ISOLATION_LEVEL == 3
    struct asset_desc_t             assets[TFM_SP_NS_AGENT_NASSETS];
#endif
} __attribute__((aligned(4)));

/* Partition load, deps, service load data. Put to a dedicated section. */
#if defined(__ICCARM__)
/* Section priority: lowest */
#pragma location = ".part_load"
__root
#endif
const struct partition_tfm_sp_ns_agent_tz_load_info_t
    tfm_sp_ns_agent_tz_load __attribute__((used, section(".part_load"))) = {
    .load_info = {
        .psa_ff_ver                 = 0x0100 | PARTITION_INFO_MAGIC,
        .pid                        = TFM_SP_TZ_AGENT,
        .flags                      = (PARTITION_PRI_LOWEST - 1)
                                    | PARTITION_MODEL_IPC
                                    | PARTITION_MODEL_PSA_ROT
                                    | PARTITION_NS_AGENT_TZ,
        .entry                      = ENTRY_TO_POSITION(ns_agent_tz_main),
        .stack_size                 = TFM_NS_AGENT_TZ_STACK_SIZE_ALIGNED,
        .heap_size                  = 0,
        .client_id_base             = TZ_NS_CLIENT_ID_BASE,
        .client_id_limit            = TZ_NS_CLIENT_ID_LIMIT,
        .ndeps                      = TFM_SP_NS_AGENT_NDEPS,
        .nservices                  = TFM_SP_NS_AGENT_NSERVS,
#if TFM_ISOLATION_LEVEL == 3
        .nassets                    = TFM_SP_NS_AGENT_NASSETS,
#else
        .nassets                    = 0,
#endif
        .load_order                 = LOAD_ORDER_BY_PRIORITY(PARTITION_PRI_LOWEST - 1),
    },
    .stack_addr                     = (uintptr_t)ns_agent_tz_stack,
    .heap_addr                      = 0,
#if TFM_ISOLATION_LEVEL == 3
    .assets                         = {
        {
            .mem.start              = (uintptr_t)ns_agent_tz_stack,

            .mem.limit              =
               (uintptr_t)&ns_agent_tz_stack[TFM_NS_AGENT_TZ_STACK_SIZE_ALIGNED],
            .attr                   = ASSET_ATTR_READ_WRITE,
        },
    },
#endif
};
#if defined(__ICCARM__)
/* Section priority: lowest */
#pragma location = ".bss.part_runtime"
__root
#endif
/* Placeholder for partition runtime space. Do not reference it. */
static struct partition_t tfm_sp_ns_agent_tz_partition_runtime_item
    __attribute__((used, section(".bss.part_runtime")));

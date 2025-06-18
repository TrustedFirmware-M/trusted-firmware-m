/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PARTITION_DEFS_H__
#define __PARTITION_DEFS_H__

#include <stddef.h>
#include <stdint.h>

/* TF-M internal partition ID */
#define TFM_SP_IDLE                          (1U)
#define TFM_SP_TZ_AGENT                      (2U)
#define INVALID_PARTITION_ID                 (0U)

/* Encode a magic number into version for validating partition info */
#define PARTITION_INFO_VERSION_MASK             (0x0000FFFF)
#define PARTITION_INFO_MAGIC_MASK               (0xFFFF0000)
#define PARTITION_INFO_MAGIC                    (0x5F5F0000)

/*
 * Partition flag start
 *
 * 31      12 11 10  9   8  7         0
 * +---------+--+--+---+---+----------+
 * | RES[20] |TZ|MB|I/S|A/P| Priority |
 * +---------+--+--+---+---+----------+
 *
 * Field                Desc                        Value
 * Priority, bits[7:0]:  Partition Priority          Lowest, low, normal, high, highest
 *                       set in manifest.
 * A/P, bit[8]:          ARoT or PRoT domain         1: PRoT              0: ARoT
 * I/S, bit[9]:          IPC or SFN typed partition  1: IPC               0: SFN
 * MB,  bit[10]:         NS Agent Mailbox or not     1: NS Agent mailbox  0: Not
 * TZ,  bit[11]:         NS Agent TZ or not          1: NS Agent TZ       0: Not
 * RES, bits[31:12]:     20 bits reserved            0
 */
#define PARTITION_PRI_HIGHEST                   (0x0)
#define PARTITION_PRI_HIGH                      (0xF)
#define PARTITION_PRI_NORMAL                    (0x1F)
#define PARTITION_PRI_LOW                       (0x7F)
#define PARTITION_PRI_LOWEST                    (0xFF)
#define PARTITION_PRI_MASK                      (0xFF)

#define PARTITION_MODEL_PSA_ROT                 (1UL << 8)
#define PARTITION_MODEL_IPC                     (1UL << 9)

#define PARTITION_NS_AGENT_MB                   (1UL << 10)
#define PARTITION_NS_AGENT_TZ                   (1UL << 11)

#define TO_THREAD_PRIORITY(x)                   (x)

#define ENTRY_TO_POSITION(x)                    (uintptr_t)(x)
#define POSITION_TO_ENTRY(x, t)                 (t)(x)

#define PTR_TO_REFERENCE(x)                     (uintptr_t)(x)
#define REFERENCE_TO_PTR(x, t)                  (t)(x)

#define IS_PSA_ROT(pldi)                        (!!((pldi)->flags \
                                                     & PARTITION_MODEL_PSA_ROT))
#define IS_IPC_MODEL(pldi)                      (!!((pldi)->flags \
                                                     & PARTITION_MODEL_IPC))
#define IS_NS_AGENT(pldi)                       (!!((pldi)->flags \
                                                     & (PARTITION_NS_AGENT_MB | PARTITION_NS_AGENT_TZ)))
#ifdef CONFIG_TFM_USE_TRUSTZONE
#define IS_NS_AGENT_TZ(pldi)                    (!!((pldi)->flags & PARTITION_NS_AGENT_TZ))
#else
#define IS_NS_AGENT_TZ(pldi)                    ((void)pldi, false)
#endif
#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
#define IS_NS_AGENT_MAILBOX(pldi)               (!!((pldi)->flags & PARTITION_NS_AGENT_MB))
#else
#define IS_NS_AGENT_MAILBOX(pldi)               ((void)pldi, false)
#endif

#define PARTITION_TYPE_TO_INDEX(type)           (!!((type) & PARTITION_NS_AGENT_TZ))

/* Partition flag end */

/*
 * Calculate partition loading order according to its priority only.
 * Dependencies are excluded from the calculation.
 * This macro shall only be called by Secure Partition statically defined
 * without manifest file, such as idle partition and TrustZone NS Agent.
 */
#define LOAD_ORDER_BY_PRIORITY(priority)        (((uint16_t)(priority)) << 8)

/*
 * Common partition structure type, the extendable data is right after it.
 * Extendable data has different size for each partition, and must be 4-byte
 * aligned. It includes: stack and heap position, dependencies, services and
 * assets data.
 */
struct partition_load_info_t {
    uint32_t        psa_ff_ver;         /* Encode the version with magic    */
    int32_t         pid;                /* Partition ID                     */
    uint32_t        flags;              /* ARoT/PRoT, SFN/IPC, priority set
                                         * in Secure Partition manifest.
                                         */
    uintptr_t       entry;              /* Entry point                      */
    size_t          stack_size;         /* Stack size                       */
    size_t          heap_size;          /* Heap size                        */
    uint32_t        ndeps;              /* Dependency number                */
    uint32_t        nservices;          /* Service number                   */
    uint32_t        nassets;            /* Asset numbers                    */
    uint32_t        nirqs;              /* Number of IRQ owned by Partition */
    int32_t         client_id_base;     /* The min translated client ID     */
    int32_t         client_id_limit;    /* The max translated client ID     */
    uint16_t        load_order;         /* loading order of this partition
                                         * The value is calculated based on the
                                         * priority set in partition manifest
                                         * and its dependencies.
                                         * A partition with a smaller loading
                                         * order value is loaded earlier.
                                         * - A partition with a higher manifest
                                         *   priority is loaded earlier than
                                         *   those with lower priorities.
                                         * - A partition is loaded later than
                                         *   its dependencies.
                                         */
} __attribute__((aligned(4)));

#endif /* __PARTITION_DEFS_H__ */

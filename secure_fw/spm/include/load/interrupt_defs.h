/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __INTERRUPT_DEFS_H__
#define __INTERRUPT_DEFS_H__

#include <stdint.h>
#include "tfm_hal_defs.h"
#include "psa/service.h"

/* IRQ static load info */
struct irq_load_info_t {
    /*
     * Initialization function per interrupt.
     * args:  owner Partition, irq_load_info
     */
    enum tfm_hal_status_t (*init)(void *pt, const struct irq_load_info_t *pildi);
    psa_flih_result_t (*flih_func)(void);     /* FLIH function, NULL for SLIH */
    int32_t      pid;                         /* Owner Partition ID           */
    uint32_t     source;                      /* IRQ source (number/index)    */
    psa_signal_t signal;                      /* The signal assigned for IRQ  */
    /* TF-M extension of PSA attributes for mailbox client support */
    int32_t     client_id_base;               /* The min translated client ID */
    int32_t     client_id_limit;              /* The max translated client ID */
    uint32_t    mbox_flags;                   /* Flags for mailbox operations */
};

/* IRQ runtime data */
struct irq_t {
    struct partition_t           *p_pt;       /* The owner Partition     */
    const struct irq_load_info_t *p_ildi;     /* The interrupt load info */
};

enum mbox_irq_flags_t {
    MBOX_IRQ_FLAGS_NONE = 0UL,
    MBOX_IRQ_FLAGS_DEFAULT_SCHEDULE = MBOX_IRQ_FLAGS_NONE,
    MBOX_IRQ_FLAGS_DEFER_SCHEDULE = (1UL << 0),

    MBOX_IRQ_FLAGS_MAX = UINT32_MAX,
};

#endif /* __INTERRUPT_DEFS_H__ */

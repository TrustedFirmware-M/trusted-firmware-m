/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <assert.h>
#include <stddef.h>

#include "array.h"
#include "internal_status_code.h"
#include "ns_mailbox_client_id.h"
#include "tfm_plat_defs.h"
#include "tfm_multi_core.h"

#include "tfm_hal_interrupt.h"
#include "utilities.h"
#include "ns_agent_mailbox_utils.h"

static const struct irq_load_info_t *irq_load_info_refs[MAILBOX_INTERRUPT_IRQ_COUNT];

void tfm_multi_core_clear_mbox_irq(void)
{
    const struct irq_load_info_t *irq_info;

    for (size_t i = 0; i < MAILBOX_INTERRUPT_IRQ_COUNT; i++) {
        irq_info = irq_load_info_refs[i];

        if (irq_info != NULL) {
            tfm_hal_irq_clear_pending(irq_info->source);
            tfm_hal_irq_enable(irq_info->source);

            irq_load_info_refs[i] = NULL;
            break;
        }
    }
}

void tfm_multi_core_set_mbox_irq(const struct irq_load_info_t *p_ildi)
{
    size_t i;

    assert(p_ildi != NULL);

#if (CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE == TFM_HYBRID_PLAT_SCHED_BALANCED)
    if (p_ildi->mbox_flags != MBOX_IRQ_FLAGS_DEFER_SCHEDULE) {
        /*
         * This request will be processed immediately, the IRQ will be cleared
         * and re-enabled via the standard rpc flow.
         */
        return;
    }
#endif

    for (i = 0; i < MAILBOX_INTERRUPT_IRQ_COUNT; i++) {
        if (irq_load_info_refs[i] == NULL) {
            irq_load_info_refs[i] = p_ildi;
            break;
        }
    }

    if (i == MAILBOX_INTERRUPT_IRQ_COUNT) {
        tfm_core_panic();
    }
}

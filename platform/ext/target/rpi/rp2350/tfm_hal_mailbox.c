/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "tfm_hal_mailbox.h"
#include "tfm_multi_core.h"
#include "tfm_hal_interrupt.h"
#include "tfm_peripherals_def.h"
#include "hardware/irq.h"
#include "interrupt.h"

#include "platform_multicore.h"

#include "pico/multicore.h"

static struct irq_t mbox_irq_info = {0};

int32_t tfm_mailbox_hal_init(struct secure_mailbox_queue_t *s_queue)
{
    struct mailbox_init_t *ns_init = NULL;

    multicore_ns_fifo_push_blocking_inline(NS_MAILBOX_INIT);

    ns_init = (struct mailbox_init_t *) multicore_ns_fifo_pop_blocking_inline();

    /*
     * FIXME
     * Necessary sanity check of the address of NPSE mailbox queue should
     * be implemented there.
     */
    if (ns_init->slot_count > NUM_MAILBOX_QUEUE_SLOT) {
        return MAILBOX_INIT_ERROR;
    }

    s_queue->ns_status = ns_init->status;
    s_queue->ns_slot_count = ns_init->slot_count;
    s_queue->ns_slots = ns_init->slots;

    multicore_ns_fifo_push_blocking_inline(S_MAILBOX_READY);

    return MAILBOX_SUCCESS;
}

int32_t tfm_mailbox_hal_notify_peer(void)
{
    multicore_ns_fifo_push_blocking_inline(NOTIFY_FROM_CORE0);
    return MAILBOX_SUCCESS;
}

void tfm_mailbox_hal_enter_critical(void)
{
    /* Reading a spinlock register attempts to claim it, returning nonzero
     * if the claim was successful and 0 if unsuccessful */
    while(!*MAILBOX_SPINLOCK);
    return;
}

void tfm_mailbox_hal_exit_critical(void)
{
    /* Writing to a spinlock register releases it */
    *MAILBOX_SPINLOCK = 0x1u;
    return;
}

/* Platform specific inter-processor communication interrupt handler. */
void SIO_IRQ_FIFO_NS_IRQHandler(void)
{
    /*
     * SPM will send a MAILBOX_SIGNAL to the corresponding partition
     * indicating that a message has arrived and can be processed.
     */
    uint32_t msg;
    if (multicore_ns_fifo_rvalid())
    {
        msg = multicore_ns_fifo_pop_blocking_inline();
        if (msg == NOTIFY_FROM_CORE1) {
            spm_handle_interrupt(mbox_irq_info.p_pt, mbox_irq_info.p_ildi);
        }
    }
}

enum tfm_hal_status_t mailbox_irq_init(void *p_pt,
                                       const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info.p_pt = p_pt;
    mbox_irq_info.p_ildi = p_ildi;


    NVIC_SetPriority(SIO_IRQ_FIFO_NS_IRQn, DEFAULT_IRQ_PRIORITY-1);
    irq_set_exclusive_handler(SIO_IRQ_FIFO_NS, SIO_IRQ_FIFO_NS_IRQHandler);

    if (tfm_multi_core_register_client_id_range(CLIENT_ID_OWNER_MAGIC,
                                                p_ildi->client_id_base,
                                                p_ildi->client_id_limit) != 0) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    return TFM_HAL_SUCCESS;
}

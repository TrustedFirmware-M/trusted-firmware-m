/*
 *  SPDX-License-Identifier: BSD-3-Clause
 *  SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

/* FIXME: This shouldn't be required when TFM_PLAT_SPECIFIC_MULTI_CORE_COMM is
 * enabled.
 */

#include "tfm_ns_mailbox.h"
#include "platform_multicore.h"
#include "region.h"

#include "pico/multicore.h"
#include "hardware/irq.h"
#include "hardware/structs/scb.h"
#include "hardware/structs/sio.h"

#include "tfm_hal_device_header.h"
#include "uart_stdout.h"
#include "Driver_Common.h"

int32_t tfm_ns_platform_init(void)
{
    if(sio_hw->cpuid == 0) {
        __enable_irq();
    } else {
        /* Core1 */
        __enable_irq();
        stdio_init();
    }

    return ARM_DRIVER_OK;
}

/* Platform specific inter-processor communication interrupt handler. */
void SIO_IRQ_FIFO_NS_IRQHandler(void)
{
    uint32_t msg;
    if(multicore_fifo_rvalid())
    {
        msg = multicore_fifo_pop_blocking();
        if (msg == NOTIFY_FROM_CORE0) {
            /* Handle all the pending replies */
            tfm_ns_mailbox_wake_reply_owner_isr();
        }
    }
}

int32_t tfm_ns_mailbox_hal_init(struct ns_mailbox_queue_t *queue)
{
    uint32_t stage;

    if(sio_hw->cpuid == 0) {
        return MAILBOX_SUCCESS;
    }

    if (!queue) {
        return MAILBOX_INVAL_PARAMS;
    }

    NVIC_SetVector(SIO_IRQ_FIFO_NS_IRQn, (uint32_t) SIO_IRQ_FIFO_NS_IRQHandler);

    /*
     * Wait until SPE mailbox library is ready to receive NSPE mailbox queue
     * address.
     */
    while (1) {
        stage = multicore_fifo_pop_blocking();
        if  (stage == NS_MAILBOX_INIT) {
            break;
        }
    }

    /* Send out the address */
    struct mailbox_init_t ns_init;
    ns_init.status = &queue->status;
    ns_init.slot_count = NUM_MAILBOX_QUEUE_SLOT;
    ns_init.slots = &queue->slots[0];
    multicore_fifo_push_blocking((uint32_t) &ns_init);

    /* Wait until SPE mailbox service is ready */
    while (1) {
        stage = multicore_fifo_pop_blocking();
        if  (stage == S_MAILBOX_READY) {
            break;
        }
    }

    NVIC_EnableIRQ(SIO_IRQ_FIFO_NS_IRQn);

    return MAILBOX_SUCCESS;
}

int32_t tfm_ns_mailbox_hal_notify_peer(void)
{
    multicore_fifo_push_blocking(NOTIFY_FROM_CORE1);
    return 0;
}

void tfm_ns_mailbox_hal_enter_critical(void)
{
    /* Reading a spinlock register attempts to claim it, returning nonzero
     * if the claim was successful and 0 if unsuccessful */
    while(!*MAILBOX_SPINLOCK);
    return;
}

void tfm_ns_mailbox_hal_exit_critical(void)
{
    /* Writing to a spinlock register releases it */
    *MAILBOX_SPINLOCK = 0x1u;
    return;
}

void tfm_ns_mailbox_hal_enter_critical_isr(void)
{
    /* Reading a spinlock register attempts to claim it, returning nonzero
     * if the claim was successful and 0 if unsuccessful */
    while(!*MAILBOX_SPINLOCK);
    return;
}

void tfm_ns_mailbox_hal_exit_critical_isr(void)
{
    /* Writing to a spinlock register releases it */
    *MAILBOX_SPINLOCK = 0x1u;
    return;
}

extern void runtime_init(void);
extern int main(void);
extern uint32_t __StackOneTop;
extern uint32_t __Vectors_Start__;

void __attribute__((section(".core1_ns_entry"), used, naked)) core1_ns_entry(void)
{
    scb_hw->vtor = (uintptr_t) &__Vectors_Start__;
    __set_MSP((uint32_t)(&__StackOneTop));
    __set_PSP((uint32_t)(&__StackOneTop));
    runtime_init();
    main();
}

#include <stdio.h>
int32_t tfm_platform_ns_wait_for_s_cpu_ready(void)
{
    if(sio_hw->cpuid == 1) {
        /* Core1 */
        multicore_fifo_push_blocking(CORE1_NS_READY);
    }
    return 0;
}

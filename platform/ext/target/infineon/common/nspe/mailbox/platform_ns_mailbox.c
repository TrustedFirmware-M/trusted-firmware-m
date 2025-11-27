/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2019-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------- Includes ----------------------------------- */
#include <limits.h>
#include <stdint.h>
#include <string.h>

#include "cmsis_compiler.h"

#include "cy_ipc_drv.h"
#include "cy_sysint.h"
#include "ifx_interrupt_defs.h"

#include "tfm_multi_core_api.h"
#include "tfm_ns_mailbox.h"
#include "tfm_peripherals_def.h"
#include "platform_multicore.h"

int32_t tfm_ns_multi_core_boot(struct ns_mailbox_queue_t *queue)
{
    int32_t ret;

    ret = tfm_platform_ns_wait_for_s_cpu_ready();
    if (ret != IFX_PLATFORM_MAILBOX_SUCCESS) {
        return MAILBOX_INIT_ERROR;
    }

    ret = tfm_ns_mailbox_init(queue);
    if (ret != MAILBOX_SUCCESS) {
        return ret;
    }

    return MAILBOX_SUCCESS;
}

static void ifx_mailbox_ipc_init(void)
{
    Cy_IPC_Drv_SetInterruptMask(Cy_IPC_Drv_GetIntrBaseAddr(IFX_IPC_TFM_TO_NS_INTR_STRUCT),
                                CY_IPC_NO_NOTIFICATION,
                                IFX_IPC_TFM_TO_NS_INTR_MASK);
}

static void ifx_mailbox_ipc_config(void)
{
    NVIC_SetPriority(IFX_IPC_TFM_TO_NS_IPC_INTR, IFX_IPC_TFM_TO_NS_IRQ_PRIORITY);

    NVIC_EnableIRQ(IFX_IPC_TFM_TO_NS_IPC_INTR);
}

static bool ifx_mailbox_clear_intr(void)
{
    IPC_INTR_STRUCT_Type *intr_struct = Cy_IPC_Drv_GetIntrBaseAddr(IFX_IPC_TFM_TO_NS_INTR_STRUCT);
    uint32_t status = Cy_IPC_Drv_GetInterruptStatusMasked(intr_struct);

    if ((status & _VAL2FLD(IPC_INTR_STRUCT_INTR_MASK_NOTIFY,
                           IFX_IPC_TFM_TO_NS_INTR_MASK)) == 0U) {
        return false;
    }

    Cy_IPC_Drv_ClearInterrupt(intr_struct,
                              CY_IPC_NO_NOTIFICATION,
                              IFX_IPC_TFM_TO_NS_INTR_MASK);
    return true;
}

static int32_t ifx_platform_ns_ipc_init(void)
{
    Cy_IPC_Drv_SetInterruptMask(Cy_IPC_Drv_GetIntrBaseAddr(IFX_IPC_TFM_TO_NS_INTR_STRUCT),
                                CY_IPC_NO_NOTIFICATION,
                                IFX_IPC_TFM_TO_NS_INTR_MASK);
    return IFX_PLATFORM_MAILBOX_SUCCESS;
}


int32_t tfm_platform_ns_wait_for_s_cpu_ready(void)
{
    uint32_t data = 0;

    if (ifx_platform_ns_ipc_init() != IFX_PLATFORM_MAILBOX_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_INVAL_PARAMS;
    }
    while (data != IFX_IPC_SYNC_MAGIC) {
        ifx_mailbox_wait_for_notify();
        ifx_mailbox_fetch_msg_data(&data);
    }

    if (ifx_mailbox_send_msg_data(~IFX_IPC_SYNC_MAGIC) !=
        IFX_PLATFORM_MAILBOX_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_RX_ERROR;
    }
    return IFX_PLATFORM_MAILBOX_SUCCESS;
}

void IFX_IRQ_NAME_TO_HANDLER(IFX_IPC_TFM_TO_NS_IPC_INTR)(void)
{
    uint32_t magic;

    if (!ifx_mailbox_clear_intr()) {
        return;
    }

    ifx_mailbox_fetch_msg_data(&magic);
    if (magic == IFX_PSA_CLIENT_CALL_REPLY_MAGIC) {
        /* Handle all the pending replies */
        tfm_ns_mailbox_wake_reply_owner_isr();
    }
}

/* --------------------------------- NS mailbox HAL API ------------------------------- */

int32_t tfm_ns_mailbox_hal_notify_peer(void)
{
    cy_en_ipcdrv_status_t status;

    status = Cy_IPC_Drv_SendMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_NS_TO_TFM_CHAN),
                                    IFX_IPC_NS_TO_TFM_NOTIFY_MASK,
                                    IFX_PSA_CLIENT_CALL_REQ_MAGIC);

    if (status == CY_IPC_DRV_SUCCESS) {
        return MAILBOX_SUCCESS;
    } else {
        return MAILBOX_CHAN_BUSY;
    }
}

int32_t tfm_ns_mailbox_hal_init(struct ns_mailbox_queue_t *queue)
{
    uint32_t stage;

    if (queue == NULL) {
        return MAILBOX_INVAL_PARAMS;
    }

    /*
     * Mailbox queue pointer is checked in the secure code in
     * tfm_mailbox_hal_init(), thus no need to check it in NSPE side.
     * Further verification of mailbox queue address may be required according
     * to diverse NSPE implementations. It is left up to the system integrators.
     */

    ifx_mailbox_ipc_init();

    /*
     * Wait until SPE mailbox library is ready to receive NSPE mailbox queue
     * address.
     */
    while (true) {
        ifx_mailbox_wait_for_notify();

        ifx_mailbox_fetch_msg_data(&stage);
        if  (stage == IFX_NS_MAILBOX_INIT_ENABLE) {
            break;
        }
    }

    /* Send out the address */
    /* IAR can't allocate stricter aligned structure in the stack */
    static struct mailbox_init_t ns_init;
    ns_init.status = &queue->status;
    ns_init.slot_count = NUM_MAILBOX_QUEUE_SLOT;
    ns_init.slots = &queue->slots[0];
    MAILBOX_CLEAN_CACHE(&ns_init, sizeof(ns_init));
    ifx_mailbox_send_msg_ptr(&ns_init);

    /* Wait until SPE mailbox service is ready */
    while (true) {
        ifx_mailbox_wait_for_notify();

        ifx_mailbox_fetch_msg_data(&stage);
        if  (stage == IFX_S_MAILBOX_READY) {
            break;
        }
    }

    ifx_mailbox_ipc_config();

    return MAILBOX_SUCCESS;
}

uint32_t tfm_ns_mailbox_hal_enter_critical(void)
{
    /* Note: Cy_SysLib_EnterCriticalSection doesn't work when it is called in unprivileged mode */
    /* Disable interrupts to avoid reentrance */
    uint32_t state = Cy_SysLib_EnterCriticalSection();

    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_MAILBOX_LOCK_CHAN);

    while (CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_LockAcquire (ipc_struct))
    {
        /* Re-enable interrupts to avoid too much latency */
        Cy_SysLib_ExitCriticalSection(state);
        state = Cy_SysLib_EnterCriticalSection();
    }

    return state;
}

void tfm_ns_mailbox_hal_exit_critical(uint32_t state)
{
    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_MAILBOX_LOCK_CHAN);
    Cy_IPC_Drv_LockRelease(ipc_struct, CY_IPC_NO_NOTIFICATION);

    /* Restore interrupts */
    Cy_SysLib_ExitCriticalSection(state);
}

uint32_t tfm_ns_mailbox_hal_enter_critical_isr(void)
{
    /* Disable interrupts to avoid interruption by higher priority IRQ which can extend
     * execution of critical section on this core and therefore extend the wait
     * for critical section on another core.
     */
    return tfm_ns_mailbox_hal_enter_critical();
}

void tfm_ns_mailbox_hal_exit_critical_isr(uint32_t state)
{
    tfm_ns_mailbox_hal_exit_critical(state);
}

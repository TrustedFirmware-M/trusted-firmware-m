/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2019-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------- Includes ----------------------------------- */
#include "tfm_hal_device_header.h"
#include "cmsis_compiler.h"

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_ipc_drv.h"
#include "cy_sysint.h"

#include "spe_ipc_config.h"
#include "tfm_hal_mailbox.h"
#include "platform_multicore.h"

/* -------------------------------------- HAL API ------------------------------------ */

int32_t tfm_mailbox_hal_notify_peer(void)
{
    cy_en_ipcdrv_status_t status;

    status = Cy_IPC_Drv_SendMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(IPC_TX_CHAN),
                                    IPC_TX_NOTIFY_MASK,
                                    PSA_CLIENT_CALL_REPLY_MAGIC);

    if (status == CY_IPC_DRV_SUCCESS) {
        return MAILBOX_SUCCESS;
    } else {
        return MAILBOX_CHAN_BUSY;
    }
}

static void mailbox_ipc_config(void)
{
    Cy_SysInt_SetIntSource(PSA_CLIENT_CALL_NVIC_IRQn, PSA_CLIENT_CALL_IPC_INTR);

    NVIC_SetPriority(PSA_CLIENT_CALL_NVIC_IRQn, PSA_CLIENT_CALL_IRQ_PRIORITY);

    NVIC_EnableIRQ(PSA_CLIENT_CALL_NVIC_IRQn);
}

int32_t tfm_mailbox_hal_init(struct secure_mailbox_queue_t *s_queue)
{
    struct mailbox_init_t *ns_init = NULL;

    /* Inform NSPE that NSPE mailbox initialization can start */
    platform_mailbox_send_msg_data(NS_MAILBOX_INIT_ENABLE);

    platform_mailbox_wait_for_notify();

    /* Receive the address of NSPE mailbox queue */
    platform_mailbox_fetch_msg_ptr((void **)&ns_init);

    s_queue->ns_status = ns_init->status;
    s_queue->ns_slot_count = ns_init->slot_count;
    s_queue->ns_slots = ns_init->slots;

    mailbox_ipc_config();

    /* Inform NSPE that SPE mailbox service is ready */
    platform_mailbox_send_msg_data(S_MAILBOX_READY);

    return MAILBOX_SUCCESS;
}

uint32_t tfm_mailbox_hal_enter_critical(void)
{
    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IPC_PSA_MAILBOX_LOCK_CHAN);
    while(CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_LockAcquire (ipc_struct))
    {
    }
    return 0;
}

void tfm_mailbox_hal_exit_critical(uint32_t state)
{
    (void)state;
    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IPC_PSA_MAILBOX_LOCK_CHAN);
    Cy_IPC_Drv_LockRelease(ipc_struct, CY_IPC_NO_NOTIFICATION);
}

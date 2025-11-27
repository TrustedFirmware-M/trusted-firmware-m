/*
 * Copyright (c) 2024-2025 Arm Limited. All rights reserved.
 * Copyright (c) 2019-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include "cmsis_compiler.h"

#include "platform_multicore.h"

#include "cy_ipc_drv.h"
#include "cy_sysint.h"
#include "tfm_peripherals_def.h"

#if DOMAIN_S == 1
#define IPC_RX_CHAN                            IFX_IPC_NS_TO_TFM_CHAN
#define IPC_RX_INTR_STRUCT                     IFX_IPC_NS_TO_TFM_INTR_STRUCT
#define IPC_RX_INT_MASK                        IFX_IPC_NS_TO_TFM_INTR_MASK

#define IPC_TX_CHAN                            IFX_IPC_TFM_TO_NS_CHAN
#define IPC_TX_NOTIFY_MASK                     IFX_IPC_TFM_TO_NS_NOTIFY_MASK
#else
#define IPC_RX_CHAN                            IFX_IPC_TFM_TO_NS_CHAN
#define IPC_RX_INTR_STRUCT                     IFX_IPC_TFM_TO_NS_INTR_STRUCT
#define IPC_RX_INT_MASK                        IFX_IPC_TFM_TO_NS_INTR_MASK

#define IPC_TX_CHAN                            IFX_IPC_NS_TO_TFM_CHAN
#define IPC_TX_NOTIFY_MASK                     IFX_IPC_NS_TO_TFM_NOTIFY_MASK
#endif

int32_t ifx_mailbox_fetch_msg_ptr(void **msg_ptr)
{
    IPC_STRUCT_Type *ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IPC_RX_CHAN);
    cy_en_ipcdrv_status_t status;

    if (msg_ptr == NULL) {
        return IFX_PLATFORM_MAILBOX_INVAL_PARAMS;
    }

    status = Cy_IPC_Drv_ReadMsgPtr(ipc_struct, msg_ptr);
    if (status != CY_IPC_DRV_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_RX_ERROR;
    }

    Cy_IPC_Drv_ReleaseNotify(ipc_struct, 0);
    return IFX_PLATFORM_MAILBOX_SUCCESS;
}

int32_t ifx_mailbox_fetch_msg_data(uint32_t *data_ptr)
{
    IPC_STRUCT_Type *ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IPC_RX_CHAN);
    cy_en_ipcdrv_status_t status;

    if (data_ptr == NULL) {
        return IFX_PLATFORM_MAILBOX_INVAL_PARAMS;
    }

    status = Cy_IPC_Drv_ReadMsgWord(ipc_struct, data_ptr);
    if (status != CY_IPC_DRV_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_RX_ERROR;
    }

    Cy_IPC_Drv_ReleaseNotify(ipc_struct, 0);
    return IFX_PLATFORM_MAILBOX_SUCCESS;
}

int32_t ifx_mailbox_send_msg_ptr(const void *msg_ptr)
{
    cy_en_ipcdrv_status_t status;

    if (msg_ptr == NULL) {
        return IFX_PLATFORM_MAILBOX_INVAL_PARAMS;
    }

    status = Cy_IPC_Drv_SendMsgPtr(Cy_IPC_Drv_GetIpcBaseAddress(IPC_TX_CHAN),
                                   IPC_TX_NOTIFY_MASK,
                                   msg_ptr);
    if (status != CY_IPC_DRV_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_TX_ERROR;
    }

    return IFX_PLATFORM_MAILBOX_SUCCESS;
}

int32_t ifx_mailbox_send_msg_data(uint32_t data)
{
    cy_en_ipcdrv_status_t status = Cy_IPC_Drv_SendMsgWord(
                                     Cy_IPC_Drv_GetIpcBaseAddress(IPC_TX_CHAN),
                                     IPC_TX_NOTIFY_MASK,
                                     data);
    if (status != CY_IPC_DRV_SUCCESS) {
        return IFX_PLATFORM_MAILBOX_TX_ERROR;
    }

    return IFX_PLATFORM_MAILBOX_SUCCESS;
}

void ifx_mailbox_wait_for_notify(void)
{
    IPC_INTR_STRUCT_Type *intr_struct = Cy_IPC_Drv_GetIntrBaseAddr(IPC_RX_INTR_STRUCT);
    uint32_t status;

    while (true) {
        status = Cy_IPC_Drv_GetInterruptStatusMasked(intr_struct);
        if ((status & _VAL2FLD(IPC_INTR_STRUCT_INTR_MASK_NOTIFY,
                              IPC_RX_INT_MASK)) != 0u) {
            break;
        }
    }

    Cy_IPC_Drv_ClearInterrupt(intr_struct, CY_IPC_NO_NOTIFICATION, IPC_RX_INT_MASK);
}

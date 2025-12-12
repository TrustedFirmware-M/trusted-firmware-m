/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 * Copyright (c) 2019-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_ipc_drv.h"
#include "ifx_regions.h"
#include "platform_multicore.h"
#include "tfm_hal_multi_core.h"
#include "tfm_peripherals_def.h"
#include "tfm_sp_log.h"

void tfm_hal_wait_for_ns_cpu_ready(void)
{
    IPC_INTR_STRUCT_Type *intr_struct
                              = Cy_IPC_Drv_GetIntrBaseAddr(IFX_IPC_NS_TO_TFM_INTR_STRUCT);
    IPC_STRUCT_Type *rx_ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_NS_TO_TFM_CHAN);
    uint32_t data;
    uint32_t intr;
    cy_en_ipcdrv_status_t status;

    Cy_IPC_Drv_SetInterruptMask(intr_struct,
                                CY_IPC_NO_NOTIFICATION,
                                IFX_IPC_NS_TO_TFM_INTR_MASK);

    status = Cy_IPC_Drv_SendMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_TFM_TO_NS_CHAN),
                                    IFX_IPC_TFM_TO_NS_NOTIFY_MASK, IFX_IPC_SYNC_MAGIC);
    while (true)
    {
        intr = Cy_IPC_Drv_GetInterruptStatusMasked(intr_struct);
        if ((intr & _VAL2FLD(IPC_INTR_STRUCT_INTR_MASK_NOTIFY, IFX_IPC_NS_TO_TFM_INTR_MASK)) != 0u)
        {
            Cy_IPC_Drv_ClearInterrupt(intr_struct,
                                      CY_IPC_NO_NOTIFICATION,
                                      IFX_IPC_NS_TO_TFM_INTR_MASK);

            status = Cy_IPC_Drv_ReadMsgWord(rx_ipc_struct, &data);
            if (status == CY_IPC_DRV_SUCCESS) {
                Cy_IPC_Drv_ReleaseNotify(rx_ipc_struct, 0);
                if (data == ~IFX_IPC_SYNC_MAGIC) {
                    LOG_INFFMT("Cores sync success.\r\n");
                    break;
                }
            }
        }
    }
}

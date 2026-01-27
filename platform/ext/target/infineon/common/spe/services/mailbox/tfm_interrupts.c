/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2024-2025-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_ipc_drv.h"
#include "ifx_interrupt_defs.h"
#include "interrupt.h"
#include "platform_multicore.h"
#include "spm.h"
#include "tfm_multi_core.h"
#include "tfm_peripherals_def.h"
#include "load/interrupt_defs.h"
#include "coverity_check.h"

static struct irq_t mbox_irq_info = {0};

static void ifx_mailbox_clear_intr(void)
{
    IPC_INTR_STRUCT_Type *intr_struct
                            = Cy_IPC_Drv_GetIntrBaseAddr(IFX_IPC_NS_TO_TFM_INTR_STRUCT);
    uint32_t status = Cy_IPC_Drv_GetInterruptStatusMasked(intr_struct);
    if ((status & _VAL2FLD(IPC_INTR_STRUCT_INTR_MASK_NOTIFY,
                           IFX_IPC_NS_TO_TFM_INTR_MASK)) == 0U) {
        return;
    }

    Cy_IPC_Drv_ClearInterrupt(intr_struct,
                              CY_IPC_NO_NOTIFICATION,
                              IFX_IPC_NS_TO_TFM_INTR_MASK);
}

void IFX_IRQ_NAME_TO_HANDLER(IFX_IPC_NS_TO_TFM_IPC_INTR)(void)
{
    uint32_t magic;

    ifx_mailbox_clear_intr();

    /* Read from mailbox */
    ifx_mailbox_fetch_msg_data(&magic);
    if (magic == IFX_PSA_CLIENT_CALL_REQ_MAGIC) {
        spm_handle_interrupt(mbox_irq_info.p_pt, mbox_irq_info.p_ildi);
    }
}

enum tfm_hal_status_t mailbox_irq_init(void *p_pt,
                                       const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info.p_pt = p_pt;
    mbox_irq_info.p_ildi = p_ildi;

    NVIC_SetPriority(MAILBOX_IRQ, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(MAILBOX_IRQ);
    NVIC_DisableIRQ(MAILBOX_IRQ);

    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_6, "Intentional pointer cast")
    if (tfm_multi_core_register_client_id_range(CLIENT_ID_OWNER_MAGIC,
                                                p_ildi->client_id_base,
                                                p_ildi->client_id_limit) != 0) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }
    return TFM_HAL_SUCCESS;
}

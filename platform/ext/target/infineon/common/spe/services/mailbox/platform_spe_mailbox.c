/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2024-2025-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------- Includes ----------------------------------- */
#include "config_tfm.h"
#include "cmsis.h"
#include "cmsis_compiler.h"

#include "cy_device.h"
#include "cy_ipc_drv.h"
#include "cy_sysint.h"

#include "current.h"
#include "ifx_fih.h"
#include "ifx_utils.h"
#include "tfm_hal_isolation.h"
#include "tfm_hal_multi_core.h"
#include "tfm_peripherals_def.h"
#include "tfm_spe_mailbox.h"
#include "platform_multicore.h"
#include "utilities.h"
#include "coverity_check.h"

/* If there's no dcache at all, the SCB cache functions won't exist */
/* If the mailbox is uncached on the S side, no need to flush and invalidate */
#if !defined(__DCACHE_PRESENT) || (__DCACHE_PRESENT == 0U) || defined(MAILBOX_IS_UNCACHED_S)
#define MAILBOX_CLEAN_CACHE(addr, size) { __DSB(); }
#define MAILBOX_INVALIDATE_CACHE(addr, size) do {} while (0)
#else
#define MAILBOX_CLEAN_CACHE(addr, size) SCB_CleanDCache_by_Addr((addr), (size))
#define MAILBOX_INVALIDATE_CACHE(addr, size) SCB_InvalidateDCache_by_Addr((addr), (size))
#endif

static void ifx_mailbox_ipc_config(void)
{
    NVIC_SetPriority(MAILBOX_IRQ, IFX_IPC_NS_TO_TFM_IRQ_PRIORITY);
    NVIC_ClearTargetState(MAILBOX_IRQ);
    NVIC_EnableIRQ(MAILBOX_IRQ);
}

/* -------------------------------------- HAL API ------------------------------------ */

#ifndef NDEBUG
static bool in_critical_section = false;
#endif

int32_t tfm_mailbox_hal_notify_peer(void)
{
    cy_en_ipcdrv_status_t status;

    status = Cy_IPC_Drv_SendMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_TFM_TO_NS_CHAN),
                                    IFX_IPC_TFM_TO_NS_NOTIFY_MASK,
                                    IFX_PSA_CLIENT_CALL_REPLY_MAGIC);

    if (status == CY_IPC_DRV_SUCCESS) {
        return MAILBOX_SUCCESS;
    } else {
        return MAILBOX_CHAN_BUSY;
    }
}

int32_t tfm_mailbox_hal_init(struct secure_mailbox_queue_t *s_queue)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);
    const struct partition_t *partition = GET_CURRENT_COMPONENT();
    struct mailbox_init_t *ns_init = NULL;
    /* IAR can't allocate stricter aligned structure in the stack */
    static struct mailbox_init_t ns_init_s;

    /* Inform NSPE that NSPE mailbox initialization can start */
    ifx_mailbox_send_msg_data(IFX_NS_MAILBOX_INIT_ENABLE);

    ifx_mailbox_wait_for_notify();

    /* Receive the address of NSPE mailbox queue */
    ifx_mailbox_fetch_msg_ptr((void **)&ns_init);

    /* Sanity check the address of NSPE mailbox queue */
    FIH_CALL(tfm_hal_memory_check,
             fih_rc,
             partition->boundary,
             (uintptr_t)ns_init,
             sizeof(*ns_init),
             (TFM_HAL_ACCESS_READWRITE | TFM_HAL_ACCESS_NS));
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_4, "Cannot change types due to Fault injection architecture")
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        tfm_core_panic();
    }
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_4)

    void* ns_init_remapped = tfm_hal_remap_ns_cpu_address(ns_init);

    MAILBOX_INVALIDATE_CACHE(ns_init_remapped, sizeof(*ns_init));
    memcpy(&ns_init_s, ns_init_remapped, sizeof(*ns_init));

    if ((ns_init_s.slot_count == 0U) || (ns_init_s.slot_count > NUM_MAILBOX_QUEUE_SLOT)) {
        return MAILBOX_INIT_ERROR;
    }

    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_4, "Cannot change types due to Fault injection architecture")
    FIH_CALL(tfm_hal_memory_check,
             fih_rc,
             partition->boundary,
             (uintptr_t)ns_init_s.status,
             sizeof(*ns_init_s.status),
             (TFM_HAL_ACCESS_READWRITE | TFM_HAL_ACCESS_NS));
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        tfm_core_panic();
    }

    FIH_CALL(tfm_hal_memory_check,
             fih_rc,
             partition->boundary,
             (uintptr_t)ns_init_s.slots,
             sizeof(*ns_init_s.slots) * ns_init_s.slot_count,
             (TFM_HAL_ACCESS_READWRITE | TFM_HAL_ACCESS_NS));
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        tfm_core_panic();
    }
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_4)

    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "Conversion is safe as ns_init_s.status has the same type as s_queue->ns_status")
    s_queue->ns_status = (struct mailbox_status_t*)tfm_hal_remap_ns_cpu_address(ns_init_s.status);
    s_queue->ns_slot_count = ns_init_s.slot_count;
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "Conversion is safe as ns_init_s.slots has the same type as s_queue->ns_slots")
    s_queue->ns_slots = (struct mailbox_slot_t*)tfm_hal_remap_ns_cpu_address(ns_init_s.slots);

    ifx_mailbox_ipc_config();

    /* Inform NSPE that SPE mailbox service is ready */
    ifx_mailbox_send_msg_data(IFX_S_MAILBOX_READY);

    return MAILBOX_SUCCESS;
}

int32_t tfm_mailbox_hal_deinit(struct secure_mailbox_queue_t *s_queue)
{
    NVIC_DisableIRQ(MAILBOX_IRQ);

    s_queue->ns_status = NULL;
    s_queue->ns_slot_count = 0;
    s_queue->ns_slots = NULL;

    return MAILBOX_SUCCESS;
}

uint32_t tfm_mailbox_hal_enter_critical(void)
{
    /* Note that interrupts are left enabled here to avoid the possibility that the NSPE
     * code could lock up TF-M by entering and never leaving the critical section.
     * If that happens here, the mailbox partition will lock up inside this function,
     * but the rest of TF-M will continue to run.
     */

    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_MAILBOX_LOCK_CHAN);

#ifndef NDEBUG
    if (in_critical_section) {
        tfm_core_panic();
    }
    in_critical_section = true;
#endif

    while (CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_LockAcquire (ipc_struct))
    {
    }

    return 0;
}

void tfm_mailbox_hal_exit_critical(uint32_t state)
{
    IPC_STRUCT_Type* ipc_struct =
        Cy_IPC_Drv_GetIpcBaseAddress(IFX_IPC_MAILBOX_LOCK_CHAN);
    IFX_UNUSED(state);

    Cy_IPC_Drv_LockRelease(ipc_struct, CY_IPC_NO_NOTIFICATION);
#ifndef NDEBUG
    in_critical_section = false;
#endif
}

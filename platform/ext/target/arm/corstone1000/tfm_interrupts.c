/*
 * Copyright (c) 2021-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis.h"
#include "device_definition.h"
#include "spm.h"
#include "tfm_hal_interrupt.h"
#include "tfm_peripherals_def.h"
#include "interrupt.h"
#include "load/interrupt_defs.h"
#include "platform_irq.h"
#include "rse_comms_hal.h"

/* Offset of Secure Enclave Interrupt Collator Status 0 */
#define SEC_ENC_INT_COL_ST0_OFFSET  (0x10)
/* (SEEI{x}) where x is the shared interrupt index (SDC-600 is 1) */
#define SDC600_SEEI_BIT          1u
#define SDC600_SEEI_MASK         (1u << SDC600_SEEI_BIT)

static struct irq_t mbox_irq_info = {0};

/* Platform specific inter-processor communication interrupt handler. */
void HSE1_RECEIVER_COMBINED_IRQHandler(void)
{
    (void)tfm_multi_core_hal_receive(&MHU1_HOST_TO_SE_DEV,
                                     &MHU1_SE_TO_HOST_DEV,
                                     mbox_irq_info.p_ildi->source);

    /*
     * SPM will send a MAILBOX_SIGNAL to the corresponding partition
     * indicating that a message has arrived and can be processed.
     */
    spm_handle_interrupt(mbox_irq_info.p_pt, mbox_irq_info.p_ildi);
}

enum tfm_hal_status_t mailbox_irq_init(void *p_pt,
                                       const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info.p_pt = p_pt;
    mbox_irq_info.p_ildi = p_ildi;

    /* Set MHU interrupt priority to the same as PendSV (the lowest)
     * TODO: Consider advantages/disadvantages of setting it one higher
     */
    NVIC_SetPriority(HSE1_RECEIVER_COMBINED_IRQn, NVIC_GetPriority(PendSV_IRQn));

    NVIC_DisableIRQ(HSE1_RECEIVER_COMBINED_IRQn);

    return TFM_HAL_SUCCESS;
}

static struct irq_t se_interrupt_expansion_irq = {0};

void SE_INTERRUPT_EXPANSION_IRQHandler(void)
{
    volatile uint32_t *ST0 =
        (volatile uint32_t *)(CORSTONE1000_BASE_SCR_BASE + SEC_ENC_INT_COL_ST0_OFFSET);

    if ((*ST0) & SDC600_SEEI_MASK) {
        spm_handle_interrupt(se_interrupt_expansion_irq.p_pt,
                             se_interrupt_expansion_irq.p_ildi);
    }
}

enum tfm_hal_status_t adac_request_irq_init(void *p_pt,
                                            const struct irq_load_info_t *p_ildi)
{

    se_interrupt_expansion_irq.p_ildi = p_ildi;
    se_interrupt_expansion_irq.p_pt = p_pt;

    return TFM_HAL_SUCCESS;
}
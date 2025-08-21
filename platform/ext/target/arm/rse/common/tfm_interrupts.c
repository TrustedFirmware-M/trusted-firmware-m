/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "config_tfm_target.h"
#include "internal_status_code.h"
#include "tfm_hal_defs.h"
#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "spm.h"
#include "tfm_hal_interrupt.h"
#include "tfm_peripherals_def.h"
#include "tfm_multi_core.h"
#include "interrupt.h"
#include "load/interrupt_defs.h"
#include "platform_irq.h"
#ifdef TFM_MULTI_CORE_TOPOLOGY
#include "rse_comms_runtime_hal.h"
#include "rse_comms_platform.h"
#endif

static struct irq_t timer0_irq = {0};

void TFM_TIMER0_IRQ_Handler(void)
{
    spm_handle_interrupt(timer0_irq.p_pt, timer0_irq.p_ildi);
}

enum tfm_hal_status_t tfm_timer0_irq_init(void *p_pt,
                                          const struct irq_load_info_t *p_ildi)
{
    timer0_irq.p_ildi = p_ildi;
    timer0_irq.p_pt = p_pt;

    NVIC_SetPriority(TFM_TIMER0_IRQ, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(TFM_TIMER0_IRQ);
    NVIC_DisableIRQ(TFM_TIMER0_IRQ);

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_MULTI_CORE_TOPOLOGY
static struct irq_t mbox_irq_info[3] = {0};

/* Platform specific inter-processor communication interrupt handler. */
void CMU_MHU0_Receiver_Handler(void)
{
    struct rse_comms_platform_device_t device = {
        &MHU0_RECEIVER_DEV_S,
#if PLAT_MHU_VERSION == 2
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2,
#else
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3,
#endif
    };

    (void)tfm_multi_core_hal_receive(rse_comms_platform_get_receive_link_id(device),
                                     mbox_irq_info[0].p_ildi->source);

    /*
     * SPM will send a MAILBOX_INTERRUPT_SIGNAL to the corresponding partition
     * indicating that a message has arrived and can be processed.
     */
    spm_handle_interrupt(mbox_irq_info[0].p_pt, mbox_irq_info[0].p_ildi);
}

#ifdef MHU1_S
/* Platform specific inter-processor communication interrupt handler. */
void CMU_MHU1_Receiver_Handler(void)
{
    struct rse_comms_platform_device_t device = {
        &MHU1_RECEIVER_DEV_S,
#if PLAT_MHU_VERSION == 2
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2,
#else
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3,
#endif
    };

    (void)tfm_multi_core_hal_receive(rse_comms_platform_get_receive_link_id(device),
                                     mbox_irq_info[1].p_ildi->source);

    /*
     * SPM will send a MAILBOX_INTERRUPT_SIGNAL to the corresponding partition
     * indicating that a message has arrived and can be processed.
     */
    spm_handle_interrupt(mbox_irq_info[1].p_pt, mbox_irq_info[1].p_ildi);
}
#endif /* MHU_AP_NS_TO_RSE_DEV */

#ifdef MHU2_S
/* Platform specific inter-processor communication interrupt handler. */
void CMU_MHU2_Receiver_Handler(void)
{
    struct rse_comms_platform_device_t device = {
        &MHU2_RECEIVER_DEV_S,
#if PLAT_MHU_VERSION == 2
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2,
#else
        RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3,
#endif
    };

    (void)tfm_multi_core_hal_receive(rse_comms_platform_get_receive_link_id(device),
                                     mbox_irq_info[2].p_ildi->source);

    /*
     * SPM will send a MAILBOX_INTERRUPT_SIGNAL to the corresponding partition
     * indicating that a message has arrived and can be processed.
     */
    spm_handle_interrupt(mbox_irq_info[2].p_pt, mbox_irq_info[2].p_ildi);
}
#endif /* MHU_AP_S_TO_RSE_DEV */

enum tfm_hal_status_t mailbox_irq_init(void *p_pt,
                                       const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info[0].p_pt = p_pt;
    mbox_irq_info[0].p_ildi = p_ildi;

    /* Set MHU interrupt priority to the same as PendSV (the lowest)
     * TODO: Consider advantages/disadvantages of setting it one higher
     */
    NVIC_SetPriority(CMU_MHU0_Receiver_IRQn, NVIC_GetPriority(PendSV_IRQn));

    /* CMU_MHU0 is a secure peripheral, so its IRQs have to target S state */
    NVIC_ClearTargetState(CMU_MHU0_Receiver_IRQn);
    NVIC_DisableIRQ(CMU_MHU0_Receiver_IRQn);

    if (tfm_multi_core_register_client_id_range(&MHU0_SENDER_DEV_S, p_ildi->source) !=
        SPM_SUCCESS) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }
    return TFM_HAL_SUCCESS;
}

#ifdef MHU_AP_NS_TO_RSE_DEV
enum tfm_hal_status_t mailbox_irq_1_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info[1].p_pt = p_pt;
    mbox_irq_info[1].p_ildi = p_ildi;

    /* Set MHU interrupt priority to the same as PendSV (the lowest)
     * TODO: Consider advantages/disadvantages of setting it one higher
     */
    NVIC_SetPriority(CMU_MHU1_Receiver_IRQn, NVIC_GetPriority(PendSV_IRQn));

    /* CMU_MHU1 is a secure peripheral, so its IRQs have to target S state */
    NVIC_ClearTargetState(CMU_MHU1_Receiver_IRQn);
    NVIC_DisableIRQ(CMU_MHU1_Receiver_IRQn);

    if (tfm_multi_core_register_client_id_range(&MHU1_SENDER_DEV_S, p_ildi->source) !=
        SPM_SUCCESS) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }
    return TFM_HAL_SUCCESS;
}
#else /* MHU_AP_NS_TO_RSE_DEV */
enum tfm_hal_status_t mailbox_irq_1_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    (void)p_pt;
    (void)p_ildi;

    return TFM_HAL_ERROR_NOT_SUPPORTED;
}
#endif /* MHU_AP_NS_TO_RSE_DEV */

#ifdef MHU_AP_S_TO_RSE_DEV
enum tfm_hal_status_t mailbox_irq_2_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    mbox_irq_info[2].p_pt = p_pt;
    mbox_irq_info[2].p_ildi = p_ildi;

    /* Set MHU interrupt priority to the same as PendSV (the lowest)
     * TODO: Consider advantages/disadvantages of setting it one higher
     */
    NVIC_SetPriority(CMU_MHU2_Receiver_IRQn, NVIC_GetPriority(PendSV_IRQn));

    /* CMU_MHU2 is a secure peripheral, so its IRQs have to target S state */
    NVIC_ClearTargetState(CMU_MHU2_Receiver_IRQn);
    NVIC_DisableIRQ(CMU_MHU2_Receiver_IRQn);

    if (tfm_multi_core_register_client_id_range(&MHU2_SENDER_DEV_S, p_ildi->source) !=
        SPM_SUCCESS) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    return TFM_HAL_SUCCESS;
}
#else /* MHU_AP_S_TO_RSE_DEV */
enum tfm_hal_status_t mailbox_irq_2_init(void *p_pt,
                                         const struct irq_load_info_t *p_ildi)
{
    (void)p_pt;
    (void)p_ildi;

    return TFM_HAL_ERROR_NOT_SUPPORTED;
}
#endif /* MHU_AP_S_TO_RSE_DEV */
#endif /* TFM_MULTI_CORE_TOPOLOGY */

#ifdef TFM_PARTITION_SCMI_COMMS
static struct irq_t scp_doorbell_irq = {0};

void SCP_DOORBELL_IRQ_HANDLER(void)
{
    spm_handle_interrupt(scp_doorbell_irq.p_pt, scp_doorbell_irq.p_ildi);
}

enum tfm_hal_status_t scp_doorbell_irq_init(void *p_pt,
                                            const struct irq_load_info_t *p_ildi)
{
    scp_doorbell_irq.p_pt = p_pt;
    scp_doorbell_irq.p_ildi = p_ildi;

    /* SCP MHU communication in the bootloader with the IRQ disabled may leave a
     * pending IRQ. Clear it here to avoid a false IRQ being triggered.
     */
    NVIC_ClearPendingIRQ(SCP_DOORBELL_IRQ);

    NVIC_SetPriority(SCP_DOORBELL_IRQ, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(SCP_DOORBELL_IRQ);
    NVIC_DisableIRQ(SCP_DOORBELL_IRQ);

    return TFM_HAL_SUCCESS;
}
#endif /* TFM_PARTITION_SCMI_COMMS */

static struct irq_t dma0_ch0_irq = {0};

void DMA_Combined_S_Handler(void)
{
    spm_handle_interrupt(dma0_ch0_irq.p_pt, dma0_ch0_irq.p_ildi);
}

enum tfm_hal_status_t tfm_dma0_combined_s_irq_init(void *p_pt,
                                          struct irq_load_info_t *p_ildi)
{
    dma0_ch0_irq.p_ildi = p_ildi;
    dma0_ch0_irq.p_pt = p_pt;

    NVIC_SetPriority(TFM_DMA0_COMBINED_S_IRQ, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(TFM_DMA0_COMBINED_S_IRQ);
    NVIC_DisableIRQ(TFM_DMA0_COMBINED_S_IRQ);

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_PARTITION_RUNTIME_PROVISIONING
static struct irq_t runtime_provisioning_message_irq = {0};

void RUNTIME_PROVISIONING_MESSAGE_IRQ_HANDLER(void)
{
    spm_handle_interrupt(runtime_provisioning_message_irq.p_pt,
                         runtime_provisioning_message_irq.p_ildi);
}

enum tfm_hal_status_t runtime_provisioning_message_irq_init(void *p_pt,
                                                            const struct irq_load_info_t *p_ildi)
{
    runtime_provisioning_message_irq.p_ildi = p_ildi;
    runtime_provisioning_message_irq.p_pt = p_pt;

    NVIC_SetPriority(RUNTIME_PROVISIONING_MESSAGE_IRQ, DEFAULT_IRQ_PRIORITY);
    NVIC_ClearTargetState(RUNTIME_PROVISIONING_MESSAGE_IRQ);
    NVIC_DisableIRQ(RUNTIME_PROVISIONING_MESSAGE_IRQ);

    return TFM_HAL_SUCCESS;
}
#endif /* TFM_PARTITION_RUNTIME_PROVISIONING */

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
static struct irq_t sdc_irq = {0};

void SDC_Handler(void)
{
    spm_handle_interrupt(sdc_irq.p_pt, sdc_irq.p_ildi);
}

enum tfm_hal_status_t adac_request_irq_init(void *p_pt,
                                            const struct irq_load_info_t *p_ildi)
{
    sdc_irq.p_ildi = p_ildi;
    sdc_irq.p_pt = p_pt;

    return TFM_HAL_SUCCESS;
}
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

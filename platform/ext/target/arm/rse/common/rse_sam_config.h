/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_SAM_CONFIG_H__
#define __RSE_SAM_CONFIG_H__

#include "sam_drv.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum rse_sam_event_id_t {
    RSE_SAM_EVENT_LCM_FATAL_ERROR = SAM_EVENT_USECASE_SPECIFIC_START,
    RSE_SAM_EVENT_CPU_LOCKUP,
    RSE_SAM_EVENT_ATU_ERROR,
    RSE_SAM_EVENT_KMU_PARITY_ERROR,
    RSE_SAM_EVENT_CRYPTO_PARITY_ERROR,
    RSE_SAM_EVENT_SIC_PARITY_ERROR,
    RSE_SAM_EVENT_AES_DFA_ERROR,
    RSE_SAM_EVENT_AES_PARITY_ERROR,
    RSE_SAM_EVENT_DMA_DCLS_ERROR,
    RSE_SAM_EVENT_PSI_PARITY_ERROR,
    RSE_SAM_EVENT_BUS_PARITY_ERROR,
    RSE_SAM_EVENT_PROCESSOR_DCLS_ERROR,
    RSE_SAM_EVENT_PROCESSOR_RAS_SET_0,
    RSE_SAM_EVENT_PROCESSOR_RAS_SET_1,
    RSE_SAM_EVENT_PROCESSOR_RAS_SET_2,
    RSE_SAM_EVENT_SRAM_PARTIAL_WRITE,
    RSE_SAM_EVENT_VM0_SINGLE_ECC_ERROR,
    RSE_SAM_EVENT_VM1_SINGLE_ECC_ERROR,
    RSE_SAM_EVENT_VM2_SINGLE_ECC_ERROR,
    RSE_SAM_EVENT_VM3_SINGLE_ECC_ERROR,
    RSE_SAM_EVENT_VM0_DOUBLE_ECC_ERROR,
    RSE_SAM_EVENT_VM1_DOUBLE_ECC_ERROR,
    RSE_SAM_EVENT_VM2_DOUBLE_ECC_ERROR,
    RSE_SAM_EVENT_VM3_DOUBLE_ECC_ERROR,
    RSE_SAM_EVENT_SRAM_MPC_PARITY_ERROR,
    RSE_SAM_EVENT_SIC_MPC_PARITY_ERROR,
    RSE_SAM_EVENT_ATU_PARITY_ERROR,
    RSE_SAM_EVENT_PPR_PARITY_ERROR,
    RSE_SAM_EVENT_SYSCTRL_PARITY_ERROR,
    RSE_SAM_EVENT_CPU_PPB_PARITY_ERROR,
    RSE_SAM_EVENT_SACFG_PARITY_ERROR,
    RSE_SAM_EVENT_NSACFG_PARITY_ERROR,
    RSE_SAM_EVENT_INTEGRITY_CHECKER_ALARM,
    RSE_SAM_EVENT_TRAM_PARITY_ERROR,
    /* Reserved 37-47 */
    RSE_SAM_EVENT_EXTERNAL_SENSOR_0 = 48UL,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_1,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_2,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_3,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_4,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_5,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_6,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_7,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_8,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_9,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_10,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_11,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_12,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_13,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_14,
    RSE_SAM_EVENT_EXTERNAL_SENSOR_15,

    RSE_SAM_EVENT_COUNT = 64
};

/**
 * @brief On the fast-path attack tracking counter increment, first set the counter to
 * the incremented value. Once that is done we don't have any performance
 * constraints any more, so we can leisurely acknowledge the outstanding SAM events
 *
 * This path deliberately minimizes latency between the event being triggered
 * and the attack counter being incremented, since it minimizes the chance that
 * an attacker can reset the system (by cutting the external power supply, since
 * the SAM events are preserved over a cold reset) and in doing so avoid
 * triggering the attack tracking counter increment.
 */
void sam_handle_nmi_event(void);

/**
 * @brief Handle SAM critical severity event.
 *
 * Handle pending SAM events and reset the system.
 */
void sam_handle_critical_serverity_event(void);

/**
 * @brief Select how SAM init should run.
 *
 * - RSE_SAM_INIT_SETUP_HANDLERS_ONLY:
 *     Skip SAM response configuration in the SE LCS state because ADA DMA
 *     provisions SAM responses during secure provisioning.
 *     Also prefer this in stages beyond BL1, since SAM responses only
 *     need to be set once.
 *
 * - RSE_SAM_INIT_SETUP_FULL:
 *     Configure SAM responses and send a manual DMA ACK for trigger 4.
 *     Required in non-SE LCS states (e.g., CM or DM). In SE, ADA DMA is
 *     expected to provision SAM and handle the ACK sequence correctly.
 */
enum rse_sam_init_setup_t {
    RSE_SAM_INIT_SETUP_HANDLERS_ONLY,
    RSE_SAM_INIT_SETUP_FULL,
};

/**
 * @brief Initialize the SAM for RSE.
 *
 * This function sets up the SAM hardware and its event responses according
 * to the provided setup mode. It also registers SAM event handlers and
 * enables SAM interrupts to handle critical and security faults.
 *
 * The setup mode determines whether only event handlers are registered or
 * whether the full SAM response configuration is also performed:
 * - RSE_SAM_INIT_SETUP_HANDLERS_ONLY:
 *   Skip SAM response configuration. Only register handlers.
 *   Used when the SAM responses are expected to be pre-provisioned by ADA DMA
 *   (e.g. in SE state during secure provisioning) or by BL1-1 in non-SE states.
 * - RSE_SAM_INIT_SETUP_FULL:
 *   Configure all SAM responses in software and send a one-time manual
 *   DMA ACK to unblock the SAM FSM. This is required in CM/DM states where
 *   ADA DMA does not provision the SAM.
 *
 * Additionally, if a watchdog event is pending (indicating an NMI handler
 * failure), the attack tracking counter is incremented manually, and all
 * pending events are cleared to ensure a clean state.
 *
 * @param[in] setup  Specifies the initialization mode:
 *                   - RSE_SAM_INIT_SETUP_HANDLERS_ONLY
 *                   - RSE_SAM_INIT_SETUP_FULL
 *
 * @return SAM_ERROR_NONE on success.
 *         A specific `sam_error_t` code if SAM initialization, configuration,
 *         or handler registration fails.
 */
uint32_t rse_sam_init(enum rse_sam_init_setup_t setup);

/**
 * @brief Finalize the SAM setup for the current boot stage.
 *
 * This function disables the SAM-related interrupt lines but keeps
 * SAM event responses active. This allows SAM events with NMI responses
 * to continue functioning during transitions between boot stages.
 *
 * Pending interrupt-driven events will remain queued and will be
 * handled when `rse_sam_init()` re-enables the SAM interrupts.
 */
void rse_sam_finish(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_SAM_CONFIG_H__ */

/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_PC_H
#define PROTECTION_PC_H

#include "fih.h"
#include "tfm_hal_defs.h"

extern fih_int ifx_arch_active_protection_context;

/**
 * \brief Initialize Protection Context switching.
 *
 * Configures the VTOR to implement switching to Protection Context used by SPM.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_pc_init(void);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Validates Protection Context switching critical settings.
 *
 * Checks critical interrupts component use by Protection Context switching.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_pc_verify_static_boundaries(void);
#endif /* TFM_FIH_PROFILE_ON */

/*!
 * \brief Entry point to Protection Context switching via UsageFault/HardFault handler
 *
 * This function schedule UsageFault as an entry point to Protection Context switching.
 * But UsageFault escalates HardFault because masked interrupts are disabled
 * when \ref ifx_arch_switch_protection_context_from_irq is called.
 *
 * HardFault validates that it was called because of `udf` instruction with
 * correct set of arguments pushed via exception stack frame that are duplicate of
 * one prepared by \ref ifx_arch_switch_protection_context_from_irq.
 * HardFault calls Protection Context switching if all validation tests are passed.
 * See \ref PLATFORM_HARD_FAULT_HANDLER_HOOK for more information.
 */
void ifx_arch_switch_protection_context_thread(uint32_t pc);

#endif /* PROTECTION_PC_H */

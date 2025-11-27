/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TARGET_CFG_H
#define TARGET_CFG_H

#include "fih.h"
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Configures the system reset request properties
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
FIH_RET_TYPE(enum tfm_plat_err_t) ifx_system_reset_cfg(void);

/**
 * \brief Configures the system debug properties.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t ifx_init_debug(void);

/**
 * \brief Configures all external interrupts to target the
 *        NS state, apart for the ones associated to secure
 *        peripherals (plus MPC and PPC)
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
FIH_RET_TYPE(enum tfm_plat_err_t) ifx_nvic_interrupt_target_state_cfg(void);

/**
 * \brief Configures Sleep and Exception Handling (System Control Block).
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t ifx_init_system_control_block(void);

#ifdef __cplusplus
}
#endif

#endif /* TARGET_CFG_H */

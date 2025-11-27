/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROVISIONING_H
#define PROVISIONING_H

#include <stdint.h>
#include "psa/lifecycle.h"
#include "cy_device.h"

/**
 * \brief Enumeration used to define debug access port state
 */
typedef enum {
    IFX_DAP_DISABLED,
    IFX_DAP_ENABLED_NS_ONLY,
    IFX_DAP_ENABLED_S_NS,
    IFX_DAP_UNKNOWN,
} ifx_dap_state_t ;

/**
 * \brief Retrieve the security lifecycle of the device
 *
 * \return Security lifecycle state, see PSA_LIFECYCLE_XXX in psa/lifecycle.h
 */
uint32_t ifx_get_security_lifecycle(void);

/**
 * \brief Retrieve the state of debug access port
 *
 * \return debug access port state, see \ref ifx_dap_state_t
 */
ifx_dap_state_t ifx_get_dap_state(void);

#endif /* PROVISIONING_H */

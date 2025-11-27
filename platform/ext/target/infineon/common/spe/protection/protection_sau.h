/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_SAU_H
#define PROTECTION_SAU_H

#include "fih.h"
#include "tfm_hal_defs.h"

/**
 * \brief Configures the SAU.
 *
 * \return  TFM_HAL_SUCCESS       - SAU configured successfully
 *          TFM_HAL_ERROR_GENERIC - failed to configure SAU
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_sau_cfg(void);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Validates critical configuration of SAU.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_sau_verify_static_boundaries(void);
#endif /* TFM_FIH_PROFILE_ON */

#endif /* PROTECTION_SAU_H */

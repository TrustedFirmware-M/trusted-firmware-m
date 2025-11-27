/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file protection_ppc_api.h
 * \brief This file contains PPC driver API declaration.
 *
 * It's expected that PPC driver implementation follows API declared in this file.
 */

#ifndef PROTECTION_PPC_API_H
#define PROTECTION_PPC_API_H

#include "fih.h"
#include "load/asset_defs.h"
#include "protection_types.h"
#include "tfm_hal_defs.h"

/**
 * \brief Configures the Peripheral Protection Controller.
 *
 * \return  TFM_HAL_SUCCESS       - static PPC initialized successfully
 *          TFM_HAL_ERROR_GENERIC - failed to init static PPC
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_init_cfg(void);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Validates critical configuration of PPC.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_verify_static_boundaries(void);
#endif /* TFM_FIH_PROFILE_ON */

/**
 * \brief Apply PPC protection to named MMIO asset.
 *
 * \param[in] ppc_cfg   PPC configuration settings that should be used. See
 *                      \ref ifx_ppc_named_mmio_config_t structure for details.
 * \param[in] asset     Named MMIO asset that should be protected.
 *
 * \return    TFM_HAL_SUCCESS             - PPC configuration applied successfully.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - Asset attributes are not supported.
 *            TFM_HAL_ERROR_INVALID_INPUT - Invalid named asset.
 *            TFM_HAL_ERROR_GENERIC       - Failed to apply PPC configuration.
 */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_isolate_named_mmio(
                                                 const ifx_ppc_named_mmio_config_t* ppc_cfg,
                                                 cy_en_prot_region_t asset);

#endif /* PROTECTION_PPC_API_H */

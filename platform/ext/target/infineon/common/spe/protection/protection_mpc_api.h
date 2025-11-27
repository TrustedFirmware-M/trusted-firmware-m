/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file protection_mpc_api.h
 * \brief This file contains MPC driver API declaration.
 *
 * It's expected that MPC driver implementation follows API declared in this file.
 */

#ifndef PROTECTION_MPC_API_H
#define PROTECTION_MPC_API_H

#include "fih.h"
#include "load/asset_defs.h"
#include "protection_types.h"
#include "tfm_hal_defs.h"

/**
 * \brief Configures the Memory Protection Controller.
 *
 * \return  TFM_HAL_SUCCESS       - static MPC initialized successfully
 *          TFM_HAL_ERROR_GENERIC - failed to init static MPC
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_init_cfg(void);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Validates critical configuration of MPC.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_static_boundaries(void);
#endif /* TFM_FIH_PROFILE_ON */

#if IFX_MPC_CONFIGURED_BY_TFM

/**
 * \brief Apply MPC protection to numbered MMIO asset.
 *
 * \param[in] mpc_cfg   MPC configuration settings that should be used. See
 *                      \ref ifx_mpc_numbered_mmio_config_t structure for more
 *                      details.
 * \param[in] asset     Numbered MMIO asset that should be protected.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - asset can not be protected by MPCs.
 *                                          Can occur when MPC that should
 *                                          protect the asset is not controlled
 *                                          by TFM.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_isolate_numbered_mmio(
                                                    const ifx_mpc_numbered_mmio_config_t* mpc_cfg,
                                                    const struct asset_desc_t* asset);

#endif /* IFX_MPC_CONFIGURED_BY_TFM */

/**
 * \brief Check access to memory region by MPC.
 *
 * \param[in] p_info          Pointer to partition info \ref ifx_partition_info_t.
 * \param[in]   base          The base address of the region.
 * \param[in]   size          The size of the region.
 * \param[in]   access_type   The memory access types to be checked between
 *                            given memory and boundaries.
 *
 * \return TFM_HAL_SUCCESS - The memory region has the access permissions by MPC.
 *         TFM_HAL_ERROR_MEM_FAULT - The memory region has not the access
 *                                   permissions by MPC.
 *         TFM_HAL_ERROR_INVALID_INPUT - Invalid inputs.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_memory_check(const struct ifx_partition_info_t *p_info,
                                                         uintptr_t base,
                                                         size_t size,
                                                         uint32_t access_type);

#endif /* PROTECTION_MPC_API_H */

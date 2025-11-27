/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file protection_mpc_sert.h
 * \brief This file contains the API used by HW MPC driver, to protect memory via SE RT Basic/Full.
 */

#ifndef PROTECTION_MPC_SERT_H
#define PROTECTION_MPC_SERT_H

#include "config_impl.h"
#include "config_tfm.h"
#include "fih.h"
#include "tfm_hal_defs.h"
#include "protection_types.h"

/**
 * \brief Initialize the MPC attribute cache for SE RT Services.
 *
 * This function sets up the RRAM MPC attribute cache used for memory protection checks.
 *
 * \return TFM_HAL_SUCCESS on success, error code otherwise.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_init(void);

/**
 * \brief Apply MPC configuration for MPC controller that is handled by optional
 * SE RT Service or other non-TF-M service/hardware.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_raw_region_config_t for more details.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - configuration can not be applied.
 *                                          Can occur when MPC that should
 *                                          protect the memory is not controlled
 *                                          by TFM.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input (e.g. provided memory
 *                                          region is not supported by external
 *                                          service).
 */
enum tfm_hal_status_t ifx_mpc_sert_apply_configuration(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg);

/**
 * \brief Check memory access permissions using MPC attribute cache.
 *
 * This function validates access permissions for a memory region using the MPC cache.
 *
 * \param[in]  p_info         Partition information structure.
 * \param[in]  memory_config  Memory configuration structure.
 * \param[in]  base           Base address of the memory region.
 * \param[in]  size           Size of the memory region.
 * \param[in]  access_type    Requested access type (read/write/secure/non-secure).
 *
 * \return    TFM_HAL_SUCCESS         - Access is permitted.
 *            TFM_HAL_ERROR_MEM_FAULT - Access is not permitted or invalid input.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_memory_check(
                                           const struct ifx_partition_info_t *p_info,
                                           const ifx_memory_config_t* memory_config,
                                           uintptr_t base,
                                           size_t size,
                                           uint32_t access_type);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Verify MPC configuration using MPC attribute cache.
 *
 * This function checks that the MPC cache matches the expected configuration.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure to verify.
 *
 * \return    TFM_HAL_SUCCESS         - Configuration matches expected values.
 *            TFM_HAL_ERROR_GENERIC   - Configuration does not match or invalid input.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_verify_configuration(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg);
#endif /* TFM_FIH_PROFILE_ON */

#endif /* PROTECTION_MPC_SERT_H */

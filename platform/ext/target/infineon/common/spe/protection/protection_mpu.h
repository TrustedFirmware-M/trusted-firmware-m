/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_MPU_H
#define PROTECTION_MPU_H

#include "config_tfm.h"
#include "fih.h"
#include "load/asset_defs.h"
#include "mpu_armv8m_drv.h"
#include "partition_info.h"
#include "protection_regions_cfg.h"
#include "protection_utils.h"
#include "tfm_hal_defs.h"
#include "load/partition_defs.h"

/**
 * \brief Configures the Memory Protection Unit.
 *
 * \return  TFM_HAL_SUCCESS             - Static MPU initialized successfully
 *          TFM_HAL_ERROR_INVALID_INPUT - Failed to init static MPU
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_init_cfg(void);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Validates critical configuration of MPU.
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_verify_static_boundaries(void);
#endif /* TFM_FIH_PROFILE_ON */

/**
 * \brief Disable MPU regions that are reserved for partition assets.
 */
void ifx_mpu_disable_asset_regions(void);

/**
 * \brief Isolate memory region (numbered MMIO) by MPU
 *
 * \param[in] p_info          Pointer to partition info \ref ifx_partition_info_t
 *                            that is owner of the p_asset
 * \param[in] p_asset         Asset that must be protected by MPU
 *
 * \return  TFM_HAL_SUCCESS             - Numbered MMIO was isolated successfully by MPU
 *          TFM_HAL_ERROR_BAD_STATE     - Failed to isolate numbered MMIO by MPU
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_isolate_numbered_mmio(
                                                    const ifx_partition_info_t *p_info,
                                                    const struct asset_desc_t *p_asset);

#if CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1
/**
 * \brief  Enable/Disable Read-Write access to shared metadata section in MPU
 *
 * \param[in]   enable - if true - enables RW access to shared metadata section,
 *                       if false - enables RO access to shared metadata section
 */
void ifx_mpu_shared_metadata_rw_enable(bool enable);
#endif /* CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1 */

#endif /* PROTECTION_MPU_H */

/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PARTITION_INFO_H
#define PARTITION_INFO_H

#include "load/partition_defs.h"
#include "load/asset_defs.h"
#include "protection_types.h"

/**
 * \brief Return platform specific partition info.
 *
 * \param [in] p_ldinfo  Partition load info. This function uses partition id
 *                       to lookup for partition properties.
 *
 * It's expected that it will be used only once to bind partition boundary by
 * \ref tfm_hal_bind_boundary. In all other cases boundary should be converted
 * to constant pointer to \ref ifx_partition_info_t.
 *
 * \return  Pointer to platform specific partition info
 */
const ifx_partition_info_t * ifx_protection_get_partition_info(
        const struct partition_load_info_t *p_ldinfo);

#ifdef IFX_MEMORY_CONFIGURATOR_MPC_CONFIG
/**
 * \brief Convert memory configuration provided by Device Configurator to TF-M partition asset
 *
 * \param[in] p_region        Pointer to memory region configuration from Device Configurator
 * \param[out] p_asset        Configuration converted to TF-M asset.
 *                            Size is set to zero if configuration must be skipped.
 *
 * \return  true              - Asset is valid, apply configuration.
 *          false             - Skip asset configuration (empty or duplicate).
 *
 * \return  TFM_HAL_SUCCESS             - Valid region
 *          TFM_HAL_ERROR_INVALID_INPUT - Failed to convert memory region
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_domain_mem_get_asset(const ifx_mem_domain_region_cfg_t *p_region,
                                                             struct asset_desc_t *p_asset,
                                                             bool *valid);
#endif

#endif /* PARTITION_INFO_H */

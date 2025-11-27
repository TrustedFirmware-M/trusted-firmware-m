/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_UTILS_H
#define PROTECTION_UTILS_H

#include "protection_types.h"

#if IFX_MPC_DRIVER_HW_MPC
/**
 * \brief Returns configuration of the memory in which provided region is located.
 *
 * \param[in] address       Start address of the region.
 * \param[in] size          Size of the region in byte.
 * \param[in] configs       Pointer to memory configs \ref ifx_memory_config_t array.
 * \param[in] config_count  Number of elements in memory configs array.
 *
 * \return              Pointer to configuration structure. NULL - no
 *                      configuration covers the entire region.
 */
const ifx_memory_config_t* ifx_find_memory_config(uint32_t address,
                                                  uint32_t size,
                                                  const ifx_memory_config_t* const configs[],
                                                  const size_t config_count);

/**
 * \brief Returns all configurations of the memory in which provided region is
 * located. For IFX devices same memory can have different configuration (e.g.
 * different MPC) when accessing from different bus masters.
 *
 * \param[out] memory_config Output array where found configs will be stored.
 * \param[in/out] list_size  Maximum number of elements in memory_config. Can't
 *                           be less than \ref IFX_REGION_MAX_MPC_COUNT.
 * \param[in] mem_address    Start address of the region.
 * \param[in] mem_size       Size of the region in bytes.
 *
 * \return    TFM_HAL_SUCCESS             - all memory configurations were
 *                                          successfully found.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input parameters.
 *            TFM_HAL_ERROR_GENERIC       - failed to find memory configuration
 *                                          for provided region.
 */
enum tfm_hal_status_t ifx_get_all_memory_configs(
                                        const ifx_memory_config_t* memory_config[],
                                        uint32_t* list_size,
                                        uint32_t mem_address,
                                        uint32_t mem_size);
#endif /* IFX_MPC_DRIVER_HW_MPC */

#endif /* PROTECTION_UTILS_H */

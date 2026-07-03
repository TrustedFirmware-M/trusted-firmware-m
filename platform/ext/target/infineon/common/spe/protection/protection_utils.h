/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_UTILS_H
#define PROTECTION_UTILS_H

#include <stddef.h>

#include "protection_types.h"

#if IFX_MPC_DRIVER_HW_MPC
/**
 * \def IFX_MAX_SPLIT_REGIONS_COUNT
 * \brief Maximum number of MPC regions a memory region can span across.
 *
 * This define specifies the upper limit on the number of Memory Protection
 * Controller (MPC) regions that a single memory region can span across. A
 * memory region may span across multiple MPC regions when it crosses boundaries
 * between different memory segments managed by separate MPCs (e.g., a region
 * that starts in SRAM0 and ends in SRAM1).
 *
 * This constant is used to allocate sufficient space for arrays that store
 * information about the split regions when a memory region is divided across
 * multiple MPC controllers.
 * The value of this define should be chosen based on the maximum number of
 * consecutive memory segments with distinct MPC configurations in the target
 * system.
 *
 * \see ifx_split_memory_region_across_mpcs()
 * \see ifx_memory_region_split_t
 */
#ifndef IFX_MAX_SPLIT_REGIONS_COUNT
#error IFX_MAX_SPLIT_REGIONS_COUNT must be defined
#endif

/**
 * \brief Structure representing a memory region split across different MPCs.
 */
typedef struct {
    const ifx_memory_config_t* mpc_config;    /**< MPC configuration for this split region */
    uint32_t region_address;                  /**< Start address of this split region */
    uint32_t region_size;                     /**< Size of this split region */
} ifx_memory_region_split_t;

/**
 * \brief Split a memory region across multiple MPC configurations.
 *
 * This function finds all MPC configurations that overlap with the specified
 * memory region and creates separate sub-regions for each overlapping MPC config.
 * This is useful when a memory region spans across multiple MPCs.
 *
 * \param[in] mem_address     Start address of the memory region to split.
 * \param[in] mem_size        Size of the memory region to split.
 * \param[in] configs         Array of MPC configuration pointers to check.
 * \param[in] config_count    Number of elements in configs array.
 * \param[out] splits         Output array to store the split regions.
 * \param[in,out] split_count Size of the splits array on input, actual count on output.
 *
 * \return    TFM_HAL_SUCCESS                  - Memory region successfully split.
 *            TFM_HAL_ERROR_INVALID_INPUT      - Invalid input parameters.
 *            TFM_HAL_ERROR_GENERIC            - No overlapping MPC configs found or
 *                                               splits don't cover entire region.
 */
enum tfm_hal_status_t ifx_split_memory_region_across_mpcs(
                                        uint32_t mem_address,
                                        uint32_t mem_size,
                                        const ifx_memory_config_t* const configs[],
                                        const size_t config_count,
                                        ifx_memory_region_split_t* splits,
                                        uint32_t* split_count);

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
 * \brief Returns configuration of the memory served by the provided MPC.
 *
 * Unlike \ref ifx_find_memory_config() which matches by address range, this
 * function matches by the MPC controller pointer stored in
 * \ref ifx_memory_config_t::mpc. It is primarily used to obtain the static
 * configuration (e.g. block size) of external MPCs that can't be read directly.
 *
 * \param[out] memory_config Output pointer that receives the matching config.
 * \param[in]  mpc           MPC controller pointer to match against
 *                           \ref ifx_memory_config_t::mpc.
 * \param[in]  configs       Pointer to memory configs \ref ifx_memory_config_t array.
 * \param[in]  config_count  Number of elements in memory configs array.
 *
 * \return    TFM_HAL_SUCCESS             - matching configuration was found.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input parameters.
 *            TFM_HAL_ERROR_GENERIC       - no configuration uses the provided MPC.
 */
enum tfm_hal_status_t ifx_find_memory_config_by_mpc(
                                        const ifx_memory_config_t** memory_config,
                                        const MPC_Type* mpc,
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

/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "protection_utils.h"
#include "protection_data_common.h"
#include "ifx_regions.h"
#include "mxs22.h"

#if IFX_MPC_DRIVER_HW_MPC
enum tfm_hal_status_t ifx_split_memory_region_across_mpcs(
                                        uint32_t mem_address,
                                        uint32_t mem_size,
                                        const ifx_memory_config_t* const configs[],
                                        const size_t config_count,
                                        ifx_memory_region_split_t* splits,
                                        uint32_t* split_count)
{
#if (IFX_MAX_SPLIT_REGIONS_COUNT > 1)
    uint32_t found_splits = 0U;
#endif /* (IFX_MAX_SPLIT_REGIONS_COUNT > 1) */
    uint32_t region_end = mem_address + mem_size;

    if ((splits == NULL) || (split_count == NULL) || (configs == NULL)) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if (*split_count == 0U) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    uint32_t mem_start_alias = IFX_S_ADDRESS_ALIAS(mem_address);
    uint32_t mem_end_alias = IFX_S_ADDRESS_ALIAS(region_end);

    for (size_t idx = 0; idx < config_count; idx++) {
        const ifx_memory_config_t* mpc_config = configs[idx];

        if (mpc_config == NULL) {
            continue;
        }

        uint32_t mpc_start = mpc_config->s_address;
        uint32_t mpc_end = mpc_config->s_address + mpc_config->size;

        /* Check if the region fits entirely within this single MPC (priority check) */
        if (ifx_is_region_inside_other(mem_start_alias, mem_end_alias, mpc_start, mpc_end)) {
            /* Perfect fit - region is completely within one MPC */
            splits[0].mpc_config = mpc_config;
            splits[0].region_address = mem_start_alias;
            splits[0].region_size = mem_size;
            *split_count = 1U;
            return TFM_HAL_SUCCESS;
        }

#if (IFX_MAX_SPLIT_REGIONS_COUNT > 1)
        /* Check if this MPC config overlaps with our memory region */
        if (ifx_is_region_overlap_other(mem_start_alias, mem_end_alias, mpc_start, mpc_end)) {
            if (found_splits >= *split_count) {
                return TFM_HAL_ERROR_MEM_FAULT;
            }

            /* Calculate the overlapping region */
            uint32_t overlap_start = (mem_start_alias > mpc_start) ? mem_start_alias : mpc_start;
            uint32_t overlap_end = (mem_end_alias < mpc_end) ? mem_end_alias : mpc_end;

            /* Store the split region */
            splits[found_splits].mpc_config = mpc_config;
            splits[found_splits].region_address = overlap_start;
            splits[found_splits].region_size = overlap_end - overlap_start;

            found_splits++;
        }
#endif /* (IFX_MAX_SPLIT_REGIONS_COUNT > 1) */
    }

#if (IFX_MAX_SPLIT_REGIONS_COUNT > 1)
    if (found_splits == 0U) {
        return TFM_HAL_ERROR_GENERIC;
    }

    /* Sort splits by address to ensure proper ordering */
    if (found_splits > 1U) {
        for (uint32_t i = 0U; i < (found_splits - 1U); i++) {
            for (uint32_t j = 0U; j < ((found_splits - 1U) - i); j++) {
                if (splits[j].region_address > splits[j + 1U].region_address) {
                    ifx_memory_region_split_t temp = splits[j];
                    splits[j] = splits[j + 1U];
                    splits[j + 1U] = temp;
                }
            }
        }
    }

    *split_count = found_splits;
    return TFM_HAL_SUCCESS;
#else /* (IFX_MAX_SPLIT_REGIONS_COUNT > 1) */
    /* When IFX_MAX_SPLIT_REGIONS_COUNT == 1, we only support single regions */
    return TFM_HAL_ERROR_GENERIC;
#endif /* (IFX_MAX_SPLIT_REGIONS_COUNT > 1) */
}

const ifx_memory_config_t* ifx_find_memory_config(uint32_t address,
                                                  uint32_t size,
                                                  const ifx_memory_config_t* const configs[],
                                                  const size_t config_count)
{
    const ifx_memory_config_t* mpc_config;

    if (configs == NULL) {
        return NULL;
    }

    for (size_t idx = 0; idx < config_count; idx++) {
        mpc_config = configs[idx];

        if (mpc_config == NULL) {
            return NULL;
        }

        if (ifx_is_region_inside_other(IFX_S_ADDRESS_ALIAS(address),
                                       IFX_S_ADDRESS_ALIAS(address) + size,
                                       mpc_config->s_address,
                                       mpc_config->s_address + mpc_config->size)) {
            return mpc_config;
        }
    }

    return NULL;
}

enum tfm_hal_status_t ifx_get_all_memory_configs(
                                        const ifx_memory_config_t* memory_config[],
                                        uint32_t* list_size,
                                        uint32_t mem_address,
                                        uint32_t mem_size)
{
    uint32_t mpc_count = 0U;

    if ((list_size == NULL) || (memory_config == NULL)) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* Ensure that output array is big enough to store maximum length result */
    if (*list_size < IFX_REGION_MAX_MPC_COUNT) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    memory_config[mpc_count] = ifx_find_memory_config(mem_address,
                                                      mem_size,
                                                      ifx_memory_cm33_config,
                                                      ifx_memory_cm33_config_count);

    /* All memory in the system that TFM cares about is accessible by CM33,
     * so if provided memory area is not found in CM33 memory config - error
     * is returned. */
    if (memory_config[mpc_count] == NULL) {
        return TFM_HAL_ERROR_GENERIC;
    }

    ++mpc_count;
#if IFX_MPC_CM55_MPC
    memory_config[mpc_count] = ifx_find_memory_config(mem_address,
                                                      mem_size,
                                                      ifx_memory_cm55_config,
                                                      ifx_memory_cm55_config_count);

    /* Some memory areas have different configs (e.g. different MPC) when
     * accessing from CM55, so CM55 memory config is also checked. If area
     * is not found in CM55 memory config then area has same settings for both
     * CM55 and CM33 bus masters, thus value from CM33 memory config can be used,
     * so in such case no error is returned */
    if (memory_config[mpc_count] != NULL) {
        ++mpc_count;
    }
#endif /* IFX_MPC_CM55_MPC */
    /* Update list size */
    *list_size = mpc_count;

    return TFM_HAL_SUCCESS;
}
#endif /* IFX_MPC_DRIVER_HW_MPC */

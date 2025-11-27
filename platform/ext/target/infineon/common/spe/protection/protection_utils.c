/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "protection_utils.h"
#include "ifx_regions.h"
#include "mxs22.h"


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
    uint32_t mpc_count = 0;

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

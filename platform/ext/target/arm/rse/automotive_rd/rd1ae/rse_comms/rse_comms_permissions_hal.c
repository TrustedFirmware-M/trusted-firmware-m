/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_permissions_hal.h"

#include "device_definition.h"
#include "psa_manifest/sid.h"
#include "tfm_hal_platform.h"
#include "host_base_address.h"

#ifdef TFM_PARTITION_CRYPTO
#include "tfm_crypto_defs.h"
#endif /*TFM_PARTITION_CRYPTO */

#ifdef TFM_PARTITION_PLATFORM
#include "tfm_platform_api.h"
#endif /* TFM_PARTITION_PLATFORM */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
#include "tfm_ps_defs.h"
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
#include "tfm_its_defs.h"
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#define INVALID_REGION_COUNTER_MAX  128
#define INVALID_SERVICE_COUNTER_MAX 64

static uint32_t invalid_region_counter = 0;
static uint32_t invalid_service_counter = 0;

/*
 * Check if the interface is getting a lot of invalid requests, and shutdown
 * the system if it exceeds the threshold. This is intended to make fuzzing the
 * interface difficult.
 */
static void counter_check(void) {
    if (invalid_region_counter > INVALID_REGION_COUNTER_MAX) {
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
        tfm_hal_system_halt();
#else
        tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */
    }

    if (invalid_service_counter > INVALID_SERVICE_COUNTER_MAX) {
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
        tfm_hal_system_halt();
#else
        tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */
    }

    return;
}

/*
 * Check that RSE comms callers have permission to access a memory buffer.
 * The owner must be an MHU device on the platform. Different shared memory
 * space is used for different MHU device.
 */
#define AP_S_NODE_ID (3)

enum tfm_plat_err_t comms_permissions_memory_check(rse_comms_node_id_t node_id,
                                                   uint64_t host_ptr,
                                                   uint32_t size,
                                                   bool is_write)
{
    if (node_id == AP_S_NODE_ID) {
        /* Is fully within the AP Shared SRAM? */
        if (host_ptr >= HOST_AP_SHARED_SRAM_PHYS_BASE &&
            size <= (HOST_AP_SHARED_SRAM_PHYS_LIMIT -
                     HOST_AP_SHARED_SRAM_PHYS_BASE) &&
            host_ptr + size <= HOST_AP_SHARED_SRAM_PHYS_LIMIT) {
            return TFM_PLAT_ERR_SUCCESS;
        }

        /* Is fully within the AP shared DRAM for MHU? */
        if (host_ptr >= HOST_AP_MHU_POINTER_ACCESS_PHYS_BASE &&
            size <= (HOST_AP_MHU_POINTER_ACCESS_PHYS_LIMIT -
                     HOST_AP_MHU_POINTER_ACCESS_PHYS_BASE) &&
            host_ptr + size <= HOST_AP_MHU_POINTER_ACCESS_PHYS_LIMIT) {
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    invalid_region_counter++;
    counter_check();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t comms_permissions_service_check(psa_handle_t handle,
                                                    const psa_invec *in_vec,
                                                    size_t in_len,
                                                    int32_t type)
{
    uint32_t function_id = 0;

    switch(handle) {
#ifdef TFM_PARTITION_CRYPTO
    case TFM_CRYPTO_HANDLE:
        switch(type) {
        case PSA_IPC_CALL:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_CRYPTO */
#ifdef TFM_PARTITION_PLATFORM
    case TFM_PLATFORM_SERVICE_HANDLE:
        switch(type) {
        case TFM_PLATFORM_API_ID_NV_READ:
        case TFM_PLATFORM_API_ID_NV_INCREMENT:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_PLATFORM */
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case TFM_PROTECTED_STORAGE_SERVICE_HANDLE:
        switch(type) {
        case TFM_PS_SET:
        case TFM_PS_GET:
        case TFM_PS_GET_INFO:
        case TFM_PS_REMOVE:
        case TFM_PS_GET_SUPPORT:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    case TFM_INTERNAL_TRUSTED_STORAGE_SERVICE_HANDLE:
        switch (type) {
        case TFM_ITS_SET:
        case TFM_ITS_GET:
        case TFM_ITS_GET_INFO:
        case TFM_ITS_REMOVE:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */
    default:
        goto out_err;
    }

out_err:
    invalid_service_counter++;
    counter_check();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

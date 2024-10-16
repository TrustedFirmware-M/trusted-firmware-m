/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "rse_comms_permissions_hal.h"

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

#define INVALID_REGION_COUNTER_MAX  128
#define INVALID_SERVICE_COUNTER_MAX 64

static uint32_t invalid_region_counter = 0;
static uint32_t invalid_service_counter = 0;

/*
 * Check if the interface is getting a lot of invalid requests, and shutdown
 * the system if it exceeds the threshold. This is intended to make fuzzing the
 * interface difficult.
 */
static void counter_check(void)
{
    if (invalid_region_counter > INVALID_REGION_COUNTER_MAX) {
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
        tfm_hal_system_halt();
#else
        tfm_hal_system_reset();
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */
    }

    if (invalid_service_counter > INVALID_SERVICE_COUNTER_MAX) {
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
        tfm_hal_system_halt();
#else
        tfm_hal_system_reset();
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */
    }

    return;
}

/*
 * This interface is accessed only from root world, so we don't care about the
 * owners of host memory. However, we should still be somewhat discerning about
 * where data is coming from or going to.
 */
enum tfm_plat_err_t comms_permissions_memory_check(void *owner,
                                                   uint64_t host_ptr,
                                                   uint32_t size,
                                                   bool is_write)
{
    /* Accessed only from root world - can be ignored */
    (void)owner;

    /* Is fully within the AP Shared SRAM? */
    if (host_ptr >= HOST_AP_SHARED_SRAM_PHYS_BASE &&
        host_ptr + size <= HOST_AP_SHARED_SRAM_PHYS_LIMIT) {
        return TFM_PLAT_ERR_SUCCESS;
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

    switch (handle) {
#ifdef TFM_PARTITION_CRYPTO
    case TFM_CRYPTO_HANDLE:
        switch (type) {
        case PSA_IPC_CALL:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_CRYPTO */
#ifdef TFM_PARTITION_PLATFORM
    case TFM_PLATFORM_SERVICE_HANDLE:
        switch (type) {
        case TFM_PLATFORM_API_ID_NV_READ:
        case TFM_PLATFORM_API_ID_NV_INCREMENT:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_PLATFORM */
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case TFM_PROTECTED_STORAGE_SERVICE_HANDLE:
        switch (type) {
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
    default:
        goto out_err;
    }

out_err:
    invalid_service_counter++;
    counter_check();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

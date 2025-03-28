/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_permissions_hal.h"

#include "device_definition.h"
#include "psa_manifest/sid.h"
#include "region_defs.h"
#include "tfm_hal_platform.h"

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
#include "tfm_attest_defs.h"
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
#ifdef TFM_PARTITION_MEASURED_BOOT
#include "measured_boot_defs.h"
#endif /* TFM_PARTITION_MEASURED_BOOT */
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
#include "tfm_delegated_attest_defs.h"
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
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
#ifdef TFM_PARTITION_FIRMWARE_UPDATE
#include "tfm_fwu_defs.h"
#endif /* TFM_PARTITION_FIRMWARE_UPDATE */

#define INVALID_REGION_COUNTER_MAX  128
#define INVALID_SERVICE_COUNTER_MAX 64

static uint32_t invalid_region_counter = 0;
static uint32_t invalid_service_counter = 0;

/* Check if the interface is  getting a lot of invalid requests, and shutdown
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

enum tfm_plat_err_t comms_permissions_memory_check(void *owner,
                                                   uint64_t host_ptr,
                                                   uint32_t size,
                                                   bool is_write)
{
    /* Is fully within the shared memory */
    if ((host_ptr >= INTER_PROCESSOR_HOST_SHARED_MEMORY_START_ADDR) &&
        ((host_ptr + size) < (INTER_PROCESSOR_HOST_SHARED_MEMORY_START_ADDR +
                              INTER_PROCESSOR_SHARED_MEMORY_SIZE))) {
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
    switch(handle) {
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
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    case TFM_ATTESTATION_SERVICE_HANDLE:
        switch(type) {
        case TFM_ATTEST_GET_TOKEN:
        case TFM_ATTEST_GET_TOKEN_SIZE:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    case TFM_DELEGATED_ATTESTATION_HANDLE:
        switch(type) {
        case DELEGATED_ATTEST_GET_DELEGATED_KEY:
        case DELEGATED_ATTEST_GET_PLATFORM_TOKEN:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
#ifdef TFM_PARTITION_MEASURED_BOOT
    case TFM_MEASURED_BOOT_HANDLE:
        switch(type) {
        case TFM_MEASURED_BOOT_EXTEND:
        case TFM_MEASURED_BOOT_READ:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_MEASURED_BOOT */
#ifdef TFM_PARTITION_CRYPTO
    case TFM_CRYPTO_HANDLE:
        /* Every crypto operation is done by the SE */
        return TFM_PLAT_ERR_SUCCESS;
#endif /* TFM_PARTITION_CRYPTO */
#ifdef TFM_PARTITION_PLATFORM
    case TFM_PLATFORM_SERVICE_HANDLE:
        switch(type) {
        case TFM_PLATFORM_API_ID_NV_READ:
        case TFM_PLATFORM_API_ID_NV_INCREMENT:
        case TFM_PLATFORM_API_ID_SYSTEM_RESET:
        case TFM_PLATFORM_API_ID_IOCTL:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_PLATFORM */
#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    case TFM_INTERNAL_TRUSTED_STORAGE_SERVICE_HANDLE:
        switch(type) {
        case TFM_ITS_SET:
        case TFM_ITS_GET:
        case TFM_ITS_GET_INFO:
        case TFM_ITS_REMOVE:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */
#ifdef TFM_PARTITION_DPE
    case TFM_DPE_SERVICE_HANDLE:
        return TFM_PLAT_ERR_SUCCESS;
#endif /* TFM_PARTITION_DPE */

#ifdef TFM_PARTITION_FIRMWARE_UPDATE
    case TFM_FIRMWARE_UPDATE_SERVICE_HANDLE:
        switch(type) {
        case TFM_FWU_START:
        case TFM_FWU_WRITE:
        case TFM_FWU_FINISH:
        case TFM_FWU_CANCEL:
        case TFM_FWU_INSTALL:
        case TFM_FWU_CLEAN:
        case TFM_FWU_REJECT:
        case TFM_FWU_REQUEST_REBOOT:
        case TFM_FWU_ACCEPT:
        case TFM_FWU_QUERY:
            return TFM_PLAT_ERR_SUCCESS;
        default:
            goto out_err;
        }
#endif /* TFM_PARTITION_FIRMWARE_UPDATE */
    default:
        goto out_err;
    }

out_err:
    invalid_service_counter++;
    counter_check();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

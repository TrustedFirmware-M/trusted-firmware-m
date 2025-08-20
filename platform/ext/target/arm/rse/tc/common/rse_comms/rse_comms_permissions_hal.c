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
#include "rse_attack_tracking_counter.h"

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

#define AP_MONITOR_NODE_ID (2)

enum tfm_plat_err_t comms_permissions_memory_check(rse_comms_node_id_t node_id,
                                                   uint64_t host_ptr,
                                                   uint32_t size,
                                                   bool is_write)
{
    if (node_id == AP_MONITOR_NODE_ID) {
        /* Is fully within the Secure ROM and is a read */
        if (host_ptr >= 0x0 && host_ptr + size < 0x80000 && !is_write) {
            return TFM_PLAT_ERR_SUCCESS;
        }

        if (host_ptr >= 0x4000000 && host_ptr + size < 0x4080000) {
            return TFM_PLAT_ERR_SUCCESS;
        }
    }

    /* Is fully within the Non-secure ROM and is a read */
    if (host_ptr >= 0x5000000 && host_ptr + size < 0x5080000 && !is_write) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    /* Is fully within the Non-secure RAM */
    if (host_ptr >= 0x6000000 && host_ptr + size < 0x6080000) {
        return TFM_PLAT_ERR_SUCCESS;
    }

#ifdef TFM_PARTITION_DPE
    /* Is fully within the Non-secure SDRAM (BL33) */
    if (host_ptr >= 0x80000000 && host_ptr + size < 0xf9000000) {
        return TFM_PLAT_ERR_SUCCESS;
    }
#endif /* TFM_PARTITION_DPE */

    increment_attack_tracking_counter_minor();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t comms_permissions_service_check(psa_handle_t handle,
                                                    const psa_invec *in_vec,
                                                    size_t in_len,
                                                    int32_t type)
{
    uint32_t function_id = 0;

    switch(handle) {
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
        if (in_len >= 1) {
            function_id = ((struct tfm_crypto_pack_iovec *)in_vec[0].base)->function_id;
            switch(function_id) {
            case TFM_CRYPTO_EXPORT_PUBLIC_KEY_SID:
            case TFM_CRYPTO_GENERATE_RANDOM_SID:
                return TFM_PLAT_ERR_SUCCESS;
            default:
                goto out_err;
            }
        }
        goto out_err;
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
#ifdef TFM_PARTITION_DPE
    case TFM_DPE_SERVICE_HANDLE:
        return TFM_PLAT_ERR_SUCCESS;
#endif /* TFM_PARTITION_DPE */
    default:
        goto out_err;
    }

out_err:
    increment_attack_tracking_counter_minor();

    return TFM_PLAT_ERR_UNSUPPORTED;
}

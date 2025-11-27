/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>

#include "psa_manifest/pid.h"
#include "tfm_plat_nv_counters.h"

enum tfm_plat_err_t tfm_plat_nv_counter_permissions_check(int32_t client_id,
                                                          enum tfm_nv_counter_t nv_counter_no,
                                                          bool is_read)
{
    (void)is_read;

    switch (nv_counter_no) {
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case PLAT_NV_COUNTER_PS_0:
    case PLAT_NV_COUNTER_PS_1:
    case PLAT_NV_COUNTER_PS_2:
        if (client_id == TFM_SP_PS) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
    case PLAT_NV_COUNTER_NS_0:
    case PLAT_NV_COUNTER_NS_1:
    case PLAT_NV_COUNTER_NS_2:
        if (client_id < 0) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
}

enum tfm_plat_err_t tfm_plat_ns_counter_idx_to_nv_counter(uint32_t ns_counter_idx,
                                                          enum tfm_nv_counter_t *counter_id)
{
    if ((ns_counter_idx > (PLAT_NV_COUNTER_NS_MAX - PLAT_NV_COUNTER_NS_0))
        || (counter_id == NULL)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    *counter_id = PLAT_NV_COUNTER_NS_0 + ns_counter_idx;

    return TFM_PLAT_ERR_SUCCESS;
}

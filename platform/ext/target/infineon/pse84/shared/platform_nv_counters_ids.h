/*
 * Copyright (c) 2023-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLATFORM_NV_COUNTERS_IDS_H
#define PLATFORM_NV_COUNTERS_IDS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_nv_counter_t {
    PLAT_NV_COUNTER_PS_0 = 0,  /* Used by PS service */
    PLAT_NV_COUNTER_PS_1,      /* Used by PS service */
    PLAT_NV_COUNTER_PS_2,      /* Used by PS service */

    /* NS counters must be contiguous */
    PLAT_NV_COUNTER_NS_0,      /* Used by NS */
    PLAT_NV_COUNTER_NS_1,      /* Used by NS */
    PLAT_NV_COUNTER_NS_2,      /* Used by NS */
    PLAT_NV_COUNTER_NS_MAX = PLAT_NV_COUNTER_NS_2,

    PLAT_NV_COUNTER_MAX,
    PLAT_NV_COUNTER_BOUNDARY = UINT32_MAX  /* Fix  tfm_nv_counter_t size
                                              to 4 bytes */
};

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_NV_COUNTERS_IDS_H */

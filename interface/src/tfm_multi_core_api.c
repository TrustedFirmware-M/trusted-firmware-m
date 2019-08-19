/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis_os2.h"

#include "platform_multicore.h"
#include "tfm_api.h"
#include "tfm_multi_core_api.h"
#include "tfm_ns_lock.h"

osMutexId_t ns_lock_id;

/**
 * \brief Mutex properties, NS lock
 */
static const osMutexAttr_t ns_lock_attrib = {
    .name = "ns_lock",
    .attr_bits = osMutexPrioInherit
};

/**
 * \brief NS world, Init NS lock
 */
enum tfm_status_e tfm_ns_lock_init(void)
{
    ns_lock_id = osMutexNew(&ns_lock_attrib);
    if (ns_lock_id != NULL) {
        return TFM_SUCCESS;
    } else {
        return TFM_ERROR_GENERIC;
    }
}

int tfm_ns_wait_for_s_cpu_ready(void)
{
    return platform_ns_wait_for_s_cpu_ready();
}

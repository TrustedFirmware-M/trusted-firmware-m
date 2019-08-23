/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "os_wrapper/mutex.h"

#include "tfm_api.h"
#include "tfm_multi_core_api.h"

void *ns_lock_handle = NULL;

__attribute__((weak))
enum tfm_status_e tfm_ns_interface_init(void)
{
    void *handle;

    handle = os_wrapper_mutex_create();
    if (!handle) {
        return TFM_ERROR_GENERIC;
    }

    ns_lock_handle = handle;
    return TFM_SUCCESS;
}

int tfm_ns_wait_for_s_cpu_ready(void)
{
    return tfm_platform_ns_wait_for_s_cpu_ready();
}

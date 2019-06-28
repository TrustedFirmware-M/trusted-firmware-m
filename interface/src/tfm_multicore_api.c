/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_multicore_api.h"
#include "platform_multicore.h"

int tfm_ns_wait_for_s_cpu_ready(void)
{
    return platform_ns_wait_for_s_cpu_ready();
}

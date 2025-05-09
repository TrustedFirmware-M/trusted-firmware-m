/*
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* This file provides implementation of TF-M NS os wrapper functions for the
 * bare metal use case.
 *
 * \note  This implementation does not provide multithread safety, so it
 *        shouldn't be used in RTOS environment.
 */

#include "tfm_ns_interface.h"
#include "common.h"

#ifdef TFM_HYBRID_PLATFORM_API_BROKER
#include "psa/api_broker.h"
#endif

int32_t tfm_ns_interface_dispatch(veneer_fn fn,
                                  uint32_t arg0, uint32_t arg1,
                                  uint32_t arg2, uint32_t arg3)
{
    return fn(arg0, arg1, arg2, arg3);
}

uint32_t tfm_ns_interface_init(void)
{
#ifdef TFM_HYBRID_PLATFORM_API_BROKER
    int32_t ret = tfm_hybrid_plat_api_broker_set_exec_target(TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE);
    if (ret != 0) {
        return OS_WRAPPER_ERROR;
    }
#endif

    return OS_WRAPPER_SUCCESS;
}

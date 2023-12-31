/*
 * Copyright (c) 2021-2023, Arm Limited. All rights reserved.
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_nspm.h"
#include "tfm_ns_ctx.h"
#include "tfm_ns_client_ext.h"
#include "utilities.h"
#include "tfm_arch.h"
#include "tfm_hal_platform.h"

#define DEFAULT_NS_CLIENT_ID ((int32_t)-1)

static int32_t tz_ns_agent_client_id_translate(int32_t client_id_in)
{
    /* TODO: Implement the client ID translation for TZ clients. */
    return client_id_in;
}

int32_t tfm_nspm_get_current_client_id(void)
{
    int32_t input_client_id;

#ifdef TFM_NS_MANAGE_NSID
    input_client_id = get_nsid_from_active_ns_ctx();
#else
    input_client_id = DEFAULT_NS_CLIENT_ID;
#endif
    return tz_ns_agent_client_id_translate(input_client_id);
}

void tfm_nspm_ctx_init(void)
{
#ifdef TFM_PARTITION_NS_AGENT_TZ
    /* SCB_NS.VTOR points to the Non-secure vector table base address */
    SCB_NS->VTOR = tfm_hal_get_ns_VTOR();

    /* Setups Main stack pointer of the non-secure code */
    __TZ_set_MSP_NS(tfm_hal_get_ns_MSP());
#endif

#ifdef TFM_NS_MANAGE_NSID
    if (!init_ns_ctx()) {
        tfm_core_panic();
    }
#endif
}

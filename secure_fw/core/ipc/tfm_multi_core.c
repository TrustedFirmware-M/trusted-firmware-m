/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include "platform/include/tfm_spm_hal.h"
#include "psa_client.h"
#include "secure_utilities.h"
#include "tfm_internal.h"
#include "tfm_nspm.h"
#include "tfm_spe_mailbox.h"

psa_status_t tfm_nspm_thread_entry(void)
{
#ifdef TFM_CORE_DEBUG
    /* Boot up non-secure code */
    LOG_MSG("Enabling non-secure code...");
#endif

    tfm_spm_hal_boot_ns_cpu(tfm_spm_hal_get_ns_VTOR());
    tfm_spm_hal_wait_for_ns_cpu_ready();

    tfm_mailbox_init();

    jump_to_ns_code();

    /*
     * TODO
     * The infinite-loop can be replaced with low-power sleep and resume
     * operation. It may require privileged access to platform specific
     * hardware.
     */
    while (1) {};

    /* Should not run here */
    return PSA_SUCCESS;
}

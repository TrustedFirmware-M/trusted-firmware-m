/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2021-2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "async.h"
#include "config_tfm.h"
#include "psa/service.h"
#include "psa_manifest/ns_agent_mailbox.h"
#include "tfm_hal_mailbox.h"
#include "tfm_hal_multi_core.h"
#include "tfm_hal_platform.h"
#include "tfm_multi_core.h"
#include "tfm_rpc.h"
#include "tfm_sp_log.h"

#include "compiler_ext_defs.h" /* Keep last. */

static void boot_ns_core(void)
{
    /* Boot up non-secure core */
    LOG_DBGFMT("Enabling non-secure core...\r\n");

    tfm_hal_boot_ns_cpu(tfm_hal_get_ns_VTOR());
    tfm_hal_wait_for_ns_cpu_ready();
}

void ns_agent_mailbox_entry(void)
{
    psa_signal_t signals = 0;

    boot_ns_core();

    if (tfm_inter_core_comm_init()) {
        LOG_ERRFMT("Inter-core communication init failed\r\n");
        psa_panic();
    }

    MAILBOX_ENABLE_INTERRUPTS();

    while (1) {
        signals = psa_wait(PSA_WAIT_ANY, PSA_BLOCK);
        if (MAILBOX_SIGNAL_IS_ACTIVE(signals)) {
            psa_eoi(MAILBOX_SIGNAL_GET_ACTIVE(signals));
            tfm_rpc_client_call_handler();
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
        } else if (signals & ASYNC_MSG_REPLY) {
            tfm_rpc_client_call_reply();
#endif
        } else {
            psa_panic();
        }
    }
}

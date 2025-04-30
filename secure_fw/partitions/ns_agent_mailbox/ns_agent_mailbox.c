/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2021-2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "async.h"
#include "config_tfm.h"
#include "ns_agent_mailbox_signal_utils.h"
#include "psa/service.h"
#include "psa_manifest/ns_agent_mailbox.h"
#include "tfm_hal_mailbox.h"
#include "tfm_hal_multi_core.h"
#include "tfm_hal_platform.h"
#include "tfm_multi_core.h"
#include "tfm_rpc.h"
#include "tfm_log_unpriv.h"

#include "compiler_ext_defs.h"

static void boot_ns_core(void)
{
    /* Boot up non-secure core */
    VERBOSE_UNPRIV_RAW("Enabling non-secure core...\n");

    tfm_hal_boot_ns_cpu(tfm_hal_get_ns_VTOR());
    tfm_hal_wait_for_ns_cpu_ready();
}

void ns_agent_mailbox_entry(void)
{
    psa_signal_t signals = 0, active_signal = 0;

    boot_ns_core();

    if (tfm_inter_core_comm_init()) {
        ERROR_UNPRIV_RAW("Inter-core communication init failed\n");
        psa_panic();
    }

    mailbox_enable_interrupts();

    while (1) {
        signals = psa_wait(PSA_WAIT_ANY, PSA_BLOCK);
        while (mailbox_signal_is_active(signals)) {
            active_signal = mailbox_signal_get_active(signals);
            psa_eoi(active_signal);
            tfm_rpc_client_call_handler(active_signal);
            signals &= ~active_signal;
        }
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
        if (signals & ASYNC_MSG_REPLY) {
            tfm_rpc_client_call_reply();
            signals &= ~ASYNC_MSG_REPLY;
        }
#endif
#if (CONFIG_TFM_HYBRID_PLAT_SCHED_TYPE != TFM_HYBRID_PLAT_SCHED_OFF)
        if (signals & NS_AGENT_MBOX_PROCESS_NEW_MSG_SIGNAL) {
            psa_status_t status;
            psa_msg_t msg;
            uint32_t nr_msg;

            status = psa_get(NS_AGENT_MBOX_PROCESS_NEW_MSG_SIGNAL, &msg);
            if (status != PSA_SUCCESS) {
                continue;
            }

            tfm_multi_core_clear_mbox_irq();

            if (msg.type != PSA_IPC_CALL) {
                status = PSA_ERROR_NOT_SUPPORTED;
            } else if (msg.out_size[0] != 4) {
                status = PSA_ERROR_PROGRAMMER_ERROR;
            } else {
                status = (psa_status_t)tfm_rpc_client_process_new_msg(&nr_msg);
                if (status == PSA_SUCCESS) {
                    psa_write(msg.handle, 0, (const void *)&nr_msg, msg.out_size[0]);
                }
            }

            psa_reply(msg.handle, status);
            signals &= ~NS_AGENT_MBOX_PROCESS_NEW_MSG_SIGNAL;
        }
#endif
        if (signals != 0) {
            /* Wrong signal asserted */
            psa_panic();
        }
    }
}

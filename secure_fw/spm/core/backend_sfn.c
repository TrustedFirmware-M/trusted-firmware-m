/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022-2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <assert.h>
#include "compiler_ext_defs.h"
#include "current.h"
#include "runtime_defs.h"
#include "tfm_hal_platform.h"
#include "tfm_nspm.h"
#include "ffm/backend.h"
#include "stack_watermark.h"
#include "load/partition_defs.h"
#include "load/service_defs.h"
#include "load/spm_load_api.h"
#include "psa/error.h"
#include "psa/service.h"
#include "spm.h"
#include "memory_symbols.h"

/* SFN Partition state */
#define SFN_PARTITION_STATE_NOT_INITED        0
#define SFN_PARTITION_STATE_INITED            1

/* Declare the global component list */
struct partition_head_t partition_listhead;

/* Current running partition. */
struct partition_t *p_current_partition;

/*
 * Send message and wake up the SP who is waiting on message queue, block the
 * current component state and activate the next component.
 */
psa_status_t backend_messaging(struct connection_t *p_connection)
{
    struct partition_t *p_target;
    psa_status_t status;

    if (!p_connection || !p_connection->service ||
        !p_connection->service->p_ldinf         ||
        !p_connection->service->partition) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    p_target = p_connection->service->partition;
    p_target->p_reqs = p_connection;

    SET_CURRENT_COMPONENT(p_target);

    if (p_target->state == SFN_PARTITION_STATE_NOT_INITED) {
        if (p_target->p_ldinf->entry != 0) {
            status = ((sfn_init_fn_t)p_target->p_ldinf->entry)(NULL);
            /* Negative value indicates errors. */
            if (status < PSA_SUCCESS) {
                return PSA_ERROR_PROGRAMMER_ERROR;
            }
        }
        p_target->state = SFN_PARTITION_STATE_INITED;
    }

    status = ((service_fn_t)p_connection->service->p_ldinf->sfn)(&p_connection->msg);

    return status;
}

psa_status_t backend_replying(struct connection_t *handle, int32_t status)
{
    SET_CURRENT_COMPONENT(handle->p_client);

    /*
     * Returning a value here is necessary, because 'psa_reply' is absent
     * for SFN clients, the 'reply' method is performed by SPM internally
     * when SFN case, to forward the 'status' to the caller.
     *
     * For example:
     *   'status' MAY contain a 'psa_handle_t' returned by SPM 'connect' and
     *   SPM needs to 'reply' it back to the caller. Treat 'psa_handle_t' value
     *   as SPM specific return value and represnent it as 'psa_status_t'.
     */
    return status;
}

static uint32_t spm_init_function(uint32_t param)
{
    struct partition_t *p_part, *p_curr;
    psa_status_t status;

    p_curr = GET_CURRENT_COMPONENT();
    /* Call partition initialization routine one by one. */
    UNI_LIST_FOREACH(p_part, PARTITION_LIST_ADDR, next) {
        if (IS_IPC_MODEL(p_part->p_ldinf)) {
            continue;
        }

        if (p_part->state == SFN_PARTITION_STATE_INITED) {
            continue;
        }

        SET_CURRENT_COMPONENT(p_part);

        if (p_part->p_ldinf->entry != 0) {
            status = ((sfn_init_fn_t)p_part->p_ldinf->entry)(NULL);
            if (status < PSA_SUCCESS) {
                tfm_core_panic();
            }
        }

        p_part->state = SFN_PARTITION_STATE_INITED;
    }

    SET_CURRENT_COMPONENT(p_curr);

    return param;
}

/* Parameters are treated as assuredly */
void backend_init_comp_assuredly(struct partition_t *p_pt,
                                 uint32_t service_setting)
{
    const struct partition_load_info_t *p_pldi = p_pt->p_ldinf;

    (void)service_setting;

    p_pt->p_reqs = NULL;
    p_pt->state = SFN_PARTITION_STATE_NOT_INITED;

    watermark_stack(p_pt);

    /*
     * Built-in partitions have only one thread instance: NS Agent (TZ or Mailbox)
     * It needs to be specific cared here.
     */
    if (IS_NS_AGENT(p_pldi)) {
        if (IS_NS_AGENT_TZ(p_pldi)) {
            tz_ns_agent_register_client_id_range(p_pt->p_ldinf->client_id_base,
                                                 p_pt->p_ldinf->client_id_limit);
        }
        SET_CURRENT_COMPONENT(p_pt);
    }
}

uint32_t backend_system_run(void)
{
    void *param;
    uint32_t psp;
    uint32_t psp_limit;
    const struct partition_load_info_t *pldi;
    struct partition_t *partition = GET_CURRENT_COMPONENT();

    assert(partition != NULL);

    pldi = partition->p_ldinf;

    if (!IS_NS_AGENT(pldi)) {
        tfm_core_panic();
    }

    /* NS agent expects NSPE entry point as the parameter */
    param      = (void *)tfm_hal_get_ns_entry_point();

    /* Assign stack and stack limit. */
    psp        = arch_seal_thread_stack(((uint32_t)(LOAD_ALLOCED_STACK_ADDR(pldi)) +
                                         (uint32_t)(pldi->stack_size)) & ~0x7UL);
    psp_limit  = ((uint32_t)(LOAD_ALLOCED_STACK_ADDR(pldi)) + 7) & ~0x7UL;

    arch_update_process_sp(psp, psp_limit);

    /*
     * The current execution is Thread mode using MSP.
     * Change to use PSP and reset MSP.
     */
    arch_clean_stack_and_launch(param, (uintptr_t)spm_init_function,
                                pldi->entry, SPM_BOOT_STACK_BOTTOM);

    return 0;
}

psa_signal_t backend_wait_signals(struct partition_t *p_pt, psa_signal_t signals)
{
    while (!(p_pt->signals_asserted & signals)) {
        __WFI();
    }

    return p_pt->signals_asserted & signals;
}

psa_status_t backend_assert_signal(struct partition_t *p_pt, psa_signal_t signal)
{
    p_pt->signals_asserted |= signal;

    return PSA_SUCCESS;
}

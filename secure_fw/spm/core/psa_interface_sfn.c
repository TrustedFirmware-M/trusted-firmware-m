/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "config_impl.h"
#include "current.h"
#include "tfm_psa_call_pack.h"
#include "ffm/backend.h"
#include "ffm/psa_api.h"
#include "psa/client.h"

#ifdef CONFIG_TFM_BACKTRACE_ON_CORE_PANIC
#include "tfm_log.h"
#include "backtrace.h"
#endif

uint32_t psa_framework_version(void)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_client_psa_framework_version();
}

uint32_t psa_version(uint32_t sid)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_client_psa_version(sid);
}

static inline psa_status_t reply_from_rot_service(
    const struct partition_t *p_target,
    psa_status_t status)
{
    if (p_target->p_reqs == NULL) {
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_reply(p_target->p_reqs->msg.handle, status);
}

psa_status_t tfm_psa_call_pack(psa_handle_t handle, uint32_t ctrl_param,
                               const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_client_psa_call(handle, ctrl_param, in_vec, out_vec);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, status);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }

    return (psa_status_t)status;
}

size_t psa_read(psa_handle_t msg_handle, uint32_t invec_idx,
                void *buffer, size_t num_bytes)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_read(msg_handle, invec_idx,
                                       buffer, num_bytes);
}

size_t psa_skip(psa_handle_t msg_handle, uint32_t invec_idx,
                size_t num_bytes)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_skip(msg_handle, invec_idx, num_bytes);
}

void psa_write(psa_handle_t msg_handle, uint32_t outvec_idx,
               const void *buffer, size_t num_bytes)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_write(msg_handle, outvec_idx, buffer, num_bytes);
}

void psa_panic(void)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

#ifdef CONFIG_TFM_BACKTRACE_ON_CORE_PANIC
    tfm_dump_backtrace(__func__, tfm_log);
#endif

    tfm_spm_partition_psa_panic();
}

/* Following PSA APIs are only needed by connection-based services */
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1

psa_handle_t psa_connect(uint32_t sid, uint32_t version)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_client_psa_connect(sid, version);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, status);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }

    return (psa_handle_t)status;
}

void psa_close(psa_handle_t handle)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_client_psa_close(handle);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, PSA_SUCCESS);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }
}

#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */

#if (CONFIG_TFM_FLIH_API == 1) || (CONFIG_TFM_SLIH_API == 1)
psa_signal_t psa_wait(psa_signal_t signal_mask, uint32_t timeout)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_wait(signal_mask, timeout);
}

void psa_irq_enable(psa_signal_t irq_signal)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_irq_enable(irq_signal);
}

psa_irq_status_t psa_irq_disable(psa_signal_t irq_signal)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_irq_disable(irq_signal);
}
#endif

#if CONFIG_TFM_SLIH_API == 1
void psa_eoi(psa_signal_t irq_signal)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_eoi(irq_signal);
}
#endif

#if CONFIG_TFM_FLIH_API == 1
void psa_reset_signal(psa_signal_t irq_signal)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_reset_signal(irq_signal);
}
#endif

#if PSA_FRAMEWORK_HAS_MM_IOVEC

const void *psa_map_invec(psa_handle_t msg_handle, uint32_t invec_idx)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_map_invec(msg_handle, invec_idx);
}

void psa_unmap_invec(psa_handle_t msg_handle, uint32_t invec_idx)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_unmap_invec(msg_handle, invec_idx);
}

void *psa_map_outvec(psa_handle_t msg_handle, uint32_t outvec_idx)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    return tfm_spm_partition_psa_map_outvec(msg_handle, outvec_idx);
}

void psa_unmap_outvec(psa_handle_t msg_handle, uint32_t outvec_idx, size_t len)
{
    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    tfm_spm_partition_psa_unmap_outvec(msg_handle, outvec_idx, len);
}
#endif /* PSA_FRAMEWORK_HAS_MM_IOVEC */

#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
psa_status_t agent_psa_call(psa_handle_t handle,
                            uint32_t control,
                            const struct client_params_t *params,
                            const void *client_data_stateless)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_agent_psa_call(handle, control, params, client_data_stateless);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, status);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }

    return (psa_status_t)status;
}

#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
psa_status_t agent_psa_connect(uint32_t sid, uint32_t version,
                               int32_t ns_client_id, const void *client_data)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_agent_psa_connect(sid, version, ns_client_id, client_data);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, status);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }

    return status;
}

psa_status_t agent_psa_close(psa_handle_t handle, int32_t ns_client_id)
{
    const struct partition_t *p_client, *p_target;
    psa_status_t status;

    if (__get_active_exc_num() != EXC_NUM_THREAD_MODE) {
        /* PSA APIs must be called from Thread mode */
        tfm_core_panic();
    }

    p_client = GET_CURRENT_COMPONENT();

    status = tfm_spm_agent_psa_close(handle, ns_client_id);

    p_target = GET_CURRENT_COMPONENT();
    if (p_client != p_target) {
        /* Execution is returned from RoT Service */
        status = reply_from_rot_service(p_target, PSA_SUCCESS);
    } else {
        /* Execution is returned from SPM */
        spm_handle_programmer_errors(status);
    }

    return status;
}
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */
#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */

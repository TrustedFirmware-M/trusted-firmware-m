/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdint.h>
#include "compiler_ext_defs.h"
#include "config_spm.h"
#include "ffm/psa_api.h"
#include "spm.h"
#include "svc_num.h"
#include "tfm_psa_call_pack.h"
#include "psa/client.h"
#include "psa/lifecycle.h"
#include "psa/service.h"
#include "runtime_defs.h"
#include "tfm_arch.h"

#if defined(__ICCARM__)
#pragma required = tfm_arch_thread_fn_call
#endif

/*
 * Restore target psa api to R12 and step to tfm_arch_thread_fn_call.
 */
#define TFM_THREAD_FN_CALL_ENTRY(target_psa_api)      \
    __asm volatile(                                   \
        SYNTAX_UNIFIED                                \
        "push   {r4, lr}                   \n"        \
        "ldr    r4, ="M2S(target_psa_api)" \n"        \
        "mov    r12, r4                    \n"        \
        "bl     tfm_arch_thread_fn_call    \n"        \
        "pop    {r4, pc}                   \n"        \
    )

__naked
uint32_t psa_framework_version_thread_fn_call(void)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_client_psa_framework_version);
}

__naked
uint32_t psa_version_thread_fn_call(uint32_t sid)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_client_psa_version);
}

__naked
psa_status_t tfm_psa_call_pack_thread_fn_call(psa_handle_t handle,
                                              uint32_t ctrl_param,
                                              const psa_invec *in_vec,
                                              psa_outvec *out_vec)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_client_psa_call);
}

__naked
psa_signal_t psa_wait_thread_fn_call(psa_signal_t signal_mask, uint32_t timeout)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_wait);
}

__naked
psa_status_t psa_get_thread_fn_call(psa_signal_t signal, psa_msg_t *msg)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_get);
}

__naked
size_t psa_read_thread_fn_call(psa_handle_t msg_handle, uint32_t invec_idx,
                               void *buffer, size_t num_bytes)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_read);
}

__naked
size_t psa_skip_thread_fn_call(psa_handle_t msg_handle,
                               uint32_t invec_idx, size_t num_bytes)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_skip);
}

__naked
void psa_write_thread_fn_call(psa_handle_t msg_handle, uint32_t outvec_idx,
                              const void *buffer, size_t num_bytes)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_write);
}

__naked
void psa_reply_thread_fn_call(psa_handle_t msg_handle, psa_status_t status)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_reply);
}

#if CONFIG_TFM_DOORBELL_API == 1
__naked
void psa_notify_thread_fn_call(int32_t partition_id)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_notify);
}

__naked
void psa_clear_thread_fn_call(void)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_clear);
}
#endif /* CONFIG_TFM_DOORBELL_API == 1 */

__naked __NO_RETURN
void psa_panic_thread_fn_call(void)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_panic);
}

__naked
uint32_t psa_rot_lifecycle_state_thread_fn_call(void)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_get_lifecycle_state);
}

/* Following PSA APIs are only needed by connection-based services */
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1

__naked
psa_handle_t psa_connect_thread_fn_call(uint32_t sid, uint32_t version)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_client_psa_connect);
}

__naked
void psa_close_thread_fn_call(psa_handle_t handle)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_client_psa_close);
}

__naked
void psa_set_rhandle_thread_fn_call(psa_handle_t msg_handle, void *rhandle)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_set_rhandle);
}

#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */

#if (CONFIG_TFM_FLIH_API == 1) || (CONFIG_TFM_SLIH_API == 1)
__naked
void psa_irq_enable_thread_fn_call(psa_signal_t irq_signal)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_irq_enable);
}

__naked
psa_irq_status_t psa_irq_disable_thread_fn_call(psa_signal_t irq_signal)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_irq_disable);
}

/* This API is only used for FLIH. */
#if CONFIG_TFM_FLIH_API == 1
__naked
void psa_reset_signal_thread_fn_call(psa_signal_t irq_signal)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_reset_signal);
}
#endif /* CONFIG_TFM_FLIH_API == 1 */

/* This API is only used for SLIH. */
#if CONFIG_TFM_SLIH_API == 1
__naked
void psa_eoi_thread_fn_call(psa_signal_t irq_signal)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_eoi);
}
#endif /* CONFIG_TFM_SLIH_API */
#endif /* CONFIG_TFM_FLIH_API == 1 || CONFIG_TFM_SLIH_API == 1 */

#if PSA_FRAMEWORK_HAS_MM_IOVEC

__naked
const void *psa_map_invec_thread_fn_call(psa_handle_t msg_handle, uint32_t invec_idx)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_map_invec);
}

__naked
void psa_unmap_invec_thread_fn_call(psa_handle_t msg_handle, uint32_t invec_idx)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_unmap_invec);
}

__naked
void *psa_map_outvec_thread_fn_call(psa_handle_t msg_handle, uint32_t outvec_idx)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_map_outvec);
}

__naked
void psa_unmap_outvec_thread_fn_call(psa_handle_t msg_handle, uint32_t outvec_idx,
                                     size_t len)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_partition_psa_unmap_outvec);
}

#endif /* PSA_FRAMEWORK_HAS_MM_IOVEC */

#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
__naked
psa_status_t agent_psa_call_thread_fn_call(psa_handle_t handle,
                                           uint32_t control,
                                           const struct client_params_t *params,
                                           const void *client_data_stateless)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_agent_psa_call);
}

#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
__naked
psa_handle_t agent_psa_connect_thread_fn_call(uint32_t sid, uint32_t version,
                                              int32_t ns_client_id,
                                              const void *client_data)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_agent_psa_connect);
}

__naked
psa_status_t agent_psa_close_thread_fn_call(psa_handle_t handle, int32_t ns_client_id)
{
    TFM_THREAD_FN_CALL_ENTRY(tfm_spm_agent_psa_close);
}
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */
#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */

const struct psa_api_tbl_t psa_api_thread_fn_call = {
                                tfm_psa_call_pack_thread_fn_call,
                                psa_version_thread_fn_call,
                                psa_framework_version_thread_fn_call,
                                psa_wait_thread_fn_call,
                                psa_get_thread_fn_call,
                                psa_read_thread_fn_call,
                                psa_skip_thread_fn_call,
                                psa_write_thread_fn_call,
                                psa_reply_thread_fn_call,
                                psa_panic_thread_fn_call,
                                psa_rot_lifecycle_state_thread_fn_call,
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
                                psa_connect_thread_fn_call,
                                psa_close_thread_fn_call,
                                psa_set_rhandle_thread_fn_call,
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API */
#if CONFIG_TFM_DOORBELL_API == 1
                                psa_notify_thread_fn_call,
                                psa_clear_thread_fn_call,
#endif /* CONFIG_TFM_DOORBELL_API == 1 */
#if (CONFIG_TFM_FLIH_API == 1) || (CONFIG_TFM_SLIH_API == 1)
                                psa_irq_enable_thread_fn_call,
                                psa_irq_disable_thread_fn_call,
#if CONFIG_TFM_FLIH_API == 1
                                psa_reset_signal_thread_fn_call,
#endif /* CONFIG_TFM_FLIH_API == 1 */
#if CONFIG_TFM_SLIH_API == 1
                                psa_eoi_thread_fn_call,
#endif /* CONFIG_TFM_SLIH_API == 1 */
#endif /* CONFIG_TFM_FLIH_API == 1 || CONFIG_TFM_SLIH_API == 1 */
#if PSA_FRAMEWORK_HAS_MM_IOVEC
                                psa_map_invec_thread_fn_call,
                                psa_unmap_invec_thread_fn_call,
                                psa_map_outvec_thread_fn_call,
                                psa_unmap_outvec_thread_fn_call,
#endif /* PSA_FRAMEWORK_HAS_MM_IOVEC */
#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
                                agent_psa_call_thread_fn_call,
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1
                                agent_psa_connect_thread_fn_call,
                                agent_psa_close_thread_fn_call,
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */
#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */
                            };

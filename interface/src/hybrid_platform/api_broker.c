/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "psa/api_broker.h"
#include "psa/client.h"
#include "tfm_ns_interface.h"
#include "psa/api_broker_defs.h"

/*
 * This file implements an API broker used in Hybrid Platforms.
 *
 * It allows a redirection of PSA API function calls from either a local or
 * remote clients, which need to use a different interface: TrustZone or mailbox.
 * The redirection choice selection is performed at initialization time by the
 * respective client.
 */
static enum tfm_hybrid_plat_api_broker_pe_exec_t exec_target =
    TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE;

static uint32_t (*psa_framework_version_f[])(void) = {
    [TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE] = psa_framework_version_tz,
    [TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE] = psa_framework_version_multicore,
};

static uint32_t (*psa_service_version_f[])(uint32_t sid) = {
    [TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE] = psa_version_tz,
    [TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE] = psa_version_multicore,
};

static psa_status_t (*psa_call_f[])(
    psa_handle_t handle,
    int32_t type,
    const psa_invec *in_vec,
    size_t in_len,
    psa_outvec *out_vec,
    size_t out_len) = {
    [TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE] = psa_call_tz,
    [TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE] = psa_call_multicore,
};

static psa_handle_t (*psa_connect_f[])(uint32_t sid, uint32_t version) = {
    [TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE] = psa_connect_tz,
    [TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE] = psa_connect_multicore,
};

static void (*psa_close_f[])(psa_handle_t handle) = {
    [TFM_HYBRID_PLATFORM_API_BROKER_LOCAL_NSPE] = psa_close_tz,
    [TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE] = psa_close_multicore,
};

/*
 * Choose the redirection selection
 */
int32_t tfm_hybrid_plat_api_broker_set_exec_target(
    enum tfm_hybrid_plat_api_broker_pe_exec_t id)
{
    int32_t ret;

    if (id < TFM_HYBRID_PLATFORM_API_BROKER_TYPE_COUNT) {
        exec_target = id;
        ret = 0;
    } else {
        ret = -1;
    }

    return ret;
}

/*
 * API functions redirection
 */
uint32_t psa_framework_version(void)
{
    return psa_framework_version_f[exec_target]();
}

uint32_t psa_version(uint32_t sid)
{
    return psa_service_version_f[exec_target](sid);
}

psa_status_t psa_call(psa_handle_t handle, int32_t type,
                      const psa_invec *in_vec, size_t in_len,
                      psa_outvec *out_vec, size_t out_len)
{
    return psa_call_f[exec_target](
        handle,
        type,
        in_vec,
        in_len,
        out_vec,
        out_len);
}

psa_handle_t psa_connect(uint32_t sid, uint32_t version)
{
    return psa_connect_f[exec_target](sid, version);
}

void psa_close(psa_handle_t handle)
{
    psa_close_f[exec_target](handle);
}

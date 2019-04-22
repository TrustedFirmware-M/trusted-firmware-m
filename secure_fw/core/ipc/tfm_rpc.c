/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdio.h>

#include "tfm_utils.h"

#include "tfm_rpc.h"
#include "tfm_psa_client_call.h"

static const struct tfm_rpc_ops_t *rpc_ops_ptr = NULL;

uint32_t tfm_rpc_psa_framework_version(
                                    const struct client_call_params_t *params)
{
    (void)params;

    return tfm_psa_framework_version();
}

uint32_t tfm_rpc_psa_version(const struct client_call_params_t *params,
                             int32_t ns_caller)
{
    TFM_ASSERT(params != NULL);

    return tfm_psa_version(params->sid, ns_caller);
}

psa_status_t tfm_rpc_psa_connect(const struct client_call_params_t *params,
                                 int32_t ns_caller)
{
    TFM_ASSERT(params != NULL);

    return tfm_psa_connect(params->sid, params->minor_version, ns_caller);
}

psa_status_t tfm_rpc_psa_call(const struct client_call_params_t *params,
                              int32_t ns_caller)
{
    TFM_ASSERT(params != NULL);

    return tfm_psa_call(params->handle, params->in_vec, params->in_len,
                        params->out_vec, params->out_len, ns_caller);
}

void tfm_rpc_psa_close(const struct client_call_params_t *params,
                       int32_t ns_caller)
{
    TFM_ASSERT(params != NULL);

    tfm_psa_close(params->handle, ns_caller);
}

int32_t tfm_rpc_register_ops(const struct tfm_rpc_ops_t *ops_ptr)
{
    if (!ops_ptr) {
        return TFM_RPC_INVAL_PARAM;
    }

    if (!ops_ptr->handle_req || !ops_ptr->reply) {
        return TFM_RPC_INVAL_PARAM;
    }

    /* Currently, one and only one mailbox implementation is supported. */
    if (rpc_ops_ptr) {
        return TFM_RPC_CONFLICT_CALLBACK;
    }

    rpc_ops_ptr = ops_ptr;

    return TFM_RPC_SUCCESS;
}

void tfm_rpc_unregister_ops(const struct tfm_rpc_ops_t *ops_ptr)
{
    (void)ops_ptr;

    rpc_ops_ptr = NULL;
}

void tfm_rpc_client_call_handler(void)
{
    if (rpc_ops_ptr && rpc_ops_ptr->handle_req) {
        rpc_ops_ptr->handle_req();
    }
}

void tfm_rpc_client_call_reply(void *owner, int32_t ret)
{
    if (rpc_ops_ptr && rpc_ops_ptr->reply) {
        rpc_ops_ptr->reply(owner, ret);
    }
}

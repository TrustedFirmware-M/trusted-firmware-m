/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdbool.h>

#include "async.h"
#include "config_impl.h"
#include "ns_agent_mailbox_rpc.h"
#include "spm.h"
#include "tfm_log_unpriv.h"
#include "tfm_rpc.h"

static void default_handle_req(void)
{
    psa_panic();
}

static void default_mailbox_reply(const void *owner, int32_t ret)
{
    (void)owner;
    (void)ret;

    psa_panic();
}

static void default_handle_req_irq_src(uint32_t irq_src)
{
    (void)irq_src;

    psa_panic();
}

static int32_t default_process_new_msg(uint32_t *nr_msg)
{
    return PSA_SUCCESS;
}

static struct tfm_rpc_ops_t rpc_ops = {
    .handle_req = default_handle_req,
    .reply      = default_mailbox_reply,
    .handle_req_irq_src = default_handle_req_irq_src,
    .process_new_msg = default_process_new_msg,
};

int32_t tfm_rpc_register_ops(const struct tfm_rpc_ops_t *ops_ptr)
{
    if (ops_ptr == NULL) {
        return TFM_RPC_INVAL_PARAM;
    }

    if ((ops_ptr->handle_req == NULL) || (ops_ptr->reply == NULL)) {
        return TFM_RPC_INVAL_PARAM;
    }

    /* Currently, one and only one RPC callback instance is supported. */
    if ((rpc_ops.handle_req != default_handle_req) ||
        (rpc_ops.reply != default_mailbox_reply)) {
        return TFM_RPC_CONFLICT_CALLBACK;
    }

    rpc_ops.handle_req = ops_ptr->handle_req;
    rpc_ops.reply = ops_ptr->reply;
    rpc_ops.handle_req_irq_src = default_handle_req_irq_src;
    if (ops_ptr->process_new_msg != NULL) {
        rpc_ops.process_new_msg = ops_ptr->process_new_msg;
    }

    return TFM_RPC_SUCCESS;
}

int32_t tfm_rpc_register_ops_multi_srcs(const struct tfm_rpc_ops_t *ops_ptr)
{
    if (ops_ptr == NULL) {
        return TFM_RPC_INVAL_PARAM;
    }

    if ((ops_ptr->handle_req_irq_src == NULL) || (ops_ptr->reply == NULL)) {
        return TFM_RPC_INVAL_PARAM;
    }

    /* Currently, one and only one RPC callback instance is supported. */
    if ((rpc_ops.handle_req_irq_src != default_handle_req_irq_src) ||
        (rpc_ops.reply != default_mailbox_reply)) {
        return TFM_RPC_CONFLICT_CALLBACK;
    }

    rpc_ops.handle_req = default_handle_req;
    rpc_ops.reply = ops_ptr->reply;
    rpc_ops.handle_req_irq_src = ops_ptr->handle_req_irq_src;
    if (ops_ptr->process_new_msg != NULL) {
        rpc_ops.process_new_msg = ops_ptr->process_new_msg;
    }

    return TFM_RPC_SUCCESS;
}

void tfm_rpc_unregister_ops(void)
{
    rpc_ops.handle_req = default_handle_req;
    rpc_ops.reply = default_mailbox_reply;
    rpc_ops.handle_req_irq_src = default_handle_req_irq_src;
    rpc_ops.process_new_msg = default_process_new_msg;
}

void tfm_rpc_client_call_handler(psa_signal_t signal)
{
    uint32_t irq_src;

    if (rpc_ops.handle_req_irq_src != default_handle_req_irq_src) {
        irq_src = rpc_map_signal_to_irq(signal);
        if (irq_src == INVALID_MAILBOX_IRQ) {
            psa_panic();
        }

        rpc_ops.handle_req_irq_src(irq_src);
        return;
    }

    rpc_ops.handle_req();
}

#if CONFIG_TFM_SPM_BACKEND_IPC == 1
void tfm_rpc_client_call_reply(void)
{
    psa_msg_t msg;
    struct connection_t *handle;
    psa_status_t status = psa_get(ASYNC_MSG_REPLY, &msg);

    if (status != PSA_SUCCESS) {
        ERROR_UNPRIV("psa_get(ASYNC_MSG_REPLY) call returned %d\n", status);
        return;
    }

    handle = (struct connection_t *)msg.rhandle;

    rpc_ops.reply(handle->client_data, status);

    if (handle->status == TFM_HANDLE_STATUS_TO_FREE) {
        spm_free_connection(handle);
    } else {
        handle->status = TFM_HANDLE_STATUS_IDLE;
    }
}
#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1 */

int32_t tfm_rpc_client_process_new_msg(uint32_t *nr_msg)
{
    return rpc_ops.process_new_msg(nr_msg);
}

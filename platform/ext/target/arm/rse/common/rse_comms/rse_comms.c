/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms.h"

#include <stddef.h>
#include <stdint.h>

#include "internal_status_code.h"
#include "rse_comms_hal.h"
#include "rse_comms_queue.h"
#include "tfm_rpc.h"
#include "tfm_multi_core.h"
#include "tfm_hal_multi_core.h"
#include "tfm_psa_call_pack.h"
#include "tfm_sp_log.h"
#include "rse_comms_permissions_hal.h"

static psa_status_t message_dispatch(struct client_request_t *req)
{
    enum tfm_plat_err_t plat_err;

    /* Create the call parameters */
    struct client_params_t params = {
        .p_invecs = req->in_vec,
        .p_outvecs = req->out_vec,
    };

    LOG_DBGFMT("[RSE-COMMS] Received message\r\n");
    LOG_DBGFMT("protocol_ver=%d\r\n", req->protocol_ver);
    LOG_DBGFMT("seq_num=%d\r\n", req->seq_num);
    LOG_DBGFMT("handle=0x%x\r\n", req->handle);
    LOG_DBGFMT("type=%d\r\n", req->type);
    LOG_DBGFMT("in_len=%d\r\n", req->in_len);
    LOG_DBGFMT("out_len=%d\r\n", req->out_len);
    if (req->in_len > 0) {
        LOG_DBGFMT("in_vec[0].len=%d\r\n", req->in_vec[0].len);
    }
    if (req->in_len > 1) {
        LOG_DBGFMT("in_vec[1].len=%d\r\n", req->in_vec[1].len);
    }
    if (req->in_len > 2) {
        LOG_DBGFMT("in_vec[2].len=%d\r\n", req->in_vec[2].len);
    }
    if (req->in_len > 3) {
        LOG_DBGFMT("in_vec[3].len=%d\r\n", req->in_vec[3].len);
    }
    if (req->out_len > 0) {
        LOG_DBGFMT("out_vec[0].len=%d\r\n", req->out_vec[0].len);
    }
    if (req->out_len > 1) {
        LOG_DBGFMT("out_vec[1].len=%d\r\n", req->out_vec[1].len);
    }
    if (req->out_len > 2) {
        LOG_DBGFMT("out_vec[2].len=%d\r\n", req->out_vec[2].len);
    }
    if (req->out_len > 3) {
        LOG_DBGFMT("out_vec[3].len=%d\r\n", req->out_vec[3].len);
    }

    plat_err = comms_permissions_service_check(req->handle,
                                               req->in_vec,
                                               req->in_len,
                                               req->type);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        LOG_ERRFMT("[RSE-COMMS] Call not permitted\r\n");
        return PSA_ERROR_NOT_PERMITTED;
    }

    plat_err = tfm_multi_core_hal_client_id_translate(req->mhu_sender_dev,
                                                      -1 * (int32_t)(req->client_id),
                                                      &params.ns_client_id_stateless);
    if (plat_err != SPM_SUCCESS) {
        LOG_ERRFMT("[RSE-COMMS] Invalid client_id: 0x%x\r\n",
                    (uint32_t)(req->client_id));
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return tfm_rpc_psa_call(req->handle,
                            PARAM_PACK(req->type,
                                       req->in_len,
                                       req->out_len),
                            &params,
                            req);
}

static void rse_comms_reply(const void *owner, int32_t ret)
{
    struct client_request_t *req = (struct client_request_t *)owner;

    req->return_val = ret;

    LOG_DBGFMT("[RSE-COMMS] Sending reply\r\n");
    LOG_DBGFMT("protocol_ver=%d\r\n", req->protocol_ver);
    LOG_DBGFMT("seq_num=%d\r\n", req->seq_num);
    LOG_DBGFMT("client_id=%d\r\n", req->client_id);
    LOG_DBGFMT("return_val=%d\r\n", req->return_val);
    LOG_DBGFMT("out_vec[0].len=%d\r\n", req->out_vec[0].len);
    LOG_DBGFMT("out_vec[1].len=%d\r\n", req->out_vec[1].len);
    LOG_DBGFMT("out_vec[2].len=%d\r\n", req->out_vec[2].len);
    LOG_DBGFMT("out_vec[3].len=%d\r\n", req->out_vec[3].len);

    if (tfm_multi_core_hal_reply(req) != TFM_PLAT_ERR_SUCCESS) {
        LOG_DBGFMT("[RSE-COMMS] Sending reply failed!\r\n");
    }
}

static void rse_comms_handle_req(void)
{
    psa_status_t status;
    void *queue_entry;
    struct client_request_t *req;

    /* FIXME: consider memory limitations that may prevent dispatching all
     * messages in one go.
     */
    while (queue_dequeue(&queue_entry) == 0) {
        /* Deliver PSA Client call request to handler in SPM. */
        req = queue_entry;
        status = message_dispatch(req);
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
        /*
         * If status == PSA_SUCCESS, peer will be replied when mailbox agent
         * partition receives a 'ASYNC_MSG_REPLY' signal from the requested
         * service partition.
         * If status != PSA_SUCCESS, the service call has been finished.
         * Reply to the peer directly.
         */
        if (status != PSA_SUCCESS) {
            LOG_DBGFMT("[RSE-COMMS] Message dispatch failed: %d\r\n", status);
            rse_comms_reply(req, status);
        }
#else
        /* In SFN model, the service call has been finished. Reply to the peer directly. */
        rse_comms_reply(req, status);
#endif
    }
}

static struct tfm_rpc_ops_t rpc_ops = {
    .handle_req = rse_comms_handle_req,
    .reply = rse_comms_reply,
};

int32_t tfm_inter_core_comm_init(void)
{
    int32_t ret;

    /* Register RPC callbacks */
    ret = tfm_rpc_register_ops(&rpc_ops);
    if (ret != TFM_RPC_SUCCESS) {
        return ret;
    }

    /* Platform specific initialization */
    ret = tfm_multi_core_hal_init();
    if (ret != TFM_PLAT_ERR_SUCCESS) {
        tfm_rpc_unregister_ops();
        return ret;
    }

    return TFM_RPC_SUCCESS;
}

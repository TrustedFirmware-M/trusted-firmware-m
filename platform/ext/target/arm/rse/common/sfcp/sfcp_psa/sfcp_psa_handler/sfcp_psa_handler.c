/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_psa_client_request.h"

#include <stddef.h>
#include <stdint.h>

#include "internal_status_code.h"
#include "sfcp_runtime_hal.h"
#include "sfcp_psa_queue.h"
#include "tfm_rpc.h"
#include "tfm_multi_core.h"
#include "tfm_hal_multi_core.h"
#include "tfm_psa_call_pack.h"
#include "tfm_log_unpriv.h"
#include "tfm_peripherals_def.h"
#include "tfm_pools.h"
#include "sfcp_permissions_hal.h"
#include "sfcp.h"
#include "sfcp_psa_protocol.h"
#include "sfcp_link_hal.h"
#include "sfcp_platform.h"
#include "critical_section.h"

struct sfcp_pool_entry_t {
    sfcp_buffer_handle_t buffer_handle;
    struct client_request_t req;
    struct sfcp_msg_metadata_t metadata;
};

TFM_POOL_DECLARE(sfcp_pool, sizeof(struct sfcp_pool_entry_t), SFCP_PSA_HANDLER_MAX_CONCURRENT_REQ);

/* Use for both the message and reply, define to the larger of
 * the two */
static __ALIGNED(4) uint8_t
    psa_payload_buf[SFCP_BUFFER_MINIMUM_SIZE +
                    (sizeof(struct serialized_psa_msg_t) > sizeof(struct serialized_psa_reply_t) ?
                         sizeof(struct serialized_psa_msg_t) :
                         sizeof(struct serialized_psa_reply_t))];

static psa_status_t message_deserialize_dispatch(struct sfcp_pool_entry_t *pool_entry,
                                                 uint8_t *payload, size_t payload_size)
{
    enum tfm_plat_err_t plat_err;
    struct client_request_t *req = &pool_entry->req;

    plat_err =
        sfcp_protocol_deserialize_msg(req, (struct serialized_psa_msg_t *)payload, payload_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        ERROR_UNPRIV_RAW("[SFCP] Deserialize failed: %d\n", plat_err);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Create the call parameters */
    struct client_params_t params = {
        .p_invecs = req->in_vec,
        .p_outvecs = req->out_vec,
    };

    VERBOSE_UNPRIV_RAW("[SFCP] Received message\n");
    VERBOSE_UNPRIV_RAW("protocol_ver=%d\n", req->protocol_ver);
    VERBOSE_UNPRIV_RAW("handle=0x%x\n", req->handle);
    VERBOSE_UNPRIV_RAW("type=%d\n", req->type);
    VERBOSE_UNPRIV_RAW("in_len=%d\n", req->in_len);
    VERBOSE_UNPRIV_RAW("out_len=%d\n", req->out_len);
    if (req->in_len > 0) {
        VERBOSE_UNPRIV_RAW("in_vec[0].len=%d\n", req->in_vec[0].len);
    }
    if (req->in_len > 1) {
        VERBOSE_UNPRIV_RAW("in_vec[1].len=%d\n", req->in_vec[1].len);
    }
    if (req->in_len > 2) {
        VERBOSE_UNPRIV_RAW("in_vec[2].len=%d\n", req->in_vec[2].len);
    }
    if (req->in_len > 3) {
        VERBOSE_UNPRIV_RAW("in_vec[3].len=%d\n", req->in_vec[3].len);
    }
    if (req->out_len > 0) {
        VERBOSE_UNPRIV_RAW("out_vec[0].len=%d\n", req->out_vec[0].len);
    }
    if (req->out_len > 1) {
        VERBOSE_UNPRIV_RAW("out_vec[1].len=%d\n", req->out_vec[1].len);
    }
    if (req->out_len > 2) {
        VERBOSE_UNPRIV_RAW("out_vec[2].len=%d\n", req->out_vec[2].len);
    }
    if (req->out_len > 3) {
        VERBOSE_UNPRIV_RAW("out_vec[3].len=%d\n", req->out_vec[3].len);
    }

    plat_err = comms_permissions_service_check(req->handle, req->in_vec, req->in_len, req->type);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        ERROR_UNPRIV_RAW("[SFCP] Call not permitted\n");
        return PSA_ERROR_NOT_PERMITTED;
    }

    plat_err = tfm_multi_core_hal_client_id_translate(
        (void *)(sfcp_platform_get_send_device(sfcp_hal_get_route(req->remote_id)).device),
        -1 * (int32_t)(req->client_id), &params.ns_client_id_stateless);
    if (plat_err != SPM_SUCCESS) {
        ERROR_UNPRIV_RAW("[SFCP] Invalid client_id: 0x%x\n", (uint32_t)(req->client_id));
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return tfm_rpc_psa_call(req->handle, PARAM_PACK(req->type, req->in_len, req->out_len), &params,
                            pool_entry);
}

static void sfcp_reply(const void *owner, int32_t ret)
{
    struct sfcp_pool_entry_t *pool_entry = (struct sfcp_pool_entry_t *)owner;
    struct client_request_t *req = &pool_entry->req;
    enum sfcp_error_t sfcp_err;
    enum tfm_plat_err_t plat_err;
    size_t reply_size;
    uint8_t *payload;
    size_t payload_len;
    size_t psa_payload_size;
    struct sfcp_packet_t *reply;
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;

    req->return_val = ret;

    VERBOSE_UNPRIV_RAW("[SFCP] Sending reply\n");
    VERBOSE_UNPRIV_RAW("protocol_ver=%d\n", req->protocol_ver);
    VERBOSE_UNPRIV_RAW("client_id=%d\n", req->client_id);
    VERBOSE_UNPRIV_RAW("return_val=%d\n", req->return_val);
    VERBOSE_UNPRIV_RAW("out_vec[0].len=%d\n", req->out_vec[0].len);
    VERBOSE_UNPRIV_RAW("out_vec[1].len=%d\n", req->out_vec[1].len);
    VERBOSE_UNPRIV_RAW("out_vec[2].len=%d\n", req->out_vec[2].len);
    VERBOSE_UNPRIV_RAW("out_vec[3].len=%d\n", req->out_vec[3].len);

    sfcp_err = sfcp_init_reply(psa_payload_buf, sizeof(psa_payload_buf), pool_entry->metadata,
                               &payload, &payload_len, &reply, &reply_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        plat_err = (enum tfm_plat_err_t)sfcp_err;
        goto out_error;
    }

    if (payload_len < sizeof(struct serialized_psa_reply_t)) {
        plat_err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_error;
    }

    plat_err = sfcp_protocol_serialize_reply(req, (struct serialized_psa_reply_t *)payload,
                                             &psa_payload_size);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        goto out_error;
    }

    sfcp_err = sfcp_send_reply(reply, reply_size, psa_payload_size);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        plat_err = (enum tfm_plat_err_t)sfcp_err;
        goto out_error;
    }

    goto out_free;

out_error:
    VERBOSE_UNPRIV_RAW("[SFCP] Sending reply failed!: %d\n", plat_err);
out_free:
    /* Prevent concurrent queue accesses from sfcp_handler which is called
     * in interrupt context
     */
    CRITICAL_SECTION_ENTER(cs_assert);
    tfm_pool_free(sfcp_pool, pool_entry);
    CRITICAL_SECTION_LEAVE(cs_assert);
}

static void sfcp_handle_req(void)
{
    psa_status_t status;
    enum sfcp_error_t sfcp_err;
    void *queue_entry;
    struct sfcp_pool_entry_t *pool_entry;
    sfcp_node_id_t sender;
    uint16_t client_id;
    bool needs_reply;
    size_t payload_size;
    int32_t queue_err;
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;

    /* FIXME: consider memory limitations that may prevent dispatching all
     * messages in one go.
     */
    while (1) {
        /* Prevent concurrent queue accesses from sfcp_handler which is called
         * in interrupt context
         */
        CRITICAL_SECTION_ENTER(cs_assert);
        queue_err = queue_dequeue(&queue_entry);
        CRITICAL_SECTION_LEAVE(cs_assert);

        if (queue_err != 0) {
            break;
        }

        pool_entry = queue_entry;

        /*
         * Only need to zero out client_request_t as rest of pool entry
         * will be completely populated
         */
        memset(&pool_entry->req, 0, sizeof(pool_entry->req));

        sfcp_err = sfcp_pop_msg_from_buffer(pool_entry->buffer_handle, &sender, &client_id,
                                            &needs_reply, psa_payload_buf, sizeof(psa_payload_buf),
                                            &payload_size, &pool_entry->metadata);
        if (sfcp_err != SFCP_ERROR_SUCCESS) {
            VERBOSE_UNPRIV_RAW("[SFCP] Pop msg from buffer failed: %d\n", sfcp_err);
            continue;
        }

        if (!needs_reply) {
            VERBOSE_UNPRIV_RAW("[SFCP] Expecting a message which needs a reply\n");
            continue;
        }

        pool_entry->req.client_id = client_id;
        pool_entry->req.remote_id = sender;

        /* Deliver PSA Client call request to handler in SPM. */
        status = message_deserialize_dispatch(pool_entry, psa_payload_buf, payload_size);
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
        /*
         * If status == PSA_SUCCESS, peer will be replied when mailbox agent
         * partition receives a 'ASYNC_MSG_REPLY' signal from the requested
         * service partition.
         * If status != PSA_SUCCESS, the service call has been finished.
         * Reply to the peer directly.
         */
        if (status != PSA_SUCCESS) {
            VERBOSE_UNPRIV_RAW("[SFCP] Message deserialize and dispatch failed: %d\n", status);
            sfcp_reply(pool_entry, status);
        }
#else
        /* In SFN model, the service call has been finished. Reply to the peer directly. */
        sfcp_reply(pool_entry, status);
#endif
    }
}

static enum sfcp_error_t sfcp_handler(sfcp_buffer_handle_t buffer_handle)
{
    struct sfcp_pool_entry_t *pool_entry;
    enum sfcp_error_t sfcp_err;
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;

    /* This function is called in the interrupt context but we need to
     * prevent potential concurrent access from higher priority interrupts
     */
    CRITICAL_SECTION_ENTER(cs_assert);

    pool_entry = tfm_pool_alloc(sfcp_pool);
    if (pool_entry == NULL) {
        sfcp_err = SFCP_ERROR_INVALID_POINTER;
        goto out;
    }

    pool_entry->buffer_handle = buffer_handle;

    if (queue_enqueue(pool_entry) != 0) {
        sfcp_err = SFCP_ERROR_INVALID_POINTER;
        goto error_free;
    }

    sfcp_err = SFCP_ERROR_SUCCESS;
    goto out;

error_free:
    tfm_pool_free(sfcp_pool, pool_entry);
out:
    CRITICAL_SECTION_LEAVE(cs_assert);
    return sfcp_err;
}

static struct tfm_rpc_ops_t rpc_ops = {
    .handle_req = sfcp_handle_req,
    .reply = sfcp_reply,
};

int32_t tfm_inter_core_comm_init(void)
{
    int32_t ret;
    psa_status_t psa_err;
    enum sfcp_error_t sfcp_err;

    /* Register RPC callbacks */
    ret = tfm_rpc_register_ops(&rpc_ops);
    if (ret != TFM_RPC_SUCCESS) {
        return ret;
    }

    /* Platform specific initialization */
    ret = tfm_multi_core_hal_init();
    if (ret != TFM_PLAT_ERR_SUCCESS) {
        goto out_unregister_ops;
    }

    psa_err = tfm_pool_init(sfcp_pool, POOL_BUFFER_SIZE(sfcp_pool),
                            sizeof(struct sfcp_pool_entry_t), SFCP_MAX_CONCURRENT_REQ);
    if (psa_err != PSA_SUCCESS) {
        ret = (int32_t)psa_err;
        goto out_unregister_ops;
    }

    sfcp_err = sfcp_register_msg_handler(0, sfcp_handler);
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        ret = (int32_t)sfcp_err;
        goto out_unregister_ops;
    }

    return TFM_PLAT_ERR_SUCCESS;

out_unregister_ops:
    tfm_rpc_unregister_ops();
    return ret;
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "sfcp_psa_protocol_pointer_access.h"
#include "sfcp_psa_client_request.h"

#include "tfm_psa_call_pack.h"
#include "sfcp_permissions_hal.h"

psa_status_t sfcp_protocol_pointer_access_serialize_msg(psa_handle_t handle, int16_t type,
                                                        const psa_invec *in_vec, uint8_t in_len,
                                                        const psa_outvec *out_vec, uint8_t out_len,
                                                        struct sfcp_pointer_access_msg_t *msg,
                                                        size_t *msg_len)
{
    uint8_t i;

    assert(msg != NULL);
    assert(msg_len != NULL);
    assert(in_vec != NULL);

    msg->ctrl_param = PARAM_PACK(type, in_len, out_len);
    msg->handle = handle;

    /* Fill msg iovec lengths */
    for (i = 0U; i < in_len; ++i) {
        msg->io_sizes[i] = in_vec[i].len;
        msg->host_ptrs[i] = (uint64_t)in_vec[i].base;
    }
    for (i = 0U; i < out_len; ++i) {
        msg->io_sizes[in_len + i] = out_vec[i].len;
        msg->host_ptrs[in_len + i] = (uint64_t)out_vec[i].base;
    }

    *msg_len = sizeof(*msg);

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_pointer_access_deserialize_msg(struct client_request_t *req,
                                                          struct sfcp_pointer_access_msg_t *msg,
                                                          size_t msg_len)
{
    psa_status_t err;
    uint32_t idx;
    void *mapped_host_ptr;
    uint8_t atu_region;

    if (msg_len != sizeof(*msg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    req->in_len = PARAM_UNPACK_IN_LEN(msg->ctrl_param);
    req->out_len = PARAM_UNPACK_OUT_LEN(msg->ctrl_param);
    req->type = PARAM_UNPACK_TYPE(msg->ctrl_param);
    req->handle = msg->handle;

    /* Only support 4 iovecs */
    if (req->in_len + req->out_len > PSA_MAX_IOVEC) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Invecs */
    for (idx = 0; idx < req->in_len; idx++) {
        err = comms_permissions_memory_check(req->remote_id, msg->host_ptrs[idx],
                                             msg->io_sizes[idx], false);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_NOT_PERMITTED;
        }

        err = comms_atu_alloc_region(msg->host_ptrs[idx], msg->io_sizes[idx], &atu_region);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err = comms_atu_add_region_to_set(&req->atu_regions, atu_region);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err =
            comms_atu_get_rse_ptr_from_host_addr(atu_region, msg->host_ptrs[idx], &mapped_host_ptr);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        req->in_vec[idx].base = mapped_host_ptr;
        req->in_vec[idx].len = msg->io_sizes[idx];
    }

    /* Outvecs */
    for (idx = 0; idx < req->out_len; idx++) {
        err = comms_permissions_memory_check(req->remote_id, msg->host_ptrs[idx + req->in_len],
                                             msg->io_sizes[idx + req->in_len], true);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_NOT_PERMITTED;
        }

        err = comms_atu_alloc_region(msg->host_ptrs[idx + req->in_len],
                                     msg->io_sizes[idx + req->in_len], &atu_region);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err = comms_atu_add_region_to_set(&req->atu_regions, atu_region);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        err = comms_atu_get_rse_ptr_from_host_addr(atu_region, msg->host_ptrs[idx + req->in_len],
                                                   &mapped_host_ptr);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        req->out_vec[idx].base = mapped_host_ptr;
        req->out_vec[idx].len = msg->io_sizes[idx + req->in_len];
    }

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_pointer_access_serialize_reply(struct client_request_t *req,
                                                          struct sfcp_pointer_access_reply_t *reply,
                                                          size_t *reply_size)
{
    uint32_t idx;

    reply->return_val = req->return_val;

    /* Outvecs */
    for (idx = 0; idx < req->out_len; idx++) {
        reply->out_size[idx] = req->out_vec[idx].len;
    }

    *reply_size = sizeof(*reply);
    comms_atu_free_regions(req->atu_regions);

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_pointer_access_deserialize_reply(
    psa_outvec *out_vec, uint8_t out_len, psa_status_t *return_val,
    const struct sfcp_pointer_access_reply_t *reply, size_t reply_size)
{
    uint8_t i;

    assert(reply != NULL);
    assert(return_val != NULL);

    for (i = 0U; i < out_len; ++i) {
        out_vec[i].len = reply->out_size[i];
    }

    *return_val = reply->return_val;

    return PSA_SUCCESS;
}

psa_status_t sfcp_protocol_pointer_access_serialize_error(struct client_request_t *req,
                                                          psa_status_t err,
                                                          struct sfcp_pointer_access_reply_t *reply,
                                                          size_t *reply_size)
{
    reply->return_val = err;

    /* The out_sizes are already zeroed by the caller. */

    *reply_size = sizeof(*reply);
    if (req != NULL) {
        comms_atu_free_regions(req->atu_regions);
    }

    return PSA_SUCCESS;
}

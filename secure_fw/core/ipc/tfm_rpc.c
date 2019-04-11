/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <inttypes.h>
#include <stdio.h>
#include "tfm_internal_defines.h"
#include "tfm_rpc.h"
#include "psa_client.h"
#include "psa_service.h"
#include "tfm_svc.h"
#include "tfm_svcalls.h"
#include "secure_utilities.h"
#include "tfm_memory_utils.h"

static uint32_t dispatch_control_msg(struct tfm_rpc_payload_t *p_ctrl,
psa_invec *invecs, uint32_t in_len, psa_outvec *outvec, uint32_t out_len)
{
    uint32_t args[5];
    uint32_t *p_data = (uint32_t *)p_ctrl->data;

    if (p_ctrl->ilen < sizeof(uint32_t))
        return IPC_ERROR_BAD_PARAMETERS;

    switch(p_data[0]) {
        case TRPC_CTRL_CONNECT:
            if (p_ctrl->ilen < 4 * sizeof(uint32_t))
                return IPC_ERROR_BAD_PARAMETERS;
            args[0] = p_data[1];
            args[1] = p_data[2];
            tfm_svcall_psa_connect(args, 1);
            return IPC_SUCCESS;
        case TRPC_CTRL_CALL:
            if (p_ctrl->ilen < 3 * sizeof(uint32_t))
                return IPC_ERROR_BAD_PARAMETERS;
            args[0] = p_data[1];
            args[1] = (uint32_t)invecs;
            args[2] = in_len;
            args[3] = (uint32_t)outvec;
            args[4] = out_len;
            /* FixMe - pass lr as 0, it is only used for getting the FPU context */
            tfm_svcall_psa_call(args, 1, 0);
            return IPC_SUCCESS;
        case TRPC_CTRL_CLOSE:
            if (p_ctrl->ilen < sizeof(uint32_t))
                return IPC_ERROR_BAD_PARAMETERS;
            tfm_svcall_psa_close(args, 1);
            return IPC_SUCCESS;
        default:
            break;
    }
    return IPC_ERROR_BAD_PARAMETERS;
}

static int32_t reply_control_msg(struct tfm_rpc_payload_t *p_ctrl, uint32_t reply)
{
    uint32_t *p_data = (uint32_t *)p_ctrl->data;

    if (p_ctrl->ilen < sizeof(*p_data))
        return IPC_ERROR_BAD_PARAMETERS;

    switch(p_data[0]) {
        case TRPC_CTRL_CONNECT:
            if (p_ctrl->ilen < 4 * sizeof(uint32_t))
                return IPC_SUCCESS;
            p_data[3] = reply;
            return IPC_SUCCESS;
        case TRPC_CTRL_CALL:
            if (p_ctrl->ilen < 3 * sizeof(uint32_t))
                return IPC_SUCCESS;
            p_data[2] = reply;
        case TRPC_CTRL_CLOSE:
            return IPC_SUCCESS;
        default:
            break;
    }
    return IPC_ERROR_BAD_PARAMETERS;
}

static int32_t checking_msg_header(void *msg, size_t size, uint32_t target_sync)
{
    struct tfm_rpc_msg_header_t *p_header = (struct tfm_rpc_msg_header_t *)msg;

    if (p_header == NULL || size <= sizeof(*p_header) || ((uintptr_t)p_header) & 0x3)
        return IPC_ERROR_BAD_PARAMETERS;

    if (p_header->magic != TRPC_MAGIC ||
        p_header->len + sizeof(*p_header) > size ||
        p_header->sync != target_sync ||
        (p_header->len & 0x3))
        return IPC_ERROR_BAD_PARAMETERS;

    return IPC_SUCCESS;
}

int32_t tfm_rpc_service_reply(void *buf, uint32_t size, uint32_t reply,
    void *outv)
{
    uint32_t i;
    struct tfm_rpc_payload_t *p_load, *p_ctrl;
    struct tfm_rpc_msg_header_t *p_header = (struct tfm_rpc_msg_header_t *)buf;
    uintptr_t msg_limit = (uintptr_t)buf + size;
    psa_outvec *outvec = (psa_outvec *)outv;

    if (checking_msg_header(buf, size, TRPC_SYNC_LOCK) != IPC_SUCCESS)
        return IPC_ERROR_BAD_PARAMETERS;

    p_load = (struct tfm_rpc_payload_t *)p_header->payloads;
    p_ctrl = NULL;

    while ((uintptr_t)p_load + sizeof(*p_load) < msg_limit) {
        if (p_load->ilen == 0)
            break;

        if (p_load->type == TRPC_PAYLOAD_CTRL) {
            p_ctrl = p_load;
        }

        if (p_load->type == TRPC_PAYLOAD_OUTPUT) {
            for (i = 0; i < PSA_MAX_IOVEC; i++) {
                if (outvec[i].base == p_load->data && outvec[i].len <= p_load->ilen)
                    p_load->olen = outvec[i].len;
            }
        }
        p_load = TO_NEXT_PAYLOAD(p_load);
    }

    if (p_ctrl) {
        reply_control_msg(p_ctrl, reply);
    }

    p_header->sync = TRPC_SYNC_RELEASE;

    return IPC_SUCCESS;
}


int32_t tfm_rpc_service_process(void *buf, size_t size)
{
    uint32_t in_len, out_len;
    psa_invec invecs[PSA_MAX_IOVEC];
    psa_outvec outvecs[PSA_MAX_IOVEC];
    struct tfm_rpc_payload_t *p_load, *p_ctrload;
    struct tfm_rpc_msg_header_t *p_header = (struct tfm_rpc_msg_header_t *)buf;


    if (checking_msg_header(buf, size, TRPC_SYNC_READY) != IPC_SUCCESS)
        return IPC_ERROR_BAD_PARAMETERS;

    p_header->sync = TRPC_SYNC_LOCK;

    in_len = 0;
    out_len = 0;
    tfm_memset(invecs, 0, sizeof(invecs));
    tfm_memset(outvecs, 0, sizeof(outvecs));

    p_header->sync = TRPC_SYNC_LOCK;
    p_load = (struct tfm_rpc_payload_t *)p_header->payloads;
    p_ctrload = NULL;

    while ((uintptr_t)p_load + sizeof (*p_load) < (uintptr_t)&p_header->payloads[p_header->len]) {

        if (p_load->ilen == 0)
            break;

        if (p_load->type == TRPC_PAYLOAD_CTRL) {
            p_ctrload = p_load;
        } else if(p_load->type == TRPC_PAYLOAD_INPUT) {
            if (in_len < PSA_MAX_IOVEC - 1) {
                invecs[in_len].len = p_load->ilen;
                invecs[in_len].base = p_load->data;
                in_len++;
            }
        } else if(p_load->type == TRPC_PAYLOAD_OUTPUT) {
            if (out_len < PSA_MAX_IOVEC - 1) {
                outvecs[out_len].len = p_load->ilen;
                outvecs[out_len].base = p_load->data;
                out_len++;
            }
       } else {
           /* Invalid payload type, should assert */
           break;
        }

        p_load = TO_NEXT_PAYLOAD(p_load);
    }

    if (p_ctrload) {
        dispatch_control_msg(p_ctrload, invecs, in_len, outvecs, out_len);
        return IPC_SUCCESS;
    }

    return IPC_ERROR_BAD_PARAMETERS;
}

int32_t tfm_rpc_client_message(void *buf, size_t size)
{
    struct tfm_rpc_msg_header_t *header;

    if (buf == NULL || size < sizeof(struct tfm_rpc_msg_header_t))
        return IPC_ERROR_BAD_PARAMETERS;

    header = (struct tfm_rpc_msg_header_t *)buf;
    header->magic = TRPC_MAGIC;
    header->len = 0;
    header->sync = TRPC_SYNC_CREATING;

    return IPC_SUCCESS;
}

int32_t tfm_rpc_client_ready(void *buf, size_t size)
{
    struct tfm_rpc_msg_header_t *p_header;

    if (checking_msg_header(buf, size, TRPC_SYNC_CREATING) != IPC_SUCCESS)
        return IPC_ERROR_BAD_PARAMETERS;

    p_header = (struct tfm_rpc_msg_header_t *)buf;

    p_header->sync = TRPC_SYNC_READY;

    return IPC_SUCCESS;
}

void *tfm_rpc_client_recv(void *buf, size_t size, void *start)
{
    struct tfm_rpc_msg_header_t *p_header;
    struct tfm_rpc_payload_t *p_load;

    if (checking_msg_header(buf, size, TRPC_SYNC_RELEASE) != IPC_SUCCESS)
        return NULL;

    p_header = (struct tfm_rpc_msg_header_t *)buf;
    if (start == NULL ) {
        p_load = (struct tfm_rpc_payload_t *)p_header->payloads;
        while (((uintptr_t)p_load + sizeof (*p_load) < (uintptr_t)&p_header->payloads[p_header->len]) &&
            (void *)p_load > buf){
            if (p_load->type == TRPC_PAYLOAD_CTRL ||
                p_load->type == TRPC_PAYLOAD_INPUT ||
                p_load->type == TRPC_PAYLOAD_OUTPUT)
                    return p_load;
            p_load = TO_NEXT_PAYLOAD(p_load);
        }
        return NULL;
    }

    p_load = (struct tfm_rpc_payload_t *)start;
    p_load = TO_NEXT_PAYLOAD(p_load);

    if (p_load->type == TRPC_PAYLOAD_CTRL ||
        p_load->type == TRPC_PAYLOAD_INPUT ||
        p_load->type == TRPC_PAYLOAD_OUTPUT)
           return p_load;

    return NULL;
}



int32_t tfm_rpc_client_payload(void *buf, size_t size, uint32_t type, void *p_src, size_t src_sz)
{
    struct tfm_rpc_payload_t *p_dest;
    struct tfm_rpc_msg_header_t *p_header;
    uintptr_t msg_limit = (uintptr_t)buf + size;

    if (checking_msg_header(buf, size, TRPC_SYNC_CREATING) != IPC_SUCCESS)
        return IPC_ERROR_BAD_PARAMETERS;

    p_header = (struct tfm_rpc_msg_header_t *)buf;
    p_dest = (struct tfm_rpc_payload_t *)&p_header->payloads[p_header->len];
    if ((uintptr_t)p_dest + src_sz + sizeof(struct tfm_rpc_payload_t) > msg_limit)
        return IPC_ERROR_BAD_PARAMETERS;

    if ((type & TRPC_PAYLOAD_MASK) != TRPC_PAYLOAD_TYPE)
        return IPC_ERROR_BAD_PARAMETERS;

    p_dest->type = type;
    p_dest->ilen = src_sz;
    tfm_memcpy(p_dest->data, p_src, src_sz);

    p_header->len += TFM_RPC_ALIGN_32(src_sz) + sizeof(*p_dest);

    return IPC_SUCCESS;
}

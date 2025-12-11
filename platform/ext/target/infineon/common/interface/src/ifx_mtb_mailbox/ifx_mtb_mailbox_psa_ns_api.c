/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ifx_mtb_mailbox.h"
#include "psa/client.h"
#include "psa/error.h"

/*
 * IFX MTB Mailbox PSA client API implementations.
 */

uint32_t psa_framework_version(void)
{
    ifx_psa_client_params_t params = {0};
    uint32_t version = PSA_VERSION_NONE;
    int32_t ret;
    ifx_mtb_mailbox_reply_t reply = {.return_val = IFX_MTB_MAILBOX_GENERIC_ERROR};

    ret = ifx_mtb_mailbox_client_call(IFX_MTB_MAILBOX_PSA_FRAMEWORK_VERSION,
                                      &params,
                                      &reply);
    version = (uint32_t)reply.return_val;
    if (ret != IFX_MTB_MAILBOX_SUCCESS) {
        version = PSA_VERSION_NONE;
    }

    return version;
}

uint32_t psa_version(uint32_t sid)
{
    ifx_psa_client_params_t params;
    uint32_t version;
    int32_t ret;
    ifx_mtb_mailbox_reply_t reply = {.return_val = IFX_MTB_MAILBOX_GENERIC_ERROR};

    params.psa_params.psa_version_params.sid = sid;

    ret = ifx_mtb_mailbox_client_call(IFX_MTB_MAILBOX_PSA_VERSION, &params,
                                      &reply);
    version = (uint32_t)reply.return_val;
    if (ret != IFX_MTB_MAILBOX_SUCCESS) {
        version = PSA_VERSION_NONE;
    }

    return version;
}

psa_handle_t psa_connect(uint32_t sid, uint32_t version)
{
    ifx_psa_client_params_t params;
    psa_handle_t psa_handle;
    int32_t ret;
    ifx_mtb_mailbox_reply_t reply = {.return_val = IFX_MTB_MAILBOX_GENERIC_ERROR};

    params.psa_params.psa_connect_params.sid = sid;
    params.psa_params.psa_connect_params.version = version;

    ret = ifx_mtb_mailbox_client_call(IFX_MTB_MAILBOX_PSA_CONNECT, &params,
                                      &reply);
    psa_handle = (psa_handle_t)reply.return_val;
    if (ret != IFX_MTB_MAILBOX_SUCCESS) {
        psa_handle = PSA_NULL_HANDLE;
    }

    return psa_handle;
}

psa_status_t psa_call(psa_handle_t handle, int32_t type,
                      const psa_invec *in_vec, size_t in_len,
                      psa_outvec *out_vec, size_t out_len)
{
    ifx_psa_client_params_t params;
    int32_t ret;
    ifx_mtb_mailbox_reply_t reply = {.return_val = IFX_MTB_MAILBOX_GENERIC_ERROR, .out_vec_len = {0}};
    psa_status_t status;

    if ((in_len > IOVEC_LEN(params.psa_params.psa_call_params.in_vec)) ||
        (out_len > IOVEC_LEN(params.psa_params.psa_call_params.out_vec)) ||
        ((in_len + out_len) > PSA_MAX_IOVEC) ||
        ((in_vec == NULL) && (in_len > 0U)) ||
        ((out_vec == NULL) && (out_len > 0U))) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /* The in/out vectors are copied to ifx_psa_client_params_t before being
     * copied to the mailbox packet. This additional copy is necessary
     * because the mailbox packet is allocated later within the
     * ifx_mtb_mailbox_client_call function. Managing the allocation and
     * lifecycle of the mailbox packet within ifx_mtb_mailbox_client_call
     * simplifies the overall code structure. The trade-off of this extra
     * copy operation, involving only a few bytes, is considered acceptable
     * for the sake of code maintainability and clarity.
     */
    params.psa_params.psa_call_params.handle = handle;
    params.psa_params.psa_call_params.type = type;
    if (in_len > 0U) {
        memcpy(params.psa_params.psa_call_params.in_vec, in_vec, sizeof(in_vec[0]) * in_len);
    }
    params.psa_params.psa_call_params.in_len = in_len;
    if (out_len > 0U) {
        memcpy(params.psa_params.psa_call_params.out_vec, out_vec, sizeof(out_vec[0]) * out_len);
    }
    params.psa_params.psa_call_params.out_len = out_len;

    ret = ifx_mtb_mailbox_client_call(IFX_MTB_MAILBOX_PSA_CALL, &params,
                                      &reply);
    status = (psa_status_t)reply.return_val;
    if (ret != IFX_MTB_MAILBOX_SUCCESS) {
        status = PSA_ERROR_COMMUNICATION_FAILURE;
    }

    for (size_t i = 0; i < out_len; i++) {
        out_vec[i].len = reply.out_vec_len[i];
    }

    return status;
}

void psa_close(psa_handle_t handle)
{
    ifx_psa_client_params_t params;
    ifx_mtb_mailbox_reply_t reply = {.return_val = IFX_MTB_MAILBOX_GENERIC_ERROR};

    params.psa_params.psa_close_params.handle = handle;

    (void)ifx_mtb_mailbox_client_call(IFX_MTB_MAILBOX_PSA_CLOSE, &params,
                                      &reply);
}

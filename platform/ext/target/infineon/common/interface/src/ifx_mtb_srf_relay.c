/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <string.h>

#include "config_tfm.h"

#if IFX_MTB_MAILBOX && IFX_NS_INTERFACE_TZ
#include "cmsis.h"
#include "ifx_platform_private.h"
#include "mtb_srf_ipc.h"
#include "mtb_srf.h"
#include "tfm_hal_multi_core.h"
#include "tfm_mailbox.h"
#include "tfm_platform_api.h"

cy_rslt_t mtb_srf_ipc_process_request(mtb_srf_ipc_packet_t* request)
{
    if (request == NULL) {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    int32_t* return_val = &request->reply.return_val;
    struct mailbox_reply_t* reply = &request->reply;
    const struct psa_client_params_t* params = &request->params;

    psa_invec in_vec[PSA_MAX_IOVEC];
    psa_outvec out_vec[PSA_MAX_IOVEC];
    size_t in_len;
    size_t out_len;

    switch (request->call_type) {
    case MAILBOX_PSA_FRAMEWORK_VERSION:
        *return_val = psa_framework_version();
        break;

    case MAILBOX_PSA_VERSION:
        *return_val = psa_version(params->psa_params.psa_version_params.sid);
        break;

    case MAILBOX_PSA_CALL:
        in_len = params->psa_params.psa_call_params.in_len;
        out_len = params->psa_params.psa_call_params.out_len;

        memset(in_vec, 0, sizeof(in_vec));
        memset(out_vec, 0, sizeof(out_vec));

        for (size_t i = 0; i < in_len; i++) {
            /* NULL pointer is a special case that should not be remapped even
             * if it is a valid memory in off core NSPE. */
            if (params->psa_params.psa_call_params.in_vec[i].base == NULL) {
                in_vec[i].base = NULL;
            } else {
                in_vec[i].base = tfm_hal_remap_ns_cpu_address(
                                       params->psa_params.psa_call_params.in_vec[i].base);
            }
            in_vec[i].len = params->psa_params.psa_call_params.in_vec[i].len;
        }

        for (size_t i = 0; i < out_len; i++) {
            /* NULL pointer is a special case that should not be remapped even
             * if it is a valid memory in off core NSPE. */
            if (params->psa_params.psa_call_params.out_vec[i].base == NULL) {
                out_vec[i].base = NULL;
            } else {
                out_vec[i].base = tfm_hal_remap_ns_cpu_address(
                                       params->psa_params.psa_call_params.out_vec[i].base);
            }
            out_vec[i].len = params->psa_params.psa_call_params.out_vec[i].len;
        }

        *return_val = psa_call(params->psa_params.psa_call_params.handle,
                               params->psa_params.psa_call_params.type,
                               in_vec,
                               in_len,
                               out_vec,
                               out_len);

        for (size_t i = 0; i < out_len; i++) {
            reply->out_vec_len[i] = out_vec[i].len;
        }
        break;

    case MAILBOX_PSA_CONNECT:
        *return_val = psa_connect(params->psa_params.psa_connect_params.sid,
                                  params->psa_params.psa_connect_params.version);
        break;

    case MAILBOX_PSA_CLOSE:
        psa_close(params->psa_params.psa_close_params.handle);
        break;

    default:
        *return_val = MAILBOX_INVAL_PARAMS;
        return MTB_SRF_ERR_BAD_PARAM;
    }

    return CY_RSLT_SUCCESS;
}
#endif /* IFX_MTB_MAILBOX && IFX_NS_INTERFACE_TZ */

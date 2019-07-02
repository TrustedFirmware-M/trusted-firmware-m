/*
 * Copyright (c) 2017-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include <string.h>

#include "secure_utilities.h"
#include "tfm_svc.h"
#include "tfm_secure_api.h"
#include "region_defs.h"
#include "tfm_api.h"
#include "tfm_internal.h"
#include "tfm_memory_utils.h"
#include "tfm_arch.h"
#ifdef TFM_PSA_API
#include <stdbool.h>
#include "tfm_svcalls.h"
#endif

/* This SVC handler is called when a secure partition requests access to a
 * buffer area
 */
extern int32_t tfm_core_set_buffer_area_handler(const uint32_t args[]);
#ifdef TFM_PSA_API
extern void tfm_psa_ipc_request_handler(const uint32_t svc_args[]);
#endif

uint32_t SVCHandler_main(uint32_t *svc_args, uint32_t lr)
{
    uint8_t svc_number;
    /*
     * Stack contains:
     * r0, r1, r2, r3, r12, r14 (lr), the return address and xPSR
     * First argument (r0) is svc_args[0]
     */
    if (is_return_secure_stack(lr)) {
        /* SV called directly from secure context. Check instruction for
         * svc_number
         */
        svc_number = ((uint8_t *)svc_args[6])[-2];
    } else {
        /* Secure SV executing with NS return.
         * NS cannot directly trigger S SVC so this should not happen
         * FixMe: check for security implications
         */
        return lr;
    }
    switch (svc_number) {
#ifdef TFM_PSA_API
    case TFM_SVC_IPC_REQUEST:
        tfm_psa_ipc_request_handler(svc_args);
        break;
    case TFM_SVC_SCHEDULE:
    case TFM_SVC_EXIT_THRD:
    case TFM_SVC_PSA_FRAMEWORK_VERSION:
    case TFM_SVC_PSA_VERSION:
    case TFM_SVC_PSA_CONNECT:
    case TFM_SVC_PSA_CALL:
    case TFM_SVC_PSA_CLOSE:
    case TFM_SVC_PSA_WAIT:
    case TFM_SVC_PSA_GET:
    case TFM_SVC_PSA_SET_RHANDLE:
    case TFM_SVC_PSA_READ:
    case TFM_SVC_PSA_SKIP:
    case TFM_SVC_PSA_WRITE:
    case TFM_SVC_PSA_REPLY:
    case TFM_SVC_PSA_NOTIFY:
    case TFM_SVC_PSA_CLEAR:
    case TFM_SVC_PSA_EOI:
        svc_args[0] = SVC_Handler_IPC(svc_number, svc_args, lr);
        break;
#else
    case TFM_SVC_SFN_REQUEST:
        lr = tfm_core_partition_request_svc_handler(svc_args, lr);
        break;
    case TFM_SVC_SFN_RETURN:
        lr = tfm_core_partition_return_handler(lr);
        break;
    case TFM_SVC_VALIDATE_SECURE_CALLER:
        tfm_core_validate_secure_caller_handler(svc_args);
        break;
    case TFM_SVC_GET_CALLER_CLIENT_ID:
        tfm_core_get_caller_client_id_handler(svc_args);
        break;
    case TFM_SVC_SPM_REQUEST:
        tfm_core_spm_request_handler((struct tfm_exc_stack_t *)svc_args);
        break;
    case TFM_SVC_MEMORY_CHECK:
        tfm_core_memory_permission_check_handler(svc_args);
        break;
    case TFM_SVC_SET_SHARE_AREA:
        tfm_core_set_buffer_area_handler(svc_args);
        break;
#endif
    case TFM_SVC_PRINT:
        printf("\033[1;34m[Sec Thread] %s\033[0m\r\n", (char *)svc_args[0]);
        break;
    case TFM_SVC_GET_BOOT_DATA:
        tfm_core_get_boot_data_handler(svc_args);
        break;
    default:
        LOG_MSG("Unknown SVC number requested!");
        break;
    }

    return lr;
}

void tfm_access_violation_handler(void)
{
    while (1) {
        ;
    }
}

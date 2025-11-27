/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "config_tfm.h"
#include "ifx_platform_api.h"
#include "ifx_platform_private.h"
#include "ifx_utils.h"

uint32_t ifx_platform_log_msg(const char *msg, uint32_t msg_size)
{
    IFX_ASSERT(IFX_STDIO_CORE_ID < IFX_STDIO_CORE_COUNT);
    const uint32_t max_chunk_len = (uint32_t)PLATFORM_SERVICE_INPUT_BUFFER_SIZE;

    uint32_t out_count = 0U;
    while (msg_size != 0U) {
        uint32_t chunk_len = (msg_size < max_chunk_len) ?
                             msg_size : max_chunk_len;
        psa_invec in_vec = { .base = msg, .len = chunk_len };
        /* Use IOCTL request id to encode core id */
        enum tfm_platform_err_t status =
                tfm_platform_ioctl(IFX_PLATFORM_IOCTL_LOG_MSG_MIN + IFX_STDIO_CORE_ID,
                                   &in_vec, NULL);
        if (status != TFM_PLATFORM_ERR_SUCCESS) {
            return out_count;
        }

        msg += chunk_len;
        msg_size -= chunk_len;
        out_count += chunk_len;
    }

    return out_count;
}

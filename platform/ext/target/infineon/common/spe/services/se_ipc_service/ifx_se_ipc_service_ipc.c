/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_se_ipc_service_syscall.h"

#include "cy_syslib.h"

ifx_se_status_t ifx_se_ipc_service_spm_syscall(ifx_se_fih_ptr_t ipc_packet,
                                               ifx_se_fih_t ipc_packet_size,
                                               void *ctx)
{
    (void)ipc_packet_size; /* unused parameter */
    /* Call ifx_se_syscall_builtin */
    return ifx_se_syscall_builtin(ipc_packet, ctx);
}

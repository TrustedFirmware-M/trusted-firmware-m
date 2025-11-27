/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_se_fih.h"
#include "ifx_se_syscall.h"

/*******************************************************************************
* Function Name: ifx_se_syscall
********************************************************************************
*
* Used to call syscall to Secure Enclave. This implementation makes the syscall
* directly.
*
* \param[in] ipc_packet: The pointer to the buffer with syscall parameters.
*
* \param[in] ipc_packet_size: The size of the buffer with syscall parameters.
*
* \param[in] *ctx: The pointer to the SE syscall context that contain a special
* syscall data (IPC release callback etc).
*
* \return \ref IFX_SE_SUCCESS for success or error code
*
*******************************************************************************/
ifx_se_status_t ifx_se_syscall(ifx_se_fih_ptr_t ipc_packet,
                               ifx_se_fih_t ipc_packet_size,
                               void *ctx)
{
    (void)ipc_packet_size; /* unused parameter */
    /* Call ifx_se_syscall_builtin */
    return ifx_se_syscall_builtin(ipc_packet, ctx);
}

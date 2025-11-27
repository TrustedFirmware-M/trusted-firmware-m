/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_SE_IPC_SERVICE_SYSCALL_H
#define IFX_SE_IPC_SERVICE_SYSCALL_H

#include "ifx_se_syscall.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Handle SPM's syscall to SE IPC Service
 *
 * \return Returns values as specified by the \ref ifx_se_status_t
 */
ifx_se_status_t ifx_se_ipc_service_spm_syscall(ifx_se_fih_ptr_t ipc_packet,
                                               ifx_se_fih_t ipc_packet_size,
                                               void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* IFX_SE_IPC_SERVICE_SYSCALL_H */

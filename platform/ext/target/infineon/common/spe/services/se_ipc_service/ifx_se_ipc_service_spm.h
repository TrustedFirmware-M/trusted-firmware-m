/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_SE_IPC_SERVICE_SPM_H
#define IFX_SE_IPC_SERVICE_SPM_H

#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Lets SPM to use SE IPC channel.
 *
 * \note SE IPC Service interface (calls to se-rt-services-utils) should be used
 * during initialization phase only before calling \ref ifx_se_ipc_service_spm_shutdown.
 * It's not possible to use SE IPC interface within SPM and secure/non-secure partition
 * at the same time. So it's important to shutdown this interface by calling
 * \ref ifx_se_ipc_service_spm_shutdown before \ref BACKEND_SPM_INIT.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t ifx_se_ipc_service_spm_init(void);

/**
 * \brief Shutdown SE IPC Service.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t ifx_se_ipc_service_spm_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* IFX_SE_IPC_SERVICE_SPM_H */

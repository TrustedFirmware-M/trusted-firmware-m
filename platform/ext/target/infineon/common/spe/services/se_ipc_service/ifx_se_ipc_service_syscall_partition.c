/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_se_syscall.h"
#include "psa/client.h"
#include "psa_manifest/sid.h"
#include "coverity_check.h"
#include "ifx_se_ipc_service_syscall.h"
#include "protection_shared_data.h"

/* ifx_se_syscall works within SPM and service. It means that we can't link ifx_se_syscall
 * with SPM. So, \ref tfm_core_panic is declared here instead of include utilities.h */
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_5, "Can't link ifx_se_syscall.")
void tfm_core_panic(void);

/*******************************************************************************
* Function Name: ifx_se_syscall
********************************************************************************
*
* Used to call syscall to Secure Enclave. This implementation uses IFX SE IPC
* Service to access SE IPC interface.
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
    if (IFX_IS_SPM_INITILIZING()) {
        /* IFX SE IPC Service is handling SPM request */
        return ifx_se_ipc_service_spm_syscall(ipc_packet, ipc_packet_size, ctx);
    } else if (IFX_IS_SPM_RUNNING()) {
        /* ctx is unused for TF-M */
        (void)ctx;

        /* Call IFX SE IPC Service to handle client request */
        psa_status_t status;
        ifx_se_status_t se_status = IFX_SE_SYSCALL_GENERAL_ERROR;
        psa_invec in_vec[1];
        psa_outvec out_vec[1];
        size_t packet_size_bytes = ifx_se_fih_uint_decode(ipc_packet_size);

        TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_6, "Current implementation requires this cast")
        const void *packet_ptr = (void *)ifx_se_fih_ptr_decode(ipc_packet);

        in_vec[0].base = packet_ptr;
        in_vec[0].len = packet_size_bytes;

        out_vec[0].base = (void *)&se_status;
        out_vec[0].len = sizeof(se_status);

        status = psa_call(IFX_SE_IPC_SERVICE_HANDLE, 0,
                          in_vec, IOVEC_LEN(in_vec), out_vec, IOVEC_LEN(out_vec));
        if (status == PSA_SUCCESS) {
            /* use se_status returned by psa_call */
            return se_status;
        }
        else if (status == PSA_ERROR_INVALID_ARGUMENT) {
            return IFX_SE_SYSCALL_INVALID_ARGUMENT;
        }
        else {
            return IFX_SE_SYSCALL_GENERAL_ERROR;
        }
    } else {
        tfm_core_panic();
    }

    /* Should not get here */
    return IFX_SE_SYSCALL_GENERAL_ERROR;
}

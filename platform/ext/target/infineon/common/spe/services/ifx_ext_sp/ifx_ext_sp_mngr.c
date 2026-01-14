/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa/service.h"

#include "ifx_ext_sp_defs.h"

#ifdef IFX_MTB_SRF
#include "cybsp.h"
#include "ffm/original_vector_api.h"
#include "mtb_srf.h"
#endif /* IFX_MTB_SRF */

#include <stdio.h>

psa_status_t ifx_ext_sp_init(void)
{
    /* Initialize the IFX_EXT_SP */
    return PSA_SUCCESS;
}

#ifdef IFX_MTB_SRF
/* Overwrites default implementation of mtb_srf_memory_validate */
cy_rslt_t mtb_srf_memory_validate(volatile mtb_srf_invec_ns_t* inVec_ns,
                                  uint8_t inVec_cnt_ns,
                                  volatile mtb_srf_outvec_ns_t* outVec_ns,
                                  uint8_t outVec_cnt_ns,
                                  mtb_srf_invec_ns_t* inVec,
                                  mtb_srf_outvec_ns_t* outVec)
{
    /* In TFM case access rights validation is done during psa_call */

    /* Copy in/out vectors to SRF provided buffers */
    for (uint32_t i = 0UL; i < inVec_cnt_ns; ++i) {
        inVec[i].base = inVec_ns[i].base;
        inVec[i].len = inVec_ns[i].len;
    }

    for (uint32_t i = 0UL; i < outVec_cnt_ns; ++i) {
        outVec[i].base = outVec_ns[i].base;
        outVec[i].len = outVec_ns[i].len;
    }

    return CY_RSLT_SUCCESS;
}
#endif /* IFX_MTB_SRF */

psa_status_t ifx_mtb_srf_handler(const psa_msg_t *msg)
{
#ifdef IFX_MTB_SRF
    psa_status_t psa_ret = PSA_ERROR_GENERIC_ERROR;
    tfm_original_iovec_t io_vec;
    memset(&io_vec, 0, sizeof(io_vec));

    psa_ret = original_iovec(msg->handle, &io_vec);
    if (psa_ret != PSA_SUCCESS) {
        return psa_ret;
    }

    return mtb_srf_request_execute(&cybsp_srf_context,
                                   io_vec.invec, io_vec.invec_count,
                                   io_vec.outvec, io_vec.outvec_count);
#else /* IFX_MTB_SRF */
    return PSA_ERROR_NOT_SUPPORTED;
#endif /* IFX_MTB_SRF */
}

psa_status_t ifx_ext_sp_service_sfn(const psa_msg_t *msg)
{
    /* Handle messages sent to the IFX_EXT_SP */
    switch (msg->type) {
        case IFX_EXT_SP_API_ID_MTB_SRF:
            return ifx_mtb_srf_handler(msg);
        default:
            return PSA_ERROR_NOT_SUPPORTED;
    }
}

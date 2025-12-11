/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa_manifest/sid.h"
#include "psa/client.h"

#include "ifx_ext_sp_api.h"
#include "ifx_ext_sp_defs.h"

#ifdef IFX_MTB_SRF
psa_status_t ifx_mtb_srf_call(mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                              mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    return psa_call(IFX_EXT_SP_SERVICE_HANDLE, IFX_EXT_SP_API_ID_MTB_SRF,
                    inVec_ns, inVec_cnt_ns,
                    outVec_ns, outVec_cnt_ns);
}
#endif /* IFX_MTB_SRF */

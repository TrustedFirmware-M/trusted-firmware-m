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

#include "cmsis.h"
#include "ifx_ext_sp_api.h"
#include "mtb_srf.h"
#include "psa_manifest/sid.h"

cy_rslt_t mtb_srf_request_submit(mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                 mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    return ifx_mtb_srf_call(inVec_ns, inVec_cnt_ns, outVec_ns, outVec_cnt_ns);
}

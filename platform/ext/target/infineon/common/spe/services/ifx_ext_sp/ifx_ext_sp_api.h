/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_EXT_SP_API_H
#define IFX_EXT_SP_API_H

#include <stddef.h>
#include <stdint.h>

#include "psa/error.h"

#ifdef IFX_MTB_SRF
#include "mtb_srf.h"
#endif /* IFX_MTB_SRF */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef IFX_MTB_SRF
/**
 * \brief Call the MTB SRF service
 *
 * Invokes the IFX Extensions partition to perform MTB SRF operation.
 *
 * \param[in]  inVec_ns        Pointer to the input vector array
 * \param[in]  inVec_cnt_ns    Number of input vectors in `inVec_ns`
 * \param[out] outVec_ns       Pointer to the output vector array
 * \param[in]  outVec_cnt_ns   Number of output vectors expected in `outVec_ns`
 *
 * \return A PSA status indicating the success or failure of the operation
 */
psa_status_t ifx_mtb_srf_call(mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                              mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns);
#endif /* IFX_MTB_SRF */

#ifdef __cplusplus
}
#endif

#endif /* IFX_EXT_SP_API_H */

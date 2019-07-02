/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SST_REQ_MNGR_H__
#define __TFM_SST_REQ_MNGR_H__

#include <stddef.h>

#include "psa_client.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Handles the set request.
 *
 * \param[in]  in_vec  Pointer to the input vector which contains the input
 *                     parameters.
 * \param[in]  in_len  Number of input parameters in the input vector.
 * \param[out] out_vec Pointer to the ouput vector which contains the output
 *                     parameters.
 * \param[in]  out_len Number of output parameters in the output vector.
 *
 * \return A status indicating the success/failure of the operation as specified
 *         in \ref psa_status_t
 */
psa_status_t tfm_sst_set_req(psa_invec *in_vec, size_t in_len,
                             psa_outvec *out_vec, size_t out_len);

/**
 * \brief Handles the get request.
 *
 * \param[in]  in_vec  Pointer to the input vector which contains the input
 *                     parameters.
 * \param[in]  in_len  Number of input parameters in the input vector.
 * \param[out] out_vec Pointer to the ouput vector which contains the output
 *                     parameters.
 * \param[in]  out_len Number of output parameters in the output vector.
 *
 * \return A status indicating the success/failure of the operation as specified
 *         in \ref psa_status_t
 */
psa_status_t tfm_sst_get_req(psa_invec *in_vec, size_t in_len,
                             psa_outvec *out_vec, size_t out_len);

/**
 * \brief Handles the get info request.
 *
 * \param[in]  in_vec  Pointer to the input vector which contains the input
 *                     parameters.
 * \param[in]  in_len  Number of input parameters in the input vector.
 * \param[out] out_vec Pointer to the ouput vector which contains the output
 *                     parameters.
 * \param[in]  out_len Number of output parameters in the output vector.
 *
 * \return A status indicating the success/failure of the operation as specified
 *         in \ref psa_status_t
 */
psa_status_t tfm_sst_get_info_req(psa_invec *in_vec, size_t in_len,
                                  psa_outvec *out_vec, size_t out_len);

/**
 * \brief Handles the remove request.
 *
 * \param[in]  in_vec  Pointer to the input vector which contains the input
 *                     parameters.
 * \param[in]  in_len  Number of input parameters in the input vector.
 * \param[out] out_vec Pointer to the ouput vector which contains the output
 *                     parameters.
 * \param[in]  out_len Number of output parameters in the output vector.
 *
 * \return A status indicating the success/failure of the operation as specified
 *         in \ref psa_status_t
 */
psa_status_t tfm_sst_remove_req(psa_invec *in_vec, size_t in_len,
                                psa_outvec *out_vec, size_t out_len);

/**
 * \brief Handles the get support request.
 *
 * \param[in]  in_vec  Pointer to the input vector which contains the input
 *                     parameters.
 * \param[in]  in_len  Number of input parameters in the input vector.
 * \param[out] out_vec Pointer to the ouput vector which contains the output
 *                     parameters.
 * \param[in]  out_len Number of output parameters in the output vector.
 *
 * \return A status indicating the success/failure of the operation as specified
 *         in \ref psa_status_t
 *
 */
psa_status_t tfm_sst_get_support_req(psa_invec *in_vec, size_t in_len,
                                     psa_outvec *out_vec, size_t out_len);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_SST_REQ_MNGR_H__ */

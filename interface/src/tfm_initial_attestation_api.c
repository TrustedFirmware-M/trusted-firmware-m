/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa_initial_attestation_api.h"
#include "tfm_veneers.h"
#include "tfm_ns_lock.h"
#include "psa_client.h"
#ifdef TFM_PSA_API
#include "tfm_attest_defs.h"
#endif

#define IOVEC_LEN(x) (sizeof(x)/sizeof(x[0]))

enum psa_attest_err_t
psa_initial_attest_get_token(const uint8_t *challenge_obj,
                             uint32_t       challenge_size,
                             uint8_t       *token,
                             uint32_t      *token_size)
{
#ifdef TFM_PSA_API
    psa_handle_t handle = PSA_NULL_HANDLE;
    psa_status_t status;
#else
    uint32_t res;
#endif
    psa_invec in_vec[] = {
        {challenge_obj, challenge_size}
    };
    psa_outvec out_vec[] = {
        {token, *token_size}
    };

#ifdef TFM_PSA_API
    handle = psa_connect(TFM_ATTEST_GET_TOKEN_SID,
                         TFM_ATTEST_GET_TOKEN_MINOR_VER);
    if (handle <= 0) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    status = psa_call(handle,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));
    psa_close(handle);

    if (status < PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    if (status == PSA_SUCCESS) {
        *token_size = out_vec[0].len;
    }

    return (enum psa_attest_err_t)status;
#else
    res = tfm_ns_lock_dispatch((veneer_fn)tfm_initial_attest_get_token_veneer,
                               (uint32_t)in_vec,  IOVEC_LEN(in_vec),
                               (uint32_t)out_vec, IOVEC_LEN(out_vec));

    if (res == PSA_ATTEST_ERR_SUCCESS) {
        *token_size = out_vec[0].len;
    }

    return (enum psa_attest_err_t)res;
#endif
}

enum psa_attest_err_t
psa_initial_attest_get_token_size(uint32_t  challenge_size,
                                  uint32_t *token_size)
{
#ifdef TFM_PSA_API
    psa_handle_t handle = PSA_NULL_HANDLE;
    psa_status_t status;
#endif
    psa_invec in_vec[] = {
        {&challenge_size, sizeof(challenge_size)}
    };
    psa_outvec out_vec[] = {
        {token_size, sizeof(uint32_t)}
    };

#ifdef TFM_PSA_API
    handle = psa_connect(TFM_ATTEST_GET_TOKEN_SIZE_SID,
                         TFM_ATTEST_GET_TOKEN_SIZE_MINOR_VER);
    if (handle <= 0) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    status = psa_call(handle,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));
    psa_close(handle);

    if (status < PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    return (enum psa_attest_err_t)status;
#else
    return (enum psa_attest_err_t)tfm_ns_lock_dispatch(
                            (veneer_fn)tfm_initial_attest_get_token_size_veneer,
                            (uint32_t)in_vec,  IOVEC_LEN(in_vec),
                            (uint32_t)out_vec, IOVEC_LEN(out_vec));
#endif
}

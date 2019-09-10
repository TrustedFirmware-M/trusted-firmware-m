/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa/initial_attestation.h"
#include "tfm_veneers.h"
#include "tfm_memory_utils.h"
#include "tfm_client.h"
#include "tfm_secure_api.h"
#ifdef TFM_PSA_API
#include "psa_manifest/sid.h"
#endif
#include <string.h>

#ifndef TFM_PSA_API
/* FIXME: If iovec will be supported by SPM then remove the usage of
 * scratch area.
 */
extern uint8_t *tfm_scratch_area;
#else
#define IOVEC_LEN(x) (sizeof(x)/sizeof(x[0]))
#endif

__attribute__((section("SFN")))
enum psa_attest_err_t
psa_initial_attest_get_token(const uint8_t *challenge_obj,
                             uint32_t       challenge_size,
                             uint8_t       *token,
                             uint32_t      *token_size)
{
    psa_status_t status;
#ifdef TFM_PSA_API
    psa_handle_t handle = PSA_NULL_HANDLE;
    psa_invec in_vec[] = {
        {challenge_obj, challenge_size}
    };
    psa_outvec out_vec[] = {
        {token, *token_size}
    };
#else
    psa_invec *in_vec;
    psa_outvec *out_vec;
    uint8_t *challenge_buff;
    uint8_t *token_buff;
#endif

#ifdef TFM_PSA_API
    handle = psa_connect(TFM_ATTEST_GET_TOKEN_SID,
                         TFM_ATTEST_GET_TOKEN_VERSION);
    if (handle <= 0) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    status = psa_call(handle, PSA_IPC_CALL,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));
    psa_close(handle);

    if (status < PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    if (status == PSA_SUCCESS) {
        *token_size = out_vec[0].len;
    }
#else
    if (tfm_core_set_buffer_area(TFM_BUFFER_SHARE_SCRATCH) !=
                                                         (int32_t)TFM_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    /*
     * Scratch area layout
     * -------------------------------------------------------
     * |in_vec[0] | out_vec[0] | challenge_buff | token_buff |
     * -------------------------------------------------------
     */

    in_vec  = (psa_invec  *)(tfm_scratch_area);
    out_vec = (psa_outvec *)(in_vec + 1);

    challenge_buff = (uint8_t *)(out_vec + 1);
    token_buff     = (uint8_t *)(challenge_buff + challenge_size);

    /* Copy challenge object to scratch area */
    (void)tfm_memcpy(challenge_buff, challenge_obj, challenge_size);

    in_vec[0].base = challenge_buff;
    in_vec[0].len  = challenge_size;

    out_vec[0].base = token_buff;
    out_vec[0].len  = *token_size;

    status = tfm_initial_attest_get_token_veneer(in_vec, 1, out_vec, 1);
    if (status == (psa_status_t)PSA_ATTEST_ERR_SUCCESS) {
        (void)tfm_memcpy(token, out_vec[0].base, out_vec[0].len);
        *token_size = out_vec[0].len;
    }
#endif

    return (enum psa_attest_err_t)status;
}

__attribute__((section("SFN")))
enum psa_attest_err_t
psa_initial_attest_get_token_size(uint32_t challenge_size,
                                  uint32_t *token_size)
{
    psa_status_t status;
#ifdef TFM_PSA_API
    psa_handle_t handle = PSA_NULL_HANDLE;
    psa_invec in_vec[] = {
        {&challenge_size, sizeof(challenge_size) }
    };
    psa_outvec out_vec[] = {
        {token_size, sizeof(uint32_t)}
    };
#else
    struct paramters_t {
        psa_invec in_vec;
        uint32_t challenge_size;
        psa_outvec out_vec;
        uint32_t token_size;
    };
#endif

#ifdef TFM_PSA_API
    handle = psa_connect(TFM_ATTEST_GET_TOKEN_SIZE_SID,
                         TFM_ATTEST_GET_TOKEN_SIZE_VERSION);
    if (handle <= 0) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    status = psa_call(handle, PSA_IPC_CALL,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));
    psa_close(handle);

    if (status < PSA_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }
#else
    if (tfm_core_set_buffer_area(TFM_BUFFER_SHARE_SCRATCH) !=
                                                         (int32_t)TFM_SUCCESS) {
        return PSA_ATTEST_ERR_GENERAL;
    }

    struct paramters_t *param = (struct paramters_t *)tfm_scratch_area;
    /*
     * Scratch area layout
     * ------------------------------------------------------
     * |in_vec[0] | challenge_size | out_vec[0] | token_size|
     * ------------------------------------------------------
     */
    param->challenge_size = challenge_size;
    param->in_vec.base  = &param->challenge_size;
    param->in_vec.len   = sizeof(uint32_t);
    param->out_vec.base = &param->token_size;
    param->out_vec.len  = sizeof(uint32_t);

    status = tfm_initial_attest_get_token_size_veneer(&param->in_vec,  1,
                                                      &param->out_vec, 1);
    if (status == (psa_status_t)PSA_ATTEST_ERR_SUCCESS) {
        *token_size = param->token_size;
    }
#endif

    return (enum psa_attest_err_t)status;
}

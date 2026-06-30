/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa/initial_attestation.h"
#include "psa/client.h"
#include "psa_manifest/sid.h"
#include "tfm_attest_defs.h"

psa_status_t
psa_initial_attest_get_token(const uint8_t *auth_challenge,
                             size_t         challenge_size,
                             uint8_t       *token_buf,
                             size_t         token_buf_size,
                             size_t        *token_size)
{
    psa_status_t status;

    psa_invec in_vec[] = {
        {auth_challenge, challenge_size}
    };
    psa_outvec out_vec[] = {
        {token_buf, token_buf_size}
    };

    status = psa_call(TFM_ATTESTATION_SERVICE_HANDLE, TFM_ATTEST_GET_TOKEN,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));

    if (status == PSA_SUCCESS) {
        *token_size = out_vec[0].len;
    }

    return status;
}

psa_status_t
psa_initial_attest_get_token_size(size_t  challenge_size,
                                  size_t *token_size)
{
    psa_status_t status;
    rot_size_t challenge_size_param;
    rot_size_t token_size_param = 0;

    psa_invec in_vec[] = {
        {&challenge_size_param, sizeof(challenge_size_param)}
    };
    psa_outvec out_vec[] = {
        {&token_size_param, sizeof(token_size_param)}
    };

#if SIZE_MAX > ROT_SIZE_MAX
    if (challenge_size > ROT_SIZE_MAX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
#endif
    challenge_size_param = (rot_size_t)challenge_size;

    if (token_size == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = psa_call(TFM_ATTESTATION_SERVICE_HANDLE, TFM_ATTEST_GET_TOKEN_SIZE,
                      in_vec, IOVEC_LEN(in_vec),
                      out_vec, IOVEC_LEN(out_vec));

    *token_size = token_size_param;

    return status;
}

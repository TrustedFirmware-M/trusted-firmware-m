/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "attest.h"
#include "config_tfm.h"
#include "ifx_se_fih.h"
#include "ifx_se_platform.h"
#include "ifx_se_tfm_utils.h"
#include "psa/initial_attestation.h"
#include "tfm_attest_hal.h"
#include "tfm_plat_device_id.h"

#include <string.h>

static inline psa_status_t error_mapping_to_psa_status_t(enum psa_attest_err_t attest_err)
{
    switch (attest_err) {
    case PSA_ATTEST_ERR_SUCCESS:
        return PSA_SUCCESS;
        break;
    case PSA_ATTEST_ERR_INIT_FAILED:
        return PSA_ERROR_SERVICE_FAILURE;
        break;
    case PSA_ATTEST_ERR_BUFFER_OVERFLOW:
        return PSA_ERROR_BUFFER_TOO_SMALL;
        break;
    case PSA_ATTEST_ERR_CLAIM_UNAVAILABLE:
        return PSA_ERROR_GENERIC_ERROR;
        break;
    case PSA_ATTEST_ERR_INVALID_INPUT:
        return PSA_ERROR_INVALID_ARGUMENT;
        break;
    case PSA_ATTEST_ERR_GENERAL:
        return PSA_ERROR_GENERIC_ERROR;
        break;
    default:
        return PSA_ERROR_GENERIC_ERROR;
    }
}

static inline psa_status_t ifx_se_get_psa_status(ifx_se_status_t status)
{
    if( IFX_SE_IS_STATUS_SUCCESS(status) ) {
        return PSA_SUCCESS;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_NOT_SUPPORTED)) {
        return PSA_ERROR_NOT_SUPPORTED;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_GENERAL_ERROR )) {
        return PSA_ERROR_GENERIC_ERROR;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_INVALID_OPCODE )) {
        return PSA_ERROR_INVALID_ARGUMENT;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_INVALID_ARGUMENT )) {
        return PSA_ERROR_INVALID_ARGUMENT;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_TIMEOUT_ERROR )) {
        return PSA_ERROR_COMMUNICATION_FAILURE;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_CORRUPTION_DETECTED )) {
        return PSA_ERROR_CORRUPTION_DETECTED;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_INVALID_MEM_ALLOC )) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_STORAGE_FAILURE ) ||
               IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_STORAGE_TIMEOUT )) {
        return PSA_ERROR_STORAGE_FAILURE;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_BUFFER_TOO_SMALL )) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    } else if( IFX_SE_STATUS_CHECK(status, IFX_SE_SYSCALL_INSUFFICIENT_STORAGE )) {
        return PSA_ERROR_INSUFFICIENT_STORAGE;
    } else {
        return ifx_se_fih_uint_decode(status);
    }
}

psa_status_t
tfm_attest_hal_get_token(const void *challenge_buf, size_t challenge_size,
                         void *token_buf, size_t token_buf_size,
                         size_t *token_size)
{
    psa_status_t status = PSA_ERROR_INVALID_ARGUMENT;
    enum psa_attest_err_t res_attest;
    enum tfm_plat_err_t res_plat;

    int32_t caller_id;
    uint8_t certification_ref[CERTIFICATION_REF_MAX_SIZE];
    uint32_t certification_size = sizeof(certification_ref);

    uint8_t verification_url[VERIFICATION_URL_MAX_SIZE];
    uint32_t verification_size = sizeof(verification_url);

    res_attest = attest_get_caller_client_id(&caller_id);
    if (res_attest != PSA_ATTEST_ERR_SUCCESS) {
        return error_mapping_to_psa_status_t(res_attest);
    }

    res_plat = tfm_attest_hal_get_verification_service(&verification_size, verification_url);
    if (res_plat != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    res_plat = tfm_plat_get_cert_ref(&certification_size, certification_ref);
    if (res_plat != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    status = ifx_se_get_psa_status( ifx_se_initial_attest_get_token(
                    ifx_se_fih_ptr_encode(challenge_buf),
                    ifx_se_fih_uint_encode(challenge_size),
                    ifx_se_fih_uint_encode(caller_id),
                    ifx_se_fih_ptr_encode(verification_url),
                    ifx_se_fih_uint_encode(verification_size),
                    ifx_se_fih_ptr_encode(certification_ref),
                    ifx_se_fih_uint_encode(certification_size),
                    ifx_se_fih_ptr_encode(token_buf),
                    ifx_se_fih_uint_encode(token_buf_size),
                    ifx_se_fih_ptr_encode(token_size),
                    IFX_SE_TFM_SYSCALL_CONTEXT) );

    return status;
}

psa_status_t
tfm_attest_hal_get_token_size(size_t challenge_size, size_t *token_size)
{
    psa_status_t status = PSA_ERROR_INVALID_ARGUMENT;

    status = ifx_se_get_psa_status( ifx_se_initial_attest_get_token_size(
                    ifx_se_fih_uint_encode(challenge_size),
                    ifx_se_fih_ptr_encode(token_size),
                    IFX_SE_TFM_SYSCALL_CONTEXT) );

    return status;
}

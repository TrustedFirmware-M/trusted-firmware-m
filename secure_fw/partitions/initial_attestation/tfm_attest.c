/*
 * Copyright (c) 2019-2022, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "service_api.h"
#include "attest.h"
#include "psa/error.h"
#include "psa/initial_attestation.h"
#include "tfm_boot_status.h"

extern int32_t g_attest_caller_id;

enum psa_attest_err_t
attest_get_caller_client_id(int32_t *caller_id)
{
    enum psa_attest_err_t attest_res = PSA_ATTEST_ERR_SUCCESS;
    *caller_id = g_attest_caller_id;

    return attest_res;
}

enum psa_attest_err_t
attest_get_boot_data(uint8_t major_type,
                     struct tfm_boot_data *boot_data,
                     uint32_t len)
{
    enum psa_attest_err_t attest_res = PSA_ATTEST_ERR_SUCCESS;
    int32_t tfm_res;

    tfm_res = tfm_core_get_boot_data(major_type, boot_data, len);
    if (tfm_res != (int32_t)PSA_SUCCESS) {
        attest_res =  PSA_ATTEST_ERR_INIT_FAILED;
    }

    return attest_res;
}

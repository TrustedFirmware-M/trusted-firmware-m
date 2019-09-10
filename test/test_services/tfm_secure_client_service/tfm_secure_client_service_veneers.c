/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_secure_client_service_veneers.h"

#include "tfm_secure_client_service.h"
#include "tfm_secure_api.h"
#include "secure_fw/spm/spm_partition_defs.h"

__tfm_secure_gateway_attributes__
int32_t tfm_secure_client_service_veneer_run_tests(void)
{
    TFM_CORE_SFN_REQUEST(TFM_SP_SECURE_TEST_PARTITION_ID,
                         tfm_secure_client_service_sfn_run_tests,
                         0, 0, 0, 0);
}

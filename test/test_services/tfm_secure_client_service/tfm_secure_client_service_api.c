/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_secure_client_service_api.h"
#ifdef TFM_PSA_API
#include "psa_client.h"
#include "tfm_api.h"

/*
 * Defines for SID and minor version number. These SIDs should align with the
 * value in service manifest file.
 */
#define TFM_SECURE_CLIENT_SFN_RUN_TESTS_SID     (0x0000F000)
#define TFM_SECURE_CLIENT_SFN_RUN_TESTS_MIN_VER (0x00000001)
#else /* TFM_PSA_API */
#include "tfm_secure_client_service_veneers.h"
#endif /* TFM_PSA_API */

int32_t tfm_secure_client_run_tests(void)
{
#ifdef TFM_PSA_API
    psa_handle_t handle;
    psa_status_t status;

    handle = psa_connect(TFM_SECURE_CLIENT_SFN_RUN_TESTS_SID,
                         TFM_SECURE_CLIENT_SFN_RUN_TESTS_MIN_VER);
    if (handle <= 0) {
        return TFM_ERROR_GENERIC;
    }

    status = psa_call(handle, NULL, 0, NULL, 0);
    psa_close(handle);

    if (status != PSA_SUCCESS) {
        return TFM_ERROR_GENERIC;
    }
#else
    tfm_secure_client_service_veneer_run_tests();
#endif

    return 0;
}

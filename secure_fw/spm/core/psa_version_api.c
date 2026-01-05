/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "ffm/psa_api.h"
#include "load/service_defs.h"
#include "spm.h"

uint32_t tfm_spm_client_psa_framework_version(void)
{
    return PSA_FRAMEWORK_VERSION;
}

uint32_t tfm_spm_client_psa_version(uint32_t sid)
{
    const struct service_t *service;
    bool ns_caller = tfm_spm_is_ns_caller();

    /*
     * It should return PSA_VERSION_NONE if the RoT Service is not
     * implemented.
     */
    service = tfm_spm_get_service_by_sid(sid);
    if (!service) {
        return PSA_VERSION_NONE;
    }

    /*
     * It should return PSA_VERSION_NONE if the caller is not authorized
     * to access the RoT Service.
     */
    if (tfm_spm_check_authorization(sid, service, ns_caller) != PSA_SUCCESS) {
        return PSA_VERSION_NONE;
    }

    assert(service->p_ldinf != NULL);

    return service->p_ldinf->version;
}

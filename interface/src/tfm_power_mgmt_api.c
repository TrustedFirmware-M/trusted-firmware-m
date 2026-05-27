/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "power_mgmt/tfm_power_mgmt_api.h"

#include "psa/client.h"
#include "psa_manifest/sid.h"

enum tfm_power_mgmt_err_t tfm_power_mgmt_set_state(
    enum tfm_power_mgmt_power_state_t pwr_state,
    uint32_t wait_for)
{
    union tfm_power_mgmt_call_params pm_params;
    psa_status_t status;
    struct psa_invec in_vec[1];

    if ((pwr_state > TFM_POWER_MGMT_PWR_STATE_COUNT) ||
        (pwr_state > TFM_POWER_MGMT_WAIT_FOR_INTERRUPT)) {
        return TFM_POWER_MGMT_ERR_INVALID_PARAM;
    }

    if ((wait_for == TFM_POWER_MGMT_WAIT_FOR_NONE) &&
        (pwr_state < TFM_POWER_MGMT_PWR_STATE_CPUSYSTEM_COUNT)) {
        return TFM_POWER_MGMT_ERR_INVALID_PARAM;
    }
    if (((wait_for == TFM_POWER_MGMT_WAIT_FOR_EVENT) ||
        (wait_for == TFM_POWER_MGMT_WAIT_FOR_INTERRUPT)) &&
        (pwr_state > TFM_POWER_MGMT_PWR_STATE_CPUSYSTEM_COUNT)) {
        return TFM_POWER_MGMT_ERR_INVALID_PARAM;
    }

    pm_params.set.call_type = TFM_POWER_MGMT_SET;
    pm_params.set.pwr_state = pwr_state;
    pm_params.set.wait_for = wait_for;

    in_vec[0].base = &pm_params;
    in_vec[0].len = sizeof(pm_params);

    status = psa_call(TFM_POWER_MGMT_SERVICE_HANDLE,
                      PSA_IPC_CALL,
                      in_vec, 1,
                      NULL, 0);
    if (status < PSA_SUCCESS) {
        return TFM_POWER_MGMT_ERR_SYSTEM_ERROR;
    } else {
        return TFM_POWER_MGMT_ERR_SUCCESS;
    }
}

enum tfm_power_mgmt_err_t tfm_power_mgmt_get_state(
    uint32_t device_id,
    int32_t *state)
{
    union tfm_power_mgmt_call_params pm_params;
    psa_status_t status;

    struct psa_invec in_vec[1];
    struct psa_outvec out_vec[1];

    if (device_id > PLAT_POWER_MGMT_DEVICE_ID_MAX) {
        return TFM_POWER_MGMT_ERR_INVALID_PARAM;
    }

    pm_params.get.call_type = TFM_POWER_MGMT_GET;
    pm_params.get.device_id = device_id;

    in_vec[0].base = &pm_params;
    in_vec[0].len = sizeof(pm_params);
    out_vec[0].base = state;
    out_vec[0].len = sizeof(*state);

    status = psa_call(TFM_POWER_MGMT_SERVICE_HANDLE,
                      PSA_IPC_CALL,
                      in_vec, 1,
                      out_vec, 1);
    if (status < PSA_SUCCESS) {
        return TFM_POWER_MGMT_ERR_SYSTEM_ERROR;
    } else {
        return TFM_POWER_MGMT_ERR_SUCCESS;
    }
}

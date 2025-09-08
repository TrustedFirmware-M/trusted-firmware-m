/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "current.h"
#include "fih.h"
#include "internal_status_code.h"
#include "spm.h"
#include "tfm_hal_isolation.h"
#include "tfm_multi_core.h"
#include "ffm/mailbox_agent_api.h"
#include "ffm/backend.h"
#include "ffm/psa_api.h"
#include "psa/error.h"

psa_status_t tfm_spm_agent_psa_call(psa_handle_t handle,
                                    uint32_t control,
                                    const struct client_params_t *params,
                                    const void *client_data_stateless)
{
    struct connection_t *p_connection;
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    psa_status_t status;

    FIH_CALL(tfm_hal_memory_check, fih_rc,
             curr_partition->boundary, (uintptr_t)params,
             sizeof(struct client_params_t),
             TFM_HAL_ACCESS_READABLE);
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    status = spm_get_idle_connection(&p_connection, handle, params->ns_client_id_stateless);
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = spm_associate_call_params(p_connection, control, params->p_invecs, params->p_outvecs);
    if (status != PSA_SUCCESS) {
        if (IS_STATIC_HANDLE(handle)) {
            spm_free_connection(p_connection);
        }
        return status;
    }

    /* Set Mailbox client data in connection handle for message reply. */
    p_connection->client_data = client_data_stateless;

    status = backend_messaging(p_connection);

    p_connection->status = TFM_HANDLE_STATUS_ACTIVE;
    return status;
}

#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1

psa_status_t tfm_spm_agent_psa_connect(uint32_t sid, uint32_t version,
                                       int32_t ns_client_id,
                                       const void *client_data)
{
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();
    struct connection_t *p_connection;
    psa_status_t status;

    if (!IS_NS_AGENT_MAILBOX(curr_partition->p_ldinf)) {
        tfm_core_panic();
    }
    if (ns_client_id >= 0) {
        tfm_core_panic();
    }

    status = spm_psa_connect_client_id_associated(&p_connection, sid, version, ns_client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Set Mailbox client data in connection handle for message reply. */
    p_connection->client_data = client_data;

    status = backend_messaging(p_connection);

    p_connection->status = TFM_HANDLE_STATUS_ACTIVE;
    return status;
}

psa_status_t tfm_spm_agent_psa_close(psa_handle_t handle,
                                     int32_t ns_client_id)
{
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();

    if ((!IS_NS_AGENT_MAILBOX(curr_partition->p_ldinf)) || (ns_client_id >= 0)) {
        tfm_core_panic();
    }

    return spm_psa_close_client_id_associated(handle, ns_client_id);
}
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "ffm/backend.h"
#include "ffm/psa_api.h"
#include "load/service_defs.h"
#include "spm.h"
#include "utilities.h"

/* PSA APIs only needed by connection-based services */

psa_status_t tfm_spm_client_psa_connect(uint32_t sid, uint32_t version)
{
    int32_t client_id;
    struct connection_t *p_connection;
    psa_status_t status;

    bool ns_caller = tfm_spm_is_ns_caller();

    client_id = tfm_spm_get_client_id(ns_caller);
    status = spm_psa_connect_client_id_associated(&p_connection, sid, version, client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = backend_messaging(p_connection);

    p_connection->status = TFM_HANDLE_STATUS_ACTIVE;
    return status;
}

psa_status_t spm_psa_connect_client_id_associated(struct connection_t **p_connection,
                                                  uint32_t sid, uint32_t version, int32_t client_id)
{
    const struct service_t *service;
    struct connection_t *connection;
    bool ns_caller = (client_id < 0) ? true : false;

    /*
     * It is a PROGRAMMER ERROR if the RoT Service does not exist on the
     * platform.
     */
    service = tfm_spm_get_service_by_sid(sid);
    if (!service) {
        return PSA_ERROR_CONNECTION_REFUSED;
    }

    /* It is a PROGRAMMER ERROR if connecting to a stateless service. */
    if (SERVICE_IS_STATELESS(service->p_ldinf->flags)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /*
     * It is a PROGRAMMER ERROR if the caller is not authorized to access the
     * RoT Service.
     */
    if (tfm_spm_check_authorization(sid, service, ns_caller) != PSA_SUCCESS) {
        return PSA_ERROR_CONNECTION_REFUSED;
    }

    /*
     * It is a PROGRAMMER ERROR if the version of the RoT Service requested is
     * not supported on the platform.
     */
    if (tfm_spm_check_client_version(service, version) != PSA_SUCCESS) {
        return PSA_ERROR_CONNECTION_REFUSED;
    }

    /*
     * Create connection handle here since it is possible to return the error
     * code to client when creation fails.
     *
     * Current SPM doesn't support multiple context management. There is only one
     * instance in SPM to call the connection pool allocation. It is no need to be
     * protected.
     * Protection should be established after the context management is implemented.
     */
    connection = spm_allocate_connection();
    if (!connection) {
        return PSA_ERROR_CONNECTION_BUSY;
    }

    spm_init_idle_connection(connection, service, client_id);
    connection->msg.type = PSA_IPC_CONNECT;

    assert(p_connection != NULL);
    *p_connection = connection;

    return PSA_SUCCESS;
}

psa_status_t tfm_spm_client_psa_close(psa_handle_t handle)
{
    bool ns_caller = tfm_spm_is_ns_caller();
    return spm_psa_close_client_id_associated(handle, tfm_spm_get_client_id(ns_caller));
}

psa_status_t spm_psa_close_client_id_associated(psa_handle_t handle, int32_t client_id)
{
    struct connection_t *p_connection;
    psa_status_t status;

    /* It will have no effect if called with the NULL handle */
    if (handle == PSA_NULL_HANDLE) {
        return PSA_SUCCESS;
    }

    /* It is a PROGRAMMER ERROR if called with a stateless handle. */
    if (IS_STATIC_HANDLE(handle)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /*
     * It is a PROGRAMMER ERROR if an invalid handle was provided that is not
     * the null handle.
     */
    status = spm_get_idle_connection(&p_connection, handle, client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    p_connection->msg.type = PSA_IPC_DISCONNECT;

    status = backend_messaging(p_connection);

    p_connection->status = TFM_HANDLE_STATUS_TO_FREE;

    return status;
}

psa_status_t tfm_spm_partition_psa_set_rhandle(psa_handle_t msg_handle, void *rhandle)
{
    struct connection_t *handle;

    /* It is a fatal error if message handle is invalid */
    handle = spm_msg_handle_to_connection(msg_handle);
    if (!handle) {
        tfm_core_panic();
    }

    /* It is a PROGRAMMER ERROR if a stateless service sets rhandle. */
    if (SERVICE_IS_STATELESS(handle->service->p_ldinf->flags)) {
        tfm_core_panic();
    }

    handle->msg.rhandle = rhandle;

    return PSA_SUCCESS;
}

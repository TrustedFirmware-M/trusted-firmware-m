/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __AGENT_API_H__
#define __AGENT_API_H__

#include <stdint.h>
#include "psa/service.h"

struct client_params_t {
    int32_t    ns_client_id_stateless;
    psa_invec  *p_invecs;
    psa_outvec *p_outvecs;
};

/**
 * \brief Specific psa_call() variants for agents
 *
 * \param[in] handle                 Handle to the service being accessed.
 * \param[in] control                A composited uint32_t value for controlling purpose,
 *                                   containing call types, numbers of in/out vectors and
 *                                   attributes of vectors.
 * \param[in] params                 Combines the psa_invec and psa_outvec params
 *                                   for the psa_call() to be made, as well as
 *                                   NS agent's client identifier, which is ignored
 *                                   for connection-based services.
 * \param[in] client_data_stateless  Client data, treated as opaque by SPM.
 *
 * \retval PSA_SUCCESS               Success.
 * \retval "Does not return"         The call is invalid, one or more of the
 *                                   following are true:
 * \arg                                An invalid handle was passed.
 * \arg                                The connection is already handling a request.
 * \arg                                An invalid memory reference was provided.
 * \arg                                in_num + out_num > PSA_MAX_IOVEC.
 * \arg                                The message is unrecognized by the RoT
 *                                     Service or incorrectly formatted.
 */
psa_status_t agent_psa_call(psa_handle_t handle, uint32_t control,
                            const struct client_params_t *params,
                            const void *client_data_stateless);

#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1

/**
 * \brief psa_connect() interface for NS agents
 *
 * \param[in] sid                       RoT Service identity.
 * \param[in] version                   The version of the RoT Service.
 * \param[in] ns_client_id              NS client's identifier.
 * \param[in] client_data               Client data, treated as opaque by SPM.
 *
 * \retval PSA_SUCCESS                  Success.
 * \retval PSA_ERROR_CONNECTION_REFUSED The SPM or RoT Service has refused the
 *                                      connection.
 * \retval PSA_ERROR_CONNECTION_BUSY    The SPM or RoT Service cannot make the
 *                                      connection at the moment.
 * \retval "Does not return"            The RoT Service ID and version are not
 *                                      supported, or the caller is not
 *                                      permitted to access the service.
 */
psa_status_t agent_psa_connect(uint32_t sid, uint32_t version,
                               int32_t ns_client_id, const void *client_data);

/**
 * \brief psa_close() interface for NS agents
 *
 * \param[in] handle            A handle to an established connection, or the
 *                              null handle.
 * \param[in] ns_client_id      NS client's identifier.
 *
 * \retval PSA_SUCCESS          Success.
 * \retval "PROGRAMMER ERROR"   The call is a PROGRAMMER ERROR if one or more
 *                              of the following are true:
 * \arg                           An invalid handle was provided that is not
 *                                the null handle.
 * \arg                           The connection is currently handling a
 *                                request.
 */
psa_status_t agent_psa_close(psa_handle_t handle, int32_t ns_client_id);

#else /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */
#define agent_psa_connect    NULL
#define agent_psa_close      NULL
#endif /* CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */

#endif /* __AGENT_API_H__ */

/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * Definitions of Remote Procedure Call (RPC) functionalities in TF-M, which
 * sits between upper TF-M SPM and underlying mailbox implementation.
 */

#ifndef __TFM_RPC_H__
#define __TFM_RPC_H__

#ifdef TFM_PARTITION_NS_AGENT_MAILBOX

#include <stdint.h>
#include "cmsis_compiler.h"
#include "psa/client.h"
#include "psa/service.h"
#include "thread.h"
#include "spm.h"
#include "ffm/mailbox_agent_api.h"

#define TFM_RPC_SUCCESS             (0)
#define TFM_RPC_INVAL_PARAM         (INT32_MIN + 1)
#define TFM_RPC_CONFLICT_CALLBACK   (INT32_MIN + 2)

/*
 * The underlying mailbox communication implementation should provide
 * the specific operations to complete the RPC functionalities.
 *
 * It includes the following operations:
 * handle_req() - Handle PSA client call request from NSPE
 * reply()      - Reply PSA client call return result to NSPE. The parameter
 *                owner identifies the owner of the PSA client call.
 */
struct tfm_rpc_ops_t {
    void (*handle_req)(void);
    void (*reply)(const void *owner, int32_t ret);
};

/**
 * \brief RPC handler for \ref psa_framework_version.
 *
 * \return version              The version of the PSA Framework implementation
 *                              that is providing the runtime services.
 */
uint32_t tfm_rpc_psa_framework_version(void);

/**
 * \brief RPC handler for \ref psa_version.
 *
 * \param[in] sid               RoT Service identity.
 *
 * \retval PSA_VERSION_NONE     The RoT Service is not implemented, or the
 *                              caller is not permitted to access the service.
 * \retval > 0                  The version of the implemented RoT Service.
 */
uint32_t tfm_rpc_psa_version(uint32_t sid);

/**
 * \brief RPC handler for \ref psa_connect.
 *
 * \param[in] sid               RoT Service identity.
 * \param[in] version           The version of the RoT Service.
 * \param[in] ns_client_id      Agent representing NS client's identifier.
 * \param[in] client_data       Client data, treated as opaque by SPM.
 *
 * \retval PSA_SUCCESS          Success.
 * \retval PSA_CONNECTION_BUSY  The SPM cannot make the connection
 *                              at the moment.
 * \retval "Does not return"    The RoT Service ID and version are not
 *                              supported, or the caller is not permitted to
 *                              access the service.
 */
psa_status_t tfm_rpc_psa_connect(uint32_t sid,
                                 uint32_t version,
                                 int32_t ns_client_id,
                                 const void *client_data);

/**
 * \brief RPC handler for \ref psa_call.
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
psa_status_t tfm_rpc_psa_call(psa_handle_t handle, uint32_t control,
                              const struct client_params_t *params,
                              const void *client_data_stateless);

/**
 * \brief RPC handler for \ref psa_close.
 *
 * \param[in] handle            A handle to an established connection, or the null handle.
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
psa_status_t tfm_rpc_psa_close(psa_handle_t handle, int32_t ns_client_id);

/**
 * \brief Register underlying mailbox communication operations.
 *
 * \param[in] ops_ptr           Pointer to the specific operation structure.
 *
 * \retval TFM_RPC_SUCCESS      Mailbox operations are successfully registered.
 * \retval Other error code     Fail to register mailbox operations.
 */
int32_t tfm_rpc_register_ops(const struct tfm_rpc_ops_t *ops_ptr);

/**
 * \brief Unregister underlying mailbox communication operations.
 *
 * Currently one and only one underlying mailbox communication implementation is
 * allowed in runtime. Thus it is unnecessary to specify the mailbox
 * communication operation callbacks to be unregistered.
 *
 * \param[in] void
 */
void tfm_rpc_unregister_ops(void);

/**
 * \brief Handling PSA client call request
 *
 * \param void
 */
void tfm_rpc_client_call_handler(void);

#if CONFIG_TFM_SPM_BACKEND_IPC == 1
/**
 * \brief Reply PSA client call return result
 *
 * \param[in] void
 */
void tfm_rpc_client_call_reply(void);
#endif /* CONFIG_TFM_SPM_BACKEND_IPC == 1 */
#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */
#endif /* __TFM_RPC_H__ */

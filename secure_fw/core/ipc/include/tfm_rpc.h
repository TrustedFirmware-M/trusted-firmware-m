/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * Definitions of Remote Procedure Call (RPC) functionalities in TF-M, which
 * sits between upper TF-M SPM and underlying mailbox implementation.
 */

#ifndef _TFM_RPC_H_
#define _TFM_RPC_H_

#if TFM_MULTI_CORE_TOPOLOGY

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_compiler.h"
#include "psa_client.h"
#include "psa_service.h"
#include "tfm_thread.h"
#include "tfm_wait.h"
#include "tfm_message_queue.h"

#define TFM_RPC_SUCCESS             (0)
#define TFM_RPC_INVAL_PARAM         (INT32_MIN + 1)
#define TFM_RPC_CONFLICT_CALLBACK   (INT32_MIN + 2)

/*
 * This structure holds the parameters used in a PSA client call.
 * The parameters are passed from non-secure core to secure core.
 */
struct client_call_params_t {
    uint32_t        sid;
    psa_handle_t    handle;
    const psa_invec *in_vec;
    size_t          in_len;
    psa_outvec      *out_vec;
    size_t          out_len;
    uint32_t        minor_version;
};

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
    void (*reply)(void *owner, int32_t ret);
};

/**
 * \brief RPC handler for \ref psa_framework_version.
 *
 * \param[in] params            Base address of parameters.
 *
 * \return version              The version of the PSA Framework implementation
 *                              that is providing the runtime services.
 */
uint32_t tfm_rpc_psa_framework_version(
                                    const struct client_call_params_t *params);

/**
 * \brief RPC handler for \ref psa_version.
 *
 * \param[in] params            Base address of parameters
 * \param[in] ns_caller         A non-zero value to indicate
 *                              the non-secure caller
 *
 * \retval PSA_VERSION_NONE     The RoT Service is not implemented, or the
 *                              caller is not permitted to access the service.
 * \retval > 0                  The minor version of the implemented RoT
 *                              Service.
 */
uint32_t tfm_rpc_psa_version(const struct client_call_params_t *params,
                             int32_t ns_caller);

/**
 * \brief RPC handler for \ref psa_connect.
 *
 * \param[in] params            Base address of parameters
 * \param[in] ns_caller         A non-zero value to indicate
 *                              the non-secure caller
 *
 * \retval PSA_SUCCESS          Success.
 * \retval PSA_CONNECTION_BUSY  The SPM cannot make the connection
 *                              at the moment.
 * \retval "Does not return"    The RoT Service ID and version are not
 *                              supported, or the caller is not permitted to
 *                              access the service.
 */
psa_status_t tfm_rpc_psa_connect(const struct client_call_params_t *params,
                                 int32_t ns_caller);

/**
 * \brief RPC handler for \ref psa_call.
 *
 * \param[in] params            Base address of parameters
 * \param[in] ns_caller         A non-zero value to indicate
 *                              the non-secure caller
 *
 * \retval PSA_SUCCESS          Success.
 * \retval "Does not return"    The call is invalid, one or more of the
 *                              following are true:
 * \arg                           An invalid handle was passed.
 * \arg                           The connection is already handling a request.
 * \arg                           An invalid memory reference was provided.
 * \arg                           in_len + out_len > PSA_MAX_IOVEC.
 * \arg                           The message is unrecognized or
 *                                incorrectly formatted.
 */
psa_status_t tfm_rpc_psa_call(const struct client_call_params_t *params,
                              int32_t ns_caller);

/**
 * \brief RPC handler for \ref psa_close.
 *
 * \param[in] params            Base address of parameters
 * \param[in] ns_caller         A non-zero value to indicate
 *                              the non-secure caller
 *
 * \retval void                 Success.
 * \retval "Does not return"    The call is invalid, one or more of the
 *                              following are true:
 * \arg                           An invalid handle was provided that is not
 *                                the null handle..
 */
void tfm_rpc_psa_close(const struct client_call_params_t *params,
                       int32_t ns_caller);

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
 * \param[in] ops_ptr           Pointer to the specific operation structure.
 */
void tfm_rpc_unregister_ops(const struct tfm_rpc_ops_t *ops_ptr);

/**
 * \brief Handling PSA client call request
 *
 * \param void
 */
void tfm_rpc_client_call_handler(void);

/**
 * \brief Reply PSA client call return result
 *
 * \param[in] owner             A handle to identify the owner of the PSA
 *                              client call.
 * \param[in] ret               PSA client call return result value.
 */
void tfm_rpc_client_call_reply(void *owner, int32_t ret);

/*
 * Check if the message was allocated for a non-secure request via RPC
 *
 * \param[in] msg           The message body context pointer
 *                          \ref msg_body_t structures
 *
 * \retval true             The message was allocated for a NS request via RPC.
 * \retval false            Otherwsie.
 */
__STATIC_INLINE bool is_tfm_rpc_msg(const struct tfm_msg_body_t *msg)
{
    /*
     * FIXME
     * The ID should be smaller than 0 if the message is allocted by a
     * non-secure caller.
     * However, current TF-M implementation use 0 as the default non-secure
     * caller ID. Therefore, treat the caller as non-secure when client_id == 0.
     *
     * This conditiion check should be improved after TF-M non-secure client ID
     * management is implemented.
     */
    if (msg && (msg->msg.client_id <= 0) && !msg->ack_evnt.owner) {
        return true;
    }

    return false;
}
#else /* TFM_MULIT_CORE_TOPOLOGY */

/* RPC is only available in mulit-core scenario */
#define is_tfm_rpc_msg(x)             (false)

#define tfm_rpc_client_call_handler() do {} while (0)

#define tfm_rpc_client_call_reply(owner, ret)   do {} while (0)

#endif /* TFM_MULIT_CORE_TOPOLOGY */
#endif
/*
 * Copyright (c) 2020-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2021-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SPM_H__
#define __SPM_H__

#include <stdbool.h>
#include <stdint.h>
#include "config_impl.h"
#include "config_spm.h"
#include "tfm_arch.h"
#include "lists.h"
#include "runtime_defs.h"
#include "thread.h"
#include "psa/service.h"
#include "load/partition_defs.h"
#include "load/interrupt_defs.h"

enum connection_status {
    TFM_HANDLE_STATUS_IDLE = 0,     /* Handle created, idle */
    TFM_HANDLE_STATUS_ACTIVE = 1,   /* Handle in use */
    TFM_HANDLE_STATUS_TO_FREE = 2,  /* Handle to be freed */
    TFM_HANDLE_STATUS_MAX = 3,

    _TFM_HANDLE_STATUS_PAD = UINT32_MAX,
};

/* The mask used for timeout values */
#define PSA_TIMEOUT_MASK        PSA_BLOCK

/*
 * Set a number limit for stateless handle.
 * Valid handle must be positive, set client handle minimum value to 1.
 */
#define STATIC_HANDLE_NUM_LIMIT         32
#define CLIENT_HANDLE_VALUE_MIN         1

/*
 * Bit width can be increased to match STATIC_HANDLE_NUM_LIMIT,
 * current allowed maximum bit width is 8 for 256 handles.
 */
#define STATIC_HANDLE_IDX_BIT_WIDTH     5
#define STATIC_HANDLE_IDX_MASK \
    (uint32_t)((1UL << STATIC_HANDLE_IDX_BIT_WIDTH) - 1)
#define GET_INDEX_FROM_STATIC_HANDLE(handle) \
    (uint32_t)((handle) & STATIC_HANDLE_IDX_MASK)

#define STATIC_HANDLE_VER_BIT_WIDTH     8
#define STATIC_HANDLE_VER_OFFSET        8
#define STATIC_HANDLE_VER_MASK \
    (uint32_t)((1UL << STATIC_HANDLE_VER_BIT_WIDTH) - 1)
#define GET_VERSION_FROM_STATIC_HANDLE(handle) \
    (uint32_t)(((handle) >> STATIC_HANDLE_VER_OFFSET) & STATIC_HANDLE_VER_MASK)

/* Validate the static handle indicator bit */
#define STATIC_HANDLE_INDICATOR_OFFSET  30
#define IS_STATIC_HANDLE(handle) \
    ((handle) & (1UL << STATIC_HANDLE_INDICATOR_OFFSET))

#define SPM_INVALID_PARTITION_IDX       (~0U)

/* Get partition by thread or context data */
#define GET_THRD_OWNER(x)        TO_CONTAINER(x, struct partition_t, thrd)
#define GET_CTX_OWNER(x)         TO_CONTAINER(x, struct partition_t, ctx_ctrl)

/* Checks if the provided client ID is a non-secure client ID */
#define TFM_CLIENT_ID_IS_NS(client_id)        ((client_id) < 0)

/* RoT connection handle list */
struct connection_t {
    enum connection_status status;
    struct partition_t *p_client;            /* Caller partition               */
    const struct service_t *service;         /* RoT service pointer            */
    psa_msg_t msg;                           /* PSA message body               */
    const void *invec_base[PSA_MAX_IOVEC];   /* Base addresses of invec from client */
    size_t invec_accessed[PSA_MAX_IOVEC];    /* Size of data accessed by psa_read/skip */
    void *outvec_base[PSA_MAX_IOVEC];        /* Base addresses of outvec from client */
    size_t outvec_written[PSA_MAX_IOVEC];    /* Size of data written by psa_write */
    psa_outvec *caller_outvec;               /* Save caller outvec pointer for write length update*/
#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
    const void *client_data;                 /*
                                              * Pointer to the private data of the
                                              * client. It saves the mailbox private
                                              * data in multi-core topology.
                                              */
#endif
#if PSA_FRAMEWORK_HAS_MM_IOVEC
    uint32_t iovec_status;                   /* MM-IOVEC status                */
#endif
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
    struct connection_t *p_reqs;             /* Request handle(s) link         */
    struct connection_t *p_replied;          /* Replied Handle(s) link         */
    uintptr_t replied_value;                 /* Result of this operation       */
#endif
};

/* Partition runtime type */
struct partition_t {
    const struct partition_load_info_t *p_ldinf;
    uintptr_t                          boundary;
    uint32_t                           signals_allowed;
    uint32_t                           signals_waiting;
    volatile uint32_t                  signals_asserted;
#if CONFIG_TFM_SPM_BACKEND_IPC == 1
    const struct runtime_metadata_t    *p_metadata;
    struct context_ctrl_t              ctx_ctrl;
    struct thread_t                    thrd;       /* IPC model */
    struct connection_t                *p_replied; /* Handle(s) to record replied connections */
#else
    uint32_t                           state;      /* SFN model */
#endif
    struct connection_t                *p_reqs;    /* Handle(s) to record request connections to service. */
    struct partition_t                 *next;
};

/* RoT Service data */
struct service_t {
    const struct service_load_info_t *p_ldinf;     /* Service load info      */
    struct partition_t *partition;                 /* Owner of the service   */
    struct service_t *next;                        /* For list operation     */
};

/**
 * \brief   Get the running partition ID.
 *
 * \return  Returns the partition ID
 */
int32_t tfm_spm_partition_get_running_partition_id(void);

/******************** Service handle management functions ********************/
void spm_init_connection_space(void);

struct connection_t *spm_allocate_connection(void);

psa_status_t spm_validate_connection(const struct connection_t *p_connection);

/* Panic if invalid connection is given. */
void spm_free_connection(struct connection_t *p_connection);

/******************** Partition management functions *************************/

#if CONFIG_TFM_SPM_BACKEND_IPC == 1

/*
 * Get the replied handles in the asynchnorous reply mode. The first handle to
 * be replied is at the tail of list. Take the handle one by one and clean the
 * asynchronous signal after all handles are operated.
 */
struct connection_t *spm_get_async_replied_handle(struct partition_t *partition);

/*
 * Lookup and grab the last spotted handles containing the message
 * by the given signal. Only ONE signal bit can be accepted in 'signal',
 * multiple bits lead to 'no matched handles found to that signal'.
 *
 * Returns NULL if no handles matched with the given signal.
 * Returns an internal handle instance if spotted, the instance
 * is moved out of partition handles. Partition available signals
 * also get updated based on the count of handles with given signal
 * still in the partition handles.
 */
struct connection_t *spm_get_handle_by_signal(struct partition_t *p_ptn,
                                              psa_signal_t signal);
#endif /* CONFIG_TFM_SPM_BACKEND_IPC */

#if CONFIG_TFM_DOORBELL_API == 1
/**
 * \brief                   Get partition by Partition ID.
 *
 * \param[in] partition_id  The Partition ID of the partition to get
 *
 * \retval NULL             Failed
 * \retval "Not NULL"       Return the partition context pointer
 *                          \ref partition_t structures
 */
struct partition_t *tfm_spm_get_partition_by_id(int32_t partition_id);
#endif /* CONFIG_TFM_DOORBELL_API == 1 */

/**
 * \brief                   Get the service context by service ID.
 *
 * \param[in] sid           RoT Service identity
 *
 * \retval NULL             Failed
 * \retval "Not NULL"       Target service context pointer,
 *                          \ref service_t structures
 */
const struct service_t *tfm_spm_get_service_by_sid(uint32_t sid);

/************************ Message functions **********************************/

/**
 * \brief                   Convert the given user handle to an SPM recognised
 *                          connection and verify that it is a valid idle
 *                          connection that the caller is authorised to access.
 *
 * \param[out] p_connection The address of connection pointer to be converted
 *                          from the given user handle.
 *
 * \param[in] handle        Either a static handle or a handle to an established
 *                          connection that was returned by a prior psa_connect
 *                          call.
 *
 * \param[in] client_id     The client ID of the caller.
 *
 * \retval PSA_SUCCESS      Success.
 * \retval PSA_ERROR_CONNECTION_REFUSED The SPM or RoT Service has refused the
 *                          connection.
 * \retval PSA_ERROR_CONNECTION_BUSY The SPM or RoT Service cannot make the
 *                          connection at the moment.
 * \retval PSA_ERROR_PROGRAMMER_ERROR The handle is invalid, the caller is not
 *                          authorised to use it or the connection is already
 *                          handling a request.
 */
psa_status_t spm_get_idle_connection(struct connection_t **p_connection,
                                     psa_handle_t handle,
                                     int32_t client_id);

/**
 * \brief                   Convert the given message handle to SPM recognised
 *                          handle and verify it.
 *
 * \param[in] msg_handle    Message handle which is a reference generated
 *                          by the SPM to a specific message.
 *
 * \return                  A SPM recognised handle or NULL. It is NULL when
 *                          verification of the converted SPM handle fails.
 *                          \ref connection_t structures
 */
struct connection_t *spm_msg_handle_to_connection(psa_handle_t msg_handle);

/**
 * \brief                   Initialize connection, fill in with the input
 *                          information and set to idle.
 *
 * \param[in] p_connection  The 'p_connection' to initialize and fill information in.
 * \param[in] service       Target service context pointer, which can be
 *                          obtained by partition management functions
 * \param[in] client_id     Partition ID of the sender of the message
 */
void spm_init_idle_connection(struct connection_t *p_connection,
                              const struct service_t *service,
                              int32_t client_id);

/*
 * Update connection content with information extracted from control param,
 * including message type and information of IO vectors if any.
 */
psa_status_t spm_associate_call_params(struct connection_t *p_connection,
                                       uint32_t            ctrl_param,
                                       const psa_invec     *inptr,
                                       psa_outvec          *outptr);

/**
 * \brief                   Check the client version according to
 *                          version policy
 *
 * \param[in] service       Target service context pointer, which can be get
 *                          by partition management functions
 * \param[in] version       Client support version
 *
 * \retval PSA_SUCCESS      Success
 * \retval SPM_ERROR_BAD_PARAMETERS Bad parameters input
 * \retval SPM_ERROR_VERSION Check failed
 */
int32_t tfm_spm_check_client_version(const struct service_t *service,
                                     uint32_t version);

/**
 * \brief                   Check the client access authorization
 *
 * \param[in] sid           Target RoT Service identity
 * \param[in] service       Target service context pointer, which can be get
 *                          by partition management functions
 * \param[in] ns_caller     Whether from NS caller
 *
 * \retval PSA_SUCCESS      Success
 * \retval SPM_ERROR_GENERIC Authorization check failed
 */
int32_t tfm_spm_check_authorization(uint32_t sid,
                                    const struct service_t *service,
                                    bool ns_caller);

/**
 * \brief                       Get the ns_caller info from runtime context.
 *
 * \retval                      - true: the PSA API caller is from non-secure
 *                              - false: the PSA API caller is from secure
 */
bool tfm_spm_is_ns_caller(void);

/**
 * \brief               Get ID of current RoT Service client.
 *                      This API ensures the caller gets a valid ID.
 *
 * \param[in] ns_caller If the client is Non-Secure or not.
 *
 * \retval              The client ID
 */
int32_t tfm_spm_get_client_id(bool ns_caller);

/*
 * PendSV specified function.
 *
 * Parameters :
 *  exc_return    -    EXC_RETURN value for the PendSV handler
 *
 * Return:
 *  Pointers to context control (sp, splimit, dummy, lr) of the current and
 *  the next thread.
 *  Each takes 32 bits. The context control is used by PendSV_Handler to do
 *  context switch.
 */
uint64_t ipc_schedule(uint32_t exc_return);

/**
 * \brief                      SPM initialization implementation
 *
 * \details                    This function must be called under handler mode.
 * \retval                     This function returns an EXC_RETURN value. Other
 *                             faults would panic the execution and never
 *                             returned.
 */
uint32_t tfm_spm_init(void);

/**
 * \brief Converts a handle instance into a corresponded user handle.
 */
psa_handle_t connection_to_handle(struct connection_t *p_connection);

/**
 * \brief Converts a user handle into a corresponded handle instance.
 */
struct connection_t *handle_to_connection(psa_handle_t handle);


/* Following PSA APIs are only needed by connection-based services */
#if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1

/* Handler for \ref psa_connect.
 *
 * \param[in] p_connection      The address of connection pointer.
 * \param[in] sid               RoT Service identity.
 * \param[in] version           The version of the RoT Service.
 * \param[in] client_id         Client id of the service caller. It should be
 *                              validated before this API is being called.
 *
 * \retval PSA_SUCCESS          Success.
 * \retval PSA_ERROR_CONNECTION_REFUSED The SPM or RoT Service has refused the
 *                              connection.
 * \retval PSA_ERROR_CONNECTION_BUSY The SPM or RoT Service cannot make the
 *                              connection at the moment.
 * \retval "Does not return"    The RoT Service ID and version are not
 *                              supported, or the caller is not permitted to
 *                              access the service.
 */
psa_status_t spm_psa_connect_client_id_associated(struct connection_t **p_connection,
                                                  uint32_t sid, uint32_t version,
                                                  int32_t client_id);

/* Handler for \ref psa_close.
 *
 * \param[in] handle            Service handle to the connection to be closed,
 *                              \ref psa_handle_t
 * \param[in] client_id         Client id of the connection caller.
 *
 * \retval PSA_SUCCESS          Success.
 * \retval PSA_ERROR_PROGRAMMER_ERROR The call is invalid, one or more of the
 *                              following are true:
 * \arg                           Called with a stateless handle.
 * \arg                           An invalid handle was provided that is not
 *                                the null handle.
 * \arg                           The connection is handling a request.
 */
psa_status_t spm_psa_close_client_id_associated(psa_handle_t handle, int32_t client_id);

#endif /* #if CONFIG_TFM_CONNECTION_BASED_SERVICE_API == 1 */

#ifdef TFM_PARTITION_NS_AGENT_MAILBOX

/*
 * Check if the message was allocated for a non-secure request via RPC
 *
 *  param[in] handle        The connection handle context pointer
 *                          connection_t structures
 *
 *  retval true             The message was allocated for a NS request via RPC.
 *  retval false            Otherwise.
 */
__STATIC_INLINE bool tfm_spm_is_rpc_msg(const struct connection_t *handle)
{
    if (handle && (handle->client_data) && (handle->msg.client_id < 0)) {
        return true;
    }

    return false;
}
#else /* TFM_PARTITION_NS_AGENT_MAILBOX */

/* RPC is only available in multi-core scenario */
#define tfm_spm_is_rpc_msg(x)                       (false)

#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */

#endif /* __SPM_H__ */

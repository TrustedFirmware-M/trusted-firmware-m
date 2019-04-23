/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdbool.h>

#include "cmsis_os2.h"

#include "interface/include/psa_client.h"
#include "tfm_api.h"
#include "tfm_ns_mailbox.h"

/*
 * FIXME
 * Currently, force all the non-secure client to share the same ID.
 *
 * It requires a more clear mechanism to synchronize the non-secure client
 * ID with SPE in dual core scenario.
 * In current design, the value is transferred to SPE via mailbox message.
 * A dedicated routine to receive the non-secure client information in
 * TF-M core/SPM in dual core scenario should be added besides current
 * implementation for single Armv8-M.
 * The non-secure client identification is shared with SPE in
 * single Armv8-M scenario via CMSIS TrustZone context management API,
 * which may not work in dual core scenario.
 */
#define NON_SECURE_CLIENT_ID            (1)

/*
 * FIXME
 * Require a formal defnition of errors related to mailbox in PSA client call.
 */
#define PSA_INTER_CORE_COMM_ERR         (INT32_MIN + 0xFF)

static osMutexId_t ns_lock_id;

/**
 * \brief Mutex properties, NS lock
 */
static const osMutexAttr_t ns_lock_attrib = {
    .name = "ns_lock",
    .attr_bits = osMutexPrioInherit
};

static void mailbox_wait_reply(mailbox_msg_handle_t handle)
{
    while (!mailbox_is_msg_replied(handle)) {};
}

/**
 * \brief NS world, Init NS lock
 */
uint32_t tfm_ns_lock_init()
{
    ns_lock_id = osMutexNew(&ns_lock_attrib);
    if (ns_lock_id != NULL) {
        return TFM_SUCCESS;
    } else {
        return TFM_ERROR_GENERIC;
    }
}

/**** API functions ****/

uint32_t psa_framework_version(void)
{
    struct client_call_params_t params = { 0 };
    mailbox_msg_handle_t handle;
    uint32_t version;
    int32_t ret;

    osMutexAcquire(ns_lock_id, osWaitForever);

    handle = mailbox_tx_client_call_req(MAILBOX_PSA_FRAMEWORK_VERSION, &params,
                                        NON_SECURE_CLIENT_ID);
    if (handle < 0) {
        osMutexRelease(ns_lock_id);
        return PSA_VERSION_NONE;
    }

    mailbox_wait_reply(handle);

    ret = mailbox_rx_client_call_reply(handle, (int32_t *)&version);
    if (ret != MAILBOX_SUCCESS) {
        version = PSA_VERSION_NONE;
    }

    osMutexRelease(ns_lock_id);

    return version;
}

uint32_t psa_version(uint32_t sid)
{
    struct client_call_params_t params = { 0 };
    mailbox_msg_handle_t handle;
    uint32_t version;
    int32_t ret;

    params.sid = sid;

    osMutexAcquire(ns_lock_id, osWaitForever);

    handle = mailbox_tx_client_call_req(MAILBOX_PSA_VERSION, &params,
                                        NON_SECURE_CLIENT_ID);
    if (handle < 0) {
        osMutexRelease(ns_lock_id);
        return PSA_VERSION_NONE;
    }

    mailbox_wait_reply(handle);

    ret = mailbox_rx_client_call_reply(handle, (int32_t *)&version);
    if (ret != MAILBOX_SUCCESS) {
        version = PSA_VERSION_NONE;
    }

    osMutexRelease(ns_lock_id);

    return version;
}

psa_handle_t psa_connect(uint32_t sid, uint32_t minor_version)
{
    struct client_call_params_t params = { 0 };
    mailbox_msg_handle_t handle;
    psa_handle_t psa_handle;
    int32_t ret;

    params.sid = sid;
    params.minor_version = minor_version;

    osMutexAcquire(ns_lock_id, osWaitForever);

    handle = mailbox_tx_client_call_req(MAILBOX_PSA_CONNECT, &params,
                                        NON_SECURE_CLIENT_ID);
    if (handle < 0) {
        osMutexRelease(ns_lock_id);
        return PSA_NULL_HANDLE;
    }

    mailbox_wait_reply(handle);

    ret = mailbox_rx_client_call_reply(handle, (int32_t *)&psa_handle);
    if (ret != MAILBOX_SUCCESS) {
        psa_handle = PSA_NULL_HANDLE;
    }

    osMutexRelease(ns_lock_id);

    return psa_handle;
}

psa_status_t psa_call(psa_handle_t handle,
                      const psa_invec *in_vec,
                      size_t in_len,
                      psa_outvec *out_vec,
                      size_t out_len)
{
    struct client_call_params_t params = { 0 };
    mailbox_msg_handle_t msg_handle;
    int32_t ret;
    psa_status_t status;

    params.handle = handle;
    params.in_vec = in_vec;
    params.in_len = in_len;
    params.out_vec = out_vec;
    params.out_len = out_len;

    osMutexAcquire(ns_lock_id, osWaitForever);

    msg_handle = mailbox_tx_client_call_req(MAILBOX_PSA_CALL, &params,
                                            NON_SECURE_CLIENT_ID);
    if (msg_handle < 0) {
        osMutexRelease(ns_lock_id);
        return PSA_INTER_CORE_COMM_ERR;
    }

    mailbox_wait_reply(msg_handle);

    ret = mailbox_rx_client_call_reply(msg_handle, (int32_t *)&status);
    if (ret != MAILBOX_SUCCESS) {
        status = PSA_INTER_CORE_COMM_ERR;
    }

    osMutexRelease(ns_lock_id);

    return status;
}

void psa_close(psa_handle_t handle)
{
    struct client_call_params_t params = { 0 };
    mailbox_msg_handle_t msg_handle;
    int32_t reply;

    params.handle = handle;

    osMutexAcquire(ns_lock_id, osWaitForever);

    msg_handle = mailbox_tx_client_call_req(MAILBOX_PSA_CLOSE, &params,
                                            NON_SECURE_CLIENT_ID);
    if (msg_handle < 0) {
        osMutexRelease(ns_lock_id);
        return;
    }

    mailbox_wait_reply(msg_handle);

    (void)mailbox_rx_client_call_reply(msg_handle, &reply);

    osMutexRelease(ns_lock_id);
}

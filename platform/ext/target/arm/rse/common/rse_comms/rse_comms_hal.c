/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_hal.h"

#include "rse_comms.h"
#include "rse_comms_queue.h"
#include "mhu.h"
#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_log_unpriv.h"
#include "tfm_pools.h"
#include "rse_comms_protocol.h"
#include <string.h>

/* Declared statically to avoid using huge amounts of stack space. Maybe revisit
 * if functions not being reentrant becomes a problem.
 */
static __ALIGNED(4) struct serialized_psa_msg_t msg;
static __ALIGNED(4) struct serialized_psa_reply_t reply;

TFM_POOL_DECLARE(req_pool, sizeof(struct client_request_t),
                 RSE_COMMS_MAX_CONCURRENT_REQ);

static enum tfm_plat_err_t initialize_mhu(void)
{
    enum mhu_error_t err;

    err = mhu_init_sender(&MHU_RSE_TO_AP_MONITOR_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] RSE to AP_MONITOR MHU driver init failed: %i\n",
            err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = mhu_init_receiver(&MHU_AP_MONITOR_TO_RSE_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] AP_MONITOR to RSE MHU driver init failed: %i\n",
            err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

#ifdef MHU_AP_NS_TO_RSE_DEV
    err = mhu_init_sender(&MHU_RSE_TO_AP_NS_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] RSE to AP_NS MHU driver init failed: %i\n", err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = mhu_init_receiver(&MHU_AP_NS_TO_RSE_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] AP_NS to RSE MHU driver init failed: %i\n", err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif /* MHU_AP_NS_TO_RSE_DEV */

#ifdef MHU_RSE_TO_AP_S_DEV
    err = mhu_init_sender(&MHU_RSE_TO_AP_S_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] RSE to AP_S MHU driver init failed: %i\n", err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = mhu_init_receiver(&MHU_AP_S_TO_RSE_DEV);
    if (err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] AP_S to RSE MHU driver init failed: %i\n", err);
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif /* MHU_RSE_TO_AP_S_DEV */

    VERBOSE_UNPRIV_RAW("[COMMS] MHU driver initialized successfully.\n");
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_multi_core_hal_receive(void *mhu_receiver_dev,
                                               void *mhu_sender_dev,
                                               uint32_t source)
{
    enum mhu_error_t mhu_err;
    enum tfm_plat_err_t err;
    size_t msg_len = sizeof(msg);
    size_t reply_size;

    memset(&msg, 0, sizeof(msg));
    memset(&reply, 0, sizeof(reply));

    /* Receive complete message */
    mhu_err = mhu_receive_data(mhu_receiver_dev, (uint8_t *)&msg, &msg_len);

    /* Clear the pending interrupt for this MHU. This prevents the mailbox
     * interrupt handler from being called without the next request arriving
     * through the mailbox
     */
    NVIC_ClearPendingIRQ(source);

    if (mhu_err != MHU_ERR_NONE) {
        /* Can't respond, since we don't know anything about the message */
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    struct client_request_t *req = tfm_pool_alloc(req_pool);
    if (!req) {
        /* No free capacity, drop message */
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_err;
    }
    memset(req, 0, sizeof(struct client_request_t));

    /* Record the MHU sender device to be used for the reply */
    req->mhu_sender_dev = mhu_sender_dev;

    err = rse_protocol_deserialize_msg(req, &msg, msg_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        /* Deserialisation failed, drop message */
        goto out_return_err;
    }

    if (queue_enqueue(req) != 0) {
        /* No queue capacity, drop message */
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_err;
    }

    /* Message successfully received */
    return TFM_PLAT_ERR_SUCCESS;

out_return_err:
    /* Attempt to respond with a failure message */
    if (rse_protocol_serialize_error(req, &msg.header,
                                     PSA_ERROR_CONNECTION_BUSY,
                                     &reply, &reply_size)
        == TFM_PLAT_ERR_SUCCESS) {
        mhu_err = mhu_send_data(mhu_sender_dev, (uint8_t *)&reply, reply_size);
        if (mhu_err != MHU_ERR_NONE) {
            ERROR_UNPRIV_RAW("[COMMS] Cannot send failure message: %i\n", mhu_err);
        }
    }

    if (req) {
        tfm_pool_free(req_pool, req);
    }

    return err;
}

enum tfm_plat_err_t tfm_multi_core_hal_reply(struct client_request_t *req)
{
    enum tfm_plat_err_t err;
    enum mhu_error_t mhu_err;
    size_t reply_size;

    /* This function is called by the mailbox partition with Thread priority, so
     * MHU interrupts must be disabled to prevent concurrent accesses by
     * tfm_multi_core_hal_receive().
     */
    NVIC_DisableIRQ(MAILBOX_IRQ);

    if (!is_valid_chunk_data_in_pool(req_pool, (uint8_t *)req)) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out;
    }

    err = rse_protocol_serialize_reply(req, &reply, &reply_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        VERBOSE_UNPRIV_RAW("[COMMS] Serialize reply failed: %i\n", err);
        goto out_free_req;
    }

    mhu_err = mhu_send_data(req->mhu_sender_dev, (uint8_t *)&reply, reply_size);
    if (mhu_err != MHU_ERR_NONE) {
        VERBOSE_UNPRIV_RAW("[COMMS] MHU send failed: %i\n", mhu_err);
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_free_req;
    }

    VERBOSE_UNPRIV_RAW("[COMMS] Sent reply\n");

out_free_req:
    tfm_pool_free(req_pool, req);
out:
    NVIC_EnableIRQ(MAILBOX_IRQ);
    return err;
}

enum tfm_plat_err_t tfm_multi_core_hal_init(void)
{
    int32_t spm_err;

    spm_err = tfm_pool_init(req_pool, POOL_BUFFER_SIZE(req_pool),
                            sizeof(struct client_request_t),
                            RSE_COMMS_MAX_CONCURRENT_REQ);
    if (spm_err) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return initialize_mhu();
}

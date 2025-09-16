/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_comms_runtime_hal.h"

#include "rse_comms_queue.h"
#include "mhu.h"
#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "tfm_peripherals_def.h"
#include "tfm_log_unpriv.h"
#include "tfm_pools.h"
#include "config_tfm.h"
#include "rse_comms_defs.h"
#include "rse_comms_link_hal.h"
#include "rse_comms_client_request.h"
#include <string.h>

/* Declared statically to avoid using huge amounts of stack space. Maybe revisit
 * if functions not being reentrant becomes a problem.
 */
static __ALIGNED(4) uint8_t msg_buf[RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) +
                                    sizeof(struct serialized_psa_msg_t)];
static __ALIGNED(4) uint8_t reply_buf[RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true) +
                                      sizeof(struct serialized_psa_reply_t)];

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

static void populate_reply_header(enum rse_comms_packet_type_t packet_type,
                                  rse_comms_node_id_t sender, rse_comms_node_id_t receiver,
                                  uint8_t seq_num)
{
    struct rse_comms_packet_t *reply = (struct rse_comms_packet_t *)reply_buf;

    reply->header.metadata =
        SET_ALL_METADATA_FIELDS(packet_type, false, true, RSE_COMMS_PROTOCOL_VERSION);
    reply->header.sender_id = sender;
    reply->header.receiver_id = receiver;
    reply->header.seq_num = seq_num;
}

static void return_psa_error(struct client_request_t *req,
                             struct serialized_rse_comms_header_t *header, void *mhu_sender_dev,
                             rse_comms_node_id_t sender, rse_comms_node_id_t receiver,
                             uint8_t seq_num, uint16_t client_id)
{
    enum mhu_error_t mhu_err;
    enum tfm_plat_err_t err;
    size_t reply_size;
    struct rse_comms_packet_t *reply = (struct rse_comms_packet_t *)reply_buf;
    struct serialized_psa_reply_t *psa_reply;

    populate_reply_header(RSE_COMMS_PACKET_TYPE_REPLY, sender, receiver, seq_num);
    GET_RSE_COMMS_CLIENT_ID(reply, false) = client_id;
    GET_RSE_COMMS_APPLICATION_ID(reply, false) = 0;

    psa_reply = (struct serialized_psa_reply_t *)GET_RSE_COMMS_PAYLOAD_PTR(reply, false, true);

    /* Attempt to respond with a failure message */
    err = rse_protocol_serialize_error(req, header, PSA_ERROR_CONNECTION_BUSY, psa_reply,
                                       &reply_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        ERROR_UNPRIV_RAW("[COMMS] Cannot serialize failure message: %i\n", err);
        return;
    }

    mhu_err = mhu_send_data(mhu_sender_dev, (uint8_t *)reply,
                            reply_size + RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true));
    if (mhu_err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] Cannot send failure message: %i\n", mhu_err);
    }
}

static void return_protocol_error(uint16_t error, void *mhu_sender_dev, rse_comms_node_id_t sender,
                                  rse_comms_node_id_t receiver, uint8_t seq_num, uint16_t client_id)
{
    enum mhu_error_t mhu_err;
    struct rse_comms_packet_t *reply = (struct rse_comms_packet_t *)reply_buf;

    populate_reply_header(RSE_COMMS_PACKET_TYPE_REPLY, sender, receiver, seq_num);

    GET_RSE_COMMS_ERROR_REPLY_CLIENT_ID(reply) = client_id;
    GET_RSE_COMMS_ERROR_REPLY_PROTCOL_ERROR(reply) = error;

    mhu_err = mhu_send_data(mhu_sender_dev, (uint8_t *)reply, RSE_COMMS_PACKET_SIZE_ERROR_REPLY);
    if (mhu_err != MHU_ERR_NONE) {
        ERROR_UNPRIV_RAW("[COMMS] Cannot send failure message: %i\n", mhu_err);
    }
}

enum tfm_plat_err_t tfm_multi_core_hal_receive(void *mhu_receiver_dev,
                                               void *mhu_sender_dev,
                                               uint32_t source)
{
    enum mhu_error_t mhu_err;
    enum tfm_plat_err_t err;
    enum rse_comms_hal_error_t hal_err;
    size_t msg_len = sizeof(msg_buf);
    struct serialized_psa_msg_t *psa_msg;
    rse_comms_node_id_t my_node_id;
    struct rse_comms_packet_t *msg = (struct rse_comms_packet_t *)msg_buf;

    memset(msg_buf, 0, sizeof(msg_buf));
    memset(reply_buf, 0, sizeof(reply_buf));

    /* Receive complete message */
    mhu_err = mhu_receive_data(mhu_receiver_dev, (uint8_t *)msg, &msg_len);

    /* Clear the pending interrupt for this MHU. This prevents the mailbox
     * interrupt handler from being called without the next request arriving
     * through the mailbox
     */
    NVIC_ClearPendingIRQ(source);

    if (mhu_err != MHU_ERR_NONE) {
        /* Can't respond, since we don't know anything about the message */
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    hal_err = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        err = (enum tfm_plat_err_t)hal_err;
        goto out_return_protocol_error;
    }

    if (GET_METADATA_FIELD(PROTOCOL_VERSION, msg->header.metadata) != RSE_COMMS_PROTOCOL_VERSION) {
        ERROR_UNPRIV_RAW("[COMMS] Invalid protocol version, expected %d\n",
                         RSE_COMMS_PROTOCOL_VERSION);
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    if (msg->header.receiver_id != my_node_id) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    if (GET_METADATA_FIELD(PACKET_TYPE, msg->header.metadata) !=
        RSE_COMMS_PACKET_TYPE_MSG_NEEDS_REPLY) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    if (GET_METADATA_FIELD(USES_CRYPTOGRAPHY, msg->header.metadata)) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    if (!GET_METADATA_FIELD(USES_ID_EXTENSION, msg->header.metadata)) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    /*
     * TODO: Currently only support PSA messages.
     * We need to implement handler mode based on message application ID
     */
    if (GET_RSE_COMMS_APPLICATION_ID(msg, false) != 0) {
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }

    struct client_request_t *req = tfm_pool_alloc(req_pool);
    if (!req) {
        /* No free capacity, drop message */
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_protocol_error;
    }
    memset(req, 0, sizeof(struct client_request_t));

    req->seq_num = msg->header.seq_num;
    req->client_id = GET_RSE_COMMS_CLIENT_ID(msg, false);
    /* Record the MHU sender device to be used for the reply */
    req->mhu_sender_dev = mhu_sender_dev;
    req->remote_id = msg->header.sender_id;

    psa_msg = (struct serialized_psa_msg_t *)GET_RSE_COMMS_PAYLOAD_PTR(msg, false, true);

    err = rse_protocol_deserialize_msg(
        req, psa_msg, msg_len - RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        /* Deserialisation failed, drop message */
        goto out_return_psa_error;
    }

    if (queue_enqueue(req) != 0) {
        /* No queue capacity, drop message */
        err = TFM_PLAT_ERR_SYSTEM_ERR;
        goto out_return_psa_error;
    }

    /* Message successfully received */
    return TFM_PLAT_ERR_SUCCESS;

out_return_protocol_error:
    return_protocol_error(err, mhu_sender_dev, msg->header.sender_id, msg->header.receiver_id,
                          msg->header.seq_num, GET_RSE_COMMS_CLIENT_ID(msg, false));
    return err;
out_return_psa_error:
    /* Attempt to respond with a failure message */
    return_psa_error(req, &psa_msg->header, mhu_sender_dev, req->remote_id, msg->header.receiver_id,
                     req->seq_num, req->client_id);
    tfm_pool_free(req_pool, req);
    return err;
}

enum tfm_plat_err_t tfm_multi_core_hal_reply(struct client_request_t *req)
{
    enum tfm_plat_err_t err;
    enum mhu_error_t mhu_err;
    enum rse_comms_hal_error_t hal_err;
    rse_comms_node_id_t my_node_id;
    struct rse_comms_packet_t *reply = (struct rse_comms_packet_t *)reply_buf;
    struct serialized_psa_reply_t *psa_reply;
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

    hal_err = rse_comms_hal_get_my_node_id(&my_node_id);
    if (hal_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        err = (enum tfm_plat_err_t)hal_err;
        goto out_free_req;
    }

    populate_reply_header(RSE_COMMS_PACKET_TYPE_REPLY, req->remote_id, my_node_id, req->seq_num);
    GET_RSE_COMMS_CLIENT_ID(reply, false) = req->client_id;
    GET_RSE_COMMS_APPLICATION_ID(reply, false) = 0;

    psa_reply = (struct serialized_psa_reply_t *)GET_RSE_COMMS_PAYLOAD_PTR(reply, false, true);

    err = rse_protocol_serialize_reply(req, psa_reply, &reply_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        VERBOSE_UNPRIV_RAW("[COMMS] Serialize reply failed: %i\n", err);
        goto out_free_req;
    }

    mhu_err = mhu_send_data(req->mhu_sender_dev, (uint8_t *)reply,
                            reply_size + RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(false, true));
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

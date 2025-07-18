/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "rse_handshake.h"

#include "device_definition.h"
#include "mhu.h"
#include "tfm_plat_otp.h"
#include "rse_kmu_keys.h"
#include "rse_kmu_slot_ids.h"
#include "crypto.h"
#include "cc3xx_aes.h"
#include "cc3xx_rng.h"
#include "cmsis.h"
#include "dpa_hardened_word_copy.h"
#include "rse_comms.h"
#include "rse_get_rse_id.h"
#include "bl1_random.h"

#include <string.h>
#include <assert.h>

#define RSE_SERVER_ID            0
#define SESSION_KEY_IV_SIZE      32
#define SESSION_KEY_IV_WORD_SIZE 8
#define VHUK_SEED_SIZE           32
#define VHUK_SEED_WORD_SIZE      8

enum rse_handshake_msg_type {
    RSE_HANDSHAKE_SESSION_KEY_MSG,
    RSE_HANDSHAKE_SESSION_KEY_REPLY,
    RSE_HANDSHAKE_VHUK_MSG,
    RSE_HANDSHAKE_VHUK_REPLY,
    RSE_HANDSHAKE_ERROR_REPLY,
    RSE_HANDSHAKE_MAX_MSG = UINT32_MAX,
};

enum rse_handshake_crypt_type {
    RSE_HANDSHAKE_ENCRYPT_MESSAGE,
    RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE,
};

__PACKED_STRUCT rse_handshake_header {
    enum rse_handshake_msg_type type;
    uint32_t rse_id;
    uint32_t error;
    uint32_t ccm_iv[3];
};

__PACKED_STRUCT rse_handshake_trailer {
    uint32_t ccm_tag[4];
};

struct __attribute__((__packed__)) rse_handshake_msg {
    struct rse_handshake_header header;
    __PACKED_UNION {
        __PACKED_STRUCT {
            uint32_t session_key_iv[SESSION_KEY_IV_WORD_SIZE];
        } session_key_msg;
        __PACKED_STRUCT {
            uint32_t session_key_ivs[SESSION_KEY_IV_WORD_SIZE * RSE_AMOUNT];
        } session_key_reply;
        __PACKED_STRUCT {
            uint32_t vhuk_contribution[VHUK_SEED_WORD_SIZE];
        } vhuk_msg;
        __PACKED_STRUCT {
            uint32_t vhuk_contributions[VHUK_SEED_WORD_SIZE * RSE_AMOUNT];
        } vhuk_reply;
    } body;
    struct rse_handshake_trailer trailer;
};

/* Can use the same buffer for the msg and reply. Specify the buffer size to the largest possible message */
static __ALIGNED(4) uint8_t
    rse_comms_buf[RSE_COMMS_BUFFER_MINIMUM_SIZE + sizeof(struct rse_handshake_msg)];

static enum tfm_plat_err_t header_init(struct rse_handshake_msg *msg,
                                       enum rse_handshake_msg_type type)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t rse_id;

    msg->header.type = type;

    plat_err = rse_get_rse_id(&rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    msg->header.rse_id = rse_id;

    cc_err = bl1_random_generate_secure((uint8_t *)&msg->header.ccm_iv,
                                        sizeof(msg->header.ccm_iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t construct_session_key_msg(struct rse_handshake_msg *msg,
                                                     uint32_t *session_key_iv)
{
    enum tfm_plat_err_t plat_err;

    plat_err = header_init(msg, RSE_HANDSHAKE_SESSION_KEY_MSG);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    dpa_hardened_word_copy(msg->body.session_key_msg.session_key_iv,
                           session_key_iv, SESSION_KEY_IV_WORD_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t construct_vhuk_msg(struct rse_handshake_msg *msg,
                                              uint32_t *vhuk_seed)
{
    enum tfm_plat_err_t plat_err;

    plat_err = header_init(msg, RSE_HANDSHAKE_VHUK_MSG);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    dpa_hardened_word_copy(msg->body.vhuk_msg.vhuk_contribution,
                           vhuk_seed, VHUK_SEED_WORD_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t construct_session_key_reply(struct rse_handshake_msg *msg,
                                                       uint32_t *session_key_ivs)
{
    enum tfm_plat_err_t plat_err;

    plat_err = header_init(msg, RSE_HANDSHAKE_SESSION_KEY_REPLY);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    dpa_hardened_word_copy(msg->body.session_key_reply.session_key_ivs,
                           session_key_ivs, SESSION_KEY_IV_WORD_SIZE * RSE_AMOUNT);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t construct_vhuk_reply(struct rse_handshake_msg *msg,
                                                uint32_t *vhuk_seeds)
{
    enum tfm_plat_err_t plat_err;

    plat_err = header_init(msg, RSE_HANDSHAKE_VHUK_REPLY);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    dpa_hardened_word_copy(msg->body.vhuk_reply.vhuk_contributions,
                           vhuk_seeds, VHUK_SEED_WORD_SIZE * RSE_AMOUNT);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t construct_failure_reply(struct rse_handshake_msg *msg,
                                                   enum tfm_plat_err_t return_error)
{
    enum tfm_plat_err_t plat_err;

    plat_err = header_init(msg, RSE_HANDSHAKE_ERROR_REPLY);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    msg->header.error = return_error;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t rse_handshake_msg_crypt(cc3xx_aes_direction_t direction,
                                                   struct rse_handshake_msg *msg)
{
    cc3xx_err_t cc_err;

    cc_err = cc3xx_lowlevel_aes_init(direction, CC3XX_AES_MODE_CCM, RSE_KMU_SLOT_SESSION_KEY_0,
                                     NULL, CC3XX_AES_KEYSIZE_256,
                                     (uint32_t *)msg->header.ccm_iv, sizeof(msg->header.ccm_iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    cc3xx_lowlevel_aes_set_tag_len(sizeof(msg->trailer.ccm_tag));
    cc3xx_lowlevel_aes_set_data_len(sizeof(msg->body),
                                    sizeof(msg->header));

    cc3xx_lowlevel_aes_update_authed_data((uint8_t *)msg,
                                          sizeof(msg->header));

    cc3xx_lowlevel_aes_set_output_buffer((uint8_t*)&msg->body,
                                         sizeof(msg->body));

    cc_err = cc3xx_lowlevel_aes_update((uint8_t*)&msg->body,
                                       sizeof(msg->body));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    cc_err = cc3xx_lowlevel_aes_finish((uint32_t *)&msg->trailer.ccm_tag, NULL);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t calculate_session_key_client(uint32_t rse_id)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t session_key_iv[SESSION_KEY_IV_WORD_SIZE];
    struct rse_handshake_msg *rse_handshake_msg;
    struct rse_comms_packet_t *msg;
    size_t msg_size;
    struct rse_comms_reply_metadata_t reply_metadata;
    size_t payload_len;
    enum rse_comms_error_t comms_err;

    /* Calculate our session key */
    cc_err = bl1_random_generate_secure((uint8_t *)session_key_iv,
                                        SESSION_KEY_IV_SIZE);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    comms_err = rse_comms_init_msg(rse_comms_buf, sizeof(rse_comms_buf), RSE_SERVER_ID, 0, 0, true,
                                   false, (uint8_t **)&rse_handshake_msg, &payload_len, &msg,
                                   &msg_size, &reply_metadata);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    if (payload_len < sizeof(*rse_handshake_msg)) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_PAYLOAD_LENGTH;
    }

    /* Send our session key IV to the server */
    plat_err = construct_session_key_msg(rse_handshake_msg, session_key_iv);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    comms_err = rse_comms_send_msg(msg, msg_size, payload_len);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    do {
        comms_err = rse_comms_receive_reply(rse_comms_buf, sizeof(rse_comms_buf), reply_metadata,
                                            (uint8_t **)&rse_handshake_msg, &payload_len);
    } while (comms_err == RSE_COMMS_ERROR_NO_REPLY_AVAILABLE);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    if (payload_len < sizeof(*rse_handshake_msg)) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_REPLY;
    }

    if (rse_handshake_msg->header.type != RSE_HANDSHAKE_SESSION_KEY_REPLY) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_CLIENT_SESSION_INVALID_HEADER;
    }

    /* Finally construct the session key */
    plat_err =
        rse_setup_session_key((uint8_t *)rse_handshake_msg->body.session_key_reply.session_key_ivs,
                              SESSION_KEY_IV_SIZE * RSE_AMOUNT);

    return plat_err;
}

static enum tfm_plat_err_t exchange_vhuk_seeds_client(uint32_t rse_id, uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t vhuk_seed[VHUK_SEED_WORD_SIZE];
    struct rse_handshake_msg *rse_handshake_msg;
    struct rse_comms_packet_t *msg;
    size_t msg_size;
    struct rse_comms_reply_metadata_t reply_metadata;
    size_t payload_len;
    enum rse_comms_error_t comms_err;

    /* Calculate our VHUK contribution key */
    cc_err = bl1_random_generate_secure((uint8_t *)vhuk_seed, VHUK_SEED_SIZE);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    comms_err = rse_comms_init_msg(rse_comms_buf, sizeof(rse_comms_buf), RSE_SERVER_ID, 0, 0, true,
                                   false, (uint8_t **)&rse_handshake_msg, &payload_len, &msg,
                                   &msg_size, &reply_metadata);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    if (payload_len < sizeof(*rse_handshake_msg)) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_PAYLOAD_LENGTH;
    }

    /* Send our VHUK contribution to the server */
    plat_err = construct_vhuk_msg(rse_handshake_msg, vhuk_seed);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_ENCRYPT, rse_handshake_msg);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    comms_err = rse_comms_send_msg(msg, msg_size, payload_len);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    do {
        comms_err = rse_comms_receive_reply(rse_comms_buf, sizeof(rse_comms_buf), reply_metadata,
                                            (uint8_t **)&rse_handshake_msg, &payload_len);
    } while (comms_err == RSE_COMMS_ERROR_NO_REPLY_AVAILABLE);
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    if (payload_len < sizeof(*rse_handshake_msg)) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_REPLY;
    }

    plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_DECRYPT, rse_handshake_msg);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (rse_handshake_msg->header.type != RSE_HANDSHAKE_VHUK_REPLY) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_CLIENT_VHUK_INVALID_HEADER;
    }

    dpa_hardened_word_copy(vhuk_seeds_buf, rse_handshake_msg->body.vhuk_reply.vhuk_contributions,
                           VHUK_SEED_WORD_SIZE * RSE_AMOUNT);
    /* Overwrite our VHUK contribution in the array, in case the sender has
     * overwritten it.
     */
    dpa_hardened_word_copy(vhuk_seeds_buf + VHUK_SEED_WORD_SIZE * rse_id,
                           vhuk_seed, VHUK_SEED_WORD_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t rse_handshake_client(uint32_t rse_id, uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;

    plat_err = calculate_session_key_client(rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = exchange_vhuk_seeds_client(rse_id, vhuk_seeds_buf);

    return plat_err;
}

static void server_reply_with_error(struct rse_comms_msg_metadata_t *msg_metadata,
                                    enum tfm_plat_err_t return_err)
{
    enum rse_comms_error_t comms_error;
    enum tfm_plat_err_t plat_err;
    struct rse_handshake_msg *rse_handshake_msg;
    struct rse_comms_packet_t *reply;
    size_t reply_size;
    size_t payload_len;

    comms_error = rse_comms_init_reply(rse_comms_buf, sizeof(rse_comms_buf), *msg_metadata,
                                       (uint8_t **)&rse_handshake_msg, &payload_len, &reply,
                                       &reply_size);
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        NONFATAL_ERR(comms_error);
        return;
    }

    if (payload_len < sizeof(*rse_handshake_msg)) {
        NONFATAL_ERR(TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_PAYLOAD_LENGTH);
        return;
    }

    plat_err = construct_failure_reply(rse_handshake_msg, return_err);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        NONFATAL_ERR(plat_err);
        return;
    }

    comms_error = rse_comms_send_reply(reply, reply_size, sizeof(*rse_handshake_msg));
    if (comms_error != RSE_COMMS_ERROR_SUCCESS) {
        NONFATAL_ERR(comms_error);
        return;
    }
}

static enum tfm_plat_err_t calculate_session_key_server(void)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t idx;
    uint32_t session_key_ivs[SESSION_KEY_IV_WORD_SIZE * RSE_AMOUNT];
    struct rse_handshake_msg *rse_handshake_msg;
    struct rse_comms_packet_t *reply;
    size_t reply_size;
    struct rse_comms_msg_metadata_t msg_metadata[RSE_AMOUNT];
    size_t payload_len;
    enum rse_comms_error_t comms_err;
    uint16_t client_id;

    /* Calculate the session key for RSE 0 */
    cc_err = bl1_random_generate_secure((uint8_t *)session_key_ivs,
                                        SESSION_KEY_IV_SIZE);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    /* Receive all the other session keys */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        do {
            comms_err = rse_comms_receive_msg(rse_comms_buf, sizeof(rse_comms_buf), idx, false, 0,
                                              &client_id, (uint8_t **)&rse_handshake_msg,
                                              &payload_len, &msg_metadata[idx]);
        } while (comms_err == RSE_COMMS_ERROR_NO_MSG_AVAILABLE);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return (enum tfm_plat_err_t)comms_err;
        }

        if (payload_len < sizeof(*rse_handshake_msg)) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_MESSAGE;
            goto reply_with_error;
        }

        if (rse_handshake_msg->header.type != RSE_HANDSHAKE_SESSION_KEY_MSG) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_SERVER_SESSION_INVALID_HEADER;
            goto reply_with_error;
        }

        dpa_hardened_word_copy(session_key_ivs + (SESSION_KEY_IV_WORD_SIZE * idx),
                               rse_handshake_msg->body.session_key_msg.session_key_iv,
                               SESSION_KEY_IV_WORD_SIZE);
    }

    /* Send the session key reply to all other RSEes */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        comms_err = rse_comms_init_reply(rse_comms_buf, sizeof(rse_comms_buf), msg_metadata[idx],
                                         (uint8_t **)&rse_handshake_msg, &payload_len, &reply,
                                         &reply_size);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            plat_err = (enum tfm_plat_err_t)comms_err;
            goto reply_with_error;
        }

        if (payload_len < sizeof(*rse_handshake_msg)) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_PAYLOAD_LENGTH;
            goto reply_with_error;
        }

        memset(rse_handshake_msg, 0, sizeof(*rse_handshake_msg));
        plat_err = construct_session_key_reply(rse_handshake_msg, session_key_ivs);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            goto reply_with_error;
        }

        comms_err = rse_comms_send_reply(reply, reply_size, sizeof(*rse_handshake_msg));
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return (enum tfm_plat_err_t)comms_err;
        }
    }

    /* Finally derive our own key */
    return rse_setup_session_key((uint8_t *)session_key_ivs, sizeof(session_key_ivs));

reply_with_error:
    /* Ignore failures when attempting to reply with error as we have
     * failed at this point anyway */
    server_reply_with_error(&msg_metadata[idx], plat_err);
    return plat_err;
}

static enum tfm_plat_err_t exchange_vhuk_seeds_server(uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;
    uint32_t idx;
    struct rse_handshake_msg *rse_handshake_msg;
    struct rse_comms_packet_t *reply;
    size_t reply_size;
    struct rse_comms_msg_metadata_t msg_metadata[RSE_AMOUNT];
    size_t payload_len;
    enum rse_comms_error_t comms_err;
    uint16_t client_id;

    /* Receive all the other vhuk seeds */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        do {
            comms_err = rse_comms_receive_msg(rse_comms_buf, sizeof(rse_comms_buf), idx, false, 0,
                                              &client_id, (uint8_t **)&rse_handshake_msg,
                                              &payload_len, &msg_metadata[idx]);
        } while (comms_err == RSE_COMMS_ERROR_NO_MSG_AVAILABLE);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return (enum tfm_plat_err_t)comms_err;
        }

        if (payload_len < sizeof(*rse_handshake_msg)) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_MESSAGE;
            goto reply_with_error;
        }

        plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_DECRYPT, rse_handshake_msg);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            goto reply_with_error;
        }

        if (rse_handshake_msg->header.type != RSE_HANDSHAKE_VHUK_MSG) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_SERVER_SESSION_INVALID_HEADER;
            goto reply_with_error;
        }

        dpa_hardened_word_copy(vhuk_seeds_buf + (SESSION_KEY_IV_WORD_SIZE * idx),
                               rse_handshake_msg->body.vhuk_msg.vhuk_contribution,
                               VHUK_SEED_WORD_SIZE);
    }

    /* Send the VUHK reply to all other RSEes */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        comms_err = rse_comms_init_reply(rse_comms_buf, sizeof(rse_comms_buf), msg_metadata[idx],
                                         (uint8_t **)&rse_handshake_msg, &payload_len, &reply,
                                         &reply_size);
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            plat_err = (enum tfm_plat_err_t)comms_err;
            goto reply_with_error;
        }

        if (payload_len < sizeof(*rse_handshake_msg)) {
            plat_err = TFM_PLAT_ERR_RSE_HANDSHAKE_INVALID_PAYLOAD_LENGTH;
            goto reply_with_error;
        }

        memset(rse_handshake_msg, 0, sizeof(*rse_handshake_msg));
        plat_err = construct_vhuk_reply(rse_handshake_msg, vhuk_seeds_buf);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            goto reply_with_error;
        }

        plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_ENCRYPT, rse_handshake_msg);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            goto reply_with_error;
        }

        comms_err = rse_comms_send_reply(reply, reply_size, sizeof(*rse_handshake_msg));
        if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
            return (enum tfm_plat_err_t)comms_err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;

reply_with_error:
    /* Ignore failures when attempting to reply with error as we have
     * failed at this point anyway */
    server_reply_with_error(&msg_metadata[idx], plat_err);
    return plat_err;
}

static enum tfm_plat_err_t rse_handshake_server(uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;

    plat_err = calculate_session_key_server();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = exchange_vhuk_seeds_server(vhuk_seeds_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_handshake(uint32_t *vhuk_seeds_buf)
{
    uint32_t rse_id;
    enum tfm_plat_err_t plat_err;
    enum rse_comms_error_t comms_err;

    plat_err = rse_get_rse_id(&rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    comms_err = rse_comms_init();
    if (comms_err != RSE_COMMS_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)comms_err;
    }

    if (rse_id == RSE_SERVER_ID) {
#if RSE_SERVER_ID != 0
        dpa_hardened_word_copy(vhuk_seeds_buf + VHUK_SEED_WORD_SIZE * rse_id,
                               vhuk_seeds_buf, VHUK_SEED_WORD_SIZE);
#endif /* RSE_SERVER_ID != 0 */
        return rse_handshake_server(vhuk_seeds_buf);
    } else {
        return rse_handshake_client(rse_id, vhuk_seeds_buf);
    }
}

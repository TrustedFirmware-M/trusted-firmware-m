/*
 * Copyright (c) 2023-2024 Arm Limited. All rights reserved.
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

#include <string.h>

#define RSE_SERVER_ID            0
#define SESSION_KEY_IV_SIZE      32
#define SESSION_KEY_IV_WORD_SIZE 8
#define VHUK_SEED_SIZE           32
#define VHUK_SEED_WORD_SIZE      8

uint32_t sending_mhu[RSE_AMOUNT];
uint32_t receiving_mhu[RSE_AMOUNT];

enum rse_handshake_msg_type {
    RSE_HANDSHAKE_SESSION_KEY_MSG,
    RSE_HANDSHAKE_SESSION_KEY_REPLY,
    RSE_HANDSHAKE_VHUK_MSG,
    RSE_HANDSHAKE_VHUK_REPLY,
    RSE_HANDSHAKE_MAX_MSG = UINT32_MAX,
};

enum rse_handshake_crypt_type {
    RSE_HANDSHAKE_ENCRYPT_MESSAGE,
    RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE,
};

__PACKED_STRUCT rse_handshake_header {
    enum rse_handshake_msg_type type;
    uint32_t rse_id;
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

static enum tfm_plat_err_t header_init(struct rse_handshake_msg *msg,
                                       enum rse_handshake_msg_type type)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;

    msg->header.type = type;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_ID,
                                 sizeof(msg->header.rse_id),
                                 (uint8_t*)&msg->header.rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    cc_err = cc3xx_lowlevel_rng_get_random((uint8_t *)&msg->header.ccm_iv,
                                           sizeof(msg->header.ccm_iv),
                                           CC3XX_RNG_DRBG);
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

static enum tfm_plat_err_t rse_handshake_msg_send(void *mhu_sender_dev,
                                                  struct rse_handshake_msg *msg,
                                                  enum rse_handshake_crypt_type crypt)
{
    enum tfm_plat_err_t plat_err;
    enum mhu_error_t mhu_err;

    mhu_err = mhu_init_sender(mhu_sender_dev);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    if (crypt == RSE_HANDSHAKE_ENCRYPT_MESSAGE) {
        plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_ENCRYPT, msg);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    mhu_err = mhu_send_data(mhu_sender_dev,
                            (uint8_t *)msg,
                            sizeof(struct rse_handshake_msg));
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t rse_handshake_msg_receive(void *mhu_receiver_dev,
                                                     struct rse_handshake_msg *msg,
                                                     enum rse_handshake_crypt_type crypt)
{
    enum tfm_plat_err_t plat_err;
    enum mhu_error_t mhu_err;
    size_t size;

    mhu_err = mhu_init_receiver(mhu_receiver_dev);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    mhu_err = mhu_wait_data(mhu_receiver_dev);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    size = sizeof(struct rse_handshake_msg);
    mhu_err = mhu_receive_data(mhu_receiver_dev, (uint8_t*)msg, &size);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    if (crypt == RSE_HANDSHAKE_ENCRYPT_MESSAGE) {
        plat_err = rse_handshake_msg_crypt(CC3XX_AES_DIRECTION_DECRYPT, msg);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t calculate_session_key_client(uint32_t rse_id)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t session_key_iv[SESSION_KEY_IV_WORD_SIZE];
    struct rse_handshake_msg msg;

    /* Calculate our session key */
    cc_err = cc3xx_lowlevel_rng_get_random((uint8_t *)session_key_iv,
                                           SESSION_KEY_IV_SIZE,
                                           CC3XX_RNG_DRBG);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    /* Send our session key IV to the server */
    plat_err = construct_session_key_msg(&msg, session_key_iv);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = rse_handshake_msg_send(&MHU_RSE_TO_RSE_SENDER_DEVS[sending_mhu[RSE_SERVER_ID]],
                                      &msg, RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Receive back the session key IVs */
    plat_err = rse_handshake_msg_receive(&MHU_RSE_TO_RSE_RECEIVER_DEVS[receiving_mhu[RSE_SERVER_ID]],
                                         &msg, RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (msg.header.type != RSE_HANDSHAKE_SESSION_KEY_REPLY) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_CLIENT_SESSION_INVALID_HEADER;
    }

    /* Finally construct the session key */
    plat_err = rse_setup_session_key((uint8_t *)&msg.body.session_key_reply.session_key_ivs,
                                      SESSION_KEY_IV_SIZE * RSE_AMOUNT);

    return plat_err;
}

static enum tfm_plat_err_t exchange_vhuk_seeds_client(uint32_t rse_id, uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t vhuk_seed[VHUK_SEED_WORD_SIZE];
    struct rse_handshake_msg msg;

    /* Calculate our VHUK contribution key */
    cc_err = cc3xx_lowlevel_rng_get_random((uint8_t *)vhuk_seed,
                                           VHUK_SEED_SIZE,
                                           CC3XX_RNG_DRBG);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    /* Send our VHUK contribution to the server */
    plat_err = construct_vhuk_msg(&msg, vhuk_seed);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = rse_handshake_msg_send(&MHU_RSE_TO_RSE_SENDER_DEVS[sending_mhu[RSE_SERVER_ID]],
                                      &msg, RSE_HANDSHAKE_ENCRYPT_MESSAGE);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Receive back the VHUK contributions */
    plat_err = rse_handshake_msg_receive(&MHU_RSE_TO_RSE_RECEIVER_DEVS[receiving_mhu[RSE_SERVER_ID]],
                                         &msg, RSE_HANDSHAKE_ENCRYPT_MESSAGE);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (msg.header.type != RSE_HANDSHAKE_VHUK_REPLY) {
        return TFM_PLAT_ERR_RSE_HANDSHAKE_CLIENT_VHUK_INVALID_HEADER;
    }

    dpa_hardened_word_copy(vhuk_seeds_buf, msg.body.vhuk_reply.vhuk_contributions,
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

static enum tfm_plat_err_t calculate_session_key_server()
{
    enum tfm_plat_err_t plat_err;
    cc3xx_err_t cc_err;
    uint32_t idx;
    uint32_t session_key_ivs[SESSION_KEY_IV_WORD_SIZE * RSE_AMOUNT];
    struct rse_handshake_msg msg;

    /* Calculate the session key for RSE 0 */
    cc_err = cc3xx_lowlevel_rng_get_random((uint8_t *)session_key_ivs,
                                           SESSION_KEY_IV_SIZE,
                                           CC3XX_RNG_DRBG);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return cc_err;
    }

    /* Receive all the other session keys */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        memset(&msg, 0, sizeof(msg));
        plat_err = rse_handshake_msg_receive(&MHU_RSE_TO_RSE_RECEIVER_DEVS[receiving_mhu[idx]],
                                             &msg, RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        if (msg.header.type != RSE_HANDSHAKE_SESSION_KEY_MSG) {
            return TFM_PLAT_ERR_RSE_HANDSHAKE_SERVER_SESSION_INVALID_HEADER;
        }

        dpa_hardened_word_copy(session_key_ivs + (SESSION_KEY_IV_WORD_SIZE * idx),
                               msg.body.session_key_msg.session_key_iv,
                               SESSION_KEY_IV_WORD_SIZE);
    }

    /* Construct the reply */
    memset(&msg, 0, sizeof(msg));
    plat_err = construct_session_key_reply(&msg, session_key_ivs);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Send the session key reply to all other RSEes */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        plat_err = rse_handshake_msg_send(&MHU_RSE_TO_RSE_SENDER_DEVS[sending_mhu[idx]],
                                          &msg, RSE_HANDSHAKE_DONT_ENCRYPT_MESSAGE);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    /* Finally derive our own key */
    plat_err = rse_setup_session_key((uint8_t *)session_key_ivs, sizeof(session_key_ivs));

    return plat_err;
}

static enum tfm_plat_err_t exchange_vhuk_seeds_server(uint32_t *vhuk_seeds_buf)
{
    enum tfm_plat_err_t plat_err;
    uint32_t idx;
    struct rse_handshake_msg msg;

    /* Receive all the other vhuk seeds */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        memset(&msg, 0, sizeof(msg));
        plat_err = rse_handshake_msg_receive(&MHU_RSE_TO_RSE_RECEIVER_DEVS[receiving_mhu[idx]],
                                        &msg, RSE_HANDSHAKE_ENCRYPT_MESSAGE);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        if (msg.header.type != RSE_HANDSHAKE_VHUK_MSG) {
            return TFM_PLAT_ERR_RSE_HANDSHAKE_SERVER_VHUK_INVALID_HEADER;
        }

        dpa_hardened_word_copy(vhuk_seeds_buf + (SESSION_KEY_IV_WORD_SIZE * idx),
                               msg.body.vhuk_msg.vhuk_contribution,
                               VHUK_SEED_WORD_SIZE);
    }

    /* Construct the reply */
    memset(&msg, 0, sizeof(msg));
    plat_err = construct_vhuk_reply(&msg, vhuk_seeds_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Send the VUHK reply to all other RSEes */
    for (idx = 0; idx < RSE_AMOUNT; idx++) {
        if (idx == RSE_SERVER_ID) {
            continue;
        }

        plat_err = rse_handshake_msg_send(&MHU_RSE_TO_RSE_SENDER_DEVS[sending_mhu[idx]],
                                          &msg, RSE_HANDSHAKE_ENCRYPT_MESSAGE);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
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
#ifndef RSE_OTP_HAS_ROUTING_TABLES
    /* The handshake can't be supported without routing tables in OTP */
    return TFM_PLAT_ERR_UNSUPPORTED;
#else
    uint32_t rse_id;
    enum tfm_plat_err_t plat_err;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_SENDER_ROUTING_TABLE,
                                 sizeof(sending_mhu), (uint8_t *)sending_mhu);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_RECEIVER_ROUTING_TABLE,
                                 sizeof(receiving_mhu), (uint8_t *)receiving_mhu);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_ID, sizeof(rse_id),
                                 (uint8_t*)&rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
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
#endif /* RSE_OTP_HAS_ROUTING_TABLES */
}

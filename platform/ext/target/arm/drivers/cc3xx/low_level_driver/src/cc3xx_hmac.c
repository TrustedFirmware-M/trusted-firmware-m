/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "cc3xx_hash.h"
#include "cc3xx_hmac.h"
#include "cc3xx_stdlib.h"

#define IPAD_PATTERN (0x36363636UL)
#define OPAD_PATTERN (0x5c5c5c5cUL)

cc3xx_err_t cc3xx_lowlevel_hmac_compute(
    size_t tag_len,
    const uint8_t *key,
    size_t key_size,
    cc3xx_hash_alg_t alg,
    const uint8_t *data,
    size_t data_length,
    uint32_t *tag,
    size_t tag_size,
    size_t *tag_length)
{
    cc3xx_err_t err;
    /* Local scratch buffers to hold intermediate values */
    uint32_t block[CC3XX_HMAC_BLOCK_SIZE / sizeof(uint32_t)] = {0};
    uint32_t h_out[CC3XX_HASH_LENGTH(alg) / sizeof(uint32_t)];

    *tag_length = 0;

    assert(tag_size >= tag_len);
    assert(tag_len <= CC3XX_HASH_LENGTH(alg));

    if (key_size > CC3XX_HMAC_BLOCK_SIZE) {
        err = cc3xx_lowlevel_hash_init(alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* hash the key to L bytes */
        err = cc3xx_lowlevel_hash_update(key, key_size);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }

        cc3xx_lowlevel_hash_finish(block, CC3XX_HASH_LENGTH(alg));
    } else if (key_size) {
        assert((key_size & 0b11) == 0);
        cc3xx_dpa_hardened_word_copy(block, (uint32_t *)key, key_size / sizeof(uint32_t));
    }

    /* H(K ^ ipad) */
    err = cc3xx_lowlevel_hash_init(alg);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_set_xor_input(IPAD_PATTERN);
    err = cc3xx_lowlevel_hash_update((uint8_t *)block, CC3XX_HMAC_BLOCK_SIZE);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    /* H(K ^ ipad | data) */
    if (data_length > 0) {
        cc3xx_lowlevel_hash_reset_xor_input();
        err = cc3xx_lowlevel_hash_update(data, data_length);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }
    }

    /* Produce H(K ^ ipad | data) */
    cc3xx_lowlevel_hash_finish(h_out, CC3XX_HASH_LENGTH(alg));

    /* H( K ^ opad | H(K ^ ipad | data) ) */
    err = cc3xx_lowlevel_hash_init(alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_hash_set_xor_input(OPAD_PATTERN);
    err = cc3xx_lowlevel_hash_update((uint8_t *)block, CC3XX_HMAC_BLOCK_SIZE);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_reset_xor_input();
    err = cc3xx_lowlevel_hash_update((uint8_t *)h_out, CC3XX_HASH_LENGTH(alg));
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    /* Produce H( K ^ opad | H(K ^ ipad | data) ) */
    cc3xx_lowlevel_hash_finish(h_out, CC3XX_HASH_LENGTH(alg));

out:
    if (err == CC3XX_ERR_SUCCESS) {
        cc3xx_dpa_hardened_word_copy(tag, h_out, tag_len / sizeof(uint32_t));
        if (tag_len % sizeof(uint32_t)) {
            memcpy(&(((uint32_t *)tag)[tag_len / sizeof(uint32_t)]),
                &h_out[tag_len / sizeof(uint32_t)], tag_len % sizeof(uint32_t));
        }
        *tag_length = tag_len;
    }
    cc3xx_lowlevel_hash_uninit();
    cc3xx_secure_erase_buffer(block, CC3XX_HMAC_BLOCK_SIZE / sizeof(uint32_t));
    cc3xx_secure_erase_buffer(h_out, CC3XX_HASH_LENGTH(alg) / sizeof(uint32_t));
    return err;
}

cc3xx_err_t cc3xx_lowlevel_hmac_set_key(
    struct cc3xx_hmac_state_t *state,
    const uint8_t *key,
    size_t key_size,
    cc3xx_hash_alg_t alg)
{
    cc3xx_err_t err;

    memset(state->key, 0, sizeof(state->key));

    if (key_size > CC3XX_HMAC_BLOCK_SIZE) {
        err = cc3xx_lowlevel_hash_init(alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* hash the key to L bytes */
        err = cc3xx_lowlevel_hash_update(key, key_size);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }

        cc3xx_lowlevel_hash_finish(state->key, CC3XX_HASH_LENGTH(alg));
    } else if (key_size) {
        assert((key_size & 0b11) == 0);
        cc3xx_dpa_hardened_word_copy(state->key, (uint32_t *)key, key_size / sizeof(uint32_t));
    }

    /* H(K ^ ipad) */
    err = cc3xx_lowlevel_hash_init(alg);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_set_xor_input(IPAD_PATTERN);
    err = cc3xx_lowlevel_hash_update((uint8_t *)state->key, sizeof(state->key));
    cc3xx_lowlevel_hash_reset_xor_input();

out:
    if (err == CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_hash_get_state(&state->hash);
        state->alg = alg;
        state->tag_len = CC3XX_HASH_LENGTH(alg);
    }
    cc3xx_lowlevel_hash_uninit();
    return err;
}

void cc3xx_lowlevel_hmac_set_tag_length(
    struct cc3xx_hmac_state_t *state,
    size_t tag_len)
{
    state->tag_len = (uint8_t)tag_len;
}

cc3xx_err_t cc3xx_lowlevel_hmac_update(
    struct cc3xx_hmac_state_t *state,
    const uint8_t *data,
    size_t data_length)
{
    cc3xx_err_t err;

    cc3xx_lowlevel_hash_set_state(&state->hash);

    /* H(K ^ ipad | data)*/
    err = cc3xx_lowlevel_hash_update(data, data_length);

    if (err == CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_hash_get_state(&state->hash);
    }
    cc3xx_lowlevel_hash_uninit();
    return err;
}

cc3xx_err_t cc3xx_lowlevel_hmac_finish(
    struct cc3xx_hmac_state_t *state,
    uint32_t *tag,
    size_t tag_size,
    size_t *tag_len)
{
    uint32_t h_out[CC3XX_HASH_LENGTH(state->alg) / sizeof(uint32_t)];
    cc3xx_err_t err;

    assert(tag_size >= state->tag_len);

    cc3xx_lowlevel_hash_set_state(&state->hash);

    /* Produce H(K ^ ipad | data) */
    cc3xx_lowlevel_hash_finish(h_out, sizeof(h_out));

    /* H( K ^ opad | H(K ^ ipad | data)) */
    err = cc3xx_lowlevel_hash_init(state->alg);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_set_xor_input(OPAD_PATTERN);
    err = cc3xx_lowlevel_hash_update((uint8_t *)state->key, sizeof(state->key));
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_reset_xor_input();
    err = cc3xx_lowlevel_hash_update((const uint8_t *)h_out, sizeof(h_out));
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    cc3xx_lowlevel_hash_finish(h_out, sizeof(h_out));

    if (tag_len != NULL) {
        *tag_len = state->tag_len;
    }

out:
    if (err == CC3XX_ERR_SUCCESS) {
        cc3xx_dpa_hardened_word_copy(tag, h_out, state->tag_len / sizeof(uint32_t));
        if (state->tag_len % sizeof(uint32_t)) {
            memcpy(&(((uint32_t *)tag)[state->tag_len / sizeof(uint32_t)]),
                &h_out[state->tag_len / sizeof(uint32_t)], state->tag_len % sizeof(uint32_t));
        }
        cc3xx_lowlevel_hash_get_state(&state->hash);
        cc3xx_secure_erase_buffer(h_out, CC3XX_HASH_LENGTH(state->alg) / sizeof(uint32_t));
    }
    cc3xx_lowlevel_hash_uninit();
    return err;
}

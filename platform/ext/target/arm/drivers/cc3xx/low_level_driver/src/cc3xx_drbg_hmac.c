/*
 * Copyright (c) 2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "cc3xx_stdlib.h"
#include "cc3xx_hmac.h"
#include "cc3xx_drbg_hmac.h"

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#define BITS_TO_BYTES(x) (((x) + 7)/8)
#define BYTES_TO_BITS(x) ((x)*8)

/**
 * @brief Update the state (K,V)
 *
 * @param hmac_inputs_num Number of inputs for the update operation, it can be zero
 * @param state A pointer to a state structure
 * @param hmac_inputs Inputs for the update operation, passed as an array of hmac_inputs_num pointers
 * @param hmac_inputs_len Lengths for the update operation, passed as an array of hmac_inputs_num values
 * @return cc3xx_err_t
 */
static cc3xx_err_t hmac_update(
    size_t hmac_inputs_num,
    struct cc3xx_drbg_hmac_state_t *state,
    const uint8_t **hmac_inputs, const size_t *hmac_inputs_len)
{
    const uint8_t byte0 = 0x00; const uint8_t byte1 = 0x01;
    cc3xx_err_t err;
    size_t idx;
    const cc3xx_hash_alg_t alg = CC3XX_HASH_ALG_SHA256;

    /* 1. K = HMAC(K, V || 0x00 || provided_data) */
    err = cc3xx_lowlevel_hmac_set_key(&state->h, (const uint8_t *)state->key_k, sizeof(state->key_k), alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, (const uint8_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, &byte0, sizeof(byte0));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    /* provided_data can be given into up to 3 chunks, starting from 0 index */
    for (idx = 0; idx < hmac_inputs_num && hmac_inputs_len[idx] != 0; idx++) {
        err = cc3xx_lowlevel_hmac_update(&state->h, hmac_inputs[idx], hmac_inputs_len[idx]);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    }

    err = cc3xx_lowlevel_hmac_finish(&state->h, state->key_k, sizeof(state->key_k), NULL);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* 2. V = HMAC(K, V) */
    err = cc3xx_lowlevel_hmac_set_key(&state->h, (const uint8_t *)state->key_k, sizeof(state->key_k), alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, (const uint8_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_finish(&state->h, state->block_v, sizeof(state->block_v), NULL);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* 3. If no provided_data has been passed, just return here */
    if (hmac_inputs_num == 0) {
        return err;
    }

    /* 4. K = HMAC(K, V || 0x01 || provided_data) */
    err = cc3xx_lowlevel_hmac_set_key(&state->h, (const uint8_t *)state->key_k, sizeof(state->key_k), alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, (const uint8_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, &byte1, sizeof(byte1));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    for (idx = 0; idx < hmac_inputs_num && hmac_inputs_len[idx] != 0; idx++) {
        err = cc3xx_lowlevel_hmac_update(&state->h, hmac_inputs[idx], hmac_inputs_len[idx]);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    }

    err = cc3xx_lowlevel_hmac_finish(&state->h, state->key_k, sizeof(state->key_k), NULL);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* 5. V = HMAC(K, V) */
    err = cc3xx_lowlevel_hmac_set_key(&state->h, (const uint8_t *)state->key_k, sizeof(state->key_k), alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_update(&state->h, (const uint8_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hmac_finish(&state->h, state->block_v, sizeof(state->block_v), NULL);

    /* return updated (K, V) state */
    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hmac_instantiate(
    struct cc3xx_drbg_hmac_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len)
{
    cc3xx_err_t err;

    /* Initialize the state */
    memset(state->block_v, 0x01, sizeof(state->block_v));
    memset(state->key_k, 0x00, sizeof(state->key_k));

    /* Prepare the seed material to be passed to update() */
    const uint8_t *seed[3] = {entropy, nonce, personalization};
    const size_t seed_len[3] = {entropy_len, nonce_len, personalization_len};

    err = hmac_update(3, state, seed, seed_len);

    state->reseed_counter = 1;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hmac_generate(
    struct cc3xx_drbg_hmac_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;
    size_t generated_bits = 0;
    const uint8_t *data[3] = {NULL};
    size_t data_len[3] = {0};
    size_t idx;
    size_t last_hmac_update_num = 0;
    const cc3xx_hash_alg_t alg = CC3XX_HASH_ALG_SHA256;
    /* Special handling of aligned requests into aligned buffer. This allows
     * HW with particular alignment requirements to directly generate
     * random numbers into its buffers without need for temporary buffers, i.e.
     * generating integer number of random words into word-aligned buffers
     */
    const bool request_is_word_aligned =
            ((uintptr_t)returned_bits & 0x3) == 0 && (BITS_TO_BYTES(len_bits) & 0x3) == 0;

    if (state->reseed_counter == UINT32_MAX) {
        /* When we reach 2^32 invocations we must reseed */
        return CC3XX_ERR_DRBG_RESEED_REQUIRED;
    }

    if (additional_input_len && additional_input != NULL) {
        data[0] = additional_input;
        data_len[0] = additional_input_len;
        err = hmac_update(1, state, data, data_len);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    }

    /* While len(temp) < requested_number_of_bits, as per spec */
    while (generated_bits < len_bits) {
        uint32_t temp[CC3XX_DRBG_HMAC_OUTLEN / sizeof(uint32_t)];
        size_t bytes_to_copy;

        /* V = HMAC(K, V) */
        err = cc3xx_lowlevel_hmac_set_key(&state->h,
                                 (const uint8_t *)state->key_k,
                                 sizeof(state->key_k),
                                 alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        err = cc3xx_lowlevel_hmac_update(&state->h, (const uint8_t *)state->block_v, sizeof(state->block_v));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        err = cc3xx_lowlevel_hmac_finish(&state->h, temp, CC3XX_DRBG_HMAC_OUTLEN, NULL);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        bytes_to_copy = len_bits - generated_bits < BYTES_TO_BITS(CC3XX_DRBG_HMAC_OUTLEN) ?
                        BITS_TO_BYTES(len_bits - generated_bits) : CC3XX_DRBG_HMAC_OUTLEN;

        if (request_is_word_aligned) {
            uint32_t *base_ptr = (uint32_t *)&returned_bits[BITS_TO_BYTES(generated_bits)];
            for (size_t i = 0; i < bytes_to_copy / sizeof(uint32_t); i++) {
                base_ptr[i] = temp[i];
            }
        } else {
            memcpy(&returned_bits[BITS_TO_BYTES(generated_bits)], temp, bytes_to_copy);
        }

        /* The increment in the generated bits always happens to the full 256 bits per generation */
        generated_bits += BYTES_TO_BITS(CC3XX_DRBG_HMAC_OUTLEN);

        memcpy(state->block_v, temp, CC3XX_DRBG_HMAC_OUTLEN);
    }

    /* We need to mask the last byte in case len_bits % 8 is different than 0 */
    if (len_bits % 8) {
        uint8_t mask = 0UL;
        for (idx = 0; idx < len_bits % 8; idx++) {
            mask |= 1UL << (8 - idx - 1);
        }

        returned_bits[BITS_TO_BYTES(len_bits) - 1] &= mask;
    }

    /* The update is done with no additional_input to update() */
    if (additional_input != NULL && additional_input_len != 0) {
        data[0] = additional_input;
        data_len[0] = additional_input_len;
        last_hmac_update_num = 1;
    }

    err = hmac_update(last_hmac_update_num, state, data, data_len);

    state->reseed_counter++;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hmac_reseed(
    struct cc3xx_drbg_hmac_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;

    /* The update is done with no personalization string update() */
    const uint8_t *data[3] = {entropy, additional_input, NULL};
    const size_t data_len[3] = {entropy_len, additional_input_len, 0};

    err = hmac_update(2, state, data, data_len);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    state->reseed_counter = 1;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hmac_uninit(struct cc3xx_drbg_hmac_state_t *state)
{
    cc3xx_secure_erase_buffer((uint32_t *)state, sizeof(struct cc3xx_drbg_hmac_state_t)/4);
    return CC3XX_ERR_SUCCESS;
}

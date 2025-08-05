/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "endian.h"
#include "cc3xx_hash.h"
#include "cc3xx_drbg_hash.h"
#include "cc3xx_pka.h"
#include "cc3xx_stdlib.h"

/**
 * @brief Ceiling of a / b
 */
#define CEIL(a, b) ((a) + (b) - 1)/(b)

/** \note Throughout the file sizeof(state_v) and sizeof(constant_c) are
 *        decreased by 1 byte because they have been defined with 1 byte
 *        more in the \ref struct cc3xx_drbg_hash_state_t to be 4 bytes
 *        aligned
 */

static void long_acc(uint8_t *acc, const uint8_t *val, size_t acc_size, size_t val_size)
{
    /* Need to convert BE -> LE -> BE again if PKA is configured for LE */
    cc3xx_pka_reg_id_t r0, r1;
    assert(acc_size == CC3XX_DRBG_HASH_SEEDLEN);

    /* Accumulation happen only on 440 bit accumulators */
    cc3xx_lowlevel_pka_init(CC3XX_DRBG_HASH_SEEDLEN);

    /* Allocate a register among those not in use, given configured size */
    r0 = cc3xx_lowlevel_pka_allocate_reg();

    /* Initialize the accumulator register with the current value of acc */
    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (const uint32_t *)acc, CC3XX_DRBG_HASH_SEEDLEN);

    /* Request another register for the value to accumulate */
    r1 = cc3xx_lowlevel_pka_allocate_reg();

    /* Write the value to accumulate into the register */
    cc3xx_lowlevel_pka_write_reg_swap_endian(r1, (const uint32_t *)val, val_size);

    /* Perform the actual operation */
    cc3xx_lowlevel_pka_add(r0, r1, r0);

    /* Read back the accumulator register */
    cc3xx_lowlevel_pka_read_reg_swap_endian(r0, (uint32_t *)acc, CC3XX_DRBG_HASH_SEEDLEN);

    /* Uninit the engine */
    cc3xx_lowlevel_pka_uninit();
}

/* Hardcode support for SHA-256 based HMAC only */
static const cc3xx_hash_alg_t alg = CC3XX_HASH_ALG_SHA256;

/**
 * @brief Hash derivation function as specified by NIST SP 800-90 Section 10.3.1
 *
 * @param hash_inputs_num Total number of the hash_inputs being passed to the update function
 * @param hash_inputs     An array of three buffer pointers that can be used in the derivation process
 * @param hash_inputs_len An array of three size_t values that contain the size of each buffer passed
 * @param out             Buffer containing the output of the derivation function
 * @param out_len_bits    Size in bits of the buffer containing the result of the derivation operation
 * @return cc3xx_err_t
 */
static cc3xx_err_t hash_df(
    size_t hash_inputs_num,
    const uint8_t **hash_inputs,
    const size_t *hash_inputs_len,
    uint8_t *out,
    size_t out_len_bits)
{
    /* The number of full SHA-256 hashes output (256 bit) that we need to cover the requested
     * output of out_len_bits = 440 bit, i.e. the CC3XX_DRBG_HASH_SEEDLEN
     */
    const size_t num_hash = 2;
    cc3xx_err_t err;
    uint8_t counter_out_len_bits[5] = {0x01, 0x00, 0x00, 0x01, 0xB8}; /* 0x01 || out_len_bits */
    size_t idx;
    size_t hash_input_idx;
    uint32_t temp[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];

    /* Number of bits to return must be fixed to 440 for the implementation, i.e. 0x1B8 */
    assert(out_len_bits == CC3XX_DRBG_HASH_SEEDLEN * 8);

    for (idx = 0; idx < num_hash; idx++) {

        err = cc3xx_lowlevel_hash_init(alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        err = cc3xx_lowlevel_hash_update(counter_out_len_bits, sizeof(counter_out_len_bits));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        for (hash_input_idx = 0; hash_input_idx < hash_inputs_num && hash_inputs_len[hash_input_idx] != 0; hash_input_idx++) {
            err = cc3xx_lowlevel_hash_update(hash_inputs[hash_input_idx], hash_inputs_len[hash_input_idx]);
            if (err != CC3XX_ERR_SUCCESS) {
                return err;
            }
        }

        cc3xx_lowlevel_hash_finish((idx != num_hash - 1) ? (uint32_t *)out : temp, SHA256_OUTPUT_SIZE);

        if (idx != num_hash - 1) {
            out += SHA256_OUTPUT_SIZE;
        }
        counter_out_len_bits[0]++;
    }

    memcpy(out, temp, CC3XX_DRBG_HASH_SEEDLEN - SHA256_OUTPUT_SIZE);

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hash_init(
    struct cc3xx_drbg_hash_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len)
{
    cc3xx_err_t err;
    uint8_t byte0 = 0x0;
    const uint8_t *data[3] = {entropy, nonce, personalization};
    size_t data_len[3] = {entropy_len, nonce_len, personalization_len};

    err = hash_df(3, data, data_len, state->value_v, CC3XX_DRBG_HASH_SEEDLEN * 8);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    data[0] = &byte0;
    data[1] = state->value_v;
    data_len[0] = sizeof(byte0);
    data_len[1] = sizeof(state->value_v) - 1;

    err = hash_df(2, data, data_len, state->constant_c, CC3XX_DRBG_HASH_SEEDLEN * 8);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    state->reseed_counter = 1;

    return err;
}

/**
 * @brief Hash based generation process as specified by NIST SP 800-90 Section 10.1.1.4
 *
 * @param block_v       block_v containing the seed to be used by the hashgen process
 * @param out_len_bits  Number of bits requested to be generated, byte aligned
 * @param returned_bits Buffer containing the bits generated using the hash based process
 * @return cc3xx_err_t
 */
static cc3xx_err_t hash_gen_process(uint8_t *block_v, size_t out_len_bits, uint8_t *returned_bits)
{
    cc3xx_err_t err;
    size_t idx;
    size_t remaining_bytes = (out_len_bits / 8) % SHA256_OUTPUT_SIZE;
    size_t gen_num_m = CEIL(out_len_bits, SHA256_OUTPUT_SIZE * 8); /* Number of hash generations */
    uint32_t data[(CC3XX_DRBG_HASH_SEEDLEN + 1) / sizeof(uint32_t)];
    uint32_t partial_last_block[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];

    /* Special handling of aligned requests into aligned buffer. This allows
     * HW with particular alignment requirements to directly generate
     * random numbers into its buffers without need for temporary buffers, i.e.
     * generating integer number of random words into word-aligned buffers
     */
    const bool request_is_word_aligned =
            !((uintptr_t) returned_bits & 0x3) && !((out_len_bits / 8) & 0x3);
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    size_t num_words_to_copy = sizeof(data) / sizeof(uint32_t);
    cc3xx_dpa_hardened_word_copy((uint32_t *)data, (uint32_t *)block_v, num_words_to_copy);
#else
    memcpy(data, block_v, CC3XX_DRBG_HASH_SEEDLEN);
#endif

    for (idx = 0; idx < gen_num_m; idx++) {
        const uint8_t byte1 = 0x1;
        uint32_t *p_output_buf = NULL;

        err = cc3xx_lowlevel_hash_init(alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        err = cc3xx_lowlevel_hash_update((uint8_t *)data, CC3XX_DRBG_HASH_SEEDLEN);
        if (err!= CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* We need to discriminate the case where the last generation is for a whole
            * block or a partial block
            */
        if ((idx == gen_num_m - 1) && (remaining_bytes > 0)) {
            p_output_buf = partial_last_block;
        } else {
            p_output_buf = (uint32_t *)returned_bits;
        }

        cc3xx_lowlevel_hash_finish(p_output_buf, SHA256_OUTPUT_SIZE);

        long_acc((uint8_t *)data, &byte1, CC3XX_DRBG_HASH_SEEDLEN, sizeof(byte1));

        returned_bits += SHA256_OUTPUT_SIZE;
    }

    returned_bits -= SHA256_OUTPUT_SIZE;

    if (remaining_bytes == 0) {
        goto finish;
    }

    if (request_is_word_aligned) {
        for (idx = 0; idx < remaining_bytes / sizeof(uint32_t); idx++) {
            ((uint32_t *) returned_bits)[idx] = partial_last_block[idx];
        }
    } else {
        memcpy(returned_bits, partial_last_block, remaining_bytes);
    }

finish:
    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hash_generate(
    struct cc3xx_drbg_hash_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;
    const uint8_t byte3 = 0x03;
    uint8_t reseed_counter[4];
    uint32_t hash_output_buffer[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];
    /* The reseed counter must be treated as a BE number, so use a local
     * buffer to format it as a big endian number for the long addition
     */
    uint32_t *p_reseed_counter = (uint32_t *) reseed_counter;

    if (state->reseed_counter == UINT32_MAX) {
        /* When we reach 2^32 invocations we must reseed */
        return CC3XX_ERR_DRBG_RESEED_REQUIRED;
    }

    /* The implementation constraints the output length to be byte aligned to
     * reduce complexity
     */
    assert(len_bits != 0);
    assert((len_bits % 8) == 0);

    if (additional_input_len && additional_input != NULL) {
        const uint8_t byte2 = 0x02;

        err = cc3xx_lowlevel_hash_init(alg);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        err = cc3xx_lowlevel_hash_update(&byte2, sizeof(byte2));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        err = cc3xx_lowlevel_hash_update(state->value_v, sizeof(state->value_v) - 1);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        err = cc3xx_lowlevel_hash_update(additional_input, additional_input_len);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        cc3xx_lowlevel_hash_finish(hash_output_buffer, SHA256_OUTPUT_SIZE);
        long_acc(state->value_v, (uint8_t *)hash_output_buffer,
                 sizeof(state->value_v) - 1, sizeof(hash_output_buffer));
    }

    err = hash_gen_process(state->value_v, len_bits, returned_bits);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    err = cc3xx_lowlevel_hash_init(alg);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hash_update(&byte3, sizeof(byte3));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
    err = cc3xx_lowlevel_hash_update(state->value_v, sizeof(state->value_v) - 1);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_hash_finish(hash_output_buffer, SHA256_OUTPUT_SIZE);

    /* V = V + H + C + reseed_counter */
    long_acc(state->value_v, (uint8_t *)hash_output_buffer,
             sizeof(state->value_v) - 1, sizeof(hash_output_buffer));
    long_acc(state->value_v, state->constant_c,
             sizeof(state->value_v) - 1, sizeof(state->constant_c) - 1);

    *p_reseed_counter = bswap_32(state->reseed_counter);
    long_acc(state->value_v, reseed_counter,
             sizeof(state->value_v) - 1, sizeof(reseed_counter));

    state->reseed_counter++;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hash_reseed(
    struct cc3xx_drbg_hash_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;
    const uint8_t byte0 = 0x0;
    /* temporary buffer for (byte1 || V). Note that hash_df does not work in-place */
    uint8_t temp[1 + sizeof(state->value_v) - 1] = {0x01};
    const uint8_t *data[3] = {temp, entropy, additional_input};
    size_t data_len[3] = {sizeof(temp), entropy_len, additional_input_len};

    /* temp concatenates 0x01 || V */
    memcpy(&temp[1], state->value_v, sizeof(state->value_v) - 1);

    err = hash_df(3, data, data_len, state->value_v, CC3XX_DRBG_HASH_SEEDLEN * 8);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    data[0] = &byte0;
    data[1] = state->value_v;
    data_len[0] = sizeof(byte0);
    data_len[1] = sizeof(state->value_v) - 1;

    err = hash_df(2, data, data_len, state->constant_c, CC3XX_DRBG_HASH_SEEDLEN * 8);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    state->reseed_counter = 1;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_hash_uninit(struct cc3xx_drbg_hash_state_t *state)
{
    cc3xx_secure_erase_buffer((uint32_t *)state, sizeof(struct cc3xx_drbg_hash_state_t)/4);
    return CC3XX_ERR_SUCCESS;
}

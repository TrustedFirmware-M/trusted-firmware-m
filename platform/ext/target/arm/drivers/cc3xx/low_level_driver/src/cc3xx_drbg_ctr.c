/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "endian.h"
#include "cc3xx_pka.h"
#include "cc3xx_drbg_ctr.h"
#include "cc3xx_rng.h"
#include "cc3xx_stdlib.h"

static void long_inc_int(uint32_t *acc, size_t acc_size, bool is_increment)
{
    const bool pka_initialized = cc3xx_lowlevel_pka_is_initialized();
    cc3xx_pka_reg_id_t r0;

    assert(acc_size == CC3XX_DRBG_CTR_BLOCKLEN);

    if (!pka_initialized) {
        /* Accumulation happen only on 128 bit accumulators */
        cc3xx_lowlevel_pka_init(CC3XX_DRBG_CTR_BLOCKLEN);
    }

    /* Allocate a register among those not in use, given configured size */
    r0 = cc3xx_lowlevel_pka_allocate_reg();

    /* Initialize the accumulator register with the current value of acc */
    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (const uint32_t *)acc, CC3XX_DRBG_CTR_BLOCKLEN);

    /* Perform the actual operation */
    if (is_increment) {
        cc3xx_lowlevel_pka_add_si(r0, 1, r0);
    } else {
        cc3xx_lowlevel_pka_sub_si(r0, 1, r0);
    }

    /* Read back the accumulator register */
    cc3xx_lowlevel_pka_read_reg_swap_endian(r0, acc, CC3XX_DRBG_CTR_BLOCKLEN);

    cc3xx_lowlevel_pka_free_reg(r0);

    if (!pka_initialized) {
        /* Uninit the engine */
        cc3xx_lowlevel_pka_uninit();
    }
}

static inline void long_inc(uint32_t *acc, size_t acc_size)
{
    long_inc_int(acc, acc_size, true);
}

static inline void long_dec(uint32_t *acc, size_t acc_size)
{
    long_inc_int(acc, acc_size, false);
}

/**
 * @brief Produces seedlen bits of data through the underlying block
 *        cipher (AES) set in CTR mode, and uses the produced data to update
 *        the values of (Key, V) to be used as a state
 *
 * @param state    A pointer to a state structure
 * @param data     provided data for the update process
 * @param data_len Length of the update operation
 *
 * @return cc3xx_err_t
 */
static cc3xx_err_t cc3xx_drbg_ctr_update(
    struct cc3xx_drbg_ctr_state_t *state,
    const uint8_t *data, const size_t data_len)
{
    cc3xx_err_t err;
    assert(data_len <= CC3XX_DRBG_CTR_SEEDLEN);

    long_inc((uint32_t *)state->block_v, sizeof(state->block_v));

    err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT,
                                  CC3XX_AES_MODE_CTR,
                                  CC3XX_AES_KEY_ID_USER_KEY,
                                  (const uint32_t *)state->key_k, CC3XX_AES_KEYSIZE_128,
                                  (const uint32_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_aes_set_output_buffer((uint8_t *)state->key_k, CC3XX_DRBG_CTR_SEEDLEN);

    err = cc3xx_lowlevel_aes_update(data, data_len);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* allow for the update() to happen on less than 256 bit of data */
    if (data_len < CC3XX_DRBG_CTR_SEEDLEN) {
        uint8_t all_zeros[CC3XX_DRBG_CTR_SEEDLEN - data_len];
        memset(all_zeros, 0, sizeof(all_zeros));
        err = cc3xx_lowlevel_aes_update(all_zeros, sizeof(all_zeros));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    }

    err = cc3xx_lowlevel_aes_finish(NULL, NULL);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_ctr_init(
    struct cc3xx_drbg_ctr_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *nonce, size_t nonce_len,
    const uint8_t *personalization, size_t personalization_len)
{
    cc3xx_err_t err;
    uint32_t personalized_entropy[CC3XX_DRBG_CTR_SEEDLEN_WORDS];
    uint8_t *seed_material = (uint8_t *)entropy;
    size_t idx;

    /* The entropy must be equal to 256 bit. The spec allows for a lower
     * amount of entropy to be passed during instantiation, then using a
     * derivation function at this point to reach 256 bit. But this implementation
     * focuses on lower complexity hence the derivation function is not used
     */
    assert(entropy_len == CC3XX_DRBG_CTR_SEEDLEN);

    /* This implementation does not use a derivation function, hence the nonce
     * is not used during the instantiation procedure
     */
    (void)nonce;
    (void)nonce_len;

    if (personalization != NULL) {

        /* If present and less than 256 bit, it's equivalent to be zero padded */
        assert(personalization_len <= CC3XX_DRBG_CTR_SEEDLEN);

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
        cc3xx_dpa_hardened_word_copy(personalized_entropy,
                                     (uint32_t *)entropy,
                                     CC3XX_DRBG_CTR_SEEDLEN_WORDS);
#else
        memcpy(personalized_entropy, entropy, CC3XX_DRBG_CTR_SEEDLEN);
#endif
        for (idx = 0; idx < personalization_len; idx++) {
            ((uint8_t *)personalized_entropy)[idx] ^= personalization[idx];
        }
        seed_material = (uint8_t *)personalized_entropy;
    }

    memset(state, 0, sizeof(struct cc3xx_drbg_ctr_state_t));

    err = cc3xx_drbg_ctr_update(state, seed_material, CC3XX_DRBG_CTR_SEEDLEN);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    state->reseed_counter = 1;

out:
    if (personalization != NULL) {
        /* Make sure the seed material on the stack gets overwritten with random values */
        cc3xx_secure_erase_buffer(personalized_entropy, CC3XX_DRBG_CTR_SEEDLEN_WORDS);
    }

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_ctr_generate(
    struct cc3xx_drbg_ctr_state_t *state,
    size_t len_bits, uint8_t *returned_bits,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;
    const uint8_t all_zeros[CC3XX_DRBG_CTR_SEEDLEN] = {0};
    const uint8_t *p_additional_input = all_zeros;
    size_t produced_bits = 0;
    size_t num_whole_blocks = (len_bits/8)/CC3XX_DRBG_CTR_SEEDLEN;
    struct cc3xx_aes_state_t aes_state;
    size_t idx;

    if (state->reseed_counter == UINT32_MAX) {
        /* When we reach 2^32 invocations we must reseed */
        return CC3XX_ERR_DRBG_RESEED_REQUIRED;
    }

    /* The implementation constraints the output length to be byte aligned to
     * reduce complexity
     */
    assert(len_bits != 0);
    assert((len_bits % 8) == 0);

    if (additional_input != NULL) {

        assert(additional_input_len <= CC3XX_DRBG_CTR_SEEDLEN);

        err = cc3xx_drbg_ctr_update(state, additional_input, additional_input_len);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        p_additional_input = additional_input;
    }

    long_inc((uint32_t *)state->block_v, sizeof(state->block_v));

    err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT,
                                  CC3XX_AES_MODE_CTR,
                                  CC3XX_AES_KEY_ID_USER_KEY,
                                  (const uint32_t *)state->key_k, CC3XX_AES_KEYSIZE_128,
                                  (const uint32_t *)state->block_v, sizeof(state->block_v));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_aes_set_output_buffer(returned_bits, len_bits/8); /* length is in bytes */

    for (idx = 0; idx < num_whole_blocks; idx++) {
        err = cc3xx_lowlevel_aes_update(all_zeros, sizeof(all_zeros));
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        produced_bits += (CC3XX_DRBG_CTR_SEEDLEN * 8);
    }

    /* Deal with a partial block */
    if ((len_bits - produced_bits) != 0) {
        /* Produce the last block */
        err = cc3xx_lowlevel_aes_update(all_zeros, (len_bits - produced_bits)/8); /* in bytes */
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
    }

    /* We need to get the value of the counter back from the AES subsystem
     * as it's required in update()
     */
    cc3xx_lowlevel_aes_get_state(&aes_state);

    err = cc3xx_lowlevel_aes_finish(NULL, NULL);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    cc3xx_dpa_hardened_word_copy((uint32_t *)state->block_v,
                                 aes_state.ctr,
                                 CC3XX_DRBG_CTR_BLOCKLEN_WORDS);
#else
    memcpy(state->block_v, aes_state.ctr, sizeof(state->block_v));
#endif
    long_dec((uint32_t *)state->block_v, sizeof(state->block_v));

    /* Update for back tracking resistance */
    err = cc3xx_drbg_ctr_update(state, p_additional_input, CC3XX_DRBG_CTR_SEEDLEN);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    state->reseed_counter++;

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_ctr_reseed(
    struct cc3xx_drbg_ctr_state_t *state,
    const uint8_t *entropy, size_t entropy_len,
    const uint8_t *additional_input, size_t additional_input_len)
{
    cc3xx_err_t err;
    uint32_t personalized_entropy[CC3XX_DRBG_CTR_SEEDLEN_WORDS];
    uint8_t *seed_material = (uint8_t *)entropy;
    size_t idx;

    assert(entropy_len == CC3XX_DRBG_CTR_SEEDLEN);

    if (additional_input != NULL) {
        assert(additional_input_len <= CC3XX_DRBG_CTR_SEEDLEN);
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
        cc3xx_dpa_hardened_word_copy(personalized_entropy,
                                     (uint32_t *)entropy,
                                     CC3XX_DRBG_CTR_SEEDLEN_WORDS);
#else
        memcpy(personalized_entropy, entropy, entropy_len);
#endif
        for (idx = 0; idx < additional_input_len; idx++) {
            ((uint8_t *)personalized_entropy)[idx] ^= additional_input[idx];
        }
        seed_material = (uint8_t *)personalized_entropy;
    }

    err = cc3xx_drbg_ctr_update(state, seed_material, entropy_len);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    state->reseed_counter = 1;

out:
    if (additional_input != NULL) {
        /* Make sure the seed material on the stack gets overwritten with random values */
        cc3xx_secure_erase_buffer(personalized_entropy, CC3XX_DRBG_CTR_SEEDLEN_WORDS);
    }

    return err;
}

cc3xx_err_t cc3xx_lowlevel_drbg_ctr_uninit(struct cc3xx_drbg_ctr_state_t *state)
{
    /* Secure erase only the sensitive material*/
    cc3xx_secure_erase_buffer((uint32_t *)state, CC3XX_DRBG_CTR_SEEDLEN_WORDS);

    memset(state, 0, sizeof(struct cc3xx_drbg_ctr_state_t));

    return CC3XX_ERR_SUCCESS;
}

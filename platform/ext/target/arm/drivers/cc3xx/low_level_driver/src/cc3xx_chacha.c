/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_chacha.h"

#include "cc3xx_dev.h"
#include "cc3xx_engine_state.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_rng.h"

#include <string.h>
#include <assert.h>

struct cc3xx_chacha_state_t chacha_state;

static void set_iv(const uint32_t *iv)
{
    if (chacha_state.iv_is_96_bit) {
        P_CC3XX->chacha.chacha_block_cnt_msb = iv[0];
        iv += 1;
    }
    P_CC3XX->chacha.chacha_iv[0] = iv[0];
    P_CC3XX->chacha.chacha_iv[1] = iv[1];
}

static void get_iv(uint32_t *iv)
{
    if (chacha_state.iv_is_96_bit) {
        iv[0] = P_CC3XX->chacha.chacha_block_cnt_msb;
        iv += 1;
    }
    iv[0] = P_CC3XX->chacha.chacha_iv[0];
    iv[1] = P_CC3XX->chacha.chacha_iv[1];
}

static void set_ctr(const uint64_t ctr)
{
    if (!chacha_state.iv_is_96_bit) {
        P_CC3XX->chacha.chacha_block_cnt_msb = ctr >> 32;
    }
    P_CC3XX->chacha.chacha_block_cnt_lsb = (uint32_t)ctr;
}

static uint64_t get_ctr(void)
{
    uint64_t ctr = 0;

    if (!chacha_state.iv_is_96_bit) {
        ctr = (uint64_t)P_CC3XX->chacha.chacha_block_cnt_msb << 32;
    }
    ctr |= P_CC3XX->chacha.chacha_block_cnt_lsb;

    return ctr;
}

static inline void set_key(const uint32_t *key)
{
    size_t idx;

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    (void)idx;

    cc3xx_dpa_hardened_word_copy(P_CC3XX->chacha.chacha_key, key, 7);
    P_CC3XX->chacha.chacha_key[7] = key[7];
#else
    for (idx = 0; idx < 8; idx++) {
        P_CC3XX->chacha.chacha_key[idx] = key[idx];
    }
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
}

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
static void reset_current_output_size(void)
{
    dma_state.current_bytes_output = 0;
}
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

static void chacha_init_from_state(void)
{
    P_CC3XX->misc.chacha_clk_enable = 0x1U;

    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_CHACHA);

    /* This is the block size */
    cc3xx_lowlevel_dma_set_buffer_size(CC3XX_CHACHA_BLOCK_SIZE);

    set_key(chacha_state.key);

    P_CC3XX->chacha.chacha_control_reg = 0x0U;

    while(P_CC3XX->chacha.chacha_busy) {}

    if (chacha_state.iv_is_96_bit) {
        /* 96 bit IVs use a special case */
        P_CC3XX->chacha.chacha_control_reg |= 0b1 << 10;
    }

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        /* Set to output the poly1305 key */
        P_CC3XX->chacha.chacha_control_reg |= (chacha_state.mode & 0b1) << 2;
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */
}

cc3xx_err_t cc3xx_lowlevel_chacha20_init(
    cc3xx_chacha_direction_t direction,
    cc3xx_chacha_mode_t mode,
    const uint32_t *key,
    uint64_t initial_counter,
    const uint32_t *iv, size_t iv_len)
{
    uint32_t idx;
#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    uint32_t poly_key[CC3XX_CHACHA_BLOCK_SIZE / sizeof(uint32_t)] = {0};

    if (mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        assert(initial_counter == 0);
    }
#else
    assert(mode == CC3XX_CHACHA_MODE_CHACHA);
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    cc3xx_lowlevel_chacha20_uninit();

    chacha_state.direction = direction;
    chacha_state.mode = mode;

    if (iv_len == 12) {
        chacha_state.iv_is_96_bit = true;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    (void)idx;

    cc3xx_dpa_hardened_word_copy(chacha_state.key, key, 8);
#else
    for (idx = 0; idx < 8; idx++) {
        chacha_state.key[idx] = key[idx];
    }
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

    chacha_init_from_state();

    set_iv(iv);
    set_ctr(initial_counter);

    /* Init new message from host. This must be the last thing done before data
     * is input.
     */
    P_CC3XX->chacha.chacha_control_reg |= 0b1 << 1;

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    /* Calculate the poly1305 key by inputting an all-zero block. This uses
     * counter value 0, leaving the encryption to start on counter value 1.
     */
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        cc3xx_lowlevel_dma_set_output(poly_key, sizeof(poly_key));
        cc3xx_lowlevel_dma_buffered_input_data(poly_key, sizeof(poly_key), true, true);
        cc3xx_lowlevel_dma_flush_buffer(true);

        /* This is a preparatory operation so no need to count it in the output size */
        reset_current_output_size();

        cc3xx_lowlevel_poly1305_init(poly_key,
                                     poly_key + (POLY1305_KEY_SIZE / sizeof(uint32_t)));
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_chacha20_get_state(struct cc3xx_chacha_state_t *state)
{
    memcpy(state, &chacha_state, sizeof(struct cc3xx_chacha_state_t));
    memcpy(&state->dma_state, &dma_state, sizeof(dma_state));

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        cc3xx_lowlevel_poly1305_get_state(&state->poly_state);
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    get_iv(state->iv);
    state->counter = get_ctr();
}

void cc3xx_lowlevel_chacha20_set_state(const struct cc3xx_chacha_state_t *state)
{
    memcpy(&chacha_state, state, sizeof(struct cc3xx_chacha_state_t));
    memcpy(&dma_state, &state->dma_state, sizeof(dma_state));

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        cc3xx_lowlevel_poly1305_set_state(&state->poly_state);
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    chacha_init_from_state();

    set_iv(state->iv);
    set_ctr(state->counter);

    /* Init new message from host. This must be the last thing done before data
     * is input.
     */
    P_CC3XX->chacha.chacha_control_reg |= 0b1 << 1;
}

size_t cc3xx_lowlevel_chacha20_get_current_output_size(void)
{
    return dma_state.current_bytes_output;
}

void cc3xx_lowlevel_chacha20_set_output_buffer(uint8_t *out, size_t out_len)
{
    cc3xx_lowlevel_dma_set_output(out, out_len);
}

void cc3xx_lowlevel_chacha20_update_authed_data(const uint8_t* in, size_t in_len)
{
    if (in_len == 0) {
        return;
    }

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        chacha_state.authed_len += in_len;
        cc3xx_lowlevel_poly1305_update(in, in_len);
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */
}

cc3xx_err_t cc3xx_lowlevel_chacha20_update(const uint8_t* in, size_t in_len)
{
    cc3xx_err_t err;
#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    size_t block_buf_size_before_update = dma_state.block_buf_size_in_use;
    size_t bytes_outputted_from_dma;
    uint32_t pad_len;
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    if (in_len == 0) {
        return CC3XX_ERR_SUCCESS;
    }

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    /* Input into poly1305 before into the DMA, in case we're doing an in-place
     * operation.
     */
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        const uint8_t zero_block[POLY1305_BLOCK_SIZE] = {0};
        pad_len = POLY1305_BLOCK_SIZE - (chacha_state.authed_len % POLY1305_BLOCK_SIZE);

        /* If the pad_len is POLY1305_BLOCK_SIZE, then we're already padded
         * correctly.
         */
        if (chacha_state.crypted_len == 0 && pad_len != POLY1305_BLOCK_SIZE) {
            /* Pad poly1305 between AAD and plaintext */
            cc3xx_lowlevel_poly1305_update(zero_block, pad_len);
        }

        chacha_state.crypted_len += in_len;

        /* If we're decrypting, then input the input data to poly1305. If we're
         * encrypting then it's trickier as we have to deal with the DMA
         * buffering, so is done elsewhere.
         */
        if (chacha_state.direction == CC3XX_CHACHA_DIRECTION_DECRYPT) {
            cc3xx_lowlevel_poly1305_update(in, in_len);
        }
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    err = cc3xx_lowlevel_dma_buffered_input_data(in, in_len, true, true);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* Flush the block straight away if we have enough data */
    if (dma_state.block_buf_size_in_use == CC3XX_CHACHA_BLOCK_SIZE) {
        cc3xx_lowlevel_dma_flush_buffer(false);
    }

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    /* If we're encrypting, we now need to input any blocks that got outputted
     * in this operation into poly1305.
     */
    bytes_outputted_from_dma = (block_buf_size_before_update + in_len)
                                / CC3XX_CHACHA_BLOCK_SIZE * CC3XX_CHACHA_BLOCK_SIZE;

    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305 &&
        chacha_state.direction == CC3XX_CHACHA_DIRECTION_ENCRYPT &&
        bytes_outputted_from_dma > 0) {
        cc3xx_lowlevel_poly1305_update((uint8_t *)(dma_state.output_addr - bytes_outputted_from_dma),
                                       bytes_outputted_from_dma);
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    return err;
}

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
static cc3xx_err_t tag_cmp_or_copy(uint32_t *tag, uint32_t *calculated_tag)
{
    uint32_t idx;
    uint32_t tag_word_size = POLY1305_TAG_LEN / sizeof(uint32_t);
    uint8_t permutation_buf[tag_word_size];
    bool are_different = 0;

    if (chacha_state.direction == CC3XX_CHACHA_DIRECTION_DECRYPT) {
        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, tag_word_size);

        for (idx = 0; idx < tag_word_size; idx++) {
            are_different |= tag[permutation_buf[idx]] ^ calculated_tag[permutation_buf[idx]];
        }
    } else {
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
        cc3xx_dpa_hardened_word_copy(tag, calculated_tag, tag_word_size);
#else
        memcpy(tag, calculated_tag, POLY1305_TAG_LEN);
#endif
    }

    if (are_different) {
        return CC3XX_ERR_INVALID_TAG;
    } else {
        return CC3XX_ERR_SUCCESS;
    }
}
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

cc3xx_err_t cc3xx_lowlevel_chacha20_finish(uint32_t *tag, size_t *size)
{
#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    uint64_t len_block[2] = {0};
    uint32_t calculated_tag[POLY1305_TAG_LEN / sizeof(uint32_t)];
    size_t pad_len;
    uint32_t final_data_size = dma_state.block_buf_size_in_use;
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */
    cc3xx_err_t err;

    /* Check alignment */
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    assert(((uintptr_t)tag & 0b11) == 0);
#endif

    cc3xx_lowlevel_dma_flush_buffer(false);

    if (size != NULL) {
        *size = cc3xx_lowlevel_chacha20_get_current_output_size();
    }

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        /* Finish inputting the last of the flushed blocks
         */
        if (chacha_state.direction == CC3XX_CHACHA_DIRECTION_ENCRYPT) {
            cc3xx_lowlevel_poly1305_update((uint8_t *)(dma_state.output_addr - final_data_size),
                                           final_data_size);
        }

        if (chacha_state.crypted_len == 0) {
            pad_len = chacha_state.authed_len;
        } else {
            pad_len = chacha_state.crypted_len;
        }
        pad_len = POLY1305_BLOCK_SIZE - (pad_len % POLY1305_BLOCK_SIZE);

        /* The len block starts zeroed, so use it for padding. If the pad length
         * is POLY1305_BLOCK_SIZE then no padding is needed.
         */
        if (pad_len != POLY1305_BLOCK_SIZE) {
            cc3xx_lowlevel_poly1305_update((uint8_t *)len_block, pad_len);
        }

        len_block[0] = chacha_state.authed_len;
        len_block[1] = chacha_state.crypted_len;

        cc3xx_lowlevel_poly1305_update((uint8_t *)len_block,
                              sizeof(len_block));
        cc3xx_lowlevel_poly1305_finish(calculated_tag);

        err = tag_cmp_or_copy(tag, calculated_tag);
    } else
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */
    {
        err = CC3XX_ERR_SUCCESS;
    }

    cc3xx_lowlevel_chacha20_uninit();

    return err;
}

void cc3xx_lowlevel_chacha20_uninit(void)
{
    uint32_t zero_iv[3] = {0};
    memset(&chacha_state, 0, sizeof(chacha_state));

#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE)
    if (chacha_state.mode == CC3XX_CHACHA_MODE_CHACHA_POLY1305) {
        cc3xx_lowlevel_poly1305_uninit();
    }
#endif /* CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

    set_ctr(0);
    set_iv(zero_iv);

    P_CC3XX->chacha.chacha_control_reg = 0;
    P_CC3XX->misc.chacha_clk_enable = 0;

    cc3xx_lowlevel_dma_uninit();
}

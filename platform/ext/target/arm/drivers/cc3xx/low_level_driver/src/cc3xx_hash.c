/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_hash.h"

#include "cc3xx_dev.h"
#include "cc3xx_error.h"
#include "cc3xx_dma.h"
#include "cc3xx_engine_state.h"
#include "cc3xx_endian_helpers.h"
#include "cc3xx_stdlib.h"

#include "fatal_error.h"

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#ifdef CC3XX_CONFIG_HASH_SHA256_ENABLE
static const uint32_t iv_sha256[8] = {
    0x67e6096aU, 0x85ae67bbU, 0x72f36e3cU, 0x3af54fa5U,
    0x7f520e51U, 0x8c68059bU, 0xabd9831fU, 0x19cde05bU,
};
#endif /* CC3XX_CONFIG_SHA256_ENABLE */
#ifdef CC3XX_CONFIG_HASH_SHA224_ENABLE
static const uint32_t iv_sha224[8] = {
    0xD89E05C1U, 0x07D57C36U, 0x17DD7030U, 0x39590EF7U,
    0x310BC0FFU, 0x11155868U, 0xA78FF964U, 0xA44FFABEU,
};
#endif /* CC3XX_CONFIG_HASH_SHA224_ENABLE */
#ifdef CC3XX_CONFIG_HASH_SHA1_ENABLE
static const uint32_t iv_sha1[5] = {
    0x01234567U, 0x89ABCDEFU, 0xFEDCBA98U, 0x76543210U,
    0xF0E1D2C3U,
};
#endif /* CC3XX_CONFIG_HASH_SHA1_ENABLE */

static void set_hash_h(const uint32_t *buf, size_t length)
{
    int32_t idx;

    /* The set of the hash_h register must be done in reverse order */
    for (idx = (length / 4) - 1; idx >= 0; idx--) {
        P_CC3XX->hash.hash_h[idx] = bswap_32(buf[idx]);
    }
}

static void get_hash_h(uint32_t *buf, size_t length)
{
    size_t idx;

    for (idx = 0; idx < (length / 4); idx++) {
        buf[idx] = bswap_32(P_CC3XX->hash.hash_h[idx]);
    }
}

static void init_without_iv_set(cc3xx_hash_alg_t alg)
{
    /* Enable the hash engine clock */
    P_CC3XX->misc.hash_clk_enable = 0x1U;

    /* Select hash engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_HASH);

    /* Select HASH mode, not MAC */
    P_CC3XX->hash.hash_sel_aes_mac  = 0x0U;

    /* Enable padding */
    P_CC3XX->hash.hash_pad_en = 0x1U;

    /* Disable auto-padding to allow multipart operations */
    P_CC3XX->hash.auto_hw_padding = 0x0U;

    P_CC3XX->hash.hash_control = alg & 0b1111;

    cc3xx_lowlevel_dma_set_buffer_size(64);
}

cc3xx_err_t cc3xx_lowlevel_hash_init(cc3xx_hash_alg_t alg)
{
    cc3xx_lowlevel_hash_uninit();

    const uint32_t *iv;
    size_t iv_len;

    init_without_iv_set(alg);

    /* Set already processed length to 0 */
    P_CC3XX->hash.hash_cur_len[0] = 0x0U;
    P_CC3XX->hash.hash_cur_len[1] = 0x0U;

    switch (alg) {
#ifdef CC3XX_CONFIG_HASH_SHA224_ENABLE
    case CC3XX_HASH_ALG_SHA224:
        iv = iv_sha224;
        iv_len = sizeof(iv_sha224);
        break;
#endif /* CC3XX_CONFIG_HASH_SHA224_ENABLE */
#ifdef CC3XX_CONFIG_HASH_SHA256_ENABLE
    case CC3XX_HASH_ALG_SHA256:
        iv = iv_sha256;
        iv_len = sizeof(iv_sha256);
        break;
#endif /* CC3XX_CONFIG_HASH_SHA256_ENABLE */
#ifdef CC3XX_CONFIG_HASH_SHA1_ENABLE
    case CC3XX_HASH_ALG_SHA1:
        iv = iv_sha1;
        iv_len = sizeof(iv_sha1);
        break;
#endif /* CC3XX_CONFIG_HASH_SHA1_ENABLE */
    default:
        cc3xx_lowlevel_hash_uninit();
        FATAL_ERR(CC3XX_ERR_NOT_IMPLEMENTED);
        return CC3XX_ERR_NOT_IMPLEMENTED;
    }

    set_hash_h(iv, iv_len);

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_hash_set_xor_input(const uint32_t xor_input)
{
    /* Flush any pending data before changing the xor_input mask */
    cc3xx_lowlevel_dma_flush_buffer(false);

    P_CC3XX->hash.hash_xor_din = xor_input;
}

void cc3xx_lowlevel_hash_reset_xor_input(void)
{
    cc3xx_lowlevel_hash_set_xor_input(0x0UL);
}

void cc3xx_lowlevel_hash_uninit(void)
{
    static const uint32_t zero_buf[9] = {0};
    cc3xx_lowlevel_dma_uninit();

    set_hash_h(zero_buf, sizeof(zero_buf));

    /* Reset padding registers as required by the hardware */
    P_CC3XX->hash.hash_pad_cfg = 0x0U;
    P_CC3XX->hash.auto_hw_padding = 0x0U;

    /* Reset XOR DIN input register */
    P_CC3XX->hash.hash_xor_din = 0x0U;

    /* Reset engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_NONE);

    /* Disable the hash engine clock */
    P_CC3XX->misc.hash_clk_enable = 0x0U;
}

cc3xx_err_t cc3xx_lowlevel_hash_update(const uint8_t *buf, size_t length)
{
    return cc3xx_lowlevel_dma_buffered_input_data(buf, length, false);
}

void cc3xx_lowlevel_hash_get_state(struct cc3xx_hash_state_t *state)
{
    state->curr_len = P_CC3XX->hash.hash_cur_len[0];
    state->curr_len |= (uint64_t)P_CC3XX->hash.hash_cur_len[1] << 32;
    state->alg = P_CC3XX->hash.hash_control & 0b1111;
    state->xor_input = P_CC3XX->hash.hash_xor_din;

    get_hash_h(state->hash_h, sizeof(state->hash_h));
    memcpy(&state->dma_state, &dma_state, sizeof(state->dma_state));
}

void cc3xx_lowlevel_hash_set_state(const struct cc3xx_hash_state_t *state)
{
    init_without_iv_set(state->alg);
    size_t hash_h_len = state->alg != CC3XX_HASH_ALG_SHA1 ? SHA256_OUTPUT_SIZE
                                                          : SHA1_OUTPUT_SIZE;

    P_CC3XX->hash.hash_cur_len[0] = (uint32_t)state->curr_len;
    P_CC3XX->hash.hash_cur_len[1] = (uint32_t)(state->curr_len >> 32);

    P_CC3XX->hash.hash_xor_din = state->xor_input;

    set_hash_h(state->hash_h, hash_h_len);
    memcpy(&dma_state, &state->dma_state, sizeof(dma_state));
}

void cc3xx_lowlevel_hash_finish(uint32_t *res, size_t length)
{
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    /* Check alignment */
    assert(((uintptr_t)res & 0b11) == 0);
#endif

    /* Check size */
    switch (P_CC3XX->hash.hash_control & 0b1111) {
    case CC3XX_HASH_ALG_SHA256:
        assert(length >= SHA256_OUTPUT_SIZE);
        break;
    case CC3XX_HASH_ALG_SHA224:
        assert(length >= SHA224_OUTPUT_SIZE);
        break;
    case CC3XX_HASH_ALG_SHA1:
        assert(length >= SHA1_OUTPUT_SIZE);
        break;
    }

    /* If any data has been input to the hash, the DMA block buf will be
     * non-zero size.
     */
    if (dma_state.block_buf_size_in_use != 0) {
        P_CC3XX->hash.auto_hw_padding = 0x1U;
        cc3xx_lowlevel_dma_flush_buffer(false);
    } else {
        /* Special-case for hardware padding when the length is 0 */
        P_CC3XX->hash.hash_pad_cfg = 0x4U;
    }

    /* Wait until HASH engine is idle */
    while (P_CC3XX->cc_ctl.hash_busy != 0) {}

    get_hash_h(res, length);

    cc3xx_lowlevel_hash_uninit();
}

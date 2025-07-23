/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <assert.h>
#include <stdbool.h>
#include "endian.h"
#include <stdint.h>

#include "cc3xx_aes.h"
#include "cc3xx_dev.h"
#include "cc3xx_dma.h"
#include "cc3xx_hash.h"
#include "cc3xx_lcs.h"
#include "cc3xx_engine_state.h"
#include "cc3xx_stdlib.h"
#include "cc3xx_rng.h"

#include "fatal_error.h"

#ifdef CC3XX_CONFIG_AES_EXTERNAL_KEY_LOADER
#include "cc3xx_aes_external_key_loader.h"
#endif /* CC3XX_CONFIG_AES_EXTERNAL_KEY_LOADER */

struct cc3xx_aes_state_t aes_state;

static inline size_t get_key_size_bytes(cc3xx_aes_keysize_t key_size)
{
    assert(key_size == CC3XX_AES_KEYSIZE_128
        || key_size == CC3XX_AES_KEYSIZE_192
        || key_size == CC3XX_AES_KEYSIZE_256);
    return 16 + key_size * 8;
}

/* We don't offer CBC_MAC as a standalone mode, so define it here instead of in
 * the header
 */
#define CC3XX_AES_MODE_CBC_MAC 0b0011U

#ifndef CC3XX_CONFIG_AES_EXTERNAL_KEY_LOADER
static cc3xx_err_t check_key_lock(cc3xx_aes_key_id_t key_id)
{
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    cc3xx_lcs_t lcs;

    switch (key_id) {
    case CC3XX_AES_KEY_ID_HUK:
        break;
    case CC3XX_AES_KEY_ID_KRTL:
        err = cc3xx_lowlevel_lcs_get(&lcs);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
        /* The RTL key is only valid in certain states */
        if (! (lcs == (cc3xx_lcs_cm | cc3xx_lcs_dm))) {
            FATAL_ERR(CC3XX_ERR_INVALID_LCS);
            return CC3XX_ERR_INVALID_LCS;
        }
        break;
    case CC3XX_AES_KEY_ID_KCP:
        if (P_CC3XX->ao.host_ao_lock_bits & (0x1U << 3)) {
            FATAL_ERR(CC3XX_ERR_INVALID_STATE);
            return CC3XX_ERR_INVALID_STATE;
        }
        break;
    case CC3XX_AES_KEY_ID_KCE:
        if (P_CC3XX->ao.host_ao_lock_bits & (0x1U << 4)) {
            FATAL_ERR(CC3XX_ERR_INVALID_STATE);
            return CC3XX_ERR_INVALID_STATE;
        }
        break;
    case CC3XX_AES_KEY_ID_KPICV:
        if (P_CC3XX->ao.host_ao_lock_bits & (0x1U << 1)) {
            FATAL_ERR(CC3XX_ERR_INVALID_STATE);
            return CC3XX_ERR_INVALID_STATE;
        }
        break;
    case CC3XX_AES_KEY_ID_KCEICV:
        if (P_CC3XX->ao.host_ao_lock_bits & (0x1U << 2)) {
            FATAL_ERR(CC3XX_ERR_INVALID_STATE);
            return CC3XX_ERR_INVALID_STATE;
        }
        break;
    case CC3XX_AES_KEY_ID_USER_KEY:
        break;
    default:
        return CC3XX_ERR_SUCCESS;
    }

    return CC3XX_ERR_SUCCESS;
}

static cc3xx_err_t set_key(cc3xx_aes_key_id_t key_id, const uint32_t *key,
                           cc3xx_aes_keysize_t key_size, bool is_tun1)
{
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    volatile uint32_t *hw_key_buf_ptr;

#if !defined(CC3XX_CONFIG_AES_CCM_ENABLE) || !defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE)
    if (is_tun1) {
        assert(0); /* Wrong programming for this driver configuration */
        FATAL_ERR(CC3XX_ERR_INVALID_STATE);
        return CC3XX_ERR_INVALID_STATE;
    }
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) */

    if (!is_tun1) {
        hw_key_buf_ptr = P_CC3XX->aes.aes_key_0;
    } else {
        hw_key_buf_ptr = P_CC3XX->aes.aes_key_1;
    }

    /* Set key0 size */
    if (!is_tun1) {
        P_CC3XX->aes.aes_control &= ~(0b11U << 12);
        P_CC3XX->aes.aes_control |= (key_size & 0b11U) << 12;
    } else {
        /* Set key1 size */
        P_CC3XX->aes.aes_control &= ~(0b11U << 14);
        P_CC3XX->aes.aes_control |= (key_size & 0b11U) << 14;
    }

    if (key_id != CC3XX_AES_KEY_ID_USER_KEY) {
        /* Check if the HOST_FATAL_ERROR mode is enabled */
        if (P_CC3XX->ao.host_ao_lock_bits & 0x1U) {
            FATAL_ERR(CC3XX_ERR_INVALID_STATE);
            return CC3XX_ERR_INVALID_STATE;
        }

        /* Check if the key is masked / locked */
        err = check_key_lock(key_id);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }

        /* Select the required key */
        P_CC3XX->host_rgf.host_cryptokey_sel = key_id;

        /* Trigger the load into the key registers */
        if (!is_tun1) {
            P_CC3XX->aes.aes_sk = 0b1U;
        } else {
            P_CC3XX->aes.aes_sk1 = 0b1U;
        }
    } else {
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
        size_t key_word_size = 4 + (key_size * 2);

        cc3xx_dpa_hardened_word_copy(hw_key_buf_ptr, key, key_word_size - 1);
        hw_key_buf_ptr[key_word_size - 1] = key[key_word_size - 1];
#else
        hw_key_buf_ptr[0] = key[0];
        hw_key_buf_ptr[1] = key[1];
        hw_key_buf_ptr[2] = key[2];
        hw_key_buf_ptr[3] = key[3];
        if (key_size > CC3XX_AES_KEYSIZE_128) {
            hw_key_buf_ptr[4] = key[4];
            hw_key_buf_ptr[5] = key[5];
        }
        if (key_size > CC3XX_AES_KEYSIZE_192) {
            hw_key_buf_ptr[6] = key[6];
            hw_key_buf_ptr[7] = key[7];
        }
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
    }

    return CC3XX_ERR_SUCCESS;
}
#endif /* !CC3XX_CONFIG_AES_EXTERNAL_KEY_LOADER */

static void set_iv(const uint32_t *iv)
{
    P_CC3XX->aes.aes_iv_0[0] = iv[0];
    P_CC3XX->aes.aes_iv_0[1] = iv[1];
    P_CC3XX->aes.aes_iv_0[2] = iv[2];
    P_CC3XX->aes.aes_iv_0[3] = iv[3];
}

static void set_ctr(const uint32_t *ctr)
{
    P_CC3XX->aes.aes_ctr_0[0] = ctr[0];
    P_CC3XX->aes.aes_ctr_0[1] = ctr[1];
    P_CC3XX->aes.aes_ctr_0[2] = ctr[2];
    P_CC3XX->aes.aes_ctr_0[3] = ctr[3];
}

static void get_iv(uint32_t *iv)
{
    iv[0] = P_CC3XX->aes.aes_iv_0[0];
    iv[1] = P_CC3XX->aes.aes_iv_0[1];
    iv[2] = P_CC3XX->aes.aes_iv_0[2];
    iv[3] = P_CC3XX->aes.aes_iv_0[3];
}

static void get_ctr(uint32_t *ctr)
{
     ctr[0]= P_CC3XX->aes.aes_ctr_0[0];
     ctr[1]= P_CC3XX->aes.aes_ctr_0[1];
     ctr[2]= P_CC3XX->aes.aes_ctr_0[2];
     ctr[3]= P_CC3XX->aes.aes_ctr_0[3];
}

#ifndef CC3XX_CONFIG_AES_CCM_ENABLE
inline
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
static void set_mode(cc3xx_aes_mode_t mode)
{
    /* Set mode field of AES control register */
    P_CC3XX->aes.aes_control &= ~(0b111U << 2);
    P_CC3XX->aes.aes_control |= (mode & 0b111U) << 2;
}

static inline void set_tun1_mode(cc3xx_aes_mode_t mode)
{
    /* Set mode field of AES control register */
    P_CC3XX->aes.aes_control &= ~(0b111U << 5);
    P_CC3XX->aes.aes_control |= (mode & 0b111U) << 5;
}

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
static void cc3xx_aes_reset_current_output_size(void)
{
    dma_state.current_bytes_output = 0;
}

#ifdef CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE
static void gcm_calc_initial_counter_from_iv(uint32_t *counter,
                                             const uint32_t *iv,
                                             size_t iv_len)
{
    uint32_t __attribute__((__aligned__(8)))
        iv_block_buf[AES_GCM_FIELD_POINT_SIZE / sizeof(uint32_t)] = {0};
    uint32_t zero_iv[AES_CTR_LEN / sizeof(uint32_t)] = {0};

    /* Select HASH-only engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_HASH);

    /* This calculation is done from the zero field-point */
    P_CC3XX->ghash.ghash_iv_0[0] = zero_iv[0];
    P_CC3XX->ghash.ghash_iv_0[1] = zero_iv[1];
    P_CC3XX->ghash.ghash_iv_0[2] = zero_iv[2];
    P_CC3XX->ghash.ghash_iv_0[3] = zero_iv[3];

    /* Feed IV into the DMA, padding with zeroes. */
    cc3xx_lowlevel_dma_buffered_input_data(iv, iv_len, false, false);
    cc3xx_lowlevel_dma_flush_buffer(true);

    /* Make up the length block, 8 bytes of zeros and a big-endian 64-bit size
     * of the IV in bits
     */
    memset(iv_block_buf, 0, sizeof(iv_block_buf));
    ((uint64_t *)iv_block_buf)[1] = bswap_64((uint64_t)iv_len * 8);
    cc3xx_lowlevel_dma_buffered_input_data(iv_block_buf, sizeof(iv_block_buf), false, false);
    cc3xx_lowlevel_dma_flush_buffer(false);

    /* Wait for the GHASH to complete */
    while(P_CC3XX->ghash.ghash_busy) {}

    /* Grab the result out of the GHASH buffer */
    counter[0] = P_CC3XX->ghash.ghash_iv_0[0];
    counter[1] = P_CC3XX->ghash.ghash_iv_0[1];
    counter[2] = P_CC3XX->ghash.ghash_iv_0[2];
    counter[3] = P_CC3XX->ghash.ghash_iv_0[3];
}
#endif /* CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE */

static void gcm_init_iv(const uint32_t *iv, size_t iv_len)
{
    uint32_t zero_iv[AES_CTR_LEN / sizeof(uint32_t)] = {0};

    /* The hash-key is an ECB-encrypted zero block. GCTR mode with a zero-ctr is
     * the same as ECB
     */
    P_CC3XX->aes.aes_ctr_0[0] = zero_iv[0];
    P_CC3XX->aes.aes_ctr_0[1] = zero_iv[1];
    P_CC3XX->aes.aes_ctr_0[2] = zero_iv[2];
    P_CC3XX->aes.aes_ctr_0[3] = zero_iv[3];

    /* Encrypt the all-zero block to get the hash key */
    cc3xx_lowlevel_dma_set_output(aes_state.ghash_key, sizeof(aes_state.ghash_key));
    cc3xx_lowlevel_dma_buffered_input_data(zero_iv, sizeof(zero_iv), true, true);
    cc3xx_lowlevel_dma_flush_buffer(false);

    /* This is a preparatory operation so no need to count it in the output size */
    cc3xx_aes_reset_current_output_size();

    /* Set GHASH_INIT and set the key */
    P_CC3XX->ghash.ghash_subkey_0[0] = aes_state.ghash_key[0];
    P_CC3XX->ghash.ghash_subkey_0[1] = aes_state.ghash_key[1];
    P_CC3XX->ghash.ghash_subkey_0[2] = aes_state.ghash_key[2];
    P_CC3XX->ghash.ghash_subkey_0[3] = aes_state.ghash_key[3];
    P_CC3XX->ghash.ghash_init = 0x1;

    /* The 96-bit (12 byte) IV is a special case (IV || 0b0^31 || 0b1) */
    if (iv_len == 12) {
        aes_state.counter_0[0] = iv[0];
        aes_state.counter_0[1] = iv[1];
        aes_state.counter_0[2] = iv[2];
        aes_state.counter_0[3] = bswap_32(0x1U);
    } else if (iv_len > 0) {
#ifdef CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE
        /* Else GHASH the IV */
        gcm_calc_initial_counter_from_iv(aes_state.counter_0, iv, iv_len);

        /* Set up the GHASH block again so it's ready for the data */
        P_CC3XX->ghash.ghash_init = 0x1;
#else
        assert(false);
#endif /* CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE */
    }

    /* Set the initial AES counter value to the incremented counter_0 */
    set_ctr(aes_state.counter_0);
    P_CC3XX->aes.aes_ctr_0[3] = bswap_32(bswap_32(aes_state.counter_0[3]) + 1);

    /* Set the GHASH module start point to the zero-point */
    P_CC3XX->ghash.ghash_iv_0[0] = 0;
    P_CC3XX->ghash.ghash_iv_0[1] = 0;
    P_CC3XX->ghash.ghash_iv_0[2] = 0;
    P_CC3XX->ghash.ghash_iv_0[3] = 0;
}
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
static inline void ccm_init_iv(const uint32_t *iv, size_t iv_len)
{

    assert(iv_len >= 7 && iv_len <= 13);

    /* Because CCM requires knowledge of the data length and the tag length
     * before we can construct an IV, we defer the actual iv construction to
     * later.
     */
    memcpy(aes_state.ccm_initial_iv_buf, iv, iv_len);
    aes_state.ccm_initial_iv_size = iv_len;
}
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

static cc3xx_err_t init_from_state(void)
{
    cc3xx_err_t err;

    /* Enable the aes engine clock */
    P_CC3XX->misc.aes_clk_enable = 0x1U;

    /* Set the crypto engine to the AES engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);

    /* If tunnelling is disabled, DFA mitigations are controlled by the
     * HOST_FORCE_DFA_ENABLE switch. If tunnelling is enabled, then they are
     * controlled here, and enabled for all non-tunnelling modes.
     */
#if defined(CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE)
    assert(!(P_CC3XX->ao.host_ao_lock_bits & (0b1U << 7)));

    if (aes_state.mode == CC3XX_AES_MODE_CCM) {
        P_CC3XX->aes.aes_dfa_is_on = 0x0U;
    } else {
        P_CC3XX->aes.aes_dfa_is_on = 0x1U;
    }

#endif /* defined(CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) */

    /* Clear number of remaining bytes */
    P_CC3XX->aes.aes_remaining_bytes = 0x0U;

    /* Set direction field of AES control register */
    P_CC3XX->aes.aes_control &= ~0b1U;
    P_CC3XX->aes.aes_control |= (aes_state.direction & 0b1U);

#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    if (aes_state.mode == CC3XX_AES_MODE_CMAC) {
        /* Reset to encrypt direction. Decryption is undefined in MAC modes.
         * This must be done before the key is set.
         */
        P_CC3XX->aes.aes_control &= ~0b1U;
    }
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    if (aes_state.mode == CC3XX_AES_MODE_CCM) {

        /* Reset to encrypt direction. Decryption is undefined in MAC modes.
         * This must be done before the key is set.
         */
        P_CC3XX->aes.aes_control &= ~0b1U;

#ifdef CC3XX_CONFIG_AES_TUNNELLING_ENABLE
        /* Set TUN1 key to same key as TUN0 */
        err = set_key(aes_state.key_id,
                      aes_state.state_contains_key ? aes_state.key_buf : NULL,
                      aes_state.key_size, true);
        if (err != CC3XX_ERR_SUCCESS) {
            return err;
        }
#endif /* CC3XX_CONFIG_AES_TUNNELLING_ENABLE */
    }
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

    /* Set the mode field */
    set_mode(aes_state.mode);

    /* Clear mode_is_cbc_cts field of control register */
    P_CC3XX->aes.aes_control &= ~(0b1U << 1);

    err = set_key(aes_state.key_id,
                  aes_state.state_contains_key ? aes_state.key_buf : NULL,
                  aes_state.key_size, false);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    if (aes_state.mode == CC3XX_AES_MODE_CMAC) {
        /* Kick the CC to derive K1 and K2 */
        P_CC3XX->aes.aes_cmac_init = 0b1U;
    }
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    if (aes_state.mode == CC3XX_AES_MODE_GCM) {
        /* Set mode_is_cbc_cts field of control register */
        P_CC3XX->aes.aes_control |= (0b1U) << 1;

        /* Set up the GHASH block. First enable hash clock */
        P_CC3XX->misc.hash_clk_enable = 0x1;

        /* Set hash to the GHASH module */
        P_CC3XX->hash.hash_sel_aes_mac = 0b10U;
    }
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_aes_valid_iv_length(
    cc3xx_aes_mode_t mode,
    size_t iv_len)
{
    switch (mode) {
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        /* No IV to set up for CMAC */
        (void)iv_len;
        return CC3XX_ERR_INVALID_IV_LENGTH;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#ifdef CC3XX_CONFIG_AES_ECB_ENABLE
    case CC3XX_AES_MODE_ECB:
        /* No IV to set up for ECB */
        (void)iv_len;
        return CC3XX_ERR_INVALID_IV_LENGTH;
#endif /* CC3XX_CONFIG_AES_ECB_ENABLE */
#ifdef CC3XX_CONFIG_AES_CTR_ENABLE
    case CC3XX_AES_MODE_CTR:
        if (iv_len != 16) {
            return CC3XX_ERR_INVALID_IV_LENGTH;
        }
        break;
#endif /* CC3XX_CONFIG_AES_CTR_ENABLE */
#ifdef CC3XX_CONFIG_AES_CBC_ENABLE
    case CC3XX_AES_MODE_CBC:
        if (iv_len != 16) {
            return CC3XX_ERR_INVALID_IV_LENGTH;
        }
        break;
#endif /* CC3XX_CONFIG_AES_CBC_ENABLE */
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
#ifdef CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE
        if (iv_len == 0) {
            return CC3XX_ERR_INVALID_IV_LENGTH;
        }
#else
        if (iv_len != 12) {
            return CC3XX_ERR_INVALID_IV_LENGTH;
        }
#endif /* CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE */
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    case CC3XX_AES_MODE_CCM:
        if (!((iv_len >= 7) && (iv_len <= 13))) {
            return CC3XX_ERR_INVALID_IV_LENGTH;
        }
        break;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
    default:
        return CC3XX_ERR_NOT_IMPLEMENTED;
    }

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_aes_init(
    cc3xx_aes_direction_t direction,
    cc3xx_aes_mode_t mode, cc3xx_aes_key_id_t key_id,
    const uint32_t *key, cc3xx_aes_keysize_t key_size,
    const uint32_t *iv, size_t iv_len)
{
    cc3xx_err_t err;

    /* Check alignment */
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    assert(((uintptr_t)key & 0b11) == 0);
    assert(((uintptr_t)iv & 0b11) == 0);
#endif

    /* Check larger keys are supported */
    assert(P_CC3XX->host_rgf.host_boot & (1 << 28)); /* SUPPORT_256_192_KEY_LOCAL */
    assert(P_CC3XX->aes.aes_hw_flags & 1); /* SUPPORT_256_192_KEY */

#ifdef CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE
    /* Check if the DFA alarm is tripped, if applicable. This disables the AES
     * block, so we have to return an error.
     */
    if (P_CC3XX->aes.aes_hw_flags & (0x1 << 12)
        && P_CC3XX->aes.aes_dfa_err_status) {
            FATAL_ERR(CC3XX_ERR_DFA_VIOLATION);
            return CC3XX_ERR_DFA_VIOLATION;
    }
#endif /* CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE */

    /* Get a clean starting state */
    cc3xx_lowlevel_aes_uninit();

    aes_state.mode = mode;
    aes_state.direction = direction;

    aes_state.key_id = key_id;
    aes_state.key_size = key_size;
    if (key != NULL) {
        aes_state.state_contains_key = true;
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
        cc3xx_dpa_hardened_word_copy((uint32_t *)aes_state.key_buf, key,
                                     get_key_size_bytes(key_size) / sizeof(uint32_t));
#else
        memcpy(aes_state.key_buf, key, get_key_size_bytes(key_size));
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
    }

    cc3xx_lowlevel_dma_set_buffer_size(16);

    err = init_from_state();
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    switch (mode) {
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        /* No IV to set up for CMAC */
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#ifdef CC3XX_CONFIG_AES_ECB_ENABLE
    case CC3XX_AES_MODE_ECB:
        /* No IV to set up for ECB */
#endif /* CC3XX_CONFIG_AES_ECB_ENABLE */
        break;
#ifdef CC3XX_CONFIG_AES_CTR_ENABLE
    case CC3XX_AES_MODE_CTR:
        assert(iv_len == 16);
        set_ctr(iv);
        break;
#endif /* CC3XX_CONFIG_AES_CTR_ENABLE */
#ifdef CC3XX_CONFIG_AES_CBC_ENABLE
    case CC3XX_AES_MODE_CBC:
        assert(iv_len == 16);
        set_iv(iv);
        break;
#endif /* CC3XX_CONFIG_AES_CBC_ENABLE */
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        gcm_init_iv(iv, iv_len);
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    case CC3XX_AES_MODE_CCM:
        ccm_init_iv(iv, iv_len);
        break;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
    default:
        FATAL_ERR(CC3XX_ERR_NOT_IMPLEMENTED);
        return CC3XX_ERR_NOT_IMPLEMENTED;
    }

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_aes_get_state(struct cc3xx_aes_state_t *state)
{
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    memcpy(state, &aes_state, sizeof(*state));
    cc3xx_dpa_hardened_word_copy(state->key_buf,
                                 aes_state.key_buf,
                                 sizeof(state->key_buf) / sizeof(uint32_t));
#else
    memcpy(state, &aes_state, sizeof(*state));
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

    /* Fill the static aes_state with  */
    get_iv(state->iv);
    get_ctr(state->ctr);

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    state->gcm_field_point[0] = P_CC3XX->ghash.ghash_iv_0[0];
    state->gcm_field_point[1] = P_CC3XX->ghash.ghash_iv_0[1];
    state->gcm_field_point[2] = P_CC3XX->ghash.ghash_iv_0[2];
    state->gcm_field_point[3] = P_CC3XX->ghash.ghash_iv_0[3];
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE)
    state->tun1_iv[0] = P_CC3XX->aes.aes_iv_1[0];
    state->tun1_iv[1] = P_CC3XX->aes.aes_iv_1[1];
    state->tun1_iv[2] = P_CC3XX->aes.aes_iv_1[2];
    state->tun1_iv[3] = P_CC3XX->aes.aes_iv_1[3];
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) */

    memcpy(&state->dma_state, &dma_state, sizeof(state->dma_state));
}

cc3xx_err_t cc3xx_lowlevel_aes_set_state(const struct cc3xx_aes_state_t *state)
{
    cc3xx_err_t err;

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    memcpy(&aes_state, state, sizeof(*state));
    cc3xx_dpa_hardened_word_copy(aes_state.key_buf,
                                 state->key_buf,
                                 sizeof(state->key_buf) / sizeof(uint32_t));
#else
    memcpy(&aes_state, state, sizeof(*state));
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

    err = init_from_state();
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    /* Fill the static aes_state with  */
    set_iv(state->iv);
    set_ctr(state->ctr);
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    P_CC3XX->ghash.ghash_iv_0[0] = state->gcm_field_point[0];
    P_CC3XX->ghash.ghash_iv_0[1] = state->gcm_field_point[1];
    P_CC3XX->ghash.ghash_iv_0[2] = state->gcm_field_point[2];
    P_CC3XX->ghash.ghash_iv_0[3] = state->gcm_field_point[3];

    P_CC3XX->ghash.ghash_subkey_0[0] = state->ghash_key[0];
    P_CC3XX->ghash.ghash_subkey_0[1] = state->ghash_key[1];
    P_CC3XX->ghash.ghash_subkey_0[2] = state->ghash_key[2];
    P_CC3XX->ghash.ghash_subkey_0[3] = state->ghash_key[3];
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE)
    P_CC3XX->aes.aes_iv_1[0] = state->tun1_iv[0];
    P_CC3XX->aes.aes_iv_1[1] = state->tun1_iv[1];
    P_CC3XX->aes.aes_iv_1[2] = state->tun1_iv[2];
    P_CC3XX->aes.aes_iv_1[3] = state->tun1_iv[3];
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) */

    memcpy(&dma_state, &state->dma_state, sizeof(dma_state));

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_aes_set_output_buffer(uint8_t *out, size_t out_len)
{
    cc3xx_lowlevel_dma_set_output(out, out_len);
}

void cc3xx_lowlevel_aes_set_tag_len(uint32_t tag_len)
{
    /* This is only needed if there is an AEAD/MAC mode enabled */
#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_GCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_CMAC_ENABLE)
    aes_state.aes_tag_len = tag_len;

    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    case CC3XX_AES_MODE_CCM:
        /* NIST SP800-38C recommends 8 as a lower bound. IEEE 802.15 specifies
         * that 0, 4, 6, 8, 10, 12, 14, 16 are valid for CCM*.
         */
        assert(tag_len <= 16 && !(tag_len & 0b1) && tag_len != 2);
        break;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        /* NIST SP800-38D recommends 12 as a lower bound. */
        assert(tag_len >= 12 && tag_len <= 16);
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        /* NIST SP800-38B recommends 8 as a lower bound. */
        assert(tag_len >= 8 && tag_len <= 16);
        break;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
    default:
        break;
    }
#endif
}

void cc3xx_lowlevel_aes_set_data_len(uint32_t to_crypt_len, uint32_t to_auth_len)
{
    /* CCM is the only mode that _needs_ to know this information upfront (to
     * calculate the IV) - GCM etc we can set the aes_remaining_bytes just
     * before finally flushing the block buffer.
     */
#if defined(CC3XX_CONFIG_AES_CCM_ENABLE)
    aes_state.aes_to_auth_len = to_auth_len;
    aes_state.aes_to_crypt_len = to_crypt_len;
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) */
}

size_t cc3xx_lowlevel_aes_get_current_output_size(void)
{
    return dma_state.current_bytes_output;
}

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
static void ccm_calc_iv(bool from_auth)
{
    uint8_t __attribute__((__aligned__(4))) b0_block[AES_BLOCK_SIZE] = {0};
    uint64_t crypt_length_be = bswap_64((uint64_t)aes_state.aes_to_crypt_len);

    /* The maximum size of the counter is determined by the size of the IV
     * (since they must both fit into one block (with a byte of padding).
     * Shorter IVs allow more data to be processed by the cipher before the
     * counter overflows (which is unacceptable).
     */
    uint32_t q = 15 - aes_state.ccm_initial_iv_size;

    /* Store q-1 & 0b111 where q=(15 - ccm_initial_iv_size) in the lowest 3
     * bits. q is the size of Q in bytes. Q is the size of the message in bytes.
     */
    b0_block[0] |= (q - 1) & 0b111;

    /* Check that the message size is acceptable according to q */
    assert(((aes_state.aes_to_crypt_len + aes_state.aes_to_auth_len) >> (q * 8)) == 0);

    /* Store t mod 0b111 where t=((ccm_tag_len - 2)/2) in the next 3 bytes. Tag
     * lengths under 4 are not acceptable, but CCM* allows a special-case tag
     * length of 0 which is encoded as 0b000. The case where aes_tag_len is 2 is
     * not checked here, but must be by the caller. */
    if (aes_state.aes_tag_len >= 4) {
        b0_block[0] |= (((aes_state.aes_tag_len - 2) / 2) & 0b111) << 3;
    }

    /* Set the AAD field if this was called from update_authed_data (this is why
     * we had to defer this calculation).
     */
    if (from_auth) {
        b0_block[0] |= 0b1 << 6;
    }

    /* Construct the b0 block using the flags byte, the IV, and the length of
     * the data to be encrypted.
     */
    memcpy(b0_block + 1, aes_state.ccm_initial_iv_buf,
           aes_state.ccm_initial_iv_size);
    memcpy(b0_block + 1 + aes_state.ccm_initial_iv_size,
           ((uint8_t *)&crypt_length_be) + sizeof(crypt_length_be) - q, q);

    /* Input the B0 block into the CBC-MAC */
    cc3xx_lowlevel_dma_buffered_input_data(b0_block, sizeof(b0_block), false, false);

    /* The initial counter value is the same construction as b0, except that the
     * ciphertext length is set to 0 and used at the counter (a neat way to
     * avoid the iv and the ctr ever having the same value). We also need to
     * zero some of the field of the flags byte.
     */
    memset(b0_block + 1 + aes_state.ccm_initial_iv_size, 0, q);
    b0_block[0] &= 0b111;

    /* Save the b0 block for encrypting the last block (similarly to GCM) */
    memcpy(aes_state.counter_0, b0_block, sizeof(aes_state.counter_0));

    /* Increment and set the counter */
    b0_block[15] = 0x1;
    set_ctr((uint32_t *) b0_block);
}

#ifndef CC3XX_CONFIG_AES_TUNNELLING_ENABLE
void c3xx_lowlevel_aes_ccm_init_ctr(uint8_t *ctr, const uint8_t *nonce, size_t nonce_size)
{
    /* The formatting of the counter block is [Flags None [i]8q].
     * q is the byte length of the binary representation of the byte length of the payload,
     * note that q assumes the range 2 << q << 8.
     * the bit formatting of Flags is [0 0 0 0 0 [q-1]3]
     */

    /* Compute q */
    const uint32_t q = AES_BLOCK_SIZE - 1 - nonce_size;

    /* Write [q - 1]3 to its field in Flags */
    ctr[0] = (q - 1) & 0b111;

    /* Copy the nonce */
    memcpy(ctr + 1, nonce, nonce_size);

    /* Initialise the counter value for encryption to 1 */
    ctr[AES_BLOCK_SIZE - 1] = 0x1;
}

void c3xx_lowlevel_aes_ccm_incr_ctr(uint8_t *ctr, const size_t incr_val)
{
    /* The formatting of the counter block is [Flags None [i]8q].
     * q is the byte length of the binary representation of the byte length of the payload,
     * note that q assumes the range 2 << q << 8.
     * the bit formatting of Flags is [0 0 0 0 0 [q-1]3]
     */

    /* Extract "q" from Flags */
    const size_t q = (ctr[0] & 0b111) + 1;

    /* Use q to find the counter value offset */
    const size_t ctr_pos = AES_BLOCK_SIZE - q;

    /* Counter size can be up to 8 bytes, positioned at the end of the buffer */
    uint64_t ctr_val = *((uint64_t *)(ctr + AES_BLOCK_SIZE - sizeof(uint64_t)));

    /* The counter is encoded in big-endian format */
    ctr_val = bswap_64(bswap_64(ctr_val) + incr_val);

    /* counter write-back using the correct offset */
    memcpy(ctr + ctr_pos, ((uint8_t *)&ctr_val) + sizeof(uint64_t) - q, q);
}
#endif /* !CC3XX_CONFIG_AES_TUNNELLING_ENABLE */
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

static void configure_engine_for_authed_data(bool *write_output)
{
    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        cc3xx_lowlevel_set_engine(CC3XX_ENGINE_HASH);
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);
        break;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#if defined(CC3XX_CONFIG_AES_CCM_ENABLE)
    case CC3XX_AES_MODE_CCM:
        cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);
        break;
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) */
    default:
        return;
    }

    *write_output = false;
}

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
static size_t ccm_input_auth_length(void)
{
    uint8_t auth_length_buf[6];
    uint64_t auth_length_be = bswap_64((uint64_t)aes_state.aes_to_auth_len);
    size_t auth_length_byte_length;

    /* 65280 = 2^16 - 2^8 */
    if (aes_state.aes_to_auth_len < 65280) {
        memcpy(auth_length_buf,
               ((uint8_t *)&auth_length_be) + sizeof(auth_length_be) - 2, 2);
        auth_length_byte_length = 2;
    } else {
        auth_length_buf[0] = 0xFF;
        auth_length_buf[1] = 0xFE;
        memcpy(auth_length_buf,
               ((uint8_t *)&auth_length_be) + sizeof(auth_length_be) - 4, 4);
        auth_length_byte_length = 6;
    }

    cc3xx_lowlevel_dma_buffered_input_data(auth_length_buf, auth_length_byte_length, false, false);
    return auth_length_byte_length;
}
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

void cc3xx_lowlevel_aes_update_authed_data(const uint8_t* in, size_t in_len)
{
    cc3xx_err_t err;
    bool write_output;

    if (in_len == 0) {
        return;
    }

    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        P_CC3XX->aes.aes_remaining_bytes = in_len + AES_BLOCK_SIZE;
        break;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#if defined(CC3XX_CONFIG_AES_CCM_ENABLE)
    case CC3XX_AES_MODE_CCM:
        if (aes_state.authed_length == 0) {
            ccm_calc_iv(true);
            /* Do not increment aes_state.authed_length in this
             * case because no authed data has been input
             */
            (void)ccm_input_auth_length();
        }
        break;
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) */
    default:
        return;
    }

    configure_engine_for_authed_data(&write_output);
    assert(write_output == false);

    aes_state.authed_length += in_len;

    /**
     * @note write_output is always false, so the return value cannot be
     *       CC3XX_ERR_DMA_OUTPUT_BUFFER_TOO_SMALL, hence must always be
     *       equal to success.
     */
    err = cc3xx_lowlevel_dma_buffered_input_data(in, in_len, write_output, write_output);
    assert(err == CC3XX_ERR_SUCCESS);
}

static void configure_engine_for_crypted_data(bool *write_output)
{
    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        if (aes_state.direction == CC3XX_AES_DIRECTION_ENCRYPT) {
            cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES_TO_HASH_AND_DOUT);
        } else {
            cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES_AND_HASH);
        }
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        return;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    case CC3XX_AES_MODE_CCM:
#ifdef CC3XX_CONFIG_AES_TUNNELLING_ENABLE
        set_mode(CC3XX_AES_MODE_CTR);
        set_tun1_mode(CC3XX_AES_MODE_CBC_MAC);
        if (aes_state.direction == CC3XX_AES_DIRECTION_ENCRYPT) {
            /* Set AES_TUN_B1_USES_PADDED_DATA_IN, AES_TUNNEL0_ENCRYPT and
             * AES_OUTPUT_MID_TUNNEL_DATA */
            P_CC3XX->aes.aes_control |= 0b111 << 23;
        } else {
            /* Set AES_OUTPUT_MID_TUNNEL_DATA and AES_TUNNEL_B1_PAD_EN */
            P_CC3XX->aes.aes_control |= 0b11 << 25;
            /* Unset AES_TUNNEL0_ENCRYPT */
            P_CC3XX->aes.aes_control &= ~(0b1 << 24);
        }

        /* Set AES_TUNNEL_IS_ON */
        P_CC3XX->aes.aes_control |= 0B1U << 10;

        cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);
#else
        /* Without tunnelling, we just perform CBC_MAC */
        *write_output = false;
        return;
#endif /* CC3XX_CONFIG_AES_TUNNELLING_ENABLE */
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
        break;
    default:
        cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);
    }

    *write_output = true;
}

cc3xx_err_t cc3xx_lowlevel_aes_update(const uint8_t* in, size_t in_len)
{
    cc3xx_err_t err;
    bool write_output, validate_output;

    /* MAC modes have no concept of encryption/decryption
     * so cc3xx_lowlevel_aes_update is a no-op.
     */
    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        return CC3XX_ERR_SUCCESS;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
    default:
        break;
    }

    /* If there is auth data input, then perform a zero-pad and flush before we
     * change how the engine is set up.
     */
    if (aes_state.crypted_length == 0 && aes_state.authed_length != 0) {
        configure_engine_for_authed_data(&write_output);
        cc3xx_lowlevel_dma_flush_buffer(true);
    }

#if defined(CC3XX_CONFIG_AES_CCM_ENABLE)
    if (aes_state.mode == CC3XX_AES_MODE_CCM) {
        if (aes_state.authed_length == 0 && aes_state.crypted_length == 0) {
            /* If the IV was not calculated already by update_authed_data(),
             * then we perform the IV calculation now, but set the argument to
             * indicate that there is no auth data in this operation.
             */
            ccm_calc_iv(false);
            cc3xx_lowlevel_dma_flush_buffer(false);
        }

#ifdef CC3XX_CONFIG_AES_TUNNELLING_ENABLE
        /* For the authed data, CCM uses non-tunnelling CBC_MAC mode. Now we're
         * switching to tunnelling for the encrypted data, we need to copy the
         * current state of the CBC_MAC to the tunnel 1 IV, since tunnel 0 will
         * now be used for the CTR mode operation
         */
        if (aes_state.crypted_length == 0) {
            P_CC3XX->aes.aes_iv_1[0] = P_CC3XX->aes.aes_iv_0[0];
            P_CC3XX->aes.aes_iv_1[1] = P_CC3XX->aes.aes_iv_0[1];
            P_CC3XX->aes.aes_iv_1[2] = P_CC3XX->aes.aes_iv_0[2];
            P_CC3XX->aes.aes_iv_1[3] = P_CC3XX->aes.aes_iv_0[3];
        }
#endif /* CC3XX_CONFIG_AES_TUNNELLING_ENABLE */
    }
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) */

    configure_engine_for_crypted_data(&write_output);
    validate_output = write_output;

    aes_state.crypted_length += in_len;
    if ((aes_state.crypted_length < AES_BLOCK_SIZE) &&
        (aes_state.mode == CC3XX_AES_MODE_CBC || aes_state.mode == CC3XX_AES_MODE_ECB)) {
        validate_output = false;
    }
    err = cc3xx_lowlevel_dma_buffered_input_data(in, in_len, write_output, validate_output);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    if (dma_state.block_buf_size_in_use == AES_BLOCK_SIZE) {
        cc3xx_lowlevel_dma_flush_buffer(false);
    }

    return CC3XX_ERR_SUCCESS;
}

#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_GCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_CMAC_ENABLE)
static cc3xx_err_t tag_cmp_or_copy(uint32_t *tag, uint32_t *calculated_tag)
{
    uint32_t idx;
    uint32_t tag_word_size = (aes_state.aes_tag_len + sizeof(uint32_t) - 1) / sizeof(uint32_t);
    uint8_t permutation_buf[tag_word_size];
    bool are_different = 0;

    if (aes_state.direction == CC3XX_AES_DIRECTION_DECRYPT) {
        cc3xx_lowlevel_rng_get_random_permutation(permutation_buf, tag_word_size);

        for (idx = 0; idx < tag_word_size; idx++) {
            are_different |= tag[permutation_buf[idx]] ^ calculated_tag[permutation_buf[idx]];
        }
    } else {
        cc3xx_dpa_hardened_word_copy(tag, calculated_tag, tag_word_size);
    }

    if (are_different) {
        NONFATAL_ERR(CC3XX_ERR_INVALID_TAG);
        return CC3XX_ERR_INVALID_TAG;
    } else {
        return CC3XX_ERR_SUCCESS;
    }
}
#endif

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
static cc3xx_err_t gcm_finish(uint32_t *tag)
{
    uint64_t len_block[2];
    uint32_t final_block[4];
    uint32_t calculated_tag[4];

    /* Create and input the length block into the GHASH engine. GCM measures all
     * lengths in bits
     */
    len_block[0] = bswap_64((uint64_t)aes_state.authed_length * 8);
    len_block[1] = bswap_64((uint64_t)aes_state.crypted_length * 8);

    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_HASH);

    /* Input the length block in GHASH */
    cc3xx_lowlevel_dma_buffered_input_data(len_block, sizeof(len_block), false, false);
    cc3xx_lowlevel_dma_flush_buffer(false);

    /* Wait for the GHASH to finish */
    while(P_CC3XX->ghash.ghash_busy){}

    /* Set up CTR mode, using the saved counter 0 value */
    set_ctr(aes_state.counter_0);

    /* Encrypt the final GHASH output value */
    final_block[0] = P_CC3XX->ghash.ghash_iv_0[0];
    final_block[1] = P_CC3XX->ghash.ghash_iv_0[1];
    final_block[2] = P_CC3XX->ghash.ghash_iv_0[2];
    final_block[3] = P_CC3XX->ghash.ghash_iv_0[3];

    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_AES);

    cc3xx_lowlevel_dma_set_output(calculated_tag, sizeof(calculated_tag));
    cc3xx_lowlevel_dma_buffered_input_data(final_block, AES_GCM_FIELD_POINT_SIZE, true, true);
    cc3xx_lowlevel_dma_flush_buffer(false);

    while(P_CC3XX->aes.aes_busy) {}

    return tag_cmp_or_copy(tag, calculated_tag);
}
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
static cc3xx_err_t cmac_finish(uint32_t *tag)
{
    uint32_t calculated_tag[AES_IV_LEN / sizeof(uint32_t)];

    if (aes_state.authed_length == 0) {
        /* Special-case for when no data has been input. */
        P_CC3XX->aes.aes_cmac_size0_kick = 0b1U;
    }

    /* The tag is just the final IV */
    get_iv(calculated_tag);

    return tag_cmp_or_copy(tag, calculated_tag);
}
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
static cc3xx_err_t ccm_finish(uint32_t *tag)
{
    uint32_t calculated_tag[AES_IV_LEN / sizeof(uint32_t)];
    volatile uint32_t *calculated_tag_iv_register = P_CC3XX->aes.aes_iv_0;

    /* If tunnelling is disabled, CCM mode is CBC_MAC with the special IV
     * calculations. Depending on whether tunnelling modes is enabled or not,
     * the IV that has the final value is different.
     */
#ifdef CC3XX_CONFIG_AES_TUNNELLING_ENABLE
    if (aes_state.crypted_length != 0) {
        calculated_tag_iv_register = P_CC3XX->aes.aes_iv_1;
    }
#endif /* CC3XX_CONFIG_AES_TUNNELLING_ENABLE */

    calculated_tag[0] = calculated_tag_iv_register[0];
    calculated_tag[1] = calculated_tag_iv_register[1];
    calculated_tag[2] = calculated_tag_iv_register[2];
    calculated_tag[3] = calculated_tag_iv_register[3];

    /* Finally, encrypt the IV value with the original counter 0 value. */
    set_ctr(aes_state.counter_0);
    set_mode(CC3XX_AES_MODE_CTR);
    cc3xx_lowlevel_dma_set_output(calculated_tag, sizeof(calculated_tag));
    cc3xx_lowlevel_dma_buffered_input_data(calculated_tag, sizeof(calculated_tag), true, true);
    cc3xx_lowlevel_dma_flush_buffer(false);

    return tag_cmp_or_copy(tag, calculated_tag);
}
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

cc3xx_err_t cc3xx_lowlevel_aes_finish(uint32_t *tag, size_t *size)
{
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    bool write_output;

    /* Check alignment */
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    assert(((uintptr_t)tag & 0b11) == 0);
#endif

    /* Check how much data is in the DMA block buffer, and set
     * aes_remaining_bytes accordingly.
     */
    P_CC3XX->aes.aes_remaining_bytes = dma_state.block_buf_size_in_use;

    /* The DMA buffer doesn't save the engine state when the block buffer was
     * created, so we need to configure the engine to the right state before the
     * final flush.
     */
    if (aes_state.crypted_length == 0 && aes_state.authed_length != 0) {
        configure_engine_for_authed_data(&write_output);

        /* Most AEAD-only operations require a pad-flush, except CMAC */
        switch (aes_state.mode) {
        default:
            cc3xx_lowlevel_dma_flush_buffer(true);
            break;
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
        case CC3XX_AES_MODE_CMAC:
            cc3xx_lowlevel_dma_flush_buffer(false);
            break;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
        }
    } else if (aes_state.crypted_length != 0) {
        configure_engine_for_crypted_data(&write_output);

        /* ECB and CBC modes require padding since they can't have non-block-sized
         * ciphertexts. Other modes don't need padding.
         */
        switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_ECB_ENABLE
        case CC3XX_AES_MODE_ECB:
            cc3xx_lowlevel_dma_flush_buffer(true);
            break;
#endif /* CC3XX_CONFIG_AES_ECB_ENABLE */
#ifdef CC3XX_CONFIG_AES_CBC_ENABLE
        case CC3XX_AES_MODE_CBC:
            cc3xx_lowlevel_dma_flush_buffer(true);
            break;
#endif /* CC3XX_CONFIG_AES_CBC_ENABLE */
        default:
            cc3xx_lowlevel_dma_flush_buffer(false);
            break;
        }
    }

    /* At this point all the bytes have been input into the actual AES
     * operation, so we can unset aes_remaining_bytes in case a finish step
     * requires running a secondary AES operation.
     */
    P_CC3XX->aes.aes_remaining_bytes = 0x0U;

    /* Get the size before any tag is produced */
    if (size != NULL) {
        *size = cc3xx_lowlevel_aes_get_current_output_size();
    }

    switch (aes_state.mode) {
#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    case CC3XX_AES_MODE_GCM:
        err = gcm_finish(tag);
        break;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#ifdef CC3XX_CONFIG_AES_CMAC_ENABLE
    case CC3XX_AES_MODE_CMAC:
        err = cmac_finish(tag);
        break;
#endif /* CC3XX_CONFIG_AES_CMAC_ENABLE */
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    case CC3XX_AES_MODE_CCM:
        err = ccm_finish(tag);
        break;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */
    default:
        break;
    }

    cc3xx_lowlevel_aes_uninit();

    return err;
}

void cc3xx_lowlevel_aes_uninit(void)
{
    static const uint32_t zero_block[AES_BLOCK_SIZE / sizeof(uint32_t)] = {0};
    memset(&aes_state, 0, sizeof(struct cc3xx_aes_state_t));

    set_iv(zero_block);
    set_ctr(zero_block);

    cc3xx_lowlevel_dma_uninit();

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    cc3xx_lowlevel_hash_uninit();
    P_CC3XX->ghash.ghash_iv_0[0] = 0;
    P_CC3XX->ghash.ghash_iv_0[1] = 0;
    P_CC3XX->ghash.ghash_iv_0[2] = 0;
    P_CC3XX->ghash.ghash_iv_0[3] = 0;
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */

    /* Reset AES_CTRL */
    P_CC3XX->aes.aes_control = 0x0U;

    /* Set the crypto engine back to the default PASSTHROUGH engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_NONE);

    /* Disable the AES clock */
    P_CC3XX->misc.aes_clk_enable = 0x0U;
}

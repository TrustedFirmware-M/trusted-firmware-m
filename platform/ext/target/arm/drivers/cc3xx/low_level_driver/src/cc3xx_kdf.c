/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_kdf.h"

#include "cc3xx_rng.h"
#include "cc3xx_stdlib.h"

#include <assert.h>

#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)

cc3xx_err_t cc3xx_lowlevel_kdf_cmac(
    cc3xx_aes_key_id_t key_id, const uint32_t *key,
    cc3xx_aes_keysize_t key_size,
    const uint8_t *label, size_t label_length,
    const uint8_t *context, size_t context_length,
    uint32_t *output_key, size_t out_length)
{
    /* [L]2 is encoded as the length in bits, in binary. Safely assumes processor is LE */
    const size_t out_length_bits = 8 * out_length;
    const uint8_t l_total_length[] = {
        (out_length_bits >> 24) & 0xFF,
        (out_length_bits >> 16) & 0xFF,
        (out_length_bits >> 8) & 0xFF,
         out_length_bits & 0xFF};
    const uint8_t null_byte = 0;
    const size_t num_blocks = ROUND_UP(out_length, AES_TAG_MAX_LEN) / AES_TAG_MAX_LEN;
    const size_t unaligned_block_size = out_length % AES_TAG_MAX_LEN;
    uint32_t k0[AES_TAG_MAX_LEN / sizeof(uint32_t)];
    cc3xx_err_t err;

    /* Check alignment */
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    assert(((uintptr_t)output_key & 0b11) == 0);
#endif
    /* AES CMAC output tag is copied in words */
    assert((out_length % sizeof(uint32_t)) == 0);

    err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, CC3XX_AES_MODE_CMAC,
                                  key_id, key, key_size, NULL, 0);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    /* Pre-erase buffer with random values as a DPA countermeasure */
    cc3xx_secure_erase_buffer(k0, sizeof(k0) / sizeof(uint32_t));
#endif

    cc3xx_lowlevel_aes_set_tag_len(AES_TAG_MAX_LEN);

    /* K(0) = PRF(K_in, Label || 0x00 || Context || [L]2) */
    cc3xx_lowlevel_aes_update_authed_data(label, label_length);
    cc3xx_lowlevel_aes_update_authed_data(&null_byte, sizeof(null_byte));
    cc3xx_lowlevel_aes_update_authed_data(context, context_length);
    cc3xx_lowlevel_aes_update_authed_data(l_total_length, sizeof(l_total_length));

    cc3xx_lowlevel_aes_finish(k0, NULL);

    for (size_t idx = 0; idx < num_blocks; idx++) {
        const uint8_t *output_key_offset = ((uint8_t *) output_key) + idx * AES_TAG_MAX_LEN;
        const size_t aes_tag_size = ((idx == num_blocks - 1) && (unaligned_block_size > 0)) ?
                                    unaligned_block_size : AES_TAG_MAX_LEN;
        /* [i]2 is encoded on 4 bytes, i.e. r = 32, in binary. Assumes processor is LE */
        const size_t i_idx = idx + 1;
        const uint8_t i_encoded[] = {
            (i_idx >> 24) & 0xFF,
            (i_idx >> 16) & 0xFF,
            (i_idx >> 8) & 0xFF,
            i_idx & 0xFF};

        err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, CC3XX_AES_MODE_CMAC,
                                      key_id, key, key_size, NULL, 0);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }

        cc3xx_lowlevel_aes_set_tag_len(aes_tag_size);

        /* K(i) = PRF(K_in, [i]2 || Label || 0x00 || Context || [L]2 || K(0)) */
        cc3xx_lowlevel_aes_update_authed_data(i_encoded, sizeof(i_encoded));
        cc3xx_lowlevel_aes_update_authed_data(label, label_length);
        cc3xx_lowlevel_aes_update_authed_data(&null_byte, sizeof(null_byte));
        cc3xx_lowlevel_aes_update_authed_data(context, context_length);
        cc3xx_lowlevel_aes_update_authed_data(l_total_length, sizeof(l_total_length));
        cc3xx_lowlevel_aes_update_authed_data((uint8_t *)k0, sizeof(k0));

        cc3xx_lowlevel_aes_finish((void *) output_key_offset, NULL);
    }

    err = CC3XX_ERR_SUCCESS;

out:
    cc3xx_secure_erase_buffer(k0, sizeof(k0) / sizeof(uint32_t));

    if (err != CC3XX_ERR_SUCCESS) {
        cc3xx_secure_erase_buffer(output_key, out_length / sizeof(uint32_t));
    }

    return err;
}

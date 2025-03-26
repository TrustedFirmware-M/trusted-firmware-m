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

cc3xx_err_t cc3xx_lowlevel_kdf_cmac(
    cc3xx_aes_key_id_t key_id, const uint32_t *key,
    cc3xx_aes_keysize_t key_size,
    const uint8_t *label, size_t label_length,
    const uint8_t *context, size_t context_length,
    uint32_t *output_key, size_t out_length)
{
    uint32_t i_idx = 1;
    /* [L]2 is encoded as the length in bits, in binary. Safely assumes processor is LE */
    const uint8_t l_total_length[] = {
        ((8 * out_length) >> 24) & 0xFF,
        ((8 * out_length) >> 16) & 0xFF,
        ((8 * out_length) >> 8) & 0xFF,
        (8 * out_length) & 0xFF};
    const uint8_t null_byte = 0;
    cc3xx_err_t err;
    const size_t block_output_size = AES_TAG_MAX_LEN;
    uint32_t k0[block_output_size / sizeof(uint32_t)];
    size_t output_idx;

    /* Check alignment */
#ifdef CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT
    assert(((uintptr_t)output_key & 0b11) == 0);
#endif
    assert((out_length / block_output_size) != 0);

    err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, CC3XX_AES_MODE_CMAC,
                                  key_id, key, key_size, NULL, 0);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    /* Pre-erase buffer with random values as a DPA countermeasure */
    cc3xx_secure_erase_buffer(k0, sizeof(k0) / sizeof(uint32_t));
#endif

    cc3xx_lowlevel_aes_set_tag_len(block_output_size);

    /* K(0) = PRF(K_in, Label || 0x00 || Context || [L]2) */
    cc3xx_lowlevel_aes_update_authed_data(label, label_length);
    cc3xx_lowlevel_aes_update_authed_data(&null_byte, sizeof(null_byte));
    cc3xx_lowlevel_aes_update_authed_data(context, context_length);
    cc3xx_lowlevel_aes_update_authed_data(l_total_length, sizeof(l_total_length));

    cc3xx_lowlevel_aes_finish(k0, NULL);

    for(output_idx = 0; output_idx < out_length; output_idx += block_output_size) {
        /* [i]2 is encoded on 4 bytes, i.e. r = 32, in binary. Assumes processor is LE */
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

        cc3xx_lowlevel_aes_set_tag_len(AES_TAG_MAX_LEN);

        /* K(i) = PRF(K_in, [i]2 || Label || 0x00 || Context || [L]2 || K(0)) */
        cc3xx_lowlevel_aes_update_authed_data(i_encoded, sizeof(i_encoded));
        cc3xx_lowlevel_aes_update_authed_data(label, label_length);
        cc3xx_lowlevel_aes_update_authed_data(&null_byte, sizeof(null_byte));
        cc3xx_lowlevel_aes_update_authed_data(context, context_length);
        cc3xx_lowlevel_aes_update_authed_data(l_total_length, sizeof(l_total_length));
        cc3xx_lowlevel_aes_update_authed_data((uint8_t *)k0, sizeof(k0));

        cc3xx_lowlevel_aes_finish((void *)output_key + output_idx, NULL);
        i_idx += 1;
    }

    err = CC3XX_ERR_SUCCESS;

out:
    cc3xx_secure_erase_buffer(k0, sizeof(k0) / sizeof(uint32_t));

    if (err != CC3XX_ERR_SUCCESS) {
        cc3xx_secure_erase_buffer(output_key, out_length / sizeof(uint32_t));
    }

    return err;
}

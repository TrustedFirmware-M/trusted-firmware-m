/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Original code taken from mcuboot project at:
 * https://github.com/mcu-tools/mcuboot
 * Git SHA of the original version: ac55554059147fff718015be9f4bd3108123f50a
 * Modifications are Copyright (c) 2019-2025 Arm Limited.
 */

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <bootutil/sign_key.h>
#include "mcuboot_config/mcuboot_config.h"
#include "tfm_plat_rotpk.h"
#include "tfm_plat_crypto_keys.h"
#include "tfm_plat_otp.h"
#include "psa/crypto.h"

#if defined(MCUBOOT_ENCRYPT_RSA)
/* Generated from MCUBOOT_KEY_ENC with "imgtool getpriv" at build time */
extern const unsigned char enc_priv_key[];
extern const unsigned int enc_priv_key_len;

const struct bootutil_key bootutil_enc_key = {
    /*
     * The casts are needed with MCUBOOT_HW_KEY, where the members of
     * struct bootutil_key are declared without const. The key is only
     * read by MCUboot, the generated data can stay in read-only memory.
     */
    .key = (uint8_t *)enc_priv_key,
    .len = (unsigned int *)&enc_priv_key_len,
};

#else
/* Generated from MCUBOOT_KEY_ENC and MCUBOOT_KEY_ENC_NS at build time */
extern const unsigned char enc_key_s[];
extern const unsigned char enc_key_ns[];
extern const unsigned int enc_key_len;

const struct bootutil_key bootutil_enc_key = {
    /*
     * The casts are needed with MCUBOOT_HW_KEY, where the members of
     * struct bootutil_key are declared without const. The key is only
     * read by MCUboot, the generated data can stay in read-only memory.
     */
    .key = (uint8_t *)enc_key_ns,
    .len = (unsigned int *)&enc_key_len,
};

uint32_t get_enc_key_id_for_image(uint32_t image_id)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_id_t key = 0;
    psa_key_attributes_t attributes;

    psa_set_key_bits(&attributes, PSA_BYTES_TO_BITS(enc_key_len));
    psa_set_key_lifetime(&attributes, PSA_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
        PSA_KEY_PERSISTENCE_DEFAULT, PSA_KEY_LOCATION_LOCAL_STORAGE));
    psa_set_key_type(&attributes, PSA_KEY_TYPE_AES);
    psa_set_key_usage_flags(&attributes, (PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT));
    psa_set_key_algorithm(&attributes, PSA_ALG_ECB_NO_PADDING);

    if (image_id == 0) {
        status = psa_import_key(&attributes, enc_key_s, enc_key_len, &key);
    } else {
        status = psa_import_key(&attributes, enc_key_ns, enc_key_len, &key);
    }
    if (status != PSA_SUCCESS) {
            return PSA_KEY_ID_NULL;
    }

    return key;
}
#endif

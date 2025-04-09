/*
 * Copyright (c) 2023 Nordic Semiconductor ASA.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <string.h>

#include "config_tfm.h"
#include "platform/include/tfm_hal_its_encryption.h"
#include "platform/include/tfm_hal_its.h"

typedef uint64_t psa_drv_slot_number_t;
#include <hw_unique_key.h>
#include <cracen_psa.h>


#define CHACHA20_KEY_SIZE 32
#define TFM_ITS_AEAD_ALG PSA_ALG_CHACHA20_POLY1305


/* Global encryption counter which resets per boot. The counter ensures that
 * the nonce will not be identical for consecutive file writes during the same
 * boot.
 */
static uint32_t g_enc_counter;

/* The global nonce seed which is fetched once in every boot. The seed is used
 * as part of the nonce and allows the platforms to diversify their nonces
 * across resets. Note that the way that this seed is generated is platform
 * specific, so the diversification is optional.
 */
static uint8_t g_enc_nonce_seed[TFM_ITS_ENC_NONCE_LENGTH -
                                sizeof(g_enc_counter)];

/* TFM_ITS_ENC_NONCE_LENGTH is configurable but this implementation expects
 * the seed to be 8 bytes and the nonce length to be 12.
 */
#if TFM_ITS_ENC_NONCE_LENGTH != 12
#error "This implementation only supports a ITS nonce of size 12"
#endif

/*
 * This implementation doesn't use monotonic counters, but therfore a 64 bit
 * seed combined with a counter, that gets reset on each reboot.
 * This still has the risk of getting a collision on the seed resulting in
 * nonce's beeing the same after a reboot.
 * It would still need 3.3x10^9 resets to get a collision with a probability of
 * 0.25.
 */
enum tfm_hal_status_t tfm_hal_its_aead_generate_nonce(uint8_t *nonce,
                                                      const size_t nonce_size)
{
    if(nonce == NULL){
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if(nonce_size < sizeof(g_enc_nonce_seed) + sizeof(g_enc_counter)){
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* To avoid wrap-around of the g_enc_counter and subsequent re-use of the
     * nonce we check the counter value for its max value
     */
    if(g_enc_counter ==  UINT32_MAX) {
        return TFM_HAL_ERROR_GENERIC;
    }

    if (g_enc_counter == 0) {
        psa_status_t status =  cracen_get_random(NULL, g_enc_nonce_seed, sizeof(g_enc_nonce_seed));
        if (status != PSA_SUCCESS) {
            return TFM_HAL_ERROR_GENERIC;
        }
    }

    memcpy(nonce, g_enc_nonce_seed, sizeof(g_enc_nonce_seed));
    memcpy(nonce + sizeof(g_enc_nonce_seed),
               &g_enc_counter,
               sizeof(g_enc_counter));

    g_enc_counter++;

    return TFM_HAL_SUCCESS;
}

static bool ctx_is_valid(struct tfm_hal_its_auth_crypt_ctx *ctx)
{
    bool ret;

    if (ctx == NULL) {
        return false;
    }

    ret = (ctx->deriv_label == NULL && ctx->deriv_label_size != 0) ||
          (ctx->aad == NULL && ctx->aad_size != 0) ||
          (ctx->nonce == NULL && ctx->nonce_size != 0);

    return !ret;
}

psa_status_t tfm_hal_its_get_aead(struct tfm_hal_its_auth_crypt_ctx *ctx,
                                  const uint8_t *input,
                                  const size_t input_size,
                                  uint8_t *output,
                                  const size_t output_size,
                                  uint8_t *tag,
                                  const size_t tag_size,
                                  bool encrypt)
{
    psa_status_t status;
    uint8_t key_out[CHACHA20_KEY_SIZE];
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    cracen_aead_operation_t operation = {0};
    size_t out_length;
    size_t tag_length = PSA_AEAD_TAG_LENGTH(PSA_KEY_TYPE_CHACHA20,
                                            PSA_BYTES_TO_BITS(CHACHA20_KEY_SIZE),
                                            TFM_ITS_AEAD_ALG);

    if (!ctx_is_valid(ctx) || tag == NULL) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if(tag_size < tag_length){
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    if (encrypt && (output_size < PSA_AEAD_UPDATE_OUTPUT_SIZE(PSA_KEY_TYPE_CHACHA20,
                                                               TFM_ITS_AEAD_ALG,
                                                               input_size))){
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    status = hw_unique_key_derive_key(HUK_KEYSLOT_MKEK, NULL, 0, ctx->deriv_label, ctx->deriv_label_size, key_out, sizeof(key_out));
    if (status != HW_UNIQUE_KEY_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    psa_set_key_usage_flags(&attributes, (PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT));
    psa_set_key_algorithm(&attributes, TFM_ITS_AEAD_ALG);
    psa_set_key_type(&attributes, PSA_KEY_TYPE_CHACHA20);
    psa_set_key_bits(&attributes, PSA_BYTES_TO_BITS(CHACHA20_KEY_SIZE));

    if (encrypt) {
        status = cracen_aead_encrypt_setup(&operation, &attributes, key_out, sizeof(key_out), TFM_ITS_AEAD_ALG);
    } else {
        status = cracen_aead_decrypt_setup(&operation, &attributes, key_out, sizeof(key_out), TFM_ITS_AEAD_ALG);
    }

    if (status != PSA_SUCCESS) {
        return status;
    }

    status = cracen_aead_set_nonce(&operation, ctx->nonce, ctx->nonce_size);
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = cracen_aead_update_ad(&operation, ctx->aad, ctx->aad_size);
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = cracen_aead_update(&operation, input, input_size, output, output_size, &out_length);
    if (status != PSA_SUCCESS) {
        return status;
    }

    if (encrypt) {
        status = cracen_aead_finish(&operation, output + out_length, output_size - out_length, &out_length, tag, tag_size, &tag_length);
    } else {
        status = cracen_aead_verify(&operation, output + out_length, output_size - out_length, &out_length , tag, tag_size);
    }

    return status;
}

enum tfm_hal_status_t tfm_hal_its_aead_encrypt(struct tfm_hal_its_auth_crypt_ctx *ctx,
                                               const uint8_t *plaintext,
                                               const size_t plaintext_size,
                                               uint8_t *ciphertext,
                                               const size_t ciphertext_size,
                                               uint8_t *tag,
                                               const size_t tag_size)
{
    psa_status_t status = tfm_hal_its_get_aead(ctx,
                                               plaintext,
                                               plaintext_size,
                                               ciphertext,
                                               ciphertext_size,
                                               tag,
                                               tag_size,
                                               true);
    if (status != PSA_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    return TFM_HAL_SUCCESS;
}

enum tfm_hal_status_t tfm_hal_its_aead_decrypt(struct tfm_hal_its_auth_crypt_ctx *ctx,
                                               const uint8_t *ciphertext,
                                               const size_t ciphertext_size,
                                               uint8_t *tag,
                                               const size_t tag_size,
                                               uint8_t *plaintext,
                                               const size_t plaintext_size)
{
    psa_status_t status = tfm_hal_its_get_aead(ctx,
                                               ciphertext,
                                               ciphertext_size,
                                               plaintext,
                                               plaintext_size,
                                               tag,
                                               tag_size,
                                               false);

    if (status != PSA_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    return TFM_HAL_SUCCESS;
}

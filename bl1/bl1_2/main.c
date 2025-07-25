/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>

#include "crypto.h"
#include "otp.h"
#include "boot_hal.h"
#include "psa/crypto.h"
#include "uart_stdout.h"
#include "fih.h"
#include "util.h"
#include "tfm_log.h"
#include "image.h"
#include "region_defs.h"
#include "pq_crypto.h"
#include "tfm_plat_nv_counters.h"
#include "tfm_plat_otp.h"

#ifdef TFM_MEASURED_BOOT_API
#include "tfm_boot_measurement.h"
#else
enum boot_measurement_slot_t {
    BOOT_MEASUREMENT_SLOT_BL2,
};
#endif

#if defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
#include "bl1_2_suites.h"
#endif /* defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

/* Disable both semihosting code and argv usage for main */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__asm("  .global __ARM_use_no_argv\n");
#endif

#ifdef TFM_MEASURED_BOOT_API
static fih_ret submit_boot_measurement(const struct bl1_2_image_t *image,
                                       uint8_t *rotpk_hash, size_t rotpk_hash_size,
                                       uint8_t *measurement_hash, size_t measurement_hash_size,
                                       enum boot_measurement_slot_t slot)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);;

    struct boot_measurement_metadata bl2_metadata = {
        .measurement_type = TFM_BL1_2_MEASUREMENT_HASH_ALG,
        .signer_id = { 0 },
        .signer_id_size = measurement_hash_size,
        .sw_type = "BL2",
        .sw_version = {
            image->protected_values.version.major,
            image->protected_values.version.minor,
            image->protected_values.version.revision,
            image->protected_values.version.build_num,
        },
    };

    if (sizeof(bl2_metadata.signer_id) < rotpk_hash_size) {
        FIH_RET(FIH_FAILURE);
    }

    /* Use the ROTPK hash as the signer ID */
    memcpy(bl2_metadata.signer_id, rotpk_hash, rotpk_hash_size);

    /* Save the boot measurement of the BL2 image. */
    fih_rc = fih_ret_encode_zero_equality(boot_store_measurement(slot,
                                                                 measurement_hash,
                                                                 measurement_hash_size,
                                                                 &bl2_metadata, true));
    FIH_RET(fih_rc);
}
#endif /* TFM_MEASURED_BOOT_API */

static fih_ret is_image_security_counter_valid(struct bl1_2_image_t *img)
{
    uint32_t security_counter;
    FIH_DECLARE(fih_rc, FIH_FAILURE);;
    enum tfm_plat_err_t plat_err;

    plat_err = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_BL1_0,
                                        sizeof(security_counter),
                                        (uint8_t *)&security_counter);
    fih_rc = fih_ret_encode_zero_equality(plat_err);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* Encodes 0 to true and 1 to false, so the actual comparison is flipped */
    FIH_RET(
        fih_ret_encode_zero_equality(security_counter
                                     > img->protected_values.security_counter));
}

static fih_ret validate_image_signature(struct bl1_2_image_t *img,
                                        struct tfm_bl1_image_signature_t *sig,
                                        enum tfm_bl1_key_id_t key_id,
                                        uint8_t *measurement_hash,
                                        size_t measurement_hash_size,
                                        enum boot_measurement_slot_t measurement_slot)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    uint8_t rotpk[TFM_BL1_2_ROTPK_MAX_SIZE];
    uint8_t *p_rotpk = rotpk;
    size_t rotpk_size;
    uint8_t rotpk_hash[TFM_BL1_2_ROTPK_HASH_MAX_SIZE];
    enum tfm_bl1_key_type_t key_type;
    enum tfm_bl1_hash_alg_t key_hash_alg;


    if (sig->sig_len > sizeof(sig->sig)) {
        ERROR("Invalid signature length\n");
        FIH_RET(FIH_FAILURE);
    }

    assert(TFM_BL1_2_ROTPK_MAX_SIZE >= TFM_BL1_2_ROTPK_HASH_MAX_SIZE);

    FIH_CALL(bl1_otp_read_key, fih_rc, key_id, rotpk, sizeof(rotpk), &rotpk_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("ROTPK not provisioned\n");
        FIH_RET(fih_rc);
    }

#ifdef TFM_BL1_2_EMBED_ROTPK_IN_IMAGE
    if (rotpk_size > TFM_BL1_2_ROTPK_HASH_MAX_SIZE) {
        ERROR("Image ROTPK hash size mismatch\n");
        FIH_RET(FIH_FAILURE);
    }

#if defined(TFM_BL1_ENABLE_SHA256) && defined(TFM_BL1_ENABLE_SHA384)
    FIH_CALL(bl1_otp_get_key_hash_alg, fih_rc, key_id, &key_hash_alg);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Key type lookup failure\n");
        FIH_RET(fih_rc);
    }
#elif defined(TFM_BL1_ENABLE_SHA256)
    key_hash_alg = TFM_BL1_HASH_ALG_SHA256;
#elif defined(TFM_BL1_ENABLE_SHA384)
    key_hash_alg = TFM_BL1_HASH_ALG_SHA384;
#else
    #error No TFM_BL1_2 ROTPK hash algorithms enabled
#endif

    FIH_CALL(bl1_hash_compute, fih_rc, key_hash_alg,
                                       sig->rotpk, sig->rotpk_len,
                                       rotpk_hash, sizeof(rotpk_hash), NULL);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Hash function failure\n");
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl_fih_memeql, fih_rc, rotpk, rotpk_hash, rotpk_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Image ROTPK hash mismatch\n");
        FIH_RET(fih_rc);
    }

    p_rotpk = sig->rotpk;
    rotpk_size = sig->rotpk_len;
#endif /* TFM_BL1_2_EMBED_ROTPK_IN_IMAGE */

#if defined(TFM_BL1_2_ENABLE_ECDSA) && defined(TFM_BL1_2_ENABLE_LMS)
    FIH_CALL(bl1_otp_get_key_type, fih_rc, key_id, &key_type);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Key type lookup failure\n");
        FIH_RET(fih_rc);
    }
#elif defined(TFM_BL1_2_ENABLE_ECDSA)
    key_type = TFM_BL1_KEY_TYPE_ECDSA;
#elif defined(TFM_BL1_2_ENABLE_LMS)
    key_type = TFM_BL1_KEY_TYPE_LMS;
#else
    #error No TFM_BL1_2 authenication methods enabled
#endif

    switch(key_type) {
    case TFM_BL1_KEY_TYPE_ECDSA:
#ifdef TFM_BL1_2_ENABLE_ECDSA
        FIH_CALL(bl1_ecdsa_verify, fih_rc, TFM_BL1_2_ECDSA_CURVE,
                                           p_rotpk, rotpk_size,
                                           measurement_hash,
                                           measurement_hash_size,
                                           sig->sig,
                                           sig->sig_len);
        break;
#else
        ERROR("ECDSA key type but ECDSA support not enabled\n");
        FIH_RET(FIH_FAILURE);
#endif
    case TFM_BL1_KEY_TYPE_LMS:
#ifdef TFM_BL1_2_ENABLE_LMS
        FIH_CALL(pq_crypto_verify, fih_rc, p_rotpk, rotpk_size,
                                           (uint8_t *)&img->protected_values,
                                           sizeof(img->protected_values),
                                           sig->sig,
                                           sig->sig_len);
        break;
#else
        ERROR("LMS key type but LMS support not enabled\n");
        FIH_RET(FIH_FAILURE);
#endif
    default:
        ERROR("Unknown key type\n");
        FIH_RET(FIH_FAILURE);
    }

    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Signature validation failed\n");
        FIH_RET(FIH_FAILURE);
    }

#ifdef TFM_MEASURED_BOOT_API
    /* At this point there is a valid and decrypted BL2 image in the RAM at
     * address BL2_IMAGE_START.
     */
#if !defined(TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
    FIH_CALL(bl1_hash_compute, fih_rc, key_hash_alg,
                                       p_rotpk, rotpk_size,
                                       rotpk_hash, sizeof(rotpk_hash),
                                       NULL);
#endif
    FIH_CALL(submit_boot_measurement, fih_rc, img, rotpk_hash, sizeof(rotpk_hash),
                                              measurement_hash, measurement_hash_size,
                                              measurement_slot);
#endif /* TFM_MEASURED_BOOT_API */

    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

#ifdef TFM_BL1_2_ENABLE_ROTPK_POLICIES
static fih_ret check_key_policy(fih_int validate_rc,
                                enum tfm_bl1_key_id_t key_id,
                                bool *key_might_sign, bool *key_must_sign)
{
    enum tfm_bl1_key_policy_t policy;
    FIH_DECLARE(fih_rc, FIH_FAILURE);;

    FIH_CALL(bl1_otp_get_key_policy, fih_rc, TFM_BL1_KEY_ROTPK_0, &policy);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    if (fih_eq(validate_rc, FIH_SUCCESS)) {
        if (policy == TFM_BL1_KEY_MIGHT_SIGN) {
            *key_might_sign |= fih_eq(fih_rc, FIH_SUCCESS);
        } else {
            *key_might_sign |= fih_eq(fih_rc, FIH_SUCCESS);
            *key_must_sign  &= fih_eq(fih_rc, FIH_SUCCESS);
        }
    }

    FIH_RET(FIH_SUCCESS);
}
#endif

static fih_ret is_image_signature_valid(struct bl1_2_image_t *img)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    static uint8_t measurement_hash[TFM_BL1_2_MEASUREMENT_HASH_MAX_SIZE];
    static size_t measurement_hash_size;
    uint32_t idx;
#ifdef TFM_BL1_2_ENABLE_ROTPK_POLICIES
    bool key_must_sign  = true;
    bool key_might_sign = false;
#endif

    /* Calculate the image hash for measured boot */
    FIH_CALL(bl1_hash_compute, fih_rc, TFM_BL1_2_MEASUREMENT_HASH_ALG,
                                       (uint8_t *)&img->protected_values,
                                       sizeof(img->protected_values),
                                       measurement_hash, sizeof(measurement_hash),
                                       &measurement_hash_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("Boot measurement failed\n");
        FIH_RET(fih_rc);
    }

    for (idx = 0; idx < TFM_BL1_2_SIGNER_AMOUNT; idx++) {
        FIH_CALL(validate_image_signature, fih_rc, img,
                                                   &img->header.sigs[idx],
                                                   TFM_BL1_KEY_ROTPK_0 + idx,
                                                   measurement_hash, measurement_hash_size,
                                                   BOOT_MEASUREMENT_SLOT_BL2);
#ifdef TFM_BL1_2_ENABLE_ROTPK_POLICIES
        fih_rc = check_key_policy(fih_rc, TFM_BL1_KEY_ROTPK_0, &key_might_sign, &key_must_sign);
#endif
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            FIH_RET(fih_rc);
        }
    }

#ifdef TFM_BL1_2_ENABLE_ROTPK_POLICIES
    if (FIH_NOT_EQ(key_must_sign, true) || FIH_NOT_EQ(key_might_sign, true)) {
        FIH_RET(FIH_FAILURE);
    }
#endif

    FIH_RET(FIH_SUCCESS);
}

#ifndef TEST_BL1_2
static
#endif
fih_ret bl1_2_validate_image_at_addr(struct bl1_2_image_t *image)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    FIH_CALL(is_image_signature_valid, fih_rc, image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image signature failed to validate\n");
        FIH_RET(fih_rc);
    }

    FIH_CALL(is_image_security_counter_valid, fih_rc, image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image security_counter failed to validate\n");
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
#ifndef TEST_BL1_2
static
#endif
fih_ret copy_and_decrypt_image(uint32_t image_id, struct bl1_2_image_t *image)
{
    struct bl1_2_image_t *image_to_decrypt;
    uint32_t key_buf[32 / sizeof(uint32_t)];
    uint8_t label[] = "BL2_DECRYPTION_KEY";
    FIH_DECLARE(fih_rc, FIH_FAILURE);

#ifdef TFM_BL1_MEMORY_MAPPED_FLASH
    /* If we have memory-mapped flash, we can do the decrypt directly from the
     * flash and output to the SRAM. This is significantly faster if the AES
     * invocation calls through to a crypto accelerator with a DMA, and slightly
     * faster otherwise.
     */
    image_to_decrypt = (struct bl1_2_image_t *)(FLASH_BL1_BASE_ADDRESS +
                       bl1_image_get_flash_offset(image_id));

    /* Copy everything that isn't encrypted, to prevent TOCTOU attacks and
     * simplify logic.
     */
    memcpy(image, image_to_decrypt, sizeof(struct bl1_2_image_t) -
           sizeof(image->protected_values.encrypted_data));
#else
    /* If the flash isn't memory-mapped, defer to the flash driver to copy the
     * entire block in to SRAM. We'll then do the decrypt in-place.
     */
    FIH_CALL(bl1_image_copy_to_sram, fih_rc, image_id, (uint8_t *)image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }
    image_to_decrypt = image;
#endif /* TFM_BL1_MEMORY_MAPPED_FLASH */

    /* As the security counter is an attacker controlled parameter, bound the
     * values to a sensible range. In this case, we choose 1024 as the bound as
     * it is the same as the max amount of signatures as a H=10 LMS key.
     */
    if (image->protected_values.security_counter >= 1024) {
        FIH_RET(FIH_FAILURE);
    }

    /* The image security counter is used as a KDF input */
    FIH_CALL(bl1_derive_key, fih_rc, TFM_BL1_KEY_BL2_ENCRYPTION, label, sizeof(label),
                        (uint8_t *)&image->protected_values.security_counter,
                        sizeof(image->protected_values.security_counter),
                        key_buf, sizeof(key_buf));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl1_aes_256_ctr_decrypt, fih_rc, TFM_BL1_KEY_USER, (uint8_t *)key_buf,
                                 image->header.ctr_iv,
                                 (uint8_t *)&image_to_decrypt->protected_values.encrypted_data,
                                 sizeof(image->protected_values.encrypted_data),
                                 (uint8_t *)&image->protected_values.encrypted_data);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    if (image->protected_values.encrypted_data.decrypt_magic
            != TFM_BL1_2_IMAGE_DECRYPT_MAGIC_EXPECTED) {
        FIH_RET(FIH_FAILURE);
    }

    FIH_RET(FIH_SUCCESS);
}

#else /* TFM_BL1_2_IMAGE_ENCRYPTION */

fih_ret copy_image(uint32_t image_id, struct bl1_2_image_t *image)
{
    struct bl1_2_image_t *image_to_copy;

#ifdef TFM_BL1_MEMORY_MAPPED_FLASH
    image_to_copy = (struct bl1_2_image_t *)(FLASH_BL1_BASE_ADDRESS +
                       bl1_image_get_flash_offset(image_id));

    memcpy(image, image_to_copy, BL2_CODE_SIZE + BL2_HEADER_SIZE);
#else
    bl1_image_copy_to_sram(image_id, (uint8_t *)image);
#endif /* TFM_BL1_MEMORY_MAPPED_FLASH */

    FIH_RET(FIH_SUCCESS);
}

#endif /* TFM_BL1_2_IMAGE_ENCRYPTION */

static fih_ret bl1_2_validate_image(uint32_t image_id)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    struct bl1_2_image_t *image =
        (struct bl1_2_image_t *)(BL2_CODE_START -
                                 offsetof(struct bl1_2_image_t, protected_values.encrypted_data.data));

#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
    FIH_CALL(copy_and_decrypt_image, fih_rc, image_id, image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image failed to decrypt\n");
        FIH_RET(fih_rc);
    }

    INFO("BL2 image decrypted successfully\n");
#else
    FIH_CALL(copy_image, fih_rc, image_id, image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image failed to decrypt\n");
        FIH_RET(fih_rc);
    }

    INFO("BL2 image copied successfully\n");
#endif

    FIH_CALL(bl1_2_validate_image_at_addr, fih_rc, image);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image failed to validate\n");
        FIH_RET(fih_rc);
    }

    INFO("BL2 image validated successfully\n");

    FIH_RET(FIH_SUCCESS);
}

int main(void)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    FIH_DECLARE(recovery_succeeded, FIH_FAILURE);
    uint32_t image_id = 0xFFFF;

    fih_rc = fih_ret_encode_zero_equality(boot_platform_init());
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
        FIH_PANIC;
    }
    INFO("Starting TF-M BL1_2\n");

#if defined(TEST_BL1_2) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
    run_bl1_2_testsuite();
#endif /* defined(TEST_BL1_2) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

    fih_rc = fih_ret_encode_zero_equality(boot_platform_post_init());
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
        FIH_PANIC;
    }

    do {
        FIH_CALL(bl1_2_select_image, image_id);

        INFO("Attempting to boot image %d\n", image_id);

        fih_rc = fih_ret_encode_zero_equality(
                    boot_platform_pre_load(image_id));
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            boot_platform_error_state(fih_rc);
            FIH_PANIC;
        }

        FIH_CALL(bl1_2_validate_image, fih_rc, image_id);

        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            FIH_CALL(bl1_2_rollback_image, image_id);

            INFO("Attempting to boot image %d\n", image_id);

            fih_rc = fih_ret_encode_zero_equality(
                        boot_platform_pre_load(image_id));
            if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
                boot_platform_error_state(fih_rc);
                FIH_PANIC;
            }

            FIH_CALL(bl1_2_validate_image, fih_rc, image_id);
        }

        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            recovery_succeeded = fih_ret_encode_zero_equality(boot_initiate_recovery_mode(0));
            if (FIH_NOT_EQ(recovery_succeeded, FIH_SUCCESS)) {
                boot_platform_error_state(recovery_succeeded);
                FIH_PANIC;
            }
        }
    } while (FIH_NOT_EQ(fih_rc, FIH_SUCCESS));

    fih_rc = fih_ret_encode_zero_equality(boot_platform_post_load(0));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
        FIH_PANIC;
    }

    INFO("Jumping to BL2\n");
    boot_platform_start_next_image((struct boot_arm_vector_table *)BL2_CODE_START);

    boot_platform_error_state(0);
    FIH_PANIC;
}

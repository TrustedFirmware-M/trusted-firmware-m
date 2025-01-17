/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>

#include "crypto.h"
#include "otp.h"
#include "boot_hal.h"
#ifdef TFM_MEASURED_BOOT_API
#include "boot_measurement.h"
#endif /* TFM_MEASURED_BOOT_API */
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

#if defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
#include "bl1_2_suites.h"
#endif /* defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

/* Disable both semihosting code and argv usage for main */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__asm("  .global __ARM_use_no_argv\n");
#endif

#if defined(TFM_MEASURED_BOOT_API) || !defined(TFM_BL1_PQ_CRYPTO)
static uint8_t computed_bl2_hash[BL2_HASH_SIZE];
#endif

#ifdef TFM_MEASURED_BOOT_API
#if (BL2_HASH_SIZE == 32)
#define BL2_HASH_ALG  PSA_ALG_SHA_256
#elif (BL2_HASH_SIZE == 64)
#define BL2_HASH_ALG  PSA_ALG_SHA_512
#else
#error "The specified BL2_HASH_SIZE is not supported with measured boot."
#endif /* BL2_HASH_SIZE */

static void collect_boot_measurement(const struct bl1_2_image_t *image)
{
    struct boot_measurement_metadata bl2_metadata = {
        .measurement_type = BL2_HASH_ALG,
        .signer_id = { 0 },
        .signer_id_size = BL2_HASH_SIZE,
        .sw_type = "BL2",
        .sw_version = {
            image->protected_values.version.major,
            image->protected_values.version.minor,
            image->protected_values.version.revision,
            image->protected_values.version.build_num,
        },
    };

#ifdef TFM_BL1_PQ_CRYPTO
    /* Get the public key hash as the signer ID */
    if (pq_crypto_get_pub_key_hash(TFM_BL1_KEY_ROTPK_0, bl2_metadata.signer_id,
                                   sizeof(bl2_metadata.signer_id),
                                   &bl2_metadata.signer_id_size)) {
        WARN("Signer ID missing in measurement of BL2\n");
    }
#endif

    /* Save the boot measurement of the BL2 image. */
    if (boot_store_measurement(BOOT_MEASUREMENT_SLOT_BL2, computed_bl2_hash,
                               BL2_HASH_SIZE, &bl2_metadata, true)) {
        WARN("Failed to store boot measurement of BL2\n");
    }
}
#endif /* TFM_MEASURED_BOOT_API */

#ifndef TFM_BL1_PQ_CRYPTO
static fih_int image_hash_check(struct bl1_2_image_t *img)
{
    enum tfm_plat_err_t plat_err;
    uint8_t stored_bl2_hash[BL2_HASH_SIZE];
    fih_int fih_rc = FIH_FAILURE;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL2_IMAGE_HASH, BL2_HASH_SIZE,
                                 stored_bl2_hash);
    fih_rc = fih_int_encode_zero_equality(plat_err);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl_fih_memeql, fih_rc, computed_bl2_hash, stored_bl2_hash,
                                    BL2_HASH_SIZE);
    FIH_RET(fih_rc);
}
#endif /* !TFM_BL1_PQ_CRYPTO */

static fih_int is_image_security_counter_valid(struct bl1_2_image_t *img)
{
    uint32_t security_counter;
    fih_int fih_rc;
    enum tfm_plat_err_t plat_err;

    plat_err = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_BL1_0,
                                        sizeof(security_counter),
                                        (uint8_t *)&security_counter);
    fih_rc = fih_int_encode_zero_equality(plat_err);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* Encodes 0 to true and 1 to false, so the actual comparison is flipped */
    FIH_RET(
        fih_int_encode_zero_equality(security_counter
                                     > img->protected_values.security_counter));
}

static fih_int is_image_signature_valid(struct bl1_2_image_t *img)
{
    fih_int fih_rc = FIH_FAILURE;

    /* Calculate the image hash for measured boot and/or a hash-locked image */
#if defined(TFM_MEASURED_BOOT_API) || !defined(TFM_BL1_PQ_CRYPTO)
    FIH_CALL(bl1_sha256_compute, fih_rc, (uint8_t *)&img->protected_values,
                                         sizeof(img->protected_values),
                                         computed_bl2_hash);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }
#endif

#ifdef TFM_BL1_PQ_CRYPTO
    FIH_CALL(pq_crypto_verify, fih_rc, TFM_BL1_KEY_ROTPK_0,
                                       (uint8_t *)&img->protected_values,
                                       sizeof(img->protected_values),
                                       img->header.sig,
                                       sizeof(img->header.sig));
#else
    FIH_CALL(image_hash_check, fih_rc, img);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }
#endif /* TFM_BL1_PQ_CRYPTO */

    FIH_RET(fih_rc);
}

#ifndef TEST_BL1_2
static
#endif
fih_int bl1_2_validate_image_at_addr(struct bl1_2_image_t *image)
{
    fih_int fih_rc = FIH_FAILURE;
    enum tfm_plat_err_t plat_err;

    FIH_CALL(is_image_signature_valid, fih_rc, image);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image signature failed to validate\n");
        FIH_RET(fih_rc);
    }
    FIH_CALL(is_image_security_counter_valid, fih_rc, image);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image security_counter failed to validate\n");
        FIH_RET(fih_rc);
    }

    /* TODO work out if the image actually boots before updating the counter */
    plat_err = tfm_plat_set_nv_counter(PLAT_NV_COUNTER_BL1_0,
                                       image->protected_values.security_counter);
    fih_rc = fih_int_encode_zero_equality(plat_err);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        ERROR("NV counter update failed\n");
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

#ifndef TEST_BL1_2
static
#endif
fih_int copy_and_decrypt_image(uint32_t image_id, struct bl1_2_image_t *image)
{
    int rc;
    struct bl1_2_image_t *image_to_decrypt;
    uint8_t key_buf[32];
    uint8_t label[] = "BL2_DECRYPTION_KEY";

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
    bl1_image_copy_to_sram(image_id, (uint8_t *)BL2_IMAGE_START);
    image_to_decrypt = (struct bl1_2_image_t *)BL2_IMAGE_START;
#endif /* TFM_BL1_MEMORY_MAPPED_FLASH */

    /* As the security counter is an attacker controlled parameter, bound the
     * values to a sensible range. In this case, we choose 1024 as the bound as
     * it is the same as the max amount of signatures as a H=10 LMS key.
     */
    if (image->protected_values.security_counter >= 1024) {
        FIH_RET(FIH_FAILURE);
    }

    /* The image security counter is used as a KDF input */
    rc = bl1_derive_key(TFM_BL1_KEY_BL2_ENCRYPTION, label, sizeof(label),
                        (uint8_t *)&image->protected_values.security_counter,
                        sizeof(image->protected_values.security_counter),
                        key_buf, sizeof(key_buf));
    if (rc) {
        FIH_RET(fih_int_encode_zero_equality(rc));
    }

    rc = bl1_aes_256_ctr_decrypt(TFM_BL1_KEY_USER, key_buf,
                                 image->header.ctr_iv,
                                 (uint8_t *)&image_to_decrypt->protected_values.encrypted_data,
                                 sizeof(image->protected_values.encrypted_data),
                                 (uint8_t *)&image->protected_values.encrypted_data);
    if (rc) {
        FIH_RET(fih_int_encode_zero_equality(rc));
    }

    if (image->protected_values.encrypted_data.decrypt_magic
            != BL1_2_IMAGE_DECRYPT_MAGIC_EXPECTED) {
        FIH_RET(FIH_FAILURE);
    }

    FIH_RET(FIH_SUCCESS);
}

static fih_int bl1_2_validate_image(uint32_t image_id)
{
    fih_int fih_rc = FIH_FAILURE;
    struct bl1_2_image_t *image = (struct bl1_2_image_t *)BL2_IMAGE_START;

    FIH_CALL(copy_and_decrypt_image, fih_rc, image_id, image);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image failed to decrypt\n");
        FIH_RET(fih_rc);
    }

    INFO("BL2 image decrypted successfully\n");

    FIH_CALL(bl1_2_validate_image_at_addr, fih_rc, image);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        ERROR("BL2 image failed to validate\n");
        FIH_RET(fih_rc);
    }

    INFO("BL2 image validated successfully\n");

    FIH_RET(FIH_SUCCESS);
}

int main(void)
{
    fih_int fih_rc = FIH_FAILURE;
    fih_int recovery_succeeded = FIH_FAILURE;

    fih_rc = fih_int_encode_zero_equality(boot_platform_init());
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_PANIC;
    }
    INFO("Starting TF-M bl1_2\n");

#if defined(TEST_BL1_2) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
    run_bl1_2_testsuite();
#endif /* defined(TEST_BL1_2) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

    fih_rc = fih_int_encode_zero_equality(boot_platform_post_init());
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_PANIC;
    }

    fih_rc = fih_int_encode_zero_equality(boot_platform_pre_load(0));
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_PANIC;
    }

    do {
        INFO("Attempting to boot image 0\n");
        FIH_CALL(bl1_2_validate_image, fih_rc, 0);

        if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
            INFO("Attempting to boot image 1\n");
            FIH_CALL(bl1_2_validate_image, fih_rc, 1);
        }

        if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
            recovery_succeeded = fih_int_encode_zero_equality(boot_initiate_recovery_mode(0));
            if (fih_not_eq(recovery_succeeded, FIH_SUCCESS)) {
                FIH_PANIC;
            }
        }
    } while (fih_not_eq(fih_rc, FIH_SUCCESS));

    fih_rc = fih_int_encode_zero_equality(boot_platform_post_load(0));
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        FIH_PANIC;
    }

#ifdef TFM_MEASURED_BOOT_API
    /* At this point there is a valid and decrypted BL2 image in the RAM at
     * address BL2_IMAGE_START.
     */
    collect_boot_measurement((const struct bl1_2_image_t *)BL2_IMAGE_START);
#endif /* TFM_MEASURED_BOOT_API */

    INFO("Jumping to BL2\n");
    boot_platform_start_next_image((struct boot_arm_vector_table *)BL2_CODE_START);

    FIH_PANIC;
}

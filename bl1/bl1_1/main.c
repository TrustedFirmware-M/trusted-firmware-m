/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "crypto.h"
#include "otp.h"
#include "tfm_plat_provisioning.h"
#include "tfm_plat_otp.h"
#include "boot_hal.h"
#ifdef TFM_MEASURED_BOOT_API
#include "tfm_boot_measurement.h"
#endif /* TFM_MEASURED_BOOT_API */
#include "region_defs.h"
#include "tfm_log.h"
#include "util.h"
#include "image.h"
#include "fih.h"
#include "bl1_1_config.h"

#if defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
#include "bl1_1_suites.h"
#endif /* defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

/* Disable both semihosting code and argv usage for main */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__asm("  .global __ARM_use_no_argv\n");
#endif

uint8_t computed_bl1_2_hash[TFM_BL1_1_MEASUREMENT_HASH_MAX_SIZE];
size_t computed_bl1_2_hash_size;

#ifdef TFM_MEASURED_BOOT_API
static void collect_boot_measurement(void)
{
    struct boot_measurement_metadata bl1_2_metadata = {
        .measurement_type = TFM_BL1_1_MEASUREMENT_HASH_ALG,
        .signer_id = { 0 },
        .signer_id_size = computed_bl1_2_hash_size,
        .sw_type = "BL1_2",
        .sw_version = { 0 },
    };

    /* Missing metadata:
     * - image version: not available,
     * - signer ID: the BL1_2 image is not signed.
     */
    if (boot_store_measurement(BOOT_MEASUREMENT_SLOT_BL1_2, computed_bl1_2_hash,
                               computed_bl1_2_hash_size, &bl1_2_metadata, true)) {
        WARN("Failed to store boot measurement of BL1_2\n");
    }
}
#endif /* TFM_MEASURED_BOOT_API */

#ifndef TEST_BL1_1
static
#endif
fih_ret bl1_1_validate_image_at_addr(const uint8_t *image)
{
    enum tfm_plat_err_t plat_err;
    uint8_t stored_bl1_2_hash[TFM_BL1_1_MEASUREMENT_HASH_MAX_SIZE];
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    FIH_CALL(bl1_hash_compute, fih_rc, TFM_BL1_1_MEASUREMENT_HASH_ALG,
                                       image, BL1_2_CODE_SIZE, computed_bl1_2_hash,
                                       sizeof(computed_bl1_2_hash),
                                       &computed_bl1_2_hash_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL1_2_IMAGE_HASH, sizeof(stored_bl1_2_hash),
                                 stored_bl1_2_hash);
    fih_rc = fih_ret_encode_zero_equality(plat_err);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(bl_fih_memeql, fih_rc, computed_bl1_2_hash,
                                    stored_bl1_2_hash, computed_bl1_2_hash_size);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_RET(FIH_SUCCESS);
}

int main(void)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    FIH_DECLARE(recovery_succeeded, FIH_FAILURE);
    enum tfm_plat_err_t plat_err;
    bool provisioning_required;

    fih_rc = fih_ret_encode_zero_equality(boot_platform_init());
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
    }

    INFO("Starting TF-M BL1_1\n");

#if defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION)
    run_bl1_1_testsuite();
#endif /* defined(TEST_BL1_1) && defined(PLATFORM_DEFAULT_BL1_TEST_EXECUTION) */

    plat_err = tfm_plat_provisioning_is_required(&provisioning_required);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        ERROR("BL1 provision necessity check failed\n");
        boot_platform_error_state(fih_rc);
    }

    if (provisioning_required) {
        fih_rc = fih_ret_encode_zero_equality(tfm_plat_provisioning_perform());
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            ERROR("BL1 provisioning failed\n");
            boot_platform_error_state(fih_rc);
        }
    }

    tfm_plat_provisioning_check_for_dummy_keys();

    fih_rc = fih_ret_encode_zero_equality(boot_platform_post_init());
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
    }

    fih_rc = fih_ret_encode_zero_equality(boot_platform_pre_load(0));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
    }

    do {
        /* Copy BL1_2 from OTP into SRAM*/
        FIH_CALL(bl1_read_bl1_2_image, fih_rc, (uint8_t *)BL1_2_CODE_START);
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            boot_platform_error_state(fih_rc);
        }

        FIH_CALL(bl1_1_validate_image_at_addr, fih_rc, (uint8_t *)BL1_2_CODE_START);

        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            ERROR("BL1_2 image failed to validate\n");

            recovery_succeeded = fih_ret_encode_zero_equality(boot_initiate_recovery_mode(0));
            if (FIH_NOT_EQ(recovery_succeeded, FIH_SUCCESS)) {
                boot_platform_error_state(recovery_succeeded);
            }
        }
    } while (FIH_NOT_EQ(fih_rc, FIH_SUCCESS));

    fih_rc = fih_ret_encode_zero_equality(boot_platform_post_load(0));
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        boot_platform_error_state(fih_rc);
    }

#ifdef TFM_MEASURED_BOOT_API
    collect_boot_measurement();
#endif /* TFM_MEASURED_BOOT_API */

    INFO("Jumping to BL1_2\n");
    /* Jump to BL1_2 */
    boot_platform_start_next_image((struct boot_arm_vector_table *)BL1_2_CODE_START);

    /* This should never happen */
    FIH_PANIC;
}


/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "rse_test_common.h"

#include "tfm_plat_defs.h"
#include "tfm_plat_otp.h"

#include "device_definition.h"
#include "rse_kmu_keys.h"

/* device headers */
#include "kmu_drv.h"
#include "cc3xx_drv.h"

/* arbitrary key */
#define SLOT_COUNT KMU_USER_SLOT_MAX + 1
#define SLOT       (SLOT_COUNT - 2)

const struct kmu_key_export_config_t export_config = {
    .export_address = CC3XX_BASE_S + 0x400, /* CC3XX AES_KEY_0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

const struct kmu_key_export_config_t aead_export_config = {
    .export_address = CC3XX_BASE_S + 0x420, /* CC3XX AES_KEY_1 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};


static void test_setup_key_from_derivation(struct test_result_t *ret)
{
    ret->val = TEST_SKIPPED;
    return;

    /* TODO: Test is currently FAILING
     *
     * Trying to derive a key from all hardware key slots
     * to verify that they work.
     * Unfortunately not all keys are available to use when
     * the test is run.
     * Currently the test encounters a kmu hardware error
     * for all the keys listed below.
     *
     * The kmu error, KMU_ERROR_EXPORT_KEY_INVALID_LENGTH,
     * is encountered whenever the "kmu_export_key" function
     * is called.
     *
     * Trying the wrappers provided in the rse_kmu_keys.c file
     * gave similair results. Wrappers:
     *  rse_setup_iak_seed    - HUK
     *  rse_setup_dak_seed    - GUK
     *  rse_setup_rot_cdi     - HUK
     *  rse_setup_vhuk        - GUK
     *  rse_setup_session_key - GUK
     *
     * Steps to resolve the issues could be:
     *  + Testing only a specific key?
     *  + Changing the export configs?
     */
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;


    struct {
        const char *name;
        enum kmu_hardware_keyslot_t hw_slot;
    } test_info[] = {
        {"KRTL",   KMU_HW_SLOT_KRTL},
        {"HUK",    KMU_HW_SLOT_HUK},
        {"GUK",    KMU_HW_SLOT_GUK},
        {"KP_CM",  KMU_HW_SLOT_KP_CM},
        {"KCE_CM", KMU_HW_SLOT_KCE_CM},
        {"KP_DM",  KMU_HW_SLOT_KP_DM},
        {"KCE_DM", KMU_HW_SLOT_KCE_DM},
    };

    uint32_t *key;

    const uint8_t *label   = "KEY_LABEL";
    const uint8_t *context = "KEY_CONTEXT";

    for (uint32_t s = 0; s < ARRAY_SIZE(test_info); s++) {
        TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

        err = setup_key_from_derivation(test_info[s].hw_slot, key,
                                        label,   sizeof(label),
                                        context, sizeof(context),
                                        SLOT,
                                        &export_config, &aead_export_config,
                                        true, 0);
        TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
                "Failed to set up key using derivation");
    }

    ret->val = TEST_PASSED;
}


static void test_setup_key_from_derivation_boot_state_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    uint8_t context;

    err = setup_key_from_derivation(0, NULL, NULL, 0,
                                    &context, sizeof(context),
                                    0, NULL, NULL, 0,
                                    RSE_BOOT_STATE_INCLUDE_TP_MODE);
    TEST_ASSERT(err == TFM_PLAT_ERR_KEY_DERIVATION_INVALID_BOOT_STATE_WITH_CONTEXT,
            "Failed invalid boot state with context check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_derivation_kmu_get_buffer_ptr_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = setup_key_from_derivation(0, NULL,
                                    NULL, 0,
                                    NULL, 0,
                                    SLOT_COUNT,
                                    NULL, NULL,
                                    0, RSE_BOOT_STATE_INCLUDE_NONE);
    TEST_ASSERT(err != TFM_PLAT_ERR_SUCCESS,
            "Failed kmu get buffer ptr check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_derivation_derivation_slot_size_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    struct kmu_key_export_config_t invalid_config = export_config;

    invalid_config.destination_port_data_writes_code =
        KMU_DESTINATION_PORT_WIDTH_16_WRITES;

    err = setup_key_from_derivation(0, NULL,
                                    NULL, 0,
                                    NULL, 0,
                                    SLOT,
                                    &invalid_config, NULL,
                                    0, RSE_BOOT_STATE_INCLUDE_NONE);
    TEST_ASSERT(err == TFM_PLAT_ERR_KEY_DERIVATION_DERIVATION_SLOT_TOO_SMALL,
            "Failed derivation slot size check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_otp(struct test_result_t *ret)
{
    ret->val = TEST_SKIPPED;
    return;

    /* TODO: Test is currently FAILING
     *
     * Trying to setup keys using the otp so as
     * to verify that keys can be generated from
     * any otp section.
     *
     * Testing it on the below otp sections causes
     * failures.
     *
     */
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    static struct {
        const char *name;
        enum tfm_otp_element_id_t id;
    } test_info[] = {
        {"HUK",                     PLAT_OTP_ID_HUK},
        {"GUK",                     PLAT_OTP_ID_GUK},
        {"BOOT_SEED",               PLAT_OTP_ID_BOOT_SEED},
        {"LCS",                     PLAT_OTP_ID_LCS},
        {"IMPLEMENTATION_ID",       PLAT_OTP_ID_IMPLEMENTATION_ID},
        {"CERT_REF",                PLAT_OTP_ID_CERT_REF},
        {"VERIFICATION_SERVICE_URL",PLAT_OTP_ID_VERIFICATION_SERVICE_URL},
        {"PROFILE_DEFINITION",      PLAT_OTP_ID_PROFILE_DEFINITION},
        {"BL1_2_IMAGE",             PLAT_OTP_ID_BL1_2_IMAGE},
        {"BL1_2_IMAGE_HASH",        PLAT_OTP_ID_BL1_2_IMAGE_HASH},
    };

    for (uint32_t i = 0; i < ARRAY_SIZE(test_info); i++) {
        TEST_SETUP(kmu_set_slot_invalid(&KMU_DEV_S, SLOT));

        err = setup_key_from_otp(SLOT, test_info[i].id,
                &export_config, &aead_export_config, true);

        TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
                "Failed to setup key using otp");
    }

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_otp_kmu_get_buffer_ptr_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = setup_key_from_otp(SLOT_COUNT,
            PLAT_OTP_ID_BOOT_SEED, NULL, NULL, false);
    TEST_ASSERT(err != TFM_PLAT_ERR_SUCCESS,
            "Failed kmu get buffer ptr check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_otp_derivation_slot_size_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    struct kmu_key_export_config_t invalid_config = export_config;

    invalid_config.destination_port_data_writes_code =
        KMU_DESTINATION_PORT_WIDTH_16_WRITES;

    err = setup_key_from_otp(SLOT,
            PLAT_OTP_ID_BOOT_SEED, &invalid_config, NULL, true);
    TEST_ASSERT(err == TFM_PLAT_ERR_KEY_DERIVATION_OTP_SLOT_TOO_SMALL,
            "Failed derivation slot size check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_rng(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = setup_key_from_rng(SLOT, &export_config, &aead_export_config, false);
    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            "Failed to setup key using rng");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_rng_kmu_get_buffer_ptr_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = setup_key_from_rng(SLOT_COUNT, NULL, NULL, false);
    TEST_ASSERT(err != TFM_PLAT_ERR_SUCCESS,
            "Failed kmu get buffer ptr check");

    ret->val = TEST_PASSED;
}

static void test_setup_key_from_rng_derivation_slot_size_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    struct kmu_key_export_config_t invalid_config = export_config;

    invalid_config.destination_port_data_writes_code =
        KMU_DESTINATION_PORT_WIDTH_16_WRITES;

    err = setup_key_from_rng(SLOT, &invalid_config, NULL, false);
    TEST_ASSERT(err == TFM_PLAT_ERR_KEY_DERIVATION_RNG_SLOT_TOO_SMALL,
            "Failed derivation slot size check");

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] =
{
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_derivation,
            "",
            "test_setup_key_from_derivation"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_derivation_boot_state_check,
            "",
            "test_setup_key_from_derivation_boot_state_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_derivation_kmu_get_buffer_ptr_check,
            "",
            "test_setup_key_from_derivation_kmu_get_buffer_ptr_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_derivation_derivation_slot_size_check,
            "",
            "test_setup_key_from_derivation_derivation_slot_size_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_otp,
            "",
            "test_setup_key_from_otp"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_otp_kmu_get_buffer_ptr_check,
            "",
            "test_setup_key_from_otp_kmu_get_buffer_ptr_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_otp_derivation_slot_size_check,
            "",
            "test_setup_key_from_otp_derivation_slot_size_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_rng,
            "",
            "test_setup_key_from_rng"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_rng_kmu_get_buffer_ptr_check,
            "",
            "test_setup_key_from_rng_kmu_get_buffer_ptr_check"
        },
    },
    {
        .tp_mode      = LCM_TP_MODE_VIRGIN,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_setup_key_from_rng_derivation_slot_size_check,
            "",
            "test_setup_key_from_rng_derivation_slot_size_check"
        },
    },
};

void add_bl1_rse_kmu_keys_tests (struct test_suite_t *p_ts, uint32_t ts_size)
{
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}

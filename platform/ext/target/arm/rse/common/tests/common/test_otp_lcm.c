/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "tfm_plat_otp.h"

#include "rse_otp_layout.h"
#include "rse_test_common.h"

struct test_otp_info {
    const char *name;
    const enum tfm_otp_element_id_t id;
};

static const struct test_otp_info read_test_info[] = {
    {"ID_HUK", PLAT_OTP_ID_HUK},
    {"ID_GUK", PLAT_OTP_ID_GUK},

    {"ID_CM_ROTPK_REPROVISIONING", PLAT_OTP_ID_CM_ROTPK_REPROVISIONING},
    {"ID_DM_ROTPK_REPROVISIONING", PLAT_OTP_ID_DM_ROTPK_REPROVISIONING},

    {"ID_KRTL_USAGE_COUNTER", PLAT_OTP_ID_KRTL_USAGE_COUNTER},
    {"ID_LFT_COUNTER", PLAT_OTP_ID_LFT_COUNTER},

    {"ID_DEVICE_STATUS", PLAT_OTP_ID_DEVICE_STATUS},

    {"ID_CM_CONFIG_FLAGS", PLAT_OTP_ID_CM_CONFIG_FLAGS},
    {"ID_DM_CONFIG_FLAGS", PLAT_OTP_ID_DM_CONFIG_FLAGS},

    {"ID_CM_ROTPK_POLICIES", PLAT_OTP_ID_CM_ROTPK_POLICIES},
    {"ID_DM_ROTPK_POLICIES", PLAT_OTP_ID_DM_ROTPK_POLICIES},

    {"ID_NV_COUNTER_BANK_0_COUNTER", PLAT_OTP_ID_NV_COUNTER_BANK_0_COUNTER},

    {"ID_BL1_2_IMAGE", PLAT_OTP_ID_BL1_2_IMAGE},
    {"ID_BL1_2_IMAGE_LEN", PLAT_OTP_ID_BL1_2_IMAGE_LEN},
    {"ID_BL1_2_IMAGE_HASH", PLAT_OTP_ID_BL1_2_IMAGE_HASH},

    {"ID_REPROVISIONING_BITS", PLAT_OTP_ID_REPROVISIONING_BITS},

#ifdef RSE_OTP_HAS_RSE_ID
    {"ID_RSE_ID", PLAT_OTP_ID_RSE_ID},
#endif

    {"ID_DMA_ICS", PLAT_OTP_ID_DMA_ICS},


    {"ID_CM_CODE_ENCRYPTION_KEY", PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY},
    {"ID_CM_PROVISIONING_KEY", PLAT_OTP_ID_CM_PROVISIONING_KEY},

    {"ID_DM_CODE_ENCRYPTION_KEY", PLAT_OTP_ID_DM_CODE_ENCRYPTION_KEY},
    {"ID_DM_PROVISIONING_KEY", PLAT_OTP_ID_DM_PROVISIONING_KEY},

#ifdef RSE_OTP_HAS_ROUTING_TABLES
    {"ID_RSE_TO_RSE_ROUTING_TABLE", PLAT_OTP_ID_RSE_TO_RSE_ROUTING_TABLE},
#endif
};
static const uint32_t otp_read_test_info_len = ARRAY_SIZE(read_test_info);

static const struct test_otp_info write_test_info[] = {
    {"ID_DEVICE_STATUS", PLAT_OTP_ID_DEVICE_STATUS},

#ifdef RSE_OTP_HAS_RSE_ID
    {"ID_RSE_ID", PLAT_OTP_ID_RSE_ID},
#endif
#ifdef RSE_OTP_HAS_ROUTING_TABLES
    {"ID_RSE_TO_RSE_ROUTING_TABLE", PLAT_OTP_ID_RSE_TO_RSE_ROUTING_TABLE},
#endif
};
static const uint32_t otp_write_test_info_len = ARRAY_SIZE(write_test_info);

static const struct test_otp_info getsize_test_info[] = {
    {"ID_HUK", PLAT_OTP_ID_HUK},
    {"ID_GUK", PLAT_OTP_ID_GUK},

    {"ID_KRTL_USAGE_COUNTER", PLAT_OTP_ID_KRTL_USAGE_COUNTER},
    {"ID_LFT_COUNTER", PLAT_OTP_ID_LFT_COUNTER},

    {"ID_CM_CONFIG_FLAGS", PLAT_OTP_ID_CM_CONFIG_FLAGS},
    {"ID_DM_CONFIG_FLAGS", PLAT_OTP_ID_DM_CONFIG_FLAGS},

    {"ID_CM_ROTPK_POLICIES", PLAT_OTP_ID_CM_ROTPK_POLICIES},
    {"ID_DM_ROTPK_POLICIES", PLAT_OTP_ID_DM_ROTPK_POLICIES},

    {"ID_BL1_2_IMAGE", PLAT_OTP_ID_BL1_2_IMAGE},
    {"ID_BL1_2_IMAGE_LEN", PLAT_OTP_ID_BL1_2_IMAGE_LEN},
    {"ID_BL1_2_IMAGE_HASH", PLAT_OTP_ID_BL1_2_IMAGE_HASH},

    {"ID_REPROVISIONING_BITS", PLAT_OTP_ID_REPROVISIONING_BITS},
    {"ID_CM_ROTPK_REPROVISIONING", PLAT_OTP_ID_CM_ROTPK_REPROVISIONING},
    {"ID_DM_ROTPK_REPROVISIONING", PLAT_OTP_ID_DM_ROTPK_REPROVISIONING},

    {"ID_DMA_ICS", PLAT_OTP_ID_DMA_ICS},

    {"ID_CM_CODE_ENCRYPTION_KEY", PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY},
    {"ID_CM_PROVISIONING_KEY", PLAT_OTP_ID_CM_PROVISIONING_KEY},

    {"ID_DM_CODE_ENCRYPTION_KEY", PLAT_OTP_ID_DM_CODE_ENCRYPTION_KEY},
    {"ID_DM_PROVISIONING_KEY", PLAT_OTP_ID_DM_PROVISIONING_KEY},

    {"ID_DEVICE_STATUS", PLAT_OTP_ID_DEVICE_STATUS},

    {"ID_DM_CONFIG_FLAGS", PLAT_OTP_ID_DM_CONFIG_FLAGS},

    {"ID_DM_ROTPK_POLICIES", PLAT_OTP_ID_DM_ROTPK_POLICIES},

#ifdef RSE_OTP_HAS_RSE_ID
    {"ID_RSE_ID", PLAT_OTP_ID_RSE_ID},
#endif
#ifdef RSE_OTP_HAS_ROUTING_TABLES
    {"ID_RSE_TO_RSE_ROUTING_TABLE", PLAT_OTP_ID_RSE_TO_RSE_ROUTING_TABLE},
#endif
};
static const uint32_t otp_getsize_test_info_len = ARRAY_SIZE(getsize_test_info);

/*======================================== otp read ==========================================*/
static void test_common_otp_read_basic(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_FORCE_UINT_SIZE;

    uint32_t output;

    for (uint32_t i = 0; i < otp_read_test_info_len; i++) {
        struct test_otp_info info = read_test_info[i];

        err = tfm_plat_otp_read(info.id,
                sizeof(output), (uint8_t *) &output);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
                " > otp: %s -- Failed read\r\n", info.name);
    }

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_null_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_read(read_test_info[0].id, 1, NULL);

    TEST_ASSERT(err == TFM_PLAT_ERR_OTP_READ_INVALID_INPUT,
            "Failed NULL check on otp read");

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_id_bounds_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint8_t output;

    err = tfm_plat_otp_read(PLAT_OTP_ID_MAX, 1, &output);

    TEST_ASSERT(err == TFM_PLAT_ERR_OTP_READ_INVALID_ID,
            "Failed otp id bounds check");

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_invalid_mapping(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    /* unique test data */
    struct test_otp_info info =
        {"ID_BOOT_SEED", PLAT_OTP_ID_BOOT_SEED};

    uint32_t output;

    err = tfm_plat_otp_read(info.id,
            sizeof(output), (uint8_t *) &output);

    TEST_FMT_ASSERT(err == TFM_PLAT_ERR_OTP_ID_NOT_SET_UP,
            " > otp: %s -- Failed invalid otp mapping\r\n", info.name);

    ret->val = TEST_PASSED;
}

/*====================================== otp read lcs ========================================*/
static void test_common_otp_read_lcs_assembly_and_test(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t output;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS,
            sizeof(output), (uint8_t *) &output);

    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            " > otp lcs: Failed read");
    TEST_ASSERT(output == PLAT_OTP_LCS_ASSEMBLY_AND_TEST,
            " > otp lcs: Incorrect LCS read");

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_lcs_psa_rot_provisioning(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t output;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS,
            sizeof(output), (uint8_t *) &output);

    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            " > otp lcs: Failed read");
    TEST_ASSERT(output == PLAT_OTP_LCS_PSA_ROT_PROVISIONING,
            " > otp lcs: Incorrect LCS read");

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_lcs_secured(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t output;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS,
            sizeof(output), (uint8_t *) &output);

    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            " > otp lcs: Failed read");
    TEST_ASSERT(output == PLAT_OTP_LCS_SECURED,
            " > otp lcs: Incorrect LCS read");

    ret->val = TEST_PASSED;
}
static void test_common_otp_read_lcs_decommissioned(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t output;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS,
            sizeof(output), (uint8_t *) &output);

    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            " > otp lcs: Failed read");
    TEST_ASSERT(output == PLAT_OTP_LCS_DECOMMISSIONED,
            " > otp lcs: Incorrect LCS read");

    ret->val = TEST_PASSED;
}

/*======================================== otp write =========================================*/
static void test_common_otp_write(struct test_result_t *ret)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_FORCE_UINT_SIZE;

    uint32_t input = 9;

    for (uint32_t i = 0; i < otp_write_test_info_len; i++) {
        struct test_otp_info info = write_test_info[i];

        err = tfm_plat_otp_write(info.id, sizeof(input), (uint8_t *)&input);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
                " > otp: %s -- Failed write\r\n", info.name);
    }

    ret->val = TEST_PASSED;
}
static void test_common_otp_write_id_bounds_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint8_t input = 0;

    err = tfm_plat_otp_write(PLAT_OTP_ID_MAX, 1, &input);

    TEST_ASSERT(err == TFM_PLAT_ERR_OTP_WRITE_INVALID_ID,
            "Failed otp id bounds check");

    ret->val = TEST_PASSED;
}
static void test_common_otp_write_invalid_mapping(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint32_t input = 0;

    /* unique test data */
    struct test_otp_info info =
        {"ID_BOOT_SEED", PLAT_OTP_ID_BOOT_SEED};

    err = tfm_plat_otp_write(info.id,
            sizeof(input), (uint8_t *) &input);

    TEST_FMT_ASSERT(err == TFM_PLAT_ERR_OTP_WRITE_ID_NOT_SET_UP,
            " > otp: %s -- Failed invalid otp mapping check\r\n", info.name);

    ret->val = TEST_PASSED;
}
static void test_common_otp_write_null_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_write(write_test_info[0].id, 1, NULL);

    TEST_ASSERT(err == TFM_PLAT_ERR_OTP_WRITE_INVALID_INPUT,
            "Failed NULL check on otp write");

    ret->val = TEST_PASSED;
}

/*===================================== otp get size =======================================*/
static void test_common_otp_get_size_basic(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    size_t size;

    for (uint32_t i = 0; i < otp_getsize_test_info_len; i++) {
        struct test_otp_info info = getsize_test_info[i];

        err = tfm_plat_otp_get_size(info.id, &size);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
                " > otp: %s -- Failed get size\r\n", info.name);
    }

    ret->val = TEST_PASSED;
}
static void test_common_otp_get_size_null_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_get_size(getsize_test_info[0].id, NULL);

    TEST_ASSERT(err != TFM_PLAT_ERR_SUCCESS,
            "Failed NULL check on otp get size");

    ret->val = TEST_PASSED;
}
static void test_common_otp_get_size_id_bounds_check(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    size_t size;

    err = tfm_plat_otp_get_size(PLAT_OTP_ID_MAX, &size);

    TEST_ASSERT(err == TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_INVALID_ID,
            "Failed otp id bounds check");

    ret->val = TEST_PASSED;
}
static void test_common_otp_get_size_invalid_mapping(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    /* unique test data */
    struct test_otp_info info =
        {"ID_CERT_REF", PLAT_OTP_ID_CERT_REF};

    size_t size;

    err = tfm_plat_otp_get_size(info.id, &size);

    TEST_FMT_ASSERT(err == TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_ID_NOT_SET_UP,
            " > otp: %s -- Failed invalid otp mapping check\r\n", info.name);

    ret->val = TEST_PASSED;
}
/*============================= otp secure provisioning start  =============================*/
static void test_common_otp_secure_provisioning_start(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_secure_provisioning_start();

    TEST_ASSERT(err == TFM_PLAT_ERR_SUCCESS,
            "Failed to start otp secure provisioning");

    ret->val = TEST_PASSED;
}
/*==================================== test scheduling ======================================*/
static struct conditional_test_t tests[] = {
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_read_basic,
            "OTP_LCM_TEST_01",
            "Check OTP read basic functionality"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_read_null_check,
            "OTP_LCM_TEST_02",
            "Verify OTP read null check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_read_id_bounds_check,
            "OTP_LCM_TEST_03",
            "Verify OTP read id bounds check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_read_invalid_mapping,
            "OTP_LCM_TEST_04",
            "Verify OTP read invalid mapping"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .lcs          = LCM_LCS_CM,
        .test         = {
            &test_common_otp_write,
            "OTP_LCM_TEST_05",
            "Check OTP write basic functionality"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_write_null_check,
            "OTP_LCM_TEST_06",
            "Verify OTP write null check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_write_id_bounds_check,
            "OTP_LCM_TEST_07",
            "Verify OTP write id bounds check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_write_invalid_mapping,
            "OTP_LCM_TEST_08",
            "Verify OTP write invalid mapping"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_get_size_basic,
            "OTP_LCM_TEST_09",
            "Check OTP get size basic functionality"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_get_size_null_check,
            "OTP_LCM_TEST_10",
            "Verify OTP get size null check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_get_size_id_bounds_check,
            "OTP_LCM_TEST_11",
            "Verify OTP get size id bounds check"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_otp_get_size_invalid_mapping,
            "OTP_LCM_TEST_12",
            "Verify OTP get size invalid mapping"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .lcs          = LCM_LCS_CM,
        .test         = {
            &test_common_otp_read_lcs_assembly_and_test,
            "OTP_LCM_TEST_13",
            "OTP read LCS assembley and test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .lcs          = LCM_LCS_DM,
        .test         = {
            &test_common_otp_read_lcs_psa_rot_provisioning,
            "OTP_LCM_TEST_14",
            "OTP read LCS psa rot provisioning"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .lcs          = LCM_LCS_SE,
        .test         = {
            &test_common_otp_read_lcs_secured,
            "OTP_LCM_TEST_15",
            "OTP read LCS secured"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .lcs          = LCM_LCS_RMA,
        .test         = {
            &test_common_otp_read_lcs_decommissioned,
            "OTP_LCM_TEST_16",
            "OTP read LCS decommissioned"
        },
    },
    {
        .any_tp_mode = true,
        .sp_enabled  = false,
        .lcs         = LCM_LCS_DM,
        .test        = {
            &test_common_otp_secure_provisioning_start,
            "OTP_LCM_TEST_17",
            "OTP start secure provisioning"
        },
    },
};

void add_common_otp_lcm_tests(struct test_suite_t *p_ts, uint32_t ts_size) {
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}

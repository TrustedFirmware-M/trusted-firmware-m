/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "unity.h"

#include "lcm_drv.h"
#include "otp.h"
#include "rse_boot_state.h"

#include "mock_cc3xx_hash.h"
#include "mock_lcm_drv.h"
#include "mock_tfm_plat_otp.h"

static uint32_t LCM_DEV_BASE;
static struct lcm_dev_cfg_t LCM_DEV_CFG_S = {.base = (uintptr_t)&LCM_DEV_BASE};
struct lcm_dev_t LCM_DEV_S = {.cfg = &(LCM_DEV_CFG_S)};

uint8_t computed_bl1_2_hash[BL1_2_HASH_SIZE];

void test_rse_get_boot_state_invalid_state_buf_len(void)
{
    int err;
    uint8_t state[SHA256_OUTPUT_SIZE];
    boot_state_include_mask mask;
    size_t state_buf_len;
    size_t state_size;

    /* Prepare */
    mask = RSE_BOOT_STATE_INCLUDE_NONE;
    state_buf_len = 0;
    state_size = 0;

    /* Act */
    err = rse_get_boot_state(state, state_buf_len, &state_size, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(err, 1);
}

void test_rse_get_boot_state_hash_init_fails(void)
{
    int err;
    uint8_t state[SHA256_OUTPUT_SIZE];
    boot_state_include_mask mask;
    size_t state_buf_len;
    size_t state_size;

    /* Prepare */
    mask = RSE_BOOT_STATE_INCLUDE_NONE;
    state_buf_len = SHA256_OUTPUT_SIZE;
    state_size = 0;

    cc3xx_lowlevel_hash_init_ExpectAndReturn(CC3XX_HASH_ALG_SHA256,
                                             CC3XX_ERR_NOT_IMPLEMENTED);

    /* Act */
    err = rse_get_boot_state(state, state_buf_len, &state_size, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(err, -1);
}

TEST_CASE(RSE_BOOT_STATE_INCLUDE_LCS, PLAT_OTP_ID_LCS)
TEST_CASE(RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS,
          PLAT_OTP_ID_REPROVISIONING_BITS)
void test_rse_get_boot_state_otp_read_fails(boot_state_include_mask mask,
                                            enum tfm_otp_element_id_t otp_id)
{
    int err;
    uint8_t state[SHA256_OUTPUT_SIZE];
    size_t state_buf_len;
    size_t state_size;

    /* Prepare */
    state_buf_len = SHA256_OUTPUT_SIZE;
    state_size = 0;

    cc3xx_lowlevel_hash_init_ExpectAndReturn(CC3XX_HASH_ALG_SHA256,
                                             CC3XX_ERR_SUCCESS);

    tfm_plat_otp_read_ExpectAndReturn(otp_id, sizeof(uint32_t), NULL,
                                      TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_read_IgnoreArg_out();

    /* Act */
    err = rse_get_boot_state(state, state_buf_len, &state_size, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(err, -2);
}

TEST_CASE(RSE_BOOT_STATE_INCLUDE_TP_MODE)
TEST_CASE(RSE_BOOT_STATE_INCLUDE_LCS)
TEST_CASE(RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS)
TEST_CASE(RSE_BOOT_STATE_INCLUDE_BL1_2_HASH)
void test_rse_get_boot_state_hash_update_fails(boot_state_include_mask mask)
{
    int err;
    uint8_t state[SHA256_OUTPUT_SIZE];
    size_t state_buf_len;
    size_t state_size;
    size_t hash_update_len;

    /* Prepare */
    state_buf_len = SHA256_OUTPUT_SIZE;
    state_size = 0;

    if (mask & RSE_BOOT_STATE_INCLUDE_BL1_2_HASH)
        hash_update_len = SHA256_OUTPUT_SIZE;
    else
        hash_update_len = sizeof(uint32_t);

    cc3xx_lowlevel_hash_init_ExpectAndReturn(CC3XX_HASH_ALG_SHA256,
                                             CC3XX_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    if (mask & RSE_BOOT_STATE_INCLUDE_TP_MODE) {
        lcm_get_tp_mode_ExpectAndReturn(&LCM_DEV_S, NULL, TFM_PLAT_ERR_OTP_WRITE_INVALID_INPUT);
        lcm_get_tp_mode_IgnoreArg_mode();
    }

    cc3xx_lowlevel_hash_update_ExpectAndReturn(NULL, hash_update_len,
                                               CC3XX_ERR_NOT_IMPLEMENTED);
    cc3xx_lowlevel_hash_update_IgnoreArg_buf();

    /* Act */
    err = rse_get_boot_state(state, state_buf_len, &state_size, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(err, -1);
}

void test_rse_get_boot_state_ok(void)
{
    int err;
    uint8_t state[SHA256_OUTPUT_SIZE];
    boot_state_include_mask mask;
    size_t state_buf_len;
    size_t state_size;

    /* Prepare */
    mask = RSE_BOOT_STATE_INCLUDE_NONE;
    state_buf_len = SHA256_OUTPUT_SIZE;
    state_size = 0;

    cc3xx_lowlevel_hash_init_ExpectAndReturn(CC3XX_HASH_ALG_SHA256,
                                             CC3XX_ERR_SUCCESS);
    cc3xx_lowlevel_hash_finish_Expect((uint32_t *)state, SHA256_OUTPUT_SIZE);

    /* Act */
    err = rse_get_boot_state(state, state_buf_len, &state_size, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(err, 0);
}

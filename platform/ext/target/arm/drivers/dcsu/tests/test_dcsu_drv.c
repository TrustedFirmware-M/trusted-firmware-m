/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <string.h>

#include "test_framework.h"

#include "dcsu_drv.h"
#include "test_dcsu_drv.h"
#include "device_definition.h"
#include "rse_otp_dev.h"
#include "rse_zero_count.h"
#include "rse_soc_uid.h"

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) {             \
        TEST_FAIL(msg);        \
        return;                \
    }
#define ARRAY_SIZE(_arr) (sizeof(_arr) / sizeof((_arr)[0]))

#define EXPECTED_DATA_BYTES "\xAB\xCD\xEF\x10\x01\x23\x45\x67"
#define EXPECTED_DATA_BYTES_SIZE (sizeof(EXPECTED_DATA_BYTES) - 1)

#define SOC_FAMILY_ID_BYTES "\xDE\xAD\xBE\xEF"
#define IEEE_ECID_BYTES "\xFE\xED\xC0\xDE\xFE\xED\xC0\xDE\xFE\xED\xC0\xDE\xFE\xED\xC0\xDE"

static uint8_t rx_recv_buffer[1024];

static enum dcsu_error_t process_multiple_commands(enum dcsu_rx_command command)
{
    enum dcsu_error_t err;
    bool got_complete = false;

    while (!got_complete) {
        TEST_LOG("Waiting for command...\n");
        if (dcsu_wait_for_rx_command(&DCSU_DEV_S, command) == DCSU_ERROR_NONE) {
            got_complete = true;
        }

        err = dcsu_handle_rx_command(&DCSU_DEV_S);
        if (err != DCSU_ERROR_NONE) {
            return err;
        }
    }

    return DCSU_ERROR_NONE;
}

static enum dcsu_error_t process_commands_until_complete(void)
{
    return process_multiple_commands(DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA);
}

static void test_teardown(void)
{
    memset(rx_recv_buffer, 0, sizeof(rx_recv_buffer));
}

static void dcsu_drv_test_0001(struct test_result_t *ret)
{
    TEST_ASSERT(dcsu_init(&DCSU_DEV_S, rx_recv_buffer, sizeof(rx_recv_buffer), NULL) ==
                    DCSU_ERROR_NONE,
                "DCSU initialisation failed!");

    TEST_LOG("Signalling DCSU ready, start test_dcsu.py now!\n");
    TEST_ASSERT(dcsu_import_ready(&DCSU_DEV_S) == DCSU_ERROR_NONE, "Failed to get signal!");

    test_teardown();
}

static enum dcsu_error_t wait_run_command(enum dcsu_rx_command command)
{
    enum dcsu_error_t dcsu_err;

    dcsu_err = dcsu_wait_for_rx_command(&DCSU_DEV_S, command);
    if (dcsu_err != DCSU_ERROR_NONE) {
        return dcsu_err;
    }

    return dcsu_handle_rx_command(&DCSU_DEV_S);
}

static enum lcm_error_t check_otp_area_correct(uint32_t offset, size_t len, uint8_t *buf,
                                               bool *correct)
{
    uint8_t read_buf[len];
    enum lcm_error_t lcm_err;

    lcm_err = lcm_otp_read(&LCM_DEV_S, offset, len, read_buf);
    if (lcm_err != LCM_ERROR_NONE) {
        return lcm_err;
    }

    for (unsigned i = 0; i < len; i++) {
        if (buf != NULL) {
            if (read_buf[i] != buf[i]) {
                *correct = false;
                return LCM_ERROR_NONE;
            }
        } else {
            if (read_buf[i] == 0) {
                *correct = false;
                return LCM_ERROR_NONE;
            }
        }
    }

    *correct = true;
    return LCM_ERROR_NONE;
}

static void dcsu_drv_test_0100(struct test_result_t *ret)
{
    bool correct_otp_val;

    /* Generate SoC Unique ID */
    TEST_ASSERT(wait_run_command(DCSU_RX_COMMAND_GENERATE_SOC_UNIQUE_ID) == DCSU_ERROR_NONE,
                "Failed to handle SoC UID command");

    TEST_ASSERT(check_otp_area_correct(OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.unique_id),
                                       sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id), NULL,
                                       &correct_otp_val) == LCM_ERROR_NONE,
                "Failed to read SoC UID");
    TEST_ASSERT(correct_otp_val, "SoC UID value incorrect");

    /* Second attempted write should succeed here but return failure to the host */
    TEST_ASSERT(wait_run_command(DCSU_RX_COMMAND_GENERATE_SOC_UNIQUE_ID) == DCSU_ERROR_NONE,
                "Failed to handle SoC UID command");
}

static void test_write_read_otp_field(struct test_result_t *ret, enum dcsu_rx_command write_command,
                                      enum dcsu_rx_command read_command, uint32_t offset,
                                      size_t len, uint8_t *buf)
{
    bool correct_otp_val;

    TEST_ASSERT(wait_run_command(write_command) == DCSU_ERROR_NONE,
                "Failed to handle write command");

    TEST_ASSERT(check_otp_area_correct(offset, len, buf, &correct_otp_val) == LCM_ERROR_NONE,
                "Failed to read OTP field");
    TEST_ASSERT(correct_otp_val, "OTP field value incorrect");

    /* Allow host to read back value to confirm */
    TEST_ASSERT(wait_run_command(read_command) == DCSU_ERROR_NONE, "Failed to handle read command");
}

static void dcsu_drv_test_0101(struct test_result_t *ret)
{
    test_write_read_otp_field(ret, DCSU_RX_COMMAND_WRITE_SOC_FAMILY_ID,
                              DCSU_RX_COMMAND_READ_SOC_FAMILY_ID,
                              OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.family_id),
                              sizeof(P_RSE_OTP_SOC->soc_id_area.family_id),
                              (uint8_t *)SOC_FAMILY_ID_BYTES);
}

static void dcsu_drv_test_0102(struct test_result_t *ret)
{
    test_write_read_otp_field(ret, DCSU_RX_COMMAND_WRITE_SOC_IEEE_ECID,
                              DCSU_RX_COMMAND_READ_SOC_IEEE_ECID,
                              OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.ieee_ecid),
                              sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid),
                              (uint8_t *)IEEE_ECID_BYTES);
}

static void dcsu_drv_test_0103(struct test_result_t *ret)
{
    TEST_ASSERT(wait_run_command(DCSU_RX_COMMAND_COMPUTE_ZC_SOC_IDS) == DCSU_ERROR_NONE,
                "Failed to handle compute SoC ID zero count command");

    TEST_ASSERT(rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_SOC->soc_id_area.family_id,
                                         sizeof(P_RSE_OTP_SOC->soc_id_area.family_id) +
                                             sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid),
                                         P_RSE_OTP_SOC->soc_id_area.zero_count_id) ==
                    TFM_PLAT_ERR_SUCCESS,
                "SoC Config area zero count failed");
}

static void dcsu_drv_test_0104(struct test_result_t *ret)
{
    /* Allow host to test multiple commands */
    TEST_ASSERT(process_multiple_commands(DCSU_RX_COMMAND_READ_SOC_CONFIG_DATA) == DCSU_ERROR_NONE,
                "Command processing should have succeeded!");

    /* Host should have called the write zero count command, ensure that the
     * value written is correct here */
    TEST_ASSERT(rse_check_zero_bit_count(
                    (uint8_t *)((uintptr_t)&P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc +
                                sizeof(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc)),
                    sizeof(P_RSE_OTP_SOC->soc_cfg_area) -
                        sizeof(P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc),
                    P_RSE_OTP_SOC->soc_cfg_area.soc_cfg_data_zc) == TFM_PLAT_ERR_SUCCESS,
                "SoC Config area zero count failed");
}

static void dcsu_drv_test_0202(struct test_result_t *ret)
{
    /* Spin in command loop and process until the script indicates that
     * we should move to the next test (using COMPLETE)*/
    TEST_ASSERT(process_commands_until_complete() == DCSU_ERROR_NONE,
                "Command processing should have succeeded!");

    test_teardown();
}

static void dcsu_drv_test_receieve_check_data(struct test_result_t *ret)
{
    /* Expect specific data to be written by the script and verify
     * that is the case */
    TEST_ASSERT(process_commands_until_complete() == DCSU_ERROR_NONE,
                "Command processing should have succeeded!");

    for (uint8_t *ptr = rx_recv_buffer;
         ptr + EXPECTED_DATA_BYTES_SIZE - 1 < rx_recv_buffer + sizeof(rx_recv_buffer);
         ptr += EXPECTED_DATA_BYTES_SIZE) {
        if (memcmp(ptr, EXPECTED_DATA_BYTES, EXPECTED_DATA_BYTES_SIZE)) {
            TEST_FAIL("Invalid data written!");
            return;
        }
    }

    test_teardown();
}

static void dcsu_drv_test_0203(struct test_result_t *ret)
{
    /* Receive direct data */
    dcsu_drv_test_receieve_check_data(ret);
}

static void dcsu_drv_test_0204(struct test_result_t *ret)
{
    /* Receive data passed to script from file */
    dcsu_drv_test_receieve_check_data(ret);
}

static struct test_t dcsu_drv_tests[] = {
    { &dcsu_drv_test_0001, "DCSU_DRV_TEST_0001", "Initial DCSU driver setup and wait for signal" },
    { &dcsu_drv_test_0100, "DCSU_DRV_TEST_0100", "Process Generate SoC UID command" },
    { &dcsu_drv_test_0101, "DCSU_DRV_TEST_0101", "Process write SoC family ID command" },
    { &dcsu_drv_test_0102, "DCSU_DRV_TEST_0102", "Process write IEEE ECID command" },
    { &dcsu_drv_test_0103, "DCSU_DRV_TEST_0103",
      "Process SoC ID zero count write command and check zero count" },
    { &dcsu_drv_test_0104, "DCSU_DRV_TEST_0104",
      "Process multiple SoC Config Area commands and check zero count" },
    { &dcsu_drv_test_0202, "DCSU_DRV_TEST_0202", "Process arbitrary commands until COMPLETE" },
    { &dcsu_drv_test_0203, "DCSU_DRV_TEST_0203", "Receieve data until COMPLETE and verify" },
    { &dcsu_drv_test_0204, "DCSU_DRV_TEST_0204",
      "Receieve data from file until COMPLETE and verify" },

};

void add_dcsu_drv_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
    const size_t num_tests = ARRAY_SIZE(dcsu_drv_tests);

    assert(p_ts->list_size + num_tests <= ts_size);

    /* The DCSU driver tests write to various regions in the OTP and therefore they cannot be
     * run more than once (as they will fail to write to the OTP a second time). Check if the
     * SoC UID has already been generated (is non-zero) and do not add the tests to the suite
     * if so */
    if (rse_soc_uid_is_generated()) {
        return;
    }

    memcpy(&(p_ts->test_list[p_ts->list_size]), dcsu_drv_tests, num_tests * sizeof(struct test_t));
    p_ts->list_size += num_tests;
}

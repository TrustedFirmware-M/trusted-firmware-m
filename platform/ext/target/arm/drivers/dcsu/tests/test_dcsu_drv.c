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

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) {             \
        TEST_FAIL(msg);        \
        return;                \
    }
#define ARRAY_SIZE(_arr) (sizeof(_arr) / sizeof((_arr)[0]))

#define EXPECTED_DATA_BYTES "\xAB\xCD\xEF\x10\x01\x23\x45\x67"
#define EXPECTED_DATA_BYTES_SIZE (sizeof(EXPECTED_DATA_BYTES) - 1)

static uint8_t rx_recv_buffer[1024];

static enum dcsu_error_t process_commands_until_complete(void)
{
    enum dcsu_error_t err;
    bool got_complete = false;

    while (!got_complete) {
        TEST_LOG("Waiting for command...\n");
        if (dcsu_wait_for_rx_command(&DCSU_DEV_S, DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA) ==
            DCSU_ERROR_NONE) {
            got_complete = true;
        }

        err = dcsu_handle_rx_command(&DCSU_DEV_S);
        if (err != DCSU_ERROR_NONE) {
            return err;
        }
    }
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

static void dcsu_drv_test_0002(struct test_result_t *ret)
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

static void dcsu_drv_test_0003(struct test_result_t *ret)
{
    /* Receive direct data */
    dcsu_drv_test_receieve_check_data(ret);
}

static void dcsu_drv_test_0004(struct test_result_t *ret)
{
    /* Receive data passed to script from file */
    dcsu_drv_test_receieve_check_data(ret);
}

static struct test_t dcsu_drv_tests[] = {
    { &dcsu_drv_test_0001, "DCSU_DRV_TEST_001", "Initial DCSU driver setup and wait for signal" },
    { &dcsu_drv_test_0002, "DCSU_DRV_TEST_002", "Process arbitrary commands until COMPLETE" },
    { &dcsu_drv_test_0003, "DCSU_DRV_TEST_003", "Receieve data until COMPLETE and verify" },
    { &dcsu_drv_test_0004, "DCSU_DRV_TEST_004",
      "Receieve data from file until COMPLETE and verify" },

};

void add_dcsu_drv_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
    const size_t num_tests = ARRAY_SIZE(dcsu_drv_tests);

    assert(p_ts->list_size + num_tests <= ts_size);

    memcpy(&(p_ts->test_list[p_ts->list_size]), dcsu_drv_tests, num_tests * sizeof(struct test_t));
    p_ts->list_size += num_tests;
}

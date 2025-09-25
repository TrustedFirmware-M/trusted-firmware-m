/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

/* framework headers */
#include "rse_test_common.h"
#include "test_atu_rse_common.h"

/* device header */
#include "atu_rse_drv.h"

static void test_natdrv_atu_setter_getter_test(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint64_t exp_phy_addr = ATU_DUMMY_SLOT_LOG_ADDR;
    uint64_t phy_addr = 0;
    uint32_t exp_log_addr = ATU_DUMMY_SLOT_PHY_ADDR;
    uint32_t log_addr = 0;
    uint32_t exp_bus_attr = ATU_SEC_OUT_ATTR;
    uint32_t bus_attr = 0;

    /* Test setter and getter of start logical address */
    err = atu_rse_set_start_logical_address(NULL, MIN_TEST_REGION, exp_log_addr);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ARG, "NULL device error");
    err = atu_rse_set_start_logical_address(&ATU_DEV_S, NUM_REGIONS, exp_log_addr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_set_start_logical_address(&ATU_DEV_S, MIN_TEST_REGION, exp_log_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    err = atu_rse_get_start_logical_address(&ATU_DEV_S, NUM_REGIONS, &log_addr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_get_start_logical_address(&ATU_DEV_S, MIN_TEST_REGION, &log_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    TEST_ASSERT(log_addr == exp_log_addr, "Returned address differs");

    /* Test setter and getter of end logical address */
    err = atu_rse_set_end_logical_address(&ATU_DEV_S, MIN_TEST_REGION, exp_log_addr - 1);
    TEST_ASSERT(err == ATU_ERR_INVALID_LOGICAL_ADDRESS, "End is not smaller than start");

    err = atu_rse_set_end_logical_address(&ATU_DEV_S, MIN_TEST_REGION, exp_log_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    err = atu_rse_get_end_logical_address(&ATU_DEV_S, NUM_REGIONS, &log_addr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_get_end_logical_address(&ATU_DEV_S, MIN_TEST_REGION, &log_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    TEST_ASSERT(log_addr == exp_log_addr, "Returned address differs");

    /* Test setter and getter of physical region offset */
    atu_rse_set_physical_region_offset(&ATU_DEV_S, MIN_TEST_REGION, exp_phy_addr);
    err = atu_rse_get_physical_region_offset(&ATU_DEV_S, NUM_REGIONS, &phy_addr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_get_physical_region_offset(&ATU_DEV_S, MIN_TEST_REGION, &phy_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    TEST_ASSERT(phy_addr == exp_phy_addr, "Returned address differs");

    /* Test setter and getter of bus attributes */
    err = atu_rse_set_bus_attributes(&ATU_DEV_S, NUM_REGIONS, exp_bus_attr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_set_bus_attributes(&ATU_DEV_S, MIN_TEST_REGION, exp_bus_attr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    err = atu_rse_get_bus_attributes(&ATU_DEV_S, NUM_REGIONS, &bus_attr);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Invalid region");
    err = atu_rse_get_bus_attributes(&ATU_DEV_S, MIN_TEST_REGION, &bus_attr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected success");
    TEST_ASSERT(bus_attr == exp_bus_attr, "Returned address differs");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_check_supported_region(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_check_supported_region(&ATU_DEV_S, NUM_REGIONS);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Expected overflow while checking supported regions");

    err = atu_rse_check_supported_region(&ATU_DEV_S, MIN_TEST_REGION);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expecting success while checking supported regions");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_initialize_region_null_dev(struct test_result_t *ret)
{
    enum atu_error_t err = atu_rse_initialize_region(NULL, MIN_TEST_REGION, 0, 0, 0);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ARG, "Expected region initialization null device error");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_initialize_region_errors(struct test_result_t *ret)
{
    enum atu_error_t err;

    /* Test region boundaries */
    err = atu_rse_initialize_region(&ATU_DEV_S, NUM_REGIONS, 0, 0, 0);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Expected region initialization region overflow");

    /* Test logical address alignment */
    err = atu_rse_initialize_region(&ATU_DEV_S, MIN_TEST_REGION, PAGE_SIZE - 1, 0, 0);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected region initialization logical address alignment error");

    /* Test logical address alignment */
    err = atu_rse_initialize_region(&ATU_DEV_S, MIN_TEST_REGION, UINT32_MAX, 0, 0);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected region initialization logical address overflow");

    /* Test physical address alignment */
    err = atu_rse_initialize_region(&ATU_DEV_S, MIN_TEST_REGION, 0, PAGE_SIZE - 1, 0);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected region initialization physical address alignment error");

    /* Test size alignment */
    err = atu_rse_initialize_region(&ATU_DEV_S, MIN_TEST_REGION, 0, 0, PAGE_SIZE - 1);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected region initialization size alignment error");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_initialize_region_ok(struct test_result_t *ret)
{
    enum atu_error_t err;

    /* Test region boundaries */
    err = atu_rse_initialize_region(&ATU_DEV_S, MIN_TEST_REGION, ATU_DUMMY_SLOT_LOG_ADDR, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_SIZE);

    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful region initialization");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_uninitialize_region_null_dev(struct test_result_t *ret)
{
    enum atu_error_t err = atu_rse_uninitialize_region(NULL, MIN_TEST_REGION);
    TEST_ASSERT(err == ATU_ERR_UNINIT_REGION_INVALID_ARG, "Expected region uninitialization null device error");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_uninitialize_region_invalid_region(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_uninitialize_region(&ATU_DEV_S, NUM_REGIONS);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Expected region uninitialization region overflow");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_uninitialize_region_ok(struct test_result_t *ret)
{
    enum atu_error_t err;

    /* Test region boundaries */
    err = atu_rse_uninitialize_region(&ATU_DEV_S, MIN_TEST_REGION);

    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful region uninitialization");

    deinit_test_regions();

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] =
{
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_setter_getter_test,
            "ATU_RSE_DRV_TEST_0001",
            "getter setter test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_check_supported_region,
            "ATU_RSE_DRV_TEST_0002",
            "atu_rse_check_supported_region test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_initialize_region_null_dev,
            "ATU_RSE_DRV_TEST_0003",
            "initialize_region null device test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_initialize_region_errors,
            "ATU_RSE_DRV_TEST_0004",
            "initialize_region argument error test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_initialize_region_ok,
            "ATU_RSE_DRV_TEST_0005",
            "initialize_region success test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_uninitialize_region_null_dev,
            "ATU_RSE_DRV_TEST_0006",
            "uninitialize_region null device test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_uninitialize_region_invalid_region,
            "ATU_RSE_DRV_TEST_0007",
            "uninitialize_region invalid region test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_uninitialize_region_ok,
            "ATU_RSE_DRV_TEST_0008",
            "uninitialize_region success test"
        },
    },
};

void add_natdrv_atu_rse_drv_tests(struct test_suite_t *p_ts, uint32_t ts_size) {
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}

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
#include "atu_config.h"
#include "atu_rse_lib.h"

#include "host_base_address.h"

static const struct atu_region_map_t test_atu_regions_static[] =
{
#ifdef RSE_USE_HOST_UART
    /* Non-Secure Uart Slot*/
    {
        .phys_addr = HOST_UART_BASE,
        .log_addr = HOST_UART0_BASE_NS,
        .size = HOST_UART_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
#endif
    /* Dummy slot 0*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
        .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
        .size = ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
    /* Dummy slot 1*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 1 * ATU_DUMMY_OFFSET,
        .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 1 * ATU_DUMMY_OFFSET,
        .size = ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    /* Dummy slot 2*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 2 * ATU_DUMMY_OFFSET,
        .log_addr = (ATU_DUMMY_SLOT_LOG_ADDR + 2 * ATU_DUMMY_OFFSET),
        .size = 3 * ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
};

const uint8_t test_atu_stat_count = sizeof(test_atu_regions_static)/sizeof(test_atu_regions_static[0]);

/* Clears all the test regions and initializes the default, static regions */
static void set_default_region_state(void)
{
    deinit_test_regions();

    (void)atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
}

static void test_natdrv_atu_rse_drv_init_null_dev(struct test_result_t *ret)
{
    enum atu_error_t err = atu_rse_drv_init(NULL, ATU_DOMAIN_ROOT, test_atu_regions_static,
                                            test_atu_stat_count);

    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ARG, "Expected atu driver initialization null device error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_init_static_count_overflow(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, ATU_STATIC_SLOT_COUNT + 1);
    TEST_ASSERT(err == ATU_ERR_STAT_CFG_COUNT, "Not enough slots");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_init_ok(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected atu driver initialization success");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_deinit_null_dev(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected atu driver initialization success");

    err = atu_rse_drv_deinit(NULL, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_UNINIT_REGION_INVALID_ARG,
        "Expected atu driver deinitialization null device error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_deinit_static_count_overflow(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_deinit(&ATU_DEV_S, ATU_STATIC_SLOT_COUNT + 1);
    TEST_ASSERT(err == ATU_ERR_STAT_CFG_COUNT, "Not enough slots");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_deinit_ok(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected atu driver initialization success");

    err = atu_rse_drv_deinit(&ATU_DEV_S, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected atu driver deinitialization success");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_rse_drv_init_addr_overlap_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_overlap[] =
    {
        /* Dummy slot 0*/
        {
            .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
            .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
            .size = ATU_DUMMY_SLOT_SIZE,
            .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
        },
        /* Dummy slot 1*/
        {
            .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 1 * ATU_DUMMY_OFFSET,
            .log_addr = ATU_DUMMY_SLOT_LOG_ADDR - ATU_DUMMY_SLOT_SIZE,
            .size = 3 * ATU_DUMMY_SLOT_SIZE,
            .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
        },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_overlap, 2);
    TEST_ASSERT(err == ATU_ERR_STAT_CFG_OVRLP,
        "Expected overlapping regions while initializing atu driver");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_map_addr_size_higher_than_range_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_automatically(NULL, ATU_DUMMY_SLOT_PHY_ADDR,
        ATU_DYN_NON_SEC_LOG_ADDR_SIZE, 0, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_MEM_INVALID_ARG, "NULL device error");

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                         ATU_DYN_NON_SEC_LOG_ADDR_SIZE, 0, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_MEM_SIZE_NOT_AVAILABLE, "Expected mapping address error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_map_addr_size_lower_than_page_size_ok(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;
    uint8_t ps;
    struct atu_dev_t *dev = &ATU_DEV_S;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;

    ps = ATU_GET_ATUPS(p_atu);

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful driver initialization");

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, 1 << (ps-1), 0,
                                         &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful address mapping");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_map_addr_size_zero_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Successful atu driver initialization");

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, 0, 0, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_MEM_INVALID_ARG, "Expected error while mapping as a result of wrong size");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_static_size_zero_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_size_zero[] =
    {
            /* Dummy slot 0*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
                .size = 0,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
            /* Dummy slot 1*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 1 * ATU_DUMMY_OFFSET,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 1 * ATU_DUMMY_OFFSET,
                .size = 0,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_size_zero, 1);
    TEST_ASSERT(err == ATU_ERR_MEM_INVALID_ARG, "Expected error as a result of zero size");

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_size_zero, 2);
    TEST_ASSERT(err == ATU_ERR_MEM_INVALID_ARG, "Expected error as a result of zero size");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_static_unsorted_log_addr_ok(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_unsorted_log_addr[] =
    {
            /* Dummy slot 0*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 2 * ATU_DUMMY_OFFSET,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 2 * ATU_DUMMY_OFFSET,
                .size = ATU_DUMMY_OFFSET,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
            /* Dummy slot 1*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 1 * ATU_DUMMY_OFFSET,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 1 * ATU_DUMMY_OFFSET,
                .size = ATU_DUMMY_OFFSET,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
            /* Dummy slot 2*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
                .size = ATU_DUMMY_OFFSET,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_unsorted_log_addr, 3);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_static_phys_addr_alignment_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_unaligned_phys_addr[] =
    {
            /* Dummy slot 0*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 0x1,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
                .size = 3 * ATU_DUMMY_SLOT_SIZE,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_unaligned_phys_addr, 1);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected atu alignment error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_static_log_addr_alignment_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_unaligned_log_addr[] =
    {
            /* Dummy slot 0*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 0x1,
                .size = 3 * ATU_DUMMY_SLOT_SIZE,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_unaligned_log_addr, 1);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected atu alignment error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_static_size_alignment_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    const struct atu_region_map_t atu_regions_static_unaligned_size[] =
    {
            /* Dummy slot 0*/
            {
                .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
                .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
                .size = 3 * ATU_DUMMY_SLOT_SIZE + 0x1,
                .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
            },
    };

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static_unaligned_size, 1);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected atu alignment error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_phys_addr_alignment_fail(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    atu_rse_drv_deinit(&ATU_DEV_S, test_atu_stat_count);

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, 0);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR + 0x1,
                                         ATU_DUMMY_SLOT_SIZE, 0, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_INIT_REGION_INVALID_ADDRESS, "Expected atu alignment error");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_size_alignment_ok(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                         ATU_DUMMY_SLOT_SIZE + 0x1, 0, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_use_existing_region(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_to_log_addr(NULL, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
        ATU_DUMMY_SLOT_SIZE * 2, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_MEM_INVALID_ARG, "NULL device error");

    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
                                       ATU_DUMMY_SLOT_SIZE * 2, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    /* Request same region with smaller size */
    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
                                       ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_map_and_free_all(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    for (int i = 0; i < ATU_DYN_SLOT_COUNT; i++) {

        err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S,
                                       ATU_DUMMY_SLOT_PHY_ADDR + i * ATU_DUMMY_SLOT_SIZE,
                                       ATU_DUMMY_SLOT_LOG_ADDR + i * ATU_DUMMY_SLOT_SIZE,
                                       ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
        TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");
    }

    /* Try another mapping a too high slot */
    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S,
                                   ATU_DUMMY_SLOT_PHY_ADDR + ATU_DYN_SLOT_COUNT * ATU_DUMMY_SLOT_SIZE,
                                   ATU_DUMMY_SLOT_LOG_ADDR + ATU_DYN_SLOT_COUNT * ATU_DUMMY_SLOT_SIZE,
                                   ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_SLOT_NOT_AVAIL, "No more available slots");

    /* Free all slots */
    for (int i = 0; i < ATU_DYN_SLOT_COUNT; i++) {
        err = atu_rse_free_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_LOG_ADDR + i * ATU_DUMMY_SLOT_SIZE);
        TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu freeing");
    }

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_map_same_region_overflow_size(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
                                       ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    /* Request same region with bigger size */
    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
                                       ATU_DUMMY_SLOT_SIZE * 2, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_MAPPING_TOO_SMALL, "The found region should be too small");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_use_existing_region_different_phys(struct test_result_t *ret)
{
    enum atu_error_t err;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);

    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_LOG_ADDR,
                                       3 * ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                       ATU_DUMMY_SLOT_LOG_ADDR + ATU_DUMMY_SLOT_SIZE,
                                       3 * ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Same region with different add value is erronous");

    /*
     * The requests start inside of an existing logical region that should be reused, but the
     * physical region is different
     */
    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR + 3 * ATU_DUMMY_SLOT_SIZE,
                                       ATU_DUMMY_SLOT_LOG_ADDR + ATU_DUMMY_SLOT_SIZE,
                                       3 * ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_MAPPING_INVALID, "Region with overlapping logical space is erronous");

    /* Now allocate the same region with a total different logical address */
    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                       ATU_DUMMY_SLOT_LOG_ADDR + 3 * ATU_DUMMY_SLOT_SIZE,
                                       3 * ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR);
    TEST_ASSERT(err == ATU_ERR_INVALID_REGION, "Can not access physical region from multiple logical ones");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_dyn_slot_user_counting(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, test_atu_regions_static, test_atu_stat_count);

    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    for (int i = 0; i < UINT8_MAX; i++) {
        err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                             ATU_DUMMY_SLOT_SIZE, ATU_SEC_OUT_ATTR,
                                             &log_addr, &size);
        TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");
    }

    /* Try another mapping a too high slot */
    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_SIZE,
                                         ATU_SEC_OUT_ATTR, &log_addr, &size);
    TEST_ASSERT(err == ATU_MAPPING_NOT_AVAIL, "Too many users");

    /* Free a single user */
    err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu freeing");

    /* Now a new user can use it */
    err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR, ATU_DUMMY_SLOT_SIZE,
                                         ATU_SEC_OUT_ATTR, &log_addr, &size);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static void test_natdrv_atu_domain_test(struct test_result_t *ret)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    uint8_t secure_domains = ATU_DOMAIN_SECURE | ATU_DOMAIN_REALM;

    err = atu_rse_drv_init(&ATU_DEV_S, secure_domains, test_atu_regions_static, 0);
    TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu driver initialization");

    for (uint8_t nse_bit = 0; nse_bit < 2; nse_bit++) {
        for (uint8_t prot1_bit = 0; prot1_bit < 2; prot1_bit++) {
            uint8_t out_bus_attr = (nse_bit << ATU_ATUROBA_AXNSE_OFF) |
                                   (prot1_bit << ATU_ATUROBA_AXPROT1_OFF);

            bool is_secure = ((nse_bit << 1) | prot1_bit) & secure_domains;

            err = atu_rse_map_addr_automatically(&ATU_DEV_S, ATU_DUMMY_SLOT_PHY_ADDR,
                                                 ATU_DUMMY_SLOT_SIZE, out_bus_attr,
                                                 &log_addr, &size);

            TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful atu address mapping");

            if (is_secure) {
                TEST_ASSERT(ATU_DYN_SEC_LOG_ADDR_START <= log_addr &&
                            log_addr < ATU_DYN_SEC_LOG_ADDR_START + ATU_DYN_SEC_LOG_ADDR_SIZE,
                            "Expected successful atu address mapping");
            } else {
                TEST_ASSERT(ATU_DYN_NON_SEC_LOG_ADDR_START <= log_addr &&
                            log_addr < ATU_DYN_NON_SEC_LOG_ADDR_START + ATU_DYN_NON_SEC_LOG_ADDR_SIZE,
                            "Expected successful atu address mapping");
            }

            err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
            TEST_ASSERT(err == ATU_ERR_NONE, "Expected successful freeing of region");
        }
    }

    set_default_region_state();

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] =
{
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_init_null_dev,
            "ATU_RSE_LIB_TEST_0001",
            "atu_rse_drv_init null device test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_init_static_count_overflow,
            "ATU_RSE_LIB_TEST_0002",
            "atu_rse_drv_init slot count arg overflow"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_init_ok,
            "ATU_RSE_LIB_TEST_0003",
            "atu_rse_drv_init success test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_deinit_null_dev,
            "ATU_RSE_LIB_TEST_0004",
            "atu_rse_drv_deinit null device test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_deinit_static_count_overflow,
            "ATU_RSE_LIB_TEST_0005",
            "atu_rse_drv_deinit slot count arg overflow"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_deinit_ok,
            "ATU_RSE_LIB_TEST_0006",
            "atu_rse_drv_deinit success test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_rse_drv_init_addr_overlap_fail,
            "ATU_RSE_LIB_TEST_0007",
            "atu_rse_drv_init address overlapping test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_map_addr_size_higher_than_range_fail,
            "ATU_RSE_LIB_TEST_0008",
            "atu_map_addr size overflow test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_map_addr_size_lower_than_page_size_ok,
            "ATU_RSE_LIB_TEST_0009",
            "atu_map_addr size alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_map_addr_size_zero_fail,
            "ATU_RSE_LIB_TEST_0010",
            "atu_map_addr zero size test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_static_size_zero_fail,
            "ATU_RSE_LIB_TEST_0011",
            "atu_rse_drv_init static configuration size error test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_static_unsorted_log_addr_ok,
            "ATU_RSE_LIB_TEST_0012",
            "atu_rse_drv_init unsorted static config test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_static_phys_addr_alignment_fail,
            "ATU_RSE_LIB_TEST_0013",
            "atu_rse_drv_init static config physical address alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_static_log_addr_alignment_fail,
            "ATU_RSE_LIB_TEST_0014",
            "atu_rse_drv_init static config logical address alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_static_size_alignment_fail,
            "ATU_RSE_LIB_TEST_0015",
            "atu_rse_drv_init static config size alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_phys_addr_alignment_fail,
            "ATU_RSE_LIB_TEST_0016",
            "atu_map_addr dynamic config physical address alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_size_alignment_ok,
            "ATU_RSE_LIB_TEST_0017",
            "atu_map_addr dynamic config size alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_use_existing_region,
            "ATU_RSE_LIB_TEST_0018",
            "atu_map_addr dynamic config size alignment test"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_map_and_free_all,
            "ATU_RSE_LIB_TEST_0019",
            "Fill all slots and free them"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_map_same_region_overflow_size,
            "ATU_RSE_LIB_TEST_0020",
            "Request existing region, but too huge size"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_use_existing_region_different_phys,
            "ATU_RSE_LIB_TEST_0021",
            "Requesting existing region with different add value"
        },
    },
    /* FixMe: Re-enable this test once the FVP is fixed for ATURGPV truncation */
#if 0
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_dyn_slot_user_counting,
            "ATU_RSE_LIB_TEST_0022",
            "Test the user counter of the slots"
        },
    },
#endif
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_atu_domain_test,
            "ATU_RSE_LIB_TEST_0023",
            "Testing domain handling"
        },
    },
};

void add_natdrv_atu_rse_lib_tests(struct test_suite_t *p_ts, uint32_t ts_size) {
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}

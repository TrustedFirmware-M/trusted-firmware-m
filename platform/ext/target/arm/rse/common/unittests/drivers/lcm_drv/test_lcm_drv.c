/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "lcm_drv.h"
#include "lcm_otp_layout.h"
#include "unity.h"

/* Lifecycle state reset value */
#define LCM_LCS_VALUE_RESET_VALUE 0xEEEEA5A5u
/* OTP Keys error status reset value */
#define LCM_KEY_ERR_RESET_VALUE 0x3Fu
/* Test or production mode reset value */
#define LCM_TP_MODE_RESET_VALUE 0x2222AA55u
/* Fatal error FSM state reset value */
#define LCM_FATAL_ERR_RESET_VALUE 0x0u
/* RMA flag lock enable reset value */
#define LCM_DM_RMA_LOCK_RESET_VALUE 0x0u
/* Secure provisioning enable reset value */
#define LCM_SP_ENABLE_RESET_VALUE 0x0u
/* OTP address width reset value */
#define LCM_OTP_ADDR_WIDTH_RESET_VALUE 0xFu
/* OTP memory size in bytes reset value */
#define LCM_OTP_SIZE_IN_BYTES_RESET_VALUE 0x4000u
/* General purpose persistent conﬁguration reset value */
#define LCM_GPPC_RESET_VALUE 0x0u
/* Debug Control Unit enable reset value */
#define LCM_DCU_ENABLE_RESET_VALUE 0x0u
/* Debug Control Unit lock reset value */
#define LCM_DCU_LOCK_RESET_VALUE 0x0u
/* Debug Control Unit SP disable mask reset value */
#define LCM_DCU_SP_DISABLE_MASK_RESET_VALUE 0xFFFFFFFFu
/* Debug Control Unit disable mask reset value */
#define LCM_DCU_DISABLE_MASK_RESET_VALUE 0xFFFFFFFFu
/* Peripheral ID 0 register */
#define LCM_PIDR0_RESET_VALUE 0xF5u
/* Peripheral ID 1 register */
#define LCM_PIDR1_RESET_VALUE 0xB0u
/* Peripheral ID 2 register */
#define LCM_PIDR2_RESET_VALUE 0x0Bu
/* Peripheral ID 3 register */
#define LCM_PIDR3_RESET_VALUE 0x0u
/* Peripheral ID 4 register */
#define LCM_PIDR4_RESET_VALUE 0xF4u
/* Component ID 0 register */
#define LCM_CIDR0_RESET_VALUE 0xDu
/* Component ID 1 register */
#define LCM_CIDR1_RESET_VALUE 0xF0u
/* Component ID 2 register */
#define LCM_CIDR2_RESET_VALUE 0x5u
/* Component ID 3 register */
#define LCM_CIDR3_RESET_VALUE 0xB1u

/* Arm Lifecycle Manager (LCM) Speciﬁcation (107616_0000_01_en) */
struct _lcm_reg_map_t {
    volatile uint32_t lcs_value;
    /*!< Offset: 0x000 (R/ ) LCM Lifecycle state Register */
    volatile uint32_t key_err;
    /*!< Offset: 0x004 (R/ ) LCM zero count error status Register */
    volatile uint32_t tp_mode;
    /*!< Offset: 0x008 (R/ ) LCM TP Mode (TCI/PCI) Register */
    volatile uint32_t fatal_err;
    /*!< Offset: 0x00C (R/W) LCM Fatal Error mode Enable Register */
    volatile uint32_t dm_rma_lock;
    /*!< Offset: 0x010 (R/W) LCM DRM RMA Flag lock enable */
    volatile uint32_t sp_enable;
    /*!< Offset: 0x014 (R/W) LCM Secure Provisioning enable
     *                       Register */
    volatile uint32_t otp_addr_width;
    /*!< Offset: 0x018 (R/ ) LCM OTP Address Width Register  */
    volatile uint32_t otp_size_in_bytes;
    /*!< Offset: 0x01C (R/ ) LCM OTP Size in bytes Register */
    volatile uint32_t gppc;
    /*!< Offset: 0x020 (R/ ) LCM General Purpose Persistent
     *                       Configuration Register */
    volatile uint32_t reserved_0[55];
    /*!< Offset: 0x024-0x0FC Reserved */
    volatile uint32_t dcu_en[4];
    /*!< Offset: 0x100 (R/W) LCM DCU enable Registers */
    volatile uint32_t dcu_lock[4];
    /*!< Offset: 0x110 (R/W) LCM DCU lock Registers */
    volatile uint32_t dcu_sp_disable_mask[4];
    /*!< Offset: 0x120 (R/ ) LCM DCU SP disable mask Registers */
    volatile uint32_t dcu_disable_mask[4];
    /*!< Offset: 0x130 (R/ ) LCM DCU disable mask Registers */
    volatile uint32_t reserved_1[932];
    /*!< Offset: 0x140-0xFCC Reserved */
    volatile uint32_t pidr4;
    /*!< Offset: 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved_2[3];
    /*!< Offset: 0xFD4-0xFDC Reserved */
    volatile uint32_t pidr0;
    /*!< Offset: 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;
    /*!< Offset: 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;
    /*!< Offset: 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;
    /*!< Offset: 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;
    /*!< Offset: 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;
    /*!< Offset: 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;
    /*!< Offset: 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;
    /*!< Offset: 0xFFC (R/ ) Component ID 3 */
    union {
        volatile uint32_t raw_otp[16384];
        /*!< Offset: 0x1000 (R/W) OTP direct access */
        struct lcm_otp_layout_t otp;
    };
} regmap;

static struct lcm_dev_cfg_t LCM_DEV_CFG_S = {.base = (uintptr_t)&regmap};
struct lcm_dev_t LCM_DEV_S = {.cfg = &(LCM_DEV_CFG_S)};

/* Set KMU Registers to their default reset values */
void set_default_regmap_values(void)
{
    regmap.lcs_value = LCM_LCS_VALUE_RESET_VALUE;
    regmap.key_err = LCM_KEY_ERR_RESET_VALUE;
    regmap.tp_mode = LCM_TP_MODE_RESET_VALUE;
    regmap.fatal_err = LCM_FATAL_ERR_RESET_VALUE;
    regmap.dm_rma_lock = LCM_DM_RMA_LOCK_RESET_VALUE;
    regmap.sp_enable = LCM_SP_ENABLE_RESET_VALUE;
    regmap.otp_addr_width = LCM_OTP_ADDR_WIDTH_RESET_VALUE;
    regmap.otp_size_in_bytes = LCM_OTP_SIZE_IN_BYTES_RESET_VALUE;
    regmap.gppc = LCM_GPPC_RESET_VALUE;
    memset((void *)regmap.reserved_0, 0x0u, sizeof(regmap.reserved_0));
    memset((void *)regmap.dcu_en, LCM_DCU_ENABLE_RESET_VALUE,
           sizeof(regmap.dcu_en));
    memset((void *)regmap.dcu_lock, LCM_DCU_LOCK_RESET_VALUE,
           sizeof(regmap.dcu_lock));
    memset((void *)regmap.dcu_sp_disable_mask,
           LCM_DCU_SP_DISABLE_MASK_RESET_VALUE,
           sizeof(regmap.dcu_sp_disable_mask));
    memset((void *)regmap.dcu_disable_mask, LCM_DCU_DISABLE_MASK_RESET_VALUE,
           sizeof(regmap.dcu_disable_mask));
    memset((void *)regmap.reserved_1, 0x0u, sizeof(regmap.reserved_1));
    regmap.pidr4 = LCM_PIDR4_RESET_VALUE;
    memset((void *)regmap.reserved_2, 0x0u, sizeof(regmap.reserved_2));
    regmap.pidr0 = LCM_PIDR0_RESET_VALUE;
    regmap.pidr1 = LCM_PIDR1_RESET_VALUE;
    regmap.pidr2 = LCM_PIDR2_RESET_VALUE;
    regmap.pidr3 = LCM_PIDR3_RESET_VALUE;
    regmap.cidr0 = LCM_CIDR0_RESET_VALUE;
    regmap.cidr1 = LCM_CIDR1_RESET_VALUE;
    regmap.cidr2 = LCM_CIDR2_RESET_VALUE;
    regmap.cidr3 = LCM_CIDR3_RESET_VALUE;
    memset((void *)regmap.raw_otp, 0x0u, sizeof(regmap.raw_otp));
}

/* Verify that Read-Only registers have not been modified */
void verify_read_only_registers(void)
{
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        LCM_LCS_VALUE_RESET_VALUE, regmap.lcs_value,
        "Read-Only register LCS_VALUE was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_KEY_ERR_RESET_VALUE, regmap.key_err,
                                     "Read-Only register KEY_ERR was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_TP_MODE_RESET_VALUE, regmap.tp_mode,
                                     "Read-Only register TP_MODE was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        LCM_OTP_ADDR_WIDTH_RESET_VALUE, regmap.otp_addr_width,
        "Read-Only register OTP_ADDR_WIDTH was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        LCM_OTP_SIZE_IN_BYTES_RESET_VALUE, regmap.otp_size_in_bytes,
        "Read-Only register OTP_SIZE_IN_BYTES was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_GPPC_RESET_VALUE, regmap.gppc,
                                     "Read-Only register GPPC was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_PIDR0_RESET_VALUE, regmap.pidr0,
                                     "Read-Only register PIDR0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_PIDR1_RESET_VALUE, regmap.pidr1,
                                     "Read-Only register PIDR1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_PIDR2_RESET_VALUE, regmap.pidr2,
                                     "Read-Only register PIDR2 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_PIDR3_RESET_VALUE, regmap.pidr3,
                                     "Read-Only register PIDR3 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_PIDR4_RESET_VALUE, regmap.pidr4,
                                     "Read-Only register PIDR4 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_CIDR0_RESET_VALUE, regmap.cidr0,
                                     "Read-Only register CIDR0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_CIDR1_RESET_VALUE, regmap.cidr1,
                                     "Read-Only register CIDR1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_CIDR2_RESET_VALUE, regmap.cidr2,
                                     "Read-Only register CIDR2 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(LCM_CIDR3_RESET_VALUE, regmap.cidr3,
                                     "Read-Only register CIDR3 was modified");
}

void setUp(void) { set_default_regmap_values(); }

void tearDown(void) { verify_read_only_registers(); }

TEST_CASE(LCM_LCS_INVALID, 0x0u, LCM_ERROR_GET_LCS_INVALID_LCS)
TEST_CASE(LCM_LCS_SE, 0x1u, LCM_ERROR_INIT_INVALID_KEY)
TEST_CASE(LCM_LCS_RMA, 0x0u, LCM_ERROR_NONE)
TEST_CASE(LCM_LCS_SE, 0x0u, LCM_ERROR_NONE)
void test_lcm_init(uint32_t lcs_value, uint32_t key_err,
                   enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;

    /* Prepare */
    regmap.key_err = key_err;
    regmap.lcs_value = lcs_value;

    /* Act */
    lcm_err = lcm_init(&LCM_DEV_S);

    /* Cleanup */
    regmap.key_err = LCM_KEY_ERR_RESET_VALUE;
    regmap.lcs_value = LCM_LCS_VALUE_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
    /* TODO: Maybe add an assert to compare raw otp
     *       from 0 to rotpk are 0xff */
}

TEST_CASE(LCM_LCS_INVALID, LCM_TP_MODE_VIRGIN, LCM_TP_MODE_TCI, 0x00000000u,
          LCM_ERROR_GET_LCS_INVALID_LCS)
TEST_CASE(LCM_LCS_SE, LCM_TP_MODE_VIRGIN, LCM_TP_MODE_TCI, 0x00000000u,
          LCM_ERROR_SET_TP_MODE_INVALID_LCS)
TEST_CASE(LCM_LCS_CM, LCM_TP_MODE_TCI, LCM_TP_MODE_TCI, 0x00000000u,
          LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION)
TEST_CASE(LCM_LCS_CM, LCM_TP_MODE_VIRGIN, LCM_TP_MODE_INVALID, 0x00000000u,
          LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION)
TEST_CASE(LCM_LCS_CM, LCM_TP_MODE_VIRGIN, LCM_TP_MODE_TCI, 0x0000FFFFu,
          LCM_ERROR_NONE)
TEST_CASE(LCM_LCS_CM, LCM_TP_MODE_VIRGIN, LCM_TP_MODE_PCI, 0xFFFF0000u,
          LCM_ERROR_NONE)
void test_lcm_set_tp_mode(uint32_t lcs_value, enum lcm_tp_mode_t curr_tp_mode,
                          enum lcm_tp_mode_t tp_mode,
                          uint32_t expected_mode_reg_val,
                          enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t offset;

    /* Prepare */
    regmap.lcs_value = lcs_value;
    regmap.tp_mode = curr_tp_mode;

    offset = offsetof(struct lcm_otp_layout_t, tp_mode_config);

    /* Act */
    lcm_err = lcm_set_tp_mode(&LCM_DEV_S, tp_mode);

    /* Cleanup */
    regmap.lcs_value = LCM_LCS_VALUE_RESET_VALUE;
    regmap.tp_mode = LCM_TP_MODE_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(regmap.raw_otp[offset / sizeof(uint32_t)],
                             expected_mode_reg_val);
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

static void *lcm_sp_enable_hw_op(void *thread_args)
{
    while (regmap.sp_enable != 0x5EC10E1Eu) {
    }
    regmap.sp_enable = LCM_TRUE;

    return NULL;
}

TEST_CASE(LCM_TP_MODE_INVALID, LCM_FALSE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INVALID_TP_MODE)
TEST_CASE(LCM_TP_MODE_TCI, LCM_TRUE, LCM_TRUE,
          LCM_ERROR_SET_SP_ENABLED_FATAL_ERROR)
TEST_CASE(LCM_TP_MODE_TCI, LCM_FALSE, LCM_TRUE, LCM_ERROR_NONE)
void test_lcm_set_sp_enabled(enum lcm_tp_mode_t tp_mode, uint32_t fatal_err,
                             uint32_t expected_sp_enable,
                             enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    int32_t pthread_err;
    pthread_t pthread_id;

    /* Prepare */
    regmap.tp_mode = tp_mode;
    regmap.fatal_err = fatal_err;

    /* Act */
    switch (tp_mode) {
    case LCM_TP_MODE_PCI:
    case LCM_TP_MODE_TCI:
        pthread_err =
            pthread_create(&pthread_id, NULL, lcm_sp_enable_hw_op, NULL);
        TEST_ASSERT_EQUAL_INT_MESSAGE(
            0, pthread_err, "Failed to create lcm_sp_enable_hw_op thread");
    }

    lcm_err = lcm_set_sp_enabled(&LCM_DEV_S);

    switch (tp_mode) {
    case LCM_TP_MODE_PCI:
    case LCM_TP_MODE_TCI:
        pthread_err = pthread_join(pthread_id, NULL);
        TEST_ASSERT_EQUAL_INT_MESSAGE(
            0, pthread_err, "Failed to join lcm_sp_enable_hw_op thread");
    }

    /* Cleanup */
    regmap.tp_mode = LCM_TP_MODE_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(regmap.sp_enable, expected_sp_enable);
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

void test_lcm_set_fatal_error(void)
{
    uint32_t expected_fatal_err;

    /* Prepare */
    expected_fatal_err = 0xFA7A1EEEu;

    /* Act */
    lcm_set_fatal_error(&LCM_DEV_S);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(regmap.fatal_err, expected_fatal_err);
}

void test_lcm_get_gppc(void)
{
    uint32_t gppc;
    uint32_t expected_gppc;

    /* Prepare */
    expected_gppc = 0xAA00AA00;
    regmap.gppc = expected_gppc;

    /* Act */
    lcm_get_gppc(&LCM_DEV_S, &gppc);

    /* Cleanup */
    regmap.gppc = LCM_GPPC_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(gppc, expected_gppc);
}

TEST_CASE(LCM_TRUE, LCM_LCS_CM, LCM_ERROR_GET_LCS_FATAL_ERROR)
TEST_CASE(LCM_FALSE, LCM_LCS_INVALID, LCM_ERROR_GET_LCS_INVALID_LCS)
TEST_CASE(LCM_FALSE, LCM_LCS_CM, LCM_ERROR_NONE)
void test_lcm_get_lcs(uint32_t fatal_err, uint32_t lcs_value,
                      enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;

    /* Prepare */
    regmap.fatal_err = fatal_err;
    regmap.lcs_value = lcs_value;

    /* Act */
    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);

    /* Cleanup */
    regmap.lcs_value = LCM_LCS_VALUE_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(LCM_LCS_INVALID, LCM_LCS_DM, LCM_TP_MODE_VIRGIN, LCM_FALSE, LCM_FALSE,
          LCM_ERROR_GET_LCS_INVALID_LCS)
TEST_CASE(LCM_LCS_DM, LCM_LCS_DM, LCM_TP_MODE_VIRGIN, LCM_FALSE, LCM_FALSE,
          LCM_ERROR_NONE)
TEST_CASE(LCM_LCS_CM, LCM_LCS_DM, LCM_TP_MODE_INVALID, LCM_FALSE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INVALID_TP_MODE)
TEST_CASE(LCM_LCS_CM, LCM_LCS_INVALID, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INVALID_LCS)
TEST_CASE(LCM_LCS_CM, 0x0u, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INTERNAL_ERROR)
TEST_CASE(LCM_LCS_DM, LCM_LCS_CM, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INVALID_TRANSITION)
TEST_CASE(LCM_LCS_RMA, LCM_LCS_DM, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_SET_LCS_INVALID_TRANSITION)
TEST_CASE(LCM_LCS_CM, LCM_LCS_DM, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_CM_TO_DM_WRITE_VERIFY_FAIL)
TEST_CASE(LCM_LCS_DM, LCM_LCS_SE, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_DM_TO_SE_WRITE_VERIFY_FAIL)
TEST_CASE(LCM_LCS_DM, LCM_LCS_RMA, LCM_TP_MODE_TCI, LCM_TRUE, LCM_FALSE,
          LCM_ERROR_NONE)
void test_lcm_set_lcs(enum lcm_lcs_t curr_lcs, enum lcm_lcs_t lcs,
                      enum lcm_tp_mode_t tp_mode, enum lcm_bool_t sp_enable,
                      enum lcm_bool_t fatal_err, enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint16_t gppc_val;

    /* Prepare */
    gppc_val = 0;
    regmap.lcs_value = curr_lcs;
    regmap.tp_mode = tp_mode;
    regmap.sp_enable = sp_enable;
    regmap.fatal_err = fatal_err;

    /* Act */
    lcm_err = lcm_set_lcs(&LCM_DEV_S, lcs, gppc_val);

    /* Cleanup */
    regmap.lcs_value = LCM_LCS_VALUE_RESET_VALUE;
    regmap.tp_mode = LCM_TP_MODE_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0xE0u, 0x0004u, 0x0u, LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0x01u, 0x0000u, 0x0u, LCM_ERROR_OTP_WRITE_INVALID_OFFSET)
TEST_CASE(0x0u, 0xE0u, 0x0001u, 0x0u, LCM_ERROR_OTP_WRITE_INVALID_LENGTH)
TEST_CASE(0x0u, 0xE0u, 0x4000u, 0x0u, LCM_ERROR_OTP_WRITE_INVALID_OFFSET)
TEST_CASE(0x0u, 0xC0u, 0x0020u, 0x0u, LCM_ERROR_NONE)
TEST_CASE(0x0u, 0xE0u, 0x0004u, 0xA0A0A0A0, LCM_ERROR_NONE)
void test_lcm_otp_write(uint32_t buf_offset, uint32_t offset, uint32_t len,
                        uint32_t val, enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t buf[0x10];

    /* Prepare */
    memcpy(buf, &val, sizeof(uint32_t));

    /* Act */
    lcm_err =
        lcm_otp_write(&LCM_DEV_S, offset, len, (uint8_t *)buf + buf_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(regmap.raw_otp[offset / sizeof(uint32_t)], val);
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x10B0u, 0x0004u, 0x0u, LCM_ERROR_OTP_READ_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0x0001u, 0x0000u, 0x0u, LCM_ERROR_OTP_READ_INVALID_OFFSET)
TEST_CASE(0x0u, 0x10B0u, 0x0001u, 0x0u, LCM_ERROR_OTP_READ_INVALID_LENGTH)
TEST_CASE(0x0u, 0x10B0u, 0x4000u, 0x0u, LCM_ERROR_OTP_READ_INVALID_OFFSET)
TEST_CASE(0x0u, 0x10B0u, 0x0004u, 0xA0A0A0A0, LCM_ERROR_NONE)
void test_lcm_otp_read(uint32_t buf_offset, uint32_t offset, uint32_t len,
                       uint32_t val, enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t buf[0x10];

    /* Prepare */
    regmap.raw_otp[offset / sizeof(uint32_t)] = val;
    memset(buf, 0x0u, sizeof(buf));

    /* Act */
    lcm_err =
        lcm_otp_read(&LCM_DEV_S, offset, len, (uint8_t *)buf + buf_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(buf[0], val);
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1, LCM_ERROR_DCU_GET_ENABLED_INVALID_ALIGNMENT)
TEST_CASE(0x0, LCM_ERROR_NONE)
void test_lcm_dcu_get_enabled(uint32_t p_val_offset,
                              enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Act */
    lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x00u, 0x00u, LCM_ERROR_DCU_SET_ENABLED_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0xF0u, 0x0Fu, LCM_ERROR_DCU_CHECK_MASK_MISMATCH)
TEST_CASE(0x0u, 0x0Fu, 0x0Fu, LCM_ERROR_NONE)
void test_lcm_dcu_set_enabled(uint32_t p_val_offset, uint8_t dcu_disable_mask,
                              uint8_t dcu_en, enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Prepare */
    memset((void *)regmap.dcu_disable_mask, dcu_disable_mask,
           sizeof(regmap.dcu_disable_mask));
    memset(val, dcu_en, sizeof(val));

    /* Act */
    lcm_err = lcm_dcu_set_enabled(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x00u, LCM_ERROR_DCU_GET_LOCKED_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0xAAu, LCM_ERROR_NONE)
void test_lcm_dcu_get_locked(uint32_t p_val_offset, uint8_t dcu_lock,
                             enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t expected_dcu_lock[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Prepare */
    memset((void *)val, 0x0u, sizeof(val));
    memset((void *)regmap.dcu_lock, dcu_lock, sizeof(regmap.dcu_lock));
    memset((void *)expected_dcu_lock, dcu_lock, sizeof(expected_dcu_lock));

    /* Act */
    lcm_err = lcm_dcu_get_locked(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32_ARRAY(val, expected_dcu_lock,
                                   LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t));
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x00u, LCM_ERROR_DCU_SET_LOCKED_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0xAAu, LCM_ERROR_NONE)
void test_lcm_dcu_set_locked(uint32_t p_val_offset, uint8_t dcu_lock,
                             enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t expected_dcu_lock[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Prepare */
    memset(val, dcu_lock, sizeof(val));
    memset((void *)expected_dcu_lock, dcu_lock, sizeof(expected_dcu_lock));

    /* Act */
    lcm_err = lcm_dcu_set_locked(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32_ARRAY(regmap.dcu_lock, expected_dcu_lock,
                                   LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t));
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x00u, LCM_ERROR_DCU_GET_SP_DISABLE_MASK_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0xAAu, LCM_ERROR_NONE)
void test_lcm_dcu_get_sp_disable_mask(uint32_t p_val_offset,
                                      uint8_t dcu_sp_disable_mask,
                                      enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t
        expected_dcu_sp_disable_mask[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Prepare */
    memset((void *)val, 0x0u, sizeof(val));
    memset((void *)regmap.dcu_sp_disable_mask, dcu_sp_disable_mask,
           sizeof(regmap.dcu_sp_disable_mask));
    memset((void *)expected_dcu_sp_disable_mask, dcu_sp_disable_mask,
           sizeof(expected_dcu_sp_disable_mask));

    /* Act */
    lcm_err =
        lcm_dcu_get_sp_disable_mask(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32_ARRAY(val, expected_dcu_sp_disable_mask,
                                   LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t));
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

TEST_CASE(0x1u, 0x00u, LCM_ERROR_DCU_GET_DISABLE_MASK_INVALID_ALIGNMENT)
TEST_CASE(0x0u, 0xAAu, LCM_ERROR_NONE)
void test_lcm_dcu_get_disable_mask(uint32_t p_val_offset,
                                   uint8_t dcu_disable_mask,
                                   enum lcm_error_t expected_err)
{
    enum lcm_error_t lcm_err;
    uint32_t val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t
        expected_dcu_disable_mask[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    /* Prepare */
    memset((void *)val, 0x0u, sizeof(val));
    memset((void *)regmap.dcu_disable_mask, dcu_disable_mask,
           sizeof(regmap.dcu_disable_mask));
    memset((void *)expected_dcu_disable_mask, dcu_disable_mask,
           sizeof(expected_dcu_disable_mask));

    /* Act */
    lcm_err =
        lcm_dcu_get_disable_mask(&LCM_DEV_S, (uint8_t *)val + p_val_offset);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32_ARRAY(val, expected_dcu_disable_mask,
                                   LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t));
    TEST_ASSERT_EQUAL(lcm_err, expected_err);
}

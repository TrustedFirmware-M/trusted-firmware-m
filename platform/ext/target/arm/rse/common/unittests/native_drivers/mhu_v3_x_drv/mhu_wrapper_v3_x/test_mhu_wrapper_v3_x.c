/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>

#include "mhu.h"
#include "mhu_v3_x.h"

#include "mock_mhu_v3_x.h"

#include "unity.h"

#define MHU_NOTIFY_VALUE (1234u)

uint32_t MHU_RECEIVER_DEV_BASE;
static struct mhu_v3_x_dev_t MHU_RECEIVER_DEV = {
    .version = 3,
    .base = (uintptr_t)&MHU_RECEIVER_DEV_BASE,
    .frame = MHU_V3_X_MBX_FRAME,
    .subversion = 0};

uint32_t MHU_SENDER_DEV_BASE;
static struct mhu_v3_x_dev_t MHU_SENDER_DEV = {
    .version = 3,
    .base = (uintptr_t)&MHU_SENDER_DEV_BASE,
    .frame = MHU_V3_X_PBX_FRAME,
    .subversion = 0};

void test_signal_and_wait_for_clear_invalid_dev_arg(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;

    /* Act */
    mhu_err = signal_and_wait_for_clear(NULL, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG, mhu_err);
}

void test_signal_and_wait_for_clear_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = signal_and_wait_for_clear(&MHU_SENDER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_signal_and_wait_for_clear_read_pending_transfer_ack_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, NULL,
        MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&value,
                                                  sizeof(value));

    /* Act */
    mhu_err = signal_and_wait_for_clear(&MHU_SENDER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_signal_and_wait_for_clear_notify_transfer_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = 0x0;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    mhu_v3_x_doorbell_write_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, value,
        MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM);

    /* Act */
    mhu_err = signal_and_wait_for_clear(&MHU_SENDER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_signal_and_wait_for_clear_read_transfer_ack_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = 0x0;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                            value, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, NULL,
        MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    /* Act */
    mhu_err = signal_and_wait_for_clear(&MHU_SENDER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_signal_and_wait_for_clear_ok(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = 0x0;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                            value, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    /* Act */
    mhu_err = signal_and_wait_for_clear(&MHU_SENDER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_wait_for_signal_and_clear_invalid_dev_arg(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;

    /* Act */
    mhu_err = wait_for_signal_and_clear(NULL, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_WAIT_SIGNAL_CLEAR_INVALID_ARG, mhu_err);
}

void test_wait_for_signal_and_clear_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = wait_for_signal_and_clear(&MHU_RECEIVER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_wait_for_signal_and_clear_read_transfer_ack_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_RECEIVER_DEV, num_channels - 1, NULL,
        MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    /* Act */
    mhu_err = wait_for_signal_and_clear(&MHU_RECEIVER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_wait_for_signal_and_clear_transfer_ack_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    mhu_v3_x_doorbell_clear_ExpectAndReturn(
        &MHU_RECEIVER_DEV, num_channels - 1, value,
        MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM);

    /* Act */
    mhu_err = wait_for_signal_and_clear(&MHU_RECEIVER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM, mhu_err);
}

void test_wait_for_signal_and_clear_ok(void)
{
    enum mhu_error_t mhu_err;
    uint32_t value;
    uint32_t read_value;
    uint8_t num_channels;

    /* Prepare */
    value = MHU_NOTIFY_VALUE;
    read_value = MHU_NOTIFY_VALUE;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    mhu_v3_x_doorbell_clear_ExpectAndReturn(&MHU_RECEIVER_DEV, num_channels - 1,
                                            value, MHU_V_3_X_ERR_NONE);

    /* Act */
    mhu_err = wait_for_signal_and_clear(&MHU_RECEIVER_DEV, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_init_sender_invalid_dev_arg(void)
{
    enum mhu_error_t mhu_err;

    /* Act */
    mhu_err = mhu_init_sender(NULL);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_INIT_SENDER_INVALID_ARG, mhu_err);
}

void test_mhu_init_sender_driver_init_fails(void)
{
    enum mhu_error_t mhu_err;

    /* Prepare */
    mhu_v3_x_driver_init_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION);

    /* Act */
    mhu_err = mhu_init_sender(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_init_sender_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;

    /* Prepare */
    num_channels = 0x10;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_init_sender(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_init_sender_insufficient_supported_channels(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;

    /* Prepare */
    num_channels = 0x1;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_init_sender(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_INIT_SENDER_UNSUPPORTED, mhu_err);
}

void test_mhu_init_sender_channel_interrupt_disable_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_channel_interrupt_disable_ExpectAndReturn(
        &MHU_SENDER_DEV, channel, MHU_V3_X_CHANNEL_TYPE_DBCH,
        MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED);

    /* Act */
    mhu_err = mhu_init_sender(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED, mhu_err);
}

void test_mhu_init_sender_ok(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    for (channel = 0; channel < num_channels; ++channel) {
        mhu_v3_x_channel_interrupt_disable_ExpectAndReturn(
            &MHU_SENDER_DEV, channel, MHU_V3_X_CHANNEL_TYPE_DBCH,
            MHU_V_3_X_ERR_NONE);
    }

    /* Act */
    mhu_err = mhu_init_sender(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_init_receiver_invalid_dev_arg(void)
{
    enum mhu_error_t mhu_err;

    /* Act */
    mhu_err = mhu_init_receiver(NULL);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_INIT_RECEIVER_INVALID_ARG, mhu_err);
}

void test_mhu_init_receiver_driver_init_fails(void)
{
    enum mhu_error_t mhu_err;

    /* Prepare */
    mhu_v3_x_driver_init_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION);

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_RECEIVER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_init_receiver_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;

    /* Prepare */
    num_channels = 0x10;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_RECEIVER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_RECEIVER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_init_receiver_insufficient_supported_channels(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;

    /* Prepare */
    num_channels = 0x1;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_RECEIVER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_RECEIVER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_INIT_RECEIVER_UNSUPPORTED, mhu_err);
}

void test_mhu_init_receiver_doorbell_mask_set_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_mask_set_ExpectAndReturn(
        &MHU_SENDER_DEV, channel, UINT32_MAX,
        MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM);

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM, mhu_err);
}

void test_mhu_init_receiver_doorbell_mask_clear_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    for (channel = 0; channel < (num_channels - 1); ++channel) {
        mhu_v3_x_doorbell_mask_set_ExpectAndReturn(
            &MHU_SENDER_DEV, channel, UINT32_MAX, MHU_V_3_X_ERR_NONE);
    }

    mhu_v3_x_doorbell_mask_clear_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, UINT32_MAX,
        MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM);

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_init_receiver_interrupt_enable_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    for (channel = 0; channel < (num_channels - 1); ++channel) {
        mhu_v3_x_doorbell_mask_set_ExpectAndReturn(
            &MHU_SENDER_DEV, channel, UINT32_MAX, MHU_V_3_X_ERR_NONE);
    }

    mhu_v3_x_doorbell_mask_clear_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, UINT32_MAX, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_channel_interrupt_enable_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, MHU_V3_X_CHANNEL_TYPE_DBCH,
        MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED);

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED, mhu_err);
}

void test_mhu_init_receiver_ok(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t channel;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    mhu_v3_x_driver_init_ExpectAndReturn(&MHU_SENDER_DEV, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    for (channel = 0; channel < (num_channels - 1); ++channel) {
        mhu_v3_x_doorbell_mask_set_ExpectAndReturn(
            &MHU_SENDER_DEV, channel, UINT32_MAX, MHU_V_3_X_ERR_NONE);
    }

    mhu_v3_x_doorbell_mask_clear_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, UINT32_MAX, MHU_V_3_X_ERR_NONE);

    mhu_v3_x_channel_interrupt_enable_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, MHU_V3_X_CHANNEL_TYPE_DBCH,
        MHU_V_3_X_ERR_NONE);

    /* Act */
    mhu_err = mhu_init_receiver(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_send_data_invalid_send_buffer_arg(void)
{
    enum mhu_error_t mhu_err;
    uint8_t send_buffer[0x20];
    size_t offset;
    size_t size;

    /* Prepare */
    offset = 0x1;
    size = 0x20;

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer + offset, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_VALIDATE_BUFFER_PARAMS_INVALID_ARG, mhu_err);
}

void test_mhu_send_data_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint8_t send_buffer[0x20];
    size_t size;

    /* Prepare */
    size = 0x20;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED, mhu_err);
}

void test_mhu_send_data_msg_size_write_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint8_t channel;
    uint8_t send_buffer[0x20];
    size_t size;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x20;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_write_ExpectAndReturn(
        &MHU_SENDER_DEV, channel, (uint32_t)size,
        MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM);

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_mhu_send_data_msg_write_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint8_t channel;
    uint8_t send_buffer[0x20];
    size_t size;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x20;
    memset((void *)send_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                            (uint32_t)size, MHU_V_3_X_ERR_NONE);

    channel++;
    mhu_v3_x_doorbell_write_ExpectAndReturn(
        &MHU_SENDER_DEV, channel, send_buffer[0],
        MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM);

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_mhu_send_data_signal_between_transfers_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint8_t channel;

    uint8_t send_buffer[0x80];
    uint32_t *buffer;
    size_t size;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    buffer = (uint32_t *)send_buffer;
    memset((void *)send_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                            (uint32_t)size, MHU_V_3_X_ERR_NONE);
    channel++;

    while (channel < (num_channels - 1)) {
        mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                                *buffer++, MHU_V_3_X_ERR_NONE);
        channel++;
    }

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_send_data_signal_last_transfer_fails(void)
{
    enum mhu_error_t mhu_err;
    uint32_t read_value;
    uint8_t num_channels;
    uint8_t channel;

    uint8_t send_buffer[0x80];
    uint32_t *buffer;
    size_t size;

    /* Prepare */
    read_value = 0;
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    buffer = (uint32_t *)send_buffer;
    memset((void *)send_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                            (uint32_t)size, MHU_V_3_X_ERR_NONE);
    channel++;

    for (size_t i = 0; i < size; i += 4) {
        mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                                *buffer++, MHU_V_3_X_ERR_NONE);

        if (++channel == (num_channels - 1)) {
            mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
                &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
                MHU_V_3_X_ERR_NONE);
            mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
            mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
                (uint8_t *)&num_channels, sizeof(num_channels));

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            mhu_v3_x_doorbell_write_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, MHU_NOTIFY_VALUE,
                MHU_V_3_X_ERR_NONE);

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            channel = 0;
        }
    }

    if (channel != 0) {
        mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
            &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
            MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG);
        mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
        mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
            (uint8_t *)&num_channels, sizeof(num_channels));
    }

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG, mhu_err);
}

void test_mhu_send_data_ok(void)
{
    enum mhu_error_t mhu_err;
    uint32_t read_value;
    uint8_t num_channels;
    uint8_t channel;

    uint8_t send_buffer[0x80];
    uint32_t *buffer;
    size_t size;

    /* Prepare */
    read_value = 0;
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    buffer = (uint32_t *)send_buffer;
    memset((void *)send_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                            (uint32_t)size, MHU_V_3_X_ERR_NONE);
    channel++;

    for (size_t i = 0; i < size; i += 4) {
        mhu_v3_x_doorbell_write_ExpectAndReturn(&MHU_SENDER_DEV, channel,
                                                *buffer++, MHU_V_3_X_ERR_NONE);

        if (++channel == (num_channels - 1)) {
            mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
                &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
                MHU_V_3_X_ERR_NONE);
            mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
            mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
                (uint8_t *)&num_channels, sizeof(num_channels));

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            mhu_v3_x_doorbell_write_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, MHU_NOTIFY_VALUE,
                MHU_V_3_X_ERR_NONE);

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            channel = 0;
        }
    }

    if (channel != 0) {
        mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
            &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
            MHU_V_3_X_ERR_NONE);
        mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
        mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
            (uint8_t *)&num_channels, sizeof(num_channels));

        mhu_v3_x_doorbell_read_ExpectAndReturn(
            &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
        mhu_v3_x_doorbell_read_IgnoreArg_value();
        mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                      sizeof(read_value));

        mhu_v3_x_doorbell_write_ExpectAndReturn(
            &MHU_SENDER_DEV, num_channels - 1, MHU_NOTIFY_VALUE,
            MHU_V_3_X_ERR_NONE);

        mhu_v3_x_doorbell_read_ExpectAndReturn(
            &MHU_SENDER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
        mhu_v3_x_doorbell_read_IgnoreArg_value();
        mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                      sizeof(read_value));
    }

    /* Act */
    mhu_err = mhu_send_data(&MHU_SENDER_DEV, send_buffer, size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_wait_data_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;

    /* Prepare */
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_wait_data(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_wait_data_read_doorbell_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t read_value;

    /* Prepare */
    num_channels = 0x10;
    read_value = MHU_NOTIFY_VALUE;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_SENDER_DEV, num_channels - 1, NULL,
        MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    /* Act */
    mhu_err = mhu_wait_data(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_mhu_wait_data_ok(void)
{
    enum mhu_error_t mhu_err;
    uint8_t num_channels;
    uint32_t read_value;

    /* Prepare */
    num_channels = 0x10;
    read_value = MHU_NOTIFY_VALUE;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_SENDER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_SENDER_DEV, num_channels - 1,
                                           NULL, MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&read_value,
                                                  sizeof(read_value));

    /* Act */
    mhu_err = mhu_wait_data(&MHU_SENDER_DEV);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_receive_data_invalid_receive_buffer_arg(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    size_t offset;
    size_t size;

    /* Prepare */
    size = 0x80;
    offset = 0x1;

    /* Act */
    mhu_err =
        mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer + offset, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_VALIDATE_BUFFER_PARAMS_INVALID_ARG, mhu_err);
}

void test_mhu_receive_data_get_num_channel_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint8_t num_channels;
    size_t size;

    /* Prepare */
    size = 0x80;
    num_channels = 0x10;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_receive_data_msg_size_read_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint8_t num_channels;
    uint8_t channel;
    uint32_t msg_len;
    size_t size;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    msg_len = 0x80;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_RECEIVER_DEV, channel, NULL,
        MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_mhu_receive_data_buffer_too_small(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint8_t num_channels;
    uint8_t channel;
    size_t size;
    uint32_t msg_len;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    msg_len = 0x100;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                           MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_ERR_RECEIVE_DATA_BUFFER_TOO_SMALL, mhu_err);
}

void test_mhu_receive_data_msg_read_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint8_t num_channels;
    uint8_t channel;
    size_t size;
    uint32_t msg_len;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;

    size = 0x80;
    msg_len = 0x80;

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                           MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));

    channel++;
    mhu_v3_x_doorbell_read_ExpectAndReturn(
        &MHU_RECEIVER_DEV, channel, NULL,
        MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
        (uint32_t *)&receive_buffer[0], sizeof(uint32_t));

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_mhu_receive_data_signal_between_transfers_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint32_t *buffer;
    uint8_t num_channels;
    uint8_t channel;
    size_t size;
    uint32_t msg_len;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;
    size = 0x80;
    msg_len = 0x80;

    buffer = (uint32_t *)receive_buffer;
    memset((void *)receive_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                           MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));
    channel++;

    while (channel < (num_channels - 1)) {
        mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                               MHU_V_3_X_ERR_NONE);
        mhu_v3_x_doorbell_read_IgnoreArg_value();
        mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&buffer,
                                                      sizeof(uint32_t));
        buffer++;
        channel++;
    }

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_receive_data_clear_channels_after_transfer_fails(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint32_t *buffer;
    uint8_t num_channels;
    uint8_t channel;
    size_t size;
    uint32_t msg_len;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;
    size = 0x80;
    msg_len = 0x80;

    buffer = (uint32_t *)receive_buffer;
    memset((void *)receive_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                           MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));
    channel++;

    for (size_t i = 0; i < msg_len; i += 4) {
        mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                               MHU_V_3_X_ERR_NONE);
        mhu_v3_x_doorbell_read_IgnoreArg_value();
        mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&buffer,
                                                      sizeof(uint32_t));
        buffer++;
        if (++channel == (num_channels - 1)) {
            uint32_t read_value = MHU_NOTIFY_VALUE;

            mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
                &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
                MHU_V_3_X_ERR_NONE);
            mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
            mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
                (uint8_t *)&num_channels, sizeof(num_channels));

            for (size_t j = 0; j < num_channels; ++j) {
                mhu_v3_x_doorbell_clear_ExpectAndReturn(
                    &MHU_RECEIVER_DEV, j, UINT32_MAX, MHU_V_3_X_ERR_NONE);
            }

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_RECEIVER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            channel = 0;
        }
    }

    mhu_v3_x_doorbell_clear_ExpectAndReturn(
        &MHU_RECEIVER_DEV, 0, UINT32_MAX,
        MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM);

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_receive_data_ok(void)
{
    enum mhu_error_t mhu_err;
    uint8_t receive_buffer[0x80];
    uint32_t *buffer;
    uint8_t num_channels;
    uint8_t channel;
    size_t size;
    uint32_t msg_len;

    /* Prepare */
    num_channels = 0x10;
    channel = 0;
    size = 0x80;
    msg_len = 0x80;

    buffer = (uint32_t *)receive_buffer;
    memset((void *)receive_buffer, 0x0u, size);

    mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
        &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
        MHU_V_3_X_ERR_NONE);
    mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
    mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
        (uint8_t *)&num_channels, sizeof(num_channels));

    mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                           MHU_V_3_X_ERR_NONE);
    mhu_v3_x_doorbell_read_IgnoreArg_value();
    mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&msg_len,
                                                  sizeof(msg_len));
    channel++;

    for (size_t i = 0; i < msg_len; i += 4) {
        mhu_v3_x_doorbell_read_ExpectAndReturn(&MHU_RECEIVER_DEV, channel, NULL,
                                               MHU_V_3_X_ERR_NONE);
        mhu_v3_x_doorbell_read_IgnoreArg_value();
        mhu_v3_x_doorbell_read_ReturnMemThruPtr_value((uint32_t *)&buffer,
                                                      sizeof(uint32_t));
        buffer++;
        if (++channel == (num_channels - 1)) {
            uint32_t read_value = MHU_NOTIFY_VALUE;

            mhu_v3_x_get_num_channel_implemented_ExpectAndReturn(
                &MHU_RECEIVER_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, NULL,
                MHU_V_3_X_ERR_NONE);
            mhu_v3_x_get_num_channel_implemented_IgnoreArg_num_ch();
            mhu_v3_x_get_num_channel_implemented_ReturnMemThruPtr_num_ch(
                (uint8_t *)&num_channels, sizeof(num_channels));

            for (size_t j = 0; j < num_channels; ++j) {
                mhu_v3_x_doorbell_clear_ExpectAndReturn(
                    &MHU_RECEIVER_DEV, j, UINT32_MAX, MHU_V_3_X_ERR_NONE);
            }

            mhu_v3_x_doorbell_read_ExpectAndReturn(
                &MHU_RECEIVER_DEV, num_channels - 1, NULL, MHU_V_3_X_ERR_NONE);
            mhu_v3_x_doorbell_read_IgnoreArg_value();
            mhu_v3_x_doorbell_read_ReturnMemThruPtr_value(
                (uint32_t *)&read_value, sizeof(read_value));

            channel = 0;
        }
    }

    for (size_t i = 0; i < num_channels; ++i) {
        mhu_v3_x_doorbell_clear_ExpectAndReturn(&MHU_RECEIVER_DEV, i,
                                                UINT32_MAX, MHU_V_3_X_ERR_NONE);
    }

    /* Act */
    mhu_err = mhu_receive_data(&MHU_RECEIVER_DEV, receive_buffer, &size);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

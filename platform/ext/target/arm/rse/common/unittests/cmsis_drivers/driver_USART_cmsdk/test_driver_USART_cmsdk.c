/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>

#include "Driver_USART.h"
#include "Driver_USART_Common.h"
#include "uart_cmsdk_drv.h"

#include "mock_uart_cmsdk_drv.h"

#include "unity.h"

#define DEFAULT_PERIPHERAL_CLOCK 75000000UL
#define DEFAULT_UART_BAUDRATE 115200UL

extern ARM_DRIVER_USART Driver_USART0;

static uint32_t UART0_CMSDK_DEV_NS_BASE;
static struct uart_cmsdk_dev_cfg_t UART0_CMSDK_DEV_CFG_NS = {
    .base = (uintptr_t)&UART0_CMSDK_DEV_NS_BASE,
    .default_baudrate = DEFAULT_UART_BAUDRATE};
static struct uart_cmsdk_dev_data_t UART0_CMSDK_DEV_DATA_NS = {
    .state = 0, .system_clk = 0, .baudrate = 0};
struct uart_cmsdk_dev_t UART0_CMSDK_DEV_NS = {&(UART0_CMSDK_DEV_CFG_NS),
                                              &(UART0_CMSDK_DEV_DATA_NS)};

uint32_t PeripheralClock = DEFAULT_PERIPHERAL_CLOCK;

void test_USART_GetVersion(void)
{
    ARM_DRIVER_VERSION driver_version;

    /* Act */
    driver_version = Driver_USART0.GetVersion();

    /* Assert */
    TEST_ASSERT_EQUAL_UINT16(driver_version.api, ARM_USART_API_VERSION);
    TEST_ASSERT_EQUAL_UINT16(driver_version.drv, ARM_USART_DRV_VERSION);
}

void test_USART_GetCapabilities(void)
{
    ARM_USART_CAPABILITIES driver_capabilities;

    /* Act */
    driver_capabilities = Driver_USART0.GetCapabilities();

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(0x1, driver_capabilities.asynchronous);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.synchronous_master);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.synchronous_slave);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.single_wire);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.irda);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.smart_card);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.smart_card_clock);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.flow_control_rts);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.flow_control_cts);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_tx_complete);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_rx_timeout);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.rts);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.cts);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.dtr);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.dsr);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.dcd);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.ri);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_cts);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_dsr);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_dcd);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.event_ri);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_capabilities.reserved);
}

void test_USART_Initialize(void)
{
    int32_t err;

    /* Prepare */
    uart_cmsdk_init_IgnoreAndReturn(UART_CMSDK_ERR_NONE);

    /* Act */
    err = Driver_USART0.Initialize(NULL);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_OK, err);
}

void test_USART_Uninitialize(void)
{
    int32_t err;

    /* Act */
    err = Driver_USART0.Uninitialize();

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_OK, err);
}

TEST_CASE(ARM_POWER_OFF, ARM_DRIVER_ERROR_UNSUPPORTED)
TEST_CASE(ARM_POWER_LOW, ARM_DRIVER_ERROR_UNSUPPORTED)
TEST_CASE(ARM_POWER_FULL, ARM_DRIVER_OK)
void test_USART_PowerControl(ARM_POWER_STATE state, int32_t expected_err)
{
    int32_t err;

    /* Act */
    err = Driver_USART0.PowerControl(state);

    /* Asset */
    TEST_ASSERT_EQUAL(expected_err, err);
}

void test_USART_Send_invalid_data_param(void)
{
    int32_t err;
    uint32_t tx_data_size;

    /* Prepare */
    tx_data_size = 32;

    /* Act */
    err = Driver_USART0.Send(NULL, tx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_PARAMETER, err);
}

void test_USART_Send_invalid_num_param(void)
{
    int32_t err;
    uint32_t tx_data;
    uint32_t tx_data_size;

    /* Prepare */
    tx_data = 0xdeadc0de;
    tx_data_size = 0;

    /* Act */
    err = Driver_USART0.Send((void *)&tx_data, tx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_PARAMETER, err);
}

void test_USART_Send_ok(void)
{
    int32_t err;
    uint32_t tx_data;
    uint32_t tx_data_size;

    /* Prepare */
    tx_data = 0xdeadc0de;
    tx_data_size = 4;
    uart_cmsdk_tx_ready_IgnoreAndReturn(0x1);
    uart_cmsdk_write_IgnoreAndReturn(UART_CMSDK_ERR_NONE);

    /* Act */
    err = Driver_USART0.Send((void *)&tx_data, tx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_OK, err);
}

void test_USART_Receive_invalid_data_param(void)
{
    int32_t err;
    uint32_t rx_data_size;

    /* Prepare */
    rx_data_size = 32;

    /* Act */
    err = Driver_USART0.Receive(NULL, rx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_PARAMETER, err);
}

void test_USART_Receive_invalid_num_param(void)
{
    int32_t err;
    uint32_t rx_data;
    uint32_t rx_data_size;

    /* Prepare */
    rx_data_size = 0;

    /* Act */
    err = Driver_USART0.Receive((void *)&rx_data, rx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_PARAMETER, err);
}

void test_USART_Receive_ok(void)
{
    int32_t err;
    uint32_t rx_data;
    uint32_t rx_data_size;

    /* Prepare */
    rx_data_size = 4;
    uart_cmsdk_rx_ready_IgnoreAndReturn(0x1);
    uart_cmsdk_read_IgnoreAndReturn(UART_CMSDK_ERR_NONE);

    /* Act */
    err = Driver_USART0.Receive((void *)&rx_data, rx_data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_OK, err);
}

void test_USART_Transfer(void)
{
    int32_t err;
    uint32_t tx_data;
    uint32_t rx_data;
    uint32_t data_size;

    /* Act */
    err = Driver_USART0.Transfer((void *)&tx_data, (void *)&rx_data, data_size);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_UNSUPPORTED, err);
}

void test_GetTxCount(void)
{
    int32_t err;
    uint32_t tx_count;
    uint32_t tx_data;
    uint32_t tx_data_size;

    /* Prepare */
    tx_data = 0xdeadc0de;
    tx_count = 0;
    tx_data_size = 4;

    uart_cmsdk_init_IgnoreAndReturn(UART_CMSDK_ERR_NONE);
    uart_cmsdk_tx_ready_IgnoreAndReturn(0x1);
    uart_cmsdk_write_IgnoreAndReturn(UART_CMSDK_ERR_NONE);

    /* Act */
    err = Driver_USART0.Initialize(NULL);
    TEST_ASSERT_EQUAL_MESSAGE(err, ARM_DRIVER_OK,
                              "Failed to initialize Driver_USART0");

    err = Driver_USART0.Send((void *)&tx_data, tx_data_size);
    TEST_ASSERT_EQUAL_MESSAGE(err, ARM_DRIVER_OK,
                              "Failed to send data using Driver_USART0");

    tx_count = Driver_USART0.GetTxCount();

    /* Asset */
    TEST_ASSERT_EQUAL(tx_data_size, tx_count);
}

void test_GetRxCount(void)
{
    int32_t err;
    uint32_t rx_count;
    uint32_t rx_data;
    uint32_t rx_data_size;

    /* Prepare */
    rx_count = 0;
    rx_data_size = 4;

    uart_cmsdk_init_IgnoreAndReturn(UART_CMSDK_ERR_NONE);
    uart_cmsdk_tx_ready_IgnoreAndReturn(0x1);
    uart_cmsdk_write_IgnoreAndReturn(UART_CMSDK_ERR_NONE);

    /* Act */
    err = Driver_USART0.Initialize(NULL);
    TEST_ASSERT_EQUAL_MESSAGE(err, ARM_DRIVER_OK,
                              "Failed to initialize Driver_USART0");

    err = Driver_USART0.Send((void *)&rx_data, rx_data_size);
    TEST_ASSERT_EQUAL_MESSAGE(err, ARM_DRIVER_OK,
                              "Failed to read data using Driver_USART0");

    rx_count = Driver_USART0.GetRxCount();

    /* Asset */
    TEST_ASSERT_EQUAL(rx_data_size, rx_count);
}

void test_USART_GetStatus(void)
{
    ARM_USART_STATUS driver_status;

    /* Act */
    driver_status = Driver_USART0.GetStatus();

    /* Asset */
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.tx_busy);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.rx_busy);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.tx_underflow);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.rx_overflow);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.rx_break);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.rx_framing_error);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.rx_parity_error);
    TEST_ASSERT_EQUAL_UINT32(0x0, driver_status.reserved);
}

void test_USART_SetModemControl(void)
{
    int32_t err;
    ARM_USART_MODEM_CONTROL modem_control = {0};

    /* Act */
    err = Driver_USART0.SetModemControl(modem_control);

    /* Asset */
    TEST_ASSERT_EQUAL(ARM_DRIVER_ERROR_UNSUPPORTED, err);
}

void test_USART_GetModemStatus(void)
{
    ARM_USART_MODEM_STATUS modem_status;

    /* Act */
    modem_status = Driver_USART0.GetModemStatus();

    /* Asset */
    TEST_ASSERT_EQUAL_UINT32(0x0, modem_status.cts);
    TEST_ASSERT_EQUAL_UINT32(0x0, modem_status.dsr);
    TEST_ASSERT_EQUAL_UINT32(0x0, modem_status.dcd);
    TEST_ASSERT_EQUAL_UINT32(0x0, modem_status.ri);
    TEST_ASSERT_EQUAL_UINT32(0x0, modem_status.reserved);
}

/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <assert.h>
#include <stdio.h>

#include <device.h>
#include <uart.h>
#include <uart_stdout.h>

static const struct device *dev_console = DEVICE_DT_GET(DT_CHOSEN(stdout_device));

int stdio_output_string(const char *str, uint32_t len)
{
	int32_t err;

	if (!device_is_ready(dev_console))
		return -ENODEV;

	err = uart_tx(dev_console, (const uint8_t *)str, len, 0);
	if (err)
		return err;

	return len;
}

#if defined(__GNUC__)
int _write(int fd, char *str, int len)
{
    (void)fd;

    /* Send string and return the number of characters written */
    return stdio_output_string((const char *)str, (uint32_t)len);
}
#else
#error "Toolchain not supported"
#endif

/* stdio_init is called by TFM core,
 * but this device depend on platform ressources and their init
 */
void stdio_init(void)
{
}

void stdio_uninit(void)
{
}

static int uart_console_init(void)
{
	if (!device_is_ready(dev_console))
		return -ENODEV;

	return 0;
}
SYS_INIT(uart_console_init, CORE, 1);

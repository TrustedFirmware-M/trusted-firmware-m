/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "uart_stdout.h"

static bool host_stdio_initialized = true;

void stdio_init(void)
{
    host_stdio_initialized = true;
}

void stdio_uninit(void)
{
    fflush(stdout);
    host_stdio_initialized = false;
}

int stdio_output_string(const char *str, uint32_t len)
{
    size_t written;

    if (!host_stdio_initialized || str == NULL || len == 0) {
        return 0;
    }

    written = fwrite(str, 1, len, stdout);
    fflush(stdout);

    return (int)written;
}

bool stdio_is_initialized(void)
{
    return host_stdio_initialized;
}

void stdio_is_initialized_reset(void)
{
    host_stdio_initialized = false;
}

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

#include "tfm_vprintf_priv.h"
#include "tfm_log.h"
#include "uart_stdout.h"

static void output_log(void *priv, const char *str, uint32_t len)
{
    stdio_output_string(str, len);
}

void tfm_log(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    tfm_vprintf(output_log, NULL, fmt, args, true);
    va_end(args);
}

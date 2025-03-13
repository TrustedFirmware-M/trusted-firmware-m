/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <inttypes.h>
#include "tfm_log.h"
#include "fatal_error.h"
#include "tfm_hal_device_header.h"
#include "uart_stdout.h"

__WEAK bool log_error_permissions_check(uint32_t err, bool is_fatal)
{
    return true;
}

#define LOG_FATAL_NON_FATAL_ERR(_is_fatal, ...) \
    do {                                        \
        if (_is_fatal) {                        \
            ERROR_RAW(__VA_ARGS__);             \
        } else {                                \
            WARN_RAW(__VA_ARGS__);              \
        }                                       \
    } while (0);

__WEAK void log_error(char *file, uint32_t line, uint32_t err, void *sp, bool is_fatal)
{
    if (stdio_is_initialized()) {
        if (is_fatal) {
            ERROR("Fatal error ");
        } else {
            WARN("Non-fatal error ");
        }

        if (err != 0) {
            LOG_FATAL_NON_FATAL_ERR(is_fatal, "%08"PRIx32" ", err);
        }

        if (file != NULL) {
            LOG_FATAL_NON_FATAL_ERR(is_fatal, "in file %s ", file);
        }

        if (line != 0) {
            LOG_FATAL_NON_FATAL_ERR(is_fatal, "at line %"PRIu32" ", line);
        }

        if (sp != NULL) {
            LOG_FATAL_NON_FATAL_ERR(is_fatal, "with SP=0x%"PRIx32" ", (uint32_t)sp);
        }

        LOG_FATAL_NON_FATAL_ERR(is_fatal, "\n");
    }
}

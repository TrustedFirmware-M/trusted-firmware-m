/*
 * Copyright (c) 2013-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*
 * Based on TF-A include/common/debug.h
 */

#ifndef __TF_M_VPRINTF_H__
#define __TF_M_VPRINTF_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

/*
 * The log output macros print output to the console. These macros produce
 * compiled log output only if the LOG_LEVEL defined in the CMake (or the
 * make command line) is greater or equal than the level required for that
 * type of log output.
 *
 * The format expected is the same as for printf(). For example:
 * INFO("Info %s.\n", "message")    -> '[INF]: Info message.'
 * WARN("Warning %s.\n", "message") ->'[WAR]: Warning message.'
 */
#define LOG_LEVEL_NONE      UINT8_C(0)
#define LOG_LEVEL_ERROR     UINT8_C(10)
#define LOG_LEVEL_NOTICE    UINT8_C(20)
#define LOG_LEVEL_WARNING   UINT8_C(30)
#define LOG_LEVEL_INFO      UINT8_C(40)
#define LOG_LEVEL_VERBOSE   UINT8_C(50)

/*
 * Define Log Markers corresponding to each log level which will
 * be embedded in the format string and is expected by tfm_vprintf() to determine
 * the log level.
 */
#define LOG_MARKER_ERROR    "\xa"   /* 10 */
#define LOG_MARKER_NOTICE   "\x14"  /* 20 */
#define LOG_MARKER_WARNING  "\x1e"  /* 30 */
#define LOG_MARKER_INFO     "\x28"  /* 40 */
#define LOG_MARKER_VERBOSE  "\x32"  /* 50 */

/* Function called to output a string to the terminal */
typedef void (*tfm_log_output_str)(void *priv, const unsigned char *str, uint32_t len);

/* Function to generate formatted string and pass to output_func */
void tfm_vprintf(tfm_log_output_str output_func, void *priv, const char *fmt, va_list args);

#endif /* __TF_M_VPRINTF_H__ */
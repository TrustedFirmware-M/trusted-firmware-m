/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TF_M_LOG_H__
#define __TF_M_LOG_H__

#include <stdbool.h>
#include <stdint.h>

#include "tfm_vprintf.h"

/*
 * If the log output is too low then this macro is used in place of tfm_log()
 * below. The intent is to get the compiler to evaluate the function call for
 * type checking and format specifier correctness but let it optimize it out.
 */
#define no_tfm_log(fmt, ...)                \
    do {                                         \
        if (false) {                             \
            tfm_log(fmt, ##__VA_ARGS__);    \
        }                                        \
    } while (false)

#ifndef LOG_LEVEL
#error "LOG_LEVEL not defined!"
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
# define ERROR(...)         tfm_log(LOG_MARKER_ERROR __VA_ARGS__)
# define ERROR_RAW(...)     tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#else
# define ERROR(...)         no_tfm_log(LOG_MARKER_ERROR __VA_ARGS__)
# define ERROR_RAW(...)     no_tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_NOTICE
# define NOTICE(...)        tfm_log(LOG_MARKER_NOTICE __VA_ARGS__)
# define NOTICE_RAW(...)    tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#else
# define NOTICE(...)        no_tfm_log(LOG_MARKER_NOTICE __VA_ARGS__)
# define NOTICE_RAW(...)    no_tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARNING
# define WARN(...)      tfm_log(LOG_MARKER_WARNING __VA_ARGS__)
# define WARN_RAW(...)  tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#else
# define WARN(...)      no_tfm_log(LOG_MARKER_WARNING __VA_ARGS__)
# define WARN_RAW(...)  no_tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
# define INFO(...)      tfm_log(LOG_MARKER_INFO __VA_ARGS__)
# define INFO_RAW(...)  tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#else
# define INFO(...)      no_tfm_log(LOG_MARKER_INFO __VA_ARGS__)
# define INFO_RAW(...)  no_tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_VERBOSE
# define VERBOSE(...)       tfm_log(LOG_MARKER_VERBOSE __VA_ARGS__)
# define VERBOSE_RAW(...)   tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#else
# define VERBOSE(...)       no_tfm_log(LOG_MARKER_VERBOSE __VA_ARGS__)
# define VERBOSE_RAW(...)   no_tfm_log(LOG_MARKER_RAW __VA_ARGS__)
#endif

#if defined(__ICCARM__)
#pragma __printf_args
void tfm_log(const char *fmt, ...);
#else
__attribute__((format(printf, 1, 2)))
void tfm_log(const char *fmt, ...);
#endif

#endif /* __TF_M_LOG_H__ */

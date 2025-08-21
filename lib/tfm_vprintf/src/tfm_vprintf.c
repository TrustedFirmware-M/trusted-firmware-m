/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*
 * Based on TF-A common/tf_log.c
 */

#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

#include "tfm_vprintf.h"
#include "tfm_vprintf_priv.h"

#define LOG_RAW_VALUE UINT8_C(60)

static inline const char *get_log_prefix(uint8_t log_level)
{
    switch(log_level) {
    case LOG_LEVEL_ERROR:
        return "[ERR]";
    case LOG_LEVEL_NOTICE:
        return "[NOT]";
    case LOG_LEVEL_WARNING:
        return "[WRN]";
    case LOG_LEVEL_INFO:
        return "[INF]";
    case LOG_LEVEL_VERBOSE:
        return "[VER]";
    default:
        /* String must start with LOG_MARKER_* */
        assert(0);
        return NULL;
    }
}

static void output_char(tfm_log_output_str output_func, void *priv, char c)
{
    output_func(priv, &c, 1);
}

static inline void output_padding_chars(tfm_log_output_str output_func, void *priv,
                                        uint16_t num_padding, char pad_char)
{
    uint16_t i;

    for (i = 0; i < num_padding; i++) {
        output_char(output_func, priv, pad_char);
    }
}

static void output_str(tfm_log_output_str output_func, void *priv, const char *str, uint32_t len,
                       uint16_t num_padding, bool left_aligned, char pad_char,
                       bool calculate_length)
{
    const char *str_ptr = str;

    if (str_ptr == NULL) {
        assert(false);
        return;
    }

    if (calculate_length) {
        len = 0;
        while (*str_ptr++ != '\0') {
            len++;
        }
    }

    if (num_padding > len) {
        num_padding -= len;
    } else {
        num_padding = 0;
    }

    if (!left_aligned) {
        output_padding_chars(output_func, priv, num_padding, pad_char);
    }

    output_func(priv, str, len);

    if (left_aligned) {
        output_padding_chars(output_func, priv, num_padding, pad_char);
    }
}

static void output_str_not_formatted(tfm_log_output_str output_func, void *priv, const char *str)
{
    output_str(output_func, priv, str, 0, 0, false, 0, true);
}

static void output_val(tfm_log_output_str output_func, void *priv, uint32_t val,
                       uint16_t num_padding, bool zero_padding, bool left_aligned, uint8_t base,
                       bool signed_specifier, bool hex_caps)
{
    uint8_t digit;
    /* uint32_t has maximum value of 4,294,967,295. Require enough space in buffer
     * for 10 digits + '-'. Note that the buffer does not need to be NULL terminated
     * as we pass the string length to output_str */
    char buf[11] = { 0 };
    char *const buf_end = &buf[sizeof(buf) - 1];
    char *buf_ptr = buf_end;
    const char pad_char = zero_padding ? '0' : ' ';
    const char negative_char = '-';
    const char start_hex_char = hex_caps ? 'A' : 'a';
    bool negative = false;

    if (signed_specifier && ((int32_t)val < 0)) {
        val = -val;
        negative = true;
    }

    do {
        digit = val % base;

        if (digit < 10) {
            *buf_ptr-- = '0' + digit;
        } else {
            *buf_ptr-- = start_hex_char + digit - 10;
        }

        val /= base;
    } while (val);

    if (negative) {
        if (!zero_padding) {
            *buf_ptr-- = negative_char;
        } else {
            output_char(output_func, priv, negative_char);
        }
    }

    output_str(output_func, priv, buf_ptr + 1, buf_end - buf_ptr, num_padding, left_aligned,
               pad_char, false);
}

/* Basic vprintf, understands:
 * %s: output string
 * %u: output uint32_t in decimal
 * %d: output int32_t in decimal
 * %x: output uint32_t in hex
 */
static void tfm_vprintf_internal(tfm_log_output_str output_func,
                                void *priv, const char *fmt, va_list args)
{
    char c;
    bool formatting = false;
    uint16_t num_padding = 0;
    bool zero_padding = false;
    bool left_aligned = false;

    while ((c = *fmt++) != '\0') {
        if (!formatting) {
            if (c == '%') {
                zero_padding = false;
                num_padding = 0;
                left_aligned = false;
                formatting = true;
            } else {
                if (c == '\n') {
                    output_char(output_func, priv, '\r');
                }
                output_char(output_func, priv, c);
            }
            continue;
        }

        switch (c) {
        case 'l':
            continue;
        case 'u':
            output_val(output_func, priv, va_arg(args, uint32_t), num_padding, zero_padding,
                       left_aligned, 10, false, false);
            break;
        case 'd':
        case 'i':
            output_val(output_func, priv, va_arg(args, uint32_t), num_padding, zero_padding,
                       left_aligned, 10, true, false);
            break;
        case 'x':
            output_val(output_func, priv, va_arg(args, uint32_t), num_padding, zero_padding,
                       left_aligned, 16, false, false);
            break;
        case 'X':
            output_val(output_func, priv, va_arg(args, uint32_t), num_padding, zero_padding,
                       left_aligned, 16, false, true);
            break;
        case 's':
            output_str(output_func, priv, va_arg(args, char *), 0, num_padding, left_aligned, ' ',
                       true);
            break;
        case '-':
            left_aligned = true;
            continue;
        case '0':
            if (num_padding == 0) {
                zero_padding = true;
                continue;
            }
            /* fallthrough */
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            num_padding *= 10;
            num_padding += c - '0';
            continue;
        case '%':
            output_char(output_func, priv, '%');
            break;
        default:
            output_str_not_formatted(output_func, priv, "[Unsupported]");
        }

        formatting = false;
    }
}

void tfm_vprintf(tfm_log_output_str output_func, void *priv, const char *fmt, va_list args,
                 bool with_marker)
{
    uint8_t log_marker;
    const char spacer = ' ';

    if (with_marker) {
        log_marker = fmt[0];
        fmt++;
        if (log_marker != LOG_RAW_VALUE) {
            output_str_not_formatted(output_func, priv, get_log_prefix(log_marker));
            output_char(output_func, priv, spacer);
        }
    }

    tfm_vprintf_internal(output_func, priv, fmt, args);
}

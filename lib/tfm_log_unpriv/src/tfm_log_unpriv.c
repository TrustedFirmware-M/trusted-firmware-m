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
#include <string.h>

#include "tfm_vprintf_priv.h"
#include "tfm_log_unpriv.h"
#include "tfm_hal_sp_logdev.h"

#define LOG_UNPRIV_BUFFER_SIZE (32)

struct tfm_log_unpriv_data {
    uint8_t buf_pos;
    size_t total_output_chars;
    char buf[LOG_UNPRIV_BUFFER_SIZE];
};

static void output_buf(struct tfm_log_unpriv_data *data, uint32_t buf_len)
{
    int32_t ret;

    ret = tfm_hal_output_sp_log(data->buf, buf_len);
    if (ret > 0) {
        data->total_output_chars += ret;
    }
}

static void output_string_to_buf(void *priv, const char *str, uint32_t len)
{
    struct tfm_log_unpriv_data *data = priv;

    if ((data->buf_pos + len) > LOG_UNPRIV_BUFFER_SIZE) {
        /* Flush current buffer and re-use */
        output_buf(data, data->buf_pos);
        data->buf_pos = 0;

        /* Handle strings larger than buffer with multiple flushes */
        for (; len > LOG_UNPRIV_BUFFER_SIZE;
             len -= LOG_UNPRIV_BUFFER_SIZE, str += LOG_UNPRIV_BUFFER_SIZE) {
            memcpy(data->buf, str, LOG_UNPRIV_BUFFER_SIZE);
            output_buf(data, LOG_UNPRIV_BUFFER_SIZE);
        }
    }

    memcpy(data->buf + data->buf_pos, str, len);
    data->buf_pos += len;
}

static int vprintf_output_buffer(const char *fmt, va_list args, bool with_marker)
{
    struct tfm_log_unpriv_data data;

    data.buf_pos = 0;
    data.total_output_chars = 0;

    tfm_vprintf(output_string_to_buf, &data, fmt, args, with_marker);

    output_buf(&data, data.buf_pos);

    return data.total_output_chars;
}

int tfm_vprintf_unpriv(const char *fmt, va_list args)
{
    return vprintf_output_buffer(fmt, args, false);
}

void tfm_log_unpriv(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vprintf_output_buffer(fmt, args, true);
    va_end(args);
}

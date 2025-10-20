/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __BACKTRACE_H__
#define __BACKTRACE_H__

#include <stdint.h>

/**
 * Function type to pass into tfm_dump_backtrace to
 * log the backtrace output
 */
typedef void (*tfm_log_func)(const char *fmt, ...);

/**
 * Dump a backtrace of current location to the
 * terminal
 * - info: Information string to be printed with
 *  the backtrace
 * - log_func: Function which will be called to log output
 */
void tfm_dump_backtrace(const char *info, tfm_log_func log_func);

/**
 * Collect a backtrace and store it in the buffer
 * - buf: Buffer to store the backtrace data
 * - buf_size: Size of the buffer in uint32_t dwords
 * - num_frames: Receieves the numer of stack frames read into
 *  the buffer
 */
void tfm_get_backtrace(uint32_t *buf, uint8_t buf_size, uint8_t *num_frames);


#endif /* __BACKTRACE_H__ */

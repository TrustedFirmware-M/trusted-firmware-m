/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * @file  prix64.h
 *
 * @brief  This file declares utility functions, and defines an associated
 *         convenience type, for formatting uint64_t values according to the
 *         pattern 0x0123_4567_89AB_CDEF. The name "prix64" is inspired by the
 *         ISO C <inttypes.h> PRIx64 format specifier macro.
 */

#ifndef __PRIX64_H__
#define __PRIX64_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief  The number of characters in a string like "0x0123_4567_89AB_CDEF",
 *         including the terminating NUL.
 */
#define PRIX64_SIZE (sizeof("0x0123_4567_89AB_CDEF"))

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Format a uint64_t value to a NUL-terminated character string
 *         according to the pattern 0x0123_4567_89AB_CDEF. Place the string in
 *         a general, caller-provided array of characters.
 *
 * param[out] str    Pointer to the character in the array where formatting is
 *                   supposed to start. NULL may be passed only if "size" is
 *                   zero.
 * param[in]  size   The number of characters available starting at "str",
 *                   including the terminating NUL. If "size" is zero, no
 *                   characters are written; otherwise, the output is always
 *                   NUL-terminated, even if truncation occurs. The output is
 *                   truncated iff "size" is less than PRIX64_SIZE.
 * param[in]  value  The uint64_t value to format.
 *
 * @retval  str
 */
char *prix64a(char *str, size_t size, uint64_t value);

/**
 * @brief  Convenience typedef of a fixed, minimum size array into which a
 *         uint64_t value may be formatted without truncation.
 */
typedef char prix64_t[PRIX64_SIZE];

/**
 * @brief  Format a uint64_t value to a NUL-terminated character string
 *         according to the pattern 0x0123_4567_89AB_CDEF. Place the string in
 *         a caller-provided prix64_t object.
 *
 * This function expressly doesn't support formatting a uint64_t value into a
 * generic character array. The prototype prevents the prix64_t (i.e., fixed
 * size array) object from decaying to a pointer to its first element.
 *
 * @param[out] fmt    Pointer to the prix64_t object (fixed size array)
 *                    accepting the formatted string.
 * @param[in]  value  The uint64_t value to format.
 *
 * @return  Pointer to the first character of the formatted string.
 */
char *prix64(prix64_t *fmt, uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /*  __PRIX64_H__ */

/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FATAL_ERROR_H__
#define __FATAL_ERROR_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef PLATFORM_CUSTOM_ERROR_HANDLER
#include "platform_error_handler.h"
#else /* PLATFORM_CUSTOM_ERROR_HANDLER */

#ifdef HALT_ON_FATAL_ERROR
#define ERROR_HALT() do { __asm volatile ("wfi"); } while (1)
#else
#define ERROR_HALT()
#endif /* HALT_ON_FATAL_ERROR */

#ifdef FATAL_ERR_LOG_FILE_AND_LINE
#define ERR_FILE __FILE__
#define ERR_LINE __LINE__
#else
#define ERR_FILE NULL
#define ERR_LINE 0
#endif /* FATAL_ERR_LOG_FILE_AND_LINE */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Checks whether the error code \p err is enabled or not
 *
 * @param[in] err      Error to log
 * @param[in] is_fatal Whether the error causes a halt or not
 *
 * @return true        The error can be logged
 * @return false       The error can't be logged
 */
bool log_error_permissions_check(uint32_t err, bool is_fatal);

/**
 * @brief Performs the error logging operation
 *
 * @param[in] file      String pointing to the file that caused the error
 * @param[in] line      Lone in the file that caused the error
 * @param[in] err       Error to log
 * @param[in] sp        Stack pointer when the error occurred
 * @param[in] is_fatal  Whether the error is fatal or not
 */
void log_error(const char *file, uint32_t line, uint32_t err, void *sp, bool is_fatal);

#ifdef LOG_FATAL_ERRORS
#define FATAL_ERR(err)                                      \
    do {                                                    \
        uint32_t foo;                                       \
        if (log_error_permissions_check(err, true)) {       \
            log_error(ERR_FILE, ERR_LINE, err, &foo, true); \
            ERROR_HALT();                                   \
        }                                                   \
    } while(0)
#else
#define FATAL_ERR(err) ERROR_HALT()
#endif /* LOG_FATAL_ERRORS */

#ifdef LOG_NONFATAL_ERRORS
#define NONFATAL_ERR(err)                                    \
    do {                                                     \
        uint32_t foo;                                        \
        if (log_error_permissions_check(err, false)) {       \
            log_error(ERR_FILE, ERR_LINE, err, &foo, false); \
        }                                                    \
    } while(0)
#else
#define NONFATAL_ERR(err)
#endif /* LOG_NONFATAL_ERRORS */

#endif /* PLATFORM_CUSTOM_ERROR_HANDLER */

#ifdef __cplusplus
}
#endif

#endif /* __FATAL_ERROR_H__ */

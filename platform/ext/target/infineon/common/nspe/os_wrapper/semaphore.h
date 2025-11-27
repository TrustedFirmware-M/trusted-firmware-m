/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef OS_WRAPPER_SEMAPHORE_H
#define OS_WRAPPER_SEMAPHORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "os_wrapper/common.h"

/**
 * \brief Creates a new semaphore
 *
 * \param[in] max_count       Highest count of the semaphore
 * \param[in] initial_count   Starting count of the available semaphore
 * \param[in] name            Name of the semaphore
 *
 * \return Returns handle of the semaphore created, or NULL in case of error
 */
void *os_wrapper_semaphore_create(uint32_t max_count, uint32_t initial_count,
                                  const char *name);

/**
 * \brief Acquires the semaphore
 *
 * \param[in] hanlde  Semaphore handle
 * \param[in] timeout Timeout value
 *
 * \return \ref OS_WRAPPER_SUCCESS in case of successful acquision, or
 *         \ref OS_WRAPPER_ERROR in case of error
 */
uint32_t os_wrapper_semaphore_acquire(void *handle, uint32_t timeout);

/**
 * \brief Releases the semaphore
 *
 * \param[in] hanlde Semaphore handle
 *
 * \return \ref OS_WRAPPER_SUCCESS in case of successful release, or
 *         \ref OS_WRAPPER_ERROR in case of error
 */
uint32_t os_wrapper_semaphore_release(void *handle);

/**
 * \brief Deletes the semaphore
 *
 * \param[in] handle Semaphore handle
 *
 * \return \ref OS_WRAPPER_SUCCESS in case of successful release, or
 *         \ref OS_WRAPPER_ERROR in case of error
 */
uint32_t os_wrapper_semaphore_delete(void *handle);

#ifdef __cplusplus
}
#endif

#endif /* OS_WRAPPER_SEMAPHORE_H */

/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2017-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
#include <string.h>
#include <stdlib.h>
#include "cyabs_rtos.h"

#include "os_wrapper/common.h"
#include "os_wrapper/mutex.h"
#include "os_wrapper/semaphore.h"
#include "os_wrapper/thread.h"

void *os_wrapper_thread_new(const char* name, int32_t stack_size,
                            os_wrapper_thread_func func, void *arg,
                            uint32_t priority)
{
    uint32_t ssize = stack_size > 0U ? stack_size : CY_RTOS_MIN_STACK_SIZE;
    cy_thread_t handle;

    if (CY_RSLT_SUCCESS != cy_rtos_create_thread(&handle,
                                                 (cy_thread_entry_fn_t)func,
                                                 name,
                                                 NULL,
                                                 ssize,
                                                 (cy_thread_priority_t)priority,
                                                 (cy_thread_arg_t)arg))
    {
        return NULL;
    }
    return (void *)handle;
}


void *os_wrapper_semaphore_create(uint32_t max_count, uint32_t initial_count,
                                     const char* name)
{
    (void)name;
    cy_semaphore_t * handle = (cy_semaphore_t *)malloc(sizeof(cy_semaphore_t));
    if (NULL == handle)
    {
        return NULL;
    }
    if (CY_RSLT_SUCCESS != cy_rtos_init_semaphore(handle, max_count, initial_count))
    {
        free(handle);
        return NULL;
    }
    return (void *)handle;
}

uint32_t os_wrapper_semaphore_acquire(void *handle, uint32_t timeout)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if (CY_RSLT_SUCCESS != cy_rtos_get_semaphore((cy_semaphore_t *)handle,
                                                 (cy_time_t)timeout,
                                                 false))
    {
        return OS_WRAPPER_ERROR;
    }

    return OS_WRAPPER_SUCCESS;
}

uint32_t os_wrapper_semaphore_release(void *handle)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if (CY_RSLT_SUCCESS != cy_rtos_set_semaphore((cy_semaphore_t *)handle, false))
    {
        return OS_WRAPPER_ERROR;
    }
    return OS_WRAPPER_SUCCESS;
}

uint32_t os_wrapper_semaphore_release_isr(void *handle)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if (CY_RSLT_SUCCESS != cy_rtos_set_semaphore((cy_semaphore_t *)handle, true))
    {
        return OS_WRAPPER_ERROR;
    }
    return OS_WRAPPER_SUCCESS;
}

void os_wrapper_isr_yield(uint32_t yield)
{
    (void)yield;
}

uint32_t os_wrapper_semaphore_delete(void *handle)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if (CY_RSLT_SUCCESS != cy_rtos_deinit_semaphore((cy_semaphore_t *)handle))
    {
        return OS_WRAPPER_ERROR;
    }
    free(handle);
    return OS_WRAPPER_SUCCESS;
}

void *os_wrapper_mutex_create(void)
{
    cy_mutex_t *handle = (cy_mutex_t *) malloc(sizeof(cy_mutex_t));
    if (NULL == handle)
    {
        return NULL;
    }

    if (CY_RSLT_SUCCESS != cy_rtos_init_mutex(handle))
    {
        free(handle);
        return NULL;
    }
    return (void *)handle;
}

uint32_t os_wrapper_mutex_acquire(void *handle, uint32_t timeout)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if(CY_RSLT_SUCCESS != cy_rtos_get_mutex((cy_mutex_t *)handle, (cy_time_t)timeout))
    {
        return OS_WRAPPER_ERROR;
    }
    return OS_WRAPPER_SUCCESS;
}

uint32_t os_wrapper_mutex_release(void *handle)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if(CY_RSLT_SUCCESS != cy_rtos_set_mutex((cy_mutex_t *)handle))
    {
        return OS_WRAPPER_ERROR;
    }
    return OS_WRAPPER_SUCCESS;
}

uint32_t os_wrapper_mutex_delete(void *handle)
{
    if (NULL == handle)
    {
        return OS_WRAPPER_ERROR;
    }

    if(CY_RSLT_SUCCESS != cy_rtos_deinit_mutex((cy_mutex_t *)handle))
    {
        return OS_WRAPPER_ERROR;
    }
    free(handle);
    return OS_WRAPPER_SUCCESS;
}

void *os_wrapper_thread_get_handle(void)
{
    cy_thread_t handle;
    if (CY_RSLT_SUCCESS == cy_rtos_get_thread_handle(&handle))
    {
        return (void *)handle;
    }
    else
    {
        return NULL;
    }
}

uint32_t os_wrapper_thread_get_priority(void *handle, uint32_t *priority)
{
     (void)handle;
     (void)priority;
     /* not supported by CY_RTOS abstraction layer */
     return OS_WRAPPER_ERROR;
}

void os_wrapper_thread_exit(void)
{
    cy_rtos_exit_thread();
}

uint32_t os_wrapper_join_thread(void* handle)
{
    if (CY_RSLT_SUCCESS == cy_rtos_join_thread((cy_thread_t *)handle))
    {
        return OS_WRAPPER_SUCCESS;
    }
    else
    {
        return OS_WRAPPER_ERROR;
    }
}

uint32_t os_wrapper_thread_set_flag(void *handle, uint32_t flags)
{
    (void)flags;
    cy_thread_t cy_handle = (cy_thread_t) handle;
    if (CY_RSLT_SUCCESS == cy_rtos_set_thread_notification(&cy_handle, false))
    {
        return OS_WRAPPER_SUCCESS;
    }
    else
    {
        return OS_WRAPPER_ERROR;
    }
}

uint32_t os_wrapper_thread_set_flag_isr(void *handle, uint32_t flags)
{
    (void)flags;
    cy_thread_t cy_handle = (cy_thread_t) handle;
    if (CY_RSLT_SUCCESS == cy_rtos_set_thread_notification(&cy_handle, true))
    {
        return OS_WRAPPER_SUCCESS;
    }
    else
    {
        return OS_WRAPPER_ERROR;
    }
}

uint32_t os_wrapper_thread_wait_flag(uint32_t flags, uint32_t timeout)
{
    (void)flags;
    if (CY_RSLT_SUCCESS == cy_rtos_wait_thread_notification(timeout))
    {
        return OS_WRAPPER_SUCCESS;
    }
    else
    {
        return OS_WRAPPER_ERROR;
    }
}

uint32_t os_wrapper_get_tick(void)
{
    cy_time_t ticks;
    cy_rtos_time_get(&ticks);
    return ticks;
}

bool os_wrapper_is_kernel_running(void)
{
    cy_scheduler_state_t state = CY_SCHEDULER_STATE_UNKNOWN;
    cy_rslt_t ret = cy_rtos_scheduler_get_state(&state);
    if (ret != CY_RSLT_SUCCESS) {
        return false;
    }
    return state == CY_SCHEDULER_STATE_RUNNING;
}

#endif /* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) */

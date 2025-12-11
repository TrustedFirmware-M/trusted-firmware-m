/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cybsp.h"
#include "ifx_mtb_mailbox.h"
#include "mtb_srf_ipc_init.h"

#if !defined(__DCACHE_PRESENT) || (__DCACHE_PRESENT == 0U)
#define IFX_MTB_MAILBOX_CACHE_PRESENT   (0)
#else /* !defined(__DCACHE_PRESENT) || (__DCACHE_PRESENT == 0U) */
#define IFX_MTB_MAILBOX_CACHE_PRESENT   (1)
#endif /* !defined(__DCACHE_PRESENT) || (__DCACHE_PRESENT == 0U) */

#if IFX_MTB_MAILBOX_CACHE_PRESENT
#include "mtb_hal_system.h"
#endif /* IFX_MTB_MAILBOX_CACHE_PRESENT */

int32_t ifx_mtb_mailbox_client_call(uint32_t call_type,
                                    const ifx_psa_client_params_t *params,
                                    ifx_mtb_mailbox_reply_t *reply)
{
    mtb_srf_ipc_packet_t* request = NULL;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_rslt_t sema_dealloc_rslt = CY_RSLT_SUCCESS;
    cy_rslt_t req_dealloc_rslt = CY_RSLT_SUCCESS;
    uint16_t sema_idx = 0;

    if ((params == NULL) || (reply == NULL)) {
        return IFX_MTB_MAILBOX_INVAL_PARAMS;
    }

    /* Allocate request from shared memory. */
    result = mtb_srf_ipc_pool_req_alloc(cybsp_mtb_srf_client_context.pool,
                                        &request,
                                        MTB_SRF_IPC_SERVICE_TIMEOUT_US);
    if (result != CY_RSLT_SUCCESS) {
        return IFX_MTB_MAILBOX_GENERIC_ERROR;
    }

    /* Allocate semaphore */
    result = mtb_srf_ipc_pool_semaphore_alloc(cybsp_mtb_srf_client_context.pool,
                                              &sema_idx,
                                              MTB_SRF_IPC_SERVICE_TIMEOUT_US);
    if (result != CY_RSLT_SUCCESS) {
        /* Deallocate request. Void deallocation result as this is already an error path */
        (void)mtb_srf_ipc_pool_req_free(cybsp_mtb_srf_client_context.pool, request);

        return IFX_MTB_MAILBOX_GENERIC_ERROR;
    }

    /*
     * Copy data into the request structure (allocated in shared memory).
     * Pointers cannot be used because the request must be self-contained and
     * accessible by both sides of the IPC (all data must reside in shared memory).
     */
    request->call_type = call_type;
    request->params = *params;
    request->reply = *reply;
    request->semaphore_idx = sema_idx;

    /*
     * Data cache handling:
     *
     * The data cache must be disabled before sending an IPC request to ensure
     * data coherency between cores. However, if multiple threads or nested
     * calls attempt to disable/enable the cache, simply toggling the cache can
     * lead to race conditions or leave the cache in the wrong state. To avoid
     * this, a counter is used to track the number of active requests that
     * require the cache to be disabled. Only when the counter transitions from
     * 0 to 1 (first request is initiated) is the cache actually disabled, and
     * only when it returns to 0 (all requests are completed) cache is
     * re-enabled (if it was enabled).
     *
     * This ensures that nested or concurrent calls do not accidentally
     * re-enable the cache while another operation still requires it to be off.
     */
#if IFX_MTB_MAILBOX_CACHE_PRESENT
    static uint32_t active_requests_counter = 0;
    static bool dcache_was_enabled = false;
    uint32_t primask;

    /* Enter critical section to protect counter and cache state */
    primask = mtb_hal_system_critical_section_enter();
    if (active_requests_counter == 0u) {
        /* Record if D-Cache is currently enabled */
        dcache_was_enabled = ((SCB->CCR & SCB_CCR_DC_Msk) != 0u);
        if (dcache_was_enabled) {
            /* Disable D-Cache */
            SCB_DisableDCache();
        }
    }
    active_requests_counter++;
    mtb_hal_system_critical_section_exit(primask);
#endif /* IFX_MTB_MAILBOX_CACHE_PRESENT */

    /* Send request over IPC and wait for return. mtb_srf_ipc_request_send takes
     * care of cache clean/invalidate for the request structure */
    result = mtb_srf_ipc_request_send(&cybsp_mtb_srf_client_context,
                                      request,
                                      MTB_IPC_NEVER_TIMEOUT);

#if IFX_MTB_MAILBOX_CACHE_PRESENT
    /*
     * After the IPC request is complete, restore the D-Cache state if this is
     * the last request. Again, use a critical section to protect the counter
     * and state.
     */
    primask = mtb_hal_system_critical_section_enter();
    CY_ASSERT(active_requests_counter > 0u);
    active_requests_counter--;
    if ((active_requests_counter == 0u) && dcache_was_enabled) {
        /* After all requests are done - Re-enable D-Cache only if it was
         * previously enabled */
        SCB_EnableDCache();
    }
    mtb_hal_system_critical_section_exit(primask);
#endif /* IFX_MTB_MAILBOX_CACHE_PRESENT */

    /* Deallocate semaphore */
    sema_dealloc_rslt = mtb_srf_ipc_pool_semaphore_free(cybsp_mtb_srf_client_context.pool,
                                                        sema_idx);

    /* Deallocate request */
    req_dealloc_rslt = mtb_srf_ipc_pool_req_free(cybsp_mtb_srf_client_context.pool, request);

    if ((result != CY_RSLT_SUCCESS) || (sema_dealloc_rslt != CY_RSLT_SUCCESS)
        || (req_dealloc_rslt != CY_RSLT_SUCCESS)) {
        return IFX_MTB_MAILBOX_GENERIC_ERROR;
    }

    /* Copy the entire reply structure back so the caller receives all output values. */
    *reply = request->reply;

    return IFX_MTB_MAILBOX_SUCCESS;
}

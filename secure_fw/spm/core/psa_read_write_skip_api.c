/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2022-2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "ffm/psa_api.h"
#include "spm.h"
#include "utilities.h"
#include "tfm_hal_isolation.h"

size_t tfm_spm_partition_psa_read(psa_handle_t msg_handle, uint32_t invec_idx,
                                  void *buffer, size_t num_bytes)
{
    size_t bytes, remaining;
    struct connection_t *handle = NULL;
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    /* It is a fatal error if message handle is invalid */
    handle = spm_msg_handle_to_connection(msg_handle);
    if (!handle) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if message handle does not refer to a request
     * message
     */
    if (handle->msg.type < PSA_IPC_CALL) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if invec_idx is equal to or greater than
     * PSA_MAX_IOVEC
     */
    if (invec_idx >= PSA_MAX_IOVEC) {
        tfm_core_panic();
    }

#if PSA_FRAMEWORK_HAS_MM_IOVEC
    /*
     * It is a fatal error if the input vector has already been mapped using
     * psa_map_invec().
     */
    if (IOVEC_IS_MAPPED(handle, (invec_idx + INVEC_IDX_BASE)) ||
        IOVEC_IS_UNMAPPED(handle, (invec_idx + INVEC_IDX_BASE))) {
        tfm_core_panic();
    }

    SET_IOVEC_ACCESSED(handle, (invec_idx + INVEC_IDX_BASE));
#endif

    remaining = handle->msg.in_size[invec_idx] - handle->invec_accessed[invec_idx];
    /* There was no remaining data in this input vector */
    if (remaining == 0) {
        return 0;
    }

    /*
     * Copy the client data to the service buffer. It is a fatal error
     * if the memory reference for buffer is invalid or not read-write.
     */
    FIH_CALL(tfm_hal_memory_check, fih_rc,
             curr_partition->boundary, (uintptr_t)buffer,
             num_bytes, TFM_HAL_ACCESS_READWRITE);
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        tfm_core_panic();
    }

    bytes = (num_bytes < remaining) ? num_bytes : remaining;

    spm_memcpy(buffer, (char *)handle->invec_base[invec_idx] +
                               handle->invec_accessed[invec_idx], bytes);

    /* Update the data size read */
    handle->invec_accessed[invec_idx] += bytes;

    return bytes;
}

size_t tfm_spm_partition_psa_skip(psa_handle_t msg_handle, uint32_t invec_idx,
                                  size_t num_bytes)
{
    struct connection_t *handle = NULL;
    size_t remaining;

    /* It is a fatal error if message handle is invalid */
    handle = spm_msg_handle_to_connection(msg_handle);
    if (!handle) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if message handle does not refer to a request
     * message
     */
    if (handle->msg.type < PSA_IPC_CALL) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if invec_idx is equal to or greater than
     * PSA_MAX_IOVEC
     */
    if (invec_idx >= PSA_MAX_IOVEC) {
        tfm_core_panic();
    }

#if PSA_FRAMEWORK_HAS_MM_IOVEC
    /*
     * It is a fatal error if the input vector has already been mapped using
     * psa_map_invec().
     */
    if (IOVEC_IS_MAPPED(handle, (invec_idx + INVEC_IDX_BASE)) ||
        IOVEC_IS_UNMAPPED(handle, (invec_idx + INVEC_IDX_BASE))) {
        tfm_core_panic();
    }

    SET_IOVEC_ACCESSED(handle, (invec_idx + INVEC_IDX_BASE));
#endif

    remaining = handle->msg.in_size[invec_idx] - handle->invec_accessed[invec_idx];
    /* There was no remaining data in this input vector */
    if (remaining == 0) {
        return 0;
    }

    /*
     * If num_bytes is greater than the remaining size of the input vector then
     * the remaining size of the input vector is used.
     */
    if (num_bytes > remaining) {
        num_bytes = remaining;
    }

    /* Update the data size accessed */
    handle->invec_accessed[invec_idx] += num_bytes;

    return num_bytes;
}

psa_status_t tfm_spm_partition_psa_write(psa_handle_t msg_handle, uint32_t outvec_idx,
                                         const void *buffer, size_t num_bytes)
{
    struct connection_t *handle = NULL;
    const struct partition_t *curr_partition = GET_CURRENT_COMPONENT();
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    /* It is a fatal error if message handle is invalid */
    handle = spm_msg_handle_to_connection(msg_handle);
    if (!handle) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if message handle does not refer to a request
     * message
     */
    if (handle->msg.type < PSA_IPC_CALL) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if outvec_idx is equal to or greater than
     * PSA_MAX_IOVEC
     */
    if (outvec_idx >= PSA_MAX_IOVEC) {
        tfm_core_panic();
    }

    /*
     * It is a fatal error if the call attempts to write data past the end of
     * the client output vector
     */
    if (num_bytes > (handle->msg.out_size[outvec_idx] - handle->outvec_written[outvec_idx])) {
        tfm_core_panic();
    }

#if PSA_FRAMEWORK_HAS_MM_IOVEC
    /*
     * It is a fatal error if the output vector has already been mapped using
     * psa_map_outvec().
     */
    if (IOVEC_IS_MAPPED(handle, (outvec_idx + OUTVEC_IDX_BASE)) ||
        IOVEC_IS_UNMAPPED(handle, (outvec_idx + OUTVEC_IDX_BASE))) {
        tfm_core_panic();
    }

    SET_IOVEC_ACCESSED(handle, (outvec_idx + OUTVEC_IDX_BASE));
#endif

    /*
     * Copy the service buffer to client outvecs. It is a fatal error
     * if the memory reference for buffer is invalid or not readable.
     */
    FIH_CALL(tfm_hal_memory_check, fih_rc,
             curr_partition->boundary, (uintptr_t)buffer,
             num_bytes, TFM_HAL_ACCESS_READABLE);
    if (FIH_NOT_EQ(fih_rc, PSA_SUCCESS)) {
        tfm_core_panic();
    }

    spm_memcpy((char *)handle->outvec_base[outvec_idx] +
               handle->outvec_written[outvec_idx], buffer, num_bytes);

    /* Update the data size written */
    handle->outvec_written[outvec_idx] += num_bytes;

    return PSA_SUCCESS;
}

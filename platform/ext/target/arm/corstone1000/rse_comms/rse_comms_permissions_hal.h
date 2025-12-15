/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_PERMISSIONS_HAL_H__
#define __RSE_COMMS_PERMISSIONS_HAL_H__

#include <assert.h>

#include "psa/client.h"
#include "tfm_plat_defs.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Check whether the left-inclusive, right-exclusive address interval
 *        [host_ptr, host_ptr+size) is a subset of the left-inclusive,
 *        right-inclusive address interval [range_base, range_limit].
 *
 * \param[in] host_ptr    Base address of the (presumed) subset address
 *                        interval.
 * \param[in] size        Size of the (presumed) subset interval (i.e., the
 *                        number of bytes inside the (presumed) subset
 *                        interval).
 * \param[in] range_base  Base address of the (presumed) superset address
 *                        interval.
 * \param[in] range_limit Inclusive end address of the (presumed) superset
 *                        address interval (i.e., the address of the last byte
 *                        within the (presumed) superset interval).
 *
 * \retval true   The presumed subset interval is indeed a subset of the
 *                presumed superset interval.
 * \retval false  Otherwise.
 */
static inline bool comms_range_access_valid(uint64_t host_ptr,
                                            uint32_t size,
                                            uint64_t range_base,
                                            uint64_t range_limit)
{
    /*
     * Accessing zero bytes is permitted anywhere, even in an empty interval.
     * (The empty set is a subset of the empty set.)
     */
    if (size == 0) {
        return true;
    }

    /*
     * Accessing at least one byte in an empty interval is not permitted.
     * (Note: both boundaries of the presumed superset interval are inclusive.)
     */
    if (range_base > range_limit) {
        assert(false);
        return false;
    }

    /* Compare the base addresses; both are inclusive. */
    if (host_ptr < range_base) {
        return false;
    }

    /*
     * The mathematical inequality that permits the access, comparing exclusive
     * end addresses, is
     *
     *     host_ptr + size <= range_limit + 1
     *
     * A naïve encoding of this inequality in C hazards two unsigned integer
     * wrap-arounds: one in either addition. Because here we know that "size"
     * is positive, we can rewrite the above as
     *
     *     host_ptr + (size - 1) <= range_limit
     *
     * with the (size - 1) term remaining non-negative. (And this inequality in
     * fact compares the inclusive end addresses.) Subtracting (size - 1) from
     * both sides, we get
     *
     *     host_ptr <= range_limit - (size - 1)
     *
     * If the RHS is negative, then the access must be rejected (as "host_ptr"
     * is non-negative).
     *
     * If, on the other hand, the RHS is non-negative, then this form of the
     * inequality can be encoded in C as-is, for permitting access.
     */
    if (range_limit < size - 1) {
        return false;
    }
    if (host_ptr <= range_limit - (size - 1)) {
        return true;
    }
    return false;
}

/**
 * \brief Check that RSE comms callers have permission to access a memory
 *        buffer.
 *
 * \param[in]  owner               The owner of host memory against which the
 *                                 memory access is checked (e.g. MHU device).
 * \param[in]  host_ptr            Address of the memory region to be accessed.
 * \param[in]  size                Size of the memory region to be accessed.
 * \param[in]  is_write            True, if the memory access is a write
 *                                 operation, False otherwise.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Caller has permission to access buffer.
 * \retval Other return code     Caller does not have permission, or an error
 *                               occurred.
 */
enum tfm_plat_err_t comms_permissions_memory_check(void *owner,
                                                   uint64_t host_ptr,
                                                   uint32_t size,
                                                   bool is_write);

/**
 * \brief Check that RSE comms callers have permission to access a service.
 *
 * \note in_vec and in_len are passed in as the Crypto partition encodes which
 *       function is requested in the first in_vec.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Caller has permission to access service.
 * \retval Other return code     Caller does not have permission, or an error
 *                               occurred.
 */
enum tfm_plat_err_t comms_permissions_service_check(psa_handle_t handle,
                                                    const psa_invec *in_vec,
                                                    size_t in_len,
                                                    int32_t type);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_PERMISSIONS_HAL_H__ */

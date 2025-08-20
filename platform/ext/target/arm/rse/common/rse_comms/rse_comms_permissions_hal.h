/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_PERMISSIONS_HAL_H__
#define __RSE_COMMS_PERMISSIONS_HAL_H__

#include "psa/client.h"
#include "tfm_plat_defs.h"
#include "rse_comms_atu_hal.h"
#include "rse_comms_link_defs.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

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
enum tfm_plat_err_t comms_permissions_memory_check(rse_comms_node_id_t node_id,
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

/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_GET_ROUTING_TABLES_H__
#define __RSE_GET_ROUTING_TABLES_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Retrieves the routing tables associated with a given RSE.
 *
 * This function populates the provided buffer with the routing table entries for the specified
 * RSE identifier. The number of entries returned is limited by the size of the buffer.
 *
 * \param[out] routing_tables_buf  Pointer to a buffer where the routing table entries will be stored.
                                   This must be a multiple of words in size.
 * \param[in]  buf_size            Size of the buffer in bytes.
 * \param[in]  rse_id              Identifier for the RSE whose routing tables are to be retrieved.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t rse_get_routing_tables(uint8_t *routing_tables_buf, size_t buf_size,
                                           uint32_t rse_id);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_GET_ROUTING_TABLES_H__ */

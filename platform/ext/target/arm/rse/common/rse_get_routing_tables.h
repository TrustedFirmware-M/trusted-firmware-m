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
 * This function returns a pointer to the routing tables for the specified
 * RSE identifier.
 *
 * \param[out] routing_tables  Pointer to a pointer to receive the routing tables
 * \param[in]  routing_tables_size Size of the routing tables
 * \param[in]  rse_id              Identifier for the RSE whose routing tables are to be retrieved.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t rse_get_routing_tables(const uint8_t **routing_tables,
                                           size_t *routing_tables_size, uint32_t rse_id);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_GET_ROUTING_TABLES_H__ */

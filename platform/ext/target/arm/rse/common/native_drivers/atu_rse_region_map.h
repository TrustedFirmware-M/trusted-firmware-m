/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __ATU_RSE_REGION_MAP_H__
#define __ATU_RSE_REGION_MAP_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief ATU configuration request structure
 */
struct atu_region_map_t {
    uint64_t phys_addr;                         /*!< Physical address */
    uint32_t log_addr;                          /*!< Logical address */
    uint32_t size;                              /*!< Size to request */
    uint32_t out_bus_attr;                      /*!< Output bus attributes */
    uint8_t region_idx;                         /*!< ATU slot index */
    bool dynamically_allocate_logical_address;  /*!< Let the driver chose logical address */
};

#ifdef __cplusplus
}
#endif

#endif /* __ATU_RSE_REGION_MAP_H__ */

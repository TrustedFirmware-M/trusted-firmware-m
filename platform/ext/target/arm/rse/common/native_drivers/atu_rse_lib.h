/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __ATU_RSE_LIB_H__
#define __ATU_RSE_LIB_H__

#include <stdint.h>
#include "atu_rse_drv.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief ATU logical address space security types
 */
enum atu_log_type_t {
    ATU_LOG_ADDR_TYPE_NON_SECURE,
    ATU_LOG_ADDR_TYPE_SECURE,
    ATU_LOG_ADDR_TYPE_MAX
};

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

#define ATU_DOMAIN_SECURE (1u << 0)
#define ATU_DOMAIN_NONSEC (1u << 1)
#define ATU_DOMAIN_ROOT   (1u << 2)
#define ATU_DOMAIN_REALM  (1u << 3)

 /*
 * @brief API to return the page size value of the peripheral
 *
 * @param[in] dev       Pointer to ATU device structure
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
uint16_t atu_rse_get_page_size(struct atu_dev_t *dev);

/*
 * @brief API to initialize the ATU driver. Function to be called before any ATU operations
 *        in the hardware. Performs both static and dynamic initialization based on platform
 *        configuration.
 *
 * @param[in] dev                 Pointer to the ATU hardware base register address
 * @param[in] secure_domains      Domains to be considered secure
 * @param[in] atu_static_cfg      Static configuration array of the driver
 * @param[in] atu_static_cfg_cnt  Number of static configuration entries of the driver
 *
 * @return atu_error_t            On success ATU_ERR_NONE is returned, On failure
 *                                appropriate error code is returned
 */
enum atu_error_t atu_rse_drv_init(struct atu_dev_t *dev, uint8_t secure_domains,
                                  const struct atu_region_map_t atu_static_cfg[],
                                  const uint8_t atu_stat_cfg_cnt);

/*
 * @brief API to De-initialize the ATU driver
 *
 * @param[in] dev                 Pointer to the ATU hardware base register address
 * @param[in] atu_static_cfg_cnt  Number of static configuration entries of the driver
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 */
enum atu_error_t atu_rse_drv_deinit(struct atu_dev_t *dev, const uint8_t atu_static_cfg_cnt);

/*
 * @brief API to create a new dynamic mapping based on the address request
 *
 * @param[in] dev          Pointer to the ATU hardware base register address
 * @param[in] phys_addr    Physical address to be mapped
 * @param[in] log_addr     Logical address to be mapped to the physical address
 * @param[in] size         Size of the requested region
 * @param[in] out_bus_attr Bus attributes
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 */
enum atu_error_t atu_rse_map_addr_to_log_addr(struct atu_dev_t *dev, uint64_t phys_addr,
                                              uint32_t log_addr, uint32_t size,
                                              uint32_t out_bus_attr);

/*
 * @brief API to create a new dynamic mapping with log address selected by the driver
 *
 * @param[in] dev          Pointer to the ATU hardware base register address
 * @param[in] phys_addr    Physical address to be mapped
 * @param[in] size         Size of the requested region
 * @param[in] out_bus_attr Bus attributes
 * @param[out] log_addr    Logical address mapped to the physical address
 * @param[out] avail_size  Available size in case of error
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 */
enum atu_error_t atu_rse_map_addr_automatically(struct atu_dev_t *dev, uint64_t phys_addr,
                                                uint32_t size, uint32_t out_bus_attr,
                                                uint32_t *log_addr, uint32_t *avail_size);

/*
 * @brief API to free the ATU region which has already been mapped dynamically
 *
 * @param[in] dev       Pointer to the ATU hardware base register address
 * @param[in] log_addr  corresponding Logical address to release the mapping
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 */
enum atu_error_t atu_rse_free_addr(struct atu_dev_t *dev, uint32_t log_addr);

/*
 * atu_map_addr and atu_rse_free_addr declaration are intentionally added without dependency
 * on the dynamic slots to avoid warnings. ATU configuration macroes are provided by the
 * user in a custom header, thus the preprocessor can not evaluate it in this file.
 * With conditionless declaration the caller will access these functions and receive
 * linking error if the dynamic part of the library is disabled.
 */

#ifdef __cplusplus
}
#endif

#endif /* __ATU_RSE_LIB_H__ */

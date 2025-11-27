/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_DRIVER_SMIF_H
#define IFX_DRIVER_SMIF_H

#include <stdint.h>
#include "ifx_flash_driver_api.h"
#include "cy_smif_memslot.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Structure containing the SMIF driver memory configuration.
 *
 * SMIF driver instance represent memory region with own boundaries. Such
 * instance can share common SMIF memory configuration and context.
 */
typedef struct ifx_driver_smif_mem_t {
    SMIF_Type *smif_base; /**< Holds the base address of the SMIF block registers */
    const cy_stc_smif_block_config_t *block_config; /**< SMIF block config for Cy_SMIF_MemInit */
    const cy_stc_smif_mem_config_t *mem_config;  /**< SMIF memory configuration */
    const cy_stc_smif_mem_config_t *mem_config_dual_quad_pair;  /**< SMIF dual-quad pair memory config */
    cy_stc_smif_context_t *smif_context;  /**< SMIF driver context */
} ifx_driver_smif_mem_t;

/**
 * \brief Structure containing the SMIF driver instance data.
 *
 * SMIF flash driver uses \ref offset, \ref size  to define a working region that
 * is handled by active instance. Any access outside of this region is invalid
 * and SMIF flash driver returns \ref ARM_DRIVER_ERROR_PARAMETER in such cases.
 *
 * \ref ifx_driver_smif interface expects address to be relative to \ref offset.
 *
 * \note This structure is modified by \ref ifx_driver_smif.Initialize, so it
 * should not be a constant.
 */
typedef struct ifx_driver_smif_obj_t {
    const ifx_driver_smif_mem_t *memory;   /**< Memory configuration must be provided by BSP */

    uint32_t offset;    /**< Region offset relative to SMIF memory */
    uint32_t size;      /**< Region size */

    /* Flash CMSIS compatible information returned by driver. This structure is
     * initialized by \ref ifx_driver_smif.Initialize. */
    struct _ARM_FLASH_INFO *flash_info;
} ifx_driver_smif_obj_t;

/* TF-M SMIF driver operations */
extern const struct ifx_flash_driver_t ifx_driver_smif_mmio;
extern const struct ifx_flash_driver_t ifx_driver_smif_xip;

/* Create SMIF flash driver instance  */
#define IFX_DRIVER_SMIF_MMIO_INSTANCE(instance_name, instance_obj) \
    /* Use variable to validate instance_obj type */ \
    const struct ifx_driver_smif_obj_t *instance_name##_validate_obj = &instance_obj; \
    const ifx_flash_driver_instance_t instance_name = { \
        .handler = &instance_obj, \
        .driver = &ifx_driver_smif_mmio, \
    };

#define IFX_DRIVER_SMIF_XIP_INSTANCE(instance_name, instance_obj) \
    /* Use variable to validate instance_obj type */ \
    const struct ifx_driver_smif_obj_t *instance_name##_validate_obj = &instance_obj; \
    const ifx_flash_driver_instance_t instance_name = { \
        .handler = &instance_obj, \
        .driver = &ifx_driver_smif_xip, \
    };

#ifdef __cplusplus
}
#endif

#endif /* IFX_DRIVER_SMIF_H */

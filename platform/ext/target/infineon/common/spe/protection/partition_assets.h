/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PARTITION_ASSETS_H
#define PARTITION_ASSETS_H

#include <stddef.h>

#include "tfm_utils.h"
#include "load/asset_defs.h"
#include "region_defs.h"

/* This file exports custom partition assets.
 * IFX_{{partition.manifest.name|upper}}_CUSTOM_ASSETS and
 * IFX_{{partition.manifest.name|upper}}_CUSTOM_PERI_ASSETS patterns are used to
 * define custom assets for the partition. */

/* Define custom assets only if explicitly required by file that includes this
 * header. This is needed to avoid multiple definitions of the same assets in
 * different translation units. */
#ifdef IFX_PROVIDE_PARTITION_ASSETS

#include "platform_partition_assets.h"

/******************** PSA arch tests - FF driver partition ********************/

#ifdef PSA_API_TEST_IPC
const struct asset_desc_t ifx_driver_partition_assets[] = {
    {
        .mem.start = (uintptr_t)IFX_FF_TEST_DRIVER_PARTITION_MMIO_ADDR,
        .mem.limit = (uintptr_t)(IFX_FF_TEST_DRIVER_PARTITION_MMIO_ADDR
                                 + IFX_FF_TEST_DRIVER_PARTITION_MMIO_SIZE),
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
};

#define IFX_DRIVER_PARTITION_CUSTOM_ASSETS ifx_driver_partition_assets
#endif /* PSA_API_TEST_IPC */

/******************** PSA arch tests - FF server partition ********************/

#ifdef PSA_API_TEST_IPC
const struct asset_desc_t ifx_server_partition_assets[] = {
    {
        .mem.start = (uintptr_t)IFX_FF_TEST_SERVER_PARTITION_MMIO_ADDR,
        .mem.limit = (uintptr_t)(IFX_FF_TEST_SERVER_PARTITION_MMIO_ADDR
                                 + IFX_FF_TEST_SERVER_PARTITION_MMIO_SIZE),
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
};

#define IFX_SERVER_PARTITION_CUSTOM_ASSETS ifx_server_partition_assets
#endif /* PSA_API_TEST_IPC */

/*********************** Internal Trusted Storage *****************************/

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
const struct asset_desc_t ifx_tfm_sp_its_assets[] = {
#if !ITS_RAM_FS
    {
        .mem.start = (uintptr_t)TFM_HAL_ITS_FLASH_AREA_ADDR,
        .mem.limit = (uintptr_t)(TFM_HAL_ITS_FLASH_AREA_ADDR + TFM_HAL_ITS_FLASH_AREA_SIZE),
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
#endif
/* External memory has bigger MPC block sizes (e.g. 128 KB) so it is hard
 * to protect small PS area here, thus it is protected by protections */
#if (defined(TFM_PARTITION_PROTECTED_STORAGE) && (!IS_SMIF_MEMORY(IFX_TFM_PS_LOCATION)) && !PS_RAM_FS)
    {
        .mem.start = (uintptr_t)TFM_HAL_PS_FLASH_AREA_ADDR,
        .mem.limit = (uintptr_t)(TFM_HAL_PS_FLASH_AREA_ADDR + TFM_HAL_PS_FLASH_AREA_SIZE),
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
#endif
};

#define IFX_TFM_SP_ITS_CUSTOM_ASSETS ifx_tfm_sp_its_assets
/* Don't use MPC configuration provided by Device Configurator for ITS partition.
 * Use memory configuration provided by ifx_tfm_sp_its_assets instead. */
#define IFX_TFM_SP_ITS_SKIP_MEMORY_DOMAIN_CONFIGS
/* Don't use MPC configuration provided by Device Configurator for PS partition
 * Use memory configuration provided by ifx_tfm_sp_its_assets instead. */
#define IFX_TFM_SP_PS_SKIP_MEMORY_DOMAIN_CONFIGS
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

/******************************* Platform *************************************/

#ifdef TFM_PARTITION_PLATFORM
const struct asset_desc_t ifx_tfm_sp_platform_assets[] = {
#if !defined(IFX_MEMORY_CONFIGURATOR_MPC_CONFIG)
#if IFX_NV_COUNTERS_FLASH
    {
        .mem.start = (uintptr_t)IFX_TFM_NV_COUNTERS_AREA_ADDR,
        .mem.limit = (uintptr_t)IFX_TFM_NV_COUNTERS_AREA_ADDR + IFX_TFM_NV_COUNTERS_AREA_SIZE,
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
#endif /* IFX_NV_COUNTERS_FLASH */
#endif /* !defined(IFX_MEMORY_CONFIGURATOR_MPC_CONFIG) */
};

#define IFX_TFM_SP_PLATFORM_CUSTOM_ASSETS ifx_tfm_sp_platform_assets
#endif /* TFM_PARTITION_PLATFORM */

/***************************** NS Agent TZ ************************************/

#ifdef TFM_PARTITION_NS_AGENT_TZ
extern uint8_t ns_agent_tz_stack[];
static const struct asset_desc_t ifx_ns_agent_tz_partition_assets[] = {
/* For Isolation Level 2 and 3 ns_agent_tz_stack must be protected correctly
 * by MPU and MPC. For Level 3 this asset is generated automatically, but
 * for Level 2 it must be added here. */
#if TFM_ISOLATION_LEVEL == 2
    {
        .mem.start = (uintptr_t)ns_agent_tz_stack,
        .mem.limit = (uintptr_t)&ns_agent_tz_stack[TFM_NS_AGENT_TZ_STACK_SIZE_ALIGNED],
        .attr      = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE,
    },
#endif /* TFM_ISOLATION_LEVEL == 2 */
};

#define IFX_TFM_SP_NS_AGENT_TZ_CUSTOM_ASSETS ifx_ns_agent_tz_partition_assets
#endif /* TFM_PARTITION_NS_AGENT_TZ */

#endif /* IFX_PROVIDE_PARTITION_ASSETS */

#endif /* PARTITION_ASSETS_H */

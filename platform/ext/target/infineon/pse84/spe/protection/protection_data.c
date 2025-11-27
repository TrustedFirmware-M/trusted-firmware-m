/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_impl.h"
#include "config_tfm.h"
#include "array.h"
#include "cy_device.h"
#include "project_memory_layout.h"
#include "protection_regions_cfg.h"
#include "protection_types.h"

/* SPE must access memory MPCs using Secure alias as MPCs are protected as
 * Secure, thus, in memory configs, MPC macros are cast to Secure alias */

static const ifx_memory_config_t ifx_rram0_sbus_config = {
    .mpc = IFX_MPC_NOT_CONTROLLED_BY_TFM,  /* RRAM MPC is owned by SE and inaccessible to TF-M */
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_RRAM_SBUS_BASE),
    .size = IFX_RRAM_SIZE,
};

static const ifx_memory_config_t ifx_sram0_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC0_MPC0),
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_SBUS_BASE),
    .size = IFX_SRAM0_SIZE,
};

static const ifx_memory_config_t ifx_sram1_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC1_MPC0),
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_SBUS_BASE),
    .size = IFX_SRAM1_SIZE,
};

static const ifx_memory_config_t ifx_socmem_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SOCMEM_SRAM_MPC0),
    .mpc_block_size = CY_MPC_SIZE_8KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SOCMEM_RAM_SBUS_BASE),
    .size = IFX_SOCMEM_RAM_SIZE,
};

#if IFX_SMIF_XIP0_ENABLED
static const ifx_memory_config_t ifx_xip_port0_ahb_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT0_SBUS_BASE),
    .size = IFX_XIP_PORT0_SIZE,
};
#endif /* IFX_SMIF_XIP0_ENABLED */

#if IFX_SMIF_XIP1_ENABLED
static const ifx_memory_config_t ifx_xip_port1_ahb_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT1_SBUS_BASE),
    .size = IFX_XIP_PORT1_SIZE,
};
#endif /* IFX_SMIF_XIP1_ENABLED */

static const ifx_memory_config_t ifx_rram0_cbus_config = {
    .mpc = IFX_MPC_NOT_CONTROLLED_BY_TFM,  /* RRAM MPC is owned by SE and inaccessible to TF-M */
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_RRAM_CBUS_BASE),
    .size = IFX_RRAM_SIZE,
};

static const ifx_memory_config_t ifx_sram0_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC0_MPC0),
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_CBUS_BASE),
    .size = IFX_SRAM0_SIZE,
};

static const ifx_memory_config_t ifx_sram1_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC1_MPC0),
    .mpc_block_size = CY_MPC_SIZE_4KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_CBUS_BASE),
    .size = IFX_SRAM1_SIZE,
};

static const ifx_memory_config_t ifx_socmem_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SOCMEM_SRAM_MPC0),
    .mpc_block_size = CY_MPC_SIZE_8KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SOCMEM_RAM_CBUS_BASE),
    .size = IFX_SOCMEM_RAM_SIZE,
};

#if IFX_SMIF_XIP0_ENABLED
static const ifx_memory_config_t ifx_xip_port0_ahb_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT0_CBUS_BASE),
    .size = IFX_XIP_PORT0_SIZE,
};
#endif /* IFX_SMIF_XIP0_ENABLED */

#if IFX_SMIF_XIP1_ENABLED
static const ifx_memory_config_t ifx_xip_port1_ahb_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT1_CBUS_BASE),
    .size = IFX_XIP_PORT1_SIZE,
};
#endif /* IFX_SMIF_XIP1_ENABLED */

#if IFX_SMIF_XIP0_ENABLED
static const ifx_memory_config_t ifx_xip_port0_axi_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF0_CORE_AXI_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(CY_XIP_PORT0_BASE),
    .size = CY_XIP_PORT0_SIZE,
};
#endif /* IFX_SMIF_XIP0_ENABLED */

#if IFX_SMIF_XIP1_ENABLED
static const ifx_memory_config_t ifx_xip_port1_axi_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)SMIF1_CORE_AXI_MPC0),
    .mpc_block_size = CY_MPC_SIZE_128KB,
    .s_address = IFX_S_ADDRESS_ALIAS(CY_XIP_PORT1_BASE),
    .size = CY_XIP_PORT1_SIZE,
};
#endif /* IFX_SMIF_XIP1_ENABLED */

const ifx_memory_config_t* const ifx_memory_cm33_config[] = {
    &ifx_rram0_sbus_config,
    &ifx_sram0_sbus_config,
    &ifx_sram1_sbus_config,
    &ifx_socmem_sbus_config,
#if IFX_SMIF_XIP0_ENABLED
    &ifx_xip_port0_ahb_sbus_config,
#endif /* IFX_SMIF_XIP0_ENABLED */
#if IFX_SMIF_XIP1_ENABLED
    &ifx_xip_port1_ahb_sbus_config,
#endif /* IFX_SMIF_XIP1_ENABLED */
    &ifx_rram0_cbus_config,
    &ifx_sram0_cbus_config,
    &ifx_sram1_cbus_config,
    &ifx_socmem_cbus_config,
#if IFX_SMIF_XIP0_ENABLED
    &ifx_xip_port0_ahb_cbus_config,
#endif /* IFX_SMIF_XIP0_ENABLED */
#if IFX_SMIF_XIP1_ENABLED
    &ifx_xip_port1_ahb_cbus_config,
#endif /* IFX_SMIF_XIP1_ENABLED */
};

/* Number of items in \ref ifx_memory_cm33_config */
const size_t ifx_memory_cm33_config_count = ARRAY_SIZE(ifx_memory_cm33_config);

const ifx_memory_config_t* const ifx_memory_cm55_config[] = {
#if IFX_SMIF_XIP0_ENABLED
    &ifx_xip_port0_axi_config,
#endif /* IFX_SMIF_XIP0_ENABLED */
#if IFX_SMIF_XIP1_ENABLED
    &ifx_xip_port1_axi_config,
#endif /* IFX_SMIF_XIP1_ENABLED */
};

/* Number of items in \ref ifx_memory_cm55_config */
const size_t ifx_memory_cm55_config_count = ARRAY_SIZE(ifx_memory_cm55_config);

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_domain_mem_get_asset(
                                             const ifx_mem_domain_region_cfg_t *p_region,
                                             struct asset_desc_t *p_asset,
                                             bool *valid)
{
    uint32_t mem_base = 0UL;
    *valid = true;
    /* RRAMC0_MPC1 is not supported by TF-M */
    if ((void*)p_region->base == (void*)RRAMC0_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_RRAM_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)RAMC0_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)RAMC1_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_SBUS_BASE);
#if IFX_SOCMEM_ENABLED
    } else if ((void*)p_region->base == (void*)SOCMEM_SRAM_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_SOCMEM_RAM_SBUS_BASE);
#endif /* IFX_SOCMEM_ENABLED */
#if IFX_SMIF_XIP0_ENABLED
    } else if ((void*)p_region->base == (void*)SMIF0_CACHE_BLOCK_CACHEBLK_AHB_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT0_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)SMIF0_CORE_AXI_MPC0) {
        /* There are AHB and AXI MPC controllers for XIP, skip second one */
        *valid = false;
#endif /* IFX_SMIF_XIP0_ENABLED */
#if IFX_SMIF_XIP1_ENABLED
    } else if ((void*)p_region->base == (void*)SMIF1_CACHE_BLOCK_CACHEBLK_AHB_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_XIP_PORT1_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)SMIF1_CORE_AXI_MPC0) {
        /* There are AHB and AXI MPC controllers for XIP, skip second one */
        *valid = false;
#endif /* IFX_SMIF_XIP1_ENABLED */
    } else {
        /* Unexpected MPC */
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    p_asset->mem.start = mem_base + p_region->offset;
    p_asset->mem.limit = p_asset->mem.start + p_region->size;
    p_asset->attr = ASSET_ATTR_NUMBERED_MMIO | ASSET_ATTR_READ_WRITE;
    FIH_RET(TFM_HAL_SUCCESS);
}

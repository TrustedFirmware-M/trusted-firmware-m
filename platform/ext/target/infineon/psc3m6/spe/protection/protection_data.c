/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_impl.h"
#include "config_tfm.h"
#include "tfm_utils.h"
#include "cy_device.h"
#include "project_memory_layout.h"
#include "protection_regions_cfg.h"
#include "protection_types.h"
#include "coverity_check.h"

/* SPE must access memory MPCs using Secure alias as MPCs are protected as
 * Secure, thus, in memory configs, MPC macros are cast to Secure alias */

static const ifx_memory_config_t ifx_sram0_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC0_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_SBUS_BASE),
    .size = IFX_SRAM0_SIZE,
};

static const ifx_memory_config_t ifx_sram1_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC1_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_SBUS_BASE),
    .size = IFX_SRAM1_SIZE,
};

static const ifx_memory_config_t ifx_flash0_sbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)FLASHC_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_FLASH_SBUS_BASE),
    .size = IFX_FLASH_SIZE,
};

static const ifx_memory_config_t ifx_sram0_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC0_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_CBUS_BASE),
    .size = IFX_SRAM0_SIZE,
};

static const ifx_memory_config_t ifx_sram1_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)RAMC1_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_CBUS_BASE),
    .size = IFX_SRAM1_SIZE,
};

static const ifx_memory_config_t ifx_flash0_cbus_config = {
    .mpc = (MPC_Type*)IFX_S_ADDRESS_ALIAS((uint32_t)FLASHC_MPC0),
    .mpc_block_size = CY_MPC_SIZE_2KB,
    .s_address = IFX_S_ADDRESS_ALIAS(IFX_FLASH_CBUS_BASE),
    .size = IFX_FLASH_SIZE,
};

const ifx_memory_config_t* const ifx_memory_cm33_config[] = {
    &ifx_sram0_sbus_config,
    &ifx_sram1_sbus_config,
    &ifx_flash0_sbus_config,
    &ifx_sram0_cbus_config,
    &ifx_sram1_cbus_config,
    &ifx_flash0_cbus_config,
};

/* Number of items in \ref ifx_memory_cm33_config */
const size_t ifx_memory_cm33_config_count = ARRAY_SIZE(ifx_memory_cm33_config);

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_domain_mem_get_asset(
                                             const ifx_mem_domain_region_cfg_t *p_region,
                                             struct asset_desc_t *p_asset,
                                             bool *valid)
{
    uint32_t mem_base = 0UL;
    *valid = true;

    if ((void*)p_region->base == (void*)FLASHC_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_FLASH_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)RAMC0_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_SRAM0_SBUS_BASE);
    } else if ((void*)p_region->base == (void*)RAMC1_MPC0) {
        mem_base = IFX_S_ADDRESS_ALIAS(IFX_SRAM1_SBUS_BASE);
    } else {
        /* Unexpected MPC */
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    p_asset->mem.start = mem_base + p_region->offset;
    p_asset->mem.limit = p_asset->mem.start + p_region->size;
    p_asset->attr = IFX_ASSET_ATTR_COMBINE(ASSET_ATTR_NUMBERED_MMIO, ASSET_ATTR_READ_WRITE);
    FIH_RET(TFM_HAL_SUCCESS);
}

bool ifx_platform_mpc_is_rot(const MPC_Type *mpc)
{
    /* ROT config for Flash MPC is not accessible on this device */
    /* IMPROVEMENT: (DRIVERS-26629) Use Cy_Mpc_IsRotConfigurable function */
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_3, "FLASHC_MPC0 hardware register address is cast to the generic MPC_Type used by the driver")
    return (((mpc) == (MPC_Type*)FLASHC_MPC0) ? false : true);
}

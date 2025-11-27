/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cy_device.h"
#include "cy_mpc.h"
#include "ifx_regions.h"
#include "ifx_utils.h"
#include "protection_mpc_api.h"
#include "protection_regions_cfg.h"
#include "protection_types.h"
#include "tfm_hal_isolation.h"
#include <string.h>

/* Size of MPC block size */
#define IFX_MPC_BLOCK_SIZE            (0x800UL) /* 2 KB */

/* MPC attributes [bit[3]=0, bit[2]=W, bit[1]=R, bit[0]=NS] for each
 * nibble for PC=0 to PC=7 for this memory region (PC7, PC6, ..., PC0) */
#define IFX_MPC_PC_ATTR_MSK           (0xFUL)     /* Mask for MPC protection context */
#define IFX_MPC_PC_ATTR_SIZE_IN_BITS  (4UL)       /* Number of MPC attribute bits */
#define IFX_MPC_PC_ATTR_NS_MSK        (1UL << 0)  /* NS mask for MPC attributes for PC */
#define IFX_MPC_PC_ATTR_W_MSK         (1UL << 1)  /* Write mask for MPC attributes for PC */
#define IFX_MPC_PC_ATTR_R_MSK         (1UL << 2)  /* Read mask for MPC attributes for PC */

/* Get MPC attributes for given PC */
#define IFX_MPC_GET_PC_ATTR(attr, pc) (((attr) >> ((pc) * IFX_MPC_PC_ATTR_SIZE_IN_BITS)) \
                                       & IFX_MPC_PC_ATTR_MSK)

/* SRAM0 Secure base address */
#define CY_SRAM0_BASE_S               (IFX_S_ADDRESS_ALIAS(CY_SRAM0_BASE))
/* FLASH Secure base address */
#define CY_FLASH_BASE_S               (IFX_S_ADDRESS_ALIAS(CY_FLASH_BASE))

/* Structure that holds information about single MPC entry in policy */
typedef struct {
    uint16_t mem_offset;    /* Offset from a start of memory in IFX_MPC_BLOCK_SIZE chunks */
    uint16_t mem_size;      /* Size (in IFX_MPC_BLOCK_SIZE chunks) of the memory region */
    uint32_t attr;          /* MPC attributes [bit[3]=0, bit[2]=W, bit[1]=R, bit[0]=NS] for each
                             * nibble for PC=0 to PC=7 for this memory region (PC7, PC6, ..., PC0)
                             */
} ifx_mpc_cfg_t;

/* Structure that represents MPC policy */
typedef struct {
    uint8_t n_ram_mpc;                      /* Number of RAM MPC structs */
    uint8_t n_flash_mpc;                    /* Number of flash MPC structs */
    uint8_t unused[2];
    ifx_mpc_cfg_t mpc_struct[32];        /* RAM MPC structs followed by Flash MPC structs */
} ifx_mpc_policy_t;

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_init_cfg(void)
{
    /* When MPC settings are in policy, they are applied by lower levels of boot,
     * so nothing to do in TFM ifx_mpc_init_cfg */
    return TFM_HAL_SUCCESS;
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_static_boundaries(void)
{
    /* MPC settings are out of our control */
    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

/**
 * \brief Check access to memory region by MPC.
 *
 * \param[in]   mpc_cfg       Pointer to MPC config \ref ifx_mpc_cfg_t.
 * \param[in]   p_info        Pointer to structure describing partition info.
 * \param[in]   access_type   The memory access types to be checked.
 *
 * \return TFM_HAL_SUCCESS - The memory region has the access permissions by MPC.
 *         TFM_HAL_ERROR_MEM_FAULT - The memory region has no access permissions
 *                                   by MPC.
 */
static enum tfm_hal_status_t ifx_mpc_check_access_rights(const ifx_mpc_cfg_t *mpc_cfg,
                                                         const struct ifx_partition_info_t *p_info,
                                                         uint32_t access_type)
{
    bool is_secure = (access_type & TFM_HAL_ACCESS_NS) == 0U;
    fih_int pc = (fih_int)IFX_GET_PARTITION_PC(p_info, is_secure);
    unsigned int pc_uint = (unsigned int)(fih_int_decode(pc));
    unsigned int pc_attr = IFX_MPC_GET_PC_ATTR(mpc_cfg->attr, pc_uint);

    /* If Read is requested but not allowed - return error */
    if (((access_type & TFM_HAL_ACCESS_READABLE) == TFM_HAL_ACCESS_READABLE) &&
        !((pc_attr & IFX_MPC_PC_ATTR_R_MSK) == IFX_MPC_PC_ATTR_R_MSK)) {
        return TFM_HAL_ERROR_MEM_FAULT;
    }

    /* If Write is requested but not allowed - return error */
    if (((access_type & TFM_HAL_ACCESS_WRITABLE) == TFM_HAL_ACCESS_WRITABLE) &&
        !((pc_attr & IFX_MPC_PC_ATTR_W_MSK) == IFX_MPC_PC_ATTR_W_MSK)) {
        return TFM_HAL_ERROR_MEM_FAULT;
    }

    /* If S/NS attributes mismatch - return error */
    if (((pc_attr & IFX_MPC_PC_ATTR_NS_MSK) != 0U) == is_secure) {
        return TFM_HAL_ERROR_MEM_FAULT;
    }

    return TFM_HAL_SUCCESS;
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_memory_check(const struct ifx_partition_info_t *p_info,
                                                         uintptr_t base,
                                                         size_t size,
                                                         uint32_t access_type)
{
    uint32_t mpc_start_idx;
    uint32_t mpc_end_idx;
    uint32_t mpc_base_addr;
    const ifx_mpc_policy_t* const mpc_policy = (ifx_mpc_policy_t*) &SFLASH->N_RAM_MPC;
    uintptr_t base_s = IFX_S_ADDRESS_ALIAS(base);

    /* Handle MPCs for different memory types */
    if (ifx_is_region_inside_other(base_s, base_s + size,
                                   CY_SRAM0_BASE_S, CY_SRAM0_BASE_S + CY_SRAM0_SIZE)) {
        /* Handle SRAM0 MPC - SRAM0 MPCs are stored in indexes
         * 0 -> SFLASH->N_RAM_MPC */
        mpc_start_idx = 0;
        mpc_end_idx = mpc_policy->n_ram_mpc;
        mpc_base_addr = CY_SRAM0_BASE_S;
    } else if (ifx_is_region_inside_other(base_s, base_s + size,
                                          CY_FLASH_BASE_S, CY_FLASH_BASE_S + CY_FLASH_SIZE)) {
        /* Handle FLASH MPC - FLASH MPCs are stored in indexes
         * SFLASH->N_RAM_MPC -> (SFLASH->N_RAM_MPC + SFLASH->N_FLASH_MPC) */
        mpc_start_idx = mpc_policy->n_ram_mpc;
        mpc_end_idx = (uint32_t)mpc_policy->n_ram_mpc + (uint32_t)mpc_policy->n_flash_mpc;
        mpc_base_addr = CY_FLASH_BASE_S;
    } else {
        /* Unknown memory type - return error */
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    for (uint32_t mpc_idx = mpc_start_idx; mpc_idx < mpc_end_idx; mpc_idx++) {
        /* Calculate MPC region start and end addresses from MPC blocks */
        uint32_t mpc_region_start_addr = mpc_base_addr
                                          + (mpc_policy->mpc_struct[mpc_idx].mem_offset
                                             * IFX_MPC_BLOCK_SIZE);
        uint32_t mpc_region_end_addr   = mpc_region_start_addr
                                          + (mpc_policy->mpc_struct[mpc_idx].mem_size
                                             * IFX_MPC_BLOCK_SIZE);

        /* Check if requested region is inside current MPC region */
        if (ifx_is_region_inside_other(base_s, base_s + size,
                                       mpc_region_start_addr, mpc_region_end_addr)) {
            FIH_RET(ifx_mpc_check_access_rights(&mpc_policy->mpc_struct[mpc_idx],
                                                p_info,
                                                access_type));
        }
    }

    /* Requested region does not match any known MPC region - return error */
    FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
}

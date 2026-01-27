/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_impl.h"
#include "config_tfm.h"
#include "cy_mpc.h"
#include "ifx_se_platform.h"
#include "ifx_se_tfm_utils.h"
#include "protection_mpc_sert.h"
#include "region_defs.h"
#include "coverity_check.h"
#include "tfm_hal_isolation.h"

#define IFX_MPC_EXT_BLOCK_SIZE_TO_BYTES(mpc_size)   (1UL << ((uint32_t)(mpc_size) + 5UL))

/* The size of RRAM memory controlled by SE RT Services */
#define IFX_SE_RT_RRAM_SIZE         IFX_RRAM_SIZE

/* The number of RRAM MPC blocks controlled by SE RT Services */
#define IFX_SE_RT_RRAM_BLOCK_COUNT  (IFX_SE_RT_RRAM_SIZE / IFX_SE_RT_RRAM_BLOCK_SIZE)

/* MPC attribute cache used to implement ifx_mpc_memory_check for RRAM MPC controlled
 * by SE RT Services in following format:
 *   2:0  - PC0 W/R/NS
 *   6:4  - PC1 W/R/NS
 *  10:8  - PC2 W/R/NS
 *  14:12 - PC3 W/R/NS
 *  18:16 - PC4 W/R/NS
 *  22:20 - PC5 W/R/NS
 *  26:24 - PC6 W/R/NS
 *  30:28 - PC7 W/R/NS
 *
 * For each nibble:
 * - bit[0] : NS (0 indicates secure, 1 indicates non-secure)
 * - bit[1] : R (0 indicates read access not allowed. 1 indicates read access allowed)
 * - bit[2] : W (0 indicates write access not allowed, 1 indicates write access allowed)
 */
static uint32_t ifx_mpc_se_rt_rram_attr[IFX_SE_RT_RRAM_BLOCK_COUNT] = {0};

/* Converted information provided by ifx_mpc_region_config_t to external MPC cache attributes */
typedef struct {
    /*! Bit field with MPC cached attributes */
    uint32_t attr;
    /*! First block index in cached attributes */
    uint32_t first_block_idx;
    /*! Last block index in cached attributes */
    uint32_t last_block_idx;
} ifx_mpc_ext_cache_cfg_info_t;

/**
 * \brief Returns attributes for MPC attributes cache
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_raw_region_config_t for more details.
 * \param[out] info         Information generated for requested configuration.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input (e.g. invalid arguments or
 *                                          configuration).
 */
static enum tfm_hal_status_t ifx_mpc_sert_config_to_cache_info(
                                        const ifx_mpc_raw_region_config_t *mpc_reg_cfg,
                                        ifx_mpc_ext_cache_cfg_info_t *info)
{
    if (info == NULL) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    /* Default values to improve FIH resistance */
    info->attr = 0x00000000U;

    uint32_t block_size = IFX_MPC_EXT_BLOCK_SIZE_TO_BYTES(mpc_reg_cfg->mpc_block_size);
    if (IFX_SE_RT_RRAM_BLOCK_SIZE != block_size) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    uint32_t offset = mpc_reg_cfg->offset;
    info->first_block_idx = offset / IFX_SE_RT_RRAM_BLOCK_SIZE;
    info->last_block_idx  = IFX_ROUND_UP_TO_MULTIPLE(offset + mpc_reg_cfg->size,
                                                     IFX_SE_RT_RRAM_BLOCK_SIZE)
                             / IFX_SE_RT_RRAM_BLOCK_SIZE;
    if ((info->first_block_idx >= IFX_SE_RT_RRAM_BLOCK_COUNT) ||
        (info->last_block_idx > IFX_SE_RT_RRAM_BLOCK_COUNT)) {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }

    for (uint32_t pc = IFX_PC_TFM_SPM_ID; pc < MPC_PC_NR; pc++) {
        if (IFX_GET_PC(mpc_reg_cfg->ns_mask, pc) != 0U) {
            info->attr |= (1UL << ((pc * 4U) + 0U));
        }

        if (IFX_GET_PC(mpc_reg_cfg->r_mask, pc) != 0U) {
            info->attr |= (1UL << ((pc * 4U) + 1U));
        }

        if (IFX_GET_PC(mpc_reg_cfg->w_mask, pc) != 0U) {
            info->attr |= (1UL << ((pc * 4U) + 2U));
        }
    }

    return TFM_HAL_SUCCESS;
}

enum tfm_hal_status_t ifx_mpc_sert_apply_configuration(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
#if TFM_ISOLATION_LEVEL == 3
    /* SE RT Services are not available for SPM when TF-M scheduler is started.
     * It's expected to return success on dynamic switching. */
    if (ifx_asset_protection_type == IFX_ASSET_PROTECTION_PARTITION_DYNAMIC) {
        return TFM_HAL_SUCCESS;
    }
#endif /* TFM_ISOLATION_LEVEL == 3 */

    ifx_se_mpc_rot_cfg_crc_t config;
    ifx_se_status_t se_status;
    config.mpc_config.addr_offset = mpc_reg_cfg->offset;
    config.mpc_config.size = mpc_reg_cfg->size;
    if (mpc_reg_cfg->mpc_block_size == CY_MPC_SIZE_4KB) {
        config.mpc_config.region_size = IFX_SE_MPC_SIZE_4KB;
    } else {
        return TFM_HAL_ERROR_INVALID_INPUT;
    }
    for (uint32_t pc = IFX_PC_TFM_SPM_ID; pc < MPC_PC_NR; pc++) {
        config.mpc_config.pc = (ifx_se_mpc_prot_context_t)pc;
        config.mpc_config.secure = IFX_SE_MPC_SECURE;
        config.mpc_config.access = IFX_SE_MPC_ACCESS_DISABLED;

        if (IFX_GET_PC(mpc_reg_cfg->ns_mask, pc) != 0U) {
            config.mpc_config.secure = IFX_SE_MPC_NON_SECURE;
        } else {
            config.mpc_config.secure = IFX_SE_MPC_SECURE;
        }

        uint8_t r_mask = IFX_GET_PC(mpc_reg_cfg->r_mask, pc);
        uint8_t w_mask = IFX_GET_PC(mpc_reg_cfg->w_mask, pc);
        if ((r_mask != 0U) && (w_mask != 0U)) {
            config.mpc_config.access = IFX_SE_MPC_ACCESS_RW;
        } else if (r_mask != 0U) {
            config.mpc_config.access = IFX_SE_MPC_ACCESS_R;
        } else if (w_mask != 0U) {
            config.mpc_config.access = IFX_SE_MPC_ACCESS_W;
        } else {
            config.mpc_config.access = IFX_SE_MPC_ACCESS_DISABLED;
        }

        config.crc = IFX_CRC32_CALC((uint8_t*)&config.mpc_config, sizeof(config.mpc_config));
        se_status = ifx_se_mpc_config_rot_mpc_struct(&config, IFX_SE_TFM_SYSCALL_CONTEXT);
        if (!IFX_SE_IS_STATUS_SUCCESS(se_status)) {
            return TFM_HAL_ERROR_GENERIC;
        }
    }

    /* Update cache */
    ifx_mpc_ext_cache_cfg_info_t info;
    if (ifx_mpc_sert_config_to_cache_info(mpc_reg_cfg, &info) != TFM_HAL_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    for (uint32_t block_id = info.first_block_idx; block_id < info.last_block_idx; block_id++) {
        ifx_mpc_se_rt_rram_attr[block_id] = info.attr;
    }

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_verify_configuration(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
    /* We can't read the MPC directly because the PPCs restrict access to PC0/1 only
     * and the SE RT doesn't provide a way to read it
     * But it's possible to validate RRAM MPC attribute cache */
    ifx_mpc_ext_cache_cfg_info_t info;
    if (ifx_mpc_sert_config_to_cache_info(mpc_reg_cfg, &info) != TFM_HAL_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    for (uint32_t block_id = info.first_block_idx; block_id < info.last_block_idx; block_id++) {
        if (ifx_mpc_se_rt_rram_attr[block_id] != info.attr) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }
    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_memory_check(
                                           const struct ifx_partition_info_t *p_info,
                                           const ifx_memory_config_t* memory_config,
                                           uintptr_t base,
                                           size_t size,
                                           uint32_t access_type)
{
    if (memory_config == NULL) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }

    uint32_t block_size = IFX_MPC_EXT_BLOCK_SIZE_TO_BYTES(memory_config->mpc_block_size);
    if (IFX_SE_RT_RRAM_BLOCK_SIZE != block_size) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }

    uint32_t offset          = IFX_S_ADDRESS_ALIAS(base) - memory_config->s_address;
    uint32_t first_block_idx = offset / IFX_SE_RT_RRAM_BLOCK_SIZE;
    uint32_t last_block_idx  = IFX_ROUND_UP_TO_MULTIPLE(offset + size,
                                                        IFX_SE_RT_RRAM_BLOCK_SIZE)
                                / IFX_SE_RT_RRAM_BLOCK_SIZE;
    if ((first_block_idx >= IFX_SE_RT_RRAM_BLOCK_COUNT) ||
        (last_block_idx > IFX_SE_RT_RRAM_BLOCK_COUNT)) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }

    bool is_secure = (access_type & TFM_HAL_ACCESS_NS) == 0U;
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "external macro IS_NS_AGENT interprets non-boolean type as a boolean")
    uint32_t pc = (uint32_t)fih_int_decode(IFX_GET_PARTITION_PC(p_info, is_secure));

    uint32_t mask = 1UL << ((pc * 4u) + 0u);
    uint32_t attr = is_secure ? 0u : (1UL << ((pc * 4u) + 0u));

    if ((access_type & TFM_HAL_ACCESS_READABLE) != 0U) {
        mask |= 1UL << ((pc * 4u) + 1u);
        attr |= 1UL << ((pc * 4u) + 1u);
    }

    if ((access_type & TFM_HAL_ACCESS_WRITABLE) != 0U) {
        mask |= 1UL << ((pc * 4u) + 2u);
        attr |= 1UL << ((pc * 4u) + 2u);
    }

    for (uint32_t block_id = first_block_idx; block_id < last_block_idx; block_id++) {
        if ((ifx_mpc_se_rt_rram_attr[block_id] & mask) != attr) {
            FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_sert_init(void)
{
    /* Setup RRAM MPC MPC attribute cache used to implement ifx_mpc_memory_check */
    for (uint32_t block_id = 0; block_id < IFX_SE_RT_RRAM_BLOCK_COUNT; block_id++) {
        ifx_mpc_se_rt_rram_attr[block_id] = IFX_SE_RT_RRAM_MPC_DEFAULT_ATTRIBUTES;
    }

#if defined(TFM_FIH_PROFILE_ON)
    /* Validate ifx_mpc_memory_check */
    (void)fih_delay();
    for (uint32_t block_id = 0; block_id < IFX_SE_RT_RRAM_BLOCK_COUNT; block_id++) {
        if (ifx_mpc_se_rt_rram_attr[block_id] != IFX_SE_RT_RRAM_MPC_DEFAULT_ATTRIBUTES) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }
#endif

    FIH_RET(TFM_HAL_SUCCESS);
}

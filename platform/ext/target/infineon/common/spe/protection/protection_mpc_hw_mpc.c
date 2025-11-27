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
#include "region_defs.h"
#include "protection_types.h"
#include "protection_utils.h"
#include "protection_regions_cfg.h"
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
#include "protection_mpc_sert.h"
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
#include "region.h"
#include "ifx_regions.h"
#include "ifx_utils.h"
#include "utilities.h"

ifx_mpc_region_config_t ifx_fixed_mpc_static_config[IFX_MAX_FIXED_CONFIGS];
uint32_t ifx_fixed_mpc_static_config_count = 0;

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_fill_fixed_config(void)
{
    uint32_t idx = 0;

    /* Following MPC configs only change the PC mask thus if
     * IFX_ISOLATION_PC_SWITCHING is OFF, then PC mask will be the same, so no
     * need to reconfigure. */
#if IFX_ISOLATION_PC_SWITCHING
#if (TFM_ISOLATION_LEVEL == 2) && (CONFIG_TFM_AROT_PRESENT == 1)
    /* RW, ZI and stack as one region */
    ifx_fixed_mpc_static_config[idx++] =
    (ifx_mpc_region_config_t){
        .address    = (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_START, $$Base),
        .size       = (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) -
                      (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_START, $$Base),
        .ns_mask    = IFX_PC_NONE, /**< All secure */
        .r_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT,
        .w_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
        .is_rot     = true,
#endif
    };
#endif /* (TFM_ISOLATION_LEVEL == 2) && (CONFIG_TFM_AROT_PRESENT == 1) */

#ifdef CONFIG_TFM_PARTITION_META
    /* RW, ZI and stack as one region */
    ifx_fixed_mpc_static_config[idx++] =
    (ifx_mpc_region_config_t){
            .address    = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_START, $$Base),
            .size       = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_END, $$Base) -
                          (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_START, $$Base),
            .ns_mask    = IFX_PC_NONE, /**< All secure */
            .r_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT | IFX_PC_TZ_NSPE,
            .w_mask     = IFX_PC_TFM_SPM,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
        .is_rot         = true,
#endif
    };
#endif /* CONFIG_TFM_PARTITION_META */

#if TFM_ISOLATION_LEVEL == 3
#if TEST_NS_IFX_CODE_COVERAGE
    /* coverage linker region - secure PCs have RW access */
    ifx_fixed_mpc_static_config[idx++] =
    (ifx_mpc_region_config_t){
            .address    = (uint32_t)&REGION_NAME(Image$$, IFX_CODE_COVERAGE_START, $$Base),
            .size       = (uint32_t)&REGION_NAME(Image$$, IFX_CODE_COVERAGE_END, $$Base) -
                          (uint32_t)&REGION_NAME(Image$$, IFX_CODE_COVERAGE_START, $$Base),
            .ns_mask    = IFX_PC_NONE, /**< All secure */
            .r_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT | IFX_PC_TZ_NSPE,
            .w_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT | IFX_PC_TZ_NSPE,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
        .is_rot         = true,
#endif
    };
#endif /* TEST_NS_IFX_CODE_COVERAGE */
#endif /* TFM_ISOLATION_LEVEL == 3 */

#ifdef CONFIG_TFM_USE_TRUSTZONE
    ifx_fixed_mpc_static_config[idx++] =
    (ifx_mpc_region_config_t){
        .address    = (uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),
        .size       = (uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit) -
                      (uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),
        .ns_mask    = IFX_PC_NONE, /**< All secure */
        .r_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TZ_NSPE,
        .w_mask     = IFX_PC_NONE,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
        .is_rot     = true,
#endif
    };

    /* Unprivileged S code region for TFM image with enabled Default PC (with SPM) + PRoT + ARoT  */
    ifx_fixed_mpc_static_config[idx++] =
    (ifx_mpc_region_config_t){
        .address    = (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base),
        .size       = (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE_END, $$RO$$Limit) -
                      (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base),
        .ns_mask    = IFX_PC_NONE, /**< All secure */
        .r_mask     = IFX_PC_TFM_SPM | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT | IFX_PC_TZ_NSPE,
        .w_mask     = IFX_PC_NONE, /**< No write to code, R/O data */
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
        .is_rot     = true,
#endif
    };
    };
#endif /* CONFIG_TFM_USE_TRUSTZONE */
#endif /* IFX_ISOLATION_PC_SWITCHING */

    /* finally, set the count */
    if (idx > IFX_MAX_FIXED_CONFIGS) {
        tfm_core_panic();
    }
    ifx_fixed_mpc_static_config_count = idx;
    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_isolate_numbered_mmio(
                                                    const ifx_mpc_numbered_mmio_config_t* mpc_cfg,
                                                    const struct asset_desc_t* asset)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);
    ifx_mpc_region_config_t mpc_reg_cfg;

    mpc_reg_cfg.address = asset->mem.start;
    mpc_reg_cfg.size    = asset->mem.limit - asset->mem.start;

    mpc_reg_cfg.ns_mask = mpc_cfg->ns_mask;

    mpc_reg_cfg.r_mask  = mpc_cfg->pc_mask;
    mpc_reg_cfg.w_mask  = ((asset->attr & ASSET_ATTR_READ_WRITE) != 0U) ? mpc_cfg->pc_mask : 0U;

#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    mpc_reg_cfg.is_rot  = true;
#endif

    FIH_CALL(ifx_mpc_apply_configuration, fih_rc, &mpc_reg_cfg);
    FIH_RET(fih_rc);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_apply_configuration(
                                          const ifx_mpc_region_config_t* mpc_reg_cfg)
{
    const ifx_memory_config_t* memory_configs[IFX_REGION_MAX_MPC_COUNT];
    uint32_t                   mpc_cnt = sizeof(memory_configs)/sizeof(memory_configs[0]);
    enum tfm_hal_status_t      mem_cfg_res;
    FIH_RET_TYPE(enum tfm_hal_status_t) mem_cfg_res_fih;

    mem_cfg_res = ifx_get_all_memory_configs(memory_configs,
                                             &mpc_cnt,
                                             mpc_reg_cfg->address,
                                             mpc_reg_cfg->size);

    if (mem_cfg_res != TFM_HAL_SUCCESS) {
        FIH_RET(mem_cfg_res);
    }

    for (uint32_t mem_idx = 0; mem_idx < mpc_cnt; mem_idx++) {
        ifx_mpc_raw_region_config_t mpc_reg_cfg_raw = {
            .mpc_base       = memory_configs[mem_idx]->mpc,
            .mpc_block_size = memory_configs[mem_idx]->mpc_block_size,
            .offset         = IFX_S_ADDRESS_ALIAS(mpc_reg_cfg->address)
                               - memory_configs[mem_idx]->s_address,
            .size           = mpc_reg_cfg->size,
            .ns_mask        = mpc_reg_cfg->ns_mask,
            .r_mask         = mpc_reg_cfg->r_mask,
            .w_mask         = mpc_reg_cfg->w_mask,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
            .is_rot         = mpc_reg_cfg->is_rot,
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */
        };

        FIH_CALL(ifx_mpc_apply_raw_configuration, mem_cfg_res_fih, &mpc_reg_cfg_raw);
        if (FIH_NOT_EQ(mem_cfg_res_fih, TFM_HAL_SUCCESS)) {
            FIH_RET(mem_cfg_res_fih);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_apply_raw_configuration(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
    enum tfm_hal_status_t      mem_cfg_res;

    if (mpc_reg_cfg == NULL) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    /* MPC pointer is set to NULL for MPCs that are not configurable by TFM. */
    if (IFX_MPC_IS_EXTERNAL(mpc_reg_cfg->mpc_base)) {
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
        /* Use external service to protect memory */
        mem_cfg_res = ifx_mpc_sert_apply_configuration(mpc_reg_cfg);
        if (mem_cfg_res != TFM_HAL_SUCCESS) {
            /* Corresponding memory configuration was not found */
            FIH_RET(mem_cfg_res);
        }
#else /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
        FIH_RET(TFM_HAL_ERROR_NOT_SUPPORTED);
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
    } else {
        /* Use MPC peripheral to protect */
        mem_cfg_res = ifx_mpc_apply_configuration_with_mpc(mpc_reg_cfg);
        if (mem_cfg_res != TFM_HAL_SUCCESS) {
            /* Corresponding memory configuration was not found */
            FIH_RET(mem_cfg_res);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_configuration(
                                            const ifx_mpc_region_config_t* mpc_reg_cfg)
{
    const ifx_memory_config_t* memory_configs[IFX_REGION_MAX_MPC_COUNT];
    uint32_t                   mpc_cnt = sizeof(memory_configs)/sizeof(memory_configs[0]);
    enum tfm_hal_status_t mem_cfg_res;

    mem_cfg_res = ifx_get_all_memory_configs(memory_configs,
                                             &mpc_cnt,
                                             mpc_reg_cfg->address,
                                             mpc_reg_cfg->size);

    if (mem_cfg_res != TFM_HAL_SUCCESS) {
        FIH_RET(mem_cfg_res);
    }

    for (uint32_t mem_idx = 0; mem_idx < mpc_cnt; mem_idx++) {
        FIH_RET_TYPE(enum tfm_hal_status_t) mem_cfg_res_2;
        ifx_mpc_raw_region_config_t mpc_reg_cfg_raw = {
            .mpc_base       = memory_configs[mem_idx]->mpc,
            .mpc_block_size = memory_configs[mem_idx]->mpc_block_size,
            .offset         = IFX_S_ADDRESS_ALIAS(mpc_reg_cfg->address)
                               - memory_configs[mem_idx]->s_address,
            .size           = mpc_reg_cfg->size,
            .ns_mask        = mpc_reg_cfg->ns_mask,
            .r_mask         = mpc_reg_cfg->r_mask,
            .w_mask         = mpc_reg_cfg->w_mask,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
            .is_rot         = mpc_reg_cfg->is_rot,
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */
        };

        FIH_CALL(ifx_mpc_verify_raw_configuration, mem_cfg_res_2, &mpc_reg_cfg_raw);
        if (FIH_NOT_EQ(mem_cfg_res_2, TFM_HAL_SUCCESS)) {
            FIH_RET(mem_cfg_res_2);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_raw_configuration(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
    FIH_RET_TYPE(enum tfm_hal_status_t) mem_cfg_res;

    /* MPC pointer is set to NULL for MPCs that are not configurable by TFM. */
    if (IFX_MPC_IS_EXTERNAL(mpc_reg_cfg->mpc_base)) {
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
        /* Use external service to verify protection */
        FIH_CALL(ifx_mpc_sert_verify_configuration,
                    mem_cfg_res, mpc_reg_cfg);
        if (FIH_NOT_EQ(mem_cfg_res, TFM_HAL_SUCCESS)) {
            FIH_RET(mem_cfg_res);
        }
#else /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
        FIH_RET(TFM_HAL_ERROR_NOT_SUPPORTED);
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
    } else {
        /* Read MPC directly */
        FIH_CALL(ifx_mpc_verify_configuration_with_mpc,
                    mem_cfg_res, mpc_reg_cfg);
        if (FIH_NOT_EQ(mem_cfg_res, TFM_HAL_SUCCESS)) {
            FIH_RET(mem_cfg_res);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif

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
#include "fih.h"
#include "region_defs.h"
#include "protection_types.h"
#include "protection_utils.h"
#include "protection_regions_cfg.h"
#include "protection_mpc_api.h"
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
#include "protection_mpc_sert.h"
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
#include "region.h"
#include "ifx_platform_mailbox.h"
#include "ifx_regions.h"
#include "ifx_utils.h"
#include "tfm_hal_isolation.h"

#define IFX_MPC_BLOCK_SIZE_TO_BYTES(mpc_size)   (1UL << ((uint32_t)(mpc_size) + 5UL))

#if IFX_MPC_DRIVER_HW_MPC && !IFX_MPC_DRIVER_HW_MPC_WITH_ROT && !IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
#error "IFX_MPC_DRIVER_HW_MPC is defined, but IFX_MPC_DRIVER_HW_MPC_WITH_ROT and IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT are not defined. Please define one or both of them."
#endif

/**
 * \brief Apply MPC configuration for MPC controller handled by TF-M.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_raw_region_config_t for more details.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 */
enum tfm_hal_status_t ifx_mpc_apply_configuration_with_mpc(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    const bool rot_config = mpc_reg_cfg->is_rot;
#elif IFX_MPC_DRIVER_HW_MPC_WITH_ROT
    const bool rot_config = true;
#elif IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    const bool rot_config = false;
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */

    if (rot_config) {
        cy_stc_mpc_rot_cfg_t       mpc_rot_cfg;

        mpc_rot_cfg.addrOffset = mpc_reg_cfg->offset;
        mpc_rot_cfg.size       = mpc_reg_cfg->size;
        mpc_rot_cfg.regionSize = mpc_reg_cfg->mpc_block_size;

        for (uint32_t pc = 0UL; pc < MPC_PC_NR; pc++) {
            mpc_rot_cfg.pc     = (cy_en_mpc_prot_context_t)pc;
            mpc_rot_cfg.secure = ifx_mpc_secure_cfg(mpc_reg_cfg, (cy_en_mpc_prot_context_t)pc);
            mpc_rot_cfg.access = ifx_mpc_access_cfg(mpc_reg_cfg, (cy_en_mpc_prot_context_t)pc);

            if (Cy_Mpc_ConfigRotMpcStruct(mpc_reg_cfg->mpc_base, &mpc_rot_cfg) != CY_MPC_SUCCESS) {
                return TFM_HAL_ERROR_GENERIC;
            }
        }
    } else {
        cy_stc_mpc_cfg_t mpc_no_rot_cfg;
        mpc_no_rot_cfg.addrOffset = mpc_reg_cfg->offset;
        mpc_no_rot_cfg.size       = mpc_reg_cfg->size;
        mpc_no_rot_cfg.regionSize = mpc_reg_cfg->mpc_block_size;
        mpc_no_rot_cfg.secure = (mpc_reg_cfg->ns_mask == 0U) ? CY_MPC_SECURE : CY_MPC_NON_SECURE;
        if (Cy_Mpc_ConfigMpcStruct(mpc_reg_cfg->mpc_base, &mpc_no_rot_cfg) != CY_MPC_SUCCESS) {
            return TFM_HAL_ERROR_GENERIC;
        }
    }

    return TFM_HAL_SUCCESS;
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_configuration_with_mpc(
                                        const ifx_mpc_raw_region_config_t* mpc_reg_cfg)
{
    /* Verify that the MPC is configured as specified */
    for (uint32_t pc = 0U; pc < MPC_PC_NR; pc++) {
        cy_en_mpc_sec_attr_t secure = ifx_mpc_secure_cfg(mpc_reg_cfg,
                                                         (cy_en_mpc_prot_context_t)pc);
        cy_en_mpc_access_attr_t access = ifx_mpc_access_cfg(mpc_reg_cfg,
                                                            (cy_en_mpc_prot_context_t)pc);
        uint32_t block_size      = IFX_MPC_BLOCK_SIZE_TO_BYTES(mpc_reg_cfg->mpc_block_size);
        uint32_t offset          = mpc_reg_cfg->offset;
        uint32_t first_block_idx = offset / block_size;
        uint32_t last_block_idx  = IFX_ROUND_UP_TO_MULTIPLE(offset + mpc_reg_cfg->size, block_size)
                                    / block_size;

        for (uint32_t idx = first_block_idx; idx < last_block_idx; idx++) {
            cy_stc_mpc_rot_block_attr_t mpc_rot_cfg;

            /* Read the block config */
            cy_en_mpc_status_t ret = Cy_Mpc_GetRotBlockAttr(mpc_reg_cfg->mpc_base,
                                                            (cy_en_mpc_prot_context_t)pc,
                                                            idx,
                                                            &mpc_rot_cfg);

            /* Check that it is as expected */
            if ((ret != CY_MPC_SUCCESS)  ||
                (mpc_rot_cfg.secure != secure)  ||
                (mpc_rot_cfg.access != access)) {

                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_init_cfg(void)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, mpc_result, TFM_HAL_ERROR_BAD_STATE);

    /* Populate ifx_fixed_mpc_static_config[] */
    FIH_CALL(ifx_mpc_fill_fixed_config, mpc_result);
    if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
        FIH_RET(mpc_result);
    }

#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
    FIH_CALL(ifx_mpc_sert_init, mpc_result);
    if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
        FIH_RET(mpc_result);
    }
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */

    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

#ifdef IFX_MEMORY_CONFIGURATOR_MPC_CONFIG
    /* Apply predefined static MPC configuration for memory regions generated by TZ Configurator */
    for (uint32_t idx = 0UL; idx < cy_mpc_unified_config_count; idx++) {
        if (!IFX_MPC_IS_EXTERNAL(cy_mpc_unified_config[idx].base)) {
            uint32_t response = cy_mpc_unified_config[idx].response ? 1u : 0u;
            cy_mpc_unified_config[idx].base->CFG = _VAL2FLD(RAMC_MPC_CFG_RESPONSE, response);
        }

        for (uint32_t jdx = 0UL; jdx < cy_mpc_unified_config[idx].size; jdx++) {
            ifx_mpc_raw_region_config_t mpc_cfg = {
                .mpc_base       = cy_mpc_unified_config[idx].base,
                .mpc_block_size = cy_mpc_unified_config[idx].regionSize,
                .offset         = cy_mpc_unified_config[idx].config[jdx].offset,
                .size           = cy_mpc_unified_config[idx].config[jdx].size,
                .ns_mask        = cy_mpc_unified_config[idx].config[jdx].ns_mask,
                .r_mask         = cy_mpc_unified_config[idx].config[jdx].r_mask,
                .w_mask         = cy_mpc_unified_config[idx].config[jdx].w_mask,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
                .is_rot         = true,
#endif
            };

            FIH_CALL(ifx_mpc_apply_raw_configuration, mpc_result, &mpc_cfg);
            if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
                FIH_RET(mpc_result);
            }
        }
    }

#if defined(TFM_FIH_PROFILE_ON)
    /*
     * Some of the configs in cy_mpc_unified_config[] will be partially overridden
     * by configs in ifx_fixed_mpc_static_config[], which means that verify
     * of these partially-overwritten configs will fail if done after we
     * apply those in ifx_fixed_mpc_static_config[]. So verify these ones now
     */
    for (uint32_t idx = 0UL; idx < cy_mpc_unified_config_count; idx++) {
        for (uint32_t jdx = 0UL; jdx < cy_mpc_unified_config[idx].size; jdx++) {
            ifx_mpc_raw_region_config_t mpc_cfg = {
                .mpc_base       = cy_mpc_unified_config[idx].base,
                .mpc_block_size = cy_mpc_unified_config[idx].regionSize,
                .offset         = cy_mpc_unified_config[idx].config[jdx].offset,
                .size           = cy_mpc_unified_config[idx].config[jdx].size,
                .ns_mask        = cy_mpc_unified_config[idx].config[jdx].ns_mask,
                .r_mask         = cy_mpc_unified_config[idx].config[jdx].r_mask,
                .w_mask         = cy_mpc_unified_config[idx].config[jdx].w_mask,
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
                .is_rot         = true,
#endif
            };

            FIH_CALL(ifx_mpc_verify_raw_configuration, mpc_result, &mpc_cfg);
            if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
                FIH_RET(mpc_result);
            }
        }
    }
#endif /* defined(TFM_FIH_PROFILE_ON) */
#else /* IFX_MEMORY_CONFIGURATOR_MPC_CONFIG */
    /* Set violation response for all used memory types */
    for (uint32_t idx = 0UL; idx < ifx_memory_cm33_config_count; idx++) {
        /* Some MPCs are not controlled by TFM so the MPC pointer is set to NULL */
        if (!IFX_MPC_IS_EXTERNAL(ifx_memory_cm33_config[idx]->mpc)) {
            /* Set violation response as Bus Error instead RZWI */
            ifx_memory_cm33_config[idx]->mpc->CFG = _VAL2FLD(RAMC_MPC_CFG_RESPONSE, 1);
        }
    }

#if IFX_MPC_CM55_MPC
    for (uint32_t idx = 0UL; idx < ifx_memory_cm55_config_count; idx++) {
        /* Some MPCs are not controlled by TFM so the MPC pointer is set to NULL */
        if (!IFX_MPC_IS_EXTERNAL(ifx_memory_cm55_config[idx]->mpc)) {
            /* Set violation response as Bus Error instead RZWI */
            ifx_memory_cm55_config[idx]->mpc->CFG = _VAL2FLD(RAMC_MPC_CFG_RESPONSE, 1);
        }
    }
#endif /* IFX_MPC_CM55_MPC */

    /* Apply predefined static MPC configuration for memory regions */
    for (uint32_t idx = 0UL; idx < ifx_mpc_static_config_count; idx++) {
        FIH_CALL(ifx_mpc_apply_configuration, mpc_result,
                 &ifx_mpc_static_config[idx]);
        if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
            FIH_RET(mpc_result);
        }
    }

#if defined(TFM_FIH_PROFILE_ON)
    /*
     * Some of the configs in ifx_mpc_static_config[] will be partially overridden
     * by configs in ifx_fixed_mpc_static_config[], which means that verify
     * of these partially-overwritten configs will fail if done after we
     * apply those in ifx_fixed_mpc_static_config[]. So verify these ones now
     */

    for (uint32_t idx = 0UL; idx < ifx_mpc_static_config_count; idx++) {
        FIH_RET_TYPE(enum tfm_hal_status_t) ret;

        FIH_CALL(ifx_mpc_verify_configuration, ret, &ifx_mpc_static_config[idx]);
        if (FIH_NOT_EQ(ret, TFM_HAL_SUCCESS)) {
            FIH_RET(ret);
        }
    }
#endif /* defined(TFM_FIH_PROFILE_ON) */
#endif /* IFX_MEMORY_CONFIGURATOR_MPC_CONFIG */

    for (uint32_t idx = 0UL; idx < ifx_fixed_mpc_static_config_count; idx++) {
        FIH_CALL(ifx_mpc_apply_configuration, mpc_result,
                 &ifx_fixed_mpc_static_config[idx]);
        if (FIH_NOT_EQ(mpc_result, TFM_HAL_SUCCESS)) {
            FIH_RET(mpc_result);
        }
    }

    /* Add barriers to assure the MPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_static_boundaries(void)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, ret, TFM_HAL_ERROR_GENERIC);

    /* Populate ifx_fixed_mpc_static_config[] again, in case of fault injection */
    FIH_CALL(ifx_mpc_fill_fixed_config, ret);
    if (FIH_NOT_EQ(ret, TFM_HAL_SUCCESS)) {
        FIH_RET(ret);
    }

#ifdef IFX_MEMORY_CONFIGURATOR_MPC_CONFIG
    /* Check violation response provided by Device Configurator */
    for (uint32_t idx = 0UL; idx < cy_mpc_unified_config_count; idx++) {
        if (!IFX_MPC_IS_EXTERNAL(cy_mpc_unified_config[idx].base))) {
            uint32_t response = cy_mpc_unified_config[idx].response ? 1u : 0u;
            if (_FLD2VAL(RAMC_MPC_CFG_RESPONSE,
                         cy_mpc_unified_config[idx].base->CFG) != response) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
        }
    }
#else
    /* Check violation response for all used memory types */
    for (uint32_t idx = 0UL; idx < ifx_memory_cm33_config_count; idx++) {
        /* Some MPCs are not controlled by TFM so the MPC pointer is set to NULL */
        if (!IFX_MPC_IS_EXTERNAL(ifx_memory_cm33_config[idx]->mpc)) {
            /* Read back violation response, should be Bus Error */
            if (_FLD2VAL(RAMC_MPC_CFG_RESPONSE, ifx_memory_cm33_config[idx]->mpc->CFG) != 1u) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
        }
    }

#if IFX_MPC_CM55_MPC
    for (uint32_t idx = 0UL; idx < ifx_memory_cm55_config_count; idx++) {
        /* Some MPCs are not controlled by TFM so the MPC pointer is set to NULL */
        if (!IFX_MPC_IS_EXTERNAL(ifx_memory_cm55_config[idx]->mpc)) {
            /* Read back violation response, should be Bus Error */
            if (_FLD2VAL(RAMC_MPC_CFG_RESPONSE, ifx_memory_cm55_config[idx]->mpc->CFG) != 1u) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
        }
    }
#endif /* IFX_MPC_CM55_MPC */
#endif /* IFX_MEMORY_CONFIGURATOR_MPC_CONFIG */

    /*
     * Some of the configs in ifx_mpc_static_config[] are partially overridden
     * by configs in ifx_fixed_mpc_static_config[], which means that verify
     * of these partially-overwritten configs will fail if done after we
     * apply those in ifx_fixed_mpc_static_config[]. So we verified those ones
     * immediately after applying them instead.
     */

    for (uint32_t idx = 0UL; idx < ifx_fixed_mpc_static_config_count; idx++) {
        FIH_CALL(ifx_mpc_verify_configuration, ret, &ifx_fixed_mpc_static_config[idx]);
        if (FIH_NOT_EQ(ret, TFM_HAL_SUCCESS)) {
            FIH_RET(ret);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_memory_check(const struct ifx_partition_info_t *p_info,
                                                         uintptr_t base,
                                                         size_t size,
                                                         uint32_t access_type)
{
    const ifx_memory_config_t* mem_region_cfg;
#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
    const ifx_memory_config_t* mem_region_cfg2;
#endif

#if CONFIG_TFM_PSA_CALL_ADDRESS_REMAP
    bool is_ns_cpu_internal_memory =
#if defined(TFM_PARTITION_NS_AGENT_MAILBOX)
                            ((IS_NS_AGENT_MAILBOX(p_info->p_ldinfo))
                             && ifx_is_ns_cpu_internal_memory(base, size)) ||
#elif IFX_MTB_MAILBOX
                            ((IS_NS_AGENT_TZ(p_info->p_ldinfo))
                             && ifx_is_ns_cpu_internal_memory_remapped(base, size)) ||
#endif /* defined(TFM_PARTITION_NS_AGENT_MAILBOX) */
                            false;

#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
    (void)fih_delay();

    bool is_ns_cpu_internal_memory2 =
#if defined(TFM_PARTITION_NS_AGENT_MAILBOX)
                            ((IS_NS_AGENT_MAILBOX(p_info->p_ldinfo))
                             && ifx_is_ns_cpu_internal_memory(base, size)) ||
#elif IFX_MTB_MAILBOX
                            ((IS_NS_AGENT_TZ(p_info->p_ldinfo))
                             && ifx_is_ns_cpu_internal_memory_remapped(base, size)) ||
#endif /* defined(TFM_PARTITION_NS_AGENT_MAILBOX) */
                            false;

    if (is_ns_cpu_internal_memory != is_ns_cpu_internal_memory2) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }
#endif /* defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW) */

    if (is_ns_cpu_internal_memory) {
        FIH_RET(TFM_HAL_SUCCESS);
    }
#endif /* CONFIG_TFM_PSA_CALL_ADDRESS_REMAP */

    /* CM33 memory list is a comprehensive list of memory regions for the
     * device, protections applied to other memory lists are also applied to CM33
     * memory list so checking only CM 33 list is enough. */
    mem_region_cfg = ifx_find_memory_config(base, size,
                                            ifx_memory_cm33_config,
                                            ifx_memory_cm33_config_count);

#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
    (void)fih_delay();
    mem_region_cfg2 = ifx_find_memory_config(base, size,
                                            ifx_memory_cm33_config,
                                            ifx_memory_cm33_config_count);
    if (mem_region_cfg != mem_region_cfg2) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }
#endif

    if (mem_region_cfg == NULL) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    uint32_t block_size      = IFX_MPC_BLOCK_SIZE_TO_BYTES(mem_region_cfg->mpc_block_size);
    uint32_t offset          = IFX_S_ADDRESS_ALIAS(base) - mem_region_cfg->s_address;
    uint32_t first_block_idx = offset / block_size;
    uint32_t last_block_idx  = IFX_ROUND_UP_TO_MULTIPLE(offset + size, block_size) / block_size;
    IFX_FIH_BOOL is_secure = ((access_type & TFM_HAL_ACCESS_NS) == 0U) ? IFX_FIH_TRUE : IFX_FIH_FALSE;
    fih_int pc               = FIH_INVALID_VALUE;

    pc = IFX_GET_PARTITION_PC(p_info, IFX_FIH_EQ(is_secure, IFX_FIH_TRUE));
    fih_int_validate(pc);

    cy_en_mpc_sec_attr_t expected_sec_attr = (IS_NS_AGENT(p_info->p_ldinfo) && IFX_FIH_EQ(is_secure, IFX_FIH_FALSE)) ? CY_MPC_NON_SECURE : CY_MPC_SECURE;

#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
    (void)fih_delay();
    volatile uint32_t access_type_2 = access_type;
    IFX_FIH_BOOL is_secure2 = ((access_type_2 & TFM_HAL_ACCESS_NS) == 0U) ? IFX_FIH_TRUE : IFX_FIH_FALSE;
    if (!IFX_FIH_EQ(is_secure, is_secure2)) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }

    volatile uint32_t validated_block_count = 0;
#endif

    if (IFX_MPC_IS_EXTERNAL(mem_region_cfg->mpc)) {
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
        FIH_RET_TYPE(enum tfm_hal_status_t) ret;
        FIH_CALL(ifx_mpc_sert_memory_check,
                ret, p_info, mem_region_cfg, base, size, access_type);
        FIH_RET(ret);
#else /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
        /* If MPC is not controlled by TFM neither by SE RT Services
         * then the assumption is that partition has no access to it */
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
#endif /* IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE */
    }

#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    const bool rot_config = mem_region_cfg->is_rot;
#elif IFX_MPC_DRIVER_HW_MPC_WITH_ROT
    const bool rot_config = true;
#elif IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    const bool rot_config = false;
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */

    for (uint32_t idx = first_block_idx; idx < last_block_idx; idx++) {
        cy_stc_mpc_rot_block_attr_t mpc_settings;
        cy_stc_mpc_block_attr_t mpc_settings_no_rot;

        if (rot_config) {
            if (Cy_Mpc_GetRotBlockAttr(mem_region_cfg->mpc,
                                       (cy_en_mpc_prot_context_t)fih_int_decode(pc),
                                       idx,
                                       &mpc_settings) != CY_MPC_SUCCESS) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        } else {
            if (Cy_Mpc_GetBlockAttr(mem_region_cfg->mpc,
                                    idx,
                                    &mpc_settings_no_rot) != CY_MPC_SUCCESS) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        }

#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
        (void)fih_delay();

        if (rot_config) {
            cy_stc_mpc_rot_block_attr_t mpc_settings2;
            if (Cy_Mpc_GetRotBlockAttr(mem_region_cfg->mpc,
                                       (cy_en_mpc_prot_context_t)fih_int_decode(pc),
                                       idx,
                                       &mpc_settings2) != CY_MPC_SUCCESS) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }

            (void)fih_delay();
            if ((mpc_settings.access != mpc_settings2.access) ||
                (mpc_settings.secure != mpc_settings2.secure)) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        } else {
            cy_stc_mpc_block_attr_t mpc_settings_no_rot2;
            if (Cy_Mpc_GetBlockAttr(mem_region_cfg->mpc,
                                    idx,
                                    &mpc_settings_no_rot2) != CY_MPC_SUCCESS) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }

            (void)fih_delay();
            if (mpc_settings_no_rot.secure != mpc_settings_no_rot2.secure) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        }

        (void)fih_delay();
        validated_block_count++;
#endif /* defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW) */

        if (rot_config) {
            if (mpc_settings.secure != expected_sec_attr) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }

            /* If MPC has RW access then any (R, W, RW) access is allowed, so no
             * need for additional checks. */
            if (mpc_settings.access == CY_MPC_ACCESS_RW) {
                continue;
            }

            if (((access_type & TFM_HAL_ACCESS_READABLE) != 0U) &&
                (mpc_settings.access != CY_MPC_ACCESS_R)) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }

            if (((access_type & TFM_HAL_ACCESS_WRITABLE) != 0U) &&
                (mpc_settings.access != CY_MPC_ACCESS_W)) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        } else {
            if (mpc_settings_no_rot.secure != expected_sec_attr) {
                FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
            }
        }
    }

#if defined(TFM_FIH_PROFILE_ON) && !defined(TFM_FIH_PROFILE_LOW)
    (void)fih_delay();
    if (validated_block_count != (last_block_idx - first_block_idx)) {
        FIH_RET(TFM_HAL_ERROR_MEM_FAULT);
    }
#endif

    FIH_RET(TFM_HAL_SUCCESS);
}

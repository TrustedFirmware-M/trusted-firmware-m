/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <arm_cmse.h>
#include "cmsis.h"
#include "config_tfm.h"
#include "faults.h"
#include "protection_types.h"
#if IFX_PLATFORM_MPC_PRESENT
#include "protection_mpc_api.h"
#endif
#include "protection_mpu.h"
#include "protection_msc.h"
#if IFX_PLATFORM_PPC_PRESENT
#include "protection_ppc_api.h"
#endif
#include "protection_sau.h"
#if IFX_ISOLATION_PC_SWITCHING
#include "protection_pc.h"
#endif
#include "protection_tz.h"
#include "partition_info.h"
#include "ifx_regions.h"
#include "tfm_hal_isolation.h"
#include "ifx_tfm_log_shim.h"
#include "tfm_peripherals_def.h"
#include "load/spm_load_api.h"
#include "load/asset_defs.h"
#include "protection_shared_data.h"
#include "protection_utils.h"
#include "ifx_spm_init.h"
#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
#include "ifx_se_ipc_service_spm.h"
#endif

/*
 * Last partition boundary that has been activated. May not be equal to current partition boundary,
 * if such partitions shares same security domain.
 * It's initialized with SPM boundary, because it's a default state on the TF-M boot.
 */
static uintptr_t active_boundary        = IFX_SPM_BOUNDARY;

#if TFM_ISOLATION_LEVEL == 3
ifx_asset_protection_type_t ifx_asset_protection_type = IFX_ASSET_PROTECTION_STATIC;
#endif /* TFM_ISOLATION_LEVEL == 3 */

/**
 * \brief Configures the PPCfor the given named MMIO.
 *
 * \param[in] cfg      Pointer to the configuration settings.
 * \param[in] asset    The named MMIO asset to be protected.
 *
 * \return Returns a status code of type `enum tfm_hal_status_t` indicating
 *         the success or failure of the operation.
 */
static FIH_RET_TYPE(enum tfm_hal_status_t) ifx_apply_ppc_assets_raw(const ifx_protection_region_config_t *cfg,
                                                                    cy_en_prot_region_t asset)
{
#if IFX_PLATFORM_PPC_PRESENT
    FIH_RET_TYPE(enum tfm_hal_status_t) result;

    /* PPC asset protection */
    /* Named MMIO is not used by platform code, skip protection */
    if (asset == ((cy_en_prot_region_t)IFX_UNUSED_MMIO)) {
        FIH_RET(TFM_HAL_SUCCESS);
    }

#if TFM_ISOLATION_LEVEL == 3
    /* Apply PPC isolation for L3 if:
     * 1. For static initialization:
     *   1.1. ifx_asset_protection_type == IFX_ASSET_PROTECTION_STATIC
     *   1.2. ifx_asset_protection_type == IFX_ASSET_PROTECTION_PARTITION_STATIC
     * 2. For dynamic switch if ppc_dynamic is enabled */
    IFX_FIH_BOOL ppc_isolation =
            ((ifx_asset_protection_type != IFX_ASSET_PROTECTION_PARTITION_DYNAMIC) ||
            cfg->ppc_dynamic) ? IFX_FIH_TRUE : IFX_FIH_FALSE;
#else
    IFX_FIH_BOOL ppc_isolation = IFX_FIH_TRUE;
#endif /* TFM_ISOLATION_LEVEL == 3) */

    if (IFX_FIH_EQ(ppc_isolation, IFX_FIH_TRUE)) {
        /* Protect named MMIO asset via PPC */
        FIH_CALL(ifx_ppc_isolate_named_mmio, result, &cfg->ppc_cfg, asset);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
#else /* IFX_PLATFORM_PPC_PRESENT */
    /* PPC is not supported */
    FIH_RET(TFM_HAL_ERROR_NOT_SUPPORTED);
#endif /* IFX_PLATFORM_PPC_PRESENT */
}

/**
 * \brief Apply a configuration to specified assets of a partition.
 *
 * \param[in]   p_info      Pointer to partition info \ref ifx_partition_info_t
 * \param[in]   cfg         Pointer to configuration \ref ifx_protection_region_config_t
 * \param[in]   p_assets    Array of partition's assets
 * \param[in]   asset_cnt   Number of items in \ref p_assets
 *
 * \return  TFM_HAL_SUCCESS       - config successfully updated
 *          TFM_HAL_ERROR_GENERIC - failed to apply config
 *          TFM_HAL_ERROR_INVALID_INPUT - invalid parameter
 */
static FIH_RET_TYPE(enum tfm_hal_status_t) ifx_apply_assets(const ifx_partition_info_t *p_info,
                                              const ifx_protection_region_config_t *cfg,
                                              const struct asset_desc_t *p_assets,
                                              uint32_t asset_cnt)
{
    size_t  asset_idx;
    FIH_RET_TYPE(enum tfm_hal_status_t) result;

    if ((p_info == NULL) || (cfg == NULL)) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    for (asset_idx = 0; asset_idx < asset_cnt; asset_idx++) {
        if ((p_assets[asset_idx].attr & ASSET_ATTR_NAMED_MMIO) != 0u) {
            /* ASSET_ATTR_NAMED_MMIO for IFX devicec is a peripheral.
             * Peripheral assets for IFX devices in manifest files must use
             * ("name": value from enum \ref cy_en_prot_region_t) and
             * ("type": ASSET_ATTR_NAMED_MMIO) */

            if ((p_assets[asset_idx].attr & ASSET_ATTR_READ_WRITE) == 0U) {
                /* PPC only supports RW access to peripherals. */
                FIH_RET(TFM_HAL_ERROR_NOT_SUPPORTED);
            }

            FIH_CALL(ifx_apply_ppc_assets_raw,
                     result,
                     cfg,
                     (cy_en_prot_region_t)p_assets[asset_idx].mem.start);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }
        } else {
            /* Assets without any MMIO attribute or with ASSET_ATTR_NUMBERED_MMIO
             * attribute are treated as memory based assets. Such assets can be
             * used to assign memory area to a partition. */
            if (((p_assets[asset_idx].attr & ASSET_ATTR_READ_ONLY)  != 0U) ==
                ((p_assets[asset_idx].attr & ASSET_ATTR_READ_WRITE) != 0U)) {
                /* Error out if neither or both RO/WR attributes are set.
                 * Only one RO or RW attribute must be set. */
                FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
            }

    /* 1. If IFX_MPC_CONFIGURED_BY_TFM is OFF then TFM can not configure MPC, so
     * skip call to ifx_mpc_isolate_numbered_mmio
     * 2. If IFX_ISOLATION_PC_SWITCHING is OFF the assumption is that default PC
     * has secure RW access to whole memory, thus call to ifx_mpc_isolate_numbered_mmio
     * can be skipped. This way special MPC block alignments can be removed,
     * saving some memory. Also this improves run time performance */
#if IFX_MPC_CONFIGURED_BY_TFM && IFX_ISOLATION_PC_SWITCHING
#if TFM_ISOLATION_LEVEL == 3
            /* Apply MPC isolation for L3 if:
             * 1. For static initialization:
             *   1.1. ifx_asset_protection_type == IFX_ASSET_PROTECTION_STATIC
             *   1.2. ifx_asset_protection_type == IFX_ASSET_PROTECTION_PARTITION_STATIC
             * 2. For dynamic switch if mpc_dynamic is enabled */
            IFX_FIH_BOOL mpc_isolation =
                    ((ifx_asset_protection_type != IFX_ASSET_PROTECTION_PARTITION_DYNAMIC) ||
                    cfg->mpc_dynamic) ? IFX_FIH_TRUE : IFX_FIH_FALSE;
#else
            IFX_FIH_BOOL mpc_isolation = IFX_FIH_TRUE;
#endif /* TFM_ISOLATION_LEVEL == 3) */
            if (IFX_FIH_EQ(mpc_isolation, IFX_FIH_TRUE)) {
                /* MPC asset protection */
                FIH_CALL(ifx_mpc_isolate_numbered_mmio,
                         result,
                         &cfg->mpc_cfg,
                         &p_assets[asset_idx]);
                if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                    FIH_RET(result);
                }
            }
#endif /* IFX_MPC_CONFIGURED_BY_TFM && IFX_ISOLATION_PC_SWITCHING  */

            /* MPU asset protection */
            if (IFX_FIH_EQ(cfg->mpu_regions_enable, IFX_FIH_TRUE)) {
                FIH_CALL(ifx_mpu_isolate_numbered_mmio, result, p_info, &p_assets[asset_idx]);
                if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                    FIH_RET(result);
                }
            }
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

/**
 * \brief Apply a configuration to assets of a partition.
 *
 * \param[in]   p_info      Pointer to partition info \ref ifx_partition_info_t
 * \param[in]   cfg         Pointer to configuration \ref ifx_protection_region_config_t
 *
 * \return  TFM_HAL_SUCCESS       - config successfully updated
 *          TFM_HAL_ERROR_GENERIC - failed to apply config
 *          TFM_HAL_ERROR_INVALID_INPUT - invalid parameter
 */
static FIH_RET_TYPE(enum tfm_hal_status_t) ifx_protect_partition_assets(
                                              const ifx_partition_info_t *p_info,
                                              const ifx_protection_region_config_t *cfg)
{
    FIH_RET_TYPE(enum tfm_hal_status_t) result;

    if ((p_info == NULL) || (cfg == NULL)) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    /* Apply partition assets generated with partition load info */
    const struct partition_load_info_t *p_ldinf = p_info->p_ldinfo;
    if (p_ldinf->nassets != 0U) {
        const struct asset_desc_t *p_assets = LOAD_INFO_ASSET(p_ldinf);
        FIH_CALL(ifx_apply_assets, result, p_info, cfg, p_assets, p_ldinf->nassets);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }
    }

    /* Apply platform specific partition assets */
    if (p_info->asset_cnt != 0U) {
        FIH_CALL(ifx_apply_assets, result, p_info, cfg,
                                 p_info->p_assets, p_info->asset_cnt);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }
    }

#ifdef IFX_MEMORY_CONFIGURATOR_MPC_CONFIG
    /* Apply MPC domain settings provided by Device Configurator */
    if (p_info->p_mem_cfg != NULL) {
        const ifx_mem_domain_cfg_t *p_mem_cfg = p_info->p_mem_cfg;
        for (uint32_t i = 0; i < p_mem_cfg->region_count; i++) {
            const ifx_mem_domain_region_cfg_t *p_region = &p_mem_cfg->regions[i];
            /* Skip empty region */
            if (p_region->size == 0UL) {
                continue;
            }

            /* Convert platform specific memory configuration to TF-M asset structure */
            struct asset_desc_t asset = {0};
            bool valid = true;
            FIH_CALL(ifx_domain_mem_get_asset, result, p_region, &asset, &valid);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }

            /* Skip duplicate region if needed */
            if (!valid) {
                continue;
            }

            /* Apply protection */
            FIH_CALL(ifx_apply_assets, result, p_info, cfg, &asset, 1);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }
        }
    }
#endif /* IFX_MEMORY_CONFIGURATOR_MPC_CONFIG */

    /* Domain PPC regions generated by Edge Protect Configurator */
    for (uint32_t i = 0; i < p_info->peri_region_count; i++) {
        for (uint32_t j = 0; j < p_info->p_peri_regions[i].region_count; j++) {
            FIH_CALL(ifx_apply_ppc_assets_raw, result, cfg, p_info->p_peri_regions[i].regions[j]);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_set_up_static_boundaries(uintptr_t *p_spm_boundary)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);
    IFX_FIH_DECLARE(enum tfm_plat_err_t, plat_fih_rc, TFM_PLAT_ERR_SYSTEM_ERR);
    *p_spm_boundary = IFX_SPM_BOUNDARY;

#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
    /* Shutdown SE RT Services Utils before changing clocks */
    if (ifx_se_ipc_service_spm_shutdown() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
#endif

    /* Currently tfm_hal_set_up_static_boundaries is the first platform function
     * which is called by TF-M core. So, ifx_init_spm_peripherals is called
     * here to setup peripherals used by SPM (e.g. UART used by SPM Log) as
     * soon as possible. */
    ifx_init_spm_peripherals();

    /* Fault configuration must be performed as soon after TFM start
     * as possible to distinguish Faults occurred in TFM and before.
     * Initialize it right after SPM UART is ready. */
    FIH_CALL(ifx_faults_cfg, plat_fih_rc);
    if (FIH_NOT_EQ(plat_fih_rc, TFM_PLAT_ERR_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    INFO_RAW("\nTF-M setup static boundaries\n");

#if IFX_ISOLATION_PC_SWITCHING
    FIH_CALL(ifx_pc_init, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
#endif /* IFX_ISOLATION_PC_SWITCHING */

    FIH_CALL(ifx_msc_cfg, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    FIH_CALL(ifx_sau_cfg, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    FIH_CALL(ifx_mpu_init_cfg, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

#if IFX_SE_IPC_SERVICE_FULL || IFX_SE_IPC_SERVICE_BASE
    /* This allows SPM to use SE RT Services Utils for additional setup */
    if (ifx_se_ipc_service_spm_init() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
#endif

    FIH_CALL(ifx_ppc_init_cfg, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    FIH_CALL(ifx_mpc_init_cfg, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    /* IDAU is implemented fully in hardware and have no software
     * parameters or registers to change Thus it can't be configured */

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
fih_ret tfm_hal_verify_static_boundaries(void)
{
    FIH_DECLARE(fih_rc, TFM_HAL_ERROR_GENERIC);

#if IFX_ISOLATION_PC_SWITCHING
    FIH_CALL(ifx_pc_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }
#endif /* IFX_ISOLATION_PC_SWITCHING */

    FIH_CALL(ifx_msc_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(ifx_sau_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(ifx_mpu_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(ifx_mpc_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_CALL(ifx_ppc_verify_static_boundaries, fih_rc);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    FIH_RET(fih_rc);
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(uintptr_t boundary, uintptr_t base,
                                           size_t size, uint32_t access_type)
{
    const ifx_partition_info_t *p_info = (const ifx_partition_info_t *)boundary;
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);

#if TFM_ISOLATION_LEVEL > 1
    /* This function must check access for current partition only.
     * We can ensure that active isolation settings is valid for partition if
     * partition has same secure domain that has been activated.
     * Because tfm_hal_boundary_need_switch allows to skip tfm_hal_activate_boundary. */
    uintptr_t active_domain = IFX_GET_BOUNDARY_DOMAIN(active_boundary);
    if (p_info->ifx_domain != active_domain) {
        tfm_core_panic();
    }
#endif

    /* If size is zero, this indicates an empty buffer and base is ignored */
    if (size == 0U) {
        FIH_RET(TFM_HAL_SUCCESS);
    }

    if (base == 0U) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    /* Check for overflow in the range parameters */
    if (base > (UINTPTR_MAX - size)) {
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    /* Only TFM_HAL_ACCESS_READABLE, TFM_HAL_ACCESS_WRITABLE and TFM_HAL_ACCESS_NS are used by TFM */
    if ((access_type & ~(TFM_HAL_ACCESS_READABLE
                         | TFM_HAL_ACCESS_WRITABLE
                         | TFM_HAL_ACCESS_NS)) != 0U) {
        tfm_core_panic();
    }

    /* Check SAU, IDAU, MPU access */
    FIH_CALL(ifx_tz_memory_check, fih_rc, p_info, base, size, access_type);
    if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    /* Check MPC access */
    FIH_CALL(ifx_mpc_memory_check, fih_rc, p_info, base, size, access_type);
    FIH_RET(fih_rc);
}

/*
 * Implementation of tfm_hal_bind_boundary() on IFX devices:
 *
 * For all TFM_ISOLATION_LEVEL:
 *  - Set unique handle for each partition. Partition ifx_partition_info_t is set
 *    as partition boundary handle to allow to easily access partition
 *    information when boundary handle is provided.
 *
 * For TFM_ISOLATION_LEVEL 1 (L1 uses static protection settings):
 *  - Allow partition to access its assets.
 *
 * For TFM_ISOLATION_LEVEL 2 (L2 uses static protection settings):
 *  - Boundaries update will be performed only when switching between partitions
 *    with different types: from ARoT to PRoT or vice versa.
 *  - Allow partition to access its assets.
 *
 * For TFM_ISOLATION_LEVEL 3 (L3 uses dynamic protection settings):
 *  - Boundaries update will be performed when switching between any partitions.
 *  - Ban access to partition assets. Access to partition assets will be granted
 *    during boundaries update.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_bind_boundary(const struct partition_load_info_t *p_ldinf,
                                            uintptr_t *p_boundary)
{
    FIH_RET_TYPE(enum tfm_hal_status_t) result;

    if ((p_ldinf == NULL) || (p_boundary == NULL)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    /* Platform specific partition properties used to get PC, privilege, additional assets, etc */
    const ifx_partition_info_t *p_info = ifx_protection_get_partition_info(p_ldinf);
    *p_boundary = (uintptr_t)p_info;

#if TFM_ISOLATION_LEVEL == 3
    if (p_info->ifx_domain == IFX_PROTECT_SPM_DOMAIN) {
        /* Enable partition's assets for partition that uses static isolation */
        ifx_asset_protection_type = IFX_ASSET_PROTECTION_STATIC;
        FIH_CALL(ifx_protect_partition_assets,
                 result,
                 p_info,
                 p_info->ifx_ldinfo->protect_cfg_enabled);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }
    } else {
        /* Enable partition's assets that can't be managed dynamically */
        ifx_asset_protection_type = IFX_ASSET_PROTECTION_PARTITION_STATIC;
        FIH_CALL(ifx_protect_partition_assets,
                 result,
                 p_info,
                 p_info->ifx_ldinfo->protect_cfg_enabled);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }

        /* Disable partition's assets that can be managed dynamically.
         * Such assets are enabled before running partition and disabled during suspend. */
        ifx_asset_protection_type = IFX_ASSET_PROTECTION_PARTITION_DYNAMIC;
        FIH_CALL(ifx_protect_partition_assets,
                 result,
                 p_info,
                 p_info->ifx_ldinfo->protect_cfg_disabled);
        if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
            FIH_RET(result);
        }
    }
#else
    /* Apply static configuration to partition's assets on L1/L2 */
    FIH_CALL(ifx_protect_partition_assets,
             result,
             p_info,
             p_info->ifx_ldinfo->protect_cfg_enabled);
    if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
        FIH_RET(result);
    }
#endif

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_post_partition_init_hook(void)
{
    /* Call API to ensure that shared metadata section is RW accessible before
     * changing it. Do this only if CONFIG_TFM_PARTITION_META is enabled.
     * Otherwise (in Isolation Level 1) data from this section will be in normal
     * TFM section which is everyone accessible as it is Isolation Level 1 anyway. */
#ifdef CONFIG_TFM_PARTITION_META
    tfm_hal_shared_metadata_rw_enable(true);
#endif /* CONFIG_TFM_PARTITION_META */

    /* Scheduler is about to be running */
    ifx_spm_state = IFX_SPM_STATE_RUNNING;

    /* Call API to ensure that shared metadata section is RO accessible after
     * changing it. Do this only if CONFIG_TFM_PARTITION_META is enabled.
     * Otherwise (in Isolation Level 1) data from this section will be in normal
     * TFM section which is everyone accessible as it is Isolation Level 1 anyway. */
#ifdef CONFIG_TFM_PARTITION_META
    tfm_hal_shared_metadata_rw_enable(false);
#endif /* CONFIG_TFM_PARTITION_META */

#if TFM_ISOLATION_LEVEL == 3
    /* Start dynamic isolation of partition's assets */
    ifx_asset_protection_type = IFX_ASSET_PROTECTION_PARTITION_DYNAMIC;
#endif /* TFM_ISOLATION_LEVEL == 3 */

#if (IFX_SE_IPC_SERVICE_FULL && !defined(IFX_PARTITION_SE_IPC_SERVICE)) || IFX_SE_IPC_SERVICE_BASE
    /* Shutdown SE IPC Service because it shouldn't be used anymore */
    if (ifx_se_ipc_service_spm_shutdown() != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
#endif

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef CONFIG_TFM_PARTITION_META
void tfm_hal_shared_metadata_rw_enable(bool enable)
{
    /* Use MPU to apply proper protections for shared metadata section */
    ifx_mpu_shared_metadata_rw_enable(enable);
}
#endif /* CONFIG_TFM_PARTITION_META */

FIH_RET_TYPE(bool) tfm_hal_boundary_need_switch(uintptr_t boundary_from, uintptr_t boundary_to)
{
#if TFM_ISOLATION_LEVEL > 1
    uintptr_t domain_from = IFX_PROTECT_SPM_DOMAIN;
    /* If boundary is not SPM boundary then it is partition boundary
     * thus domain is taken from partition info structure */
    if (boundary_from != IFX_SPM_BOUNDARY) {
        const ifx_partition_info_t *p_info_from = (const ifx_partition_info_t *)boundary_from;
        domain_from = p_info_from->ifx_domain;
    }

    uintptr_t domain_to = IFX_PROTECT_SPM_DOMAIN;
    /* If boundary is not SPM boundary then it is partition boundary
     * thus domain is taken from partition info structure */
    if (boundary_to != IFX_SPM_BOUNDARY) {
        const ifx_partition_info_t *p_info_to = (const ifx_partition_info_t *)boundary_to;
        domain_to = p_info_to->ifx_domain;
    }

    FIH_RET(domain_from != domain_to);
#else /* TFM_ISOLATION_LEVEL > 1 */
    FIH_RET(false);
#endif /* TFM_ISOLATION_LEVEL > 1 */
}

/*
 * Implementation of tfm_hal_activate_boundary() on IFX devices:
 *
 * For TFM_ISOLATION_LEVEL 1 (L1 uses static protection settings):
 *  - Set mode to privileged for all partitions.
 *
 * For TFM_ISOLATION_LEVEL 2 (L2 uses static protection settings):
 *  - Set mode to privileged for PRoT partitions or unprivileged for ARoT
 *    partitions.
 *
 * For TFM_ISOLATION_LEVEL 3 (L3 uses dynamic protection settings):
 *  - Set mode to unprivileged for all partitions.
 *  - Perform dynamic switch of assets:
 *     - if active domain != IFX_PROTECT_SPM_DOMAIN (meaning that there was a running
 *       partition with isolation that differs from SPM) - remove access to assets from
 *       \ref active_boundary
 *     - grant access to assets from \ref boundary
 *     - assign active_boundary = boundary for partition
 */
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_activate_boundary(const struct partition_load_info_t *p_ldinf,
                                                uintptr_t boundary)
{
    FIH_RET_TYPE(enum tfm_hal_status_t) result;
    CONTROL_Type ctrl;

    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

    FIH_SET(result, TFM_HAL_ERROR_GENERIC);

#if TFM_ISOLATION_LEVEL == 3
    /* tfm_hal_activate_boundary is called by prepare_to_thread_mode_spm to handle SPM requests
     * in thread mode. Platform keeps memory/peripheral isolation settings of active partition
     * in such cases because these settings are used by tfm_hal_memory_check to perform validation
     * for SPM request handlers running in thread mode. */
    if ((boundary != IFX_SPM_BOUNDARY) && (boundary != active_boundary)) {
        /* Platform specific partition boundary used to get PC, privilege, additional assets, etc */
        const ifx_partition_info_t *p_info = (const ifx_partition_info_t *)boundary;

        uintptr_t old_domain = IFX_GET_BOUNDARY_DOMAIN(active_boundary);
        if (IFX_PROTECT_SPM_DOMAIN != old_domain) {
            /* Disable access to previous partition`s assets */
            const ifx_partition_info_t *p_active_info = (const ifx_partition_info_t *)active_boundary;
            FIH_CALL(ifx_protect_partition_assets,
                     result,
                     p_active_info,
                     p_active_info->ifx_ldinfo->protect_cfg_disabled);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }
        }

        /* Disable MPU regions that are reserved for partition assets */
        ifx_mpu_disable_asset_regions();

        /* There is no need to change isolation for partition that shares security domain with SPM,
         * because it's assumed by default that SPM has access to all resources that can be used by
         * any security partition. */
        uintptr_t new_domain = p_info->ifx_domain;
        if (IFX_PROTECT_SPM_DOMAIN != new_domain) {
            /* Allow access to next partition`s assets */
            FIH_CALL(ifx_protect_partition_assets,
                     result,
                     p_info,
                     p_info->ifx_ldinfo->protect_cfg_enabled);
            if (FIH_NOT_EQ(result, TFM_HAL_SUCCESS)) {
                FIH_RET(result);
            }
        } else {
            FIH_SET(result, TFM_HAL_SUCCESS);
        }

        /* Update active partition data */
        active_boundary = boundary;
    } else {
        FIH_SET(result, TFM_HAL_SUCCESS);
    }

#elif TFM_ISOLATION_LEVEL == 2
    if (boundary != IFX_SPM_BOUNDARY) {
        /* Update active partition data */
        active_boundary = boundary;
    }
    FIH_SET(result, TFM_HAL_SUCCESS);
#elif TFM_ISOLATION_LEVEL == 1
    FIH_SET(result, TFM_HAL_SUCCESS);
#endif

    /* Update privilege settings for thread mode of SPM or partition */
    ctrl.w = __get_CONTROL();
    if (boundary != IFX_SPM_BOUNDARY) {
        /* Platform specific partition boundary used to get PC, privilege, additional assets, etc */
        const ifx_partition_info_t *p_info = (const ifx_partition_info_t *)boundary;
        ctrl.b.nPRIV = (IFX_IS_PARTITION_PRIVILEGED(p_info)) ? 0U : 1U;
    } else {
        /* SPM thread requires privileged access rights */
        ctrl.b.nPRIV = 0;
    }
    __set_CONTROL(ctrl.w);

    /* Add barriers to assure the PPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    FIH_RET(result);
}

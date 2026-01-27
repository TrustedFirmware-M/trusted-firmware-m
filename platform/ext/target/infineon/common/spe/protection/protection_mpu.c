/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "config_impl.h"
#include "config_tfm.h"
#include "cmsis.h"
#include "ifx_regions.h"
#include "protection_regions_cfg.h"
#include "protection_mpu.h"
#include "protection_utils.h"
#include "region.h"
#include "utilities.h"
#include "coverity_check.h"

#if CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1
/* Index of Shared metadata section */
#define IFX_SHARED_METADATA_MPU_IDX             (0)
#endif /* CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1 */

/* MPU.CTRL.PRIVDEFENA is set to 1. Thus static MPU config only lists areas
 * that must be accessible in unprivileged mode. This is done to save up MPU regions. */
const static struct mpu_armv8m_region_cfg_t ifx_mpu_static_config[] = {
/* As region limit value is taken from linker where limit is calculated as
 * (region_base + size of region) i.e. first address of next region,
 * it's necessary to subtract 1 to get limit value as last address of
 * protected region. */
#if TFM_ISOLATION_LEVEL == 3
#ifdef CONFIG_TFM_PARTITION_META
    /* TFM partition metadata pointer region */
    {
        .region_base    = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RO_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#endif /* CONFIG_TFM_PARTITION_META */
    { /* Whole secure code region */
        .region_base    = (uint32_t)&REGION_NAME(Image$$, PT_RO_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, PT_RO_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_CODE_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_OK,
        .attr_access    = MPU_ARMV8M_AP_RO_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
    { /* Peripherals */
        .region_base    = IFX_PROTECTION_MPU_PERIPHERAL_REGION_START,
        .region_limit   = IFX_PROTECTION_MPU_PERIPHERAL_REGION_LIMIT,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DEVICE_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#if TEST_NS_IFX_CODE_COVERAGE
    /* coverage linker region */
    {
        .region_base    = (uint32_t)&REGION_NAME(Image$$, IFX_CODE_COVERAGE_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, IFX_CODE_COVERAGE_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#endif /* TEST_NS_IFX_CODE_COVERAGE */

#elif TFM_ISOLATION_LEVEL == 2
#ifdef CONFIG_TFM_PARTITION_META
    /* TFM partition metadata pointer region */
    {
        .region_base    = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, TFM_SPM_RW_OTHER_RO_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RO_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#endif /* CONFIG_TFM_PARTITION_META */
    { /* Whole secure code region */
        .region_base    = (uint32_t)&REGION_NAME(Image$$, PT_RO_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, PT_RO_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_CODE_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_OK,
        .attr_access    = MPU_ARMV8M_AP_RO_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
    { /* Peripherals */
        .region_base    = IFX_PROTECTION_MPU_PERIPHERAL_REGION_START,
        .region_limit   = IFX_PROTECTION_MPU_PERIPHERAL_REGION_LIMIT,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DEVICE_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#if IFX_PSA_ROT_PRIVILEGED == 0
    /* PRoT RW, ZI and stack as one region.
     * Even though PRoT and ARoR partitions unprivileged in this config, their
     * stacks can not be combined as one MPU region. This is because there may
     * be other regions between PRoT and ARoT stack regions. */
    {
        .region_base    = (uint32_t)&REGION_NAME(Image$$, TFM_PSA_RW_STACK_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, TFM_PSA_RW_STACK_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#endif /* IFX_PSA_ROT_PRIVILEGED == 0 */
#if CONFIG_TFM_AROT_PRESENT == 1
    /* RW, ZI and stack as one region */
    {
        .region_base    = (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_START, $$Base),
        .region_limit   = (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) - 1,
        .region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX,
        .attr_exec      = MPU_ARMV8M_XN_EXEC_NEVER,
        .attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV,
        .attr_sh        = MPU_ARMV8M_SH_NONE,
    },
#endif /* CONFIG_TFM_AROT_PRESENT == 1 */

#elif TFM_ISOLATION_LEVEL == 1
/* In Isolation Level 1 all secure code and data are privileged so there are no
 * unprivileged MPU regions */
#endif /* TFM_ISOLATION_LEVEL == 3 */

    /* Platform depended MPU static config */
#ifdef IFX_PROTECTION_MPU_CUSTOM_PLATFORM_REGION
    IFX_PROTECTION_MPU_CUSTOM_PLATFORM_REGION
#endif
};

/* Number of items in \ref ifx_mpu_static_config */
static const size_t ifx_mpu_static_config_count = sizeof(ifx_mpu_static_config)
                                                   / sizeof(ifx_mpu_static_config[0]);

/* Number of used MPU regions */
static size_t ifx_mpu_used_regions_count = 0;

/**
 * \brief Configures specified MPU region
 *
 * \param[in] mpu_region_idx  Index of specified MPU region
 * \param[in] mpu_config  Configuration of specified MPU region
 */
static void ifx_mpu_config_enable_region(size_t mpu_region_idx,
                                         const struct mpu_armv8m_region_cfg_t *mpu_config)
{
    /* Check are addresses aligned to 32 bytes */
    assert(((mpu_config->region_base) & ~MPU_RBAR_BASE_Msk) == 0U);
    /* As region limit is last address of region, it's necessary to add 1 to check alignment */
    assert(((mpu_config->region_limit + 1U) & ~MPU_RLAR_LIMIT_Msk) == 0U);
    /* Verify that base < limit */
    assert(mpu_config->region_base < mpu_config->region_limit);

    /* Set MPU Region number */
    MPU->RNR  = _VAL2FLD(MPU_RNR_REGION, mpu_region_idx);

    /* Disable current MPU region before configuring */
    MPU->RLAR &= ~MPU_RLAR_EN_Msk;

    /* Base address | Shareability | Access permission | eXecute Never attribute */
    MPU->RBAR = (mpu_config->region_base) |
                 _VAL2FLD(MPU_RBAR_SH, mpu_config->attr_sh) |
                 _VAL2FLD(MPU_RBAR_AP, mpu_config->attr_access) |
                 _VAL2FLD(MPU_RBAR_XN, mpu_config->attr_exec);
    /* As region limit is last address of region, it's necessary to set last 5 bits to 0 by mask
     * to get last address of protected region, which is aligned to multiple of 32 bytes */
    /* Limit address | MAIR attr index | Enable MPU region */
    MPU->RLAR = (mpu_config->region_limit & MPU_RLAR_LIMIT_Msk) |
                 _VAL2FLD(MPU_RLAR_AttrIndx, mpu_config->region_attridx) |
                 _VAL2FLD(MPU_RLAR_EN, 1);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_init_cfg(void)
{
    if (ifx_mpu_static_config_count > CPUSS_CM33_0_MPU_S_REGION_NR) {
        TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_14_3, "two consts comparison is fair here")
        FIH_RET(TFM_HAL_ERROR_INVALID_INPUT);
    }

    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

    /* Disable MPU */
    MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

    /* Configure static MPU regions */
    for(uint32_t idx = 0UL; idx < ifx_mpu_static_config_count; idx++) {
        /* FIH call is not used because ifx_mpu_verify_static_boundaries should validate MPU state */
        ifx_mpu_config_enable_region(idx, &ifx_mpu_static_config[idx]);
    }

    /* Disable MPU regions that are reserved for partition assets.
     * FIH call is not used because ifx_mpu_verify_static_boundaries should validate MPU state. */
    ifx_mpu_disable_asset_regions();

    /* Set 3 pre-defined MAIR_ATTR for memory.
     * MAIR0_0: Peripheral, Device-nGnRE.
     * MAIR0_1: Code, WT RA. Same attr for Outer and Inner.
     * MAIR0_2: SRAM, WBWA RA. Same attr for Outer and Inner. */
    MPU->MAIR0 = _VAL2FLD(MPU_MAIR0_Attr0, MPU_ARMV8M_MAIR_ATTR_DEVICE_VAL) |
                 _VAL2FLD(MPU_MAIR0_Attr1, MPU_ARMV8M_MAIR_ATTR_CODE_VAL) |
                 _VAL2FLD(MPU_MAIR0_Attr2, MPU_ARMV8M_MAIR_ATTR_DATA_VAL);

    /* Protect memory outside MPU regions as privileged.
     * MPU Enable for HArdFault and NMI.
     * Enable MPU */
    MPU->CTRL  = _VAL2FLD(MPU_CTRL_PRIVDEFENA, PRIVILEGED_DEFAULT_ENABLE) |
                 _VAL2FLD(MPU_CTRL_HFNMIENA, HARDFAULT_NMI_ENABLE) |
                 _VAL2FLD(MPU_CTRL_ENABLE, 1);

    /* Add barriers to assure the MPU configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_verify_static_boundaries(void)
{
    uint32_t idx;

    /*
     * All the code here has a direct 1:1 mapping to the code in
     * ifx_mpu_init_cfg(). This function just verifies that that
     * one did what it was supposed to
     */

    /* Check static MPU regions */
    for (idx = 0UL; idx < ifx_mpu_static_config_count; idx++) {
        const struct mpu_armv8m_region_cfg_t *mpu_config = &ifx_mpu_static_config[idx];

        MPU->RNR  = _VAL2FLD(MPU_RNR_REGION, idx);
        if (MPU->RBAR != ((mpu_config->region_base) |
                          _VAL2FLD(MPU_RBAR_SH, mpu_config->attr_sh) |
                          _VAL2FLD(MPU_RBAR_AP, mpu_config->attr_access) |
                          _VAL2FLD(MPU_RBAR_XN, mpu_config->attr_exec))) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
        if (MPU->RLAR != ((mpu_config->region_limit & MPU_RLAR_LIMIT_Msk) |
                          _VAL2FLD(MPU_RLAR_AttrIndx, mpu_config->region_attridx) |
                          _VAL2FLD(MPU_RLAR_EN, 1))) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

    /* Remaining regions should have been disabled by ifx_mpu_disable_asset_regions() */
    for (; idx < CPUSS_CM33_0_MPU_S_REGION_NR; idx++) {
        MPU->RNR  = _VAL2FLD(MPU_RNR_REGION, idx);
        if (MPU->RLAR & MPU_RLAR_EN_Msk) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

    /* Also check the general MPU config */
    if (MPU->MAIR0 != (_VAL2FLD(MPU_MAIR0_Attr0, MPU_ARMV8M_MAIR_ATTR_DEVICE_VAL) |
                       _VAL2FLD(MPU_MAIR0_Attr1, MPU_ARMV8M_MAIR_ATTR_CODE_VAL) |
                       _VAL2FLD(MPU_MAIR0_Attr2, MPU_ARMV8M_MAIR_ATTR_DATA_VAL))) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    if (MPU->CTRL != (_VAL2FLD(MPU_CTRL_PRIVDEFENA, PRIVILEGED_DEFAULT_ENABLE) |
                      _VAL2FLD(MPU_CTRL_HFNMIENA, HARDFAULT_NMI_ENABLE) |
                      _VAL2FLD(MPU_CTRL_ENABLE, 1))) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

void ifx_mpu_disable_asset_regions(void)
{
    /* All regions that are not used for static MPU config are considered as
     * assets reserved regions. */
    for(uint32_t idx = ifx_mpu_static_config_count; idx < CPUSS_CM33_0_MPU_S_REGION_NR; idx++) {
        MPU->RNR   = _VAL2FLD(MPU_RNR_REGION, idx);    /* Set MPU Region number */
        MPU->RLAR &= ~MPU_RLAR_EN_Msk;                 /* Disable MPU region */
    }

    ifx_mpu_used_regions_count = ifx_mpu_static_config_count;
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpu_isolate_numbered_mmio(
                                                    const ifx_partition_info_t *p_info,
                                                    const struct asset_desc_t *p_asset)
{
#if TFM_ISOLATION_LEVEL == 3
    /* MPU is protected using dynamic protection only on L3 */
    if (ifx_asset_protection_type != IFX_ASSET_PROTECTION_PARTITION_DYNAMIC) {
        FIH_RET(TFM_HAL_SUCCESS);
    }
#endif /* TFM_ISOLATION_LEVEL == 3 */

    /* MPU.CTRL.PRIVDEFENA is set to 1. This makes memory areas which are not covered
     * by MPU regions accessible in privileged mode only, thus no MPU protection is needed. */
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_4, "Cannot change types due to Fault injection architecture")
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change equal logic due to Fault injection architecture and define FIH_EQ")
    if (IFX_IS_PARTITION_PRIVILEGED(p_info)) {
        FIH_RET(TFM_HAL_SUCCESS);
    }
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_4)

    if (ifx_mpu_used_regions_count >= CPUSS_CM33_0_MPU_S_REGION_NR) {
        FIH_RET(TFM_HAL_ERROR_BAD_STATE);
    }

    /* Configure MPU region for current memory asset */

    struct mpu_armv8m_region_cfg_t mpu_config;
    mpu_config.region_base  = (uint32_t)p_asset->mem.start;
    /* As region limit value for partition is taken from linker where limit is calculated
     * as (region_base + size of region), i.e. first address of next region, it's necessary
     * to subtract 1 to get limit value as last address of protected region */
    mpu_config.region_limit = (uint32_t)p_asset->mem.limit - 1U;
    mpu_config.attr_exec = MPU_ARMV8M_XN_EXEC_NEVER;

    /* Different region_attridx (MAIR_ATTR) are set for read only and read-write
     * memory to optimize (improve) hardware memory access. */
    if ((p_asset->attr & ASSET_ATTR_READ_WRITE) != 0u) {
        mpu_config.region_attridx = MPU_ARMV8M_MAIR_ATTR_DATA_IDX;
        mpu_config.attr_access    = MPU_ARMV8M_AP_RW_PRIV_UNPRIV;
    } else {
        mpu_config.region_attridx = MPU_ARMV8M_MAIR_ATTR_CODE_IDX;
        mpu_config.attr_access    = MPU_ARMV8M_AP_RO_PRIV_UNPRIV;
    }

    mpu_config.attr_sh = MPU_ARMV8M_SH_NONE;

    ifx_mpu_config_enable_region(ifx_mpu_used_regions_count, &mpu_config);

    ifx_mpu_used_regions_count++;

    FIH_RET(TFM_HAL_SUCCESS);
}

#if CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1
void ifx_mpu_shared_metadata_rw_enable(bool enable)
{
    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

    /* Select MPU region that corresponds to shared metadata area */
    MPU->RNR  = _VAL2FLD(MPU_RNR_REGION, IFX_SHARED_METADATA_MPU_IDX);

    /* Verify that IFX_SHARED_METADATA_MPU_IDX really corresponds to shared metadata region */
    assert((MPU->RBAR & MPU_RBAR_BASE_Msk) == ((uint32_t)&REGION_NAME(Image$$,
                                                                      TFM_SPM_RW_OTHER_RO_START,
                                                                      $$Base)
                                               & MPU_RBAR_BASE_Msk));
    assert((MPU->RLAR & MPU_RBAR_BASE_Msk) == (((uint32_t)&REGION_NAME(Image$$,
                                                                       TFM_SPM_RW_OTHER_RO_END,
                                                                       $$Base) - 1)
                                               & MPU_RBAR_BASE_Msk));

    /* Select appropriate permission */
    /* RW for Privileged SW only or RO for everyone */
    enum mpu_armv8m_attr_access_t permission = enable ?
                                                    MPU_ARMV8M_AP_RW_PRIV_ONLY :
                                                    MPU_ARMV8M_AP_RO_PRIV_UNPRIV;

    /* Set permission */
    MPU->RBAR = (MPU->RBAR & ~MPU_RBAR_AP_Msk) | _VAL2FLD(MPU_RBAR_AP, permission);

    /* Add barriers to assure the MPU configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();
}
#endif /* CONFIG_TFM_PARTITION_META_DYNAMIC_ISOLATION == 1 */

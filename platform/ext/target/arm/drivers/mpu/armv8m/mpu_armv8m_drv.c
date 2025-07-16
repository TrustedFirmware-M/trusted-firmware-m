/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "mpu_armv8m_drv.h"
#include "tfm_hal_device_header.h"

FIH_RET_TYPE(enum mpu_armv8m_error_t) mpu_armv8m_enable(
                                          struct mpu_armv8m_dev_t *dev,
                                          uint32_t privdef_en,
                                          uint32_t hfnmi_en)
{
    /*No error checking*/

    FIH_DECLARE(fih_rc, FIH_FAILURE);
    MPU_Type *mpu = (MPU_Type *)dev->base;

    mpu->MAIR0 = (MPU_ARMV8M_MAIR_ATTR_DEVICE_VAL << MPU_MAIR0_Attr0_Pos) |
                 (MPU_ARMV8M_MAIR_ATTR_CODE_VAL << MPU_MAIR0_Attr1_Pos) |
                 (MPU_ARMV8M_MAIR_ATTR_DATA_VAL << MPU_MAIR0_Attr2_Pos);

    mpu->CTRL =
            (privdef_en ? MPU_CTRL_PRIVDEFENA_Msk : 0) |
            (hfnmi_en   ? MPU_CTRL_HFNMIENA_Msk   : 0);

    /*Ensure all configuration is written before enable*/

    mpu->CTRL |= MPU_CTRL_ENABLE_Msk;

    /* Enable MPU before next instruction */
    __DSB();
    __ISB();

    FIH_RET(FIH_SET(fih_rc, MPU_ARMV8M_OK));
}

enum mpu_armv8m_error_t mpu_armv8m_disable(struct mpu_armv8m_dev_t *dev)
{
    MPU_Type *mpu = (MPU_Type *)dev->base;

    /* Reset all fields as enable does full setup */
    mpu->CTRL = 0;

    return MPU_ARMV8M_OK;
}

FIH_RET_TYPE(enum mpu_armv8m_error_t) mpu_armv8m_region_enable(
                                struct mpu_armv8m_dev_t *dev,
                                struct mpu_armv8m_region_cfg_t *region_cfg)
{
    MPU_Type *mpu = (MPU_Type *)dev->base;

    uint32_t ctrl_before;
    uint32_t base_cfg;
    uint32_t limit_cfg;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    if ((region_cfg->region_base & ~MPU_RBAR_BASE_Msk) != 0) {
        FIH_RET(FIH_SET(fih_rc, MPU_ARMV8M_ERROR));
    }
    if ((region_cfg->region_limit & ~MPU_RLAR_LIMIT_Msk) != 0x1F) {
        FIH_RET(FIH_SET(fih_rc, MPU_ARMV8M_ERROR));
    }

    ctrl_before = mpu->CTRL;
    mpu->CTRL = 0;

    mpu->RNR  = region_cfg->region_nr & MPU_RNR_REGION_Msk;

    /* This zeroes the lower bits of the base address */
    base_cfg = region_cfg->region_base & MPU_RBAR_BASE_Msk;
    base_cfg |= (region_cfg->attr_sh << MPU_RBAR_SH_Pos) & MPU_RBAR_SH_Msk;
    base_cfg |= (region_cfg->attr_access << MPU_RBAR_AP_Pos) & MPU_RBAR_AP_Msk;
    base_cfg |= (region_cfg->attr_exec << MPU_RBAR_XN_Pos) & MPU_RBAR_XN_Msk;

    mpu->RBAR = base_cfg;

    /* MPU Region Limit Address Register is used to set the limit address, the
     * attribute set, and to enable/disable the seleted region.
     * These parameters are passed through the lower 5 bits of this register.
     * These bits are discarded and treated as ones when decoding the address.
     */
    limit_cfg = (region_cfg->region_limit) & MPU_RLAR_LIMIT_Msk;

    limit_cfg |= (region_cfg->region_attridx << MPU_RLAR_AttrIndx_Pos) &
                 MPU_RLAR_AttrIndx_Msk;

#ifdef TFM_PXN_ENABLE
    limit_cfg |= (region_cfg->attr_pxn << MPU_RLAR_PXN_Pos) & MPU_RLAR_PXN_Msk;
#endif

    limit_cfg |= MPU_RLAR_EN_Msk;

    mpu->RLAR = limit_cfg;

    /*Restore main MPU control*/
    mpu->CTRL = ctrl_before;

    /* Enable MPU before the next instruction */
    __DSB();
    __ISB();

    FIH_RET(FIH_SET(fih_rc, MPU_ARMV8M_OK));
}

FIH_RET_TYPE(enum mpu_armv8m_error_t) mpu_armv8m_region_disable(
                                                  struct mpu_armv8m_dev_t *dev,
                                                  uint32_t region_nr)
{

    MPU_Type *mpu = (MPU_Type *)dev->base;
    uint32_t ctrl_before;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    ctrl_before = mpu->CTRL;
    mpu->CTRL = 0;

    mpu->RNR  = region_nr & MPU_RNR_REGION_Msk;

    mpu->RBAR = 0;
    mpu->RLAR = 0;

    /*Restore main MPU control*/
    mpu->CTRL = ctrl_before;

    FIH_RET(FIH_SET(fih_rc, MPU_ARMV8M_OK));
}

enum mpu_armv8m_error_t mpu_armv8m_clean(struct mpu_armv8m_dev_t *dev)
{
    MPU_Type *mpu = (MPU_Type *)dev->base;
    uint32_t i = (mpu->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;
    FIH_DECLARE(fih_rc, FIH_FAILURE);

    while (i > 0) {
        FIH_CALL(mpu_armv8m_region_disable, fih_rc, dev, i - 1);
        if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
            return MPU_ARMV8M_ERROR;
        }
        i--;
    }

    return MPU_ARMV8M_OK;
}

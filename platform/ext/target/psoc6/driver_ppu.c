/*
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>

#include "driver_ppu.h"
#include "pc_config.h"
#include "ppu_config.h"
#include "RTE_Device.h"

#include "cy_prot.h"

/* PSoC 6 has 6 different kinds of PPU */
enum ppu_type {
    MS_PPU_PR,
    MS_PPU_FX,
    PPU_PR,
    PPU_GR,
    GR_PPU_SL,
    GR_PPU_RG,
};

struct ms_ppu_config {
    uint16_t pcMask;
    cy_en_prot_perm_t user;
    cy_en_prot_perm_t priv;
    bool secure;
};

struct ppu_resources {
    enum ppu_type ppu_type;
    union ppu {
        PERI_MS_PPU_PR_Type *ms_ppu_pr;
        PERI_MS_PPU_FX_Type *ms_ppu_fx;
        PERI_PPU_PR_Type *ppu_pr;
        PERI_PPU_GR_Type *ppu_gr;
        PERI_GR_PPU_SL_Type *gr_ppu_sl;
        PERI_GR_PPU_RG_Type *gr_ppu_rg;
    } ppu;
    union master_config {
        struct ms_ppu_config ms_ppu;
        cy_stc_ppu_prog_cfg_t ppu_pr;
        cy_stc_ppu_gr_cfg_t ppu_gr;
        cy_stc_ppu_sl_cfg_t gr_ppu_sl;
        cy_stc_ppu_rg_cfg_t gr_ppu_rg;
    } master_cfg;
    union slave_config {
        struct ms_ppu_config ms_ppu;
        /* TODO also need slave addr and size for MS_PPU_PR */
        cy_stc_ppu_prog_cfg_t ppu_pr;
        cy_stc_ppu_gr_cfg_t ppu_gr;
        cy_stc_ppu_sl_cfg_t gr_ppu_sl;
        cy_stc_ppu_rg_cfg_t gr_ppu_rg;
    } slave_cfg;
};

/* Affect all 8 subregions */
#define ALL_ENABLED 0

/* Shared Driver wrapper functions */
cy_en_prot_status_t PPU_Configure(const PPU_Resources *ppu_dev)
{
    cy_en_prot_status_t ret;

    switch(ppu_dev->ppu_type) {
/* This block is only needed if there are MS_PPU_PR PPUs on the board */
#if defined(PERI_MS_PPU_PR0)
    case MS_PPU_PR:
        ret = Cy_Prot_ConfigPpuProgMasterAtt(ppu_dev->ppu.ms_ppu_pr,
                                             ppu_dev->master_cfg.ms_ppu.pcMask,
                                             ppu_dev->master_cfg.ms_ppu.user,
                                             ppu_dev->master_cfg.ms_ppu.priv,
                                             ppu_dev->master_cfg.ms_ppu.secure);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        /* TODO Sort out address and region size
        ret = Cy_Prot_ConfigPpuProgSlaveAddr(ppu_dev->ppu.ms_ppu_pr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        */
        ret = Cy_Prot_ConfigPpuProgSlaveAtt(ppu_dev->ppu.ms_ppu_pr,
                                            ppu_dev->slave_cfg.ms_ppu.pcMask,
                                            ppu_dev->slave_cfg.ms_ppu.user,
                                            ppu_dev->slave_cfg.ms_ppu.priv,
                                            ppu_dev->slave_cfg.ms_ppu.secure);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuProgSlaveRegion(ppu_dev->ppu.ms_ppu_pr);
        break;
#endif

/* This block is only needed if there are MS_PPU_FX PPUs on the board */
#if defined(PERI_MS_PPU_FX_PERI_MAIN)
    case MS_PPU_FX:
        ret = Cy_Prot_ConfigPpuFixedMasterAtt(ppu_dev->ppu.ms_ppu_fx,
                                              ppu_dev->master_cfg.ms_ppu.pcMask,
                                              ppu_dev->master_cfg.ms_ppu.user,
                                              ppu_dev->master_cfg.ms_ppu.priv,
                                              ppu_dev->master_cfg.ms_ppu.secure);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_ConfigPpuFixedSlaveAtt(ppu_dev->ppu.ms_ppu_fx,
                                             ppu_dev->slave_cfg.ms_ppu.pcMask,
                                             ppu_dev->slave_cfg.ms_ppu.user,
                                             ppu_dev->slave_cfg.ms_ppu.priv,
                                             ppu_dev->slave_cfg.ms_ppu.secure);
        break;
#endif

    case PPU_PR:
        ret = Cy_Prot_ConfigPpuProgMasterStruct(ppu_dev->ppu.ppu_pr,
                                                &ppu_dev->master_cfg.ppu_pr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_ConfigPpuProgSlaveStruct(ppu_dev->ppu.ppu_pr,
                                               &ppu_dev->slave_cfg.ppu_pr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuProgMasterStruct(ppu_dev->ppu.ppu_pr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuProgSlaveStruct(ppu_dev->ppu.ppu_pr);
        break;

    case PPU_GR:
        ret = Cy_Prot_ConfigPpuFixedGrMasterStruct(ppu_dev->ppu.ppu_gr,
                                                   &ppu_dev->master_cfg.ppu_gr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_ConfigPpuFixedGrSlaveStruct(ppu_dev->ppu.ppu_gr,
                                                  &ppu_dev->slave_cfg.ppu_gr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedGrMasterStruct(ppu_dev->ppu.ppu_gr);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedGrSlaveStruct(ppu_dev->ppu.ppu_gr);
        break;

    case GR_PPU_SL:
        ret = Cy_Prot_ConfigPpuFixedSlMasterStruct(ppu_dev->ppu.gr_ppu_sl,
                                                   &ppu_dev->master_cfg.gr_ppu_sl);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_ConfigPpuFixedSlSlaveStruct(ppu_dev->ppu.gr_ppu_sl,
                                                  &ppu_dev->slave_cfg.gr_ppu_sl);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedSlMasterStruct(ppu_dev->ppu.gr_ppu_sl);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedSlSlaveStruct(ppu_dev->ppu.gr_ppu_sl);
        break;

    case GR_PPU_RG:
        ret = Cy_Prot_ConfigPpuFixedRgMasterStruct(ppu_dev->ppu.gr_ppu_rg,
                                                   &ppu_dev->master_cfg.gr_ppu_rg);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_ConfigPpuFixedRgSlaveStruct(ppu_dev->ppu.gr_ppu_rg,
                                                  &ppu_dev->slave_cfg.gr_ppu_rg);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedRgMasterStruct(ppu_dev->ppu.gr_ppu_rg);
        if (ret != CY_PROT_SUCCESS)
            return ret;
        ret = Cy_Prot_EnablePpuFixedRgSlaveStruct(ppu_dev->ppu.gr_ppu_rg);
        break;

    default:
        printf("Unexpected peripheral type %d\n", ppu_dev->ppu_type);
        return CY_PROT_BAD_PARAM;
    }

    return ret;
}

#define DEFINE_MS_PPU_PR(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = MS_PPU_PR, \
    .ppu = {.ms_ppu_pr = PERI_PPU_##N}, \
    .master_cfg.ms_ppu = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.ms_ppu = PPU_##N##_SLAVE_CONFIG, \
};

#define DEFINE_MS_PPU_FX(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = MS_PPU_FX, \
    .ppu = {.ms_ppu_fx = PERI_PPU_##N}, \
    .master_cfg.ms_ppu = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.ms_ppu = PPU_##N##_SLAVE_CONFIG, \
};

#define DEFINE_PPU_PR(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = PPU_PR, \
    .ppu = {.ppu_pr = PERI_PPU_##N}, \
    .master_cfg.ppu_pr = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.ppu_pr = PPU_##N##_SLAVE_CONFIG, \
};

#define DEFINE_PPU_GR(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = PPU_GR, \
    .ppu = {.ppu_gr = PERI_PPU_##N}, \
    .master_cfg.ppu_gr = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.ppu_gr = PPU_##N##_SLAVE_CONFIG, \
};

#define DEFINE_GR_PPU_SL(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = GR_PPU_SL, \
    .ppu = {.gr_ppu_sl = PERI_GR_PPU_##N}, \
    .master_cfg.gr_ppu_sl = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.gr_ppu_sl = PPU_##N##_SLAVE_CONFIG, \
};

#define DEFINE_GR_PPU_RG(N) const PPU_Resources N##_PPU_Resources = { \
    .ppu_type = GR_PPU_RG, \
    .ppu = {.gr_ppu_rg = PERI_GR_PPU_##N}, \
    .master_cfg.gr_ppu_rg = PPU_##N##_MASTER_CONFIG, \
    .slave_cfg.gr_ppu_rg = PPU_##N##_SLAVE_CONFIG, \
};

#if (RTE_PPU_PR0)
DEFINE_PPU_PR(PR0)
#endif

#if (RTE_PPU_PR1)
DEFINE_PPU_PR(PR1)
#endif

#if (RTE_PPU_PR2)
DEFINE_PPU_PR(PR2)
#endif

#if (RTE_PPU_PR3)
DEFINE_PPU_PR(PR3)
#endif

#if (RTE_PPU_PR4)
DEFINE_PPU_PR(PR4)
#endif

#if (RTE_PPU_PR5)
DEFINE_PPU_PR(PR5)
#endif

#if (RTE_PPU_PR6)
DEFINE_PPU_PR(PR6)
#endif

#if (RTE_PPU_PR7)
DEFINE_PPU_PR(PR7)
#endif

#if (RTE_PPU_PR8)
DEFINE_PPU_PR(PR8)
#endif

#if (RTE_PPU_GR0)
DEFINE_PPU_GR(GR0)
#endif

#if (RTE_PPU_GR1)
DEFINE_PPU_GR(GR1)
#endif

#if (RTE_PPU_GR2)
DEFINE_PPU_GR(GR2)
#endif

#if (RTE_PPU_GR3)
DEFINE_PPU_GR(GR3)
#endif

#if (RTE_PPU_GR4)
DEFINE_PPU_GR(GR4)
#endif

#if (RTE_PPU_GR6)
DEFINE_PPU_GR(GR6)
#endif

#if (RTE_PPU_GR9)
DEFINE_PPU_GR(GR9)
#endif

#if (RTE_PPU_GR10)
DEFINE_PPU_GR(GR10)
#endif

#if (RTE_PPU_GR_MMIO0)
DEFINE_PPU_GR(GR_MMIO0)
#endif

#if (RTE_PPU_GR_MMIO1)
DEFINE_PPU_GR(GR_MMIO1)
#endif

#if (RTE_PPU_GR_MMIO2)
DEFINE_PPU_GR(GR_MMIO2)
#endif

#if (RTE_PPU_GR_MMIO3)
DEFINE_PPU_GR(GR_MMIO3)
#endif

#if (RTE_PPU_GR_MMIO4)
DEFINE_PPU_GR(GR_MMIO4)
#endif

#if (RTE_PPU_GR_MMIO6)
DEFINE_PPU_GR(GR_MMIO6)
#endif

#if (RTE_PPU_GR_MMIO9)
DEFINE_PPU_GR(GR_MMIO9)
#endif

#if (RTE_PPU_GR_MMIO10)
DEFINE_PPU_GR(GR_MMIO10)
#endif

#if (RTE_GR_PPU_SL_PERI_GR1)
DEFINE_GR_PPU_SL(SL_PERI_GR1)
#endif

#if (RTE_GR_PPU_SL_CRYPTO)
DEFINE_GR_PPU_SL(SL_CRYPTO)
#endif

#if (RTE_GR_PPU_SL_PERI_GR2)
DEFINE_GR_PPU_SL(SL_PERI_GR2)
#endif

#if (RTE_GR_PPU_SL_CPUSS)
DEFINE_GR_PPU_SL(SL_CPUSS)
#endif

#if (RTE_GR_PPU_SL_FAULT)
DEFINE_GR_PPU_SL(SL_FAULT)
#endif

#if (RTE_GR_PPU_SL_IPC)
DEFINE_GR_PPU_SL(SL_IPC)
#endif

#if (RTE_GR_PPU_SL_PROT)
DEFINE_GR_PPU_SL(SL_PROT)
#endif

#if (RTE_GR_PPU_SL_FLASHC)
DEFINE_GR_PPU_SL(SL_FLASHC)
#endif

#if (RTE_GR_PPU_SL_SRSS)
DEFINE_GR_PPU_SL(SL_SRSS)
#endif

#if (RTE_GR_PPU_SL_BACKUP)
DEFINE_GR_PPU_SL(SL_BACKUP)
#endif

#if (RTE_GR_PPU_SL_DW0)
DEFINE_GR_PPU_SL(SL_DW0)
#endif

#if (RTE_GR_PPU_SL_DW1)
DEFINE_GR_PPU_SL(SL_DW1)
#endif

#if (RTE_GR_PPU_SL_EFUSE)
DEFINE_GR_PPU_SL(SL_EFUSE)
#endif

#if (RTE_GR_PPU_SL_PROFILE)
DEFINE_GR_PPU_SL(SL_PROFILE)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT0)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT0)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT1)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT1)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT2)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT2)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT3)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT3)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT4)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT4)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT5)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT5)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT6)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT6)
#endif

#if (RTE_GR_PPU_RG_IPC_STRUCT7)
DEFINE_GR_PPU_RG(RG_IPC_STRUCT7)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT0)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT0)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT1)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT1)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT2)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT2)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT3)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT3)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT4)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT4)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT5)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT5)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT6)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT6)
#endif

#if (RTE_GR_PPU_RG_IPC_INTR_STRUCT7)
DEFINE_GR_PPU_RG(RG_IPC_INTR_STRUCT7)
#endif

#if (RTE_GR_PPU_RG_DW0_DW_CH_STRUCT0)
DEFINE_GR_PPU_RG(RG_DW0_DW_CH_STRUCT0)
#endif

#if (RTE_GR_PPU_RG_DW0_DW_CH_STRUCT1)
DEFINE_GR_PPU_RG(RG_DW0_DW_CH_STRUCT1)
#endif

#if (RTE_GR_PPU_RG_DW0_DW_CH_STRUCT2)
DEFINE_GR_PPU_RG(RG_DW0_DW_CH_STRUCT2)
#endif

#if (RTE_GR_PPU_RG_DW0_DW_CH_STRUCT3)
DEFINE_GR_PPU_RG(RG_DW0_DW_CH_STRUCT3)
#endif

#if (RTE_GR_PPU_RG_DW1_DW_CH_STRUCT0)
DEFINE_GR_PPU_RG(RG_DW1_DW_CH_STRUCT0)
#endif

#if (RTE_GR_PPU_RG_DW1_DW_CH_STRUCT1)
DEFINE_GR_PPU_RG(RG_DW1_DW_CH_STRUCT1)
#endif

#if (RTE_GR_PPU_RG_DW1_DW_CH_STRUCT2)
DEFINE_GR_PPU_RG(RG_DW1_DW_CH_STRUCT2)
#endif

#if (RTE_GR_PPU_RG_DW1_DW_CH_STRUCT3)
DEFINE_GR_PPU_RG(RG_DW1_DW_CH_STRUCT3)
#endif

#if (RTE_GR_PPU_RG_SMPU)
DEFINE_GR_PPU_RG(RG_SMPU)
#endif

#if (RTE_GR_PPU_RG_MPU_CM0P)
DEFINE_GR_PPU_RG(RG_MPU_CM0P)
#endif

#if (RTE_GR_PPU_RG_MPU_CRYPTO)
DEFINE_GR_PPU_RG(RG_MPU_CRYPTO)
#endif

#if (RTE_GR_PPU_RG_MPU_CM4)
DEFINE_GR_PPU_RG(RG_MPU_CM4)
#endif

#if (RTE_GR_PPU_RG_MPU_TC)
DEFINE_GR_PPU_RG(RG_MPU_TC)
#endif

#if (RTE_GR_PPU_SL_PERI_GR3)
DEFINE_GR_PPU_SL(SL_PERI_GR3)
#endif

#if (RTE_GR_PPU_SL_HSIOM)
DEFINE_GR_PPU_SL(SL_HSIOM)
#endif

#if (RTE_GR_PPU_SL_GPIO)
DEFINE_GR_PPU_SL(SL_GPIO)
#endif

#if (RTE_GR_PPU_SL_SMARTIO)
DEFINE_GR_PPU_SL(SL_SMARTIO)
#endif

#if (RTE_GR_PPU_SL_UDB)
DEFINE_GR_PPU_SL(SL_UDB)
#endif

#if (RTE_GR_PPU_SL_LPCOMP)
DEFINE_GR_PPU_SL(SL_LPCOMP)
#endif

#if (RTE_GR_PPU_SL_CSD)
DEFINE_GR_PPU_SL(SL_CSD)
#endif

#if (RTE_GR_PPU_SL_TCPWM0)
DEFINE_GR_PPU_SL(SL_TCPWM0)
#endif

#if (RTE_GR_PPU_SL_TCPWM1)
DEFINE_GR_PPU_SL(SL_TCPWM1)
#endif

#if (RTE_GR_PPU_SL_LCD)
DEFINE_GR_PPU_SL(SL_LCD)
#endif

#if (RTE_GR_PPU_SL_BLE)
DEFINE_GR_PPU_SL(SL_BLE)
#endif

#if (RTE_GR_PPU_SL_USBFS)
DEFINE_GR_PPU_SL(SL_USBFS)
#endif

#if (RTE_GR_PPU_SL_PERI_GR4)
DEFINE_GR_PPU_SL(SL_PERI_GR4)
#endif

#if (RTE_GR_PPU_SL_SMIF)
DEFINE_GR_PPU_SL(SL_SMIF)
#endif

#if (RTE_GR_PPU_SL_PERI_GR6)
DEFINE_GR_PPU_SL(SL_PERI_GR6)
#endif

#if (RTE_GR_PPU_SL_SCB0)
DEFINE_GR_PPU_SL(SL_SCB0)
#endif

#if (RTE_GR_PPU_SL_SCB1)
DEFINE_GR_PPU_SL(SL_SCB1)
#endif

#if (RTE_GR_PPU_SL_SCB2)
DEFINE_GR_PPU_SL(SL_SCB2)
#endif

#if (RTE_GR_PPU_SL_SCB3)
DEFINE_GR_PPU_SL(SL_SCB3)
#endif

#if (RTE_GR_PPU_SL_SCB4)
DEFINE_GR_PPU_SL(SL_SCB4)
#endif

#if (RTE_GR_PPU_SL_SCB5)
DEFINE_GR_PPU_SL(SL_SCB5)
#endif

#if (RTE_GR_PPU_SL_SCB6)
DEFINE_GR_PPU_SL(SL_SCB6)
#endif

#if (RTE_GR_PPU_SL_SCB7)
DEFINE_GR_PPU_SL(SL_SCB7)
#endif

#if (RTE_GR_PPU_SL_SCB8)
DEFINE_GR_PPU_SL(SL_SCB8)
#endif

#if (RTE_GR_PPU_SL_PERI_GR9)
DEFINE_GR_PPU_SL(SL_PERI_GR9)
#endif

#if (RTE_GR_PPU_SL_PASS)
DEFINE_GR_PPU_SL(SL_PASS)
#endif

#if (RTE_GR_PPU_SL_PERI_GR10)
DEFINE_GR_PPU_SL(SL_PERI_GR10)
#endif

#if (RTE_GR_PPU_SL_I2S)
DEFINE_GR_PPU_SL(SL_I2S)
#endif

#if (RTE_GR_PPU_SL_PDM)
DEFINE_GR_PPU_SL(SL_PDM)
#endif


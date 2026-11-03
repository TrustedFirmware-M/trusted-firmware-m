/*******************************************************************************
 * File Name: cycfg_system.c
 *
 * Description:
 * System configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.39.0.10988
 * ifx-tf-m 1.0.0.0
 * mtb-dsl-psc3m6 1.0.0.335
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
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
 ******************************************************************************/

#include "cycfg_system.h"
#include "stdbool.h"
#include "stdint.h"
#include "string.h"

#if (smif_0_mpc_0_REGION_COUNT > 0U) || (smif_1_mpc_0_REGION_COUNT > 0U)
#include "cy_smif.h"
#endif /* (smif_0_mpc_0_REGION_COUNT > 0U) || (smif_1_mpc_0_REGION_COUNT > 0U) */

#define CY_CFG_PWR_ENABLED 1
#define CY_CFG_PWR_INIT 1
#define CY_CFG_PWR_USING_PMIC 0
#define CY_CFG_PWR_VBACKUP_USING_VDDD 1
#define CY_CFG_PWR_REGULATOR_MODE_MIN 0
#define CY_CFG_PWR_USING_ULP 0

#if (smif_0_mpc_0_REGION_COUNT > 0U) || (smif_1_mpc_0_REGION_COUNT > 0U)
#define SMIF_DESELECT_DELAY (7U)
#define TIMEOUT_1_MS (1000U)
#endif /* (smif_0_mpc_0_REGION_COUNT > 0U) || (smif_1_mpc_0_REGION_COUNT > 0U) */

#define CY_MPC_PC_LAST (8)

#if defined (CY_PDL_TZ_ENABLED)
const cy_stc_mpc_rot_cfg_t M33S_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t M33_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_NON_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_NON_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_NON_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t M33NSC_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_R,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_R,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_R,
    },
};
const cy_stc_mpc_rot_cfg_t M33S_CODE_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t TFM_SP_INITIAL_ATTESTATION_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t TFM_SP_CRYPTO_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t TFM_SP_ITS_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
const cy_stc_mpc_rot_cfg_t TFM_SP_PS_mpc_cfg[] =
{
    {
        .pc = CY_MPC_PC_2,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_3,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
    {
        .pc = CY_MPC_PC_7,
        .secure = CY_MPC_SECURE,
        .access = CY_MPC_ACCESS_RW,
    },
};
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
const cy_stc_mpc_cfg_t M33S_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t M33_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_NON_SECURE,
};
const cy_stc_mpc_cfg_t M33NSC_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t M33S_CODE_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t TFM_SP_CRYPTO_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t TFM_SP_ITS_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
const cy_stc_mpc_cfg_t TFM_SP_PS_mpc_locked_rot_cfg =
{
    .secure = CY_MPC_SECURE,
};
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
const cy_stc_mpc_regions_t M33S_mpc_regions[] =
{
    {
        .base = (MPC_Type*)RAMC0_MPC0,
        .offset = 0x00000000,
        .size = 0x00010000,
    },
    {
        .base = (MPC_Type*)RAMC1_MPC0,
        .offset = 0x00000000,
        .size = 0x00008800,
    },
};
const cy_stc_mpc_regions_t M33_mpc_regions[] =
{
    {
        .base = (MPC_Type*)RAMC1_MPC0,
        .offset = 0x00008800,
        .size = 0x00007800,
    },
};
const cy_stc_mpc_regions_t M33NSC_mpc_regions[] = {0};
const cy_stc_mpc_regions_t M33S_CODE_mpc_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_INITIAL_ATTESTATION_mpc_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_CRYPTO_mpc_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_ITS_mpc_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_PS_mpc_regions[] = {0};
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
const cy_stc_mpc_regions_t M33S_mpc_locked_rot_regions[] =
{
    {
        .base = (MPC_Type*)FLASHC_MPC0,
        .offset = 0x00014800,
        .size = 0x00000800,
    },
};
const cy_stc_mpc_regions_t M33_mpc_locked_rot_regions[] =
{
    {
        .base = (MPC_Type*)FLASHC_MPC0,
        .offset = 0x00043800,
        .size = 0x0003C800,
    },
};
const cy_stc_mpc_regions_t M33NSC_mpc_locked_rot_regions[] = {0};
const cy_stc_mpc_regions_t M33S_CODE_mpc_locked_rot_regions[] =
{
    {
        .base = (MPC_Type*)FLASHC_MPC0,
        .offset = 0x00018000,
        .size = 0x0002B800,
    },
};
const cy_stc_mpc_regions_t TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_CRYPTO_mpc_locked_rot_regions[] = {0};
const cy_stc_mpc_regions_t TFM_SP_ITS_mpc_locked_rot_regions[] =
{
    {
        .base = (MPC_Type*)FLASHC_MPC0,
        .offset = 0x00015000,
        .size = 0x00001000,
    },
};
const cy_stc_mpc_regions_t TFM_SP_PS_mpc_locked_rot_regions[] =
{
    {
        .base = (MPC_Type*)FLASHC_MPC0,
        .offset = 0x00016000,
        .size = 0x00002000,
    },
};
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

#if defined (CY_PDL_TZ_ENABLED)
const cy_stc_mpc_resp_cfg_t cy_response_mpcs[] =
{
    {
        .base = (MPC_Type*)RAMC0_MPC0,
        .response = CY_MPC_BUS_ERR,
    },
    {
        .base = (MPC_Type*)RAMC1_MPC0,
        .response = CY_MPC_BUS_ERR,
    },
};
const size_t cy_response_mpcs_count = sizeof(cy_response_mpcs) / sizeof(cy_stc_mpc_resp_cfg_t);
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
const cy_stc_mpc_unified_t unified_mpc_domains[] =
{
    {
        .regions = M33S_mpc_regions,
        .region_count = sizeof(M33S_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = M33S_mpc_cfg,
        .cfg_count = sizeof(M33S_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = M33S_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(M33S_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &M33S_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = M33_mpc_regions,
        .region_count = sizeof(M33_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = M33_mpc_cfg,
        .cfg_count = sizeof(M33_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = M33_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(M33_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &M33_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = M33NSC_mpc_regions,
        .region_count = sizeof(M33NSC_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = M33NSC_mpc_cfg,
        .cfg_count = sizeof(M33NSC_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = M33NSC_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(M33NSC_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &M33NSC_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = M33S_CODE_mpc_regions,
        .region_count = sizeof(M33S_CODE_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = M33S_CODE_mpc_cfg,
        .cfg_count = sizeof(M33S_CODE_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = M33S_CODE_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(M33S_CODE_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &M33S_CODE_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = TFM_SP_INITIAL_ATTESTATION_mpc_regions,
        .region_count = sizeof(TFM_SP_INITIAL_ATTESTATION_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = TFM_SP_INITIAL_ATTESTATION_mpc_cfg,
        .cfg_count = sizeof(TFM_SP_INITIAL_ATTESTATION_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = TFM_SP_CRYPTO_mpc_regions,
        .region_count = sizeof(TFM_SP_CRYPTO_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = TFM_SP_CRYPTO_mpc_cfg,
        .cfg_count = sizeof(TFM_SP_CRYPTO_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = TFM_SP_CRYPTO_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(TFM_SP_CRYPTO_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &TFM_SP_CRYPTO_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = TFM_SP_ITS_mpc_regions,
        .region_count = sizeof(TFM_SP_ITS_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = TFM_SP_ITS_mpc_cfg,
        .cfg_count = sizeof(TFM_SP_ITS_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = TFM_SP_ITS_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(TFM_SP_ITS_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &TFM_SP_ITS_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
    {
        .regions = TFM_SP_PS_mpc_regions,
        .region_count = sizeof(TFM_SP_PS_mpc_regions) / sizeof(cy_stc_mpc_regions_t),
        .cfg = TFM_SP_PS_mpc_cfg,
        .cfg_count = sizeof(TFM_SP_PS_mpc_cfg) / sizeof(cy_stc_mpc_rot_cfg_t),
#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
        .locked_rot_regions = TFM_SP_PS_mpc_locked_rot_regions,
        .locked_rot_region_count = sizeof(TFM_SP_PS_mpc_locked_rot_regions) / sizeof(cy_stc_mpc_regions_t),
        .locked_rot_cfg = &TFM_SP_PS_mpc_locked_rot_cfg,
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
    },
};
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined (CY_PDL_TZ_ENABLED)
const size_t unified_mpc_domains_count = sizeof(unified_mpc_domains) / sizeof(cy_stc_mpc_unified_t);
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
const cy_en_prot_region_t M33S_ppc_0_regions[] =
{
    PROT_CPUSS,
    PROT_RAMC0_CM33,
    PROT_RAMC1_CM33,
    PROT_RAMC0_RAM_PWR,
    PROT_RAMC1_RAM_PWR,
    PROT_RAMC0_MPC0_PPC_MPC_MAIN,
    PROT_RAMC1_MPC0_PPC_MPC_MAIN,
    PROT_RAMC0_MPC0_PPC_MPC_PC,
    PROT_RAMC1_MPC0_PPC_MPC_PC,
    PROT_RAMC0_MPC0_PPC_MPC_ROT,
    PROT_RAMC1_MPC0_PPC_MPC_ROT,
    PROT_FLASHC_BOOT,
    PROT_FLASHC_BOOT1,
    PROT_FLASHC_MAIN,
    PROT_FLASHC_ECC,
    PROT_FLASHC_MPC0_PPC_MPC_MAIN,
    PROT_FLASHC_MPC0_PPC_MPC_PC,
    PROT_FLASHC_FM_CTL_FM_MAIN,
    PROT_MXCM33_CM33_S,
    PROT_MXCM33_CM33_INT,
    PROT_CPUSS_CM33_S,
    PROT_CPUSS_MSC_INT,
    PROT_MS_PC31_PRIV,
    PROT_MSC_ACG,
    PROT_CPUSS_SL_CTL_GROUP,
    PROT_FAULT_STRUCT0_MAIN,
    PROT_SRSS_GENERAL,
    PROT_SRSS_HIB_DATA,
    PROT_SRSS_MAIN,
    PROT_SRSS_SECURE,
    PROT_SRSS_DPLL,
    PROT_PWRMODE_PWRMODE,
    PROT_CRYPTOLITE_MAIN,
    PROT_CRYPTOLITE_TRNG,
    PROT_SVGS_SVGS_MAIN,
    PROT_MXAES_MAIN1,
    PROT_MXAES_BOOT1,
    PROT_MXAES_MAIN2,
    PROT_MXAES_BOOT2,
    PROT_EFUSE_DATA_BOOT1,
    PROT_SCB3, 
};
const cy_en_prot_region_t M33_ppc_0_regions[] =
{
    PROT_PERI0_MAIN,
    PROT_PERI0_GR0_GROUP,
    PROT_PERI0_GR1_GROUP,
    PROT_PERI0_GR2_GROUP,
    PROT_PERI0_GR3_GROUP,
    PROT_PERI0_GR4_GROUP,
    PROT_PERI0_GR5_GROUP,
    PROT_PERI0_TR,
    PROT_PERI_PCLK0_MAIN,
    PROT_PROMC_CM33,
    PROT_MXCM33_CM33,
    PROT_MXCM33_CM33_NS,
    PROT_DW0_DW,
    PROT_DW1_DW,
    PROT_DW0_DW_CRC,
    PROT_DW1_DW_CRC,
    PROT_DW0_CH_STRUCT0_CH,
    PROT_DW0_CH_STRUCT1_CH,
    PROT_DW0_CH_STRUCT2_CH,
    PROT_DW0_CH_STRUCT3_CH,
    PROT_DW0_CH_STRUCT4_CH,
    PROT_DW0_CH_STRUCT5_CH,
    PROT_DW0_CH_STRUCT6_CH,
    PROT_DW0_CH_STRUCT7_CH,
    PROT_DW0_CH_STRUCT8_CH,
    PROT_DW0_CH_STRUCT9_CH,
    PROT_DW0_CH_STRUCT10_CH,
    PROT_DW0_CH_STRUCT11_CH,
    PROT_DW0_CH_STRUCT12_CH,
    PROT_DW0_CH_STRUCT13_CH,
    PROT_DW0_CH_STRUCT14_CH,
    PROT_DW0_CH_STRUCT15_CH,
    PROT_DW1_CH_STRUCT0_CH,
    PROT_DW1_CH_STRUCT1_CH,
    PROT_DW1_CH_STRUCT2_CH,
    PROT_DW1_CH_STRUCT3_CH,
    PROT_DW1_CH_STRUCT4_CH,
    PROT_DW1_CH_STRUCT5_CH,
    PROT_DW1_CH_STRUCT6_CH,
    PROT_DW1_CH_STRUCT7_CH,
    PROT_DW1_CH_STRUCT8_CH,
    PROT_DW1_CH_STRUCT9_CH,
    PROT_DW1_CH_STRUCT10_CH,
    PROT_DW1_CH_STRUCT11_CH,
    PROT_DW1_CH_STRUCT12_CH,
    PROT_DW1_CH_STRUCT13_CH,
    PROT_DW1_CH_STRUCT14_CH,
    PROT_DW1_CH_STRUCT15_CH,
    PROT_CPUSS_ALL_PC,
    PROT_CPUSS_CM33_NS,
    PROT_MS_PC0_PRIV_MIR,
    PROT_MS_PC31_PRIV_MIR,
    PROT_IPC_STRUCT0_IPC,
    PROT_IPC_STRUCT1_IPC,
    PROT_IPC_STRUCT2_IPC,
    PROT_IPC_STRUCT3_IPC,
    PROT_IPC_INTR_STRUCT0_INTR,
    PROT_IPC_INTR_STRUCT1_INTR,
    PROT_SRSS_GENERAL2,
    PROT_RAM_TRIM_SRSS_SRAM,
    PROT_SRSS_WDT,
    PROT_MAIN,
    PROT_BACKUP_BACKUP,
    PROT_BACKUP_B_BREG0,
    PROT_BACKUP_B_BREG1,
    PROT_BACKUP_B_BREG2,
    PROT_BACKUP_B_BREG3,
    PROT_MXCORDIC_1_1,
    PROT_DEBUG600_DEBUG600,
    PROT_HSIOM_PRT0_PRT,
    PROT_HSIOM_PRT1_PRT,
    PROT_HSIOM_PRT2_PRT,
    PROT_HSIOM_PRT3_PRT,
    PROT_HSIOM_PRT4_PRT,
    PROT_HSIOM_PRT5_PRT,
    PROT_HSIOM_PRT6_PRT,
    PROT_HSIOM_PRT7_PRT,
    PROT_HSIOM_PRT8_PRT,
    PROT_HSIOM_PRT9_PRT,
    PROT_HSIOM_PRT10_PRT,
    PROT_HSIOM_PRT11_PRT,
    PROT_HSIOM_PRT12_PRT,
    PROT_HSIOM_PRT13_PRT,
    PROT_HSIOM_SECURE_PRT0_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT1_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT2_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT3_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT4_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT5_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT6_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT7_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT8_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT9_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT10_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT11_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT12_SECURE_PRT,
    PROT_HSIOM_SECURE_PRT13_SECURE_PRT,
    PROT_HSIOM_AMUX,
    PROT_HSIOM_MON,
    PROT_GPIO_PRT0_PRT,
    PROT_GPIO_PRT1_PRT,
    PROT_GPIO_PRT2_PRT,
    PROT_GPIO_PRT3_PRT,
    PROT_GPIO_PRT4_PRT,
    PROT_GPIO_PRT5_PRT,
    PROT_GPIO_PRT6_PRT,
    PROT_GPIO_PRT7_PRT,
    PROT_GPIO_PRT8_PRT,
    PROT_GPIO_PRT9_PRT,
    PROT_GPIO_PRT10_PRT,
    PROT_GPIO_PRT11_PRT,
    PROT_GPIO_PRT12_PRT,
    PROT_GPIO_PRT13_PRT,
    PROT_GPIO_PRT0_CFG,
    PROT_GPIO_PRT1_CFG,
    PROT_GPIO_PRT2_CFG,
    PROT_GPIO_PRT3_CFG,
    PROT_GPIO_PRT4_CFG,
    PROT_GPIO_PRT5_CFG,
    PROT_GPIO_PRT6_CFG,
    PROT_GPIO_PRT7_CFG,
    PROT_GPIO_PRT8_CFG,
    PROT_GPIO_PRT9_CFG,
    PROT_GPIO_PRT10_CFG,
    PROT_GPIO_PRT11_CFG,
    PROT_GPIO_PRT12_CFG,
    PROT_GPIO_PRT13_CFG,
    PROT_GPIO_SEC_GPIO,
    PROT_GPIO_GPIO,
    PROT_GPIO_TEST,
    PROT_SMARTIO_PRT0_PRT,
    PROT_SMARTIO_PRT1_PRT,
    PROT_SMARTIO_PRT2_PRT,
    PROT_SMARTIO_PRT3_PRT,
    PROT_SMARTIO_PRT5_PRT,
    PROT_SMARTIO_PRT6_PRT,
    PROT_SMARTIO_PRT9_PRT,
    PROT_LPCOMP,
    PROT_EFUSE_CTL1,
    PROT_EFUSE_CTL3,
    PROT_CANFD0_CH0_CH,
    PROT_CANFD0_CH1_CH,
    PROT_CANFD0_MAIN,
    PROT_CANFD0_BUF,
    PROT_SCB0,
    PROT_SCB1,
    PROT_SCB2,
    PROT_SCB4,
    PROT_SCB5,
    PROT_TCPWM0_GRP0_CNT0_CNT,
    PROT_TCPWM0_GRP0_CNT1_CNT,
    PROT_TCPWM0_GRP0_CNT2_CNT,
    PROT_TCPWM0_GRP0_CNT3_CNT,
    PROT_TCPWM0_GRP0_CNT4_CNT,
    PROT_TCPWM0_GRP0_CNT5_CNT,
    PROT_TCPWM0_GRP0_CNT6_CNT,
    PROT_TCPWM0_GRP0_CNT7_CNT,
    PROT_TCPWM0_GRP1_CNT0_CNT,
    PROT_TCPWM0_GRP1_CNT1_CNT,
    PROT_TCPWM0_GRP1_CNT2_CNT,
    PROT_TCPWM0_GRP1_CNT3_CNT,
    PROT_TCPWM0_GRP1_CNT4_CNT,
    PROT_TCPWM0_GRP1_CNT5_CNT,
    PROT_TCPWM0_GRP1_CNT6_CNT,
    PROT_TCPWM0_GRP1_CNT7_CNT,
    PROT_TCPWM0_GRP2_CNT0_CNT,
    PROT_TCPWM0_GRP2_CNT1_CNT,
    PROT_TCPWM0_GRP2_CNT2_CNT,
    PROT_TCPWM0_GRP2_CNT3_CNT,
    PROT_TCPWM0_GRP2_CNT4_CNT,
    PROT_TCPWM0_GRP2_CNT5_CNT,
    PROT_TCPWM0_GRP2_CNT6_CNT,
    PROT_TCPWM0_GRP2_CNT7_CNT,
    PROT_TCPWM0_TR_ALL_GF_TR_ALL_GF,
    PROT_TCPWM0_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS,
    PROT_TCPWM0_MOTIF_GRP1_MOTIF0_MOTIF,
    PROT_TCPWM0_MOTIF_GRP2_MOTIF0_MOTIF,
    PROT_MCPASS_AFE,
    PROT_MCPASS_SARADC,
    PROT_MCPASS_SAR,
    PROT_MCPASS_DAC_BUFFER,
    PROT_MCPASS_HWFILT3P3Z,
    PROT_MCPASS_CSG,
    PROT_MCPASS_ACTRLR,
    PROT_MCPASS_INFRA,
    PROT_MCPASS_MMIO,
    PROT_I3C0,
    PROT_USBFS0, 
};
const cy_stc_ppc_attribute_t M33S_ppc_0_cfg =
{
    .pcMask = 0x8C,
    .secAttribute = CY_PPC_SECURE,
    .privAttribute = CY_PPC_PRIV,
};
const cy_stc_ppc_attribute_t M33_ppc_0_cfg =
{
    .pcMask = 0x8C,
    .secAttribute = CY_PPC_NON_SECURE,
    .privAttribute = CY_PPC_NONPRIV,
};
const cy_stc_ppc_cfg_t cycfg_ppc_0_domains_config[] =
{
    {
        .regions = &M33S_ppc_0_regions[0],
        .region_count = M33S_ppc_0_REGION_COUNT,
        .cfg = &M33S_ppc_0_cfg,
    },
    {
        .regions = &M33_ppc_0_regions[0],
        .region_count = M33_ppc_0_REGION_COUNT,
        .cfg = &M33_ppc_0_cfg,
    },
};
const size_t cycfg_ppc_0_domains_count = sizeof(cycfg_ppc_0_domains_config) / sizeof(cy_stc_ppc_cfg_t);
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#if defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE)
const mtb_srf_protection_range_s_t flashc_0_mpc_0_srf_protection_range_s[flashc_0_mpc_0_REGION_COUNT] =
{
    {
        .start = (void *) 0x22014800 ,
        .length = 0x800U,
        .is_secure = true,
    },
    {
        .start = (void *) 0x22015000 ,
        .length = 0x1000U,
        .is_secure = true,
    },
    {
        .start = (void *) 0x22016000 ,
        .length = 0x2000U,
        .is_secure = true,
    },
    {
        .start = (void *) 0x22018000 ,
        .length = 0x2B800U,
        .is_secure = true,
    },
    {
        .start = (void *) 0x22043800 ,
        .length = 0x3C800U,
        .is_secure = false,
    },
};
const mtb_srf_protection_range_s_t mxsramc_0_mpc_0_srf_protection_range_s[mxsramc_0_mpc_0_REGION_COUNT] =
{
    {
        .start = (void *) 0x24000000 ,
        .length = 0x10000U,
        .is_secure = true,
    },
};
const mtb_srf_protection_range_s_t mxsramc_1_mpc_0_srf_protection_range_s[mxsramc_1_mpc_0_REGION_COUNT] =
{
    {
        .start = (void *) 0x24010000 ,
        .length = 0x8800U,
        .is_secure = true,
    },
    {
        .start = (void *) 0x24018800 ,
        .length = 0x7800U,
        .is_secure = false,
    },
};
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE) */

#if defined(CY_PDL_TZ_ENABLED)
const cy_stc_sau_config_t SAU_config[4] =
{
    {
        .reg_num = 0U,
        .base_addr = 0x00000000,
        .size = 0x10000000,
        .nsc = false,
    },
    {
        .reg_num = 1U,
        .base_addr = 0x20000000,
        .size = 0x10000000,
        .nsc = false,
    },
    {
        .reg_num = 2U,
        .base_addr = 0x40000000,
        .size = 0xc0000000,
        .nsc = false,
    },
    {
        .reg_num = 3,
        .base_addr = NSC_START_ADDRESS,
        .size = NSC_SIZE,
        .nsc = true,
    },
};
#endif /* defined(CY_PDL_TZ_ENABLED) */

__STATIC_INLINE void init_cycfg_power(void);

#if defined(CY_PDL_TZ_ENABLED)
cy_rslt_t _cycfg_mpc_init_regions(const cy_stc_mpc_regions_t* region, const cy_stc_mpc_rot_cfg_t* config, uint8_t cfg_count);
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
cy_rslt_t _cycfg_mpc_init_regions_nonrot(const cy_stc_mpc_regions_t* region, const cy_stc_mpc_cfg_t* cfg);
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

__STATIC_INLINE void init_cycfg_power(void)
{
    Cy_SysPm_Init();
    /* **Reset the Backup domain on POR, XRES, BOD only if Backup domain is supplied by VDDD** */
    #if (CY_CFG_PWR_VBACKUP_USING_VDDD)
        #ifdef CY_CFG_SYSCLK_ILO_ENABLED
            if (0u == Cy_SysLib_GetResetReason() /* POR, XRES, or BOD */)
            {
                Cy_SysLib_ResetBackupDomain();
                Cy_SysClk_IloDisable();
                Cy_SysClk_IloInit();
            }
        #endif /* CY_CFG_SYSCLK_ILO_ENABLED */
    #endif /* CY_CFG_PWR_VBACKUP_USING_VDDD */

    /* **System Active Power Mode Profile Configuration** */
    #if (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_OD)
        Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_OD);
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_LP)
        Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_LP);
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_MF)
        Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_MF);
    #elif (CY_CFG_PWR_SYS_ACTIVE_PROFILE == CY_CFG_PWR_MODE_ULP)
        Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_ULP);
    #endif /* CY_CFG_PWR_SYS_ACTIVE_PROFILE */

    /* **System Active Low Power Profile(LPACTIVE/LPSLEEP) Configuration** */
    #if (CY_CFG_PWR_SYS_LP_PROFILE_MODE)
        Cy_SysPm_SystemLpActiveEnter();
    #endif /* CY_CFG_PWR_SYS_ACTIVE_MODE */

    /* **System Regulators Low Current Configuration** */
    #if (CY_CFG_PWR_REGULATOR_MODE_MIN)
        Cy_SysPm_SystemSetMinRegulatorCurrent();
    #endif /* CY_CFG_PWR_REGULATOR_MODE_MIN */

    /* **System Idle Power Mode Configuration** */
    #if (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP);
    #elif (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP_RAM);
    #elif (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_OFF)
        Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP_OFF);
    #endif /* CY_CFG_PWR_SYS_IDLE_MODE */
}

#if defined(CY_PDL_TZ_ENABLED)
cy_rslt_t _cycfg_mpc_init_regions(const cy_stc_mpc_regions_t* region, const cy_stc_mpc_rot_cfg_t* config, uint8_t cfg_count)
{
        // Will return an error if one occurs at all in the setup process
        cy_rslt_t retResult = CY_RSLT_SUCCESS;
        // Will track the current iteration for errors
        cy_rslt_t currentResult = CY_RSLT_SUCCESS;
    
        for (uint32_t cfg_idx = 0; cfg_idx < cfg_count; ++cfg_idx)
        {
            // Call the configuration function for each region and config
            currentResult = Cy_Mpc_ConfigRotMpcStruct(region->base, region->offset, region->size,  &config[cfg_idx]);
            if (CY_RSLT_SUCCESS != currentResult)
            {
                retResult = currentResult;
            }
        }
    
        return retResult;
}
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
cy_rslt_t _cycfg_mpc_init_regions_nonrot(const cy_stc_mpc_regions_t* region, const cy_stc_mpc_cfg_t* cfg)
{
        cy_rslt_t result = CY_RSLT_SUCCESS;
    
        result = (cy_rslt_t)Cy_Mpc_ConfigMpcStruct(region->base, region->offset, region->size, cfg);
    
        return result;
}
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
bool Cy_Mpc_IsRotConfigurable(const MPC_Type* base)
{
        if (base == (MPC_Type*)(MPC_Type*)FLASHC_MPC0) return false;
        if (base == (MPC_Type*)(MPC_Type*)RAMC0_MPC0) return true;
        if (base == (MPC_Type*)(MPC_Type*)RAMC1_MPC0) return true;
        if (base == (MPC_Type*)(PROMC_MPC_Type*)PROMC_MPC0) return true;
        return true;
}
cy_rslt_t init_cycfg_mpc(void)
{
        // Will return an error if one occurs at all in the setup process
        cy_rslt_t retResult = CY_RSLT_SUCCESS;
        // Will track the current iteration for errors
        cy_rslt_t currentResult = CY_RSLT_SUCCESS;
    
        // When executing from RRAM, the SMIF must be initialized and enabled to
        // hold onto any MPC configurations performed on the SMIF memory regions.
        // We can disable them after performing the MPC configurations.
    #if (smif_0_mpc_0_REGION_COUNT > 0U) 
        bool isSmif0Uninitialized = false;
        if (!Cy_SMIF_IsEnabled(SMIF0_CORE))
        {
            isSmif0Uninitialized = true; 
    
            cy_stc_smif_context_t SMIF_CORE0_Context;
    
            static const cy_stc_smif_config_t SMIF_0_CORE_0_config =
            {
                .mode = (uint32_t)CY_SMIF_NORMAL,
                .deselectDelay = SMIF_DESELECT_DELAY,
                .blockEvent = (uint32_t)CY_SMIF_BUS_ERROR,
                .enable_internal_dll = false
            };
    
            /* Enable IP with default configuration */
            (void) Cy_SMIF_Init(SMIF0_CORE, &SMIF_0_CORE_0_config, TIMEOUT_1_MS, &SMIF_CORE0_Context);
            Cy_SMIF_Enable(SMIF0_CORE, &SMIF_CORE0_Context);
        }
    #endif // (smif_0_mpc_0_REGION_COUNT > 0U)
    
    #if (smif_1_mpc_0_REGION_COUNT > 0U)
        bool isSmif1Uninitialized = false;
        if (!Cy_SMIF_IsEnabled(SMIF1_CORE))
        {
            isSmif1Uninitialized = true; 
    
            cy_stc_smif_context_t SMIF_CORE1_Context;
    
            static const cy_stc_smif_config_t SMIF_0_CORE_1_config =
            {
                .mode = (uint32_t)CY_SMIF_NORMAL,
                .deselectDelay = SMIF_DESELECT_DELAY,
                .blockEvent = (uint32_t)CY_SMIF_BUS_ERROR,
                .enable_internal_dll = false
            };
    
            /* Enable IP with default configuration */
            (void) Cy_SMIF_Init(SMIF1_CORE, &SMIF_0_CORE_1_config, TIMEOUT_1_MS, &SMIF_CORE1_Context);
            Cy_SMIF_Enable(SMIF1_CORE, &SMIF_CORE1_Context);
        }
    #endif // (smif_1_mpc_0_REGION_COUNT > 0U)
    
    #if (socmem_0_mpc_0_REGION_COUNT > 0U)
        /* Enable SOCMEM */
        Cy_SysEnableSOCMEM(true);
    #endif //(socmem_0_mpc_0_REGION_COUNT > 0U)
    
        for (size_t memory_idx = 0;  memory_idx < cy_response_mpcs_count;  memory_idx++)
        {
            Cy_Mpc_SetViolationResponse(cy_response_mpcs[memory_idx].base, cy_response_mpcs[memory_idx].response);
        }
    
    
        for (size_t domain_idx = 0; domain_idx < unified_mpc_domains_count; ++domain_idx)
        {
            const cy_stc_mpc_unified_t* domain = &unified_mpc_domains[domain_idx];
    
            for (uint32_t region_idx = 0; region_idx < domain->region_count; ++region_idx)
            {
                const cy_stc_mpc_regions_t* region = &domain->regions[region_idx];
    
                if (region->base != (MPC_Type*)FLASHC_MPC0)
                {
                    // Check for an empty regions struct
                    if (region->base != NULL)
                    {
                        currentResult = _cycfg_mpc_init_regions(region, &(domain->cfg[0]), domain->cfg_count);
                    }
                }
    
                if (CY_RSLT_SUCCESS != currentResult)
                {
                    retResult = currentResult;
                }
            }
    
    #if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED)
            /* Process locked ROT regions */
            for (uint32_t region_idx = 0; region_idx < domain->locked_rot_region_count; ++region_idx)
            {
                const cy_stc_mpc_regions_t* region = &domain->locked_rot_regions[region_idx];
    
                if (region->base != NULL)
                {
                    currentResult = _cycfg_mpc_init_regions_nonrot(region, domain->locked_rot_cfg);
                }
    
                if (CY_RSLT_SUCCESS != currentResult)
                {
                    retResult = currentResult;
                }
            }
    #endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) */
        }
    
    #if (smif_1_mpc_0_REGION_COUNT > 0U)
        if(isSmif1Uninitialized) 
        {
            /* Disable IP as MPC configuration is complete*/
            Cy_SMIF_Disable(SMIF1_CORE);
        }
    #endif // (smif_1_mpc_0_REGION_COUNT > 0U)
    
    #if (smif_0_mpc_0_REGION_COUNT > 0U)
        if(isSmif0Uninitialized) 
        {
            /* Disable IP as MPC configuration is complete*/
            Cy_SMIF_Disable(SMIF0_CORE);
        }
    #endif // (smif_0_mpc_0_REGION_COUNT > 0U)
    
        return retResult;
}
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
cy_rslt_t Cy_PPC_Init(PPC_Type* base, const cy_stc_ppc_cfg_t cfg[], uint32_t count, cy_en_ppc_resp_cfg_t response)
{
    cy_rslt_t ret = Cy_Ppc_InitPpc(base, response);
    
    for (size_t domain_idx = 0; ret == CY_PPC_SUCCESS && domain_idx < count; domain_idx++)
    {
        const cy_stc_ppc_cfg_t* ppc_config = &cfg[domain_idx];
        const cy_en_prot_region_t* regions = ppc_config->regions;
        const cy_stc_ppc_attribute_t* attributes = ppc_config->cfg;
        for (size_t region_idx = 0; region_idx < ppc_config->region_count; region_idx++)
        {
            ret = Cy_Ppc_ConfigAttrib(base, regions[region_idx], attributes);
            if (ret == CY_RSLT_SUCCESS)
                ret = Cy_Ppc_SetPcMask(base, regions[region_idx], attributes->pcMask);
        }
    }
    return ret;
}
cy_rslt_t init_cycfg_ppc0(void)
{
    return Cy_PPC_Init(PPC0, cycfg_ppc_0_domains_config, cycfg_ppc_0_domains_count, CY_PPC_BUS_ERR);
}
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

void init_cycfg_system(void)
{
    #ifdef CY_CFG_PWR_ENABLED
        #ifdef CY_CFG_PWR_INIT
            init_cycfg_power();
        #else
            #warning Power system will not be configured. Update power personality to v1.20 or later.
        #endif /* CY_CFG_PWR_INIT */
    #endif /* CY_CFG_PWR_ENABLED */
    
}

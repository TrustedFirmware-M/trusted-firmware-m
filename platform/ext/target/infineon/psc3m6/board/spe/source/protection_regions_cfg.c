/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_utils.h"
#include "project_memory_layout.h"
#include "cy_device.h"
#include "protection_regions_cfg.h"

/* PPC configuration should not include regions that are assigned to secure partitions
 * via manifests. Because, such peripherals are protected by SPM using information
 * provided in manifests. */


/* Following peripherals are reserved and are not configured by TFM:
 * PROT_PERI0_GR0_BOOT
 * PROT_PERI0_GR1_BOOT
 * PROT_PERI0_GR2_BOOT
 * PROT_PERI0_GR3_BOOT
 * PROT_PERI0_GR4_BOOT
 * PROT_PERI0_GR5_BOOT
 * PROT_PPC0_PPC_PPC_SECURE
 * PROT_PPC0_PPC_PPC_NONSECURE
 * PROT_RAMC0_BOOT
 * PROT_RAMC1_BOOT
 * PROT_PROMC_MPC0_PPC_MPC_MAIN
 * PROT_PROMC_MPC0_PPC_MPC_PC
 * PROT_PROMC_MPC0_PPC_MPC_ROT
 * PROT_FLASHC_DFT
 * PROT_FLASHC_MPC0_PPC_MPC_ROT
 * PROT_FLASHC_FM_CTL_FM_DFT
 * PROT_FLASHC_FM_CTL_FM_BOOT
 * PROT_MXCM33_BOOT_PC0
 * PROT_MXCM33_BOOT_PC1
 * PROT_MXCM33_BOOT_PC2
 * PROT_MXCM33_BOOT_PC3
 * PROT_MXCM33_BOOT
 * PROT_CPUSS_DDFT
 * PROT_CPUSS_AP
 * PROT_CPUSS_BOOT
 * PROT_MS0_MAIN
 * PROT_MS4_MAIN
 * PROT_MS7_MAIN
 * PROT_MS31_MAIN
 * PROT_MS_PC0_PRIV
 * PROT_BACKUP_BACKUP_SECURE
 * PROT_MXWOUND_MAIN
 * PROT_MXWOUND_MXWOUND_PROP0_PROP
 * PROT_MXWOUND_MXWOUND_PROP1_PROP
 * PROT_SVGS_SVGS_AUX
 * PROT_DFT
 * PROT_EFUSE_CTL2
 */

/* List of PPC static configs for different configurations and PPC controllers */
const ifx_ppcx_config_t ifx_ppcx_static_config[] = {
    {
        .configs = cycfg_ppc_0_domains_config,
        .config_count = &cycfg_ppc_0_domains_count,
        .ppc_base = PPC0,
    },
};

/* Number of items in \ref ifx_ppcx_static_config */
const size_t ifx_ppcx_static_config_count = ARRAY_SIZE(ifx_ppcx_static_config);

/* List of Fault sources for IFX_TFM_FAULT_STRUCT (to handle secure violations) */
const cy_en_SysFault_source_t ifx_tfm_fault_sources[] = {
    PERI_PERI_MS0_PPC_VIO,
    PERI_PERI_MS1_PPC_VIO,
    PERI_PERI_PPC_PC_MASK_VIO,
    PERI_PERI_GP1_TIMEOUT_VIO,
    PERI_PERI_GP2_TIMEOUT_VIO,
    PERI_PERI_GP3_TIMEOUT_VIO,
    PERI_PERI_GP4_TIMEOUT_VIO,
    PERI_PERI_GP5_TIMEOUT_VIO,
    PERI_PERI_GP0_AHB_VIO,
    PERI_PERI_GP1_AHB_VIO,
    PERI_PERI_GP2_AHB_VIO,
    PERI_PERI_GP3_AHB_VIO,
    PERI_PERI_GP4_AHB_VIO,
    PERI_PERI_GP5_AHB_VIO,
    CPUSS_RAMC0_MPC_FAULT_MMIO,
    CPUSS_RAMC1_MPC_FAULT_MMIO,
    CPUSS_PROMC_MPC_FAULT_MMIO,
    CPUSS_FLASHC_MPC_FAULT,
};

/* Number of items in \ref ifx_tfm_fault_sources */
const size_t ifx_tfm_fault_sources_count = ARRAY_SIZE(ifx_tfm_fault_sources);

/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_utils.h"
#include "project_memory_layout.h"
#include "cy_device.h"
#include "protection_regions_cfg.h"
#ifdef TEST_S_FPU
#include "tfm_peripherals_def.h"
#endif /* TEST_S_FPU */

/* PPC configuration should not include regions that are assigned to secure partitions
 * via manifests. Because, such peripherals are protected by SPM using information
 * provided in manifests. */


/* Array of pointers to PPC_Type structures for available PPC controllers.
 * The index in the array corresponds to the PPC controller ID.*/
PPC_Type* const ifx_ppcx_region_ptrs[] = {
    PPC0,
    PPC1,
};

/* Number of items in \ref ifx_ppcx_region_ptrs */
const size_t ifx_ppcx_region_ptrs_count = ARRAY_SIZE(ifx_ppcx_region_ptrs);

/* Following peripherals are reserved to PC0,1 and are not configured by TFM:
 *      PROT_PERI0_GR0_GROUP
 *      PROT_PERI0_GR0_BOOT
 *      PROT_PERI0_GR1_BOOT
 *      PROT_PERI0_GR2_BOOT
 *      PROT_PERI0_GR3_BOOT
 *      PROT_PERI0_GR4_BOOT
 *      PROT_PERI0_GR5_BOOT
 *      PROT_PERI0_PPC0_PPC_PPC_SECURE
 *      PROT_PERI0_PPC0_PPC_PPC_NONSECURE
 *      PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_PROTECTED
 *      PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_REPAIR
 *      PROT_PERI0_RRAMC0_RRAM_EXTRA_AREA_RRAMC_EXTRA
 *      PROT_PERI0_RRAMC0_RRAMC0_RRAMC_M0SEC
 *      PROT_PERI0_RRAMC0_MPC0_PPC_MPC_MAIN
 *      PROT_PERI0_RRAMC0_MPC1_PPC_MPC_MAIN
 *      PROT_PERI0_RRAMC0_MPC0_PPC_MPC_PC
 *      PROT_PERI0_RRAMC0_MPC1_PPC_MPC_PC
 *      PROT_PERI0_RRAMC0_MPC0_PPC_MPC_ROT
 *      PROT_PERI0_RRAMC0_MPC1_PPC_MPC_ROT
 *      PROT_PERI0_RRAMC0_RRAM_SFR_RRAMC_SFR_FPGA
 *      PROT_PERI0_RRAMC0_RRAM_SFR_RRAMC_SFR_NONUSER
 *      PROT_PERI0_RAMC0_BOOT
 *      PROT_PERI0_RAMC1_BOOT
 *      PROT_PERI0_MXCM33_BOOT_PC0
 *      PROT_PERI0_MXCM33_BOOT_PC1
 *      PROT_PERI0_MXCM33_BOOT_PC2
 *      PROT_PERI0_MXCM33_BOOT_PC3
 *      PROT_PERI0_MXCM33_BOOT
 *      PROT_PERI0_CPUSS_AP
 *      PROT_PERI0_CPUSS_BOOT
 *      PROT_PERI0_MS0_MAIN
 *      PROT_PERI0_MS4_MAIN
 *      PROT_PERI0_MS5_MAIN
 *      PROT_PERI0_MS6_MAIN
 *      PROT_PERI0_MS7_MAIN
 *      PROT_PERI0_MS8_MAIN
 *      PROT_PERI0_MS9_MAIN
 *      PROT_PERI0_MS10_MAIN
 *      PROT_PERI0_MS11_MAIN
 *      PROT_PERI0_MS29_MAIN
 *      PROT_PERI0_MS31_MAIN
 *      PROT_PERI0_MS_PC31_PRIV
 *      PROT_PERI0_CPUSS_SL_CTL_GROUP
 *      PROT_PERI0_SRSS_SECURE2
 *      PROT_PERI0_SRSS_SECURE
 *      PROT_PERI0_M0SECCPUSS_STATUS_MAIN
 *      PROT_PERI0_M0SECCPUSS_STATUS_PC1
 */

/* List of PPC static configs for different configurations and PPC controllers */
const ifx_ppcx_config_t ifx_ppcx_static_config[] = {
    {
        .configs = cycfg_ppc_0_domains_config,
        .config_count = &cycfg_ppc_0_domains_count,
        .ppc_base = PPC0,
    },
    {
        .configs = cycfg_ppc_1_domains_config,
        .config_count = &cycfg_ppc_1_domains_count,
        .ppc_base = PPC1,
    },
};

/* Number of items in \ref ifx_ppcx_static_config */
const size_t ifx_ppcx_static_config_count = ARRAY_SIZE(ifx_ppcx_static_config);

/* MSC (Bus Masters) violation response config */
const ifx_msc_agc_resp_config_t ifx_msc_agc_resp_config[] = {
#if CPUSS_CODE_MS_0_PRESENT == 1u
    {.bus_master = CODE_MS0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_CODE_MS_0_PRESENT == 1u */
#if CPUSS_SYS_MS_0_PRESENT == 1u
    {.bus_master = SYS_MS0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_SYS_MS_0_PRESENT == 1u */
#if CPUSS_SYS_MS_1_PRESENT == 1u
    {.bus_master = SYS_MS1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_SYS_MS_1_PRESENT == 1u */
#if CPUSS_EXP_MS_PRESENT == 1u
    {.bus_master = EXP_MS_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_EXP_MS_PRESENT == 1u */
#if CPUSS_DMAC0_PRESENT == 1u
    {.bus_master = DMAC0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_DMAC0_PRESENT == 1u */
#if CPUSS_DMAC1_PRESENT == 1u
    {.bus_master = DMAC1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* CPUSS_DMAC1_PRESENT == 1u */
};

/* Number of items in \ref ifx_msc_agc_resp_config */
const size_t ifx_msc_agc_resp_config_count = ARRAY_SIZE(ifx_msc_agc_resp_config);

/* MSC (Bus Masters) violation response config for CAT1D devices */
const ifx_msc_agc_resp_config_v1_t ifx_msc_agc_resp_config_v1[] = {
#if APPCPUSS_SYS_MS_0_PRESENT
    {.bus_master = APP_SYS_MS0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_SYS_MS_0_PRESENT */
#if APPCPUSS_SYS_MS_1_PRESENT
    {.bus_master = APP_SYS_MS1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_SYS_MS_1_PRESENT */
#if APPCPUSS_AXIDMAC0_PRESENT
    {.bus_master = APP_AXIDMAC0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXIDMAC0_PRESENT */
#if APPCPUSS_AXIDMAC1_PRESENT
    {.bus_master = APP_AXIDMAC1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXIDMAC1_PRESENT */
#if APPCPUSS_AXI_MS_0_PRESENT
    {.bus_master = APP_AXI_MS0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXI_MS_0_PRESENT */
#if APPCPUSS_AXI_MS_1_PRESENT
    {.bus_master = APP_AXI_MS1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXI_MS_1_PRESENT */
#if APPCPUSS_AXI_MS_2_PRESENT
    {.bus_master = APP_AXI_MS2_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXI_MS_2_PRESENT */
#if APPCPUSS_AXI_MS_3_PRESENT
    {.bus_master = APP_AXI_MS3_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_AXI_MS_3_PRESENT */
#if APPCPUSS_EXP_MS_0_PRESENT
    {.bus_master = APP_EXP_MS0_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_EXP_MS_0_PRESENT */
#if APPCPUSS_EXP_MS_1_PRESENT
    {.bus_master = APP_EXP_MS1_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_EXP_MS_1_PRESENT */
#if APPCPUSS_EXP_MS_2_PRESENT
    {.bus_master = APP_EXP_MS2_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_EXP_MS_2_PRESENT */
#if APPCPUSS_EXP_MS_3_PRESENT
    {.bus_master = APP_EXP_MS3_MSC,
     .gate_resp = CY_MS_CTL_GATE_RESP_ERR,
     .sec_resp = CY_MS_CTL_SEC_RESP_ERR,},
#endif /* APPCPUSS_EXP_MS_3_PRESENT */
};

/* Number of items in \ref ifx_msc_agc_resp_config_v1 */
const size_t ifx_msc_agc_resp_config_v1_count = ARRAY_SIZE(ifx_msc_agc_resp_config_v1);

/* List of secure interrupts that are not assigned to any Secure Partition
 * (e.g. interrupts used by hardware assigned to SPM) */
const IRQn_Type ifx_secure_interrupts_config[] = {
      m33syscpuss_interrupts_fault_0_IRQn,
      m33syscpuss_interrupt_msc_IRQn,
#ifdef TEST_S_FPU
      TFM_FPU_S_TEST_IRQ
#endif /* TEST_S_FPU */
};

/* Number of items in \ref ifx_secure_interrupts_config */
const size_t ifx_secure_interrupts_config_count = ARRAY_SIZE(ifx_secure_interrupts_config);

/* List of Fault sources for FAULT_STRUCT0 (to handle secure violations) */
const cy_en_SysFault_source_t ifx_fault_sources_fault_struct0[] = {
    PERI_0_PERI_MS0_PPC_VIO,
    PERI_0_PERI_MS1_PPC_VIO,
    PERI_0_PERI_PPC_PC_MASK_VIO,
    PERI_0_PERI_GP1_TIMEOUT_VIO,
    PERI_0_PERI_GP2_TIMEOUT_VIO,
    PERI_0_PERI_GP3_TIMEOUT_VIO,
    PERI_0_PERI_GP4_TIMEOUT_VIO,
    PERI_0_PERI_GP5_TIMEOUT_VIO,
    PERI_0_PERI_GP0_AHB_VIO,
    PERI_0_PERI_GP1_AHB_VIO,
    PERI_0_PERI_GP2_AHB_VIO,
    PERI_0_PERI_GP3_AHB_VIO,
    PERI_0_PERI_GP4_AHB_VIO,
    PERI_0_PERI_GP5_AHB_VIO,
    PERI_1_PERI_MS0_PPC_VIO,
    PERI_1_PERI_MS1_PPC_VIO,
    PERI_1_PERI_PPC_PC_MASK_VIO,
    PERI_1_PERI_GP1_TIMEOUT_VIO,
    PERI_1_PERI_GP2_TIMEOUT_VIO,
    PERI_1_PERI_GP3_TIMEOUT_VIO,
    PERI_1_PERI_GP4_TIMEOUT_VIO,
    PERI_1_PERI_GP0_AHB_VIO,
    PERI_1_PERI_GP1_AHB_VIO,
    PERI_1_PERI_GP2_AHB_VIO,
    PERI_1_PERI_GP3_AHB_VIO,
    PERI_1_PERI_GP4_AHB_VIO,
    M33SYSCPUSS_RAMC0_MPC_FAULT_MMIO,
    M33SYSCPUSS_RAMC1_MPC_FAULT_MMIO,
    M33SYSCPUSS_RRAMC_HOST_IF_MPC_FAULT,
    SMIF_0_FAULT_MXSMIF_TOP,
    SMIF_1_FAULT_MXSMIF_TOP,
    SOCMEM_SOCMEM_MPC,
};

/* Number of items in \ref ifx_fault_sources_fault_struct0 */
const size_t ifx_fault_sources_fault_struct0_count = ARRAY_SIZE(ifx_fault_sources_fault_struct0);

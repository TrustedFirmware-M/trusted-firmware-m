/*
 * Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "protection_data_common.h"
#include "tfm_peripherals_def.h"
#include "tfm_utils.h"

/* List of secure interrupts that are not assigned to any Secure Partition
 * (e.g. interrupts used by hardware assigned to SPM) */
const IRQn_Type ifx_secure_interrupts_config[] = {
    IFX_TFM_FAULT_IRQ,
    IFX_TFM_MSC_IRQ,
#ifdef TEST_S_FPU
    TFM_FPU_S_TEST_IRQ
#endif /* TEST_S_FPU */
};

/* Number of items in \ref ifx_secure_interrupts_config */
const size_t ifx_secure_interrupts_config_count = ARRAY_SIZE(ifx_secure_interrupts_config);

#if IFX_PLATFORM_PPC_PRESENT
PPC_Type* const ifx_ppcx_region_ptrs[] = {
/* Single PPC instance */
#ifdef PPC
    PPC,
#else /* PPC */
/* Multiple PPC instances */
#ifdef PPC0
    PPC0,
#endif /* PPC0 */
#ifdef PPC1
    PPC1,
#endif /* PPC1 */
#endif /* PPC */
};

const size_t ifx_ppcx_region_ptrs_count = ARRAY_SIZE(ifx_ppcx_region_ptrs);
#endif /* IFX_PLATFORM_PPC_PRESENT */

#if IFX_MSC_ACG_RESP_CONFIG
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

const size_t ifx_msc_agc_resp_config_count = ARRAY_SIZE(ifx_msc_agc_resp_config);
#endif /* IFX_MSC_ACG_RESP_CONFIG */

#if IFX_MSC_ACG_RESP_CONFIG_V1
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

const size_t ifx_msc_agc_resp_config_v1_count = ARRAY_SIZE(ifx_msc_agc_resp_config_v1);
#endif /* IFX_MSC_ACG_RESP_CONFIG_V1 */

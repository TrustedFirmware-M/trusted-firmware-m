/*******************************************************************************
 * File Name: cycfg_system.h
 *
 * Description:
 * System configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.70.0
 * device-db 4.41.0.11271
 * ifx-tf-m 1.0.0.0
 * mtb-dsl-psc3m8 1.2.0.558
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

#if !defined(CYCFG_SYSTEM_H)
#define CYCFG_SYSTEM_H

#include "cycfg_notices.h"
#include "cy_device.h"
#include "cy_sysclk.h"
#include "cy_syspm.h"
#include "cy_mpc.h"

#if defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE)
#include "mtb_srf.h"
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE) */

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
#include "cy_ppc.h"
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
#include "cy_cmsis_utils.h"
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define debug600_0_ENABLED 1U
#define srss_0_power_0_ENABLED 1U
#define CY_CFG_PWR_MODE_LP 0x01UL
#define CY_CFG_PWR_MODE_ULP 0x02UL
#define CY_CFG_PWR_MODE_ACTIVE 0x04UL
#define CY_CFG_PWR_MODE_MF 0x05UL
#define CY_CFG_PWR_MODE_OD 0x06UL
#define CY_CFG_PWR_MODE_SLEEP 0x08UL
#define CY_CFG_PWR_MODE_DEEPSLEEP 0x10UL
#define CY_CFG_PWR_MODE_DEEPSLEEP_RAM 0x11UL
#define CY_CFG_PWR_MODE_DEEPSLEEP_OFF 0x12UL
#define CY_CFG_PWR_SYS_IDLE_MODE CY_CFG_PWR_MODE_SLEEP
#define CY_CFG_PWR_DEEPSLEEP_LATENCY 5UL
#define CY_CFG_PWR_SYS_ACTIVE_MODE CY_CFG_PWR_MODE_OD
#define CY_CFG_PWR_SYS_ACTIVE_PROFILE CY_CFG_PWR_MODE_OD
#define CY_CFG_PWR_SYS_LP_PROFILE_MODE 0
#define CY_CFG_PWR_VDDA_MV 3300
#define CY_CFG_PWR_VDDD_MV 3300
#define CY_CFG_PWR_VDDBUCK 3300
#define CY_CFG_PWR_VDDIO0_MV 3300
#define CY_CFG_PWR_VDDIO1_MV 3300
#define CY_CFG_PWR_CBUCK_VOLT CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V
#define CY_CFG_PWR_CBUCK_MODE CY_SYSPM_CORE_BUCK_MODE_HP
#define CY_CFG_PWR_SDR0_VOLT CY_SYSPM_SDR_VOLTAGE_1_100V
#define CY_CFG_PWR_SDR0_MODE_BYPASS true
#define CY_CFG_PWR_SDR1_VOLT 0
#define CY_CFG_PWR_SDR1_ENABLE false
#define M33S_ENABLED 1U
#define M33_ENABLED 1U
#define M33NSC_ENABLED 1U
#define reserved_ENABLED 1U
#define vres_0_protection_0_domain_4_ENABLED 1U
#define vres_0_protection_0_domain_5_ENABLED 1U
#define vres_0_protection_0_domain_6_ENABLED 1U
#define vres_0_protection_0_domain_7_ENABLED 1U
#define vres_0_protection_0_domain_8_ENABLED 1U
#define vres_0_protection_0_mpc_0_ENABLED 1U
#define M33S_UNIFIED_MPC_DOMAIN_IDX 0U
#define M33_UNIFIED_MPC_DOMAIN_IDX 1U
#define M33NSC_UNIFIED_MPC_DOMAIN_IDX 2U
#define M33S_CODE_UNIFIED_MPC_DOMAIN_IDX 3U
#define TFM_SP_INITIAL_ATTESTATION_UNIFIED_MPC_DOMAIN_IDX 4U
#define TFM_SP_CRYPTO_UNIFIED_MPC_DOMAIN_IDX 5U
#define TFM_SP_ITS_UNIFIED_MPC_DOMAIN_IDX 6U
#define TFM_SP_PS_UNIFIED_MPC_DOMAIN_IDX 7U
#define Cy_MPC_Init init_cycfg_mpc

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
#define Cy_PPC0_Init init_cycfg_ppc0
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#if !defined(PPC0) && (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
#define PPC0 PPC
#endif /* !defined(PPC0) && (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#define peri_0_ENABLED 1U
#define CYCFG_PPC_ENABLED 1U

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
#define M33S_ppc_0_REGION_COUNT 55U
#define M33_ppc_0_REGION_COUNT 205U
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#define flashc_0_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define flashc_0_mpc_0_REGION_COUNT 5U
#define mxpromc_0_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define mxpromc_0_mpc_0_REGION_COUNT 0U
#define mxsramc_0_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define mxsramc_0_mpc_0_REGION_COUNT 1U
#define mxsramc_1_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define mxsramc_1_mpc_0_REGION_COUNT 2U
#define cpuss_0_cm33_0_sau_0_ENABLED 1U
#define ppca_0_cpuss_cnfg_0_mxsramc_0_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define ppca_0_cpuss_cnfg_0_mxsramc_0_mpc_0_REGION_COUNT 1U
#define ppca_0_cpuss_cnfg_0_mxsramc_1_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define ppca_0_cpuss_cnfg_0_mxsramc_1_mpc_0_REGION_COUNT 1U
#define ppca_0_cpuss_cnfg_0_mxsramc_2_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define ppca_0_cpuss_cnfg_0_mxsramc_2_mpc_0_REGION_COUNT 1U
#define ppca_0_cpuss_cnfg_0_mxsramc_3_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define ppca_0_cpuss_cnfg_0_mxsramc_3_mpc_0_REGION_COUNT 1U
#define ppca_0_cpuss_cnfg_0_mxsramc_4_mpc_0_RESPONSE CY_MPC_BUS_ERR
#define ppca_0_cpuss_cnfg_0_mxsramc_4_mpc_0_REGION_COUNT 1U

#if defined (CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_rot_cfg_t M33S_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t M33_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t M33NSC_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t M33S_CODE_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t TFM_SP_INITIAL_ATTESTATION_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t TFM_SP_CRYPTO_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t TFM_SP_ITS_mpc_cfg[];
extern const cy_stc_mpc_rot_cfg_t TFM_SP_PS_mpc_cfg[];
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_cfg_t M33S_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t M33_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t M33NSC_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t M33S_CODE_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t TFM_SP_CRYPTO_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t TFM_SP_ITS_mpc_locked_rot_cfg;
extern const cy_stc_mpc_cfg_t TFM_SP_PS_mpc_locked_rot_cfg;
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_regions_t M33S_mpc_regions[];
extern const cy_stc_mpc_regions_t M33_mpc_regions[];
extern const cy_stc_mpc_regions_t M33NSC_mpc_regions[];
extern const cy_stc_mpc_regions_t M33S_CODE_mpc_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_INITIAL_ATTESTATION_mpc_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_CRYPTO_mpc_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_ITS_mpc_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_PS_mpc_regions[];
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_regions_t M33S_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t M33_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t M33NSC_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t M33S_CODE_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_INITIAL_ATTESTATION_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_CRYPTO_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_ITS_mpc_locked_rot_regions[];
extern const cy_stc_mpc_regions_t TFM_SP_PS_mpc_locked_rot_regions[];
#endif /* defined(CY_DEVICE_FEATURE_SOME_MPC_ROT_LOCKED) && defined(CY_PDL_TZ_ENABLED) */

#if defined (CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_resp_cfg_t cy_response_mpcs[];
extern const size_t cy_response_mpcs_count;
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if defined(CY_PDL_TZ_ENABLED)
extern const cy_stc_mpc_unified_t unified_mpc_domains[];
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined (CY_PDL_TZ_ENABLED)
extern const size_t unified_mpc_domains_count;
#endif /* defined (CY_PDL_TZ_ENABLED) */

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
extern const cy_en_prot_region_t M33S_ppc_0_regions[];
extern const cy_en_prot_region_t M33_ppc_0_regions[];
extern const cy_stc_ppc_attribute_t M33S_ppc_0_cfg;
extern const cy_stc_ppc_attribute_t M33_ppc_0_cfg;
extern const cy_stc_ppc_cfg_t cycfg_ppc_0_domains_config[];
extern const size_t cycfg_ppc_0_domains_count;
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

#if defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE)
extern const mtb_srf_protection_range_s_t flashc_0_mpc_0_srf_protection_range_s[flashc_0_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t mxsramc_0_mpc_0_srf_protection_range_s[mxsramc_0_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t mxsramc_1_mpc_0_srf_protection_range_s[mxsramc_1_mpc_0_REGION_COUNT];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE) */

#if defined(CY_PDL_TZ_ENABLED)
extern const cy_stc_sau_config_t SAU_config[4];
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE)
extern const mtb_srf_protection_range_s_t ppca_0_cpuss_cnfg_0_mxsramc_0_mpc_0_srf_protection_range_s[ppca_0_cpuss_cnfg_0_mxsramc_0_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t ppca_0_cpuss_cnfg_0_mxsramc_1_mpc_0_srf_protection_range_s[ppca_0_cpuss_cnfg_0_mxsramc_1_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t ppca_0_cpuss_cnfg_0_mxsramc_2_mpc_0_srf_protection_range_s[ppca_0_cpuss_cnfg_0_mxsramc_2_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t ppca_0_cpuss_cnfg_0_mxsramc_3_mpc_0_srf_protection_range_s[ppca_0_cpuss_cnfg_0_mxsramc_3_mpc_0_REGION_COUNT];
extern const mtb_srf_protection_range_s_t ppca_0_cpuss_cnfg_0_mxsramc_4_mpc_0_srf_protection_range_s[ppca_0_cpuss_cnfg_0_mxsramc_4_mpc_0_REGION_COUNT];
#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE) */

#if defined(CY_PDL_TZ_ENABLED)
bool Cy_Mpc_IsRotConfigurable(const MPC_Type* base);
cy_rslt_t init_cycfg_mpc(void);
#endif /* defined(CY_PDL_TZ_ENABLED) */

#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED)
cy_rslt_t Cy_PPC_Init(PPC_Type* base, const cy_stc_ppc_cfg_t cfg[], uint32_t count, cy_en_ppc_resp_cfg_t response);
cy_rslt_t init_cycfg_ppc0(void);
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) */

void init_cycfg_system(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_SYSTEM_H */

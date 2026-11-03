/*******************************************************************************
 * File Name: cycfg_protection.c
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

#include "cycfg_protection.h"
#include "cycfg_system.h"

#if defined (COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE)
const mtb_srf_memory_protection_s_t mtb_srf_memory_protection_s[] =
{
    {
        .ranges = flashc_0_mpc_0_srf_protection_range_s,
        .size = 5U,
    },
    {
        .ranges = mxsramc_0_mpc_0_srf_protection_range_s,
        .size = 1U,
    },
    {
        .ranges = mxsramc_1_mpc_0_srf_protection_range_s,
        .size = 2U,
    },
};
const uint8_t mtb_srf_protection_range_s_count = sizeof(mtb_srf_memory_protection_s) / sizeof(mtb_srf_memory_protection_s_t);
#endif /* defined (COMPONENT_SECURE_DEVICE) && defined(COMPONENT_MW_MTB_SRF) && !defined(CY_SRF_DISABLE) */

void init_cycfg_protection(void)
{
#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CYBSP_SMIF_XIP_INIT)
    /* Note: This code will be removed, when L1 Boot has XIP support */
    init_smif_xip();
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CYBSP_SMIF_XIP_INIT) */
#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_SKIP_SAU_INIT)
    Cy_SAU_Init(SAU, SAU_config, sizeof(SAU_config) / sizeof(SAU_config[0]));
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_SKIP_SAU_INIT) */
#if  (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_SKIP_MPU_INIT)
    Cy_MPU_Init(cycfg_mpu_cm33_s_0_config, sizeof(cycfg_mpu_cm33_s_0_config) / sizeof(cycfg_mpu_cm33_s_0_config[0]));
#endif /*  (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_SKIP_MPU_INIT) */
#if  (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) && !defined(CYBSP_SKIP_MPC_INIT) && !defined(CY_DEVICE_FEATURE_MPC_LOCKED)
    init_cycfg_mpc();
#endif /*  (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) && !defined(CYBSP_SKIP_MPC_INIT) && !defined(CY_DEVICE_FEATURE_MPC_LOCKED) */
#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) && !defined(CYBSP_SKIP_PPC_INIT)
    init_cycfg_ppc0();
#endif /* (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_TZ_ENABLED) && !defined(CYBSP_SKIP_PPC_INIT) */
}

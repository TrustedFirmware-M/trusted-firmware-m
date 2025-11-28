/*
 * Copyright (c) 2018-2022 Arm Limited. All rights reserved.
 * Copyright 2019-2025 NXP
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

#include <assert.h>
#include "target_cfg.h"
#include "Driver_Common.h"
#include "platform_description.h"
#include "device_definition.h"
#include "region_defs.h"
#include "tfm_plat_defs.h"
#include "utilities.h"
#include "target_cfg_common.h"
#include "fsl_trdc.h"
#include "imx_trdc.h"
#include "trdc_config.h"

extern const struct memory_region_limits memory_regions;

struct platform_data_t tfm_peripheral_std_uart = {
        .periph_start = (uint32_t)LPUART2_BASE,
        .periph_limit = (uint32_t)LPUART2_BASE + 0xFFFF,
		.trdc_base = TRDC_A_BASE,
        .nseEnable = true,
        .mbcIdx  = 0,
		.glbacIdx = 0,
        .slaveMemoryIdx = 0,
        .memoryBlockIdx = 57,
};

struct platform_data_t tfm_peripheral_timer0 = {
        .periph_start = LPTMR1_BASE,
        .periph_limit = LPTMR1_BASE + 0xFFFF,
		.trdc_base = TRDC_A_BASE,
        .nseEnable = false,
        .mbcIdx = 0,
		.glbacIdx = 0 ,
        .slaveMemoryIdx = 0,
        .memoryBlockIdx = 48,
};

extern void BOARD_InitHardware(void);
/*------------------ Memory configuration functions -------------------------*/

struct trdc_mbc_config_info trdc_cfg_info[] = {
    {   TRDC_A_BASE,
        trdc_a_mbc, ARRAY_SIZE(trdc_a_mbc),
    }, /* TRDC_A */
    {   TRDC_W_BASE,
        trdc_w_mbc, ARRAY_SIZE(trdc_w_mbc),
    }, /* TRDC_W */
    {   TRDC_N_BASE,
        trdc_n_mbc, ARRAY_SIZE(trdc_n_mbc),
    }, /* TRDC_N */
};

struct trdc_mgr_info trdc_mgr_blks[] = {
    { TRDC_A_BASE, 0, 0, 39, 40 },
    { TRDC_W_BASE, 0, 0, 70, 71 },
    { TRDC_W_BASE, 1, 0, 1, 2 },
    { TRDC_N_BASE, 0, 1, 1, 2 },
};

unsigned int trdc_mgr_num = ARRAY_SIZE(trdc_mgr_blks);

int trdc_set_mbc_nse(uint32_t region_start, uint32_t region_end)
{
	uint32_t ns_region_start_id, ns_region_end_id, n;
    /* Set the MBC slave memory block configuration and select the memory access control of no access for this memory
     * block */
    trdc_mbc_memory_block_config_t mbcBlockConfig;
    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));

    if (region_start >= TCM_CODE_START && region_start <= TCM_CODE_END &&
        region_end >= TCM_CODE_START && region_end <= TCM_CODE_END)
    {
	/* The regions have to be alligned to TCM_SUBREGION_SIZE*/
	    assert(((region_start - TCM_CODE_START) % TCM_SUBREGION_SZ) == 0);
	assert(((region_end - TCM_CODE_START) % TCM_SUBREGION_SZ) == 0);

        /* Check TF-A for GLBAC config for this memory */
        mbcBlockConfig.memoryAccessControlSelect = TCM_GLBAC_ALL_PERM_IDX;
        /* CPU is secure mode by default, enable NSE bit to disable secure access. */
        mbcBlockConfig.nseEnable      = 1;
        mbcBlockConfig.slaveMemoryIdx = TCM_CODE_SLV_IDX;
        mbcBlockConfig.mbcIdx         = TCM_MBC_IDX;
        mbcBlockConfig.domainIdx      = TRDC_GetCurrentMasterDomainId(TRDC1);

        ns_region_start_id = (region_start - TCM_CODE_START)/TCM_SUBREGION_SZ;
        ns_region_end_id = (region_end - TCM_CODE_START)/TCM_SUBREGION_SZ;

        for (n = ns_region_start_id; n < ns_region_end_id; n++)
        {
            mbcBlockConfig.memoryBlockIdx = n;

            TRDC_MbcSetMemoryBlockConfig(TRDC1, &mbcBlockConfig);
        }
    }
    else
    if (region_start >= TCM_DATA_START && region_start <= TCM_DATA_END &&
	region_end >= TCM_DATA_START && region_end <= TCM_DATA_END)
    {
        /* Check TF-A for GLBAC config for this memory */
        mbcBlockConfig.memoryAccessControlSelect = TCM_GLBAC_ALL_PERM_IDX;
        /* CPU is secure mode by default, enable NSE bit to disable secure access. */
        mbcBlockConfig.nseEnable      = 1;
        mbcBlockConfig.slaveMemoryIdx = TCM_DATA_SLV_IDX;
        mbcBlockConfig.mbcIdx         = TCM_MBC_IDX;
        mbcBlockConfig.domainIdx      = TRDC_GetCurrentMasterDomainId(TRDC1);

	/* The regions have to be aligned to TCM_SUBREGION_SIZE*/
	    assert(((region_start - TCM_DATA_START) % TCM_SUBREGION_SZ) == 0);
	assert(((region_end - TCM_DATA_START) % TCM_SUBREGION_SZ) == 0);

        ns_region_start_id = (region_start - TCM_DATA_START)/TCM_SUBREGION_SZ;
        ns_region_end_id = (region_end - TCM_DATA_START)/TCM_SUBREGION_SZ;

        for (n = ns_region_start_id; n < ns_region_end_id; n++)
        {
            mbcBlockConfig.memoryBlockIdx = n;

            TRDC_MbcSetMemoryBlockConfig(TRDC1, &mbcBlockConfig);
        }
    }
    else
    if (region_start >= OCRAM_START && region_start <= OCRAM_END)
    {
	/* The regions have to be aligned to OCRAM_SUBREGION_SIZE*/
	    assert(((region_start - OCRAM_START) % OCRAM_SUBREGION_SZ) == 0);
	assert(((region_end - OCRAM_START) % OCRAM_SUBREGION_SZ) == 0);

        ns_region_start_id = (region_start - OCRAM_START)/OCRAM_SUBREGION_SZ;
        ns_region_end_id = (region_end - OCRAM_START)/OCRAM_SUBREGION_SZ;

        /* Check TF-A for GLBAC config for this memory */
        mbcBlockConfig.memoryAccessControlSelect = OCRAM_GLBAC_ALL_PERM_IDX;
        /* CPU is secure mode by default, enable NSE bit to disable secure access. */
        mbcBlockConfig.nseEnable      = 1;
        mbcBlockConfig.mbcIdx         = OCRAM_MBC_IDX;
        mbcBlockConfig.domainIdx      = TRDC_GetCurrentMasterDomainId(TRDC4);

        mbcBlockConfig.slaveMemoryIdx = OCRAM_SLV_IDX1;
        for (n = ns_region_start_id; n < ns_region_end_id; n++)
        {
            mbcBlockConfig.memoryBlockIdx = n;

            TRDC_MbcSetMemoryBlockConfig(TRDC4, &mbcBlockConfig);
        }

        mbcBlockConfig.slaveMemoryIdx = OCRAM_SLV_IDX2;
        for (n = ns_region_start_id; n < ns_region_end_id; n++)
        {
            mbcBlockConfig.memoryBlockIdx = n;

            TRDC_MbcSetMemoryBlockConfig(TRDC4, &mbcBlockConfig);
        }
    }
    else
    {
        return -1;
    }

	return 0;
}

int32_t mpc_init_cfg(void)
{
    int i;
    uint32_t ns_region_start = 0;
    uint32_t ns_region_end = 0;
    /*
     * Assumption:
     * TRDC is owned by Cortex A core. { TF-A has already requested ownership of Cortex A core from Sentinel/
     * Basic TRDC configuration for DID already done by TF-A.
     * Access permission for TRDC MGR and MC slots has been already set by TF-A
     * By default Tf-A sets all slaves permission to secure.
     * The configurations and tables below sets TRDC MBC NSE, to allow non secure access.
     */

    /* Configure TRDC MBC user settings from config table */
    for (i = 0U; i < ARRAY_SIZE(trdc_cfg_info); i++) {
        trdc_mbc_setup(&trdc_cfg_info[i]);
    }

    /* Code Region for NS priv/user access  */

    ns_region_start = memory_regions.non_secure_partition_base;      /* NS region start */
    ns_region_end = memory_regions.non_secure_partition_limit + 1;

	trdc_set_mbc_nse(ns_region_start, ns_region_end);

    /* Data Region for NS priv/user access */
    ns_region_start = NS_DATA_START;      /* NS region starts after S */
    ns_region_end = NS_DATA_START + NS_DATA_SIZE;

	trdc_set_mbc_nse(ns_region_start, ns_region_end);

    return ARM_DRIVER_OK;
}

/*---------------------- PPC configuration functions -------------------------*/

int32_t ppc_init_cfg(void)
{
	/* During mpc init, all peripherals were marked for access to non secure */

    return ARM_DRIVER_OK;
}

void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged)
{
    /* If the peripheral is not shared with non-secure world, give it SEC access */
    if (platform_data && platform_data->nseEnable == false)
    {
        trdc_mbc_memory_block_config_t mbcBlockConfig;

        (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));

        mbcBlockConfig.nseEnable  = false;

        mbcBlockConfig.domainIdx      = TRDC_GetCurrentMasterDomainId(TRDC4);
        mbcBlockConfig.mbcIdx = platform_data->mbcIdx;
        mbcBlockConfig.slaveMemoryIdx = platform_data->slaveMemoryIdx;
        mbcBlockConfig.memoryBlockIdx = platform_data->memoryBlockIdx;

        mbcBlockConfig.memoryAccessControlSelect = platform_data->glbacIdx;

        TRDC_MbcSetMemoryBlockConfig((TRDC_Type *)platform_data->trdc_base, &mbcBlockConfig);
    }
}


/* HARDENING_MACROS_ENABLED is defined*/
#ifdef HARDENING_MACROS_ENABLED
/* NOTE: __attribute__((used)) is used because IAR toolchain inline assembly
is not able to extern the function via MACRO defined in target_cfg_common.h*/
/* fault_detect handling function
 */
__attribute__((used)) static void fault_detect_handling(void)
{
    tfm_core_panic();
}
#endif

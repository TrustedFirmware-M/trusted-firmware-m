/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
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
#include "tfm_log.h"
#include "fsl_trdc.h"
#include "fsl_glikey.h"

extern const struct memory_region_limits memory_regions;

struct platform_data_t tfm_peripheral_std_uart = {
        LPUART1_BASE_NS,
        LPUART1_BASE_NS + 0xFFF,
        0,
        0
};

struct platform_data_t tfm_peripheral_timer0 = {
        CTIMER1_BASE,
        CTIMER1_BASE + 0xFFF,
};

const int glikey_index_mbc = 15;

/*******************************************************************************
 * Definitions
 ******************************************************************************/
static uint32_t APP_GetMbc0Mem0BlockIdx(const void* mem_ptr)
{
  uint32_t idx = (uint32_t)mem_ptr;
  const uint32_t shift = (MBC0->MBC_INDEX[0].MBC_MEM_GLBCFG[0] &
                          TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_MASK ) >>
                          TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT;
  const uint32_t nblks = (MBC0->MBC_INDEX[0].MBC_MEM_GLBCFG[0] &
                          TRDC_MBC_MEM_GLBCFG_NBLKS_MASK ) >>
                          TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS_SHIFT;

  /* Zero secure bit from address */
  idx &= ~0x10000000U;

  /* Shift by GLBCFG_NBLKS_LOG2*/
  idx >>= shift;

  /* Check if mem_ptr fits to MBC0_MEM0 */
  assert(idx < nblks);
  (void)nblks;
  return idx;
}

static void enable_mem_rule_for_partition(uint32_t memory_region_base, uint32_t memory_region_limit)
{
    uint32_t ns_region_id       = 0;
    uint32_t ns_region_start_id = 0;
    uint32_t ns_region_end_id   = 0;

    ns_region_start_id = (memory_region_base - NS_ROM_ALIAS_BASE) / FLASH_SUBREGION_SIZE;
    ns_region_end_id = ((memory_region_limit - NS_ROM_ALIAS_BASE) / FLASH_SUBREGION_SIZE) + 1;

    /* Set to non-secure and non-privileged user access allowed */
    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++) /* == Region 0 == */
    {
        if(ns_region_id < 8)
        {
            /* Set regions in the AHB controller for flash memory 0x00000000 - 0x0003FFFF */
            AHBSC->FLASH00_MEM_RULE[0] &= ~(0xF << (ns_region_id * 4));
        }
        else if((ns_region_id >= 8) && (ns_region_id < 16))
        {
            /* Set regions in the AHB controller for flash memory 0x00040000 - 0x0007FFFF */
            AHBSC->FLASH00_MEM_RULE[1] &= ~(0xF << ((ns_region_id - 8) * 4));
        }
        else if((ns_region_id >= 16) && (ns_region_id < 24))
        {
            /* Set regions the AHB controller for flash memory 0x00080000 - 0x000BFFFF */
            AHBSC->FLASH00_MEM_RULE[2] &= ~(0xF << ((ns_region_id - 16) * 4));
        }
        else if((ns_region_id >= 24) && (ns_region_id < 32))
        {
            /* Set regions the AHB controller for flash memory 0x000C0000 -  0x000FFFFF */
            AHBSC->FLASH00_MEM_RULE[3] &= ~(0xF << ((ns_region_id - 24) * 4));
        }
        else /* == Region 1 == */
        {
            if(ns_region_start_id > FLASH_REGION0_SUBREGION_NUMBER)
            {
                ns_region_start_id = (memory_region_base - NS_ROM_ALIAS_BASE - FLASH_REGION0_SIZE ) / FLASH_SUBREGION_SIZE;
            }
            else
            {
                ns_region_start_id = 0;
            }

            ns_region_end_id = ((memory_region_limit - NS_ROM_ALIAS_BASE - FLASH_REGION0_SIZE) / FLASH_SUBREGION_SIZE) + 1;

            for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
            {
                if(ns_region_id < 8)
                {
                    /* Set regions in the AHB controller for flash memory 0x00100000 - 0x0013FFFF */
                    AHBSC->FLASH01_MEM_RULE[0] &= ~(0xF << (ns_region_id*4));
                }
                else if((ns_region_id >= 8) && (ns_region_id < 16))
                {
                    /* Set regions in the AHB controller for flash memory 0x00140000 - 0x0017FFFF */
                    AHBSC->FLASH01_MEM_RULE[1] &= ~(0xF << ((ns_region_id-8)*4));
                }
                else if((ns_region_id >= 16) && (ns_region_id < 24))
                {
                    /* Set regions the AHB controller for flash memory 0x00180000 - 0x001BFFFF */
                    AHBSC->FLASH01_MEM_RULE[2] &= ~(0xF << ((ns_region_id-16)*4));
                }
                else if((ns_region_id >= 24) && (ns_region_id < 32))
                {
                    /* Set regions the AHB controller for flash memory 0x001C0000 -  0x001FFFFF */
                    AHBSC->FLASH01_MEM_RULE[3] &= ~(0xF << ((ns_region_id-24)*4));
                }
            }
        }
    }
}

/*------------------- Memory configuration functions -------------------------*/
static void trdc_configs(void)
{
    uint32_t ns_region_start_id = 0;
    uint32_t ns_region_end_id = 0;

    TRDC_Init(MBC0);

    /* Make the all flash region accessible. */
    *(volatile uint32_t *)0x500C9020 = 0x00007700;  /* GLBAC idx: 0, being configured to have only Sec Prv and Sec user access  */
    *(volatile uint32_t *)0x500C9030 = 0x00007777;  /* GLBAC idx: 4, being configured to have all type of access */
    *(volatile uint32_t *)0x500C9040 = 0x00000000;
    *(volatile uint32_t *)0x500C9044 = 0x00000000;
    *(volatile uint32_t *)0x500C9048 = 0x00000000;
    *(volatile uint32_t *)0x500C904C = 0x00000000;
    *(volatile uint32_t *)0x500C9050 = 0x00000000;
    *(volatile uint32_t *)0x500C9054 = 0x00000000;
    *(volatile uint32_t *)0x500C9058 = 0x00000000;
    *(volatile uint32_t *)0x500C905C = 0x00000000;

    /* 1. Set control policies for MBC access control configuration registers */
    trdc_memory_access_control_config_t memAccessConfig_sec;
    trdc_memory_access_control_config_t memAccessConfig_all;
    trdc_mbc_memory_block_config_t mbcBlockConfig;

    (void)memset(&memAccessConfig_sec, 0, sizeof(memAccessConfig_sec));
    (void)memset(&memAccessConfig_all, 0, sizeof(memAccessConfig_all));

    memAccessConfig_all.nonsecureUsrX  = 1U;
    memAccessConfig_all.nonsecureUsrW  = 1U;
    memAccessConfig_all.nonsecureUsrR  = 1U;
    memAccessConfig_all.nonsecurePrivX = 1U;
    memAccessConfig_all.nonsecurePrivW = 1U;
    memAccessConfig_all.nonsecurePrivR = 1U;
    memAccessConfig_all.secureUsrX     = 1U;
    memAccessConfig_all.secureUsrW     = 1U;
    memAccessConfig_all.secureUsrR     = 1U;
    memAccessConfig_all.securePrivX    = 1U;
    memAccessConfig_all.securePrivW    = 1U;
    memAccessConfig_all.securePrivR    = 1U;

    /* Enable secure priv and user access modes */
    memAccessConfig_sec.securePrivX    = 1U;
    memAccessConfig_sec.securePrivW    = 1U;
    memAccessConfig_sec.securePrivR    = 1U;
    memAccessConfig_sec.secureUsrX     = 1U;
    memAccessConfig_sec.secureUsrW     = 1U;
    memAccessConfig_sec.secureUsrR     = 1U;

    TRDC_MbcSetMemoryAccessConfig(MBC0, &memAccessConfig_sec, 0U, TRDC_ACCESS_CONTROL_POLICY_SEC_PRIV_INDEX);
    TRDC_MbcSetMemoryAccessConfig(MBC0, &memAccessConfig_all, 0U, TRDC_ACCESS_CONTROL_POLICY_NS_INDEX);

    /* 2. Set the configuration for the MBC slave 'Flash' as all SEC_PRIV by default */

    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
    mbcBlockConfig.memoryAccessControlSelect = TRDC_ACCESS_CONTROL_POLICY_SEC_PRIV_INDEX;
    mbcBlockConfig.nseEnable                 = false;
    mbcBlockConfig.mbcIdx                    = 0U; /* Only have one MBC */
    mbcBlockConfig.domainIdx                 = 0U; /* Only have one domain */
    mbcBlockConfig.slaveMemoryIdx            = MBC_SLAVE_FLASH;

    for (uint8_t i = 0U; i < 64U; i++)
    {
        mbcBlockConfig.memoryBlockIdx = i;
        TRDC_MbcSetMemoryBlockConfig(MBC0, &mbcBlockConfig);
    }

    /*Now, only flash regions of non-secure, shall be configured with NS access */
    /* The regions have to be alligned to FLASH_SUBREGION_SIZE to cover the AHB Flash Region. */
    assert(((memory_regions.non_secure_partition_base - NS_ROM_ALIAS_BASE) % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.non_secure_partition_limit - NS_ROM_ALIAS_BASE + 1) % FLASH_SUBREGION_SIZE) == 0);

    ns_region_start_id  = (memory_regions.non_secure_partition_base - NS_ROM_ALIAS_BASE)
                          / FLASH_SUBREGION_SIZE;
    ns_region_end_id    = ((memory_regions.non_secure_partition_limit - NS_ROM_ALIAS_BASE)
                          / FLASH_SUBREGION_SIZE) + 1;

    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
    mbcBlockConfig.memoryAccessControlSelect = TRDC_ACCESS_CONTROL_POLICY_NS_INDEX;
    /* MBC on this chip can't distinguish secure privilege, secure user, non-secure privilege, 
    and non- secure user, when there is an access to flash, and MBC treat all access to flash 
    as secure user level. Because of it, SUR/SUW/SUX bits in MBC Global Access Control registers
    control the permission to flash. User should not set the NonSecure Enable (NSE) bits in
    MBC Global Access Control registe */
    mbcBlockConfig.nseEnable                 = false;
    mbcBlockConfig.mbcIdx                    = 0U; /* Only have one MBC */
    mbcBlockConfig.domainIdx                 = 0U; /* Only have one domain */
    mbcBlockConfig.slaveMemoryIdx            = MBC_SLAVE_FLASH;

    for (uint8_t i = ns_region_start_id; i < ns_region_end_id; i++)
    {
        mbcBlockConfig.memoryBlockIdx = APP_GetMbc0Mem0BlockIdx((void*)(i*FLASH_SUBREGION_SIZE));
        TRDC_MbcSetMemoryBlockConfig(MBC0, &mbcBlockConfig);
    }

}

static void app_set_glikey_accessible(uint32_t idx)
{
    /* Use Glikey to enable modifications of MBC registers: */

    status_t status = GLIKEY_IsLocked(GLIKEY0);
    assert(kStatus_GLIKEY_NotLocked == status);

    status = GLIKEY_SyncReset(GLIKEY0);
    assert(kStatus_Success == status);

    status = GLIKEY_StartEnable(GLIKEY0, idx);
    assert(kStatus_Success == status);

    status = GLIKEY_ContinueEnable(GLIKEY0, GLIKEY_CODEWORD_STEP1);
    assert(kStatus_Success == status);

    status = GLIKEY_ContinueEnable(GLIKEY0, GLIKEY_CODEWORD_STEP2);
    assert(kStatus_Success == status);

    status = GLIKEY_ContinueEnable(GLIKEY0, GLIKEY_CODEWORD_STEP3);
    assert(kStatus_Success == status);

    status = GLIKEY_ContinueEnable(GLIKEY0, GLIKEY_CODEWORD_STEP_EN);
    assert(kStatus_Success == status);

    (void)status; /* In case of release build there is not assert. */
}

int32_t mpc_init_cfg(void)
{
    uint32_t ns_region_id = 0;
    uint32_t ns_region_start_id = 0;
    uint32_t ns_region_end_id = 0;
    int i;

    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

    /* Configuration of AHB Secure Controller
     * Possible values for every memory sector or peripheral rule:
     *  0    Non-secure, user access allowed.
     *  1    Non-secure, privileged access allowed.
     *  2    Secure, user access allowed.
     *  3    Secure, privileged access allowed. */

    /* == On-Chip Flash region == */
    /* Flash region has 2 MB of Flash, It is divided into 32 sub-regions (sector). Each flash sub-regions (sector) is 16 kbytes. */
    /* Two other banks are 32 KB (IFR0) and 8 KB. Each divided into 4 sub-regions (sectro) with sub-region size of 8 KB and 2KB respectively.*/
    /* 1) Set FLASH memory security access rule configuration to init value (0x3 = all regions set to secure and privileged user access) */
    for(i = 0; i < 4; i++)
    {
         AHBSC->FLASH00_MEM_RULE[i] = 0x33333333U;    /* 0x00000000 - 0x000FFFFF*/
         AHBSC->FLASH01_MEM_RULE[i] = 0x33333333U;    /* 0x00100000 - 0x001FFFFF*/
    }

    AHBSC->FLASH02_MEM_RULE = 0x33333333U;  /* 0x01000000 - 0x0100FFFF */
    AHBSC->FLASH03_MEM_RULE = 0x33333333U;  /* 0x01100000 - 0x01103FFF */

    /* 2) Set FLASH memory security access rule configuration (set to non-secure and non-privileged user access allowed).*/

    /* == Region 0 == */
    /* The regions have to be aligned to FLASH_SUBREGION_SIZE to cover the AHB Flash Region. */
    assert(((memory_regions.non_secure_partition_base - NS_ROM_ALIAS_BASE) % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.non_secure_partition_limit - NS_ROM_ALIAS_BASE + 1) % FLASH_SUBREGION_SIZE) == 0);

    enable_mem_rule_for_partition(memory_regions.non_secure_partition_base, memory_regions.non_secure_partition_limit);

#ifdef NXP_NS_STORAGE
    enable_mem_rule_for_partition(NXP_FLASH_NS_STORAGE_OFFSET,
                                  NXP_FLASH_NS_STORAGE_OFFSET + NXP_FLASH_NS_STORAGE_SIZE - 1U);
#endif /* NXP_NS_STORAGE */

#ifdef BL2 /* Set secondary image region to NS, when BL2 is enabled */
    /* The regions have to be alligned to 32 kB to cover the AHB Flash Region. */
    assert(memory_regions.secondary_partition_base >= NS_ROM_ALIAS_BASE);
    assert(((memory_regions.secondary_partition_base - NS_ROM_ALIAS_BASE) % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.secondary_partition_limit - NS_ROM_ALIAS_BASE + 1) % FLASH_SUBREGION_SIZE)
               == 0);
    enable_mem_rule_for_partition(memory_regions.secondary_partition_base, memory_regions.secondary_partition_limit);

#endif
    /* == ROM region == */
    /* Each ROM sector is 1 kbytes. There are 32 ROM sectors in total. */
    /* Security control ROM memory configuration (0x3 = all regions set to secure and privileged user access). */
    for(i=0; i < 4; i++)
    {
         AHBSC->ROM_MEM_RULE[i] = 0x33333333U; /* 0x0300_0000 - 0x0303_FFFF */
    }

    /* == RAMX region == */

    /* Each RAMX sub region is 2 kbytes. There are 8 such regions*/
    /* Security access rules for RAMX (0x3 = all regions set to secure and privileged user access). */
    for(i=0; i < AHBSC_RAMX_MEM_RULE0_COUNT; i++)
    {
        AHBSC->RAMX_MEM_RULE[i] = 0x33333333U; /* 0x0400_0000 - 0x0401_FFFF */
    }

    /* == SRAM region == */

    /* The regions have to be aligned to 4 kB to cover the AHB RAM Region */
    assert((S_DATA_SIZE % DATA_SUBREGION_SIZE) == 0);
    assert(((S_DATA_SIZE + NS_DATA_SIZE) % DATA_SUBREGION_SIZE) == 0);

    /* Security access rules for RAMA (0x3 = all regions set to secure and privileged user access*/
    for(i=0; i < AHBSC_RAMA_MEM_RULE_COUNT; i++)
    {
        AHBSC->RAMA_MEM_RULE[i] = 0x33333333U; /* 0x20000000 - 0x2003FFFF */
    }

    /* Security access rules for RAMB (0x3 = all regions set to secure and privileged user access*/
    for(i=0; i < AHBSC_RAMB_MEM_RULE_COUNT; i++)
    {
        AHBSC->RAMB_MEM_RULE[i] = 0x33333333U; /* 0x20040000 - 0x2007FFFF */
    }

    /* SRAM memory configuration (set according to region_defs.h and flash_layout.h) */
    /* == SRAM Region A8 - SRAM B7 (0-32KB) == */
    ns_region_start_id  = (NS_DATA_START - NS_RAM_ALIAS_BASE) / DATA_SUBREGION_SIZE; /* NS starts after S */
    ns_region_end_id  = (NS_DATA_START - NS_RAM_ALIAS_BASE + NS_DATA_SIZE) / DATA_SUBREGION_SIZE;

    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
    {
        /* RAMA*/
        if (ns_region_id <8) {
             AHBSC->RAMA_MEM_RULE[0] &= ~(0xF << ((ns_region_id)*4));
        }
        else if((ns_region_id >= 8) && (ns_region_id < 16)) {
             AHBSC->RAMA_MEM_RULE[1] &= ~(0xF << ((ns_region_id-8)*4));
        }
        else if((ns_region_id >= 16) && (ns_region_id < 24)) {
             AHBSC->RAMA_MEM_RULE[2] &= ~(0xF << ((ns_region_id-16)*4));
        }
        else if((ns_region_id >= 24) && (ns_region_id < 32)) {
             AHBSC->RAMA_MEM_RULE[3] &= ~(0xF << ((ns_region_id-24)*4));
        }
        else if((ns_region_id >= 32) && (ns_region_id < 40)) {
             AHBSC->RAMA_MEM_RULE[4] &= ~(0xF << ((ns_region_id-32)*4));
        }
        else if((ns_region_id >= 40) && (ns_region_id < 48)) {
             AHBSC->RAMA_MEM_RULE[5] &= ~(0xF << ((ns_region_id-40)*4));
        }
        else if((ns_region_id >= 48) && (ns_region_id < 56)) {
             AHBSC->RAMA_MEM_RULE[6] &= ~(0xF << ((ns_region_id-48)*4));
        }
        else if((ns_region_id >= 56) && (ns_region_id < 64)) {
             AHBSC->RAMA_MEM_RULE[7] &= ~(0xF << ((ns_region_id-56)*4));
        }

        /* RAMB*/
        else if((ns_region_id >= 64) && (ns_region_id < 72)) {
             AHBSC->RAMB_MEM_RULE[0] &= ~(0xF << ((ns_region_id-64)*4));
        }
        else if((ns_region_id >= 72) && (ns_region_id < 80)) {
             AHBSC->RAMB_MEM_RULE[1] &= ~(0xF << ((ns_region_id-72)*4));
        }
        else if((ns_region_id >= 80) && (ns_region_id < 88)) {
             AHBSC->RAMB_MEM_RULE[2] &= ~(0xF << ((ns_region_id-80)*4));
        }
        else if((ns_region_id >= 88) && (ns_region_id < 96)) {
             AHBSC->RAMB_MEM_RULE[3] &= ~(0xF << ((ns_region_id-88)*4));
        }
        else if((ns_region_id >= 96) && (ns_region_id < 104)) {
             AHBSC->RAMB_MEM_RULE[4] &= ~(0xF << ((ns_region_id-96)*4));
        }
        else if((ns_region_id >= 104) && (ns_region_id < 112)) {
             AHBSC->RAMB_MEM_RULE[5] &= ~(0xF << ((ns_region_id-104)*4));
        }
        else if((ns_region_id >= 112) && (ns_region_id < 120)) {
             AHBSC->RAMB_MEM_RULE[6] &= ~(0xF << ((ns_region_id-112)*4));
        }
        else if((ns_region_id >= 120) && (ns_region_id < 128)) {
             AHBSC->RAMB_MEM_RULE[7] &= ~(0xF << ((ns_region_id-120)*4));
        }
    }

#if TARGET_DEBUG_LOG
    VERBOSE_RAW("=== [AHB MPC NS] =======\n");
    VERBOSE_RAW("NS ROM starts from : 0x%08x\n",
                                      memory_regions.non_secure_partition_base);
    VERBOSE_RAW("NS ROM ends at : 0x%08x\n",
                                      memory_regions.non_secure_partition_base +
                                     memory_regions.non_secure_partition_limit);
    VERBOSE_RAW("NS DATA start from : 0x%08x\n", NS_DATA_START);
    VERBOSE_RAW("NS DATA ends at : 0x%08x\n", NS_DATA_START + NS_DATA_LIMIT);
#endif

    /* Add barriers to assure the MPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    return ARM_DRIVER_OK;
}

/*---------------------- PPC configuration functions -------------------------*/
int32_t ppc_init_cfg(void)
{

    /* Configuration of AHB Secure Controller. Grant user access to peripherals.
    * Possible values for every memory sector or peripheral rule:
    *  0    Non-secure, user access allowed.
    *  1    Non-secure, privileged access allowed.
    *  2    Secure, user access allowed.
    *  3    Secure, privileged access allowed. */

    /* Write access attributes for AHBSC module are tier-4 (secure privileged). */
    AHBSC->APB_PERIPHERAL_GROUP0_MEM_RULE0 =
       (0x00000003U) |
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0(0x0U)   |     /* Standard counter/Timer 0 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1(0x0U)   |     /* Standard counter/Timer 1 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2(0x0U)   |     /* Standard counter/Timer 2 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER3(0x0U)   |     /* Standard counter/Timer 3 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX(0x0U)  |     /* INPUTMUX */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C0(0x0U)      |     /* I3C0 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_I3C1(0x0U);           /* I3C1 */

    AHBSC->APB_PERIPHERAL_GROUP0_MEM_RULE1 =
       (0x30000300U) |
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER4(0x0U)   |     /* CTIMER4 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME(0x0U)    |     /* FREQME */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK(0x0U)     |     /* UTICK */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0(0x0U)     |     /* WWDT0 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT1(0x0U)     |     /* WWDT1 */
       AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_SMARTDMA(0x0U);       /* SMARTDMA */


    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE0 =
       (0x00000000U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_EWM0(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_ROMCP(0x3U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PKC0(0x3U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_MP(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH0(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH1(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH2(0x0U)  |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_DMA_1_CH3(0x0U)  ;

    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE1 =
       (0x03003333U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_0(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ENET0_1(0x0U) |
       AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_eSPI(0x0U);

    AHBSC->AIPS_BRIDGE_GROUP1_MEM_RULE0 =
      (0x33300000U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_FLEXSPI0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI4(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_LPSPI5(0x0U);

    AHBSC->AIPS_BRIDGE_GROUP1_MEM_RULE1 =
      (0x00003333U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_SPI_FILETER0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_T1S0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_USB1_PHY(0x0U);

     AHBSC->AHB_SECURE_CTRL_MEM_RULE0 =
      (0x33330000U) |
      AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE0(0x0U) |
      AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE1(0x0U) |
      AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE2(0x0U) |
      AHBSC_AHB_SECURE_CTRL_MEM_RULE0_RULE3(0x0U);

    AHBSC->AHB_PERIPHERAL0_MEM_RULE1 =
      (0x33333300U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0(0x0U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE1_GPIO0_ALIAS(0x0U);

    AHBSC->AHB_PERIPHERAL0_MEM_RULE2 =
      (0x33333300U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1(0x0U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE2_GPIO1_ALIAS(0x0U);

    AHBSC->AHB_PERIPHERAL0_MEM_RULE3 =
      (0x33333300U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2(0x0U) |
      AHBSC_AHB_PERIPHERAL0_MEM_RULE3_GPIO2_ALIAS(0x0U);

    AHBSC->AHB_PERIPHERAL0_MEM_RULE4 =
     (0x33333300U) |
     AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3(0x0U) |
     AHBSC_AHB_PERIPHERAL0_MEM_RULE4_GPIO3_ALIAS(0x0U);

    AHBSC->AHB_PERIPHERAL0_MEM_RULE5 =
     (0x33333300U) |
     AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4(0x0U) |
     AHBSC_AHB_PERIPHERAL0_MEM_RULE5_GPIO4_ALIAS(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE0 =
      (0x00000000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_MP(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH4(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH5(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_DMA_0_CH6(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE1 =
      (0x33300000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH7(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH8(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH9(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH10(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_DMA_0_CH11(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE2 =
      (0x33000003U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_SYSCON(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_WUU(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_VBAT(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMC(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_FMU(0x0U);


     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE3 =
      (0x00000003U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_FLEXIO(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPI2C1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPSPI1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_I3C2(0x0U)   |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_LPUART0(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE4 =
      (0x33330000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE4_LPUART4(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE5 =
      (0x00030333U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_LPTMR(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_OSTIMER(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_WAKE_TIMER(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE5_ADC0(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE6 =
      (0x33003300U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_ADC1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_CMP0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE6_DAC1(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE7 =
      (0x00000333U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_VREF0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE7_PORT3(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE8 =
      (0x00000330U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_PORT4(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_TSI0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_AOI0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CRC0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_CMC(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE8_EIM(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE9 =
      (0x00000000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_ERM(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_MBC(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SCG(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_SPC(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE9_CAN0_REGION3(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE10 =
      (0x30000000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION0(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION1(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_CAN1_REGION3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C2(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE10_LPI2C4(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE11 =
      (0x00330033U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_LPUART5(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_I3C3(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE11_GPIO5(0x0U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE12 =
      (0x03030330U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_GPIO5_ALIAS(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_PORT5(0x0U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_DGDET0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE12_ITRC0(0x3U);

     AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE13 =
      (0x30000000U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_GLIKEY0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TDET0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SECCON(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_SGI0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_TRNG0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_UDF0(0x3U) |
      AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE13_RTC0(0x0U);

     AHBSC->FLEXSPI0_REGION0_MEM_RULE[0] =
      (0x00000000U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7(0x0U);

     AHBSC->FLEXSPI0_REGION0_MEM_RULE[1] =
      (0x00000000U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7(0x0U);

     AHBSC->FLEXSPI0_REGION0_MEM_RULE[2] =
      (0x00000000U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7(0x0U);

     AHBSC->FLEXSPI0_REGION0_MEM_RULE[3] =
      (0x00000000U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE3(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE4(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE5(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE6(0x0U) |
      AHBSC_FLEXSPI0_REGION0_MEM_RULE_RULE7(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[0].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[1].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[2].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[3].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[4].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

     AHBSC->FLEXSPI0_REGION1_6_MEM_RULE[5].FLEXSPI0_REGION_MEM_RULE =
      (0x00003333U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE0(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE1(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE2(0x0U) |
      AHBSC_FLEXSPI0_REGION1_6_MEM_RULE_FLEXSPI0_REGION_MEM_RULE_RULE3(0x0U);

    /* TRDC- MBC0 configs*/
    app_set_glikey_accessible(glikey_index_mbc);
    trdc_configs();

     /* CPU Lock register*/
    AHBSC->CPU0_LOCK_REG = 0x000002AAU;

    /* Set Master Security Level of PKC and ELS Security Level to secure and privileged master, and lock it. */
    SECURE_READ_MODIFY_WRITE_REGISTER(&( AHBSC->MASTER_SEC_LEVEL),
        ~(AHBSC_MASTER_SEC_LEVEL_DMA0_MASK       |
          AHBSC_MASTER_SEC_LEVEL_DMA1_MASK       |
          AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK   |
          AHBSC_MASTER_SEC_LEVEL_ENET0_MASK      |
          AHBSC_MASTER_SEC_LEVEL_USB1_MASK       |
          AHBSC_MASTER_SEC_LEVEL_PKC_MASK ),
         (AHBSC_MASTER_SEC_LEVEL_DMA0(0x0U)      |
          AHBSC_MASTER_SEC_LEVEL_DMA1(0x0U)      |
          AHBSC_MASTER_SEC_LEVEL_SMARTDMA(0x0U)  |
          AHBSC_MASTER_SEC_LEVEL_ENET0(0x0U)     |
          AHBSC_MASTER_SEC_LEVEL_USB1(0x0U)      |
          AHBSC_MASTER_SEC_LEVEL_PKC(0x3U)));                              /* PKC */

    /* Set the corresponding ANTI POL register */
    SECURE_READ_MODIFY_WRITE_REGISTER((&( AHBSC->MASTER_SEC_ANTI_POL_REG)),
        ~(AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_MASK       |
          AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_MASK       |
          AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK   |
          AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0_MASK      |
          AHBSC_MASTER_SEC_ANTI_POL_REG_USB1_MASK       |
          AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK ),
         ~(AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0(0x0U)      |
          AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1(0x0U)      |
          AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA(0x0U)  |
          AHBSC_MASTER_SEC_ANTI_POL_REG_ENET0(0x0U)     |
          AHBSC_MASTER_SEC_ANTI_POL_REG_USB1(0x0U)      |
          AHBSC_MASTER_SEC_ANTI_POL_REG_PKC(0x3U)));                              /* PKC */

    /* Update AHB Secure control register */
    SECURE_READ_MODIFY_WRITE_REGISTER(&( AHBSC->MISC_CTRL_REG),
        ~(AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK                |
          AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK    |
          AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK       |
          AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK      |
          AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK   |
          AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK       |
          AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK               ),
         (AHBSC_MISC_CTRL_REG_WRITE_LOCK              (0x2U) |         /* 2 = Writes to this register and to the Memory and Peripheral RULE registers are allowed */
          AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING  (0x1U) |         /* 1 = Enable Secure Checking (restrictive mode) */
          AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK     (0x2U) |         /* 2 = Disabled Secure Privilege Checking */
          AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK    (0x2U) |         /* 2 = Disabled Non-Secure Privilege Checking */
          AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT (0x2U) |         /* 2 = The violation detected by the secure checker will cause an abort. */
          AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE     (0x1U) |         /* 1 = AHB master in tier mode. Can read and write to memories at same or below level. */
          AHBSC_MISC_CTRL_REG_IDAU_ALL_NS             (0x2U)));        /* 2 = IDAU is enabled (restrictive mode) */

    /* Secure control duplicate register */
    SECURE_READ_MODIFY_WRITE_REGISTER(&( AHBSC->MISC_CTRL_DP_REG),
        ~(AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK                |
          AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK    |
          AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK       |
          AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK      |
          AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK   |
          AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK       |
          AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK               ),
         (AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK              (0x2U) |      /* 2 = Writes to this register and to the Memory and Peripheral RULE registers are allowed */
          AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING  (0x1U) |      /* 1 = Enable Secure Checking (restrictive mode) */
          AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK     (0x2U) |      /* 2 = Disabled Secure Privilege Checking */
          AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK    (0x2U) |      /* 2 = Disabled Non-Secure Privilege Checking */
          AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT (0x2U) |      /* 2 = The violation detected by the secure checker will cause an abort. */
          AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE     (0x1U) |      /* 1 = AHB master in tier mode. Can read and write to memories at same or below level. */
          AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS             (0x2U)));     /* 2 = IDAU is enabled (restrictive mode) */

    return ARM_DRIVER_OK;
}

void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged)
{

}

/* HARDENING_MACROS_ENABLED is defined*/
#ifdef HARDENING_MACROS_ENABLED
/* NOTE: __attribute__((used)) is used because IAR toolchain inline assembly
is not able to extern the function via MACRO defined in target_cfg_common.h*/
/* fault_detect handling function
 */
__attribute__((used)) static void fault_detect_handling(void)
{
    VERBOSE_RAW("fault detected during secure REG write!!\n");
    tfm_core_panic();
}
#endif

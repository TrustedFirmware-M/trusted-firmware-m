/*
 * Copyright (c) 2018-2022 Arm Limited. All rights reserved.
 * Copyright 2019-2026 NXP
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

extern const struct memory_region_limits memory_regions;

struct platform_data_t tfm_peripheral_std_uart = {
        LPUART4_BASE_NS,
        LPUART4_BASE_NS + 0xFFF,
        0,
        0
};

struct platform_data_t tfm_peripheral_timer0 = {
        CTIMER2_BASE,
        CTIMER2_BASE + 0xFFF
};

void enable_mem_rule_for_partition(uint32_t memory_region_base, uint32_t memory_region_limit)
{
    uint32_t ns_region_id       = 0;
    uint32_t ns_region_start_id = 0;
    uint32_t ns_region_end_id   = 0;
        
    ns_region_start_id = (memory_region_base - NS_ROM_ALIAS_BASE) / FLASH_SUBREGION_SIZE;
    ns_region_end_id = (memory_region_limit - NS_ROM_ALIAS_BASE / FLASH_SUBREGION_SIZE) + 1;

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
    /* Flash region has 2 banks, each 1 MB and each is divided into 32 sub-regions (sector). Each flash sub-regions (sector) is 32 kbytes. */
    /* 0x0000 0000 to 0x001F FFFF 2 MB
            Region 0: 1 MB (32 * 32 KB)
            Region 1: 1 MB (32 * 2 MB) */

    /* 1) Set FLASH memory security access rule configuration to init value (0x3 = all regions set to secure and privileged user access) */
    for(i = 0; i < 4; i++)
    {
        AHBSC->FLASH00_MEM_RULE[i] = 0x33333333U;
        AHBSC->FLASH01_MEM_RULE[i] = 0x33333333U;
    }

    /* 2) Set FLASH memory security access rule configuration (set to non-secure and non-privileged user access allowed).*/

    /* == Region 0 == */
    /* The regions have to be alligned to FLASH_SUBREGION_SIZE to cover the AHB Flash Region. */
    assert(((memory_regions.non_secure_partition_base - NS_ROM_ALIAS_BASE) % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.non_secure_partition_limit - NS_ROM_ALIAS_BASE + 1) % FLASH_SUBREGION_SIZE) == 0);

    enable_mem_rule_for_partition(memory_regions.non_secure_partition_base, memory_regions.non_secure_partition_limit);

#ifdef TFM_EL2GO_DATA_IMPORT_REGION
	enable_mem_rule_for_partition(memory_regions.el2go_data_import_region_base, memory_regions.el2go_data_import_region_limit);
#endif /* TFM_EL2GO_DATA_IMPORT_REGION */

#ifdef TFM_EL2GO_CMPA_REGION
	enable_mem_rule_for_partition(memory_regions.el2go_cmpa_region_base, memory_regions.el2go_cmpa_region_limit);
#endif /* TFM_EL2GO_CMPA_REGION */

#ifdef BL2 /* Set secondary image region to NS, when BL2 is enabled */
    /* The regions have to be alligned to 32 kB to cover the AHB Flash Region. */
    assert(memory_regions.secondary_partition_base >= NS_ROM_ALIAS_BASE);
    assert(((memory_regions.secondary_partition_base - NS_ROM_ALIAS_BASE) % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.secondary_partition_limit - NS_ROM_ALIAS_BASE + 1) % FLASH_SUBREGION_SIZE)
               == 0);
    enable_mem_rule_for_partition(memory_regions.secondary_partition_base, memory_regions.secondary_partition_limit);

#endif

    /* == ROM region == */

    /* Each ROM sector is 8 kbytes. There are 32 ROM sectors in total. */
    /* Security control ROM memory configuration (0x3 = all regions set to secure and privileged user access). */
    for(i=0; i < 4; i++)
    {
        AHBSC->ROM_MEM_RULE[i] = 0x33333333U;
    }

    /* == RAMX region == */

    /* Each RAMX sub region is 4 kbytes. There are 24 such regions*/
    /* Security access rules for RAMX (0x3 = all regions set to secure and privileged user access). */
    for(i=0; i < 3; i++)
    {
        AHBSC->RAMX_MEM_RULE[i] = 0x33333333U; /* 0x0400_0000 - 0x0401_7FFF */
    }

    /* == SRAM region == */

    /* The regions have to be alligned to 4 kB to cover the AHB RAM Region */
    assert((S_DATA_SIZE % DATA_SUBREGION_SIZE) == 0);
    assert(((S_DATA_SIZE + NS_DATA_SIZE) % DATA_SUBREGION_SIZE) == 0);

    /* Security access rules for RAM (0x3 = all regions set to secure and privileged user access*/
    
    AHBSC->RAMA_MEM_RULE = 0x33333333U; /* 0x2000_0000 - 0x2000_7FFF */
    AHBSC->RAMB_MEM_RULE = 0x33333333U; /* 0x2000_8000 - 0x2000_FFFF */
    AHBSC->RAMC_MEM_RULE[0] = 0x33333333U; /* 0x2001_0000 - 0x2001_7FFF */
    AHBSC->RAMC_MEM_RULE[1] = 0x33333333U; /* 0x2001_8000 - 0x2001_FFFF */
    AHBSC->RAMD_MEM_RULE[0] = 0x33333333U; /* 0x2002_0000 - 0x2002_7FFF */
    AHBSC->RAMD_MEM_RULE[1] = 0x33333333U; /* 0x2002_8000 - 0x2002_FFFF */
    AHBSC->RAME_MEM_RULE[0] = 0x33333333U; /* 0x2003_0000 - 0x2003_7FFF */
    AHBSC->RAME_MEM_RULE[1] = 0x33333333U; /* 0x2003_8000 - 0x2003_FFFF */
    AHBSC->RAMF_MEM_RULE[0] = 0x33333333U; /* 0x2004_0000 - 0x2004_7FFF */
    AHBSC->RAMF_MEM_RULE[1] = 0x33333333U; /* 0x2004_8000 - 0x2004_FFFF */
    AHBSC->RAMG_MEM_RULE[0] = 0x33333333U; /* 0x2005_0000 - 0x2005_7FFF */
    AHBSC->RAMG_MEM_RULE[1] = 0x33333333U; /* 0x2005_8000 - 0x2005_FFFF */
    AHBSC->RAMH_MEM_RULE = 0x33333333U; /* 0x2006_0000 - 0x2006_7FFF */

    /* SRAM memory configuration (set according to region_defs.h and flash_layout.h) */
    /* == SRAM Region 0 (0-32KB) == */
    ns_region_start_id  = (NS_DATA_START - NS_RAM_ALIAS_BASE) / DATA_SUBREGION_SIZE; /* NS starts after S */
    ns_region_end_id  = (NS_DATA_START - NS_RAM_ALIAS_BASE + NS_DATA_SIZE) / DATA_SUBREGION_SIZE;

    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
    {
        if(ns_region_id < 8) {
            AHBSC->RAMA_MEM_RULE &= ~(0xF << (ns_region_id*4));
        }
        else if((ns_region_id >= 8) && (ns_region_id < 16)) {
            AHBSC->RAMB_MEM_RULE &= ~(0xF << ((ns_region_id-8)*4));
        }
        else if((ns_region_id >= 16) && (ns_region_id < 24)) {
            AHBSC->RAMC_MEM_RULE[0] &= ~(0xF << ((ns_region_id-16)*4));
        }
        else if((ns_region_id >= 24) && (ns_region_id < 32)) {
            AHBSC->RAMC_MEM_RULE[1] &= ~(0xF << ((ns_region_id-24)*4));
        }
        else if((ns_region_id >= 32) && (ns_region_id < 40)) {
            AHBSC->RAMD_MEM_RULE[0] &= ~(0xF << ((ns_region_id-32)*4));
        }
        else if((ns_region_id >= 40) && (ns_region_id < 48)) {
            AHBSC->RAMD_MEM_RULE[1] &= ~(0xF << ((ns_region_id-40)*4));
        }
        else if((ns_region_id >= 48) && (ns_region_id < 56)) {
            AHBSC->RAME_MEM_RULE[0] &= ~(0xF << ((ns_region_id-48)*4));
        }
        else if((ns_region_id >= 56) && (ns_region_id < 64)) {
            AHBSC->RAME_MEM_RULE[1] &= ~(0xF << ((ns_region_id-56)*4));
        }
        else if((ns_region_id >= 64) && (ns_region_id < 72)) {
            AHBSC->RAMF_MEM_RULE[0] &= ~(0xF << ((ns_region_id-64)*4));
        }
        else if((ns_region_id >= 72) && (ns_region_id < 80)) {
            AHBSC->RAMF_MEM_RULE[1] &= ~(0xF << ((ns_region_id-72)*4));
        }
        else if((ns_region_id >= 80) && (ns_region_id < 88)) {
            AHBSC->RAMG_MEM_RULE[0] &= ~(0xF << ((ns_region_id-80)*4));
        }
        else if((ns_region_id >= 88) && (ns_region_id < 96)) {
            AHBSC->RAMG_MEM_RULE[1] &= ~(0xF << ((ns_region_id-88)*4));
        }
        else if((ns_region_id >= 96) && (ns_region_id < 104)) {
            AHBSC->RAMH_MEM_RULE &= ~(0xF << ((ns_region_id-96)*4));
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
        (0x30303330U) |          
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON(0x0U) |                               /* System configuration */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0(0x0U) |                                /* PINT0 */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX(0x0U);                                 /* INPUTMUX */

    AHBSC->APB_PERIPHERAL_GROUP0_MEM_RULE1 =
        (0x00003333U) |  
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0(0x0U) |                              /* Standard counter/Timer 0 */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1(0x0U) |                              /* Standard counter/Timer 1 */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER2(0x0U) |                              /* Standard counter/Timer 2 */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER3(0x0U);                                /* Standard counter/Timer 3 */

    AHBSC->APB_PERIPHERAL_GROUP0_MEM_RULE2 =
        (0x00300000U) |  
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_CTIMER4(0x0U) |                          /* Standard counter/Timer 4 */
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_FREQME0(0x0U) |
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_UTCIK0(0x0U) |        
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_MRT0(0x0U) |    
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT0(0x0U) |      
        AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE2_WWDT1(0x0U);       
        
    AHBSC->APB_PERIPHERAL_GROUP0_MEM_RULE3 =
      (0x33330333U) |  
      AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE3_CACHE64_POLSEL0(0x0U);               

    AHBSC->APB_PERIPHERAL_GROUP1_MEM_RULE0 =
        (0x30033003U) |
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C0(0x0U) |                                
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_I3C1(0x0U) |
          AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_GDET(0x3U) |    /* GDET */
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE0_ITRC(0x3U);       /* ITRC */                      

    AHBSC->APB_PERIPHERAL_GROUP1_MEM_RULE1 =                    /* Changing to 0x0 */
        (0x00000333U) |
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC(0x3U) |                              
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS0(0x3U) |                             
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS1(0x3U) |     
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS2(0x3U) |                           
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE1_PUF_ALIAS3(0x3U);

    AHBSC->APB_PERIPHERAL_GROUP1_MEM_RULE2 =
        (0x33000333U) |
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_COOLFLUX(0x0U) |                   
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_SMARTDMA(0x0U) |                     
        AHBSC_APB_PERIPHERAL_GROUP1_MEM_RULE2_PLU(0x0U);                            

    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE0 =
        (0x00000000U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS0(0x0U) |                   
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_GPIO5_ALIAS1(0x0U) |              
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_PORT5(0x0U) |                          
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_FMU0(0x0U) |                          
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SCG0(0x0U) |                          
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_SPC0(0x0U) |                           
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_WUU0(0x0U) |                           
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_TRO0(0x0U);                                  

    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE1 =
        (0x30300033U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR0(0x0U) |                      
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_LPTMR1(0x0U) |                    
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_RTC(0x0U) |                    
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_FMU_TEST(0x0U);
 
    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE2 =
        (0x00000000U) |        
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_TSI(0x0U) |                        
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP0(0x0U) |                          
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP1(0x0U) |                    
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_CMP2(0x0U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS(0x3U) |          /* ELS */
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS1(0x3U) |   /* ELS Alias1 */
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS2(0x3U) |   /* ELS Alias 2 */
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_ELS_ALIAS3(0x3U);    /* ELS Alias 3 */
    
    AHBSC->AIPS_BRIDGE_GROUP0_MEM_RULE3 =
        (0x33000300U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_DIGTMP(0x0U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_VBAT(0x0U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_TRNG(0x3U) |         /* TRNG */
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_EIM0(0x0U) |
        AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_INTM0(0x0U);
    
    AHBSC->AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0 =
        (0x00000003U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_EDMA0_CH15(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_SCT0(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM0(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM1(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM2(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_LP_FLEXCOMM3(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE0_GPIO0_ALIAS0(0x0U);

          
    AHBSC->AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1 =
        (0x00000000U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO0_ALIAS1(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS0(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO1_ALIAS1(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS0(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO2_ALIAS1(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS0(0x0U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE1_GPIO3_ALIAS1(0x0U);      
      
      
    AHBSC->AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2 =
        (0x33333330U) |
        AHBSC_AHB_PERIPHERAL0_SLAVE_PORT_P12_SLAVE_RULE2_GPIO4_ALIAS1(0x0U);
      
    AHBSC->AIPS_BRIDGE_GROUP1_MEM_RULE0 =
        (0x00000000U) |
        AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_MP(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH3(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH4(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH5(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE0_EDMA0_CH6(0x0U);

    
    AHBSC->AIPS_BRIDGE_GROUP1_MEM_RULE1 =
        (0x00000000U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH7(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH8(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH9(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH10(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH11(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH12(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH13(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP1_MEM_RULE1_EDMA0_CH14(0x0U);

      
    AHBSC->AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0 =
        (0x00000003U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_EDMA1_CH15(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_SEMA42(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_MAILBOX(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_PKC_RAM(0x3U) |        /* PKC RAM */
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM4(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM5(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE0_FLEXCOMM6(0x0U);
           
    AHBSC->AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1 =
        (0x00000000U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM7(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM8(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_FLEXCOMM9(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_USB_FS_OTG_RAM(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG0(0x3U) |          /* CDOG0 */
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_CDOG1(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_DEBUG_MAILBOX(0x0U) |
	AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE1_NPU(0x0U);
         
    AHBSC->AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2 =
        (0x33333330U) |
        AHBSC_AHB_PERIPHERAL1_SLAVE_PORT_P13_SLAVE_RULE2_POWERQUAD(0x0U);
    
    AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE0 = 
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_MP(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH3(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH4(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH5(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_EDMA1_CH6(0x0U);      
      
    AHBSC->AIPS_BRIDGE_GROUP2_MEM_RULE1 =
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH7(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH8(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH9(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH10(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH11(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH12(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH13(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_EDMA1_CH14(0x0U);
      
    AHBSC->AIPS_BRIDGE_GROUP3_MEM_RULE0 =
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_EWM0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_LPCAC(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_FLEXSPI_CMX(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_SFA(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MBC(0x3U);           /* MBC */
        
    AHBSC->AIPS_BRIDGE_GROUP3_MEM_RULE1 =
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_FLEXSPI(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_OTPC(0x3U) |         /* OTPC */
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_CRC(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_NPX(0x3U) |          /* NPX */
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_PWM(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE1_ENC(0x0U);
        
    AHBSC->AIPS_BRIDGE_GROUP3_MEM_RULE2 =
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PWM1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_ENC1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_EVTG(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_CAN0_RULE3(0x0U);
     
    AHBSC->AIPS_BRIDGE_GROUP3_MEM_RULE3 =
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_CAN1_RULE3(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBDCD(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_USBFS(0x0U);
      
    AHBSC->AIPS_BRIDGE_GROUP4_MEM_RULE0 = 
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_ENET(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_EMVSIM1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_FLEXIO(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE0_SAI1(0x0U);
      
    AHBSC->AIPS_BRIDGE_GROUP4_MEM_RULE1 = 
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_SINC0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USDHC0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHSPHY(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_USBHS(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_MICD(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_ADC1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE1_DAC0(0x0U);

    AHBSC->AIPS_BRIDGE_GROUP4_MEM_RULE2 =
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_VREF(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_DAC(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP1(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_HPDAC0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_OPAMP2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE2_PORT1(0x0U);

    AHBSC->AIPS_BRIDGE_GROUP4_MEM_RULE3 =
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT2(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT3(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_PORT4(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_MTR0(0x0U) |
	AHBSC_AIPS_BRIDGE_GROUP4_MEM_RULE3_ATX0(0x0U);
 
    /* TBD */
    AHBSC->AHB_SECURE_CTRL_PERIPHERAL_RULE0 =
	AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(0x3U) |
	AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(0x3U) |
	AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(0x3U) |
	AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(0x3U);

 
    /* Secure GPIO mask for pins. 
     * This register is used to block leakage of Secure interface (GPIOs, I2C, UART configured as secure peripherals)
     * pin states to non-secure world. 
     * 0: GPIO can't read PIOn_PIN,
     * 1: GPIO can read PIOn_PIN 0x1
     */
    AHBSC->SEC_GPIO_MASK[0] = 0xFFFFFFFFU; /* Reset value */
    AHBSC->SEC_GPIO_MASK[1] = 0xFFFFFFFFU;

    /* Set Master Security Level of PKC and ELS Security Level to secure and privileged master, and lock it. */
    SECURE_READ_MODIFY_WRITE_REGISTER(&(AHBSC->MASTER_SEC_LEVEL),                                   
        ~(AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK |
 	AHBSC_MASTER_SEC_LEVEL_CPU1_MASK |
	AHBSC_MASTER_SEC_LEVEL_SMARTDMA_MASK |
	AHBSC_MASTER_SEC_LEVEL_EDMA0_MASK |
	AHBSC_MASTER_SEC_LEVEL_EDMA1_MASK |
	AHBSC_MASTER_SEC_LEVEL_PKC_MASK |
	AHBSC_MASTER_SEC_LEVEL_PQ_MASK |
	AHBSC_MASTER_SEC_LEVEL_NPUO_MASK |
	AHBSC_MASTER_SEC_LEVEL_COOLFLUXI_MASK |
	AHBSC_MASTER_SEC_LEVEL_USB_FS_MASK |
	AHBSC_MASTER_SEC_LEVEL_ETHERNET_MASK |
	AHBSC_MASTER_SEC_LEVEL_USB_HS_MASK |
	AHBSC_MASTER_SEC_LEVEL_USDHC_MASK),
        (AHBSC_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK(0x1U)     |        /* MASTER SEC LEVEL LOCK Setting */
	AHBSC_MASTER_SEC_LEVEL_CPU1(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_SMARTDMA(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_EDMA0(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_EDMA1(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_PKC(0x3U) |                              /* PKC */
	AHBSC_MASTER_SEC_LEVEL_PQ(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_NPUO(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_COOLFLUXI(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_USB_FS(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_ETHERNET(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_USB_HS(0x0U) |
	AHBSC_MASTER_SEC_LEVEL_USDHC(0x0U)));

    /* Set the corresponding ANTI POL register */
    SECURE_READ_MODIFY_WRITE_REGISTER((&(AHBSC->MASTER_SEC_ANTI_POL_REG)),
        ~(AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK |
 	AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_PQ_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS_MASK |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC_MASK),
        ~(AHBSC_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK(0x1U)     |        /* MASTER SEC LEVEL LOCK Setting */
	AHBSC_MASTER_SEC_ANTI_POL_REG_CPU1(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_SMARTDMA(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA0(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_EDMA1(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_PKC(0x3U) |                                       /* PKC us enabled as secure AHB Master*/
	AHBSC_MASTER_SEC_ANTI_POL_REG_PQ(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_NPUO(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_COOLFLUXI(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USB_FS(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_ETHERNET(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USB_HS(0x0U) |
	AHBSC_MASTER_SEC_ANTI_POL_REG_USDHC(0x0U)));
   
    /* Update AHB Secure control register */
    SECURE_READ_MODIFY_WRITE_REGISTER(&(AHBSC->MISC_CTRL_REG),
        ~(AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK                |
          AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK    |
          AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK       |
          AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK   |
          AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK               ),
         (AHBSC_MISC_CTRL_REG_WRITE_LOCK              (0x2U) |         /* 2 = Writes to this register and to the Memory and Peripheral RULE registers are allowed */
          AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING  (0x1U) |         /* 1 = Enable Secure Checking (restrictive mode) */
          AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK     (0x2U) |         /* 2 = Disabled Secure Privilege Checking */
          AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK    (0x2U) |         /* 2 = Disabled Non-Secure Privilege Checking */
          AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT (0x2U) |         /* 2 = The violation detected by the secure checker will cause an abort. */
          AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE     (0x1U) |         /* 1 = AHB master in tier mode. Can read and write to memories at same or below level. */
          AHBSC_MISC_CTRL_REG_IDAU_ALL_NS             (0x2U)));        /* 2 = IDAU is enabled (restrictive mode) */

    /* Secure control duplicate register */
    SECURE_READ_MODIFY_WRITE_REGISTER(&(AHBSC->MISC_CTRL_DP_REG),
        ~(AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK                |
          AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK    |
          AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK       |
          AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK   |
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

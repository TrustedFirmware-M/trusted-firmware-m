/*
 * Copyright (c) 2018-2022 Arm Limited. All rights reserved.
 * Copyright 2019-2023 NXP. All rights reserved.
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
#include "tfm_log.h"

extern const struct memory_region_limits memory_regions;

struct platform_data_t tfm_peripheral_std_uart = {
        USART0_BASE_NS,
        USART0_BASE_NS + 0xFFF,
        0,
        0
};

struct platform_data_t tfm_peripheral_timer0 = {
        CTIMER2_BASE,
        CTIMER2_BASE + 0xFFF,
        &(AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL1),
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_CTIMER2_RULE_SHIFT
};

/*------------------- Memory configuration functions -------------------------*/

int32_t mpc_init_cfg(void)
{
    uint32_t ns_region_id = 0;
    uint32_t ns_region_start_id = 0;
    uint32_t ns_region_end_id = 0;

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

    /* == Flash region == */

    /* The regions have to be alligned to 32 kB to cover the AHB Flash Region. */
    assert((memory_regions.non_secure_partition_base % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.non_secure_partition_limit+1) % FLASH_SUBREGION_SIZE) == 0);

    /* Flash region is divided into 20 sub-regions (sector). Each flash sub-regions (sector) is 32 kbytes. */
    /* 1) Set FLASH memory security access rule configuration to init value (0x3 = all regions set to secure and privileged user access) */
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[0] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[1] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[2] = 0x33333333U;

    /* 2) Set FLASH memory security access rule configuration (set to non-secure and non-privileged user access allowed).*/
    ns_region_start_id = memory_regions.non_secure_partition_base/FLASH_SUBREGION_SIZE;
    ns_region_end_id = (memory_regions.non_secure_partition_limit+1)/FLASH_SUBREGION_SIZE;

    /* Set to non-secure and non-privileged user access allowed */
    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
    {
        if(ns_region_id < 8)
        {
            /* Set regions the AHB controller for flash memory 0x0000_0000 - 0x0004_0000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[0] &= ~(0xF << (ns_region_id*4));
        }
        else if((ns_region_id >= 8) && (ns_region_id < 16))
        {
            /* Set regions in the AHB controller for flash memory 0x0004_0000 - 0x0008_0000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[1] &= ~(0xF << ((ns_region_id-8)*4));
        }else if((ns_region_id >= 16) && (ns_region_id < 24))
        {
            /* Set regions the AHB controller for flash memory 0x0008_0000 - 0x0009_8000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[2] &= ~(0xF << ((ns_region_id-16)*4));
        }
    }

#ifdef BL2 /* Set secondary image region to NS, when BL2 is enabled */
    /* The regions have to be alligned to 32 kB to cover the AHB Flash Region. */
    assert((memory_regions.secondary_partition_base % FLASH_SUBREGION_SIZE) == 0);
    assert(((memory_regions.secondary_partition_limit+1) % FLASH_SUBREGION_SIZE) == 0);

    /* 2) Set FLASH memory security access rule configuration (set to non-secure and non-privileged user access allowed).*/
    ns_region_start_id = memory_regions.secondary_partition_base/FLASH_SUBREGION_SIZE;
    ns_region_end_id = (memory_regions.secondary_partition_limit+1)/FLASH_SUBREGION_SIZE;

    /* Set to non-secure and non-privileged user access allowed */
    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
    {
        if(ns_region_id < 8)
        {
            /* Set regions the AHB controller for flash memory 0x0000_0000 - 0x0004_0000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[0] &= ~(0xF << (ns_region_id*4));
        }
        else if((ns_region_id >= 8) && (ns_region_id < 16))
        {
            /* Set regions in the AHB controller for flash memory 0x0004_0000 - 0x0008_0000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[1] &= ~(0xF << ((ns_region_id-8)*4));
        }else if((ns_region_id >= 16) && (ns_region_id < 24))
        {
            /* Set regions the AHB controller for flash memory 0x0008_0000 - 0x0009_8000 */
            AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[2] &= ~(0xF << ((ns_region_id-16)*4));
        }
    }
#endif

    /* == ROM region == */

    /* Each ROM sector is 4 kbytes. There are 32 ROM sectors in total. */
    /* Security control ROM memory configuration (0x3 = all regions set to secure and privileged user access). */
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[0] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[1] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[2] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[3] = 0x33333333U;

    /* == RAMX region == */

    /* Each RAMX sub region is 4 kbytes.*/
    /* Security access rules for RAMX (0x3 = all regions set to secure and privileged user access). */
    AHB_SECURE_CTRL->SEC_CTRL_RAMX[0].MEM_RULE[0]= 0x33333333U; /* 0x0400_0000 - 0x0400_7FFF */

    /* == SRAM region == */

    /* The regions have to be alligned to 4 kB to cover the AHB RAM Region */
    assert((S_DATA_SIZE % DATA_SUBREGION_SIZE) == 0);
    assert(((S_DATA_SIZE + NS_DATA_SIZE) % DATA_SUBREGION_SIZE) == 0);

    /* Security access rules for RAM (0x3 = all regions set to secure and privileged user access*/
    AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[0]= 0x33333333U; /* 0x2000_0000 - 0x2000_7FFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[1]= 0x33333333U; /* 0x2000_8000 - 0x2000_FFFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[0]= 0x33333333U; /* 0x2001_0000 - 0x2001_7FFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[1]= 0x33333333U; /* 0x2001_8000 - 0x2001_FFFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[0]= 0x33333333U; /* 0x2002_0000 - 0x2002_7FFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[1]= 0x33333333U; /* 0x2002_8000 - 0x2002_FFFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[0]= 0x33333333U; /* 0x2003_0000 - 0x2003_7FFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[1]= 0x33333333U; /* 0x2003_8000 - 0x2003_FFFF */
    AHB_SECURE_CTRL->SEC_CTRL_RAM4[0].MEM_RULE[0]= 0x33333333U; /* 0x2004_0000 - 0x2004_3FFF */

    /* RAM memory configuration (set according to region_defs.h and flash_layout.h) */
    ns_region_start_id = S_DATA_SIZE/DATA_SUBREGION_SIZE; /* NS starts after S */
    ns_region_end_id = (S_DATA_SIZE + NS_DATA_SIZE)/DATA_SUBREGION_SIZE;

    for(ns_region_id = ns_region_start_id; ns_region_id < ns_region_end_id; ns_region_id++)
    {
        /* Set regions the AHB controller for ram memory 0x2000_0000 - 0x2000_7FFF */
        if(ns_region_id < 8) {
            AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[0] &= ~(0xF << (ns_region_id*4));
        }
        /* Set regions the AHB controller for ram memory 0x2000_8000 - 0x2000_FFFF */
        else if((ns_region_id >= 8) && (ns_region_id < 16)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[1] &= ~(0xF << ((ns_region_id-8)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2001_0000 - 0x2001_7FFF */
        else if((ns_region_id >= 16) && (ns_region_id < 24)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[0] &= ~(0xF << ((ns_region_id-16)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2001_8000 - 0x2001_FFFF */
        else if((ns_region_id >= 24) && (ns_region_id < 32)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[1] &= ~(0xF << ((ns_region_id-24)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2002_0000 - 0x2002_7FFF */
        else if((ns_region_id >= 32) && (ns_region_id < 40)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[0] &= ~(0xF << ((ns_region_id-32)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2002_8000 - 0x2002_FFFF */
        else if((ns_region_id >= 40) && (ns_region_id < 48)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[1] &= ~(0xF << ((ns_region_id-40)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2003_0000 - 0x2003_7FFF */
        else if((ns_region_id >= 48) && (ns_region_id < 56)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[0] &= ~(0xF << ((ns_region_id-48)*4));
        }
        /* Set regions the AHB controller for ram memory 0x2003_8000 - 0x2003_FFFF */
        else if((ns_region_id >= 56) && (ns_region_id < 64)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[1] &= ~(0xF << ((ns_region_id-56)*4));
        }
        /* Set regions the AHB controller for ram memory  0x2004_0000 - 0x2004_3FFF */
        else if((ns_region_id >= 64) && (ns_region_id < 72)) {
                AHB_SECURE_CTRL->SEC_CTRL_RAM4[0].MEM_RULE[0] &= ~(0xF << ((ns_region_id-64)*4));
        }
    }

    /* Security access rules for USB-HS RAM sub region 0_0 to 0_3. Each USB-HS RAM sub region is 4 kbytes */
    AHB_SECURE_CTRL->SEC_CTRL_USB_HS[0].MEM_RULE[0] =
        AHB_SECURE_CTRL_SEC_CTRL_USB_HS_MEM_RULE_SRAM_SECT_0_RULE(0x0U) |                   /* Address space: 0x4010_0000 - 0x4010_0FFF */
        AHB_SECURE_CTRL_SEC_CTRL_USB_HS_MEM_RULE_SRAM_SECT_1_RULE(0x0U) |                   /* Address space: 0x4010_1000 - 0x4010_1FFF */
        AHB_SECURE_CTRL_SEC_CTRL_USB_HS_MEM_RULE_SRAM_SECT_2_RULE(0x0U) |                   /* Address space: 0x4010_2000 - 0x4010_2FFF */
        AHB_SECURE_CTRL_SEC_CTRL_USB_HS_MEM_RULE_SRAM_SECT_3_RULE(0x0U);                    /* Address space: 0x4010_3000 - 0x4010_3FFF */

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

    /* Write access attributes for AHB_SECURE_CTRL module are tier-4 (secure privileged). */ 

    /* Security access rules for APB Bridge 0 peripherals. */
    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE0_MEM_CTRL0 =
        (0x30000000U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_SYSCON_RULE(0x0U) |                  /* System configuration */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_IOCON_RULE(0x0U) |                   /* I/O configuration */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_GINT0_RULE(0x0U) |                   /* GPIO input Interrupt 0 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_GINT1_RULE(0x0U) |                   /* GPIO input Interrupt 1 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_PINT_RULE(0x0U) |                    /* Pin Interrupt and Pattern match */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_SEC_PINT_RULE(0x0U) |                /* Secure Pin Interrupt and Pattern match */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_INPUTMUX_RULE(0x0U);                 /* Peripheral Input Multiplexing. */

    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE0_MEM_CTRL1 =
        (0x30003300U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL1_CTIMER0_RULE(0x0U) |                 /* Standard counter/Timer 0 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL1_CTIMER1_RULE(0x0U) |                 /* Standard counter/Timer 1 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL1_WWDT_RULE(0x0U) |                    /* Windowed watchdog Timer */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL1_MRT_RULE(0x0U) |                     /* Multi-rate Timer */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL1_UTICK_RULE(0x0U);                    /* Micro-Timer */

    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE0_MEM_CTRL2 =
        (0x33330333U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE0_MEM_CTRL2_ANACTRL_RULE(0x0U);                  /* Analog modules controller */

    /* Security access rules for APB Bridge 1 peripherals. */
    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL0 =
        (0x33330330U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL0_PMC_RULE(0x0U) |                     /* Power Management Controller */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL0_SYSCTRL_RULE(0x0U);                  /* System Controller */

    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL1 =
        (0x33003000U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_CTIMER2_RULE(0x0U) |                 /* Standard counter/Timer 2 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_CTIMER3_RULE(0x0U) |                 /* Standard counter/Timer 3 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_CTIMER4_RULE(0x0U) |                 /* Standard counter/Timer 4 */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_RTC_RULE(0x0U) |                     /* Real Time Counter */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL1_OSEVENT_RULE(0x0U);                  /* OS Event Timer */

    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL2 =
        (0x33003333U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL2_FLASH_CTRL_RULE(0x3U) |              /* Flash controller = S*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL2_PRINCE_RULE(0x3U);                   /* PRINCE = S */

    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL3 =
        /* 0x0F000000U | */
        (0x33030030U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL3_USBHPHY_RULE(0x0U) |                 /* USB High Speed Phy controller */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL3_RNG_RULE(0x3U) |                     /* True Random Number Generator = S */
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL3_PUF_RULE(0x3U) |                     /* PUF = S*/
        AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE1_MEM_CTRL3_PLU_RULE(0x0U);                      /* Programmable Look-Up logic */

    /* Security access rules for AHB peripherals on AHB Slave Port P8*/
    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT8_SLAVE0_RULE =
        (0x00003033U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE0_RULE_DMA0_RULE(0x0U) |                    /* DMA0 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE0_RULE_FS_USB_DEV_RULE(0x0U) |              /* USB */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE0_RULE_SCT_RULE(0x0U) |                     /* SCT */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE0_RULE_FLEXCOMM0_RULE(0x0U) |               /* FLEXCOMM0 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE0_RULE_FLEXCOMM1_RULE(0x0U);                /* FLEXCOMM1 */

    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT8_SLAVE1_RULE =
        (0x00300000U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE1_RULE_FLEXCOMM2_RULE(0x0U) |               /* FLEXCOMM2 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE1_RULE_FLEXCOMM3_RULE(0x0U) |               /* FLEXCOMM3 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE1_RULE_FLEXCOMM4_RULE(0x0U) |               /* FLEXCOMM4 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE1_RULE_MAILBOX_RULE(0x0U) |                 /* MAILBOX */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT8_SLAVE1_RULE_GPIO0_RULE(0x0U);                    /* High Speed GPIO */

    /* Security access rules for AHB peripherals on AHB Slave Port P9 */
    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT9_SLAVE0_RULE =
        (0x00003333U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE0_RULE_USB_HS_DEV_RULE(0x0U) |              /* USB high Speed device registers */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE0_RULE_CRC_RULE(0x0U) |                     /* CRC engine */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE0_RULE_FLEXCOMM5_RULE(0x0U) |               /* FLEXCOMM5 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE0_RULE_FLEXCOMM6_RULE(0x0U);                /* FLEXCOMM6 */

    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT9_SLAVE1_RULE =
        (0x03300330U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE1_RULE_FLEXCOMM7_RULE(0x0U) |               /* FLEXCOMM7 */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE1_RULE_SDIO_RULE(0x0U) |                    /* SDIO */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE1_RULE_DBG_MAILBOX_RULE(0x0U) |             /* Debug mailbox (aka ISP-AP) */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT9_SLAVE1_RULE_HS_LSPI_RULE(0x0U);                  /* High Speed SPI */

    /* Security access rules for AHB peripherals on AHB Slave Port P10. */
    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT10[0].SLAVE0_RULE =
        (0x00000030U) |                                                                     /* Bits have to be set to '1' according to UM.*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_ADC_RULE(0x0U) |                    /* ADC */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_USB_FS_HOST_RULE(0x0U) |            /* USB Full Speed Host registers. */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_USB_HS_HOST_RULE(0x0U) |            /* USB High speed host registers */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_HASH_RULE(0x3U) |                   /* SHA-2 crypto registers = S*/
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_CASPER_RULE(0x3U) |                 /* RSA/ECC crypto accelerator = S */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_PQ_RULE(0x0U) |                     /* Power Quad (CM33 processor hardware accelerator) */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE0_RULE_DMA1_RULE(0x0U);                    /* DMA Controller (Secure) */

    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT10[0].SLAVE1_RULE =
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE1_RULE_GPIO1_RULE(0x0U) |                  /* Secure High Speed GPIO */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_PORT10_SLAVE1_RULE_AHB_SEC_CTRL_RULE(0x3U);            /* AHB Secure Controller = S */

    /* Security access rules for AHB secure control. */
    AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT10[0].SEC_CTRL_AHB_SEC_CTRL_MEM_RULE[0] =
        AHB_SECURE_CTRL_SEC_CTRL_AHB_SEC_CTRL_MEM_RULE_AHB_SEC_CTRL_SECT_0_RULE(0x0U) |     /* Address space: 0x400A_C000 - 0x400A_CFFF */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_SEC_CTRL_MEM_RULE_AHB_SEC_CTRL_SECT_1_RULE(0x0U) |     /* Address space: 0x400A_D000 - 0x400A_DFFF */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_SEC_CTRL_MEM_RULE_AHB_SEC_CTRL_SECT_2_RULE(0x0U) |     /* Address space: 0x400A_E000 - 0x400A_EFFF */
        AHB_SECURE_CTRL_SEC_CTRL_AHB_SEC_CTRL_MEM_RULE_AHB_SEC_CTRL_SECT_3_RULE(0x0U);      /* Address space: 0x400A_F000 - 0x400A_FFFF */

    /* This register has the security access rules for the slave port P11 on AHB multilayer. This
    slave port allows access to USB-HS RAM memories. This rule supersedes more granular
    security rules as in SEC_CTRL_USB_HS_SLAVE_RULE */
    AHB_SECURE_CTRL->SEC_CTRL_USB_HS[0].SLAVE_RULE =
        AHB_SECURE_CTRL_SEC_CTRL_USB_HS_SLAVE_RULE_RAM_USB_HS_RULE(0x0U);

    /* Enable AHB secure controller check */
    AHB_SECURE_CTRL->MISC_CTRL_REG = (AHB_SECURE_CTRL->MISC_CTRL_REG & ~(AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK | 0)) |
                                        /* AHB bus matrix enable secure checking (restrictive mode). */
                                        AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(0x1U);
                                        /* Other default values:
                                            - Write lock - secure_ctrl_group_rule registers and this register itself can be written.
                                            - AHB bus matrix enable secure privilege check - disabled
                                            - AHB bus matrix enable non-secure privilege check - disabled
                                            - The violation detected by the secure checker causes abort.
                                            - Simple master in strict mode. Can read and write to memories at same level only. (Mode recommended by ARM).
                                            - Smart masters in strict mode. Can execute, read and write to memories at same level only. (Mode recommended by ARM.).
                                            – IDAU is enabled.
                                        */
    /* Secure control duplicate register */
    AHB_SECURE_CTRL->MISC_CTRL_DP_REG = (AHB_SECURE_CTRL->MISC_CTRL_DP_REG & ~( AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK | 0)) |
                                        /* AHB bus matrix enable secure checking (restrictive mode). */
                                        AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(0x1U);

    return ARM_DRIVER_OK;
}

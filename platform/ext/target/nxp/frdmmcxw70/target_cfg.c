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

/********************************************************************************
 * strcuts
 *******************************************************************************/
extern const struct memory_region_limits memory_regions;

struct platform_data_t tfm_peripheral_std_uart = {
        .periph_start = (uint32_t)LPUART_BASE,
        .periph_limit = (uint32_t)LPUART_BASE + 0xFFF,
        .nseEnable = true,
        .mbcIdx  = 4,
        .slaveMemoryIdx = 0,
        .memoryBlockIdx = 39,
};

struct platform_data_t tfm_peripheral_timer0 = {
        .periph_start = LPTMR_0_BASE,
        .periph_limit = LPTMR_0_BASE + 0xFFF,
        .nseEnable = false,
        .mbcIdx = 0,
        .slaveMemoryIdx = 2,
        .memoryBlockIdx = 5,
};

static const uint32_t mbc0SlaveBase[] =
{
    MBC0_SLV0_BASE,
    MBC0_SLV1_BASE,
    MBC0_SLV2_BASE,
    MBC0_SLV3_BASE
};

static const uint32_t mbc4SlaveBase[] =
{
    MBC4_SLV0_BASE,
    MBC4_SLV1_BASE,
};

static const mbc_map_t mbc0_map =
{
    .slaveBase      = mbc0SlaveBase,
    .slaveCount     = (uint8_t)ARRAY_SIZE(mbc0SlaveBase),
};

static const mbc_map_t mbc4_map =
{
    .slaveBase      = mbc4SlaveBase,
    .slaveCount     = (uint8_t)ARRAY_SIZE(mbc4SlaveBase),
};

const periph_desc_t secure_peripherals_mbc0[] =
{
    { 0x4018C000u, 2 },    /* TRDC0-MGR	         */
    { 0x4018D000u, 2 },    /* TRDC0-MBC00        */
    { 0x4018E000u, 2 },    /* TRDC0-MBC1         */
    { 0x4018F000u, 2 },    /* TRDC0-MBC2         */
    { 0x40190000u, 2 },    /* TRDC0-MBC3         */
    { 0x40191000u, 2 },    /* TRDC0-MBC01        */
};

const periph_desc_t secure_peripherals_mbc4[] =
{
    { 0x40000000, 0 },      /*     AXBS0         */
    { 0x40012000, 0 },      /*     MSCM0         */
    { 0x40013000, 0 },      /*     SMSCM0        */
    { 0x40014000, 0 },      /*     SYSPM0        */
    { 0x40015000, 0 },      /*     TRGMUX0       */
    { 0x40016000, 0 },      /*     ITRC0         */
    { 0x40017000, 0 },      /*     FMU0          */
    { 0x40023000, 0 },      /*     PKCWRAP0      */
    { 0x40039000, 0 },      /*     DGDET0        */
    { 0x4003A000, 0 },      /*     SGI0          */
    { 0x4003B000, 0 },      /*     UDF0          */
    { 0x4003C000, 0 },      /*     TRNG0         */
    { 0x4003D000, 0 },      /*     AXBS_MAIN0    */
    { 0x400B0000, 1 },      /*     PKC RAM       Block size is 32KB for each peripheral*/
};

/********************************************************************************
 * Static function Definitions
 *******************************************************************************/

/* KW43 aliasing: bit-28 distinguishes Secure vs Non-secure */
#define KW43_ALIAS_BIT       (0x10000000u)
static inline uint32_t kw43_phys_addr(uint32_t addr)
{
    return (addr & ~KW43_ALIAS_BIT);
}

/* ========================================================
 * Helper: get block index against peripheral address
 * ======================================================= */
static inline bool get_periph_addr_to_block_idx(const uint32_t mbcIdx,
                                                const mbc_map_t *map,
                                                periph_desc_t p,
                                                uint32_t *outBlock)
{
    if ((map == NULL) || (outBlock == NULL))
    {
        return false;
    }

    uint32_t phys = p.addr & ~KW43_ALIAS_BIT;

    if (p.slaveIdx >= map->slaveCount)
    {
        return false;
    }

    uint32_t blk;
    uint32_t base = map->slaveBase[p.slaveIdx];
    /* Handle the one exception where block size of peripheral is 0x8000 instead of 0x1000*/
    if(mbcIdx == MBC_04_PERIPH && p.slaveIdx == 0x1u)
    {
      blk  = MBC4_SLV1_PERIPH_BLOCK_SIZE;
    }
    else
    {
      blk  = PERIPH_BLOCK_SIZE;
    }

    if (blk == 0U)
    {
        return false;
    }

    /* Prevent underflow */
    if (phys < base)
    {
        return false;
    }

    *outBlock = (phys - base) / blk;
    return true;
}

/* ========================================================
 * Helper: program a peripheral
 * ======================================================= */
static void program_secure_peripherals(const mbc_map_t *map,
                                       trdc_mbc_memory_block_config_t *cfg,
                                       const periph_desc_t *list,
                                       size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        uint32_t blk;

        cfg->slaveMemoryIdx = list[i].slaveIdx;

        if (!get_periph_addr_to_block_idx(cfg->mbcIdx, map, list[i], &blk))
        {
            continue; /* or assert / return error */
        }

        cfg->memoryBlockIdx = blk;
        TRDC_MbcSetMemoryBlockConfig(TRDC, cfg);
    }
}

/* ========================================================
 * Helper: compute block size bytes from TRDC MBC HW config
 * ======================================================= */
static int get_mbc1_ram_trdc_configs(uint32_t phys_addr, uint8_t *slvIdx, uint32_t *slvOffset, uint32_t *blk_sz)
{
    if ((phys_addr >= RAM_SLV0_BASE) && (phys_addr <= RAM_SLV0_END))
    {
        *slvIdx = 0u;
        *slvOffset = phys_addr - RAM_SLV0_BASE;
        *blk_sz = TRDC_MBC1_SLV0_SUBREGION_SIZE;
        return 0;
    }
    if ((phys_addr >= RAM_SLV1_BASE) && (phys_addr <= RAM_SLV1_END))
    {
        *slvIdx = 1u;
        *slvOffset = phys_addr - RAM_SLV1_BASE;
        *blk_sz = TRDC_MBC1_SLV1_SUBREGION_SIZE;
        return 0;
    }
    if ((phys_addr >= RAM_SLV2_BASE) && (phys_addr <= RAM_SLV2_END))
    {
        *slvIdx = 2u;
        *slvOffset = phys_addr - RAM_SLV2_BASE;
        *blk_sz = TRDC_MBC1_SLV2_SUBREGION_SIZE;
        return 0;
    }
    /* out of supported RAM windows */
    return -1;
}

/* ========================================================
 * Helper: compute block size bytes from TRDC MBC HW config
 * ======================================================= */
static uint32_t get_mbc_slave_block_count(uint8_t mbcIdx, uint8_t slvIdx)
{
    trdc_slave_memory_hardware_config_t cfg;
    memset(&cfg, 0, sizeof(cfg));
    /* gives NBLKS */
    TRDC_GetMbcHardwareConfig(TRDC, &cfg, mbcIdx, slvIdx);
    return cfg.blockNum;
}

/* ==================================================
 * Default configure all blocks:
 *  - Flash/RAM default: Secure-only for DID0
 *  - Peripherals default: allow NS, allow Secure too
 * ================================================== */
static void default_configure_all_blocks(const trdc_hardware_config_t *hw)
{
    trdc_mbc_memory_block_config_t blkCfg;
    memset(&blkCfg, 0, sizeof(blkCfg));

    for (uint8_t mbc = 0; mbc < hw->mbcNumber; mbc++)
    {
        for (uint8_t slv = 0; slv < 4 ; slv++)
        {
            uint32_t nblks = get_mbc_slave_block_count(mbc, slv);
            if (nblks == 0 || mbc == MBC_FMC1)
            {
                continue;
            }
            /* do ot configure already configure IFR0/IFR1 and P0-Flash*/
            if (mbc == MBC_FLASH && (slv >= 1))
            {
                continue;
            }
            for (uint32_t b = 0; b < nblks; b++)
            {
                blkCfg.mbcIdx = mbc;
                /* Core domain */
                blkCfg.domainIdx = 0x00;
                blkCfg.slaveMemoryIdx = slv;
                blkCfg.memoryBlockIdx = b;

                /* Allowed peripheral configs, MBC0 has 4 slaves and MBC4 has only 2 slaves  */
                if ((mbc == MBC_00_PERIPH) || (mbc == MBC_04_PERIPH))
                {
                  /* Permissive default for all peripherals  */
                  blkCfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_ALL_INDEX;

                  /* Allow ns access by default */
                  blkCfg.nseEnable = true;
                }
                /* ram and flash default configs, all regions mark as secure only with no access to ns*/
                else if (mbc == MBC_FLASH)
                {
                    blkCfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_FLASH_SEC_ALL_INDEX;
                     /* restrict ns access by default */
                    blkCfg.nseEnable = false;
                }
                else if(mbc == MBC_RAM)
                {
                    blkCfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_RAM_SEC_ALL_INDEX;
                     /* restrict ns access by default */
                    blkCfg.nseEnable = false;
                }
                /* should not reach here*/
                else
                {
                  break;
                }
                /* Apply the configs via trdc driver*/
                TRDC_MbcSetMemoryBlockConfig(TRDC, &blkCfg);
            }
        }
    }
}

/* ================================================================
 * Open NS FLASH blocks for DID1 (NS user + NS priv allowed)
 * We compute block indices relative to FLASH_BASE_ADDRESS
 * after clearing alias bit-28.
 * ================================================================ */
static void open_ns_flash_partition(void)
{
    /* flash is MBC0 slave0 in KW43 mapping (program flash uses 32KB blocks) */
    const uint8_t mbc = MBC_FLASH;
    const uint8_t slv = 0u;

    uint32_t start_off = memory_regions.non_secure_partition_base - FLASH_BASE_ADDRESS + FLASH_NBU_FW_SIZE;
    uint32_t end_off   = memory_regions.non_secure_partition_limit+1 - FLASH_BASE_ADDRESS + FLASH_NBU_FW_SIZE;
    uint32_t start_blk = start_off / FLASH_SUBREGION_SIZE;
    uint32_t end_blk   = end_off   / FLASH_SUBREGION_SIZE;

    trdc_mbc_memory_block_config_t cfg;
    memset(&cfg, 0, sizeof(cfg));
    cfg.mbcIdx = mbc;
    cfg.slaveMemoryIdx = slv;
    cfg.domainIdx = DID_SECURE;
    /* Select GLBAC index 1: */
    cfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_S_RO_NS_ALL_INDEX;
    cfg.nseEnable = true;

    for (uint32_t b = start_blk; b <= end_blk; b++)
    {
        cfg.memoryBlockIdx = (uint8_t)b;
        TRDC_MbcSetMemoryBlockConfig(TRDC, &cfg);
    }
}

/* ====================================================
 * Open NS RAM region for core 0 domain:
 *  NS region starts at NS_RAM_ALIAS_BASE + S_DATA_SIZE
 *
 * The TRDC RAM block granularity is TRDC_MBC1_SLVx_SUBREGION_SIZE (4 KB), so
 * the non-secure window can only be opened in 4 KB steps. NS_DATA_LIMIT
 * (0x20028DFF) is not 4 KB aligned, which means the last opened block rounds
 * up to 0x20028FFF and therefore covers the first 0x200 bytes of the NBU
 * private area. That area belongs to the other core and holds no TF-M secure
 * asset, so the secure/non-secure boundary of this core is not affected. The
 * checks below make sure the rounding can never reach the inter-core shared
 * region or the secure data area.
 * ==================================================== */
#define RAM_NBU_SHARED_BASE    (0x2002E000u)  /* 8 KB shared with NBU core */

/* Rounded-up end of the NS window, as actually programmed into the TRDC. */
#define NS_RAM_PROGRAMMED_END                                            \
    (((NS_DATA_START + NS_DATA_SIZE - 1u) | (TRDC_MBC1_SLV2_SUBREGION_SIZE - 1u)) + 1u)

/* The NS window must start on a TRDC block boundary, otherwise the first
 * opened block would also cover the tail of the secure data area.
 */
#if ((NS_DATA_START % TRDC_MBC1_SLV2_SUBREGION_SIZE) != 0)
#error "NS_DATA_START must be aligned to the TRDC RAM block size"
#endif

/* The rounding at the top must not reach the inter-core shared region. */
#if (NS_RAM_PROGRAMMED_END > RAM_NBU_SHARED_BASE)
#error "NS RAM window rounds up into the NBU/shared RAM region"
#endif

static void open_ns_ram_region(void)
{
    /* Half-open range [ns_start, ns_end_excl) to avoid off-by-one block math. */
    const uint32_t ns_start    = NS_DATA_START;
    const uint32_t ns_end_excl = ns_start + NS_DATA_SIZE;
    uint32_t addr = ns_start;

    while (addr < ns_end_excl)
    {
        uint32_t phys = kw43_phys_addr(addr);

        uint8_t slv;
        uint32_t off;
        uint32_t blk_sz;

        if (get_mbc1_ram_trdc_configs(phys, &slv, &off, &blk_sz) != 0)
        {
            /* The NS data region must be fully covered by the known RAM slave
             * windows, otherwise part of it would silently stay secure-only.
             */
            assert(false);
            break;
        }

        /* Limit this chunk to the end of the current slave window (exclusive) */
        uint32_t slv_end_excl;

        if (slv == 0u)
        {
            slv_end_excl = RAM_SLV0_END + 1u;
        }
        else if (slv == 1u)
        {
            slv_end_excl = RAM_SLV1_END + 1u;
        }
        else if (slv == 2u)
        {
            slv_end_excl = RAM_SLV2_END + 1u;
        }
        else
        {
            assert(false);
            break;
        }

        uint32_t phys_ns_end_excl = kw43_phys_addr(ns_end_excl);
        uint32_t chunk_end_excl;

        /* Select the smaller of phys_ns_end_excl and slv_end_excl */
        if (phys_ns_end_excl < slv_end_excl)
        {
            chunk_end_excl = phys_ns_end_excl;
        }
        else
        {
            chunk_end_excl = slv_end_excl;
        }

        if (chunk_end_excl <= phys)
        {
            break;
        }

        /* Determine the start and end blocks to apply policies. The end block
         * is computed from the last byte of the chunk so that a chunk which
         * ends exactly on a block boundary does not open the next block.
         */
        uint32_t start_blk = off / blk_sz;
        uint32_t end_blk   = (off + (chunk_end_excl - phys) - 1u) / blk_sz;

        trdc_mbc_memory_block_config_t cfg;
        memset(&cfg, 0, sizeof(cfg));
        cfg.mbcIdx = MBC_RAM;
        cfg.slaveMemoryIdx = slv;
        cfg.domainIdx = DID_SECURE;
        cfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_NS_ALL_INDEX;
        cfg.nseEnable = true;

        for (uint32_t b = start_blk; b <= end_blk; b++)
        {
            cfg.memoryBlockIdx = b;
            TRDC_MbcSetMemoryBlockConfig(TRDC, &cfg);
        }

        /* Move to next address after this slave chunk */
        addr = chunk_end_excl | (addr & KW43_ALIAS_BIT);
    }
}

/*******************************************************************************
 * Static function Definitions
 ******************************************************************************/

/* =======================
 * mpc_init_cfg entry
 * ======================= */
int32_t mpc_init_cfg(void)
{
    trdc_idau_config_t idau_cfg;
    TRDC_GetDefaultIDAUConfig(&idau_cfg);
    TRDC_SetIDAU(TRDC, &idau_cfg);
    TRDC_Init(TRDC);

    trdc_hardware_config_t hw;
    TRDC_GetHardwareConfig(TRDC, &hw);

    /* 1) Use pre-defined GLBAC policies for all MBCs, not config required here */

    /* 2) Default configure everything */
    default_configure_all_blocks(&hw);

    /* 3) Open up the NS flash primary area for NS world */
    open_ns_flash_partition();

    /* 4) Open up NS RAM region based on region_defs.h */
    open_ns_ram_region();


    /* 5) Enable TRDC global valid bits.
     * TRDC requires global enables to exit deny-by-default and become operational.
     * If no MRC is present, GVLDR is not required.
     */
    uint32_t cr = TRDC->TRDC_CR;
    cr |= TRDC_TRDC_CR_GVLDM_MASK; /* DAC enable */
    cr |= TRDC_TRDC_CR_GVLDB_MASK; /* MBC enable */
    if (hw.mrcNumber != 0u)
    {
        cr |= TRDC_TRDC_CR_GVLDR_MASK; /* MRC enable only if present */
    }
    TRDC->TRDC_CR = cr;

    return ARM_DRIVER_OK;
}

int32_t ppc_init_cfg(void)
{
    trdc_mbc_memory_block_config_t cfg = {0};

    /* GLBAC policy setup POLICY_SEC_PRIV_ONLY */
    cfg.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_SEC_RW_INDEX;
    cfg.nseEnable                 = false;
    cfg.domainIdx                 = DID_SECURE;

    /* ---- MBC0 ---- */
    cfg.mbcIdx = MBC_00_PERIPH;

    program_secure_peripherals(&mbc0_map,
                              &cfg,
                              secure_peripherals_mbc0,
                              ARRAY_SIZE(secure_peripherals_mbc0));

     /* ---- MBC4 ---- */
    cfg.mbcIdx = MBC_04_PERIPH;

    program_secure_peripherals(&mbc4_map,
                              &cfg,
                              secure_peripherals_mbc4,
                              ARRAY_SIZE(secure_peripherals_mbc4));

    /* Enable MBC enforcement */
    TRDC_SetMbcGlobalValid(TRDC);

    /* Processor master ? Secure domain */
    trdc_processor_domain_assignment_t pDomainAssignment;
    TRDC_GetDefaultProcessorDomainAssignment(&pDomainAssignment);
    pDomainAssignment.domainId = DID_SECURE;
    //pDomainAssignment.domainId = 0u;                 /* DID0 secure world */
    pDomainAssignment.domainIdSelect = kTRDC_DidMda;  /* keep default if you use it */
    pDomainAssignment.secureAttr = kTRDC_MasterSecure;/* IMPORTANT FIX */

    TRDC_SetProcessorDomainAssignment(TRDC,
                                      0,       /*CPU0/CM33*/
                                      0,
                                      &pDomainAssignment);
    TRDC_SetDacGlobalValid(TRDC);

    return ARM_DRIVER_OK;
}

void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged)
{
#ifdef TRDC
    /* If the peripheral is not shared with non-secure world, give it SEC access */
    if (platform_data && platform_data->nseEnable == false)
    {
        trdc_mbc_memory_block_config_t mbcBlockConfig;

        (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
        mbcBlockConfig.nseEnable  = false;

        mbcBlockConfig.domainIdx = 0;       /* Core domain */
        mbcBlockConfig.mbcIdx = platform_data->mbcIdx;
        mbcBlockConfig.slaveMemoryIdx = platform_data->slaveMemoryIdx;
        mbcBlockConfig.memoryBlockIdx = platform_data->memoryBlockIdx;

        if (privileged == true)
            mbcBlockConfig.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_SEC_RW_INDEX;
        else
            mbcBlockConfig.memoryAccessControlSelect = TRDC_GLBAC_IDX_POLICY_SEC_RW_INDEX;

        TRDC_MbcSetMemoryBlockConfig(TRDC, &mbcBlockConfig);
    }
#endif
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

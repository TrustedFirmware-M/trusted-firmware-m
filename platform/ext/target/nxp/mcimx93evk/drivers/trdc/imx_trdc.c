/*
 * Copyright 2022-2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stdbool.h>

#include "fsl_trdc.h"
#include "imx_trdc.h"

static bool is_trdc_mgr_slot(uintptr_t trdc_base, uint8_t mbc_id,
                 uint8_t mem_id, uint16_t blk_id)
{
    unsigned int i;

    for (i = 0U; i < trdc_mgr_num; i++) {
        if (trdc_mgr_blks[i].trdc_base == trdc_base) {
            if (mbc_id == trdc_mgr_blks[i].mbc_id &&
                mem_id == trdc_mgr_blks[i].mbc_mem_id &&
               (blk_id == trdc_mgr_blks[i].blk_mgr ||
                blk_id == trdc_mgr_blks[i].blk_mc)) {
                return true;
            }
        }
    }

    return false;
}

uint32_t trdc_mbc_blk_num(uintptr_t trdc_reg, uint32_t mbc_x, uint32_t mem_x)
{
    trdc_slave_memory_hardware_config_t mbcHwConfig;
    TRDC_GetMbcHardwareConfig((TRDC_Type *)trdc_reg, &mbcHwConfig, mbc_x, mem_x);

    return mbcHwConfig.blockNum;
}

int trdc_mbc_blk_config(uintptr_t trdc_reg, uint32_t mbc_x,
            uint32_t dom_x, uint32_t mem_x, uint32_t blk_x,
            bool sec_access, uint32_t glbac_id)
{
    uint32_t nse = 1;

    if (trdc_reg == 0 || glbac_id >= GLBAC_NUM) {
        return -1;
    }

    if (sec_access == true)
    {
        nse = 0;
    } else
    {
        nse = 1;
    }
    /* Set the MBC slave memory block configuration and select the memory access control of no access for this memory
     * block */
    trdc_mbc_memory_block_config_t mbcBlockConfig;
    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
    mbcBlockConfig.memoryAccessControlSelect = glbac_id;
    /* CPU is secure mode by default, enable NSE bit to disable secure access. */
    mbcBlockConfig.nseEnable      = nse;
    mbcBlockConfig.mbcIdx         = mbc_x;
    mbcBlockConfig.domainIdx      = dom_x;
    mbcBlockConfig.slaveMemoryIdx = mem_x;
    mbcBlockConfig.memoryBlockIdx = blk_x;

    TRDC_MbcSetMemoryBlockConfig((TRDC_Type *)trdc_reg, &mbcBlockConfig);

    return 0;
}

/*
 * Set up the TRDC access policy for MBC resources under
 * the TRDC control.
 */
void trdc_mbc_setup(struct trdc_mbc_config_info *cfg)
{
    unsigned int i, j, num;
    bool is_mgr;

    trdc_hardware_config_t hwConfig;
    TRDC_GetHardwareConfig((TRDC_Type *)cfg->trdc_base, &hwConfig);

    if (hwConfig.mbcNumber != 0) {
        /* MBC global access policy has already been set by TF-A*/

        for (i = 0U; i < cfg->num_mbc_cfg; i++) {
            if (cfg->mbc_cfg[i].blk_id == MBC_BLK_ALL) {
                num = trdc_mbc_blk_num(cfg->trdc_base,
                               cfg->mbc_cfg[i].mbc_id,
                               cfg->mbc_cfg[i].mem_id);

                for (j = 0U; j < num; j++) {
                    /* Skip mgr and mc */
                    is_mgr = is_trdc_mgr_slot(cfg->trdc_base,
                                  cfg->mbc_cfg[i].mbc_id,
                                  cfg->mbc_cfg[i].mem_id, j);
                    if (is_mgr) {
                        continue;
                    }

                    trdc_mbc_blk_config(cfg->trdc_base,
                                cfg->mbc_cfg[i].mbc_id,
                                cfg->mbc_cfg[i].dom_id,
                                cfg->mbc_cfg[i].mem_id, j,
                                cfg->mbc_cfg[i].secure,
                                cfg->mbc_cfg[i].glbac_id);
                }
            } else {
                trdc_mbc_blk_config(cfg->trdc_base,
                            cfg->mbc_cfg[i].mbc_id,
                            cfg->mbc_cfg[i].dom_id,
                            cfg->mbc_cfg[i].mem_id,
                            cfg->mbc_cfg[i].blk_id,
                            cfg->mbc_cfg[i].secure,
                            cfg->mbc_cfg[i].glbac_id);
            }
        }
    }
}

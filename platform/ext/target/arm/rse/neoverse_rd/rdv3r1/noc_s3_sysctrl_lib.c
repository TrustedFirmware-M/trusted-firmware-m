/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "bootutil/bootutil_log.h"
#include "host_device_definition.h"
#include "host_base_address.h"
#include "noc_s3_lib.h"

#include <stddef.h>

/* Chip ID enumerations */
enum rse_supported_chip_ids {
    RSE_CHIP_ID_0 = 0,
    RSE_CHIP_ID_1,
    RSE_CHIP_ID_2,
    RSE_CHIP_ID_3,
    RSE_MAX_SUPPORTED_CHIPS,
};

#define MHU_SEND_FRAME_SIZE     (RSE_MAX_SUPPORTED_CHIPS - 1)

/* System Control NoC S3 component nodes */
static const struct noc_s3_component_node sysctrl_rse_main_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_RSE_MAIN_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_scp_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_SCP_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_mcp_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_MCP_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_rse_scp_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_RSE_SCP_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_app_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_APP_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_lcp_asni  = {
    .type = NOC_S3_ASNI,
    .id = SYSCTRL_LCP_ASNI_ID,
};

static const struct noc_s3_component_node sysctrl_rsm_amni  = {
    .type = NOC_S3_AMNI,
    .id = SYSCTRL_RSM_AMNI_ID,
};

static const struct noc_s3_component_node sysctrl_rsm_pmni  = {
    .type = NOC_S3_PMNI,
    .id = SYSCTRL_RSM_PMNI_ID,
};

static const struct noc_s3_component_node sysctrl_rse_scp_amni  = {
    .type = NOC_S3_AMNI,
    .id = SYSCTRL_RSE_SCP_AMNI_ID,
};

static const struct noc_s3_component_node sysctrl_rse_mcp_amni  = {
    .type = NOC_S3_AMNI,
    .id = SYSCTRL_RSE_MCP_AMNI_ID,
};

static const struct noc_s3_component_node sysctrl_app_amni  = {
    .type = NOC_S3_AMNI,
    .id = SYSCTRL_APP_AMNI_ID,
};

static const struct noc_s3_component_node sysctrl_lcp_amni  = {
    .type = NOC_S3_AMNI,
    .id = SYSCTRL_LCP_AMNI_ID,
};

/*
 * System Control NoC S3 is the interconnect between the AXI interfaces of
 * RSE, SCP/MCP and the CMN interconnect. Following block diagram depicts an
 * abstract overview of the routing map for these interfaces.
 *
 *                             +-----+
 *                             |     |
 *                             |     |---------------------------> tcu_apbm
 *                             |     |
 *                             |     |
 *                             |     |                 +-----+
 *                             |     |-----------------| APU |---> rse_scp_axim
 *                             |     |                 +-----+
 *                             |     |
 * rse_main_axis ------------->|     |                 +-----+
 *                             |     |-----------------| APU |---> rse_mcp_axim
 *                             |     |                 +-----+
 *                             |     |
 *                             |     |       +-----+
 *                             |     |------>|     |
 *                             |     |       |     |-------------> cmn_apbm
 *                             +-----+       |     |
 *                                           |     |   +-----+
 *                                           |     |---| APU |---> rsm_axim
 *      scp_axis --------------------------->|     |   +-----+
 *                                           |     |
 *                                           |     |   +-----+
 *                                           |     |---| APU |---> rsm_apbm
 *                             +-----+       |     |   +-----+
 *                             |     |       |     |
 *                             |     |------>|     |   +-----+
 *                             |     |       |     |---| APU |---> app_axim
 *                             |     |       |     |   +-----+
 *                  +-----+    |     |       +-----+
 *      mcp_axis ---| APU |--->|     |
 *                  +-----+    |     |
 *                             |     |       +-----+
 *                             |     |       |     |
 *                             |     |------>|     |
 *                             |     |       |     |
 *                             +-----+       |     |
 *                                           |     |
 *                                           |     |-------------> app_scp_axim
 *                             +-----+       |     |
 *                             |     |       |     |
 *                             |     |------>|     |
 *                             |     |       |     |
 *                             |     |       |     |
 *                  +-----+    |     |       +-----+
 *      app_axis ---| APU |--->|     |
 *                  +-----+    |     |
 *                             |     |
 *                             |     |
 *                             |     |---------------------------> app_mcp_axim
 *                             |     |
 *                             +-----+
 *
 *                             +-----+
 *                             |     |
 *                  +-----+    |     |
 *      lcp_axis ---| APU |--->|     |---------------------------> lcp_scp_axim
 *                  +-----+    |     |
 *                             |     |
 *                             +-----+
 *
 *                             +-----+
 *                             |     |
 *                             |     |          +-----+
 *  rse_scp_axis ------------->|     |----------| APU |---------> lcp_axim
 *                             |     |          +-----+
 *                             |     |
 *                             +-----+
 *
 * The following matrix shows the connections within System Control NoC S3.
 *
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |            | rse_main_axis | scp_axis | mcp_axis | rse_scp_axis | app_axis | lcp_axis |
 * +============+===============+==========+==========+==============+==========+==========+
 * |rse_scp_axim|       X       |          |          |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |rse_mcp_axim|       X       |          |          |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  rsm_axim  |       X       |    X     |    X     |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  rsm_apbm  |       X       |    X     |    X     |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  cmn_apbm  |       X       |    X     |    X     |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  tcu_apbm  |       X       |          |          |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  lcp_axim  |               |          |          |      X       |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |  app_axim  |       X       |    X     |    X     |              |          |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |app_scp_axim|               |          |    X     |              |    X     |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |app_mcp_axim|               |          |          |              |    X     |          |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 * |lcp_scp_axim|               |          |          |              |          |    X     |
 * +------------+---------------+----------+----------+--------------+----------+----------+
 *  NOTE: 'X' means there is a connection.
 */

/*
 * Request originating from RSE ATU is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info rse_main_axis_0_psam[] = {
    /* Shared SRAM + AP Memory Expansion 1 */
    {
        HOST_AP_SHARED_SRAM_PHYS_BASE,
        HOST_AP_MEM_EXP_1_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* System Control Block NoC S3 */
    {
        HOST_SYSCTRL_NOC_S3_PHYS_BASE,
        HOST_SYSCTRL_NOC_S3_PHYS_LIMIT,
        SYSCTRL_CONFIG_SPACE_ID
    },
    /*
     * System Fabric NoC S3 + Peripheral Block NoC S3 + Interconnect
     * NoC S3 + Debug Block NCI GPV + UART Peripherals + Generic refclk +
     * AP Watchdog peripherals + SID + ECC error record registers
     */
    {
        HOST_FABRIC_NOC_S3_PHYS_BASE,
        HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* ECC error record for RSM block */
    {
        HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_BASE,
        HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_RSM_PMNI_ID
    },
    /*
     * Generic refclk registers + AP<->SCP MHUv3 registers +
     * AP<->MCP MHUv3 registers + AP<->RSE MHUv3 registers +
     * SCP<->SCP MHU registers + MCP<->MCP MHU registers
     */
    {
        HOST_GENERIC_REFCLK_CNTREAD_PHYS_BASE,
        HOST_MCP_TO_MCP_MHU_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* RSE<->RSE Cross-chip MHU registers */
    {
        HOST_RSE_TO_RSE_MHU_PHYS_BASE,
        HOST_RSE_TO_RSE_MHU_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Timer synchronization registers + STM */
    {
        HOST_SYNCNT_MSTUPDTVAL_ADDR_PHYS_BASE,
        HOST_STM_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Shared RSM SRAM */
    {
        HOST_RSM_SRAM_PHYS_BASE,
        HOST_RSM_SRAM_PHYS_LIMIT,
        SYSCTRL_RSM_AMNI_ID
    },
    /* GIC-700 */
    {
        HOST_GIC_700_PHYS_BASE,
        HOST_GIC_700_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* PCIe NCI Memory Space 1 + DRAM */
    {
        HOST_PCIE_NCI_1_PHYS_BASE,
        HOST_DRAM_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* CMN GPV */
    {
        HOST_CMN_GPV_PHYS_BASE,
        HOST_CMN_GPV_PHYS_LIMIT,
        SYSCTRL_CMN_PMNI_ID
    },
    /*
     * LCP peripherals + Cluster Utility memory region +
     * Memory Controller + MPE register space
     */
    {
        HOST_CLUST_UTIL_PHYS_BASE,
        HOST_MPE_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* IO Block SMMU + NCI GPV + PCIe CTRL + RAS Agent + PHY */
    {
        HOST_IO_BLOCK_PHYS_BASE,
        HOST_IO_BLOCK_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SYSCTRL SMMU */
    {
        HOST_SYSCTRL_SMMU_PHYS_BASE,
        HOST_SYSCTRL_SMMU_PHYS_LIMIT,
        SYSCTRL_TCU_PMNI_ID
    },
    /* AP Memory Expansion 2 */
    {
        HOST_AP_MEM_EXP_2_PHYS_BASE,
        HOST_AP_MEM_EXP_2_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Debug Memory Map */
    {
        HOST_DEBUG_MMAP_PHYS_BASE,
        HOST_DEBUG_MMAP_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
};

/*
 * Request coming from RSE ATU is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info rse_main_axis_1_psam[] = {
    /*
     * PCIe NCI Memory space 2 + PCIe NCI Memory space 3 + DRAM +
     * AP Memory Expansion 3
     */
    {
        HOST_PCIE_NCI_2_PHYS_BASE,
        HOST_AP_MEM_EXP_3_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SCP Access region */
    {
        HOST_SCP_PHYS_BASE,
        HOST_SCP_PHYS_LIMIT,
        SYSCTRL_RSE_SCP_AMNI_ID
    },
    /* MCP Access region */
    {
        HOST_MCP_PHYS_BASE,
        HOST_MCP_PHYS_LIMIT,
        SYSCTRL_RSE_MCP_AMNI_ID
    }
};

/*
 * Multi-chip environment contains set of MHUs for RSE-RSE cross chip
 * communications. Request coming from RSE ATU is mapped to targets based on
 * following address map for RSE chip-to-chip MHU send frame between the
 * current chip and other 3 chips.
 */
static const struct noc_s3_psam_reg_cfg_info
        rse_main_axis_psam_mhu_send_frame[][MHU_SEND_FRAME_SIZE] =
{
    [RSE_CHIP_ID_0] = {
        /* RSE Cross chip 0 to chip 1 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(0,1),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(0,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 0 to chip 2 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(0,2),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(0,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 0 to chip 3 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(0,3),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(0,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_1] =  {
        /* RSE Cross chip 1 to chip 0 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(1,0),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(1,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 1 to chip 2 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(1,2),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(1,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 1 to chip 3 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(1,3),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(1,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_2] =  {
        /* RSE Cross chip 2 to chip 0 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(2,0),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(2,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 2 to chip 1 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(2,1),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(2,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 2 to chip 3 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(2,3),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(2,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_3] = {
        /* RSE Cross chip 3 to chip 0 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(3,0),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(3,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 3 to chip 1 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(3,1),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(3,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* RSE Cross chip 3 to chip 2 MHU send frame */
        {
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(3,2),
            HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(3,2),
            SYSCTRL_APP_AMNI_ID
        },
    },
};

/*
 * Request originating from SCP ATU is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info scp_axis_0_psam[] = {
    /* Shared SRAM + AP Memory Expansion 1 */
    {
        HOST_AP_SHARED_SRAM_PHYS_BASE,
        HOST_AP_MEM_EXP_1_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* System Control Block NoC S3 */
    {
        HOST_SYSCTRL_NOC_S3_PHYS_BASE,
        HOST_SYSCTRL_NOC_S3_PHYS_LIMIT,
        SYSCTRL_CONFIG_SPACE_ID
    },
    /* Generic refclk registers */
    {
        HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE,
        HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SCP ECC error record */
    {
        HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
        HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SCP/MCP RSM ECC error record */
    {
        HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_BASE,
        HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_RSM_PMNI_ID
    },
    /* Refclk registers */
    {
        HOST_GENERIC_REFCLK_CNTREAD_PHYS_BASE,
        HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* AP<->SCP MHUv3 registers */
    {
        HOST_AP_NS_SCP_MHUV3_PHYS_BASE,
        HOST_AP_RT_SCP_MHUV3_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Shared RSM SRAM */
    {
        HOST_RSM_SRAM_PHYS_BASE,
        HOST_RSM_SRAM_PHYS_LIMIT,
        SYSCTRL_RSM_AMNI_ID
    },
    /* CMN GPV */
    {
        HOST_CMN_GPV_PHYS_BASE,
        HOST_CMN_GPV_PHYS_LIMIT,
        SYSCTRL_CMN_PMNI_ID
    },
    /* Memory Controller + MPE register space */
    {
        HOST_MPE_PHYS_BASE,
        HOST_MPE_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* LCP peripherals + Cluster Utility memory region */
    {
        HOST_CLUST_UTIL_PHYS_BASE,
        HOST_CLUST_UTIL_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SMMU + NCI GPV + PCIe CTRL + RAS Agent + PHY */
    {
        HOST_IO_BLOCK_PHYS_BASE,
        HOST_IO_BLOCK_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* AP Memory Expansion 2 */
    {
        HOST_AP_MEM_EXP_2_PHYS_BASE,
        HOST_AP_MEM_EXP_2_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
};

/*
 * Request coming from SCP ATU is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info scp_axis_1_psam[] = {
    /*
     * PCIe NCI Memory space 2 + PCIe NCI Memory space 3 + DRAM +
     * AP Memory Expansion 3
     */
    {
        HOST_PCIE_NCI_2_PHYS_BASE,
        HOST_PCIE_NCI_3_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
};

/*
 * Multi-chip environment contains set of MHUs for SCP-SCP cross chip
 * communications. Request coming from SCP ATU is mapped to targets based on
 * following address map for SCP chip-to-chip MHU send frame between the
 * current chip and other 3 chips.
 */
static const struct noc_s3_psam_reg_cfg_info
            scp_axis_psam_mhu_send_frame[][MHU_SEND_FRAME_SIZE] =
{
    [RSE_CHIP_ID_0] = {
        /* SCP Cross chip 0 to chip 1 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(0,1),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(0,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 0 to chip 2 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(0,2),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(0,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 0 to chip 3 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(0,3),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(0,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_1] =  {
        /* SCP Cross chip 1 to chip 0 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(1,0),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(1,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 1 to chip 2 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(1,2),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(1,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 1 to chip 3 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(1,3),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(1,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_2] =  {
        /* SCP Cross chip 2 to chip 0 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(2,0),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(2,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 2 to chip 1 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(2,1),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(2,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 2 to chip 3 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(2,3),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(2,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_3] = {
        /* SCP Cross chip 3 to chip 0 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(3,0),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(3,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 3 to chip 1 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(3,1),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(3,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* SCP Cross chip 3 to chip 2 MHU send frame */
        {
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(3,2),
            HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(3,2),
            SYSCTRL_APP_AMNI_ID
        },
    },
};

/*
 * Request originating from MCP ATU is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info mcp_axis_psam[] = {
    /* Shared SRAM */
    {
        HOST_AP_SHARED_SRAM_PHYS_BASE,
        HOST_AP_SHARED_SRAM_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Generic refclk registers */
    {
        HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE,
        HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT,
        SYSCTRL_APP_SCP_AMNI_ID
    },
    /* AP ECC error record */
    {
        HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
        HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* SCP/MCP RSM ECC error record */
    {
        HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_BASE,
        HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_RSM_PMNI_ID
    },
    /* AP<->MCP MHUv3 registers + AP<->RSE MHUv3 registers */
    {
        HOST_AP_NS_MCP_MHUV3_SEND_BASE,
        HOST_AP_RL_RSE_MHUV3_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* MCP<->MCP MHU registers */
    {
        HOST_MCP_TO_MCP_MHU_PHYS_BASE,
        HOST_MCP_TO_MCP_MHU_PHYS_LIMIT,
        SYSCTRL_APP_AMNI_ID
    },
    /* Shared RSM SRAM */
    {
        HOST_RSM_SRAM_PHYS_BASE,
        HOST_RSM_SRAM_PHYS_LIMIT,
        SYSCTRL_RSM_AMNI_ID
    },
};

/*
 * Multi-chip environment contains set of MHUs for MCP-MCP cross chip
 * communications. Request coming from MCP ATU is mapped to targets based on
 * following address map for MCP chip-to-chip MHU send frame between the
 * current chip and other 3 chips.
 */
static const struct noc_s3_psam_reg_cfg_info
            mcp_axis_psam_mhu_send_frame[][MHU_SEND_FRAME_SIZE] =
{
    [RSE_CHIP_ID_0] = {
        /* MCP Cross chip 0 to chip 1 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(0,1),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(0,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 0 to chip 2 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(0,2),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(0,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 0 to chip 3 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(0,3),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(0,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_1] =  {
        /* MCP Cross chip 1 to chip 0 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(1,0),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(1,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 1 to chip 2 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(1,2),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(1,2),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 1 to chip 3 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(1,3),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(1,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_2] =  {
        /* MCP Cross chip 2 to chip 0 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(2,0),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(2,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 2 to chip 1 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(2,1),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(2,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 2 to chip 3 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(2,3),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(2,3),
            SYSCTRL_APP_AMNI_ID
        },
    },
    [RSE_CHIP_ID_3] = {
        /* MCP Cross chip 3 to chip 0 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(3,0),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(3,0),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 3 to chip 1 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(3,1),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(3,1),
            SYSCTRL_APP_AMNI_ID
        },
        /* MCP Cross chip 3 to chip 2 MHU send frame */
        {
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(3,2),
            HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(3,2),
            SYSCTRL_APP_AMNI_ID
        },
    },
};

/*
 * Accesses from RSE and SCP targeting LCP address space are handled by a
 * NIC-400 which then forwards only the bottom [20:0] address bits of the
 * request to rse_scp_axis interface. The bottom [20:0] address bits
 * (range: 0x0 - 0x1FFFFF) are sent from NIC-400 to System Control NoC S3
 * for APU filtering of request from RSE/SCP to LCPs.
 */
static const struct noc_s3_psam_reg_cfg_info rse_scp_axis_psam[] = {
    {
        HOST_CLUS_UTIL_LCP_SMCF_OFF_ADDR_PHYS_BASE,
        HOST_CLUS_UTIL_MPMM_OFF_ADDR_PHYS_LIMIT,
        SYSCTRL_LCP_AMNI_ID
    },
};

/*
 * Request originating from AP is mapped to targets based on following
 * address map.
 */
static const struct noc_s3_psam_reg_cfg_info app_axis_psam[] = {
    /*
     * Generic refclk + AP Watchdog peripherals + SID + ECC error record
     * registers
     */
    {
        HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE,
        HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
        SYSCTRL_APP_SCP_AMNI_ID
    },
    /* Refclk registers */
    {
        HOST_GENERIC_REFCLK_CNTREAD_PHYS_BASE,
        HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT,
        SYSCTRL_APP_SCP_AMNI_ID
    },
    /* AP<->SCP MHUv3 registers */
    {
        HOST_AP_NS_SCP_MHUV3_PHYS_BASE,
        HOST_AP_RT_SCP_MHUV3_PHYS_LIMIT,
        SYSCTRL_APP_SCP_AMNI_ID
    },
    /* AP<->MCP MHUv3 registers */
    {
        HOST_AP_NS_MCP_MHUV3_SEND_BASE,
        HOST_AP_RT_MCP_MHUV3_PHYS_LIMIT,
        SYSCTRL_APP_MCP_AMNI_ID
    },
    /* AP<->RSE MHUv3 registers */
    {
        HOST_AP_NS_RSE_MHUV3_PHYS_BASE,
        HOST_AP_RL_RSE_MHUV3_PHYS_LIMIT,
        SYSCTRL_APP_SCP_AMNI_ID
    },
};

/* Request from LCP is targeted completely to LCP_SCP_AXIM */
static const struct noc_s3_psam_reg_cfg_info lcp_axis_psam[] = {
    {
        HOST_LCP_MMAP_PHYS_BASE,
        HOST_LCP_MMAP_PHYS_LIMIT,
        SYSCTRL_LCP_SCP_AMNI_ID
    },
};

/*
 * Requester side MCP AXIS APU to check access permission targeting Generic
 * refclk in SCP and shared RSM SRAM
 */
static const struct noc_s3_apu_reg_cfg_info mcp_axis_apu[] = {
    /* Root read-write permission : Generic refclk registers */
    INIT_APU_REGION(HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE,
                    HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Full permission : Shared RSM SRAM */
    INIT_APU_REGION(HOST_RSM_SRAM_PHYS_BASE,
                    HOST_RSM_SRAM_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Completer side RSM AXIM APU to check access permission targeting Shared RAM
 * between RSE, SCP and MCP
 */
static const struct noc_s3_apu_reg_cfg_info rsm_axim_apu[] = {
    INIT_APU_REGION(HOST_RSM_SRAM_PHYS_BASE,
                    HOST_RSM_SRAM_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_N_SEC_RW),
};

/*
 * RSM APBM APU to check the ECC Error record register block for Shared RAM
 * between RSE, SCP and MCP
 */
static const struct noc_s3_apu_reg_cfg_info rsm_apbm_apu[] = {
    INIT_APU_REGION(HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Completer side RSE-SCP AXIM APU to check access permission targeting the SCP
 */
static const struct noc_s3_apu_reg_cfg_info rse_scp_axim_apu[] = {
    INIT_APU_REGION(HOST_SCP_PHYS_BASE,
                    HOST_SCP_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Completer side RSE-MCP AXIM APU to check access permission targeting the MCP
 */
static const struct noc_s3_apu_reg_cfg_info rse_mcp_axim_apu[] = {
    INIT_APU_REGION(HOST_MCP_PHYS_BASE,
                    HOST_MCP_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Requester side APP AXIS APU to check access permission targeting the
 * peripherals in SCP, MCP and RSE
 */
static const struct noc_s3_apu_reg_cfg_info app_axis_apu[] = {
    /* Root read-write permission : Generic refclk registers */
    INIT_APU_REGION(HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE,
                    HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Full permission : AP Watchdog peripheral */
    INIT_APU_REGION(HOST_AP_NS_WDOG_PHYS_BASE,
                    HOST_AP_NS_WDOG_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Root read-write permission : AP Watchdog peripheral */
    INIT_APU_REGION(HOST_AP_RT_WDOG_PHYS_BASE,
                    HOST_AP_RT_WDOG_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Secure read-write permission : AP Watchdog peripheral */
    INIT_APU_REGION(HOST_AP_S_WDOG_PHYS_BASE,
                    HOST_AP_S_WDOG_PHYS_LIMIT,
                    NOC_S3_SEC_RW),
    /* Full permission : SID */
    INIT_APU_REGION(HOST_SID_PHYS_BASE,
                    HOST_SID_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Secure read-write permission : AP ECC error record */
    INIT_APU_REGION(HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_SEC_RW),
    /* Full permission : AP ECC error record */
    INIT_APU_REGION(HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Root read-write permission : AP ECC error record */
    INIT_APU_REGION(HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Realm read-write permission : AP ECC error record */
    INIT_APU_REGION(HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
    /*
     * Secure & Root read-write permission : SCP/MCP/RSE ECC error record +
     * SCP/MCP/RSE RSM ECC error record + Generic refclk registers +
     * AP refclk registers
     */
    INIT_APU_REGION(HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT,
                    NOC_S3_SEC_RW),
    /* Full permission : AP<->SCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_NS_SCP_MHUV3_PHYS_BASE,
                    HOST_AP_NS_SCP_MHUV3_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Secure & Root read-write permission : AP<->SCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_S_SCP_MHUV3_PHYS_BASE,
                    HOST_AP_S_SCP_MHUV3_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    /* Root read-write permission : AP<->SCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_RT_SCP_MHUV3_PHYS_BASE,
                    HOST_AP_RT_SCP_MHUV3_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Full permission : AP<->MCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_NS_MCP_MHUV3_SEND_BASE,
                    HOST_AP_NS_MCP_MHUV3_SEND_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Secure read-write permission : AP<->MCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_S_MCP_MHUV3_PHYS_BASE,
                    HOST_AP_S_MCP_MHUV3_PHYS_LIMIT,
                    NOC_S3_SEC_RW),
    /* Root read-write permission : AP<->MCP MHUv3 registers */
    INIT_APU_REGION(HOST_AP_RT_MCP_MHUV3_PHYS_BASE,
                    HOST_AP_RT_MCP_MHUV3_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Full permission : AP<->RSE MHUv3 registers */
    INIT_APU_REGION(HOST_AP_NS_RSE_MHUV3_PHYS_BASE,
                    HOST_AP_NS_RSE_MHUV3_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Secure read-write permission : AP<->RSE MHUv3 registers */
    INIT_APU_REGION(HOST_AP_S_RSE_MHUV3_PHYS_BASE,
                    HOST_AP_S_RSE_MHUV3_PHYS_LIMIT,
                    NOC_S3_SEC_RW),
    /* Root read-write permission : AP<->RSE MHUv3 registers */
    INIT_APU_REGION(HOST_AP_RT_RSE_MHUV3_PHYS_BASE,
                    HOST_AP_RT_RSE_MHUV3_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    /* Root & Realm read-write permission : AP<->RSE MHUv3 registers */
    INIT_APU_REGION(HOST_AP_RL_RSE_MHUV3_PHYS_BASE,
                    HOST_AP_RL_RSE_MHUV3_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_REALM_RW),
};

/*
 * Completer side APP AXIM APU to check access permission targeting the IO
 * block and the memory controller + MPE registers space
 */
static const struct noc_s3_apu_reg_cfg_info app_axim_apu[] = {
    /*
     * Full permission for the entire AP address expect for the following
     * regions:
     * 1. Root & Secure read-write permission for IO integration control
     *    registers.
     * 2. Deny full access to MCP for Memory Controller, MPE register
     *    space, LCP peripherals and Cluster Utility region.
     */
    INIT_APU_REGION(HOST_AP_SHARED_SRAM_PHYS_BASE,
                    HOST_CMN_GPV_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_IO_BLOCK_PHYS_BASE,
                    HOST_IO_NCI_GPV_PHYS_LIMIT(0),
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_IO_INTEGRATION_CTRL_PHYS_BASE(0),
                    HOST_IO_INTEGRATION_CTRL_PHYS_LIMIT(0),
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_IO_RAS_AGENT_PHYS_BASE(0),
                    HOST_IO_RAS_AGENT_PHYS_LIMIT(0),
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_IO_EXP_INTERFACE_PHYS_BASE(0),
                    HOST_IO_NCI_GPV_PHYS_LIMIT(1),
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_IO_INTEGRATION_CTRL_PHYS_BASE(1),
                    HOST_IO_INTEGRATION_CTRL_PHYS_LIMIT(1),
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_IO_RAS_AGENT_PHYS_BASE(1),
                    HOST_IO_RAS_AGENT_PHYS_LIMIT(1),
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_IO_EXP_INTERFACE_PHYS_BASE(1),
                    HOST_IO_PCIE_CTRL_EXP_PHYS_LIMIT(1),
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_SYSCTRL_SMMU_PHYS_BASE,
                    HOST_AP_MEM_EXP_3_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    /* Allow only for RSE, SCP and AP */
    INIT_APU_REGION_WITH_ALL_ID_FILTER(HOST_MPE_PHYS_BASE,
                                       HOST_MPE_PHYS_LIMIT,
                                       /* mcp_perm */ 0,
                                       /* scp_perm */ NOC_S3_ALL_PERM,
                                       /* rse_perm */ NOC_S3_ALL_PERM,
                                       /* dap_perm */ 0),
    /* Allow only for RSE, SCP and AP */
    INIT_APU_REGION_WITH_ALL_ID_FILTER(HOST_CLUST_UTIL_PHYS_BASE,
                                       HOST_CLUST_UTIL_PHYS_LIMIT,
                                       /* mcp_perm */ 0,
                                       /* scp_perm */ NOC_S3_ALL_PERM,
                                       /* rse_perm */ NOC_S3_ALL_PERM,
                                       /* dap_perm */ 0),
};

/*
 * Completer side LCP AXIM APU to check access permission targeting the Cluster
 * Utility space.
 */
static const struct noc_s3_apu_reg_cfg_info lcp_axim_apu[] = {
    INIT_APU_REGION(HOST_CLUS_UTIL_LCP_SMCF_OFF_ADDR_PHYS_BASE,
                    HOST_CLUS_UTIL_LCP_SMCF_OFF_ADDR_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_CLUS_UTIL_CLUS_CTRL_OFF_ADDR_PHYS_BASE,
                    HOST_CLUS_UTIL_CLUS_CTRL_OFF_ADDR_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_CLUS_UTIL_PPU_OFF_ADDR_PHYS_BASE,
                    HOST_CLUS_UTIL_PPU_OFF_ADDR_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_CLUS_UTIL_AMU_OFF_ADDR_PHYS_BASE,
                    HOST_CLUS_UTIL_AMU_OFF_ADDR_PHYS_LIMIT,
                    NOC_S3_N_SEC_RW | NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_CLUS_UTIL_RAS_OFF_ADDR_PHYS_BASE,
                    HOST_CLUS_UTIL_MPMM_OFF_ADDR_PHYS_LIMIT,
                    NOC_S3_SEC_RW | NOC_S3_ROOT_RW),
};

/* Requester side LCP AXIS APU to check access permission targeting the SCP */
static const struct noc_s3_apu_reg_cfg_info lcp_axis_apu[] = {
    INIT_APU_REGION(HOST_AP_SHARED_SRAM_PHYS_BASE,
                    HOST_AP_MEM_EXP_3_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Configure Programmable System Address Map (PSAM) to setup the memory map and
 * its target ID for each requester in the System Control NoC S3 for nodes
 * under AON domain.
 */
static int32_t program_sysctrl_psam_aon(uint32_t chip_id)
{
    enum noc_s3_err err;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    noc_s3_print_discovery_tree(&SYSCTRL_NOC_S3_DEV, "Sysctrl NOC_S3 - AON");
#endif

    /* Populates all address maps into a table array to enable desired PSAMs */
    const struct noc_s3_psam_cfgs psam_table[] = {
        {
            .component = &sysctrl_rse_main_asni,
            .nh_region_count = ARRAY_SIZE(rse_main_axis_0_psam),
            .regions = rse_main_axis_0_psam,
            .add_chip_addr_offset = true,
        },
        {
            .component = &sysctrl_rse_main_asni,
            .nh_region_count = ARRAY_SIZE(rse_main_axis_1_psam),
            .regions = rse_main_axis_1_psam,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_rse_main_asni,
            .nh_region_count = MHU_SEND_FRAME_SIZE,
            .regions = rse_main_axis_psam_mhu_send_frame[chip_id],
        },
        {
            .component = &sysctrl_scp_asni,
            .nh_region_count = ARRAY_SIZE(scp_axis_0_psam),
            .regions = scp_axis_0_psam,
            .add_chip_addr_offset = true,
        },
        {
            .component = &sysctrl_scp_asni,
            .nh_region_count = ARRAY_SIZE(scp_axis_1_psam),
            .regions = scp_axis_1_psam,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_scp_asni,
            .nh_region_count = MHU_SEND_FRAME_SIZE,
            .regions = scp_axis_psam_mhu_send_frame[chip_id],
        },
        {
            .component = &sysctrl_mcp_asni,
            .nh_region_count = ARRAY_SIZE(mcp_axis_psam),
            .regions = mcp_axis_psam,
            .add_chip_addr_offset = true,
        },
        {
            .component = &sysctrl_mcp_asni,
            .nh_region_count = MHU_SEND_FRAME_SIZE,
            .regions = mcp_axis_psam_mhu_send_frame[chip_id],
        },
        {
            .component = &sysctrl_rse_scp_asni,
            .nh_region_count = ARRAY_SIZE(rse_scp_axis_psam),
            .regions = rse_scp_axis_psam,
            .add_chip_addr_offset = false,
        },
    };

    err = noc_s3_program_psam_table(&SYSCTRL_NOC_S3_DEV, psam_table,
            ARRAY_SIZE(psam_table));
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}

/*
 * Configure Access Protection Unit (APU) to setup access permission for each
 * memory region based on its target in System Control NoC S3 for nodes
 * under AON domain.
 */
static int32_t program_sysctrl_apu_aon(void)
{
    enum noc_s3_err err;

    /*
     * Populates all APU entry into a table array to configure and enable
     * desired APUs
     */
    const struct noc_s3_apu_cfgs apu_table[] = {
        {
            .component = &sysctrl_mcp_asni,
            .region_count = ARRAY_SIZE(mcp_axis_apu),
            .regions = mcp_axis_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_rsm_amni,
            .region_count = ARRAY_SIZE(rsm_axim_apu),
            .regions = rsm_axim_apu,
            .add_chip_addr_offset = true,
        },
        {
            .component = &sysctrl_rsm_pmni,
            .region_count = ARRAY_SIZE(rsm_apbm_apu),
            .regions = rsm_apbm_apu,
            .add_chip_addr_offset = true,
        },
        {
            .component = &sysctrl_rse_scp_amni,
            .region_count = ARRAY_SIZE(rse_scp_axim_apu),
            .regions = rse_scp_axim_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_rse_mcp_amni,
            .region_count = ARRAY_SIZE(rse_mcp_axim_apu),
            .regions = rse_mcp_axim_apu,
            .add_chip_addr_offset = false,
        },
    };

    err = noc_s3_program_apu_table(&SYSCTRL_NOC_S3_DEV, apu_table,
            ARRAY_SIZE(apu_table));
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}

/*
 * Configure Programmable System Address Map (PSAM) to setup the memory map and
 * its target ID for each requester in the System Control NoC S3 for nodes
 * under SYSTOP domain.
 */
static int32_t program_sysctrl_psam_systop(void)
{
    enum noc_s3_err err;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    noc_s3_print_discovery_tree(&SYSCTRL_NOC_S3_DEV, "Sysctrl NOC_S3 - SYSTOP");
#endif

    /* Populates all address maps into a table array to enable desired PSAMs */
    const struct noc_s3_psam_cfgs psam_table[] = {
        {
            .component = &sysctrl_app_asni,
            .nh_region_count = ARRAY_SIZE(app_axis_psam),
            .regions = app_axis_psam,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_lcp_asni,
            .nh_region_count = ARRAY_SIZE(lcp_axis_psam),
            .regions = lcp_axis_psam,
            .add_chip_addr_offset = false,
        },
    };

    err = noc_s3_program_psam_table(&SYSCTRL_NOC_S3_DEV, psam_table,
                                                    ARRAY_SIZE(psam_table));
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}

/*
 * Configure Access Protection Unit (APU) to setup access permission for each
 * memory region based on its target in System Control NoC S3 for nodes
 * under SYSTOP domain.
 */
static int32_t program_sysctrl_apu_systop(void)
{
    enum noc_s3_err err;

    /*
     * Populates all APU entry into a table array to configure and enable
     * desired APUs
     */
    const struct noc_s3_apu_cfgs apu_table[] = {
        {
            .component = &sysctrl_app_asni,
            .region_count = ARRAY_SIZE(app_axis_apu),
            .regions = app_axis_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_app_amni,
            .region_count = ARRAY_SIZE(app_axim_apu),
            .regions = app_axim_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_lcp_amni,
            .region_count = ARRAY_SIZE(lcp_axim_apu),
            .regions = lcp_axim_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &sysctrl_lcp_asni,
            .region_count = ARRAY_SIZE(lcp_axis_apu),
            .regions = lcp_axis_apu,
            .add_chip_addr_offset = false,
        },
    };

    err = noc_s3_program_apu_table(&SYSCTRL_NOC_S3_DEV, apu_table,
                                                        ARRAY_SIZE(apu_table));
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}

int32_t program_sysctrl_noc_s3_aon(uint32_t chip_id)
{
    if (chip_id >= RSE_MAX_SUPPORTED_CHIPS) {
        return -1;
    }

    if (program_sysctrl_psam_aon(chip_id) != 0) {
        return -1;
    }

    if (program_sysctrl_apu_aon() != 0) {
        return -1;
    }

    return 0;
}

int32_t program_sysctrl_noc_s3_systop(void)
{
    if (program_sysctrl_psam_systop() != 0) {
        return -1;
    }

    if (program_sysctrl_apu_systop() != 0) {
        return -1;
    }

    return 0;
}

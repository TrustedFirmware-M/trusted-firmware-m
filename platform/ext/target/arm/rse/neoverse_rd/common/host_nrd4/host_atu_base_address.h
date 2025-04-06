/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file host_atu_base_address.h
 * \brief This file defines the host (CSS) memory ATU addresses.
 */

#ifndef __HOST_ATU_BASE_ADDRESS_H__
#define __HOST_ATU_BASE_ADDRESS_H__

#include "platform_base_address.h"
#include "host_clus_util_lcp_memory_map.h"
#include "size_defs.h"

#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))

#define RSE_ATU_BASE_ID 0

enum rse_atu_ids {
    /*
     * ATU regions for loading firmware in BL2. Reused per firmware. Not used
     * outside BL2.
     */

    /* ID to use for region loading the header of an image */
    RSE_ATU_IMG_HDR_LOAD_ID = RSE_ATU_BASE_ID,
    /* ID to use for region loading the rest of an image */
    RSE_ATU_IMG_CODE_LOAD_ID,
    /* ID to use for region initializing firmware */
    RSE_ATU_FW_INIT_ID,

    /* ATU region ID for programming NoC S3 */
    RSE_ATU_NOC_S3_ID,
    /* ATU region ID for SYSCTRL SMMU */
    RSE_ATU_SYSCTRL_SMMU_ID,
};

/*
 * ATU controller enforces a minimum size and all regions are restricted to
 * align with it
 */
#define RSE_ATU_PAGE_SIZE       0x2000U /* 8KB */

/*
 * In flash the image is laid out like so:
 *
 * ┌────────┬──────┬─────────┐
 * │ HEADER │ CODE │ TRAILER │
 * ├────────┴──────┴─────────┤
 * │ Flash Image             │
 * └─────────────────────────┘
 *
 * However, when the image is loaded the CODE region needs to be at the start
 * of the memory for the host firmware to load.
 *
 * ┌──────┐
 * │ CODE │
 * ├──────┴─────────┐
 * │ ITCM           │
 * └────────────────┘
 *
 * MCUBoot requires a contiguous copy. To allow this while moving the header to
 * a different memory region, the ATU can be used to remap contiguous logical
 * addresses to different locations.
 *
 * The ATU has a fixed size page which limits where boundaries can be. In order
 * to have the ATU boundary match the header code boundary of the image, the
 * image is aligned in logical memory so the boundaries match.
 *
 *                  ┌───────────┐         ┌─────────────────────────┐
 * Physical Memory  │ Somewhere │         │ ITCM                    │
 *                  └──┬────────┤         ├──────┬─────────┬────────┘
 *                     │ HEADER │         │ CODE │ TRAILER │
 *                     └───▲────┘         └──────┴─▲───────┘
 *                         │                       │
 *                         │                       │
 *                  ┌──────┴─────┬─────────────────┴───────┐
 *  Logical Memory  │ ATU HEADER │ ATU CODE                │
 *                  └───┬────────┼──────┬─────────┬────────┘
 *                      │ HEADER │ CODE │ TRAILER │
 *                      └────────┴──────┴─────────┘
 *
 * If there is space at the end of the ITCM then the header can be placed there
 * effectively wrapping the start of the copy to end.
 *
 *                     ┌──────┬─────────┬────────┐
 *  Bootable Image     │ CODE │ TRAILER │ HEADER │
 *                     ├──────┴─────────┴────────┤
 *                     │ ATU CODE + TRAILER      │
 *  ATU window in host └──────────▲─┬────────────┤
 *  memory space                  │ │ ATU HEADER │
 *                                │ └──────▲─────┘
 *                            ┌───┼────────┘
 *                            │   └────────────┐
 *  ATU window in      ┌──────┴─────┬──────────┴──────────────┐
 *  local memory space │ ATU HEADER │ ATU CODE + TRAILER      │
 *                     ├───┬────────┼──────┬─────────┬────────┘
 *  MCUBoot Image      │   │ HEADER │ CODE │ TRAILER │
 *                     │   ├────────┼──────┴─────────┘
 *                     │   │        │
 *                     │   │        └─────► HOST_<IMG>_IMG_CODE_BASE_S
 *                     │   │
 *                     │   └──────────────► HOST_<IMG>_IMG_HDR_BASE_S
 *                     │
 *                     └──────────────────► HOST_<IMG>_HDR_ATU_WINDOW_BASE_S
 *
 * Alternatively the header and/or trailer could be mapped to a different
 * memory such as the DTCM allowing the total image to be larger than the
 * original memory as long as the code fits. Remapping the trailer as well will
 * require an additional ATU region.
 *
 * Note: Regions not to scale
 */

/*
 * The ATU has a minimum page size of 8K and the page must be aligned to the
 * same sized block. The BL2_HEADER_SIZE is typically smaller than that at 1K.
 * The end of the header needs to align to the end of the ATU so the code can
 * be at the start of the next ATU region. So create an ATU window of 8K and
 * place the header at 7K offset.
 */
#define RSE_IMG_HDR_ATU_WINDOW_SIZE ALIGN_UP(BL2_HEADER_SIZE, RSE_ATU_PAGE_SIZE)

/* MSCP INIT CTRL region logical address start */
#define RSE_MSCP_INIT_CTRL_ATU_BASE  HOST_ACCESS_BASE_S
/* MSCP INIT CTRL region ATU size */
#define RSE_MSCP_INIT_CTRL_SIZE      ALIGN_UP(0x1000U, RSE_ATU_PAGE_SIZE)

/*
 * RSE ATU Regions for image loading
 * Note: these need to consistent with values used when signing the images.
 * Note: MCUBoot requires that the logical addresses do not overlap.
 */

/* ****************************************************************************
 *                                   SCP                                      *
 * ****************************************************************************
 */

/* SCP ATU HEADER logical address start */
#define HOST_SCP_HDR_ATU_WINDOW_BASE_S  (RSE_MSCP_INIT_CTRL_ATU_BASE +      \
                                         RSE_MSCP_INIT_CTRL_SIZE)
/* SCP Image address start, offset so end of HEADER is at end of ATU HEADER */
#define HOST_SCP_IMG_HDR_BASE_S         (HOST_SCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE -      \
                                         BL2_HEADER_SIZE)
/* SCP Code region and SCP ATU CODE logical address start */
#define HOST_SCP_IMG_CODE_BASE_S        (HOST_SCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* SCP ATU CODE size (aligned size of SCP image) */
#define HOST_SCP_ATU_SIZE               ALIGN_UP(SIZE_DEF_SCP_IMAGE,        \
                                                 RSE_ATU_PAGE_SIZE)
/* SCP HEADER physical address start (mapped to end of SCP ITCM) */
#define HOST_SCP_HDR_PHYS_BASE          (HOST_SCP_PHYS_BASE +               \
                                         HOST_SCP_ATU_SIZE -                \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* SCP INIT CTRL region logical address start */
#define HOST_SCP_INIT_CTRL_BASE_S    RSE_MSCP_INIT_CTRL_ATU_BASE
/* SCP INIT CTRL region ATU size */
#define HOST_SCP_INIT_CTRL_SIZE      RSE_MSCP_INIT_CTRL_SIZE
/* SCP INIT CTRL region ATU id */
#define HOST_SCP_INIT_CTRL_ATU_ID    RSE_ATU_FW_INIT_ID

/* ****************************************************************************
 *                                   MCP                                      *
 * ****************************************************************************
 */

/* MCP ATU HEADER logical address start */
#define HOST_MCP_HDR_ATU_WINDOW_BASE_S  (HOST_SCP_IMG_CODE_BASE_S +         \
                                         HOST_SCP_ATU_SIZE)
/* MCP Image address start, offset so end of HEADER is at end of ATU HEADER */
#define HOST_MCP_IMG_HDR_BASE_S         (HOST_MCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE -      \
                                         BL2_HEADER_SIZE)
/* MCP Code region and MCP ATU CODE logical address start */
#define HOST_MCP_IMG_CODE_BASE_S        (HOST_MCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* MCP ATU CODE size (aligned size of MCP image) */
#define HOST_MCP_ATU_SIZE               ALIGN_UP(SIZE_DEF_MCP_IMAGE,        \
                                                 RSE_ATU_PAGE_SIZE)
/* MCP HEADER physical address start (mapped to end of MCP ITCM) */
#define HOST_MCP_HDR_PHYS_BASE          (HOST_MCP_PHYS_BASE +               \
                                         HOST_MCP_ATU_SIZE -                \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* MCP INIT CTRL region logical address start */
#define HOST_MCP_INIT_CTRL_BASE_S    RSE_MSCP_INIT_CTRL_ATU_BASE
/* MCP INIT CTRL region ATU size */
#define HOST_MCP_INIT_CTRL_SIZE      RSE_MSCP_INIT_CTRL_SIZE
/* MCP INIT CTRL region ATU id */
#define HOST_MCP_INIT_CTRL_ATU_ID    RSE_ATU_FW_INIT_ID

/* ****************************************************************************
 *                                   LCP                                      *
 * ****************************************************************************
 */

/*
 * All LCP use the same ATU region but map it to a different physical address
 * The physical address is the cluster utility space in AP address space which
 * has an address translation window for each LCP.
 */

/* LCP ATU HEADER logical address start */
#define HOST_LCP_HDR_ATU_WINDOW_BASE_S  (HOST_MCP_IMG_CODE_BASE_S +         \
                                         HOST_MCP_ATU_SIZE)
/* LCP Image address start, offset so end of HEADER is at end of ATU HEADER */
#define HOST_LCP_IMG_HDR_BASE_S         (HOST_LCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE -      \
                                         BL2_HEADER_SIZE)
/* LCP Code region and LCP ATU CODE logical address start */
#define HOST_LCP_IMG_CODE_BASE_S        (HOST_LCP_HDR_ATU_WINDOW_BASE_S +   \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* LCP ITCM window in AP address start for LCP N */
#define HOST_LCP_N_CODE_PHYS_BASE(n)    (HOST_LCP_N_PHYS_BASE(n) +          \
                                         HOST_LCP_ITCM_BASE)
/* LCP ATU CODE size (aligned size of LCP image) */
#define HOST_LCP_ATU_SIZE               ALIGN_UP(SIZE_DEF_LCP_IMAGE,        \
                                                 RSE_ATU_PAGE_SIZE)
/* LCP HEADER physical address start (mapped to end of LCP0 ITCM) */
#define HOST_LCP_0_HDR_PHYS_BASE        (HOST_LCP_N_CODE_PHYS_BASE(0) +     \
                                         HOST_LCP_ATU_SIZE -                \
                                         RSE_IMG_HDR_ATU_WINDOW_SIZE)

#define HOST_LCP_N_EXT_CTRL_BASE_S          RSE_MSCP_INIT_CTRL_ATU_BASE
#define HOST_LCP_N_EXT_CTRL_PHYS_BASE(n)    (HOST_LCP_N_PHYS_BASE(n) + \
                                             HOST_LCP_EXTENDED_CONTROL_BASE)
#define HOST_LCP_N_EXT_CTRL_SIZE            RSE_MSCP_INIT_CTRL_SIZE
#define HOST_LCP_N_EXT_CTRL_ATU_ID          RSE_ATU_FW_INIT_ID

/* ****************************************************************************
 *                                   AP BL1                                   *
 * ****************************************************************************
 */

/* AP BL1 ATU HEADER logical address start */
#define HOST_AP_BL1_HDR_ATU_WINDOW_BASE_S (HOST_LCP_IMG_CODE_BASE_S +          \
                                           HOST_LCP_ATU_SIZE)
/* AP BL1 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_AP_BL1_IMG_HDR_BASE_S        (HOST_AP_BL1_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* AP BL1 Code region and SCP ATU CODE logical address start */
#define HOST_AP_BL1_IMG_CODE_BASE_S       (HOST_AP_BL1_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* AP BL1 Shared SRAM physical address start */
#define HOST_AP_BL1_PHYS_BASE             HOST_AP_SHARED_SRAM_PHYS_BASE
/* AP BL1 ATU CODE size (aligned size of SCP image) */
#define HOST_AP_BL1_ATU_SIZE              ALIGN_UP(SIZE_DEF_AP_BL1_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* AP BL1 HEADER physical address start (mapped to end of AP ITCM) */
#define HOST_AP_BL1_HDR_PHYS_BASE         (HOST_AP_BL1_PHYS_BASE +             \
                                           HOST_AP_BL1_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/*
 * ATU region mapping to access System Control NoC S3 and Peripheral
 * NoC S3
 */
#define HOST_NOC_S3_BASE      (HOST_AP_BL1_IMG_CODE_BASE_S +                   \
                               HOST_AP_BL1_ATU_SIZE)
#define HOST_NOC_S3_SIZE      ALIGN_UP(0x1000000U, RSE_ATU_PAGE_SIZE)
#define HOST_NOC_S3_ATU_ID    RSE_ATU_NOC_S3_ID

/* ATU region mapping to access SYSCTRL SMMU */
#define HOST_SYSCTRL_SMMU_BASE      (HOST_NOC_S3_BASE + HOST_NOC_S3_SIZE)
#define HOST_SYSCTRL_SMMU_SIZE      0x100000U
#define HOST_SYSCTRL_SMMU_ATU_ID    RSE_ATU_SYSCTRL_SMMU_ID

#endif  /* __HOST_ATU_BASE_ADDRESS_H__ */

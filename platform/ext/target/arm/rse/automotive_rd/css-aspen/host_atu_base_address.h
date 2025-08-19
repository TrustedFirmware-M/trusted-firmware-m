/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_atu_base_address.h
 * \brief This file defines the host memory ATU addresses.
 */

#ifndef __HOST_ATU_BASE_ADDRESS_H__
#define __HOST_ATU_BASE_ADDRESS_H__

#include "atu_config.h"
#include "image_size_defs.h"
#include "platform_base_address.h"

#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))

/* Use the slots of the dynamic ATU as this platform makes direct calls to the ATU driver instead */
#define RSE_ATU_BASE_ID ATU_DYN_SLOT_START

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

    /* ATU region ID for AP secure flash */
    RSE_ATU_AP_FLASH_ID,
    /* ATU region ID for MHU shared DRAM between AP and RSE */
    RSE_ATU_AP_RSE_MAILBOX_ATU_ID,
    /* ATU region ID for programming SI ATU */
    RSE_ATU_SI_ATU_ID,
    /* ATU region ID for programming AP ATU */
    RSE_ATU_AP_ATU_ID,
};

/*
 * ATU controller enforces a minimum size and all regions are restricted to
 * align with it
 */
#define RSE_ATU_PAGE_SIZE       0x2000U /* 8KB */

/*
 * In flash the image is layered out like so:
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

/*
 * RSE ATU Regions for image loading
 * Note: these need to consistent with values used when signing the images.
 * Note: MCUBoot requires that the logical addresses do not overlap.
 */

/* AP BL2 */

/* AP BL2 ATU HEADER logical address start */
#define HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S HOST_ACCESS_BASE_S
/* AP BL2 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_AP_BL2_IMG_HDR_BASE_S        (HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* AP BL2 Code region logical address start */
#define HOST_AP_BL2_IMG_CODE_BASE_S       (HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* AP BL2 Shared SRAM physical address start */
#define HOST_AP_BL2_PHYS_BASE             (HOST_AP_SHARED_SRAM_PHYS_BASE +     \
                                           0x82000UL)
/* AP BL2 ATU CODE size */
#define HOST_AP_BL2_ATU_SIZE              ALIGN_UP(SIZE_DEF_AP_BL2_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* AP BL2 HEADER physical address start (mapped to end of AP ITCM) */
#define HOST_AP_BL2_HDR_PHYS_BASE         (HOST_AP_BL2_PHYS_BASE +             \
                                           HOST_AP_BL2_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* SI CL0 */

/* SI CL0 ATU HEADER logical address start */
#define HOST_SI_CL0_HDR_ATU_WINDOW_BASE_S (HOST_AP_BL2_IMG_CODE_BASE_S +       \
                                           HOST_AP_BL2_ATU_SIZE)
/* SI CL0 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_SI_CL0_IMG_HDR_BASE_S        (HOST_SI_CL0_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* SI CL0 Code region logical address start */
#define HOST_SI_CL0_IMG_CODE_BASE_S       (HOST_SI_CL0_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* SI CL0 Shared SRAM physical address start */
#define HOST_SI_CL0_PHYS_BASE             HOST_SI_CL0_SRAM_PHYS_BASE
/* SI CL0 ATU CODE size */
#define HOST_SI_CL0_ATU_SIZE              ALIGN_UP(SIZE_DEF_SI_CL0_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* SI CL0 HEADER physical address start (mapped to end of SI CL0 ITCM) */
#define HOST_SI_CL0_HDR_PHYS_BASE         (HOST_SI_CL0_PHYS_BASE +             \
                                           HOST_SI_CL0_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* Last RSE logical address used for loading images */
#define RSE_IMAGE_LOADING_END             (HOST_SI_CL0_IMG_CODE_BASE_S +       \
                                           HOST_SI_CL0_ATU_SIZE)

/* SI CL0 Cluster Utility Bus logical address start */
#define HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S RSE_IMAGE_LOADING_END
/* SI CL0 Cluster Utility Bus physical address start */
#define HOST_SI_CL0_CUB_BASE              HOST_SI_CL0_CL_UTIL_BASE
/* SI CL0 Cluster Utility Bus ATU size */
#define HOST_SI_CL0_CUB_SIZE              ALIGN_UP(0x120000U,                  \
                                                   RSE_ATU_PAGE_SIZE)
/* SI CL0 Cluster Utility Bus ATU region id */
#define HOST_SI_CL0_CUB_ATU_ID            RSE_ATU_FW_INIT_ID

/* ATU region mapping to access AP secure flash */
#define HOST_AP_FLASH_BASE      (HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S +           \
                                 HOST_SI_CL0_CUB_SIZE)
#define HOST_AP_FLASH_SIZE      ALIGN_UP(AP_BOOT_FLASH_SIZE, RSE_ATU_PAGE_SIZE)
#define HOST_AP_FLASH_PHY_BASE  (HOST_AP_MEM_EXP_PHYS_BASE + HOST_AP_MEM_EXP_FLASH_OFFSET)
#define HOST_AP_FLASH_ATU_ID    RSE_ATU_AP_FLASH_ID

/* ATU region mapping to access SI's ATU from RSE */
#define HOST_SI_ATU_BASE_S         (HOST_AP_FLASH_BASE + HOST_AP_FLASH_SIZE)
#define HOST_SI_ATU_PHYS_BASE      0x4000031000000ULL
#define HOST_SI_ATU_GPV_SIZE       ALIGN_UP(0x10000, RSE_ATU_PAGE_SIZE)
#define HOST_SI_ATU_ID             RSE_ATU_SI_ATU_ID

/* ATU region mapping to access AP's ATU from RSE */
#define HOST_AP_ATU_BASE_S         (HOST_SI_ATU_BASE_S + HOST_SI_ATU_GPV_SIZE)
#define HOST_AP_ATU_PHYS_BASE      0x20000D0080000ULL
#define HOST_AP_ATU_GPV_SIZE       ALIGN_UP(0x10000, RSE_ATU_PAGE_SIZE)
#define HOST_AP_ATU_ID             RSE_ATU_AP_ATU_ID

/*
 * ATU region for AP<->RSE MHU outband message buffer
 * HOST_AP_RSE_MAILBOX_BASE_S: Logical address at which the RSE should access
 *                             the AP<->RSE outband msg buffer.
 *
 * HOST_AP_RSE_MAILBOX_PHYS_BASE: Physical address of outband msg buffer
 *                                located in the AP Shared RAM region.
 *
 * HOST_AP_RSE_MAILBOX_ATU_SIZE: Size of outband msg buffer.
 */
#define HOST_AP_RSE_MAILBOX_BASE_S     (HOST_AP_ATU_BASE_S + HOST_AP_ATU_GPV_SIZE)
#define HOST_AP_RSE_MAILBOX_PHYS_BASE  UINT64_C(0xFFFFC000)
#define HOST_AP_RSE_MAILBOX_ATU_SIZE   ALIGN_UP(0x4000, RSE_ATU_PAGE_SIZE)

/* SI PIK logical address start */
#define HOST_SI_PIK_ATU_WINDOW_BASE_S (HOST_AP_RSE_MAILBOX_BASE_S +      \
                                       HOST_AP_RSE_MAILBOX_ATU_SIZE)
/* SI PIK base address */
#define HOST_SI_PIK_PHYS_BASE         0x400002A600000ULL
/* SI PIK ATU size */
#define HOST_SI_PIK_SIZE              ALIGN_UP(0x10000U, RSE_ATU_PAGE_SIZE)
/* SI PIK ATU region id */
#define HOST_SI_PIK_ATU_ID            RSE_ATU_FW_INIT_ID

/* ATU region mapping to access Protected Storage */
#define HOST_ACCESS_PS_BASE_S      (HOST_ACCESS_BASE_NS + RSE_FLASH_IMG_SIZE)
#define HOST_ACCESS_PS_BASE_OFFSET RSE_FLASH_IMG_SIZE
#define HOST_FLASH0_PS_BASE        (0x8000060000000ULL + RSE_FLASH_IMG_SIZE)
#define HOST_FLASH0_PS_SIZE        RSE_FLASH_PS_SIZE

/* ATU region mapping to access Internal Storage */
#define HOST_ACCESS_ITS_BASE_S      (HOST_ACCESS_PS_BASE_S + \
                                     HOST_FLASH0_PS_SIZE)
#define HOST_ACCESS_ITS_BASE_OFFSET (HOST_ACCESS_PS_BASE_OFFSET + \
                                     HOST_FLASH0_PS_SIZE)
#define HOST_FLASH0_ITS_BASE        (HOST_FLASH0_PS_BASE + HOST_FLASH0_PS_SIZE)
#define HOST_FLASH0_ITS_SIZE        RSE_FLASH_ITS_SIZE

#endif  /* __HOST_ATU_BASE_ADDRESS_H__ */

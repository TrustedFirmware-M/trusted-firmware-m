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

#include "image_size_defs.h"
#include "platform_base_address.h"

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

    /* ATU region ID for AP secure flash */
    RSE_ATU_AP_FLASH_ID,
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

/* ATU region mapping to access AP secure flash */
#define HOST_AP_FLASH_BASE      HOST_ACCESS_BASE_S
#define HOST_AP_FLASH_SIZE      ALIGN_UP(AP_BOOT_FLASH_SIZE, RSE_ATU_PAGE_SIZE)
#define HOST_AP_FLASH_PHY_BASE  (HOST_AP_MEM_EXP_PHYS_BASE + HOST_AP_MEM_EXP_FLASH_OFFSET)
#define HOST_AP_FLASH_ATU_ID    RSE_ATU_AP_FLASH_ID

#endif  /* __HOST_ATU_BASE_ADDRESS_H__ */

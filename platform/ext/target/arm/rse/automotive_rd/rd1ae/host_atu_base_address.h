/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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

/**
 * \file host_atu_base_address.h
 * \brief This file defines the host memory ATU addresses.
 */

#ifndef __HOST_ATU_BASE_ADDRESS_H__
#define __HOST_ATU_BASE_ADDRESS_H__

#include "image_size_defs.h"
#include "platform_base_address.h"

#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))

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

/* SCP */

/* SCP ATU HEADER logical address start */
#define HOST_SCP_HDR_ATU_WINDOW_BASE_S  HOST_ACCESS_BASE_S
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

/* SCP shared memory for SCMI transport */
#define SCP_SHARED_MEMORY_PHYS_BASE 0x2F000000UL

/* AP BL2 */

/* AP BL2 ATU HEADER logical address start */
#define HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S (HOST_SCP_IMG_CODE_BASE_S +          \
                                           HOST_SCP_ATU_SIZE)
/* AP BL2 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_AP_BL2_IMG_HDR_BASE_S        (HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* AP BL2 Code region and SCP ATU CODE logical address start */
#define HOST_AP_BL2_IMG_CODE_BASE_S       (HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* AP BL2 Shared SRAM physical address start */
#define HOST_AP_BL2_PHYS_BASE             (HOST_AP_SHARED_SRAM_PHYS_BASE +     \
                                           0x42000UL)
/* AP BL2 ATU CODE size (aligned size of SCP image) */
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
/* SI CL0 Code region and SCP ATU CODE logical address start */
#define HOST_SI_CL0_IMG_CODE_BASE_S       (HOST_SI_CL0_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* SI CL0 Shared SRAM physical address start */
#define HOST_SI_CL0_PHYS_BASE             HOST_SI_CL0_SRAM_PHYS_BASE
/* SI CL0 ATU CODE size (aligned size of SCP image) */
#define HOST_SI_CL0_ATU_SIZE              ALIGN_UP(SIZE_DEF_SI_CL0_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* SI CL0 HEADER physical address start (mapped to end of SI CL0 ITCM) */
#define HOST_SI_CL0_HDR_PHYS_BASE         (HOST_SI_CL0_PHYS_BASE +             \
                                           HOST_SI_CL0_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* SI CL1 */

/* SI CL1 ATU HEADER logical address start */
#define HOST_SI_CL1_HDR_ATU_WINDOW_BASE_S (HOST_SI_CL0_IMG_CODE_BASE_S +       \
                                           HOST_SI_CL0_ATU_SIZE)
/* SI CL1 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_SI_CL1_IMG_HDR_BASE_S        (HOST_SI_CL1_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* SI CL1 Code region and SCP ATU CODE logical address start */
#define HOST_SI_CL1_IMG_CODE_BASE_S       (HOST_SI_CL1_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* SI CL1 Shared SRAM physical address start */
#define HOST_SI_CL1_PHYS_BASE             HOST_SI_CL1_SRAM_PHYS_BASE
/* SI CL1 ATU CODE size (aligned size of SCP image) */
#define HOST_SI_CL1_ATU_SIZE              ALIGN_UP(SIZE_DEF_SI_CL1_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* SI CL1 HEADER physical address start (mapped to end of SI CL1 ITCM) */
#define HOST_SI_CL1_HDR_PHYS_BASE         (HOST_SI_CL1_PHYS_BASE +             \
                                           HOST_SI_CL1_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* SI CL2 */

/* SI CL2 ATU HEADER logical address start */
#define HOST_SI_CL2_HDR_ATU_WINDOW_BASE_S (HOST_SI_CL1_IMG_CODE_BASE_S +       \
                                           HOST_SI_CL1_ATU_SIZE)
/* SI CL2 Image address start, offset so end of HEADER at end of ATU HEADER */
#define HOST_SI_CL2_IMG_HDR_BASE_S        (HOST_SI_CL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE -       \
                                           BL2_HEADER_SIZE)
/* SI CL2 Code region and SCP ATU CODE logical address start */
#define HOST_SI_CL2_IMG_CODE_BASE_S       (HOST_SI_CL2_HDR_ATU_WINDOW_BASE_S + \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)
/* SI CL2 Shared SRAM physical address start */
#define HOST_SI_CL2_PHYS_BASE             HOST_SI_CL2_SRAM_PHYS_BASE
/* SI CL2 ATU CODE size (aligned size of SCP image) */
#define HOST_SI_CL2_ATU_SIZE              ALIGN_UP(SIZE_DEF_SI_CL2_IMAGE,      \
                                                   RSE_ATU_PAGE_SIZE)
/* SI_CL2 HEADER physical address start (mapped to end of SI CL2 ITCM) */
#define HOST_SI_CL2_HDR_PHYS_BASE         (HOST_SI_CL2_PHYS_BASE +             \
                                           HOST_SI_CL2_ATU_SIZE -              \
                                           RSE_IMG_HDR_ATU_WINDOW_SIZE)

/* Last RSE logical address used for loading images */
#define RSE_IMAGE_LOADING_END             (HOST_SI_CL2_IMG_CODE_BASE_S +       \
                                           HOST_SI_CL2_ATU_SIZE)

/* SCP sysctrl region logical address start */
#define HOST_SCP_INIT_CTRL_BASE_S    RSE_IMAGE_LOADING_END
/* SCP sysctrl region physical address start */
#define HOST_SCP_INIT_CTRL_PHYS_BASE 0x1000050050000ULL
/* SCP sysctrl region ATU size */
#define HOST_SCP_INIT_CTRL_SIZE      ALIGN_UP(0x1000U, RSE_ATU_PAGE_SIZE)

/* ATU region mapping to access System Control NoC S3 and Peripheral NoC S3 */
#define HOST_NOC_S3_BASE      (HOST_SCP_INIT_CTRL_BASE_S +                \
                                 HOST_SCP_INIT_CTRL_SIZE)
#define HOST_NOC_S3_SIZE      ALIGN_UP(0x1000000U, RSE_ATU_PAGE_SIZE)

/* ATU region mapping to access AP secure flash */
#define HOST_AP_FLASH_BASE      (HOST_NOC_S3_BASE + HOST_NOC_S3_SIZE)
#define HOST_AP_FLASH_SIZE      ALIGN_UP(AP_BOOT_FLASH_SIZE, RSE_ATU_PAGE_SIZE)
#define HOST_AP_FLASH_PHY_BASE  HOST_AP_MEM_EXP_1_PHYS_BASE

/* Safety Island GIC View 0 region physical address start */
#define HOST_SI_GIC_VIEW_0_PHYS_BASE    0x8000030000000ULL
/* Safety Island GIC region ATU size */
#define HOST_SI_GIC_VIEW_SIZE           0x400000U

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

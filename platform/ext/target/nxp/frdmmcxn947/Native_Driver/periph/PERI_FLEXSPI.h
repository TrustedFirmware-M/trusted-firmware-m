/*
** ###################################################################
**     Processors:          MCXN247VAB
**                          MCXN247VDF
**                          MCXN247VKL
**                          MCXN247VPB
**                          MCXN526VDF_cm33_core0
**                          MCXN526VDF_cm33_core1
**                          MCXN526VKL_cm33_core0
**                          MCXN526VKL_cm33_core1
**                          MCXN527VAB_cm33_core0
**                          MCXN527VAB_cm33_core1
**                          MCXN527VDF_cm33_core0
**                          MCXN527VDF_cm33_core1
**                          MCXN527VKL_cm33_core0
**                          MCXN527VKL_cm33_core1
**                          MCXN536VAB_cm33_core0
**                          MCXN536VAB_cm33_core1
**                          MCXN536VDF_cm33_core0
**                          MCXN536VDF_cm33_core1
**                          MCXN536VKL_cm33_core0
**                          MCXN536VKL_cm33_core1
**                          MCXN536VPB_cm33_core0
**                          MCXN536VPB_cm33_core1
**                          MCXN537VAB_cm33_core0
**                          MCXN537VAB_cm33_core1
**                          MCXN537VDF_cm33_core0
**                          MCXN537VDF_cm33_core1
**                          MCXN537VKL_cm33_core0
**                          MCXN537VKL_cm33_core1
**                          MCXN537VPB_cm33_core0
**                          MCXN537VPB_cm33_core1
**                          MCXN546VAB_cm33_core0
**                          MCXN546VAB_cm33_core1
**                          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VAB_cm33_core0
**                          MCXN547VAB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN556SCDF_cm33_core0
**                          MCXN556SCDF_cm33_core1
**                          MCXN946VAB_cm33_core0
**                          MCXN946VAB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VAB_cm33_core0
**                          MCXN947VAB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250811
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLEXSPI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXSPI
 *
 * CMSIS Peripheral Access Layer for FLEXSPI
 */

#if !defined(PERI_FLEXSPI_H_)
#define PERI_FLEXSPI_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN247VAB) || defined(CPU_MCXN247VDF) || defined(CPU_MCXN247VKL) || defined(CPU_MCXN247VPB))
#include "MCXN247_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core0) || defined(CPU_MCXN526VKL_cm33_core0))
#include "MCXN526_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core1) || defined(CPU_MCXN526VKL_cm33_core1))
#include "MCXN526_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core0) || defined(CPU_MCXN527VDF_cm33_core0) || defined(CPU_MCXN527VKL_cm33_core0))
#include "MCXN527_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core1) || defined(CPU_MCXN527VDF_cm33_core1) || defined(CPU_MCXN527VKL_cm33_core1))
#include "MCXN527_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core0) || defined(CPU_MCXN536VDF_cm33_core0) || defined(CPU_MCXN536VKL_cm33_core0) || defined(CPU_MCXN536VPB_cm33_core0))
#include "MCXN536_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core1) || defined(CPU_MCXN536VDF_cm33_core1) || defined(CPU_MCXN536VKL_cm33_core1) || defined(CPU_MCXN536VPB_cm33_core1))
#include "MCXN536_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core0) || defined(CPU_MCXN537VDF_cm33_core0) || defined(CPU_MCXN537VKL_cm33_core0) || defined(CPU_MCXN537VPB_cm33_core0))
#include "MCXN537_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core1) || defined(CPU_MCXN537VDF_cm33_core1) || defined(CPU_MCXN537VKL_cm33_core1) || defined(CPU_MCXN537VPB_cm33_core1))
#include "MCXN537_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core0) || defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core1) || defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core0) || defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core1) || defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core0))
#include "MCXN556S_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core1))
#include "MCXN556S_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core0) || defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core1) || defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core0) || defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core1) || defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FLEXSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_Peripheral_Access_Layer FLEXSPI Peripheral Access Layer
 * @{
 */

/** FLEXSPI - Size of Registers Arrays */
#define FLEXSPI_AHBRXBUFCR0_COUNT                 8u
#define FLEXSPI_FLSHCR0_COUNT                     4u
#define FLEXSPI_FLSHCR1_COUNT                     4u
#define FLEXSPI_FLSHCR2_COUNT                     4u
#define FLEXSPI_DLLCR_COUNT                       2u
#define FLEXSPI_RFDR_COUNT                        32u
#define FLEXSPI_TFDR_COUNT                        32u
#define FLEXSPI_LUT_COUNT                         64u
#define FLEXSPI_IPEDCTXCTRLX_COUNT                2u

/** FLEXSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR0;                              /**< Module Control 0, offset: 0x0 */
  __IO uint32_t MCR1;                              /**< Module Control 1, offset: 0x4 */
  __IO uint32_t MCR2;                              /**< Module Control 2, offset: 0x8 */
  __IO uint32_t AHBCR;                             /**< AHB Bus Control, offset: 0xC */
  __IO uint32_t INTEN;                             /**< Interrupt Enable, offset: 0x10 */
  __IO uint32_t INTR;                              /**< Interrupt, offset: 0x14 */
  __IO uint32_t LUTKEY;                            /**< LUT Key, offset: 0x18 */
  __IO uint32_t LUTCR;                             /**< LUT Control, offset: 0x1C */
  __IO uint32_t AHBRXBUFCR0[FLEXSPI_AHBRXBUFCR0_COUNT]; /**< AHB Receive Buffer 0 Control 0..AHB Receive Buffer 7 Control 0, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[32];
  __IO uint32_t FLSHCR0[FLEXSPI_FLSHCR0_COUNT];    /**< Flash Control 0, array offset: 0x60, array step: 0x4 */
  __IO uint32_t FLSHCR1[FLEXSPI_FLSHCR1_COUNT];    /**< Flash Control 1, array offset: 0x70, array step: 0x4 */
  __IO uint32_t FLSHCR2[FLEXSPI_FLSHCR2_COUNT];    /**< Flash Control 2, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FLSHCR4;                           /**< Flash Control 4, offset: 0x94 */
       uint8_t RESERVED_2[8];
  __IO uint32_t IPCR0;                             /**< IP Control 0, offset: 0xA0 */
  __IO uint32_t IPCR1;                             /**< IP Control 1, offset: 0xA4 */
  __IO uint32_t IPCR2;                             /**< IP Control 2, offset: 0xA8 */
       uint8_t RESERVED_3[4];
  __IO uint32_t IPCMD;                             /**< IP Command, offset: 0xB0 */
  __IO uint32_t DLPR;                              /**< Data Learning Pattern, offset: 0xB4 */
  __IO uint32_t IPRXFCR;                           /**< IP Receive FIFO Control, offset: 0xB8 */
  __IO uint32_t IPTXFCR;                           /**< IP Transmit FIFO Control, offset: 0xBC */
  __IO uint32_t DLLCR[FLEXSPI_DLLCR_COUNT];        /**< DLL Control 0, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __I  uint32_t STS0;                              /**< Status 0, offset: 0xE0 */
  __I  uint32_t STS1;                              /**< Status 1, offset: 0xE4 */
  __I  uint32_t STS2;                              /**< Status 2, offset: 0xE8 */
  __I  uint32_t AHBSPNDSTS;                        /**< AHB Suspend Status, offset: 0xEC */
  __I  uint32_t IPRXFSTS;                          /**< IP Receive FIFO Status, offset: 0xF0 */
  __I  uint32_t IPTXFSTS;                          /**< IP Transmit FIFO Status, offset: 0xF4 */
       uint8_t RESERVED_5[8];
  __I  uint32_t RFDR[FLEXSPI_RFDR_COUNT];          /**< IP Receive FIFO Data 0..IP Receive FIFO Data 31, array offset: 0x100, array step: 0x4 */
  __O  uint32_t TFDR[FLEXSPI_TFDR_COUNT];          /**< IP TX FIFO Data 0..IP TX FIFO Data 31, array offset: 0x180, array step: 0x4 */
  __IO uint32_t LUT[FLEXSPI_LUT_COUNT];            /**< Lookup Table 0..Lookup Table 63, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[288];
  __IO uint32_t HADDRSTART;                        /**< HADDR REMAP Start Address, offset: 0x420 */
  __IO uint32_t HADDREND;                          /**< HADDR REMAP END ADDR, offset: 0x424 */
  __IO uint32_t HADDROFFSET;                       /**< HADDR Remap Offset, offset: 0x428 */
  __IO uint32_t IPEDCTRL;                          /**< IPED Function Control, offset: 0x42C */
  __IO uint32_t IPSNSZSTART0;                      /**< IPS Nonsecure Region 0 Start Address, offset: 0x430 */
  __IO uint32_t IPSNSZEND0;                        /**< IPS Nonsecure Region 0 End Address, offset: 0x434 */
  __IO uint32_t IPSNSZSTART1;                      /**< IPS Nonsecure Region 1 Start Address, offset: 0x438 */
  __IO uint32_t IPSNSZEND1;                        /**< IPS Nonsecure Region 1 End Address, offset: 0x43C */
  __IO uint32_t AHBBUFREGIONSTART0;                /**< Receive Buffer Start Address of Region 0, offset: 0x440 */
  __IO uint32_t AHBBUFREGIONEND0;                  /**< Receive Buffer Region 0 End Address, offset: 0x444 */
  __IO uint32_t AHBBUFREGIONSTART1;                /**< Receive Buffer Start Address of Region 1, offset: 0x448 */
  __IO uint32_t AHBBUFREGIONEND1;                  /**< Receive Buffer Region 1 End Address, offset: 0x44C */
  __IO uint32_t AHBBUFREGIONSTART2;                /**< Receive Buffer Start Address of Region 2, offset: 0x450 */
  __IO uint32_t AHBBUFREGIONEND2;                  /**< Receive Buffer Region 2 End Address, offset: 0x454 */
  __IO uint32_t AHBBUFREGIONSTART3;                /**< Receive Buffer Start Address of Region 3, offset: 0x458 */
  __IO uint32_t AHBBUFREGIONEND3;                  /**< Receive Buffer Region 3 End Address, offset: 0x45C */
       uint8_t RESERVED_7[160];
  __IO uint32_t IPEDCTXCTRL[FLEXSPI_IPEDCTXCTRLX_COUNT]; /**< IPED context control 0..IPED context control 1, array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_8[24];
  __IO uint32_t IPEDCTX0IV0;                       /**< IPED Context0 IV0, offset: 0x520 */
  __IO uint32_t IPEDCTX0IV1;                       /**< IPED Context0 IV1, offset: 0x524 */
  __IO uint32_t IPEDCTX0START;                     /**< Start Address of Region, offset: 0x528 */
  __IO uint32_t IPEDCTX0END;                       /**< End Address of Region, offset: 0x52C */
  __IO uint32_t IPEDCTX0AAD0;                      /**< IPED Context0 Additional Authenticated Data0, offset: 0x530 */
  __IO uint32_t IPEDCTX0AAD1;                      /**< IPED Context0 Additional Authenticated Data1, offset: 0x534 */
       uint8_t RESERVED_9[8];
  __IO uint32_t IPEDCTX1IV0;                       /**< IPED Context1 IV0, offset: 0x540 */
  __IO uint32_t IPEDCTX1IV1;                       /**< IPED Context1 IV1, offset: 0x544 */
  __IO uint32_t IPEDCTX1START;                     /**< Start Address of Region, offset: 0x548 */
  __IO uint32_t IPEDCTX1END;                       /**< End Address of Region, offset: 0x54C */
  __IO uint32_t IPEDCTX1AAD0;                      /**< IPED Context1 Additional Authenticated Data0, offset: 0x550 */
  __IO uint32_t IPEDCTX1AAD1;                      /**< IPED Context1 Additional Authenticated Data1, offset: 0x554 */
       uint8_t RESERVED_10[8];
  __IO uint32_t IPEDCTX2IV0;                       /**< IPED Context2 IV0, offset: 0x560 */
  __IO uint32_t IPEDCTX2IV1;                       /**< IPED Context2 IV1, offset: 0x564 */
  __IO uint32_t IPEDCTX2START;                     /**< Start Address of Region, offset: 0x568 */
  __IO uint32_t IPEDCTX2END;                       /**< End Address of Region, offset: 0x56C */
  __IO uint32_t IPEDCTX2AAD0;                      /**< IPED Context2 Additional Authenticated Data0, offset: 0x570 */
  __IO uint32_t IPEDCTX2AAD1;                      /**< IPED Context2 Additional Authenticated Data1, offset: 0x574 */
       uint8_t RESERVED_11[8];
  __IO uint32_t IPEDCTX3IV0;                       /**< IPED Context3 IV0, offset: 0x580 */
  __IO uint32_t IPEDCTX3IV1;                       /**< IPED Context3 IV1, offset: 0x584 */
  __IO uint32_t IPEDCTX3START;                     /**< Start Address of Region, offset: 0x588 */
  __IO uint32_t IPEDCTX3END;                       /**< End Address of Region, offset: 0x58C */
  __IO uint32_t IPEDCTX3AAD0;                      /**< IPED Context3 Additional Authenticated Data0, offset: 0x590 */
  __IO uint32_t IPEDCTX3AAD1;                      /**< IPED Context3 Additional Authenticated Data1, offset: 0x594 */
       uint8_t RESERVED_12[8];
  __IO uint32_t IPEDCTX4IV0;                       /**< IPED Context4 IV0, offset: 0x5A0 */
  __IO uint32_t IPEDCTX4IV1;                       /**< IPED Context4 IV1, offset: 0x5A4 */
  __IO uint32_t IPEDCTX4START;                     /**< Start Address of Region, offset: 0x5A8 */
  __IO uint32_t IPEDCTX4END;                       /**< End Address of Region, offset: 0x5AC */
  __IO uint32_t IPEDCTX4AAD0;                      /**< IPED Context4 Additional Authenticated Data0, offset: 0x5B0 */
  __IO uint32_t IPEDCTX4AAD1;                      /**< IPED Context4 Additional Authenticated Data1, offset: 0x5B4 */
       uint8_t RESERVED_13[8];
  __IO uint32_t IPEDCTX5IV0;                       /**< IPED Context5 IV0, offset: 0x5C0 */
  __IO uint32_t IPEDCTX5IV1;                       /**< IPED Context5 IV1, offset: 0x5C4 */
  __IO uint32_t IPEDCTX5START;                     /**< Start Address of Region, offset: 0x5C8 */
  __IO uint32_t IPEDCTX5END;                       /**< End Address of Region, offset: 0x5CC */
  __IO uint32_t IPEDCTX5AAD0;                      /**< IPED Context5 Additional Authenticated Data0, offset: 0x5D0 */
  __IO uint32_t IPEDCTX5AAD1;                      /**< IPED Context5 Additional Authenticated Data1, offset: 0x5D4 */
       uint8_t RESERVED_14[8];
  __IO uint32_t IPEDCTX6IV0;                       /**< IPED Context6 IV0, offset: 0x5E0 */
  __IO uint32_t IPEDCTX6IV1;                       /**< IPED Context6 IV1, offset: 0x5E4 */
  __IO uint32_t IPEDCTX6START;                     /**< Start Address of Region, offset: 0x5E8 */
  __IO uint32_t IPEDCTX6END;                       /**< End Address of Region, offset: 0x5EC */
  __IO uint32_t IPEDCTX6AAD0;                      /**< IPED Context6 Additional Authenticated Data0, offset: 0x5F0 */
  __IO uint32_t IPEDCTX6AAD1;                      /**< IPED Context6 Additional Authenticated Data1, offset: 0x5F4 */
} FLEXSPI_Type;

/* ----------------------------------------------------------------------------
   -- FLEXSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_Register_Masks FLEXSPI Register Masks
 * @{
 */

/*! @name MCR0 - Module Control 0 */
/*! @{ */

#define FLEXSPI_MCR0_SWRESET_MASK                (0x1U)
#define FLEXSPI_MCR0_SWRESET_SHIFT               (0U)
/*! SWRESET - Software Reset
 *  0b0..No impact
 *  0b1..Software reset
 */
#define FLEXSPI_MCR0_SWRESET(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SWRESET_SHIFT)) & FLEXSPI_MCR0_SWRESET_MASK)

#define FLEXSPI_MCR0_MDIS_MASK                   (0x2U)
#define FLEXSPI_MCR0_MDIS_SHIFT                  (1U)
/*! MDIS - Module Disable
 *  0b0..No impact
 *  0b1..Module disable
 */
#define FLEXSPI_MCR0_MDIS(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_MDIS_SHIFT)) & FLEXSPI_MCR0_MDIS_MASK)

#define FLEXSPI_MCR0_RXCLKSRC_MASK               (0x30U)
#define FLEXSPI_MCR0_RXCLKSRC_SHIFT              (4U)
/*! RXCLKSRC - Sample Clock Source for Flash Reading
 *  0b00..Dummy Read strobe that FlexSPI generates, looped back internally
 *  0b01..Dummy Read strobe that FlexSPI generates, looped back from DQS pad
 *  0b10..SCLK output clock and looped back from SCLK pad
 *  0b11..Flash-memory-provided read strobe and input from DQS pad
 */
#define FLEXSPI_MCR0_RXCLKSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_RXCLKSRC_SHIFT)) & FLEXSPI_MCR0_RXCLKSRC_MASK)

#define FLEXSPI_MCR0_SERCLKDIV_MASK              (0x700U)
#define FLEXSPI_MCR0_SERCLKDIV_SHIFT             (8U)
/*! SERCLKDIV - Serial Root Clock Divider
 *  0b000..Divided by 1
 *  0b001..Divided by 2
 *  0b010..Divided by 3
 *  0b011..Divided by 4
 *  0b100..Divided by 5
 *  0b101..Divided by 6
 *  0b110..Divided by 7
 *  0b111..Divided by 8
 */
#define FLEXSPI_MCR0_SERCLKDIV(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SERCLKDIV_SHIFT)) & FLEXSPI_MCR0_SERCLKDIV_MASK)

#define FLEXSPI_MCR0_HSEN_MASK                   (0x800U)
#define FLEXSPI_MCR0_HSEN_SHIFT                  (11U)
/*! HSEN - Half Speed Serial Flash Memory Access Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_MCR0_HSEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_HSEN_SHIFT)) & FLEXSPI_MCR0_HSEN_MASK)

#define FLEXSPI_MCR0_DOZEEN_MASK                 (0x1000U)
#define FLEXSPI_MCR0_DOZEEN_SHIFT                (12U)
/*! DOZEEN - Doze Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_MCR0_DOZEEN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_DOZEEN_SHIFT)) & FLEXSPI_MCR0_DOZEEN_MASK)

#define FLEXSPI_MCR0_COMBINATIONEN_MASK          (0x2000U)
#define FLEXSPI_MCR0_COMBINATIONEN_SHIFT         (13U)
/*! COMBINATIONEN - Combination Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_MCR0_COMBINATIONEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_COMBINATIONEN_SHIFT)) & FLEXSPI_MCR0_COMBINATIONEN_MASK)

#define FLEXSPI_MCR0_SCKFREERUNEN_MASK           (0x4000U)
#define FLEXSPI_MCR0_SCKFREERUNEN_SHIFT          (14U)
/*! SCKFREERUNEN - SCLK Free-running Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_MCR0_SCKFREERUNEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SCKFREERUNEN_SHIFT)) & FLEXSPI_MCR0_SCKFREERUNEN_MASK)

#define FLEXSPI_MCR0_LEARNEN_MASK                (0x8000U)
#define FLEXSPI_MCR0_LEARNEN_SHIFT               (15U)
/*! LEARNEN - Data Learning Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_MCR0_LEARNEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_LEARNEN_SHIFT)) & FLEXSPI_MCR0_LEARNEN_MASK)

#define FLEXSPI_MCR0_IPGRANTWAIT_MASK            (0xFF0000U)
#define FLEXSPI_MCR0_IPGRANTWAIT_SHIFT           (16U)
/*! IPGRANTWAIT - Timeout Wait Cycle for IP Command Grant */
#define FLEXSPI_MCR0_IPGRANTWAIT(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_IPGRANTWAIT_SHIFT)) & FLEXSPI_MCR0_IPGRANTWAIT_MASK)

#define FLEXSPI_MCR0_AHBGRANTWAIT_MASK           (0xFF000000U)
#define FLEXSPI_MCR0_AHBGRANTWAIT_SHIFT          (24U)
/*! AHBGRANTWAIT - Timeouts Wait Cycle for AHB command Grant */
#define FLEXSPI_MCR0_AHBGRANTWAIT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_AHBGRANTWAIT_SHIFT)) & FLEXSPI_MCR0_AHBGRANTWAIT_MASK)
/*! @} */

/*! @name MCR1 - Module Control 1 */
/*! @{ */

#define FLEXSPI_MCR1_AHBBUSWAIT_MASK             (0xFFFFU)
#define FLEXSPI_MCR1_AHBBUSWAIT_SHIFT            (0U)
/*! AHBBUSWAIT - AHB Bus Wait */
#define FLEXSPI_MCR1_AHBBUSWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR1_AHBBUSWAIT_SHIFT)) & FLEXSPI_MCR1_AHBBUSWAIT_MASK)

#define FLEXSPI_MCR1_SEQWAIT_MASK                (0xFFFF0000U)
#define FLEXSPI_MCR1_SEQWAIT_SHIFT               (16U)
/*! SEQWAIT - Command Sequence Wait */
#define FLEXSPI_MCR1_SEQWAIT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR1_SEQWAIT_SHIFT)) & FLEXSPI_MCR1_SEQWAIT_MASK)
/*! @} */

/*! @name MCR2 - Module Control 2 */
/*! @{ */

#define FLEXSPI_MCR2_CLRAHBBUFOPT_MASK           (0x800U)
#define FLEXSPI_MCR2_CLRAHBBUFOPT_SHIFT          (11U)
/*! CLRAHBBUFOPT - Clear AHB Buffer
 *  0b0..Not cleared automatically
 *  0b1..Cleared automatically
 */
#define FLEXSPI_MCR2_CLRAHBBUFOPT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_CLRAHBBUFOPT_SHIFT)) & FLEXSPI_MCR2_CLRAHBBUFOPT_MASK)

#define FLEXSPI_MCR2_CLRLEARNPHASE_MASK          (0x4000U)
#define FLEXSPI_MCR2_CLRLEARNPHASE_SHIFT         (14U)
/*! CLRLEARNPHASE - Clear Learn Phase Selection
 *  0b0..No impact
 *  0b1..Reset sample clock phase selection to 0
 */
#define FLEXSPI_MCR2_CLRLEARNPHASE(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_CLRLEARNPHASE_SHIFT)) & FLEXSPI_MCR2_CLRLEARNPHASE_MASK)

#define FLEXSPI_MCR2_SAMEDEVICEEN_MASK           (0x8000U)
#define FLEXSPI_MCR2_SAMEDEVICEEN_SHIFT          (15U)
/*! SAMEDEVICEEN - Same Device Enable
 *  0b0..In Individual mode, FLSHA1CRx and FLSHA2CRx, FLSHB1CRx and FLSHB2CRx settings are applied to Flash A1,
 *       A2, B1, B2 separately. In Parallel mode, FLSHA1CRx register setting is applied to Flash A1 and B1, FLSHA2CRx
 *       register setting is applied to Flash A2 and B2. FLSHB1CRx and FLSHB2CRx register settings are ignored.
 *  0b1..FLSHA1CR0, FLSHA1CR1, and FLSHA1CR2 register settings are applied to Flash A1, A2, B1, B2. FLSHA2CRx,
 *       FLSHB1CRx, and FLSHB2CRx settings are ignored.
 */
#define FLEXSPI_MCR2_SAMEDEVICEEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_SAMEDEVICEEN_SHIFT)) & FLEXSPI_MCR2_SAMEDEVICEEN_MASK)

#define FLEXSPI_MCR2_SCKBDIFFOPT_MASK            (0x80000U)
#define FLEXSPI_MCR2_SCKBDIFFOPT_SHIFT           (19U)
/*! SCKBDIFFOPT - SCLK Port B Differential Output
 *  0b0..Use B_SCLK pad as port B SCLK clock output. Port B flash memory access is available.
 *  0b1..Use B_SCLK pad as port A SCLK inverted clock output (Differential clock to A_SCLK). Port B flash memory access is not available.
 */
#define FLEXSPI_MCR2_SCKBDIFFOPT(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_SCKBDIFFOPT_SHIFT)) & FLEXSPI_MCR2_SCKBDIFFOPT_MASK)

#define FLEXSPI_MCR2_RXCLKSRC_B_MASK             (0x600000U)
#define FLEXSPI_MCR2_RXCLKSRC_B_SHIFT            (21U)
/*! RXCLKSRC_B - Port B Receiver Clock Source
 *  0b00..Dummy read strobe that FlexSPI generates, looped back internally.
 *  0b01..Dummy read strobe that FlexSPI generates, looped back from DQS pad.
 *  0b10..SCLK output clock and looped back from SCLK pad
 *  0b11..Flash-memory-provided read strobe and input from DQS pad
 */
#define FLEXSPI_MCR2_RXCLKSRC_B(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_RXCLKSRC_B_SHIFT)) & FLEXSPI_MCR2_RXCLKSRC_B_MASK)

#define FLEXSPI_MCR2_RX_CLK_SRC_DIFF_MASK        (0x800000U)
#define FLEXSPI_MCR2_RX_CLK_SRC_DIFF_SHIFT       (23U)
/*! RX_CLK_SRC_DIFF - Sample Clock Source Different
 *  0b0..Use MCR0[RXCLKSRC] for Port A and Port B. MCR2[RXCLKSRC_B] is ignored and MCR0[RXCLKSRC] selects the
 *       Sample Clock source for Flash Reading of both ports A and B.
 *  0b1..Use MCR0[RXCLKSRC] for Port A, and MCR2[RXCLKSRC_B] for Port B. MCR0[RXCLKSRC] selects the Sample Clock
 *       source for Flash Reading of port A (A_SCLK) and MCR2[RXCLKSRC_B] selects the Sample Clock source for Flash
 *       Reading of port B (B_SCLK).
 */
#define FLEXSPI_MCR2_RX_CLK_SRC_DIFF(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_RX_CLK_SRC_DIFF_SHIFT)) & FLEXSPI_MCR2_RX_CLK_SRC_DIFF_MASK)

#define FLEXSPI_MCR2_RESUMEWAIT_MASK             (0xFF000000U)
#define FLEXSPI_MCR2_RESUMEWAIT_SHIFT            (24U)
/*! RESUMEWAIT - Resume Wait Duration */
#define FLEXSPI_MCR2_RESUMEWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_RESUMEWAIT_SHIFT)) & FLEXSPI_MCR2_RESUMEWAIT_MASK)
/*! @} */

/*! @name AHBCR - AHB Bus Control */
/*! @{ */

#define FLEXSPI_AHBCR_APAREN_MASK                (0x1U)
#define FLEXSPI_AHBCR_APAREN_SHIFT               (0U)
/*! APAREN - AHB Parallel Mode Enable
 *  0b0..Flash is accessed in Individual mode.
 *  0b1..Flash is accessed in Parallel mode.
 */
#define FLEXSPI_AHBCR_APAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_APAREN_SHIFT)) & FLEXSPI_AHBCR_APAREN_MASK)

#define FLEXSPI_AHBCR_CLRAHBRXBUF_MASK           (0x2U)
#define FLEXSPI_AHBCR_CLRAHBRXBUF_SHIFT          (1U)
/*! CLRAHBRXBUF - Clear AHB Receive Buffer
 *  0b0..No impact.
 *  0b1..Enable clear operation.
 */
#define FLEXSPI_AHBCR_CLRAHBRXBUF(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_CLRAHBRXBUF_SHIFT)) & FLEXSPI_AHBCR_CLRAHBRXBUF_MASK)

#define FLEXSPI_AHBCR_CLRAHBTXBUF_MASK           (0x4U)
#define FLEXSPI_AHBCR_CLRAHBTXBUF_SHIFT          (2U)
/*! CLRAHBTXBUF - Clear AHB Transmit Buffer
 *  0b0..No impact.
 *  0b1..Enable clear operation.
 */
#define FLEXSPI_AHBCR_CLRAHBTXBUF(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_CLRAHBTXBUF_SHIFT)) & FLEXSPI_AHBCR_CLRAHBTXBUF_MASK)

#define FLEXSPI_AHBCR_CACHABLEEN_MASK            (0x8U)
#define FLEXSPI_AHBCR_CACHABLEEN_SHIFT           (3U)
/*! CACHABLEEN - Cacheable Read Access Enable
 *  0b0..Disabled. When an AHB bus cacheable read access occurs, FlexSPI does not check whether it hit the AHB transmit buffer.
 *  0b1..Enabled. When an AHB bus cacheable read access occurs, FlexSPI first checks whether the access hit the AHB transmit buffer.
 */
#define FLEXSPI_AHBCR_CACHABLEEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_CACHABLEEN_SHIFT)) & FLEXSPI_AHBCR_CACHABLEEN_MASK)

#define FLEXSPI_AHBCR_BUFFERABLEEN_MASK          (0x10U)
#define FLEXSPI_AHBCR_BUFFERABLEEN_SHIFT         (4U)
/*! BUFFERABLEEN - Bufferable Write Access Enable
 *  0b0..Disabled. For all AHB write accesses (bufferable or nonbufferable), FlexSPI returns AHB Bus Ready after
 *       transmitting all data and finishing command.
 *  0b1..Enabled. For AHB bufferable write access, FlexSPI returns AHB Bus Ready when the arbitrator grants the
 *       AHB command. FlexSPI does not wait for the AHB command to finish.
 */
#define FLEXSPI_AHBCR_BUFFERABLEEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_BUFFERABLEEN_SHIFT)) & FLEXSPI_AHBCR_BUFFERABLEEN_MASK)

#define FLEXSPI_AHBCR_PREFETCHEN_MASK            (0x20U)
#define FLEXSPI_AHBCR_PREFETCHEN_SHIFT           (5U)
/*! PREFETCHEN - AHB Read Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_AHBCR_PREFETCHEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_PREFETCHEN_SHIFT)) & FLEXSPI_AHBCR_PREFETCHEN_MASK)

#define FLEXSPI_AHBCR_READADDROPT_MASK           (0x40U)
#define FLEXSPI_AHBCR_READADDROPT_SHIFT          (6U)
/*! READADDROPT - AHB Read Address Option
 *  0b0..AHB read burst start address alignment is limited when flash memory is accessed in parallel mode or flash is word-addressable.
 *  0b1..AHB read burst start address alignment is not limited. FlexSPI fetches more data than the AHB burst requires for address alignment.
 */
#define FLEXSPI_AHBCR_READADDROPT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_READADDROPT_SHIFT)) & FLEXSPI_AHBCR_READADDROPT_MASK)

#define FLEXSPI_AHBCR_RESUMEDISABLE_MASK         (0x80U)
#define FLEXSPI_AHBCR_RESUMEDISABLE_SHIFT        (7U)
/*! RESUMEDISABLE - AHB Read Resume Disable
 *  0b0..Suspended AHB read prefetch resumes when AHB is IDLE.
 *  0b1..Suspended AHB read prefetch does not resume once aborted,
 */
#define FLEXSPI_AHBCR_RESUMEDISABLE(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_RESUMEDISABLE_SHIFT)) & FLEXSPI_AHBCR_RESUMEDISABLE_MASK)

#define FLEXSPI_AHBCR_READSZALIGN_MASK           (0x400U)
#define FLEXSPI_AHBCR_READSZALIGN_SHIFT          (10U)
/*! READSZALIGN - AHB Read Size Alignment
 *  0b0..Register settings such as PREFETCH_EN determine AHB read size.
 *  0b1..AHB read size to up size to 8 bytes aligned, no prefetching
 */
#define FLEXSPI_AHBCR_READSZALIGN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_READSZALIGN_SHIFT)) & FLEXSPI_AHBCR_READSZALIGN_MASK)

#define FLEXSPI_AHBCR_ALIGNMENT_MASK             (0x300000U)
#define FLEXSPI_AHBCR_ALIGNMENT_SHIFT            (20U)
/*! ALIGNMENT - AHB Boundary Alignment
 *  0b00..No limit
 *  0b01..1 KB
 *  0b10..512 bytes
 *  0b11..256 bytes
 */
#define FLEXSPI_AHBCR_ALIGNMENT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_ALIGNMENT_SHIFT)) & FLEXSPI_AHBCR_ALIGNMENT_MASK)

#define FLEXSPI_AHBCR_AFLASHBASE_MASK            (0xE0000000U)
#define FLEXSPI_AHBCR_AFLASHBASE_SHIFT           (29U)
/*! AFLASHBASE - AHB Memory-Mapped Flash Base Address */
#define FLEXSPI_AHBCR_AFLASHBASE(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_AFLASHBASE_SHIFT)) & FLEXSPI_AHBCR_AFLASHBASE_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable */
/*! @{ */

#define FLEXSPI_INTEN_IPCMDDONEEN_MASK           (0x1U)
#define FLEXSPI_INTEN_IPCMDDONEEN_SHIFT          (0U)
/*! IPCMDDONEEN - IP-Triggered Command Sequences Execution Finished Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDDONEEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDDONEEN_SHIFT)) & FLEXSPI_INTEN_IPCMDDONEEN_MASK)

#define FLEXSPI_INTEN_IPCMDGEEN_MASK             (0x2U)
#define FLEXSPI_INTEN_IPCMDGEEN_SHIFT            (1U)
/*! IPCMDGEEN - IP-Triggered Command Sequences Grant Timeout Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDGEEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDGEEN_SHIFT)) & FLEXSPI_INTEN_IPCMDGEEN_MASK)

#define FLEXSPI_INTEN_AHBCMDGEEN_MASK            (0x4U)
#define FLEXSPI_INTEN_AHBCMDGEEN_SHIFT           (2U)
/*! AHBCMDGEEN - AHB-Triggered Command Sequences Grant Timeout Interrupt Enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBCMDGEEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBCMDGEEN_SHIFT)) & FLEXSPI_INTEN_AHBCMDGEEN_MASK)

#define FLEXSPI_INTEN_IPCMDERREN_MASK            (0x8U)
#define FLEXSPI_INTEN_IPCMDERREN_SHIFT           (3U)
/*! IPCMDERREN - IP-Triggered Command Sequences Error Detected Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDERREN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDERREN_SHIFT)) & FLEXSPI_INTEN_IPCMDERREN_MASK)

#define FLEXSPI_INTEN_AHBCMDERREN_MASK           (0x10U)
#define FLEXSPI_INTEN_AHBCMDERREN_SHIFT          (4U)
/*! AHBCMDERREN - AHB-Triggered Command Sequences Error Detected Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBCMDERREN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBCMDERREN_SHIFT)) & FLEXSPI_INTEN_AHBCMDERREN_MASK)

#define FLEXSPI_INTEN_IPRXWAEN_MASK              (0x20U)
#define FLEXSPI_INTEN_IPRXWAEN_SHIFT             (5U)
/*! IPRXWAEN - IP Receive FIFO Watermark Available Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPRXWAEN(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPRXWAEN_SHIFT)) & FLEXSPI_INTEN_IPRXWAEN_MASK)

#define FLEXSPI_INTEN_IPTXWEEN_MASK              (0x40U)
#define FLEXSPI_INTEN_IPTXWEEN_SHIFT             (6U)
/*! IPTXWEEN - IP Transmit FIFO Watermark Empty Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPTXWEEN(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPTXWEEN_SHIFT)) & FLEXSPI_INTEN_IPTXWEEN_MASK)

#define FLEXSPI_INTEN_DATALEARNFAILEN_MASK       (0x80U)
#define FLEXSPI_INTEN_DATALEARNFAILEN_SHIFT      (7U)
/*! DATALEARNFAILEN - Data Learning Failed Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_DATALEARNFAILEN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_DATALEARNFAILEN_SHIFT)) & FLEXSPI_INTEN_DATALEARNFAILEN_MASK)

#define FLEXSPI_INTEN_SCKSTOPBYRDEN_MASK         (0x100U)
#define FLEXSPI_INTEN_SCKSTOPBYRDEN_SHIFT        (8U)
/*! SCKSTOPBYRDEN - SCLK Stopped By Read Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SCKSTOPBYRDEN(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SCKSTOPBYRDEN_SHIFT)) & FLEXSPI_INTEN_SCKSTOPBYRDEN_MASK)

#define FLEXSPI_INTEN_SCKSTOPBYWREN_MASK         (0x200U)
#define FLEXSPI_INTEN_SCKSTOPBYWREN_SHIFT        (9U)
/*! SCKSTOPBYWREN - SCLK Stopped By Write Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SCKSTOPBYWREN(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SCKSTOPBYWREN_SHIFT)) & FLEXSPI_INTEN_SCKSTOPBYWREN_MASK)

#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN_MASK       (0x400U)
#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT      (10U)
/*! AHBBUSTIMEOUTEN - AHB Bus Timeout Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT)) & FLEXSPI_INTEN_AHBBUSTIMEOUTEN_MASK)

#define FLEXSPI_INTEN_SEQTIMEOUTEN_MASK          (0x800U)
#define FLEXSPI_INTEN_SEQTIMEOUTEN_SHIFT         (11U)
/*! SEQTIMEOUTEN - Sequence execution Timeout Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SEQTIMEOUTEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SEQTIMEOUTEN_SHIFT)) & FLEXSPI_INTEN_SEQTIMEOUTEN_MASK)

#define FLEXSPI_INTEN_IPCMDSECUREVIOEN_MASK      (0x10000U)
#define FLEXSPI_INTEN_IPCMDSECUREVIOEN_SHIFT     (16U)
/*! IPCMDSECUREVIOEN - IP Command Security Violation Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDSECUREVIOEN(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDSECUREVIOEN_SHIFT)) & FLEXSPI_INTEN_IPCMDSECUREVIOEN_MASK)

#define FLEXSPI_INTEN_AHBGCMERREN_MASK           (0x20000U)
#define FLEXSPI_INTEN_AHBGCMERREN_SHIFT          (17U)
/*! AHBGCMERREN - AHB Read GCM Error Interrupt Enable
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBGCMERREN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBGCMERREN_SHIFT)) & FLEXSPI_INTEN_AHBGCMERREN_MASK)
/*! @} */

/*! @name INTR - Interrupt */
/*! @{ */

#define FLEXSPI_INTR_IPCMDDONE_MASK              (0x1U)
#define FLEXSPI_INTR_IPCMDDONE_SHIFT             (0U)
/*! IPCMDDONE - IP-Triggered Command Sequences Execution Finished
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPCMDDONE(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDDONE_SHIFT)) & FLEXSPI_INTR_IPCMDDONE_MASK)

#define FLEXSPI_INTR_IPCMDGE_MASK                (0x2U)
#define FLEXSPI_INTR_IPCMDGE_SHIFT               (1U)
/*! IPCMDGE - IP-Triggered Command Sequences Grant Timeout
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPCMDGE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDGE_SHIFT)) & FLEXSPI_INTR_IPCMDGE_MASK)

#define FLEXSPI_INTR_AHBCMDGE_MASK               (0x4U)
#define FLEXSPI_INTR_AHBCMDGE_SHIFT              (2U)
/*! AHBCMDGE - AHB-Triggered Command Sequences Grant Timeout
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_AHBCMDGE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBCMDGE_SHIFT)) & FLEXSPI_INTR_AHBCMDGE_MASK)

#define FLEXSPI_INTR_IPCMDERR_MASK               (0x8U)
#define FLEXSPI_INTR_IPCMDERR_SHIFT              (3U)
/*! IPCMDERR - IP-Triggered Command Sequences Error
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPCMDERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDERR_SHIFT)) & FLEXSPI_INTR_IPCMDERR_MASK)

#define FLEXSPI_INTR_AHBCMDERR_MASK              (0x10U)
#define FLEXSPI_INTR_AHBCMDERR_SHIFT             (4U)
/*! AHBCMDERR - AHB-Triggered Command Sequences Error
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_AHBCMDERR(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBCMDERR_SHIFT)) & FLEXSPI_INTR_AHBCMDERR_MASK)

#define FLEXSPI_INTR_IPRXWA_MASK                 (0x20U)
#define FLEXSPI_INTR_IPRXWA_SHIFT                (5U)
/*! IPRXWA - IP Receive FIFO Watermark Available
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPRXWA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPRXWA_SHIFT)) & FLEXSPI_INTR_IPRXWA_MASK)

#define FLEXSPI_INTR_IPTXWE_MASK                 (0x40U)
#define FLEXSPI_INTR_IPTXWE_SHIFT                (6U)
/*! IPTXWE - IP Transmit FIFO Watermark Empty
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPTXWE(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPTXWE_SHIFT)) & FLEXSPI_INTR_IPTXWE_MASK)

#define FLEXSPI_INTR_DATALEARNFAIL_MASK          (0x80U)
#define FLEXSPI_INTR_DATALEARNFAIL_SHIFT         (7U)
/*! DATALEARNFAIL - Data Learning Failed
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_DATALEARNFAIL(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_DATALEARNFAIL_SHIFT)) & FLEXSPI_INTR_DATALEARNFAIL_MASK)

#define FLEXSPI_INTR_SCKSTOPBYRD_MASK            (0x100U)
#define FLEXSPI_INTR_SCKSTOPBYRD_SHIFT           (8U)
/*! SCKSTOPBYRD - SCLK Stopped Due To Full Receive FIFO
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_SCKSTOPBYRD(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SCKSTOPBYRD_SHIFT)) & FLEXSPI_INTR_SCKSTOPBYRD_MASK)

#define FLEXSPI_INTR_SCKSTOPBYWR_MASK            (0x200U)
#define FLEXSPI_INTR_SCKSTOPBYWR_SHIFT           (9U)
/*! SCKSTOPBYWR - SCLK Stopped Due To Empty Transmit FIFO
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_SCKSTOPBYWR(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SCKSTOPBYWR_SHIFT)) & FLEXSPI_INTR_SCKSTOPBYWR_MASK)

#define FLEXSPI_INTR_AHBBUSTIMEOUT_MASK          (0x400U)
#define FLEXSPI_INTR_AHBBUSTIMEOUT_SHIFT         (10U)
/*! AHBBUSTIMEOUT - AHB Bus Timeout
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_AHBBUSTIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBBUSTIMEOUT_SHIFT)) & FLEXSPI_INTR_AHBBUSTIMEOUT_MASK)

#define FLEXSPI_INTR_SEQTIMEOUT_MASK             (0x800U)
#define FLEXSPI_INTR_SEQTIMEOUT_SHIFT            (11U)
/*! SEQTIMEOUT - Sequence Execution Timeout
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_SEQTIMEOUT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SEQTIMEOUT_SHIFT)) & FLEXSPI_INTR_SEQTIMEOUT_MASK)

#define FLEXSPI_INTR_IPCMDSECUREVIO_MASK         (0x10000U)
#define FLEXSPI_INTR_IPCMDSECUREVIO_SHIFT        (16U)
/*! IPCMDSECUREVIO - IP Command Security Violation
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_IPCMDSECUREVIO(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDSECUREVIO_SHIFT)) & FLEXSPI_INTR_IPCMDSECUREVIO_MASK)

#define FLEXSPI_INTR_AHBGCMERR_MASK              (0x20000U)
#define FLEXSPI_INTR_AHBGCMERR_SHIFT             (17U)
/*! AHBGCMERR - AHB Read GCM Error
 *  0b0..Interrupt condition has not occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt condition has occurred
 */
#define FLEXSPI_INTR_AHBGCMERR(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBGCMERR_SHIFT)) & FLEXSPI_INTR_AHBGCMERR_MASK)
/*! @} */

/*! @name LUTKEY - LUT Key */
/*! @{ */

#define FLEXSPI_LUTKEY_KEY_MASK                  (0xFFFFFFFFU)
#define FLEXSPI_LUTKEY_KEY_SHIFT                 (0U)
/*! KEY - LUT Key */
#define FLEXSPI_LUTKEY_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTKEY_KEY_SHIFT)) & FLEXSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LUTCR - LUT Control */
/*! @{ */

#define FLEXSPI_LUTCR_LOCK_MASK                  (0x1U)
#define FLEXSPI_LUTCR_LOCK_SHIFT                 (0U)
/*! LOCK - Lock LUT
 *  0b0..LUT is unlocked (LUTCR[UNLOCK] must be 1)
 *  0b1..LUT is locked and cannot be written
 */
#define FLEXSPI_LUTCR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTCR_LOCK_SHIFT)) & FLEXSPI_LUTCR_LOCK_MASK)

#define FLEXSPI_LUTCR_UNLOCK_MASK                (0x2U)
#define FLEXSPI_LUTCR_UNLOCK_SHIFT               (1U)
/*! UNLOCK - Unlock LUT
 *  0b0..LUT is locked (LUTCR[LOCK] must be 1)
 *  0b1..LUT is unlocked and can be written
 */
#define FLEXSPI_LUTCR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTCR_UNLOCK_SHIFT)) & FLEXSPI_LUTCR_UNLOCK_MASK)

#define FLEXSPI_LUTCR_PROTECT_MASK               (0x4U)
#define FLEXSPI_LUTCR_PROTECT_SHIFT              (2U)
/*! PROTECT - LUT Protection
 *  0b0..Not protected. All IPS controllers can access LUTCR and LUT memory.
 *  0b1..Protected. Only secure IPS controller can change the value of LUTCR and write to LUT memory.
 */
#define FLEXSPI_LUTCR_PROTECT(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTCR_PROTECT_SHIFT)) & FLEXSPI_LUTCR_PROTECT_MASK)
/*! @} */

/*! @name AHBRXBUFCR0 - AHB Receive Buffer 0 Control 0..AHB Receive Buffer 7 Control 0 */
/*! @{ */

#define FLEXSPI_AHBRXBUFCR0_BUFSZ_MASK           (0xFFU)
#define FLEXSPI_AHBRXBUFCR0_BUFSZ_SHIFT          (0U)
/*! BUFSZ - AHB Receive Buffer Size */
#define FLEXSPI_AHBRXBUFCR0_BUFSZ(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_BUFSZ_SHIFT)) & FLEXSPI_AHBRXBUFCR0_BUFSZ_MASK)

#define FLEXSPI_AHBRXBUFCR0_MSTRID_MASK          (0x1F0000U)
#define FLEXSPI_AHBRXBUFCR0_MSTRID_SHIFT         (16U)
/*! MSTRID - AHB Controller ID */
#define FLEXSPI_AHBRXBUFCR0_MSTRID(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_MSTRID_SHIFT)) & FLEXSPI_AHBRXBUFCR0_MSTRID_MASK)

#define FLEXSPI_AHBRXBUFCR0_PRIORITY_MASK        (0x7000000U)
#define FLEXSPI_AHBRXBUFCR0_PRIORITY_SHIFT       (24U)
/*! PRIORITY - AHB Controller Read Priority */
#define FLEXSPI_AHBRXBUFCR0_PRIORITY(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_PRIORITY_SHIFT)) & FLEXSPI_AHBRXBUFCR0_PRIORITY_MASK)

#define FLEXSPI_AHBRXBUFCR0_REGIONEN_MASK        (0x40000000U)
#define FLEXSPI_AHBRXBUFCR0_REGIONEN_SHIFT       (30U)
/*! REGIONEN - AHB Receive Buffer Address Region Enable
 *  0b0..Disabled. The buffer hit is based on the value of MSTRID only.
 *  0b1..Enabled. The buffer hit is based on the value of MSTRID and the address within AHBBUFREGIONSTARTn and AHBREGIONENDn.
 */
#define FLEXSPI_AHBRXBUFCR0_REGIONEN(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_REGIONEN_SHIFT)) & FLEXSPI_AHBRXBUFCR0_REGIONEN_MASK)

#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN_MASK      (0x80000000U)
#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT     (31U)
/*! PREFETCHEN - AHB Read Prefetch Enable
 *  0b0..Disabled
 *  0b1..Enabled when is enabled.
 */
#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT)) & FLEXSPI_AHBRXBUFCR0_PREFETCHEN_MASK)
/*! @} */

/*! @name FLSHCR0 - Flash Control 0 */
/*! @{ */

#define FLEXSPI_FLSHCR0_FLSHSZ_MASK              (0x7FFFFFU)
#define FLEXSPI_FLSHCR0_FLSHSZ_SHIFT             (0U)
/*! FLSHSZ - Flash Size in KB */
#define FLEXSPI_FLSHCR0_FLSHSZ(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR0_FLSHSZ_SHIFT)) & FLEXSPI_FLSHCR0_FLSHSZ_MASK)

#define FLEXSPI_FLSHCR0_ADDRSHIFT_MASK           (0x20000000U)
#define FLEXSPI_FLSHCR0_ADDRSHIFT_SHIFT          (29U)
/*! ADDRSHIFT - AHB Address Shift Function control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FLEXSPI_FLSHCR0_ADDRSHIFT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR0_ADDRSHIFT_SHIFT)) & FLEXSPI_FLSHCR0_ADDRSHIFT_MASK)

#define FLEXSPI_FLSHCR0_SPLITWREN_MASK           (0x40000000U)
#define FLEXSPI_FLSHCR0_SPLITWREN_SHIFT          (30U)
/*! SPLITWREN - AHB Write Access Split Function Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_FLSHCR0_SPLITWREN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR0_SPLITWREN_SHIFT)) & FLEXSPI_FLSHCR0_SPLITWREN_MASK)

#define FLEXSPI_FLSHCR0_SPLITRDEN_MASK           (0x80000000U)
#define FLEXSPI_FLSHCR0_SPLITRDEN_SHIFT          (31U)
/*! SPLITRDEN - AHB Read Access Split Function Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_FLSHCR0_SPLITRDEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR0_SPLITRDEN_SHIFT)) & FLEXSPI_FLSHCR0_SPLITRDEN_MASK)
/*! @} */

/*! @name FLSHCR1 - Flash Control 1 */
/*! @{ */

#define FLEXSPI_FLSHCR1_TCSS_MASK                (0x1FU)
#define FLEXSPI_FLSHCR1_TCSS_SHIFT               (0U)
/*! TCSS - Serial Flash CS Setup Time */
#define FLEXSPI_FLSHCR1_TCSS(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_TCSS_SHIFT)) & FLEXSPI_FLSHCR1_TCSS_MASK)

#define FLEXSPI_FLSHCR1_TCSH_MASK                (0x3E0U)
#define FLEXSPI_FLSHCR1_TCSH_SHIFT               (5U)
/*! TCSH - Serial Flash CS Hold Time */
#define FLEXSPI_FLSHCR1_TCSH(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_TCSH_SHIFT)) & FLEXSPI_FLSHCR1_TCSH_MASK)

#define FLEXSPI_FLSHCR1_WA_MASK                  (0x400U)
#define FLEXSPI_FLSHCR1_WA_SHIFT                 (10U)
/*! WA - Word-Addressable
 *  0b0..Byte-addressable
 *  0b1..Word-addressable
 */
#define FLEXSPI_FLSHCR1_WA(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_WA_SHIFT)) & FLEXSPI_FLSHCR1_WA_MASK)

#define FLEXSPI_FLSHCR1_CAS_MASK                 (0x7800U)
#define FLEXSPI_FLSHCR1_CAS_SHIFT                (11U)
/*! CAS - Column Address Size */
#define FLEXSPI_FLSHCR1_CAS(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CAS_SHIFT)) & FLEXSPI_FLSHCR1_CAS_MASK)

#define FLEXSPI_FLSHCR1_CSINTERVALUNIT_MASK      (0x8000U)
#define FLEXSPI_FLSHCR1_CSINTERVALUNIT_SHIFT     (15U)
/*! CSINTERVALUNIT - Chip Select Interval Unit
 *  0b0..1 serial clock cycle
 *  0b1..256 serial clock cycles
 */
#define FLEXSPI_FLSHCR1_CSINTERVALUNIT(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CSINTERVALUNIT_SHIFT)) & FLEXSPI_FLSHCR1_CSINTERVALUNIT_MASK)

#define FLEXSPI_FLSHCR1_CSINTERVAL_MASK          (0xFFFF0000U)
#define FLEXSPI_FLSHCR1_CSINTERVAL_SHIFT         (16U)
/*! CSINTERVAL - Chip Select Interval */
#define FLEXSPI_FLSHCR1_CSINTERVAL(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CSINTERVAL_SHIFT)) & FLEXSPI_FLSHCR1_CSINTERVAL_MASK)
/*! @} */

/*! @name FLSHCR2 - Flash Control 2 */
/*! @{ */

#define FLEXSPI_FLSHCR2_ARDSEQID_MASK            (0xFU)
#define FLEXSPI_FLSHCR2_ARDSEQID_SHIFT           (0U)
/*! ARDSEQID - Sequence Index for AHB Read-Triggered Command in LUT */
#define FLEXSPI_FLSHCR2_ARDSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_ARDSEQID_SHIFT)) & FLEXSPI_FLSHCR2_ARDSEQID_MASK)

#define FLEXSPI_FLSHCR2_ARDSEQNUM_MASK           (0xE0U)
#define FLEXSPI_FLSHCR2_ARDSEQNUM_SHIFT          (5U)
/*! ARDSEQNUM - Sequence Number for AHB Read-Triggered Command */
#define FLEXSPI_FLSHCR2_ARDSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_ARDSEQNUM_SHIFT)) & FLEXSPI_FLSHCR2_ARDSEQNUM_MASK)

#define FLEXSPI_FLSHCR2_AWRSEQID_MASK            (0xF00U)
#define FLEXSPI_FLSHCR2_AWRSEQID_SHIFT           (8U)
/*! AWRSEQID - Sequence Index for AHB Write-Triggered Command */
#define FLEXSPI_FLSHCR2_AWRSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRSEQID_SHIFT)) & FLEXSPI_FLSHCR2_AWRSEQID_MASK)

#define FLEXSPI_FLSHCR2_AWRSEQNUM_MASK           (0xE000U)
#define FLEXSPI_FLSHCR2_AWRSEQNUM_SHIFT          (13U)
/*! AWRSEQNUM - Sequence Number for AHB Write-Triggered Command */
#define FLEXSPI_FLSHCR2_AWRSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRSEQNUM_SHIFT)) & FLEXSPI_FLSHCR2_AWRSEQNUM_MASK)

#define FLEXSPI_FLSHCR2_AWRWAIT_MASK             (0xFFF0000U)
#define FLEXSPI_FLSHCR2_AWRWAIT_SHIFT            (16U)
/*! AWRWAIT - AHB Write Wait */
#define FLEXSPI_FLSHCR2_AWRWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRWAIT_SHIFT)) & FLEXSPI_FLSHCR2_AWRWAIT_MASK)

#define FLEXSPI_FLSHCR2_AWRWAITUNIT_MASK         (0x70000000U)
#define FLEXSPI_FLSHCR2_AWRWAITUNIT_SHIFT        (28U)
/*! AWRWAITUNIT - AWRWAIT Unit
 *  0b000..2
 *  0b001..8
 *  0b010..32
 *  0b011..128
 *  0b100..512
 *  0b101..2048
 *  0b110..8192
 *  0b111..32768
 */
#define FLEXSPI_FLSHCR2_AWRWAITUNIT(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRWAITUNIT_SHIFT)) & FLEXSPI_FLSHCR2_AWRWAITUNIT_MASK)

#define FLEXSPI_FLSHCR2_CLRINSTRPTR_MASK         (0x80000000U)
#define FLEXSPI_FLSHCR2_CLRINSTRPTR_SHIFT        (31U)
/*! CLRINSTRPTR - Clear Instruction Pointer */
#define FLEXSPI_FLSHCR2_CLRINSTRPTR(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_CLRINSTRPTR_SHIFT)) & FLEXSPI_FLSHCR2_CLRINSTRPTR_MASK)
/*! @} */

/*! @name FLSHCR4 - Flash Control 4 */
/*! @{ */

#define FLEXSPI_FLSHCR4_WMOPT1_MASK              (0x1U)
#define FLEXSPI_FLSHCR4_WMOPT1_SHIFT             (0U)
/*! WMOPT1 - Write Mask Option 1
 *  0b0..When writing to an external device, DQS pin is used as write mask. When flash memory is accessed in
 *       individual mode, AHB or IP write burst start address alignment is not limited.
 *  0b1..When writing to an external device, DQS pin is not used as write mask. When flash memory is accessed in
 *       individual mode, AHB or IP write burst start address alignment is limited.
 */
#define FLEXSPI_FLSHCR4_WMOPT1(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR4_WMOPT1_SHIFT)) & FLEXSPI_FLSHCR4_WMOPT1_MASK)

#define FLEXSPI_FLSHCR4_WMENA_MASK               (0x4U)
#define FLEXSPI_FLSHCR4_WMENA_SHIFT              (2U)
/*! WMENA - Write Mask Enable for Port A
 *  0b0..Disabled. When writing to external device, DQS(RWDS) pin is not driven.
 *  0b1..Enabled. When writing to external device, FlexSPI drives DQS(RWDS) pin as write mask output.
 */
#define FLEXSPI_FLSHCR4_WMENA(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR4_WMENA_SHIFT)) & FLEXSPI_FLSHCR4_WMENA_MASK)

#define FLEXSPI_FLSHCR4_WMENB_MASK               (0x8U)
#define FLEXSPI_FLSHCR4_WMENB_SHIFT              (3U)
/*! WMENB - Write Mask Enable for Port B
 *  0b0..Disabled. When writing to external device, DQS(RWDS) pin is not driven.
 *  0b1..Enabled. When writing to external device, FlexSPI drives DQS(RWDS) pin as write mask output.
 */
#define FLEXSPI_FLSHCR4_WMENB(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR4_WMENB_SHIFT)) & FLEXSPI_FLSHCR4_WMENB_MASK)
/*! @} */

/*! @name IPCR0 - IP Control 0 */
/*! @{ */

#define FLEXSPI_IPCR0_SFAR_MASK                  (0xFFFFFFFFU)
#define FLEXSPI_IPCR0_SFAR_SHIFT                 (0U)
/*! SFAR - Serial Flash Address */
#define FLEXSPI_IPCR0_SFAR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR0_SFAR_SHIFT)) & FLEXSPI_IPCR0_SFAR_MASK)
/*! @} */

/*! @name IPCR1 - IP Control 1 */
/*! @{ */

#define FLEXSPI_IPCR1_IDATSZ_MASK                (0xFFFFU)
#define FLEXSPI_IPCR1_IDATSZ_SHIFT               (0U)
/*! IDATSZ - Flash Read/Program Data Size (in bytes) for IP command. */
#define FLEXSPI_IPCR1_IDATSZ(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_IDATSZ_SHIFT)) & FLEXSPI_IPCR1_IDATSZ_MASK)

#define FLEXSPI_IPCR1_ISEQID_MASK                (0xF0000U)
#define FLEXSPI_IPCR1_ISEQID_SHIFT               (16U)
/*! ISEQID - Sequence Index in LUT for IP command. */
#define FLEXSPI_IPCR1_ISEQID(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_ISEQID_SHIFT)) & FLEXSPI_IPCR1_ISEQID_MASK)

#define FLEXSPI_IPCR1_ISEQNUM_MASK               (0x7000000U)
#define FLEXSPI_IPCR1_ISEQNUM_SHIFT              (24U)
/*! ISEQNUM - Sequence Number for IP command: ISEQNUM+1. */
#define FLEXSPI_IPCR1_ISEQNUM(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_ISEQNUM_SHIFT)) & FLEXSPI_IPCR1_ISEQNUM_MASK)

#define FLEXSPI_IPCR1_IPAREN_MASK                (0x80000000U)
#define FLEXSPI_IPCR1_IPAREN_SHIFT               (31U)
/*! IPAREN - Parallel Mode Enable for IP Commands
 *  0b0..Disabled. Flash memory is accessed in Individual mode.
 *  0b1..Enabled. Flash memory is accessed in Parallel mode.
 */
#define FLEXSPI_IPCR1_IPAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_IPAREN_SHIFT)) & FLEXSPI_IPCR1_IPAREN_MASK)
/*! @} */

/*! @name IPCR2 - IP Control 2 */
/*! @{ */

#define FLEXSPI_IPCR2_IPBLKAHBREQ_MASK           (0x1U)
#define FLEXSPI_IPCR2_IPBLKAHBREQ_SHIFT          (0U)
/*! IPBLKAHBREQ - IP Command Blocking AHB Command Request Enable
 *  0b0..IP commands do not block AHB command requests.
 *  0b1..IP commands block AHB command requests.
 */
#define FLEXSPI_IPCR2_IPBLKAHBREQ(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR2_IPBLKAHBREQ_SHIFT)) & FLEXSPI_IPCR2_IPBLKAHBREQ_MASK)

#define FLEXSPI_IPCR2_IPBLKAHBACK_MASK           (0x2U)
#define FLEXSPI_IPCR2_IPBLKAHBACK_SHIFT          (1U)
/*! IPBLKAHBACK - IP Command Blocking AHB Command Acknowledgment Enable
 *  0b0..IP commands do not block AHB command acknowledgment.
 *  0b1..IP commands block AHB command acknowledgment.
 */
#define FLEXSPI_IPCR2_IPBLKAHBACK(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR2_IPBLKAHBACK_SHIFT)) & FLEXSPI_IPCR2_IPBLKAHBACK_MASK)

#define FLEXSPI_IPCR2_IPBLKALLAHB_MASK           (0x4U)
#define FLEXSPI_IPCR2_IPBLKALLAHB_SHIFT          (2U)
/*! IPBLKALLAHB - IP Command Blocking All AHB Command Enable
 *  0b0..IP commands only block AHB commands that affect the IPED region.
 *  0b1..IP commands block all AHB commands.
 */
#define FLEXSPI_IPCR2_IPBLKALLAHB(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR2_IPBLKALLAHB_SHIFT)) & FLEXSPI_IPCR2_IPBLKALLAHB_MASK)
/*! @} */

/*! @name IPCMD - IP Command */
/*! @{ */

#define FLEXSPI_IPCMD_TRG_MASK                   (0x1U)
#define FLEXSPI_IPCMD_TRG_SHIFT                  (0U)
/*! TRG - Command Trigger
 *  0b0..No action
 *  0b1..Start the IP command that the IPCR0 and IPCR1 registers define.
 */
#define FLEXSPI_IPCMD_TRG(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCMD_TRG_SHIFT)) & FLEXSPI_IPCMD_TRG_MASK)
/*! @} */

/*! @name DLPR - Data Learning Pattern */
/*! @{ */

#define FLEXSPI_DLPR_DLP_MASK                    (0xFFFFFFFFU)
#define FLEXSPI_DLPR_DLP_SHIFT                   (0U)
/*! DLP - Data Learning Pattern */
#define FLEXSPI_DLPR_DLP(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLPR_DLP_SHIFT)) & FLEXSPI_DLPR_DLP_MASK)
/*! @} */

/*! @name IPRXFCR - IP Receive FIFO Control */
/*! @{ */

#define FLEXSPI_IPRXFCR_CLRIPRXF_MASK            (0x1U)
#define FLEXSPI_IPRXFCR_CLRIPRXF_SHIFT           (0U)
/*! CLRIPRXF - Clear IP Receive FIFO
 *  0b0..No function
 *  0b1..A clock cycle pulse clears all valid data entries in IP receive FIFO.
 */
#define FLEXSPI_IPRXFCR_CLRIPRXF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_CLRIPRXF_SHIFT)) & FLEXSPI_IPRXFCR_CLRIPRXF_MASK)

#define FLEXSPI_IPRXFCR_RXDMAEN_MASK             (0x2U)
#define FLEXSPI_IPRXFCR_RXDMAEN_SHIFT            (1U)
/*! RXDMAEN - IP Receive FIFO Reading by DMA Enable
 *  0b0..Disabled. The processor reads the FIFO.
 *  0b1..Enabled. DMA reads the FIFO.
 */
#define FLEXSPI_IPRXFCR_RXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_RXDMAEN_SHIFT)) & FLEXSPI_IPRXFCR_RXDMAEN_MASK)

#define FLEXSPI_IPRXFCR_RXWMRK_MASK              (0x1FCU)
#define FLEXSPI_IPRXFCR_RXWMRK_SHIFT             (2U)
/*! RXWMRK - IP Receive FIFO Watermark Level */
#define FLEXSPI_IPRXFCR_RXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_RXWMRK_SHIFT)) & FLEXSPI_IPRXFCR_RXWMRK_MASK)
/*! @} */

/*! @name IPTXFCR - IP Transmit FIFO Control */
/*! @{ */

#define FLEXSPI_IPTXFCR_CLRIPTXF_MASK            (0x1U)
#define FLEXSPI_IPTXFCR_CLRIPTXF_SHIFT           (0U)
/*! CLRIPTXF - Clear IP Transmit FIFO
 *  0b0..No function
 *  0b1..A clock cycle pulse clears all valid data entries in the IP transmit FIFO.
 */
#define FLEXSPI_IPTXFCR_CLRIPTXF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_CLRIPTXF_SHIFT)) & FLEXSPI_IPTXFCR_CLRIPTXF_MASK)

#define FLEXSPI_IPTXFCR_TXDMAEN_MASK             (0x2U)
#define FLEXSPI_IPTXFCR_TXDMAEN_SHIFT            (1U)
/*! TXDMAEN - Transmit FIFO DMA Enable
 *  0b0..Processor
 *  0b1..DMA
 */
#define FLEXSPI_IPTXFCR_TXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_TXDMAEN_SHIFT)) & FLEXSPI_IPTXFCR_TXDMAEN_MASK)

#define FLEXSPI_IPTXFCR_TXWMRK_MASK              (0x1FCU)
#define FLEXSPI_IPTXFCR_TXWMRK_SHIFT             (2U)
/*! TXWMRK - Transmit Watermark Level */
#define FLEXSPI_IPTXFCR_TXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_TXWMRK_SHIFT)) & FLEXSPI_IPTXFCR_TXWMRK_MASK)
/*! @} */

/*! @name DLLCR - DLL Control 0 */
/*! @{ */

#define FLEXSPI_DLLCR_DLLEN_MASK                 (0x1U)
#define FLEXSPI_DLLCR_DLLEN_SHIFT                (0U)
/*! DLLEN - DLL Calibration Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_DLLCR_DLLEN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_DLLEN_SHIFT)) & FLEXSPI_DLLCR_DLLEN_MASK)

#define FLEXSPI_DLLCR_DLLRESET_MASK              (0x2U)
#define FLEXSPI_DLLCR_DLLRESET_SHIFT             (1U)
/*! DLLRESET - DLL reset
 *  0b0..No function
 *  0b1..Force DLL reset.
 */
#define FLEXSPI_DLLCR_DLLRESET(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_DLLRESET_SHIFT)) & FLEXSPI_DLLCR_DLLRESET_MASK)

#define FLEXSPI_DLLCR_SLVDLYTARGET_MASK          (0x78U)
#define FLEXSPI_DLLCR_SLVDLYTARGET_SHIFT         (3U)
/*! SLVDLYTARGET - Target Delay Line */
#define FLEXSPI_DLLCR_SLVDLYTARGET(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_SLVDLYTARGET_SHIFT)) & FLEXSPI_DLLCR_SLVDLYTARGET_MASK)

#define FLEXSPI_DLLCR_OVRDEN_MASK                (0x100U)
#define FLEXSPI_DLLCR_OVRDEN_SHIFT               (8U)
/*! OVRDEN - Target Clock Delay Line Override Value Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_DLLCR_OVRDEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_OVRDEN_SHIFT)) & FLEXSPI_DLLCR_OVRDEN_MASK)

#define FLEXSPI_DLLCR_OVRDVAL_MASK               (0x7E00U)
#define FLEXSPI_DLLCR_OVRDVAL_SHIFT              (9U)
/*! OVRDVAL - Target Clock Delay Line Override Value */
#define FLEXSPI_DLLCR_OVRDVAL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_OVRDVAL_SHIFT)) & FLEXSPI_DLLCR_OVRDVAL_MASK)

#define FLEXSPI_DLLCR_REFPHASEGAP_MASK           (0x18000U)
#define FLEXSPI_DLLCR_REFPHASEGAP_SHIFT          (15U)
/*! REFPHASEGAP - Reference Clock Delay Line Phase Adjust Gap. REFPHASEGAP setting of 2h is recommended if DLLEN is set. */
#define FLEXSPI_DLLCR_REFPHASEGAP(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_REFPHASEGAP_SHIFT)) & FLEXSPI_DLLCR_REFPHASEGAP_MASK)
/*! @} */

/*! @name STS0 - Status 0 */
/*! @{ */

#define FLEXSPI_STS0_SEQIDLE_MASK                (0x1U)
#define FLEXSPI_STS0_SEQIDLE_SHIFT               (0U)
/*! SEQIDLE - SEQ_CTL State Machine Idle
 *  0b0..Not idle
 *  0b1..Idle
 */
#define FLEXSPI_STS0_SEQIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_SEQIDLE_SHIFT)) & FLEXSPI_STS0_SEQIDLE_MASK)

#define FLEXSPI_STS0_ARBIDLE_MASK                (0x2U)
#define FLEXSPI_STS0_ARBIDLE_SHIFT               (1U)
/*! ARBIDLE - ARB_CTL State Machine Idle
 *  0b0..Not idle
 *  0b1..Idle
 */
#define FLEXSPI_STS0_ARBIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_ARBIDLE_SHIFT)) & FLEXSPI_STS0_ARBIDLE_MASK)

#define FLEXSPI_STS0_ARBCMDSRC_MASK              (0xCU)
#define FLEXSPI_STS0_ARBCMDSRC_SHIFT             (2U)
/*! ARBCMDSRC - ARB Command Source
 *  0b00..Trigger source is AHB read command.
 *  0b01..Trigger source is AHB write command.
 *  0b10..Trigger source is IP command (by writing 1 to IPCMD[TRG]).
 *  0b11..Trigger source is a suspended command that has resumed.
 */
#define FLEXSPI_STS0_ARBCMDSRC(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_ARBCMDSRC_SHIFT)) & FLEXSPI_STS0_ARBCMDSRC_MASK)

#define FLEXSPI_STS0_DATALEARNPHASEA_MASK        (0xF0U)
#define FLEXSPI_STS0_DATALEARNPHASEA_SHIFT       (4U)
/*! DATALEARNPHASEA - Data Learning Phase Selection on Port A */
#define FLEXSPI_STS0_DATALEARNPHASEA(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_DATALEARNPHASEA_SHIFT)) & FLEXSPI_STS0_DATALEARNPHASEA_MASK)

#define FLEXSPI_STS0_DATALEARNPHASEB_MASK        (0xF00U)
#define FLEXSPI_STS0_DATALEARNPHASEB_SHIFT       (8U)
/*! DATALEARNPHASEB - Data Learning Phase Selection on Port B */
#define FLEXSPI_STS0_DATALEARNPHASEB(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_DATALEARNPHASEB_SHIFT)) & FLEXSPI_STS0_DATALEARNPHASEB_MASK)
/*! @} */

/*! @name STS1 - Status 1 */
/*! @{ */

#define FLEXSPI_STS1_AHBCMDERRID_MASK            (0xFU)
#define FLEXSPI_STS1_AHBCMDERRID_SHIFT           (0U)
/*! AHBCMDERRID - AHB Command Error ID */
#define FLEXSPI_STS1_AHBCMDERRID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_AHBCMDERRID_SHIFT)) & FLEXSPI_STS1_AHBCMDERRID_MASK)

#define FLEXSPI_STS1_AHBCMDERRCODE_MASK          (0xF00U)
#define FLEXSPI_STS1_AHBCMDERRCODE_SHIFT         (8U)
/*! AHBCMDERRCODE - AHB Command Error Code
 *  0b0000..No error
 *  0b0010..AHB Write command with JMP_ON_CS instruction used in the sequence
 *  0b0011..Unknown instruction opcode in the sequence
 *  0b0100..DUMMY_SDR or DUMMY_RWDS_SDR instruction used in DDR sequence
 *  0b0101..DUMMY_DDR or DUMMY_RWDS_DDR instruction used in SDR sequence
 *  0b1110..Sequence execution timeout
 */
#define FLEXSPI_STS1_AHBCMDERRCODE(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_AHBCMDERRCODE_SHIFT)) & FLEXSPI_STS1_AHBCMDERRCODE_MASK)

#define FLEXSPI_STS1_IPCMDERRID_MASK             (0xF0000U)
#define FLEXSPI_STS1_IPCMDERRID_SHIFT            (16U)
/*! IPCMDERRID - IP Command Error ID */
#define FLEXSPI_STS1_IPCMDERRID(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_IPCMDERRID_SHIFT)) & FLEXSPI_STS1_IPCMDERRID_MASK)

#define FLEXSPI_STS1_IPCMDERRCODE_MASK           (0xF000000U)
#define FLEXSPI_STS1_IPCMDERRCODE_SHIFT          (24U)
/*! IPCMDERRCODE - IP Command Error Code
 *  0b0000..No error
 *  0b0010..IP command with JMP_ON_CS instruction used in the sequence
 *  0b0011..Unknown instruction opcode in the sequence
 *  0b0100..DUMMY_SDR or DUMMY_RWDS_SDR instruction used in DDR sequence
 *  0b0101..DUMMY_DDR or DUMMY_RWDS_DDR instruction used in SDR sequence
 *  0b0110..Flash memory access start address exceeds entire flash address range (A1, A2, B1, and B2)
 *  0b1110..Sequence execution timeout
 *  0b1111..Flash boundary crossed
 */
#define FLEXSPI_STS1_IPCMDERRCODE(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_IPCMDERRCODE_SHIFT)) & FLEXSPI_STS1_IPCMDERRCODE_MASK)
/*! @} */

/*! @name STS2 - Status 2 */
/*! @{ */

#define FLEXSPI_STS2_ASLVLOCK_MASK               (0x1U)
#define FLEXSPI_STS2_ASLVLOCK_SHIFT              (0U)
/*! ASLVLOCK - Flash A Sample Target Delay Line Locked
 *  0b0..Not locked
 *  0b1..Locked
 */
#define FLEXSPI_STS2_ASLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_ASLVLOCK_SHIFT)) & FLEXSPI_STS2_ASLVLOCK_MASK)

#define FLEXSPI_STS2_AREFLOCK_MASK               (0x2U)
#define FLEXSPI_STS2_AREFLOCK_SHIFT              (1U)
/*! AREFLOCK - Flash A Sample Clock Reference Delay Line Locked
 *  0b0..Not locked
 *  0b1..Locked
 */
#define FLEXSPI_STS2_AREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_AREFLOCK_SHIFT)) & FLEXSPI_STS2_AREFLOCK_MASK)

#define FLEXSPI_STS2_ASLVSEL_MASK                (0xFCU)
#define FLEXSPI_STS2_ASLVSEL_SHIFT               (2U)
/*! ASLVSEL - Flash A Sample Clock Target Delay Line Delay Cell Number */
#define FLEXSPI_STS2_ASLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_ASLVSEL_SHIFT)) & FLEXSPI_STS2_ASLVSEL_MASK)

#define FLEXSPI_STS2_AREFSEL_MASK                (0x3F00U)
#define FLEXSPI_STS2_AREFSEL_SHIFT               (8U)
/*! AREFSEL - Flash A Sample Clock Reference Delay Line Delay Cell Number */
#define FLEXSPI_STS2_AREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_AREFSEL_SHIFT)) & FLEXSPI_STS2_AREFSEL_MASK)

#define FLEXSPI_STS2_BSLVLOCK_MASK               (0x10000U)
#define FLEXSPI_STS2_BSLVLOCK_SHIFT              (16U)
/*! BSLVLOCK - Flash B Sample Target Reference Delay Line Locked
 *  0b0..Not locked
 *  0b1..Locked
 */
#define FLEXSPI_STS2_BSLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BSLVLOCK_SHIFT)) & FLEXSPI_STS2_BSLVLOCK_MASK)

#define FLEXSPI_STS2_BREFLOCK_MASK               (0x20000U)
#define FLEXSPI_STS2_BREFLOCK_SHIFT              (17U)
/*! BREFLOCK - Flash B Sample Clock Reference Delay Line Locked
 *  0b0..Not locked
 *  0b1..Locked
 */
#define FLEXSPI_STS2_BREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BREFLOCK_SHIFT)) & FLEXSPI_STS2_BREFLOCK_MASK)

#define FLEXSPI_STS2_BSLVSEL_MASK                (0xFC0000U)
#define FLEXSPI_STS2_BSLVSEL_SHIFT               (18U)
/*! BSLVSEL - Flash B Sample Clock Target Delay Line Delay Cell Number */
#define FLEXSPI_STS2_BSLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BSLVSEL_SHIFT)) & FLEXSPI_STS2_BSLVSEL_MASK)

#define FLEXSPI_STS2_BREFSEL_MASK                (0x3F000000U)
#define FLEXSPI_STS2_BREFSEL_SHIFT               (24U)
/*! BREFSEL - Flash B Sample Clock Reference Delay Line Delay Cell Number */
#define FLEXSPI_STS2_BREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BREFSEL_SHIFT)) & FLEXSPI_STS2_BREFSEL_MASK)
/*! @} */

/*! @name AHBSPNDSTS - AHB Suspend Status */
/*! @{ */

#define FLEXSPI_AHBSPNDSTS_ACTIVE_MASK           (0x1U)
#define FLEXSPI_AHBSPNDSTS_ACTIVE_SHIFT          (0U)
/*! ACTIVE - Active AHB Read Prefetch Suspended
 *  0b0..No suspended AHB read prefetch command.
 *  0b1..An AHB read prefetch command sequence has been suspended.
 */
#define FLEXSPI_AHBSPNDSTS_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_ACTIVE_SHIFT)) & FLEXSPI_AHBSPNDSTS_ACTIVE_MASK)

#define FLEXSPI_AHBSPNDSTS_BUFID_MASK            (0xEU)
#define FLEXSPI_AHBSPNDSTS_BUFID_SHIFT           (1U)
/*! BUFID - AHB Receive Buffer ID for Suspended Command Sequence */
#define FLEXSPI_AHBSPNDSTS_BUFID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_BUFID_SHIFT)) & FLEXSPI_AHBSPNDSTS_BUFID_MASK)

#define FLEXSPI_AHBSPNDSTS_DATLFT_MASK           (0xFFFF0000U)
#define FLEXSPI_AHBSPNDSTS_DATLFT_SHIFT          (16U)
/*! DATLFT - Data Left */
#define FLEXSPI_AHBSPNDSTS_DATLFT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_DATLFT_SHIFT)) & FLEXSPI_AHBSPNDSTS_DATLFT_MASK)
/*! @} */

/*! @name IPRXFSTS - IP Receive FIFO Status */
/*! @{ */

#define FLEXSPI_IPRXFSTS_FILL_MASK               (0xFFU)
#define FLEXSPI_IPRXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill Level of IP Receive FIFO */
#define FLEXSPI_IPRXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFSTS_FILL_SHIFT)) & FLEXSPI_IPRXFSTS_FILL_MASK)

#define FLEXSPI_IPRXFSTS_RDCNTR_MASK             (0xFFFF0000U)
#define FLEXSPI_IPRXFSTS_RDCNTR_SHIFT            (16U)
/*! RDCNTR - Read Data Counter */
#define FLEXSPI_IPRXFSTS_RDCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFSTS_RDCNTR_SHIFT)) & FLEXSPI_IPRXFSTS_RDCNTR_MASK)
/*! @} */

/*! @name IPTXFSTS - IP Transmit FIFO Status */
/*! @{ */

#define FLEXSPI_IPTXFSTS_FILL_MASK               (0xFFU)
#define FLEXSPI_IPTXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill Level of IP Transmit FIFO */
#define FLEXSPI_IPTXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFSTS_FILL_SHIFT)) & FLEXSPI_IPTXFSTS_FILL_MASK)

#define FLEXSPI_IPTXFSTS_WRCNTR_MASK             (0xFFFF0000U)
#define FLEXSPI_IPTXFSTS_WRCNTR_SHIFT            (16U)
/*! WRCNTR - Write Data Counter */
#define FLEXSPI_IPTXFSTS_WRCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFSTS_WRCNTR_SHIFT)) & FLEXSPI_IPTXFSTS_WRCNTR_MASK)
/*! @} */

/*! @name RFDR - IP Receive FIFO Data 0..IP Receive FIFO Data 31 */
/*! @{ */

#define FLEXSPI_RFDR_RXDATA_MASK                 (0xFFFFFFFFU)
#define FLEXSPI_RFDR_RXDATA_SHIFT                (0U)
/*! RXDATA - Receive Data */
#define FLEXSPI_RFDR_RXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_RFDR_RXDATA_SHIFT)) & FLEXSPI_RFDR_RXDATA_MASK)
/*! @} */

/*! @name TFDR - IP TX FIFO Data 0..IP TX FIFO Data 31 */
/*! @{ */

#define FLEXSPI_TFDR_TXDATA_MASK                 (0xFFFFFFFFU)
#define FLEXSPI_TFDR_TXDATA_SHIFT                (0U)
/*! TXDATA - Transmit Data */
#define FLEXSPI_TFDR_TXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_TFDR_TXDATA_SHIFT)) & FLEXSPI_TFDR_TXDATA_MASK)
/*! @} */

/*! @name LUT - Lookup Table 0..Lookup Table 63 */
/*! @{ */

#define FLEXSPI_LUT_OPERAND0_MASK                (0xFFU)
#define FLEXSPI_LUT_OPERAND0_SHIFT               (0U)
/*! OPERAND0 - OPERAND0 */
#define FLEXSPI_LUT_OPERAND0(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPERAND0_SHIFT)) & FLEXSPI_LUT_OPERAND0_MASK)

#define FLEXSPI_LUT_NUM_PADS0_MASK               (0x300U)
#define FLEXSPI_LUT_NUM_PADS0_SHIFT              (8U)
/*! NUM_PADS0 - NUM_PADS0 */
#define FLEXSPI_LUT_NUM_PADS0(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_NUM_PADS0_SHIFT)) & FLEXSPI_LUT_NUM_PADS0_MASK)

#define FLEXSPI_LUT_OPCODE0_MASK                 (0xFC00U)
#define FLEXSPI_LUT_OPCODE0_SHIFT                (10U)
/*! OPCODE0 - OPCODE */
#define FLEXSPI_LUT_OPCODE0(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPCODE0_SHIFT)) & FLEXSPI_LUT_OPCODE0_MASK)

#define FLEXSPI_LUT_OPERAND1_MASK                (0xFF0000U)
#define FLEXSPI_LUT_OPERAND1_SHIFT               (16U)
/*! OPERAND1 - OPERAND1 */
#define FLEXSPI_LUT_OPERAND1(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPERAND1_SHIFT)) & FLEXSPI_LUT_OPERAND1_MASK)

#define FLEXSPI_LUT_NUM_PADS1_MASK               (0x3000000U)
#define FLEXSPI_LUT_NUM_PADS1_SHIFT              (24U)
/*! NUM_PADS1 - NUM_PADS1 */
#define FLEXSPI_LUT_NUM_PADS1(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_NUM_PADS1_SHIFT)) & FLEXSPI_LUT_NUM_PADS1_MASK)

#define FLEXSPI_LUT_OPCODE1_MASK                 (0xFC000000U)
#define FLEXSPI_LUT_OPCODE1_SHIFT                (26U)
/*! OPCODE1 - OPCODE1 */
#define FLEXSPI_LUT_OPCODE1(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPCODE1_SHIFT)) & FLEXSPI_LUT_OPCODE1_MASK)
/*! @} */

/*! @name HADDRSTART - HADDR REMAP Start Address */
/*! @{ */

#define FLEXSPI_HADDRSTART_REMAPEN_MASK          (0x1U)
#define FLEXSPI_HADDRSTART_REMAPEN_SHIFT         (0U)
/*! REMAPEN - AHB Bus Address Remap Enable
 *  0b0..HADDR REMAP Disabled
 *  0b1..HADDR REMAP Enabled
 */
#define FLEXSPI_HADDRSTART_REMAPEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDRSTART_REMAPEN_SHIFT)) & FLEXSPI_HADDRSTART_REMAPEN_MASK)

#define FLEXSPI_HADDRSTART_ADDRSTART_MASK        (0xFFFFF000U)
#define FLEXSPI_HADDRSTART_ADDRSTART_SHIFT       (12U)
/*! ADDRSTART - HADDR Start Address */
#define FLEXSPI_HADDRSTART_ADDRSTART(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDRSTART_ADDRSTART_SHIFT)) & FLEXSPI_HADDRSTART_ADDRSTART_MASK)
/*! @} */

/*! @name HADDREND - HADDR REMAP END ADDR */
/*! @{ */

#define FLEXSPI_HADDREND_ENDSTART_MASK           (0xFFFFF000U)
#define FLEXSPI_HADDREND_ENDSTART_SHIFT          (12U)
/*! ENDSTART - End Address of HADDR Remap Range */
#define FLEXSPI_HADDREND_ENDSTART(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDREND_ENDSTART_SHIFT)) & FLEXSPI_HADDREND_ENDSTART_MASK)
/*! @} */

/*! @name HADDROFFSET - HADDR Remap Offset */
/*! @{ */

#define FLEXSPI_HADDROFFSET_ADDROFFSET_MASK      (0xFFFFF000U)
#define FLEXSPI_HADDROFFSET_ADDROFFSET_SHIFT     (12U)
/*! ADDROFFSET - HADDR Offset */
#define FLEXSPI_HADDROFFSET_ADDROFFSET(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDROFFSET_ADDROFFSET_SHIFT)) & FLEXSPI_HADDROFFSET_ADDROFFSET_MASK)
/*! @} */

/*! @name IPEDCTRL - IPED Function Control */
/*! @{ */

#define FLEXSPI_IPEDCTRL_CONFIG_MASK             (0x1U)
#define FLEXSPI_IPEDCTRL_CONFIG_SHIFT            (0U)
/*! CONFIG - IPED Mode Select
 *  0b0..Fully pipelined
 *  0b1..Not fully pipelined
 */
#define FLEXSPI_IPEDCTRL_CONFIG(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_CONFIG_SHIFT)) & FLEXSPI_IPEDCTRL_CONFIG_MASK)

#define FLEXSPI_IPEDCTRL_IPED_EN_MASK            (0x2U)
#define FLEXSPI_IPEDCTRL_IPED_EN_SHIFT           (1U)
/*! IPED_EN - IPED Encryption and Decryption Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_IPED_EN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_IPED_EN_SHIFT)) & FLEXSPI_IPEDCTRL_IPED_EN_MASK)

#define FLEXSPI_IPEDCTRL_IPWR_EN_MASK            (0x4U)
#define FLEXSPI_IPEDCTRL_IPWR_EN_SHIFT           (2U)
/*! IPWR_EN - IP Write IPED CTR Mode Encryption Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_IPWR_EN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_IPWR_EN_SHIFT)) & FLEXSPI_IPEDCTRL_IPWR_EN_MASK)

#define FLEXSPI_IPEDCTRL_AHBWR_EN_MASK           (0x8U)
#define FLEXSPI_IPEDCTRL_AHBWR_EN_SHIFT          (3U)
/*! AHBWR_EN - AHB Write IPED CTR Mode Encryption Enable.
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_AHBWR_EN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_AHBWR_EN_SHIFT)) & FLEXSPI_IPEDCTRL_AHBWR_EN_MASK)

#define FLEXSPI_IPEDCTRL_AHBRD_EN_MASK           (0x10U)
#define FLEXSPI_IPEDCTRL_AHBRD_EN_SHIFT          (4U)
/*! AHBRD_EN - AHB Read IPED CTR Mode Decryption Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_AHBRD_EN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_AHBRD_EN_SHIFT)) & FLEXSPI_IPEDCTRL_AHBRD_EN_MASK)

#define FLEXSPI_IPEDCTRL_IPGCMWR_MASK            (0x40U)
#define FLEXSPI_IPEDCTRL_IPGCMWR_SHIFT           (6U)
/*! IPGCMWR - IP Write GCM Mode Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FLEXSPI_IPEDCTRL_IPGCMWR(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_IPGCMWR_SHIFT)) & FLEXSPI_IPEDCTRL_IPGCMWR_MASK)

#define FLEXSPI_IPEDCTRL_AHGCMWR_MASK            (0x80U)
#define FLEXSPI_IPEDCTRL_AHGCMWR_SHIFT           (7U)
/*! AHGCMWR - AHB Write IPED GCM Mode Encryption Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_AHGCMWR(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_AHGCMWR_SHIFT)) & FLEXSPI_IPEDCTRL_AHGCMWR_MASK)

#define FLEXSPI_IPEDCTRL_AHBGCMRD_MASK           (0x100U)
#define FLEXSPI_IPEDCTRL_AHBGCMRD_SHIFT          (8U)
/*! AHBGCMRD - AHB Read IPED GCM Mode Decryption Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_IPEDCTRL_AHBGCMRD(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_AHBGCMRD_SHIFT)) & FLEXSPI_IPEDCTRL_AHBGCMRD_MASK)

#define FLEXSPI_IPEDCTRL_IPED_PROTECT_MASK       (0x200U)
#define FLEXSPI_IPEDCTRL_IPED_PROTECT_SHIFT      (9U)
/*! IPED_PROTECT - IPED Protection
 *  0b0..No restrictions
 *  0b1..Only privileged controllers can write IPED registers.
 */
#define FLEXSPI_IPEDCTRL_IPED_PROTECT(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_IPED_PROTECT_SHIFT)) & FLEXSPI_IPEDCTRL_IPED_PROTECT_MASK)

#define FLEXSPI_IPEDCTRL_IPED_SWRESET_MASK       (0x400U)
#define FLEXSPI_IPEDCTRL_IPED_SWRESET_SHIFT      (10U)
/*! IPED_SWRESET - Abort Current Decryption or Encryption
 *  0b0..No function.
 *  0b1..Aborts current decryption or encryption and waits for the next start operation.
 */
#define FLEXSPI_IPEDCTRL_IPED_SWRESET(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTRL_IPED_SWRESET_SHIFT)) & FLEXSPI_IPEDCTRL_IPED_SWRESET_MASK)
/*! @} */

/*! @name IPSNSZSTART0 - IPS Nonsecure Region 0 Start Address */
/*! @{ */

#define FLEXSPI_IPSNSZSTART0_start_address_MASK  (0xFFFFF000U)
#define FLEXSPI_IPSNSZSTART0_start_address_SHIFT (12U)
/*! start_address - Start Address of Nonsecure Region */
#define FLEXSPI_IPSNSZSTART0_start_address(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPSNSZSTART0_start_address_SHIFT)) & FLEXSPI_IPSNSZSTART0_start_address_MASK)
/*! @} */

/*! @name IPSNSZEND0 - IPS Nonsecure Region 0 End Address */
/*! @{ */

#define FLEXSPI_IPSNSZEND0_end_address_MASK      (0xFFFFF000U)
#define FLEXSPI_IPSNSZEND0_end_address_SHIFT     (12U)
/*! end_address - End Address of Nonsecure Region */
#define FLEXSPI_IPSNSZEND0_end_address(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPSNSZEND0_end_address_SHIFT)) & FLEXSPI_IPSNSZEND0_end_address_MASK)
/*! @} */

/*! @name IPSNSZSTART1 - IPS Nonsecure Region 1 Start Address */
/*! @{ */

#define FLEXSPI_IPSNSZSTART1_start_address_MASK  (0xFFFFF000U)
#define FLEXSPI_IPSNSZSTART1_start_address_SHIFT (12U)
/*! start_address - Start Address of Nonsecure Region */
#define FLEXSPI_IPSNSZSTART1_start_address(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPSNSZSTART1_start_address_SHIFT)) & FLEXSPI_IPSNSZSTART1_start_address_MASK)
/*! @} */

/*! @name IPSNSZEND1 - IPS Nonsecure Region 1 End Address */
/*! @{ */

#define FLEXSPI_IPSNSZEND1_end_address_MASK      (0xFFFFF000U)
#define FLEXSPI_IPSNSZEND1_end_address_SHIFT     (12U)
/*! end_address - End Address of Nonsecure Region */
#define FLEXSPI_IPSNSZEND1_end_address(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPSNSZEND1_end_address_SHIFT)) & FLEXSPI_IPSNSZEND1_end_address_MASK)
/*! @} */

/*! @name AHBBUFREGIONSTART0 - Receive Buffer Start Address of Region 0 */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONSTART0_START_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONSTART0_START_ADDRESS_SHIFT (12U)
/*! START_ADDRESS - Start Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONSTART0_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONSTART0_START_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONSTART0_START_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONEND0 - Receive Buffer Region 0 End Address */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONEND0_END_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONEND0_END_ADDRESS_SHIFT (12U)
/*! END_ADDRESS - End Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONEND0_END_ADDRESS(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONEND0_END_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONEND0_END_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONSTART1 - Receive Buffer Start Address of Region 1 */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONSTART1_START_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONSTART1_START_ADDRESS_SHIFT (12U)
/*! START_ADDRESS - Start Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONSTART1_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONSTART1_START_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONSTART1_START_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONEND1 - Receive Buffer Region 1 End Address */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONEND1_END_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONEND1_END_ADDRESS_SHIFT (12U)
/*! END_ADDRESS - End Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONEND1_END_ADDRESS(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONEND1_END_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONEND1_END_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONSTART2 - Receive Buffer Start Address of Region 2 */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONSTART2_START_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONSTART2_START_ADDRESS_SHIFT (12U)
/*! START_ADDRESS - Start Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONSTART2_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONSTART2_START_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONSTART2_START_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONEND2 - Receive Buffer Region 2 End Address */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONEND2_END_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONEND2_END_ADDRESS_SHIFT (12U)
/*! END_ADDRESS - End Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONEND2_END_ADDRESS(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONEND2_END_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONEND2_END_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONSTART3 - Receive Buffer Start Address of Region 3 */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONSTART3_START_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONSTART3_START_ADDRESS_SHIFT (12U)
/*! START_ADDRESS - Start Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONSTART3_START_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONSTART3_START_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONSTART3_START_ADDRESS_MASK)
/*! @} */

/*! @name AHBBUFREGIONEND3 - Receive Buffer Region 3 End Address */
/*! @{ */

#define FLEXSPI_AHBBUFREGIONEND3_END_ADDRESS_MASK (0xFFFFF000U)
#define FLEXSPI_AHBBUFREGIONEND3_END_ADDRESS_SHIFT (12U)
/*! END_ADDRESS - End Address of Prefetch Sub-Buffer Region */
#define FLEXSPI_AHBBUFREGIONEND3_END_ADDRESS(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBBUFREGIONEND3_END_ADDRESS_SHIFT)) & FLEXSPI_AHBBUFREGIONEND3_END_ADDRESS_MASK)
/*! @} */

/*! @name IPEDCTXCTRLX_IPEDCTXCTRL - IPED context control 0..IPED context control 1 */
/*! @{ */

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE0_MASK (0x3U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE0_SHIFT (0U)
/*! CTX0_FREEZE0 - Context Register Freeze for Region 0 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE1_MASK (0x3U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE1_SHIFT (0U)
/*! CTX0_FREEZE1 - Context Register Freeze for Region 0 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX0_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE0_MASK (0xCU)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE0_SHIFT (2U)
/*! CTX1_FREEZE0 - Context Register Freeze for Region 1 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE1_MASK (0xCU)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE1_SHIFT (2U)
/*! CTX1_FREEZE1 - Context Register Freeze for Region 1 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX1_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE0_MASK (0x30U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE0_SHIFT (4U)
/*! CTX2_FREEZE0 - Context Register Freeze for Region 2 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE1_MASK (0x30U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE1_SHIFT (4U)
/*! CTX2_FREEZE1 - Context Register Freeze for Region 2 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX2_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE0_MASK (0xC0U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE0_SHIFT (6U)
/*! CTX3_FREEZE0 - Context Register Freeze for Region 3 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE1_MASK (0xC0U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE1_SHIFT (6U)
/*! CTX3_FREEZE1 - Context Register Freeze for Region 3 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX3_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE0_MASK (0x300U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE0_SHIFT (8U)
/*! CTX4_FREEZE0 - Context Register Freeze for Region 4 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE1_MASK (0x300U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE1_SHIFT (8U)
/*! CTX4_FREEZE1 - Context Register Freeze for Region 4 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX4_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE0_MASK (0xC00U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE0_SHIFT (10U)
/*! CTX5_FREEZE0 - Context Register Freeze for Region 5 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE1_MASK (0xC00U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE1_SHIFT (10U)
/*! CTX5_FREEZE1 - Context Register Freeze for Region 5 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX5_FREEZE1_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE0_MASK (0x3000U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE0_SHIFT (12U)
/*! CTX6_FREEZE0 - Context Register Freeze for Region 6 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE0(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE0_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE0_MASK)

#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE1_MASK (0x3000U)
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE1_SHIFT (12U)
/*! CTX6_FREEZE1 - Context Register Freeze for Region 6 */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE1_SHIFT)) & FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_CTX6_FREEZE1_MASK)
/*! @} */

/* The count of FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL */
#define FLEXSPI_IPEDCTXCTRLX_IPEDCTXCTRL_COUNT   (2U)

/*! @name IPEDCTX0IV0 - IPED Context0 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX0IV0_CTX0_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX0IV0_CTX0_IV0_SHIFT       (0U)
/*! CTX0_IV0 - Lowest 32 bits of IV for region 0. */
#define FLEXSPI_IPEDCTX0IV0_CTX0_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0IV0_CTX0_IV0_SHIFT)) & FLEXSPI_IPEDCTX0IV0_CTX0_IV0_MASK)
/*! @} */

/*! @name IPEDCTX0IV1 - IPED Context0 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX0IV1_CTX0_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX0IV1_CTX0_IV1_SHIFT       (0U)
/*! CTX0_IV1 - Highest 32 bits of IV for region 0. */
#define FLEXSPI_IPEDCTX0IV1_CTX0_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0IV1_CTX0_IV1_SHIFT)) & FLEXSPI_IPEDCTX0IV1_CTX0_IV1_MASK)
/*! @} */

/*! @name IPEDCTX0START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX0START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX0START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX0START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0START_GCM_SHIFT)) & FLEXSPI_IPEDCTX0START_GCM_MASK)

#define FLEXSPI_IPEDCTX0START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX0START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX0START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX0START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX0START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX0START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX0START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0START_start_address_SHIFT)) & FLEXSPI_IPEDCTX0START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX0END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX0END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX0END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX0END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0END_end_address_SHIFT)) & FLEXSPI_IPEDCTX0END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX0AAD0 - IPED Context0 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX0AAD0_CTX0_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX0AAD0_CTX0_AAD0_SHIFT     (0U)
/*! CTX0_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX0AAD0_CTX0_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0AAD0_CTX0_AAD0_SHIFT)) & FLEXSPI_IPEDCTX0AAD0_CTX0_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX0AAD1 - IPED Context0 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX0AAD1_CTX0_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX0AAD1_CTX0_AAD1_SHIFT     (0U)
/*! CTX0_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX0AAD1_CTX0_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX0AAD1_CTX0_AAD1_SHIFT)) & FLEXSPI_IPEDCTX0AAD1_CTX0_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX1IV0 - IPED Context1 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX1IV0_CTX1_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX1IV0_CTX1_IV0_SHIFT       (0U)
/*! CTX1_IV0 - Lowest 32 bits of IV for region 1. */
#define FLEXSPI_IPEDCTX1IV0_CTX1_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1IV0_CTX1_IV0_SHIFT)) & FLEXSPI_IPEDCTX1IV0_CTX1_IV0_MASK)
/*! @} */

/*! @name IPEDCTX1IV1 - IPED Context1 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX1IV1_CTX1_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX1IV1_CTX1_IV1_SHIFT       (0U)
/*! CTX1_IV1 - Highest 32 bits of IV for region 1. */
#define FLEXSPI_IPEDCTX1IV1_CTX1_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1IV1_CTX1_IV1_SHIFT)) & FLEXSPI_IPEDCTX1IV1_CTX1_IV1_MASK)
/*! @} */

/*! @name IPEDCTX1START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX1START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX1START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX1START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1START_GCM_SHIFT)) & FLEXSPI_IPEDCTX1START_GCM_MASK)

#define FLEXSPI_IPEDCTX1START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX1START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX1START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX1START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX1START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX1START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX1START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1START_start_address_SHIFT)) & FLEXSPI_IPEDCTX1START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX1END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX1END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX1END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX1END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1END_end_address_SHIFT)) & FLEXSPI_IPEDCTX1END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX1AAD0 - IPED Context1 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX1AAD0_CTX1_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX1AAD0_CTX1_AAD0_SHIFT     (0U)
/*! CTX1_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX1AAD0_CTX1_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1AAD0_CTX1_AAD0_SHIFT)) & FLEXSPI_IPEDCTX1AAD0_CTX1_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX1AAD1 - IPED Context1 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX1AAD1_CTX1_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX1AAD1_CTX1_AAD1_SHIFT     (0U)
/*! CTX1_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX1AAD1_CTX1_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX1AAD1_CTX1_AAD1_SHIFT)) & FLEXSPI_IPEDCTX1AAD1_CTX1_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX2IV0 - IPED Context2 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX2IV0_CTX2_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX2IV0_CTX2_IV0_SHIFT       (0U)
/*! CTX2_IV0 - Lowest 32 bits of IV for region 2. */
#define FLEXSPI_IPEDCTX2IV0_CTX2_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2IV0_CTX2_IV0_SHIFT)) & FLEXSPI_IPEDCTX2IV0_CTX2_IV0_MASK)
/*! @} */

/*! @name IPEDCTX2IV1 - IPED Context2 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX2IV1_CTX2_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX2IV1_CTX2_IV1_SHIFT       (0U)
/*! CTX2_IV1 - Highest 32 bits of IV for region 2. */
#define FLEXSPI_IPEDCTX2IV1_CTX2_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2IV1_CTX2_IV1_SHIFT)) & FLEXSPI_IPEDCTX2IV1_CTX2_IV1_MASK)
/*! @} */

/*! @name IPEDCTX2START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX2START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX2START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX2START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2START_GCM_SHIFT)) & FLEXSPI_IPEDCTX2START_GCM_MASK)

#define FLEXSPI_IPEDCTX2START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX2START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX2START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX2START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX2START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX2START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX2START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2START_start_address_SHIFT)) & FLEXSPI_IPEDCTX2START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX2END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX2END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX2END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX2END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2END_end_address_SHIFT)) & FLEXSPI_IPEDCTX2END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX2AAD0 - IPED Context2 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX2AAD0_CTX2_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX2AAD0_CTX2_AAD0_SHIFT     (0U)
/*! CTX2_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX2AAD0_CTX2_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2AAD0_CTX2_AAD0_SHIFT)) & FLEXSPI_IPEDCTX2AAD0_CTX2_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX2AAD1 - IPED Context2 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX2AAD1_CTX2_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX2AAD1_CTX2_AAD1_SHIFT     (0U)
/*! CTX2_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX2AAD1_CTX2_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX2AAD1_CTX2_AAD1_SHIFT)) & FLEXSPI_IPEDCTX2AAD1_CTX2_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX3IV0 - IPED Context3 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX3IV0_CTX3_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX3IV0_CTX3_IV0_SHIFT       (0U)
/*! CTX3_IV0 - Lowest 32 bits of IV for region 3. */
#define FLEXSPI_IPEDCTX3IV0_CTX3_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3IV0_CTX3_IV0_SHIFT)) & FLEXSPI_IPEDCTX3IV0_CTX3_IV0_MASK)
/*! @} */

/*! @name IPEDCTX3IV1 - IPED Context3 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX3IV1_CTX3_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX3IV1_CTX3_IV1_SHIFT       (0U)
/*! CTX3_IV1 - Highest 32 bits of IV for region 3. */
#define FLEXSPI_IPEDCTX3IV1_CTX3_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3IV1_CTX3_IV1_SHIFT)) & FLEXSPI_IPEDCTX3IV1_CTX3_IV1_MASK)
/*! @} */

/*! @name IPEDCTX3START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX3START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX3START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX3START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3START_GCM_SHIFT)) & FLEXSPI_IPEDCTX3START_GCM_MASK)

#define FLEXSPI_IPEDCTX3START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX3START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX3START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX3START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX3START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX3START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX3START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3START_start_address_SHIFT)) & FLEXSPI_IPEDCTX3START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX3END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX3END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX3END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX3END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3END_end_address_SHIFT)) & FLEXSPI_IPEDCTX3END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX3AAD0 - IPED Context3 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX3AAD0_CTX3_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX3AAD0_CTX3_AAD0_SHIFT     (0U)
/*! CTX3_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX3AAD0_CTX3_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3AAD0_CTX3_AAD0_SHIFT)) & FLEXSPI_IPEDCTX3AAD0_CTX3_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX3AAD1 - IPED Context3 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX3AAD1_CTX3_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX3AAD1_CTX3_AAD1_SHIFT     (0U)
/*! CTX3_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX3AAD1_CTX3_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX3AAD1_CTX3_AAD1_SHIFT)) & FLEXSPI_IPEDCTX3AAD1_CTX3_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX4IV0 - IPED Context4 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX4IV0_CTX4_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX4IV0_CTX4_IV0_SHIFT       (0U)
/*! CTX4_IV0 - Lowest 32 bits of IV for region 4. */
#define FLEXSPI_IPEDCTX4IV0_CTX4_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4IV0_CTX4_IV0_SHIFT)) & FLEXSPI_IPEDCTX4IV0_CTX4_IV0_MASK)
/*! @} */

/*! @name IPEDCTX4IV1 - IPED Context4 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX4IV1_CTX4_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX4IV1_CTX4_IV1_SHIFT       (0U)
/*! CTX4_IV1 - Highest 32 bits of IV for region 4. */
#define FLEXSPI_IPEDCTX4IV1_CTX4_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4IV1_CTX4_IV1_SHIFT)) & FLEXSPI_IPEDCTX4IV1_CTX4_IV1_MASK)
/*! @} */

/*! @name IPEDCTX4START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX4START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX4START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX4START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4START_GCM_SHIFT)) & FLEXSPI_IPEDCTX4START_GCM_MASK)

#define FLEXSPI_IPEDCTX4START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX4START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX4START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX4START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX4START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX4START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX4START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4START_start_address_SHIFT)) & FLEXSPI_IPEDCTX4START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX4END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX4END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX4END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX4END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4END_end_address_SHIFT)) & FLEXSPI_IPEDCTX4END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX4AAD0 - IPED Context4 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX4AAD0_CTX4_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX4AAD0_CTX4_AAD0_SHIFT     (0U)
/*! CTX4_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX4AAD0_CTX4_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4AAD0_CTX4_AAD0_SHIFT)) & FLEXSPI_IPEDCTX4AAD0_CTX4_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX4AAD1 - IPED Context4 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX4AAD1_CTX4_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX4AAD1_CTX4_AAD1_SHIFT     (0U)
/*! CTX4_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX4AAD1_CTX4_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX4AAD1_CTX4_AAD1_SHIFT)) & FLEXSPI_IPEDCTX4AAD1_CTX4_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX5IV0 - IPED Context5 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX5IV0_CTX5_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX5IV0_CTX5_IV0_SHIFT       (0U)
/*! CTX5_IV0 - Lowest 32 bits of IV for region 5. */
#define FLEXSPI_IPEDCTX5IV0_CTX5_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5IV0_CTX5_IV0_SHIFT)) & FLEXSPI_IPEDCTX5IV0_CTX5_IV0_MASK)
/*! @} */

/*! @name IPEDCTX5IV1 - IPED Context5 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX5IV1_CTX5_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX5IV1_CTX5_IV1_SHIFT       (0U)
/*! CTX5_IV1 - Highest 32 bits of IV for region 5. */
#define FLEXSPI_IPEDCTX5IV1_CTX5_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5IV1_CTX5_IV1_SHIFT)) & FLEXSPI_IPEDCTX5IV1_CTX5_IV1_MASK)
/*! @} */

/*! @name IPEDCTX5START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX5START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX5START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX5START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5START_GCM_SHIFT)) & FLEXSPI_IPEDCTX5START_GCM_MASK)

#define FLEXSPI_IPEDCTX5START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX5START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX5START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX5START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX5START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX5START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX5START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5START_start_address_SHIFT)) & FLEXSPI_IPEDCTX5START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX5END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX5END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX5END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX5END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5END_end_address_SHIFT)) & FLEXSPI_IPEDCTX5END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX5AAD0 - IPED Context5 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX5AAD0_CTX5_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX5AAD0_CTX5_AAD0_SHIFT     (0U)
/*! CTX5_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX5AAD0_CTX5_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5AAD0_CTX5_AAD0_SHIFT)) & FLEXSPI_IPEDCTX5AAD0_CTX5_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX5AAD1 - IPED Context5 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX5AAD1_CTX5_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX5AAD1_CTX5_AAD1_SHIFT     (0U)
/*! CTX5_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX5AAD1_CTX5_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX5AAD1_CTX5_AAD1_SHIFT)) & FLEXSPI_IPEDCTX5AAD1_CTX5_AAD1_MASK)
/*! @} */

/*! @name IPEDCTX6IV0 - IPED Context6 IV0 */
/*! @{ */

#define FLEXSPI_IPEDCTX6IV0_CTX6_IV0_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX6IV0_CTX6_IV0_SHIFT       (0U)
/*! CTX6_IV0 - Lowest 32 bits of IV for region 6. */
#define FLEXSPI_IPEDCTX6IV0_CTX6_IV0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6IV0_CTX6_IV0_SHIFT)) & FLEXSPI_IPEDCTX6IV0_CTX6_IV0_MASK)
/*! @} */

/*! @name IPEDCTX6IV1 - IPED Context6 IV1 */
/*! @{ */

#define FLEXSPI_IPEDCTX6IV1_CTX6_IV1_MASK        (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX6IV1_CTX6_IV1_SHIFT       (0U)
/*! CTX6_IV1 - Highest 32 bits of IV for region 6. */
#define FLEXSPI_IPEDCTX6IV1_CTX6_IV1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6IV1_CTX6_IV1_SHIFT)) & FLEXSPI_IPEDCTX6IV1_CTX6_IV1_MASK)
/*! @} */

/*! @name IPEDCTX6START - Start Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX6START_GCM_MASK           (0x1U)
#define FLEXSPI_IPEDCTX6START_GCM_SHIFT          (0U)
/*! GCM - GCM Mode Enable
 *  0b0..Disabled. CTR mode is used.
 *  0b1..Enabled. GCM mode is used.
 */
#define FLEXSPI_IPEDCTX6START_GCM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6START_GCM_SHIFT)) & FLEXSPI_IPEDCTX6START_GCM_MASK)

#define FLEXSPI_IPEDCTX6START_ahbbuserror_dis_MASK (0x2U)
#define FLEXSPI_IPEDCTX6START_ahbbuserror_dis_SHIFT (1U)
/*! ahbbuserror_dis - AHB Bus Error Disable
 *  0b0..AHB bus errors enabled
 *  0b1..AHB bus errors disabled
 */
#define FLEXSPI_IPEDCTX6START_ahbbuserror_dis(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6START_ahbbuserror_dis_SHIFT)) & FLEXSPI_IPEDCTX6START_ahbbuserror_dis_MASK)

#define FLEXSPI_IPEDCTX6START_start_address_MASK (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX6START_start_address_SHIFT (8U)
/*! start_address - Start Address */
#define FLEXSPI_IPEDCTX6START_start_address(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6START_start_address_SHIFT)) & FLEXSPI_IPEDCTX6START_start_address_MASK)
/*! @} */

/*! @name IPEDCTX6END - End Address of Region */
/*! @{ */

#define FLEXSPI_IPEDCTX6END_end_address_MASK     (0xFFFFFF00U)
#define FLEXSPI_IPEDCTX6END_end_address_SHIFT    (8U)
/*! end_address - End Address of IPED Region */
#define FLEXSPI_IPEDCTX6END_end_address(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6END_end_address_SHIFT)) & FLEXSPI_IPEDCTX6END_end_address_MASK)
/*! @} */

/*! @name IPEDCTX6AAD0 - IPED Context6 Additional Authenticated Data0 */
/*! @{ */

#define FLEXSPI_IPEDCTX6AAD0_CTX6_AAD0_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX6AAD0_CTX6_AAD0_SHIFT     (0U)
/*! CTX6_AAD0 - CTX AAD */
#define FLEXSPI_IPEDCTX6AAD0_CTX6_AAD0(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6AAD0_CTX6_AAD0_SHIFT)) & FLEXSPI_IPEDCTX6AAD0_CTX6_AAD0_MASK)
/*! @} */

/*! @name IPEDCTX6AAD1 - IPED Context6 Additional Authenticated Data1 */
/*! @{ */

#define FLEXSPI_IPEDCTX6AAD1_CTX6_AAD1_MASK      (0xFFFFFFFFU)
#define FLEXSPI_IPEDCTX6AAD1_CTX6_AAD1_SHIFT     (0U)
/*! CTX6_AAD1 - CTX AAD */
#define FLEXSPI_IPEDCTX6AAD1_CTX6_AAD1(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPEDCTX6AAD1_CTX6_AAD1_SHIFT)) & FLEXSPI_IPEDCTX6AAD1_CTX6_AAD1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLEXSPI_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXSPI_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FLEXSPI_H_ */


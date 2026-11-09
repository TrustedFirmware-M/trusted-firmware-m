/*
** ###################################################################
**     Processors:          MCXA286VAPR
**                          MCXA286VASR
**                          MCXA286VLL
**                          MCXA286VLQ
**                          MCXA286VPN
**                          MCXA287VAPR
**                          MCXA287VASR
**                          MCXA287VLL
**                          MCXA287VLQ
**                          MCXA287VPN
**                          MCXA456VASR
**                          MCXA456VLL
**                          MCXA456VLQ
**                          MCXA456VPN
**                          MCXA457VASR
**                          MCXA457VLL
**                          MCXA457VLQ
**                          MCXA457VPN
**                          MCXA556BVPN
**                          MCXA556VPN
**                          MCXA557BVPN
**                          MCXA557VPN
**                          MCXA566VLL
**                          MCXA566VLQ
**                          MCXA566VPN
**                          MCXA567VLL
**                          MCXA567VLQ
**                          MCXA567VPN
**                          MCXA577VAPR
**                          MCXA577VLL
**                          MCXA577VLQ
**                          MCXA577VPN
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260904
**
**     Abstract:
**         CMSIS Peripheral Access Layer for I3C
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_I3C.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for I3C
 *
 * CMSIS Peripheral Access Layer for I3C
 */

#if !defined(PERI_I3C_H_)
#define PERI_I3C_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA556BVPN) || defined(CPU_MCXA556VPN))
#include "MCXA556_COMMON.h"
#elif (defined(CPU_MCXA557BVPN) || defined(CPU_MCXA557VPN))
#include "MCXA557_COMMON.h"
#elif (defined(CPU_MCXA566VLL) || defined(CPU_MCXA566VLQ) || defined(CPU_MCXA566VPN))
#include "MCXA566_COMMON.h"
#elif (defined(CPU_MCXA567VLL) || defined(CPU_MCXA567VLQ) || defined(CPU_MCXA567VPN))
#include "MCXA567_COMMON.h"
#elif (defined(CPU_MCXA577VAPR) || defined(CPU_MCXA577VLL) || defined(CPU_MCXA577VLQ) || defined(CPU_MCXA577VPN))
#include "MCXA577_COMMON.h"
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
   -- I3C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I3C_Peripheral_Access_Layer I3C Peripheral Access Layer
 * @{
 */

/** I3C - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCONFIG;                           /**< Controller Configuration, offset: 0x0 */
  __IO uint32_t SCONFIG;                           /**< Target Configuration, offset: 0x4 */
  __IO uint32_t SSTATUS;                           /**< Target Status, offset: 0x8 */
  __IO uint32_t SCTRL;                             /**< Target Control, offset: 0xC */
  __IO uint32_t SINTSET;                           /**< Target Interrupt Set, offset: 0x10 */
  __IO uint32_t SINTCLR;                           /**< Target Interrupt Clear, offset: 0x14 */
  __I  uint32_t SINTMASKED;                        /**< Target Interrupt Mask, offset: 0x18 */
  __IO uint32_t SERRWARN;                          /**< Target Errors and Warnings, offset: 0x1C */
  __IO uint32_t SDMACTRL;                          /**< Target DMA Control, offset: 0x20 */
  __IO uint32_t SHDRBTCFG;                         /**< Target HDR-BT Configuration, offset: 0x24, not available in all instances (available on 32 out of 128) */
  __I  uint32_t SHDRBTLAST;                        /**< Target HDR-Last, offset: 0x28, not available in all instances (available on 32 out of 128) */
  __IO uint32_t SDATACTRL;                         /**< Target Data Control, offset: 0x2C */
  __O  uint32_t SWDATAB;                           /**< Target Write Data Byte, offset: 0x30 */
  __O  uint32_t SWDATABE;                          /**< Target Write Data Byte End, offset: 0x34 */
  __O  uint32_t SWDATAH;                           /**< Target Write Data Halfword, offset: 0x38 */
  __O  uint32_t SWDATAHE;                          /**< Target Write Data Halfword End, offset: 0x3C */
  __I  uint32_t SRDATAB;                           /**< Target Read Data Byte, offset: 0x40 */
       uint8_t RESERVED_0[4];
  __I  uint32_t SRDATAH;                           /**< Target Read Data Halfword, offset: 0x48 */
       uint8_t RESERVED_1[8];
  __O  uint32_t SWDATAB1;                          /**< Target Write Data Byte, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __I  uint32_t SCAPABILITIES2;                    /**< Target Capabilities 2, offset: 0x5C */
  __I  uint32_t SCAPABILITIES;                     /**< Target Capabilities, offset: 0x60 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SMAXLIMITS;                        /**< Target Maximum Limits, offset: 0x68 */
  __IO uint32_t SIDPARTNO;                         /**< Target ID Part Number, offset: 0x6C */
  __IO uint32_t SIDEXT;                            /**< Target ID Extension, offset: 0x70 */
  __IO uint32_t SVENDORID;                         /**< Target Vendor ID, offset: 0x74 */
  __IO uint32_t STCCLOCK;                          /**< Target Time Control Clock, offset: 0x78 */
  __I  uint32_t SMSGMAPADDR;                       /**< Target Message Map Address, offset: 0x7C */
  __IO uint32_t MCONFIG_EXT;                       /**< Controller Extended Configuration, offset: 0x80 */
  __IO uint32_t MCTRL;                             /**< Controller Control, offset: 0x84 */
  __IO uint32_t MSTATUS;                           /**< Controller Status, offset: 0x88 */
  __IO uint32_t MIBIRULES;                         /**< Controller In-band Interrupt Registry and Rules, offset: 0x8C */
  __IO uint32_t MINTSET;                           /**< Controller Interrupt Set, offset: 0x90 */
  __IO uint32_t MINTCLR;                           /**< Controller Interrupt Clear, offset: 0x94 */
  __I  uint32_t MINTMASKED;                        /**< Controller Interrupt Mask, offset: 0x98 */
  __IO uint32_t MERRWARN;                          /**< Controller Errors and Warnings, offset: 0x9C */
  __IO uint32_t MDMACTRL;                          /**< Controller DMA Control, offset: 0xA0 */
  __IO uint32_t MHDRBTCFG;                         /**< Controller HDR-BT Configuration, offset: 0xA4, not available in all instances (available on 32 out of 128) */
  __I  uint32_t MHDRBTLAST;                        /**< Controller HDR-Last, offset: 0xA8, not available in all instances (available on 32 out of 128) */
  __IO uint32_t MDATACTRL;                         /**< Controller Data Control, offset: 0xAC */
  __O  uint32_t MWDATAB;                           /**< Controller Write Data Byte, offset: 0xB0 */
  __O  uint32_t MWDATABE;                          /**< Controller Write Data Byte End, offset: 0xB4 */
  __O  uint32_t MWDATAH;                           /**< Controller Write Data Halfword, offset: 0xB8 */
  __O  uint32_t MWDATAHE;                          /**< Controller Write Data Halfword End, offset: 0xBC */
  __I  uint32_t MRDATAB;                           /**< Controller Read Data Byte, offset: 0xC0 */
       uint8_t RESERVED_4[4];
  __I  uint32_t MRDATAH;                           /**< Controller Read Data Halfword, offset: 0xC8 */
  __O  uint32_t MWDATAB1;                          /**< Controller Write Byte Data 1 (to Bus), offset: 0xCC */
  union {                                          /* offset: 0xD0 */
    __O  uint32_t MWMSG_SDR_CONTROL;                 /**< Controller Write Message Control in SDR mode, offset: 0xD0 */
    __O  uint32_t MWMSG_SDR_DATA;                    /**< Controller Write Message Data in SDR mode, offset: 0xD0 */
  };
  __I  uint32_t MRMSG_SDR;                         /**< Controller Read Message in SDR mode, offset: 0xD4 */
  union {                                          /* offset: 0xD8 */
    __O  uint32_t MWMSG_DDR_CONTROL;                 /**< Controller Write Message in DDR mode: First Control Word, offset: 0xD8 */
    __O  uint32_t MWMSG_DDR_CONTROL2;                /**< Controller Write Message in DDR Mode Control 2, offset: 0xD8 */
    __O  uint32_t MWMSG_DDR_DATA;                    /**< Controller Write Message Data in DDR mode, offset: 0xD8 */
  };
  __I  uint32_t MRMSG_DDR;                         /**< Controller Read Message in DDR mode, offset: 0xDC */
       uint8_t RESERVED_5[4];
  __IO uint32_t MDYNADDR;                          /**< Controller Dynamic Address, offset: 0xE4 */
       uint8_t RESERVED_6[8];
  __O  uint32_t MWDATAW;                           /**< Write Word Data (to Bus), offset: 0xF0, not available in all instances (available on 32 out of 128) */
       uint8_t RESERVED_7[4];
  __I  uint32_t MRDATAW;                           /**< Read Word Data (from Bus), offset: 0xF8, not available in all instances (available on 32 out of 128) */
       uint8_t RESERVED_8[32];
  __I  uint32_t SMAPCTRL0;                         /**< Map Feature Control 0, offset: 0x11C */
  __IO uint32_t SMAPCTRL1;                         /**< Map Feature Control 1, offset: 0x120 */
       uint8_t RESERVED_9[28];
  __IO uint32_t IBIEXT1;                           /**< Extended IBI Data 1, offset: 0x140 */
  __IO uint32_t IBIEXT2;                           /**< Extended IBI Data 2, offset: 0x144 */
       uint8_t RESERVED_10[8];
  __O  uint32_t SWDATAW;                           /**< Target Write Word Data (to Bus), offset: 0x150, not available in all instances (available on 32 out of 128) */
       uint8_t RESERVED_11[4];
  __I  uint32_t SRDATAW;                           /**< Target Read Word Data (from Bus), offset: 0x158, not available in all instances (available on 32 out of 128) */
       uint8_t RESERVED_12[3744];
  __I  uint32_t SID;                               /**< Target Module ID, offset: 0xFFC */
} I3C_Type;

/* ----------------------------------------------------------------------------
   -- I3C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I3C_Register_Masks I3C Register Masks
 * @{
 */

/*! @name MCONFIG - Controller Configuration */
/*! @{ */

#define I3C_MCONFIG_MSTENA_MASK                  (0x3U)
#define I3C_MCONFIG_MSTENA_SHIFT                 (0U)
/*! MSTENA - Controller Enable
 *  0b00..CONTROLLER_OFF
 *  0b01..CONTROLLER_ON
 *  0b10..CONTROLLER_CAPABLE
 *  0b11..I2C_CONTROLLER_MODE
 */
#define I3C_MCONFIG_MSTENA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_MSTENA_SHIFT)) & I3C_MCONFIG_MSTENA_MASK)

#define I3C_MCONFIG_DISTO_MASK                   (0x8U)
#define I3C_MCONFIG_DISTO_SHIFT                  (3U)
/*! DISTO - Disable Timeout
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define I3C_MCONFIG_DISTO(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_DISTO_SHIFT)) & I3C_MCONFIG_DISTO_MASK)

#define I3C_MCONFIG_HKEEP_MASK                   (0x30U)
#define I3C_MCONFIG_HKEEP_SHIFT                  (4U)
/*! HKEEP - High-Keeper
 *  0b00..None
 *  0b01..WIRED_IN
 *  0b10..PASSIVE_SDA (I2C mode, no clock stretches mode)
 *  0b11..PASSIVE_ON_SDA_SCL
 */
#define I3C_MCONFIG_HKEEP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_HKEEP_SHIFT)) & I3C_MCONFIG_HKEEP_MASK)

#define I3C_MCONFIG_ODSTOP_MASK                  (0x40U)
#define I3C_MCONFIG_ODSTOP_SHIFT                 (6U)
/*! ODSTOP - Open-drain Stop
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MCONFIG_ODSTOP(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODSTOP_SHIFT)) & I3C_MCONFIG_ODSTOP_MASK)

#define I3C_MCONFIG_PPBAUD_MASK                  (0xF00U)
#define I3C_MCONFIG_PPBAUD_SHIFT                 (8U)
/*! PPBAUD - Push-Pull Baud Rate */
#define I3C_MCONFIG_PPBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_PPBAUD_SHIFT)) & I3C_MCONFIG_PPBAUD_MASK)

#define I3C_MCONFIG_PPLOW_MASK                   (0xF000U)
#define I3C_MCONFIG_PPLOW_SHIFT                  (12U)
/*! PPLOW - Push-Pull Low */
#define I3C_MCONFIG_PPLOW(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_PPLOW_SHIFT)) & I3C_MCONFIG_PPLOW_MASK)

#define I3C_MCONFIG_ODBAUD_MASK                  (0xFF0000U)
#define I3C_MCONFIG_ODBAUD_SHIFT                 (16U)
/*! ODBAUD - Open-drain Baud Rate */
#define I3C_MCONFIG_ODBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODBAUD_SHIFT)) & I3C_MCONFIG_ODBAUD_MASK)

#define I3C_MCONFIG_ODHPP_MASK                   (0x1000000U)
#define I3C_MCONFIG_ODHPP_SHIFT                  (24U)
/*! ODHPP - Open-drain High Push-Pull
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MCONFIG_ODHPP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODHPP_SHIFT)) & I3C_MCONFIG_ODHPP_MASK)

#define I3C_MCONFIG_SKEW_MASK                    (0xE000000U)
#define I3C_MCONFIG_SKEW_SHIFT                   (25U)
/*! SKEW - Skew */
#define I3C_MCONFIG_SKEW(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_SKEW_SHIFT)) & I3C_MCONFIG_SKEW_MASK)

#define I3C_MCONFIG_I2CBAUD_MASK                 (0xF0000000U)
#define I3C_MCONFIG_I2CBAUD_SHIFT                (28U)
/*! I2CBAUD - I2C Baud Rate */
#define I3C_MCONFIG_I2CBAUD(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_I2CBAUD_SHIFT)) & I3C_MCONFIG_I2CBAUD_MASK)
/*! @} */

/*! @name SCONFIG - Target Configuration */
/*! @{ */

#define I3C_SCONFIG_SLVENA_MASK                  (0x1U)
#define I3C_SCONFIG_SLVENA_SHIFT                 (0U)
/*! SLVENA - Target Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SCONFIG_SLVENA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_SLVENA_SHIFT)) & I3C_SCONFIG_SLVENA_MASK)

#define I3C_SCONFIG_NACK_MASK                    (0x2U)
#define I3C_SCONFIG_NACK_SHIFT                   (1U)
/*! NACK - Not Acknowledge
 *  0b0..Always disable NACK mode
 *  0b1..Always enable NACK mode (works normally)
 */
#define I3C_SCONFIG_NACK(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_NACK_SHIFT)) & I3C_SCONFIG_NACK_MASK)

#define I3C_SCONFIG_MATCHSS_MASK                 (0x4U)
#define I3C_SCONFIG_MATCHSS_SHIFT                (2U)
/*! MATCHSS - Match Start or Stop
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SCONFIG_MATCHSS(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_MATCHSS_SHIFT)) & I3C_SCONFIG_MATCHSS_MASK)

#define I3C_SCONFIG_S0IGNORE_MASK                (0x8U)
#define I3C_SCONFIG_S0IGNORE_SHIFT               (3U)
/*! S0IGNORE - Ignore TE0 or TE1 Errors
 *  0b0..Do not ignore TE0 or TE1 errors
 *  0b1..Ignore TE0 or TE1 errors
 */
#define I3C_SCONFIG_S0IGNORE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_S0IGNORE_SHIFT)) & I3C_SCONFIG_S0IGNORE_MASK)

#define I3C_SCONFIG_DDROK_MASK                   (0x10U)
#define I3C_SCONFIG_DDROK_SHIFT                  (4U)
/*! DDROK - Double Data Rate OK
 *  0b0..Do not allow HDR-DDR messaging
 *  0b1..Allow HDR-DDR messaging
 */
#define I3C_SCONFIG_DDROK(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_DDROK_SHIFT)) & I3C_SCONFIG_DDROK_MASK)

#define I3C_SCONFIG_BTML_MASK                    (0x60U)
#define I3C_SCONFIG_BTML_SHIFT                   (5U)
/*! BTML - Bulk Transport Multi-Lane
 *  0b00..Single lane
 *  0b01..Single or dual lanes
 *  0b11..Single, dual, or quad lanes
 */
#define I3C_SCONFIG_BTML(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_BTML_SHIFT)) & I3C_SCONFIG_BTML_MASK)

#define I3C_SCONFIG_OFFLINE_MASK                 (0x200U)
#define I3C_SCONFIG_OFFLINE_SHIFT                (9U)
/*! OFFLINE - Offline
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SCONFIG_OFFLINE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_OFFLINE_SHIFT)) & I3C_SCONFIG_OFFLINE_MASK)

#define I3C_SCONFIG_BAMATCH_MASK                 (0x3F0000U)
#define I3C_SCONFIG_BAMATCH_SHIFT                (16U)
/*! BAMATCH - Bus Available Match */
#define I3C_SCONFIG_BAMATCH(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_BAMATCH_SHIFT)) & I3C_SCONFIG_BAMATCH_MASK)

#define I3C_SCONFIG_SADDR_MASK                   (0xFE000000U)
#define I3C_SCONFIG_SADDR_SHIFT                  (25U)
/*! SADDR - Static Address */
#define I3C_SCONFIG_SADDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_SADDR_SHIFT)) & I3C_SCONFIG_SADDR_MASK)
/*! @} */

/*! @name SSTATUS - Target Status */
/*! @{ */

#define I3C_SSTATUS_STNOTSTOP_MASK               (0x1U)
#define I3C_SSTATUS_STNOTSTOP_SHIFT              (0U)
/*! STNOTSTOP - Status not Stop
 *  0b0..In STOP condition
 *  0b1..Busy
 */
#define I3C_SSTATUS_STNOTSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STNOTSTOP_SHIFT)) & I3C_SSTATUS_STNOTSTOP_MASK)

#define I3C_SSTATUS_STMSG_MASK                   (0x2U)
#define I3C_SSTATUS_STMSG_SHIFT                  (1U)
/*! STMSG - Status Message
 *  0b0..Idle
 *  0b1..Busy
 */
#define I3C_SSTATUS_STMSG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STMSG_SHIFT)) & I3C_SSTATUS_STMSG_MASK)

#define I3C_SSTATUS_STCCCH_MASK                  (0x4U)
#define I3C_SSTATUS_STCCCH_SHIFT                 (2U)
/*! STCCCH - Status Common Command Code Handler
 *  0b0..No CCC message handled
 *  0b1..Handled automatically
 */
#define I3C_SSTATUS_STCCCH(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STCCCH_SHIFT)) & I3C_SSTATUS_STCCCH_MASK)

#define I3C_SSTATUS_STREQRD_MASK                 (0x8U)
#define I3C_SSTATUS_STREQRD_SHIFT                (3U)
/*! STREQRD - Status Request Read
 *  0b0..Not an SDR read
 *  0b1..SDR read from this target or an IBI is being pushed out
 */
#define I3C_SSTATUS_STREQRD(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STREQRD_SHIFT)) & I3C_SSTATUS_STREQRD_MASK)

#define I3C_SSTATUS_STREQWR_MASK                 (0x10U)
#define I3C_SSTATUS_STREQWR_SHIFT                (4U)
/*! STREQWR - Status Request Write
 *  0b0..Not an SDR write
 *  0b1..SDR write data from the controller, but not in ENTDAA mode
 */
#define I3C_SSTATUS_STREQWR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STREQWR_SHIFT)) & I3C_SSTATUS_STREQWR_MASK)

#define I3C_SSTATUS_STDAA_MASK                   (0x20U)
#define I3C_SSTATUS_STDAA_SHIFT                  (5U)
/*! STDAA - Status Dynamic Address Assignment
 *  0b0..Not in ENTDAA mode
 *  0b1..In ENTDAA mode
 */
#define I3C_SSTATUS_STDAA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STDAA_SHIFT)) & I3C_SSTATUS_STDAA_MASK)

#define I3C_SSTATUS_STHDR_MASK                   (0x40U)
#define I3C_SSTATUS_STHDR_SHIFT                  (6U)
/*! STHDR - Status High Data Rate
 *  0b0..I3C bus not in HDR-DDR mode
 *  0b1..I3C bus in HDR-DDR mode
 */
#define I3C_SSTATUS_STHDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STHDR_SHIFT)) & I3C_SSTATUS_STHDR_MASK)

#define I3C_SSTATUS_START_MASK                   (0x100U)
#define I3C_SSTATUS_START_SHIFT                  (8U)
/*! START - Start Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define I3C_SSTATUS_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_START_SHIFT)) & I3C_SSTATUS_START_MASK)

#define I3C_SSTATUS_MATCHED_MASK                 (0x200U)
#define I3C_SSTATUS_MATCHED_SHIFT                (9U)
/*! MATCHED - Matched Flag
 *  0b0..Header not matched
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Header matched
 */
#define I3C_SSTATUS_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_MATCHED_SHIFT)) & I3C_SSTATUS_MATCHED_MASK)

#define I3C_SSTATUS_STOP_MASK                    (0x400U)
#define I3C_SSTATUS_STOP_SHIFT                   (10U)
/*! STOP - Stop Flag
 *  0b0..No Stopped state detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Stopped state detected
 */
#define I3C_SSTATUS_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STOP_SHIFT)) & I3C_SSTATUS_STOP_MASK)

#define I3C_SSTATUS_RX_PEND_MASK                 (0x800U)
#define I3C_SSTATUS_RX_PEND_SHIFT                (11U)
/*! RX_PEND - Received Message Pending
 *  0b0..No received message pending
 *  0b1..Received message pending
 */
#define I3C_SSTATUS_RX_PEND(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_RX_PEND_SHIFT)) & I3C_SSTATUS_RX_PEND_MASK)

#define I3C_SSTATUS_TXNOTFULL_MASK               (0x1000U)
#define I3C_SSTATUS_TXNOTFULL_SHIFT              (12U)
/*! TXNOTFULL - Transmit Buffer Not Full
 *  0b0..Transmit buffer full
 *  0b1..Transmit buffer not full
 */
#define I3C_SSTATUS_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_TXNOTFULL_SHIFT)) & I3C_SSTATUS_TXNOTFULL_MASK)

#define I3C_SSTATUS_DACHG_MASK                   (0x2000U)
#define I3C_SSTATUS_DACHG_SHIFT                  (13U)
/*! DACHG - Dynamic Address Change Flag
 *  0b0..No DA change detected
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..DA change detected
 */
#define I3C_SSTATUS_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_DACHG_SHIFT)) & I3C_SSTATUS_DACHG_MASK)

#define I3C_SSTATUS_CCC_MASK                     (0x4000U)
#define I3C_SSTATUS_CCC_SHIFT                    (14U)
/*! CCC - Common Command Code Flag
 *  0b0..CCC not received
 *  0b0..No effect
 *  0b1..CCC received
 *  0b1..Clear the flag
 */
#define I3C_SSTATUS_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_CCC_SHIFT)) & I3C_SSTATUS_CCC_MASK)

#define I3C_SSTATUS_ERRWARN_MASK                 (0x8000U)
#define I3C_SSTATUS_ERRWARN_SHIFT                (15U)
/*! ERRWARN - Error Warning */
#define I3C_SSTATUS_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_ERRWARN_SHIFT)) & I3C_SSTATUS_ERRWARN_MASK)

#define I3C_SSTATUS_HDRMATCH_MASK                (0x10000U)
#define I3C_SSTATUS_HDRMATCH_SHIFT               (16U)
/*! HDRMATCH - High Data Rate Command Match Flag
 *  0b0..Did not match
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Matched the I3C dynamic address
 */
#define I3C_SSTATUS_HDRMATCH(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_HDRMATCH_SHIFT)) & I3C_SSTATUS_HDRMATCH_MASK)

#define I3C_SSTATUS_CHANDLED_MASK                (0x20000U)
#define I3C_SSTATUS_CHANDLED_SHIFT               (17U)
/*! CHANDLED - Common Command Code Handled Flag
 *  0b0..CCC handling not in progress
 *  0b0..No effect
 *  0b1..CCC handling in progress
 *  0b1..Clear the flag
 */
#define I3C_SSTATUS_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_CHANDLED_SHIFT)) & I3C_SSTATUS_CHANDLED_MASK)

#define I3C_SSTATUS_EVENT_MASK                   (0x40000U)
#define I3C_SSTATUS_EVENT_SHIFT                  (18U)
/*! EVENT - Event Flag
 *  0b0..No effect
 *  0b0..No event occurred
 *  0b1..Clear the flag
 *  0b1..IBI, CR, or HJ occurred
 */
#define I3C_SSTATUS_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_EVENT_SHIFT)) & I3C_SSTATUS_EVENT_MASK)

#define I3C_SSTATUS_EVDET_MASK                   (0x300000U)
#define I3C_SSTATUS_EVDET_SHIFT                  (20U)
/*! EVDET - Event Details
 *  0b00..NONE (no event or no pending event)
 *  0b01..NO_REQUEST (request is not sent yet; either there is no START condition yet, or is waiting for Bus-Available or Bus-Idle (HJ))
 *  0b10..NACKed (not acknowledged, request sent and rejected); I3C tries again
 *  0b11..ACKed (acknowledged; request sent and accepted), so done (unless the time control data is still being sent)
 */
#define I3C_SSTATUS_EVDET(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_EVDET_SHIFT)) & I3C_SSTATUS_EVDET_MASK)

#define I3C_SSTATUS_IBIDIS_MASK                  (0x1000000U)
#define I3C_SSTATUS_IBIDIS_SHIFT                 (24U)
/*! IBIDIS - In-Band Interrupts Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define I3C_SSTATUS_IBIDIS(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_IBIDIS_SHIFT)) & I3C_SSTATUS_IBIDIS_MASK)

#define I3C_SSTATUS_MRDIS_MASK                   (0x2000000U)
#define I3C_SSTATUS_MRDIS_SHIFT                  (25U)
/*! MRDIS - Controller Requests Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define I3C_SSTATUS_MRDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_MRDIS_SHIFT)) & I3C_SSTATUS_MRDIS_MASK)

#define I3C_SSTATUS_HJDIS_MASK                   (0x8000000U)
#define I3C_SSTATUS_HJDIS_SHIFT                  (27U)
/*! HJDIS - Hot-Join Disabled
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define I3C_SSTATUS_HJDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_HJDIS_SHIFT)) & I3C_SSTATUS_HJDIS_MASK)

#define I3C_SSTATUS_ACTSTATE_MASK                (0x30000000U)
#define I3C_SSTATUS_ACTSTATE_SHIFT               (28U)
/*! ACTSTATE - Activity State from Common Command Codes (CCC)
 *  0b00..NO_LATENCY (normal bus operations)
 *  0b01..LATENCY_1MS (1 ms of latency)
 *  0b10..LATENCY_100MS (100 ms of latency)
 *  0b11..LATENCY_10S (10 seconds of latency)
 */
#define I3C_SSTATUS_ACTSTATE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_ACTSTATE_SHIFT)) & I3C_SSTATUS_ACTSTATE_MASK)

#define I3C_SSTATUS_TIMECTRL_MASK                (0xC0000000U)
#define I3C_SSTATUS_TIMECTRL_SHIFT               (30U)
/*! TIMECTRL - Time Control
 *  0b00..NO_TIME_CONTROL (no time control is enabled)
 *  0b01..SYNC_MODE (Synchronous mode is enabled)
 *  0b10..ASYNC_MODE (Asynchronous standard mode (0 or 1) is enabled)
 *  0b11..BOTHSYNCASYNC (both Synchronous and Asynchronous modes are enabled)
 */
#define I3C_SSTATUS_TIMECTRL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_TIMECTRL_SHIFT)) & I3C_SSTATUS_TIMECTRL_MASK)
/*! @} */

/*! @name SCTRL - Target Control */
/*! @{ */

#define I3C_SCTRL_EVENT_MASK                     (0x3U)
#define I3C_SCTRL_EVENT_SHIFT                    (0U)
/*! EVENT - Event
 *  0b00..NORMAL_MODE
 *  0b01..IBI
 *  0b10..CONTROLLER_REQUEST
 *  0b11..HOT_JOIN_REQUEST
 */
#define I3C_SCTRL_EVENT(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_EVENT_SHIFT)) & I3C_SCTRL_EVENT_MASK)

#define I3C_SCTRL_EXTDATA_MASK                   (0x8U)
#define I3C_SCTRL_EXTDATA_SHIFT                  (3U)
/*! EXTDATA - Extended Data
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SCTRL_EXTDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_EXTDATA_SHIFT)) & I3C_SCTRL_EXTDATA_MASK)

#define I3C_SCTRL_MAPIDX_MASK                    (0x10U)
#define I3C_SCTRL_MAPIDX_SHIFT                   (4U)
/*! MAPIDX - Map Index */
#define I3C_SCTRL_MAPIDX(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_MAPIDX_SHIFT)) & I3C_SCTRL_MAPIDX_MASK)

#define I3C_SCTRL_IBIDATA_MASK                   (0xFF00U)
#define I3C_SCTRL_IBIDATA_SHIFT                  (8U)
/*! IBIDATA - In-Band Interrupt Data */
#define I3C_SCTRL_IBIDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_IBIDATA_SHIFT)) & I3C_SCTRL_IBIDATA_MASK)

#define I3C_SCTRL_PENDINT_MASK                   (0xF0000U)
#define I3C_SCTRL_PENDINT_SHIFT                  (16U)
/*! PENDINT - Pending Interrupt */
#define I3C_SCTRL_PENDINT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_PENDINT_SHIFT)) & I3C_SCTRL_PENDINT_MASK)

#define I3C_SCTRL_ACTSTATE_MASK                  (0x300000U)
#define I3C_SCTRL_ACTSTATE_SHIFT                 (20U)
/*! ACTSTATE - Activity State of Target */
#define I3C_SCTRL_ACTSTATE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_ACTSTATE_SHIFT)) & I3C_SCTRL_ACTSTATE_MASK)

#define I3C_SCTRL_VENDINFO_MASK                  (0xFF000000U)
#define I3C_SCTRL_VENDINFO_SHIFT                 (24U)
/*! VENDINFO - Vendor Information */
#define I3C_SCTRL_VENDINFO(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_VENDINFO_SHIFT)) & I3C_SCTRL_VENDINFO_MASK)
/*! @} */

/*! @name SINTSET - Target Interrupt Set */
/*! @{ */

#define I3C_SINTSET_START_MASK                   (0x100U)
#define I3C_SINTSET_START_SHIFT                  (8U)
/*! START - Start Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_START_SHIFT)) & I3C_SINTSET_START_MASK)

#define I3C_SINTSET_MATCHED_MASK                 (0x200U)
#define I3C_SINTSET_MATCHED_SHIFT                (9U)
/*! MATCHED - Match Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_MATCHED_SHIFT)) & I3C_SINTSET_MATCHED_MASK)

#define I3C_SINTSET_STOP_MASK                    (0x400U)
#define I3C_SINTSET_STOP_SHIFT                   (10U)
/*! STOP - Stop Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_STOP_SHIFT)) & I3C_SINTSET_STOP_MASK)

#define I3C_SINTSET_RXPEND_MASK                  (0x800U)
#define I3C_SINTSET_RXPEND_SHIFT                 (11U)
/*! RXPEND - Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_RXPEND_SHIFT)) & I3C_SINTSET_RXPEND_MASK)

#define I3C_SINTSET_TXSEND_MASK                  (0x1000U)
#define I3C_SINTSET_TXSEND_SHIFT                 (12U)
/*! TXSEND - Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_TXSEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_TXSEND_SHIFT)) & I3C_SINTSET_TXSEND_MASK)

#define I3C_SINTSET_DACHG_MASK                   (0x2000U)
#define I3C_SINTSET_DACHG_SHIFT                  (13U)
/*! DACHG - Dynamic Address Change Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_DACHG_SHIFT)) & I3C_SINTSET_DACHG_MASK)

#define I3C_SINTSET_CCC_MASK                     (0x4000U)
#define I3C_SINTSET_CCC_SHIFT                    (14U)
/*! CCC - Common Command Code (CCC) Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_CCC_SHIFT)) & I3C_SINTSET_CCC_MASK)

#define I3C_SINTSET_ERRWARN_MASK                 (0x8000U)
#define I3C_SINTSET_ERRWARN_SHIFT                (15U)
/*! ERRWARN - Error or Warning Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_ERRWARN_SHIFT)) & I3C_SINTSET_ERRWARN_MASK)

#define I3C_SINTSET_DDRMATCHED_MASK              (0x10000U)
#define I3C_SINTSET_DDRMATCHED_SHIFT             (16U)
/*! DDRMATCHED - Double Data Rate Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_DDRMATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_DDRMATCHED_SHIFT)) & I3C_SINTSET_DDRMATCHED_MASK)

#define I3C_SINTSET_CHANDLED_MASK                (0x20000U)
#define I3C_SINTSET_CHANDLED_SHIFT               (17U)
/*! CHANDLED - Common Command Code (CCC) Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_CHANDLED_SHIFT)) & I3C_SINTSET_CHANDLED_MASK)

#define I3C_SINTSET_EVENT_MASK                   (0x40000U)
#define I3C_SINTSET_EVENT_SHIFT                  (18U)
/*! EVENT - Event Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SINTSET_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_EVENT_SHIFT)) & I3C_SINTSET_EVENT_MASK)
/*! @} */

/*! @name SINTCLR - Target Interrupt Clear */
/*! @{ */

#define I3C_SINTCLR_START_MASK                   (0x100U)
#define I3C_SINTCLR_START_SHIFT                  (8U)
/*! START - START Interrupt Enable Clear Flag */
#define I3C_SINTCLR_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_START_SHIFT)) & I3C_SINTCLR_START_MASK)

#define I3C_SINTCLR_MATCHED_MASK                 (0x200U)
#define I3C_SINTCLR_MATCHED_SHIFT                (9U)
/*! MATCHED - Matched Interrupt Enable Clear Flag */
#define I3C_SINTCLR_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_MATCHED_SHIFT)) & I3C_SINTCLR_MATCHED_MASK)

#define I3C_SINTCLR_STOP_MASK                    (0x400U)
#define I3C_SINTCLR_STOP_SHIFT                   (10U)
/*! STOP - STOP Interrupt Enable Clear Flag */
#define I3C_SINTCLR_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_STOP_SHIFT)) & I3C_SINTCLR_STOP_MASK)

#define I3C_SINTCLR_RXPEND_MASK                  (0x800U)
#define I3C_SINTCLR_RXPEND_SHIFT                 (11U)
/*! RXPEND - RXPEND Interrupt Enable Clear Flag */
#define I3C_SINTCLR_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_RXPEND_SHIFT)) & I3C_SINTCLR_RXPEND_MASK)

#define I3C_SINTCLR_TXSEND_MASK                  (0x1000U)
#define I3C_SINTCLR_TXSEND_SHIFT                 (12U)
/*! TXSEND - TXSEND Interrupt Enable Clear Flag */
#define I3C_SINTCLR_TXSEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_TXSEND_SHIFT)) & I3C_SINTCLR_TXSEND_MASK)

#define I3C_SINTCLR_DACHG_MASK                   (0x2000U)
#define I3C_SINTCLR_DACHG_SHIFT                  (13U)
/*! DACHG - DACHG Interrupt Enable Clear Flag */
#define I3C_SINTCLR_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_DACHG_SHIFT)) & I3C_SINTCLR_DACHG_MASK)

#define I3C_SINTCLR_CCC_MASK                     (0x4000U)
#define I3C_SINTCLR_CCC_SHIFT                    (14U)
/*! CCC - CCC Interrupt Enable Clear Flag */
#define I3C_SINTCLR_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_CCC_SHIFT)) & I3C_SINTCLR_CCC_MASK)

#define I3C_SINTCLR_ERRWARN_MASK                 (0x8000U)
#define I3C_SINTCLR_ERRWARN_SHIFT                (15U)
/*! ERRWARN - ERRWARN Interrupt Enable Clear Flag */
#define I3C_SINTCLR_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_ERRWARN_SHIFT)) & I3C_SINTCLR_ERRWARN_MASK)

#define I3C_SINTCLR_DDRMATCHED_MASK              (0x10000U)
#define I3C_SINTCLR_DDRMATCHED_SHIFT             (16U)
/*! DDRMATCHED - DDRMATCHED Interrupt Enable Clear Flag */
#define I3C_SINTCLR_DDRMATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_DDRMATCHED_SHIFT)) & I3C_SINTCLR_DDRMATCHED_MASK)

#define I3C_SINTCLR_CHANDLED_MASK                (0x20000U)
#define I3C_SINTCLR_CHANDLED_SHIFT               (17U)
/*! CHANDLED - CHANDLED Interrupt Enable Clear Flag */
#define I3C_SINTCLR_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_CHANDLED_SHIFT)) & I3C_SINTCLR_CHANDLED_MASK)

#define I3C_SINTCLR_EVENT_MASK                   (0x40000U)
#define I3C_SINTCLR_EVENT_SHIFT                  (18U)
/*! EVENT - EVENT Interrupt Enable Clear Flag */
#define I3C_SINTCLR_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_EVENT_SHIFT)) & I3C_SINTCLR_EVENT_MASK)
/*! @} */

/*! @name SINTMASKED - Target Interrupt Mask */
/*! @{ */

#define I3C_SINTMASKED_START_MASK                (0x100U)
#define I3C_SINTMASKED_START_SHIFT               (8U)
/*! START - START Interrupt Mask */
#define I3C_SINTMASKED_START(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_START_SHIFT)) & I3C_SINTMASKED_START_MASK)

#define I3C_SINTMASKED_MATCHED_MASK              (0x200U)
#define I3C_SINTMASKED_MATCHED_SHIFT             (9U)
/*! MATCHED - MATCHED Interrupt Mask */
#define I3C_SINTMASKED_MATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_MATCHED_SHIFT)) & I3C_SINTMASKED_MATCHED_MASK)

#define I3C_SINTMASKED_STOP_MASK                 (0x400U)
#define I3C_SINTMASKED_STOP_SHIFT                (10U)
/*! STOP - STOP Interrupt Mask */
#define I3C_SINTMASKED_STOP(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_STOP_SHIFT)) & I3C_SINTMASKED_STOP_MASK)

#define I3C_SINTMASKED_RXPEND_MASK               (0x800U)
#define I3C_SINTMASKED_RXPEND_SHIFT              (11U)
/*! RXPEND - RXPEND Interrupt Mask */
#define I3C_SINTMASKED_RXPEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_RXPEND_SHIFT)) & I3C_SINTMASKED_RXPEND_MASK)

#define I3C_SINTMASKED_TXSEND_MASK               (0x1000U)
#define I3C_SINTMASKED_TXSEND_SHIFT              (12U)
/*! TXSEND - TXSEND Interrupt Mask */
#define I3C_SINTMASKED_TXSEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_TXSEND_SHIFT)) & I3C_SINTMASKED_TXSEND_MASK)

#define I3C_SINTMASKED_DACHG_MASK                (0x2000U)
#define I3C_SINTMASKED_DACHG_SHIFT               (13U)
/*! DACHG - DACHG Interrupt Mask */
#define I3C_SINTMASKED_DACHG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_DACHG_SHIFT)) & I3C_SINTMASKED_DACHG_MASK)

#define I3C_SINTMASKED_CCC_MASK                  (0x4000U)
#define I3C_SINTMASKED_CCC_SHIFT                 (14U)
/*! CCC - CCC Interrupt Mask */
#define I3C_SINTMASKED_CCC(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_CCC_SHIFT)) & I3C_SINTMASKED_CCC_MASK)

#define I3C_SINTMASKED_ERRWARN_MASK              (0x8000U)
#define I3C_SINTMASKED_ERRWARN_SHIFT             (15U)
/*! ERRWARN - ERRWARN Interrupt Mask */
#define I3C_SINTMASKED_ERRWARN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_ERRWARN_SHIFT)) & I3C_SINTMASKED_ERRWARN_MASK)

#define I3C_SINTMASKED_DDRMATCHED_MASK           (0x10000U)
#define I3C_SINTMASKED_DDRMATCHED_SHIFT          (16U)
/*! DDRMATCHED - DDRMATCHED Interrupt Mask */
#define I3C_SINTMASKED_DDRMATCHED(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_DDRMATCHED_SHIFT)) & I3C_SINTMASKED_DDRMATCHED_MASK)

#define I3C_SINTMASKED_CHANDLED_MASK             (0x20000U)
#define I3C_SINTMASKED_CHANDLED_SHIFT            (17U)
/*! CHANDLED - CHANDLED Interrupt Mask */
#define I3C_SINTMASKED_CHANDLED(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_CHANDLED_SHIFT)) & I3C_SINTMASKED_CHANDLED_MASK)

#define I3C_SINTMASKED_EVENT_MASK                (0x40000U)
#define I3C_SINTMASKED_EVENT_SHIFT               (18U)
/*! EVENT - EVENT Interrupt Mask */
#define I3C_SINTMASKED_EVENT(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_EVENT_SHIFT)) & I3C_SINTMASKED_EVENT_MASK)
/*! @} */

/*! @name SERRWARN - Target Errors and Warnings */
/*! @{ */

#define I3C_SERRWARN_ORUN_MASK                   (0x1U)
#define I3C_SERRWARN_ORUN_SHIFT                  (0U)
/*! ORUN - Overrun Error Flag
 *  0b0..No effect
 *  0b0..No overrun error
 *  0b1..Clear the flag
 *  0b1..Overrun error
 */
#define I3C_SERRWARN_ORUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_ORUN_SHIFT)) & I3C_SERRWARN_ORUN_MASK)

#define I3C_SERRWARN_URUN_MASK                   (0x2U)
#define I3C_SERRWARN_URUN_SHIFT                  (1U)
/*! URUN - Underrun Error Flag
 *  0b0..No effect
 *  0b0..No underrun error
 *  0b1..Clear the flag
 *  0b1..Underrun error
 */
#define I3C_SERRWARN_URUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_URUN_SHIFT)) & I3C_SERRWARN_URUN_MASK)

#define I3C_SERRWARN_URUNNACK_MASK               (0x4U)
#define I3C_SERRWARN_URUNNACK_SHIFT              (2U)
/*! URUNNACK - Underrun and Not Acknowledged (NACKed) Error Flag
 *  0b0..No effect
 *  0b0..No underrun; not acknowledged error
 *  0b1..Clear the flag
 *  0b1..Underrun; not acknowledged error
 */
#define I3C_SERRWARN_URUNNACK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_URUNNACK_SHIFT)) & I3C_SERRWARN_URUNNACK_MASK)

#define I3C_SERRWARN_TERM_MASK                   (0x8U)
#define I3C_SERRWARN_TERM_SHIFT                  (3U)
/*! TERM - Terminated Error Flag
 *  0b0..No effect
 *  0b0..No terminated error
 *  0b1..Clear the flag
 *  0b1..Terminated error
 */
#define I3C_SERRWARN_TERM(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_TERM_SHIFT)) & I3C_SERRWARN_TERM_MASK)

#define I3C_SERRWARN_INVSTART_MASK               (0x10U)
#define I3C_SERRWARN_INVSTART_SHIFT              (4U)
/*! INVSTART - Invalid Start Error Flag
 *  0b0..No effect
 *  0b0..No invalid start error
 *  0b1..Clear the flag
 *  0b1..Invalid start error
 */
#define I3C_SERRWARN_INVSTART(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_INVSTART_SHIFT)) & I3C_SERRWARN_INVSTART_MASK)

#define I3C_SERRWARN_SPAR_MASK                   (0x100U)
#define I3C_SERRWARN_SPAR_SHIFT                  (8U)
/*! SPAR - SDR Parity Error Flag
 *  0b0..No SDR parity error
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..SDR parity error
 */
#define I3C_SERRWARN_SPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_SPAR_SHIFT)) & I3C_SERRWARN_SPAR_MASK)

#define I3C_SERRWARN_HPAR_MASK                   (0x200U)
#define I3C_SERRWARN_HPAR_SHIFT                  (9U)
/*! HPAR - HDR Parity Error Flag
 *  0b0..No HDR parity error
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..HDR parity error
 */
#define I3C_SERRWARN_HPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HPAR_SHIFT)) & I3C_SERRWARN_HPAR_MASK)

#define I3C_SERRWARN_HCRC_MASK                   (0x400U)
#define I3C_SERRWARN_HCRC_SHIFT                  (10U)
/*! HCRC - HDR-DDR CRC Error Flag
 *  0b0..No HDR-DDR CRC error occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..HDR-DDR CRC error occurred
 */
#define I3C_SERRWARN_HCRC(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HCRC_SHIFT)) & I3C_SERRWARN_HCRC_MASK)

#define I3C_SERRWARN_S0S1_MASK                   (0x800U)
#define I3C_SERRWARN_S0S1_SHIFT                  (11U)
/*! S0S1 - TE0 or TE1 Error Flag
 *  0b0..No TE0 or TE1 error occurred
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..TE0 or TE1 error occurred
 */
#define I3C_SERRWARN_S0S1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_S0S1_SHIFT)) & I3C_SERRWARN_S0S1_MASK)

#define I3C_SERRWARN_HNOVERIFY_MASK              (0x1000U)
#define I3C_SERRWARN_HNOVERIFY_SHIFT             (12U)
/*! HNOVERIFY - HDR-BT Not Verified Flag
 *  0b0..No HDR-BT not verified error
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..HDR-BT not verified error
 */
#define I3C_SERRWARN_HNOVERIFY(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HNOVERIFY_SHIFT)) & I3C_SERRWARN_HNOVERIFY_MASK)

#define I3C_SERRWARN_OREAD_MASK                  (0x10000U)
#define I3C_SERRWARN_OREAD_SHIFT                 (16U)
/*! OREAD - Over-Read Error Flag
 *  0b0..No effect
 *  0b0..No over-read error
 *  0b1..Clear the flag
 *  0b1..Over-read error
 */
#define I3C_SERRWARN_OREAD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_OREAD_SHIFT)) & I3C_SERRWARN_OREAD_MASK)

#define I3C_SERRWARN_OWRITE_MASK                 (0x20000U)
#define I3C_SERRWARN_OWRITE_SHIFT                (17U)
/*! OWRITE - Over-Write Error Flag
 *  0b0..No effect
 *  0b0..No overwrite error
 *  0b1..Clear the flag
 *  0b1..Overwrite error
 */
#define I3C_SERRWARN_OWRITE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_OWRITE_SHIFT)) & I3C_SERRWARN_OWRITE_MASK)

#define I3C_SERRWARN_WRONGSIZE_MASK              (0x200000U)
#define I3C_SERRWARN_WRONGSIZE_SHIFT             (21U)
/*! WRONGSIZE - Wrong Size Flag
 *  0b0..No effect
 *  0b0..No wrong-size error
 *  0b1..Clear the flag
 *  0b1..Wrong-size error
 */
#define I3C_SERRWARN_WRONGSIZE(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_WRONGSIZE_SHIFT)) & I3C_SERRWARN_WRONGSIZE_MASK)
/*! @} */

/*! @name SDMACTRL - Target DMA Control */
/*! @{ */

#define I3C_SDMACTRL_DMAFB_MASK                  (0x3U)
#define I3C_SDMACTRL_DMAFB_SHIFT                 (0U)
/*! DMAFB - DMA Read (From-Bus) Trigger
 *  0b00..DMA not used
 *  0b01..DMA enabled for one frame
 *  0b10..DMA enabled until turned off
 *  0b11..
 */
#define I3C_SDMACTRL_DMAFB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMAFB_SHIFT)) & I3C_SDMACTRL_DMAFB_MASK)

#define I3C_SDMACTRL_DMATB_MASK                  (0xCU)
#define I3C_SDMACTRL_DMATB_SHIFT                 (2U)
/*! DMATB - DMA Write (To-Bus) Trigger
 *  0b00..DMA not used
 *  0b01..DMA enabled for one frame
 *  0b10..DMA enabled until turned off
 *  0b11..
 */
#define I3C_SDMACTRL_DMATB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMATB_SHIFT)) & I3C_SDMACTRL_DMATB_MASK)

#define I3C_SDMACTRL_DMAWIDTH_MASK               (0x30U)
#define I3C_SDMACTRL_DMAWIDTH_SHIFT              (4U)
/*! DMAWIDTH - Width of DMA Operations
 *  0b00, 0b01..Byte
 *  0b10..Halfword (16 bits) (this value ensures that two bytes are available in the FIFO)
 *  0b11..
 */
#define I3C_SDMACTRL_DMAWIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMAWIDTH_SHIFT)) & I3C_SDMACTRL_DMAWIDTH_MASK)
/*! @} */

/*! @name SHDRBTCFG - Target HDR-BT Configuration */
/*! @{ */

#define I3C_SHDRBTCFG_CRC32_MASK                 (0x4U)
#define I3C_SHDRBTCFG_CRC32_SHIFT                (2U)
/*! CRC32 - CRC32 Select
 *  0b0..CRC16
 *  0b1..CRC32
 */
#define I3C_SHDRBTCFG_CRC32(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_CRC32_SHIFT)) & I3C_SHDRBTCFG_CRC32_MASK)

#define I3C_SHDRBTCFG_WDATAMAX_MASK              (0xFFF0U)
#define I3C_SHDRBTCFG_WDATAMAX_SHIFT             (4U)
/*! WDATAMAX - Maximum Data */
#define I3C_SHDRBTCFG_WDATAMAX(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_WDATAMAX_SHIFT)) & I3C_SHDRBTCFG_WDATAMAX_MASK)

#define I3C_SHDRBTCFG_DATALEN_MASK               (0xFFFF0000U)
#define I3C_SHDRBTCFG_DATALEN_SHIFT              (16U)
/*! DATALEN - Read Data Length */
#define I3C_SHDRBTCFG_DATALEN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_DATALEN_SHIFT)) & I3C_SHDRBTCFG_DATALEN_MASK)
/*! @} */

/*! @name SHDRBTLAST - Target HDR-Last */
/*! @{ */

#define I3C_SHDRBTLAST_DATALEN_MASK              (0xFFFF0000U)
#define I3C_SHDRBTLAST_DATALEN_SHIFT             (16U)
/*! DATALEN - Data Length */
#define I3C_SHDRBTLAST_DATALEN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTLAST_DATALEN_SHIFT)) & I3C_SHDRBTLAST_DATALEN_MASK)
/*! @} */

/*! @name SDATACTRL - Target Data Control */
/*! @{ */

#define I3C_SDATACTRL_FLUSHTB_MASK               (0x1U)
#define I3C_SDATACTRL_FLUSHTB_SHIFT              (0U)
/*! FLUSHTB - Flush To-Bus Buffer or FIFO
 *  0b0..No action
 *  0b1..Flush the buffer
 */
#define I3C_SDATACTRL_FLUSHTB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_FLUSHTB_SHIFT)) & I3C_SDATACTRL_FLUSHTB_MASK)

#define I3C_SDATACTRL_FLUSHFB_MASK               (0x2U)
#define I3C_SDATACTRL_FLUSHFB_SHIFT              (1U)
/*! FLUSHFB - Flush From-Bus Buffer or FIFO
 *  0b0..No action
 *  0b1..Flush the buffer
 */
#define I3C_SDATACTRL_FLUSHFB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_FLUSHFB_SHIFT)) & I3C_SDATACTRL_FLUSHFB_MASK)

#define I3C_SDATACTRL_UNLOCK_MASK                (0x8U)
#define I3C_SDATACTRL_UNLOCK_SHIFT               (3U)
/*! UNLOCK - Unlock
 *  0b0..Cannot be changed
 *  0b1..Can be changed
 */
#define I3C_SDATACTRL_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_UNLOCK_SHIFT)) & I3C_SDATACTRL_UNLOCK_MASK)

#define I3C_SDATACTRL_TXTRIG_MASK                (0x30U)
#define I3C_SDATACTRL_TXTRIG_SHIFT               (4U)
/*! TXTRIG - Transmit Trigger Level
 *  0b00..Trigger when empty
 *  0b01..Trigger when 1/4 full or less
 *  0b10..Trigger when 1/2 full or less
 *  0b11..Default (trigger when 1 less than full or less)
 */
#define I3C_SDATACTRL_TXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXTRIG_SHIFT)) & I3C_SDATACTRL_TXTRIG_MASK)

#define I3C_SDATACTRL_RXTRIG_MASK                (0xC0U)
#define I3C_SDATACTRL_RXTRIG_SHIFT               (6U)
/*! RXTRIG - Receive Trigger Level
 *  0b00..Trigger when not empty (default)
 *  0b01..Trigger when 1/4 or more full
 *  0b10..Trigger when 1/2 or more full
 *  0b11..Trigger when 3/4 or more full
 */
#define I3C_SDATACTRL_RXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXTRIG_SHIFT)) & I3C_SDATACTRL_RXTRIG_MASK)

#define I3C_SDATACTRL_TXCOUNT_MASK               (0x1F0000U)
#define I3C_SDATACTRL_TXCOUNT_SHIFT              (16U)
/*! TXCOUNT - Count of Entries in Transmit */
#define I3C_SDATACTRL_TXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXCOUNT_SHIFT)) & I3C_SDATACTRL_TXCOUNT_MASK)

#define I3C_SDATACTRL_RXCOUNT_MASK               (0x1F000000U)
#define I3C_SDATACTRL_RXCOUNT_SHIFT              (24U)
/*! RXCOUNT - Count of Entries in Receive */
#define I3C_SDATACTRL_RXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXCOUNT_SHIFT)) & I3C_SDATACTRL_RXCOUNT_MASK)

#define I3C_SDATACTRL_TXFULL_MASK                (0x40000000U)
#define I3C_SDATACTRL_TXFULL_SHIFT               (30U)
/*! TXFULL - Transmit is Full
 *  0b0..Not full
 *  0b1..Full
 */
#define I3C_SDATACTRL_TXFULL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXFULL_SHIFT)) & I3C_SDATACTRL_TXFULL_MASK)

#define I3C_SDATACTRL_RXEMPTY_MASK               (0x80000000U)
#define I3C_SDATACTRL_RXEMPTY_SHIFT              (31U)
/*! RXEMPTY - Receive is Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define I3C_SDATACTRL_RXEMPTY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXEMPTY_SHIFT)) & I3C_SDATACTRL_RXEMPTY_MASK)
/*! @} */

/*! @name SWDATAB - Target Write Data Byte */
/*! @{ */

#define I3C_SWDATAB_DATA_MASK                    (0xFFU)
#define I3C_SWDATAB_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define I3C_SWDATAB_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_DATA_SHIFT)) & I3C_SWDATAB_DATA_MASK)

#define I3C_SWDATAB_END_MASK                     (0x100U)
#define I3C_SWDATAB_END_SHIFT                    (8U)
/*! END - End
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_SWDATAB_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_END_SHIFT)) & I3C_SWDATAB_END_MASK)

#define I3C_SWDATAB_END_ALSO_MASK                (0x10000U)
#define I3C_SWDATAB_END_ALSO_SHIFT               (16U)
/*! END_ALSO - End Also
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_SWDATAB_END_ALSO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_END_ALSO_SHIFT)) & I3C_SWDATAB_END_ALSO_MASK)
/*! @} */

/*! @name SWDATABE - Target Write Data Byte End */
/*! @{ */

#define I3C_SWDATABE_DATA_MASK                   (0xFFU)
#define I3C_SWDATABE_DATA_SHIFT                  (0U)
/*! DATA - Data */
#define I3C_SWDATABE_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATABE_DATA_SHIFT)) & I3C_SWDATABE_DATA_MASK)
/*! @} */

/*! @name SWDATAH - Target Write Data Halfword */
/*! @{ */

#define I3C_SWDATAH_DATA0_MASK                   (0xFFU)
#define I3C_SWDATAH_DATA0_SHIFT                  (0U)
/*! DATA0 - Data 0 */
#define I3C_SWDATAH_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_DATA0_SHIFT)) & I3C_SWDATAH_DATA0_MASK)

#define I3C_SWDATAH_DATA1_MASK                   (0xFF00U)
#define I3C_SWDATAH_DATA1_SHIFT                  (8U)
/*! DATA1 - Data 1 */
#define I3C_SWDATAH_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_DATA1_SHIFT)) & I3C_SWDATAH_DATA1_MASK)

#define I3C_SWDATAH_END_MASK                     (0x10000U)
#define I3C_SWDATAH_END_SHIFT                    (16U)
/*! END - End of Message
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_SWDATAH_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_END_SHIFT)) & I3C_SWDATAH_END_MASK)
/*! @} */

/*! @name SWDATAHE - Target Write Data Halfword End */
/*! @{ */

#define I3C_SWDATAHE_DATA0_MASK                  (0xFFU)
#define I3C_SWDATAHE_DATA0_SHIFT                 (0U)
/*! DATA0 - Data 0 */
#define I3C_SWDATAHE_DATA0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAHE_DATA0_SHIFT)) & I3C_SWDATAHE_DATA0_MASK)

#define I3C_SWDATAHE_DATA1_MASK                  (0xFF00U)
#define I3C_SWDATAHE_DATA1_SHIFT                 (8U)
/*! DATA1 - Data 1 */
#define I3C_SWDATAHE_DATA1(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAHE_DATA1_SHIFT)) & I3C_SWDATAHE_DATA1_MASK)
/*! @} */

/*! @name SRDATAB - Target Read Data Byte */
/*! @{ */

#define I3C_SRDATAB_DATA0_MASK                   (0xFFU)
#define I3C_SRDATAB_DATA0_SHIFT                  (0U)
/*! DATA0 - Data 0 */
#define I3C_SRDATAB_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAB_DATA0_SHIFT)) & I3C_SRDATAB_DATA0_MASK)
/*! @} */

/*! @name SRDATAH - Target Read Data Halfword */
/*! @{ */

#define I3C_SRDATAH_LSB_MASK                     (0xFFU)
#define I3C_SRDATAH_LSB_SHIFT                    (0U)
/*! LSB - Low Byte */
#define I3C_SRDATAH_LSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAH_LSB_SHIFT)) & I3C_SRDATAH_LSB_MASK)

#define I3C_SRDATAH_MSB_MASK                     (0xFF00U)
#define I3C_SRDATAH_MSB_SHIFT                    (8U)
/*! MSB - High Byte */
#define I3C_SRDATAH_MSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAH_MSB_SHIFT)) & I3C_SRDATAH_MSB_MASK)
/*! @} */

/*! @name SWDATAB1 - Target Write Data Byte */
/*! @{ */

#define I3C_SWDATAB1_DATA_MASK                   (0xFFU)
#define I3C_SWDATAB1_DATA_SHIFT                  (0U)
/*! DATA - Data */
#define I3C_SWDATAB1_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB1_DATA_SHIFT)) & I3C_SWDATAB1_DATA_MASK)
/*! @} */

/*! @name SCAPABILITIES2 - Target Capabilities 2 */
/*! @{ */

#define I3C_SCAPABILITIES2_MAPCNT_MASK           (0xFU)
#define I3C_SCAPABILITIES2_MAPCNT_SHIFT          (0U)
/*! MAPCNT - Map Count */
#define I3C_SCAPABILITIES2_MAPCNT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_MAPCNT_SHIFT)) & I3C_SCAPABILITIES2_MAPCNT_MASK)

#define I3C_SCAPABILITIES2_I2C10B_MASK           (0x10U)
#define I3C_SCAPABILITIES2_I2C10B_SHIFT          (4U)
/*! I2C10B - I2C 10-bit Address
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_I2C10B(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_I2C10B_SHIFT)) & I3C_SCAPABILITIES2_I2C10B_MASK)

#define I3C_SCAPABILITIES2_I2CDEVID_MASK         (0x40U)
#define I3C_SCAPABILITIES2_I2CDEVID_SHIFT        (6U)
/*! I2CDEVID - I2C Device ID
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_I2CDEVID(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_I2CDEVID_SHIFT)) & I3C_SCAPABILITIES2_I2CDEVID_MASK)

#define I3C_SCAPABILITIES2_DATA32_MASK           (0x80U)
#define I3C_SCAPABILITIES2_DATA32_SHIFT          (7U)
/*! DATA32 - Data 32
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_DATA32(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_DATA32_SHIFT)) & I3C_SCAPABILITIES2_DATA32_MASK)

#define I3C_SCAPABILITIES2_IBIEXT_MASK           (0x100U)
#define I3C_SCAPABILITIES2_IBIEXT_SHIFT          (8U)
/*! IBIEXT - In-Band Interrupt EXTDATA
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_IBIEXT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_IBIEXT_SHIFT)) & I3C_SCAPABILITIES2_IBIEXT_MASK)

#define I3C_SCAPABILITIES2_IBIXREG_MASK          (0x200U)
#define I3C_SCAPABILITIES2_IBIXREG_SHIFT         (9U)
/*! IBIXREG - In-Band Interrupt Extended Register
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_IBIXREG(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_IBIXREG_SHIFT)) & I3C_SCAPABILITIES2_IBIXREG_MASK)

#define I3C_SCAPABILITIES2_SMLANE_MASK           (0x3000U)
#define I3C_SCAPABILITIES2_SMLANE_SHIFT          (12U)
/*! SMLANE - Select Multi-Lane
 *  0b00..Single lane only
 *  0b01..Dual lane capable (single and dual)
 *  0b10..
 *  0b11..Quad lane capable (single, dual, quad)
 */
#define I3C_SCAPABILITIES2_SMLANE(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SMLANE_SHIFT)) & I3C_SCAPABILITIES2_SMLANE_MASK)

#define I3C_SCAPABILITIES2_V1_1_MASK             (0x10000U)
#define I3C_SCAPABILITIES2_V1_1_SHIFT            (16U)
/*! V1_1 - Version 1.1
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_V1_1(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_V1_1_SHIFT)) & I3C_SCAPABILITIES2_V1_1_MASK)

#define I3C_SCAPABILITIES2_SLVRST_MASK           (0x20000U)
#define I3C_SCAPABILITIES2_SLVRST_SHIFT          (17U)
/*! SLVRST - Target Reset
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES2_SLVRST(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SLVRST_SHIFT)) & I3C_SCAPABILITIES2_SLVRST_MASK)

#define I3C_SCAPABILITIES2_GROUP_MASK            (0xC0000U)
#define I3C_SCAPABILITIES2_GROUP_SHIFT           (18U)
/*! GROUP - Group
 *  0b00..v1.1 group addressing not supported
 *  0b01..One group supported
 *  0b10..Two groups supported
 *  0b11..Three groups supported
 */
#define I3C_SCAPABILITIES2_GROUP(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_GROUP_SHIFT)) & I3C_SCAPABILITIES2_GROUP_MASK)

#define I3C_SCAPABILITIES2_AASA_MASK             (0x200000U)
#define I3C_SCAPABILITIES2_AASA_SHIFT            (21U)
/*! AASA - SETAASA
 *  0b0..SETAASA not supported
 *  0b1..SETAASA supported
 */
#define I3C_SCAPABILITIES2_AASA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_AASA_SHIFT)) & I3C_SCAPABILITIES2_AASA_MASK)

#define I3C_SCAPABILITIES2_SSTSUB_MASK           (0x400000U)
#define I3C_SCAPABILITIES2_SSTSUB_SHIFT          (22U)
/*! SSTSUB - Target-Target(s)-Tunnel Subscriber Capable
 *  0b0..Not subscriber capable
 *  0b1..Subscriber capable
 */
#define I3C_SCAPABILITIES2_SSTSUB(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SSTSUB_SHIFT)) & I3C_SCAPABILITIES2_SSTSUB_MASK)

#define I3C_SCAPABILITIES2_SSTWR_MASK            (0x800000U)
#define I3C_SCAPABILITIES2_SSTWR_SHIFT           (23U)
/*! SSTWR - Target-Target(s)-Tunnel Write Capable
 *  0b0..Not write capable
 *  0b1..Write capable
 */
#define I3C_SCAPABILITIES2_SSTWR(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SSTWR_SHIFT)) & I3C_SCAPABILITIES2_SSTWR_MASK)
/*! @} */

/*! @name SCAPABILITIES - Target Capabilities */
/*! @{ */

#define I3C_SCAPABILITIES_IDENA_MASK             (0x3U)
#define I3C_SCAPABILITIES_IDENA_SHIFT            (0U)
/*! IDENA - ID 48b Handler
 *  0b00..Application
 *  0b01..Hardware
 *  0b10..Hardware, but the I3C module instance handles ID 48b
 *  0b11..A part number register (PARTNO)
 */
#define I3C_SCAPABILITIES_IDENA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IDENA_SHIFT)) & I3C_SCAPABILITIES_IDENA_MASK)

#define I3C_SCAPABILITIES_IDREG_MASK             (0x3CU)
#define I3C_SCAPABILITIES_IDREG_SHIFT            (2U)
/*! IDREG - ID Register
 *  0b0000..All ID register features disabled
 *  0b1xxx..A Bus Characteristics Register (BCR) is available
 *  0bx1xx..A Device Characteristic Register (DCR) is available
 *  0bxx1x..An ID Random field is available
 *  0bxxx1..ID Instance is a register; used if there is no PARTNO register
 */
#define I3C_SCAPABILITIES_IDREG(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IDREG_SHIFT)) & I3C_SCAPABILITIES_IDREG_MASK)

#define I3C_SCAPABILITIES_HDRSUPP_MASK           (0x1C0U)  /* Merged from fields with different position or width, of widths (2, 3), largest definition used */
#define I3C_SCAPABILITIES_HDRSUPP_SHIFT          (6U)
/*! HDRSUPP - High Data Rate Support
 *  0b00..No HDR modes supported
 *  0b01..DDR mode supported
 */
#define I3C_SCAPABILITIES_HDRSUPP(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_HDRSUPP_SHIFT)) & I3C_SCAPABILITIES_HDRSUPP_MASK)  /* Merged from fields with different position or width, of widths (2, 3), largest definition used */

#define I3C_SCAPABILITIES_MASTER_MASK            (0x200U)
#define I3C_SCAPABILITIES_MASTER_SHIFT           (9U)
/*! MASTER - Controller
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES_MASTER(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_MASTER_SHIFT)) & I3C_SCAPABILITIES_MASTER_MASK)

#define I3C_SCAPABILITIES_SADDR_MASK             (0xC00U)
#define I3C_SCAPABILITIES_SADDR_SHIFT            (10U)
/*! SADDR - Static Address
 *  0b00..No static address
 *  0b01..Static address is fixed in hardware
 *  0b10..Hardware controls the static address dynamically (for example, from the pin strap)
 *  0b11..SCONFIG register supplies the static address
 */
#define I3C_SCAPABILITIES_SADDR(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_SADDR_SHIFT)) & I3C_SCAPABILITIES_SADDR_MASK)

#define I3C_SCAPABILITIES_CCCHANDLE_MASK         (0xF000U)
#define I3C_SCAPABILITIES_CCCHANDLE_SHIFT        (12U)
/*! CCCHANDLE - Common Command Codes Handling
 *  0b0000..All handling features disabled
 *  0b1xxx..GETSTATUS CCC returns the value of SCTRL[VENDINFO]
 *  0bx1xx..GETSTATUS CCC returns the values of SCTRL[PENDINT] and SCTRL[ACTSTATE]
 *  0bxx1x..The I3C module manages maximum read and write lengths, and max data speed
 *  0bxxx1..The I3C module manages events, activities, status, HDR, and if enabled for it, ID and static-address-related items
 */
#define I3C_SCAPABILITIES_CCCHANDLE(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_CCCHANDLE_SHIFT)) & I3C_SCAPABILITIES_CCCHANDLE_MASK)

#define I3C_SCAPABILITIES_IBI_MR_HJ_MASK         (0x1F0000U)
#define I3C_SCAPABILITIES_IBI_MR_HJ_SHIFT        (16U)
/*! IBI_MR_HJ - In-Band Interrupts, Controller Requests, Hot-Join Events
 *  0b00000..Application cannot generate IBI, CR, or HJ
 *  0b1xxxx..Application can use SCONFIG[BAMATCH] for bus-available timing
 *  0bx1xxx..Application can generate a Hot-Join event
 *  0bxx1xx..Application can generate a controller request for a secondary controller
 *  0bxxx1x..When bit 0 = 1, the IBI has data from the SCTRL register
 *  0bxxxx1..Application can generate an IBI
 */
#define I3C_SCAPABILITIES_IBI_MR_HJ(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IBI_MR_HJ_SHIFT)) & I3C_SCAPABILITIES_IBI_MR_HJ_MASK)

#define I3C_SCAPABILITIES_TIMECTRL_MASK          (0x200000U)
#define I3C_SCAPABILITIES_TIMECTRL_SHIFT         (21U)
/*! TIMECTRL - Time Control
 *  0b0..No time control supported
 *  0b1..At least one time-control type supported
 */
#define I3C_SCAPABILITIES_TIMECTRL(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_TIMECTRL_SHIFT)) & I3C_SCAPABILITIES_TIMECTRL_MASK)

#define I3C_SCAPABILITIES_EXTFIFO_MASK           (0x3800000U)
#define I3C_SCAPABILITIES_EXTFIFO_SHIFT          (23U)
/*! EXTFIFO - External FIFO
 *  0b000..No external FIFO available
 *  0b001..Standard available or free external FIFO
 *  0b010..Request track external FIFO
 */
#define I3C_SCAPABILITIES_EXTFIFO(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_EXTFIFO_SHIFT)) & I3C_SCAPABILITIES_EXTFIFO_MASK)

#define I3C_SCAPABILITIES_FIFOTX_MASK            (0xC000000U)
#define I3C_SCAPABILITIES_FIFOTX_SHIFT           (26U)
/*! FIFOTX - FIFO Transmit
 *  0b00..Two
 *  0b01..Four
 *  0b10..Eight
 *  0b11..16 or larger
 */
#define I3C_SCAPABILITIES_FIFOTX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_FIFOTX_SHIFT)) & I3C_SCAPABILITIES_FIFOTX_MASK)

#define I3C_SCAPABILITIES_FIFORX_MASK            (0x30000000U)
#define I3C_SCAPABILITIES_FIFORX_SHIFT           (28U)
/*! FIFORX - FIFO Receive
 *  0b00..Two or three
 *  0b01..Four
 *  0b10..Eight
 *  0b11..16 or larger
 */
#define I3C_SCAPABILITIES_FIFORX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_FIFORX_SHIFT)) & I3C_SCAPABILITIES_FIFORX_MASK)

#define I3C_SCAPABILITIES_INT_MASK               (0x40000000U)
#define I3C_SCAPABILITIES_INT_SHIFT              (30U)
/*! INT - Interrupts
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES_INT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_INT_SHIFT)) & I3C_SCAPABILITIES_INT_MASK)

#define I3C_SCAPABILITIES_DMA_MASK               (0x80000000U)
#define I3C_SCAPABILITIES_DMA_SHIFT              (31U)
/*! DMA - Direct Memory Access
 *  0b0..Not supported
 *  0b1..Supported
 */
#define I3C_SCAPABILITIES_DMA(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_DMA_SHIFT)) & I3C_SCAPABILITIES_DMA_MASK)
/*! @} */

/*! @name SMAXLIMITS - Target Maximum Limits */
/*! @{ */

#define I3C_SMAXLIMITS_MAXRD_MASK                (0xFFFU)
#define I3C_SMAXLIMITS_MAXRD_SHIFT               (0U)
/*! MAXRD - Maximum Read Length */
#define I3C_SMAXLIMITS_MAXRD(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SMAXLIMITS_MAXRD_SHIFT)) & I3C_SMAXLIMITS_MAXRD_MASK)

#define I3C_SMAXLIMITS_MAXWR_MASK                (0xFFF0000U)
#define I3C_SMAXLIMITS_MAXWR_SHIFT               (16U)
/*! MAXWR - Maximum Write Length */
#define I3C_SMAXLIMITS_MAXWR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SMAXLIMITS_MAXWR_SHIFT)) & I3C_SMAXLIMITS_MAXWR_MASK)
/*! @} */

/*! @name SIDPARTNO - Target ID Part Number */
/*! @{ */

#define I3C_SIDPARTNO_PARTNO_MASK                (0xFFFFFFFFU)
#define I3C_SIDPARTNO_PARTNO_SHIFT               (0U)
/*! PARTNO - Part Number */
#define I3C_SIDPARTNO_PARTNO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SIDPARTNO_PARTNO_SHIFT)) & I3C_SIDPARTNO_PARTNO_MASK)
/*! @} */

/*! @name SIDEXT - Target ID Extension */
/*! @{ */

#define I3C_SIDEXT_DCR_MASK                      (0xFF00U)
#define I3C_SIDEXT_DCR_SHIFT                     (8U)
/*! DCR - Device Characteristic Register */
#define I3C_SIDEXT_DCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_SIDEXT_DCR_SHIFT)) & I3C_SIDEXT_DCR_MASK)

#define I3C_SIDEXT_BCR_MASK                      (0xFF0000U)
#define I3C_SIDEXT_BCR_SHIFT                     (16U)
/*! BCR - Bus Characteristics Register */
#define I3C_SIDEXT_BCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_SIDEXT_BCR_SHIFT)) & I3C_SIDEXT_BCR_MASK)
/*! @} */

/*! @name SVENDORID - Target Vendor ID */
/*! @{ */

#define I3C_SVENDORID_VID_MASK                   (0x7FFFU)
#define I3C_SVENDORID_VID_SHIFT                  (0U)
/*! VID - Vendor ID */
#define I3C_SVENDORID_VID(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SVENDORID_VID_SHIFT)) & I3C_SVENDORID_VID_MASK)
/*! @} */

/*! @name STCCLOCK - Target Time Control Clock */
/*! @{ */

#define I3C_STCCLOCK_ACCURACY_MASK               (0xFFU)
#define I3C_STCCLOCK_ACCURACY_SHIFT              (0U)
/*! ACCURACY - Clock Accuracy */
#define I3C_STCCLOCK_ACCURACY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_STCCLOCK_ACCURACY_SHIFT)) & I3C_STCCLOCK_ACCURACY_MASK)

#define I3C_STCCLOCK_FREQ_MASK                   (0xFF00U)
#define I3C_STCCLOCK_FREQ_SHIFT                  (8U)
/*! FREQ - Clock Frequency */
#define I3C_STCCLOCK_FREQ(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STCCLOCK_FREQ_SHIFT)) & I3C_STCCLOCK_FREQ_MASK)
/*! @} */

/*! @name SMSGMAPADDR - Target Message Map Address */
/*! @{ */

#define I3C_SMSGMAPADDR_MAPLAST_MASK             (0xFU)
#define I3C_SMSGMAPADDR_MAPLAST_SHIFT            (0U)
/*! MAPLAST - Matched Address Index */
#define I3C_SMSGMAPADDR_MAPLAST(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SMSGMAPADDR_MAPLAST_SHIFT)) & I3C_SMSGMAPADDR_MAPLAST_MASK)

#define I3C_SMSGMAPADDR_LASTSTATIC_MASK          (0x10U)
#define I3C_SMSGMAPADDR_LASTSTATIC_SHIFT         (4U)
/*! LASTSTATIC - Last Static Address Matched
 *  0b0..I3C dynamic address
 *  0b1..I2C static address
 */
#define I3C_SMSGMAPADDR_LASTSTATIC(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SMSGMAPADDR_LASTSTATIC_SHIFT)) & I3C_SMSGMAPADDR_LASTSTATIC_MASK)

#define I3C_SMSGMAPADDR_MAPLASTM1_MASK           (0xF00U)
#define I3C_SMSGMAPADDR_MAPLASTM1_SHIFT          (8U)
/*! MAPLASTM1 - Matched Previous Address Index 1 */
#define I3C_SMSGMAPADDR_MAPLASTM1(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SMSGMAPADDR_MAPLASTM1_SHIFT)) & I3C_SMSGMAPADDR_MAPLASTM1_MASK)

#define I3C_SMSGMAPADDR_MAPLASTM2_MASK           (0xF0000U)
#define I3C_SMSGMAPADDR_MAPLASTM2_SHIFT          (16U)
/*! MAPLASTM2 - Matched Previous Index 2 */
#define I3C_SMSGMAPADDR_MAPLASTM2(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SMSGMAPADDR_MAPLASTM2_SHIFT)) & I3C_SMSGMAPADDR_MAPLASTM2_MASK)
/*! @} */

/*! @name MCONFIG_EXT - Controller Extended Configuration */
/*! @{ */

#define I3C_MCONFIG_EXT_I3C_CAS_DEL_MASK         (0x30000U)
#define I3C_MCONFIG_EXT_I3C_CAS_DEL_SHIFT        (16U)
/*! I3C_CAS_DEL - I3C CAS Delay After START
 *  0b00..No delay
 *  0b01..Increases SCL clock period by 1/2
 *  0b10..Increases SCL clock period by 1
 *  0b11..Increases SCL clock period by 3/2
 */
#define I3C_MCONFIG_EXT_I3C_CAS_DEL(x)           (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_EXT_I3C_CAS_DEL_SHIFT)) & I3C_MCONFIG_EXT_I3C_CAS_DEL_MASK)

#define I3C_MCONFIG_EXT_I3C_CASR_DEL_MASK        (0xC0000U)
#define I3C_MCONFIG_EXT_I3C_CASR_DEL_SHIFT       (18U)
/*! I3C_CASR_DEL - I3C CAS Delay After Repeated START
 *  0b00..No delay
 *  0b01..Increases SCL clock period by 1/2
 *  0b10..Increases SCL clock period by 1
 *  0b11..Increases SCL clock period by 1 1/2
 */
#define I3C_MCONFIG_EXT_I3C_CASR_DEL(x)          (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_EXT_I3C_CASR_DEL_SHIFT)) & I3C_MCONFIG_EXT_I3C_CASR_DEL_MASK)
/*! @} */

/*! @name MCTRL - Controller Control */
/*! @{ */

#define I3C_MCTRL_REQUEST_MASK                   (0x7U)
#define I3C_MCTRL_REQUEST_SHIFT                  (0U)
/*! REQUEST - Request
 *  0b000..NONE
 *  0b001..EMITSTARTADDR
 *  0b010..EMITSTOP
 *  0b011..IBIACKNACK
 *  0b100..PROCESSDAA
 *  0b101..
 *  0b110..Force Exit and Target Reset
 *  0b111..AUTOIBI
 */
#define I3C_MCTRL_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_REQUEST_SHIFT)) & I3C_MCTRL_REQUEST_MASK)

#define I3C_MCTRL_TYPE_MASK                      (0x30U)
#define I3C_MCTRL_TYPE_SHIFT                     (4U)
/*! TYPE - Bus Type with EmitStartAddr
 *  0b00..I3C
 *  0b01..I2C
 *  0b10..DDR
 *  0b11..BT
 */
#define I3C_MCTRL_TYPE(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_TYPE_SHIFT)) & I3C_MCTRL_TYPE_MASK)

#define I3C_MCTRL_IBIRESP_MASK                   (0xC0U)
#define I3C_MCTRL_IBIRESP_SHIFT                  (6U)
/*! IBIRESP - In-Band Interrupt Response
 *  0b00..ACK (acknowledge)
 *  0b01..NACK (reject)
 *  0b10..Acknowledge with mandatory byte
 *  0b11..Manual
 */
#define I3C_MCTRL_IBIRESP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_IBIRESP_SHIFT)) & I3C_MCTRL_IBIRESP_MASK)

#define I3C_MCTRL_DIR_MASK                       (0x100U)
#define I3C_MCTRL_DIR_SHIFT                      (8U)
/*! DIR - Direction
 *  0b0..Write
 *  0b1..Read
 */
#define I3C_MCTRL_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_DIR_SHIFT)) & I3C_MCTRL_DIR_MASK)

#define I3C_MCTRL_ADDR_MASK                      (0xFE00U)
#define I3C_MCTRL_ADDR_SHIFT                     (9U)
/*! ADDR - Address */
#define I3C_MCTRL_ADDR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_ADDR_SHIFT)) & I3C_MCTRL_ADDR_MASK)

#define I3C_MCTRL_RDTERM_MASK                    (0xFF0000U)
#define I3C_MCTRL_RDTERM_SHIFT                   (16U)
/*! RDTERM - Read Terminate Counter */
#define I3C_MCTRL_RDTERM(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_RDTERM_SHIFT)) & I3C_MCTRL_RDTERM_MASK)
/*! @} */

/*! @name MSTATUS - Controller Status */
/*! @{ */

#define I3C_MSTATUS_STATE_MASK                   (0x7U)
#define I3C_MSTATUS_STATE_SHIFT                  (0U)
/*! STATE - State of the Controller
 *  0b000..IDLE (bus has stopped)
 *  0b001..SLVREQ (target request)
 *  0b010..MSGSDR
 *  0b011..NORMACT
 *  0b100..MSGDDR
 *  0b101..DAA
 *  0b110..IBIACK
 *  0b111..IBIRCV
 */
#define I3C_MSTATUS_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_STATE_SHIFT)) & I3C_MSTATUS_STATE_MASK)

#define I3C_MSTATUS_BETWEEN_MASK                 (0x10U)
#define I3C_MSTATUS_BETWEEN_SHIFT                (4U)
/*! BETWEEN - Between
 *  0b0..Inactive (for other cases)
 *  0b1..Active
 */
#define I3C_MSTATUS_BETWEEN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_BETWEEN_SHIFT)) & I3C_MSTATUS_BETWEEN_MASK)

#define I3C_MSTATUS_NACKED_MASK                  (0x20U)
#define I3C_MSTATUS_NACKED_SHIFT                 (5U)
/*! NACKED - Not Acknowledged
 *  0b0..Not NACKed
 *  0b1..NACKed (not acknowledged)
 */
#define I3C_MSTATUS_NACKED(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_NACKED_SHIFT)) & I3C_MSTATUS_NACKED_MASK)

#define I3C_MSTATUS_IBITYPE_MASK                 (0xC0U)
#define I3C_MSTATUS_IBITYPE_SHIFT                (6U)
/*! IBITYPE - In-Band Interrupt (IBI) Type
 *  0b00..NONE (no IBI: this status occurs when MSTATUS[IBIWON] becomes 0)
 *  0b01..IBI
 *  0b10..CR
 *  0b11..HJ
 */
#define I3C_MSTATUS_IBITYPE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBITYPE_SHIFT)) & I3C_MSTATUS_IBITYPE_MASK)

#define I3C_MSTATUS_SLVSTART_MASK                (0x100U)
#define I3C_MSTATUS_SLVSTART_SHIFT               (8U)
/*! SLVSTART - Target Start Flag
 *  0b0..No effect
 *  0b0..Target not requesting START
 *  0b1..Clear the flag
 *  0b1..Target requesting START
 */
#define I3C_MSTATUS_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_SLVSTART_SHIFT)) & I3C_MSTATUS_SLVSTART_MASK)

#define I3C_MSTATUS_MCTRLDONE_MASK               (0x200U)
#define I3C_MSTATUS_MCTRLDONE_SHIFT              (9U)
/*! MCTRLDONE - Controller Control Done Flag
 *  0b0..No effect
 *  0b0..Not done
 *  0b1..Clear the flag
 *  0b1..Done
 */
#define I3C_MSTATUS_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_MCTRLDONE_SHIFT)) & I3C_MSTATUS_MCTRLDONE_MASK)

#define I3C_MSTATUS_COMPLETE_MASK                (0x400U)
#define I3C_MSTATUS_COMPLETE_SHIFT               (10U)
/*! COMPLETE - Complete Flag
 *  0b0..No effect
 *  0b0..Not complete
 *  0b1..Clear the flag
 *  0b1..Complete
 */
#define I3C_MSTATUS_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_COMPLETE_SHIFT)) & I3C_MSTATUS_COMPLETE_MASK)

#define I3C_MSTATUS_RXPEND_MASK                  (0x800U)
#define I3C_MSTATUS_RXPEND_SHIFT                 (11U)
/*! RXPEND - RXPEND
 *  0b0..No receive message pending
 *  0b1..Receive message pending
 */
#define I3C_MSTATUS_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_RXPEND_SHIFT)) & I3C_MSTATUS_RXPEND_MASK)

#define I3C_MSTATUS_TXNOTFULL_MASK               (0x1000U)
#define I3C_MSTATUS_TXNOTFULL_SHIFT              (12U)
/*! TXNOTFULL - TX Buffer or FIFO Not Full
 *  0b0..Receive buffer or FIFO full
 *  0b1..Receive buffer or FIFO not full
 */
#define I3C_MSTATUS_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_TXNOTFULL_SHIFT)) & I3C_MSTATUS_TXNOTFULL_MASK)

#define I3C_MSTATUS_IBIWON_MASK                  (0x2000U)
#define I3C_MSTATUS_IBIWON_SHIFT                 (13U)
/*! IBIWON - In-Band Interrupt (IBI) Won Flag
 *  0b0..No IBI arbitration won
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..IBI arbitration won
 */
#define I3C_MSTATUS_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBIWON_SHIFT)) & I3C_MSTATUS_IBIWON_MASK)

#define I3C_MSTATUS_ERRWARN_MASK                 (0x8000U)
#define I3C_MSTATUS_ERRWARN_SHIFT                (15U)
/*! ERRWARN - Error or Warning
 *  0b0..No error or warning
 *  0b1..Error or warning
 */
#define I3C_MSTATUS_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_ERRWARN_SHIFT)) & I3C_MSTATUS_ERRWARN_MASK)

#define I3C_MSTATUS_NOWMASTER_MASK               (0x80000U)
#define I3C_MSTATUS_NOWMASTER_SHIFT              (19U)
/*! NOWMASTER - Module is now Controller Flag
 *  0b0..No effect
 *  0b0..Not a controller
 *  0b1..Clear the flag
 *  0b1..Controller
 */
#define I3C_MSTATUS_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_NOWMASTER_SHIFT)) & I3C_MSTATUS_NOWMASTER_MASK)

#define I3C_MSTATUS_IBIADDR_MASK                 (0x7F000000U)
#define I3C_MSTATUS_IBIADDR_SHIFT                (24U)
/*! IBIADDR - IBI Address */
#define I3C_MSTATUS_IBIADDR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBIADDR_SHIFT)) & I3C_MSTATUS_IBIADDR_MASK)
/*! @} */

/*! @name MIBIRULES - Controller In-band Interrupt Registry and Rules */
/*! @{ */

#define I3C_MIBIRULES_ADDR0_MASK                 (0x3FU)
#define I3C_MIBIRULES_ADDR0_SHIFT                (0U)
/*! ADDR0 - ADDR0 */
#define I3C_MIBIRULES_ADDR0(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR0_SHIFT)) & I3C_MIBIRULES_ADDR0_MASK)

#define I3C_MIBIRULES_ADDR1_MASK                 (0xFC0U)
#define I3C_MIBIRULES_ADDR1_SHIFT                (6U)
/*! ADDR1 - ADDR1 */
#define I3C_MIBIRULES_ADDR1(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR1_SHIFT)) & I3C_MIBIRULES_ADDR1_MASK)

#define I3C_MIBIRULES_ADDR2_MASK                 (0x3F000U)
#define I3C_MIBIRULES_ADDR2_SHIFT                (12U)
/*! ADDR2 - ADDR2 */
#define I3C_MIBIRULES_ADDR2(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR2_SHIFT)) & I3C_MIBIRULES_ADDR2_MASK)

#define I3C_MIBIRULES_ADDR3_MASK                 (0xFC0000U)
#define I3C_MIBIRULES_ADDR3_SHIFT                (18U)
/*! ADDR3 - ADDR3 */
#define I3C_MIBIRULES_ADDR3(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR3_SHIFT)) & I3C_MIBIRULES_ADDR3_MASK)

#define I3C_MIBIRULES_ADDR4_MASK                 (0x3F000000U)
#define I3C_MIBIRULES_ADDR4_SHIFT                (24U)
/*! ADDR4 - ADDR4 */
#define I3C_MIBIRULES_ADDR4(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR4_SHIFT)) & I3C_MIBIRULES_ADDR4_MASK)

#define I3C_MIBIRULES_MSB0_MASK                  (0x40000000U)
#define I3C_MIBIRULES_MSB0_SHIFT                 (30U)
/*! MSB0 - Most Significant Address Bit is 0
 *  0b0..MSB is not 0
 *  0b1..MSB is 0
 */
#define I3C_MIBIRULES_MSB0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_MSB0_SHIFT)) & I3C_MIBIRULES_MSB0_MASK)

#define I3C_MIBIRULES_NOBYTE_MASK                (0x80000000U)
#define I3C_MIBIRULES_NOBYTE_SHIFT               (31U)
/*! NOBYTE - No IBI byte
 *  0b0..With mandatory IBI byte
 *  0b1..Without mandatory IBI byte
 */
#define I3C_MIBIRULES_NOBYTE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_NOBYTE_SHIFT)) & I3C_MIBIRULES_NOBYTE_MASK)
/*! @} */

/*! @name MINTSET - Controller Interrupt Set */
/*! @{ */

#define I3C_MINTSET_SLVSTART_MASK                (0x100U)
#define I3C_MINTSET_SLVSTART_SHIFT               (8U)
/*! SLVSTART - Target Start Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_SLVSTART_SHIFT)) & I3C_MINTSET_SLVSTART_MASK)

#define I3C_MINTSET_MCTRLDONE_MASK               (0x200U)
#define I3C_MINTSET_MCTRLDONE_SHIFT              (9U)
/*! MCTRLDONE - Controller Control Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_MCTRLDONE_SHIFT)) & I3C_MINTSET_MCTRLDONE_MASK)

#define I3C_MINTSET_COMPLETE_MASK                (0x400U)
#define I3C_MINTSET_COMPLETE_SHIFT               (10U)
/*! COMPLETE - Completed Message Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_COMPLETE_SHIFT)) & I3C_MINTSET_COMPLETE_MASK)

#define I3C_MINTSET_RXPEND_MASK                  (0x800U)
#define I3C_MINTSET_RXPEND_SHIFT                 (11U)
/*! RXPEND - Receive Pending Interrupt Enable */
#define I3C_MINTSET_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_RXPEND_SHIFT)) & I3C_MINTSET_RXPEND_MASK)

#define I3C_MINTSET_TXNOTFULL_MASK               (0x1000U)
#define I3C_MINTSET_TXNOTFULL_SHIFT              (12U)
/*! TXNOTFULL - Transmit Buffer/FIFO Not Full Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_TXNOTFULL_SHIFT)) & I3C_MINTSET_TXNOTFULL_MASK)

#define I3C_MINTSET_IBIWON_MASK                  (0x2000U)
#define I3C_MINTSET_IBIWON_SHIFT                 (13U)
/*! IBIWON - IBI Won Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_IBIWON_SHIFT)) & I3C_MINTSET_IBIWON_MASK)

#define I3C_MINTSET_ERRWARN_MASK                 (0x8000U)
#define I3C_MINTSET_ERRWARN_SHIFT                (15U)
/*! ERRWARN - Error or Warning (ERRWARN) Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_ERRWARN_SHIFT)) & I3C_MINTSET_ERRWARN_MASK)

#define I3C_MINTSET_NOWMASTER_MASK               (0x80000U)
#define I3C_MINTSET_NOWMASTER_SHIFT              (19U)
/*! NOWMASTER - Now Controller Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_MINTSET_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_NOWMASTER_SHIFT)) & I3C_MINTSET_NOWMASTER_MASK)
/*! @} */

/*! @name MINTCLR - Controller Interrupt Clear */
/*! @{ */

#define I3C_MINTCLR_SLVSTART_MASK                (0x100U)
#define I3C_MINTCLR_SLVSTART_SHIFT               (8U)
/*! SLVSTART - SLVSTART Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_SLVSTART_SHIFT)) & I3C_MINTCLR_SLVSTART_MASK)

#define I3C_MINTCLR_MCTRLDONE_MASK               (0x200U)
#define I3C_MINTCLR_MCTRLDONE_SHIFT              (9U)
/*! MCTRLDONE - MCTRLDONE Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_MCTRLDONE_SHIFT)) & I3C_MINTCLR_MCTRLDONE_MASK)

#define I3C_MINTCLR_COMPLETE_MASK                (0x400U)
#define I3C_MINTCLR_COMPLETE_SHIFT               (10U)
/*! COMPLETE - COMPLETE Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_COMPLETE_SHIFT)) & I3C_MINTCLR_COMPLETE_MASK)

#define I3C_MINTCLR_RXPEND_MASK                  (0x800U)
#define I3C_MINTCLR_RXPEND_SHIFT                 (11U)
/*! RXPEND - RXPEND Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_RXPEND_SHIFT)) & I3C_MINTCLR_RXPEND_MASK)

#define I3C_MINTCLR_TXNOTFULL_MASK               (0x1000U)
#define I3C_MINTCLR_TXNOTFULL_SHIFT              (12U)
/*! TXNOTFULL - TXNOTFULL Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_TXNOTFULL_SHIFT)) & I3C_MINTCLR_TXNOTFULL_MASK)

#define I3C_MINTCLR_IBIWON_MASK                  (0x2000U)
#define I3C_MINTCLR_IBIWON_SHIFT                 (13U)
/*! IBIWON - IBIWON Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_IBIWON_SHIFT)) & I3C_MINTCLR_IBIWON_MASK)

#define I3C_MINTCLR_ERRWARN_MASK                 (0x8000U)
#define I3C_MINTCLR_ERRWARN_SHIFT                (15U)
/*! ERRWARN - ERRWARN Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_ERRWARN_SHIFT)) & I3C_MINTCLR_ERRWARN_MASK)

#define I3C_MINTCLR_NOWMASTER_MASK               (0x80000U)
#define I3C_MINTCLR_NOWMASTER_SHIFT              (19U)
/*! NOWMASTER - NOWCONTROLLER Interrupt Enable Clear Flag
 *  0b0..No effect
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Interrupt enable cleared
 */
#define I3C_MINTCLR_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_NOWMASTER_SHIFT)) & I3C_MINTCLR_NOWMASTER_MASK)
/*! @} */

/*! @name MINTMASKED - Controller Interrupt Mask */
/*! @{ */

#define I3C_MINTMASKED_SLVSTART_MASK             (0x100U)
#define I3C_MINTMASKED_SLVSTART_SHIFT            (8U)
/*! SLVSTART - SLVSTART Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_SLVSTART(x)               (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_SLVSTART_SHIFT)) & I3C_MINTMASKED_SLVSTART_MASK)

#define I3C_MINTMASKED_MCTRLDONE_MASK            (0x200U)
#define I3C_MINTMASKED_MCTRLDONE_SHIFT           (9U)
/*! MCTRLDONE - MCTRLDONE Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_MCTRLDONE(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_MCTRLDONE_SHIFT)) & I3C_MINTMASKED_MCTRLDONE_MASK)

#define I3C_MINTMASKED_COMPLETE_MASK             (0x400U)
#define I3C_MINTMASKED_COMPLETE_SHIFT            (10U)
/*! COMPLETE - COMPLETE Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_COMPLETE(x)               (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_COMPLETE_SHIFT)) & I3C_MINTMASKED_COMPLETE_MASK)

#define I3C_MINTMASKED_RXPEND_MASK               (0x800U)
#define I3C_MINTMASKED_RXPEND_SHIFT              (11U)
/*! RXPEND - RXPEND Interrupt Mask */
#define I3C_MINTMASKED_RXPEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_RXPEND_SHIFT)) & I3C_MINTMASKED_RXPEND_MASK)

#define I3C_MINTMASKED_TXNOTFULL_MASK            (0x1000U)
#define I3C_MINTMASKED_TXNOTFULL_SHIFT           (12U)
/*! TXNOTFULL - TXNOTFULL Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_TXNOTFULL(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_TXNOTFULL_SHIFT)) & I3C_MINTMASKED_TXNOTFULL_MASK)

#define I3C_MINTMASKED_IBIWON_MASK               (0x2000U)
#define I3C_MINTMASKED_IBIWON_SHIFT              (13U)
/*! IBIWON - IBIWON Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_IBIWON(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_IBIWON_SHIFT)) & I3C_MINTMASKED_IBIWON_MASK)

#define I3C_MINTMASKED_ERRWARN_MASK              (0x8000U)
#define I3C_MINTMASKED_ERRWARN_SHIFT             (15U)
/*! ERRWARN - ERRWARN Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_ERRWARN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_ERRWARN_SHIFT)) & I3C_MINTMASKED_ERRWARN_MASK)

#define I3C_MINTMASKED_NOWMASTER_MASK            (0x80000U)
#define I3C_MINTMASKED_NOWMASTER_SHIFT           (19U)
/*! NOWMASTER - NOWCONTROLLER Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_MINTMASKED_NOWMASTER(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_NOWMASTER_SHIFT)) & I3C_MINTMASKED_NOWMASTER_MASK)
/*! @} */

/*! @name MERRWARN - Controller Errors and Warnings */
/*! @{ */

#define I3C_MERRWARN_URUN_MASK                   (0x2U)
#define I3C_MERRWARN_URUN_SHIFT                  (1U)
/*! URUN - Underrun Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_URUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_URUN_SHIFT)) & I3C_MERRWARN_URUN_MASK)

#define I3C_MERRWARN_NACK_MASK                   (0x4U)
#define I3C_MERRWARN_NACK_SHIFT                  (2U)
/*! NACK - Not Acknowledge Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_NACK(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_NACK_SHIFT)) & I3C_MERRWARN_NACK_MASK)

#define I3C_MERRWARN_WRABT_MASK                  (0x8U)
#define I3C_MERRWARN_WRABT_SHIFT                 (3U)
/*! WRABT - Write Abort Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_WRABT(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_WRABT_SHIFT)) & I3C_MERRWARN_WRABT_MASK)

#define I3C_MERRWARN_TERM_MASK                   (0x10U)
#define I3C_MERRWARN_TERM_SHIFT                  (4U)
/*! TERM - Terminate Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_TERM(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_TERM_SHIFT)) & I3C_MERRWARN_TERM_MASK)

#define I3C_MERRWARN_HPAR_MASK                   (0x200U)
#define I3C_MERRWARN_HPAR_SHIFT                  (9U)
/*! HPAR - High Data Rate Parity Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_HPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HPAR_SHIFT)) & I3C_MERRWARN_HPAR_MASK)

#define I3C_MERRWARN_HCRC_MASK                   (0x400U)
#define I3C_MERRWARN_HCRC_SHIFT                  (10U)
/*! HCRC - High Data Rate CRC Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_HCRC(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HCRC_SHIFT)) & I3C_MERRWARN_HCRC_MASK)

#define I3C_MERRWARN_HNOVERIFY_MASK              (0x1000U)
#define I3C_MERRWARN_HNOVERIFY_SHIFT             (12U)
/*! HNOVERIFY - HDR-BT Not Verified Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_HNOVERIFY(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HNOVERIFY_SHIFT)) & I3C_MERRWARN_HNOVERIFY_MASK)

#define I3C_MERRWARN_OREAD_MASK                  (0x10000U)
#define I3C_MERRWARN_OREAD_SHIFT                 (16U)
/*! OREAD - Overread Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_OREAD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_OREAD_SHIFT)) & I3C_MERRWARN_OREAD_MASK)

#define I3C_MERRWARN_OWRITE_MASK                 (0x20000U)
#define I3C_MERRWARN_OWRITE_SHIFT                (17U)
/*! OWRITE - Overwrite Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_OWRITE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_OWRITE_SHIFT)) & I3C_MERRWARN_OWRITE_MASK)

#define I3C_MERRWARN_MSGERR_MASK                 (0x40000U)
#define I3C_MERRWARN_MSGERR_SHIFT                (18U)
/*! MSGERR - Message Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_MSGERR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_MSGERR_SHIFT)) & I3C_MERRWARN_MSGERR_MASK)

#define I3C_MERRWARN_INVREQ_MASK                 (0x80000U)
#define I3C_MERRWARN_INVREQ_SHIFT                (19U)
/*! INVREQ - Invalid Request Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_INVREQ(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_INVREQ_SHIFT)) & I3C_MERRWARN_INVREQ_MASK)

#define I3C_MERRWARN_TIMEOUT_MASK                (0x100000U)
#define I3C_MERRWARN_TIMEOUT_SHIFT               (20U)
/*! TIMEOUT - Timeout Error Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_TIMEOUT(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_TIMEOUT_SHIFT)) & I3C_MERRWARN_TIMEOUT_MASK)

#define I3C_MERRWARN_WRONGSIZE_MASK              (0x200000U)
#define I3C_MERRWARN_WRONGSIZE_SHIFT             (21U)
/*! WRONGSIZE - Wrong Size Flag
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define I3C_MERRWARN_WRONGSIZE(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_WRONGSIZE_SHIFT)) & I3C_MERRWARN_WRONGSIZE_MASK)
/*! @} */

/*! @name MDMACTRL - Controller DMA Control */
/*! @{ */

#define I3C_MDMACTRL_DMAFB_MASK                  (0x3U)
#define I3C_MDMACTRL_DMAFB_SHIFT                 (0U)
/*! DMAFB - DMA from Bus
 *  0b00..DMA not used
 *  0b01..Enable DMA for one frame
 *  0b10..Enable DMA until DMA is turned off
 *  0b11..
 */
#define I3C_MDMACTRL_DMAFB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMAFB_SHIFT)) & I3C_MDMACTRL_DMAFB_MASK)

#define I3C_MDMACTRL_DMATB_MASK                  (0xCU)
#define I3C_MDMACTRL_DMATB_SHIFT                 (2U)
/*! DMATB - DMA to Bus
 *  0b00..DMA not used
 *  0b01..Enable DMA for one frame (ended by DMA or terminated)
 *  0b10..Enable DMA until DMA is turned off
 *  0b11..
 */
#define I3C_MDMACTRL_DMATB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMATB_SHIFT)) & I3C_MDMACTRL_DMATB_MASK)

#define I3C_MDMACTRL_DMAWIDTH_MASK               (0x30U)
#define I3C_MDMACTRL_DMAWIDTH_SHIFT              (4U)
/*! DMAWIDTH - DMA Width
 *  0b00, 0b01..Byte
 *  0b10..Halfword (16 bits)
 *  0b11..
 */
#define I3C_MDMACTRL_DMAWIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMAWIDTH_SHIFT)) & I3C_MDMACTRL_DMAWIDTH_MASK)
/*! @} */

/*! @name MHDRBTCFG - Controller HDR-BT Configuration */
/*! @{ */

#define I3C_MHDRBTCFG_MLHDR_MASK                 (0x3U)
#define I3C_MHDRBTCFG_MLHDR_SHIFT                (0U)
/*! MLHDR - Multi-Lane HDR
 *  0b00..Single lane for header
 *  0b01..Dual lane for header
 *  0b10..Reserved and unused
 *  0b11..Quad-lane header
 */
#define I3C_MHDRBTCFG_MLHDR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_MLHDR_SHIFT)) & I3C_MHDRBTCFG_MLHDR_MASK)

#define I3C_MHDRBTCFG_MLDAT_MASK                 (0xCU)
#define I3C_MHDRBTCFG_MLDAT_SHIFT                (2U)
/*! MLDAT - Multi-Lane Data
 *  0b00..Single lane for data
 *  0b01..Dual lane for data
 *  0b10..Reserved and unused
 *  0b11..Quad-lane data
 */
#define I3C_MHDRBTCFG_MLDAT(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_MLDAT_SHIFT)) & I3C_MHDRBTCFG_MLDAT_MASK)

#define I3C_MHDRBTCFG_CRC32_MASK                 (0x10U)
#define I3C_MHDRBTCFG_CRC32_SHIFT                (4U)
/*! CRC32 - CRC32
 *  0b0..Use CRC16
 *  0b1..Use CRC32
 */
#define I3C_MHDRBTCFG_CRC32(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_CRC32_SHIFT)) & I3C_MHDRBTCFG_CRC32_MASK)

#define I3C_MHDRBTCFG_DATALEN_MASK               (0xFFFF0000U)
#define I3C_MHDRBTCFG_DATALEN_SHIFT              (16U)
/*! DATALEN - Data Length */
#define I3C_MHDRBTCFG_DATALEN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_DATALEN_SHIFT)) & I3C_MHDRBTCFG_DATALEN_MASK)
/*! @} */

/*! @name MHDRBTLAST - Controller HDR-Last */
/*! @{ */

#define I3C_MHDRBTLAST_DATALEN_MASK              (0xFFFF0000U)
#define I3C_MHDRBTLAST_DATALEN_SHIFT             (16U)
/*! DATALEN - Data Length */
#define I3C_MHDRBTLAST_DATALEN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTLAST_DATALEN_SHIFT)) & I3C_MHDRBTLAST_DATALEN_MASK)
/*! @} */

/*! @name MDATACTRL - Controller Data Control */
/*! @{ */

#define I3C_MDATACTRL_FLUSHTB_MASK               (0x1U)
#define I3C_MDATACTRL_FLUSHTB_SHIFT              (0U)
/*! FLUSHTB - Flush To-Bus Buffer or FIFO
 *  0b0..No action
 *  0b1..Flush the buffer
 */
#define I3C_MDATACTRL_FLUSHTB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_FLUSHTB_SHIFT)) & I3C_MDATACTRL_FLUSHTB_MASK)

#define I3C_MDATACTRL_FLUSHFB_MASK               (0x2U)
#define I3C_MDATACTRL_FLUSHFB_SHIFT              (1U)
/*! FLUSHFB - Flush From-Bus Buffer or FIFO
 *  0b0..No action
 *  0b1..Flush the buffer
 */
#define I3C_MDATACTRL_FLUSHFB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_FLUSHFB_SHIFT)) & I3C_MDATACTRL_FLUSHFB_MASK)

#define I3C_MDATACTRL_UNLOCK_MASK                (0x8U)
#define I3C_MDATACTRL_UNLOCK_SHIFT               (3U)
/*! UNLOCK - Unlock
 *  0b0..Locked
 *  0b1..Unlocked
 */
#define I3C_MDATACTRL_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_UNLOCK_SHIFT)) & I3C_MDATACTRL_UNLOCK_MASK)

#define I3C_MDATACTRL_TXTRIG_MASK                (0x30U)
#define I3C_MDATACTRL_TXTRIG_SHIFT               (4U)
/*! TXTRIG - Transmit Trigger Level
 *  0b00..Trigger when empty
 *  0b01..Trigger when 1/4 full or less
 *  0b10..Trigger when 1/2 full or less
 *  0b11..Trigger when 1 less than full or less (default)
 */
#define I3C_MDATACTRL_TXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXTRIG_SHIFT)) & I3C_MDATACTRL_TXTRIG_MASK)

#define I3C_MDATACTRL_RXTRIG_MASK                (0xC0U)
#define I3C_MDATACTRL_RXTRIG_SHIFT               (6U)
/*! RXTRIG - Receive Trigger Level
 *  0b00..Trigger when not empty (default)
 *  0b01..Trigger when 1/4 full or more
 *  0b10..Trigger when 1/2 full or more
 *  0b11..Trigger when 3/4 full or more
 */
#define I3C_MDATACTRL_RXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXTRIG_SHIFT)) & I3C_MDATACTRL_RXTRIG_MASK)

#define I3C_MDATACTRL_TXCOUNT_MASK               (0x1F0000U)
#define I3C_MDATACTRL_TXCOUNT_SHIFT              (16U)
/*! TXCOUNT - Transmit Entry Count */
#define I3C_MDATACTRL_TXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXCOUNT_SHIFT)) & I3C_MDATACTRL_TXCOUNT_MASK)

#define I3C_MDATACTRL_RXCOUNT_MASK               (0x1F000000U)
#define I3C_MDATACTRL_RXCOUNT_SHIFT              (24U)
/*! RXCOUNT - Receive Entry Count */
#define I3C_MDATACTRL_RXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXCOUNT_SHIFT)) & I3C_MDATACTRL_RXCOUNT_MASK)

#define I3C_MDATACTRL_TXFULL_MASK                (0x40000000U)
#define I3C_MDATACTRL_TXFULL_SHIFT               (30U)
/*! TXFULL - Transmit is Full
 *  0b0..Not full
 *  0b1..Full
 */
#define I3C_MDATACTRL_TXFULL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXFULL_SHIFT)) & I3C_MDATACTRL_TXFULL_MASK)

#define I3C_MDATACTRL_RXEMPTY_MASK               (0x80000000U)
#define I3C_MDATACTRL_RXEMPTY_SHIFT              (31U)
/*! RXEMPTY - Receive is Empty
 *  0b0..Not empty
 *  0b1..Empty
 */
#define I3C_MDATACTRL_RXEMPTY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXEMPTY_SHIFT)) & I3C_MDATACTRL_RXEMPTY_MASK)
/*! @} */

/*! @name MWDATAB - Controller Write Data Byte */
/*! @{ */

#define I3C_MWDATAB_VALUE_MASK                   (0xFFU)
#define I3C_MWDATAB_VALUE_SHIFT                  (0U)
/*! VALUE - Data Byte */
#define I3C_MWDATAB_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_VALUE_SHIFT)) & I3C_MWDATAB_VALUE_MASK)

#define I3C_MWDATAB_END_MASK                     (0x100U)
#define I3C_MWDATAB_END_SHIFT                    (8U)
/*! END - End of Message
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_MWDATAB_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_END_SHIFT)) & I3C_MWDATAB_END_MASK)

#define I3C_MWDATAB_END_ALSO_MASK                (0x10000U)
#define I3C_MWDATAB_END_ALSO_SHIFT               (16U)
/*! END_ALSO - End of Message ALSO
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_MWDATAB_END_ALSO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_END_ALSO_SHIFT)) & I3C_MWDATAB_END_ALSO_MASK)
/*! @} */

/*! @name MWDATABE - Controller Write Data Byte End */
/*! @{ */

#define I3C_MWDATABE_VALUE_MASK                  (0xFFU)
#define I3C_MWDATABE_VALUE_SHIFT                 (0U)
/*! VALUE - Data */
#define I3C_MWDATABE_VALUE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATABE_VALUE_SHIFT)) & I3C_MWDATABE_VALUE_MASK)
/*! @} */

/*! @name MWDATAH - Controller Write Data Halfword */
/*! @{ */

#define I3C_MWDATAH_DATA0_MASK                   (0xFFU)
#define I3C_MWDATAH_DATA0_SHIFT                  (0U)
/*! DATA0 - Data Byte 0 */
#define I3C_MWDATAH_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_DATA0_SHIFT)) & I3C_MWDATAH_DATA0_MASK)

#define I3C_MWDATAH_DATA1_MASK                   (0xFF00U)
#define I3C_MWDATAH_DATA1_SHIFT                  (8U)
/*! DATA1 - Data Byte 1 */
#define I3C_MWDATAH_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_DATA1_SHIFT)) & I3C_MWDATAH_DATA1_MASK)

#define I3C_MWDATAH_END_MASK                     (0x10000U)
#define I3C_MWDATAH_END_SHIFT                    (16U)
/*! END - End of Message
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_MWDATAH_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_END_SHIFT)) & I3C_MWDATAH_END_MASK)
/*! @} */

/*! @name MWDATAHE - Controller Write Data Halfword End */
/*! @{ */

#define I3C_MWDATAHE_DATA0_MASK                  (0xFFU)
#define I3C_MWDATAHE_DATA0_SHIFT                 (0U)
/*! DATA0 - Data Byte 0 */
#define I3C_MWDATAHE_DATA0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAHE_DATA0_SHIFT)) & I3C_MWDATAHE_DATA0_MASK)

#define I3C_MWDATAHE_DATA1_MASK                  (0xFF00U)
#define I3C_MWDATAHE_DATA1_SHIFT                 (8U)
/*! DATA1 - Data Byte 1 */
#define I3C_MWDATAHE_DATA1(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAHE_DATA1_SHIFT)) & I3C_MWDATAHE_DATA1_MASK)
/*! @} */

/*! @name MRDATAB - Controller Read Data Byte */
/*! @{ */

#define I3C_MRDATAB_VALUE_MASK                   (0xFFU)
#define I3C_MRDATAB_VALUE_SHIFT                  (0U)
/*! VALUE - Value */
#define I3C_MRDATAB_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAB_VALUE_SHIFT)) & I3C_MRDATAB_VALUE_MASK)
/*! @} */

/*! @name MRDATAH - Controller Read Data Halfword */
/*! @{ */

#define I3C_MRDATAH_LSB_MASK                     (0xFFU)
#define I3C_MRDATAH_LSB_SHIFT                    (0U)
/*! LSB - Low Byte */
#define I3C_MRDATAH_LSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAH_LSB_SHIFT)) & I3C_MRDATAH_LSB_MASK)

#define I3C_MRDATAH_MSB_MASK                     (0xFF00U)
#define I3C_MRDATAH_MSB_SHIFT                    (8U)
/*! MSB - High Byte */
#define I3C_MRDATAH_MSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAH_MSB_SHIFT)) & I3C_MRDATAH_MSB_MASK)
/*! @} */

/*! @name MWDATAB1 - Controller Write Byte Data 1 (to Bus) */
/*! @{ */

#define I3C_MWDATAB1_VALUE_MASK                  (0xFFU)
#define I3C_MWDATAB1_VALUE_SHIFT                 (0U)
/*! VALUE - Value */
#define I3C_MWDATAB1_VALUE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB1_VALUE_SHIFT)) & I3C_MWDATAB1_VALUE_MASK)
/*! @} */

/*! @name MWMSG_SDR_CONTROL - Controller Write Message Control in SDR mode */
/*! @{ */

#define I3C_MWMSG_SDR_CONTROL_DIR_MASK           (0x1U)
#define I3C_MWMSG_SDR_CONTROL_DIR_SHIFT          (0U)
/*! DIR - Direction
 *  0b0..Write
 *  0b1..Read
 */
#define I3C_MWMSG_SDR_CONTROL_DIR(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_DIR_SHIFT)) & I3C_MWMSG_SDR_CONTROL_DIR_MASK)

#define I3C_MWMSG_SDR_CONTROL_ADDR_MASK          (0xFEU)
#define I3C_MWMSG_SDR_CONTROL_ADDR_SHIFT         (1U)
/*! ADDR - Address */
#define I3C_MWMSG_SDR_CONTROL_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_ADDR_SHIFT)) & I3C_MWMSG_SDR_CONTROL_ADDR_MASK)

#define I3C_MWMSG_SDR_CONTROL_END_MASK           (0x100U)
#define I3C_MWMSG_SDR_CONTROL_END_SHIFT          (8U)
/*! END - End of SDR Message
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_MWMSG_SDR_CONTROL_END(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_END_SHIFT)) & I3C_MWMSG_SDR_CONTROL_END_MASK)

#define I3C_MWMSG_SDR_CONTROL_I2C_MASK           (0x400U)
#define I3C_MWMSG_SDR_CONTROL_I2C_SHIFT          (10U)
/*! I2C - I2C
 *  0b0..I3C message
 *  0b1..I2C message
 */
#define I3C_MWMSG_SDR_CONTROL_I2C(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_I2C_SHIFT)) & I3C_MWMSG_SDR_CONTROL_I2C_MASK)

#define I3C_MWMSG_SDR_CONTROL_LEN_MASK           (0xF800U)
#define I3C_MWMSG_SDR_CONTROL_LEN_SHIFT          (11U)
/*! LEN - Length */
#define I3C_MWMSG_SDR_CONTROL_LEN(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_LEN_SHIFT)) & I3C_MWMSG_SDR_CONTROL_LEN_MASK)
/*! @} */

/*! @name MWMSG_SDR_DATA - Controller Write Message Data in SDR mode */
/*! @{ */

#define I3C_MWMSG_SDR_DATA_DATA16B_MASK          (0xFFFFU)
#define I3C_MWMSG_SDR_DATA_DATA16B_SHIFT         (0U)
/*! DATA16B - Data */
#define I3C_MWMSG_SDR_DATA_DATA16B(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_DATA_DATA16B_SHIFT)) & I3C_MWMSG_SDR_DATA_DATA16B_MASK)
/*! @} */

/*! @name MRMSG_SDR - Controller Read Message in SDR mode */
/*! @{ */

#define I3C_MRMSG_SDR_DATA_MASK                  (0xFFFFU)
#define I3C_MRMSG_SDR_DATA_SHIFT                 (0U)
/*! DATA - Data */
#define I3C_MRMSG_SDR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MRMSG_SDR_DATA_SHIFT)) & I3C_MRMSG_SDR_DATA_MASK)
/*! @} */

/*! @name MWMSG_DDR_CONTROL - Controller Write Message in DDR mode: First Control Word */
/*! @{ */

#define I3C_MWMSG_DDR_CONTROL_ADDRCMD_MASK       (0xFFFFU)
#define I3C_MWMSG_DDR_CONTROL_ADDRCMD_SHIFT      (0U)
/*! ADDRCMD - Address Command */
#define I3C_MWMSG_DDR_CONTROL_ADDRCMD(x)         (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_CONTROL_ADDRCMD_SHIFT)) & I3C_MWMSG_DDR_CONTROL_ADDRCMD_MASK)
/*! @} */

/*! @name MWMSG_DDR_CONTROL2 - Controller Write Message in DDR Mode Control 2 */
/*! @{ */

#define I3C_MWMSG_DDR_CONTROL2_LEN_MASK          (0x3FFU)
#define I3C_MWMSG_DDR_CONTROL2_LEN_SHIFT         (0U)
/*! LEN - Length of Message */
#define I3C_MWMSG_DDR_CONTROL2_LEN(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_CONTROL2_LEN_SHIFT)) & I3C_MWMSG_DDR_CONTROL2_LEN_MASK)

#define I3C_MWMSG_DDR_CONTROL2_END_MASK          (0x4000U)
#define I3C_MWMSG_DDR_CONTROL2_END_SHIFT         (14U)
/*! END - End of Message
 *  0b0..Not the end
 *  0b1..End
 */
#define I3C_MWMSG_DDR_CONTROL2_END(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_CONTROL2_END_SHIFT)) & I3C_MWMSG_DDR_CONTROL2_END_MASK)
/*! @} */

/*! @name MWMSG_DDR_DATA - Controller Write Message Data in DDR mode */
/*! @{ */

#define I3C_MWMSG_DDR_DATA_DATA16B_MASK          (0xFFFFU)
#define I3C_MWMSG_DDR_DATA_DATA16B_SHIFT         (0U)
/*! DATA16B - Data */
#define I3C_MWMSG_DDR_DATA_DATA16B(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_DATA_DATA16B_SHIFT)) & I3C_MWMSG_DDR_DATA_DATA16B_MASK)
/*! @} */

/*! @name MRMSG_DDR - Controller Read Message in DDR mode */
/*! @{ */

#define I3C_MRMSG_DDR_DATA_MASK                  (0xFFFFU)
#define I3C_MRMSG_DDR_DATA_SHIFT                 (0U)
/*! DATA - Data */
#define I3C_MRMSG_DDR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MRMSG_DDR_DATA_SHIFT)) & I3C_MRMSG_DDR_DATA_MASK)
/*! @} */

/*! @name MDYNADDR - Controller Dynamic Address */
/*! @{ */

#define I3C_MDYNADDR_DAVALID_MASK                (0x1U)
#define I3C_MDYNADDR_DAVALID_SHIFT               (0U)
/*! DAVALID - Dynamic Address Valid
 *  0b0..No valid DA assigned
 *  0b1..Valid DA assigned
 */
#define I3C_MDYNADDR_DAVALID(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDYNADDR_DAVALID_SHIFT)) & I3C_MDYNADDR_DAVALID_MASK)

#define I3C_MDYNADDR_DADDR_MASK                  (0xFEU)
#define I3C_MDYNADDR_DADDR_SHIFT                 (1U)
/*! DADDR - Dynamic Address */
#define I3C_MDYNADDR_DADDR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDYNADDR_DADDR_SHIFT)) & I3C_MDYNADDR_DADDR_MASK)
/*! @} */

/*! @name MWDATAW - Write Word Data (to Bus) */
/*! @{ */

#define I3C_MWDATAW_DATA_MASK                    (0xFFFFFFFFU)
#define I3C_MWDATAW_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define I3C_MWDATAW_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAW_DATA_SHIFT)) & I3C_MWDATAW_DATA_MASK)
/*! @} */

/*! @name MRDATAW - Read Word Data (from Bus) */
/*! @{ */

#define I3C_MRDATAW_VALUE_MASK                   (0xFFFFFFFFU)
#define I3C_MRDATAW_VALUE_SHIFT                  (0U)
/*! VALUE - Value */
#define I3C_MRDATAW_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAW_VALUE_SHIFT)) & I3C_MRDATAW_VALUE_MASK)
/*! @} */

/*! @name SMAPCTRL0 - Map Feature Control 0 */
/*! @{ */

#define I3C_SMAPCTRL0_ENA_MASK                   (0x1U)
#define I3C_SMAPCTRL0_ENA_SHIFT                  (0U)
/*! ENA - Enable Primary Dynamic Address
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define I3C_SMAPCTRL0_ENA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_ENA_SHIFT)) & I3C_SMAPCTRL0_ENA_MASK)

#define I3C_SMAPCTRL0_DA_MASK                    (0xFEU)
#define I3C_SMAPCTRL0_DA_SHIFT                   (1U)
/*! DA - Dynamic Address */
#define I3C_SMAPCTRL0_DA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_DA_SHIFT)) & I3C_SMAPCTRL0_DA_MASK)

#define I3C_SMAPCTRL0_CAUSE_MASK                 (0x700U)
#define I3C_SMAPCTRL0_CAUSE_SHIFT                (8U)
/*! CAUSE - Cause
 *  0b000..No information (this value occurs when not configured to write DA)
 *  0b001..Set using ENTDAA
 *  0b010..Set using SETDASA, SETAASA, or SETNEWDA
 *  0b011..Cleared using RSTDAA
 *  0b100..Auto MAP change happened last
 */
#define I3C_SMAPCTRL0_CAUSE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_CAUSE_SHIFT)) & I3C_SMAPCTRL0_CAUSE_MASK)
/*! @} */

/*! @name SMAPCTRL1 - Map Feature Control 1 */
/*! @{ */

#define I3C_SMAPCTRL1_ENA_MASK                   (0x1U)
#define I3C_SMAPCTRL1_ENA_SHIFT                  (0U)
/*! ENA - Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define I3C_SMAPCTRL1_ENA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_ENA_SHIFT)) & I3C_SMAPCTRL1_ENA_MASK)

#define I3C_SMAPCTRL1_ADDR_MASK                  (0xFEU)
#define I3C_SMAPCTRL1_ADDR_SHIFT                 (1U)
/*! ADDR - Address */
#define I3C_SMAPCTRL1_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_ADDR_SHIFT)) & I3C_SMAPCTRL1_ADDR_MASK)

#define I3C_SMAPCTRL1_MAPSA_MASK                 (0x100U)
#define I3C_SMAPCTRL1_MAPSA_SHIFT                (8U)
/*! MAPSA - MAP Static Address
 *  0b0..I3C dynamic address
 *  0b1..Static address (I2C style)
 */
#define I3C_SMAPCTRL1_MAPSA(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_MAPSA_SHIFT)) & I3C_SMAPCTRL1_MAPSA_MASK)

#define I3C_SMAPCTRL1_SA10B_MASK                 (0xE00U)
#define I3C_SMAPCTRL1_SA10B_SHIFT                (9U)
/*! SA10B - Static Address 10-Bit Extension */
#define I3C_SMAPCTRL1_SA10B(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_SA10B_SHIFT)) & I3C_SMAPCTRL1_SA10B_MASK)

#define I3C_SMAPCTRL1_NACK_MASK                  (0x1000U)
#define I3C_SMAPCTRL1_NACK_SHIFT                 (12U)
/*! NACK - Not Acknowledged
 *  0b0..Do not always NACK messages
 *  0b1..Always NACK messages
 */
#define I3C_SMAPCTRL1_NACK(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_NACK_SHIFT)) & I3C_SMAPCTRL1_NACK_MASK)
/*! @} */

/*! @name IBIEXT1 - Extended IBI Data 1 */
/*! @{ */

#define I3C_IBIEXT1_CNT_MASK                     (0x7U)
#define I3C_IBIEXT1_CNT_SHIFT                    (0U)
/*! CNT - Count */
#define I3C_IBIEXT1_CNT(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_CNT_SHIFT)) & I3C_IBIEXT1_CNT_MASK)

#define I3C_IBIEXT1_MAX_MASK                     (0x70U)
#define I3C_IBIEXT1_MAX_SHIFT                    (4U)
/*! MAX - Maximum */
#define I3C_IBIEXT1_MAX(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_MAX_SHIFT)) & I3C_IBIEXT1_MAX_MASK)

#define I3C_IBIEXT1_EXT1_MASK                    (0xFF00U)
#define I3C_IBIEXT1_EXT1_SHIFT                   (8U)
/*! EXT1 - Extra Byte 1 */
#define I3C_IBIEXT1_EXT1(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT1_SHIFT)) & I3C_IBIEXT1_EXT1_MASK)

#define I3C_IBIEXT1_EXT2_MASK                    (0xFF0000U)
#define I3C_IBIEXT1_EXT2_SHIFT                   (16U)
/*! EXT2 - Extra Byte 2 */
#define I3C_IBIEXT1_EXT2(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT2_SHIFT)) & I3C_IBIEXT1_EXT2_MASK)

#define I3C_IBIEXT1_EXT3_MASK                    (0xFF000000U)
#define I3C_IBIEXT1_EXT3_SHIFT                   (24U)
/*! EXT3 - Extra Byte 3 */
#define I3C_IBIEXT1_EXT3(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT3_SHIFT)) & I3C_IBIEXT1_EXT3_MASK)
/*! @} */

/*! @name IBIEXT2 - Extended IBI Data 2 */
/*! @{ */

#define I3C_IBIEXT2_EXT4_MASK                    (0xFFU)
#define I3C_IBIEXT2_EXT4_SHIFT                   (0U)
/*! EXT4 - Extra Byte 4 */
#define I3C_IBIEXT2_EXT4(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT2_EXT4_SHIFT)) & I3C_IBIEXT2_EXT4_MASK)

#define I3C_IBIEXT2_EXT5_MASK                    (0xFF00U)
#define I3C_IBIEXT2_EXT5_SHIFT                   (8U)
/*! EXT5 - Extra Byte 5 */
#define I3C_IBIEXT2_EXT5(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT2_EXT5_SHIFT)) & I3C_IBIEXT2_EXT5_MASK)

#define I3C_IBIEXT2_EXT6_MASK                    (0xFF0000U)
#define I3C_IBIEXT2_EXT6_SHIFT                   (16U)
/*! EXT6 - Extra Byte 6 */
#define I3C_IBIEXT2_EXT6(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT2_EXT6_SHIFT)) & I3C_IBIEXT2_EXT6_MASK)

#define I3C_IBIEXT2_EXT7_MASK                    (0xFF000000U)
#define I3C_IBIEXT2_EXT7_SHIFT                   (24U)
/*! EXT7 - Extra Byte 7 */
#define I3C_IBIEXT2_EXT7(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT2_EXT7_SHIFT)) & I3C_IBIEXT2_EXT7_MASK)
/*! @} */

/*! @name SWDATAW - Target Write Word Data (to Bus) */
/*! @{ */

#define I3C_SWDATAW_DATA_MASK                    (0xFFFFFFFFU)
#define I3C_SWDATAW_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define I3C_SWDATAW_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAW_DATA_SHIFT)) & I3C_SWDATAW_DATA_MASK)
/*! @} */

/*! @name SRDATAW - Target Read Word Data (from Bus) */
/*! @{ */

#define I3C_SRDATAW_VALUE_MASK                   (0xFFFFFFFFU)
#define I3C_SRDATAW_VALUE_SHIFT                  (0U)
/*! VALUE - Value */
#define I3C_SRDATAW_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAW_VALUE_SHIFT)) & I3C_SRDATAW_VALUE_MASK)
/*! @} */

/*! @name SID - Target Module ID */
/*! @{ */

#define I3C_SID_ID_MASK                          (0xFFFFFFFFU)
#define I3C_SID_ID_SHIFT                         (0U)
/*! ID - ID */
#define I3C_SID_ID(x)                            (((uint32_t)(((uint32_t)(x)) << I3C_SID_ID_SHIFT)) & I3C_SID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group I3C_Register_Masks */


/*!
 * @}
 */ /* end of group I3C_Peripheral_Access_Layer */


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


#endif  /* PERI_I3C_H_ */


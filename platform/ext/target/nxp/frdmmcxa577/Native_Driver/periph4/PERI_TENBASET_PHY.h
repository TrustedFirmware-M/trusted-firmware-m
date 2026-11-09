/*
** ###################################################################
**     Processors:          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
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
**         CMSIS Peripheral Access Layer for TENBASET_PHY
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
 * @file PERI_TENBASET_PHY.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TENBASET_PHY
 *
 * CMSIS Peripheral Access Layer for TENBASET_PHY
 */

#if !defined(PERI_TENBASET_PHY_H_)
#define PERI_TENBASET_PHY_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
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
   -- TENBASET_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TENBASET_PHY_Peripheral_Access_Layer TENBASET_PHY Peripheral Access Layer
 * @{
 */

/** TENBASET_PHY - Register Layout Typedef */
typedef struct {
  __IO uint16_t PHYCTRL;                           /**< PHY control, offset: 0x0 */
  __I  uint16_t PHYSTAT;                           /**< PHY status, offset: 0x2 */
  __I  uint16_t PHYID0;                            /**< PHY Identifier0, offset: 0x4 */
  __I  uint16_t PHYID1;                            /**< PHY Identifier1, offset: 0x6 */
       uint8_t RESERVED_0[60];
  __I  uint16_t BASE1EXT;                          /**< PHY BASE-T1 Extended, offset: 0x44 */
       uint8_t RESERVED_1[34];
  __I  uint16_t PMAPMDCTRL;                        /**< PMA/PMD Control, offset: 0x68 */
       uint8_t RESERVED_2[40];
  __IO uint16_t PMACTRL;                           /**< PMA CTRL, offset: 0x92 */
  __I  uint16_t PMASTAT;                           /**< PMA Status, offset: 0x94 */
  __IO uint16_t PMATM;                             /**< PMA Test Mode, offset: 0x96 */
       uint8_t RESERVED_3[14];
  __IO uint16_t PCSCTRL;                           /**< PCS Control, offset: 0xA6 */
  __I  uint16_t PCSSTAT;                           /**< PCS Status, offset: 0xA8 */
  __I  uint16_t PCSDIAG1;                          /**< PCS Remote Jabber Counter, offset: 0xAA */
  __I  uint16_t PCSDIAG2;                          /**< PCS Physical Collisions Counter, offset: 0xAC */
       uint8_t RESERVED_4[18];
  __I  uint16_t PLCAIDVER;                         /**< PLCA Identification and Version, offset: 0xC0 */
  __IO uint16_t PLCACTRL0;                         /**< PLCA Control0, offset: 0xC2 */
  __IO uint16_t PLCACTRL1;                         /**< PLCA Control1, offset: 0xC4 */
  __I  uint16_t PLCASTAT;                          /**< PLCA Status, offset: 0xC6 */
  __IO uint16_t PLCATOTMR;                         /**< PLCA Transmit Opportunity Timer, offset: 0xC8 */
  __IO uint16_t PLCABURST;                         /**< PLCA Burst Mode Configuration, offset: 0xCA */
  __I  uint16_t PLCARECST;                         /**< PLCA Status, offset: 0xCC */
       uint8_t RESERVED_5[50];
  __IO uint16_t MODECTRL;                          /**< MODE Control, offset: 0x100 */
  __IO uint16_t MODECFG;                           /**< Mode Configuration, offset: 0x102 */
  __I  uint16_t MODESTAT;                          /**< Mode Status, offset: 0x104 */
       uint8_t RESERVED_6[26];
  __IO uint16_t WKCTRL;                            /**< Wake Control, offset: 0x120 */
  __IO uint16_t WKCFG;                             /**< Wake Configuration, offset: 0x122 */
       uint8_t RESERVED_7[2];
  __IO uint16_t WUPCTRL;                           /**< Wake Control, offset: 0x126 */
  __IO uint16_t WUPCFG;                            /**< Wakeup Configuration, offset: 0x128 */
  __I  uint16_t WUPSTAT;                           /**< Wakeup Status, offset: 0x12A */
       uint8_t RESERVED_8[20];
  __IO uint16_t SMIDATA;                           /**< SMI Frame DATA, offset: 0x140 */
  __IO uint16_t SMICTRL;                           /**< SMI Control, offset: 0x142 */
  __IO uint16_t SMICFG;                            /**< SMI Configuration, offset: 0x144 */
  __I  uint16_t SMISTAT;                           /**< SMI Status, offset: 0x146 */
       uint8_t RESERVED_9[24];
  __IO uint16_t INTENCAPT1;                        /**< Interrupt Capture1, offset: 0x160 */
  __IO uint16_t INTENSET1;                         /**< Interrupt Enable Set1, offset: 0x162 */
  __IO uint16_t INTENCLR1;                         /**< Interrupt Enable Clear1, offset: 0x164 */
  __I  uint16_t INTSTAT1;                          /**< Interrupt Status1, offset: 0x166 */
       uint8_t RESERVED_10[8];
  __IO uint16_t INTENCAPT2;                        /**< Interrupt Capture2, offset: 0x170 */
  __IO uint16_t INTENSET2;                         /**< Interrupt Enable Set1, offset: 0x172 */
  __IO uint16_t INTENCLR2;                         /**< Interrupt Enable Clear2, offset: 0x174 */
  __I  uint16_t INTSTAT2;                          /**< Interrupt Status2, offset: 0x176 */
       uint8_t RESERVED_11[40];
  __IO uint16_t PLCADIAG1;                         /**< PLCA TC14 Adv diagnostics, offset: 0x1A0 */
  __IO uint16_t PLCADIAG2;                         /**< PLCA NXP prop diagnostics, offset: 0x1A2 */
  __IO uint16_t PLCADIAG3;                         /**< PLCA Beacon Counter Diagnostics, offset: 0x1A4 */
  __IO uint16_t PLCADIAG4;                         /**< PLCA TO Counter Diagnostics, offset: 0x1A6 */
  __IO uint16_t TXCDIAG;                           /**< Transceiver Diagnostics, offset: 0x1A8 */
       uint8_t RESERVED_12[6];
  __IO uint16_t MSKPLCADIAG1;                      /**< Mask Control PLCADIAG1 Flag, offset: 0x1B0 */
  __IO uint16_t MSKPLCADIAG2;                      /**< Mask Control PLCADIAG2 Flags, offset: 0x1B2 */
  __IO uint16_t MSKTXCDIAG;                        /**< Mask Control TXCDIAG Flag, offset: 0x1B4 */
       uint8_t RESERVED_13[42];
  __IO uint16_t ACCESSCTRL;                        /**< Global Access Control, offset: 0x1E0 */
  __IO uint16_t DBGCTRL;                           /**< Debug Control, offset: 0x1E2 */
       uint8_t RESERVED_14[26];
  __I  uint16_t VERSION;                           /**< Version Information, offset: 0x1FE */
} TENBASET_PHY_Type;

/* ----------------------------------------------------------------------------
   -- TENBASET_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TENBASET_PHY_Register_Masks TENBASET_PHY Register Masks
 * @{
 */

/*! @name PHYCTRL - PHY control */
/*! @{ */

#define TENBASET_PHY_PHYCTRL_SPD1_MASK           (0x40U)
#define TENBASET_PHY_PHYCTRL_SPD1_SHIFT          (6U)
/*! SPD1 - Speed Selection1 */
#define TENBASET_PHY_PHYCTRL_SPD1(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_SPD1_SHIFT)) & TENBASET_PHY_PHYCTRL_SPD1_MASK)

#define TENBASET_PHY_PHYCTRL_CTEST_MASK          (0x80U)
#define TENBASET_PHY_PHYCTRL_CTEST_SHIFT         (7U)
/*! CTEST - Collision Test */
#define TENBASET_PHY_PHYCTRL_CTEST(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_CTEST_SHIFT)) & TENBASET_PHY_PHYCTRL_CTEST_MASK)

#define TENBASET_PHY_PHYCTRL_DUPLX_MASK          (0x100U)
#define TENBASET_PHY_PHYCTRL_DUPLX_SHIFT         (8U)
/*! DUPLX - Duplex Mode */
#define TENBASET_PHY_PHYCTRL_DUPLX(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_DUPLX_SHIFT)) & TENBASET_PHY_PHYCTRL_DUPLX_MASK)

#define TENBASET_PHY_PHYCTRL_SPD0_MASK           (0x2000U)
#define TENBASET_PHY_PHYCTRL_SPD0_SHIFT          (13U)
/*! SPD0 - Speed Selection0 */
#define TENBASET_PHY_PHYCTRL_SPD0(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_SPD0_SHIFT)) & TENBASET_PHY_PHYCTRL_SPD0_MASK)

#define TENBASET_PHY_PHYCTRL_RESET_MASK          (0x8000U)
#define TENBASET_PHY_PHYCTRL_RESET_SHIFT         (15U)
/*! RESET - RESET */
#define TENBASET_PHY_PHYCTRL_RESET(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_RESET_SHIFT)) & TENBASET_PHY_PHYCTRL_RESET_MASK)
/*! @} */

/*! @name PHYSTAT - PHY status */
/*! @{ */

#define TENBASET_PHY_PHYSTAT_LJAB_MASK           (0x2U)
#define TENBASET_PHY_PHYSTAT_LJAB_SHIFT          (1U)
/*! LJAB - Local Jabber */
#define TENBASET_PHY_PHYSTAT_LJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYSTAT_LJAB_SHIFT)) & TENBASET_PHY_PHYSTAT_LJAB_MASK)

#define TENBASET_PHY_PHYSTAT_RJAB_MASK           (0x10U)
#define TENBASET_PHY_PHYSTAT_RJAB_SHIFT          (4U)
/*! RJAB - Remote Jabber */
#define TENBASET_PHY_PHYSTAT_RJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYSTAT_RJAB_SHIFT)) & TENBASET_PHY_PHYSTAT_RJAB_MASK)
/*! @} */

/*! @name PHYID0 - PHY Identifier0 */
/*! @{ */

#define TENBASET_PHY_PHYID0_OUI_03_18_MASK       (0xFFFFU)
#define TENBASET_PHY_PHYID0_OUI_03_18_SHIFT      (0U)
/*! OUI_03_18 - Organizationally Unique Identifier */
#define TENBASET_PHY_PHYID0_OUI_03_18(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID0_OUI_03_18_SHIFT)) & TENBASET_PHY_PHYID0_OUI_03_18_MASK)
/*! @} */

/*! @name PHYID1 - PHY Identifier1 */
/*! @{ */

#define TENBASET_PHY_PHYID1_ICREVISION_MASK      (0xFU)
#define TENBASET_PHY_PHYID1_ICREVISION_SHIFT     (0U)
/*! ICREVISION - IC Model Revision */
#define TENBASET_PHY_PHYID1_ICREVISION(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_ICREVISION_SHIFT)) & TENBASET_PHY_PHYID1_ICREVISION_MASK)

#define TENBASET_PHY_PHYID1_ICMODEL_MASK         (0x3F0U)
#define TENBASET_PHY_PHYID1_ICMODEL_SHIFT        (4U)
/*! ICMODEL - IC Model Identifier */
#define TENBASET_PHY_PHYID1_ICMODEL(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_ICMODEL_SHIFT)) & TENBASET_PHY_PHYID1_ICMODEL_MASK)

#define TENBASET_PHY_PHYID1_OUI_19_24_MASK       (0xFC00U)
#define TENBASET_PHY_PHYID1_OUI_19_24_SHIFT      (10U)
/*! OUI_19_24 - Organizationally Unique Identifier */
#define TENBASET_PHY_PHYID1_OUI_19_24(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_OUI_19_24_SHIFT)) & TENBASET_PHY_PHYID1_OUI_19_24_MASK)
/*! @} */

/*! @name BASE1EXT - PHY BASE-T1 Extended */
/*! @{ */

#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_MASK (0xFFFFU)
#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_SHIFT (0U)
/*! BASET1EXT_BIT - Capability Info */
#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT(x)   (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_SHIFT)) & TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_MASK)
/*! @} */

/*! @name PMAPMDCTRL - PMA/PMD Control */
/*! @{ */

#define TENBASET_PHY_PMAPMDCTRL_TYPE_MASK        (0xFU)
#define TENBASET_PHY_PMAPMDCTRL_TYPE_SHIFT       (0U)
/*! TYPE - Type
 *  0b0000..CBT1
 *  0b0001..MBT1
 *  0b0010..XBT1L
 *  0b0011..XBT1S
 */
#define TENBASET_PHY_PMAPMDCTRL_TYPE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMAPMDCTRL_TYPE_SHIFT)) & TENBASET_PHY_PMAPMDCTRL_TYPE_MASK)
/*! @} */

/*! @name PMACTRL - PMA CTRL */
/*! @{ */

#define TENBASET_PHY_PMACTRL_LOOP_MASK           (0x1U)
#define TENBASET_PHY_PMACTRL_LOOP_SHIFT          (0U)
/*! LOOP - Loop
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_PMACTRL_LOOP(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_LOOP_SHIFT)) & TENBASET_PHY_PMACTRL_LOOP_MASK)

#define TENBASET_PHY_PMACTRL_MULT_MASK           (0x400U)
#define TENBASET_PHY_PMACTRL_MULT_SHIFT          (10U)
/*! MULT - Multidrop Configuration */
#define TENBASET_PHY_PMACTRL_MULT(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_MULT_SHIFT)) & TENBASET_PHY_PMACTRL_MULT_MASK)

#define TENBASET_PHY_PMACTRL_TXDIS_MASK          (0x4000U)
#define TENBASET_PHY_PMACTRL_TXDIS_SHIFT         (14U)
/*! TXDIS - Transmission Disable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_PMACTRL_TXDIS(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_TXDIS_SHIFT)) & TENBASET_PHY_PMACTRL_TXDIS_MASK)

#define TENBASET_PHY_PMACTRL_RST_MASK            (0x8000U)
#define TENBASET_PHY_PMACTRL_RST_SHIFT           (15U)
/*! RST - Reset */
#define TENBASET_PHY_PMACTRL_RST(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_RST_SHIFT)) & TENBASET_PHY_PMACTRL_RST_MASK)
/*! @} */

/*! @name PMASTAT - PMA Status */
/*! @{ */

#define TENBASET_PHY_PMASTAT_RJAB_MASK           (0x2U)
#define TENBASET_PHY_PMASTAT_RJAB_SHIFT          (1U)
/*! RJAB - RJAB Alias */
#define TENBASET_PHY_PMASTAT_RJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_RJAB_SHIFT)) & TENBASET_PHY_PMASTAT_RJAB_MASK)

#define TENBASET_PHY_PMASTAT_RFLTA_MASK          (0x200U)
#define TENBASET_PHY_PMASTAT_RFLTA_SHIFT         (9U)
/*! RFLTA - Receive Fault Advertises */
#define TENBASET_PHY_PMASTAT_RFLTA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_RFLTA_SHIFT)) & TENBASET_PHY_PMASTAT_RFLTA_MASK)

#define TENBASET_PHY_PMASTAT_MULTA_MASK          (0x400U)
#define TENBASET_PHY_PMASTAT_MULTA_SHIFT         (10U)
/*! MULTA - Multidrop Advertises */
#define TENBASET_PHY_PMASTAT_MULTA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_MULTA_SHIFT)) & TENBASET_PHY_PMASTAT_MULTA_MASK)

#define TENBASET_PHY_PMASTAT_LPWA_MASK           (0x800U)
#define TENBASET_PHY_PMASTAT_LPWA_SHIFT          (11U)
/*! LPWA - Low Power Advertise */
#define TENBASET_PHY_PMASTAT_LPWA(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_LPWA_SHIFT)) & TENBASET_PHY_PMASTAT_LPWA_MASK)

#define TENBASET_PHY_PMASTAT_LOOPA_MASK          (0x2000U)
#define TENBASET_PHY_PMASTAT_LOOPA_SHIFT         (13U)
/*! LOOPA - Loopback Advertise */
#define TENBASET_PHY_PMASTAT_LOOPA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_LOOPA_SHIFT)) & TENBASET_PHY_PMASTAT_LOOPA_MASK)
/*! @} */

/*! @name PMATM - PMA Test Mode */
/*! @{ */

#define TENBASET_PHY_PMATM_PATTERN_MASK          (0xE000U)
#define TENBASET_PHY_PMATM_PATTERN_SHIFT         (13U)
/*! PATTERN - Pattern
 *  0b000..NONE
 *  0b001..TM1
 *  0b010..TM2
 *  0b011..TM3
 *  0b100..TM4
 *  0b101..RES0
 *  0b110..RES1
 *  0b111..WUT
 */
#define TENBASET_PHY_PMATM_PATTERN(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMATM_PATTERN_SHIFT)) & TENBASET_PHY_PMATM_PATTERN_MASK)
/*! @} */

/*! @name PCSCTRL - PCS Control */
/*! @{ */

#define TENBASET_PHY_PCSCTRL_DUPLX_MASK          (0x100U)
#define TENBASET_PHY_PCSCTRL_DUPLX_SHIFT         (8U)
/*! DUPLX - Duplex */
#define TENBASET_PHY_PCSCTRL_DUPLX(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_DUPLX_SHIFT)) & TENBASET_PHY_PCSCTRL_DUPLX_MASK)

#define TENBASET_PHY_PCSCTRL_LOOP_MASK           (0x4000U)
#define TENBASET_PHY_PCSCTRL_LOOP_SHIFT          (14U)
/*! LOOP - Loop
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_PCSCTRL_LOOP(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_LOOP_SHIFT)) & TENBASET_PHY_PCSCTRL_LOOP_MASK)

#define TENBASET_PHY_PCSCTRL_RST_MASK            (0x8000U)
#define TENBASET_PHY_PCSCTRL_RST_SHIFT           (15U)
/*! RST - Reset
 *  0b0..STAT_NO_RESET
 *  0b1..STAT_RESET
 */
#define TENBASET_PHY_PCSCTRL_RST(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_RST_SHIFT)) & TENBASET_PHY_PCSCTRL_RST_MASK)
/*! @} */

/*! @name PCSSTAT - PCS Status */
/*! @{ */

#define TENBASET_PHY_PCSSTAT_JAB_MASK            (0x80U)
#define TENBASET_PHY_PCSSTAT_JAB_SHIFT           (7U)
/*! JAB - Jabber condition
 *  0b0..No
 *  0b1..Yes
 */
#define TENBASET_PHY_PCSSTAT_JAB(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSSTAT_JAB_SHIFT)) & TENBASET_PHY_PCSSTAT_JAB_MASK)
/*! @} */

/*! @name PCSDIAG1 - PCS Remote Jabber Counter */
/*! @{ */

#define TENBASET_PHY_PCSDIAG1_REMJABCNT_MASK     (0xFFFFU)
#define TENBASET_PHY_PCSDIAG1_REMJABCNT_SHIFT    (0U)
/*! REMJABCNT - Remote Jabber Counter */
#define TENBASET_PHY_PCSDIAG1_REMJABCNT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSDIAG1_REMJABCNT_SHIFT)) & TENBASET_PHY_PCSDIAG1_REMJABCNT_MASK)
/*! @} */

/*! @name PCSDIAG2 - PCS Physical Collisions Counter */
/*! @{ */

#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT_MASK     (0xFFFFU)
#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT_SHIFT    (0U)
/*! PHYCOLCNT - Physical Collisions Counter */
#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSDIAG2_PHYCOLCNT_SHIFT)) & TENBASET_PHY_PCSDIAG2_PHYCOLCNT_MASK)
/*! @} */

/*! @name PLCAIDVER - PLCA Identification and Version */
/*! @{ */

#define TENBASET_PHY_PLCAIDVER_VER_MASK          (0xFFU)
#define TENBASET_PHY_PLCAIDVER_VER_SHIFT         (0U)
/*! VER - Version */
#define TENBASET_PHY_PLCAIDVER_VER(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCAIDVER_VER_SHIFT)) & TENBASET_PHY_PLCAIDVER_VER_MASK)

#define TENBASET_PHY_PLCAIDVER_IDM_MASK          (0xFF00U)
#define TENBASET_PHY_PLCAIDVER_IDM_SHIFT         (8U)
/*! IDM - OA memory map identifier */
#define TENBASET_PHY_PLCAIDVER_IDM(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCAIDVER_IDM_SHIFT)) & TENBASET_PHY_PLCAIDVER_IDM_MASK)
/*! @} */

/*! @name PLCACTRL0 - PLCA Control0 */
/*! @{ */

#define TENBASET_PHY_PLCACTRL0_RST_MASK          (0x4000U)
#define TENBASET_PHY_PLCACTRL0_RST_SHIFT         (14U)
/*! RST - Reset */
#define TENBASET_PHY_PLCACTRL0_RST(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL0_RST_SHIFT)) & TENBASET_PHY_PLCACTRL0_RST_MASK)

#define TENBASET_PHY_PLCACTRL0_EN_MASK           (0x8000U)
#define TENBASET_PHY_PLCACTRL0_EN_SHIFT          (15U)
/*! EN - Enable */
#define TENBASET_PHY_PLCACTRL0_EN(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL0_EN_SHIFT)) & TENBASET_PHY_PLCACTRL0_EN_MASK)
/*! @} */

/*! @name PLCACTRL1 - PLCA Control1 */
/*! @{ */

#define TENBASET_PHY_PLCACTRL1_ID_MASK           (0xFFU)
#define TENBASET_PHY_PLCACTRL1_ID_SHIFT          (0U)
/*! ID - Identifier */
#define TENBASET_PHY_PLCACTRL1_ID(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL1_ID_SHIFT)) & TENBASET_PHY_PLCACTRL1_ID_MASK)

#define TENBASET_PHY_PLCACTRL1_NCNT_MASK         (0xFF00U)
#define TENBASET_PHY_PLCACTRL1_NCNT_SHIFT        (8U)
/*! NCNT - PLCA Node count */
#define TENBASET_PHY_PLCACTRL1_NCNT(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL1_NCNT_SHIFT)) & TENBASET_PHY_PLCACTRL1_NCNT_MASK)
/*! @} */

/*! @name PLCASTAT - PLCA Status */
/*! @{ */

#define TENBASET_PHY_PLCASTAT_PST_MASK           (0x8000U)
#define TENBASET_PHY_PLCASTAT_PST_SHIFT          (15U)
/*! PST - PLCA Node status */
#define TENBASET_PHY_PLCASTAT_PST(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCASTAT_PST_SHIFT)) & TENBASET_PHY_PLCASTAT_PST_MASK)
/*! @} */

/*! @name PLCATOTMR - PLCA Transmit Opportunity Timer */
/*! @{ */

#define TENBASET_PHY_PLCATOTMR_TOTMR_MASK        (0xFFU)
#define TENBASET_PHY_PLCATOTMR_TOTMR_SHIFT       (0U)
/*! TOTMR - PLCA Transmit Opportunity */
#define TENBASET_PHY_PLCATOTMR_TOTMR(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCATOTMR_TOTMR_SHIFT)) & TENBASET_PHY_PLCATOTMR_TOTMR_MASK)
/*! @} */

/*! @name PLCABURST - PLCA Burst Mode Configuration */
/*! @{ */

#define TENBASET_PHY_PLCABURST_BTMR_MASK         (0xFFU)
#define TENBASET_PHY_PLCABURST_BTMR_SHIFT        (0U)
/*! BTMR - Burst Timer */
#define TENBASET_PHY_PLCABURST_BTMR(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCABURST_BTMR_SHIFT)) & TENBASET_PHY_PLCABURST_BTMR_MASK)

#define TENBASET_PHY_PLCABURST_MAXBC_MASK        (0xFF00U)
#define TENBASET_PHY_PLCABURST_MAXBC_SHIFT       (8U)
/*! MAXBC - Maximum Burst Count */
#define TENBASET_PHY_PLCABURST_MAXBC(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCABURST_MAXBC_SHIFT)) & TENBASET_PHY_PLCABURST_MAXBC_MASK)
/*! @} */

/*! @name PLCARECST - PLCA Status */
/*! @{ */

#define TENBASET_PHY_PLCARECST_RECST_MASK        (0x8000U)
#define TENBASET_PHY_PLCARECST_RECST_SHIFT       (15U)
/*! RECST - Recovering Status */
#define TENBASET_PHY_PLCARECST_RECST(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCARECST_RECST_SHIFT)) & TENBASET_PHY_PLCARECST_RECST_MASK)
/*! @} */

/*! @name MODECTRL - MODE Control */
/*! @{ */

#define TENBASET_PHY_MODECTRL_CMD_MASK           (0x7U)
#define TENBASET_PHY_MODECTRL_CMD_SHIFT          (0U)
/*! CMD - Set back to NONE when mode controller has entered the selected mode
 *  0b000..None
 *  0b001..Linkdown
 *  0b010..Linkup
 *  0b011..TXCCFG
 *  0b100..Low-power
 *  0b101..TXCBIST
 */
#define TENBASET_PHY_MODECTRL_CMD(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECTRL_CMD_SHIFT)) & TENBASET_PHY_MODECTRL_CMD_MASK)
/*! @} */

/*! @name MODECFG - Mode Configuration */
/*! @{ */

#define TENBASET_PHY_MODECFG_LCLWKENA_MASK       (0x1U)
#define TENBASET_PHY_MODECFG_LCLWKENA_SHIFT      (0U)
/*! LCLWKENA - Enable wake-up to WAITINIT mode by local-wake-event
 *  0b0..Disable
 *  0b1..Enable
 */
#define TENBASET_PHY_MODECFG_LCLWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_LCLWKENA_SHIFT)) & TENBASET_PHY_MODECFG_LCLWKENA_MASK)

#define TENBASET_PHY_MODECFG_REMWKENA_MASK       (0x2U)
#define TENBASET_PHY_MODECFG_REMWKENA_SHIFT      (1U)
/*! REMWKENA - Enable wake-up to WAITINIT mode by remote-wake-event
 *  0b0..Disable
 *  0b1..Enable
 */
#define TENBASET_PHY_MODECFG_REMWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_REMWKENA_SHIFT)) & TENBASET_PHY_MODECFG_REMWKENA_MASK)

#define TENBASET_PHY_MODECFG_SSPWKENA_MASK       (0x4U)
#define TENBASET_PHY_MODECFG_SSPWKENA_SHIFT      (2U)
/*! SSPWKENA - Enable wake-up to WAITINIT mode by SUSPEND detection
 *  0b0..Disable
 *  0b1..Enable
 */
#define TENBASET_PHY_MODECFG_SSPWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_SSPWKENA_SHIFT)) & TENBASET_PHY_MODECFG_SSPWKENA_MASK)
/*! @} */

/*! @name MODESTAT - Mode Status */
/*! @{ */

#define TENBASET_PHY_MODESTAT_STAT_MASK          (0xFU)
#define TENBASET_PHY_MODESTAT_STAT_SHIFT         (0U)
/*! STAT - Status power-mode sequencer
 *  0b0000..PORST
 *  0b0001..WAITINIT
 *  0b0010..Linkdown
 *  0b0011..Linkup
 *  0b0100..WAITCMDLP
 *  0b0101..Low-power
 *  0b0110..WAITCMDCFG
 *  0b0111..TXCCFG
 *  0b1000..TXCBIST
 *  0b1001..WAITSSILENTLP
 *  0b1010..WAITSILENTCFG
 */
#define TENBASET_PHY_MODESTAT_STAT(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODESTAT_STAT_SHIFT)) & TENBASET_PHY_MODESTAT_STAT_MASK)

#define TENBASET_PHY_MODESTAT_SILENTTO_MASK      (0x10U)
#define TENBASET_PHY_MODESTAT_SILENTTO_SHIFT     (4U)
/*! SILENTTO - Silent Time-out condition
 *  0b0..No
 *  0b1..Yes
 */
#define TENBASET_PHY_MODESTAT_SILENTTO(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODESTAT_SILENTTO_SHIFT)) & TENBASET_PHY_MODESTAT_SILENTTO_MASK)
/*! @} */

/*! @name WKCTRL - Wake Control */
/*! @{ */

#define TENBASET_PHY_WKCTRL_REMWKFDW_MASK        (0x1U)
#define TENBASET_PHY_WKCTRL_REMWKFDW_SHIFT       (0U)
/*! REMWKFDW - Command to generate a wake-forward pulse
 *  0b0..NO_EFFECT
 *  0b1..Trigger generation of a wake-forward pulse
 */
#define TENBASET_PHY_WKCTRL_REMWKFDW(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WKCTRL_REMWKFDW_SHIFT)) & TENBASET_PHY_WKCTRL_REMWKFDW_MASK)
/*! @} */

/*! @name WKCFG - Wake Configuration */
/*! @{ */

#define TENBASET_PHY_WKCFG_REMKWKFDW_MASK        (0x1U)
#define TENBASET_PHY_WKCFG_REMKWKFDW_SHIFT       (0U)
/*! REMKWKFDW - Enable wake forwarding of a remote-wake-event
 *  0b0..DISABLED
 *  0b1..ENABLED
 */
#define TENBASET_PHY_WKCFG_REMKWKFDW(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WKCFG_REMKWKFDW_SHIFT)) & TENBASET_PHY_WKCFG_REMKWKFDW_MASK)
/*! @} */

/*! @name WUPCTRL - Wake Control */
/*! @{ */

#define TENBASET_PHY_WUPCTRL_WUPCMD_MASK         (0x1U)
#define TENBASET_PHY_WUPCTRL_WUPCMD_SHIFT        (0U)
/*! WUPCMD - Trigger the WUP sequencer transmission
 *  0b0..NO_EFFECT
 *  0b1..Trigger WUP-sequencer
 */
#define TENBASET_PHY_WUPCTRL_WUPCMD(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCTRL_WUPCMD_SHIFT)) & TENBASET_PHY_WUPCTRL_WUPCMD_MASK)

#define TENBASET_PHY_WUPCTRL_ABORTCMD_MASK       (0x2U)
#define TENBASET_PHY_WUPCTRL_ABORTCMD_SHIFT      (1U)
/*! ABORTCMD - Abort the WUP sequencer when pending.
 *  0b0..NO_EFFECT
 *  0b1..Abort WUP-sequencer
 */
#define TENBASET_PHY_WUPCTRL_ABORTCMD(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCTRL_ABORTCMD_SHIFT)) & TENBASET_PHY_WUPCTRL_ABORTCMD_MASK)
/*! @} */

/*! @name WUPCFG - Wakeup Configuration */
/*! @{ */

#define TENBASET_PHY_WUPCFG_LCLWKWUP_MASK        (0x1U)
#define TENBASET_PHY_WUPCFG_LCLWKWUP_SHIFT       (0U)
/*! LCLWKWUP - Enable WUP transmission by local-wake-event
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_WUPCFG_LCLWKWUP(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCFG_LCLWKWUP_SHIFT)) & TENBASET_PHY_WUPCFG_LCLWKWUP_MASK)

#define TENBASET_PHY_WUPCFG_WUPTIMEOUT_MASK      (0xFF00U)
#define TENBASET_PHY_WUPCFG_WUPTIMEOUT_SHIFT     (8U)
/*! WUPTIMEOUT - Wakeup Timeout */
#define TENBASET_PHY_WUPCFG_WUPTIMEOUT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCFG_WUPTIMEOUT_SHIFT)) & TENBASET_PHY_WUPCFG_WUPTIMEOUT_MASK)
/*! @} */

/*! @name WUPSTAT - Wakeup Status */
/*! @{ */

#define TENBASET_PHY_WUPSTAT_STAT_MASK           (0x3U)
#define TENBASET_PHY_WUPSTAT_STAT_SHIFT          (0U)
/*! STAT - Status
 *  0b00..IDLE
 *  0b01..WAITLINK
 *  0b10..PENDING
 *  0b11..TRANSMIT
 */
#define TENBASET_PHY_WUPSTAT_STAT(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPSTAT_STAT_SHIFT)) & TENBASET_PHY_WUPSTAT_STAT_MASK)

#define TENBASET_PHY_WUPSTAT_ERRCODE_MASK        (0x1CU)
#define TENBASET_PHY_WUPSTAT_ERRCODE_SHIFT       (2U)
/*! ERRCODE - Error code
 *  0b000..NONE
 *  0b001..SWABORT
 *  0b010..MODECHG
 *  0b011..TOWM
 *  0b100..TOPD
 *  0b101..TOWP
 *  0b110..TOWA
 *  0b111..CORE
 */
#define TENBASET_PHY_WUPSTAT_ERRCODE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPSTAT_ERRCODE_SHIFT)) & TENBASET_PHY_WUPSTAT_ERRCODE_MASK)
/*! @} */

/*! @name SMIDATA - SMI Frame DATA */
/*! @{ */

#define TENBASET_PHY_SMIDATA_DATA_MASK           (0xFFFFU)
#define TENBASET_PHY_SMIDATA_DATA_SHIFT          (0U)
/*! DATA - Frame Data */
#define TENBASET_PHY_SMIDATA_DATA(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMIDATA_DATA_SHIFT)) & TENBASET_PHY_SMIDATA_DATA_MASK)
/*! @} */

/*! @name SMICTRL - SMI Control */
/*! @{ */

#define TENBASET_PHY_SMICTRL_TA_MASK             (0x3U)
#define TENBASET_PHY_SMICTRL_TA_SHIFT            (0U)
/*! TA - Turn Around */
#define TENBASET_PHY_SMICTRL_TA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_TA_SHIFT)) & TENBASET_PHY_SMICTRL_TA_MASK)

#define TENBASET_PHY_SMICTRL_RA_MASK             (0x7CU)
#define TENBASET_PHY_SMICTRL_RA_SHIFT            (2U)
/*! RA - Register Address */
#define TENBASET_PHY_SMICTRL_RA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_RA_SHIFT)) & TENBASET_PHY_SMICTRL_RA_MASK)

#define TENBASET_PHY_SMICTRL_PA_MASK             (0xF80U)
#define TENBASET_PHY_SMICTRL_PA_SHIFT            (7U)
/*! PA - PHY Address */
#define TENBASET_PHY_SMICTRL_PA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_PA_SHIFT)) & TENBASET_PHY_SMICTRL_PA_MASK)

#define TENBASET_PHY_SMICTRL_OP_MASK             (0x3000U)
#define TENBASET_PHY_SMICTRL_OP_SHIFT            (12U)
/*! OP - Operation
 *  0b00..WRITE_COMPERR
 *  0b01..WRITE
 *  0b10..READ
 *  0b11..READ_COMPERR
 */
#define TENBASET_PHY_SMICTRL_OP(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_OP_SHIFT)) & TENBASET_PHY_SMICTRL_OP_MASK)

#define TENBASET_PHY_SMICTRL_ST_MASK             (0xC000U)
#define TENBASET_PHY_SMICTRL_ST_SHIFT            (14U)
/*! ST - Start */
#define TENBASET_PHY_SMICTRL_ST(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_ST_SHIFT)) & TENBASET_PHY_SMICTRL_ST_MASK)
/*! @} */

/*! @name SMICFG - SMI Configuration */
/*! @{ */

#define TENBASET_PHY_SMICFG_SPEED_MASK           (0x7EU)
#define TENBASET_PHY_SMICFG_SPEED_SHIFT          (1U)
/*! SPEED - Speed */
#define TENBASET_PHY_SMICFG_SPEED(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_SPEED_SHIFT)) & TENBASET_PHY_SMICFG_SPEED_MASK)

#define TENBASET_PHY_SMICFG_DISPRE_MASK          (0x80U)
#define TENBASET_PHY_SMICFG_DISPRE_SHIFT         (7U)
/*! DISPRE - Disable SMI Preamble
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_SMICFG_DISPRE(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_DISPRE_SHIFT)) & TENBASET_PHY_SMICFG_DISPRE_MASK)

#define TENBASET_PHY_SMICFG_HOLD_MASK            (0x700U)
#define TENBASET_PHY_SMICFG_HOLD_SHIFT           (8U)
/*! HOLD - Hold
 *  0b000..HOLD_1
 *  0b001..HOLD_2
 *  0b010..HOLD_3
 *  0b011..HOLD_4
 *  0b100..HOLD_5
 *  0b101..6 PCLK cycles 6
 *  0b110..HOLD_7
 *  0b111..HOLD_8
 */
#define TENBASET_PHY_SMICFG_HOLD(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_HOLD_SHIFT)) & TENBASET_PHY_SMICFG_HOLD_MASK)
/*! @} */

/*! @name SMISTAT - SMI Status */
/*! @{ */

#define TENBASET_PHY_SMISTAT_READY_MASK          (0x1U)
#define TENBASET_PHY_SMISTAT_READY_SHIFT         (0U)
/*! READY - Ready
 *  0b0..No
 *  0b1..Yes
 */
#define TENBASET_PHY_SMISTAT_READY(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMISTAT_READY_SHIFT)) & TENBASET_PHY_SMISTAT_READY_MASK)

#define TENBASET_PHY_SMISTAT_ERRCODE_MASK        (0xEU)
#define TENBASET_PHY_SMISTAT_ERRCODE_SHIFT       (1U)
/*! ERRCODE - Error Code
 *  0b000..NONE
 *  0b001..NONTC14
 *  0b010..Disabled
 *  0b011..ABORTED
 *  0b100..INPRGS
 */
#define TENBASET_PHY_SMISTAT_ERRCODE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMISTAT_ERRCODE_SHIFT)) & TENBASET_PHY_SMISTAT_ERRCODE_MASK)
/*! @} */

/*! @name INTENCAPT1 - Interrupt Capture1 */
/*! @{ */

#define TENBASET_PHY_INTENCAPT1_PHYSCOL_MASK     (0x1U)
#define TENBASET_PHY_INTENCAPT1_PHYSCOL_SHIFT    (0U)
/*! PHYSCOL - Physical Collision
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_PHYSCOL(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCAPT1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCAREC_MASK     (0x2U)
#define TENBASET_PHY_INTENCAPT1_PLCAREC_SHIFT    (1U)
/*! PLCAREC - PLCA Recovery
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_PLCAREC(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCAREC_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCASTAT_MASK    (0x4U)
#define TENBASET_PHY_INTENCAPT1_PLCASTAT_SHIFT   (2U)
/*! PLCASTAT - PLCA Status
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_PLCASTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCAPT1_MODESTAT_MASK    (0x8U)
#define TENBASET_PHY_INTENCAPT1_MODESTAT_SHIFT   (3U)
/*! MODESTAT - MODE Status
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_MODESTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCAPT1_MODESTAT_MASK)

#define TENBASET_PHY_INTENCAPT1_INVLDAPB_MASK    (0x10U)
#define TENBASET_PHY_INTENCAPT1_INVLDAPB_SHIFT   (4U)
/*! INVLDAPB - Invalid APB
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_INVLDAPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCAPT1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCAPT1_LOCJAB_MASK      (0x20U)
#define TENBASET_PHY_INTENCAPT1_LOCJAB_SHIFT     (5U)
/*! LOCJAB - Local Jabber
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_LOCJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCAPT1_LOCJAB_MASK)

#define TENBASET_PHY_INTENCAPT1_REMJAB_MASK      (0x40U)
#define TENBASET_PHY_INTENCAPT1_REMJAB_SHIFT     (6U)
/*! REMJAB - Remote Jabber
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_REMJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_REMJAB_SHIFT)) & TENBASET_PHY_INTENCAPT1_REMJAB_MASK)

#define TENBASET_PHY_INTENCAPT1_PINFAULT_MASK    (0x80U)
#define TENBASET_PHY_INTENCAPT1_PINFAULT_SHIFT   (7U)
/*! PINFAULT - PIN Fault Monitor
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_PINFAULT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCAPT1_PINFAULT_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCADIAG_MASK    (0x100U)
#define TENBASET_PHY_INTENCAPT1_PLCADIAG_SHIFT   (8U)
/*! PLCADIAG - PLCA Diagnostics
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_PLCADIAG(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCAPT1_SMIACCESS_MASK   (0x200U)
#define TENBASET_PHY_INTENCAPT1_SMIACCESS_SHIFT  (9U)
/*! SMIACCESS - SMI Access
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_SMIACCESS(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCAPT1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCAPT1_LCLWK_MASK       (0x400U)
#define TENBASET_PHY_INTENCAPT1_LCLWK_SHIFT      (10U)
/*! LCLWK - Local Wake
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_LCLWK(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_LCLWK_SHIFT)) & TENBASET_PHY_INTENCAPT1_LCLWK_MASK)

#define TENBASET_PHY_INTENCAPT1_SSPDET_MASK      (0x800U)
#define TENBASET_PHY_INTENCAPT1_SSPDET_SHIFT     (11U)
/*! SSPDET - Suspend Symbol Detects
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_SSPDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_SSPDET_SHIFT)) & TENBASET_PHY_INTENCAPT1_SSPDET_MASK)

#define TENBASET_PHY_INTENCAPT1_WUTDET_MASK      (0x1000U)
#define TENBASET_PHY_INTENCAPT1_WUTDET_SHIFT     (12U)
/*! WUTDET - WUT Detect
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_WUTDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_WUTDET_SHIFT)) & TENBASET_PHY_INTENCAPT1_WUTDET_MASK)

#define TENBASET_PHY_INTENCAPT1_WUPDONE_MASK     (0x2000U)
#define TENBASET_PHY_INTENCAPT1_WUPDONE_SHIFT    (13U)
/*! WUPDONE - WUP transmission completed Write 1 clears bits.
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_WUPDONE(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCAPT1_WUPDONE_MASK)

#define TENBASET_PHY_INTENCAPT1_APBPARITY_MASK   (0x4000U)
#define TENBASET_PHY_INTENCAPT1_APBPARITY_SHIFT  (14U)
/*! APBPARITY - APB Parity
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT1_APBPARITY(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCAPT1_APBPARITY_MASK)
/*! @} */

/*! @name INTENSET1 - Interrupt Enable Set1 */
/*! @{ */

#define TENBASET_PHY_INTENSET1_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENSET1_PHYSCOL_SHIFT     (0U)
/*! PHYSCOL - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENSET1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENSET1_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENSET1_PLCAREC_SHIFT     (1U)
/*! PLCAREC - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENSET1_PLCAREC_MASK)

#define TENBASET_PHY_INTENSET1_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENSET1_PLCASTAT_SHIFT    (2U)
/*! PLCASTAT - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENSET1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENSET1_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENSET1_MODESTAT_SHIFT    (3U)
/*! MODESTAT - Mode status
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENSET1_MODESTAT_MASK)

#define TENBASET_PHY_INTENSET1_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENSET1_INVLDAPB_SHIFT    (4U)
/*! INVLDAPB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENSET1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENSET1_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENSET1_LOCJAB_SHIFT      (5U)
/*! LOCJAB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENSET1_LOCJAB_MASK)

#define TENBASET_PHY_INTENSET1_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENSET1_REMJAB_SHIFT      (6U)
/*! REMJAB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_REMJAB_SHIFT)) & TENBASET_PHY_INTENSET1_REMJAB_MASK)

#define TENBASET_PHY_INTENSET1_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENSET1_PINFAULT_SHIFT    (7U)
/*! PINFAULT - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENSET1_PINFAULT_MASK)

#define TENBASET_PHY_INTENSET1_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENSET1_PLCADIAG_SHIFT    (8U)
/*! PLCADIAG - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENSET1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENSET1_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENSET1_SMIACCESS_SHIFT   (9U)
/*! SMIACCESS - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENSET1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENSET1_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENSET1_LCLWK_SHIFT       (10U)
/*! LCLWK - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_LCLWK_SHIFT)) & TENBASET_PHY_INTENSET1_LCLWK_MASK)

#define TENBASET_PHY_INTENSET1_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENSET1_SSPDET_SHIFT      (11U)
/*! SSPDET - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_SSPDET_SHIFT)) & TENBASET_PHY_INTENSET1_SSPDET_MASK)

#define TENBASET_PHY_INTENSET1_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENSET1_WUTDET_SHIFT      (12U)
/*! WUTDET - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_WUTDET_SHIFT)) & TENBASET_PHY_INTENSET1_WUTDET_MASK)

#define TENBASET_PHY_INTENSET1_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENSET1_WUPDONE_SHIFT     (13U)
/*! WUPDONE - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENSET1_WUPDONE_MASK)

#define TENBASET_PHY_INTENSET1_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENSET1_APBPARITY_SHIFT   (14U)
/*! APBPARITY - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET1_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENSET1_APBPARITY_MASK)
/*! @} */

/*! @name INTENCLR1 - Interrupt Enable Clear1 */
/*! @{ */

#define TENBASET_PHY_INTENCLR1_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENCLR1_PHYSCOL_SHIFT     (0U)
/*! PHYSCOL - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCLR1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCLR1_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENCLR1_PLCAREC_SHIFT     (1U)
/*! PLCAREC - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCAREC_MASK)

#define TENBASET_PHY_INTENCLR1_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENCLR1_PLCASTAT_SHIFT    (2U)
/*! PLCASTAT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCLR1_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENCLR1_MODESTAT_SHIFT    (3U)
/*! MODESTAT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCLR1_MODESTAT_MASK)

#define TENBASET_PHY_INTENCLR1_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENCLR1_INVLDAPB_SHIFT    (4U)
/*! INVLDAPB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCLR1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCLR1_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENCLR1_LOCJAB_SHIFT      (5U)
/*! LOCJAB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCLR1_LOCJAB_MASK)

#define TENBASET_PHY_INTENCLR1_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENCLR1_REMJAB_SHIFT      (6U)
/*! REMJAB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_REMJAB_SHIFT)) & TENBASET_PHY_INTENCLR1_REMJAB_MASK)

#define TENBASET_PHY_INTENCLR1_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENCLR1_PINFAULT_SHIFT    (7U)
/*! PINFAULT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCLR1_PINFAULT_MASK)

#define TENBASET_PHY_INTENCLR1_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENCLR1_PLCADIAG_SHIFT    (8U)
/*! PLCADIAG - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCLR1_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENCLR1_SMIACCESS_SHIFT   (9U)
/*! SMIACCESS - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCLR1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCLR1_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENCLR1_LCLWK_SHIFT       (10U)
/*! LCLWK - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_LCLWK_SHIFT)) & TENBASET_PHY_INTENCLR1_LCLWK_MASK)

#define TENBASET_PHY_INTENCLR1_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENCLR1_SSPDET_SHIFT      (11U)
/*! SSPDET - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_SSPDET_SHIFT)) & TENBASET_PHY_INTENCLR1_SSPDET_MASK)

#define TENBASET_PHY_INTENCLR1_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENCLR1_WUTDET_SHIFT      (12U)
/*! WUTDET - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_WUTDET_SHIFT)) & TENBASET_PHY_INTENCLR1_WUTDET_MASK)

#define TENBASET_PHY_INTENCLR1_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENCLR1_WUPDONE_SHIFT     (13U)
/*! WUPDONE - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCLR1_WUPDONE_MASK)

#define TENBASET_PHY_INTENCLR1_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENCLR1_APBPARITY_SHIFT   (14U)
/*! APBPARITY - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR1_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCLR1_APBPARITY_MASK)
/*! @} */

/*! @name INTSTAT1 - Interrupt Status1 */
/*! @{ */

#define TENBASET_PHY_INTSTAT1_PHYSCOL_MASK       (0x1U)
#define TENBASET_PHY_INTSTAT1_PHYSCOL_SHIFT      (0U)
/*! PHYSCOL - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_PHYSCOL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTSTAT1_PHYSCOL_MASK)

#define TENBASET_PHY_INTSTAT1_PLCAREC_MASK       (0x2U)
#define TENBASET_PHY_INTSTAT1_PLCAREC_SHIFT      (1U)
/*! PLCAREC - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_PLCAREC(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCAREC_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCAREC_MASK)

#define TENBASET_PHY_INTSTAT1_PLCASTAT_MASK      (0x4U)
#define TENBASET_PHY_INTSTAT1_PLCASTAT_SHIFT     (2U)
/*! PLCASTAT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_PLCASTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCASTAT_MASK)

#define TENBASET_PHY_INTSTAT1_MODESTAT_MASK      (0x8U)
#define TENBASET_PHY_INTSTAT1_MODESTAT_SHIFT     (3U)
/*! MODESTAT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_MODESTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_MODESTAT_SHIFT)) & TENBASET_PHY_INTSTAT1_MODESTAT_MASK)

#define TENBASET_PHY_INTSTAT1_INVLDAPB_MASK      (0x10U)
#define TENBASET_PHY_INTSTAT1_INVLDAPB_SHIFT     (4U)
/*! INVLDAPB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_INVLDAPB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTSTAT1_INVLDAPB_MASK)

#define TENBASET_PHY_INTSTAT1_LOCJAB_MASK        (0x20U)
#define TENBASET_PHY_INTSTAT1_LOCJAB_SHIFT       (5U)
/*! LOCJAB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_LOCJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_LOCJAB_SHIFT)) & TENBASET_PHY_INTSTAT1_LOCJAB_MASK)

#define TENBASET_PHY_INTSTAT1_REMJAB_MASK        (0x40U)
#define TENBASET_PHY_INTSTAT1_REMJAB_SHIFT       (6U)
/*! REMJAB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_REMJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_REMJAB_SHIFT)) & TENBASET_PHY_INTSTAT1_REMJAB_MASK)

#define TENBASET_PHY_INTSTAT1_PINFAULT_MASK      (0x80U)
#define TENBASET_PHY_INTSTAT1_PINFAULT_SHIFT     (7U)
/*! PINFAULT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_PINFAULT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PINFAULT_SHIFT)) & TENBASET_PHY_INTSTAT1_PINFAULT_MASK)

#define TENBASET_PHY_INTSTAT1_PLCADIAG_MASK      (0x100U)
#define TENBASET_PHY_INTSTAT1_PLCADIAG_SHIFT     (8U)
/*! PLCADIAG - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_PLCADIAG(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCADIAG_MASK)

#define TENBASET_PHY_INTSTAT1_SMIACCESS_MASK     (0x200U)
#define TENBASET_PHY_INTSTAT1_SMIACCESS_SHIFT    (9U)
/*! SMIACCESS - status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_SMIACCESS(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTSTAT1_SMIACCESS_MASK)

#define TENBASET_PHY_INTSTAT1_LCLWK_MASK         (0x400U)
#define TENBASET_PHY_INTSTAT1_LCLWK_SHIFT        (10U)
/*! LCLWK - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_LCLWK(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_LCLWK_SHIFT)) & TENBASET_PHY_INTSTAT1_LCLWK_MASK)

#define TENBASET_PHY_INTSTAT1_SSPDET_MASK        (0x800U)
#define TENBASET_PHY_INTSTAT1_SSPDET_SHIFT       (11U)
/*! SSPDET - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_SSPDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_SSPDET_SHIFT)) & TENBASET_PHY_INTSTAT1_SSPDET_MASK)

#define TENBASET_PHY_INTSTAT1_WUTDET_MASK        (0x1000U)
#define TENBASET_PHY_INTSTAT1_WUTDET_SHIFT       (12U)
/*! WUTDET - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_WUTDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_WUTDET_SHIFT)) & TENBASET_PHY_INTSTAT1_WUTDET_MASK)

#define TENBASET_PHY_INTSTAT1_WUPDONE_MASK       (0x2000U)
#define TENBASET_PHY_INTSTAT1_WUPDONE_SHIFT      (13U)
/*! WUPDONE - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_WUPDONE(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_WUPDONE_SHIFT)) & TENBASET_PHY_INTSTAT1_WUPDONE_MASK)

#define TENBASET_PHY_INTSTAT1_APBPARITY_MASK     (0x4000U)
#define TENBASET_PHY_INTSTAT1_APBPARITY_SHIFT    (14U)
/*! APBPARITY - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT1_APBPARITY(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_APBPARITY_SHIFT)) & TENBASET_PHY_INTSTAT1_APBPARITY_MASK)
/*! @} */

/*! @name INTENCAPT2 - Interrupt Capture2 */
/*! @{ */

#define TENBASET_PHY_INTENCAPT2_PHYSCOL_MASK     (0x1U)
#define TENBASET_PHY_INTENCAPT2_PHYSCOL_SHIFT    (0U)
/*! PHYSCOL - Physical Collision
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_PHYSCOL(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCAPT2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCAREC_MASK     (0x2U)
#define TENBASET_PHY_INTENCAPT2_PLCAREC_SHIFT    (1U)
/*! PLCAREC - PLCA Recovery
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_PLCAREC(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCAREC_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCASTAT_MASK    (0x4U)
#define TENBASET_PHY_INTENCAPT2_PLCASTAT_SHIFT   (2U)
/*! PLCASTAT - PLCA Status
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_PLCASTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCAPT2_MODESTAT_MASK    (0x8U)
#define TENBASET_PHY_INTENCAPT2_MODESTAT_SHIFT   (3U)
/*! MODESTAT - MODE Status
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_MODESTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCAPT2_MODESTAT_MASK)

#define TENBASET_PHY_INTENCAPT2_INVLDAPB_MASK    (0x10U)
#define TENBASET_PHY_INTENCAPT2_INVLDAPB_SHIFT   (4U)
/*! INVLDAPB - Invalid APB
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_INVLDAPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCAPT2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCAPT2_LOCJAB_MASK      (0x20U)
#define TENBASET_PHY_INTENCAPT2_LOCJAB_SHIFT     (5U)
/*! LOCJAB - Local Jabber
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_LOCJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCAPT2_LOCJAB_MASK)

#define TENBASET_PHY_INTENCAPT2_REMJAB_MASK      (0x40U)
#define TENBASET_PHY_INTENCAPT2_REMJAB_SHIFT     (6U)
/*! REMJAB - Remote Jabber
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_REMJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_REMJAB_SHIFT)) & TENBASET_PHY_INTENCAPT2_REMJAB_MASK)

#define TENBASET_PHY_INTENCAPT2_PINFAULT_MASK    (0x80U)
#define TENBASET_PHY_INTENCAPT2_PINFAULT_SHIFT   (7U)
/*! PINFAULT - PIN Fault Monitor
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_PINFAULT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCAPT2_PINFAULT_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCADIAG_MASK    (0x100U)
#define TENBASET_PHY_INTENCAPT2_PLCADIAG_SHIFT   (8U)
/*! PLCADIAG - PLCA Diagnostics
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_PLCADIAG(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCAPT2_SMIACCESS_MASK   (0x200U)
#define TENBASET_PHY_INTENCAPT2_SMIACCESS_SHIFT  (9U)
/*! SMIACCESS - SMI Access
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_SMIACCESS(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCAPT2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCAPT2_LCLWK_MASK       (0x400U)
#define TENBASET_PHY_INTENCAPT2_LCLWK_SHIFT      (10U)
/*! LCLWK - Local Wake
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_LCLWK(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_LCLWK_SHIFT)) & TENBASET_PHY_INTENCAPT2_LCLWK_MASK)

#define TENBASET_PHY_INTENCAPT2_SSPDET_MASK      (0x800U)
#define TENBASET_PHY_INTENCAPT2_SSPDET_SHIFT     (11U)
/*! SSPDET - Suspend Symbol Detects
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_SSPDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_SSPDET_SHIFT)) & TENBASET_PHY_INTENCAPT2_SSPDET_MASK)

#define TENBASET_PHY_INTENCAPT2_WUTDET_MASK      (0x1000U)
#define TENBASET_PHY_INTENCAPT2_WUTDET_SHIFT     (12U)
/*! WUTDET - WUT Detect
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_WUTDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_WUTDET_SHIFT)) & TENBASET_PHY_INTENCAPT2_WUTDET_MASK)

#define TENBASET_PHY_INTENCAPT2_WUPDONE_MASK     (0x2000U)
#define TENBASET_PHY_INTENCAPT2_WUPDONE_SHIFT    (13U)
/*! WUPDONE - WUP transmission completed Write 1 clears bits.
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_WUPDONE(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCAPT2_WUPDONE_MASK)

#define TENBASET_PHY_INTENCAPT2_APBPARITY_MASK   (0x4000U)
#define TENBASET_PHY_INTENCAPT2_APBPARITY_SHIFT  (14U)
/*! APBPARITY - APB Parity
 *  0b0..NO Effect
 *  0b1..Clear
 */
#define TENBASET_PHY_INTENCAPT2_APBPARITY(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCAPT2_APBPARITY_MASK)
/*! @} */

/*! @name INTENSET2 - Interrupt Enable Set1 */
/*! @{ */

#define TENBASET_PHY_INTENSET2_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENSET2_PHYSCOL_SHIFT     (0U)
/*! PHYSCOL - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENSET2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENSET2_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENSET2_PLCAREC_SHIFT     (1U)
/*! PLCAREC - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENSET2_PLCAREC_MASK)

#define TENBASET_PHY_INTENSET2_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENSET2_PLCASTAT_SHIFT    (2U)
/*! PLCASTAT - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENSET2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENSET2_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENSET2_MODESTAT_SHIFT    (3U)
/*! MODESTAT - Mode status
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENSET2_MODESTAT_MASK)

#define TENBASET_PHY_INTENSET2_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENSET2_INVLDAPB_SHIFT    (4U)
/*! INVLDAPB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENSET2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENSET2_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENSET2_LOCJAB_SHIFT      (5U)
/*! LOCJAB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENSET2_LOCJAB_MASK)

#define TENBASET_PHY_INTENSET2_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENSET2_REMJAB_SHIFT      (6U)
/*! REMJAB - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_REMJAB_SHIFT)) & TENBASET_PHY_INTENSET2_REMJAB_MASK)

#define TENBASET_PHY_INTENSET2_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENSET2_PINFAULT_SHIFT    (7U)
/*! PINFAULT - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENSET2_PINFAULT_MASK)

#define TENBASET_PHY_INTENSET2_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENSET2_PLCADIAG_SHIFT    (8U)
/*! PLCADIAG - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENSET2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENSET2_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENSET2_SMIACCESS_SHIFT   (9U)
/*! SMIACCESS - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENSET2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENSET2_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENSET2_LCLWK_SHIFT       (10U)
/*! LCLWK - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_LCLWK_SHIFT)) & TENBASET_PHY_INTENSET2_LCLWK_MASK)

#define TENBASET_PHY_INTENSET2_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENSET2_SSPDET_SHIFT      (11U)
/*! SSPDET - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_SSPDET_SHIFT)) & TENBASET_PHY_INTENSET2_SSPDET_MASK)

#define TENBASET_PHY_INTENSET2_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENSET2_WUTDET_SHIFT      (12U)
/*! WUTDET - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_WUTDET_SHIFT)) & TENBASET_PHY_INTENSET2_WUTDET_MASK)

#define TENBASET_PHY_INTENSET2_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENSET2_WUPDONE_SHIFT     (13U)
/*! WUPDONE - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENSET2_WUPDONE_MASK)

#define TENBASET_PHY_INTENSET2_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENSET2_APBPARITY_SHIFT   (14U)
/*! APBPARITY - write 1 enables corresponding interrupt
 *  0b0..Disabled
 *  0b1..ENABLED
 */
#define TENBASET_PHY_INTENSET2_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENSET2_APBPARITY_MASK)
/*! @} */

/*! @name INTENCLR2 - Interrupt Enable Clear2 */
/*! @{ */

#define TENBASET_PHY_INTENCLR2_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENCLR2_PHYSCOL_SHIFT     (0U)
/*! PHYSCOL - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCLR2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCLR2_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENCLR2_PLCAREC_SHIFT     (1U)
/*! PLCAREC - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCAREC_MASK)

#define TENBASET_PHY_INTENCLR2_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENCLR2_PLCASTAT_SHIFT    (2U)
/*! PLCASTAT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCLR2_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENCLR2_MODESTAT_SHIFT    (3U)
/*! MODESTAT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCLR2_MODESTAT_MASK)

#define TENBASET_PHY_INTENCLR2_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENCLR2_INVLDAPB_SHIFT    (4U)
/*! INVLDAPB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCLR2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCLR2_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENCLR2_LOCJAB_SHIFT      (5U)
/*! LOCJAB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCLR2_LOCJAB_MASK)

#define TENBASET_PHY_INTENCLR2_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENCLR2_REMJAB_SHIFT      (6U)
/*! REMJAB - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_REMJAB_SHIFT)) & TENBASET_PHY_INTENCLR2_REMJAB_MASK)

#define TENBASET_PHY_INTENCLR2_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENCLR2_PINFAULT_SHIFT    (7U)
/*! PINFAULT - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCLR2_PINFAULT_MASK)

#define TENBASET_PHY_INTENCLR2_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENCLR2_PLCADIAG_SHIFT    (8U)
/*! PLCADIAG - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCLR2_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENCLR2_SMIACCESS_SHIFT   (9U)
/*! SMIACCESS - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCLR2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCLR2_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENCLR2_LCLWK_SHIFT       (10U)
/*! LCLWK - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_LCLWK_SHIFT)) & TENBASET_PHY_INTENCLR2_LCLWK_MASK)

#define TENBASET_PHY_INTENCLR2_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENCLR2_SSPDET_SHIFT      (11U)
/*! SSPDET - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_SSPDET_SHIFT)) & TENBASET_PHY_INTENCLR2_SSPDET_MASK)

#define TENBASET_PHY_INTENCLR2_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENCLR2_WUTDET_SHIFT      (12U)
/*! WUTDET - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_WUTDET_SHIFT)) & TENBASET_PHY_INTENCLR2_WUTDET_MASK)

#define TENBASET_PHY_INTENCLR2_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENCLR2_WUPDONE_SHIFT     (13U)
/*! WUPDONE - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCLR2_WUPDONE_MASK)

#define TENBASET_PHY_INTENCLR2_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENCLR2_APBPARITY_SHIFT   (14U)
/*! APBPARITY - write 1 disables corresponding interrupt
 *  0b0..NO_EFFECT
 *  0b1..DISABLE
 */
#define TENBASET_PHY_INTENCLR2_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCLR2_APBPARITY_MASK)
/*! @} */

/*! @name INTSTAT2 - Interrupt Status2 */
/*! @{ */

#define TENBASET_PHY_INTSTAT2_PHYSCOL_MASK       (0x1U)
#define TENBASET_PHY_INTSTAT2_PHYSCOL_SHIFT      (0U)
/*! PHYSCOL - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_PHYSCOL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTSTAT2_PHYSCOL_MASK)

#define TENBASET_PHY_INTSTAT2_PLCAREC_MASK       (0x2U)
#define TENBASET_PHY_INTSTAT2_PLCAREC_SHIFT      (1U)
/*! PLCAREC - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_PLCAREC(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCAREC_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCAREC_MASK)

#define TENBASET_PHY_INTSTAT2_PLCASTAT_MASK      (0x4U)
#define TENBASET_PHY_INTSTAT2_PLCASTAT_SHIFT     (2U)
/*! PLCASTAT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_PLCASTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCASTAT_MASK)

#define TENBASET_PHY_INTSTAT2_MODESTAT_MASK      (0x8U)
#define TENBASET_PHY_INTSTAT2_MODESTAT_SHIFT     (3U)
/*! MODESTAT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_MODESTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_MODESTAT_SHIFT)) & TENBASET_PHY_INTSTAT2_MODESTAT_MASK)

#define TENBASET_PHY_INTSTAT2_INVLDAPB_MASK      (0x10U)
#define TENBASET_PHY_INTSTAT2_INVLDAPB_SHIFT     (4U)
/*! INVLDAPB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_INVLDAPB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTSTAT2_INVLDAPB_MASK)

#define TENBASET_PHY_INTSTAT2_LOCJAB_MASK        (0x20U)
#define TENBASET_PHY_INTSTAT2_LOCJAB_SHIFT       (5U)
/*! LOCJAB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_LOCJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_LOCJAB_SHIFT)) & TENBASET_PHY_INTSTAT2_LOCJAB_MASK)

#define TENBASET_PHY_INTSTAT2_REMJAB_MASK        (0x40U)
#define TENBASET_PHY_INTSTAT2_REMJAB_SHIFT       (6U)
/*! REMJAB - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_REMJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_REMJAB_SHIFT)) & TENBASET_PHY_INTSTAT2_REMJAB_MASK)

#define TENBASET_PHY_INTSTAT2_PINFAULT_MASK      (0x80U)
#define TENBASET_PHY_INTSTAT2_PINFAULT_SHIFT     (7U)
/*! PINFAULT - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_PINFAULT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PINFAULT_SHIFT)) & TENBASET_PHY_INTSTAT2_PINFAULT_MASK)

#define TENBASET_PHY_INTSTAT2_PLCADIAG_MASK      (0x100U)
#define TENBASET_PHY_INTSTAT2_PLCADIAG_SHIFT     (8U)
/*! PLCADIAG - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_PLCADIAG(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCADIAG_MASK)

#define TENBASET_PHY_INTSTAT2_SMIACCESS_MASK     (0x200U)
#define TENBASET_PHY_INTSTAT2_SMIACCESS_SHIFT    (9U)
/*! SMIACCESS - status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_SMIACCESS(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTSTAT2_SMIACCESS_MASK)

#define TENBASET_PHY_INTSTAT2_LCLWK_MASK         (0x400U)
#define TENBASET_PHY_INTSTAT2_LCLWK_SHIFT        (10U)
/*! LCLWK - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_LCLWK(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_LCLWK_SHIFT)) & TENBASET_PHY_INTSTAT2_LCLWK_MASK)

#define TENBASET_PHY_INTSTAT2_SSPDET_MASK        (0x800U)
#define TENBASET_PHY_INTSTAT2_SSPDET_SHIFT       (11U)
/*! SSPDET - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_SSPDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_SSPDET_SHIFT)) & TENBASET_PHY_INTSTAT2_SSPDET_MASK)

#define TENBASET_PHY_INTSTAT2_WUTDET_MASK        (0x1000U)
#define TENBASET_PHY_INTSTAT2_WUTDET_SHIFT       (12U)
/*! WUTDET - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_WUTDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_WUTDET_SHIFT)) & TENBASET_PHY_INTSTAT2_WUTDET_MASK)

#define TENBASET_PHY_INTSTAT2_WUPDONE_MASK       (0x2000U)
#define TENBASET_PHY_INTSTAT2_WUPDONE_SHIFT      (13U)
/*! WUPDONE - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_WUPDONE(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_WUPDONE_SHIFT)) & TENBASET_PHY_INTSTAT2_WUPDONE_MASK)

#define TENBASET_PHY_INTSTAT2_APBPARITY_MASK     (0x4000U)
#define TENBASET_PHY_INTSTAT2_APBPARITY_SHIFT    (14U)
/*! APBPARITY - Status of corresponding interrupt after enable stage
 *  0b0..Not Pending
 *  0b1..Pending
 */
#define TENBASET_PHY_INTSTAT2_APBPARITY(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_APBPARITY_SHIFT)) & TENBASET_PHY_INTSTAT2_APBPARITY_MASK)
/*! @} */

/*! @name PLCADIAG1 - PLCA TC14 Adv diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG1_BCNBFTO_MASK      (0x1U)
#define TENBASET_PHY_PLCADIAG1_BCNBFTO_SHIFT     (0U)
/*! BCNBFTO - Beacon Consecutive
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG1_BCNBFTO(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_BCNBFTO_SHIFT)) & TENBASET_PHY_PLCADIAG1_BCNBFTO_MASK)

#define TENBASET_PHY_PLCADIAG1_UNEXPB_MASK       (0x2U)
#define TENBASET_PHY_PLCADIAG1_UNEXPB_SHIFT      (1U)
/*! UNEXPB - Unexpected Beacon
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG1_UNEXPB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_UNEXPB_SHIFT)) & TENBASET_PHY_PLCADIAG1_UNEXPB_MASK)

#define TENBASET_PHY_PLCADIAG1_RXINTO_MASK       (0x4U)
#define TENBASET_PHY_PLCADIAG1_RXINTO_SHIFT      (2U)
/*! RXINTO - Indicates Reception
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG1_RXINTO(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_RXINTO_SHIFT)) & TENBASET_PHY_PLCADIAG1_RXINTO_MASK)
/*! @} */

/*! @name PLCADIAG2 - PLCA NXP prop diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG2_EARLYBCN_MASK     (0x1U)
#define TENBASET_PHY_PLCADIAG2_EARLYBCN_SHIFT    (0U)
/*! EARLYBCN - Early Beacon
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG2_EARLYBCN(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_EARLYBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_EARLYBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_LATEBCN_MASK      (0x2U)
#define TENBASET_PHY_PLCADIAG2_LATEBCN_SHIFT     (1U)
/*! LATEBCN - Late Beacon
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG2_LATEBCN(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_LATEBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_LATEBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_NORXBCN_MASK      (0x4U)
#define TENBASET_PHY_PLCADIAG2_NORXBCN_SHIFT     (2U)
/*! NORXBCN - No Beacon Received
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG2_NORXBCN(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_NORXBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_NORXBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE_MASK   (0x8U)
#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE_SHIFT  (3U)
/*! UNDEFSTATE - Undefined State
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_UNDEFSTATE_SHIFT)) & TENBASET_PHY_PLCADIAG2_UNDEFSTATE_MASK)
/*! @} */

/*! @name PLCADIAG3 - PLCA Beacon Counter Diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT_MASK    (0xFFFFU)
#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT_SHIFT   (0U)
/*! RXBCNTCNT - RX Beacon Counter */
#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG3_RXBCNTCNT_SHIFT)) & TENBASET_PHY_PLCADIAG3_RXBCNTCNT_MASK)
/*! @} */

/*! @name PLCADIAG4 - PLCA TO Counter Diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG4_TOCNT_MASK        (0xFFFFU)
#define TENBASET_PHY_PLCADIAG4_TOCNT_SHIFT       (0U)
/*! TOCNT - Transmit Opportunity Counter */
#define TENBASET_PHY_PLCADIAG4_TOCNT(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG4_TOCNT_SHIFT)) & TENBASET_PHY_PLCADIAG4_TOCNT_MASK)
/*! @} */

/*! @name TXCDIAG - Transceiver Diagnostics */
/*! @{ */

#define TENBASET_PHY_TXCDIAG_RXLOWFAIL_MASK      (0x1U)
#define TENBASET_PHY_TXCDIAG_RXLOWFAIL_SHIFT     (0U)
/*! RXLOWFAIL - RX Low Pin Detect
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_TXCDIAG_RXLOWFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_RXLOWFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_RXLOWFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_RXHGHFAIL_MASK      (0x2U)
#define TENBASET_PHY_TXCDIAG_RXHGHFAIL_SHIFT     (1U)
/*! RXHGHFAIL - RX High Pin Detect
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_TXCDIAG_RXHGHFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_RXHGHFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_RXHGHFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_EDLOWFAIL_MASK      (0x4U)
#define TENBASET_PHY_TXCDIAG_EDLOWFAIL_SHIFT     (2U)
/*! EDLOWFAIL - Stuck Low ED Pin
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_TXCDIAG_EDLOWFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_EDLOWFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_EDLOWFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_EDHGHFAIL_MASK      (0x8U)
#define TENBASET_PHY_TXCDIAG_EDHGHFAIL_SHIFT     (3U)
/*! EDHGHFAIL - Stuck High ED Pin
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_TXCDIAG_EDHGHFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_EDHGHFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_EDHGHFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_LPWRFAIL_MASK       (0x10U)
#define TENBASET_PHY_TXCDIAG_LPWRFAIL_SHIFT      (4U)
/*! LPWRFAIL - Low Power Failure
 *  0b0..NO
 *  0b1..Yes
 */
#define TENBASET_PHY_TXCDIAG_LPWRFAIL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_LPWRFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_LPWRFAIL_MASK)
/*! @} */

/*! @name MSKPLCADIAG1 - Mask Control PLCADIAG1 Flag */
/*! @{ */

#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_MASK   (0x1U)
#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_SHIFT  (0U)
/*! BCNBFTO - Mask control for BCNBFTO flag
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_MASK)

#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB_MASK    (0x2U)
#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB_SHIFT   (1U)
/*! UNEXPB - Mask control for UNEXPB flag
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_UNEXPB_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_UNEXPB_MASK)

#define TENBASET_PHY_MSKPLCADIAG1_RXINTO_MASK    (0x4U)
#define TENBASET_PHY_MSKPLCADIAG1_RXINTO_SHIFT   (2U)
/*! RXINTO - Mask control for RXINTO flag
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG1_RXINTO(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_RXINTO_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_RXINTO_MASK)
/*! @} */

/*! @name MSKPLCADIAG2 - Mask Control PLCADIAG2 Flags */
/*! @{ */

#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_MASK  (0x1U)
#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_SHIFT (0U)
/*! EARLYBCN - Early Beacon Flag
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN(x)    (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN_MASK   (0x2U)
#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN_SHIFT  (1U)
/*! LATEBCN - Late Beacon
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_LATEBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_LATEBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN_MASK   (0x4U)
#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN_SHIFT  (2U)
/*! NORXBCN - NO RX Beacon
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_NORXBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_NORXBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_MASK (0x8U)
#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_SHIFT (3U)
/*! UNDEFSTATE - UNDEF State
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE(x)  (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_MASK)
/*! @} */

/*! @name MSKTXCDIAG - Mask Control TXCDIAG Flag */
/*! @{ */

#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_MASK   (0x1U)
#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_SHIFT  (0U)
/*! RXLOWFAIL - RX Low Fail
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_MASK   (0x2U)
#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_SHIFT  (1U)
/*! RXHGHFAIL - RX High Fail
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_MASK   (0x4U)
#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_SHIFT  (2U)
/*! EDLOWFAIL - ED Low Fail
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_MASK   (0x8U)
#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_SHIFT  (3U)
/*! EDHGHFAIL - ED High Flag
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_MASK    (0x10U)
#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_SHIFT   (4U)
/*! LPWRFAIL - Low Power Fail
 *  0b0..Enabled
 *  0b1..Masked
 */
#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_MASK)
/*! @} */

/*! @name ACCESSCTRL - Global Access Control */
/*! @{ */

#define TENBASET_PHY_ACCESSCTRL_ACCESS_MASK      (0x1U)
#define TENBASET_PHY_ACCESSCTRL_ACCESS_SHIFT     (0U)
/*! ACCESS - APB Write Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define TENBASET_PHY_ACCESSCTRL_ACCESS(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_ACCESSCTRL_ACCESS_SHIFT)) & TENBASET_PHY_ACCESSCTRL_ACCESS_MASK)
/*! @} */

/*! @name DBGCTRL - Debug Control */
/*! @{ */

#define TENBASET_PHY_DBGCTRL_DEBUG_MASK          (0xFFU)
#define TENBASET_PHY_DBGCTRL_DEBUG_SHIFT         (0U)
/*! DEBUG - Debug */
#define TENBASET_PHY_DBGCTRL_DEBUG(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_DBGCTRL_DEBUG_SHIFT)) & TENBASET_PHY_DBGCTRL_DEBUG_MASK)
/*! @} */

/*! @name VERSION - Version Information */
/*! @{ */

#define TENBASET_PHY_VERSION_CUSTVER_MASK        (0xFU)
#define TENBASET_PHY_VERSION_CUSTVER_SHIFT       (0U)
/*! CUSTVER - Customer Version */
#define TENBASET_PHY_VERSION_CUSTVER(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_CUSTVER_SHIFT)) & TENBASET_PHY_VERSION_CUSTVER_MASK)

#define TENBASET_PHY_VERSION_MINORVER_MASK       (0xFF0U)
#define TENBASET_PHY_VERSION_MINORVER_SHIFT      (4U)
/*! MINORVER - Minor Version */
#define TENBASET_PHY_VERSION_MINORVER(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_MINORVER_SHIFT)) & TENBASET_PHY_VERSION_MINORVER_MASK)

#define TENBASET_PHY_VERSION_MAJORVER_MASK       (0xF000U)
#define TENBASET_PHY_VERSION_MAJORVER_SHIFT      (12U)
/*! MAJORVER - Major Version */
#define TENBASET_PHY_VERSION_MAJORVER(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_MAJORVER_SHIFT)) & TENBASET_PHY_VERSION_MAJORVER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TENBASET_PHY_Register_Masks */


/*!
 * @}
 */ /* end of group TENBASET_PHY_Peripheral_Access_Layer */


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


#endif  /* PERI_TENBASET_PHY_H_ */


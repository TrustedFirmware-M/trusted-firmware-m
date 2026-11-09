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
**                          MCXA536VLL
**                          MCXA536VLQ
**                          MCXA536VPN
**                          MCXA537VLL
**                          MCXA537VLQ
**                          MCXA537VPN
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
**         CMSIS Peripheral Access Layer for USBNC
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
 * @file PERI_USBNC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA286VAPR) || defined(CPU_MCXA286VASR) || defined(CPU_MCXA286VLL) || defined(CPU_MCXA286VLQ) || defined(CPU_MCXA286VPN))
#include "MCXA286_COMMON.h"
#elif (defined(CPU_MCXA287VAPR) || defined(CPU_MCXA287VASR) || defined(CPU_MCXA287VLL) || defined(CPU_MCXA287VLQ) || defined(CPU_MCXA287VPN))
#include "MCXA287_COMMON.h"
#elif (defined(CPU_MCXA456VASR) || defined(CPU_MCXA456VLL) || defined(CPU_MCXA456VLQ) || defined(CPU_MCXA456VPN))
#include "MCXA456_COMMON.h"
#elif (defined(CPU_MCXA457VASR) || defined(CPU_MCXA457VLL) || defined(CPU_MCXA457VLQ) || defined(CPU_MCXA457VPN))
#include "MCXA457_COMMON.h"
#elif (defined(CPU_MCXA536VLL) || defined(CPU_MCXA536VLQ) || defined(CPU_MCXA536VPN))
#include "MCXA536_COMMON.h"
#elif (defined(CPU_MCXA537VLL) || defined(CPU_MCXA537VLQ) || defined(CPU_MCXA537VPN))
#include "MCXA537_COMMON.h"
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
   -- USBNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Peripheral_Access_Layer USBNC Peripheral Access Layer
 * @{
 */

/** USBNC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL1;                             /**< USB Control 1, offset: 0x0 */
  __IO uint32_t CTRL2;                             /**< USB Control 2, offset: 0x4 */
       uint8_t RESERVED_0[36];
  __IO uint32_t HSIC_DLL_CFG4;                     /**< HSIC DLL Configuration 4, offset: 0x2C */
       uint8_t RESERVED_1[112];
  __IO uint32_t LPM_CSR0;                          /**< USB LPM Control and Status 0, offset: 0xA0 */
  __IO uint32_t LPM_CSR1;                          /**< USB LPM Control and Status 1, offset: 0xA4 */
  __IO uint32_t LPM_CSR2;                          /**< USB LPM Control and Status 2, offset: 0xA8 */
       uint8_t RESERVED_2[340];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock Recovery Control, offset: 0x200 */
       uint8_t RESERVED_3[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< FIRC Oscillator Enable, offset: 0x204 */
       uint8_t RESERVED_4[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock Recovery Combined Interrupt Enable, offset: 0x214 */
       uint8_t RESERVED_5[7];
  __IO uint8_t CLK_RECOVER_INT_STATUS;             /**< Clock Recovery Separated Interrupt Status, offset: 0x21C */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name CTRL1 - USB Control 1 */
/*! @{ */

#define USBNC_CTRL1_OVER_CUR_DIS_MASK            (0x80U)
#define USBNC_CTRL1_OVER_CUR_DIS_SHIFT           (7U)
/*! OVER_CUR_DIS - Overcurrent Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define USBNC_CTRL1_OVER_CUR_DIS(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_CTRL1_OVER_CUR_POL_MASK            (0x100U)
#define USBNC_CTRL1_OVER_CUR_POL_SHIFT           (8U)
/*! OVER_CUR_POL - Overcurrent Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define USBNC_CTRL1_OVER_CUR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_CTRL1_PWR_POL_MASK                 (0x200U)
#define USBNC_CTRL1_PWR_POL_SHIFT                (9U)
/*! PWR_POL - Power Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define USBNC_CTRL1_PWR_POL(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_PWR_POL_SHIFT)) & USBNC_CTRL1_PWR_POL_MASK)

#define USBNC_CTRL1_WIE_MASK                     (0x400U)
#define USBNC_CTRL1_WIE_SHIFT                    (10U)
/*! WIE - Wake-Up Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIE_SHIFT)) & USBNC_CTRL1_WIE_MASK)

#define USBNC_CTRL1_WKUP_SW_EN_MASK              (0x4000U)
#define USBNC_CTRL1_WKUP_SW_EN_SHIFT             (14U)
/*! WKUP_SW_EN - Software Wake-Up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_CTRL1_WKUP_SW_MASK                 (0x8000U)
#define USBNC_CTRL1_WKUP_SW_SHIFT                (15U)
/*! WKUP_SW - Software Wake-Up
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_CTRL1_WKUP_SW(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_SHIFT)) & USBNC_CTRL1_WKUP_SW_MASK)

#define USBNC_CTRL1_WKUP_ID_EN_MASK              (0x10000U)
#define USBNC_CTRL1_WKUP_ID_EN_SHIFT             (16U)
/*! WKUP_ID_EN - Wake-Up After ID Change Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_ID_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_CTRL1_WKUP_VBUS_EN_MASK            (0x20000U)
#define USBNC_CTRL1_WKUP_VBUS_EN_SHIFT           (17U)
/*! WKUP_VBUS_EN - Wake-Up After VBUS Change Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_WKUP_VBUS_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK        (0x10000000U)
#define USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT       (28U)
/*! REMOTE_WAKEUP_EN - Remote Wake-Up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CTRL1_REMOTE_WAKEUP_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT)) & USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK)

#define USBNC_CTRL1_WKUP_DPDM_EN_MASK            (0x20000000U)
#define USBNC_CTRL1_WKUP_DPDM_EN_SHIFT           (29U)
/*! WKUP_DPDM_EN - Wake-Up After DP or DM Change Enable
 *  0b0..Disable only when VBUS is invalid
 *  0b1..Enable (default)
 */
#define USBNC_CTRL1_WKUP_DPDM_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_CTRL1_WIR_MASK                     (0x80000000U)
#define USBNC_CTRL1_WIR_SHIFT                    (31U)
/*! WIR - Wake-Up Interrupt Request
 *  0b0..Not received
 *  0b1..Received
 */
#define USBNC_CTRL1_WIR(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIR_SHIFT)) & USBNC_CTRL1_WIR_MASK)
/*! @} */

/*! @name CTRL2 - USB Control 2 */
/*! @{ */

#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK         (0x3U)
#define USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT        (0U)
/*! VBUS_SOURCE_SEL - VBUS Source Select
 *  0b00..vbus_valid
 *  0b01..sess_valid
 *  0b10..sess_valid
 *  0b11..sess_valid
 */
#define USBNC_CTRL2_VBUS_SOURCE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_CTRL2_UTMI_CLK_VLD_MASK            (0x80000000U)
#define USBNC_CTRL2_UTMI_CLK_VLD_SHIFT           (31U)
/*! UTMI_CLK_VLD - UTMI Clock Valid Flag
 *  0b0..No effect
 *  0b0..Not valid
 *  0b1..Clear the flag
 *  0b1..Valid
 */
#define USBNC_CTRL2_UTMI_CLK_VLD(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name HSIC_DLL_CFG4 - HSIC DLL Configuration 4 */
/*! @{ */

#define USBNC_HSIC_DLL_CFG4_LPM_EN_ENDP_CHK_MASK (0x40000000U)
#define USBNC_HSIC_DLL_CFG4_LPM_EN_ENDP_CHK_SHIFT (30U)
/*! LPM_EN_ENDP_CHK - LPM EXT Token ENDP Check Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_HSIC_DLL_CFG4_LPM_EN_ENDP_CHK(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_DLL_CFG4_LPM_EN_ENDP_CHK_SHIFT)) & USBNC_HSIC_DLL_CFG4_LPM_EN_ENDP_CHK_MASK)

#define USBNC_HSIC_DLL_CFG4_FS_ISO_B2B_FIXEN_MASK (0x80000000U)
#define USBNC_HSIC_DLL_CFG4_FS_ISO_B2B_FIXEN_SHIFT (31U)
/*! FS_ISO_B2B_FIXEN - FS Isochronous Back-to-Back Transfer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_HSIC_DLL_CFG4_FS_ISO_B2B_FIXEN(x)  (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_DLL_CFG4_FS_ISO_B2B_FIXEN_SHIFT)) & USBNC_HSIC_DLL_CFG4_FS_ISO_B2B_FIXEN_MASK)
/*! @} */

/*! @name LPM_CSR0 - USB LPM Control and Status 0 */
/*! @{ */

#define USBNC_LPM_CSR0_LPM_EN_MASK               (0x1U)
#define USBNC_LPM_CSR0_LPM_EN_SHIFT              (0U)
/*! LPM_EN - Link Power Management Feature Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_LPM_CSR0_LPM_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_EN_SHIFT)) & USBNC_LPM_CSR0_LPM_EN_MASK)

#define USBNC_LPM_CSR0_LPM_ERRATA_EN_MASK        (0x2U)
#define USBNC_LPM_CSR0_LPM_ERRATA_EN_SHIFT       (1U)
/*! LPM_ERRATA_EN - Link Power Management ECN Errata Feature Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_LPM_CSR0_LPM_ERRATA_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_ERRATA_EN_SHIFT)) & USBNC_LPM_CSR0_LPM_ERRATA_EN_MASK)

#define USBNC_LPM_CSR0_LPM_AUTO_PHCD_MASK        (0x8U)
#define USBNC_LPM_CSR0_LPM_AUTO_PHCD_SHIFT       (3U)
/*! LPM_AUTO_PHCD - Auto Low-Power Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_LPM_CSR0_LPM_AUTO_PHCD(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_AUTO_PHCD_SHIFT)) & USBNC_LPM_CSR0_LPM_AUTO_PHCD_MASK)

#define USBNC_LPM_CSR0_LPM_RESUMEOK_MASK         (0x40000000U)
#define USBNC_LPM_CSR0_LPM_RESUMEOK_SHIFT        (30U)
/*! LPM_RESUMEOK - LPM Resume OK
 *  0b0..Cannot resume
 *  0b1..Can resume
 */
#define USBNC_LPM_CSR0_LPM_RESUMEOK(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_RESUMEOK_SHIFT)) & USBNC_LPM_CSR0_LPM_RESUMEOK_MASK)

#define USBNC_LPM_CSR0_LPM_L1_ACTIVE_MASK        (0x80000000U)
#define USBNC_LPM_CSR0_LPM_L1_ACTIVE_SHIFT       (31U)
/*! LPM_L1_ACTIVE - LPM Active
 *  0b0..Inactive
 *  0b1..Active
 */
#define USBNC_LPM_CSR0_LPM_L1_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_L1_ACTIVE_SHIFT)) & USBNC_LPM_CSR0_LPM_L1_ACTIVE_MASK)
/*! @} */

/*! @name LPM_CSR1 - USB LPM Control and Status 1 */
/*! @{ */

#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_MASK    (0xFU)
#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_SHIFT   (0U)
/*! LPM_DEV_BESLTHRES - Device Required Host Initiated Resume Duration
 *  0b0000..75 us, if LPM_ERRATA_EN = 1; 50 us, if LPM_ERRATA_EN = 0
 *  0b0001..100 us, if LPM_ERRATA_EN = 1; 125 us, if LPM_ERRATA_EN = 0
 *  0b0010..150 us, if LPM_ERRATA_EN = 1; 200 us, if LPM_ERRATA_EN = 0
 *  0b0011..250 us, if LPM_ERRATA_EN = 1; 275 us, if LPM_ERRATA_EN = 0
 *  0b0100..350 us, if LPM_ERRATA_EN = 1; 350 us, if LPM_ERRATA_EN = 0
 *  0b0101..450 us, if LPM_ERRATA_EN = 1; 425 us, if LPM_ERRATA_EN = 0
 *  0b0110..950 us, if LPM_ERRATA_EN = 1; 500 us, if LPM_ERRATA_EN = 0
 *  0b0111..1950 us, if LPM_ERRATA_EN = 1; 575 us, if LPM_ERRATA_EN = 0
 *  0b1000..2950 us, if LPM_ERRATA_EN = 1; 650 us, if LPM_ERRATA_EN = 0
 *  0b1001..3950 us, if LPM_ERRATA_EN = 1; 725 us, if LPM_ERRATA_EN = 0
 *  0b1010..4950 us, if LPM_ERRATA_EN = 1; 800 us, if LPM_ERRATA_EN = 0
 *  0b1011..5950 us, if LPM_ERRATA_EN = 1; 875 us, if LPM_ERRATA_EN = 0
 *  0b1100..6950 us, if LPM_ERRATA_EN = 1; 950 us, if LPM_ERRATA_EN = 0
 *  0b1101..7950 us, if LPM_ERRATA_EN = 1; 1025 us, if LPM_ERRATA_EN = 0
 *  0b1110..8950 us, if LPM_ERRATA_EN = 1; 1100 us, if LPM_ERRATA_EN = 0
 *  0b1111..9950 us, if LPM_ERRATA_EN = 1; 1175 us, if LPM_ERRATA_EN = 0
 */
#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RES_MASK          (0x10U)
#define USBNC_LPM_CSR1_LPM_DEV_RES_SHIFT         (4U)
/*! LPM_DEV_RES - LPM Device Response
 *  0b0..Fourth condition not needed
 *  0b1..Fourth condition needed
 */
#define USBNC_LPM_CSR1_LPM_DEV_RES(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RES_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RES_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_DP_MASK           (0x20U)
#define USBNC_LPM_CSR1_LPM_DEV_DP_SHIFT          (5U)
/*! LPM_DEV_DP - LPM Device Data Pending
 *  0b0..Not pending
 *  0b1..Pending
 */
#define USBNC_LPM_CSR1_LPM_DEV_DP(x)             (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_DP_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_DP_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS_MASK       (0x300000U)
#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS_SHIFT      (20U)
/*! LPM_DEV_RSPSTS - LPM Device Response Status
 *  0b00..Invalid
 *  0b01..ACK
 *  0b10..NYET
 *  0b11..STALL
 */
#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RSPSTS_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RSPSTS_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_MASK    (0x800000U)
#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_SHIFT   (23U)
/*! LPM_DEV_RWKENRCVD - LPM Device Received bRemoteWake
 *  0b0..0
 *  0b1..1
 */
#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_MASK    (0xF000000U)
#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_SHIFT   (24U)
/*! LPM_DEV_LNKSTRCVD - LPM Device Received bLinkState
 *  0b0000..Reserved for future use
 *  0b0001..L1 (Sleep mode)
 *  0b0010-0b1111..Reserved for future use
 */
#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_MASK     (0xF0000000U)
#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_SHIFT    (28U)
/*! LPM_DEV_BESLRCVD - LPM Device Received BESL */
#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_MASK)
/*! @} */

/*! @name LPM_CSR2 - USB LPM Control and Status 2 */
/*! @{ */

#define USBNC_LPM_CSR2_LPM_HST_SEND_MASK         (0x1U)
#define USBNC_LPM_CSR2_LPM_HST_SEND_SHIFT        (0U)
/*! LPM_HST_SEND - LPM Host Send Extension Token
 *  0b0..LPM transaction did not happen or is complete
 *  0b1..LPM transaction is ongoing
 */
#define USBNC_LPM_CSR2_LPM_HST_SEND(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_SEND_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_SEND_MASK)

#define USBNC_LPM_CSR2_LPM_HST_DEVADD_MASK       (0xFEU)
#define USBNC_LPM_CSR2_LPM_HST_DEVADD_SHIFT      (1U)
/*! LPM_HST_DEVADD - LPM Host Extension Token's Device Address */
#define USBNC_LPM_CSR2_LPM_HST_DEVADD(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_DEVADD_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_DEVADD_MASK)

#define USBNC_LPM_CSR2_LPM_HST_BESL_MASK         (0xF00U)
#define USBNC_LPM_CSR2_LPM_HST_BESL_SHIFT        (8U)
/*! LPM_HST_BESL - LPM Host Extension Token's BESL or HIRD */
#define USBNC_LPM_CSR2_LPM_HST_BESL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_BESL_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_BESL_MASK)

#define USBNC_LPM_CSR2_LPM_HST_RWKEN_MASK        (0x1000U)
#define USBNC_LPM_CSR2_LPM_HST_RWKEN_SHIFT       (12U)
/*! LPM_HST_RWKEN - LPM Host Extension Token's bRemoteWake
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_LPM_CSR2_LPM_HST_RWKEN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_RWKEN_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_RWKEN_MASK)

#define USBNC_LPM_CSR2_LPM_HST_STSRCVD_MASK      (0x70000000U)
#define USBNC_LPM_CSR2_LPM_HST_STSRCVD_SHIFT     (28U)
/*! LPM_HST_STSRCVD - LPM Host Response Status from the Device
 *  0b000..Invalid
 *  0b001..ACK
 *  0b010..NYET
 *  0b011..STALL
 *  0b100..Timeout
 *  0b101..ERR
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define USBNC_LPM_CSR2_LPM_HST_STSRCVD(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_STSRCVD_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_STSRCVD_MASK)
/*! @} */

/*! @name CLK_RECOVER_CTRL - USB Clock Recovery Control */
/*! @{ */

#define USBNC_CLK_RECOVER_CTRL_TRIM_INIT_VAL_SEL_MASK (0x8U)
#define USBNC_CLK_RECOVER_CTRL_TRIM_INIT_VAL_SEL_SHIFT (3U)
/*! TRIM_INIT_VAL_SEL - Selects the source for the initial FIRC192M trim fine value used after a reset.
 *  0b0..Mid-scale
 *  0b1..IFR
 */
#define USBNC_CLK_RECOVER_CTRL_TRIM_INIT_VAL_SEL(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_CTRL_TRIM_INIT_VAL_SEL_SHIFT)) & USBNC_CLK_RECOVER_CTRL_TRIM_INIT_VAL_SEL_MASK)

#define USBNC_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)
#define USBNC_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)
/*! RESTART_IFRTRIM_EN - Restart from IFR Trim Value
 *  0b0..Trim fine adjustment always works based on the previous updated trim fine value.
 *  0b1..Trim fine restarts from the IFR trim value whenever you detect bus_reset or bus_resume or deassert module enable.
 */
#define USBNC_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT)) & USBNC_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)

#define USBNC_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)
#define USBNC_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)
/*! RESET_RESUME_ROUGH_EN - Reset or Resume to Rough Phase Enable
 *  0b0..Always works in tracking phase after the first time rough phase, to track transition.
 *  0b1..Go back to rough stage whenever a bus reset or bus resume occurs.
 */
#define USBNC_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT)) & USBNC_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK)

#define USBNC_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK (0x80U)
#define USBNC_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT (7U)
/*! CLOCK_RECOVER_EN - Crystal-Less USB Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define USBNC_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT)) & USBNC_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_IRC_EN - FIRC Oscillator Enable */
/*! @{ */

#define USBNC_CLK_RECOVER_IRC_EN_IRC_EN_MASK     (0x2U)
#define USBNC_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT    (1U)
/*! IRC_EN - Fast IRC enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CLK_RECOVER_IRC_EN_IRC_EN(x)       (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT)) & USBNC_CLK_RECOVER_IRC_EN_IRC_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_EN - Clock Recovery Combined Interrupt Enable */
/*! @{ */

#define USBNC_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)
#define USBNC_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)
/*! OVF_ERROR_EN - Overflow error interrupt enable
 *  0b0..The interrupt is masked
 *  0b1..The interrupt is enabled
 */
#define USBNC_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT)) & USBNC_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_STATUS - Clock Recovery Separated Interrupt Status */
/*! @{ */

#define USBNC_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)
#define USBNC_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)
/*! OVF_ERROR - Overflow Error Interrupt Status Flag
 *  0b0..Interrupt did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Unmasked interrupt occurred
 */
#define USBNC_CLK_RECOVER_INT_STATUS_OVF_ERROR(x) (((uint8_t)(((uint8_t)(x)) << USBNC_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT)) & USBNC_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBNC_Register_Masks */

/* Backward compatibility */
#define USB_OTGn_CTRL     CTRL1
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK     USBNC_CTRL1_OVER_CUR_DIS_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT     USBNC_CTRL1_OVER_CUR_DIS_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)     USBNC_CTRL1_OVER_CUR_DIS(x)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK     USBNC_CTRL1_OVER_CUR_POL_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT     USBNC_CTRL1_OVER_CUR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)     USBNC_CTRL1_OVER_CUR_POL(x)
#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK     USBNC_CTRL1_PWR_POL_MASK
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT     USBNC_CTRL1_PWR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)     USBNC_CTRL1_PWR_POL(x)
#define USBNC_USB_OTGn_CTRL_WIE_MASK     USBNC_CTRL1_WIE_MASK
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT     USBNC_CTRL1_WIE_SHIFT
#define USBNC_USB_OTGn_CTRL_WIE(x)     USBNC_CTRL1_WIE(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK     USBNC_CTRL1_WKUP_SW_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT     USBNC_CTRL1_WKUP_SW_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)     USBNC_CTRL1_WKUP_SW_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK     USBNC_CTRL1_WKUP_SW_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT     USBNC_CTRL1_WKUP_SW_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)     USBNC_CTRL1_WKUP_SW(x)
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_MASK     USBNC_CTRL1_WKUP_ID_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_SHIFT     USBNC_CTRL1_WKUP_ID_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN(x)     USBNC_CTRL1_WKUP_ID_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK     USBNC_CTRL1_WKUP_VBUS_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT     USBNC_CTRL1_WKUP_VBUS_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)     USBNC_CTRL1_WKUP_VBUS_EN(x)
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_MASK     USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_SHIFT     USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN(x)     USBNC_CTRL1_REMOTE_WAKEUP_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK     USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)     USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK     USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT     USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)     USBNC_CTRL1_WIR(x)


/*!
 * @}
 */ /* end of group USBNC_Peripheral_Access_Layer */


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


#endif  /* PERI_USBNC_H_ */


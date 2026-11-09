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
**         CMSIS Peripheral Access Layer for TRDC
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
 * @file PERI_TRDC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRDC
 *
 * CMSIS Peripheral Access Layer for TRDC
 */

#if !defined(PERI_TRDC_H_)
#define PERI_TRDC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- TRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_Peripheral_Access_Layer TRDC Peripheral Access Layer
 * @{
 */

/** TRDC - Size of Registers Arrays */
#define MBC_MEM_GLBCFG_COUNT                      4u
#define MBC_MEMN_GLBAC_COUNT                      8u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_COUNT 16u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_COUNT 4u
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_COUNT 1u
#define TRDC_MBC_INDEX_COUNT                      1u

/** TRDC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x1AC */
    __IO uint32_t MBC_MEM_GLBCFG[MBC_MEM_GLBCFG_COUNT];   /**< MBC Global Configuration Register, array offset: 0x0, array step: index*0x1AC, index2*0x4 */
         uint8_t RESERVED_0[16];
    __IO uint32_t MBC_MEMN_GLBAC[MBC_MEMN_GLBAC_COUNT];   /**< MBC Global Access Control, array offset: 0x20, array step: index*0x1AC, index2*0x4 */
    __IO uint32_t MBC_DOM0_MEM0_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x40, array step: index*0x1AC, index2*0x4 */
         uint8_t RESERVED_1[256];
    __IO uint32_t MBC_DOM0_MEM1_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x180, array step: index*0x1AC, index2*0x4 */
         uint8_t RESERVED_2[24];
    __IO uint32_t MBC_DOM0_MEM2_BLK_CFG_W[TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_COUNT];   /**< MBC Memory Block Configuration Word, array offset: 0x1A8, array step: index*0x1AC, index2*0x4 */
  } MBC_INDEX[TRDC_MBC_INDEX_COUNT];
} TRDC_Type;

/* ----------------------------------------------------------------------------
   -- TRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_Register_Masks TRDC Register Masks
 * @{
 */

/*! @name MBC_INDEX_MBC_MEM_GLBCFG - MBC Global Configuration Register */
/*! @{ */

#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS_MASK (0x3FFU)
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS_SHIFT (0U)
/*! NBLKS - Number of blocks in this memory */
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS(x)   (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS_SHIFT)) & TRDC_MBC_INDEX_MBC_MEM_GLBCFG_NBLKS_MASK)

#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_SIZE_LOG2_MASK (0x1F0000U)
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT (16U)
/*! SIZE_LOG2 - Log2 size per block */
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_SIZE_LOG2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT)) & TRDC_MBC_INDEX_MBC_MEM_GLBCFG_SIZE_LOG2_MASK)

#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_CLRE_MASK  (0xC0000000U)
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_CLRE_SHIFT (30U)
/*! CLRE - Clear Error */
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_CLRE(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEM_GLBCFG_CLRE_SHIFT)) & TRDC_MBC_INDEX_MBC_MEM_GLBCFG_CLRE_MASK)
/*! @} */

/* The count of TRDC_MBC_INDEX_MBC_MEM_GLBCFG */
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_COUNT      (1U)

/* The count of TRDC_MBC_INDEX_MBC_MEM_GLBCFG */
#define TRDC_MBC_INDEX_MBC_MEM_GLBCFG_COUNT2     (4U)

/*! @name MBC_INDEX_MBC_MEMN_GLBAC - MBC Global Access Control */
/*! @{ */

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUX_MASK   (0x1U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUX_SHIFT  (0U)
/*! NUX - NonsecureUser Execute
 *  0b0..Execute access is not allowed in Nonsecure User mode.
 *  0b1..Execute access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUX(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUX_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUX_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUW_MASK   (0x2U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUW_SHIFT  (1U)
/*! NUW - NonsecureUser Write
 *  0b0..Write access is not allowed in Nonsecure User mode.
 *  0b1..Write access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUW(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUW_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUW_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUR_MASK   (0x4U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUR_SHIFT  (2U)
/*! NUR - NonsecureUser Read
 *  0b0..Read access is not allowed in Nonsecure User mode.
 *  0b1..Read access is allowed in Nonsecure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUR(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUR_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NUR_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPX_MASK   (0x10U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPX_SHIFT  (4U)
/*! NPX - NonsecurePriv Execute
 *  0b0..Execute access is not allowed in Nonsecure Privilege mode.
 *  0b1..Execute access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPX(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPX_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPX_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPW_MASK   (0x20U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPW_SHIFT  (5U)
/*! NPW - NonsecurePriv Write
 *  0b0..Write access is not allowed in Nonsecure Privilege mode.
 *  0b1..Write access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPW(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPW_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPW_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPR_MASK   (0x40U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPR_SHIFT  (6U)
/*! NPR - NonsecurePriv Read
 *  0b0..Read access is not allowed in Nonsecure Privilege mode.
 *  0b1..Read access is allowed in Nonsecure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPR(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPR_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_NPR_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUX_MASK   (0x100U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUX_SHIFT  (8U)
/*! SUX - SecureUser Execute
 *  0b0..Execute access is not allowed in Secure User mode.
 *  0b1..Execute access is allowed in Secure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUX(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUX_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUX_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUW_MASK   (0x200U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUW_SHIFT  (9U)
/*! SUW - SecureUser Write
 *  0b0..Write access is not allowed in Secure User mode.
 *  0b1..Write access is allowed in Secure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUW(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUW_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUW_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUR_MASK   (0x400U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUR_SHIFT  (10U)
/*! SUR - SecureUser Read
 *  0b0..Read access is not allowed in Secure User mode.
 *  0b1..Read access is allowed in Secure User mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUR(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUR_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SUR_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPX_MASK   (0x1000U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPX_SHIFT  (12U)
/*! SPX - SecurePriv Execute
 *  0b0..Execute access is not allowed in Secure Privilege mode.
 *  0b1..Execute access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPX(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPX_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPX_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPW_MASK   (0x2000U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPW_SHIFT  (13U)
/*! SPW - SecurePriv Write
 *  0b0..Write access is not allowed in Secure Privilege mode.
 *  0b1..Write access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPW(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPW_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPW_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPR_MASK   (0x4000U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPR_SHIFT  (14U)
/*! SPR - SecurePriv Read
 *  0b0..Read access is not allowed in Secure Privilege mode.
 *  0b1..Read access is allowed in Secure Privilege mode.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPR(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPR_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_SPR_MASK)

#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_LK_MASK    (0x80000000U)
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_LK_SHIFT   (31U)
/*! LK - LOCK
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered.
 */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_LK(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_MEMN_GLBAC_LK_SHIFT)) & TRDC_MBC_INDEX_MBC_MEMN_GLBAC_LK_MASK)
/*! @} */

/* The count of TRDC_MBC_INDEX_MBC_MEMN_GLBAC */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_COUNT      (1U)

/* The count of TRDC_MBC_INDEX_MBC_MEMN_GLBAC */
#define TRDC_MBC_INDEX_MBC_MEMN_GLBAC_COUNT2     (8U)

/*! @name MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_MASK (0x8U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_SHIFT (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_MASK (0x80U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_SHIFT (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_MASK (0x800U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_SHIFT (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_MASK (0x8000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_SHIFT (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_MASK (0x80000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_SHIFT (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_MASK (0x800000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_SHIFT (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_MASK (0x8000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_SHIFT (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_MASK (0x80000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_SHIFT (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_COUNT (1U)

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM0_BLK_CFG_W_MBC_DOM0_MEM0_BLK_CFG_W_COUNT2 (16U)

/*! @name MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_MASK (0x8U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_SHIFT (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_MASK (0x80U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_SHIFT (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_MASK (0x800U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_SHIFT (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_MASK (0x8000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_SHIFT (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_MASK (0x80000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_SHIFT (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_MASK (0x800000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_SHIFT (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_MASK (0x8000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_SHIFT (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_MASK (0x80000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_SHIFT (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_COUNT (1U)

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM1_BLK_CFG_W_MBC_DOM0_MEM1_BLK_CFG_W_COUNT2 (4U)

/*! @name MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W - MBC Memory Block Configuration Word */
/*! @{ */

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_MASK (0x7U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_SHIFT (0U)
/*! MBACSEL0 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_MASK (0x8U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_SHIFT (3U)
/*! NSE0 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE0(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE0_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_MASK (0x70U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_SHIFT (4U)
/*! MBACSEL1 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_MASK (0x80U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_SHIFT (7U)
/*! NSE1 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE1(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE1_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_MASK (0x700U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_SHIFT (8U)
/*! MBACSEL2 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_MASK (0x800U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_SHIFT (11U)
/*! NSE2 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE2(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE2_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_MASK (0x7000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_SHIFT (12U)
/*! MBACSEL3 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_MASK (0x8000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_SHIFT (15U)
/*! NSE3 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE3(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE3_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_MASK (0x70000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_SHIFT (16U)
/*! MBACSEL4 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_MASK (0x80000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_SHIFT (19U)
/*! NSE4 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE4(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE4_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_MASK (0x700000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_SHIFT (20U)
/*! MBACSEL5 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_MASK (0x800000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_SHIFT (23U)
/*! NSE5 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE5(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE5_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_MASK (0x7000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_SHIFT (24U)
/*! MBACSEL6 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_MASK (0x8000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_SHIFT (27U)
/*! NSE6 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE6(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE6_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_MASK (0x70000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_SHIFT (28U)
/*! MBACSEL7 - Memory Block Access Control Select for block B
 *  0b000..select MBC_MEMN_GLBAC0 access control policy for block B
 *  0b001..select MBC_MEMN_GLBAC1 access control policy for block B
 *  0b010..select MBC_MEMN_GLBAC2 access control policy for block B
 *  0b011..select MBC_MEMN_GLBAC3 access control policy for block B
 *  0b100..select MBC_MEMN_GLBAC4 access control policy for block B
 *  0b101..select MBC_MEMN_GLBAC5 access control policy for block B
 *  0b110..select MBC_MEMN_GLBAC6 access control policy for block B
 *  0b111..select MBC_MEMN_GLBAC7 access control policy for block B
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_MBACSEL7_MASK)

#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_MASK (0x80000000U)
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_SHIFT (31U)
/*! NSE7 - NonSecure Enable for block B
 *  0b0..Secure read and write to block B are based on corresponding MBACSEL field in this register
 *       (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]), secure execution and nonsecure accesses to block B are not allowed.
 *  0b1..Secure accesses to block B are not allowed, nonsecure accesses to block B are based on corresponding
 *       MBACSEL field in this register (MBCm_DOMd_MEMs_BLK_CFG_Ww[MBACSEL]).
 */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE7(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_SHIFT)) & TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_NSE7_MASK)
/*! @} */

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_COUNT (1U)

/* The count of TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W */
#define TRDC_MBC_INDEX_MBC_INDEX_DOM0_MEM2_BLK_CFG_W_MBC_DOM0_MEM2_BLK_CFG_W_COUNT2 (1U)


/*!
 * @}
 */ /* end of group TRDC_Register_Masks */


/*!
 * @}
 */ /* end of group TRDC_Peripheral_Access_Layer */


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


#endif  /* PERI_TRDC_H_ */


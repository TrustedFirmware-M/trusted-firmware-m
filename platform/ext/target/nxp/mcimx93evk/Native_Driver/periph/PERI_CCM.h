/*
** ###################################################################
**     Processors:          MIMX9301CVVXD_ca55
**                          MIMX9301CVVXD_cm33
**                          MIMX9301DVVXD_ca55
**                          MIMX9301DVVXD_cm33
**                          MIMX9302CVVXD_ca55
**                          MIMX9302CVVXD_cm33
**                          MIMX9302DVVXD_ca55
**                          MIMX9302DVVXD_cm33
**                          MIMX9311CVXXM_ca55
**                          MIMX9311CVXXM_cm33
**                          MIMX9311DVXXM_ca55
**                          MIMX9311DVXXM_cm33
**                          MIMX9311XVXXM_ca55
**                          MIMX9311XVXXM_cm33
**                          MIMX9312CVXXM_ca55
**                          MIMX9312CVXXM_cm33
**                          MIMX9312DVXXM_ca55
**                          MIMX9312DVXXM_cm33
**                          MIMX9312XVXXM_ca55
**                          MIMX9312XVXXM_cm33
**                          MIMX9321CVXXM_ca55
**                          MIMX9321CVXXM_cm33
**                          MIMX9321DVXXM_ca55
**                          MIMX9321DVXXM_cm33
**                          MIMX9321XVXXM_ca55
**                          MIMX9321XVXXM_cm33
**                          MIMX9322CVXXM_ca55
**                          MIMX9322CVXXM_cm33
**                          MIMX9322DVXXM_ca55
**                          MIMX9322DVXXM_cm33
**                          MIMX9322XVXXM_ca55
**                          MIMX9322XVXXM_cm33
**                          MIMX9331AVTXM_ca55
**                          MIMX9331AVTXM_cm33
**                          MIMX9331CVVXM_ca55
**                          MIMX9331CVVXM_cm33
**                          MIMX9331DVVXM_ca55
**                          MIMX9331DVVXM_cm33
**                          MIMX9331XVVXM_ca55
**                          MIMX9331XVVXM_cm33
**                          MIMX9332AVTXM_ca55
**                          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_ca55
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_ca55
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_ca55
**                          MIMX9332XVVXM_cm33
**                          MIMX9351AVTXM_ca55
**                          MIMX9351AVTXM_cm33
**                          MIMX9351CVVXM_ca55
**                          MIMX9351CVVXM_cm33
**                          MIMX9351DVVXM_ca55
**                          MIMX9351DVVXM_cm33
**                          MIMX9351XVVXM_ca55
**                          MIMX9351XVVXM_cm33
**                          MIMX9352AVTXM_ca55
**                          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_ca55
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_ca55
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_ca55
**                          MIMX9352XVVXM_cm33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CCM
 *
 * CMSIS Peripheral Access Layer for CCM
 */

#if !defined(PERI_CCM_H_)
#define PERI_CCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9301CVVXD_ca55) || defined(CPU_MIMX9301DVVXD_ca55))
#include "MIMX9301_ca55_COMMON.h"
#elif (defined(CPU_MIMX9301CVVXD_cm33) || defined(CPU_MIMX9301DVVXD_cm33))
#include "MIMX9301_cm33_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_ca55) || defined(CPU_MIMX9302DVVXD_ca55))
#include "MIMX9302_ca55_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_cm33) || defined(CPU_MIMX9302DVVXD_cm33))
#include "MIMX9302_cm33_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_ca55) || defined(CPU_MIMX9311DVXXM_ca55) || defined(CPU_MIMX9311XVXXM_ca55))
#include "MIMX9311_ca55_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_cm33) || defined(CPU_MIMX9311DVXXM_cm33) || defined(CPU_MIMX9311XVXXM_cm33))
#include "MIMX9311_cm33_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_ca55) || defined(CPU_MIMX9312DVXXM_ca55) || defined(CPU_MIMX9312XVXXM_ca55))
#include "MIMX9312_ca55_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_cm33) || defined(CPU_MIMX9312DVXXM_cm33) || defined(CPU_MIMX9312XVXXM_cm33))
#include "MIMX9312_cm33_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_ca55) || defined(CPU_MIMX9321DVXXM_ca55) || defined(CPU_MIMX9321XVXXM_ca55))
#include "MIMX9321_ca55_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_cm33) || defined(CPU_MIMX9321DVXXM_cm33) || defined(CPU_MIMX9321XVXXM_cm33))
#include "MIMX9321_cm33_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_ca55) || defined(CPU_MIMX9322DVXXM_ca55) || defined(CPU_MIMX9322XVXXM_ca55))
#include "MIMX9322_ca55_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_cm33) || defined(CPU_MIMX9322DVXXM_cm33) || defined(CPU_MIMX9322XVXXM_cm33))
#include "MIMX9322_cm33_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_ca55) || defined(CPU_MIMX9331CVVXM_ca55) || defined(CPU_MIMX9331DVVXM_ca55) || defined(CPU_MIMX9331XVVXM_ca55))
#include "MIMX9331_ca55_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_cm33) || defined(CPU_MIMX9331CVVXM_cm33) || defined(CPU_MIMX9331DVVXM_cm33) || defined(CPU_MIMX9331XVVXM_cm33))
#include "MIMX9331_cm33_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_ca55) || defined(CPU_MIMX9332CVVXM_ca55) || defined(CPU_MIMX9332DVVXM_ca55) || defined(CPU_MIMX9332XVVXM_ca55))
#include "MIMX9332_ca55_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_cm33) || defined(CPU_MIMX9332CVVXM_cm33) || defined(CPU_MIMX9332DVVXM_cm33) || defined(CPU_MIMX9332XVVXM_cm33))
#include "MIMX9332_cm33_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_ca55) || defined(CPU_MIMX9351CVVXM_ca55) || defined(CPU_MIMX9351DVVXM_ca55) || defined(CPU_MIMX9351XVVXM_ca55))
#include "MIMX9351_ca55_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_cm33) || defined(CPU_MIMX9351CVVXM_cm33) || defined(CPU_MIMX9351DVVXM_cm33) || defined(CPU_MIMX9351XVVXM_cm33))
#include "MIMX9351_cm33_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_ca55) || defined(CPU_MIMX9352CVVXM_ca55) || defined(CPU_MIMX9352DVVXM_ca55) || defined(CPU_MIMX9352XVVXM_ca55))
#include "MIMX9352_ca55_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_cm33) || defined(CPU_MIMX9352CVVXM_cm33) || defined(CPU_MIMX9352DVVXM_cm33) || defined(CPU_MIMX9352XVVXM_cm33))
#include "MIMX9352_cm33_COMMON.h"
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
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Size of Registers Arrays */
#define CCM_CLOCK_ROOT_COUNT                      95u
#define CCM_GPR_SHARED_COUNT                      5u
#define CCM_GPR_PRIVATE_COUNT                     8u
#define CCM_OSCPLL_COUNT                          19u
#define CCM_LPCG_COUNT                            127u

/** CCM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x80 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t RW;                                /**< Clock Root Control Register, offset: 0x0 */
      __IO uint32_t SET;                               /**< Clock Root Control Register, offset: 0x4 */
      __IO uint32_t CLR;                               /**< Clock Root Control Register, offset: 0x8 */
      __IO uint32_t TOG;                               /**< Clock Root Control Register, offset: 0xC */
    } CLOCK_ROOT_CONTROL;
         uint8_t RESERVED_0[16];
    __I  uint32_t STATUS0;                           /**< Clock root working status, array offset: 0x20, array step: 0x80 */
         uint8_t RESERVED_1[12];
    struct {                                         /* offset: 0x30 */
      __IO uint32_t RW;                                /**< Clock root access control, offset: 0x30 */
      __IO uint32_t SET;                               /**< Clock root access control, offset: 0x34 */
      __IO uint32_t CLR;                               /**< Clock root access control, offset: 0x38 */
      __IO uint32_t TOG;                               /**< Clock root access control, offset: 0x3C */
    } CLOCK_ROOT_AUTHEN;
         uint8_t RESERVED_2[64];
  } CLOCK_ROOT[CCM_CLOCK_ROOT_COUNT];
       uint8_t RESERVED_0[6272];
  struct {                                         /* offset: 0x4800 */
         uint32_t RW;                                /**< General Purpose Register, offset: 0x4800 */
         uint32_t SET;                               /**< General Purpose Register, offset: 0x4804 */
         uint32_t CLR;                               /**< General Purpose Register, offset: 0x4808 */
         uint32_t TOG;                               /**< General Purpose Register, offset: 0x480C */
  } GPR_SHARED0;
  struct {                                         /* offset: 0x4810 */
    __IO uint32_t RW;                                /**< GPR access control, offset: 0x4810 */
    __IO uint32_t SET;                               /**< GPR access control, offset: 0x4814 */
    __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4818 */
    __IO uint32_t TOG;                               /**< GPR access control, offset: 0x481C */
  } GPR_SHARED0_AUTHEN;
  struct {                                         /* offset: 0x4820 */
    __IO uint32_t RW;                                /**< General Purpose Register, offset: 0x4820 */
    __IO uint32_t SET;                               /**< General Purpose Register, offset: 0x4824 */
    __IO uint32_t CLR;                               /**< General Purpose Register, offset: 0x4828 */
    __IO uint32_t TOG;                               /**< General Purpose Register, offset: 0x482C */
  } GPR_SHARED1;
  struct {                                         /* offset: 0x4830 */
    __IO uint32_t RW;                                /**< GPR access control, offset: 0x4830 */
    __IO uint32_t SET;                               /**< GPR access control, offset: 0x4834 */
    __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4838 */
    __IO uint32_t TOG;                               /**< GPR access control, offset: 0x483C */
  } GPR_SHARED1_AUTHEN;
  struct {                                         /* offset: 0x4840 */
    __IO uint32_t RW;                                /**< General Purpose Register, offset: 0x4840 */
    __IO uint32_t SET;                               /**< General Purpose Register, offset: 0x4844 */
    __IO uint32_t CLR;                               /**< General Purpose Register, offset: 0x4848 */
    __IO uint32_t TOG;                               /**< General Purpose Register, offset: 0x484C */
  } GPR_SHARED2;
  struct {                                         /* offset: 0x4850 */
    __IO uint32_t RW;                                /**< GPR access control, offset: 0x4850 */
    __IO uint32_t SET;                               /**< GPR access control, offset: 0x4854 */
    __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4858 */
    __IO uint32_t TOG;                               /**< GPR access control, offset: 0x485C */
  } GPR_SHARED2_AUTHEN;
  struct {                                         /* offset: 0x4860, array step: 0x20 */
    struct {                                         /* offset: 0x4860 */
           uint32_t RW;                                /**< General Purpose Register, offset: 0x4860 */
           uint32_t SET;                               /**< General Purpose Register, offset: 0x4864 */
           uint32_t CLR;                               /**< General Purpose Register, offset: 0x4868 */
           uint32_t TOG;                               /**< General Purpose Register, offset: 0x486C */
    } GPR_SHARED;
    struct {                                         /* offset: 0x4870 */
      __IO uint32_t RW;                                /**< GPR access control, offset: 0x4870 */
      __IO uint32_t SET;                               /**< GPR access control, offset: 0x4874 */
      __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4878 */
      __IO uint32_t TOG;                               /**< GPR access control, offset: 0x487C */
    } GPR_SHARED_AUTHEN;
  } GPR_SHARED[CCM_GPR_SHARED_COUNT];
       uint8_t RESERVED_1[768];
  struct {                                         /* offset: 0x4C00, array step: 0x20 */
    struct {                                         /* offset: 0x4C00 */
      __IO uint32_t RW;                                /**< General puspose register, offset: 0x4C00 */
      __IO uint32_t SET;                               /**< General puspose register, offset: 0x4C04 */
      __IO uint32_t CLR;                               /**< General puspose register, offset: 0x4C08 */
      __IO uint32_t TOG;                               /**< General puspose register, offset: 0x4C0C */
    } GPR_PRIVATE;
    struct {                                         /* offset: 0x4C10 */
      __IO uint32_t RW;                                /**< GPR access control, offset: 0x4C10 */
      __IO uint32_t SET;                               /**< GPR access control, offset: 0x4C14 */
      __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4C18 */
      __IO uint32_t TOG;                               /**< GPR access control, offset: 0x4C1C */
    } GPR_PRIVATE_AUTHEN;
  } GPR_PRIVATE[CCM_GPR_PRIVATE_COUNT];
       uint8_t RESERVED_2[768];
  struct {                                         /* offset: 0x5000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< Clock source direct control, array offset: 0x5000, array step: 0x40 */
    __I  uint32_t LPM_STATUS0;                       /**< Low power mode information transfer status, array offset: 0x5004, array step: 0x40 */
    __I  uint32_t LPM_STATUS1;                       /**< Low power mode information transfer status, array offset: 0x5008, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t LPM0;                              /**< Clock source low power mode setting, array offset: 0x5010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< clock source low power mode setting, array offset: 0x5014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __I  uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x501C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< Clock source working status, array offset: 0x5020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< Clock source domain status, array offset: 0x5024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< Clock Source access control, array offset: 0x5030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } OSCPLL[CCM_OSCPLL_COUNT];
       uint8_t RESERVED_3[11072];
  struct {                                         /* offset: 0x8000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< LPCG direct control, array offset: 0x8000, array step: 0x40 */
    __I  uint32_t LPM_STATUS0;                       /**< Low power mode information transfer status, array offset: 0x8004, array step: 0x40 */
    __I  uint32_t LPM_STATUS1;                       /**< Low power mode information transfer status, array offset: 0x8008, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t LPM0;                              /**< LPCG low power mode setting, array offset: 0x8010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< LPCG low power mode setting, array offset: 0x8014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __IO uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x801C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< LPCG working status, array offset: 0x8020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< LPCG domain status, array offset: 0x8024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< LPCG access control, array offset: 0x8030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } LPCG[CCM_LPCG_COUNT];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name CLOCK_ROOT - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_DIV_MASK                  (0xFFU)
#define CCM_CLOCK_ROOT_DIV_SHIFT                 (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_DIV_SHIFT)) & CCM_CLOCK_ROOT_DIV_MASK)

#define CCM_CLOCK_ROOT_MUX_MASK                  (0x300U)
#define CCM_CLOCK_ROOT_MUX_SHIFT                 (8U)
/*! MUX - Clock multiplexer.
 *  0b00..Select clock source 0
 *  0b01..Select clock source 1
 *  0b10..Select clock source 2
 *  0b11..Select clock source 3
 */
#define CCM_CLOCK_ROOT_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_MUX_SHIFT)) & CCM_CLOCK_ROOT_MUX_MASK)

#define CCM_CLOCK_ROOT_OFF_MASK                  (0x1000000U)
#define CCM_CLOCK_ROOT_OFF_SHIFT                 (24U)
/*! OFF - Shutdown clock root.
 *  0b0..Clock is running.
 *  0b1..Turn off clock.
 */
#define CCM_CLOCK_ROOT_OFF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_OFF_SHIFT)) & CCM_CLOCK_ROOT_OFF_MASK)
/*! @} */

/*! @name CLOCK_ROOT_STATUS0 - Clock root working status */
/*! @{ */

#define CCM_CLOCK_ROOT_STATUS0_DIV_MASK          (0xFFU)
#define CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT         (0U)
/*! DIV - Current clock root DIV setting */
#define CCM_CLOCK_ROOT_STATUS0_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_DIV_MASK)

#define CCM_CLOCK_ROOT_STATUS0_MUX_MASK          (0x300U)
#define CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT         (8U)
/*! MUX - Current clock root MUX setting */
#define CCM_CLOCK_ROOT_STATUS0_MUX(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_MUX_MASK)

#define CCM_CLOCK_ROOT_STATUS0_OFF_MASK          (0x1000000U)
#define CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT         (24U)
/*! OFF - Current clock root OFF setting
 *  0b0..Clock is running.
 *  0b1..Turn off clock.
 */
#define CCM_CLOCK_ROOT_STATUS0_OFF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_OFF_MASK)

#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK   (0x10000000U)
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT  (28U)
/*! SLICE_BUSY - Indication for clock generation logic is applying new setting.
 *  0b0..Clock generation logic is not busy.
 *  0b1..Clock generation logic is applying new setting.
 */
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY(x)     (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK)

#define CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK     (0x80000000U)
#define CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT    (31U)
/*! CHANGING - Internal updating in clock root
 *  0b0..Clock Status is not updating currently
 *  0b1..Clock generation logic is updating currently
 */
#define CCM_CLOCK_ROOT_STATUS0_CHANGING(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_STATUS0 */
#define CCM_CLOCK_ROOT_STATUS0_COUNT             (95U)

/*! @name CLOCK_ROOT - Clock root access control */
/*! @{ */

#define CCM_CLOCK_ROOT_TZ_USER_MASK              (0x100U)
#define CCM_CLOCK_ROOT_TZ_USER_SHIFT             (8U)
/*! TZ_USER - User access permission
 *  0b0..Clock Root settings cannot be changed in user mode.
 *  0b1..Clock Root settings can be changed in user mode.
 */
#define CCM_CLOCK_ROOT_TZ_USER(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_TZ_USER_SHIFT)) & CCM_CLOCK_ROOT_TZ_USER_MASK)

#define CCM_CLOCK_ROOT_TZ_NS_MASK                (0x200U)
#define CCM_CLOCK_ROOT_TZ_NS_SHIFT               (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_CLOCK_ROOT_TZ_NS(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_TZ_NS_SHIFT)) & CCM_CLOCK_ROOT_TZ_NS_MASK)

#define CCM_CLOCK_ROOT_LOCK_TZ_MASK              (0x800U)
#define CCM_CLOCK_ROOT_LOCK_TZ_SHIFT             (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone setting is not locked.
 *  0b1..TrustZone setting is locked.
 */
#define CCM_CLOCK_ROOT_LOCK_TZ(x)                (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_LOCK_TZ_SHIFT)) & CCM_CLOCK_ROOT_LOCK_TZ_MASK)

#define CCM_CLOCK_ROOT_LOCK_LIST_MASK            (0x8000U)
#define CCM_CLOCK_ROOT_LOCK_LIST_SHIFT           (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_CLOCK_ROOT_LOCK_LIST(x)              (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_LOCK_LIST_SHIFT)) & CCM_CLOCK_ROOT_LOCK_LIST_MASK)

#define CCM_CLOCK_ROOT_WHITE_LIST_MASK           (0xFFFF0000U)
#define CCM_CLOCK_ROOT_WHITE_LIST_SHIFT          (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_CLOCK_ROOT_WHITE_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_WHITE_LIST_SHIFT)) & CCM_CLOCK_ROOT_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED0_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED1_CA55_CLOCK_SELECT_MASK   (0x1U)
#define CCM_GPR_SHARED1_CA55_CLOCK_SELECT_SHIFT  (0U)
/*! CA55_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..Clkroot_arm_a55 is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CLOCK_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CLOCK_SELECT_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS_MASK     (0x1U)
#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS_SHIFT    (0U)
/*! DRAM_PLL_BYPASS - Clock select signal between ccm clock root and DRAM PLL clock
 *  0b0..The clock output of DRAM PLL is selected.
 *  0b1..Dram_alt_clk_root is selected.
 */
#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_DRAM_PLL_BYPASS_SHIFT)) & CCM_GPR_SHARED2_DRAM_PLL_BYPASS_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED_TZ_USER_MASK              (0x100U)
#define CCM_GPR_SHARED_TZ_USER_SHIFT             (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED_TZ_USER(x)                (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_TZ_USER_SHIFT)) & CCM_GPR_SHARED_TZ_USER_MASK)

#define CCM_GPR_SHARED_TZ_NS_MASK                (0x200U)
#define CCM_GPR_SHARED_TZ_NS_SHIFT               (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED_TZ_NS(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_TZ_NS_SHIFT)) & CCM_GPR_SHARED_TZ_NS_MASK)

#define CCM_GPR_SHARED_LOCK_TZ_MASK              (0x800U)
#define CCM_GPR_SHARED_LOCK_TZ_SHIFT             (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED_LOCK_TZ(x)                (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED_LOCK_TZ_MASK)

#define CCM_GPR_SHARED_LOCK_LIST_MASK            (0x8000U)
#define CCM_GPR_SHARED_LOCK_LIST_SHIFT           (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED_LOCK_LIST(x)              (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED_LOCK_LIST_MASK)

#define CCM_GPR_SHARED_WHITE_LIST_MASK           (0xFFFF0000U)
#define CCM_GPR_SHARED_WHITE_LIST_SHIFT          (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED_WHITE_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_PRIVATE - General puspose register */
/*! @{ */

#define CCM_GPR_PRIVATE_GPR_MASK                 (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_GPR_SHIFT                (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_GPR(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_GPR_SHIFT)) & CCM_GPR_PRIVATE_GPR_MASK)
/*! @} */

/*! @name GPR_PRIVATE - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_TZ_USER_MASK             (0x100U)
#define CCM_GPR_PRIVATE_TZ_USER_SHIFT            (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of privat GPR cannot be changed in user mode.
 *  0b1..Registers of private GPR can be changed in user mode.
 */
#define CCM_GPR_PRIVATE_TZ_USER(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_TZ_NS_MASK               (0x200U)
#define CCM_GPR_PRIVATE_TZ_NS_SHIFT              (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_PRIVATE_TZ_NS(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_LOCK_TZ_MASK             (0x800U)
#define CCM_GPR_PRIVATE_LOCK_TZ_SHIFT            (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_PRIVATE_LOCK_TZ(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_LOCK_LIST_MASK           (0x8000U)
#define CCM_GPR_PRIVATE_LOCK_LIST_SHIFT          (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_PRIVATE_LOCK_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_WHITE_LIST_MASK          (0xFFFF0000U)
#define CCM_GPR_PRIVATE_WHITE_LIST_SHIFT         (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_PRIVATE_WHITE_LIST(x)            (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_WHITE_LIST_MASK)
/*! @} */

/*! @name OSCPLL_DIRECT - Clock source direct control */
/*! @{ */

#define CCM_OSCPLL_DIRECT_ON_MASK                (0x1U)
#define CCM_OSCPLL_DIRECT_ON_SHIFT               (0U)
/*! ON - Turn on clock source
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_DIRECT_ON(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_DIRECT_ON_SHIFT)) & CCM_OSCPLL_DIRECT_ON_MASK)
/*! @} */

/* The count of CCM_OSCPLL_DIRECT */
#define CCM_OSCPLL_DIRECT_COUNT                  (19U)

/*! @name OSCPLL_LPM_STATUS0 - Low power mode information transfer status */
/*! @{ */

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK (0x3U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT (0U)
/*! CPU_MODE_DOMAIN0 - Current mode of CPU domain 0
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK (0x4U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT (2U)
/*! TRANS_REQ_DOMAIN0 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK (0x30U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT (4U)
/*! CPU_MODE_DOMAIN1 - Current mode of CPU domain 1
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK (0x40U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT (6U)
/*! TRANS_REQ_DOMAIN1 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK (0x300U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT (8U)
/*! CPU_MODE_DOMAIN2 - Current mode of CPU domain 2
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK (0x400U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT (10U)
/*! TRANS_REQ_DOMAIN2 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK (0x3000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT (12U)
/*! CPU_MODE_DOMAIN3 - Current mode of CPU domain 3
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK (0x4000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT (14U)
/*! TRANS_REQ_DOMAIN3 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK (0x30000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT (16U)
/*! CPU_MODE_DOMAIN4 - Current mode of CPU domain 4
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK (0x40000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT (18U)
/*! TRANS_REQ_DOMAIN4 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK (0x300000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT (20U)
/*! CPU_MODE_DOMAIN5 - Current mode of CPU domain 5
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK (0x400000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT (22U)
/*! TRANS_REQ_DOMAIN5 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK (0x3000000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT (24U)
/*! CPU_MODE_DOMAIN6 - Current mode of CPU domain 6
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK (0x4000000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT (26U)
/*! TRANS_REQ_DOMAIN6 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK (0x30000000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT (28U)
/*! CPU_MODE_DOMAIN7 - Current mode of CPU domain 7
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK (0x40000000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT (30U)
/*! TRANS_REQ_DOMAIN7 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_STATUS0 */
#define CCM_OSCPLL_LPM_STATUS0_COUNT             (19U)

/*! @name OSCPLL_LPM_STATUS1 - Low power mode information transfer status */
/*! @{ */

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK (0x3U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT (0U)
/*! CPU_MODE_DOMAIN8 - Current mode of CPU domain 8
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK (0x4U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT (2U)
/*! TRANS_REQ_DOMAIN8 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK (0x30U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT (4U)
/*! CPU_MODE_DOMAIN9 - Current mode of CPU domain 9
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK (0x40U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT (6U)
/*! TRANS_REQ_DOMAIN9 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK (0x300U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT (8U)
/*! CPU_MODE_DOMAIN10 - Current mode of CPU domain 10
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK (0x400U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT (10U)
/*! TRANS_REQ_DOMAIN10 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK (0x3000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT (12U)
/*! CPU_MODE_DOMAIN11 - Current mode of CPU domain 11
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK (0x4000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT (14U)
/*! TRANS_REQ_DOMAIN11 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK (0x30000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT (16U)
/*! CPU_MODE_DOMAIN12 - Current mode of CPU domain 12
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK (0x40000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT (18U)
/*! TRANS_REQ_DOMAIN12 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK (0x300000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT (20U)
/*! CPU_MODE_DOMAIN13 - Current mode of CPU domain 13
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK (0x400000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT (22U)
/*! TRANS_REQ_DOMAIN13 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK (0x3000000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT (24U)
/*! CPU_MODE_DOMAIN14 - Current mode of CPU domain 14
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK (0x4000000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT (26U)
/*! TRANS_REQ_DOMAIN14 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK (0x30000000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT (28U)
/*! CPU_MODE_DOMAIN15 - Current mode of CPU domain 15
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK (0x40000000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT (30U)
/*! TRANS_REQ_DOMAIN15 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_STATUS1 */
#define CCM_OSCPLL_LPM_STATUS1_COUNT             (19U)

/*! @name OSCPLL_LPM0 - Clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK      (0x7U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT     (0U)
/*! LPM_SETTING_D0 - Clock Source LPM in DOMAIN0
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK      (0x70U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT     (4U)
/*! LPM_SETTING_D1 - Clock Source LPM in DOMAIN1
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK      (0x700U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT     (8U)
/*! LPM_SETTING_D2 - Clock Source LPM in DOMAIN2
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK      (0x7000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT     (12U)
/*! LPM_SETTING_D3 - Clock Source LPM in DOMAIN3
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK      (0x70000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT     (16U)
/*! LPM_SETTING_D4 - Clock Source LPM in DOMAIN4
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK      (0x700000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT     (20U)
/*! LPM_SETTING_D5 - Clock Source LPM in DOMAIN5
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK      (0x7000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT     (24U)
/*! LPM_SETTING_D6 - Clock Source LPM in DOMAIN6
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK      (0x70000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT     (28U)
/*! LPM_SETTING_D7 - Clock Source LPM in DOMAIN7
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM0 */
#define CCM_OSCPLL_LPM0_COUNT                    (19U)

/*! @name OSCPLL_LPM1 - clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK      (0x7U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT     (0U)
/*! LPM_SETTING_D8 - Clock Source LPM in DOMAIN8
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK      (0x70U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT     (4U)
/*! LPM_SETTING_D9 - Clock Source LPM in DOMAIN9
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK     (0x700U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT    (8U)
/*! LPM_SETTING_D10 - Clock Source LPM in DOMAIN10
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK     (0x7000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT    (12U)
/*! LPM_SETTING_D11 - Clock Source LPM in DOMAIN11
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK     (0x70000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT    (16U)
/*! LPM_SETTING_D12 - Clock Source LPM in DOMAIN12
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK     (0x700000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT    (20U)
/*! LPM_SETTING_D13 - Clock Source LPM in DOMAIN13
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK     (0x7000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT    (24U)
/*! LPM_SETTING_D14 - Clock Source LPM in DOMAIN14
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK     (0x70000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT    (28U)
/*! LPM_SETTING_D15 - Clock Source LPM in DOMAIN15
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM1 */
#define CCM_OSCPLL_LPM1_COUNT                    (19U)

/*! @name OSCPLL_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK  (0x7U)
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT (0U)
/*! LPM_SETTING_CUR - LPM SETTING of current CPU DOMAIN */
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR(x)    (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_CUR */
#define CCM_OSCPLL_LPM_CUR_COUNT                 (19U)

/*! @name OSCPLL_STATUS0 - Clock source working status */
/*! @{ */

#define CCM_OSCPLL_STATUS0_ON_MASK               (0x1U)
#define CCM_OSCPLL_STATUS0_ON_SHIFT              (0U)
/*! ON - Clock source current state
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_STATUS0_ON(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_ON_SHIFT)) & CCM_OSCPLL_STATUS0_ON_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK     (0x10U)
#define CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT    (4U)
#define CCM_OSCPLL_STATUS0_STATUS_EARLY(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_LATE_MASK      (0x20U)
#define CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT     (5U)
#define CCM_OSCPLL_STATUS0_STATUS_LATE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_LATE_MASK)

#define CCM_OSCPLL_STATUS0_IN_USE_MASK           (0x1000U)
#define CCM_OSCPLL_STATUS0_IN_USE_SHIFT          (12U)
/*! IN_USE - This Clock Source is being used or not.
 *  0b0..Clock Source is not being used.
 *  0b1..Clock Source is being used.
 */
#define CCM_OSCPLL_STATUS0_IN_USE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_IN_USE_SHIFT)) & CCM_OSCPLL_STATUS0_IN_USE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS0 */
#define CCM_OSCPLL_STATUS0_COUNT                 (19U)

/*! @name OSCPLL_STATUS1 - Clock source domain status */
/*! @{ */

#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK    (0xFFFFU)
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT   (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK    (0xFFFF0000U)
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT   (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS1 */
#define CCM_OSCPLL_STATUS1_COUNT                 (19U)

/*! @name OSCPLL_AUTHEN - Clock Source access control */
/*! @{ */

#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK       (0x4U)
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT      (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode.
 *  0b1..Enable CPULPM mode.
 */
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK)

#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK         (0x8U)
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT        (3U)
/*! AUTO_CTRL - Auto mode enable
 *  0b0..Disable Auto mode
 *  0b1..Enable Auto mode
 */
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT)) & CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_MODE_MASK         (0x80U)
#define CCM_OSCPLL_AUTHEN_LOCK_MODE_SHIFT        (7U)
/*! LOCK_MODE
 *  0b0..CPULPM_MODE and AUTO_CTRL is not locked.
 *  0b1..CPULPM_MODE and AUTO_CTRL is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_MODE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_MODE_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_MODE_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_USER_MASK           (0x100U)
#define CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT          (8U)
/*! TZ_USER - User access permission
 *  0b0..Clock Source settings cannot be changed in user mode.
 *  0b1..Clock Source settings can be changed in user mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_USER(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_USER_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_NS_MASK             (0x200U)
#define CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT            (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_NS(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_NS_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK           (0x800U)
#define CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT          (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_TZ(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK         (0x8000U)
#define CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT        (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_LIST(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK)

#define CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK        (0xFFFF0000U)
#define CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT       (16U)
/*! WHITE_LIST - Whitelist */
#define CCM_OSCPLL_AUTHEN_WHITE_LIST(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OSCPLL_AUTHEN */
#define CCM_OSCPLL_AUTHEN_COUNT                  (19U)

/*! @name LPCG_DIRECT - LPCG direct control */
/*! @{ */

#define CCM_LPCG_DIRECT_ON_MASK                  (0x1U)
#define CCM_LPCG_DIRECT_ON_SHIFT                 (0U)
/*! ON - Turn on LPCG
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_DIRECT_ON(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_ON_SHIFT)) & CCM_LPCG_DIRECT_ON_MASK)

#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK (0x4U)
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT (2U)
/*! CLKOFF_ACK_TIMEOUT_EN - Clock off handshake timeout enable
 *  0b0..disable
 *  0b1..enable
 */
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT)) & CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK)
/*! @} */

/* The count of CCM_LPCG_DIRECT */
#define CCM_LPCG_DIRECT_COUNT                    (127U)

/*! @name LPCG_LPM_STATUS0 - Low power mode information transfer status */
/*! @{ */

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK (0x3U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT (0U)
/*! CPU_MODE_DOMAIN0 - Current mode of CPU domain 0
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK (0x4U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT (2U)
/*! TRANS_REQ_DOMAIN0 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK (0x30U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT (4U)
/*! CPU_MODE_DOMAIN1 - Current mode of CPU domain 1
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK (0x40U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT (6U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK (0x300U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT (8U)
/*! CPU_MODE_DOMAIN2 - Current mode of CPU domain 2
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK (0x400U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT (10U)
/*! TRANS_REQ_DOMAIN2 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK (0x3000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT (12U)
/*! CPU_MODE_DOMAIN3 - Current mode of CPU domain 3
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK (0x4000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT (14U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK (0x30000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT (16U)
/*! CPU_MODE_DOMAIN4 - Current mode of CPU domain 4
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK (0x40000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT (18U)
/*! TRANS_REQ_DOMAIN4 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK (0x300000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT (20U)
/*! CPU_MODE_DOMAIN5 - Current mode of CPU domain 5
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK (0x400000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT (22U)
/*! TRANS_REQ_DOMAIN5 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK (0x3000000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT (24U)
/*! CPU_MODE_DOMAIN6 - Current mode of CPU domain 6
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK (0x4000000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT (26U)
/*! TRANS_REQ_DOMAIN6 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK (0x30000000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT (28U)
/*! CPU_MODE_DOMAIN7 - Current mode of CPU domain 7
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK (0x40000000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT (30U)
/*! TRANS_REQ_DOMAIN7 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_STATUS0 */
#define CCM_LPCG_LPM_STATUS0_COUNT               (127U)

/*! @name LPCG_LPM_STATUS1 - Low power mode information transfer status */
/*! @{ */

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK (0x3U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT (0U)
/*! CPU_MODE_DOMAIN8 - Current mode of CPU domain 8
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK (0x4U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT (2U)
/*! TRANS_REQ_DOMAIN8 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK (0x30U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT (4U)
/*! CPU_MODE_DOMAIN9 - Current mode of CPU domain 9
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK (0x40U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT (6U)
/*! TRANS_REQ_DOMAIN9 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK (0x300U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT (8U)
/*! CPU_MODE_DOMAIN10 - Current mode of CPU domain 10
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK (0x400U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT (10U)
/*! TRANS_REQ_DOMAIN10 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK (0x3000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT (12U)
/*! CPU_MODE_DOMAIN11 - Current mode of CPU domain 11
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK (0x4000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT (14U)
/*! TRANS_REQ_DOMAIN11 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK (0x30000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT (16U)
/*! CPU_MODE_DOMAIN12 - Current mode of CPU domain 12
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK (0x40000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT (18U)
/*! TRANS_REQ_DOMAIN12 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK (0x300000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT (20U)
/*! CPU_MODE_DOMAIN13 - Current mode of CPU domain 13
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK (0x400000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT (22U)
/*! TRANS_REQ_DOMAIN13 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK (0x3000000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT (24U)
/*! CPU_MODE_DOMAIN14 - Current mode of CPU domain 14
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK (0x4000000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT (26U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK (0x30000000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT (28U)
/*! CPU_MODE_DOMAIN15 - Current mode of CPU domain 15
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK (0x40000000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT (30U)
/*! TRANS_REQ_DOMAIN15 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_STATUS1 */
#define CCM_LPCG_LPM_STATUS1_COUNT               (127U)

/*! @name LPCG_LPM0 - LPCG low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM0_LPM_SETTING_D0_MASK        (0x7U)
#define CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT       (0U)
/*! LPM_SETTING_D0 - LPCG LPM in DOMAIN0
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D0(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D0_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D1_MASK        (0x70U)
#define CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT       (4U)
/*! LPM_SETTING_D1 - LPCG LPM in DOMAIN1
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D1_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D2_MASK        (0x700U)
#define CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT       (8U)
/*! LPM_SETTING_D2 - LPCG LPM in DOMAIN2
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D2_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D3_MASK        (0x7000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT       (12U)
/*! LPM_SETTING_D3
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D3_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D4_MASK        (0x70000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT       (16U)
/*! LPM_SETTING_D4
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D4(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D4_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D5_MASK        (0x700000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT       (20U)
/*! LPM_SETTING_D5
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D5(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D5_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D6_MASK        (0x7000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT       (24U)
/*! LPM_SETTING_D6
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D6(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D6_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D7_MASK        (0x70000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT       (28U)
/*! LPM_SETTING_D7
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D7(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM0 */
#define CCM_LPCG_LPM0_COUNT                      (127U)

/*! @name LPCG_LPM1 - LPCG low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM1_LPM_SETTING_D8_MASK        (0x7U)
#define CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT       (0U)
/*! LPM_SETTING_D8
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D8(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D8_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D9_MASK        (0x70U)
#define CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT       (4U)
/*! LPM_SETTING_D9
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D9(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D9_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D10_MASK       (0x700U)
#define CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT      (8U)
/*! LPM_SETTING_D10
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D10(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D10_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D11_MASK       (0x7000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT      (12U)
/*! LPM_SETTING_D11
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D11(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D11_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D12_MASK       (0x70000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT      (16U)
/*! LPM_SETTING_D12
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D12(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D12_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D13_MASK       (0x700000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT      (20U)
/*! LPM_SETTING_D13
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D13(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D13_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D14_MASK       (0x7000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT      (24U)
/*! LPM_SETTING_D14
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D14(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D14_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D15_MASK       (0x70000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT      (28U)
/*! LPM_SETTING_D15
 *  0b000..LPCG will be OFF in any CPU mode.
 *  0b001..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..LPCG will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D15(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM1 */
#define CCM_LPCG_LPM1_COUNT                      (127U)

/*! @name LPCG_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK    (0x7U)
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT   (0U)
/*! LPM_SETTING_CUR - LPM SETTING of current CPU DOMAIN */
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR(x)      (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_CUR */
#define CCM_LPCG_LPM_CUR_COUNT                   (127U)

/*! @name LPCG_STATUS0 - LPCG working status */
/*! @{ */

#define CCM_LPCG_STATUS0_ON_MASK                 (0x1U)
#define CCM_LPCG_STATUS0_ON_SHIFT                (0U)
/*! ON - LPCG work status
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_STATUS0_ON(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS0_ON_SHIFT)) & CCM_LPCG_STATUS0_ON_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS0 */
#define CCM_LPCG_STATUS0_COUNT                   (127U)

/*! @name LPCG_STATUS1 - LPCG domain status */
/*! @{ */

#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK      (0xFFFFU)
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT     (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK      (0xFFFF0000U)
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT     (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS1 */
#define CCM_LPCG_STATUS1_COUNT                   (127U)

/*! @name LPCG_AUTHEN - LPCG access control */
/*! @{ */

#define CCM_LPCG_AUTHEN_CPULPM_MODE_MASK         (0x4U)
#define CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT        (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode, this LPCG is in Direct Control mode.
 *  0b1..Enable CPULPM mode, this LPCG is in CPULPM mode.
 */
#define CCM_LPCG_AUTHEN_CPULPM_MODE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_LPCG_AUTHEN_CPULPM_MODE_MASK)

#define CCM_LPCG_AUTHEN_LOCK_MODE_MASK           (0x80U)
#define CCM_LPCG_AUTHEN_LOCK_MODE_SHIFT          (7U)
/*! LOCK_MODE
 *  0b0..CPULPM_MODE is not locked.
 *  0b1..CPULPM_MODE is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_MODE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_MODE_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_MODE_MASK)

#define CCM_LPCG_AUTHEN_TZ_USER_MASK             (0x100U)
#define CCM_LPCG_AUTHEN_TZ_USER_SHIFT            (8U)
/*! TZ_USER - User access permission
 *  0b0..LPCG settings cannot be changed in user mode.
 *  0b1..LPCG settings can be changed in user mode.
 */
#define CCM_LPCG_AUTHEN_TZ_USER(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_USER_SHIFT)) & CCM_LPCG_AUTHEN_TZ_USER_MASK)

#define CCM_LPCG_AUTHEN_TZ_NS_MASK               (0x200U)
#define CCM_LPCG_AUTHEN_TZ_NS_SHIFT              (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_LPCG_AUTHEN_TZ_NS(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_NS_SHIFT)) & CCM_LPCG_AUTHEN_TZ_NS_MASK)

#define CCM_LPCG_AUTHEN_LOCK_TZ_MASK             (0x800U)
#define CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT            (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_TZ(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_TZ_MASK)

#define CCM_LPCG_AUTHEN_LOCK_LIST_MASK           (0x8000U)
#define CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT          (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_LIST_MASK)

#define CCM_LPCG_AUTHEN_WHITE_LIST_MASK          (0xFFFF0000U)
#define CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT         (16U)
/*! WHITE_LIST - Whitelist */
#define CCM_LPCG_AUTHEN_WHITE_LIST(x)            (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT)) & CCM_LPCG_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_LPCG_AUTHEN */
#define CCM_LPCG_AUTHEN_COUNT                    (127U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_H_ */

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
**         CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
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
 * @file PERI_BLK_CTRL_WAKEUPMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 */

#if !defined(PERI_BLK_CTRL_WAKEUPMIX_H_)
#define PERI_BLK_CTRL_WAKEUPMIX_H_               /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_WAKEUPMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer BLK_CTRL_WAKEUPMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_WAKEUPMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG DEBUG mask bit, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t QCH_DIS;                           /**< QCHANNEL DISABLE, offset: 0x10 */
       uint8_t RESERVED_2[8];
  __IO uint32_t DEXSC_ERR;                         /**< DEXSC error response configuration, offset: 0x1C */
  __IO uint32_t MQS_SETTING;                       /**< MQS Settings for MQS2, offset: 0x20 */
  __IO uint32_t SAI_CLK_SEL;                       /**< SAI2 and SAI3 MCLK1~3 CLK root mux settings, offset: 0x24 */
  __IO uint32_t GPR;                               /**< ENET QOS control signals, offset: 0x28 */
  __IO uint32_t ENET_CLK_SEL;                      /**< ENET CLK direction selection, offset: 0x2C */
       uint8_t RESERVED_3[4];
  __I  uint32_t VOLT_DETECT;                       /**< Voltage detectors output, offset: 0x34 */
  __IO uint32_t I3C2_WAKEUP;                       /**< I3C2 WAKEUPX CLR, offset: 0x38 */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG mask bit for CA55 core0, offset: 0x3C */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG DEBUG mask bit for CA55 core1, offset: 0x40 */
  __IO uint32_t AXI_ATTR_CFG;                      /**< AXI CACHE OVERRITE BIT, offset: 0x44 */
  __IO uint32_t I3C2_SDA_IRQ;                      /**< I3C SDA IRQ Control, offset: 0x48 */
} BLK_CTRL_WAKEUPMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Register_Masks BLK_CTRL_WAKEUPMIX Register Masks
 * @{
 */

/*! @name IPG_DEBUG_CM33 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_SHIFT (0U)
/*! CAN2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_SHIFT (1U)
/*! EDMA2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_SHIFT (2U)
/*! FLEXIO1
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_SHIFT (3U)
/*! FLEXIO2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_SHIFT (4U)
/*! LPI2C3
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_SHIFT (5U)
/*! LPI2C4
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_SHIFT (6U)
/*! LPI2C5
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_SHIFT (7U)
/*! LPI2C6
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_SHIFT (8U)
/*! LPI2C7
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_SHIFT (9U)
/*! LPI2C8
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_SHIFT (10U)
/*! LPIT2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_SHIFT (11U)
/*! LPSPI3
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_SHIFT (12U)
/*! LPSPI4
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_SHIFT (13U)
/*! LPSPI5
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_SHIFT (14U)
/*! LPSPI6
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_SHIFT (15U)
/*! LPSPI7
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_SHIFT (16U)
/*! LPSPI8
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_SHIFT (17U)
/*! LPTMR2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_SHIFT (18U)
/*! TPM3
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_SHIFT (19U)
/*! TPM4
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_SHIFT (20U)
/*! TPM5
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_SHIFT (21U)
/*! TPM6
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG3_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG3_SHIFT (22U)
/*! WDOG3
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG4_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG4_SHIFT (23U)
/*! WDOG4
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_SHIFT (24U)
/*! WDOG5
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_SHIFT (25U)
/*! I3C2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_SHIFT (26U)
/*! SAI2
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_SHIFT (27U)
/*! SAI3
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_ENET1_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_ENET1_SHIFT (28U)
/*! ENET1
 *  0b0..Module does not enter debug halted mode with CM33
 *  0b1..Module enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_ENET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_ENET1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_ENET1_MASK)
/*! @} */

/*! @name QCH_DIS - QCHANNEL DISABLE */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO2_MASK    (0x1U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO2_SHIFT   (0U)
/*! GPIO2 - GPIO2 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO2(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO3_MASK    (0x2U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO3_SHIFT   (1U)
/*! GPIO3
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO3(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_GPIO3_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO1_MASK  (0x4U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO1_SHIFT (2U)
/*! FLEXIO1 - FLEXIO1 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO1(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO2_MASK  (0x8U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO2_SHIFT (3U)
/*! FLEXIO2 - FLEXIO2 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO2(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI3_MASK   (0x10U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI3_SHIFT  (4U)
/*! LPSPI3 - LPSPI3 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI3(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI4_MASK   (0x20U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI4_SHIFT  (5U)
/*! LPSPI4 - LPSPI4 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI4(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART3_MASK  (0x40U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART3_SHIFT (6U)
/*! LPUART3 - LPUART3 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART3(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART3_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART4_MASK  (0x80U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART4_SHIFT (7U)
/*! LPUART4 - LPUART4 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART4(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART4_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART5_MASK  (0x100U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART5_SHIFT (8U)
/*! LPUART5 - LPUART5 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART5(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART5_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART5_MASK)

#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART6_MASK  (0x200U)
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART6_SHIFT (9U)
/*! LPUART6 - LPUART6 QCHANNEL disable
 *  0b0..QCHANNEL is enabled
 *  0b1..QCHANNEL is disabled
 */
#define BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART6(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART6_SHIFT)) & BLK_CTRL_WAKEUPMIX_QCH_DIS_LPUART6_MASK)
/*! @} */

/*! @name DEXSC_ERR - DEXSC error response configuration */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_SHIFT (0U)
/*! EXC_ERR_RESP_EN - Exclusive error response enable
 *  0b0..OKAY response
 *  0b1..SLVError response
 */
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_SHIFT (1U)
/*! LOCK_EXC_ERR_RESP_EN - Lock bit of EXC_ERR_RESP_EN */
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_MASK)
/*! @} */

/*! @name MQS_SETTING - MQS Settings for MQS2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SAI_SEL_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SAI_SEL_SHIFT (0U)
/*! SAI_SEL - SAI select
 *  0b0..SAI2
 *  0b1..SAI3
 */
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SAI_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS_SETTING_SAI_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS_SETTING_SAI_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_MQS_EN_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_MQS_EN_SHIFT (1U)
/*! MQS_EN - MQS Enable
 *  0b0..MQS2 is disabled
 *  0b1..MQS2 is enabled
 */
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_MQS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS_SETTING_MQS_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS_SETTING_MQS_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SOFT_RESET_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SOFT_RESET_SHIFT (2U)
/*! SOFT_RESET - Software Reset
 *  0b0..Reset is enabled
 *  0b1..Reset is disabled
 */
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS_SETTING_SOFT_RESET_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS_SETTING_SOFT_RESET_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_OVERSAMPLE_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_OVERSAMPLE_SHIFT (3U)
/*! OVERSAMPLE - Oversample enable
 *  0b0..32
 *  0b1..64
 */
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS_SETTING_OVERSAMPLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS_SETTING_OVERSAMPLE_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_CLK_DIVIDE_MASK (0xFF00U)
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_CLK_DIVIDE_SHIFT (8U)
/*! CLK_DIVIDE - Clock divide factor configuration
 *  0b00000000..hmclk frequency
 *  0b00000001..hmclk frequency x 1/2
 *  0b00000010..hmclk frequency x 1/3
 *  0b00000011..hmclk frequency x 1/4
 *  0b00000100-0b11111111..mclk frequency = hmclk frequency x 1/(n+1)
 */
#define BLK_CTRL_WAKEUPMIX_MQS_SETTING_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS_SETTING_CLK_DIVIDE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS_SETTING_CLK_DIVIDE_MASK)
/*! @} */

/*! @name SAI_CLK_SEL - SAI2 and SAI3 MCLK1~3 CLK root mux settings */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_SHIFT (0U)
/*! SAI2_MCLK1 - SAI2 MCLK1 clock source selection
 *  0b0..SAI2 CLK_ROOT from CCM
 *  0b1..SAI2 MCLK
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_MASK (0xEU)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_SHIFT (1U)
/*! SAI2_MCLK2 - SAI2 MCLK2 clock source selection
 *  0b000..SAI1 CLK ROOT from CCM
 *  0b001..SAI2 CLK ROOT from CCM
 *  0b010..SAI3 CLK ROOT from CCM
 *  0b011..SAI1_MCLK from IOMUX
 *  0b100..SAI2_MCLK from IOMUX
 *  0b101..SAI3_MCLK from IOMUX
 *  0b110..SPDIF CLK ROOT from CCM
 *  0b111..SPDIF RX clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_SHIFT (4U)
/*! SAI2_MCLK3 - SAI2 MCLK3 clock source selection
 *  0b000..SAI1 CLK ROOT from CCM
 *  0b001..SAI2 CLK ROOT from CCM
 *  0b010..SAI3 CLK ROOT from CCM
 *  0b011..SAI1_MCLK from IOMUX
 *  0b100..SAI2_MCLK from IOMUX
 *  0b101..SAI3_MCLK from IOMUX
 *  0b110..SPDIF CLK ROOT from CCM
 *  0b111..SPDIF RX clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT (16U)
/*! SAI3_MCLK1 - SAI3 MCLK1 clock source selection
 *  0b0..SAI3 CLK_ROOT from CCM
 *  0b1..SAI3 MCLK
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK (0xE0000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT (17U)
/*! SAI3_MCLK2 - SAI2 MCLK2 clock source selection
 *  0b000..SAI1 CLK ROOT from CCM
 *  0b001..SAI2 CLK ROOT from CCM
 *  0b010..SAI3 CLK ROOT from CCM
 *  0b011..SAI1_MCLK from IOMUX
 *  0b100..SAI2_MCLK from IOMUX
 *  0b101..SAI3_MCLK from IOMUX
 *  0b110..SPDIF CLK ROOT from CCM
 *  0b111..SPDIF RX clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT (20U)
/*! SAI3_MCLK3 - SAI3 MCLK3 clock source selection
 *  0b000..SAI1 CLK ROOT from CCM
 *  0b001..SAI2 CLK ROOT from CCM
 *  0b010..SAI3 CLK ROOT from CCM
 *  0b011..SAI1_MCLK from IOMUX
 *  0b100..SAI2_MCLK from IOMUX
 *  0b101..SAI3_MCLK from IOMUX
 *  0b110..SPDIF CLK ROOT from CCM
 *  0b111..SPDIF RX clock
 */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK)
/*! @} */

/*! @name GPR - ENET QOS control signals */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPR_ENABLE_MASK       (0x1U)
#define BLK_CTRL_WAKEUPMIX_GPR_ENABLE_SHIFT      (0U)
/*! ENABLE - ENET QOS enable
 *  0b0..ENET QoS is disabled
 *  0b1..ENET QoS is enabled
 */
#define BLK_CTRL_WAKEUPMIX_GPR_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPR_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPR_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_GPR_MODE_MASK         (0xEU)
#define BLK_CTRL_WAKEUPMIX_GPR_MODE_SHIFT        (1U)
/*! MODE - ENET QOS mode selection
 *  0b000..MII mode is selected
 *  0b001..RGMII mode is selected
 *  0b100..RMII mode is selected
 */
#define BLK_CTRL_WAKEUPMIX_GPR_MODE(x)           (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPR_MODE_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPR_MODE_MASK)

#define BLK_CTRL_WAKEUPMIX_GPR_DIS_CRC_CHK_MASK  (0x10U)
#define BLK_CTRL_WAKEUPMIX_GPR_DIS_CRC_CHK_SHIFT (4U)
/*! DIS_CRC_CHK - Disable ENET QoS CRC check
 *  0b0..CRC check is disabled
 *  0b1..CRC check is enabled
 */
#define BLK_CTRL_WAKEUPMIX_GPR_DIS_CRC_CHK(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPR_DIS_CRC_CHK_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPR_DIS_CRC_CHK_MASK)
/*! @} */

/*! @name ENET_CLK_SEL - ENET CLK direction selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET_QOS_CLK_TX_CLK_SEL_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET_QOS_CLK_TX_CLK_SEL_SHIFT (0U)
/*! ENET_QOS_CLK_TX_CLK_SEL - Direction of TX_CLK of ENET QOS
 *  0b0..ENET QOS TX CLK is Input
 *  0b1..ENET QOS TX CLK is Output
 */
#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET_QOS_CLK_TX_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET_QOS_CLK_TX_CLK_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET_QOS_CLK_TX_CLK_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET1_TX_CLK_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET1_TX_CLK_SEL_SHIFT (1U)
/*! ENET1_TX_CLK_SEL - Direction of TX_CLK of ENET
 *  0b0..ENET TX CLK is Input
 *  0b1..ENET TX CLK is Output
 */
#define BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET1_TX_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET1_TX_CLK_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENET_CLK_SEL_ENET1_TX_CLK_SEL_MASK)
/*! @} */

/*! @name VOLT_DETECT - Voltage detectors output */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_SHIFT (0U)
/*! SUPPLY_DETECTOR_AON - Voltage detectors output of AON
 *  0b0..The input voltage of the domain is 1.8V
 *  0b1..The input voltage of the domain is 3.3V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_SHIFT (1U)
/*! SUPPLY_DETECTOR_GPIO - Voltage detectors output of GPIO
 *  0b0..The input voltage of the domain is 1.8V
 *  0b1..The input voltage of the domain is 3.3V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_SHIFT (2U)
/*! SUPPLY_DETECTOR_SD2 - Voltage detectors output of SD2
 *  0b0..The input voltage of the domain is 1.8V
 *  0b1..The input voltage of the domain is 3.3V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_SHIFT (3U)
/*! SUPPLY_DETECTOR_WAKEUP - Voltage detectors output of WAKEUP
 *  0b0..The input voltage of the domain is 1.8V
 *  0b1..The input voltage of the domain is 3.3V
 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_MASK)
/*! @} */

/*! @name I3C2_WAKEUP - I3C2 WAKEUPX CLR */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_SHIFT (0U)
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG mask bit for CA55 core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_SHIFT (0U)
/*! CAN2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_SHIFT (1U)
/*! EDMA2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_SHIFT (2U)
/*! FLEXIO1
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_SHIFT (3U)
/*! FLEXIO2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_SHIFT (4U)
/*! LPI2C3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_SHIFT (5U)
/*! LPI2C4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_SHIFT (6U)
/*! LPI2C5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_SHIFT (7U)
/*! LPI2C6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_SHIFT (8U)
/*! LPI2C7
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_SHIFT (9U)
/*! LPI2C8
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_SHIFT (10U)
/*! LPIT2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_SHIFT (11U)
/*! LPSPI3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_SHIFT (12U)
/*! LPSPI4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_SHIFT (13U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_SHIFT (14U)
/*! LPSPI6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_SHIFT (15U)
/*! LPSPI7
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_SHIFT (16U)
/*! LPSPI8
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_SHIFT (17U)
/*! LPTMR2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_SHIFT (18U)
/*! TPM3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_SHIFT (19U)
/*! TPM4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_SHIFT (20U)
/*! TPM5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_SHIFT (21U)
/*! TPM6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG3_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG3_SHIFT (22U)
/*! WDOG3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG4_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG4_SHIFT (23U)
/*! WDOG4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_SHIFT (24U)
/*! WDOG5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_SHIFT (25U)
/*! I3C2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_SHIFT (26U)
/*! SAI2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_SHIFT (27U)
/*! SAI3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_ENET1_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_ENET1_SHIFT (28U)
/*! ENET1
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_ENET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_ENET1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_ENET1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG DEBUG mask bit for CA55 core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_SHIFT (0U)
/*! CAN2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_SHIFT (1U)
/*! EDMA2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_SHIFT (2U)
/*! FLEXIO1
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_SHIFT (3U)
/*! FLEXIO2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_SHIFT (4U)
/*! LPI2C3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_SHIFT (5U)
/*! LPI2C4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_SHIFT (6U)
/*! LPI2C5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_SHIFT (7U)
/*! LPI2C6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_SHIFT (8U)
/*! LPI2C7
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_SHIFT (9U)
/*! LPI2C8
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_SHIFT (10U)
/*! LPIT2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_SHIFT (11U)
/*! LPSPI3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_SHIFT (12U)
/*! LPSPI4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_SHIFT (13U)
/*! LPSPI5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_SHIFT (14U)
/*! LPSPI6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_SHIFT (15U)
/*! LPSPI7
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_SHIFT (16U)
/*! LPSPI8
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_SHIFT (17U)
/*! LPTMR2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_SHIFT (18U)
/*! TPM3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_SHIFT (19U)
/*! TPM4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_SHIFT (20U)
/*! TPM5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_SHIFT (21U)
/*! TPM6
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG3_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG3_SHIFT (22U)
/*! WDOG3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG4_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG4_SHIFT (23U)
/*! WDOG4
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_SHIFT (24U)
/*! WDOG5
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_SHIFT (25U)
/*! I3C2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_SHIFT (26U)
/*! SAI2
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_SHIFT (27U)
/*! SAI3
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_ENET1_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_ENET1_SHIFT (28U)
/*! ENET1
 *  0b0..Module does not enter debug halted mode with A55
 *  0b1..Module enters debug halted mode when A55 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_ENET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_ENET1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_ENET1_MASK)
/*! @} */

/*! @name AXI_ATTR_CFG - AXI CACHE OVERRITE BIT */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT (0U)
/*! ARCACHE_USDHC1 - Overwrite arcache of USDHC1 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT (1U)
/*! AWCACHE_USDHC1 - Overwrite awcache of USDHC1 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT (2U)
/*! ARCACHE_USDHC2 - Overwrite arcache of USDHC2 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT (3U)
/*! AWCACHE_USDHC2 - Overwrite awcache of USDHC2 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_SHIFT (4U)
/*! ARCACHE_USDHC3 - Overwrite arcache of USDHC3 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_SHIFT (5U)
/*! AWCACHE_USDHC3 - Overwrite awcache of USDHC3 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_MASK)
/*! @} */

/*! @name I3C2_SDA_IRQ - I3C SDA IRQ Control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_SHIFT (0U)
/*! enable - IRQ enable bit
 *  0b0..I3C2 SDA IRQ disable
 *  0b1..I3C2 SDA IRQ enable
 */
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_enable_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_WAKEUPMIX_H_ */

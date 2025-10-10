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
**         CMSIS Peripheral Access Layer for FLEXIO
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
 * @file PERI_FLEXIO.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXIO
 *
 * CMSIS Peripheral Access Layer for FLEXIO
 */

#if !defined(PERI_FLEXIO_H_)
#define PERI_FLEXIO_H_                           /**< Symbol preventing repeated inclusion */

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
   -- FLEXIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Peripheral_Access_Layer FLEXIO Peripheral Access Layer
 * @{
 */

/** FLEXIO - Size of Registers Arrays */
#define FLEXIO_SHIFTCTL_COUNT                     8u
#define FLEXIO_SHIFTCFG_COUNT                     8u
#define FLEXIO_SHIFTBUF_COUNT                     8u
#define FLEXIO_SHIFTBUFBIS_COUNT                  8u
#define FLEXIO_SHIFTBUFBYS_COUNT                  8u
#define FLEXIO_SHIFTBUFBBS_COUNT                  8u
#define FLEXIO_TIMCTL_COUNT                       8u
#define FLEXIO_TIMCFG_COUNT                       8u
#define FLEXIO_TIMCMP_COUNT                       8u
#define FLEXIO_SHIFTBUFNBS_COUNT                  8u
#define FLEXIO_SHIFTBUFHWS_COUNT                  8u
#define FLEXIO_SHIFTBUFNIS_COUNT                  8u
#define FLEXIO_SHIFTBUFOES_COUNT                  8u
#define FLEXIO_SHIFTBUFEOS_COUNT                  8u
#define FLEXIO_SHIFTBUFHBS_COUNT                  8u

/** FLEXIO - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< FLEXIO Control, offset: 0x8 */
  __I  uint32_t PIN;                               /**< Pin State, offset: 0xC */
  __IO uint32_t SHIFTSTAT;                         /**< Shifter Status, offset: 0x10 */
  __IO uint32_t SHIFTERR;                          /**< Shifter Error, offset: 0x14 */
  __IO uint32_t TIMSTAT;                           /**< Timer Status Flag, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SHIFTSIEN;                         /**< Shifter Status Interrupt Enable, offset: 0x20 */
  __IO uint32_t SHIFTEIEN;                         /**< Shifter Error Interrupt Enable, offset: 0x24 */
  __IO uint32_t TIMIEN;                            /**< Timer Interrupt Enable, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SHIFTSDEN;                         /**< Shifter Status DMA Enable, offset: 0x30 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TIMERSDEN;                         /**< Timer Status DMA Enable, offset: 0x38 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SHIFTSTATE;                        /**< Shifter State, offset: 0x40 */
       uint8_t RESERVED_4[4];
  __IO uint32_t TRGSTAT;                           /**< Trigger Status, offset: 0x48 */
  __IO uint32_t TRIGIEN;                           /**< External Trigger Interrupt Enable, offset: 0x4C */
  __IO uint32_t PINSTAT;                           /**< Pin Status, offset: 0x50 */
  __IO uint32_t PINIEN;                            /**< Pin Interrupt Enable, offset: 0x54 */
  __IO uint32_t PINREN;                            /**< Pin Rising Edge Enable, offset: 0x58 */
  __IO uint32_t PINFEN;                            /**< Pin Falling Edge Enable, offset: 0x5C */
  __IO uint32_t PINOUTD;                           /**< Pin Output Data, offset: 0x60 */
  __IO uint32_t PINOUTE;                           /**< Pin Output Enable, offset: 0x64 */
  __IO uint32_t PINOUTDIS;                         /**< Pin Output Disable, offset: 0x68 */
  __IO uint32_t PINOUTCLR;                         /**< Pin Output Clear, offset: 0x6C */
  __IO uint32_t PINOUTSET;                         /**< Pin Output Set, offset: 0x70 */
  __IO uint32_t PINOUTTOG;                         /**< Pin Output Toggle, offset: 0x74 */
       uint8_t RESERVED_5[8];
  __IO uint32_t SHIFTCTL[FLEXIO_SHIFTCTL_COUNT];   /**< Shifter Control, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_6[96];
  __IO uint32_t SHIFTCFG[FLEXIO_SHIFTCFG_COUNT];   /**< Shifter Configuration, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_7[224];
  __IO uint32_t SHIFTBUF[FLEXIO_SHIFTBUF_COUNT];   /**< Shifter Buffer, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_8[96];
  __IO uint32_t SHIFTBUFBIS[FLEXIO_SHIFTBUFBIS_COUNT]; /**< Shifter Buffer Bit Swapped, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_9[96];
  __IO uint32_t SHIFTBUFBYS[FLEXIO_SHIFTBUFBYS_COUNT]; /**< Shifter Buffer Byte Swapped, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_10[96];
  __IO uint32_t SHIFTBUFBBS[FLEXIO_SHIFTBUFBBS_COUNT]; /**< Shifter Buffer Bit Byte Swapped, array offset: 0x380, array step: 0x4 */
       uint8_t RESERVED_11[96];
  __IO uint32_t TIMCTL[FLEXIO_TIMCTL_COUNT];       /**< Timer Control, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_12[96];
  __IO uint32_t TIMCFG[FLEXIO_TIMCFG_COUNT];       /**< Timer Configuration, array offset: 0x480, array step: 0x4 */
       uint8_t RESERVED_13[96];
  __IO uint32_t TIMCMP[FLEXIO_TIMCMP_COUNT];       /**< Timer Compare, array offset: 0x500, array step: 0x4 */
       uint8_t RESERVED_14[352];
  __IO uint32_t SHIFTBUFNBS[FLEXIO_SHIFTBUFNBS_COUNT]; /**< Shifter Buffer Nibble Byte Swapped, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_15[96];
  __IO uint32_t SHIFTBUFHWS[FLEXIO_SHIFTBUFHWS_COUNT]; /**< Shifter Buffer Halfword Swapped, array offset: 0x700, array step: 0x4 */
       uint8_t RESERVED_16[96];
  __IO uint32_t SHIFTBUFNIS[FLEXIO_SHIFTBUFNIS_COUNT]; /**< Shifter Buffer Nibble Swapped, array offset: 0x780, array step: 0x4 */
       uint8_t RESERVED_17[96];
  __IO uint32_t SHIFTBUFOES[FLEXIO_SHIFTBUFOES_COUNT]; /**< Shifter Buffer Odd Even Swapped, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_18[96];
  __IO uint32_t SHIFTBUFEOS[FLEXIO_SHIFTBUFEOS_COUNT]; /**< Shifter Buffer Even Odd Swapped, array offset: 0x880, array step: 0x4 */
       uint8_t RESERVED_19[96];
  __IO uint32_t SHIFTBUFHBS[FLEXIO_SHIFTBUFHBS_COUNT]; /**< Shifter Buffer Halfword Byte Swapped, array offset: 0x900, array step: 0x4 */
} FLEXIO_Type;

/* ----------------------------------------------------------------------------
   -- FLEXIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Register_Masks FLEXIO Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define FLEXIO_VERID_FEATURE_MASK                (0xFFFFU)
#define FLEXIO_VERID_FEATURE_SHIFT               (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 *  0b0000000000000001..State, logic, and parallel modes supported
 *  0b0000000000000010..Pin control registers supported
 *  0b0000000000000011..State, logic, and parallel modes, plus pin control registers supported
 */
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_FEATURE_SHIFT)) & FLEXIO_VERID_FEATURE_MASK)

#define FLEXIO_VERID_MINOR_MASK                  (0xFF0000U)
#define FLEXIO_VERID_MINOR_SHIFT                 (16U)
/*! MINOR - Minor Version Number */
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_MINOR_SHIFT)) & FLEXIO_VERID_MINOR_MASK)

#define FLEXIO_VERID_MAJOR_MASK                  (0xFF000000U)
#define FLEXIO_VERID_MAJOR_SHIFT                 (24U)
/*! MAJOR - Major Version Number */
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_MAJOR_SHIFT)) & FLEXIO_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define FLEXIO_PARAM_SHIFTER_MASK                (0xFFU)
#define FLEXIO_PARAM_SHIFTER_SHIFT               (0U)
/*! SHIFTER - Shifter Number */
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_SHIFTER_SHIFT)) & FLEXIO_PARAM_SHIFTER_MASK)

#define FLEXIO_PARAM_TIMER_MASK                  (0xFF00U)
#define FLEXIO_PARAM_TIMER_SHIFT                 (8U)
/*! TIMER - Timer Number */
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_TIMER_SHIFT)) & FLEXIO_PARAM_TIMER_MASK)

#define FLEXIO_PARAM_PIN_MASK                    (0xFF0000U)
#define FLEXIO_PARAM_PIN_SHIFT                   (16U)
/*! PIN - Pin Number */
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_PIN_SHIFT)) & FLEXIO_PARAM_PIN_MASK)

#define FLEXIO_PARAM_TRIGGER_MASK                (0xFF000000U)
#define FLEXIO_PARAM_TRIGGER_SHIFT               (24U)
/*! TRIGGER - Trigger Number */
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_TRIGGER_SHIFT)) & FLEXIO_PARAM_TRIGGER_MASK)
/*! @} */

/*! @name CTRL - FLEXIO Control */
/*! @{ */

#define FLEXIO_CTRL_FLEXEN_MASK                  (0x1U)
#define FLEXIO_CTRL_FLEXEN_SHIFT                 (0U)
/*! FLEXEN - FLEXIO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_FLEXEN_SHIFT)) & FLEXIO_CTRL_FLEXEN_MASK)

#define FLEXIO_CTRL_SWRST_MASK                   (0x2U)
#define FLEXIO_CTRL_SWRST_SHIFT                  (1U)
/*! SWRST - Software Reset
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_SWRST_SHIFT)) & FLEXIO_CTRL_SWRST_MASK)

#define FLEXIO_CTRL_FASTACC_MASK                 (0x4U)
#define FLEXIO_CTRL_FASTACC_SHIFT                (2U)
/*! FASTACC - Fast Access
 *  0b0..Normal
 *  0b1..Fast
 */
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_FASTACC_SHIFT)) & FLEXIO_CTRL_FASTACC_MASK)

#define FLEXIO_CTRL_DBGE_MASK                    (0x40000000U)
#define FLEXIO_CTRL_DBGE_SHIFT                   (30U)
/*! DBGE - Debug Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_DBGE_SHIFT)) & FLEXIO_CTRL_DBGE_MASK)

#define FLEXIO_CTRL_DOZEN_MASK                   (0x80000000U)
#define FLEXIO_CTRL_DOZEN_SHIFT                  (31U)
/*! DOZEN - Doze Enable
 *  0b0..Enable
 *  0b1..Disable
 */
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_DOZEN_SHIFT)) & FLEXIO_CTRL_DOZEN_MASK)
/*! @} */

/*! @name PIN - Pin State */
/*! @{ */

#define FLEXIO_PIN_PDI_MASK                      (0xFFFFFFFFU)
#define FLEXIO_PIN_PDI_SHIFT                     (0U)
/*! PDI - Pin Data Input */
#define FLEXIO_PIN_PDI(x)                        (((uint32_t)(((uint32_t)(x)) << FLEXIO_PIN_PDI_SHIFT)) & FLEXIO_PIN_PDI_MASK)
/*! @} */

/*! @name SHIFTSTAT - Shifter Status */
/*! @{ */

#define FLEXIO_SHIFTSTAT_SSF_MASK                (0xFFU)
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               (0U)
/*! SSF - Shifter Status Flag
 *  0b00000000..Clear
 *  0b00000000..No effect
 *  0b00000001..Clear the flag
 *  0b00000001..Set
 */
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSTAT_SSF_SHIFT)) & FLEXIO_SHIFTSTAT_SSF_MASK)
/*! @} */

/*! @name SHIFTERR - Shifter Error */
/*! @{ */

#define FLEXIO_SHIFTERR_SEF_MASK                 (0xFFU)
#define FLEXIO_SHIFTERR_SEF_SHIFT                (0U)
/*! SEF - Shifter Error Flag
 *  0b00000000..Clear
 *  0b00000000..No effect
 *  0b00000001..Clear the flag
 *  0b00000001..Set
 */
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTERR_SEF_SHIFT)) & FLEXIO_SHIFTERR_SEF_MASK)
/*! @} */

/*! @name TIMSTAT - Timer Status Flag */
/*! @{ */

#define FLEXIO_TIMSTAT_TSF_MASK                  (0xFFU)
#define FLEXIO_TIMSTAT_TSF_SHIFT                 (0U)
/*! TSF - Timer Status Flag
 *  0b00000000..Clear
 *  0b00000000..No effect
 *  0b00000001..Clear the flag
 *  0b00000001..Set
 */
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMSTAT_TSF_SHIFT)) & FLEXIO_TIMSTAT_TSF_MASK)
/*! @} */

/*! @name SHIFTSIEN - Shifter Status Interrupt Enable */
/*! @{ */

#define FLEXIO_SHIFTSIEN_SSIE_MASK               (0xFFU)
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              (0U)
/*! SSIE - Shifter Status Interrupt Enable */
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSIEN_SSIE_SHIFT)) & FLEXIO_SHIFTSIEN_SSIE_MASK)
/*! @} */

/*! @name SHIFTEIEN - Shifter Error Interrupt Enable */
/*! @{ */

#define FLEXIO_SHIFTEIEN_SEIE_MASK               (0xFFU)
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              (0U)
/*! SEIE - Shifter Error Interrupt Enable */
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTEIEN_SEIE_SHIFT)) & FLEXIO_SHIFTEIEN_SEIE_MASK)
/*! @} */

/*! @name TIMIEN - Timer Interrupt Enable */
/*! @{ */

#define FLEXIO_TIMIEN_TEIE_MASK                  (0xFFU)
#define FLEXIO_TIMIEN_TEIE_SHIFT                 (0U)
/*! TEIE - Timer Status Interrupt Enable */
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMIEN_TEIE_SHIFT)) & FLEXIO_TIMIEN_TEIE_MASK)
/*! @} */

/*! @name SHIFTSDEN - Shifter Status DMA Enable */
/*! @{ */

#define FLEXIO_SHIFTSDEN_SSDE_MASK               (0xFFU)
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              (0U)
/*! SSDE - Shifter Status DMA Enable */
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSDEN_SSDE_SHIFT)) & FLEXIO_SHIFTSDEN_SSDE_MASK)
/*! @} */

/*! @name TIMERSDEN - Timer Status DMA Enable */
/*! @{ */

#define FLEXIO_TIMERSDEN_TSDE_MASK               (0xFFU)
#define FLEXIO_TIMERSDEN_TSDE_SHIFT              (0U)
/*! TSDE - Timer Status DMA Enable */
#define FLEXIO_TIMERSDEN_TSDE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMERSDEN_TSDE_SHIFT)) & FLEXIO_TIMERSDEN_TSDE_MASK)
/*! @} */

/*! @name SHIFTSTATE - Shifter State */
/*! @{ */

#define FLEXIO_SHIFTSTATE_STATE_MASK             (0x7U)
#define FLEXIO_SHIFTSTATE_STATE_SHIFT            (0U)
/*! STATE - Current State Pointer */
#define FLEXIO_SHIFTSTATE_STATE(x)               (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSTATE_STATE_SHIFT)) & FLEXIO_SHIFTSTATE_STATE_MASK)
/*! @} */

/*! @name TRGSTAT - Trigger Status */
/*! @{ */

#define FLEXIO_TRGSTAT_ETSF_MASK                 (0xFFU)
#define FLEXIO_TRGSTAT_ETSF_SHIFT                (0U)
/*! ETSF - External Trigger Status Flag
 *  0b00000000..Clear
 *  0b00000000..No effect
 *  0b00000001..Clear the flag
 *  0b00000001..Set
 */
#define FLEXIO_TRGSTAT_ETSF(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TRGSTAT_ETSF_SHIFT)) & FLEXIO_TRGSTAT_ETSF_MASK)
/*! @} */

/*! @name TRIGIEN - External Trigger Interrupt Enable */
/*! @{ */

#define FLEXIO_TRIGIEN_TRIE_MASK                 (0xFFU)
#define FLEXIO_TRIGIEN_TRIE_SHIFT                (0U)
/*! TRIE - External Trigger Interrupt Enable */
#define FLEXIO_TRIGIEN_TRIE(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TRIGIEN_TRIE_SHIFT)) & FLEXIO_TRIGIEN_TRIE_MASK)
/*! @} */

/*! @name PINSTAT - Pin Status */
/*! @{ */

#define FLEXIO_PINSTAT_PSF_MASK                  (0xFFFFFFFFU)
#define FLEXIO_PINSTAT_PSF_SHIFT                 (0U)
/*! PSF - Pin Status Flag
 *  0b00000000000000000000000000000000..Clear
 *  0b00000000000000000000000000000000..No effect
 *  0b00000000000000000000000000000001..Clear the flag
 *  0b00000000000000000000000000000001..Set
 */
#define FLEXIO_PINSTAT_PSF(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINSTAT_PSF_SHIFT)) & FLEXIO_PINSTAT_PSF_MASK)
/*! @} */

/*! @name PINIEN - Pin Interrupt Enable */
/*! @{ */

#define FLEXIO_PINIEN_PSIE_MASK                  (0xFFFFFFFFU)
#define FLEXIO_PINIEN_PSIE_SHIFT                 (0U)
/*! PSIE - Pin Status Interrupt Enable */
#define FLEXIO_PINIEN_PSIE(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINIEN_PSIE_SHIFT)) & FLEXIO_PINIEN_PSIE_MASK)
/*! @} */

/*! @name PINREN - Pin Rising Edge Enable */
/*! @{ */

#define FLEXIO_PINREN_PRE_MASK                   (0xFFFFFFFFU)
#define FLEXIO_PINREN_PRE_SHIFT                  (0U)
/*! PRE - Pin Rising Edge */
#define FLEXIO_PINREN_PRE(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINREN_PRE_SHIFT)) & FLEXIO_PINREN_PRE_MASK)
/*! @} */

/*! @name PINFEN - Pin Falling Edge Enable */
/*! @{ */

#define FLEXIO_PINFEN_PFE_MASK                   (0xFFFFFFFFU)
#define FLEXIO_PINFEN_PFE_SHIFT                  (0U)
/*! PFE - Pin Falling Edge */
#define FLEXIO_PINFEN_PFE(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINFEN_PFE_SHIFT)) & FLEXIO_PINFEN_PFE_MASK)
/*! @} */

/*! @name PINOUTD - Pin Output Data */
/*! @{ */

#define FLEXIO_PINOUTD_OUTD_MASK                 (0xFFFFFFFFU)
#define FLEXIO_PINOUTD_OUTD_SHIFT                (0U)
/*! OUTD - Output Data */
#define FLEXIO_PINOUTD_OUTD(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTD_OUTD_SHIFT)) & FLEXIO_PINOUTD_OUTD_MASK)
/*! @} */

/*! @name PINOUTE - Pin Output Enable */
/*! @{ */

#define FLEXIO_PINOUTE_OUTE_MASK                 (0xFFFFFFFFU)
#define FLEXIO_PINOUTE_OUTE_SHIFT                (0U)
/*! OUTE - Output Enable */
#define FLEXIO_PINOUTE_OUTE(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTE_OUTE_SHIFT)) & FLEXIO_PINOUTE_OUTE_MASK)
/*! @} */

/*! @name PINOUTDIS - Pin Output Disable */
/*! @{ */

#define FLEXIO_PINOUTDIS_OUTDIS_MASK             (0xFFFFFFFFU)
#define FLEXIO_PINOUTDIS_OUTDIS_SHIFT            (0U)
/*! OUTDIS - Output Disable */
#define FLEXIO_PINOUTDIS_OUTDIS(x)               (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTDIS_OUTDIS_SHIFT)) & FLEXIO_PINOUTDIS_OUTDIS_MASK)
/*! @} */

/*! @name PINOUTCLR - Pin Output Clear */
/*! @{ */

#define FLEXIO_PINOUTCLR_OUTCLR_MASK             (0xFFFFFFFFU)
#define FLEXIO_PINOUTCLR_OUTCLR_SHIFT            (0U)
/*! OUTCLR - Output Clear */
#define FLEXIO_PINOUTCLR_OUTCLR(x)               (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTCLR_OUTCLR_SHIFT)) & FLEXIO_PINOUTCLR_OUTCLR_MASK)
/*! @} */

/*! @name PINOUTSET - Pin Output Set */
/*! @{ */

#define FLEXIO_PINOUTSET_OUTSET_MASK             (0xFFFFFFFFU)
#define FLEXIO_PINOUTSET_OUTSET_SHIFT            (0U)
/*! OUTSET - Output Set */
#define FLEXIO_PINOUTSET_OUTSET(x)               (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTSET_OUTSET_SHIFT)) & FLEXIO_PINOUTSET_OUTSET_MASK)
/*! @} */

/*! @name PINOUTTOG - Pin Output Toggle */
/*! @{ */

#define FLEXIO_PINOUTTOG_OUTTOG_MASK             (0xFFFFFFFFU)
#define FLEXIO_PINOUTTOG_OUTTOG_SHIFT            (0U)
/*! OUTTOG - Output Toggle */
#define FLEXIO_PINOUTTOG_OUTTOG(x)               (((uint32_t)(((uint32_t)(x)) << FLEXIO_PINOUTTOG_OUTTOG_SHIFT)) & FLEXIO_PINOUTTOG_OUTTOG_MASK)
/*! @} */

/*! @name SHIFTCTL - Shifter Control */
/*! @{ */

#define FLEXIO_SHIFTCTL_SMOD_MASK                (0x7U)
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               (0U)
/*! SMOD - Shifter Mode
 *  0b000..Disable
 *  0b001..Receive mode; capture the current shifter content into SHIFTBUF on expiration of the timer
 *  0b010..Transmit mode; load SHIFTBUF contents into the shifter on expiration of the timer
 *  0b011..Reserved
 *  0b100..Match Store mode; shifter data is compared to SHIFTBUF content on expiration of the timer
 *  0b101..Match Continuous mode; shifter data is continuously compared to SHIFTBUF contents
 *  0b110..State mode; SHIFTBUF contents store programmable state attributes
 *  0b111..Logic mode; SHIFTBUF contents implement programmable logic lookup table
 */
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_SMOD_SHIFT)) & FLEXIO_SHIFTCTL_SMOD_MASK)

#define FLEXIO_SHIFTCTL_PINPOL_MASK              (0x80U)
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             (7U)
/*! PINPOL - Shifter Pin Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINPOL_SHIFT)) & FLEXIO_SHIFTCTL_PINPOL_MASK)

#define FLEXIO_SHIFTCTL_PINSEL_MASK              (0x1F00U)
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             (8U)
/*! PINSEL - Shifter Pin Select */
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINSEL_SHIFT)) & FLEXIO_SHIFTCTL_PINSEL_MASK)

#define FLEXIO_SHIFTCTL_PINCFG_MASK              (0x30000U)
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             (16U)
/*! PINCFG - Shifter Pin Configuration
 *  0b00..Shifter pin output disabled
 *  0b01..Shifter pin open-drain or bidirectional output enable
 *  0b10..Shifter pin bidirectional output data
 *  0b11..Shifter pin output
 */
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINCFG_SHIFT)) & FLEXIO_SHIFTCTL_PINCFG_MASK)

#define FLEXIO_SHIFTCTL_TIMPOL_MASK              (0x800000U)
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             (23U)
/*! TIMPOL - Timer Polarity
 *  0b0..Positive edge
 *  0b1..Negative edge
 */
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_TIMPOL_SHIFT)) & FLEXIO_SHIFTCTL_TIMPOL_MASK)

#define FLEXIO_SHIFTCTL_TIMSEL_MASK              (0x7000000U)
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             (24U)
/*! TIMSEL - Timer Select */
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT)) & FLEXIO_SHIFTCTL_TIMSEL_MASK)
/*! @} */

/*! @name SHIFTCFG - Shifter Configuration */
/*! @{ */

#define FLEXIO_SHIFTCFG_SSTART_MASK              (0x3U)
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             (0U)
/*! SSTART - Shifter Start
 *  0b00..Start bit disabled for Transmitter, Receiver, and Match Store modes; Transmitter mode loads data on enable
 *  0b01..Start bit disabled for Transmitter, Receiver, and Match Store modes; Transmitter mode loads data on first shift
 *  0b10..Transmitter mode outputs start bit value 0 before loading data on first shift; if start bit is not 0,
 *        Receiver and Match Store modes set error flag
 *  0b11..Transmitter mode outputs start bit value 1 before loading data on first shift; if start bit is not 1,
 *        Receiver and Match Store modes set error flag
 */
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_SSTART_SHIFT)) & FLEXIO_SHIFTCFG_SSTART_MASK)

#define FLEXIO_SHIFTCFG_SSTOP_MASK               (0x30U)
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              (4U)
/*! SSTOP - Shifter Stop
 *  0b00..Stop bit disabled for Transmitter, Receiver, and Match Store modes
 *  0b01..Stop bit disabled for Transmitter, Receiver, and Match Store modes; when timer is in stop condition,
 *        Receiver and Match Store modes store receive data on the configured shift edge
 *  0b10..Transmitter mode outputs stop bit value 0 in Match Store mode; if stop bit is not 0, Receiver and Match
 *        Store modes set error flag (when timer is in stop condition, these modes also store receive data on the
 *        configured shift edge)
 *  0b11..Transmitter mode outputs stop bit value 1 in Match Store mode; if stop bit is not 1, Receiver and Match
 *        Store modes set error flag (when timer is in stop condition, these modes also store receive data on the
 *        configured shift edge)
 */
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_SSTOP_SHIFT)) & FLEXIO_SHIFTCFG_SSTOP_MASK)

#define FLEXIO_SHIFTCFG_INSRC_MASK               (0x100U)
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              (8U)
/*! INSRC - Input Source
 *  0b0..Pin
 *  0b1..Shifter n+1 output
 */
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_INSRC_SHIFT)) & FLEXIO_SHIFTCFG_INSRC_MASK)

#define FLEXIO_SHIFTCFG_LATST_MASK               (0x200U)
#define FLEXIO_SHIFTCFG_LATST_SHIFT              (9U)
/*! LATST - Late Store
 *  0b0..Store the pre-shift register state
 *  0b1..Store the post-shift register state
 */
#define FLEXIO_SHIFTCFG_LATST(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_LATST_SHIFT)) & FLEXIO_SHIFTCFG_LATST_MASK)

#define FLEXIO_SHIFTCFG_SSIZE_MASK               (0x1000U)
#define FLEXIO_SHIFTCFG_SSIZE_SHIFT              (12U)
/*! SSIZE - Shifter Size
 *  0b0..32-bit
 *  0b1..24-bit
 */
#define FLEXIO_SHIFTCFG_SSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_SSIZE_SHIFT)) & FLEXIO_SHIFTCFG_SSIZE_MASK)

#define FLEXIO_SHIFTCFG_PWIDTH_MASK              (0x1F0000U)
#define FLEXIO_SHIFTCFG_PWIDTH_SHIFT             (16U)
/*! PWIDTH - Parallel Width */
#define FLEXIO_SHIFTCFG_PWIDTH(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_PWIDTH_SHIFT)) & FLEXIO_SHIFTCFG_PWIDTH_MASK)
/*! @} */

/*! @name SHIFTBUF - Shifter Buffer */
/*! @{ */

#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           (0U)
/*! SHIFTBUF - Shift Buffer */
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT)) & FLEXIO_SHIFTBUF_SHIFTBUF_MASK)
/*! @} */

/*! @name SHIFTBUFBIS - Shifter Buffer Bit Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     (0U)
/*! SHIFTBUFBIS - Shift Buffer */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT)) & FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK)
/*! @} */

/*! @name SHIFTBUFBYS - Shifter Buffer Byte Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     (0U)
/*! SHIFTBUFBYS - Shift Buffer */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT)) & FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK)
/*! @} */

/*! @name SHIFTBUFBBS - Shifter Buffer Bit Byte Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     (0U)
/*! SHIFTBUFBBS - Shift Buffer */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT)) & FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK)
/*! @} */

/*! @name TIMCTL - Timer Control */
/*! @{ */

#define FLEXIO_TIMCTL_TIMOD_MASK                 (0x7U)
#define FLEXIO_TIMCTL_TIMOD_SHIFT                (0U)
/*! TIMOD - Timer Mode
 *  0b000..Timer disabled
 *  0b001..Dual 8-bit counters baud mode
 *  0b010..Dual 8-bit counters PWM high mode
 *  0b011..Single 16-bit counter mode
 *  0b100..Single 16-bit counter disable mode
 *  0b101..Dual 8-bit counters word mode
 *  0b110..Dual 8-bit counters PWM low mode
 *  0b111..Single 16-bit input capture mode
 */
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TIMOD_SHIFT)) & FLEXIO_TIMCTL_TIMOD_MASK)

#define FLEXIO_TIMCTL_ONETIM_MASK                (0x20U)
#define FLEXIO_TIMCTL_ONETIM_SHIFT               (5U)
/*! ONETIM - Timer One Time Operation
 *  0b0..Generate the timer enable event as normal
 *  0b1..Block the timer enable event unless the timer status flag is clear
 */
#define FLEXIO_TIMCTL_ONETIM(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_ONETIM_SHIFT)) & FLEXIO_TIMCTL_ONETIM_MASK)

#define FLEXIO_TIMCTL_PININS_MASK                (0x40U)
#define FLEXIO_TIMCTL_PININS_SHIFT               (6U)
/*! PININS - Timer Pin Input Select
 *  0b0..PINSEL selects timer pin input and output
 *  0b1..PINSEL + 1 selects the timer pin input; timer pin output remains selected by PINSEL
 */
#define FLEXIO_TIMCTL_PININS(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PININS_SHIFT)) & FLEXIO_TIMCTL_PININS_MASK)

#define FLEXIO_TIMCTL_PINPOL_MASK                (0x80U)
#define FLEXIO_TIMCTL_PINPOL_SHIFT               (7U)
/*! PINPOL - Timer Pin Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINPOL_SHIFT)) & FLEXIO_TIMCTL_PINPOL_MASK)

#define FLEXIO_TIMCTL_PINSEL_MASK                (0x1F00U)
#define FLEXIO_TIMCTL_PINSEL_SHIFT               (8U)
/*! PINSEL - Timer Pin Select */
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINSEL_SHIFT)) & FLEXIO_TIMCTL_PINSEL_MASK)

#define FLEXIO_TIMCTL_PINCFG_MASK                (0x30000U)
#define FLEXIO_TIMCTL_PINCFG_SHIFT               (16U)
/*! PINCFG - Timer Pin Configuration
 *  0b00..Timer pin output disabled
 *  0b01..Timer pin open-drain or bidirectional output enable
 *  0b10..Timer pin bidirectional output data
 *  0b11..Timer pin output
 */
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINCFG_SHIFT)) & FLEXIO_TIMCTL_PINCFG_MASK)

#define FLEXIO_TIMCTL_TRGSRC_MASK                (0x400000U)
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               (22U)
/*! TRGSRC - Trigger Source
 *  0b0..External
 *  0b1..Internal
 */
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGSRC_SHIFT)) & FLEXIO_TIMCTL_TRGSRC_MASK)

#define FLEXIO_TIMCTL_TRGPOL_MASK                (0x800000U)
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               (23U)
/*! TRGPOL - Trigger Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGPOL_SHIFT)) & FLEXIO_TIMCTL_TRGPOL_MASK)

#define FLEXIO_TIMCTL_TRGSEL_MASK                (0x3F000000U)
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               (24U)
/*! TRGSEL - Trigger Select */
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGSEL_SHIFT)) & FLEXIO_TIMCTL_TRGSEL_MASK)
/*! @} */

/*! @name TIMCFG - Timer Configuration */
/*! @{ */

#define FLEXIO_TIMCFG_TSTART_MASK                (0x2U)
#define FLEXIO_TIMCFG_TSTART_SHIFT               (1U)
/*! TSTART - Timer Start
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TSTART_SHIFT)) & FLEXIO_TIMCFG_TSTART_MASK)

#define FLEXIO_TIMCFG_TSTOP_MASK                 (0x30U)
#define FLEXIO_TIMCFG_TSTOP_SHIFT                (4U)
/*! TSTOP - Timer Stop
 *  0b00..Disabled
 *  0b01..Enabled on timer compare
 *  0b10..Enabled on timer disable
 *  0b11..Enabled on timer compare and timer disable
 */
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TSTOP_SHIFT)) & FLEXIO_TIMCFG_TSTOP_MASK)

#define FLEXIO_TIMCFG_TIMENA_MASK                (0x700U)
#define FLEXIO_TIMCFG_TIMENA_SHIFT               (8U)
/*! TIMENA - Timer Enable
 *  0b000..Timer always enabled
 *  0b001..Timer enabled on timer n-1 enable
 *  0b010..Timer enabled on trigger high
 *  0b011..Timer enabled on trigger high and pin high
 *  0b100..Timer enabled on pin rising edge
 *  0b101..Timer enabled on pin rising edge and trigger high
 *  0b110..Timer enabled on trigger rising edge
 *  0b111..Timer enabled on trigger rising or falling edge
 */
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMENA_SHIFT)) & FLEXIO_TIMCFG_TIMENA_MASK)

#define FLEXIO_TIMCFG_TIMDIS_MASK                (0x7000U)
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               (12U)
/*! TIMDIS - Timer Disable
 *  0b000..Timer never disabled
 *  0b001..Timer disabled on timer n-1 disable
 *  0b010..Timer disabled on timer compare (upper 8 bits match and decrement)
 *  0b011..Timer disabled on timer compare (upper 8 bits match and decrement) and trigger low
 *  0b100..Timer disabled on pin rising or falling edge
 *  0b101..Timer disabled on pin rising or falling edge provided trigger is high
 *  0b110..Timer disabled on trigger falling edge
 *  0b111..Reserved
 */
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMDIS_SHIFT)) & FLEXIO_TIMCFG_TIMDIS_MASK)

#define FLEXIO_TIMCFG_TIMRST_MASK                (0x70000U)
#define FLEXIO_TIMCFG_TIMRST_SHIFT               (16U)
/*! TIMRST - Timer Reset
 *  0b000..Never reset timer
 *  0b001..Timer reset on timer output high.
 *  0b010..Timer reset on timer pin equal to timer output
 *  0b011..Timer reset on timer trigger equal to timer output
 *  0b100..Timer reset on timer pin rising edge
 *  0b101..Reserved
 *  0b110..Timer reset on trigger rising edge
 *  0b111..Timer reset on trigger rising or falling edge
 */
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMRST_SHIFT)) & FLEXIO_TIMCFG_TIMRST_MASK)

#define FLEXIO_TIMCFG_TIMDEC_MASK                (0x700000U)
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               (20U)
/*! TIMDEC - Timer Decrement
 *  0b000..Decrement counter on FLEXIO clock; shift clock equals timer output
 *  0b001..Decrement counter on trigger input (both edges); shift clock equals timer output
 *  0b010..Decrement counter on pin input (both edges); shift clock equals pin input
 *  0b011..Decrement counter on trigger input (both edges); shift clock equals trigger input
 *  0b100..Decrement counter on FLEXIO clock divided by 16; shift clock equals timer output
 *  0b101..Decrement counter on FLEXIO clock divided by 256; shift clock equals timer output
 *  0b110..Decrement counter on pin input (rising edge); shift clock equals pin input
 *  0b111..Decrement counter on trigger input (rising edge); shift clock equals trigger input
 */
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMDEC_SHIFT)) & FLEXIO_TIMCFG_TIMDEC_MASK)

#define FLEXIO_TIMCFG_TIMOUT_MASK                (0x3000000U)
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               (24U)
/*! TIMOUT - Timer Output
 *  0b00..Logic one when enabled; not affected by timer reset
 *  0b01..Logic zero when enabled; not affected by timer reset
 *  0b10..Logic one when enabled and on timer reset
 *  0b11..Logic zero when enabled and on timer reset
 */
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMOUT_SHIFT)) & FLEXIO_TIMCFG_TIMOUT_MASK)
/*! @} */

/*! @name TIMCMP - Timer Compare */
/*! @{ */

#define FLEXIO_TIMCMP_CMP_MASK                   (0xFFFFU)
#define FLEXIO_TIMCMP_CMP_SHIFT                  (0U)
/*! CMP - Timer Compare Value */
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCMP_CMP_SHIFT)) & FLEXIO_TIMCMP_CMP_MASK)
/*! @} */

/*! @name SHIFTBUFNBS - Shifter Buffer Nibble Byte Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_SHIFT     (0U)
/*! SHIFTBUFNBS - Shift Buffer */
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_SHIFT)) & FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_MASK)
/*! @} */

/*! @name SHIFTBUFHWS - Shifter Buffer Halfword Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_SHIFT     (0U)
/*! SHIFTBUFHWS - Shift Buffer */
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_SHIFT)) & FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_MASK)
/*! @} */

/*! @name SHIFTBUFNIS - Shifter Buffer Nibble Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_SHIFT     (0U)
/*! SHIFTBUFNIS - Shift Buffer */
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_SHIFT)) & FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_MASK)
/*! @} */

/*! @name SHIFTBUFOES - Shifter Buffer Odd Even Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFOES_SHIFTBUFOES_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFOES_SHIFTBUFOES_SHIFT     (0U)
/*! SHIFTBUFOES - Shift Buffer */
#define FLEXIO_SHIFTBUFOES_SHIFTBUFOES(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFOES_SHIFTBUFOES_SHIFT)) & FLEXIO_SHIFTBUFOES_SHIFTBUFOES_MASK)
/*! @} */

/*! @name SHIFTBUFEOS - Shifter Buffer Even Odd Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFEOS_SHIFTBUFEOS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFEOS_SHIFTBUFEOS_SHIFT     (0U)
/*! SHIFTBUFEOS - Shift Buffer */
#define FLEXIO_SHIFTBUFEOS_SHIFTBUFEOS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFEOS_SHIFTBUFEOS_SHIFT)) & FLEXIO_SHIFTBUFEOS_SHIFTBUFEOS_MASK)
/*! @} */

/*! @name SHIFTBUFHBS - Shifter Buffer Halfword Byte Swapped */
/*! @{ */

#define FLEXIO_SHIFTBUFHBS_SHIFTBUFHBS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFHBS_SHIFTBUFHBS_SHIFT     (0U)
/*! SHIFTBUFHBS - Shift Buffer */
#define FLEXIO_SHIFTBUFHBS_SHIFTBUFHBS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFHBS_SHIFTBUFHBS_SHIFT)) & FLEXIO_SHIFTBUFHBS_SHIFTBUFHBS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLEXIO_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXIO_Peripheral_Access_Layer */


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


#endif  /* PERI_FLEXIO_H_ */


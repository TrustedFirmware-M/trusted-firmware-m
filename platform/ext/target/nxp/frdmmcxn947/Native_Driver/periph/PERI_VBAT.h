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
**         CMSIS Peripheral Access Layer for VBAT
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
 * @file PERI_VBAT.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VBAT
 *
 * CMSIS Peripheral Access Layer for VBAT
 */

#if !defined(PERI_VBAT_H_)
#define PERI_VBAT_H_                             /**< Symbol preventing repeated inclusion */

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
   -- VBAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Peripheral_Access_Layer VBAT Peripheral Access Layer
 * @{
 */

/** VBAT - Size of Registers Arrays */
#define VBAT_WAKEUP_COUNT                         2u

/** VBAT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t STATUSA;                           /**< Status A, offset: 0x10 */
  __IO uint32_t STATUSB;                           /**< Status B, offset: 0x14 */
  __IO uint32_t IRQENA;                            /**< Interrupt Enable A, offset: 0x18 */
  __IO uint32_t IRQENB;                            /**< Interrupt Enable B, offset: 0x1C */
  __IO uint32_t WAKENA;                            /**< Wake-up Enable A, offset: 0x20 */
  __IO uint32_t WAKENB;                            /**< Wake-up Enable B, offset: 0x24 */
  __IO uint32_t TAMPERA;                           /**< Tamper Enable A, offset: 0x28 */
  __IO uint32_t TAMPERB;                           /**< Tamper Enable B, offset: 0x2C */
  __IO uint32_t LOCKA;                             /**< Lock A, offset: 0x30 */
  __IO uint32_t LOCKB;                             /**< Lock B, offset: 0x34 */
  __IO uint32_t WAKECFG;                           /**< Wake-up Configuration, offset: 0x38 */
       uint8_t RESERVED_1[196];
  __IO uint32_t OSCCTLA;                           /**< Oscillator Control A, offset: 0x100 */
  __IO uint32_t OSCCTLB;                           /**< Oscillator Control B, offset: 0x104 */
  __IO uint32_t OSCCFGA;                           /**< Oscillator Configuration A, offset: 0x108 */
  __IO uint32_t OSCCFGB;                           /**< Oscillator Configuration B, offset: 0x10C */
       uint8_t RESERVED_2[8];
  __IO uint32_t OSCLCKA;                           /**< Oscillator Lock A, offset: 0x118 */
  __IO uint32_t OSCLCKB;                           /**< Oscillator Lock B, offset: 0x11C */
  __IO uint32_t OSCCLKE;                           /**< Oscillator Clock Enable, offset: 0x120 */
       uint8_t RESERVED_3[220];
  __IO uint32_t FROCTLA;                           /**< FRO16K Control A, offset: 0x200 */
  __IO uint32_t FROCTLB;                           /**< FRO16K Control B, offset: 0x204 */
       uint8_t RESERVED_4[16];
  __IO uint32_t FROLCKA;                           /**< FRO16K Lock A, offset: 0x218 */
  __IO uint32_t FROLCKB;                           /**< FRO16K Lock B, offset: 0x21C */
  __IO uint32_t FROCLKE;                           /**< FRO16K Clock Enable, offset: 0x220 */
       uint8_t RESERVED_5[220];
  __IO uint32_t LDOCTLA;                           /**< LDO_RAM Control A, offset: 0x300 */
  __IO uint32_t LDOCTLB;                           /**< LDO_RAM Control B, offset: 0x304 */
       uint8_t RESERVED_6[16];
  __IO uint32_t LDOLCKA;                           /**< LDO_RAM Lock A, offset: 0x318 */
  __IO uint32_t LDOLCKB;                           /**< LDO_RAM Lock B, offset: 0x31C */
  __IO uint32_t LDORAMC;                           /**< RAM Control, offset: 0x320 */
       uint8_t RESERVED_7[12];
  __IO uint32_t LDOTIMER0;                         /**< Bandgap Timer 0, offset: 0x330 */
       uint8_t RESERVED_8[4];
  __IO uint32_t LDOTIMER1;                         /**< Bandgap Timer 1, offset: 0x338 */
       uint8_t RESERVED_9[196];
  __IO uint32_t MONCTLA;                           /**< CLKMON Control A, offset: 0x400 */
  __IO uint32_t MONCTLB;                           /**< CLKMON Control B, offset: 0x404 */
  __IO uint32_t MONCFGA;                           /**< CLKMON Configuration A, offset: 0x408 */
  __IO uint32_t MONCFGB;                           /**< CLKMON Configuration B, offset: 0x40C */
       uint8_t RESERVED_10[8];
  __IO uint32_t MONLCKA;                           /**< CLKMON Lock A, offset: 0x418 */
  __IO uint32_t MONLCKB;                           /**< CLKMON Lock B, offset: 0x41C */
       uint8_t RESERVED_11[224];
  __IO uint32_t TAMCTLA;                           /**< TAMPER Control A, offset: 0x500 */
  __IO uint32_t TAMCTLB;                           /**< TAMPER Control B, offset: 0x504 */
       uint8_t RESERVED_12[16];
  __IO uint32_t TAMLCKA;                           /**< TAMPER Lock A, offset: 0x518 */
  __IO uint32_t TAMLCKB;                           /**< TAMPER Lock B, offset: 0x51C */
       uint8_t RESERVED_13[224];
  __IO uint32_t SWICTLA;                           /**< Switch Control A, offset: 0x600 */
  __IO uint32_t SWICTLB;                           /**< Switch Control B, offset: 0x604 */
       uint8_t RESERVED_14[16];
  __IO uint32_t SWILCKA;                           /**< Switch Lock A, offset: 0x618 */
  __IO uint32_t SWILCKB;                           /**< Switch Lock B, offset: 0x61C */
       uint8_t RESERVED_15[224];
  struct {                                         /* offset: 0x700, array step: 0x8 */
    __IO uint32_t WAKEUPA;                           /**< Wakeup 0 Register A, array offset: 0x700, array step: 0x8 */
    __IO uint32_t WAKEUPB;                           /**< Wakeup 0 Register B, array offset: 0x704, array step: 0x8 */
  } WAKEUP[VBAT_WAKEUP_COUNT];
       uint8_t RESERVED_16[232];
  __IO uint32_t WAKLCKA;                           /**< Wakeup Lock A, offset: 0x7F8 */
  __IO uint32_t WAKLCKB;                           /**< Wakeup Lock B, offset: 0x7FC */
} VBAT_Type;

/* ----------------------------------------------------------------------------
   -- VBAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Register_Masks VBAT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VBAT_VERID_FEATURE_MASK                  (0xFFFFU)
#define VBAT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number */
#define VBAT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_FEATURE_SHIFT)) & VBAT_VERID_FEATURE_MASK)

#define VBAT_VERID_MINOR_MASK                    (0xFF0000U)
#define VBAT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define VBAT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MINOR_SHIFT)) & VBAT_VERID_MINOR_MASK)

#define VBAT_VERID_MAJOR_MASK                    (0xFF000000U)
#define VBAT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define VBAT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MAJOR_SHIFT)) & VBAT_VERID_MAJOR_MASK)
/*! @} */

/*! @name STATUSA - Status A */
/*! @{ */

#define VBAT_STATUSA_POR_DET_MASK                (0x1U)
#define VBAT_STATUSA_POR_DET_SHIFT               (0U)
/*! POR_DET - POR Detect Flag
 *  0b0..No effect
 *  0b0..Not reset
 *  0b1..Clear the flag
 *  0b1..Reset
 */
#define VBAT_STATUSA_POR_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_POR_DET_SHIFT)) & VBAT_STATUSA_POR_DET_MASK)

#define VBAT_STATUSA_WAKEUP_FLAG_MASK            (0x2U)
#define VBAT_STATUSA_WAKEUP_FLAG_SHIFT           (1U)
/*! WAKEUP_FLAG - Wakeup Pin Flag
 *  0b0..No effect
 *  0b0..Not asserted
 *  0b1..Asserted
 *  0b1..Clear the flag
 */
#define VBAT_STATUSA_WAKEUP_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_WAKEUP_FLAG_SHIFT)) & VBAT_STATUSA_WAKEUP_FLAG_MASK)

#define VBAT_STATUSA_TIMER0_FLAG_MASK            (0x4U)
#define VBAT_STATUSA_TIMER0_FLAG_SHIFT           (2U)
/*! TIMER0_FLAG - Bandgap Timer 0 Flag
 *  0b0..No effect
 *  0b0..Not reached
 *  0b1..Clear the flag
 *  0b1..Reached
 */
#define VBAT_STATUSA_TIMER0_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_TIMER0_FLAG_SHIFT)) & VBAT_STATUSA_TIMER0_FLAG_MASK)

#define VBAT_STATUSA_TIMER1_FLAG_MASK            (0x8U)
#define VBAT_STATUSA_TIMER1_FLAG_SHIFT           (3U)
/*! TIMER1_FLAG - Bandgap Timer 1 Flag
 *  0b0..No effect
 *  0b0..Not reached
 *  0b1..Clear the flag
 *  0b1..Reached
 */
#define VBAT_STATUSA_TIMER1_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_TIMER1_FLAG_SHIFT)) & VBAT_STATUSA_TIMER1_FLAG_MASK)

#define VBAT_STATUSA_LDO_RDY_MASK                (0x10U)
#define VBAT_STATUSA_LDO_RDY_SHIFT               (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disabled (not ready)
 *  0b1..Enabled (ready)
 */
#define VBAT_STATUSA_LDO_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_LDO_RDY_SHIFT)) & VBAT_STATUSA_LDO_RDY_MASK)

#define VBAT_STATUSA_OSC_RDY_MASK                (0x20U)
#define VBAT_STATUSA_OSC_RDY_SHIFT               (5U)
/*! OSC_RDY - OSC32k Ready
 *  0b0..Disabled (clock not ready)
 *  0b1..Enabled (clock ready)
 */
#define VBAT_STATUSA_OSC_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_OSC_RDY_SHIFT)) & VBAT_STATUSA_OSC_RDY_MASK)

#define VBAT_STATUSA_CLOCK_DET_MASK              (0x40U)
#define VBAT_STATUSA_CLOCK_DET_SHIFT             (6U)
/*! CLOCK_DET - Clock Detect
 *  0b0..Clock error not detected
 *  0b1..Clock error detected
 */
#define VBAT_STATUSA_CLOCK_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_CLOCK_DET_SHIFT)) & VBAT_STATUSA_CLOCK_DET_MASK)

#define VBAT_STATUSA_CONFIG_DET_MASK             (0x80U)
#define VBAT_STATUSA_CONFIG_DET_SHIFT            (7U)
/*! CONFIG_DET - Configuration Detect Flag
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define VBAT_STATUSA_CONFIG_DET(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_CONFIG_DET_SHIFT)) & VBAT_STATUSA_CONFIG_DET_MASK)

#define VBAT_STATUSA_VOLT_DET_MASK               (0x100U)
#define VBAT_STATUSA_VOLT_DET_SHIFT              (8U)
/*! VOLT_DET - Voltage Detect
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define VBAT_STATUSA_VOLT_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_VOLT_DET_SHIFT)) & VBAT_STATUSA_VOLT_DET_MASK)

#define VBAT_STATUSA_TEMP_DET_MASK               (0x200U)
#define VBAT_STATUSA_TEMP_DET_SHIFT              (9U)
/*! TEMP_DET - Temperature Detect
 *  0b0..Temperature error not detected
 *  0b1..Temperature error detected
 */
#define VBAT_STATUSA_TEMP_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_TEMP_DET_SHIFT)) & VBAT_STATUSA_TEMP_DET_MASK)

#define VBAT_STATUSA_LIGHT_DET_MASK              (0x400U)
#define VBAT_STATUSA_LIGHT_DET_SHIFT             (10U)
/*! LIGHT_DET - Light Detect
 *  0b0..Light error not detected
 *  0b1..Light error detected
 */
#define VBAT_STATUSA_LIGHT_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_LIGHT_DET_SHIFT)) & VBAT_STATUSA_LIGHT_DET_MASK)

#define VBAT_STATUSA_SEC0_DET_MASK               (0x1000U)
#define VBAT_STATUSA_SEC0_DET_SHIFT              (12U)
/*! SEC0_DET - Input 0 Detect
 *  0b0..Security input 0 not detected
 *  0b1..Security input 0 detected
 */
#define VBAT_STATUSA_SEC0_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_SEC0_DET_SHIFT)) & VBAT_STATUSA_SEC0_DET_MASK)

#define VBAT_STATUSA_IRQ0_DET_MASK               (0x10000U)
#define VBAT_STATUSA_IRQ0_DET_SHIFT              (16U)
/*! IRQ0_DET - Interrupt 0 Detect
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define VBAT_STATUSA_IRQ0_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_IRQ0_DET_SHIFT)) & VBAT_STATUSA_IRQ0_DET_MASK)

#define VBAT_STATUSA_IRQ1_DET_MASK               (0x20000U)
#define VBAT_STATUSA_IRQ1_DET_SHIFT              (17U)
/*! IRQ1_DET - Interrupt 1 Detect
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define VBAT_STATUSA_IRQ1_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_IRQ1_DET_SHIFT)) & VBAT_STATUSA_IRQ1_DET_MASK)

#define VBAT_STATUSA_IRQ2_DET_MASK               (0x40000U)
#define VBAT_STATUSA_IRQ2_DET_SHIFT              (18U)
/*! IRQ2_DET - Interrupt 2 Detect
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define VBAT_STATUSA_IRQ2_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_IRQ2_DET_SHIFT)) & VBAT_STATUSA_IRQ2_DET_MASK)

#define VBAT_STATUSA_IRQ3_DET_MASK               (0x80000U)
#define VBAT_STATUSA_IRQ3_DET_SHIFT              (19U)
/*! IRQ3_DET - Interrupt 3 Detect
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define VBAT_STATUSA_IRQ3_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_IRQ3_DET_SHIFT)) & VBAT_STATUSA_IRQ3_DET_MASK)
/*! @} */

/*! @name STATUSB - Status B */
/*! @{ */

#define VBAT_STATUSB_INVERSE_MASK                (0xFFFFFU)
#define VBAT_STATUSB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse value */
#define VBAT_STATUSB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSB_INVERSE_SHIFT)) & VBAT_STATUSB_INVERSE_MASK)
/*! @} */

/*! @name IRQENA - Interrupt Enable A */
/*! @{ */

#define VBAT_IRQENA_POR_DET_MASK                 (0x1U)
#define VBAT_IRQENA_POR_DET_SHIFT                (0U)
/*! POR_DET - POR Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_POR_DET(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_POR_DET_SHIFT)) & VBAT_IRQENA_POR_DET_MASK)

#define VBAT_IRQENA_WAKEUP_FLAG_MASK             (0x2U)
#define VBAT_IRQENA_WAKEUP_FLAG_SHIFT            (1U)
/*! WAKEUP_FLAG - Wakeup Pin Flag
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_WAKEUP_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_WAKEUP_FLAG_SHIFT)) & VBAT_IRQENA_WAKEUP_FLAG_MASK)

#define VBAT_IRQENA_TIMER0_FLAG_MASK             (0x4U)
#define VBAT_IRQENA_TIMER0_FLAG_SHIFT            (2U)
/*! TIMER0_FLAG - Bandgap Timer 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_TIMER0_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_TIMER0_FLAG_SHIFT)) & VBAT_IRQENA_TIMER0_FLAG_MASK)

#define VBAT_IRQENA_TIMER1_FLAG_MASK             (0x8U)
#define VBAT_IRQENA_TIMER1_FLAG_SHIFT            (3U)
/*! TIMER1_FLAG - Bandgap Timer 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_TIMER1_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_TIMER1_FLAG_SHIFT)) & VBAT_IRQENA_TIMER1_FLAG_MASK)

#define VBAT_IRQENA_LDO_RDY_MASK                 (0x10U)
#define VBAT_IRQENA_LDO_RDY_SHIFT                (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_LDO_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_LDO_RDY_SHIFT)) & VBAT_IRQENA_LDO_RDY_MASK)

#define VBAT_IRQENA_OSC_RDY_MASK                 (0x20U)
#define VBAT_IRQENA_OSC_RDY_SHIFT                (5U)
/*! OSC_RDY - OSC32k Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_OSC_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_OSC_RDY_SHIFT)) & VBAT_IRQENA_OSC_RDY_MASK)

#define VBAT_IRQENA_CLOCK_DET_MASK               (0x40U)
#define VBAT_IRQENA_CLOCK_DET_SHIFT              (6U)
/*! CLOCK_DET - Clock Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_CLOCK_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_CLOCK_DET_SHIFT)) & VBAT_IRQENA_CLOCK_DET_MASK)

#define VBAT_IRQENA_CONFIG_DET_MASK              (0x80U)
#define VBAT_IRQENA_CONFIG_DET_SHIFT             (7U)
/*! CONFIG_DET - Configuration Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_CONFIG_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_CONFIG_DET_SHIFT)) & VBAT_IRQENA_CONFIG_DET_MASK)

#define VBAT_IRQENA_VOLT_DET_MASK                (0x100U)
#define VBAT_IRQENA_VOLT_DET_SHIFT               (8U)
/*! VOLT_DET - Voltage Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_VOLT_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_VOLT_DET_SHIFT)) & VBAT_IRQENA_VOLT_DET_MASK)

#define VBAT_IRQENA_TEMP_DET_MASK                (0x200U)
#define VBAT_IRQENA_TEMP_DET_SHIFT               (9U)
/*! TEMP_DET - Temperature Detect
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define VBAT_IRQENA_TEMP_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_TEMP_DET_SHIFT)) & VBAT_IRQENA_TEMP_DET_MASK)

#define VBAT_IRQENA_LIGHT_DET_MASK               (0x400U)
#define VBAT_IRQENA_LIGHT_DET_SHIFT              (10U)
/*! LIGHT_DET - Light Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_LIGHT_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_LIGHT_DET_SHIFT)) & VBAT_IRQENA_LIGHT_DET_MASK)

#define VBAT_IRQENA_SEC0_DET_MASK                (0x1000U)
#define VBAT_IRQENA_SEC0_DET_SHIFT               (12U)
/*! SEC0_DET - Input 0 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_SEC0_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_SEC0_DET_SHIFT)) & VBAT_IRQENA_SEC0_DET_MASK)

#define VBAT_IRQENA_IRQ0_DET_MASK                (0x10000U)
#define VBAT_IRQENA_IRQ0_DET_SHIFT               (16U)
/*! IRQ0_DET - Interrupt 0 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_IRQ0_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_IRQ0_DET_SHIFT)) & VBAT_IRQENA_IRQ0_DET_MASK)

#define VBAT_IRQENA_IRQ1_DET_MASK                (0x20000U)
#define VBAT_IRQENA_IRQ1_DET_SHIFT               (17U)
/*! IRQ1_DET - Interrupt 1 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_IRQ1_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_IRQ1_DET_SHIFT)) & VBAT_IRQENA_IRQ1_DET_MASK)

#define VBAT_IRQENA_IRQ2_DET_MASK                (0x40000U)
#define VBAT_IRQENA_IRQ2_DET_SHIFT               (18U)
/*! IRQ2_DET - Interrupt 2 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_IRQ2_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_IRQ2_DET_SHIFT)) & VBAT_IRQENA_IRQ2_DET_MASK)

#define VBAT_IRQENA_IRQ3_DET_MASK                (0x80000U)
#define VBAT_IRQENA_IRQ3_DET_SHIFT               (19U)
/*! IRQ3_DET - Interrupt 3 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_IRQ3_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_IRQ3_DET_SHIFT)) & VBAT_IRQENA_IRQ3_DET_MASK)
/*! @} */

/*! @name IRQENB - Interrupt Enable B */
/*! @{ */

#define VBAT_IRQENB_INVERSE_MASK                 (0xFFFFFU)
#define VBAT_IRQENB_INVERSE_SHIFT                (0U)
/*! INVERSE - Inverse Value */
#define VBAT_IRQENB_INVERSE(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENB_INVERSE_SHIFT)) & VBAT_IRQENB_INVERSE_MASK)
/*! @} */

/*! @name WAKENA - Wake-up Enable A */
/*! @{ */

#define VBAT_WAKENA_POR_DET_MASK                 (0x1U)
#define VBAT_WAKENA_POR_DET_SHIFT                (0U)
/*! POR_DET - POR Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_POR_DET(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_POR_DET_SHIFT)) & VBAT_WAKENA_POR_DET_MASK)

#define VBAT_WAKENA_WAKEUP_FLAG_MASK             (0x2U)
#define VBAT_WAKENA_WAKEUP_FLAG_SHIFT            (1U)
/*! WAKEUP_FLAG - Wake-up Pin Flag
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_WAKEUP_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_WAKEUP_FLAG_SHIFT)) & VBAT_WAKENA_WAKEUP_FLAG_MASK)

#define VBAT_WAKENA_TIMER0_FLAG_MASK             (0x4U)
#define VBAT_WAKENA_TIMER0_FLAG_SHIFT            (2U)
/*! TIMER0_FLAG - Bandgap Timer 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_TIMER0_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_TIMER0_FLAG_SHIFT)) & VBAT_WAKENA_TIMER0_FLAG_MASK)

#define VBAT_WAKENA_TIMER1_FLAG_MASK             (0x8U)
#define VBAT_WAKENA_TIMER1_FLAG_SHIFT            (3U)
/*! TIMER1_FLAG - Bandgap Timer 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_TIMER1_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_TIMER1_FLAG_SHIFT)) & VBAT_WAKENA_TIMER1_FLAG_MASK)

#define VBAT_WAKENA_LDO_RDY_MASK                 (0x10U)
#define VBAT_WAKENA_LDO_RDY_SHIFT                (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_LDO_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_LDO_RDY_SHIFT)) & VBAT_WAKENA_LDO_RDY_MASK)

#define VBAT_WAKENA_OSC_RDY_MASK                 (0x20U)
#define VBAT_WAKENA_OSC_RDY_SHIFT                (5U)
/*! OSC_RDY - OSC32K Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_OSC_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_OSC_RDY_SHIFT)) & VBAT_WAKENA_OSC_RDY_MASK)

#define VBAT_WAKENA_CLOCK_DET_MASK               (0x40U)
#define VBAT_WAKENA_CLOCK_DET_SHIFT              (6U)
/*! CLOCK_DET - Clock Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_CLOCK_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_CLOCK_DET_SHIFT)) & VBAT_WAKENA_CLOCK_DET_MASK)

#define VBAT_WAKENA_CONFIG_DET_MASK              (0x80U)
#define VBAT_WAKENA_CONFIG_DET_SHIFT             (7U)
/*! CONFIG_DET - Configuration Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_CONFIG_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_CONFIG_DET_SHIFT)) & VBAT_WAKENA_CONFIG_DET_MASK)

#define VBAT_WAKENA_VOLT_DET_MASK                (0x100U)
#define VBAT_WAKENA_VOLT_DET_SHIFT               (8U)
/*! VOLT_DET - Voltage Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_VOLT_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_VOLT_DET_SHIFT)) & VBAT_WAKENA_VOLT_DET_MASK)

#define VBAT_WAKENA_TEMP_DET_MASK                (0x200U)
#define VBAT_WAKENA_TEMP_DET_SHIFT               (9U)
/*! TEMP_DET - Temperature Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_TEMP_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_TEMP_DET_SHIFT)) & VBAT_WAKENA_TEMP_DET_MASK)

#define VBAT_WAKENA_LIGHT_DET_MASK               (0x400U)
#define VBAT_WAKENA_LIGHT_DET_SHIFT              (10U)
/*! LIGHT_DET - Light Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_LIGHT_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_LIGHT_DET_SHIFT)) & VBAT_WAKENA_LIGHT_DET_MASK)

#define VBAT_WAKENA_SEC0_DET_MASK                (0x1000U)
#define VBAT_WAKENA_SEC0_DET_SHIFT               (12U)
/*! SEC0_DET - Input 0 Detect
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define VBAT_WAKENA_SEC0_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_SEC0_DET_SHIFT)) & VBAT_WAKENA_SEC0_DET_MASK)

#define VBAT_WAKENA_IRQ0_DET_MASK                (0x10000U)
#define VBAT_WAKENA_IRQ0_DET_SHIFT               (16U)
/*! IRQ0_DET - Interrupt 0 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_IRQ0_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_IRQ0_DET_SHIFT)) & VBAT_WAKENA_IRQ0_DET_MASK)

#define VBAT_WAKENA_IRQ1_DET_MASK                (0x20000U)
#define VBAT_WAKENA_IRQ1_DET_SHIFT               (17U)
/*! IRQ1_DET - Interrupt 1 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_IRQ1_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_IRQ1_DET_SHIFT)) & VBAT_WAKENA_IRQ1_DET_MASK)

#define VBAT_WAKENA_IRQ2_DET_MASK                (0x40000U)
#define VBAT_WAKENA_IRQ2_DET_SHIFT               (18U)
/*! IRQ2_DET - Interrupt 2 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_IRQ2_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_IRQ2_DET_SHIFT)) & VBAT_WAKENA_IRQ2_DET_MASK)

#define VBAT_WAKENA_IRQ3_DET_MASK                (0x80000U)
#define VBAT_WAKENA_IRQ3_DET_SHIFT               (19U)
/*! IRQ3_DET - Interrupt 3 Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_IRQ3_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_IRQ3_DET_SHIFT)) & VBAT_WAKENA_IRQ3_DET_MASK)
/*! @} */

/*! @name WAKENB - Wake-up Enable B */
/*! @{ */

#define VBAT_WAKENB_INVERSE_MASK                 (0xFFFFFU)
#define VBAT_WAKENB_INVERSE_SHIFT                (0U)
/*! INVERSE - Inverse Value */
#define VBAT_WAKENB_INVERSE(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENB_INVERSE_SHIFT)) & VBAT_WAKENB_INVERSE_MASK)
/*! @} */

/*! @name TAMPERA - Tamper Enable A */
/*! @{ */

#define VBAT_TAMPERA_POR_DET_MASK                (0x1U)
#define VBAT_TAMPERA_POR_DET_SHIFT               (0U)
/*! POR_DET - POR Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_POR_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_POR_DET_SHIFT)) & VBAT_TAMPERA_POR_DET_MASK)

#define VBAT_TAMPERA_CLOCK_DET_MASK              (0x40U)
#define VBAT_TAMPERA_CLOCK_DET_SHIFT             (6U)
/*! CLOCK_DET - Clock Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_CLOCK_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_CLOCK_DET_SHIFT)) & VBAT_TAMPERA_CLOCK_DET_MASK)

#define VBAT_TAMPERA_CONFIG_DET_MASK             (0x80U)
#define VBAT_TAMPERA_CONFIG_DET_SHIFT            (7U)
/*! CONFIG_DET - Configuration Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_CONFIG_DET(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_CONFIG_DET_SHIFT)) & VBAT_TAMPERA_CONFIG_DET_MASK)

#define VBAT_TAMPERA_VOLT_DET_MASK               (0x100U)
#define VBAT_TAMPERA_VOLT_DET_SHIFT              (8U)
/*! VOLT_DET - Voltage Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_VOLT_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_VOLT_DET_SHIFT)) & VBAT_TAMPERA_VOLT_DET_MASK)

#define VBAT_TAMPERA_TEMP_DET_MASK               (0x200U)
#define VBAT_TAMPERA_TEMP_DET_SHIFT              (9U)
/*! TEMP_DET - Temperature Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_TEMP_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_TEMP_DET_SHIFT)) & VBAT_TAMPERA_TEMP_DET_MASK)

#define VBAT_TAMPERA_LIGHT_DET_MASK              (0x400U)
#define VBAT_TAMPERA_LIGHT_DET_SHIFT             (10U)
/*! LIGHT_DET - Light Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_LIGHT_DET(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_LIGHT_DET_SHIFT)) & VBAT_TAMPERA_LIGHT_DET_MASK)

#define VBAT_TAMPERA_SEC0_DET_MASK               (0x1000U)
#define VBAT_TAMPERA_SEC0_DET_SHIFT              (12U)
/*! SEC0_DET - Input 0 Detect
 *  0b0..Tamper disabled
 *  0b1..Tamper enabled
 */
#define VBAT_TAMPERA_SEC0_DET(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERA_SEC0_DET_SHIFT)) & VBAT_TAMPERA_SEC0_DET_MASK)
/*! @} */

/*! @name TAMPERB - Tamper Enable B */
/*! @{ */

#define VBAT_TAMPERB_INVERSE_MASK                (0xFFFFU)
#define VBAT_TAMPERB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse value */
#define VBAT_TAMPERB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_TAMPERB_INVERSE_SHIFT)) & VBAT_TAMPERB_INVERSE_MASK)
/*! @} */

/*! @name LOCKA - Lock A */
/*! @{ */

#define VBAT_LOCKA_LOCK_MASK                     (0x1U)
#define VBAT_LOCKA_LOCK_SHIFT                    (0U)
/*! LOCK - Lock
 *  0b0..Disables lock
 *  0b1..Enables lock. Cleared by VBAT POR.
 */
#define VBAT_LOCKA_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << VBAT_LOCKA_LOCK_SHIFT)) & VBAT_LOCKA_LOCK_MASK)
/*! @} */

/*! @name LOCKB - Lock B */
/*! @{ */

#define VBAT_LOCKB_LOCK_MASK                     (0x1U)
#define VBAT_LOCKB_LOCK_SHIFT                    (0U)
/*! LOCK - Lock
 *  0b0..Enables lock
 *  0b1..Disables lock
 */
#define VBAT_LOCKB_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << VBAT_LOCKB_LOCK_SHIFT)) & VBAT_LOCKB_LOCK_MASK)
/*! @} */

/*! @name WAKECFG - Wake-up Configuration */
/*! @{ */

#define VBAT_WAKECFG_OUT_MASK                    (0x1U)
#define VBAT_WAKECFG_OUT_SHIFT                   (0U)
/*! OUT - Output
 *  0b0..Logic zero (asserted)
 *  0b1..Logic one
 */
#define VBAT_WAKECFG_OUT(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_WAKECFG_OUT_SHIFT)) & VBAT_WAKECFG_OUT_MASK)
/*! @} */

/*! @name OSCCTLA - Oscillator Control A */
/*! @{ */

#define VBAT_OSCCTLA_OSC_EN_MASK                 (0x1U)
#define VBAT_OSCCTLA_OSC_EN_SHIFT                (0U)
/*! OSC_EN - Crystal Oscillator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_OSCCTLA_OSC_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_OSC_EN_SHIFT)) & VBAT_OSCCTLA_OSC_EN_MASK)

#define VBAT_OSCCTLA_OSC_BYP_EN_MASK             (0x2U)
#define VBAT_OSCCTLA_OSC_BYP_EN_SHIFT            (1U)
/*! OSC_BYP_EN - Crystal Oscillator Bypass Enable
 *  0b0..Does not bypass
 *  0b1..Bypass
 */
#define VBAT_OSCCTLA_OSC_BYP_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_OSC_BYP_EN_SHIFT)) & VBAT_OSCCTLA_OSC_BYP_EN_MASK)

#define VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK        (0xCU)
#define VBAT_OSCCTLA_COARSE_AMP_GAIN_SHIFT       (2U)
/*! COARSE_AMP_GAIN - Amplifier gain adjustment bits to allow the use of a wide range of external
 *    crystal ESR values See the device datasheet for the ranges supported by this device
 *  0b00..ESR Range 0
 *  0b01..ESR Range 1
 *  0b10..ESR Range 2
 *  0b11..ESR Range 3
 */
#define VBAT_OSCCTLA_COARSE_AMP_GAIN(x)          (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_COARSE_AMP_GAIN_SHIFT)) & VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK)

#define VBAT_OSCCTLA_CAP_SEL_EN_MASK             (0x80U)
#define VBAT_OSCCTLA_CAP_SEL_EN_SHIFT            (7U)
/*! CAP_SEL_EN - Crystal Load Capacitance Selection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_OSCCTLA_CAP_SEL_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_CAP_SEL_EN_SHIFT)) & VBAT_OSCCTLA_CAP_SEL_EN_MASK)

#define VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK          (0xF00U)
#define VBAT_OSCCTLA_EXTAL_CAP_SEL_SHIFT         (8U)
/*! EXTAL_CAP_SEL - Crystal Load Capacitance Selection
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define VBAT_OSCCTLA_EXTAL_CAP_SEL(x)            (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_EXTAL_CAP_SEL_SHIFT)) & VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK)

#define VBAT_OSCCTLA_XTAL_CAP_SEL_MASK           (0xF000U)
#define VBAT_OSCCTLA_XTAL_CAP_SEL_SHIFT          (12U)
/*! XTAL_CAP_SEL - Crystal Load Capacitance Selection
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define VBAT_OSCCTLA_XTAL_CAP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_XTAL_CAP_SEL_SHIFT)) & VBAT_OSCCTLA_XTAL_CAP_SEL_MASK)

#define VBAT_OSCCTLA_MODE_EN_MASK                (0x30000U)
#define VBAT_OSCCTLA_MODE_EN_SHIFT               (16U)
/*! MODE_EN - Mode Enable
 *  0b00..Normal mode
 *  0b01..Startup mode
 *  0b11..Low power mode
 */
#define VBAT_OSCCTLA_MODE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_MODE_EN_SHIFT)) & VBAT_OSCCTLA_MODE_EN_MASK)

#define VBAT_OSCCTLA_SUPPLY_DET_MASK             (0xC0000U)
#define VBAT_OSCCTLA_SUPPLY_DET_SHIFT            (18U)
/*! SUPPLY_DET - Supply Detector Trim
 *  0b00..VBAT supply is less than 3V
 *  0b01..VBAT supply is greater than 3V
 */
#define VBAT_OSCCTLA_SUPPLY_DET(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_SUPPLY_DET_SHIFT)) & VBAT_OSCCTLA_SUPPLY_DET_MASK)
/*! @} */

/*! @name OSCCTLB - Oscillator Control B */
/*! @{ */

#define VBAT_OSCCTLB_INVERSE_MASK                (0xFFFFFU)
#define VBAT_OSCCTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse Value */
#define VBAT_OSCCTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLB_INVERSE_SHIFT)) & VBAT_OSCCTLB_INVERSE_MASK)
/*! @} */

/*! @name OSCCFGA - Oscillator Configuration A */
/*! @{ */

#define VBAT_OSCCFGA_CMP_TRIM_MASK               (0x3U)
#define VBAT_OSCCFGA_CMP_TRIM_SHIFT              (0U)
/*! CMP_TRIM - Comparator Trim
 *  0b00..760 mV
 *  0b01..770 mV
 *  0b11..740 mV
 */
#define VBAT_OSCCFGA_CMP_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CMP_TRIM_SHIFT)) & VBAT_OSCCFGA_CMP_TRIM_MASK)

#define VBAT_OSCCFGA_CAP2_TRIM_MASK              (0x4U)
#define VBAT_OSCCFGA_CAP2_TRIM_SHIFT             (2U)
/*! CAP2_TRIM - CAP2_TRIM */
#define VBAT_OSCCFGA_CAP2_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CAP2_TRIM_SHIFT)) & VBAT_OSCCFGA_CAP2_TRIM_MASK)

#define VBAT_OSCCFGA_DLY_TRIM_MASK               (0x78U)
#define VBAT_OSCCFGA_DLY_TRIM_SHIFT              (3U)
/*! DLY_TRIM - Delay Trim
 *  0b0000..P current 9(nA) and N Current 6(nA)
 *  0b0001..P current 13(nA) and N Current 6(nA)
 *  0b0011..P current 4(nA) and N Current 6(nA)
 *  0b0100..P current 9(nA) and N Current 4(nA)
 *  0b0101..P current 13(nA) and N Current 4(nA)
 *  0b0111..P current 4(nA) and N Current 4(nA)
 *  0b1000..P current 9(nA) and N Current 2(nA)
 *  0b1001..P current 13(nA) and N Current 2(nA)
 *  0b1011..P current 4(nA) and N Current 2(nA)
 */
#define VBAT_OSCCFGA_DLY_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_DLY_TRIM_SHIFT)) & VBAT_OSCCFGA_DLY_TRIM_MASK)

#define VBAT_OSCCFGA_CAP_TRIM_MASK               (0x180U)
#define VBAT_OSCCFGA_CAP_TRIM_SHIFT              (7U)
/*! CAP_TRIM - Capacitor Trim
 *  0b00..Default (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 00 )
 *  0b01..-1us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 01)
 *  0b10..-2us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 10) or or +3.5us (when CAP2_TRIM = 1 and CAP_TRIM[1:0] = 10)
 *  0b11..-2.5us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 11) or +1us (when CAP2_TRIM = 1 and CAP_TRIM[1:0] = 11)
 */
#define VBAT_OSCCFGA_CAP_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CAP_TRIM_SHIFT)) & VBAT_OSCCFGA_CAP_TRIM_MASK)

#define VBAT_OSCCFGA_INIT_TRIM_MASK              (0xE00U)
#define VBAT_OSCCFGA_INIT_TRIM_SHIFT             (9U)
/*! INIT_TRIM - Initialization Trim
 *  0b000..8 s
 *  0b001..4 s
 *  0b010..2 s
 *  0b011..1 s
 *  0b100..0.5 s
 *  0b101..0.25 s
 *  0b110..0.125 s
 *  0b111..0.5 ms
 */
#define VBAT_OSCCFGA_INIT_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_INIT_TRIM_SHIFT)) & VBAT_OSCCFGA_INIT_TRIM_MASK)
/*! @} */

/*! @name OSCCFGB - Oscillator Configuration B */
/*! @{ */

#define VBAT_OSCCFGB_INVERSE_MASK                (0xFFFU)
#define VBAT_OSCCFGB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse Value */
#define VBAT_OSCCFGB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGB_INVERSE_SHIFT)) & VBAT_OSCCFGB_INVERSE_MASK)
/*! @} */

/*! @name OSCLCKA - Oscillator Lock A */
/*! @{ */

#define VBAT_OSCLCKA_LOCK_MASK                   (0x1U)
#define VBAT_OSCLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_OSCLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_OSCLCKA_LOCK_SHIFT)) & VBAT_OSCLCKA_LOCK_MASK)
/*! @} */

/*! @name OSCLCKB - Oscillator Lock B */
/*! @{ */

#define VBAT_OSCLCKB_LOCK_MASK                   (0x1U)
#define VBAT_OSCLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Block
 *  0b1..Do not block
 */
#define VBAT_OSCLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_OSCLCKB_LOCK_SHIFT)) & VBAT_OSCLCKB_LOCK_MASK)
/*! @} */

/*! @name OSCCLKE - Oscillator Clock Enable */
/*! @{ */

#define VBAT_OSCCLKE_CLKE_MASK                   (0xFU)
#define VBAT_OSCCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_OSCCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCLKE_CLKE_SHIFT)) & VBAT_OSCCLKE_CLKE_MASK)
/*! @} */

/*! @name FROCTLA - FRO16K Control A */
/*! @{ */

#define VBAT_FROCTLA_FRO_EN_MASK                 (0x1U)
#define VBAT_FROCTLA_FRO_EN_SHIFT                (0U)
/*! FRO_EN - FRO16K Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_FROCTLA_FRO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_FROCTLA_FRO_EN_SHIFT)) & VBAT_FROCTLA_FRO_EN_MASK)
/*! @} */

/*! @name FROCTLB - FRO16K Control B */
/*! @{ */

#define VBAT_FROCTLB_INVERSE_MASK                (0x1U)
#define VBAT_FROCTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse Value */
#define VBAT_FROCTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_FROCTLB_INVERSE_SHIFT)) & VBAT_FROCTLB_INVERSE_MASK)
/*! @} */

/*! @name FROLCKA - FRO16K Lock A */
/*! @{ */

#define VBAT_FROLCKA_LOCK_MASK                   (0x1U)
#define VBAT_FROLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_FROLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROLCKA_LOCK_SHIFT)) & VBAT_FROLCKA_LOCK_MASK)
/*! @} */

/*! @name FROLCKB - FRO16K Lock B */
/*! @{ */

#define VBAT_FROLCKB_LOCK_MASK                   (0x1U)
#define VBAT_FROLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Block
 *  0b1..Do not block
 */
#define VBAT_FROLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROLCKB_LOCK_SHIFT)) & VBAT_FROLCKB_LOCK_MASK)
/*! @} */

/*! @name FROCLKE - FRO16K Clock Enable */
/*! @{ */

#define VBAT_FROCLKE_CLKE_MASK                   (0xFU)
#define VBAT_FROCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_FROCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROCLKE_CLKE_SHIFT)) & VBAT_FROCLKE_CLKE_MASK)
/*! @} */

/*! @name LDOCTLA - LDO_RAM Control A */
/*! @{ */

#define VBAT_LDOCTLA_BG_EN_MASK                  (0x1U)
#define VBAT_LDOCTLA_BG_EN_SHIFT                 (0U)
/*! BG_EN - Bandgap Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOCTLA_BG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_BG_EN_SHIFT)) & VBAT_LDOCTLA_BG_EN_MASK)

#define VBAT_LDOCTLA_LDO_EN_MASK                 (0x2U)
#define VBAT_LDOCTLA_LDO_EN_SHIFT                (1U)
/*! LDO_EN - LDO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOCTLA_LDO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_LDO_EN_SHIFT)) & VBAT_LDOCTLA_LDO_EN_MASK)

#define VBAT_LDOCTLA_REFRESH_EN_MASK             (0x4U)
#define VBAT_LDOCTLA_REFRESH_EN_SHIFT            (2U)
/*! REFRESH_EN - Refresh Enable
 *  0b0..Refresh mode is disabled
 *  0b1..Refresh mode is enabled for low power operation
 */
#define VBAT_LDOCTLA_REFRESH_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_REFRESH_EN_SHIFT)) & VBAT_LDOCTLA_REFRESH_EN_MASK)
/*! @} */

/*! @name LDOCTLB - LDO_RAM Control B */
/*! @{ */

#define VBAT_LDOCTLB_INVERSE_MASK                (0x7U)
#define VBAT_LDOCTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse Value */
#define VBAT_LDOCTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLB_INVERSE_SHIFT)) & VBAT_LDOCTLB_INVERSE_MASK)
/*! @} */

/*! @name LDOLCKA - LDO_RAM Lock A */
/*! @{ */

#define VBAT_LDOLCKA_LOCK_MASK                   (0x1U)
#define VBAT_LDOLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_LDOLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDOLCKA_LOCK_SHIFT)) & VBAT_LDOLCKA_LOCK_MASK)
/*! @} */

/*! @name LDOLCKB - LDO_RAM Lock B */
/*! @{ */

#define VBAT_LDOLCKB_LOCK_MASK                   (0x1U)
#define VBAT_LDOLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Block
 *  0b1..Do not block
 */
#define VBAT_LDOLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDOLCKB_LOCK_SHIFT)) & VBAT_LDOLCKB_LOCK_MASK)
/*! @} */

/*! @name LDORAMC - RAM Control */
/*! @{ */

#define VBAT_LDORAMC_ISO_MASK                    (0x1U)
#define VBAT_LDORAMC_ISO_SHIFT                   (0U)
/*! ISO - Isolate SRAM
 *  0b0..State follows the chip power modes
 *  0b1..Isolates SRAM and places it in Low-Power Retention mode
 */
#define VBAT_LDORAMC_ISO(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_ISO_SHIFT)) & VBAT_LDORAMC_ISO_MASK)

#define VBAT_LDORAMC_SWI_MASK                    (0x2U)
#define VBAT_LDORAMC_SWI_SHIFT                   (1U)
/*! SWI - Switch SRAM
 *  0b0..Supply follows the chip power modes
 *  0b1..LDO_RAM powers the array
 */
#define VBAT_LDORAMC_SWI(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_SWI_SHIFT)) & VBAT_LDORAMC_SWI_MASK)

#define VBAT_LDORAMC_RET0_MASK                   (0x100U)
#define VBAT_LDORAMC_RET0_SHIFT                  (8U)
/*! RET0 - Retention
 *  0b0..Corresponding SRAM array is retained in low-power modes
 *  0b1..Corresponding SRAM array is not retained in low-power modes
 */
#define VBAT_LDORAMC_RET0(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_RET0_SHIFT)) & VBAT_LDORAMC_RET0_MASK)

#define VBAT_LDORAMC_RET1_MASK                   (0x200U)
#define VBAT_LDORAMC_RET1_SHIFT                  (9U)
/*! RET1 - Retention
 *  0b0..Corresponding SRAM array is retained in low-power modes
 *  0b1..Corresponding SRAM array is not retained in low-power modes
 */
#define VBAT_LDORAMC_RET1(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_RET1_SHIFT)) & VBAT_LDORAMC_RET1_MASK)

#define VBAT_LDORAMC_RET2_MASK                   (0x400U)
#define VBAT_LDORAMC_RET2_SHIFT                  (10U)
/*! RET2 - Retention
 *  0b0..Corresponding SRAM array is retained in low-power modes
 *  0b1..Corresponding SRAM array is not retained in low-power modes
 */
#define VBAT_LDORAMC_RET2(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_RET2_SHIFT)) & VBAT_LDORAMC_RET2_MASK)

#define VBAT_LDORAMC_RET3_MASK                   (0x800U)
#define VBAT_LDORAMC_RET3_SHIFT                  (11U)
/*! RET3 - Retention
 *  0b0..Corresponding SRAM array is retained in low-power modes
 *  0b1..Corresponding SRAM array is not retained in low-power modes
 */
#define VBAT_LDORAMC_RET3(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_RET3_SHIFT)) & VBAT_LDORAMC_RET3_MASK)
/*! @} */

/*! @name LDOTIMER0 - Bandgap Timer 0 */
/*! @{ */

#define VBAT_LDOTIMER0_TIMCFG_MASK               (0x7U)
#define VBAT_LDOTIMER0_TIMCFG_SHIFT              (0U)
/*! TIMCFG - Timeout Configuration
 *  0b000..1 s
 *  0b001..500 ms
 *  0b010..250 ms
 *  0b011..125 ms
 *  0b100..62.5 ms
 *  0b101..31.25 ms
 *  0b110..15.625 ms
 *  0b111..7.8125 ms
 */
#define VBAT_LDOTIMER0_TIMCFG(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER0_TIMCFG_SHIFT)) & VBAT_LDOTIMER0_TIMCFG_MASK)

#define VBAT_LDOTIMER0_TIMEN_MASK                (0x80000000U)
#define VBAT_LDOTIMER0_TIMEN_SHIFT               (31U)
/*! TIMEN - Bandgap Timeout Period Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOTIMER0_TIMEN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER0_TIMEN_SHIFT)) & VBAT_LDOTIMER0_TIMEN_MASK)
/*! @} */

/*! @name LDOTIMER1 - Bandgap Timer 1 */
/*! @{ */

#define VBAT_LDOTIMER1_TIMCFG_MASK               (0xFFFFFFU)
#define VBAT_LDOTIMER1_TIMCFG_SHIFT              (0U)
/*! TIMCFG - Timeout Configuration */
#define VBAT_LDOTIMER1_TIMCFG(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER1_TIMCFG_SHIFT)) & VBAT_LDOTIMER1_TIMCFG_MASK)

#define VBAT_LDOTIMER1_TIMEN_MASK                (0x80000000U)
#define VBAT_LDOTIMER1_TIMEN_SHIFT               (31U)
/*! TIMEN - Bandgap Timeout Period Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOTIMER1_TIMEN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER1_TIMEN_SHIFT)) & VBAT_LDOTIMER1_TIMEN_MASK)
/*! @} */

/*! @name MONCTLA - CLKMON Control A */
/*! @{ */

#define VBAT_MONCTLA_MON_EN_MASK                 (0x1U)
#define VBAT_MONCTLA_MON_EN_SHIFT                (0U)
/*! MON_EN - CLKMON Enable
 *  0b0..CLKMON is disabled
 *  0b1..CLKMON is enabled
 */
#define VBAT_MONCTLA_MON_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_MONCTLA_MON_EN_SHIFT)) & VBAT_MONCTLA_MON_EN_MASK)
/*! @} */

/*! @name MONCTLB - CLKMON Control B */
/*! @{ */

#define VBAT_MONCTLB_INVERSE_MASK                (0x1U)
#define VBAT_MONCTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse value */
#define VBAT_MONCTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_MONCTLB_INVERSE_SHIFT)) & VBAT_MONCTLB_INVERSE_MASK)
/*! @} */

/*! @name MONCFGA - CLKMON Configuration A */
/*! @{ */

#define VBAT_MONCFGA_FREQ_TRIM_MASK              (0x3U)
#define VBAT_MONCFGA_FREQ_TRIM_SHIFT             (0U)
/*! FREQ_TRIM - Frequency Trim
 *  0b00..Clock monitor asserts 2 cycle after expected edge
 *  0b01..Clock monitor asserts 4 cycles after expected edge
 *  0b10..Clock monitor asserts 6 cycles after expected edge
 *  0b11..Clock monitor asserts 8 cycles after expected edge
 */
#define VBAT_MONCFGA_FREQ_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_MONCFGA_FREQ_TRIM_SHIFT)) & VBAT_MONCFGA_FREQ_TRIM_MASK)

#define VBAT_MONCFGA_DIVIDE_TRIM_MASK            (0x4U)
#define VBAT_MONCFGA_DIVIDE_TRIM_SHIFT           (2U)
/*! DIVIDE_TRIM - Divide Trim
 *  0b0..Clock monitor operates at 1 kHz
 *  0b1..Clock monitor operates at 64 Hz
 */
#define VBAT_MONCFGA_DIVIDE_TRIM(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_MONCFGA_DIVIDE_TRIM_SHIFT)) & VBAT_MONCFGA_DIVIDE_TRIM_MASK)

#define VBAT_MONCFGA_RSVD_TRIM_MASK              (0xF8U)
#define VBAT_MONCFGA_RSVD_TRIM_SHIFT             (3U)
/*! RSVD_TRIM - Reserved Trim */
#define VBAT_MONCFGA_RSVD_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_MONCFGA_RSVD_TRIM_SHIFT)) & VBAT_MONCFGA_RSVD_TRIM_MASK)
/*! @} */

/*! @name MONCFGB - CLKMON Configuration B */
/*! @{ */

#define VBAT_MONCFGB_INVERSE_MASK                (0xFFU)
#define VBAT_MONCFGB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse value */
#define VBAT_MONCFGB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_MONCFGB_INVERSE_SHIFT)) & VBAT_MONCFGB_INVERSE_MASK)
/*! @} */

/*! @name MONLCKA - CLKMON Lock A */
/*! @{ */

#define VBAT_MONLCKA_LOCK_MASK                   (0x1U)
#define VBAT_MONLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is disabled
 *  0b1..Lock is enabled
 */
#define VBAT_MONLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_MONLCKA_LOCK_SHIFT)) & VBAT_MONLCKA_LOCK_MASK)
/*! @} */

/*! @name MONLCKB - CLKMON Lock B */
/*! @{ */

#define VBAT_MONLCKB_LOCK_MASK                   (0x1U)
#define VBAT_MONLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is enabled
 *  0b1..Lock is disabled
 */
#define VBAT_MONLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_MONLCKB_LOCK_SHIFT)) & VBAT_MONLCKB_LOCK_MASK)
/*! @} */

/*! @name TAMCTLA - TAMPER Control A */
/*! @{ */

#define VBAT_TAMCTLA_VOLT_EN_MASK                (0x1U)
#define VBAT_TAMCTLA_VOLT_EN_SHIFT               (0U)
/*! VOLT_EN - Voltage Detect Enable
 *  0b0..Voltage detect is disabled
 *  0b1..Voltage detect is enabled
 */
#define VBAT_TAMCTLA_VOLT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_TAMCTLA_VOLT_EN_SHIFT)) & VBAT_TAMCTLA_VOLT_EN_MASK)

#define VBAT_TAMCTLA_TEMP_EN_MASK                (0x2U)
#define VBAT_TAMCTLA_TEMP_EN_SHIFT               (1U)
/*! TEMP_EN - Temperature Detect Enable
 *  0b0..Temperature detect is disabled
 *  0b1..Temperature detect is enabled
 */
#define VBAT_TAMCTLA_TEMP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_TAMCTLA_TEMP_EN_SHIFT)) & VBAT_TAMCTLA_TEMP_EN_MASK)

#define VBAT_TAMCTLA_LIGHT_EN_MASK               (0x4U)
#define VBAT_TAMCTLA_LIGHT_EN_SHIFT              (2U)
/*! LIGHT_EN - Light Detect Enable
 *  0b0..Light detect is disabled
 *  0b1..Light detect is enabled
 */
#define VBAT_TAMCTLA_LIGHT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_TAMCTLA_LIGHT_EN_SHIFT)) & VBAT_TAMCTLA_LIGHT_EN_MASK)
/*! @} */

/*! @name TAMCTLB - TAMPER Control B */
/*! @{ */

#define VBAT_TAMCTLB_INVERSE_MASK                (0xFU)
#define VBAT_TAMCTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse value */
#define VBAT_TAMCTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_TAMCTLB_INVERSE_SHIFT)) & VBAT_TAMCTLB_INVERSE_MASK)
/*! @} */

/*! @name TAMLCKA - TAMPER Lock A */
/*! @{ */

#define VBAT_TAMLCKA_LOCK_MASK                   (0x1U)
#define VBAT_TAMLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is disabled
 *  0b1..Lock is enabled
 */
#define VBAT_TAMLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_TAMLCKA_LOCK_SHIFT)) & VBAT_TAMLCKA_LOCK_MASK)
/*! @} */

/*! @name TAMLCKB - TAMPER Lock B */
/*! @{ */

#define VBAT_TAMLCKB_LOCK_MASK                   (0x1U)
#define VBAT_TAMLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is enabled
 *  0b1..Lock is disabled
 */
#define VBAT_TAMLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_TAMLCKB_LOCK_SHIFT)) & VBAT_TAMLCKB_LOCK_MASK)
/*! @} */

/*! @name SWICTLA - Switch Control A */
/*! @{ */

#define VBAT_SWICTLA_SWI_EN_MASK                 (0x1U)
#define VBAT_SWICTLA_SWI_EN_SHIFT                (0U)
/*! SWI_EN - Switch Enable
 *  0b0..VDD_BAT
 *  0b1..VDD_SYS
 */
#define VBAT_SWICTLA_SWI_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_SWICTLA_SWI_EN_SHIFT)) & VBAT_SWICTLA_SWI_EN_MASK)

#define VBAT_SWICTLA_LP_EN_MASK                  (0x2U)
#define VBAT_SWICTLA_LP_EN_SHIFT                 (1U)
/*! LP_EN - Low Power Enable
 *  0b0..VDD_BAT always supplies VBAT modules in low-power modes
 *  0b1..VDD_SYS always supplies VBAT modules if SWI_EN is also 1
 */
#define VBAT_SWICTLA_LP_EN(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_SWICTLA_LP_EN_SHIFT)) & VBAT_SWICTLA_LP_EN_MASK)
/*! @} */

/*! @name SWICTLB - Switch Control B */
/*! @{ */

#define VBAT_SWICTLB_INVERSE_MASK                (0x3U)
#define VBAT_SWICTLB_INVERSE_SHIFT               (0U)
/*! INVERSE - Inverse Value */
#define VBAT_SWICTLB_INVERSE(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_SWICTLB_INVERSE_SHIFT)) & VBAT_SWICTLB_INVERSE_MASK)
/*! @} */

/*! @name SWILCKA - Switch Lock A */
/*! @{ */

#define VBAT_SWILCKA_LOCK_MASK                   (0x1U)
#define VBAT_SWILCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_SWILCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_SWILCKA_LOCK_SHIFT)) & VBAT_SWILCKA_LOCK_MASK)
/*! @} */

/*! @name SWILCKB - Switch Lock B */
/*! @{ */

#define VBAT_SWILCKB_LOCK_MASK                   (0x1U)
#define VBAT_SWILCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Block
 *  0b1..Do not block
 */
#define VBAT_SWILCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_SWILCKB_LOCK_SHIFT)) & VBAT_SWILCKB_LOCK_MASK)
/*! @} */

/*! @name WAKEUP_WAKEUPA - Wakeup 0 Register A */
/*! @{ */

#define VBAT_WAKEUP_WAKEUPA_REG_MASK             (0xFFFFFFFFU)
#define VBAT_WAKEUP_WAKEUPA_REG_SHIFT            (0U)
/*! REG - Register */
#define VBAT_WAKEUP_WAKEUPA_REG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKEUP_WAKEUPA_REG_SHIFT)) & VBAT_WAKEUP_WAKEUPA_REG_MASK)
/*! @} */

/* The count of VBAT_WAKEUP_WAKEUPA */
#define VBAT_WAKEUP_WAKEUPA_COUNT                (2U)

/*! @name WAKEUP_WAKEUPB - Wakeup 0 Register B */
/*! @{ */

#define VBAT_WAKEUP_WAKEUPB_INVERSE_MASK         (0xFFFFFFFFU)
#define VBAT_WAKEUP_WAKEUPB_INVERSE_SHIFT        (0U)
/*! INVERSE - Inverse value */
#define VBAT_WAKEUP_WAKEUPB_INVERSE(x)           (((uint32_t)(((uint32_t)(x)) << VBAT_WAKEUP_WAKEUPB_INVERSE_SHIFT)) & VBAT_WAKEUP_WAKEUPB_INVERSE_MASK)
/*! @} */

/* The count of VBAT_WAKEUP_WAKEUPB */
#define VBAT_WAKEUP_WAKEUPB_COUNT                (2U)

/*! @name WAKLCKA - Wakeup Lock A */
/*! @{ */

#define VBAT_WAKLCKA_LOCK_MASK                   (0x1U)
#define VBAT_WAKLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is disabled
 *  0b1..Lock is enabled
 */
#define VBAT_WAKLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_WAKLCKA_LOCK_SHIFT)) & VBAT_WAKLCKA_LOCK_MASK)
/*! @} */

/*! @name WAKLCKB - Wakeup Lock B */
/*! @{ */

#define VBAT_WAKLCKB_LOCK_MASK                   (0x1U)
#define VBAT_WAKLCKB_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is enabled
 *  0b1..Lock is disabled
 */
#define VBAT_WAKLCKB_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_WAKLCKB_LOCK_SHIFT)) & VBAT_WAKLCKB_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VBAT_Register_Masks */


/*!
 * @}
 */ /* end of group VBAT_Peripheral_Access_Layer */


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


#endif  /* PERI_VBAT_H_ */


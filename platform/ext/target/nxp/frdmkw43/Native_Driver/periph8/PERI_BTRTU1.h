/*
** ###################################################################
**     Processors:          KW43B43ZC2MFT
**                          KW43B43ZC3MFT
**                          KW43B43ZC6MFT
**                          KW43B43ZC7MFT
**                          KW43L43Z92MFT
**                          KW43L43Z93MFT
**                          KW43L43Z96MFT
**                          KW43L43Z97MFT
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BTRTU1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BTRTU1.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for BTRTU1
 *
 * CMSIS Peripheral Access Layer for BTRTU1
 */

#if !defined(PERI_BTRTU1_H_)
#define PERI_BTRTU1_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW43B43ZC2MFT))
#include "KW43B43ZC2_COMMON.h"
#elif (defined(CPU_KW43B43ZC3MFT))
#include "KW43B43ZC3_COMMON.h"
#elif (defined(CPU_KW43B43ZC6MFT))
#include "KW43B43ZC6_COMMON.h"
#elif (defined(CPU_KW43B43ZC7MFT))
#include "KW43B43ZC7_COMMON.h"
#elif (defined(CPU_KW43L43Z92MFT))
#include "KW43L43Z92_COMMON.h"
#elif (defined(CPU_KW43L43Z93MFT))
#include "KW43L43Z93_COMMON.h"
#elif (defined(CPU_KW43L43Z96MFT))
#include "KW43L43Z96_COMMON.h"
#elif (defined(CPU_KW43L43Z97MFT))
#include "KW43L43Z97_COMMON.h"
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
   -- BTRTU1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTRTU1_Peripheral_Access_Layer BTRTU1 Peripheral Access Layer
 * @{
 */

/** BTRTU1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BTRTU1_TIMER1_LEN;                 /**< Timer1 Length, offset: 0x0 */
  __IO uint32_t BTRTU1_TIMER2_LEN;                 /**< Timer2 Length, offset: 0x4 */
  __IO uint32_t BTRTU1_TIMER3_LEN;                 /**< Timer3 Length, offset: 0x8 */
  __IO uint32_t BTRTU1_TIMER4_LEN;                 /**< Timer4 Length, offset: 0xC */
  __IO uint32_t BTRTU1_CSR;                        /**< Timer Control, offset: 0x10 */
  __I  uint32_t BTRTU1_TIMER1_VAL;                 /**< Timer1 Value, offset: 0x14 */
  __I  uint32_t BTRTU1_TIMER2_VAL;                 /**< Timer2 Value, offset: 0x18 */
  __I  uint32_t BTRTU1_TIMER3_VAL;                 /**< Timer3 Value, offset: 0x1C */
  __I  uint32_t BTRTU1_TIMER4_VAL;                 /**< Timer4 Value, offset: 0x20 */
  __I  uint16_t BTRTU1_ISR;                        /**< Interrupt Soruce Status, offset: 0x24 */
       uint8_t RESERVED_0[2];
  __IO uint16_t BTRTU1_IMR;                        /**< Interrupt Mask, offset: 0x28 */
       uint8_t RESERVED_1[2];
  __IO uint32_t BTRTU1_PRER_1KHZ;                  /**< 1kHz Timer Prescaler, offset: 0x2C */
  __IO uint32_t BTRTU1_PRER_1MHZ;                  /**< 1MHz Timer Prescaler, offset: 0x30 */
  __IO uint32_t BTRTU1_WD_CTRL;                    /**< Watchdog Control, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __I  uint32_t BTRTU1_PRER1_CNT;                  /**< Prescaler1 Value, offset: 0x40 */
  __I  uint32_t BTRTU1_PRER2_CNT;                  /**< Prescaler2 Value, offset: 0x44 */
  __I  uint32_t BTRTU1_PRER3_CNT;                  /**< Prescaler3 Value, offset: 0x48 */
  __I  uint32_t BTRTU1_PRER4_CNT;                  /**< Prescaler4 Value, offset: 0x4C */
} BTRTU1_Type;

/* ----------------------------------------------------------------------------
   -- BTRTU1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTRTU1_Register_Masks BTRTU1 Register Masks
 * @{
 */

/*! @name BTRTU1_TIMER1_LEN - Timer1 Length */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER1_LEN_LEN_MASK        (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER1_LEN_LEN_SHIFT       (0U)
/*! len - " */
#define BTRTU1_BTRTU1_TIMER1_LEN_LEN(x)          (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER1_LEN_LEN_SHIFT)) & BTRTU1_BTRTU1_TIMER1_LEN_LEN_MASK)
/*! @} */

/*! @name BTRTU1_TIMER2_LEN - Timer2 Length */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER2_LEN_LEN_MASK        (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER2_LEN_LEN_SHIFT       (0U)
/*! len - " */
#define BTRTU1_BTRTU1_TIMER2_LEN_LEN(x)          (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER2_LEN_LEN_SHIFT)) & BTRTU1_BTRTU1_TIMER2_LEN_LEN_MASK)
/*! @} */

/*! @name BTRTU1_TIMER3_LEN - Timer3 Length */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER3_LEN_LEN_MASK        (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER3_LEN_LEN_SHIFT       (0U)
/*! len - " */
#define BTRTU1_BTRTU1_TIMER3_LEN_LEN(x)          (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER3_LEN_LEN_SHIFT)) & BTRTU1_BTRTU1_TIMER3_LEN_LEN_MASK)
/*! @} */

/*! @name BTRTU1_TIMER4_LEN - Timer4 Length */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER4_LEN_LEN_MASK        (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER4_LEN_LEN_SHIFT       (0U)
/*! len - " */
#define BTRTU1_BTRTU1_TIMER4_LEN_LEN(x)          (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER4_LEN_LEN_SHIFT)) & BTRTU1_BTRTU1_TIMER4_LEN_LEN_MASK)
/*! @} */

/*! @name BTRTU1_CSR - Timer Control */
/*! @{ */

#define BTRTU1_BTRTU1_CSR_T1_RST_MASK            (0x1U)
#define BTRTU1_BTRTU1_CSR_T1_RST_SHIFT           (0U)
/*! t1_rst - " */
#define BTRTU1_BTRTU1_CSR_T1_RST(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T1_RST_SHIFT)) & BTRTU1_BTRTU1_CSR_T1_RST_MASK)

#define BTRTU1_BTRTU1_CSR_T1_ACT_MASK            (0x2U)
#define BTRTU1_BTRTU1_CSR_T1_ACT_SHIFT           (1U)
/*! t1_act - " */
#define BTRTU1_BTRTU1_CSR_T1_ACT(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T1_ACT_SHIFT)) & BTRTU1_BTRTU1_CSR_T1_ACT_MASK)

#define BTRTU1_BTRTU1_CSR_T1_INT_CLR_SEL_MASK    (0x4U)
#define BTRTU1_BTRTU1_CSR_T1_INT_CLR_SEL_SHIFT   (2U)
/*! t1_int_clr_sel - " */
#define BTRTU1_BTRTU1_CSR_T1_INT_CLR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T1_INT_CLR_SEL_SHIFT)) & BTRTU1_BTRTU1_CSR_T1_INT_CLR_SEL_MASK)

#define BTRTU1_BTRTU1_CSR_T1_LOAD_MASK           (0x8U)
#define BTRTU1_BTRTU1_CSR_T1_LOAD_SHIFT          (3U)
/*! t1_load - " */
#define BTRTU1_BTRTU1_CSR_T1_LOAD(x)             (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T1_LOAD_SHIFT)) & BTRTU1_BTRTU1_CSR_T1_LOAD_MASK)

#define BTRTU1_BTRTU1_CSR_T2_RST_MASK            (0x10U)
#define BTRTU1_BTRTU1_CSR_T2_RST_SHIFT           (4U)
/*! t2_rst - " */
#define BTRTU1_BTRTU1_CSR_T2_RST(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T2_RST_SHIFT)) & BTRTU1_BTRTU1_CSR_T2_RST_MASK)

#define BTRTU1_BTRTU1_CSR_T2_ACT_MASK            (0x20U)
#define BTRTU1_BTRTU1_CSR_T2_ACT_SHIFT           (5U)
/*! t2_act - " */
#define BTRTU1_BTRTU1_CSR_T2_ACT(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T2_ACT_SHIFT)) & BTRTU1_BTRTU1_CSR_T2_ACT_MASK)

#define BTRTU1_BTRTU1_CSR_T2_INT_CLR_SEL_MASK    (0x40U)
#define BTRTU1_BTRTU1_CSR_T2_INT_CLR_SEL_SHIFT   (6U)
/*! t2_int_clr_sel - " */
#define BTRTU1_BTRTU1_CSR_T2_INT_CLR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T2_INT_CLR_SEL_SHIFT)) & BTRTU1_BTRTU1_CSR_T2_INT_CLR_SEL_MASK)

#define BTRTU1_BTRTU1_CSR_T2_LOAD_MASK           (0x80U)
#define BTRTU1_BTRTU1_CSR_T2_LOAD_SHIFT          (7U)
/*! t2_load - " */
#define BTRTU1_BTRTU1_CSR_T2_LOAD(x)             (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T2_LOAD_SHIFT)) & BTRTU1_BTRTU1_CSR_T2_LOAD_MASK)

#define BTRTU1_BTRTU1_CSR_T3_RST_MASK            (0x100U)
#define BTRTU1_BTRTU1_CSR_T3_RST_SHIFT           (8U)
/*! t3_rst - " */
#define BTRTU1_BTRTU1_CSR_T3_RST(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T3_RST_SHIFT)) & BTRTU1_BTRTU1_CSR_T3_RST_MASK)

#define BTRTU1_BTRTU1_CSR_T3_ACT_MASK            (0x200U)
#define BTRTU1_BTRTU1_CSR_T3_ACT_SHIFT           (9U)
/*! t3_act - " */
#define BTRTU1_BTRTU1_CSR_T3_ACT(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T3_ACT_SHIFT)) & BTRTU1_BTRTU1_CSR_T3_ACT_MASK)

#define BTRTU1_BTRTU1_CSR_T3_INT_CLR_SEL_MASK    (0x400U)
#define BTRTU1_BTRTU1_CSR_T3_INT_CLR_SEL_SHIFT   (10U)
/*! t3_int_clr_sel - " */
#define BTRTU1_BTRTU1_CSR_T3_INT_CLR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T3_INT_CLR_SEL_SHIFT)) & BTRTU1_BTRTU1_CSR_T3_INT_CLR_SEL_MASK)

#define BTRTU1_BTRTU1_CSR_T3_LOAD_MASK           (0x800U)
#define BTRTU1_BTRTU1_CSR_T3_LOAD_SHIFT          (11U)
/*! t3_load - " */
#define BTRTU1_BTRTU1_CSR_T3_LOAD(x)             (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T3_LOAD_SHIFT)) & BTRTU1_BTRTU1_CSR_T3_LOAD_MASK)

#define BTRTU1_BTRTU1_CSR_T4_RST_MASK            (0x1000U)
#define BTRTU1_BTRTU1_CSR_T4_RST_SHIFT           (12U)
/*! t4_rst - " */
#define BTRTU1_BTRTU1_CSR_T4_RST(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T4_RST_SHIFT)) & BTRTU1_BTRTU1_CSR_T4_RST_MASK)

#define BTRTU1_BTRTU1_CSR_T4_ACT_MASK            (0x2000U)
#define BTRTU1_BTRTU1_CSR_T4_ACT_SHIFT           (13U)
/*! t4_act - " */
#define BTRTU1_BTRTU1_CSR_T4_ACT(x)              (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T4_ACT_SHIFT)) & BTRTU1_BTRTU1_CSR_T4_ACT_MASK)

#define BTRTU1_BTRTU1_CSR_T4_INT_CLR_SEL_MASK    (0x4000U)
#define BTRTU1_BTRTU1_CSR_T4_INT_CLR_SEL_SHIFT   (14U)
/*! t4_int_clr_sel - " */
#define BTRTU1_BTRTU1_CSR_T4_INT_CLR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T4_INT_CLR_SEL_SHIFT)) & BTRTU1_BTRTU1_CSR_T4_INT_CLR_SEL_MASK)

#define BTRTU1_BTRTU1_CSR_T4_LOAD_MASK           (0x8000U)
#define BTRTU1_BTRTU1_CSR_T4_LOAD_SHIFT          (15U)
/*! t4_load - " */
#define BTRTU1_BTRTU1_CSR_T4_LOAD(x)             (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T4_LOAD_SHIFT)) & BTRTU1_BTRTU1_CSR_T4_LOAD_MASK)

#define BTRTU1_BTRTU1_CSR_T5_INT_CLR_SEL_MASK    (0x10000U)
#define BTRTU1_BTRTU1_CSR_T5_INT_CLR_SEL_SHIFT   (16U)
/*! t5_int_clr_sel - " */
#define BTRTU1_BTRTU1_CSR_T5_INT_CLR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_CSR_T5_INT_CLR_SEL_SHIFT)) & BTRTU1_BTRTU1_CSR_T5_INT_CLR_SEL_MASK)
/*! @} */

/*! @name BTRTU1_TIMER1_VAL - Timer1 Value */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER1_VAL_TIMER1_VAL_MASK (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER1_VAL_TIMER1_VAL_SHIFT (0U)
/*! timer1_val - " */
#define BTRTU1_BTRTU1_TIMER1_VAL_TIMER1_VAL(x)   (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER1_VAL_TIMER1_VAL_SHIFT)) & BTRTU1_BTRTU1_TIMER1_VAL_TIMER1_VAL_MASK)
/*! @} */

/*! @name BTRTU1_TIMER2_VAL - Timer2 Value */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER2_VAL_TIMER2_VAL_MASK (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER2_VAL_TIMER2_VAL_SHIFT (0U)
/*! timer2_val - " */
#define BTRTU1_BTRTU1_TIMER2_VAL_TIMER2_VAL(x)   (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER2_VAL_TIMER2_VAL_SHIFT)) & BTRTU1_BTRTU1_TIMER2_VAL_TIMER2_VAL_MASK)
/*! @} */

/*! @name BTRTU1_TIMER3_VAL - Timer3 Value */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER3_VAL_TIMER3_VAL_MASK (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER3_VAL_TIMER3_VAL_SHIFT (0U)
/*! timer3_val - " */
#define BTRTU1_BTRTU1_TIMER3_VAL_TIMER3_VAL(x)   (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER3_VAL_TIMER3_VAL_SHIFT)) & BTRTU1_BTRTU1_TIMER3_VAL_TIMER3_VAL_MASK)
/*! @} */

/*! @name BTRTU1_TIMER4_VAL - Timer4 Value */
/*! @{ */

#define BTRTU1_BTRTU1_TIMER4_VAL_TIMER4_VAL_MASK (0xFFFFFFFFU)
#define BTRTU1_BTRTU1_TIMER4_VAL_TIMER4_VAL_SHIFT (0U)
/*! timer4_val - " */
#define BTRTU1_BTRTU1_TIMER4_VAL_TIMER4_VAL(x)   (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_TIMER4_VAL_TIMER4_VAL_SHIFT)) & BTRTU1_BTRTU1_TIMER4_VAL_TIMER4_VAL_MASK)
/*! @} */

/*! @name BTRTU1_ISR - Interrupt Soruce Status */
/*! @{ */

#define BTRTU1_BTRTU1_ISR_T1_INT_MASK            (0x1U)
#define BTRTU1_BTRTU1_ISR_T1_INT_SHIFT           (0U)
/*! t1_int - " */
#define BTRTU1_BTRTU1_ISR_T1_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_ISR_T1_INT_SHIFT)) & BTRTU1_BTRTU1_ISR_T1_INT_MASK)

#define BTRTU1_BTRTU1_ISR_T2_INT_MASK            (0x2U)
#define BTRTU1_BTRTU1_ISR_T2_INT_SHIFT           (1U)
/*! t2_int - " */
#define BTRTU1_BTRTU1_ISR_T2_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_ISR_T2_INT_SHIFT)) & BTRTU1_BTRTU1_ISR_T2_INT_MASK)

#define BTRTU1_BTRTU1_ISR_T3_INT_MASK            (0x4U)
#define BTRTU1_BTRTU1_ISR_T3_INT_SHIFT           (2U)
/*! t3_int - " */
#define BTRTU1_BTRTU1_ISR_T3_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_ISR_T3_INT_SHIFT)) & BTRTU1_BTRTU1_ISR_T3_INT_MASK)

#define BTRTU1_BTRTU1_ISR_T4_INT_MASK            (0x8U)
#define BTRTU1_BTRTU1_ISR_T4_INT_SHIFT           (3U)
/*! t4_int - " */
#define BTRTU1_BTRTU1_ISR_T4_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_ISR_T4_INT_SHIFT)) & BTRTU1_BTRTU1_ISR_T4_INT_MASK)

#define BTRTU1_BTRTU1_ISR_WD_INT_MASK            (0x10U)
#define BTRTU1_BTRTU1_ISR_WD_INT_SHIFT           (4U)
/*! wd_int - " */
#define BTRTU1_BTRTU1_ISR_WD_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_ISR_WD_INT_SHIFT)) & BTRTU1_BTRTU1_ISR_WD_INT_MASK)
/*! @} */

/*! @name BTRTU1_IMR - Interrupt Mask */
/*! @{ */

#define BTRTU1_BTRTU1_IMR_T1_INT_MASK            (0x1U)
#define BTRTU1_BTRTU1_IMR_T1_INT_SHIFT           (0U)
/*! t1_int - " */
#define BTRTU1_BTRTU1_IMR_T1_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_IMR_T1_INT_SHIFT)) & BTRTU1_BTRTU1_IMR_T1_INT_MASK)

#define BTRTU1_BTRTU1_IMR_T2_INT_MASK            (0x2U)
#define BTRTU1_BTRTU1_IMR_T2_INT_SHIFT           (1U)
/*! t2_int - " */
#define BTRTU1_BTRTU1_IMR_T2_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_IMR_T2_INT_SHIFT)) & BTRTU1_BTRTU1_IMR_T2_INT_MASK)

#define BTRTU1_BTRTU1_IMR_T3_INT_MASK            (0x4U)
#define BTRTU1_BTRTU1_IMR_T3_INT_SHIFT           (2U)
/*! t3_int - " */
#define BTRTU1_BTRTU1_IMR_T3_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_IMR_T3_INT_SHIFT)) & BTRTU1_BTRTU1_IMR_T3_INT_MASK)

#define BTRTU1_BTRTU1_IMR_T4_INT_MASK            (0x8U)
#define BTRTU1_BTRTU1_IMR_T4_INT_SHIFT           (3U)
/*! t4_int - " */
#define BTRTU1_BTRTU1_IMR_T4_INT(x)              (((uint16_t)(((uint16_t)(x)) << BTRTU1_BTRTU1_IMR_T4_INT_SHIFT)) & BTRTU1_BTRTU1_IMR_T4_INT_MASK)
/*! @} */

/*! @name BTRTU1_PRER_1KHZ - 1kHz Timer Prescaler */
/*! @{ */

#define BTRTU1_BTRTU1_PRER_1KHZ_PRER_1KHZ_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER_1KHZ_PRER_1KHZ_SHIFT  (0U)
/*! prer_1khz - " */
#define BTRTU1_BTRTU1_PRER_1KHZ_PRER_1KHZ(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER_1KHZ_PRER_1KHZ_SHIFT)) & BTRTU1_BTRTU1_PRER_1KHZ_PRER_1KHZ_MASK)
/*! @} */

/*! @name BTRTU1_PRER_1MHZ - 1MHz Timer Prescaler */
/*! @{ */

#define BTRTU1_BTRTU1_PRER_1MHZ_PRER_1MHZ_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER_1MHZ_PRER_1MHZ_SHIFT  (0U)
/*! prer_1mhz - " */
#define BTRTU1_BTRTU1_PRER_1MHZ_PRER_1MHZ(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER_1MHZ_PRER_1MHZ_SHIFT)) & BTRTU1_BTRTU1_PRER_1MHZ_PRER_1MHZ_MASK)
/*! @} */

/*! @name BTRTU1_WD_CTRL - Watchdog Control */
/*! @{ */

#define BTRTU1_BTRTU1_WD_CTRL_WD_S2_EN_MASK      (0x1U)
#define BTRTU1_BTRTU1_WD_CTRL_WD_S2_EN_SHIFT     (0U)
/*! wd_s2_en - " */
#define BTRTU1_BTRTU1_WD_CTRL_WD_S2_EN(x)        (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_WD_CTRL_WD_S2_EN_SHIFT)) & BTRTU1_BTRTU1_WD_CTRL_WD_S2_EN_MASK)

#define BTRTU1_BTRTU1_WD_CTRL_WD_S1_EN_MASK      (0x2U)
#define BTRTU1_BTRTU1_WD_CTRL_WD_S1_EN_SHIFT     (1U)
/*! wd_s1_en - " */
#define BTRTU1_BTRTU1_WD_CTRL_WD_S1_EN(x)        (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_WD_CTRL_WD_S1_EN_SHIFT)) & BTRTU1_BTRTU1_WD_CTRL_WD_S1_EN_MASK)

#define BTRTU1_BTRTU1_WD_CTRL_WD_CNT_EXP_MASK    (0x70U)
#define BTRTU1_BTRTU1_WD_CTRL_WD_CNT_EXP_SHIFT   (4U)
/*! wd_cnt_exp - " */
#define BTRTU1_BTRTU1_WD_CTRL_WD_CNT_EXP(x)      (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_WD_CTRL_WD_CNT_EXP_SHIFT)) & BTRTU1_BTRTU1_WD_CTRL_WD_CNT_EXP_MASK)

#define BTRTU1_BTRTU1_WD_CTRL_WD_CLR_MASK        (0x100U)
#define BTRTU1_BTRTU1_WD_CTRL_WD_CLR_SHIFT       (8U)
/*! wd_clr - " */
#define BTRTU1_BTRTU1_WD_CTRL_WD_CLR(x)          (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_WD_CTRL_WD_CLR_SHIFT)) & BTRTU1_BTRTU1_WD_CTRL_WD_CLR_MASK)

#define BTRTU1_BTRTU1_WD_CTRL_TRIG_SOFT_RSTN_MASK (0x10000U)
#define BTRTU1_BTRTU1_WD_CTRL_TRIG_SOFT_RSTN_SHIFT (16U)
/*! trig_soft_rstn - " */
#define BTRTU1_BTRTU1_WD_CTRL_TRIG_SOFT_RSTN(x)  (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_WD_CTRL_TRIG_SOFT_RSTN_SHIFT)) & BTRTU1_BTRTU1_WD_CTRL_TRIG_SOFT_RSTN_MASK)
/*! @} */

/*! @name BTRTU1_PRER1_CNT - Prescaler1 Value */
/*! @{ */

#define BTRTU1_BTRTU1_PRER1_CNT_PRER1_CNT_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER1_CNT_PRER1_CNT_SHIFT  (0U)
/*! prer1_cnt - " */
#define BTRTU1_BTRTU1_PRER1_CNT_PRER1_CNT(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER1_CNT_PRER1_CNT_SHIFT)) & BTRTU1_BTRTU1_PRER1_CNT_PRER1_CNT_MASK)
/*! @} */

/*! @name BTRTU1_PRER2_CNT - Prescaler2 Value */
/*! @{ */

#define BTRTU1_BTRTU1_PRER2_CNT_PRER2_CNT_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER2_CNT_PRER2_CNT_SHIFT  (0U)
/*! prer2_cnt - " */
#define BTRTU1_BTRTU1_PRER2_CNT_PRER2_CNT(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER2_CNT_PRER2_CNT_SHIFT)) & BTRTU1_BTRTU1_PRER2_CNT_PRER2_CNT_MASK)
/*! @} */

/*! @name BTRTU1_PRER3_CNT - Prescaler3 Value */
/*! @{ */

#define BTRTU1_BTRTU1_PRER3_CNT_PRER3_CNT_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER3_CNT_PRER3_CNT_SHIFT  (0U)
/*! prer3_cnt - " */
#define BTRTU1_BTRTU1_PRER3_CNT_PRER3_CNT(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER3_CNT_PRER3_CNT_SHIFT)) & BTRTU1_BTRTU1_PRER3_CNT_PRER3_CNT_MASK)
/*! @} */

/*! @name BTRTU1_PRER4_CNT - Prescaler4 Value */
/*! @{ */

#define BTRTU1_BTRTU1_PRER4_CNT_PRER4_CNT_MASK   (0x3FFFFU)
#define BTRTU1_BTRTU1_PRER4_CNT_PRER4_CNT_SHIFT  (0U)
/*! prer4_cnt - " */
#define BTRTU1_BTRTU1_PRER4_CNT_PRER4_CNT(x)     (((uint32_t)(((uint32_t)(x)) << BTRTU1_BTRTU1_PRER4_CNT_PRER4_CNT_SHIFT)) & BTRTU1_BTRTU1_PRER4_CNT_PRER4_CNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BTRTU1_Register_Masks */


/*!
 * @}
 */ /* end of group BTRTU1_Peripheral_Access_Layer */


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


#endif  /* PERI_BTRTU1_H_ */


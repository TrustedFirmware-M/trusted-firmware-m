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
**         CMSIS Peripheral Access Layer for RTU
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
 * @file PERI_RTU.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for RTU
 *
 * CMSIS Peripheral Access Layer for RTU
 */

#if !defined(PERI_RTU_H_)
#define PERI_RTU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- RTU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_Peripheral_Access_Layer RTU Peripheral Access Layer
 * @{
 */

/** RTU - Register Layout Typedef */
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
  __I  uint32_t BTRTU1_ISR;                        /**< Interrupt Soruce Status, offset: 0x24 */
  __IO uint32_t BTRTU1_IMR;                        /**< Interrupt Mask, offset: 0x28 */
  __IO uint32_t BTRTU1_PRER_1KHZ;                  /**< 1kHz Timer Prescaler, offset: 0x2C */
  __IO uint32_t BTRTU1_PRER_1MHZ;                  /**< 1MHz Timer Prescaler, offset: 0x30 */
  __IO uint32_t BTRTU1_WD_CTRL;                    /**< Watchdog Control, offset: 0x34 */
       uint8_t RESERVED_0[8];
  __I  uint32_t BTRTU1_PRER1_CNT;                  /**< Prescaler1 Value, offset: 0x40 */
  __I  uint32_t BTRTU1_PRER2_CNT;                  /**< Prescaler2 Value, offset: 0x44 */
  __I  uint32_t BTRTU1_PRER3_CNT;                  /**< Prescaler3 Value, offset: 0x48 */
  __I  uint32_t BTRTU1_PRER4_CNT;                  /**< Prescaler4 Value, offset: 0x4C */
} RTU_Type;

/* ----------------------------------------------------------------------------
   -- RTU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_Register_Masks RTU Register Masks
 * @{
 */

/*! @name BTRTU1_TIMER1_LEN - Timer1 Length */
/*! @{ */

#define RTU_BTRTU1_TIMER1_LEN_len_MASK           (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER1_LEN_len_SHIFT          (0U)
/*! len - " */
#define RTU_BTRTU1_TIMER1_LEN_len(x)             (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER1_LEN_len_SHIFT)) & RTU_BTRTU1_TIMER1_LEN_len_MASK)
/*! @} */

/*! @name BTRTU1_TIMER2_LEN - Timer2 Length */
/*! @{ */

#define RTU_BTRTU1_TIMER2_LEN_len_MASK           (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER2_LEN_len_SHIFT          (0U)
/*! len - " */
#define RTU_BTRTU1_TIMER2_LEN_len(x)             (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER2_LEN_len_SHIFT)) & RTU_BTRTU1_TIMER2_LEN_len_MASK)
/*! @} */

/*! @name BTRTU1_TIMER3_LEN - Timer3 Length */
/*! @{ */

#define RTU_BTRTU1_TIMER3_LEN_len_MASK           (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER3_LEN_len_SHIFT          (0U)
/*! len - " */
#define RTU_BTRTU1_TIMER3_LEN_len(x)             (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER3_LEN_len_SHIFT)) & RTU_BTRTU1_TIMER3_LEN_len_MASK)
/*! @} */

/*! @name BTRTU1_TIMER4_LEN - Timer4 Length */
/*! @{ */

#define RTU_BTRTU1_TIMER4_LEN_len_MASK           (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER4_LEN_len_SHIFT          (0U)
/*! len - " */
#define RTU_BTRTU1_TIMER4_LEN_len(x)             (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER4_LEN_len_SHIFT)) & RTU_BTRTU1_TIMER4_LEN_len_MASK)
/*! @} */

/*! @name BTRTU1_CSR - Timer Control */
/*! @{ */

#define RTU_BTRTU1_CSR_t1_rst_MASK               (0x1U)
#define RTU_BTRTU1_CSR_t1_rst_SHIFT              (0U)
/*! t1_rst - " */
#define RTU_BTRTU1_CSR_t1_rst(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t1_rst_SHIFT)) & RTU_BTRTU1_CSR_t1_rst_MASK)

#define RTU_BTRTU1_CSR_t1_act_MASK               (0x2U)
#define RTU_BTRTU1_CSR_t1_act_SHIFT              (1U)
/*! t1_act - " */
#define RTU_BTRTU1_CSR_t1_act(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t1_act_SHIFT)) & RTU_BTRTU1_CSR_t1_act_MASK)

#define RTU_BTRTU1_CSR_t1_int_clr_sel_MASK       (0x4U)
#define RTU_BTRTU1_CSR_t1_int_clr_sel_SHIFT      (2U)
/*! t1_int_clr_sel - " */
#define RTU_BTRTU1_CSR_t1_int_clr_sel(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t1_int_clr_sel_SHIFT)) & RTU_BTRTU1_CSR_t1_int_clr_sel_MASK)

#define RTU_BTRTU1_CSR_t1_load_MASK              (0x8U)
#define RTU_BTRTU1_CSR_t1_load_SHIFT             (3U)
/*! t1_load - " */
#define RTU_BTRTU1_CSR_t1_load(x)                (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t1_load_SHIFT)) & RTU_BTRTU1_CSR_t1_load_MASK)

#define RTU_BTRTU1_CSR_t2_rst_MASK               (0x10U)
#define RTU_BTRTU1_CSR_t2_rst_SHIFT              (4U)
/*! t2_rst - " */
#define RTU_BTRTU1_CSR_t2_rst(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t2_rst_SHIFT)) & RTU_BTRTU1_CSR_t2_rst_MASK)

#define RTU_BTRTU1_CSR_t2_act_MASK               (0x20U)
#define RTU_BTRTU1_CSR_t2_act_SHIFT              (5U)
/*! t2_act - " */
#define RTU_BTRTU1_CSR_t2_act(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t2_act_SHIFT)) & RTU_BTRTU1_CSR_t2_act_MASK)

#define RTU_BTRTU1_CSR_t2_int_clr_sel_MASK       (0x40U)
#define RTU_BTRTU1_CSR_t2_int_clr_sel_SHIFT      (6U)
/*! t2_int_clr_sel - " */
#define RTU_BTRTU1_CSR_t2_int_clr_sel(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t2_int_clr_sel_SHIFT)) & RTU_BTRTU1_CSR_t2_int_clr_sel_MASK)

#define RTU_BTRTU1_CSR_t2_load_MASK              (0x80U)
#define RTU_BTRTU1_CSR_t2_load_SHIFT             (7U)
/*! t2_load - " */
#define RTU_BTRTU1_CSR_t2_load(x)                (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t2_load_SHIFT)) & RTU_BTRTU1_CSR_t2_load_MASK)

#define RTU_BTRTU1_CSR_t3_rst_MASK               (0x100U)
#define RTU_BTRTU1_CSR_t3_rst_SHIFT              (8U)
/*! t3_rst - " */
#define RTU_BTRTU1_CSR_t3_rst(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t3_rst_SHIFT)) & RTU_BTRTU1_CSR_t3_rst_MASK)

#define RTU_BTRTU1_CSR_t3_act_MASK               (0x200U)
#define RTU_BTRTU1_CSR_t3_act_SHIFT              (9U)
/*! t3_act - " */
#define RTU_BTRTU1_CSR_t3_act(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t3_act_SHIFT)) & RTU_BTRTU1_CSR_t3_act_MASK)

#define RTU_BTRTU1_CSR_t3_int_clr_sel_MASK       (0x400U)
#define RTU_BTRTU1_CSR_t3_int_clr_sel_SHIFT      (10U)
/*! t3_int_clr_sel - " */
#define RTU_BTRTU1_CSR_t3_int_clr_sel(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t3_int_clr_sel_SHIFT)) & RTU_BTRTU1_CSR_t3_int_clr_sel_MASK)

#define RTU_BTRTU1_CSR_t3_load_MASK              (0x800U)
#define RTU_BTRTU1_CSR_t3_load_SHIFT             (11U)
/*! t3_load - " */
#define RTU_BTRTU1_CSR_t3_load(x)                (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t3_load_SHIFT)) & RTU_BTRTU1_CSR_t3_load_MASK)

#define RTU_BTRTU1_CSR_t4_rst_MASK               (0x1000U)
#define RTU_BTRTU1_CSR_t4_rst_SHIFT              (12U)
/*! t4_rst - " */
#define RTU_BTRTU1_CSR_t4_rst(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t4_rst_SHIFT)) & RTU_BTRTU1_CSR_t4_rst_MASK)

#define RTU_BTRTU1_CSR_t4_act_MASK               (0x2000U)
#define RTU_BTRTU1_CSR_t4_act_SHIFT              (13U)
/*! t4_act - " */
#define RTU_BTRTU1_CSR_t4_act(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t4_act_SHIFT)) & RTU_BTRTU1_CSR_t4_act_MASK)

#define RTU_BTRTU1_CSR_t4_int_clr_sel_MASK       (0x4000U)
#define RTU_BTRTU1_CSR_t4_int_clr_sel_SHIFT      (14U)
/*! t4_int_clr_sel - " */
#define RTU_BTRTU1_CSR_t4_int_clr_sel(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t4_int_clr_sel_SHIFT)) & RTU_BTRTU1_CSR_t4_int_clr_sel_MASK)

#define RTU_BTRTU1_CSR_t4_load_MASK              (0x8000U)
#define RTU_BTRTU1_CSR_t4_load_SHIFT             (15U)
/*! t4_load - " */
#define RTU_BTRTU1_CSR_t4_load(x)                (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t4_load_SHIFT)) & RTU_BTRTU1_CSR_t4_load_MASK)

#define RTU_BTRTU1_CSR_t5_int_clr_sel_MASK       (0x10000U)
#define RTU_BTRTU1_CSR_t5_int_clr_sel_SHIFT      (16U)
/*! t5_int_clr_sel - " */
#define RTU_BTRTU1_CSR_t5_int_clr_sel(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_CSR_t5_int_clr_sel_SHIFT)) & RTU_BTRTU1_CSR_t5_int_clr_sel_MASK)
/*! @} */

/*! @name BTRTU1_TIMER1_VAL - Timer1 Value */
/*! @{ */

#define RTU_BTRTU1_TIMER1_VAL_timer1_val_MASK    (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER1_VAL_timer1_val_SHIFT   (0U)
/*! timer1_val - " */
#define RTU_BTRTU1_TIMER1_VAL_timer1_val(x)      (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER1_VAL_timer1_val_SHIFT)) & RTU_BTRTU1_TIMER1_VAL_timer1_val_MASK)
/*! @} */

/*! @name BTRTU1_TIMER2_VAL - Timer2 Value */
/*! @{ */

#define RTU_BTRTU1_TIMER2_VAL_timer2_val_MASK    (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER2_VAL_timer2_val_SHIFT   (0U)
/*! timer2_val - " */
#define RTU_BTRTU1_TIMER2_VAL_timer2_val(x)      (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER2_VAL_timer2_val_SHIFT)) & RTU_BTRTU1_TIMER2_VAL_timer2_val_MASK)
/*! @} */

/*! @name BTRTU1_TIMER3_VAL - Timer3 Value */
/*! @{ */

#define RTU_BTRTU1_TIMER3_VAL_timer3_val_MASK    (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER3_VAL_timer3_val_SHIFT   (0U)
/*! timer3_val - " */
#define RTU_BTRTU1_TIMER3_VAL_timer3_val(x)      (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER3_VAL_timer3_val_SHIFT)) & RTU_BTRTU1_TIMER3_VAL_timer3_val_MASK)
/*! @} */

/*! @name BTRTU1_TIMER4_VAL - Timer4 Value */
/*! @{ */

#define RTU_BTRTU1_TIMER4_VAL_timer4_val_MASK    (0xFFFFFFFFU)
#define RTU_BTRTU1_TIMER4_VAL_timer4_val_SHIFT   (0U)
/*! timer4_val - " */
#define RTU_BTRTU1_TIMER4_VAL_timer4_val(x)      (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_TIMER4_VAL_timer4_val_SHIFT)) & RTU_BTRTU1_TIMER4_VAL_timer4_val_MASK)
/*! @} */

/*! @name BTRTU1_ISR - Interrupt Soruce Status */
/*! @{ */

#define RTU_BTRTU1_ISR_t1_int_MASK               (0x1U)
#define RTU_BTRTU1_ISR_t1_int_SHIFT              (0U)
/*! t1_int - " */
#define RTU_BTRTU1_ISR_t1_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_ISR_t1_int_SHIFT)) & RTU_BTRTU1_ISR_t1_int_MASK)

#define RTU_BTRTU1_ISR_t2_int_MASK               (0x2U)
#define RTU_BTRTU1_ISR_t2_int_SHIFT              (1U)
/*! t2_int - " */
#define RTU_BTRTU1_ISR_t2_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_ISR_t2_int_SHIFT)) & RTU_BTRTU1_ISR_t2_int_MASK)

#define RTU_BTRTU1_ISR_t3_int_MASK               (0x4U)
#define RTU_BTRTU1_ISR_t3_int_SHIFT              (2U)
/*! t3_int - " */
#define RTU_BTRTU1_ISR_t3_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_ISR_t3_int_SHIFT)) & RTU_BTRTU1_ISR_t3_int_MASK)

#define RTU_BTRTU1_ISR_t4_int_MASK               (0x8U)
#define RTU_BTRTU1_ISR_t4_int_SHIFT              (3U)
/*! t4_int - " */
#define RTU_BTRTU1_ISR_t4_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_ISR_t4_int_SHIFT)) & RTU_BTRTU1_ISR_t4_int_MASK)

#define RTU_BTRTU1_ISR_wd_int_MASK               (0x10U)
#define RTU_BTRTU1_ISR_wd_int_SHIFT              (4U)
/*! wd_int - " */
#define RTU_BTRTU1_ISR_wd_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_ISR_wd_int_SHIFT)) & RTU_BTRTU1_ISR_wd_int_MASK)
/*! @} */

/*! @name BTRTU1_IMR - Interrupt Mask */
/*! @{ */

#define RTU_BTRTU1_IMR_t1_int_MASK               (0x1U)
#define RTU_BTRTU1_IMR_t1_int_SHIFT              (0U)
/*! t1_int - " */
#define RTU_BTRTU1_IMR_t1_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_IMR_t1_int_SHIFT)) & RTU_BTRTU1_IMR_t1_int_MASK)

#define RTU_BTRTU1_IMR_t2_int_MASK               (0x2U)
#define RTU_BTRTU1_IMR_t2_int_SHIFT              (1U)
/*! t2_int - " */
#define RTU_BTRTU1_IMR_t2_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_IMR_t2_int_SHIFT)) & RTU_BTRTU1_IMR_t2_int_MASK)

#define RTU_BTRTU1_IMR_t3_int_MASK               (0x4U)
#define RTU_BTRTU1_IMR_t3_int_SHIFT              (2U)
/*! t3_int - " */
#define RTU_BTRTU1_IMR_t3_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_IMR_t3_int_SHIFT)) & RTU_BTRTU1_IMR_t3_int_MASK)

#define RTU_BTRTU1_IMR_t4_int_MASK               (0x8U)
#define RTU_BTRTU1_IMR_t4_int_SHIFT              (3U)
/*! t4_int - " */
#define RTU_BTRTU1_IMR_t4_int(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_IMR_t4_int_SHIFT)) & RTU_BTRTU1_IMR_t4_int_MASK)
/*! @} */

/*! @name BTRTU1_PRER_1KHZ - 1kHz Timer Prescaler */
/*! @{ */

#define RTU_BTRTU1_PRER_1KHZ_prer_1khz_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER_1KHZ_prer_1khz_SHIFT     (0U)
/*! prer_1khz - " */
#define RTU_BTRTU1_PRER_1KHZ_prer_1khz(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER_1KHZ_prer_1khz_SHIFT)) & RTU_BTRTU1_PRER_1KHZ_prer_1khz_MASK)
/*! @} */

/*! @name BTRTU1_PRER_1MHZ - 1MHz Timer Prescaler */
/*! @{ */

#define RTU_BTRTU1_PRER_1MHZ_prer_1mhz_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER_1MHZ_prer_1mhz_SHIFT     (0U)
/*! prer_1mhz - " */
#define RTU_BTRTU1_PRER_1MHZ_prer_1mhz(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER_1MHZ_prer_1mhz_SHIFT)) & RTU_BTRTU1_PRER_1MHZ_prer_1mhz_MASK)
/*! @} */

/*! @name BTRTU1_WD_CTRL - Watchdog Control */
/*! @{ */

#define RTU_BTRTU1_WD_CTRL_wd_s2_en_MASK         (0x1U)
#define RTU_BTRTU1_WD_CTRL_wd_s2_en_SHIFT        (0U)
/*! wd_s2_en - " */
#define RTU_BTRTU1_WD_CTRL_wd_s2_en(x)           (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_WD_CTRL_wd_s2_en_SHIFT)) & RTU_BTRTU1_WD_CTRL_wd_s2_en_MASK)

#define RTU_BTRTU1_WD_CTRL_wd_s1_en_MASK         (0x2U)
#define RTU_BTRTU1_WD_CTRL_wd_s1_en_SHIFT        (1U)
/*! wd_s1_en - " */
#define RTU_BTRTU1_WD_CTRL_wd_s1_en(x)           (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_WD_CTRL_wd_s1_en_SHIFT)) & RTU_BTRTU1_WD_CTRL_wd_s1_en_MASK)

#define RTU_BTRTU1_WD_CTRL_wd_cnt_exp_MASK       (0x70U)
#define RTU_BTRTU1_WD_CTRL_wd_cnt_exp_SHIFT      (4U)
/*! wd_cnt_exp - " */
#define RTU_BTRTU1_WD_CTRL_wd_cnt_exp(x)         (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_WD_CTRL_wd_cnt_exp_SHIFT)) & RTU_BTRTU1_WD_CTRL_wd_cnt_exp_MASK)

#define RTU_BTRTU1_WD_CTRL_wd_clr_MASK           (0x100U)
#define RTU_BTRTU1_WD_CTRL_wd_clr_SHIFT          (8U)
/*! wd_clr - " */
#define RTU_BTRTU1_WD_CTRL_wd_clr(x)             (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_WD_CTRL_wd_clr_SHIFT)) & RTU_BTRTU1_WD_CTRL_wd_clr_MASK)

#define RTU_BTRTU1_WD_CTRL_trig_soft_rstn_MASK   (0x10000U)
#define RTU_BTRTU1_WD_CTRL_trig_soft_rstn_SHIFT  (16U)
/*! trig_soft_rstn - " */
#define RTU_BTRTU1_WD_CTRL_trig_soft_rstn(x)     (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_WD_CTRL_trig_soft_rstn_SHIFT)) & RTU_BTRTU1_WD_CTRL_trig_soft_rstn_MASK)
/*! @} */

/*! @name BTRTU1_PRER1_CNT - Prescaler1 Value */
/*! @{ */

#define RTU_BTRTU1_PRER1_CNT_prer1_cnt_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER1_CNT_prer1_cnt_SHIFT     (0U)
/*! prer1_cnt - " */
#define RTU_BTRTU1_PRER1_CNT_prer1_cnt(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER1_CNT_prer1_cnt_SHIFT)) & RTU_BTRTU1_PRER1_CNT_prer1_cnt_MASK)
/*! @} */

/*! @name BTRTU1_PRER2_CNT - Prescaler2 Value */
/*! @{ */

#define RTU_BTRTU1_PRER2_CNT_prer2_cnt_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER2_CNT_prer2_cnt_SHIFT     (0U)
/*! prer2_cnt - " */
#define RTU_BTRTU1_PRER2_CNT_prer2_cnt(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER2_CNT_prer2_cnt_SHIFT)) & RTU_BTRTU1_PRER2_CNT_prer2_cnt_MASK)
/*! @} */

/*! @name BTRTU1_PRER3_CNT - Prescaler3 Value */
/*! @{ */

#define RTU_BTRTU1_PRER3_CNT_prer3_cnt_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER3_CNT_prer3_cnt_SHIFT     (0U)
/*! prer3_cnt - " */
#define RTU_BTRTU1_PRER3_CNT_prer3_cnt(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER3_CNT_prer3_cnt_SHIFT)) & RTU_BTRTU1_PRER3_CNT_prer3_cnt_MASK)
/*! @} */

/*! @name BTRTU1_PRER4_CNT - Prescaler4 Value */
/*! @{ */

#define RTU_BTRTU1_PRER4_CNT_prer4_cnt_MASK      (0x3FFFFU)
#define RTU_BTRTU1_PRER4_CNT_prer4_cnt_SHIFT     (0U)
/*! prer4_cnt - " */
#define RTU_BTRTU1_PRER4_CNT_prer4_cnt(x)        (((uint32_t)(((uint32_t)(x)) << RTU_BTRTU1_PRER4_CNT_prer4_cnt_SHIFT)) & RTU_BTRTU1_PRER4_CNT_prer4_cnt_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTU_Register_Masks */


/*!
 * @}
 */ /* end of group RTU_Peripheral_Access_Layer */


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


#endif  /* PERI_RTU_H_ */


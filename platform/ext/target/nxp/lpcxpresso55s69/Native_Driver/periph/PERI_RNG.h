/*
** ###################################################################
**     Processors:          LPC5526JBD100
**                          LPC5526JBD64
**                          LPC5526JEV98
**                          LPC5528JBD100
**                          LPC5528JBD64
**                          LPC5528JEV59
**                          LPC5528JEV98
**                          LPC55S26JBD100
**                          LPC55S26JBD64
**                          LPC55S26JEV98
**                          LPC55S28JBD100
**                          LPC55S28JBD64
**                          LPC55S28JEV59
**                          LPC55S28JEV98
**                          LPC55S66JBD100_cm33_core0
**                          LPC55S66JBD100_cm33_core1
**                          LPC55S66JBD64_cm33_core0
**                          LPC55S66JBD64_cm33_core1
**                          LPC55S66JEV98_cm33_core0
**                          LPC55S66JEV98_cm33_core1
**                          LPC55S69JBD100_cm33_core0
**                          LPC55S69JBD100_cm33_core1
**                          LPC55S69JBD64_cm33_core0
**                          LPC55S69JBD64_cm33_core1
**                          LPC55S69JEV59_cm33_core0
**                          LPC55S69JEV59_cm33_core1
**                          LPC55S69JEV98_cm33_core0
**                          LPC55S69JEV98_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250529
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RNG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-08-22)
**         Initial version based on v0.2UM
**     - rev. 1.1 (2019-05-16)
**         Initial A1 version based on v1.3UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RNG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RNG
 *
 * CMSIS Peripheral Access Layer for RNG
 */

#if !defined(PERI_RNG_H_)
#define PERI_RNG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5526JBD100) || defined(CPU_LPC5526JBD64) || defined(CPU_LPC5526JEV98))
#include "LPC5526_COMMON.h"
#elif (defined(CPU_LPC5528JBD100) || defined(CPU_LPC5528JBD64) || defined(CPU_LPC5528JEV59) || defined(CPU_LPC5528JEV98))
#include "LPC5528_COMMON.h"
#elif (defined(CPU_LPC55S26JBD100) || defined(CPU_LPC55S26JBD64) || defined(CPU_LPC55S26JEV98))
#include "LPC55S26_COMMON.h"
#elif (defined(CPU_LPC55S28JBD100) || defined(CPU_LPC55S28JBD64) || defined(CPU_LPC55S28JEV59) || defined(CPU_LPC55S28JEV98))
#include "LPC55S28_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core0) || defined(CPU_LPC55S66JBD64_cm33_core0) || defined(CPU_LPC55S66JEV98_cm33_core0))
#include "LPC55S66_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S66JBD100_cm33_core1) || defined(CPU_LPC55S66JBD64_cm33_core1) || defined(CPU_LPC55S66JEV98_cm33_core1))
#include "LPC55S66_cm33_core1_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core0) || defined(CPU_LPC55S69JBD64_cm33_core0) || defined(CPU_LPC55S69JEV59_cm33_core0) || defined(CPU_LPC55S69JEV98_cm33_core0))
#include "LPC55S69_cm33_core0_COMMON.h"
#elif (defined(CPU_LPC55S69JBD100_cm33_core1) || defined(CPU_LPC55S69JBD64_cm33_core1) || defined(CPU_LPC55S69JEV59_cm33_core1) || defined(CPU_LPC55S69JEV98_cm33_core1))
#include "LPC55S69_cm33_core1_COMMON.h"
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
   -- RNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Peripheral_Access_Layer RNG Peripheral Access Layer
 * @{
 */

/** RNG - Register Layout Typedef */
typedef struct {
  __I  uint32_t RANDOM_NUMBER;                     /**< This register contains a random 32 bit number which is computed on demand, at each time it is read, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t COUNTER_VAL;                       /**< offset: 0x8 */
  __IO uint32_t COUNTER_CFG;                       /**< offset: 0xC */
  __IO uint32_t ONLINE_TEST_CFG;                   /**< offset: 0x10 */
  __I  uint32_t ONLINE_TEST_VAL;                   /**< offset: 0x14 */
       uint8_t RESERVED_1[4068];
  __I  uint32_t MODULEID;                          /**< IP identifier, offset: 0xFFC */
} RNG_Type;

/* ----------------------------------------------------------------------------
   -- RNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Register_Masks RNG Register Masks
 * @{
 */

/*! @name RANDOM_NUMBER - This register contains a random 32 bit number which is computed on demand, at each time it is read */
/*! @{ */

#define RNG_RANDOM_NUMBER_RANDOM_NUMBER_MASK     (0xFFFFFFFFU)
#define RNG_RANDOM_NUMBER_RANDOM_NUMBER_SHIFT    (0U)
/*! RANDOM_NUMBER - This register contains a random 32 bit number which is computed on demand, at each time it is read. */
#define RNG_RANDOM_NUMBER_RANDOM_NUMBER(x)       (((uint32_t)(((uint32_t)(x)) << RNG_RANDOM_NUMBER_RANDOM_NUMBER_SHIFT)) & RNG_RANDOM_NUMBER_RANDOM_NUMBER_MASK)
/*! @} */

/*! @name COUNTER_VAL -  */
/*! @{ */

#define RNG_COUNTER_VAL_CLK_RATIO_MASK           (0xFFU)
#define RNG_COUNTER_VAL_CLK_RATIO_SHIFT          (0U)
/*! CLK_RATIO - Gives the ratio between the internal clocks frequencies and the register clock
 *    frequency for evaluation and certification purposes.
 */
#define RNG_COUNTER_VAL_CLK_RATIO(x)             (((uint32_t)(((uint32_t)(x)) << RNG_COUNTER_VAL_CLK_RATIO_SHIFT)) & RNG_COUNTER_VAL_CLK_RATIO_MASK)

#define RNG_COUNTER_VAL_REFRESH_CNT_MASK         (0x1F00U)
#define RNG_COUNTER_VAL_REFRESH_CNT_SHIFT        (8U)
/*! REFRESH_CNT - Incremented (till max possible value) each time COUNTER was updated since last reading to any *_NUMBER. */
#define RNG_COUNTER_VAL_REFRESH_CNT(x)           (((uint32_t)(((uint32_t)(x)) << RNG_COUNTER_VAL_REFRESH_CNT_SHIFT)) & RNG_COUNTER_VAL_REFRESH_CNT_MASK)
/*! @} */

/*! @name COUNTER_CFG -  */
/*! @{ */

#define RNG_COUNTER_CFG_MODE_MASK                (0x3U)
#define RNG_COUNTER_CFG_MODE_SHIFT               (0U)
/*! MODE - 00: disabled 01: update once. */
#define RNG_COUNTER_CFG_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << RNG_COUNTER_CFG_MODE_SHIFT)) & RNG_COUNTER_CFG_MODE_MASK)

#define RNG_COUNTER_CFG_CLOCK_SEL_MASK           (0x1CU)
#define RNG_COUNTER_CFG_CLOCK_SEL_SHIFT          (2U)
/*! CLOCK_SEL - Selects the internal clock on which to compute statistics. */
#define RNG_COUNTER_CFG_CLOCK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << RNG_COUNTER_CFG_CLOCK_SEL_SHIFT)) & RNG_COUNTER_CFG_CLOCK_SEL_MASK)

#define RNG_COUNTER_CFG_SHIFT4X_MASK             (0xE0U)
#define RNG_COUNTER_CFG_SHIFT4X_SHIFT            (5U)
/*! SHIFT4X - To be used to add precision to clock_ratio and determine 'entropy refill'. */
#define RNG_COUNTER_CFG_SHIFT4X(x)               (((uint32_t)(((uint32_t)(x)) << RNG_COUNTER_CFG_SHIFT4X_SHIFT)) & RNG_COUNTER_CFG_SHIFT4X_MASK)
/*! @} */

/*! @name ONLINE_TEST_CFG -  */
/*! @{ */

#define RNG_ONLINE_TEST_CFG_ACTIVATE_MASK        (0x1U)
#define RNG_ONLINE_TEST_CFG_ACTIVATE_SHIFT       (0U)
/*! ACTIVATE - 0: disabled 1: activated Update rythm for VAL depends on COUNTER_CFG if data_sel is set to COUNTER. */
#define RNG_ONLINE_TEST_CFG_ACTIVATE(x)          (((uint32_t)(((uint32_t)(x)) << RNG_ONLINE_TEST_CFG_ACTIVATE_SHIFT)) & RNG_ONLINE_TEST_CFG_ACTIVATE_MASK)

#define RNG_ONLINE_TEST_CFG_DATA_SEL_MASK        (0x6U)
#define RNG_ONLINE_TEST_CFG_DATA_SEL_SHIFT       (1U)
/*! DATA_SEL - Selects source on which to apply online test: 00: LSB of COUNTER: raw data from one
 *    or all sources of entropy 01: MSB of COUNTER: raw data from one or all sources of entropy 10:
 *    RANDOM_NUMBER 11: ENCRYPTED_NUMBER 'activate' should be set to 'disabled' before changing this
 *    field.
 */
#define RNG_ONLINE_TEST_CFG_DATA_SEL(x)          (((uint32_t)(((uint32_t)(x)) << RNG_ONLINE_TEST_CFG_DATA_SEL_SHIFT)) & RNG_ONLINE_TEST_CFG_DATA_SEL_MASK)
/*! @} */

/*! @name ONLINE_TEST_VAL -  */
/*! @{ */

#define RNG_ONLINE_TEST_VAL_LIVE_CHI_SQUARED_MASK (0xFU)
#define RNG_ONLINE_TEST_VAL_LIVE_CHI_SQUARED_SHIFT (0U)
/*! LIVE_CHI_SQUARED - This value is updated as described in field 'activate'. */
#define RNG_ONLINE_TEST_VAL_LIVE_CHI_SQUARED(x)  (((uint32_t)(((uint32_t)(x)) << RNG_ONLINE_TEST_VAL_LIVE_CHI_SQUARED_SHIFT)) & RNG_ONLINE_TEST_VAL_LIVE_CHI_SQUARED_MASK)

#define RNG_ONLINE_TEST_VAL_MIN_CHI_SQUARED_MASK (0xF0U)
#define RNG_ONLINE_TEST_VAL_MIN_CHI_SQUARED_SHIFT (4U)
/*! MIN_CHI_SQUARED - This field is reset when 'activate'==0. */
#define RNG_ONLINE_TEST_VAL_MIN_CHI_SQUARED(x)   (((uint32_t)(((uint32_t)(x)) << RNG_ONLINE_TEST_VAL_MIN_CHI_SQUARED_SHIFT)) & RNG_ONLINE_TEST_VAL_MIN_CHI_SQUARED_MASK)

#define RNG_ONLINE_TEST_VAL_MAX_CHI_SQUARED_MASK (0xF00U)
#define RNG_ONLINE_TEST_VAL_MAX_CHI_SQUARED_SHIFT (8U)
/*! MAX_CHI_SQUARED - This field is reset when 'activate'==0. */
#define RNG_ONLINE_TEST_VAL_MAX_CHI_SQUARED(x)   (((uint32_t)(((uint32_t)(x)) << RNG_ONLINE_TEST_VAL_MAX_CHI_SQUARED_SHIFT)) & RNG_ONLINE_TEST_VAL_MAX_CHI_SQUARED_MASK)
/*! @} */

/*! @name MODULEID - IP identifier */
/*! @{ */

#define RNG_MODULEID_APERTURE_MASK               (0xFFU)
#define RNG_MODULEID_APERTURE_SHIFT              (0U)
/*! APERTURE - Aperture i. */
#define RNG_MODULEID_APERTURE(x)                 (((uint32_t)(((uint32_t)(x)) << RNG_MODULEID_APERTURE_SHIFT)) & RNG_MODULEID_APERTURE_MASK)

#define RNG_MODULEID_MIN_REV_MASK                (0xF00U)
#define RNG_MODULEID_MIN_REV_SHIFT               (8U)
/*! MIN_REV - Minor revision i. */
#define RNG_MODULEID_MIN_REV(x)                  (((uint32_t)(((uint32_t)(x)) << RNG_MODULEID_MIN_REV_SHIFT)) & RNG_MODULEID_MIN_REV_MASK)

#define RNG_MODULEID_MAJ_REV_MASK                (0xF000U)
#define RNG_MODULEID_MAJ_REV_SHIFT               (12U)
/*! MAJ_REV - Major revision i. */
#define RNG_MODULEID_MAJ_REV(x)                  (((uint32_t)(((uint32_t)(x)) << RNG_MODULEID_MAJ_REV_SHIFT)) & RNG_MODULEID_MAJ_REV_MASK)

#define RNG_MODULEID_ID_MASK                     (0xFFFF0000U)
#define RNG_MODULEID_ID_SHIFT                    (16U)
/*! ID - Identifier. */
#define RNG_MODULEID_ID(x)                       (((uint32_t)(((uint32_t)(x)) << RNG_MODULEID_ID_SHIFT)) & RNG_MODULEID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RNG_Register_Masks */


/*!
 * @}
 */ /* end of group RNG_Peripheral_Access_Layer */


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


#endif  /* PERI_RNG_H_ */


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
**         CMSIS Peripheral Access Layer for FREQME
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
 * @file PERI_FREQME.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FREQME
 *
 * CMSIS Peripheral Access Layer for FREQME
 */

#if !defined(PERI_FREQME_H_)
#define PERI_FREQME_H_                           /**< Symbol preventing repeated inclusion */

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
   -- FREQME Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FREQME_Peripheral_Access_Layer FREQME Peripheral Access Layer
 * @{
 */

/** FREQME - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __I  uint32_t CTRL_R;                            /**< Control (in Read mode), offset: 0x0 */
    __O  uint32_t CTRL_W;                            /**< Control (in Write mode), offset: 0x0 */
  };
  __IO uint32_t CTRLSTAT;                          /**< Control Status, offset: 0x4 */
  __IO uint32_t MIN;                               /**< Minimum, offset: 0x8 */
  __IO uint32_t MAX;                               /**< Maximum, offset: 0xC */
} FREQME_Type;

/* ----------------------------------------------------------------------------
   -- FREQME Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FREQME_Register_Masks FREQME Register Masks
 * @{
 */

/*! @name CTRL_R - Control (in Read mode) */
/*! @{ */

#define FREQME_CTRL_R_RESULT_MASK                (0x7FFFFFFFU)
#define FREQME_CTRL_R_RESULT_SHIFT               (0U)
#define FREQME_CTRL_R_RESULT(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_R_RESULT_SHIFT)) & FREQME_CTRL_R_RESULT_MASK)

#define FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK   (0x80000000U)
#define FREQME_CTRL_R_MEASURE_IN_PROGRESS_SHIFT  (31U)
/*! MEASURE_IN_PROGRESS - Measurement In Progress
 *  0b0..Complete
 *  0b1..In progress
 */
#define FREQME_CTRL_R_MEASURE_IN_PROGRESS(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_R_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name CTRL_W - Control (in Write mode) */
/*! @{ */

#define FREQME_CTRL_W_REF_SCALE_MASK             (0x1FU)
#define FREQME_CTRL_W_REF_SCALE_SHIFT            (0U)
/*! REF_SCALE - Reference Clock Scaling Factor */
#define FREQME_CTRL_W_REF_SCALE(x)               (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_REF_SCALE_SHIFT)) & FREQME_CTRL_W_REF_SCALE_MASK)

#define FREQME_CTRL_W_PULSE_MODE_MASK            (0x100U)
#define FREQME_CTRL_W_PULSE_MODE_SHIFT           (8U)
/*! PULSE_MODE - Pulse Width Measurement Mode Select
 *  0b0..Frequency Measurement mode
 *  0b1..Pulse Width Measurement mode
 */
#define FREQME_CTRL_W_PULSE_MODE(x)              (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_PULSE_MODE_SHIFT)) & FREQME_CTRL_W_PULSE_MODE_MASK)

#define FREQME_CTRL_W_PULSE_POL_MASK             (0x200U)
#define FREQME_CTRL_W_PULSE_POL_SHIFT            (9U)
/*! PULSE_POL - Pulse Polarity
 *  0b0..High period
 *  0b1..Low period
 */
#define FREQME_CTRL_W_PULSE_POL(x)               (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_PULSE_POL_SHIFT)) & FREQME_CTRL_W_PULSE_POL_MASK)

#define FREQME_CTRL_W_LT_MIN_INT_EN_MASK         (0x1000U)
#define FREQME_CTRL_W_LT_MIN_INT_EN_SHIFT        (12U)
/*! LT_MIN_INT_EN - Less Than Minimum Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_LT_MIN_INT_EN(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_LT_MIN_INT_EN_SHIFT)) & FREQME_CTRL_W_LT_MIN_INT_EN_MASK)

#define FREQME_CTRL_W_GT_MAX_INT_EN_MASK         (0x2000U)
#define FREQME_CTRL_W_GT_MAX_INT_EN_SHIFT        (13U)
/*! GT_MAX_INT_EN - Greater Than Maximum Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_GT_MAX_INT_EN(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_GT_MAX_INT_EN_SHIFT)) & FREQME_CTRL_W_GT_MAX_INT_EN_MASK)

#define FREQME_CTRL_W_RESULT_READY_INT_EN_MASK   (0x4000U)
#define FREQME_CTRL_W_RESULT_READY_INT_EN_SHIFT  (14U)
/*! RESULT_READY_INT_EN - Result Ready Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_RESULT_READY_INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_RESULT_READY_INT_EN_SHIFT)) & FREQME_CTRL_W_RESULT_READY_INT_EN_MASK)

#define FREQME_CTRL_W_CONTINUOUS_MODE_EN_MASK    (0x40000000U)
#define FREQME_CTRL_W_CONTINUOUS_MODE_EN_SHIFT   (30U)
/*! CONTINUOUS_MODE_EN - Continuous Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FREQME_CTRL_W_CONTINUOUS_MODE_EN(x)      (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_CONTINUOUS_MODE_EN_SHIFT)) & FREQME_CTRL_W_CONTINUOUS_MODE_EN_MASK)

#define FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK   (0x80000000U)
#define FREQME_CTRL_W_MEASURE_IN_PROGRESS_SHIFT  (31U)
/*! MEASURE_IN_PROGRESS - Measurement In Progress
 *  0b0..Terminates measurement
 *  0b1..Initiates measurement
 */
#define FREQME_CTRL_W_MEASURE_IN_PROGRESS(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRL_W_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name CTRLSTAT - Control Status */
/*! @{ */

#define FREQME_CTRLSTAT_REF_SCALE_MASK           (0x1FU)
#define FREQME_CTRLSTAT_REF_SCALE_SHIFT          (0U)
/*! REF_SCALE - Reference Scale */
#define FREQME_CTRLSTAT_REF_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_REF_SCALE_SHIFT)) & FREQME_CTRLSTAT_REF_SCALE_MASK)

#define FREQME_CTRLSTAT_PULSE_MODE_MASK          (0x100U)
#define FREQME_CTRLSTAT_PULSE_MODE_SHIFT         (8U)
/*! PULSE_MODE - Pulse Mode
 *  0b0..Frequency Measurement mode
 *  0b1..Pulse Width Measurement mode
 */
#define FREQME_CTRLSTAT_PULSE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_PULSE_MODE_SHIFT)) & FREQME_CTRLSTAT_PULSE_MODE_MASK)

#define FREQME_CTRLSTAT_PULSE_POL_MASK           (0x200U)
#define FREQME_CTRLSTAT_PULSE_POL_SHIFT          (9U)
/*! PULSE_POL - Pulse Polarity
 *  0b0..High period
 *  0b1..Low period
 */
#define FREQME_CTRLSTAT_PULSE_POL(x)             (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_PULSE_POL_SHIFT)) & FREQME_CTRLSTAT_PULSE_POL_MASK)

#define FREQME_CTRLSTAT_LT_MIN_INT_EN_MASK       (0x1000U)
#define FREQME_CTRLSTAT_LT_MIN_INT_EN_SHIFT      (12U)
/*! LT_MIN_INT_EN - Less Than Minimum Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_LT_MIN_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_LT_MIN_INT_EN_SHIFT)) & FREQME_CTRLSTAT_LT_MIN_INT_EN_MASK)

#define FREQME_CTRLSTAT_GT_MAX_INT_EN_MASK       (0x2000U)
#define FREQME_CTRLSTAT_GT_MAX_INT_EN_SHIFT      (13U)
/*! GT_MAX_INT_EN - Greater Than Maximum Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_GT_MAX_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_GT_MAX_INT_EN_SHIFT)) & FREQME_CTRLSTAT_GT_MAX_INT_EN_MASK)

#define FREQME_CTRLSTAT_RESULT_READY_INT_EN_MASK (0x4000U)
#define FREQME_CTRLSTAT_RESULT_READY_INT_EN_SHIFT (14U)
/*! RESULT_READY_INT_EN - Result Ready Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_RESULT_READY_INT_EN(x)   (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_RESULT_READY_INT_EN_SHIFT)) & FREQME_CTRLSTAT_RESULT_READY_INT_EN_MASK)

#define FREQME_CTRLSTAT_LT_MIN_STAT_MASK         (0x1000000U)
#define FREQME_CTRLSTAT_LT_MIN_STAT_SHIFT        (24U)
/*! LT_MIN_STAT - Less Than Minimum Results Status
 *  0b0..Greater than MIN[MIN_VALUE]
 *  0b1..Less than MIN[MIN_VALUE]
 */
#define FREQME_CTRLSTAT_LT_MIN_STAT(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_LT_MIN_STAT_SHIFT)) & FREQME_CTRLSTAT_LT_MIN_STAT_MASK)

#define FREQME_CTRLSTAT_GT_MAX_STAT_MASK         (0x2000000U)
#define FREQME_CTRLSTAT_GT_MAX_STAT_SHIFT        (25U)
/*! GT_MAX_STAT - Greater Than Maximum Result Status
 *  0b0..Less than MAX[MAX_VALUE]
 *  0b1..Greater than MAX[MAX_VALUE]
 */
#define FREQME_CTRLSTAT_GT_MAX_STAT(x)           (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_GT_MAX_STAT_SHIFT)) & FREQME_CTRLSTAT_GT_MAX_STAT_MASK)

#define FREQME_CTRLSTAT_RESULT_READY_STAT_MASK   (0x4000000U)
#define FREQME_CTRLSTAT_RESULT_READY_STAT_SHIFT  (26U)
/*! RESULT_READY_STAT - Result Ready Status
 *  0b0..Not complete
 *  0b1..Complete
 */
#define FREQME_CTRLSTAT_RESULT_READY_STAT(x)     (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_RESULT_READY_STAT_SHIFT)) & FREQME_CTRLSTAT_RESULT_READY_STAT_MASK)

#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_MASK  (0x40000000U)
#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_SHIFT (30U)
/*! CONTINUOUS_MODE_EN - Continuous Mode Enable Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FREQME_CTRLSTAT_CONTINUOUS_MODE_EN(x)    (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_SHIFT)) & FREQME_CTRLSTAT_CONTINUOUS_MODE_EN_MASK)

#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_MASK (0x80000000U)
#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_SHIFT (31U)
/*! MEASURE_IN_PROGRESS - Measurement in Progress Status
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define FREQME_CTRLSTAT_MEASURE_IN_PROGRESS(x)   (((uint32_t)(((uint32_t)(x)) << FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_SHIFT)) & FREQME_CTRLSTAT_MEASURE_IN_PROGRESS_MASK)
/*! @} */

/*! @name MIN - Minimum */
/*! @{ */

#define FREQME_MIN_MIN_VALUE_MASK                (0x7FFFFFFFU)
#define FREQME_MIN_MIN_VALUE_SHIFT               (0U)
/*! MIN_VALUE - Minimum Value */
#define FREQME_MIN_MIN_VALUE(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_MIN_MIN_VALUE_SHIFT)) & FREQME_MIN_MIN_VALUE_MASK)
/*! @} */

/*! @name MAX - Maximum */
/*! @{ */

#define FREQME_MAX_MAX_VALUE_MASK                (0x7FFFFFFFU)
#define FREQME_MAX_MAX_VALUE_SHIFT               (0U)
/*! MAX_VALUE - Maximum Value */
#define FREQME_MAX_MAX_VALUE(x)                  (((uint32_t)(((uint32_t)(x)) << FREQME_MAX_MAX_VALUE_SHIFT)) & FREQME_MAX_MAX_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FREQME_Register_Masks */


/*!
 * @}
 */ /* end of group FREQME_Peripheral_Access_Layer */


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


#endif  /* PERI_FREQME_H_ */


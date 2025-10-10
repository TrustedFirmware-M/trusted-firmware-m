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
**         CMSIS Peripheral Access Layer for PLU
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
 * @file PERI_PLU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PLU
 *
 * CMSIS Peripheral Access Layer for PLU
 */

#if !defined(PERI_PLU_H_)
#define PERI_PLU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PLU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Peripheral_Access_Layer PLU Peripheral Access Layer
 * @{
 */

/** PLU - Size of Registers Arrays */
#define PLU_LUT_INP_COUNT                         5u
#define PLU_LUT_COUNT                             26u
#define PLU_LUT_T_COUNT                           26u
#define PLU_OUTPUT_MUX_COUNT                      8u

/** PLU - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x20 */
    __IO uint32_t INP_MUX[PLU_LUT_INP_COUNT];        /**< Input select register for LUTn (0 to 25), Inputx (5 inputs), array offset: 0x0, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[12];
  } LUT[PLU_LUT_COUNT];
       uint8_t RESERVED_0[1216];
  __IO uint32_t LUT_TRUTH[PLU_LUT_T_COUNT];        /**< PLU LUT truth table, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_1[152];
  __I  uint32_t OUTPUTS;                           /**< PLU outputs, offset: 0x900 */
  __IO uint32_t WAKEINT_CTRL;                      /**< Wakeup interrupt control, offset: 0x904 */
       uint8_t RESERVED_2[760];
  __IO uint32_t OUTPUT_MUX[PLU_OUTPUT_MUX_COUNT];  /**< PLU output multiplexer, array offset: 0xC00, array step: 0x4 */
} PLU_Type;

/* ----------------------------------------------------------------------------
   -- PLU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Register_Masks PLU Register Masks
 * @{
 */

/*! @name LUT_INP_MUX - Input select register for LUTn (0 to 25), Inputx (5 inputs) */
/*! @{ */

#define PLU_LUT_INP_MUX_LUTn_INPx_MASK           (0x3FU)
#define PLU_LUT_INP_MUX_LUTn_INPx_SHIFT          (0U)
/*! LUTn_INPx - Selects the input source to be connected to LUTn_INPx
 *  0b000000..PLU primary inputs 0
 *  0b000001..PLU primary inputs 1
 *  0b000010..PLU primary inputs 2
 *  0b000011..PLU primary inputs 3
 *  0b000100..PLU primary inputs 4
 *  0b000101..PLU primary inputs 5
 *  0b000110..Output of LUT0
 *  0b000111..Output of LUT1
 *  0b001000..Output of LUT2
 *  0b001001..Output of LUT3
 *  0b001010..Output of LUT4
 *  0b001011..Output of LUT5
 *  0b001100..Output of LUT6
 *  0b001101..Output of LUT7
 *  0b001110..Output of LUT8
 *  0b001111..Output of LUT9
 *  0b010000..Output of LUT10
 *  0b010001..Output of LUT11
 *  0b010010..Output of LUT12
 *  0b010011..Output of LUT13
 *  0b010100..Output of LUT14
 *  0b010101..Output of LUT15
 *  0b010110..Output of LUT16
 *  0b010111..Output of LUT17
 *  0b011000..Output of LUT18
 *  0b011001..Output of LUT19
 *  0b011010..Output of LUT20
 *  0b011011..Output of LUT21
 *  0b011100..Output of LUT22
 *  0b011101..Output of LUT23
 *  0b011110..Output of LUT24
 *  0b011111..Output of LUT25
 *  0b100000..State[0]
 *  0b100001..State[1]
 *  0b100010..State[2]
 *  0b100011..State[3]
 */
#define PLU_LUT_INP_MUX_LUTn_INPx(x)             (((uint32_t)(((uint32_t)(x)) << PLU_LUT_INP_MUX_LUTn_INPx_SHIFT)) & PLU_LUT_INP_MUX_LUTn_INPx_MASK)
/*! @} */

/* The count of PLU_LUT_INP_MUX */
#define PLU_LUT_INP_MUX_COUNT                    (26U)

/* The count of PLU_LUT_INP_MUX */
#define PLU_LUT_INP_MUX_COUNT2                   (5U)

/*! @name LUT_TRUTH - PLU LUT truth table */
/*! @{ */

#define PLU_LUT_TRUTH_LUT_TRUTH_MASK             (0xFFFFFFFFU)
#define PLU_LUT_TRUTH_LUT_TRUTH_SHIFT            (0U)
/*! LUT_TRUTH - LUT truth table */
#define PLU_LUT_TRUTH_LUT_TRUTH(x)               (((uint32_t)(((uint32_t)(x)) << PLU_LUT_TRUTH_LUT_TRUTH_SHIFT)) & PLU_LUT_TRUTH_LUT_TRUTH_MASK)
/*! @} */

/* The count of PLU_LUT_TRUTH */
#define PLU_LUT_TRUTH_COUNT                      (26U)

/*! @name OUTPUTS - PLU outputs */
/*! @{ */

#define PLU_OUTPUTS_OUTPUT_STATE_MASK            (0xFFU)
#define PLU_OUTPUTS_OUTPUT_STATE_SHIFT           (0U)
/*! OUTPUT_STATE - Output state */
#define PLU_OUTPUTS_OUTPUT_STATE(x)              (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUTS_OUTPUT_STATE_SHIFT)) & PLU_OUTPUTS_OUTPUT_STATE_MASK)
/*! @} */

/*! @name WAKEINT_CTRL - Wakeup interrupt control */
/*! @{ */

#define PLU_WAKEINT_CTRL_MASK_MASK               (0xFFU)
#define PLU_WAKEINT_CTRL_MASK_SHIFT              (0U)
/*! MASK - Interrupt mask */
#define PLU_WAKEINT_CTRL_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << PLU_WAKEINT_CTRL_MASK_SHIFT)) & PLU_WAKEINT_CTRL_MASK_MASK)

#define PLU_WAKEINT_CTRL_FILTER_MODE_MASK        (0x300U)
#define PLU_WAKEINT_CTRL_FILTER_MODE_SHIFT       (8U)
/*! FILTER_MODE - Filter Mode
 *  0b00..Bypass mode
 *  0b01..Filter 1 clock period
 *  0b10..Filter 2 clock period
 *  0b11..Filter 3 clock period
 */
#define PLU_WAKEINT_CTRL_FILTER_MODE(x)          (((uint32_t)(((uint32_t)(x)) << PLU_WAKEINT_CTRL_FILTER_MODE_SHIFT)) & PLU_WAKEINT_CTRL_FILTER_MODE_MASK)

#define PLU_WAKEINT_CTRL_FILTER_CLKSEL_MASK      (0xC00U)
#define PLU_WAKEINT_CTRL_FILTER_CLKSEL_SHIFT     (10U)
/*! FILTER_CLKSEL - Filter clock select
 *  0b00..Selects the 1 MHz low-power oscillator as the filter clock.
 *  0b01..Selects the 12 MHz FRO as the filter clock.
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define PLU_WAKEINT_CTRL_FILTER_CLKSEL(x)        (((uint32_t)(((uint32_t)(x)) << PLU_WAKEINT_CTRL_FILTER_CLKSEL_SHIFT)) & PLU_WAKEINT_CTRL_FILTER_CLKSEL_MASK)

#define PLU_WAKEINT_CTRL_LATCH_ENABLE_MASK       (0x1000U)
#define PLU_WAKEINT_CTRL_LATCH_ENABLE_SHIFT      (12U)
/*! LATCH_ENABLE - Latch the interrupt */
#define PLU_WAKEINT_CTRL_LATCH_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << PLU_WAKEINT_CTRL_LATCH_ENABLE_SHIFT)) & PLU_WAKEINT_CTRL_LATCH_ENABLE_MASK)

#define PLU_WAKEINT_CTRL_INTR_CLEAR_MASK         (0x2000U)
#define PLU_WAKEINT_CTRL_INTR_CLEAR_SHIFT        (13U)
/*! INTR_CLEAR - Write to clear wakeint_latched */
#define PLU_WAKEINT_CTRL_INTR_CLEAR(x)           (((uint32_t)(((uint32_t)(x)) << PLU_WAKEINT_CTRL_INTR_CLEAR_SHIFT)) & PLU_WAKEINT_CTRL_INTR_CLEAR_MASK)
/*! @} */

/*! @name OUTPUT_MUX - PLU output multiplexer */
/*! @{ */

#define PLU_OUTPUT_MUX_OUTPUT_MASK               (0x1FU)
#define PLU_OUTPUT_MUX_OUTPUT_SHIFT              (0U)
/*! OUTPUT - Selects the source to be connected to PLU output n.
 *  0b00000..LUT output 0
 *  0b00001..LUT output 1
 *  0b00010..LUT output 2
 *  0b00011..LUT output 3
 *  0b00100..LUT output 4
 *  0b00101..LUT output 5
 *  0b00110..LUT output 6
 *  0b00111..LUT output 7
 *  0b01000..LUT output 8
 *  0b01001..LUT output 9
 *  0b01010..LUT output 10
 *  0b01011..LUT output 11
 *  0b01100..LUT output 12
 *  0b01101..LUT output 13
 *  0b01110..LUT output 14
 *  0b01111..LUT output 15
 *  0b10000..LUT output 16
 *  0b10001..LUT output 17
 *  0b10010..LUT output 18
 *  0b10011..LUT output 19
 *  0b10100..LUT output 20
 *  0b10101..LUT output 21
 *  0b10110..LUT output 22
 *  0b10111..LUT output 23
 *  0b11000..LUT output 24
 *  0b11001..LUT output 25
 *  0b11010..State[0]
 *  0b11011..State[1]
 *  0b11100..State[2]
 *  0b11101..State[3]
 */
#define PLU_OUTPUT_MUX_OUTPUT(x)                 (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUT_MUX_OUTPUT_SHIFT)) & PLU_OUTPUT_MUX_OUTPUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLU_Register_Masks */

/* Backward compatibility */
#define PLU                               PLU0


/*!
 * @}
 */ /* end of group PLU_Peripheral_Access_Layer */


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


#endif  /* PERI_PLU_H_ */


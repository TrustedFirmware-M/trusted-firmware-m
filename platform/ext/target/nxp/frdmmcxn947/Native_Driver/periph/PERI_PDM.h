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
**         CMSIS Peripheral Access Layer for PDM
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
 * @file PERI_PDM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PDM
 *
 * CMSIS Peripheral Access Layer for PDM
 */

#if !defined(PERI_PDM_H_)
#define PERI_PDM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PDM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDM_Peripheral_Access_Layer PDM Peripheral Access Layer
 * @{
 */

/** PDM - Size of Registers Arrays */
#define PDM_DATACHN_COUNT                         4u

/** PDM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL_1;                            /**< MICFIL Control 1, offset: 0x0 */
  __IO uint32_t CTRL_2;                            /**< MICFIL Control 2, offset: 0x4 */
  __IO uint32_t STAT;                              /**< MICFIL Status, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t FIFO_CTRL;                         /**< MICFIL FIFO Control, offset: 0x10 */
  __IO uint32_t FIFO_STAT;                         /**< MICFIL FIFO Status, offset: 0x14 */
       uint8_t RESERVED_1[12];
  __I  uint32_t DATACH[PDM_DATACHN_COUNT];         /**< MICFIL Output Result, array offset: 0x24, array step: 0x4 */
       uint8_t RESERVED_2[48];
  __I  uint32_t DC_CTRL;                           /**< MICFIL DC Remover Control, offset: 0x64 */
  __IO uint32_t DC_OUT_CTRL;                       /**< MICFIL Output DC Remover Control, offset: 0x68 */
       uint8_t RESERVED_3[8];
  __IO uint32_t RANGE_CTRL;                        /**< MICFIL Range Control, offset: 0x74 */
       uint8_t RESERVED_4[4];
  __IO uint32_t RANGE_STAT;                        /**< MICFIL Range Status, offset: 0x7C */
  __IO uint32_t FSYNC_CTRL;                        /**< Frame Synchronization Control, offset: 0x80 */
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x84 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x88 */
} PDM_Type;

/* ----------------------------------------------------------------------------
   -- PDM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDM_Register_Masks PDM Register Masks
 * @{
 */

/*! @name CTRL_1 - MICFIL Control 1 */
/*! @{ */

#define PDM_CTRL_1_CH0EN_MASK                    (0x1U)
#define PDM_CTRL_1_CH0EN_SHIFT                   (0U)
/*! CH0EN - Channel 0 Enable */
#define PDM_CTRL_1_CH0EN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_CH0EN_SHIFT)) & PDM_CTRL_1_CH0EN_MASK)

#define PDM_CTRL_1_CH1EN_MASK                    (0x2U)
#define PDM_CTRL_1_CH1EN_SHIFT                   (1U)
/*! CH1EN - Channel 1 Enable */
#define PDM_CTRL_1_CH1EN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_CH1EN_SHIFT)) & PDM_CTRL_1_CH1EN_MASK)

#define PDM_CTRL_1_CH2EN_MASK                    (0x4U)
#define PDM_CTRL_1_CH2EN_SHIFT                   (2U)
/*! CH2EN - Channel 2 Enable */
#define PDM_CTRL_1_CH2EN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_CH2EN_SHIFT)) & PDM_CTRL_1_CH2EN_MASK)

#define PDM_CTRL_1_CH3EN_MASK                    (0x8U)
#define PDM_CTRL_1_CH3EN_SHIFT                   (3U)
/*! CH3EN - Channel 3 Enable */
#define PDM_CTRL_1_CH3EN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_CH3EN_SHIFT)) & PDM_CTRL_1_CH3EN_MASK)

#define PDM_CTRL_1_FSYNCEN_MASK                  (0x10000U)
#define PDM_CTRL_1_FSYNCEN_SHIFT                 (16U)
/*! FSYNCEN - Frame Synchronization Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDM_CTRL_1_FSYNCEN(x)                    (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_FSYNCEN_SHIFT)) & PDM_CTRL_1_FSYNCEN_MASK)

#define PDM_CTRL_1_DECFILS_MASK                  (0x100000U)
#define PDM_CTRL_1_DECFILS_SHIFT                 (20U)
/*! DECFILS - Decimation Filter Enable in Stop
 *  0b0..Stops decimation filter
 *  0b1..Keeps decimation filter running
 */
#define PDM_CTRL_1_DECFILS(x)                    (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_DECFILS_SHIFT)) & PDM_CTRL_1_DECFILS_MASK)

#define PDM_CTRL_1_ERREN_MASK                    (0x800000U)
#define PDM_CTRL_1_ERREN_SHIFT                   (23U)
/*! ERREN - Error Interruption Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDM_CTRL_1_ERREN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_ERREN_SHIFT)) & PDM_CTRL_1_ERREN_MASK)

#define PDM_CTRL_1_DISEL_MASK                    (0x3000000U)
#define PDM_CTRL_1_DISEL_SHIFT                   (24U)
/*! DISEL - DMA Interrupt Selection
 *  0b00..Disables DMA and interrupt requests
 *  0b01..Enables DMA requests
 *  0b10..Enables interrupt requests
 *  0b11..Reserved
 */
#define PDM_CTRL_1_DISEL(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_DISEL_SHIFT)) & PDM_CTRL_1_DISEL_MASK)

#define PDM_CTRL_1_DBGE_MASK                     (0x4000000U)
#define PDM_CTRL_1_DBGE_SHIFT                    (26U)
/*! DBGE - Module Enable in Debug
 *  0b0..Disables after completing the current frame
 *  0b1..Enables operation
 */
#define PDM_CTRL_1_DBGE(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_DBGE_SHIFT)) & PDM_CTRL_1_DBGE_MASK)

#define PDM_CTRL_1_SRES_MASK                     (0x8000000U)
#define PDM_CTRL_1_SRES_SHIFT                    (27U)
/*! SRES - Software Reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define PDM_CTRL_1_SRES(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_SRES_SHIFT)) & PDM_CTRL_1_SRES_MASK)

#define PDM_CTRL_1_DBG_MASK                      (0x10000000U)
#define PDM_CTRL_1_DBG_SHIFT                     (28U)
/*! DBG - Debug Mode
 *  0b0..Normal
 *  0b1..Debug
 */
#define PDM_CTRL_1_DBG(x)                        (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_DBG_SHIFT)) & PDM_CTRL_1_DBG_MASK)

#define PDM_CTRL_1_PDMIEN_MASK                   (0x20000000U)
#define PDM_CTRL_1_PDMIEN_SHIFT                  (29U)
/*! PDMIEN - MICFIL Enable
 *  0b0..Stops MICFIL operation
 *  0b1..Starts MICFIL operation
 */
#define PDM_CTRL_1_PDMIEN(x)                     (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_PDMIEN_SHIFT)) & PDM_CTRL_1_PDMIEN_MASK)

#define PDM_CTRL_1_DOZEN_MASK                    (0x40000000U)
#define PDM_CTRL_1_DOZEN_SHIFT                   (30U)
/*! DOZEN - Stop Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDM_CTRL_1_DOZEN(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_DOZEN_SHIFT)) & PDM_CTRL_1_DOZEN_MASK)

#define PDM_CTRL_1_MDIS_MASK                     (0x80000000U)
#define PDM_CTRL_1_MDIS_SHIFT                    (31U)
/*! MDIS - Module Disable
 *  0b0..Normal mode
 *  0b1..DLL mode
 */
#define PDM_CTRL_1_MDIS(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_1_MDIS_SHIFT)) & PDM_CTRL_1_MDIS_MASK)
/*! @} */

/*! @name CTRL_2 - MICFIL Control 2 */
/*! @{ */

#define PDM_CTRL_2_CLKDIV_MASK                   (0xFFU)
#define PDM_CTRL_2_CLKDIV_SHIFT                  (0U)
/*! CLKDIV - Clock Divider
 *  0b00000000..Internal clock divider value = 0
 *  0b00000001..Internal clock divider value = 1
 *  0b00000010-0b11111110.....
 *  0b11111111..Internal clock divider value = 255
 */
#define PDM_CTRL_2_CLKDIV(x)                     (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_2_CLKDIV_SHIFT)) & PDM_CTRL_2_CLKDIV_MASK)

#define PDM_CTRL_2_CLKDIVDIS_MASK                (0x8000U)
#define PDM_CTRL_2_CLKDIVDIS_SHIFT               (15U)
/*! CLKDIVDIS - Clock Divider Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define PDM_CTRL_2_CLKDIVDIS(x)                  (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_2_CLKDIVDIS_SHIFT)) & PDM_CTRL_2_CLKDIVDIS_MASK)

#define PDM_CTRL_2_CICOSR_MASK                   (0xF0000U)
#define PDM_CTRL_2_CICOSR_SHIFT                  (16U)
/*! CICOSR - CIC Decimation Rate
 *  0b0000..CIC oversampling rate = 0
 *  0b0001..CIC oversampling rate = 1
 *  0b0010-0b1110.....
 *  0b1111..CIC oversampling rate = 15
 */
#define PDM_CTRL_2_CICOSR(x)                     (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_2_CICOSR_SHIFT)) & PDM_CTRL_2_CICOSR_MASK)

#define PDM_CTRL_2_QSEL_MASK                     (0xE000000U)
#define PDM_CTRL_2_QSEL_SHIFT                    (25U)
/*! QSEL - Quality Mode
 *  0b000..Medium-Quality mode
 *  0b001..High-Quality mode
 *  0b100..Very-Low-Quality 2 mode
 *  0b101..Very-Low-Quality 1 mode
 *  0b110..Very-Low-Quality 0 mode
 *  0b111..Low-Quality mode
 */
#define PDM_CTRL_2_QSEL(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_CTRL_2_QSEL_SHIFT)) & PDM_CTRL_2_QSEL_MASK)
/*! @} */

/*! @name STAT - MICFIL Status */
/*! @{ */

#define PDM_STAT_CH0F_MASK                       (0x1U)
#define PDM_STAT_CH0F_SHIFT                      (0U)
/*! CH0F - Channel 0 Output Data Flag
 *  0b0..Not surpassed
 *  0b1..Surpassed
 */
#define PDM_STAT_CH0F(x)                         (((uint32_t)(((uint32_t)(x)) << PDM_STAT_CH0F_SHIFT)) & PDM_STAT_CH0F_MASK)

#define PDM_STAT_CH1F_MASK                       (0x2U)
#define PDM_STAT_CH1F_SHIFT                      (1U)
/*! CH1F - Channel 1 Output Data Flag
 *  0b0..Not surpassed
 *  0b1..Surpassed
 */
#define PDM_STAT_CH1F(x)                         (((uint32_t)(((uint32_t)(x)) << PDM_STAT_CH1F_SHIFT)) & PDM_STAT_CH1F_MASK)

#define PDM_STAT_CH2F_MASK                       (0x4U)
#define PDM_STAT_CH2F_SHIFT                      (2U)
/*! CH2F - Channel 2 Output Data Flag
 *  0b0..Not surpassed
 *  0b1..Surpassed
 */
#define PDM_STAT_CH2F(x)                         (((uint32_t)(((uint32_t)(x)) << PDM_STAT_CH2F_SHIFT)) & PDM_STAT_CH2F_MASK)

#define PDM_STAT_CH3F_MASK                       (0x8U)
#define PDM_STAT_CH3F_SHIFT                      (3U)
/*! CH3F - Channel 3 Output Data Flag
 *  0b0..Not surpassed
 *  0b1..Surpassed
 */
#define PDM_STAT_CH3F(x)                         (((uint32_t)(((uint32_t)(x)) << PDM_STAT_CH3F_SHIFT)) & PDM_STAT_CH3F_MASK)

#define PDM_STAT_BSY_FIL_MASK                    (0x80000000U)
#define PDM_STAT_BSY_FIL_SHIFT                   (31U)
/*! BSY_FIL - Busy Flag
 *  0b0..MICFIL is stopped
 *  0b1..MICFIL is running
 */
#define PDM_STAT_BSY_FIL(x)                      (((uint32_t)(((uint32_t)(x)) << PDM_STAT_BSY_FIL_SHIFT)) & PDM_STAT_BSY_FIL_MASK)
/*! @} */

/*! @name FIFO_CTRL - MICFIL FIFO Control */
/*! @{ */

#define PDM_FIFO_CTRL_FIFOWMK_MASK               (0xFU)
#define PDM_FIFO_CTRL_FIFOWMK_SHIFT              (0U)
/*! FIFOWMK - FIFO Watermark Control */
#define PDM_FIFO_CTRL_FIFOWMK(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_CTRL_FIFOWMK_SHIFT)) & PDM_FIFO_CTRL_FIFOWMK_MASK)
/*! @} */

/*! @name FIFO_STAT - MICFIL FIFO Status */
/*! @{ */

#define PDM_FIFO_STAT_FIFOOVF0_MASK              (0x1U)
#define PDM_FIFO_STAT_FIFOOVF0_SHIFT             (0U)
/*! FIFOOVF0 - FIFO Overflow Exception Flag for Channel 0
 *  0b0..No exception by FIFO overflow
 *  0b1..Exception by FIFO overflow
 */
#define PDM_FIFO_STAT_FIFOOVF0(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOOVF0_SHIFT)) & PDM_FIFO_STAT_FIFOOVF0_MASK)

#define PDM_FIFO_STAT_FIFOOVF1_MASK              (0x2U)
#define PDM_FIFO_STAT_FIFOOVF1_SHIFT             (1U)
/*! FIFOOVF1 - FIFO Overflow Exception Flag for Channel 1
 *  0b0..No exception by FIFO overflow
 *  0b1..Exception by FIFO overflow
 */
#define PDM_FIFO_STAT_FIFOOVF1(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOOVF1_SHIFT)) & PDM_FIFO_STAT_FIFOOVF1_MASK)

#define PDM_FIFO_STAT_FIFOOVF2_MASK              (0x4U)
#define PDM_FIFO_STAT_FIFOOVF2_SHIFT             (2U)
/*! FIFOOVF2 - FIFO Overflow Exception Flag for Channel 2
 *  0b0..No exception by FIFO overflow
 *  0b1..Exception by FIFO overflow
 */
#define PDM_FIFO_STAT_FIFOOVF2(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOOVF2_SHIFT)) & PDM_FIFO_STAT_FIFOOVF2_MASK)

#define PDM_FIFO_STAT_FIFOOVF3_MASK              (0x8U)
#define PDM_FIFO_STAT_FIFOOVF3_SHIFT             (3U)
/*! FIFOOVF3 - FIFO Overflow Exception Flag for Channel 3
 *  0b0..No exception by FIFO overflow
 *  0b1..Exception by FIFO overflow
 */
#define PDM_FIFO_STAT_FIFOOVF3(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOOVF3_SHIFT)) & PDM_FIFO_STAT_FIFOOVF3_MASK)

#define PDM_FIFO_STAT_FIFOUND0_MASK              (0x100U)
#define PDM_FIFO_STAT_FIFOUND0_SHIFT             (8U)
/*! FIFOUND0 - FIFO Underflow Exception Flag for Channel 0
 *  0b0..No exception by FIFO underflow
 *  0b1..Exception by FIFO underflow
 */
#define PDM_FIFO_STAT_FIFOUND0(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOUND0_SHIFT)) & PDM_FIFO_STAT_FIFOUND0_MASK)

#define PDM_FIFO_STAT_FIFOUND1_MASK              (0x200U)
#define PDM_FIFO_STAT_FIFOUND1_SHIFT             (9U)
/*! FIFOUND1 - FIFO Underflow Exception Flag for Channel 1
 *  0b0..No exception by FIFO underflow
 *  0b1..Exception by FIFO underflow
 */
#define PDM_FIFO_STAT_FIFOUND1(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOUND1_SHIFT)) & PDM_FIFO_STAT_FIFOUND1_MASK)

#define PDM_FIFO_STAT_FIFOUND2_MASK              (0x400U)
#define PDM_FIFO_STAT_FIFOUND2_SHIFT             (10U)
/*! FIFOUND2 - FIFO Underflow Exception Flag for Channel 2
 *  0b0..No exception by FIFO underflow
 *  0b1..Exception by FIFO underflow
 */
#define PDM_FIFO_STAT_FIFOUND2(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOUND2_SHIFT)) & PDM_FIFO_STAT_FIFOUND2_MASK)

#define PDM_FIFO_STAT_FIFOUND3_MASK              (0x800U)
#define PDM_FIFO_STAT_FIFOUND3_SHIFT             (11U)
/*! FIFOUND3 - FIFO Underflow Exception Flag for Channel 3
 *  0b0..No exception by FIFO underflow
 *  0b1..Exception by FIFO underflow
 */
#define PDM_FIFO_STAT_FIFOUND3(x)                (((uint32_t)(((uint32_t)(x)) << PDM_FIFO_STAT_FIFOUND3_SHIFT)) & PDM_FIFO_STAT_FIFOUND3_MASK)
/*! @} */

/*! @name DATACHN_DATACH - MICFIL Output Result */
/*! @{ */

#define PDM_DATACHN_DATACH_DATA_MASK             (0xFFFFFFFFU)
#define PDM_DATACHN_DATACH_DATA_SHIFT            (0U)
/*! DATA - Channel n Data */
#define PDM_DATACHN_DATACH_DATA(x)               (((uint32_t)(((uint32_t)(x)) << PDM_DATACHN_DATACH_DATA_SHIFT)) & PDM_DATACHN_DATACH_DATA_MASK)
/*! @} */

/* The count of PDM_DATACHN_DATACH */
#define PDM_DATACHN_DATACH_COUNT                 (4U)

/*! @name DC_CTRL - MICFIL DC Remover Control */
/*! @{ */

#define PDM_DC_CTRL_DCCONFIG0_MASK               (0x3U)
#define PDM_DC_CTRL_DCCONFIG0_SHIFT              (0U)
/*! DCCONFIG0 - Channel 0 DC Remover Configuration
 *  0b00..20 Hz (PDM_CLK = 3.072 MHz)
 *  0b01..13.3 Hz (PDM_CLK = 3.072 MHz)
 *  0b10..40 Hz (PDM_CLK = 3.072 MHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_CTRL_DCCONFIG0(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_DC_CTRL_DCCONFIG0_SHIFT)) & PDM_DC_CTRL_DCCONFIG0_MASK)

#define PDM_DC_CTRL_DCCONFIG1_MASK               (0xCU)
#define PDM_DC_CTRL_DCCONFIG1_SHIFT              (2U)
/*! DCCONFIG1 - Channel 1 DC Remover Configuration
 *  0b00..20 Hz (PDM_CLK = 3.072 MHz)
 *  0b01..13.3 Hz (PDM_CLK = 3.072 MHz)
 *  0b10..40 Hz (PDM_CLK = 3.072 MHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_CTRL_DCCONFIG1(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_DC_CTRL_DCCONFIG1_SHIFT)) & PDM_DC_CTRL_DCCONFIG1_MASK)

#define PDM_DC_CTRL_DCCONFIG2_MASK               (0x30U)
#define PDM_DC_CTRL_DCCONFIG2_SHIFT              (4U)
/*! DCCONFIG2 - Channel 2 DC Remover Configuration
 *  0b00..20 Hz (PDM_CLK = 3.072 MHz)
 *  0b01..13.3 Hz (PDM_CLK = 3.072 MHz)
 *  0b10..40 Hz (PDM_CLK = 3.072 MHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_CTRL_DCCONFIG2(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_DC_CTRL_DCCONFIG2_SHIFT)) & PDM_DC_CTRL_DCCONFIG2_MASK)

#define PDM_DC_CTRL_DCCONFIG3_MASK               (0xC0U)
#define PDM_DC_CTRL_DCCONFIG3_SHIFT              (6U)
/*! DCCONFIG3 - Channel 3 DC Remover Configuration
 *  0b00..20 Hz (PDM_CLK = 3.072 MHz)
 *  0b01..13.3 Hz (PDM_CLK = 3.072 MHz)
 *  0b10..40 Hz (PDM_CLK = 3.072 MHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_CTRL_DCCONFIG3(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_DC_CTRL_DCCONFIG3_SHIFT)) & PDM_DC_CTRL_DCCONFIG3_MASK)
/*! @} */

/*! @name DC_OUT_CTRL - MICFIL Output DC Remover Control */
/*! @{ */

#define PDM_DC_OUT_CTRL_DCCONFIG0_MASK           (0x3U)
#define PDM_DC_OUT_CTRL_DCCONFIG0_SHIFT          (0U)
/*! DCCONFIG0 - Channel 0 DC Remover Configuration
 *  0b00..20 Hz (FS = 48 kHz)
 *  0b01..13.3 Hz (FS = 48 kHz)
 *  0b10..40 Hz (FS = 48 kHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_OUT_CTRL_DCCONFIG0(x)             (((uint32_t)(((uint32_t)(x)) << PDM_DC_OUT_CTRL_DCCONFIG0_SHIFT)) & PDM_DC_OUT_CTRL_DCCONFIG0_MASK)

#define PDM_DC_OUT_CTRL_DCCONFIG1_MASK           (0xCU)
#define PDM_DC_OUT_CTRL_DCCONFIG1_SHIFT          (2U)
/*! DCCONFIG1 - Channel 1 DC Remover Configuration
 *  0b00..20 Hz (FS = 48 kHz)
 *  0b01..13.3 Hz (FS = 48 kHz)
 *  0b10..40 Hz (FS = 48 kHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_OUT_CTRL_DCCONFIG1(x)             (((uint32_t)(((uint32_t)(x)) << PDM_DC_OUT_CTRL_DCCONFIG1_SHIFT)) & PDM_DC_OUT_CTRL_DCCONFIG1_MASK)

#define PDM_DC_OUT_CTRL_DCCONFIG2_MASK           (0x30U)
#define PDM_DC_OUT_CTRL_DCCONFIG2_SHIFT          (4U)
/*! DCCONFIG2 - Channel 2 DC Remover Configuration
 *  0b00..20 Hz (FS = 48 kHz)
 *  0b01..13.3 Hz (FS = 48 kHz)
 *  0b10..40 Hz (FS = 48 kHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_OUT_CTRL_DCCONFIG2(x)             (((uint32_t)(((uint32_t)(x)) << PDM_DC_OUT_CTRL_DCCONFIG2_SHIFT)) & PDM_DC_OUT_CTRL_DCCONFIG2_MASK)

#define PDM_DC_OUT_CTRL_DCCONFIG3_MASK           (0xC0U)
#define PDM_DC_OUT_CTRL_DCCONFIG3_SHIFT          (6U)
/*! DCCONFIG3 - Channel 3 DC Remover Configuration
 *  0b00..20 Hz (FS = 48 kHz)
 *  0b01..13.3 Hz (FS = 48 kHz)
 *  0b10..40 Hz (FS = 48 kHz)
 *  0b11..DC remover is bypassed
 */
#define PDM_DC_OUT_CTRL_DCCONFIG3(x)             (((uint32_t)(((uint32_t)(x)) << PDM_DC_OUT_CTRL_DCCONFIG3_SHIFT)) & PDM_DC_OUT_CTRL_DCCONFIG3_MASK)
/*! @} */

/*! @name RANGE_CTRL - MICFIL Range Control */
/*! @{ */

#define PDM_RANGE_CTRL_RANGEADJ0_MASK            (0xFU)
#define PDM_RANGE_CTRL_RANGEADJ0_SHIFT           (0U)
/*! RANGEADJ0 - Channel 0 Range Adjustment */
#define PDM_RANGE_CTRL_RANGEADJ0(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_CTRL_RANGEADJ0_SHIFT)) & PDM_RANGE_CTRL_RANGEADJ0_MASK)

#define PDM_RANGE_CTRL_RANGEADJ1_MASK            (0xF0U)
#define PDM_RANGE_CTRL_RANGEADJ1_SHIFT           (4U)
/*! RANGEADJ1 - Channel 1 Range Adjustment */
#define PDM_RANGE_CTRL_RANGEADJ1(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_CTRL_RANGEADJ1_SHIFT)) & PDM_RANGE_CTRL_RANGEADJ1_MASK)

#define PDM_RANGE_CTRL_RANGEADJ2_MASK            (0xF00U)
#define PDM_RANGE_CTRL_RANGEADJ2_SHIFT           (8U)
/*! RANGEADJ2 - Channel 2 Range Adjustment */
#define PDM_RANGE_CTRL_RANGEADJ2(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_CTRL_RANGEADJ2_SHIFT)) & PDM_RANGE_CTRL_RANGEADJ2_MASK)

#define PDM_RANGE_CTRL_RANGEADJ3_MASK            (0xF000U)
#define PDM_RANGE_CTRL_RANGEADJ3_SHIFT           (12U)
/*! RANGEADJ3 - Channel 3 Range Adjustment */
#define PDM_RANGE_CTRL_RANGEADJ3(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_CTRL_RANGEADJ3_SHIFT)) & PDM_RANGE_CTRL_RANGEADJ3_MASK)
/*! @} */

/*! @name RANGE_STAT - MICFIL Range Status */
/*! @{ */

#define PDM_RANGE_STAT_RANGEOVF0_MASK            (0x1U)
#define PDM_RANGE_STAT_RANGEOVF0_SHIFT           (0U)
/*! RANGEOVF0 - Channel 0 Range Overflow Error Flag
 *  0b0..No exception by range overflow
 *  0b1..Exception by range overflow
 */
#define PDM_RANGE_STAT_RANGEOVF0(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEOVF0_SHIFT)) & PDM_RANGE_STAT_RANGEOVF0_MASK)

#define PDM_RANGE_STAT_RANGEOVF1_MASK            (0x2U)
#define PDM_RANGE_STAT_RANGEOVF1_SHIFT           (1U)
/*! RANGEOVF1 - Channel 1 Range Overflow Error Flag
 *  0b0..No exception by range overflow
 *  0b1..Exception by range overflow
 */
#define PDM_RANGE_STAT_RANGEOVF1(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEOVF1_SHIFT)) & PDM_RANGE_STAT_RANGEOVF1_MASK)

#define PDM_RANGE_STAT_RANGEOVF2_MASK            (0x4U)
#define PDM_RANGE_STAT_RANGEOVF2_SHIFT           (2U)
/*! RANGEOVF2 - Channel 2 Range Overflow Error Flag
 *  0b0..No exception by range overflow
 *  0b1..Exception by range overflow
 */
#define PDM_RANGE_STAT_RANGEOVF2(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEOVF2_SHIFT)) & PDM_RANGE_STAT_RANGEOVF2_MASK)

#define PDM_RANGE_STAT_RANGEOVF3_MASK            (0x8U)
#define PDM_RANGE_STAT_RANGEOVF3_SHIFT           (3U)
/*! RANGEOVF3 - Channel 3 Range Overflow Error Flag
 *  0b0..No exception by range overflow
 *  0b1..Exception by range overflow
 */
#define PDM_RANGE_STAT_RANGEOVF3(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEOVF3_SHIFT)) & PDM_RANGE_STAT_RANGEOVF3_MASK)

#define PDM_RANGE_STAT_RANGEUNF0_MASK            (0x10000U)
#define PDM_RANGE_STAT_RANGEUNF0_SHIFT           (16U)
/*! RANGEUNF0 - Channel 0 Range Underflow Error Flag
 *  0b0..No exception by range underflow
 *  0b1..Exception by range underflow
 */
#define PDM_RANGE_STAT_RANGEUNF0(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEUNF0_SHIFT)) & PDM_RANGE_STAT_RANGEUNF0_MASK)

#define PDM_RANGE_STAT_RANGEUNF1_MASK            (0x20000U)
#define PDM_RANGE_STAT_RANGEUNF1_SHIFT           (17U)
/*! RANGEUNF1 - Channel 1 Range Underflow Error Flag
 *  0b0..No exception by range underflow
 *  0b1..Exception by range underflow
 */
#define PDM_RANGE_STAT_RANGEUNF1(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEUNF1_SHIFT)) & PDM_RANGE_STAT_RANGEUNF1_MASK)

#define PDM_RANGE_STAT_RANGEUNF2_MASK            (0x40000U)
#define PDM_RANGE_STAT_RANGEUNF2_SHIFT           (18U)
/*! RANGEUNF2 - Channel 2 Range Underflow Error Flag
 *  0b0..No exception by range underflow
 *  0b1..Exception by range underflow
 */
#define PDM_RANGE_STAT_RANGEUNF2(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEUNF2_SHIFT)) & PDM_RANGE_STAT_RANGEUNF2_MASK)

#define PDM_RANGE_STAT_RANGEUNF3_MASK            (0x80000U)
#define PDM_RANGE_STAT_RANGEUNF3_SHIFT           (19U)
/*! RANGEUNF3 - Channel 3 Range Underflow Error Flag
 *  0b0..No exception by range underflow
 *  0b1..Exception by range underflow
 */
#define PDM_RANGE_STAT_RANGEUNF3(x)              (((uint32_t)(((uint32_t)(x)) << PDM_RANGE_STAT_RANGEUNF3_SHIFT)) & PDM_RANGE_STAT_RANGEUNF3_MASK)
/*! @} */

/*! @name FSYNC_CTRL - Frame Synchronization Control */
/*! @{ */

#define PDM_FSYNC_CTRL_FSYNCLEN_MASK             (0xFFFFFFFFU)
#define PDM_FSYNC_CTRL_FSYNCLEN_SHIFT            (0U)
/*! FSYNCLEN - Frame Synchronization Window Length */
#define PDM_FSYNC_CTRL_FSYNCLEN(x)               (((uint32_t)(((uint32_t)(x)) << PDM_FSYNC_CTRL_FSYNCLEN_SHIFT)) & PDM_FSYNC_CTRL_FSYNCLEN_MASK)
/*! @} */

/*! @name VERID - Version ID */
/*! @{ */

#define PDM_VERID_FEATURE_MASK                   (0xFFFFU)
#define PDM_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number */
#define PDM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << PDM_VERID_FEATURE_SHIFT)) & PDM_VERID_FEATURE_MASK)

#define PDM_VERID_MINOR_MASK                     (0xFF0000U)
#define PDM_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define PDM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_VERID_MINOR_SHIFT)) & PDM_VERID_MINOR_MASK)

#define PDM_VERID_MAJOR_MASK                     (0xFF000000U)
#define PDM_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define PDM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_VERID_MAJOR_SHIFT)) & PDM_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define PDM_PARAM_NPAIR_MASK                     (0xFU)
#define PDM_PARAM_NPAIR_SHIFT                    (0U)
/*! NPAIR - Number of Microphone Pairs
 *  0b0000..None
 *  0b0001..1 pair
 *  0b0010..2 pairs
 *  0b0011-0b1110.....
 *  0b1111..15 pairs
 */
#define PDM_PARAM_NPAIR(x)                       (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_NPAIR_SHIFT)) & PDM_PARAM_NPAIR_MASK)

#define PDM_PARAM_FIFO_PTRWID_MASK               (0xF0U)
#define PDM_PARAM_FIFO_PTRWID_SHIFT              (4U)
/*! FIFO_PTRWID - FIFO Pointer Width
 *  0b0000..0 bits
 *  0b0001..1 bit
 *  0b0010..2 bits
 *  0b0011-0b1110.....
 *  0b1111..15 bits
 */
#define PDM_PARAM_FIFO_PTRWID(x)                 (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_FIFO_PTRWID_SHIFT)) & PDM_PARAM_FIFO_PTRWID_MASK)

#define PDM_PARAM_FIL_OUT_WIDTH_24B_MASK         (0x100U)
#define PDM_PARAM_FIL_OUT_WIDTH_24B_SHIFT        (8U)
/*! FIL_OUT_WIDTH_24B - Filter Output Width
 *  0b0..16 bits
 *  0b1..24 bits
 */
#define PDM_PARAM_FIL_OUT_WIDTH_24B(x)           (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_FIL_OUT_WIDTH_24B_SHIFT)) & PDM_PARAM_FIL_OUT_WIDTH_24B_MASK)

#define PDM_PARAM_LOW_POWER_MASK                 (0x200U)
#define PDM_PARAM_LOW_POWER_SHIFT                (9U)
/*! LOW_POWER - Low-Power Decimation Filter
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDM_PARAM_LOW_POWER(x)                   (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_LOW_POWER_SHIFT)) & PDM_PARAM_LOW_POWER_MASK)

#define PDM_PARAM_DC_BYPASS_MASK                 (0x400U)
#define PDM_PARAM_DC_BYPASS_SHIFT                (10U)
/*! DC_BYPASS - Input DC Remover Bypass
 *  0b0..Active
 *  0b1..Disabled
 */
#define PDM_PARAM_DC_BYPASS(x)                   (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_DC_BYPASS_SHIFT)) & PDM_PARAM_DC_BYPASS_MASK)

#define PDM_PARAM_DC_OUT_BYPASS_MASK             (0x800U)
#define PDM_PARAM_DC_OUT_BYPASS_SHIFT            (11U)
/*! DC_OUT_BYPASS - Output DC Remover Bypass
 *  0b0..Active
 *  0b1..Disabled
 */
#define PDM_PARAM_DC_OUT_BYPASS(x)               (((uint32_t)(((uint32_t)(x)) << PDM_PARAM_DC_OUT_BYPASS_SHIFT)) & PDM_PARAM_DC_OUT_BYPASS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PDM_Register_Masks */


/*!
 * @}
 */ /* end of group PDM_Peripheral_Access_Layer */


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


#endif  /* PERI_PDM_H_ */


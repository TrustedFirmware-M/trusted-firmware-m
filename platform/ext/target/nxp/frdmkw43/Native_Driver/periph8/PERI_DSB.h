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
**         CMSIS Peripheral Access Layer for DSB
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
 * @file PERI_DSB.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for DSB
 *
 * CMSIS Peripheral Access Layer for DSB
 */

#if !defined(PERI_DSB_H_)
#define PERI_DSB_H_                              /**< Symbol preventing repeated inclusion */

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
   -- DSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSB_Peripheral_Access_Layer DSB Peripheral Access Layer
 * @{
 */

/** DSB - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Control, offset: 0x0 */
  __IO uint32_t INT;                               /**< Interrupt Request Status, offset: 0x4 */
  __IO uint32_t WMC;                               /**< Watermark Configuration, offset: 0x8 */
  __I  uint32_t RDATA;                             /**< FIFO Read Data, offset: 0xC */
  __IO uint32_t DADDR;                             /**< DMA Destination Address, offset: 0x10 */
  __IO uint32_t XCR;                               /**< DMA Transfer Count, offset: 0x14 */
} DSB_Type;

/* ----------------------------------------------------------------------------
   -- DSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSB_Register_Masks DSB Register Masks
 * @{
 */

/*! @name CSR - Control */
/*! @{ */

#define DSB_CSR_SFTRST_MASK                      (0x1U)
#define DSB_CSR_SFTRST_SHIFT                     (0U)
/*! SFTRST - Soft Reset
 *  0b0..No operation
 *  0b1..Resets DSB
 */
#define DSB_CSR_SFTRST(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_SFTRST_SHIFT)) & DSB_CSR_SFTRST_MASK)

#define DSB_CSR_DSB_EN_MASK                      (0x2U)
#define DSB_CSR_DSB_EN_SHIFT                     (1U)
/*! DSB_EN - DSB Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DSB_CSR_DSB_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_DSB_EN_SHIFT)) & DSB_CSR_DSB_EN_MASK)

#define DSB_CSR_DMA_EN_MASK                      (0x4U)
#define DSB_CSR_DMA_EN_SHIFT                     (2U)
/*! DMA_EN - DMA Transfer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DSB_CSR_DMA_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_DMA_EN_SHIFT)) & DSB_CSR_DMA_EN_MASK)

#define DSB_CSR_INT_EN_MASK                      (0x8U)
#define DSB_CSR_INT_EN_SHIFT                     (3U)
/*! INT_EN - Interrupt Request Enable
 *  0b0..Interrupt requests disabled
 *  0b1..Interrupt requests enabled
 */
#define DSB_CSR_INT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_INT_EN_SHIFT)) & DSB_CSR_INT_EN_MASK)

#define DSB_CSR_ERR_EN_MASK                      (0x10U)
#define DSB_CSR_ERR_EN_SHIFT                     (4U)
/*! ERR_EN - Error Interrupt Request Enable
 *  0b0..Error interrupt requests disabled
 *  0b1..Error interrupt requests enabled
 */
#define DSB_CSR_ERR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_ERR_EN_SHIFT)) & DSB_CSR_ERR_EN_MASK)

#define DSB_CSR_CBT_EN_MASK                      (0x20U)
#define DSB_CSR_CBT_EN_SHIFT                     (5U)
/*! CBT_EN - Continuous Burst Transfer Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DSB_CSR_CBT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_CBT_EN_SHIFT)) & DSB_CSR_CBT_EN_MASK)
/*! @} */

/*! @name INT - Interrupt Request Status */
/*! @{ */

#define DSB_INT_DRDY_MASK                        (0x1U)
#define DSB_INT_DRDY_SHIFT                       (0U)
/*! DRDY - Data Ready
 *  0b0..No data to read (watermark has not been reached)
 *  0b1..Data is ready to read (watermark has been reached)
 */
#define DSB_INT_DRDY(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_DRDY_SHIFT)) & DSB_INT_DRDY_MASK)

#define DSB_INT_OVRF_MASK                        (0x2U)
#define DSB_INT_OVRF_SHIFT                       (1U)
/*! OVRF - Overflow Error
 *  0b0..No overflow error
 *  0b1..The last recorded error is a buffer overflow
 */
#define DSB_INT_OVRF(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_OVRF_SHIFT)) & DSB_INT_OVRF_MASK)

#define DSB_INT_UNDR_MASK                        (0x4U)
#define DSB_INT_UNDR_SHIFT                       (2U)
/*! UNDR - Underrun Error
 *  0b0..No underrun error
 *  0b1..The last recorded error is an underrun on a read
 */
#define DSB_INT_UNDR(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_UNDR_SHIFT)) & DSB_INT_UNDR_MASK)

#define DSB_INT_DBE_MASK                         (0x8U)
#define DSB_INT_DBE_SHIFT                        (3U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error is bus error on a write
 */
#define DSB_INT_DBE(x)                           (((uint32_t)(((uint32_t)(x)) << DSB_INT_DBE_SHIFT)) & DSB_INT_DBE_MASK)

#define DSB_INT_DONE_MASK                        (0x10U)
#define DSB_INT_DONE_SHIFT                       (4U)
/*! DONE - DMA Packet Transfer Complete
 *  0b0..Packet transfer not done; CCNT less than TCNT
 *  0b1..Packet transfer is done; TCNT 32-bit words transferred
 */
#define DSB_INT_DONE(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_DONE_SHIFT)) & DSB_INT_DONE_MASK)
/*! @} */

/*! @name WMC - Watermark Configuration */
/*! @{ */

#define DSB_WMC_WMRK_MASK                        (0xFU)
#define DSB_WMC_WMRK_SHIFT                       (0U)
/*! WMRK - Watermark
 *  0b0000..Disables
 *  0b0001..Enables
 */
#define DSB_WMC_WMRK(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_WMC_WMRK_SHIFT)) & DSB_WMC_WMRK_MASK)

#define DSB_WMC_CNT_MASK                         (0x1F0000U)
#define DSB_WMC_CNT_SHIFT                        (16U)
/*! CNT - FIFO Count */
#define DSB_WMC_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << DSB_WMC_CNT_SHIFT)) & DSB_WMC_CNT_MASK)

#define DSB_WMC_SIZE_MASK                        (0x1F000000U)
#define DSB_WMC_SIZE_SHIFT                       (24U)
/*! SIZE - FIFO size */
#define DSB_WMC_SIZE(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_WMC_SIZE_SHIFT)) & DSB_WMC_SIZE_MASK)
/*! @} */

/*! @name RDATA - FIFO Read Data */
/*! @{ */

#define DSB_RDATA_DATA_MASK                      (0xFFFFFFFFU)
#define DSB_RDATA_DATA_SHIFT                     (0U)
/*! DATA - FIFO Data */
#define DSB_RDATA_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_RDATA_DATA_SHIFT)) & DSB_RDATA_DATA_MASK)
/*! @} */

/*! @name DADDR - DMA Destination Address */
/*! @{ */

#define DSB_DADDR_DADDR_MASK                     (0xFFFFFFFFU)
#define DSB_DADDR_DADDR_SHIFT                    (0U)
/*! DADDR - Destination Address */
#define DSB_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x)) << DSB_DADDR_DADDR_SHIFT)) & DSB_DADDR_DADDR_MASK)
/*! @} */

/*! @name XCR - DMA Transfer Count */
/*! @{ */

#define DSB_XCR_TCNT_MASK                        (0xFFFFU)
#define DSB_XCR_TCNT_SHIFT                       (0U)
/*! TCNT - Total Transfer Count */
#define DSB_XCR_TCNT(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_XCR_TCNT_SHIFT)) & DSB_XCR_TCNT_MASK)

#define DSB_XCR_CCNT_MASK                        (0xFFFF0000U)
#define DSB_XCR_CCNT_SHIFT                       (16U)
/*! CCNT - Current Transfer Count */
#define DSB_XCR_CCNT(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_XCR_CCNT_SHIFT)) & DSB_XCR_CCNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSB_Register_Masks */


/*!
 * @}
 */ /* end of group DSB_Peripheral_Access_Layer */


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


#endif  /* PERI_DSB_H_ */


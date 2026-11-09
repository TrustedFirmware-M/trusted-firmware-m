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
**         CMSIS Peripheral Access Layer for DMA
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
 * @file PERI_DMA.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

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
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(DMA_REQUEST_SOURCE_T_)
#define DMA_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA hardware request
 *
 * Defines the enumeration for the DMA hardware request collections.
 */

typedef enum _dma_request_source
{
    kDmaRequestDisabled             = 0U,          /**< Disabled */
    kDmaRequestWUU0                 = 1U,          /**< WUU0 Wake up event */
    kDmaRequestReserved2            = 2U,          /**< Reserved */
    kDmaRequestLPTMR0               = 3U,          /**< LPTMR0 Counter match event */
    kDmaRequestLPTMR1               = 4U,          /**< LPTMR1 Counter match event */
    kDmaRequestTPM0Channel0         = 5U,          /**< TPM0 Channel 0 request */
    kDmaRequestTPM0Channel1         = 6U,          /**< TPM0 Channel 1 request */
    kDmaRequestTPM0Channel2         = 7U,          /**< TPM0 Channel 2 request */
    kDmaRequestTPM0Channel3         = 8U,          /**< TPM0 Channel 3 request */
    kDmaRequestTPM0Channel4         = 9U,          /**< TPM0 Channel 4 request */
    kDmaRequestTPM0Channel5         = 10U,         /**< TPM0 Channel 5 request */
    kDmaRequestTPM0Overflow         = 11U,         /**< TPM0 Counter overflow request */
    kDmaRequestTPM2Channel0         = 12U,         /**< TPM2 Channel 0 request */
    kDmaRequestTPM2Channel1         = 13U,         /**< TPM2 Channel 1 request */
    kDmaRequestSGI0In               = 14U,         /**< SGI0 input request */
    kDmaRequestSGI0Out              = 15U,         /**< SGI0 output request */
    kDmaRequestReserved16           = 16U,         /**< Reserved */
    kDmaRequestReserved17           = 17U,         /**< Reserved */
    kDmaRequestTPM2Overflow         = 18U,         /**< TPM2 Counter overflow request */
    kDmaRequestRFInputData          = 19U,         /**< Radio Bric Input data request */
    kDmaRequestRFOutputData         = 20U,         /**< Radio Bric Output data request */
    kDmaRequestLPI2C0Rx             = 21U,         /**< LPI2C0 Master / Slave receive request */
    kDmaRequestLPI2C0Tx             = 22U,         /**< LPI2C0 Master / Slave transmit request */
    kDmaRequestLPI2C1Rx             = 23U,         /**< LPI2C1 Master / Slave receive request */
    kDmaRequestLPI2C1Tx             = 24U,         /**< LPI2C1 Master / Slave transmit request */
    kDmaRequestLPSPI0Rx             = 25U,         /**< LPSPI0 Master / Slave receive request */
    kDmaRequestLPSPI0Tx             = 26U,         /**< LPSPI0 Master / Slave transmit request */
    kDmaRequestLPSPI1Rx             = 27U,         /**< LPSPI1 Master / Slave receive request */
    kDmaRequestLPSPI1Tx             = 28U,         /**< LPSPI1 Master / Slave transmit request */
    kDmaRequestLPSPI2Rx             = 29U,         /**< LPSPI2 Master / Slave receive request */
    kDmaRequestLPSPI2Tx             = 30U,         /**< LPSPI2 Master / Slave transmit request */
    kDmaRequestLPUART0Rx            = 31U,         /**< LPUART0 receive request */
    kDmaRequestLPUART0Tx            = 32U,         /**< LPUART0 transmit request */
    kDmaRequestLPUART1Rx            = 33U,         /**< LPUART1 receive request */
    kDmaRequestLPUART1Tx            = 34U,         /**< LPUART1 transmit request */
    kDmaRequestTPM1Channel0         = 35U,         /**< TPM1 Channel 0 request */
    kDmaRequestTPM1Channel1         = 36U,         /**< TPM1 Channel 1 request */
    kDmaRequestTPM1Overflow         = 37U,         /**< TPM1 Counter overflow request */
    kDmaRequestTPM3Channel0         = 38U,         /**< TPM3 Channel 0 request */
    kDmaRequestTPM3Channel1         = 39U,         /**< TPM3 Channel 1 request */
    kDmaRequestTPM3Overflow         = 40U,         /**< TPM3 Counter overflow request */
    kDmaRequestTPM4Channel0         = 41U,         /**< TPM4 Channel 0 request */
    kDmaRequestTPM4Channel1         = 42U,         /**< TPM4 Channel 1 request */
    kDmaRequestTPM4Overflow         = 43U,         /**< TPM4 Counter overflow request */
    kDmaRequestCAN0                 = 44U,         /**< CAN0 DMA request */
    kDmaRequestGPIOAPinEvent0       = 45U,         /**< GPIOA Pin event request 0 */
    kDmaRequestGPIOAPinEvent1       = 46U,         /**< GPIOA Pin event request 1 */
    kDmaRequestGPIOBPinEvent0       = 47U,         /**< GPIOB Pin event request 0 */
    kDmaRequestGPIOBPinEvent1       = 48U,         /**< GPIOB Pin event request 1 */
    kDmaRequestGPIOCPinEvent0       = 49U,         /**< GPIOC Pin event request 0 */
    kDmaRequestGPIOCPinEvent1       = 50U,         /**< GPIOC Pin event request 1 */
    kDmaRequestGPIODPinEvent0       = 51U,         /**< GPIOD Pin event request 0 */
    kDmaRequestGPIODPinEvent1       = 52U,         /**< GPIOD Pin event request 1 */
    kDmaRequestADCFifoA             = 53U,         /**< ADC FIFO A request */
    kDmaRequestCMP0                 = 54U,         /**< CMP0 DMA request */
    kDmaRequestPWMCap0              = 55U,         /**< Read DMA request for Capture Regs */
    kDmaRequestPWMCap1              = 56U,         /**< Read DMA request for Capture Regs */
    kDmaRequestPWMCap2              = 57U,         /**< Read DMA request for Capture Regs */
    kDmaRequestPWMValue0            = 58U,         /**< Write DMA request for value Regs */
    kDmaRequestPWMValue1            = 59U,         /**< Write DMA request for value Regs */
    kDmaRequestPWMValue2            = 60U,         /**< Write DMA request for value Regs */
} dma_request_source_t;

/* @} */
#endif /* DMA_REQUEST_SOURCE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_MP_GRPRI_COUNT                        16u
#define DMA_CH_COUNT                              16u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT;                            /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t MP_HRS;                            /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_MP_GRPRI_COUNT];      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[3776];
  struct {                                         /* offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x1004, array step: 0x1000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x1008, array step: 0x1000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x100C, array step: 0x1000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x1010, array step: 0x1000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x1014, array step: 0x1000 */
         uint8_t RESERVED_0[8];
    __IO uint32_t TCD_SADDR;                         /**< TCD Source Address, array offset: 0x1020, array step: 0x1000 */
    __IO uint16_t TCD_SOFF;                          /**< TCD Signed Source Address Offset, array offset: 0x1024, array step: 0x1000 */
    __IO uint16_t TCD_ATTR;                          /**< TCD Transfer Attributes, array offset: 0x1026, array step: 0x1000 */
    union {                                          /* offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFNO;                /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFYES;               /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
    };
    __IO uint32_t TCD_SLAST_SDA;                     /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x102C, array step: 0x1000 */
    __IO uint32_t TCD_DADDR;                         /**< TCD Destination Address, array offset: 0x1030, array step: 0x1000 */
    __IO uint16_t TCD_DOFF;                          /**< TCD Signed Destination Address Offset, array offset: 0x1034, array step: 0x1000 */
    union {                                          /* offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKNO;                 /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKYES;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1036, array step: 0x1000 */
    };
    __IO uint32_t TCD_DLAST_SGA;                     /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x1038, array step: 0x1000 */
    __IO uint16_t TCD_CSR;                           /**< TCD Control and Status, array offset: 0x103C, array step: 0x1000 */
    union {                                          /* offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKNO;                 /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKYES;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x103E, array step: 0x1000 */
    };
         uint8_t RESERVED_1[4032];
  } CH[DMA_CH_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA_MP_CSR_EDBG_MASK                     (0x2U)
#define DMA_MP_CSR_EDBG_SHIFT                    (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_MP_CSR_EDBG(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_EDBG_SHIFT)) & DMA_MP_CSR_EDBG_MASK)

#define DMA_MP_CSR_ERCA_MASK                     (0x4U)
#define DMA_MP_CSR_ERCA_SHIFT                    (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_MP_CSR_ERCA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ERCA_SHIFT)) & DMA_MP_CSR_ERCA_MASK)

#define DMA_MP_CSR_HAE_MASK                      (0x10U)
#define DMA_MP_CSR_HAE_SHIFT                     (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_MP_CSR_HAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HAE_SHIFT)) & DMA_MP_CSR_HAE_MASK)

#define DMA_MP_CSR_HALT_MASK                     (0x20U)
#define DMA_MP_CSR_HALT_SHIFT                    (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_MP_CSR_HALT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HALT_SHIFT)) & DMA_MP_CSR_HALT_MASK)

#define DMA_MP_CSR_GCLC_MASK                     (0x40U)
#define DMA_MP_CSR_GCLC_SHIFT                    (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_MP_CSR_GCLC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GCLC_SHIFT)) & DMA_MP_CSR_GCLC_MASK)

#define DMA_MP_CSR_GMRC_MASK                     (0x80U)
#define DMA_MP_CSR_GMRC_SHIFT                    (7U)
/*! GMRC - Global Initiator ID Replication Control
 *  0b0..Initiator ID replication disabled for all channels
 *  0b1..Initiator ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_MP_CSR_GMRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GMRC_SHIFT)) & DMA_MP_CSR_GMRC_MASK)

#define DMA_MP_CSR_ECX_MASK                      (0x100U)
#define DMA_MP_CSR_ECX_SHIFT                     (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ECX_SHIFT)) & DMA_MP_CSR_ECX_MASK)

#define DMA_MP_CSR_CX_MASK                       (0x200U)
#define DMA_MP_CSR_CX_SHIFT                      (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_CX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_CX_SHIFT)) & DMA_MP_CSR_CX_MASK)

#define DMA_MP_CSR_ACTIVE_ID_MASK                (0xF000000U)
#define DMA_MP_CSR_ACTIVE_ID_SHIFT               (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_MP_CSR_ACTIVE_ID(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_MP_CSR_ACTIVE_ID_MASK)

#define DMA_MP_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_MP_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_MP_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_SHIFT)) & DMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                       (0x1U)
#define DMA_MP_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_MP_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DBE_SHIFT)) & DMA_MP_ES_DBE_MASK)

#define DMA_MP_ES_SBE_MASK                       (0x2U)
#define DMA_MP_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_MP_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SBE_SHIFT)) & DMA_MP_ES_SBE_MASK)

#define DMA_MP_ES_SGE_MASK                       (0x4U)
#define DMA_MP_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_MP_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SGE_SHIFT)) & DMA_MP_ES_SGE_MASK)

#define DMA_MP_ES_NCE_MASK                       (0x8U)
#define DMA_MP_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_MP_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_NCE_SHIFT)) & DMA_MP_ES_NCE_MASK)

#define DMA_MP_ES_DOE_MASK                       (0x10U)
#define DMA_MP_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_MP_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DOE_SHIFT)) & DMA_MP_ES_DOE_MASK)

#define DMA_MP_ES_DAE_MASK                       (0x20U)
#define DMA_MP_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_MP_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DAE_SHIFT)) & DMA_MP_ES_DAE_MASK)

#define DMA_MP_ES_SOE_MASK                       (0x40U)
#define DMA_MP_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_MP_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SOE_SHIFT)) & DMA_MP_ES_SOE_MASK)

#define DMA_MP_ES_SAE_MASK                       (0x80U)
#define DMA_MP_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_MP_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SAE_SHIFT)) & DMA_MP_ES_SAE_MASK)

#define DMA_MP_ES_ECX_MASK                       (0x100U)
#define DMA_MP_ES_ECX_SHIFT                      (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_MP_ES_ECX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ECX_SHIFT)) & DMA_MP_ES_ECX_MASK)

#define DMA_MP_ES_ERRCHN_MASK                    (0xF000000U)
#define DMA_MP_ES_ERRCHN_SHIFT                   (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_MP_ES_ERRCHN(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ERRCHN_SHIFT)) & DMA_MP_ES_ERRCHN_MASK)

#define DMA_MP_ES_VLD_MASK                       (0x80000000U)
#define DMA_MP_ES_VLD_SHIFT                      (31U)
/*! VLD - Valid
 *  0b0..No CHn_ES[ERR] fields are set to 1
 *  0b1..At least one CHn_ES[ERR] field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_MP_ES_VLD(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_VLD_SHIFT)) & DMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                      (0xFFFFU)
#define DMA_MP_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request Status */
#define DMA_MP_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_INT_INT_SHIFT)) & DMA_MP_INT_INT_MASK)
/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                      (0xFFFFU)
#define DMA_MP_HRS_HRS_SHIFT                     (0U)
/*! HRS - Hardware Request Status */
#define DMA_MP_HRS_HRS(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_HRS_HRS_SHIFT)) & DMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_CH_GRPRI_GRPRI_SHIFT                 (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_CH_GRPRI_GRPRI(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CH_GRPRI_GRPRI_SHIFT)) & DMA_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_CH_GRPRI */
#define DMA_CH_GRPRI_COUNT                       (16U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                      (0x1U)
#define DMA_CH_CSR_ERQ_SHIFT                     (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH_CSR_ERQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ERQ_SHIFT)) & DMA_CH_CSR_ERQ_MASK)

#define DMA_CH_CSR_EARQ_MASK                     (0x2U)
#define DMA_CH_CSR_EARQ_SHIFT                    (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH_CSR_EARQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EARQ_SHIFT)) & DMA_CH_CSR_EARQ_MASK)

#define DMA_CH_CSR_EEI_MASK                      (0x4U)
#define DMA_CH_CSR_EEI_SHIFT                     (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH_CSR_EEI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EEI_SHIFT)) & DMA_CH_CSR_EEI_MASK)

#define DMA_CH_CSR_EBW_MASK                      (0x8U)
#define DMA_CH_CSR_EBW_SHIFT                     (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH_CSR_EBW(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EBW_SHIFT)) & DMA_CH_CSR_EBW_MASK)

#define DMA_CH_CSR_DONE_MASK                     (0x40000000U)
#define DMA_CH_CSR_DONE_SHIFT                    (30U)
/*! DONE - Channel Done */
#define DMA_CH_CSR_DONE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_DONE_SHIFT)) & DMA_CH_CSR_DONE_MASK)

#define DMA_CH_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_CH_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ACTIVE_SHIFT)) & DMA_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA_CH_CSR */
#define DMA_CH_CSR_COUNT                         (16U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                       (0x1U)
#define DMA_CH_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DBE_SHIFT)) & DMA_CH_ES_DBE_MASK)

#define DMA_CH_ES_SBE_MASK                       (0x2U)
#define DMA_CH_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SBE_SHIFT)) & DMA_CH_ES_SBE_MASK)

#define DMA_CH_ES_SGE_MASK                       (0x4U)
#define DMA_CH_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SGE_SHIFT)) & DMA_CH_ES_SGE_MASK)

#define DMA_CH_ES_NCE_MASK                       (0x8U)
#define DMA_CH_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_NCE_SHIFT)) & DMA_CH_ES_NCE_MASK)

#define DMA_CH_ES_DOE_MASK                       (0x10U)
#define DMA_CH_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DOE_SHIFT)) & DMA_CH_ES_DOE_MASK)

#define DMA_CH_ES_DAE_MASK                       (0x20U)
#define DMA_CH_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DAE_SHIFT)) & DMA_CH_ES_DAE_MASK)

#define DMA_CH_ES_SOE_MASK                       (0x40U)
#define DMA_CH_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SOE_SHIFT)) & DMA_CH_ES_SOE_MASK)

#define DMA_CH_ES_SAE_MASK                       (0x80U)
#define DMA_CH_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SAE_SHIFT)) & DMA_CH_ES_SAE_MASK)

#define DMA_CH_ES_ERR_MASK                       (0x80000000U)
#define DMA_CH_ES_ERR_SHIFT                      (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH_ES_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_ERR_SHIFT)) & DMA_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA_CH_ES */
#define DMA_CH_ES_COUNT                          (16U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                      (0x1U)
#define DMA_CH_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_INT_INT_SHIFT)) & DMA_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA_CH_INT */
#define DMA_CH_INT_COUNT                         (16U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                      (0x3FU)
#define DMA_CH_SBR_MID_SHIFT                     (0U)
/*! MID - Initiator ID */
#define DMA_CH_SBR_MID(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_MID_SHIFT)) & DMA_CH_SBR_MID_MASK)

#define DMA_CH_SBR_SEC_MASK                      (0x4000U)
#define DMA_CH_SBR_SEC_SHIFT                     (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA_CH_SBR_SEC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_SEC_SHIFT)) & DMA_CH_SBR_SEC_MASK)

#define DMA_CH_SBR_PAL_MASK                      (0x8000U)
#define DMA_CH_SBR_PAL_SHIFT                     (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH_SBR_PAL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_PAL_SHIFT)) & DMA_CH_SBR_PAL_MASK)

#define DMA_CH_SBR_EMI_MASK                      (0x10000U)
#define DMA_CH_SBR_EMI_SHIFT                     (16U)
/*! EMI - Enable Initiator ID Replication
 *  0b0..Initiator ID replication is disabled
 *  0b1..Initiator ID replication is enabled
 */
#define DMA_CH_SBR_EMI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_EMI_SHIFT)) & DMA_CH_SBR_EMI_MASK)

#define DMA_CH_SBR_ATTR_MASK                     (0x1E0000U)
#define DMA_CH_SBR_ATTR_SHIFT                    (17U)
/*! ATTR - Attribute Output */
#define DMA_CH_SBR_ATTR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_ATTR_SHIFT)) & DMA_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA_CH_SBR */
#define DMA_CH_SBR_COUNT                         (16U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                      (0x7U)
#define DMA_CH_PRI_APL_SHIFT                     (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH_PRI_APL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_APL_SHIFT)) & DMA_CH_PRI_APL_MASK)

#define DMA_CH_PRI_DPA_MASK                      (0x40000000U)
#define DMA_CH_PRI_DPA_SHIFT                     (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH_PRI_DPA(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_DPA_SHIFT)) & DMA_CH_PRI_DPA_MASK)

#define DMA_CH_PRI_ECP_MASK                      (0x80000000U)
#define DMA_CH_PRI_ECP_SHIFT                     (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH_PRI_ECP(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_ECP_SHIFT)) & DMA_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA_CH_PRI */
#define DMA_CH_PRI_COUNT                         (16U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA_CH_MUX_SRC_MASK                      (0x3FU)
#define DMA_CH_MUX_SRC_SHIFT                     (0U)
/*! SRC - Service Request Source */
#define DMA_CH_MUX_SRC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_MUX_SRC_SHIFT)) & DMA_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA_CH_MUX */
#define DMA_CH_MUX_COUNT                         (16U)

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_SADDR_SADDR_SHIFT                (0U)
/*! SADDR - Source Address */
#define DMA_TCD_SADDR_SADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SADDR_SADDR_SHIFT)) & DMA_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_TCD_SADDR */
#define DMA_TCD_SADDR_COUNT                      (16U)

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK                   (0xFFFFU)
#define DMA_TCD_SOFF_SOFF_SHIFT                  (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD_SOFF_SOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_SOFF_SOFF_SHIFT)) & DMA_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_TCD_SOFF */
#define DMA_TCD_SOFF_COUNT                       (16U)

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK                  (0x7U)
#define DMA_TCD_ATTR_DSIZE_SHIFT                 (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD_ATTR_DSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DSIZE_SHIFT)) & DMA_TCD_ATTR_DSIZE_MASK)

#define DMA_TCD_ATTR_DMOD_MASK                   (0xF8U)
#define DMA_TCD_ATTR_DMOD_SHIFT                  (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD_ATTR_DMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DMOD_SHIFT)) & DMA_TCD_ATTR_DMOD_MASK)

#define DMA_TCD_ATTR_SSIZE_MASK                  (0x700U)
#define DMA_TCD_ATTR_SSIZE_SHIFT                 (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..
 *  0b111..
 */
#define DMA_TCD_ATTR_SSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SSIZE_SHIFT)) & DMA_TCD_ATTR_SSIZE_MASK)

#define DMA_TCD_ATTR_SMOD_MASK                   (0xF800U)
#define DMA_TCD_ATTR_SMOD_SHIFT                  (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 */
#define DMA_TCD_ATTR_SMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SMOD_SHIFT)) & DMA_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_TCD_ATTR */
#define DMA_TCD_ATTR_COUNT                       (16U)

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK       (0x3FFFFFFFU)
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT      (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK        (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT       (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK        (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT       (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFNO */
#define DMA_TCD_NBYTES_MLOFFNO_COUNT             (16U)

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK      (0x3FFU)
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT     (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK       (0x3FFFFC00U)
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT      (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK       (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT      (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK       (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT      (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFYES */
#define DMA_TCD_NBYTES_MLOFFYES_COUNT            (16U)

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT        (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA_TCD_SLAST_SDA */
#define DMA_TCD_SLAST_SDA_COUNT                  (16U)

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_DADDR_DADDR_SHIFT                (0U)
/*! DADDR - Destination Address */
#define DMA_TCD_DADDR_DADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DADDR_DADDR_SHIFT)) & DMA_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_TCD_DADDR */
#define DMA_TCD_DADDR_COUNT                      (16U)

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK                   (0xFFFFU)
#define DMA_TCD_DOFF_DOFF_SHIFT                  (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD_DOFF_DOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_DOFF_DOFF_SHIFT)) & DMA_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_TCD_DOFF */
#define DMA_TCD_DOFF_COUNT                       (16U)

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK         (0x7FFFU)
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT        (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKNO_CITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKNO */
#define DMA_TCD_CITER_ELINKNO_COUNT              (16U)

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK        (0x1FFU)
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT       (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKYES_CITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK       (0x1E00U)
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKYES */
#define DMA_TCD_CITER_ELINKYES_COUNT             (16U)

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT        (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA_TCD_DLAST_SGA */
#define DMA_TCD_DLAST_SGA_COUNT                  (16U)

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK                   (0x1U)
#define DMA_TCD_CSR_START_SHIFT                  (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD_CSR_START(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_START_SHIFT)) & DMA_TCD_CSR_START_MASK)

#define DMA_TCD_CSR_INTMAJOR_MASK                (0x2U)
#define DMA_TCD_CSR_INTMAJOR_SHIFT               (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD_CSR_INTMAJOR(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTMAJOR_SHIFT)) & DMA_TCD_CSR_INTMAJOR_MASK)

#define DMA_TCD_CSR_INTHALF_MASK                 (0x4U)
#define DMA_TCD_CSR_INTHALF_SHIFT                (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD_CSR_INTHALF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTHALF_SHIFT)) & DMA_TCD_CSR_INTHALF_MASK)

#define DMA_TCD_CSR_DREQ_MASK                    (0x8U)
#define DMA_TCD_CSR_DREQ_SHIFT                   (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD_CSR_DREQ(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_DREQ_SHIFT)) & DMA_TCD_CSR_DREQ_MASK)

#define DMA_TCD_CSR_ESG_MASK                     (0x10U)
#define DMA_TCD_CSR_ESG_SHIFT                    (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD_CSR_ESG(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESG_SHIFT)) & DMA_TCD_CSR_ESG_MASK)

#define DMA_TCD_CSR_MAJORELINK_MASK              (0x20U)
#define DMA_TCD_CSR_MAJORELINK_SHIFT             (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CSR_MAJORELINK(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORELINK_SHIFT)) & DMA_TCD_CSR_MAJORELINK_MASK)

#define DMA_TCD_CSR_EEOP_MASK                    (0x40U)
#define DMA_TCD_CSR_EEOP_SHIFT                   (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD_CSR_EEOP(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_EEOP_SHIFT)) & DMA_TCD_CSR_EEOP_MASK)

#define DMA_TCD_CSR_ESDA_MASK                    (0x80U)
#define DMA_TCD_CSR_ESDA_SHIFT                   (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD_CSR_ESDA(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESDA_SHIFT)) & DMA_TCD_CSR_ESDA_MASK)

#define DMA_TCD_CSR_MAJORLINKCH_MASK             (0xF00U)
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT            (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD_CSR_MAJORLINKCH(x)               (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD_CSR_MAJORLINKCH_MASK)

#define DMA_TCD_CSR_BWC_MASK                     (0xC000U)
#define DMA_TCD_CSR_BWC_SHIFT                    (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD_CSR_BWC(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_BWC_SHIFT)) & DMA_TCD_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_TCD_CSR */
#define DMA_TCD_CSR_COUNT                        (16U)

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK         (0x7FFFU)
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT        (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKNO_BITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKNO */
#define DMA_TCD_BITER_ELINKNO_COUNT              (16U)

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK        (0x1FFU)
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT       (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKYES_BITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK       (0x1E00U)
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKYES */
#define DMA_TCD_BITER_ELINKYES_COUNT             (16U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */



/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */


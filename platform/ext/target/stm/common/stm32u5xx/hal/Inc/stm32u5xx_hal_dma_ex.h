/**
  **********************************************************************************************************************
  * @file    stm32u5xx_hal_dma_ex.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL extension module.
  **********************************************************************************************************************
  * @attention
  *
  * Copyright (c) 2021 - 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  **********************************************************************************************************************
  */

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef STM32U5xx_HAL_DMA_EX_H
#define STM32U5xx_HAL_DMA_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "stm32u5xx_hal_def.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @addtogroup DMAEx
  * @{
  */

/* Exported types ----------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Types DMAEx Exported Types
  * @brief DMAEx Exported types
  * @{
  */

/**
  * @brief DMAEx Data Handling Configuration Structure Definition.
  */
typedef struct
{
  uint32_t DataExchange;  /*!< Specifies the DMA channel data exchange mode.
                               This parameter can be a value of @ref DMAEx_Data_Exchange  */

  uint32_t DataAlignment; /*!< Specifies the DMA channel data padding and alignment mode
                               This parameter can be a value of @ref DMAEx_Data_Alignment */

} DMA_DataHandlingConfTypeDef;

/**
  * @brief DMAEx Trigger Configuration Structure Definition.
  */
typedef struct
{
  uint32_t TriggerMode;      /*!< Specifies the DMA channel trigger mode.
                                  This parameter can be a value of @ref DMAEx_Trigger_Mode      */

  uint32_t TriggerPolarity;  /*!< Specifies the DMA channel trigger event polarity.
                                  This parameter can be a value of @ref DMAEx_Trigger_Polarity  */

  uint32_t TriggerSelection; /*!< Specifies the DMA channel trigger event selection.
                                  This parameter can be a value of @ref DMAEx_Trigger_Selection */

} DMA_TriggerConfTypeDef;

/**
  * @brief DMAEx Repeated Block Configuration Structure Definition.
  */
typedef struct
{
  uint32_t RepeatCount;      /*!< Specifies the DMA channel repeat count (the number of repetitions of block).
                                  This parameter can be a value between 1 and 2048                                    */

  int32_t SrcAddrOffset;     /*!< Specifies the DMA channel single/burst source address offset :
                                  This parameter can be a value between -8191 and 8191.
                                  * If source address offset > 0 => Increment the source address by offset from where
                                    the last single/burst transfer ends.
                                  * If source address offset < 0 => Decrement the source address by offset from where
                                    the last single/burst transfer ends.
                                  * If source address offset == 0 => The next single/burst source address starts from
                                    where the last transfer ends                                                      */

  int32_t DestAddrOffset;    /*!< Specifies the DMA channel single/burst destination address offset signed value :
                                  This parameter can be a value between -8191 and 8191.
                                  * If destination address offset > 0 => Increment the destination address by offset
                                    from where the last single/burst transfer ends.
                                  * If destination address offset < 0 => Decrement the destination address by offset
                                    from where the last single/burst transfer ends.
                                  * If destination address offset == 0 => The next single/burst destination address
                                    starts from where the last transfer ends.                                         */

  int32_t BlkSrcAddrOffset;  /*!< Specifies the DMA channel block source address offset signed value :
                                  This parameter can be a value between -65535 and 65535.
                                  * If block source address offset > 0 => Increment the block source address by offset
                                    from where the last block ends.
                                  * If block source address offset < 0 => Decrement the next block source address by
                                    offset from where the last block ends.
                                  * If block source address offset == 0 =>  the next block source address starts from
                                    where the last block ends                                                         */

  int32_t BlkDestAddrOffset; /*!< Specifies the DMA channel block destination address offset signed value :
                                  This parameter can be a value between -65535 and 65535.
                                  * If block destination address offset > 0 => Increment the block destination address
                                    by offset from where the last block ends.
                                  * If block destination address offset < 0 => Decrement the next block destination
                                    address by offset from where the last block ends.
                                  * If block destination address offset == 0 =>  the next block destination address
                                    starts from where the last block ends                                             */

} DMA_RepeatBlockConfTypeDef;

/**
  * @brief DMAEx Queue State Enumeration Definition.
  */
typedef enum
{
  HAL_DMA_QUEUE_STATE_RESET = 0x00U, /*!< DMA queue empty              */
  HAL_DMA_QUEUE_STATE_READY = 0x01U, /*!< DMA queue ready for use      */
  HAL_DMA_QUEUE_STATE_BUSY  = 0x02U  /*!< DMA queue execution on going */

} HAL_DMA_QStateTypeDef;

/**
  * @brief  DMAEx Linked-List Node Configuration Structure Definition.
  */
typedef struct
{
  uint32_t                    NodeType;           /*!< Specifies the DMA channel node type.
                                                       This parameter can be a value of @ref DMAEx_Node_Type          */

  DMA_InitTypeDef             Init;               /*!< Specifies the DMA channel basic configuration                  */

  DMA_DataHandlingConfTypeDef DataHandlingConfig; /*!< Specifies the DMA channel data handling channel configuration  */

  DMA_TriggerConfTypeDef      TriggerConfig;      /*!< Specifies the DMA channel trigger configuration                */

  DMA_RepeatBlockConfTypeDef  RepeatBlockConfig;  /*!< Specifies the DMA channel repeated block configuration         */

  uint32_t                    SrcAddress;         /*!< Specifies the source memory address                            */
  uint32_t                    DstAddress;         /*!< Specifies the destination memory address                       */
  uint32_t                    DataSize;           /*!< Specifies the source data size in bytes                        */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  uint32_t                    SrcSecure;          /*!< Specifies the source security attribute                        */
  uint32_t                    DestSecure;         /*!< Specifies the destination security attribute                   */
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

} DMA_NodeConfTypeDef;

/**
  * @brief  DMAEx Linked-List Node Structure Definition.
  */
typedef struct
{
  uint32_t LinkRegisters[8U]; /*!< Physical Node register description */
  uint32_t NodeInfo;          /*!< Node information                   */

} DMA_NodeTypeDef;

/**
  * @brief DMAEx Linked-List Queue Structure Definition.
  */
typedef struct __DMA_QListTypeDef
{
  DMA_NodeTypeDef                *Head;              /*!< Specifies the queue head node                    */

  DMA_NodeTypeDef                *FirstCircularNode; /*!< Specifies the queue first circular node          */

  uint32_t                       NodeNumber;         /*!< Specifies the queue node number                  */

  __IO HAL_DMA_QStateTypeDef     State;              /*!< Specifies the queue state                        */

  __IO uint32_t                  ErrorCode;          /*!< Specifies the queue error code                   */

  __IO uint32_t                  Type;               /*!< Specifies whether the queue is static or dynamic */

} DMA_QListTypeDef;
/**
  * @}
  */

/* Exported constants ------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Constants DMAEx Exported Constants
  * @brief    DMAEx Exported Constants
  * @{
  */

/** @defgroup Queue_Error_Codes Queue Error Codes
  * @brief    Queue Error Codes
  * @{
  */
#define HAL_DMA_QUEUE_ERROR_NONE        (0x00U) /*!< No error                                                */
#define HAL_DMA_QUEUE_ERROR_BUSY        (0x01U) /*!< Error busy                                              */
#define HAL_DMA_QUEUE_ERROR_EMPTY       (0x02U) /*!< Error unallowed operation for empty queue               */
#define HAL_DMA_QUEUE_ERROR_UNSUPPORTED (0x03U) /*!< Error unsupported feature                               */
#define HAL_DMA_QUEUE_ERROR_INVALIDTYPE (0x04U) /*!< Error incompatible node type or circular initialization
                                                     and queue circular types are incompatible               */
#define HAL_DMA_QUEUE_ERROR_OUTOFRANGE  (0x05U) /*!< Error out of range node memory                          */
#define HAL_DMA_QUEUE_ERROR_NOTFOUND    (0x06U) /*!< Error node not found in queue                           */
/**
  * @}
  */

/** @defgroup DMAEx_LinkedList_Mode DMAEx LinkedList Mode
  * @brief    DMAEx LinkedList Mode
  * @{
  */
#define DMA_LINKEDLIST_NORMAL   DMA_LINKEDLIST             /*!< Linear linked-list DMA channel transfer   */
#define DMA_LINKEDLIST_CIRCULAR (DMA_LINKEDLIST | (0x01U)) /*!< Circular linked-list DMA channel transfer */
/**
  * @}
  */

/** @defgroup DMAEx_Data_Alignment DMAEx Data Alignment
  * @brief    DMAEx Data Alignment
  * @{
  */
#define DMA_DATA_RIGHTALIGN_ZEROPADDED 0x00000000U    /*!< If source data width < destination data width
                                                           => Right aligned padded with 0 up to destination data
                                                              width                                              */
#define DMA_DATA_RIGHTALIGN_LEFTTRUNC  0x00000000U    /*!< If source data width > destination data width
                                                           => Right aligned left Truncated down to destination
                                                              data width                                         */
#define DMA_DATA_RIGHTALIGN_SIGNEXT    DMA_CTR1_PAM_0 /*!< If source data width < destination data width
                                                           => Right Aligned padded with sign extended up to
                                                              destination data width                             */
#define DMA_DATA_LEFTALIGN_RIGHTTRUNC  DMA_CTR1_PAM_0 /*!< If source data width > destination data width
                                                           => Left Aligned Right Truncated down to the
                                                              destination data width                             */
#define DMA_DATA_PACK                  DMA_CTR1_PAM_1 /*!< If source data width < destination data width
                                                           => Packed at the destination data width
                                                              (Not available on LPDMA)                           */
#define DMA_DATA_UNPACK                DMA_CTR1_PAM_1 /*!< If source data width > destination data width
                                                           => Unpacked at the destination data width
                                                              (Not available on LPDMA)                           */
/**
  * @}
  */

/** @defgroup DMAEx_Data_Exchange DMAEx Data Exchange
  * @brief    DMAEx Data Exchange
  * @{
  */
#define DMA_EXCHANGE_NONE          0x00000000U  /*!< No data exchange                                                          */
#define DMA_EXCHANGE_DEST_BYTE     DMA_CTR1_DBX /*!< Destination Byte exchange when destination data width is > Byte           */
#define DMA_EXCHANGE_DEST_HALFWORD DMA_CTR1_DHX /*!< Destination Half-Word exchange when destination data width is > Half-Word */
#define DMA_EXCHANGE_SRC_BYTE      DMA_CTR1_SBX /*!< Source Byte endianness exchange when source data width is word            */
/**
  * @}
  */

/** @defgroup DMAEx_Trigger_Polarity DMAEx Trigger Polarity
  * @brief    DMAEx Trigger Polarity
  * @{
  */
#define DMA_TRIG_POLARITY_MASKED  0x00000000U        /*!< No trigger of the selected DMA request. Masked trigger event                                */
#define DMA_TRIG_POLARITY_RISING  DMA_CTR2_TRIGPOL_0 /*!< Trigger of the selected DMA request on the rising edge of the selected trigger event input  */
#define DMA_TRIG_POLARITY_FALLING DMA_CTR2_TRIGPOL_1 /*!< Trigger of the selected DMA request on the falling edge of the selected trigger event input */
/**
  * @}
  */

/** @defgroup DMAEx_Trigger_Mode DMAEx Trigger Mode
  * @brief    DMAEx Trigger Mode
  * @{
  */
#define DMA_TRIGM_BLOCK_TRANSFER          0x00000000U      /*!< A block transfer is conditioned by (at least) one hit trigger          */
#define DMA_TRIGM_REPEATED_BLOCK_TRANSFER DMA_CTR2_TRIGM_0 /*!< A repeated block transfer is conditioned by (at least) one hit trigger */
#define DMA_TRIGM_LLI_LINK_TRANSFER       DMA_CTR2_TRIGM_1 /*!< A LLI link transfer is conditioned by (at least) one hit trigger       */
#define DMA_TRIGM_SINGLE_BURST_TRANSFER   DMA_CTR2_TRIGM   /*!< A single/burst transfer is conditioned by (at least) one hit trigger   */
/**
  * @}
  */

/** @defgroup DMAEx_Trigger_Selection DMAEx Trigger Selection
  * @brief    DMAEx Trigger Selection
  * @{
  */
/* GPDMA1 triggers */
#define GPDMA1_TRIGGER_EXTI_LINE0         0U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE0      */
#define GPDMA1_TRIGGER_EXTI_LINE1         1U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE1      */
#define GPDMA1_TRIGGER_EXTI_LINE2         2U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE2      */
#define GPDMA1_TRIGGER_EXTI_LINE3         3U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE3      */
#define GPDMA1_TRIGGER_EXTI_LINE4         4U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE4      */
#define GPDMA1_TRIGGER_EXTI_LINE5         5U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE5      */
#define GPDMA1_TRIGGER_EXTI_LINE6         6U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE6      */
#define GPDMA1_TRIGGER_EXTI_LINE7         7U    /*!< GPDMA1 HW Trigger signal is EXTI_LINE7      */
#define GPDMA1_TRIGGER_TAMP_TRG1          8U    /*!< GPDMA1 HW Trigger signal is TAMP_TRG1       */
#define GPDMA1_TRIGGER_TAMP_TRG2          9U    /*!< GPDMA1 HW Trigger signal is TAMP_TRG2       */
#define GPDMA1_TRIGGER_TAMP_TRG3          10U   /*!< GPDMA1 HW Trigger signal is TAMP_TRG3       */
#define GPDMA1_TRIGGER_LPTIM1_CH1         11U   /*!< GPDMA1 HW Trigger signal is LPTIM1_CH1      */
#define GPDMA1_TRIGGER_LPTIM1_CH2         12U   /*!< GPDMA1 HW Trigger signal is LPTIM1_CH2      */
#define GPDMA1_TRIGGER_LPTIM2_CH1         13U   /*!< GPDMA1 HW Trigger signal is LPTIM2_CH1      */
#define GPDMA1_TRIGGER_LPTIM2_CH2         14U   /*!< GPDMA1 HW Trigger signal is LPTIM2_CH2      */
#define GPDMA1_TRIGGER_LPTIM4_OUT         15U   /*!< GPDMA1 HW Trigger signal is LPTIM4_OUT      */
#define GPDMA1_TRIGGER_COMP1_OUT          16U   /*!< GPDMA1 HW Trigger signal is COMP1_OUT       */
#if defined(COMP2)
#define GPDMA1_TRIGGER_COMP2_OUT          17U   /*!< GPDMA1 HW Trigger signal is COMP2_OUT       */
#endif /* COMP2 */
#define GPDMA1_TRIGGER_RTC_ALRA_TRG       18U   /*!< GPDMA1 HW Trigger signal is RTC_ALRA_TRG    */
#define GPDMA1_TRIGGER_RTC_ALRB_TRG       19U   /*!< GPDMA1 HW Trigger signal is RTC_ALRB_TRG    */
#define GPDMA1_TRIGGER_RTC_WUT_TRG        20U   /*!< GPDMA1 HW Trigger signal is RTC_WUT_TRG     */
#define GPDMA1_TRIGGER_GPDMA1_CH0_TCF     22U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH0_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH1_TCF     23U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH1_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH2_TCF     24U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH2_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH3_TCF     25U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH3_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH4_TCF     26U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH4_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH5_TCF     27U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH5_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH6_TCF     28U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH6_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH7_TCF     29U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH7_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH8_TCF     30U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH8_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH9_TCF     31U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH9_TCF  */
#define GPDMA1_TRIGGER_GPDMA1_CH10_TCF    32U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH10_TCF */
#define GPDMA1_TRIGGER_GPDMA1_CH11_TCF    33U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH11_TCF */
#define GPDMA1_TRIGGER_GPDMA1_CH12_TCF    34U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH12_TCF */
#define GPDMA1_TRIGGER_GPDMA1_CH13_TCF    35U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH13_TCF */
#define GPDMA1_TRIGGER_GPDMA1_CH14_TCF    36U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH14_TCF */
#define GPDMA1_TRIGGER_GPDMA1_CH15_TCF    37U   /*!< GPDMA1 HW Trigger signal is GPDMA1_CH15_TCF */
#define GPDMA1_TRIGGER_LPDMA1_CH0_TCF     38U   /*!< GPDMA1 HW Trigger signal is LPDMA1_CH0_TCF  */
#define GPDMA1_TRIGGER_LPDMA1_CH1_TCF     39U   /*!< GPDMA1 HW Trigger signal is LPDMA1_CH1_TCF  */
#define GPDMA1_TRIGGER_LPDMA1_CH2_TCF     40U   /*!< GPDMA1 HW Trigger signal is LPDMA1_CH2_TCF  */
#define GPDMA1_TRIGGER_LPDMA1_CH3_TCF     41U   /*!< GPDMA1 HW Trigger signal is LPDMA1_CH3_TCF  */
#define GPDMA1_TRIGGER_TIM2_TRGO          42U   /*!< GPDMA1 HW Trigger signal is TIM2_TRGO       */
#define GPDMA1_TRIGGER_TIM15_TRGO         43U   /*!< GPDMA1 HW Trigger signal is TIM15_TRGO      */
#if defined (TIM3_TRGO_TRIGGER_SUPPORT)
#define GPDMA1_TRIGGER_TIM3_TRGO          44U   /*!< GPDMA1 HW Trigger signal is TIM3_TRGO       */
#endif /* TIM3_TRGO_TRIGGER_SUPPORT */
#if defined (TIM4_TRGO_TRIGGER_SUPPORT)
#define GPDMA1_TRIGGER_TIM4_TRGO          45U   /*!< GPDMA1 HW Trigger signal is TIM4_TRGO       */
#endif /* TIM4_TRGO_TRIGGER_SUPPORT */
#if defined (TIM5_TRGO_TRIGGER_SUPPORT)
#define GPDMA1_TRIGGER_TIM5_TRGO          46U   /*!< GPDMA1 HW Trigger signal is TIM5_TRGO       */
#endif /* TIM5_TRGO_TRIGGER_SUPPORT */
#if defined (LTDC)
#define GPDMA1_TRIGGER_LTDC_LI            47U   /*!< GPDMA1 HW Trigger signal is LTDC_LI         */
#endif /* LTDC */
#if defined (DSI)
#define GPDMA1_TRIGGER_DSI_TE             48U   /*!< GPDMA1 HW Trigger signal is DSI_TE          */
#define GPDMA1_TRIGGER_DSI_ER             49U   /*!< GPDMA1 HW Trigger signal is DSI_ER          */
#endif /* DSI */
#if defined (DMA2D_TRIGGER_SUPPORT)
#define GPDMA1_TRIGGER_DMA2D_TC           50U   /*!< GPDMA1 HW Trigger signal is DMA2D_TC        */
#define GPDMA1_TRIGGER_DMA2D_CTC          51U   /*!< GPDMA1 HW Trigger signal is DMA2D_CTC       */
#define GPDMA1_TRIGGER_DMA2D_TW           52U   /*!< GPDMA1 HW Trigger signal is DMA2D_TW        */
#endif /* DMA2D_TRIGGER_SUPPORT */
#if defined (GPU2D)
#define GPDMA1_TRIGGER_GPU2D_FLAG0        53U   /*!< GPDMA1 HW Trigger signal is GPU2D_FLAG0     */
#define GPDMA1_TRIGGER_GPU2D_FLAG1        54U   /*!< GPDMA1 HW Trigger signal is GPU2D_FLAG1     */
#define GPDMA1_TRIGGER_GPU2D_FLAG2        55U   /*!< GPDMA1 HW Trigger signal is GPU2D_FLAG2     */
#define GPDMA1_TRIGGER_GPU2D_FLAG3        56U   /*!< GPDMA1 HW Trigger signal is GPU2D_FLAG3     */
#endif /* GPU2D */
#define GPDMA1_TRIGGER_ADC4_AWD1          57U   /*!< GPDMA1 HW Trigger signal is ADC4_AWD1       */
#define GPDMA1_TRIGGER_ADC1_AWD1          58U   /*!< GPDMA1 HW Trigger signal is ADC1_AWD1       */
#if defined (GFXTIM)
#define GPDMA1_TRIGGER_GFXTIM_EVT3        59U   /*!< GPDMA1 HW Trigger signal is GFXTIM_EVT3     */
#define GPDMA1_TRIGGER_GFXTIM_EVT2        60U   /*!< GPDMA1 HW Trigger signal is GFXTIM_EVT2     */
#define GPDMA1_TRIGGER_GFXTIM_EVT1        61U   /*!< GPDMA1 HW Trigger signal is GFXTIM_EVT1     */
#define GPDMA1_TRIGGER_GFXTIM_EVT0        62U   /*!< GPDMA1 HW Trigger signal is GFXTIM_EVT0     */
#endif /* GFXTIM */
#if defined (JPEG)
#define GPDMA1_TRIGGER_JPEG_EOC           63U   /*!< GPDMA1 HW Trigger signal is JPEG_EOC        */
#define GPDMA1_TRIGGER_JPEG_IFNF          64U   /*!< GPDMA1 HW Trigger signal is JPEG_IFNF       */
#define GPDMA1_TRIGGER_JPEG_IFT           65U   /*!< GPDMA1 HW Trigger signal is JPEG_IFT        */
#define GPDMA1_TRIGGER_JPEG_OFNE          66U   /*!< GPDMA1 HW Trigger signal is JPEG_OFNE       */
#define GPDMA1_TRIGGER_JPEG_OFT           67U   /*!< GPDMA1 HW Trigger signal is JPEG_OFT        */
#endif /* JPEG */

/* LPDMA1 triggers */
#define LPDMA1_TRIGGER_EXTI_LINE0         0U    /*!< LPDMA1 HW Trigger signal is EXTI_LINE0      */
#define LPDMA1_TRIGGER_EXTI_LINE1         1U    /*!< LPDMA1 HW Trigger signal is EXTI_LINE1      */
#define LPDMA1_TRIGGER_EXTI_LINE2         2U    /*!< LPDMA1 HW Trigger signal is EXTI_LINE2      */
#define LPDMA1_TRIGGER_EXTI_LINE3         3U    /*!< LPDMA1 HW Trigger signal is EXTI_LINE3      */
#define LPDMA1_TRIGGER_EXTI_LINE4         4U    /*!< LPDMA1 HW Trigger signal is EXTI_LINE4      */
#define LPDMA1_TRIGGER_TAMP_TRG1          5U    /*!< LPDMA1 HW Trigger signal is TAMP_TRG1       */
#define LPDMA1_TRIGGER_TAMP_TRG2          6U    /*!< LPDMA1 HW Trigger signal is TAMP_TRG2       */
#define LPDMA1_TRIGGER_TAMP_TRG3          7U    /*!< LPDMA1 HW Trigger signal is TAMP_TRG3       */
#define LPDMA1_TRIGGER_LPTIM1_CH1         8U    /*!< LPDMA1 HW Trigger signal is LPTIM1_CH1      */
#define LPDMA1_TRIGGER_LPTIM1_CH2         9U    /*!< LPDMA1 HW Trigger signal is LPTIM1_CH2      */
#define LPDMA1_TRIGGER_LPTIM3_CH1         10U   /*!< LPDMA1 HW Trigger signal is LPTIM3_CH1      */
#define LPDMA1_TRIGGER_LPTIM4_OUT         11U   /*!< LPDMA1 HW Trigger signal is LPTIM4_OUT      */
#define LPDMA1_TRIGGER_COMP1_OUT          12U   /*!< LPDMA1 HW Trigger signal is COMP1_OUT       */
#if defined(COMP2)
#define LPDMA1_TRIGGER_COMP2_OUT          13U   /*!< LPDMA1 HW Trigger signal is COMP2_OUT       */
#endif /* COMP2 */
#define LPDMA1_TRIGGER_RTC_ALRA_TRG       14U   /*!< LPDMA1 HW Trigger signal is RTC_ALRA_TRG    */
#define LPDMA1_TRIGGER_RTC_ALRB_TRG       15U   /*!< LPDMA1 HW Trigger signal is RTC_ALRB_TRG    */
#define LPDMA1_TRIGGER_RTC_WUT_TRG        16U   /*!< LPDMA1 HW Trigger signal is RTC_WUT_TRG     */
#define LPDMA1_TRIGGER_ADC4_AWD1          17U   /*!< LPDMA1 HW Trigger signal is ADC4_AWD1       */
#define LPDMA1_TRIGGER_LPDMA1_CH0_TCF     18U   /*!< LPDMA1 HW Trigger signal is LPDMA1_CH0_TCF  */
#define LPDMA1_TRIGGER_LPDMA1_CH1_TCF     19U   /*!< LPDMA1 HW Trigger signal is LPDMA1_CH1_TCF  */
#define LPDMA1_TRIGGER_LPDMA1_CH2_TCF     20U   /*!< LPDMA1 HW Trigger signal is LPDMA1_CH2_TCF  */
#define LPDMA1_TRIGGER_LPDMA1_CH3_TCF     21U   /*!< LPDMA1 HW Trigger signal is LPDMA1_CH3_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH0_TCF     22U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH0_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH1_TCF     23U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH1_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH4_TCF     24U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH4_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH5_TCF     25U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH5_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH6_TCF     26U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH6_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH7_TCF     27U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH7_TCF  */
#define LPDMA1_TRIGGER_GPDMA1_CH12_TCF    28U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH12_TCF */
#define LPDMA1_TRIGGER_GPDMA1_CH13_TCF    29U   /*!< LPDMA1 HW Trigger signal is GPDMA1_CH13_TCF */
#define LPDMA1_TRIGGER_TIM2_TRGO          30U   /*!< LPDMA1 HW Trigger signal is TIM2_TRGO       */
#define LPDMA1_TRIGGER_TIM15_TRGO         31U   /*!< LPDMA1 HW Trigger signal is TIM15_TRGO      */
/**
  * @}
  */

/** @defgroup DMAEx_Node_Type DMAEx Node Type
  * @brief    DMAEx Node Type
  * @{
  */
#define DMA_LPDMA_LINEAR_NODE (DMA_CHANNEL_TYPE_LPDMA | DMA_CHANNEL_TYPE_LINEAR_ADDR) /*!< Defines the LPDMA linear addressing node type      */
#define DMA_GPDMA_LINEAR_NODE (DMA_CHANNEL_TYPE_GPDMA | DMA_CHANNEL_TYPE_LINEAR_ADDR) /*!< Defines the GPDMA linear addressing node type      */
#define DMA_GPDMA_2D_NODE     (DMA_CHANNEL_TYPE_GPDMA | DMA_CHANNEL_TYPE_2D_ADDR)     /*!< Defines the GPDMA 2 dimension addressing node type */
/**
  * @}
  */

/** @defgroup DMAEx_Link_Allocated_Port DMAEx Linked-List Allocated Port
  * @brief    DMAEx Linked-List Allocated Port
  * @{
  */
#define DMA_LINK_ALLOCATED_PORT0 0x00000000U /*!< Link allocated port 0 */
#define DMA_LINK_ALLOCATED_PORT1 DMA_CCR_LAP /*!< Link allocated port 1 */
/**
  * @}
  */

/** @defgroup DMAEx_Link_Step_Mode DMAEx Link Step Mode
  * @brief    DMAEx Link Step Mode
  * @{
  */
#define DMA_LSM_FULL_EXECUTION  0x00000000U /*!< Channel is executed for the full linked-list */
#define DMA_LSM_1LINK_EXECUTION DMA_CCR_LSM /*!< Channel is executed once for the current LLI */
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions ------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Functions DMAEx Exported Functions
  * @brief    DMAEx Exported functions
  * @{
  */

/** @defgroup DMAEx_Exported_Functions_Group1 Linked-List Initialization and De-Initialization Functions
  * @brief    Linked-List Initialization and De-Initialization Functions
  * @{
  */
HAL_StatusTypeDef HAL_DMAEx_List_Init(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_DeInit(DMA_HandleTypeDef *const hdma);
/**
  * @}
  */

/** @defgroup DMAEx_Exported_Functions_Group2 Linked-List IO Operation Functions
  * @brief    Linked-List IO Operation Functions
  * @{
  */
HAL_StatusTypeDef HAL_DMAEx_List_Start(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_Start_IT(DMA_HandleTypeDef *const hdma);
/**
  * @}
  */

/** @defgroup DMAEx_Exported_Functions_Group3 Linked-List Management Functions
  * @brief    Linked-List Management Functions
  * @{
  */
HAL_StatusTypeDef HAL_DMAEx_List_BuildNode(DMA_NodeConfTypeDef const *const pNodeConfig,
                                           DMA_NodeTypeDef *const pNode);
HAL_StatusTypeDef HAL_DMAEx_List_GetNodeConfig(DMA_NodeConfTypeDef *const pNodeConfig,
                                               DMA_NodeTypeDef const *const pNode);

HAL_StatusTypeDef HAL_DMAEx_List_InsertNode(DMA_QListTypeDef *const pQList,
                                            DMA_NodeTypeDef *const pPrevNode,
                                            DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_InsertNode_Head(DMA_QListTypeDef *const pQList,
                                                 DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_InsertNode_Tail(DMA_QListTypeDef *const pQList,
                                                 DMA_NodeTypeDef *const pNewNode);

HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode(DMA_QListTypeDef *const pQList,
                                            DMA_NodeTypeDef *const pNode);
HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode_Head(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode_Tail(DMA_QListTypeDef *const pQList);

HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode(DMA_QListTypeDef *const pQList,
                                             DMA_NodeTypeDef *const pOldNode,
                                             DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode_Head(DMA_QListTypeDef *const pQList,
                                                  DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode_Tail(DMA_QListTypeDef *const pQList,
                                                  DMA_NodeTypeDef *const pNewNode);

HAL_StatusTypeDef HAL_DMAEx_List_ResetQ(DMA_QListTypeDef *const pQList);

HAL_StatusTypeDef HAL_DMAEx_List_InsertQ(DMA_QListTypeDef *const pSrcQList,
                                         DMA_NodeTypeDef const *const pPrevNode,
                                         DMA_QListTypeDef *const pDestQList);
HAL_StatusTypeDef HAL_DMAEx_List_InsertQ_Head(DMA_QListTypeDef *const pSrcQList,
                                              DMA_QListTypeDef *const pDestQList);
HAL_StatusTypeDef HAL_DMAEx_List_InsertQ_Tail(DMA_QListTypeDef *const pSrcQList,
                                              DMA_QListTypeDef *const pDestQList);

HAL_StatusTypeDef HAL_DMAEx_List_SetCircularModeConfig(DMA_QListTypeDef *const pQList,
                                                       DMA_NodeTypeDef *const pFirstCircularNode);
HAL_StatusTypeDef HAL_DMAEx_List_SetCircularMode(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ClearCircularMode(DMA_QListTypeDef *const pQList);

HAL_StatusTypeDef HAL_DMAEx_List_ConvertQToDynamic(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ConvertQToStatic(DMA_QListTypeDef *const pQList);

HAL_StatusTypeDef HAL_DMAEx_List_LinkQ(DMA_HandleTypeDef *const hdma,
                                       DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_UnLinkQ(DMA_HandleTypeDef *const hdma);
/**
  * @}
  */

/** @defgroup DMAEx_Exported_Functions_Group4 Data Handling, Repeated Block and Trigger Configuration Functions
  * @brief    Data Handling, Repeated Block and Trigger Configuration Functions
  * @{
  */
HAL_StatusTypeDef HAL_DMAEx_ConfigDataHandling(DMA_HandleTypeDef *const hdma,
                                               DMA_DataHandlingConfTypeDef const *const pConfigDataHandling);
HAL_StatusTypeDef HAL_DMAEx_ConfigTrigger(DMA_HandleTypeDef *const hdma,
                                          DMA_TriggerConfTypeDef const *const pConfigTrigger);
HAL_StatusTypeDef HAL_DMAEx_ConfigRepeatBlock(DMA_HandleTypeDef *const hdma,
                                              DMA_RepeatBlockConfTypeDef const *const pConfigRepeatBlock);
/**
  * @}
  */

/** @defgroup DMAEx_Exported_Functions_Group5 Suspend and Resume Operation Functions
  * @brief    Suspend and Resume Operation Functions
  * @{
  */
HAL_StatusTypeDef HAL_DMAEx_Suspend(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_Suspend_IT(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_Resume(DMA_HandleTypeDef *const hdma);
/**
  * @}
  */

/** @defgroup DMAEx_Exported_Functions_Group6 FIFO Status Function
  * @brief    FIFO Status Function
  * @{
  */
uint32_t HAL_DMAEx_GetFifoLevel(DMA_HandleTypeDef const *const hdma);
/**
  * @}
  */

/**
  * @}
  */

/* Private types -----------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Private_Types DMAEx Private Types
  * @brief    DMAEx Private Types
  * @{
  */

/**
  * @brief DMA Node in Queue Information Structure Definition.
  */
typedef struct
{
  uint32_t cllr_offset;       /* CLLR register offset  */

  uint32_t previousnode_addr; /* Previous node address */

  uint32_t currentnode_pos;   /* Current node position */

  uint32_t currentnode_addr;  /* Current node address  */

  uint32_t nextnode_addr;     /* Next node address     */

} DMA_NodeInQInfoTypeDef;
/**
  * @}
  */

/* Private constants -------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Private_Constants DMAEx Private Constants
  * @brief    DMAEx Private Constants
  * @{
  */
#define DMA_LINKEDLIST                  (0x0080UL) /* DMA channel linked-list mode          */

#define DMA_CHANNEL_TYPE_LINEAR_ADDR    (0x0001UL) /* DMA channel linear addressing mode    */
#define DMA_CHANNEL_TYPE_2D_ADDR        (0x0002UL) /* DMA channel 2D addressing mode        */
#define DMA_CHANNEL_TYPE_LPDMA          (0x0010UL) /* LPDMA channel node                    */
#define DMA_CHANNEL_TYPE_GPDMA          (0x0020UL) /* GPDMA channel node                    */

#define NODE_TYPE_MASK                  (0x00FFUL) /* DMA channel node type                 */
#define NODE_CLLR_IDX                   (0x0700UL) /* DMA channel node CLLR index mask      */
#define NODE_CLLR_IDX_POS               (0x0008UL) /* DMA channel node CLLR index position  */

#define NODE_MAXIMUM_SIZE               (0x0008UL) /* Amount of registers of the node       */

#define NODE_STATIC_FORMAT              (0x0000UL) /* DMA channel node static format        */
#define NODE_DYNAMIC_FORMAT             (0x0001UL) /* DMA channel node dynamic format       */

#define UPDATE_CLLR_POSITION            (0x0000UL) /* DMA channel update CLLR position      */
#define UPDATE_CLLR_VALUE               (0x0001UL) /* DMA channel update CLLR value         */

#define LASTNODE_ISNOT_CIRCULAR         (0x0000UL) /* Last node is not first circular node  */
#define LASTNODE_IS_CIRCULAR            (0x0001UL) /* Last node is first circular node      */

#define QUEUE_TYPE_STATIC               (0x0000UL) /* DMA channel static queue              */
#define QUEUE_TYPE_DYNAMIC              (0x0001UL) /* DMA channel dynamic queue             */

#define NODE_CTR1_DEFAULT_OFFSET        (0x0000UL) /* CTR1 default offset                   */
#define NODE_CTR2_DEFAULT_OFFSET        (0x0001UL) /* CTR2 default offset                   */
#define NODE_CBR1_DEFAULT_OFFSET        (0x0002UL) /* CBR1 default offset                   */
#define NODE_CSAR_DEFAULT_OFFSET        (0x0003UL) /* CSAR default offset                   */
#define NODE_CDAR_DEFAULT_OFFSET        (0x0004UL) /* CDAR default offset                   */
#define NODE_CTR3_DEFAULT_OFFSET        (0x0005UL) /* CTR3 2D addressing default offset     */
#define NODE_CBR2_DEFAULT_OFFSET        (0x0006UL) /* CBR2 2D addressing default offset     */
#define NODE_CLLR_2D_DEFAULT_OFFSET     (0x0007UL) /* CLLR 2D addressing default offset     */
#define NODE_CLLR_LINEAR_DEFAULT_OFFSET (0x0005UL) /* CLLR linear addressing default offset */

#define DMA_BURST_ADDR_OFFSET_MIN       (-8192L)  /* DMA burst minimum address offset      */
#define DMA_BURST_ADDR_OFFSET_MAX       (8192L)   /* DMA burst maximum address offset      */
#define DMA_BLOCK_ADDR_OFFSET_MIN       (-65536L) /* DMA block minimum address offset      */
#define DMA_BLOCK_ADDR_OFFSET_MAX       (65536L)  /* DMA block maximum address offset      */
/**
  * @}
  */

/* Private macros ----------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Private_Macros DMAEx Private Macros
  * @brief    DMAEx Private Macros
  * @{
  */
#define IS_DMA_DATA_ALIGNMENT(ALIGNMENT)              \
  (((ALIGNMENT) == DMA_DATA_RIGHTALIGN_ZEROPADDED) || \
   ((ALIGNMENT) == DMA_DATA_RIGHTALIGN_SIGNEXT)    || \
   ((ALIGNMENT) == DMA_DATA_PACK))

#define IS_DMA_DATA_EXCHANGE(EXCHANGE) \
  (((EXCHANGE) & (~(DMA_EXCHANGE_SRC_BYTE | DMA_EXCHANGE_DEST_BYTE | DMA_EXCHANGE_DEST_HALFWORD))) == 0U)

#define IS_DMA_REPEAT_COUNT(COUNT) \
  (((COUNT) > 0U) && ((COUNT) <= (DMA_CBR1_BRC >> DMA_CBR1_BRC_Pos)))

#define IS_DMA_BURST_ADDR_OFFSET(BURST_ADDR_OFFSET)     \
  (((BURST_ADDR_OFFSET) > DMA_BURST_ADDR_OFFSET_MIN) && \
   ((BURST_ADDR_OFFSET) < DMA_BURST_ADDR_OFFSET_MAX))

#define IS_DMA_BLOCK_ADDR_OFFSET(BLOCK_ADDR_OFFSET)     \
  (((BLOCK_ADDR_OFFSET) > DMA_BLOCK_ADDR_OFFSET_MIN) && \
   ((BLOCK_ADDR_OFFSET) < DMA_BLOCK_ADDR_OFFSET_MAX))

#define IS_DMA_LINK_ALLOCATED_PORT(LINK_ALLOCATED_PORT) \
  (((LINK_ALLOCATED_PORT) & (~(DMA_CCR_LAP))) == 0U)

#define IS_DMA_LINK_STEP_MODE(MODE)      \
  (((MODE) == DMA_LSM_FULL_EXECUTION) || \
   ((MODE) == DMA_LSM_1LINK_EXECUTION))

#define IS_DMA_TRIGGER_MODE(MODE)                   \
  (((MODE) == DMA_TRIGM_BLOCK_TRANSFER)          || \
   ((MODE) == DMA_TRIGM_REPEATED_BLOCK_TRANSFER) || \
   ((MODE) == DMA_TRIGM_LLI_LINK_TRANSFER)       || \
   ((MODE) == DMA_TRIGM_SINGLE_BURST_TRANSFER))

#define IS_DMA_TCEM_LINKEDLIST_EVENT_MODE(MODE)    \
  (((MODE) == DMA_TCEM_BLOCK_TRANSFER)          || \
   ((MODE) == DMA_TCEM_REPEATED_BLOCK_TRANSFER) || \
   ((MODE) == DMA_TCEM_EACH_LL_ITEM_TRANSFER)   || \
   ((MODE) == DMA_TCEM_LAST_LL_ITEM_TRANSFER))

#define IS_DMA_LINKEDLIST_MODE(MODE)    \
  (((MODE) == DMA_LINKEDLIST_NORMAL) || \
   ((MODE) == DMA_LINKEDLIST_CIRCULAR))

#define IS_DMA_TRIGGER_POLARITY(POLARITY)      \
  (((POLARITY) == DMA_TRIG_POLARITY_MASKED) || \
   ((POLARITY) == DMA_TRIG_POLARITY_RISING) || \
   ((POLARITY) == DMA_TRIG_POLARITY_FALLING))

#if defined (GPDMA1_TRIGGER_JPEG_OFT)
#define IS_DMA_TRIGGER_SELECTION(TRIGGER) ((TRIGGER) <= GPDMA1_TRIGGER_JPEG_OFT)
#else
#define IS_DMA_TRIGGER_SELECTION(TRIGGER) ((TRIGGER) <= GPDMA1_TRIGGER_ADC1_AWD1)
#endif /* GPDMA1_TRIGGER_JPEG_OFT */

#define IS_DMA_NODE_TYPE(TYPE)          \
  (((TYPE) == DMA_LPDMA_LINEAR_NODE) || \
   ((TYPE) == DMA_GPDMA_LINEAR_NODE) || \
   ((TYPE) == DMA_GPDMA_2D_NODE))
/**
  * @}
  */


/* Private functions -------------------------------------------------------------------------------------------------*/
/** @defgroup DMAEx_Private_Functions DMAEx Private Functions
  * @brief    DMAEx Private Functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STM32U5xx_HAL_DMA_EX_H */

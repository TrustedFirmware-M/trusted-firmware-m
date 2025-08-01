/**
  ******************************************************************************
  * @file    stm32u5xx_hal_gtzc.h
  * @author  MCD Application Team
  * @brief   Header file of GTZC HAL module.
  ******************************************************************************
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
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U5xx_HAL_GTZC_H
#define STM32U5xx_HAL_GTZC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal_def.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @addtogroup GTZC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup GTZC_Exported_Types GTZC Exported Types
  * @{
  */

/*!< Values needed for MPCBB_Attribute_ConfigTypeDef structure sizing */
#if defined (SRAM5_BASE)
#define GTZC_MPCBB_NB_VCTR_REG_MAX      (52U)     /* Up to 52 super-blocks       */
#define GTZC_MPCBB_NB_LCK_VCTR_REG_MAX  (2U)      /* More than one 32-bit needed */
#else
#define GTZC_MPCBB_NB_VCTR_REG_MAX      (32U)     /* Up to 32 super-blocks       */
#define GTZC_MPCBB_NB_LCK_VCTR_REG_MAX  (1U)      /* One 32-bit needed           */
#endif /* SRAM5_BASE */

typedef struct
{
  uint32_t MPCBB_SecConfig_array[GTZC_MPCBB_NB_VCTR_REG_MAX];  /*!< Each element specifies secure access mode for
                                                                    a super-block. Each bit corresponds to a block
                                                                    inside the super-block. 0 means non-secure,
                                                                    1 means secure */
  uint32_t MPCBB_PrivConfig_array[GTZC_MPCBB_NB_VCTR_REG_MAX]; /*!< Each element specifies privilege access mode for
                                                                    a super-block. Each bit corresponds to a block
                                                                    inside the super-block. 0 means non-privilege,
                                                                    1 means privilege */
  uint32_t MPCBB_LockConfig_array[GTZC_MPCBB_NB_LCK_VCTR_REG_MAX]; /*!< Each bit specifies the lock configuration of
                                                                        a super-block (32 blocks). 0 means unlocked,
                                                                        1 means locked */
} MPCBB_Attribute_ConfigTypeDef;

typedef struct
{
  uint32_t SecureRWIllegalMode; /*!< Secure read/write illegal access
                                     field. It can be a value of @ref GTZC_MPCBB_SecureRWIllegalMode */
  uint32_t InvertSecureState;   /*!< Default security state field (can be inverted or not).
                                     It can be a value of @ref GTZC_MPCBB_InvertSecureState */
  MPCBB_Attribute_ConfigTypeDef AttributeConfig; /*!< MPCBB attribute configuration sub-structure */
} MPCBB_ConfigTypeDef;

typedef struct
{
  uint32_t AreaId;     /*!< Area identifier field. It can be a value of @ref
                            GTZC_MPCWM_AreaId */
  uint32_t Offset;     /*!< Offset of the watermark area, starting from the selected
                            memory base address. It must aligned on 128KB for FMC
                            and OCTOSPI memories, and on 32-byte for BKPSRAM */
  uint32_t Length;     /*!< Length of the watermark area, starting from the selected
                            Offset. It must aligned on 128KB for FMC and OCTOSPI
                            memories, and on 32-byte for BKPSRAM */
  uint32_t Attribute;  /*!< Attributes of the watermark area. It can be a value
                            of @ref GTZC_MPCWM_Attribute */
  uint32_t Lock;       /*!< Lock of the watermark area. It can be a value
                            of @ref GTZC_MPCWM_Lock */
  uint32_t AreaStatus; /*!< Status of the watermark area. It can be set to
                            ENABLE or DISABLE */
} MPCWM_ConfigTypeDef;

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/

/** @defgroup GTZC_Private_Constants GTZC Private Constants
  * @{
  */

/** @defgroup GTZC_Private_PeriphId_composition GTZC Peripheral identifier composition
  * @{
  */

/* composition definition for Peripheral identifier parameter (PeriphId) used in
 * HAL_GTZC_TZSC_ConfigPeriphAttributes() and HAL_GTZC_TZSC_GetConfigPeriphAttributes()
 * functions and also in all HAL_GTZC_TZIC relative functions.
 * Bitmap Definition
 *   bits[31:28] Field "register". Define the register index a peripheral belongs to.
 *               Each bit is dedicated to a single register.
 *   bit[5]      Field "all peripherals". If this bit is set then the PeriphId targets
 *               all peripherals within all registers.
 *   bits[4:0]   Field "bit position". Define the bit position within the
 *               register dedicated to the peripheral, value from 0 to 31.
 */
#define GTZC_PERIPH_REG_SHIFT     (28U)
#define GTZC_PERIPH_REG           (0xF0000000U)
#define GTZC1_PERIPH_REG1         (0x00000000U)
#define GTZC1_PERIPH_REG2         (0x10000000U)
#define GTZC1_PERIPH_REG3         (0x20000000U)
#define GTZC1_PERIPH_REG4         (0x30000000U)
#define GTZC2_PERIPH_REG1         (0x40000000U)
#define GTZC2_PERIPH_REG2         (0x50000000U)
#define GTZC_PERIPH_BIT_POSITION  (0x0000001FU)

/**
  * @}
  */

/** @defgroup GTZC_Private_Attributes_Msk GTZC Attributes Masks
  * @{
  */
#define GTZC_ATTR_SEC_MASK         0x100U
#define GTZC_ATTR_PRIV_MASK        0x200U

/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup GTZC_Exported_Constants GTZC Exported Constants
  * @{
  */

/** @defgroup GTZC_MPCBB_SecureRWIllegalMode GTZC MPCBB SRWILADIS values
  * @{
  */

#define GTZC_MPCBB_SRWILADIS_ENABLE  (0U)
#define GTZC_MPCBB_SRWILADIS_DISABLE (GTZC_MPCBB_CR_SRWILADIS_Msk)

/**
  * @}
  */

/** @defgroup GTZC_MPCBB_InvertSecureState GTZC MPCBB INVSECSTATE values
  * @{
  */

#define GTZC_MPCBB_INVSECSTATE_NOT_INVERTED  (0U)
#define GTZC_MPCBB_INVSECSTATE_INVERTED      (GTZC_MPCBB_CR_INVSECSTATE_Msk)

/**
  * @}
  */

/** @defgroup GTZC_MPCWM_AreaId GTZC MPCWM area identifier values
  * @{
  */

#define GTZC_TZSC_MPCWM_ID1  (0U)
#define GTZC_TZSC_MPCWM_ID2  (1U)

/**
  * @}
  */

/** @defgroup GTZC_TZSC_TZIC_PeriphId GTZC TZSC and TZIC Peripheral identifier values
  * @{
  */
/* GTZC1 */
#define GTZC_PERIPH_TIM2          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM2_Pos)
#define GTZC_PERIPH_TIM3          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM3_Pos)
#define GTZC_PERIPH_TIM4          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM4_Pos)
#define GTZC_PERIPH_TIM5          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM5_Pos)
#define GTZC_PERIPH_TIM6          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM6_Pos)
#define GTZC_PERIPH_TIM7          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_TIM7_Pos)
#define GTZC_PERIPH_WWDG          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_WWDG_Pos)
#define GTZC_PERIPH_IWDG          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_IWDG_Pos)
#define GTZC_PERIPH_SPI2          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_SPI2_Pos)
#if defined (USART2)
#define GTZC_PERIPH_USART2        (GTZC1_PERIPH_REG1 | GTZC_CFGR1_USART2_Pos)
#endif /* USART2 */
#define GTZC_PERIPH_USART3        (GTZC1_PERIPH_REG1 | GTZC_CFGR1_USART3_Pos)
#define GTZC_PERIPH_UART4         (GTZC1_PERIPH_REG1 | GTZC_CFGR1_UART4_Pos)
#define GTZC_PERIPH_UART5         (GTZC1_PERIPH_REG1 | GTZC_CFGR1_UART5_Pos)
#define GTZC_PERIPH_I2C1          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_I2C1_Pos)
#define GTZC_PERIPH_I2C2          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_I2C2_Pos)
#define GTZC_PERIPH_CRS           (GTZC1_PERIPH_REG1 | GTZC_CFGR1_CRS_Pos)
#define GTZC_PERIPH_I2C4          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_I2C4_Pos)
#define GTZC_PERIPH_LPTIM2        (GTZC1_PERIPH_REG1 | GTZC_CFGR1_LPTIM2_Pos)
#define GTZC_PERIPH_FDCAN1        (GTZC1_PERIPH_REG1 | GTZC_CFGR1_FDCAN1_Pos)
#if defined (UCPD1)
#define GTZC_PERIPH_UCPD1         (GTZC1_PERIPH_REG1 | GTZC_CFGR1_UCPD1_Pos)
#endif /* UCPD1 */
#if defined (USART6)
#define GTZC_PERIPH_USART6        (GTZC1_PERIPH_REG1 | GTZC_CFGR1_USART6_Pos)
#endif /* USART6 */
#if defined (I2C5)
#define GTZC_PERIPH_I2C5          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_I2C5_Pos)
#endif /* I2C5 */
#if defined (I2C6)
#define GTZC_PERIPH_I2C6          (GTZC1_PERIPH_REG1 | GTZC_CFGR1_I2C6_Pos)
#endif /* I2C6 */
#define GTZC_PERIPH_TIM1          (GTZC1_PERIPH_REG2 | GTZC_CFGR2_TIM1_Pos)
#define GTZC_PERIPH_SPI1          (GTZC1_PERIPH_REG2 | GTZC_CFGR2_SPI1_Pos)
#define GTZC_PERIPH_TIM8          (GTZC1_PERIPH_REG2 | GTZC_CFGR2_TIM8_Pos)
#define GTZC_PERIPH_USART1        (GTZC1_PERIPH_REG2 | GTZC_CFGR2_USART1_Pos)
#define GTZC_PERIPH_TIM15         (GTZC1_PERIPH_REG2 | GTZC_CFGR2_TIM15_Pos)
#define GTZC_PERIPH_TIM16         (GTZC1_PERIPH_REG2 | GTZC_CFGR2_TIM16_Pos)
#define GTZC_PERIPH_TIM17         (GTZC1_PERIPH_REG2 | GTZC_CFGR2_TIM17_Pos)
#define GTZC_PERIPH_SAI1          (GTZC1_PERIPH_REG2 | GTZC_CFGR2_SAI1_Pos)
#if defined (SAI2)
#define GTZC_PERIPH_SAI2          (GTZC1_PERIPH_REG2 | GTZC_CFGR2_SAI2_Pos)
#endif /* SAI2 */
#if defined (LTDC) || defined (USB_DRD_FS)
#define GTZC_PERIPH_LTDCUSB       (GTZC1_PERIPH_REG2 | GTZC_CFGR2_LTDCUSB_Pos)
#endif /* LTDC || USB_DRD_FS */
#if defined (DSI)
#define GTZC_PERIPH_DSI           (GTZC1_PERIPH_REG2 | GTZC_CFGR2_DSI_Pos)
#endif /* DSI */
#if defined (GFXTIM)
#define GTZC_PERIPH_GFXTIM        (GTZC1_PERIPH_REG2 | GTZC_CFGR2_GFXTIM_Pos)
#endif /* GFXTIM */
#define GTZC_PERIPH_MDF1          (GTZC1_PERIPH_REG3 | GTZC_CFGR3_MDF1_Pos)
#define GTZC_PERIPH_CORDIC        (GTZC1_PERIPH_REG3 | GTZC_CFGR3_CORDIC_Pos)
#define GTZC_PERIPH_FMAC          (GTZC1_PERIPH_REG3 | GTZC_CFGR3_FMAC_Pos)
#define GTZC_PERIPH_CRC           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_CRC_Pos)
#define GTZC_PERIPH_TSC           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_TSC_Pos)
#if defined (DMA2D)
#define GTZC_PERIPH_DMA2D         (GTZC1_PERIPH_REG3 | GTZC_CFGR3_DMA2D_Pos)
#endif /* DMA2D */
#define GTZC_PERIPH_ICACHE_REG    (GTZC1_PERIPH_REG3 | GTZC_CFGR3_ICACHE_REG_Pos)
#define GTZC_PERIPH_DCACHE1_REG   (GTZC1_PERIPH_REG3 | GTZC_CFGR3_DCACHE1_REG_Pos)
#define GTZC_PERIPH_ADC12         (GTZC1_PERIPH_REG3 | GTZC_CFGR3_ADC12_Pos)
#define GTZC_PERIPH_DCMI_PSSI     (GTZC1_PERIPH_REG3 | GTZC_CFGR3_DCMI_Pos)
#if defined (USB_OTG_FS) || defined (USB_OTG_HS)
#define GTZC_PERIPH_OTG           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_OTG_Pos)
#endif /* (USB_OTG_FS) || (USB_OTG_HS) */
#if defined (AES)
#define GTZC_PERIPH_AES           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_AES_Pos)
#endif /* AES */
#define GTZC_PERIPH_HASH          (GTZC1_PERIPH_REG3 | GTZC_CFGR3_HASH_Pos)
#define GTZC_PERIPH_RNG           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_RNG_Pos)
#if defined (PKA)
#define GTZC_PERIPH_PKA           (GTZC1_PERIPH_REG3 | GTZC_CFGR3_PKA_Pos)
#endif /* PKA */
#if defined (SAES)
#define GTZC_PERIPH_SAES          (GTZC1_PERIPH_REG3 | GTZC_CFGR3_SAES_Pos)
#endif /* SAES */
#if defined (OCTOSPIM)
#define GTZC_PERIPH_OCTOSPIM      (GTZC1_PERIPH_REG3 | GTZC_CFGR3_OCTOSPIM_Pos)
#endif /* OCTOSPIM */
#define GTZC_PERIPH_SDMMC1        (GTZC1_PERIPH_REG3 | GTZC_CFGR3_SDMMC1_Pos)
#if defined (SDMMC2)
#define GTZC_PERIPH_SDMMC2        (GTZC1_PERIPH_REG3 | GTZC_CFGR3_SDMMC2_Pos)
#endif /* SDMMC2 */
#if defined (FMC_BASE)
#define GTZC_PERIPH_FSMC_REG      (GTZC1_PERIPH_REG3 | GTZC_CFGR3_FSMC_REG_Pos)
#endif /* FMC_BASE */
#define GTZC_PERIPH_OCTOSPI1_REG  (GTZC1_PERIPH_REG3 | GTZC_CFGR3_OCTOSPI1_REG_Pos)
#if defined (OCTOSPI2)
#define GTZC_PERIPH_OCTOSPI2_REG  (GTZC1_PERIPH_REG3 | GTZC_CFGR3_OCTOSPI2_REG_Pos)
#endif /* OCTOSPI2 */
#define GTZC_PERIPH_RAMCFG        (GTZC1_PERIPH_REG3 | GTZC_CFGR3_RAMCFG_Pos)
#if defined (GPU2D)
#define GTZC_PERIPH_GPU2D         (GTZC1_PERIPH_REG3 | GTZC_CFGR3_GPU2D_Pos)
#endif /* GPU2D */
#if defined (GFXMMU)
#define GTZC_PERIPH_GFXMMU        (GTZC1_PERIPH_REG3 | GTZC_CFGR3_GFXMMU_Pos)
#define GTZC_PERIPH_GFXMMU_REG    (GTZC1_PERIPH_REG3 | GTZC_CFGR3_GFXMMU_REG_Pos)
#endif /* GFXMMU */
#if defined (HSPI1)
#define GTZC_PERIPH_HSPI1_REG     (GTZC1_PERIPH_REG3 | GTZC_CFGR3_HSPI1_REG_Pos)
#endif /* HSPI1 */
#if defined (DCACHE2)
#define GTZC_PERIPH_DCACHE2_REG   (GTZC1_PERIPH_REG3 | GTZC_CFGR3_DCACHE2_REG_Pos)
#endif /* DCACHE2 */
#if defined (JPEG)
#define GTZC_PERIPH_JPEG          (GTZC1_PERIPH_REG3 | GTZC_CFGR3_JPEG_Pos)
#endif /* JPEG */
#define GTZC_PERIPH_GPDMA1        (GTZC1_PERIPH_REG4 | GTZC_CFGR4_GPDMA1_Pos)
#define GTZC_PERIPH_FLASH_REG     (GTZC1_PERIPH_REG4 | GTZC_CFGR4_FLASH_REG_Pos)
#define GTZC_PERIPH_FLASH         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_FLASH_Pos)
#if defined (OTFDEC2)
#define GTZC_PERIPH_OTFDEC2       (GTZC1_PERIPH_REG4 | GTZC_CFGR4_OTFDEC2_Pos)
#endif /* OTFDEC2 */
#if defined (OTFDEC1)
#define GTZC_PERIPH_OTFDEC1       (GTZC1_PERIPH_REG4 | GTZC_CFGR4_OTFDEC1_Pos)
#endif /* OTFDEC1 */
#define GTZC_PERIPH_TZSC1         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_TZSC1_Pos)
#define GTZC_PERIPH_TZIC1         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_TZIC1_Pos)
#define GTZC_PERIPH_OCTOSPI1_MEM  (GTZC1_PERIPH_REG4 | GTZC_CFGR4_OCTOSPI1_MEM_Pos)
#if defined (FMC_BASE)
#define GTZC_PERIPH_FSMC_MEM      (GTZC1_PERIPH_REG4 | GTZC_CFGR4_FSMC_MEM_Pos)
#endif /* FMC_BASE */
#define GTZC_PERIPH_BKPSRAM       (GTZC1_PERIPH_REG4 | GTZC_CFGR4_BKPSRAM_Pos)
#if defined (OCTOSPI2)
#define GTZC_PERIPH_OCTOSPI2_MEM  (GTZC1_PERIPH_REG4 | GTZC_CFGR4_OCTOSPI2_MEM_Pos)
#endif /* OCTOSPI2 */
#if defined (HSPI1)
#define GTZC_PERIPH_HSPI1_MEM     (GTZC1_PERIPH_REG4 | GTZC_CFGR4_HSPI1_MEM_Pos)
#endif /* HSPI1 */
#if defined (SRAM6_BASE)
#define GTZC_PERIPH_SRAM6         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_SRAM6_Pos)
#define GTZC_PERIPH_MPCBB6_REG    (GTZC1_PERIPH_REG4 | GTZC_CFGR4_MPCBB6_REG_Pos)
#endif /* SRAM6_BASE */
#define GTZC_PERIPH_SRAM1         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_SRAM1_Pos)
#define GTZC_PERIPH_MPCBB1_REG    (GTZC1_PERIPH_REG4 | GTZC_CFGR4_MPCBB1_REG_Pos)
#define GTZC_PERIPH_SRAM2         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_SRAM2_Pos)
#define GTZC_PERIPH_MPCBB2_REG    (GTZC1_PERIPH_REG4 | GTZC_CFGR4_MPCBB2_REG_Pos)
#if defined (SRAM3_BASE)
#define GTZC_PERIPH_SRAM3         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_SRAM3_Pos)
#endif /* SRAM3_BASE */
#define GTZC_PERIPH_MPCBB3_REG    (GTZC1_PERIPH_REG4 | GTZC_CFGR4_MPCBB3_REG_Pos)
#if defined (SRAM5_BASE)
#define GTZC_PERIPH_SRAM5         (GTZC1_PERIPH_REG4 | GTZC_CFGR4_SRAM5_Pos)
#define GTZC_PERIPH_MPCBB5_REG    (GTZC1_PERIPH_REG4 | GTZC_CFGR4_MPCBB5_REG_Pos)
#endif /* SRAM5_BASE */

/* GTZC2 */
#define GTZC_PERIPH_SPI3          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_SPI3_Pos)
#define GTZC_PERIPH_LPUART1       (GTZC2_PERIPH_REG1 | GTZC_CFGR1_LPUART1_Pos)
#define GTZC_PERIPH_I2C3          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_I2C3_Pos)
#define GTZC_PERIPH_LPTIM1        (GTZC2_PERIPH_REG1 | GTZC_CFGR1_LPTIM1_Pos)
#define GTZC_PERIPH_LPTIM3        (GTZC2_PERIPH_REG1 | GTZC_CFGR1_LPTIM3_Pos)
#define GTZC_PERIPH_LPTIM4        (GTZC2_PERIPH_REG1 | GTZC_CFGR1_LPTIM4_Pos)
#define GTZC_PERIPH_OPAMP         (GTZC2_PERIPH_REG1 | GTZC_CFGR1_OPAMP_Pos)
#define GTZC_PERIPH_COMP          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_COMP_Pos)
#define GTZC_PERIPH_ADC4          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_ADC4_Pos)
#define GTZC_PERIPH_VREFBUF       (GTZC2_PERIPH_REG1 | GTZC_CFGR1_VREFBUF_Pos)
#define GTZC_PERIPH_DAC1          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_DAC1_Pos)
#define GTZC_PERIPH_ADF1          (GTZC2_PERIPH_REG1 | GTZC_CFGR1_ADF1_Pos)
#define GTZC_PERIPH_SYSCFG        (GTZC2_PERIPH_REG2 | GTZC_CFGR2_SYSCFG_Pos)
#define GTZC_PERIPH_RTC           (GTZC2_PERIPH_REG2 | GTZC_CFGR2_RTC_Pos)
#define GTZC_PERIPH_TAMP          (GTZC2_PERIPH_REG2 | GTZC_CFGR2_TAMP_Pos)
#define GTZC_PERIPH_PWR           (GTZC2_PERIPH_REG2 | GTZC_CFGR2_PWR_Pos)
#define GTZC_PERIPH_RCC           (GTZC2_PERIPH_REG2 | GTZC_CFGR2_RCC_Pos)
#define GTZC_PERIPH_LPDMA1        (GTZC2_PERIPH_REG2 | GTZC_CFGR2_LPDMA1_Pos)
#define GTZC_PERIPH_EXTI          (GTZC2_PERIPH_REG2 | GTZC_CFGR2_EXTI_Pos)
#define GTZC_PERIPH_TZSC2         (GTZC2_PERIPH_REG2 | GTZC_CFGR2_TZSC2_Pos)
#define GTZC_PERIPH_TZIC2         (GTZC2_PERIPH_REG2 | GTZC_CFGR2_TZIC2_Pos)
#define GTZC_PERIPH_SRAM4         (GTZC2_PERIPH_REG2 | GTZC_CFGR2_SRAM4_Pos)
#define GTZC_PERIPH_MPCBB4_REG    (GTZC2_PERIPH_REG2 | GTZC_CFGR2_MPCBB4_REG_Pos)

#define GTZC_PERIPH_ALL           (0x00000020U)

/* Note that two maximum values are also defined here:
 * - max number of securable AHB/APB peripherals or masters
 *   (used in TZSC sub-block)
 * - max number of securable and TrustZone-aware AHB/APB peripherals or masters
 *   (used in TZIC sub-block)
 */
#define GTZC_TZSC_PERIPH_NUMBER   (HAL_GTZC_TZSC_GET_ARRAY_INDEX(GTZC_PERIPH_ADF1 + 1U))
#define GTZC_TZIC_PERIPH_NUMBER   (HAL_GTZC_TZIC_GET_ARRAY_INDEX(GTZC_PERIPH_MPCBB4_REG + 1U))

/**
  * @}
  */

/** @defgroup GTZC_TZSC_PeriphAttributes GTZC TZSC peripheral attribute values
  * @{
  */

/* user-oriented definitions for attribute parameter (PeriphAttributes) used in
 * HAL_GTZC_TZSC_ConfigPeriphAttributes() and HAL_GTZC_TZSC_GetConfigPeriphAttributes()
 * functions
 */
#define GTZC_TZSC_PERIPH_SEC    (GTZC_ATTR_SEC_MASK | 0x00000001U)  /*!< Secure attribute        */
#define GTZC_TZSC_PERIPH_NSEC   (GTZC_ATTR_SEC_MASK | 0x00000000U)  /*!< Non-secure attribute    */
#define GTZC_TZSC_PERIPH_PRIV   (GTZC_ATTR_PRIV_MASK | 0x00000002U) /*!< Privilege attribute     */
#define GTZC_TZSC_PERIPH_NPRIV  (GTZC_ATTR_PRIV_MASK | 0x00000000U) /*!< Non-privilege attribute */

/**
  * @}
  */

/** @defgroup GTZC_TZSC_Lock GTZC TZSC lock values
  * @{
  */

/* user-oriented definitions for HAL_GTZC_TZSC_GetLock() returned value */
#define GTZC_TZSC_LOCK_OFF  (0U)
#define GTZC_TZSC_LOCK_ON   GTZC_TZSC_CR_LCK_Msk

/**
  * @}
  */

/** @defgroup GTZC_MPCWM_Group GTZC MPCWM values
  * @{
  */

/* user-oriented definitions for TZSC_MPCWM */
#define GTZC_TZSC_MPCWM_GRANULARITY_1    0x00020000U /* OCTOSPI & FMC granularity: 128 kbytes */
#define GTZC_TZSC_MPCWM_GRANULARITY_2    0x00000020U /* BKPSRAM granularity: 32 bytes         */

/**
  * @}
  */

/** @defgroup GTZC_MPCWM_Lock GTZC MPCWM Lock values
  * @{
  */

/* user-oriented definitions for TZSC_MPCWM */
#define GTZC_TZSC_MPCWM_LOCK_OFF  (0U)
#define GTZC_TZSC_MPCWM_LOCK_ON   GTZC_TZSC_MPCWM_CFGR_SRLOCK_Msk

/**
  * @}
  */

/** @defgroup GTZC_MPCWM_Attribute GTZC MPCWM Attribute values
  * @{
  */

/* user-oriented definitions for TZSC_MPCWM */
#define GTZC_TZSC_MPCWM_REGION_NSEC  (0U)
#define GTZC_TZSC_MPCWM_REGION_SEC   (1U)
#define GTZC_TZSC_MPCWM_REGION_NPRIV (0U)
#define GTZC_TZSC_MPCWM_REGION_PRIV  (2U)

/**
  * @}
  */

/** @defgroup GTZC_MPCBB_Group GTZC MPCBB values
  * @{
  */

/* user-oriented definitions for MPCBB */
#define GTZC_MPCBB_BLOCK_SIZE           0x200U                        /* 512 Bytes */
#define GTZC_MPCBB_SUPERBLOCK_SIZE      (GTZC_MPCBB_BLOCK_SIZE * 32U) /* 16 KBytes */
#define GTZC_MPCBB_SUPERBLOCK_UNLOCKED  (0U)
#define GTZC_MPCBB_SUPERBLOCK_LOCKED    (1U)

#define GTZC_MPCBB_BLOCK_NSEC           (GTZC_ATTR_SEC_MASK  | 0U)
#define GTZC_MPCBB_BLOCK_SEC            (GTZC_ATTR_SEC_MASK  | 1U)
#define GTZC_MPCBB_BLOCK_NPRIV          (GTZC_ATTR_PRIV_MASK | 0U)
#define GTZC_MPCBB_BLOCK_PRIV           (GTZC_ATTR_PRIV_MASK | 2U)

/* user-oriented definitions for HAL_GTZC_MPCBB_GetLock() returned value */
#define GTZC_MPCBB_LOCK_OFF  (0U)
#define GTZC_MPCBB_LOCK_ON   (1U)

/**
  * @}
  */

/** @defgroup GTZC_TZIC_Flag GTZC TZIC flag values
  * @{
  */

/* user-oriented definitions for HAL_GTZC_TZIC_GetFlag() flag parameter */
#define GTZC_TZIC_NO_ILA_EVENT       (0U)
#define GTZC_TZIC_ILA_EVENT_PENDING  (1U)

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/** @defgroup GTZC_Private_Macros GTZC Private Macros
  * @{
  */

/* retrieve information to access register for a specific PeriphId */
#define GTZC_GET_REG_INDEX(periph_id)\
  (((periph_id) & GTZC_PERIPH_REG) >> GTZC_PERIPH_REG_SHIFT)
#define GTZC_GET_REG_INDEX_IN_INSTANCE(periph_id)\
  ((((periph_id) & GTZC_PERIPH_REG) <= GTZC1_PERIPH_REG4) ? \
   (((periph_id) & GTZC_PERIPH_REG) >> GTZC_PERIPH_REG_SHIFT) : \
   ((((periph_id) & GTZC_PERIPH_REG) >> GTZC_PERIPH_REG_SHIFT) - 4U))
#define GTZC_GET_PERIPH_POS(periph_id)     ((periph_id) & GTZC_PERIPH_BIT_POSITION)

#define IS_GTZC_BASE_ADDRESS(mem, address)\
  ( ( (uint32_t)(address) == (uint32_t)GTZC_BASE_ADDRESS_NS(mem) ) || \
    ( (uint32_t)(address) == (uint32_t)GTZC_BASE_ADDRESS_S(mem) ) )

#define GTZC_MEM_SIZE(mem)\
  ( mem ## _SIZE )

#define GTZC_BASE_ADDRESS_S(mem)\
  ( mem ## _BASE_S )

#define GTZC_BASE_ADDRESS_NS(mem)\
  ( mem ## _BASE_NS )

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup GTZC_Exported_Macros GTZC Exported Macros
  * @{
  */

/* user-oriented macro to get array index of a specific PeriphId
  * in case of GTZC_PERIPH_ALL usage in the two following functions:
  * HAL_GTZC_TZSC_ConfigPeriphAttributes() and HAL_GTZC_TZSC_GetConfigPeriphAttributes()
  */
#define HAL_GTZC_TZSC_GET_ARRAY_INDEX(periph_id) \
  (uint32_t)((HAL_GTZC_TZSC_GET_INSTANCE(periph_id) == GTZC_TZSC1)? \
             ((GTZC_GET_REG_INDEX(periph_id) * 32U) + GTZC_GET_PERIPH_POS(periph_id)) : \
             (((GTZC_GET_REG_INDEX(periph_id) - 1U) * 32U) + GTZC_GET_PERIPH_POS(periph_id) ))

#define HAL_GTZC_TZIC_GET_ARRAY_INDEX(periph_id) \
  ( (GTZC_GET_REG_INDEX((periph_id)) * 32U) + GTZC_GET_PERIPH_POS((periph_id)) )

/* user-oriented macro to get TZSC instance of a specific PeriphId */
#define HAL_GTZC_TZSC_GET_INSTANCE(periph_id) \
  ((GTZC_GET_REG_INDEX(periph_id) <= (GTZC1_PERIPH_REG4 >> GTZC_PERIPH_REG_SHIFT))? \
   GTZC_TZSC1 : GTZC_TZSC2)

/* user-oriented macro to get TZIC instance of a specific PeriphId */
#define HAL_GTZC_TZIC_GET_INSTANCE(periph_id) \
  ((GTZC_GET_REG_INDEX(periph_id) <= (GTZC1_PERIPH_REG4>> GTZC_PERIPH_REG_SHIFT))? \
   GTZC_TZIC1 : GTZC_TZIC2)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup GTZC_Exported_Functions
  * @{
  */

/** @addtogroup GTZC_Exported_Functions_Group1
  * @brief    TZSC Initialization and Configuration functions
  * @{
  */

HAL_StatusTypeDef HAL_GTZC_TZSC_ConfigPeriphAttributes(uint32_t PeriphId,
                                                       uint32_t PeriphAttributes);
HAL_StatusTypeDef HAL_GTZC_TZSC_GetConfigPeriphAttributes(uint32_t PeriphId,
                                                          uint32_t *PeriphAttributes);

/**
  * @}
  */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/** @addtogroup GTZC_Exported_Functions_Group2
  * @brief    MPCWM Initialization and Configuration functions
  * @{
  */

HAL_StatusTypeDef HAL_GTZC_TZSC_MPCWM_ConfigMemAttributes(uint32_t MemBaseAddress,
                                                          const MPCWM_ConfigTypeDef *pMPCWM_Desc);
HAL_StatusTypeDef HAL_GTZC_TZSC_MPCWM_GetConfigMemAttributes(uint32_t MemBaseAddress,
                                                             MPCWM_ConfigTypeDef *pMPCWM_Desc);
/**
  * @}
  */

/** @addtogroup GTZC_Exported_Functions_Group3
  * @brief    TZSC and TZSC-MPCWM Lock functions
  * @{
  */

void     HAL_GTZC_TZSC_Lock(GTZC_TZSC_TypeDef *TZSC_Instance);
uint32_t HAL_GTZC_TZSC_GetLock(const GTZC_TZSC_TypeDef *TZSC_Instance);

/**
  * @}
  */
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
/** @addtogroup GTZC_Exported_Functions_Group4
  * @brief    MPCBB Initialization and Configuration functions
  * @{
  */

HAL_StatusTypeDef HAL_GTZC_MPCBB_ConfigMem(uint32_t MemBaseAddress,
                                           const MPCBB_ConfigTypeDef *pMPCBB_desc);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetConfigMem(uint32_t MemBaseAddress,
                                              MPCBB_ConfigTypeDef *pMPCBB_desc);
HAL_StatusTypeDef HAL_GTZC_MPCBB_ConfigMemAttributes(uint32_t MemAddress,
                                                     uint32_t NbBlocks,
                                                     const uint32_t *pMemAttributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetConfigMemAttributes(uint32_t MemAddress,
                                                        uint32_t NbBlocks,
                                                        uint32_t *pMemAttributes);

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
HAL_StatusTypeDef HAL_GTZC_MPCBB_LockConfig(uint32_t MemAddress,
                                            uint32_t NbSuperBlocks,
                                            const uint32_t *pLockAttributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetLockConfig(uint32_t MemAddress,
                                               uint32_t NbSuperBlocks,
                                               uint32_t *pLockAttributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_Lock(uint32_t MemBaseAddress);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetLock(uint32_t MemBaseAddress,
                                         uint32_t *pLockState);
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/**
  * @}
  */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/** @addtogroup GTZC_Exported_Functions_Group5
  * @brief    TZIC functions
  * @{
  */

HAL_StatusTypeDef HAL_GTZC_TZIC_DisableIT(uint32_t PeriphId);
HAL_StatusTypeDef HAL_GTZC_TZIC_EnableIT(uint32_t PeriphId);
HAL_StatusTypeDef HAL_GTZC_TZIC_GetFlag(uint32_t PeriphId, uint32_t *pFlag);
HAL_StatusTypeDef HAL_GTZC_TZIC_ClearFlag(uint32_t PeriphId);

/**
  * @}
  */

/** @addtogroup GTZC_Exported_Functions_Group6
  * @brief    IRQ related Functions
  * @{
  */

void HAL_GTZC_IRQHandler(void);
void HAL_GTZC_TZIC_Callback(uint32_t PeriphId);

/**
  * @}
  */

#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

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
#endif

#endif /* STM32U5xx_HAL_GTZC_H */


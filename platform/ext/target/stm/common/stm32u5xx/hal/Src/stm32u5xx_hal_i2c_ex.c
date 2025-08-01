/**
  ******************************************************************************
  * @file    stm32u5xx_hal_i2c_ex.c
  * @author  MCD Application Team
  * @brief   I2C Extended HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of I2C Extended peripheral:
  *           + Filter Mode Functions
  *           + WakeUp Mode Functions
  *           + FastModePlus Functions
  *           + Autonomous Mode Functions
  *
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
  @verbatim
  ==============================================================================
               ##### I2C peripheral Extended features  #####
  ==============================================================================

  [..] Comparing to other previous devices, the I2C interface for STM32U5xx
       devices contains the following additional features

       (+) Possibility to disable or enable Analog Noise Filter
       (+) Use of a configured Digital Noise Filter
       (+) Disable or enable wakeup from Stop mode(s)
       (+) Disable or enable Fast Mode Plus
       (+) Configure Autonomous mode

                     ##### How to use this driver #####
  ==============================================================================
  [..] This driver provides functions to configure Noise Filter and Wake Up Feature
    (#) Configure I2C Analog noise filter using the function HAL_I2CEx_ConfigAnalogFilter()
    (#) Configure I2C Digital noise filter using the function HAL_I2CEx_ConfigDigitalFilter()
    (#) Configure the enable or disable of I2C Wake Up Mode using the functions :
          (++) HAL_I2CEx_EnableWakeUp()
          (++) HAL_I2CEx_DisableWakeUp()
    (#) Configure the enable or disable of fast mode plus driving capability using the functions :
          (++) HAL_I2CEx_ConfigFastModePlus()
    (#) Set or get or clear the autonomous mode configuration using these functions :
          (++) HAL_I2CEx_SetConfigAutonomousMode()
          (++) HAL_I2CEx_GetConfigAutonomousMode()
          (++) HAL_I2CEx_ClearConfigAutonomousMode()
  @endverbatim
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @defgroup I2CEx I2CEx
  * @brief I2C Extended HAL module driver
  * @{
  */

#ifdef HAL_I2C_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup I2CEx_Exported_Functions I2C Extended Exported Functions
  * @{
  */

/** @defgroup I2CEx_Exported_Functions_Group1 Filter Mode Functions
  * @brief    Filter Mode Functions
  *
@verbatim
 ===============================================================================
                      ##### Filter Mode Functions #####
 ===============================================================================
    [..] This section provides functions allowing to:
      (+) Configure Noise Filters

@endverbatim
  * @{
  */

/**
  * @brief  Configure I2C Analog noise filter.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @param  AnalogFilter New state of the Analog filter.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_ConfigAnalogFilter(I2C_HandleTypeDef *hi2c, uint32_t AnalogFilter)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_ANALOG_FILTER(AnalogFilter));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Disable the selected I2C peripheral */
    __HAL_I2C_DISABLE(hi2c);

    /* Reset I2Cx ANOFF bit */
    hi2c->Instance->CR1 &= ~(I2C_CR1_ANFOFF);

    /* Set analog filter bit*/
    hi2c->Instance->CR1 |= AnalogFilter;

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Configure I2C Digital noise filter.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @param  DigitalFilter Coefficient of digital noise filter between Min_Data=0x00 and Max_Data=0x0F.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_ConfigDigitalFilter(I2C_HandleTypeDef *hi2c, uint32_t DigitalFilter)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_DIGITAL_FILTER(DigitalFilter));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Disable the selected I2C peripheral */
    __HAL_I2C_DISABLE(hi2c);

    /* Get the old register value */
    tmpreg = hi2c->Instance->CR1;

    /* Reset I2Cx DNF bits [11:8] */
    tmpreg &= ~(I2C_CR1_DNF);

    /* Set I2Cx DNF coefficient */
    tmpreg |= DigitalFilter << 8U;

    /* Store the new register value */
    hi2c->Instance->CR1 = tmpreg;

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}
/**
  * @}
  */

/** @defgroup I2CEx_Exported_Functions_Group2 WakeUp Mode Functions
  * @brief    WakeUp Mode Functions
  *
@verbatim
 ===============================================================================
                      ##### WakeUp Mode Functions #####
 ===============================================================================
    [..] This section provides functions allowing to:
      (+) Configure Wake Up Feature

@endverbatim
  * @{
  */

/**
  * @brief  Enable I2C wakeup from Stop mode(s).
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_EnableWakeUp(I2C_HandleTypeDef *hi2c)
{
  /* Check the parameters */
  assert_param(IS_I2C_WAKEUP_FROMSTOP_INSTANCE(hi2c->Instance));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Disable the selected I2C peripheral */
    __HAL_I2C_DISABLE(hi2c);

    /* Enable wakeup from stop mode */
    hi2c->Instance->CR1 |= I2C_CR1_WUPEN;

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Disable I2C wakeup from Stop mode(s).
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_DisableWakeUp(I2C_HandleTypeDef *hi2c)
{
  /* Check the parameters */
  assert_param(IS_I2C_WAKEUP_FROMSTOP_INSTANCE(hi2c->Instance));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Disable the selected I2C peripheral */
    __HAL_I2C_DISABLE(hi2c);

    /* Enable wakeup from stop mode */
    hi2c->Instance->CR1 &= ~(I2C_CR1_WUPEN);

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}
/**
  * @}
  */

/** @defgroup I2CEx_Exported_Functions_Group3 Fast Mode Plus Functions
  * @brief    Fast Mode Plus Functions
  *
@verbatim
 ===============================================================================
                      ##### Fast Mode Plus Functions #####
 ===============================================================================
    [..] This section provides functions allowing to:
      (+) Configure Fast Mode Plus

@endverbatim
  * @{
  */

/**
  * @brief  Configure I2C Fast Mode Plus.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @param  FastModePlus New state of the Fast Mode Plus.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_ConfigFastModePlus(I2C_HandleTypeDef *hi2c, uint32_t FastModePlus)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_FASTMODEPLUS(FastModePlus));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Disable the selected I2C peripheral */
    __HAL_I2C_DISABLE(hi2c);

    if (FastModePlus == I2C_FASTMODEPLUS_ENABLE)
    {
      /* Set I2Cx FMP bit */
      hi2c->Instance->CR1 |= (I2C_CR1_FMP);
    }
    else
    {
      /* Reset I2Cx FMP bit */
      hi2c->Instance->CR1 &= ~(I2C_CR1_FMP);
    }

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @}
  */

/** @defgroup I2CEx_Exported_Functions_Group4 Autonomous Mode Functions
  * @brief    Autonomous Mode Functions
  *
@verbatim
 ===============================================================================
                     ##### Autonomous Mode functions #####
 ===============================================================================
    [..] This section provides functions allowing to:
      (+) Configure Autonomous Mode

@endverbatim
  * @{
  */

/**
  * @brief  Set Autonomous Mode configuration
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @param  sConfig Pointer to a I2C_AutonomousModeConfTypeDef structure that contains
  *                the configuration information of the autonomous mode for the specified I2Cx peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_SetConfigAutonomousMode(I2C_HandleTypeDef *hi2c,
                                                    const I2C_AutonomousModeConfTypeDef *sConfig)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Check the parameters */
    assert_param(IS_I2C_TRIG_INPUT_INSTANCE(hi2c->Instance));
    assert_param(IS_I2C_TRIG_SOURCE(hi2c->Instance, sConfig->TriggerSelection));
    assert_param(IS_I2C_AUTO_MODE_TRG_POL(sConfig->TriggerPolarity));

    /* Disable the selected I2C peripheral to be able to configure AUTOCR */
    __HAL_I2C_DISABLE(hi2c);

    /* I2Cx AUTOCR Configuration */
    WRITE_REG(hi2c->Instance->AUTOCR,
              (sConfig->TriggerState | \
               ((sConfig->TriggerSelection) & I2C_AUTOCR_TRIGSEL_Msk) | \
               sConfig->TriggerPolarity));

    /* Enable the selected I2C peripheral */
    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}

/**
  * @brief  Get Autonomous Mode configuration
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @param  sConfig Pointer to a I2C_AutonomousModeConfTypeDef structure that contains
  *                the configuration information of the autonomous mode for the specified I2Cx peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_GetConfigAutonomousMode(const I2C_HandleTypeDef *hi2c,
                                                    I2C_AutonomousModeConfTypeDef *sConfig)
{
  uint32_t autocr_tmp;

  /* Check the parameters */
  assert_param(IS_I2C_TRIG_INPUT_INSTANCE(hi2c->Instance));

  autocr_tmp = hi2c->Instance->AUTOCR;

  sConfig->TriggerState     = (autocr_tmp & I2C_AUTOCR_TRIGEN);
  if (IS_I2C_GRP2_INSTANCE(hi2c->Instance))
  {
    sConfig->TriggerSelection = ((autocr_tmp & I2C_AUTOCR_TRIGSEL) | I2C_TRIG_GRP2);
  }
  else
  {
    sConfig->TriggerSelection = ((autocr_tmp & I2C_AUTOCR_TRIGSEL) | I2C_TRIG_GRP1);
  }
  sConfig->TriggerPolarity  = (autocr_tmp & I2C_AUTOCR_TRIGPOL);

  return HAL_OK;
}

/**
  * @brief  Clear Autonomous Mode configuration
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2Cx peripheral.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2CEx_ClearConfigAutonomousMode(I2C_HandleTypeDef *hi2c)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    /* Check the parameters */
    assert_param(IS_I2C_TRIG_INPUT_INSTANCE(hi2c->Instance));

    /* Disable the selected I2C peripheral to be able to clear AUTOCR */
    __HAL_I2C_DISABLE(hi2c);

    CLEAR_REG(hi2c->Instance->AUTOCR);

    /* Enable the selected I2C peripheral */
    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}
/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_I2C_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

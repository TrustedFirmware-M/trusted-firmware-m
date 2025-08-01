/**
  ******************************************************************************
  * @file    stm32u5xx_hal.c
  * @author  MCD Application Team
  * @brief   HAL module driver.
  *          This is the common part of the HAL initialization
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
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The common HAL driver contains a set of generic and common APIs that can be
    used by the PPP peripheral drivers and the user to start using the HAL.
    [..]
    The HAL contains two APIs' categories:
         (+) Common HAL APIs
         (+) Services HAL APIs

  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @defgroup HAL HAL
  * @brief HAL module driver
  * @{
  */

#ifdef HAL_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup HAL_Private_Defines HAL Private Defines
  * @{
  */
/**
  * @brief STM32U5xx HAL Driver version number 1.6.2
   */
#define __STM32U5xx_HAL_VERSION_MAIN   (0x01UL) /*!< [31:24] main version */
#define __STM32U5xx_HAL_VERSION_SUB1   (0x06UL) /*!< [23:16] sub1 version */
#define __STM32U5xx_HAL_VERSION_SUB2   (0x02UL) /*!< [15:8]  sub2 version */
#define __STM32U5xx_HAL_VERSION_RC     (0x00UL) /*!< [7:0]  release candidate */
#define __STM32U5xx_HAL_VERSION         ((__STM32U5xx_HAL_VERSION_MAIN << 24U)\
                                         |(__STM32U5xx_HAL_VERSION_SUB1 << 16U)\
                                         |(__STM32U5xx_HAL_VERSION_SUB2 << 8U )\
                                         |(__STM32U5xx_HAL_VERSION_RC))

#define VREFBUF_TIMEOUT_VALUE           10U   /* 10 ms (to be confirmed) */
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/

/** @defgroup HAL_Exported_Variables HAL Exported Variables
  * @{
  */
__IO uint32_t uwTick;
uint32_t uwTickPrio   = (1UL << __NVIC_PRIO_BITS); /* Invalid PRIO */
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;  /* 1KHz */
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup HAL_Exported_Functions HAL Exported Functions
  * @{
  */

/** @defgroup HAL_Exported_Functions_Group1 HAL Initialization and de-initialization Functions
  *  @brief    Initialization and de-initialization functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initializes the Flash interface the NVIC allocation and initial clock
          configuration. It initializes the systick also when timeout is needed
          and the backup domain when enabled.
      (+) De-Initializes common part of the HAL.
      (+) Configure The time base source to have 1ms time base with a dedicated
          Tick interrupt priority.
        (++) SysTick timer is used by default as source of time base, but user
             can eventually implement his proper time base source (a general purpose
             timer for example or other time source), keeping in mind that Time base
             duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
             handled in milliseconds basis.
        (++) Time base configuration function (HAL_InitTick ()) is called automatically
             at the beginning of the program after reset by HAL_Init() or at any time
             when clock is configured, by HAL_RCC_ClockConfig().
        (++) Source of time base is configured  to generate interrupts at regular
             time intervals. Care must be taken if HAL_Delay() is called from a
             peripheral ISR process, the Tick interrupt line must have higher priority
            (numerically lower) than the peripheral interrupt. Otherwise the caller
            ISR process will be blocked.
       (++) functions affecting time base configurations are declared as __weak
             to make  override possible  in case of other  implementations in user file.
@endverbatim
  * @{
  */

/**
  * @brief  Configure the Flash prefetch, the time base source, NVIC and any required global low
  *         level hardware by calling the HAL_MspInit() callback function to be optionally defined
  *         in user file stm32u5xx_hal_msp.c.
  *
  * @note   HAL_Init() function is called at the beginning of program after reset and before
  *         the clock configuration.
  *
  * @note   In the default implementation the System Timer (SysTick) is used as source of time base.
  *         The SysTick configuration is based on MSI clock, as MSI is the clock
  *         used after a system Reset and the NVIC configuration is set to Priority group 4.
  *         Once done, time base tick starts incrementing: the tick variable counter is incremented
  *         each 1ms in the SysTick_Handler() interrupt handler.
  *
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_Init(void)
{
  /* Configure Flash prefetch */
#if (PREFETCH_ENABLE != 0U)
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif /* PREFETCH_ENABLE */

  /* Set Interrupt Group Priority */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR2 & RCC_CFGR2_HPRE) >> RCC_CFGR2_HPRE_Pos];

  /* Select HCLK as SysTick clock source */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* Use systick as time base source and configure 1ms tick (default clock after Reset is HSI) */
  if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Init the low level hardware */
  HAL_MspInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  This function de-Initializes common part of the HAL and stops the systick.
  *         This function is optional.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DeInit(void)
{
  /* Reset of all peripherals */
  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();

  __HAL_RCC_AHB2_FORCE_RESET();
  __HAL_RCC_AHB2_RELEASE_RESET();

  __HAL_RCC_AHB3_FORCE_RESET();
  __HAL_RCC_AHB3_RELEASE_RESET();

  /* De-Init the low level hardware */
  HAL_MspDeInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the MSP.
  * @retval None
  */
__weak void HAL_MspInit(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes the MSP.
  * @retval None
  */
__weak void HAL_MspDeInit(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief This function configures the source of the time base.
  *        The time source is configured to have 1ms time base with a dedicated
  *        Tick interrupt priority.
  * @note This function is called  automatically at the beginning of program after
  *       reset by HAL_Init() or at any time when clock is reconfigured  by HAL_RCC_ClockConfig().
  * @note In the default implementation, SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals.
  *       Care must be taken if HAL_Delay() is called from a peripheral ISR process,
  *       The SysTick interrupt must have higher priority (numerically lower)
  *       than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
  *       The function is declared as __weak  to be overwritten  in case of other
  *       implementation  in user file.
  * @param TickPriority: Tick interrupt priority.
  * @retval HAL status
  */
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  uint32_t ticknumber = 0U;
  uint32_t systicksel;

  /* Check uwTickFreq for MisraC 2012 (even if uwTickFreq is a enum type that don't take the value zero)*/
  if ((uint32_t)uwTickFreq == 0UL)
  {
    return HAL_ERROR;
  }

  /* Check Clock source to calculate the tickNumber */
  if (READ_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk) == SysTick_CTRL_CLKSOURCE_Msk)
  {
    /* HCLK selected as SysTick clock source */
    ticknumber = SystemCoreClock / (1000UL / (uint32_t)uwTickFreq);
  }
  else
  {
    systicksel = HAL_SYSTICK_GetCLKSourceConfig();
    switch (systicksel)
    {
      /* HCLK_DIV8 selected as SysTick clock source */
      case SYSTICK_CLKSOURCE_HCLK_DIV8:
        /* Calculate tick value */
        ticknumber = (SystemCoreClock / (8000UL / (uint32_t)uwTickFreq));
        break;
      /* LSI selected as SysTick clock source */
      case SYSTICK_CLKSOURCE_LSI:
        /* Calculate tick value */
        ticknumber = (LSI_VALUE / (1000UL / (uint32_t)uwTickFreq));
        break;
      /* LSE selected as SysTick clock source */
      case SYSTICK_CLKSOURCE_LSE:
        /* Calculate tick value */
        ticknumber = (LSE_VALUE / (1000UL / (uint32_t)uwTickFreq));
        break;
      default:
        /* Nothing to do */
        break;
    }
  }

  /* Configure the SysTick to have interrupt in 1ms time basis*/
  if (HAL_SYSTICK_Config(ticknumber) > 0U)
  {
    return HAL_ERROR;
  }

  /* Configure the SysTick IRQ priority */
  HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
  uwTickPrio = TickPriority;

  /* Return function status */
  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group2 HAL Control functions
  *  @brief    HAL Control functions
  *
@verbatim
 ===============================================================================
                      ##### HAL Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Provide a tick value in millisecond
      (+) Provide a blocking delay in millisecond
      (+) Suspend the time base source interrupt
      (+) Resume the time base source interrupt
      (+) Get the HAL API driver version
      (+) Get the device identifier
      (+) Get the device revision identifier
      (+) Enable/Disable Debug module during SLEEP mode
      (+) Enable/Disable Debug module during STOP mode
      (+) Enable/Disable Debug module during STANDBY mode

@endverbatim
  * @{
  */

/**
  * @brief This function is called to increment a global variable "uwTick"
  *        used as application time base.
  * @note In the default implementation, this variable is incremented each 1ms
  *       in SysTick ISR.
  * @note This function is declared as __weak to be overwritten in case of other
  *      implementations in user file.
  * @retval None
  */
__weak void HAL_IncTick(void)
{
  uwTick += (uint32_t)uwTickFreq;
}

/**
  * @brief Provides a tick value in millisecond.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval tick value
  */
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}

/**
  * @brief This function returns a tick priority.
  * @retval tick priority
  */
uint32_t HAL_GetTickPrio(void)
{
  return uwTickPrio;
}

/**
  * @brief Set new tick Freq.
  * @retval Status
  */
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq)
{
  HAL_StatusTypeDef status  = HAL_OK;
  HAL_TickFreqTypeDef prevTickFreq;

  assert_param(IS_TICKFREQ(Freq));

  if (uwTickFreq != Freq)
  {

    /* Back up uwTickFreq frequency */
    prevTickFreq = uwTickFreq;

    /* Update uwTickFreq global variable used by HAL_InitTick() */
    uwTickFreq = Freq;

    /* Apply the new tick Freq  */
    status = HAL_InitTick(uwTickPrio);
    if (status != HAL_OK)
    {
      /* Restore previous tick frequency */
      uwTickFreq = prevTickFreq;
    }
  }

  return status;
}

/**
  * @brief Return tick frequency.
  * @retval Tick frequency.
  *         Value of @ref HAL_TickFreqTypeDef.
  */
HAL_TickFreqTypeDef HAL_GetTickFreq(void)
{
  return uwTickFreq;
}

/**
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @param Delay  specifies the delay time length, in milliseconds.
  * @retval None
  */
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}

/**
  * @brief Suspend Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once HAL_SuspendTick()
  *       is called, the SysTick interrupt will be disabled and so Tick increment
  *       is suspended.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval None
  */
__weak void HAL_SuspendTick(void)
{
  /* Disable SysTick Interrupt */
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

/**
  * @brief Resume Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once HAL_ResumeTick()
  *       is called, the SysTick interrupt will be enabled and so Tick increment
  *       is resumed.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval None
  */
__weak void HAL_ResumeTick(void)
{
  /* Enable SysTick Interrupt */
  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}

/**
  * @brief  Returns the HAL revision
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t HAL_GetHalVersion(void)
{
  return __STM32U5xx_HAL_VERSION;
}

/**
  * @brief  Returns the device revision identifier.
  * @retval Device revision identifier
  */
uint32_t HAL_GetREVID(void)
{
  return ((DBGMCU->IDCODE & DBGMCU_IDCODE_REV_ID) >> 16);
}

/**
  * @brief  Returns the device identifier.
  * @retval Device identifier
  */
uint32_t HAL_GetDEVID(void)
{
  return (DBGMCU->IDCODE & DBGMCU_IDCODE_DEV_ID);
}

/**
  * @brief  Return the first word of the unique device identifier (UID based on 96 bits)
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw0(void)
{
  return (READ_REG(*((uint32_t *)UID_BASE)));
}

/**
  * @brief  Return the second word of the unique device identifier (UID based on 96 bits)
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw1(void)
{
  return (READ_REG(*((uint32_t *)(UID_BASE + 4U))));
}

/**
  * @brief  Return the third word of the unique device identifier (UID based on 96 bits)
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw2(void)
{
  return (READ_REG(*((uint32_t *)(UID_BASE + 8U))));
}

/**
  * @}
  */


/** @defgroup HAL_Exported_Functions_Group3 HAL Debug functions
  *  @brief    HAL Debug functions
  *
@verbatim
 ===============================================================================
                      ##### HAL Debug functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Enable/Disable Debug module during STOP0/STOP1/STOP2 modes
      (+) Enable/Disable Debug module during STANDBY mode

@endverbatim
  * @{
  */

/**
  * @brief  Enable the Debug Module during STOP0/STOP1/STOP2 modes.
  * @retval None
  */
void HAL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

/**
  * @brief  Disable the Debug Module during STOP0/STOP1/STOP2 modes.
  * @retval None
  */
void HAL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

/**
  * @brief  Enable the Debug Module during STANDBY mode.
  * @retval None
  */
void HAL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

/**
  * @brief  Disable the Debug Module during STANDBY mode.
  * @retval None
  */
void HAL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group4 HAL SYSCFG configuration functions
  *  @brief    HAL SYSCFG configuration functions
  *
@verbatim
 ===============================================================================
                      ##### HAL SYSCFG configuration functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Configure the Voltage reference buffer
      (+) Enable/Disable the Voltage reference buffer
      (+) Enable/Disable the I/O analog switch voltage booster

@endverbatim
  * @{
  */

/**
  * @brief Configure the internal voltage reference buffer voltage scale.
  * @param  VoltageScaling: specifies the output voltage to achieve
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_VREFBUF_VOLTAGE_SCALE0: VREF_OUT1 around 1.5 V.
  *                                                This requires VDDA equal to or higher than 1.8 V.
  *            @arg SYSCFG_VREFBUF_VOLTAGE_SCALE1: VREF_OUT1 around 1.8 V.
  *                                                This requires VDDA equal to or higher than 2.1 V.
  *            @arg SYSCFG_VREFBUF_VOLTAGE_SCALE2: VREF_OUT1 around 2.048 V.
  *                                                This requires VDDA equal to or higher than 2.4 V.
  *            @arg SYSCFG_VREFBUF_VOLTAGE_SCALE3: VREF_OUT1 around 2.5 V.
  *                                                This requires VDDA equal to or higher than 2.8 V.
  * @retval None
  */
void HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_VREFBUF_VOLTAGE_SCALE(VoltageScaling));

  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_VRS, VoltageScaling);
}

/**
  * @brief Configure the internal voltage reference buffer high impedance mode.
  * @param  Mode: specifies the high impedance mode
  *          This parameter can be one of the following values:
  *            @arg SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE: VREF+ pin is internally connect to VREFINT output.
  *            @arg SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE: VREF+ pin is high impedance.
  * @retval None
  */
void HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE(Mode));

  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_HIZ, Mode);
}

/**
  * @brief  Tune the Internal Voltage Reference buffer (VREFBUF).
  * @retval None
  */
void HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_VREFBUF_TRIMMING(TrimmingValue));

  MODIFY_REG(VREFBUF->CCR, VREFBUF_CCR_TRIM, TrimmingValue);
}

/**
  * @brief  Enable the Internal Voltage Reference buffer (VREFBUF).
  * @retval HAL_OK/HAL_TIMEOUT
  */
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void)
{
  uint32_t  tickstart;

  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);

  /* Get Start Tick*/
  tickstart = HAL_GetTick();

  /* Wait for VRR bit  */
  while (READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRR) == 0UL)
  {
    if ((HAL_GetTick() - tickstart) > VREFBUF_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  return HAL_OK;
}

/**
  * @brief  Disable the Internal Voltage Reference buffer (VREFBUF).
  *
  * @retval None
  */
void HAL_SYSCFG_DisableVREFBUF(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}

/**
  * @brief  Enable the I/O analog switch voltage booster
  *
  * @retval None
  */
void HAL_SYSCFG_EnableIOAnalogBooster(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

/**
  * @brief  Disable the I/O analog switch voltage booster
  *
  * @retval None
  */
void HAL_SYSCFG_DisableIOAnalogBooster(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

/**
  * @brief  Enable the I/O analog switch voltage selection
  *
  * @retval None
  */
void HAL_SYSCFG_EnableIOAnalogVoltageSelection(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_ANASWVDD);
}

/**
  * @brief  Disable the I/O analog switch voltage selection
  *
  * @retval None
  */
void HAL_SYSCFG_DisableIOAnalogVoltageSelection(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_ANASWVDD);
}

#if defined(SYSCFG_CFGR1_ENDCAP)
/**
  * @brief  Set decoupling capacitance on HSPI supply.
  * @rmtoll SYSCFG_CFGR1   ENDCAP   HAL_SYSCFG_SetHSPIDecouplingCapacitance
  * @param  Capacitance This parameter can be one of the following values:
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_OFF
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_1_DIV_3
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_2_DIV_3
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_FULL
  * @retval None
  */
void HAL_SYSCFG_SetHSPIDecouplingCapacitance(uint32_t Capacitance)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_DECOUPLING_CAPACITANCE(Capacitance));

  MODIFY_REG(SYSCFG->CFGR1, SYSCFG_CFGR1_ENDCAP, Capacitance);
}

/**
  * @brief  Get decoupling capacitance on HSPI supply.
  * @rmtoll SYSCFG_CFGR1   ENDCAP   HAL_SYSCFG_GetHSPIDecouplingCapacitance
  * @retval Returned value can be one of the following values:
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_OFF
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_1_DIV_3
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_2_DIV_3
  *         @arg @ref SYSCFG_HSPI_CAPACITANCE_FULL
  */
uint32_t HAL_SYSCFG_GetHSPIDecouplingCapacitance(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_ENDCAP));
}
#endif /* SYSCFG_CFGR1_ENDCAP */

#if defined(SYSCFG_CFGR1_SRAMCACHED)
/**
  * @brief  Enable the Cacheability of internal SRAMx by DCACHE2
  *
  * @retval None
  */
void HAL_SYSCFG_EnableSRAMCached(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_SRAMCACHED);
}

/**
  * @brief  Disable the Cacheability of internal SRAMx by DCACHE2
  *
  * @retval None
  */
void HAL_SYSCFG_DisableSRAMCached(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_SRAMCACHED);
}
#endif /* SYSCFG_CFGR1_SRAMCACHED */

/**
  * @brief  Enable the Compensation Cell of GPIO supplied by VDD
  * @rmtoll CCCSR   EN1    HAL_SYSCFG_EnableVddCompensationCell
  * @note   The vdd compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
void HAL_SYSCFG_EnableVddCompensationCell(void)
{
  SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN1);
}

/**
  * @brief  Enable the Compensation Cell of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   EN2    HAL_SYSCFG_EnableVddIO2CompensationCell
  * @note   The Vdd I/O compensation cell can be used only when the device supply
  *         voltage ranges from 1.08 to 3.6 V
  * @retval None
  */
void HAL_SYSCFG_EnableVddIO2CompensationCell(void)
{
  SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN2);
}

#if defined(SYSCFG_CCCSR_EN3)
/**
  * @brief  Enable the Compensation Cell of HSPI IO supplied by VDD
  * @rmtoll CCCSR   EN3    HAL_SYSCFG_EnableVddHSPICompensationCell
  * @retval None
  */
void HAL_SYSCFG_EnableVddHSPICompensationCell(void)
{
  SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN3);
}
#endif /* SYSCFG_CCCSR_EN3 */

/**
  * @brief  Disable the Compensation Cell of GPIO supplied by VDD
  * @rmtoll CCCSR   EN1    HAL_SYSCFG_DisableVddCompensationCell
  * @note   The Vdd compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
void HAL_SYSCFG_DisableVddCompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN1);
}

/**
  * @brief  Disable the Compensation Cell of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   EN2    HAL_SYSCFG_DisableVddIO2CompensationCell
  * @note   The Vdd I/O compensation cell can be used only when the device supply
  *         voltage ranges from 1.08 to 3.6 V
  * @retval None
  */
void HAL_SYSCFG_DisableVddIO2CompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN2);
}

#if defined(SYSCFG_CCCSR_EN3)
/**
  * @brief  Disable the Compensation Cell of HSPI IO supplied by VDD
  * @rmtoll CCCSR   EN3    HAL_SYSCFG_DisableVddHSPICompensationCell
  * @retval None
  */
void HAL_SYSCFG_DisableVddHSPICompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN3);
}
#endif /* SYSCFG_CCCSR_EN3 */
/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group5 HAL SYSCFG lock management functions
  *  @brief SYSCFG lock management functions.
  *
@verbatim
 ===============================================================================
                       ##### SYSCFG lock functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Lock the SYSCFG item(s).
  * @note   Setting lock(s) depends on privilege mode in secure/non-secure code
  *         Lock(s) cleared only at system reset
  * @param  Item Item(s) to set lock on.
  *         This parameter can be a combination of @ref SYSCFG_Lock_items
  * @retval None
  */
void HAL_SYSCFG_Lock(uint32_t Item)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_LOCK_ITEMS(Item));

  /* Privilege secure/non-secure locks */
  SYSCFG->CNSLCKR = (0xFFFFU & Item);  /* non-secure lock item in 16 lowest bits */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  /* Privilege secure only locks */
  SYSCFG->CSLCKR = ((0xFFFF0000U & Item) >> 16U);  /* Secure-only lock item in 16 highest bits */
#endif /* __ARM_FEATURE_CMSE */
}

/**
  * @brief  Get the lock state of SYSCFG item.
  * @note   Getting lock(s) depends on privilege mode in secure/non-secure code
  * @param  pItem pointer to return locked items
  *         the return value can be a combination of @ref SYSCFG_Lock_items
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SYSCFG_GetLock(uint32_t *pItem)
{
  uint32_t tmp_lock;

  /* Check null pointer */
  if (pItem == NULL)
  {
    return HAL_ERROR;
  }

  /* Get the non-secure lock state */
  tmp_lock = SYSCFG->CNSLCKR;

  /* Get the secure lock state in secure code */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  tmp_lock |= (SYSCFG->CSLCKR << 16U);
#endif /* __ARM_FEATURE_CMSE */

  /* Return overall lock status */
  *pItem = tmp_lock;

  return HAL_OK;
}

/**
  * @}
  */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/** @defgroup HAL_Exported_Functions_Group6 HAL SYSCFG attributes management functions
  *  @brief SYSCFG attributes management functions.
  *
@verbatim
 ===============================================================================
                       ##### SYSCFG attributes functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Configure the SYSCFG item attribute(s).
  * @note   Available attributes are to secure SYSCFG items, so this function is
  *         only available in secure
  * @param  Item Item(s) to set attributes on.
  *         This parameter can be a one or a combination of @ref SYSCFG_Attributes_items
  * @param  Attributes  specifies the secure/non-secure attributes.
  * @retval None
  */
void HAL_SYSCFG_ConfigAttributes(uint32_t Item, uint32_t Attributes)
{
  uint32_t tmp;

  /* Check the parameters */
  assert_param(IS_SYSCFG_ITEMS_ATTRIBUTES(Item));
  assert_param(IS_SYSCFG_ATTRIBUTES(Attributes));

  tmp = SYSCFG_S->SECCFGR;

  /* Set or reset Item */
  if ((Attributes & SYSCFG_SEC) != 0x00U)
  {
    tmp |= Item;
  }
  else
  {
    tmp &= ~Item;
  }

  /* Set secure attributes */
  SYSCFG_S->SECCFGR = tmp;
}

/**
  * @brief  Get the attribute of a SYSCFG item.
  * @note   Available attributes are to secure SYSCFG items, so this function is
  *         only available in secure
  * @param  Item Single item to get secure/non-secure attribute from.
  * @param  pAttributes pointer to return the attribute.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SYSCFG_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes)
{
  /* Check null pointer */
  if (pAttributes == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_SYSCFG_ITEMS_ATTRIBUTES(Item));

  /* Get the secure attribute state */
  if ((SYSCFG_S->SECCFGR & Item) != 0U)
  {
    *pAttributes = SYSCFG_SEC;
  }
  else
  {
    *pAttributes = SYSCFG_NSEC;
  }

  return HAL_OK;
}

/**
  * @}
  */

#endif /* __ARM_FEATURE_CMSE */

#ifdef SYSCFG_OTGHSPHYCR_EN
/**
  * @brief  Enable the OTG PHY .
  * @param  OTGPHYConfig Defines the OTG PHY configuration.
            This parameter can be one of @ref SYSCFG_OTG_PHY_Enable
  * @retval None
  */
void HAL_SYSCFG_EnableOTGPHY(uint32_t OTGPHYConfig)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_CONFIG(OTGPHYConfig));

  MODIFY_REG(SYSCFG->OTGHSPHYCR, SYSCFG_OTGHSPHYCR_EN, OTGPHYConfig);
}

/**
  * @brief  Set the OTG PHY  Power Down config.
  * @param  PowerDownConfig Defines the OTG PHY Power down configuration.
            This parameter can be one of @ref SYSCFG_OTG_PHY_PowerDown
  * @retval None
  */
void HAL_SYSCFG_SetOTGPHYPowerDownConfig(uint32_t PowerDownConfig)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_POWERDOWN_CONFIG(PowerDownConfig));

  MODIFY_REG(SYSCFG->OTGHSPHYCR, SYSCFG_OTGHSPHYCR_PDCTRL, PowerDownConfig);
}

/**
  * @brief  Set the OTG PHY reference clock selection.
  * @param  RefClkSelection Defines the OTG PHY reference clock selection.
            This parameter can be one of the @ref SYSCFG_OTG_PHY_RefenceClockSelection
  * @retval None
  */
void HAL_SYSCFG_SetOTGPHYReferenceClockSelection(uint32_t RefClkSelection)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_REFERENCE_CLOCK(RefClkSelection));

  MODIFY_REG(SYSCFG->OTGHSPHYCR, SYSCFG_OTGHSPHYCR_CLKSEL, RefClkSelection);
}

/**
  * @brief  Set the OTG PHY Disconnect Threshold.
  * @param  DisconnectThreshold Defines the voltage level for the threshold used to detect a disconnect event.
            This parameter can be one of the @ref SYSCFG_OTG_PHYTUNER_DisconnectThreshold
  * @retval None
  */

void HAL_SYSCFG_SetOTGPHYDisconnectThreshold(uint32_t DisconnectThreshold)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_DISCONNECT(DisconnectThreshold));

  MODIFY_REG(SYSCFG->OTGHSPHYTUNER2, SYSCFG_OTGHSPHYTUNER2_COMPDISTUNE, DisconnectThreshold);
}

/**
  * @brief  Adjust the voltage level for the threshold used to detect valid high speed data.
  * @param  SquelchThreshold Defines the voltage level.
            This parameter can be onez of the @ref SYSCFG_OTG_PHYTUNER_SquelchThreshold

  * @retval None
  */

void HAL_SYSCFG_SetOTGPHYSquelchThreshold(uint32_t SquelchThreshold)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_SQUELCH(SquelchThreshold));

  MODIFY_REG(SYSCFG->OTGHSPHYTUNER2, SYSCFG_OTGHSPHYTUNER2_SQRXTUNE, SquelchThreshold);
}

/**
  * @brief  Set the OTG PHY Current config.
  * @param  PreemphasisCurrent Defines the current configuration.
            This parameter can be one of the @ref SYSCFG_OTG_PHYTUNER_PreemphasisCurrent

  * @retval None
  */

void HAL_SYSCFG_SetOTGPHYPreemphasisCurrent(uint32_t PreemphasisCurrent)
{
  /* Check the parameter */
  assert_param(IS_SYSCFG_OTGPHY_PREEMPHASIS(PreemphasisCurrent));

  MODIFY_REG(SYSCFG->OTGHSPHYTUNER2, SYSCFG_OTGHSPHYTUNER2_TXPREEMPAMPTUNE, PreemphasisCurrent);
}

#endif /* SYSCFG_OTGHSPHYCR_EN */

/**
  * @}
  */

#endif /* HAL_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/**
  ******************************************************************************
  * @file    boot_hal_bl2.c
  * @author  MCD Application Team
  * @brief   This file contains  mcuboot stm32u5xx hardware specific implementation
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "boot_hal_cfg.h"
#include "boot_hal.h"
#ifdef CRYPTO_HW_ACCELERATOR
#include "crypto_hw.h"
#endif
#include "mcuboot_config/mcuboot_config.h"
#if defined(MCUBOOT_DOUBLE_SIGN_VERIF)
#include "boot_hal_imagevalid.h"
#endif
#if defined(FLOW_CONTROL)
#include "boot_hal_flowcontrol.h"
#else
/* dummy definitions */
#define FLOW_CONTROL_STEP(C,B,A) ((void)0)
#define FLOW_CONTROL_CHECK(B,A) ((void)0)
#define FLOW_STAGE_CFG          (0x0)
#define FLOW_STAGE_CHK          (0x0)
#endif
#include "uart_stdout.h"
#include "low_level_security.h"
#ifdef BL2_DATA
#include "tfm_bl2_shared_data.h"
#endif
#include "bootutil/boot_record.h"
#include "target_cfg.h"
#include "tfm_hal_device_header.h"
#include "Driver_Flash.h"
#include "region_defs.h"
#include "low_level_rng.h"
#ifdef MCUBOOT_EXT_LOADER
#include "bootutil/crypto/sha256.h"
#define BUTTON_PORT                       GPIOC
#define BUTTON_CLK_ENABLE                 __HAL_RCC_GPIOC_CLK_ENABLE()
#define BUTTON_PIN                        GPIO_PIN_13
#endif /* MCUBOOT_EXT_LOADER */
#include "template/flash_otp_nv_counters_backend.h"
#include "nv_counters.h"

#ifdef BL2_OTP_AREA_BASE
extern  struct flash_otp_nv_counters_region_t otp_stm_provision;
#define OTP_KEEP otp_stm_provision.init_value
#else
#define OTP_KEEP (0)
#endif

#ifdef BL2_NVM_AREA_BASE
extern  struct nv_counters_t nvm_init;
#define NVM_KEEP nvm_init.init_value
#else
#define NVM_KEEP (0)
#endif

#ifdef BL2_NVMCNT_AREA_BASE
extern  struct nv_counters_t nvmcnt_init;
#define NVMCNT_KEEP nvmcnt_init.init_value
#else
#define NVMCNT_KEEP (0)
#endif

extern HAL_StatusTypeDef HAL_ICACHE_Invalidate(void);
extern int  LL_SECU_UpdateRunTimeProtections(void);
extern HAL_StatusTypeDef HAL_ICACHE_Enable(void);
extern void LL_SECU_ApplyRunTimeProtections(void);
extern void LL_SECU_CheckStaticProtections(void);
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;


#if defined(MCUBOOT_DOUBLE_SIGN_VERIF)
/* Global variables to memorize images validation status */
#if (MCUBOOT_IMAGE_NUMBER == 1)
uint8_t ImageValidStatus[MCUBOOT_IMAGE_NUMBER] = {IMAGE_INVALID};
#elif (MCUBOOT_IMAGE_NUMBER == 2)
uint8_t ImageValidStatus[MCUBOOT_IMAGE_NUMBER] = {IMAGE_INVALID, IMAGE_INVALID};
#else
#error "MCUBOOT_IMAGE_NUMBER not supported"
#endif /* (MCUBOOT_IMAGE_NUMBER == 1)  */
uint8_t ImageValidIndex = 0;
uint8_t ImageValidEnable = 0;
#endif /* MCUBOOT_DOUBLE_SIGN_VERIF */

#if defined(FLOW_CONTROL)
/* Global variable for Flow Control state */
volatile uint32_t uFlowProtectValue = FLOW_CTRL_INIT_VALUE;
#endif /* FLOW_CONTROL */
volatile uint32_t uFlowStage = FLOW_STAGE_CFG;

/*
#define ICACHE_MONITOR
*/
#if defined(ICACHE_MONITOR)
#define ICACHE_MONITOR_PRINT() printf("icache monitor - Hit: %x, Miss: %x\r\n", \
                                      HAL_ICACHE_Monitor_GetHitValue(), HAL_ICACHE_Monitor_GetMissValue());
#else
#define ICACHE_MONITOR_PRINT()
#endif /* ICACHE_MONITOR */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup BOOT_HAL_Private_Functions  Private Functions
  * @{
  */
#ifdef MCUBOOT_EXT_LOADER
__NO_RETURN void execute_loader(void);
#endif /* MCUBOOT_EXT_LOADER */
void boot_clean_ns_ram_area(void);
__attribute__((naked)) void boot_jump_to_ns_image(uint32_t reset_handler_addr);
void icache_init(void);
/**
  * @}
  */
#ifdef MCUBOOT_EXT_LOADER
/**
  * @brief This function manage the jump to Local loader application.
  * @note
  * @retval void
  */
void boot_platform_noimage(void)
{
    /* Check Flow control for dynamic protections */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_2);
    uFlowStage = FLOW_STAGE_CFG;
    /* unsecure all pin configuration ,non secure loader is initializing Octospi pin*/
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    GPIOA_S->SECCFGR = 0x0;
    GPIOB_S->SECCFGR = 0x0;
    GPIOC_S->SECCFGR = 0x0;
    GPIOD_S->SECCFGR = 0x0;
    GPIOE_S->SECCFGR = 0x0;
    GPIOF_S->SECCFGR = 0x0;
    GPIOG_S->SECCFGR = 0x0;
    GPIOH_S->SECCFGR = 0x0;
#if defined(MCUBOOT_PRIMARY_ONLY)
    /* loader code is set secure after control being set successfully */
    /* MPU allowing execution of this area is set after HDP activation */
    LL_SECU_SetLoaderCodeSecure();

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_3_L);
    uFlowStage = FLOW_STAGE_CHK;

    /* Second function call to resist to basic hardware attacks */
    LL_SECU_SetLoaderCodeSecure();
#endif /* MCUBOOT_PRIMARY_ONLY */
    execute_loader();
}

/* Place code in a specific section */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_NoHdp_Code"
#else
__attribute__((section(".BL2_NoHdp_Code")))
#endif /* __ICCARM__ */
/**
  * @brief This function activates the protection before executing local loader.
  * @note
  * @retval void
  */
void execute_loader(void)
{
#if defined(MCUBOOT_PRIMARY_ONLY)
    static struct boot_arm_vector_table *vt = (struct boot_arm_vector_table *)LOADER_S_CODE_START;

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_4_L);
    uFlowStage = FLOW_STAGE_CFG;

    /* Update run time protections for application execution */
    LL_SECU_UpdateLoaderRunTimeProtections();

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_5_L);
    uFlowStage = FLOW_STAGE_CHK;

    /* Second function call to resist to basic hardware attacks */
    LL_SECU_UpdateLoaderRunTimeProtections();

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_6_L);

    /* set the secure vector */
    SCB->VTOR = (uint32_t)LOADER_S_CODE_START;

    /* Lock Secure Vector Table */
    SYSCFG->CSLCKR |= SYSCFG_CSLCKR_LOCKSVTAIRCR;

    /*  change stack limit  */
    __set_MSPLIM(0);
    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSP(vt->msp);
    __DSB();
    __ISB();
    boot_stm_jump_to_next_image((uint32_t)&boot_stm_jump_to_next_image, vt->reset);
#else
    static struct boot_arm_vector_table *vt = (struct boot_arm_vector_table *)LOADER_NS_CODE_START;

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_4_L);
    uFlowStage = FLOW_STAGE_CFG;

    /* Update run time protections for application execution */
    LL_SECU_UpdateLoaderRunTimeProtections();

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_5_L);
    uFlowStage = FLOW_STAGE_CHK;

    /* Second function call to resist to basic hardware attacks */
    LL_SECU_UpdateLoaderRunTimeProtections();

    /* Check Flow control */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_6_L);

    /* set the vector */
    SCB_NS->VTOR = LOADER_NS_CODE_START;

    /* Lock Secure Vector Table */
    SYSCFG->CSLCKR |= SYSCFG_CSLCKR_LOCKSVTAIRCR;

    /* Set non-secure main stack (MSP_NS) */
    __TZ_set_MSP_NS((*(uint32_t *)LOADER_NS_CODE_START));
    /* the function erase all internal SRAM , and unsecure all SRAM to adapt to any non secure loader mapping */
    boot_stm_jump_to_next_image((uint32_t)&boot_jump_to_ns_image,vt->reset);
#endif /* defined(MCUBOOT_PRIMARY_ONLY) */

    /* Avoid compiler to pop registers after having changed MSP */
#if !defined(__ICCARM__)
    __builtin_unreachable();
#endif /* defined(__ICCARM__) */
}

/* Continue to place code in a specific section */
#if defined(__GNUC__)
__attribute__((section(".BL2_NoHdp_Code")))
#endif /* __GNUC__ */

/*!
 * \brief Chain-loading the next image in the boot sequence.
 *
 * This function calls the Reset_Handler of the next image in the boot sequence,
 * usually it is the secure firmware. Before passing the execution to next image
 * there is conditional rule to remove the secrets from the memory. This must be
 * done if the following conditions are satisfied:
 *  - Memory is shared between SW components at different stages of the trusted
 *    boot process.
 *  - There are secrets in the memory: KDF parameter, symmetric key,
 *    manufacturer sensitive code/data, etc.
 */
__attribute__((naked)) void boot_jump_to_ns_image(uint32_t reset_handler_addr)
{
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified                 \n"
#endif /* !defined(__ICCARM__) */
        "mov     r7, r0                  \n"
        "bl      boot_clean_ns_ram_area  \n" /* Clean all RAM and unsecure all before jump */
        "movs    r0, #0                  \n" /* Clear registers: R0-R12, */
        "mov     r1, r0                  \n" /* except R7 */
        "mov     r2, r0                  \n"
        "mov     r3, r0                  \n"
        "mov     r4, r0                  \n"
        "mov     r5, r0                  \n"
        "mov     r6, r0                  \n"
        "mov     r8, r0                  \n"
        "mov     r9, r0                  \n"
        "mov     r10, r0                 \n"
        "mov     r11, r0                 \n"
        "mov     r12, r0                 \n"
        "mov     lr,  r0                 \n"
        "bic.w   r7, r7, #1              \n"
        "blxns   r7                      \n" /* Jump to non secure Reset_handler */
    );
}
/* Stop placing data in specified section */
#if defined(__ICCARM__)
#pragma default_function_attributes =
#endif /* __ICCARM__ */

#endif /* MCUBOOT_EXT_LOADER */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_NoHdp_Code"
#elif defined(__CC_ARM)
#pragma arm section code = ".BL2_NoHdp_Code"
#else
__attribute__((section(".BL2_NoHdp_Code")))
#endif /* __ICCARM__ */
__attribute__((naked)) void boot_stm_jump_to_next_image(uint32_t boot_jump_addr, uint32_t reset_handler_addr)
{
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified                 \n"
#endif
        "mov     r7, r0                  \n"
        "mov     r8, r1                  \n"
        "bl      boot_clear_bl2_ram_area \n" /* Clear RAM before jump */
        "movs    r0, #0                  \n" /* Clear registers: R0-R12, */
        "mov     r1, r0                  \n" /* except R7 */
        "mov     r2, r0                  \n"
        "mov     r3, r0                  \n"
        "mov     r4, r0                  \n"
        "mov     r5, r0                  \n"
        "mov     r6, r0                  \n"
        "mov     r9, r0                  \n"
        "mov     r10, r0                 \n"
        "mov     r11, r0                 \n"
        "mov     r12, r0                 \n"
        "mov     lr,  r0                 \n"
        "mov     r0, r8                  \n"
        "mov     r8, r1                  \n"
        "bx      r7                      \n" /* Jump to Reset_handler */
    );
}
/* Stop placing data in specified section */
#if defined(__ICCARM__)
#pragma default_function_attributes =
#elif defined(__CC_ARM)
#pragma arm section code
#endif /* __ICCARM__ */
/* Place code in a specific section */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_NoHdp_Code"
#else
__attribute__((section(".BL2_NoHdp_Code")))
#endif /* __ICCARM__ */
/**
  * @brief This function manage the jump to secure application.
  * @note
  * @retval void
  */
void boot_platform_start_next_image(struct boot_arm_vector_table *vector)
{
    static struct boot_arm_vector_table *vt;
#if defined(MCUBOOT_DOUBLE_SIGN_VERIF)
    uint32_t image_index;

   (void)fih_delay();
    /* Check again if images have been validated, to resist to basic hw attacks */
    for (image_index = 0; image_index < MCUBOOT_IMAGE_NUMBER; image_index++)
    {
        if (ImageValidStatus[image_index] != IMAGE_VALID)
        {
            BOOT_LOG_ERR("Error while double controlling images validation");
            Error_Handler();
        }
    }
#endif /* MCUBOOT_DOUBLE_SIGN_VERIF */

    /* Check Flow control state */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_2);
    uFlowStage = FLOW_STAGE_CFG;

    /* Copy shared data in SRAM for Secure services */
#ifdef BL2_DATA
    TFM_BL2_CopySharedData();
#endif
    (void)crypto_hw_accelerator_finish();


    RNG_DeInit();

    ICACHE_MONITOR_PRINT()

#ifdef TFM_ICACHE_ENABLE
    /* Invalidate ICache before jumping to application */
    if (HAL_ICACHE_Invalidate() != HAL_OK)
    {
        Error_Handler();
    }
#endif /* ICACHE_ENABLED */
    /* Update run time protections for application execution */
    LL_SECU_UpdateRunTimeProtections();

    /* set the secure vector */
    SCB->VTOR = (uint32_t)vector;

    vt = (struct boot_arm_vector_table *)vector;
    /* Check Flow control state */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_3_A);
    uFlowStage = FLOW_STAGE_CHK;

    /* Double the update of run time protections, to resist to basic hardware attacks */
    LL_SECU_UpdateRunTimeProtections();

    /* Check Flow control for dynamic protections */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_4_A);
    /*  change stack limit  */
    __set_MSPLIM(0);
    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSP(vt->msp);
    __DSB();
    __ISB();

    boot_stm_jump_to_next_image((uint32_t)&boot_stm_jump_to_next_image, vt->reset);
    /* Avoid compiler to pop registers after having changed MSP */
#if !defined(__ICCARM__)
    __builtin_unreachable();
#endif /* defined(__ICCARM__) */
}

/* Continue to place code in a specific section */
#if defined(__GNUC__)
__attribute__((section(".BL2_NoHdp_Code")))

/* Ensure local variables of this function are not placed in RAM but in
 * registers only, even in case of low compile optimization configuration
 * at project side.
 * - IAR: No need to force compile optimization level.
 * - KEIL: Force high compile optimization on per-file basis.
 * - STM32CUBEIDE: Force high compile optimization on function only.
 *  */
#if !defined(__ARMCC_VERSION)
__attribute__((optimize("Os")))
#endif /* !__ARMCC_VERSION */
#endif /* __GNUC__ */

/**
  * @brief This function is called to clear all RAM area before jumping in
  * in Secure application .
  * @note
  * @retval void
  */
void boot_clear_bl2_ram_area(void)
{
    __IO uint32_t *pt = (uint32_t *)BL2_DATA_START;
    uint32_t index;


    for (index = 0; index < (BL2_DATA_SIZE / 4); index++)
    {
        pt[index] = 0;
    }

}

/* Continue to place code in a specific section */
#if defined(__GNUC__)
__attribute__((section(".BL2_NoHdp_Code")))
/* Ensure local variables of this function are not placed in RAM but in
 * registers only, even in case of low compile optimization configuration
 * at project side.
 * - IAR: No need to force compile optimization level.
 * - KEIL: Force high compile optimization on per-file basis.
 * - STM32CUBEIDE: Force high compile optimization on function only.
 *  */
#if !defined(__ARMCC_VERSION)
__attribute__((optimize("Os")))
#endif /* !__ARMCC_VERSION */
#endif /* __GNUC__ */

/**
  * @brief This function is called to clear all RAM area before jumping in
  * in Secure application .
  * @note
  * @retval void
  */
void  boot_clean_ns_ram_area(void)
{
#ifdef TFM_ERROR_HANDLER_NON_SECURE
    __IO uint32_t *pt = (uint32_t *)(SRAM1_BASE + 256);
#else /*  TFM_ERROR_HANDLER_NON_SECURE */
    __IO uint32_t *pt = (uint32_t *)SRAM1_BASE;
#endif /* TFM_ERROR_HANDLER_NON_SECURE */
    uint32_t index;
    /* clean all SRAM1 */
    for (index = 0; index < (_SRAM1_SIZE_MAX / 4); index++)
    {
        pt[index] = 0;
    }
    /* unsecure all SRAM1 */
    for (index = 0; index < 24 ; index++)
    {
        /* assume loader is only in SRAM1 */
        GTZC_MPCBB1_S->SECCFGR[index] = 0;
    }
    pt = (uint32_t *)BL2_DATA_START;
    for (index = 0; index < (BL2_DATA_SIZE / 4); index++)
    {
        pt[index] = 0;
    }
}

/* Stop placing data in specified section */
#if defined(__ICCARM__)
#pragma default_function_attributes =
#endif /* __ICCARM__ */



/**
  * @brief This function configures and enables the ICache.
  * @note
  * @retval execution_status
  */
void icache_init(void)
{
#ifdef ICACHE_MONITOR
    if (HAL_ICACHE_Monitor_Reset(ICACHE_MONITOR_HIT_MISS) != HAL_OK)
    {
        Error_Handler();
    }
    if (HAL_ICACHE_Monitor_Start(ICACHE_MONITOR_HIT_MISS) != HAL_OK)
    {
        Error_Handler();
    }
#endif /* ICACHE_MONITOR */
    ICACHE_MONITOR_PRINT()

    /* Enable ICache */
    if (HAL_ICACHE_Enable() != HAL_OK)
    {
        Error_Handler();
    }
}

/* exported variables --------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @brief  Platform init
  * @param  None
  * @retval status
  */
int32_t boot_platform_init(void)
{
#ifdef MCUBOOT_EXT_LOADER
    GPIO_InitTypeDef GPIO_Init;
#endif /* MCUBOOT_EXT_LOADER */
    /* STM32U5xx HAL library initialization:
         - Systick timer is configured by default as source of time base, but user
               can eventually implement his proper time base source (a general purpose
               timer for example or other time source), keeping in mind that Time base
               duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
               handled in milliseconds basis.
         - Set NVIC Group Priority to 3
         - Low Level Initialization
       */
    /*  Place here to force linker to keep provision and init const */
     __IO uint32_t otp = OTP_KEEP;
     __IO uint32_t nvm = NVM_KEEP;
     __IO uint32_t nvmcnt = NVMCNT_KEEP;
    (void)otp;
    (void)nvm;
    (void)nvmcnt;
    HAL_Init();
#ifdef TFM_DEV_MODE
    /* Init for log */
    stdio_init();
#endif /*  TFM_DEV_MODE */

#ifdef TFM_ICACHE_ENABLE
    /* Configure and enable ICache */
    icache_init();
#endif /* ICACHE_ENABLED */

    /* Initialize RNG */
    if (RNG_Init()){
      BOOT_LOG_ERR("Error while initializing RNG Ip");
      Error_Handler();
    }
    if (crypto_hw_accelerator_init()){
      BOOT_LOG_ERR("Error while initializing HW accelerator Ip");
      Error_Handler();
    }
    /* Start HW randomization */
    fih_delay_init();
    /* Apply Run time Protection */
    LL_SECU_ApplyRunTimeProtections();
    /* Check static protections */
    LL_SECU_CheckStaticProtections();

    /* Check Flow control state */
    FLOW_CONTROL_CHECK(uFlowProtectValue, FLOW_CTRL_STAGE_1);
    uFlowStage = FLOW_STAGE_CHK;
    /* Double protections apply / check to resist to basic fault injections */
    /* Apply Run time Protection */
   (void)fih_delay();
    LL_SECU_ApplyRunTimeProtections();
    /* Check static protections */
    LL_SECU_CheckStaticProtections();
    if (FLASH_DEV_NAME.Initialize(NULL) != ARM_DRIVER_OK)
    {
        BOOT_LOG_ERR("Error while initializing Flash Interface");
        Error_Handler();
    }


#ifdef MCUBOOT_EXT_LOADER
    /* configure Button pin */
    BUTTON_CLK_ENABLE;
    GPIO_Init.Pin       = BUTTON_PIN;
    GPIO_Init.Mode      = 0;
    GPIO_Init.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_Init.Pull      = GPIO_NOPULL;
    GPIO_Init.Alternate = 0;
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_Init);
    /* read pin value */
    if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_SET)
    {
        boot_platform_noimage();
    }
#endif /* MCUBOOT_EXT_LOADER */
    return 0;
}

/**
  * @brief  This function is executed in case of error occurrence.
  *         This function does not return.
  * @param  None
  * @retval None
  */
#ifdef TFM_ERROR_HANDLER_NON_SECURE
/* Place code in a specific section */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_Error_Code"
#else
__attribute__((section(".BL2_Error_Code")))
#endif /* __ICCARM__ */
void Error_Handler(void)
{
#define WHILE_1_OPCODE 0xe7fe
    typedef void (*nsfptr_t)(void) __attribute__((cmse_nonsecure_call));
    nsfptr_t nsfptr = (nsfptr_t)(SRAM1_BASE_NS + 1);
    __IO uint16_t *pt = (uint16_t *)SRAM1_BASE_NS;
    /*  copy while(1) instruction */
    *pt = WHILE_1_OPCODE;
    /* Flush and refill pipeline  */
    __DSB();
    __ISB();
    /*  call non secure while(1) */
    nsfptr();
}
#else /* TFM_ERROR_HANDLER_NON_SECURE */
/* Place code in a specific section */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_Error_Code"
__NO_RETURN void Error_Handler_rdp(void)
#else
__attribute__((section(".BL2_Error_Code")))
void Error_Handler_rdp(void)
#endif
{
    /* it is customizeable */
    /* an infinite loop,  and a reset for single fault injection */
    static __IO int twice = 0;
    while (!twice);
    NVIC_SystemReset();
#if !defined(__ICCARM__)
    /* Avoid bx lr instruction (for fault injection) */
    __builtin_unreachable();
#endif /* defined(__ICCARM__) */
}
/* Place code in a specific section */
#if defined(__ICCARM__)
#pragma default_function_attributes = @ ".BL2_Error_Code"
__NO_RETURN void Error_Handler(void)
#else
__attribute__((section(".BL2_Error_Code")))
void Error_Handler(void)
#endif
{
    /* It is customizeable */
    NVIC_SystemReset();
#if !defined(__ICCARM__)
    /* Avoid bx lr instruction (for fault injection) */
    __builtin_unreachable();
#endif /* defined(__ICCARM__) */
}
#endif /* TFM_ERROR_HANDLER_NON_SECURE */

/* Stop placing data in specified section */
#if defined(__ICCARM__)
#pragma default_function_attributes =
#endif /* __ICCARM__ */

#if defined(__ARMCC_VERSION)
/* reimplement the function to reach Error Handler */
void __aeabi_assert(const char *expr, const char *file, int line)
{
#ifdef TFM_DEV_MODE
    printf("assertion \" %s \" failed: file %s %d\n", expr, file, line);
#endif /*  TFM_DEV_MODE  */
    Error_Handler();
}
#endif  /*  __ARMCC_VERSION */
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    Error_Handler();
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

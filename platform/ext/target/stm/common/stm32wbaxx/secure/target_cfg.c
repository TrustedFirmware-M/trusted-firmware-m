/*
 * Copyright (c) 2018-2024, Arm Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tfm_hal_device_header.h"
#include "target_cfg.h"
/* dummy definitions */
extern volatile uint32_t uFlowStage;
#define FLOW_CONTROL_STEP(C,B,A) ((void)0)
#define FLOW_CONTROL_CHECK(B,A) ((void)0)
#define FLOW_STAGE_CFG          (0x0)
#define FLOW_STAGE_CHK          (0x1)
#include "Driver_MPC.h"
#include "region_defs.h"
#include "tfm_plat_defs.h"
/*  fix me to move to a CMSIS driver */
#include "stm32wbaxx_hal.h"
#include <stdio.h>
#include "region.h"
#ifdef TFM_FIH_PROFILE_ON
#include "fih.h"
#endif

extern void Error_Handler(void);
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

volatile uint32_t uFlowStage;
/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
REGION_DECLARE(Load$$LR$$, LR_VENEER, $$Base);
REGION_DECLARE(Load$$LR$$, LR_VENEER, $$Limit);
REGION_DECLARE(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base);
REGION_DECLARE(Image$$, TFM_APP_RW_STACK_END, $$Base);

#define NON_SECURE_BASE (uint32_t) &REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base)
#define NON_SECURE_LIMIT (uint32_t)(FLASH_BASE_NS + FLASH_TOTAL_SIZE - 1)
#define VENEER_BASE (uint32_t) &REGION_NAME(Load$$LR$$, LR_VENEER, $$Base)
#define VENEER_LIMIT (uint32_t) &REGION_NAME(Load$$LR$$, LR_VENEER, $$Limit)

#define DATA_NPRIV_START (uint32_t) &REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
const struct memory_region_limits memory_regions =
{
  .non_secure_code_start =
  (uint32_t) &REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

  .non_secure_partition_base =
  NON_SECURE_BASE,

  .non_secure_partition_limit =
  NON_SECURE_LIMIT,

  .veneer_base =
  VENEER_BASE,

  .veneer_limit =
  VENEER_LIMIT,
};

#define TFM_NS_REGION_CODE      0
#define TFM_NS_REGION_DATA_1    1
#define TFM_NS_REGION_DATA_2    2
#define TFM_NS_REGION_VENEER    3
#define TFM_NS_REGION_PERIPH_1  4
#define TFM_NS_REGION_PERIPH_2  5

/* Define Peripherals NS address range for the platform */
#define PERIPHERALS_BASE_NS_START (PERIPH_BASE_NS)
#define PERIPHERALS_BASE_NS_END   (0x4FFFFFFF)

const struct sau_cfg_t sau_init_cfg[] = {
    /* Configures SAU regions to be non-secure */
    {
        TFM_NS_REGION_CODE,
        NON_SECURE_BASE,
        NON_SECURE_LIMIT,
        TFM_FALSE,
    },
    {
        TFM_NS_REGION_DATA_1,
        NS_DATA_START,
        NS_DATA_LIMIT,
        TFM_FALSE,
    },
    {
        TFM_NS_REGION_DATA_2,
        SRAM2_BASE_NS,
        (SRAM2_BASE_NS + _SRAM2_SIZE_MAX - 1),
        TFM_FALSE,
    },
    /* Configures veneers region to be non-secure callable */
    {
        TFM_NS_REGION_VENEER,
        VENEER_BASE,
        VENEER_LIMIT,
        TFM_TRUE,
    },
    /* Configure the peripherals space */
    {
        TFM_NS_REGION_PERIPH_1,
        PERIPHERALS_BASE_NS_START,
        PERIPHERALS_BASE_NS_END,
        TFM_FALSE,
    },
    /* Configure the peripherals space 2 to access package information */
    {
        TFM_NS_REGION_PERIPH_2,
        PACKAGE_BASE,
        (PACKAGE_BASE + 0xfff),
        TFM_FALSE,
    },
};
#ifdef TFM_DEV_MODE
static __IO int once=0;
void Error_Handler(void)
{
	/* Reset the system */
    while(once==0);
}
#else
void Error_Handler(void)
{
	/* Reset the system */
    NVIC_SystemReset();
}
#endif

enum tfm_plat_err_t enable_fault_handlers(void)
{
  NVIC_SetPriority(SecureFault_IRQn, 0);
  /* Enables BUS, MEM, USG and Secure faults */
  SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
                | SCB_SHCSR_BUSFAULTENA_Msk
                | SCB_SHCSR_MEMFAULTENA_Msk
                | SCB_SHCSR_SECUREFAULTENA_Msk;
  return TFM_PLAT_ERR_SUCCESS;

}

/*----------------- NVIC interrupt target state to NS configuration ----------*/
enum tfm_plat_err_t nvic_interrupt_target_state_cfg()
{
  /* Target every interrupt to NS; unimplemented interrupts will be WI */
  for (uint8_t i = 0; i < sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0]); i++)
  {
    NVIC->ITNS[i] = 0xFFFFFFFF;
  }
  return TFM_PLAT_ERR_SUCCESS;
}
void system_reset_cfg(void)
{
  /*  fix me : not implemented yet */

}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
enum tfm_plat_err_t nvic_interrupt_enable()
{
  /* Check TAMP_IRQn has highest prio (0) and is enabled  */
  if ((NVIC_GetPriority(TAMP_IRQn) > 0) || !(NVIC_GetEnableIRQ(TAMP_IRQn)))
       return TFM_PLAT_ERR_SYSTEM_ERR;
  /* Fix Priority and Enable interruption handled, other interrupt prio must be above 0 */
  NVIC_SetPriority(GTZC_IRQn, 1);
  NVIC_EnableIRQ(GTZC_IRQn);
  return TFM_PLAT_ERR_SUCCESS;
}
/*----------------- RCC accessible for non secure --------------- */
/*  allow clock configuration from non secure */
void enable_ns_clk_config(void)
{
  /*  fix me : not implemented yet */

}
/*----------------- GPIO Pin mux configuration for non secure --------------- */
/*  set all pin mux to un-secure */
#ifdef TFM_FIH_PROFILE_ON
fih_int pinmux_init_cfg(void)
#else
void pinmux_init_cfg(void)
#endif
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  GPIOA_S->SECCFGR = 0x0;
  GPIOB_S->SECCFGR = 0x0;
  GPIOC_S->SECCFGR = 0x0;
  GPIOD_S->SECCFGR = 0x0;
  GPIOE_S->SECCFGR = 0x0;
  GPIOG_S->SECCFGR = 0x0;
  GPIOH_S->SECCFGR = 0x0;
#ifdef TFM_FIH_PROFILE_ON
  FIH_RET(fih_int_encode(TFM_PLAT_ERR_SUCCESS));
#endif
}
/*------------------- SAU/IDAU configuration functions -----------------------*/

#ifdef TFM_FIH_PROFILE_ON
fih_int sau_and_idau_cfg(void)
#else
void sau_and_idau_cfg(void)
#endif
{
  uint32_t i;
  uint32_t rnr;
  uint32_t rbar;
  uint32_t rlar;
  uint32_t rnr_reg;
  uint32_t rbar_reg;
  uint32_t rlar_reg;
  uint32_t ctrl_reg;

  /* configuration stage */
  if (uFlowStage == FLOW_STAGE_CFG)
  {
    SCB->NSACR = (SCB->NSACR & ~(SCB_NSACR_CP10_Msk | SCB_NSACR_CP11_Msk)) |
                 ((SCB_NSACR_CP10_11_VAL << SCB_NSACR_CP10_Pos) & (SCB_NSACR_CP10_Msk | SCB_NSACR_CP11_Msk));

    FPU->FPCCR = (FPU->FPCCR & ~(FPU_FPCCR_TS_Msk | FPU_FPCCR_CLRONRETS_Msk | FPU_FPCCR_CLRONRET_Msk)) |
                 ((FPU_FPCCR_TS_VAL        << FPU_FPCCR_TS_Pos) & FPU_FPCCR_TS_Msk) |
                 ((FPU_FPCCR_CLRONRETS_VAL << FPU_FPCCR_CLRONRETS_Pos) & FPU_FPCCR_CLRONRETS_Msk) |
                 ((FPU_FPCCR_CLRONRET_VAL  << FPU_FPCCR_CLRONRET_Pos) & FPU_FPCCR_CLRONRET_Msk);

    /* Disable SAU */
    TZ_SAU_Disable();

    for (i = 0; i < ARRAY_SIZE(sau_init_cfg); i++)
    {
      SAU->RNR = sau_init_cfg[i].RNR;
      SAU->RBAR = sau_init_cfg[i].RBAR & SAU_RBAR_BADDR_Msk;
      SAU->RLAR = (sau_init_cfg[i].RLAR & SAU_RLAR_LADDR_Msk) |
                  (sau_init_cfg[i].nsc ? SAU_RLAR_NSC_Msk : 0U) |
                  SAU_RLAR_ENABLE_Msk;

      /* Execution stopped if flow control failed */
      FLOW_CONTROL_STEP(uFlowProtectValue, sau_init_cfg[i].flow_step_enable,
                                           sau_init_cfg[i].flow_ctrl_enable);
    }

    /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();
    /* Enable SAU */
    TZ_SAU_Enable();

    /* Execution stopped if flow control failed */
    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_SAU_EN, FLOW_CTRL_SAU_EN);
  }
  /* verification stage */
  else
  {
    for (i = 0; i < ARRAY_SIZE(sau_init_cfg); i++)
    {
      SAU->RNR = sau_init_cfg[i].RNR;

      rnr = sau_init_cfg[i].RNR;
      rbar = sau_init_cfg[i].RBAR & SAU_RBAR_BADDR_Msk;
      rlar = (sau_init_cfg[i].RLAR & SAU_RLAR_LADDR_Msk) |
                  (sau_init_cfg[i].nsc ? SAU_RLAR_NSC_Msk : 0U) |
                  SAU_RLAR_ENABLE_Msk;

      rnr_reg = SAU->RNR;
      rbar_reg = SAU->RBAR;
      rlar_reg = SAU->RLAR;

      if ((rnr_reg != rnr) || (rbar_reg != rbar) || (rlar_reg != rlar))
      {
        /* FIX ME */
        while (1);
      }

      /* Execution stopped if flow control failed */
      FLOW_CONTROL_STEP(uFlowProtectValue, sau_init_cfg[i].flow_step_check,
                                           sau_init_cfg[i].flow_ctrl_check);
    }

    ctrl_reg = SAU->CTRL;
    if ((ctrl_reg && SAU_CTRL_ENABLE_Msk) != 1U)
    {
        /* FIX ME */
        while (1);
    }
    else
    {
      /* Execution stopped if flow control failed */
      FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_SAU_CH, FLOW_CTRL_SAU_CH);
    }

    /* Lock SAU config */
    __IO uint32_t read_reg = (uint32_t) &SYSCFG->CSLCKR;
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    SYSCFG->CSLCKR |= SYSCFG_CSLCKR_LOCKSAU;
    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_SAU_LCK, FLOW_CTRL_SAU_LCK);
    if (!((*(uint32_t *)read_reg) &  SYSCFG_CSLCKR_LOCKSAU))
        Error_Handler();
    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_SAU_LCK_CH, FLOW_CTRL_SAU_LCK_CH);
  }
#ifdef TFM_FIH_PROFILE_ON
  FIH_RET(fih_int_encode(TFM_PLAT_ERR_SUCCESS));
#endif
}
#define MPCBB_BLOCK_SIZE GTZC_MPCBB_BLOCK_SIZE
#define MPCBB_SUPER_BLOCK_SIZE (GTZC_MPCBB_SUPERBLOCK_SIZE)
#define FLAG_NPRIV (1)
#define FLAG_NSEC (1<<1)
#define PAGE_SIZE FLASH_AREA_IMAGE_SECTOR_SIZE

#define MPCBB_LOCK_SRAM1_SIZE 0xf
#define MPCBB_LOCK_SRAM2_SIZE 0xf
#define MPCBB_LOCK_SRAM6_SIZE 0xffffffff
#define MPCBB_LOCK(A) MPCBB_LOCK_##A

static void gtzc_config_sram(uint32_t base, uint32_t max_size, uint32_t off_start, uint32_t off_end, uint32_t flag);
static void gtzc_internal_flash_priv(uint32_t offset_start, uint32_t offset_end);

/*------------------- Memory configuration functions -------------------------*/
static void  gtzc_config_sram(uint32_t base, uint32_t max_size, uint32_t off_start, uint32_t off_end, uint32_t flag)
{
  /* by default SRAM is privileged secure */
  MPCBB_ConfigTypeDef MPCBB_desc;
  uint32_t secure_regwrite = 0xffffffff;
  uint32_t privilege_regwrite = 0xffffffff;
  uint32_t index;
  uint32_t block_start = (off_start) / (MPCBB_BLOCK_SIZE);
  uint32_t block_end = (off_end + 1) / (MPCBB_BLOCK_SIZE);

  /*  Check alignment to avoid further problem  */
  if ((off_start & (MPCBB_BLOCK_SIZE - 1)) ||
     ((off_end & (MPCBB_BLOCK_SIZE - 1))!=(MPCBB_BLOCK_SIZE - 1)))
    Error_Handler();
  if (off_end >  (max_size-1))
    Error_Handler();

  if (HAL_GTZC_MPCBB_GetConfigMem(base, &MPCBB_desc) != HAL_OK)
  {
    Error_Handler();
  }
  /* compute index to start and to end */
  /* start and end index is on superblock */
  /* end index is highest supreblock */
  for (index = 0; index < (max_size/MPCBB_BLOCK_SIZE); index++)
  {
    /* clean register on index aligned */
    if (!(index & 0x1f))
    {
      /* at index 0 */
      secure_regwrite = MPCBB_desc.AttributeConfig.MPCBB_SecConfig_array[index >> 5];
      privilege_regwrite = MPCBB_desc.AttributeConfig.MPCBB_PrivConfig_array[index >> 5];
    }
    if ((index >= block_start) && (index < block_end))
    {
      if (flag & FLAG_NSEC)
        /* clear bit to set as non secure */
        secure_regwrite &= ~(1 << (index & 0x1f));
      else
        /* set bit to set secure */
        secure_regwrite |= (1 << (index & 0x1f));

      if (flag & FLAG_NPRIV)
        /* clear bit to allow non privileged access */
        privilege_regwrite &=  ~(1 << (index & 0x1f));
      else
        /* set bit to set secure */
        privilege_regwrite |=  (1 << (index & 0x1f));

    }
    /* write register when 32 sub block are set  */
    if ((index & 0x1f) == 0x1f)
    {
      if (uFlowStage == FLOW_STAGE_CFG)
      {
        MPCBB_desc.AttributeConfig.MPCBB_SecConfig_array[index >> 5] = secure_regwrite;
        MPCBB_desc.AttributeConfig.MPCBB_PrivConfig_array[index >> 5] = privilege_regwrite;
      }
      else
      {
        if (MPCBB_desc.AttributeConfig.MPCBB_SecConfig_array[index >> 5] != secure_regwrite )
            Error_Handler();
        if (MPCBB_desc.AttributeConfig.MPCBB_PrivConfig_array[index >> 5] != privilege_regwrite)
            Error_Handler();
      }
    }
  }

  if ((uFlowStage == FLOW_STAGE_CFG) && (HAL_GTZC_MPCBB_ConfigMem(base, &MPCBB_desc) != HAL_OK))
    /* FIX ME */
    Error_Handler();

}

static void gtzc_internal_flash_priv(uint32_t offset_start, uint32_t offset_end)
{
#ifdef FLASH_BANK_2 /* STM32WBA65xx_H*/
  __IO uint32_t *PrivBB[4] = {&FLASH_S->PRIVBB1R1, &FLASH_S->PRIVBB1R2, &FLASH_S->PRIVBB1R3, &FLASH_S->PRIVBB1R4};
#else /* STM32WBA52xx_H */
  __IO uint32_t *PrivBB[4] = {&FLASH_S->PRIVBBR1, &FLASH_S->PRIVBBR2, &FLASH_S->PRIVBBR3, &FLASH_S->PRIVBBR4};
#endif
  __IO uint32_t *ptr;
  uint32_t regwrite = 0x0;
  uint32_t index;
  uint32_t block_start = offset_start;
  uint32_t block_end =  offset_end;
  block_start = block_start / FLASH_AREA_IMAGE_SECTOR_SIZE;
  block_end = block_end / FLASH_AREA_IMAGE_SECTOR_SIZE ;
  /*  Check alignment to avoid further problem  */
  if (offset_start & (FLASH_AREA_IMAGE_SECTOR_SIZE - 1))
    Error_Handler();
  /*  1f is for 32 bits */
  for (index = block_start & ~0x1f; index < ((sizeof(PrivBB)/sizeof(PrivBB[0])) << 5) ; index++) {
    /* clean register on index aligned */
    if (!(index & 0x1f)) {
      regwrite = 0x0;
    }
    if ((index >= block_start) && (index <= block_end)) {
      regwrite = regwrite | (1 << (index & 0x1f));
    }
    /* write register when 32 sub block are set or last block to set  */
    if ((index & 0x1f) == 0x1f) {
      ptr = (uint32_t *)PrivBB[index >> 5];
      if (uFlowStage == FLOW_STAGE_CFG)
        *ptr =  regwrite;
      else if (*ptr != regwrite)
        Error_Handler();
    }
  }
}

#ifdef TFM_FIH_PROFILE_ON
fih_int gtzc_init_cfg(void)
#else
void gtzc_init_cfg(void)
#endif
{
  uint32_t gtzc_periph_att;

  (void)gtzc_periph_att;

  if (uFlowStage == FLOW_STAGE_CFG)
  {
    /* Check VTOR Is locked */
    if (!(SYSCFG->CSLCKR & SYSCFG_CSLCKR_LOCKSVTAIRCR))
        Error_Handler();
    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_GTZC_VTOR_LCK, FLOW_CTRL_GTZC_VTOR_LCK);

    /* Check PRIS Is enabled */
    if( (SCB->AIRCR & SCB_AIRCR_PRIS_Msk) == 0 )
      Error_Handler();
    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_GTZC_PRIS_EN, FLOW_CTRL_GTZC_PRIS_EN);

    /* Enable GTZC clock */
    __HAL_RCC_GTZC1_CLK_ENABLE();
    /* assume non secure ram is only in SRAM 1 , SRAM 2 is reserved for secure */
      gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (NS_DATA_START - NS_RAM_ALIAS(0)),
              (NS_DATA_START + NS_DATA_SIZE - 1) - NS_RAM_ALIAS(0), FLAG_NSEC | FLAG_NPRIV);
#if S_TOTAL_RAM1_SIZE != 0
      /*  is unpriv area ending in SRAM1 */
      if ((SRAM2_BASE > (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)))
      {
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (NS_DATA_START + NS_DATA_SIZE) - NS_RAM_ALIAS(0),
                  (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) - SRAM1_BASE  -1, FLAG_NPRIV);
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) - SRAM1_BASE,
                  SRAM1_SIZE - 1, 0);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, SRAM2_SIZE - 1, 0);
      }
      else
      {
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (NS_DATA_START + NS_DATA_SIZE) - NS_RAM_ALIAS(0), SRAM1_SIZE -1, FLAG_NPRIV);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
                  - SRAM2_BASE - 1, FLAG_NPRIV);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
                  - SRAM2_BASE, SRAM2_SIZE - 1, 0);
      }
#else
      /*   only SRAM2 is secure  */
      gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
              - SRAM2_BASE - 1, FLAG_NPRIV);
      gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
              -SRAM2_BASE, SRAM2_SIZE - 1, 0);
#endif
      gtzc_config_sram(SRAM6_BASE, SRAM6_SIZE, 0, SRAM6_SIZE -1, FLAG_NPRIV | FLAG_NSEC);

    GTZC_MPCBB1_S->CFGLOCK=MPCBB_LOCK(SRAM1_SIZE);
    GTZC_MPCBB2_S->CFGLOCK=MPCBB_LOCK(SRAM2_SIZE);

    /* privileged secure internal flash */
    gtzc_internal_flash_priv(0x0, (uint32_t)(&REGION_NAME(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base)) - FLASH_BASE_S - 1);

    /*  use sticky bit to lock all SRAM config  */

    /* Configure Secure peripherals */
    HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_RNG, GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_RNG);

#if (defined (MBEDTLS_SHA256_C) && defined (MBEDTLS_SHA256_ALT)) \
 || (defined (MBEDTLS_SHA1_C) && defined (MBEDTLS_SHA1_ALT)) \
 || (defined (MBEDTLS_MD5_C) && defined (MBEDTLS_MD5_ALT))
    HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_HASH, GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_HASH);
#endif
#if (defined (MBEDTLS_ECP_C) && defined (MBEDTLS_ECP_ALT)) \
 || (defined (MBEDTLS_ECDSA_C) && (defined (MBEDTLS_ECDSA_SIGN_ALT) || defined (MBEDTLS_ECDSA_VERIFY_ALT)))
    HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_PKA, GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_PKA);
#endif
#if (defined (MBEDTLS_AES_C) && defined (MBEDTLS_AES_ALT)) \
 || (defined (MBEDTLS_GCM_C) && defined (MBEDTLS_GCM_ALT)) \
 || (defined (MBEDTLS_CCM_C) && defined (MBEDTLS_CCM_ALT))
    HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_AES, GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_AES);
#endif
#if defined (HW_CRYPTO_DPA_AES) || defined (HW_CRYPTO_DPA_GCM)
    HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_SAES, GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_SAES);
#endif

    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_GTZC_PERIPH_CFG, FLOW_CTRL_GTZC_PERIPH_CFG);

    /*  enable interruption on illegal access on FLASH ,FLASH reg , Secure SRAM2 and Secure Peripheral*/
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_FLASH);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_FLASH_REG);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_SRAM2);
    /* GTZC register */
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_TZIC);
    HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_TZSC);
    /* Add barriers to assure the GTZC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();
  }
  /* Verification stage */
  else
  {
#if S_TOTAL_RAM1_SIZE != 0
      /*  is unpriv area ending in SRAM1 */
      if ((SRAM2_BASE > (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)))
      {
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (NS_DATA_START + NS_DATA_SIZE) - NS_RAM_ALIAS(0),
                  (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) - SRAM1_BASE  -1, FLAG_NPRIV);
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base) - SRAM1_BASE,
                  SRAM1_SIZE - 1, 0);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, SRAM2_SIZE - 1, 0);
      }
      else
      {
          gtzc_config_sram(SRAM1_BASE, SRAM1_SIZE, (NS_DATA_START + NS_DATA_SIZE) - NS_RAM_ALIAS(0), SRAM1_SIZE -1, FLAG_NPRIV);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
                  - SRAM2_BASE - 1, FLAG_NPRIV);
          gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
                  - SRAM2_BASE, SRAM2_SIZE - 1, 0);
      }
#else
      /*   only SRAM2 is secure  */
      gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, 0, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
              - SRAM2_BASE - 1, FLAG_NPRIV);
      gtzc_config_sram(SRAM2_BASE, SRAM2_SIZE, (uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)
              -SRAM2_BASE, SRAM2_SIZE - 1, 0);
#endif
      gtzc_config_sram(SRAM6_BASE, SRAM6_SIZE, 0, SRAM6_SIZE -1, FLAG_NPRIV | FLAG_NSEC);
    if (GTZC_MPCBB1_S->CFGLOCK != MPCBB_LOCK(SRAM1_SIZE)) Error_Handler();
    if (GTZC_MPCBB2_S->CFGLOCK != MPCBB_LOCK(SRAM2_SIZE)) Error_Handler();

    gtzc_internal_flash_priv(0x0, (uint32_t)(&REGION_NAME(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base)) - FLASH_BASE_S - 1);
#if (defined (MBEDTLS_SHA256_C) && defined (MBEDTLS_SHA256_ALT)) \
 || (defined (MBEDTLS_SHA1_C) && defined (MBEDTLS_SHA1_ALT)) \
 || (defined (MBEDTLS_MD5_C) && defined (MBEDTLS_MD5_ALT))
    HAL_GTZC_TZSC_GetConfigPeriphAttributes(GTZC_PERIPH_HASH, &gtzc_periph_att);
    if (gtzc_periph_att != (GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV)) {
      Error_Handler();
    }
#endif
#if (defined (MBEDTLS_ECP_C) && defined (MBEDTLS_ECP_ALT)) \
 || (defined (MBEDTLS_ECDSA_C) && (defined (MBEDTLS_ECDSA_SIGN_ALT) || defined (MBEDTLS_ECDSA_VERIFY_ALT)))
    HAL_GTZC_TZSC_GetConfigPeriphAttributes(GTZC_PERIPH_PKA, &gtzc_periph_att);
    if (gtzc_periph_att != (GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV)) {
      Error_Handler();
    }
#endif
#if (defined (MBEDTLS_AES_C) && defined (MBEDTLS_AES_ALT)) \
 || (defined (MBEDTLS_GCM_C) && defined (MBEDTLS_GCM_ALT)) \
 || (defined (MBEDTLS_CCM_C) && defined (MBEDTLS_CCM_ALT))
    HAL_GTZC_TZSC_GetConfigPeriphAttributes(GTZC_PERIPH_AES, &gtzc_periph_att);
    if (gtzc_periph_att != (GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV)) {
      Error_Handler();
    }
#endif
#if defined (HW_CRYPTO_DPA_AES) || defined (HW_CRYPTO_DPA_GCM)
    HAL_GTZC_TZSC_GetConfigPeriphAttributes(GTZC_PERIPH_SAES, &gtzc_periph_att);
    if (gtzc_periph_att != (GTZC_TZSC_PERIPH_SEC | GTZC_TZSC_PERIPH_PRIV)) {
      Error_Handler();
    }
#endif

    FLOW_CONTROL_STEP(uFlowProtectValue, FLOW_STEP_GTZC_PERIPH_CH, FLOW_CTRL_GTZC_PERIPH_CH);
  }
  /* Lock GTZC */
  HAL_GTZC_TZSC_Lock(GTZC_TZSC_S);
#ifdef TFM_FIH_PROFILE_ON
  FIH_RET(fih_int_encode(TFM_PLAT_ERR_SUCCESS));
#endif
}

#ifdef TFM_FIH_PROFILE_ON

fih_int tfm_spm_hal_init_debug(void)
{
  /*  debug is available  only with RDP 0 for secure*/
  FIH_RET(fih_int_encode(TFM_PLAT_ERR_SUCCESS));
}

fih_int tfm_spm_hal_verify_isolation_hw(void)
{
  FIH_RET(fih_int_encode(TFM_PLAT_ERR_SUCCESS));
}

#else
void tfm_spm_hal_init_debug(void)
{
  /*  debug is available  only with RDP 0 for secure*/
}
#endif /* TFM_FIH_PROFILE_ON */

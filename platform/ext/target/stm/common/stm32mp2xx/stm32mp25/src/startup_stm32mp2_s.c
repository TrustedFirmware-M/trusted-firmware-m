/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <cmsis.h>
#include <startup.h>
#include <exception_info.h>
#include <utilities.h>

__WEAK void arm_nvic_isr(void)
{
	while (1) {
	}
}

void default_tfm_exception_handler(void)
{
	tfm_core_panic();
}

__NO_RETURN __attribute__((naked)) void default_exception_handler(void)
{
	EXCEPTION_INFO();

	__ASM volatile("BL	default_tfm_exception_handler\n"
		       "B	.\n"
	);
}

void default_irq_handler(void)
{
	arm_nvic_isr();
}

/* Exceptions */
DEFAULT_EXCEPTION_HANDLER(NMI_Handler)
DEFAULT_EXCEPTION_HANDLER(HardFault_Handler)
DEFAULT_EXCEPTION_HANDLER(MemManage_Handler)
DEFAULT_EXCEPTION_HANDLER(BusFault_Handler)
DEFAULT_EXCEPTION_HANDLER(UsageFault_Handler)
DEFAULT_EXCEPTION_HANDLER(SecureFault_Handler)
DEFAULT_EXCEPTION_HANDLER(SVC_Handler)
DEFAULT_EXCEPTION_HANDLER(DebugMon_Handler)
DEFAULT_EXCEPTION_HANDLER(PendSV_Handler)
DEFAULT_EXCEPTION_HANDLER(SysTick_Handler)

/* Core interrupts */
DEFAULT_IRQ_HANDLER(PVD_IRQHandler)
DEFAULT_IRQ_HANDLER(PVM_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG3_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG4_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG1_RST_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG2_RST_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG4_RST_IRQHandler)
DEFAULT_IRQ_HANDLER(IWDG5_RST_IRQHandler)
DEFAULT_IRQ_HANDLER(WWDG1_IRQHandler)
DEFAULT_IRQ_HANDLER(WWDG2_RST_IRQHandler)
DEFAULT_IRQ_HANDLER(TAMP_IRQHandler)
DEFAULT_IRQ_HANDLER(RTC_IRQHandler)
DEFAULT_IRQ_HANDLER(TAMP_S_IRQHandler)
DEFAULT_IRQ_HANDLER(RTC_S_IRQHandler)
DEFAULT_IRQ_HANDLER(RCC_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_0_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_1_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_2_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_3_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_4_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_5_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_6_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_7_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_8_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_9_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_10_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_11_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_12_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_13_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_14_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI2_15_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel0_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel1_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel2_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel3_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel4_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel5_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel6_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel7_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel8_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel9_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel10_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel11_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel12_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel13_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel14_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_Channel15_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel0_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel1_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel2_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel3_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel4_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel5_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel6_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel7_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel8_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel9_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel10_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel11_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel12_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel13_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel14_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_Channel15_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel0_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel1_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel2_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel3_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel4_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel5_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel6_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel7_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel8_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel9_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel10_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel11_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel12_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel13_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel14_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_Channel15_IRQHandler)
DEFAULT_IRQ_HANDLER(LPDMA_Channel0_IRQHandler)
DEFAULT_IRQ_HANDLER(LPDMA_Channel1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPDMA_Channel2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPDMA_Channel3_IRQHandler)
DEFAULT_IRQ_HANDLER(ICACHE_IRQHandler)
DEFAULT_IRQ_HANDLER(DCACHE_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC1_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC2_IRQHandler)
DEFAULT_IRQ_HANDLER(ADC3_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN_CAL_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN1_IT0_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN2_IT0_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN3_IT0_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN1_IT1_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN2_IT1_IRQHandler)
DEFAULT_IRQ_HANDLER(FDCAN3_IT1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_BRK_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_UP_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_TRG_COM_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM1_CC_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM20_BRK_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM20_UP_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM20_TRG_COM_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM20_CC_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM2_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM3_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM4_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C1_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C1_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C2_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C2_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI2_IRQHandler)
DEFAULT_IRQ_HANDLER(USART1_IRQHandler)
DEFAULT_IRQ_HANDLER(USART2_IRQHandler)
DEFAULT_IRQ_HANDLER(USART3_IRQHandler)
DEFAULT_IRQ_HANDLER(VDEC_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_BRK_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_UP_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_TRG_COM_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM8_CC_IRQHandler)
DEFAULT_IRQ_HANDLER(FMC_IRQHandler)
DEFAULT_IRQ_HANDLER(SDMMC1_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM5_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI3_IRQHandler)
DEFAULT_IRQ_HANDLER(UART4_IRQHandler)
DEFAULT_IRQ_HANDLER(UART5_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM6_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM7_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH1_SBD_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH1_PMT_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH1_LPI_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH2_SBD_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH2_PMT_IRQHandler)
DEFAULT_IRQ_HANDLER(ETH2_LPI_IRQHandler)
DEFAULT_IRQ_HANDLER(USART6_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C3_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C3_IRQHandler)
DEFAULT_IRQ_HANDLER(USBH_EHCI_IRQHandler)
DEFAULT_IRQ_HANDLER(USBH_OHCI_IRQHandler)
DEFAULT_IRQ_HANDLER(DCMI_PSSI_IRQHandler)
DEFAULT_IRQ_HANDLER(CSI_IRQHandler)
DEFAULT_IRQ_HANDLER(DSI_IRQHandler)
#if defined(STM32MP2_HAS_CRYPTO)
DEFAULT_IRQ_HANDLER(CRYP1_IRQHandler)
#endif /* STM32MP2_HAS_CRYPTO */
DEFAULT_IRQ_HANDLER(HASH_IRQHandler)
DEFAULT_IRQ_HANDLER(PKA_IRQHandler)
DEFAULT_IRQ_HANDLER(FPU_IRQHandler)
DEFAULT_IRQ_HANDLER(UART7_IRQHandler)
DEFAULT_IRQ_HANDLER(UART8_IRQHandler)
DEFAULT_IRQ_HANDLER(UART9_IRQHandler)
DEFAULT_IRQ_HANDLER(LPUART1_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI4_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI5_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI6_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI7_IRQHandler)
DEFAULT_IRQ_HANDLER(SPI8_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI1_IRQHandler)
DEFAULT_IRQ_HANDLER(LTDC_IRQHandler)
DEFAULT_IRQ_HANDLER(LTDC_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(LTDC_SEC_IRQHandler)
DEFAULT_IRQ_HANDLER(LTDC_SEC_ER_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI2_IRQHandler)
DEFAULT_IRQ_HANDLER(OCTOSPI1_IRQHandler)
DEFAULT_IRQ_HANDLER(OCTOSPI2_IRQHandler)
DEFAULT_IRQ_HANDLER(OTFDEC1_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM1_IRQHandler)
DEFAULT_IRQ_HANDLER(VENC_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C4_IRQHandler)
DEFAULT_IRQ_HANDLER(USBH_WAKEUP_IRQHandler)
DEFAULT_IRQ_HANDLER(SPDIFRX_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC1_RX_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC1_TX_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC1_RX_S_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC1_TX_S_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC2_RX_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC2_TX_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC2_RX_S_IRQHandler)
DEFAULT_IRQ_HANDLER(IPCC2_TX_S_IRQHandler)
#if defined(STM32MP2_HAS_CRYPTO)
DEFAULT_IRQ_HANDLER(SAES_IRQHandler)
DEFAULT_IRQ_HANDLER(CRYP2_IRQHandler)
#endif /* STM32MP2_HAS_CRYPTO */
DEFAULT_IRQ_HANDLER(I2C5_IRQHandler)
DEFAULT_IRQ_HANDLER(USB3DR_WAKEUP_IRQHandler)
DEFAULT_IRQ_HANDLER(GPU_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT0_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT1_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT2_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT3_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT4_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT5_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT6_IRQHandler)
DEFAULT_IRQ_HANDLER(MDF1_FLT7_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI3_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM15_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM16_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM17_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM12_IRQHandler)
DEFAULT_IRQ_HANDLER(SDMMC2_IRQHandler)
DEFAULT_IRQ_HANDLER(DCMIPP_IRQHandler)
DEFAULT_IRQ_HANDLER(HSEM_IRQHandler)
DEFAULT_IRQ_HANDLER(HSEM_S_IRQHandler)
DEFAULT_IRQ_HANDLER(nCTIIRQ1_IRQHandler)
DEFAULT_IRQ_HANDLER(nCTIIRQ2_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM13_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM14_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM10_IRQHandler)
DEFAULT_IRQ_HANDLER(RNG_IRQHandler)
DEFAULT_IRQ_HANDLER(ADF1_FLT_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C6_IRQHandler)
DEFAULT_IRQ_HANDLER(COMBOPHY_WAKEUP_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C7_IRQHandler)
DEFAULT_IRQ_HANDLER(I2C8_IRQHandler)
DEFAULT_IRQ_HANDLER(I3C4_IRQHandler)
DEFAULT_IRQ_HANDLER(SDMMC3_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM2_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM3_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM4_IRQHandler)
DEFAULT_IRQ_HANDLER(LPTIM5_IRQHandler)
DEFAULT_IRQ_HANDLER(OTFDEC2_IRQHandler)
DEFAULT_IRQ_HANDLER(CPU1_SEV_IRQHandler)
DEFAULT_IRQ_HANDLER(CPU3_SEV_IRQHandler)
DEFAULT_IRQ_HANDLER(RCC_WAKEUP_IRQHandler)
DEFAULT_IRQ_HANDLER(SAI4_IRQHandler)
DEFAULT_IRQ_HANDLER(DTS_IRQHandler)
DEFAULT_IRQ_HANDLER(TIM11_IRQHandler)
DEFAULT_IRQ_HANDLER(CPU2_WAKEUP_PIN_IRQHandler)
DEFAULT_IRQ_HANDLER(USB3DR_BC_IRQHandler)
DEFAULT_IRQ_HANDLER(USB3DR_IRQHandler)
DEFAULT_IRQ_HANDLER(UCPD1_IRQHandler)
DEFAULT_IRQ_HANDLER(SERF_IRQHandler)
DEFAULT_IRQ_HANDLER(BUSPERFM_IRQHandler)
DEFAULT_IRQ_HANDLER(RAMCFG_IRQHandler)
DEFAULT_IRQ_HANDLER(DDRCTRL_IRQHandler)
DEFAULT_IRQ_HANDLER(DDRPHYC_IRQHandler)
DEFAULT_IRQ_HANDLER(DFI_ERR_IRQHandler)
DEFAULT_IRQ_HANDLER(IAC_IRQHandler)
DEFAULT_IRQ_HANDLER(VDDCPU_VD_IRQHandler)
DEFAULT_IRQ_HANDLER(VDDCORE_VD_IRQHandler)
DEFAULT_IRQ_HANDLER(ETHSW_IRQHandler)
DEFAULT_IRQ_HANDLER(ETHSW_MSGBUF_IRQHandler)
DEFAULT_IRQ_HANDLER(ETHSW_FSC_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA1_WKUP_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA2_WKUP_IRQHandler)
DEFAULT_IRQ_HANDLER(HPDMA3_WKUP_IRQHandler)
DEFAULT_IRQ_HANDLER(LPDMA_WKUP_IRQHandler)
DEFAULT_IRQ_HANDLER(UCPD1_VBUS_IRQHandler)
DEFAULT_IRQ_HANDLER(UCPD1_VSAFE5V_IRQHandler)
DEFAULT_IRQ_HANDLER(RCC_HSI_FMON_IRQHandler)
DEFAULT_IRQ_HANDLER(VDDGPU_VD_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_0_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_1_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_2_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_3_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_4_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_5_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_6_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_7_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_8_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_9_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_10_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_11_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_12_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_13_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_14_IRQHandler)
DEFAULT_IRQ_HANDLER(EXTI1_15_IRQHandler)
DEFAULT_IRQ_HANDLER(IS2M_IRQHandler)
DEFAULT_IRQ_HANDLER(DDRPERFM_IRQHandler)
DEFAULT_IRQ_HANDLER(RESERVED_284_IRQHandler)
DEFAULT_IRQ_HANDLER(RESERVED_285_IRQHandler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
	(VECTOR_TABLE_Type)(&__INITIAL_SP),	/* Initial Stack Pointer */
	Reset_Handler,               /* Reset Handler */
	NMI_Handler,                 /* NMI Handler */
	HardFault_Handler,           /* Hard Fault Handler */
	MemManage_Handler,           /* MPU Fault Handler */
	BusFault_Handler,            /* Bus Fault Handler */
	UsageFault_Handler,          /* Usage Fault Handler */
	SecureFault_Handler,         /* Secure Fault Handler */
	0,
	0,
	0,
	SVC_Handler,                 /* SVCall Handler */
	DebugMon_Handler,            /* Debug Monitor Handler */
	0,
	PendSV_Handler,              /* PendSV Handler */
	SysTick_Handler,             /* SysTick Handler */

	/* Core interrupts */
	/*******************************************************************************/
	/* External interrupts according to                                            */
	/* "Table 226. interrupt mapping for Cortex®-M33"                              */
	/* in chapitre 32 "interrupt list" of reference document                       */
	/* RM0457 - Reference Manual - STM32MP25xx - advanced ARM-based 32/64-bit MPUs */
	/* file "DM00485804 (RM0457) Rev0.1.pdf" (Revision 0.1 / 09-Mar-2021)          */
	/*******************************************************************************/
	PVD_IRQHandler,              /* PVD detector through EXTI */
	PVM_IRQHandler,              /* PVM detector through EXTI */
	IWDG3_IRQHandler,            /* Independent Watchdog 3 Early wake interrupt */
	IWDG4_IRQHandler,            /* Independent Watchdog 4 Early wake interrupt */
	IWDG1_RST_IRQHandler,        /* Independent Watchdog 1 Reset through EXTI */
	IWDG2_RST_IRQHandler,        /* Independent Watchdog 2 Reset through EXTI */
	IWDG4_RST_IRQHandler,        /* Independent Watchdog 4 Reset through EXTI */
	IWDG5_RST_IRQHandler,        /* Independent Watchdog 5 Reset through EXTI */
	WWDG1_IRQHandler,            /* Window Watchdog 1 Early Wakeup interrupt */
	0,
	0,
	WWDG2_RST_IRQHandler,        /* Window Watchdog 2 Reset through EXTI */
	TAMP_IRQHandler,             /* Tamper interrupt (include LSECSS interrupts) */
	RTC_IRQHandler,              /* RTC global interrupt */
	TAMP_S_IRQHandler,           /* Tamper secure interrupt (include LSECSS interrupts) */
	RTC_S_IRQHandler,            /* RTC global secure interrupt */
	RCC_IRQHandler,              /* RCC global interrupt */
	EXTI2_0_IRQHandler,          /* EXTI2 Line 0 interrupt */
	EXTI2_1_IRQHandler,          /* EXTI2 Line 1 interrupt */
	EXTI2_2_IRQHandler,          /* EXTI2 Line 2 interrupt */
	EXTI2_3_IRQHandler,          /* EXTI2 Line 3 interrupt */
	EXTI2_4_IRQHandler,          /* EXTI2 Line 4 interrupt */
	EXTI2_5_IRQHandler,          /* EXTI2 Line 5 interrupt */
	EXTI2_6_IRQHandler,          /* EXTI2 Line 6 interrupt */
	EXTI2_7_IRQHandler,          /* EXTI2 Line 7 interrupt */
	EXTI2_8_IRQHandler,          /* EXTI2 Line 8 interrupt */
	EXTI2_9_IRQHandler,          /* EXTI2 Line 9 interrupt */
	EXTI2_10_IRQHandler,         /* EXTI2 Line 10 interrupt */
	EXTI2_11_IRQHandler,         /* EXTI2 Line 11 interrupt */
	EXTI2_12_IRQHandler,         /* EXTI2 Line 12 interrupt */
	EXTI2_13_IRQHandler,         /* EXTI2 Line 13 interrupt */
	EXTI2_14_IRQHandler,         /* EXTI2 Line 14 interrupt */
	EXTI2_15_IRQHandler,         /* EXTI2 Line 15 interrupt */
	HPDMA1_Channel0_IRQHandler,  /* HPDMA1 Channel0 interrupt */
	HPDMA1_Channel1_IRQHandler,  /* HPDMA1 Channel1 interrupt */
	HPDMA1_Channel2_IRQHandler,  /* HPDMA1 Channel2 interrupt */
	HPDMA1_Channel3_IRQHandler,  /* HPDMA1 Channel3 interrupt */
	HPDMA1_Channel4_IRQHandler,  /* HPDMA1 Channel4 interrupt */
	HPDMA1_Channel5_IRQHandler,  /* HPDMA1 Channel5 interrupt */
	HPDMA1_Channel6_IRQHandler,  /* HPDMA1 Channel6 interrupt */
	HPDMA1_Channel7_IRQHandler,  /* HPDMA1 Channel7 interrupt */
	HPDMA1_Channel8_IRQHandler,  /* HPDMA1 Channel8 interrupt */
	HPDMA1_Channel9_IRQHandler,  /* HPDMA1 Channel9 interrupt */
	HPDMA1_Channel10_IRQHandler, /* HPDMA1 Channel10 interrupt */
	HPDMA1_Channel11_IRQHandler, /* HPDMA1 Channel11 interrupt */
	HPDMA1_Channel12_IRQHandler, /* HPDMA1 Channel12 interrupt */
	HPDMA1_Channel13_IRQHandler, /* HPDMA1 Channel13 interrupt */
	HPDMA1_Channel14_IRQHandler, /* HPDMA1 Channel14 interrupt */
	HPDMA1_Channel15_IRQHandler, /* HPDMA1 Channel15 interrupt */
	HPDMA2_Channel0_IRQHandler,  /* HPDMA2 Channel0 interrupt */
	HPDMA2_Channel1_IRQHandler,  /* HPDMA2 Channel1 interrupt */
	HPDMA2_Channel2_IRQHandler,  /* HPDMA2 Channel2 interrupt */
	HPDMA2_Channel3_IRQHandler,  /* HPDMA2 Channel3 interrupt */
	HPDMA2_Channel4_IRQHandler,  /* HPDMA2 Channel4 interrupt */
	HPDMA2_Channel5_IRQHandler,  /* HPDMA2 Channel5 interrupt */
	HPDMA2_Channel6_IRQHandler,  /* HPDMA2 Channel6 interrupt */
	HPDMA2_Channel7_IRQHandler,  /* HPDMA2 Channel7 interrupt */
	HPDMA2_Channel8_IRQHandler,  /* HPDMA2 Channel8 interrupt */
	HPDMA2_Channel9_IRQHandler,  /* HPDMA2 Channel9 interrupt */
	HPDMA2_Channel10_IRQHandler, /* HPDMA2 Channel10 interrupt */
	HPDMA2_Channel11_IRQHandler, /* HPDMA2 Channel11 interrupt */
	HPDMA2_Channel12_IRQHandler, /* HPDMA2 Channel12 interrupt */
	HPDMA2_Channel13_IRQHandler, /* HPDMA2 Channel13 interrupt */
	HPDMA2_Channel14_IRQHandler, /* HPDMA2 Channel14 interrupt */
	HPDMA2_Channel15_IRQHandler, /* HPDMA2 Channel15 interrupt */
	HPDMA3_Channel0_IRQHandler,  /* HPDMA3 Channel0 interrupt */
	HPDMA3_Channel1_IRQHandler,  /* HPDMA3 Channel1 interrupt */
	HPDMA3_Channel2_IRQHandler,  /* HPDMA3 Channel2 interrupt */
	HPDMA3_Channel3_IRQHandler,  /* HPDMA3 Channel3 interrupt */
	HPDMA3_Channel4_IRQHandler,  /* HPDMA3 Channel4 interrupt */
	HPDMA3_Channel5_IRQHandler,  /* HPDMA3 Channel5 interrupt */
	HPDMA3_Channel6_IRQHandler,  /* HPDMA3 Channel6 interrupt */
	HPDMA3_Channel7_IRQHandler,  /* HPDMA3 Channel7 interrupt */
	HPDMA3_Channel8_IRQHandler,  /* HPDMA3 Channel8 interrupt */
	HPDMA3_Channel9_IRQHandler,  /* HPDMA3 Channel9 interrupt */
	HPDMA3_Channel10_IRQHandler, /* HPDMA3 Channel10 interrupt */
	HPDMA3_Channel11_IRQHandler, /* HPDMA3 Channel11 interrupt */
	HPDMA3_Channel12_IRQHandler, /* HPDMA3 Channel12 interrupt */
	HPDMA3_Channel13_IRQHandler, /* HPDMA3 Channel13 interrupt */
	HPDMA3_Channel14_IRQHandler, /* HPDMA3 Channel14 interrupt */
	HPDMA3_Channel15_IRQHandler, /* HPDMA3 Channel15 interrupt */
	LPDMA_Channel0_IRQHandler,   /* LPDMA Channel0 interrupt */
	LPDMA_Channel1_IRQHandler,   /* LPDMA Channel1 interrupt */
	LPDMA_Channel2_IRQHandler,   /* LPDMA Channel2 interrupt */
	LPDMA_Channel3_IRQHandler,   /* LPDMA Channel3 interrupt */
	ICACHE_IRQHandler,           /* ICACHE interrupt */
	DCACHE_IRQHandler,           /* DCACHE interrupt */
	ADC1_IRQHandler,             /* ADC1 interrupt */
	ADC2_IRQHandler,             /* ADC2  interrupt */
	ADC3_IRQHandler,             /* ADC3 interrupt */
	FDCAN_CAL_IRQHandler,        /* FDCAN CCU interrupt */
	FDCAN1_IT0_IRQHandler,       /* FDCAN1 interrupt 0 */
	FDCAN2_IT0_IRQHandler,       /* FDCAN2 interrupt 0 */
	FDCAN3_IT0_IRQHandler,       /* FDCAN3 interrupt 0 */
	FDCAN1_IT1_IRQHandler,       /* FDCAN1 interrupt 1 */
	FDCAN2_IT1_IRQHandler,       /* FDCAN2 interrupt 1 */
	FDCAN3_IT1_IRQHandler,       /* FDCAN3 interrupt 1 */
	TIM1_BRK_IRQHandler,         /* TIM1 Break interrupt */
	TIM1_UP_IRQHandler,          /* TIM1 Update interrupt */
	TIM1_TRG_COM_IRQHandler,     /* TIM1 Trigger and Commutation interrupts */
	TIM1_CC_IRQHandler,          /* TIM1 Capture Compare interrupt */
	TIM20_BRK_IRQHandler,        /* TIM20 Break interrupt */
	TIM20_UP_IRQHandler,         /* TIM20 Update interrupt */
	TIM20_TRG_COM_IRQHandler,    /* TIM20 Trigger and Commutation interrupts */
	TIM20_CC_IRQHandler,         /* TIM20 Capture Compare interrupt */
	TIM2_IRQHandler,             /* TIM2 global interrupt */
	TIM3_IRQHandler,             /* TIM3 global interrupt */
	TIM4_IRQHandler,             /* TIM4 global interrupt */
	I2C1_IRQHandler,             /* I2C1 global interrupt */
	I3C1_IRQHandler,             /* I3C1 global interrupt */
	I2C2_IRQHandler,             /* I2C2 global interrupt */
	I3C2_IRQHandler,             /* I3C2 global interrupt */
	SPI1_IRQHandler,             /* SPI1 global interrupt */
	SPI2_IRQHandler,             /* SPI2 global interrupt */
	USART1_IRQHandler,           /* USART1 global interrupt */
	USART2_IRQHandler,           /* USART2 global interrupt */
	USART3_IRQHandler,           /* USART3 global interrupt */
	VDEC_IRQHandler,             /* VDEC global interrupt */
	TIM8_BRK_IRQHandler,         /* TIM8 Break interrupt */
	TIM8_UP_IRQHandler,          /* TIM8 Update interrupt */
	TIM8_TRG_COM_IRQHandler,     /* TIM8 Trigger & Commutation interrupt */
	TIM8_CC_IRQHandler,          /* TIM8 Capture Compare interrupt */
	FMC_IRQHandler,              /* FMC global interrupt */
	SDMMC1_IRQHandler,           /* SDMMC1 global interrupt */
	TIM5_IRQHandler,             /* TIM5 global interrupt */
	SPI3_IRQHandler,             /* SPI3 global interrupt */
	UART4_IRQHandler,            /* UART4 global interrupt */
	UART5_IRQHandler,            /* UART5 global interrupt */
	TIM6_IRQHandler,             /* TIM6 global interrupt */
	TIM7_IRQHandler,             /* TIM7 global interrupt */
	ETH1_SBD_IRQHandler,         /* ETH1 global interrupt */
	ETH1_PMT_IRQHandler,         /* ETH1 wake-up interrupt */
	ETH1_LPI_IRQHandler,         /* ETH1 LPI interrupt */
	ETH2_SBD_IRQHandler,         /* ETH2 global interrupt */
	ETH2_PMT_IRQHandler,         /* ETH2 wake-up interrupt */
	ETH2_LPI_IRQHandler,         /* ETH2 LPI interrupt */
	USART6_IRQHandler,           /* USART6 global interrupt */
	I2C3_IRQHandler,             /* I2C3 global interrupt */
	I3C3_IRQHandler,             /* I3C3 global interrupt */
	USBH_EHCI_IRQHandler,        /* USB Host EHCI interrupt */
	USBH_OHCI_IRQHandler,        /* USB Host OHCI interrupt */
	DCMI_PSSI_IRQHandler,        /* DCMI & PSSI global interrupt */
	CSI_IRQHandler,              /* CSI-2 interrupt */
	DSI_IRQHandler,              /* DSI Host controller global interrupt */
#if defined(STM32MP2_HAS_CRYPTO)
	CRYP1_IRQHandler,            /* Crypto1 interrupt */
#else /* STM32MP2_HAS_CRYPTO */
	0,
#endif /* STM32MP2_HAS_CRYPTO */
	HASH_IRQHandler,             /* Hash interrupt */
	PKA_IRQHandler,              /* PKA interrupt */
	FPU_IRQHandler,              /* FPU global interrupt */
	UART7_IRQHandler,            /* UART7 global interrupt */
	UART8_IRQHandler,            /* UART8 global interrupt */
	UART9_IRQHandler,            /* UART9 global interrupt */
	LPUART1_IRQHandler,          /* LPUART1 global interrupt */
	SPI4_IRQHandler,             /* SPI4 global interrupt */
	SPI5_IRQHandler,             /* SPI5 global interrupt */
	SPI6_IRQHandler,             /* SPI6 global interrupt */
	SPI7_IRQHandler,             /* SPI7 global interrupt */
	SPI8_IRQHandler,             /* SPI8 global interrupt */
	SAI1_IRQHandler,             /* SAI1 global interrupt */
	LTDC_IRQHandler,             /* LTDC global interrupt */
	LTDC_ER_IRQHandler,          /* LTDC global error interrupt */
	LTDC_SEC_IRQHandler,         /* LTDC security global interrupt */
	LTDC_SEC_ER_IRQHandler,      /* LTDC security global error interrupt */
	SAI2_IRQHandler,             /* SAI2 global interrupt */
	OCTOSPI1_IRQHandler,         /* OCTOSPI1 global interrupt */
	OCTOSPI2_IRQHandler,         /* OCTOSPI2 global interrupt */
	OTFDEC1_IRQHandler,          /* OTFDEC1 interrupt */
	LPTIM1_IRQHandler,           /* LPTIMER1 global interrupt */
	VENC_IRQHandler,             /* VENC global interrupt */
	I2C4_IRQHandler,             /* I2C4 global interrupt */
	USBH_WAKEUP_IRQHandler,      /* USB Host remote wake up from USB2PHY1 interrupt */
	SPDIFRX_IRQHandler,          /* SPDIFRX global interrupt */
	IPCC1_RX_IRQHandler,         /* Mailbox 1 RX Occupied interrupt */
	IPCC1_TX_IRQHandler,         /* Mailbox 1 TX Free interrupt */
	IPCC1_RX_S_IRQHandler,       /* Mailbox 1 RX Occupied secure interrupt */
	IPCC1_TX_S_IRQHandler,       /* Mailbox 1 TX Free secure interrupt */
	IPCC2_RX_IRQHandler,         /* Mailbox 2 RX Occupied interrupt */
	IPCC2_TX_IRQHandler,         /* Mailbox 2 TX Free interrupt */
	IPCC2_RX_S_IRQHandler,       /* Mailbox 2 RX Occupied secure interrupt */
	IPCC2_TX_S_IRQHandler,       /* Mailbox 2 TX Free secure interrupt */
#if defined(STM32MP2_HAS_CRYPTO)
	SAES_IRQHandler,             /* Secure AES */
	CRYP2_IRQHandler,            /* Crypto2 interrupt */
#else /* STM32MP2_HAS_CRYPTO */
	0,
	0,
#endif /* STM32MP2_HAS_CRYPTO */
	I2C5_IRQHandler,             /* I2C5 global interrupt */
	USB3DR_WAKEUP_IRQHandler,    /* USB3 remote wake up from USB2PHY1 interrupt */
	GPU_IRQHandler,              /* GPU global Interrupt */
	MDF1_FLT0_IRQHandler,        /* MDF1 Filter0 interrupt */
	MDF1_FLT1_IRQHandler,        /* MDF1 Filter1 interrupt */
	MDF1_FLT2_IRQHandler,        /* MDF1 Filter2 interrupt */
	MDF1_FLT3_IRQHandler,        /* MDF1 Filter3 interrupt */
	MDF1_FLT4_IRQHandler,        /* MDF1 Filter4 interrupt */
	MDF1_FLT5_IRQHandler,        /* MDF1 Filter5 interrupt */
	MDF1_FLT6_IRQHandler,        /* MDF1 Filter6 interrupt */
	MDF1_FLT7_IRQHandler,        /* MDF1 Filter7 interrupt */
	SAI3_IRQHandler,             /* SAI3 global interrupt */
	TIM15_IRQHandler,            /* TIM15 global interrupt */
	TIM16_IRQHandler,            /* TIM16 global interrupt */
	TIM17_IRQHandler,            /* TIM17 global interrupt */
	TIM12_IRQHandler,            /* TIM12 global interrupt */
	SDMMC2_IRQHandler,           /* SDMMC2 global interrupt */
	DCMIPP_IRQHandler,           /* DCMIPP global interrupt */
	HSEM_IRQHandler,             /* HSEM nonsecure interrupt */
	HSEM_S_IRQHandler,           /* HSEM secure interrupt */
	nCTIIRQ1_IRQHandler,         /* Cortex-M33 CTI interrupt 1 */
	nCTIIRQ2_IRQHandler,         /* Cortex-M33 CTI interrupt 2 */
	TIM13_IRQHandler,            /* TIM13 global interrupt */
	TIM14_IRQHandler,            /* TIM14 global interrupt */
	TIM10_IRQHandler,            /* TIM10 global interrupt */
	RNG_IRQHandler,              /* RNG global interrupt */
	ADF1_FLT_IRQHandler,         /* ADF1 Filter interrupt */
	I2C6_IRQHandler,             /* I2C6 global interrupt */
	COMBOPHY_WAKEUP_IRQHandler,  /* COMBOPHY LFPS start request interrupt */
	I2C7_IRQHandler,             /* I2C7 global interrupt */
	0,
	I2C8_IRQHandler,             /* I2C8 global interrupt */
	I3C4_IRQHandler,             /* I3C4 global interrupt */
	SDMMC3_IRQHandler,           /* SDMMC3 global interrupt */
	LPTIM2_IRQHandler,           /* LPTIMER2 global interrupt */
	LPTIM3_IRQHandler,           /* LPTIMER3 global interrupt */
	LPTIM4_IRQHandler,           /* LPTIMER4 global interrupt */
	LPTIM5_IRQHandler,           /* LPTIMER5 global interrupt */
	OTFDEC2_IRQHandler,          /* OTFDEC2 interrupt */
	CPU1_SEV_IRQHandler,         /* Cortex-A35 Send Event through EXTI */
	CPU3_SEV_IRQHandler,         /* Cortex-M0+ Send Event through EXTI */
	RCC_WAKEUP_IRQHandler,       /* RCC CPU2 Wake up interrupt */
	SAI4_IRQHandler,             /* SAI4 global interrupt */
	DTS_IRQHandler,              /* Temperature sensor interrupt */
	TIM11_IRQHandler,            /* TIMER11 global interrupt */
	CPU2_WAKEUP_PIN_IRQHandler,  /* Interrupt for all 6 wake-up enabled by CPU2 */
	USB3DR_BC_IRQHandler,        /* USB3 BC interrupt */
	USB3DR_IRQHandler,           /* USB3 interrupt */
	UCPD1_IRQHandler,            /* USB PD interrupt */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	SERF_IRQHandler,             /* SERF global interrupt */
	BUSPERFM_IRQHandler,         /* BUS Performance Monitor interrupt */
	RAMCFG_IRQHandler,           /* RAM configuration global interrupt */
	DDRCTRL_IRQHandler,          /* DDRCTRL interrupt */
	DDRPHYC_IRQHandler,          /* DDRPHY interrupt (active low) */
	DFI_ERR_IRQHandler,          /* DDRPHY DFI error interrupt */
	IAC_IRQHandler,              /* RIF Illegal access Controller interrupt */
	VDDCPU_VD_IRQHandler,        /* VDDCPU voltage detector interrupt */
	VDDCORE_VD_IRQHandler,       /* VDDCORE voltage detector interrupt */
	0,
	ETHSW_IRQHandler,            /* Ethernet Switch global interrupt */
	ETHSW_MSGBUF_IRQHandler,     /* Ethernet ACM Message buffer interrupt */
	ETHSW_FSC_IRQHandler,        /* Ethernet ACM Scheduler interrupt */
	HPDMA1_WKUP_IRQHandler,      /* HPDMA1 channel 0 to 15 wake up */
	HPDMA2_WKUP_IRQHandler,      /* HPDMA2 channel 0 to 15 wake up */
	HPDMA3_WKUP_IRQHandler,      /* HPDMA3 channel 0 to 15 wake up */
	LPDMA_WKUP_IRQHandler,       /* LPDMA channel 0 to 3 wake up */
	UCPD1_VBUS_IRQHandler,       /* USB TypeC VBUS valid interrupt */
	UCPD1_VSAFE5V_IRQHandler,    /* USB TypeC VSAFE5V valid interrupt */
	RCC_HSI_FMON_IRQHandler,     /* HSI Frequency Monitor interrupt */
	VDDGPU_VD_IRQHandler,        /* VDDGPU voltage detector interrupt */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	EXTI1_0_IRQHandler,          /* EXTI1 Line 0 interrupt */
	EXTI1_1_IRQHandler,          /* EXTI1 Line 1 interrupt */
	EXTI1_2_IRQHandler,          /* EXTI1 Line 2 interrupt */
	EXTI1_3_IRQHandler,          /* EXTI1 Line 3 interrupt */
	EXTI1_4_IRQHandler,          /* EXTI1 Line 4 interrupt */
	EXTI1_5_IRQHandler,          /* EXTI1 Line 5 interrupt */
	EXTI1_6_IRQHandler,          /* EXTI1 Line 6 interrupt */
	EXTI1_7_IRQHandler,          /* EXTI1 Line 7 interrupt */
	EXTI1_8_IRQHandler,          /* EXTI1 Line 8 interrupt */
	EXTI1_9_IRQHandler,          /* EXTI1 Line 9 interrupt */
	EXTI1_10_IRQHandler,         /* EXTI1 Line 10 interrupt */
	EXTI1_11_IRQHandler,         /* EXTI1 Line 11 interrupt */
	EXTI1_12_IRQHandler,         /* EXTI1 Line 12 interrupt */
	EXTI1_13_IRQHandler,         /* EXTI1 Line 13 interrupt */
	EXTI1_14_IRQHandler,         /* EXTI1 Line 14 interrupt */
	EXTI1_15_IRQHandler,         /* EXTI1 Line 15 interrupt */
	RESERVED_284_IRQHandler,
	RESERVED_285_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	IS2M_IRQHandler,             /* IS2M fault detection interrupt */
	0,
	DDRPERFM_IRQHandler,         /* DDR Performance Monitor interrupt */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
	__disable_irq();
	__set_PSP((uint32_t)(&__INITIAL_SP));

	__set_MSPLIM((uint32_t)(&__STACK_LIMIT));
	__set_PSPLIM((uint32_t)(&__STACK_LIMIT));
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
	__TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

	SystemInit();                             /* CMSIS System Initialization */
	__PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

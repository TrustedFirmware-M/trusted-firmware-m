/*
 * Prototypes for common nRF54L interrupt handlers used in vector tables.
 * These are defined as weak defaults in startup_nrf54l_common.c.
 */

#ifndef STARTUP_NRF54L_COMMON_H
#define STARTUP_NRF54L_COMMON_H

#include "startup.h"

/* Core/system exceptions */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SecureFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

/* Shared nRF54L IRQ handlers */
void SWI00_IRQHandler(void);
void SWI01_IRQHandler(void);
void SWI02_IRQHandler(void);
void SWI03_IRQHandler(void);
void AAR00_CCM00_IRQHandler(void);
void ECB00_IRQHandler(void);
void SERIAL00_IRQHandler(void);
void RRAMC_IRQHandler(void);
void VPR00_IRQHandler(void);
void CTRLAP_IRQHandler(void);
void CM33SS_IRQHandler(void);
void TIMER00_IRQHandler(void);
void TIMER10_IRQHandler(void);
void RTC10_IRQHandler(void);
void EGU10_IRQHandler(void);
void AAR10_CCM10_IRQHandler(void);
void ECB10_IRQHandler(void);
void RADIO_0_IRQHandler(void);
void RADIO_1_IRQHandler(void);
void SERIAL20_IRQHandler(void);
void SERIAL21_IRQHandler(void);
void SERIAL22_IRQHandler(void);
void EGU20_IRQHandler(void);
void TIMER20_IRQHandler(void);
void TIMER21_IRQHandler(void);
void TIMER22_IRQHandler(void);
void TIMER23_IRQHandler(void);
void TIMER24_IRQHandler(void);
void PWM20_IRQHandler(void);
void PWM21_IRQHandler(void);
void PWM22_IRQHandler(void);
void SAADC_IRQHandler(void);
void NFCT_IRQHandler(void);
void TEMP_IRQHandler(void);
void GPIOTE20_1_IRQHandler(void);
void TAMPC_IRQHandler(void);
void I2S20_IRQHandler(void);
void QDEC20_IRQHandler(void);
void QDEC21_IRQHandler(void);
void GRTC_0_IRQHandler(void);
void GRTC_1_IRQHandler(void);
void GRTC_2_IRQHandler(void);
void GRTC_3_IRQHandler(void);
void SERIAL30_IRQHandler(void);
void CLOCK_POWER_IRQHandler(void);
void COMP_LPCOMP_IRQHandler(void);
void WDT30_IRQHandler(void);
void WDT31_IRQHandler(void);
void GPIOTE30_1_IRQHandler(void);

/* Conditionally defaulted in common file, but declare always for visibility */
void MPC00_IRQHandler(void);
void SPU00_IRQHandler(void);
void SPU10_IRQHandler(void);
void SPU20_IRQHandler(void);
void SPU30_IRQHandler(void);
void CRACEN_IRQHandler(void);

#endif /* STARTUP_NRF54L_COMMON_H */

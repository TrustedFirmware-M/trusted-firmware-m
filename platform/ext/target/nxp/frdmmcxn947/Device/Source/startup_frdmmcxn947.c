/*
 * Copyright (c) 2022 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

/* NS linker scripts using the default CMSIS style naming conventions, while the
 * secure and bl2 linker scripts remain untouched (region.h compatibility).
 * To be compatible with the untouched files (which using ARMCLANG naming style),
 * we have to override __INITIAL_SP and __STACK_LIMIT labels. */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) 
#include "cmsis_override.h"
#endif

#include "cmsis.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

typedef void(*VECTOR_TABLE_Type)(void);

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/

void default_handler (void);
void default_handler (void) {
    while(1);
}

#define DEFAULT_IRQ_HANDLER(handler_name)  \
void handler_name (void) __attribute__((weak, alias("default_handler")));

#define DEFAULT_DRIVER_IRQ_HANDLER(handler_name, driver_handler_name)  \
DEFAULT_IRQ_HANDLER(driver_handler_name) \
void __WEAK handler_name (void); \
void handler_name (void) { \
    driver_handler_name(); \
}

DEFAULT_IRQ_HANDLER(DefaultISR)

/* Exceptions */
DEFAULT_IRQ_HANDLER(NMI_Handler)
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)

/* Driver Exceptions */
DEFAULT_DRIVER_IRQ_HANDLER(OR_IRQHandler, OR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH0_IRQHandler, EDMA_0_CH0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH1_IRQHandler, EDMA_0_CH1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH2_IRQHandler, EDMA_0_CH2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH3_IRQHandler, EDMA_0_CH3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH4_IRQHandler, EDMA_0_CH4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH5_IRQHandler, EDMA_0_CH5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH6_IRQHandler, EDMA_0_CH6_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH7_IRQHandler, EDMA_0_CH7_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH8_IRQHandler, EDMA_0_CH8_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH9_IRQHandler, EDMA_0_CH9_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH10_IRQHandler, EDMA_0_CH10_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH11_IRQHandler, EDMA_0_CH11_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH12_IRQHandler, EDMA_0_CH12_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH13_IRQHandler, EDMA_0_CH13_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH14_IRQHandler, EDMA_0_CH14_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_0_CH15_IRQHandler, EDMA_0_CH15_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO00_IRQHandler, GPIO00_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO01_IRQHandler, GPIO01_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO10_IRQHandler, GPIO10_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO11_IRQHandler, GPIO11_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO20_IRQHandler, GPIO20_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO21_IRQHandler, GPIO21_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO30_IRQHandler, GPIO30_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO31_IRQHandler, GPIO31_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO40_IRQHandler, GPIO40_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO41_IRQHandler, GPIO41_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO50_IRQHandler, GPIO50_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO51_IRQHandler, GPIO51_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(UTICK0_IRQHandler, UTICK0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MRT0_IRQHandler, MRT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER0_IRQHandler, CTIMER0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER1_IRQHandler, CTIMER1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SCT0_IRQHandler, SCT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER2_IRQHandler, CTIMER2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM0_IRQHandler, LP_FLEXCOMM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM1_IRQHandler, LP_FLEXCOMM1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM2_IRQHandler, LP_FLEXCOMM2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM3_IRQHandler, LP_FLEXCOMM3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM4_IRQHandler, LP_FLEXCOMM4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM5_IRQHandler, LP_FLEXCOMM5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM6_IRQHandler, LP_FLEXCOMM6_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM7_IRQHandler, LP_FLEXCOMM7_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM8_IRQHandler, LP_FLEXCOMM8_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LP_FLEXCOMM9_IRQHandler, LP_FLEXCOMM9_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ADC0_IRQHandler, ADC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ADC1_IRQHandler, ADC1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PINT0_IRQHandler, PINT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PDM_EVENT_IRQHandler, PDM_EVENT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved65_IRQHandler, Reserved65_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB0_FS_IRQHandler, USB0_FS_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB0_DCD_IRQHandler, USB0_DCD_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RTC_IRQHandler, RTC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SMARTDMA_IRQHandler, SMARTDMA_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MAILBOX_IRQHandler, MAILBOX_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER3_IRQHandler, CTIMER3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER4_IRQHandler, CTIMER4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(OS_EVENT_IRQHandler, OS_EVENT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXSPI0_IRQHandler, FLEXSPI0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SAI0_IRQHandler, SAI0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SAI1_IRQHandler, SAI1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USDHC0_IRQHandler, USDHC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CAN0_IRQHandler, CAN0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CAN1_IRQHandler, CAN1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved80_IRQHandler, Reserved80_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved81_IRQHandler, Reserved81_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB1_HS_PHY_IRQHandler, USB1_HS_PHY_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB1_HS_IRQHandler, USB1_HS_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SEC_HYPERVISOR_CALL_IRQHandler, SEC_HYPERVISOR_CALL_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved85_IRQHandler, Reserved85_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PLU_IRQHandler, PLU_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Freqme_IRQHandler, Freqme_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SEC_VIO_IRQHandler, SEC_VIO_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ELS_IRQHandler, ELS_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PKC_IRQHandler, PKC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PUF_IRQHandler, PUF_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PQ_IRQHandler, PQ_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH0_IRQHandler, EDMA_1_CH0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH1_IRQHandler, EDMA_1_CH1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH2_IRQHandler, EDMA_1_CH2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH3_IRQHandler, EDMA_1_CH3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH4_IRQHandler, EDMA_1_CH4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH5_IRQHandler, EDMA_1_CH5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH6_IRQHandler, EDMA_1_CH6_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH7_IRQHandler, EDMA_1_CH7_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH8_IRQHandler, EDMA_1_CH8_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH9_IRQHandler, EDMA_1_CH9_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH10_IRQHandler, EDMA_1_CH10_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH11_IRQHandler, EDMA_1_CH11_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH12_IRQHandler, EDMA_1_CH12_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH13_IRQHandler, EDMA_1_CH13_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH14_IRQHandler, EDMA_1_CH14_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EDMA_1_CH15_IRQHandler, EDMA_1_CH15_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CDOG0_IRQHandler, CDOG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CDOG1_IRQHandler, CDOG1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C0_IRQHandler, I3C0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C1_IRQHandler, I3C1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(NPU_IRQHandler, NPU_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GDET_IRQHandler, GDET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(VBAT0_IRQHandler, VBAT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EWM0_IRQHandler, EWM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TSI_END_OF_SCAN_IRQHandler, TSI_END_OF_SCAN_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TSI_OUT_OF_SCAN_IRQHandler, TSI_OUT_OF_SCAN_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EMVSIM0_IRQHandler, EMVSIM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EMVSIM1_IRQHandler, EMVSIM1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXIO_IRQHandler, FLEXIO_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DAC0_IRQHandler, DAC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DAC1_IRQHandler, DAC1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DAC2_IRQHandler, DAC2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(HSCMP0_IRQHandler, HSCMP0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(HSCMP1_IRQHandler, HSCMP1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(HSCMP2_IRQHandler, HSCMP2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_RELOAD_ERROR_IRQHandler, FLEXPWM0_RELOAD_ERROR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_FAULT_IRQHandler, FLEXPWM0_FAULT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE0_IRQHandler, FLEXPWM0_SUBMODULE0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE1_IRQHandler, FLEXPWM0_SUBMODULE1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE2_IRQHandler, FLEXPWM0_SUBMODULE2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM0_SUBMODULE3_IRQHandler, FLEXPWM0_SUBMODULE3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_RELOAD_ERROR_IRQHandler, FLEXPWM1_RELOAD_ERROR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_FAULT_IRQHandler, FLEXPWM1_FAULT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_SUBMODULE0_IRQHandler, FLEXPWM1_SUBMODULE0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_SUBMODULE1_IRQHandler, FLEXPWM1_SUBMODULE1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_SUBMODULE2_IRQHandler, FLEXPWM1_SUBMODULE2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXPWM1_SUBMODULE3_IRQHandler, FLEXPWM1_SUBMODULE3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC0_COMPARE_IRQHandler, ENC0_COMPARE_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC0_HOME_IRQHandler, ENC0_HOME_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC0_WDG_SAB_IRQHandler, ENC0_WDG_SAB_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC0_IDX_IRQHandler, ENC0_IDX_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC1_COMPARE_IRQHandler, ENC1_COMPARE_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC1_HOME_IRQHandler, ENC1_HOME_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC1_WDG_SAB_IRQHandler, ENC1_WDG_SAB_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ENC1_IDX_IRQHandler, ENC1_IDX_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ITRC0_IRQHandler, ITRC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(BSP32_IRQHandler, BSP32_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ELS_ERR_IRQHandler, ELS_ERR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PKC_ERR_IRQHandler, PKC_ERR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ERM_SINGLE_BIT_ERROR_IRQHandler, ERM_SINGLE_BIT_ERROR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ERM_MULTI_BIT_ERROR_IRQHandler, ERM_MULTI_BIT_ERROR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FMU0_IRQHandler, FMU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETHERNET_IRQHandler, ETHERNET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETHERNET_PMT_IRQHandler, ETHERNET_PMT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETHERNET_MACLP_IRQHandler, ETHERNET_MACLP_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SINC_FILTER_IRQHandler, SINC_FILTER_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPTMR0_IRQHandler, LPTMR0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPTMR1_IRQHandler, LPTMR1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SCG_IRQHandler, SCG_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SPC_IRQHandler, SPC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WUU_IRQHandler, WUU_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PORT_EFT_IRQHandler, PORT_EFT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETB0_IRQHandler, ETB0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SM3_IRQHandler, SM3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TRNG0_IRQHandler, TRNG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WWDT0_IRQHandler, WWDT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WWDT1_IRQHandler, WWDT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CMC0_IRQHandler, CMC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTI0_IRQHandler, CTI0_DriverIRQHandler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),            /*      Initial Stack Pointer */
  Reset_Handler,                     /* Reset Handler */
  NMI_Handler,                       /* NMI Handler*/
  HardFault_Handler,                 /* Hard Fault Handler*/
  MemManage_Handler,                 /* MPU Fault Handler*/
  BusFault_Handler,                  /* Bus Fault Handler*/
  UsageFault_Handler,                /* Usage Fault Handler*/
  SecureFault_Handler,               /* Secure Fault Handler */
  0,                                 /* Reserved*/
  0,                                 /* Reserved*/
  0,                                 /* Reserved*/
  SVC_Handler,                       /* SVCall Handler*/
  DebugMon_Handler,                  /* Debug Monitor Handler*/
  0,                                 /* Reserved*/
  PendSV_Handler,                    /* PendSV Handler*/
  SysTick_Handler,                   /* SysTick Handler*/

/* External Interrupts*/
  OR_IRQHandler,                               //OR IRQ
  EDMA_0_CH0_IRQHandler,                       //eDMA_0_CH0 error or transfer complete
  EDMA_0_CH1_IRQHandler,                       //eDMA_0_CH1 error or transfer complete
  EDMA_0_CH2_IRQHandler,                       //eDMA_0_CH2 error or transfer complete
  EDMA_0_CH3_IRQHandler,                       //eDMA_0_CH3 error or transfer complete
  EDMA_0_CH4_IRQHandler,                       //eDMA_0_CH4 error or transfer complete
  EDMA_0_CH5_IRQHandler,                       //eDMA_0_CH5 error or transfer complete
  EDMA_0_CH6_IRQHandler,                       //eDMA_0_CH6 error or transfer complete
  EDMA_0_CH7_IRQHandler,                       //eDMA_0_CH7 error or transfer complete
  EDMA_0_CH8_IRQHandler,                       //eDMA_0_CH8 error or transfer complete
  EDMA_0_CH9_IRQHandler,                       //eDMA_0_CH9 error or transfer complete
  EDMA_0_CH10_IRQHandler,                      //eDMA_0_CH10 error or transfer complete
  EDMA_0_CH11_IRQHandler,                      //eDMA_0_CH11 error or transfer complete
  EDMA_0_CH12_IRQHandler,                      //eDMA_0_CH12 error or transfer complete
  EDMA_0_CH13_IRQHandler,                      //eDMA_0_CH13 error or transfer complete
  EDMA_0_CH14_IRQHandler,                      //eDMA_0_CH14 error or transfer complete
  EDMA_0_CH15_IRQHandler,                      //eDMA_0_CH15 error or transfer complete
  GPIO00_IRQHandler,                           //GPIO0 interrupt 0
  GPIO01_IRQHandler,                           //GPIO0 interrupt 1
  GPIO10_IRQHandler,                           //GPIO1 interrupt 0
  GPIO11_IRQHandler,                           //GPIO1 interrupt 1
  GPIO20_IRQHandler,                           //GPIO2 interrupt 0
  GPIO21_IRQHandler,                           //GPIO2 interrupt 1
  GPIO30_IRQHandler,                           //GPIO3 interrupt 0
  GPIO31_IRQHandler,                           //GPIO3 interrupt 1
  GPIO40_IRQHandler,                           //GPIO4 interrupt 0
  GPIO41_IRQHandler,                           //GPIO4 interrupt 1
  GPIO50_IRQHandler,                           //GPIO5 interrupt 0
  GPIO51_IRQHandler,                           //GPIO5 interrupt 1
  UTICK0_IRQHandler,                           //Micro-Tick Timer interrupt
  MRT0_IRQHandler,                             //Multi-Rate Timer interrupt
  CTIMER0_IRQHandler,                          //Standard counter/timer 0 interrupt
  CTIMER1_IRQHandler,                          //Standard counter/timer 1 interrupt
  SCT0_IRQHandler,                             //SCTimer/PWM interrupt
  CTIMER2_IRQHandler,                          //Standard counter/timer 2 interrupt
  LP_FLEXCOMM0_IRQHandler,                     //LP_FLEXCOMM0 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM1_IRQHandler,                     //LP_FLEXCOMM1 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM2_IRQHandler,                     //LP_FLEXCOMM2 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM3_IRQHandler,                     //LP_FLEXCOMM3 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM4_IRQHandler,                     //LP_FLEXCOMM4 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM5_IRQHandler,                     //LP_FLEXCOMM5 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM6_IRQHandler,                     //LP_FLEXCOMM6 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM7_IRQHandler,                     //LP_FLEXCOMM7 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM8_IRQHandler,                     //LP_FLEXCOMM8 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  LP_FLEXCOMM9_IRQHandler,                     //LP_FLEXCOMM9 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
  ADC0_IRQHandler,                             //Analog-to-Digital Converter 0 - General Purpose interrupt
  ADC1_IRQHandler,                             //Analog-to-Digital Converter 1 - General Purpose interrupt
  PINT0_IRQHandler,                            //Pin Interrupt Pattern Match Interrupt
  PDM_EVENT_IRQHandler,                        //Microphone Interface interrupt
  Reserved65_IRQHandler,                       //Reserved interrupt
  USB0_FS_IRQHandler,                          //Universal Serial Bus - Full Speed interrupt
  USB0_DCD_IRQHandler,                         //Universal Serial Bus - Device Charge Detect interrupt
  RTC_IRQHandler,                              //RTC Subsystem interrupt (RTC interrupt or Wake timer interrupt)
  SMARTDMA_IRQHandler,                         //SmartDMA_IRQ
  MAILBOX_IRQHandler,                          //Inter-CPU Mailbox interrupt0 for CPU0 Inter-CPU Mailbox interrupt1 for CPU1
  CTIMER3_IRQHandler,                          //Standard counter/timer 3 interrupt
  CTIMER4_IRQHandler,                          //Standard counter/timer 4 interrupt
  OS_EVENT_IRQHandler,                         //OS event timer interrupt
  FLEXSPI0_IRQHandler,                         //Flexible Serial Peripheral Interface interrupt
  SAI0_IRQHandler,                             //Serial Audio Interface 0 interrupt
  SAI1_IRQHandler,                             //Serial Audio Interface 1 interrupt
  USDHC0_IRQHandler,                           //Ultra Secured Digital Host Controller interrupt
  CAN0_IRQHandler,                             //Controller Area Network 0 interrupt
  CAN1_IRQHandler,                             //Controller Area Network 1 interrupt
  Reserved80_IRQHandler,                       //Reserved interrupt
  Reserved81_IRQHandler,                       //Reserved interrupt
  USB1_HS_PHY_IRQHandler,                      //USBHS DCD or USBHS Phy interrupt
  USB1_HS_IRQHandler,                          //USB High Speed OTG Controller interrupt
  SEC_HYPERVISOR_CALL_IRQHandler,              //AHB Secure Controller hypervisor call interrupt
  Reserved85_IRQHandler,                       //Reserved interrupt
  PLU_IRQHandler,                              //Programmable Logic Unit interrupt
  Freqme_IRQHandler,                           //Frequency Measurement interrupt
  SEC_VIO_IRQHandler,                          //Secure violation interrupt (Memory Block Checker interrupt or secure AHB matrix violation interrupt)
  ELS_IRQHandler,                              //ELS interrupt
  PKC_IRQHandler,                              //PKC interrupt
  PUF_IRQHandler,                              //Physical Unclonable Function interrupt
  PQ_IRQHandler,                               //Power Quad interrupt
  EDMA_1_CH0_IRQHandler,                       //eDMA_1_CH0 error or transfer complete
  EDMA_1_CH1_IRQHandler,                       //eDMA_1_CH1 error or transfer complete
  EDMA_1_CH2_IRQHandler,                       //eDMA_1_CH2 error or transfer complete
  EDMA_1_CH3_IRQHandler,                       //eDMA_1_CH3 error or transfer complete
  EDMA_1_CH4_IRQHandler,                       //eDMA_1_CH4 error or transfer complete
  EDMA_1_CH5_IRQHandler,                       //eDMA_1_CH5 error or transfer complete
  EDMA_1_CH6_IRQHandler,                       //eDMA_1_CH6 error or transfer complete
  EDMA_1_CH7_IRQHandler,                       //eDMA_1_CH7 error or transfer complete
  EDMA_1_CH8_IRQHandler,                       //eDMA_1_CH8 error or transfer complete
  EDMA_1_CH9_IRQHandler,                       //eDMA_1_CH9 error or transfer complete
  EDMA_1_CH10_IRQHandler,                      //eDMA_1_CH10 error or transfer complete
  EDMA_1_CH11_IRQHandler,                      //eDMA_1_CH11 error or transfer complete
  EDMA_1_CH12_IRQHandler,                      //eDMA_1_CH12 error or transfer complete
  EDMA_1_CH13_IRQHandler,                      //eDMA_1_CH13 error or transfer complete
  EDMA_1_CH14_IRQHandler,                      //eDMA_1_CH14 error or transfer complete
  EDMA_1_CH15_IRQHandler,                      //eDMA_1_CH15 error or transfer complete
  CDOG0_IRQHandler,                            //Code Watchdog Timer 0 interrupt
  CDOG1_IRQHandler,                            //Code Watchdog Timer 1 interrupt
  I3C0_IRQHandler,                             //Improved Inter Integrated Circuit interrupt 0
  I3C1_IRQHandler,                             //Improved Inter Integrated Circuit interrupt 1
  NPU_IRQHandler,                              //NPU interrupt
  GDET_IRQHandler,                             //Digital Glitch Detect 0 interrupt  or Digital Glitch Detect 1 interrupt
  VBAT0_IRQHandler,                            //VBAT interrupt( VBAT interrupt or digital tamper interrupt)
  EWM0_IRQHandler,                             //External Watchdog Monitor interrupt
  TSI_END_OF_SCAN_IRQHandler,                  //TSI End of Scan interrupt
  TSI_OUT_OF_SCAN_IRQHandler,                  //TSI Out of Scan interrupt
  EMVSIM0_IRQHandler,                          //EMVSIM0 interrupt
  EMVSIM1_IRQHandler,                          //EMVSIM1 interrupt
  FLEXIO_IRQHandler,                           //Flexible Input/Output interrupt
  DAC0_IRQHandler,                             //Digital-to-Analog Converter 0 - General Purpose interrupt
  DAC1_IRQHandler,                             //Digital-to-Analog Converter 1 - General Purpose interrupt
  DAC2_IRQHandler,                             //14-bit Digital-to-Analog Converter interrupt
  HSCMP0_IRQHandler,                           //High-Speed comparator0 interrupt
  HSCMP1_IRQHandler,                           //High-Speed comparator1 interrupt
  HSCMP2_IRQHandler,                           //High-Speed comparator2 interrupt
  FLEXPWM0_RELOAD_ERROR_IRQHandler,            //FlexPWM0_reload_error interrupt
  FLEXPWM0_FAULT_IRQHandler,                   //FlexPWM0_fault interrupt
  FLEXPWM0_SUBMODULE0_IRQHandler,              //FlexPWM0 Submodule 0 capture/compare/reload interrupt
  FLEXPWM0_SUBMODULE1_IRQHandler,              //FlexPWM0 Submodule 1 capture/compare/reload interrupt
  FLEXPWM0_SUBMODULE2_IRQHandler,              //FlexPWM0 Submodule 2 capture/compare/reload interrupt
  FLEXPWM0_SUBMODULE3_IRQHandler,              //FlexPWM0 Submodule 3 capture/compare/reload interrupt
  FLEXPWM1_RELOAD_ERROR_IRQHandler,            //FlexPWM1_reload_error interrupt
  FLEXPWM1_FAULT_IRQHandler,                   //FlexPWM1_fault interrupt
  FLEXPWM1_SUBMODULE0_IRQHandler,              //FlexPWM1 Submodule 0 capture/compare/reload interrupt
  FLEXPWM1_SUBMODULE1_IRQHandler,              //FlexPWM1 Submodule 1 capture/compare/reload interrupt
  FLEXPWM1_SUBMODULE2_IRQHandler,              //FlexPWM1 Submodule 2 capture/compare/reload interrupt
  FLEXPWM1_SUBMODULE3_IRQHandler,              //FlexPWM1 Submodule 3 capture/compare/reload interrupt
  ENC0_COMPARE_IRQHandler,                     //ENC0_Compare interrupt
  ENC0_HOME_IRQHandler,                        //ENC0_Home interrupt
  ENC0_WDG_SAB_IRQHandler,                     //ENC0_WDG_IRQ/SAB interrupt
  ENC0_IDX_IRQHandler,                         //ENC0_IDX interrupt
  ENC1_COMPARE_IRQHandler,                     //ENC1_Compare interrupt
  ENC1_HOME_IRQHandler,                        //ENC1_Home interrupt
  ENC1_WDG_SAB_IRQHandler,                     //ENC1_WDG_IRQ/SAB interrupt
  ENC1_IDX_IRQHandler,                         //ENC1_IDX interrupt
  ITRC0_IRQHandler,                            //Intrusion and Tamper Response Controller interrupt
  BSP32_IRQHandler,                            //CoolFlux BSP32 interrupt
  ELS_ERR_IRQHandler,                          //ELS error interrupt
  PKC_ERR_IRQHandler,                          //PKC error interrupt
  ERM_SINGLE_BIT_ERROR_IRQHandler,             //ERM Single Bit error interrupt
  ERM_MULTI_BIT_ERROR_IRQHandler,              //ERM Multi Bit error interrupt
  FMU0_IRQHandler,                             //Flash Management Unit interrupt
  ETHERNET_IRQHandler,                         //Ethernet QoS interrupt
  ETHERNET_PMT_IRQHandler,                     //Ethernet QoS power management interrupt
  ETHERNET_MACLP_IRQHandler,                   //Ethernet QoS MAC interrupt
  SINC_FILTER_IRQHandler,                      //SINC Filter interrupt
  LPTMR0_IRQHandler,                           //Low Power Timer 0 interrupt
  LPTMR1_IRQHandler,                           //Low Power Timer 1 interrupt
  SCG_IRQHandler,                              //System Clock Generator interrupt
  SPC_IRQHandler,                              //System Power Controller interrupt
  WUU_IRQHandler,                              //Wake Up Unit interrupt
  PORT_EFT_IRQHandler,                         //PORT0~5 EFT interrupt
  ETB0_IRQHandler,                             //ETB counter expires interrupt
  SM3_IRQHandler,                              //Secure Generic Interface (SGI) SAFO interrupt
  TRNG0_IRQHandler,                            //True Random Number Generator interrupt
  WWDT0_IRQHandler,                            //Windowed Watchdog Timer 0 interrupt
  WWDT1_IRQHandler,                            //Windowed Watchdog Timer 1 interrupt
  CMC0_IRQHandler,                             //Core Mode Controller interrupt
  CTI0_IRQHandler,                             //Cross Trigger Interface interrupt
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();                             /* CMSIS System Initialization */
    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

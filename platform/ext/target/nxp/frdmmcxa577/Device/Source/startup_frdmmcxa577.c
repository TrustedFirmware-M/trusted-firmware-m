/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
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

#if defined(TFM_COPY_ZERO_TABLES_REQUIRED)
#include "tfm_copy_zero_tables.h"
#endif /* TFM_COPY_ZERO_TABLES_REQUIRED */

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

DEFAULT_DRIVER_IRQ_HANDLER(Reserved16_IRQHandler, Reserved16_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CMC_IRQHandler, CMC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH0_IRQHandler, DMA0_CH0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH1_IRQHandler, DMA0_CH1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH2_IRQHandler, DMA0_CH2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH3_IRQHandler, DMA0_CH3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH4_IRQHandler, DMA0_CH4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH5_IRQHandler, DMA0_CH5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH6_IRQHandler, DMA0_CH6_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH7_IRQHandler, DMA0_CH7_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ERM0_SINGLE_BIT_IRQHandler, ERM0_SINGLE_BIT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ERM0_MULTI_BIT_IRQHandler, ERM0_MULTI_BIT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FMU0_IRQHandler, FMU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GLIKEY0_IRQHandler, GLIKEY0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(MBC0_IRQHandler, MBC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SCG0_IRQHandler, SCG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SPC0_IRQHandler, SPC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TDET_IRQHandler, TDET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WUU0_IRQHandler, WUU0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CAN0_IRQHandler, CAN0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CAN1_IRQHandler, CAN1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved37_IRQHandler, Reserved37_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved38_IRQHandler, Reserved38_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXIO_IRQHandler, FLEXIO_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C0_IRQHandler, I3C0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C1_IRQHandler, I3C1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C0_IRQHandler, LPI2C0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C1_IRQHandler, LPI2C1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI0_IRQHandler, LPSPI0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI1_IRQHandler, LPSPI1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI2_IRQHandler, LPSPI2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART0_IRQHandler, LPUART0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART1_IRQHandler, LPUART1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART2_IRQHandler, LPUART2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART3_IRQHandler, LPUART3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART4_IRQHandler, LPUART4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved52_IRQHandler, Reserved52_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved53_IRQHandler, Reserved53_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CDOG0_IRQHandler, CDOG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER0_IRQHandler, CTIMER0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER1_IRQHandler, CTIMER1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER2_IRQHandler, CTIMER2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER3_IRQHandler, CTIMER3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CTIMER4_IRQHandler, CTIMER4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved60_IRQHandler, Reserved60_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved61_IRQHandler, Reserved61_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved62_IRQHandler, Reserved62_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved63_IRQHandler, Reserved63_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved64_IRQHandler, Reserved64_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved65_IRQHandler, Reserved65_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved66_IRQHandler, Reserved66_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved67_IRQHandler, Reserved67_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved68_IRQHandler, Reserved68_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved69_IRQHandler, Reserved69_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FREQME0_IRQHandler, FREQME0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPTMR0_IRQHandler, LPTMR0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved72_IRQHandler, Reserved72_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(OS_EVENT_IRQHandler, OS_EVENT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WAKETIMER0_IRQHandler, WAKETIMER0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(UTICK0_IRQHandler, UTICK0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WWDT0_IRQHandler, WWDT0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(WWDT1_IRQHandler, WWDT1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ADC0_IRQHandler, ADC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ADC1_IRQHandler, ADC1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CMP0_IRQHandler, CMP0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved81_IRQHandler, Reserved81_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved82_IRQHandler, Reserved82_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DAC0_IRQHandler, DAC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DAC1_IRQHandler, DAC1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved85_IRQHandler, Reserved85_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved86_IRQHandler, Reserved86_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO0_IRQHandler, GPIO0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO1_IRQHandler, GPIO1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO2_IRQHandler, GPIO2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO3_IRQHandler, GPIO3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO4_IRQHandler, GPIO4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO5_IRQHandler, GPIO5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C2_IRQHandler, LPI2C2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C3_IRQHandler, LPI2C3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved95_IRQHandler, Reserved95_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved96_IRQHandler, Reserved96_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved97_IRQHandler, Reserved97_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved98_IRQHandler, Reserved98_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved99_IRQHandler, Reserved99_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved100_IRQHandler, Reserved100_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved101_IRQHandler, Reserved101_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved102_IRQHandler, Reserved102_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved103_IRQHandler, Reserved103_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved104_IRQHandler, Reserved104_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ESPI_IRQHandler, ESPI_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETHERNET_IRQHandler, ETHERNET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ETHERNET_PMT_IRQHandler, ETHERNET_PMT_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved108_IRQHandler, Reserved108_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TENBASET_PHY0_IRQHandler, TENBASET_PHY0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C2_IRQHandler, I3C2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPUART5_IRQHandler, LPUART5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved112_IRQHandler, Reserved112_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI3_IRQHandler, LPSPI3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI4_IRQHandler, LPSPI4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPSPI5_IRQHandler, LPSPI5_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(LPI2C4_IRQHandler, LPI2C4_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(I3C3_IRQHandler, I3C3_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved118_IRQHandler, Reserved118_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB1_HS_IRQHandler, USB1_HS_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(USB1_HS_PHY_IRQHandler, USB1_HS_PHY_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved121_IRQHandler, Reserved121_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(FLEXSPI0_IRQHandler, FLEXSPI0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved123_IRQHandler, Reserved123_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SMARTDMA_IRQHandler, SMARTDMA_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(CDOG1_IRQHandler, CDOG1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(PKC_IRQHandler, PKC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SGI_IRQHandler, SGI_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SPI_FILTER_IRQHandler, SPI_FILTER_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TRNG0_IRQHandler, TRNG0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SECURE_ERR_IRQHandler, SECURE_ERR_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(SEC_HYPERVISOR_CALL_IRQHandler, SEC_HYPERVISOR_CALL_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved132_IRQHandler, Reserved132_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved133_IRQHandler, Reserved133_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved134_IRQHandler, Reserved134_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(RTC_IRQHandler, RTC_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved136_IRQHandler, Reserved136_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved137_IRQHandler, Reserved137_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GDET_IRQHandler, GDET_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(EWM0_IRQHandler, EWM0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TSI_END_OF_SCAN_IRQHandler, TSI_END_OF_SCAN_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(TSI_OUT_OF_SCAN_IRQHandler, TSI_OUT_OF_SCAN_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO0_1_IRQHandler, GPIO0_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO1_1_IRQHandler, GPIO1_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO2_1_IRQHandler, GPIO2_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO3_1_IRQHandler, GPIO3_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO4_1_IRQHandler, GPIO4_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(GPIO5_1_IRQHandler, GPIO5_1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved148_IRQHandler, Reserved148_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(ITRC0_IRQHandler, ITRC0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH8_IRQHandler, DMA0_CH8_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH9_IRQHandler, DMA0_CH9_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH10_IRQHandler, DMA0_CH10_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA0_CH11_IRQHandler, DMA0_CH11_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved154_IRQHandler, Reserved154_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved155_IRQHandler, Reserved155_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved156_IRQHandler, Reserved156_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(Reserved157_IRQHandler, Reserved157_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA1_CH0_IRQHandler, DMA1_CH0_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA1_CH1_IRQHandler, DMA1_CH1_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA1_CH2_IRQHandler, DMA1_CH2_DriverIRQHandler)
DEFAULT_DRIVER_IRQ_HANDLER(DMA1_CH3_IRQHandler, DMA1_CH3_DriverIRQHandler)

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
    Reset_Handler,                                   /* Reset Handler */
    NMI_Handler,                                     /* NMI Handler*/
    HardFault_Handler,                               /* Hard Fault Handler*/
    MemManage_Handler,                               /* MPU Fault Handler*/
    BusFault_Handler,                                /* Bus Fault Handler*/
    UsageFault_Handler,                              /* Usage Fault Handler*/
    SecureFault_Handler,                             /* Secure Fault Handler*/
    0,                                               /* Reserved*/
    0,                                               /* Reserved*/
    0,                                               /* Reserved*/
    SVC_Handler,                                     /* SVCall Handler*/
    DebugMon_Handler,                                /* Debug Monitor Handler*/
    0,                                               /* Reserved*/
    PendSV_Handler,                                  /* PendSV Handler*/
    SysTick_Handler,                                 /* SysTick Handler*/

    // Chip Level - MCXA577
    Reserved16_IRQHandler,          // 16 : Reserved interrupt
    CMC_IRQHandler,                 // 17 : Core Mode Controller interrupt
    DMA0_CH0_IRQHandler,            // 18 : DMA3_0_CH0 error or transfer complete
    DMA0_CH1_IRQHandler,            // 19 : DMA3_0_CH1 error or transfer complete
    DMA0_CH2_IRQHandler,            // 20 : DMA3_0_CH2 error or transfer complete
    DMA0_CH3_IRQHandler,            // 21 : DMA3_0_CH3 error or transfer complete
    DMA0_CH4_IRQHandler,            // 22 : DMA3_0_CH4 error or transfer complete
    DMA0_CH5_IRQHandler,            // 23 : DMA3_0_CH5 error or transfer complete
    DMA0_CH6_IRQHandler,            // 24 : DMA3_0_CH6 error or transfer complete
    DMA0_CH7_IRQHandler,            // 25 : DMA3_0_CH7 error or transfer complete
    ERM0_SINGLE_BIT_IRQHandler,     // 26 : ERM Single Bit error interrupt
    ERM0_MULTI_BIT_IRQHandler,      // 27 : ERM Multi Bit error interrupt
    FMU0_IRQHandler,                // 28 : Flash Management Unit interrupt
    GLIKEY0_IRQHandler,             // 29 : GLIKEY Interrupt
    MBC0_IRQHandler,                // 30 : MBC secure violation interrupt
    SCG0_IRQHandler,                // 31 : System Clock Generator interrupt
    SPC0_IRQHandler,                // 32 : System Power Controller interrupt
    TDET_IRQHandler,                // 33 : TDET interrrupt
    WUU0_IRQHandler,                // 34 : Wake Up Unit interrupt
    CAN0_IRQHandler,                // 35 : Controller Area Network 0 interrupt
    CAN1_IRQHandler,                // 36 : Controller Area Network 1 interrupt
    Reserved37_IRQHandler,          // 37 : Reserved interrupt
    Reserved38_IRQHandler,          // 38 : Reserved interrupt
    FLEXIO_IRQHandler,              // 39 : Flexible Input/Output interrupt
    I3C0_IRQHandler,                // 40 : Improved Inter Integrated Circuit interrupt 0
    I3C1_IRQHandler,                // 41 : Improved Inter Integrated Circuit interrupt 1
    LPI2C0_IRQHandler,              // 42 : Low-Power Inter Integrated Circuit 0 interrupt
    LPI2C1_IRQHandler,              // 43 : Low-Power Inter Integrated Circuit 1 interrupt
    LPSPI0_IRQHandler,              // 44 : Low-Power Serial Peripheral Interface 0 interrupt
    LPSPI1_IRQHandler,              // 45 : Low-Power Serial Peripheral Interface 1 interrupt
    LPSPI2_IRQHandler,              // 46 : Low-Power Serial Peripheral Interface 2 interrupt
    LPUART0_IRQHandler,             // 47 : Low-Power Universal Asynchronous Receive/Transmit 0 interrupt
    LPUART1_IRQHandler,             // 48 : Low-Power Universal Asynchronous Receive/Transmit 1 interrupt
    LPUART2_IRQHandler,             // 49 : Low-Power Universal Asynchronous Receive/Transmit 2 interrupt
    LPUART3_IRQHandler,             // 50 : Low-Power Universal Asynchronous Receive/Transmit 3 interrupt
    LPUART4_IRQHandler,             // 51 : Low-Power Universal Asynchronous Receive/Transmit 4 interrupt
    Reserved52_IRQHandler,          // 52 : Reserved interrupt
    Reserved53_IRQHandler,          // 53 : Reserved interrupt
    CDOG0_IRQHandler,               // 54 : Code Watchdog Timer 0 interrupt
    CTIMER0_IRQHandler,             // 55 : Standard counter/timer 0 interrupt
    CTIMER1_IRQHandler,             // 56 : Standard counter/timer 1 interrupt
    CTIMER2_IRQHandler,             // 57 : Standard counter/timer 2 interrupt
    CTIMER3_IRQHandler,             // 58 : Standard counter/timer 3 interrupt
    CTIMER4_IRQHandler,             // 59 : Standard counter/timer 4 interrupt
    Reserved60_IRQHandler,          // 60 : Reserved interrupt
    Reserved61_IRQHandler,          // 61 : Reserved interrupt
    Reserved62_IRQHandler,          // 62 : Reserved interrupt
    Reserved63_IRQHandler,          // 63 : Reserved interrupt
    Reserved64_IRQHandler,          // 64 : Reserved interrupt
    Reserved65_IRQHandler,          // 65 : Reserved interrupt
    Reserved66_IRQHandler,          // 66 : Reserved interrupt
    Reserved67_IRQHandler,          // 67 : Reserved interrupt
    Reserved68_IRQHandler,          // 68 : Reserved interrupt
    Reserved69_IRQHandler,          // 69 : Reserved interrupt
    FREQME0_IRQHandler,             // 70 : Frequency Measurement interrupt
    LPTMR0_IRQHandler,              // 71 : Low Power Timer 0 interrupt
    Reserved72_IRQHandler,          // 72 : Reserved interrupt
    OS_EVENT_IRQHandler,            // 73 : OS event timer interrupt
    WAKETIMER0_IRQHandler,          // 74 : Wake Timer Interrupt
    UTICK0_IRQHandler,              // 75 : Micro-Tick Timer interrupt
    WWDT0_IRQHandler,               // 76 : Windowed Watchdog Timer 0 interrupt
    WWDT1_IRQHandler,               // 77 : Windowed Watchdog Timer 2 interrupt
    ADC0_IRQHandler,                // 78 : Analog-to-Digital Converter 0 interrupt
    ADC1_IRQHandler,                // 79 : Analog-to-Digital Converter 1 interrupt
    CMP0_IRQHandler,                // 80 : Comparator 0 interrupt
    Reserved81_IRQHandler,          // 81 : Reserved interrupt
    Reserved82_IRQHandler,          // 82 : Reserved interrupt
    DAC0_IRQHandler,                // 83 : Digital-to-Analog Converter 0 - General Purpose interrupt
    DAC1_IRQHandler,                // 84 : Digital-to-Analog Converter 1 - General Purpose interrupt
    Reserved85_IRQHandler,          // 85 : Reserved interrupt
    Reserved86_IRQHandler,          // 86 : Reserved interrupt
    GPIO0_IRQHandler,               // 87 : General Purpose Input/Output 0 interrupt 0
    GPIO1_IRQHandler,               // 88 : General Purpose Input/Output 1 interrupt 0
    GPIO2_IRQHandler,               // 89 : General Purpose Input/Output 2 interrupt 0
    GPIO3_IRQHandler,               // 90 : General Purpose Input/Output 3 interrupt 0
    GPIO4_IRQHandler,               // 91 : General Purpose Input/Output 4 interrupt 0
    GPIO5_IRQHandler,               // 92 : General Purpose Input/Output 5 interrupt 0
    LPI2C2_IRQHandler,              // 93 : Low-Power Inter Integrated Circuit 2 interrupt
    LPI2C3_IRQHandler,              // 94 : Low-Power Inter Integrated Circuit 3 interrupt
    Reserved95_IRQHandler,          // 95 : Reserved interrupt
    Reserved96_IRQHandler,          // 96 : Reserved interrupt
    Reserved97_IRQHandler,          // 97 : Reserved interrupt
    Reserved98_IRQHandler,          // 98 : Reserved interrupt
    Reserved99_IRQHandler,          // 99 : Reserved interrupt
    Reserved100_IRQHandler,         // 100: Reserved interrupt
    Reserved101_IRQHandler,         // 101: Reserved interrupt
    Reserved102_IRQHandler,         // 102: Reserved interrupt
    Reserved103_IRQHandler,         // 103: Reserved interrupt
    Reserved104_IRQHandler,         // 104: Reserved interrupt
    ESPI_IRQHandler,                // 105: eSPI interrupt
    ETHERNET_IRQHandler,            // 106: Ethernet QoS interrupt
    ETHERNET_PMT_IRQHandler,        // 107: Ethernet QoS power management interrupt
    Reserved108_IRQHandler,         // 108: Reserved interrupt
    TENBASET_PHY0_IRQHandler,       // 109: 10Base-T1S interrupt
    I3C2_IRQHandler,                // 110: Improved Inter Integrated Circuit interrupt 2
    LPUART5_IRQHandler,             // 111: Low-Power Universal Asynchronous Receive/Transmit interrupt
    Reserved112_IRQHandler,         // 112: Reserved interrupt
    LPSPI3_IRQHandler,              // 113: Low-Power Serial Peripheral Interface 3 interrupt
    LPSPI4_IRQHandler,              // 114: Low-Power Serial Peripheral Interface 4 interrupt
    LPSPI5_IRQHandler,              // 115: Low-Power Serial Peripheral Interface 5 interrupt
    LPI2C4_IRQHandler,              // 116: Low-Power Inter Integrated Circuit 4 interrupt
    I3C3_IRQHandler,                // 117: Improved Inter Integrated Circuit interrupt 3
    Reserved118_IRQHandler,         // 118: Reserved interrupt
    USB1_HS_IRQHandler,             // 119: USB High Speed OTG Controller interrupt
    USB1_HS_PHY_IRQHandler,         // 120: USBHS DCD or USBHS Phy interrupt
    Reserved121_IRQHandler,         // 121: Reserved interrupt
    FLEXSPI0_IRQHandler,            // 122: Flexible Serial Peripheral Interface interrupt
    Reserved123_IRQHandler,         // 123: Reserved interrupt
    SMARTDMA_IRQHandler,            // 124: SmartDMA interrupt
    CDOG1_IRQHandler,               // 125: Code Watchdog Timer 1 interrupt
    PKC_IRQHandler,                 // 126: PKC interrupt
    SGI_IRQHandler,                 // 127: SGI interrupt
    SPI_FILTER_IRQHandler,          // 128: Reserved interrupt
    TRNG0_IRQHandler,               // 129: True Random Number Generator interrupt
    SECURE_ERR_IRQHandler,          // 130: Secure IP Error interrupt. It OR SGI, PKC, TRNG error together.
    SEC_HYPERVISOR_CALL_IRQHandler, // 131: AHB Secure Controller hypervisor call interrupt
    Reserved132_IRQHandler,         // 132: Reserved interrupt
    Reserved133_IRQHandler,         // 133: Reserved interrupt
    Reserved134_IRQHandler,         // 134: Reserved interrupt
    RTC_IRQHandler,                 // 135: RTC alarm interrupt
    Reserved136_IRQHandler,         // 136: Reserved interrupt
    Reserved137_IRQHandler,         // 137: Reserved interrupt
    GDET_IRQHandler,                // 138: Digital Glitch Detect 0 interrupt
    EWM0_IRQHandler,                // 139: External Watchdog Monitor interrupt
    TSI_END_OF_SCAN_IRQHandler,     // 140: TSI End of Scan interrupt
    TSI_OUT_OF_SCAN_IRQHandler,     // 141: TSI Out of Scan interrupt
    GPIO0_1_IRQHandler,             // 142: General Purpose Input/Output 0 interrupt 1
    GPIO1_1_IRQHandler,             // 143: General Purpose Input/Output 1 interrupt 1
    GPIO2_1_IRQHandler,             // 144: General Purpose Input/Output 2 interrupt 1
    GPIO3_1_IRQHandler,             // 145: General Purpose Input/Output 3 interrupt 1
    GPIO4_1_IRQHandler,             // 146: General Purpose Input/Output 4 interrupt 1
    GPIO5_1_IRQHandler,             // 147: General Purpose Input/Output 5 interrupt 1
    Reserved148_IRQHandler,         // 148: Reserved interrupt
    ITRC0_IRQHandler,               // 149: Intrusion and Tamper Response Controller interrupt
    DMA0_CH8_IRQHandler,            // 150: DMA3_0_CH8 error or transfer complete
    DMA0_CH9_IRQHandler,            // 151: DMA3_0_CH9 error or transfer complete
    DMA0_CH10_IRQHandler,           // 152: DMA3_0_CH10 error or transfer complete
    DMA0_CH11_IRQHandler,           // 153: DMA3_0_CH11 error or transfer complete
    Reserved154_IRQHandler,         // 154: Reserved interrupt
    Reserved155_IRQHandler,         // 155: Reserved interrupt
    Reserved156_IRQHandler,         // 156: Reserved interrupt
    Reserved157_IRQHandler,         // 157: Reserved interrupt
    DMA1_CH0_IRQHandler,            // 158: DMA3_1_CH0 error or transfer complete
    DMA1_CH1_IRQHandler,            // 159: DMA3_1_CH1 error or transfer complete
    DMA1_CH2_IRQHandler,            // 160: DMA3_1_CH2 error or transfer complete
    DMA1_CH3_IRQHandler,            // 161: DMA3_1_CH3 error or transfer complete
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

    /* CMSIS System Initialization */
    SystemInit();

#if defined(TFM_COPY_ZERO_TABLES_REQUIRED)
    /* Initialize regions not handled by the C runtime startup. */
    tfm_copy_zero_tables();
#endif /* TFM_COPY_ZERO_TABLES_REQUIRED */

    /* Enter PreMain (C library entry point) */
    __PROGRAM_START();
}

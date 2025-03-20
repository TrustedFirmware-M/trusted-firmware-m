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

/*
 * Define __VECTOR_TABLE_ATTRIBUTE (which can be provided by cmsis.h)
 * before including cmsis.h because TF-M's linker script
 * tfm_common_s.ld assumes the vector table section is called .vectors
 * while cmsis.h will sometimes (e.g. when cmsis is provided by nrfx)
 * default to using the name .isr_vector.
 */
#define __VECTOR_TABLE_ATTRIBUTE  __attribute__((used, section(".vectors")))

#include "cmsis.h"
#include "startup.h"
#include "exception_info.h"

__NO_RETURN __attribute__((naked)) void default_tfm_IRQHandler(void) {
	EXCEPTION_INFO();

	__ASM volatile(
        "BL        default_irq_handler     \n"
        "B         .                       \n"
    );
}

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

DEFAULT_IRQ_HANDLER(SWI00_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI01_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI02_IRQHandler)
DEFAULT_IRQ_HANDLER(SWI03_IRQHandler)
DEFAULT_IRQ_HANDLER(AAR00_CCM00_IRQHandler)
DEFAULT_IRQ_HANDLER(ECB00_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL00_IRQHandler)
DEFAULT_IRQ_HANDLER(RRAMC_IRQHandler)
DEFAULT_IRQ_HANDLER(VPR00_IRQHandler)
DEFAULT_IRQ_HANDLER(CTRLAP_IRQHandler)
DEFAULT_IRQ_HANDLER(CM33SS_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER00_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER10_IRQHandler)
DEFAULT_IRQ_HANDLER(RTC10_IRQHandler)
DEFAULT_IRQ_HANDLER(EGU10_IRQHandler)
DEFAULT_IRQ_HANDLER(AAR10_CCM10_IRQHandler)
DEFAULT_IRQ_HANDLER(ECB10_IRQHandler)
DEFAULT_IRQ_HANDLER(RADIO_0_IRQHandler)
DEFAULT_IRQ_HANDLER(RADIO_1_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL20_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL21_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL22_IRQHandler)
DEFAULT_IRQ_HANDLER(EGU20_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER20_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER21_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER22_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER23_IRQHandler)
DEFAULT_IRQ_HANDLER(TIMER24_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM20_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM21_IRQHandler)
DEFAULT_IRQ_HANDLER(PWM22_IRQHandler)
DEFAULT_IRQ_HANDLER(SAADC_IRQHandler)
DEFAULT_IRQ_HANDLER(NFCT_IRQHandler)
DEFAULT_IRQ_HANDLER(TEMP_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE20_1_IRQHandler)
DEFAULT_IRQ_HANDLER(TAMPC_IRQHandler)
DEFAULT_IRQ_HANDLER(I2S20_IRQHandler)
DEFAULT_IRQ_HANDLER(QDEC20_IRQHandler)
DEFAULT_IRQ_HANDLER(QDEC21_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_0_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_1_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_2_IRQHandler)
DEFAULT_IRQ_HANDLER(GRTC_3_IRQHandler)
DEFAULT_IRQ_HANDLER(SERIAL30_IRQHandler)
DEFAULT_IRQ_HANDLER(CLOCK_POWER_IRQHandler)
DEFAULT_IRQ_HANDLER(COMP_LPCOMP_IRQHandler)
DEFAULT_IRQ_HANDLER(WDT30_IRQHandler)
DEFAULT_IRQ_HANDLER(WDT31_IRQHandler)
DEFAULT_IRQ_HANDLER(GPIOTE30_1_IRQHandler)

#if defined(DOMAIN_NS) || defined(BL2)
DEFAULT_IRQ_HANDLER(MPC00_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU00_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU10_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU20_IRQHandler)
DEFAULT_IRQ_HANDLER(SPU30_IRQHandler)
DEFAULT_IRQ_HANDLER(CRACEN_IRQHandler)
#endif

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),     /*      Initial Stack Pointer */
/* Exceptions */
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,           /* MPU Fault Handler */
    BusFault_Handler,
    UsageFault_Handler,
    SecureFault_Handler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SVC_Handler,
    DebugMon_Handler,
    default_tfm_IRQHandler,
    PendSV_Handler,
    SysTick_Handler,
/* Device specific interrupt handlers */
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SWI00_IRQHandler,
    SWI01_IRQHandler,
    SWI02_IRQHandler,
    SWI03_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SPU00_IRQHandler,
    MPC00_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    AAR00_CCM00_IRQHandler,
    ECB00_IRQHandler,
    CRACEN_IRQHandler,
    default_tfm_IRQHandler,
    SERIAL00_IRQHandler,
    RRAMC_IRQHandler,
    VPR00_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    CTRLAP_IRQHandler,
    CM33SS_IRQHandler,
    default_tfm_IRQHandler,
    TIMER00_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SPU10_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    TIMER10_IRQHandler,
    RTC10_IRQHandler,
    EGU10_IRQHandler,
    AAR10_CCM10_IRQHandler,
    ECB10_IRQHandler,
    RADIO_0_IRQHandler,
    RADIO_1_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SPU20_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SERIAL20_IRQHandler,
    SERIAL21_IRQHandler,
    SERIAL22_IRQHandler,
    EGU20_IRQHandler,
    TIMER20_IRQHandler,
    TIMER21_IRQHandler,
    TIMER22_IRQHandler,
    TIMER23_IRQHandler,
    TIMER24_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    PWM20_IRQHandler,
    PWM21_IRQHandler,
    PWM22_IRQHandler,
    SAADC_IRQHandler,
    NFCT_IRQHandler,
    TEMP_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    GPIOTE20_1_IRQHandler,
    TAMPC_IRQHandler,
    I2S20_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    QDEC20_IRQHandler,
    QDEC21_IRQHandler,
    GRTC_0_IRQHandler,
    GRTC_1_IRQHandler,
    GRTC_2_IRQHandler,
    GRTC_3_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SPU30_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    SERIAL30_IRQHandler,
    CLOCK_POWER_IRQHandler,
    COMP_LPCOMP_IRQHandler,
    default_tfm_IRQHandler,
    WDT30_IRQHandler,
    WDT31_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    default_tfm_IRQHandler,
    GPIOTE30_1_IRQHandler,
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

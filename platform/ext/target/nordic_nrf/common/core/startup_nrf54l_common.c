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
 * This file contains common interrupt handlers shared by all nRF54L variants.
 * It should be included by the variant-specific startup files.
 */

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

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

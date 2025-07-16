/*
 * Copyright (c) 2025 Nordic Semiconductor ASA.
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
#include "target_cfg.h"
#include "region_defs.h"
#include "tfm_plat_defs.h"
#include "tfm_peripherals_config.h"
#include "tfm_plat_provisioning.h"
#include "utilities.h"
#include "region.h"
#include "array.h"
#include <nrfx.h>

#if TFM_PERIPHERAL_DCNF_SECURE
struct platform_data_t tfm_peripheral_dcnf = {
    NRF_DCNF_S_BASE,
    NRF_DCNF_S_BASE + (sizeof(NRF_DCNF_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_FPU_SECURE
struct platform_data_t tfm_peripheral_fpu = {
    NRF_FPU_S_BASE,
    NRF_FPU_S_BASE + (sizeof(NRF_FPU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_OSCILLATORS_SECURE
struct platform_data_t tfm_peripheral_oscillators = {
    NRF_OSCILLATORS_S_BASE,
    NRF_OSCILLATORS_S_BASE + (sizeof(NRF_OSCILLATORS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_REGULATORS_SECURE
struct platform_data_t tfm_peripheral_regulators = {
    NRF_REGULATORS_S_BASE,
    NRF_REGULATORS_S_BASE + (sizeof(NRF_REGULATORS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_CLOCK_SECURE
struct platform_data_t tfm_peripheral_clock = {
    NRF_CLOCK_S_BASE,
    NRF_CLOCK_S_BASE + (sizeof(NRF_CLOCK_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_POWER_SECURE
struct platform_data_t tfm_peripheral_power = {
    NRF_POWER_S_BASE,
    NRF_POWER_S_BASE + (sizeof(NRF_POWER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_RESET_SECURE
struct platform_data_t tfm_peripheral_reset = {
    NRF_RESET_S_BASE,
    NRF_RESET_S_BASE + (sizeof(NRF_RESET_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM0_SECURE
struct platform_data_t tfm_peripheral_spim0 = {
    NRF_SPIM0_S_BASE,
    NRF_SPIM0_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM00_SECURE
struct platform_data_t tfm_peripheral_spim00 = {
    NRF_SPIM00_S_BASE,
    NRF_SPIM00_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM20_SECURE
struct platform_data_t tfm_peripheral_spim20 = {
    NRF_SPIM20_S_BASE,
    NRF_SPIM20_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM21_SECURE
struct platform_data_t tfm_peripheral_spim21 = {
    NRF_SPIM21_S_BASE,
    NRF_SPIM21_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM22_SECURE
struct platform_data_t tfm_peripheral_spim22 = {
    NRF_SPIM22_S_BASE,
    NRF_SPIM22_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM23_SECURE
struct platform_data_t tfm_peripheral_spim23 = {
    NRF_SPIM23_S_BASE,
    NRF_SPIM23_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM30_SECURE
struct platform_data_t tfm_peripheral_spim30 = {
    NRF_SPIM30_S_BASE,
    NRF_SPIM30_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIS0_SECURE
struct platform_data_t tfm_peripheral_spis0 = {
    NRF_SPIS0_S_BASE,
    NRF_SPIS0_S_BASE + (sizeof(NRF_SPIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIM0_SECURE
struct platform_data_t tfm_peripheral_twim0 = {
    NRF_TWIM0_S_BASE,
    NRF_TWIM0_S_BASE + (sizeof(NRF_TWIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIS0_SECURE
struct platform_data_t tfm_peripheral_twis0 = {
    NRF_TWIS0_S_BASE,
    NRF_TWIS0_S_BASE + (sizeof(NRF_TWIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE0_SECURE
struct platform_data_t tfm_peripheral_uarte0 = {
    NRF_UARTE0_S_BASE,
    NRF_UARTE0_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM1_SECURE
struct platform_data_t tfm_peripheral_spim1 = {
    NRF_SPIM1_S_BASE,
    NRF_SPIM1_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIS1_SECURE
struct platform_data_t tfm_peripheral_spis1 = {
    NRF_SPIS1_S_BASE,
    NRF_SPIS1_S_BASE + (sizeof(NRF_SPIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIM1_SECURE
struct platform_data_t tfm_peripheral_twim1 = {
    NRF_TWIM1_S_BASE,
    NRF_TWIM1_S_BASE + (sizeof(NRF_TWIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIS1_SECURE
struct platform_data_t tfm_peripheral_twis1 = {
    NRF_TWIS1_S_BASE,
    NRF_TWIS1_S_BASE + (sizeof(NRF_TWIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE1_SECURE
struct platform_data_t tfm_peripheral_uarte1 = {
    NRF_UARTE1_S_BASE,
    NRF_UARTE1_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM4_SECURE
struct platform_data_t tfm_peripheral_spim4 = {
    NRF_SPIM4_S_BASE,
    NRF_SPIM4_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM2_SECURE
struct platform_data_t tfm_peripheral_spim2 = {
    NRF_SPIM2_S_BASE,
    NRF_SPIM2_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIS2_SECURE
struct platform_data_t tfm_peripheral_spis2 = {
    NRF_SPIS2_S_BASE,
    NRF_SPIS2_S_BASE + (sizeof(NRF_SPIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIM2_SECURE
struct platform_data_t tfm_peripheral_twim2 = {
    NRF_TWIM2_S_BASE,
    NRF_TWIM2_S_BASE + (sizeof(NRF_TWIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIS2_SECURE
struct platform_data_t tfm_peripheral_twis2 = {
    NRF_TWIS2_S_BASE,
    NRF_TWIS2_S_BASE + (sizeof(NRF_TWIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE2_SECURE
struct platform_data_t tfm_peripheral_uarte2 = {
    NRF_UARTE2_S_BASE,
    NRF_UARTE2_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIM3_SECURE
struct platform_data_t tfm_peripheral_spim3 = {
    NRF_SPIM3_S_BASE,
    NRF_SPIM3_S_BASE + (sizeof(NRF_SPIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SPIS3_SECURE
struct platform_data_t tfm_peripheral_spis3 = {
    NRF_SPIS3_S_BASE,
    NRF_SPIS3_S_BASE + (sizeof(NRF_SPIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIM3_SECURE
struct platform_data_t tfm_peripheral_twim3 = {
    NRF_TWIM3_S_BASE,
    NRF_TWIM3_S_BASE + (sizeof(NRF_TWIM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TWIS3_SECURE
struct platform_data_t tfm_peripheral_twis3 = {
    NRF_TWIS3_S_BASE,
    NRF_TWIS3_S_BASE + (sizeof(NRF_TWIS_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE3_SECURE
struct platform_data_t tfm_peripheral_uarte3 = {
    NRF_UARTE3_S_BASE,
    NRF_UARTE3_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE00_SECURE
struct platform_data_t tfm_peripheral_uarte00 = {
    NRF_UARTE00_S_BASE,
    NRF_UARTE00_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE20_SECURE
struct platform_data_t tfm_peripheral_uarte20 = {
    NRF_UARTE20_S_BASE,
    NRF_UARTE20_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE21_SECURE
struct platform_data_t tfm_peripheral_uarte21 = {
    NRF_UARTE21_S_BASE,
    NRF_UARTE21_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE22_SECURE
struct platform_data_t tfm_peripheral_uarte22 = {
    NRF_UARTE22_S_BASE,
    NRF_UARTE22_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_UARTE30_SECURE
struct platform_data_t tfm_peripheral_uarte30 = {
    NRF_UARTE30_S_BASE,
    NRF_UARTE30_S_BASE + (sizeof(NRF_UARTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_SAADC_SECURE
struct platform_data_t tfm_peripheral_saadc = {
    NRF_SAADC_S_BASE,
    NRF_SAADC_S_BASE + (sizeof(NRF_SAADC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER0_SECURE
struct platform_data_t tfm_peripheral_timer0 = {
    NRF_TIMER0_S_BASE,
    NRF_TIMER0_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER00_SECURE
struct platform_data_t tfm_peripheral_timer00 = {
    NRF_TIMER00_S_BASE,
    NRF_TIMER00_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER10_SECURE
struct platform_data_t tfm_peripheral_timer10 = {
    NRF_TIMER10_S_BASE,
    NRF_TIMER10_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER20_SECURE
struct platform_data_t tfm_peripheral_timer20 = {
    NRF_TIMER20_S_BASE,
    NRF_TIMER20_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER21_SECURE
struct platform_data_t tfm_peripheral_timer21 = {
    NRF_TIMER21_S_BASE,
    NRF_TIMER21_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER22_SECURE
struct platform_data_t tfm_peripheral_timer22 = {
    NRF_TIMER22_S_BASE,
    NRF_TIMER22_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER23_SECURE
struct platform_data_t tfm_peripheral_timer23 = {
    NRF_TIMER23_S_BASE,
    NRF_TIMER23_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER24_SECURE
struct platform_data_t tfm_peripheral_timer24 = {
    NRF_TIMER24_S_BASE,
    NRF_TIMER24_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER1_SECURE
struct platform_data_t tfm_peripheral_timer1 = {
    NRF_TIMER1_S_BASE,
    NRF_TIMER1_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_TIMER2_SECURE
struct platform_data_t tfm_peripheral_timer2 = {
    NRF_TIMER2_S_BASE,
    NRF_TIMER2_S_BASE + (sizeof(NRF_TIMER_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_RTC0_SECURE
struct platform_data_t tfm_peripheral_rtc0 = {
    NRF_RTC0_S_BASE,
    NRF_RTC0_S_BASE + (sizeof(NRF_RTC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_RTC1_SECURE
struct platform_data_t tfm_peripheral_rtc1 = {
    NRF_RTC1_S_BASE,
    NRF_RTC1_S_BASE + (sizeof(NRF_RTC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_DPPI_SECURE
struct platform_data_t tfm_peripheral_dppi = {
    NRF_DPPIC_S_BASE,
    NRF_DPPIC_S_BASE + (sizeof(NRF_DPPIC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_WDT_SECURE
struct platform_data_t tfm_peripheral_wdt = {
    NRF_WDT_S_BASE,
    NRF_WDT_S_BASE + (sizeof(NRF_WDT_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_WDT0_SECURE
struct platform_data_t tfm_peripheral_wdt0 = {
    NRF_WDT0_S_BASE,
    NRF_WDT0_S_BASE + (sizeof(NRF_WDT_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_WDT1_SECURE
struct platform_data_t tfm_peripheral_wdt1 = {
    NRF_WDT1_S_BASE,
    NRF_WDT1_S_BASE + (sizeof(NRF_WDT_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_COMP_SECURE
struct platform_data_t tfm_peripheral_comp = {
    NRF_COMP_S_BASE,
    NRF_COMP_S_BASE + (sizeof(NRF_COMP_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_LPCOMP_SECURE
struct platform_data_t tfm_peripheral_lpcomp = {
    NRF_LPCOMP_S_BASE,
    NRF_LPCOMP_S_BASE + (sizeof(NRF_LPCOMP_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU0_SECURE
struct platform_data_t tfm_peripheral_egu0 = {
    NRF_EGU0_S_BASE,
    NRF_EGU0_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU1_SECURE
struct platform_data_t tfm_peripheral_egu1 = {
    NRF_EGU1_S_BASE,
    NRF_EGU1_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU2_SECURE
struct platform_data_t tfm_peripheral_egu2 = {
    NRF_EGU2_S_BASE,
    NRF_EGU2_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU3_SECURE
struct platform_data_t tfm_peripheral_egu3 = {
    NRF_EGU3_S_BASE,
    NRF_EGU3_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU4_SECURE
struct platform_data_t tfm_peripheral_egu4 = {
    NRF_EGU4_S_BASE,
    NRF_EGU4_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU5_SECURE
struct platform_data_t tfm_peripheral_egu5 = {
    NRF_EGU5_S_BASE,
    NRF_EGU5_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU10_SECURE
struct platform_data_t tfm_peripheral_egu10 = {
    NRF_EGU10_S_BASE,
    NRF_EGU10_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_EGU20_SECURE
struct platform_data_t tfm_peripheral_egu20 = {
    NRF_EGU20_S_BASE,
    NRF_EGU20_S_BASE + (sizeof(NRF_EGU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM0_SECURE
struct platform_data_t tfm_peripheral_pwm0 = {
    NRF_PWM0_S_BASE,
    NRF_PWM0_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM1_SECURE
struct platform_data_t tfm_peripheral_pwm1 = {
    NRF_PWM1_S_BASE,
    NRF_PWM1_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM2_SECURE
struct platform_data_t tfm_peripheral_pwm2 = {
    NRF_PWM2_S_BASE,
    NRF_PWM2_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM3_SECURE
struct platform_data_t tfm_peripheral_pwm3 = {
    NRF_PWM3_S_BASE,
    NRF_PWM3_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM20_SECURE
struct platform_data_t tfm_peripheral_pwm20 = {
    NRF_PWM20_S_BASE,
    NRF_PWM20_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM21_SECURE
struct platform_data_t tfm_peripheral_pwm21 = {
    NRF_PWM21_S_BASE,
    NRF_PWM21_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PWM22_SECURE
struct platform_data_t tfm_peripheral_pwm22 = {
    NRF_PWM22_S_BASE,
    NRF_PWM22_S_BASE + (sizeof(NRF_PWM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PDM0_SECURE
struct platform_data_t tfm_peripheral_pdm0 = {
    NRF_PDM0_S_BASE,
    NRF_PDM0_S_BASE + (sizeof(NRF_PDM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_PDM_SECURE
struct platform_data_t tfm_peripheral_pdm = {
    NRF_PDM_S_BASE,
    NRF_PDM_S_BASE + (sizeof(NRF_PDM_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_I2S0_SECURE
struct platform_data_t tfm_peripheral_i2s0 = {
    NRF_I2S0_S_BASE,
    NRF_I2S0_S_BASE + (sizeof(NRF_I2S_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_I2S_SECURE
struct platform_data_t tfm_peripheral_i2s = {
    NRF_I2S_S_BASE,
    NRF_I2S_S_BASE + (sizeof(NRF_I2S_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_IPC_SECURE
struct platform_data_t tfm_peripheral_ipc = {
    NRF_IPC_S_BASE,
    NRF_IPC_S_BASE + (sizeof(NRF_IPC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_FPU_SECURE
struct platform_data_t tfm_peripheral_fpu = {
    NRF_FPU_S_BASE,
    NRF_FPU_S_BASE + (sizeof(NRF_FPU_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_QSPI_SECURE
struct platform_data_t tfm_peripheral_qspi = {
    NRF_QSPI_S_BASE,
    NRF_QSPI_S_BASE + (sizeof(NRF_QSPI_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_NFCT_SECURE
struct platform_data_t tfm_peripheral_nfct = {
    NRF_NFCT_S_BASE,
    NRF_NFCT_S_BASE + (sizeof(NRF_NFCT_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_MUTEX_SECURE
struct platform_data_t tfm_peripheral_mutex = {
    NRF_MUTEX_S_BASE,
    NRF_MUTEX_S_BASE + (sizeof(NRF_MUTEX_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_QDEC0_SECURE
struct platform_data_t tfm_peripheral_qdec0 = {
    NRF_QDEC0_S_BASE,
    NRF_QDEC0_S_BASE + (sizeof(NRF_QDEC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_QDEC1_SECURE
struct platform_data_t tfm_peripheral_qdec1 = {
    NRF_QDEC1_S_BASE,
    NRF_QDEC1_S_BASE + (sizeof(NRF_QDEC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_USBD_SECURE
struct platform_data_t tfm_peripheral_usbd = {
    NRF_USBD_S_BASE,
    NRF_USBD_S_BASE + (sizeof(NRF_USBD_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_USBREG_SECURE
struct platform_data_t tfm_peripheral_usbreg = {
    NRF_USBREGULATOR_S_BASE,
    NRF_USBREGULATOR_S_BASE + (sizeof(NRF_USBREG_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_NVMC_SECURE
struct platform_data_t tfm_peripheral_nvmc = {
    NRF_NVMC_S_BASE,
    NRF_NVMC_S_BASE + (sizeof(NRF_NVMC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_GPIO0_SECURE
struct platform_data_t tfm_peripheral_gpio0 = {
    NRF_P0_S_BASE,
    NRF_P0_S_BASE + (sizeof(NRF_GPIO_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_GPIO1_SECURE
struct platform_data_t tfm_peripheral_gpio1 = {
    NRF_P1_S_BASE,
    NRF_P1_S_BASE + (sizeof(NRF_GPIO_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_VMC_SECURE
struct platform_data_t tfm_peripheral_vmc = {
    NRF_VMC_S_BASE,
    NRF_VMC_S_BASE + (sizeof(NRF_VMC_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_GPIOTE20_SECURE
struct platform_data_t tfm_peripheral_gpiote20 = {
    NRF_GPIOTE20_S_BASE,
    NRF_GPIOTE20_S_BASE + (sizeof(NRF_GPIOTE_Type) - 1),
};
#endif

#if TFM_PERIPHERAL_GPIOTE30_SECURE
struct platform_data_t tfm_peripheral_gpiote30 = {
    NRF_GPIOTE30_S_BASE,
    NRF_GPIOTE30_S_BASE + (sizeof(NRF_GPIOTE_Type) - 1),
};
#endif

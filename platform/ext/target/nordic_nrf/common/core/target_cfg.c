/*
 * Copyright (c) 2018-2020 Arm Limited. All rights reserved.
 * Copyright (c) 2020 Nordic Semiconductor ASA.
 * Copyright (c) 2021 Laird Connectivity.
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

#ifdef __NRF_TFM__
#include <zephyr/autoconf.h>
#endif

#include <spu.h>
#include <nrfx.h>

#include <hal/nrf_gpio.h>
#include <hal/nrf_spu.h>

#ifdef RRAMC_PRESENT
#include <nrfx_rramc.h>
#include <hal/nrf_rramc.h>

#if CONFIG_NRF_RRAM_WRITE_BUFFER_SIZE > 0
#define WRITE_BUFFER_SIZE CONFIG_NRF_RRAM_WRITE_BUFFER_SIZE
#else
#define WRITE_BUFFER_SIZE 0
#endif

#endif

#define SPU_ADDRESS_REGION    (0x50000000)
#define GET_SPU_SLAVE_INDEX(periph) ((periph.periph_start & 0x0003F000) >> 12)
#define GET_SPU_INSTANCE(periph) ((NRF_SPU_Type*)(SPU_ADDRESS_REGION | (periph.periph_start & 0x00FC0000)))


#ifdef CACHE_PRESENT
#include <hal/nrf_cache.h>
#endif

#ifdef NVMC_PRESENT
#include <nrfx_nvmc.h>
#include <hal/nrf_nvmc.h>
#endif

#ifdef MPC_PRESENT
#include <hal/nrf_mpc.h>
#endif

#ifdef NRF53_SERIES
#define PIN_XL1 0
#define PIN_XL2 1
#endif

#ifdef NRF54L_SERIES
/* On nRF54L15 XL1 and XL2 are(P1.00) and XL2(P1.01) */
#define PIN_XL1 32
#define PIN_XL2 33

/* During TF-M system initialization we invoke a function that comes
 * from Zephyr. This function does not have a header file so we
 * declare its prototype here.
 */
int nordicsemi_nrf54l_init(void);
#endif

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

#if TFM_PERIPHERAL_SPIM22_SECURE
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

#ifdef PSA_API_TEST_IPC
struct platform_data_t
    tfm_peripheral_FF_TEST_SERVER_PARTITION_MMIO = {
        FF_TEST_SERVER_PARTITION_MMIO_START,
        FF_TEST_SERVER_PARTITION_MMIO_END
};

struct platform_data_t
    tfm_peripheral_FF_TEST_DRIVER_PARTITION_MMIO = {
        FF_TEST_DRIVER_PARTITION_MMIO_START,
        FF_TEST_DRIVER_PARTITION_MMIO_END
};

/* This platform implementation uses PSA_TEST_SCRATCH_AREA for
 * storing the state between resets, but the FF_TEST_NVMEM_REGIONS
 * definitons are still needed for tests to compile.
 */
#define FF_TEST_NVMEM_REGION_START  0xFFFFFFFF
#define FF_TEST_NVMEM_REGION_END    0xFFFFFFFF
struct platform_data_t
    tfm_peripheral_FF_TEST_NVMEM_REGION = {
        FF_TEST_NVMEM_REGION_START,
        FF_TEST_NVMEM_REGION_END
};
#endif /* PSA_API_TEST_IPC */


/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
REGION_DECLARE(Image$$, ER_VENEER, $$Base);
REGION_DECLARE(Image$$, VENEER_ALIGN, $$Limit);

const struct memory_region_limits memory_regions = {
    .non_secure_code_start =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        BL2_HEADER_SIZE,

    .non_secure_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

    .non_secure_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        NS_PARTITION_SIZE - 1,

    .veneer_base =
        (uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),

    .veneer_limit =
        (uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit),

#ifdef NRF_NS_SECONDARY
    .secondary_partition_base = SECONDARY_PARTITION_START,
    .secondary_partition_limit = SECONDARY_PARTITION_START +
        SECONDARY_PARTITION_SIZE - 1,
#endif /* NRF_NS_SECONDARY */

#ifdef NRF_NS_STORAGE_PARTITION_START
    .non_secure_storage_partition_base = NRF_NS_STORAGE_PARTITION_START,
    .non_secure_storage_partition_limit = NRF_NS_STORAGE_PARTITION_START +
        NRF_NS_STORAGE_PARTITION_SIZE - 1,
#endif /* NRF_NS_STORAGE_PARTITION_START */
};

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

enum tfm_plat_err_t enable_fault_handlers(void)
{
    /* Explicitly set secure fault priority to the highest */
    NVIC_SetPriority(SecureFault_IRQn, 0);

    /* Enables BUS, MEM, USG and Secure faults */
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk |
                  SCB_SHCSR_BUSFAULTENA_Msk |
                  SCB_SHCSR_MEMFAULTENA_Msk |
                  SCB_SHCSR_SECUREFAULTENA_Msk;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t system_reset_cfg(void)
{
    uint32_t reg_value = SCB->AIRCR;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Enable system reset request only to the secure world */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_debug(void)
{
#if defined(NRF_APPROTECT) || defined(NRF_SECURE_APPROTECT)

#if !defined(DAUTH_CHIP_DEFAULT)
#error "Debug access controlled by NRF_APPROTECT and NRF_SECURE_APPROTECT."
#endif

#if defined(NRF_APPROTECT) && !defined(NRF54L_SERIES)
    /* For nRF53 and nRF91x1 already active. For nRF9160, active in the next boot.*/
    if (nrfx_nvmc_word_writable_check((uint32_t)&NRF_UICR_S->APPROTECT,
                                    UICR_APPROTECT_PALL_Protected)) {
        nrfx_nvmc_word_write((uint32_t)&NRF_UICR_S->APPROTECT, UICR_APPROTECT_PALL_Protected);
    } else {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif
#if defined(NRF_SECURE_APPROTECT) && !defined(NRF54L_SERIES)
    /* For nRF53 and nRF91x1 already active. For nRF9160, active in the next boot. */
    if (nrfx_nvmc_word_writable_check((uint32_t)&NRF_UICR_S->SECUREAPPROTECT,
                                    UICR_SECUREAPPROTECT_PALL_Protected)) {
        nrfx_nvmc_word_write((uint32_t)&NRF_UICR_S->SECUREAPPROTECT,
            UICR_SECUREAPPROTECT_PALL_Protected);
    } else {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif

#elif defined(NRF91_SERIES) || defined(NRF54L_SERIES)

#if !defined(DAUTH_CHIP_DEFAULT)
#error "Debug access on this platform can only be configured by programming the corresponding registers in UICR."
#endif

#elif defined(NRF53_SERIES)

#if defined(DAUTH_NONE)
    /* Disable debugging */
    NRF_CTRLAP->APPROTECT.DISABLE = 0;
    NRF_CTRLAP->SECUREAPPROTECT.DISABLE = 0;
#elif defined(DAUTH_NS_ONLY)
    /* Allow debugging Non-Secure only */
    NRF_CTRLAP->APPROTECT.DISABLE = NRF_UICR->APPROTECT;
    NRF_CTRLAP->SECUREAPPROTECT.DISABLE = 0;
#elif defined(DAUTH_FULL) || defined(DAUTH_CHIP_DEFAULT)
    /* Allow debugging */
    /* Use the configuration in UICR. */
    NRF_CTRLAP->APPROTECT.DISABLE = NRF_UICR->APPROTECT;
    NRF_CTRLAP->SECUREAPPROTECT.DISABLE = NRF_UICR->SECUREAPPROTECT;
#else
#error "No debug authentication setting is provided."
#endif

    /* Lock access to APPROTECT, SECUREAPPROTECT */
    NRF_CTRLAP->APPROTECT.LOCK = CTRLAPPERI_APPROTECT_LOCK_LOCK_Locked <<
        CTRLAPPERI_APPROTECT_LOCK_LOCK_Msk;
    NRF_CTRLAP->SECUREAPPROTECT.LOCK = CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_Locked <<
        CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_Msk;

#else
#error "Unrecognized platform"

#endif

    return TFM_PLAT_ERR_SUCCESS;
}

#define NRF_UARTE_INSTANCE(id) NRF_UARTE ## id
#define NRF_UARTE_INSTANCE_GET(id) NRF_UARTE_INSTANCE(id)

/*----------------- NVIC interrupt target state to NS configuration ----------*/
enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
    /* Target every interrupt to NS; unimplemented interrupts will be Write-Ignored */
    for (uint8_t i = 0; i < sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0]); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFF;
    }

    /* Make sure that the SPU instance(s) are targeted to S state */
	for(int i = 0; i < ARRAY_SIZE(spu_instances); i++) {
		NVIC_ClearTargetState(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
	}

#ifdef NRF_CRACEN
	NVIC_ClearTargetState(NRFX_IRQ_NUMBER_GET(NRF_CRACEN));
#endif
#ifdef NRF_MPC00
	NVIC_ClearTargetState(MPC00_IRQn);
#endif

#ifdef SECURE_UART1
    /* IRQ for the selected secure UART has to target S state */
    NVIC_ClearTargetState(NRFX_IRQ_NUMBER_GET(NRF_UARTE_INSTANCE_GET(NRF_SECURE_UART_INSTANCE)));
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
enum tfm_plat_err_t nvic_interrupt_enable(void)
{
    /* SPU interrupt enabling */
    spu_enable_interrupts();

	for(int i = 0; i < ARRAY_SIZE(spu_instances); i++) {
		NVIC_ClearPendingIRQ(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
		NVIC_EnableIRQ(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
	}

#ifdef MPC_PRESENT
    mpc_clear_events();
    /* MPC interrupt enabling */
    mpc_enable_interrupts();

    NVIC_ClearPendingIRQ(NRFX_IRQ_NUMBER_GET(NRF_MPC00));
    NVIC_EnableIRQ(NRFX_IRQ_NUMBER_GET(NRF_MPC00));
#endif

	/* The CRACEN driver configures the NVIC for CRACEN and is
	 * therefore omitted here.
	 */

    return TFM_PLAT_ERR_SUCCESS;
}

/*------------------- SAU/IDAU configuration functions -----------------------*/

void sau_and_idau_cfg(void)
{
	/*
	 * SAU and IDAU configuration is very different between old
	 * (53/91) and new (54++) platforms. New platforms have a proper SAU
	 * and IDAU, whereas old platforms do not.
	 */
#ifdef NRF54L_SERIES
	/*
	 * This SAU configuration aligns with ARM's RSS implementation of
	 * sau_and_idau_cfg when possible.
	 */

	/* Enables SAU */
    TZ_SAU_Enable();

    /* Configures SAU regions to be non-secure */

	/* Note that this SAU configuration assumes that there is only one
	 * secure NVM partition and one non-secure NVM partition. Meaning,
	 * memory_regions.non_secure_partition_limit is at the end of
	 * NVM.
	 */

	/* Configure the end of NVM, and the FICR, to be non-secure using
	   a single region. Note that the FICR is placed after the
	   non-secure NVM and before the UICR.*/
    SAU->RNR  = 0;
    SAU->RBAR = (memory_regions.non_secure_partition_base
                 & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (NRF_UICR_S_BASE & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

	/* Leave SAU region 1 disabled until we find a use for it */

    /* Configures veneers region to be non-secure callable */
    SAU->RNR  = 2;
    SAU->RBAR = (memory_regions.veneer_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk)
                 | SAU_RLAR_ENABLE_Msk | SAU_RLAR_NSC_Msk;

	/* Configures SAU region 3 to cover both the end of SRAM and
	 * regions above it as shown in the "Example memory map" in the
	 * "Product Specification" */
    SAU->RNR  = 3;
    SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (0xFFFFFFFFul & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

#else
    /* IDAU (SPU) is always enabled. SAU is non-existent.
     * Allow SPU to have precedence over (non-existing) ARMv8-M SAU.
     */
    TZ_SAU_Disable();
    SAU->CTRL |= SAU_CTRL_ALLNS_Msk;
#endif
}

#if NRF_SPU_HAS_MEMORY
enum tfm_plat_err_t spu_init_cfg(void)
{
    /*
     * Configure SPU Regions for Non-Secure Code and SRAM (Data)
     * Configure SPU for Peripheral Security
     * Configure Non-Secure Callable Regions
     * Configure Secondary Image Partition
     * Configure Non-Secure Storage Partition
     */

    /* Reset Flash and SRAM configuration of regions that are not owned by
     * the bootloader(s) to all-Secure.
     */
    spu_regions_reset_unlocked_secure();

    uint32_t perm;

    /* Configure Secure Code to be secure and RX */
    perm = 0;
    perm |= NRF_SPU_MEM_PERM_READ;
    /* Do not permit writes to secure flash */
    perm |= NRF_SPU_MEM_PERM_EXECUTE;

    spu_regions_flash_config(S_CODE_START, S_CODE_LIMIT, SPU_SECURE_ATTR_SECURE, perm,
			     SPU_LOCK_CONF_LOCKED);

    /* Configure Secure RAM to be secure and RWX */
    perm = 0;
    perm |= NRF_SPU_MEM_PERM_READ;
    perm |= NRF_SPU_MEM_PERM_WRITE;
    /* Permit execute from Secure RAM because otherwise Crypto fails
     * to initialize. */
    perm |= NRF_SPU_MEM_PERM_EXECUTE;

    spu_regions_sram_config(S_DATA_START, S_DATA_LIMIT, SPU_SECURE_ATTR_SECURE, perm,
			    SPU_LOCK_CONF_LOCKED);

    /* Configures SPU Code and Data regions to be non-secure */
    perm = 0;
    perm |= NRF_SPU_MEM_PERM_READ;
    perm |= NRF_SPU_MEM_PERM_WRITE;
    perm |= NRF_SPU_MEM_PERM_EXECUTE;

    spu_regions_flash_config(memory_regions.non_secure_partition_base,
			     memory_regions.non_secure_partition_limit, SPU_SECURE_ATTR_NONSECURE,
			     perm, SPU_LOCK_CONF_LOCKED);

    spu_regions_sram_config(NS_DATA_START, NS_DATA_LIMIT, SPU_SECURE_ATTR_NONSECURE, perm,
			    SPU_LOCK_CONF_LOCKED);

    /* Configures veneers region to be non-secure callable */
    spu_regions_flash_config_non_secure_callable(memory_regions.veneer_base,
						 memory_regions.veneer_limit - 1);

#ifdef NRF_NS_SECONDARY
	perm = 0;
	perm |= NRF_SPU_MEM_PERM_READ;
	perm |= NRF_SPU_MEM_PERM_WRITE;

    /* Secondary image partition */
    spu_regions_flash_config(memory_regions.secondary_partition_base,
			     memory_regions.secondary_partition_limit, SPU_SECURE_ATTR_NONSECURE,
			     perm, SPU_LOCK_CONF_LOCKED);
#endif /* NRF_NS_SECONDARY */

#ifdef NRF_NS_STORAGE_PARTITION_START
    /* Configures storage partition to be non-secure */
    perm = 0;
    perm |= NRF_SPU_MEM_PERM_READ;
    perm |= NRF_SPU_MEM_PERM_WRITE;

    spu_regions_flash_config(memory_regions.non_secure_storage_partition_base,
			     memory_regions.non_secure_storage_partition_limit,
			     SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);
#endif /* NRF_NS_STORAGE_PARTITION_START */

#ifdef REGION_PCD_SRAM_ADDRESS
    /* Netcore needs PCD memory area to be non-secure. */
    perm = 0;
    perm |= NRF_SPU_MEM_PERM_READ;
    if (tfm_plat_provisioning_is_required()) {
        perm |= NRF_SPU_MEM_PERM_WRITE;
    }

    spu_regions_sram_config(REGION_PCD_SRAM_ADDRESS, REGION_PCD_SRAM_LIMIT,
                SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);
#endif

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* NRF_SPU_HAS_MEMORY */


#ifdef MPC_PRESENT
struct mpc_region_override {
	nrf_mpc_override_config_t config;
	nrf_owner_t owner_id;
	uintptr_t start_address;
	size_t endaddr;
	uint32_t perm;
	uint32_t permmask;
	size_t index;
};

static void mpc_configure_override(NRF_MPC_Type *mpc, struct mpc_region_override *override)
{
	nrf_mpc_override_startaddr_set(mpc, override->index, override->start_address);
	nrf_mpc_override_endaddr_set(mpc, override->index, override->endaddr);
	nrf_mpc_override_perm_set(mpc, override->index, override->perm);
	nrf_mpc_override_permmask_set(mpc, override->index, override->permmask);
#if defined(NRF_MPC_HAS_OVERRIDE_OWNERID) && NRF_MPC_HAS_OVERRIDE_OWNERID
	nrf_mpc_override_ownerid_set(mpc, override->index, override->owner_id);
#endif
	nrf_mpc_override_config_set(mpc, override->index, &override->config);
}

/*
 * Configure the override struct with reasonable defaults. This includes:
 *
 * Use a slave number of 0 to avoid redirecting bus transactions from
 * one slave to another.
 *
 * Lock the override to prevent the code that follows from tampering
 * with the configuration.
 *
 * Enable the override so it takes effect.
 *
 * Indicate that secdom is not enabled as this driver is not used on
 * platforms with secdom.
 */
static void init_mpc_region_override(struct mpc_region_override * override)
{
	*override = (struct mpc_region_override){
		.config =
		(nrf_mpc_override_config_t){
			.slave_number = 0,
			.lock = true,
			.enable = true,
			.secdom_enable = false,
			.secure_mask = true,
		},
		.perm = 0, /* 0 for non-secure */
		.owner_id = 0,
	};

	override->permmask = MPC_OVERRIDE_PERM_SECATTR_Msk;
}

enum tfm_plat_err_t nrf_mpc_init_cfg(void)
{
	/* On 54l the NRF_MPC00->REGION[]'s are fixed in HW and the
	 * OVERRIDE indexes (that are useful to us) start at 0 and end
	 * (inclusive) at 4.
	 *
	 * Note that the MPC regions configure all volatile and non-volatile memory as secure, so we only
	 * need to explicitly OVERRIDE the non-secure addresses to permit non-secure access.
	 *
	 * Explicitly configuring memory as secure is not necessary.
	 *
	 * The last OVERRIDE in 54L is fixed in HW and exists to prevent
	 * other bus masters than the KMU from accessing CRACEN protected RAM.
	 *
	 * Note that we must take care not to configure an OVERRIDE that
	 * affects an active bus transaction.
	 *
	 * Note that we don't configure the NSC region to be NS because
	 * from the MPC's perspective it is secure. NSC is only configurable from the SAU.
	 *
	 * Note that OVERRIDE[n].MASTERPORT has a reasonable reset value
	 * so it is left unconfigured.
	 *
	 * Note that there are two owners in 54L. KMU with owner ID 1, and everything else with owner ID 0.
	 */

	uint32_t index = 0;
	/*
	 * Configure the non-secure partition of the non-volatile
	 * memory. This MPC region is intended to cover both the
	 * non-secure partition in the NVM and also the FICR. The FICR
	 * starts after the NVM and ends just before the UICR.
	 */
	{
		struct mpc_region_override override;

		init_mpc_region_override(&override);

		override.start_address = memory_regions.non_secure_partition_base;
		override.endaddr = NRF_UICR_S_BASE;
		override.index = index++;

		mpc_configure_override(NRF_MPC00, &override);
	}

	/* Configure the non-secure partition of the volatile memory */
	{
		struct mpc_region_override override;

		init_mpc_region_override(&override);

		override.start_address = NS_DATA_START;
		override.endaddr = 1 + NS_DATA_LIMIT;
		override.index = index++;

		mpc_configure_override(NRF_MPC00, &override);
	}

	if(index > 4) {
		/* Used more overrides than are available */
		tfm_core_panic();
	}

	/* Lock and disable any unused MPC overrides to prevent malicious configuration */
	while(index <= 4) {
		struct mpc_region_override override;

		init_mpc_region_override(&override);

		override.config.enable = false;

		override.index = index++;

		mpc_configure_override(NRF_MPC00, &override);
	}

	return TFM_PLAT_ERR_SUCCESS;
}

#endif /* MPC_PRESENT */

static void dppi_channel_configuration(void)
{
	/* The SPU HW and corresponding NRFX HAL API have two different
	 * API's for DPPI security configuration. The defines
	 * NRF_SPU_HAS_OWNERSHIP and NRF_SPU_HAS_MEMORY identify which of the two API's
	 * are present.
	 *
	 * TFM_PERIPHERAL_DPPI_CHANNEL_MASK_SECURE is configurable, but
	 * usually defaults to 0, which results in all DPPI channels being
	 * non-secure.
	 */
#if NRF_SPU_HAS_MEMORY
    /* There is only one dppi_id */
    uint8_t dppi_id = 0;
    nrf_spu_dppi_config_set(NRF_SPU, dppi_id, TFM_PERIPHERAL_DPPI_CHANNEL_MASK_SECURE,
			    SPU_LOCK_CONF_LOCKED);
#else
	/* TODO_NRF54L15: Use the nrf_spu_feature API to configure DPPI
	   channels according to a user-controllable config similar to
	   TFM_PERIPHERAL_DPPI_CHANNEL_MASK_SECURE. */
#endif
}

enum tfm_plat_err_t spu_periph_init_cfg(void)
{
    /* Peripheral configuration */
#ifdef NRF54L_SERIES
	/* Configure features to be non-secure */

	/*
	 * Due to MLT-7600, many SPU HW reset values are wrong. The docs
	 * generally features being non-secure when coming out of HW
	 * reset, but the HW has a good mix of both.
	 *
	 * When configuring NRF_SPU 0 will indicate non-secure and 1 will
	 * indicate secure.
	 *
	 * Most of the chip should be non-secure so to simplify and be
	 * consistent, we memset the entire memory map of each SPU
	 * peripheral to 0.
	 *
	 * Just after memsetting to 0 we explicitly configure the
	 * peripherals that should be secure back to secure again.
	 */
	// TODO: NCSDK-22597: Evaluate if it is safe to memset everything
	// in NRF_SPU to 0.
	memset(NRF_SPU00, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU10, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU20, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU30, 0, sizeof(NRF_SPU_Type));

#if SECURE_UART1
	/* Configure TF-M's UART peripheral to be secure */
#if NRF_SECURE_UART_INSTANCE == 00
    uint32_t uart_periph_start = tfm_peripheral_uarte00.periph_start;
#elif NRF_SECURE_UART_INSTANCE == 20
    uint32_t uart_periph_start = tfm_peripheral_uarte20.periph_start;
#elif NRF_SECURE_UART_INSTANCE == 21
    uint32_t uart_periph_start = tfm_peripheral_uarte21.periph_start;
#elif NRF_SECURE_UART_INSTANCE == 22
    uint32_t uart_periph_start = tfm_peripheral_uarte22.periph_start;
#elif NRF_SECURE_UART_INSTANCE == 30
    uint32_t uart_periph_start = tfm_peripheral_uarte30.periph_start;
#endif
	spu_peripheral_config_secure(uart_periph_start, SPU_LOCK_CONF_LOCKED);
#endif /* SECURE_UART1 */

	/* Configure the CTRL-AP mailbox interface to be secure as it is used by the secure ADAC service */
	spu_peripheral_config_secure(NRF_CTRLAP_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure NRF_MEMCONF to be secure as it could otherwise be used to corrupt secure RAM. */
	spu_peripheral_config_secure(NRF_MEMCONF_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure trace to be secure, as the security implications of non-secure trace are not understood */
	spu_peripheral_config_secure(NRF_TAD_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure these HW features, which are not in the MDK, to be
	 * secure, as the security implications of them being non-secure
	 * are not understood
	 */
	uint32_t base_addresses[4] = {
		0x50056000,
		0x5008C000,
		0x500E6000,
		0x5010F000
	};
	for(int i = 0; i < 4; i++) {
		spu_peripheral_config_secure(base_addresses[i], SPU_LOCK_CONF_LOCKED);
	}


	/* GPIOTE channel configuration */
	uint32_t secure_gpiote_channels[] = {
#if TFM_PERIPHERAL_GPIOTE20_SECURE_CHANNELS_MASK
	TFM_PERIPHERAL_GPIOTE20_SECURE_CHANNELS_MASK,
#endif
#if TFM_PERIPHERAL_GPIOTE30_SECURE_CHANNELS_MASK
	TFM_PERIPHERAL_GPIOTE30_SECURE_CHANNELS_MASK,
#endif
		0 /* Not used, its here to avoid compilation failures */
	};

	uint32_t gpiote_instances[] = {
#if TFM_PERIPHERAL_GPIOTE20_SECURE_CHANNELS_MASK
	NRF_GPIOTE20_S_BASE,
#endif
#if TFM_PERIPHERAL_GPIOTE30_SECURE_CHANNELS_MASK
	NRF_GPIOTE30_S_BASE,
#endif
		0 /* Not used, its here to avoid compilation failures */
	};

	/* Configure the SPU GPIOTE registers. Each GPIOTE can fire 2 interrupts for
	 * each available channel. If a channel is configured as secure both of the
	 * interrupts will only available in secure mode so a single configuration
	 * should suffice.
	 */
	for(int i = 0; i < ARRAY_SIZE(gpiote_instances) - 1; i++) {

		NRF_SPU_Type * spu_instance = spu_instance_from_peripheral_addr(gpiote_instances[i]);
		for (int channel = 0; channel < NRF_SPU_FEATURE_GPIOTE_CHANNEL_COUNT; channel++) {
			if(secure_gpiote_channels[i] & (1 << channel)){
				nrf_spu_feature_secattr_set(spu_instance, NRF_SPU_FEATURE_GPIOTE_CHANNEL, 0,
								channel,
								true);
				nrf_spu_feature_lock_enable(spu_instance, NRF_SPU_FEATURE_GPIOTE_CHANNEL, 0, channel);

				nrf_spu_feature_secattr_set(spu_instance, NRF_SPU_FEATURE_GPIOTE_INTERRUPT, 0,
								channel,
								true);
				nrf_spu_feature_lock_enable(spu_instance, NRF_SPU_FEATURE_GPIOTE_INTERRUPT, 0, channel);
			}
		}
	}

	/* Configure NRF_REGULATORS, and NRF_OSCILLATORS to be secure as NRF_REGULATORS.POFCON is needed
	 * to prevent glitches when the power supply is attacked.
	 *
	 * NB: Note that NRF_OSCILLATORS and NRF_REGULATORS have the same base address and must therefore
	 * have the same security configuration.
	 */
	spu_peripheral_config_secure(NRF_REGULATORS_S_BASE, SPU_LOCK_CONF_LOCKED);
#else /* NRF54L_SERIES */
static const uint32_t target_peripherals[] = {
    /* The following peripherals share ID:
     * - FPU (FPU cannot be configured in NRF91 series, it's always NS)
     * - DCNF (On 53, but not 91)
     */
#ifndef NRF91_SERIES
    NRF_FPU_S_BASE,
#endif
    /* The following peripherals share ID:
     * - REGULATORS
     * - OSCILLATORS
     */
    NRF_REGULATORS_S_BASE,
    /* The following peripherals share ID:
     * - CLOCK
     * - POWER
     * - RESET (On 53, but not 91)
     */
    NRF_CLOCK_S_BASE,
    /* The following peripherals share ID: (referred to as Serial-Box)
     * - SPIMx
     * - SPISx
     * - TWIMx
     * - TWISx
     * - UARTEx
     */

    /* When UART0 is a secure peripheral we need to leave Serial-Box 0 as Secure.
     * The UART Driver will configure it as non-secure when it uninitializes.
     */
#if !(defined(SECURE_UART1) && NRF_SECURE_UART_INSTANCE == 0)
    NRF_SPIM0_S_BASE,
#endif
#if !(defined(SECURE_UART1) && NRF_SECURE_UART_INSTANCE == 1)
    /* UART1 is a secure peripheral, so we need to leave Serial-Box 1 as Secure */
    NRF_SPIM1_S_BASE,
#endif
    NRF_SPIM2_S_BASE,
    NRF_SPIM3_S_BASE,
#ifdef NRF_SPIM4
    NRF_SPIM4_S_BASE,
#endif
    NRF_SAADC_S_BASE,
    NRF_TIMER0_S_BASE,
    NRF_TIMER1_S_BASE,
    NRF_TIMER2_S_BASE,
    NRF_RTC0_S_BASE,
    NRF_RTC1_S_BASE,
    NRF_DPPIC_S_BASE,
#ifndef PSA_API_TEST_IPC
#ifdef NRF_WDT0
    /* WDT0 is used as a secure peripheral in PSA FF tests */
    NRF_WDT0_S_BASE,
#endif
#ifdef NRF_WDT
    NRF_WDT_S_BASE,
#endif
#endif /* PSA_API_TEST_IPC */
#ifdef NRF_WDT1
    NRF_WDT1_S_BASE,
#endif
    /* The following peripherals share ID:
     * - COMP
     * - LPCOMP
     */
#ifdef NRF_COMP
    NRF_COMP_S_BASE,
#endif
    NRF_EGU0_S_BASE,
    NRF_EGU1_S_BASE,
    NRF_EGU2_S_BASE,
    NRF_EGU3_S_BASE,
    NRF_EGU4_S_BASE,
#ifndef PSA_API_TEST_IPC
    /* EGU5 is used as a secure peripheral in PSA FF tests */
    NRF_EGU5_S_BASE,
#endif
    NRF_PWM0_S_BASE,
    NRF_PWM1_S_BASE,
    NRF_PWM2_S_BASE,
    NRF_PWM3_S_BASE,
#ifdef NRF_PDM
    NRF_PDM_S_BASE,
#endif
#ifdef NRF_PDM0
    NRF_PDM0_S_BASE,
#endif
#ifdef NRF_I2S
    NRF_I2S_S_BASE,
#endif
#ifdef NRF_I2S0
    NRF_I2S0_S_BASE,
#endif
    NRF_IPC_S_BASE,
#ifndef SECURE_QSPI
#ifdef NRF_QSPI
    NRF_QSPI_S_BASE,
#endif
#endif
#ifdef NRF_NFCT
    NRF_NFCT_S_BASE,
#endif
#ifdef NRF_MUTEX
    NRF_MUTEX_S_BASE,
#endif
#ifdef NRF_QDEC0
    NRF_QDEC0_S_BASE,
#endif
#ifdef NRF_QDEC1
    NRF_QDEC1_S_BASE,
#endif
#ifdef NRF_USBD
    NRF_USBD_S_BASE,
#endif
#ifdef NRF_USBREGULATOR
    NRF_USBREGULATOR_S_BASE,
#endif /* NRF_USBREGULATOR */
    NRF_NVMC_S_BASE,
    NRF_P0_S_BASE,
#ifdef NRF_P1
    NRF_P1_S_BASE,
#endif /*NRF_P1 */
#if defined(NRF91_SERIES) || defined(NRF53_SERIES)
    NRF_VMC_S_BASE
#endif
};

    for (int i = 0; i < ARRAY_SIZE(target_peripherals); i++) {
        spu_peripheral_config_non_secure(target_peripherals[i], SPU_LOCK_CONF_UNLOCKED);
    }

#endif /* NRF54L_SERIES */

    /* DPPI channel configuration */
	dppi_channel_configuration();

    /* GPIO pin configuration */
	uint32_t secure_pins[] = {
#ifdef TFM_PERIPHERAL_GPIO0_PIN_MASK_SECURE
		TFM_PERIPHERAL_GPIO0_PIN_MASK_SECURE,
#endif
#ifdef TFM_PERIPHERAL_GPIO1_PIN_MASK_SECURE
		TFM_PERIPHERAL_GPIO1_PIN_MASK_SECURE,
#endif
#ifdef TFM_PERIPHERAL_GPIO2_PIN_MASK_SECURE
		TFM_PERIPHERAL_GPIO2_PIN_MASK_SECURE,
#endif
	};

	/* Note that there are two different API's for SPU configuration */
#if NRF_SPU_HAS_MEMORY

	for(int port = 0; port < ARRAY_SIZE(secure_pins); port++){
		nrf_spu_gpio_config_set(NRF_SPU, port, secure_pins[port], SPU_LOCK_CONF_LOCKED);
	}

#elif NRF_SPU_HAS_PERIPHERAL_ACCESS

	for(int port = 0; port < ARRAY_SIZE(secure_pins); port++) {
		for (int pin = 0; pin < 32; pin++) {
			if (secure_pins[port] & (1 << pin)) {
				bool enable = true; // secure

				/*
				 * Unfortunately, NRF_P0 is not configured by NRF_SPU00, etc.
				 * so it is a bit convoluted to find the SPU instance for port x.
				 */
				uint32_t gpio_port_addr[2] = {
					NRF_P0_S_BASE,
					NRF_P1_S_BASE,
				};

				NRF_SPU_Type * spu_instance = spu_instance_from_peripheral_addr(gpio_port_addr[port]);

				nrf_spu_feature_secattr_set(spu_instance, NRF_SPU_FEATURE_GPIO_PIN, port, pin, enable);
				nrf_spu_feature_lock_enable(spu_instance, NRF_SPU_FEATURE_GPIO_PIN, port, pin);
			}
		}
	}
#else
#error "Expected either NRF_SPU_HAS_MEMORY or NRF_SPU_HAS_PERIPHERAL_ACCESS to be true"
#endif

    /* Configure properly the XL1 and XL2 pins so that the low-frequency crystal
     * oscillator (LFXO) can be used.
     * This configuration can be done only from secure code, as otherwise those
     * register fields are not accessible. That's why it is placed here.
     */
#ifdef NRF53_SERIES
    nrf_gpio_pin_control_select(PIN_XL1, NRF_GPIO_PIN_SEL_PERIPHERAL);
    nrf_gpio_pin_control_select(PIN_XL2, NRF_GPIO_PIN_SEL_PERIPHERAL);
#endif /* NRF53_SERIES */
#ifdef NRF54L_SERIES
    /* NRF54L has a different define */
    nrf_gpio_pin_control_select(PIN_XL1, NRF_GPIO_PIN_SEL_GPIO);
    nrf_gpio_pin_control_select(PIN_XL2, NRF_GPIO_PIN_SEL_GPIO);
#endif

	/*
	 * 91 has an instruction cache.
	 * 53 has both instruction cache and a data cache.
	 *
	 * 53's instruction cache has an nrfx driver, but 91's cache is
	 * not supported by nrfx at time of writing.
	 *
	 * We enable all caches available here because non-secure cannot
	 * configure caches.
	 */
#if defined(NVMC_FEATURE_CACHE_PRESENT) // From MDK
	nrfx_nvmc_icache_enable();
#elif defined(CACHE_PRESENT) // From MDK

#ifdef NRF_CACHE
	nrf_cache_enable(NRF_CACHE);
#endif
#ifdef NRF_ICACHE
	nrf_cache_enable(NRF_ICACHE);
#endif
#ifdef NRF_DCACHE
	nrf_cache_enable(NRF_DCACHE);
#endif

#endif

#ifdef RRAMC_PRESENT
	nrfx_rramc_config_t config = NRFX_RRAMC_DEFAULT_CONFIG(WRITE_BUFFER_SIZE);

	config.mode_write = true;

#if CONFIG_NRF_RRAM_READYNEXT_TIMEOUT_VALUE > 0
	config.preload_timeout_enable = true;
	config.preload_timeout = CONFIG_NRF_RRAM_READYNEXT_TIMEOUT_VALUE;
#else
	config.preload_timeout_enable = false;
	config.preload_timeout = 0;
#endif

	/* Don't use an event handler until it's understood whether we
	 * want it or not
	 */
	nrfx_rramc_evt_handler_t handler = NULL;

	nrfx_err_t err = nrfx_rramc_init(&config, handler);
	if(err != NRFX_SUCCESS && err != NRFX_ERROR_ALREADY) {
		return err;
	}
#endif /* RRAMC_PRESENT */

#ifdef NRF54L_SERIES
	/* SOC configuration from Zephyr's soc.c. */
	int soc_err = nordicsemi_nrf54l_init();
	if (soc_err) {
		return soc_err;
	}
#endif

#if NRF_SPU_HAS_MEMORY
    /* Enforce that the nRF5340 Network MCU is in the Non-Secure
     * domain. Non-secure is the HW reset value for the network core
     * so configuring this should not be necessary, but we want to
     * make sure that the bootloader has not accidentally configured
     * it to be secure. Additionally we lock the register to make sure
     * it doesn't get changed by accident.
     */
    nrf_spu_extdomain_set(NRF_SPU, 0, false, true);
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

/*
 * Copyright (c) 2025 Nordic Semiconductor ASA.
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
#include "tfm_peripherals_def.h"
#include "tfm_plat_provisioning.h"
#include "utilities.h"
#include "region.h"
#include "array.h"

#ifdef __NRF_TFM__
#include <zephyr/autoconf.h>
#endif

#include <spu.h>
#include <nrfx.h>
#include <nrfx_nvmc.h>
#include <hal/nrf_gpio.h>
#include <hal/nrf_spu.h>
#include <hal/nrf_nvmc.h>

#define SPU_ADDRESS_REGION	    (0x50000000)
#define GET_SPU_SLAVE_INDEX(periph) ((periph.periph_start & 0x0003F000) >> 12)
#define GET_SPU_INSTANCE(periph)                                                                   \
	((NRF_SPU_Type *)(SPU_ADDRESS_REGION | (periph.periph_start & 0x00FC0000)))

#ifdef NRF53_SERIES
#include <hal/nrf_cache.h>
#define PIN_XL1 0
#define PIN_XL2 1
#endif

extern const struct memory_region_limits memory_regions;

static inline enum tfm_plat_err_t configure_approtect_nvmc(void)
{
#if defined(NRF_APPROTECT)
	/* For nRF53 and nRF91x1 already active. For nRF9160, active in the next boot.*/
	if (nrfx_nvmc_word_writable_check((uint32_t)&NRF_UICR_S->APPROTECT,
					  UICR_APPROTECT_PALL_Protected)) {
		nrfx_nvmc_word_write((uint32_t)&NRF_UICR_S->APPROTECT,
				     UICR_APPROTECT_PALL_Protected);
	} else {
		return TFM_PLAT_ERR_SYSTEM_ERR;
	}
#endif
#if defined(NRF_SECURE_APPROTECT)
	/* For nRF53 and nRF91x1 already active. For nRF9160, active in the next boot. */
	if (nrfx_nvmc_word_writable_check((uint32_t)&NRF_UICR_S->SECUREAPPROTECT,
					  UICR_SECUREAPPROTECT_PALL_Protected)) {
		nrfx_nvmc_word_write((uint32_t)&NRF_UICR_S->SECUREAPPROTECT,
				     UICR_SECUREAPPROTECT_PALL_Protected);
	} else {
		return TFM_PLAT_ERR_SYSTEM_ERR;
	}
#endif

	return TFM_PLAT_ERR_SUCCESS;
}

#if defined(NRF53_SERIES)

static inline enum tfm_plat_err_t configure_approtect_registers(void)
{
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
	NRF_CTRLAP->APPROTECT.LOCK = CTRLAPPERI_APPROTECT_LOCK_LOCK_Locked
				     << CTRLAPPERI_APPROTECT_LOCK_LOCK_Msk;
	NRF_CTRLAP->SECUREAPPROTECT.LOCK = CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_Locked
					   << CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_Msk;

	return TFM_PLAT_ERR_SUCCESS;
}
#endif

enum tfm_plat_err_t init_debug(void)
{

#if (defined(NRF_APPROTECT) || defined(NRF_SECURE_APPROTECT)) && !defined(DAUTH_CHIP_DEFAULT)
#error "Debug access controlled by NRF_APPROTECT and NRF_SECURE_APPROTECT."
#elif defined(NRF91_SERIES) && !defined(DAUTH_CHIP_DEFAULT)
#error "Debug access on the nRF91 series can only be configured by programming the corresponding registers in UICR."
#endif

#if defined(NRF_APPROTECT) || defined(NRF_SECURE_APPROTECT)
	return configure_approtect_nvmc();
#elif defined(NRF53_SERIES)
	return configure_approtect_registers();
#endif
}

/*------------------- SAU/IDAU configuration functions -----------------------*/

void sau_and_idau_cfg(void)
{
	/* IDAU (SPU) is always enabled. SAU is non-existent.
	 * Allow SPU to have precedence over (non-existing) ARMv8-M SAU.
	 */
	TZ_SAU_Disable();
	SAU->CTRL |= SAU_CTRL_ALLNS_Msk;
}

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
				 memory_regions.non_secure_partition_limit,
				 SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);

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
				 memory_regions.secondary_partition_limit,
				 SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);
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
	enum tfm_plat_err_t err;
	bool provisioning_required;
	/* Netcore needs PCD memory area to be non-secure. */
	perm = 0;
	perm |= NRF_SPU_MEM_PERM_READ;

	err = tfm_plat_provisioning_is_required(&provisioning_required);
	if (err != TFM_PLAT_ERR_SUCCESS) {
		return err;
	}

	if (provisioning_required) {
		perm |= NRF_SPU_MEM_PERM_WRITE;
	}

	spu_regions_sram_config(REGION_PCD_SRAM_ADDRESS, REGION_PCD_SRAM_LIMIT,
				SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);
#endif /* REGION_PCD_SRAM_ADDRESS */

#ifdef REGION_RPMSG_NRF53_SRAM_ADDRESS
	/* Configures rpmsg nrf53 partition to be non-secure */
	perm = 0;
	perm |= NRF_SPU_MEM_PERM_READ;
	perm |= NRF_SPU_MEM_PERM_WRITE;

	spu_regions_sram_config(REGION_RPMSG_NRF53_SRAM_ADDRESS,
				REGION_RPMSG_NRF53_SRAM_LIMIT,
				SPU_SECURE_ATTR_NONSECURE, perm, SPU_LOCK_CONF_LOCKED);
#endif /* REGION_RPMSG_NRF53_SRAM_ADDRESS */

	return TFM_PLAT_ERR_SUCCESS;
}

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
	/* There is only one dppi_id */
	uint8_t dppi_id = 0;
	nrf_spu_dppi_config_set(NRF_SPU, dppi_id, TFM_PERIPHERAL_DPPI_CHANNEL_MASK_SECURE,
				SPU_LOCK_CONF_LOCKED);
}

static void cache_configuration(void)
{
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
#endif
#if defined(CACHE_PRESENT) // From MDK
	nrf_cache_enable(NRF_CACHE);
#endif
}

static void gpio_configuration(void)
{
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

	for (int port = 0; port < ARRAY_SIZE(secure_pins); port++) {
		nrf_spu_gpio_config_set(NRF_SPU, port, secure_pins[port], SPU_LOCK_CONF_LOCKED);
	}

	/* Configure properly the XL1 and XL2 pins so that the low-frequency crystal
	 * oscillator (LFXO) can be used.
	 * This configuration can be done only from secure code, as otherwise those
	 * register fields are not accessible. That's why it is placed here.
	 */
#ifdef NRF53_SERIES
	nrf_gpio_pin_control_select(PIN_XL1, NRF_GPIO_PIN_SEL_PERIPHERAL);
	nrf_gpio_pin_control_select(PIN_XL2, NRF_GPIO_PIN_SEL_PERIPHERAL);
#endif /* NRF53_SERIES */
}

static void peripheral_configuration(void)
{
	/* Peripheral configuration */
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
		NRF_VMC_S_BASE
	};

	for (int i = 0; i < ARRAY_SIZE(target_peripherals); i++) {
		spu_peripheral_config_non_secure(target_peripherals[i], SPU_LOCK_CONF_UNLOCKED);
	}
}

enum tfm_plat_err_t spu_periph_init_cfg(void)
{

	/* The default peripheral configuration sets most of the peripherals with split-security
	 * as non-secure by default. The peripherals explicitly configured as secure
	 * will be configured as secure later in the tfm_hal_bind_boundary function.
	 */
	peripheral_configuration();
	dppi_channel_configuration();
	gpio_configuration();
	cache_configuration();

#ifdef NRF53_SERIES
	/* Enforce that the nRF5340 Network MCU is in the Non-Secure
	 * domain. Non-secure is the HW reset value for the network core
	 * so configuring this should not be necessary, but we want to
	 * make sure that the bootloader has not accidentally configured
	 * it to be secure. Additionally we lock the register to make sure
	 * it doesn't get changed by accident.
	 */
	nrf_spu_extdomain_set(NRF_SPU, 0, false, true);
#endif /* NRF53_SERIES */

	return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt target state to NS configuration ----------*/
enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
	/* Target every interrupt to NS; unimplemented interrupts will be Write-Ignored */
	for (uint8_t i = 0; i < sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0]); i++) {
		NVIC->ITNS[i] = 0xFFFFFFFF;
	}

	/* Make sure that the SPU instance(s) are targeted to S state */
	for (int i = 0; i < ARRAY_SIZE(spu_instances); i++) {
		NVIC_ClearTargetState(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
	}

#ifdef SECURE_UART1
	/* IRQ for the selected secure UART has to target S state */
	NVIC_ClearTargetState(
		NRFX_IRQ_NUMBER_GET(NRF_UARTE_INSTANCE_GET(NRF_SECURE_UART_INSTANCE)));
#endif

	return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
enum tfm_plat_err_t nvic_interrupt_enable(void)
{
	/* SPU interrupt enabling */
	spu_enable_interrupts();

	for (int i = 0; i < ARRAY_SIZE(spu_instances); i++) {
		NVIC_ClearPendingIRQ(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
		NVIC_EnableIRQ(NRFX_IRQ_NUMBER_GET(spu_instances[i]));
	}

	return TFM_PLAT_ERR_SUCCESS;
}

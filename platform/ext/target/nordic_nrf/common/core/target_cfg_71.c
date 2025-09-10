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

#include <hal/nrf_gpio.h>
#include <hal/nrf_spu.h>
#include <nrfx_mramc.h>
#include <hal/nrf_mramc.h>
#include <hal/nrf_mpc.h>
#include <hal/nrf_cache.h>
#include "tfm_spm_log.h"


#if !defined(DAUTH_CHIP_DEFAULT)
#error "Debug access on this platform can only be configured by programming the corresponding registers in UICR."
#endif

#define SPU_ADDRESS_REGION	    (0x50000000)
#define GET_SPU_SLAVE_INDEX(periph) ((periph.periph_start & 0x0003F000) >> 12)
#define GET_SPU_INSTANCE(periph)                                                                   \
	((NRF_SPU_Type *)(SPU_ADDRESS_REGION | (periph.periph_start & 0x00FC0000)))

/* During TF-M system initialization we invoke a function that comes
 * from Zephyr. This function does not have a header file so we
 * declare its prototype here.
 */
int soc_early_init_hook(void);

extern const struct memory_region_limits memory_regions;

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
static void init_mpc_region_override(struct mpc_region_override *override)
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

static nrfx_err_t mramc_configuration(void)
{
	nrfx_mramc_config_t config = NRFX_MRAMC_DEFAULT_CONFIG();

	config.config.mode_write = NRF_MRAMC_MODE_WRITE_DIRECT;

	/* Don't use an event handler until it's understood whether we
	 * want it or not
	 */
	nrfx_mramc_evt_handler_t handler = NULL;

	nrfx_err_t err = nrfx_mramc_init(&config, handler);
	if (err != NRFX_SUCCESS && err != NRFX_ERROR_ALREADY) {
		return err;
	}

	return NRFX_SUCCESS;
}

enum tfm_plat_err_t init_debug(void)
{
	return TFM_PLAT_ERR_SUCCESS;
}

/*------------------- SAU/IDAU configuration functions -----------------------*/

void sau_and_idau_cfg(void)
{
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
	SAU->RNR = 0;
	SAU->RBAR = (memory_regions.non_secure_partition_base & SAU_RBAR_BADDR_Msk);
	SAU->RLAR = (NRF_UICR_S_BASE & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

	/* Leave SAU region 1 disabled until we find a use for it */

	/* Configures veneers region to be non-secure callable */
	SAU->RNR = 2;
	SAU->RBAR = (memory_regions.veneer_base & SAU_RBAR_BADDR_Msk);
	SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk |
		    SAU_RLAR_NSC_Msk;

	/* Configures SAU region 3 to cover both the end of SRAM and
	 * regions above it as shown in the "Example memory map" in the
	 * "Product Specification" */
	SAU->RNR = 3;
	SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
	SAU->RLAR = (0xFFFFFFFFul & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;
}

enum tfm_plat_err_t nrf_mpc_init_cfg(void)
{
	/* On 7120 the NRF_MPC00->REGION[]'s are fixed in HW and the
	 * OVERRIDE indexes (that are useful to us) start at 0 and end
	 * (inclusive) at 4.
	 *
	 * Note that the MPC regions configure all volatile and non-volatile memory as secure, so we
	 * only need to explicitly OVERRIDE the non-secure addresses to permit non-secure access.
	 *
	 * Explicitly configuring memory as secure is not necessary.
	 *
	 * The last OVERRIDE in 7120 is fixed in HW and exists to prevent
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
	 * Note that there are two owners in 7120. KMU with owner ID 1, and everything else with
	 * owner ID 0.
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

	if (index > 6) {
		/* Used more overrides than are available */
		tfm_core_panic();
	}

	/* Lock and disable any unused MPC overrides to prevent malicious configuration */
	while (index <= 6) {
		struct mpc_region_override override;

		init_mpc_region_override(&override);

		override.config.enable = false;

		override.index = index++;

		mpc_configure_override(NRF_MPC00, &override);
	}

	return TFM_PLAT_ERR_SUCCESS;
}

void peripheral_configuration(void)
{
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

	/* Configure the CTRL-AP mailbox interface to be secure as it is used by the secure ADAC
	 * service */
	spu_peripheral_config_secure(NRF_CTRLAP_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure NRF_MEMCONF to be secure as it could otherwise be used to corrupt secure RAM.
	 */
	spu_peripheral_config_secure(NRF_MEMCONF_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure trace to be secure, as the security implications of non-secure trace are not
	 * understood */
	spu_peripheral_config_secure(NRF_TAD_S_BASE, SPU_LOCK_CONF_LOCKED);

	/* Configure these HW features, which are not in the MDK, to be
	 * secure, as the security implications of them being non-secure
	 * are not understood
	 */
	uint32_t base_addresses[4] = {0x5007E000, 0x5008C000, 0x500E6000, 0x5010F000};
	for (int i = 0; i < 4; i++) {
		spu_peripheral_config_secure(base_addresses[i], SPU_LOCK_CONF_LOCKED);
	}

	/* Configure NRF_REGULATORS, and NRF_OSCILLATORS to be secure as it is
	 * needed to prevent glitches when the power supply is attacked.
	 *
	 * NB: Note that NRF_OSCILLATORS and NRF_REGULATORS have the same base address and must
	 * therefore have the same security configuration.
	 */
	spu_peripheral_config_secure(NRF_REGULATORS_S_BASE, SPU_LOCK_CONF_LOCKED);
}

static void gpiote_channel_configuration(void)
{
	/* Configure GPIOTE channels to be secure */
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
	for (int i = 0; i < ARRAY_SIZE(gpiote_instances) - 1; i++) {

		NRF_SPU_Type *spu_instance = spu_instance_from_peripheral_addr(gpiote_instances[i]);
		for (int channel = 0; channel < NRF_SPU_FEATURE_GPIOTE_CHANNEL_COUNT; channel++) {
			if (secure_gpiote_channels[i] & (1 << channel)) {
				nrf_spu_feature_secattr_set(spu_instance,
							    NRF_SPU_FEATURE_GPIOTE_CHANNEL, 0,
							    channel, true);
				nrf_spu_feature_lock_enable(
					spu_instance, NRF_SPU_FEATURE_GPIOTE_CHANNEL, 0, channel);

				nrf_spu_feature_secattr_set(spu_instance,
							    NRF_SPU_FEATURE_GPIOTE_INTERRUPT, 0,
							    channel, true);
				nrf_spu_feature_lock_enable(
					spu_instance, NRF_SPU_FEATURE_GPIOTE_INTERRUPT, 0, channel);
			}
		}
	}
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

	for (int port = 0; port < ARRAY_SIZE(secure_pins); port++) {
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

				NRF_SPU_Type *spu_instance =
					spu_instance_from_peripheral_addr(gpio_port_addr[port]);

				nrf_spu_feature_secattr_set(spu_instance, NRF_SPU_FEATURE_GPIO_PIN,
							    port, pin, enable);
				nrf_spu_feature_lock_enable(spu_instance, NRF_SPU_FEATURE_GPIO_PIN,
							    port, pin);
			}
		}
	}
}

enum tfm_plat_err_t spu_periph_init_cfg(void)
{
	/* Peripheral configuration */
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
	// TODO: Evaluate if it is safe to memset everything
	// in NRF_SPU to 0.
	memset(NRF_SPU00, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU10, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU20, 0, sizeof(NRF_SPU_Type));
	memset(NRF_SPU30, 0, sizeof(NRF_SPU_Type));

	peripheral_configuration();

	/* TODO_NRF7120: Use the nrf_spu_feature API to configure DPPI
	   channels according to a user-controllable config similar to
	   TFM_PERIPHERAL_DPPI_CHANNEL_MASK_SECURE. */

	gpiote_channel_configuration();
	gpio_configuration();

	nrf_cache_enable(NRF_ICACHE);

	nrfx_err_t nrfx_err = mramc_configuration();
	if (nrfx_err != NRFX_SUCCESS) {
		return TFM_PLAT_ERR_SYSTEM_ERR;
	}

	/* SOC configuration from Zephyr's soc.c. */
	int soc_err = soc_early_init_hook();
	if (soc_err) {
		return TFM_PLAT_ERR_SYSTEM_ERR;
	}

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

	NVIC_ClearTargetState(NRFX_IRQ_NUMBER_GET(NRF_CRACEN));
	NVIC_ClearTargetState(MPC00_IRQn);

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

	mpc_clear_events();
	/* MPC interrupt enabling */
	mpc_enable_interrupts();

	NVIC_ClearPendingIRQ(NRFX_IRQ_NUMBER_GET(NRF_MPC00));
	NVIC_EnableIRQ(NRFX_IRQ_NUMBER_GET(NRF_MPC00));

	/* The CRACEN driver configures the NVIC for CRACEN and is
	 * therefore omitted here.
	 */

	return TFM_PLAT_ERR_SUCCESS;
}

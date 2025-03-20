/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <stdint.h>
#include <nrfx.h>
#include <hal/nrf_oscillators.h>
#include <nrf_erratas.h>

#ifndef BIT_MASK
/* Use Zephyr BIT_MASK for unasigned integers */
#define BIT_MASK(n) ((1UL << (n)) - 1UL)
#endif

/* This handler needs to be ported to the upstream TF-M project when Cracen is supported there.
 * The implementation of this is currently in sdk-nrf. We define it to avoid warnings when we build
 * the target_cfg.c file which is the same for both upsteam TF-M and sdk-nrf.
 * It is defined as weak to allow the sdk-nrf version to be used when available. */
void __attribute__((weak)) CRACEN_IRQHandler(void){};

/* This is a simplified version of the function existing in the Zephyr's soc.c file for
 * the nRF54L15.
 * This function only supports one static configuration.
 * It is defined as weak to allow the sdk-nrf version to be used when available.
 *
 * The LFXO, HFXO configuration are taken from a sample build in sdk-nrf with the following
 * properties:
 *
 *	lfxo: lfxo {
 *		compatible = "nordic,nrf-lfxo";
 *		#clock-cells = < 0x0 >;
 *		clock-frequency = < 0x8000 >;
 *		load-capacitors = "internal";
 *		load-capacitance-femtofarad = < 0x3c8c >;
 *		phandle = < 0xc >;
 *	};
 *	hfxo: hfxo {
 *		compatible = "nordic,nrf-hfxo";
 *		#clock-cells = < 0x0 >;
 *		clock-frequency = < 0x1e84800 >;
 *		load-capacitors = "internal";
 *		load-capacitance-femtofarad = < 0x3a98 >;
 *		phandle = < 0x6 >;
 *	};
 *
 * The CONFIG_SOC_NRF_FORCE_CONSTLAT is not enabled.
 *
 * The following vreg configuration is supported:
 *
 *	vregmain: regulator@120600 {
 *		compatible = "nordic,nrf5x-regulator";
 *		reg = < 0x120600 0x1 >;
 *		status = "okay";
 *		regulator-name = "VREGMAIN";
 *		regulator-initial-mode = < 0x1 >; # 1 means NRF5X_REG_MODE_DCDC
 *	};
 * And the NRF54L_ERRATA_31_ENABLE_WORKAROUND is enabled.
 *
 */
int  __attribute__((weak)) nordicsemi_nrf54l_init(void){
	uint32_t xosc32ktrim = NRF_FICR->XOSC32KTRIM;

	uint32_t offset_k =
		(xosc32ktrim & FICR_XOSC32KTRIM_OFFSET_Msk) >> FICR_XOSC32KTRIM_OFFSET_Pos;

	uint32_t slope_field_k =
		(xosc32ktrim & FICR_XOSC32KTRIM_SLOPE_Msk) >> FICR_XOSC32KTRIM_SLOPE_Pos;
	uint32_t slope_mask_k = FICR_XOSC32KTRIM_SLOPE_Msk >> FICR_XOSC32KTRIM_SLOPE_Pos;
	uint32_t slope_sign_k = (slope_mask_k - (slope_mask_k >> 1));
	int32_t slope_k = (int32_t)(slope_field_k ^ slope_sign_k) - (int32_t)slope_sign_k;

	/* As specified in the nRF54L15 PS:
	 * CAPVALUE = round( (CAPACITANCE - 4) * (FICR->XOSC32KTRIM.SLOPE + 0.765625 * 2^9)/(2^9)
	 *            + FICR->XOSC32KTRIM.OFFSET/(2^6) );
	 * where CAPACITANCE is the desired capacitor value in pF, holding any
	 * value between 4 pF and 18 pF in 0.5 pF steps.
	 */

	/* Encoding of desired capacitance (single ended) to value required for INTCAP core
	 * calculation: (CAP_VAL - 4 pF)* 0.5
	 * That translate to ((CAP_VAL_FEMTO_F - 4000fF) * 2UL) / 1000UL
	 *
	 * NOTE: The desired capacitance value is used in encoded from in INTCAP calculation formula
	 *       That is different than in case of HFXO.
	 */
	uint32_t cap_val_encoded =
		(((0x3c8c - 4000UL) * 2UL) / 1000UL);

	/* Calculation of INTCAP code before rounding. Min that calculations here are done on
	 * values multiplied by 2^9, e.g. 0.765625 * 2^9 = 392.
	 * offset_k should be divided by 2^6, but to add it to value shifted by 2^9 we have to
	 * multiply it be 2^3.
	 */
	uint32_t mid_val =
		(cap_val_encoded - 4UL) * (uint32_t)(slope_k + 392UL) + (offset_k << 3UL);

	/* Get integer part of the INTCAP code */
	uint32_t lfxo_intcap = mid_val >> 9UL;

	/* Round based on fractional part */
	if ((mid_val & BIT_MASK(9)) > (BIT_MASK(9) / 2)) {
		lfxo_intcap++;
	}

	nrf_oscillators_lfxo_cap_set(NRF_OSCILLATORS, lfxo_intcap);

	uint32_t xosc32mtrim = NRF_FICR->XOSC32MTRIM;
	/* The SLOPE field is in the two's complement form, hence this special
	 * handling. Ideally, it would result in just one SBFX instruction for
	 * extracting the slope value, at least gcc is capable of producing such
	 * output, but since the compiler apparently tries first to optimize
	 * additions and subtractions, it generates slightly less than optimal
	 * code.
	 */
	uint32_t slope_field =
		(xosc32mtrim & FICR_XOSC32MTRIM_SLOPE_Msk) >> FICR_XOSC32MTRIM_SLOPE_Pos;
	uint32_t slope_mask = FICR_XOSC32MTRIM_SLOPE_Msk >> FICR_XOSC32MTRIM_SLOPE_Pos;
	uint32_t slope_sign = (slope_mask - (slope_mask >> 1));
	int32_t slope_m = (int32_t)(slope_field ^ slope_sign) - (int32_t)slope_sign;
	uint32_t offset_m =
		(xosc32mtrim & FICR_XOSC32MTRIM_OFFSET_Msk) >> FICR_XOSC32MTRIM_OFFSET_Pos;
	/* As specified in the nRF54L15 PS:
	 * CAPVALUE = (((CAPACITANCE-5.5)*(FICR->XOSC32MTRIM.SLOPE+791)) +
	 *              FICR->XOSC32MTRIM.OFFSET<<2)>>8;
	 * where CAPACITANCE is the desired total load capacitance value in pF,
	 * holding any value between 4.0 pF and 17.0 pF in 0.25 pF steps.
	 */

	/* NOTE 1: Requested HFXO internal capacitance in femto Faradas is used directly in formula
	 *         to calculate INTCAP code. That is different than in case of LFXO.
	 *
	 * NOTE 2: PS formula uses piko Farads, the implementation of the formula uses femto Farads
	 *         to avoid use of floating point data type.
	 */
	uint32_t cap_val_femto_f = 0x3a98;

	uint32_t mid_val_intcap = (((cap_val_femto_f - 5500UL) * (uint32_t)(slope_m + 791UL)) +
				   (offset_m << 2UL) * 1000UL) >>
				  8UL;

	/* Convert the calculated value to piko Farads */
	uint32_t hfxo_intcap = mid_val_intcap / 1000;

	/* Round based on fractional part */
	if (mid_val_intcap % 1000 >= 500) {
		hfxo_intcap++;
	}

	nrf_oscillators_hfxo_cap_set(NRF_OSCILLATORS, true, hfxo_intcap);

	/* Workaround for Errata 31 */
	if (nrf54l_errata_31()) {
		*((volatile uint32_t *)0x50120624ul) = 20 | 1<<5;
		*((volatile uint32_t *)0x5012063Cul) &= ~(1<<19);
	}


        return 0;
}

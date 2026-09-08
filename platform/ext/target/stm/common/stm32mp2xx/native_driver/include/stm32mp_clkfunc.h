/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef STM32MP_CLKFUNC_H
#define STM32MP_CLKFUNC_H

#include <stdbool.h>

#ifdef LIBFDT
#include <libfdt.h>

#include <platform_def.h>

int fdt_osc_read_freq(const char *name, uint32_t *freq);
bool fdt_clk_read_bool(const char *node_label, const char *prop_name);
uint32_t fdt_clk_read_uint32_default(const char *node_label,
				     const char *prop_name,
				     uint32_t dflt_value);

int fdt_get_rcc_node(void);
int fdt_rcc_read_uint32_array(const char *prop_name, uint32_t count,
			      uint32_t *array);
uint32_t fdt_rcc_read_uint32_default(const char *prop_name,
				     uint32_t dflt_value);
int fdt_rcc_subnode_offset(const char *name);
const fdt32_t *fdt_rcc_read_prop(const char *prop_name, int *lenp);
bool fdt_get_rcc_secure_status(void);
int fdt_rcc_enable_it(const char *name);

int fdt_get_clock_id(int node);
int fdt_get_clock_id_by_name(int node, const char *name);
unsigned long fdt_get_uart_clock_freq(uintptr_t instance);

bool fdt_is_pll1_predefined(void);
#endif
void __unused stm32mp_systick_config(unsigned long rate);
void __unused stm32mp_stgen_config(unsigned long rate);
void __unused stm32mp_stgen_restore_counter(unsigned long long value,
				   unsigned long long offset_in_ms);
unsigned long long __unused stm32mp_stgen_get_counter(void);
#endif /* STM32MP_CLKFUNC_H */

/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <errno.h>

#ifdef LIBFDT
#include <libfdt.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <common/fdt_wrappers.h>
#include <drivers/clk.h>
#include <drivers/generic_delay_timer.h>
#include <drivers/st/stm32_gpio.h>
#include <drivers/st/stm32mp_clkfunc.h>
#include <lib/mmio.h>

#define DT_UART_COMPAT		"st,stm32h7-uart"

/*
 * Get the frequency of an oscillator from its name in device tree.
 * @param name: oscillator name
 * @param freq: stores the frequency of the oscillator
 * @return: 0 on success, and a negative FDT/ERRNO error code on failure.
 */
int fdt_osc_read_freq(const char *name, uint32_t *freq)
{
	int node, subnode;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return -ENOENT;
	}

	node = fdt_path_offset(fdt, "/clocks");
	if (node < 0) {
		return -FDT_ERR_NOTFOUND;
	}

	fdt_for_each_subnode(subnode, fdt, node) {
		const char *cchar;
		int ret;

		cchar = fdt_get_name(fdt, subnode, &ret);
		if (cchar == NULL) {
			return ret;
		}

		if ((strncmp(cchar, name, (size_t)ret) == 0) &&
		    (fdt_get_status(subnode) != DT_DISABLED)) {
			const fdt32_t *cuint;

			cuint = fdt_getprop(fdt, subnode, "clock-frequency",
					    &ret);
			if (cuint == NULL) {
				return ret;
			}

			*freq = fdt32_to_cpu(*cuint);

			return 0;
		}
	}

	/* Oscillator not found, freq=0 */
	*freq = 0;
	return 0;
}

/*
 * Check the presence of an oscillator property from its id.
 * @param osc_id: oscillator ID
 * @param prop_name: property name
 * @return: true/false regarding search result.
 */
bool fdt_clk_read_bool(const char *node_label, const char *prop_name)
{
	int node, subnode;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return false;
	}

	node = fdt_path_offset(fdt, "/clocks");
	if (node < 0) {
		return false;
	}

	fdt_for_each_subnode(subnode, fdt, node) {
		const char *cchar;
		int ret;

		cchar = fdt_get_name(fdt, subnode, &ret);
		if (cchar == NULL) {
			return false;
		}

		if (strncmp(cchar, node_label, (size_t)ret) != 0) {
			continue;
		}

		if (fdt_getprop(fdt, subnode, prop_name, NULL) != NULL) {
			return true;
		}
	}

	return false;
}

/*
 * Get the value of a oscillator property from its name.
 * @param node_label: oscillator name
 * @param prop_name: property name
 * @param dflt_value: default value
 * @return oscillator value on success, default value if property not found.
 */
uint32_t fdt_clk_read_uint32_default(const char *node_label,
				     const char *prop_name, uint32_t dflt_value)
{
	int node, subnode;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return dflt_value;
	}

	node = fdt_path_offset(fdt, "/clocks");
	if (node < 0) {
		return dflt_value;
	}

	fdt_for_each_subnode(subnode, fdt, node) {
		const char *cchar;
		int ret;

		cchar = fdt_get_name(fdt, subnode, &ret);
		if (cchar == NULL) {
			return dflt_value;
		}

		if (strncmp(cchar, node_label, (size_t)ret) != 0) {
			continue;
		}

		return fdt_read_uint32_default(fdt, subnode, prop_name,
					       dflt_value);
	}

	return dflt_value;
}

/*
 * Get the RCC node offset from the device tree
 * @return: Node offset or a negative value on error
 */
int fdt_get_rcc_node(void)
{
	return dt_get_node_by_compatible(DT_RCC_CLK_COMPAT);
}

/*
 * Read a series of parameters in rcc-clk section in device tree
 * @param prop_name: Name of the RCC property to be read
 * @param array: the array to store the property parameters
 * @param count: number of parameters to be read
 * @return: 0 on succes or a negative value on error
 */
int fdt_rcc_read_uint32_array(const char *prop_name, uint32_t count,
			      uint32_t *array)
{
	int node;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return -ENOENT;
	}

	node = fdt_get_rcc_node();
	if (node < 0) {
		return -FDT_ERR_NOTFOUND;
	}

	return fdt_read_uint32_array(fdt, node, prop_name, count, array);
}

/*******************************************************************************
 * This function reads a property rcc-clk section.
 * It reads the values indicated inside the device tree, from property name.
 * Returns dflt_value if property is not found, and a property value on
 * success.
 ******************************************************************************/
uint32_t fdt_rcc_read_uint32_default(const char *prop_name, uint32_t dflt_value)
{
	int node;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return dflt_value;
	}


	node = fdt_get_rcc_node();
	if (node < 0) {
		return dflt_value;
	}

	return fdt_read_uint32_default(fdt, node, prop_name, dflt_value);
}

/*
 * Get the subnode offset in rcc-clk section from its name in device tree
 * @param name: name of the RCC property
 * @return: offset on success, and a negative FDT/ERRNO error code on failure.
 */
int fdt_rcc_subnode_offset(const char *name)
{
	int node, subnode;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return -ENOENT;
	}

	node = fdt_get_rcc_node();
	if (node < 0) {
		return -FDT_ERR_NOTFOUND;
	}

	subnode = fdt_subnode_offset(fdt, node, name);
	if (subnode <= 0) {
		return -FDT_ERR_NOTFOUND;
	}

	return subnode;
}

/*
 * Get the pointer to a rcc-clk property from its name.
 * @param name: name of the RCC property
 * @param lenp: stores the length of the property.
 * @return: pointer to the property on success, and NULL value on failure.
 */
const fdt32_t *fdt_rcc_read_prop(const char *prop_name, int *lenp)
{
	const fdt32_t *cuint;
	int node, len;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return NULL;
	}

	node = fdt_get_rcc_node();
	if (node < 0) {
		return NULL;
	}

	cuint = fdt_getprop(fdt, node, prop_name, &len);
	if (cuint == NULL) {
		return NULL;
	}

	*lenp = len;
	return cuint;
}

/*
 * Get the secure status for rcc node in device tree.
 * @return: true if rcc is available from secure world, false if not.
 */
bool fdt_get_rcc_secure_status(void)
{
	int node;

	node = fdt_get_rcc_node();
	if (node < 0) {
		return false;
	}

	return !!(fdt_get_status(node) & DT_SECURE);
}

/*
 * This function gets interrupt name.
 * It reads the values indicated the enabling status.
 * Returns 0 if success, and a negative value else.
 */
int fdt_rcc_enable_it(const char *name)
{
	int node = fdt_get_rcc_node();

	if (node < 0) {
		return -ENODEV;
	}

	return stm32_gic_enable_spi(node, name);
}

/*
 * Get the clock ID of the given node in device tree.
 * @param node: node offset
 * @return: Clock ID on success, and a negative FDT/ERRNO error code on failure.
 */
int fdt_get_clock_id(int node)
{
	const fdt32_t *cuint;
	void *fdt;

	if (fdt_get_address(&fdt) == 0) {
		return -ENOENT;
	}

	cuint = fdt_getprop(fdt, node, "clocks", NULL);
	if (cuint == NULL) {
		return -FDT_ERR_NOTFOUND;
	}

	cuint++;
	return (int)fdt32_to_cpu(*cuint);
}

/*******************************************************************************
 * This function gets the clock ID of the given node using clock-names.
 * It reads the value indicated inside the device tree.
 * Returns ID on success, and a negative FDT/ERRNO error code on failure.
 ******************************************************************************/
int fdt_get_clock_id_by_name(int node, const char *name)
{
	const fdt32_t *cuint;
	void *fdt;
	int index, len;

	if (fdt_get_address(&fdt) == 0) {
		return -ENOENT;
	}

	index = fdt_stringlist_search(fdt, node, "clock-names", name);
	if (index < 0) {
		return index;
	}

	cuint = fdt_getprop(fdt, node, "clocks", &len);
	if (cuint == NULL) {
		return -FDT_ERR_NOTFOUND;
	}

	if ((index * (int)sizeof(uint32_t)) > len) {
		return -FDT_ERR_BADVALUE;
	}

	cuint += (index << 1) + 1;
	return (int)fdt32_to_cpu(*cuint);
}

/*******************************************************************************
 * This function gets the frequency of the specified uart instance.
 * From this instance, all the uarts nodes in DT are parsed, and the register
 * base is compared to the instance. If match between these two values, then
 * the clock source is read from the DT and we deduce the frequency.
 * Returns clock frequency on success, 0 value on failure.
 ******************************************************************************/
unsigned long fdt_get_uart_clock_freq(uintptr_t instance)
{
	void *fdt;
	int node;
	int clk_id;

	if (fdt_get_address(&fdt) == 0) {
		return 0;
	}

	/* Check for UART nodes */
	node = dt_match_instance_by_compatible(DT_UART_COMPAT, instance);
	if (node < 0) {
		return 0UL;
	}

	clk_id = fdt_get_clock_id(node);
	if (clk_id < 0) {
		return 0UL;
	}

	return clk_get_rate((unsigned long)clk_id);
}

/*******************************************************************************
 * This function checks if PLL1 hard-coded settings have been defined in DT.
 * Returns true if PLL1 node is found and enabled, false if not.
 ******************************************************************************/
bool fdt_is_pll1_predefined(void)
{
	return fdt_check_node(fdt_rcc_subnode_offset(DT_PLL1_NODE_NAME));
}
#endif /* LIBFDT */

#ifdef M33_TDCID_REVIEW_NEEDED
/*******************************************************************************
 * This function gets the STGEN counter value.
 ******************************************************************************/
static unsigned long long stgen_get_counter(uintptr_t stgen)
{
#ifdef __aarch64__
	return mmio_read_64(stgen + CNTCV_OFF);
#else
	return (((unsigned long long)mmio_read_32(stgen + CNTCVU_OFF) << 32) |
		mmio_read_32(stgen + CNTCVL_OFF));
#endif
}

/*******************************************************************************
 * This function sets the STGEN counter value.
 ******************************************************************************/
static void stgen_set_counter(uintptr_t stgen, unsigned long long counter)
{
#ifdef __aarch64__
	mmio_write_64(stgen + CNTCV_OFF, counter);
#else
	mmio_write_32(stgen + CNTCVL_OFF, (uint32_t)counter);
	mmio_write_32(stgen + CNTCVU_OFF, (uint32_t)(counter >> 32));
#endif
}

/*******************************************************************************
 * This function configures and restores the STGEN counter depending on the
 * connected clock.
 ******************************************************************************/
void stm32mp_stgen_config(unsigned long rate)
{
	uint32_t cntfid0;
	unsigned long long counter;

	cntfid0 = mmio_read_32(STGEN_BASE + CNTFID_OFF);

	if (cntfid0 == rate) {
		return;
	}

	mmio_clrbits_32(STGEN_BASE + CNTCR_OFF, CNTCR_EN);
	counter = stgen_get_counter(STGEN_BASE);
	counter = (counter * rate / cntfid0);

	stgen_set_counter(STGEN_BASE, counter);
	mmio_write_32(STGEN_BASE + CNTFID_OFF, rate);
	mmio_setbits_32(STGEN_BASE + CNTCR_OFF, CNTCR_EN);

	write_cntfrq_el0((u_register_t)rate);

	/* Need to update timer with new frequency */
	generic_delay_timer_init();
}

/*******************************************************************************
 * This function returns the STGEN counter value.
 ******************************************************************************/
unsigned long long stm32mp_stgen_get_counter(void)
{
	return stgen_get_counter(STGEN_BASE);
}

/*******************************************************************************
 * This function restores the STGEN counter value.
 * It takes a first input value as a counter backup value to be restored and a
 * offset in ms to be added.
 ******************************************************************************/
void stm32mp_stgen_restore_counter(unsigned long long value,
				   unsigned long long offset_in_ms)
{
	unsigned long long cnt = value;

	cnt += (offset_in_ms * mmio_read_32(STGEN_BASE + CNTFID_OFF)) / 1000U;

	mmio_clrbits_32(STGEN_BASE + CNTCR_OFF, CNTCR_EN);
	stgen_set_counter(STGEN_BASE, cnt);
	mmio_setbits_32(STGEN_BASE + CNTCR_OFF, CNTCR_EN);
}
#else
void stm32mp_stgen_config(unsigned long rate) {}
void stm32mp_stgen_restore_counter(unsigned long long value,
				   unsigned long long offset_in_ms) {}
unsigned long long stm32mp_stgen_get_counter(void) { return 0; }
#endif /* M33_TDCID_REVIEW_NEEDED */

/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */

#define DT_STPMIC25_COMPAT st_stpmic2
#define DT_STPMIC2L_COMPAT st_stpmic2l
#define DT_STPMIC1L_COMPAT st_stpmic1l

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <lib/timeout.h>
#include <pm/device.h>
#include <pm/pm.h>

#include <device.h>
#include <i2c.h>
#include <irq.h>
#include <regulator.h>
#include <linear_range.h>

/* Status Registers */
#define PRODUCT_ID		U(0x00)
#define VERSION_SR		U(0x01)
#define TURN_ON_SR		U(0x02)
#define TURN_OFF_SR		U(0x03)
#define RESTART_SR		U(0x04)
#define OCP_SR1			U(0x05)
#define OCP_SR2			U(0x06)
#define EN_SR1			U(0x07)
#define EN_SR2			U(0x08)
#define FS_CNT_SR1		U(0x09)
#define FS_CNT_SR2		U(0x0A)
#define FS_CNT_SR3		U(0x0B)
#define MODE_SR			U(0x0C)
/* Control Registers */
#define MAIN_CR			U(0x10)
#define VINLOW_CR		U(0x11)
#define PKEY_LKP_CR		U(0x12)
#define WDG_CR			U(0x13)
#define WDG_TMR_CR		U(0x14)
#define WDG_TMR_SR		U(0x15)
#define FS_OCP_CR1		U(0x16)
#define FS_OCP_CR2		U(0x17)
#define PADS_PULL_CR		U(0x18)
#define BUCKS_PD_CR1		U(0x19)
#define BUCKS_PD_CR2		U(0x1A)
#define LDOS_PD_CR1		U(0x1B)
#define LDOS_PD_CR2		U(0x1C)
#define GPO_MRST_CR		U(0x1C)
#define BUCKS_MRST_CR		U(0x1D)
#define LDOS_MRST_CR		U(0x1E)
/* Buck CR */
#define BUCK1_MAIN_CR1		U(0x20)
#define BUCK1_MAIN_CR2		U(0x21)
#define BUCK1_ALT_CR1		U(0x22)
#define BUCK1_ALT_CR2		U(0x23)
#define BUCK1_PWRCTRL_CR	U(0x24)
#define BUCK2_MAIN_CR1		U(0x25)
#define BUCK2_MAIN_CR2		U(0x26)
#define BUCK2_ALT_CR1		U(0x27)
#define BUCK2_ALT_CR2		U(0x28)
#define BUCK2_PWRCTRL_CR	U(0x29)
#define BUCK3_MAIN_CR1		U(0x2A)
#define BUCK3_MAIN_CR2		U(0x2B)
#define BUCK3_ALT_CR1		U(0x2C)
#define BUCK3_ALT_CR2		U(0x2D)
#define BUCK3_PWRCTRL_CR	U(0x2E)
#define BUCK4_MAIN_CR1		U(0x2F)
#define BUCK4_MAIN_CR2		U(0x30)
#define BUCK4_ALT_CR1		U(0x31)
#define BUCK4_ALT_CR2		U(0x32)
#define BUCK4_PWRCTRL_CR	U(0x33)
#define BUCK5_MAIN_CR1		U(0x34)
#define BUCK5_MAIN_CR2		U(0x35)
#define BUCK5_ALT_CR1		U(0x36)
#define BUCK5_ALT_CR2		U(0x37)
#define BUCK5_PWRCTRL_CR	U(0x38)
#define BUCK6_MAIN_CR1		U(0x39)
#define BUCK6_MAIN_CR2		U(0x3A)
#define BUCK6_ALT_CR1		U(0x3B)
#define BUCK6_ALT_CR2		U(0x3C)
#define BUCK6_PWRCTRL_CR	U(0x3D)
#define BUCK7_MAIN_CR1		U(0x3E)
#define BUCK7_MAIN_CR2		U(0x3F)
#define BUCK7_ALT_CR1		U(0x40)
#define BUCK7_ALT_CR2		U(0x41)
#define BUCK7_PWRCTRL_CR	U(0x42)
/* GPO CR used only on PMIC1L and PMIC2L*/
#define GPO1_MAIN_CR		U(0x43)
#define GPO1_ALT_CR		U(0x44)
#define GPO1_PWRCTRL_CR		U(0x45)
#define GPO2_MAIN_CR		U(0x46)
#define GPO2_ALT_CR		U(0x47)
#define GPO2_PWRCTRL_CR		U(0x48)
/* LDO CR */
#define LDO1_MAIN_CR		U(0x4C)
#define LDO1_ALT_CR		U(0x4D)
#define LDO1_PWRCTRL_CR		U(0x4E)
#define LDO2_MAIN_CR		U(0x4F)
#define LDO2_ALT_CR		U(0x50)
#define LDO2_PWRCTRL_CR		U(0x51)
#define LDO3_MAIN_CR		U(0x52)
#define LDO3_ALT_CR		U(0x53)
#define LDO3_PWRCTRL_CR		U(0x54)
#define LDO4_MAIN_CR		U(0x55)
#define LDO4_ALT_CR		U(0x56)
#define LDO4_PWRCTRL_CR		U(0x57)
#define LDO5_MAIN_CR		U(0x58)
#define LDO5_ALT_CR		U(0x59)
#define LDO5_PWRCTRL_CR		U(0x5A)
#define LDO6_MAIN_CR		U(0x5B)
#define LDO6_ALT_CR		U(0x5C)
#define LDO6_PWRCTRL_CR		U(0x5D)
#define LDO7_MAIN_CR		U(0x5E)
#define LDO7_ALT_CR		U(0x5F)
#define LDO7_PWRCTRL_CR		U(0x60)
#define LDO8_MAIN_CR		U(0x61)
#define LDO8_ALT_CR		U(0x62)
#define LDO8_PWRCTRL_CR		U(0x63)
#define REFDDR_MAIN_CR		U(0x64)
#define REFDDR_ALT_CR		U(0x65)
#define REFDDR_PWRCTRL_CR	U(0x66)
/* GPO CR used only on PMIC1L and PMIC2L*/
#define GPO3_MAIN_CR		U(0x67)
#define GPO3_ALT_CR		U(0x68)
#define GPO3_PWRCTRL_CR		U(0x69)
#define GPO4_MAIN_CR		U(0x6A)
#define GPO4_ALT_CR		U(0x6B)
#define GPO4_PWRCTRL_CR		U(0x6C)
#define GPO5_MAIN_CR		U(0x6D)
#define GPO5_ALT_CR		U(0x6E)
#define GPO5_PWRCTRL_CR		U(0x6F)
/* INTERRUPT CR */
#define INT_PENDING_R1		U(0x70)
#define INT_PENDING_R2		U(0x71)
#define INT_PENDING_R3		U(0x72)
#define INT_PENDING_R4		U(0x73)
#define INT_CLEAR_R1		U(0x74)
#define INT_CLEAR_R2		U(0x75)
#define INT_CLEAR_R3		U(0x76)
#define INT_CLEAR_R4		U(0x77)
#define INT_MASK_R1		U(0x78)
#define INT_MASK_R2		U(0x79)
#define INT_MASK_R3		U(0x7A)
#define INT_MASK_R4		U(0x7B)
#define INT_SRC_R1		U(0x7C)
#define INT_SRC_R2		U(0x7D)
#define INT_SRC_R3		U(0x7E)
#define INT_SRC_R4		U(0x7F)
#define INT_DBG_LATCH_R1	U(0x80)
#define INT_DBG_LATCH_R2	U(0x81)
#define INT_DBG_LATCH_R3	U(0x82)
#define INT_DBG_LATCH_R4	U(0x83)
/* NVM shadow registers */
#define NVM_BUCK1_VOUT_SHR	U(0x9C)
#define NVM_BUCK2_VOUT_SHR	U(0x9D)
#define NVM_BUCK3_VOUT_SHR	U(0x9E)
#define NVM_BUCK4_VOUT_SHR	U(0x9F)
#define NVM_BUCK5_VOUT_SHR	U(0xA0)
#define NVM_BUCK6_VOUT_SHR	U(0xA1)
#define NVM_BUCK7_VOUT_SHR	U(0xA2)
#define NVM_LDO2_VOUT_SHR	U(0xA3)
#define NVM_LDO3_VOUT_SHR	U(0xA4)
#define NVM_LDO5_VOUT_SHR	U(0xA5)
#define NVM_LDO6_VOUT_SHR	U(0xA6)
#define NVM_LDO7_VOUT_SHR	U(0xA7)
#define NVM_LDO8_VOUT_SHR	U(0xA8)

/* PRODUCT_ID bits definition */
#define PMIC_NVM_ID_MASK	GENMASK_32(3, 0)
#define PMIC_REF_ID_MASK	GENMASK_32(7, 4)
#define PMIC_REF_ID_SHIFT	4
#define PMIC_REF_ID_STPMIC1L	U(1)
#define PMIC_REF_ID_STPMIC25	U(2)
#define PMIC_REF_ID_STPMIC2L	U(3)

/* VERSION_SR bits definition */
#define MINOR_VERSION_MASK	GENMASK_32(3, 0)
#define MINOR_VERSION_SHIFT	0
#define MAJOR_VERSION_MASK	GENMASK_32(7, 4)
#define MAJOR_VERSION_SHIFT	4

/* BUCKS_MRST_CR bits definition */
#define BUCK1_MRST		BIT(0)
#define BUCK2_MRST		BIT(1)
#define BUCK3_MRST		BIT(2)
#define BUCK4_MRST		BIT(3)
#define BUCK5_MRST		BIT(4)
#define BUCK6_MRST		BIT(5)
#define BUCK7_MRST		BIT(6)
#define REFDDR_MRST		BIT(7)

/* LDOS_MRST_CR bits definition */
#define LDO1_MRST		BIT(0)
#define LDO2_MRST		BIT(1)
#define LDO3_MRST		BIT(2)
#define LDO4_MRST		BIT(3)
#define LDO5_MRST		BIT(4)
#define LDO6_MRST		BIT(5)
#define LDO7_MRST		BIT(6)
#define LDO8_MRST		BIT(7)

/* GPO_MRST_CR bits definition */
#define GPO1_MRST		BIT(1)
#define GPO2_MRST		BIT(2)
#define GPO3_MRST		BIT(3)
#define GPO4_MRST		BIT(4)
#define GPO5_MRST		BIT(5)

/* LDOx_MAIN_CR */
#define LDO_VOUT_SHIFT		1
#define LDO_VOUT_MASK		GENMASK_32(5, 1)
#define LDO_BYPASS		BIT(6)
#define LDO1_INPUT_SRC		BIT(7)
#define LDO3_SNK_SRC		BIT(7)
#define LDO4_INPUT_SRC_SHIFT	6
#define LDO4_INPUT_SRC_MASK	GENMASK_32(7, 6)

/* PWRCTRL register bit definition */
#define PWRCTRL_EN		BIT(0)
#define PWRCTRL_RS		BIT(1)
#define PWRCTRL_SEL_SHIFT	2
#define PWRCTRL_SEL_MASK	GENMASK_32(3, 2)

/* BUCKx_MAIN/ALT_CR2 LDOx_MAIN/ALT_CR REFDDR_MAIN/ALT_CR*/
#define CR_EN_SHIFT		0
#define CR_EN_MASK		BIT(0)
#define CR_ENABLE		BIT(0)
#define CR_DISABLE		0

/* BUCKx_MAIN_CR1 / BUCKx_ALT_CR1 */
#define BUCKX_VOUT_SHIFT	0
#define BUCKX_VOUT_MASK		GENMASK_32(6, 0)

/* BUCKx_MAIN_CR2 / BUCKx_ALT_CR2 */
#define BUCKX_PREG_MODE_SHIFT	1
#define BUCKX_PREG_MODE_MASK	GENMASK_32(2, 1)

/* BUCKS_PD_CR1 */
#define BUCK1_PD_MASK		GENMASK_32(1, 0)
#define BUCK2_PD_MASK		GENMASK_32(3, 2)
#define BUCK3_PD_MASK		GENMASK_32(5, 4)
#define BUCK4_PD_MASK		GENMASK_32(7, 6)

#define BUCK1_PD_FAST		BIT(1)
#define BUCK2_PD_FAST		BIT(3)
#define BUCK3_PD_FAST		BIT(5)
#define BUCK4_PD_FAST		BIT(7)

/* BUCKS_PD_CR2 */
#define BUCK5_PD_MASK		GENMASK_32(1, 0)
#define BUCK6_PD_MASK		GENMASK_32(3, 2)
#define BUCK7_PD_MASK		GENMASK_32(5, 4)

#define BUCK5_PD_FAST		BIT(1)
#define BUCK6_PD_FAST		BIT(3)
#define BUCK7_PD_FAST		BIT(5)

/* LDOS_PD_CR1 */
#define LDO1_PD			BIT(0)
#define LDO2_PD			BIT(1)
#define LDO3_PD			BIT(2)
#define LDO4_PD			BIT(3)
#define LDO5_PD			BIT(4)
#define LDO6_PD			BIT(5)
#define LDO7_PD			BIT(6)
#define LDO8_PD			BIT(7)

/* LDOS_PD_CR2 */
#define REFDDR_PD		BIT(0)

/* FS_OCP_CR1 */
#define FS_OCP_BUCK1		BIT(0)
#define FS_OCP_BUCK2		BIT(1)
#define FS_OCP_BUCK3		BIT(2)
#define FS_OCP_BUCK4		BIT(3)
#define FS_OCP_BUCK5		BIT(4)
#define FS_OCP_BUCK6		BIT(5)
#define FS_OCP_BUCK7		BIT(6)
#define FS_OCP_REFDDR		BIT(7)

/* FS_OCP_CR2 */
#define FS_OCP_LDO1		BIT(0)
#define FS_OCP_LDO2		BIT(1)
#define FS_OCP_LDO3		BIT(2)
#define FS_OCP_LDO4		BIT(3)
#define FS_OCP_LDO5		BIT(4)
#define FS_OCP_LDO6		BIT(5)
#define FS_OCP_LDO7		BIT(6)
#define FS_OCP_LDO8		BIT(7)

#define _PMIC_NB_IRQ				U(32)
#define _PMIC_IRQ_PER_BANK			U(8)

#define _PMIC_SPEC_NARGS			U(1)
#define _PMIC_SPEC_ARG_IRQ			U(0)

#define PMIC_SPEC_GET_NARGS(ispec)		((ispec)->nargs)
#define PMIC_SPEC_GET_IRQ(ispec)		((ispec)->args[_PMIC_SPEC_ARG_IRQ])

#define PMIC_INT_REG_RX(_reg, _x)		((_reg) + (_x) / _PMIC_IRQ_PER_BANK)

/* NVM_BUCK1_VOUT_SHR (only for STPMIC1L and STPMIC2L) */
#define BUCK1_VRANGE_CFG	BIT(7)

#define STPMIC2_LP_STATE_OFF	BIT(0)
#define STPMIC2_LP_STATE_ON	BIT(1)

/*
 * Low power configurations for STPM32MP2 with STPMIC2:
 *
 * STM32_PM_DEFAULT
 *   "default" sub nodes in device-tree
 *   is applied at probe, and re-applied at PM resume.
 *   should support STOP1, LP-STOP1, STOP2, LP-STOP2
 *
 * STM32_PM_LPLV
 *   "lplv" sub nodes in device-tree
 *   should support LPLV-STOP2
 *
 * STM32_PM_STANDBY
 *   "standby" sub nodes in device-tree
 *   should support STANDBY-DDR-SR
 *   (Standby1 for STM32MP25/23, Standby for STM32MP21)
 *   is applied in pm suspend call back
 *
 * STM32_PM_OFF
 *   "off" sub nodes in device-tree
 *   should support STANDBY-DDR-OFF mode
 *   (Standby2 for STM32MP25/23, Standby for STM32MP21)
 *   and should be applied before shutdown
 *
 */
enum stpmic2_pm_mode {
	STM32_PM_DEFAULT = 0,
	STM32_PM_LPLV,
	STM32_PM_STANDBY,
	STM32_PM_OFF,
	STM32_PM_NB_MODES,
	STM32_PM_INVALID = -1,
};

/* Platform state value in pm_hint for platform OFF mode: Standby2 DDR off */
#define PM_OFF	(PM_HINT_PLATFORM_STATE_MASK >> PM_HINT_PLATFORM_STATE_SHIFT)

struct stpmic_config {
	struct i2c_dt_spec i2c;
	const struct irq_spec *int_spec;
	uint8_t ref_id;
};

struct stpmic_data {
	struct irq_handler **irq_hdl_tbl;
};

enum stpmic2_prop_id {
	STPMIC2_MASK_RESET = 0,
	STPMIC2_PULL_DOWN,
	STPMIC2_BYPASS,		/* takes arg = bypass enable */
	STPMIC2_SINK_SOURCE,
	STPMIC2_OCP,
	STPMIC2_PWRCTRL_EN,
	STPMIC2_PWRCTRL_RS,
	STPMIC2_PWRCTRL_SEL,	/* takes arg = pwrctrl line number */
	STPMIC2_MAIN_PREG_MODE,	/* takes arg = preg mode HP=1, CCM=2 */
	STPMIC2_ALT_PREG_MODE,	/* takes arg = preg mode HP=1, CCM=2 */
	STPMIC2_ALTERNATE_SOURCE,
};

struct regu_stpmic2_desc {
	const char *name;
	const struct linear_range *ranges;
	uint8_t nranges;
	uint8_t volt_cr;
	uint8_t nvm_volt_cr;
	uint8_t volt_shift;
	uint8_t volt_mask;
	uint8_t en_cr;
	uint8_t alt_en_cr;
	uint8_t alt_volt_cr;
	uint8_t pwrctrl_cr;
	uint8_t msrt_reg;
	uint8_t msrt_mask;
	uint8_t pd_reg;
	uint8_t pd_val;
	uint8_t pd_mask;
	uint8_t ocp_reg;
	uint8_t ocp_mask;
	bool has_bypass;
	bool has_sink;
	bool has_preg;
	bool has_alternate_source;
};

/* Voltage tables in uV */
static const struct linear_range __maybe_unused buck1236_ranges[] = {
	LINEAR_RANGE_INIT(500000, 10000U, 0, 100),
	LINEAR_RANGE_INIT(1500000, 0, 101, 127),
};

static const struct linear_range __maybe_unused buck457_ranges[] = {
	LINEAR_RANGE_INIT(1500000, 0, 0, 100),
	LINEAR_RANGE_INIT(1600000, 100000, 101, 127),
};

static const struct linear_range __maybe_unused ldo235678_ranges[] = {
	LINEAR_RANGE_INIT(900000, 100000, 0, 31),
};

static const struct linear_range __maybe_unused ldo1_ranges[] = {
	LINEAR_RANGE_INIT(1800000, 0, 0, 0),
};

static const struct linear_range __maybe_unused ldo4_ranges[] = {
	LINEAR_RANGE_INIT(3300000, 0, 0, 0),
};

static const struct linear_range __maybe_unused refddr_ranges[] = {
	LINEAR_RANGE_INIT(0, 0, 0, 0),
};

static const struct linear_range __maybe_unused gpox_ranges[] = {
	LINEAR_RANGE_INIT(3300000, 0, 0, 0),
};

#define DEFINE_BUCK(_regu_name, _id, _pd, _ranges) {		\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.en_cr			= _id ## _MAIN_CR2,		\
	.volt_cr		= _id ## _MAIN_CR1,		\
	.nvm_volt_cr		= NVM_ ## _id ## _VOUT_SHR,	\
	.volt_shift		= BUCKX_VOUT_SHIFT,		\
	.volt_mask		= BUCKX_VOUT_MASK,		\
	.alt_en_cr		= _id ## _ALT_CR2,		\
	.alt_volt_cr		= _id ## _ALT_CR1,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= BUCKS_MRST_CR,		\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= _pd,				\
	.pd_val			= _id ## _PD_FAST,		\
	.pd_mask		= _id ## _PD_MASK,		\
	.ocp_reg		= FS_OCP_CR1,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= false,			\
	.has_sink		= false,			\
	.has_preg		= true,				\
	.has_alternate_source	= false,			\
}

#define DEFINE_LDO_BYPASS(_regu_name, _id, _pd, _ranges) {	\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.volt_shift		= LDO_VOUT_SHIFT,		\
	.volt_mask		= LDO_VOUT_MASK,		\
	.nvm_volt_cr		= NVM_ ## _id ## _VOUT_SHR,	\
	.en_cr			= _id ## _MAIN_CR,		\
	.volt_cr		= _id ## _MAIN_CR,		\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.alt_volt_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= LDOS_MRST_CR,			\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= LDOS_PD_CR1,			\
	.pd_val			= _id ## _PD,			\
	.pd_mask		= _id ## _PD,			\
	.ocp_reg		= FS_OCP_CR2,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= true,				\
	.has_sink		= false,			\
	.has_alternate_source	= false,			\
}

#define DEFINE_LDO_BYPASS_SINK(_regu_name, _id, _pd, _ranges) {	\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.volt_shift		= LDO_VOUT_SHIFT,		\
	.volt_mask		= LDO_VOUT_MASK,		\
	.en_cr			= _id ## _MAIN_CR,		\
	.volt_cr		= _id ## _MAIN_CR,		\
	.nvm_volt_cr		= NVM_ ## _id ## _VOUT_SHR,	\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.alt_volt_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= LDOS_MRST_CR,			\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= LDOS_PD_CR1,			\
	.pd_val			= _id ## _PD,			\
	.pd_mask		= _id ## _PD,			\
	.ocp_reg		= FS_OCP_CR2,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= true,				\
	.has_sink		= true,				\
	.has_alternate_source	= false,			\
}

#define DEFINE_LDO(_regu_name, _id, _pd, _ranges) {		\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.volt_shift		= LDO_VOUT_SHIFT,		\
	.volt_mask		= 0x0,				\
	.en_cr			= _id ## _MAIN_CR,		\
	.volt_cr		= _id ## _MAIN_CR,		\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.alt_volt_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= LDOS_MRST_CR,			\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= LDOS_PD_CR1,			\
	.pd_val			= _id ## _PD,			\
	.pd_mask		= _id ## _PD,			\
	.ocp_reg		= FS_OCP_CR2,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= false,			\
	.has_sink		= false,			\
	.has_alternate_source	= false,			\
}

#define DEFINE_LDO1(_regu_name, _id, _pd, _ranges) {		\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.volt_shift		= LDO_VOUT_SHIFT,		\
	.volt_mask		= 0x0,				\
	.en_cr			= _id ## _MAIN_CR,		\
	.volt_cr		= _id ## _MAIN_CR,		\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.alt_volt_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= LDOS_MRST_CR,			\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= LDOS_PD_CR1,			\
	.pd_val			= _id ## _PD,			\
	.pd_mask		= _id ## _PD,			\
	.ocp_reg		= FS_OCP_CR2,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= false,			\
	.has_sink		= false,			\
	.has_alternate_source	= true,				\
}

#define DEFINE_REFDDR(_regu_name, _id, _pd, _ranges) {		\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.en_cr			= _id ## _MAIN_CR,		\
	.volt_cr		= _id ## _MAIN_CR,		\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.alt_volt_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= BUCKS_MRST_CR,		\
	.msrt_mask		= _id ## _MRST,			\
	.pd_reg			= LDOS_PD_CR2,			\
	.pd_val			= _id ## _PD,			\
	.pd_mask		= _id ## _PD,			\
	.ocp_reg		= FS_OCP_CR1,			\
	.ocp_mask		= FS_OCP_ ## _id,		\
	.has_bypass		= false,			\
	.has_sink		= false,			\
	.has_alternate_source	= false,			\
}

#define DEFINE_GPO(_regu_name, _id, _pd, _ranges) {		\
	.name			= _regu_name,			\
	.ranges			= _ranges,			\
	.nranges		= ARRAY_SIZE(_ranges),		\
	.en_cr			= _id ## _MAIN_CR,		\
	.alt_en_cr		= _id ## _ALT_CR,		\
	.pwrctrl_cr		= _id ## _PWRCTRL_CR,		\
	.msrt_reg		= GPO_MRST_CR,			\
	.msrt_mask		= _id ## _MRST,			\
}

struct regu_stpmic2_lp {
	unsigned int state;
	int32_t level_uv;
};

struct regu_stpmic2_config {
	struct regulator_common_config common;
	const struct regu_stpmic2_desc desc;
	struct regu_stpmic2_lp lp[STM32_PM_NB_MODES];
	bool st_mask_reset;
	bool st_pwrctrl;
	bool st_pwrctrl_reset;
	bool st_sink_source;
	bool st_alternate_source;
	int32_t st_pwrctrl_sel;
	int32_t st_bypass_uv;
	const struct device *pmic_dev;
};

struct regu_stpmic2_data {
	struct regulator_common_data data;
	bool use_buck457_ranges;
	bool forced_off;
	enum stpmic2_pm_mode lp_mode;
};

static void stpmic2_reg_get_range(const struct device *dev,
				  const struct linear_range **ranges,
				  size_t *nranges)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	struct regu_stpmic2_data *drv_data = dev_get_data(dev);

	/* BUCK1 with high voltage range for STPMIC1L and STPMIC2L */
	if (drv_data->use_buck457_ranges) {
		*ranges = buck457_ranges;
		*nranges = ARRAY_SIZE(buck457_ranges);
	} else {
		*ranges = regu_desc->ranges;
		*nranges = regu_desc->nranges;
	}
}

static int stpmic2_update_en_crs(const struct device *dev,
				 uint8_t mask, uint8_t value)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	int err;

	err = i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->en_cr,
				     mask, value);
	if (err)
		return err;

	return i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->alt_en_cr,
				      mask, value);
}

static int stpmic2_set_prop(const struct device *dev,
			    enum stpmic2_prop_id prop, uint8_t arg)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	int err = 0;

	switch (prop) {
	case STPMIC2_PULL_DOWN:
		return i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->pd_reg,
					      regu_desc->pd_val,
					      regu_desc->pd_val);
	case STPMIC2_MASK_RESET:
		if (!regu_desc->msrt_mask)
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->msrt_reg,
					      regu_desc->msrt_mask,
					      regu_desc->msrt_mask);
	case STPMIC2_BYPASS:
		if (!regu_desc->has_bypass)
			return -ENOTSUP;

		/* clear sink source mode if set bypass */
		if (arg && regu_desc->has_sink) {
			err = stpmic2_update_en_crs(dev, LDO3_SNK_SRC, 0);
			if (err)
				return err;
		}

		/* set or clear bypass depending on arg value */
		return stpmic2_update_en_crs(dev, LDO_BYPASS,
					     arg ? LDO_BYPASS : 0);
	case STPMIC2_SINK_SOURCE:
		if (!regu_desc->has_sink)
			return -ENOTSUP;

		/* clear bypass mode */
		err = stpmic2_update_en_crs(dev, LDO_BYPASS, 0);
		if (err)
			return err;

		return stpmic2_update_en_crs(dev, LDO3_SNK_SRC, LDO3_SNK_SRC);
	case STPMIC2_ALTERNATE_SOURCE:
		if (!regu_desc->has_alternate_source)
			return -ENOTSUP;

		return stpmic2_update_en_crs(dev, LDO1_INPUT_SRC, LDO1_INPUT_SRC);
	case STPMIC2_OCP:
		if (!regu_desc->ocp_reg)
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->ocp_reg,
					      regu_desc->ocp_mask,
					      regu_desc->ocp_mask);
	case STPMIC2_PWRCTRL_EN:
		if (!regu_desc->pwrctrl_cr)
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->pwrctrl_cr,
					      PWRCTRL_EN | PWRCTRL_RS,
					      PWRCTRL_EN);
	case STPMIC2_PWRCTRL_RS:
		if (!regu_desc->pwrctrl_cr)
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->pwrctrl_cr,
					      PWRCTRL_EN | PWRCTRL_RS,
					      arg ? PWRCTRL_RS : 0);
	case STPMIC2_PWRCTRL_SEL:
		if (!regu_desc->pwrctrl_cr)
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->pwrctrl_cr,
					      PWRCTRL_SEL_MASK,
					      _FLD_PREP(PWRCTRL_SEL, arg));
	case STPMIC2_MAIN_PREG_MODE:
		if ((!regu_desc->has_preg) || (arg > 2))
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->en_cr,
					      BUCKX_PREG_MODE_MASK,
					      _FLD_PREP(BUCKX_PREG_MODE, arg));
	case STPMIC2_ALT_PREG_MODE:
		if ((!regu_desc->has_preg) || (arg > 2))
			return -ENOTSUP;

		return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
					      regu_desc->alt_en_cr,
					      BUCKX_PREG_MODE_MASK,
					      _FLD_PREP(BUCKX_PREG_MODE, arg));
	default:
		err = -EINVAL;
	}

	return err;
}

static int stpmic2_reg_enable(const struct device *dev)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);

	return i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->en_cr,
				      CR_EN_MASK, CR_ENABLE);
}

static int stpmic2_reg_disable(const struct device *dev)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);

	return i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->en_cr,
				      CR_EN_MASK, CR_DISABLE);
}

static unsigned int stpmic2_reg_count_voltages(const struct device *dev)
{
	const struct linear_range *ranges;
	size_t nranges;

	stpmic2_reg_get_range(dev, &ranges, &nranges);

	return linear_range_group_values_count(ranges, nranges);
}

static int stpmic2_reg_list_voltage(const struct device *dev, unsigned int idx,
				     int32_t *volt_uv)
{
	const struct linear_range *ranges;
	size_t nranges;

	stpmic2_reg_get_range(dev, &ranges, &nranges);

	return linear_range_group_get_value(ranges, nranges, idx, volt_uv);
}

static int stpmic2_reg_set_voltage(const struct device *dev, int32_t min_uv,
				    int32_t max_uv)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	const struct linear_range *ranges;
	size_t nranges;
	uint8_t reg_idx;
	int32_t val_uv;
	uint16_t idx = 0;
	int err;

	/* if st_bypass_uv value is requested, set bypass and return */
	if (drv_cfg->st_bypass_uv && min_uv == max_uv && max_uv == drv_cfg->st_bypass_uv)
		return stpmic2_set_prop(dev, STPMIC2_BYPASS, 1);

	stpmic2_reg_get_range(dev, &ranges, &nranges);

	err = linear_range_group_get_win_index(ranges, nranges, min_uv, max_uv, &idx);

	err |= linear_range_group_get_value(ranges, nranges, idx, &val_uv);

	if (err)
		return -EINVAL;

	reg_idx = (idx << regu_desc->volt_shift) & regu_desc->volt_mask;

	err = i2c_reg_update_byte_dt(&pmic_cfg->i2c,
				     regu_desc->volt_cr,
				     regu_desc->volt_mask, reg_idx);
	if (err)
		return err;

	/* maybe clear bypass after set voltage */
	if (drv_cfg->st_bypass_uv) {
		err = stpmic2_set_prop(dev, STPMIC2_BYPASS, 0);
		if (err)
			return err;
	}

	return 0;
}

static int stpmic2_reg_get_volt_cr(const struct device *dev,
				   uint8_t volt_cr,
				   int32_t *volt_uv)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	const struct linear_range *ranges;
	size_t nranges;
	uint8_t val = 0;
	int err;

	/* read volt_cr register only when needed */
	if (regu_desc->volt_mask || regu_desc->has_bypass) {
		err = i2c_reg_read_byte_dt(&pmic_cfg->i2c, volt_cr, &val);
		if (err)
			return err;
	}

	if (drv_cfg->st_bypass_uv != 0 && regu_desc->has_bypass) {
		if (val & LDO_BYPASS) {
			*volt_uv = drv_cfg->st_bypass_uv;
			return 0;
		}
	}

	val = (val & regu_desc->volt_mask) >> regu_desc->volt_shift;

	stpmic2_reg_get_range(dev, &ranges, &nranges);

	return linear_range_group_get_value(ranges, nranges, val, volt_uv);
}

static int stpmic2_reg_get_voltage(const struct device *dev, int32_t *volt_uv)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;

	return stpmic2_reg_get_volt_cr(dev, regu_desc->volt_cr, volt_uv);
}

static int stpmic2_reg_get_default_voltage(const struct device *dev, int32_t *volt_uv)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;

	return stpmic2_reg_get_volt_cr(dev, regu_desc->nvm_volt_cr, volt_uv);
}

static int stpmic2_set_alt_state(const struct device *dev, bool enable)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	uint8_t value = enable ? CR_ENABLE : CR_DISABLE;

	return i2c_reg_update_byte_dt(&pmic_cfg->i2c, regu_desc->alt_en_cr,
				      CR_EN_MASK, value);
}

static int stpmic2_set_alt_voltage(const struct device *dev,  int32_t volt_uv)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	const struct linear_range *ranges;
	size_t nranges;
	uint8_t reg_idx;
	int32_t val_uv;
	uint16_t idx = 0;
	int err;

	stpmic2_reg_get_range(dev, &ranges, &nranges);

	err = linear_range_group_get_win_index(ranges, nranges, volt_uv, volt_uv, &idx);

	err |= linear_range_group_get_value(ranges, nranges, idx, &val_uv);

	if (err)
		return -EINVAL;

	reg_idx = (idx << regu_desc->volt_shift) & regu_desc->volt_mask;

	return i2c_reg_update_byte_dt(&pmic_cfg->i2c,
				      regu_desc->alt_volt_cr,
				      regu_desc->volt_mask, reg_idx);
}

static int stpmic2_reg_alt_mode(const struct device *dev, uint8_t mode)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	struct regu_stpmic2_data *drv_data = dev_get_data(dev);
	uint8_t state = drv_cfg->lp[mode].state;
	int level_uv = drv_cfg->lp[mode].level_uv;
	int err;

	DMSG("%s: suspend(%d): %x %d uV\n", dev->name, mode, state, level_uv);

	if (mode == drv_data->lp_mode)
		return 0;

	if (state & STPMIC2_LP_STATE_OFF) {
		err = stpmic2_set_alt_state(dev, false);
		if (err)
			return err;
	}

	if (state & STPMIC2_LP_STATE_ON) {
		err = stpmic2_set_alt_state(dev, true);
		if (err)
			return err;

		if (level_uv > 0U)  {
			err = stpmic2_set_alt_voltage(dev, level_uv);
			if (err)
				return err;
		}
	}

	drv_data->lp_mode = mode;

	return 0;
}

#ifdef CONFIG_PM_DEVICE
static int stpmic2_reg_pm_suspend(const struct device *dev, uint8_t mode)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	struct regu_stpmic2_data *drv_data = dev_get_data(dev);
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	uint8_t state = drv_cfg->lp[mode].state;
	uint8_t en_cr;
	int err;

	 drv_data->forced_off = false;
	 /*
	  * If controlled by the consumer (i.e. power control line disabled),
	  * and requested OFF in suspend mode, force disable the regulator
	  */
	if (!drv_cfg->st_pwrctrl && (state & STPMIC2_LP_STATE_OFF)) {
		err = i2c_reg_read_byte_dt(&pmic_cfg->i2c, regu_desc->en_cr, &en_cr);
		if (err)
			return err;
		if ((en_cr & CR_EN_MASK) == CR_ENABLE) {
			err = stpmic2_reg_disable(dev);
			if (err)
				return err;
			IMSG("regulator %s forced OFF\n", dev->name);
			drv_data->forced_off = true;
		}
	}

	/*
	 * pwrctrl reset only for system low power modes and not for D1 DStandby
	 * when regulator are reset to default values for ROM code execution
	 */
	if (drv_cfg->st_pwrctrl_reset)
		return stpmic2_set_prop(dev, STPMIC2_PWRCTRL_RS, 1);

	return 0;
}

static int stpmic2_reg_pm_resume(const struct device *dev)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	struct regu_stpmic2_data *drv_data = dev_get_data(dev);
	int err;

	if (drv_data->forced_off) {
		/* Re-enable a regulator that was forced off in suspend */
		err = stpmic2_reg_enable(dev);
		if (err)
			return err;

		drv_data->forced_off = false;
	}

	if (drv_cfg->st_pwrctrl_reset)
		return stpmic2_set_prop(dev, STPMIC2_PWRCTRL_RS, 0);

	return 0;
}

static int stpmic2_reg_pm_action(const struct device *dev,
				 enum pm_device_action action,
				 uint32_t pm_hint)
{
	unsigned int pwrlvl = PM_HINT_PLATFORM_STATE(pm_hint);
	uint8_t mode;
	int err = 0;

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		/* configure PMIC level according platform PM domain */
		switch (pwrlvl) {
		case PM_LPLV_STOP2:
			mode = STM32_PM_LPLV;
			break;
		case PM_STANDBY1:
			mode = STM32_PM_STANDBY;
			break;
		case PM_OFF:
			mode = STM32_PM_OFF;
			break;
		default:
			mode = STM32_PM_DEFAULT;
			break;
		}
		err = stpmic2_reg_alt_mode(dev, mode);
		if (err)
			goto out;
		err = stpmic2_reg_pm_suspend(dev, mode);
	}
	if (action == PM_DEVICE_ACTION_RESUME) {
		err = stpmic2_reg_alt_mode(dev, STM32_PM_DEFAULT);
		if (err)
			goto out;
		err = stpmic2_reg_pm_resume(dev);
	}

out:
	return err;
}
#endif

static void _show_reg(const struct i2c_dt_spec *i2c, uint8_t i2c_addr, char *name)
{
	uint8_t val;
	int err;

	if (!i2c_addr)
		return;

	err = i2c_reg_read_byte_dt(i2c, i2c_addr, &val);
	if (err) {
		EMSG("read %s error %d\n", name, err);
		return;
	}

	IMSG("\t[%02x]=%02x\t%s\n", i2c_addr, val, name);
}

static int stpmic2_reg_show(const struct device *dev)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);

	IMSG("dump regu:%s\n", dev->name);

	_show_reg(&pmic_cfg->i2c, regu_desc->volt_cr, "volt_cr");
	_show_reg(&pmic_cfg->i2c, regu_desc->en_cr, "en_cr");
	_show_reg(&pmic_cfg->i2c, regu_desc->alt_en_cr, "alt_en_cr");
	_show_reg(&pmic_cfg->i2c, regu_desc->alt_volt_cr, "alt_volt_cr");
	_show_reg(&pmic_cfg->i2c, regu_desc->pwrctrl_cr, "pwrctrl_cr");
	_show_reg(&pmic_cfg->i2c, regu_desc->msrt_reg, "msrt_reg");
	_show_reg(&pmic_cfg->i2c, regu_desc->pd_reg, "pd_reg");
	_show_reg(&pmic_cfg->i2c, regu_desc->ocp_reg, "ocp_reg");
	_show_reg(&pmic_cfg->i2c, regu_desc->nvm_volt_cr, "nvm_volt_cr");

	return 0;
}

static int stpmic2_parse_prop(const struct device *dev)
{
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	int err = 0;

	if (drv_cfg->st_mask_reset)
		err |= stpmic2_set_prop(dev, STPMIC2_MASK_RESET, 0);

	if (drv_cfg->st_pwrctrl_sel)
		err |= stpmic2_set_prop(dev, STPMIC2_PWRCTRL_SEL,
					drv_cfg->st_pwrctrl_sel);

	if (drv_cfg->st_pwrctrl)
		err |= stpmic2_set_prop(dev, STPMIC2_PWRCTRL_EN, 0);

	if (drv_cfg->st_sink_source)
		err |= stpmic2_set_prop(dev, STPMIC2_SINK_SOURCE, 0);

	if (drv_cfg->st_alternate_source)
		err |= stpmic2_set_prop(dev, STPMIC2_ALTERNATE_SOURCE, 0);

	return err ? -EINVAL : 0;
}

static int __used stpmic2_reg_init(const struct device *dev)
{
	struct regu_stpmic2_data *drv_data = dev_get_data(dev);
	const struct regu_stpmic2_config *drv_cfg = dev_get_config(dev);
	const struct regu_stpmic2_desc *regu_desc = &drv_cfg->desc;
	const struct stpmic_config *pmic_cfg = dev_get_config(drv_cfg->pmic_dev);
	uint8_t nvm;
	int err;

	regulator_common_data_init(dev);

	/* BUCK1 high voltage range selected in NVM for STPMIC1L and 2L */
	if (regu_desc->volt_cr == BUCK1_MAIN_CR1 &&
	    pmic_cfg->ref_id != PMIC_REF_ID_STPMIC25) {
		err = i2c_reg_read_byte_dt(&pmic_cfg->i2c, NVM_BUCK1_VOUT_SHR, &nvm);
		if (err)
			return err;
		if (nvm & BUCK1_VRANGE_CFG)
			drv_data->use_buck457_ranges = true;
	}
	err = stpmic2_parse_prop(dev);
	if (err)
		return err;

	if (drv_cfg->common.flags & REGULATOR_PULL_DOWN) {
		err = stpmic2_set_prop(dev, STPMIC2_PULL_DOWN, 0);
		if (err)
			return err;
	}

	if (drv_cfg->common.flags & REGULATOR_OVER_CURRENT) {
		err = stpmic2_set_prop(dev, STPMIC2_OCP, 0);
		if (err)
			return err;
	}

	err = regulator_common_init(dev, false);
	if (err)
		return err;

	err = stpmic2_reg_alt_mode(dev, STM32_PM_DEFAULT);
	if (err) {
		EMSG("Failed to prepare suspend for regulator %s (%d)\n",
		     dev->name, err);
		return err;
	}

#if LOG_LEVEL >= LOG_LEVEL_VERBOSE
	/* For TF-M debug, dump the regulators after STPMIC initialization */
	if (!IS_ENABLED(STM32_BL2))
		regulator_show(dev);
#endif

	return 0;
};

static const struct regulator_driver_api stpmic2_api = {
	.enable = stpmic2_reg_enable,
	.disable = stpmic2_reg_disable,
	.count_voltages = stpmic2_reg_count_voltages,
	.list_voltage = stpmic2_reg_list_voltage,
	.set_voltage = stpmic2_reg_set_voltage,
	.get_voltage = stpmic2_reg_get_voltage,
	.get_default_voltage = stpmic2_reg_get_default_voltage,
	.show = stpmic2_reg_show,
};

#define LP_DEFINE(node_id, id)									\
[id] = {											\
	.state = ((DT_PROP_OR(node_id, regulator_off_in_suspend, 0U) * STPMIC2_LP_STATE_OFF) |	\
		  (DT_PROP_OR(node_id, regulator_on_in_suspend, 0U) * STPMIC2_LP_STATE_ON)),\
	.level_uv = DT_PROP_OR(node_id, regulator_suspend_microvolt, 0),			\
},

#define LP_DEFINE_COND(node_id, child, id)					\
	COND_CODE_1(								\
		DT_NODE_EXISTS(DT_CHILD(node_id, child)),			\
		(LP_DEFINE(DT_CHILD(node_id, child), id)),			\
		())

#define REGULATOR_DEFINE(dev, node_id, id, macro_desc, reg_id, pd, ranges)		\
	static struct regu_stpmic2_data data_##id = {					\
		.use_buck457_ranges = false,						\
		.forced_off = false,							\
		.lp_mode = STM32_PM_INVALID,						\
	};										\
											\
	static const struct regu_stpmic2_config cfg_##id = {				\
		.common = REGULATOR_DT_COMMON_CONFIG_INIT(node_id),			\
		.common.ramp_delay_uv_per_us = DT_PROP_OR(node_id,			\
							  regulator_ramp_delay,		\
							  U(2200)),			\
		.common.enable_ramp_delay_us = DT_PROP_OR(node_id,			\
							  regulator_enable_ramp_delay,	\
							  U(1000)),			\
		.st_mask_reset = DT_PROP(node_id, st_mask_reset),			\
		.st_pwrctrl = DT_PROP(node_id, st_pwrctrl_enable),			\
		.st_pwrctrl_reset = DT_PROP(node_id, st_pwrctrl_reset),			\
		.st_pwrctrl_sel = DT_PROP_OR(node_id, st_pwrctrl_sel, 0),		\
		.st_bypass_uv = DT_PROP_OR(node_id, st_regulator_bypass_microvolt, 0),	\
		.st_sink_source = DT_PROP(node_id, st_regulator_sink_source),		\
		.st_alternate_source = DT_PROP(node_id, st_alternate_input_source),	\
		.desc = macro_desc(STRINGIFY(id), reg_id, pd, ranges),			\
		.lp =  {								\
			LP_DEFINE_COND(node_id, default, STM32_PM_DEFAULT)		\
			LP_DEFINE_COND(node_id, lplv, STM32_PM_LPLV)			\
			LP_DEFINE_COND(node_id, standby, STM32_PM_STANDBY)		\
			LP_DEFINE_COND(node_id, off, STM32_PM_OFF)			\
		},									\
		.pmic_dev = dev,							\
	};										\
											\
	PM_DEVICE_DT_DEFINE(node_id, stpmic2_reg_pm_action, PM_DEVICE_F_NONE);		\
											\
	DEVICE_DT_DEFINE(node_id, &stpmic2_reg_init,					\
			 PM_DEVICE_DT_GET(node_id),					\
			 &data_##id, &cfg_##id,						\
			 CORE, 7, &stpmic2_api);

#define REGULATOR_DEFINE_COND(dev, n, inst, child, macro_desc, reg_id, pd, ranges)	\
	COND_CODE_1(									\
		DT_NODE_EXISTS(DT_CHILD(n, child)),					\
		(REGULATOR_DEFINE(dev, DT_CHILD(n, child),				\
				  inst ## _ ## child,					\
				  macro_desc, reg_id, pd, ranges)),			\
		())

static int __maybe_unused _stpmic_irq_mask(const struct device *dev, uint32_t irq, bool state)
{
	const struct stpmic_config *dev_cfg = dev_get_config(dev);
	uint8_t reg = PMIC_INT_REG_RX(INT_MASK_R1, irq);
	uint8_t mask = BIT(irq % _PMIC_IRQ_PER_BANK);
	uint8_t val = state ? mask : 0;

	return i2c_reg_update_byte_dt(&dev_cfg->i2c, reg, mask, val);
}

static __unused int stpmic_i2c_dump(const struct device *dev)
{
	const struct stpmic_config *dev_cfg = dev_get_config(dev);
	int i;

	for (i = 0; i < div_round_up(_PMIC_NB_IRQ, _PMIC_IRQ_PER_BANK); i++) {
		uint8_t pend, mask, src;

		i2c_reg_read_byte_dt(&dev_cfg->i2c, INT_PENDING_R1 + i, &pend);
		i2c_reg_read_byte_dt(&dev_cfg->i2c, INT_MASK_R1 + i, &mask);
		i2c_reg_read_byte_dt(&dev_cfg->i2c, INT_SRC_R1 + i, &src);
		IMSG("%s: R%d pend:0x%x mask:0x%x src:0x%x\r\n",
		     dev->name, i, pend, mask, src);
	}

	return 0;
}

static irqreturn_t __maybe_unused stpmic_isr(void *data)
{
	const struct device *dev = data;
	const struct stpmic_config *dev_cfg = dev_get_config(dev);
	struct stpmic_data *dev_data = dev_get_data(dev);
	irqreturn_t irq_ret = IRQ_NONE;
	uint8_t i, int_pend_rx, pending;
	int err;

	for (i = 0; i < div_round_up(_PMIC_NB_IRQ, _PMIC_IRQ_PER_BANK); i++) {
		err = i2c_reg_read_byte_dt(&dev_cfg->i2c, INT_PENDING_R1 + i, &int_pend_rx);
		if (err) {
			EMSG("%s: read INT_PENDING_R%u fail err:%d\r\n", dev->name, i + 1, err);
			continue;
		}

		if (!int_pend_rx)
			continue;

		pending = int_pend_rx;

		do {
			uint8_t irq_n = (i * _PMIC_IRQ_PER_BANK) + __builtin_ctz(pending);
			struct irq_handler *irq_hdl = dev_data->irq_hdl_tbl[irq_n];

			pending &= pending - 1;

			if (!irq_hdl || !irq_hdl->callback) {
				continue;
			}

			irq_hdl->callback(irq_hdl->data);
		} while (pending);

		/* Ack all interrupts of RX */
		err = i2c_reg_write_byte_dt(&dev_cfg->i2c, INT_CLEAR_R1 + i, int_pend_rx);
		if (err) {
			EMSG("%s: write INT_CLEAR_R%u fail err:%d\r\n", dev->name, i + 1, err);
			continue;
		}

		irq_ret = IRQ_HANDLED;
	}

	return irq_ret;
}

static int __maybe_unused stpmic_interrupt_request(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	struct stpmic_data *dev_data = dev_get_data(dev);
	uint32_t irq;

	if (PMIC_SPEC_GET_NARGS(spec) != _PMIC_SPEC_NARGS)
		return -EINVAL;

	irq = PMIC_SPEC_GET_IRQ(spec);
	if (irq >= _PMIC_NB_IRQ)
		return -ENOTSUP;

	spec->irq_hdl->irq = irq;
	dev_data->irq_hdl_tbl[irq] = spec->irq_hdl;

	return 0;
}

static int __maybe_unused stpmic_interrupt_enable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	uint32_t irq = spec->irq_hdl->irq;

	if (irq >= _PMIC_NB_IRQ)
		return -ENOTSUP;

	return _stpmic_irq_mask(dev, irq, false);
}

static int __maybe_unused stpmic_interrupt_disable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	uint32_t irq = spec->irq_hdl->irq;

	if (irq >= _PMIC_NB_IRQ)
		return -ENOTSUP;

	return _stpmic_irq_mask(dev, irq, true);
}

static const struct interrupt_controller_api __maybe_unused stpmic_interrupt_api = {
	.request = stpmic_interrupt_request,
	.enable = stpmic_interrupt_enable,
	.disable = stpmic_interrupt_disable,
};

static int __maybe_unused stpmic_interrupt_init(const struct device *dev)
{
	const struct stpmic_config *drv_cfg = dev_get_config(dev);
	uint32_t i;
	int err;

	if (!drv_cfg->int_spec)
		return 0;

	/* clear and mask all interrupts before request parent interrupt */
	for (i = 0; i < div_round_up(_PMIC_NB_IRQ, _PMIC_IRQ_PER_BANK); i++) {
		err = i2c_reg_write_byte_dt(&drv_cfg->i2c, INT_CLEAR_R1 + i, 0xFF);
		if (err) {
			EMSG("%s: write INT_CLEAR_R:%u fail\r\n", dev->name, i + 1);
			return err;
		}

		err = i2c_reg_write_byte_dt(&drv_cfg->i2c, INT_MASK_R1 + i, 0xFF);
		if (err) {
			EMSG("%s: write INT_MASK_R1mask:%d fail\r\n", dev->name, i + 1);
			return err;
		}
	}

	err = interrupt_request(drv_cfg->int_spec, (void *)dev, stpmic_isr, IRQF_NONE);
	if (err)
		EMSG("%s: interrupt request fail: %d\r\n", dev->name, err);

	return err;
}

static int __maybe_unused stpmic_probe(const struct device *dev)
{
	const struct stpmic_config *drv_cfg = dev_get_config(dev);
	uint8_t prod_id, version;
	uint8_t ref_id;
	int err;

	if (!i2c_is_ready_dt(&drv_cfg->i2c)) {
		EMSG("init:%s not accessible\n", dev->name);
		panic();
		return -ENODEV;
	}

	err = i2c_reg_read_byte_dt(&drv_cfg->i2c, PRODUCT_ID, &prod_id);
	if (err) {
		EMSG("init:%s not accessible (%d)\n", dev->name, err);
		return err;
	}

	err = i2c_reg_read_byte_dt(&drv_cfg->i2c, VERSION_SR, &version);
	if (err) {
		EMSG("init:%s not accessible (%d)\n", dev->name, err);
		return err;
	}

	ref_id = _FLD_GET(PMIC_REF_ID, prod_id);
	IMSG("init:%s STPMIC:%02x V%d.%d\n", dev->name,
	     prod_id,
	     _FLD_GET(MAJOR_VERSION, version),
	     _FLD_GET(MINOR_VERSION, version));

	if (ref_id != drv_cfg->ref_id) {
		EMSG("init:%s unexpected ref id, %02x expected.\n",
		     dev->name, drv_cfg->ref_id);
		panic();
		return -ENODEV;
	}

	if (IS_ENABLED(STM32_SEC))
		err = stpmic_interrupt_init(dev);

	return err;
}

#define _PMIC_INTC_IRQ_TBL_NAME(inst) \
	_CONCAT(DEVICE_DT_NAME_GET(DT_DRV_INST(inst)), _irq_hdl_tbl)

#define _PMIC_INTC_IRQ_HDL_TBL_DEFINE(inst, n_irqs) \
	static struct irq_handler *_PMIC_INTC_IRQ_TBL_NAME(inst)[n_irqs];

#define STPMIC_INIT(t, n, _ref_id)						\
										\
DT_INST_IRQS_SPEC_DEFINE(n)							\
_PMIC_INTC_IRQ_HDL_TBL_DEFINE(n, _PMIC_NB_IRQ)					\
										\
static const struct stpmic_config stpmic##t##_cfg_##n = {			\
	.i2c = I2C_DT_SPEC_GET(DT_DRV_INST(n)),					\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),					\
	.ref_id = _ref_id,							\
};										\
										\
static struct stpmic_data stpmic##t##_data_##n = {				\
	.irq_hdl_tbl = _PMIC_INTC_IRQ_TBL_NAME(n),				\
};										\
										\
DEVICE_DT_INST_DEFINE(n, &stpmic_probe,	NULL,					\
	&stpmic##t##_data_##n, &stpmic##t##_cfg_##n,				\
	CORE, 6,								\
	&stpmic_interrupt_api);

/* STPMIC25 */
#define REGULATORS_STPMIC25_DEFINE(dev, n, inst)				\
	REGULATOR_DEFINE_COND(dev, n, inst, buck1, DEFINE_BUCK,			\
			      BUCK1, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck2, DEFINE_BUCK,			\
			      BUCK2, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck3, DEFINE_BUCK,			\
			      BUCK3, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck4, DEFINE_BUCK,			\
			      BUCK4, BUCKS_PD_CR1, buck457_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck5, DEFINE_BUCK,			\
			      BUCK5, BUCKS_PD_CR2, buck457_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck6, DEFINE_BUCK,			\
			      BUCK6, BUCKS_PD_CR2, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck7, DEFINE_BUCK,			\
			      BUCK7, BUCKS_PD_CR2, buck457_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, refddr, DEFINE_REFDDR,		\
			      REFDDR, NULL, refddr_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo1, DEFINE_LDO1,			\
			      LDO1, NULL, ldo1_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo2, DEFINE_LDO_BYPASS,		\
			      LDO2, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo3, DEFINE_LDO_BYPASS_SINK,	\
			      LDO3, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo4, DEFINE_LDO,			\
			      LDO4, NULL, ldo4_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo5, DEFINE_LDO_BYPASS,		\
			      LDO5, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo6, DEFINE_LDO_BYPASS,		\
			      LDO6, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo7, DEFINE_LDO_BYPASS,		\
			      LDO7, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo8, DEFINE_LDO_BYPASS,		\
			      LDO8, NULL, ldo235678_ranges)			\

#define STPMIC25_INIT(n)							\
	STPMIC_INIT(25, n, PMIC_REF_ID_STPMIC25)				\
	COND_CODE_1(DT_NODE_EXISTS(DT_INST_CHILD(n, regulators)),		\
		    (REGULATORS_STPMIC25_DEFINE(DEVICE_DT_INST_GET(n),		\
						DT_INST_CHILD(n, regulators),	\
						stpmic25_ ## n)),		\
		    ())

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT DT_STPMIC25_COMPAT
DT_INST_FOREACH_STATUS_OKAY(STPMIC25_INIT)

/* STPMIC2L */
#define REGULATORS_STPMIC2L_DEFINE(dev, n, inst)				\
	REGULATOR_DEFINE_COND(dev, n, inst, buck1, DEFINE_BUCK,			\
			      BUCK1, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck2, DEFINE_BUCK,			\
			      BUCK2, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck3, DEFINE_BUCK,			\
			      BUCK3, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo1, DEFINE_LDO1,			\
			      LDO1, NULL, ldo1_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo2, DEFINE_LDO_BYPASS,		\
			      LDO2, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo3, DEFINE_LDO_BYPASS_SINK,	\
			      LDO3, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo4, DEFINE_LDO,			\
			      LDO4, NULL, ldo4_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo5, DEFINE_LDO_BYPASS,		\
			      LDO5, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo6, DEFINE_LDO_BYPASS,		\
			      LDO6, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo7, DEFINE_LDO_BYPASS,		\
			      LDO7, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo1, DEFINE_GPO,			\
			      GPO1, NULL, gpox_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo2, DEFINE_GPO,			\
			      GPO2, NULL, gpox_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo3, DEFINE_GPO,			\
			      GPO3, NULL, gpox_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo4, DEFINE_GPO,			\
			      GPO4, NULL, gpox_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo5, DEFINE_GPO,			\
			      GPO5, NULL, gpox_ranges)				\

#define STPMIC2L_INIT(n)							\
	STPMIC_INIT(2l, n, PMIC_REF_ID_STPMIC2L)				\
	COND_CODE_1(DT_NODE_EXISTS(DT_INST_CHILD(n, regulators)),		\
		    (REGULATORS_STPMIC2L_DEFINE(DEVICE_DT_INST_GET(n),		\
						DT_INST_CHILD(n, regulators),	\
						stpmic2l_ ## n)),		\
		    ())

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT DT_STPMIC2L_COMPAT
DT_INST_FOREACH_STATUS_OKAY(STPMIC2L_INIT)

/* STPMIC1L  */
#define REGULATORS_STPMIC1L_DEFINE(dev, n, inst)				\
	REGULATOR_DEFINE_COND(dev, n, inst, buck1, DEFINE_BUCK,			\
			      BUCK1, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, buck2, DEFINE_BUCK,			\
			      BUCK2, BUCKS_PD_CR1, buck1236_ranges)		\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo2, DEFINE_LDO_BYPASS,		\
			      LDO2, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo3, DEFINE_LDO_BYPASS_SINK,	\
			      LDO3, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo4, DEFINE_LDO,			\
			      LDO4, NULL, ldo4_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, ldo5, DEFINE_LDO_BYPASS,		\
			      LDO5, NULL, ldo235678_ranges)			\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo1, DEFINE_GPO,			\
			      GPO1, NULL, gpox_ranges)				\
	REGULATOR_DEFINE_COND(dev, n, inst, gpo2, DEFINE_GPO,			\
			      GPO2, NULL, gpox_ranges)				\

#define STPMIC1L_INIT(n)							\
	STPMIC_INIT(1l, n, PMIC_REF_ID_STPMIC1L)				\
	COND_CODE_1(DT_NODE_EXISTS(DT_INST_CHILD(n, regulators)),		\
		    (REGULATORS_STPMIC1L_DEFINE(DEVICE_DT_INST_GET(n),		\
						DT_INST_CHILD(n, regulators),	\
						stpmic1l_ ## n)),		\
		    ())

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT DT_STPMIC1L_COMPAT
DT_INST_FOREACH_STATUS_OKAY(STPMIC1L_INIT)

/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 */

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <cmsis_compiler.h>

#include <device.h>
#include <debug.h>
#include <firewall.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <nvmem.h>
#include <pm/device.h>
#include <pm/pm.h>

#include <stm32_bsec3.h>
#include <tfm_plat_otp.h>

/* BSEC REGISTER OFFSET (base relative) */
#define _BSEC_FVR(i)			(U(0x000) + 4U * (i))
#define _BSEC_SPLOCK(i)			(U(0x800) + 4U * (i))
#define _BSEC_SWLOCK(i)			(U(0x840) + 4U * (i))
#define _BSEC_SRLOCK(i)			(U(0x880) + 4U * (i))
#define _BSEC_OTPVLDR(i)		(U(0x8C0) + 4U * (i))
#define _BSEC_SFSR(i)			(U(0x940) + 4U * (i))
#define _BSEC_OTPCR			U(0xC04)
#define _BSEC_WDR			U(0xC08)
#define _BSEC_LOCKR			U(0xE10)
#define _BSEC_DENR			U(0xE20)
#define _BSEC_SR			U(0xE40)
#define _BSEC_OTPSR			U(0xE44)
#define _BSEC_DBGMCR			U(0xE8C)
#define _BSEC_AP_UNLOCK			U(0xE90)
#define _BSEC_HDPLMSR			U(0xE94)
#define _BSEC_HDPLMCR			U(0xE98)
#define _BSEC_DBGACR			U(0xEAC)
#define _BSEC_VERR			U(0xFF4)
#define _BSEC_IPIDR			U(0xFF8)

/* BSEC_OTPSR register fields */
#define _BSEC_OTPSR_BUSY		BIT(0)
#define _BSEC_OTPSR_INIT_DONE		BIT(1)
#define _BSEC_OTPSR_HIDEUP		BIT(2)
#define _BSEC_OTPSR_OTPNVIR		BIT(4)
#define _BSEC_OTPSR_OTPERR		BIT(5)
#define _BSEC_OTPSR_OTPSEC		BIT(6)
#define _BSEC_OTPSR_PROGFAIL		BIT(16)
#define _BSEC_OTPSR_DISTURBF		BIT(17)
#define _BSEC_OTPSR_DEDF		BIT(18)
#define _BSEC_OTPSR_SECF		BIT(19)
#define _BSEC_OTPSR_PPLF		BIT(20)
#define _BSEC_OTPSR_PPLMF		BIT(21)
#define _BSEC_OTPSR_AMEF		BIT(22)

/* BSEC_LOCKR register fields */
#define _BSEC_LOCKR_GWLOCK_MASK		BIT(0)

/* BSEC_DENR register fields */
#define _BSEC_DENR_DBG_FULL		GENMASK_32(11, 0)

/* Compute DENR_RCODE (SECDED ECC) as HAMMING(17,12) with parity */
#define PARITY_4BIT(x)			((((x) >> 3) ^ ((x) >> 2) ^ ((x) >> 1) ^ (x)) & 1)
#define PARITY_12BIT(x)			PARITY_4BIT(((x) >> 8) ^ ((x) >> 4) ^ (x))
#define _BSEC_DENR_RCODE(x)		(((PARITY_12BIT((x) & 0x800)) << 17) | \
					 ((PARITY_12BIT((x) & 0x7f0)) << 16) | \
					 ((PARITY_12BIT((x) & 0x78e)) << 15) | \
					 ((PARITY_12BIT((x) & 0x66d)) << 14) | \
					 ((PARITY_12BIT((x) & 0xd5b)) << 13) | \
					 ((PARITY_12BIT((x) & 0xcb7)) << 12))
#define BSEC_DENR_v(x)			(_BSEC_DENR_RCODE((x) & _BSEC_DENR_DBG_FULL) | \
					 ((x) & _BSEC_DENR_DBG_FULL))

/* BSEC_SR register fields */
#define _BSEC_SR_HVALID_MASK		BIT(1)
#define _BSEC_SR_HVALID_SHIFT		0
#define _BSEC_SR_NVSTATES_MASK		GENMASK_32(31, 26)
#define _BSEC_SR_NVSTATES_SHIFT		26

#define _BSEC_SR_NVSTATES_OPEN		U(0x16)
#define _BSEC_SR_NVSTATES_CLOSED	U(0x0D)
#define _BSEC_SR_NVSTATES_OTP_LOCKED	U(0x23)

#define _OTP_ACCESS_SIZE			12U

#define _HIDEUP_ERROR			(LOCK_SHADOW_R | LOCK_SHADOW_W | \
					 LOCK_SHADOW_P | LOCK_ERROR)

/* BSEC_HDPLMCR register fields */
#define BSEC_HDPLMCR_INC_MAGIC		U(0x60B166E7)

/* 32 bit by OTP bank in each register */
#define _BSEC_OTP_BIT_MASK		GENMASK_32(4, 0)
#define _BSEC_OTP_BIT_SHIFT		0
#define _BSEC_OTP_BANK_MASK		GENMASK_32(31, 5)
#define _BSEC_OTP_BANK_SHIFT		5U

#define _MAX_NB_TRIES			3U

/* Timeout when polling on status */
#define _BSEC_TIMEOUT_US		U(10000)

/* OTP18 = BOOTROM_CONFIG_0-3: Security life-cycle word 2 */
#define _OTP_SECURE_BOOT		18U
#define _OTP_CLOSED_SECURE		GENMASK_32(3, 0)

/*
 * otp shadow depend of TDCID loader
 * which copies bsec otp to shadow memory.
 * must be aligned with [TDCID loader]stm32_bsec3 driver
 */
#ifdef STM32MP21xxxx
#define STM32MP2_OTP_MAX_ID		363
#define OTP_MAX_SIZE			(STM32MP2_OTP_MAX_ID + 1U)
#else
#define STM32MP2_OTP_MAX_ID		367
#define OTP_MAX_SIZE			(STM32MP2_OTP_MAX_ID + 1U)
#endif

#define STM32MP2_UPPER_BASE		256

#define BSEC_VERR_1_2			U(0x00000012)

#define HDPL_ARRAY_SIZE			U(4)

static const uint8_t hdpl_array[HDPL_ARRAY_SIZE] = {0xB4, 0x51, 0x8A, 0x6F};

/* BSEC_DBGMCR, BSEC_DBGACR, BSEC_AP_UNLOCK registers fields & constants */
#define BSEC_AUTH_UNLOCK_MASK		GENMASK_32(15, 8)
#define BSEC_AUTH_UNLOCK_SHIFT		8
#define BSEC_AUTH_HDPL_MASK		GENMASK_32(23, 16)
#define BSEC_AUTH_HDPL_SHIFT		16
#define BSEC_AUTH_SEC_MASK		GENMASK_32(31, 24)
#define BSEC_AUTH_SEC_SHIFT		24
#define BSEC_AP_UNLOCK_MASK		GENMASK_32(7, 0)
#define BSEC_AP_UNLOCK_SHIFT		0
#define BSEC_AUTH_UNLOCKED		0xb4
#define BSEC_AUTH_LOCKED		0xff
#define BSEC_DBGxCR_NOT_SET		0x00000bad

struct nvmem_cell {
	const char *cell_label;
	uint32_t otp_id;
	uint32_t n_otp;
	const uint32_t *shadow_value;
	uint32_t n_shadow_value;
};

struct bsec_mirror {
	uint32_t magic;
	uint32_t state;
	struct {
		uint32_t value;
		uint32_t status;
	} otp[OTP_MAX_SIZE];
};

struct stm32_bsec_config {
	uintptr_t base;
	uintptr_t mirror_addr;
	size_t mirror_size;
	const struct firewall_spec *firewall_ctrls;
	const int n_firewall_ctrls;
	const struct nvmem_cell *otp_cell;
	int n_otp_cell;
};

struct stm32_bsec_variant {
	uint32_t max_id;
	unsigned int oem_key_first_otp;
	uint32_t denr_all_mask;
	uint32_t denr_key;
	bool has_hdpl;
};

struct stm32_bsec_data {
	const struct stm32_bsec_variant *variant;
	bool hw_key_valid;
	struct bsec_mirror *p_mirror;
	uint32_t verr;
	uint32_t dbgacr;
};

static const struct device *bsec_dev;


static bool is_bsec_write_locked(void)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);

	return (mmio_read_32(drv_cfg->base + _BSEC_LOCKR) &
		_BSEC_LOCKR_GWLOCK_MASK) != 0U;
}

static int shadow_otp(const struct device *dev, uint32_t otp)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	struct stm32_bsec_data *drv_data = dev_get_data(dev);
	struct bsec_mirror *mirror = drv_data->p_mirror;
	uint32_t i, err, sr = 0;

	if (mirror) {
		/* if shadow is not allowed */
		if (mirror->otp[otp].status & LOCK_SHADOW_R) {
			mirror->otp[otp].status |= LOCK_ERROR;
			mirror->otp[otp].value = 0x0U;
			return -EACCES;
		}

		mirror->otp[otp].status &= ~LOCK_ERROR;
	}

	for (i = 0U; i < _MAX_NB_TRIES; i++) {
		io_write32(drv_cfg->base + _BSEC_OTPCR, otp);

		err = mmio_read32_poll_timeout(drv_cfg->base + _BSEC_OTPSR, sr,
					       (!(sr & _BSEC_OTPSR_BUSY)),
					       _BSEC_TIMEOUT_US);

		if (err) {
			EMSG("BSEC busy timeout\n");
			panic();
		}

		/* Retry on error */
		if (sr & (_BSEC_OTPSR_AMEF | _BSEC_OTPSR_DISTURBF |
			  _BSEC_OTPSR_DEDF))
			continue;

		/* break for OTP correctly shadowed */
		break;
	}

	if (mirror && sr & _BSEC_OTPSR_PPLF)
		mirror->otp[otp].status |= LOCK_PERM;

	if (i == _MAX_NB_TRIES || sr & (_BSEC_OTPSR_PPLMF | _BSEC_OTPSR_AMEF |
					_BSEC_OTPSR_DISTURBF |
					_BSEC_OTPSR_DEDF)) {
		if (mirror)
			mirror->otp[otp].status |= LOCK_ERROR;

		return -EIO;
	}

	return 0;
}

static bool is_fuse_shadowed(uint32_t otp)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	uint32_t bank = _FLD_GET(_BSEC_OTP_BANK, otp);
	uint32_t mask = BIT(_FLD_GET(_BSEC_OTP_BIT, otp));
	uint32_t bank_value = io_read32(drv_cfg->base + _BSEC_SFSR(bank));

	if (bank_value & mask)
		return true;

	return false;
}

/*
 * bsec_read_otp: read an OTP data value.
 * val: read value.
 * otp: OTP number.
 * return value: 0 if no error.
 */
static int __maybe_unused stm32_bsec_read_otp(uint32_t *val, uint32_t otp)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	int ret;

	if (!val || otp > drv_data->variant->max_id)
		return -EINVAL;

	*val = 0U;
	ret = shadow_otp(bsec_dev, otp);
	if (!ret)
		*val = io_read32(drv_cfg->base + _BSEC_FVR(otp));

	return ret;
}

/*
 * bsec_shadow_read_otp: Load OTP from SAFMEM and provide its value
 * val: read value.
 * otp: OTP number.
 * return value: 0 if no error.
 */
static int __maybe_unused stm32_bsec_shadow_read_otp(uint32_t *val,
						     uint32_t otp)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	int ret = 0;

	if (!val || otp > drv_data->variant->max_id)
		return -EINVAL;

	*val = 0U;
	if (!is_fuse_shadowed(otp))
		ret = shadow_otp(bsec_dev, otp);
	if (!ret)
		*val = io_read32(drv_cfg->base + _BSEC_FVR(otp));

	return ret;
}

/*
 * bsec_write_otp: write value in BSEC data register.
 * value: value to write.
 * otp: OTP number.
 * return value: 0 if no error.
 */
static int __maybe_unused stm32_bsec_write_otp(uint32_t value, uint32_t otp)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	bool sw_lock = false;
	int ret;

	if (otp > drv_data->variant->max_id)
		return -EINVAL;

	if (is_bsec_write_locked())
		return -EPERM;

	/* for HW shadowed OTP, update value in FVR register */
	if (is_fuse_shadowed(otp)) {
		ret = stm32_bsec_read_sw_lock(otp, &sw_lock);
		if (ret)
			return ret;

		if (sw_lock)
			return -EPERM;


		io_write32(drv_cfg->base + _BSEC_FVR(otp), value);
	}

	return 0;
}

void stm32_bsec_parse_permissions(uint32_t perm_mask,
				  uint32_t *dbg_en_val,
				  uint32_t *dbg_a_ctrl_val,
				  uint32_t *dbg_m_ctrl_val,
				  uint32_t *ap_unlock)
{
	*dbg_en_val = 0;
	*dbg_a_ctrl_val = 0;
	*dbg_m_ctrl_val = 0;
	*ap_unlock = 0;

	/* TODO: manage ADAC_SOC_MASK (OTP 101) */

	/* Prepare value for BSEC debug enable register */
	if (!(perm_mask & STM32MP2_PERM_MASK_A35NSDDIS)) {
		if (perm_mask & STM32MP2_PERM_MASK_A35NSTO)
			*dbg_en_val |= BSEC_DENR_NIDENA;
		if (perm_mask & STM32MP2_PERM_MASK_A35NSFD)
			*dbg_en_val |= BSEC_DENR_NIDENA | BSEC_DENR_DBGENA;
	}
	if (!(perm_mask & STM32MP2_PERM_MASK_A35SDDIS)) {
		if (perm_mask & STM32MP2_PERM_MASK_A35STO)
			*dbg_en_val |= BSEC_DENR_SPNIDENA;
		if (perm_mask & STM32MP2_PERM_MASK_A35SFD)
			*dbg_en_val |= BSEC_DENR_SPNIDENA | BSEC_DENR_SPIDENA;
	}
	if (!(perm_mask & STM32MP2_PERM_MASK_M33NSDDIS)) {
		if (perm_mask & STM32MP2_PERM_MASK_M33NSTO)
			*dbg_en_val |= BSEC_DENR_NIDENM;
		if (perm_mask & STM32MP2_PERM_MASK_M33NSFD)
			*dbg_en_val |= BSEC_DENR_NIDENM | BSEC_DENR_DBGENM;
	}
	if (!(perm_mask & STM32MP2_PERM_MASK_M33SDDIS)) {
		if (perm_mask & STM32MP2_PERM_MASK_M33STO)
			*dbg_en_val |= BSEC_DENR_SPNIDENM;
		if (perm_mask & STM32MP2_PERM_MASK_M33SFD)
			*dbg_en_val |= BSEC_DENR_SPNIDENM | BSEC_DENR_SPIDENM;
	}
	if (*dbg_en_val != 0) /* At least one debug profile is enabled */
		*dbg_en_val |= BSEC_DENR_DEVICEEN | BSEC_DENR_HDPEN | BSEC_DENR_DBGSWEN;

	/* Prepare values for BSEC debug control registers */
	if (IS_ENABLED(STM32MP21xxxx)) {
		int8_t lvl = HDPL_ARRAY_SIZE - 1;

		for (lvl = HDPL_ARRAY_SIZE - 1; lvl >= 0; lvl--) {
			if (perm_mask & STM32MP21_PERM_MASK_A35HDP(lvl)) {
				*dbg_a_ctrl_val |= _FLD_PREP(BSEC_AUTH_HDPL, hdpl_array[lvl]);
				break;
			}
		}
		for (lvl = HDPL_ARRAY_SIZE - 1; lvl >= 0; lvl--) {
			if (perm_mask & STM32MP21_PERM_MASK_M33HDP(lvl)) {
				*dbg_m_ctrl_val |= _FLD_PREP(BSEC_AUTH_HDPL, hdpl_array[lvl]);
				break;
			}
		}

		if (!(perm_mask & STM32MP2_PERM_MASK_A35NSDDIS))
			*dbg_a_ctrl_val |= _FLD_PREP(BSEC_AUTH_UNLOCK, BSEC_AUTH_UNLOCKED);
		if (!(perm_mask & STM32MP2_PERM_MASK_A35SDDIS))
			*dbg_a_ctrl_val |= _FLD_PREP(BSEC_AUTH_SEC, BSEC_AUTH_UNLOCKED);
		if (!(perm_mask & STM32MP2_PERM_MASK_M33NSDDIS))
			*dbg_m_ctrl_val |= _FLD_PREP(BSEC_AUTH_UNLOCK, BSEC_AUTH_UNLOCKED);
		if (!(perm_mask & STM32MP2_PERM_MASK_M33SDDIS))
			*dbg_m_ctrl_val |= _FLD_PREP(BSEC_AUTH_SEC, BSEC_AUTH_UNLOCKED);

		if ((_FLD_GET(BSEC_AUTH_UNLOCK, *dbg_a_ctrl_val) == BSEC_AUTH_UNLOCKED) ||
		    (_FLD_GET(BSEC_AUTH_UNLOCK, *dbg_m_ctrl_val) == BSEC_AUTH_UNLOCKED))
			/* At least one is unlocked, unlock the access port */
			*ap_unlock = _FLD_PREP(BSEC_AP_UNLOCK, BSEC_AUTH_UNLOCKED);
		else 	/* Both are locked, lock the access port */
			*ap_unlock = _FLD_PREP(BSEC_AP_UNLOCK, BSEC_AUTH_LOCKED);
	}

	/* TODO: STM32MP2_PERM_MASK_WAITATTACH */
}

int stm32_bsec_write_debug_conf(uint32_t perm_mask)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	uint32_t denr, dbgacr, dbgmcr, ap_unlock;

	if (!IS_ENABLED(STM32_M33TDCID))
		return 0;

	if (is_bsec_write_locked())
		panic();

	stm32_bsec_parse_permissions(perm_mask, &denr, &dbgacr, &dbgmcr, &ap_unlock);

	denr &= drv_data->variant->denr_all_mask;

	if (drv_data->verr >= BSEC_VERR_1_2)
		denr = BSEC_DENR_v(denr);

	mmio_write_32(drv_cfg->base + _BSEC_DENR,
		      drv_data->variant->denr_key | denr);

	if (mmio_read_32(drv_cfg->base + _BSEC_DENR) != (drv_data->variant->denr_key | denr))
		return -EIO;

	if (drv_data->verr >= BSEC_VERR_1_2) {
		mmio_write_32(drv_cfg->base + _BSEC_DBGACR, dbgacr);
		mmio_write_32(drv_cfg->base + _BSEC_DBGMCR, dbgmcr);
		mmio_write_32(drv_cfg->base + _BSEC_AP_UNLOCK, ap_unlock);

		/*
		 * Can't check the value of DBGACR, since Cortex-A may be under reset. The write
		 * could have been ignored, but the value will be written later when the Cortex-A
		 * starts.
		 */
		if (mmio_read_32(drv_cfg->base + _BSEC_DBGMCR) != dbgmcr)
			return -EIO;
		if (mmio_read_32(drv_cfg->base + _BSEC_AP_UNLOCK) != ap_unlock)
			return -EIO;

		drv_data->dbgacr = dbgacr;
	}

	return 0;
}

void stm32_bsec_restore_cortexa_debug_conf(void)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	uint32_t dbgacr = BSEC_DBGxCR_NOT_SET;

	if (!IS_ENABLED(STM32_M33TDCID))
		return;

	if (drv_data->verr < BSEC_VERR_1_2)
		return;

#if defined(DAUTH_NONE)
	dbgacr = 0;
#elif defined(DAUTH_NS_ONLY)
	dbgacr = 0x00b4b400;
#elif defined(DAUTH_FULL)
	dbgacr = 0xb4b4b400;
#elif defined(DAUTH_CHIP_DEFAULT)
	dbgacr = drv_data->dbgacr;
#endif

	if (dbgacr == BSEC_DBGxCR_NOT_SET)
		return;

	mmio_write_32(drv_cfg->base + _BSEC_DBGACR, dbgacr);
}

int stm32_bsec_increment_hdpl(void)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	uint32_t hdpl, hdpl_inc;
	uint32_t i;

	if (!drv_data->variant->has_hdpl)
		return 0;

	hdpl = io_read32(drv_cfg->base + _BSEC_HDPLMSR);
	for (i = 0; i < HDPL_ARRAY_SIZE; i++) {
		if (hdpl_array[i] == hdpl)
			break;
	}

	if (i == HDPL_ARRAY_SIZE) {
		EMSG("Unsupported HDPL value %x\n", hdpl);
		return -EINVAL;
	}

	io_write32(drv_cfg->base + _BSEC_HDPLMCR, BSEC_HDPLMCR_INC_MAGIC);

	if (i < HDPL_ARRAY_SIZE - 1)
		i++;

	hdpl_inc = io_read32(drv_cfg->base + _BSEC_HDPLMSR);
	if (hdpl_inc != hdpl_array[i]) {
		EMSG("Error fail to increment HDPL, %x but expecting %x\n",
		     hdpl_inc, hdpl_array[i]);
		return -EINVAL;
	}

	return 0;
}

bool stm32_bsec_is_huk_ready(void)
{
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);

	return drv_data->hw_key_valid;
}

static inline int _otp_is_valid(uint32_t status)
{
	return !(status & (STATUS_SECURE | LOCK_ERROR));
}

static int _otp_read(uint32_t otp_id, size_t len, size_t out_len, uint8_t *out)
{
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	struct bsec_mirror *mirror = drv_data->p_mirror;
	size_t copy_size = len < out_len ? len : out_len;
	uint32_t *p_out_w = (uint32_t *)out;
	uint32_t idx;

	if (copy_size % (sizeof(uint32_t)))
		return -EINVAL;

	for (idx = 0; idx < (copy_size / sizeof(uint32_t)); idx++) {
		if (mirror) {
			if (!_otp_is_valid(mirror->otp[otp_id + idx].status))
				return -EPERM;

			p_out_w[idx] = mirror->otp[otp_id + idx].value;
		} else {
			uint32_t val;
			int res;

			res = stm32_bsec_shadow_read_otp(&val, otp_id + idx);
			if (res) {
				memset(p_out_w, 0, copy_size);
				return -EIO;
			}

			p_out_w[idx] = val;
		}
	}

	return 0;
}

static int __maybe_unused _otp_write(uint32_t otp_id, size_t len,
				     size_t in_len, const uint8_t *in)
{
	struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);
	struct bsec_mirror *mirror = drv_data->p_mirror;
	uint32_t *p_in_w = (uint32_t *)in;
	uint32_t idx;

	if (len != in_len)
		return -EINVAL;

	if (len % (sizeof(uint32_t)))
		return -EINVAL;

	for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
		if (mirror) {
			if (!_otp_is_valid(mirror->otp[otp_id + idx].status))
				return -EPERM;

			mirror->otp[otp_id + idx].value = p_in_w[idx];
			mirror->otp[otp_id + idx].status = LOCK_SHADOW_R;
		} else {
			if (stm32_bsec_write_otp(p_in_w[idx], otp_id + idx))
				return -EIO;
		}
	}

	return 0;
}

/*
 * STM32 driver Interface
 */
int stm32_bsec_read_sw_lock(uint32_t otp, bool *value)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(bsec_dev);
	const struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);

	if (!value)
		return -EINVAL;

	if (otp > drv_data->variant->max_id)
		return -EINVAL;

	if (drv_data->p_mirror) {
		*value = !!(drv_data->p_mirror->otp[otp].status & LOCK_SHADOW_W);
	} else {
		uint32_t bank = _FLD_GET(_BSEC_OTP_BANK, otp);
		uint32_t mask = BIT(_FLD_GET(_BSEC_OTP_BIT, otp));

		*value = !!(io_read32(drv_cfg->base + _BSEC_SWLOCK(bank)) & mask);
	}

	return 0;
}

int stm32_bsec_write(uint32_t otp, uint32_t value)
{
	const struct stm32_bsec_data *drv_data = dev_get_data(bsec_dev);

	if (stm32_bsec_write_otp(value, otp))
		return -EIO;

	/* update bsec mirror */
	if (drv_data->p_mirror)
		drv_data->p_mirror->otp[otp].value = value;

	return 0;
}

/*
 * Interface with TFM
 */
static int stm32_bsec_nvmem_get_cell_size(const struct device *dev, size_t *size)
{
	const struct nvmem_cell *cell = dev_get_config(dev);

	if (!cell)
		return -EINVAL;

	*size = cell->n_otp * sizeof(uint32_t);

	return 0;
}

static int stm32_bsec_nvmem_read_cell(const struct device *dev, size_t out_len, uint8_t *out,
			       size_t *read_len)
{
	const struct nvmem_cell *cell = dev_get_config(dev);
	int res;

	if (!cell ||  out_len > cell->n_otp * sizeof(uint32_t))
		return -EINVAL;

	res = _otp_read(cell->otp_id, cell->n_otp * sizeof(uint32_t), out_len, out);
	if (res) {
		memset(out, 0, out_len);
		return res;
	}

	*read_len = out_len;

	return 0;
}

static int stm32_bsec_nvmem_write_cell(const struct device *dev, size_t in_len, const uint8_t *in)
{
	return -ENOTSUP;
}

static void stm32_bsec_check_error(uint32_t opt_status)
{
	if (opt_status & _BSEC_OTPSR_OTPSEC)
		DMSG("BSEC reset single error correction detected\n");

	if (!(opt_status & _BSEC_OTPSR_OTPNVIR))
		DMSG("BSEC virgin OTP word 0\n");

	if (opt_status & _BSEC_OTPSR_HIDEUP)
		DMSG("BSEC upper fuse not accessible\n");

	if (opt_status & _BSEC_OTPSR_OTPERR) {
		EMSG("BSEC shadow error detected\n");
		panic();
	}

	if (!(opt_status & _BSEC_OTPSR_INIT_DONE)) {
		EMSG("BSEC reset operations not completed\n");
		panic();
	}

	if (is_bsec_write_locked()) {
		EMSG("BSEC global write lock\n");
		panic();
	}
}

static uint32_t init_state(const struct device *dev, uint32_t status)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	struct stm32_bsec_data *drv_data = dev_get_data(dev);
	struct bsec_mirror *mirror = drv_data->p_mirror;
	uint32_t state = BSEC_STATE_INVALID;

	if (status & _BSEC_OTPSR_INIT_DONE) {
		/* NVSTATES is only valid if INIT_DONE = 1 */
		uint32_t sr = io_read32(drv_cfg->base + _BSEC_SR);
		uint32_t nvstates = _FLD_GET(_BSEC_SR_NVSTATES, sr);

		/* Only 1 supported state = CLOSED */
		if (nvstates != _BSEC_SR_NVSTATES_CLOSED) {
			state = BSEC_STATE_INVALID;
			EMSG("BSEC invalid nvstates 0x%x\n", nvstates);
		} else {
			state = BSEC_STATE_SEC_OPEN;
			if (mirror->otp[_OTP_SECURE_BOOT].value & _OTP_CLOSED_SECURE)
				state = BSEC_STATE_SEC_CLOSED;
		}

		if (_FLD_GET(_BSEC_SR_HVALID, sr))
			state |= BSEC_HARDWARE_KEY;
	}

	return state;
}


static void stm32_bsec_mirror_load(const struct device *dev, uint32_t status)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	struct stm32_bsec_data *drv_data = dev_get_data(dev);
	unsigned int otp = 0U, bank = 0U;
	//uint32_t exceptions = 0U;
	uint32_t srlock[_OTP_ACCESS_SIZE] = { 0U };
	uint32_t swlock[_OTP_ACCESS_SIZE] = { 0U };
	uint32_t splock[_OTP_ACCESS_SIZE] = { 0U };
	uint32_t mask = 0U;
	unsigned int max_id = drv_data->variant->max_id;

	memset(drv_data->p_mirror, 0, sizeof(*drv_data->p_mirror));
	drv_data->p_mirror->magic = BSEC_MAGIC;
	drv_data->p_mirror->state = BSEC_STATE_INVALID;

	/* HIDEUP: read and write not possible in upper region */
	if (status & _BSEC_OTPSR_HIDEUP) {
		for (otp = STM32MP2_UPPER_BASE;
		     otp <= drv_data->variant->max_id ; otp++) {
			drv_data->p_mirror->otp[otp].status |= _HIDEUP_ERROR;
			drv_data->p_mirror->otp[otp].value = 0x0U;
		}
		max_id = STM32MP2_UPPER_BASE - 1;
	}

	for (bank = 0U; bank < _OTP_ACCESS_SIZE; bank++) {
		srlock[bank] = io_read32(drv_cfg->base + _BSEC_SRLOCK(bank));
		swlock[bank] = io_read32(drv_cfg->base + _BSEC_SWLOCK(bank));
		splock[bank] = io_read32(drv_cfg->base + _BSEC_SPLOCK(bank));
	}

	for (otp = 0U; otp <= max_id ; otp++) {
		int ret;

		bank = _FLD_GET(_BSEC_OTP_BANK, otp);
		mask = BIT(_FLD_GET(_BSEC_OTP_BIT, otp));

		if (srlock[bank] & mask)
			drv_data->p_mirror->otp[otp].status |= LOCK_SHADOW_R;
		if (swlock[bank] & mask)
			drv_data->p_mirror->otp[otp].status |= LOCK_SHADOW_W;
		if (splock[bank] & mask)
			drv_data->p_mirror->otp[otp].status |= LOCK_SHADOW_P;

		if (drv_data->p_mirror->otp[otp].status & STATUS_SECURE)
			continue;

		/*
		 * OEM keys are accessible only in ROM code
		 * They are stored in last OTPs
		 */
		if (otp >= drv_data->variant->oem_key_first_otp) {
			drv_data->p_mirror->otp[otp].status |= LOCK_SHADOW_R;
			continue;
		}

		if (!(drv_data->p_mirror->otp[otp].status & LOCK_SHADOW_R)) {
			/* reload shadow to read Permanent Programing Lock Flag */

			ret = shadow_otp(dev, otp);
			if (ret) {
				EMSG("Shadowing failed (%d)\n", ret);
				return;
			}
		}

		drv_data->p_mirror->otp[otp].value = io_read32(drv_cfg->base +
							   _BSEC_FVR(otp));
	}

}

static void stm32_bsec_mirror_init(const struct device *dev, bool force_load)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	struct stm32_bsec_data *drv_data = dev_get_data(dev);
	struct bsec_mirror *mirror = drv_data->p_mirror;
	uint32_t status;

	status = io_read32(drv_cfg->base + _BSEC_OTPSR);
	stm32_bsec_check_error(status);

	/* update mirror when forced or invalid */
	if (force_load || mirror->magic != BSEC_MAGIC)
		stm32_bsec_mirror_load(dev, status);

	/* always update status */
	mirror->state = init_state(dev, status);
	if ((mirror->state & BSEC_STATE_MASK) == BSEC_STATE_INVALID) {
		EMSG("BSEC invalid state\n");
		panic();
	}
}

static int stm32_bsec_shadow_init(const struct device *dev)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	const struct nvmem_cell *cell = NULL;
	uint32_t otp_val;
	bool sw_lock;
	int i, j, ret;

	for (i = 0; i < drv_cfg->n_otp_cell; i++) {
		cell = &drv_cfg->otp_cell[i];

		if (cell->n_shadow_value == 0)
			continue;

		/*
		 * The shadow_value array must have a value for all
		 * the OTP of the section.
		 */
		if (cell->n_shadow_value != cell->n_otp) {
			EMSG("size of shadow-provisionning not equal to size of"
			     " reg for node otp : %d\n",
			     cell->otp_id);
			return -EINVAL;
		}

		for (j = 0; j < cell->n_otp; j++) {

			/* no shadow value to provision, skip OTP */
			if (cell->shadow_value[j] == 0)
				continue;

			/* ensure shadow write is allowed */
			ret = stm32_bsec_read_sw_lock(cell->otp_id + j,
						      &sw_lock);
			if (ret)
				return ret;

			if (sw_lock)
				return -EACCES;

			ret = stm32_bsec_read_otp(&otp_val, cell->otp_id + j);
			if (ret)
				return ret;

			otp_val |= cell->shadow_value[j];
			stm32_bsec_write(cell->otp_id + j, otp_val);

			/* update bsec mirror */
			ret = _otp_write(cell->otp_id, cell->n_otp * sizeof(uint32_t),
					 cell->n_shadow_value * sizeof(uint32_t),
					 (uint8_t *)&otp_val);
			if (ret)
				return ret;
		}
	}

	return 0;
}

static int stm32_bsec_dt_init(const struct device *dev)
{
	const struct stm32_bsec_config *drv_cfg = dev_get_config(dev);
	struct stm32_bsec_data *drv_data = dev_get_data(dev);

	drv_data->hw_key_valid = false;

	if (IS_ENABLED(STM32_BL2)) {
		drv_data->hw_key_valid = !!(io_read32(drv_cfg->base + _BSEC_SR) &
					    _BSEC_SR_HVALID_MASK);
		drv_data->p_mirror = NULL;
	} else {
		drv_data->p_mirror = (struct bsec_mirror *)drv_cfg->mirror_addr;

		if (IS_ENABLED(STM32_M33TDCID))
			stm32_bsec_mirror_init(dev, true);

		if (drv_data->p_mirror->magic != BSEC_MAGIC)
			return -ENOSYS;

		if (drv_data->p_mirror->state & BSEC_HARDWARE_KEY)
			drv_data->hw_key_valid = true;
	}

	if (IS_ENABLED(STM32_M33TDCID)) {
		drv_data->verr = io_read32(drv_cfg->base + _BSEC_VERR);
		drv_data->dbgacr = BSEC_DBGxCR_NOT_SET;
	}

	return stm32_bsec_shadow_init(dev);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_bsec_pm_action(const struct device *dev,
				enum pm_device_action action, uint32_t pm_hint)
{
	if ((PM_HINT_IS_STATE(pm_hint, CONTEXT)) &&
	    (action == PM_DEVICE_ACTION_RESUME)) {
		stm32_bsec_mirror_init(dev, true);
		return stm32_bsec_shadow_init(dev);
	}

	return 0;
}
#endif

static const struct nvmem_driver_api __maybe_unused stm32_bsec_nvmem_api = {
	.get_cell_size = stm32_bsec_nvmem_get_cell_size,
	.read_cell = stm32_bsec_nvmem_read_cell,
	.write_cell = stm32_bsec_nvmem_write_cell,
};

#define NVMEM_CELL_CHILD_DEFINE(node_id)					\
static const uint32_t shadow_value_##node_id[] =				\
	DT_PROP_OR(node_id, shadow_provisionning, {});				\
										\
static const char * const stm32_otp_label_##node_id[] =				\
	DT_NODELABEL_STRING_ARRAY(node_id);					\
										\
static const struct nvmem_cell stm32_otp_cell_##node_id = {			\
	.cell_label = stm32_otp_label_##node_id[0],				\
	.otp_id = (DT_REG_ADDR(node_id) / 4),					\
	.n_otp = (DT_REG_SIZE(node_id) / 4),					\
	.shadow_value = shadow_value_##node_id,					\
	.n_shadow_value = DT_PROP_LEN_OR(node_id, shadow_provisionning, 0)	\
};										\
										\
DEVICE_DT_DEFINE(node_id, NULL, NULL,						\
		 NULL,								\
		 &stm32_otp_cell_##node_id,					\
		 CORE, 6,							\
		 &stm32_bsec_nvmem_api);


#define NVMEM_CELL_CHILD_GET(node_id) stm32_otp_cell_##node_id,

#define BSEC_MIRROR_ADDR_OR(n_id)						\
	COND_CODE_1(DT_NODE_HAS_PROP(n_id, memory_region),			\
		    (DT_REG_ADDR(DT_PHANDLE(n_id, memory_region))), (0U))

#define BSEC_MIRROR_SIZE_OR(n_id)						\
	COND_CODE_1(DT_NODE_HAS_PROP(n_id, memory_region),			\
		    (DT_REG_SIZE(DT_PHANDLE(n_id, memory_region))), (0U))

#define STM32_BSEC3_INIT(node_id, _variant)					\
										\
DT_FOREACH_CHILD(node_id, NVMEM_CELL_CHILD_DEFINE)				\
										\
static const struct nvmem_cell stm32_otp_cells_##node_id [] = {			\
	DT_FOREACH_CHILD(node_id, NVMEM_CELL_CHILD_GET)				\
};										\
										\
DT_ACCESS_CTRLS_DEFINE(node_id);						\
										\
static const struct stm32_bsec_config stm32_bsec3_cfg_ ## node_id = {		\
	.base = DT_REG_ADDR(node_id),						\
	.mirror_addr = BSEC_MIRROR_ADDR_OR(node_id),				\
	.mirror_size = BSEC_MIRROR_SIZE_OR(node_id),				\
	.firewall_ctrls = DT_ACCESS_CTRLS_GET(node_id),				\
	.n_firewall_ctrls = DT_ACCESS_CTRLS_NUM(node_id),			\
	.otp_cell = stm32_otp_cells_##node_id,					\
	.n_otp_cell = ARRAY_SIZE(stm32_otp_cells_##node_id),			\
};										\
										\
static struct stm32_bsec_data stm32_bsec3_data_ ## node_id = {			\
	.variant = _variant,							\
};										\
										\
static const struct device *bsec_dev = DEVICE_DT_INST_GET(0);			\
										\
PM_DEVICE_DT_DEFINE(node_id, stm32_bsec_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_DEFINE(node_id, &stm32_bsec_dt_init, PM_DEVICE_DT_GET(node_id),	\
		 &stm32_bsec3_data_##node_id,					\
		 &stm32_bsec3_cfg_##node_id,					\
		 CORE, 5,							\
		 NULL);



static __unused struct stm32_bsec_variant variant_stm32mp21 = {
/*
 * BSEC: 364 available OTPs, the other are masked
 * - OEM FSBL keys 348 to 363 (programmable but not readable)
 * - ECIES key: 364 to 375 (only readable by bootrom)
 * - HWKEY: 376 to 383 (never reloadable or readable)
 */
	.oem_key_first_otp = 348,
	.max_id = STM32MP2_OTP_MAX_ID,
	.denr_all_mask = GENMASK(17, 0),
	.denr_key = 0xdeb00000,
	.has_hdpl = true,
};

static __unused struct stm32_bsec_variant variant_stm32mp25 = {
/*
 * BSEC: 368 available OTPs, the other are masked
 * - OEM FSBL keys 360 to 367 (programmable but not readable)
 * - ECIES key: 368 to 375 (only readable by bootrom)
 * - HWKEY: 376 to 383 (never reloadable or readable)
 */
	.oem_key_first_otp = 360,
	.max_id = STM32MP2_OTP_MAX_ID,
	.denr_all_mask = GENMASK(15, 0),
	.denr_key = 0xdeb60000,
	.has_hdpl = false,
};

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT		st_stm32mp21_bsec

DT_FOREACH_STATUS_OKAY_VARGS(st_stm32mp21_bsec, STM32_BSEC3_INIT,
			     &variant_stm32mp21)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT		st_stm32mp25_bsec

DT_FOREACH_STATUS_OKAY_VARGS(st_stm32mp25_bsec, STM32_BSEC3_INIT,
			     &variant_stm32mp25)

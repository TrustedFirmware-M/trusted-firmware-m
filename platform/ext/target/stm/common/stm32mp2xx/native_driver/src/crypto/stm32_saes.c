/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <clk.h>
#include <debug.h>
#include <device.h>
#include <errno.h>
#include <firewall.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <reset.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/endian.h>

#include <lib/delay.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/timeout.h>
#include <sk_cipher.h>

#if defined(STM32MP21xxxx)
#include <dt-bindings/saes/stm32mp21-saes.h>
#else
#include <dt-bindings/saes/stm32mp25-saes.h>
#endif

#define SHIFT_U32(v, shift)		((uint32_t)(v) << (shift))
#define IS_ALIGNED_WITH_TYPE(x, t)	((uintptr_t)x % __alignof__(t) == 0)
#define IS_ALIGNED_U32(x)		IS_ALIGNED_WITH_TYPE(x, uint32_t)

#define SAES_TIMEOUT_US			U(100000)
#define SAES_RESET_DELAY_US		U(20)
#define SAES_SUSPSIZE			U(8)

#define IS_CHAINING_MODE(mode, cr) \
	!!((cr & _SAES_CR_CHMOD_MASK) == _FLD_PREP(_SAES_CR_CHMOD, _SAES_CR_CHMOD_##mode))

#define SET_CHAINING_MODE(mode) \
	(_FLD_PREP(_SAES_CR_CHMOD, _SAES_CR_CHMOD_##mode))

struct stm32_saes_context {
	uintptr_t base;
	uint32_t cr;
	uint32_t assoc_len;
	uint32_t load_len;
	uint32_t key[8]; /* In HW byte order */
	uint32_t iv[4];  /* In HW byte order */
	uint32_t susp[8];
	uint32_t extra[4];
	size_t extra_size;
};

struct clock_control {
	const struct device *dev;
	const clk_subsys_t subsys;
};

struct stm32_saes_config {
	uintptr_t base;
	const struct clock_control *clk_ctl;
	int n_clk;
	const struct reset_control rst_ctl;
	const struct firewall_spec *firewall;
	const int n_firewall;
	/* uint32_t caps;  TODO? */
};

struct stm32_saes_variant {
	bool support_192_bit_key;
};

struct stm32_saes_data {
	const struct stm32_saes_variant *variant;
	struct stm32_saes_context ctx;
};

static bool does_chaining_mode_need_iv(uint32_t cr)
{
	return !IS_CHAINING_MODE(ECB, cr);
}

static bool is_encrypt(uint32_t cr)
{
	return !!(cr & _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_ENC));
}

static bool is_decrypt(uint32_t cr)
{
	return !!(cr & _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_DEC));
}

static bool can_suspend(uint32_t cr)
{
	return !IS_CHAINING_MODE(GCM, cr);
}

static int stm32_saes_set_clock(const struct stm32_saes_config *drv_cfg, bool enable)
{
	const struct clock_control *clock_ctl;
	struct clk *clk;
	int err, i;

	for (i = 0, clock_ctl = drv_cfg->clk_ctl; i < drv_cfg->n_clk; i++, clock_ctl++) {
		clk = clk_get(clock_ctl->dev, clock_ctl->subsys);
		if (clk) {
			if (enable) {
				err = clk_enable(clk);

			} else {
				clk_disable(clk);
				err = 0;
			}

			if (err) {
				EMSG("%s: clock[%d] enable fail\n", __func__, i);
				return err;
			}
		} else {
			WMSG("%s: get clock[%d] fail\n", __func__, i);
		}
	}

	return 0;
}

static void write_aligned_block(uintptr_t base, uint32_t *data)
{
	unsigned int i = 0;

	/* SAES must be configured to swap bytes as expected */
	for (i = 0; i < AES_BLOCK_NB_U32; i++)
		io_write32(base + _SAES_DINR, data[i]);
}

static void write_block(uintptr_t base, uint8_t *data)
{
	if (IS_ALIGNED_U32(data)) {
		write_aligned_block(base, (void *)data);
	} else {
		uint32_t data_u32[AES_BLOCK_NB_U32] = { };

		memcpy(data_u32, data, sizeof(data_u32));
		write_aligned_block(base, data_u32);
	}
}

static void read_aligned_block(uintptr_t base, uint32_t *data)
{
	unsigned int i = 0;

	/* SAES must be configured to swap bytes as expected */
	for (i = 0; i < AES_BLOCK_NB_U32; i++)
		data[i] = io_read32(base + _SAES_DOUTR);
}

static void read_block(uintptr_t base, uint8_t *data)
{
	if (IS_ALIGNED_U32(data)) {
		read_aligned_block(base, (void *)data);
	} else {
		uint32_t data_u32[AES_BLOCK_NB_U32] = { };

		read_aligned_block(base, data_u32);

		memcpy(data, data_u32, sizeof(data_u32));
	}
}

static int wait_computation_completed(uintptr_t base)
{
	uint32_t isr;
	int err;

	err = mmio_read32_poll_timeout((base + _SAES_ISR), isr, (isr & _SAES_I_CCF),
				       SAES_TIMEOUT_US);

	if (err)
		EMSG("%s: Computation Complete timeout, ISR: %x\n", __func__, isr);

	return err;
}

static void clear_computation_completed(uintptr_t base)
{
	io_setbits32(base + _SAES_ICR, _SAES_I_CCF);
}

static int wait_key_valid(uintptr_t base)
{
	uint32_t sr;
	int err;

	err = mmio_read32_poll_timeout((base + _SAES_SR), sr, (sr & _SAES_SR_KEYVALID),
				       SAES_TIMEOUT_US);

	if (err)
		EMSG("%s: Key valid timeout, SR: %x\n", __func__, sr);

	return err;
}

static int wait_for_not_busy(uintptr_t base)
{
	uint32_t sr;
	int err;

	err = mmio_read32_poll_timeout((base + _SAES_SR), sr, !(sr & _SAES_SR_BUSY),
				       SAES_TIMEOUT_US);

	if (err)
		EMSG("%s: timeout, SR: %x\n", __func__, sr);

	return err;
}

static int stm32_saes_acquire_sem(const struct stm32_saes_config *drv_cfg)
{
	struct firewall_spec *firewall;
	int err, i;

	err = acquire_sem_for_each_firewall(drv_cfg->firewall, firewall, drv_cfg->n_firewall, i);
	if (err)
		ERROR("%s: could not acquire firewall access.\n", __func__);

	return err;
}

static void stm32_saes_release_sem(const struct stm32_saes_config *drv_cfg)
{
	struct firewall_spec *firewall;
	int err, i;

	err = release_sem_for_each_firewall(drv_cfg->firewall, firewall, drv_cfg->n_firewall, i);
	if (err)
		ERROR("%s: could not release firewall access.\n", __func__);
}

static int saes_start(const struct device *dev)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;
	struct clk *clk;
	int err;

	err = stm32_saes_acquire_sem(drv_cfg);
	if (err)
		return err;

	/* Enable driver clock if needed before usage */
	clk = clk_get(drv_cfg->clk_ctl->dev, drv_cfg->clk_ctl->subsys);
	if (!clk_is_enabled(clk))
		stm32_saes_set_clock(drv_cfg, true);

	/* Reset SAES */
	if (!(io_read32(ctx->base + _SAES_SR) & _SAES_SR_BUSY)) {
		io_setbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);
		udelay(SAES_RESET_DELAY_US);
		io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);
	}

	return wait_for_not_busy(ctx->base);
}

static void saes_end(const struct device *dev, int prev_error)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;

	if (prev_error) {
		/* Reset SAES */
		io_setbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);
		udelay(SAES_RESET_DELAY_US);
		io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);
	}

	/* Disable the SAES peripheral */
	io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	stm32_saes_release_sem(drv_cfg);
}

static void saes_write_iv(struct stm32_saes_context *ctx)
{
	/* If chaining mode need to restore IV */
	if (does_chaining_mode_need_iv(ctx->cr)) {
		unsigned int i = 0;

		for (i = 0; i < AES_IVSIZE / sizeof(uint32_t); i++)
			io_write32(ctx->base + _SAES_IVR0 + i * sizeof(uint32_t), ctx->iv[i]);
	}
}

static void saes_save_suspend(struct stm32_saes_context *ctx)
{
	size_t i = 0;

	for (i = 0; i < SAES_SUSPSIZE; i++)
		ctx->susp[i] = io_read32(ctx->base + _SAES_SUSPR0 + i * sizeof(uint32_t));
}

static void saes_restore_suspend(struct stm32_saes_context *ctx)
{
	size_t i = 0;

	for (i = 0; i < SAES_SUSPSIZE; i++)
		io_write32(ctx->base + _SAES_SUSPR0 + i * sizeof(uint32_t),
			   ctx->susp[i]);
}


static uint32_t saes_get_keysize(struct stm32_saes_context *ctx)
{
	int keysize;
	uint32_t ret = 0;

	keysize = _FLD_GET(_SAES_CR_KEYSIZE, ctx->cr);

	switch (keysize) {
	case _SAES_CR_KEYSIZE_256:
		ret =  AES_KEYSIZE_256;
		break;
	case _SAES_CR_KEYSIZE_192:
		ret = AES_KEYSIZE_192;
		break;
	case _SAES_CR_KEYSIZE_128:
		ret = AES_KEYSIZE_128;
		break;
	default:
		EMSG("Invalid keysize.\n");
		break;
	}

	return ret;
}

static int saes_write_key(struct stm32_saes_context *ctx)
{
	/* Restore the _SAES_KEYRx if SOFTWARE key */
	if (_FLD_GET(_SAES_CR_KEYSEL, ctx->cr) == _SAES_CR_KEYSEL_SOFT) {
		size_t i = 0;
		uint32_t ks = 0;

		ks = saes_get_keysize(ctx);
		if (!ks)
			return -EPERM;

		for (i = 0; i < AES_KEYSIZE_128 / sizeof(uint32_t); i++)
			io_write32(ctx->base + _SAES_KEYR0 + i * sizeof(uint32_t), ctx->key[i]);

		if (ks > AES_KEYSIZE_128) {
			ks -= AES_KEYSIZE_128; /* writes only remaining bytes */
			for (i = 0; i < ks / sizeof(uint32_t); i++) {
				io_write32(ctx->base + _SAES_KEYR4 + i * sizeof(uint32_t),
					   ctx->key[i + 4]);
			}
		}
	}

	return 0;
}

static int saes_prepare_key(struct stm32_saes_context *ctx)
{
	int res;

	/* Disable the SAES peripheral */
	io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	res = saes_write_key(ctx);
	if (res)
		return res;

	res = wait_key_valid(ctx->base);
	if (res)
		return res;

	if (!is_decrypt(ctx->cr))
		return 0;

	/*
	 * For ECB/CBC decryption, key preparation mode must be selected
	 * to populate the key.
	 */
	if ((IS_CHAINING_MODE(ECB, ctx->cr) || IS_CHAINING_MODE(CBC, ctx->cr))) {
		/* Select Mode 2 */
		io_clrsetbits32(ctx->base + _SAES_CR, _SAES_CR_MODE_MASK,
				SHIFT_U32(_SAES_CR_MODE_KEYPREP, _SAES_CR_MODE_SHIFT));

		/* Enable SAES */
		io_setbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

		res = wait_computation_completed(ctx->base);
		if (res)
			return res;

		clear_computation_completed(ctx->base);

		/* Set Mode 3 */
		io_clrsetbits32(ctx->base + _SAES_CR, _SAES_CR_MODE_MASK,
				SHIFT_U32(_SAES_CR_MODE_DEC, _SAES_CR_MODE_SHIFT));
	}

	return 0;
}

static int save_context(struct stm32_saes_context *ctx)
{
	if ((io_read32(ctx->base + _SAES_ISR) & _SAES_I_CCF)) {
		/* Device should not be in a processing phase */
		return -EPERM;
	}

	/* Save CR */
	ctx->cr = io_read32(ctx->base + _SAES_CR);

	if (!can_suspend(ctx->cr))
		return 0;

	saes_save_suspend(ctx);

	/* If chaining mode need to save current IV */
	if (does_chaining_mode_need_iv(ctx->cr)) {
		uint8_t i = 0;

		/* Save IV */
		for (i = 0; i < AES_IVSIZE / sizeof(uint32_t); i++)
			ctx->iv[i] = io_read32(ctx->base + _SAES_IVR0 + i * sizeof(uint32_t));
	}

	/* Disable the SAES peripheral */
	io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	return 0;
}

/* To resume the processing of a message */
static int restore_context(struct stm32_saes_context *ctx)
{
	int res = 0;

	/* SAES shall be disabled */
	if ((io_read32(ctx->base + _SAES_CR) & _SAES_CR_EN)) {
		DMSG("Device is still enabled\n");
		return -EPERM;
	}

	/* Reset internal state */
	io_setbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);

	/* Restore configuration register */
	io_write32(ctx->base + _SAES_CR, ctx->cr);

	/* Write key and, in case of CBC or ECB decrypt, prepare it */
	res = saes_prepare_key(ctx);
	if (res)
		return res;

	saes_restore_suspend(ctx);

	saes_write_iv(ctx);

	/* Enable the SAES peripheral */
	io_setbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	return 0;
}

/**
 * @brief Update (or start) an AES de/encrypt process (ECB, CBC or CTR).
 * @param dev: SAES device
 * @param last_block: true if last payload data block
 * @param data_in: pointer to payload
 * @param data_out: pointer where to save de/encrypted payload
 * @param data_size: payload size
 *
 * @retval 0 if OK.
 */
int stm32_saes_update(const struct device *dev, bool last_block,
				   uint8_t *data_in, uint8_t *data_out,
				   size_t data_size)
{
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;
	int res = 0;
	unsigned int i = U(0);

	/* test if init was done */
	if (!ctx)
		return -EINVAL;

	if ((!last_block) && (round_down(data_size, AES_BLOCK_SIZE) != data_size)) {
		EMSG("%s: non last block must be multiple of 128 bits\n", __func__);
		res = -EINVAL;
		goto out;
	}

	/*
	 * CBC encryption requires the 2 last blocks to be aligned with AES
	 * block size.
	 */
	if (last_block && IS_CHAINING_MODE(CBC, ctx->cr) && is_encrypt(ctx->cr) &&
	    (round_down(data_size, AES_BLOCK_SIZE) != data_size)) {
		if (data_size < AES_BLOCK_SIZE * 2) {
			/*
			 * If CBC, size of the last part should be at
			 * least 2*AES_BLOCK_SIZE
			 */
			EMSG("Unexpected last block size.\n");
			res = -EINVAL;
			goto out;
		}
		/*
		 * Do not support padding if the total size is not aligned with
		 * the size of a block.
		 */
		res = -EPERM;
		goto out;
	}

	/* Manage remaining CTR mask from previous update call */
	if (IS_CHAINING_MODE(CTR, ctx->cr) && ctx->extra_size) {
		uint8_t *mask = (uint8_t *)ctx->extra;

		for (i = 0; i < ctx->extra_size && i < data_size; i++)
			data_out[i] = data_in[i] ^ mask[i];

		if (i != ctx->extra_size) {
			/*
			 * We didn't consume all saved mask,
			 * but no more data.
			 */

			/* We save remaining mask and its new size */
			memmove(ctx->extra, ctx->extra + i, ctx->extra_size - i);
			ctx->extra_size -= i;

			/*
			 * We don't need to save HW context we didn't
			 * modify HW state.
			 */
			res = 0;
			goto out;
		}
		/* All extra mask consumed */
		ctx->extra_size = 0;
	}

	res = restore_context(ctx);
	if (res)
		goto out;

	while (data_size - i >= AES_BLOCK_SIZE) {
		write_block(ctx->base, data_in + i);

		res = wait_computation_completed(ctx->base);
		if (res)
			goto out;

		read_block(ctx->base, data_out + i);

		clear_computation_completed(ctx->base);

		/* Process next block */
		i += AES_BLOCK_SIZE;
	}

	/* Manage last block if not a block size multiple */
	if (i < data_size) {
		if (IS_CHAINING_MODE(CTR, ctx->cr)) {
			/*
			 * For CTR we save the generated mask to use it at next
			 * update call.
			 */
			uint32_t block_in[AES_BLOCK_NB_U32] = { };
			uint32_t block_out[AES_BLOCK_NB_U32] = { };

			memcpy(block_in, data_in + i, data_size - i);

			write_aligned_block(ctx->base, block_in);

			res = wait_computation_completed(ctx->base);
			if (res)
				goto out;

			read_aligned_block(ctx->base, block_out);

			clear_computation_completed(ctx->base);

			memcpy(data_out + i, block_out, data_size - i);

			/* Save mask for possibly next call */
			ctx->extra_size = AES_BLOCK_SIZE - (data_size - i);
			memcpy(ctx->extra, (uint8_t *)block_out + data_size - i, ctx->extra_size);
		} else {
			/* CBC and ECB can manage only multiple of block_size */
			res = -EINVAL;
			goto out;
		}
	}

	if (!last_block)
		res = save_context(ctx);

out:
	/* If last block or error, end of SAES process */
	if (last_block || res)
		saes_end(dev, res);

	return res;
}

static int stm32_saes_wrap_init(const struct device *dev, bool wrap, int share_id)
{
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;

	/* force usage of DHUK for wrapping process */
	ctx->cr &= ~(_SAES_CR_KEYSEL_MASK);
	ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_DHUK);

	/* force datatype to NONE, mandatory for wrapping. */
	ctx->cr &= ~(_SAES_CR_DATATYPE_MASK);
	ctx->cr |= _FLD_PREP(_SAES_CR_DATATYPE, _SAES_CR_DATATYPE_NONE);

	switch (share_id)
	{
	case 0: /* No key sharing */
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYMOD, _SAES_CR_KEYMOD_WRAPPED);
		break;
	case 1: /* CRYP1 peripheral key sharing */
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYMOD, _SAES_CR_KEYMOD_SHARED);
		ctx->cr |= _FLD_PREP(_SAES_CR_KSHAREID, _SAES_CR_KSHAREID_CRYP1);
		break;
	case 2: /* CRYP2 peripheral key sharing */
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYMOD, _SAES_CR_KEYMOD_SHARED);
		ctx->cr |= _FLD_PREP(_SAES_CR_KSHAREID, _SAES_CR_KSHAREID_CRYP2);
		break;
	default:
		return -ENODEV;
	}

	ctx->cr &= ~(_SAES_CR_MODE_MASK);

	if (wrap) {
		ctx->cr |= _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_ENC);
	} else {
		ctx->cr |= _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_KEYPREP);
	}

	return 0;
}

/**
 * @brief Wraps or unwraps a secret key using ECB or CBC mode, with optional
 * hardware key sharing support. More info in sk_cipher.h
 *
 * When key sharing is set the key is available to the shared peripheral until
 * SAES is initialized again.
 *
 * @param dev Pointer to the cipher device instance.
 * @param wrap True to wrap a key, false to unwrap.
 * @param share_id Optional ID to enable hardware key sharing with a peripheral.
 * @param data_in Input key data (cleartext for wrap, wrapped for unwrap).
 * @param data_out Output buffer for wrapped key (used only when wrapping).
 *
 * @return 0 on success, or an error code on failure.
 */
int stm32_saes_wrap(const struct device *dev, bool wrap, int share_id,
				 uint8_t *key_in, uint8_t *key_out)
{
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;
	int res = 0;
	size_t key_size;
	uint32_t i = U(0);

	/* Only ECB and CBC are available */
	if (!IS_CHAINING_MODE(ECB, ctx->cr) && !IS_CHAINING_MODE(CBC, ctx->cr))
		return -EPERM;

	/* Key size must be set with a ctx init, 192 bit unsupported yet. */
	key_size = saes_get_keysize(ctx);
	if (key_size != AES_KEYSIZE_128 && key_size != AES_KEYSIZE_256)
		return -EINVAL;

	res = stm32_saes_wrap_init(dev, wrap, share_id);
	if(res)
		return res;

	/* Disable the SAES peripheral */
	io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	if (wait_for_not_busy(ctx->base))
		goto out;

	io_setbits32(ctx->base + _SAES_CR, ctx->cr);

	/* TODO: CBC: IV could be set here in wrap mode */

	if (wait_key_valid(ctx->base))
		goto out;

	if (!wrap) {
		/* unwrap specific process */
		io_setbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

		res = wait_computation_completed(ctx->base);
		if (res)
			goto out;

		/* SAES is automatically disabled here */
		clear_computation_completed(ctx->base);

		io_clrsetbits32(ctx->base + _SAES_CR, _SAES_CR_MODE_MASK,
				_FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_DEC));

		/* TODO: CBC: IV could be set here in unwrap mode */

	}

	/* TODO: CBC: not in refman but load IV at this moment could work... */

	/* Activate SAES. */
	io_setbits32(ctx->base + _SAES_CR, _SAES_CR_EN);

	/* key_size is always one or two block size */
	while (key_size - i >= AES_BLOCK_SIZE) {
		write_block(ctx->base, key_in + i);

		res = wait_computation_completed(ctx->base);
		if (res)
			goto out;

		/* Never read DOUTR when unwraping, this causes an error */
		if (wrap)
			read_block(ctx->base, key_out + i);

		clear_computation_completed(ctx->base);

		/* Process next block */
		i += AES_BLOCK_SIZE;
	}

out:
	saes_end(dev, res);
	return res;
}

/**
 * @brief Start an AES computation.
 * @param dev: SAES device
 * @param config: SAES configuration, see sk_cipher_config_t
 * @note this function doesn't access to hardware but stores in ctx the values
 *
 * @retval 0 if OK or a errno code.
 */
int stm32_saes_ctx_init(const struct device *dev, struct sk_cipher_config_t *config)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;
	const uint32_t *key_u32 = NULL;
	const uint32_t *iv_u32 = NULL;
	uint32_t local_key[8] = { };
	uint32_t local_iv[4] = { };
	unsigned int i = 0;

	if (!ctx)
		return -EINVAL;

	/* Check Peripheral capabilities */
	if (!drv_dat->variant->support_192_bit_key) {
		if (config->key_size == AES_KEYSIZE_192)
			return -EINVAL;
	}

	*ctx = (struct stm32_saes_context){
		.base = drv_cfg->base,
		.cr = _SAES_CR_RESET_VALUE
	};

	/* We want buffer to be u32 aligned */
	if (IS_ALIGNED_U32(config->key)) {
		key_u32 = config->key;
	} else {
		memcpy(local_key, config->key, config->key_size);
		key_u32 = local_key;
	}

	if (IS_ALIGNED_U32(config->iv)) {
		iv_u32 = config->iv;
	} else {
		memcpy(local_iv, config->iv, config->iv_size);
		iv_u32 = local_iv;
	}

	if (config->is_dec)
		ctx->cr |= _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_DEC);
	else
		ctx->cr |= _FLD_PREP(_SAES_CR_MODE, _SAES_CR_MODE_ENC);

	/* Save chaining mode */
	switch (config->ch_mode) {
	case SK_CIPHER_MODE_ECB:
		ctx->cr |= SET_CHAINING_MODE(ECB);
		break;
	case SK_CIPHER_MODE_CBC:
		ctx->cr |= SET_CHAINING_MODE(CBC);
		break;
	case SK_CIPHER_MODE_CTR:
		ctx->cr |= SET_CHAINING_MODE(CTR);
		break;
	case SK_CIPHER_MODE_GCM:
		ctx->cr |= SET_CHAINING_MODE(GCM);
		break;
	case SK_CIPHER_MODE_CCM:
		ctx->cr |= SET_CHAINING_MODE(CCM);
		break;
	default:
		EMSG("Unsupported chaining mode.\n");
		return -EINVAL;
	}

	/*
	 * Use HW Byte swap _SAES_CR_DATATYPE_BYTE for data.
	 * _SAES_CR_DATATYPE_NONE if no swap needed
	 *
	 * Note that wrap key only accept _SAES_CR_DATATYPE_NONE.
	 */
	ctx->cr |= _FLD_PREP(_SAES_CR_DATATYPE, _SAES_CR_DATATYPE_BYTE);

	/* Configure keysize */
	switch (config->key_size) {
	case AES_KEYSIZE_128:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSIZE, _SAES_CR_KEYSIZE_128);
		break;
	case AES_KEYSIZE_192:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSIZE, _SAES_CR_KEYSIZE_192);
		break;
	case AES_KEYSIZE_256:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSIZE, _SAES_CR_KEYSIZE_256);
		break;
	default:
		EMSG("Unsupported key size.\n");
		return -EINVAL;
	}

	/* Configure key */
	switch (config->key_select) {
	case SK_CIPHER_KEY_SOFT:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_SOFT);
		/* Save key */
		switch (config->key_size) {
		case AES_KEYSIZE_128:
			/* First 16 bytes == 4 u32 */
			for (i = 0; i < AES_KEYSIZE_128 / sizeof(uint32_t); i++) {
				ctx->key[i] = htobe32(key_u32[3 - i]);
				/*
				 * /!\ we save the key in HW byte order
				 * and word order: key[i] is for _SAES_KEYRi.
				 */
			}
			break;
		case AES_KEYSIZE_192:
			for (i = 0; i < AES_KEYSIZE_192 / sizeof(uint32_t); i++) {
				ctx->key[i] = htobe32(key_u32[5 - i]);
				/*
				 * /!\ we save the key in HW byte order
				 * and word order: key[i] is for _SAES_KEYRi.
				 */
			}
			break;
		case AES_KEYSIZE_256:
			for (i = 0; i < AES_KEYSIZE_256 / sizeof(uint32_t); i++) {
				ctx->key[i] = htobe32(key_u32[7 - i]);
				/*
				 * /!\ we save the key in HW byte order
				 * and word order: key[i] is for _SAES_KEYRi.
				 */
			}
			break;
		default:
			return -EINVAL;
		}
		break;
	case STM32_SAES_KEY_DHU:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_DHUK);
		break;
	case STM32_SAES_KEY_BH:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_BHK);
		break;
	case STM32_SAES_KEY_BHU_XOR_BH:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_BHU_XOR_BH_K);
		break;
	case STM32_SAES_KEY_WRAPPED:
		ctx->cr |= _FLD_PREP(_SAES_CR_KEYSEL, _SAES_CR_KEYSEL_SOFT);
		break;

	default:
		EMSG("Unsupported key type.\n");
		return -EINVAL;
	}

	/* Save IV */
	if (config->ch_mode != SK_CIPHER_MODE_ECB) {
		if (!config->iv || config->iv_size != AES_IVSIZE)
			return -EINVAL;

		for (i = 0; i < AES_IVSIZE / sizeof(uint32_t); i++)
			/* /!\ We save the iv in HW byte order */
			ctx->iv[i] = htobe32(iv_u32[3 - i]);
	}

	/* Reset suspend registers */
	memset(ctx->susp, 0, sizeof(ctx->susp));

	return saes_start(dev);
}

int stm32_saes_reset(const struct device *dev)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	struct stm32_saes_data *drv_dat = dev_get_data(dev);
	struct stm32_saes_context *ctx = &drv_dat->ctx;
	struct clk *clk;
	int err;

	err = stm32_saes_acquire_sem(drv_cfg);
	if (err)
		return err;

	clk = clk_get(drv_cfg->clk_ctl->dev, drv_cfg->clk_ctl->subsys);
	if (!clk_is_enabled(clk))
		goto release;

	/* Reset SAES */
	io_setbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);
	udelay(SAES_RESET_DELAY_US);
	io_clrbits32(ctx->base + _SAES_CR, _SAES_CR_IPRST);

	(void)stm32_saes_set_clock(drv_cfg, false);

release:
	stm32_saes_release_sem(drv_cfg);

	return 0;
}

static int __maybe_unused stm32_saes_probe(const struct device *dev)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	int err;

	err = stm32_saes_acquire_sem(drv_cfg);
	if (err)
		return err;

	err = stm32_saes_set_clock(drv_cfg, true);
	if (err)
		goto end;

	err = reset_control_reset(&drv_cfg->rst_ctl);

	(void)stm32_saes_set_clock(drv_cfg, false);
end:
	stm32_saes_release_sem(drv_cfg);

	return err;
}

#ifdef CONFIG_PM_DEVICE
static int stm32_saes_pm_action(const struct device *dev,
				enum pm_device_action action, uint32_t pm_hint)
{
	const struct stm32_saes_config *drv_cfg = dev_get_config(dev);
	int err;

	err = stm32_saes_acquire_sem(drv_cfg);
	if (err)
		return err;

	switch (action) {
	case PM_DEVICE_ACTION_SUSPEND:
		break;

	case PM_DEVICE_ACTION_RESUME:
		err = stm32_saes_set_clock(drv_cfg, true);
		if (!err && PM_HINT_IS_STATE(pm_hint, CONTEXT))
			err = reset_control_reset(&drv_cfg->rst_ctl);
		(void)stm32_saes_set_clock(drv_cfg, false);
		break;

	default:
		err = -EINVAL;
		break;
	}

	stm32_saes_release_sem(drv_cfg);

	return err;
}
#endif

static const struct sk_cipher_driver_api __maybe_unused stm32_saes_api = {
	.ctx_init = stm32_saes_ctx_init,
	.update = stm32_saes_update,
	.wrap = stm32_saes_wrap,
	.reset = stm32_saes_reset,
};

#define DT_CLOCK_CONTROL_GET_BY_IDX(node_id, idx)					\
	{										\
		.dev = DEVICE_DT_GET(DT_CLOCKS_CTLR_BY_IDX(node_id, idx)),		\
		.subsys = (clk_subsys_t)DT_CLOCKS_CELL_BY_IDX(node_id, idx, bits)	\
	}

#define _DT_CLOCK_CTL(clk_id, node_id) DT_CLOCK_CONTROL_GET_BY_IDX(node_id, clk_id)

#define DT_CLOCK_CONTROL(node_id)						\
	{									\
		LISTIFY(DT_NUM_CLOCKS(node_id), _DT_CLOCK_CTL, (,), node_id)	\
	}

#define DT_INST_CLOCK_CONTROL(inst) DT_CLOCK_CONTROL(DT_DRV_INST(inst))

#define STM32_SAES_INIT(n, _variant)						\
										\
DT_INST_ACCESS_CTRLS_DEFINE(n);							\
										\
static const struct clock_control clk_ctrl_##n[] = DT_INST_CLOCK_CONTROL(n);	\
										\
static const struct stm32_saes_config stm32_saes_cfg_##n = {			\
	.base = DT_INST_REG_ADDR(n),						\
	.clk_ctl = clk_ctrl_##n,						\
	.n_clk = DT_INST_NUM_CLOCKS(n),						\
	.rst_ctl = DT_INST_RESET_CONTROL_GET(n),				\
	.firewall = DT_INST_ACCESS_CTRLS_GET(n),				\
	.n_firewall = DT_INST_ACCESS_CTRLS_NUM(n),				\
};										\
										\
static struct stm32_saes_data stm32_saes_data_##n = {				\
	.variant = _variant,							\
};										\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_saes_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_INST_DEFINE(n,							\
		      &stm32_saes_probe,					\
		      PM_DEVICE_DT_INST_GET(n),					\
		      &stm32_saes_data_##n,					\
		      &stm32_saes_cfg_##n,					\
		      CORE, 50,							\
		      &stm32_saes_api);

/* MP21 configuration default values */
static __unused struct stm32_saes_variant variant_stm32mp21 = {
	.support_192_bit_key = true,
};

/* MP23 and MP25 configuration default values */
static __unused struct stm32_saes_variant variant_stm32mp13 = {
	.support_192_bit_key = false,
};

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_saes

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_SAES_INIT, &variant_stm32mp21)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp13_saes

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_SAES_INIT, &variant_stm32mp13)

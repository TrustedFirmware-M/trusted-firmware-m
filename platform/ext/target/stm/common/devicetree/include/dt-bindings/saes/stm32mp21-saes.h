/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef _DT_BINDINGS_STM32MP21_SAES_H
#define _DT_BINDINGS_STM32MP21_SAES_H

/* SAES control register */
#define _SAES_CR			U(0x0)
/* SAES status register */
#define _SAES_SR			U(0x04)
/* SAES data input register */
#define _SAES_DINR			U(0x08)
/* SAES data output register */
#define _SAES_DOUTR			U(0x0C)
/* SAES key registers [0-7] */
#define _SAES_KEYR0			U(0x20)
#define _SAES_KEYR1			U(0x24)
#define _SAES_KEYR2			U(0x28)
#define _SAES_KEYR3			U(0x2C)
#define _SAES_KEYR4			U(0x30)
#define _SAES_KEYR5			U(0x34)
#define _SAES_KEYR6			U(0x38)
#define _SAES_KEYR7			U(0x3C)
/* SAES initialization vector registers [0-3] */
#define _SAES_IVR0			U(0x40)
#define _SAES_IVR1			U(0x44)
#define _SAES_IVR2			U(0x48)
#define _SAES_IVR3			U(0x4C)
/* SAES context swap registers [0-7] */
#define _SAES_CSR0			U(0x50)
#define _SAES_CSR1			U(0x54)
#define _SAES_CSR2			U(0x58)
#define _SAES_CSR3			U(0x5C)
#define _SAES_CSR4			U(0x50)
#define _SAES_CSR5			U(0x54)
#define _SAES_CSR6			U(0x58)
#define _SAES_CSR7			U(0x5C)
/* SAES Interrupt Enable Register */
#define _SAES_IER			U(0x300)
/* SAES Interrupt Status Register */
#define _SAES_ISR			U(0x304)
/* SAES Interrupt Clear Register */
#define _SAES_ICR			U(0x308)

/* SAES control register fields */
#define _SAES_CR_RESET_VALUE		U(0x0)
#define _SAES_CR_IPRST			BIT(31)
#define _SAES_CR_KEYSEL_MASK		GENMASK_32(30, 28)
#define _SAES_CR_KEYSEL_SHIFT		U(28)
#define _SAES_CR_KEYSEL_SOFT		U(0x0)
#define _SAES_CR_KEYSEL_DHUK		U(0x1)
#define _SAES_CR_KEYSEL_BHK		U(0x2)
#define _SAES_CR_KEYSEL_BHU_XOR_BH_K	U(0x4)
#define _SAES_CR_WRAPID_MASK		GENMASK_32(27, 25)
#define _SAES_CR_WRAPID_SHIFT		U(25)
#define _SAES_CR_WRAPID_SAES		U(0x0)
#define _SAES_CR_WRAPID_CRYP1		U(0x1)
#define _SAES_CR_WRAPID_CRYP2		U(0x2)
#define _SAES_CR_WRAPEN			BIT(24)
#define _SAES_CR_NPBLB_MASK		GENMASK_32(23, 20)
#define _SAES_CR_NPBLB_SHIFT		U(20)
#define _SAES_CR_KEYPROT		BIT(19)
#define _SAES_CR_KEYSIZE_MASK		GENMASK_32(18, 17)
#define _SAES_CR_KEYSIZE_SHIFT		U(17)
#define _SAES_CR_KEYSIZE_128		U(0x0)
#define _SAES_CR_KEYSIZE_192		U(0x1)
#define _SAES_CR_KEYSIZE_256		U(0x2)
#define _SAES_CR_CPHASE_MASK		GENMASK_32(14, 13)
#define _SAES_CR_CPHASE_SHIFT		U(13)
#define _SAES_CR_CPHASE_INIT		U(0)
#define _SAES_CR_CPHASE_HEADER		U(1)
#define _SAES_CR_CPHASE_PAYLOAD		U(2)
#define _SAES_CR_CPHASE_FINAL		U(3)
#define _SAES_CR_DMAOUTEN		BIT(12)
#define _SAES_CR_DMAINEN		BIT(11)
#define _SAES_CR_CHMOD_MASK		GENMASK_32(8, 5)
#define _SAES_CR_CHMOD_SHIFT		U(5)
#define _SAES_CR_CHMOD_ECB		U(0x0)
#define _SAES_CR_CHMOD_CBC		U(0x1)
#define _SAES_CR_CHMOD_CTR		U(0x2)
#define _SAES_CR_CHMOD_GCM		U(0x3)
#define _SAES_CR_CHMOD_GMAC		U(0x3)
#define _SAES_CR_CHMOD_CCM		U(0x4)
#define _SAES_CR_OPMODE_MASK		GENMASK_32(4, 3)
#define _SAES_CR_OPMODE_SHIFT		U(3)
#define _SAES_CR_OPMODE_ENC		U(0)
#define _SAES_CR_OPMODE_KEYPREP		U(1)
#define _SAES_CR_OPMODE_DEC		U(2)
#define _SAES_CR_DATATYPE_MASK		GENMASK_32(2, 1)
#define _SAES_CR_DATATYPE_SHIFT		U(1)
#define _SAES_CR_DATATYPE_NONE		U(0)
#define _SAES_CR_DATATYPE_HALF_WORD	U(1)
#define _SAES_CR_DATATYPE_BYTE		U(2)
#define _SAES_CR_DATATYPE_BIT		U(3)
#define _SAES_CR_EN			BIT(0)

/* SAES status register fields */
#define _SAES_SR_KEYVALID		BIT(7)
#define _SAES_SR_WRERR			BIT(6)
#define _SAES_SR_RDERR			BIT(5)
#define _SAES_SR_BUSY			BIT(4)

/* SAES interrupt registers fields */
#define _SAES_I_RNG_ERR			BIT(5)
#define _SAES_I_KEY_ERR			BIT(4)
#define _SAES_I_RW_ERR			BIT(3)
#define _SAES_I_CCF			BIT(2)

/* Correspondence between registers name and the used define in the driver */
#define _SAES_SUSPR0			_SAES_CSR0
#define _SAES_SUSPR1			_SAES_CSR1
#define _SAES_SUSPR2			_SAES_CSR2
#define _SAES_SUSPR3			_SAES_CSR3
#define _SAES_SUSPR4			_SAES_CSR4
#define _SAES_SUSPR5			_SAES_CSR5
#define _SAES_SUSPR6			_SAES_CSR6
#define _SAES_SUSPR7			_SAES_CSR7

/* Correspondence between registers fields and the used define in the driver */
#define _SAES_CR_GCMPH_MASK		_SAES_CR_CPHASE_MASK
#define _SAES_CR_GCMPH_SHIFT		_SAES_CR_CPHASE_SHIFT
#define _SAES_CR_GCMPH_INIT		_SAES_CR_CPHASE_INIT
#define _SAES_CR_GCMPH_HEADER		_SAES_CR_CPHASE_HEADER
#define _SAES_CR_GCMPH_PAYLOAD		_SAES_CR_CPHASE_PAYLOAD
#define _SAES_CR_GCMPH_FINAL		_SAES_CR_CPHASE_FINAL

#define _SAES_CR_MODE_MASK		_SAES_CR_OPMODE_MASK
#define _SAES_CR_MODE_SHIFT		_SAES_CR_OPMODE_SHIFT
#define _SAES_CR_MODE_ENC		_SAES_CR_OPMODE_ENC
#define _SAES_CR_MODE_KEYPREP		_SAES_CR_OPMODE_KEYPREP
#define _SAES_CR_MODE_DEC		_SAES_CR_OPMODE_DEC

#define _SAES_CR_KSHAREID_MASK		_SAES_CR_WRAPID_MASK
#define _SAES_CR_KSHAREID_SHIFT		_SAES_CR_WRAPID_SHIFT
#define _SAES_CR_KSHAREID_CRYP1		_SAES_CR_WRAPID_CRYP1
#define _SAES_CR_KSHAREID_CRYP2         _SAES_CR_WRAPID_CRYP2
#define _SAES_CR_KEYMOD_MASK		_SAES_CR_WRAPEN
#define _SAES_CR_KEYMOD_SHIFT		U(24)
#define _SAES_CR_KEYMOD_NORMAL		U(0x0)
#define _SAES_CR_KEYMOD_WRAPPED		U(0x1)
#define _SAES_CR_KEYMOD_SHARED		U(0x1)

/* SAES Capabilities */
#define SAES_CASPS_AES192               (true)

#endif /* _DT_BINDINGS_STM32MP21_SAES_H */

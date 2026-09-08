/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef _DT_BINDINGS_STM32MP25_SAES_H
#define _DT_BINDINGS_STM32MP25_SAES_H

/* SAES control register */
#define _SAES_CR			U(0x0)
/* SAES status register */
#define _SAES_SR			U(0x04)
/* SAES data input register */
#define _SAES_DINR			U(0x08)
/* SAES data output register */
#define _SAES_DOUTR			U(0x0c)
/* SAES key registers [0-3] */
#define _SAES_KEYR0			U(0x10)
#define _SAES_KEYR1			U(0x14)
#define _SAES_KEYR2			U(0x18)
#define _SAES_KEYR3			U(0x1c)
/* SAES initialization vector registers [0-3] */
#define _SAES_IVR0			U(0x20)
#define _SAES_IVR1			U(0x24)
#define _SAES_IVR2			U(0x28)
#define _SAES_IVR3			U(0x2c)
/* SAES key registers [4-7] */
#define _SAES_KEYR4			U(0x30)
#define _SAES_KEYR5			U(0x34)
#define _SAES_KEYR6			U(0x38)
#define _SAES_KEYR7			U(0x3c)
/* SAES suspend registers [0-7] */
#define _SAES_SUSPR0			U(0x40)
#define _SAES_SUSPR1			U(0x44)
#define _SAES_SUSPR2			U(0x48)
#define _SAES_SUSPR3			U(0x4c)
#define _SAES_SUSPR4			U(0x50)
#define _SAES_SUSPR5			U(0x54)
#define _SAES_SUSPR6			U(0x58)
#define _SAES_SUSPR7			U(0x5c)
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
#define _SAES_CR_KEYSEL_TEST		U(0x7)
#define _SAES_CR_KSHAREID_MASK		GENMASK_32(27, 26)
#define _SAES_CR_KSHAREID_SHIFT		U(26)
#define _SAES_CR_KSHAREID_CRYP1		U(0x0)
#define _SAES_CR_KSHAREID_CRYP2		U(0x1)
#define _SAES_CR_KEYMOD_MASK		GENMASK_32(25, 24)
#define _SAES_CR_KEYMOD_SHIFT		U(24)
#define _SAES_CR_KEYMOD_NORMAL		U(0x0)
#define _SAES_CR_KEYMOD_WRAPPED		U(0x1)
#define _SAES_CR_KEYMOD_SHARED		U(0x2)
#define _SAES_CR_NPBLB_MASK		GENMASK_32(23, 20)
#define _SAES_CR_NPBLB_SHIFT		U(20)
#define _SAES_CR_KEYPROT		BIT(19)
#define _SAES_CR_KEYSIZE		BIT(18)
#define _SAES_CR_KEYSIZE_SHIFT          U(18)
#define _SAES_CR_KEYSIZE_128		U(0x0)
#define _SAES_CR_KEYSIZE_256		U(0x1)
#define _SAES_CR_GCMPH_MASK		GENMASK_32(14, 13)
#define _SAES_CR_GCMPH_SHIFT		U(13)
#define _SAES_CR_GCMPH_INIT		U(0)
#define _SAES_CR_GCMPH_HEADER		U(1)
#define _SAES_CR_GCMPH_PAYLOAD		U(2)
#define _SAES_CR_GCMPH_FINAL		U(3)
#define _SAES_CR_DMAOUTEN		BIT(12)
#define _SAES_CR_DMAINEN		BIT(11)
#define _SAES_CR_CHMOD_MASK		(BIT(16) | GENMASK_32(6, 5))
#define _SAES_CR_CHMOD_SHIFT		U(5)
#define _SAES_CR_CHMOD_ECB		U(0x0)
#define _SAES_CR_CHMOD_CBC		U(0x1)
#define _SAES_CR_CHMOD_CTR		U(0x2)
#define _SAES_CR_CHMOD_GCM		U(0x3)
#define _SAES_CR_CHMOD_GMAC		U(0x3)
#define _SAES_CR_CHMOD_CCM		U(0x800)
#define _SAES_CR_MODE_MASK		GENMASK_32(4, 3)
#define _SAES_CR_MODE_SHIFT		U(3)
#define _SAES_CR_MODE_ENC		U(0)
#define _SAES_CR_MODE_KEYPREP		U(1)
#define _SAES_CR_MODE_DEC		U(2)
#define _SAES_CR_DATATYPE_MASK		GENMASK_32(2, 1)
#define _SAES_CR_DATATYPE_SHIFT		U(1)
#define _SAES_CR_DATATYPE_NONE		U(0)
#define _SAES_CR_DATATYPE_HALF_WORD	U(1)
#define _SAES_CR_DATATYPE_BYTE		U(2)
#define _SAES_CR_DATATYPE_BIT		U(3)
#define _SAES_CR_EN			BIT(0)

/* SAES status register fields */
#define _SAES_SR_KEYVALID		BIT(7)
#define _SAES_SR_BUSY			BIT(3)
#define _SAES_SR_WRERR			BIT(2)
#define _SAES_SR_RDERR			BIT(1)

/* SAES interrupt registers fields */
#define _SAES_I_RNG_ERR			BIT(3)
#define _SAES_I_KEY_ERR			BIT(2)
#define _SAES_I_RW_ERR			BIT(1)
#define _SAES_I_CCF			BIT(0)

/* Correspondence between registers fields and the used define in the driver */
#define _SAES_CR_KEYSIZE_MASK          _SAES_CR_KEYSIZE
#define _SAES_CR_KEYSIZE_192           U(0xDEADBEEF)

#endif /* _DT_BINDINGS_STM32MP25_SAES_H */

/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef _DT_BINDINGS_STM32MP2_RISAF_H
#define _DT_BINDINGS_STM32MP2_RISAF_H

/* RISAF region IDs */
#define RISAF_REG_ID(idx)	(idx)

/* RISAF base region enable modes */
#define RIF_BREN_DIS		0x0
#define RIF_BREN_EN		0x1

/* RISAF encryption modes */
#define RIF_ENC_DIS		0x0

#define RIF_ENC_MCE_EN		0x1 /* used for RISAF MCE extension */
#define RIF_ENC_EN		0x2

/* RISAF subregion IDs */
#define RISAF_SUBREG_ID(idx)	(idx)

/* RISAF subregion enable modes */
#define RIF_SREN_DIS		0x0
#define RIF_SREN_EN		0x1

/* RISAF subregion read enable modes */
#define RIF_RDEN_DIS		0x0
#define RIF_RDEN_EN		0x1

/* RISAF subregion write enable modes */
#define RIF_WREN_DIS		0x0
#define RIF_WREN_EN		0x1

/* RISAF subregion delegation control modes */
#define RIF_DCEN_DIS		0x0
#define RIF_DCEN_EN		0x1

/* RISAF subregion resource lock modes */
#define RIF_RLOCK_DIS		0x0
#define RIF_RLOCK_EN		0x1

#define DT_RISAF_ID_SHIFT	0
#define DT_RISAF_ID_MASK	GENMASK_32(3, 0)
#define DT_RISAF_EN_SHIFT	4
#define DT_RISAF_EN_MASK	BIT(4)
#define DT_RISAF_SEC_SHIFT	5
#define DT_RISAF_SEC_MASK	BIT(5)
#define DT_RISAF_ENC_SHIFT	6
#define DT_RISAF_ENC_MASK	GENMASK_32(7, 6)
#define DT_RISAF_PRIV_SHIFT	8
#define DT_RISAF_PRIV_MASK	GENMASK_32(15, 8)
#define DT_RISAF_READ_SHIFT	16
#define DT_RISAF_READ_MASK	GENMASK_32(23, 16)
#define DT_RISAF_WRITE_SHIFT	24
#define DT_RISAF_WRITE_MASK	GENMASK_32(31, 24)

#define DT_RISAF_CFG_SHIFT	0
#define DT_RISAF_CFG_MASK	\
	DT_RISAF_PRIV_MASK |	\
	DT_RISAF_ENC_MASK |	\
	DT_RISAF_SEC_MASK |	\
	DT_RISAF_EN_MASK

#define DT_RISAF_CIDCFG_SHIFT	0
#define DT_RISAF_CIDCFG_MASK	\
	DT_RISAF_READ_MASK |	\
	DT_RISAF_WRITE_MASK

#define RISAFPROT(risaf_region, cid_read_list, cid_write_list, cid_priv_list, sec, enc, enabled) \
	(((cid_write_list) << DT_RISAF_WRITE_SHIFT) |	\
	 ((cid_read_list) << DT_RISAF_READ_SHIFT) |	\
	 ((cid_priv_list) << DT_RISAF_PRIV_SHIFT) |	\
	 ((enc) << DT_RISAF_ENC_SHIFT) |		\
	 ((sec) << DT_RISAF_SEC_SHIFT) |		\
	 ((enabled) << DT_RISAF_EN_SHIFT) |		\
	 (risaf_region))

#define DT_RISAF_SUB_ID_SHIFT		0
#define DT_RISAF_SUB_ID_MASK	        BIT(DT_RISAF_SUB_ID_SHIFT)
#define DT_RISAF_SUB_EN_SHIFT		1
#define DT_RISAF_SUB_EN_MASK		BIT(DT_RISAF_SUB_EN_SHIFT)
#define DT_RISAF_SUB_SEC_SHIFT		2
#define DT_RISAF_SUB_SEC_MASK		BIT(DT_RISAF_SUB_SEC_SHIFT)
#define DT_RISAF_SUB_PRIV_SHIFT		3
#define DT_RISAF_SUB_PRIV_MASK		BIT(DT_RISAF_SUB_PRIV_SHIFT)
#define DT_RISAF_SUB_SRCID_SHIFT	4
#define DT_RISAF_SUB_SRCID_MASK		GENMASK_32(6, DT_RISAF_SUB_SRCID_SHIFT)
#define DT_RISAF_SUB_RDEN_SHIFT		8
#define DT_RISAF_SUB_RDEN_MASK		BIT(DT_RISAF_SUB_RDEN_SHIFT)
#define DT_RISAF_SUB_WREN_SHIFT		9
#define DT_RISAF_SUB_WREN_MASK		BIT(DT_RISAF_SUB_WREN_SHIFT)
#define DT_RISAF_SUB_DCEN_SHIFT		16
#define DT_RISAF_SUB_DCEN_MASK		BIT(DT_RISAF_SUB_DCEN_SHIFT)
#define DT_RISAF_SUB_DCCID_SHIFT	17
#define DT_RISAF_SUB_DCCID_MASK		GENMASK_32(19, DT_RISAF_SUB_DCCID_SHIFT)
#define DT_RISAF_SUB_RLOCK_SHIFT	31
#define DT_RISAF_SUB_RLOCK_MASK		BIT(DT_RISAF_SUB_RLOCK_SHIFT)

#define DT_RISAF_SUB_CFG_SHIFT	        0
#define DT_RISAF_SUB_CFG_MASK	        \
	DT_RISAF_SUB_WREN_MASK |	\
	DT_RISAF_SUB_RDEN_MASK |	\
	DT_RISAF_SUB_PRIV_MASK |	\
	DT_RISAF_SUB_SEC_MASK |	        \
	DT_RISAF_SUB_SRCID_MASK |	\
	DT_RISAF_SUB_RLOCK_MASK |	\
	DT_RISAF_SUB_EN_MASK

#define DT_RISAF_SUB_NEST_SHIFT	        0
#define DT_RISAF_SUB_NEST_MASK	        \
	DT_RISAF_SUB_DCCID_MASK |	\
	DT_RISAF_SUB_DCEN_MASK

#define RISAFSUBPROT(risaf_subregion, dccid, dcen, rden, wren, srcid, priv, sec, enabled, rlock) \
	(((rlock) << DT_RISAF_SUB_RLOCK_SHIFT) |	\
	 ((dccid) << DT_RISAF_SUB_DCCID_SHIFT) |	\
	 ((dcen) << DT_RISAF_SUB_DCEN_SHIFT) |		\
	 ((wren) << DT_RISAF_SUB_WREN_SHIFT) |		\
	 ((rden) << DT_RISAF_SUB_RDEN_SHIFT) |		\
	 ((srcid) << DT_RISAF_SUB_SRCID_SHIFT) |	\
	 ((priv) << DT_RISAF_SUB_PRIV_SHIFT) |		\
	 ((sec) << DT_RISAF_SUB_SEC_SHIFT) |		\
	 ((enabled) << DT_RISAF_SUB_EN_SHIFT) |		\
	 (risaf_subregion))

/* for RISAF access-controllers on
 * region:
 *   access-controllers = <&risaf_phandle RISAFREGION(region_id, IS_BASEREGION) RISAFPROT()>
 * sub-region:
 *   access-controllers = <&risaf_phandle RISAFREGION(region_id, IS_SUBREGION) RISAFSUBPROT()>
 */
#define DT_RISAFREGION_SUB_SHIFT		0
#define DT_RISAFREGION_SUB_MASK			BIT(0)
#define DT_RISAFREGION_BASE_SHIFT		8
#define DT_RISAFREGION_BASE_MASK		GENMASK_32(15, 8)

#define IS_SUBREGION				1
#define IS_BASEREGION				0

#define RISAFREGION(base_region, is_subregion)		\
	(((base_region) << DT_RISAFREGION_BASE_SHIFT) |	\
	 ((is_subregion) << DT_RISAFREGION_SUB_SHIFT))

#endif /* _DT_BINDINGS_STM32MP2_RISAF_H */

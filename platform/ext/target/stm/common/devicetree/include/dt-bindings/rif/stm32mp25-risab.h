/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef _DT_BINDINGS_STM32MP25_RISAB_H
#define _DT_BINDINGS_STM32MP25_RISAB_H

/* RISAB control modes */
#define RIF_DDCID_DIS				0x0
#define RIF_DDCID_EN				0x1

#define DT_RISAB_PLIST_MASK			GENMASK_32(7, 0)
#define DT_RISAB_PLIST_SHIFT			0
#define DT_RISAB_READ_LIST_MASK			GENMASK_32(15, 8)
#define DT_RISAB_READ_LIST_SHIFT		8
#define DT_RISAB_WRITE_LIST_MASK		GENMASK_32(23, 16)
#define DT_RISAB_WRITE_LIST_SHIFT		16
#define DT_RISAB_CFEN_MASK			BIT(24)
#define DT_RISAB_CFEN_SHIFT			24
#define DT_RISAB_DPRIV_MASK			BIT(25)
#define DT_RISAB_DPRIV_SHIFT			25
#define DT_RISAB_SEC_MASK			BIT(26)
#define DT_RISAB_SEC_SHIFT			26
#define DT_RISAB_DCCID_MASK			GENMASK_32(29, 27)
#define DT_RISAB_DCCID_SHIFT			27
#define DT_RISAB_DCEN_MASK			BIT(31)
#define DT_RISAB_DCEN_SHIFT			31

#define RISABPROT(delegate_en, delegate_cid, sec, default_priv,			\
		  enabled, cid_read_list, cid_write_list, cid_priv_list)	\
		  (((delegate_en) << DT_RISAB_DCEN_SHIFT) |			\
		   ((delegate_cid) << DT_RISAB_DCCID_SHIFT) |			\
		   ((sec) << DT_RISAB_SEC_SHIFT) |				\
		   ((default_priv) << DT_RISAB_DPRIV_SHIFT) |			\
		   ((enabled) << DT_RISAB_CFEN_SHIFT) |				\
		   ((cid_write_list) << DT_RISAB_WRITE_LIST_SHIFT) |		\
		   ((cid_read_list) << DT_RISAB_READ_LIST_SHIFT) |		\
		   (cid_priv_list))

#endif /* _DT_BINDINGS_STM32MP25_RISAB_H */

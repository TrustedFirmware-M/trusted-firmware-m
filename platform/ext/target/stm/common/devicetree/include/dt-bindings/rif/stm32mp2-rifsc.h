/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef _DT_BINDINGS_STM32MP2_RIFSC_H
#define _DT_BINDINGS_STM32MP2_RIFSC_H

/* Global lock bindings */
#define RIFSC_RIMU_GLOCK			1
#define RIFSC_RISUP_GLOCK			2

/* masters ID */
#define RIMU_ID(idx)		(idx)

/* master configuration modes */
#define RIF_CIDSEL_P	0x0 /* config from RISUP */
#define RIF_CIDSEL_M	0x1 /* config from RIMU */

#define RIFSC_RIMC_MODE_SHIFT		2
#define RIFSC_RIMC_MODE_MASK		BIT(2)
#define RIFSC_RIMC_MCID_SHIFT		4
#define RIFSC_RIMC_MCID_MASK		GENMASK_32(6, 4)
#define RIFSC_RIMC_MSEC_SHIFT		8
#define RIFSC_RIMC_MSEC_MASK		BIT(8)
#define RIFSC_RIMC_MPRIV_SHIFT		9
#define RIFSC_RIMC_MPRIV_MASK		BIT(9)
#define RIFSC_RIMC_M_ID_SHIFT		16
#define RIFSC_RIMC_M_ID_MASK		GENMASK_32(23, 16)

#define RIFSC_RIMC_ATTRx_SHIFT		0
#define RIFSC_RIMC_ATTRx_MASK		(RIFSC_RIMC_MODE_MASK | \
					 RIFSC_RIMC_MCID_MASK | \
					 RIFSC_RIMC_MSEC_MASK | \
					 RIFSC_RIMC_MPRIV_MASK)

#define RIMUPROT(rimuid, mcid, msec, mpriv, mode) \
	(((rimuid) << RIFSC_RIMC_M_ID_SHIFT) | \
	 ((mpriv) << RIFSC_RIMC_MPRIV_SHIFT) | \
	 ((msec) << RIFSC_RIMC_MSEC_SHIFT) | \
	 ((mcid) << RIFSC_RIMC_MCID_SHIFT) | \
	 ((mode) << RIFSC_RIMC_MODE_SHIFT))

#endif /* _DT_BINDINGS_STM32MP2_RIFSC_H */

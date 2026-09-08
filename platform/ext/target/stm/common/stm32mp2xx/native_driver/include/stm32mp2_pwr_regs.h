/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 */
#ifndef STM32MP2_PWR_REGS_H
#define STM32MP2_PWR_REGS_H

/* PWR offset register */
#define _PWR_CR1_OFFSET			U(0x000)
#define _PWR_CR7_OFFSET			U(0x018)
#define _PWR_CR8_OFFSET			U(0x01C)
#define _PWR_CR9_OFFSET			U(0x020)
#define _PWR_CR11			U(0x028)
#define _PWR_CR12_OFFSET		U(0x02C)
#define _PWR_UCPDR_OFFSET		U(0x030)
#define _PWR_BDCR1			U(0x038)
#define _PWR_CPU2CR			U(0x044)
#define _PWR_D1CR			U(0x04C)
#define _PWR_D2CR			U(0x050)
#define _PWR_WKUPCR			U(0x060)
#define _PWR_RSECCFGR			U(0x100)
#define _PWR_RPRIVCFGR			U(0x104)
#define _PWR_RCIDCFGR			U(0x108)
#define _PWR_WIOSECCFGR			U(0x180)
#define _PWR_WIOPRIVCFGR		U(0x184)
#define _PWR_WIOCIDCFGR			U(0x188)
#define _PWR_WIOSEMCR			U(0x18C)

/* PWR_CR1 register fields */
#define _CR1_VDDIO3VMEN			BIT(0)
#define _CR1_VDDIO4VMEN			BIT(1)
#define _CR1_UCPDVMEN			BIT(3)
#define _CR1_AVMEN			BIT(4)

#define _CR1_VDDIO3SV			BIT(8)
#define _CR1_VDDIO4SV			BIT(9)
#define _CR1_UCPDSV			BIT(11)
#define _CR1_ASV			BIT(12)

#define _CR1_VDDIO3RDY			BIT(16)
#define _CR1_VDDIO4RDY			BIT(17)
#define _CR1_UCPDRDY			BIT(19)
#define _CR1_ARDY			BIT(20)

#define _CR1_VDDIOVRSEL			BIT(24)
#define _CR1_VDDIO3VRSEL		BIT(25)
#define _CR1_VDDIO4VRSEL		BIT(26)

/* PWR_CR7 register fields */
#define _CR7_VDDIO2VMEN			BIT(0)
#define _CR7_VDDIO2SV			BIT(8)
#define _CR7_VDDIO2RDY			BIT(16)
#define _CR7_VDDIO2VRSEL		BIT(24)

/* PWR_CR8 register fields */
#define _CR8_VDDIO1VMEN			BIT(0)
#define _CR8_VDDIO1SV			BIT(8)
#define _CR8_VDDIO1RDY			BIT(16)
#define _CR8_VDDIO1VRSEL		BIT(24)

/* PWR_CR11 register fields */
#define _CR11_DDRRETDIS			BIT(0)

/* PWR_CR12 register fields */
#define _CR12_GPUVMEN			BIT(0)
#define _CR12_GPUSV			BIT(8)
#define _CR12_VDDGPURDY			BIT(16)

/* PWR_BDCR1 register fields */
#define _BDCR1_DBD3P			BIT(0)

/* PWR_CPU2CR register fields */
#define _CPU2CR_CSSF			BIT(9)

/* PWR_D1CR register fields */
#define _D1CR_POPL_D1_MASK		GENMASK(12, 8)
#define _D1CR_POPL_D1_SHIFT		8

/* PWR_D2CR register fields */
#define _D2CR_LPCFG_D2_MASK		BIT(0)
#define _D2CR_LPCFG_D2_SHIFT		0
#define _D2CR_POPL_D2_MASK		GENMASK(12, 8)
#define _D2CR_POPL_D2_SHIFT		8
#define _D2CR_LPLVDLY_D2_MASK		GENMASK(18, 16)
#define _D2CR_LPLVDLY_D2_SHIFT		16
#define _D2CR_PODH_D2_MASK		GENMASK(27, 24)
#define _D2CR_PODH_D2_SHIFT		24

/* PWR_WKUPCRx register fields */
#define _WKUPCR_WKUPC_MASK		BIT(0)
#define _WKUPCR_WKUPC_SHIFT		0
#define _WKUPCR_WKUPP_MASK		BIT(8)
#define _WKUPCR_WKUPP_SHIFT		8
#define _WKUPCR_WKUPPUPD_MASK		GENMASK(13, 12)
#define _WKUPCR_WKUPPUPD_SHIFT		12
#define _WKUPCR_WKUPENCPU2_MASK		BIT(17)
#define _WKUPCR_WKUPENCPU2_SHIFT	17
#define _WKUPCR_WKUPF_MASK		BIT(31)
#define _WKUPCR_WKUPF_SHIFT		31

#define _WKUPCR_WKUPPUPD_NO_PULLS	0
#define _WKUPCR_WKUPPUPD_PULL_UP	1
#define _WKUPCR_WKUPPUPD_PULL_DOWN	2

/* PWR_RxCIDCFGR register fields */
#define _RCIDCFGR_CFEN_MASK		BIT(0)
#define _RCIDCFGR_CFEN_SHIFT		0
#define _RCIDCFGR_SCID_MASK		GENMASK_32(6, 4)
#define _RCIDCFGR_SCID_SHIFT		4

/* PWR_WIOxCIDCFGR register fields */
#define _WIOCIDCFGR_CFEN_MASK		BIT(0)
#define _WIOCIDCFGR_CFEN_SHIFT		0
#define _WIOCIDCFGR_SEMEN_MASK		BIT(1)
#define _WIOCIDCFGR_SEMEN_SHIFT		1
#define _WIOCIDCFGR_SCID_MASK		GENMASK_32(6, 4)
#define _WIOCIDCFGR_SCID_SHIFT		4
#define _WIOCIDCFGR_SEMWLC_MASK		GENMASK_32(23, 16)
#define _WIOCIDCFGR_SEMWLC_SHIFT	16

/* PWR_WIOxSEMCR register fields */
#define _WIOSEMCR_MUTEX_MASK		BIT(0)
#define _WIOSEMCR_MUTEX_SHIFT		0
#define _WIOSEMCR_SCID_MASK		GENMASK_32(6, 4)
#define _WIOSEMCR_SCID_SHIFT		U(4)

#define PWR_WKUPCR_X_ADDR(_base, _x)	((_base) + _PWR_WKUPCR + (U(0x4) * (_x)))

/* initlevel */
#define STM32MP2_PWR_LVL		PRE_CORE
#define STM32MP2_PWR_PRIO		1

#define STM32MP2_PWR_RIF_LVL		STM32MP2_PWR_LVL
#define STM32MP2_PWR_RIF_PRIO		UTIL_INC(STM32MP2_PWR_PRIO)

#define STM32MP2_PWR_INTC_LVL		STM32MP2_PWR_LVL
#define STM32MP2_PWR_INTC_PRIO		6

#define STM32MP2_PWR_REGU_LVL		CORE
#define STM32MP2_PWR_REGU_PRIO		8

#endif /* STM32MP2_PWR_REGS_H */

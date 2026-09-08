/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef _DT_BINDINGS_STM32MP25_RIF_H
#define _DT_BINDINGS_STM32MP25_RIF_H

/* RIF CIDs */
#define RIF_CID0		0x0
#define RIF_CID1		0x1
#define RIF_CID2		0x2
#define RIF_CID3		0x3
#define RIF_CID4		0x4
#define RIF_CID5		0x5
#define RIF_CID6		0x6
#define RIF_CID7		0x7

/* RIF semaphore list */
#define EMPTY_SEMWL		0x0
#define RIF_CID0_BF		(1 << RIF_CID0)
#define RIF_CID1_BF		(1 << RIF_CID1)
#define RIF_CID2_BF		(1 << RIF_CID2)
#define RIF_CID3_BF		(1 << RIF_CID3)
#define RIF_CID4_BF		(1 << RIF_CID4)
#define RIF_CID5_BF		(1 << RIF_CID5)
#define RIF_CID6_BF		(1 << RIF_CID6)
#define RIF_CID7_BF		(1 << RIF_CID7)

/* RIF secure levels */
#define RIF_NSEC		0x0
#define RIF_SEC			0x1

/* RIF privilege levels */
#define RIF_NPRIV		0x0
#define RIF_PRIV		0x1

/* RIF semaphore modes */
#define RIF_SEM_DIS		0x0
#define RIF_SEM_EN		0x1

/* RIF CID filtering modes */
#define RIF_CFDIS		0x0
#define RIF_CFEN		0x1

/* RIF lock states */
#define RIF_UNLOCK		0x0
#define RIF_LOCK		0x1
/* define for mp2 Resource */
#define RES_FLEX0		0
#define RES_FLEX1		1
#define RES_FLEX2		2
#define RES_FLEX3		3
#define RES_FLEX4		4
#define RES_FLEX5		5
#define RES_FLEX6		6
#define RES_FLEX7		7
#define RES_FLEX8		8
#define RES_FLEX9		9
#define RES_FLEX10		10
#define RES_FLEX11		11
#define RES_FLEX12		12
#define RES_FLEX13		13
#define RES_FLEX14		14
#define RES_FLEX15		15
#define RES_FLEX16		16
#define RES_FLEX17		17
#define RES_FLEX18		18
#define RES_FLEX19		19
#define RES_FLEX20		20
#define RES_FLEX21		21
#define RES_FLEX22		22
#define RES_FLEX23		23
#define RES_FLEX24		24
#define RES_FLEX25		25
#define RES_FLEX26		26
#define RES_FLEX27		27
#define RES_FLEX28		28
#define RES_FLEX29		29
#define RES_FLEX30		30
#define RES_FLEX31		31
#define RES_FLEX32		32
#define RES_FLEX33		33
#define RES_FLEX34		34
#define RES_FLEX35		35
#define RES_FLEX36		36
#define RES_FLEX37		37
#define RES_FLEX38		38
#define RES_FLEX39		39
#define RES_FLEX40		40
#define RES_FLEX41		41
#define RES_FLEX42		42
#define RES_FLEX43		43
#define RES_FLEX44		44
#define RES_FLEX45		45
#define RES_FLEX46		46
#define RES_FLEX47		47
#define RES_FLEX48		48
#define RES_FLEX49		49
#define RES_FLEX50		50
#define RES_FLEX51		51
#define RES_FLEX52		52
#define RES_FLEX53		53
#define RES_FLEX54		54
#define RES_FLEX55		55
#define RES_FLEX56		56
#define RES_FLEX57		57
#define RES_FLEX58		58
#define RES_FLEX59		59
#define RES_FLEX60		60
#define RES_FLEX61		61
#define RES_FLEX62		62
#define RES_FLEX63		63
#define RES_PLL45678            64
#define RES_FCALC               65
#define RES_SYSRST              66
#define RES_BOOT_STDB           67
#define RES_RDCR                68
#define RES_SYSCLK              69
#define RES_CPU1                70
#define RES_CPU2                71
#define RES_CPU3                72
#define RES_DEBUG               73
#define RES_SYSRAM              74
#define RES_VDERAM              75
#define RES_RETRAM              76
#define RES_BKPSRAM             77
#define RES_SRAM1               78
#define RES_SRAM2               79
#define RES_LPSRAM1             80
#define RES_LPSRAM2             81
#define RES_LPSRAM3             82
#define RES_HPDMA1		83
#define RES_HPDMA2		84
#define RES_HPDMA3		85
#define RES_LPDMA1		86
#define RES_IPCC1		87
#define RES_IPCC2		88
#define RES_HSEM		89
#define RES_GPIOA		90
#define RES_GPIOB		91
#define RES_GPIOC		92
#define RES_GPIOD		93
#define RES_GPIOE		94
#define RES_GPIOF		95
#define RES_GPIOG		96
#define RES_GPIOH		97
#define RES_GPIOI		98
#define RES_GPIOJ		99
#define RES_GPIOK		100
#define RES_GPIOZ		101
#define RES_RTC		        102
#define RES_BSEC		103
#define RES_DDRC                104
#define RES_PLL3                105
#define RES_SYSCPU1             106
#define RES_MCO1                107
#define RES_MCO2                108
#define RES_OSPI1               109
#define RES_OSPI2               110
#define RES_FMC                 111
#define RES_HSI                 112



/* Used when a field in a macro has no impact */
#define RIF_UNUSED		0x0

#define RIF_EXTI1_RESOURCE(x)		(x)
#define RIF_EXTI2_RESOURCE(x)		(x)
#define RIF_FMC_CTRL(x)			(x)
#define RIF_IOPORT_PIN(x)		(x)
#define RIF_HPDMA_CHANNEL(x)		(x)
#define RIF_IPCC_CPU1_CHANNEL(x)        (x - 1)
#define RIF_IPCC_CPU2_CHANNEL(x)        (((x) - 1) + 16)
#define RIF_PWR_RESOURCE(x)		(x)
#define RIF_HSEM_RESOURCE(x)		(x)
/* Shareable PWR resources, RIF_PWR_RESOURCE_WIO(0) doesn't exist */
#define RIF_PWR_RESOURCE_WIO(x)		((x) + 6)
#define RIF_RCC_RESOURCE(x)		(x)
#define RIF_RTC_RESOURCE(x)		(x)
#define RIF_TAMP_RESOURCE(x)		(x)

#define RIFPROT_CFEN_SHIFT		0
#define RIFPROT_CFEN_MASK		BIT(0)
#define RIFPROT_SEM_EN_SHIFT		1
#define RIFPROT_SEM_EN_MASK		BIT(1)
#define RIFPROT_SCID_SHIFT		4
#define RIFPROT_SCID_MASK		GENMASK_32(6, 4)
#define RIFPROT_SEC_SHIFT		8
#define RIFPROT_SEC_MASK		BIT(8)
#define RIFPROT_PRIV_SHIFT		9
#define RIFPROT_PRIV_MASK		BIT(9)
#define RIFPROT_LOCK_SHIFT		10
#define RIFPROT_LOCK_MASK		BIT(10)
#define RIFPROT_SEML_SHIFT		16
#define RIFPROT_SEML_MASK		GENMASK_32(23, 16)
#define RIFPROT_PER_ID_SHIFT		24
#define RIFPROT_PER_ID_MASK		GENMASK_32(31, 24)

#define RIFPROT_PERx_CID_SHIFT		0
#define RIFPROT_PERx_CID_MASK		(RIFPROT_CFEN_MASK |	\
					 RIFPROT_SEM_EN_MASK |	\
					 RIFPROT_SCID_MASK |	\
					 RIFPROT_SEML_MASK)

#define RIFPROT(rifid, sem_list, lock, sec, priv, scid, sem_en, cfen)	\
	(((rifid) << RIFPROT_PER_ID_SHIFT) |				\
	 ((sem_list) << RIFPROT_SEML_SHIFT) |				\
	 ((lock) << RIFPROT_LOCK_SHIFT) |				\
	 ((priv) << RIFPROT_PRIV_SHIFT) |				\
	 ((sec) << RIFPROT_SEC_SHIFT) |					\
	 ((scid) << RIFPROT_SCID_SHIFT) |				\
	 ((sem_en) << RIFPROT_SEM_EN_SHIFT) |				\
	 ((cfen) << RIFPROT_CFEN_SHIFT))

#endif /* _DT_BINDINGS_STM32MP25_RIF_H */

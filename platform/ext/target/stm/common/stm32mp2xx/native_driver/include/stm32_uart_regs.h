/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef STM32_UART_REGS_H
#define STM32_UART_REGS_H

#include <lib/utils_def.h>

#define _USART_CR1		0x00U
#define _USART_CR2		0x04U
#define _USART_CR3		0x08U
#define _USART_BRR		0x0CU
#define _USART_GTPR		0x10U
#define _USART_RTOR		0x14U
#define _USART_RQR		0x18U
#define _USART_ISR		0x1CU
#define _USART_ICR		0x20U
#define _USART_RDR		0x24U
#define _USART_TDR		0x28U
#define _USART_PRESC		0x2CU

/* USART_CR1 register fields */
#define _USART_CR1_UE		BIT(0)
#define _USART_CR1_UESM		BIT(1)
#define _USART_CR1_RE		BIT(2)
#define _USART_CR1_TE		BIT(3)
#define _USART_CR1_IDLEIE	BIT(4)
#define _USART_CR1_RXNEIE	BIT(5)
#define _USART_CR1_TCIE		BIT(6)
#define _USART_CR1_TXEIE	BIT(7)
#define _USART_CR1_PEIE		BIT(8)
#define _USART_CR1_PS		BIT(9)
#define _USART_CR1_PCE		BIT(10)
#define _USART_CR1_WAKE		BIT(11)
#define _USART_CR1_M		(BIT(28) | BIT(12))
#define _USART_CR1_M0		BIT(12)
#define _USART_CR1_MME		BIT(13)
#define _USART_CR1_CMIE		BIT(14)
#define _USART_CR1_OVER8	BIT(15)
#define _USART_CR1_DEDT		GENMASK(20, 16)
#define _USART_CR1_DEDT_0	BIT(16)
#define _USART_CR1_DEDT_1	BIT(17)
#define _USART_CR1_DEDT_2	BIT(18)
#define _USART_CR1_DEDT_3	BIT(19)
#define _USART_CR1_DEDT_4	BIT(20)
#define _USART_CR1_DEAT		GENMASK(25, 21)
#define _USART_CR1_DEAT_0	BIT(21)
#define _USART_CR1_DEAT_1	BIT(22)
#define _USART_CR1_DEAT_2	BIT(23)
#define _USART_CR1_DEAT_3	BIT(24)
#define _USART_CR1_DEAT_4	BIT(25)
#define _USART_CR1_RTOIE	BIT(26)
#define _USART_CR1_EOBIE	BIT(27)
#define _USART_CR1_M1		BIT(28)
#define _USART_CR1_FIFOEN	BIT(29)
#define _USART_CR1_TXFEIE	BIT(30)
#define _USART_CR1_RXFFIE	BIT(31)

/* USART_CR2 register fields */
#define _USART_CR2_SLVEN	BIT(0)
#define _USART_CR2_DIS_NSS	BIT(3)
#define _USART_CR2_ADDM7	BIT(4)
#define _USART_CR2_LBDL		BIT(5)
#define _USART_CR2_LBDIE	BIT(6)
#define _USART_CR2_LBCL		BIT(8)
#define _USART_CR2_CPHA		BIT(9)
#define _USART_CR2_CPOL		BIT(10)
#define _USART_CR2_CLKEN	BIT(11)
#define _USART_CR2_STOP		GENMASK(13, 12)
#define _USART_CR2_STOP_0	BIT(12)
#define _USART_CR2_STOP_1	BIT(13)
#define _USART_CR2_LINEN	BIT(14)
#define _USART_CR2_SWAP		BIT(15)
#define _USART_CR2_RXINV	BIT(16)
#define _USART_CR2_TXINV	BIT(17)
#define _USART_CR2_DATAINV	BIT(18)
#define _USART_CR2_MSBFIRST	BIT(19)
#define _USART_CR2_ABREN	BIT(20)
#define _USART_CR2_ABRMODE	GENMASK(22, 21)
#define _USART_CR2_ABRMODE_0	BIT(21)
#define _USART_CR2_ABRMODE_1	BIT(22)
#define _USART_CR2_RTOEN	BIT(23)
#define _USART_CR2_ADD		GENMASK(31, 24)

/* USART_CR3 register fields */
#define _USART_CR3_EIE		BIT(0)
#define _USART_CR3_IREN		BIT(1)
#define _USART_CR3_IRLP		BIT(2)
#define _USART_CR3_HDSEL	BIT(3)
#define _USART_CR3_NACK		BIT(4)
#define _USART_CR3_SCEN		BIT(5)
#define _USART_CR3_DMAR		BIT(6)
#define _USART_CR3_DMAT		BIT(7)
#define _USART_CR3_RTSE		BIT(8)
#define _USART_CR3_CTSE		BIT(9)
#define _USART_CR3_CTSIE	BIT(10)
#define _USART_CR3_ONEBIT	BIT(11)
#define _USART_CR3_OVRDIS	BIT(12)
#define _USART_CR3_DDRE		BIT(13)
#define _USART_CR3_DEM		BIT(14)
#define _USART_CR3_DEP		BIT(15)
#define _USART_CR3_SCARCNT	GENMASK(19, 17)
#define _USART_CR3_SCARCNT_0	BIT(17)
#define _USART_CR3_SCARCNT_1	BIT(18)
#define _USART_CR3_SCARCNT_2	BIT(19)
#define _USART_CR3_WUS		GENMASK(21, 20)
#define _USART_CR3_WUS_0	BIT(20)
#define _USART_CR3_WUS_1	BIT(21)
#define _USART_CR3_WUFIE	BIT(22)
#define _USART_CR3_TXFTIE	BIT(23)
#define _USART_CR3_TCBGTIE	BIT(24)
#define _USART_CR3_RXFTCFG	GENMASK(27, 25)
#define _USART_CR3_RXFTCFG_0	BIT(25)
#define _USART_CR3_RXFTCFG_1	BIT(26)
#define _USART_CR3_RXFTCFG_2	BIT(27)
#define _USART_CR3_RXFTIE	BIT(28)
#define _USART_CR3_TXFTCFG	GENMASK(31, 29)
#define _USART_CR3_TXFTCFG_0	BIT(29)
#define _USART_CR3_TXFTCFG_1	BIT(30)
#define _USART_CR3_TXFTCFG_2	BIT(31)

/* USART_BRR register fields */
#define _USART_BRR_DIV_FRACTION	GENMASK(3, 0)
#define _USART_BRR_DIV_MANTISSA	GENMASK(15, 4)

/* USART_GTPR register fields */
#define _USART_GTPR_PSC		GENMASK(7, 0)
#define _USART_GTPR_GT		GENMASK(15, 8)

/* USART_RTOR register fields */
#define _USART_RTOR_RTO		GENMASK(23, 0)
#define _USART_RTOR_BLEN	GENMASK(31, 24)

/* USART_RQR register fields */
#define _USART_RQR_ABRRQ	BIT(0)
#define _USART_RQR_SBKRQ	BIT(1)
#define _USART_RQR_MMRQ		BIT(2)
#define _USART_RQR_RXFRQ	BIT(3)
#define _USART_RQR_TXFRQ	BIT(4)

/* USART_ISR register fields */
#define _USART_ISR_PE		BIT(0)
#define _USART_ISR_FE		BIT(1)
#define _USART_ISR_NE		BIT(2)
#define _USART_ISR_ORE		BIT(3)
#define _USART_ISR_IDLE		BIT(4)
#define _USART_ISR_RXNE		BIT(5)
#define _USART_ISR_TC		BIT(6)
#define _USART_ISR_TXE		BIT(7)
#define _USART_ISR_LBDF		BIT(8)
#define _USART_ISR_CTSIF	BIT(9)
#define _USART_ISR_CTS		BIT(10)
#define _USART_ISR_RTOF		BIT(11)
#define _USART_ISR_EOBF		BIT(12)
#define _USART_ISR_UDR		BIT(13)
#define _USART_ISR_ABRE		BIT(14)
#define _USART_ISR_ABRF		BIT(15)
#define _USART_ISR_BUSY		BIT(16)
#define _USART_ISR_CMF		BIT(17)
#define _USART_ISR_SBKF		BIT(18)
#define _USART_ISR_RWU		BIT(19)
#define _USART_ISR_WUF		BIT(20)
#define _USART_ISR_TEACK	BIT(21)
#define _USART_ISR_REACK	BIT(22)
#define _USART_ISR_TXFE		BIT(23)
#define _USART_ISR_RXFF		BIT(24)
#define _USART_ISR_TCBGT	BIT(25)
#define _USART_ISR_RXFT		BIT(26)
#define _USART_ISR_TXFT		BIT(27)

/* USART_ICR register fields */
#define _USART_ICR_PECF		BIT(0)
#define _USART_ICR_FECF		BIT(1)
#define _USART_ICR_NCF		BIT(2)
#define _USART_ICR_ORECF	BIT(3)
#define _USART_ICR_IDLECF	BIT(4)
#define _USART_ICR_TCCF		BIT(6)
#define _USART_ICR_TCBGT	BIT(7)
#define _USART_ICR_LBDCF	BIT(8)
#define _USART_ICR_CTSCF	BIT(9)
#define _USART_ICR_RTOCF	BIT(11)
#define _USART_ICR_EOBCF	BIT(12)
#define _USART_ICR_UDRCF	BIT(13)
#define _USART_ICR_CMCF		BIT(17)
#define _USART_ICR_WUCF		BIT(20)

/* USART_RDR register fields */
#define _USART_RDR_RDR		GENMASK(8, 0)

/* USART_TDR register fields */
#define _USART_TDR_TDR		GENMASK(8, 0)

/* USART_PRESC register fields */
#define _USART_PRESC_PRESCALER	GENMASK(3, 0)

#endif /* STM32_UART_REGS_H */

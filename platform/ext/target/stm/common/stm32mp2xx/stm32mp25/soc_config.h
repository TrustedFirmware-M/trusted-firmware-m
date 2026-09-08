/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __SOC_CONFIG_H__
#define __SOC_CONFIG_H__

#include <dt-bindings/clock/st,stm32mp25-rcc.h>

#define S_RETRAM_ALIAS_BASE		(0x0E080000)
#define NS_RETRAM_ALIAS_BASE		(0x0A080000)
#define RETRAM_SZ			(0x20000)		/* 128KB */

#define S_SRAM2_ALIAS_BASE		(0x0E060000)
#define NS_SRAM2_ALIAS_BASE		(0x0A060000)
#define SRAM2_SZ			(0x20000)		/* 128KB */

#define S_SRAM1_ALIAS_BASE		(0x0E040000)
#define NS_SRAM1_ALIAS_BASE		(0x0A040000)
#define SRAM1_SZ			(0x20000)		/* 128KB */

#define S_SYSRAM_ALIAS_BASE		(0x0E000000)
#define NS_SYSRAM_ALIAS_BASE		(0x0A000000)
#define SYSRAM_SZ			(0x40000)		/* 256KB */

#define S_BKPSRAM_ALIAS_BASE		(0x52000000)
#define NS_BKPSRAM_ALIAS_BASE		(0x42000000)
#define BKPSRAM_SZ			(0x2000)		/* 8KB */

#define S_BKPREG_ALIAS_BASE		(0x56010000 + 0x100)	/* tamp base + bkpreg offset */
#define NS_BKPREG_ALIAS_BASE		(0x46010000 + 0x100)
#define BKPREG_SZ			(0x80)			/* 128B */

#define OSPI_MEM_BASE			(0x60000000)

#define NS_DDR_ALIAS_BASE		(0x80000000)

#define FLASH_RETRAM_BASE		S_RETRAM_ALIAS_BASE
#define FLASH_RETRAM_CLK		CK_BUS_RETRAM
#define FLASH_RETRAM_SIZE		RETRAM_SZ	/* 128 kB */
#define FLASH_RETRAM_SECTOR_SIZE	(0x0000100)	/* 256 B */
#define FLASH_RETRAM_PROGRAM_UNIT	(0x1)		/* Minimum write size */

#define FLASH_BKPSRAM_BASE		S_BKPSRAM_ALIAS_BASE
#define FLASH_BKPSRAM_CLK		CK_BUS_BKPSRAM
#define FLASH_BKPSRAM_SIZE		BKPSRAM_SZ	/* 8 kB */
#define FLASH_BKPSRAM_SECTOR_SIZE	(0x0000100)	/* 256 B */
#define FLASH_BKPSRAM_PROGRAM_UNIT	(0x1)		/* Minimum write size */

#define FLASH_BKPREG_BASE		S_BKPREG_ALIAS_BASE
#define FLASH_BKPREG_CLK		CK_BUS_RTC
#define FLASH_BKPREG_SIZE		BKPREG_SZ	/* 128 B */
#define FLASH_BKPREG_SECTOR_SIZE	(0x4)		/* 32-bit backup registers */
#define FLASH_BKPREG_PROGRAM_UNIT	(0x4)		/* Minimum write size */

#define FLASH_DDR_BASE			NS_DDR_ALIAS_BASE
#define FLASH_DDR_CLK			CLK_UNDEF

#if STM32_M33TDCID
#if IPCC_LEGACY
#define IPCC_IRQ_LEGACY			DT_IRQN(DT_NODELABEL(ipcc1))
#define IPCC_IRQ                        RESERVED_309
#else
#define IPCC_IRQ			DT_IRQN(DT_NODELABEL(ipcc1))
#define IPCC_IRQ_LEGACY                 RESERVED_309
#endif
#define EXTI2_IWDG_1			BIT(15)
#endif

#endif /* __SOC_CONFIG_H__ */

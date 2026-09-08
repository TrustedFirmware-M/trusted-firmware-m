/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef DDRPHY_PHYINIT_USERCUSTOM_H
#define DDRPHY_PHYINIT_USERCUSTOM_H

#include <stdbool.h>
#include <stdint.h>

#include <cmsis.h>
#include <region_defs.h>
#include <ddrphy_csr_all_cdefines.h>
#include <stm32mp2_ddr.h>

/* Message Block Structure Definitions */
#if STM32MP_DDR3_TYPE
#include <mnpmusrammsgblock_ddr3.h>
#elif STM32MP_DDR4_TYPE
#include <mnpmusrammsgblock_ddr4.h>
#else /* STM32MP_LPDDR4_TYPE */
#include <mnpmusrammsgblock_lpddr4.h>
#endif /* STM32MP_DDR3_TYPE */

/*
 * -------------------------------------------------------------
 * Defines for Firmware Images
 * - indicate IMEM/DMEM address, size (bytes) and offsets.
 * -------------------------------------------------------------
 *
 * IMEM_SIZE max size of instruction memory.
 * DMEM_SIZE max size of data memory.
 *
 * IMEM_ST_ADDR start of IMEM address in memory.
 * DMEM_ST_ADDR start of DMEM address in memory.
 * DMEM_BIN_OFFSET start offset in DMEM memory (message block).
 */
#if STM32MP_DDR3_TYPE
#define IMEM_SIZE			0x4C28U
#define DMEM_SIZE			0x6C8U
#elif STM32MP_DDR4_TYPE
#define IMEM_SIZE			0x6D24U
#define DMEM_SIZE			0x6CCU
#else /* STM32MP_LPDDR4_TYPE */
#define IMEM_SIZE			0x7E50U
#define DMEM_SIZE			0x67CU
#endif /* STM32MP_DDR3_TYPE */
#define IMEM_ST_ADDR			0x50000U
#define DMEM_ST_ADDR			0x54000U
#define DMEM_BIN_OFFSET			0x200U

/*
 * ------------------
 * Type definitions
 * ------------------
 */

/* A structure used to SRAM memory address space */
enum return_offset_lastaddr {
	RETURN_OFFSET,
	RETURN_LASTADDR
};

/* Enumeration of instructions for PhyInit Register Interface */
enum reginstr {
	STARTTRACK,	/* Start register tracking */
	STOPTRACK,	/* Stop register tracking */
	SAVEREGS,	/* Save(read) tracked register values */
	RESTOREREGS,	/* Restore (write) saved register values */
} ;

/* Data structure to store register address/value pairs */
struct reg_addr_val {
	uint32_t	address;	/* Register address */
	uint16_t	value;		/* Register value */
};

/* Target CSR for the impedance value for ddrphy_phyinit_mapdrvstren() */
enum drvtype {
	DRVSTRENFSDQP,
	DRVSTRENFSDQN,
	ODTSTRENP,
	ODTSTRENN,
	ADRVSTRENP,
	ADRVSTRENN
};

/*
 * -------------------------------------------------------------
 * Fixed Function prototypes
 * -------------------------------------------------------------
 */
int ddrphy_phyinit_sequence(const struct stm32mp_ddr_config *config);
int ddrphy_phyinit_c_initphyconfig(const struct stm32mp_ddr_config *config,
				   struct pmu_smb_ddr_1d *mb_ddr_1d);
void ddrphy_phyinit_d_loadimem(void);
int ddrphy_phyinit_f_loaddmem(const struct stm32mp_ddr_config *config,
			      struct pmu_smb_ddr_1d *mb_ddr_1d);
int ddrphy_phyinit_g_execfw(void);
void ddrphy_phyinit_i_loadpieimage(const struct stm32mp_ddr_config *config);
void ddrphy_phyinit_loadpieprodcode(void);
int ddrphy_phyinit_mapdrvstren(uint32_t drvstren_ohm, enum drvtype targetcsr);
int ddrphy_phyinit_calcmb(const struct stm32mp_ddr_config *config,
			  struct pmu_smb_ddr_1d *mb_ddr_1d);
void ddrphy_phyinit_writeoutmem(uint32_t *mem, uint32_t mem_offset, uint32_t mem_size);
void ddrphy_phyinit_writeoutmsgblk(uint16_t *mem, uint32_t mem_offset, uint32_t mem_size);
int ddrphy_phyinit_isdbytedisabled(const struct stm32mp_ddr_config *config,
				   struct pmu_smb_ddr_1d *mb_ddr_1d, uint32_t dbytenumber);
void ddrphy_phyinit_usercustom_custompretrain(const struct stm32mp_ddr_config *config);
int ddrphy_phyinit_usercustom_g_waitfwdone(void);

#endif /* DDRPHY_PHYINIT_USERCUSTOM_H */

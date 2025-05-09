/*
 * Copyright (c) 2019-2024 Arm Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __PLATFORM_REGS_H__
#define __PLATFORM_REGS_H__

#include <stdint.h>

/* Secure Access Configuration Register Block */
struct rse_sacfg_t {
    volatile uint32_t spcsecctrl;     /* 0x000 (R/W) Secure Privilege Controller
                                                     Secure Configuration Control
                                                     register */
    volatile uint32_t buswait;        /* 0x004 (R/W) Bus Access wait control */
    volatile uint32_t reserved0[2];
    volatile uint32_t secrespcfg;     /* 0x010 (R/W) Security Violation Response
                                       *             Configuration register */
    volatile uint32_t nsccfg;         /* 0x014 (R/W) Non Secure Callable
                                       *             Configuration for IDAU */
    volatile uint32_t reserved1;
    volatile uint32_t secmpcintstat;  /* 0x01C (R/ ) Secure MPC IRQ Status */
    volatile uint32_t secppcintstat;  /* 0x020 (R/ ) Secure PPC IRQ Status */
    volatile uint32_t secppcintclr;   /* 0x024 (R/W) Secure PPC IRQ Clear */
    volatile uint32_t secppcinten;    /* 0x028 (R/W) Secure PPC IRQ Enable */
    volatile uint32_t reserved2;
    volatile uint32_t secmscintstat;  /* 0x030 (R/ ) Secure MSC IRQ Status */
    volatile uint32_t secmscintclr;   /* 0x034 (R/W) Secure MSC IRQ Clear */
    volatile uint32_t secmscinten;    /* 0x038 (R/W) Secure MSC IRQ Enable */
    volatile uint32_t reserved3;
    volatile uint32_t brgintstat;     /* 0x040 (R/ ) Bridge Buffer Error IRQ
                                       *             Status */
    volatile uint32_t brgintclr;      /* 0x044 (R/W) Bridge Buffer Error IRQ
                                       *             Clear */
    volatile uint32_t brginten;       /* 0x048 (R/W) Bridge Buffer Error IRQ
                                       *             Enable */
    volatile uint32_t reserved4;
    volatile uint32_t mainnsppc0;     /* 0x050 (R/W) Non-secure Access
                                       *             Peripheral Protection
                                       *             Control 0 on the Main
                                       *             Interconnect */
    volatile uint32_t reserved5[3];
    volatile uint32_t mainnsppcexp0;  /* 0x060 (R/W) Expansion 0 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on the
                                       *             Main Interconnect */
    volatile uint32_t mainnsppcexp1;  /* 0x064 (R/W) Expansion 1 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on the
                                       *             Main Interconnect */
    volatile uint32_t mainnsppcexp2;  /* 0x068 (R/W) Expansion 2 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on the
                                       *             Main Interconnect */
    volatile uint32_t mainnsppcexp3;  /* 0x06C (R/W) Expansion 3 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on the
                                       *             Main Interconnect */
    volatile uint32_t periphnsppc0;   /* 0x070 (R/W) Non-secure Access
                                       *             Peripheral Protection
                                       *             Control 0 on the Peripheral
                                       *             Interconnect */
    volatile uint32_t periphnsppc1;   /* 0x074 (R/W) Non-secure Access
                                       *             Peripheral Protection
                                       *             Control 1 on the Peripheral
                                       *             Interconnect */
    volatile uint32_t npuspporsl;     /* 0x078 (R/W) Secure Access
                                       *             NPU Security Level Reset
                                       *             State Control */
    volatile uint32_t reserved6;
    volatile uint32_t periphnsppcexp0;/* 0x080 (R/W) Expansion 0 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on
                                       *             Peripheral Bus */
    volatile uint32_t periphnsppcexp1;/* 0x084 (R/W) Expansion 1 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on
                                       *             Peripheral Bus */
    volatile uint32_t periphnsppcexp2;/* 0x088 (R/W) Expansion 2 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on
                                       *             Peripheral Bus */
    volatile uint32_t periphnsppcexp3;/* 0x08C (R/W) Expansion 3 Non-secure
                                       *             Access Peripheral
                                       *             Protection Control on
                                       *             Peripheral Bus */
    volatile uint32_t mainspppc0;     /* 0x090 (R/W) Secure Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control 0 on Main
                                       *             Interconnect */
    volatile uint32_t reserved7[3];
    volatile uint32_t mainspppcexp0;  /* 0x0A0 (R/W) Expansion 0 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Main
                                       *             Interconnect */
    volatile uint32_t mainspppcexp1;  /* 0x0A4 (R/W) Expansion 1 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Main
                                       *             Interconnect */
    volatile uint32_t mainspppcexp2;  /* 0x0A8 (R/W) Expansion 2 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Main
                                       *             Interconnect */
    volatile uint32_t mainspppcexp3;  /* 0x0AC (R/W) Expansion 3 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Main
                                       *             Interconnect */
    volatile uint32_t periphspppc0;   /* 0x0B0 (R/W) Secure Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control 0 on
                                       *             Peripheral Interconnect */
    volatile uint32_t periphspppc1;   /* 0x0B4 (R/W) Secure Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control 1 on
                                       *             Peripheral Interconnect */
    volatile uint32_t npuspporpl;     /* 0x0B8 (R/W) Secure Access NPU
                                       *             Privilege Level
                                       *             Reset State Control */
    volatile uint32_t ns_npu0porpl;   /* 0x0BC (R/W) Non Secure Access NPU
                                       *             Privilege Level
                                       *             Reset State Control */
    volatile uint32_t periphspppcexp0;/* 0x0C0 (R/W) Expansion 0 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Peripheral
                                       *             Interconnect */
    volatile uint32_t periphspppcexp1;/* 0x0C4 (R/W) Expansion 1 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Peripheral
                                       *             Interconnect */
    volatile uint32_t periphspppcexp2;/* 0x0C8 (R/W) Expansion 2 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Peripheral
                                       *             Interconnect */
    volatile uint32_t periphspppcexp3;/* 0x0CC (R/W) Expansion 3 Secure
                                       *             Unprivileged Access
                                       *             Peripheral Protection
                                       *             Control on Peripheral
                                       *             Interconnect */
    volatile uint32_t nsmscexp;       /* 0x0D0 (R/W) Expansion MSC Non-Secure
                                       *             Configuration */
    volatile uint32_t reserved9[959];
    volatile uint32_t pidr4;          /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved10[3];
    volatile uint32_t pidr0;          /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;          /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;          /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;          /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;          /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;          /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;          /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;          /* 0xFFC (R/ ) Component ID 3 */
};

/* PPC interrupt position mask */
#define PERIPH_PPC0_INT_POS_MASK     (1UL << 0)
#define PERIPH_PPC1_INT_POS_MASK     (1UL << 1)
#define PERIPH_PPCEXP0_INT_POS_MASK  (1UL << 4)
#define PERIPH_PPCEXP1_INT_POS_MASK  (1UL << 5)
#define PERIPH_PPCEXP2_INT_POS_MASK  (1UL << 6)
#define PERIPH_PPCEXP3_INT_POS_MASK  (1UL << 7)
#define MAIN_PPC0_INT_POS_MASK       (1UL << 16)
#define MAIN_PPCEXP0_INT_POS_MASK    (1UL << 20)
#define MAIN_PPCEXP1_INT_POS_MASK    (1UL << 21)
#define MAIN_PPCEXP2_INT_POS_MASK    (1UL << 22)
#define MAIN_PPCEXP3_INT_POS_MASK    (1UL << 23)

/* Non-secure Access Configuration Register Block */
struct rse_nsacfg_t {
    volatile uint32_t reserved0[36];
    volatile uint32_t mainnspppc0;     /* 0x090 (R/W) Non-secure Unprivileged
                                        *             Access Peripheral
                                        *             Protection Control 0 on
                                        *             Main Interconnect */
    volatile uint32_t reserved1[3];

    volatile uint32_t mainnspppcexp0;  /* 0x0A0 (R/W) Expansion 0 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Main
                                        *             Interconnect */
    volatile uint32_t mainnspppcexp1;  /* 0x0A4 (R/W) Expansion 1 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Main
                                        *             Interconnect */
    volatile uint32_t mainnspppcexp2;  /* 0x0A8 (R/W) Expansion 2 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Main
                                        *             Interconnect */
    volatile uint32_t mainnspppcexp3;  /* 0x0AC (R/W) Expansion 3 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Main
                                        *             Interconnect */
    volatile uint32_t periphnspppc0;   /* 0x0B0 (R/W) Non-secure Unprivileged
                                        *             Access Peripheral
                                        *             Protection Control 0 on
                                        *             Peripheral Interconnect */
    volatile uint32_t periphnspppc1;   /* 0x0B4 (R/W) Non-secure Unprivileged
                                        *             Access Peripheral
                                        *             Protection Control 1 on
                                        *             Peripheral Interconnect */
    volatile uint32_t npunsporpl;      /* 0x0B8 (R/W) Non-secure Access NPU
                                        *             Privilege Level
                                        *             Reset State Control */
    volatile uint32_t reserved2;
    volatile uint32_t periphnspppcexp0;/* 0x0C0 (R/W) Expansion 0 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Peripheral
                                        *             Interconnect */
    volatile uint32_t periphnspppcexp1;/* 0x0C4 (R/W) Expansion 1 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Peripheral
                                        *             Interconnect */
    volatile uint32_t periphnspppcexp2;/* 0x0C8 (R/W) Expansion 2 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Peripheral
                                        *             Interconnect */
    volatile uint32_t periphnspppcexp3;/* 0x0CC (R/W) Expansion 3 Non-secure
                                        *             Unprivileged Access
                                        *             Peripheral Protection
                                        *             Control on Peripheral
                                        *             Interconnect */
    volatile uint32_t reserved3[960];
    volatile uint32_t pidr4;           /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved4[3];
    volatile uint32_t pidr0;           /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;           /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;           /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;           /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;           /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;           /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;           /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;           /* 0xFFC (R/ ) Component ID 3 */
};

/* MAIN PPC0 peripherals definition */
/* End MAIN PPC0 peripherals definition */

/* MAIN PPCEXP0 peripherals definition */
/* End MAIN PPCEXP0 peripherals definition */

/* MAIN PPCEXP1 peripherals definition */
/* End MAIN PPCEXP1 peripherals definition */

/* MAIN PPCEXP2 peripherals definition */
/* End MAIN PPCEXP2 peripherals definition */

/* MAIN PPCEXP3 peripherals definition */
/* End MAIN PPCEXP3 peripherals definition */

/* PERIPH PPC0 peripherals definition */
#define SYSTEM_TIMER0_PERIPH_PPC0_POS_MASK         (1UL << 0)
#define SYSTEM_TIMER1_PERIPH_PPC0_POS_MASK         (1UL << 1)
#define SYSTEM_TIMER2_PERIPH_PPC0_POS_MASK         (1UL << 2)
#define SYSTEM_TIMER3_PERIPH_PPC0_POS_MASK         (1UL << 5)
/* There are separate secure and non-secure watchdog peripherals, so this bit
 * can only be used in the unprivileged access registers. */
/* End PERIPH PPC0 peripherals definition */

/* PERIPH PPC1 peripherals definition */
#define SLOWCLK_TIMER_PERIPH_PPC1_POS_MASK         (1UL << 0)
/* End PERIPH PPC1 peripherals definition */

/* PERIPH PPCEXP0 peripherals definition */
#define GPIO0_PERIPH_PPCEXP0_POS_MASK              (1UL << 0)
#define GPIO1_PERIPH_PPCEXP0_POS_MASK              (1UL << 1)
/* End PERIPH PPCEXP0 peripherals definition */

/* PERIPH PPCEXP1 peripherals definition */
/* End PERIPH PPCEXP1 peripherals definition */

/* PERIPH PPCEXP2 peripherals definition */
/* End PERIPH PPCEXP2 peripherals definition */

/* PERIPH PPCEXP3 peripherals definition */
/* End PERIPH PPCEXP3 peripherals definition */

struct cpu0_pwrctrl_t {
    volatile uint32_t cpupwrcfg;      /* 0x000 (R/W) CPU 0 Local Power
                                       *             Configuration */
    volatile uint32_t reserved0[1011];
    volatile uint32_t pidr4;          /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved1[3];
    volatile uint32_t pidr0;          /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;          /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;          /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;          /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;          /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;          /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;          /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;          /* 0xFFC (R/ ) Component ID 3 */
};

struct cpu0_secctrl_t {
    volatile uint32_t cpuseccfg;      /* 0x000 (R/W) CPU Local Security
                                       *             Configuration */
    volatile uint32_t reserved0[1011];
    volatile uint32_t pidr4;          /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved1[3];
    volatile uint32_t pidr0;          /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;          /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;          /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;          /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;          /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;          /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;          /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;          /* 0xFFC (R/ ) Component ID 3 */
};

/* CPUSECCFG bit position masks */
#define CPUSECCFG_LOCKSVTAIRCR_POS_MASK  (1UL << 0)
#define CPUSECCFG_LOCKSAU_POS_MASK       (1UL << 1)
#define CPUSECCFG_LOCKSMPU_POS_MASK      (1UL << 2)
#define CPUSECCFG_LOCKTCM_POS_MASK       (1UL << 3)
#define CPUSECCFG_LOCKITGU_POS_MASK      (1UL << 4)
#define CPUSECCFG_LOCKDTGU_POS_MASK      (1UL << 5)

struct rse_sysinfo_t {
    volatile uint32_t soc_identity;   /* 0x000 (R/ ) SoC Identity Register */
    volatile uint32_t sys_config0;    /* 0x004 (R/ ) System Hardware
                                       *             Configuration 0 */
    volatile uint32_t sys_config1;    /* 0x008 (R/ ) System Hardware
                                       *             Configuration 1 */
    volatile uint32_t sys_config2;    /* 0x00C (R/ ) System Hardware
                                       *             Configuration 2 */
    volatile uint32_t reserved0[1005];
    volatile uint32_t iidr;           /* 0xFC8 (R/ ) Subsystem Implementation
                                       *             Identity */
    volatile uint32_t reserved1;
    volatile uint32_t pidr4;          /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved2[3];
    volatile uint32_t pidr0;          /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;          /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;          /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;          /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;          /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;          /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;          /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;          /* 0xFFC (R/ ) Component ID 3 */
};

struct rse_sysctrl_t {
    volatile uint32_t secdbgstat;        /* 0x000 (R/ ) Secure Debug
                                          *             Configuration Status */
    volatile uint32_t secdbgset;         /* 0x004 (R/W) Secure Debug
                                          *             Configuration Set */
    volatile uint32_t secdbgclr;         /* 0x008 ( /W) Secure Debug
                                          *             Configuration Clear */
    volatile uint32_t scsecctrl;         /* 0x00C (R/W) System Control Security
                                          *             Controls */
    volatile uint32_t clk_cfg0;          /* 0x010 (R/W) Clock Configuration 0 */
    volatile uint32_t clk_cfg1;          /* 0x014 (R/W) Clock Configuration 1 */
    volatile uint32_t clock_force;       /* 0x018 (R/W) Clock Forces */
    volatile uint32_t clk_cfg2;          /* 0x01C (R/W) Clock Configuration 2 */
    volatile uint32_t reserved0[56];
    volatile uint32_t reset_syndrome;    /* 0x100 (R/W) Reset syndrome */
    volatile uint32_t reset_mask;        /* 0x104 (R/W) Reset mask */
    volatile uint32_t swreset;           /* 0x108 ( /W) Software Reset */
    volatile uint32_t gretreg;           /* 0x10C (R/W) General Purpose
                                          *             Retention */
    volatile uint32_t initsvtor0;        /* 0x110 (R/W) CPU 0 Initial Secure
                                          *             Reset Vector Register */
    volatile uint32_t reserved1[3];
    volatile uint32_t cpuwait;           /* 0x120 (R/W) CPU Boot Wait Control */
    volatile uint32_t nmi_enable;        /* 0x124 (R/W) Non Maskable Interrupts
                                          *             Enable */
    volatile uint32_t ppuintstat;        /* 0x128 (R/W) PPU Interrupt Status */
    volatile uint32_t reserved2[52];
    volatile uint32_t pwrctrl;           /* 0x1FC (R/W) Power Configuration and
                                          *             Control */
    volatile uint32_t pdcm_pd_sys_sense; /* 0x200 (R/W) PDCM PD_SYS
                                          *             Sensitivity */
    volatile uint32_t pdcm_pd_cpu0_sense;/* 0x204 (R/ ) PDCM PD_CPU0
                                          *             Sensitivity */
    volatile uint32_t reserved3[3];
    volatile uint32_t pdcm_pd_vmr0_sense;/* 0x214 (R/W) PDCM PD_VMR0
                                          *             Sensitivity */
    volatile uint32_t pdcm_pd_vmr1_sense;/* 0x218 (R/W) PDCM PD_VMR1
                                          *             Sensitivity */
    volatile uint32_t reserved4[12];
    volatile uint32_t pdcm_pd_mgmt_sense;/* 0x24C (R/W) PDCM PD_MGMT
                                          *             Sensitivity */
    volatile uint32_t gretexreg;         /* 0x250 (R/W) General Purpose
                                          *             Retention Expansion */
    volatile uint32_t dma_boot_en;       /* 0x254 (R/W) DMA-350 Boot Enable
                                          *             Static Config */
    volatile uint32_t dma_boot_addr;     /* 0x258 (R/W) DMA-350 Boot Address
                                          *             Static Config */
    volatile uint32_t lcm_dcu_force_dis; /* 0x25C (R/W) LCM DCU Force
                                          *             Disable */
    volatile uint32_t reserved5[860];
    volatile uint32_t pidr4;             /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved6[3];
    volatile uint32_t pidr0;             /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;             /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;             /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;             /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;             /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;             /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;             /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;             /* 0xFFC (R/ ) Component ID 3 */
};

/* Bit to mark boot failure (SWSYN) in swreset reg */
#define SWSYN_FAILED_BOOT_BIT_POS      24
/* Bit to notify boot to enter debug state (SWSYN) in swreset reg */
#define SWSYN_DEBUG_STATE_IN_BOOT_BIT_POS 25
#define CLK_CFG1_SYSCLKCFG_POS         0
#define CLK_CFG1_SYSCLKCFG_MASK        (0xFUL << CLK_CFG1_SYSCLKCFG_POS)
#define CLK_CFG1_AONCLKCFG_POS         4
#define CLK_CFG1_AONCLKCFG_MASK        (0xFUL << CLK_CFG1_AONCLKCFG_POS)
#define CLK_CFG1_SYSCLKCFGSTATUS_POS   16
#define CLK_CFG1_SYSCLKCFGSTATUS_MASK  (0xFUL << CLK_CFG1_SYSCLKCFGSTATUS_POS)
#define CLK_CFG1_AONCLKCFGSTATUS_POS   20
#define CLK_CFG1_AONCLKCFGSTATUS_MASK  (0xFUL << CLK_CFG1_AONCLKCFGSTATUS_POS)

struct rse_ewic_t {
    volatile uint32_t ewic_cr;        /* 0x000 (R/W) EWIC Control */
    volatile uint32_t ewic_ascr;      /* 0x004 (R/W) Automatic Sequence
                                       *             Control */
    volatile uint32_t ewic_clrmask;   /* 0x008 ( /W) Clear All Mask */
    volatile uint32_t ewic_numid;     /* 0x00C (R/ ) ID Register for the number
                                       *             of events supported */
    volatile uint32_t reserved0[124];
    volatile uint32_t ewic_maska;     /* 0x200 (R/W) Set which internal events
                                       *             cause wakeup */
    volatile uint32_t ewic_mask[15];  /* 0x204 (R/W) Set which external
                                       *             interrupts cause wakeup
                                       *             Only the first (total
                                       *             system IRQ number)/32
                                       *             registers are implemented
                                       *             in array */
    volatile uint32_t reserved1[112];
    volatile uint32_t ewic_penda;     /* 0x400 (R/ ) Shows which internal
                                       *             interrupts were pended
                                       *             while the EWIC was
                                       *             enabled */

    volatile uint32_t ewic_pend[15];   /* 0x404 (R/W) Shows which external
                                       *             interrupts were pended
                                       *             while the EWIC was
                                       *             enabled
                                       *             Only the first (total
                                       *             system IRQ number)/32
                                       *             registers are implemented
                                       *             in array */
    volatile uint32_t reserved2[112];
    volatile uint32_t ewic_psr;       /* 0x600 (R/ ) Pending Summary */
    volatile uint32_t reserved3[575];
    volatile uint32_t itctrl;         /* 0xF00 (R/ ) Integration Mode Control */
    volatile uint32_t reserved4[39];
    volatile uint32_t claimset;       /* 0xFA0 (R/W) Claim Tag Set */
    volatile uint32_t claimclr;       /* 0xFA4 (R/W) Claim Tag Clear */
    volatile uint32_t devaff0;        /* 0xFA8 (R/ ) Device Affinity 0 */
    volatile uint32_t devaff1;        /* 0xFAC (R/ ) Device Affinity 1 */
    volatile uint32_t lar;            /* 0xFB0 ( /W) Lock Access */
    volatile uint32_t lsr;            /* 0xFB4 (R/ ) Lock Status */
    volatile uint32_t authstatus;     /* 0xFB8 (R/ ) Authentication Status */
    volatile uint32_t devarch;        /* 0xFBC (R/ ) Device Architecture */
    volatile uint32_t devid2;         /* 0xFC0 (R/ ) Device Configuration 2 */
    volatile uint32_t devid1;         /* 0xFC4 (R/ ) Device Configuration 1 */
    volatile uint32_t devid;          /* 0xFC8 (R/ ) Device Configuration */
    volatile uint32_t devtype;        /* 0xFCC (R/ ) Device Type */
    volatile uint32_t pidr4;          /* 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved5[3];
    volatile uint32_t pidr0;          /* 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;          /* 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;          /* 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;          /* 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;          /* 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;          /* 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;          /* 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;          /* 0xFFC (R/ ) Component ID 3 */
};
#endif /* __PLATFORM_REGS_H__ */

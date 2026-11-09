/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Configurations
 ******************************************************************************/

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 1.0.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/* Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (96000000UL)
#endif

/*! @brief External XTAL0 (OSC0/SYSOSC) clock frequency.
 *
 * The XTAL0/EXTAL0 (OSC0/SYSOSC) clock frequency in Hz. When the clock is set up, use the
 * function CLOCK_SetXtal0Freq to set the value in the clock driver. For example,
 * if XTAL0 is 8 MHz:
 * @code
 * CLOCK_InitSysOsc(...);
 * CLOCK_SetXtal0Freq(80000000);
 * @endcode
 *
 * This is important for the multicore platforms where only one core needs to set up the
 * OSC0/SYSOSC using CLOCK_InitSysOsc. All other cores need to call the CLOCK_SetXtal0Freq
 * to get a valid clock frequency.
 */
extern volatile uint32_t g_xtal0Freq;

/*! @brief External XTAL32/EXTAL32 clock frequency.
 *
 * The XTAL32/EXTAL32 clock frequency in Hz. When the clock is set up, use the
 * function CLOCK_SetXtal32Freq to set the value in the clock driver.
 *
 * This is important for the multicore platforms where only one core needs to set up
 * the clock. All other cores need to call the CLOCK_SetXtal32Freq
 * to get a valid clock frequency.
 */
extern volatile uint32_t g_xtal32Freq;

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS \
    {               \
        kCLOCK_Dma0 \
    }

/*! @brief Clock ip name array for SYSPM. */
#define SYSPM_CLOCKS  \
    {                 \
        kCLOCK_Syspm0 \
    }

/*! @brief Clock ip name array for SFA. */
#define SFA_CLOCKS               \
    {                            \
        kCLOCK_Sfa0, kCLOCK_Sfa1 \
    }

/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS               \
    {                            \
        kCLOCK_Crc0, kCLOCK_Crc1 \
    }

/*! @brief Clock ip name array for TPM. */
#define TPM_CLOCKS                                                      \
    {                                                                   \
        kCLOCK_Tpm0, kCLOCK_Tpm1, kCLOCK_Tpm2, kCLOCK_Tpm3, kCLOCK_Tpm4 \
    }

/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                 \
    {                                \
        kCLOCK_Lpi2c0, kCLOCK_Lpi2c1 \
    }

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                \
    {                                               \
        kCLOCK_Lpspi0, kCLOCK_Lpspi1, kCLOCK_Lpspi2 \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                  \
    {                                  \
        kCLOCK_Lpuart0, kCLOCK_Lpuart1 \
    }

/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS                                             \
    {                                                           \
        kCLOCK_PortA, kCLOCK_PortB, kCLOCK_PortC, kCLOCK_NOGATE \
    }

/*! @brief Clock ip name array for LPADC. */
#define LPADC_CLOCKS  \
    {                 \
        kCLOCK_Lpadc0 \
    }

/*! @brief Clock ip name array for LPCMP. */
#define LPCMP_CLOCKS \
    {                \
        kCLOCK_Cmp0  \
    }

/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS                                             \
    {                                                           \
        kCLOCK_GpioA, kCLOCK_GpioB, kCLOCK_GpioC, kCLOCK_NOGATE \
    }

/*! @brief Clock ip name array for LPIT. */
#define LPIT_CLOCKS  \
    {                \
        kCLOCK_Lpit0 \
    }

/*! @brief Clock ip name array for RF. */
#define RF_CLOCKS     \
    {                 \
        kCLOCK_NOGATE \
    }

/*! @brief Clock ip name array for WDOG. */
#define WDOG_CLOCKS                \
    {                              \
        kCLOCK_Wdog0, kCLOCK_Wdog1 \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS \
    {                  \
        kCLOCK_Can0    \
    }

/*! @brief Clock ip name array for TSTMR. */
#define TSTMR_CLOCKS                                \
    {                                               \
        kCLOCK_Tstmr0, kCLOCK_NOGATE, kCLOCK_NOGATE \
    }

/*! @brief Clock ip name array for EWM. */
#define EWM_CLOCKS  \
    {               \
        kCLOCK_Ewm0 \
    }

/*! @brief Clock ip name array for SEMA. */
#define SEMA42_CLOCKS \
    {                 \
        kCLOCK_Sema   \
    }

/*! @brief Clock gate name array for MU. */
#define MU_CLOCKS  \
    {              \
        kCLOCK_Mu0, kCLOCK_Mu0, kCLOCK_Mu1, kCLOCK_Mu1 \
    }

/*! @brief Clock ip name array for LPTMR. */
#define LPTMR_CLOCKS                 \
    {                                \
        kCLOCK_Lptmr0, kCLOCK_Lptmr1 \
    }

/*! @brief Clock ip name array for TRNG. */
#define TRNG_CLOCKS   \
    {                 \
        kCLOCK_NOGATE \
    }

/*! @brief Clock ip name array for AOI. */
#define AOI_CLOCKS  \
    {               \
        kCLOCK_Aoi0 \
    }

/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS      \
    {                   \
        kCLOCK_Flexpwm0 \
    }

/*! @brief Clock ip name array for GDET. */
#define GDET_CLOCKS         \
    {                       \
        kCLOCK_Gdet_wrapper \
    }

/*! @brief Clock name used to get clock frequency.
 *
 * These clocks source would be generated from SCG module.
 */
typedef enum _clock_name
{
    /* ----------------------------- System layer clock -------------------------------*/
    kCLOCK_CoreSysClk, /*!< Cortex M33 clock. */
    kCLOCK_SlowClk,    /*!< SLOW_CLK with DIVSLOW. */
    kCLOCK_PlatClk,    /*!< PLAT_CLK. */
    kCLOCK_SysClk,     /*!< SYS_CLK. */
    kCLOCK_BusClk,     /*!< BUS_CLK with DIVBUS. */

    /* For SCG CLK intput */
    kCLOCK_ScgSysOscClk, /*!< SCG system OSC clock.                               */
    kCLOCK_ScgSircClk,   /*!< SCG SIRC clock.                                     */
    kCLOCK_ScgFircClk,   /*!< SCG FIRC clock.                                     */
    kCLOCK_RtcOscClk,    /*!< RTC OSC clock.                                      */
} clock_name_t;

/*!
 * @brief Clock source for peripherals that support various clock selections.
 *
 * These options are for MRCC->XX[CC]
 */
typedef enum _clock_ip_control
{
    kCLOCK_IpClkControl_fun0 = MRCC_CC(0U), /*!< Peripheral clocks are disabled, module does not stall low power mode entry. */
    kCLOCK_IpClkControl_fun1 = MRCC_CC(1U), /*!< Peripheral clocks are enabled, module does not stall low power mode entry. */
    kCLOCK_IpClkControl_fun2 = MRCC_CC(2U), /*!< Peripheral clocks are enabled unless module is idle, low power mode entry
                                      stalls until module is idle. */
    kCLOCK_IpClkControl_fun3 =
        MRCC_CC(3U), /*!<  Peripheral clocks are enabled unless in SLEEP (or lower) mode, low power mode entry stalls until
               module is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not
               stall low power mode entry unless entering DEEPSLEEP (or lower) mode. */
} clock_ip_control_t;

/*!
 * @brief Clock source for peripherals that support various clock selections.
 *
 * These options are for MRCC->XX[MUX].
 */
typedef enum _clock_ip_src
{
    kCLOCK_IpSrcFro6M   = 0U, /*!< FRO 6M clock. */
    kCLOCK_IpSrcFro192M = 1U, /*!< FRO 192M clock. */
    kCLOCK_IpSrcSoscClk = 2U, /*!< OSC RF clock. */
    kCLOCK_IpSrc32kClk  = 3U, /*!< 32k Clk clock. */
    kCLOCK_IpSrcFro200M = 4U, /*!< FRO_200M clock for CAN. */
    kCLOCK_IpSrc1M      = 5U, /*!< 1MHZ is derived out of FRO6M. */
} clock_ip_src_t;

/*!
 * @brief "IP Connector name definition used for clock gate, clock source
 * and clock divider setting. It is defined as the corresponding register address.
 */
#define MAKE_MRCC_REGADDR(base, offset) ((base) + (offset))

#if defined(FSL_SDK_FORCE_CLK_DRIVER_NS_ACCESS) && FSL_SDK_FORCE_CLK_DRIVER_NS_ACCESS
#define CLOCK_REG(name) ((*(volatile uint32_t *)((uint32_t)(name) & ~0x10000000UL)))
#else
#define CLOCK_REG(name) (*(volatile uint32_t *)((uint32_t)(name)))
#endif

/*!
 * @brief Clock IP name.
 */
typedef enum _clock_ip_name
{
    kCLOCK_NOGATE          = 0U,                                    /*!< No clock gate for the IP in MRCC */
    kCLOCK_Lpadc0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xA0),  /*!< Clock adc0 */
    kCLOCK_Aoi0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xA8),  /*!< Clock aoi0 */
    kCLOCK_Atx0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xB0),  /*!< Clock atx0 */
    kCLOCK_CLK_1M          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xB8),  /*!< Clock clk_1m */
    kCLOCK_CLK_6M          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xC0),  /*!< Clock clk_6m */
    kCLOCK_CLK_32M         = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xC8),  /*!< Clock clk_32m */
    kCLOCK_Cmp0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xD0),  /*!< Clock cmp0 */
    kCLOCK_Crc0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xD8),  /*!< Clock crc0 */
    kCLOCK_Crc1            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xE0),  /*!< Clock crc1 */
    kCLOCK_Data_stream_2p4 = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xE8),  /*!< Clock data_stream_2p4 */
    kCLOCK_Dma0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xF0),  /*!< Clock dma */
    kCLOCK_Dsp_ramc0       = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0xF8),  /*!< Clock dsp_ramc0 */
    kCLOCK_Edt_cc          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x100), /*!< Clock edt_cc */
    kCLOCK_Ewm0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x108), /*!< Clock ewm0 */
    kCLOCK_Ezramc_ram0     = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x110), /*!< Clock ezramc_ram0 */
    kCLOCK_Ezramc_ram1     = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x118), /*!< Clock ezramc_ram1 */
    kCLOCK_Ezramc_ram2     = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x120), /*!< Clock ezramc_ram2 */
    kCLOCK_Ezramc_ram3     = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x128), /*!< Clock ezramc_ram3 */
    kCLOCK_Can0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x130), /*!< Clock Can0 */
    kCLOCK_Flexpwm0        = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x138), /*!< Clock flexpwm0 */
    kCLOCK_Fmc             = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x140), /*!< Clock fmc */
    kCLOCK_Fro200m         = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x148), /*!< Clock FRO200M */
    kCLOCK_Fro_hf_div      = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x150), /*!< Clock fro_hf_div */
    kCLOCK_Gdet_wrapper    = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x158), /*!< Clock gdet_wrapper */
    kCLOCK_GpioA           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x160), /*!< Clock gpioA */
    kCLOCK_GpioB           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x168), /*!< Clock gpioB */
    kCLOCK_GpioC           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x170), /*!< Clock gpioC */
    kCLOCK_Intm            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x178), /*!< Clock intm */
    kCLOCK_Ipsync_Trng0    = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x180), /*!< Clock IPSYNC_TRNG0 */
    kCLOCK_Itrc            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x188), /*!< Clock itrc */
    kCLOCK_Lpi2c0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x190), /*!< Clock lpi2c0 */
    kCLOCK_Lpi2c1          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x198), /*!< Clock lpi2c1 */
    kCLOCK_Lpit0           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1A0), /*!< Clock lpit0 */
    kCLOCK_Lpspi0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1A8), /*!< Clock lpspi0 */
    kCLOCK_Lpspi1          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1B0), /*!< Clock lpspi1 */
    kCLOCK_Lpspi2          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1B8), /*!< Clock lpspi2 */
    kCLOCK_Lptmr0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1C0), /*!< Clock lptmr0 */
    kCLOCK_Lptmr1          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1C8), /*!< Clock lptmr1 */
    kCLOCK_Lpuart0         = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1D0), /*!< Clock lpuart0 */
    kCLOCK_Lpuart1         = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1D8), /*!< Clock lpuart1 */
    kCLOCK_Mtr             = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1E0), /*!< Clock mtr */
    kCLOCK_Mu0             = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1E8), /*!< Clock mu0 */
    kCLOCK_Mu1             = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1F0), /*!< Clock mu1 */
    kCLOCK_Pkc_Ram_Ctrl    = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x1F8), /*!< Clock pck_ram_ctrl */
    kCLOCK_Pkc_wrapper     = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x200), /*!< Clock pkc_wrapper */
    kCLOCK_PortA           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x208), /*!< Clock portA */
    kCLOCK_PortB           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x210), /*!< Clock portB */
    kCLOCK_PortC           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x218), /*!< Clock portC */
    kCLOCK_Romcp           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x220), /*!< Clock romcp */
    kCLOCK_Sema            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x228), /*!< Clock Sema */
    kCLOCK_Sfa0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x230), /*!< Clock sfa0 */
    kCLOCK_Sfa1            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x238), /*!< Clock sfa1 */
    kCLOCK_Sgi0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x240), /*!< Clock sgi0 */
    kCLOCK_Syspm0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x248), /*!< Clock syspm */
    kCLOCK_Tcu             = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x250), /*!< Clock Tcu */
    kCLOCK_Tpm0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x258), /*!< Clock tpm0 */
    kCLOCK_Tpm1            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x260), /*!< Clock tpm1 */
    kCLOCK_Tpm2            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x268), /*!< Clock tpm2 */
    kCLOCK_Tpm3            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x270), /*!< Clock tpm3 */
    kCLOCK_Tpm4            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x278), /*!< Clock tpm4 */
    kCLOCK_Trgmux0         = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x280), /*!< Clock trgmux0 */
    kCLOCK_Tstmr0          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x288), /*!< Clock tstmr0 */
    kCLOCK_Udf0            = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x290), /*!< Clock udf0 */
    kCLOCK_Uteal1          = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x298), /*!< Clock uteal_1 */
    kCLOCK_Wdog0           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x2A0), /*!< Clock wdog0 */
    kCLOCK_Wdog1           = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x2A8), /*!< Clock wdog1 */
    kCLOCK_Zenv_core       = MAKE_MRCC_REGADDR(MRCC_0_BASE, 0x2B0), /*!< Clock zenv_core */
} clock_ip_name_t;

/*!
 * @brief SCG status return codes.
 */
enum _scg_status
{
    kStatus_SCG_Busy       = MAKE_STATUS(kStatusGroup_SCG, 1), /*!< Clock is busy.  */
    kStatus_SCG_InvalidSrc = MAKE_STATUS(kStatusGroup_SCG, 2)  /*!< Invalid source. */
};

/*!
 * @brief SCG system clock type.
 */
typedef enum _scg_sys_clk
{
    kSCG_SysClkSlow,     /*!< System slow clock. */
    kSCG_SysClkBus,      /*!< Bus clock.         */
    kSCG_SysClkPlatform, /*!< Platform clock.    */
    kSCG_SysClkCore,     /*!< Core clock.        */
} scg_sys_clk_t;

/*!
 * @brief SCG system clock source.
 */
typedef enum _scg_sys_clk_src
{
    kSCG_SysClkSrcSysOsc = 1U, /*!< System OSC. */
    kSCG_SysClkSrcSirc   = 2U, /*!< Slow IRC.   */
    kSCG_SysClkSrcFirc   = 3U, /*!< Fast IRC.   */
    kSCG_SysClkSrcRosc   = 4U, /*!< RTC OSC. */
} scg_sys_clk_src_t;

/*!
 * @brief SCG system clock divider value.
 */
typedef enum _scg_sys_clk_div
{
    kSCG_SysClkDivBy1  = 0U,  /*!< Divided by 1.  */
    kSCG_SysClkDivBy2  = 1U,  /*!< Divided by 2.  */
    kSCG_SysClkDivBy3  = 2U,  /*!< Divided by 3.  */
    kSCG_SysClkDivBy4  = 3U,  /*!< Divided by 4.  */
    kSCG_SysClkDivBy5  = 4U,  /*!< Divided by 5.  */
    kSCG_SysClkDivBy6  = 5U,  /*!< Divided by 6.  */
    kSCG_SysClkDivBy7  = 6U,  /*!< Divided by 7.  */
    kSCG_SysClkDivBy8  = 7U,  /*!< Divided by 8.  */
    kSCG_SysClkDivBy9  = 8U,  /*!< Divided by 9.  */
    kSCG_SysClkDivBy10 = 9U,  /*!< Divided by 10. */
    kSCG_SysClkDivBy11 = 10U, /*!< Divided by 11. */
    kSCG_SysClkDivBy12 = 11U, /*!< Divided by 12. */
    kSCG_SysClkDivBy13 = 12U, /*!< Divided by 13. */
    kSCG_SysClkDivBy14 = 13U, /*!< Divided by 14. */
    kSCG_SysClkDivBy15 = 14U, /*!< Divided by 15. */
    kSCG_SysClkDivBy16 = 15U  /*!< Divided by 16. */
} scg_sys_clk_div_t;

/*!
 * @brief SCG system clock configuration.
 */
typedef struct _scg_sys_clk_config
{
    uint32_t divSlow : 4; /*!< Slow clock divider, see @ref scg_sys_clk_div_t. */
    uint32_t divBus : 4;  /*!< Bus clock divider, see @ref scg_sys_clk_div_t.  */
    uint32_t : 4;         /*!< Reserved. */
    uint32_t divPlat : 4; /*!< Plat clock divider (core#1), see @ref scg_sys_clk_div_t. */
    uint32_t divCore : 4; /*!< Core clock divider (core#0), see @ref scg_sys_clk_div_t. */
    uint32_t : 4;         /*!< Reserved. */
    uint32_t src : 3;     /*!< System clock source, see @ref scg_sys_clk_src_t. */
    uint32_t : 5;         /*!< reserved. */
} scg_sys_clk_config_t;

/*!
 * @brief SCG clock out configuration (CLKOUTSEL).
 */
typedef enum _clock_clkout_src
{
    kClockClkoutSelScgSlow   = 0U, /*!< SCG Slow clock. */
    kClockClkoutSelSosc      = 1U, /*!< System OSC.     */
    kClockClkoutSelSirc      = 2U, /*!< Slow IRC.       */
    kClockClkoutSelFirc      = 3U, /*!< Fast IRC.       */
    kClockClkoutSelScgRtcOsc = 4U, /*!< SCG RTC OSC clock. */
} clock_clkout_src_t;

/*!
 * @brief SCG system OSC monitor mode.
 */
typedef enum _scg_sosc_monitor_mode
{
    kSCG_SysOscMonitorDisable = 0U,                      /*!< Monitor disabled. */
    kSCG_SysOscMonitorInt     = SCG_SOSCCSR_SOSCCM_MASK, /*!< Interrupt when the SOSC error is detected. */
    kSCG_SysOscMonitorReset =
        SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK /*!< Reset when the SOSC error is detected.     */
} scg_sosc_monitor_mode_t;

/*! @brief SOSC enable mode. */
enum
{
    kSCG_SoscDisable       = 0,                         /*!< Disable SOSC clock.             */
    kSCG_SoscEnable        = SCG_SOSCCSR_SOSCEN_MASK,   /*!< Enable SOSC clock.              */
    kSCG_SoscEnableInSleep = SCG_SOSCCSR_SOSCSTEN_MASK, /*!< Enable SOSC in sleep mode.      */
};

/*!
 * @brief SCG system OSC configuration.
 */
typedef struct _scg_sosc_config
{
    uint32_t freq;                       /*!< System OSC frequency. */
    uint32_t enableMode;                 /*!< Enable mode, OR'ed value of _scg_sosc_enable_mode.  */
    scg_sosc_monitor_mode_t monitorMode; /*!< Clock monitor mode selected.     */
} scg_sosc_config_t;

/*!
 * @brief SCG ROSC monitor mode.
 */
typedef enum _scg_rosc_monitor_mode
{
    kSCG_RoscMonitorDisable = 0U,                      /*!< Monitor disabled. */
    kSCG_RoscMonitorInt     = SCG_ROSCCSR_ROSCCM_MASK, /*!< Interrupt when the RTC OSC error is detected. */
    kSCG_RoscMonitorReset =
        SCG_ROSCCSR_ROSCCM_MASK | SCG_ROSCCSR_ROSCCMRE_MASK /*!< Reset when the RTC OSC error is detected. */
} scg_rosc_monitor_mode_t;

/*!
 * @brief SCG ROSC configuration.
 */
typedef struct _scg_rosc_config
{
    scg_rosc_monitor_mode_t monitorMode; /*!< Clock monitor mode selected.     */
} scg_rosc_config_t;

/*! @brief SIRC enable mode. */
typedef enum _scg_sirc_enable_mode
{
    kSCG_SircDisableInSleep = 0,                         /*!< Disable SIRC clock.             */
    kSCG_SircEnableInSleep  = SCG_SIRCCSR_SIRCSTEN_MASK, /*!< Enable SIRC in sleep mode.      */
} scg_sirc_enable_mode_t;

/*!
 * @brief SCG slow IRC clock configuration.
 */
typedef struct _scg_sirc_config
{
    scg_sirc_enable_mode_t enableMode; /*!< Enable mode, OR'ed value of _scg_sirc_enable_mode. */
} scg_sirc_config_t;

/*!
 * @brief SCG fast IRC trim mode.
 */
typedef enum _scg_firc_trim_mode
{
    kSCG_FircTrimNonUpdate = SCG_FIRCCSR_FIRCTREN_MASK,
    /*!< FIRC trim enable but not enable trim value update. In this mode, the
     trim value is fixed to the initialized value which is defined by
     trimCoar and trimFine in configure structure \ref scg_firc_trim_config_t.*/

    kSCG_FircTrimUpdate = SCG_FIRCCSR_FIRCTREN_MASK | SCG_FIRCCSR_FIRCTRUP_MASK
    /*!< FIRC trim enable and trim value update enable. In this mode, the trim
     value is auto update. */

} scg_firc_trim_mode_t;

/*!
 * @brief SCG fast IRC trim source.
 */
typedef enum _scg_firc_trim_src
{
    kSCG_FircTrimSrcSysOsc = 2U, /*!< System OSC.                 */
    kSCG_FircTrimSrcRtcOsc = 3U, /*!< RTC OSC (32.768 kHz).       */
} scg_firc_trim_src_t;

/*!
 * @brief SCG fast IRC clock trim configuration.
 */
typedef struct _scg_firc_trim_config
{
    scg_firc_trim_mode_t trimMode; /*!< FIRC trim mode.                       */
    scg_firc_trim_src_t trimSrc;   /*!< Trim source.                          */
    uint16_t trimDiv;              /*!< Divider of SOSC for FIRC.             */

    uint8_t trimCoar; /*!< Trim coarse value; Irrelevant if trimMode is kSCG_FircTrimUpdate. */
    uint8_t trimFine; /*!< Trim fine value; Irrelevant if trimMode is kSCG_FircTrimUpdate. */
} scg_firc_trim_config_t;

/*! @brief FIRC enable mode. */
enum
{
    kSCG_FircDisable       = 0,                         /*!< Disable FIRC clock.             */
    kSCG_FircEnable        = SCG_FIRCCSR_FIRCEN_MASK,   /*!< Enable FIRC clock.              */
    kSCG_FircEnableInSleep = SCG_FIRCCSR_FIRCSTEN_MASK, /*!< Enable FIRC in sleep mode.      */
};

/*!
 * @brief SCG fast IRC clock frequency range.
 */
typedef enum _scg_firc_range
{
    kSCG_FircRange48M,  /*!< Fast IRC is trimmed to 48 MHz. */
    kSCG_FircRange64M,  /*!< Fast IRC is trimmed to 64 MHz. */
    kSCG_FircRange96M,  /*!< Fast IRC is trimmed to 96 MHz. */
    kSCG_FircRange192M, /*!< Fast IRC is trimmed to 192 MHz. */
} scg_firc_range_t;

/*!
 * @brief SCG fast IRC clock configuration.
 */
typedef struct _scg_firc_config_t
{
    uint32_t enableMode;    /*!< Enable mode. */
    scg_firc_range_t range; /*!< Fast IRC frequency range. */

    const scg_firc_trim_config_t *trimConfig; /*!< Pointer to the FIRC trim configuration; set NULL to disable trim. */
} scg_firc_config_t;

typedef enum _tstmr_clk_sel
{
    kTSTMR_ClkSel_ClkRoot12M,
    kTSTMR_ClkSel_FIRCDix,
    kTSTMR_ClkSel_SOSC,
    kTSTMR_ClkSel_32kHz,
    kTSTMR_ClkSel_200MHz,
    kTSTMR_ClkSel_1MHz,        /*!< TSTMR 1MHz precision. */
    kTSTMR_ClkSel_Null,        /*!< TSTMR not counting. */
    kTSTMR_ClkSel_IPCClkDiv,
} tstmr_clk_sel_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Specific clock enablement for TSTMR0 : need to configure source clock.
 *
 * @param src which source clock to count  \ref tstmr_clk_sel_t.
 * @param cc  clock control \ref clock_ip_control_t.
 */
static inline void CLOCK_StartTstmr0(tstmr_clk_sel_t src, clock_ip_control_t cc)
{
    uint32_t reg = CLOCK_REG(kCLOCK_Tstmr0);

    assert(reg & MRCC_PR_MASK);
    assert(kCLOCK_IpClkControl_fun1 == cc ||
           kCLOCK_IpClkControl_fun2 == cc ||
           kCLOCK_IpClkControl_fun3 == cc);
    if ((reg & MRCC_PR_MASK) == MRCC_PR_MASK)
    {
        CLOCK_REG(kCLOCK_Tstmr0) |= MRCC_RSTB_MASK;
    }
    reg &= ~(MRCC_MUX_MASK | MRCC_CC_MASK);
    reg |= (MRCC_MUX(src) |  ((uint32_t)cc &MRCC_CC_MASK));

    /*
     * If clock is already enabled, first disable it, then set the clock
     * source and re-enable it.
     */
    CLOCK_REG(kCLOCK_Tstmr0) = reg & (~MRCC_CC_MASK);
    CLOCK_REG(kCLOCK_Tstmr0) = reg;
}

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t name)
{
    if (kCLOCK_NOGATE == name)
    {
        return;
    }
    if (kCLOCK_Tstmr0 == name)
    {
        CLOCK_StartTstmr0(kTSTMR_ClkSel_1MHz, kCLOCK_IpClkControl_fun1);
    }
    else
    {
        uint32_t reg = CLOCK_REG(name);

        if (kCLOCK_IpClkControl_fun1 == (reg & MRCC_CC_MASK))
        {
            return;
        }

        CLOCK_REG(name) &= (~MRCC_CC_MASK);
        CLOCK_REG(name) |= (MRCC_CC_MASK & (uint32_t)kCLOCK_IpClkControl_fun1);
    }
    if ((CLOCK_REG(name) & MRCC_PR_MASK) == MRCC_PR_MASK)
    {
        CLOCK_REG(name) |= MRCC_RSTB_MASK;
    }

    /* Make sure enable clock finished */
    __ISB();
    __DSB();
}

/*!
 * @brief Enable the clock for specific IP in low power mode.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 * @param control  Clock Config, see \ref clock_ip_control_t.
 */
static inline void CLOCK_EnableClockLPMode(clock_ip_name_t name, clock_ip_control_t control)
{
    if (kCLOCK_NOGATE == name)
    {
        return;
    }
    if (kCLOCK_Tstmr0 == name)
    {
        CLOCK_StartTstmr0(kTSTMR_ClkSel_1MHz, kCLOCK_IpClkControl_fun1);
        return;
    }

    assert(kCLOCK_IpClkControl_fun1 == control || kCLOCK_IpClkControl_fun2 == control ||
           kCLOCK_IpClkControl_fun3 == control);

    CLOCK_REG(name) &= (~MRCC_CC_MASK);
    CLOCK_REG(name) |= (MRCC_CC_MASK & (uint32_t)control);

    if ((CLOCK_REG(name) & MRCC_PR_MASK) == MRCC_PR_MASK)
    {
        CLOCK_REG(name) |= MRCC_RSTB_MASK;
    }

    /* Make sure enable clock finished */
    __ISB();
    __DSB();
}

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t name)
{
    if (kCLOCK_NOGATE == name)
    {
        return;
    }

    CLOCK_REG(name) &= (uint32_t)kCLOCK_IpClkControl_fun0;

    if ((CLOCK_REG(name) & MRCC_PR_MASK) == MRCC_PR_MASK)
    {
        CLOCK_REG(name) &= ~MRCC_RSTB_MASK;
    }
}

/*!
 * @brief Set the clock source for specific IP module.
 *
 * Set the clock source for specific IP, not all modules need to set the
 * clock source, should only use this function for the modules need source
 * setting.
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param src Clock source to set.
 */
static inline void CLOCK_SetIpSrc(clock_ip_name_t name, clock_ip_src_t src)
{
    if (kCLOCK_NOGATE == name)
    {
        return;
    }

    uint32_t reg = CLOCK_REG(name);

    assert(reg & MRCC_PR_MASK);

    reg = (reg & (~MRCC_MUX_MASK)) | MRCC_MUX(src);

    /*
     * If clock is already enabled, first disable it, then set the clock
     * source and re-enable it.
     */
    CLOCK_REG(name) = reg & (~MRCC_CC_MASK);
    CLOCK_REG(name) = reg;
}

/*!
 * @brief Set the clock source and divider for specific IP module.
 *
 * Set the clock source and divider for specific IP, not all modules need to
 * set the clock source and divider, should only use this function for the
 * modules need source and divider setting.
 *
 * Divider output clock = Divider input clock / (divValue + 1U)]).
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param value  The divider value.
 */
static inline void CLOCK_SetIpSrcDiv(clock_ip_name_t name, uint8_t divValue)
{
    volatile uint32_t *pDivCtrl = 0;

    switch (name)
    {
        case kCLOCK_Lpadc0:
        case kCLOCK_Ewm0:
        case kCLOCK_Can0:
        case kCLOCK_Fro_hf_div:
        case kCLOCK_Gdet_wrapper:
        case kCLOCK_Lpi2c0:
        case kCLOCK_Lpi2c1:
        case kCLOCK_Lpit0:
        case kCLOCK_Lpspi0:
        case kCLOCK_Lpspi1:
        case kCLOCK_Lpspi2:
        case kCLOCK_Lptmr0:
        case kCLOCK_Lptmr1:
        case kCLOCK_Lpuart0:
        case kCLOCK_Lpuart1:
        case kCLOCK_Tpm0:
        case kCLOCK_Tpm1:
        case kCLOCK_Tpm2:
        case kCLOCK_Tpm3:
        case kCLOCK_Tpm4:
        case kCLOCK_Wdog0:
        case kCLOCK_Wdog1:
            pDivCtrl = (volatile uint32_t *)((uint32_t)name + 4U);
            break;
        default:
            assert(false);
            return;
    }

    /* halt and reset clock dividers */
    *pDivCtrl = 0x3UL << 29U;

    if (divValue == 0U) /*!<  halt */
    {
        *pDivCtrl |= (1UL << 30U);
    }
    else
    {
        *pDivCtrl = divValue - 1;
    }
}

/*!
 * @brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_name_t.
 *
 * @param clockName Clock names defined in clock_name_t
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*!
 * @brief Get the core clock or system clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*!
 * @brief Get the platform clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetPlatClkFreq(void);

/*!
 * @brief Get the bus clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetBusClkFreq(void);

/*!
 * @brief Get the flash clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetFlashClkFreq(void);

/*!
 * @brief Gets the functional clock frequency for a specific IP module.
 *
 * This function gets the IP module's functional clock frequency based on MRCC
 * registers. It is only used for the IP modules which could select clock source
 * by MRCC[PCS].
 *
 * @param name Which peripheral to get, see \ref clock_ip_name_t.
 * @return Clock frequency value in Hz
 */
uint32_t CLOCK_GetIpFreq(clock_ip_name_t name);

/*!
 * @name MCU System Clock.
 * @{
 */

/*!
 * @brief Gets the SCG system clock frequency.
 *
 * This function gets the SCG system clock frequency. These clocks are used for
 * core, platform, external, and bus clock domains.
 *
 * @param type     Which type of clock to get, core clock or slow clock.
 * @return  Clock frequency.
 */
uint32_t CLOCK_GetSysClkFreq(scg_sys_clk_t type);

/*!
 * @brief Sets the system clock configuration for RUN mode.
 *
 * This function sets the system clock configuration for RUN mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_SetRunModeSysClkConfig(const scg_sys_clk_config_t *config)
{
    assert(config);

    union
    {
        scg_sys_clk_config_t config;
        uint32_t u32;
    } scgSysClkConfig;

    scgSysClkConfig.config = *config;
    CLOCK_REG(&SCG_0->RCCR) = scgSysClkConfig.u32;
}

/*!
 * @brief Gets the system clock configuration in the current power mode.
 *
 * This function gets the system configuration in the current power mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_GetCurSysClkConfig(scg_sys_clk_config_t *config)
{
    assert(config);

    union
    {
        scg_sys_clk_config_t config;
        uint32_t u32;
    } scgSysClkConfig;

    scgSysClkConfig.u32 = CLOCK_REG(&SCG_0->CSR);
    *config             = scgSysClkConfig.config;
}

/*!
 * @brief Sets the clock out selection.
 *
 * This function sets the clock out selection (CLKOUTSEL).
 *
 * @param setting The selection to set.
 */
static inline void CLOCK_SetClkOutSel(clock_clkout_src_t setting)
{
    CLOCK_REG(&SCG_0->CLKOUTCNFG) = SCG_CLKOUTCNFG_CLKOUTSEL(setting);
}
/* @} */

/*!
 * @name SCG System OSC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG system OSC.
 *
 * This function enables the SCG system OSC clock according to the
 * configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success System OSC is initialized.
 * @retval kStatus_SCG_Busy System OSC has been enabled and is used by the system clock.
 * @retval kStatus_ReadOnly System OSC control register is locked.
 *
 * @note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitSysOsc(const scg_sosc_config_t *config);

/*!
 * @brief De-initializes the SCG system OSC.
 *
 * This function disables the SCG system OSC clock.
 *
 * @retval kStatus_Success System OSC is deinitialized.
 * @retval kStatus_SCG_Busy System OSC is used by the system clock.
 * @retval kStatus_ReadOnly System OSC control register is locked.
 *
 * @note This function can't detect whether the system OSC is used by an IP.
 */
status_t CLOCK_DeinitSysOsc(void);

/*!
 * @brief Gets the SCG system OSC clock frequency (SYSOSC).
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSysOscFreq(void);

/*!
 * @brief Checks whether the system OSC clock error occurs.
 *
 * @return  True if the error occurs, false if not.
 */
static inline bool CLOCK_IsSysOscErr(void)
{
    return (bool)(CLOCK_REG(&SCG_0->SOSCCSR) & SCG_SOSCCSR_SOSCERR_MASK);
}

/*!
 * @brief Clears the system OSC clock error.
 */
static inline void CLOCK_ClearSysOscErr(void)
{
    CLOCK_REG(&SCG_0->SOSCCSR) |= SCG_SOSCCSR_SOSCERR_MASK;
}

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
static inline void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode)
{
    uint32_t reg = CLOCK_REG(&SCG_0->SOSCCSR);

    reg &= ~(SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK);

    reg |= (uint32_t)mode;

    CLOCK_REG(&SCG_0->SOSCCSR) = reg;
}

/*!
 * @brief Checks whether the system OSC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsSysOscValid(void)
{
    return (bool)(CLOCK_REG(&SCG_0->SOSCCSR) & SCG_SOSCCSR_SOSCVLD_MASK);
}

/*!
 * @brief Unlock the SOSCCSR control status register.
 */
static inline void CLOCK_UnlockSysOscControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->SOSCCSR) &= ~(SCG_SOSCCSR_LK_MASK);
}

/*!
 * @brief Lock the SOSCCSR control status register.
 */
static inline void CLOCK_LockSysOscControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->SOSCCSR) |= SCG_SOSCCSR_LK_MASK;
}

/* @} */

/*!
 * @name SCG Slow IRC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG slow IRC clock.
 *
 * This function enables the SCG slow IRC clock according to the
 * configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success SIRC is initialized.
 * @retval kStatus_SCG_Busy SIRC has been enabled and is used by system clock.
 * @retval kStatus_ReadOnly SIRC control register is locked.
 *
 * @note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitSirc(const scg_sirc_config_t *config);

/*!
 * @brief De-initializes the SCG slow IRC.
 *
 * This function disables the SCG slow IRC.
 *
 * @retval kStatus_Success SIRC is deinitialized.
 * @retval kStatus_SCG_Busy SIRC is used by system clock.
 * @retval kStatus_ReadOnly SIRC control register is locked.
 *
 * @note This function can't detect whether the SIRC is used by an IP.
 */
status_t CLOCK_DeinitSirc(void);

/*!
 * @brief Gets the SCG SIRC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSircFreq(void);

/*!
 * @brief Checks whether the SIRC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsSircValid(void)
{
    return (bool)(CLOCK_REG(&SCG_0->SIRCCSR) & SCG_SIRCCSR_SIRCVLD_MASK);
}

/*!
 * @brief Unlock the SIRCCSR control status register.
 */
static inline void CLOCK_UnlockSircControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->SIRCCSR) &= ~(SCG_SIRCCSR_LK_MASK);
}

/*!
 * @brief Lock the SIRCCSR control status register.
 */
static inline void CLOCK_LockSircControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->SIRCCSR) |= SCG_SIRCCSR_LK_MASK;
}

/* @} */

/*!
 * @name SCG Fast IRC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG fast IRC clock.
 *
 * This function enables the SCG fast IRC clock according to the configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success FIRC is initialized.
 * @retval kStatus_SCG_Busy FIRC has been enabled and is used by the system clock.
 * @retval kStatus_ReadOnly FIRC control register is locked.
 *
 * @note This function can't detect whether the FIRC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitFirc(const scg_firc_config_t *config);

/*!
 * @brief De-initializes the SCG fast IRC.
 *
 * This function disables the SCG fast IRC.
 *
 * @retval kStatus_Success FIRC is deinitialized.
 * @retval kStatus_SCG_Busy FIRC is used by the system clock.
 * @retval kStatus_ReadOnly FIRC control register is locked.
 *
 * @note This function can't detect whether the FIRC is used by an IP.
 */
status_t CLOCK_DeinitFirc(void);

/*!
 * @brief Gets the SCG FIRC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetFircFreq(void);

/*!
 * @brief Checks whether the FIRC clock error occurs.
 *
 * @return  True if the error occurs, false if not.
 */
static inline bool CLOCK_IsFircErr(void)
{
    return (bool)(CLOCK_REG(&SCG_0->FIRCCSR) & SCG_FIRCCSR_FIRCERR_MASK);
}

/*!
 * @brief Clears the FIRC clock error.
 */
static inline void CLOCK_ClearFircErr(void)
{
    CLOCK_REG(&SCG_0->FIRCCSR) |= SCG_FIRCCSR_FIRCERR_MASK;
}

/*!
 * @brief Checks whether the FIRC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsFircValid(void)
{
    return (bool)(CLOCK_REG(&SCG_0->FIRCCSR) & SCG_FIRCCSR_FIRCVLD_MASK);
}

/*!
 * @brief Unlock the FIRCCSR control status register.
 */
static inline void CLOCK_UnlockFircControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->FIRCCSR) &= ~(SCG_FIRCCSR_LK_MASK);
}

/*!
 * @brief Lock the FIRCCSR control status register.
 */
static inline void CLOCK_LockFircControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->FIRCCSR) |= SCG_FIRCCSR_LK_MASK;
}

/*!
 * brief Initializes the SCG ROSC.
 *
 * This function enables the SCG ROSC clock according to the
 * configuration.
 *
 * param config   Pointer to the configuration structure.
 * retval kStatus_Success ROSC is initialized.
 * retval kStatus_SCG_Busy ROSC has been enabled and is used by the system clock.
 * retval kStatus_ReadOnly ROSC control register is locked.
 *
 * note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitRosc(const scg_rosc_config_t *config);

/*!
 * brief De-initializes the SCG ROSC.
 *
 * This function disables the SCG ROSC clock.
 *
 * retval kStatus_Success System OSC is deinitialized.
 * retval kStatus_SCG_Busy System OSC is used by the system clock.
 * retval kStatus_ReadOnly System OSC control register is locked.
 *
 * note This function can't detect whether the ROSC is used by an IP.
 */
status_t CLOCK_DeinitRosc(void);

/*!
 * @brief Gets the SCG RTC OSC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetRtcOscFreq(void);

/*!
 * @brief Gets the clock frequency of the clock 1MHz, 1MHZ is derived out of FRO6M.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_Get1MClkFreq(void);

/*!
 * @brief Gets the frequency of the TSTMR.
 *
 * @param instance TSTMR instance.
 *
 * @return Clock frequency of the TSTMR instance; If the instance is invalid, returns 0.
 */
uint32_t CLOCK_GetTstmrFreq(uint32_t instance);

/*!
 * @brief Checks whether the ROSC clock error occurs.
 *
 * @return  True if the error occurs, false if not.
 */
static inline bool CLOCK_IsRoscErr(void)
{
    return (bool)(CLOCK_REG(&SCG_0->ROSCCSR) & SCG_ROSCCSR_ROSCERR_MASK);
}

/*!
 * @brief Clears the ROSC clock error.
 */
static inline void CLOCK_ClearRoscErr(void)
{
    CLOCK_REG(&SCG_0->ROSCCSR) |= SCG_ROSCCSR_ROSCERR_MASK;
}

/*!
 * @brief Sets the ROSC monitor mode.
 *
 * This function sets the ROSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
static inline void CLOCK_SetRoscMonitorMode(scg_rosc_monitor_mode_t mode)
{
    uint32_t reg = CLOCK_REG(&SCG_0->ROSCCSR);

    reg &= ~(SCG_ROSCCSR_ROSCCM_MASK | SCG_ROSCCSR_ROSCCMRE_MASK);

    reg |= (uint32_t)mode;

    CLOCK_REG(&SCG_0->ROSCCSR) = reg;
}

/*!
 * @brief Checks whether the ROSC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsRoscValid(void)
{
    return (bool)(CLOCK_REG(&SCG_0->ROSCCSR) & SCG_ROSCCSR_ROSCVLD_MASK);
}

/*!
 * @brief Unlock the ROSCCSR control status register.
 */
static inline void CLOCK_UnlockRoscControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->ROSCCSR) &= ~(SCG_ROSCCSR_LK_MASK);
}

/*!
 * @brief Lock the ROSCCSR control status register.
 */
static inline void CLOCK_LockRoscControlStatusReg(void)
{
    CLOCK_REG(&SCG_0->ROSCCSR) |= SCG_ROSCCSR_LK_MASK;
}

/*!
 * @name External clock frequency
 * @{
 */

/*!
 * @brief Sets the XTAL0 frequency based on board settings.
 *
 * @param freq The XTAL0/EXTAL0 input clock frequency in Hz.
 */
static inline void CLOCK_SetXtal0Freq(uint32_t freq)
{
    g_xtal0Freq = freq;
}

/*!
 * @brief Sets the XTAL32 frequency based on board settings.
 *
 * @param freq The XTAL32/EXTAL32 input clock frequency in Hz.
 */
static inline void CLOCK_SetXtal32Freq(uint32_t freq)
{
    g_xtal32Freq = freq;
}

/* @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */

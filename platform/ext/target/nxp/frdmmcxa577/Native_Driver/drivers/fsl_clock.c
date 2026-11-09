/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_clock.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

#define NVALMAX       (0x100U)
#define PVALMAX       (0x20U)
#define MVALMAX       (0x10000U)
#define PLL_MAX_N_DIV (0x100U)

/*--------------------------------------------------------------------------
!!! If required these #defines can be moved to chip library file
----------------------------------------------------------------------------*/

#define PLL_NDIV_VAL_P (0U) /* NDIV is in bits  7:0 */
#define PLL_NDIV_VAL_M (0xFFUL << PLL_NDIV_VAL_P)
#define PLL_MDIV_VAL_P (0U) /* MDIV is in bits  15:0 */
#define PLL_MDIV_VAL_M (0xFFFFULL << PLL_MDIV_VAL_P)
#define PLL_PDIV_VAL_P (0U) /* PDIV is in bits  4:0 */
#define PLL_PDIV_VAL_M (0x1FUL << PLL_PDIV_VAL_P)

#define PLL_MIN_CCO_FREQ_MHZ (275000000U)
#define PLL_MAX_CCO_FREQ_MHZ (550000000U)
#define PLL_LOWER_IN_LIMIT   (32000U)     /*!<  Minimum PLL input rate */
#define PLL_HIGHER_IN_LIMIT  (150000000U) /*!<  Maximum PLL input rate */
#define PLL_MIN_IN_SSMODE    (3000000U)
#define PLL_MAX_IN_SSMODE \
    (100000000U) /*!<  Not find the value in UM, Just use the maximum frequency which device support */

/* PLL NDIV reg */
#define PLL_NDIV_VAL_SET(value) (((unsigned long)(value) << PLL_NDIV_VAL_P) & PLL_NDIV_VAL_M)
/* PLL MDIV reg */
#define PLL_MDIV_VAL_SET(value) (((unsigned long long)(value) << PLL_MDIV_VAL_P) & PLL_MDIV_VAL_M)
/* PLL PDIV reg */
#define PLL_PDIV_VAL_SET(value) (((unsigned long)(value) << PLL_PDIV_VAL_P) & PLL_PDIV_VAL_M)

/* PLL SSCG control1 */
#define PLL_SSCG_MD_FRACT_P          (0U)
#define PLL_SSCG_MD_INT_P            (25U)
#define PLL_SSCG_MD_FRACT_M          (0x1FFFFFFUL << PLL_SSCG_MD_FRACT_P)
#define PLL_SSCG_MD_INT_M            ((uint64_t)0xFFUL << PLL_SSCG_MD_INT_P)
#define PLL_SSCG_MD_FRACT_SET(value) (((uint64_t)(value) << PLL_SSCG_MD_FRACT_P) & PLL_SSCG_MD_FRACT_M)
#define PLL_SSCG_MD_INT_SET(value)   (((uint64_t)(value) << PLL_SSCG_MD_INT_P) & PLL_SSCG_MD_INT_M)

/*! @brief Retry times for waiting flag. */
#ifndef SOC_DRIVER_RETRY_TIMES
#ifdef CONFIG_SOC_DRIVER_RETRY_TIMES
#define SOC_DRIVER_RETRY_TIMES CONFIG_SOC_DRIVER_RETRY_TIMES
#else
#define SOC_DRIVER_RETRY_TIMES 0U /* Defining to zero means to keep waiting for the flag until it is assert/deassert. */
#endif
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
/** External clock rate on the CLKIN pin in Hz. If not used,
    set this to 0. Otherwise, set it to the exact rate in Hz this pin is
    being driven at. */
volatile static uint32_t s_Ext_Clk_Freq = 16000000U;
/*! @brief ENET TX CLK clock frequency. */
volatile static uint32_t s_Enet_Tx_Clk_Freq = 0U;
/*! @brief External XTAL32K clock frequency. */
#define OSC32K_Freq (32768U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* Get FRO 12M Clk */
static uint32_t CLOCK_GetFro12MFreq(void);
/* Get LF FRO_DIV Clk */
static uint32_t CLOCK_GetFroLfDivFreq(void);
/* Get CLK 1M Clk */
static uint32_t CLOCK_GetClk1MFreq(void);
/* Get HF FRO Clk */
static uint32_t CLOCK_GetFroHfFreq(void);
/* Get HF FRO_DIV Clk */
static uint32_t CLOCK_GetFroHfDivFreq(void);
/* Get CLK 48M Clk */
static uint32_t CLOCK_GetClk48MFreq(void);
/* Get CLK 16K Clk */
static uint32_t CLOCK_GetClk16KFreq(uint8_t id);
/* Get EXT OSC Clk */
static uint32_t CLOCK_GetExtClkFreq(void);
/* Get Main_Clk */
static uint32_t CLOCK_GetMainClk(void);
/* Get FRO_16K */
static uint32_t CLOCK_GetFRO16KFreq(void);
/* Get Pll1ClkDiv */
static uint32_t CLOCK_GetPll1ClkDivFreq(void);
/* Get Pll1Clk */
static uint32_t CLOCK_GetPll1ClkFreq(void);
/* Get Osc32K */
static uint32_t CLOCK_GetOsc32KFreq(uint32_t id);
/* Get LP_OSC Clk */
static uint32_t CLOCK_GetLposcFreq(void);
/* Get UsbPll */
static uint32_t CLOCK_GetUsbPllFreq(void);
/* Get UsbPfdClk */
static uint32_t CLOCK_GetUsbPfdClkFreq(void);

/* Find SELP, SELI, and SELR values for raw M value, max M = MVALMAX */
static void pllFindSel(uint32_t M, uint32_t *pSelP, uint32_t *pSelI, uint32_t *pSelR);
/* Get predivider (N) from PLL1 NDIV setting */
static uint32_t findPll1PreDiv(void);
/* Get postdivider (P) from PLL1 PDIV setting */
static uint32_t findPll1PostDiv(void);
/* Get multiplier (M) from PLL1 MDIV and SSCG settings */
static float findPll1MMult(void);
/* Get the greatest common divisor */
static uint32_t FindGreatestCommonDivisor(uint32_t m, uint32_t n);
/* Set PLL output based on desired output rate */
static pll_error_t CLOCK_GetPllConfig(uint32_t finHz, uint32_t foutHz, pll_setup_t *pSetup, bool useSS);
/* Set PLL0 output based on desired output rate */
static pll_error_t CLOCK_GetPllConfigInternal(uint32_t finHz, uint32_t foutHz, pll_setup_t *pSetup, bool useSS);
/* Get PLL input clock rate from setup structure */
static uint32_t CLOCK_GetPLLInClockRateFromSetup(pll_setup_t *pSetup);
/* Get predivider (N) from setup structure */
static uint32_t findPllPreDivFromSetup(pll_setup_t *pSetup);
/* Get postdivider (P) from setup structure */
static uint32_t findPllPostDivFromSetup(pll_setup_t *pSetup);
/* Get multiplier (M) from setup structure */
static float findPllMMultFromSetup(pll_setup_t *pSetup);

/* Check if DIV is halt */
static inline bool CLOCK_IsDivHalt(uint32_t div_value)
{
    if (0U != (div_value & (1UL << 30U)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Clock Selection for IP */
/**
 * brief   Configure the clock selection muxes.
 * param   connection  : Clock to be configured.
 * return  Nothing
 */
void CLOCK_AttachClk(clock_attach_id_t connection)
{
    const uint32_t reg_offset = CLK_ATTACH_REG_OFFSET(connection);
    const uint32_t clk_sel    = CLK_ATTACH_CLK_SEL(connection);

    if (kNONE_to_NONE != connection)
    {
        CLOCK_SetClockSelect((clock_select_name_t)reg_offset, clk_sel);
    }
}

/* Return the actual clock attach id */
/**
 * brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual
 * source value in the register and combine the offset to obtain an actual
 * attach id.
 * value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t connection)
{
    const uint32_t reg_offset = CLK_ATTACH_REG_OFFSET(connection);
    uint32_t actual_sel       = 0U;
    uint32_t clock_attach_id  = 0U;

    if (kNONE_to_NONE == connection)
    {
        return kNONE_to_NONE;
    }

    actual_sel      = CLOCK_GetClockSelect((clock_select_name_t)reg_offset);
    clock_attach_id = CLK_ATTACH_MUX(reg_offset, actual_sel);

    assert(clock_attach_id < kNONE_to_NONE);

    return (clock_attach_id_t)clock_attach_id;
}

/* Set the clock selection value */
status_t CLOCK_SetClockSelect(clock_select_name_t sel_name, uint32_t value)
{
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)sel_name);
    assert(sel_name <= kCLOCK_SelMax);

    if (sel_name == kCLOCK_SelSCGSCS)
    {
        SCG0->RCCR = (SCG0->RCCR & ~(SCG_RCCR_SCS_MASK)) | SCG_RCCR_SCS(value);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
        uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
        while ((SCG0->CSR & SCG_CSR_SCS_MASK) != SCG_CSR_SCS(value))
        {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
            if (--waitTimes == 0U)
            {
                assert(false);
                return kStatus_Timeout;
            }
#endif
        }
    }
    else
    {
        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

        *pClkCtrl = value;

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
    }

    return kStatus_Success;
}

/* Get the clock selection value */
uint32_t CLOCK_GetClockSelect(clock_select_name_t sel_name)
{
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)sel_name);
    uint32_t actual_sel         = 0U;
    assert(sel_name <= kCLOCK_SelMax);

    if (sel_name == kCLOCK_SelSCGSCS)
    {
        actual_sel = (uint32_t)((SCG0->RCCR & SCG_RCCR_SCS_MASK) >> SCG_RCCR_SCS_SHIFT);
    }
    else
    {
        actual_sel = *pClkCtrl;
    }

    return actual_sel;
}

/* Set the clock divider value */
void CLOCK_SetClockDiv(clock_div_name_t div_name, uint32_t value)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    /* Early exit: current DIV value already matches the requested value,
     * and the divider is not in halt state */
    if ((value != 0U) && ((*pDivCtrl & (1UL << 30U)) == 0U) && ((*pDivCtrl & 0xFFU) == (value - 1U)))
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    /* AHBCLKDIV does not support HALT(bit30) or RESET(bit29);
     * writing those bits would corrupt reserved fields. Write the DIV value directly. */
    if (div_name == kCLOCK_DivAHBCLK)
    {
        *pDivCtrl = (value == 0U) ? 0U : (value - 1U);
    }
    else
    {
        /* halt and reset clock dividers */
        *pDivCtrl = 0x3UL << 29U;

        if (value == 0U) /*!<  halt */
        {
            *pDivCtrl |= (1UL << 30U);
        }
        else
        {
            /* Write new DIV value while keeping HALT bit set */
            *pDivCtrl = (value - 1U) | (1UL << 30U);
            /* Clear HALT bit to start the divider with the new value */
            *pDivCtrl &= ~(1UL << 30U);
        }
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/* Get the clock divider value */
uint32_t CLOCK_GetClockDiv(clock_div_name_t div_name)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    if (((*pDivCtrl) & (1UL << 30U)) != 0U)
    {
        return 0;
    }
    else
    {
        return ((*pDivCtrl & 0xFFU) + 1U);
    }
}

/* Halt the clock divider value */
void CLOCK_HaltClockDiv(clock_div_name_t div_name)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    *pDivCtrl |= (1UL << 30U);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/* Initialize the FROHF to given frequency (48M,64M,96M,192M) */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq)
{
    uint8_t freq_select = 0x0U;
    switch (iFreq)
    {
        case 48000000U:
            freq_select = 1U;
            break;
        case 64000000U:
            freq_select = 3U;
            break;
        case 96000000U:
            freq_select = 5U;
            break;
        case 192000000U:
            freq_select = 7U;
            break;
        default:
            freq_select = 0xFU;
            break;
    }

    if (0xFU == freq_select)
    {
        return kStatus_Fail;
    }

    /* Set FIRC frequency */
    SCG0->FIRCCFG = SCG_FIRCCFG_FREQ_SEL(freq_select);

    /* Unlock FIRCCSR */
    SCG0->FIRCCSR &= ~SCG_FIRCCSR_LK_MASK;

    /* Enable FIRC 48 MHz clock for peripheral use */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK;
    /* Enable FIRC 192 MHz clock for peripheral use */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK;

    /* Enable FIRC */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRCEN_MASK;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for FIRC clock to be valid. */
    while ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/* Initialize the FRO12M. */
status_t CLOCK_SetupFRO12MClocking(void)
{
    /* Unlock SIRCCSR */
    SCG0->SIRCCSR &= ~SCG_SIRCCSR_LK_MASK;

    /* Enable FRO12M clock for peripheral use */
    SCG0->SIRCCSR |= SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK;

    /* Lock SIRCCSR */
    SCG0->SIRCCSR |= SCG_SIRCCSR_LK_MASK;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for SIRC clock to be valid. */
    while ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    /* Release FROLFDIV */
    SYSCON->FROLFDIV &= ~SYSCON_FROLFDIV_HALT_MASK;

    return kStatus_Success;
}

/*!
 * brief   Initialize the FRO16K.
 * This function turns on FRO16K.
 * return  returns success or fail status.
 */
status_t CLOCK_SetupFRO16KClocking(uint8_t clk_16k_enable_mask)
{
    /* Enable clk_16k */
    VBAT0->FROCTLA |= VBAT_FROCTLA_FRO_EN_MASK;
    VBAT0->FROLCKA |= VBAT_FROLCKA_LOCK_MASK;

    /* Enable clk_16k output clock to corresponding modules according to the
     * enable_mask. */
    VBAT0->FROCLKE |= VBAT_FROCLKE_CLKE(((uint32_t)clk_16k_enable_mask));

    return kStatus_Success;
}

/*!
 * brief   Initialize the external osc clock to given frequency.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq)
{
    uint8_t range = 0U;

    if ((iFreq >= 16000000U) && (iFreq < 20000000U))
    {
        range = 0U;
    }
    else if ((iFreq >= 20000000U) && (iFreq < 30000000U))
    {
        range = 1U;
    }
    else if ((iFreq >= 30000000U) && (iFreq < 50000000U))
    {
        range = 2U;
    }
    else if ((iFreq >= 50000000U) && (iFreq <= 66000000U))
    {
        range = 3U;
    }
    else
    {
        return kStatus_InvalidArgument;
    }

    /* If configure register is locked, return error. */
    if ((SCG0->SOSCCSR & SCG_SOSCCSR_LK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* De-initializes the SCG SOSC */
    SCG0->SOSCCSR = SCG_SOSCCSR_SOSCERR_MASK;

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    /* Select SOSC source(internal crystal oscillator) and Configure SOSC range */
    SCG0->SOSCCFG = SCG_SOSCCFG_EREFS_MASK | SCG_SOSCCFG_RANGE(range);

    /* Unlock SOSCCSR */
    SCG0->SOSCCSR &= ~SCG_SOSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable SOSC */
    SCG0->SOSCCSR |= (SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCEN_MASK);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for SOSC clock to be valid. */
    while ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    s_Ext_Clk_Freq = iFreq;

    return kStatus_Success;
}

/*!
 * @brief   Initialize the external reference clock to given frequency.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupExtRefClocking(uint32_t iFreq)
{
    if (iFreq > 50000000U)
    {
        return kStatus_InvalidArgument;
    }

    /* If configure register is locked, return error. */
    if ((SCG0->SOSCCSR & SCG_SOSCCSR_LK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* De-initializes the SCG SOSC */
    SCG0->SOSCCSR = SCG_SOSCCSR_SOSCERR_MASK;

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    /* Select SOSC source (external reference clock)*/
    SCG0->SOSCCFG &= ~SCG_SOSCCFG_EREFS_MASK;

    /* Unlock SOSCCSR */
    SCG0->SOSCCSR &= ~SCG_SOSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable SOSC */
    SCG0->SOSCCSR |= (SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCEN_MASK);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for SOSC clock to be valid. */
    while ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    s_Ext_Clk_Freq = iFreq;

    return kStatus_Success;
}

/**
 * @brief   Initialize the OSC 32K.
 * @param   id   : OSC 32 kHz output clock to specified modules
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClocking(uint32_t id)
{
    uint32_t temp32 = 0;
#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes;
#endif

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;
    
    VBAT0->OSCCFGA = (VBAT0->OSCCFGA & ~VBAT_OSCCFGA_INIT_TRIM_MASK) | VBAT_OSCCFGA_INIT_TRIM(3);

    temp32 = VBAT0->OSCCTLA;

    temp32 &= ~(VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK | VBAT_OSCCTLA_XTAL_CAP_SEL_MASK | VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK);
    temp32 |= (VBAT_OSCCTLA_EXTAL_CAP_SEL(0x6) | VBAT_OSCCTLA_XTAL_CAP_SEL(0x6) | VBAT_OSCCTLA_COARSE_AMP_GAIN(1));

    temp32 &= ~(VBAT_OSCCTLA_MODE_EN_MASK | VBAT_OSCCTLA_CAP_SEL_EN_MASK | VBAT_OSCCTLA_OSC_EN_MASK);
    temp32 |= VBAT_OSCCTLA_MODE_EN(0x1) | VBAT_OSCCTLA_CAP_SEL_EN_MASK | VBAT_OSCCTLA_OSC_EN_MASK;

    VBAT0->OSCCTLA = temp32;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for STATUSA[OSC_RDY] to set. */
    while ((VBAT0->STATUSA & VBAT_STATUSA_OSC_RDY_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    VBAT0->OSCCLKE |= VBAT_OSCCLKE_CLKE(id);

    /* De-initializes the SCG ROSC */
    SCG0->ROSCCSR = SCG_ROSCCSR_ROSCERR_MASK;

    /* Unlock ROSCCSR */
    SCG0->ROSCCSR &= ~SCG_ROSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable ROSC */
    SCG0->ROSCCSR |= SCG_ROSCCSR_ROSCCM_MASK;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for ROSC clock to be valid. */
    while ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/**
 * @brief   Get default XTAL32/EXTAL32 clock configuration structure.
 * This function initializes the osc 32k configuration structure to a default value. The default
 * values are:
 *   config->initTrim = kVBAT_OscInitTrim500ms;
 *   config->capTrim  = kVBAT_OscCapTrimDefault;
 *   config->dlyTrim  = kVBAT_OscDlyTrim5;
 *   config->cap2Trim = kVBAT_OscCap2Trim0;
 *   config->cmpTrim  = kVBAT_OscCmpTrim760mv;
 *   config->mode     = kVBAT_OscNormalModeEnable;
 *   config->xtalCap  = kVBAT_OscXtal24pFCap;
 *   config->extalCap = kVBAT_OscExtal22pFCap;
 *   config->ampGain  = kVBAT_OscCoarseAdjustment05;
 *   config->id       = kCLOCK_Osc32kToVbat;
 *   config->updateTrim = false
 * @param   config: Pointer to a configuration structure
 */
void CLOCK_GetDefaultOsc32KConfig(osc_32k_config_t *config)
{
    config->initTrim = kVBAT_OscInitTrim500ms;
    config->capTrim  = kVBAT_OscCapTrimDefault;
    config->dlyTrim  = kVBAT_OscDlyTrim5;
    config->cap2Trim = kVBAT_OscCap2Trim0;
    config->cmpTrim  = kVBAT_OscCmpTrim760mv;

    config->mode     = kVBAT_OscNormalModeEnable;
    config->xtalCap  = kVBAT_OscXtal24pFCap;
    config->extalCap = kVBAT_OscExtal22pFCap;
    config->ampGain  = kVBAT_OscCoarseAdjustment05;

    config->id         = kCLOCK_Osc32kToVbat;
    config->updateTrim = false;
}

/**
 * @brief   Initialize the OSC 32K with user-defined settings.
 * @param   config   : OSC 32K configuration structure
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClockingConfig(osc_32k_config_t config)
{
    uint32_t oscctlaMask = 0U;
#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes;
#endif

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    oscctlaMask =
        (VBAT_OSCCTLA_MODE_EN_MASK | VBAT_OSCCTLA_CAP_SEL_EN_MASK | VBAT_OSCCTLA_OSC_EN_MASK |
         VBAT_OSCCTLA_XTAL_CAP_SEL_MASK | VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK | VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK);

    if (config.updateTrim)
    {
        VBAT0->OSCCFGA = VBAT_OSCCFGA_INIT_TRIM(config.initTrim) | VBAT_OSCCFGA_CAP_TRIM(config.capTrim) |
                         VBAT_OSCCFGA_DLY_TRIM(config.dlyTrim) | VBAT_OSCCFGA_CAP2_TRIM(config.cap2Trim) |
                         VBAT_OSCCFGA_CMP_TRIM(config.cmpTrim);
    }

    if (config.mode == kVBAT_OscLowpowerModeEnable)
    {
        VBAT0->OSCCFGA = (VBAT0->OSCCFGA & ~VBAT_OSCCFGA_INIT_TRIM_MASK) | VBAT_OSCCFGA_INIT_TRIM(3);

        /* Low power mode sequence: enter startup mode first, then switch to low power mode. */
        VBAT0->OSCCTLA = (VBAT0->OSCCTLA & ~oscctlaMask) | VBAT_OSCCTLA_MODE_EN(kVBAT_OscStartupModeEnable) |
                         VBAT_OSCCTLA_OSC_EN_MASK | VBAT_OSCCTLA_XTAL_CAP_SEL(config.xtalCap) |
                         VBAT_OSCCTLA_EXTAL_CAP_SEL(config.extalCap) | VBAT_OSCCTLA_CAP_SEL_EN_MASK |
                         VBAT_OSCCTLA_COARSE_AMP_GAIN(config.ampGain);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
        waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
        /* Wait for STATUSA[OSC_RDY] to set. */
        while ((VBAT0->STATUSA & VBAT_STATUSA_OSC_RDY_MASK) == 0U)
        {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
            if (--waitTimes == 0U)
            {
                assert(false);
                return kStatus_Timeout;
            }
#endif
        }

        /* Clear INIT_TRIM after oscillator is ready. */
        VBAT0->OSCCFGA &= ~VBAT_OSCCFGA_INIT_TRIM_MASK;

        /* Switch to low power mode. Cap selections are forced to 0. */
        VBAT0->OSCCTLA = (VBAT0->OSCCTLA & ~oscctlaMask) | VBAT_OSCCTLA_MODE_EN(kVBAT_OscLowpowerModeEnable) |
                         VBAT_OSCCTLA_OSC_EN_MASK | VBAT_OSCCTLA_XTAL_CAP_SEL(0U) | VBAT_OSCCTLA_EXTAL_CAP_SEL(0U) |
                         VBAT_OSCCTLA_CAP_SEL_EN_MASK | VBAT_OSCCTLA_COARSE_AMP_GAIN(config.ampGain);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
        waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
        /* Wait for STATUSA[OSC_RDY] to set. */
        while ((VBAT0->STATUSA & VBAT_STATUSA_OSC_RDY_MASK) == 0U)
        {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
            if (--waitTimes == 0U)
            {
                assert(false);
                return kStatus_Timeout;
            }
#endif
        }
    }
    else
    {
        /* Normal/startup mode sequence. */
        VBAT0->OSCCTLA = (VBAT0->OSCCTLA & ~oscctlaMask) | VBAT_OSCCTLA_MODE_EN(config.mode) |
                         VBAT_OSCCTLA_OSC_EN_MASK | VBAT_OSCCTLA_XTAL_CAP_SEL(config.xtalCap) |
                         VBAT_OSCCTLA_EXTAL_CAP_SEL(config.extalCap) | VBAT_OSCCTLA_CAP_SEL_EN_MASK |
                         VBAT_OSCCTLA_COARSE_AMP_GAIN(config.ampGain);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
        waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
        /* Wait for STATUSA[OSC_RDY] to set. */
        while ((VBAT0->STATUSA & VBAT_STATUSA_OSC_RDY_MASK) == 0U)
        {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
            if (--waitTimes == 0U)
            {
                assert(false);
                return kStatus_Timeout;
            }
#endif
        }

        if (config.mode == kVBAT_OscNormalModeEnable)
        {
            /* Clear CAP_SEL */
            VBAT0->OSCCTLA &= ~(VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK | VBAT_OSCCTLA_XTAL_CAP_SEL_MASK);
        }
    }

    VBAT0->OSCCLKE |= VBAT_OSCCLKE_CLKE(config.id);

    /* De-initializes the SCG ROSC */
    SCG0->ROSCCSR = SCG_ROSCCSR_ROSCERR_MASK;

    /* Unlock ROSCCSR */
    SCG0->ROSCCSR &= ~SCG_ROSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable ROSC */
    SCG0->ROSCCSR |= SCG_ROSCCSR_ROSCCM_MASK;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for ROSC clock to be valid. */
    while ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) == 0U)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/* Get IP Clk */
/*! brief  Return Frequency of selected clock
 *  return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq = 0U;

    switch (clockName)
    {
        case kCLOCK_MainClk: /* MAIN_CLK */
            freq = CLOCK_GetMainClk();
            break;
        case kCLOCK_CoreSysClk: /* Core/system clock(CPU_CLK) */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_SYSTEM_CLK: /* AHB clock */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_BusClk: /* Bus clock */
            freq = (CLOCK_GetCoreSysClkFreq() >> 1);
            break;
        case kCLOCK_ExtClk: /* External Clock */
            freq = CLOCK_GetExtClkFreq();
            break;
        case kCLOCK_FroHf: /* FROHF */
            freq = CLOCK_GetFroHfFreq();
            break;
        case kCLOCK_FroHfDiv: /* Divided by FROHF */
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case kCLOCK_Clk48M: /* CLK_48M */
            freq = CLOCK_GetClk48MFreq();
            break;
        case kCLOCK_Fro12M: /* FRO12M */
            freq = CLOCK_GetFro12MFreq();
            break;
        case kCLOCK_Fro12MDiv: /* FRO_LF_DIV */
            freq = CLOCK_GetFro12MFreq() / ((SYSCON->FROLFDIV & 0xfU) + 1U);
            break;
        case kCLOCK_Clk1M: /* CLK1M */
            freq = CLOCK_GetClk1MFreq();
            break;
        case kCLOCK_Fro16K: /* FRO16K */
            freq = CLOCK_GetFRO16KFreq();
            break;
        case kCLOCK_Clk16K0: /* CLK16K[0] */
            freq = CLOCK_GetClk16KFreq(0);
            break;
        case kCLOCK_Clk16K1: /* CLK16K[1] */
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case kCLOCK_Clk16K2: /* CLK16K[2] */
            freq = CLOCK_GetClk16KFreq(2);
            break;
        case kCLOCK_SLOW_CLK: /* SYSTEM_CLK divided by 6 */
            freq = (CLOCK_GetCoreSysClkFreq() / 6);
            break;
        case kCLOCK_Pll1Clk: /* Pll1Clk */
            freq = CLOCK_GetPll1ClkFreq();
            break;
        case kCLOCK_Pll1ClkDiv: /* Pll1ClkDiv */
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        case kCLOCK_UsbPll:
            freq = CLOCK_GetUsbPllFreq();
            break;
        case kCLOCK_UsbPfdClk:
            freq = CLOCK_GetUsbPfdClkFreq();
            break;
        case kCLOCK_Osc32K0:
            freq = CLOCK_GetOsc32KFreq(0);
            break;
        case kCLOCK_Osc32K1:
            freq = CLOCK_GetOsc32KFreq(1);
            break;
        case kCLOCK_Osc32K2:
            freq = CLOCK_GetOsc32KFreq(2);
            break;
        case kCLOCK_LpOsc:
            freq = CLOCK_GetLposcFreq();
            break;
        default:
            freq = 0U;
            break;
    }
    return freq;
}

/* Get FRO 12M Clk */
/*! brief  Return Frequency of FRO 12MHz
 *  return Frequency of FRO 12MHz
 */
static uint32_t CLOCK_GetFro12MFreq(void)
{
    return ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK) != 0U) ? 12000000U : 0U;
}

/* Get CLK 1M Clk */
/*! brief  Return Frequency of CLK 1MHz
 *  return Frequency of CLK 1MHz
 */
static uint32_t CLOCK_GetClk1MFreq(void)
{
    return 1000000U;
}

/* Get HF FRO Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroHfFreq(void)
{
    uint32_t freq;

    if (((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) == 0U) ||
        ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK) == 0U))
    {
        return 0U;
    }

    switch ((SCG0->FIRCCFG & SCG_FIRCCFG_FREQ_SEL_MASK) >> SCG_FIRCCFG_FREQ_SEL_SHIFT)
    {
        case 1U:
            freq = 48000000U;
            break;
        case 3U:
            freq = 64000000U;
            break;
        case 5U:
            freq = 96000000U;
            break;
        case 7U:
            freq = 192000000U;
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/* Get HF FRO DIV Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroHfDivFreq(void)
{
    return CLOCK_GetFroHfFreq() / ((SYSCON->FROHFDIV & SYSCON_FROHFDIV_DIV_MASK) + 1U);
}

/* Get LF FRO DIV Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroLfDivFreq(void)
{
    return CLOCK_GetFro12MFreq() / ((SYSCON->FROLFDIV & SYSCON_FROLFDIV_DIV_MASK) + 1U);
}

/* Get CLK_48M frequency */
/*! brief  Return Frequency of CLK 48MHz
 *  return Frequency of CLK 48MHz
 */
static uint32_t CLOCK_GetClk48MFreq(void)
{
    if ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK) == 0U)
    {
        return 0U;
    }
    else
    {
        return 48000000U;
    }
}

/*! brief  Return Frequency of FRO16K
 *  return Frequency of FRO_16K
 */
static uint32_t CLOCK_GetFRO16KFreq(void)
{
    return ((VBAT0->FROCTLA & VBAT_FROCTLA_FRO_EN_MASK) != 0U) ? 16000U : 0U;
}
/* Get CLK 16K Clk */
/*! brief  Return Frequency of CLK 16KHz
 *  return Frequency of CLK 16KHz
 */
static uint32_t CLOCK_GetClk16KFreq(uint8_t id)
{
    return (((VBAT0->FROCTLA & VBAT_FROCTLA_FRO_EN_MASK) != 0U) &&
            ((VBAT0->FROCLKE & VBAT_FROCLKE_CLKE(1UL << (uint32_t)id)) != 0U)) ?
               (16000U) :
               (0U);
}

/* Get EXT OSC Clk */
/*! brief  Return Frequency of External Clock
 *  return Frequency of External Clock. If no external clock is used returns 0.
 */
static uint32_t CLOCK_GetExtClkFreq(void)
{
    return ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) != 0U) ? s_Ext_Clk_Freq : 0U;
}

/* Get OSC32 Clk */
/*! brief  Return Frequency of 32kHz osc
 *  return Frequency of 32kHz osc
 */
static uint32_t CLOCK_GetOsc32KFreq(uint32_t id)
{
    assert(id <= 2u);

    return ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) != 0UL) ?
               (((VBAT0->OSCCLKE & VBAT_OSCCLKE_CLKE(1UL << id)) != 0UL) ? OSC32K_Freq : 0U) :
               0U;
}

/* Get LP_OSC Clk */
/*! brief  Return Frequency of LP_OSC
 *  return Frequency of LP_OSC
 */
static uint32_t CLOCK_GetLposcFreq(void)
{
    uint32_t freq;

    if ((RTC0->CTRL & RTC_CTRL_CLK_SEL_MASK) == 0U)
    {
        freq = CLOCK_GetClk16KFreq(0);
    }
    else
    {
        freq = CLOCK_GetOsc32KFreq(0);
    }

    return freq;
}

/* Get Pll1ClkDiv */
static uint32_t CLOCK_GetPll1ClkDivFreq(void)
{
    return CLOCK_GetPll1ClkFreq() / ((SYSCON->PLL1CLKDIV & SYSCON_PLL1CLKDIV_DIV_MASK) + 1U);
}

/*! brief Enable USB HS PHY PLL clock.
 *
 * This function enables the internal 480MHz USB PHY PLL clock.
 * param clockSourceFreq The frequency specified by src.
 * retval true The clock is set successfully.
 * retval false The clock source is invalid to get proper USB HS clock.
 */
bool CLOCK_EnableUsbhsPhyPllClock(uint32_t clockSourceFreq)
{
    uint32_t phyPllDiv  = 0U;
    uint16_t multiplier = 0U;
    bool err            = false;

    USBHS1_PHY->CTRL_CLR    = USBPHY_CTRL_SFTRST_MASK;
    USBHS1_PHY->ANACTRL_SET = USBPHY_ANACTRL_LVI_EN_MASK;
    USBHS1_PHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK;
    SDK_DelayAtLeastUs(15U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    USBHS1_PHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_POWER(1);
    if ((480000000UL % clockSourceFreq) != 0UL)
    {
        return false;
    }
    multiplier = (uint16_t)((480000000UL / clockSourceFreq) & 0xFFFFU);

    switch (multiplier)
    {
        case 15:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(0U);
            break;
        }
        case 16:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(1U);
            break;
        }
        case 20:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(2U);
            break;
        }
        case 22:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(3U);
            break;
        }
        case 24:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(4U);
            break;
        }
        case 25:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(5U);
            break;
        }
        case 30:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(6U);
            break;
        }
        case 40:
        {
            phyPllDiv = USBPHY_PLL_SIC_PLL_DIV_SEL(7U);
            break;
        }
        default:
        {
            err = true;
            break;
        }
    }

    if (err)
    {
        return false;
    }

    USBHS1_PHY->PLL_SIC = (USBHS1_PHY->PLL_SIC & ~(USBPHY_PLL_SIC_PLL_DIV_SEL_MASK)) | phyPllDiv;

    USBHS1_PHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_BYPASS_MASK;
    USBHS1_PHY->PLL_SIC_SET = (USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK);

    USBHS1_PHY->CTRL_CLR = USBPHY_CTRL_CLR_CLKGATE_MASK;
    USBHS1_PHY->PWD      = 0x0U;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    while (0UL == (USBHS1_PHY->PLL_SIC & USBPHY_PLL_SIC_PLL_LOCK_MASK))
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return false;
        }
#endif
    }

    return true;
}

/*! brief Disable USB HS PHY PLL clock.
 *
 * This function disables USB HS PHY PLL clock.
 */
void CLOCK_DisableUsbhsPhyPllClock(void)
{
    USBHS1_PHY->CTRL |= USBPHY_CTRL_CLKGATE_MASK; /* Set to 1U to gate clocks */
}

#ifdef USBHS1
/*! brief Enable USB HS clock.
 * retval true The clock is set successfully.
 * retval false The clock source is invalid to get proper USB HS clock.
 */
bool CLOCK_EnableUsbhsClock(void)
{
    USBHS1->USBCMD |= USBHS_USBCMD_RST_MASK;
    /* Add a delay between RST and RS so make sure there is a DP pullup sequence*/
    for (uint32_t i = 0; i < 400000U; i++)
    {
        __ASM("nop");
    }
    return true;
}
#endif

/* Get UsbPll */
static uint32_t CLOCK_GetUsbPllFreq(void)
{
    if (0 == (USBHS1_PHY->CTRL & USBPHY_CTRL_CLKGATE_MASK))
    {
        return 480000000U;
    }
    else
    {
        return 0;
    }
}

/* Enable USBPHY_PFD clock */
bool CLOCK_EnableUsbhsPhyPfdClock(uint32_t pfdDiv, pfd_clkout_selection_t pfdClkSel)
{
    /* 480 MHz * 18 / n, where n = 18-35 */
    if (pfdDiv < 18U || pfdDiv > 35U)
    {
        return kStatus_Fail;
    }

    /* Gate the PFD clock before configuration */
    USBHS1_PHY->PFDA |= USBPHY_PFDA_PFD0_CLKGATE_MASK;

    /* Reset USBPLL */
    USBHS1_PHY->PLL_SIC &= ~USBPHY_PLL_SIC_PLL_POWER_MASK;
    USBHS1_PHY->PLL_SIC |= USBPHY_PLL_SIC_PLL_POWER_MASK;

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for USBPLL to stabilize */
    while (0 == (USBHS1_PHY->PLL_SIC & USBPHY_PLL_SIC_PLL_LOCK_MASK))
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#else
        __NOP();
#endif
    }

    /* Select the PFD clock source */
    USBHS1_PHY->ANACTRL =
        (USBHS1_PHY->ANACTRL & ~USBPHY_ANACTRL_PFD_CLK_SEL_MASK) | USBPHY_ANACTRL_PFD_CLK_SEL((uint8_t)pfdClkSel);

    /* 480 MHz * 18 / n, where n = 18-3 */
    USBHS1_PHY->PFDA = (USBHS1_PHY->PFDA & ~USBPHY_PFDA_PFD0_FRAC_MASK) | USBPHY_PFDA_PFD0_FRAC((uint8_t)pfdDiv);

    /* Ungate the PFD clock */
    USBHS1_PHY->PFDA &= ~USBPHY_PFDA_PFD0_CLKGATE_MASK;

    return kStatus_Success;
}

/* Get UsbPfdClk */
static uint32_t CLOCK_GetUsbPfdClkFreq(void)
{
    uint32_t pfdDiv       = 0U;
    uint32_t pfdClkSel    = 0U;
    uint32_t pfdOutClk    = 0U;
    uint32_t usbPhyClkSrc = 0U;
    uint32_t freq         = 0U;

    if ((0U != (USBHS1_PHY->CTRL & USBPHY_CTRL_CLKGATE_MASK)) ||
        (0U != (USBHS1_PHY->PFDA & USBPHY_PFDA_PFD0_CLKGATE_MASK)))
    {
        return 0U;
    }

    pfdDiv    = (USBHS1_PHY->PFDA & USBPHY_PFDA_PFD0_FRAC_MASK) >> USBPHY_PFDA_PFD0_FRAC_SHIFT;
    pfdClkSel = (USBHS1_PHY->ANACTRL & USBPHY_ANACTRL_PFD_CLK_SEL_MASK) >> USBPHY_ANACTRL_PFD_CLK_SEL_SHIFT;

    if ((pfdDiv < 18U) || (pfdDiv > 35U))
    {
        return 0U;
    }

    pfdOutClk = 480000000U / pfdDiv * 18U;

    /* pfdClkSel:0 - USB PHY CLK Source, 1 - PFD clock/4, 2 - PFD clock/2, 3 - PFD clock */
    if (pfdClkSel == 0U)
    {
        usbPhyClkSrc = (MRCC0->MRCC_USB1_PHY_CLKSEL & MRCC_MRCC_USB1_PHY_CLKSEL_MUX_MASK);

        if (usbPhyClkSrc == 1U)
        {
            freq = CLOCK_GetFroHfFreq();
        }
        else if (usbPhyClkSrc == 2U)
        {
            freq = CLOCK_GetExtClkFreq();
        }
        else
        {
            freq = 0U;
        }
    }
    else if (pfdClkSel == 1U)
    {
        freq = (pfdOutClk >> 2U);
    }
    else if (pfdClkSel == 2U)
    {
        freq = (pfdOutClk >> 1U);
    }
    else
    {
        freq = pfdOutClk;
    }

    return freq;
}

/* Get ENET TX CLK */
/*! brief  Initialize the ENET TX CLK to given frequency.
 *  return Nothing
 */
void CLOCK_SetupEnetTxClk(uint32_t iFreq)
{
    s_Enet_Tx_Clk_Freq = iFreq;

    return;
}

/* Get ENET TX CLK */
/*! brief  Return Frequency of ENET TX CLK
 *  return Frequency of ENET TX CLK
 */
uint32_t CLOCK_GetEnetTxClkFreq(void)
{
    return s_Enet_Tx_Clk_Freq;
}

/* Get MAIN Clk */
/*! brief  Return Frequency of Core System
 *  return Frequency of Core System
 */
uint32_t CLOCK_GetMainClk(void)
{
    uint32_t freq = 0U;

    switch ((SCG0->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT)
    {
        case 1U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 2U:
            freq = CLOCK_GetFro12MFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 4U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkFreq() / ((SCG0->SPLLCSR & SCG_SPLLCSR_SPLL_DIV2_EN_MASK) ? 2U : 1U);
            break;
        case 7U:
            freq = CLOCK_GetUsbPfdClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/*! brief  Return Frequency of core
 *  return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void)
{
    return CLOCK_GetMainClk() / ((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) + 1U);
}

/* Get CTimer Clk */
/*! brief  Return Frequency of CTimer functional Clock
 *  return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    assert(id <= 4U);

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_CTIMER0_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_CTIMER1_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_CTIMER2_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER2_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_CTIMER3_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER3_CLKDIV;
            break;
        case 4U:
            clksel = MRCC0->MRCC_CTIMER4_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER4_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_CTIMER0_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetLposcFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of LPI2C functional Clock
 *  return Frequency of LPI2C functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    assert(id <= 4U);

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_LPI2C0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_LPI2C1_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_LPI2C2_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C2_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_LPI2C3_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C3_CLKDIV;
            break;
        case 4U:
            clksel = MRCC0->MRCC_LPI2C4_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C4_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_LPI2C0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of LPSPI Clock
 *  return Frequency of LPSPI Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    assert(id <= 5U);

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_LPSPI0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_LPSPI1_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_LPSPI2_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI2_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_LPSPI3_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI3_CLKDIV;
            break;
        case 4U:
            clksel = MRCC0->MRCC_LPSPI4_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI4_CLKDIV;
            break;
        case 5U:
            clksel = MRCC0->MRCC_LPSPI5_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI5_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_LPSPI0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPSPI0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of LPUART Clock
 *  return Frequency of LPUART Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    assert(id <= 5U);

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_LPUART0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_LPUART1_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_LPUART2_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART2_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_LPUART3_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART3_CLKDIV;
            break;
        case 4U:
            clksel = MRCC0->MRCC_LPUART4_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART4_CLKDIV;
            break;
        case 5U:
            clksel = MRCC0->MRCC_LPUART5_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART5_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_LPUART0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetLposcFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/* Get I3C Clk */
/*! brief  Return Frequency of I3C Clock
 *  return Frequency of I3C Clock
 */
uint32_t CLOCK_GetI3CFClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    assert(id <= 3U);

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_I3C0_FCLK_CLKSEL;
            clkdiv = MRCC0->MRCC_I3C0_FCLK_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_I3C1_FCLK_CLKSEL;
            clkdiv = MRCC0->MRCC_I3C1_FCLK_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_I3C2_FCLK_CLKSEL;
            clkdiv = MRCC0->MRCC_I3C2_FCLK_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_I3C3_FCLK_CLKSEL;
            clkdiv = MRCC0->MRCC_I3C3_FCLK_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_I3C0_FCLK_CLKSEL;
            clkdiv = MRCC0->MRCC_I3C0_FCLK_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of LPTMR Clock
 *  return Frequency of LPTMR Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_LPTMR0_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_LPTMR0_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of OSTIMER
 *  return Frequency of OSTIMER Clock
 */
uint32_t CLOCK_GetOstimerClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_OSTIMER0_CLKSEL);

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 1U:
            freq = CLOCK_GetOsc32KFreq(1);
            break;
        case 2U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/*! brief  Return Frequency of Adc Clock
 *  return Frequency of Adc.
 */
uint32_t CLOCK_GetAdcClkFreq(uint32_t id)
{
    uint32_t freq = 0U;
    assert(id <= 1);

    uint32_t clksel = MRCC0->MRCC_ADC_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_ADC_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetUsbPllFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of Dac Clock
 *  return Frequency of Dac.
 */
uint32_t CLOCK_GetDacClkFreq(uint32_t id)
{
    uint32_t freq = 0U;
    assert(id <= 1);

    uint32_t clksel = (id == 0) ? (MRCC0->MRCC_DAC0_CLKSEL) : (MRCC0->MRCC_DAC1_CLKSEL);
    uint32_t clkdiv = (id == 0) ? (MRCC0->MRCC_DAC0_CLKDIV) : (MRCC0->MRCC_DAC1_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CMP Function Clock
 *  return Frequency of CMP Function.
 */
uint32_t CLOCK_GetCmpFClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_CMP0_FUNC_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CMP Round Robin Clock
 *  return Frequency of CMP Round Robin.
 */
uint32_t CLOCK_GetCmpRRClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_CMP0_RR_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Trace Clock
 *  return Frequency of Trace.
 */
uint32_t CLOCK_GetTraceClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_DBG_TRACE_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_DBG_TRACE_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case 1U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CLKOUT Clock
 *  return Frequency of CLKOUT.
 */
uint32_t CLOCK_GetClkoutClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_CLKOUT_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_CLKOUT_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFro12MFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 3U:
            freq = CLOCK_GetLposcFreq();
            break;
        case 5U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        case 6U:
            freq = CLOCK_GetFreq(kCLOCK_SLOW_CLK);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Systick Clock
 *  return Frequency of Systick.
 */
uint32_t CLOCK_GetSystickClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_SYSTICK_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_SYSTICK_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case 1U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of dt0 Clock
 *  return Frequency of dt0.
 */
uint32_t CLOCK_GetWwdt0ClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clkdiv = (MRCC0->MRCC_WWDT0_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    freq = CLOCK_GetClk1MFreq();

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Wwdt1 Clock
 *  return Frequency of Wwdt1.
 */
uint32_t CLOCK_GetWwdt1ClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_WWDT1_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_WWDT1_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 1U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 3U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of FlexCAN FCLK
 *  return Frequency of FlexCAN FCLK.
 */
/*! brief  Return Frequency of FlexCAN Clock
 *  param  id : FlexCAN instance ID
 *  return Frequency of FlexCAN Clock.
 */
uint32_t CLOCK_GetFlexcanClkFreq(uint32_t id)
{
    uint32_t freq = 0U;
    assert(id <= 1U);

    uint32_t clksel = (id == 0) ? (MRCC0->MRCC_FLEXCAN0_CLKSEL) : (MRCC0->MRCC_FLEXCAN1_CLKSEL);
    uint32_t clkdiv = (id == 0) ? (MRCC0->MRCC_FLEXCAN0_CLKDIV) : (MRCC0->MRCC_FLEXCAN1_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4:
            freq = CLOCK_GetUsbPllFreq();
            break;
        case 6:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Flexspi CLK
 *  return Frequency of Flexspi CLK.
 */
uint32_t CLOCK_GetFlexspiClkFreq(void)
{
    uint32_t freq = 0U;

    uint32_t clksel = MRCC0->MRCC_FLEXSPI0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_FLEXSPI0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 4U:
            freq = CLOCK_GetUsbPfdClkFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of TSI CLK
 *  return Frequency of TSI CLK.
 */
uint32_t CLOCK_GetTsiClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_TSI0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_TSI0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of ENET MRR CLK
 *  return Frequency of ENET MRR CLK.
 */
uint32_t CLOCK_GetEnetRmiiClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_RMII_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_RMII_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of ENET PTP REF CLK
 *  return Frequency of ENET PTP REF CLK.
 */
uint32_t CLOCK_GetEnetPtpRefClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_E1588_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_E1588_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetEnetTxClkFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of TENBASET_PHY CLK
 *  return Frequency of TENBASET_PHY CLK.
 */
uint32_t CLOCK_GetTenbaset_PhyClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_T1S0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_T1S0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of ESPI CLK
 *  return Frequency of ESPI CLK.
 */
uint32_t CLOCK_GetEspiClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC0->MRCC_ESPI0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_ESPI0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/*! brief  Return Frequency of FLEXIO FCLK
 *  return Frequency of FLEXIO FCLK.
 */
uint32_t CLOCK_GetFlexioClkFreq(void)
{
    uint32_t freq = 0U;

    uint32_t clksel = MRCC0->MRCC_FLEXIO0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_FLEXIO0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 6U:
            freq = CLOCK_GetPll1ClkDivFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}
/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config)
{
    SCG0->SIRCTCFG = SCG_SIRCTCFG_TRIMDIV(config.trimDiv) | SCG_SIRCTCFG_TRIMSRC(config.trimSrc);

    if (kSCG_SircTrimNonUpdate == config.trimMode)
    {
        SCG0->SIRCSTAT = (SCG0->SIRCSTAT & ~SCG_SIRCSTAT_CLTRIM_MASK) | SCG_SIRCSTAT_CCOTRIM(config.cltrim);
        SCG0->SIRCSTAT = (SCG0->SIRCSTAT & ~SCG_SIRCSTAT_CCOTRIM_MASK) | SCG_SIRCSTAT_CCOTRIM(config.ccotrim);
    }

    /* Set trim mode. */
    SCG0->SIRCCSR =
        (SCG0->SIRCCSR & ~(SCG_SIRCCSR_SIRCTREN_MASK | SCG_SIRCCSR_SIRCTRUP_MASK)) | (uint32_t)config.trimMode;

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
        return (status_t)kStatus_Fail;
    }

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCERR_MASK) == SCG_SIRCCSR_SIRCERR_MASK)
    {
        return (status_t)kStatus_Fail;
    }

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_TRIM_LOCK_MASK) == 0U)
    {
        return (status_t)kStatus_Fail;
    }

    return (status_t)kStatus_Success;
}

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the
 * error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode)
{
    uint32_t reg = SCG0->SOSCCSR;

    reg &= ~(SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG0->SOSCCSR = reg;
}

/*!
 * @brief   Set the additional number of wait-states added to account for the
 * ratio of system clock period to flash access time during full speed power
 * mode.
 * @param   system_freq_hz  : Input frequency
 * @param   mode            : Active run mode (voltage level).
 * @return  success or fail status
 */
status_t CLOCK_SetFLASHAccessCyclesForFreq(uint32_t system_freq_hz, run_mode_t mode)
{
    uint32_t num_wait_states_added = 0U;
    switch ((uint32_t)mode)
    {
        case (uint32_t)kMD_Mode:
        {
            if (system_freq_hz > 48000000U)
            {
                return kStatus_Fail;
            }
            else if (system_freq_hz > 24000000U)
            {
                num_wait_states_added = 1U;
            }
            else
            {
                num_wait_states_added = 0U;
            }
            break;
        }
        case (uint32_t)kSD_Mode:
        {
            if (system_freq_hz > 120000000U)
            {
                return kStatus_Fail;
            }
            else if (system_freq_hz > 60000000U)
            {
                num_wait_states_added = 2U;
            }
            else if (system_freq_hz > 30000000U)
            {
                num_wait_states_added = 1U;
            }
            else
            {
                num_wait_states_added = 0U;
            }
            break;
        }
        case (uint32_t)kOD_Mode:
        {
            if (system_freq_hz > 240000000U)
            {
                return kStatus_Fail;
            }
            else if (system_freq_hz > 200000000U)
            {
                num_wait_states_added = 5U;
            }
            else if (system_freq_hz > 160000000U)
            {
                num_wait_states_added = 4U;
            }
            else if (system_freq_hz > 80000000U)
            {
                num_wait_states_added = 2U;
            }
            else if (system_freq_hz > 40000000U)
            {
                num_wait_states_added = 1U;
            }
            else
            {
                num_wait_states_added = 0U;
            }
            break;
        }
        default:
            num_wait_states_added = 0U;
            break;
    }

    /* additional wait-states are added */
    FMU0->FCTRL = (FMU0->FCTRL & ~FMU_FCTRL_RWSC_MASK) | FMU_FCTRL_RWSC(num_wait_states_added);

    return kStatus_Success;
}

/* Get SYSTEM PLL1 Clk */
/*! @brief  Return Frequency of PLL1
 *  @return Frequency of PLL1
 */
uint32_t CLOCK_GetPll1ClkFreq(void)
{
    uint32_t clkRate = 0;
    uint32_t prediv, postdiv;
    float workRate = 0.0F;

    /* Get the input clock frequency of PLL. */
    clkRate = CLOCK_GetPLL1InClockRate();

    /* If PLL1 is work */
    if (CLOCK_IsPLL1Locked() == true)
    {
        prediv  = findPll1PreDiv();
        postdiv = findPll1PostDiv();
        /* Adjust input clock */
        clkRate = clkRate / prediv;
        /* MDEC used for rate */
        workRate = (float)clkRate * (float)findPll1MMult();
        workRate /= (float)postdiv;
    }

    return (uint32_t)workRate;
}

/*!
 * @brief Sets the PLL1 monitor mode.
 *
 * This function sets the PLL1 monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetPll1MonitorMode(scg_pll1_monitor_mode_t mode)
{
    uint32_t reg = SCG0->SPLLCSR;

    reg &= ~(SCG_SPLLCSR_SPLLCM_MASK | SCG_SPLLCSR_SPLLCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG0->SPLLCSR = reg;
}

/* Return PLL1 input clock rate */
uint32_t CLOCK_GetPLL1InClockRate(void)
{
    uint32_t clkRate = 0U;

    switch ((SCG0->SPLLCTRL & SCG_SPLLCTRL_SOURCE_MASK) >> SCG_SPLLCTRL_SOURCE_SHIFT)
    {
        case 0x00U:
            clkRate = CLOCK_GetExtClkFreq();
            break;
        case 0x01U:
            clkRate = CLOCK_GetClk48MFreq();
            break;
        case 0x03U:
            clkRate = CLOCK_GetFro12MFreq();
            break;
        default:
            clkRate = 0U;
            break;
    }

    return clkRate;
}

/* Return PLL output clock rate from setup structure */
/*! brief    Return PLL0 output clock rate from setup structure
 *  param    pSetup : Pointer to a PLL setup structure
 *  return   PLL0 output clock rate the setup structure will generate
 */
uint32_t CLOCK_GetPLLOutFromSetup(pll_setup_t *pSetup)
{
    uint32_t clkRate = 0;
    uint32_t prediv, postdiv;
    float workRate = 0.0F;

    /* Get the input clock frequency of PLL. */
    clkRate = CLOCK_GetPLLInClockRateFromSetup(pSetup);

    prediv  = findPllPreDivFromSetup(pSetup);
    postdiv = findPllPostDivFromSetup(pSetup);
    /* Adjust input clock */
    clkRate = clkRate / prediv;
    /* MDEC used for rate */
    workRate = (float)clkRate * (float)findPllMMultFromSetup(pSetup);
    workRate /= (float)postdiv;

    return (uint32_t)workRate;
}

/* Set PLL output based on the passed PLL setup data */
/*! brief    Set PLL output based on the passed PLL setup data
 *  param    pControl    : Pointer to populated PLL control structure to generate setup with
 *  param    pSetup      : Pointer to PLL setup structure to be filled
 *  return   PLL_ERROR_SUCCESS on success, or PLL setup error code
 *  note Actual frequency for setup may vary from the desired frequency based on the
 *  accuracy of input clocks, rounding, non-fractional PLL mode, etc.
 */
pll_error_t CLOCK_SetupPLLData(pll_config_t *pControl, pll_setup_t *pSetup)
{
    uint32_t inRate;
    bool useSS = (bool)((pControl->flags & PLL_CONFIGFLAG_FORCENOFRACT) == 0UL);

    pll_error_t pllError;

    /* Get PLL Input Clock Rate */
    switch (pControl->inputSource)
    {
        case (uint32_t)kPll_ClkSrcSysOsc:
            inRate = CLOCK_GetExtClkFreq();
            break;
        case (uint32_t)kPll_ClkSrcFirc:
            inRate = CLOCK_GetClk48MFreq();
            break;
        case (uint32_t)kPll_ClkSrcSirc:
            inRate = CLOCK_GetFro12MFreq();
            break;
        default:
            inRate = 0U;
            break;
    }

    /* PLL flag options */
    pllError = CLOCK_GetPllConfig(inRate, pControl->desiredRate, pSetup, useSS);
    pSetup->pllctrl |= (uint32_t)pControl->inputSource;
    if ((useSS) && (pllError == kStatus_PLL_Success))
    {
        /* If using SS mode, then some tweaks are made to the generated setup */
        pSetup->pllsscg[1] |= (uint32_t)pControl->ss_mf | (uint32_t)pControl->ss_mr | (uint32_t)pControl->ss_mc;
        if (pControl->mfDither)
        {
            pSetup->pllsscg[1] |= (1UL << SCG_SPLLSSCG1_DITHER_SHIFT);
        }
    }

    return pllError;
}

/* Setup PLL1 Frequency from pre-calculated value */
/**
 * brief Set PLL1 output from PLL setup structure (precise frequency)
 * param pSetup  : Pointer to populated PLL setup structure
 * return    kStatus_PLL_Success on success, or PLL setup error code
 * note  This function will power off the PLL, setup the PLL with the
 * new setup data, and then optionally powerup the PLL, wait for PLL lock,
 * and adjust system voltages to the new PLL rate. The function will not
 * alter any source clocks (ie, main systen clock) that may use the PLL,
 * so these should be setup prior to and after exiting the function.
 */
pll_error_t CLOCK_SetPLL1Freq(const pll_setup_t *pSetup)
{
    uint32_t inRate, clkRate, prediv;

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    /* Power off PLL1 and disable PLL1 clock during setup changes */
    SCG0->SPLLCSR &= ~(SCG_SPLLCSR_SPLLPWREN_MASK | SCG_SPLLCSR_SPLLCLKEN_MASK);

    /* Write PLL setup data */
    SCG0->SPLLCTRL  = pSetup->pllctrl;
    SCG0->SPLLNDIV  = pSetup->pllndiv;
    SCG0->SPLLNDIV  = pSetup->pllndiv | (1UL << SCG_SPLLNDIV_NREQ_SHIFT); /* latch */
    SCG0->SPLLPDIV  = pSetup->pllpdiv;
    SCG0->SPLLPDIV  = pSetup->pllpdiv | (1UL << SCG_SPLLPDIV_PREQ_SHIFT); /* latch */
    SCG0->SPLLMDIV  = pSetup->pllmdiv;
    SCG0->SPLLMDIV  = pSetup->pllmdiv | (1UL << SCG_SPLLMDIV_MREQ_SHIFT); /* latch */
    SCG0->SPLLSSCG0 = pSetup->pllsscg[0];
    SCG0->SPLLSSCG1 = pSetup->pllsscg[1];

    /* Unlock SPLLLOCK_CNFG register */
    SCG0->TRIM_LOCK = 0x5a5a0001;

    /* Configure lock time of APLL stable, value = 500�s/x+300, where x is the period of clk_ref (clk_in/N). */
    inRate = CLOCK_GetPLL1InClockRate();
    prediv = findPll1PreDiv();
    /* Adjust input clock */
    clkRate             = inRate / prediv;
    SCG0->SPLLLOCK_CNFG = SCG_SPLLLOCK_CNFG_LOCK_TIME(clkRate / 2000U + 300U);

    /* Power on PLL1 and enable PLL1 clock */
    SCG0->SPLLCSR |= (SCG_SPLLCSR_SPLLPWREN_MASK | SCG_SPLLCSR_SPLLCLKEN_MASK);

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* Wait for APLL lock */
    while (CLOCK_IsPLL1Locked() == false)
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_PLL_Timeout;
        }
#endif
    }

    if (pSetup->pllRate != CLOCK_GetPll1ClkFreq())
    {
        return kStatus_PLL_OutputError;
    }

    return kStatus_PLL_Success;
}

/* Find SELP, SELI, and SELR values for raw M value, max M = MVALMAX */
static void pllFindSel(uint32_t M, uint32_t *pSelP, uint32_t *pSelI, uint32_t *pSelR)
{
    uint32_t seli, selp;
    /* bandwidth: compute selP from Multiplier */
    if ((SCG0->SPLLCTRL & SCG_SPLLCTRL_LIMUPOFF_MASK) == 0UL) /* normal mode */
    {
        selp = (M >> 2U) + 1U;
        if (selp >= 31U)
        {
            selp = 31U;
        }
        *pSelP = selp;

        if (M >= 8000UL)
        {
            seli = 1UL;
        }
        else if (M >= 122UL)
        {
            seli = (uint32_t)(8000UL / M); /*floor(8000/M) */
        }
        else
        {
            seli = 2UL * ((uint32_t)(M / 4UL)) + 3UL; /* 2*floor(M/4) + 3 */
        }

        if (seli >= 63UL)
        {
            seli = 63UL;
        }
        *pSelI = seli;

        *pSelR = 0U;
    }
    else
    {
        /* Note: If the spread spectrum and fractional mode, choose N to ensure 3 MHz < Fin/N < 5 MHz */
        *pSelP = 3U;
        *pSelI = 4U;
        *pSelR = 4U;
    }
}

/* Get predivider (N) from PLL1 NDIV setting */
static uint32_t findPll1PreDiv(void)
{
    uint32_t preDiv = 1UL;

    /* Direct input is not used? */
    if ((SCG0->SPLLCTRL & SCG_SPLLCTRL_BYPASSPREDIV_MASK) == 0UL)
    {
        preDiv = SCG0->SPLLNDIV & SCG_SPLLNDIV_NDIV_MASK;
        if (preDiv == 0UL)
        {
            preDiv = 1UL;
        }
    }
    return preDiv;
}

/* Get postdivider (P) from PLL1 PDIV setting. */
static uint32_t findPll1PostDiv(void)
{
    uint32_t postDiv = 1UL;

    if ((SCG0->SPLLCTRL & SCG_SPLLCTRL_BYPASSPOSTDIV_MASK) == 0UL)
    {
        if ((SCG0->SPLLCTRL & SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK) != 0UL)
        {
            postDiv = SCG0->SPLLPDIV & SCG_SPLLPDIV_PDIV_MASK;
        }
        else
        {
            postDiv = 2UL * (SCG0->SPLLPDIV & SCG_SPLLPDIV_PDIV_MASK);
        }
        if (postDiv == 0UL)
        {
            postDiv = 2UL;
        }
    }

    return postDiv;
}

/* Get multiplier (M) from PLL1 MDEC. */
static float findPll1MMult(void)
{
    float mMult;
    float mMult_fract;
    uint32_t mMult_int;

    if ((SCG0->SPLLSSCG1 & SCG_SPLLSSCG1_SEL_SS_MDIV_MASK) == 0UL)
    {
        mMult = (float)(uint32_t)(SCG0->SPLLMDIV & SCG_SPLLMDIV_MDIV_MASK);
    }
    else
    {
        mMult_int = ((SCG0->SPLLSSCG1 & SCG_SPLLSSCG1_SS_MDIV_MSB_MASK) << 7U);
        mMult_int = mMult_int | ((SCG0->SPLLSSCG0) >> PLL_SSCG_MD_INT_P);
        mMult_fract =
            ((float)(uint32_t)((SCG0->SPLLSSCG0) & PLL_SSCG_MD_FRACT_M) / (float)(uint32_t)(1UL << PLL_SSCG_MD_INT_P));
        mMult = (float)mMult_int + mMult_fract;
    }
    if (0ULL == ((uint64_t)mMult))
    {
        mMult = 1.0F;
    }
    return mMult;
}

/* Find greatest common divisor between m and n */
static uint32_t FindGreatestCommonDivisor(uint32_t m, uint32_t n)
{
    uint32_t tmp;

    while (n != 0U)
    {
        tmp = n;
        n   = m % n;
        m   = tmp;
    }

    return m;
}

#if (defined(CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT) && CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT)
/* Alloct the static buffer for cache. */
static pll_setup_t s_PllSetupCacheStruct[CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT];
static uint32_t s_FinHzCache[CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT]  = {0};
static uint32_t s_FoutHzCache[CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT] = {0};
static bool s_UseSSCache[CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT]      = {false};
static uint32_t s_PllSetupCacheIdx                                  = 0U;
#endif /* CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT */

/*
 * Calculate the PLL setting values from input clock freq to output freq.
 */
static pll_error_t CLOCK_GetPllConfig(uint32_t finHz, uint32_t foutHz, pll_setup_t *pSetup, bool useSS)
{
    pll_error_t retErr;
#if (defined(CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT) && CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT)
    uint32_t i;

    for (i = 0U; i < CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT; i++)
    {
        if ((finHz == s_FinHzCache[i]) && (foutHz == s_FoutHzCache[i]) && (useSS == s_UseSSCache[i]))
        {
            /* Hit the target in cache buffer. */
            pSetup->pllctrl    = s_PllSetupCacheStruct[i].pllctrl;
            pSetup->pllndiv    = s_PllSetupCacheStruct[i].pllndiv;
            pSetup->pllmdiv    = s_PllSetupCacheStruct[i].pllmdiv;
            pSetup->pllpdiv    = s_PllSetupCacheStruct[i].pllpdiv;
            pSetup->pllsscg[0] = s_PllSetupCacheStruct[i].pllsscg[0];
            pSetup->pllsscg[1] = s_PllSetupCacheStruct[i].pllsscg[1];
            retErr             = kStatus_PLL_Success;
            break;
        }
    }

    if (i < CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT)
    {
        return retErr;
    }
#endif /* CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT */

    retErr = CLOCK_GetPllConfigInternal(finHz, foutHz, pSetup, useSS);

#if (defined(CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT) && CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT)
    /* Cache the most recent calulation result into buffer. */
    s_FinHzCache[s_PllSetupCacheIdx]  = finHz;
    s_FoutHzCache[s_PllSetupCacheIdx] = foutHz;
    s_UseSSCache[s_PllSetupCacheIdx]  = useSS;

    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllctrl    = pSetup->pllctrl;
    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllndiv    = pSetup->pllndiv;
    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllmdiv    = pSetup->pllmdiv;
    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllpdiv    = pSetup->pllpdiv;
    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllsscg[0] = pSetup->pllsscg[0];
    s_PllSetupCacheStruct[s_PllSetupCacheIdx].pllsscg[1] = pSetup->pllsscg[1];
    /* Update the index for next available buffer. */
    s_PllSetupCacheIdx = (s_PllSetupCacheIdx + 1U) % CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT;
#endif /* CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT */

    return retErr;
}

/*
 * Set PLL output based on desired output rate.
 * In this function, the it calculates the PLL0 setting for output frequency from input clock
 * frequency. The calculation would cost a few time. So it is not recommaned to use it frequently.
 * the "pllctrl", "pllndiv", "pllpdiv", "pllmdiv" would updated in this function.
 */
static pll_error_t CLOCK_GetPllConfigInternal(uint32_t finHz, uint32_t foutHz, pll_setup_t *pSetup, bool useSS)
{
    uint32_t nDivOutHz, fccoHz;
    uint32_t pllPreDivider, pllMultiplier, pllPostDivider;
    uint32_t pllDirectInput, pllDirectOutput;
    uint32_t pllSelP, pllSelI, pllSelR, uplimoff;

    /* Baseline parameters (no input or output dividers) */
    pllPreDivider   = 1U; /* 1 implies pre-divider will be disabled */
    pllPostDivider  = 1U; /* 1 implies post-divider will be disabled */
    pllDirectOutput = 1U;

    /* Verify output rate parameter */
    if (foutHz > PLL_MAX_CCO_FREQ_MHZ)
    {
        /* Maximum PLL output with post divider=1 cannot go above this frequency */
        return kStatus_PLL_OutputTooHigh;
    }
    if (foutHz < (PLL_MIN_CCO_FREQ_MHZ / (PVALMAX << 1U)))
    {
        /* Minmum PLL output with maximum post divider cannot go below this frequency */
        return kStatus_PLL_OutputTooLow;
    }

    /* If using SS mode, input clock needs to be between 3MHz and 20MHz */
    if (useSS)
    {
        /* Verify input rate parameter */
        if (finHz < PLL_MIN_IN_SSMODE)
        {
            /* Input clock into the PLL cannot be lower than this */
            return kStatus_PLL_InputTooLow;
        }
        /* PLL input in SS mode must be under 20MHz */
        if (finHz > (PLL_MAX_IN_SSMODE * NVALMAX))
        {
            return kStatus_PLL_InputTooHigh;
        }
    }
    else
    {
        /* Verify input rate parameter */
        if (finHz < PLL_LOWER_IN_LIMIT)
        {
            /* Input clock into the PLL cannot be lower than this */
            return kStatus_PLL_InputTooLow;
        }
        if (finHz > PLL_HIGHER_IN_LIMIT)
        {
            /* Input clock into the PLL cannot be higher than this */
            return kStatus_PLL_InputTooHigh;
        }
    }

    /* Find the optimal CCO frequency for the output and input that
       will keep it inside the PLL CCO range. This may require
       tweaking the post-divider for the PLL. */
    fccoHz = foutHz;
    while (fccoHz < PLL_MIN_CCO_FREQ_MHZ)
    {
        /* CCO output is less than minimum CCO range, so the CCO output
           needs to be bumped up and the post-divider is used to bring
           the PLL output back down. */
        pllPostDivider++;
        if (pllPostDivider > PVALMAX)
        {
            return kStatus_PLL_OutsideIntLimit;
        }

        /* Target CCO goes up, PLL output goes down */
        /* divide-by-2 divider in the post-divider is always work*/
        fccoHz          = foutHz * (pllPostDivider * 2U);
        pllDirectOutput = 0U;
    }

    /* Determine if a pre-divider is needed to get the best frequency */
    if ((finHz > PLL_LOWER_IN_LIMIT) && (fccoHz >= finHz) && (useSS == false))
    {
        uint32_t a = FindGreatestCommonDivisor(fccoHz, finHz);

        if (a > PLL_LOWER_IN_LIMIT)
        {
            a = finHz / a;
            if ((a != 0U) && (a < PLL_MAX_N_DIV))
            {
                pllPreDivider = a;
            }
        }
    }

    /* Bypass pre-divider hardware if pre-divider is 1 */
    if (pllPreDivider > 1U)
    {
        pllDirectInput = 0U;
    }
    else
    {
        pllDirectInput = 1U;
    }

    /* Determine PLL multipler */
    nDivOutHz     = (finHz / pllPreDivider);
    pllMultiplier = (fccoHz / nDivOutHz);

    /* Find optimal values for filter */
    if (useSS == false)
    {
        /* Will bumping up M by 1 get us closer to the desired CCO frequency? */
        if ((nDivOutHz * ((pllMultiplier * 2U) + 1U)) < (fccoHz * 2U))
        {
            pllMultiplier++;
        }

        /* Setup filtering */
        pllFindSel(pllMultiplier, &pllSelP, &pllSelI, &pllSelR);
        uplimoff = 0U;

        /* Get encoded value for M (mult) and use manual filter, disable SS mode */
        pSetup->pllmdiv = (uint32_t)PLL_MDIV_VAL_SET(pllMultiplier);
        pSetup->pllsscg[1] &= ~SCG_SPLLSSCG1_SEL_SS_MDIV_MASK;
    }
    else
    {
        uint64_t fc;

        /* Filtering will be handled by SSC */
        pllSelR  = 0UL;
        pllSelI  = 0UL;
        pllSelP  = 0UL;
        uplimoff = 1U;

        /* The PLL multiplier will get very close and slightly under the
           desired target frequency. A small fractional component can be
           added to fine tune the frequency upwards to the target. */
        fc = ((uint64_t)(uint32_t)(fccoHz % nDivOutHz) << 25UL) / nDivOutHz;

        /* Set multiplier */
        pSetup->pllsscg[0] =
            (uint32_t)((PLL_SSCG_MD_INT_SET(pllMultiplier) | PLL_SSCG_MD_FRACT_SET((uint32_t)fc)) & 0xFFFFFFFFU);
        pSetup->pllsscg[1] = (uint32_t)(PLL_SSCG_MD_INT_SET(pllMultiplier) >> 32U) | SCG_SPLLSSCG1_SEL_SS_MDIV_MASK;
    }

    /* Get encoded values for N (prediv) and P (postdiv) */
    pSetup->pllndiv = PLL_NDIV_VAL_SET(pllPreDivider);
    pSetup->pllpdiv = PLL_PDIV_VAL_SET(pllPostDivider);

    /* PLL control */
    pSetup->pllctrl = (pllSelR << SCG_SPLLCTRL_SELR_SHIFT) |                 /* Filter coefficient */
                      (pllSelI << SCG_SPLLCTRL_SELI_SHIFT) |                 /* Filter coefficient */
                      (pllSelP << SCG_SPLLCTRL_SELP_SHIFT) |                 /* Filter coefficient */
                      (uplimoff << SCG_SPLLCTRL_LIMUPOFF_SHIFT) |            /* SS/fractional mode disabled */
                      (pllDirectInput << SCG_SPLLCTRL_BYPASSPREDIV_SHIFT) |  /* Bypass pre-divider? */
                      (pllDirectOutput << SCG_SPLLCTRL_BYPASSPOSTDIV_SHIFT); /* Bypass post-divider? */

    return kStatus_PLL_Success;
}

/* Get PLL input clock rate from setup structure */
static uint32_t CLOCK_GetPLLInClockRateFromSetup(pll_setup_t *pSetup)
{
    uint32_t clkRate = 0U;

    switch ((pSetup->pllctrl & SCG_SPLLCTRL_SOURCE_MASK) >> SCG_SPLLCTRL_SOURCE_SHIFT)
    {
        case 0x00U:
            clkRate = CLOCK_GetExtClkFreq();
            break;
        case 0x01U:
            clkRate = CLOCK_GetClk48MFreq();
            break;
        case 0x03U:
            clkRate = CLOCK_GetFro12MFreq();
            break;
        default:
            clkRate = 0U;
            break;
    }

    return clkRate;
}

/* Get predivider (N) from from setup structure */
static uint32_t findPllPreDivFromSetup(pll_setup_t *pSetup)
{
    uint32_t preDiv = 1UL;

    /* Direct input is not used? */
    if ((pSetup->pllctrl & SCG_SPLLCTRL_BYPASSPREDIV_MASK) == 0UL)
    {
        preDiv = pSetup->pllndiv & SCG_SPLLNDIV_NDIV_MASK;
        if (preDiv == 0UL)
        {
            preDiv = 1UL;
        }
    }
    return preDiv;
}

/* Get postdivider (P) from from setup structure */
static uint32_t findPllPostDivFromSetup(pll_setup_t *pSetup)
{
    uint32_t postDiv = 1UL;

    if ((pSetup->pllctrl & SCG_SPLLCTRL_BYPASSPOSTDIV_MASK) == 0UL)
    {
        if ((pSetup->pllctrl & SCG_SPLLCTRL_BYPASSPOSTDIV2_MASK) != 0UL)
        {
            postDiv = pSetup->pllpdiv & SCG_SPLLPDIV_PDIV_MASK;
        }
        else
        {
            postDiv = 2UL * (pSetup->pllpdiv & SCG_SPLLPDIV_PDIV_MASK);
        }
        if (postDiv == 0UL)
        {
            postDiv = 2UL;
        }
    }

    return postDiv;
}

/* Get multiplier (M) from from setup structure */
static float findPllMMultFromSetup(pll_setup_t *pSetup)
{
    float mMult;
    float mMult_fract;
    uint32_t mMult_int;

    if ((pSetup->pllsscg[1] & SCG_SPLLSSCG1_SEL_SS_MDIV_MASK) == 0UL)
    {
        mMult = (float)(uint32_t)(pSetup->pllmdiv & SCG_SPLLMDIV_MDIV_MASK);
    }
    else
    {
        mMult_int   = ((pSetup->pllsscg[1] & SCG_SPLLSSCG1_SS_MDIV_MSB_MASK) << 7U);
        mMult_int   = mMult_int | ((pSetup->pllsscg[0]) >> PLL_SSCG_MD_INT_P);
        mMult_fract = ((float)(uint32_t)((pSetup->pllsscg[0]) & PLL_SSCG_MD_FRACT_M) /
                       (float)(uint32_t)(1UL << PLL_SSCG_MD_INT_P));
        mMult       = (float)mMult_int + mMult_fract;
    }
    if (0ULL == ((uint64_t)mMult))
    {
        mMult = 1.0F;
    }
    return mMult;
}

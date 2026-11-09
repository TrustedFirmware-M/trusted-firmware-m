/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_reset.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.reset"
#endif

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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define GET_REG_INDEX(x) ((uint32_t)(((uint32_t)(x) & 0xFF00U) >> 8))
#define GET_BIT_INDEX(x) ((uint32_t)((uint32_t)(x) & 0x00FFU))

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * param peripheral Assert reset to this peripheral. The enum argument contains
 * encoding of reset register and reset bit position in the reset register.
 */
status_t RESET_SetPeripheralReset(reset_ip_name_t peripheral)
{
    uint32_t regIndex             = GET_REG_INDEX(peripheral);
    uint32_t bitPos               = GET_BIT_INDEX(peripheral);
    uint32_t bitMask              = 1UL << bitPos;
    volatile uint32_t *pResetCtrl = &(MRCC0->MRCC_GLB_RST0);

    if (peripheral == NotAvail_RSTn)
    {
        return kStatus_Fail;
    }

    assert(bitPos < 32u);
    assert(regIndex < 5u);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    /* reset register is in MRCC */
    /* set bit */
    if (regIndex == 0U)
    {
        MRCC0->MRCC_GLB_RST0_SET = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST0);
    }
    else if (regIndex == 1U)
    {
        MRCC0->MRCC_GLB_RST1_SET = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST1);
    }
    else if (regIndex == 2U)
    {
        MRCC0->MRCC_GLB_RST2_SET = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST2);
    }
    else if (regIndex == 3U)
    {
        MRCC0->MRCC_GLB_RST3_SET = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST3);
    }
    else if (regIndex == 4U)
    {
        MRCC0->MRCC_GLB_RST4_SET = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST4);
    }
    else
    {
        /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
    }

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* wait until it reads 0b1 */
    while (0u == ((*pResetCtrl) & bitMask))
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;

    return kStatus_Success;
}

/*!
 * brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * param peripheral Clear reset to this peripheral. The enum argument contains
 * encoding of reset register and reset bit position in the reset register.
 */
status_t RESET_ClearPeripheralReset(reset_ip_name_t peripheral)
{
    uint32_t regIndex             = GET_REG_INDEX(peripheral);
    uint32_t bitPos               = GET_BIT_INDEX(peripheral);
    uint32_t bitMask              = 1UL << bitPos;
    volatile uint32_t *pResetCtrl = &(MRCC0->MRCC_GLB_RST0);

    if (peripheral == NotAvail_RSTn)
    {
        return kStatus_Fail;
    }

    assert(bitPos < 32u);
    assert(regIndex < 5u);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    /* reset register is in MRCC */
    /* clear bit */
    if (regIndex == 0U)
    {
        MRCC0->MRCC_GLB_RST0_CLR = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST0);
    }
    else if (regIndex == 1U)
    {
        MRCC0->MRCC_GLB_RST1_CLR = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST1);
    }
    else if (regIndex == 2U)
    {
        MRCC0->MRCC_GLB_RST2_CLR = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST2);
    }
    else if (regIndex == 3U)
    {
        MRCC0->MRCC_GLB_RST3_CLR = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST3);
    }
    else if (regIndex == 4U)
    {
        MRCC0->MRCC_GLB_RST4_CLR = bitMask;
        pResetCtrl               = &(MRCC0->MRCC_GLB_RST4);
    }
    else
    {
        /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
    }

#if (SOC_DRIVER_RETRY_TIMES != 0U)
    uint32_t waitTimes = SOC_DRIVER_RETRY_TIMES;
#endif
    /* wait until it reads 0b0 */
    while (bitMask == ((*pResetCtrl) & bitMask))
    {
#if (SOC_DRIVER_RETRY_TIMES != 0U)
        if (--waitTimes == 0U)
        {
            assert(false);
            return kStatus_Timeout;
        }
#endif
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;

    return kStatus_Success;
}

/*!
 * brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * param peripheral Peripheral to reset. The enum argument contains encoding of
 * reset register and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral)
{
    RESET_ClearPeripheralReset(peripheral);
    RESET_SetPeripheralReset(peripheral);
}

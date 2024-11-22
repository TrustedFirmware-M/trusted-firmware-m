/*
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "Driver_PPC.h"

#include "mxc_device.h"
#include "RTE_Device.h"
#include "spc.h"

/* Driver version */
#define ARM_PPC_DRV_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1,0)

#ifdef RTE_PPC

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_PPC_API_VERSION,
    ARM_PPC_DRV_VERSION
};

static ARM_DRIVER_VERSION ARM_PPC_GetVersion(void)
{
    return DriverVersion;
}

static int32_t PPC_Initialize(void)
{
    return ARM_DRIVER_OK;
}

static int32_t PPC_Uninitialize(void)
{
    return ARM_DRIVER_OK;
}

static int32_t PPC_ConfigPeriph(uint8_t periph,
                                ARM_PPC_SecAttr sec_attr,
                                ARM_PPC_PrivAttr priv_attr)
{
    mxc_spc_periph_t mxc_periph = (1U << periph);
    mxc_spc_priv_t mxc_priv;

    if (priv_attr == ARM_PPC_PRIV_ONLY) {
        mxc_priv = MXC_SPC_PRIVILEGED;
    } else {
        mxc_priv = MXC_SPC_UNPRIVILEGED;
    }

    if(sec_attr == ARM_PPC_SECURE_ONLY) {
        MXC_SPC_SetSecure(mxc_periph);
    } else {
        MXC_SPC_SetNonSecure(mxc_periph);
    }
    MXC_SPC_SetPrivAccess(mxc_periph, mxc_priv);

    return ARM_DRIVER_OK;
}

static uint32_t PPC_IsPeriphSecure(uint8_t periph)
{
    mxc_spc_periph_t mxc_periph = (1U << periph);

    if (MXC_SPC->apbsec & mxc_periph) {
        return 0; // Non-Secure
    } else {
        return 1; // Secure
    }
}

static uint32_t PPC_IsPeriphPrivOnly(uint8_t periph)
{
    mxc_spc_periph_t mxc_periph = (1U << periph);

    if (MXC_SPC->apbpriv & mxc_periph) {
        return 0; // unprivileged
    } else {
        return 1; // privileged
    }
}

static int32_t PPC_EnableInterrupt(void)
{
    MXC_SPC_PPC_EnableInt(MXC_F_SPC_PPC_INTEN_APBPPC);

    return ARM_DRIVER_OK;
}

static void PPC_DisableInterrupt(void)
{
    MXC_SPC_PPC_DisableInt(MXC_F_SPC_PPC_INTEN_APBPPC);
}

static void PPC_ClearInterrupt(void)
{
    MXC_SPC_PPC_ClearFlags(MXC_F_SPC_PPC_INTCLR_APBPPC);
}

static uint32_t PPC_InterruptState(void)
{
    if (MXC_SPC_PPC_GetFlags() & MXC_F_SPC_PPC_STATUS_APBPPC) {
        return 1; // pending interrupt
    } else {
        return 0; // no interrupt
    }
}

ARM_DRIVER_PPC Driver_PPC = {
    .GetVersion        = ARM_PPC_GetVersion,
    .Initialize        = PPC_Initialize,
    .Uninitialize      = PPC_Uninitialize,
    .ConfigPeriph      = PPC_ConfigPeriph,
    .IsPeriphSecure    = PPC_IsPeriphSecure,
    .IsPeriphPrivOnly  = PPC_IsPeriphPrivOnly,
    .EnableInterrupt   = PPC_EnableInterrupt,
    .DisableInterrupt  = PPC_DisableInterrupt,
    .ClearInterrupt    = PPC_ClearInterrupt,
    .InterruptState    = PPC_InterruptState
};
#endif /* RTE_PPC */

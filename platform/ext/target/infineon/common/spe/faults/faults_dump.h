/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FAULTS_DUMPS_H
#define FAULTS_DUMPS_H

#include "cmsis_compiler.h"
#include "cy_sysfault.h"
#include "ifx_utils.h"
#include "ifx_tfm_log_shim.h"

/**
 * \brief Print PPC violation fault information captured by fault peripheral when
 *        a locked PC tries to write to PC_MASK register.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_peri_msx_ppc_vio_fault(FAULT_STRUCT_Type *base)
{
    /* DATA0: The address of the violating transfer (peri_ms<>_mmio_ppc_vio_addr) */
    uint32_t fault_addr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(fault_addr);
    /* DATA1: The attributes of the violating transfer (peri_ms<>_mmio_ppc_vio_attr) */
    uint32_t fault_attr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA1);
    IFX_UNUSED(fault_attr);

    /* bits description
     * [31:24]: Indicates the Master ID of violating transfer
     * [18:16]: Type of security violation.
     *          b000 - No violation,
     *          b001 - Secure/Non-Secure access mismatch. (Valid only when SECEXT=1),
     *          b010 - Privilege/User access mismatch,
     *          b011 - PC access mismatch,
     *          b101 - AHB_ERROR response detected,
     *          other - reserved.
     *          If multiple violations occur at the same time, the HW will log
     *          the highest priority with the priority listed below.
     *          1st priority: PC access mismatch.
     *          2nd priority: Secure/Non-Secure access mismatch.
     *          3rd priority: Privilege/User access mismatch.
     *          4th priority: AHB_ERROR response detected.
     * [15:12]: Indicates the master interface transaction PC value
     *          when violation is detected
     * [9:0]:   Index to indicate which peripheral region has violated security access.
     *          Note that when above type field DATA1[18:16] = AHB_ERROR (b101),
     *          this field is not valid. */

    ERROR_RAW("PPC violations and bus-error\n");
    ERROR_RAW("\tAddress of the violating transfer: 0x%08x\n", fault_addr);

    ERROR_RAW("\tAttributes of the violating transfer: 0x%08x\n", fault_attr);
    ERROR_RAW("\t\tMaster ID: 0x%08x\n", (fault_attr >> 24) & 0xFFUL);
    ERROR_RAW("\t\tType: 0x%08x\n", (fault_attr >> 16) & 0x7UL);
    ERROR_RAW("\t\tTransaction PC: 0x%08x\n", (fault_attr >> 12) & 0xFUL);
    ERROR_RAW("\t\tPeripheral #: 0x%08x\n", (fault_attr >> 0) & 0x3FFUL);
}

/**
 * \brief Print PPC MMIO access violation fault information captured by fault peripheral.
 *
 * It's used to report PPC violation when a locked PC tries to write to PC_MASK register.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_peri_ppc_pc_mask_vio_fault(FAULT_STRUCT_Type *base)
{
    /* DATA0: The address of the violating transfer (peri_ms<>_mmio_ppc_vio_addr) */
    uint32_t fault_addr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(fault_addr);
    /* DATA1: The attributes of the violating transfer (peri_ms<>_mmio_ppc_vio_attr) */
    uint32_t fault_attr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA1);
    IFX_UNUSED(fault_attr);

    /* bits description
     * [31:24]: Indicates the Master ID of violating transfer
     * [18:16]: Type of security violation.
     *          b100 - write access to PC_MASK registers from locked PC,
     *          other - reserved.
     * [15:12]: Indicates the master interface transaction PC value
     *          when violation is detected
     * [9:0]:   Index to indicate which peripheral region has violated security access.
     *          Note that when above type field DATA1[18:16] = AHB_ERROR (b101),
     *          this field is not valid. */

    ERROR_RAW("PPC MMIO violation\n");
    ERROR_RAW("\tAddress of the violating transfer: 0x%08x\n", fault_addr);

    ERROR_RAW("\tAttributes of the violating transfer: 0x%08x\n", fault_attr);
    ERROR_RAW("\t\tMaster ID: 0x%08x\n", (fault_attr >> 24) & 0xFFUL);
    ERROR_RAW("\t\tType: 0x%08x\n", (fault_attr >> 16) & 0x7UL);
    ERROR_RAW("\t\tTransaction PC: 0x%08x\n", (fault_attr >> 12) & 0xFUL);
    ERROR_RAW("\t\tPeripheral #: 0x%08x\n", (fault_attr >> 0) & 0x3FFUL);
}

/**
 * \brief Print peripheral group timeout violation fault information captured by fault peripheral.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_peri_gpx_timeout_vio_fault(FAULT_STRUCT_Type *base)
{
    /* DATA0: The attributes of the violating transfer (peri_gp<>_mmio_timeout_vio_attr) */
    uint32_t fault_attr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(fault_attr);

    /* bits description
     * [4:0]:   Indicate slave number in respective peripheral group for
     *          which Timeout is detected. */

    ERROR_RAW("AHB timeout in peripheral group\n");

    ERROR_RAW("\tAttributes of the violating transfer: 0x%08x\n", fault_attr);
    ERROR_RAW("\t\tSlave number: 0x%08x\n", (fault_attr >> 0) & 0xFUL);
}

/**
 * \brief Print peripheral group AHB violation fault information captured by fault peripheral.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_peri_gpx_ahb_vio_fault(FAULT_STRUCT_Type *base)
{
    /* DATA0: The address of the violating transfer (peri_gp<>_mmio_ahb_vio_addr) */
    uint32_t fault_addr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(fault_addr);
    /* DATA1: The attributes of the violating transfer (peri_gp<i>_mmio_ahb_vio_attr) */
    uint32_t fault_attr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA1);
    IFX_UNUSED(fault_attr);

    /* bits description
     * [31:30]: Error type
     *          b00- AHB ERROR response,
     *          b01- Reports an AHB bus ERROR when any of the peripheral group's is
     *               in reset, and an attempt is made to access it via the AHB
     *          other - reserved.
     * [23:8]:  Master ID of AHB master from which AHB5 transaction is initiated.
     * [7:4]:   Indicates the master interface transaction PC value when violation is detected.
     * [2]:     1 - indicates write,
     *          0 - indicates read.
     * [1]:     1 - indicates non secure transaction,
     *          0 - indicates secure transaction.
     * [0]:     1 - indicates privileged mode,
     *          0 - indicates unprivileged mode. */

    ERROR_RAW("AHB ERROR in peripheral group\n");
    ERROR_RAW("\tAddress of the violating transfer: 0x%08x\n", fault_addr);

    ERROR_RAW("\tAttributes of the violating transfer: 0x%08x\n", fault_attr);
    ERROR_RAW("\t\tType: 0x%08x\n", (fault_attr >> 30) & 0x3UL);
    ERROR_RAW("\t\tMaster ID: 0x%08x\n", (fault_attr >> 8) & 0xFFFFUL);
    ERROR_RAW("\t\tTransaction PC: 0x%08x\n", (fault_attr >> 4) & 0xFUL);
    if (fault_attr & (1UL << 2)) {
        ERROR_RAW("\t\tWrite\n");
    } else {
        ERROR_RAW("\t\tRead\n");
    }
    if (fault_attr & (1UL << 1)) {
        ERROR_RAW("\t\tNon secure\n");
    } else {
        ERROR_RAW("\t\tSecure\n");
    }
    if (fault_attr & (1UL << 0)) {
        ERROR_RAW("\t\tPrivileged\n");
    } else {
        ERROR_RAW("\t\tUnprivileged\n");
    }
}

/**
 * \brief Print MPC fault information captured by fault peripheral.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_mpc_fault(FAULT_STRUCT_Type *base)
{
    /* DATA0: The address of the violating transfer (mpc_mmio_vio_addr) */
    uint32_t fault_addr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(fault_addr);
    /* DATA1: The attributes of the violating transfer (mpc_mmio_vio_att) */
    uint32_t fault_attr = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA1);
    IFX_UNUSED(fault_attr);

    /* bits description
     * [31]:    PC access violation
     * [30]:    Security access violation
     * [27:24]: Transaction PC of access violation
     * [18]:    1 - indicates write,
     *          0 - indicates read.
     * [17]:    1 - secure config of violated block,
     *          0 - non-secure config of violated block.
     * [16]:    hnonsec of transaction
     * [15:0]:  Master ID. */

    ERROR_RAW("MPC Fault\n");
    ERROR_RAW("\tAddress of the violating transfer: 0x%08x\n", fault_addr);

    ERROR_RAW("\tAttributes of the violating transfer: 0x%08x\n", fault_attr);
    if (fault_attr & (1UL << 31)) {
        ERROR_RAW("\t\tPC access violation\n");
    }
    if (fault_attr & (1UL << 30)) {
        ERROR_RAW("\t\tSecurity access violation occurred\n");
    }
    ERROR_RAW("\t\tTransaction PC: 0x%08x\n", (fault_attr >> 24) & 0xFUL);
    if (fault_attr & (1UL << 18)) {
        ERROR_RAW("\t\tWrite\n");
    } else {
        ERROR_RAW("\t\tRead\n");
    }
    if (fault_attr & (1UL << 17)) {
        ERROR_RAW("\t\tSecure config\n");
    } else {
        ERROR_RAW("\t\tNon-Secure config\n");
    }
    if (fault_attr & (1UL << 16)) {
        ERROR_RAW("\t\thnonsec set\n");
    } else {
        ERROR_RAW("\t\thnonsec clear\n");
    }
    ERROR_RAW("\t\tMaster ID: 0x%08x\n", (fault_attr >> 0) & 0xFFFFUL);
}

/**
 * \brief Print fault information captured by fault peripheral.
 *
 * \param[in] base      Fault structure with captured fault
 */
__STATIC_FORCEINLINE void ifx_faults_dump_default_fault(FAULT_STRUCT_Type *base)
{
    uint32_t data0 = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA0);
    IFX_UNUSED(data0);
    ERROR_RAW("\tDATA0 0x%08x\n", data0);
    uint32_t data1 = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA1);
    IFX_UNUSED(data1);
    ERROR_RAW("\tDATA1 0x%08x\n", data1);
    uint32_t data2 = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA2);
    IFX_UNUSED(data2);
    ERROR_RAW("\tDATA2 0x%08x\n", data2);
    uint32_t data3 = Cy_SysFault_GetFaultData(base, CY_SYSFAULT_DATA3);
    IFX_UNUSED(data3);
    ERROR_RAW("\tDATA3 0x%08x\n", data3);
}

#endif /* FAULTS_DUMPS_H */

/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 * Copyright (c) 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdio.h>

#include "config_tfm.h"

#include "cy_ipc_drv.h"
#include "fih.h"
#include "ifx_platform_mailbox.h"
#include "ifx_regions.h"
#ifdef TFM_FIH_PROFILE_ON
#include "psa/service.h" /* Used for psa_panic */
#endif /* TFM_FIH_PROFILE_ON */
#include "tfm_hal_multi_core.h"
#include "tfm_peripherals_def.h"

#define IFX_IS_REGION_IN_ITCM_MEMORY(base, size)   \
            (ifx_is_region_inside_other(base, base + size, \
                                        CY_CM55_ITCM_INTERNAL_NS_SBUS_BASE, \
                                        (CY_CM55_ITCM_INTERNAL_NS_SBUS_BASE \
                                         + CY_CM55_ITCM_INTERNAL_SIZE)) == true)

#define IFX_IS_REGION_IN_DTCM_MEMORY(base, size)   \
            (ifx_is_region_inside_other(base, base + size, \
                                        CY_CM55_DTCM_INTERNAL_NS_SBUS_BASE, \
                                        (CY_CM55_DTCM_INTERNAL_NS_SBUS_BASE \
                                         + CY_CM55_DTCM_INTERNAL_SIZE)) == true)

#define IFX_IS_REGION_IN_ITCM_MEMORY_REMAPPED(base, size)   \
            (ifx_is_region_inside_other(base, base + size, \
                                        CY_CM55_ITCM_NS_SBUS_BASE, \
                                        (CY_CM55_ITCM_NS_SBUS_BASE \
                                         + CY_CM55_ITCM_INTERNAL_SIZE)) == true)

#define IFX_IS_REGION_IN_DTCM_MEMORY_REMAPPED(base, size)   \
            (ifx_is_region_inside_other(base, base + size, \
                                        CY_CM55_DTCM_NS_SBUS_BASE, \
                                        (CY_CM55_DTCM_NS_SBUS_BASE \
                                         + CY_CM55_DTCM_INTERNAL_SIZE)) == true)

#if (DOMAIN_S) || (IFX_MTB_MAILBOX && IFX_NS_INTERFACE_TZ)
void tfm_hal_boot_ns_cpu(uintptr_t start_addr)
{
    printf("Starting Cortex-M55 at 0x%x\r\n", start_addr);
    Cy_SysEnableCM55(IFX_MXCM55, start_addr, CY_SYS_CORE_WAIT_INFINITE);

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that CM55 was started from the correct address.
     * From the time CM55 was started till this check, CM55 might have already
     * changed the vector table address (e.g. to RAM_VECTOR_TABLE), thus verify
     * that address of Reset_Handler from active vector table is same as
     * Reset_Handler address from expected vector table.
     */
    if ((*((uint32_t *)((IFX_MXCM55->CM55_NS_VECTOR_TABLE_BASE) + 4U))) !=
        (*((uint32_t *)((start_addr) + 4U)))) {
        psa_panic();
    }
#endif /* TFM_FIH_PROFILE_ON */
}
#endif /* (DOMAIN_S) || (IFX_MTB_MAILBOX && IFX_NS_INTERFACE_TZ) */

#if CONFIG_TFM_PSA_CALL_ADDRESS_REMAP
bool ifx_is_ns_cpu_internal_memory(uintptr_t base, size_t size)
{
    return IFX_IS_REGION_IN_ITCM_MEMORY(base, size) || IFX_IS_REGION_IN_DTCM_MEMORY(base, size);
}

bool ifx_is_ns_cpu_internal_memory_remapped(uintptr_t base, size_t size)
{
    return IFX_IS_REGION_IN_ITCM_MEMORY_REMAPPED(base, size)
            || IFX_IS_REGION_IN_DTCM_MEMORY_REMAPPED(base, size);
}

void* tfm_hal_remap_ns_cpu_address(const void* addr)
{
    /* ITCM/DTCM memory has different address in CM55 vs CM33 address space,
     * thus ITCM/DTCM memory address needs to be remapped to be usable on CM33
     * side. */
    if (IFX_IS_REGION_IN_ITCM_MEMORY((uintptr_t)addr, 0U)) {
        return (void*)(((uint32_t)addr)
                       - CY_CM55_ITCM_INTERNAL_NS_SBUS_BASE
                       + CY_CM55_ITCM_NS_SBUS_BASE);
    } else if (IFX_IS_REGION_IN_DTCM_MEMORY((uintptr_t)addr, 0U)) {
        return (void*)(((uint32_t)addr)
                       - CY_CM55_DTCM_INTERNAL_NS_SBUS_BASE
                       + CY_CM55_DTCM_NS_SBUS_BASE);
    } else {
        /* Address is not in ITCM/DTCM memory, thus no remapping is needed */
        return ((void*)addr);
    }
}
#endif /* CONFIG_TFM_PSA_CALL_ADDRESS_REMAP */

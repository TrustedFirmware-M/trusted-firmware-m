/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file ifx_platform_spe_types.h
 * \brief Platform-specific types and data declaration used to build the secure image.
 *
 * This file is part of Infineon platform configuration files. It's expected that
 * this file provides platform dependent types and data declaration used by Infineon common code.
 */

#ifndef IFX_PLATFORM_SPE_TYPES_H
#define IFX_PLATFORM_SPE_TYPES_H

#include <stdint.h>
#include "cy_mpc.h"
#include "partition_psc3.h" /* IMPROVEMENT: BSP-7403, For now file name in PSC3M6 BSP is wrong */

/* Peripheral region starts from Non-Secure base (MMIO_NS_START)
 * and ends at the end of peripheral Secure alias (MMIO_S_START + MMIO_SIZE - 1)
 * This is needed to be able to access peripherals by both Secure and Non-Secure
 * alias. */
#define IFX_PROTECTION_MPU_PERIPHERAL_REGION_START    ((uint32_t)MMIO_NS_START)
#define IFX_PROTECTION_MPU_PERIPHERAL_REGION_LIMIT    ((uint32_t)(MMIO_S_START + MMIO_SIZE - 1))

#define IFX_MPC_IS_EXTERNAL(base) false

#endif /* IFX_PLATFORM_SPE_TYPES_H */

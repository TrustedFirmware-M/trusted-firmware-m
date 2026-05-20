/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
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
#include "partition_edge.h"

/* MPU: Peripheral region starts from Non-Secure base (MMIO_NS_M33SYS_START)
 * and ends at the end of peripheral Secure alias
 * ( MMIO_S_M33SYS_START + MMIO_M33SYS_SIZE + MMIO_M55APP_SIZE - 1)
 * This is needed to be able to access peripherals by both Secure and Non-Secure alias. */
#define IFX_PROTECTION_MPU_PERIPHERAL_REGION_START    ((uint32_t)MMIO_NS_M33SYS_START)
#define IFX_PROTECTION_MPU_PERIPHERAL_REGION_LIMIT    ((uint32_t)(MMIO_S_M33SYS_START \
                                                                  + MMIO_M33SYS_SIZE \
                                                                  + MMIO_M55APP_SIZE - 1))

#define IFX_MPC_IS_EXTERNAL(base) \
    (((void *)base == IFX_MPC_NOT_CONTROLLED_BY_TFM) || \
     ((void *)base == RRAMC0_MPC0) || \
     ((void *)base == RRAMC0_MPC1))

#if (IFX_CORE == IFX_CM33)
/*\ brief Number of CM33 core exceptions excluding stack point entry */
#define VECTOR_FIXED_EXP_NR                           ARMV8M_FIXED_EXP_NR
#endif /* (IFX_CORE == IFX_CM33) */

#endif /* IFX_PLATFORM_SPE_TYPES_H */

/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PERIPHERALS_DEF_H
#define TFM_PERIPHERALS_DEF_H

#include "tfm_peripherals_def_common.h"

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_1               PROT_GPIO_PRT0_PRT
#define IFX_TEST_PERIPHERAL_1_BASE          GPIO_PRT0
#define IFX_TEST_PERIPHERAL_1_SIZE          0x40U

/* Free peripheral that does not require configuration is used */
#define IFX_TEST_PERIPHERAL_2               PROT_GPIO_PRT1_PRT
#define IFX_TEST_PERIPHERAL_2_BASE          GPIO_PRT1
#define IFX_TEST_PERIPHERAL_2_SIZE          0x40U

#endif /* TFM_PERIPHERALS_DEF_H */

/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 *
 */

#ifndef __MMIO_DEFS_H__
#define __MMIO_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "handle_attr.h"
#include "tfm_peripherals_config.h"
#include "tfm_peripherals_def.h"
#include <stdint.h>

/* Allowed named MMIO of this platform */
const uintptr_t partition_named_mmio_list[] = {
#if TFM_PERIPHERAL_TIMER00_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER00,
#endif
#if TFM_PERIPHERAL_TIMER10_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER10,
#endif
#if TFM_PERIPHERAL_TIMER20_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER20,
#endif
#if TFM_PERIPHERAL_TIMER21_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER21,
#endif
#if TFM_PERIPHERAL_TIMER22_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER22,
#endif
#if TFM_PERIPHERAL_TIMER23_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER23,
#endif
#if TFM_PERIPHERAL_TIMER24_SECURE
    (uintptr_t)TFM_PERIPHERAL_TIMER24,
#endif
#if TFM_PERIPHERAL_SPIM00_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM00,
#endif
#if TFM_PERIPHERAL_SPIM20_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM20,
#endif
#if TFM_PERIPHERAL_SPIM21_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM21,
#endif
#if TFM_PERIPHERAL_SPIM22_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM22,
#endif
#if TFM_PERIPHERAL_SPIM23_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM23,
#endif
#if TFM_PERIPHERAL_SPIM30_SECURE
    (uintptr_t)TFM_PERIPHERAL_SPIM30,
#endif
#if TFM_PERIPHERAL_EGU10_SECURE
    (uintptr_t)TFM_PERIPHERAL_EGU10,
#endif
#if TFM_PERIPHERAL_EGU20_SECURE
    (uintptr_t)TFM_PERIPHERAL_EGU20,
#endif
#if TFM_PERIPHERAL_PWM20_SECURE
    (uintptr_t)TFM_PERIPHERAL_PWM20,
#endif
#if TFM_PERIPHERAL_PWM21_SECURE
    (uintptr_t)TFM_PERIPHERAL_PWM21,
#endif
#if TFM_PERIPHERAL_PWM22_SECURE
    (uintptr_t)TFM_PERIPHERAL_PWM22,
#endif
#if TFM_PERIPHERAL_PWM20_SECURE
    (uintptr_t)TFM_PERIPHERAL_PWM20,
#endif
#if TFM_PERIPHERAL_UARTE00_SECURE
    (uintptr_t)TFM_PERIPHERAL_UARTE00,
#endif
#if TFM_PERIPHERAL_UARTE20_SECURE
    (uintptr_t)TFM_PERIPHERAL_UARTE20,
#endif
#if TFM_PERIPHERAL_UARTE21_SECURE
    (uintptr_t)TFM_PERIPHERAL_UARTE21,
#endif
#if TFM_PERIPHERAL_UARTE22_SECURE
    (uintptr_t)TFM_PERIPHERAL_UARTE22,
#endif
#if TFM_PERIPHERAL_UARTE30_SECURE
    (uintptr_t)TFM_PERIPHERAL_UARTE30,
#endif
};

#ifdef __cplusplus
}
#endif

#endif /* __MMIO_DEFS_H__ */

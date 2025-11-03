/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * @file cc3xx_platform_helpers.h
 *
 * @brief Platform-defined hooks invoked around CC3xx DMA transfers.
 *
 * These hooks are intentionally platform-specific and are compiled/called
 * only when CC3XX_CONFIG_DMA_HOOKS_ENABLE is defined by
 * the platform configuration.
 *
 * Typical uses (non-exhaustive):
 *  - cache maintenance for DMA source/destination windows,
 *  - temporarily masking/adjusting platform security monitors,
 *  - setting up address windowing or bus fabric attributes,
 *  - applying SoC-specific workarounds.
 *
 * The common CC3xx driver does not ascribe semantics to these hooks; their
 * meaning is entirely determined by the platform that enables them.
 */

#ifndef __CC3XX_PLATFORM_HELPERS_H
#define __CC3XX_PLATFORM_HELPERS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Platform prologue run just before arming the CC3xx DMA.
 *
 * @param[in] src    Source address (as uintptr_t) for the pending DMA.
 * @param[in] dst    Destination address (as uintptr_t) for the pending DMA.
 *               May be 0 to indicate that the current DMA invocation has no
 *               destination buffer.
 * @param[in] length Number of bytes to be transferred.
 *
 * @note If CC3XX_CONFIG_DMA_HOOKS_ENABLE is not defined,
 *       this symbol is never referenced by the common driver.
 */
void cc3xx_dma_platform_prologue(uintptr_t src, uintptr_t dst, size_t length);

/**
 * @brief Platform epilogue run immediately after the CC3xx DMA completes.
 *
 * The epilogue is called after the driver disables the DMA clock and after
 * the transfer’s completion is observed by the driver. Platforms may use it
 * to perform post-DMA fixups.
 *
 * @note If CC3XX_CONFIG_DMA_HOOKS_ENABLE is not defined,
 *       this symbol is never referenced by the common driver.
 */
void cc3xx_dma_platform_epilogue(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CC3XX_PLATFORM_HELPERS_H */

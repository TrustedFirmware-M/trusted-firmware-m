/*
 * Copyright (c) 2021-2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_DMA_H
#define CC3XX_DMA_H

#include "cc3xx_error.h"
#include "cc3xx_config.h"

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#ifndef __PACKED_ENUM
#define __PACKED_ENUM enum __attribute__((packed))
#endif /* __PACKED_ENUM */

#define CC3XX_DMA_BLOCK_BUF_MAX_SIZE 64

__PACKED_ENUM cc3xx_dma_input_src {
    CC3XX_DMA_INPUT_SRC_CPU_MEM = 0, /* Default state */
    CC3XX_DMA_INPUT_SRC_RNG_SRAM,
};

struct cc3xx_dma_state_t {
    uint8_t block_buf[CC3XX_DMA_BLOCK_BUF_MAX_SIZE];
    size_t block_buf_size_in_use;
    size_t block_buf_size;
    bool block_buf_needs_output;
    uintptr_t output_addr;
    size_t output_size;
    uint32_t remap_cpusel;
    size_t current_bytes_output;
    enum cc3xx_dma_input_src input_src;
};

extern struct cc3xx_dma_state_t dma_state;

#ifdef CC3XX_CONFIG_DMA_REMAP_ENABLE

typedef struct {
    uintptr_t region_base; /*!< The base of the region that will be remapped */
    size_t region_size;    /*!< The size of the region that will be remapped */
    uintptr_t remap_base;  /*!< The base of the region that mapped to */
    size_t remap_cpusel_offset; /*!< How much the remap will be incremented per cpu */
    bool valid;            /*!< Validity of the region */
} cc3xx_dma_remap_region_t;

typedef struct {
    uintptr_t region_base; /*!< The base of the region that will be restricted */
    size_t region_size;    /*!< The size of the region that will be restricted */
    bool valid;            /*!< Validity of the region */
} cc3xx_dma_burst_restricted_region_t;

#endif /* CC3XX_CONFIG_DMA_REMAP_ENABLE */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CC3XX_CONFIG_DMA_REMAP_ENABLE

/**
 * @brief                        Configure and enable a remap region. Any DMA
 *                               input/output address that is within a remap
 *                               region will be altered to the offset into the
 *                               region plus the remap base (plus an extra
 *                               cpusel offset if configured). This is intended
 *                               primarily to be used to remap CPU TCM accesses
 *                               to use the TCM subordinate interface (as cc3xx
 *                               has no access via the main TCM mapping).

 * @param[in]  remap_region_idx  Which remap region should be configured and
 *                               enabled.
 * @param[in]  region            The configuration for the remap region.
 */
void cc3xx_lowlevel_dma_remap_region_init(uint32_t remap_region_idx,
                                          const cc3xx_dma_remap_region_t *region);
/**
 * @brief                        Clear and disable a remap region.
 *
 * @param[in]  remap_region_idx  Which remap region should be cleared and
 *                               disabled.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
void cc3xx_lowlevel_dma_remap_region_clear(uint32_t remap_region_idx);

/**
 * @brief             Select which CPU memory space should be used for remap
 *                    offsets. Useful for selecting different ITCM / DTCMs.
 *
 * @param[in]  cpuid  Which CPU's memory space should be accessed when
 *                    remapping.
 *
 * @return            CC3XX_ERR_SUCCESS on success, another cc3xx_err_t on
 *                    error.
 */
void cc3xx_lowlevel_dma_tcm_cpusel(uint32_t cpuid);

#endif /* CC3XX_CONFIG_DMA_REMAP_ENABLE */

#ifdef CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE
/**
 * @brief                        Configure and enable a burst restricted region.
 *                               Any DMA input/output address that is within a
 *                               burst restricted region will be issued as single
 *                               AHB transaction instead of a burst incr4
 *                               transaction.
 *
 * @param[in]  region_idx        Which region should be burst restricted
 * @param[in]  region            The range of the region.
 */
void cc3xx_lowlevel_dma_burst_restricted_region_init(uint32_t region_idx,
    const cc3xx_dma_burst_restricted_region_t *region);

#endif /* CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE */

/**
 * @brief             Use the cc3xx DMA to copy data directly without performing
 *                    cryptographic operations on it. This function can be used
 *                    as a drop-in replacement for memcpy.
 *
 * @param[out] dest   The pointer to copy data to.
 * @param[in]  src    The pointer to copy data from.
 * @param[in]  length The size of the data.
 */
void cc3xx_lowlevel_dma_copy_data(void* dest, const void* src, size_t length);

/**
 * @brief             Use the cc3xx DMA to copy data directly without performing
 *                    cryptographic operations on it. This function copies data
 *                    from RNG SRAM (within CryptoCell) to CPU memory
 *
 * @param[out] dest             The pointer to copy data to.
 * @param[in]  rng_sram_offset  The offset in bytes from RNG SRAM.
 * @param[in]  length           The size of the data.
 */
void cc3xx_lowlevel_dma_copy_data_from_rng_sram(void* dest,
                                                const size_t rng_sram_offset,
                                                size_t length);

/**
 * @brief             Set the DMA input location. This triggers DMA input to be
 *                    started. This operation buffers data, and
 *                    cc3xx_dma_flush_buffer must be called to ensure all data
 *                    is processed.
 *
 * @param[in]  buf          The pointer to copy data from.
 * @param[in]  length       The size of the data.
 * @param[in]  write_output Whether the data should be output from the engine.
 *
 * @return            CC3XX_ERR_SUCCESS on success, another cc3xx_err_t on
 *                    error.
 */
cc3xx_err_t cc3xx_lowlevel_dma_buffered_input_data(const void* buf, size_t length,
                                                   bool write_output);

/**
 * @brief             Flush the DMA buffer. Engine setup is not saved with the
 *                    DMA buffer, so the engine must be configured correctly
 *                    before this is called.
 *
 * @param[in]  zero_pad_first Whether the data should be zero-padded to the DMA
 *                            buffer size before being input.
 */
void cc3xx_lowlevel_dma_flush_buffer(bool zero_pad_first);

/**
 * @brief             Set the size of the DMA block buffer. This must be called
 *                    before the DMA is used, as the default value is 0, which
 *                    is invalid.
 *
 * @param[in]  size   The size of the block buffer. Must not be larger than
 *                    CC3XX_DMA_BLOCK_BUF_MAX_SIZE.
 */
void cc3xx_lowlevel_dma_set_buffer_size(size_t size);

/**
 * @brief             Set the DMA output location. This controls where the
 *                    DMA will output to after input is started.
 *
 * @param[out] buf    The pointer to output to.
 * @param[in]  length The size of the output location. The DMA will not copy
 *                    more data than this to the pointer.
 */
void cc3xx_lowlevel_dma_set_output(void* buf, size_t length);

/**
 * @brief                       Uninitialize the DMA.
 *
 * @note                        The DMA is not implicitly uninitialized
 *                              on an error.
 *
 */
void cc3xx_lowlevel_dma_uninit(void);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_DMA_H */

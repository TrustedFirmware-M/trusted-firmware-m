/*
 * Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_dma.h"

#include "cc3xx_dev.h"
#include "cc3xx_engine_state.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <assert.h>

#include "fatal_error.h"
#ifdef CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE
#include "cmsis.h"
#endif

struct cc3xx_dma_state_t dma_state;

#ifdef CC3XX_CONFIG_DMA_REMAP_ENABLE
static cc3xx_dma_remap_region_t g_remap_regions[CC3XX_CONFIG_DMA_REMAP_REGION_AM] = {0};

void cc3xx_lowlevel_dma_remap_region_init(uint32_t remap_region_idx,
                                        const cc3xx_dma_remap_region_t *region)
{
    memcpy(&g_remap_regions[remap_region_idx], region, sizeof(*region));
    g_remap_regions[remap_region_idx].valid = true;
}

void cc3xx_lowlevel_dma_remap_region_clear(uint32_t remap_region_idx)
{
    memset(&g_remap_regions[remap_region_idx], 0, sizeof(cc3xx_dma_remap_region_t));
    g_remap_regions[remap_region_idx].valid = false;
}

void cc3xx_lowlevel_dma_tcm_cpusel(uint32_t cpuid)
{
    dma_state.remap_cpusel = cpuid;
}

static uintptr_t remap_addr(uintptr_t addr)
{
    uint32_t idx;
    cc3xx_dma_remap_region_t *region;

    for (idx = 0; idx < CC3XX_CONFIG_DMA_REMAP_REGION_AM; idx++) {
        region = &g_remap_regions[idx];

        if (!region->valid) {
            continue;
        }

        if ((addr >= region->region_base)
            && (addr < region->region_base + region->region_size)) {
            return (addr - region->region_base) + region->remap_base
                    + (region->remap_cpusel_offset * dma_state.remap_cpusel);
        }
    }

    return addr;
}

#else

static uintptr_t remap_addr(uintptr_t addr) {
    return addr;
}

#endif /* CC3XX_CONFIG_DMA_REMAP_ENABLE */

#ifdef CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE
static cc3xx_dma_burst_restricted_region_t
            g_burst_restricted_regions[CC3XX_CONFIG_DMA_BURST_RESTRICTED_REGION_AM] = {0};

void cc3xx_lowlevel_dma_burst_restricted_region_init(uint32_t region_idx,
    const cc3xx_dma_burst_restricted_region_t *region)
{
    memcpy(&g_burst_restricted_regions[region_idx], region, sizeof(*region));
    g_burst_restricted_regions[region_idx].valid = true;
}

static bool is_addr_burst_restricted(uintptr_t addr) {
    uint32_t idx;
    cc3xx_dma_burst_restricted_region_t *region;

    for (idx = 0; idx < CC3XX_CONFIG_DMA_BURST_RESTRICTED_REGION_AM; idx++) {
        region = &g_burst_restricted_regions[idx];

        if (!region->valid) {
            continue;
        }

        if ((addr >= region->region_base)
            && (addr < region->region_base + region->region_size)) {
            return true;
        }
    }

    return false;
}
#endif /* CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE */

#ifndef CC3XX_CONFIG_HW_VERSION_CC310
static inline uint32_t get_interrupt_mask_from_input_source(
                                enum cc3xx_dma_input_src input_src)
{
    return (input_src == CC3XX_DMA_INPUT_SRC_RNG_SRAM) ?
                            (SRAM_TO_DIN_INT | DOUT_TO_MEM_INT) :
                            SYM_DMA_COMPLETED;
}
#endif

static void wait_for_dma_complete(void)
{
    uint32_t poll_mask;

#ifdef CC3XX_CONFIG_HW_VERSION_CC310
    if (dma_state.block_buf_needs_output) {
        poll_mask = DOUT_TO_MEM_INT;
    } else {
        poll_mask = MEM_TO_DIN_INT;
    }
#else
    poll_mask = get_interrupt_mask_from_input_source(dma_state.input_src);
#endif /* CC3XX_CONFIG_HW_VERSION_CC310 */

    /* Poll the interrupt status */
    while ((P_CC3XX->host_rgf.host_rgf_irr & poll_mask) != poll_mask) {
        #ifdef CC3XX_CONFIG_DMA_WFI_WAIT_ENABLE
                __asm("WFI");
        #endif /* CC3XX_CONFIG_WFI_WAIT_ENABLE */
    }

    /* Reset the polled interrupt */
    P_CC3XX->host_rgf.host_rgf_icr = poll_mask;
}

static void process_data(const void* buf, size_t length)
{
    uintptr_t remapped_buf = (uintptr_t)NULL;

    /* Enable the DMA clock */
    P_CC3XX->misc.dma_clk_enable = 0x1U;

    if (dma_state.input_src == CC3XX_DMA_INPUT_SRC_RNG_SRAM) {
        /* Mask all interrupts except SRAM_TO_DIN_INT and DOUT_TO_MEM_INT */
        P_CC3XX->host_rgf.host_rgf_imr = 0xF60U;
    } else {
        /* Mask all interrupts except SYM_DMA_COMPLETED */
        P_CC3XX->host_rgf.host_rgf_imr = 0x7F0U;
    }

    /* Reset the AXI_ERROR and SYM_DMA_COMPLETED interrupts */
    P_CC3XX->host_rgf.host_rgf_icr |= 0xFF0U;

    if (dma_state.input_src == CC3XX_DMA_INPUT_SRC_CPU_MEM) {
        /* remap the address, particularly for TCMs */
        remapped_buf = remap_addr((uintptr_t)buf);
    }

    if (dma_state.block_buf_needs_output) {
        uintptr_t output_addr = dma_state.output_addr;
#ifdef CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE
        /* Force single transactions for restricted addresses */
        if (is_addr_burst_restricted(output_addr)) {
            P_CC3XX->ahb.ahbm_singles = 0x1UL;
        } else {
            P_CC3XX->ahb.ahbm_singles = 0x0UL;
        }
#endif /* CC3XX_CONFIG_DMA_BURST_RESTRICTED_ENABLE */

        /* Set the data target */
        P_CC3XX->dout.dst_lli_word0 = output_addr;
        /* And the length */
        P_CC3XX->dout.dst_lli_word1 = length;

#ifdef CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE
        /* Flush the output data. Note that this is only enough to avoid cache
         * issues if the CPU is is a busy-wait loop while the access completes.
         * If the DMA is used asynchronously via an interrupt and the CPU
         * continues running while the DMA is operating, it will be necessary to
         * set up an MPU covering the input and output regions so they can be
         * marked as SHAREABLE (which is not currently implemented).
         */
        SCB_CleanInvalidateDCache_by_Addr((volatile void *)output_addr, length);
#endif /* CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE */

        dma_state.output_addr += length;
        dma_state.current_bytes_output += length;
    }

    if (dma_state.input_src == CC3XX_DMA_INPUT_SRC_CPU_MEM) {
#ifdef CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE
        /* Flush the input data. Note that this is only enough to avoid cache
         * issues if the CPU is in a busy-wait loop while the access completes.
         * If the DMA is used asynchronously via an interrupt and the CPU
         * continues running while the DMA is operating, it will be necessary to
         * set up an MPU covering the input and output regions so they can be
         * marked as SHAREABLE (which is not currently implemented).
         */
        SCB_CleanInvalidateDCache_by_Addr((volatile void *)remapped_buf, length);
#endif /* CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE */

        /* Set the data source */
        P_CC3XX->din.src_lli_word0 = remapped_buf;
        /* Writing the length triggers the DMA */
        P_CC3XX->din.src_lli_word1 = length;
    } else {
        /* Offset from RNG SRAM */
        P_CC3XX->din.sram_src_addr = (uintptr_t)buf;
        /* Writing the length triggers the DMA */
        P_CC3XX->din.din_sram_bytes_len = length;
    }

    wait_for_dma_complete();

    /* Disable the DMA clock */
    P_CC3XX->misc.dma_clk_enable = 0x0U;
}

void cc3xx_lowlevel_dma_copy_data(void* dest, const void* src, size_t length)
{
    /* Set to PASSTHROUGH engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_NONE);

    /* Set output target */
    cc3xx_lowlevel_dma_set_output(dest, length);

    /* This starts the copy */
    cc3xx_lowlevel_dma_buffered_input_data(src, length, true);
    cc3xx_lowlevel_dma_flush_buffer(false);
}

void cc3xx_lowlevel_dma_copy_data_from_rng_sram(void* dest,
                                                const size_t rng_sram_offset,
                                                size_t length)
{
    /* Flush pending data with the previous input source */
    cc3xx_lowlevel_dma_flush_buffer(false);

    /* Set to PASSTHROUGH engine */
    cc3xx_lowlevel_set_engine(CC3XX_ENGINE_NONE);

    /* Set output target */
    cc3xx_lowlevel_dma_set_output(dest, length);

    /* Set input source to RNG SRAM */
    dma_state.input_src = CC3XX_DMA_INPUT_SRC_RNG_SRAM;

    /* Output is written to CPU memory */
    dma_state.block_buf_needs_output = true;

    /* This starts the copy */
    process_data((const void *)rng_sram_offset, length);

    /* Clear the DMA state */
    cc3xx_lowlevel_dma_uninit();
}

cc3xx_err_t cc3xx_lowlevel_dma_buffered_input_data(const void* buf, size_t length,
                                                   bool write_output)
{
    size_t block_buf_size_free =
        dma_state.block_buf_size - dma_state.block_buf_size_in_use;
    size_t data_to_process_length = 0;
    size_t dma_input_length = 0;

    if (write_output) {
        if (length > dma_state.output_size) {
            FATAL_ERR(CC3XX_ERR_DMA_OUTPUT_BUFFER_TOO_SMALL);
            return CC3XX_ERR_DMA_OUTPUT_BUFFER_TOO_SMALL;
        }
        dma_state.output_size -= length;
    }

    /* The DMA block buf will hold a block (to allow GCM and Hashing which both
     * require a last-block special case to work). First, fill this block.
     */
    if (dma_state.block_buf_size_in_use != 0) {
        /* If we need to output the block buffer, and then new data shouldn't be
         * output, then the block buffer needs to be flushed
         */
        if (dma_state.block_buf_needs_output != write_output) {
            cc3xx_lowlevel_dma_flush_buffer(false);
        } else {
            data_to_process_length =
                length < block_buf_size_free ? length : block_buf_size_free;
            memcpy(dma_state.block_buf + dma_state.block_buf_size_in_use, buf,
                   block_buf_size_free);
            dma_state.block_buf_size_in_use += data_to_process_length;
            buf += data_to_process_length;
            length -= data_to_process_length;
        }
    }

    if (length == 0) {
        return CC3XX_ERR_SUCCESS;
    }

    dma_state.block_buf_needs_output = write_output;

    /* The block buf is now full, and we have remaining data. First dispatch the
     * block buf. If the buffer is empty, this is a no-op.
     */
    cc3xx_lowlevel_dma_flush_buffer(false);

    /* If we have any whole blocks left, flush them (but make sure at least some
     * data always remains to insert into the block buf.
     */
    data_to_process_length = ((length - 1) / dma_state.block_buf_size) * dma_state.block_buf_size;
    while (data_to_process_length > 0) {
        dma_input_length = data_to_process_length < 0x10000 ? data_to_process_length
                                                            : 0x10000 - dma_state.block_buf_size;
        process_data(buf, dma_input_length);
        data_to_process_length -= dma_input_length;
        length -= dma_input_length;
        buf += dma_input_length;
    }

    /* Write the remaining data into the block buffer. The previous flush means
     * the buffer is empty, and we have less than a block of input data left, so
     * this can't overflow.
     */
    memcpy(dma_state.block_buf, buf, length);
    dma_state.block_buf_size_in_use += length;

    return CC3XX_ERR_SUCCESS;
}

void cc3xx_lowlevel_dma_flush_buffer(bool zero_pad_first)
{
    if (dma_state.block_buf_size_in_use > 0) {
        if (zero_pad_first) {
            memset(dma_state.block_buf + dma_state.block_buf_size_in_use, 0,
                   sizeof(dma_state.block_buf) - dma_state.block_buf_size_in_use);
            dma_state.block_buf_size_in_use = dma_state.block_buf_size;
        }

        process_data(dma_state.block_buf, dma_state.block_buf_size_in_use);
        dma_state.block_buf_size_in_use = 0;
    }
}

void cc3xx_lowlevel_dma_set_buffer_size(size_t size) {
    dma_state.block_buf_size = size;
    assert(size <= CC3XX_DMA_BLOCK_BUF_MAX_SIZE);
}

void cc3xx_lowlevel_dma_set_output(void* buf, size_t length)
{
    /* remap the address, particularly for TCMs */
    dma_state.output_addr = remap_addr((uintptr_t)buf);
    dma_state.output_size = length;
}

void cc3xx_lowlevel_dma_uninit(void)
{
    memset(&dma_state, 0, sizeof(dma_state));
}

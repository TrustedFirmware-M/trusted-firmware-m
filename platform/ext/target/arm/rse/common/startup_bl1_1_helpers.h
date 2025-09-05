/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __STARTUP_BL1_1_HELPERS__
#define __STARTUP_BL1_1_HELPERS__

#include <stdint.h>
#include "cc3xx_rng.h"
#include "cc3xx_error.h"
#include "cc3xx_dev.h"
#include "cc3xx_config.h"
#include "cc3xx_noise_source.h"
#include "fih.h"
#include "platform_base_address.h"
#include "dma350_regdef.h"
#include "dma350_ch_drv.h"

/* Decent sampling rate to be used for startup_trng_init */
#define STARTUP_RNG_SUBSAMPLING_RATE (1500)
#if STARTUP_RNG_SUBSAMPLING_RATE < CC3XX_CONFIG_RNG_SUBSAMPLING_RATE
#error "Error: Choose higher sampling rate"
#endif

#define REG32(addr) (*(volatile uint32_t*)(addr))

#define DMA350_CH_REG(channel_idx, reg) \
    REG32(DMA_350_BASE_S + 0x1000 + 0x100*channel_idx + offsetof(DMACH_TypeDef,reg))

#define TRAM_TRC_REG_OFFSET 0x004
#define TRAM_TRKEY_REG_OFFSET 0x008
#define TRAM_TRKEY_COUNT 8

#define TRAM_TRC REG32(TRAM_BASE_S + TRAM_TRC_REG_OFFSET)
#define TRAM_TRKEY(x) REG32(TRAM_BASE_S + TRAM_TRKEY_REG_OFFSET + 4*x)

#ifdef __cplusplus
extern "C" {
#endif

static inline __attribute__ ((always_inline))
void startup_fill_cc3xx_rng_ehr_buffers(void)
{
    /* Enable clock */
    P_CC3XX->rng.rng_clk_enable = 0x1U;

    /* reset trng */
    P_CC3XX->rng.rng_sw_reset = 0x1U;

    /* Apparently there's no way to tell that the reset has finished, so just do
     * these things repeatedly until they succeed (and hence the reset has
     * finished). Works because the reset value of SAMPLE_CNT1 is 0xFFFF.
     */
    do {
        /* Enable clock */
        P_CC3XX->rng.rng_clk_enable = 0x1U;

        /* Set subsampling ratio */
        P_CC3XX->rng.sample_cnt1 = STARTUP_RNG_SUBSAMPLING_RATE;

    } while (P_CC3XX->rng.sample_cnt1 != STARTUP_RNG_SUBSAMPLING_RATE);

   /*
    * Add redundant check in case while loop was glitched out of without SW reset completing or
    * subsampling rate set correctly.
    */
    if (P_CC3XX->rng.sample_cnt1 != STARTUP_RNG_SUBSAMPLING_RATE
         || (P_CC3XX->rng.sample_cnt1 != STARTUP_RNG_SUBSAMPLING_RATE)) {
        FIH_PANIC;
    }

    /* Temporarily disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Clear the interrupts */
    P_CC3XX->rng.rng_icr = 0x3FU;

    /* Mask all interrupts except EHR_VALID */
    P_CC3XX->rng.rng_imr = 0x3EU;

    /* Select the oscillator ring (And set SOP_SEL to 0x1 as is mandatory) */
    P_CC3XX->rng.trng_config = CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID | (0x1U << 2);

    /* Set debug control register to bypass all HW test */
    P_CC3XX->rng.trng_debug_control = 0xEU;

    /* Enable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x1U;

    /* Redundant register enable */
    P_CC3XX->rng.rnd_source_enable = 0x1U;

   /* Add redundant check to protect against glitches on rnd_source_enable write. */
    if (P_CC3XX->rng.rnd_source_enable != 0x1U
         || (P_CC3XX->rng.rnd_source_enable != 0x1U)) {
        FIH_PANIC;
    }

    /*
     * Wait until the RNG has finished. Any status other than 0x1 indicates
     * that either the RNG hasn't finished.
     */
    while(! (P_CC3XX->rng.rng_isr & 0x1U));

    /* Add redundant check to protect against glitches out of while loop */
    if (P_CC3XX->rng.rnd_source_enable != 0x1U
         || (P_CC3XX->rng.rnd_source_enable != 0x1U)) {
        FIH_PANIC;
    }

    /* Reset EHR register */
    P_CC3XX->rng.rst_bits_counter = 0x1U;

    /* Make sure the interrupt is cleared before the generator is
     * restarted, to avoid a race condition with the hardware
     */
    P_CC3XX->rng.rng_icr = 0xFFFFFFFF;

    /* Disable the random source */
    P_CC3XX->rng.rnd_source_enable = 0x0U;

    /* Disable clock */
    P_CC3XX->rng.rng_clk_enable = 0x0U;
}

static inline __attribute__((always_inline, optimize("O2")))
void startup_delay(uint32_t delay_val)
{
    /* O2 optimisation should result in use of DLS and LE instructions such that
     * number of cyles taken by this loop should approximately equal y.
     */
    while (delay_val--) {
        __asm("nop");
    }
}

static inline __attribute__ ((always_inline))
void startup_dma_double_word_memset(uint32_t des_addr,  uint32_t size, uint32_t fill_val)
{
    /* Work out how many DMA channels exist */
    register uint32_t dma_channel_amount __asm("r3") =
        (*((volatile uint32_t *)(DMA_350_BASE_S + 0xfb0)) >> 4 & 0xF) + 1;

    /* Configure all DMA channels to wipe the DTCM with the random value in
     * multiplex.
     */
    for (register uint32_t idx __asm("r4") = 0; idx < dma_channel_amount; idx++) {

        /* Stop DMA Channel in case already running (ie. from DMA ICS) */
        DMA350_CH_REG(idx, CH_CMD) = DMA350_CH_CMD_STOPCMD;
        while ((DMA350_CH_REG(idx, CH_CMD) & DMA350_CH_CMD_STOPCMD) != 0) {}

        /* Clear DMA Channel registers */
        DMA350_CH_REG(idx, CH_CMD) = DMA350_CH_CMD_CLEARCMD;
        while ((DMA350_CH_REG(idx, CH_CMD) & DMA350_CH_CMD_CLEARCMD) != 0) {}

        DMA350_CH_REG(idx, CH_FILLVAL) = fill_val;

        /*
         * Enable burst and set mem attributes to normal non-cachable,
         * non-shareable.
         */
        DMA350_CH_REG(idx, CH_DESTRANSCFG) = 0x000F0044;

        DMA350_CH_REG(idx, CH_DESADDR) = des_addr + ((size / dma_channel_amount) * idx);

        /* Increment only the DES ADDR */
        DMA350_CH_REG(idx, CH_XADDRINC) = 0x00010000;

        /* Only set DES XSIZE to enable FILLVAL to fill up destination writes */
        DMA350_CH_REG(idx, CH_XSIZE) = (size / (sizeof(uint64_t) * dma_channel_amount)) << 16;

        DMA350_CH_REG(idx, CH_CTRL) = DMA350_CH_TRANSIZE_64BITS |
                                      DMA350_CH_XTYPE_FILL |
                                      DMA_CH_CTRL_DONEPAUSEEN_Msk |
                                      DMA350_CH_DONETYPE_END_OF_CMD;

        DMA350_CH_REG(idx, CH_CMD) = DMA350_CH_CMD_ENABLECMD;
    }
}

static inline __attribute__ ((always_inline))
void wait_for_dma_operation_complete(void)
{
    /* Work out how many DMA channels exist */
    register uint32_t dma_channel_amount __asm("r0") =
        (*((volatile uint32_t *)(DMA_350_BASE_S + 0xfb0)) >> 4 & 0xF) + 1;

    /* Wait for all the DMA channels to finish */
    for (register uint32_t idx __asm("r1") = 0; idx < dma_channel_amount; idx++) {
        while((DMA350_CH_REG(idx, CH_CMD) & DMA350_CH_CMD_ENABLECMD) != 0) {}
    }
}

#ifdef __cplusplus
}
#endif
#endif /* __STARTUP_BL1_1_HELPERS__ */

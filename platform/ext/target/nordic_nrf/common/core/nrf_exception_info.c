/*
 * Copyright (c) 2023, Nordic Semiconductor ASA. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include "nrf_exception_info.h"
#include "tfm_log.h"
#include "spu.h"

static struct nrf_exception_info nrf_exc_info;

static void dump_exception_info(struct nrf_exception_info *ctx)
{
    ERROR_RAW("Platform Exception:\n");

    /* Report which type of violation occured */
    if (ctx->events & SPU_EVENT_RAMACCERR) {
        VERBOSE_RAW("  SPU.RAMACCERR\n");
    }

    if (ctx->events & SPU_EVENT_PERIPHACCERR) {
        VERBOSE_RAW("  SPU.PERIPHACCERR\n");
        VERBOSE_RAW(" Target addr: 0x%08x\n", ctx->periphaccerr.address);
    }

    if (ctx->events & SPU_EVENT_FLASHACCERR) {
        VERBOSE_RAW("  SPU.FLASHACCERR\n");
    }

#if MPC_PRESENT
    if (ctx->events & MPC_EVENT_MEMACCERR) {
        VERBOSE_RAW("  MPC.MEMACCERR\n");
        VERBOSE_RAW("  Target addr:          0x%08x\n", ctx->memaccerr.address);
        VERBOSE_RAW("  Access information:   0x%08x\n", ctx->memaccerr.info);
        VERBOSE_RAW("    Owner id:     0x%08x\n", ctx->memaccerr.info & 0xf);
        VERBOSE_RAW("    Masterport:   0x%08x\n", (ctx->memaccerr.info & 0x1f0) >> 4);
        VERBOSE_RAW("    Read:         0x%08x\n", (ctx->memaccerr.info >> 12) & 1);
        VERBOSE_RAW("    Write:        0x%08x\n", (ctx->memaccerr.info >> 13) & 1);
        VERBOSE_RAW("    Execute:      0x%08x\n", (ctx->memaccerr.info >> 14) & 1);
        VERBOSE_RAW("    Secure:       0x%08x\n", (ctx->memaccerr.info >> 15) & 1);
        VERBOSE_RAW("    Error source: 0x%08x\n", (ctx->memaccerr.info >> 16) & 1);
    }
#endif
}

void nrf_exception_info_store_context(void)
{
    nrf_exc_info.events = spu_events_get();

#ifdef SPU_PERIPHACCERR_ADDRESS_ADDRESS_Msk
    if (nrf_exc_info.events & SPU_EVENT_PERIPHACCERR){
        nrf_exc_info.periphaccerr.address = spu_get_peri_addr();
    }
#endif

#ifdef MPC_PRESENT
    nrf_exc_info.events |= mpc_events_get();
    if (nrf_exc_info.events & MPC_EVENT_MEMACCERR)
    {
        nrf_exc_info.memaccerr.address = NRF_MPC00->MEMACCERR.ADDRESS;
        nrf_exc_info.memaccerr.info = NRF_MPC00->MEMACCERR.INFO;
    }
#endif

    dump_exception_info(&nrf_exc_info);
}

void nrf_exception_info_get_context(struct nrf_exception_info *ctx)
{
    memcpy(ctx, &nrf_exc_info, sizeof(struct nrf_exception_info));
}

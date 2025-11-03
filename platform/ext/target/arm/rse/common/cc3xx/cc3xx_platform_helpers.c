/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "cc3xx_platform_helpers.h"
#include "rse_sam_config.h"
#include "device_definition.h"
#include "cmsis_compiler.h"

/*
 * RSE-only implementation of the platform CryptoCell DMA hooks.
 *
 * Context:
 *   VM0/VM1 are SRAM regions with ECC. A DMA that updates only a subset of a
 *   64-bit ECC dword can trigger the SAM “SRAM_PARTIAL_WRITE” event.
 *
 * Strategy:
 *   - In prologue: if the DMA destination is within [VM_START, VM_END[,
 *     temporarily disable the SAM event and compute the 64-bit–aligned span
 *     that covers the DMA write.
 *   - In epilogue: after DMA completion, perform a read-modify-write across
 *     each 64-bit dword in the span to recompute ECC, then re-enable the SAM
 *     event.
 */

#define VM_START ((uintptr_t)VM0_BASE_S)
#define VM_END   ((uintptr_t)VM1_BASE_S + VM1_SIZE)  /* one past last */

_Static_assert((VM_START % 8) == 0, "VM_START must be 8-byte aligned");
_Static_assert((VM_END   % 8) == 0, "VM_END must be 8-byte aligned");
_Static_assert(VM1_BASE_S == (VM0_BASE_S + VM0_SIZE), "VM1 must follow VM0");

static struct {
    bool active;
    volatile uint64_t *aligned_start;
    size_t dword_count;
} g_vm_partial_write_fix;

static inline bool addr_in_vm(uintptr_t addr)
{
    return (addr >= VM_START) && (addr < VM_END);
}

static void vm_partial_write_fix_prepare(uintptr_t dst, size_t length)
{
    /* Prologue/epilogue must be paired; no reentrancy */
    assert(!g_vm_partial_write_fix.active);

    /* Ensure span stays within [VM_START, VM_END] and no wrap */
    assert(length <= (size_t)(VM_END - dst));

    /*
     * Compute the 64-bit aligned span that fully covers [dst, dst+length].
     * This function is only called when dst is already in [VM_START, VM_END[
     */
    const uintptr_t mask = (uintptr_t)(sizeof(uint64_t) - 1);
    uintptr_t start_aligned = dst & ~mask;
    uintptr_t end_rounded = (dst + length + mask) & ~mask;

    /* Range must remain within the half-open [VM_START, VM_END[ interval */
    assert((start_aligned >= VM_START) && (end_rounded <= VM_END));

    g_vm_partial_write_fix.active        = true;
    g_vm_partial_write_fix.aligned_start = (volatile uint64_t *)start_aligned;
    g_vm_partial_write_fix.dword_count   = (end_rounded - start_aligned) / sizeof(uint64_t);

    /* Mask the SAM partial-write event for the DMA window. */
    sam_disable_event(&SAM_DEV_S, (enum sam_event_id_t)RSE_SAM_EVENT_SRAM_PARTIAL_WRITE);
}

static void vm_partial_write_fix_apply(void)
{
    volatile uint64_t *vm_ptr = g_vm_partial_write_fix.aligned_start;

    /* Order DMA writes before CPU RMW sequence */
    __DSB();

    for(size_t idx = 0; idx < g_vm_partial_write_fix.dword_count; idx++, vm_ptr++) {
        /* Read-Modify-Write sequence to recompute the ECC tag */
        uint64_t v = *vm_ptr;
        *vm_ptr = v;
    }

    /* Ensure writes hit VM before re-enabling SAM */
    __DSB();

    /* Reset state first to avoid stale reuse on faulting paths */
    memset(&g_vm_partial_write_fix, 0, sizeof(g_vm_partial_write_fix));

    /* Re-enable partial-write SAM event */
    sam_enable_event(&SAM_DEV_S, (enum sam_event_id_t)RSE_SAM_EVENT_SRAM_PARTIAL_WRITE);
}

void cc3xx_dma_platform_prologue(uintptr_t src, uintptr_t dst, size_t length)
{
    (void)src;

    if ((length == 0) || (dst == (uintptr_t)0)) {
        /* Nothing to do */
        return;
    }

    if (addr_in_vm(dst)) {
        vm_partial_write_fix_prepare(dst, length);
    }
}

void cc3xx_dma_platform_epilogue(void)
{
    if (g_vm_partial_write_fix.active) {
        vm_partial_write_fix_apply();
    }
}

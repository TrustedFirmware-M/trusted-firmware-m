/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "rse_sam_config.h"

#include "tfm_hal_device_header.h"
#include "tfm_plat_nv_counters.h"
#include "tfm_hal_platform.h"
#include "device_definition.h"
#include "rse_attack_tracking_counter.h"

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

static uintptr_t get_ecc_address(const struct sam_dev_t *dev,
                                 enum rse_sam_event_id_t event)
{
    switch (event) {
    case RSE_SAM_EVENT_SRAM_PARTIAL_WRITE:
        /* Since we only have one event for all the 4 VMs, we have to iterate
         * through them.
         */
        for (uint32_t vm_id = 0; vm_id < 4; vm_id++) {
            uintptr_t addr = sam_get_vm_partial_write_addr(dev, vm_id);
            if (addr != 0) {
                return addr;
            }
        }
        break;
    case RSE_SAM_EVENT_VM0_SINGLE_ECC_ERROR:
    case RSE_SAM_EVENT_VM1_SINGLE_ECC_ERROR:
    case RSE_SAM_EVENT_VM2_SINGLE_ECC_ERROR:
    case RSE_SAM_EVENT_VM3_SINGLE_ECC_ERROR:
        return sam_get_vm_single_corrected_err_addr(
            dev, event - RSE_SAM_EVENT_VM0_SINGLE_ECC_ERROR);
    case RSE_SAM_EVENT_TRAM_PARITY_ERROR:
        return sam_get_tram_single_corrected_err_addr(dev);
    default:
        break;
    }

    return 0;
}

/* On the fast-path attack tracking counter increment, first set the counter to
 * the incremented value. Once that is done we don't have any performance
 * constraints any more, so we can leisurely handle the outstanding SAM events
 * (which currently all don't have handlers, so just clear the events) and then
 * reset the system.
 *
 * This path deliberately minimizes latency between the event being triggered
 * and the attack counter being incremented, since it minimizes the chance that
 * an attacker can reset the system (by cutting the external power supply, since
 * the SAM events are preserved over a cold reset) and in doing so avoid
 * triggering the attack tracking counter increment.
 */
void __NO_RETURN sam_handle_fast_attack_counter_increment(void)
{
    increment_attack_tracking_counter_major();

    sam_handle_all_events(&SAM_DEV_S);

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
    __builtin_unreachable();
}

static void read_and_write_address(enum sam_event_id_t event_id)
{
    volatile uint64_t *vm_ptr;

    /* Handle any partial writes or ECC errors by reading & writing-back the
     * affected memory address.
     */
    vm_ptr =
        (volatile uint64_t *)get_ecc_address(&SAM_DEV_S,
                                             (enum rse_sam_event_id_t)event_id);

    /* Make sure the address we load/store is 8 byte aligned in order to
     * read/write the correct 64 bit memory doubleword, by aligning it down
     * to the nearest 8-byte boundary, i.e. clear the last three bits of the address
     */
    vm_ptr = (volatile uint64_t *)((uintptr_t)vm_ptr & ~(sizeof(uint64_t) - 1));

    /* The ECC is based on a 64-bit word, so we need to read and write back a 64
     * bit word in order to not trigger a partial write. This is usually done by
     * the cache, but in this case the cache is not in use either because it is
     * disabled or because this memory has been marked as SHAREABLE so it can be
     * accessed by the CC3XX DMA or other bus primaries.
     */
    if (vm_ptr != NULL) {
        /* This must generate a 64-bit doubleword load/store via LDRD and STRD.
         * All tested compilers do this, but if the partial write support isn't
         * working on a new compiler it is worth checking what this compiles to.
         */
        *vm_ptr = *vm_ptr;

        /* If this is an ECC error, likely the address has caching enabled
         * (except in the unlikely case that it is also SHAREABLE due to being
         * accessed by CC3XX or similar). The cache must be flushed here to make
         * sure the write makes it back to the SRAM.
         */
        SCB_CleanInvalidateDCache_by_Addr(vm_ptr, sizeof(uint64_t));
    }
}

static void handle_partial_write(enum sam_event_id_t event_id)
{
    /* perform this action twice, in case there are outstanding partial writes
     * in both VM0 and VM1.
     */
    read_and_write_address(event_id);
    read_and_write_address(event_id);
}

/* The only events that actually have handlers here are the recoverable ECC
 * errors and the SRAM partial writes. All other errors use the fast-path attack
 * counter set which is handled in the interrupt handler so as to avoid the
 * latency overhead of running the SAM event checking code first.
 */
static const sam_event_handler_t rse_handlers[RSE_SAM_EVENT_COUNT] = {
    [RSE_SAM_EVENT_TRAM_PARITY_ERROR]       = read_and_write_address,
    [RSE_SAM_EVENT_VM0_SINGLE_ECC_ERROR]    = read_and_write_address,
    [RSE_SAM_EVENT_VM1_SINGLE_ECC_ERROR]    = read_and_write_address,

    /* Partial writes to the SRAM are not expected - they should be handled by
     * the caching and therefore are treated as programmer errors. Because of
     * this, the partial write event halts the system so that the programmer
     * error can be corrected.
     */
    [RSE_SAM_EVENT_SRAM_PARTIAL_WRITE]      = handle_partial_write,
};

static const enum sam_response_t rse_responses[RSE_SAM_EVENT_COUNT] = {
    /* The watchdog timer resets the system if the NMI isn't handled within a
     * _very_ small amount of cycles. If this handling doesn't happen, it's
     * likely that the system has been rendered inoperable by whatever triggers
     * the fault. The attack tracking is still done after the reset by checking
     * if the SAM watchdog event has triggered.
     */
    [SAM_EVENT_WATCHDOG_TIMER] = SAM_RESPONSE_COLD_RESET,

    /* These events trigger the "fast" attack tracker counting increment, in
     * order to prevent the ability of the attacker to defeat the tracking by
     * power-cycling the device.
     */
    [SAM_EVENT_CONFIG_INTEGRITY_ERROR]      = SAM_RESPONSE_NMI,
    [SAM_EVENT_DUPLICATION_ERROR]           = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_LCM_FATAL_ERROR]         = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_CPU_LOCKUP]              = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_ATU_ERROR]               = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_KMU_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_CRYPTO_PARITY_ERROR]     = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_SIC_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_AES_DFA_ERROR]           = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_AES_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_DMA_DCLS_ERROR]          = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PSI_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_BUS_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PROCESSOR_DCLS_ERROR]    = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PROCESSOR_RAS_SET_0]     = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PROCESSOR_RAS_SET_1]     = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PROCESSOR_RAS_SET_2]     = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_SRAM_MPC_PARITY_ERROR]   = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_SIC_MPC_PARITY_ERROR]    = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_ATU_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_PPR_PARITY_ERROR]        = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_SYSCTRL_PARITY_ERROR]    = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_CPU_PPB_PARITY_ERROR]    = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_SACFG_PARITY_ERROR]      = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_NSACFG_PARITY_ERROR]     = SAM_RESPONSE_NMI,
    [RSE_SAM_EVENT_INTEGRITY_CHECKER_ALARM] = SAM_RESPONSE_NMI,
};

static enum sam_error_t rse_enable_sam_interrupts(void)
{
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return SAM_ERROR_GENERIC_ERROR;
    }

    if (lcs != LCM_LCS_SE) {
        /* Do not enable interrupts */
        return SAM_ERROR_NONE;
    }

    /* Enable SAM interrupts. Set SAM critical security fault to the highest
     * priority and other SAM faults to one lower priority.
     */
    NVIC_SetPriority(SAM_Critical_Sec_Fault_S_IRQn, 0);
    NVIC_SetPriority(SAM_Sec_Fault_S_IRQn, 1);
    NVIC_SetPriority(SRAM_TRAM_ECC_Err_S_IRQn, 1);
    NVIC_SetPriority(SRAM_ECC_Partial_Write_S_IRQn, 1);

    NVIC_EnableIRQ(SAM_Critical_Sec_Fault_S_IRQn);
    NVIC_EnableIRQ(SAM_Sec_Fault_S_IRQn);
    NVIC_EnableIRQ(SRAM_TRAM_ECC_Err_S_IRQn);
    NVIC_EnableIRQ(SRAM_ECC_Partial_Write_S_IRQn);

    return SAM_ERROR_NONE;
}

uint32_t rse_sam_init(bool setup_handlers_only)
{
    enum sam_error_t sam_err;

    sam_err = sam_init(&SAM_DEV_S);
    if (sam_err != SAM_ERROR_NONE) {
        return sam_err;
    }

    /* If the watchdog is pending, then the NMI handler failed to run. In that
     * case do the tracking counter increment here, since the watchdog only
     * catches the NMI used in the fast counter increment path. We don't know
     * which event triggered the watchdog, and we don't want to double-increment
     * the tracking counter, so just clear all the events here.
     */
    if (sam_is_event_pending(&SAM_DEV_S, SAM_EVENT_WATCHDOG_TIMER)) {
        increment_attack_tracking_counter_major();
        sam_clear_all_events(&SAM_DEV_S);
    }

    if (!setup_handlers_only) {
        for (uint32_t idx = 0; idx < ARRAY_LEN(rse_responses); idx++) {
            sam_err = sam_set_event_response(&SAM_DEV_S,
                                             idx,
                                             rse_responses[idx]);
            if (sam_err != SAM_ERROR_NONE) {
                return sam_err;
            }
        }
    }

    for (uint32_t idx = 0; idx < ARRAY_LEN(rse_handlers); idx++) {
        if (rse_handlers[idx] != NULL) {
            sam_err = sam_register_event_handler(&SAM_DEV_S,
                                                 idx,
                                                 rse_handlers[idx]);
            if (sam_err != SAM_ERROR_NONE) {
                return sam_err;
            }
        }
    }

    /* Set the SAM watchdog counter to trigger if NMI is not handled within
     * 256 cycles. If this doesn't happen, then likely whatever happened to the
     * system was fatal and we need to reset (and then do the counter increment
     * afterwards). TODO check this is a sane bound - it should be as tight as
     * possible without having it trigger erroneously.
     */
    sam_set_watchdog_counter_initial_value(&SAM_DEV_S, 0xFF,
                                           SAM_RESPONSE_NMI);

    /* Enable the SAM interrupts. At this point, all pending events will be
     * handled.
     */
    return rse_enable_sam_interrupts();
}

void rse_sam_finish(void)
{
    /* Just disable the interrupts, but leave the events enabled, in case this
     * _finish() is between two boot stages where we can't guarantee the SAM
     * handler pointers are valid. If we have a pending event which triggers a
     * non-interrupt response during the time the SAM is disabled then it will
     * still occur, and if an interrupt is triggered it will just pend until we
     * re-enable these interrupts in _init().
     */
    NVIC_DisableIRQ(SAM_Critical_Sec_Fault_S_IRQn);
    NVIC_DisableIRQ(SAM_Sec_Fault_S_IRQn);
    NVIC_DisableIRQ(SRAM_TRAM_ECC_Err_S_IRQn);
    NVIC_DisableIRQ(SRAM_ECC_Partial_Write_S_IRQn);
}

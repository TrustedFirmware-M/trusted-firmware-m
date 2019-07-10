/*
 * Copyright (c) 2017-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include "region_defs.h"
#include "tfm_core.h"
#include "tfm_internal.h"
#include "tfm_api.h"
#include "tfm_arch.h"
#include "tfm_core_topology.h"
#include "tfm_nspm.h"
#include "platform/include/tfm_spm_hal.h"
#include "uart_stdout.h"
#include "secure_utilities.h"
#include "secure_fw/spm/spm_api.h"
#include "secure_fw/include/tfm_spm_services_api.h"
#ifdef TFM_PSA_API
#include "psa_client.h"
#include "psa_service.h"
#include "tfm_thread.h"
#include "tfm_wait.h"
#include "tfm_message_queue.h"
#include "tfm_spm.h"
#endif

/*
 * Avoids the semihosting issue
 * FixMe: describe 'semihosting issue'
 */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
__asm("  .global __ARM_use_no_argv\n");
#endif

#ifndef TFM_LVL
#error TFM_LVL is not defined!
#endif
#if (TFM_LVL != 1) && (TFM_LVL != 2) && (TFM_LVL != 3)
#error Only TFM_LVL 1, 2 and 3 are supported!
#endif

/* Macros to pick linker symbols and allow to form the partition data base */
#define REGION(a, b, c) a##b##c
#define REGION_NAME(a, b, c) REGION(a, b, c)
#define REGION_DECLARE(a, b, c) extern uint32_t REGION_NAME(a, b, c)

#ifndef TFM_PSA_API
REGION_DECLARE(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Limit);
#endif

REGION_DECLARE(Image$$, ARM_LIB_STACK_MSP,  $$ZI$$Base);

int32_t tfm_core_init(void)
{
    /* Enables fault handlers */
    enable_fault_handlers();

    /* Configures the system reset request properties */
    system_reset_cfg();

    /* Configures debug authentication */
    tfm_spm_hal_init_debug();

    __enable_irq();

    stdio_init();
    LOG_MSG("Secure image initializing!");

#ifdef TFM_CORE_DEBUG
    printf("TFM level is: %d\r\n", TFM_LVL);
#endif

    tfm_core_validate_boot_data();

    tfm_spm_hal_init_isolation_hw();

    configure_ns_code();

    /* Configures all interrupts to retarget NS state, except for
     * secure peripherals
     */
    nvic_interrupt_target_state_cfg();
    /* Enable secure peripherals interrupts */
    nvic_interrupt_enable();

#ifdef TFM_PSA_API
    /* FixMe: In case of IPC messaging, scratch area must not be referenced
     * These variables should be removed when all obsolete references are
     * removed from the codebase
     */
    tfm_scratch_area = NULL;
    tfm_scratch_area_size = 0;
#else
    tfm_scratch_area =
        (uint8_t *)&REGION_NAME(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Base);
    tfm_scratch_area_size =
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Limit) -
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Base);
#endif
    return 0;
}

static int32_t tfm_core_set_secure_exception_priorities(void)
{
    tfm_arch_prioritize_secure_exception();

    /* Explicitly set Secure SVC priority to highest */
    tfm_spm_hal_set_secure_irq_priority(SVCall_IRQn, 0);

    tfm_core_topology_set_pendsv_priority();

    return TFM_SUCCESS;
}

void tfm_core_spm_request_handler(const struct tfm_exc_stack_t *svc_ctx)
{
    uint32_t *res_ptr = (uint32_t *)&svc_ctx->R0;

    /* FixMe: check if caller partition is permitted to make an SPM request */

    switch (svc_ctx->R0) {
    case TFM_SPM_REQUEST_RESET_VOTE:
        /* FixMe: this is a placeholder for checks to be performed before
         * allowing execution of reset
         */
        *res_ptr = TFM_SUCCESS;
        break;
    default:
        *res_ptr = TFM_ERROR_INVALID_PARAMETER;
    }
}

int main(void)
{
    /* set Main Stack Pointer limit */
    uint32_t msp_stack_bottom =
            (uint32_t)&REGION_NAME(Image$$, ARM_LIB_STACK_MSP, $$ZI$$Base);

    tfm_arch_set_msplim(msp_stack_bottom);

    if (tfm_core_init() != 0) {
        /* Placeholder for error handling, currently ignored. */
    }

    if (tfm_spm_db_init() != SPM_ERR_OK) {
        /* Placeholder for error handling, currently ignored. */
    }

    tfm_spm_hal_setup_isolation_hw();

#ifndef TFM_PSA_API
    tfm_spm_partition_set_state(TFM_SP_CORE_ID, SPM_PARTITION_STATE_RUNNING);

    REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base)[];
    uint32_t psp_stack_bottom = (uint32_t)REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base);

    tfm_arch_set_psplim(psp_stack_bottom);

    if (tfm_spm_partition_init() != SPM_ERR_OK) {
        /* Certain systems might refuse to boot altogether if partitions fail
         * to initialize. This is a placeholder for such an error handler
         */
    }

    /*
     * Prioritise secure exceptions to avoid NS being able to pre-empt
     * secure SVC or SecureFault. Do it before PSA API initialization.
     */
    tfm_core_set_secure_exception_priorities();

    /* We close the TFM_SP_CORE_ID partition, because its only purpose is
     * to be able to pass the state checks for the tests started from secure.
     */
    tfm_spm_partition_set_state(TFM_SP_CORE_ID, SPM_PARTITION_STATE_CLOSED);
    tfm_spm_partition_set_state(TFM_SP_NON_SECURE_ID,
                                SPM_PARTITION_STATE_RUNNING);

#ifdef TFM_CORE_DEBUG
    /* Jumps to non-secure code */
    LOG_MSG("Jumping to non-secure code...");
#endif

    jump_to_ns_code();
#else
    /*
     * Prioritise secure exceptions to avoid NS being able to pre-empt
     * secure SVC or SecureFault. Do it before PSA API initialization.
     */
    tfm_core_set_secure_exception_priorities();

    tfm_spm_init();
#endif
}

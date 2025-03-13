/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2020-2022 NXP. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "target_cfg.h"
#include "tfm_hal_platform.h"
#include "tfm_plat_defs.h"
#include "uart_stdout.h"
#include "fih.h"
#include "region_defs.h"
#include "region.h"
#include "tfm_log.h"

/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
REGION_DECLARE(Image$$, ER_VENEER, $$Base);
REGION_DECLARE(Image$$, VENEER_ALIGN, $$Limit);
#ifdef BL2
REGION_DECLARE(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base);
#endif /* BL2 */

const struct memory_region_limits memory_regions = {
    .non_secure_code_start =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        BL2_HEADER_SIZE,

    .non_secure_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

    .non_secure_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        NS_PARTITION_SIZE - 1,

    .veneer_base =
        (uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),

    .veneer_limit =
        (uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit) - 1,

#ifdef BL2
    .secondary_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base),

    .secondary_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base) +
        SECONDARY_PARTITION_SIZE - 1,
#endif /* BL2 */
};

extern void BOARD_InitHardware(void);

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_platform_init(void)
{
    enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;

    BOARD_InitHardware();

    stdio_init();

    plat_err = enable_fault_handlers();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = system_reset_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = init_debug();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    __enable_irq();

    plat_err = nvic_interrupt_target_state_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    plat_err = nvic_interrupt_enable();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode(TFM_HAL_ERROR_GENERIC));
    }

    FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

uint32_t tfm_hal_get_ns_VTOR(void)
{
    return memory_regions.non_secure_code_start;
}

uint32_t tfm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)memory_regions.non_secure_code_start);
}

uint32_t tfm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(memory_regions.non_secure_code_start + 4));
}

enum tfm_plat_err_t enable_fault_handlers(void)
{
    /* Explicitly set secure fault priority to the highest */
    NVIC_SetPriority(SecureFault_IRQn, 0);

    /* Enables BUS, MEM, USG and Secure faults */
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
                  | SCB_SHCSR_BUSFAULTENA_Msk
                  | SCB_SHCSR_MEMFAULTENA_Msk
                  | SCB_SHCSR_SECUREFAULTENA_Msk;
    return TFM_PLAT_ERR_SUCCESS;
}

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

enum tfm_plat_err_t system_reset_cfg(void)
{
    uint32_t reg_value = SCB->AIRCR;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Enable system reset request only to the secure world */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_debug(void)
{

#if !defined(DAUTH_CHIP_DEFAULT)
#error "Debug features are set during provisioning. Application is not able to change them as the SYSCTRL->DEBUG_LOCK_EN is locked by the MCU secure boot.  "
#endif
    return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt target state to NS configuration ----------*/
enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
    /* Target every interrupt to NS; unimplemented interrupts will be WI */
    for (uint8_t i=0; i<sizeof(NVIC->ITNS)/sizeof(NVIC->ITNS[0]); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFF;
    }

    /* Make sure that MPC and PPC are targeted to S state */
    NVIC_ClearTargetState(SEC_VIO_IRQn);

    return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
enum tfm_plat_err_t nvic_interrupt_enable(void)
{
    /* MPC/PPC interrupt enabling */
    NVIC_EnableIRQ(SEC_VIO_IRQn);

    return TFM_PLAT_ERR_SUCCESS;
}

/* Alternative Control Flow Integrity, using  Code Watchdog Timer */
#if defined(FIH_ENABLE_CFI) & defined(FIH_CFI_ALT) & defined(CDOG)

#include "fsl_cdog.h"

static volatile bool cdog_init_is_done = false;
static void fih_cdog_init(void)
{
    status_t result = kStatus_Fail;
    cdog_config_t conf;

    /* Initialize CDOG */
    CDOG_GetDefaultConfig(&conf);

    conf.timeout    = kCDOG_FaultCtrl_EnableInterrupt;
    conf.miscompare = kCDOG_FaultCtrl_EnableInterrupt;
    conf.sequence   = kCDOG_FaultCtrl_EnableInterrupt;
    conf.state      = kCDOG_FaultCtrl_EnableInterrupt;
    conf.address    = kCDOG_FaultCtrl_EnableInterrupt;
    conf.irq_pause  = kCDOG_IrqPauseCtrl_Pause;
    conf.debug_halt = kCDOG_DebugHaltCtrl_Pause;
    conf.lock       = kCDOG_LockCtrl_Lock; /* Lock */ //kCDOG_LockCtrl_Unlock;

    /* Clears pending FLAGS and sets CONTROL register */
    result = CDOG_Init(CDOG, &conf);
    if (result != kStatus_Success)
    {
        ERROR_RAW("[CDOG] Init error.\n");
        FIH_PANIC;
    }

    cdog_init_is_done = true;
}

void CDOG_DriverIRQHandler(void)
{
    NVIC_ClearPendingIRQ(CDOG_IRQn);

    ERROR_RAW("[CDOG IRQ] ");

    if ((CDOG->FLAGS & CDOG_FLAGS_TO_FLAG_MASK))
    {
        ERROR_RAW("Timeout ");
    }
    if ((CDOG->FLAGS & CDOG_FLAGS_MISCOM_FLAG_MASK))
    {
        ERROR_RAW("Miscompare ");
    }
    if ((CDOG->FLAGS & CDOG_FLAGS_SEQ_FLAG_MASK))
    {
        ERROR_RAW("Sequence ");
    }
    if ((CDOG->FLAGS & CDOG_FLAGS_CNT_FLAG_MASK))
    {
        ERROR_RAW("Control ");
    }
    if ((CDOG->FLAGS & CDOG_FLAGS_STATE_FLAG_MASK))
    {
        ERROR_RAW("State ");
    }
    if ((CDOG->FLAGS & CDOG_FLAGS_ADDR_FLAG_MASK))
    {
        ERROR_RAW("Address ");
    }
    ERROR_RAW("fault occured\n");

    FIH_PANIC;
}

fih_int fih_cfi_get_and_increment(uint8_t cnt)
{
    fih_int saved_ctr = _fih_cfi_ctr;

    /* HW */
    if(cdog_init_is_done == false)
    {
        fih_cdog_init();
    }

    /* Start if in the IDLE state */
    if((CDOG->STATUS & CDOG_STATUS_CURST_MASK) == CDOG_STATUS_CURST(0x5)) {
        CDOG_Start(CDOG, 0xFFFFFFFF, fih_int_decode(saved_ctr));
    }

    CDOG_Add(CDOG, cnt);

    /* SW */
    _fih_cfi_ctr = fih_int_encode(fih_int_decode(_fih_cfi_ctr) + cnt);

    return saved_ctr;
}

void fih_cfi_validate(fih_int saved)
{
    /* HW */
    CDOG_Stop(CDOG, fih_int_decode(saved));
}

void fih_cfi_decrement(void)
{
    /* HW */
    /* Start if in the IDLE state */
    if((CDOG->STATUS & 0xF0000000) == 0x50000000) {
        CDOG_Start(CDOG, 0xFFFFFFFF, (fih_int_decode(_fih_cfi_ctr)));
    }
    CDOG_Sub1(CDOG);

    /* SW */
    _fih_cfi_ctr = fih_int_encode(fih_int_decode(_fih_cfi_ctr) - 1);
}
#endif /* defined(FIH_ENABLE_CFI) & defined(FIH_CFI_ALT) & defined(CDOG) */


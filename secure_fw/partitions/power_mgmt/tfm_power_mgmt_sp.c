/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_power_mgmt.h"

#include "power_mgmt/tfm_power_mgmt_api.h"
#include "psa/framework_feature.h"
#include "psa/service.h"

#if TFM_POWER_MGMT_ARCH_SUPPORTED == 1
#include "cmsis.h"
#endif

#include "tfm_log.h"
#include "tfm_hal_device_header.h"
#include "utilities.h"
#include "critical_section.h"

static const struct plat_power_mgmt_set_state_callback_settings_t *plat_callbacks;
static power_mgmt_get_callback_t get_callback;
static size_t callbacks_count;
volatile uint32_t *ret_ram_addr;

#if TFM_POWER_MGMT_ARCH_SUPPORTED == 1

extern void Reset_Handler(void);

/*
 * layout
 * [0]      r0
 * [1-11]   r1-r11
 * [12]     r12
 * [13]     sp
 * [14]     xPSR
 * [15]     LR
 */
enum tfm_power_mgmt_mem_ret_layout_t {
    TFM_POWER_MGMT_MEMRET_LAYOUT_R0 = 0,
    TFM_POWER_MGMT_MEMRET_LAYOUT_R12 = 12,
    TFM_POWER_MGMT_MEMRET_LAYOUT_SP = 13,
    TFM_POWER_MGMT_MEMRET_LAYOUT_XPSR = 14,
    TFM_POWER_MGMT_MEMRET_LAYOUT_LR = 15,

    TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI,
    TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL,
    TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK,
    TFM_POWER_MGMT_MEMRET_LAYOUT_MSP,
    TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PSP,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM,
#if (CONFIG_TFM_FLOAT_ABI >= 1)
    TFM_POWER_MGMT_MEMRET_LAYOUT_FPSCR,
#endif

#ifdef CONFIG_TFM_USE_TRUSTZONE
    TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_MSP_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PSP_NS,
    TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM_NS,
#endif

};

typedef void(*VECTOR_TABLE_Type)(void);

static void restore_special_purpose_regs(void);

void Reset_Handler_Resume_MEM_RET(void)
{
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified        \n"
#endif
        "ldr    r4, =ret_ram_addr   \n"
        "ldr    r4, [r4]        \n"

        "add    r4, #52         \n"
        "ldr    r1, [r4]        \n"
        "sub    r1, #32         \n"
        "mov    sp, r1          \n"

        "add    r1, #24         \n"
        "ldr    r2, =ret_address\n"
        "str    r2, [r1]        \n"

        "add    r1, #4          \n"
        "add    r4, #4          \n"
        "ldr    r3, [r4]        \n"
        "str    r3, [r1]        \n"

        "sub    r1, #8          \n"
        "add    r4, #4          \n"
        "ldr    r3, [r4]        \n"
        "str    r3, [r1]        \n"

        /* restore r0-r3, r12 */
        "ldr    r4, =ret_ram_addr  \n"
        "ldr    r4, [r4]        \n"
        "ldmia  r4, {r0-r12}    \n"

        "push   {r5}            \n"
        "mov    r5, sp          \n"
        "add    r5, #4          \n"
        "stmia  r5!, {r0-r3}    \n"
        "str    r12, [r5]       \n"
        "pop    {r5}            \n"

        "movs   r0, #"M2S(EXC_RETURN_THREAD_PSP)"   \n"
        "mov    lr, r0          \n"

        "bx     lr              \n"
    );

}

static void save_vectors(void)
{
    VECTOR_TABLE_Type *vt = (VECTOR_TABLE_Type *)SCB->VTOR;
    vt[1] = Reset_Handler_Resume_MEM_RET;
}

static void restore_vectors(void)
{
    VECTOR_TABLE_Type *vt = (VECTOR_TABLE_Type *)SCB->VTOR;
    vt[1] = Reset_Handler;
}

static inline __attribute__((always_inline)) void save_all_regs_naked(void)
{
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified            \n"
#endif
        "push       {r0}            \n"

        "push       {r1}            \n"
        "mrs        r1, xpsr        \n"
        "orr        r1, r1, #(1 << 24) \n"
        "ldr        r0, =ret_ram_addr  \n"
        "ldr        r0, [r0]        \n"
        "add        r0, #56         \n"
        "str        r1, [r0]        \n"

        "add        r0, #4          \n"
        "str        lr, [r0]        \n"

        "pop        {r1}            \n"

        "ldr        r0, =ret_ram_addr  \n"
        "ldr        r0, [r0]        \n"
        "stmia      r0, {r0-r12}    \n"
        "mov        r1, r0          \n"
        "mov        r2, r0          \n"
        "add        r0, #52         \n"

        "mov        r1, sp          \n"
        "add        r1, #4          \n"
        "str        r1, [r0]        \n"

        "pop        {r0}            \n"
        "str        r0, [r2]        \n"
    );
}

static void save_special_purpose_regs(void)
{
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI] = __get_BASEPRI();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL] = __get_CONTROL();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK] = __get_FAULTMASK();
#if (CONFIG_TFM_FLOAT_ABI >= 1)
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FPSCR] = __get_FPSCR();
#endif
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSP] = __get_MSP();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM] = __get_MSPLIM();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK] = __get_PRIMASK();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSP] = __get_PSP();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM] = __get_PSPLIM();

#ifdef CONFIG_TFM_USE_TRUSTZONE
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI_NS] = __TZ_get_BASEPRI_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL_NS] = __TZ_get_CONTROL_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK_NS] = __TZ_get_FAULTMASK_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSP_NS] = __TZ_get_MSP_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM_NS] = __TZ_get_MSPLIM_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK_NS] = __TZ_get_PRIMASK_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSP_NS] = __TZ_get_PSP_NS();
    ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM_NS] = __TZ_get_PSPLIM_NS();
#endif
}

static void restore_special_purpose_regs(void)
{
    __set_BASEPRI(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI]);
    __set_CONTROL(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL]);
    __set_FAULTMASK(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK]);
#if (CONFIG_TFM_FLOAT_ABI >= 1)
    __set_FPSCR(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FPSCR]);
#endif
    __set_MSP(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSP]);
    __set_MSPLIM(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM]);
    __set_PRIMASK(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK]);
    __set_PSP(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSP]);
    __set_PSPLIM(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM]);

#ifdef CONFIG_TFM_USE_TRUSTZONE
    __TZ_set_BASEPRI_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_BASEPRI_NS]);
    __TZ_set_CONTROL_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_CONTROL_NS]);
    __TZ_set_FAULTMASK_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_FAULTMASK_NS]);
    __TZ_set_MSP_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSP_NS]);
    __TZ_set_MSPLIM_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_MSPLIM_NS]);
    __TZ_set_PRIMASK_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PRIMASK_NS]);
    __TZ_set_PSP_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSP_NS]);
    __TZ_set_PSPLIM_NS(ret_ram_addr[TFM_POWER_MGMT_MEMRET_LAYOUT_PSPLIM_NS]);
#endif
}

static void power_state_retention(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    SCB_DisableDCache();
    SCB_DisableICache();
    SCB_InvalidateICache();
    SCB_CleanInvalidateDCache();
    SCB_CleanDCache();

    __disable_irq();

    MEMSYSCTL->MSCR &= ~(
        (0b1 << MEMSYSCTL_MSCR_DCACTIVE_Pos) |
        (0b1 << MEMSYSCTL_MSCR_ICACTIVE_Pos));

    ICB->CPPWR |= 0xFFFFFFFF;
    ICB->CPPWR |= 0x05;
    SCB->CPACR = 0x00;
    __DSB();

    PWRMODCTL->CPDLPSTATE |=
        ((0x03 << PWRMODCTL_CPDLPSTATE_ELPSTATE_Pos) |
        (0x02 << PWRMODCTL_CPDLPSTATE_RLPSTATE_Pos) |
        (0x03 << PWRMODCTL_CPDLPSTATE_CLPSTATE_Pos));

    __DSB();
    __ISB();
}

static void power_state_off(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    SCB_DisableDCache();
    SCB_DisableICache();
    SCB_InvalidateICache();
    SCB_CleanInvalidateDCache();
    SCB_CleanDCache();

    __disable_irq();

    MEMSYSCTL->MSCR &= ~(
        (0b1 << MEMSYSCTL_MSCR_DCACTIVE_Pos) |
        (0b1 << MEMSYSCTL_MSCR_ICACTIVE_Pos));

    ICB->CPPWR |= 0xFFFFFFFF;
    ICB->CPPWR |= 0x05;
    SCB->CPACR = 0x00;
    __DSB();

    PWRMODCTL->CPDLPSTATE |=
        (PWRMODCTL_CPDLPSTATE_ELPSTATE_Msk |
        PWRMODCTL_CPDLPSTATE_RLPSTATE_Msk |
        PWRMODCTL_CPDLPSTATE_CLPSTATE_Msk);

    __DSB();
    __ISB();
}
#endif

static psa_status_t process_cpu_system_states(struct tfm_power_mgmt_set_params *params)
{
    struct critical_section_t cs = CRITICAL_SECTION_STATIC_INIT;

#if TFM_POWER_MGMT_ARCH_SUPPORTED == 1

    switch (params->pwr_state) {
    case TFM_POWER_MGMT_PWR_STATE_OFF:
    case TFM_POWER_MGMT_PWR_STATE_HIBERNATE:
        power_state_off();

        break;

    case TFM_POWER_MGMT_PWR_STATE_SLEEP:
        break;
    case TFM_POWER_MGMT_PWR_STATE_DEEPSLEEP:
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        break;
    case TFM_POWER_MGMT_PWR_STATE_SUSPEND:
        power_state_retention();

        CRITICAL_SECTION_ENTER(cs);

        save_vectors();

        save_special_purpose_regs();

        save_all_regs_naked();

#if (CONFIG_TFM_FLOAT_ABI > 0)
        /* TODO */
#endif

        CRITICAL_SECTION_LEAVE(cs);
        break;

    default:
        break;
    }

    if (params->wait_for == TFM_POWER_MGMT_WAIT_FOR_INTERRUPT) {
        __WFI();
    }
    if (params->wait_for == TFM_POWER_MGMT_WAIT_FOR_EVENT) {
        __WFE();
    }

    /* this is just a placeholder */
    __asm__ volatile (
        ".global ret_address\n"
        "ret_address:\n"
    );

    switch (params->pwr_state) {
    case TFM_POWER_MGMT_PWR_STATE_OFF:
    case TFM_POWER_MGMT_PWR_STATE_HIBERNATE:
        tfm_core_panic();
        break;
    case TFM_POWER_MGMT_PWR_STATE_SLEEP:
        break;
    case TFM_POWER_MGMT_PWR_STATE_DEEPSLEEP:
        SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
        break;
    case TFM_POWER_MGMT_PWR_STATE_SUSPEND:
        CRITICAL_SECTION_ENTER(cs);

        restore_vectors();

        restore_special_purpose_regs();

        CRITICAL_SECTION_LEAVE(cs);
        break;

    default:
        break;
    }

#else
    return PSA_ERROR_NOT_SUPPORTED;

#endif

    return PSA_SUCCESS;
}

static psa_status_t tfm_power_mgmt_set_power_state(
    struct tfm_power_mgmt_set_params *params)
{
    enum tfm_power_mgmt_err_t ret;
    psa_status_t status;

    if (params->pwr_state >= TFM_POWER_MGMT_PWR_STATE_MAX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (params->pwr_state < TFM_POWER_MGMT_PWR_STATE_CPUSYSTEM_COUNT) {
        /* cpu states */
        if (!((params->wait_for == TFM_POWER_MGMT_WAIT_FOR_EVENT) ||
            (params->wait_for == TFM_POWER_MGMT_WAIT_FOR_INTERRUPT))) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    } else {
        /* custom states */
        if (params->wait_for != TFM_POWER_MGMT_WAIT_FOR_NONE) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
    if ((params->pwr_state == TFM_POWER_MGMT_PWR_STATE_SUSPEND) &&
        (ret_ram_addr == NULL)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if ((callbacks_count == 0) && (params->pwr_state <= TFM_POWER_MGMT_PWR_STATE_HIBERNATE)) {
        /* Simple operation when no hooks/callbacks are required */
        return process_cpu_system_states(params);
    }

    /* pre-state */
    for (size_t i = 0; i < callbacks_count; i++) {
        if ((plat_callbacks[i].state == params->pwr_state) && (plat_callbacks[i].pre_cb != NULL)) {
            ret = plat_callbacks[i].pre_cb(params->pwr_state);
            if ((ret != TFM_POWER_MGMT_ERR_SUCCESS) &&
                (plat_callbacks[i].policy == TFM_POWER_MGMT_PWR_POLICY_GRACEFUL)) {
                /* NOTE: here the UART must be available */
                WARN("[PWR-MGMT] Incomplete pre-transition\r\n");
                return PSA_OPERATION_INCOMPLETE;
            }
        }
    }

    if (params->pwr_state <= TFM_POWER_MGMT_PWR_STATE_HIBERNATE) {
        /* call arch-specific power states */
        status = process_cpu_system_states(params);
        if (status != PSA_SUCCESS) {
            return status;
        }
    }

    /* post-state */
    for (size_t i = 0; i < callbacks_count; i++) {
        if ((plat_callbacks[i].state == params->pwr_state) && (plat_callbacks[i].post_cb != NULL)) {
            ret = plat_callbacks[i].post_cb(params->pwr_state);
            if ((ret != TFM_POWER_MGMT_ERR_SUCCESS) &&
                (plat_callbacks[i].policy == TFM_POWER_MGMT_PWR_POLICY_GRACEFUL)) {
                /* NOTE: here the UART must be available */
                WARN("[PWR-MGMT] Incomplete post-transition\r\n");
                return PSA_OPERATION_INCOMPLETE;
            }
        }
    }

    return PSA_SUCCESS;
}

static psa_status_t tfm_power_mgmt_get_power_state(
    struct tfm_power_mgmt_get_params *params,
    int32_t *dev_state)
{
    enum tfm_power_mgmt_err_t status;

    if (params->device_id > PLAT_POWER_MGMT_DEVICE_ID_MAX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = (*get_callback)(params->device_id, dev_state);

    return PSA_SUCCESS;
}

static psa_status_t tfm_power_mgmt_power_state(const psa_msg_t *msg)
{
#if PSA_FRAMEWORK_HAS_MM_IOVEC == 1
    const void *p_data;
#else
    size_t len;
#endif

    psa_status_t status;
    int32_t dev_state;

    union tfm_power_mgmt_call_params pm_params;

    if (msg->in_size[0] != sizeof(pm_params)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

#if PSA_FRAMEWORK_HAS_MM_IOVEC == 1
    p_data = psa_map_invec(msg->handle, 0);
    (void)memcpy(&pm_params, p_data, sizeof(pm_params));
    psa_unmap_invec(msg->handle, 0);
#else
    len = psa_read(msg->handle, 0, &pm_params, sizeof(pm_params));
    if (len != sizeof(pm_params)) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }
#endif

    switch (pm_params.call_type) {
    case TFM_POWER_MGMT_SET:
        status = tfm_power_mgmt_set_power_state(&pm_params.set);
        break;

    case TFM_POWER_MGMT_GET:
        if (get_callback == NULL) {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }
        if (msg->out_size[0] != sizeof(dev_state)) {
            return PSA_ERROR_PROGRAMMER_ERROR;
        }

        status = tfm_power_mgmt_get_power_state(&pm_params.get, &dev_state);
#if PSA_FRAMEWORK_HAS_MM_IOVEC == 1
        void *p_odata;
        p_odata = psa_map_outvec(msg->handle, 0);
        if (p_odata != NULL) {
            *(int32_t *)p_odata = dev_state;
            psa_unmap_outvec(msg->handle, 0, sizeof(dev_state));
        } else {
            psa_unmap_outvec(msg->handle, 0, 0);
        }
#else
        psa_write(msg->handle, 0, &dev_state, sizeof(dev_state));
#endif

        break;

    default:
        status = PSA_ERROR_NOT_SUPPORTED;
        break;
    }

    return status;
}

psa_status_t tfm_power_mgmt_service_sfn(const psa_msg_t *msg)
{
    psa_status_t status;

    switch (msg->type) {
    case PSA_IPC_CALL:
        status = tfm_power_mgmt_power_state(msg);
        break;
    default:
        status = PSA_ERROR_NOT_SUPPORTED;
        break;
    }

    return status;
}

psa_status_t power_mgmt_sp_init(void)
{
    enum tfm_power_mgmt_err_t status;

    platform_power_mgmt_get_power_table(&plat_callbacks, &callbacks_count);

    ret_ram_addr = NULL;
    status = platform_power_mgmt_get_retention_memory(
        &ret_ram_addr,
        SIZE_OF_RETAINED_MEMORY);
    if (status != TFM_POWER_MGMT_ERR_SUCCESS) {
        /* SUSPEND not supported */
        ret_ram_addr = NULL;
    }

    if (callbacks_count == 0) {
        return PSA_SUCCESS;
    }
    if (plat_callbacks == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* validate table */
    for (size_t i = 0; i < callbacks_count; i++) {
        if (plat_callbacks[i].state > TFM_POWER_MGMT_PWR_STATE_MAX) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        if (plat_callbacks[i].policy >= TFM_POWER_MGMT_PWR_POLICY_COUNT) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        /* If there's a valid state there must be at least one valid callback */
        if ((plat_callbacks[i].pre_cb == NULL) && (plat_callbacks[i].post_cb == NULL)) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    get_callback = NULL;
    status = platform_power_mgmt_get_callback(&get_callback);
    if ((status != TFM_POWER_MGMT_ERR_SUCCESS) || (PLAT_POWER_MGMT_DEVICE_ID_MAX == 0)) {
        /* not supported */
        get_callback = NULL;
    }

    return PSA_SUCCESS;
}

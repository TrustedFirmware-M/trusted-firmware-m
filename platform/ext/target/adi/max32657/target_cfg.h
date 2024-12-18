/*
 * Copyright (c) 2017-2021 Arm Limited
 * Portions Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TARGET_CFG_H__
#define __TARGET_CFG_H__

#include "uart_stdout.h"
#include "tfm_peripherals_def.h"
#include "tfm_plat_defs.h"
#include "fih.h"

#define TFM_DRIVER_STDIO    Driver_USART0
#define NS_DRIVER_STDIO     Driver_USART0


/**
 * @brief Defines word offsets of the PPC
 */
enum ppc_bank_e {
    PPC_SP_DO_NOT_CONFIGURE = -1,
    PPC_SP_PPC0,
};

/**
 * \brief Defines the bit offsets of within the SPC
 */
enum spc_periph_e {
   SPC_GCR = 0,
   SPC_SIR,
   SPC_FCR,
   SPC_WDT,
   SPC_AES,
   SPC_AESKEY,
   SPC_CRC,
   SPC_GPIO0,
   SPC_TIMER0,
   SPC_TIMER1,
   SPC_TIMER2,
   SPC_TIMER3,
   SPC_TIMER4,
   SPC_TIMER5,
   SPC_I3C,
   SPC_UART,
   SPC_SPI,
   SPC_TRNG,
   SPC_BTLE_DBB,
   SPC_BTLE_RFFE,
   SPC_RSTZ,
   SPC_BOOST,
   SPC_BBSIR,
   SPC_BBFCR,
   SPC_RTC,
   SPC_WUT0,
   SPC_WUT1,
   SPC_PWR,
   SPC_MCR,
   NUM_SPC_PERIPH
};

/**
 * \brief Store the addresses of memory regions
 */
struct memory_region_limits {
    uint32_t non_secure_code_start;
    uint32_t non_secure_partition_base;
    uint32_t non_secure_partition_limit;
    uint32_t veneer_base;
    uint32_t veneer_limit;
#ifdef BL2
    uint32_t secondary_partition_base;
    uint32_t secondary_partition_limit;
#endif /* BL2 */
};

/**
 * \brief Holds the data necessary to do isolation for a specific peripheral.
 */
struct platform_data_t {
    uint32_t periph_start;
    uint32_t periph_limit;
    enum ppc_bank_e periph_ppc_bank;
    int16_t periph_ppc_loc;
};

/**
 * \brief Configures the Memory Protection Controller.
 *
 * \return  Returns error code.
 */
FIH_RET_TYPE(int32_t) mpc_init_cfg(void);

/**
 * \brief Configures the Peripheral Protection Controller.
 */
FIH_RET_TYPE(int32_t) ppc_init_cfg(void);

/**
 * \brief Restict access to peripheral to secure
 */
FIH_RET_TYPE(int32_t) ppc_configure_to_secure(uint16_t loc);

/**
 * \brief Allow non-secure access to peripheral
 */
void ppc_configure_to_non_secure(uint16_t loc);

/**
 * \brief Enable secure unprivileged access to peripheral
 */
FIH_RET_TYPE(int32_t) ppc_en_secure_unpriv(uint16_t pos);

/**
 * \brief Clear secure unprivileged access to peripheral
 */
FIH_RET_TYPE(int32_t) ppc_clr_secure_unpriv(uint16_t pos);

/**
 * \brief Clears PPC interrupt.
 */
void ppc_clear_irq(void);

/**
 * \brief Configures SAU and IDAU.
 */
FIH_RET_TYPE(int32_t) sau_and_idau_cfg(void);

/**
 * \brief Enables the fault handlers and sets priorities.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t enable_fault_handlers(void);

/**
 * \brief Configures the system reset request properties
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t system_reset_cfg(void);

/**
 * \brief Configures the system debug properties.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
FIH_RET_TYPE(enum tfm_plat_err_t) init_debug(void);

/**
 * \brief Configures all external interrupts to target the
 *        NS state, apart for the ones associated to secure
 *        peripherals (plus MPC and PPC)
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void);

/**
 * \brief This function enable the interrupts associated
 *        to the secure peripherals (plus the isolation boundary violation
 *        interrupts)
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */
enum tfm_plat_err_t nvic_interrupt_enable(void);

/* Function for FIH to verify that SAU & IDAU are correctly configured. */
fih_int fih_verify_sau_and_idau_cfg(void);

/* Function for FIH to verify that MPC is correctly configured. */
fih_int fih_verify_mpc_cfg(void);

/* Function for FIH to verify that PPC is correctly configured. */
fih_int fih_verify_ppc_cfg(void);

#endif /* __TARGET_CFG_H__ */

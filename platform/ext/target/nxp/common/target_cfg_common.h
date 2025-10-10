/*
 * Copyright (c) 2018-2020 Arm Limited
 * Copyright 2019-2023, 2025 NXP
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

#ifndef __TARGET_CFG_COMMON_H__
#define __TARGET_CFG_COMMON_H__

#include "uart_stdout.h"
#include "tfm_peripherals_def.h"
#if defined(TFM_LPUART_FEATURE)
#include "fsl_lpuart.h"
#else
#include "fsl_usart.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TARGET_DEBUG_LOG
#define TARGET_DEBUG_LOG 0
#endif

/* HARDENING_MACROS_ENABLED is NOT defined*/
#ifndef HARDENING_MACROS_ENABLED
#define SECURE_WRITE_REGISTER( ADDRESS, VALUE )   \
    *ADDRESS = VALUE                              \

#define SECURE_READ_MODIFY_WRITE_REGISTER( ADDRESS, MASK, FLAG )\
    *ADDRESS = ((*ADDRESS & MASK) | (FLAG))                     \

#else /* HARDENING_MACROS_ENABLED is defined*/

/* Defined for IAR (iar compiler) and Keil (armclang compiler)*/
#if defined( __ICCARM__ ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
/*
* SECURE_WRITE_REGISTER(ADDRESS, VALUE) macro function.
* Writes the given value to the given address, reads back the value for verification. In case of
* mismatch, tfm_core_panic() is called. For robustness against fault injection, the address is loaded twice.
* Also the verification step can not be skipped with a single glitch.
* Typical usecase is to write a constant to a particular register.
*/
/* Macro for register write that is robust against instruction glitch */
#define SECURE_WRITE_REGISTER( ADDRESS, VALUE )   \
do{                                               \
    __asm volatile ("MOVS  R4, #0x5A\n"           \
        "MOV   R0, %0\n"                          \
        "MOV   R2, %1\n"                          \
        "STR   R2, [R0]\n"                        \
        "MOV   R1, %0\n"                          \
        "LDR   R4, [R1]\n"                        \
        "MOV   R3, %1\n"                          \
        "CMP   R4, R3\n"                          \
        "BEQ   sec_write_exit%=\n"                \
        "BL    fault_detect_handling\n"           \
        "sec_write_exit%=:\n"                     \
        :: "r"(ADDRESS),                          \
           "r" (VALUE)                            \
           :"r0", "r1", "r2", "r3", "r4");        \
}while(false)

/* Macro for register read-modify-write that is robust against instruction glitch */
#define SECURE_READ_MODIFY_WRITE_REGISTER( ADDRESS, MASK, FLAG )\
do{                                                \
    __asm volatile ("MOV   R2, %0\n"               \
        "LDR   R0, [R2]\n"                         \
        "MOV   R4, %1\n"                           \
        "AND   R0, R4\n"                           \
        "MOV   R4, %2\n"                           \
        "ORR   R0, R4\n"                           \
        "MOV   R3, %0\n"                           \
        "LDR   R1, [R3]\n"                         \
        "MOV   R5, %1\n"                           \
        "AND   R1, R5\n"                           \
        "MOV   R5, %2\n"                           \
        "ORR   R1, R5\n"                           \
        "MOVS  R4, #0x5A\n"                        \
        "STR   R0, [R2]\n"                         \
        "LDR   R4, [R3]\n"                         \
        "CMP   R1, R4\n"                           \
        "BEQ   sec_write_exit%=\n"                 \
        "BL    fault_detect_handling\n"            \
        "sec_write_exit%=:\n"                      \
        :: "r" (ADDRESS),                          \
           "r" (MASK),                             \
           "r" (FLAG)                              \
           :"r0", "r1", "r2", "r3", "r4", "r5");   \
}while(false)

/* check for: gcc and armgcc */
#elif defined (__GNUC__)
/* Macro for register write that is robust against instruction glitch */
#define SECURE_WRITE_REGISTER( ADDRESS, VALUE )                    \
do{                                                           \
    __asm__ volatile ("MOVS  R4, #0x5A\n" ::                      \
                  : "r0", "r1", "r2", "r3", "r4");            \
    __asm__ volatile ("LDR   R0, =%0\n"   :: "i" (ADDRESS));      \
    __asm__ volatile ("LDR   R2, =%0\n"   :: "i" (VALUE));        \
    __asm__ volatile ("STR   R2, [R0]\n");                        \
    __asm__ volatile ("LDR   R1, =%0\n"   :: "i" (ADDRESS));      \
    __asm__ volatile ("LDR   R4, [R1]\n");                        \
    __asm__ volatile ("LDR   R3, =%0\n"   :: "i" (VALUE));        \
    __asm__ volatile ("CMP   R4, R3\n");                          \
    __asm__ volatile ("BEQ   1f\n");                              \
    __asm__ volatile ("BL    fault_detect_handling\n");           \
    __asm__ volatile (".word 0xde00de00\n");                      \
    __asm__ volatile ("1:\n");                                    \
}while(false)

/* Macro for register read-modify-write that is robust against instruction glitch */
#define SECURE_READ_MODIFY_WRITE_REGISTER( ADDRESS, MASK, FLAG ) \
do{                                                           \
    __asm__ volatile ("LDR   R2, =%0\n" :: "i" (ADDRESS)          \
                  : "r0", "r1", "r2", "r3", "r4", "r5");      \
    __asm__ volatile ("LDR   R0, [R2]\n");                        \
    __asm__ volatile ("LDR   R4, =%0\n" :: "i" (MASK));           \
    __asm__ volatile ("AND   R0, R4\n");                          \
    __asm__ volatile ("LDR   R4, =%0\n" :: "i" (FLAG));           \
    __asm__ volatile ("ORR   R0, R4\n");                          \
    __asm__ volatile ("LDR   R3, =%0\n" :: "i" (ADDRESS));        \
    __asm__ volatile ("LDR   R1, [R3]\n");                        \
    __asm__ volatile ("LDR   R5, =%0\n" :: "i" (MASK));           \
    __asm__ volatile ("AND   R1, R5\n");                          \
    __asm__ volatile ("LDR   R5, =%0\n" :: "i" (FLAG));           \
    __asm__ volatile ("ORR   R1, R5\n");                          \
    __asm__ volatile ("MOVS  R4, #0x5A\n");                       \
    __asm__ volatile ("STR   R0, [R2]\n");                        \
    __asm__ volatile ("LDR   R4, [R3]\n");                        \
    __asm__ volatile ("CMP   R1, R4\n");                          \
    __asm__ volatile ("BEQ   1f\n");                              \
    __asm__ volatile ("BL    fault_detect_handling\n");           \
    __asm__ volatile (".word 0xde00de00\n");                      \
    __asm__ volatile ("1:\n");                                    \
}while(false)

#endif /* __GNUC__ Compiler*/
#endif /* HARDENING_MACROS_ENABLED */

/**
 * \brief Store the addresses of memory regions
 */
struct memory_region_limits {
    uint32_t non_secure_code_start;
    uint32_t non_secure_partition_base;
    uint32_t non_secure_partition_limit;
    uint32_t veneer_base;
    uint32_t veneer_limit;
#ifdef TFM_WIFI_FLASH_REGION
    uint32_t wifi_flash_region_base;
    uint32_t wifi_flash_region_limit;
#endif /* TFM_WIFI_FLASH_REGION */
#ifdef TFM_EL2GO_DATA_IMPORT_REGION
    uint32_t el2go_data_import_region_base;
    uint32_t el2go_data_import_region_limit;
#endif // TFM_EL2GO_DATA_IMPORT_REGION
#ifdef TFM_EL2GO_CMPA_REGION
    uint32_t el2go_cmpa_region_base;
    uint32_t el2go_cmpa_region_limit;
#endif // TFM_EL2GO_CMPA_REGION

#ifdef BL2
    uint32_t secondary_partition_base;
    uint32_t secondary_partition_limit;
#endif /* BL2 */
};

/**
 * \brief Configures the Memory Protection Controller.
 *
 * \return  Returns error code.
 */
int32_t mpc_init_cfg(void);

/**
 * \brief Configures the Peripheral Protection Controller.
 *
 * \return  Returns error code.
 */
int32_t ppc_init_cfg(void);

/**
 * \brief Restict access to peripheral to secure
 */
void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged);

/**
 * \brief Configures SAU and IDAU.
 */
void sau_and_idau_cfg(void);

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
enum tfm_plat_err_t init_debug(void);

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

#ifdef __cplusplus
}
#endif

#endif /* __TARGET_CFG_COMMON_H__ */

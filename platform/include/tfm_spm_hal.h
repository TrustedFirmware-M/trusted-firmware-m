/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SPM_HAL_H__
#define __TFM_SPM_HAL_H__

#include <stdint.h>
#include "tfm_secure_api.h"
#include "spm_api.h"
#if TFM_MULTI_CORE_TOPOLOGY
#include "tfm_multi_core.h"
#endif

/**
 * \brief Holds peripheral specific data fields required to manage the
 *        peripherals isolation
 *
 * This structure has to be defined in the platform directory, and may have
 * different definition for each platform. The structure should contain fields
 * that describe the peripheral for the functions that are prototyped in this
 * file and are responsible for configuring the isolation of the peripherals.
 *
 * Pointers to structures of this type are managed by the SPM, and passed to the
 * necessary function on isolation request. The pointers are also defined by the
 * platform in the header file tfm_peripherals_def.h. For details on this, see
 * the documentation of that file.
 */
struct tfm_spm_partition_platform_data_t;

#if defined (TFM_PSA_API) || (TFM_LVL != 1)
/**
 * \brief Holds SPM db fields that define the memory regions used by a
 *        partition.
 */
struct tfm_spm_partition_memory_data_t
{
    uint32_t code_start;   /*!< Start of the code memory of this partition. */
    uint32_t code_limit;   /*!< Address of the byte beyond the end of the code
                            *   memory of this partition.
                            */
    uint32_t ro_start;     /*!< Start of the read only memory of this
                            *   partition.
                            */
    uint32_t ro_limit;     /*!< Address of the byte beyond the end of the read
                            *   only memory of this partition.
                            */
    uint32_t rw_start;     /*!< Start of the data region of this partition. */
    uint32_t rw_limit;     /*!< Address of the byte beyond the end of the data
                            *   region of this partition.
                            */
    uint32_t zi_start;     /*!< Start of the zero initialised data region of
                            *   this partition.
                            */
    uint32_t zi_limit;     /*!< Address of the byte beyond the end of the zero
                            *   initialised region of this partition.
                            */
    uint32_t stack_bottom; /*!< The bottom of the stack for the partition. */
    uint32_t stack_top;    /*!< The top of the stack for the partition. */
};
#endif

/**
 * \brief This function initialises the HW used for isolation, and sets the
 *        default configuration for them.
 *
 * This function is called during TF-M core early startup, before DB init
 */
void tfm_spm_hal_init_isolation_hw(void);

/**
 * \brief This function initialises the HW used for isolation, and sets the
 *        default configuration for them.
 * This function is called during TF-M core early startup, after DB init
 */
void tfm_spm_hal_setup_isolation_hw(void);

/**
 * \brief Configure peripherals for a partition based on the platfotm data from
 *        the DB
 *
 * This function is called during partition initialisation (before calling the
 * init function for the partition)
 *
 * \param[in] platform_data    The platform fields of the partition DB record to
 *                             be used for configuration. Can be NULL.
 */
void tfm_spm_hal_configure_default_isolation(
                 const struct tfm_spm_partition_platform_data_t *platform_data);
/**
 * \brief Configures the system debug properties.
 *        The default configuration of this function should disable secure debug
 *        when either DAUTH_NONE or DAUTH_NS_ONLY define is set. It is up to the
 *        platform owner to decide if secure debug can be turned on in their
 *        system, if DAUTH_FULL define is present.
 *        The DAUTH_CHIP_DEFAULT define should not be considered a safe default
 *        option unless explicitly noted by the chip vendor.
 *        The implementation has to expect that one of those defines is going to
 *        be set. Otherwise, a compile error needs to be triggered.
 */
void tfm_spm_hal_init_debug(void);

/**
 * \brief Enables the fault handlers and sets priorities.
 *
 * Secure fault (if present) must have the highest possible priority
 */
void enable_fault_handlers(void);

/**
 * \brief Configures the system reset request properties
 */
void system_reset_cfg(void);

/**
 * \brief Configures all external interrupts to target the
 *        NS state, apart for the ones associated to secure
 *        peripherals (plus MPC and PPC)
 */
void nvic_interrupt_target_state_cfg(void);

/**
 * \brief This function enable the interrupts associated
 *        to the secure peripherals (plus the isolation boundary violation
 *        interrupts)
 */
void nvic_interrupt_enable(void);

/**
 * \brief Get the VTOR value of non-secure image
 *
 * \return Returns the address where the vector table of the non-secure image
 *         is located
 */
uint32_t tfm_spm_hal_get_ns_VTOR(void);

/**
 * \brief Get the initial address of non-secure image main stack
 *
 * \return Returns the initial non-secure MSP
 */
uint32_t tfm_spm_hal_get_ns_MSP(void);

/**
 * \brief Get the entry point of the non-secure image
 *
 * \return Returns the address of the non-secure image entry point
 */
uint32_t tfm_spm_hal_get_ns_entry_point(void);

/**
 * \brief Set the priority of a secure IRQ
 *
 * \param[in] irq_line    The IRQ to set the priority for. Might be less than 0
 * \param[in] priority    The priority to set. [0..255]
 *
 * \details This function sets the priority for the IRQ passed in the parameter.
 *          The precision of the priority value might be adjusted to match the
 *          available priority bits in the underlying target platform.
 */
void tfm_spm_hal_set_secure_irq_priority(int32_t irq_line, uint32_t priority);

#if TFM_MULTI_CORE_TOPOLOGY
/**
 * \brief Performs the necessary actions to start the non-secure CPU running
 *        the code at the specified address.
 */
void tfm_spm_hal_boot_ns_cpu(uintptr_t start_addr);

/**
 * \brief Called on the secure CPU.
 *        Flags that the secure CPU has completed its initialization
 *        Waits, if necessary, for the non-secure CPU to flag that
 *        it has completed its initialisation
 */
void tfm_spm_hal_wait_for_ns_cpu_ready(void);

/**
 * \brief Retrieve the current active security configuration information and
 *        fills the \ref security_attr_info_t.
 *
 * \param[in]  p               Base address of target memory region
 * \param[in]  s               Size of target memory region
 * \param[out] p_attr          Address of \ref security_attr_info_t to be filled
 *
 * \return void
 */
void tfm_spm_hal_get_mem_security_attr(const void *p, size_t s,
                                       struct security_attr_info_t *p_attr);

/**
 * \brief Retrieve the secure memory protection configuration information and
 *        fills the \ref mem_attr_info_t.
 *
 * \param[in]  p               Base address of target memory region
 * \param[in]  s               Size of target memory region
 * \param[out] p_attr          Address of \ref mem_attr_info_t to be filled
 *
 * \return void
 */
void tfm_spm_hal_get_secure_access_attr(const void *p, size_t s,
                                        struct mem_attr_info_t *p_attr);

/**
 * \brief Retrieve the non-secure memory protection configuration information
 *        and fills the \ref mem_attr_info_t.
 *
 * \param[in]  p               Base address of target memory region
 * \param[in]  s               Size of target memory region
 * \param[out] p_attr          Address of \ref mem_attr_info_t to be filled
 *
 * \return void
 */
void tfm_spm_hal_get_ns_access_attr(const void *p, size_t s,
                                    struct mem_attr_info_t *p_attr);

#endif /*TFM_MULTI_CORE_TOPOLOGY*/

#if (TFM_LVL != 1) && !defined(TFM_PSA_API)
/**
 * \brief Configure the sandbox for a partition.
 *
 * \param[in] memory_data      The memory ranges from the partition DB for this
 *                             partition
 * \param[in] platform_data    The platform fields of the partition DB record
 *                             for this partition. Can be NULL.
 *
 * \return Returns the result operation as per \ref spm_err_t
 */
enum spm_err_t tfm_spm_hal_partition_sandbox_config(
                 const struct tfm_spm_partition_memory_data_t *memory_data,
                 const struct tfm_spm_partition_platform_data_t *platform_data);

/**
 * \brief Deconfigure the sandbox for a partition.
 *
 * \param[in] memory_data      The memory ranges from the partition DB for this
 *                             partition
 * \param[in] platform_data    The platform fields of the partition DB record
 *                             for this partition. Can be NULL.
 *
 * \return Returns the result operation as per \ref spm_err_t
 */
enum spm_err_t tfm_spm_hal_partition_sandbox_deconfig(
                 const struct tfm_spm_partition_memory_data_t *memory_data,
                 const struct tfm_spm_partition_platform_data_t *platform_data);

/**
 * \brief Set the share region mode
 *
 * \param[in] share      The mode to set
 *
 * \return Returns the result operation as per \ref spm_err_t
 */
enum spm_err_t tfm_spm_hal_set_share_region(
                                          enum tfm_buffer_share_region_e share);
#endif

#endif /* __TFM_SPM_HAL_H__ */

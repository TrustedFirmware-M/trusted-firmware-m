/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_TYPES_H
#define PROTECTION_TYPES_H

#include "config_tfm.h"
#include "fih.h"
#include "ifx_fih.h"
#include "ifx_spe_config.h"
#include "ifx_platform_spe_types.h"

#if IFX_PLATFORM_MPC_PRESENT
#if IFX_MPC_DRIVER_HW_MPC_V1 || IFX_MPC_DRIVER_HW_MPC_V2
#include "protection_mpc_hw_mpc.h"
#elif IFX_MPC_DRIVER_SW_POLICY
#include "protection_mpc_sw_policy.h"
#endif
#endif /* IFX_PLATFORM_MPC_PRESENT */

#if IFX_PLATFORM_PPC_PRESENT
#if defined(IFX_PPC_DRIVER_V1)
#include "protection_ppc_v1.h"
#elif defined(IFX_PPC_DRIVER_V2)
#include "protection_ppc_v2.h"
#else
#error "Unsupported PPC driver"
#endif /* IFX_PPC_DRIVER_V1 */
#endif /* IFX_PLATFORM_PPC_PRESENT */

#define IFX_IS_PARTITION_PRIVILEGED(p_info) (IFX_FIH_EQ((p_info)->ifx_ldinfo->privileged, \
                                                        IFX_FIH_TRUE))

#define IFX_SPM_BOUNDARY                        ((uintptr_t)0U)

/* SPM domain used to implement \brief tfm_hal_boundary_need_switch */
#define IFX_PROTECT_SPM_DOMAIN                  ((uintptr_t)0xC273706DU)

/* Single PRoT domain used to implement \brief tfm_hal_boundary_need_switch */
#define IFX_PROTECT_PSA_ROT_SINGLE_DOMAIN       ((uintptr_t)0xA5505341U)

/* Single ARoT domain used to implement \brief tfm_hal_boundary_need_switch */
#define IFX_PROTECT_APP_ROT_SINGLE_DOMAIN       ((uintptr_t)0xB6616050U)

/* Helper function for IFX_PROTECT_IS_PRIVILEGED_DOMAIN to remove braces */
#define IFX_PROTECT_IS_PRIVILEGED_DOMAIN_PRIVATE(privileged, ...) \
    ((privileged) != 0)

/*
 * Return whether domain is privileged
 *
 * \param[in] domain      Security domain settings in format (privileged, optional PC if supported)
 */
#define IFX_PROTECT_IS_PRIVILEGED_DOMAIN(domain) \
    IFX_PROTECT_IS_PRIVILEGED_DOMAIN_PRIVATE domain

#if IFX_ISOLATION_PC_SWITCHING
/* SPM domain settings */
#define IFX_PROTECT_SPM_DOMAIN_CFG              (1, IFX_PC_TFM_SPM_ID)

/* PRoT domain settings */
#define IFX_PROTECT_PSA_ROT_DOMAIN_CFG          (IFX_PSA_ROT_PRIVILEGED, IFX_PC_TFM_PROT_ID)

/* ARoT domain settings */
#define IFX_PROTECT_APP_ROT_DOMAIN_CFG          (IFX_APP_ROT_PRIVILEGED, IFX_PC_TFM_AROT_ID)

#ifdef TFM_PARTITION_NS_AGENT_TZ
/* NS Agent TZ domain settings */
#define IFX_PROTECT_NS_AGENT_TZ_DOMAIN_CFG      (IFX_NS_AGENT_TZ_PRIVILEGED, IFX_PC_TZ_NSPE_ID)
#endif

/* Helper function for IFX_PROTECT_GET_DOMAIN_PC to remove braces */
#define __IFX_PROTECT_GET_DOMAIN_PC(privileged, pc) \
    (pc)

/*
 * Return domain Protection Context
 *
 * \param[in] domain        Security domain settings in format (privileged, protection context)
 */
#define IFX_PROTECT_GET_DOMAIN_PC(domain) \
        __IFX_PROTECT_GET_DOMAIN_PC domain

/*
 * Return whether two domains have equal settings
 *
 * \param[in] domain1       Security domain settings in format (privileged, protection context)
 * \param[in] domain2       Security domain settings in format (privileged, protection context)
 */
#define IFX_PROTECT_IS_DOMAIN_EQUAL(domain1, domain2) \
    ((IFX_PROTECT_IS_PRIVILEGED_DOMAIN(domain1) == IFX_PROTECT_IS_PRIVILEGED_DOMAIN(domain2)) && \
     (IFX_PROTECT_GET_DOMAIN_PC(domain1) == IFX_PROTECT_GET_DOMAIN_PC(domain2)))

#else /* IFX_ISOLATION_PC_SWITCHING */

/* SPM domain settings - privileged */
#define IFX_PROTECT_SPM_DOMAIN_CFG              (1)

/* PRoT domain settings */
#define IFX_PROTECT_PSA_ROT_DOMAIN_CFG          (IFX_PSA_ROT_PRIVILEGED)

/* ARoT domain settings - IFX_APP_ROT_PRIVILEGED */
#define IFX_PROTECT_APP_ROT_DOMAIN_CFG          (IFX_APP_ROT_PRIVILEGED)

#ifdef TFM_PARTITION_NS_AGENT_TZ
/* NS Agent TZ domain settings - IFX_NS_AGENT_TZ_PRIVILEGED */
#define IFX_PROTECT_NS_AGENT_TZ_DOMAIN_CFG      (IFX_NS_AGENT_TZ_PRIVILEGED)
#endif

/*
 * Return whether two domains have equal settings
 *
 * \param[in] domain1       Security domain settings in format (privileged)
 * \param[in] domain2       Security domain settings in format (privileged)
 */
#define IFX_PROTECT_IS_DOMAIN_EQUAL(domain1, domain2) \
    (IFX_PROTECT_IS_PRIVILEGED_DOMAIN(domain1) == IFX_PROTECT_IS_PRIVILEGED_DOMAIN(domain2))
#endif /* IFX_ISOLATION_PC_SWITCHING */

/**
 * \brief Return partition's Protection Context using partition load info
 *
 * \param[in] p_info        Pointer to partition load info \ref ifx_partition_info_t
 * \param[in] secure        Boolean value, true for secure access
 */
#if IFX_ISOLATION_PC_SWITCHING
#define IFX_GET_PARTITION_PC(p_info, secure) \
        ((IS_NS_AGENT(p_info->p_ldinfo) && !(secure)) ? \
        p_info->ifx_ldinfo->non_secure_pc : p_info->ifx_ldinfo->secure_pc)
#else
#define IFX_GET_PARTITION_PC(p_info, secure) \
        fih_int_encode(IFX_PC_TFM_SPM_ID)
#endif

/* Return boundary security domain */
#define IFX_GET_BOUNDARY_DOMAIN(boundary) (((boundary) == IFX_SPM_BOUNDARY) \
                                           ? IFX_PROTECT_SPM_DOMAIN \
                                           : (((const ifx_partition_info_t *)boundary)->ifx_domain))

/* \brief PPC regions configuration generated by platform and Edge Protect Configurator */
typedef struct ifx_ppc_regions_config_t {
    /*! \brief Pointer to the array of regions for the domain */
    const cy_en_prot_region_t*  regions;
    /*! \brief Number of items in \ref regions */
    uint32_t                    region_count;
} ifx_ppc_regions_config_t;

/**
 * \brief Structure used to store platform specific protection properties.
 */
typedef struct {
#if IFX_PLATFORM_PPC_PRESENT
    ifx_ppc_named_mmio_config_t       ppc_cfg;
#endif
#if IFX_MPC_CONFIGURED_BY_TFM
    ifx_mpc_numbered_mmio_config_t    mpc_cfg;
#endif
    IFX_FIH_BOOL                      mpu_regions_enable;
#if TFM_ISOLATION_LEVEL == 3
#if IFX_MPC_CONFIGURED_BY_TFM
    /* Whether to dynamically configure MPC on L3 isolation */
    bool                              mpc_dynamic;
#endif /* IFX_MPC_CONFIGURED_BY_TFM */
#if IFX_PLATFORM_PPC_PRESENT
    /* Whether to dynamically configure PPC on L3 isolation */
    bool                              ppc_dynamic;
#endif /* IFX_PLATFORM_PPC_PRESENT */
#endif /* TFM_ISOLATION_LEVEL == 3 */
} ifx_protection_region_config_t;

/**
 * \brief Structure used to store platform specific partition properties.
 */
typedef struct {
    /*! \brief Is partition privileged */
    IFX_FIH_BOOL privileged;
#if IFX_ISOLATION_PC_SWITCHING
    /*! \brief Protection Context used to enter secure state.
     * \note Set to \ref FIH_INVALID_VALUE to disable secure state. */
    fih_int secure_pc;
    /*! \brief Protection Context used to enter non-secure state.
     * \note Set to \ref FIH_INVALID_VALUE to disable non-secure state. */
    fih_int non_secure_pc;
#endif
    /*! \brief Partition configuration applied by \ref tfm_hal_bind_boundary or
     * by \ref tfm_hal_activate_boundary when partition is enabled */
    const ifx_protection_region_config_t *protect_cfg_enabled;
#if TFM_ISOLATION_LEVEL == 3
    /*! \brief Partition configuration applied by \ref tfm_hal_bind_boundary or
     * by \ref tfm_hal_activate_boundary when partition is disabled */
    const ifx_protection_region_config_t *protect_cfg_disabled;
#endif /* TFM_ISOLATION_LEVEL == 3 */
} ifx_partition_load_info_t;

/**
 * \brief Structure describing partition info.
 *
 * Pointer to this structure is used to provide boundary for isolation HAL.
 */
typedef struct ifx_partition_info_t {
    /* \brief Pointer to partition load info generated by TF-M */
    const struct partition_load_info_t *p_ldinfo;
    /* \brief Pointer to IFX platform specific partition properties */
    const ifx_partition_load_info_t *ifx_ldinfo;
    /* \brief Security domain used to implement \ref tfm_hal_boundary_need_switch */
    uintptr_t ifx_domain;
    /*! \brief Platform specific assets which can't be added to manifest */
    const struct asset_desc_t *p_assets;
    /*! \brief Number of items in \ref p_assets */
    uint32_t asset_cnt;
#ifdef IFX_MEMORY_CONFIGURATOR_MPC_CONFIG
    /* \brief MPC domain settings provided by Device Configurator */
    const ifx_mem_domain_cfg_t *p_mem_cfg;
#endif /* IFX_MEMORY_CONFIGURATOR_MPC_CONFIG */
    /*! \brief Partition peripheral assets added by platform or Edge Protect Configurator */
    const ifx_ppc_regions_config_t *p_peri_regions;
    /*! \brief Number of items in \ref p_peri_regions */
    uint32_t peri_region_count;
} ifx_partition_info_t;

#if TFM_ISOLATION_LEVEL == 3
/**
 * \brief Enumeration used to define asset protection phase
 *
 * It's used to implement protection of service`s assets that can't be protected dynamically.
 * Platforms that has no direct access to RRAM MPC controller uses this feature to
 * setup protection of RRAM memory region via SE RT Services.
 */
typedef enum {
    /*! \brief Used for resources that are statically protected during initial phase */
    IFX_ASSET_PROTECTION_STATIC,
    /*! \brief Static protection used for partition's asset with dynamic isolation */
    IFX_ASSET_PROTECTION_PARTITION_STATIC,
    /*! \brief Dynamic protection used for partition's asset with dynamic isolation */
    IFX_ASSET_PROTECTION_PARTITION_DYNAMIC,
} ifx_asset_protection_type_t;

/*
 * HAL isolation notifies isolation drivers (MPU, MPC, PPC, ...) through this variable
 * about different stages of assets protection on Level 3 isolation (dynamic).
 */
extern ifx_asset_protection_type_t ifx_asset_protection_type;
#endif /* TFM_ISOLATION_LEVEL == 3 */

#endif /* PROTECTION_TYPES_H */

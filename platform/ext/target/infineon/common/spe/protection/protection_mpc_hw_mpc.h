/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file protection_mpc_hw_mpc.h
 * \brief This file contains types/API used by HW MPC driver, see cy_mpc.h in PDL.
 *
 * \note Don't include this file directly, include protection_types.h instead !!!
 * It's expected that this file is included by protection_types.h if platform is configured
 * to use HW MPC driver via IFX_MPC_DRIVER_HW_MPC_V1 or IFX_MPC_DRIVER_HW_MPC_V2 option.
 */

#ifndef PROTECTION_MPC_HW_MPC_H
#define PROTECTION_MPC_HW_MPC_H

#include <stdint.h>
#include "config_impl.h"
#include "config_tfm.h"
#include "cy_mpc.h"
#include "fih.h"

#include "ifx_platform_spe_types.h"
#include "ifx_spe_config.h"

typedef struct {
    ifx_pc_mask_t   pc_mask; /**< Mask that define what PCs must be modified.
                              *   1 - must be applied new value,
                              *   0 - must be left old value no matter what it was */
    ifx_pc_mask_t   ns_mask; /**< NS bit mask for each PC*/
} ifx_mpc_numbered_mmio_config_t;

typedef struct {
    uint32_t             address;
    uint32_t             size;
    ifx_pc_mask_t        ns_mask; /**< NS bit mask for each PC*/
    ifx_pc_mask_t        r_mask;  /**< R  bit mask for each PC*/
    ifx_pc_mask_t        w_mask;  /**< W  bit mask for each PC*/
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    bool                 is_rot;  /**< True if this MPC region is for ROT, false otherwise */
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */
} ifx_mpc_region_config_t;

/**
 * @brief Configuration structure for MPC raw region.
 */
typedef struct {
    MPC_Type*            mpc_base; /**< Base address of the MPC controller */
    cy_en_mpc_size_t     mpc_block_size; /**< Size of the MPC block */
    uint32_t             offset;
    uint32_t             size;
    ifx_pc_mask_t        ns_mask; /**< NS bit mask for each PC*/
    ifx_pc_mask_t        r_mask;  /**< R  bit mask for each PC*/
    ifx_pc_mask_t        w_mask;  /**< W  bit mask for each PC*/
#if IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT
    bool                 is_rot;  /**< True if this MPC region is for ROT, false otherwise */
#endif /* IFX_MPC_DRIVER_HW_MPC_WITH_ROT && IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT */
} ifx_mpc_raw_region_config_t;

/* SPM protection configuration for \ref ifx_mpc_numbered_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_SPM_ROT_CFG \
    .mpc_cfg = { \
        .pc_mask        = IFX_PC_DEFAULT, \
        .ns_mask        = IFX_PC_NONE, \
    },

/* PSA RoT partition protection configuration for \ref ifx_mpc_numbered_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_PSA_ROT_CFG \
    .mpc_cfg = { \
        .pc_mask        = IFX_PC_DEFAULT | IFX_PC_TFM_PROT, \
        .ns_mask        = IFX_PC_NONE, \
    },

#if TFM_ISOLATION_LEVEL == 2
/* App RoT partition protection configuration for \ref ifx_mpc_numbered_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_APP_ROT_CFG \
    .mpc_cfg = { \
        /* In L2 PRoT should be able to access ARoT so IFX_PC_TFM_PROT is added */ \
        .pc_mask        = IFX_PC_DEFAULT | IFX_PC_TFM_PROT | IFX_PC_TFM_AROT, \
        .ns_mask        = IFX_PC_NONE, \
    },
#else
/* App RoT partition protection configuration for \ref ifx_mpc_numbered_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_APP_ROT_CFG \
    .mpc_cfg = { \
        .pc_mask        = IFX_PC_DEFAULT | IFX_PC_TFM_AROT, \
        .ns_mask        = IFX_PC_NONE, \
    },
#endif /* TFM_ISOLATION_LEVEL == 2 */

#ifdef TFM_PARTITION_NS_AGENT_TZ
/* NS Agent TZ partition protection configuration for \ref ifx_mpc_numbered_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_NS_AGENT_TZ_CFG \
    .mpc_cfg = { \
        .pc_mask        = IFX_PC_DEFAULT | IFX_PC_TZ_NSPE, \
        .ns_mask        = IFX_PC_NONE, \
    },
#endif /* TFM_PARTITION_NS_AGENT_TZ */

#if TFM_ISOLATION_LEVEL == 3
/* Suspended partition configuration for L3 isolation for \ref ifx_mpc_named_mmio_config_t */
#define IFX_MPC_NAMED_MMIO_L3_DISABLED_CFG \
    .mpc_cfg = { \
        .pc_mask        = IFX_PC_DEFAULT, \
        .ns_mask        = IFX_PC_NONE, \
    },
#endif

#define IFX_MAX_FIXED_CONFIGS 5U

/* Additional configs that are internal to TFM.
 * The sizes can't be determined by the compiler as constants.
 * This array is populated by ifx_mpc_fill_fixed_config().
 */
extern ifx_mpc_region_config_t ifx_fixed_mpc_static_config[IFX_MAX_FIXED_CONFIGS];

/* The number of used entries in \ref ifx_fixed_mpc_static_config */
extern uint32_t ifx_fixed_mpc_static_config_count;

/**
 * \brief Populate the internal static MPC configuration array.
 *
 * This function fills the ifx_fixed_mpc_static_config array with additional
 * MPC region configurations that are internal to TF-M and cannot be determined
 * by the compiler as constants. It also sets the ifx_fixed_mpc_static_config_count
 * to the number of valid entries. The function may call tfm_core_panic() if the
 * number of configurations exceeds IFX_MAX_FIXED_CONFIGS.
 *
 * \note The actual regions and permissions depend on build-time configuration
 *       and linker symbols.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_fill_fixed_config(void);

/**
 * \brief Apply MPC configuration.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_region_config_t for more details.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - configuration can not be applied.
 *                                          Can occur when MPC that should
 *                                          protect the memory is not controlled
 *                                          by TFM.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input (e.g. provided memory
 *                                          region is not fully located in any
 *                                          known memory).
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_apply_configuration(
                                            const ifx_mpc_region_config_t* mpc_reg_cfg);

/**
 * \brief Apply MPC configuration using raw interface.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_raw_region_config_t for more details.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - configuration can not be applied.
 *                                          Can occur when MPC that should
 *                                          protect the memory is not controlled
 *                                          by TFM.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 *            TFM_HAL_ERROR_INVALID_INPUT - invalid input (e.g. provided memory
 *                                          region is not fully located in any
 *                                          known memory).
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_apply_raw_configuration(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg);

/**
 * \brief Apply MPC configuration for MPC controller handled by TF-M.
 *
 * \param[in] mpc_reg_cfg   MPC configuration structure which will be applied.
 *                          See \ref ifx_mpc_raw_region_config_t for more details.
 *
 * \return    TFM_HAL_SUCCESS             - MPC configuration applied successfully.
 *            TFM_HAL_ERROR_GENERIC       - failed to apply MPC configuration.
 */
enum tfm_hal_status_t ifx_mpc_apply_configuration_with_mpc(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg);

#ifdef TFM_FIH_PROFILE_ON
/**
 * \brief Verify the MPC configuration for a region.
 *
 * This function checks that the MPC configuration for the specified region matches
 * the expected values. It verifies all memory regions covered by the configuration.
 *
 * \param[in] mpc_reg_cfg   Pointer to the MPC region configuration structure to verify.
 *
 * \return    TFM_HAL_SUCCESS         - Configuration matches expected values.
 *            TFM_HAL_ERROR_GENERIC   - Configuration does not match or invalid input.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_configuration(
                                            const ifx_mpc_region_config_t* mpc_reg_cfg);

/**
 * \brief Verify the MPC configuration for a raw region.
 *
 * This function checks that the MPC configuration for the specified raw region matches
 * the expected values. For external MPCs, it uses an external service to verify protection.
 * For internal MPCs, it reads the MPC directly and compares the configuration.
 *
 * \param[in] mpc_reg_cfg   Pointer to the MPC raw region configuration structure to verify.
 *
 * \return    TFM_HAL_SUCCESS         - Configuration matches expected values.
 *            TFM_HAL_ERROR_GENERIC   - Configuration does not match or invalid input.
 *            TFM_HAL_ERROR_NOT_SUPPORTED - Verification not supported for this MPC.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_raw_configuration(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg);

/**
 * \brief Verify the MPC configuration for a raw region using direct MPC access.
 *
 * This function checks that the MPC configuration for the specified raw region matches
 * the expected values by reading the MPC hardware directly. It verifies all blocks and
 * protection contexts covered by the configuration.
 *
 * \param[in] mpc_reg_cfg   Pointer to the MPC raw region configuration structure to verify.
 *
 * \return    TFM_HAL_SUCCESS         - Configuration matches expected values.
 *            TFM_HAL_ERROR_GENERIC   - Configuration does not match or invalid input.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_mpc_verify_configuration_with_mpc(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg);
#endif /* TFM_FIH_PROFILE_ON */

/**
 * \brief Get the security attribute for a given protection context (PC).
 *
 * This function determines whether the specified PC should be configured as secure or non-secure
 * based on the MPC configuration structure.
 *
 * \param[in] mpc_reg_cfg   Pointer to the MPC raw region configuration structure.
 * \param[in] pc            Protection context to query.
 *
 * \return    CY_MPC_SECURE     - The PC is configured as secure.
 *            CY_MPC_NON_SECURE - The PC is configured as non-secure.
 */
static inline cy_en_mpc_sec_attr_t ifx_mpc_secure_cfg(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg,
                                            cy_en_mpc_prot_context_t pc)
{
    cy_en_mpc_sec_attr_t ret = CY_MPC_SECURE;

    if (IFX_GET_PC(mpc_reg_cfg->ns_mask, pc) != 0U) {
        ret = CY_MPC_NON_SECURE;
    } else {
        ret = CY_MPC_SECURE;
    }

    return ret;
}

/**
 * \brief Get the access attribute for a given protection context (PC).
 *
 * This function determines the access permissions (read, write, read/write, or disabled)
 * for the specified PC based on the MPC configuration structure.
 *
 * \param[in] mpc_reg_cfg   Pointer to the MPC raw region configuration structure.
 * \param[in] pc            Protection context to query.
 *
 * \return    CY_MPC_ACCESS_RW       - Read and write access allowed.
 *            CY_MPC_ACCESS_R        - Read access allowed.
 *            CY_MPC_ACCESS_W        - Write access allowed.
 *            CY_MPC_ACCESS_DISABLED - No access allowed.
 */
static inline cy_en_mpc_access_attr_t ifx_mpc_access_cfg(
                                            const ifx_mpc_raw_region_config_t* mpc_reg_cfg,
                                            cy_en_mpc_prot_context_t pc)
{
    cy_en_mpc_access_attr_t ret = CY_MPC_ACCESS_DISABLED;

    uint8_t r_mask = IFX_GET_PC(mpc_reg_cfg->r_mask, pc);
    uint8_t w_mask = IFX_GET_PC(mpc_reg_cfg->w_mask, pc);

    if ((r_mask != 0U) && (w_mask != 0U)) {
        ret = CY_MPC_ACCESS_RW;
    } else if (r_mask != 0U) {
        ret = CY_MPC_ACCESS_R;
    } else if (w_mask != 0U) {
        ret = CY_MPC_ACCESS_W;
    } else {
        ret = CY_MPC_ACCESS_DISABLED;
    }

    return ret;
}

#endif /* PROTECTION_MPC_HW_MPC_H */

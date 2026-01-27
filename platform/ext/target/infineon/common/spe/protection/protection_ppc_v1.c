/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cy_ppc.h"
#include "ifx_tfm_log_shim.h"
#include "utilities.h"
#include "protection_types.h"
#include "protection_regions_cfg.h"
#include "protection_ppc_api.h"
#include "coverity_check.h"

/* IMPROVEMENT: move Cy_Ppc_GetPcMask(), Cy_Ppc_GetAttrib() and Function Description to PDL (DRIVERS-10521)*/

/*******************************************************************************
* Function Name: Cy_Ppc_GetPcMask
********************************************************************************
*
* \brief Get the PC mask for a regions of referenced PPC
*
* \param base
* Base address of PPC being configured
*
* \param region
* region in space of \ref cy_en_prot_region_t
*
* \return
* Actual value of pcMask from PPC registers
*
*******************************************************************************/
static uint32_t Cy_Ppc_GetPcMask(const PPC_Type* base, cy_en_prot_region_t region)
{
    return base->PC_MASK[CY_PPC_DRV_REGION_EXTRACT(region)];
}

/*******************************************************************************
* Function Name: Cy_Ppc_GetPointerForRegion
********************************************************************************
*
* \brief Get a pointer to the PPC_Type structure for a given PPC region.
*
* This function returns a pointer to the PPC_Type structure associated with the
* specified PPC region. If the provided PPC region is invalid, the function
* triggers a tfm_core_panic().
*
* \param ppc_region
* PPC region as defined in \ref cy_en_prot_region_t
*
* \return
* A pointer to the PPC_Type structure for the given PPC region.
* In case of an invalid PPC region, the function will not return and will
* trigger a tfm_core_panic().
*
*******************************************************************************/
static PPC_Type* Cy_Ppc_GetPointerForRegion(cy_en_prot_region_t ppc_region)
{
    TFM_COVERITY_DEVIATE_BLOCK(constant_expression_result, "index_ppc can be more than 0")
    size_t index_ppc = CY_PPC_DRV_BLOCK_EXTRACT(ppc_region);
    if (index_ppc < ifx_ppcx_region_ptrs_count) {
        return ifx_ppcx_region_ptrs[index_ppc];
    }
    TFM_COVERITY_BLOCK_END(constant_expression_result)

    tfm_core_panic();
}

/*******************************************************************************
* Function Name: Cy_Ppc_GetAttrib
********************************************************************************
*
* \brief Get the PPC security attributes for a region of referenced PPC
*
* \param base
* Base address of PPC being configured
*
* \param region
* region in space of \ref cy_en_prot_region_t
*
* \param p_attribute
* ptr to return attribute values \ref cy_stc_ppc_attribute_t
*
* \return* TFM_HAL_SUCCESS       - Attribute retrieved successfully
*          TFM_HAL_ERROR_GENERIC - Failed to retrieve Attribute
*
*******************************************************************************/
static enum tfm_hal_status_t Cy_Ppc_GetAttrib(const PPC_Type* base,
                                              cy_en_prot_region_t ppc_region,
                                              cy_stc_ppc_attribute_t* p_attribute)
{
    uint32_t            sBit;
    uint32_t            blkIdx;

    if (p_attribute == NULL) {
        return TFM_HAL_ERROR_GENERIC;
    }

    sBit   = ((uint32_t)CY_PPC_DRV_REGION_EXTRACT(ppc_region)) % 32U;
    blkIdx = ((uint32_t)CY_PPC_DRV_REGION_EXTRACT(ppc_region)) / 32U;

    p_attribute->startRegion       = ppc_region;
    p_attribute->endRegion         = ppc_region;
    p_attribute->secAttribute      = ((base->NS_ATT[blkIdx]   & (1UL << sBit)) != 0U) ? CY_PPC_NON_SECURE     : CY_PPC_SECURE;
    p_attribute->secPrivAttribute  = ((base->S_P_ATT[blkIdx]  & (1UL << sBit)) !=0U) ? CY_PPC_SEC_NONPRIV     : CY_PPC_SEC_PRIV;
    p_attribute->nsPrivAttribute   = ((base->NS_P_ATT[blkIdx] & (1UL << sBit)) !=0U) ? CY_PPC_NON_SEC_NONPRIV : CY_PPC_NON_SEC_PRIV;

    return TFM_HAL_SUCCESS;
}

/* Check whether the specified config is one that can be set. Panic if not */
static void ifx_check_config_validity(const PPC_Type               *ppc_ptr,
                                      const cy_stc_ppc_attribute_t *ppc_attribute,
                                      const cy_stc_ppc_pc_mask_t   *ppc_pcmask)
{
    /* IMPROVEMENT: Remove the typecast once DRIVERS-23320 is fixed */
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_8, "Typecast is needed due to DRIVERS-23320")
    uint32_t lock_mask = Cy_Ppc_GetLockMask((PPC_Type *)ppc_ptr);
    uint32_t pc_mask = Cy_Ppc_GetPcMask(ppc_ptr, ppc_attribute->startRegion);
    cy_stc_ppc_attribute_t attr = {
        .secAttribute = CY_PPC_SECURE,
        .secPrivAttribute = CY_PPC_SEC_PRIV,
        .nsPrivAttribute = CY_PPC_NON_SEC_PRIV,
    };
    enum tfm_hal_status_t ret = Cy_Ppc_GetAttrib(ppc_ptr, ppc_attribute->startRegion, &attr);

    if (ret != TFM_HAL_SUCCESS) {
        tfm_core_panic();
    }

    /* If a locked PC has access to a region, secAttribute and secPrivAttribute cannot be changed */
    if (pc_mask & lock_mask) {
        if (attr.secAttribute != ppc_attribute->secAttribute) {
            ERROR_RAW("PPC config cannot be set (secAttribute when locked PC has access) for region 0x%08x\n",
                      (uint32_t)ppc_attribute->startRegion);
            ERROR_RAW("pc_mask 0x%08x\n", pc_mask);
            ERROR_RAW("lock_mask 0x%08x\n", lock_mask);
            ERROR_RAW("current secAttribute 0x%08x\n", (uint32_t)attr.secAttribute);
            tfm_core_panic();
        }
        if (attr.secPrivAttribute != ppc_attribute->secPrivAttribute) {
            ERROR_RAW("PPC config cannot be set (secPrivAttribute when locked PC has access) for region 0x%08x\n",
                      (uint32_t)ppc_attribute->startRegion);
            ERROR_RAW("pc_mask 0x%08x\n", pc_mask);
            ERROR_RAW("lock_mask 0x%08x\n", lock_mask);
            ERROR_RAW("current secPrivAttribute 0x%08x\n", (uint32_t)attr.secPrivAttribute);
            tfm_core_panic();
        }
    }

    /* PC mask can't be changed for a locked PC */
    if ((pc_mask ^ ppc_pcmask->pcMask) & lock_mask) {
        ERROR_RAW("PPC config cannot be set (PC mask for locked PC) for region 0x%08x\n",
                  (uint32_t)ppc_attribute->startRegion);
        ERROR_RAW("pc_mask 0x%08x\n", pc_mask);
        ERROR_RAW("lock_mask 0x%08x\n", lock_mask);
        tfm_core_panic();
    }

    /* If any PC with access is locked, we can't set new PC bits */
    if (((pc_mask & lock_mask) != 0U) && (((pc_mask ^ ppc_pcmask->pcMask) & ppc_pcmask->pcMask) != 0U)) {
        ERROR_RAW("PPC config cannot be set (grant access when locked PC has access) for region 0x%08x\n",
                  (uint32_t)ppc_attribute->startRegion);
        ERROR_RAW("pc_mask 0x%08x\n", pc_mask);
        ERROR_RAW("lock_mask 0x%08x\n", lock_mask);
        tfm_core_panic();
    }
}

static cy_en_ppc_secpriv_attribute_t to_s_priv_attr(bool allow_unpriv,
                                                    cy_en_ppc_sec_attribute_t sec_attr)
{
    cy_en_ppc_secpriv_attribute_t ret = CY_PPC_SEC_PRIV;

    if (allow_unpriv && (sec_attr == CY_PPC_SECURE)) {
        ret = CY_PPC_SEC_NONPRIV;
    }
    return ret;
}

static cy_en_ppc_nspriv_attribute_t to_ns_priv_attr(bool allow_unpriv,
                                                    cy_en_ppc_sec_attribute_t sec_attr)
{
    cy_en_ppc_nspriv_attribute_t ret = CY_PPC_NON_SEC_PRIV;

    if (allow_unpriv && (sec_attr == CY_PPC_NON_SECURE)) {
        ret = CY_PPC_NON_SEC_NONPRIV;
    }
    return ret;
}

/* Init PPC static protection for one PPC controller */
static FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppcx_init_cfg(const ifx_ppcx_config_t* p_config)
{
    cy_en_ppc_status_t      ppc_status;
    cy_stc_ppc_attribute_t  ppc_attribute;
    cy_stc_ppc_pc_mask_t    ppc_pcmask;
    PPC_Type*               ppc_ptr;
    cy_en_prot_region_t     ppc_region;

    for (uint32_t idx = 0UL; idx < p_config->region_count; idx++) {

        ppc_ptr    = Cy_Ppc_GetPointerForRegion(p_config->regions[idx]);
        ppc_region = p_config->regions[idx];

        ppc_attribute.startRegion      = ppc_region;
        ppc_attribute.endRegion        = ppc_region;
        ppc_attribute.secAttribute     = p_config->sec_attr;
        ppc_attribute.secPrivAttribute = to_s_priv_attr(p_config->allow_unpriv,
                                                        p_config->sec_attr);
        ppc_attribute.nsPrivAttribute  = to_ns_priv_attr(p_config->allow_unpriv,
                                                         p_config->sec_attr);

        ppc_pcmask.startRegion         = ppc_region;
        ppc_pcmask.endRegion           = ppc_region;
        ppc_pcmask.pcMask              = p_config->pc_mask;

        ifx_check_config_validity(ppc_ptr, &ppc_attribute, &ppc_pcmask);

        ppc_status = Cy_Ppc_ConfigAttrib(ppc_ptr, &ppc_attribute);
        if (ppc_status != CY_PPC_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }

        ppc_status = Cy_Ppc_SetPcMask(ppc_ptr, &ppc_pcmask);
        if (ppc_status != CY_PPC_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_init_cfg(void)
{
    IFX_FIH_DECLARE(enum tfm_hal_status_t, fih_rc, TFM_HAL_ERROR_GENERIC);

    /*
    * Starts changing actual configuration so issue DMB to ensure every
    * transaction has completed by now
    */
    __DMB();

    const cy_stc_ppc_init_t ppc_init = {.respConfig = CY_PPC_BUS_ERR};
    for (uint32_t idx = 0UL; idx < ifx_ppcx_region_ptrs_count; idx++) {
        /* Initialize PPCs */
        if (Cy_Ppc_InitPpc(ifx_ppcx_region_ptrs[idx], &ppc_init) != CY_PPC_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

    for (uint32_t idx = 0UL; idx < ifx_ppcx_static_config_count; idx++) {
        TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_20_7, "Cannot wrap with parentheses due to Fault injection architecture and define FIH_RET_TYPE")
        FIH_CALL(ifx_ppcx_init_cfg, fih_rc, &ifx_ppcx_static_config[idx]);
        TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_4, "Cannot change types due to Fault injection architecture")
        TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
        if (FIH_NOT_EQ(fih_rc, TFM_HAL_SUCCESS)) {
            FIH_RET(fih_rc);
        }
        TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_4)
    }

    /* Add barriers to assure the PPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_verify_static_boundaries(void)
{
    /*
     * All the code here has a direct 1:1 mapping to the code in
     * ifx_ppc_init_cfg(). This function just verifies that that
     * one did what it was supposed to
     */

    /* all PPCs should be configured to generate a BusError exception */
    for (uint32_t idx = 0UL; idx < ifx_ppcx_region_ptrs_count; idx++) {
        if ((ifx_ppcx_region_ptrs[idx]->CTL & PPC_CTL_RESP_CFG_Msk) == 0U) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

    /* Each region should be configured as in ifx_ppcx_static_config[] */
    for (uint32_t idx = 0UL; idx < ifx_ppcx_static_config_count; idx++) {
        const ifx_ppcx_config_t* p_config = &ifx_ppcx_static_config[idx];

        for (uint32_t i = 0UL; i < p_config->region_count; i++) {
            const PPC_Type * ppc_ptr = Cy_Ppc_GetPointerForRegion(p_config->regions[i]);
            cy_en_prot_region_t ppc_region = p_config->regions[i];
            cy_stc_ppc_attribute_t attr;
            enum tfm_hal_status_t ret = Cy_Ppc_GetAttrib(ppc_ptr, ppc_region, &attr);

            if ((ret != TFM_HAL_SUCCESS) ||
                (attr.secAttribute != p_config->sec_attr) ||
                (attr.secPrivAttribute != to_s_priv_attr(p_config->allow_unpriv,
                                                         p_config->sec_attr)) ||
                (attr.nsPrivAttribute != to_ns_priv_attr(p_config->allow_unpriv,
                                                         p_config->sec_attr))) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }

            if (Cy_Ppc_GetPcMask(ppc_ptr, ppc_region) != p_config->pc_mask) {
                FIH_RET(TFM_HAL_ERROR_GENERIC);
            }
        }
    }

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_ppc_isolate_named_mmio(
                                                 const ifx_ppc_named_mmio_config_t* ppc_cfg,
                                                 cy_en_prot_region_t asset)
{
    PPC_Type* ppc_ptr = Cy_Ppc_GetPointerForRegion(asset);

    /* Set PC mask for PPC region to allow SPM modify attributes */
    cy_stc_ppc_pc_mask_t ppc_pcmask = {
        .startRegion = asset,
        .endRegion   = asset,
        .pcMask      = ppc_cfg->pc_mask | IFX_PC_TFM_SPM,
    };

    cy_stc_ppc_attribute_t ppc_attribute = {
        .startRegion      = asset,
        .endRegion        = asset,
        .secAttribute     = ppc_cfg->sec_attr,
        .secPrivAttribute = to_s_priv_attr(ppc_cfg->allow_unpriv, ppc_cfg->sec_attr),
        .nsPrivAttribute  = to_ns_priv_attr(ppc_cfg->allow_unpriv, ppc_cfg->sec_attr),
    };

    ifx_check_config_validity(ppc_ptr, &ppc_attribute, &ppc_pcmask);

    if (Cy_Ppc_SetPcMask(ppc_ptr, &ppc_pcmask) != CY_PPC_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    };

    (void)fih_delay();

    /* Set PPC attributes */
    if (Cy_Ppc_ConfigAttrib(ppc_ptr, &ppc_attribute) != CY_PPC_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    if ((ppc_cfg->pc_mask & IFX_PC_TFM_SPM) == 0U)
    {
        /* Set PC mask for PPC region according to ppc_cfg */
        ppc_pcmask.startRegion = asset;
        ppc_pcmask.endRegion = asset;
        ppc_pcmask.pcMask = ppc_cfg->pc_mask;
        if (Cy_Ppc_SetPcMask(ppc_ptr, &ppc_pcmask) != CY_PPC_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        };
    }

    FIH_RET(TFM_HAL_SUCCESS);
}

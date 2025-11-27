/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cy_ms_ctl.h"
#include "protection_msc.h"
#include "protection_regions_cfg.h"
#include "utilities.h"

#ifdef TFM_FIH_PROFILE_ON
#if IFX_MSC_ACG_RESP_CONFIG
static void ifx_msc_read_acg_resp(en_ms_ctl_master_sc_acg_t busMaster,
                                  cy_en_ms_ctl_cfg_gate_resp_t *gateResp,
                                  cy_en_ms_ctl_sec_resp_t *secResp)
{
    uint32_t value;
    uint32_t gate_val;
    uint32_t sec_val;

    switch (busMaster) {
    case CODE_MS0_MSC:
        value = MS_CTL_CODE_MS0_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    case SYS_MS0_MSC:
        value = MS_CTL_SYS_MS0_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    case SYS_MS1_MSC:
        value = MS_CTL_SYS_MS1_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    case EXP_MS_MSC:
        value = MS_CTL_EXP_MS_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    case DMAC0_MSC:
        value = MS_CTL_DMAC0_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    case DMAC1_MSC:
        value = MS_CTL_DMAC1_MSC_ACG_CTL_VX;
        gate_val = _FLD2VAL(MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX, value);
        sec_val = _FLD2VAL(MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX, value);
        break;

    default:
        tfm_core_panic();
        break;
    }

    /* Map the values to the enumerals - could just typecast? */
    if (gate_val == 1U) {
        *gateResp = CY_MS_CTL_GATE_RESP_ERR;
    } else {
        *gateResp = CY_MS_CTL_GATE_RESP_WAITED_TRFR;
    }

    if (sec_val == 1U) {
        *secResp = CY_MS_CTL_SEC_RESP_ERR;
    } else {
        *secResp = CY_MS_CTL_SEC_RESP_RAZ_WI;
    }
}
#endif /* IFX_MSC_ACG_RESP_CONFIG */

#if IFX_MSC_ACG_RESP_CONFIG_V1
static void ifx_msc_read_acg_resp_v1(en_ms_ctl_master_sc_acg_v1_t busMaster,
                                     cy_en_ms_ctl_cfg_gate_resp_t *gateResp,
                                     cy_en_ms_ctl_sec_resp_t *secResp)
{
    uint32_t value;
    uint32_t gate_val;
    uint32_t sec_val;

    switch (busMaster) {
    case APP_SYS_MS0_MSC:
        value = MS_CTL_SYS_MS0_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_SYS_MS1_MSC:
        value = MS_CTL_SYS_MS1_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXIDMAC0_MSC:
        value = MS_CTL_AXIDMAC0_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXIDMAC1_MSC:
        value = MS_CTL_AXIDMAC1_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXI_MS0_MSC:
        value = MS_CTL_AXI_MS0_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXI_MS1_MSC:
        value = MS_CTL_AXI_MS1_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXI_MS2_MSC:
        value = MS_CTL_AXI_MS2_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_AXI_MS3_MSC:
        value = MS_CTL_AXI_MS3_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_EXP_MS0_MSC:
        value = MS_CTL_EXP_MS0_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_EXP_MS1_MSC:
        value = MS_CTL_EXP_MS1_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_EXP_MS2_MSC:
        value = MS_CTL_EXP_MS2_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    case APP_EXP_MS3_MSC:
        value = MS_CTL_EXP_MS3_MSC_ACG_CTL_V1;
        gate_val = _FLD2VAL(MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1, value);
        sec_val = _FLD2VAL(MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1, value);
        break;

    default:
        tfm_core_panic();
        break;
    }

    /* Map the values to the enumerals - could just typecast? */
    if (gate_val == 1U) {
        *gateResp = CY_MS_CTL_GATE_RESP_ERR;
    } else {
        *gateResp = CY_MS_CTL_GATE_RESP_WAITED_TRFR;
    }

    if (sec_val == 1U) {
        *secResp = CY_MS_CTL_SEC_RESP_ERR;
    } else {
        *secResp = CY_MS_CTL_SEC_RESP_RAZ_WI;
    }
}
#endif /* IFX_MSC_ACG_RESP_CONFIG_V1 */
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_hal_status_t) ifx_msc_cfg(void)
{
    cy_en_ms_ctl_status_t    ms_ctl_status;

#if IFX_MSC_ACG_RESP_CONFIG
    /* Response configuration for ACG and MSC for the referenced bus master */
    for (uint32_t idx = 0UL; idx < ifx_msc_agc_resp_config_count; idx++) {
        ms_ctl_status = Cy_Ms_Ctl_ConfigMscAcgResp(ifx_msc_agc_resp_config[idx].bus_master,
                                                   ifx_msc_agc_resp_config[idx].gate_resp,
                                                   ifx_msc_agc_resp_config[idx].sec_resp);
        if (ms_ctl_status != CY_MS_CTL_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }
#endif /* IFX_MSC_ACG_RESP_CONFIG */

#if IFX_MSC_ACG_RESP_CONFIG_V1
    /* Response configuration for ACG and MSC for the referenced bus master in CAT1D devices */
    for (uint32_t idx = 0UL; idx < ifx_msc_agc_resp_config_v1_count; idx++) {
        ms_ctl_status = Cy_Ms_Ctl_ConfigMscAcgRespV1(ifx_msc_agc_resp_config_v1[idx].bus_master,
                                                     ifx_msc_agc_resp_config_v1[idx].gate_resp,
                                                     ifx_msc_agc_resp_config_v1[idx].sec_resp);
        if (ms_ctl_status != CY_MS_CTL_SUCCESS) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }

#ifdef TFM_FIH_PROFILE_ON
    /*
     * Any v1 config must be read here.
     * This is because v1 config is APPCPUSS powertrain and PDL uses Secure
     * aliases for it, but it will be marked as NS later. So check it now,
     * while it is still Secure.
     */
    (void)fih_delay();

    for (uint32_t idx = 0UL; idx < ifx_msc_agc_resp_config_v1_count; idx++) {
        cy_en_ms_ctl_cfg_gate_resp_t gate_resp;
        cy_en_ms_ctl_sec_resp_t sec_resp;

        ifx_msc_read_acg_resp_v1(ifx_msc_agc_resp_config_v1[idx].bus_master,
                                 &gate_resp,
                                 &sec_resp);

        if ((gate_resp != ifx_msc_agc_resp_config_v1[idx].gate_resp)
            || (sec_resp != ifx_msc_agc_resp_config_v1[idx].sec_resp)) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }
#endif /* TFM_FIH_PROFILE_ON */
#endif /* IFX_MSC_ACG_RESP_CONFIG_V1 */

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_FIH_PROFILE_ON
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_msc_verify_static_boundaries(void)
{
    cy_en_ms_ctl_cfg_gate_resp_t gate_resp;
    cy_en_ms_ctl_sec_resp_t sec_resp;

#if IFX_MSC_ACG_RESP_CONFIG
    /* Check response configuration for ACG and MSC for the referenced bus master */
    for (uint32_t idx = 0UL; idx < ifx_msc_agc_resp_config_count; idx++) {
        ifx_msc_read_acg_resp(ifx_msc_agc_resp_config[idx].bus_master,
                              &gate_resp,
                              &sec_resp);

        if ((gate_resp != ifx_msc_agc_resp_config[idx].gate_resp)
            || (sec_resp != ifx_msc_agc_resp_config[idx].sec_resp)) {
            FIH_RET(TFM_HAL_ERROR_GENERIC);
        }
    }
#endif /* IFX_MSC_ACG_RESP_CONFIG */

    /*
     * Any v1 config can't be read here, so was double-checked in ifx_msc_cfg().
     * This is because v1 config is APPCPUSS powertrain, which is marked NS at this
     * point but PDL uses Secure aliases for it.
     */

    FIH_RET(TFM_HAL_SUCCESS);
}
#endif /* TFM_FIH_PROFILE_ON */

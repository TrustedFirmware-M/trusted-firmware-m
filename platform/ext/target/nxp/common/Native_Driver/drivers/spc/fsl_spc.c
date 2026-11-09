/*
 * Copyright 2019, 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_spc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.spc"
#endif

/*
 * $Coverage Justification Reference$
 *
 * $Justification spc_c_ref_1$
 * The SPC busy status flag is too short to get coverage data.
 *
 * $Justification spc_c_ref_2$
 * On devices with FSL_FEATURE_SPC_HAS_VDD_SYS, the VD status functions
 * (SPC_GetActiveModeVoltageDetectStatus, SPC_GetLowPowerModeVoltageDetectStatus,
 * SPC_GetHighPowerModeVoltageDetectStatus) always return 0 due to non-overlapping
 * bit masks in the AND operation, making VD-dependent error paths unreachable.
 *
 * $Justification spc_c_ref_3$
 * Hardware prevents setting SysLDO/CoreLDO/glitch-detect to a state that would
 * trigger the bandgap-disable error path on this device.
 *
 * $Justification spc_c_ref_4$
 * Gcovr reports synthetic branches on simple bool-to-bitfield conditional
 * expressions, so excluding those assignments avoids redundant branch targets
 * in configuration helper code.
 *
 * $Justification spc_c_ref_5$
 * Composite regulator configuration wrappers only propagate helper status.
 * The relevant success and failure paths are covered in the lower-level helper
 * unit tests, so excluding these wrapper gates and follow-on helper calls avoids
 * redundant permutations.
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Gets selected power domain's requested low power mode.
 *
 * param base SPC peripheral base address.
 * param powerDomainId Power Domain Id, please refer to spc_power_domain_id_t.
 *
 * return The selected power domain's requested low power mode, please refer to spc_power_domain_low_power_mode_t.
 */
spc_power_domain_low_power_mode_t SPC_GetPowerDomainLowPowerMode(SPC_Type *base, spc_power_domain_id_t powerDomainId)
{
    uint32_t val;

    val = ((base->PD_STATUS[(uint8_t)powerDomainId] & SPC_PD_STATUS_LP_MODE_MASK) >> SPC_PD_STATUS_LP_MODE_SHIFT);
    return (spc_power_domain_low_power_mode_t)val;
}

/*!
 * brief Gets Isolation status for each power domains.
 *
 * This function gets the status which indicates whether certain
 * peripheral and the IO pads are in a latched state as a result
 * of having been in POWERDOWN mode.
 *
 * param base SPC peripheral base address.
 * return Current isolation status for each power domains.
 */
uint8_t SPC_GetPeriphIOIsolationStatus(SPC_Type *base)
{
    uint32_t reg;

    reg = base->SC;
    return (uint8_t)((reg & SPC_SC_ISO_CLR_MASK) >> SPC_SC_ISO_CLR_SHIFT);
}

/*!
 * brief Configs Low power request output pin.
 *
 * This function configs the low power request output pin
 *
 * param base SPC peripheral base address.
 * param config Pointer the spc_LowPower_Request_config_t structure.
 */
void SPC_SetLowPowerRequestConfig(SPC_Type *base, const spc_lowpower_request_config_t *config)
{
    assert(config != NULL);

    uint32_t reg;

    reg = base->LPREQ_CFG;
    reg &= ~(SPC_LPREQ_CFG_LPREQOE_MASK | SPC_LPREQ_CFG_LPREQPOL_MASK | SPC_LPREQ_CFG_LPREQOV_MASK);

    if (config->enable)
    {
        reg |= SPC_LPREQ_CFG_LPREQOE_MASK | SPC_LPREQ_CFG_LPREQPOL((uint8_t)(config->polarity)) |
               SPC_LPREQ_CFG_LPREQOV((uint8_t)(config->override));
    }
    else
    {
        reg &= ~SPC_LPREQ_CFG_LPREQOE_MASK;
    }

    base->LPREQ_CFG = reg;
}

#if defined(FSL_FEATURE_SPC_HAS_CFG_REGISTER) && FSL_FEATURE_SPC_HAS_CFG_REGISTER
/*!
 * brief Configs Integrated power switch in active mode.
 *
 * note Legacy API, will be removed.
 * param base SPC peripheral base address.
 * param config Pointer to spc_intergrated_power_switch_config_t pointer.
 */
void SPC_SetActiveModeIntegratedPowerSwitchConfig(SPC_Type *base, const spc_intergrated_power_switch_config_t *config)
{
    assert(config != NULL);

    if (config->wakeup)
    {
        base->CFG |= SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_MASK;
    }
    else
    {
        base->CFG &= ~SPC_CFG_INTG_PWSWTCH_WKUP_ACTIVE_EN_MASK;
    }

    if (config->sleep)
    {
        base->CFG |= SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_MASK;
    }
    else
    {
        base->CFG &= ~SPC_CFG_INTG_PWSWTCH_SLEEP_ACTIVE_EN_MASK;
    }
}
#endif /* FSL_FEATURE_SPC_HAS_CFG_REGISTER */

/*!
 * brief Configs Bandgap mode in Active mode.
 *
 * note In active mode, because CORELDO_VDD_DS is reserved and set to Normal, so it is impossible to
 * disable Bandgap in active mode
 *
 * param base SPC peripheral base address.
 * param mode The Bandgap mode be selected.
 *
 * retval kStatus_SPC_BandgapModeWrong The Bandgap can not be disabled in active mode.
 * retval kStatus_Success Config Bandgap mode in Active power mode successful.
 */
status_t SPC_SetActiveModeBandgapModeConfig(SPC_Type *base, spc_bandgap_mode_t mode)
{
    uint32_t reg;
    uint32_t state;

    reg = base->ACTIVE_CFG;

    if (mode == kSPC_BandgapDisabled)
    {
        state = SPC_GetActiveModeVoltageDetectStatus(base);

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any of the LVD/HVDs are kept enabled, bandgap mode must be enabled with buffer disabled. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_BandgapModeWrong; /* GCOVR_EXCL_LINE */
        }

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* The bandgap mode must be enabled if any regulators' drive strength set as Normal. */
        if ((base->ACTIVE_CFG & SPC_ACTIVE_CFG_DCDC_VDD_DS_MASK) ==
            SPC_ACTIVE_CFG_DCDC_VDD_DS(kSPC_DCDC_NormalDriveStrength))
        {
            return kStatus_SPC_BandgapModeWrong;
        }

#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* GCOVR_EXCL_START */
        if ((base->ACTIVE_CFG & SPC_ACTIVE_CFG_SYSLDO_VDD_DS_MASK) ==
            SPC_ACTIVE_CFG_SYSLDO_VDD_DS(kSPC_SysLDO_NormalDriveStrength))
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* state of GLITCH_DETECT_DISABLE will be ignored if bandgap is disabled. */
        /* GCOVR_EXCL_START */
        if ((base->ACTIVE_CFG & SPC_ACTIVE_CFG_GLITCH_DETECT_DISABLE_MASK) == 0UL)
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
#if defined(FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS) && FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* GCOVR_EXCL_START */
        if ((base->ACTIVE_CFG & SPC_ACTIVE_CFG_CORELDO_VDD_DS_MASK) ==
            SPC_ACTIVE_CFG_CORELDO_VDD_DS(kSPC_CoreLDO_NormalDriveStrength))
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS */
    }

    reg &= ~SPC_ACTIVE_CFG_BGMODE_MASK;
    reg |= SPC_ACTIVE_CFG_BGMODE(mode);

    base->ACTIVE_CFG = reg;

    return kStatus_Success;
}

#if defined(FSL_FEATURE_SPC_HAS_CFG_REGISTER) && FSL_FEATURE_SPC_HAS_CFG_REGISTER
/*!
 * brief Configs Integrated power switch in low power mode.
 *
 * note Legacy API, will be removed.
 *
 * param base SPC peripheral base address.
 * param config Pointer to spc_intergrated_power_switch_config_t pointer.
 */
void SPC_SetLowPowerModeIntegratedPowerSwitchConfig(SPC_Type *base, const spc_intergrated_power_switch_config_t *config)
{
    assert(config != NULL);

    if (config->wakeup)
    {
        base->CFG |= SPC_CFG_INTG_PWSWTCH_WKUP_EN_MASK;
    }
    else
    {
        base->CFG &= ~SPC_CFG_INTG_PWSWTCH_WKUP_EN_MASK;
    }

    if (config->sleep)
    {
        base->CFG |= SPC_CFG_INTG_PWSWTCH_SLEEP_EN_MASK;
    }
    else
    {
        base->CFG &= ~SPC_CFG_INTG_PWSWTCH_SLEEP_EN_MASK;
    }
}
#endif /* FSL_FEATURE_SPC_HAS_CFG_REGISTER */

/*!
 * brief Configs Bandgap mode in Low Power mode.
 *
 * This function configs Bandgap mode in Low Power mode.
 * IF user wants to disable Bandgap while keeping any of the Regulator in Normal Driver Strength
 * or if any of the High voltage detectors/Low voltage detectors are kept enabled, the Bandgap mode
 * will be set as Bandgap Enabled with Buffer Disabled.
 *
 * param base SPC peripheral base address.
 * param mode The Bandgap mode be selected.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Low Power mode is wrong.
 * retval kStatus_Success Config Bandgap mode in Low Power power mode successful.
 */
status_t SPC_SetLowPowerModeBandgapmodeConfig(SPC_Type *base, spc_bandgap_mode_t mode)
{
    uint32_t reg;
    uint32_t state;

    reg = base->LP_CFG;

    if (mode == kSPC_BandgapDisabled)
    {
        state = (uint32_t)SPC_GetLowPowerModeVoltageDetectStatus(base);

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any of the LVD/HVDs are kept enabled, bandgap mode must be enabled with buffer disabled. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_BandgapModeWrong; /* GCOVR_EXCL_LINE */
        }

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* The bandgap mode must be enabled if any regulators' drive strength set as Normal. */
        if (((base->LP_CFG & SPC_LP_CFG_DCDC_VDD_DS_MASK) == SPC_LP_CFG_DCDC_VDD_DS(kSPC_DCDC_NormalDriveStrength)) || /* GCOVR_EXCL_START */
            ((base->LP_CFG & SPC_LP_CFG_CORELDO_VDD_DS_MASK) ==
             SPC_LP_CFG_CORELDO_VDD_DS(kSPC_CoreLDO_NormalDriveStrength)))
        {
            return kStatus_SPC_BandgapModeWrong;
        } /* GCOVR_EXCL_STOP */

#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* GCOVR_EXCL_START */
        if ((((base->LP_CFG & SPC_LP_CFG_SYSLDO_VDD_DS_MASK) ==
             SPC_LP_CFG_SYSLDO_VDD_DS(kSPC_SysLDO_NormalDriveStrength))))
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */


        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* state of GLITCH_DETECT_DISABLE will be ignored if bandgap is disabled. */
        /* GCOVR_EXCL_START */
        if ((base->LP_CFG & SPC_LP_CFG_GLITCH_DETECT_DISABLE_MASK) == 0UL)
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
    }

    reg &= ~SPC_LP_CFG_BGMODE_MASK;
    reg |= SPC_LP_CFG_BGMODE(mode);
    base->LP_CFG = reg;

    return kStatus_Success;
}

/*!
 * brief Configs CORE voltage detect options.
 *
 * This function configs CORE voltage detect options.
 * Note: Setting both the voltage detect interrupt and reset
 *       enable will cause interrupt to be generated on exit from reset.
 *       If those conditioned is not desired, interrupt/reset only one is enabled.
 *
 * param base       SPC peripheral base address.
 * param config     Pointer to spc_core_voltage_detect_config_t structure.
 */
void SPC_SetCoreVoltageDetectConfig(SPC_Type *base, const spc_core_voltage_detect_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0UL;

    reg |= (config->option.HVDInterruptEnable) ? SPC_VD_CORE_CFG_HVDIE(1U) : SPC_VD_CORE_CFG_HVDIE(0U);
    reg |= (config->option.LVDInterruptEnable) ? SPC_VD_CORE_CFG_LVDIE(1U) : SPC_VD_CORE_CFG_LVDIE(0U);
    reg |= (config->option.HVDResetEnable) ? SPC_VD_CORE_CFG_HVDRE(1U) : SPC_VD_CORE_CFG_HVDRE(0U);
    reg |= (config->option.LVDResetEnable) ? SPC_VD_CORE_CFG_LVDRE(1U) : SPC_VD_CORE_CFG_LVDRE(0U);

    base->VD_CORE_CFG = reg;
}

#if (defined(FSL_FEATURE_SPC_HAS_VDD1P8_LVD) && FSL_FEATURE_SPC_HAS_VDD1P8_LVD)
/*!
 * brief Configs VDD1P8 low voltage detect options.
 *
 * param base       SPC peripheral base address.
 * param config     Pointer to spc_vdd1p8_voltage_detect_config_t structure.
 */
void SPC_SetVDD1P8VoltageDetectConfig(SPC_Type *base, const spc_vdd1p8_voltage_detect_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = base->VD_VDD1P8_CFG;

    reg &= ~SPC_VD_VDD1P8_CFG_LVDIE_MASK;
    reg |= (config->LVDInterruptEnable) ? SPC_VD_VDD1P8_CFG_LVDIE(1U) : SPC_VD_VDD1P8_CFG_LVDIE(0U);

    base->VD_VDD1P8_CFG = reg;
}
#endif /* FSL_FEATURE_SPC_HAS_VDD1P8_LVD */

/*!
 * brief Enables the Core High Voltage Detector in Active mode.
 *
 * note If the CORE_LDO high voltage detect is enabled in Active mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable Core HVD.
 *          true    -   Enable Core High voltage detector in active mode.
 *          false   -   Disable Core High voltage detector in active mode.
 *
 * retval kStatus_Success Enable Core High Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeCoreHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_CORE_HVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_CORE_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the Core Low Voltage Detector in Active mode.
 *
 * note If the CORE_LDO high voltage detect is enabled in Active mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable Core LVD.
 *          true    -   Enable Core Low voltage detector in active mode.
 *          false   -   Disable Core Low voltage detector in active mode.
 *
 * retval kStatus_Success Enable Core Low Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeCoreLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_CORE_LVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_CORE_LVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the Core High Voltage Detector in Low Power mode.
 *
 * note If the CORE_LDO high voltage detect is enabled in Low Power mode,
 * please note that the bandgap must be enabled and the drive strength of each regulator
 * must not set to low in low power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable Core HVD.
 *          true    -   Enable Core High voltage detector in low power mode.
 *          false   -   Disable Core High voltage detector in low power mode.
 *
 * retval kStatus_Success Enable Core High Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeCoreHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_CORE_HVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_CORE_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the Core Low Voltage Detector in Low Power mode.
 *
 * note If the CORE_LDO low voltage detect is enabled in Low Power mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable Core HVD.
 *          true    -   Enable Core Low voltage detector in low power mode.
 *          false   -   Disable Core Low voltage detector in low power mode.
 *
 * retval kStatus_Success Enable Core Low Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeCoreLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_CORE_LVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_CORE_LVDE_MASK;
    }

    return status;
}

#if (defined(FSL_FEATURE_SPC_HAS_VDD1P8_LVD) && FSL_FEATURE_SPC_HAS_VDD1P8_LVD)
/*!
 * brief Enables the VDD1P8 Low Voltage Detector in Active mode.
 *
 * note If the VDD1P8 low voltage detect is enabled in Active mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low in Active mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable VDD1P8 LVD.
 *          true    -   Enable VDD1P8 low voltage detector in active mode.
 *          false   -   Disable VDD1P8 low voltage detector in active mode.
 *
 * retval kStatus_Success Enable VDD1P8 Low Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeVDD1P8LowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_VDD1P8_LVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_VDD1P8_LVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the VDD1P8 Low Voltage Detector in Low Power mode.
 *
 * note If the VDD1P8 low voltage detect is enabled in Low Power mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable VDD1P8 LVD.
 *          true    -   Enable VDD1P8 low voltage detector in low power mode.
 *          false   -   Disable VDD1P8 low voltage detector in low power mode.
 *
 * retval kStatus_Success Enable VDD1P8 Low Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeVDD1P8LowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_VDD1P8_LVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_VDD1P8_LVDE_MASK;
    }

    return status;
}
#endif /* FSL_FEATURE_SPC_HAS_VDD1P8_LVD */

#if (defined(FSL_FEATURE_SPC_HAS_VDD_SYS) && FSL_FEATURE_SPC_HAS_VDD_SYS)
/*!
 * @brief Set system VDD Low-voltage level selection.
 *
 * This function selects the system VDD low-voltage level. Changing system VDD low-voltage level
 * must be done after disabling the System VDD low voltage reset and interrupt.
 *
 * @param base SPC peripheral base address.
 * @param level System VDD Low-Voltage level selection. See @ref spc_low_voltage_level_select_t for details.
 */
void SPC_SetSystemVDDLowVoltageLevel(SPC_Type *base, spc_low_voltage_level_select_t level)
{
    (void)level;
    (void)base;

    /*
    uint32_t reg;

    reg = base->VD_SYS_CFG;
    base->VD_SYS_CFG &= ~(SPC_VD_SYS_CFG_LVDRE_MASK | SPC_VD_SYS_CFG_LVDIE_MASK);
    reg |= SPC_VD_SYS_CFG_LVSEL(level);

    base->VD_SYS_CFG = reg; */
}

/*!
 * brief Configs SYS voltage detect options.
 *
 * This function config SYS voltage detect options.
 * Note: Setting both the voltage detect interrupt and reset
 *       enable will cause interrupt to be generated on exit from reset.
 *       If those conditioned is not desired, interrupt/reset only one is enabled.
 *
 * param base       SPC peripheral base address.
 * param config     Pointer to spc_system_voltage_detect_config_t structure.
 */
void SPC_SetSystemVoltageDetectConfig(SPC_Type *base, const spc_system_voltage_detect_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0UL;

    reg |= (config->option.HVDInterruptEnable) ? SPC_VD_SYS_CFG_HVDIE(1U) : SPC_VD_SYS_CFG_HVDIE(0U);
    reg |= (config->option.LVDInterruptEnable) ? SPC_VD_SYS_CFG_LVDIE(1U) : SPC_VD_SYS_CFG_LVDIE(0U);
    reg |= (config->option.HVDResetEnable) ? SPC_VD_SYS_CFG_HVDRE(1U) : SPC_VD_SYS_CFG_HVDRE(0U);
    reg |= (config->option.LVDResetEnable) ? SPC_VD_SYS_CFG_LVDRE(1U) : SPC_VD_SYS_CFG_LVDRE(0U);

    base->VD_SYS_CFG = reg;

    (void)(config->level);

    /* SPC_SetSystemVDDLowVoltageLevel(base, config->level); */
}

/*!
 * brief Enables the System High Voltage Detector in Active mode.
 *
 * note If the System_LDO high voltage detect is enabled in Active mode,
 * please note that the bandgap must be enabled and the drive strength of
 * each regulator must not set to low in Active mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable System HVD.
 *          true    -   Enable System High voltage detector in active mode.
 *          false   -   Disable System High voltage detector in active mode.
 *
 * retval kStatus_Success Enable System High Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeSystemHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_SYS_HVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_SYS_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the System Low Voltage Detector in Active mode.
 *
 * note If the System_LDO low voltage detect is enabled in Active mode,
 * please note that the bandgap must be enabled and the drive strength of each
 * regulator must not set to low in Active mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable System LVD.
 *          true    -   Enable System Low voltage detector in active mode.
 *          false   -   Disable System Low voltage detector in active mode.
 *
 * retval kStatus_Success Enable the System Low Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeSystemLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_SYS_LVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_SYS_LVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the System High Voltage Detector in Low Power mode.
 *
 * note If the System_LDO high voltage detect is enabled in low power mode,
 * please note that the bandgap must be enabled and the drive strength of each
 * regulator must not set to low in low power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable System HVD.
 *          true    -   Enable System High voltage detector in low power mode.
 *          false   -   Disable System High voltage detector in low power mode.
 *
 * retval kStatus_Success Enable System High Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeSystemHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_SYS_HVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_SYS_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the System Low Voltage Detector in Low Power mode.
 *
 * note If the System_LDO low voltage detect is enabled in Low Power mode,
 * please note that the bandgap must be enabled and the drive strength of each
 * regulator must not set to low in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable System HVD.
 *          true    -   Enable System Low voltage detector in low power mode.
 *          false   -   Disable System Low voltage detector in low power mode.
 *
 * retval kStatus_Success Enable System Low Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeSystemLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_SYS_LVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_SYS_LVDE_MASK;
    }

    return status;
}

#endif /* FSL_FEATURE_SPC_HAS_VDD_SYS */

/*!
 * brief Set IO VDD Low-Voltage level selection.
 *
 * This function selects the IO VDD Low-voltage level. Changing IO VDD low-voltage level
 * must be done after disabling the IO VDD low voltage reset and interrupt.
 *
 * param base SPC peripheral base address.
 * param level IO VDD Low-voltage level selection.
 */
void SPC_SetIOVDDLowVoltageLevel(SPC_Type *base, spc_low_voltage_level_select_t level)
{
    uint32_t reg;

    reg = base->VD_IO_CFG;

    base->VD_IO_CFG &= ~(SPC_VD_IO_CFG_LVSEL_MASK
#if (defined(SPC_VD_IO_CFG_LVDRE_MASK) && defined(SPC_VD_IO_CFG_LVDIE_MASK))
                         | SPC_VD_IO_CFG_LVDRE_MASK | SPC_VD_IO_CFG_LVDIE_MASK
#endif
    );
    reg |= SPC_VD_IO_CFG_LVSEL(level);

    base->VD_IO_CFG = reg;
}

/*!
 * brief Configs IO voltage detect options.
 *
 * This function config IO voltage detect options.
 * Note: Setting both the voltage detect interrupt and reset
 *       enable will cause interrupt to be generated on exit from reset.
 *       If those conditioned is not desired, interrupt/reset so only one is enabled.
 *
 * param base       SPC peripheral base address.
 * param config     Pointer to spc_IO_voltage_detect_config_t structure.
 */
void SPC_SetIOVoltageDetectConfig(SPC_Type *base, const spc_io_voltage_detect_config_t *config)
{
    assert(config != NULL);

    uint32_t reg = 0UL;

    /* Set trip voltage level. */
    SPC_SetIOVDDLowVoltageLevel(base, config->level);

    reg = base->VD_IO_CFG;
    reg &= ~(
#if (defined(SPC_VD_IO_CFG_LVDRE_MASK))
        SPC_VD_IO_CFG_LVDRE_MASK |
#endif
#if (defined(SPC_VD_IO_CFG_LVDIE_MASK))
        SPC_VD_IO_CFG_LVDIE_MASK |
#endif
        SPC_VD_IO_CFG_HVDRE_MASK | SPC_VD_IO_CFG_HVDIE_MASK);

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_4$.
     */
    reg |= (config->option.HVDInterruptEnable) ? SPC_VD_IO_CFG_HVDIE(1U) : SPC_VD_IO_CFG_HVDIE(0U); /* GCOVR_EXCL_BR_LINE */
#if defined(SPC_VD_IO_CFG_LVDIE_MASK)
    reg |= (config->option.LVDInterruptEnable) ? SPC_VD_IO_CFG_LVDIE(1U) : SPC_VD_IO_CFG_LVDIE(0U); /* GCOVR_EXCL_BR_LINE */
#endif
    reg |= (config->option.HVDResetEnable) ? SPC_VD_IO_CFG_HVDRE(1U) : SPC_VD_IO_CFG_HVDRE(0U); /* GCOVR_EXCL_BR_LINE */
#if defined(SPC_VD_IO_CFG_LVDRE_MASK)
    reg |= (config->option.LVDResetEnable) ? SPC_VD_IO_CFG_LVDRE(1U) : SPC_VD_IO_CFG_LVDRE(0U); /* GCOVR_EXCL_BR_LINE */
#endif

    base->VD_IO_CFG = reg;
}

/*!
 * brief Enables the IO High Voltage Detector in Active mode.
 *
 * note If the IO high voltage detect is enabled in Active mode,
 * please note that the bandgap must be enabled and the drive strength
 * of each regulator must not set to low in Active mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable IO HVD.
 *          true    -   Enable IO High voltage detector in active mode.
 *          false   -   Disable IO High voltage detector in active mode.
 *
 * retval kStatus_Success Enable IO High Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeIOHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_IO_HVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_IO_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the IO Low Voltage Detector in Active mode.
 *
 * note If the IO low voltage detect is enabled in Active mode,
 * please note that the bandgap must be enabled and the drive strength
 * of each regulator must not set to low in Active mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable IO LVD.
 *          true    -   Enable IO Low voltage detector in active mode.
 *          false   -   Disable IO Low voltage detector in active mode.
 *
 * retval kStatus_Success Enable IO Low Voltage Detect successfully.
 */
status_t SPC_EnableActiveModeIOLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_IO_LVDE_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_IO_LVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the IO High Voltage Detector in Low Power mode.
 *
 * note If the IO high voltage detect is enabled in Low Power mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable IO HVD.
 *          true    -   Enable IO High voltage detector in low power mode.
 *          false   -   Disable IO High voltage detector in low power mode.
 *
 * retval kStatus_Success Enable IO High Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeIOHighVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_IO_HVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_IO_HVDE_MASK;
    }

    return status;
}

/*!
 * brief Enables the IO Low Voltage Detector in Low Power mode.
 *
 * note If the IO low voltage detect is enabled in Low Power mode, please note that the bandgap must be enabled
 * and the drive strength of each regulator must not set to low in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Enable/Disable IO HVD.
 *          true    -   Enable IO Low voltage detector in low power mode.
 *          false   -   Disable IO Low voltage detector in low power mode.
 *
 * retval kStatus_Success Enable IO Low Voltage Detect in low power mode successfully.
 */
status_t SPC_EnableLowPowerModeIOLowVoltageDetect(SPC_Type *base, bool enable)
{
    status_t status = kStatus_Success;

    if (enable)
    {
        base->LP_CFG |= SPC_LP_CFG_IO_LVDE_MASK;
    }
    else
    {
        base->LP_CFG &= ~SPC_LP_CFG_IO_LVDE_MASK;
    }

    return status;
}

/*!
 * brief Configs external voltage domains
 *
 * This function configs external voltage domains isolation.
 *
 * param base SPC peripheral base address.
 * param lowPowerIsoMask The mask of external domains isolate enable during low power mode.
 * param IsoMask The mask of external domains isolate.
 */
void SPC_SetExternalVoltageDomainsConfig(SPC_Type *base, uint8_t lowPowerIsoMask, uint8_t IsoMask)
{
    uint32_t reg = 0UL;

    reg |= SPC_EVD_CFG_REG_EVDISO(IsoMask) | SPC_EVD_CFG_REG_EVDLPISO(lowPowerIsoMask);
    base->EVD_CFG = reg;
}

/*!
 * brief Configs Core LDO VDD Regulator in Active mode.
 *
 * note If any voltage detect feature is enabled in Active mode, then CORE_LDO's drive strength must not set to low.
 * note Core VDD level for the Core LDO low power regulator can only be changed when CORELDO_VDD_DS is normal
 *
 * param base SPC peripheral base address.
 * param option Pointer to the spc_active_mode_Core_LDO_option_t structure.
 *
 * retval kStatus_Success Config Core LDO regulator in Active power mode successful.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_CORELDOLowDriveStrengthIgnore If any voltage detect enabled, core_ldo's drive strength can not
 * set to low.
 * retval kStatus_SPC_CORELDOVoltageWrong The selected voltage level in active mode is not allowed.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetActiveModeCoreLDORegulatorConfig(SPC_Type *base, const spc_active_mode_core_ldo_option_t *option)
{
    assert(option != NULL);

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS) && FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS
    spc_core_ldo_voltage_level_t preVoltage;
    uint32_t state;
#endif /* FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS */

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

#if defined(FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS) && FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS
    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
    if (option->CoreLDODriveStrength == kSPC_CoreLDO_LowDriveStrength) /* GCOVR_EXCL_BR_LINE */
    {
        /* If any voltage detect feature is enabled in Active mode, then CORE_LDO's drive strength must not set to low.
         */
        state = SPC_GetActiveModeVoltageDetectStatus(base); /* GCOVR_EXCL_START */
        if (state != 0UL)
        {
            return kStatus_SPC_CORELDOLowDriveStrengthIgnore;
        }

        /* Core VDD level for the Core LDO low power regulator can only be changed when CORELDO_VDD_DS is normal. */
        preVoltage = SPC_GetActiveModeCoreLDOVDDVoltageLevel(base);
        if ((option->CoreLDOVoltage != kSPC_CoreLDO_MidDriveVoltage) && (preVoltage != option->CoreLDOVoltage))
        {
            return kStatus_SPC_CORELDOVoltageSetFail;
        }

        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_CORELDO_VDD_DS_MASK;
    } /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS */
    base->ACTIVE_CFG = ((base->ACTIVE_CFG & ~SPC_ACTIVE_CFG_CORELDO_VDD_LVL_MASK) |
                        SPC_ACTIVE_CFG_CORELDO_VDD_LVL(option->CoreLDOVoltage));

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/*!
 * brief Configs CORE LDO Regulator in low power mode
 *
 * This function configs CORE LDO Regulator in Low Power mode.
 * If CORE LDO VDD Drive Strength is set to Normal, the CORE LDO VDD regulator voltage
 * level in Active mode must be equal to the voltage level in Low power mode. And the Bandgap
 * must be programmed to select bandgap enabled.
 * Core VDD voltage levels for the Core LDO low power regulator can only be changed when the CORE
 * LDO Drive Strength is set as Normal.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the spc_lowpower_mode_Core_LDO_option_t structure.
 * retval kStatus_Success Config Core LDO regulator in power mode successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in low powermode is wrong.
 * retval kStatus_SPC_CORELDOVoltageWrong The selected voltage level is wrong.
 * retval kStatus_SPC_CORELDOLowDriveStrengthIgnore Set driver strength to low will be ignored.
 * retval kStatus_SPC_CORELDOVoltageSetFail. Fail to change Core LDO voltage level.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetLowPowerModeCoreLDORegulatorConfig(SPC_Type *base, const spc_lowpower_mode_core_ldo_option_t *option)
{
    spc_core_ldo_voltage_level_t preVoltage;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->CoreLDODriveStrength == kSPC_CoreLDO_NormalDriveStrength)
    {
        base->LP_CFG |= SPC_LP_CFG_CORELDO_VDD_DS_MASK;
        base->LP_CFG =
            ((base->LP_CFG & (~SPC_LP_CFG_CORELDO_VDD_LVL_MASK)) | SPC_LP_CFG_CORELDO_VDD_LVL(option->CoreLDOVoltage));
    }
    else
    {
        state = (uint32_t)SPC_GetLowPowerModeVoltageDetectStatus(base);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_CORELDOLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }

        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        preVoltage = SPC_GetLowPowerCoreLDOVDDVoltageLevel(base); /* GCOVR_EXCL_LINE */
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* Core LDO voltage level can only be changed when the Core LDO Drive Strength set to Normal */
        if ((option->CoreLDOVoltage >= kSPC_CoreLDO_MidDriveVoltage) && (preVoltage != option->CoreLDOVoltage)) /* GCOVR_EXCL_START */
        {
            return kStatus_SPC_CORELDOVoltageSetFail;
        } /* GCOVR_EXCL_STOP */

        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        base->LP_CFG &= ~SPC_LP_CFG_CORELDO_VDD_DS_MASK; /* GCOVR_EXCL_LINE */
    }

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
/*!
 * brief Configs System LDO VDD Regulator in Active mode.
 *
 * This function configs System LDO VDD Regulator in Active mode.
 * If System LDO VDD Drive Strength is set to Normal, the Bandgap mode in Active mode must be programmed
 * to a value that enable the bandgap.
 * If any voltage detects are kept enabled, configuration to set System LDO VDD drive strength to low will
 * be ignored.
 * If select System LDO VDD Regulator voltage level to Over Drive Voltage, the Drive Strength of System LDO VDD
 * Regulator must be set to Normal otherwise the regulator Drive Strength will be forced to Normal.
 * If select System LDO VDD Regulator voltage level to Over Drive Voltage, the High voltage detect must be disabled.
 * Otherwise it will be fail to regulator to Over Drive Voltage.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the spc_active_mode_Sys_LDO_option_t structure.
 * retval kStatus_Success Config System LDO regulator in Active power mode successful.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Active mode is wrong.
 * retval kStatus_SPC_SYSLDOOverDriveVoltageFail Fail to regulator to Over Drive Voltage.
 * retval kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set System LDO VDD regulator's driver strength to Low will be
 * ignored.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetActiveModeSystemLDORegulatorConfig(SPC_Type *base, const spc_active_mode_sys_ldo_option_t *option)
{
    assert(option != NULL);

    uint32_t reg;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if (defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY)
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->SysLDODriveStrength == kSPC_SysLDO_NormalDriveStrength)
    {
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* When select System LDO voltage level to Over Drive voltage, The HVD of System LDO must be disabled. */
        if (((base->ACTIVE_CFG & SPC_ACTIVE_CFG_SYS_HVDE_MASK) != 0UL) &&
            (option->SysLDOVoltage == kSPC_SysLDO_OverDriveVoltage))
        {
            return kStatus_SPC_SYSLDOOverDriveVoltageFail;
        }
    }
    else
    {
        state = (uint32_t)SPC_GetActiveModeVoltageDetectStatus(base);

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_SYSLDOLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* If select voltage level as Over Drive Voltage, Drive Strength can not be set to low. */
        if (option->SysLDOVoltage == kSPC_SysLDO_OverDriveVoltage)
        {
            return kStatus_SPC_SYSLDOLowDriveStrengthIgnore;
        }
    }

    reg = base->ACTIVE_CFG;
    reg &= ~(SPC_ACTIVE_CFG_SYSLDO_VDD_DS_MASK | SPC_ACTIVE_CFG_SYSLDO_VDD_LVL_MASK);
    reg |= SPC_ACTIVE_CFG_SYSLDO_VDD_DS(option->SysLDODriveStrength) |
           SPC_ACTIVE_CFG_SYSLDO_VDD_LVL(option->SysLDOVoltage);

    base->ACTIVE_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/*!
 * brief Configs System LDO regulator in low power modes.
 *
 * This function configs System LDO regulator in low power modes.
 * If System LDO VDD Regulator Drive strength is set to normal, bandgap mode in low power
 * mode must be programmed to a value that enables the Bandgap.
 * If any High voltage detectors or Low Voltage detectors are kept enabled, configuration
 * to set System LDO Regulator drive strength as Low will be ignored.
 *
 * param base SPC peripheral base address.
 * param option Pointer to spc_lowpower_mode_Sys_LDO_option_t structure.
 * retval kStatus_Success Config System LDO regulator in Low Power Mode successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Low Power Mode is wrong.
 * retval kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set driver strength to low will be ignored.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetLowPowerModeSystemLDORegulatorConfig(SPC_Type *base, const spc_lowpower_mode_sys_ldo_option_t *option)
{
    uint32_t reg;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->SysLDODriveStrength == kSPC_SysLDO_LowDriveStrength)
    {
        state = (uint32_t)SPC_GetLowPowerModeVoltageDetectStatus(base);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_SYSLDOLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }
    }

    reg = base->LP_CFG;
    reg &= ~(SPC_LP_CFG_SYSLDO_VDD_DS_MASK);
    reg |= SPC_LP_CFG_SYSLDO_VDD_DS(option->SysLDODriveStrength);

    base->LP_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */

/*!
 * brief Configs DCDC VDD Regulator in Active mode.
 *
 * This function configs DCDC VDD Regulator in Active mode.
 * If DCDDC VDD Drive Strength is set to Normal, the Bandgap mode in Active mode must be programmed
 * to a value that enable the bandgap.
 * If any voltage detects are kept enabled, configuration to set DCDC VDD drive strength to low will
 * be ignored.
 * When switching DCDC from low drive strength to Normal driver strength, make sure the DCDC high VDD LVL
 * setting to the same level that is set prior to switching the DCDC to low drive strength.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the spc_active_mode_DCDC_option_t structure.
 * retval kStatus_Success Config DCDC regulator in Active power mode successful.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Active mode is wrong.
 * retval kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetActiveModeDCDCRegulatorConfig(SPC_Type *base, const spc_active_mode_dcdc_option_t *option)
{
    assert(option != NULL);

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

    uint32_t reg;
    uint32_t state;

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->DCDCDriveStrength == kSPC_DCDC_LowDriveStrength)
    {
        state = (uint32_t)SPC_GetActiveModeVoltageDetectStatus(base);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_DCDCLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }
    }

    reg = base->ACTIVE_CFG;
    reg &= ~(SPC_ACTIVE_CFG_DCDC_VDD_LVL_MASK | SPC_ACTIVE_CFG_DCDC_VDD_DS_MASK);
    reg |= SPC_ACTIVE_CFG_DCDC_VDD_DS(option->DCDCDriveStrength) | SPC_ACTIVE_CFG_DCDC_VDD_LVL(option->DCDCVoltage);

    base->ACTIVE_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if defined(FSL_FEATURE_SPC_HAS_DCDC_VOUT2P5_SEL) && FSL_FEATURE_SPC_HAS_DCDC_VOUT2P5_SEL
/*!
 * brief Enable/disable the DCDC 2.5V output in Active mode.
 *
 * note Depending on the SoC the 2.5V output select resides either in the per-mode ACTIVE_CFG
 * register or in the global DCDC_CFG register; this function writes whichever applies.
 *
 * param base SPC peripheral base address.
 * param enable Select the DCDC 2.5V output in Active mode.
 *
 * retval kStatus_Success The 2.5V output selection was applied successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_EnableActiveModeDCDC2P5VOutput(SPC_Type *base, bool enable)
{
#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        return kStatus_SPC_Busy;
    }

    /* The DCDC 2.5V output select bit lives in a different register depending on the SoC: in the
     * per-mode ACTIVE_CFG register on some instances (KW43/MCXW70), and in the global DCDC_CFG
     * register on others (KW45/KW47/MCXW71/MCXW72). */
#if defined(FSL_FEATURE_SPC_DCDC_VOUT2P5_SEL_IN_ACTIVE_CFG) && FSL_FEATURE_SPC_DCDC_VOUT2P5_SEL_IN_ACTIVE_CFG
    if (enable)
    {
        base->ACTIVE_CFG |= SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_MASK;
    }
    else
    {
        base->ACTIVE_CFG &= ~SPC_ACTIVE_CFG_DCDC_VOUT2P5_SEL_MASK;
    }
#else
    if (enable)
    {
        base->DCDC_CFG |= SPC_DCDC_CFG_VOUT2P5_SEL_MASK;
    }
    else
    {
        base->DCDC_CFG &= ~SPC_DCDC_CFG_VOUT2P5_SEL_MASK;
    }
#endif /* FSL_FEATURE_SPC_DCDC_VOUT2P5_SEL_IN_ACTIVE_CFG */

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if (defined(FSL_FEATURE_SPC_DCDC_VOUT2P5_SEL_IN_ACTIVE_CFG) && FSL_FEATURE_SPC_DCDC_VOUT2P5_SEL_IN_ACTIVE_CFG) && \
    (defined(FSL_FEATURE_SPC_HAS_HP_CFG_REG) && FSL_FEATURE_SPC_HAS_HP_CFG_REG)
/*!
 * brief Enable/disable the DCDC 2.5V output in High Power mode.
 *
 * param base SPC peripheral base address.
 * param enable Select the DCDC 2.5V output in High Power mode.
 *
 * retval kStatus_Success The 2.5V output selection was applied successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_EnableHighPowerModeDCDC2P5VOutput(SPC_Type *base, bool enable)
{
#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        return kStatus_SPC_Busy;
    }

    if (enable)
    {
        base->HP_CFG |= SPC_HP_CFG_DCDC_VOUT2P5_SEL_MASK;
    }
    else
    {
        base->HP_CFG &= ~SPC_HP_CFG_DCDC_VOUT2P5_SEL_MASK;
    }

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}
#endif /* ..._IN_ACTIVE_CFG && FSL_FEATURE_SPC_HAS_HP_CFG_REG */
#endif /* FSL_FEATURE_SPC_HAS_DCDC_VOUT2P5_SEL */

#if defined(FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL) && FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL
/*!
 * brief Configure DCDC output voltage ramp control.
 *
 * param base SPC peripheral base address.
 * param config Pointer to the ramp control configuration.
 *
 * retval kStatus_Success Ramp control configuration applied successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetDCDCRampControlConfig(SPC_Type *base, const spc_dcdc_ramp_config_t *config)
{
    assert(config != NULL);
    assert(config->rampControl <= (uint8_t)(SPC_DCDC_CFG_RAMP_CNTRL_MASK >> SPC_DCDC_CFG_RAMP_CNTRL_SHIFT));
#if defined(FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP) && FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP
    assert(config->rampControlLowPower <=
           (uint8_t)(SPC_DCDC_CFG_RAMP_CNTRL_LP_MASK >> SPC_DCDC_CFG_RAMP_CNTRL_LP_SHIFT));
#endif

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif
    uint32_t reg;

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        return kStatus_SPC_Busy;
    }

    /* Program the ramp enable bit first and let it settle before applying the ramp trims,
     * matching the recommended hardware programming sequence. */
    reg = base->DCDC_CFG;
    if (config->enableRampControl)
    {
        reg |= SPC_DCDC_CFG_RAMP_CNTRL_EN_MASK;
    }
    else
    {
        reg &= ~SPC_DCDC_CFG_RAMP_CNTRL_EN_MASK;
    }
    base->DCDC_CFG = reg;

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    if (config->enableRampControl)
    {
        reg = base->DCDC_CFG;
        reg &= ~(SPC_DCDC_CFG_RAMP_CNTRL_MASK
#if defined(FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP) && FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP
                 | SPC_DCDC_CFG_RAMP_CNTRL_LP_MASK
#endif
        );
        reg |= SPC_DCDC_CFG_RAMP_CNTRL(config->rampControl);
#if defined(FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP) && FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL_LP
        reg |= SPC_DCDC_CFG_RAMP_CNTRL_LP(config->rampControlLowPower);
#endif
        base->DCDC_CFG = reg;

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
        while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
        while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
        {
#if SPC_BUSY_TIMEOUT
            if ((--timeout) == 0U)
            {
                return kStatus_Timeout;
            }
#endif
        }
    }

    return kStatus_Success;
}
#endif /* FSL_FEATURE_SPC_HAS_DCDC_RAMP_CNTRL */

/*!
 * brief Configs DCDC VDD Regulator in Low power modes.
 *
 * This function configs DCDC VDD Regulator in Low Power modes.
 * If DCDC VDD Drive Strength is set to Normal, the Bandgap mode in Low Power mode must be programmed
 * to a value that enables the Bandgap.
 * If any of voltage detectors are kept enabled, configuration to set DCDC VDD Drive Strength to Low or Pulse mode
 * will be ignored.
 * In Deep Power Down mode, DCDC regulator is always turned off.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the spc_lowpower_mode_DCDC_option_t structure.
 * retval kStatus_Success Config DCDC regulator in low power mode successfully.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Low Power mode is wrong.
 * retval kStatus_SPC_DCDCPulseRefreshModeIgnore Set driver strength to Pulse Refresh mode will be ignored.
 * retval kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low Drive Strength will be ignored.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetLowPowerModeDCDCRegulatorConfig(SPC_Type *base, const spc_lowpower_mode_dcdc_option_t *option)
{
    uint32_t reg;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    state = (uint32_t)SPC_GetLowPowerModeVoltageDetectStatus(base);

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_2$.
     */
    /* GCOVR_EXCL_START */
    if (state != 0UL)
    {
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* If any HVD/LVDs are kept enabled write to set DCDC regulator's drive strength to low/pluse refresh will be
         * ignored. */
        if (option->DCDCDriveStrength == kSPC_DCDC_PulseRefreshMode)
        {
            return kStatus_SPC_DCDCPulseRefreshModeIgnore;
        }
        else if (option->DCDCDriveStrength == kSPC_DCDC_LowDriveStrength)
        {
            return kStatus_SPC_DCDCLowDriveStrengthIgnore;
        }
        else
        {
            /* Add comments to prevent the case of MISRA C-2012 rule 15.7. */
        }
    }
    /* GCOVR_EXCL_STOP */

    reg = base->LP_CFG;
    reg &= ~(SPC_LP_CFG_DCDC_VDD_LVL_MASK | SPC_LP_CFG_DCDC_VDD_DS_MASK);
    reg |= SPC_LP_CFG_DCDC_VDD_LVL(option->DCDCVoltage) | SPC_LP_CFG_DCDC_VDD_DS(option->DCDCDriveStrength);

    base->LP_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if (defined(FSL_FEATURE_SPC_HAS_DCDC_BURST_CFG) && FSL_FEATURE_SPC_HAS_DCDC_BURST_CFG)
/*!
 * brief Config DCDC Burst options
 *
 * param base SPC peripheral base address.
 * param config Pointer to spc_DCDC_burst_config_t structure.
 *
 * retval kStatus_Success Successfully configured.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetDCDCBurstConfig(SPC_Type *base, spc_dcdc_burst_config_t *config)
{
    assert(config != NULL);

#if SPC_DCDC_ACK_TIMEOUT
    uint32_t timeout = SPC_DCDC_ACK_TIMEOUT;
#endif

#if !(defined(FSL_FEATURE_SPC_HAS_NO_DCDC_FREQ_CNTRL) && FSL_FEATURE_SPC_HAS_NO_DCDC_FREQ_CNTRL)
    uint32_t reg = base->DCDC_CFG;
    reg &= ~(SPC_DCDC_CFG_FREQ_CNTRL_MASK | SPC_DCDC_CFG_FREQ_CNTRL_ON_MASK);
    reg |= SPC_DCDC_CFG_FREQ_CNTRL(config->freq);
    reg |= config->stabilizeBurstFreq ? SPC_DCDC_CFG_FREQ_CNTRL_ON(1U) : SPC_DCDC_CFG_FREQ_CNTRL_ON(0U);
    base->DCDC_CFG = reg;
#endif

    /* Clear DCDC burst acknowledge flag. */
    base->DCDC_BURST_CFG |= SPC_DCDC_BURST_CFG_BURST_ACK_MASK;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_4$.
     */
    /* INT31-C: Use conditional expression for bool to unsigned long conversion */
    base->DCDC_BURST_CFG |= SPC_DCDC_BURST_CFG_EXT_BURST_EN(config->externalBurstRequest ? 1U : 0U); /* GCOVR_EXCL_BR_LINE */

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
    if (config->sofwareBurstRequest) /* GCOVR_EXCL_BR_LINE */
    {
        base->DCDC_BURST_CFG |= SPC_DCDC_BURST_CFG_BURST_REQ_MASK;

        while ((base->DCDC_BURST_CFG & SPC_DCDC_BURST_CFG_BURST_ACK_MASK) == 0U)
        {
#if SPC_DCDC_ACK_TIMEOUT
            if ((--timeout) == 0U)
            {
                return kStatus_Timeout;
            }
#endif
        }

        /* DCDC burst request has completed and acknowledged, need to clear this flag. */
        base->DCDC_BURST_CFG |= SPC_DCDC_BURST_CFG_BURST_ACK_MASK;
    }

    return kStatus_Success;
}

/*!
 * brief Set the count value of the reference clock.
 *
 * This function set the count value of the reference clock to control the frequency
 * of dcdc refresh when dcdc is configured in Pulse Refresh mode.
 *
 * param base SPC peripheral base address.
 * param count The count value, 16 bit width.
 */
void SPC_SetDCDCRefreshCount(SPC_Type *base, uint16_t count)
{
    uint32_t reg;

    reg = base->DCDC_BURST_CFG;
    reg &= ~SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT_MASK;
    reg |= SPC_DCDC_BURST_CFG_PULSE_REFRESH_CNT(count);

    base->DCDC_BURST_CFG = reg;
}
#endif /* FSL_FEATURE_SPC_HAS_DCDC_BURST_CFG */

/*!
 * brief Configs regulators in Active mode.
 *
 * This function provides the method to config all on-chip regulators in active mode.
 *
 * param base SPC peripheral base address.
 * param config Pointer to spc_active_mode_regulators_config_t structure.
 * retval kStatus_Success Config regulators in Active power mode successful.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Active mode is wrong.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_CORELDOVoltageWrong The selected voltage level in active mode is not allowed.
 * retval kStatus_SPC_SYSLDOOverDriveVoltageFail Fail to regulator to Over Drive Voltage.
 * retval kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetActiveModeRegulatorsConfig(SPC_Type *base, const spc_active_mode_regulators_config_t *config)
{
    assert(config != NULL);

    status_t status;
#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

    status = SPC_SetActiveModeCoreLDORegulatorConfig(base, &config->CoreLDOOption);
    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_5$.
     */
    if (status == kStatus_Success) /* GCOVR_EXCL_BR_LINE */
    {
        status = SPC_SetActiveModeDCDCRegulatorConfig(base, &config->DCDCOption);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_5$.
         */
        if (status == kStatus_Success) /* GCOVR_EXCL_START */
        {
            while (SPC_GetBusyStatusFlag(base) == true)
            {
#if SPC_BUSY_TIMEOUT
                if ((--timeout) == 0U)
                {
                    status = kStatus_Timeout;
                }
#endif
            }
#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
            status = SPC_SetActiveModeSystemLDORegulatorConfig(base, &config->SysLDOOption);
#endif
            if (status == kStatus_Success)
            {
                status = SPC_SetActiveModeBandgapModeConfig(base, config->bandgapMode);
#if (defined(FSL_FEATURE_SPC_HAS_LPBUFF) && FSL_FEATURE_SPC_HAS_LPBUFF)
                if (status == kStatus_Success)
                {
                    SPC_EnableActiveModeCMPBandgapBuffer(base, config->lpBuff);
                }
#endif /* FSL_FEATURE_SPC_HAS_LPBUFF */
            }
        } /* GCOVR_EXCL_STOP */
    }
    return status;
}

/*!
 * brief Configs regulators in Low Power mode.
 *
 * This function provides the method to config all on-chip regulators in Low Power mode.
 *
 * param base SPC peripheral base address.
 * param config Pointer to spc_lowpower_mode_regulators_config_t structure.
 * retval kStatus_Success Config regulators in Low power mode successful.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in Low Power mode is wrong.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_CORELDOVoltageWrong The selected voltage level is wrong.
 * retval kStatus_SPC_CORELDOLowDriveStrengthIgnore Set driver strength to low will be ignored.
 * retval kStatus_SPC_CORELDOVoltageSetFail. Fail to change Core LDO voltage level.
 * retval kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set driver strength to low will be ignored.
 * retval kStatus_SPC_DCDCPulseRefreshModeIgnore Set driver strength to Pulse Refresh mode will be ignored.
 * retval kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low Drive Strength will be ignored.
 */
status_t SPC_SetLowPowerModeRegulatorsConfig(SPC_Type *base, const spc_lowpower_mode_regulators_config_t *config)
{
    assert(config != NULL);

    status_t status = kStatus_Success;

    status = SPC_SetLowPowerModeCoreLDORegulatorConfig(base, &config->CoreLDOOption);
    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_2$.
     */
    if (status == kStatus_Success)
    {
#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
        status = SPC_SetLowPowerModeSystemLDORegulatorConfig(base, &config->SysLDOOption);
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        if (status == kStatus_Success)
        {
            status = SPC_SetLowPowerModeDCDCRegulatorConfig(base, &config->DCDCOption);
            /*
             * $Branch Coverage Justification$
             * $ref spc_c_ref_2$.
             */
            if (status == kStatus_Success)
            {
                status = SPC_SetLowPowerModeBandgapmodeConfig(base, config->bandgapMode);
                if (status == kStatus_Success)
                {
#if (defined(FSL_FEATURE_SPC_HAS_LPBUFF) && FSL_FEATURE_SPC_HAS_LPBUFF)
                    SPC_EnableLowPowerModeCMPBandgapBufferMode(base, config->lpBuff);
#endif /* FSL_FEATURE_SPC_HAS_LPBUFF */
                    SPC_EnableLowPowerModeLowPowerIREF(base, config->lpIREF);
                    SPC_EnableLowPowerModeCoreVDDInternalVoltageScaling(base, config->CoreIVS);
                }
            }
        }
    }

    return status;
}

/*!
 * brief Set the SRAM operate voltage level.
 *
 * param base SPC peripheral base address.
 * param voltage Target SRAM operate voltage level, please refer to spc_sram_operat_voltage_t.
 *
 * retval kStatus_Success Successfully configured.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetSRAMOperateVoltage(SPC_Type *base, spc_sram_operat_voltage_t voltage)
{
#if SPC_SRAM_ACK_TIMEOUT
    uint32_t timeout = SPC_SRAM_ACK_TIMEOUT;
#endif

    /* Configure SRAM to support new voltage level. */
    base->SRAMCTL = ((base->SRAMCTL & ~SPC_SRAMCTL_VSM_MASK) | (SPC_SRAMCTL_VSM(voltage)));

    /* Request SRAM voltage update. */
    base->SRAMCTL |= SPC_SRAMCTL_REQ_MASK;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
    /* Wait for SRAM voltage update complete. */
    while ((base->SRAMCTL & SPC_SRAMCTL_ACK_MASK) == 0U) /* GCOVR_EXCL_BR_LINE */
    {
#if SPC_SRAM_ACK_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Clear SRAM voltage update request. */
    base->SRAMCTL &= ~SPC_SRAMCTL_REQ_MASK;

    return kStatus_Success;
}

#if (defined(FSL_FEATURE_SPC_HAS_HP_CFG_REG) && FSL_FEATURE_SPC_HAS_HP_CFG_REG)
/*!
 * brief Set bandgap mode in high power mode.
 *
 * param base SPC peripheral base address.
 * param mode Specify the bandgap mode in high power mode.
 *
 * retval kStatus_SPC_BandgapModeWrong The Bandgap can not be disabled in high power mode.
 * retval kStatus_Success Config Bandgap mode in high power mode successful.
 */
status_t SPC_SetHighPowerModeBandgapModeConfig(SPC_Type *base, spc_bandgap_mode_t mode)
{
    uint32_t reg;
    uint32_t state;

    reg = base->HP_CFG;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_3$.
     */
    if (mode == kSPC_BandgapDisabled) /* GCOVR_EXCL_BR_LINE */
    {
        state = SPC_GetHighPowerModeVoltageDetectStatus(base);

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any of the LVD/HVDs are kept enabled, bandgap mode must be enabled with buffer disabled. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_BandgapModeWrong; /* GCOVR_EXCL_LINE */
        }

        /* The bandgap mode must be enabled if any regulators' drive strength set as Normal. */
        if (((base->HP_CFG & SPC_HP_CFG_DCDC_VDD_DS_MASK) == SPC_HP_CFG_DCDC_VDD_DS(kSPC_DCDC_NormalDriveStrength)))
        {
            return kStatus_SPC_BandgapModeWrong;
        }

#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        if (((base->HP_CFG & SPC_HP_CFG_SYSLDO_VDD_DS_MASK) ==
             SPC_HP_CFG_SYSLDO_VDD_DS(kSPC_SysLDO_NormalDriveStrength)))
        {
            return kStatus_SPC_BandgapModeWrong;
        }
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* state of GLITCH_DETECT_DISABLE will be ignored if bandgap is disabled. */
        if ((base->HP_CFG & SPC_HP_CFG_GLITCH_DETECT_DISABLE_MASK) == 0UL) /* GCOVR_EXCL_START */
        {
            return kStatus_SPC_BandgapModeWrong;
        } /* GCOVR_EXCL_STOP */
#if defined(FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS) && FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* GCOVR_EXCL_START */
        if ((base->HP_CFG & SPC_HP_CFG_CORELDO_VDD_DS_MASK) ==
            SPC_HP_CFG_CORELDO_VDD_DS(kSPC_CoreLDO_NormalDriveStrength))
        {
            return kStatus_SPC_BandgapModeWrong;
        }
        /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS */
    }

    reg &= ~SPC_HP_CFG_BGMODE_MASK;
    reg |= SPC_HP_CFG_BGMODE(mode);

    base->HP_CFG = reg;

    return kStatus_Success;
}

/*!
 * brief Configure CORE LDO regulator in high power mode.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the CORE LDO regulator configuration, please refer to @ref spc_hp_mode_core_ldo_option_t.
 *
 * retval #kStatus_Success Config Core LDO regulator in High power mode successful.
 * retval #kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval #kStatus_SPC_CORELDOLowDriveStrengthIgnore If any voltage detect enabled, core_ldo's drive strength can not
 * set to low.
 * retval #kStatus_SPC_CORELDOVoltageWrong The selected voltage level in high power mode is not allowed.
 * retval #kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetHighPowerModeCoreLDORegulatorConfig(SPC_Type *base, const spc_hp_mode_core_ldo_option_t *option)
{
    spc_core_ldo_voltage_level_t preVoltage;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

#if defined(FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS) && FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS
    if (option->CoreLDODriveStrength == kSPC_CoreLDO_LowDriveStrength) /* GCOVR_EXCL_BR_LINE */
    {
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        /* If any voltage detect feature is enabled in High power mode, then CORE_LDO's drive strength must not set to
         * low.
         */
        state = SPC_GetHighPowerModeVoltageDetectStatus(base); /* GCOVR_EXCL_START */
        if (state != 0UL)
        {
            return kStatus_SPC_CORELDOLowDriveStrengthIgnore;
        }

        preVoltage = SPC_GetHighPowerModeCoreLDOVDDVoltageLevel(base);
        if ((option->CoreLDOVoltage != kSPC_CoreLDO_MidDriveVoltage) && (preVoltage != option->CoreLDOVoltage))
        {
            return kStatus_SPC_CORELDOVoltageSetFail;
        }

        base->HP_CFG &= ~SPC_HP_CFG_CORELDO_VDD_DS_MASK;
    } /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_CORELDO_VDD_DS */
    base->HP_CFG =
        ((base->HP_CFG & ~SPC_HP_CFG_CORELDO_VDD_LVL_MASK) | SPC_HP_CFG_CORELDO_VDD_LVL(option->CoreLDOVoltage));

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
/*!
 * brief Configure System LDO regulator in high power mode.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the SYSTEM LDO regulator configuration, please refer to @ref spc_hp_mode_sys_ldo_option_t.
 *
 * retval #kStatus_Success Config System LDO regulator in Active power mode successful.
 * retval #kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval #kStatus_SPC_SYSLDOOverDriveVoltageFail Fail to regulator to Over Drive Voltage.
 * retval #kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval #kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetHighPowerModeSystemLDORegulatorConfig(SPC_Type *base, const spc_hp_mode_sys_ldo_option_t *option)
{
    assert(option != NULL);

    uint32_t reg;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if (defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY)
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->SysLDODriveStrength == kSPC_SysLDO_NormalDriveStrength)
    {
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* When select System LDO voltage level to Over Drive voltage, The HVD of System LDO must be disabled. */
        if (((base->HP_CFG & SPC_HP_CFG_SYS_HVDE_MASK) != 0UL) && /* GCOVR_EXCL_START */
            (option->SysLDOVoltage == kSPC_SysLDO_OverDriveVoltage))
        {
            return kStatus_SPC_SYSLDOOverDriveVoltageFail;
        } /* GCOVR_EXCL_STOP */
    }
    else
    {
        state = (uint32_t)SPC_GetHighPowerModeVoltageDetectStatus(base);

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_SYSLDOLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }

        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_3$.
         */
        /* If select voltage level as Over Drive Voltage, Drive Strength can not be set to low. */
        if (option->SysLDOVoltage == kSPC_SysLDO_OverDriveVoltage) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_SYSLDOLowDriveStrengthIgnore;
        }
    }

    reg = base->HP_CFG;
    reg &= ~(SPC_HP_CFG_SYSLDO_VDD_DS_MASK | SPC_HP_CFG_SYSLDO_VDD_LVL_MASK);
    reg |= SPC_HP_CFG_SYSLDO_VDD_DS(option->SysLDODriveStrength) | SPC_HP_CFG_SYSLDO_VDD_LVL(option->SysLDOVoltage);

    base->HP_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */

/*!
 * brief Configure DCDC regulator in high power mode.
 *
 * param base SPC peripheral base address.
 * param option Pointer to the DCDC regulator configuration, please refer to @ref spc_hp_mode_dcdc_option_t.
 *
 * retval #kStatus_Success Config DCDC regulator in Active power mode successful.
 * retval #kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval #kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval #kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t SPC_SetHighPowerModeDCDCRegulatorConfig(SPC_Type *base, const spc_hp_mode_dcdc_option_t *option)
{
    assert(option != NULL);

    uint32_t reg;
    uint32_t state;

#if SPC_BUSY_TIMEOUT
    uint32_t timeout = SPC_BUSY_TIMEOUT;
#endif

#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    if ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL)
#else
    if ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
        /*
         * $Line Coverage Justification$
         * $ref spc_c_ref_1$.
         */
        return kStatus_SPC_Busy; /* GCOVR_EXCL_LINE */
    }

    if (option->DCDCDriveStrength == kSPC_DCDC_LowDriveStrength)
    {
        state = (uint32_t)SPC_GetHighPowerModeVoltageDetectStatus(base);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_2$.
         */
        /* If any HVD/LVDs are kept enabled write to set drive strength to low will be ignored. */
        if (state != 0UL) /* GCOVR_EXCL_BR_LINE */
        {
            return kStatus_SPC_DCDCLowDriveStrengthIgnore; /* GCOVR_EXCL_LINE */
        }
    }

    reg = base->HP_CFG;
    reg &= ~(SPC_HP_CFG_DCDC_VDD_LVL_MASK | SPC_HP_CFG_DCDC_VDD_DS_MASK);
    reg |= SPC_HP_CFG_DCDC_VDD_DS(option->DCDCDriveStrength) | SPC_HP_CFG_DCDC_VDD_LVL(option->DCDCVoltage);

    base->HP_CFG = reg;

    /*
     * $Branch Coverage Justification$
     * $ref spc_c_ref_1$.
     */
#if defined(FSL_FEATURE_SPC_HAS_SC_REG_BUSY) && FSL_FEATURE_SPC_HAS_SC_REG_BUSY
    while ((base->SC & SPC_SC_REG_BUSY_MASK) != 0UL) /* GCOVR_EXCL_BR_LINE */
#else
    while ((base->SC & SPC_SC_BUSY_MASK) != 0UL)
#endif
    {
#if SPC_BUSY_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    return kStatus_Success;
}

/*!
 * brief Set configuration of regulators in high power mode.
 *
 * param base SPC peripheral base address.
 * param config Pointer to the regulator configuration, please refer to @ref spc_hp_mode_regulators_config_t.
 *
 * retval kStatus_Success Config regulators in High power mode successful.
 * retval kStatus_SPC_BandgapModeWrong The bandgap mode setting in high power mode is wrong.
 * retval kStatus_SPC_Busy The SPC instance is busy to execute any type of power mode transition.
 * retval kStatus_SPC_CORELDOVoltageWrong The selected voltage level in high mode is not allowed.
 * retval kStatus_SPC_SYSLDOOverDriveVoltageFail Fail to regulator to Over Drive Voltage.
 * retval kStatus_SPC_SYSLDOLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 * retval kStatus_SPC_DCDCLowDriveStrengthIgnore Set driver strength to Low will be ignored.
 */
status_t SPC_SetHighPowerModeRegulatorsConfig(SPC_Type *base, const spc_hp_mode_regulators_config_t *config)
{
    assert(config != NULL);

    status_t status;

    status = SPC_SetHighPowerModeCoreLDORegulatorConfig(base, &config->CoreLDOOption);
    if (status == kStatus_Success)
    {
        status = SPC_SetHighPowerModeDCDCRegulatorConfig(base, &config->DCDCOption);
        /*
         * $Branch Coverage Justification$
         * $ref spc_c_ref_5$.
         */
        if (status == kStatus_Success) /* GCOVR_EXCL_BR_LINE */
        {
#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
            /*
             * $Line Coverage Justification$
             * $ref spc_c_ref_5$.
             */
            status = SPC_SetHighPowerModeSystemLDORegulatorConfig(base, &config->SysLDOOption); /* GCOVR_EXCL_LINE */
            /*
             * $Line Coverage Justification$
             * $ref spc_c_ref_5$.
             */
            /* GCOVR_EXCL_START */
            if (status == kStatus_Success)
            {
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */
                /* GCOVR_EXCL_START */
                status = SPC_SetHighPowerModeBandgapModeConfig(base, config->bandgapMode);
#if (defined(FSL_FEATURE_SPC_HAS_LPBUFF) && FSL_FEATURE_SPC_HAS_LPBUFF)
                if (status == kStatus_Success) /* GCOVR_EXCL_BR_LINE */
                {
                    SPC_EnableHighPowerModeCMPBandgapBuffer(base, config->lpBuff);
                }
#endif /* FSL_FEATURE_SPC_HAS_LPBUFF */
                /* GCOVR_EXCL_STOP */
#if (defined(FSL_FEATURE_SPC_HAS_SYS_LDO) && FSL_FEATURE_SPC_HAS_SYS_LDO)
            }
            /* GCOVR_EXCL_STOP */
#endif /* FSL_FEATURE_SPC_HAS_SYS_LDO */
        }
    }
    return status;
}

#endif /* (defined(FSL_FEATURE_SPC_HAS_HP_CFG_REG) && FSL_FEATURE_SPC_HAS_HP_CFG_REG) */

/*!
 * brief Configures VDD Core Glitch detector, including ripple counter selection, timeout value and so on.
 *
 * param base SPC peripheral base address.
 * param config Pointer to the structure in type of spc_vdd_core_glitch_detector_config_t.
 */
void SPC_ConfigVddCoreGlitchDetector(SPC_Type *base, const spc_vdd_core_glitch_detector_config_t *config)
{
    assert(config != NULL);

    uint32_t reg;

    reg = (base->VDD_CORE_GLITCH_DETECT_SC) &
          ~(SPC_VDD_CORE_GLITCH_DETECT_SC_CNT_SELECT_MASK | SPC_VDD_CORE_GLITCH_DETECT_SC_TIMEOUT_MASK |
            SPC_VDD_CORE_GLITCH_DETECT_SC_RE_MASK | SPC_VDD_CORE_GLITCH_DETECT_SC_IE_MASK);

    reg |= SPC_VDD_CORE_GLITCH_DETECT_SC_CNT_SELECT(config->rippleCounterSelect) |
           SPC_VDD_CORE_GLITCH_DETECT_SC_TIMEOUT(config->resetTimeoutValue) |
           /* INT31-C: Use conditional expression for bool to unsigned long conversion */
           SPC_VDD_CORE_GLITCH_DETECT_SC_RE(config->enableReset ? 1U : 0U) |
           SPC_VDD_CORE_GLITCH_DETECT_SC_IE(config->enableInterrupt ? 1U : 0U);

    base->VDD_CORE_GLITCH_DETECT_SC = reg;
}

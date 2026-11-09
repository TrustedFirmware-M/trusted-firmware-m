# SPC

## [2.10.0]

- New Features
  - Added SPC_EnableRegulators()/SPC_DisableRegulators() to enable or disable the Core LDO,
    System LDO, and DCDC regulators together with a single write to SPC->CNTRL. On devices
    such as KW45/KW47 where SPC->CNTRL accepts only one write in total between POR/LVD/HVD
    events, calling the existing per-regulator enable functions one after another only
    applies the first call; the new combined API avoids that hazard.

## [2.9.0]

- New Features
  - Added VDD1P8 low-voltage detect APIs (config, Active/LP/HP enable, status flag)
    guarded by FSL_FEATURE_SPC_HAS_VDD1P8_LVD for SPC variants that monitor the
    VDD_FRO rail.
  - Added kSPC_PowerDomain3 and kSPC_INFRAPowerDomainRetain for SPC variants with
    a 4-domain topology.
  - Added VDD_GLITCH_DETECT_SC -> VDD_CORE_GLITCH_DETECT_SC alias block so both
    GLITCH_DETECT_SC and VDD_GLITCH_DETECT_SC register names resolve to a single
    unified set of driver macros.

- Improvements
  - Guarded DCDC_CFG FREQ_CNTRL access with FSL_FEATURE_SPC_HAS_NO_DCDC_FREQ_CNTRL
    for SPC variants that omit the frequency-control field.
  - Extended VD_STAT valid-flags mask to include VDD1P8 and composed it from
    per-domain sub-masks for cleaner compile-time selection.

- Bug Fixes
  - Fixed MISRA C-2012 Rule 14.3 violation in `SPC_SetHighPowerModeRegulatorsConfig`:
    moved `if (status == kStatus_Success)` guard for bandgap config inside the
    `FSL_FEATURE_SPC_HAS_SYS_LDO` conditional block so the condition is only present
    when `status` can actually change (i.e. when SYS LDO is configured).

## [2.8.3]

- Bug Fixes
  - Fixed voltage detect status accumulation in Active, High Power, and Low Power mode helpers so VDD_SYS status bits are returned correctly when present.

## [2.8.2]

- Bug Fixes
  - Mask voltage detect status bits to return only valid SPC VD status flags.
  - Mask external domain status bits before shifting to return only EVDSTAT field values.


## [2.8.1]

- Bug Fixes
  - Add explicit boolean to integer conversions (? 1U : 0U) for enable flags in DCDC burst configuration.
  - Add explicit boolean to integer conversions (? 1U : 0U) for reset and interrupt
    enable flags in VDD core glitch detector.
  - Follow INT31-C CERT coding standard for safe boolean to unsigned long conversions.


## [2.8.0]

- Improvements
  - Added feature macros to support some platforms which do not have system LDO, VDD_SYS, DCDC_BURST_CFG.


- Bug Fixes
  - Fixed doxygen warnings:
    1. unbalanced grouping commands.
    2. Argument 'base' of command @param is not found in the argument
      list of sfa_callback_t(status_t status)
    3. Explicit link request to 'kStatus_SPC_CORELDOVoltageSetFail.' could not be resolved


## [2.7.1]

- Improvements
  - Make configuration structure pointers const in SPC driver API for Higher Power mode

## [2.7.0]

- Improvements
  - Added new APIs to control VDD Core Glitch Detector.

## [2.6.1]

- Improvements
  - Add timeout for while loop code.

## [2.6.0]

- New Features
  - Added new feature FSL_FEATURE_SPC_HAS_SC_SPC_LP_REQ_BIT for compatibility with
    new platforms that do not support the SPC SC[SPC_LP_REQ] bitfield.

## [2.5.0]

- New Features
  - Added new function group to support high power feature.

## [2.4.1]

- Improvements
  - Added the new feature FSL_FEATURE_SPC_HAS_SC_REG_BUSY to support the device which has the SC[REG_BUSY] bitfield.

## [2.4.0]

- Improvements
  - Set functions of VD_SYS_CFG[LVSEL] configuration as deprecated,
    since this bit filed is reserved for all devices.

## [2.3.0]

- Improvements

  - Added SPC_SetSRAMOperateVoltage() to set SRAM operate voltage.

- Bug Fixes

  - Fixed the issue in SPC_SetDCDCBurstConfig() function.
  - Fixed a bug that is SPC has VDD_DS the voltage is not configured correctly.

## [2.2.0]

- Bug Fixes

  - The default value of ACTIVE_CFG[CORELDO_VDD_DS] bit is 1, removed code of set that bit.
  - Fixed an issue of SPC_SetDCDCBurstConfig() to avoid program stuck in a while loop.
  - Removed some duplicate code that never reached.

- Improvements

  - Added two APIs to control Vdd core glitch detect feature in Active/lowpower modes.

## [2.1.0]

- Improvements

  - Improved the spc_dcdc_voltage_level_t enumeration.
  - Added some low power request check APIs.
  - Added SPC_SoftwareGatePowerSwitch() and SPC_PowerModeControlPowerSwitch() function.
  - If APIs' parameters is in type of structure pointer, set it to const structure pointer.

- Bug Fixes

  - Fixed the issue in SPC_SetDCDCRefreshCount() function.
  - Fixed some issues in voltage detect enable APIs.
  - Fixed some issues in Bandgap control APIs.
  - Fixed some issues in regulator active/lowpower mode configuration APIs.

## [2.0.2]

- Bug Fixes
  - Fixed the doxygen issue by adding missed comments.

## [2.0.1]

- Bug Fixes
  - The enumerator spc_core_ldo_voltage_level_t may different for different devices,
    added the macro to separate different scenes.

## [2.0.0]

- Initial version.

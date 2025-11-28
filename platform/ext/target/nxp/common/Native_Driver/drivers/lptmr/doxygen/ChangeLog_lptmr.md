# LPTMR

## [2.2.1]

- Bug Fixes
  - Fix CERT INT31-C issues.

## [2.2.0]

- Improvements
  - Updated lptmr_prescaler_clock_select_t, only define the valid options.

## [2.1.1]

- Improvements
  - Updated the characters from "PTMR" to "LPTMR" in "FSL_FEATURE_PTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_1_SUPPORT"
    feature definition.

## [2.1.0]

- Improvements
  - Implement for some special devices' not supporting for all clock sources.
- Bug Fixes
  - Fixed issue when accessing CMR register.

## [2.0.2]

- Bug Fixes
  - Fixed MISRA-2012 issues.
    - Rule 10.1.

## [2.0.1]

- Improvements
  - Updated the LPTMR driver to support 32-bit CNR and CMR registers in some devices.

## [2.0.0]

- Initial version.

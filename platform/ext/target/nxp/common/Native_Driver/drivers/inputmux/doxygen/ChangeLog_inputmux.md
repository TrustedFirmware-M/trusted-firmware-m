# INPUTMUX

## [2.0.11]

- Bug Fixes
  - Fixed Coverity UNUSED_VALUE finding in INPUTMUX_EnableSignal().

## [2.0.10]

- Bug Fixes
  - Fixed CERT-C violations.

## [2.0.9]

- Improvements
  - Use INPUTMUX_CLOCKS to initialize the inputmux module clock to adapt to multiple inputmux instances.
  - Modify the API base type from INPUTMUX_Type to void.

## [2.0.8]

- Improvements
  - Updated a feature macro usage for function INPUTMUX_EnableSignal.

## [2.0.7]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.0.6]

- Bug Fixes
  - Fixed the documentation wrong in API INPUTMUX_AttachSignal.

## [2.0.5]

- Bug Fixes
  - Fixed build error because some devices has no sct.

## [2.0.4]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rule 10.4, 12.2 in
    INPUTMUX_EnableSignal() function.

## [2.0.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.4, 10.7, 12.2.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.4, 12.2.

## [2.0.1]

- Support channel mux setting in INPUTMUX_EnableSignal().

## [2.0.0]

- Initial version.

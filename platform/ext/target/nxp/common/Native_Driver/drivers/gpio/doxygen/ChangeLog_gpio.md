# GPIO

## [2.8.6]
- Bug Fixes
  - Fixed CERT INT31-C violations in `GPIO_FIT_REG` macro for platforms with 8-bit register width.

## [2.8.5]
- Improvements
  - Add AND logic in GPIO_GpioClearInterruptFlags to support clearing multiple interrupt flags simultaneously.

## [2.8.4]
- Improvements
  - Make function `GPIO_PortGetInterruptFlags` and `GPIO_PortClearInterruptFlags`
    available for all variants, they are used for all pins flags in one GPIO port.

## [2.8.3]
- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 5.7.

## [2.8.2]
- Bug Fixes
  - Fixed COVERITY issue that GPIO_GetInstance could return clock array overflow values due to GPIO base and clock being out of sync.

## [2.8.1]

- Bug Fixes
  - Fixed CERT INT31-C issues.

## [2.8.0]

- Improvements
  - Add API GPIO_PortInit/GPIO_PortDeinit to set GPIO clock enable and releasing GPIO reset.

## [2.8.0]

- Improvements
  - Add API GPIO_PortInit/GPIO_PortDeinit to set GPIO clock enable and releasing GPIO reset.
  - Remove support for API GPIO_GetPinsDMARequestFlags with GPIO_ISFR_COUNT <= 1.

## [2.7.3]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.7.2]

- New Features
  - Support devices without PORT module.

## [2.7.1]

- Bug Fixes
  - Fixed MISRA C-2012 rule 10.4 issues in GPIO_GpioGetInterruptChannelFlags() function and GPIO_GpioClearInterruptChannelFlags() function.

## [2.7.0]

- New Features
  - Added API to support Interrupt select (IRQS) bitfield.

## [2.6.0]

- New Features
  - Added API to get GPIO version information.
  - Added API to control a pin for general purpose input.
  - Added some APIs to control pin in secure and previliege status.

## [2.5.3]

- Bug Fixes
  - Correct the feature macro typo: FSL_FEATURE_GPIO_HAS_NO_INDEP_OUTPUT_CONTORL.

## [2.5.2]

- Improvements
  - Improved GPIO_PortSet/GPIO_PortClear/GPIO_PortToggle functions to support devices without Set/Clear/Toggle registers.

## [2.5.1]

- Bug Fixes

  - Fixed wrong macro definition.
  - Fixed MISRA C-2012 rule issues in the FGPIO_CheckAttributeBytes() function.
  - Defined the new macro to separate the scene when the width of registers is different.
  - Removed some redundant macros.

- New Features

  - Added some APIs to get/clear the interrupt status flag
    when the port doesn't control pins' interrupt.

## [2.4.1]

- Improvements
  - Improved GPIO_CheckAttributeBytes() function to support 8 bits width GACR register.

## [2.4.0]

- Improvements
  - API interface added:
    - New APIs were added to configure the GPIO interrupt clear settings.

## [2.3.2]

- Bug Fixes
  - Fixed the issue for MISRA-2012 check.
    - Fixed rule 3.1, 10.1, 8.6, 10.6, and 10.3.

## [2.3.1]

- Improvements
  - Removed deprecated APIs.

## [2.3.0]

- New Features
  - Updated the driver code to adapt the case of interrupt configurations in GPIO module. New APIs were added
    to configure the GPIO interrupt settings if the module has this feature on it.

## [2.2.1]

- Improvements
  - API interface changes:
    - Refined naming of APIs while keeping all original APIs by marking them
      as deprecated. The original APIs will be removed in next release. The
      main change is updating APIs with prefix of _PinXXX() and
      _PortXXX.

## [2.1.1]

- Improvements
  - API interface changes:
    - Added an API for the check attribute bytes.

## [2.1.0]

- Improvements
  - API interface changes:
    - Added "pins" or "pin" to some APIs' names.
    - Renamed "_PinConfigure" to "GPIO_PinInit".

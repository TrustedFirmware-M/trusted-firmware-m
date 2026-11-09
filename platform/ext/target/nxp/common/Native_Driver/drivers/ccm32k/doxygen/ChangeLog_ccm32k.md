# CCM32K

## [2.2.2]

- Bug Fixes
  - Fixed MISRA C-2012 Rule 10.1 violation in `CCM32K_SetClockMonitorConfig`:
    changed `assert(config)` to `assert(config != NULL)`.

## [2.2.1]

- Bug Fixes
  - Fixed doxygen warning: unbalanced grouping commands.

## [2.2.0]

- Improvements
  - Removed wait loops in CCM32K's APIs.

## [2.1.1]

- Improvements
  - Updated the judgment conditions in the CCM32K_Enable32kFro() API to avoid code stuck in the while loop.

## [2.1.0]

- New Features
  - Added clock monitor control function group and clock gate control function
    group to support some devices that support clock monitor and clock gate control.

## [2.0.0]

- Initial version.

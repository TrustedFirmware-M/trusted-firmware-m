# GPIO

## [2.1.7]

- Improvements
  - Enhanced GPIO_PinInit to enable clock internally.

## [2.1.6]

- Bug Fixes
  - Clear bit before set it within GPIO_SetPinInterruptConfig() API.

## [2.1.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 3.1, 10.6, 10.7, 17.7.

## [2.1.4]

- Improvements
  - Added API GPIO_PortGetInterruptStatus to retrieve interrupt status for
    whole port.
  - Corrected typos in header file.

## [2.1.3]

- Improvements
  - Updated "GPIO_PinInit" API. If it has DIRCLR and DIRSET registers, use them at set 1 or clean 0.

## [2.1.2]

- Improvements
  - Removed deprecated APIs.

## [2.1.1]

- Improvements
  - API interface changes:
    - Refined naming of APIs while keeping all original APIs, marking them
      as deprecated. Original APIs will be removed in next release. The
      mainin change is updating APIs with prefix of _PinXXX() and
      _PorortXXX

## [2.1.0]

- New Features
  - Added GPIO initialize API.

## [2.0.0]

- Initial version.

# PORT

## [2.5.1]

- Bug Fixes
  - Fix CERT INT31-C issues.
  - Fixed the violations of MISRA C-2012 rules: 10.1.

## [2.5.0]

- Bug Fixes
  - Correct the kPORT_MuxAsGpio for some platforms.

## [2.4.1]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules: 10.1, 10.8 and 14.4.

## [2.4.0]

- New Features
  - Updated port_pin_config_t to support input buffer and input invert.

## [2.3.0]

- New Features
  - Added new APIs for Electrical Fast Transient(EFT) detect.
  - Added new API to configure port voltage range.

## [2.2.0]

- New Features
  - Added new api PORT_EnablePinDoubleDriveStrength.

## [2.1.1]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules: 10.1, 10.4，11.3，11.8, 14.4.

## [2.1.0]

- New Features
  - Updated the driver code to adapt the case of the interrupt configurations in GPIO module. Will move
    the pin configuration APIs to GPIO module.

## [2.0.2]

- Other Changes
  - Added feature guard macros in the driver.

## [2.0.1]

- Other Changes
  - Added "const" in function parameter.
  - Updated some enumeration variables' names.

# TRNG

## [2.0.23]

- New features:
  - Updated TRNG default values for MCXA577 devices based on silicon characterization.

## [2.0.22]

- New features:
  - Added support for KW43 and MCXW70 devices.

## [2.0.21]

- New features:
  - Added support for MCXC devices.

## [2.0.20]

- New features:
  - Added support for MCXA devices.
  
## [2.0.19]

- New features:
  - Added support for MCXA and MCXL.

## [2.0.18]

- Bug fix:
  - TRNG health checks now done in software on RT5xx and RT6xx.

## [2.0.17]

- New features:
  - Add support for RT700.

## [2.0.16]

- Improvements:
  - Added support for Dual oscillator mode.

## [2.0.15]

- Other changes:
  - Changed TRNG_USER_CONFIG_DEFAULT_XXX values according to latest reccomended by design team.

## [2.0.14]

- New features:
  - Add support for RW610 and RW612.

## [2.0.13]

- Bug fix:
  - After deepsleep it might return error, added clearing bits in TRNG_GetRandomData() and generating new entropy.
  - Modified reloading entropy in TRNG_GetRandomData(), for some data length it doesn't reloading entropy correctly.

## [2.0.12]

- Bug fix:
  - For KW34A4_SERIES, KW35A4_SERIES, KW36A4_SERIES set TRNG_USER_CONFIG_DEFAULT_OSC_DIV to kTRNG_RingOscDiv8.

## [2.0.11]

- Bug fix:
  - Add clearing pending errors in TRNG_Init().

## [2.0.10]

- Bug Fix:
  - Fixed doxygen issues.

## [2.0.9]

- Bug Fix:
  - Fix HIS_CCM metrics issues.

## [2.0.8]

- Bug fix:
  - For K32L2A41A_SERIES set TRNG_USER_CONFIG_DEFAULT_OSC_DIV to kTRNG_RingOscDiv4.

## [2.0.7]

- Bug fix:
  - Fix MISRA 2004 issue rule 12.5.

## [2.0.6]

- Bug fix:
  - For KW35Z4_SERIES set TRNG_USER_CONFIG_DEFAULT_OSC_DIV to kTRNG_RingOscDiv8.

## [2.0.5]

- Improvements:
  - For FRQMIN, FRQMAX and OSCDIV, add possibility to use device specific preprocessor macro
    to define default value in TRNG user configuration structure.

## [2.0.4]

- Bug Fix:
  - Fix MISRA-2012 issues.
    - Rule 10.1, rule 10.3, rule 13.5, rule 16.1.

## [2.0.3]

- Improvements:
  - update TRNG_Init to restart new entropy generation.

## [2.0.2]

- Improvements:
  - fix MISRA issues
    - Rule 14.4.

## [2.0.1]

- New features:

  - Set default OSCDIV for Kinetis devices KL8x and KL28Z.

- Other changes:

  - Changed default OSCDIV for K81 to divide by 2.

## [2.0.0]

- Initial version.

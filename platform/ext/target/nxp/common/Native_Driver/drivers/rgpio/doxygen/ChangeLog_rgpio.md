# RGPIO

## [2.1.0]

- New feature:
  - Added API RGPIO_EnablePortInput()
  - Added API RGPIO_SetPinInterruptConfig()
  - Added API RGPIO_GetPinsInterruptFlags()
  - Added API RGPIO_ClearPinsInterruptFlags()

## [2.0.3]

- Improvements:
  - Enhanced FGPIO_PinInit to enable clock internally.

## [2.0.2]

- Bug fix
  - MISRA C-2012 issue fixed.
    - Fix rules, containing: rule-10.3, rule-14.4, rule-15.5.

## [2.0.1]

- API Interface Change:
  - Refined naming of API while keep all original APIs with marking them
    as deprecated. The original API will be removed in the next release. The
    main change is to update API with prefix of _PinXXX() and
    _PortXXX().

## [2.0.0]

- Initial version.

# LPFLEXCOMM

## [2.2.1]

- Bug Fix
  - Fixed the bug that function LPFLEXCOMM_GetBaseAddr() type was uint32_t,but return NULL((void*)0).

## [2.2.0]

- New Features
  - Added new API to get LPFLEXCOMM base address.

## [2.1.2]

- Bug Fix
  - Fixed the bug that when the same instance is initialized multiple times, all previous states will be cleared and only the last state will be retained.

## [2.1.1]

- New Features
  - Supported new platform that has more lpflexcomm instance.

## [2.1.0]

- Improvements
  - Function LP_FLEXCOMM_SetPeriph changed from public to private,function LP_FLEXCOMM_Init no longer judges the periph.

## [2.0.0]

- Initial version.

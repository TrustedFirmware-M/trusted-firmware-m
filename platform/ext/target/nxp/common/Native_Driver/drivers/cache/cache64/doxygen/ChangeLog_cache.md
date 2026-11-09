# CACHE64

## [2.0.14]

- Bug Fixes
  - Fixed boundary check in CACHE64_GetInstanceByAddr() to correctly include the last address of the memory range.

## [2.0.13]

- Bug Fixes
  - Fix issue in CACHE64_InvalidateCacheByRange(), CACHE64_CleanCacheByRange() and CACHE64_CleanInvalidateCacheByRange() functions to avoid cleaning/invalidation less cache lines than expected.

## [2.0.12]

- Improvements
  - Add memory barrier when enabling/disabling cache.

## [2.0.11]

- Bug Fixes
  - Fixed CERT INT30-C violations: check and guarantee address plus size is equal or smaller than UINT32_MAX.

## [2.0.10]

- Improvements
  - Updated CACHE64_InvalidateCacheByRange(), CACHE64_CleanCacheByRange() and CACHE64_CleanInvalidateCacheByRange() to
    support some platforms that multiple regions in the memory map are remapped to create a continuous address space.

## [2.0.9]

- Improvements
  - Removed assert(false) in CACHE64_GetInstanceByAddr.

## [2.0.8]

- Improvements
  - Updated function CACHE64_GetInstanceByAddr() to support some devices
    that provide alias of cacheable memory section.

## [2.0.7]

- Improvements
  - Check input parameter "size_byte" must be larger than 0.

## [2.0.6]

- Bug Fixes
  - Fixed overflow for CACHE64_GetInstanceByAddr()/CACHE64_CleanCacheByRange()/CACHE64_InvalidateCacheByRange() APIs.

## [2.0.5]

- Improvement
  - Made use of FSL_FEATURE_CACHE64_CTRL_HAS_NO_WRITE_BUF feature

## [2.0.4]

- Improvement
  - Disable cache policy feature on SoC without CACHE64_POLSEL IP.
- Bug Fixes
  - Fixed doxygen issue.

## [2.0.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.3.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3, 10.4 and 14.4.
  - Fixed doxygen issue.

## [2.0.1]

- Improvements
  - Moved CLCR register configuration out of the while loop, it's unnecessary to repeat this operation.

## [2.0.0]

- Initial version.

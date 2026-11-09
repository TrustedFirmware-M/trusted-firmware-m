# CACHE XCACHE

## [2.0.6]

- Improvements
  - Add assert in XCACHE_GetInstanceByAddr() to check out-of-range address.

## [2.0.5]

- Bug Fixes
  - Fixed boundary check in XCACHE_GetInstanceByAddr() to correctly include the last address of the memory range.

## [2.0.4]

- Improvements
  - Add memory barrier when enabling/disabling cache.

## [2.0.3]

- Bug Fixes
  - Fixed CERT INT30-C violations.

## [2.0.2]

- Bug Fixes
  - Updated XCACHE_InvalidateCacheByRange(), XCACHE_CleanCacheByRange(),
    XCACHE_CleanInvalidateCacheByRange() in case of startAddr equal to endAddr.

## [2.0.1]

- Improvements
  - Check input parameter "size_byte" must be larger than 0.

## [2.0.0]

- Initial version.

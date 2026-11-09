# COMMON

## [2.6.7]

- Improvements
  - EnableIRQ/DisableIRQ: Use IRQSTEER_GetInstIdxByIRQ() to determine IRQSTEER
    instance index instead of simple division. Supports multiple IRQSTEER instances
    with different interrupt counts.

## [2.6.6]

- Improvements
  - Support Cortex M55.

## [2.6.5]
- Bug Fixes
  - Fixed the issue that the function SDK_DelayAtLeastUs may underflow and 
    cause a long delay when the input parameter is small and the system clock is low.

## [2.6.4]

- New Features
  - Add macros to tag deprecated features and experimental features.

## [2.6.3]

- New Features
  - Added bit mask inversion macros to avoid type promotion.
  - Added register operation macros.
- Improvements
  - Make function `MSDK_EnableCpuCycleCounter` compatible with CMSIS-5 and CMSIS-6.

- Bug Fixes
  - Fixed build issue of CMSIS PACK BSP example caused by CMSIS 6.1 issue.
## [2.6.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule for implicit conversions in boolean contexts

## [2.6.1]

- Improvements
  - Support Cortex M23.

## [2.6.0]

- Bug Fixes
  - Fix CERT-C violations.

## [2.5.0]

- New Features
  - Added new APIs InitCriticalSectionMeasurementContext, DisableGlobalIRQEx and
    EnableGlobalIRQEx so that user can measure the execution time of the protected sections.

## [2.4.3]

- Improvements
  - Enable irqs that mount under irqsteer interrupt extender.

## [2.4.2]

- Improvements
  - Add the macros to convert peripheral address to secure address or non-secure address.

## [2.4.1]

- Improvements
  - Improve for the macro redefinition error when integrated with zephyr.

## [2.4.0]

- New Features
  - Added EnableIRQWithPriority, IRQ_SetPriority, and IRQ_ClearPendingIRQ for ARM.
  - Added MSDK_EnableCpuCycleCounter, MSDK_GetCpuCycleCount for ARM.

## [2.3.3]

- New Features
  - Added NETC into status group.

## [2.3.2]

- Improvements
  - Make driver aarch64 compatible

## [2.3.1]

- Bug Fixes
  - Fixed MAKE_VERSION overflow on 16-bit platforms.

## [2.3.0]

- Improvements
  - Split the driver to common part and CPU architecture related part.

## [2.2.10]

- Bug Fixes
  - Fixed the ATOMIC macros build error in cpp files.

## [2.2.9]

- Bug Fixes
  - Fixed MISRA C-2012 issue, 5.6, 5.8, 8.4, 8.5, 8.6, 10.1, 10.4, 17.7, 21.3.
  - Fixed SDK_Malloc issue that not allocate memory with required size.

## [2.2.8]

- Improvements
  - Included stddef.h header file for MDK tool chain.
- New Features:
  - Added atomic modification macros.

## [2.2.7]

- Other Change
  - Added MECC status group definition.

## [2.2.6]

- Other Change
  - Added more status group definition.
- Bug Fixes
  - Undef __VECTOR_TABLE to avoid duplicate definition in cmsis_clang.h

## [2.2.5]

- Bug Fixes
  - Fixed MISRA C-2012 rule-15.5.

## [2.2.4]

- Bug Fixes
  - Fixed MISRA C-2012 rule-10.4.

## [2.2.3]

- New Features
  - Provided better accuracy of SDK_DelayAtLeastUs with DWT, use macro SDK_DELAY_USE_DWT to enable this feature.
  - Modified the Cortex-M7 delay count divisor based on latest tests on RT series boards, this
    setting lets result be closer to actual delay time.

## [2.2.2]

- New Features
  - Added include RTE_Components.h for CMSIS pack RTE.

## [2.2.1]

- Bug Fixes
  - Fixed violation of MISRA C-2012 Rule 3.1, 10.1, 10.3, 10.4, 11.6, 11.9.

## [2.2.0]

- New Features
  - Moved SDK_DelayAtLeastUs function from clock driver to common driver.

## [2.1.4]

- New Features
  - Added OTFAD into status group.

## [2.1.3]

- Bug Fixes
  - MISRA C-2012 issue fixed.
    - Fixed the rule: rule-10.3.

## [2.1.2]

- Improvements
  - Add SUPPRESS_FALL_THROUGH_WARNING() macro for the usage of suppressing fallthrough warning.

## [2.1.1]

- Bug Fixes
  - Deleted and optimized repeated macro.

## [2.1.0]

- New Features
  - Added IRQ operation for XCC toolchain.
  - Added group IDs for newly supported drivers.

## [2.0.2]

- Bug Fixes
  - MISRA C-2012 issue fixed.
    - Fixed the rule: rule-10.4.

## [2.0.1]

- Improvements
  - Removed the implementation of LPC8XX Enable/DisableDeepSleepIRQ() function.
  - Added new feature macro switch "FSL_FEATURE_HAS_NO_NONCACHEABLE_SECTION" for
    specific SoCs which have no noncacheable sections,
    that helps avoid an unnecessary complex in link file and the startup file.
  - Updated the align(x) to **attribute**(aligned(x)) to support MDK v6 armclang compiler.

## [2.0.0]

- Initial version.

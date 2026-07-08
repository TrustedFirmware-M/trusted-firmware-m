#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2026 Texas Instruments Incorporated
#
# CPU architecture configuration for LP_MSPM33C321A
#
# Specifies ARM Cortex-M33 (ARMv8-M mainline) architecture and compilation flags.
# MSPM33C321A features:
#   - ARM Cortex-M33 processor
#   - TrustZone-M security extensions
#   - Floating-point unit (FPv5-SP-D16)
#   - DSP extensions
#
#-------------------------------------------------------------------------------

# CPU architecture and system properties
# TFM_SYSTEM_PROCESSOR must be "cortex-m33" (without suffixes) so that
# tf-m-tests string-replaces it to "ARMCM33" and selects ARMCM33_TZ.h.
# DSP/FP are suppressed via TFM_SYSTEM_DSP=OFF and COMPILER_CP_FLAG (+nofp+nodsp).
# mcpu_features.cmake in tf-m-tests will append +nodsp+nofp automatically.
set(TFM_SYSTEM_PROCESSOR cortex-m33)
set(TFM_SYSTEM_ARCHITECTURE armv8-m.main)
set(TFM_SYSTEM_DSP OFF)

# Compiler flags for Cortex-M33 (software float, no DSP)
set(COMPILER_CP_FLAG        "-mcpu=cortex-m33+nofp+nodsp")
set(COMPILER_C_FLAGS        "-mthumb")
set(COMPILER_FPU_FLAG       "-mfloat-abi=soft")
set(COMPILER_CMSE_FLAG      "-mcmse")

# Combined flags for common platform builds
set(COMMON_COMPILE_FLAGS
    ${COMPILER_CP_FLAG}
    ${COMPILER_C_FLAGS}
    ${COMPILER_FPU_FLAG}
)
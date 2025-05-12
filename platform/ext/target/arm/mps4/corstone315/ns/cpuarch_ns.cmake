#-------------------------------------------------------------------------------
# Copyright (c) 2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(TARGET_PLATFORM_PATH    ${CMAKE_CURRENT_LIST_DIR})

# Set architecture and CPU
set(TFM_SYSTEM_PROCESSOR cortex-m85)
set(TFM_SYSTEM_ARCHITECTURE armv8.1-m.main)

set(CONFIG_TFM_FP_ARCH "fpv5-d16")
set(CONFIG_TFM_FP_ARCH_ASM "FPv5_D16")

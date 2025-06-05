#-------------------------------------------------------------------------------
# Copyright (c) 2022-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

########################## FPU and MVE #########################################

tfm_invalid_config(CMAKE_C_COMPILER_ID STREQUAL "IAR" AND (CONFIG_TFM_ENABLE_MVE OR CONFIG_TFM_ENABLE_MVE_FP))
tfm_invalid_config((NOT CONFIG_TFM_FP_ARCH) AND (CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE_FP))
tfm_invalid_config((CMAKE_C_COMPILER_ID STREQUAL "ARMClang") AND (NOT CONFIG_TFM_FP_ARCH_ASM) AND CONFIG_TFM_ENABLE_FP)
tfm_invalid_config((NOT CONFIG_TFM_ENABLE_FP AND NOT CONFIG_TFM_ENABLE_MVE AND NOT CONFIG_TFM_ENABLE_MVE_FP) AND CONFIG_TFM_LAZY_STACKING)
tfm_invalid_config((CONFIG_TFM_ENABLE_FP OR CONFIG_TFM_ENABLE_MVE OR CONFIG_TFM_ENABLE_MVE_FP) AND NOT CONFIG_TFM_ENABLE_CP10CP11)
tfm_invalid_config(CONFIG_TFM_ENABLE_CP10CP11 AND CONFIG_TFM_DISABLE_CP10CP11)

#-------------------------------------------------------------------------------
# Copyright (c) 2023, Arm Limited. All rights reserved.
# Copyright (C) 2024 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# In the new split build this file defines a platform specific parameters
# like mcpu core, arch etc and to be included by toolchain files.

set(TFM_SYSTEM_PROCESSOR         cortex-m33)
set(TFM_SYSTEM_ARCHITECTURE      armv8-m.main)
set(CONFIG_TFM_FP_ARCH           "fpv5-sp-d16")
set(CONFIG_TFM_ENABLE_FP         OFF)
set(CONFIG_TFM_ENABLE_CP10CP11 ON)

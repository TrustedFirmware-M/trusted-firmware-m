#-------------------------------------------------------------------------------
# Portions Copyright (C) 2024 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(BL2                                 ON         CACHE BOOL     "Whether to build BL2")

set(HAL_ADI_PATH                        "DOWNLOAD"  CACHE PATH      "Path to hal_adi (or DOWNLOAD to fetch automatically")
set(HAL_ADI_VERSION                     "dd1c525"   CACHE STRING    "The version of hal_adi to use")

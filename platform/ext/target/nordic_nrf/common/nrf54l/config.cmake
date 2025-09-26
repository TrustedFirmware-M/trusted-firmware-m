#-------------------------------------------------------------------------------
# Copyright (c) 2020, Nordic Semiconductor ASA.
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${PLATFORM_PATH}/common/core/config.cmake)

set(BL2                                 OFF        CACHE BOOL      "Whether to build BL2" FORCE)
set(NRF_NS_SECONDARY                    OFF        CACHE BOOL      "Enable non-secure secondary partition" FORCE)

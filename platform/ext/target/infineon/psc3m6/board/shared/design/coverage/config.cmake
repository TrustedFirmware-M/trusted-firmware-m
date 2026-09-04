#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(IFX_ENABLE_HW_PERI_IN_STARTUP           ON)

##################################### BL2 ######################################
set(BL2                                     OFF         CACHE BOOL      "Whether to build BL2")
set(BL2_HEADER_SIZE                         0x0         CACHE STRING    "BL2 Header size")
set(BL2_TRAILER_SIZE                        0x0         CACHE STRING    "BL2 Trailer size")

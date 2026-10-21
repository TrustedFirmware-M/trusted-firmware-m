#-------------------------------------------------------------------------------
# (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_FLIH_IRQ_TEST_SUPPORT          ON)
set(PLATFORM_SLIH_IRQ_TEST_SUPPORT          ON)

# Enable multi core tests support for when MTB mailbox is enabled
if(IFX_MTB_MAILBOX)
    set(PLATFORM_MULTI_CORE_TEST_SUPPORT    ON CACHE BOOL "Whether platform has multi core tests support")
endif()

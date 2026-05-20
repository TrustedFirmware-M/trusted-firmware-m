#-------------------------------------------------------------------------------
# Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Prevent multiple inclusions
include_guard()

# Core identifiers used across all Infineon platforms.
set(IFX_CM33 "cm33")
set(IFX_CM55 "cm55")

# Compile definitions for available cores
add_compile_definitions(IFX_CM33=33)
add_compile_definitions(IFX_CM55=55)

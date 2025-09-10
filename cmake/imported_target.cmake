#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

macro(add_imported_target target build_target output_path)
    add_executable(${target} IMPORTED GLOBAL)
    set_target_properties(${target} PROPERTIES
        IMPORTED_LOCATION "${output_path}"
    )
    add_dependencies(${target} ${build_target})
endmacro()

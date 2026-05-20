#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${IFX_COMMON_SOURCE_DIR}/cmake/utils.cmake)

# Adds code coverage flags to all infineon files that are built, excluding EXCLUDE
#
# EXCLUDE - list of regex match expressions to exclude, see string (REGEX MATCH)
# FILTER_FILE - path to the file containing the list of files to include in code coverage.
function(ifx_add_code_coverage)
    set(options "")
    set(oneValueArgs FILTER_FILE)
    set(multiValueArgs EXCLUDE)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Get all build targets
    ifx_get_all_targets(ifx_all_targets)

    # Create a list of directories where targets ware created
    foreach(target ${ifx_all_targets})
        get_target_property(target_source_dir ${target} SOURCE_DIR)
        list(APPEND ifx_all_target_source_directories ${target_source_dir})
    endforeach()

    # Get a list of all files relative to target ()
    file(READ ${ARG_FILTER_FILE} IFX_FILES_LIST)

    # Convert string to a list
    string(REPLACE "\n" ";" ifx_target_sources ${IFX_FILES_LIST})

    # Include only infineon files
    list(FILTER ifx_target_sources INCLUDE REGEX "platform/ext/target/infineon")

    # Exclude test (we measure coverage of the secure code, not the code that tests it)
    list(FILTER ifx_target_sources EXCLUDE REGEX "platform/ext/target/infineon/common/tests")

    # Exclude coverage library itself
    list(FILTER ifx_target_sources EXCLUDE REGEX "platform/ext/target/infineon/common/libs/ifx_gcov_lib")

    # Exclude interrupt handler since it requires special handling of enter/exit by exclusion of protection_interrupts.c.
    # This file also has protection context switching assembler function and initialization of H/W PC handler.
    # It's ok to exclude interrupt handler and protection context switching functions because coverage tool
    # doesn't properly handle pure assembler code.
    list(FILTER ifx_target_sources EXCLUDE REGEX "protection_pc.c")

    # Exclude platform_svc_api.c since it contains naked functions that are not compatible with code coverage.
    list(FILTER ifx_target_sources EXCLUDE REGEX "platform_svc_api.c")

    # Exclude shared startup because it runs before .data is copied.
    list(FILTER ifx_target_sources EXCLUDE REGEX "ifx_startup.c")

    # Exclude required files
    foreach(exclude_item ${ARG_EXCLUDE})
        list(FILTER ifx_target_sources EXCLUDE REGEX ${exclude_item})
    endforeach()

    # Print the list of files
    foreach(FILE ${ifx_target_sources})
        message(STATUS "Enabling coverage for file: ${FILE}")
    endforeach()

    # Add --coverage flag for each of the files. This will add code coverage
    # code to the specified files.
    foreach(ifx_source_file ${ifx_target_sources})
        set_source_files_properties(${CMAKE_SOURCE_DIR}/${ifx_source_file}
            # Specify PROPERTIES scope (to be sure that PROPERTY is added,
            # PROPERTY must visible at the scope of the directory where target
            # was created). Simplest solution is just to add all of the
            # directories
            DIRECTORY ${ifx_all_target_source_directories}
            PROPERTIES
                COMPILE_FLAGS
                    --coverage
        )
    endforeach()
endfunction()

# Adds code coverage flags to non-secure inteface files
function(ifx_add_code_coverage_ns)
    # Get all build targets
    ifx_get_all_targets(ifx_all_targets)

    set(EXCLUDE "")

    # Create a list of directories where targets ware created
    foreach(target ${ifx_all_targets})
        message(STATUS "Found target: ${target}")
        get_target_property(target_source_dir ${target} SOURCE_DIR)
        list(APPEND ifx_all_target_source_directories ${target_source_dir})
    endforeach()

    # Define the directory you want to search
    set(DIRECTORY_TO_SEARCH ${CONFIG_SPE_PATH})

    # Use file(GLOB_RECURSE ...) to list all files recursively
    file(GLOB_RECURSE FILE_LIST "${DIRECTORY_TO_SEARCH}/*")

    list(FILTER FILE_LIST INCLUDE REGEX "api_ns/interface")

    # Exclude header files
    list(FILTER FILE_LIST EXCLUDE REGEX "\.h$")

    # Print the list of files
    foreach(FILE ${FILE_LIST})
        message(STATUS "Enabling coverage for file: ${FILE}")
    endforeach()

    # Add --coverage flag for each of the files. This will add code coverage
    # code to the specified files.
    foreach(ifx_source_file ${FILE_LIST})
        set_source_files_properties(${ifx_source_file}
            # Specify PROPERTIES scope (to be sure that PROPERTY is added,
            # PROPERTY must visible at the scope of the directory where target
            # was created). Simplest solution is just to add all of the
            # directories
            DIRECTORY ${ifx_all_target_source_directories}
            PROPERTIES
                COMPILE_FLAGS
                    --coverage
        )
    endforeach()
endfunction()

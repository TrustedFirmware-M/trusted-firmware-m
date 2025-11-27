#-------------------------------------------------------------------------------
# Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${IFX_COMMON_SOURCE_DIR}/cmake/utils.cmake)

# Filter MTB path using components or other filter rules.
#
# Component is folder started with `COMPONENT_` prefix.
#
# FILTERED - result variable name that receives list of filtered path.
# COMPONENTS - list of enabled components.
# DISABLE_COMPONENTS - list of disabled components.
# EXCLUDE - list of regex match expression, see string(REGEX MATCH )
function(_ifx_mtb_filter_components FILTERED)
    set(options "")
    set(oneValueArgs "")
    set(multiValueArgs FILES COMPONENTS DISABLE_COMPONENTS EXCLUDE)
    cmake_parse_arguments(PARSE_ARGV 0 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    string(REPLACE ";" "|" COMBINED_MATCH "${ARG_EXCLUDE}")

    set(FILTERED_FILES "")
    foreach(FILE_PATH IN LISTS ARG_FILES)
        # process components
        string(REPLACE "/" ";" PATH_PARTS "${FILE_PATH}")
        string(REGEX MATCHALL ";(COMPONENT_.+);" COMPONENTS "${PATH_PARTS}")
        string(REPLACE ";COMPONENT_" ";" COMPONENTS "${COMPONENTS}")
        set(ADD_FILE TRUE)
        if(NOT "" STREQUAL COMPONENTS)
            # Path contains component name(s), validate
            foreach(COMPONENT IN LISTS COMPONENTS)
                if("" STREQUAL COMPONENT)
                    # Ignore empty components caused by MATCHALL delimiters
                elseif(COMPONENT IN_LIST ARG_DISABLE_COMPONENTS)
                    # Skip disabled component
                    set(ADD_FILE FALSE)
                    break()
                elseif(NOT COMPONENT IN_LIST ARG_COMPONENTS)
                    # Skip unknown component
                    set(ADD_FILE FALSE)
                    break()
                endif()
            endforeach()
        endif()

        if(ADD_FILE AND NOT "" STREQUAL COMBINED_MATCH)
            # Validate EXCLUDE
            string(REGEX MATCH "${COMBINED_MATCH}" IS_EXCLUDE_MATCHED "${FILE_PATH}")
            if(NOT "" STREQUAL IS_EXCLUDE_MATCHED)
                # Skip excluded file
                set(ADD_FILE FALSE)
            endif()
        endif()

        if(ADD_FILE)
            # File must be added
            list(APPEND FILTERED_FILES "${FILE_PATH}")
        endif()
    endforeach()
    set(${FILTERED} ${FILTERED_FILES} PARENT_SCOPE)
endfunction()

# Perform autodiscovery in MTB library.
#
# PATH - path to BSP.
# TARGET - target name, sources and includes are added to this target.
# COMPONENTS - list of enabled components.
# DISABLE_COMPONENTS - list of disabled components.
# EXCLUDE - list of regex match expression, see string(REGEX MATCH )
# EXCLUDE_HEADERS - set it to disable discovery of headers and adding includes
# EXCLUDE_SOURCES - set it to disable discovery of sources
function(ifx_mtb_autodiscovery)
    set(options EXCLUDE_HEADERS EXCLUDE_SOURCES)
    set(oneValueArgs TARGET)
    set(multiValueArgs PATH COMPONENTS DISABLE_COMPONENTS EXCLUDE)
    cmake_parse_arguments(PARSE_ARGV 0 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    # Use absolute path
    file(REAL_PATH "${ARG_PATH}" ARG_PATH)

    # Detect target type to use PUBLIC or INTERFACE keyword
    get_target_property(TARGET_TYPE ${ARG_TARGET} TYPE)
    if (${TARGET_TYPE} STREQUAL "INTERFACE_LIBRARY")
        set(INCLUDE_TYPE INTERFACE)
        set(SOURCE_TYPE INTERFACE)
    else()
        set(INCLUDE_TYPE PUBLIC)
        set(SOURCE_TYPE PRIVATE)
    endif()

    if (NOT ${ARG_EXCLUDE_HEADERS})
        # Filter .h files
        set(H_SOURCES "")
        foreach(LOOKUP_PATH IN LISTS ARG_PATH)
            file(GLOB_RECURSE __H_SOURCES LIST_DIRECTORIES false "${LOOKUP_PATH}/*.h")
            list(APPEND H_SOURCES ${__H_SOURCES})
        endforeach()
        file(TO_CMAKE_PATH "${H_SOURCES}" H_SOURCES)
        _ifx_mtb_filter_components(
            H_SOURCES
            FILES ${H_SOURCES}
            COMPONENTS ${ARG_COMPONENTS}
            DISABLE_COMPONENTS ${ARG_DISABLE_COMPONENTS}
            EXCLUDE ${ARG_EXCLUDE}
        )

        # Generate list of includes
        ifx_files_to_folders(
            FILTERED_INCLUDES
            FILES ${H_SOURCES}
        )

        # Add include to target
        foreach(PATH IN LISTS FILTERED_INCLUDES)
            target_include_directories(${ARG_TARGET} ${INCLUDE_TYPE} ${PATH})
        endforeach()
    endif()

    if (NOT ${ARG_EXCLUDE_SOURCES})
        # Filter .c files
        set(C_SOURCES "")
        foreach(LOOKUP_PATH IN LISTS ARG_PATH)
            file(GLOB_RECURSE __C_SOURCES LIST_DIRECTORIES false "${LOOKUP_PATH}/*.c")
            list(APPEND C_SOURCES ${__C_SOURCES})
        endforeach()
        file(TO_CMAKE_PATH "${C_SOURCES}" C_SOURCES)
        _ifx_mtb_filter_components(
            C_SOURCES
            FILES ${C_SOURCES}
            COMPONENTS ${ARG_COMPONENTS}
            DISABLE_COMPONENTS ${ARG_DISABLE_COMPONENTS}
            EXCLUDE ${ARG_EXCLUDE}
        )

        # Add sources to target
        foreach(PATH IN LISTS C_SOURCES)
            target_sources(${ARG_TARGET} ${SOURCE_TYPE} ${PATH})
        endforeach()
    endif()
endfunction()

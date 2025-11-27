#-------------------------------------------------------------------------------
# Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This function replace list item in the target property.
# See cmake string(REGEX REPLACE) help for how to specify regular expression and replace value.
# It also removes empty list items in the target property value.
#
# TARGET_NAME - target name
# PROPERTY_NAME - target property name
# MATCH_REGEX - matching regular expression
# REPLACE_VALUE - replace value, use \1, \2, ... \9 to referer parenthesis-delimited subexpressions
function(ifx_target_regex_replace_list_item TARGET_NAME PROPERTY_NAME MATCH_REGEX REPLACE_VALUE)
    get_target_property(PROPERTY_VALUE ${TARGET_NAME} ${PROPERTY_NAME})

    # replace matched value
    string(REGEX REPLACE "${MATCH_REGEX}" "${REPLACE_VALUE}" EDITED_VALUE "${PROPERTY_VALUE}")

    # remove empty item at the beginning
    string(REGEX REPLACE "^;" "" EDITED_VALUE "${EDITED_VALUE}")

    # remove empty item in the middle
    string(REGEX REPLACE ";;" ";" EDITED_VALUE "${EDITED_VALUE}")

    # remove empty item at the end
    string(REGEX REPLACE ";$" "" EDITED_VALUE "${EDITED_VALUE}")

    # update target property
    set_target_properties(${TARGET_NAME} PROPERTIES ${PROPERTY_NAME} "${EDITED_VALUE}")
endfunction()

# Generates list of directories using list of files.
#
# FILES - list of files.
# DIRS - variable name that receives list of directories extracted from FILES with
#           removed duplicates.
function(ifx_files_to_folders DIRS)
    set(options "")
    set(oneValueArgs "")
    set(multiValueArgs FILES)
    cmake_parse_arguments(PARSE_ARGV 0 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    set(FILTERED_DIRS "")
    foreach(FILE_PATH IN LISTS ARG_FILES)
        # process components
        string(REPLACE "/" ";" PATH_PARTS "${FILE_PATH}")
        list(POP_BACK PATH_PARTS)
        string(REPLACE ";" "/" PATH_DIR "${PATH_PARTS}")

        if(NOT PATH_DIR IN_LIST FILTERED_DIRS)
            # File must be added
            list(APPEND FILTERED_DIRS "${PATH_DIR}")
        endif()
    endforeach()
    set(${DIRS} ${FILTERED_DIRS} PARENT_SCOPE)
endfunction()

# Generates list of all targets present in the build.
#
# RES - variable name that receives list of all targets present in the build.
function(ifx_get_all_targets RES)
    set(targets)
    ifx_get_all_targets_recursive(targets ${CMAKE_SOURCE_DIR})
    set(${RES} ${targets} PARENT_SCOPE)
endfunction()

# Generates list of all targets for given directory recursively.
#
# TARGETS - variable name that receives list of all targets for given directory
#           recursively.
# DIR     - path to the directory to look for targets in.
macro(ifx_get_all_targets_recursive TARGETS DIR)
    get_property(subdirectories DIRECTORY ${DIR} PROPERTY SUBDIRECTORIES)
    foreach(subdir ${subdirectories})
        ifx_get_all_targets_recursive(${TARGETS} ${subdir})
    endforeach()

    get_property(current_targets DIRECTORY ${DIR} PROPERTY BUILDSYSTEM_TARGETS)

    list(APPEND ${TARGETS} ${current_targets})
endmacro()

#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This function is a wrapper around the standard add_subdirectory command.
# On Windows, the binary directory path is truncated and hashed to avoid path length issues.
#
# Usage:
#   add_subdirectory_ext(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])
# - source_dir: Source directory to add.
# - binary_dir (optional): Custom binary directory. If not specified, uses source_dir.
# - EXCLUDE_FROM_ALL (optional): Exclude from all build targets.
# - SYSTEM (optional): Treat as a system directory.
function(add_subdirectory_ext source_dir)
    set(options EXCLUDE_FROM_ALL SYSTEM)
    set(oneValueArgs "")
    set(multiValueArgs "")

    unset(binary_dir)
    if(ARGC GREATER 1)
        list(FIND options "${ARGV1}" option_index)
        if(option_index EQUAL -1)
            set(binary_dir "${ARGV1}")
        endif()
    endif()

    cmake_parse_arguments(PARSE_ARGV 2 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    if (ARG_EXCLUDE_FROM_ALL)
        set(ARG_EXCLUDE_FROM_ALL "EXCLUDE_FROM_ALL")
    else()
        unset(ARG_EXCLUDE_FROM_ALL)
    endif()

    if (ARG_SYSTEM)
        set(ARG_SYSTEM "SYSTEM")
    else()
        unset(ARG_SYSTEM)
    endif()

    if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
        # Limit path length to avoid problems during build on Windows
        # Set FULL_BINARY_DIR to the requested absolute path
        if (DEFINED binary_dir)
            if(IS_ABSOLUTE "${binary_dir}")
                set(full_binary_dir "${binary_dir}")
            else()
                set(full_binary_dir "${CMAKE_CURRENT_BINARY_DIR}/${binary_dir}")
            endif()
        else()
            set(full_binary_dir "${CMAKE_CURRENT_BINARY_DIR}/${source_dir}")
        endif()

        # Get relative path to the build directory
        file(RELATIVE_PATH ref_binary_dir "${CMAKE_BINARY_DIR}" "${full_binary_dir}")

        # Calculate MD5 of the relative path and truncate it to 24 characters
        string(MD5 hashed_path "${ref_binary_dir}")
        string(SUBSTRING "${hashed_path}" 0 24 hashed_path)

        # If the original binary_dir is shorter than the hashed path, use it instead
        set(hashed_binary_dir "${CMAKE_BINARY_DIR}/${hashed_path}")
        string(LENGTH "${full_binary_dir}" full_binary_dir_len)
        string(LENGTH "${hashed_binary_dir}" hashed_binary_dir_len)
        if(full_binary_dir_len LESS_EQUAL hashed_binary_dir_len)
            set(binary_dir "${full_binary_dir}")
        else()
            set(binary_dir "${hashed_binary_dir}")
        endif()
    endif()

    # Add subdirectory with optionally truncated path
    add_subdirectory("${source_dir}" "${binary_dir}" ${ARG_EXCLUDE_FROM_ALL} ${ARG_SYSTEM})
endfunction()

# A string calibrating routine to the specified length by
# appending to an input string a specified character.
#
# output - variable to return the calibrated string

function(format_string output input size filler)
    string(LENGTH ${input} length)
    foreach(i RANGE ${length} ${size})
        string(CONCAT input ${input} ${filler})
    endforeach()
    set(${output} ${input} PARENT_SCOPE)
endfunction()

# Prints formatted list of options with a title
#
# title - will be printed in a header
# options - list of CMake options to print (semicolon separated)
#
# Example:
# dump_options("Partitions" "TFM_PARTITION_CRYPTO; TFM_PARTITION_FIRMWARE_UPDATE ")
# will produce:
# -- -------- Partitions ---------------------
# -- TFM_PARTITION_CRYPTO                  ON
# -- TFM_PARTITION_FIRMWARE_UPDATE         OFF
# -- -----------------------------------------

function(dump_options title options)

    if (CONFIG_TFM_PARTITION_QUIET)
        return()
    endif()

    format_string(header "-------- ${title} " 50 "-")
    message(STATUS )
    message(STATUS "${header}")

    foreach (option ${options})
        string(STRIP ${option} option)
        # avoid errors on empty strings to tolerate ';' at the end of list
        if((DEFINED ${option}) AND NOT ${option} STREQUAL "")
            format_string(option_name ${option} 40 " ")
            message(STATUS "${option_name} ${${option}}")
        endif()
    endforeach()

    format_string(footer "-" 50 "-")
    message(STATUS "${footer}")
endfunction()

function(tfm_invalid_config)
    if (${ARGV})
        string (REPLACE ";" " " ARGV_STRING "${ARGV}")
        string (REPLACE "STREQUAL"     "=" ARGV_STRING "${ARGV_STRING}")
        string (REPLACE "GREATER"      ">" ARGV_STRING "${ARGV_STRING}")
        string (REPLACE "LESS"         "<" ARGV_STRING "${ARGV_STRING}")
        string (REPLACE "VERSION_LESS" "<" ARGV_STRING "${ARGV_STRING}")
        string (REPLACE "EQUAL"        "=" ARGV_STRING "${ARGV_STRING}")
        string (REPLACE "IN_LIST"      "in" ARGV_STRING "${ARGV_STRING}")

        message(FATAL_ERROR "INVALID CONFIG: ${ARGV_STRING}")
    endif()
endfunction()

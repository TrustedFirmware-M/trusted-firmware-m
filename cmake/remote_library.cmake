#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors#
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

find_package(Git)

# This function helps to handle options with an empty string values.
# There is a feature/bug in CMake that result in problem with the empty string arguments.
# See https://gitlab.kitware.com/cmake/cmake/-/issues/16341 for details
#
# Arguments:
#   [in]  KEY              - option name
#   [out]  KEY_VAR         - name of variable that is set to ${KEY} on exit if value is not
#                            an empty string otherwise to the empty string.
#   [out]  VALUE_VAR       - name of variable that is set to option value for ${KEY}.
#   [in/out]  ARG_LIST_VAR - name of variable that holds list of key/value pairs - arguments.
#                            Function looks for key/value pair specified by ${KEY} variable in
#                            this list. Function removes key/value pair specified by ${KEY} on
#                            exit.
#
# Example #1:
#   # We have following key/options:
#   #  GIT_SUBMODULES  ""
#   #  BOO  "abc"
#   #  HEY  "hi"
#   set(ARGS    GIT_SUBMODULES "" BOO "abc" HEY "hi")
#   # Extract key/value for option "GIT_SUBMODULES"
#   extract_key_value(GIT_SUBMODULES GIT_SUBMODULES_VAR GIT_SUBMODULES_VALUE_VAR ARGS)
#   # ${GIT_SUBMODULES_VAR} is equal to ""
#   # ${GIT_SUBMODULES_VALUE_VAR} is equal to ""
#
# Example #2:
#   # We have following key/options:
#   #  GIT_SUBMODULES  "name"
#   #  BOO  "abc"
#   #  HEY  "hi"
#   set(ARGS    GIT_SUBMODULES "name" BOO "abc" HEY "hi")
#   # Extract key/value for option "GIT_SUBMODULES"
#   extract_key_value(GIT_SUBMODULES GIT_SUBMODULES_VAR GIT_SUBMODULES_VALUE_VAR ARGS)
#   # ${GIT_SUBMODULES_VAR} is equal to "GIT_SUBMODULES"
#   # ${GIT_SUBMODULES_VALUE_VAR} is equal to "name"
function(extract_key_value KEY KEY_VAR VALUE_VAR ARG_LIST_VAR)
    list(FIND ${ARG_LIST_VAR} ${KEY} KEY_INDEX)
    if(${KEY_INDEX} GREATER_EQUAL 0)
        # Variable has been set, remove KEY
        list(REMOVE_AT ${ARG_LIST_VAR} ${KEY_INDEX})

        # Validate that there is an option value in the list of arguments
        list(LENGTH ${ARG_LIST_VAR} ARG_LIST_LENGTH)
        if(${KEY_INDEX} GREATER_EQUAL ${ARG_LIST_LENGTH})
            message(FATAL_ERROR "Missing option value for ${KEY}")
        endif()

        # Get value
        list(GET ${ARG_LIST_VAR} ${KEY_INDEX} VALUE)

        # Remove value in the list
        list(REMOVE_AT ${ARG_LIST_VAR} ${KEY_INDEX})

        # Update argument list
        set(${ARG_LIST_VAR} ${${ARG_LIST_VAR}} PARENT_SCOPE)

        # Set KEY_VAR & VALUE_VAR
        set(${KEY_VAR} ${KEY} PARENT_SCOPE)
        set(${VALUE_VAR} ${VALUE} PARENT_SCOPE)
    else()
        # Variable is not defined, set KEY_VAR & VALUE_VAR to empty strings
        set(${KEY_VAR} "" PARENT_SCOPE)
        set(${VALUE_VAR} "" PARENT_SCOPE)
    endif()
endfunction()


# This function allows to fetch library from a remote repository or use a local
# library copy.
#
# You can specify location of directory with patches. Patches are applied in
# alphabetical order.
#
# Arguments:
# [in]     LIB_NAME <name> - library name
# [in/out] LIB_SOURCE_PATH_VAR <var> - name of variable which holds path to library source
#           or "DOWNLOAD" if sources should be fetched from the remote repository. This
#           variable is updated in case if library is downloaded. It will point
#           to the path where FetchContent_Populate will locate local library copy.
# [out]    LIB_BINARY_PATH_VAR <var> - optional name of variable which is updated to
#           directory intended for use as a corresponding build directory if
#           library is fetched from the remote repository.
# [in]     LIB_BASE_DIR <path>  - is used to set FETCHCONTENT_BASE_DIR.
# [in]     LIB_PATCH_DIR <path> - optional path to local folder which contains patches
#           that should be applied.
# [in]     LIB_FORCE_PATCH - optional argument to force applying patches when the path
#            is a local folder instead of fetching from the remote repository.
# [in]     GIT_REPOSITORY, GIT_TAG, ... - see https://cmake.org/cmake/help/latest/module/ExternalProject.html
#           for more details
#
# This function set CMP0097 to NEW if CMAKE_VERSION is greater or equal than 3.18.0.
# Because of https://gitlab.kitware.com/cmake/cmake/-/issues/20579 CMP0097 is
# non-functional until cmake 3.18.0.
# See https://cmake.org/cmake/help/latest/policy/CMP0097.html for more info.
function(fetch_remote_library)
    # Parse arguments
    set(options "")
    set(oneValueArgs LIB_NAME LIB_SOURCE_PATH_VAR LIB_BINARY_PATH_VAR LIB_BASE_DIR LIB_PATCH_DIR LIB_FORCE_PATCH)
    set(multiValueArgs FETCH_CONTENT_ARGS)
    cmake_parse_arguments(PARSE_ARGV 0 ARG "${options}" "${oneValueArgs}" "${multiValueArgs}")

    if(ARG_LIB_BASE_DIR)
        set(FETCHCONTENT_BASE_DIR "${ARG_LIB_BASE_DIR}")
    endif()

    if ("${${ARG_LIB_SOURCE_PATH_VAR}}" STREQUAL "DOWNLOAD")
        # Process arguments which can be an empty string
        # There is a feature/bug in CMake that result in problem with empty string arguments
        # See https://gitlab.kitware.com/cmake/cmake/-/issues/16341 for details
        extract_key_value(GIT_SUBMODULES GIT_SUBMODULES GIT_SUBMODULES_VALUE ARG_FETCH_CONTENT_ARGS)

        # Validate that there is no empty arguments to FetchContent_Declare
        LIST(FIND ARG_FETCH_CONTENT_ARGS "" EMPTY_VALUE_INDEX)
        if(${EMPTY_VALUE_INDEX} GREATER_EQUAL 0)
            # There is an unsupported empty string argument, FATAL ERROR!
            math(EXPR EMPTY_KEY_INDEX "${EMPTY_VALUE_INDEX} - 1")
            list(GET ARG_FETCH_CONTENT_ARGS ${EMPTY_KEY_INDEX} EMPTY_KEY)
            # TODO: Use extract_key_value if you have argument with empty value (see GIT_SUBMODULES above)
            message(FATAL_ERROR "fetch_remote_library: Unexpected empty string value for ${EMPTY_KEY}. "
                                "Please, validate arguments or update fetch_remote_library to support empty value for ${EMPTY_KEY}!!!")
        endif()
    else()
        string(TOUPPER ${ARG_LIB_NAME} ARG_LIB_NAME_UPCASE)
        set(FETCHCONTENT_SOURCE_DIR_${ARG_LIB_NAME_UPCASE} ${${ARG_LIB_SOURCE_PATH_VAR}})
    endif()

    # list all available patches in absolute names
    file(GLOB PATCH_FILES ${ARG_LIB_PATCH_DIR}/*.patch LIST_DIRECTORIES true)

    if(PATCH_FILES)
        set(PATCH_COMMAND PATCH_COMMAND ${GIT_EXECUTABLE} am --ignore-date ${PATCH_FILES})
    endif()

    # Content fetching
    FetchContent_Declare(${ARG_LIB_NAME}
        ${ARG_FETCH_CONTENT_ARGS}
        ${GIT_SUBMODULES}     ${GIT_SUBMODULES_VALUE}
        ${PATCH_COMMAND}
    )
    FetchContent_MakeAvailable(${ARG_LIB_NAME})
    set(${ARG_LIB_SOURCE_PATH_VAR} ${${ARG_LIB_NAME}_SOURCE_DIR} CACHE PATH "Library has been downloaded from ${REPO_URL_VAR}, tag ${TAG_VAR}" FORCE)
endfunction()

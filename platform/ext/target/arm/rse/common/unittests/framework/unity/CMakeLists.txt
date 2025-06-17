#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(FETCHCONTENT_QUIET FALSE)

set(UNITY_PATH      "DOWNLOAD"  CACHE PATH      "Path to Unity (or DOWNLOAD to fetch automatically)")
set(UNITY_TAG       "v2.6.1"   CACHE STRING     "Unity version to use")

fetch_remote_library(
    LIB_NAME                    unity
    LIB_SOURCE_PATH_VAR         UNITY_PATH
    LIB_PATCH_DIR               ${CMAKE_CURRENT_LIST_DIR}
    LIB_BASE_DIR                ${CMAKE_BINARY_DIR}/unittests
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY          https://github.com/ThrowTheSwitch/Unity
        GIT_TAG                 ${UNITY_TAG}
        GIT_SHALLOW             TRUE
        GIT_PROGRESS            FALSE
)

target_compile_definitions(unity PUBLIC
    UNITY_USE_COMMAND_LINE_ARGS
    UNITY_SUPPORT_TEST_CASES
    UNITY_INCLUDE_PRINT_FORMATTED
)

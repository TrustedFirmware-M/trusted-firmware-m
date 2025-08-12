#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                libeventlog
    LIB_SOURCE_PATH_VAR     LIB_EVENTLOG_PATH
    LIB_BASE_DIR            ${CMAKE_BINARY_DIR}/lib/ext
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://git.trustedfirmware.org/shared/libEventLog
        GIT_TAG             ${LIB_EVENTLOG_VERSION}
        GIT_SHALLOW         FALSE
        GIT_PROGRESS        TRUE
# The FetchContent_MakeAvailable() function automatically adds the fetched library
# directory to the build using add_subdirectory(). However, the libeventlog module
# defines its own custom target instead of using the default one provided by the
# remote library.
# We set the SOURCE_SUBDIR variable to a non-existent directory as a workaround.
# Related issue: https://gitlab.kitware.com/cmake/cmake/-/issues/26220
        SOURCE_SUBDIR       non-exist-dir
)

if(NOT EXISTS "${LIB_EVENTLOG_PATH}/src/event_log.c")
    message(FATAL_ERROR "event_log.c not found in ${LIB_EVENTLOG_PATH}/src")
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug.h
    ${LIB_EVENTLOG_PATH}/include/private/debug.h
    COPYONLY
)

add_library(eventlog STATIC EXCLUDE_FROM_ALL
    ${LIB_EVENTLOG_PATH}/src/event_log.c
    ${LIB_EVENTLOG_PATH}/src/event_print.c
    ${LIB_EVENTLOG_PATH}/src/digest.c
)

target_include_directories(eventlog
    PUBLIC
    ${LIB_EVENTLOG_PATH}/include
    PRIVATE
    ${LIB_EVENTLOG_PATH}/include/private
)

if(EVENTLOG_HASH_ALGORITHM STREQUAL "SHA512")
    add_compile_definitions(TPM_ALG_ID=TPM_ALG_SHA512)
    add_compile_definitions(TCG_DIGEST_SIZE=64U)
elseif(EVENTLOG_HASH_ALGORITHM STREQUAL "SHA384")
    add_compile_definitions(TPM_ALG_ID=TPM_ALG_SHA384)
    add_compile_definitions(TCG_DIGEST_SIZE=48U)
else()
    add_compile_definitions(TPM_ALG_ID=TPM_ALG_SHA256)
    add_compile_definitions(TCG_DIGEST_SIZE=32U)
endif()

target_link_libraries(eventlog
    PRIVATE
        tfm_log_headers
)

target_compile_definitions(eventlog
    PUBLIC
        EVENT_LOG_LIB=1
        EVENT_LOG_BUFFER_SIZE=${EVENT_LOG_BUFFER_SIZE}
    PRIVATE
       DEBUG_BACKEND_HEADER="log_backend_tfm.h"
)

add_compile_definitions(LOG_LEVEL=${TFM_SPM_LOG_LEVEL})

if(LOG_LEVEL STREQUAL "LOG_LEVEL_VERBOSE")
    add_compile_definitions(EVLOG_LOG_LEVEL=EVLOG_LEVEL_VERBOSE)
else()
    add_compile_definitions(EVLOG_LOG_LEVEL=EVLOG_LEVEL_NONE)
endif()

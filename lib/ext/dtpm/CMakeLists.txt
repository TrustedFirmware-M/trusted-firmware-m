#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                libtpm_client
    LIB_SOURCE_PATH_VAR     LIB_DTPM_PATH
    LIB_BASE_DIR            ${CMAKE_BINARY_DIR}/lib/ext
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://git.trustedfirmware.org/shared/libTPM
        GIT_TAG             ${LIB_DTPM_VERSION}
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

add_library(lib_tpm STATIC EXCLUDE_FROM_ALL
    ${LIB_DTPM_PATH}/src/tpm2_chip.c
    ${LIB_DTPM_PATH}/src/tpm2_cmds.c
    ${LIB_DTPM_PATH}/src/tpm2_fifo.c
    ${LIB_DTPM_PATH}/src/tpm2_fifo_spi.c
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug.h
    ${LIB_DTPM_PATH}/include/debug.h
    COPYONLY
)

target_include_directories(lib_tpm
    PUBLIC
    ${LIB_DTPM_PATH}/include
    ${LIB_DTPM_PATH}/include/platform
    ${LIB_DTPM_PATH}/include/transport
    ${CMAKE_SOURCE_DIR}/platform/ext/driver/spi
)

target_link_libraries(lib_tpm
    PRIVATE
        tfm_log_headers
)

add_compile_definitions(LOG_LEVEL=${TFM_SPM_LOG_LEVEL})

if(LOG_LEVEL STREQUAL "LOG_LEVEL_VERBOSE")
    add_compile_definitions(EVLOG_LOG_LEVEL=EVLOG_LEVEL_VERBOSE)
else()
    add_compile_definitions(EVLOG_LOG_LEVEL=EVLOG_LEVEL_NONE)
endif()

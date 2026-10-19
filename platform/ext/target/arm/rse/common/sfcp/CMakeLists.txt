#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(SFCP_PATH "DOWNLOAD" CACHE PATH "Path to SFCP (or DOWNLOAD to fetch automatically)")
set(SFCP_VERSION "9994276949d80db05cc8aa3cf22c1b5569729a56" CACHE STRING "The version of SFCP to use")
set(SFCP_GIT_REMOTE "https://review.trustedfirmware.org/shared/sfcp" CACHE STRING "The URL to retrieve SFCP from")

fetch_remote_library(
    LIB_NAME sfcp
    LIB_SOURCE_PATH_VAR SFCP_PATH
    LIB_BASE_DIR ${CMAKE_BINARY_DIR}/lib/ext
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY ${SFCP_GIT_REMOTE}
        GIT_TAG ${SFCP_VERSION}
        GIT_SHALLOW FALSE
        GIT_PROGRESS TRUE
        # Build each firmware stage through the library's target factory.
        # This directory has no CMakeLists.txt, so fetching does not create
        # the standalone project's default target.
        SOURCE_SUBDIR cmake
)

include("${SFCP_PATH}/cmake/SFCP.cmake")

function(rse_add_sfcp_library consumer)
    set(library sfcp_${consumer})
    set(SFCP_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/interface/include)
    sfcp_add_library(${library} STATIC)
    target_link_libraries(${consumer} PUBLIC ${library})
    # Hardware providers live in the consumer archive. Rescan both archives
    # without applying the consumer's compile settings to SFCP.
    target_link_libraries(${library} INTERFACE $<LINK_ONLY:${consumer}>)
endfunction()

add_subdirectory(sfcp_core)
add_subdirectory(sfcp_psa)

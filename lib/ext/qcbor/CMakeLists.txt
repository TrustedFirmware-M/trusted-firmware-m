#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# Default configuration of QCBOR repository
set(QCBOR_PATH      "DOWNLOAD"  CACHE PATH      "Path to qcbor (or DOWNLOAD to fetch automatically")
set(QCBOR_VERSION   "v1.2"      CACHE STRING    "The version of qcbor to use")

# Entirely disable the floating-point support
# in the qcbor library to reduce code size.
set(QCBOR_OPT_DISABLE_FLOAT_HW_USE     ON  CACHE BOOL  "Eliminate dependency on FP hardware and FP instructions" FORCE)
set(QCBOR_OPT_DISABLE_FLOAT_PREFERRED  ON  CACHE BOOL  "Eliminate support for half-precision and CBOR preferred serialization" FORCE)
set(QCBOR_OPT_DISABLE_FLOAT_ALL        ON  CACHE BOOL  "Eliminate floating-point support completely" FORCE)

fetch_remote_library(
    LIB_NAME                qcbor
    LIB_SOURCE_PATH_VAR     QCBOR_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    LIB_BASE_DIR            "${CMAKE_BINARY_DIR}/lib/ext"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/laurencelundblade/QCBOR.git
        GIT_TAG             ${QCBOR_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
)

set_target_properties(qcbor PROPERTIES EXCLUDE_FROM_ALL TRUE)

target_compile_options(qcbor
    PUBLIC
        ${COMPILER_CP_FLAG}
)

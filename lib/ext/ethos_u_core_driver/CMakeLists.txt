#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                ethos_u_core_driver
    LIB_SOURCE_PATH_VAR     ETHOS_DRIVER_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      "https://review.mlplatform.org/ml/ethos-u/ethos-u-core-driver"
        GIT_TAG             "24.08"
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
# We set the SOURCE_SUBDIR variable to a non-existent directory as a workaround 
# to avoid adding the library directory into the project.
# Related issue: https://gitlab.kitware.com/cmake/cmake/-/issues/26220
        SOURCE_SUBDIR       non-exist-dir
)

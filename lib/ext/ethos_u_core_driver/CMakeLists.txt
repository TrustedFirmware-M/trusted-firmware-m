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
)

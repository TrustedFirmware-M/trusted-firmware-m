#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                tf-m-extras
    LIB_SOURCE_PATH_VAR     TFM_EXTRAS_REPO_PATH
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://git.trustedfirmware.org/TF-M/tf-m-extras.git
        GIT_TAG             ${TFM_EXTRAS_REPO_VERSION}
        GIT_SHALLOW         FALSE
        GIT_PROGRESS        TRUE
)

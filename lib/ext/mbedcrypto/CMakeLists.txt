#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors#
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                mbedcrypto
    LIB_SOURCE_PATH_VAR     MBEDCRYPTO_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    LIB_FORCE_PATCH         ${MBEDCRYPTO_FORCE_PATCH}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${MBEDCRYPTO_GIT_REMOTE}
        GIT_TAG             ${MBEDCRYPTO_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
# The FetchContent_MakeAvailable() function automatically adds the fetched library
# directory to the build using add_subdirectory(). However, the TF-M does not need
# whole MbedCrypto remote library so it defines its own custom targets.
# We set the SOURCE_SUBDIR variable to a non-existent directory as a workaround.
# Related details: https://gitlab.kitware.com/cmake/cmake/-/issues/26220
        SOURCE_SUBDIR       non-exist-dir
)

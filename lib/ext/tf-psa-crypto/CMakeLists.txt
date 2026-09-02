#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                tf-psa-crypto
    LIB_SOURCE_PATH_VAR     TF_PSA_CRYPTO_PATH
    LIB_PATCH_DIR           ${TF_PSA_CRYPTO_PATCH_DIR}
    LIB_FORCE_PATCH         ${TF_PSA_CRYPTO_FORCE_PATCH}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${TF_PSA_CRYPTO_GIT_REMOTE}
        GIT_TAG             ${TF_PSA_CRYPTO_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
# The FetchContent_MakeAvailable() function automatically adds the fetched
# library directory to the build using add_subdirectory(). However, the TF-M
# does not need the whole TF-PSA-Crypto remote library so it defines its own
# custom targets. We set the SOURCE_SUBDIR variable to a non-existent directory
# as a workaround.
# Related details: https://gitlab.kitware.com/cmake/cmake/-/issues/26220
        SOURCE_SUBDIR       non-exist-dir
)

################################################################################
# Apply platform-specific tf-psa-crypto patches (if provided via patch.cmake)
################################################################################

if(DEFINED PLATFORM_TF_PSA_CRYPTO_PATCH_DIR AND EXISTS ${PLATFORM_TF_PSA_CRYPTO_PATCH_DIR})
    file(GLOB PLATFORM_PATCHES
         LIST_DIRECTORIES false
         ${PLATFORM_TF_PSA_CRYPTO_PATCH_DIR}/*.patch)

    if(PLATFORM_PATCHES)
        list(SORT PLATFORM_PATCHES)
        message(STATUS "Applying platform-specific tf-psa-crypto patches from: ${PLATFORM_TF_PSA_CRYPTO_PATCH_DIR}")

        foreach(PATCH ${PLATFORM_PATCHES})
            get_filename_component(PATCH_NAME ${PATCH} NAME)

            execute_process(
                COMMAND ${GIT_EXECUTABLE} am --ignore-date ${PATCH}
                WORKING_DIRECTORY ${TF_PSA_CRYPTO_PATH}
                RESULT_VARIABLE PATCH_RESULT
                OUTPUT_QUIET
                ERROR_VARIABLE PATCH_ERROR
            )

            if(NOT PATCH_RESULT EQUAL 0)
                # Check if patch was already applied
                if(PATCH_ERROR MATCHES "already exists in index|Patch already applied")
                    message(STATUS "  ${PATCH_NAME} - already applied, skipping")
                else()
                    message(FATAL_ERROR
                        "Failed to apply platform patch: ${PATCH_NAME}\n"
                        "Error: ${PATCH_ERROR}\n"
                        "Working directory: ${TF_PSA_CRYPTO_PATH}\n"
                        "You may need to:\n"
                        "  1. Check patch compatibility with tf-psa-crypto version\n"
                        "  2. Manually apply: cd ${TF_PSA_CRYPTO_PATH} && git am ${PATCH}\n"
                        "  3. Or abort failed am: cd ${TF_PSA_CRYPTO_PATH} && git am --abort")
                endif()
            else()
                message(STATUS "  ${PATCH_NAME} - applied successfully")
            endif()
        endforeach()

        message(STATUS "Platform tf-psa-crypto patches applied successfully")
    else()
        message(STATUS "No platform-specific tf-psa-crypto patches found in: ${PLATFORM_TF_PSA_CRYPTO_PATCH_DIR}")
    endif()
endif()

#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# Default configuration of cc3xx repository
set(TF_PSA_CRYPTO_DRIVERS_PATH     "DOWNLOAD"         CACHE PATH   "Path to cc3xx Crypto driver (or DOWNLOAD to fetch automatically")
set(TF_PSA_CRYPTO_DRIVERS_NAME     "vendor/arm/cc3xx" CACHE STRING "PSA Crypto driver name")
set(TF_PSA_CRYPTO_DRIVERS_VERSION  "27c8ccd"          CACHE STRING "Revision of cc3xx to fetch")

# 'fetch_remote_library' updates the PATH once completed
set(TF_PSA_CRYPTO_DRIVERS_PATH_ORIG ${TF_PSA_CRYPTO_DRIVERS_PATH})

fetch_remote_library(
    LIB_NAME                cc3xx
    LIB_SOURCE_PATH_VAR     TF_PSA_CRYPTO_DRIVERS_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    LIB_BASE_DIR            "${CMAKE_BINARY_DIR}/driver"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://git.trustedfirmware.org/shared/tf-psa-crypto-drivers
        GIT_TAG             ${TF_PSA_CRYPTO_DRIVERS_VERSION}
        GIT_SHALLOW         FALSE
        GIT_PROGRESS        TRUE
)

set(CC3XX_DRIVER_PATH ${TF_PSA_CRYPTO_DRIVERS_PATH}/${TF_PSA_CRYPTO_DRIVERS_NAME} CACHE PATH "CC3XX Crypto driver path")


if(DEFINED PLATFORM_TF_PSA_CRYPTO_DRIVERS_PATCH_DIR AND
    EXISTS "${PLATFORM_TF_PSA_CRYPTO_DRIVERS_PATCH_DIR}" AND
    NOT ${TF_PSA_CRYPTO_DRIVERS_PATH_ORIG} STREQUAL "DOWNLOAD")

    file(GLOB PLATFORM_PATCHES
         LIST_DIRECTORIES false
         ${PLATFORM_TF_PSA_CRYPTO_DRIVERS_PATCH_DIR}/*.patch)

    get_property(PATCHEDOUT GLOBAL PROPERTY "CC3XX_PLAT_PATCHED")

    if(PLATFORM_PATCHES AND NOT PATCHEDOUT)
        set_property(GLOBAL PROPERTY "CC3XX_PLAT_PATCHED" TRUE)

        list(SORT PLATFORM_PATCHES)
        message(STATUS  "Applying platform-specific tf-psa-crypto-drivers patches "
                        "from: ${PLATFORM_TF_PSA_CRYPTO_DRIVERS_PATCH_DIR}")

        foreach(PATCH ${PLATFORM_PATCHES})
            get_filename_component(PATCH_NAME ${PATCH} NAME)

            execute_process(
                COMMAND ${GIT_EXECUTABLE} am --ignore-date ${PATCH}
                WORKING_DIRECTORY ${TF_PSA_CRYPTO_DRIVERS_PATH}
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
                        "Working directory: ${TF_PSA_CRYPTO_DRIVERS_PATH}\n"
                        "You may need to:\n"
                        "  1. Check patch compatibility with tf-psa-crypto-drivers version\n"
                        "  2. Manually apply: cd ${TF_PSA_CRYPTO_DRIVERS_PATH} && git am ${PATCH}\n"
                        "  3. Or abort failed am: cd ${TF_PSA_CRYPTO_DRIVERS_PATH} && git am --abort")
                endif()
            else()
                message(STATUS "  ${PATCH_NAME} - applied successfully")
            endif()
        endforeach()

        message(STATUS "Platform tf-psa-crypto-drivers patches applied successfully")
    else()
        if(NOT PATCHEDOUT)
            message(STATUS  "No platform-specific tf-psa-crypto-drivers patches found in: "
                    "${PLATFORM_TF_PSA_CRYPTO_DRIVERS_PATCH_DIR}")
        endif()
    endif()
endif()

#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PSA_ADAC_TARGET "trusted-firmware-m")
set(PSA_ADAC_MBEDTLS_INCLUDE "${MBEDCRYPTO_PATH}/include")
set(PSA_ADAC_TOOLCHAIN    FALSE    CACHE BOOL "Whether to use psa-adac toolchain." FORCE)

fetch_remote_library(
    LIB_NAME                libpsaadac
    LIB_SOURCE_PATH_VAR     PLATFORM_PSA_ADAC_SOURCE_PATH
    LIB_BINARY_PATH_VAR     PLATFORM_PSA_ADAC_BUILD_PATH
    FETCH_CONTENT_ARGS
        GIT_TAG             ${PLATFORM_PSA_ADAC_VERSION}
        GIT_REPOSITORY      https://git.trustedfirmware.org/shared/psa-adac.git
)

if (NOT LIB_BINARY_PATH_VAR)
    set(PLATFORM_PSA_ADAC_BUILD_PATH "${CMAKE_SOURCE_DIR}/build/lib/ext/libpsaadac-build" CACHE PATH "Path to build directory of psa-adac.")
endif()

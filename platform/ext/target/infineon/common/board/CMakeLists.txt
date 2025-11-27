#-------------------------------------------------------------------------------
# Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# In MTB BSP is a local folder which is not a git repository, thus it is
# impossible to patch it.
if(IFX_MTB_BUILD)
    set(IFX_BSP_LIB_FORCE_PATCH OFF CACHE BOOL "Whether to force BSP patches")
else()
    set(IFX_BSP_LIB_FORCE_PATCH ON  CACHE BOOL "Whether to force BSP patches")
endif()

# Fetch BSP library
fetch_remote_library(
    LIB_NAME                ifx_bsp_lib
    LIB_SOURCE_PATH_VAR     IFX_BSP_LIB_PATH
    # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
    # and then reused by subsequent builds. This speeds up the build.
    LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
    LIB_PATCH_DIR           ${IFX_BSP_LIB_PATCH_DIR}
    LIB_FORCE_PATCH         ${IFX_BSP_LIB_FORCE_PATCH}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${IFX_BSP_LIB_GIT_REMOTE}
        GIT_TAG             ${IFX_BSP_LIB_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
)

############################### Generated Sources ##############################

# Note: if one of these files need to be used by target then CMakeLists.txt
# that creates the target must cmake_policy(SET CMP0118 NEW) before adding
# target
ifx_generate_sources(
    GENERATED_LIST IFX_BSP_GENERATED_SOURCES_LIST
    DEVICE_SUPPORT_LIBS ${IFX_BSP_DEVICE_SUPPORT_LIBS}
)

# Create target for generated sources. Each target that uses generated sources
# must depend (add_dependencies(<target> ifx_bsp_generated_sources)) on this
# target so that sources will be generated before they are built.
add_custom_target(ifx_bsp_generated_sources
    DEPENDS ${IFX_BSP_GENERATED_SOURCES_LIST}
)

############################### Platform Secure ###############################

if(S_BUILD)
    add_subdirectory(spe)

    # Board customization provided by platform
    add_subdirectory(${IFX_BOARD_PATH}/spe platform)
endif()

############################# Platform Non-Secure #############################

if(NS_BUILD)
    add_subdirectory(nspe)

    # Board customization provided by platform
    add_subdirectory(${IFX_BOARD_PATH}/nspe platform)
endif()

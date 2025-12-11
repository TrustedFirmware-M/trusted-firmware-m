#-------------------------------------------------------------------------------
# Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                ifx_mtb_srf
    LIB_SOURCE_PATH_VAR     IFX_MTB_SRF_LIB_PATH
    # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
    # and then reused by subsequent builds. This speeds up the build.
    LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
    LIB_PATCH_DIR           ${IFX_MTB_SRF_LIB_PATCH_DIR}
    LIB_FORCE_PATCH         ON
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${IFX_MTB_SRF_LIB_GIT_REMOTE}
        GIT_TAG             ${IFX_MTB_SRF_LIB_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        GIT_SUBMODULES      ""
)

add_library(ifx_mtb_srf_int INTERFACE)

target_include_directories(ifx_mtb_srf_int
    INTERFACE
        ${IFX_MTB_SRF_LIB_PATH}/include
)

target_compile_definitions(ifx_mtb_srf_int
    INTERFACE
        COMPONENT_MW_MTB_SRF
        MTB_SRF_CUSTOM_REQUEST_SUBMIT # TFM uses own SRF request handling mechanism
        MTB_SRF_USE_PSA # Make SRF use TFM compatible code
)

if (IFX_MTB_MAILBOX)
    target_compile_definitions(ifx_mtb_srf_int
        INTERFACE
            MTB_SRF_CUSTOM_IPC_REQUEST_SUBMIT # TFM uses own SRF IPC request handling mechanism
            MTB_SRF_CUSTOM_PROCESS_REQUEST # TFM uses own SRF process request handling mechanism
            MTB_SRF_IPC_CUSTOM_PACKET_TYPE # TFM uses own SRF IPC packet type to implement PSA call functionality
    )
endif()

target_link_libraries(ifx_mtb_srf_int
    INTERFACE
        psa_interface
)

if (S_BUILD)
    add_library(ifx_mtb_srf_s)

    target_sources(ifx_mtb_srf_s
        PRIVATE
            ${IFX_MTB_SRF_LIB_PATH}/source/mtb_srf.c
    )

    target_link_libraries(ifx_mtb_srf_s
        PRIVATE
            cmsis
            ifx_core_lib
            ifx_pdl_inc_s
        PUBLIC
            ifx_mtb_srf_int
    )

    target_compile_options(ifx_mtb_srf_s
        PRIVATE
            ${COMPILER_CP_FLAG}
    )

    target_link_libraries(ifx_pdl_s
        PRIVATE
            ifx_mtb_srf_s
    )

    target_link_libraries(ifx_pdl_inc_s
        INTERFACE
            ifx_mtb_srf_int
    )
endif()

if (NS_BUILD)
    add_library(ifx_mtb_srf_ns)

    target_sources(ifx_mtb_srf_ns
        PRIVATE
            ${IFX_MTB_SRF_LIB_PATH}/source/COMPONENT_NON_SECURE_DEVICE/mtb_srf_pool.c
            ${IFX_MTB_SRF_LIB_PATH}/source/mtb_srf.c
    )

    target_include_directories(ifx_mtb_srf_int
        INTERFACE
            ${IFX_MTB_SRF_LIB_PATH}/include/COMPONENT_NON_SECURE_DEVICE
            ${IFX_MTB_SRF_LIB_PATH}/include/COMPONENT_NON_SECURE_DEVICE/COMPONENT_MW_MTB_IPC
    )

    target_link_libraries(ifx_mtb_srf_ns
        PRIVATE
            ifx_cmsis_lib
            ifx_core_lib
            ifx_mtb_hal
            ifx_pdl_inc_ns
        PUBLIC
            ifx_abstraction_rtos
        INTERFACE
            ifx_mtb_srf_int
    )

    target_sources(tfm_api_ns
        PRIVATE
            ${INTERFACE_SRC_DIR}/ifx_mtb_srf.c
            # MTB SRF is implemented through IFX Extensions Partition
            ${INTERFACE_SRC_DIR}/ifx_ext_sp_api.c
    )

    if(IFX_MTB_MAILBOX)
        target_sources(ifx_mtb_srf_ns
            PRIVATE
                ${IFX_MTB_SRF_LIB_PATH}/source/COMPONENT_NON_SECURE_DEVICE/COMPONENT_MW_MTB_IPC/mtb_srf_ipc.c
                ${INTERFACE_SRC_DIR}/ifx_mtb_srf_relay.c
        )

        target_link_libraries(ifx_mtb_srf_ns
            PUBLIC
                ifx_mtb_ipc
        )

        target_sources(tfm_api_ns
            PRIVATE
            # Core specific multi core hal is added so that SRF Relay on NSPE
            # can use memory remapping functions
            $<$<AND:$<BOOL:${IFX_MULTICORE_CM55}>,$<BOOL:${IFX_NS_INTERFACE_TZ}>>:${INTERFACE_SRC_DIR}/ifx_mtb_mailbox/platform_hal_multi_core_cm55.c>
        )
    endif()

    target_link_libraries(tfm_api_ns
        PRIVATE
            ifx_mtb_srf_ns
    )

    target_link_libraries(ifx_pdl_ns
        PRIVATE
            ifx_mtb_srf_ns
    )

    target_link_libraries(ifx_pdl_inc_ns
        INTERFACE
            ifx_mtb_srf_int
    )
endif()

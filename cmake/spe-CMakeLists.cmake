#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

# This CMake script is prepard by TF-M for building the non-secure side
# application and not used in secure build a tree being for export only.
# This file is renamed to spe/CMakeList.txt during installation phase

include(spe_config)
include(spe_export)
include(hex_generator)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

set_target_properties(tfm_config psa_interface psa_crypto_config PROPERTIES IMPORTED_GLOBAL True)
target_link_libraries(tfm_config INTERFACE psa_interface)

# In actual NS integration, NS side build should include the source files
# exported by TF-M build.
set(INTERFACE_SRC_DIR    ${CMAKE_CURRENT_LIST_DIR}/interface/src)
set(INTERFACE_INC_DIR    ${CMAKE_CURRENT_LIST_DIR}/interface/include)
set(PLATFORM_DIR         ${CMAKE_CURRENT_LIST_DIR}/platform)
if (DEFINED NS_TARGET_NAME)
    message(STATUS "Using NS_TARGET_NAME: ${NS_TARGET_NAME}")
else()
    set(NS_TARGET_NAME "tfm_ns")
endif()

add_library(tfm_api_ns STATIC)

target_sources(tfm_api_ns
    PUBLIC
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${INTERFACE_SRC_DIR}/tfm_platform_api.c>
        $<$<BOOL:${TFM_PARTITION_PROTECTED_STORAGE}>:${INTERFACE_SRC_DIR}/tfm_ps_api.c>
        $<$<BOOL:${TFM_PARTITION_INTERNAL_TRUSTED_STORAGE}>:${INTERFACE_SRC_DIR}/tfm_its_api.c>
        $<$<BOOL:${TFM_PARTITION_CRYPTO}>:${INTERFACE_SRC_DIR}/tfm_crypto_api.c>
        $<$<BOOL:${TFM_PARTITION_INITIAL_ATTESTATION}>:${INTERFACE_SRC_DIR}/tfm_attest_api.c>
        $<$<BOOL:${TFM_PARTITION_FIRMWARE_UPDATE}>:${INTERFACE_SRC_DIR}/tfm_fwu_api.c>
)

# Include interface headers exported by TF-M
target_include_directories(tfm_api_ns
    PUBLIC
        ${INTERFACE_INC_DIR}
        ${INTERFACE_INC_DIR}/crypto_keys
)

if (CONFIG_TFM_USE_TRUSTZONE)
    add_library(tfm_api_ns_tz STATIC)

    target_sources(tfm_api_ns_tz
        PUBLIC
            ${INTERFACE_SRC_DIR}/tfm_tz_psa_ns_api.c
    )

    target_include_directories(tfm_api_ns_tz
        PUBLIC
            ${INTERFACE_INC_DIR}
    )

    target_link_libraries(tfm_api_ns_tz
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/interface/lib/s_veneers.o
    )
endif()

if (TFM_HYBRID_PLATFORM_API_BROKER)
    add_library(tfm_api_broker STATIC)
    target_sources(tfm_api_broker
        PUBLIC
            ${INTERFACE_SRC_DIR}/hybrid_platform/api_broker.c
    )

    target_compile_definitions(tfm_api_broker
        PUBLIC
            TFM_HYBRID_PLATFORM_API_BROKER
    )

    target_include_directories(tfm_api_broker
        PUBLIC
            ${INTERFACE_INC_DIR}
    )

    target_link_libraries(tfm_api_ns_tz PUBLIC tfm_api_broker)

endif()

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    add_library(tfm_api_ns_mailbox STATIC)

    target_sources(tfm_api_ns_mailbox
        PUBLIC
            ${INTERFACE_SRC_DIR}/multi_core/tfm_multi_core_ns_api.c
            ${INTERFACE_SRC_DIR}/multi_core/tfm_multi_core_psa_ns_api.c
            ${INTERFACE_SRC_DIR}/multi_core/tfm_ns_mailbox.c
            ${INTERFACE_SRC_DIR}/multi_core/platform_ns_mailbox.c
    )

    target_include_directories(tfm_api_ns_mailbox
        PUBLIC
            ${INTERFACE_INC_DIR}
            ${INTERFACE_INC_DIR}/multi_core
            ${PLATFORM_DIR}/ext/cmsis/Include
    )

    target_compile_definitions(tfm_api_ns_mailbox
        PUBLIC
            $<$<BOOL:${TFM_HYBRID_PLATFORM_API_BROKER}>:TFM_HYBRID_PLATFORM_API_BROKER>
    )
endif()

if (TFM_PARTITION_CRYPTO)
    target_link_libraries(tfm_api_ns
        PUBLIC
            psa_crypto_config
    )
endif()

add_library(platform_region_defs INTERFACE)

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${BL1}>:BL1>
        $<$<BOOL:${BL2}>:BL2>
        BL2_HEADER_SIZE=${BL2_HEADER_SIZE}
        BL2_TRAILER_SIZE=${BL2_TRAILER_SIZE}
        $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
        $<$<STREQUAL:${MCUBOOT_EXECUTION_SLOT},2>:LINK_TO_SECONDARY_PARTITION>
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_${TEST_PSA_API}>
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:relwithdebinfo>>:ENABLE_HEAP>
)

target_link_libraries(platform_region_defs
    INTERFACE
        tfm_config
)

add_subdirectory(platform)

target_sources(platform_ns
    PRIVATE
        $<$<BOOL:${PLATFORM_DEFAULT_UART_STDOUT}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/ext/common/uart_stdout.c>
)

add_library(platform_ns_definitions INTERFACE)

# these compile definitions must match on the secure and nonsecure side for security
target_compile_definitions(platform_ns_definitions
    INTERFACE
        DOMAIN_NS=1
        $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:PLATFORM_DEFAULT_CRYPTO_KEYS>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},hard>:CONFIG_TFM_FLOAT_ABI=2>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},soft>:CONFIG_TFM_FLOAT_ABI=0>
        $<$<BOOL:${CONFIG_TFM_DISABLE_CP10CP11}>:CONFIG_TFM_DISABLE_CP10CP11>
        $<$<BOOL:${CONFIG_TFM_ENABLE_CP10CP11}>:CONFIG_TFM_ENABLE_CP10CP11>
)

target_link_libraries(platform_ns
    PUBLIC
        platform_ns_definitions
)

if (DEFINED PLATFORM_CUSTOM_NS_FILES)
    message(STATUS "Using PLATFORM_CUSTOM_NS_FILES: ${PLATFORM_CUSTOM_NS_FILES}")
else()
    set(PLATFORM_CUSTOM_NS_FILES FALSE)
endif()

target_link_libraries(tfm_api_ns
    PUBLIC
        platform_region_defs
        platform_ns_definitions
        $<$<NOT:$<BOOL:${PLATFORM_CUSTOM_NS_FILES}>>:platform_ns>
)

if(BL2 AND PLATFORM_DEFAULT_IMAGE_SIGNING)

    find_package(Python3)

    add_custom_target(tfm_s_ns_signed_bin
        ALL
        SOURCES ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
    )

    if (DEFINED S_NS_SIGNED_TARGET_NAME)
        message(STATUS "Using S_NS_SIGNED_TARGET_NAME: ${S_NS_SIGNED_TARGET_NAME}")
    else()
        set(S_NS_SIGNED_TARGET_NAME tfm_s_ns_signed)
    endif()

    add_convert_to_offset_hex_target(tfm_s_ns_signed
        INPUT_FILE          ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
        OFFSET_MACRO_NAME   S_CODE_START
        INCLUDE_BL2_HEADER  TRUE
        MIRROR_FILE         $<TARGET_PROPERTY:${NS_TARGET_NAME},LINK_DEPENDS>
        OUTPUT_FILE         ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.hex
    )

    add_custom_command(
        TARGET tfm_s_ns_signed_hex_build
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
            $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${S_NS_SIGNED_TARGET_NAME}.bin
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.hex
            $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${S_NS_SIGNED_TARGET_NAME}.hex
    )

    if (MCUBOOT_IMAGE_NUMBER GREATER 1)

        set(wrapper_args
            --version ${MCUBOOT_IMAGE_VERSION_NS}
            --layout ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_ns.o
            --key ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/keys/image_ns_signing_private_key.pem
            --public-key-format $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
            --align ${MCUBOOT_ALIGN_VAL}
            --pad
            --pad-header
            -H ${BL2_HEADER_SIZE}
            -s ${MCUBOOT_SECURITY_COUNTER_NS}
            -L ${MCUBOOT_ENC_KEY_LEN}
            -d \"\(0, ${MCUBOOT_S_IMAGE_MIN_VER}\)\"
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
            $<$<BOOL:${MCUBOOT_CONFIRM_IMAGE}>:--confirm>
            $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${MCUBOOT_KEY_ENC_NS}>
            $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
            $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${NS_TARGET_NAME}.bin
            ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
        )

        if(MCUBOOT_BUILTIN_KEY)
            set(wrapper_args ${wrapper_args} --psa-key-ids ${TFM_NS_KEY_ID})
        endif()

        add_custom_target(${NS_TARGET_NAME}_signed_bin
            SOURCES ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
        )
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
            DEPENDS ${NS_TARGET_NAME}_bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_ns.o
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/scripts

            #Sign non-secure binary image with provided secret key
            COMMAND mcuboot_imagesign_wrapper ${wrapper_args}
        )

        add_convert_to_offset_hex_target(${NS_TARGET_NAME}_signed
            INPUT_FILE          ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
            OFFSET_MACRO_NAME   NS_CODE_START
            INCLUDE_BL2_HEADER  TRUE
            MIRROR_FILE         $<TARGET_PROPERTY:${NS_TARGET_NAME},LINK_DEPENDS>
            OUTPUT_FILE         ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.hex
        )

        # Create concatenated binary image from the two independently signed
        # binary file. This only uses the local assemble script (not from
        # upstream mcuboot) because that script is geared towards zephyr
        # support
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bin/tfm_s_signed.bin
            DEPENDS ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s.o
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/scripts

            COMMAND mcuboot_imagesign_assemble
                --layout ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s.o
                --secure ${CMAKE_CURRENT_SOURCE_DIR}/bin/tfm_s_signed.bin
                --non_secure ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_signed.bin
                --output ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
            COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
                $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${S_NS_SIGNED_TARGET_NAME}.bin
        )
    else()
        add_custom_target(tfm_s_ns_bin
            SOURCES ${CMAKE_BINARY_DIR}/bin/tfm_s_ns.bin
        )
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/tfm_s_ns.bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bin/tfm_s.bin
            DEPENDS ${NS_TARGET_NAME}_bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s_ns.o
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/scripts

            # concatenate S + NS binaries into tfm_s_ns.bin
            COMMAND mcuboot_imagesign_assemble
                --layout ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s_ns.o
                --secure ${CMAKE_CURRENT_SOURCE_DIR}/bin/tfm_s.bin
                --non_secure $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${NS_TARGET_NAME}.bin
                --output ${CMAKE_BINARY_DIR}/bin/tfm_s_ns.bin
        )

        set(wrapper_args
            --version    ${MCUBOOT_IMAGE_VERSION_S}
            --layout     ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s_ns.o
            --key        ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/keys/image_s_signing_private_key.pem
            --public-key-format  $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
            --align      ${MCUBOOT_ALIGN_VAL}
            --pad
            --pad-header
            -H           ${BL2_HEADER_SIZE}
            -s           ${MCUBOOT_SECURITY_COUNTER_S}
            -L           ${MCUBOOT_ENC_KEY_LEN}
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
            $<$<BOOL:${MCUBOOT_CONFIRM_IMAGE}>:--confirm>
            $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${MCUBOOT_KEY_ENC}>
            $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
            ${CMAKE_BINARY_DIR}/bin/tfm_s_ns.bin
            ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
        )

        if(MCUBOOT_BUILTIN_KEY)
            set(wrapper_args ${wrapper_args} --psa-key-ids ${TFM_S_KEY_ID})
        endif()

        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
            DEPENDS tfm_s_ns_bin ${CMAKE_BINARY_DIR}/bin/tfm_s_ns.bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/layout_files/signing_layout_s_ns.o
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/image_signing/scripts

            # sign the combined tfm_s_ns.bin file
            COMMAND mcuboot_imagesign_wrapper ${wrapper_args}
            COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/tfm_s_ns_signed.bin
                $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${S_NS_SIGNED_TARGET_NAME}.bin
        )
    endif()
endif()

if(TFM_MERGE_HEX_FILES)
    merge_hex(merged_hex
        OUTPUT         ${CMAKE_BINARY_DIR}/bin/combined.hex
        INPUT_TARGETS  ${NS_TARGET_NAME}_signed_hex
        INPUT_FILES    ${TFM_S_HEX_FILE_PATH}
    )
endif()

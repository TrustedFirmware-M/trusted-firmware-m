#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build a platform on non-secure side.
# The structure and sources list are fully platform specific.

if (NOT TFM_LOAD_NS_IMAGE)
    message(FATAL_ERR "NS image cannot be built with TFM_LOAD_NS_IMAGE=OFF")
endif()

add_library(platform_ns)

target_sources(platform_ns
    PRIVATE
        device/source/device_definition.c
        device/source/startup_rse.c
        device/source/rse_clocks.c
        device/source/system_core_init.c
        uart_stdout.c
)

target_include_directories(platform_ns
    PRIVATE
        cmsis_drivers/config
        device/include
        native_drivers
        cmsis_drivers
    PUBLIC
        device
        include
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        ext/common
        device/config
)

target_link_libraries(platform_ns
    PUBLIC
        platform_region_defs
)

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${RSE_XIP}>:RSE_XIP>
        $<$<BOOL:${RSE_DEBUG_UART}>:RSE_DEBUG_UART>
        $<$<BOOL:${RSE_USE_HOST_UART}>:RSE_USE_HOST_UART>
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:RSE_USE_LOCAL_UART>
        $<$<BOOL:${RSE_USE_HOST_FLASH}>:RSE_USE_HOST_FLASH>
        $<$<BOOL:${RSE_GPT_SUPPORT}>:RSE_GPT_SUPPORT>
        $<$<BOOL:${RSE_HAS_EXPANSION_PERIPHERALS}>:RSE_HAS_EXPANSION_PERIPHERALS>
        $<$<BOOL:${PLATFORM_HAS_PS_NV_OTP_COUNTERS}>:PLATFORM_HAS_PS_NV_OTP_COUNTERS>
        $<$<BOOL:${PLATFORM_ERROR_CODES}>:PLATFORM_ERROR_CODES>
        $<$<BOOL:${RSE_ENABLE_BRINGUP_HELPERS}>:RSE_ENABLE_BRINGUP_HELPERS>
        $<$<BOOL:${RSE_OTP_TRNG}>:RSE_OTP_TRNG>
        $<$<BOOL:${PLAT_MHU_VERSION}>:PLAT_MHU_VERSION=${PLAT_MHU_VERSION}>
        TFM_LOAD_NS_IMAGE
        TFM_UNIQUE_ERROR_CODES=1
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
        subplatform_pal_config
        bl1_2_config
)

if (RSE_XIP)
    find_package(Python3)

    add_custom_target(${NS_TARGET_NAME}_sic_tables
        ALL
        SOURCES ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables.bin
    )

    add_custom_command(OUTPUT ${NS_TARGET_NAME}_sic_tables.bin
        OUTPUT ${NS_TARGET_NAME}_encrypted.bin
        DEPENDS ${NS_TARGET_NAME}_bin
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../image_signing/scripts/create_xip_tables.py
            --input_image $<TARGET_FILE_DIR:${NS_TARGET_NAME}>/${NS_TARGET_NAME}.bin
            --encrypt_key_file ${CMAKE_CURRENT_SOURCE_DIR}/../image_signing/scripts/dummy_guk.bin
            --table_output_file ${NS_TARGET_NAME}_sic_tables.bin
            --encrypted_image_output_file ${NS_TARGET_NAME}_encrypted.bin
            --image_version ${MCUBOOT_SECURITY_COUNTER_NS}
            --label "RUNTIME_NON_SECURE_ENCRYPTION_KEY"
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables.bin ${CMAKE_BINARY_DIR}/bin
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_encrypted.bin ${CMAKE_BINARY_DIR}/bin
    )

    add_library(signing_layout_ns OBJECT ../image_signing/layout_files/signing_layout_sic_tables_ns.c)

    target_compile_options(signing_layout_ns
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-E\;-xc>
            $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
            $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_ns>>
            $<$<C_COMPILER_ID:Clang>:-E\;-xc>
    )
    target_compile_definitions(signing_layout_ns
        PRIVATE
            $<$<BOOL:${BL2}>:BL2>
            $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},DIRECT_XIP>:IMAGE_ROM_FIXED>
    )
    target_link_libraries(signing_layout_ns
        PRIVATE
            platform_region_defs
    )

    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables_signed.bin
        DEPENDS ${NS_TARGET_NAME}_sic_tables
        DEPENDS ${NS_TARGET_NAME}_bin signing_layout_ns
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../image_signing/scripts

        #Sign non-secure binary image with provided secret key
        COMMAND mcuboot_imagesign_wrapper
            -v ${MCUBOOT_IMAGE_VERSION_NS}
            --layout $<TARGET_OBJECTS:signing_layout_ns>
            --key ${CMAKE_CURRENT_SOURCE_DIR}/../image_signing/keys/image_ns_signing_private_key.pem
            --public-key-format $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
            --align ${MCUBOOT_ALIGN_VAL}
            --pad
            --pad-header
            -H ${BL2_HEADER_SIZE}
            -s ${MCUBOOT_SECURITY_COUNTER_NS}
            -L ${MCUBOOT_ENC_KEY_LEN}
            -d \"\(0, ${MCUBOOT_S_IMAGE_MIN_VER}\)\"
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
            $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${CMAKE_CURRENT_SOURCE_DIR}/../image_signing/keys/image_enc_key.pem>
            $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
            ${CMAKE_BINARY_DIR}/bin/${NS_TARGET_NAME}_sic_tables.bin
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
            $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${MCUBOOT_KEY_ENC_NS}>
            $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
            ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables_signed.bin
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables_signed.bin ${CMAKE_BINARY_DIR}/bin
    )

    add_custom_target(signed_images
        ALL
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${NS_TARGET_NAME}_sic_tables_signed.bin
    )
endif()

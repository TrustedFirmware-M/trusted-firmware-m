#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.15)

set(STM_DDR_DIR             ${CMAKE_CURRENT_LIST_DIR})
set(DDR_PHY_BIN_SRC_PATH    "DOWNLOAD"     CACHE PATH   "Path to ddr phy binary (or DOWNLOAD to fetch automatically)")
set(DDR_PHY_BIN_VERSION     "v1.0-stm32mp" CACHE STRING "The version of ddr phy binary to use")

fetch_remote_library(
    LIB_NAME                ddr_phy_bin
    LIB_SOURCE_PATH_VAR     DDR_PHY_BIN_SRC_PATH
    FETCH_CONTENT_ARGS
    GIT_REPOSITORY          https://github.com/STMicroelectronics/stm32-ddr-phy-binary
    GIT_TAG                 ${DDR_PHY_BIN_VERSION}
    GIT_SHALLOW             FALSE
    GIT_PROGRESS            TRUE
    GIT_SUBMODULES          ""
)

# Extract MAJOR/MINOR/REVISION from DDR_PHY_BIN_VERSION (format: v<major>.<minor>[.<revision>]-stm32mp)
# and build a version string compliant with imgtool's expected format (maj[.min[.rev]]).
function(extract_imgtool_version INPUT_VERSION OUT_IMGTOOL_VERSION)
    string(REGEX MATCH "^v?([0-9]+)(\\.([0-9]+)(\\.([0-9]+))?)?(-stm32mp)?$" _match "${INPUT_VERSION}")

    if(NOT _match)
        message(FATAL_ERROR "Version '${INPUT_VERSION}' does not match expected format 'maj[.min[.rev]]'")
    endif()

    set(_major "${CMAKE_MATCH_1}")
    set(_minor "${CMAKE_MATCH_3}")
    set(_revision "${CMAKE_MATCH_5}")

    if(NOT "${_revision}" STREQUAL "")
        set(_normalized "${_major}.${_minor}.${_revision}")
    elseif(NOT "${_minor}" STREQUAL "")
        set(_normalized "${_major}.${_minor}")
    else()
        set(_normalized "${_major}")
    endif()

    set(${OUT_IMGTOOL_VERSION} "${_normalized}" PARENT_SCOPE)
endfunction()

target_include_directories(platform_bl2
    PUBLIC
        ${STM_DDR_DIR}/include
        ${STM_DDR_DIR}/phy/firmware/include
        ${STM_DDR_DIR}/phy/phyinit/include
)

target_sources(platform_bl2
    PRIVATE
        ${STM_DDR_DIR}/stm32mp2_ddr.c
        ${STM_DDR_DIR}/stm32mp_ddr.c
        ${STM_DDR_DIR}/stm32mp2_ddr_helpers.c
        ${STM_DDR_DIR}/stm32mp2_ram.c
        ${STM_DDR_DIR}/stm32mp_ddr_test.c

        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_c_initphyconfig.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_calcmb.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_i_loadpieimage.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_initstruct.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_isdbytedisabled.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_loadpieprodcode.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_mapdrvstren.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_sequence.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_softsetmb.c
        ${STM_DDR_DIR}/phy/phyinit/usercustom/ddrphy_phyinit_usercustom_custompretrain.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_d_loadimem.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_f_loaddmem.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_g_execfw.c
        ${STM_DDR_DIR}/phy/phyinit/src/ddrphy_phyinit_writeoutmem.c
        ${STM_DDR_DIR}/phy/phyinit/usercustom/ddrphy_phyinit_usercustom_g_waitfwdone.c
)

target_compile_definitions(platform_bl2
    PUBLIC
        $<$<STREQUAL:${STM32_DDR_PHY_FILE},ddr4_pmu_train.bin>:STM32MP_DDR4_TYPE=1>
        $<$<STREQUAL:${STM32_DDR_PHY_FILE},lpddr4_pmu_train.bin>:STM32MP_LPDDR4_TYPE=1>
)

# Custom command to install the ddr_phy.bin file
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/bin/ddr_phy.bin
    COMMAND ${CMAKE_COMMAND} -E copy ${DDR_PHY_BIN_SRC_PATH}/stm32mp2/${STM32_DDR_PHY_FILE} ${CMAKE_BINARY_DIR}/bin/ddr_phy.bin
    DEPENDS ${DDR_PHY_BIN_SRC_PATH}/stm32mp2/${STM32_DDR_PHY_FILE}
    COMMENT "Installing ddr_phy.bin"
)

# Custom target to generate ddr_phy.bin
add_custom_target(ddr_phy_bin_target ALL DEPENDS ${CMAKE_BINARY_DIR}/bin/ddr_phy.bin)

#========================= SIGNING ddr_phy.bin =================================#
find_package(Python3)

set(BL2_SOURCE ${CMAKE_SOURCE_DIR}/bl2)
set(API_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/api_ns)

if (NOT EXISTS ${MUCBOOT_KEY_DDRFW})
    set(MUCBOOT_KEY_DDRFW ${MCUBOOT_KEY_NS})
endif()

configure_file(signing_layout.c.in ${CMAKE_CURRENT_BINARY_DIR}/signing_layout.c @ONLY)
add_library(signing_layout_for_ddr_phy OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout.c)

target_link_libraries(signing_layout_for_ddr_phy
    PRIVATE
        platform_bl2
)

target_compile_options(signing_layout_for_ddr_phy
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-E\;-xc>
        $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
)

add_custom_target(ddr_phy_signed_bin
    ALL
    SOURCES ddr_phy_signed.bin
)

extract_imgtool_version("${DDR_PHY_BIN_VERSION}" DDR_PHY_BIN_IMGTOOL_VERSION)

set(wrapper_args
    -v ${DDR_PHY_BIN_IMGTOOL_VERSION}
    --layout $<TARGET_OBJECTS:signing_layout_for_ddr_phy>
    -k ${MUCBOOT_KEY_DDRFW}
    --public-key-format $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
    --align ${MCUBOOT_ALIGN_VAL}
    --pad
    --pad-header
    -H ${BL2_HEADER_SIZE}
    -s ${DDRFW_SECURITY_COUNTER_S}
    -L ${MCUBOOT_ENC_KEY_LEN}
    $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
    $<$<BOOL:${MCUBOOT_CONFIRM_IMAGE}>:--confirm>
    $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${API_SOURCE}/image_signing/keys/image_enc_key.pem>
    $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
    $<TARGET_FILE_DIR:bl2>/ddr_phy.bin
    ${CMAKE_CURRENT_BINARY_DIR}/ddr_phy_signed.bin
)

add_custom_command(
    OUTPUT ddr_phy_signed.bin
    DEPENDS $<TARGET_FILE_DIR:bl2>/ddr_phy.bin
    DEPENDS platform_bl2 signing_layout_for_ddr_phy
    DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
    WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts

    #Sign secure binary image with provided secret key
    COMMAND  mcuboot_imagesign_wrapper ${wrapper_args}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/ddr_phy_signed.bin $<TARGET_FILE_DIR:bl2>
)

# add signing_layout.o in build bin folder.
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/ddrfw_signing_layout.o
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_OBJECTS:signing_layout_for_ddr_phy>
    ${CMAKE_CURRENT_BINARY_DIR}/ddrfw_signing_layout.o
    DEPENDS signing_layout_for_ddr_phy
)

add_custom_target(copy_signing_layout ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/ddrfw_signing_layout.o)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ddrfw_signing_layout.o
    DESTINATION $<TARGET_FILE_DIR:bl2>/layout_files
)

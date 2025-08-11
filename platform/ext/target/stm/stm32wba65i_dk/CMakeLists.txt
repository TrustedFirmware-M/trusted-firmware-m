#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

if(POLICY CMP0115)
    cmake_policy(SET CMP0115 OLD)
endif()
set(STM32WBA65I_DK_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${STM32WBA65I_DK_DIR}/../common)

#def for stm32wbaxx
include(${STM_COMMON_DIR}/stm32wbaxx/CMakeLists.txt)
#========================= Platform defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/stm32wbaxx/Device/Source/startup_stm32wbaxx_s.c
)

target_sources(platform_s
    PRIVATE
        ${STM_COMMON_DIR}/hal/provision/otp_provision.c
)

if(NS)
target_sources(${NS_TARGET_NAME}
        PRIVATE
            ${STM_COMMON_DIR}/stm32wbaxx/Device/Source/startup_stm32wbaxx_ns.c
    )
endif()

install(FILES
    ${STM32WBA65I_DK_DIR}/partition/flash_layout.h
    ${STM32WBA65I_DK_DIR}/partition/region_defs.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

set (BL2_FILE_TO_PREPROCESS ${CMAKE_CURRENT_BINARY_DIR}/image_macros_to_preprocess_bl2.c)
file(WRITE ${BL2_FILE_TO_PREPROCESS} ${BL2_PREPROCESSING})

install(FILES
    ${BL2_FILE_TO_PREPROCESS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
################# Install platform files for NS build #################

# cpuarch.cmake is used to set things that related to the platform that are both
install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/include
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/accelerator/crypto_accelerator_config.h
DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${STM_COMMON_DIR}/hal/accelerator/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
        FILES_MATCHING PATTERN "*.h")

install(FILES
    ${STM32WBA65I_DK_DIR}/partition/region_defs.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition
)

# Install a flash_layout.h header file that consider STM32_FLASH_LAYOUT_BEGIN_OFFSET
# TF-M was built with.
install(FILES
    ${STM32WBA65I_DK_DIR}/partition/flash_layout.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition/gen_layout
)

file(WRITE ${INSTALL_PLATFORM_NS_DIR}/partition/flash_layout.h
  "#define STM32_FLASH_LAYOUT_BEGIN_OFFSET ${STM32_FLASH_LAYOUT_BEGIN_OFFSET}\n"
  "#include \"gen_layout/flash_layout.h\"\n"
)

install(DIRECTORY   ${PLATFORM_DIR}/ext/common
                    ${PLATFORM_DIR}/ext/driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext)

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Extract firmware and OTP binary image files
get_target_property(tfm_s_bin_dir tfm_s RUNTIME_OUTPUT_DIRECTORY)

set(tfm_s_split_out
    ${tfm_s_bin_dir}/tfm_s_fmw.bin
    ${tfm_s_bin_dir}/tfm_s_otp.bin
)

add_custom_target(tfm_s_fmw ALL SOURCES ${tfm_s_split_out})

if(CMAKE_C_COMPILER STREQUAL "iccarm")
add_custom_command(
  OUTPUT ${tfm_s_split_out}
  DEPENDS tfm_s_bin
  COMMAND ielftool --silent --exclude=.BL2_OTP --bin $<TARGET_FILE:tfm_s> ${tfm_s_bin_dir}/tfm_s_fmw.bin
  COMMAND ielftool --silent --only=.BL2_OTP --bin $<TARGET_FILE:tfm_s> ${tfm_s_bin_dir}/tfm_s_otp.bin
)
else()
add_custom_command(
  OUTPUT ${tfm_s_split_out}
  DEPENDS tfm_s_bin
  COMMAND ${CMAKE_OBJCOPY} --remove-section .BL2_OTP -O binary $<TARGET_FILE:tfm_s> ${tfm_s_bin_dir}/tfm_s_fmw.bin
  COMMAND ${CMAKE_OBJCOPY} --only-section .BL2_OTP -O binary $<TARGET_FILE:tfm_s> ${tfm_s_bin_dir}/tfm_s_otp.bin
)
endif()

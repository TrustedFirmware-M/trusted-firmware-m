#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/boards
)

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<OR:$<BOOL:${TEST_NS}>,$<BOOL:${TEST_S}>>:FLASH_LAYOUT_FOR_TEST>
)

#========================= Platform common defs ===============================#
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/armclang/tfm_common_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/tfm_common_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/iar/tfm_common_s.icf>
)

if(BL2)
    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${STM_COMMON_DIR}/hal/template/gcc/bl2.ld>
        $<$<C_COMPILER_ID:ARMClang>:${STM_COMMON_DIR}/hal/template/armclang/bl2.sct>
        $<$<C_COMPILER_ID:IAR>:${STM_COMMON_DIR}/hal/template/iar/bl2.icf>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${STM_COMMON_DIR}/hal/Native_Driver
        ${STM_COMMON_DIR}/hal/CMSIS_Driver
        ${CMAKE_CURRENT_SOURCE_DIR}/Device/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/secure
        ${MBEDCRYPTO_PATH}/library
        ${CMAKE_SOURCE_DIR}/include
)

target_sources(platform_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/secure/system_stm32u5xx.c
        ${STM_COMMON_DIR}/hal/Native_Driver/mpu_armv8m_drv.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/secure/low_level_device.c
        ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_flash.c
        ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_com.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_flash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_flash_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_gtzc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cortex.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/secure/tfm_platform_system.c>
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rng.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rng_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_ospi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_ll_dlyb.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rtc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rtc_ex.c
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_rng.c>
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_hash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_hash_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pka.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cryp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cryp_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_i2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_i2c_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_icache.c
        ${STM_COMMON_DIR}/hal/Native_Driver/low_level_rng.c
        ${STM_COMMON_DIR}/hal/Native_Driver/nv_counters.c
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

# GNU ld and IAR does not deal well with strong functions in static libraries
# overriding weak functions in object files. For this reason, files with strong
# functions are linked as an object file. This issue does not affect armclang,
# but the fix is compatible.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/hal/Native_Driver/tick.c
)

#========================= Platform Non-Secure ================================#

# Install linker scripts
install(FILES
    ${STM_COMMON_DIR}/hal/template/iar/appli_ns.icf
    ${STM_COMMON_DIR}/hal/template/gcc/appli_ns.ld
    ${STM_COMMON_DIR}/hal/template/armclang/appli_ns.sct
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts
)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/Device/Include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device
)

install(FILES
    ${PLATFORM_DIR}/ext/common/test_interrupt.h
    ${PLATFORM_DIR}/include/tfm_plat_defs.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/Inc
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/hal
)

install(FILES
    ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_com.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/CMSIS_Driver
)
install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/Templates/system_stm32u5xx.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source/
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/boards/cmsis.h
    ${CMAKE_CURRENT_SOURCE_DIR}/boards/target_cfg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/boards/tfm_peripherals_def.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
)


install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cortex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc_ex.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/hal/Src
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_include_directories(platform_bl2
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${STM_COMMON_DIR}/hal/Native_Driver
            ${STM_COMMON_DIR}/hal/CMSIS_Driver
            ${CMAKE_CURRENT_SOURCE_DIR}/Device/Include
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Inc
            ${MCUBOOT_PATH}/boot/bootutil/include
            $<TARGET_PROPERTY:bl2,BINARY_DIR>/ext/mcuboot
            ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/include
            ${CMAKE_CURRENT_SOURCE_DIR}/bl2
            ${CMAKE_SOURCE_DIR}/interface/include
    )

    target_sources(platform_bl2
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/Templates/system_stm32u5xx.c
            ${CMAKE_CURRENT_SOURCE_DIR}/bl2/boot_hal_bl2.c
            ${STM_COMMON_DIR}/hal/Native_Driver/mpu_armv8m_drv.c
            ${CMAKE_CURRENT_SOURCE_DIR}/bl2/low_level_security.c
            ${CMAKE_CURRENT_SOURCE_DIR}/bl2/low_level_device.c
            ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_flash.c
            ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_com.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_flash.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_flash_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_dma_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pwr.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rcc_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cortex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_gpio.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_uart_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_gtzc.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_hash.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_hash_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_pka.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cryp.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_cryp_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rng.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rng_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rtc.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_rtc_ex.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_icache.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_hal_ospi.c
            ${CMAKE_CURRENT_SOURCE_DIR}/hal/Src/stm32u5xx_ll_dlyb.c
            ${STM_COMMON_DIR}/hal/Native_Driver/low_level_rng.c
            ${STM_COMMON_DIR}/hal/provision/otp_provision.c
            ${STM_COMMON_DIR}/hal/Native_Driver/nv_counters.c
            ${STM_COMMON_DIR}/hal/provision/nvm_init.c
            ${STM_COMMON_DIR}/hal/provision/nvmcnt_init.c
    )

    target_compile_options(platform_bl2
        PUBLIC
            ${COMPILER_CMSE_FLAG}
    )

    # GNU ld and IAR does not deal well with strong functions in static libraries
    # overriding weak functions in object files. For this reason, files with strong
    # functions are linked as an object file. This issue does not affect armclang,
    # but the fix is compatible.
    target_sources(bl2
        PRIVATE
            ${STM_COMMON_DIR}/hal/Native_Driver/tick.c
            ${CMAKE_CURRENT_SOURCE_DIR}/bl2/stm32u5xx_hal_msp.c
    )

endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/secure/target_cfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/secure/tfm_hal_isolation.c
        ${CMAKE_CURRENT_SOURCE_DIR}/secure/tfm_hal_platform.c
)

install(FILES
        ${STM_COMMON_DIR}/scripts/stm_tool.py
        ${STM_COMMON_DIR}/scripts/bin2hex.py
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../bl2/ext/mcuboot/scripts/macro_parser.py
        DESTINATION ${CMAKE_INSTALL_PREFIX}/scripts )

if (${CMAKE_C_COMPILER_ID} STREQUAL GNU)
    set(PREPROCESSOR_FILE ${STM_COMMON_DIR}/scripts/gcc/preprocess.sh)
elseif (${CMAKE_C_COMPILER_ID} STREQUAL ARMClang)
    set(PREPROCESSOR_FILE ${STM_COMMON_DIR}/scripts/armclang/preprocess.sh)
else()
    set(PREPROCESSOR_FILE ${STM_COMMON_DIR}/scripts/iar/preprocess.sh)
endif()

install(FILES ${STM_COMMON_DIR}/scripts/regression.sh
         ${PREPROCESSOR_FILE}
         ${STM_COMMON_DIR}/scripts/TFM_UPDATE.sh
         ${STM_COMMON_DIR}/scripts/TFM_BIN2HEX.sh
         ${STM_COMMON_DIR}/scripts/postbuild.sh
         PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
         DESTINATION ${CMAKE_INSTALL_PREFIX} )

if (${TEST_S} OR ${TEST_NS})
    #the define FLASH_LAYOUT_FOR_TEST
    #increase SECURE and NON SECURE IMAGE and modify the  content of  low_level_device.c from BL2 (low_level_flash.c)
    set(FLAGS_FOR_BL2_PREPROCESSING
        "#define FLASH_LAYOUT_FOR_TEST\n"
        "#define BL2\n"
        "#define MCUBOOT_IMAGE_NUMBER 2\n"
        "#define MCUBOOT_OVERWRITE_ONLY\n"
         )
    add_definitions("-DFLASH_LAYOUT_FOR_TEST")
else()
    set(FLAGS_FOR_BL2_PREPROCESSING
        "#define BL2\n"
        "#define MCUBOOT_IMAGE_NUMBER 2\n"
        "#define MCUBOOT_OVERWRITE_ONLY\n"
       )
endif()

set(CONTENT_FOR_BL2_PREPROCESSING
    "#include \"flash_layout.h\"\n\n"
    "enum bl2_image_attributes {\n"
    "\tRE_IMAGE_FLASH_ADDRESS_SECURE = (FLASH_BASE_ADDRESS+FLASH_AREA_0_OFFSET),\n"
    "\tRE_IMAGE_FLASH_ADDRESS_NON_SECURE = (FLASH_BASE_ADDRESS+FLASH_AREA_1_OFFSET),\n"
    "\tRE_BL2_BIN_ADDRESS = (FLASH_BASE_ADDRESS+FLASH_AREA_BL2_BIN_OFFSET),\n"
    "\tRE_BL2_NVMCNT_ADDRESS = (FLASH_BASE_ADDRESS+FLASH_BL2_NVCNT_AREA_OFFSET),\n"
    "\tRE_BL2_PROVISION_ADDRESS = (FLASH_BASE_ADDRESS+FLASH_AREA_OTP_OFFSET),\n"
    "\tRE_BL2_BOOT_ADDRESS = (FLASH_BASE_ADDRESS+FLASH_AREA_BL2_OFFSET),\n"
    "\tRE_BL2_WRP_START = (FLASH_AREA_BL2_OFFSET),\n"
    "\tRE_BL2_WRP_END = (FLASH_AREA_BL2_NOHDP_OFFSET+FLASH_AREA_BL2_NOHDP_SIZE-0x1),\n"
    "\tRE_BL2_HDP_END = (FLASH_AREA_BL2_NOHDP_OFFSET-0x1),\n"
    "#if defined(EXTERNAL_FLASH)\n"
    "\tRE_IMAGE_FLASH_SECURE_UPDATE = (OSPI_FLASH_BASE_ADDRESS+FLASH_AREA_2_OFFSET),\n"
    "\tRE_IMAGE_FLASH_NON_SECURE_UPDATE = (OSPI_FLASH_BASE_ADDRESS+FLASH_AREA_3_OFFSET),\n"
    "\tRE_IMAGE_FLASH_UNUSED = (FLASH_BASE_ADDRESS+FLASH_AREA_1_OFFSET+FLASH_AREA_1_SIZE),\n"
    "#else\n"
    "\tRE_IMAGE_FLASH_SECURE_UPDATE = (FLASH_BASE_ADDRESS+FLASH_AREA_2_OFFSET),\n"
    "\tRE_IMAGE_FLASH_NON_SECURE_UPDATE = (FLASH_BASE_ADDRESS+FLASH_AREA_3_OFFSET),\n"
    "\tRE_IMAGE_FLASH_UNUSED = (FLASH_BASE_ADDRESS+FLASH_AREA_3_OFFSET+FLASH_AREA_3_SIZE),\n"
    "#endif\n"
    "\tRE_IMAGE_FLASH_SCRATCH = (FLASH_BASE_ADDRESS+FLASH_AREA_SCRATCH_OFFSET),\n"
    "\tRE_IMAGE_FLASH_NV_COUNTERS = (FLASH_BASE_ADDRESS+FLASH_NV_COUNTERS_AREA_OFFSET),\n"
    "\tRE_IMAGE_FLASH_NV_PS = (FLASH_BASE_ADDRESS+FLASH_PS_AREA_OFFSET),\n"
    "\tRE_IMAGE_FLASH_NV_ITS = (FLASH_BASE_ADDRESS+FLASH_ITS_AREA_OFFSET),\n"
)
if(MCUBOOT_ENC_IMAGES)
    set(CONTENT_ENCRYPTED
    "\tRE_IMAGE_ENCRYPTED = 0x01\n}\;"
    )
else()
    set(CONTENT_ENCRYPTED
    "\tRE_IMAGE_ENCRYPTED = 0x0\n}\;"
    )
endif()

string(CONCAT BL2_PREPROCESSING ${FLAGS_FOR_BL2_PREPROCESSING}
       ${CONTENT_FOR_BL2_PREPROCESSING}
       ${CONTENT_ENCRYPTED})

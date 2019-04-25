#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#This file is derived from musca_a.cmake file
#This file gathers all twincpu ref platform specific files in the application.

#reference twincpu platform has M4 on host side
include("Common/CpuM4")

set(PLATFORM_DIR ${CMAKE_CURRENT_LIST_DIR})

#Specify the location of platform specific build dependencies.
if(COMPILER STREQUAL "ARMCLANG")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/ref_twincpu_bl2.sct")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/ref_twincpu_s.sct")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/ref_twincpu_ns.sct")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/ARM/RTX_CM4F.lib")
    endif()
elseif(COMPILER STREQUAL "GNUARM")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/ref_twincpu_bl2.ld")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/ref_twincpu_s.ld")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/ref_twincpu_ns.ld")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/GCC/libRTX_CM4F.a")
    endif()
else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
endif()
set (FLASH_LAYOUT          "${PLATFORM_DIR}/target/ref_twincpu/partition/flash_layout.h")
set (PLATFORM_LINK_INCLUDES "${PLATFORM_DIR}/target/ref_twincpu/partition")
set (SIGN_BIN_SIZE         0x100000)

if (BL2)
  set (BL2_LINKER_CONFIG ${BL2_SCATTER_FILE_NAME})
endif()

embedded_include_directories(PATH "${PLATFORM_DIR}/cmsis" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/Device/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/Device/Include" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/partition" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/Libraries" ABSOLUTE)

#Gather all source files we need.
if (NOT DEFINED BUILD_CMSIS_CORE)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_CORE (true|false) is undefined!")
elseif(BUILD_CMSIS_CORE)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/system_cmsdk_ref_twincpu.c")
endif()

if (NOT DEFINED BUILD_RETARGET)
  message(FATAL_ERROR "Configuration variable BUILD_RETARGET (true|false) is undefined!")
elseif(BUILD_RETARGET)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/platform_retarget_dev.c")
endif()

if (NOT DEFINED BUILD_UART_STDOUT)
  message(FATAL_ERROR "Configuration variable BUILD_UART_STDOUT (true|false) is undefined!")
elseif(BUILD_UART_STDOUT)
  if (NOT DEFINED SECURE_UART1)
    message(FATAL_ERROR "Configuration variable SECURE_UART1 (true|false) is undefined!")
  elseif(SECURE_UART1)
    message(FATAL_ERROR "Configuration SECURE_UART1 TRUE is invalid for this target!")
  endif()
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/uart_stdout.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/common" ABSOLUTE)
  set(BUILD_NATIVE_DRIVERS true)
  set(BUILD_CMSIS_DRIVERS true)
endif()

if (NOT DEFINED BUILD_NATIVE_DRIVERS)
  message(FATAL_ERROR "Configuration variable BUILD_NATIVE_DRIVERS (true|false) is undefined!")
elseif(BUILD_NATIVE_DRIVERS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/uart_pl011_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/ref_twincpu_scc_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/qspi_ip6514e_drv.c")

  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/mpc_sie200_drv.c"
              "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/ppc_sse200_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/qspi_ip6514e_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Libraries/mt25ql_flash_lib.c")
endif()

if (NOT DEFINED BUILD_TIME)
  message(FATAL_ERROR "Configuration variable BUILD_TIME (true|false) is undefined!")
elseif(BUILD_TIME)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/timer_cmsdk.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_STARTUP)
  message(FATAL_ERROR "Configuration variable BUILD_STARTUP (true|false) is undefined!")
elseif(BUILD_STARTUP)
  if(CMAKE_C_COMPILER_ID STREQUAL "ARMCLANG")
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/startup_cmsdk_ref_twincpu_s.s")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/startup_cmsdk_ref_twincpu_ns.s")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/armclang/startup_cmsdk_ref_twincpu_bl2.s")
  elseif(CMAKE_C_COMPILER_ID STREQUAL "GNUARM")
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/startup_cmsdk_ref_twincpu_s.S")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/startup_cmsdk_ref_twincpu_ns.S")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/ref_twincpu/Device/Source/gcc/startup_cmsdk_ref_twincpu_bl2.S")
    set_property(SOURCE "${ALL_SRC_ASM_S}" "${ALL_SRC_ASM_NS}" "${ALL_SRC_ASM_BL2}" APPEND
      PROPERTY COMPILE_DEFINITIONS "__STARTUP_CLEAR_BSS_MULTIPLE" "__STARTUP_COPY_MULTIPLE")
  else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
  endif()
endif()

if (NOT DEFINED BUILD_TARGET_CFG)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_CFG (true|false) is undefined!")
elseif(BUILD_TARGET_CFG)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/target_cfg.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/spm_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/attest_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/Native_Driver/mpu_armv8m_drv.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/tfm_platform_system.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/common" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_TARGET_HARDWARE_KEYS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_HARDWARE_KEYS (true|false) is undefined!")
elseif(BUILD_TARGET_HARDWARE_KEYS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/tfm_initial_attestation_key_material.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/dummy_crypto_keys.c")
endif()

if (NOT DEFINED BUILD_TARGET_NV_COUNTERS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_NV_COUNTERS (true|false) is undefined!")
elseif(BUILD_TARGET_NV_COUNTERS)
  # NOTE: This non-volatile counters implementation is a dummy
  #       implementation. Platform vendors have to implement the
  #       API ONLY if the target has non-volatile counters.
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/dummy_nv_counters.c")
  set(TARGET_NV_COUNTERS_ENABLE ON)
  # Sets SST_ROLLBACK_PROTECTION flag to compile in the SST services
  # rollback protection code as the target supports nv counters.
  set (SST_ROLLBACK_PROTECTION ON)
endif()

if (NOT DEFINED BUILD_CMSIS_DRIVERS)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_DRIVERS (true|false) is undefined!")
elseif(BUILD_CMSIS_DRIVERS)
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver/Driver_MPC.c"
    "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver/Driver_PPC.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver/Driver_USART.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_FLASH)
  message(FATAL_ERROR "Configuration variable BUILD_FLASH (true|false) is undefined!")
elseif(BUILD_FLASH)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver/Driver_Flash.c")
  # As the SST area is going to be in RAM, it is required to set SST_CREATE_FLASH_LAYOUT
  # to be sure the SST service knows that when it starts the SST area does not contain any
  # valid SST flash layout and it needs to create one.
  set(SST_CREATE_FLASH_LAYOUT ON)
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/ref_twincpu/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT BL2)
	message(STATUS "WARNING: BL2 is mandatory on target \"${TARGET_PLATFORM}\" Your choice was override.")
	set(BL2 True)
endif()

if (MCUBOOT_NO_SWAP)
	message (FATAL_ERROR "MCUBOOT_NO_SWAP configuration is not supported on " ${TARGET_PLATFORM})
endif()

if (NOT DEFINED BUILD_BOOT_SEED)
  message(FATAL_ERROR "Configuration variable BUILD_BOOT_SEED (true|false) is undefined!")
elseif(BUILD_BOOT_SEED)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/dummy_boot_seed.c")
endif()

if (NOT DEFINED BUILD_DEVICE_ID)
  message(FATAL_ERROR "Configuration variable BUILD_DEVICE_ID (true|false) is undefined!")
elseif(BUILD_DEVICE_ID)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/ref_twincpu/dummy_device_id.c")
endif()

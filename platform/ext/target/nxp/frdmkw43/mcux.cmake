# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.tfm.s.board)
    mcux_add_macro(
        CC "-DUSE_SGI_HUK\
        "
    )
    mcux_add_source(
        SOURCES
        ./common/crypto_key/sgi_based/crypto_keys.c
        ./frdmkw43/target_cfg.c
        ./frdmkw43/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmkw43
    )
endif()
if (CONFIG_MCUX_COMPONENT_middleware.tfm.ns.board)
    mcux_add_source(
        SOURCES
        ./frdmkw43/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmkw43
    )
endif()
if (CONFIG_MCUX_COMPONENT_middleware.tfm.board_headers)
    mcux_add_macro(
        CC "-DTARGET_CONFIG_HEADER_FILE=\\\"config_tfm_target.h\\\"\
        "
    )
    mcux_add_source(
        SOURCES
        ./common/target_cfg_common.h
        ./frdmkw43/platform_psa_hw_accel.h
        ./frdmkw43/config_tfm_target.h
        ./frdmkw43/target_cfg.h
        ./frdmkw43/tfm_peripherals_def.h
        ./frdmkw43/Device/Include/platform_base_address.h
        ./frdmkw43/partition/region_defs.h
        ./frdmkw43/partition/flash_layout.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmkw43
    )
    mcux_add_include(
        INCLUDES
        ./common/
        ./frdmkw43/
        ./frdmkw43/partition
        ./frdmkw43/Device/Include/
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmkw43
    )
endif()
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
        ./frdmmcxw70/target_cfg.c
        ./frdmmcxw70/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxw70
    )
endif()
if (CONFIG_MCUX_COMPONENT_middleware.tfm.ns.board)
    mcux_add_source(
        SOURCES
        ./frdmmcxw70/Device/Source/startup_${board}.c
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxw70
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
        ./frdmmcxw70/platform_psa_hw_accel.h
        ./frdmmcxw70/config_tfm_target.h
        ./frdmmcxw70/target_cfg.h
        ./frdmmcxw70/tfm_peripherals_def.h
        ./frdmmcxw70/Device/Include/platform_base_address.h
        ./frdmmcxw70/partition/region_defs.h
        ./frdmmcxw70/partition/flash_layout.h
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxw70
    )
    mcux_add_include(
        INCLUDES
        ./common/
        ./frdmmcxw70/
        ./frdmmcxw70/partition
        ./frdmmcxw70/Device/Include/
        BASE_PATH ${SdkRootDirPath}/middleware/tfm/tf-m/platform/ext/target/nxp
        BOARDS frdmmcxw70
    )
endif()
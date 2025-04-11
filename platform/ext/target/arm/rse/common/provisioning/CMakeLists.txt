#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

add_subdirectory(bundle)

target_sources(platform_s
    PRIVATE
        ./runtime_stub_provisioning.c
        $<$<BOOL:${RSE_HAS_DCSU}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_provisioning_comms_dcsu.c>
        $<$<NOT:$<BOOL:${RSE_HAS_DCSU}>>:${CMAKE_CURRENT_SOURCE_DIR}/rse_provisioning_comms_stub.c>
)

target_sources(platform_bl2
    PRIVATE
        ./bl2_stub_provisioning.c
)

target_sources(platform_bl1_2
    PRIVATE
        ./bl1_2_provisioning.c
)

target_sources(platform_bl1_1
    PRIVATE
        ./bl1_1_provisioning.c
        $<$<BOOL:${RSE_HAS_DCSU}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_provisioning_comms_dcsu.c>
        $<$<NOT:$<BOOL:${RSE_HAS_DCSU}>>:${CMAKE_CURRENT_SOURCE_DIR}/rse_provisioning_comms_stub.c>
        ./rse_provisioning_message_handler.c
        ./rse_provisioning_rotpk.c
        ./rse_provisioning_tci_key.c
        ./rse_provisioning_aes_key.c
)

target_link_libraries(platform_bl1_1
    PUBLIC
        tfm_log
        tfm_vprintf
)

target_include_directories(platform_bl1_1_interface
    INTERFACE
        ./bundle_common
        ../bl1
        .
)

add_custom_target(cm_provisioning_key
    ALL
    SOURCES ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin
    SOURCES ${CMAKE_BINARY_DIR}/bin/keys/kmaster_cm.bin
)

add_custom_target(dm_provisioning_key
    ALL
    SOURCES ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
    SOURCES ${CMAKE_BINARY_DIR}/bin/keys/kmaster_dm.bin
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/keys)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin
    OUTPUT ${CMAKE_BINARY_DIR}/bin/keys/kmaster_cm.bin
    DEPENDS ${RSE_RTL_KEY_PATH}
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/derive_provisioning_master_key.py
        --krtl=${RSE_RTL_KEY_PATH}
        --key_owner=CM
        --batch_number=${RSE_BATCH_NUMBER}
        --kmaster_file=${CMAKE_BINARY_DIR}/bin/keys/kmaster_cm.bin

    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/derive_provisioning_key.py
        --kmaster=${CMAKE_BINARY_DIR}/bin/keys/kmaster_cm.bin
        --key_owner=CM
        --kprov_file=${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
    OUTPUT ${CMAKE_BINARY_DIR}/bin/keys/kmaster_dm.bin
    DEPENDS ${RSE_RTL_KEY_PATH}
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/derive_provisioning_master_key.py
        --krtl=${RSE_RTL_KEY_PATH}
        --key_owner=DM
        --dm_number=${RSE_DM_NUMBER}
        --kmaster_file=${CMAKE_BINARY_DIR}/bin/keys/kmaster_dm.bin

    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/derive_provisioning_key.py
        --kmaster=${CMAKE_BINARY_DIR}/bin/keys/kmaster_dm.bin
        --key_owner=DM
        --kprov_file=${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
)

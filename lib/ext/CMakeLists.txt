#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/lib/ext CACHE STRING "" FORCE)

add_subdirectory(qcbor)
add_subdirectory(tf-psa-crypto)
add_subdirectory(t_cose)
add_subdirectory(cmsis)
add_subdirectory(efi_soft_crc)
if (${PLATFORM_PSA_ADAC_SECURE_DEBUG})
    add_subdirectory(psa-adac)
endif()
add_subdirectory(tf-m-extras)

if (${TFM_PARTITION_DTPM_CLIENT})
    add_subdirectory(eventlog)
    add_subdirectory(dtpm)
endif()

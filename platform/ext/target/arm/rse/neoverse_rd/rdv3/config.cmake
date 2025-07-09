#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Note: Cached variables always take the first value set, while normal
# variables always take the last.

set(PLAT_NEOVERSE_HOST_VERSION_VERSION  3        CACHE STRING  "Version of Neoverse-RD host mapping to use - corresponds to nrdX directories.")
if (TFM_PLATFORM_VARIANT STREQUAL "1")
    set(MULTI_RSE_TOPOLOGY_FILE             ${CMAKE_CURRENT_LIST_DIR}/rse_comms/rdv3.tgf CACHE STRING "Topology file for RSE to RSE BL1 communication")
    set(PLAT_LCP_COUNT                      8        CACHE STRING  "Number of LCPs to load")
elseif (TFM_PLATFORM_VARIANT STREQUAL "2")
    set(PLAT_LCP_COUNT                      4        CACHE STRING  "Number of LCPs to load")
    set(RSE_AMOUNT                          4        CACHE STRING  "Amount of RSEs in the system")
    set(MULTI_RSE_TOPOLOGY_FILE             ${CMAKE_CURRENT_LIST_DIR}/rse_comms/rdv3cfg2.tgf CACHE STRING "Topology file for RSE to RSE BL1 communication")
    set(RSE_OTP_HAS_ROUTING_TABLES          ON       CACHE BOOL    "Whether the RSE OTP contains the RSE communications routing tables")
else()
    set(MULTI_RSE_TOPOLOGY_FILE             ${CMAKE_CURRENT_LIST_DIR}/rse_comms/rdv3.tgf CACHE STRING "Topology file for RSE to RSE BL1 communication")
    set(PLAT_LCP_COUNT                      16       CACHE STRING  "Number of LCPs to load")
endif()

# Once all cache options are set, set common options as fallback
include(${CMAKE_CURRENT_LIST_DIR}/../common/config.cmake)

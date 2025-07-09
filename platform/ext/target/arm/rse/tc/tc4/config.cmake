#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(RSE_XIP                        ON    CACHE BOOL   "Whether to run runtime firmware XIP via the SIC")

set(PLAT_MHU_VERSION               3     CACHE STRING "Supported MHU version by platform")

set(RSE_USE_HOST_UART              OFF   CACHE BOOL   "Whether RSE should setup to use the UART from the host system")
set(RSE_USE_LOCAL_UART             ON    CACHE BOOL   "Whether RSE should setup to use the UART local to the RSE subsystem")

set(TFM_ATTESTATION_SCHEME         "DPE" CACHE STRING "Attestation scheme to use [OFF, PSA, CCA, DPE]")

set(RSE_SUPPORT_ROM_LIB_RELOCATION ON    CACHE BOOL   "Whether shared ROM code supports being copied to SRAM and then executed")

set(RSE_COMMS_NUMBER_NODES         4     CACHE STRING "Amount of nodes in the RSE comms system, by default equal to number of RSEs")
set(MULTI_RSE_TOPOLOGY_FILE     ${CMAKE_CURRENT_LIST_DIR}/../common/rse_comms/tc.tgf CACHE STRING "Topology file for RSE communications")

# Once all options are set, set common options as fallback

include(${CMAKE_CURRENT_LIST_DIR}/../../common/config.cmake)

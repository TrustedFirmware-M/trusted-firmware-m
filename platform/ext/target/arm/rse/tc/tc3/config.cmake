#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(RSE_XIP                     ON     CACHE BOOL    "Whether to run runtime firmware XIP via the SIC")

set(PLAT_MHU_VERSION            3      CACHE STRING  "Supported MHU version by platform")

set(TFM_ATTESTATION_SCHEME      "DPE"  CACHE STRING  "Attestation scheme to use [OFF, PSA, CCA, DPE]")

set(SFCP_NUMBER_NODES           4      CACHE STRING "Amount of nodes in the SFCP system, by default equal to number of RSEs")
set(MULTI_RSE_TOPOLOGY_FILE     ${CMAKE_CURRENT_LIST_DIR}/../common/sfcp/tc.tgf CACHE STRING "Topology file for RSE communications")

# Once all options are set, set common options as fallback

include(${CMAKE_CURRENT_LIST_DIR}/../../common/config.cmake)

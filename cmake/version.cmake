#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# The 'TFM_VERSION_MANUAL' is used for fallback when Git tags are not available
set(TFM_VERSION_MANUAL "2.2.1")

execute_process(COMMAND git describe --always --candidates=1
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE TFM_VERSION_FULL
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULTS_VARIABLE GIT_RESULT)

if(GIT_RESULT EQUAL 128)
    # Git execution fails.
    # Applying a manual version assuming the code tree is a local copy.
    set(TFM_VERSION_FULL "v${TFM_VERSION_MANUAL}")
    return()
endif()

# In a repository cloned with --no-tags option TFM_VERSION_FULL will be a hash
# only hence checking it for a tag format to accept as valid version.

string(FIND "${TFM_VERSION_FULL}" "TF-M" TFM_TAG)
if(TFM_TAG EQUAL -1)
    execute_process(COMMAND git log --format=format:%h -n 1
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE TFM_GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE)

    set(TFM_VERSION_FULL "v${TFM_VERSION_MANUAL}+g${TFM_GIT_HASH}")
endif()

string(REGEX REPLACE "TF-M" "" TFM_VERSION_FULL ${TFM_VERSION_FULL})
# remove a commit number
string(REGEX REPLACE "-[0-9]+-g" "+" TFM_VERSION_FULL ${TFM_VERSION_FULL})
string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" TFM_VERSION ${TFM_VERSION_FULL})

# Check that manually set version is up to date
if (NOT TFM_VERSION_MANUAL STREQUAL TFM_VERSION)
    message(WARNING "TFM_VERSION_MANUAL=" ${TFM_VERSION_MANUAL} " mismatches to actual TF-M version=" ${TFM_VERSION} ". Please update TFM_VERSION_MANUAL in cmake/version.cmake")
endif()

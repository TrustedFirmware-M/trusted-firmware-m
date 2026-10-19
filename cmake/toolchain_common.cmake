#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

function(_target_add_scatter_file target)
    add_library(${target}_scatter OBJECT)
    foreach(scatter_file ${ARGN})
        target_sources(${target}_scatter PRIVATE ${scatter_file}
        )
        # Cmake cannot use generator expressions in the
        # set_source_file_properties command, so instead we just parse the regex
        # for the filename and set the property on all files, regardless of if
        # the generator expression would evaluate to true or not.
        string(REGEX REPLACE ".*>:(.*)>$" "\\1" SCATTER_FILE_PATH "${scatter_file}")
        set_source_files_properties(${SCATTER_FILE_PATH}
            PROPERTIES
            LANGUAGE C
            KEEP_EXTENSION True # Do not use .o extension for the preprocessed file
        )
    endforeach()

    add_dependencies(${target} ${target}_scatter)

    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${target}_scatter>)

    target_link_libraries(${target}_scatter
        platform_region_defs
        psa_interface
        tfm_config
    )
endfunction()

function(_target_link_shared_code target use_just_symbols)
    foreach(symbol_provider ${ARGN})
        if (TARGET ${symbol_provider})
            get_target_property(SYMBOL_PROVIDER_TYPE ${symbol_provider} TYPE)
            if (NOT SYMBOL_PROVIDER_TYPE STREQUAL "EXECUTABLE")
                message(FATAL_ERROR "${symbol_provider} is not an executable. Symbols cannot be shared from libraries.")
            endif()
        endif()

        # Ensure ${symbol_provider}_shared_symbols is built before ${target}
        add_dependencies(${target} ${symbol_provider}_shared_symbols)
        # ${symbol_provider}_shared_symbols - a custom target is always considered out-of-date
        # To only link when necessary, depend on ${symbol_provider} instead
        set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS $<TARGET_OBJECTS:${symbol_provider}>)

        if (${use_just_symbols})
            target_link_options(${target} PRIVATE
                LINKER:--just-symbols
                $<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX}
            )
        else()
            target_link_options(${target} PRIVATE
                LINKER:$<TARGET_FILE_DIR:${symbol_provider}>/${symbol_provider}${CODE_SHARING_INPUT_FILE_SUFFIX}
            )
        endif()
    endforeach()
endfunction()

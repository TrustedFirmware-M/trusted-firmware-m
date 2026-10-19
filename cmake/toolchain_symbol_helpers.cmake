#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

function(target_strip_symbols target)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --strip-symbol=)

    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${target}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${target}>
    )
endfunction()

function(target_strip_symbols_from_dependency target dependency)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --strip-symbol=)

    add_custom_command(
        TARGET ${target}
        PRE_LINK
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${dependency}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${dependency}>
    )
endfunction()

function(target_weaken_symbols target)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --weaken-symbol=)

    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${target}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${target}>
    )
endfunction()

function(target_weaken_symbols_from_dependency target dependency)
    set(SYMBOL_LIST "${ARGN}")
    list(TRANSFORM SYMBOL_LIST PREPEND  --weaken-symbol=)

    add_custom_command(
        TARGET ${target}
        PRE_LINK
        COMMAND ${CMAKE_OBJCOPY}
        ARGS $<TARGET_FILE:${dependency}> --wildcard ${SYMBOL_LIST} $<TARGET_FILE:${dependency}>
    )
endfunction()

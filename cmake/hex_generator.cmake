#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)
include(imported_target)

macro(add_convert_to_offset_hex_target target)
    set(options)
    set(oneValueArgs INPUT_FILE OFFSET_MACRO_NAME INCLUDE_BL2_HEADER MIRROR_FILE OUTPUT_FILE)
    set(multiValueArgs)
    cmake_parse_arguments(MH "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Normalize OUTPUT_FILE to be relative to the current binary dir.
    # Error if it's outside the build tree.
    if (IS_ABSOLUTE "${MH_OUTPUT_FILE}")
        file(RELATIVE_PATH _rel_out "${CMAKE_BINARY_DIR}" "${MH_OUTPUT_FILE}")
        if (_rel_out MATCHES "^\\.\\.")
            message(FATAL_ERROR
                "OUTPUT_FILE must be inside the build tree.\n"
                "Given: ${MH_OUTPUT_FILE}\n"
                "Build dir: ${CMAKE_BINARY_DIR}")
        endif()
    else()
        set(_rel_out "${MH_OUTPUT_FILE}")
    endif()

    set(_abs_out "${CMAKE_BINARY_DIR}/${_rel_out}")

    # Declare how to build the file (command “owns” the OUTPUT).
    add_custom_command(
        OUTPUT "${_rel_out}"
        OUTPUT "${_abs_out}"
        COMMAND hex_generation
                    --image_layout_h_file region_defs.h
                    --file_to_mirror "${MH_MIRROR_FILE}"
                    --compile_commands_file ${CMAKE_BINARY_DIR}/compile_commands.json
                    --macro_name ${MH_OFFSET_MACRO_NAME}
                    $<IF:$<BOOL:${MH_INCLUDE_BL2_HEADER}>,--bl2_header_excluded,--no-bl2_header_excluded>
                    --input_binary_file "${MH_INPUT_FILE}"
                    --output_hex_file "${_abs_out}"
        DEPENDS ${target}_bin
        VERBATIM
    )

    # Small target that makes sure the OUTPUT is built (and can be invoked by name).
    add_custom_target(${target}_hex_build ALL
        DEPENDS "${_rel_out}"
    )

    # Expose the file as an imported target (if your helper expects an absolute path).
    add_imported_target(${target}_hex ${target}_hex_build "${_abs_out}")
endmacro()

# merge_hex(<target_name>
#   OUTPUT         <path/to/output.hex>
#   [INPUT_TARGETS <tgt1> <tgt2> ...]   # targets whose built files are inputs
#   [INPUT_FILES   <in1.hex> <in2.hex> ...]  # plain files known at configure time
#   [OVERLAP replace|ignore|error]      # default: replace
# )
#
# The generated file is ${OUTPUT}. Build it by building <target_name>.
# Uses: pip install intelhex

macro(merge_hex target)
    set(options)
    set(oneValueArgs OUTPUT OVERLAP)
    set(multiValueArgs INPUT_TARGETS INPUT_FILES)
    cmake_parse_arguments(MH "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT MH_OUTPUT)
        message(FATAL_ERROR "merge_hex(${target}): missing required OUTPUT")
    endif()
    if(NOT MH_INPUT_TARGETS AND NOT MH_INPUT_FILES)
        message(FATAL_ERROR "merge_hex(${target}): provide at least one of INPUT_TARGETS or INPUT_FILES")
    endif()

    if(NOT MH_OVERLAP)
        set(MH_OVERLAP "replace")
    endif()

    # Build the argument list for the Python script:
    #  - For targets: use $<TARGET_FILE:tgt> (generator expressions OK in COMMAND)
    #  - For plain files: use them as-is
    set(_INPUT_ARGS)
    foreach(_tgt IN LISTS MH_INPUT_TARGETS)
        list(APPEND _INPUT_ARGS "$<TARGET_FILE:${_tgt}>")
    endforeach()
    if(MH_INPUT_FILES)
        list(APPEND _INPUT_ARGS ${MH_INPUT_FILES})
    endif()

    # One-liner Python: merge all inputs -> OUTPUT with selected overlap strategy
    set(_PY_CODE
    "import sys; from intelhex import IntelHex; out=sys.argv[1]; files=sys.argv[2:]; ih=IntelHex(); \
    [ih.merge(IntelHex(f), overlap='${MH_OVERLAP}') for f in files]; ih.write_hex_file(out)")

    add_custom_command(
        OUTPUT "${MH_OUTPUT}"
        COMMAND "${Python3_EXECUTABLE}" -c "${_PY_CODE}" "${MH_OUTPUT}" ${_INPUT_ARGS}
        # Depend on producing targets (not $<TARGET_FILE:...>) and any plain files
        COMMAND ${CMAKE_COMMAND} -E echo "Merged: ${MH_OUTPUT}"
        DEPENDS ${MH_INPUT_TARGETS} ${MH_INPUT_FILES}
        VERBATIM
    )

    add_custom_target(${target}_build ALL DEPENDS "${MH_OUTPUT}")
    add_imported_target(${target} ${target}_build "${MH_OUTPUT}")
endmacro()

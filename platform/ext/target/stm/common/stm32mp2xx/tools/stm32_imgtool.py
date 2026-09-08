#!/usr/bin/env python3
#
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: Apache-2.0
#
# extracts load address and entry point from an ELF file and prepends
# the STM32 image header to the corresponding binary file.
#
import os
import sys
import struct
import argparse
from dataclasses import dataclass
from elftools.elf.elffile import ELFFile
from elftools.common.exceptions import ELFError


def _parse_args():
    parser = argparse.ArgumentParser(description="Add stm32 header at binary (need elf informations)")
    # Add the arguments
    parser.add_argument('-e', '--elf_file', help='elf file', required=True)
    parser.add_argument('-b', '--bin_file', help='binary file', required=True)
    parser.add_argument('-o', '--out_file', help='output file', required=True)
    parser.add_argument('-bt', '--binary_type', help='binary file', required=True)
    parser.add_argument('-v_maj', '--major_version', help='major version', required=False, default=1, type=int)
    parser.add_argument('-v_min', '--minor_version', help='minor version', required=False, default=0, type=int)
    return parser.parse_args()

# Known "Binary type" field value ranges, per header family. Used only for
# display purposes (see _get_binary_type_name()): a value outside these
# ranges is still accepted (e.g. a custom/future firmware type) and shown
# as "Unknown".
# Each entry is a (low, high, name) tuple with an inclusive [low, high] range.
BINARY_TYPES_V1 = (
    (0x10, 0x1F, "TF-A"),
    (0x30, 0x30, "COPRO"),
)
BINARY_TYPES_V2 = (
    (0x00, 0x00, "U-Boot"),
    (0x10, 0x10, "TF-A"),
    (0x20, 0x2F, "OP-TEE"),
    (0x30, 0x30, "CM33"),
)


@dataclass(frozen=True)
class HeaderSpec:
    """Describes the parts of the STM32 image header layout that vary from
    one header version to another. Adding a new supported version is just
    a matter of adding a new entry to HEADER_SPECS below (as long as it fits
    in the existing "v1"/"v2" family layouts)."""
    family: str                 # "v1" (option flags + ecdsa) or "v2" (extension header)
    signature_size: int         # size in bytes of the "Image Signature" field
    ext_padding_size: int = 0   # size in bytes of the "Extension PAD" field ("v2" family only)
    binary_types: tuple = ()    # supported "Binary type" (low, high, name) ranges, for display


# Single source of truth for every (major, minor) header version supported by
# add_stm32_header(). To add a new version, add an entry here.
HEADER_SPECS = {
    (1, 0): HeaderSpec(family="v1", signature_size=64, binary_types=BINARY_TYPES_V1),
    (2, 0): HeaderSpec(family="v2", signature_size=64, ext_padding_size=376, binary_types=BINARY_TYPES_V2),
    (2, 2): HeaderSpec(family="v2", signature_size=64, ext_padding_size=376, binary_types=BINARY_TYPES_V2),
    (2, 3): HeaderSpec(family="v2", signature_size=96, ext_padding_size=408, binary_types=BINARY_TYPES_V2),
}


def _get_header_spec(header_major_ver, header_minor_ver):
    """Return the HeaderSpec for the given (major, minor) couple.

    Raises ValueError if the couple is not supported.
    """
    spec = HEADER_SPECS.get((header_major_ver, header_minor_ver))
    if spec is None:
        supported = ", ".join(f"{maj}.{min_}" for maj, min_ in sorted(HEADER_SPECS))
        raise ValueError(
            f"Unsupported header version {header_major_ver}.{header_minor_ver} "
            f"(supported versions: {supported})"
        )
    return spec


def _get_binary_type_name(spec, binary_type):
    """Return the human-readable name for a known "Binary type" field value
    for the given HeaderSpec, or "Unknown" if the value isn't part of the
    documented STM32MP2 boot chain convention for that header family."""
    for low, high, name in spec.binary_types:
        if low <= binary_type <= high:
            return name
    return "Unknown"

def _stm32image_checksum(image):
    """Compute the STM32 image header checksum: the sum of every byte of
    `image`, wrapped to 32 bits (matches the STM32 ROM code convention)."""
    return sum(image) & 0xffffffff


def _display_array(name, offset, data):
    newdata = bytearray(data)
    mystr = ""
    size = len(data)

    for x in range(0, len(newdata)):
        mystr += f"{newdata[x]:02X} "

    maxNbByte = 16
    maxlg = maxNbByte * 2 + maxNbByte

    if len(mystr) > maxlg:
        mystr = mystr[0:maxlg] + "..."

    print(f"| {name:<23} | @{offset:#04x} | sz {size:03d} | {mystr} ")


def _print_stm32_header(header_major_ver, header_minor_ver, image_length,
                         load_address, entry_point, checksum, extension_flag,
                         binary_type, binary_type_name, version_number):
    print(f"Image Type  : ST Microelectronics STM32 V{header_major_ver}.{header_minor_ver}")
    print(f"Image Size  : {image_length} bytes")
    print(f"Image Load  : {load_address:#08X}")
    print(f"Entry Point : {entry_point:#08X}")
    print(f"Checksum    : {checksum:#08X}")
    print(f"Ext flag    : {extension_flag:#08X}")
    print(f"Binary Type : {binary_type:#08X} ({binary_type_name})")
    print(f"Version     : {version_number:#08X}")

def _build_common_fields(spec, header_major_ver, header_minor_ver, checksum,
                          image_length, entry_point, load_address, version_number):
    """Build the header fields shared by every supported version ("v1" and
    "v2" families). Returns a list of (name, packed_bytes) tuples."""
    return [
        ("Magic number", struct.pack('<4s', b'STM\x32')),
        ("Image Signature", struct.pack(f'{spec.signature_size}s', b'\x00' * spec.signature_size)),
        ("Image Checksum", struct.pack('<I', checksum)),
        ("Header version", struct.pack('<4B', 0x0, header_minor_ver, header_major_ver, 0x0)),
        ("Image Length", struct.pack('<I', image_length)),
        ("Image Entry  Point", struct.pack('<I', entry_point)),
        ("Reserved1", struct.pack('4s', b'\x00' * 4)),
        ("Load address", struct.pack('<I', load_address)),
        ("Reserved2", struct.pack('4s', b'\x00' * 4)),
        ("Version Number", struct.pack('<I', version_number)),
    ]


def _build_v1_fields(binary_type):
    """Build the "v1" family specific tail (option flags + ecdsa placeholder).
    Returns (extension_flag, [(name, packed_bytes), ...])."""
    option_flags = 1
    ecdsa_algorithm = 1
    ecdsa_pub_key = b'\x00' * 64
    fields = [
        ("Option flags", struct.pack('<I', option_flags)),
        ("ecdsa algo", struct.pack('<I', ecdsa_algorithm)),
        ("ecdsa_public_key", struct.pack('64s', ecdsa_pub_key)),
        ("padding", struct.pack('83s', b'\x00' * 83)),
        ("Binary type", struct.pack('<B', binary_type)),
    ]
    extension_flag = 0  # not applicable to the "v1" family
    return extension_flag, fields


def _build_v2_fields(spec, binary_type):
    """Build the "v2" family specific tail (extension header). The size of
    the "Extension PAD" field is driven by spec.ext_padding_size, which is
    the only thing that varies between the "v2" sub-versions (e.g. V2.3).
    Returns (extension_flag, [(name, packed_bytes), ...])."""
    extension_flag = (1 << 31)
    post_headers_length = spec.ext_padding_size + 8
    ext_header_type = b'ST\xFF\xFF'
    ext_header_length = post_headers_length
    ext_padding0 = b'\x00' * spec.ext_padding_size
    fields = [
        ("Extension flags", struct.pack('<I', extension_flag)),
        ("Post headers length", struct.pack('<I', post_headers_length)),
        ("Binary type", struct.pack('<I', binary_type)),
        ("PAD", struct.pack('16s', b'\x00' * 16)),
        ("Extension header type", struct.pack('<4s', ext_header_type)),
        ("Extension header length", struct.pack('<I', ext_header_length)),
        ("Extension PAD", struct.pack(f'{spec.ext_padding_size}s', ext_padding0)),
    ]
    return extension_flag, fields


# Per-family tail builders: build_fn(spec, binary_type) -> (extension_flag, fields)
_FAMILY_BUILDERS = {
    "v1": lambda spec, binary_type: _build_v1_fields(binary_type),
    "v2": _build_v2_fields,
}


def add_stm32_header(input_file, output_file, header_major_ver, header_minor_ver,
                      entry_point, load_address, binary_type):
    """Build the STM32 image header, prepend it to input_file's content and
    write the result to output_file.

    Raises ValueError if the (header_major_ver, header_minor_ver) couple is
    not supported, OSError if the input file cannot be read or the output
    file cannot be written."""

    spec = _get_header_spec(header_major_ver, header_minor_ver)

    try:
        with open(input_file, "rb") as origin_file:
            bin_data = origin_file.read()
    except OSError as e:
        raise OSError(f"Unable to read input file '{input_file}': {e}") from e

    image_length = len(bin_data)
    checksum = _stm32image_checksum(bin_data)
    version_number = 0

    fields = _build_common_fields(spec, header_major_ver, header_minor_ver,
                                  checksum, image_length, entry_point,
                                  load_address, version_number)

    extension_flag, tail_fields = _FAMILY_BUILDERS[spec.family](spec, binary_type)
    fields.extend(tail_fields)

    # creating the output file
    try:
        with open(output_file, "wb") as new_file:
            # adding header
            for _, data in fields:
                new_file.write(data)
            # adding firmware code
            new_file.write(bin_data)
    except OSError as e:
        raise OSError(f"Unable to write output file '{output_file}': {e}") from e

    # display header field
    offset = 0
    for name, data in fields:
        _display_array(name, offset, data)
        offset += len(data)

    _print_stm32_header(header_major_ver, header_minor_ver, image_length,
                        load_address, entry_point, checksum, extension_flag,
                        binary_type, _get_binary_type_name(spec, binary_type),
                        version_number)

    return 0

def get_elf_info(elf_file_path):
    """Get (load_address, entry_point) from the ELF file's .text section.

    Raises ValueError if the file is not a valid ELF or has no .text section,
    OSError if the file cannot be read."""
    try:
        with open(elf_file_path, "rb") as file:
            try:
                elf_file = ELFFile(file)
            except ELFError as e:
                raise ValueError(f"'{elf_file_path}' is not a valid ELF file: {e}") from e

            text_section = elf_file.get_section_by_name(".text")
            if text_section is None:
                raise ValueError(f"No .text section found in ELF file:{elf_file_path}")

            load_address = text_section.header["sh_addr"]
            entry_point = elf_file.header.e_entry
    except OSError as e:
        raise OSError(f"Unable to read ELF file '{elf_file_path}': {e}") from e

    return load_address, entry_point


def run(args):
    if not os.path.isfile(args.elf_file):
        raise FileNotFoundError(f"No such file:{args.elf_file}")

    if not os.path.isfile(args.bin_file):
        raise FileNotFoundError(f"No such file:{args.bin_file}")

    load_address, entry_point = get_elf_info(args.elf_file)

    try:
        binary_type = int(args.binary_type, 16)
    except ValueError as e:
        raise ValueError(
            f"Invalid binary type '{args.binary_type}': expected a hexadecimal value"
        ) from e

    print(f"elf file     :{args.elf_file}")
    print(f"bin file     :{args.bin_file}")
    print(f"load address :{load_address:#X}")
    print(f"entry point  :{entry_point:#X}")
    print(f"binary type  :{binary_type:#X}")
    print(f"header ver   :{args.major_version}.{args.minor_version}")

    add_stm32_header(args.bin_file, args.out_file,
                     args.major_version, args.minor_version,
                     entry_point, load_address, binary_type)

    print(f"{args.out_file} generated")

def main():
    args = _parse_args()

    try:
        run(args)
    except (FileNotFoundError, ValueError, OSError, ELFError) as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())

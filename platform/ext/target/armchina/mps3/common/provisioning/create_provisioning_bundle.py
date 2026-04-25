#-------------------------------------------------------------------------------
# Copyright (c) 2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import struct
from elftools.elf.elffile import ELFFile
from tfm_tools.struct_pack import struct_pack


parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--provisioning_bundle_axf",
                    help="the input provisioning bundle elf/axf",
                    required=True)
parser.add_argument("--magic",
                    help="the magic constant to insert at the start and end",
                    required=True)
parser.add_argument("--bl1_2_padded_hash_input_file",
                    help="the hash of the final bl1_2 image",
                    required=False)
parser.add_argument("--bl1_2_input_file",
                    help="the final bl1_2 image",
                    required=False)
parser.add_argument("--code_pad_size",
                    help="size to pad the code section",
                    required=True)
parser.add_argument("--values_pad_size",
                    help="size to pad the values section",
                    required=True)
parser.add_argument("--data_pad_size",
                    help="size to pad the data section",
                    required=True)
parser.add_argument("--bundle_output_file",
                    help="bundle output file",
                    required=False)
args = parser.parse_args()

elffile = ELFFile(open(args.provisioning_bundle_axf, 'rb'))

values_section = elffile.get_section_by_name("VALUES")
rodata_section = elffile.get_section_by_name("RO_DATA")
rwdata_section = elffile.get_section_by_name("RW_DATA")
code_section = elffile.get_section_by_name("CODE")

if code_section is not None:
    code = code_section.data()
else:
    print("provisioning_bundle's code sections is mandatory")
    sys.exit(1)

if rwdata_section is not None:
    rwdata = rwdata_section.data()
else:
    rwdata = bytes(0)

if rodata_section is not None:
    rodata = rodata_section.data()
else:
    rodata = bytes(0)

if values_section is not None:
    values = values_section.data()
else:
    print("provisioning_bundle's values sections is mandatory")
    sys.exit(1)


if args.bl1_2_padded_hash_input_file:
    with open(args.bl1_2_padded_hash_input_file, "rb") as in_file:
        bl1_2_padded_hash = in_file.read()
else:
    bl1_2_padded_hash = bytes(0)

if args.bl1_2_input_file:
    with open(args.bl1_2_input_file, "rb") as in_file:
        bl1_2 = in_file.read()
else:
    bl1_2 = bytes(0)

patch_bundle = struct_pack([
    bl1_2_padded_hash,
    bl1_2,
])

code = struct_pack([code],
                   pad_to=int(args.code_pad_size, 0))
values = struct_pack([patch_bundle, values[len(patch_bundle):]],
                     pad_to=int(args.values_pad_size, 0))
data = struct_pack([values, rwdata, rodata],
                   pad_to=int(args.values_pad_size, 0)+int(args.data_pad_size, 0))

bundle = struct_pack([
    int(args.magic, 16).to_bytes(4, 'little'),
    code,
    data,
    bytes(16), # Replace with GCM TAG
    int(args.magic, 16).to_bytes(4, 'little'),
])

with open(args.bundle_output_file, "wb") as out_file:
    out_file.write(bundle)

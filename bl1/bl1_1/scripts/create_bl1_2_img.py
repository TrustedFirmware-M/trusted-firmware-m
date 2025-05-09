#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import hashlib
import os
import sys
sys.path.append(os.path.join(os.path.dirname(os.path.realpath(__file__)), "../../../bl2/ext/mcuboot/scripts"))
import macro_parser
import struct

def hash_binary_blob(blob, hash_alg):
   hash = getattr(hashlib, hash_alg.lower())()
   hash.update(blob)
   return hash.digest()

def struct_pack(objects, pad_to=0):
    defstring = "<"
    for obj in objects:
        defstring += str(len(obj)) + "s"

    size = struct.calcsize(defstring)
    if size < pad_to:
        defstring += str(pad_to - size) + "x"

    return (bytes(struct.pack(defstring, *objects)))


parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--input_file", help="the image to process", required=True)
parser.add_argument("--img_output_file", help="image output file", required=True)
parser.add_argument("--hash_output_file", help="hash output file", required=True)
parser.add_argument("--hash_alg", help="Hash algorithm to use for measurement", required=True)
parser.add_argument("--signing_layout_file", help="signing layout file", required=True)
args = parser.parse_args()

with open(args.input_file, "rb") as in_file:
    bl1_2_code = in_file.read()

bl1_2_partition_size = macro_parser.evaluate_macro(args.signing_layout_file,
                                    ".*(RE_BL1_2_BIN_SIZE) = *(.*)",
                                    1, 2, True)['RE_BL1_2_BIN_SIZE']

image = struct_pack([bl1_2_code], pad_to=bl1_2_partition_size)
hash = hash_binary_blob(image, args.hash_alg)

with open(args.img_output_file, "wb") as img_out_file:
    img_out_file.write(image)

with open(args.hash_output_file, "wb") as hash_out_file:
    hash_out_file.write(hash)

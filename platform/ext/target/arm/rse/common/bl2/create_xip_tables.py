#-------------------------------------------------------------------------------
# Copyright (c) 2022-2025, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import hashlib
from functools import reduce
from operator import add
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import hashes
import struct
import secrets
import os
import sys
from tfm_tools.struct_pack import struct_pack

from tfm_tools.key_derivation import derive_symmetric_key

sic_page_size = 1024
sic_line_size = 16

def chunk_bytes(x, n):
    return [x[i:i+n] for i in range(0, len(x), n)]

def round_up(x, boundary):
    return ((x + (boundary - 1)) // boundary) * boundary

parser = argparse.ArgumentParser(allow_abbrev=False)
parser.add_argument("--input_image", help="the image to create table from", required=True)
parser.add_argument("--encrypt_key_file", help="Key to derive the encrypt key", required=False)
parser.add_argument("--label", help="Label to derive the encrypt key", required=True)
parser.add_argument("--image_version", help="Version of the image", required=True)
parser.add_argument("--table_output_file", help="table output file", required=True)
parser.add_argument("--encrypted_image_output_file", help="encrypted image output file", required=True)
args = parser.parse_args()

with open(args.input_image, "rb") as in_file:
    image = in_file.read()

if args.encrypt_key_file is not None:
    with open(args.encrypt_key_file, "rb") as in_file:
        encrypt_key = in_file.read()
else:
    encrypt_key = bytearray([0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45,
                             0x67, 0x89, 0x01, 0x23, 0x45, 0x67, 0x89, 0x01,
                             0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45, 0x67,
                             0x89, 0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23,
])

digest = hashes.Hash(hashes.SHA256())
digest.update(int("0x111155AA", 16).to_bytes(4, 'little'))
digest.update(int("0x00000000", 16).to_bytes(4, 'little')) #reprovisioning bits
data_hash = digest.finalize()

derived_encrypt_key = derive_symmetric_key(encrypt_key, bytes(data_hash), args.label, 32)


fw_version_bytes = int(args.image_version, 0).to_bytes(4, 'little')
nonce_bytes = secrets.token_bytes(8)

# We need to pad the image to the authentication page size
image = struct_pack([image], round_up(len(image), sic_page_size))

# The SIC uses a non-standard counter construction, so we need to do this
# manually
enc_image = []
line_idx = 0
for chunk in chunk_bytes(image, sic_line_size):
    counter_val = struct_pack([line_idx.to_bytes(4, 'little'), fw_version_bytes, nonce_bytes[4:], nonce_bytes[:4]], pad_to=16)
    line_idx += 1
    cipher = Cipher(algorithms.AES(derived_encrypt_key), modes.CTR(counter_val))
    enc_image.append(cipher.encryptor().update(chunk))
enc_image = reduce(add, enc_image, b"")

htr = reduce(add, map(lambda x:hashlib.sha256(x).digest(), chunk_bytes(enc_image, sic_page_size)), b"")

table = struct_pack([
            fw_version_bytes,
            nonce_bytes,
            len(htr).to_bytes(4, 'little'),
            htr
            ])

with open(args.table_output_file, "wb") as out_file:
    out_file.write(table)

with open(args.encrypted_image_output_file, "wb") as out_file:
    out_file.write(enc_image)
